/**
 * @file serial_frame_test.c
 * @brief Host test for the access point's serial frame parser and radio bridge
 *
 * The interesting half of firmware/access-point/src/main.c has no MCU
 * dependency: the host frame format, the CRC, the resynchronisation rules and
 * the bridge's timeout/retry decisions are all logic, not registers. So this
 * test compiles the *real* main.c - not a copy of it - against stub headers,
 * and drives it with a scripted serial line and a scripted tag.
 *
 * How the trick works (see ap_stubs/):
 *   - <libmftypes.h> turns __reentrant/__xdata/... into nothing, exactly as
 *     libmf's own header does for non-SDCC compilers;
 *   - U0SHREG is a function call used as an lvalue, so every byte the
 *     firmware transmits lands in this test's capture buffer;
 *   - delay() advances a virtual clock, which is what makes the retry budgets
 *     assertable ("the END wait was 60 s and IMG_END went out exactly once");
 *   - radio_tx()/radio_rx() are a scripted tag: the test queues the answers it
 *     wants, with the virtual time each arrives at.
 *
 * Build and run (from the repository root):
 *
 *   gcc -Wall -Wextra -Wno-unused-function -Wno-unused-parameter \
 *       -I tools/tests/ap_stubs -I firmware/shared/include \
 *       -o tools/tests/serial_frame_test.exe tools/tests/serial_frame_test.c
 *   ./tools/tests/serial_frame_test.exe
 *
 * (-I firmware/shared/include because main.c includes shelfkit_proto.h the
 * same way the SDCC build does.)
 *
 * What it cannot prove: crc_ccitt_msb_byte() here is a from-scratch
 * implementation of the same algorithm, not libmf's 8051 assembly. The test
 * pins the *algorithm and the wire bytes* (including the published check value
 * 0x29B1 for "123456789"), and reads the polynomial straight out of libmf's
 * crc_ccitt_msbtable source comment; only hardware can confirm that the
 * linked assembly agrees.
 */

#include <stdio.h>
#include <string.h>
#include <stdint.h>

/* The firmware's own headers first, so every stub below is checked against
 * the declaration the firmware actually sees. */
#include "../../firmware/access-point/src/radio.h"
#include "../../firmware/access-point/src/uart.h"
#include "../../firmware/access-point/src/board.h"
#include "../../firmware/access-point/src/hal.h"
#include "../../firmware/shared/include/shelfkit_proto.h"

/* ── the virtual world ────────────────────────────────────────────────── */

#define FEED_MAX 65536

/* Bytes the host has sent, in arrival order. */
static uint8_t rx_feed[FEED_MAX];
static size_t  rx_feed_len;
static size_t  rx_feed_pos;

/* Everything the access point has transmitted. */
static uint8_t tx_capture[FEED_MAX];
static size_t  tx_capture_len;
static size_t  frame_pos;               /* start of the frame not yet checked */

/* Bytes that arrive while the access point is transmitting: one is injected
 * per byte it sends. This is the situation the RX ring in main.c exists for. */
static uint8_t tx_inject[SK_UART_PAYLOAD_MAX + 8];
static size_t  tx_inject_len;
static size_t  tx_inject_pos;

static uint32_t virtual_ms;
static unsigned radio_tx_calls, radio_rx_start_calls, radio_rx_calls;
static uint8_t  radio_tx_fail;

uint16_t ap_sfr[12];
uint8_t  u0_status = 0xFF;      /* TX always empty, so uart_putc never waits */
uint8_t  u0_ctrl;
uint8_t  ap_ie_5;

uint8_t *ap_tx_slot(void)
{
    if (tx_inject_pos < tx_inject_len)
        rx_feed[rx_feed_len++] = tx_inject[tx_inject_pos++];
    return &tx_capture[tx_capture_len++];
}

void delay(uint16_t us) { virtual_ms += us / 1000; }
void enter_standby(void) { }

uint8_t uart_rx_ready(void) { return (uint8_t)(rx_feed_pos < rx_feed_len); }
uint8_t uart_getc(void) { return rx_feed[rx_feed_pos++]; }
void uart_begin(void) { }

/* ── CRC: the reference implementation the firmware is checked against ── */

/* CRC-16/CCITT-FALSE, written the long way: poly 0x1021, init 0xFFFF, MSB
 * first, no reflection. Independent of the table-driven form libmf uses. */
static uint16_t crc_ccitt_ref(uint16_t crc, uint8_t c)
{
    int i;

    crc ^= (uint16_t)((uint16_t)c << 8);
    for (i = 0; i < 8; i++) {
        if (crc & 0x8000)
            crc = (uint16_t)((crc << 1) ^ 0x1021);
        else
            crc = (uint16_t)(crc << 1);
    }
    return crc;
}

/* The same thing as libmf's crc_ccitt_msb_byte() is written: a 256-entry
 * table indexed by the top byte of the CRC xored with the data byte. */
static uint16_t ccitt_table[256];

static void ccitt_table_init(void)
{
    int i;

    for (i = 0; i < 256; i++)
        ccitt_table[i] = crc_ccitt_ref(0x0000, (uint8_t)i);
}

uint16_t crc_ccitt_msb_byte(uint16_t crc, uint8_t c)
{
    return (uint16_t)((crc << 8) ^ ccitt_table[((crc >> 8) ^ c) & 0xFF]);
}

uint16_t crc_ccitt_msb(const uint8_t *buf, uint16_t buflen, uint16_t crc)
{
    while (buflen--)
        crc = crc_ccitt_msb_byte(crc, *buf++);
    return crc;
}

/* libmf's *other* CRC-16, poly 0x8005 - the one crc_crc16_msb() computes and
 * the protocol does not use. Only here to make the difference visible. */
uint16_t crc_crc16_msb_byte(uint16_t crc, uint8_t c)
{
    uint16_t poly = 0x8005;
    int i;

    crc ^= (uint16_t)((uint16_t)c << 8);
    for (i = 0; i < 8; i++) {
        if (crc & 0x8000)
            crc = (uint16_t)((crc << 1) ^ poly);
        else
            crc = (uint16_t)(crc << 1);
    }
    return crc;
}

static uint8_t xor8(const uint8_t *buf, uint8_t len)
{
    uint8_t x = 0, i;

    for (i = 0; i < len; i++)
        x ^= buf[i];
    return x;
}

uint8_t sk_checksum(const uint8_t *buf, uint8_t len) { return xor8(buf, len); }

