/**
 * @file main.c
 * @brief ShelfKit access point: a UART <-> radio adapter for the tags
 *
 * One loop, two jobs.
 *
 * ── Idle ─────────────────────────────────────────────────────────────────
 * Listen on the AX5043 for tag announcements and print every one of them
 * over UART0 (38400 8N1 on PB4), so a host sees which shelf tags are in
 * range:
 *
 *   *** ShelfKit access point ***
 *   radio ready (silicon rev 51, PLLRANGINGA 0A PLL locked, VCOI 9B)
 *   listening: 868.300 MHz, 4800 bit/s, FSK
 *   TAG 1408F525 rssi=-42
 *   TAG 1408F525 rssi=-41
 *
 * ── Bridging ─────────────────────────────────────────────────────────────
 * A host on the serial port sends the image-transfer frames of
 * firmware/shared/include/shelfkit_proto.h
 *
 *   [0xAA][0x55][TYPE][LEN][LEN payload][CRC hi][CRC lo]
 *
 * and the access point turns each one into the matching radio packet, retries
 * it until the tag acknowledges it, and answers with the offset the tag has
 * confirmed (SK_U_ACK) or with a status (SK_U_STATUS). One host frame in, one
 * answer out: the host is never more than one block ahead of the tag's flash.
 *
 * The air protocol is in firmware/shared/include/shelfkit_proto.h; the link
 * parameters live in radio.h and must match the tag firmware.
 *
 * UART0 RX is PB5. On a *tag* board that pin is the e-paper reset line, so
 * the host -> tag direction exists only on the access point - which is
 * exactly what this board is for.
 *
 * TX goes straight to the UART registers, because the prebuilt libmf.lib in
 * this link has broken FIFO size tables and wedges libmf's own uart0_tx()
 * after a few bytes. RX does the same in the other direction: poll U0STATUS
 * bit 0 and read U0SHREG (see uart.c).
 */

#include <ax8052f143.h>
#include <libmf.h>
#include <libmfcrc.h>
#include <libmftypes.h>
#include "hal.h"
#include "board.h"
#include "pwr.h"
#include "radio.h"
#include "uart.h"
#include "shelfkit_proto.h"

/* ── UART RX pipe ───────────────────────────────────────────────────────
 *
 * The UART has one receive register, so a byte that arrives while we are not
 * looking is overwritten by the next one - and we are not looking for as long
 * as it takes to print a TAG line (~6 ms of blocking UART TX, ~25 bytes).
 * Rather than let that cost the host a whole frame, every wait for the
 * transmitter is spent draining the receiver into this ring, and the frame
 * parser reads the ring. 64 bytes: one TAG line's worth of arrival plus room
 * to spare, in XRAM because internal RAM belongs to the stack. */
#define UART_RXFIFO_SIZE 64             /* power of two, see the mask below */
#define UART_RXFIFO_MASK (UART_RXFIFO_SIZE - 1)

static uint8_t __xdata uart_rxfifo[UART_RXFIFO_SIZE];
static uint8_t uart_rxfifo_rd;
static uint8_t uart_rxfifo_wr;

/* Move whatever the receiver has into the ring. Never blocks: it stops as
 * soon as the UART has nothing more, and stops early if the ring is full
 * (that byte then stays in U0SHREG and the next one overruns it, which costs
 * one frame and is caught by the frame CRC). */
static void uart_rx_pump(void) __reentrant
{
    while (uart_rx_ready()) {
        uint8_t w = (uint8_t)((uart_rxfifo_wr + 1) & UART_RXFIFO_MASK);

        if (w == uart_rxfifo_rd)
            return;
        uart_rxfifo[uart_rxfifo_wr] = uart_getc();
        uart_rxfifo_wr = w;
    }
}

/* ── UART TX ──────────────────────────────────────────────────────────── */

static void uart_putc(uint8_t c)
{
    while (!(U0STATUS & 0x04)) {    /* wait for U0TXEMPTY */
        uart_rx_pump();             /* ... and use the time to keep RX moving */
    }
    U0SHREG = c;
    U0CTRL |= 0x08;                 /* arm the TX-done flag, like iocore */
    uart_rx_pump();
}

static void uart_puts(const char *s)
{
    while (*s)
        uart_putc((uint8_t)*s++);
}

