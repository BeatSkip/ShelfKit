/**
 * @file sk_link_test.c
 * @brief Host test for the ShelfKit link layer (firmware/<project>/src/sk_link.c)
 *
 * The link layer has no MCU dependency at all: the frame layout, the CRC, the
 * addressing, the flooding rules and the record route are logic. So this test
 * compiles the *real* sk_link.c - not a copy of it - against a virtual radio,
 * and drives it from both sides:
 *
 *   * frames it builds itself (with its own independent CRC and its own
 *     reading of the header layout) are pushed into the radio, which is how
 *     the receive path, the dedup ring, the role rules and the forwarding are
 *     exercised;
 *   * frames sk_link.c transmits are captured byte for byte and checked
 *     against that same independent builder, which is how the transmit path
 *     and the record route are exercised.
 *
 * Two things are cross-checked rather than trusted:
 *
 *   * the CRC: sk_crc16() must agree with a from-scratch bitwise
 *     implementation here, and both must answer 0x29B1 for "123456789"
 *     (CRC-16/CCITT-FALSE's published check value). libmf carries a
 *     *different* CRC-16 whose name is one letter away, so this is the test
 *     that stops the wrong one being wired in.
 *   * the node id: sk_id_from_serial() must agree with an FNV-1a computed
 *     here, and must fold case, because the access point reads a serial out
 *     of a file name and the tag reads one out of an NFC URI.
 *
 * It also asserts the constraint the two firmwares live under: the tag's and
 * the access point's copies of sk_link.c (and of radio.c/radio.h) are
 * byte-identical. A field one end disagrees about is a link that silently
 * does not work, and "we compared them by hand" is not a test.
 *
 * Build and run (from the repository root):
 *
 *   gcc -Wall -Wextra -Wno-unused-function -Wno-unused-parameter \
 *       -I tools/tests/ap_stubs -I firmware/shared/include \
 *       -c -o tools/tests/sk_link_test_link.o \
 *       firmware/shelfkit-vusion/src/sk_link.c
 *   gcc -Wall -Wextra -Wno-unused-function -Wno-unused-parameter \
 *       -I tools/tests/ap_stubs -I firmware/shared/include \
 *       -o tools/tests/sk_link_test.exe \
 *       tools/tests/sk_link_test.c tools/tests/sk_link_test_link.o
 *   ./tools/tests/sk_link_test.exe
 *
 * tools/run_tests.ps1 does exactly that.
 */

#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>

#include "../../firmware/shelfkit-vusion/src/radio.h"
#include "../../firmware/shared/include/sk_link.h"

/* ── the virtual radio ────────────────────────────────────────────────── */

#define AIR_MAX 8
#define TX_MAX  16

/* Frames waiting to be received, in arrival order: this is the "air", and the
 * test decides what is in it. */
static uint8_t air[AIR_MAX][SK_LINK_MAX];
static uint8_t air_len[AIR_MAX];
static int air_head, air_tail;

/* Everything sk_link.c transmitted, in order. */
static uint8_t tx[TX_MAX][SK_LINK_MAX];
static uint8_t tx_len[TX_MAX];
static int tx_n;

static uint32_t virtual_ms;
static uint8_t tx_fail;
static int8_t  fake_rssi;
static int rx_start_calls, rx_wor_calls, tx_wor_calls;

void delay(uint16_t us) { virtual_ms += (uint32_t)us / 1000; }
void enter_standby(void) { }

static void push_air(const uint8_t *frame, uint8_t len)
{
    if (air_tail >= AIR_MAX) {
        printf("FAIL air queue overflow\n");
        exit(1);
    }
    memcpy(air[air_tail], frame, len);
    air_len[air_tail] = len;
    air_tail++;
}

static uint8_t read_fifo(uint8_t *payload, uint8_t maxlen)
{
    uint8_t n;

    if (air_head == air_tail)
        return 0;
    n = air_len[air_head];
    if (n > maxlen)
        n = maxlen;
    memcpy(payload, air[air_head], n);
    air_head++;
    return n;
}

static void reset_radio(void)
{
    air_head = air_tail = 0;
    tx_n = 0;
    virtual_ms = 0;
    tx_fail = 0;
    fake_rssi = -66;
    rx_start_calls = rx_wor_calls = tx_wor_calls = 0;
}

/* The radio interface sk_link.c uses. radio_tx()'s signature is radio.h's, so
 * a change there breaks this build rather than silently disagreeing. */
uint8_t radio_tx(const uint8_t *payload, uint8_t len)
{
    if (tx_fail)
        return RADIO_ERR_TX_FIFO;
    if (tx_n >= TX_MAX) {
        printf("FAIL too many transmissions\n");
        exit(1);
    }
    memcpy(tx[tx_n], payload, len);
    tx_len[tx_n] = len;
    tx_n++;
    return RADIO_OK;
}

uint8_t radio_tx_wor(const uint8_t *payload, uint8_t len)
{
    tx_wor_calls++;
    return radio_tx(payload, len);
}

uint8_t radio_rx(uint8_t *payload, uint8_t maxlen)
{
    return read_fifo(payload, maxlen);
}

