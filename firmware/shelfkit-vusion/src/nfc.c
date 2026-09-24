/**
 * @file nfc.c
 * @brief Fudan FM11NT081DS NFC tag chip - contact (SPI) interface driver
 *
 * The chip is a passive NFC Forum Type 2 tag with a 924-byte EEPROM that
 * can also be reached over SPI by the AX8052. The factory-programmed
 * 7-byte UID (the tag's serial number) is at EEPROM address 0x000.
 *
 * ── Why this is bit-banged ────────────────────────────────────────────
 * The FM11NT081DS SPI slave only implements mode 1 (CPOL=0, CPHA=1, the
 * factory default) or mode 3 - see the FM11NT081D technical manual,
 * section 4.2.5. The AX8052's SPI unit is configured for mode 0, because
 * that is what the IL0373 e-paper controller on the same bus needs, and
 * the mode bits of SPMODE are not documented in the AX8052F143 datasheet.
 * A mode-0 master talking to a mode-1 slave is a timing race (the master
 * changes MOSI on the same edge the slave samples it), so instead of
 * guessing SPMODE bits this driver drives SCK/MOSI as GPIO and reads MISO
 * from PINC, then hands the bus back to the hardware SPI (nfc_release()).
 *
 * Pin control follows the AX8052F143 datasheet, figure 10 ("Port Pin
 * Schematic"): with DIRx.y = 1 the PALTx.y bit selects between the
 * peripheral output (1) and the PORT register (0), so clearing the PALTC
 * bits routes SCK/MOSI to the GPIO. MISO has to be read from PINC - PORTC
 * is the output latch and only holds the pull-up bit for an input pin.
 *
 * ── Protocol ──────────────────────────────────────────────────────────
 * The contact interface is a 24-series-style EEPROM (technical manual
 * 4.2.2/4.2.6): SSN low wakes the chip up (>= 100 us), then a command
 * byte and an address byte. "Read EEPROM" is 011_000xx, where xx are
 * address bits A9:A8; the following byte is A7:A0 and the internal address
 * pointer auto-increments, so one command reads a run of bytes. SSN high
 * for >= 50 ns resets the SPI port for the next frame.
 */

#include "nfc.h"
#include "nfc_ndef.h"
#include "board.h"
#include "spi.h"

/* ── bus pins (see board.h and documentation/signal-list.md) ─────────── */

#define NFC_SCK     SPI_SCK     /* PC1 */
#define NFC_MOSI    SPI_MOSI    /* PC2 */
#define NFC_MISO    PINC_3      /* PC3 - input: read the pin, not the latch */
#define NFC_CS      CS_NFC      /* PB1 */

#define NFC_PALT_MASK   0x0E    /* PC1, PC2, PC3 alternate-function bits */
#define NFC_OUT_MASK    0x06    /* PC1 (SCK), PC2 (MOSI) */
#define NFC_MISO_MASK   0x08    /* PC3 */

/* "Read EEPROM": 011_000xx, xx = address bits A9:A8 */
#define NFC_CMD_READ_EE 0x60

/* SSN-low to first clock: the datasheet asks for >= 100 us of power-up
 * preparation (4.2.3). delay() is microseconds (libmftypes.h) and errs on
 * the long side on this tag, which is fine. */
#define NFC_WAKE_US     200

/* SSN must stay high >= 50 ns so the slave resets its SPI port (5.3.3) */
#define NFC_RESET_US    2

/* ── bus muxing ──────────────────────────────────────────────────────── */

static uint8_t nfc_paltc;       /* PALTC as it was before we took the pads */

void nfc_init(void)
{
    /* Every chip select high first, exactly like spi_init() - the flash
     * and the panel must stay off the bus while we talk to the NFC chip. */
    DIRA |= 0x02;                   /* EPD CS on PA1 */
    DIRB |= 0x02;                   /* NFC CS on PB1 */
    DIRC |= 0x01;                   /* FLASH CS on PC0 */
    CS_EPD   = 1;
    CS_FLASH = 1;
    NFC_CS   = 1;

    /* Stop the SPI unit (the vendor's own lcd_portoff() uses this exact
     * pair) and give the three SPI pads back to the GPIO. */
    SPCLKSRC = 0x07;                /* SPI clock off */
    SPMODE   = 0x00;                /* SPI master off */
    nfc_paltc = PALTC;
    PALTC &= (uint8_t)~NFC_PALT_MASK;

    DIRC |= NFC_OUT_MASK;           /* SCK, MOSI = outputs */
    DIRC &= (uint8_t)~NFC_MISO_MASK;/* MISO = input */

    NFC_SCK  = 0;                   /* mode 1: clock idles low */
    NFC_MOSI = 0;
    PORTC |= NFC_MISO_MASK;         /* input: PORT bit = pull-up on */
}

void nfc_release(void)
{
    PALTC = nfc_paltc;              /* pads back to the SPI peripheral */
    spi_init();                     /* and the SPI unit back on for the panel */
}

/* ── bit-banged mode-1 transfer ──────────────────────────────────────── */

static void nfc_bb_delay(void)
{
    /* A few cycles at 20 MHz. The chip takes up to 5 MHz (200 ns per
     * clock); this lands around 100-200 kHz, which is plenty for a
     * boot-time read and leaves the timing jitter-proof. */
    volatile uint8_t i;
    for (i = 4; i; i--)
        ;
}

