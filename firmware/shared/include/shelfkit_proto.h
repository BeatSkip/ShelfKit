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
 *   last    1     checksum: XOR of every byte before it
 *
 * The checksum exists because radio.c runs the AX5043 with its hardware
 * CRC off (see the note there): the chip's CRC covers a packet whose
 * boundaries depend on how the sync word and the preamble are accounted
 * for, and getting that wrong is silent. A byte-wide XOR is trivially
 * verifiable on both ends and is enough to throw away noise.
 *
 * ── over the air: tag -> access point ────────────────────────────────────
 *
 *   SK_PKT_ANNOUNCE    0x01  [ver][type][slen][serial n][xor]
 *                            the tag boots, read its serial from the NFC
 *                            chip and says so, three times.
 *
 *   SK_PKT_IMG_ACK     0x13  [ver][type][off_hi][off_lo][status][xor]
 *                            "I have every image byte below off". Also the
 *                            answer to IMG_BEGIN (off = 0) and to IMG_END
 *                            (off = total, status = the CRC verdict).
 *
 *   SK_PKT_IMG_STATUS  0x14  [ver][type][slen][serial n][status][xor]
 *                            a transfer was refused or failed: wrong
 *                            serial, flash not writable, and so on.
 *
 * ── over the air: access point -> tag ────────────────────────────────────
 *
 *   SK_PKT_IMG_BEGIN   0x10  [ver][type][slen][serial n]
 *                            [total_hi][total_lo][crc_hi][crc_lo][xor]
 *                            addressed to one tag by serial. The tag
 *                            answers with IMG_ACK(off = 0)
 *                            (status = SK_ST_OK) or with IMG_STATUS.
 *
 *   SK_PKT_IMG_DATA    0x11  [ver][type][off_hi][off_lo][data k][xor]
 *                            k <= SK_IMG_DATA_MAX, off = the image byte
 *                            offset of data[0]. The tag answers every one
 *                            with IMG_ACK(off = next byte it still needs),
 *                            so a lost frame is retried rather than
 *                            silently skipped.
 *
 *   SK_PKT_IMG_END     0x12  [ver][type][xor]
 *                            no more data. The tag flushes its last flash
 *                            page, verifies the image CRC from IMG_BEGIN,
 *                            displays the image and answers
 *                            IMG_ACK(off = SK_IMG_TOTAL_BYTES, status).
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

/* Total worst-case radio payload, including the trailing checksum. The
 * largest is an IMG_DATA frame (SK_HDR_LEN + 2 offset bytes + 96 + xor),
 * and every other packet type fits well inside it. */
#define SK_PKT_MAX          (SK_HDR_LEN + 2 + SK_IMG_DATA_MAX + 1)

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

/* XOR of len bytes - the protocol's whole integrity check (radio.c).
 * __reentrant keeps its parameter block off the 8051's 128 bytes of
 * directly addressable RAM; see the note in nfc.c. */
uint8_t sk_checksum(const uint8_t *buf, uint8_t len) __reentrant;

#endif /* SHELFKIT_PROTO_H */