int8_t radio_rssi(void) { return fake_rssi; }
void radio_rx_start(void) { rx_start_calls++; }
void radio_rx_wor_start(void) { rx_wor_calls++; }
void radio_rx_stop(void) { }

/* ── independent references ───────────────────────────────────────────── */

/* CRC-16/CCITT-FALSE, written the long way and independently of sk_crc16():
 * poly 0x1021, init 0xFFFF, MSB first, no reflection, no final xor. */
static uint16_t crc_ref(const uint8_t *buf, uint8_t len)
{
    uint16_t crc = 0xFFFF;
    uint8_t i;
    int bit;

    for (i = 0; i < len; i++) {
        crc ^= (uint16_t)((uint16_t)buf[i] << 8);
        for (bit = 0; bit < 8; bit++)
            crc = (crc & 0x8000) ? (uint16_t)((crc << 1) ^ 0x1021)
                                 : (uint16_t)(crc << 1);
    }
    return crc;
}

/* FNV-1a/32, one character at a time, with the case folded. */
static uint32_t fnv_ref(const char *s)
{
    uint32_t h = 2166136261UL;

    while (*s) {
        unsigned char c = (unsigned char)*s++;

        if (c >= 'a' && c <= 'z')
            c = (unsigned char)(c - 'a' + 'A');
        h ^= c;
        h *= 16777619UL;
    }
    return h;
}

/* ── an independent frame builder ─────────────────────────────────────── */

static void put32(uint8_t *p, uint32_t v)
{
    p[0] = (uint8_t)(v >> 24);
    p[1] = (uint8_t)(v >> 16);
    p[2] = (uint8_t)(v >> 8);
    p[3] = (uint8_t)v;
}

static uint32_t get32(const uint8_t *p)
{
    return ((uint32_t)p[0] << 24) | ((uint32_t)p[1] << 16) |
           ((uint32_t)p[2] << 8) | p[3];
}

/* Build a frame from scratch: the test's own understanding of the wire
 * format, used both to feed the receiver and to check the transmitter. */
static uint8_t build(uint8_t *out, uint8_t type, uint8_t hops, uint8_t seq,
                     uint32_t origin, uint32_t dst, uint8_t role_router,
                     const uint16_t *route, uint8_t routelen,
                     const uint8_t *app, uint8_t applen)
{
    uint8_t n = SK_LINK_HDR_LEN;
    uint8_t i;
    uint16_t crc;

    out[SK_LINK_O_VER] = SK_LINK_VERSION;
    out[SK_LINK_O_TYPE] = type;
    out[SK_LINK_O_CTL] = (uint8_t)((hops << SK_LINK_CTL_HOPS_SHIFT) |
                                   (role_router ? SK_LINK_CTL_ROUTER : 0));
    out[SK_LINK_O_SEQ] = seq;
    put32(&out[SK_LINK_O_ORIGIN], origin);
    put32(&out[SK_LINK_O_DST], dst);
    out[SK_LINK_O_ROUTELEN] = routelen;
    for (i = 0; i < routelen; i++) {
        out[n++] = (uint8_t)(route[i] >> 8);
        out[n++] = (uint8_t)route[i];
    }
    for (i = 0; i < applen; i++)
        out[n++] = app[i];
    crc = crc_ref(out, n);
    out[n++] = (uint8_t)(crc >> 8);
    out[n++] = (uint8_t)crc;
    return n;
}

/* ── harness ──────────────────────────────────────────────────────────── */

static int failures, checks;

#define CHECK(cond, ...)                                        \
    do {                                                        \
        checks++;                                               \
        if (!(cond)) {                                          \
            failures++;                                         \
            printf("FAIL %d: ", __LINE__);                      \
            printf(__VA_ARGS__);                                \
            printf("\n");                                       \
        }                                                       \
    } while (0)

/* Short ids for the test's nodes, chosen so they are easy to read in a hex
 * dump: a node id is FNV-1a of a serial in real life, but nothing in the link
 * layer cares where it came from. */
#define ID_AP    0x534B4150UL           /* SK_LINK_AP_ID, same as the firmware */
#define ID_TAG   0xE5C0F240UL           /* FNV-1a of "1408F525" */
#define ID_OTHER 0xA82F4A55UL           /* FNV-1a of "ABCD1234" */

static const uint8_t APP[] = { SK_PROTO_VERSION, SK_PKT_IMG_DATA, 0x00, 0xC0,
                               0x40, 0x41, 0x42, 0x43 };
#define APP_LEN ((uint8_t)sizeof APP)

/* The payload sk_link_poll() delivered, and whether it delivered one. */
static uint8_t got[SK_LINK_MAX];
static uint8_t got_len;

/* Push a frame in and examine it exactly once, the way a firmware loop does:
 * one call to sk_link_poll(). The metadata accessors (relayed, dup, bad,
 * origin, route) describe that one frame and stay valid until the next poll
 * examines another, so they are checked before anything else polls again. */
static uint8_t receive(const uint8_t *frame, uint8_t len)
{
    push_air(frame, len);
    got_len = sk_link_poll(got, sizeof got);
    return got_len;
}

