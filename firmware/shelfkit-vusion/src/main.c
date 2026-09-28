/**
 * @file main.c
 * @brief Read the NFC chip, show the polyform logo, then receive images
 *
 * Boots, brings up UART0 and the SPI bus, reads the NFC chip's serial
 * number and the whole NFC EEPROM and prints both over UART, then brings
 * up the e-paper display (GDEW026Z39, 2.6"), uploads the polyform boot
 * image (both black/white and red planes), refreshes the panel, powers it
 * down, and flashes the blue LED once when the refresh has finished. The
 * panel holds the image in deep sleep.
 *
 * After that the tag stops being a demo and starts being a shelf label: it
 * sits in a receive loop, re-announcing its serial number every few seconds
 * so an access point can find it, and accepts an image transfer addressed to
 * that serial number. A transfer arrives as IMG_BEGIN / IMG_DATA / IMG_END
 * (firmware/shared/include/shelfkit_proto.h), is staged in the upper half of
 * the 128 KiB SPI flash - 11248 bytes do not fit in 8 KiB of XRAM - and is
 * streamed back out to the panel from there once IMG_END says the image is
 * complete and its CRC-16 checks out.
 *
 * The NFC read happens first: it needs the SPI pads as GPIO (the chip is a
 * mode-1 SPI slave, the panel a mode-0 one - see nfc.c) and hands the bus
 * back to the hardware SPI unit when it is done.
 *
 * UART0 is TX-only debug logging at 38400 8N1 on PB4, using the same
 * register-level output path as the flash-dump firmware (avoids the
 * broken libmf FIFO tables). RX is never enabled, so PB5 stays free for
 * the panel's reset line.
 */

#include <ax8052f143.h>
#include <libmf.h>
#include <libmftypes.h>
#include <libmfcrc.h>       /* crc_ccitt_msb() - the image CRC */
#include "hal.h"
#include "board.h"
#include "pwr.h"
#include "spi.h"
#include "nfc.h"
#include "radio.h"
#include "sk_link.h"
#include "uart.h"
#include "epd.h"
#include "epd_image.h"      /* epd_image_bw / epd_image_red */
#include "flash.h"
#include "shelfkit_proto.h"

/* How often an idle tag repeats its announcement, in milliseconds. Long
 * enough not to talk over a transfer, short enough that an access point
 * which comes up after the tag still finds it.
 *
 * A leaf says it ten times less often (LEAF_ANNOUNCE_MS): an announcement is
 * the main thing a leaf transmits on its own account, and a battery label
 * that is already asleep most of the time should not wake up to say hello
 * every ten seconds. It is still often enough that an access point which
 * comes up later finds it within a minute.
 *
 * (The leaf's number is written out rather than 10 s x 6 because SDCC is
 * right to warn about the overflow in the multiply: 60000 does not fit in a
 * signed 16-bit int.) */
#define ANNOUNCE_INTERVAL_MS 10000
#define LEAF_ANNOUNCE_MS     60000

#if SK_TAG_ROUTER
#define IDLE_ANNOUNCE_MS     ANNOUNCE_INTERVAL_MS
#else
#define IDLE_ANNOUNCE_MS     LEAF_ANNOUNCE_MS
#endif

/* Is this tag a mains-powered router or a battery leaf?
 *
 *   0 (default)  leaf: never relays, and spends its idle life in
 *                wake-on-radio (radio.h). This is what a battery label is.
 *   1            router: stays in continuous receive and relays other
 *                nodes' traffic, so tags further away reach the access
 *                point through it. This is what a label with a permanent
 *                supply is - and it is the board that makes a mesh out of
 *                a star.
 *
 * Build with -DSK_TAG_ROUTER=1 for the second one; tools/build_firmware.ps1
 * takes -Define SK_TAG_ROUTER=1. The link layer itself does not care which
 * this is - it is one bit in every frame it sends, and one decision about
 * relaying (sk_link.h). */
#ifndef SK_TAG_ROUTER
#define SK_TAG_ROUTER 0
#endif

/* How long a leaf stays in continuous receive after it hears something, in
 * milliseconds. This is the other half of wake-on-radio: waking up costs the
 * sender a few hundred milliseconds of long preamble, so once a tag is up it
 * stays up for the rest of the conversation - an image transfer's frames
 * arrive every couple of hundred milliseconds, and the tag has to be
 * listening for them anyway to answer each one. When the window expires with
 * nothing heard, the tag goes back to WOR. */
#define LEAF_AWAKE_MS 3000

/* How long a transfer may go without a frame before the tag gives up on it,
 * in milliseconds. The access point is stop-and-wait, so a healthy transfer
 * has frames every few hundred ms; this is only here so a sender that dies
 * mid-transfer cannot leave the tag refusing every BEGIN with SK_ST_BUSY
 * until the battery is pulled. */
#define RX_STALL_MS 30000

/* ── UART TX debug logging (register-level) ──────────────────────────── */

static void uart_putc(uint8_t c)
{
    while (!(U0STATUS & 0x04))      /* wait for U0TXEMPTY */
        ;
    U0SHREG = c;
    U0CTRL |= 0x08;                 /* arm the TX-done flag, like iocore */
}

static void uart_puts(const char *s)
{
    while (*s)
        uart_putc((uint8_t)*s++);
}

static void uart_puthex8(uint8_t v)
{
    static const char hex[] = "0123456789ABCDEF";
    uart_putc(hex[v >> 4]);
    uart_putc(hex[v & 0x0F]);
}

static void uart_puthex16(uint16_t v)
{
    uart_puthex8((uint8_t)(v >> 8));
    uart_puthex8((uint8_t)v);
}

/* ── NFC chip: serial number + EEPROM dump ───────────────────────────── */

