/**
 * @file shelfkit_proto.h
 * @brief Air protocol between ShelfKit tags and the access point
 *
 * Both ends run the AX5043 in the same configuration (see the radio.c of
 * each firmware - every parameter is a #define there, and the two ends must
 * agree on all of them):
 *
 *   modulation  FSK, h = 2/3
 *   carrier     868.300 MHz
 *   bit rate    4800 bit/s, deviation 1600 Hz
 *   framing     raw + pattern match, one length byte, chip CRC off
 *
 * These are the values AX-RadioLAB generated for this board (see
 * documentation/reference/VusionLink). radio.c writes the preamble, the
 * sync word and the length byte itself, because in raw pattern match mode
 * the packet controller neither adds them nor checks a CRC. On the air a
 * packet is therefore
 *
 *   [ 0xAA x4 ] [ 93 0B 51 DE ] [ LEN ] [ payload ]
 *
 * and LEN counts itself plus the payload.
 *
 * A payload always starts with a version byte and a type byte:
 *
 *   offset  size  field
 *   0       1     protocol version (SK_PROTO_VERSION)
 *   1       1     packet type (SK_PKT_*)
 *   2       ...   type-specific body
 *
 * There is no checksum in the application payload: integrity is the link
 * frame's CRC-16 (see the next section). Until the mesh work this payload
 * ended with a one-byte XOR of everything before it, which is what made the
 * old link "mostly works" - it catches a single flipped bit and very little
 * else, and a 101-byte image block inverted in one bit at each end of the
 * frame got through it.
 *
 * ── the link frame: what actually goes on the air ────────────────────────
 *
 * The application payload above travels inside a link frame built by
 * firmware/<project>/src/sk_link.c (byte-identical in both firmwares):
 *
 *   offset  size  field
 *   0       1     link version (SK_LINK_VERSION)
 *   1       1     packet type (SK_PKT_*)
 *   2       1     control: hops left in the high nibble, role flag in bit 0
 *   3       1     sequence number (per origin, wraps at 256)
 *   4       4     origin id: the node that first sent this frame
 *   8       4     destination id (SK_LINK_BROADCAST = 0 for "everyone")
 *   12      1     route length n: how many relays have recorded themselves
 *   13      2*n   route: the 2-byte short id of each relay, in order
 *   13+2n   ..    the application payload (version, type, body)
 *   last    2     CRC-16/CCITT-FALSE over everything before it, big-endian
 *
 * The id is FNV-1a/32 of the node's serial number with the letters
 * upper-cased (sk_id_from_serial) - the same compact address the NB-Fi work
 * used, and the one thing about it worth keeping: it is 4 bytes in every
 * frame instead of an ASCII serial, and both ends can compute a tag's id
 * from its file name without ever having heard it. A serial still travels in
 * SK_PKT_ANNOUNCE, because the host tooling and the image file names are
 * built on it.
 *
 * The route is the mesh's record-route: every router that forwards the frame
 * appends its own short id (the low 16 bits of its full id - display only,
 * never used for addressing, so a collision there is cosmetic). It is
 * bounded by SK_LINK_ROUTE_MAX; a frame that has already recorded that many
 * relays is still forwarded, it just stops recording. The last hop's rssi and
 * the whole chain are what let an operator answer "which router is my
 * far-room tag using" from one console.
 *
 * The CRC is the link's only integrity check and it is the one the UART side
 * already uses: CRC-16/CCITT-FALSE, poly 0x1021, init 0xFFFF, MSB first, no
 * reflection, no final xor. Check value of "123456789" is 0x29B1, pinned by
 * tools/tests/sk_link_test.c and by tools/tests/test_send_image.py. Note that
 * libmf's *other* entry point, crc_crc16_msb() (poly 0x8005), is a different
 * CRC entirely - the names are one letter apart, so sk_link.c implements its
 * own rather than trusting a name lookup.
 *
 * ── over the air: tag -> access point ────────────────────────────────────
 *
 *   SK_PKT_ANNOUNCE    0x01  [ver][type][slen][serial n]
 *                            the tag boots, reads its serial from the NFC
 *                            chip and says so, three times. Broadcast (dst =
 *                            SK_LINK_BROADCAST), because the access point may
 *                            not know this tag exists yet.
 *
 *   SK_PKT_IMG_ACK     0x13  [ver][type][off_hi][off_lo][status]
 *                            "I have every image byte below off". Also the
 *                            answer to IMG_BEGIN (off = 0) and to IMG_END
 *                            (off = total, status = the CRC verdict).
 *                            Addressed to the origin of the frame it answers.
 *
 *   SK_PKT_IMG_STATUS  0x14  [ver][type][slen][serial n][status]
 *                            a transfer was refused or failed: wrong
 *                            serial, flash not writable, and so on.
 *
 * ── over the air: access point -> tag ────────────────────────────────────
 *
 *   SK_PKT_IMG_BEGIN   0x10  [ver][type][slen][serial n]
 *                            [total_hi][total_lo][crc_hi][crc_lo]
 *                            addressed to one tag by serial. Still broadcast
 *                            on the air: every tag in range hears it, the
 *                            ones it is not for answer IMG_STATUS +
 *                            SK_ST_BAD_SERIAL, and the access point uses
 *                            those to tell "wrong tag" from "no tag". The tag
 *                            answers with IMG_ACK(off = 0) (status =
 *                            SK_ST_OK) or with IMG_STATUS.
 *
 *   SK_PKT_IMG_DATA    0x11  [ver][type][off_hi][off_lo][data k]
 *                            k <= SK_IMG_DATA_MAX, off = the image byte
 *                            offset of data[0]. Addressed to the target tag's
 *                            id, so a mesh does not fill with other tags'
 *                            image blocks. The tag answers every one with
 *                            IMG_ACK(off = next byte it still needs), so a
 *                            lost frame is retried rather than silently
 *                            skipped.
 *
 *   SK_PKT_IMG_END     0x12  [ver][type]
 *                            no more data. The tag flushes its last flash
 *                            page, verifies the image CRC from IMG_BEGIN,
 *                            displays the image and answers IMG_ACK(off =
 *                            SK_IMG_TOTAL_BYTES, status).
 *
 * ── the image itself ─────────────────────────────────────────────────────
 *
 * Two monochrome planes in the panel's own framebuffer format (see epd.h):
 * the black/white plane first, then the red plane, each SK_IMG_PLANE_BYTES
 * long, row major, MSB first within a byte, 0 = ink, 1 = white. The whole
 * image is therefore SK_IMG_TOTAL_BYTES = 11248 bytes, which is far too
 * much for the tag's 8 KB of XRAM: the tag stages it in its SPI flash at
 * SK_IMG_FLASH_ADDR and streams it to the panel from there.
 */

