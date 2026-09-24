/**
 * @file uart.c
 * @brief Minimal UART0 bring-up - byte-for-byte what libmf does, minus the
 *        ring buffers we never use
 *
 * The functions this replaces are:
 *
 *   uart_timer0_baud(clksrc, baud, clkfreq)   libmf source uarttimer.c,
 *                                             the "other than ARM" branch
 *   uart0_init(0, 8, 1)                       libmf source uartinit.c,
 *                                             the SDCC branch
 *
 * Both are copied here faithfully, minus the FIFO index bookkeeping (all
 * output goes straight to the UART registers - see the uart_putc() in each
 * firmware's main.c) and minus IRQENA, which only matters if interrupts are
 * enabled (this firmware never sets EA).
 *
 * The baud rate comes from timer 0 in baud-generator mode: TPERIOD is the
 * divider, T0CLKSRC packs the prescaler shift into the upper bits and the
 * clock source into the lower three.
 */

#include "uart.h"
#include <libmfuart0.h>

/* The firmware runs the core from this oscillator (main() starts it). */
#define UART_CLKSRC   CLKSRC_FRCOSC
#define UART_CLK_HZ   20000000UL
#define UART_BAUD     38400UL

static void uart_set_baud(uint8_t clksrc, uint32_t baud, uint32_t clkfreq)
{
    uint8_t sh = 26;

    /* Normalise the baud rate so its most significant bit is set, counting
     * the shifts in sh - that is the prescaler the divider below needs. */
    while (sh) {
        uint8_t bdhi = (uint8_t)(baud >> 24);
        if (!bdhi && sh >= 8) {
            baud <<= 8;
            sh = (uint8_t)(sh - 8);
            continue;
        }
        if (!(bdhi & 0xF0) && sh >= 4) {
            baud <<= 4;
            sh = (uint8_t)(sh - 4);
            continue;
        }
        if (!(bdhi & 0xC0) && sh >= 2) {
            baud <<= 2;
            sh = (uint8_t)(sh - 2);
            continue;
        }
        if (!(bdhi & 0x80)) {
            baud <<= 1;
            --sh;
            continue;
        }
        break;
    }

    clkfreq >>= sh;
    baud /= clkfreq;

    /* Keep the divider inside 16 bits by halving it and dropping the
     * prescaler by another factor of 256. */
    sh = 0x38;
    while (baud >= 16384UL && (sh & 0xF0)) {
        baud >>= 1;
        sh = (uint8_t)(sh - 8);
    }

    T0CLKSRC = (uint8_t)(sh | (clksrc & 7));
    T0MODE   = 0x04;                /* baud rate generator mode */
    T0PERIOD = (uint16_t)baud;
}

void uart_begin(void)
{
    uart_set_baud(UART_CLKSRC, UART_BAUD, UART_CLK_HZ);

    /* Timer 0 generates the baud rate, 8 data bits, 1 stop bit, enable.
     * 0x07 turns the receiver on as well as the transmitter; the access
     * point is the only firmware here that reads it back. */
    U0MODE  = 0x41;
    U0CTRL  = 0x07;
}

/* ── receive ──────────────────────────────────────────────────────────────
 *
 * libmf's UART0 interrupt handler is the source for both halves of this
 * (libraries/libmf/builtsource/uart0init.c, the SDCC uart_iocore):
 *
 *     mov  a,_USTATUS
 *     jnb  acc.0,iocnorx      ; U0STATUS bit 0 = a received byte is ready
 *     ...
 *     mov  a,_USHREG         ; the byte itself is U0SHREG
 *     movx @dptr,a
 *     orl  _UCTRL,#0x04      ; re-arm the "byte arrived" flag
 *
 * and the same handler clears UCTRL bit 2 only when its ring buffer is full
 * (that is its flow control). This firmware never sets IE/EA - it has no
 * interrupt vectors at all - so it makes exactly those accesses by hand:
 * uart_rx_ready() is bit 0 of U0STATUS, reading U0SHREG takes the byte and
 * clears the bit, and re-arming keeps the next one coming. */

uint8_t uart_rx_ready(void) __reentrant
{
    return (uint8_t)(U0STATUS & 0x01);
}

uint8_t uart_getc(void) __reentrant
{
    uint8_t c = U0SHREG;

    U0CTRL |= 0x04;
    return c;
}
