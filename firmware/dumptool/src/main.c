/**
 * @file main.c
 * @brief Dump every memory on the tag over UART
 *
 * Boots, brings up UART0 (38400 8N1 on PB4 - the AXSEM bootloader rate) and
 * then dumps, back to back:
 *
 *   1. the NFC chip   FM11NT081DS: 7-byte serial number, capability
 *                     container, and the whole 924-byte EEPROM
 *   2. the SPI flash  JEDEC ID plus a 128 KiB hexdump
 *   3. the MCU flash  the AX8052's own 64 KiB code space, optional
 *                     (DUMP_MCU_FLASH, off by default)
 *
 * Order matters. The NFC chip is a mode-1 SPI slave while the flash and the
 * panel sit on the hardware SPI unit, which runs mode 0 (see nfc.c), so the
 * NFC section bit-bangs the pads, prints, and hands the bus back before the
 * flash section starts.
 *
 * Every section is labelled ("--- NFC ... ---", "--- SPI flash ---") so
 * tools/memdump.py can split the capture back into binary images; the final
 * line is always "*** end of dump ***", which tools/flashdump.py looks for.
 *
 * UART0 is TX-only - its RX pin (PB5) doubles as the panel reset line - and
 * TX goes straight to the UART registers, because the prebuilt libmf.lib has
 * broken FIFO size tables in this link (they read 0x75 instead of 0x40 and
 * wedge libmf's uart0_tx() after a few bytes).
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
#include "flash.h"
#include "nfc.h"

/* Dump the AX8052's own 64 KiB code space as well. Off by default: it holds
 * the firmware you just flashed (plus the AXSEM bootloader at the top), it
 * adds ~80 s to the capture, and tools/memdump.py needs --timeout raised. */
#define DUMP_MCU_FLASH  0

#define MCU_FLASH_SIZE  0x10000UL   /* 64 KiB code space */

/* ── UART output ──────────────────────────────────────────────────────── */

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

/* Wait until everything has left the shift register (U0TXEMPTY and U0TXIDLE
 * both set - the same test the bootloader's 'R' uses). */
static void uart_flush(void)
{
    while (0x44 & (uint8_t)~U0STATUS)
        ;
}

static void uart_puthex8(uint8_t v)
{
    static const char hex[] = "0123456789ABCDEF";
    uart_putc(hex[v >> 4]);
    uart_putc(hex[v & 0x0F]);
}

static void uart_puthex24(uint32_t v)
{
    uart_puthex8((uint8_t)(v >> 16));
    uart_puthex8((uint8_t)(v >> 8));
    uart_puthex8((uint8_t)v);
}

/* ── hexdump helper ───────────────────────────────────────────────────── */

/* One line per 16 bytes:
 *   000000: 04 5A 3C EA ...  |.Z<.|
 * Short lines (the tail of the NFC EEPROM) are padded so the ASCII column
 * stays put. buf may live in data or XRAM - the pointer is generic. */
static void dump_hexline(uint32_t addr, const uint8_t *buf, uint8_t n)
{
    uint8_t i;

    uart_puthex24(addr);
    uart_puts(": ");
    for (i = 0; i < n; i++) {
        uart_puthex8(buf[i]);
        uart_putc(' ');
    }
    for (i = n; i < 16; i++)
        uart_puts("   ");
    uart_puts(" |");
    for (i = 0; i < n; i++) {
        uint8_t c = buf[i];
        uart_putc((c >= 32 && c <= 126) ? c : '.');
    }
    uart_puts("|\r\n");
}

/* ── the memories ─────────────────────────────────────────────────────── */

/* 16 bytes of scratch shared by every dump, in XRAM: an 8051 has 256 bytes
 * of internal RAM and all of it should stay available for the stack. */
static uint8_t __xdata dump_buf[16];

static void dump_nfc(void)
{
    uint8_t serial[NFC_SERIAL_LEN];
    uint8_t ok, i, n;
    uint16_t addr;

    uart_puts("--- NFC (FM11NT081DS) ---\r\n");

    nfc_init();                     /* SPI unit off, pads bit-banged */

    ok = nfc_read_serial(serial);
    uart_puts("NFC serial: ");
    for (i = 0; i < NFC_SERIAL_LEN; i++) {
        uart_puthex8(serial[i]);
        uart_putc(' ');
    }
    uart_puts(ok ? "[check bytes ok]\r\n"
                 : "[check bytes BAD - read is not trustworthy]\r\n");

    /* Capability container: E1 10 <user bytes/8> <access> for a Type 2 tag */
    nfc_read(NFC_CC_ADDR, dump_buf, 4);
    uart_puts("NFC CC: ");
    for (i = 0; i < 4; i++) {
        uart_puthex8(dump_buf[i]);
        uart_putc(' ');
    }
    uart_puts("\r\n");

    uart_puts("NFC EEPROM: 924 bytes\r\n");
    for (addr = 0; addr < NFC_EEPROM_SIZE; addr += 16) {
        n = 16;
        if (NFC_EEPROM_SIZE - addr < 16)
            n = (uint8_t)(NFC_EEPROM_SIZE - addr);   /* 924 = 57*16 + 12 */
        nfc_read(addr, dump_buf, n);
        dump_hexline(addr, dump_buf, n);
    }

    nfc_release();                  /* back to the hardware SPI unit */
    uart_puts("--- end of NFC ---\r\n");
}