/* Scratch lives in XRAM: this is an 8051, and keeping it out of IRAM
 * leaves the whole internal RAM as stack headroom. */
static uint8_t __xdata nfc_uid[NFC_SERIAL_LEN];
static uint8_t __xdata nfc_buf[16];

/* The tag's identity, as the stock system defines it: the last path segment
 * of the NDEF URI stored in the NFC chip ("1408F525"). Used to address an
 * announcement and to match an incoming transfer. */
static char __xdata nfc_serial_str[NFC_SERIAL_STR_MAX];
static uint8_t nfc_serial_len;

/* One outgoing radio payload: the announcement, an IMG_ACK or an
 * IMG_STATUS. XRAM again: 19 bytes of a 128-byte internal RAM is a lot to
 * spend on a packet. */
static uint8_t __xdata tx_pkt[SK_PKT_MAX];

/* This tag's link address (sk_link.h), and whether it is currently awake.
 * Both are XRAM for the same reason as everything else here: the 128 bytes
 * of directly addressable internal RAM are the stack's, and main() - which
 * is not __reentrant and therefore keeps its locals in the overlay area
 * those 128 bytes hold - has no room to spare at all. */
static uint32_t __xdata tag_id;
static uint8_t __xdata link_awake;

static void nfc_report(void)
{
    uint8_t ok, i;
    uint16_t addr;

    uart_puts("\r\n--- NFC chip (FM11NT081DS) ---\r\n");

    nfc_init();                     /* bit-bang the bus, SPI unit off */

    ok = nfc_read_serial(nfc_uid);
    uart_puts("UID (7 bytes): ");
    for (i = 0; i < NFC_SERIAL_LEN; i++) {
        uart_puthex8(nfc_uid[i]);
        if (i + 1 < NFC_SERIAL_LEN)
            uart_putc(' ');
    }
    uart_puts(ok ? "  [check bytes ok]\r\n"
                 : "  [check bytes BAD - read is not trustworthy]\r\n");

    /* The serial number: last path segment of the NDEF URI record */
    nfc_serial_len = nfc_read_tag_serial(nfc_serial_str, sizeof nfc_serial_str);
    if (nfc_serial_len) {
        uart_puts("serial number: ");
        for (i = 0; i < nfc_serial_len; i++)
            uart_putc((uint8_t)nfc_serial_str[i]);
        uart_puts("  [from the NDEF URI]\r\n");
    } else {
        /* No usable NDEF record - fall back to the UID so the tag can still
         * be told apart, and say so plainly. */
        nfc_serial_len = nfc_uid_string(nfc_serial_str, sizeof nfc_serial_str);
        uart_puts("serial number: ");
        for (i = 0; i < nfc_serial_len; i++)
            uart_putc((uint8_t)nfc_serial_str[i]);
        uart_puts("  [NO NDEF RECORD - using the UID]\r\n");
    }

    /* Capability container: E1 10 <user bytes/8> <access> for a Type 2 tag */
    nfc_read(NFC_CC_ADDR, nfc_buf, 4);
    uart_puts("capability container: ");
    for (i = 0; i < 4; i++) {
        uart_puthex8(nfc_buf[i]);
        uart_putc(' ');
    }
    uart_puts((nfc_buf[0] == 0xE1) ? "(NFC Forum Type 2 tag)\r\n"
                                   : "(unexpected - see nfc.c)\r\n");

    uart_puts("EEPROM dump, 924 bytes:\r\n");
    for (addr = 0; addr < NFC_EEPROM_SIZE; addr += 16) {
        uint8_t n = 16;             /* the last line is short (924 = 57*16 + 12) */
        if (NFC_EEPROM_SIZE - addr < 16)
            n = (uint8_t)(NFC_EEPROM_SIZE - addr);

        nfc_read(addr, nfc_buf, n);
        uart_puthex16(addr);
        uart_puts(": ");
        for (i = 0; i < n; i++) {
            uart_puthex8(nfc_buf[i]);
            uart_putc(' ');
        }
        for (i = n; i < 16; i++)    /* keep the ASCII column lined up */
            uart_puts("   ");
        uart_puts(" |");
        for (i = 0; i < n; i++) {
            uint8_t c = nfc_buf[i];
            uart_putc((c >= 32 && c <= 126) ? c : '.');
        }
        uart_puts("|\r\n");
    }
    uart_puts("--- end of NFC dump ---\r\n");

    nfc_release();                  /* SPI unit back on for the panel */
}

/* ── small helpers ────────────────────────────────────────────────────── */

static void ms_delay(uint16_t ms)
{
    while (ms--)
        delay(1000);
}

/* ── start the display ────────────────────────────────────────────────── */

/* BUSY helpers are level-agnostic (work with either tag polarity):
 * wait for an edge away from a level, then wait for a return to it. */

static void wait_busy_change(uint8_t from_level, uint16_t timeout_ms)
{
    uint16_t t = timeout_ms;
    while (EPD_BUSY == from_level) {
        if (!--t)
            break;
        delay(1000);
    }
}

static void wait_busy_return(uint8_t to_level, uint16_t timeout_ms)
{
    uint16_t t = timeout_ms;
    while (EPD_BUSY != to_level) {
        if (!--t)
            break;
        delay(1000);
    }
}

static void epd_write_cmd(uint8_t cmd)
{
    EPD_DC = 0;
    spi_select(SPI_DEV_EPD);
    spi_transfer(cmd);
    spi_deselect(SPI_DEV_EPD);
    EPD_DC = 1;
}

static void epd_write_data(uint8_t data)
{
    spi_select(SPI_DEV_EPD);
    spi_transfer(data);
    spi_deselect(SPI_DEV_EPD);
}