#ifndef SHELFKIT_PROTO_H
#define SHELFKIT_PROTO_H

#if defined(SDCC)
#include <libmftypes.h>
#else
#include <stdint.h>
#endif

#define SK_PROTO_VERSION    1

/* ── radio packet types ──────────────────────────────────────────────── */

#define SK_PKT_ANNOUNCE     0x01    /* tag -> AP: "I exist, this is my serial" */

#define SK_PKT_IMG_BEGIN    0x10    /* AP -> tag: start an image transfer */
#define SK_PKT_IMG_DATA     0x11    /* AP -> tag: one block of image bytes */
#define SK_PKT_IMG_END      0x12    /* AP -> tag: that was all of it */
#define SK_PKT_IMG_ACK      0x13    /* tag -> AP: next byte I still need */
#define SK_PKT_IMG_STATUS   0x14    /* tag -> AP: refused, or failed */

/* ── status codes (IMG_ACK, IMG_STATUS) ──────────────────────────────── */

#define SK_ST_OK            0       /* nothing wrong */
#define SK_ST_BAD_SERIAL    1       /* not my serial number */
#define SK_ST_FLASH         2       /* SPI flash erase or write failed */
#define SK_ST_CRC           3       /* image CRC does not match */
#define SK_ST_OFFSET        4       /* data frame out of order */
#define SK_ST_BUSY          5       /* already in a transfer */
#define SK_ST_UNSUPPORTED   6       /* do not know that packet type */

