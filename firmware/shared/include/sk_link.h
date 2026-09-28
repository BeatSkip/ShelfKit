/**
 * @file sk_link.h
 * @brief The ShelfKit link layer: frame, CRC, addressing, managed flooding
 *
 * One file, kept byte-identical between firmware/shelfkit-vusion and
 * firmware/access-point (the same rule radio.c/radio.h follow), because both
 * ends must agree on every field of the frame. The frame layout itself is
 * documented in firmware/shared/include/shelfkit_proto.h, next to the
 * application protocol it wraps.
 *
 * What this layer is for:
 *
 *   * a CRC-16/CCITT-FALSE over every frame, instead of the one-byte XOR the
 *     old link used - the XOR is what made it "mostly works";
 *   * addressing by a 4-byte id derived from a node's serial (sk_id_from_serial),
 *     so an address costs four bytes instead of an ASCII serial per frame;
 *   * managed flooding: a message id, a hop budget, a small ring of recently
 *     seen ids, and a random backoff before a relay repeats a frame. No
 *     routing table, no neighbour discovery, no state that has to survive a
 *     reboot - the whole point is that it fits in a tag's RAM;
 *   * a record route: every relay appends its own two-byte short id, so the
 *     receiver holds the exact chain the frame travelled and can print it.
 *
 * Roles. A router (a mains-powered board) stays in continuous receive and
 * relays other nodes' traffic. A leaf (a battery tag) never relays, so it can
 * spend its life in wake-on-radio - see radio.h's WOR section. The role only
 * changes two decisions in here (relay or not, and whether the sender's role
 * flag is set), but it is what makes the same firmware fit both jobs.
 *
 * RAM: the frames are in XRAM, not internal RAM - two of them (receive and
 * the one being forwarded) plus the seen ring. On the tag that is around
 * 350 bytes of its 8192, and none of the 128 bytes of directly addressable
 * RAM, which is why every function here is __reentrant and every static in
 * sk_link.c carries an explicit __xdata.
 *
 * The buffer parameters are __xdata pointers for the same reason. On an 8051
 * every access through a *generic* pointer is library code, and typing these
 * as generic pointers cost a few hundred bytes across the two firmwares for
 * nothing: every real caller passes an XRAM buffer. A caller that ever needs
 * to hash something in __code (a constant table, say) needs its own entry
 * point rather than a cast.
 */

#ifndef SK_LINK_H
#define SK_LINK_H

#include <libmftypes.h>

#include "shelfkit_proto.h"

/* ── roles ───────────────────────────────────────────────────────────── */

#define SK_ROLE_LEAF      0     /* battery: never relays, lives in WOR */
#define SK_ROLE_ROUTER    1     /* mains: stays awake, relays for others */

/* ── sk_link_send() results ──────────────────────────────────────────── */

#define SK_LINK_OK        0
#define SK_LINK_ERR_RADIO 1     /* radio_tx() refused the frame */
#define SK_LINK_ERR_LEN   2     /* payload does not fit in a frame */

/* ── the flooding parameters ─────────────────────────────────────────────
 *
 * SK_LINK_SEEN is the whole of the mesh's memory: the last N (origin, seq)
 * pairs this node has handled. Eight is enough for a house - duplicates of a
 * frame arrive within a few hundred milliseconds of each other, and a
 * broadcast storm is not what this is designed for - and it costs 40 bytes of
 * XRAM. The tradeoff is stated plainly: a duplicate that turns up more than
 * eight messages later is not recognised as one, so it is relayed a second
 * time. That is a duplicate on the air, not a wrong answer, because the
 * application layer is stop-and-wait and answers a repeated frame the same
 * way it answered the first.
 *
 * SK_LINK_BACKOFF_MS is the window a relay picks its forwarding delay from:
 * (origin, seq, my id) is hashed into it, so two relays hearing the same
 * frame almost always pick different delays and the copies do not start on
 * top of each other. A power of two so the mask is cheap on an 8051. It is
 * deliberately shorter than a frame's air time (~200 ms for an image block
 * at 4800 bit/s): two relays in the same house rarely fire together, and a
 * window longer than a frame would add a fifth of a second to every hop. */
#define SK_LINK_SEEN        8
#define SK_LINK_BACKOFF_MS  96

/* ── API ────────────────────────────────────────────────────────────────
 * Every function is __reentrant for the reason above: parameters and locals
 * ride the stack rather than a parameter block in the 128 bytes of internal
 * RAM that this part shares with the stack. */

/* How the receiver is left after this node transmits. radio_tx() powers the
 * chip down when it is done, so somebody has to put it back on the air or the
 * node goes deaf after every packet it sends - and the two modes a node can
 * be in are the two radio.h offers. Doing it here rather than at every call
 * site is what keeps a leaf in wake-on-radio across its own transmissions. */