static void epd_init_panel(void)
{
    uint8_t idle;

    /* DC out (PA0), RST out (PB5), BUSY in (PB2); CS (PA1) per spi_init */
    DIRA |= 0x01;
    DIRB |= 0x20;
    DIRB &= (uint8_t)~0x04;
    EPD_DC = 1;
    EPD_RST = 1;

    /* Hardware reset: 100 ms low, 100 ms settle */
    EPD_RST = 0;
    ms_delay(100);
    EPD_RST = 1;
    ms_delay(100);

    /* Booster soft start */
    epd_write_cmd(0x06);
    epd_write_data(0x17);
    epd_write_data(0x17);
    epd_write_data(0x17);

    /* Power on and let the booster pulse settle */
    idle = EPD_BUSY;
    epd_write_cmd(0x04);
    wait_busy_change(idle, 1500);
    wait_busy_return(idle, 2500);

    /* Panel setting: LUT from OTP, BWR */
    epd_write_cmd(0x00);
    epd_write_data(0x0F);

    /* Resolution: 152 x 296 (from epd.h), 3-byte form */
    epd_write_cmd(0x61);
    epd_write_data((uint8_t)EPD_W);
    epd_write_data((uint8_t)((uint16_t)EPD_H >> 8));
    epd_write_data((uint8_t)EPD_H);

    /* VCOM and data interval */
    epd_write_cmd(0x50);
    epd_write_data(0x77);
}

/* ── announce ourselves to the access point ──────────────────────────── */

/* The radio is a separate block inside the AX8052F143 with its own register
 * window, so this neither touches nor disturbs the SPI bus the NFC chip and
 * the panel share. Runs before the panel refresh, which takes ~20 s. */

/* Build one SK_PKT_ANNOUNCE into tx_pkt and return its length, or 0 when
 * the tag has no serial number - it could then never be addressed by a
 * transfer either, and there is nothing useful to say. */
static uint8_t announce_build(void) __reentrant
{
    uint8_t len, i;

    if (!nfc_serial_len)
        return 0;

    tx_pkt[0] = SK_PROTO_VERSION;
    tx_pkt[1] = SK_PKT_ANNOUNCE;
    tx_pkt[2] = nfc_serial_len;
    for (i = 0; i < nfc_serial_len; i++)
        tx_pkt[SK_HDR_LEN + i] = (uint8_t)nfc_serial_str[i];
    len = (uint8_t)(SK_HDR_LEN + nfc_serial_len);

    return len;
}

/* One announcement from the receive loop. It is broadcast: the access point
 * may not know this tag exists yet, so there is nobody to address it to. */
static void announce_send(void) __reentrant
{
    uint8_t len = announce_build();

    if (len) {
        if (sk_link_send(SK_LINK_BROADCAST, tx_pkt, len) == SK_LINK_OK)
            uart_puts("radio: announced\r\n");
        else
            uart_puts("radio: announce failed\r\n");
    }
}

static void announce(void) __reentrant
{
    uint8_t d[RADIO_DIAG_LEN];
    uint8_t len, i, err;

    if (!nfc_serial_len) {
        uart_puts("radio: no serial number, not announcing\r\n");
        return;
    }

    len = announce_build();

    uart_puts("radio: ");
    err = radio_init();
    if (err) {
        uart_puts("init failed, code ");
        uart_puthex8(err);
        uart_puts(" - ");
        uart_puts(radio_error_str(err));
        uart_puts("\r\n");

        radio_diag(d);
        uart_puts("radio: rev ");
        uart_puthex8(d[RADIO_DIAG_REV]);
        uart_puts(", XTALSTATUS ");
        uart_puthex8(d[RADIO_DIAG_XTAL]);
        uart_puts(", POWSTAT ");
        uart_puthex8(d[RADIO_DIAG_POWSTAT]);
        uart_puts("\r\n       PLLRANGINGA ");
        uart_puthex8(d[RADIO_DIAG_RANGING]);
        if (d[RADIO_DIAG_RANGING] & 0x10)
            uart_puts(" RNGSTART STUCK");
        else if (d[RADIO_DIAG_RANGING] & 0x20)
            uart_puts(" RNGERR");
        else
            uart_puts(" ranged");
        if (d[RADIO_DIAG_RANGING] & 0x40)
            uart_puts(", PLL locked");
        else
            uart_puts(", PLL NOT LOCKED");
        uart_puts(", VCOI ");
        uart_puthex8(d[RADIO_DIAG_VCOI]);
        uart_puts(" VCOIR ");
        uart_puthex8(d[RADIO_DIAG_VCOIR]);
        uart_puts("\r\n");

        return;                     /* the panel demo still runs */
    }
    radio_diag(d);
    uart_puts("ready (silicon rev ");
    uart_puthex8(radio_revision());
    uart_puts(", PLLRANGINGA ");
    uart_puthex8(d[RADIO_DIAG_RANGING]);
    if (d[RADIO_DIAG_RANGING] & 0x40)
        uart_puts(" PLL locked");
    else
        uart_puts(" PLL NOT LOCKED");
    uart_puts(", VCOI ");
    uart_puthex8(d[RADIO_DIAG_VCOI]);
    uart_puts(")\r\n");

    /* A few repeats: the access point may have started listening after the
     * tag powered up, and this beacon is the only way it finds us. */
    for (i = 0; i < RADIO_ANNOUNCE_REPEATS; i++) {
        err = sk_link_send(SK_LINK_BROADCAST, tx_pkt, len);
        if (err) {
            uart_puts("radio: tx failed, code ");
            uart_puthex8(err);
            uart_puts("\r\n");
            return;
        }
        if (i + 1 < RADIO_ANNOUNCE_REPEATS)
            ms_delay(RADIO_ANNOUNCE_GAP_MS);
    }
    uart_puts("radio: announced\r\n");
}

