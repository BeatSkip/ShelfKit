/**
 * @file main.c
 * @brief Read the NFC chip, then show the polyform logo on the e-paper
 *
 * Boots, brings up UART0 and the SPI bus, reads the NFC chip's serial
 * number and the whole NFC EEPROM and prints both over UART, then brings
 * up the e-paper display (GDEW026Z39, 2.6"), uploads the polyform boot
 * image (both black/white and red planes), refreshes the panel, powers it
 * down, and flashes the blue LED once when the refresh has finished. The
 * panel holds the image in deep sleep.
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
#include <libmfuart.h>
#include <libmfuart0.h>
#include "hal.h"
#include "board.h"
#include "pwr.h"
#include "spi.h"
#include "nfc.h"
#include "epd.h"
#include "epd_image.h"      /* epd_image_bw / epd_image_red */

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
static uint8_t __xdata nfc_serial[NFC_SERIAL_LEN];
static uint8_t __xdata nfc_buf[16];

static void nfc_report(void)
{
    uint8_t ok, i;
    uint16_t addr;

    uart_puts("\r\n--- NFC chip (FM11NT081DS) ---\r\n");

    nfc_init();                     /* bit-bang the bus, SPI unit off */

    ok = nfc_read_serial(nfc_serial);
    uart_puts("serial number (7-byte UID): ");
    for (i = 0; i < NFC_SERIAL_LEN; i++) {
        uart_puthex8(nfc_serial[i]);
        if (i + 1 < NFC_SERIAL_LEN)
            uart_putc(' ');
    }
    uart_puts(ok ? "  [check bytes ok]\r\n"
                 : "  [check bytes BAD - read is not trustworthy]\r\n");

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

/* ── start the display ────────────────────────────────────────────────── */

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

void main()
{
    uint8_t idle;

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

    uart_timer0_baud(CLKSRC_FRCOSC, 38400, 20000000);
    uart0_init(0, 8, 1);

    uart_puts("\r\n*** polyform demo ***\r\n");

    /* NFC chip first: it is a mode-1 SPI slave, so this bit-bangs the bus
     * and hands it back to the hardware SPI unit (mode 0) afterwards. */
    nfc_report();

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

    for (;;)
        ;
}