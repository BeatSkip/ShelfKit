/**
 * @file radio.c
 * @brief AX5043 driver for the tag <-> access point link
 *
 * ── What this file is ────────────────────────────────────────────────
 * A port of the vendor's own working AX5043 configuration for this board,
 * the AX-RadioLAB "VusionLink" sample project, reduced to what a plain
 * tag -> access point link needs. The physical layer is copied register by
 * register from
 *
 *   documentation/reference/VusionLink/AX_Radio_Lab_output/config.c
 *
 * and the sequences around it (init, VCO calibration, FIFO chunking) from
 *
 *   documentation/reference/VusionLink/COMMON/easyax5043.c
 *
 * Every block below names the reference function it mirrors, so the two can
 * be diffed by eye. What is *not* copied is the Vusion MAC: no address
 * bytes, no ACKs, no channel hopping, no software CRC-16. Both ends of this
 * link are our own firmware, so what follows the length byte is the ShelfKit
 * link frame from sk_link.c - addressing, a CRC-16, a hop budget and a
 * record route - whose layout and reasoning are in
 * firmware/shared/include/shelfkit_proto.h. This driver only knows how long
 * it is.
 *
 * ── The link ─────────────────────────────────────────────────────────
 *
 *   carrier      868.300001 MHz   FREQA = 0x21656A57 (channel 0 of six)
 *   modulation   FSK              MODULATION = 0x08
 *   bit rate     4799.5 bit/s     TXRATE  = 0x000C19
 *   deviation    1599.3 Hz        FSKDEV  = 0x000408   (h = 2/3)
 *   encoding     plain NRZ        ENCODING = 0x00
 *   framing      raw + pattern match, chip CRC off      FRAMING = 0x06
 *   reference    26 MHz TCXO on CLK16P/N   XTALOSC = 0x04, XTALAMPL = 0x00
 *   sync word    93 0B 51 DE      MATCH0PAT = 0x7B8AD0C9, MATCH0LEN = 0x9F
 *   preamble     32 bits of 0xAA  MATCH1PAT = 0x5555, MATCH1LEN = 0x8A
 *
 * On the air a packet is
 *
 *   [ 0xAA x 4 ] [ 93 0B 51 DE ] [ LEN ] [ payload ] [ no CRC ]
 *
 * The preamble and the sync word are written into the FIFO as separate
 * chunks with the UNENC|RAW|NOCRC flag byte 0x38, exactly as the
 * reference's transmit_isr() does; the length byte and the payload follow
 * in one packet chunk with PKTSTART|PKTEND.
 *
 * ── The three things the reference does not settle ───────────────────
 *   1. Byte order. config.c has PKTADDRCFG = 0x81, i.e. MSB FIRST. That is
 *      not cosmetic: the reference's MATCH0PAT holds the *bit reversed*
 *      sync bytes (rev8(0x93) = 0xC9 in PAT0 ...), which is only the right
 *      pattern if each byte goes out MSB first. Adopting the pattern
 *      registers therefore forces MSB FIRST, and MSB FIRST in turn forces
 *      the preamble byte to be 0xAA rather than 0x55 (see radio.h).
 *   2. Address filtering. 0x81 also means ADDR POS = 1, so the packet
 *      controller compares four bytes at packet positions 1..4 with
 *      PKTADDR0..3. We carry no address, so the comparison must be made
 *      harmless - see radio_set_registers() below.
 *   3. PKTSTOREFLAGS. config.c does not write it; the reference sets 0x15
 *      in ax5043_init_registers(), which makes the receiver prepend RSSI /
 *      RF-offset / timer chunks to every packet. Our parser reads the RSSI
 *      register instead, so we write 0.
 *
 * Sources: ON Semiconductor AND9347/D (AX5043 Programming Manual), the
 * AXSEM VusionLink project, and libmf (libmfradio.h, ax5043.h).
 */

#include "radio.h"
#include "shelfkit_proto.h"

#include <libmfradio.h>     /* radio_read8/radio_write8, ax5043_* helpers */
#include <ax5043.h>         /* register addresses */

/* ── PWRMODE (manual table 26, AX8052F143 datasheet table 28) ───────────
 * Plain mode values, exactly as config.c and easyax5043.c write them:
 * 0x05 / 0x07 / 0x0C / 0x0D / 0x09 / 0x00.
 *
 * PWRMODE also has REFEN (bit 5), XOEN (bit 6) and RST (bit 7), and REFEN
 * and XOEN reset to 1 - which is why the previous version of this driver
 * OR-ed 0x60 into every mode value. That is unnecessary: the mode field
 * alone selects the power state, and the datasheet's own mode table says so
 * ("0101 STANDBY: the crystal oscillator and the reference are powered on";
 * "1101 FULLTX: synthesizer and transmitter are running"; "in power-down
 * mode the core supply voltages ... are switched off"), and adds "the
 * voltage regulator system must be set into the appropriate state before
 * receive or transmit operations can be initiated. This is handled
 * automatically when programming the device modes via the AX5043_PWRMODE
 * register." REFEN/XOEN are keep-alive overrides for modes that would
 * otherwise leave the reference off - the reset value 0x30 is POWERDOWN
 * with both of them set. Writing them as 0 is what the vendor's own SDK
 * does; OR-ing 0x60 in was our invention.
 *
 * (The two published FIFO encodings disagree: the datasheet table 28 lists
 * 0110, the programming manual table 26 lists 0111. The SDK and libmf both
 * use 0x07, so that is what goes on the wire here.) */
#define RADIO_PWR_POWERDOWN  0x00
#define RADIO_PWR_XTAL_ON    0x05
#define RADIO_PWR_FIFO_ON    0x07
#define RADIO_PWR_FULL_RX    0x09
#define RADIO_PWR_WOR_RX     0x0B   /* easyax5043.h: AX5043_PWRSTATE_WOR_RX */
#define RADIO_PWR_SYNTH_TX   0x0C
#define RADIO_PWR_FULL_TX    0x0D

/* ── wake-on-radio ──────────────────────────────────────────────────────
 * Both numbers are the vendor's, from config.c's WOR block. RADIO_WOR_PERIOD
 * is axradio_wor_period (128): the wake-up timer counts LPOSC cycles, and the
 * LPOSC in LPOSCCONFIG's slow mode is the low-power oscillator the WOR
 * receiver lives on. RADIO_WOR_PREAMBLE_UNITS is the vendor's wake-up
 * preamble: axradio_phy_preamble_wor_longlen = 4 plus
 * axradio_phy_preamble_wor_len = 160, whose own comment says the two "total
 * to 240.0ms plus 32bits" - i.e. long enough to span a whole 200 ms-ish
 * wake-up period at 4800 bit/s, which is the property that matters: a WOR
 * receiver that is only on for a fraction of each period must find the
 * preamble still going when it wakes.
 *
 * The unit (bytes or bits) is the one thing about these numbers the vendor's
 * sources do not state, and it decides whether the preamble is ~270 ms or
 * ~34 ms. The total is used verbatim, in one REPEATDATA chunk, and the
 * hardware test is what settles it: a tag that does not wake means the count
 * has to be eight times longer. */
#ifndef RADIO_WOR_PERIOD
#define RADIO_WOR_PERIOD          128
#endif
#ifndef RADIO_WOR_PREAMBLE_UNITS
#define RADIO_WOR_PREAMBLE_UNITS  164
#endif

/* ── FIFOSTAT commands (manual table 64) ─────────────────────────────── */
#define RADIO_FIFOSTAT_EMPTY 0x01       /* read: FIFO is empty */
#define RADIO_FIFOCMD_CLEAR  0x03       /* write: clear FIFO data + flags */
#define RADIO_FIFOCMD_COMMIT 0x04       /* write: commit (make data visible) */

/* ── FIFO chunk headers (manual tables 3/4) ──────────────────────────── */
/* Variable length DATA chunk: header 0xE1, then a length byte that counts
 * the flag byte plus the data. */
#define RADIO_CHUNK_DATA     0xE1
/* REPEATDATA chunk with a fixed three byte payload (flags, repeat count,
 * data byte) - the reference builds the preamble with this. */