static void uart_flush(void)
{
    while (0x44 & (uint8_t)~U0STATUS)
        uart_rx_pump();
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

/* Signed decimal, for the RSSI. RSSI is negative or zero dB. */
static void uart_putdec(int16_t v)
{
    uint16_t u;

    if (v < 0) {
        uart_putc('-');
        u = (uint16_t)(-v);
    } else {
        u = (uint16_t)v;
    }

    if (u >= 100) {
        uart_putc((uint8_t)('0' + (u / 100)));
        u = (uint16_t)(u % 100);
        uart_putc((uint8_t)('0' + (u / 10)));
    } else if (u >= 10) {
        uart_putc((uint8_t)('0' + (u / 10)));
    }
    uart_putc((uint8_t)('0' + (u % 10)));
}

/* ── state ──────────────────────────────────────────────────────────────
 *
 * The buffers are XRAM: the 128 bytes of directly addressable internal RAM
 * have to hold every other static below *and* the stack, and a packet buffer
 * is far too big for that. */

/* The host frame being assembled:
 *   [0] 0xAA  [1] 0x55  [2] TYPE  [3] LEN  [4..4+LEN-1] payload
 * and then the two CRC bytes uart_tx_frame() appends. Held whole rather than
 * streamed straight out, so a frame is never half-written when the next one
 * starts and the CRC can be taken over the same bytes that go on the wire. */
static uint8_t __xdata uart_out[6 + SK_UART_PAYLOAD_MAX];

/* The host frame as received: [0] TYPE [1] LEN [2..2+LEN-1] payload. The two
 * sync bytes are consumed by the parser's state machine, not stored. */
static uint8_t __xdata ser_buf[2 + SK_UART_PAYLOAD_MAX];

/* Radio payloads, one per direction, rebuilt for every packet. */
static uint8_t __xdata rx_pkt[SK_PKT_MAX];
static uint8_t __xdata tx_pkt[SK_PKT_MAX];

/* The image size IMG_BEGIN announced. IMG_END's answer is measured against
 * it: the tag ends its transfer at that offset, whatever it is. */
static uint16_t __xdata xfer_total;

/* A tag has taken the transfer on (IMG_ACK(off = 0) after IMG_BEGIN). */
static uint8_t xfer_active;

/* A tag's answer to IMG_DATA/IMG_BEGIN/IMG_END, or its refusal. Statics
 * rather than a struct by value: this is an 8051, and returning a struct
 * would cost a parameter block in the 128 bytes of directly addressable RAM
 * (the same reason every parameter list below is __reentrant). */
#define REPLY_NONE   0              /* nothing arrived in the window */
#define REPLY_ACK    1              /* IMG_ACK: reply_off and reply_status */
#define REPLY_STATUS 2              /* IMG_STATUS: reply_status only */

static uint16_t reply_off;
static uint8_t  reply_status;

/* Where the access point gave up, for SK_U_STATUS's detail byte. */
#define LINK_D_TIMEOUT  0           /* the tag never answered */
#define LINK_D_RADIO    1           /* radio_tx() refused the frame */
#define LINK_D_NO_XFER  2           /* IMG_DATA/IMG_END with no IMG_BEGIN */
#define LINK_D_TAG      3           /* the tag itself reported the status */

/* Retry budgets, per host frame.
 *
 * A radio round trip is a few hundred milliseconds: a 101-byte IMG_DATA
 * packet is ~180 ms on the air at 4800 bit/s, the ACK ~60 ms, and then the
 * tag writes a flash page. One wait slice below is therefore several round
 * trips' worth, and the budgets are deliberately lopsided:
 *
 *   IMG_BEGIN  4 x 1.5 s, within a 12 s budget for the answer.
 *                          The tag erases the three flash sectors of its
 *                          staging area *before* it answers IMG_BEGIN -
 *                          typically ~150 ms, up to 1 s, with a 3 s hard
 *                          timeout per sector - so 12 s is that worst case
 *                          plus margin. A second BEGIN that arrives while it
 *                          is erasing is answered SK_ST_BUSY, which means
 *                          "already on it" and is *not* a refusal: the wait
 *                          continues inside the budget instead of failing the
 *                          transfer.
 *   IMG_DATA  10 x 0.6 s  - the retry the protocol is built on: the tag
 *                          answers every data frame with the next offset it
 *                          still needs, so a lost frame is simply sent again,
 *                          and a duplicate is answered the same way without
 *                          being written. 6 s total, comfortably inside the
 *                          30 s of radio silence after which the tag abandons
 *                          a transfer by itself.
 *   IMG_END        60 s   - see link_image_end(): sent once, and then waited
 *                          for, because the answer is only sent after the tag
 *                          has flushed its last page, checked the image CRC
 *                          and driven the e-paper panel (~20 s).
 *
 * Worst case per host frame, radio_tx()'s own ~300 ms timeout included:
 * ~13 s for BEGIN, ~9 s for DATA, ~60 s for END. All bounded on purpose -
 * the host is always answered, and the access point never blocks on the
 * radio without a deadline. */
#define LINK_BEGIN_TRIES     4
#define LINK_BEGIN_WAIT_MS   1500
#define LINK_BEGIN_BUDGET_MS 12000
#define LINK_DATA_TRIES      10
#define LINK_DATA_WAIT_MS    600
#define LINK_END_WAIT_MS     60000

/* ── the serial frame CRC ───────────────────────────────────────────────
 *
 * shelfkit_proto.h defines it as CRC-16/CCITT-FALSE (poly 0x1021, init
 * 0xFFFF, MSB first, no reflection) over TYPE, LEN and the payload, and the
 * host side uses binascii.crc_hqx(data, 0xFFFF).
 *
 * libmf carries two CRC-16s whose names are one letter apart, and they are
 * *not* the same check:
 *
 *   crc_crc16_msb_byte()  indexes crc_crc16_msbtable, whose own source
 *                         comment reads "Polynomial: x^16 + x^15 + x^2 + 1
 *                         = 0x18005  MSB first"  - the Vusion MAC's CRC
 *   crc_ccitt_msb_byte()  indexes crc_ccitt_msbtable, "Polynomial: x^16 +
 *                         x^12 + x^5 + 1 = 0x11021  MSB first"
 *
 * The protocol means the second one, so that is what both directions here
 * use - one byte at a time, which also keeps every call a value, so no frame
 * buffer is ever handed to libmf's generic-pointer space decoder. The check
 * value pins it: CCITT-FALSE over "123456789" is 0x29B1, and
 * tools/tests/serial_frame_test.c asserts exactly that against the crc_*()
 * calls below. */

/* Finish the frame in uart_out: CRC over TYPE, LEN and the payload - the
 * three fields the receiver feeds to the same function, so the two ends
 * agree without a shared table - then write it out. */
static void uart_tx_frame(void) __reentrant
{
    uint8_t i, len = uart_out[3];
    uint16_t crc = 0xFFFF;

    for (i = 0; i < (uint8_t)(len + 2); i++)
        crc = crc_ccitt_msb_byte(crc, uart_out[2 + i]);

    uart_out[4 + len] = (uint8_t)(crc >> 8);
    uart_out[5 + len] = (uint8_t)crc;

    for (i = 0; i < (uint8_t)(len + 6); i++)
        uart_putc(uart_out[i]);
    uart_flush();
}

/* Start a host frame: sync, type, length. The payload follows, then
 * uart_tx_frame() closes it. */
static void host_begin(uint8_t type, uint8_t len) __reentrant
{
    uart_out[0] = SK_UART_SYNC0;
    uart_out[1] = SK_UART_SYNC1;
    uart_out[2] = type;
    uart_out[3] = len;
}

/* SK_U_ACK [off hi][off lo][status]: off is how much of the image the tag has
 * confirmed, so the host can tell "the tag has this block" from "it does
 * not" without keeping its own idea of what the air did. */
static void host_ack(uint16_t off, uint8_t status) __reentrant
{
    host_begin(SK_U_ACK, 3);
    uart_out[4] = (uint8_t)(off >> 8);
    uart_out[5] = (uint8_t)off;
    uart_out[6] = status;
    uart_tx_frame();
}

/* SK_U_STATUS [status][detail]: the access point could not deliver. The
 * detail byte is ours and says which side failed; a code the tag itself
 * reported goes out unchanged with LINK_D_TAG. */
static void host_status(uint8_t status, uint8_t detail) __reentrant
{
    host_begin(SK_U_STATUS, 2);
    uart_out[4] = status;
    uart_out[5] = detail;
    uart_tx_frame();
}

/* ── the radio side of the bridge ─────────────────────────────────────── */

/* Send one radio packet and put the receiver back on the air. radio_tx()
 * powers the chip down when it is done (radio.c), so without this the tag's
 * answer - and every later announcement - would be missed. Doing it in one
 * place also covers the radio_tx() failure path. */
static uint8_t radio_send(const uint8_t *pkt, uint8_t len) __reentrant
{
    uint8_t err = radio_tx(pkt, len);

    radio_rx_start();
    return err;
}

/* Poll the receiver for @p ms milliseconds and pick out the tag's answer.
 *
 * Polling rather than sleeping, because the answer can land at any point in
 * the window and radio_rx() is non-blocking: the packet is taken as it
 * arrives. Anything that is not an answer - another tag announcing, a frame
 * whose XOR checksum did not survive the air - is dropped and the wait
 * carries on. The loop is bounded by @p ms iterations, so neither noise nor
 * a tag that never answers can keep this here forever. */
static uint8_t radio_wait_reply(uint16_t ms) __reentrant
{
    uint8_t len, n;

    while (ms--) {
        len = radio_rx(rx_pkt, SK_PKT_MAX);
        if (!len) {
            delay(1000);            /* libmf's delay(): ~1 ms per unit */
            continue;
        }

        if (len < SK_HDR_LEN + 1)
            continue;               /* no room for a type and a checksum */
        if (rx_pkt[0] != SK_PROTO_VERSION)
            continue;
        if (sk_checksum(rx_pkt, (uint8_t)(len - 1)) != rx_pkt[len - 1])
            continue;

        if (rx_pkt[1] == SK_PKT_IMG_ACK && len >= 6) {
            /* [ver][type][off hi][off lo][status][xor] */
            reply_off = (uint16_t)(((uint16_t)rx_pkt[2] << 8) | rx_pkt[3]);
            reply_status = rx_pkt[4];
            return REPLY_ACK;
        }
        if (rx_pkt[1] == SK_PKT_IMG_STATUS) {
            /* [ver][type][slen][serial n][status][xor]: the status is the
             * byte after the serial, and the slen field is clamped to what
             * the length byte actually left, the same way report_packet()
             * treats it. Any tag's refusal is taken: it is a definite answer
             * to a transfer attempt, and the protocol carries no addressing
             * that would let us tell whose it was. */
            n = rx_pkt[2];
            if (n > (uint8_t)(len - SK_HDR_LEN - 1))
                n = (uint8_t)(len - SK_HDR_LEN - 1);
            reply_status = rx_pkt[SK_HDR_LEN + n];
            return REPLY_STATUS;
        }
        /* Not an answer: keep waiting inside the same budget. */
    }
    return REPLY_NONE;
}

/* ── the three host commands ──────────────────────────────────────────── */

/* SK_U_IMG_BEGIN [slen][serial n][total hi][total lo][crc hi][crc lo]
 *    -> IMG_BEGIN, addressed to that serial, carrying the image size and the
 *       whole-image CRC the tag checks at the end.
 * The tag answers IMG_ACK(off = 0) when it has taken the transfer on, or
 * IMG_STATUS if it will not (wrong serial, a total it does not support, a
 * flash it cannot erase). */
static void link_image_begin(void) __reentrant
{
    uint8_t n, i, t, len, reply, busy;
    uint16_t waited;

    if (ser_buf[1] < 6)
        return;                     /* no room for a serial and four fields */

    n = ser_buf[2];
    if (n > (uint8_t)(ser_buf[1] - 5))
        n = (uint8_t)(ser_buf[1] - 5);  /* trust the LEN byte, not the field */
    if (n > SK_SERIAL_MAX)
        n = SK_SERIAL_MAX;

    tx_pkt[0] = SK_PROTO_VERSION;
    tx_pkt[1] = SK_PKT_IMG_BEGIN;
    tx_pkt[2] = n;
    for (i = 0; i < n; i++)
        tx_pkt[SK_HDR_LEN + i] = ser_buf[3 + i];
    tx_pkt[SK_HDR_LEN + n]     = ser_buf[3 + n];    /* total hi */
    tx_pkt[SK_HDR_LEN + n + 1] = ser_buf[4 + n];    /* total lo */
    tx_pkt[SK_HDR_LEN + n + 2] = ser_buf[5 + n];    /* image CRC hi */
    tx_pkt[SK_HDR_LEN + n + 3] = ser_buf[6 + n];    /* image CRC lo */
    len = (uint8_t)(SK_HDR_LEN + n + 4);
    tx_pkt[len] = sk_checksum(tx_pkt, len);
    len++;

    xfer_total = (uint16_t)(((uint16_t)ser_buf[3 + n] << 8) | ser_buf[4 + n]);

    /* A new BEGIN supersedes whatever was running: the protocol allows one
     * transfer at a time, and a host that starts another has given up on the
     * first. Until the tag answers this one, there is no transfer at all. */
    xfer_active = 0;

    waited = 0;
    for (t = 0; t < LINK_BEGIN_TRIES; t++) {
        if (radio_send(tx_pkt, len)) {
            host_status(SK_ST_BAD_SERIAL, LINK_D_RADIO);
            return;
        }

        /* Wait out this attempt. SK_ST_BUSY is not a refusal to give up on:
         * the tag erases its staging sectors before it answers IMG_BEGIN, and
         * a BEGIN that arrives while it is erasing is answered SK_ST_BUSY -
         * "already on it". So once the tag has said that, keep waiting for
         * the real answer until the budget is gone instead of sending the
         * frame again; before it has, silence means the air lost the frame
         * and one retransmission is worth it. */
        busy = 0;
        for (;;) {
            reply = radio_wait_reply(LINK_BEGIN_WAIT_MS);
            waited = (uint16_t)(waited + LINK_BEGIN_WAIT_MS);
            if (waited >= LINK_BEGIN_BUDGET_MS)
                break;
            if (reply == REPLY_STATUS && reply_status == SK_ST_BUSY) {
                busy = 1;
                continue;
            }
            if (reply == REPLY_NONE && busy)
                continue;           /* still erasing; the answer is coming */
            break;
        }

        if (reply == REPLY_ACK) {
            if (reply_status != SK_ST_OK) {
                /* The tag answered with an error status: do not pretend a
                 * transfer is running. */
                host_ack(reply_off, reply_status);
                return;
            }
            if (reply_off == 0) {
                xfer_active = 1;
                host_ack(0, SK_ST_OK);
                return;
            }
            /* An ACK that does not say "ready at zero" is not an answer to
             * this packet; send it again. */
        } else if (reply == REPLY_STATUS && reply_status != SK_ST_BUSY) {
            /* Refused, and the tag said why: its reason goes through as it
             * is rather than as a guess of our own. */
            host_status(reply_status, LINK_D_TAG);
            return;
        }

        if (waited >= LINK_BEGIN_BUDGET_MS)
            break;                  /* erasing for far too long */
        /* No answer: the air or the tag lost it. Send it again. */
    }

    host_status(SK_ST_BAD_SERIAL, LINK_D_TIMEOUT);
}

/* SK_U_IMG_DATA [off hi][off lo][data k]
 *    -> IMG_DATA carrying that block at that offset.
 * The tag answers IMG_ACK(off = the next byte it still needs), so "did this
 * block arrive" is a comparison rather than a guess: while the acknowledged
 * offset is still below off + k the block goes out again. A duplicate is
 * harmless by design - the tag answers a repeat with the same offset and
 * SK_ST_OK. */
static void link_image_data(void) __reentrant
{
    uint8_t i, k, t, len, reply;
    uint16_t off, want;

    if (!xfer_active) {
        host_status(SK_ST_OFFSET, LINK_D_NO_XFER);
        return;
    }

    if (ser_buf[1] < 3)
        return;                     /* no room for an offset and a byte */
    off = (uint16_t)(((uint16_t)ser_buf[2] << 8) | ser_buf[3]);
    k = (uint8_t)(ser_buf[1] - 2);

    tx_pkt[0] = SK_PROTO_VERSION;
    tx_pkt[1] = SK_PKT_IMG_DATA;
    tx_pkt[2] = (uint8_t)(off >> 8);
    tx_pkt[3] = (uint8_t)off;
    for (i = 0; i < k; i++)
        tx_pkt[4 + i] = ser_buf[4 + i];
    len = (uint8_t)(4 + k);
    tx_pkt[len] = sk_checksum(tx_pkt, len);
    len++;

    /* The tag has this block once it reports every byte below off + k. */
    want = (uint16_t)(off + k);

    for (t = 0; t < LINK_DATA_TRIES; t++) {
        if (radio_send(tx_pkt, len)) {
            host_status(SK_ST_BAD_SERIAL, LINK_D_RADIO);
            return;
        }
        reply = radio_wait_reply(LINK_DATA_WAIT_MS);

        if (reply == REPLY_STATUS) {
            xfer_active = 0;
            host_status(reply_status, LINK_D_TAG);
            return;
        }
        if (reply == REPLY_ACK) {
            if (reply_status != SK_ST_OK) {
                /* The tag refused this one block but is still in the
                 * transfer: SK_ST_OFFSET means "you are ahead of me - the
                 * byte I need is at off" and nothing was written, so that
                 * offset is a resume point. Report it and leave the transfer
                 * open; resending the same block would only be refused
                 * again, and the host is the party that chose the offset. */
                host_ack(reply_off, reply_status);
                return;
            }
            if (reply_off >= want) {
                /* Delivered - and the offset reported may be further on than
                 * this block, if the tag had already stored part of it. */
                host_ack(reply_off, SK_ST_OK);
                return;
            }
            /* Still short of this block: the frame did not make it. Send it
             * again; the tag treats the duplicate as the same block and
             * answers without writing it twice. */
        }
        /* No answer either: the same treatment. */
    }

    /* Out of retries. The transfer stays open: the host may well want to
     * send this block again once it has looked at the link, and nothing else
     * depends on it being closed. */
    host_status(SK_ST_BAD_SERIAL, LINK_D_TIMEOUT);
}

/* SK_U_IMG_END -> IMG_END.
 *
 * The tag answers this one only after it has flushed its last flash page,
 * verified the whole image against the CRC from IMG_BEGIN and refreshed the
 * e-paper panel - ~20 s, and longer if the panel is slow (the tag firmware
 * allows its own refresh 30 s). So IMG_END is transmitted *once* and then
 * waited for: sending it again after the panel update has started could make
 * the tag display the image a second time, which is the one failure this
 * direction must not cause. A lost IMG_END therefore costs the transfer - and
 * the host is told so, rather than being left waiting - because a host that
 * knew the panel had already changed would have to start again anyway. */
static void link_image_end(void) __reentrant
{
    uint8_t reply;

    if (!xfer_active) {
        host_status(SK_ST_OFFSET, LINK_D_NO_XFER);
        return;
    }

    tx_pkt[0] = SK_PROTO_VERSION;
    tx_pkt[1] = SK_PKT_IMG_END;
    tx_pkt[2] = sk_checksum(tx_pkt, 2);     /* the XOR covers the first two */

    if (radio_send(tx_pkt, 3)) {
        host_status(SK_ST_BAD_SERIAL, LINK_D_RADIO);
        return;
    }
    reply = radio_wait_reply(LINK_END_WAIT_MS);

    if (reply == REPLY_STATUS) {
        xfer_active = 0;
        host_status(reply_status, LINK_D_TAG);
        return;
    }
    if (reply == REPLY_ACK) {
        xfer_active = 0;
        if (reply_off == xfer_total) {
            /* off = the whole image, and status = the tag's CRC verdict.
             * SK_U_ACK carries exactly those two fields, so a transfer whose
             * CRC check failed is reported honestly instead of as a success:
             * SK_ST_CRC means the tag stored every byte and did not display
             * anything. */
            host_ack(reply_off, reply_status);
            return;
        }
        /* The tag is still short of the end, so the host ended the image
         * early. Report where the tag actually got to. */
        host_ack(reply_off, SK_ST_OFFSET);
        return;
    }

    /* Nothing came back inside the panel-refresh budget. The tag gives up on
     * a transfer it has heard nothing about for 30 s, so by now there is no
     * transfer at the tag either: close this one and say so, rather than let
     * the host wait another minute for an answer that cannot come. */
    xfer_active = 0;
    host_status(SK_ST_BAD_SERIAL, LINK_D_TIMEOUT);
}

/* A complete, CRC-checked host frame has landed in ser_buf. Unknown types
 * are not answered: shelfkit_proto.h's rule is to resynchronise and say
 * nothing, and an answer to a frame we did not understand would only confuse
 * a host that is waiting for the answer to a frame we did. */
static void link_frame(void) __reentrant
{
    switch (ser_buf[0]) {
    case SK_U_IMG_BEGIN:
        link_image_begin();
        break;
    case SK_U_IMG_DATA:
        link_image_data();
        break;
    case SK_U_IMG_END:
        link_image_end();
        break;
    default:
        break;
    }
}

/* ── the serial frame parser ────────────────────────────────────────────
 *
 * Non-blocking and byte at a time, so a host that is halfway through a frame
 * never stops the access point from hearing tags. Every error - a bad CRC, a
 * LEN that could not fit the buffer, an unknown type, a byte that breaks the
 * sync - drops the parser back to hunting for 0xAA 0x55, which is the
 * resynchronisation the header specifies; a byte that is not part of a frame
 * therefore costs at most that frame. Nothing here can block or loop: each
 * call consumes exactly the bytes that have arrived and returns. */
#define SER_WANT_AA   0
#define SER_WANT_55   1
#define SER_TYPE      2
#define SER_LEN       3
#define SER_BODY      4
#define SER_CRC_HI    5
#define SER_CRC_LO    6

/* How many idle passes of this function abandon a frame that stopped
 * half-way.
 *
 * A truncated frame is otherwise invisible until its CRC finally fails, and
 * by then it has eaten the opening bytes of whatever frame the host sent
 * next - the host sends a frame as one back-to-back burst (260 us per byte
 * at 38400), so a gap in the middle of one means the rest is never coming.
 * This count is a rough tenth of a second (the loop has no timer and the
 * radio poll dominates it, so it is only good to a factor of a few), which
 * is three orders of magnitude more than the gap between two bytes of a real
 * frame and far less than any host's retry delay - so the exact value does
 * not matter, only that it sits in that window. */
#define SER_IDLE_LIMIT  20000

/* Bytes one call of serial_poll() will process. Comfortably more than the
 * longest legal frame (104 bytes), so a whole frame is normally taken in one
 * pass, and small enough that a host which streams without ever pausing
 * cannot keep the main loop away from the radio. */
#define SER_POLL_BUDGET 128

static uint8_t ser_state;
static uint8_t ser_len;
static uint8_t ser_got;
static uint8_t ser_crc_hi;
static uint16_t ser_idle;

/* A validated frame is waiting in ser_buf. */
static uint8_t serial_poll(void) __reentrant
{
    uint8_t i, budget, got = 0;
    uint16_t crc;

    for (budget = SER_POLL_BUDGET; budget; budget--) {
        uint8_t c;

        uart_rx_pump();
        if (uart_rxfifo_rd == uart_rxfifo_wr)
            break;

        c = uart_rxfifo[uart_rxfifo_rd];
        uart_rxfifo_rd = (uint8_t)((uart_rxfifo_rd + 1) & UART_RXFIFO_MASK);
        got = 1;
        ser_idle = 0;

        switch (ser_state) {
        case SER_WANT_AA:
            if (c == SK_UART_SYNC0)
                ser_state = SER_WANT_55;
            break;

        case SER_WANT_55:
            /* 0xAA 0xAA 0x55 starts a frame too: waiting through a second
             * 0xAA costs nothing and covers a host that restarted mid-sync. */
            if (c == SK_UART_SYNC1)
                ser_state = SER_TYPE;
            else if (c != SK_UART_SYNC0)
                ser_state = SER_WANT_AA;
            break;

        case SER_TYPE:
            ser_buf[0] = c;
            ser_state = SER_LEN;
            break;

        case SER_LEN:
            /* Longer than any legal frame: the rest of it could never be
             * buffered, so resync rather than read a truncated body whose
             * CRC might pass by accident. */
            if (c > SK_UART_PAYLOAD_MAX) {
                ser_state = SER_WANT_AA;
                break;
            }
            ser_buf[1] = c;
            ser_len = c;
            ser_got = 0;
            ser_state = c ? SER_BODY : SER_CRC_HI;
            break;

        case SER_BODY:
            ser_buf[2 + ser_got] = c;
            if (++ser_got == ser_len)
                ser_state = SER_CRC_HI;
            break;

        case SER_CRC_HI:
            ser_crc_hi = c;
            ser_state = SER_CRC_LO;
            break;

        default:                    /* SER_CRC_LO */
            crc = 0xFFFF;
            for (i = 0; i < (uint8_t)(ser_len + 2); i++)
                crc = crc_ccitt_msb_byte(crc, ser_buf[i]);
            ser_state = SER_WANT_AA;    /* the next frame starts from scratch */
            if (crc == (uint16_t)(((uint16_t)ser_crc_hi << 8) | c))
                return 1;
            break;
        }
    }

    /* Nothing arrived this time. If we were in the middle of a frame and the
     * line has now been quiet for long enough that the rest cannot still be
     * in flight, drop it and go back to hunting for a sync. */
    if (!got && ser_state != SER_WANT_AA && ++ser_idle > SER_IDLE_LIMIT) {
        ser_state = SER_WANT_AA;
        ser_idle = 0;
    }
    return 0;
}

/* ── reporting ────────────────────────────────────────────────────────── */

/* One accepted radio packet, while no host frame is being bridged. */
static void report_packet(const uint8_t *payload, uint8_t len, int8_t rssi)
{
    uint8_t n, i;

    if (len < SK_HDR_LEN + 1) {
        uart_puts("?? short packet (");
        uart_puthex8(len);
        uart_puts(" bytes)\r\n");
        return;
    }
    if (payload[0] != SK_PROTO_VERSION) {
        uart_puts("?? unknown protocol version ");
        uart_puthex8(payload[0]);
        uart_puts("\r\n");
        return;
    }
    if (sk_checksum(payload, (uint8_t)(len - 1)) != payload[len - 1]) {
        uart_puts("?? checksum mismatch (");
        uart_puthex8(len);
        uart_puts(" bytes, noise?)\r\n");
        return;
    }

    if (payload[1] == SK_PKT_ANNOUNCE) {
        n = payload[2];
        if (n > (uint8_t)(len - SK_HDR_LEN - 1))
            n = (uint8_t)(len - SK_HDR_LEN - 1);    /* trust the packet, not the field */

        uart_puts("TAG ");
        for (i = 0; i < n; i++) {
            uint8_t c = payload[SK_HDR_LEN + i];
            uart_putc((c >= 32 && c <= 126) ? c : '?');
        }
        uart_puts(" rssi=");
        uart_putdec(rssi);
        uart_puts("\r\n");
        uart_flush();
        return;
    }

    /* An answer to a transfer nobody is running: a tag that heard a frame the
     * air mangled, or one that answered after the host gave up. Printed
     * anyway - it is the only window into the tag's side of the protocol, and
     * exactly what is wanted while the tag firmware is being brought up. */
    if (payload[1] == SK_PKT_IMG_ACK && len >= 6) {
        uart_puts("ACK off=");
        uart_puthex16((uint16_t)(((uint16_t)payload[2] << 8) | payload[3]));
        uart_puts(" st=");
        uart_puthex8(payload[4]);
        uart_puts(" (no transfer)\r\n");
        uart_flush();
        return;
    }
    if (payload[1] == SK_PKT_IMG_STATUS) {
        n = payload[2];
        if (n > (uint8_t)(len - SK_HDR_LEN - 1))
            n = (uint8_t)(len - SK_HDR_LEN - 1);
        uart_puts("IMG_STATUS st=");
        uart_puthex8(payload[SK_HDR_LEN + n]);
        uart_puts(" (no transfer)\r\n");
        uart_flush();
        return;
    }

    uart_puts("?? unknown packet type ");
    uart_puthex8(payload[1]);
    uart_puts("\r\n");
}

/* ── boot ─────────────────────────────────────────────────────────────── */

/* How many passes of the idle loop the blue LED stays lit after a packet.
 * A countdown instead of a delay(): a blocking blink costs ~2 ms of not
 * reading the serial port, and there is a stop-and-wait host on the other end
 * of it. */
#define LED_HOLD_PASSES 40

static uint8_t led_hold;

void main()
{
    uint8_t d[RADIO_DIAG_LEN];
    uint8_t err, len;

    periph_init();

    /* Power rails via the PA2/PA5 transistor lines (see pwr.h) */
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

    /* UART0 on PB4(TX) / PB5(RX) - the AXSEM bootloader's pins. PB5 is an
     * input here: on the access point it is the host's transmit line, and
     * uart_begin() turns the receiver on. */
    PALTB |= 0x10;
    DIRB  |= 0x10;
    DIRB  &= (uint8_t)~0x20;
    PORTB |= 0x30;

    /* Start the 20 MHz FRC oscillator slaved to the 32 kHz crystal - the
     * AXSEM bootloader's sequence, needed for an exact 38400 baud. */
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

    /* UART0 at 38400 8N1 on PB4/PB5. uart_begin() is libmf's
     * uart_timer0_baud() + uart0_init() inlined: linking libmf's versions
     * drags in the buffered UART and the UART1 ring buffers, which is
     * internal RAM this part does not have to spare (see uart.c). */
    uart_begin();

    uart_puts("\r\n*** ShelfKit access point ***\r\n");

    err = radio_init();
    if (err) {
        uart_puts("radio: init failed, code ");
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

        for (;;)
            ;                       /* keep the LED dark: nothing works */
    }

    radio_diag(d);
    uart_puts("radio ready (silicon rev ");
    uart_puthex8(radio_revision());
    uart_puts(", PLLRANGINGA ");
    uart_puthex8(d[RADIO_DIAG_RANGING]);
    if (d[RADIO_DIAG_RANGING] & 0x40)
        uart_puts(" PLL locked");
    else
        uart_puts(" PLL NOT LOCKED");
    uart_puts(", VCOI ");
    uart_puthex8(d[RADIO_DIAG_VCOI]);
    uart_puts(")\r\nlistening: 868.300 MHz, 4800 bit/s, FSK\r\n");
    uart_flush();

    radio_rx_start();

    for (;;) {
        /* The serial port first: a host waiting for an answer is the only
         * thing here with a deadline, and both calls are non-blocking, so
         * tags are still heard while a frame is being assembled. */
        if (serial_poll())
            link_frame();

        len = radio_rx(rx_pkt, sizeof rx_pkt);
        if (len) {
            report_packet(rx_pkt, len, radio_rssi());
            PIN_SET_LOW(LEDB_PORT, LEDB_PIN);   /* blue LED: one packet */
            led_hold = LED_HOLD_PASSES;
        } else if (led_hold) {
            if (!--led_hold)
                PIN_SET_HIGH(LEDB_PORT, LEDB_PIN);
        }
    }
}