/* ── the scripted tag ─────────────────────────────────────────────────── */

#define AIR_MAX 64

static uint8_t  air[AIR_MAX][SK_PKT_MAX];
static uint8_t  air_len[AIR_MAX];
static uint32_t air_at[AIR_MAX];
static int      air_head, air_tail;

#define TX_LOG_MAX 64
static uint8_t tx_log[TX_LOG_MAX][SK_PKT_MAX];
static uint8_t tx_log_len[TX_LOG_MAX];
static int     tx_log_n;

static void air_push(uint16_t delay_ms, const uint8_t *payload, uint8_t len)
{
    if (air_tail >= AIR_MAX) {
        printf("      (air queue full)\n");
        return;
    }
    memcpy(air[air_tail], payload, len);
    air_len[air_tail] = len;
    air_at[air_tail] = virtual_ms + delay_ms;
    air_tail++;
}

static void tag_reply_ack(uint16_t delay_ms, uint16_t off, uint8_t status)
{
    uint8_t p[6];

    p[0] = SK_PROTO_VERSION;
    p[1] = SK_PKT_IMG_ACK;
    p[2] = (uint8_t)(off >> 8);
    p[3] = (uint8_t)off;
    p[4] = status;
    p[5] = xor8(p, 5);
    air_push(delay_ms, p, 6);
}

static void tag_reply_status(uint16_t delay_ms, const char *serial, uint8_t status)
{
    uint8_t p[SK_PKT_MAX];
    uint8_t n = (uint8_t)strlen(serial);
    uint8_t i;

    p[0] = SK_PROTO_VERSION;
    p[1] = SK_PKT_IMG_STATUS;
    p[2] = n;
    for (i = 0; i < n; i++)
        p[SK_HDR_LEN + i] = (uint8_t)serial[i];
    p[SK_HDR_LEN + n] = status;
    p[SK_HDR_LEN + n + 1] = xor8(p, (uint8_t)(SK_HDR_LEN + n + 1));
    air_push(delay_ms, p, (uint8_t)(SK_HDR_LEN + n + 2));
}

static void tag_announce(uint16_t delay_ms, const char *serial)
{
    uint8_t p[SK_PKT_MAX];
    uint8_t n = (uint8_t)strlen(serial);
    uint8_t i;

    p[0] = SK_PROTO_VERSION;
    p[1] = SK_PKT_ANNOUNCE;
    p[2] = n;
    for (i = 0; i < n; i++)
        p[SK_HDR_LEN + i] = (uint8_t)serial[i];
    p[SK_HDR_LEN + n] = xor8(p, (uint8_t)(SK_HDR_LEN + n));
    air_push(delay_ms, p, (uint8_t)(SK_HDR_LEN + n + 1));
}

uint8_t radio_init(void) { return RADIO_OK; }
const char *radio_error_str(uint8_t err) { (void)err; return "stub"; }
void radio_diag(uint8_t *out) { memset(out, 0, RADIO_DIAG_LEN); }
uint8_t radio_revision(void) { return 0x51; }
int8_t radio_rssi(void) { return -42; }
void radio_rx_start(void) { radio_rx_start_calls++; }
void radio_rx_stop(void) { }
void periph_init(void) { }
void pwr_init(void) { }
void pwr_on(void) { }
void pwr_off(void) { }

uint8_t radio_tx(const uint8_t *payload, uint8_t len)
{
    radio_tx_calls++;
    if (radio_tx_fail)
        return RADIO_ERR_TX_FIFO;
    if (tx_log_n < TX_LOG_MAX) {
        memcpy(tx_log[tx_log_n], payload, len);
        tx_log_len[tx_log_n] = len;
        tx_log_n++;
    }
    return RADIO_OK;
}

uint8_t radio_rx(uint8_t *payload, uint8_t maxlen)
{
    uint8_t n;

    radio_rx_calls++;
    if (air_head == air_tail)
        return 0;
    if (virtual_ms < air_at[air_head])
        return 0;
    n = air_len[air_head];
    if (n > maxlen)
        n = maxlen;
    memcpy(payload, air[air_head], n);
    air_head++;
    return n;
}

/* ── the firmware under test ──────────────────────────────────────────── */

/* main.c defines main(); rename it so this file can have its own. */
#define main ap_main
#include "../../firmware/access-point/src/main.c"
#undef main

/* ── harness ──────────────────────────────────────────────────────────── */

static int failures, checks;

#define CHECK(cond, ...)                                        \
    do {                                                        \
        checks++;                                               \
        if (!(cond)) {                                          \
            failures++;                                         \
            printf("FAIL %d: ", __LINE__);                      \
            printf(__VA_ARGS__);                                \
            printf("\n");                                       \
        }                                                       \
    } while (0)

static void reset_world(void)
{
    rx_feed_len = rx_feed_pos = 0;
    tx_capture_len = frame_pos = 0;
    tx_inject_len = tx_inject_pos = 0;
    virtual_ms = 0;
    radio_tx_calls = radio_rx_start_calls = radio_rx_calls = 0;
    radio_tx_fail = 0;
    air_head = air_tail = 0;
    tx_log_n = 0;

    uart_rxfifo_rd = uart_rxfifo_wr = 0;
    ser_state = SER_WANT_AA;
    ser_len = ser_got = ser_crc_hi = 0;
    ser_idle = 0;
    xfer_active = 0;
    xfer_total = 0;
    reply_off = 0;
    reply_status = 0;
}

static void feed(const uint8_t *b, size_t n)
{
    memcpy(rx_feed + rx_feed_len, b, n);
    rx_feed_len += n;
}

static void build_frame(uint8_t *out, uint8_t type, const uint8_t *payload, uint8_t len)
{
    uint16_t crc = 0xFFFF;
    uint8_t i;

    out[0] = SK_UART_SYNC0;
    out[1] = SK_UART_SYNC1;
    out[2] = type;
    out[3] = len;
    crc = crc_ccitt_msb_byte(crc, type);
    crc = crc_ccitt_msb_byte(crc, len);
    for (i = 0; i < len; i++) {
        out[4 + i] = payload[i];
        crc = crc_ccitt_msb_byte(crc, payload[i]);
    }
    out[4 + len] = (uint8_t)(crc >> 8);
    out[5 + len] = (uint8_t)crc;
}

static void feed_frame(uint8_t type, const uint8_t *payload, uint8_t len)
{
    uint8_t f[2 + 2 + SK_UART_PAYLOAD_MAX + 2];

    build_frame(f, type, payload, len);
    feed(f, (size_t)(len + 6));
}