#define RADIO_CHUNK_REPEAT   0x62
/* DATA chunk with a fixed five byte payload (flags + the four sync bytes):
 * AX5043_FIFOCMD_DATA | (5 << 5) = 0x01 | 0xA0. Manual table 3 calls the
 * 5 byte length code "invalid", but this is the byte the reference writes
 * in transmit_isr() and its receive_isr() decodes length codes 4..6
 * generically, so the silicon does support them and the table is
 * over-restrictive. Kept verbatim: the on-air result is unchanged either
 * way, since the FIFO header never reaches the air. */
#define RADIO_CHUNK_SYNC     0xA1

/* ── DATA / REPEATDATA flag byte (manual tables 15/16) ───────────────── */
#define RADIO_DATA_PKTSTART  0x01
#define RADIO_DATA_PKTEND    0x02
#define RADIO_DATA_RESIDUE   0x04
#define RADIO_DATA_NOCRC     0x08
#define RADIO_DATA_RAW       0x10
#define RADIO_DATA_UNENC     0x20

/* The preamble and the sync word bypass the framing mode, the encoder and
 * the CRC generator. config.c: axradio_phy_preamble_flags = 0x38 and
 * axradio_framing_syncflags = 0x38 (RESIDUE is added by the SDK only when
 * the sync word is not a whole number of bytes - ours is 32 bits). */
#define RADIO_BYPASS_FLAGS   (RADIO_DATA_UNENC | RADIO_DATA_RAW | RADIO_DATA_NOCRC)

/* ── receive DATA chunk flag byte (manual table 17) ──────────────────── */
#define RADIO_RX_PKTSTART    0x01
#define RADIO_RX_CRCFAIL     0x08
#define RADIO_RX_ADDRFAIL    0x10
#define RADIO_RX_SIZEFAIL    0x20
#define RADIO_RX_ABORT       0x40
/* Anything in here and the chunk is not a packet we can use. ADDRFAIL is
 * deliberately *not* fatal: PKTACCEPTFLAGS ACCPT ADDRF is set (see
 * radio_set_registers), so a packet the address check did not like is still
 * delivered, and throwing it away here would defeat that. It is reported in
 * radio_diag() instead. */
#define RADIO_RX_BAD         (RADIO_RX_ABORT | RADIO_RX_SIZEFAIL | RADIO_RX_CRCFAIL)

/* ── packet controller: our framing (see the file header) ────────────── */
/* PKTADDRCFG = 0x81 from config.c: MSB FIRST (bit 7) and ADDR POS = 1.
 * MSB FIRST is required by the MATCH0PAT values; ADDR POS = 1 comes along
 * with it. */
#define RADIO_PKTADDRCFG      0x81
/* PKTLENCFG = 0x80: eight significant bits in the length byte, and the
 * length byte is at packet position 0, i.e. the first byte after the sync
 * pattern - where both firmwares put it. */
#define RADIO_PKTLENCFG       0x80
/* PKTLENOFFSET = 0: config.c has 0x01, and easyax5043.c adds
 * axradio_framing_swcrclen (2) on top of it, which is the Vusion MAC's
 * software CRC-16 trailer (manual p. 65: "length byte + LEN OFFSET counts
 * every byte in the packet after the synchronization pattern, up to and
 * excluding the CRC bytes, but including the length byte"). We have no
 * address bytes and no CRC, so the receiver must expect exactly the length
 * byte value. */
#define RADIO_PKTLENOFFSET    0x00
/* Longest packet: the length byte itself plus the payload. One spare byte on
 * top of the longest frame we ever send, so that the maximum-length packet
 * passes the size check whichever way the chip counts (the length byte value
 * alone, or the byte count including the length byte). Too small a value
 * here is a *silent* drop - SIZEFAIL is not in PKTACCEPTFLAGS - so the
 * headroom is worth the byte. */
#define RADIO_PKTMAXLEN       ((uint8_t)(SK_LINK_MAX + 2))
/* PKTACCEPTFLAGS: ACCPT LRGP (0x20, from config.c - needed so a packet that
 * spans more than one FIFO chunk is not dropped) | ACCPT ADDRF (0x08, ours).
 * The address check must never cost us a frame, whatever the mask below
 * turns out to mean in silicon. */
#define RADIO_PKTACCEPTFLAGS  0x28
/* PKTADDRCFG ADDR POS = 1 means the controller compares the four bytes at
 * packet positions 1..4 against PKTADDR0..3, bit by bit, for every bit set
 * in PKTADDRMASK0..3. We carry no address, so the mask is cleared: no bit
 * is compared and the check passes unconditionally. (That reading is the
 * only one consistent with the mask's reset value of 0x00000000 - if a
 * cleared mask meant "the address must equal PKTADDR", every AX5043 would
 * reject every packet out of reset.) ACCPT ADDRF above is the belt to this
 * brace: even if silicon reads the mask the other way round, the frame
 * arrives and radio_diag()[RADIO_DIAG_RXFLAGS] shows ADDRFAIL was set. */
#define RADIO_PKTADDRMASK     0x00
/* Chunk size 0x0D = 240 bytes including the flag byte (manual table 183).
 * Larger than PKTMAXLEN, so a whole packet always arrives in one chunk,
 * which is what radio_rx() parses. */
#define RADIO_PKTCHUNKSIZE    0x0D

/* ── the ranging / calibration starting points (config.c) ────────────── */
#define RADIO_RANGE_INIT      0x0A   /* axradio_phy_chanpllrnginit[0] */
#define RADIO_VCOI_INIT       0x99   /* axradio_phy_chanvcoiinit[0] */

/* ── RSSI ─────────────────────────────────────────────────────────────── */
/* config.c: axradio_phy_rssireference = 0xFA + 64 and
 * axradio_phy_rssioffset = 64 - the RSSI register is offset by +64 so that
 * the 8 bit signed value does not bottom out. radio_rssi() takes the 64
 * back off, which is what the reference reports to the application. */
#define RADIO_RSSI_REFERENCE  0x3A
#define RADIO_RSSI_OFFSET     64

/* ── timeouts (all loops poll, so none of them can hang forever) ─────── */
#define RADIO_TMO_XTAL       1000    /* x 100 us = 100 ms for the TCXO */
#define RADIO_TMO_RANGE      6000    /* x  50 us = 300 ms for autoranging */
#define RADIO_TMO_TX         6000    /* x  50 us = 300 ms for one packet */
#define RADIO_TMO_ADC        400     /* x   1 us, one GPADC conversion */
#define RADIO_TMO_PLL        2000    /* x  50 us = 100 ms for the PLL to lock */

/* ── the AX-RadioLAB register table, verbatim ────────────────────────────
 * This is config.c's ax5043_set_registers(), one line per radio_write8(),
 * in the same order. The address field is the AX5043's own 12 bit register
 * address (libmf's radio_write8() masks the top bits off), and the comment
 * is config.c's own value ordering so the two can be compared directly.
 *
 * Nothing here is derived or rounded by hand: it is the table AX-RadioLAB
 * computed for 868.300 MHz, 4.8 kbit/s, deviation 1.6 kHz, 15 dBm. */
typedef struct {
    uint16_t addr;
    uint8_t  val;
} radio_reg_t;

