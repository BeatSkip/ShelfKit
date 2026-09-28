/**
 * @file sk_link.c
 * @brief The ShelfKit link layer: frame, CRC, addressing, managed flooding
 *
 * The frame layout and the reasoning behind it are in
 * firmware/shared/include/shelfkit_proto.h (the frame) and sk_link.h (the
 * flooding rules, the roles, and what each parameter costs). This file is the
 * implementation, and it is kept byte-identical between the tag and the
 * access point - the two copies are compared by hash the same way radio.c's
 * are, because a field either end disagrees about is a link that silently
 * does not work.
 *
 * Three things are worth reading before changing anything here:
 *
 *   * RAM. Every buffer is __xdata and every function is __reentrant. This
 *     part has 128 bytes of directly addressable internal RAM and the stack
 *     lives in it: a byte array here would be taken straight out of the stack
 *     and a parameter block would do the same. Nothing in this file may move
 *     into internal RAM "because it is only a few bytes".
 *
 *   * The seen ring is the whole of the mesh's memory, deliberately. A router
 *     holds no routing table, no neighbour list and no per-peer state, so a
 *     tag that reboots is immediately a full member again. What that costs is
 *     in sk_link.h: a duplicate older than eight messages is relayed twice.
 *
 *   * The radio calls are the only hardware dependency (radio.h). The host
 *     test compiles this file twice - once per role - against a stubbed radio
 *     and wires the two nodes together, so a change that only works with one
 *     node on the air is a change the test can see.
 */

#include <libmftypes.h>

#include "radio.h"
#include "sk_link.h"

/* ── state ────────────────────────────────────────────────────────────────
 * All of it in XRAM; see the RAM note above.
 *
 * Every one of these carries __xdata, the one-byte flags included. Under
 * SDCC's --model-small an unqualified variable is *internal* RAM, and this
 * part has 128 bytes of it shared with the stack and with the overlay area
 * the linker uses for every non-reentrant function's parameter block: a
 * dozen stray bytes here is not a rounding error, it is the link failing
 * with "Could not get N consecutive bytes in internal RAM for area OSEG",
 * which is what happened the first time this file was built. XRAM has room;
 * internal RAM does not. */

/* The frame being examined, and the frame being forwarded. Two buffers
 * because a relay has to keep the frame it is about to repeat while it
 * listens for someone else repeating it first. */
static uint8_t __xdata sl_rx[SK_LINK_MAX];
static uint8_t __xdata sl_fwd[SK_LINK_MAX];

/* The seen ring: (origin, seq) of the last SK_LINK_SEEN messages handled,
 * oldest overwritten. */
static uint32_t __xdata sl_seen_origin[SK_LINK_SEEN];
static uint8_t  __xdata sl_seen_seq[SK_LINK_SEEN];
static uint8_t __xdata sl_seen_next;
static uint8_t __xdata sl_seen_count;

/* This node. */
static uint32_t __xdata sl_my_id;
static uint8_t __xdata sl_role;
static uint8_t __xdata sl_seq;      /* sequence number of the next frame we send */

/* The forward waiting for its backoff. One at a time: a relay is not a
 * router's critical path, and a pointer-free single slot is what fits. If a
 * second frame arrives while one is pending, that one is not relayed - the
 * origin will send it again (the application layer is stop-and-wait), and a
 * dropped relay costs a retry, not a wrong answer. */
static uint8_t __xdata sl_fwd_pending;
static uint8_t __xdata sl_fwd_len;
static uint8_t __xdata sl_fwd_wait;

/* The last frame examined, whatever happened to it. These are what let both
 * consoles answer "which way did that packet come". */
static uint32_t __xdata sl_last_origin;
static uint32_t __xdata sl_last_dst;
static uint16_t __xdata sl_last_route[SK_LINK_ROUTE_MAX];
static uint8_t __xdata sl_last_seq;
static uint8_t __xdata sl_last_hops;
static uint8_t __xdata sl_last_routelen;
static uint8_t __xdata sl_last_dup;
static uint8_t __xdata sl_last_relay;
static uint8_t __xdata sl_last_bad;
static uint8_t __xdata sl_last_router;
static int8_t  __xdata sl_last_rssi;

/* What the receiver does after a transmission (SK_RX_*). Continuous unless a
 * leaf says otherwise. */
static uint8_t __xdata sl_rx_mode;

/* ── the CRC and the id ───────────────────────────────────────────────────
 * Both are in sk_link.c rather than borrowed from libmf. libmf carries two
 * CRC-16s whose names differ by one letter (crc_ccitt_msb / crc_crc16_msb)
 * and the wrong one fails silently - see shelfkit_proto.h. Implementing the
 * protocol's own CRC here costs about 60 bytes of code, is the same code on
 * the host test and on both firmwares, and can be pinned against the
 * published check value. */