/* The firmware's main loop body, minus the radio: poll the parser and hand
 * every complete frame to the bridge. serial_poll() returns non-zero only
 * for an accepted frame and handles at most SER_POLL_BUDGET bytes per call,
 * so this keeps calling it until the line and the ring are dry - which is
 * what the real main loop does, just faster. */
static int run_pending(void)
{
    int served = 0;
    long guard = 0;

    do {
        if (serial_poll()) {
            link_frame();
            served++;
        }
    } while ((uart_rxfifo_rd != uart_rxfifo_wr || uart_rx_ready()) && ++guard < 1000000);

    return served;
}

/* Ignore anything emitted so far: the next host frame is checked from here. */
static void mark_tx(void)
{
    frame_pos = tx_capture_len;
}

/* Check that the bytes emitted since the last call are exactly one host
 * frame, CRC and all, and hand back its type/len/payload. */
static int take_host_frame(uint8_t *type, uint8_t *len, uint8_t *out)
{
    size_t n = tx_capture_len - frame_pos;
    uint16_t crc = 0xFFFF, want;
    uint8_t i, l;

    if (n < 6) {
        printf("      (only %u bytes emitted, no frame)\n", (unsigned)n);
        return 0;
    }
    if (tx_capture[frame_pos] != SK_UART_SYNC0 || tx_capture[frame_pos + 1] != SK_UART_SYNC1) {
        printf("      (no 0xAA 0x55 at the start of the emitted bytes)\n");
        return 0;
    }
    l = tx_capture[frame_pos + 3];
    if (n != (size_t)(l + 6)) {
        printf("      (frame says %u bytes, %u were emitted)\n", l + 6, (unsigned)n);
        return 0;
    }
    for (i = 0; i < (uint8_t)(l + 2); i++)
        crc = crc_ccitt_msb_byte(crc, tx_capture[frame_pos + 2 + i]);
    want = (uint16_t)(((uint16_t)tx_capture[frame_pos + 4 + l] << 8) |
                      tx_capture[frame_pos + 5 + l]);
    if (crc != want) {
        printf("      (frame CRC %04X, computed %04X)\n", want, crc);
        return 0;
    }
    *type = tx_capture[frame_pos + 2];
    *len = l;
    for (i = 0; i < l; i++)
        out[i] = tx_capture[frame_pos + 4 + i];
    frame_pos += (size_t)(l + 6);
    return 1;
}

static void expect_ack(uint16_t off, uint8_t status)
{
    uint8_t type = 0, len = 0, p[SK_UART_PAYLOAD_MAX];

    checks++;
    if (!take_host_frame(&type, &len, p)) {
        failures++;
        printf("FAIL no well-formed host frame (wanted ACK off=%u st=%u)\n", off, status);
        return;
    }
    if (type != SK_U_ACK || len != 3 ||
        p[0] != (uint8_t)(off >> 8) || p[1] != (uint8_t)off || p[2] != status) {
        failures++;
        printf("FAIL wanted ACK off=%u st=%u, got type=%02X len=%u payload=%02X %02X %02X\n",
               off, status, type, len, p[0], p[1], p[2]);
    }
}

static void expect_status(uint8_t status, uint8_t detail)
{
    uint8_t type = 0, len = 0, p[SK_UART_PAYLOAD_MAX];

    checks++;
    if (!take_host_frame(&type, &len, p)) {
        failures++;
        printf("FAIL no well-formed host frame (wanted STATUS st=%u d=%u)\n", status, detail);
        return;
    }
    if (type != SK_U_STATUS || len != 2 || p[0] != status || p[1] != detail) {
        failures++;
        printf("FAIL wanted STATUS st=%u d=%u, got type=%02X len=%u payload=%02X %02X\n",
               status, detail, type, len, p[0], p[1]);
    }
}

static void expect_no_frame(void)
{
    checks++;
    if (tx_capture_len != frame_pos) {
        failures++;
        printf("FAIL expected no host answer, %u bytes were emitted\n",
               (unsigned)(tx_capture_len - frame_pos));
    }
}

/* ── host frames the test sends ───────────────────────────────────────── */

static void host_begin_cmd(uint16_t total, uint16_t image_crc)
{
    uint8_t p[1 + 8 + 4];
    const char *sn = "1408F525";
    uint8_t i;

    p[0] = 8;
    for (i = 0; i < 8; i++)
        p[1 + i] = (uint8_t)sn[i];
    p[9] = (uint8_t)(total >> 8);
    p[10] = (uint8_t)total;
    p[11] = (uint8_t)(image_crc >> 8);
    p[12] = (uint8_t)image_crc;
    feed_frame(SK_U_IMG_BEGIN, p, 13);
}

static void host_data_cmd(uint16_t off, uint8_t first, uint8_t k)
{
    uint8_t p[2 + SK_IMG_DATA_MAX];
    uint8_t i;

    p[0] = (uint8_t)(off >> 8);
    p[1] = (uint8_t)off;
    for (i = 0; i < k; i++)
        p[2 + i] = (uint8_t)(first + i);
    feed_frame(SK_U_IMG_DATA, p, (uint8_t)(2 + k));
}

static void host_end_cmd(void)
{
    feed_frame(SK_U_IMG_END, NULL, 0);
}

/* ── 1. the CRC ───────────────────────────────────────────────────────── */

static void test_crc_vectors(void)
{
    static const uint8_t digits[] = "123456789";
    uint8_t buf[64];
    uint16_t a, b;
    int i;

    printf("-- CRC-16/CCITT-FALSE\n");
    ccitt_table_init();

    /* The published check value for CRC-16/CCITT-FALSE. */
    a = 0xFFFF;
    for (i = 0; i < 9; i++)
        a = crc_ccitt_ref(a, digits[i]);
    CHECK(a == 0x29B1, "bitwise CCITT-FALSE(\"123456789\") = %04X, wanted 29B1", a);

    /* The table-driven form libmf's assembly implements must agree with it,
     * because that is what the firmware actually calls. */
    b = crc_ccitt_msb(digits, 9, 0xFFFF);
    CHECK(b == 0x29B1, "crc_ccitt_msb(\"123456789\") = %04X, wanted 29B1", b);

    for (i = 0; i < 64; i++)
        buf[i] = (uint8_t)(i * 7 + 1);
    a = 0xFFFF;
    for (i = 0; i < 64; i++)
        a = crc_ccitt_ref(a, buf[i]);
    b = crc_ccitt_msb(buf, 64, 0xFFFF);
    CHECK(a == b, "table form disagrees with the bitwise form on 64 bytes: %04X vs %04X", a, b);

    /* And the trap: libmf's crc_crc16_msb() is a *different* CRC-16 (poly
     * 0x8005). If the firmware had used it, the host would have rejected
     * every frame - and this is what the number would have been. */
    a = 0xFFFF;
    for (i = 0; i < 9; i++)
        a = crc_crc16_msb_byte(a, digits[i]);
    CHECK(a == 0xAEE7, "poly-0x8005 MSB-first check value = %04X, wanted AEE7", a);
    CHECK(a != 0x29B1, "the two libmf CRC-16s must not be conflated");
}