static const radio_reg_t __code radio_regs_common[] = {
    { AX5043_REG_MODULATION,        0x08 },   /* FSK */
    { AX5043_REG_ENCODING,          0x00 },   /* NRZ: no inv, no diff, no scrambler, no Manchester */
    { AX5043_REG_FRAMING,           0x06 },   /* FRMMODE = Raw/Pattern Match, CRCMODE = off */
    { AX5043_REG_PINFUNCSYSCLK,     0x01 },
    { AX5043_REG_PINFUNCDCLK,       0x01 },
    { AX5043_REG_PINFUNCDATA,       0x01 },
    { AX5043_REG_PINFUNCANTSEL,     0x82 },
    { AX5043_REG_PINFUNCPWRAMP,     0x82 },
    { AX5043_REG_WAKEUPXOEARLY,     0x01 },
    { AX5043_REG_IFFREQ1,           0x01 },
    { AX5043_REG_IFFREQ0,           0xE4 },
    { AX5043_REG_DECIMATION,        0x16 },
    { AX5043_REG_RXDATARATE2,       0x00 },
    { AX5043_REG_RXDATARATE1,       0x3D },
    { AX5043_REG_RXDATARATE0,       0x8D },
    { AX5043_REG_MAXDROFFSET2,      0x00 },
    { AX5043_REG_MAXDROFFSET1,      0x00 },
    { AX5043_REG_MAXDROFFSET0,      0x00 },
    { AX5043_REG_MAXRFOFFSET2,      0x80 },
    { AX5043_REG_MAXRFOFFSET1,      0x04 },
    { AX5043_REG_MAXRFOFFSET0,      0x61 },
    { AX5043_REG_FSKDMAX1,          0x00 },
    { AX5043_REG_FSKDMAX0,          0xA6 },
    { AX5043_REG_FSKDMIN1,          0xFF },
    { AX5043_REG_FSKDMIN0,          0x5A },
    { AX5043_REG_AMPLFILTER,        0x00 },
    { AX5043_REG_RXPARAMSETS,       0xF4 },
    { AX5043_REG_AGCGAIN0,          0xC5 },
    { AX5043_REG_AGCTARGET0,        0x84 },
    { AX5043_REG_TIMEGAIN0,         0xF8 },
    { AX5043_REG_DRGAIN0,           0xF2 },
    { AX5043_REG_PHASEGAIN0,        0xC3 },
    { AX5043_REG_FREQUENCYGAINA0,   0x0F },
    { AX5043_REG_FREQUENCYGAINB0,   0x1F },
    { AX5043_REG_FREQUENCYGAINC0,   0x08 },
    { AX5043_REG_FREQUENCYGAIND0,   0x08 },
    { AX5043_REG_AMPLITUDEGAIN0,    0x06 },
    { AX5043_REG_FREQDEV10,         0x00 },
    { AX5043_REG_FREQDEV00,         0x00 },
    { AX5043_REG_BBOFFSRES0,        0x00 },
    { AX5043_REG_AGCGAIN1,          0xC5 },
    { AX5043_REG_AGCTARGET1,        0x84 },
    { AX5043_REG_AGCAHYST1,         0x00 },
    { AX5043_REG_AGCMINMAX1,        0x00 },
    { AX5043_REG_TIMEGAIN1,         0xF6 },
    { AX5043_REG_DRGAIN1,           0xF1 },
    { AX5043_REG_PHASEGAIN1,        0xC3 },
    { AX5043_REG_FREQUENCYGAINA1,   0x0F },
    { AX5043_REG_FREQUENCYGAINB1,   0x1F },
    { AX5043_REG_FREQUENCYGAINC1,   0x08 },
    { AX5043_REG_FREQUENCYGAIND1,   0x08 },
    { AX5043_REG_AMPLITUDEGAIN1,    0x06 },
    { AX5043_REG_FREQDEV11,         0x00 },
    { AX5043_REG_FREQDEV01,         0x43 },
    { AX5043_REG_FOURFSK1,          0x16 },
    { AX5043_REG_BBOFFSRES1,        0x00 },
    { AX5043_REG_AGCGAIN3,          0xFF },
    { AX5043_REG_AGCTARGET3,        0x84 },
    { AX5043_REG_AGCAHYST3,         0x00 },
    { AX5043_REG_AGCMINMAX3,        0x00 },
    { AX5043_REG_TIMEGAIN3,         0xF5 },
    { AX5043_REG_DRGAIN3,           0xF0 },
    { AX5043_REG_PHASEGAIN3,        0xC3 },
    { AX5043_REG_FREQUENCYGAINA3,   0x0F },
    { AX5043_REG_FREQUENCYGAINB3,   0x1F },
    { AX5043_REG_FREQUENCYGAINC3,   0x0C },
    { AX5043_REG_FREQUENCYGAIND3,   0x0C },
    { AX5043_REG_AMPLITUDEGAIN3,    0x06 },
    { AX5043_REG_FREQDEV13,         0x00 },
    { AX5043_REG_FREQDEV03,         0x43 },
    { AX5043_REG_FOURFSK3,          0x16 },
    { AX5043_REG_BBOFFSRES3,        0x00 },
    { AX5043_REG_MODCFGF,           0x03 },
    { AX5043_REG_FSKDEV2,           0x00 },
    { AX5043_REG_FSKDEV1,           0x04 },
    { AX5043_REG_FSKDEV0,           0x08 },
    { AX5043_REG_MODCFGA,           0x05 },
    { AX5043_REG_TXRATE2,           0x00 },
    { AX5043_REG_TXRATE1,           0x0C },
    { AX5043_REG_TXRATE0,           0x19 },
    { AX5043_REG_TXPWRCOEFFB1,      (uint8_t)(RADIO_TXPWR_COEFF >> 8) },
    { AX5043_REG_TXPWRCOEFFB0,      (uint8_t)RADIO_TXPWR_COEFF },
    { AX5043_REG_PLLVCOI,           RADIO_VCOI_INIT },
    { AX5043_REG_PLLRNGCLK,         0x04 },
    { AX5043_REG_BBTUNE,            0x0F },
    { AX5043_REG_BBOFFSCAP,         0x77 },
    { AX5043_REG_PKTADDRCFG,        RADIO_PKTADDRCFG },
    { AX5043_REG_PKTLENCFG,         RADIO_PKTLENCFG },
    { AX5043_REG_PKTLENOFFSET,      0x01 },   /* overwritten below */
    { AX5043_REG_PKTMAXLEN,         0xC8 },   /* overwritten below */
    { AX5043_REG_MATCH0PAT3,        0x7B },   /* rev8(0xDE) */
    { AX5043_REG_MATCH0PAT2,        0x8A },   /* rev8(0x51) */
    { AX5043_REG_MATCH0PAT1,        0xD0 },   /* rev8(0x0B) */
    { AX5043_REG_MATCH0PAT0,        0xC9 },   /* rev8(0x93) - first bit on air */
    { AX5043_REG_MATCH0LEN,         0x9F },   /* RAW, 32 bit pattern */
    { AX5043_REG_MATCH0MAX,         0x1F },   /* all 32 bits must match */
    { AX5043_REG_MATCH1PAT1,        0x55 },   /* the 0xAA preamble, LSB first */
    { AX5043_REG_MATCH1PAT0,        0x55 },
    { AX5043_REG_MATCH1LEN,         0x8A },   /* RAW, 11 bit pattern */
    { AX5043_REG_MATCH1MAX,         0x0A },   /* all 11 bits must match */
    { AX5043_REG_TMGTXBOOST,        0x3E },
    { AX5043_REG_TMGTXSETTLE,       0x31 },
    { AX5043_REG_TMGRXBOOST,        0x3E },
    { AX5043_REG_TMGRXSETTLE,       0x31 },
    { AX5043_REG_TMGRXOFFSACQ,      0x00 },
    { AX5043_REG_TMGRXCOARSEAGC,    0x7F },
    { AX5043_REG_TMGRXRSSI,         0x03 },
    { AX5043_REG_TMGRXPREAMBLE2,    0x35 },
    { AX5043_REG_RSSIABSTHR,        0xE0 },
    { AX5043_REG_BGNDRSSITHR,       0x00 },
    { AX5043_REG_PKTCHUNKSIZE,      RADIO_PKTCHUNKSIZE },
    { AX5043_REG_PKTACCEPTFLAGS,    0x20 },   /* overwritten below */
    { AX5043_REG_DACVALUE1,         0x00 },
    { AX5043_REG_DACVALUE0,         0x00 },
    { AX5043_REG_DACCONFIG,         0x00 },
    { AX5043_REG_REF,               0x03 },
    { AX5043_REG_XTALOSC,           RADIO_XTALOSC },
    { AX5043_REG_XTALAMPL,          RADIO_XTALAMPL },
    { AX5043_REG_0xF1C,             0x07 },
    { AX5043_REG_0xF21,             0x68 },
    { AX5043_REG_0xF22,             0xFF },
    { AX5043_REG_0xF23,             0x84 },
    { AX5043_REG_0xF26,             0x98 },
    { AX5043_REG_0xF34,             0x08 },   /* RFDIV = 0 -> 0x08, not 0x28 */
    { AX5043_REG_0xF35,             0x11 },   /* fXTAL >= 24.8 MHz -> fXTALDIV = 2 */
    { AX5043_REG_0xF44,             0x25 }
};