uint16_t sk_crc16(const uint8_t __xdata *buf, uint8_t len, uint16_t crc) __reentrant
{
    uint8_t i, bit;

    for (i = 0; i < len; i++) {
        crc ^= (uint16_t)((uint16_t)buf[i] << 8);
        for (bit = 0; bit < 8; bit++) {
            if (crc & 0x8000)
                crc = (uint16_t)((uint16_t)(crc << 1) ^ 0x1021);
            else
                crc = (uint16_t)(crc << 1);
        }
    }
    return crc;
}

/* FNV-1a/32, with the letters folded to upper case: the tag reads its serial
 * out of the NFC chip's NDEF URI and the access point reads it out of an
 * image file name, and "1408f525" and "1408F525" are the same tag. The two
 * ends must compute the same address for it. */
uint32_t sk_id_from_serial(const char __xdata *serial, uint8_t len) __reentrant
{
    uint32_t h = 2166136261UL;
    uint8_t i;

    for (i = 0; i < len; i++) {
        uint8_t c = (uint8_t)serial[i];

        if (c >= 'a' && c <= 'z')
            c = (uint8_t)(c - 'a' + 'A');
        h ^= c;
        h *= 16777619UL;
    }
    return h;
}

/* ── small frame helpers ──────────────────────────────────────────────── */

static void sl_put_id(uint8_t __xdata *p, uint32_t v) __reentrant
{
    p[0] = (uint8_t)(v >> 24);
    p[1] = (uint8_t)(v >> 16);
    p[2] = (uint8_t)(v >> 8);
    p[3] = (uint8_t)v;
}

static uint32_t sl_get_id(const uint8_t __xdata *p) __reentrant
{
    return ((uint32_t)p[0] << 24) | ((uint32_t)p[1] << 16) |
           ((uint32_t)p[2] << 8) | (uint32_t)p[3];
}

static uint8_t sl_hops_of(uint8_t ctl) __reentrant
{
    return (uint8_t)((ctl & SK_LINK_CTL_HOPS_MASK) >> SK_LINK_CTL_HOPS_SHIFT);
}

static uint8_t sl_ctl_of(uint8_t hops) __reentrant
{
    uint8_t ctl = (uint8_t)((hops << SK_LINK_CTL_HOPS_SHIFT) & SK_LINK_CTL_HOPS_MASK);

    if (sl_role == SK_ROLE_ROUTER)
        ctl |= SK_LINK_CTL_ROUTER;
    return ctl;
}

/* The two bytes this node records itself with in a frame's route: the low 16
 * bits of its full id. Display only - nothing is ever addressed by it - so a
 * collision between two nodes' short ids is a cosmetic problem in a log
 * line, not a delivery problem. */
static uint16_t sl_short_id(void) __reentrant
{
    return (uint16_t)sl_my_id;
}

/* ── the seen ring ────────────────────────────────────────────────────── */

static uint8_t sl_seen_has(uint32_t origin, uint8_t seq) __reentrant
{
    uint8_t i;

    for (i = 0; i < sl_seen_count; i++) {
        if (sl_seen_seq[i] == seq && sl_seen_origin[i] == origin)
            return 1;
    }
    return 0;
}

static void sl_seen_add(uint32_t origin, uint8_t seq) __reentrant
{
    sl_seen_origin[sl_seen_next] = origin;
    sl_seen_seq[sl_seen_next] = seq;
    sl_seen_next = (uint8_t)((sl_seen_next + 1) & (SK_LINK_SEEN - 1));
    if (sl_seen_count < SK_LINK_SEEN)
        sl_seen_count++;
}

/* ── transmitting ─────────────────────────────────────────────────────── */

/* sl_fwd holds a complete frame of sl_fwd_len bytes; put it on the air.
 * @p wor selects the wake-on-radio preamble (radio.h), and the receiver is
 * re-armed afterwards in whichever mode the node is in - radio_tx() powers
 * the chip down when it finishes, so leaving it there would make the node
 * deaf to its own conversation. */
static uint8_t sl_tx(uint8_t wor) __reentrant
{
    uint8_t err = wor ? radio_tx_wor(sl_fwd, sl_fwd_len)
                      : radio_tx(sl_fwd, sl_fwd_len);

    if (sl_rx_mode == SK_RX_WOR)
        radio_rx_wor_start();
    else
        radio_rx_start();

    return err == RADIO_OK ? SK_LINK_OK : SK_LINK_ERR_RADIO;
}