/* ── receiving an image ──────────────────────────────────────────────────
 *
 * State of the one transfer the tag can have open at a time. Everything is
 * in XRAM: this part has 128 bytes of directly addressable internal RAM and
 * SDCC spends it on statics and parameter blocks before the stack gets any
 * (that is also why every function with parameters here is __reentrant).
 *
 * The sender is stop-and-wait: it sends one IMG_DATA frame and waits for the
 * ACK that says which image byte the tag needs next. That makes the offset
 * in the frame the whole flow control - the tag never has to buffer out of
 * order, and a frame that arrives twice costs nothing but a repeated ACK.
 */

/* 0 = nothing going on, 1 = a transfer is open, 2 = the last transfer has
 * been answered. The third state is not idle: the panel refresh takes ~20 s
 * without the radio being serviced, so the access point's IMG_END repeats
 * are still waiting in the FIFO afterwards and every one of them needs the
 * same answer, not a fresh "start over". */
#define RX_IDLE       0
#define RX_RECEIVING  1
#define RX_DONE       2

static uint8_t __xdata rx_pkt[SK_PKT_MAX];  /* one received radio payload */

/* A flash page being assembled while a transfer is running. */
static uint8_t __xdata page_buf[FLASH_PAGE_SIZE];

/* One whole plane, read out of the flash in one go and handed to the panel
 * in one transaction. 5624 bytes is affordable - the tag has 8192 - and it
 * buys the *proven* wire sequence: one CS-low burst per plane, exactly what
 * the boot image already does on this panel. Pushing a plane in chunks with
 * CS released in between would save the RAM but is a sequence nothing here
 * has ever run (see epd.h). */
static uint8_t __xdata plane_buf[SK_IMG_PLANE_BYTES];

static uint8_t  __xdata rx_state;
static uint8_t  __xdata rx_status;      /* verdict of a finished transfer */
static uint16_t __xdata rx_next;        /* next image byte the sender must send */
static uint16_t __xdata rx_total;       /* image size the transfer announced */
static uint16_t __xdata rx_crc;         /* CRC-16 the sender computed */
static uint16_t __xdata rx_crc_run;     /* CRC-16 over the bytes accepted so far */

/* 11248 bytes cover three 4 KiB sectors of the flash: two whole ones and
 * 3056 bytes of a third. */
#define SK_IMG_SECTORS \
    ((uint16_t)((SK_IMG_TOTAL_BYTES + FLASH_SECTOR_SIZE - 1) / FLASH_SECTOR_SIZE))

/* ── packets out ──────────────────────────────────────────────────────── */

/* Send tx_pkt (len bytes) and leave the receiver in whatever mode the tag is
 * in (sk_link_rx_mode): radio_tx() powers the chip down when it is done, and
 * a node that did not re-arm would go deaf. The destination is whoever sent
 * the frame now being answered - the access point - which the link layer
 * remembers from the last packet it delivered. Nothing is logged: the
 * receive loop may answer a hundred frames in a row. */
static void tx_and_listen(uint8_t len) __reentrant
{
    uint8_t err = sk_link_send(sk_link_origin(), tx_pkt, len);

    /* A failed transmit used to be invisible here, because the loop answers
     * too many frames to log every success. It is the one failure worth a
     * line: a tag that cannot transmit looks exactly like a tag that is out
     * of range, and this is the difference. */
    if (err) {
        uart_puts("radio: tx failed, code ");
        uart_puthex8(err);
        uart_puts("\r\n");
    }
}

/* IMG_ACK: [ver][type][off hi][off lo][status] - "I have every image byte
 * below off". Also the answer to IMG_BEGIN (off = 0) and, with off = the
 * image size, to IMG_END. */
static void ack_send(uint16_t off, uint8_t status) __reentrant
{
    tx_pkt[0] = SK_PROTO_VERSION;
    tx_pkt[1] = SK_PKT_IMG_ACK;
    tx_pkt[2] = (uint8_t)(off >> 8);
    tx_pkt[3] = (uint8_t)off;
    tx_pkt[4] = status;
    tx_and_listen(5);
}

/* IMG_STATUS: [ver][type][slen][serial n][status] - a transfer was refused or
 * failed. It carries the serial because an access point may be talking to
 * several tags and has to know which one is unhappy. */
static void status_send(uint8_t status) __reentrant
{
    uint8_t len, i;

    tx_pkt[0] = SK_PROTO_VERSION;
    tx_pkt[1] = SK_PKT_IMG_STATUS;
    tx_pkt[2] = nfc_serial_len;
    for (i = 0; i < nfc_serial_len; i++)
        tx_pkt[SK_HDR_LEN + i] = (uint8_t)nfc_serial_str[i];
    len = (uint8_t)(SK_HDR_LEN + nfc_serial_len);
    tx_pkt[len] = status;
    len++;

    tx_and_listen(len);
}

/* ── staging into the flash ───────────────────────────────────────────── */

/* Copy the payload of one IMG_DATA frame into the page being assembled and
 * program the flash whenever that page fills up. The image starts on a
 * 256-byte boundary of the flash (SK_IMG_FLASH_ADDR) and the page size is
 * 256, so an image offset's low byte is its offset inside its page.
 *
 * @return 1, or 0 when a page would not program or did not read back as
 *         written - the caller turns that into SK_ST_FLASH. */