/* config.c's ax5043_set_registers_tx() and _rx() differ in one byte
 * (PLLCPI), so the five registers they share live here and PLLCPI is
 * written by radio_set_registers_tx()/_rx(). */
static const radio_reg_t __code radio_regs_pll[] = {
    { AX5043_REG_PLLLOOP,           0x07 },
    { AX5043_REG_PLLVCODIV,         0x20 },   /* REFDIV = 0, RFDIV = 0, VCO2INT = 1 */
    { AX5043_REG_XTALCAP,           0x00 },
    { AX5043_REG_0xF00,             0x0F },
    { AX5043_REG_0xF18,             0x06 }
};

/* config.c's ax5043_set_registers_rxcont() */
static const radio_reg_t __code radio_regs_rxcont[] = {
    { AX5043_REG_TMGRXAGC,          0x00 },
    { AX5043_REG_TMGRXPREAMBLE1,    0x00 },
    { AX5043_REG_PKTMISCFLAGS,      0x00 }
};

/* config.c's ax5043_set_registers_rxwor() - the three registers that differ
 * from the continuous set above, and only those three. See the WOR section
 * further down for what each one is for; they are the vendor's generated
 * values, not ours. */
static const radio_reg_t __code radio_regs_rxwor[] = {
    { AX5043_REG_TMGRXAGC,          0x0A },
    { AX5043_REG_TMGRXPREAMBLE1,    0x19 },
    { AX5043_REG_PKTMISCFLAGS,      0x03 }
};

/* The four FREQA bytes of channel 0, low byte first (config.c:
 * axradio_phy_chanfreq[0] = 0x21656A57 -> 868.300001 MHz). */
static const uint8_t __code radio_freqa[4] = { 0x57, 0x6A, 0x65, 0x21 };

/* The on-air sync word, in the order it is transmitted (config.c:
 * axradio_framing_syncword[] = { 0x93, 0x0b, 0x51, 0xde }). */
static const uint8_t __code radio_syncword[RADIO_SYNC_BYTES] = {
    RADIO_SYNC0, RADIO_SYNC1, RADIO_SYNC2, RADIO_SYNC3
};

/* ── state ──────────────────────────────────────────────────────────────
 * One array, indexed by the RADIO_DIAG_* fields documented in radio.h. It
 * is deliberately the only sizeable static: this is an 8051 with 128 bytes
 * of directly addressable RAM shared with the stack, so every field has to
 * earn its byte. */
static uint8_t radio_state[RADIO_DIAG_LEN];

/* VCORA found by auto-ranging is bits 3:0 of RADIO_DIAG_RANGING - kept
 * there rather than in a static of its own, because this is an 8051 with
 * 128 bytes of RAM for everything. */
#define RADIO_RANGE()  ((uint8_t)(radio_state[RADIO_DIAG_RANGING] & 0x0F))

/* FIFO image for one transmit, in XRAM: internal RAM belongs to the stack.
 * Four bytes of REPEATDATA preamble (or six for a wake-on-radio preamble,
 * whose repeat count is a byte rather than a nibble), two header + five
 * bytes of sync word, two header + flags + length byte, then the payload. */
static uint8_t __xdata radio_fifo[18 + SK_LINK_MAX];

/* ── small helpers ──────────────────────────────────────────────────── */

/* Write a whole __code table into the chip. */
static void radio_apply(const radio_reg_t __code *t, uint8_t n) __reentrant
{
    uint8_t i;

    for (i = 0; i < n; i++)
        radio_write8(t[i].addr, t[i].val);
}

/* The FREQA word of channel 0. FREQA0 is at 0x37 and FREQA3 at 0x34, so the
 * byte index is the low nibble difference. */
static void radio_program_freqa(void) __reentrant
{
    uint8_t i;

    for (i = 0; i < 4; i++)
        radio_write8((uint16_t)(AX5043_REG_FREQA0 - i), radio_freqa[i]);
}

/* Wait for the reference clock: XTALSTATUS bit 0 is "XTAL OSCILLATOR
 * RUNNING and stable" (manual table 48). The reference waits for the
 * xtal-ready interrupt instead; polling the same status bit is the same
 * gate without an interrupt handler. */
static uint8_t radio_wait_xtal(void) __reentrant
{
    uint16_t t = RADIO_TMO_XTAL;

    while (t--) {
        radio_state[RADIO_DIAG_XTAL] = radio_read8(AX5043_REG_XTALSTATUS);
        if (radio_state[RADIO_DIAG_XTAL] & 0x01)
            return RADIO_OK;
        delay(100);
    }
    return RADIO_ERR_XTAL;
}

/* ── the PLL lock check: the one place bit 6 of PLLRANGINGA means
 * anything ──────────────────────────────────────────────────────────────
 *
 * PLLRANGINGA bit 6 is "PLL is locked if 1" - but only while the
 * synthesizer is actually running. At every other point in radio_init() the
 * chip is in STANDBY (PWRMODE 0x05) or POWERDOWN (0x00), the VCO is not
 * powered, and bit 6 is 0 by construction. It says nothing about the PLL
 * there: an unlocked PLL and a healthy-but-asleep PLL read the same.
 *
 * That is exactly why the reference never checks it during ranging.
 * easyax5043.c's axradio_init() tests only RNGERR after ranging (line 1744)
 * and moves straight on to the VCOI calibration, and the datasheet's own
 * ranging flow chart (figure 8) checks RNGERR and nothing else before going
 * to POWERDOWN. The one place the vendor reads the lock at all is
 * axradio_calvcoi() (line 1632), which runs with PWRMODE = SYNTH_TX and the
 * synthesizer up - and ShelfKit does not even take that branch, because
 * chanvcoiinit is 0x99, so axradio_adjustvcoi() runs instead, which never
 * looks at the lock.
 *
 * So this is called once, from inside the VCOI calibration, with the
 * synthesizer running and the *calibrated* PLLVCOI in place - i.e. on
 * precisely the settings the radio goes on to use. It is a real check: a PLL
 * that does not lock here will not lock in FULLRX either, and the failure
 * otherwise shows up much later as a receiver that silently never hears
 * anything, which is a far worse thing to debug.
 *
 * It also fixes the register snapshot. The previous version of this driver
 * sampled PLLRANGINGA once, inside the ranging poll loop, and printed that
 * value on the boot line as "PLL locked" / "PLL NOT LOCKED" - so every unit
 * reported "PLL NOT LOCKED", whether it was faulty or not, because the
 * sample was taken in a power state where the bit cannot be set. Refreshing
 * the byte here makes the reported state true.
 *
 * VCORA in bits 3:0 comes back unchanged - the chip only rewrites it during
 * auto-ranging - so overwriting the whole byte keeps RADIO_RANGE() correct
 * for the PLLRANGINGA writes in steps 6 and 7.
 *
 * Bit 7 is the sticky companion: "if 0, the PLL lost lock after the last read
 * of PLLRANGINGA", and every read clears it. That clear-on-read is exactly why
 * the reference reads the register around *every* tune-voltage measurement in
 * axradio_calvcoi() (lines 1623 and 1625) - it is clearing the flag, not
 * testing it.
 *
 * Which is why this function has to clear it too, and why the first statement
 * is a discarded read. The VCOI sweep immediately above retunes the VCO 32
 * times, and every one of those writes can drop lock for a moment, so the
 * sticky bit is *certain* to be set on arrival here - on a perfectly healthy
 * chip. Reading once first means bit 7 then reports "lost lock since we
 * started watching", which is a real observation; without that read it reports
 * the sweep, and the boot log says "lock was lost" on every unit that ever
 * calibrates successfully. That is the same class of bug as the stale
 * snapshot this function exists to fix: reporting a bit that was never
 * measured in the state being described.
 *
 * Bit 6 is the bit that converges, so that is what the loop waits for. Once
 * it is set, the loop exits and the value stored is the one that satisfied it
 * - so bit 7 in the snapshot is "still locked and nothing dropped since the
 * cleared read", which is what a caller wants to know. */
