/**
 * @file nfc_ndef_test.c
 * @brief Host test for the NFC NDEF serial-number parser
 *
 * The parser in firmware/<project>/src/nfc_ndef.c has no MCU dependencies,
 * so it can be built and run on the PC - no tag required:
 *
 *   gcc -Wall -Wextra -o nfc_ndef_test tools/tests/nfc_ndef_test.c \
 *       firmware/shelfkit-vusion/src/nfc_ndef.c
 *   ./nfc_ndef_test          (or nfc_ndef_test.exe)
 *
 * The first case is the real capture from a UU340 tag (see nfc_ndef.h);
 * the rest are the shapes the parser has to survive on a chip whose EEPROM
 * contents we do not control.
 */

#include <stdio.h>
#include <string.h>

#include "../../firmware/shelfkit-vusion/src/nfc_ndef.h"

static int failures;

static void check_serial(const char *what, const uint8_t *tlv, uint16_t tlv_len,
                         const char *want_uri, const char *want_serial)
{
    char uri[NFC_NDEF_URI_MAX];
    char serial[NFC_NDEF_SERIAL_MAX];
    unsigned uri_len;
    unsigned serial_len;

    uri[0] = serial[0] = 0;
    uri_len   = nfc_ndef_uri(tlv, tlv_len, uri, sizeof uri);
    serial_len = nfc_ndef_last_segment(uri, serial, sizeof serial);

    if (strcmp(uri, want_uri) != 0 || strcmp(serial, want_serial) != 0) {
        printf("FAIL %-28s uri=\"%s\" serial=\"%s\" (wanted \"%s\" / \"%s\")\n",
               what, uri, serial, want_uri, want_serial);
        failures++;
        return;
    }
    printf("ok   %-28s uri=\"%s\" serial=\"%s\" (%u+%u bytes)\n",
           what, uri, serial, uri_len, serial_len);
}

/* ── the real thing: tools/flashdump-style capture of a UU340 NFC EEPROM ── */

static void test_real_capture(void)
{
    /* EEPROM 0x010-0x03F exactly as captured from the tag */
    static const uint8_t eeprom[] = {
        0x01, 0x03, 0xE8, 0x0E, 0x66, 0x03, 0x22, 0xD1,
        0x01, 0x1E, 0x55, 0x04, 0x6E, 0x66, 0x63, 0x2E,
        0x73, 0x65, 0x73, 0x2D, 0x69, 0x6D, 0x61, 0x67,
        0x6F, 0x74, 0x61, 0x67, 0x2E, 0x63, 0x6F, 0x6D,
        0x2F, 0x31, 0x34, 0x30, 0x38, 0x46, 0x35, 0x32,
        0x35, 0xFE, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    };

    check_serial("real UU340 capture", eeprom, sizeof eeprom,
                 "https://nfc.ses-imagotag.com/1408F525", "1408F525");
}

/* ── edge cases ───────────────────────────────────────────────────────── */

static void test_ndef_without_lock_tlv(void)
{
    /* NDEF TLV first: "http://x/ABC123" with the 03 abbreviation */
    static const uint8_t tlv[] = {
        0x03, 0x0E,
        0xD1, 0x01, 0x09, 0x55, 0x03,
        'x', '/', 'A', 'B', 'C', '1', '2', '3',
        0xFE
    };

    check_serial("no lock control tlv", tlv, sizeof tlv,
                 "http://x/ABC123", "ABC123");
}

static void test_null_tlvs_are_skipped(void)
{
    static const uint8_t tlv[] = {
        0x00, 0x00, 0x00,                       /* NULL TLVs */
        0x03, 0x0A,                             /* NDEF TLV, 10 bytes */
        0xD1, 0x01, 0x06, 0x55, 0x00,           /* 1 code byte + 5 chars */
        'S', 'N', '9', '9', '9'
    };

    check_serial("null tlvs skipped", tlv, sizeof tlv, "SN999", "SN999");
}

static void test_no_ndef_record(void)
{
    /* A terminator before any NDEF TLV: nothing to find */
    static const uint8_t tlv[] = { 0x01, 0x03, 0xE8, 0x0E, 0x66, 0xFE };

    check_serial("no ndef tlv", tlv, sizeof tlv, "", "");
}

static void test_truncated_tlv_is_safe(void)
{
    /* Claims 0x40 bytes of NDEF but the buffer ends - must not read past it */
    static const uint8_t tlv[] = { 0x03, 0x40, 0xD1, 0x01, 0x1E, 0x55, 0x04, 'a' };

    check_serial("truncated payload", tlv, sizeof tlv, "", "");

    /* TLV header cut in half */
    static const uint8_t half[] = { 0x03 };
    check_serial("truncated header", half, sizeof half, "", "");

    /* Length that overruns into a second TLV */
    static const uint8_t overrun[] = { 0x01, 0x7F, 0x03, 0x02, 0xAA, 0xBB };
    check_serial("length overrun", overrun, sizeof overrun, "", "");
}

static void test_not_a_uri_record(void)
{
    /* Well-known record, but type 'T' (text) instead of 'U' */
    static const uint8_t tlv[] = {
        0x03, 0x0A,
        0xD1, 0x01, 0x07, 0x54, 0x02,
        'x', 'x', '/', 'a', 'b', 'c'
    };

    check_serial("text record, not uri", tlv, sizeof tlv, "", "");
}

static void test_last_segment(void)
{
    char out[NFC_NDEF_SERIAL_MAX];

    nfc_ndef_last_segment("https://nfc.ses-imagotag.com/1408F525", out, sizeof out);
    if (strcmp(out, "1408F525")) { printf("FAIL last_segment plain\n"); failures++; }
    else printf("ok   last_segment plain\n");

    nfc_ndef_last_segment("https://host/path/DEADBEEF?x=1", out, sizeof out);
    if (strcmp(out, "DEADBEEF")) { printf("FAIL last_segment query\n"); failures++; }
    else printf("ok   last_segment stops at '?'\n");

    nfc_ndef_last_segment("https://host/", out, sizeof out);
    if (out[0]) { printf("FAIL last_segment empty\n"); failures++; }
    else printf("ok   last_segment empty tail\n");

    nfc_ndef_last_segment("noslashes", out, sizeof out);
    if (strcmp(out, "noslashes")) { printf("FAIL last_segment no slash\n"); failures++; }
    else printf("ok   last_segment without a slash\n");
}

int main(void)
{
    printf("NFC NDEF serial parser tests\n");
    test_real_capture();
    test_ndef_without_lock_tlv();
    test_null_tlvs_are_skipped();
    test_no_ndef_record();
    test_truncated_tlv_is_safe();
    test_not_a_uri_record();
    test_last_segment();

    printf("%s (%d failure%s)\n", failures ? "FAILED" : "all passed",
           failures, failures == 1 ? "" : "s");
    return failures ? 1 : 0;
}
