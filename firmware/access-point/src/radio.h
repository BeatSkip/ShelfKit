/**
 * @file radio.h
 * @brief AX5043 radio driver for the ShelfKit tag <-> access point link
 *
 * The AX8052F143 has the AX5043 transceiver on the same die, and the
 * microcontroller reaches it through a register window in X address space
 * (0x4000...) that libmf's radio_read8()/radio_write8() macros drive - not
 * through the SPI pins PC1..PC3. The radio therefore never competes with
 * the NFC chip or the e-paper for the shared SPI bus.
 *
 * ── Where the numbers come from ──────────────────────────────────────
 * Everything the two ends of a link must agree on is defined here, and all
 * of it is copied from the vendor's own working configuration for this
 * board: the AX-RadioLAB generated register table of the AXSEM
 * "VusionLink" sample project,
 *
 *   documentation/reference/VusionLink/AX_Radio_Lab_output/config.c
 *
 * which announces itself as
 *
 *   TX: fcarrier = 868.300 MHz dev = 1.600 kHz br = 4.800 kBit/s pwr = 15.0 dBm
 *   RX: fcarrier = 868.300 MHz bw = 7.200 kHz br = 4.800 kBit/s
 *
 * So: FSK (h = 2/3), 4800 bit/s, 1600 Hz deviation, a 26 MHz reference and
 * RAW + PATTERN MATCH framing with the chip's CRC off. radio.c carries the
 * whole register table, the init/calibration sequence and the FIFO chunk
 * sequence, each block labelled with the reference function it mirrors.
 *
 * The one thing the reference does not decide for us is the packet layer:
 * VusionLink carries a Vusion MAC (four address bytes, ACKs, six channels,
 * a software CRC-16) which this link does not need, because both ends are
 * our own firmware. What we put on the air is the ShelfKit link frame from
 * sk_link.c - addressing, a CRC-16, a hop budget and a record route - and
 * its layout, and the reasoning behind each field, is in
 * firmware/shared/include/shelfkit_proto.h. This driver treats it as opaque
 * bytes with a length: it writes the preamble, the sync word and the length
 * byte, and the chip's own address filter and CRC stay off (see the note in
 * radio.c).
 *
 * ── The reference clock ──────────────────────────────────────────────
 * The reference is a 26 MHz TCXO on CLK16P/N, not a crystal: config.c has
 * XTALOSC (0xF10) = 0x04, XTALAMPL (0xF11) = 0x00 and XTALCAP = 0x00, and
 * XTALAMPL = 0x07 / XTALOSC = 0x03 is what an on-chip crystal would need.
 * A chip left in crystal mode on a TCXO board never starts its oscillator,
 * which is exactly what "XTALSTATUS bit 0 never goes high" looks like. If
 * the clock still does not come up on hardware, those two registers are the
 * first thing to try.
 *
 *   register value for this link: RADIO_XTALOSC / RADIO_XTALAMPL below.
 */

#ifndef RADIO_DRIVER_H
#define RADIO_DRIVER_H

#include <ax8052f143.h>
#include <libmftypes.h>

/* ── link parameters: BOTH ENDS MUST MATCH ───────────────────────────── */

/* 26 MHz reference (config.c: axradio_fxtal = 26000000) */
#define RADIO_FXTAL_HZ       26000000UL

/* Carrier: channel 0 of the reference's six-channel plan,
 * axradio_phy_chanfreq[0] = 0x21656A57 -> 868.300001 MHz.
 * (The channels are 25 kHz apart, 0x3F04 per step.) */
#define RADIO_FREQA_CH0      0x21656A57UL
#define RADIO_FREQ_HZ        868300000UL

/* Reference source. TCXO: XTALOSC = 0x04, XTALAMPL = 0x00 (config.c).
 * Crystal instead: XTALOSC = 0x03 with XTALAMPL = 0x07 (0x0D above 43 MHz).
 * These are written by the register table in radio.c; they are named here
 * because flipping them is the first thing to try on new hardware. */
#define RADIO_XTALOSC        0x04
#define RADIO_XTALAMPL       0x00

/* The on-air sync word, four bytes, MSB first (config.c:
 * axradio_framing_syncword[] = { 0x93, 0x0b, 0x51, 0xde }). */