static uint8_t radio_wait_pll_lock(void) __reentrant
{
    uint16_t t = RADIO_TMO_PLL;

    /* Discarded on purpose: clears the sticky lock-loss flag the VCOI sweep
     * left behind. See above. */
    (void)radio_read8(AX5043_REG_PLLRANGINGA);

    while (t--) {
        radio_state[RADIO_DIAG_RANGING] = radio_read8(AX5043_REG_PLLRANGINGA);
        if (radio_state[RADIO_DIAG_RANGING] & 0x40)
            return RADIO_OK;
        delay(50);
    }
    return RADIO_ERR_PLL_LOCK;
}

/* Any init failure ends the same way: radio off, error recorded. */
static uint8_t radio_fail(uint8_t err) __reentrant
{
    radio_write8(AX5043_REG_PWRMODE, RADIO_PWR_POWERDOWN);
    radio_state[RADIO_DIAG_ERR] = err;
    return err;
}

/* ── the register sets ──────────────────────────────────────────────────
 * easyax5043.c splits these three ways and so do we:
 *
 *   radio_set_registers()          <- ax5043_init_registers()
 *                                     (config.c's table + the packet
 *                                      controller and address registers)
 *   radio_set_registers_tx()/_rx() <- config.c's ax5043_set_registers_tx/rx
 *   radio_init_registers_tx()/_rx()<- ax5043_init_registers_tx/rx (the two
 *                                     above plus the ranging result)
 */
static void radio_set_registers(void) __reentrant
{
    radio_apply(radio_regs_common,
                (uint8_t)(sizeof radio_regs_common / sizeof radio_regs_common[0]));

    /* Where we leave config.c, all in one place. PKTLENOFFSET and
     * PKTMAXLEN because we have no address bytes and no software CRC-16,
     * PKTACCEPTFLAGS to add ACCPT ADDRF. */
    radio_write8(AX5043_REG_PKTLENOFFSET, RADIO_PKTLENOFFSET);
    radio_write8(AX5043_REG_PKTMAXLEN, RADIO_PKTMAXLEN);
    radio_write8(AX5043_REG_PKTACCEPTFLAGS, RADIO_PKTACCEPTFLAGS);

    /* ax5043_init_registers()'s tail: IRQ pin, and PKTSTOREFLAGS = 0
     * instead of the reference's 0x15, so the receiver does not prepend
     * RSSI / RF-offset / timer chunks to the packet (manual table 185). Our
     * parser reads the RSSI register instead, and would lose sync on a
     * metadata chunk because those have no length byte of their own. */
    radio_write8(AX5043_REG_PINFUNCIRQ, 0x03);
    radio_write8(AX5043_REG_PKTSTOREFLAGS, 0x00);

    /* This driver polls; it never enables a radio interrupt, and the
     * firmware never enables the radio interrupt at the MCU either. Clear
     * both masks so a warm start cannot leave one armed. */
    radio_write8(AX5043_REG_IRQMASK0, 0x00);
    radio_write8(AX5043_REG_IRQMASK1, 0x00);

    /* axradio_setaddrregs(), with the mask cleared: no address bit is
     * compared, so any frame passes the address check. */
    radio_write8(AX5043_REG_PKTADDR0, 0x00);
    radio_write8(AX5043_REG_PKTADDR1, 0x00);
    radio_write8(AX5043_REG_PKTADDR2, 0x00);
    radio_write8(AX5043_REG_PKTADDR3, 0x00);
    radio_write8(AX5043_REG_PKTADDRMASK0, RADIO_PKTADDRMASK);
    radio_write8(AX5043_REG_PKTADDRMASK1, RADIO_PKTADDRMASK);
    radio_write8(AX5043_REG_PKTADDRMASK2, RADIO_PKTADDRMASK);
    radio_write8(AX5043_REG_PKTADDRMASK3, RADIO_PKTADDRMASK);
}

static void radio_set_registers_tx(void) __reentrant
{
    radio_apply(radio_regs_pll,
                (uint8_t)(sizeof radio_regs_pll / sizeof radio_regs_pll[0]));
    radio_write8(AX5043_REG_PLLCPI, 0x12);
}

static void radio_set_registers_rx(void) __reentrant
{
    radio_apply(radio_regs_pll,
                (uint8_t)(sizeof radio_regs_pll / sizeof radio_regs_pll[0]));
    radio_write8(AX5043_REG_PLLCPI, 0x08);
}

/* ax5043_init_registers_common(): hand the chip the VCO range and VCO
 * current that auto-ranging and the calibration found. Nothing else in the
 * driver writes PLLRANGINGA, so this is what makes the synthesizer come up
 * on 868.3 MHz every time. */
static void radio_init_registers_common(void) __reentrant
{
    radio_write8(AX5043_REG_PLLRANGINGA, RADIO_RANGE());
    if (radio_state[RADIO_DIAG_VCOI] & 0x80)
        radio_write8(AX5043_REG_PLLVCOI, radio_state[RADIO_DIAG_VCOI]);
}

static void radio_init_registers_tx(void) __reentrant
{
    radio_set_registers_tx();
    radio_init_registers_common();
}

static void radio_init_registers_rx(void) __reentrant
{
    radio_set_registers_rx();
    radio_init_registers_common();
}

/* ── VCO current calibration (axradio_adjustvcoi) ───────────────────────
 * config.c says this board wants VCOI = 0x99 with VCORA = 0x0A, but both
 * are per-chip values: auto-ranging may have picked a different range, and
 * the VCO bias current that puts the tune voltage in the middle of its
 * range differs from die to die. The reference measures the tune voltage
 * over the 16 VCOI settings either side of its starting point and keeps the
 * one with the lowest reading.
 *
 * radio_tunevoltage() reads GPADC channel 1 (manual table 187: GPADC13
 * selects channels 1-3, and the conversion is started and the busy bit
 * cleared by writing GPADCCTRL = 0x84). The reference discards 64
 * conversions and then averages 32; so do we. Its inner wait has no
 * timeout - ours does, and it returns -1 if a conversion never finishes: a
 * hung ADC would otherwise hang the tag, and a -1 reading is 0xFFFF, which
 * loses every comparison in radio_adjustvcoi(), so a failed measurement
 * falls back to RadioLab's value instead of picking a VCOI from garbage. */
static int16_t radio_tunevoltage(void) __reentrant
{
    int16_t sum = 0;
    uint8_t cnt;
    uint8_t started;
    uint16_t t;

    for (cnt = 64; cnt; cnt--) {
        radio_write8(AX5043_REG_GPADCCTRL, 0x84);
        started = 0;
        t = RADIO_TMO_ADC;
        while (t--) {
            if (!(radio_read8(AX5043_REG_GPADCCTRL) & 0x80)) {
                started = 1;
                break;
            }
            delay(1);
        }
        if (!started)
            return -1;
    }

    for (cnt = 32; cnt; cnt--) {
        radio_write8(AX5043_REG_GPADCCTRL, 0x84);
        started = 0;
        t = RADIO_TMO_ADC;
        while (t--) {
            if (!(radio_read8(AX5043_REG_GPADCCTRL) & 0x80)) {
                started = 1;
                break;
            }
            delay(1);
        }
        if (!started)
            return -1;
        sum = (int16_t)(sum +
              (((int16_t)(radio_read8(AX5043_REG_GPADC13VALUE1) & 0x03) << 8) |
               (int16_t)radio_read8(AX5043_REG_GPADC13VALUE0)));
    }

    return sum;
}