/* ── 2. the parser ────────────────────────────────────────────────────── */

static void test_parser_byte_at_a_time(void)
{
    uint8_t f[2 + 2 + SK_UART_PAYLOAD_MAX + 2];
    uint8_t p[1 + 8 + 4];
    const char *sn = "1408F525";
    uint8_t i, n;
    int accepted = 0;

    printf("-- a frame split into bytes is accepted only on its last byte\n");
    reset_world();

    p[0] = 8;
    for (i = 0; i < 8; i++)
        p[1 + i] = (uint8_t)sn[i];
    p[9] = 0x2B; p[10] = 0xF0; p[11] = 0x12; p[12] = 0x34;
    build_frame(f, SK_U_IMG_BEGIN, p, 13);
    n = (uint8_t)(13 + 6);

    for (i = 0; i < n; i++) {
        feed(&f[i], 1);
        if (serial_poll()) {
            accepted++;
            CHECK(i == n - 1, "the frame was accepted at byte %u of %u", i + 1, n);
        }
    }
    CHECK(accepted == 1, "the frame was accepted %d times, wanted 1", accepted);
    CHECK(ser_buf[0] == SK_U_IMG_BEGIN, "type = %02X", ser_buf[0]);
    CHECK(ser_buf[1] == 13, "len = %u", ser_buf[1]);
    CHECK(memcmp(ser_buf + 2, p, 13) == 0, "payload differs from what was sent");

    /* Two frames in one feed: both have to come out, in order. */
    reset_world();
    feed_frame(SK_U_IMG_END, NULL, 0);
    feed_frame(SK_U_IMG_END, NULL, 0);
    CHECK(run_pending() == 2, "two frames in one feed should both be served");
}

static void test_junk_before_frame(void)
{
    uint8_t junk[] = { 0x00, 0xFF, 0x55, 0xAA, 0x13, 0x01, 0x00 };
    uint8_t p[2];

    printf("-- junk, then a good frame\n");
    reset_world();
    feed(junk, sizeof junk);

    p[0] = 0x00; p[1] = 0x00;
    feed_frame(SK_U_IMG_DATA, p, 2);        /* refused, but it must be *seen* */
    CHECK(run_pending() == 1, "the good frame after junk was not parsed");
    expect_status(SK_ST_OFFSET, LINK_D_NO_XFER);
}

static void test_bad_crc_then_valid(void)
{
    uint8_t f[2 + 2 + SK_UART_PAYLOAD_MAX + 2];
    uint8_t p[2];

    printf("-- a frame with a bad CRC, then a good one\n");
    reset_world();
    build_frame(f, SK_U_IMG_DATA, (const uint8_t *)"\x00\x00", 2);
    f[4] ^= 0xFF;                           /* corrupt one payload byte */
    feed(f, 2 + 2 + 2 + 2);
    CHECK(serial_poll() == 0, "a frame with a bad CRC was accepted");

    p[0] = 0; p[1] = 0;
    feed_frame(SK_U_IMG_DATA, p, 2);
    CHECK(run_pending() == 1, "the good frame after a bad CRC was not parsed");
    expect_status(SK_ST_OFFSET, LINK_D_NO_XFER);
    expect_no_frame();
}

static void test_overlong_len(void)
{
    uint8_t f[4];
    uint8_t p[2];

    printf("-- a LEN longer than any legal frame\n");
    reset_world();
    f[0] = SK_UART_SYNC0;
    f[1] = SK_UART_SYNC1;
    f[2] = SK_U_IMG_DATA;
    f[3] = SK_UART_PAYLOAD_MAX + 1;         /* 99: impossible */
    feed(f, 4);
    CHECK(serial_poll() == 0, "an over-long LEN was accepted");

    /* ... and the parser is immediately back in sync, with no delay at all */
    p[0] = 0; p[1] = 0;
    feed_frame(SK_U_IMG_DATA, p, 2);
    CHECK(run_pending() == 1, "the frame after an over-long LEN was not parsed");
}

static void test_truncated_frame_then_valid(void)
{
    uint8_t f[6];
    uint8_t p[2];
    int i;

    printf("-- a frame that stops half-way does not swallow the next one\n");
    reset_world();

    /* A BEGIN whose LEN claims 13 payload bytes, of which only four arrive. */
    f[0] = SK_UART_SYNC0;
    f[1] = SK_UART_SYNC1;
    f[2] = SK_U_IMG_BEGIN;
    f[3] = 13;
    f[4] = 8; f[5] = 0x31;
    feed(f, 6);
    CHECK(serial_poll() == 0, "a truncated frame was accepted");

    /* The host gave up; the line goes quiet. The parser has to let go of the
     * half-frame after its idle limit, or the next frame is eaten. */
    for (i = 0; i < SER_IDLE_LIMIT + 2; i++)
        (void)serial_poll();
    CHECK(ser_state == SER_WANT_AA, "the parser did not drop the half-frame");

    p[0] = 0; p[1] = 0;
    feed_frame(SK_U_IMG_DATA, p, 2);
    CHECK(run_pending() == 1, "the frame after a truncated one was not parsed");
}

static void test_unknown_type_is_silent(void)
{
    uint8_t p[3];
    uint8_t f[2 + 2 + SK_UART_PAYLOAD_MAX + 2];

    printf("-- an unknown type resynchronises without an answer\n");
    reset_world();

    /* A CRC-valid frame of a type the access point does not know: the header
     * says resynchronise and say nothing. The parser hands it up - it has no
     * business knowing the command set - and the bridge drops it. */
    p[0] = 1; p[1] = 2; p[2] = 3;
    build_frame(f, 0x77, p, 3);
    feed(f, 3 + 6);
    (void)run_pending();
    CHECK(radio_tx_calls == 0, "an unknown type went out on the air");
    expect_no_frame();

    p[0] = 0; p[1] = 0;
    feed_frame(SK_U_IMG_DATA, p, 2);
    CHECK(run_pending() == 1, "the frame after an unknown type was not parsed");
    expect_status(SK_ST_OFFSET, LINK_D_NO_XFER);
}