static uint8_t nfc_bb_transfer(uint8_t out)
{
    uint8_t in = 0;
    uint8_t i;

    for (i = 0; i < 8; i++) {
        /* Mode 1 (CPOL=0, CPHA=1): the clock idles low, MOSI changes while
         * it is low and is sampled by the chip on the falling edge, and
         * the chip shifts MISO out on the rising edge - so sample MISO
         * while the clock is high, right before the falling edge. */
        NFC_MOSI = (out & 0x80) ? 1 : 0;
        out = (uint8_t)(out << 1);
        nfc_bb_delay();

        NFC_SCK = 1;
        nfc_bb_delay();

        in = (uint8_t)(in << 1);
        if (NFC_MISO)
            in |= 0x01;

        NFC_SCK = 0;
        nfc_bb_delay();
    }
    return in;
}

/* ── EEPROM access ───────────────────────────────────────────────────── */

void nfc_read(uint16_t addr, uint8_t *buf, uint8_t len) __reentrant
{
    uint8_t i;

    NFC_CS = 0;
    delay(NFC_WAKE_US);             /* power the chip up */

    nfc_bb_transfer((uint8_t)(NFC_CMD_READ_EE | ((addr >> 8) & 0x03)));
    nfc_bb_transfer((uint8_t)addr); /* A7:A0 */

    for (i = 0; i < len; i++)
        buf[i] = nfc_bb_transfer(0x00);

    NFC_CS = 1;
    delay(NFC_RESET_US);            /* >= 50 ns high resets the SPI port */
}

uint8_t nfc_read_serial(uint8_t serial[NFC_SERIAL_LEN]) __reentrant
{
    /* In XRAM like every other buffer here: a 9-byte local array plus the
     * parameter block would be a 20-plus byte chunk of the 128 bytes of
     * directly addressable RAM this part has for everything. */
    static uint8_t __xdata raw[9];  /* SN0..2, BCC0, SN3..6, BCC1 */
    uint8_t bcc0, bcc1;

    nfc_read(NFC_SERIAL_ADDR, raw, 9);

    /* The UID is stored around BCC0: page 0 holds SN0-SN2, page 1 holds
     * SN3-SN6, page 2 starts with BCC1. */
    serial[0] = raw[0];
    serial[1] = raw[1];
    serial[2] = raw[2];
    serial[3] = raw[4];
    serial[4] = raw[5];
    serial[5] = raw[6];
    serial[6] = raw[7];

    /* ISO/IEC 14443-3 check bytes for a 7-byte UID / cascade level 2:
     * BCC0 includes the 0x88 cascade tag. */
    bcc0 = (uint8_t)(0x88 ^ raw[0] ^ raw[1] ^ raw[2]);
    bcc1 = (uint8_t)(raw[4] ^ raw[5] ^ raw[6] ^ raw[7]);

    if (raw[3] != bcc0 || raw[8] != bcc1)
        return 0;
    return 1;
}

/* ── serial number from the NDEF record ──────────────────────────────── */

/* The TLV area and the reconstructed URI live in XRAM - 152 bytes that the
 * 256-byte internal RAM does not have to give up (see main.c). */
static uint8_t __xdata nfc_tlv[NFC_TLV_WINDOW];
static char    __xdata nfc_uri[NFC_NDEF_URI_MAX];

/* Read the TLV window off the chip and rebuild the URI into nfc_uri.
 * Returns the URI length, or 0 when there is no usable URI record. */
static uint8_t nfc_load_uri(void)
{
    uint16_t i;
    uint8_t  n;

    /* 16 bytes per transaction, and the window never crosses a 256-byte
     * block boundary, which is all one read command can reach. */
    for (i = 0; i < NFC_TLV_WINDOW; i += 16) {
        n = 16;
        if (NFC_TLV_WINDOW - i < 16)
            n = (uint8_t)(NFC_TLV_WINDOW - i);
        nfc_read((uint16_t)(NFC_TLV_ADDR + i), &nfc_tlv[i], n);
    }

    return nfc_ndef_uri(nfc_tlv, NFC_TLV_WINDOW, nfc_uri, sizeof nfc_uri);
}

uint8_t nfc_read_tag_serial(char *serial, uint8_t maxlen) __reentrant
{
    if (!nfc_load_uri())
        return 0;
    return nfc_ndef_last_segment(nfc_uri, serial, maxlen);
}

uint8_t nfc_read_ndef_uri(char *uri, uint8_t maxlen) __reentrant
{
    uint8_t n, i;

    n = nfc_load_uri();
    if (!n || (uint8_t)(n + 1) > maxlen)
        return 0;

    for (i = 0; i < n; i++)
        uri[i] = nfc_uri[i];
    uri[n] = 0;
    return n;
}

uint8_t nfc_uid_string(char *out, uint8_t maxlen) __reentrant
{
    static const char hex[] = "0123456789ABCDEF";
    static uint8_t __xdata raw[NFC_SERIAL_LEN];
    uint8_t i;

    if (maxlen < (NFC_SERIAL_LEN * 2) + 1)
        return 0;

    /* Not nfc_read_serial(): for an identifier we would rather have the
     * bytes than a check-byte verdict. */
    (void)nfc_read_serial(raw);

    for (i = 0; i < NFC_SERIAL_LEN; i++) {
        out[(i * 2)]     = hex[raw[i] >> 4];
        out[(i * 2) + 1] = hex[raw[i] & 0x0F];
    }
    out[NFC_SERIAL_LEN * 2] = 0;
    return NFC_SERIAL_LEN * 2;
}