static uint8_t radio_adjustvcoi(uint8_t rng) __reentrant
{
    uint8_t offs;
    uint8_t bestrng;
    uint16_t bestval = 0xFFFF;

    rng &= 0x7F;
    bestrng = rng;

    for (offs = 0; offs != 16; offs++) {
        uint16_t val;

        if (!((uint8_t)(rng + offs) & 0xC0)) {
            radio_write8(AX5043_REG_PLLVCOI, (uint8_t)(0x80 | (rng + offs)));
            val = (uint16_t)radio_tunevoltage();
            if (val < bestval) {
                bestval = val;
                bestrng = (uint8_t)(rng + offs);
            }
        }
        if (!offs)
            continue;
        if (!((uint8_t)(rng - offs) & 0xC0)) {
            radio_write8(AX5043_REG_PLLVCOI, (uint8_t)(0x80 | (rng - offs)));
            val = (uint16_t)radio_tunevoltage();
            if (val < bestval) {
                bestval = val;
                bestrng = (uint8_t)(rng - offs);
            }
        }
    }

    /* If we hit the lower rail, do not change anything (the reference's
     * rule verbatim). */
    if (bestval <= 0x0010)
        return (uint8_t)(rng | 0x80);
    return (uint8_t)(bestrng | 0x80);
}

/* ── init (axradio_init) ────────────────────────────────────────────────
 * The reference's sequence, in its order, with IRQ waits replaced by polls
 * on the same status bits. It is worth following closely: the PLL loop
 * bandwidth, the ranging, the VCO current calibration and the final
 * re-application of the register table all matter, and the calibration is
 * the reason the reference touches 0xF35 and PLLVCOI at all.
 *
 * What we dropped is the six channel loop (we use channel 0) and the
 * axradio_calvcoi() branch (config.c sets axradio_phy_chanvcoiinit to
 * 0x99, so the reference takes axradio_adjustvcoi() too). */
uint8_t radio_init(void) __reentrant
{
    uint8_t j;
    uint16_t t;
    uint8_t err;

    radio_state[RADIO_DIAG_ERR] = RADIO_OK;

    /* 1. Reset, and prove the chip answers: ax5043_reset() checks the
     *    silicon revision and round-trips a scratch register. Its 1..3 are
     *    ours 1..3. */
    err = ax5043_reset();
    radio_state[RADIO_DIAG_ERR] = err;
    if (err)
        return err;
    radio_state[RADIO_DIAG_REV] = radio_read8(AX5043_REG_SILICONREVISION);

    /* 2. The register table, then its TX variant. */
    radio_set_registers();
    radio_set_registers_tx();

    /* 3. 100 kHz PLL loop bandwidth, the setting ranging is specified for. */
    radio_write8(AX5043_REG_PLLLOOP, 0x09);
    radio_write8(AX5043_REG_PLLCPI, 0x08);

    /* 4. Reference clock on. Modulation stays at FSK but the deviation is
     *    zero while ranging, as in the reference. */
    radio_write8(AX5043_REG_PWRMODE, RADIO_PWR_XTAL_ON);
    radio_write8(AX5043_REG_MODULATION, 0x08);
    radio_write8(AX5043_REG_FSKDEV2, 0x00);
    radio_write8(AX5043_REG_FSKDEV1, 0x00);
    radio_write8(AX5043_REG_FSKDEV0, 0x00);
    err = radio_wait_xtal();
    if (err)
        return radio_fail(err);
    radio_state[RADIO_DIAG_POWSTAT] = radio_read8(AX5043_REG_POWSTAT);

    /* 5. VCO auto-ranging on channel 0. Ranging starts from VCORA = 0x0A,
     *    RadioLab's value for this band, and the chip clears RNGSTART when
     *    it is done (manual figure 8). */
    radio_program_freqa();
    radio_write8(AX5043_REG_PLLRANGINGA, (uint8_t)(RADIO_RANGE_INIT | 0x10));

    t = RADIO_TMO_RANGE;
    while (t--) {
        radio_state[RADIO_DIAG_RANGING] = radio_read8(AX5043_REG_PLLRANGINGA);
        if (!(radio_state[RADIO_DIAG_RANGING] & 0x10))
            break;
        delay(50);
    }
    if (!t)
        return radio_fail(RADIO_ERR_RANGE_TMO);
    if (radio_state[RADIO_DIAG_RANGING] & 0x20)
        return radio_fail(RADIO_ERR_RANGE_ERR);

    /* 6. VCO current calibration. Everything here is the reference's "VCOI
     *    Calibration" block: back to the TX PLL settings, deviation off,
     *    0xF35 into its calibration state, synthesizer running, then the
     *    starting point corrected by the difference between the range we
     *    found and the range RadioLab saw, and the sweep run twice (the
     *    reference's do/while (--j) with j = 2). */
    radio_set_registers_tx();
    radio_write8(AX5043_REG_MODULATION, 0x08);
    radio_write8(AX5043_REG_FSKDEV2, 0x00);
    radio_write8(AX5043_REG_FSKDEV1, 0x00);
    radio_write8(AX5043_REG_FSKDEV0, 0x00);
    radio_write8(AX5043_REG_PLLLOOP, (uint8_t)(radio_read8(AX5043_REG_PLLLOOP) | 0x04));
    {
        uint8_t x = radio_read8(AX5043_REG_0xF35);

        x |= 0x80;
        if (2 & (uint8_t)~x)
            x++;
        radio_write8(AX5043_REG_0xF35, x);
    }
    radio_write8(AX5043_REG_PWRMODE, RADIO_PWR_SYNTH_TX);
    {
        uint8_t vcoisave = radio_read8(AX5043_REG_PLLVCOI);
        uint8_t x = (uint8_t)(RADIO_VCOI_INIT + RADIO_RANGE() - RADIO_RANGE_INIT);

        radio_write8(AX5043_REG_PLLRANGINGA, RADIO_RANGE());
        radio_program_freqa();
        j = 2;
        do {
            radio_state[RADIO_DIAG_VCOI] = radio_adjustvcoi(x);
        } while (--j);

        /* The calibrated current is the one the radio will actually use, so
         * put it in and confirm the PLL locks on it. This is the first and
         * only point in the sequence where the lock bits mean anything -
         * everything before it is STANDBY or POWERDOWN - so it both catches
         * a synthesizer that will not lock and refreshes the PLLRANGINGA
         * snapshot the boot log prints. See radio_wait_pll_lock(). */
        radio_write8(AX5043_REG_PLLVCOI, radio_state[RADIO_DIAG_VCOI]);
        err = radio_wait_pll_lock();
        if (err)
            return radio_fail(err);

        /* Read the calibrated setting back before restoring the register,
         * while the synthesizer is still up. */
        radio_state[RADIO_DIAG_VCOIR] = radio_read8(AX5043_REG_PLLVCOIR);
        radio_write8(AX5043_REG_PLLVCOI, vcoisave);
    }

    /* 7. Power down and lay the table down again - which is also what puts
     *    0xF35 back to RadioLab's 0x11 after the calibration modified it -
     *    then the RX PLL variant, the ranged VCO setting and channel 0. */
    radio_write8(AX5043_REG_PWRMODE, RADIO_PWR_POWERDOWN);
    radio_set_registers();
    radio_set_registers_rx();
    radio_write8(AX5043_REG_PLLRANGINGA, RADIO_RANGE());
    radio_program_freqa();

    radio_state[RADIO_DIAG_ERR] = RADIO_OK;
    return RADIO_OK;
}

/* ── diagnostics ─────────────────────────────────────────────────────── */

void radio_diag(uint8_t *out) __reentrant
{
    uint8_t i;

    for (i = 0; i < RADIO_DIAG_LEN; i++)
        out[i] = radio_state[i];
}

uint8_t radio_revision(void) __reentrant
{
    return radio_state[RADIO_DIAG_REV];
}

int8_t radio_rssi(void) __reentrant
{
    return (int8_t)radio_state[RADIO_DIAG_RSSI];
}

/* Short description of an error code, for the boot log. The strings live in
 * code space; a pointer table would cost RAM this part does not have. */