/* Let a scheduled relay's backoff expire, advancing the virtual clock. The
 * link layer delays a millisecond itself on each poll while a forward is
 * pending, and this adds one more per iteration (as both firmwares' loops
 * do), so the wall-clock wait is up to twice the tick count - see the note on
 * SK_LINK_BACKOFF_MS in sk_link.h. Hence the bound below. */
static void pump_relay(int want_tx)
{
    uint32_t t0 = virtual_ms;

    while (tx_n < want_tx &&
           virtual_ms - t0 < 2 * (uint32_t)SK_LINK_BACKOFF_MS + 8) {
        if (sk_link_poll(got, sizeof got))
            return;
        delay(1000);
    }
}

/* ── 1. the CRC and the id ────────────────────────────────────────────── */

static void test_crc(void)
{
    static const uint8_t check[] = "123456789";
    uint8_t buf[6];
    uint8_t i;

    printf("-- CRC-16/CCITT-FALSE\n");
    CHECK(sk_crc16(check, 9, 0xFFFF) == 0x29B1,
          "check value is %04X, wanted 29B1", sk_crc16(check, 9, 0xFFFF));
    CHECK(sk_crc16(check, 0, 0xFFFF) == 0xFFFF, "empty input must leave the CRC alone");

    /* A handful of byte strings, against the reference implementation. */
    for (i = 0; i < 6; i++)
        buf[i] = (uint8_t)(i * 37 + 1);
    for (i = 1; i <= 6; i++)
        CHECK(sk_crc16(buf, i, 0xFFFF) == crc_ref(buf, i),
              "CRC of %u bytes differs from the reference", i);

    /* Chaining: two calls with the running value must equal one call. */
    CHECK(sk_crc16(buf + 2, 4, sk_crc16(buf, 2, 0xFFFF)) == crc_ref(buf, 6),
          "chained CRC differs from one call over the whole buffer");
}

static void test_id(void)
{
    printf("-- the compact id\n");
    CHECK(sk_id_from_serial("1408F525", 8) == 0xE5C0F240UL,
          "1408F525 hashes to %08lX", (unsigned long)sk_id_from_serial("1408F525", 8));
    CHECK(sk_id_from_serial("1408f525", 8) == sk_id_from_serial("1408F525", 8),
          "case must not change the id: the two ends read the serial differently");
    CHECK(sk_id_from_serial("ABCD1234", 8) != sk_id_from_serial("1408F525", 8),
          "two serials must not share an id");
    CHECK(sk_id_from_serial("1408F525", 8) == fnv_ref("1408F525"),
          "the id differs from the reference FNV-1a");
    CHECK(sk_id_from_serial("", 0) == 2166136261UL, "the empty serial is the FNV offset basis");
    CHECK(sk_id_from_serial("ABCD1234", 8) == fnv_ref("abcd1234"),
          "lower-case input must fold");
}

/* ── 2. the frame we build ────────────────────────────────────────────── */

static void test_frame_layout(void)
{
    uint8_t n;

    printf("-- the frame sk_link_send() builds\n");
    reset_radio();
    sk_link_init(SK_ROLE_LEAF, ID_TAG);

    CHECK(sk_link_send(ID_AP, APP, APP_LEN) == SK_LINK_OK, "send failed");
    CHECK(tx_n == 1, "%d frames went out, wanted 1", tx_n);

    n = tx_len[0];
    CHECK(n == (uint8_t)(SK_LINK_HDR_LEN + APP_LEN + SK_LINK_CRC_LEN),
          "frame is %u bytes, wanted %u", n,
          (unsigned)(SK_LINK_HDR_LEN + APP_LEN + SK_LINK_CRC_LEN));
    CHECK(tx[0][SK_LINK_O_VER] == SK_LINK_VERSION, "version = %02X", tx[0][SK_LINK_O_VER]);
    CHECK(tx[0][SK_LINK_O_TYPE] == SK_PKT_IMG_DATA,
          "the type is not the application type: %02X", tx[0][SK_LINK_O_TYPE]);
    CHECK((tx[0][SK_LINK_O_CTL] & SK_LINK_CTL_HOPS_MASK) >> SK_LINK_CTL_HOPS_SHIFT
          == SK_LINK_HOPS_INIT, "a fresh frame must start with a full hop budget");
    CHECK(!(tx[0][SK_LINK_O_CTL] & SK_LINK_CTL_ROUTER),
          "a leaf must not set the router flag");
    CHECK(tx[0][SK_LINK_O_ROUTELEN] == 0, "a fresh frame has an empty route");
    CHECK(get32(&tx[0][SK_LINK_O_ORIGIN]) == ID_TAG, "origin is not this node");
    CHECK(get32(&tx[0][SK_LINK_O_DST]) == ID_AP, "destination is wrong");
    CHECK(memcmp(&tx[0][SK_LINK_HDR_LEN], APP, APP_LEN) == 0,
          "the application payload was altered");
    CHECK(tx[0][n - 2] == (uint8_t)(crc_ref(tx[0], (uint8_t)(n - 2)) >> 8) &&
          tx[0][n - 1] == (uint8_t)crc_ref(tx[0], (uint8_t)(n - 2)),
          "the frame CRC is not CRC-16/CCITT-FALSE over the frame");

    /* A second send gets a new sequence number - otherwise the mesh would
     * treat it as a duplicate of the first. */
    CHECK(sk_link_send(ID_AP, APP, APP_LEN) == SK_LINK_OK, "second send failed");
    CHECK(tx_n == 2 && tx[1][SK_LINK_O_SEQ] == (uint8_t)(tx[0][SK_LINK_O_SEQ] + 1),
          "the sequence number did not advance");

    /* A router says so. */
    sk_link_init(SK_ROLE_ROUTER, ID_OTHER);
    CHECK(sk_link_send(SK_LINK_BROADCAST, APP, APP_LEN) == SK_LINK_OK, "broadcast failed");
    CHECK(tx[2][SK_LINK_O_CTL] & SK_LINK_CTL_ROUTER, "a router must set the router flag");
    CHECK(get32(&tx[2][SK_LINK_O_DST]) == SK_LINK_BROADCAST, "broadcast dst is wrong");

    /* Too long to fit: refused, and nothing goes on the air. */
    reset_radio();
    sk_link_init(SK_ROLE_LEAF, ID_TAG);
    CHECK(sk_link_send(ID_AP, APP, (uint8_t)(SK_PKT_MAX + 1)) == SK_LINK_ERR_LEN,
          "an oversized payload must be refused");
    CHECK(tx_n == 0, "%d frames went out for an oversized payload", tx_n);
}