static void test_payload_may_contain_sync(void)
{
    uint8_t p[2 + 4];

    printf("-- 0xAA 0x55 inside a payload is data, not a new frame\n");
    reset_world();
    xfer_active = 1;                        /* pretend BEGIN was accepted */
    xfer_total = SK_IMG_TOTAL_BYTES;

    p[0] = 0x00; p[1] = 0x60;
    p[2] = 0xAA; p[3] = 0x55; p[4] = 0xAA; p[5] = 0x55;
    tag_reply_ack(10, 0x0064, SK_ST_OK);
    feed_frame(SK_U_IMG_DATA, p, 6);
    CHECK(run_pending() == 1, "a DATA frame holding AA 55 was not parsed");
    CHECK(radio_tx_calls == 1, "expected one IMG_DATA, got %u", radio_tx_calls);
    CHECK(tx_log_len[0] == 9, "IMG_DATA length = %u, wanted 9", tx_log_len[0]);
    CHECK(tx_log[0][4] == 0xAA && tx_log[0][5] == 0x55 &&
          tx_log[0][6] == 0xAA && tx_log[0][7] == 0x55,
          "the data bytes were not carried through unchanged");
    expect_ack(0x0064, SK_ST_OK);
}

static void test_garbage_flood(void)
{
    /* A pattern that never contains 0xAA 0x55, so no false frame can pass a
     * CRC by accident and the test stays deterministic. */
    static const uint8_t pattern[4] = { 0x00, 0xAA, 0x13, 0x55 };
    uint8_t p[2];
    int i;

    printf("-- %d bytes of junk, then a good frame\n", 4 * 2000);
    reset_world();
    for (i = 0; i < 2000; i++)
        feed(pattern, 4);

    CHECK(run_pending() == 0, "junk produced a frame");
    CHECK(uart_rxfifo_rd == uart_rxfifo_wr, "the parser did not drain the ring");
    CHECK(ser_state == SER_WANT_AA, "the parser is stuck in state %u", ser_state);

    p[0] = 0; p[1] = 0;
    feed_frame(SK_U_IMG_DATA, p, 2);
    CHECK(run_pending() == 1, "the frame after the junk was not parsed");
}

static void test_rx_ring_survives_a_transmit(void)
{
    uint8_t p[1 + 8 + 4];
    uint8_t announce[3 + 8 + 1];
    uint8_t f[2 + 2 + SK_UART_PAYLOAD_MAX + 2];
    const char *sn = "1408F525";
    uint8_t i;

    printf("-- a frame that arrives during a TAG print is not lost\n");
    reset_world();

    /* The incoming frame: a whole BEGIN, delivered one byte per byte the
     * access point transmits while printing an announcement. */
    p[0] = 8;
    for (i = 0; i < 8; i++)
        p[1 + i] = (uint8_t)sn[i];
    p[9] = 0x2B; p[10] = 0xF0; p[11] = 0x00; p[12] = 0x00;
    build_frame(f, SK_U_IMG_BEGIN, p, 13);
    memcpy(tx_inject, f, 19);
    tx_inject_len = 19;
    tx_inject_pos = 0;

    /* The announcement the access point prints - 25 bytes of blocking TX. */
    announce[0] = SK_PROTO_VERSION;
    announce[1] = SK_PKT_ANNOUNCE;
    announce[2] = 8;
    for (i = 0; i < 8; i++)
        announce[3 + i] = (uint8_t)sn[i];
    announce[11] = xor8(announce, 11);

    report_packet(announce, 12, -42);
    CHECK(tx_inject_pos == tx_inject_len, "only %u of %u bytes arrived during the TX",
          (unsigned)tx_inject_pos, (unsigned)tx_inject_len);
    mark_tx();                              /* the TAG line is not a host frame */

    tag_reply_ack(10, 0, SK_ST_OK);
    CHECK(run_pending() == 1, "the frame that arrived during the TX was lost");
    CHECK(radio_tx_calls == 1, "expected one IMG_BEGIN, got %u", radio_tx_calls);
    expect_ack(0, SK_ST_OK);
}

/* ── 3. the bridge ────────────────────────────────────────────────────── */

static void test_begin_ok(void)
{
    uint32_t t0;

    printf("-- IMG_BEGIN accepted\n");
    reset_world();
    t0 = virtual_ms;
    tag_reply_ack(300, 0, SK_ST_OK);
    host_begin_cmd(SK_IMG_TOTAL_BYTES, 0x1234);

    CHECK(run_pending() == 1, "the BEGIN frame was not parsed");
    CHECK(radio_tx_calls == 1, "IMG_BEGIN went out %u times, wanted 1", radio_tx_calls);
    CHECK(tx_log_len[0] == 16, "IMG_BEGIN length = %u, wanted 16", tx_log_len[0]);
    CHECK(tx_log[0][0] == SK_PROTO_VERSION && tx_log[0][1] == SK_PKT_IMG_BEGIN,
          "packet type = %02X %02X", tx_log[0][0], tx_log[0][1]);
    CHECK(tx_log[0][2] == 8, "serial length = %u", tx_log[0][2]);
    CHECK(memcmp(tx_log[0] + 3, "1408F525", 8) == 0, "serial differs");
    CHECK(tx_log[0][11] == 0x2B && tx_log[0][12] == 0xF0,
          "total = %02X%02X, wanted 2BF0", tx_log[0][11], tx_log[0][12]);
    CHECK(tx_log[0][13] == 0x12 && tx_log[0][14] == 0x34,
          "the image CRC was not passed through: %02X%02X", tx_log[0][13], tx_log[0][14]);
    CHECK(tx_log[0][15] == xor8(tx_log[0], 15), "the radio XOR checksum is wrong");

    CHECK(xfer_active == 1, "the transfer is not marked live");
    CHECK(xfer_total == SK_IMG_TOTAL_BYTES, "total recorded as %u", xfer_total);
    CHECK(radio_rx_start_calls == 1, "the receiver was not put back on the air");
    CHECK(radio_tx_calls == radio_rx_start_calls, "TX and back-to-RX counts disagree");
    CHECK(virtual_ms - t0 < 5000, "a reply 300 ms away took %u ms", virtual_ms - t0);
    expect_ack(0, SK_ST_OK);
}