static uint8_t stage_data(const uint8_t *data, uint16_t len) __reentrant
{
    while (len) {
        uint16_t at = (uint16_t)(rx_next & (FLASH_PAGE_SIZE - 1));
        uint16_t room = (uint16_t)(FLASH_PAGE_SIZE - at);   /* 256 when at is 0 */
        uint16_t n = room;
        uint16_t i;

        if (len < n)
            n = len;

        for (i = 0; i < n; i++)
            page_buf[at + i] = data[i];

        /* The CRC covers the image in the order it arrives, and bytes are
         * only ever staged when their offset is the next one needed, so
         * this sees every image byte exactly once, in sequence. */
        rx_crc_run = crc_ccitt_msb(data, n, rx_crc_run);

        rx_next = (uint16_t)(rx_next + n);
        data += n;
        len = (uint16_t)(len - n);

        if ((rx_next & (FLASH_PAGE_SIZE - 1)) == 0) {
            /* The offset just wrapped: a whole page is in hand. rx_next is
             * a multiple of the page size, so the page starts one page
             * below it. */
            uint32_t addr = SK_IMG_FLASH_ADDR + (uint32_t)rx_next - FLASH_PAGE_SIZE;

            if (!extflash_write(addr, page_buf, FLASH_PAGE_SIZE))
                return 0;
            if (!extflash_verify(addr, page_buf, FLASH_PAGE_SIZE))
                return 0;

            uart_puts("img: page ");
            uart_puthex16(rx_next);
            uart_puts(" ok\r\n");
        }
    }

    return 1;
}

/* ── stream the staged image to the panel ─────────────────────────────── */

/* Send both planes from the flash to the panel and refresh it. This takes
 * ~20 s, during which the radio is not serviced at all: the AX5043 keeps
 * receiving into its FIFO and the access point simply repeats whatever it
 * does not get an answer to. Nothing here can lose the tag's place - the
 * whole image is already in the flash before the first byte goes out. */
static void show_image(void) __reentrant
{
    uint8_t idle;

    /* The boot refresh ended with POF, so the panel is off: bring it up
     * again with the same sequence the boot image used. */
    epd_init_panel();

    /* Two bulk reads out of the flash and two whole-plane uploads. That is
     * byte for byte the sequence the boot image has already proved on this
     * panel: one CS-low burst per plane, no interrupts in the middle of a
     * transfer. (epd_stream_begin()/epd_stream_data() still exist, and
     * epd_upload() is built on them, for an image that does not fit in XRAM
     * - but a plane pushed in chunks is a wire sequence nothing has run.) */
    extflash_read(SK_IMG_FLASH_ADDR, plane_buf, SK_IMG_PLANE_BYTES);
    epd_upload(0x10, plane_buf, SK_IMG_PLANE_BYTES);            /* black/white */

    extflash_read(SK_IMG_FLASH_ADDR + SK_IMG_PLANE_BYTES, plane_buf,
                  SK_IMG_PLANE_BYTES);
    epd_upload(0x13, plane_buf, SK_IMG_PLANE_BYTES);            /* red */

    uart_puts("img: refreshing panel\r\n");
    idle = EPD_BUSY;
    epd_write_cmd(0x12);            /* display refresh */
    wait_busy_change(idle, 3000);
    wait_busy_return(idle, 30000);  /* a full refresh is ~20 s */

    /* There is no status code for "the panel did not finish", and the image
     * is safely in the flash either way, so this is reported and nothing
     * more. The wording is deliberately loud: on the bench this is the line
     * that says "the transfer worked, the panel did not". */
    if (EPD_BUSY != idle)
        uart_puts("img: PANEL REFRESH INCOMPLETE - image is stored but not shown\r\n");

    epd_write_cmd(0x02);            /* POF: the panel keeps the image */
}

/* ── the three transfer packets ───────────────────────────────────────── */

/* IMG_BEGIN: [ver][type][slen][serial n][total hi][total lo][crc hi][crc lo] */
static void img_begin(uint8_t len) __reentrant
{
    uint8_t slen = rx_pkt[2];
    uint8_t i, mine, sec;
    uint16_t total;

    /* The frame has to carry a serial, an image size and a CRC; the link
     * layer has already checked the frame's CRC-16. Anything that is not
     * that shape is not a BEGIN, and there is no sensible way to answer
     * it. */
    if (slen == 0 || slen > SK_SERIAL_MAX ||
        len != (uint8_t)(SK_HDR_LEN + slen + 4))
        return;

    /* The serial is the only addressing this link has: a transfer is for
     * the tag whose NFC chip carries that serial, and for nobody else.
     * Compared case-insensitively, because the host tool upper-cases a
     * serial before it puts it on the wire: a tag whose NDEF URI happened
     * to carry a lower-case one would otherwise refuse its own transfer
     * with SK_ST_BAD_SERIAL and look like a bug in the radio. Folding both
     * sides changes nothing about the bytes on the wire. */
    mine = 1;
    if (slen != nfc_serial_len)
        mine = 0;
    for (i = 0; mine && i < slen; i++) {
        uint8_t a = rx_pkt[SK_HDR_LEN + i];
        uint8_t b = (uint8_t)nfc_serial_str[i];

        if (a >= 'a' && a <= 'z')
            a = (uint8_t)(a - ('a' - 'A'));
        if (b >= 'a' && b <= 'z')
            b = (uint8_t)(b - ('a' - 'A'));
        if (a != b)
            mine = 0;
    }
    if (!mine) {
        uart_puts("img: BEGIN for another tag, refused\r\n");
        status_send(SK_ST_BAD_SERIAL);
        return;
    }

    if (rx_state == RX_RECEIVING) {
        uart_puts("img: BEGIN during a transfer, refused\r\n");
        status_send(SK_ST_BUSY);
        return;
    }

    total = (uint16_t)(((uint16_t)rx_pkt[SK_HDR_LEN + slen] << 8) |
                       rx_pkt[SK_HDR_LEN + slen + 1]);
    /* There is exactly one image this panel can show - 152 x 296 for each of
     * two planes - and exactly one place to stage it, so a transfer that
     * describes anything else cannot be honoured. Refusing now beats ending
     * up with half a picture on the screen. */
    if (total != SK_IMG_TOTAL_BYTES) {
        uart_puts("img: unknown image size ");
        uart_puthex16(total);
        uart_puts(", refused\r\n");
        status_send(SK_ST_UNSUPPORTED);
        return;
    }

    /* NOR flash can only be cleared by erasing, so the three sectors the
     * image will live in go first, before a single byte is acknowledged. */
    uart_puts("img: BEGIN, erasing ");
    uart_puthex8((uint8_t)SK_IMG_SECTORS);
    uart_puts(" sectors\r\n");
    extflash_release_powerdown();
    for (sec = 0; sec < SK_IMG_SECTORS; sec++) {
        uint32_t addr = SK_IMG_FLASH_ADDR + (uint32_t)sec * FLASH_SECTOR_SIZE;

        if (!extflash_sector_erase(addr)) {
            uart_puts("img: sector ");
            uart_puthex16((uint16_t)addr);
            uart_puts(" erase failed\r\n");
            status_send(SK_ST_FLASH);
            return;
        }
    }

    rx_total = total;
    rx_crc = (uint16_t)(((uint16_t)rx_pkt[SK_HDR_LEN + slen + 2] << 8) |
                        rx_pkt[SK_HDR_LEN + slen + 3]);
    /* CRC-16/CCITT-FALSE: init 0xFFFF, no final xor. Note that libmf's
     * crc_crc16_msb() is *not* this CRC - that one is poly 0x8005 - see
     * shelfkit_proto.h. */
    rx_crc_run = 0xFFFF;
    rx_next = 0;
    rx_status = SK_ST_OK;
    rx_state = RX_RECEIVING;

    uart_puts("img: receiving ");
    uart_puthex16(rx_total);
    uart_puts(" bytes, CRC ");
    uart_puthex16(rx_crc);
    uart_puts("\r\n");

    ack_send(0, SK_ST_OK);
}