/* ── 3. receiving ─────────────────────────────────────────────────────── */

static void test_receive_delivers(void)
{
    uint8_t frame[SK_LINK_MAX];
    uint8_t n;

    printf("-- a frame for this node is delivered\n");
    reset_radio();
    sk_link_init(SK_ROLE_LEAF, ID_TAG);

    /* Unicast to us. */
    n = build(frame, SK_PKT_IMG_DATA, SK_LINK_HOPS_INIT, 7, ID_AP, ID_TAG, 1,
              NULL, 0, APP, APP_LEN);
    CHECK(receive(frame, n) == APP_LEN, "a unicast frame for this node was not delivered");
    CHECK(memcmp(got, APP, APP_LEN) == 0, "the delivered payload differs");
    CHECK(sk_link_origin() == ID_AP, "origin is wrong");
    CHECK(sk_link_hops() == SK_LINK_HOPS_INIT, "hops left is %u", sk_link_hops());
    CHECK(sk_link_rssi() == fake_rssi, "rssi is wrong");
    CHECK(sk_link_route_len() == 0, "a direct frame has no route");
    CHECK(sk_link_sender_router(), "the sender's role flag was not reported");
    CHECK(!sk_link_dup(), "a fresh frame must not be flagged as a duplicate");
    CHECK(!sk_link_bad(), "a good frame must not be flagged as bad");

    /* A leaf's frame says so, which is what tells the access point whether a
     * wake-up preamble is worth sending. */
    n = build(frame, SK_PKT_IMG_ACK, SK_LINK_HOPS_INIT, 17, ID_OTHER, ID_TAG, 0,
              NULL, 0, APP, APP_LEN);
    CHECK(receive(frame, n) == APP_LEN, "a leaf's frame was not delivered");
    CHECK(sk_link_origin() == ID_OTHER, "the leaf's origin is wrong");
    CHECK(!sk_link_sender_router(), "a leaf's frame was reported as a router's");

    /* Broadcast reaches everyone. */
    n = build(frame, SK_PKT_ANNOUNCE, SK_LINK_HOPS_INIT, 8, ID_AP,
              SK_LINK_BROADCAST, 1, NULL, 0, APP, APP_LEN);
    CHECK(receive(frame, n) == APP_LEN, "a broadcast was not delivered");

    /* Somebody else's unicast is not. */
    n = build(frame, SK_PKT_IMG_DATA, SK_LINK_HOPS_INIT, 9, ID_AP, ID_OTHER, 1,
              NULL, 0, APP, APP_LEN);
    CHECK(receive(frame, n) == 0, "another node's unicast was delivered here");
    CHECK(sk_link_origin() == ID_AP, "the metadata of the undelivered frame was not kept");
}