static void test_begin_retries_then_gives_up(void)
{
    uint32_t t0;

    printf("-- IMG_BEGIN with no tag in range\n");
    reset_world();
    t0 = virtual_ms;
    host_begin_cmd(SK_IMG_TOTAL_BYTES, 0);

    CHECK(run_pending() == 1, "the BEGIN frame was not parsed");
    CHECK(radio_tx_calls == LINK_BEGIN_TRIES, "IMG_BEGIN went out %u times, wanted %u",
          radio_tx_calls, LINK_BEGIN_TRIES);
    CHECK(virtual_ms - t0 == (uint32_t)LINK_BEGIN_TRIES * LINK_BEGIN_WAIT_MS,
          "the wait was %u ms, wanted %u", virtual_ms - t0,
          LINK_BEGIN_TRIES * LINK_BEGIN_WAIT_MS);
    CHECK(xfer_active == 0, "there is no transfer to be active");
    expect_status(SK_ST_BAD_SERIAL, LINK_D_TIMEOUT);
}

static void test_begin_late_answer(void)
{
    printf("-- IMG_BEGIN answered on the third try\n");
    reset_world();
    /* The first two transmissions are lost: the tag only hears the third. */
    tag_reply_ack(LINK_BEGIN_WAIT_MS * 2 + 100, 0, SK_ST_OK);
    host_begin_cmd(SK_IMG_TOTAL_BYTES, 0);
    CHECK(run_pending() == 1, "the BEGIN frame was not parsed");
    CHECK(radio_tx_calls == 3, "IMG_BEGIN went out %u times, wanted 3", radio_tx_calls);
    CHECK(xfer_active == 1, "the transfer is not live");
    expect_ack(0, SK_ST_OK);
}

static void test_begin_busy_is_not_a_refusal(void)
{
    uint32_t t0;

    printf("-- IMG_BEGIN answered SK_ST_BUSY (the tag is erasing), then accepted\n");
    reset_world();
    t0 = virtual_ms;
    /* The tag erases its staging sectors before it answers, so the first thing
     * back is BUSY - which means "already on it", not "go away". */
    tag_reply_status(200, "1408F525", SK_ST_BUSY);
    tag_reply_ack(9000, 0, SK_ST_OK);
    host_begin_cmd(SK_IMG_TOTAL_BYTES, 0);
    CHECK(run_pending() == 1, "the BEGIN frame was not parsed");
    CHECK(radio_tx_calls == 1, "a BUSY answer must not cause a retransmission (%u sends)",
          radio_tx_calls);
    CHECK(xfer_active == 1, "the transfer should be live after the real ACK");
    CHECK(virtual_ms - t0 < LINK_BEGIN_BUDGET_MS,
          "the wait ran past the budget: %u ms", virtual_ms - t0);
    expect_ack(0, SK_ST_OK);
}

static void test_begin_busy_forever_is_bounded(void)
{
    uint32_t t0;
    int i;

    printf("-- IMG_BEGIN answered SK_ST_BUSY for ever: bounded, then reported\n");
    reset_world();
    t0 = virtual_ms;
    for (i = 0; i < 12; i++)
        tag_reply_status((uint16_t)(100 + i * LINK_BEGIN_WAIT_MS), "1408F525", SK_ST_BUSY);
    host_begin_cmd(SK_IMG_TOTAL_BYTES, 0);
    CHECK(run_pending() == 1, "the BEGIN frame was not parsed");
    CHECK(virtual_ms - t0 <= LINK_BEGIN_BUDGET_MS,
          "the wait was %u ms, the budget is %u", virtual_ms - t0, LINK_BEGIN_BUDGET_MS);
    CHECK(xfer_active == 0, "there is no transfer to be active");
    expect_status(SK_ST_BAD_SERIAL, LINK_D_TIMEOUT);
}

static void test_begin_refused(void)
{
    printf("-- IMG_BEGIN refused by the tag (wrong serial)\n");
    reset_world();
    tag_reply_status(120, "DEADBEEF", SK_ST_BAD_SERIAL);
    host_begin_cmd(SK_IMG_TOTAL_BYTES, 0);
    CHECK(run_pending() == 1, "the BEGIN frame was not parsed");
    CHECK(radio_tx_calls == 1, "IMG_BEGIN went out %u times, wanted 1", radio_tx_calls);
    CHECK(xfer_active == 0, "a refused BEGIN must not open a transfer");
    expect_status(SK_ST_BAD_SERIAL, LINK_D_TAG);
}

static void test_begin_ack_with_error_status(void)
{
    printf("-- IMG_BEGIN answered with a non-zero status\n");
    reset_world();
    tag_reply_ack(120, 0, SK_ST_FLASH);
    host_begin_cmd(SK_IMG_TOTAL_BYTES, 0);
    CHECK(run_pending() == 1, "the BEGIN frame was not parsed");
    CHECK(xfer_active == 0, "a failed BEGIN must not open a transfer");
    expect_ack(0, SK_ST_FLASH);
}

static void test_data_without_begin(void)
{
    printf("-- IMG_DATA with no transfer open\n");
    reset_world();
    host_data_cmd(0, 0x10, 4);
    CHECK(run_pending() == 1, "the DATA frame was not parsed");
    CHECK(radio_tx_calls == 0, "nothing should have gone on the air");
    expect_status(SK_ST_OFFSET, LINK_D_NO_XFER);

    printf("-- IMG_END with no transfer open\n");
    reset_world();
    host_end_cmd();
    CHECK(run_pending() == 1, "the END frame was not parsed");
    CHECK(radio_tx_calls == 0, "nothing should have gone on the air");
    expect_status(SK_ST_OFFSET, LINK_D_NO_XFER);
}