#define RADIO_SYNC0          0x93
#define RADIO_SYNC1          0x0B
#define RADIO_SYNC2          0x51
#define RADIO_SYNC3          0xDE
#define RADIO_SYNC_BYTES     4

/* Preamble: 32 bits of unencoded 0101... (config.c:
 * axradio_phy_preamble_len = 32, axradio_phy_preamble_byte = 0xAA).
 *
 * The byte is 0xAA, not 0x55, because PKTADDRCFG MSB FIRST is set - and it
 * has to be, or pattern match unit 1 (MATCH1PAT = 0x5555, the preamble
 * detector) would see the inverted pattern and never signal a match. */
#define RADIO_PREAMBLE_BYTES 4
#define RADIO_PREAMBLE_BYTE  0xAA

/* TXPWRCOEFFB (config.c: 0x0FFF) - alpha1 = 1, the maximum output power,
 * which is 15 dBm: the reference's value, and what a shelf label talking to
 * a ceiling-mounted access point across a shop needs.
 *
 * This is the one setting that depends on how far apart the two boards are,
 * and it is worth knowing both failure modes, because they look nothing
 * alike:
 *
 *   0x0FFF (0 dB)   fine at any normal distance. With the two boards a few
 *                   centimetres apart the transmitter overloads the other
 *                   end's front end instead: handshake frames still get
 *                   through, but an image block is corrupted often enough
 *                   that the transfer crawls and eventually stalls.
 *   0x0400 (-12 dB)   right for boards within arm's reach of each other. At
 *                   room distance it is too little: the access point stops
 *                   hearing the tag at all, not even its announcements.
 *
 * So: leave it at 0x0FFF unless the boards sit right next to each other, and
 * if a transfer stalls with everything else healthy, this is the knob. Keep
 * the two firmwares' radio.h identical - the tag and the access point have
 * to agree on the link, this value included.
 *
 * It can be overridden from the build (-DRADIO_TXPWR_COEFF=0x0400) so that
 * bench measurements can be taken without editing this file; the committed
 * value is the one below. */
#ifndef RADIO_TXPWR_COEFF
#define RADIO_TXPWR_COEFF    0x0FFF
#endif

/* How many times a tag repeats its announcement, and how far apart */
#define RADIO_ANNOUNCE_REPEATS  3
#define RADIO_ANNOUNCE_GAP_MS   120

/* ── API ─────────────────────────────────────────────────────────────── */

/* radio_init() error codes. 1..3 are what libmf's ax5043_reset() returns
 * (they mirror radiodefs.h) and are passed straight through. */
#define RADIO_OK                0
#define RADIO_ERR_REVISION      1   /* AX5043 not answering / wrong silicon */
#define RADIO_ERR_COMM          2   /* register scratch test failed */
#define RADIO_ERR_IRQ           3   /* interrupt probe failed */
#define RADIO_ERR_XTAL          4   /* XTALSTATUS bit 0 never came up */
#define RADIO_ERR_RANGE_TMO     5   /* VCO auto-ranging never finished */
#define RADIO_ERR_RANGE_ERR     6   /* the VCO could not reach 868.3 MHz */
#define RADIO_ERR_PLL_LOCK      7   /* the PLL did not lock, measured with the
                                    * synthesizer running and the calibrated
                                    * VCO current in place - the only state in
                                    * which PLLRANGINGA bit 6 means anything */
#define RADIO_ERR_TX_FIFO       8   /* the transmitter never went idle again */
#define RADIO_ERR_TX_LEN        9   /* payload does not fit in one packet */

/* radio_diag() buffer: RADIO_DIAG_LEN bytes, and what each one holds.
 * Meaningful after radio_init(), successful or not; the RX fields are
 * filled in by radio_rx(). */
#define RADIO_DIAG_LEN       10
#define RADIO_DIAG_REV        0   /* AX5043 silicon revision register */
#define RADIO_DIAG_XTAL       1   /* XTALSTATUS as last read while waiting
                                   * for the reference clock (bit 0 = running) */
#define RADIO_DIAG_POWSTAT    2   /* POWSTAT after the register set went in */
#define RADIO_DIAG_RANGING    3   /* PLLRANGINGA, re-read with the synthesizer
                                   * running during the VCOI calibration: VCORA
                                   * in bits 3:0, RNGERR bit 5, PLL LOCK bit 6,
                                   * sticky lock loss bit 7. The lock bits are
                                   * only meaningful from that read - see
                                   * radio_wait_pll_lock() in radio.c */