/* ── payload and image sizes ─────────────────────────────────────────── */

/* Longest serial we carry (the UID fallback is 14 hex characters) */
#define SK_SERIAL_MAX       16

/* Header bytes before a serial number: version, type, length */
#define SK_HDR_LEN          3

/* The shortest an application payload can be: a version byte and a type byte.
 * SK_PKT_IMG_END is exactly that, and SK_HDR_LEN is *not* the right minimum to
 * test it against - that constant counts the length byte only the packets
 * carrying a serial have, and testing IMG_END against it silently drops every
 * one of them. (It cost a hardware session: the tag staged all 11248 bytes and
 * then never saw the END, so the transfer was abandoned 82 s later.) */
#define SK_MIN_PAYLOAD      2

/* Bytes of image data in one SK_PKT_IMG_DATA frame. The radio's receiver
 * generates FIFO chunks of up to 240 bytes (AX5043 PKTCHUNKSIZE = 0x0D,
 * manual table 183), and radio_rx() reads exactly one chunk, so a payload
 * has to stay under 239 bytes; 96 keeps the whole transmit FIFO image
 * comfortably small and still gives ~19000 byte/s of goodput at 4800 bps.
 * The same number is the data block of one UART frame, so the access point
 * never has to re-block anything. */
#define SK_IMG_DATA_MAX     96

/* The flat-addressable image: 152 x 296 pixels, one bit each, two planes */
#define SK_IMG_W            152
#define SK_IMG_H            296
#define SK_IMG_PLANE_BYTES  5624    /* 152 * 296 / 8 */
#define SK_IMG_PLANES       2       /* black/white, then red */
#define SK_IMG_TOTAL_BYTES  (SK_IMG_PLANE_BYTES * SK_IMG_PLANES)    /* 11248 */

/* Where a received image is staged in the tag's SPI flash. The upper half
 * of the 128 KiB part: the lower half keeps whatever the factory left
 * there, which tools/memdump.py can still read out. */
#define SK_IMG_FLASH_ADDR   0x10000UL

/* Total worst-case application payload. The largest is an IMG_DATA frame
 * (SK_HDR_LEN + 2 offset bytes + 96), and every other packet type fits well
 * inside it. No checksum byte is counted here any more - see the link frame
 * in the header comment. */
#define SK_PKT_MAX          (SK_HDR_LEN + 2 + SK_IMG_DATA_MAX)

/* ── the link frame (see the header comment for the layout) ─────────────
 *
 * Byte offsets into the frame sk_link.c builds and parses. They are here,
 * next to the application protocol they wrap, so both firmwares and the host
 * test read the same numbers. */

#define SK_LINK_VERSION     2

#define SK_LINK_O_VER       0
#define SK_LINK_O_TYPE      1
#define SK_LINK_O_CTL       2
#define SK_LINK_O_SEQ       3
#define SK_LINK_O_ORIGIN    4       /* 4 bytes, big-endian on the air */
#define SK_LINK_O_DST       8       /* 4 bytes, 0 = broadcast */
#define SK_LINK_O_ROUTELEN  12
#define SK_LINK_O_ROUTE     13      /* 2 bytes per recorded relay */
#define SK_LINK_HDR_LEN     13      /* through the route-length byte */
#define SK_LINK_CRC_LEN     2

/* How many relays a frame may record itself through. Also the hop budget a
 * frame starts with: a house is a handful of rooms across, so four hops is
 * already generous, and every extra possible hop is 2 more bytes in the
 * worst-case frame. */
#define SK_LINK_ROUTE_MAX   4
#define SK_LINK_HOPS_INIT   4

/* Control byte: hops left in the high nibble, flags in the low one. */
#define SK_LINK_CTL_HOPS_MASK   0xF0
#define SK_LINK_CTL_HOPS_SHIFT  4
#define SK_LINK_CTL_ROUTER      0x01    /* the sender stays awake and relays */

/* The broadcast address. A real tag id is FNV-1a/32 of its serial, so 0 is
 * as good as any other value that hash will not produce in practice. */
#define SK_LINK_BROADCAST   0x00000000UL