/* Close a frame in sl_fwd: append the CRC over the first @p len bytes and
 * return the new total length. */
static uint8_t sl_close(uint8_t len) __reentrant
{
    uint16_t crc = sk_crc16(sl_fwd, len, 0xFFFF);

    sl_fwd[len] = (uint8_t)(crc >> 8);
    sl_fwd[len + 1] = (uint8_t)crc;
    return (uint8_t)(len + SK_LINK_CRC_LEN);
}

/* Build a frame of our own in sl_fwd. @p seq is the sequence number to use,
 * so a relay can repeat someone else's frame with its number rather than a
 * fresh one (which is the whole point of the dedup ring). Returns the total
 * frame length, or 0 when the payload does not fit. */
static uint8_t sl_build(uint32_t dst, uint32_t origin, uint8_t seq,
                        const uint8_t __xdata *app, uint8_t len) __reentrant
{
    uint8_t i;

    if (len > SK_PKT_MAX)
        return 0;

    sl_fwd[SK_LINK_O_VER] = SK_LINK_VERSION;
    /* A copy of the application type at a fixed offset: a relay can then log
     * what it is forwarding without knowing where the payload starts (which
     * depends on the route). One byte, and it is what the relay trace below
     * prints. */
    sl_fwd[SK_LINK_O_TYPE] = (uint8_t)(len >= 2 ? app[1] : 0);
    sl_fwd[SK_LINK_O_CTL] = sl_ctl_of(SK_LINK_HOPS_INIT);
    sl_fwd[SK_LINK_O_SEQ] = seq;
    sl_put_id(&sl_fwd[SK_LINK_O_ORIGIN], origin);
    sl_put_id(&sl_fwd[SK_LINK_O_DST], dst);
    sl_fwd[SK_LINK_O_ROUTELEN] = 0;
    for (i = 0; i < len; i++)
        sl_fwd[SK_LINK_HDR_LEN + i] = app[i];

    return sl_close((uint8_t)(SK_LINK_HDR_LEN + len));
}

/* Send one of our own frames. Any forward waiting for its backoff goes out
 * first: sl_fwd is the transmit buffer, there is only one of it, and a relay
 * that has been waiting is closer to being due than this new frame is. */
static uint8_t sl_send(uint32_t dst, const uint8_t __xdata *app, uint8_t len,
                       uint8_t wor) __reentrant
{
    uint8_t total;

    if (sl_fwd_pending) {
        sl_fwd_pending = 0;
        (void)sl_tx(0);
    }

    total = sl_build(dst, sl_my_id, sl_seq, app, len);
    if (!total)
        return SK_LINK_ERR_LEN;

    /* Our own message goes into the ring too. Without it a router would relay
     * the copy the mesh hands back to it, and two boards on a bench would
     * ping-pong one frame between them until the hop budget ran out. */
    sl_seen_add(sl_my_id, sl_seq);
    sl_seq++;

    sl_fwd_len = total;
    return sl_tx(wor);
}

uint8_t sk_link_send(uint32_t dst, const uint8_t __xdata *app, uint8_t len) __reentrant
{
    return sl_send(dst, app, len, 0);
}

uint8_t sk_link_send_wor(uint32_t dst, const uint8_t __xdata *app, uint8_t len) __reentrant
{
    return sl_send(dst, app, len, 1);
}

/* ── forwarding ───────────────────────────────────────────────────────── */

/* How long this relay waits before repeating a frame. Deterministic - the
 * host test would be a lottery otherwise - but different for each (message,
 * node) pair, so two relays of the same frame almost never pick the same
 * slot. It is not a random number generator and does not need to be. */
static uint8_t sl_backoff(const uint8_t __xdata *f) __reentrant
{
    uint32_t origin = sl_get_id(&f[SK_LINK_O_ORIGIN]);
    uint16_t mix = (uint16_t)((uint16_t)f[SK_LINK_O_SEQ] * 37u);

    mix ^= (uint16_t)sl_my_id;
    mix ^= (uint16_t)(sl_my_id >> 16);
    mix ^= (uint16_t)origin;
    mix ^= (uint16_t)(origin >> 16);
    return (uint8_t)(mix & (SK_LINK_BACKOFF_MS - 1));
}

/* Build the repeat of sl_rx in sl_fwd: one hop less, this node's short id
 * appended to the route (unless the route is full, which stops the recording
 * rather than the forwarding), and a fresh CRC over the result. */