static void test_data_ok(void)
{
    printf("-- IMG_DATA accepted\n");
    reset_world();
    xfer_active = 1;
    xfer_total = SK_IMG_TOTAL_BYTES;

    tag_reply_ack(250, 0x00C3, SK_ST_OK);
    host_data_cmd(0x00C0, 0x40, 3);         /* 3 bytes at offset 192 */
    CHECK(run_pending() == 1, "the DATA frame was not parsed");
    CHECK(radio_tx_calls == 1, "IMG_DATA went out %u times, wanted 1", radio_tx_calls);
    CHECK(tx_log_len[0] == 8, "IMG_DATA length = %u, wanted 8", tx_log_len[0]);
    CHECK(tx_log[0][1] == SK_PKT_IMG_DATA, "type = %02X", tx_log[0][1]);
    CHECK(tx_log[0][2] == 0x00 && tx_log[0][3] == 0xC0, "offset = %02X%02X",
          tx_log[0][2], tx_log[0][3]);
    CHECK(tx_log[0][4] == 0x40 && tx_log[0][5] == 0x41 && tx_log[0][6] == 0x42,
          "data bytes were not carried through");
    CHECK(tx_log[0][7] == xor8(tx_log[0], 7), "the radio XOR checksum is wrong");
    expect_ack(0x00C3, SK_ST_OK);
}

static void test_data_retried_until_the_ack_moves(void)
{
    printf("-- IMG_DATA lost once, sent again\n");
    reset_world();
    xfer_active = 1;
    xfer_total = SK_IMG_TOTAL_BYTES;

    /* First answer says the tag still needs byte 192 - the block did not
     * arrive. The second says it has it. */
    tag_reply_ack(200, 0x00C0, SK_ST_OK);
    tag_reply_ack(200, 0x00C3, SK_ST_OK);
    host_data_cmd(0x00C0, 0x40, 3);
    CHECK(run_pending() == 1, "the DATA frame was not parsed");

    CHECK(radio_tx_calls == 2, "IMG_DATA went out %u times, wanted 2", radio_tx_calls);
    CHECK(tx_log_len[0] == tx_log_len[1] &&
          memcmp(tx_log[0], tx_log[1], tx_log_len[0]) == 0,
          "the retry was not byte-identical to the first attempt");
    expect_ack(0x00C3, SK_ST_OK);
}

static void test_data_retries_exhausted(void)
{
    uint32_t t0;

    printf("-- IMG_DATA with no answer at all\n");
    reset_world();
    xfer_active = 1;
    xfer_total = SK_IMG_TOTAL_BYTES;
    t0 = virtual_ms;

    host_data_cmd(0, 0x10, SK_IMG_DATA_MAX);
    CHECK(run_pending() == 1, "the DATA frame was not parsed");
    CHECK(radio_tx_calls == LINK_DATA_TRIES, "IMG_DATA went out %u times, wanted %u",
          radio_tx_calls, LINK_DATA_TRIES);
    CHECK(virtual_ms - t0 == (uint32_t)LINK_DATA_TRIES * LINK_DATA_WAIT_MS,
          "the wait was %u ms, wanted %u", virtual_ms - t0,
          LINK_DATA_TRIES * LINK_DATA_WAIT_MS);
    CHECK(tx_log_len[0] == 4 + SK_IMG_DATA_MAX + 1, "a full block is 101 bytes, got %u",
          tx_log_len[0]);
    CHECK(xfer_active == 1, "the transfer should stay open for a retry");
    /* The tag abandons a transfer after 30 s of radio silence, so the whole
     * data budget has to fit inside that window. */
    CHECK(LINK_DATA_TRIES * LINK_DATA_WAIT_MS < 30000,
          "the DATA budget (%u ms) reaches past the tag's 30 s silence limit",
          LINK_DATA_TRIES * LINK_DATA_WAIT_MS);
    expect_status(SK_ST_BAD_SERIAL, LINK_D_TIMEOUT);
}

static void test_data_offset_error(void)
{
    printf("-- the tag reports SK_ST_OFFSET (the block was ahead of it)\n");
    reset_world();
    xfer_active = 1;
    xfer_total = SK_IMG_TOTAL_BYTES;

    tag_reply_ack(150, 0x0000, SK_ST_OFFSET);
    host_data_cmd(0x00C0, 0x40, 3);
    CHECK(run_pending() == 1, "the DATA frame was not parsed");
    CHECK(radio_tx_calls == 1, "a definite refusal must not be retried (%u sends)",
          radio_tx_calls);
    /* The acknowledged offset is where the tag actually is, and it is a resume
     * point - the tag is still in the transfer, so it stays open here. */
    CHECK(xfer_active == 1, "a gap must leave the transfer open at the tag's offset");
    expect_ack(0x0000, SK_ST_OFFSET);
}

static void test_end_crc_failure(void)
{
    printf("-- IMG_END, tag reports a bad image CRC\n");
    reset_world();
    xfer_active = 1;
    xfer_total = SK_IMG_TOTAL_BYTES;

    /* The tag answers only after its panel refresh (~20 s), with off = the
     * whole image and the CRC verdict in the status. The early resend fires
     * first, because 2 s of silence is nothing when the answer is 20 s away. */
    tag_reply_ack(20000, SK_IMG_TOTAL_BYTES, SK_ST_CRC);
    host_end_cmd();
    CHECK(run_pending() == 1, "the END frame was not parsed");
    CHECK(radio_tx_calls == 2, "IMG_END went out %u times, wanted 2 (one resend)",
          radio_tx_calls);
    CHECK(tx_log_len[0] == 3 && tx_log[0][1] == SK_PKT_IMG_END &&
          tx_log[0][2] == xor8(tx_log[0], 2), "the IMG_END frame is malformed");
    CHECK(tx_log_len[1] == tx_log_len[0] && memcmp(tx_log[0], tx_log[1], 3) == 0,
          "the END resend was not byte-identical to the first transmission");
    CHECK(xfer_active == 0, "the transfer should be over");
    expect_ack(SK_IMG_TOTAL_BYTES, SK_ST_CRC);
}

static void test_end_rescued_by_the_resend(void)
{
    uint32_t t0;

    printf("-- the first IMG_END is lost; the 2 s resend rescues the transfer\n");
    reset_world();
    xfer_active = 1;
    xfer_total = SK_IMG_TOTAL_BYTES;
    t0 = virtual_ms;

    /* Nothing for the first transmission (the air ate it), then the answer
     * lands after the resend - the tag was still in its receive state and
     * took the second frame. */
    tag_reply_ack(LINK_END_RESEND_MS + 500, SK_IMG_TOTAL_BYTES, SK_ST_OK);
    host_end_cmd();
    CHECK(run_pending() == 1, "the END frame was not parsed");
    CHECK(radio_tx_calls == 2, "IMG_END went out %u times, wanted 2", radio_tx_calls);
    CHECK(virtual_ms - t0 < 10000, "the rescue took %u ms, it should be seconds",
          virtual_ms - t0);
    CHECK(xfer_active == 0, "the transfer should be over");
    expect_ack(SK_IMG_TOTAL_BYTES, SK_ST_OK);
}