static void test_receive_rejects_rubbish(void)
{
    uint8_t frame[SK_LINK_MAX];
    uint8_t n;

    printf("-- bad frames are dropped and reported\n");
    reset_radio();
    sk_link_init(SK_ROLE_ROUTER, ID_TAG);

    /* A corrupt CRC. */
    n = build(frame, SK_PKT_IMG_DATA, SK_LINK_HOPS_INIT, 1, ID_AP, ID_TAG, 1,
              NULL, 0, APP, APP_LEN);
    frame[n - 1] ^= 0x01;
    CHECK(receive(frame, n) == 0, "a frame with a bad CRC was delivered");
    CHECK(sk_link_bad(), "a bad CRC must be reported");
    CHECK(!sk_link_dup(), "a bad frame is not a duplicate");
    CHECK(tx_n == 0, "a bad frame must not be relayed");

    /* A one-bit error in the middle, the case the old XOR also caught: the
     * CRC catches it too. */
    n = build(frame, SK_PKT_IMG_DATA, SK_LINK_HOPS_INIT, 2, ID_AP, ID_TAG, 1,
              NULL, 0, APP, APP_LEN);
    frame[SK_LINK_HDR_LEN + 3] ^= 0x40;
    CHECK(receive(frame, n) == 0, "a frame with a flipped bit was delivered");
    CHECK(sk_link_bad(), "the flipped bit was not reported");

    /* Two bit flips an equal distance apart, which a byte-wide XOR cannot
     * see: this is the difference between the old check and this one. */
    n = build(frame, SK_PKT_IMG_DATA, SK_LINK_HOPS_INIT, 3, ID_AP, ID_TAG, 1,
              NULL, 0, APP, APP_LEN);
    frame[SK_LINK_HDR_LEN] ^= 0x01;
    frame[SK_LINK_HDR_LEN + 4] ^= 0x01;
    CHECK(receive(frame, n) == 0, "a frame with two flipped bits was delivered");
    CHECK(sk_link_bad(), "the two-bit error was not reported");

    /* A version this firmware does not speak. */
    n = build(frame, SK_PKT_IMG_DATA, SK_LINK_HOPS_INIT, 4, ID_AP, ID_TAG, 1,
              NULL, 0, APP, APP_LEN);
    frame[SK_LINK_O_VER] = 1;
    frame[n - 2] = (uint8_t)(crc_ref(frame, (uint8_t)(n - 2)) >> 8);
    frame[n - 1] = (uint8_t)crc_ref(frame, (uint8_t)(n - 2));
    CHECK(receive(frame, n) == 0, "an unknown link version was accepted");
    CHECK(sk_link_bad(), "an unknown version was not reported");

    /* A route length that cannot be right. */
    n = build(frame, SK_PKT_IMG_DATA, SK_LINK_HOPS_INIT, 5, ID_AP, ID_TAG, 1,
              NULL, 0, APP, APP_LEN);
    frame[SK_LINK_O_ROUTELEN] = (uint8_t)(SK_LINK_ROUTE_MAX + 1);
    frame[n - 2] = (uint8_t)(crc_ref(frame, (uint8_t)(n - 2)) >> 8);
    frame[n - 1] = (uint8_t)crc_ref(frame, (uint8_t)(n - 2));
    CHECK(receive(frame, n) == 0, "an impossible route length was accepted");

    /* Truncated: the CRC may even be right, the frame still does not add up. */
    CHECK(receive(frame, SK_LINK_HDR_LEN - 1) == 0, "a truncated frame was accepted");
}

/* ── 4. flooding ──────────────────────────────────────────────────────── */

static void test_relay_and_route(void)
{
    uint8_t frame[SK_LINK_MAX];
    uint8_t n, rn;

    printf("-- a router relays somebody else's frame and records itself\n");
    reset_radio();
    sk_link_init(SK_ROLE_ROUTER, ID_OTHER);

    n = build(frame, SK_PKT_IMG_DATA, SK_LINK_HOPS_INIT, 11, ID_AP, ID_TAG, 1,
              NULL, 0, APP, APP_LEN);
    CHECK(receive(frame, n) == 0, "a frame for another node was delivered here");
    CHECK(sk_link_relayed(), "the router did not relay the frame");
    CHECK(sk_link_origin() == ID_AP, "the relay lost the frame's origin");
    CHECK(sk_link_hops() == SK_LINK_HOPS_INIT, "the relay misread the hop budget");

    /* The relay goes out after its backoff, so it is not on the air yet. */
    CHECK(tx_n == 0, "the relay went out before its backoff");

    pump_relay(1);
    CHECK(tx_n == 1, "%d relays went out, wanted 1", tx_n);
    CHECK(virtual_ms <= 2 * (uint32_t)SK_LINK_BACKOFF_MS + 8,
          "the relay waited %u ms, the window is %u", virtual_ms, SK_LINK_BACKOFF_MS);

    rn = tx_len[0];
    CHECK(rn == (uint8_t)(n + 2), "the relayed frame is %u bytes, wanted %u", rn, n + 2);
    CHECK(get32(&tx[0][SK_LINK_O_ORIGIN]) == ID_AP, "the origin was rewritten");
    CHECK(get32(&tx[0][SK_LINK_O_DST]) == ID_TAG, "the destination was rewritten");
    CHECK(tx[0][SK_LINK_O_SEQ] == 11, "the sequence number was rewritten");
    CHECK(tx[0][SK_LINK_O_TYPE] == SK_PKT_IMG_DATA, "the type was not carried through");
    CHECK(((tx[0][SK_LINK_O_CTL] & SK_LINK_CTL_HOPS_MASK) >> SK_LINK_CTL_HOPS_SHIFT)
          == SK_LINK_HOPS_INIT - 1, "the hop budget was not decremented");
    CHECK(tx[0][SK_LINK_O_CTL] & SK_LINK_CTL_ROUTER, "the relay did not set the router flag");
    CHECK(tx[0][SK_LINK_O_ROUTELEN] == 1, "route length is %u", tx[0][SK_LINK_O_ROUTELEN]);
    CHECK((uint16_t)((tx[0][SK_LINK_HDR_LEN] << 8) | tx[0][SK_LINK_HDR_LEN + 1])
          == (uint16_t)ID_OTHER, "the relay did not record its own short id");
    CHECK(memcmp(&tx[0][SK_LINK_HDR_LEN + 2], APP, APP_LEN) == 0,
          "the relayed payload was altered");
    CHECK(tx[0][rn - 2] == (uint8_t)(crc_ref(tx[0], (uint8_t)(rn - 2)) >> 8) &&
          tx[0][rn - 1] == (uint8_t)crc_ref(tx[0], (uint8_t)(rn - 2)),
          "the relayed frame's CRC was not recomputed");

    /* And the far end of that relay gets the payload with the path in hand. */
    reset_radio();
    sk_link_init(SK_ROLE_LEAF, ID_TAG);
    CHECK(receive(tx[0], rn) == APP_LEN,
          "the relayed frame was not delivered at the far end");
    CHECK(sk_link_route_len() == 1 && sk_link_route(0) == (uint16_t)ID_OTHER,
          "the far end did not see the path");
    CHECK(sk_link_hops() == SK_LINK_HOPS_INIT - 1, "the far end saw %u hops left",
          sk_link_hops());
}