/* The access point's own id. It has no NFC serial to hash, and there is one
 * access point in this design, so the id is a fixed constant ('S','K','A','P')
 * rather than something it has to discover. A second access point would need
 * its own - build with -DSK_LINK_AP_ID=... - or the two would answer each
 * other's traffic. */
#ifndef SK_LINK_AP_ID
#define SK_LINK_AP_ID       0x534B4150UL
#endif

/* Largest frame on the air: header, a full record route, a full application
 * payload and the CRC. radio.c sizes its transmit FIFO and the chip's
 * PKTMAXLEN from this. */
#define SK_LINK_MAX \
    (SK_LINK_HDR_LEN + 2 * SK_LINK_ROUTE_MAX + SK_PKT_MAX + SK_LINK_CRC_LEN)

/* ── the serial-port protocol (host <-> access point) ─────────────────────
 *
 * The access point bridges its serial port to the radio. A frame is
 *
 *   [0xAA][0x55][TYPE][LEN][LEN payload bytes][CRC hi][CRC lo]
 *
 * with CRC = CRC-16/CCITT-FALSE (poly 0x1021, init 0xFFFF, MSB first, no
 * reflection, no final xor) over TYPE, LEN and the payload. On the access
 * point that is libmf's crc_ccitt_msb(buf, len, 0xFFFF); on the host it is
 * binascii.crc_hqx(data, 0xFFFF). Note that libmf's *other* entry point,
 * crc_crc16_msb(), is a different CRC entirely (poly 0x8005, CRC-16/UMTS) -
 * the names are one letter apart and the wrong one fails silently, so the
 * check value for "123456789" is 0x29B1 for what this protocol uses.
 * A receiver that sees a bad CRC, a bad length or an unknown
 * type resynchronises on the next 0xAA 0x55.
 *
 * Host -> access point:
 *   SK_U_IMG_BEGIN  0x01  [slen][serial n][total_hi][total_lo][crc hi][crc lo]
 *   SK_U_IMG_DATA   0x02  [off_hi][off_lo][data k]        k <= SK_IMG_DATA_MAX
 *   SK_U_IMG_END    0x03  (no payload)
 *
 * Access point -> host, one answer per frame (stop and wait):
 *   SK_U_ACK        0x81  [off_hi][off_lo][status]
 *                         off = how much of the image the tag has confirmed
 *   SK_U_STATUS     0x82  [status][detail]
 *                         the access point could not deliver: no tag
 *                         answered (SK_ST_BAD_SERIAL or no answer at all),
 *                         the radio failed, or the tag reported an error.
 */

#define SK_UART_SYNC0       0xAA
#define SK_UART_SYNC1       0x55

#define SK_U_IMG_BEGIN      0x01
#define SK_U_IMG_DATA       0x02
#define SK_U_IMG_END        0x03

#define SK_U_ACK            0x81
#define SK_U_STATUS         0x82

/* Longest UART payload: an IMG_DATA frame with a full data block */
#define SK_UART_PAYLOAD_MAX (2 + SK_IMG_DATA_MAX)

/* ── link-frame helpers (sk_link.c, byte-identical in both firmwares) ────
 *
 * __reentrant keeps their parameter blocks off the 8051's 128 bytes of
 * directly addressable RAM; see the note in nfc.c. */

/* CRC-16/CCITT-FALSE over @p len bytes: poly 0x1021, init 0xFFFF, MSB first,
 * no reflection, no final xor - the same CRC the UART protocol and the image
 * CRC use, so there is exactly one CRC-16 in this project. Chained by
 * passing the previous return value as @p crc; start with 0xFFFF. "123456789"
 * must come out as 0x29B1. */
uint16_t sk_crc16(const uint8_t __xdata *buf, uint8_t len, uint16_t crc) __reentrant;

/* The compact node id: FNV-1a/32 of a serial number. Letters are folded to
 * upper case first, because the access point folds case when it compares
 * serials ("1408f525" out of an NDEF URI and "1408F525" out of an image file
 * name are the same tag and must hash to the same id). */
uint32_t sk_id_from_serial(const char __xdata *serial, uint8_t len) __reentrant;

#endif /* SHELFKIT_PROTO_H */