#define RADIO_DIAG_VCOI       4   /* VCOI written before TX/RX (bit 7 set),
                                   * 0 if the calibration produced nothing */
#define RADIO_DIAG_VCOIR      5   /* PLLVCOIR readback after the calibration */
#define RADIO_DIAG_ERR        6   /* radio_init() error code (0 = ok) */
#define RADIO_DIAG_RXFLAGS    7   /* flags byte of the last packet chunk -
                                   * bit 4 (ADDRFAIL) set would mean the packet
                                   * controller's address check bit us */
#define RADIO_DIAG_RXCOUNT    8   /* chunk length byte of the last packet */
#define RADIO_DIAG_RSSI       9   /* RSSI of the last packet, in dBm */

/* Reset, configure, range the VCO and calibrate it. 0 = ready to
 * transmit/receive.
 *
 * Every entry point is __reentrant. That is not a functional choice: on
 * this part it is what keeps SDCC from allocating a parameter/local block
 * in the 128 bytes of directly addressable RAM, which the tag firmware has
 * none of to spare (arguments and locals ride the stack instead). */
uint8_t radio_init(void) __reentrant;

/* Fill @p out (RADIO_DIAG_LEN bytes) with the fields listed above.
 * Meaningful after radio_init(), successful or not. */
void radio_diag(uint8_t *out) __reentrant;

/* Short human-readable description of a radio_init() error code (the
 * strings live in code space). */
const char *radio_error_str(uint8_t err) __reentrant;

/* AX5043 silicon revision register - a cheap "the radio answers" proof. */
uint8_t radio_revision(void) __reentrant;

/* Current RSSI in dBm (negative values), valid after a receive. The value
 * is the chip's RSSI register minus the 64 dB offset that the reference
 * builds into RSSIREFERENCE (config.c: axradio_phy_rssioffset = 64). */
int8_t radio_rssi(void) __reentrant;

/* Transmit one packet: the driver writes the preamble, the sync word and
 * the length byte + frame into the chip's FIFO. Blocks until the
 * transmission has finished.
 *
 * The payload is one whole link frame (sk_link.c) - this driver knows its
 * length and nothing else about it.
 * @return RADIO_OK, or RADIO_ERR_TX_LEN / RADIO_ERR_XTAL / RADIO_ERR_TX_FIFO. */
uint8_t radio_tx(const uint8_t *payload, uint8_t len) __reentrant;

/* The same transmit, behind the wake-on-radio preamble: the vendor's long
 * preamble instead of the normal 32-bit one, so a receiver that is only
 * listening for a fraction of each wake-up period still catches the packet.
 * The frame itself is byte-for-byte the same.
 *
 * It costs the preamble's air time - see RADIO_WOR_PREAMBLE_UNITS in radio.c,
 * a few hundred milliseconds - so it is for the first frame to a peer that
 * may be asleep, not for every frame. */
uint8_t radio_tx_wor(const uint8_t *payload, uint8_t len) __reentrant;

/* The shared body of the two: the normal preamble is a parameter so the
 * wake-on-radio one is the same code path, not a second transmit sequence
 * that could drift from it. */
uint8_t radio_tx_pre(const uint8_t *payload, uint8_t len,
                     uint16_t preamble) __reentrant;

/* Put the receiver on the air / take it back off. */
void radio_rx_start(void) __reentrant;
void radio_rx_stop(void) __reentrant;

/* Put the receiver into wake-on-radio instead of continuous receive: it
 * wakes every RADIO_WOR_PERIOD low-power oscillator cycles, listens for
 * about a preamble, and sleeps in between. This is the battery tag's idle
 * state; radio_rx_start() is what a tag calls when it has heard something
 * and wants to stay awake for the rest of a conversation.
 *
 * radio_rx() reads a packet the same way in either mode. */
void radio_rx_wor_start(void) __reentrant;

/* Non-blocking receive: copies a complete packet payload into @p payload
 * and returns its length, or 0 when nothing has arrived. A packet longer
 * than @p maxlen is dropped. */
uint8_t radio_rx(uint8_t *payload, uint8_t maxlen) __reentrant;

#endif /* RADIO_DRIVER_H */