const char *radio_error_str(uint8_t err) __reentrant
{
    switch (err) {
    case RADIO_OK:            return "ok";
    case RADIO_ERR_REVISION:  return "AX5043 silicon revision wrong - radio not answering";
    case RADIO_ERR_COMM:      return "register scratch test failed";
    case RADIO_ERR_IRQ:       return "interrupt probe failed";
    case RADIO_ERR_XTAL:      return "reference clock never became ready (XTALSTATUS bit 0)";
    case RADIO_ERR_RANGE_TMO: return "VCO auto-ranging timed out";
    case RADIO_ERR_RANGE_ERR: return "VCO could not reach 868.3 MHz";
    case RADIO_ERR_TX_FIFO:   return "transmitter never went idle";
    case RADIO_ERR_TX_LEN:    return "payload does not fit in one packet";
    case RADIO_ERR_PLL_LOCK:  return "PLL never locked with the synthesizer running";
    default:                  return "unknown";
    }
}

/* The protocol's integrity check used to live here: a one-byte XOR over the
 * application payload. It has been replaced by the link frame's CRC-16
 * (sk_link.c, described in shelfkit_proto.h) because a byte-wide XOR catches
 * a single flipped bit and very little else - which is exactly what made the
 * old link "mostly works". */

/* ── transmit ───────────────────────────────────────────────────────────
 * The chunk sequence is the reference's transmit_isr(), for the case that
 * matters here: no WOR long preamble (config.c: axradio_phy_preamble_longlen
 * = 0), so straight to the short preamble, then the sync word, then the
 * packet in one chunk (the whole packet fits in PKTCHUNKSIZE).
 *
 *   0x62 38 04 AA                     REPEATDATA: 4 bytes of preamble
 *   0xA1 38 93 0B 51 DE               DATA: flags + the four sync bytes
 *   0xE1 <len+2> 03 <len+1> <payload> DATA: PKTSTART|PKTEND, the packet
 *                                     (the chunk length counts the flag byte
 *                                      and the protocol length byte)
 *
 * The framing is done by us, not the chip: FRAMING is Raw/Pattern Match
 * with CRCMODE off, and in that mode the transmitter writes the sync word
 * and the length byte itself (manual p. 9 and the SDK's comment "write SYNC
 * word if framing mode is raw_patternmatch").
 *
 * And the order is the reference's: the FIFO is filled in FIFO_ON state,
 * committed, and only then is the transmitter powered up (ax5043_prepare_tx
 * + the tx_xtalwait branch of the SDK's interrupt handler).
 *
 * The payload is one whole link frame (sk_link.c), not an application
 * packet: the link layer decides what a frame looks like and this driver
 * only knows how long it is. */
uint8_t radio_tx_pre(const uint8_t *payload, uint8_t len,
                     uint16_t preamble) __reentrant
{
    uint8_t n = 0;
    uint8_t i;
    uint16_t t;

    if (!len || len > SK_LINK_MAX)
        return RADIO_ERR_TX_LEN;

    /* Preamble: REPEATDATA, unencoded alternating bits. The repeat count is
     * a byte here because a wake-on-radio preamble is far longer than the
     * 32-bit one: see RADIO_WOR_PREAMBLE_UNITS. */
    radio_fifo[n++] = RADIO_CHUNK_REPEAT;
    radio_fifo[n++] = RADIO_BYPASS_FLAGS;
    radio_fifo[n++] = (uint8_t)preamble;
    radio_fifo[n++] = RADIO_PREAMBLE_BYTE;

    /* Sync word: its own DATA chunk, raw and unencoded, in on-air order. */
    radio_fifo[n++] = RADIO_CHUNK_SYNC;
    radio_fifo[n++] = RADIO_BYPASS_FLAGS;
    for (i = 0; i < RADIO_SYNC_BYTES; i++)
        radio_fifo[n++] = radio_syncword[i];

    /* The packet: one DATA chunk, PKTSTART|PKTEND, the length byte first.
     * The chunk length counts the flag byte, so it is len + 2. */
    radio_fifo[n++] = RADIO_CHUNK_DATA;
    radio_fifo[n++] = (uint8_t)(len + 2);
    radio_fifo[n++] = RADIO_DATA_PKTSTART | RADIO_DATA_PKTEND;
    radio_fifo[n++] = (uint8_t)(len + 1);   /* counts itself, like the protocol says */
    for (i = 0; i < len; i++)
        radio_fifo[n++] = payload[i];

    /* 1. PWRMODE = XTAL_ON, then FIFO_ON: the FIFO can be filled before the
     *    transmitter is powered up. ax5043_prepare_tx(). */
    radio_write8(AX5043_REG_PWRMODE, RADIO_PWR_XTAL_ON);
    radio_write8(AX5043_REG_PWRMODE, RADIO_PWR_FIFO_ON);
    radio_init_registers_tx();
    radio_write8(AX5043_REG_FIFOTHRESH1, 0x00);
    radio_write8(AX5043_REG_FIFOTHRESH0, 0x80);
    (void)radio_read8(AX5043_REG_POWSTICKYSTAT);    /* clear the sticky power flags */

    /* 2. Wait for the reference clock (the SDK enables the xtal-ready
     *    interrupt here). */
    if (radio_wait_xtal() != RADIO_OK) {
        radio_write8(AX5043_REG_PWRMODE, RADIO_PWR_POWERDOWN);
        return RADIO_ERR_XTAL;
    }

    /* 3. Drop anything left in the FIFO, hand ours over, commit. The
     *    reference reads RADIOEVENTREQ0 first so that the "transmit done"
     *    event it polls later is a fresh one. */
    (void)radio_read8(AX5043_REG_RADIOEVENTREQ0);
    radio_write8(AX5043_REG_FIFOSTAT, RADIO_FIFOCMD_CLEAR);
    ax5043_writefifo(radio_fifo, n);
    radio_write8(AX5043_REG_FIFOSTAT, RADIO_FIFOCMD_COMMIT);

    /* 4. Now power the transmitter up: it sees a non-empty FIFO and goes. */
    radio_write8(AX5043_REG_PWRMODE, RADIO_PWR_FULL_TX);

    /* 5. RADIOSTATE back to 0 (idle) means the packet is out - the
     *    reference's tx_waitdone branch tests exactly this. */
    t = RADIO_TMO_TX;
    while (t--) {
        if (radio_read8(AX5043_REG_RADIOSTATE) == 0x00)
            break;
        delay(50);
    }

    radio_write8(AX5043_REG_PWRMODE, RADIO_PWR_POWERDOWN);

    return t ? RADIO_OK : RADIO_ERR_TX_FIFO;
}

/* One packet with the normal 32-bit preamble - what every frame uses except
 * the first one to a peer that may be asleep. */
uint8_t radio_tx(const uint8_t *payload, uint8_t len) __reentrant
{
    return radio_tx_pre(payload, len, RADIO_PREAMBLE_BYTES);
}

/* One packet behind a wake-on-radio preamble. See the WOR section below for
 * where RADIO_WOR_PREAMBLE_UNITS comes from. In WOR mode the receiver is only
 * on for a fraction of each wake-up period, so it cannot be expected to
 * catch a normal 32-bit preamble; the long one spans at least one whole
 * period. The transmitter is otherwise identical, and the packet itself is
 * exactly the same bytes. */
uint8_t radio_tx_wor(const uint8_t *payload, uint8_t len) __reentrant
{
    return radio_tx_pre(payload, len, RADIO_WOR_PREAMBLE_UNITS);
}