/* IMG_DATA: [ver][type][off hi][off lo][data k] */
static void img_data(uint8_t len) __reentrant
{
    uint16_t off, k;

    /* Version, type, two offset bytes and at least one image byte. Note the
     * body starts at byte 2, not at SK_HDR_LEN: that constant is the header
     * of the packets that carry a *serial* (version, type, length), and
     * IMG_DATA has no serial-length byte - it goes straight to the offset.
     * Using SK_HDR_LEN here cost one image byte per frame and left the
     * acknowledged offset one short of the sender's, so every block was
     * retried forever. */
    if (len < 2 + 2 + 1)
        return;

    k = (uint16_t)(len - 2 - 2);
    off = (uint16_t)(((uint16_t)rx_pkt[2] << 8) | rx_pkt[3]);

    if (rx_state == RX_DONE) {
        /* Left over from the transfer that just ended: the panel refresh
         * above does not service the radio, so frames can be sitting in the
         * FIFO. Answer the end of that transfer, not a new beginning. */
        ack_send(rx_next, rx_status);
        return;
    }
    if (rx_state != RX_RECEIVING) {
        /* No transfer is open. Say where the next byte of one would be -
         * byte 0 - rather than guess which transfer this belongs to. */
        ack_send(0, SK_ST_OFFSET);
        return;
    }

    /* Runs past the end of the image: take none of it and say where we are. */
    if ((uint32_t)off + k > rx_total) {
        ack_send(rx_next, SK_ST_OFFSET);
        return;
    }

    if (off != rx_next) {
        /* Off below rx_next: a block already held, i.e. the ACK we sent for
         * it was lost - not an error. Off above it: a frame went missing.
         * Either way the answer is the offset we really need, and neither
         * may touch the flash: writing bytes where they do not belong is
         * the one thing that cannot be repaired later. */
        if (off < rx_next)
            ack_send(rx_next, SK_ST_OK);
        else
            ack_send(rx_next, SK_ST_OFFSET);
        return;
    }

    if (!stage_data(&rx_pkt[2 + 2], k)) {
        uart_puts("img: flash write failed at ");
        uart_puthex16(rx_next);
        uart_puts("\r\n");
        /* Hold the verdict where a repeat of this frame or of IMG_END will
         * find it, and let a new IMG_BEGIN start over. */
        rx_status = SK_ST_FLASH;
        rx_state = RX_DONE;
        status_send(SK_ST_FLASH);
        return;
    }

    ack_send(rx_next, SK_ST_OK);
}

/* IMG_END: [ver][type] */
static void img_end(void) __reentrant
{
    uint16_t base, left;

    if (rx_state == RX_DONE) {
        /* The access point repeats IMG_END until it gets an answer, and it
         * gets one only after the refresh: answer with the same verdict
         * again rather than with "start over". */
        ack_send(rx_next, rx_status);
        return;
    }
    if (rx_state != RX_RECEIVING) {
        ack_send(0, SK_ST_OFFSET);
        return;
    }

    if (rx_next != rx_total) {
        /* Not everything arrived. Asking for the next byte is what moves the
         * transfer on: the sender resends from there and no picture is
         * displayed with a hole in it. */
        uart_puts("img: END early, still need ");
        uart_puthex16(rx_next);
        uart_puts("\r\n");
        ack_send(rx_next, SK_ST_OFFSET);
        return;
    }

    /* Flush the last, partial page. The rest of it is still 0xFF because
     * the sector was erased at the start, so only the bytes that actually
     * arrived are programmed. */
    base = (uint16_t)(rx_next & ~(uint16_t)(FLASH_PAGE_SIZE - 1));
    left = (uint16_t)(rx_next - base);
    rx_status = SK_ST_OK;
    if (left) {
        uint32_t addr = SK_IMG_FLASH_ADDR + (uint32_t)base;

        if (!extflash_write(addr, page_buf, left) ||
            !extflash_verify(addr, page_buf, left)) {
            uart_puts("img: last page failed\r\n");
            rx_status = SK_ST_FLASH;
        }
    }

    if (rx_status == SK_ST_OK && rx_crc_run != rx_crc) {
        uart_puts("img: CRC mismatch: computed ");
        uart_puthex16(rx_crc_run);
        uart_puts(", sender said ");
        uart_puthex16(rx_crc);
        uart_puts(" - not displaying\r\n");
        rx_status = SK_ST_CRC;
    }

    if (rx_status == SK_ST_OK) {
        uart_puts("img: complete\r\n");
        show_image();
        uart_puts("img: displayed\r\n");
    }

    rx_state = RX_DONE;
    /* The answer goes out last: the access point is waiting for exactly this
     * verdict and knows the refresh takes ~20 s. Logged because a lost final
     * answer is otherwise indistinguishable from a tag that never got the
     * END at all - and it is the one frame in the transfer that is sent after
     * ten seconds of driving the panel rather than the radio. */
    uart_puts("img: answering END (off ");
    uart_puthex16(rx_total);
    uart_puts(" status ");
    uart_puthex8(rx_status);
    uart_puts(")\r\n");
    /* Sent twice, deliberately. This is the one answer in the transfer that
     * goes out after ten seconds of driving the panel rather than the radio,
     * and on the bench the first copy has been lost every time while the
     * block answers before it get through - see documentation/mesh.md's
     * "unverified" list. The access point drops the second copy as a
     * duplicate (same origin and sequence number), so a repeat costs one
     * frame and cannot be mistaken for a second verdict. */
    ack_send(rx_total, rx_status);
    ms_delay(250);
    ack_send(rx_total, rx_status);
}