#define SK_RX_CONTINUOUS  0     /* radio_rx_start() */
#define SK_RX_WOR         1     /* radio_rx_wor_start() */

/* Set the node up. @p role is SK_ROLE_LEAF or SK_ROLE_ROUTER and @p my_id is
 * this node's address (sk_id_from_serial(), or SK_LINK_AP_ID for the access
 * point). Call once, before the first send or poll. */
void sk_link_init(uint8_t role, uint32_t my_id) __reentrant;

/* Choose what the receiver does after a transmission (SK_RX_*). Continuous
 * unless this is called; sk_link_init() does not change it, so a firmware
 * that never uses WOR never has to know this exists. A leaf sets SK_RX_WOR
 * while it is asleep and SK_RX_CONTINUOUS while it is awake. */
void sk_link_rx_mode(uint8_t mode) __reentrant;

uint8_t  sk_link_role(void) __reentrant;
uint32_t sk_link_id(void) __reentrant;

/* Build a frame around @p app (an application payload, @p len bytes) and
 * transmit it. @p dst is a node id or SK_LINK_BROADCAST. Returns SK_LINK_OK,
 * SK_LINK_ERR_LEN or SK_LINK_ERR_RADIO.
 *
 * The short form uses the normal preamble. The _wor form prefixes the
 * vendor's wake-on-radio preamble, which is how a sleeping leaf is woken;
 * it is ~270 ms of extra air time, so it is for the first frame to a peer
 * that may be asleep, not for every frame. */
uint8_t sk_link_send(uint32_t dst, const uint8_t __xdata *app, uint8_t len) __reentrant;
uint8_t sk_link_send_wor(uint32_t dst, const uint8_t __xdata *app, uint8_t len) __reentrant;

/* Non-blocking: 0 when no application payload is waiting, else the length of
 * the payload copied into @p app. A frame addressed to this node (or
 * broadcast) is copied up; a frame for someone else is not, but is still
 * relayed if this node is a router and the hop budget allows it.
 *
 * Whatever the return value, the metadata accessors below describe the frame
 * that was just examined - so a duplicate, or a relayed copy of this node's
 * own frame coming back, can be reported as well as delivered. */
uint8_t sk_link_poll(uint8_t __xdata *app, uint8_t maxlen) __reentrant;

/* Non-zero when the last frame sk_link_poll() examined was dropped because
 * its (origin, seq) was already in the seen ring: a duplicate, or (for the
 * node that originated the message) the mesh handing its own frame back
 * through a relay. With the accessors below this is the whole relay trace. */
uint8_t sk_link_dup(void) __reentrant;

/* Non-zero when the last frame sk_link_poll() examined was scheduled for
 * forwarding - i.e. this node is a router and it just relayed someone else's
 * traffic. Set only once per frame, and cleared by the next poll that
 * examines one, so a caller can log it exactly once:
 *
 *     relay msg 1A src 534B4150 hops 4->3
 *
 * The frame goes out after the backoff, not at the moment this is set. */
uint8_t sk_link_relayed(void) __reentrant;

/* Non-zero when the last frame sk_link_poll() examined was heard but could
 * not be used: a CRC failure, a version this firmware does not speak, or a
 * length that does not add up. The counterpart of the old "xor BAD" trace -
 * it is what tells "the radio is hearing nothing" from "the radio is hearing
 * rubbish", and therefore whether to look at the aerial or at the protocol.
 * Nothing is delivered and nothing is forwarded in that case: guessing at a
 * corrupt frame is how the wrong bytes get staged. */
uint8_t sk_link_bad(void) __reentrant;

/* Non-zero when the node that sent the last frame this one examined is a
 * router (it set the role flag). This is what lets a sender decide whether a
 * wake-up preamble is worth sending: a router is awake by definition, and
 * 270 ms of preamble in front of every frame to it is pure waste. */
uint8_t sk_link_sender_router(void) __reentrant;

/* Metadata of the last frame sk_link_poll() examined. */
uint32_t sk_link_origin(void) __reentrant;  /* who first sent it */
uint32_t sk_link_dst(void) __reentrant;     /* who it is for, 0 = broadcast */
uint8_t  sk_link_seq(void) __reentrant;     /* its sequence number */
uint8_t  sk_link_hops(void) __reentrant;    /* hops left when it arrived */
uint8_t  sk_link_route_len(void) __reentrant;
uint16_t sk_link_route(uint8_t i) __reentrant;  /* short id of relay i */
int8_t   sk_link_rssi(void) __reentrant;    /* dBm at the last hop */

#endif /* SK_LINK_H */