static void test_leaf_never_relays(void)
{
    uint8_t frame[SK_LINK_MAX];
    uint8_t n;

    printf("-- a leaf never relays\n");
    reset_radio();
    sk_link_init(SK_ROLE_LEAF, ID_OTHER);

    n = build(frame, SK_PKT_IMG_DATA, SK_LINK_HOPS_INIT, 12, ID_AP, ID_TAG, 1,
              NULL, 0, APP, APP_LEN);
    CHECK(receive(frame, n) == 0, "a frame for another node was delivered to a leaf");
    CHECK(!sk_link_relayed(), "a leaf relayed a frame");
    (void)sk_link_poll(got, sizeof got);
    CHECK(tx_n == 0, "a leaf transmitted a relay");
}

static void test_dedup(void)
{
    uint8_t frame[SK_LINK_MAX];
    uint8_t n;

    printf("-- duplicates are dropped, and our own message coming back is one\n");
    reset_radio();
    sk_link_init(SK_ROLE_ROUTER, ID_OTHER);

    n = build(frame, SK_PKT_IMG_DATA, SK_LINK_HOPS_INIT, 21, ID_AP, ID_TAG, 1,
              NULL, 0, APP, APP_LEN);
    CHECK(receive(frame, n) == 0, "the first copy was delivered");
    CHECK(sk_link_relayed(), "the first copy was not relayed");
    /* Let the relay go out, then hand the very same frame back in: the ring
     * must recognise it. */
    pump_relay(1);
    CHECK(tx_n == 1, "the relay did not go out");
    CHECK(receive(frame, n) == 0, "the second copy was delivered");
    CHECK(sk_link_dup(), "the duplicate was not recognised");
    CHECK(!sk_link_relayed(), "a duplicate must not be relayed again");

    /* A different sequence number is a different message. */
    n = build(frame, SK_PKT_IMG_DATA, SK_LINK_HOPS_INIT, 22, ID_AP, ID_TAG, 1,
              NULL, 0, APP, APP_LEN);
    CHECK(receive(frame, n) == 0, "a new message was delivered to the wrong node");
    CHECK(!sk_link_dup(), "a new message was treated as a duplicate");

    /* Our own message, handed back by a relay: dup, and the origin is us. */
    reset_radio();
    sk_link_init(SK_ROLE_ROUTER, ID_OTHER);
    CHECK(sk_link_send(ID_TAG, APP, APP_LEN) == SK_LINK_OK, "send failed");
    n = tx_len[0];
    {
        uint8_t back[SK_LINK_MAX];
        uint16_t route[1];

        route[0] = 0x1234;
        n = build(back, SK_PKT_IMG_DATA, SK_LINK_HOPS_INIT - 1,
                  tx[0][SK_LINK_O_SEQ], ID_OTHER, ID_TAG, 1, route, 1, APP, APP_LEN);
        CHECK(receive(back, n) == 0, "our own message was delivered back to us");
        CHECK(sk_link_dup(), "our own message coming back was not recognised");
        CHECK(sk_link_origin() == ID_OTHER, "the origin of the returned frame is wrong");
        CHECK(sk_link_route_len() == 1, "the returned frame's route was lost");
    }
}