/* One received application payload, already unwrapped and CRC-checked by the
 * link layer. A payload that is not this protocol, or not a type this
 * firmware knows, is dropped without an answer: guessing at a garbled frame
 * could stage the wrong bytes, and the access point's own timeout covers the
 * silence. */
static void handle_packet(uint8_t len) __reentrant
{
    if (len < SK_MIN_PAYLOAD)           /* version and type */
        return;
    if (rx_pkt[0] != SK_PROTO_VERSION)
        return;

    switch (rx_pkt[1]) {
    case SK_PKT_IMG_BEGIN:
        img_begin(len);
        break;
    case SK_PKT_IMG_DATA:
        img_data(len);
        break;
    case SK_PKT_IMG_END:
        img_end();
        break;
    default:
        /* An announcement from another tag, or a type this firmware does
         * not know: not ours, and nothing to answer. */
        break;
    }
}

/* ── boot ─────────────────────────────────────────────────────────────── */

void main()
{
    uint8_t idle;
    uint8_t len;
    uint16_t quiet_ms;

    periph_init();

    /* Power rails via the PA2/PA5 transistor lines (see pwr.h) */
    pwr_init();
    pwr_on();

    /* UART0 TX debug output, 38400 8N1 on PB4 (PALTB muxes PB4 to
     * U0TX). Only the TX direction is used; RX stays disabled so the
     * panel reset line on PB5 is untouched. */
    PALTB |= 0x10;
    DIRB |= 0x10;
    DIRB &= (uint8_t)~0x20;
    PORTB |= 0x30;

    /* Start the 20 MHz FRC oscillator, slaved to the 32 kHz LPX crystal
     * - the AXSEM bootloader's sequence, needed for exact 38400. */
    FRCOSCREF = 19531;
    FRCOSCKFILT = 2800;
    LPXOSCGM = 0x90;
    OSCFORCERUN |= 0x04;
    FRCOSCCONFIG = (6 << 3) | CLKSRC_LPXOSC;
    WTCFGB = (1 << 3) | CLKSRC_LPXOSC;
    {
        uint8_t i = 128;
        OSCCALIB = 0x01;
        IE_5 = 1;
        do {
            while (!(OSCCALIB & 0x40))
                enter_standby();
            (void)FRCOSCFREQ1;
        } while (--i);
        IE_5 = 0;
        OSCCALIB = 0x00;
    }

    /* UART0 at 38400 8N1 on PB4. uart_begin() is libmf's uart_timer0_baud()
     * + uart0_init() inlined: linking libmf's versions also links UART1's
     * ring buffers, ~86 of the 128 directly addressable bytes of internal
     * RAM, which this firmware cannot spare (see uart.c). */
    uart_begin();

    uart_puts("\r\n*** polyform demo ***\r\n");

    /* NFC chip first: it is a mode-1 SPI slave, so this bit-bangs the bus
     * and hands it back to the hardware SPI unit (mode 0) afterwards. */
    nfc_report();

    /* Then the link layer, which needs the serial: the tag's address is
     * FNV-1a/32 of it, so both ends can compute the same id without a
     * handshake and the address costs four bytes in a frame instead of the
     * whole serial. Printing it matters - a mismatch between this and the
     * access point's idea of the peer looks exactly like dead hardware.
     *
     * The id goes through a static rather than a local: an expression like
     * sk_link_init(role, sk_id_from_serial(...)) needs a temporary for the
     * 32-bit result, and main() is not __reentrant, so that temporary would
     * come out of the overlay area - which on this part has no room. */
    tag_id = sk_id_from_serial(nfc_serial_str, nfc_serial_len);
    sk_link_init(SK_TAG_ROUTER ? SK_ROLE_ROUTER : SK_ROLE_LEAF, tag_id);
    {
        uart_puts("radio: id ");
        uart_puthex8((uint8_t)(tag_id >> 24));
        uart_puthex8((uint8_t)(tag_id >> 16));
        uart_puthex8((uint8_t)(tag_id >> 8));
        uart_puthex8((uint8_t)tag_id);
        uart_puts(SK_TAG_ROUTER ? " (router)\r\n" : " (leaf)\r\n");
    }

    /* Then say hello over the radio, before spending ~20 s on the panel. */
    announce();

    /* Receiver back on straight away, even though nothing services it until
     * the refresh below is over: a BEGIN that arrives during those ~20 s now
     * at least lands in the AX5043's FIFO and is answered as soon as the loop
     * starts, instead of being missed and costing the sender a retry. */
    radio_rx_start();

    spi_init();
    epd_init_panel();
    uart_puts("panel init ok\r\n");

    /* Upload the polyform logo: black/white plane, then red plane */
    uart_puts("uploading image\r\n");
    epd_upload(0x10, epd_image_bw, EPD_PLANE_BYTES);
    epd_upload(0x13, epd_image_red, EPD_PLANE_BYTES);

    /* Refresh and wait for the panel to finish */
    uart_puts("refreshing\r\n");
    idle = EPD_BUSY;
    epd_write_cmd(0x12);
    wait_busy_change(idle, 3000);
    wait_busy_return(idle, 30000);
    uart_puts("refresh done\r\n");

    /* Panell off (keeps the image), then signal completion */
    epd_write_cmd(0x02);            /* POF */

    PIN_SET_HIGH(LEDB_PORT, LEDB_PIN);   /* blue LED: one flash */
    ms_delay(300);
    PIN_SET_LOW(LEDB_PORT, LEDB_PIN);   /* blue LED: one flash */

    /* ── receive loop ───────────────────────────────────────────────────
     * From here everything the tag does is driven by the radio. Nothing in
     * this loop blocks for longer than the panel refresh in show_image(),
     * which is deliberate: the sender is stop-and-wait, so a slow tag costs
     * a retry, while a tag that is not listening at all costs the transfer.
     *
     * A leaf starts in wake-on-radio rather than continuous receive: it is
     * only on for a fraction of each wake-up period, which is the single
     * biggest power saving available to a battery label (see radio.h). It
     * comes back to continuous receive the moment it hears anything, and
     * drops back to WOR when the conversation has been quiet for
     * LEAF_AWAKE_MS - so an image transfer pays for one wake-up, not one per
     * frame. A router stays in continuous receive: it has a supply and its
     * job is to hear everything.
     *
     * The two roles are chosen at compile time, so they are #if'd rather than
     * tested: a constant test would compile both branches and leave half of
     * them unreachable, which SDCC quite rightly warns about. */
#if SK_TAG_ROUTER
    sk_link_rx_mode(SK_RX_CONTINUOUS);
    radio_rx_start();
    uart_puts("radio: listening (router)\r\n");
#else
    sk_link_rx_mode(SK_RX_WOR);
    radio_rx_wor_start();
    uart_puts("radio: listening (leaf, wake-on-radio)\r\n");
#endif

    quiet_ms = 0;
    for (;;) {
        len = sk_link_poll(rx_pkt, sizeof rx_pkt);

        /* A frame this node forwarded (a router only - a leaf never relays).
         * Invisible without a line here, and exactly what "which way did that
         * packet go" is asked about. Checked before the delivery branch,
         * because a broadcast is delivered *and* relayed: logging it only in
         * the not-delivered path (as this did at first) hid every relay of a
         * broadcast - which is the common case, since IMG_BEGIN is one. */
        if (sk_link_relayed()) {
            uart_puts("relay msg ");
            uart_puthex8(sk_link_seq());
            uart_puts(" origin ");
            uart_puthex8((uint8_t)(sk_link_origin() >> 24));
            uart_puthex8((uint8_t)(sk_link_origin() >> 16));
            uart_puthex8((uint8_t)(sk_link_origin() >> 8));
            uart_puthex8((uint8_t)sk_link_origin());
            uart_puts(" hops ");
            uart_puthex8(sk_link_hops());
            uart_puts("->");
            uart_puthex8((uint8_t)(sk_link_hops() - 1));
            uart_puts("\r\n");
        }

        if (len) {
            quiet_ms = 0;
#if !SK_TAG_ROUTER
            /* Heard something: stay awake for the rest of the exchange, so
             * an image transfer pays for one wake-up rather than one per
             * frame. */
            if (!link_awake) {
                link_awake = 1;
                sk_link_rx_mode(SK_RX_CONTINUOUS);
                radio_rx_start();
                uart_puts("radio: awake\r\n");
            }
#endif
            handle_packet(len);
            continue;
        }

        if (sk_link_bad()) {
            /* Heard something that was not a frame: the CRC or the framing
             * did not survive the air. The distinction between "the radio is
             * hearing nothing" and "the radio is hearing rubbish" is the one
             * that says whether to look at the aerial or at the protocol, and
             * it is worth a line on the tag's console too. */
            uart_puts("radio: bad frame dropped\r\n");
        }

        ms_delay(1);                /* 1 ms between polls of the FIFO */
        quiet_ms++;

        if (rx_state == RX_RECEIVING) {
            /* The sender went away without an END. Dropping the transfer
             * keeps the tag usable - otherwise it would answer every later
             * BEGIN with SK_ST_BUSY until it was power-cycled. */
            if (quiet_ms >= RX_STALL_MS) {
                uart_puts("img: sender went quiet, transfer abandoned\r\n");
                rx_state = RX_IDLE;
                quiet_ms = 0;
            }
        } else if (quiet_ms >= IDLE_ANNOUNCE_MS) {
            /* Idle: keep saying who we are, so an access point that comes up
             * later (or missed the boot beacon) can still find this tag. */
            quiet_ms = 0;
            announce_send();
        }

#if !SK_TAG_ROUTER
        /* The conversation has gone quiet: back to sleep. A router never
         * does this - that is what makes it a router. */
        if (link_awake && quiet_ms >= LEAF_AWAKE_MS) {
            link_awake = 0;
            sk_link_rx_mode(SK_RX_WOR);
            radio_rx_wor_start();
            uart_puts("radio: idle, back to wake-on-radio\r\n");
        }
#endif
    }
}