static void dump_spi_flash(void)
{
    uint32_t addr;
    uint8_t id[3];

    uart_puts("--- SPI flash ---\r\n");

    spi_init();
    extflash_release_powerdown();
    extflash_read_jedec_id(id);

    uart_puts("JEDEC ID: ");
    uart_puthex8(id[0]);
    uart_putc(' ');
    uart_puthex8(id[1]);
    uart_putc(' ');
    uart_puthex8(id[2]);
    uart_puts("\r\n");

    for (addr = 0; addr < FLASH_SIZE; addr += 16) {
        extflash_read(addr, dump_buf, 16);
        dump_hexline(addr, dump_buf, 16);
    }

    uart_puts("--- end of SPI flash ---\r\n");
}

#if DUMP_MCU_FLASH
/* The AX8052 executes from flash, and MOVC reads it back - no unlock needed
 * (the lock bit only guards the debug link, not the CPU). */
static uint8_t mcu_flash_read(uint16_t addr)
{
    const uint8_t __code *p = (const uint8_t __code *)addr;
    return *p;
}

static void dump_mcu_flash(void)
{
    uint32_t addr;
    uint8_t i;

    uart_puts("--- MCU flash (AX8052 code space) ---\r\n");

    for (addr = 0; addr < MCU_FLASH_SIZE; addr += 16) {
        for (i = 0; i < 16; i++)
            dump_buf[i] = mcu_flash_read((uint16_t)(addr + i));
        dump_hexline(addr, dump_buf, 16);
    }

    uart_puts("--- end of MCU flash ---\r\n");
}
#endif /* DUMP_MCU_FLASH */

/* ── boot ─────────────────────────────────────────────────────────────── */

void main()
{
    periph_init();

    /* Power rails via the PA2/PA5 transistor lines (see pwr.h) - the flash
     * and the NFC chip need their supply before anything else happens. */
    pwr_init();
    pwr_on();

    /* Debug marker: two short LED blinks = reached main, before UART. */
    PIN_SET_LOW(LEDB_PORT, LEDB_PIN);
    delay(25000);
    PIN_SET_HIGH(LEDB_PORT, LEDB_PIN);
    delay(25000);
    PIN_SET_LOW(LEDB_PORT, LEDB_PIN);
    delay(25000);
    PIN_SET_HIGH(LEDB_PORT, LEDB_PIN);
    delay(25000);

    /* UART0 on PB4(TX) / PB5(RX) - the SAME pins the AXSEM serial
     * bootloader uses (PALTB = 0x10, PB4 output, PB5 input) and the only
     * UART pins wired to the serial converter on this tag. The dump only
     * transmits; PB5 stays configured as the bootloader leaves it. */
    PALTB |= 0x10;                  /* PB4 -> U0TX alternate function */
    DIRB  |= 0x10;                  /* PB4 = output */
    DIRB  &= (uint8_t)~0x20;        /* PB5 = input (U0RX) */
    PORTB |= 0x30;                  /* TX idle high, RX latch high */

    /* Start the 20 MHz FRC oscillator and slave it to the 32 kHz LPX
     * crystal - byte-for-byte the sequence the AXSEM serial bootloader runs
     * on this tag. Without it the FRC runs free at ~10 MHz +/-10% and the
     * UART baud rate is wrong. */
    FRCOSCREF = 19531;
    FRCOSCKFILT = 2800;
    LPXOSCGM = 0x90;
    OSCFORCERUN |= 0x04;                        /* force the FRC to run */
    FRCOSCCONFIG = (6 << 3) | CLKSRC_LPXOSC;    /* FRC slaved to LPXOSC */
    WTCFGB = (1 << 3) | CLKSRC_LPXOSC;
    {
        uint8_t i = 128;
        OSCCALIB = 0x01;
        IE_5 = 1;                               /* clock-management IRQ */
        do {
            while (!(OSCCALIB & 0x40))
                enter_standby();
            (void)FRCOSCFREQ1;                  /* feed the calibration filter */
        } while (--i);
        IE_5 = 0;
        OSCCALIB = 0x00;
    }

    uart_timer0_baud(CLKSRC_FRCOSC, 38400, 20000000);
    uart0_init(0, 8, 1);        /* enables the UART hardware; TX is driven
                                 * directly via uart_putc() (EA stays off) */

    uart_puts("\r\n*** imagotag memory dump ***\r\n");

    dump_nfc();
    dump_spi_flash();
#if DUMP_MCU_FLASH
    dump_mcu_flash();
#endif

    uart_puts("*** end of dump ***\r\n");
    uart_flush();

    /* Heartbeat: the dump is done, capturing can stop. */
    while (1) {
        PIN_SET_LOW(LEDB_PORT, LEDB_PIN);
        delay(25000);
        PIN_SET_HIGH(LEDB_PORT, LEDB_PIN);
        delay(25000);
    }
}