static void test_hop_limit(void)
{
    uint8_t frame[SK_LINK_MAX];
    uint8_t n;

    printf("-- the hop limit stops a frame going further\n");
    reset_radio();
    sk_link_init(SK_ROLE_ROUTER, ID_OTHER);

    n = build(frame, SK_PKT_IMG_DATA, 0, 31, ID_AP, ID_TAG, 1,
              NULL, 0, APP, APP_LEN);
    CHECK(receive(frame, n) == 0, "a frame for another node was delivered here");
    CHECK(!sk_link_relayed(), "a frame with no hops left was relayed");
    (void)sk_link_poll(got, sizeof got);
    CHECK(tx_n == 0, "a frame with no hops left went out anyway");

    /* One hop left: it may go exactly one more. */
    n = build(frame, SK_PKT_IMG_DATA, 1, 32, ID_AP, ID_TAG, 1,
              NULL, 0, APP, APP_LEN);
    CHECK(receive(frame, n) == 0, "a frame for another node was delivered here");
    CHECK(sk_link_relayed(), "a frame with one hop left was not relayed");
}

static void test_full_route(void)
{
    uint8_t frame[SK_LINK_MAX];
    uint8_t n;
    uint16_t route[SK_LINK_ROUTE_MAX];
    uint8_t i;

    printf("-- a full route stops recording, not forwarding\n");
    reset_radio();
    sk_link_init(SK_ROLE_ROUTER, ID_OTHER);

    for (i = 0; i < SK_LINK_ROUTE_MAX; i++)
        route[i] = (uint16_t)(0x1000 + i);
    n = build(frame, SK_PKT_IMG_DATA, SK_LINK_HOPS_INIT, 41, ID_AP, ID_TAG, 1,
              route, SK_LINK_ROUTE_MAX, APP, APP_LEN);
    CHECK(receive(frame, n) == 0, "a frame for another node was delivered here");
    CHECK(sk_link_relayed(), "a frame with a full route was not relayed");
    CHECK(sk_link_route_len() == SK_LINK_ROUTE_MAX, "the incoming route was misread");

    pump_relay(1);
    CHECK(tx_n == 1, "the relay did not go out");
    CHECK(tx_len[0] == n, "the frame grew: %u bytes, was %u", tx_len[0], n);
    CHECK(tx[0][SK_LINK_O_ROUTELEN] == SK_LINK_ROUTE_MAX,
          "the route length was changed instead of left alone");
    for (i = 0; i < SK_LINK_ROUTE_MAX; i++)
        CHECK((uint16_t)((tx[0][SK_LINK_HDR_LEN + 2 * i] << 8) |
                         tx[0][SK_LINK_HDR_LEN + 2 * i + 1]) == route[i],
              "route entry %u was altered", i);
    CHECK(memcmp(&tx[0][SK_LINK_HDR_LEN + 2 * SK_LINK_ROUTE_MAX], APP, APP_LEN) == 0,
          "the payload moved or was altered");
}

/* ── 5. wake-on-radio and the link's own bookkeeping ──────────────────── */

static void test_rx_mode(void)
{
    uint8_t frame[SK_LINK_MAX];
    uint8_t n;

    printf("-- the receiver is re-armed after a transmission\n");
    reset_radio();
    sk_link_init(SK_ROLE_LEAF, ID_TAG);

    /* Continuous by default: a sender leaves the receiver on the air. */
    CHECK(sk_link_send(ID_AP, APP, APP_LEN) == SK_LINK_OK, "send failed");
    CHECK(rx_start_calls == 1 && rx_wor_calls == 0,
          "after a send in continuous mode: %d start, %d wor", rx_start_calls, rx_wor_calls);

    /* A leaf that has gone to sleep is re-armed into WOR instead, or its own
     * transmissions would wake it back into continuous receive. */
    sk_link_rx_mode(SK_RX_WOR);
    CHECK(sk_link_send(ID_AP, APP, APP_LEN) == SK_LINK_OK, "send failed");
    CHECK(rx_wor_calls == 1 && rx_start_calls == 1,
          "after a send in WOR mode: %d start, %d wor", rx_start_calls, rx_wor_calls);

    /* And the WOR transmit path is the one that asks for the long preamble. */
    CHECK(sk_link_send_wor(ID_AP, APP, APP_LEN) == SK_LINK_OK, "wor send failed");
    CHECK(tx_wor_calls == 1, "the wake-up preamble was used %d times", tx_wor_calls);
    CHECK(sk_link_send(ID_AP, APP, APP_LEN) == SK_LINK_OK, "send failed");
    CHECK(tx_wor_calls == 1, "a plain send used the wake-up preamble");

    /* A failing radio is reported, not ignored. */
    reset_radio();
    tx_fail = 1;
    CHECK(sk_link_send(ID_AP, APP, APP_LEN) == SK_LINK_ERR_RADIO,
          "a refused transmission was not reported");

    /* Receiving does not care which mode the node is in. */
    reset_radio();
    sk_link_init(SK_ROLE_LEAF, ID_TAG);
    sk_link_rx_mode(SK_RX_WOR);
    n = build(frame, SK_PKT_IMG_DATA, SK_LINK_HOPS_INIT, 51, ID_AP, ID_TAG, 1,
              NULL, 0, APP, APP_LEN);
    CHECK(receive(frame, n) == APP_LEN, "a frame was not received in WOR mode");
}