static void sl_schedule_forward(uint8_t n) __reentrant
{
    uint8_t routelen = sl_rx[SK_LINK_O_ROUTELEN];
    uint8_t old_at = (uint8_t)(SK_LINK_HDR_LEN + 2 * routelen);
    uint8_t applen = (uint8_t)(n - old_at - SK_LINK_CRC_LEN);
    uint8_t hops = sl_hops_of(sl_rx[SK_LINK_O_CTL]);
    uint8_t at, i;

    for (i = 0; i < SK_LINK_HDR_LEN; i++)
        sl_fwd[i] = sl_rx[i];
    sl_fwd[SK_LINK_O_CTL] = sl_ctl_of((uint8_t)(hops - 1));

    /* Copy the route that is already there, and append this node's short id
     * if there is room for it. When the route is full the recording stops -
     * the frame is still forwarded, it just arrives with the path it already
     * had. */
    at = SK_LINK_HDR_LEN;
    if (routelen < SK_LINK_ROUTE_MAX) {
        for (i = 0; i < (uint8_t)(2 * routelen); i++)
            sl_fwd[at + i] = sl_rx[at + i];
        at = (uint8_t)(at + 2 * routelen);
        sl_fwd[at] = (uint8_t)(sl_short_id() >> 8);
        sl_fwd[at + 1] = (uint8_t)sl_short_id();
        at = (uint8_t)(at + 2);
        sl_fwd[SK_LINK_O_ROUTELEN] = (uint8_t)(routelen + 1);
    } else {
        for (i = 0; i < (uint8_t)(2 * routelen); i++)
            sl_fwd[at + i] = sl_rx[at + i];
        at = old_at;
    }

    /* The payload follows at whatever offset the route ended at. (An earlier
     * version copied it at SK_LINK_HDR_LEN in the full-route case, which
     * quietly shortened the frame and moved the payload - the host test's
     * "a full route stops recording, not forwarding" case is what caught
     * it.) */
    for (i = 0; i < applen; i++)
        sl_fwd[at + i] = sl_rx[old_at + i];

    sl_fwd_len = sl_close((uint8_t)(at + applen));
    sl_fwd_wait = sl_backoff(sl_rx);
    sl_fwd_pending = 1;
}

/* ── receiving ────────────────────────────────────────────────────────── */

static void sl_note(const uint8_t __xdata *f, uint8_t routelen, int8_t rssi) __reentrant
{
    uint8_t i;

    sl_last_origin = sl_get_id(&f[SK_LINK_O_ORIGIN]);
    sl_last_dst = sl_get_id(&f[SK_LINK_O_DST]);
    sl_last_seq = f[SK_LINK_O_SEQ];
    sl_last_hops = sl_hops_of(f[SK_LINK_O_CTL]);
    sl_last_router = (uint8_t)((f[SK_LINK_O_CTL] & SK_LINK_CTL_ROUTER) ? 1 : 0);
    sl_last_routelen = routelen;
    sl_last_rssi = rssi;
    for (i = 0; i < routelen; i++)
        sl_last_route[i] = (uint16_t)(((uint16_t)f[SK_LINK_HDR_LEN + 2 * i] << 8) |
                                      f[SK_LINK_HDR_LEN + 2 * i + 1]);
}