/* ── wake-on-radio ──────────────────────────────────────────────────────
 *
 * The biggest single power lever on a battery tag. Left in continuous
 * receive (radio_rx_start above), the AX5043 spends its whole life listening
 * - roughly 12 mA plus the front end's bias, whether or not anything is
 * there. In WOR the receiver wakes itself every RADIO_WOR_PERIOD low-power
 * oscillator cycles, listens for about a preamble's worth of time
 * (TMGRXPREAMBLE1), and sleeps in between, so the average receive current
 * falls by roughly the duty cycle. The e-paper refresh remains the largest
 * single energy cost in the tag's life - the point of WOR is not to transmit
 * less, it is to never sit in receive.
 *
 * The sequence follows easyax5043.c's ax5043_receiver_on_wor() line for
 * line, with the vendor's generated register values:
 *
 *   BGNDRSSIGAIN = 0x02     easyax5043.c writes this first. It is the
 *                           background RSSI measurement's gain, and the
 *                           vendor sets it for WOR only; the continuous
 *                           receiver leaves the RadioLAB value alone.
 *   FIFOSTAT = 3            clear FIFO data and flags, as every receive
 *                           start does.
 *   LPOSCCONFIG = 0x01      "start LPOSC, slow mode" - the low-power
 *                           oscillator the wake-up timer counts.
 *   RSSIREFERENCE = 0x3A    the same reference as the continuous receiver
 *                           (config.c: 0xFA + 64).
 *   TMGRXAGC = 0x0A         from config.c's ax5043_set_registers_rxwor().
 *   TMGRXPREAMBLE1 = 0x19   from the same table: how much preamble the
 *                           receiver waits for before it commits to the
 *                           packet. Only a WOR receiver needs it, because
 *                           only a WOR receiver is likely to wake up in the
 *                           middle of a preamble.
 *   PKTMISCFLAGS = 0x03     RXRSSICLK | RXAGCCLK (manual table 184). The
 *                           vendor's WOR value. Bit 4 (WORMULTIPKT, "stay on
 *                           after a packet") is deliberately clear, as in
 *                           the vendor's table: whether this tag stays awake
 *                           afterwards is the firmware's business, and the
 *                           tag does exactly that by calling radio_rx_start()
 *                           when it hears something (see the tag's main.c).
 *   PKTSTOREFLAGS &= ~0x40  the same "no RSSI/timer chunks in front of the
 *                           packet" rule the continuous receiver applies.
 *   PWRMODE = WOR_RX        the mode itself.
 *   WAKEUPFREQ = period     the wake-up period in LPOSC cycles, and
 *   WAKEUP = period + WAKEUPTIMER   the first wake-up, measured from now.
 *
 * Two things the vendor does that are deliberately not done here, because
 * the vendor's own guard for them is false on this board:
 *
 *   * the F143_WOR_TCXO power-interrupt dance (IRQMASK0 |= 0x80 and
 *     POWIRQMASK = 0x90). easyax5043.c only arms it when the TCXO_EN signal
 *     is passed through to a GPIO - `(PALTRADIO & 0x40) && (PINFUNCPWRAMP &
 *     0x0F) == 0x07`. config.c sets PALTRADIO = 0x00 and PINFUNCPWRAMP =
 *     0x82, so the condition is false. If WOR ever fails to wake on this
 *     hardware, that is the first thing to add.
 *   * the interrupt enables themselves. This driver polls FIFOSTAT; it never
 *     enables a radio interrupt and the firmware never enables the radio
 *     interrupt at the MCU either, which is why the receiver-on path below
 *     leaves both masks clear. */
void radio_rx_wor_start(void) __reentrant
{
    uint16_t wp;

    radio_init_registers_rx();
    radio_write8(AX5043_REG_BGNDRSSIGAIN, 0x02);
    radio_write8(AX5043_REG_FIFOSTAT, RADIO_FIFOCMD_CLEAR);
    radio_write8(AX5043_REG_LPOSCCONFIG, 0x01);
    radio_write8(AX5043_REG_RSSIREFERENCE, RADIO_RSSI_REFERENCE);
    radio_apply(radio_regs_rxwor,
                (uint8_t)(sizeof radio_regs_rxwor / sizeof radio_regs_rxwor[0]));
    radio_write8(AX5043_REG_PKTSTOREFLAGS, 0x00);
    radio_write8(AX5043_REG_IRQMASK0, 0x00);
    radio_write8(AX5043_REG_IRQMASK1, 0x00);

    radio_write8(AX5043_REG_PWRMODE, RADIO_PWR_WOR_RX);

    wp = RADIO_WOR_PERIOD;
    radio_write8(AX5043_REG_WAKEUPFREQ1, (uint8_t)(wp >> 8));
    radio_write8(AX5043_REG_WAKEUPFREQ0, (uint8_t)wp);
    wp = (uint16_t)(wp + radio_read16(AX5043_REG_WAKEUPTIMER1));
    radio_write8(AX5043_REG_WAKEUP1, (uint8_t)(wp >> 8));
    radio_write8(AX5043_REG_WAKEUP0, (uint8_t)wp);
}

/* ── receive ────────────────────────────────────────────────────────────
 * ax5043_receiver_on_continuous() plus the ax5043_init_registers_rx() the
 * SDK runs just before it. RSSIREFERENCE is the one receiver register the
 * reference sets at run time rather than in config.c. */
void radio_rx_start(void) __reentrant
{
    radio_init_registers_rx();
    radio_apply(radio_regs_rxcont,
                (uint8_t)(sizeof radio_regs_rxcont / sizeof radio_regs_rxcont[0]));
    radio_write8(AX5043_REG_RSSIREFERENCE, RADIO_RSSI_REFERENCE);
    radio_write8(AX5043_REG_FIFOSTAT, RADIO_FIFOCMD_CLEAR);
    radio_write8(AX5043_REG_PWRMODE, RADIO_PWR_FULL_RX);
}

void radio_rx_stop(void) __reentrant
{
    radio_write8(AX5043_REG_PWRMODE, RADIO_PWR_POWERDOWN);
}

/* Non-blocking. One packet always arrives as one DATA chunk (PKTCHUNKSIZE
 * is larger than PKTMAXLEN), so this is the reference's receive_isr() DATA
 * case with the Vusion MAC skipped: the chunk holds
 *
 *   [ length byte ] [ payload ]
 *
 * The length byte is the chip's - the receiver adds PKTLENOFFSET (0) to it
 * and size-checks against PKTMAXLEN, so a chunk of "length byte + 1" bytes
 * is exactly what a well-formed packet looks like. Anything else in the
 * FIFO is not ours: it is dropped, but always drained completely, so the
 * FIFO cannot end up half a chunk out of step. */
uint8_t radio_rx(uint8_t *payload, uint8_t maxlen) __reentrant
{
    uint8_t hdr, flags, count, i;
    uint8_t ok = 0;

    if (radio_read8(AX5043_REG_FIFOSTAT) & RADIO_FIFOSTAT_EMPTY)
        return 0;

    /* Chunk header: top three bits are the payload size, 7 meaning "the
     * next byte is the length" (manual table 3), bottom five the type. */
    hdr = radio_read8(AX5043_REG_FIFODATA);
    count = (uint8_t)((hdr & 0xE0) >> 5);
    if (count == 7)
        count = radio_read8(AX5043_REG_FIFODATA);

    radio_state[RADIO_DIAG_RXCOUNT] = count;

    if ((hdr & 0x1F) != 0x01 || !count) {
        /* Not a DATA chunk (metadata chunks, should PKTSTOREFLAGS ever be
         * changed back): skip its payload. */
        for (i = 0; i < count; i++)
            (void)radio_read8(AX5043_REG_FIFODATA);
        return 0;
    }

    flags = radio_read8(AX5043_REG_FIFODATA);
    count--;                            /* the flag byte is not data */
    radio_state[RADIO_DIAG_RXFLAGS] = flags;

    if (count && !(flags & RADIO_RX_BAD) && (flags & RADIO_RX_PKTSTART)) {
        uint8_t plen = radio_read8(AX5043_REG_FIFODATA);

        count--;
        /* The chip already size-checked the packet, so the length byte must
         * agree with what is left; if it does not, this is not our frame. */
        if (plen == (uint8_t)(count + 1) && count <= maxlen) {
            ax5043_readfifo(payload, count);
            ok = count;
        }
    }

    if (!ok) {
        /* Drain whatever is left of the chunk so the FIFO stays aligned. */
        while (count--) {
            if (!(radio_read8(AX5043_REG_FIFOSTAT) & RADIO_FIFOSTAT_EMPTY))
                (void)radio_read8(AX5043_REG_FIFODATA);
        }
        return 0;
    }

    /* The chip leaves the received signal strength in the RSSI register at
     * the end of the packet; strip the +64 dB the reference builds into
     * RSSIREFERENCE. */
    radio_state[RADIO_DIAG_RSSI] =
        (uint8_t)(radio_read8(AX5043_REG_RSSI) - RADIO_RSSI_OFFSET);

    return ok;
}