static void test_end_is_bounded_and_never_sent_a_third_time(void)
{
    uint32_t t0;

    printf("-- IMG_END never answered: one early resend, then one long wait\n");
    reset_world();
    xfer_active = 1;
    xfer_total = SK_IMG_TOTAL_BYTES;
    t0 = virtual_ms;

    host_end_cmd();
    CHECK(run_pending() == 1, "the END frame was not parsed");
    CHECK(radio_tx_calls == 2, "IMG_END went out %u times - it must be exactly two: "
          "one early resend to rescue a lost frame, and no more",
          radio_tx_calls);
    CHECK(virtual_ms - t0 == (uint32_t)LINK_END_RESEND_MS + LINK_END_WAIT_MS,
          "the wait was %u ms, wanted %u", virtual_ms - t0,
          LINK_END_RESEND_MS + LINK_END_WAIT_MS);
    CHECK(LINK_END_WAIT_MS >= 30000, "the panel refresh budget is only %u ms",
          LINK_END_WAIT_MS);
    /* The resend has to land well inside the tag's own 30 s abandonment. */
    CHECK(LINK_END_RESEND_MS < 30000,
          "the END resend at %u ms is outside the tag's 30 s window",
          LINK_END_RESEND_MS);
    /* By the time this wait is up the tag has long since abandoned a transfer
     * it heard nothing about for 30 s, so the access point closes its own and
     * says so rather than letting the host wait another minute. */
    CHECK(xfer_active == 0, "the transfer should be over after an END timeout");
    expect_status(SK_ST_BAD_SERIAL, LINK_D_TIMEOUT);
}

static void test_end_answered_early_is_not_resent(void)
{
    printf("-- IMG_END answered inside the resend window: no second transmission\n");
    reset_world();
    xfer_active = 1;
    xfer_total = SK_IMG_TOTAL_BYTES;

    tag_reply_ack(500, SK_IMG_TOTAL_BYTES, SK_ST_OK);
    host_end_cmd();
    CHECK(run_pending() == 1, "the END frame was not parsed");
    CHECK(radio_tx_calls == 1, "IMG_END went out %u times, wanted 1", radio_tx_calls);
    expect_ack(SK_IMG_TOTAL_BYTES, SK_ST_OK);
}

static void test_end_with_a_short_image(void)
{
    printf("-- IMG_END early: the tag still wants bytes\n");
    reset_world();
    xfer_active = 1;
    xfer_total = SK_IMG_TOTAL_BYTES;

    tag_reply_ack(500, 5000, SK_ST_OK);
    host_end_cmd();
    CHECK(run_pending() == 1, "the END frame was not parsed");
    CHECK(xfer_active == 0, "the transfer should be over");
    expect_ack(5000, SK_ST_OFFSET);
}

static void test_radio_failure(void)
{
    printf("-- radio_tx() refuses the frame\n");
    reset_world();
    radio_tx_fail = 1;
    host_begin_cmd(SK_IMG_TOTAL_BYTES, 0);
    CHECK(run_pending() == 1, "the BEGIN frame was not parsed");
    CHECK(radio_tx_calls == 1, "a radio failure must not be retried here (%u calls)",
          radio_tx_calls);
    CHECK(radio_rx_start_calls == 1,
          "the receiver was left off the air after a failed transmit");
    expect_status(SK_ST_BAD_SERIAL, LINK_D_RADIO);
}

static void test_announcements_still_print(void)
{
    const char *want = "TAG 1408F525 rssi=-42\r\n";
    uint8_t announce[3 + 8 + 1];
    const char *sn = "1408F525";
    uint8_t i;

    printf("-- idle: TAG <serial> rssi=<db> is still printed\n");
    reset_world();
    announce[0] = SK_PROTO_VERSION;
    announce[1] = SK_PKT_ANNOUNCE;
    announce[2] = 8;
    for (i = 0; i < 8; i++)
        announce[3 + i] = (uint8_t)sn[i];
    announce[11] = xor8(announce, 11);

    report_packet(announce, 12, -42);
    CHECK(tx_capture_len == strlen(want) &&
          memcmp(tx_capture, want, tx_capture_len) == 0,
          "printed \"%.*s\", wanted \"%s\"", (int)tx_capture_len, tx_capture, want);
}

static void test_idle_answers_are_reported(void)
{
    uint8_t ack[6];

    printf("-- idle: a stray tag answer is reported, not silently dropped\n");
    reset_world();
    ack[0] = SK_PROTO_VERSION;
    ack[1] = SK_PKT_IMG_ACK;
    ack[2] = 0x2B; ack[3] = 0xF0; ack[4] = SK_ST_OK;
    ack[5] = xor8(ack, 5);
    report_packet(ack, 6, -50);
    CHECK(tx_capture_len > 0 && memcmp(tx_capture, "ACK off=2BF0 st=00", 18) == 0,
          "printed \"%.*s\"", (int)tx_capture_len, tx_capture);
}

int main(void)
{
    printf("ShelfKit access point: serial frame parser and bridge tests\n");
    printf("(the real firmware/access-point/src/main.c, compiled on the PC)\n\n");

    test_crc_vectors();
    test_parser_byte_at_a_time();
    test_junk_before_frame();
    test_bad_crc_then_valid();
    test_overlong_len();
    test_truncated_frame_then_valid();
    test_unknown_type_is_silent();
    test_payload_may_contain_sync();
    test_garbage_flood();
    test_rx_ring_survives_a_transmit();

    test_begin_ok();
    test_begin_retries_then_gives_up();
    test_begin_late_answer();
    test_begin_busy_is_not_a_refusal();
    test_begin_busy_forever_is_bounded();
    test_begin_refused();
    test_begin_ack_with_error_status();
    test_data_without_begin();
    test_data_ok();
    test_data_retried_until_the_ack_moves();
    test_data_retries_exhausted();
    test_data_offset_error();
    test_end_crc_failure();
    test_end_rescued_by_the_resend();
    test_end_is_bounded_and_never_sent_a_third_time();
    test_end_answered_early_is_not_resent();
    test_end_with_a_short_image();
    test_radio_failure();
    test_announcements_still_print();
    test_idle_answers_are_reported();

    printf("\n%d checks, %s\n", checks,
           failures ? "FAILURES" : "all passed");
    return failures ? 1 : 0;
}