uint8_t sk_link_poll(uint8_t __xdata *app, uint8_t maxlen) __reentrant
{
    uint8_t n, routelen, at, applen, hops, deliver, i;
    uint32_t origin, dst;
    uint16_t crc, want;
    int8_t rssi;

    sl_last_dup = 0;
    sl_last_relay = 0;
    sl_last_bad = 0;

    /* A forward that has waited out its backoff goes now. The wait is counted
     * in polls, and poll() does the millisecond itself, so the backoff is
     * real time whether the caller polls in a tight loop (the tag) or once a
     * millisecond (the access point). */
    if (sl_fwd_pending) {
        if (sl_fwd_wait) {
            sl_fwd_wait--;
            delay(1000);
        }
        if (!sl_fwd_wait) {
            sl_fwd_pending = 0;
            (void)sl_tx(0);
        }
    }

    n = radio_rx(sl_rx, SK_LINK_MAX);
    if (!n)
        return 0;

    /* Everything below here is a frame that was heard but is not usable:
     * wrong version (another protocol, or an old build), a route length that
     * cannot be right, a length that does not add up, or a CRC that does not
     * match. sl_last_bad is what lets a console tell "the radio is hearing
     * nothing" from "the radio is hearing rubbish" - the distinction the old
     * XOR trace used to draw, and the one that says whether to look at the
     * aerial or at the protocol. */
    if (n < SK_LINK_HDR_LEN + SK_LINK_CRC_LEN)
        goto bad;
    if (sl_rx[SK_LINK_O_VER] != SK_LINK_VERSION)
        goto bad;

    routelen = sl_rx[SK_LINK_O_ROUTELEN];
    if (routelen > SK_LINK_ROUTE_MAX)
        goto bad;
    at = (uint8_t)(SK_LINK_HDR_LEN + 2 * routelen);
    if (n < (uint8_t)(at + SK_LINK_CRC_LEN))
        goto bad;

    crc = sk_crc16(sl_rx, (uint8_t)(n - SK_LINK_CRC_LEN), 0xFFFF);
    want = (uint16_t)(((uint16_t)sl_rx[n - 2] << 8) | sl_rx[n - 1]);
    if (crc != want)
        goto bad;

    origin = sl_get_id(&sl_rx[SK_LINK_O_ORIGIN]);
    dst = sl_get_id(&sl_rx[SK_LINK_O_DST]);
    hops = sl_hops_of(sl_rx[SK_LINK_O_CTL]);
    applen = (uint8_t)(n - at - SK_LINK_CRC_LEN);
    rssi = radio_rssi();
    sl_note(sl_rx, routelen, rssi);

    /* Already handled: a duplicate, or (for the node that sent it) the mesh
     * handing this node's own frame back through a relay. Either way it is
     * not delivered and not forwarded again. */
    if (sl_seen_has(origin, sl_rx[SK_LINK_O_SEQ])) {
        sl_last_dup = 1;
        return 0;
    }
    sl_seen_add(origin, sl_rx[SK_LINK_O_SEQ]);

    deliver = (uint8_t)(dst == SK_LINK_BROADCAST || dst == sl_my_id);

    /* Forward if this node relays at all, the frame is not for it, and the
     * hop budget has something left. A frame that arrives with no hops left
     * is still delivered to its destination - it just goes no further. */
    if (sl_role == SK_ROLE_ROUTER && hops > 0 && dst != sl_my_id) {
        sl_schedule_forward(n);
        sl_last_relay = 1;
    }

    if (!deliver || applen == 0 || applen > maxlen)
        return 0;

    for (i = 0; i < applen; i++)
        app[i] = sl_rx[at + i];

    return applen;

bad:
    sl_last_bad = 1;
    return 0;
}

/* ── metadata for the caller ──────────────────────────────────────────── */

uint8_t sk_link_dup(void) __reentrant
{
    return sl_last_dup;
}

uint8_t sk_link_relayed(void) __reentrant
{
    return sl_last_relay;
}

uint8_t sk_link_bad(void) __reentrant
{
    return sl_last_bad;
}

uint8_t sk_link_sender_router(void) __reentrant
{
    return sl_last_router;
}

uint32_t sk_link_origin(void) __reentrant
{
    return sl_last_origin;
}

uint32_t sk_link_dst(void) __reentrant
{
    return sl_last_dst;
}

uint8_t sk_link_seq(void) __reentrant
{
    return sl_last_seq;
}

uint8_t sk_link_hops(void) __reentrant
{
    return sl_last_hops;
}

uint8_t sk_link_route_len(void) __reentrant
{
    return sl_last_routelen;
}

uint16_t sk_link_route(uint8_t i) __reentrant
{
    if (i >= sl_last_routelen)
        return 0;
    return sl_last_route[i];
}

int8_t sk_link_rssi(void) __reentrant
{
    return sl_last_rssi;
}

/* ── init ─────────────────────────────────────────────────────────────── */

void sk_link_init(uint8_t role, uint32_t my_id) __reentrant
{
    uint8_t i;

    sl_role = role;
    sl_my_id = my_id;
    sl_seq = 0;
    sl_seen_next = 0;
    sl_seen_count = 0;
    sl_fwd_pending = 0;
    sl_fwd_len = 0;
    sl_fwd_wait = 0;
    sl_rx_mode = SK_RX_CONTINUOUS;

    sl_last_origin = 0;
    sl_last_dst = 0;
    sl_last_seq = 0;
    sl_last_hops = 0;
    sl_last_routelen = 0;
    sl_last_rssi = 0;
    sl_last_dup = 0;
    sl_last_relay = 0;
    sl_last_bad = 0;
    sl_last_router = 0;

    for (i = 0; i < SK_LINK_SEEN; i++) {
        sl_seen_origin[i] = 0;
        sl_seen_seq[i] = 0;
    }
    for (i = 0; i < SK_LINK_ROUTE_MAX; i++)
        sl_last_route[i] = 0;
}

void sk_link_rx_mode(uint8_t mode) __reentrant
{
    sl_rx_mode = mode;
}

uint8_t sk_link_role(void) __reentrant
{
    return sl_role;
}

uint32_t sk_link_id(void) __reentrant
{
    return sl_my_id;
}