/* ── 6. end to end through the real code ──────────────────────────────── */

/* One relay's worth of a three-node walk: AP -> router -> tag, then the tag's
 * answer straight back. Each step is the real link layer re-initialised as
 * one of the three nodes, and the frames in between are the bytes it actually
 * transmitted - so a wrong hop count, a lost route entry or a CRC that does
 * not survive re-encoding shows up here. */
static void test_end_to_end(void)
{
    uint8_t frame[SK_LINK_MAX];
    uint8_t n, i;

    printf("-- end to end: AP -> router -> tag -> AP\n");
    reset_radio();

    /* 1. the access point sends an image block to the tag (broadcast, as
     *    IMG_BEGIN is, so the router relays it). */
    sk_link_init(SK_ROLE_ROUTER, ID_AP);
    CHECK(sk_link_send(SK_LINK_BROADCAST, APP, APP_LEN) == SK_LINK_OK, "AP send failed");
    CHECK(tx_n == 1, "the AP sent %d frames", tx_n);
    memcpy(frame, tx[0], tx_len[0]);
    n = tx_len[0];

    /* 2. the router hears it, and relays it. */
    reset_radio();
    sk_link_init(SK_ROLE_ROUTER, ID_OTHER);
    CHECK(receive(frame, n) == APP_LEN, "the router did not deliver its own broadcast");
    CHECK(sk_link_relayed(), "the router did not relay the broadcast");
    pump_relay(1);
    CHECK(tx_n == 1, "the router did not relay");
    memcpy(frame, tx[0], tx_len[0]);
    n = tx_len[0];

    /* 3. the tag hears the relay and takes the payload, path and all. */
    reset_radio();
    sk_link_init(SK_ROLE_LEAF, ID_TAG);
    CHECK(receive(frame, n) == APP_LEN, "the tag did not get the relayed frame");
    CHECK(memcmp(got, APP, APP_LEN) == 0, "the payload changed on the way");
    CHECK(sk_link_route_len() == 1, "the tag lost the path");
    CHECK(sk_link_origin() == ID_AP, "the tag lost the origin");

    /* 4. the tag answers the access point directly (it is in range of it),
     *    addressed to the origin of the frame it is answering. */
    reset_radio();
    CHECK(sk_link_send(sk_link_origin(), got, APP_LEN) == SK_LINK_OK, "the reply failed");
    CHECK(get32(&tx[0][SK_LINK_O_DST]) == ID_AP, "the reply is not addressed to the AP");
    memcpy(frame, tx[0], tx_len[0]);
    n = tx_len[0];

    /* 5. the access point takes the answer. */
    reset_radio();
    sk_link_init(SK_ROLE_ROUTER, ID_AP);
    CHECK(receive(frame, n) == APP_LEN, "the AP did not get the answer");
    CHECK(sk_link_origin() == ID_TAG, "the AP cannot tell who answered");
    CHECK(sk_link_route_len() == 0, "the answer should have come straight back");

    /* 6. and the AP does not relay its own answer back into the mesh: it is
     *    addressed to the AP, so the destination rule stops it. */
    {
        int before = tx_n;
        (void)sk_link_poll(got, sizeof got);
        CHECK(tx_n == before, "the AP relayed a frame addressed to itself");
    }
    (void)i;
}

/* ── 7. the constraint both firmwares live under ──────────────────────── */

static int same_file(const char *a, const char *b)
{
    FILE *fa = fopen(a, "rb"), *fb = fopen(b, "rb");
    int ca, cb, same = 1;

    if (!fa || !fb)
        return 0;
    for (;;) {
        ca = fgetc(fa);
        cb = fgetc(fb);
        if (ca != cb) {
            same = 0;
            break;
        }
        if (ca == EOF)
            break;
    }
    fclose(fa);
    fclose(fb);
    return same;
}

static void test_copies_identical(void)
{
    printf("-- the two firmwares carry the same link and radio\n");
    CHECK(same_file("firmware/shelfkit-vusion/src/sk_link.c",
                    "firmware/access-point/src/sk_link.c"),
          "sk_link.c differs between the tag and the access point");
    CHECK(same_file("firmware/shelfkit-vusion/src/radio.c",
                    "firmware/access-point/src/radio.c"),
          "radio.c differs between the tag and the access point");
    CHECK(same_file("firmware/shelfkit-vusion/src/radio.h",
                    "firmware/access-point/src/radio.h"),
          "radio.h differs between the tag and the access point");
}

/* ── main ─────────────────────────────────────────────────────────────── */

int main(void)
{
    printf("ShelfKit link layer tests (the real firmware/*/src/sk_link.c, on the PC)\n\n");

    test_crc();
    test_id();
    test_frame_layout();
    test_receive_delivers();
    test_receive_rejects_rubbish();
    test_relay_and_route();
    test_leaf_never_relays();
    test_dedup();
    test_hop_limit();
    test_full_route();
    test_rx_mode();
    test_end_to_end();
    test_copies_identical();

    printf("\n%u checks, %s\n", checks, failures ? "FAILURES" : "all passed");
    return failures ? 1 : 0;
}
