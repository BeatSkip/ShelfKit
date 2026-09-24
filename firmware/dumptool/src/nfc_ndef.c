/**
 * @file nfc_ndef.c
 * @brief NDEF/TLV parsing for the NFC chip's serial number
 *
 * Pure C, no MCU dependencies - see nfc_ndef.h for the capture this is
 * modelled on and tools/tests/nfc_ndef_test.c for the host test that runs
 * this code against real EEPROM dumps.
 *
 * Everything here is written defensively: the bytes come from an EEPROM we
 * do not control, so every offset is bounds-checked before it is used and
 * any surprise makes the parser return 0 rather than read past the buffer.
 */

#include "nfc_ndef.h"

/* NFC Forum URI identifier codes (the first payload byte of a 'U' record) */
static const char *const nfc_uri_prefix[] = {
    "",                 /* 0x00 no abbreviation */
    "http://www.",      /* 0x01 */
    "https://www.",     /* 0x02 */
    "http://",          /* 0x03 */
    "https://",         /* 0x04 */
    "tel:",             /* 0x05 */
    "mailto:"           /* 0x06 */
};
#define NFC_URI_PREFIX_MAX 6

/* NDEF record header flags */
#define NDEF_MB   0x80      /* message begin */
#define NDEF_SR   0x10      /* short record: 1-byte payload length */
#define NDEF_TNF  0x07      /* type name format, 1 = NFC Forum well known */

/* Type 2 TLV tags */
#define TLV_NULL      0x00
#define TLV_NDEF      0x03
#define TLV_TERMINATOR 0xFE

/* Rebuild the URI of the first 'U' (URI) record of an NDEF message. */
static uint8_t ndef_record_uri(const uint8_t *m, uint16_t len,
                               char *uri, uint8_t uri_max)
{
    uint8_t  flags, type_len, uri_code;
    uint16_t payload_len, payload_off, i, n = 0;
    const char *prefix;

    if (len < 4)
        return 0;

    flags    = m[0];
    type_len = m[1];

    if (flags & NDEF_SR) {              /* short record */
        payload_len = m[2];
        payload_off = 3;
    } else {                            /* long record: 4-byte length */
        if (m[2] || m[3])               /* > 64 KiB - not something we handle */
            return 0;
        payload_len = (uint16_t)(((uint16_t)m[4] << 8) | m[5]);
        payload_off = 6;
    }

    if ((flags & NDEF_TNF) != 1)        /* must be "NFC Forum well known" */
        return 0;
    if (type_len != 1 || payload_off + type_len > len)
        return 0;
    if (m[payload_off] != 'U')          /* must be a URI record */
        return 0;
    payload_off = (uint16_t)(payload_off + type_len);

    if (payload_len < 1)
        return 0;
    if ((uint32_t)payload_off + payload_len > len)
        return 0;

    uri_code = m[payload_off];
    if (uri_code <= NFC_URI_PREFIX_MAX)
        prefix = nfc_uri_prefix[uri_code];
    else
        prefix = "";                    /* unknown code: use the raw payload */

    while (*prefix) {
        if (n + 1 >= uri_max)
            return 0;
        uri[n++] = *prefix++;
    }

    for (i = 1; i < payload_len; i++) { /* skip the identifier code byte */
        if (n + 1 >= uri_max)
            return 0;
        uri[n++] = (char)m[payload_off + i];
    }
    uri[n] = 0;
    return (uint8_t)n;
}

uint8_t nfc_ndef_uri(const uint8_t *tlv, uint16_t tlv_len,
                     char *uri, uint8_t uri_max) __reentrant
{
    uint16_t i = 0, off = 0, len = 0, val_len;
    uint8_t  tag;

    if (!tlv_len || uri_max < 2)
        return 0;

    while (i < tlv_len) {
        tag = tlv[i++];

        if (tag == TLV_NULL)            /* NULL TLV: no length, no value */
            continue;
        if (tag == TLV_TERMINATOR)      /* terminator: nothing more to find */
            return 0;
        if (i >= tlv_len)
            return 0;

        val_len = tlv[i++];             /* length byte */
        if (val_len == 0xFF) {          /* 3-byte length form */
            if (i + 1 >= tlv_len)
                return 0;
            if (tlv[i])                 /* > 64 KiB: not something we handle */
                return 0;
            val_len = tlv[i + 1];
            i = (uint16_t)(i + 2);
        }

        if (tag == TLV_NDEF) {          /* found it */
            off = i;
            len = val_len;
            break;
        }

        i = (uint16_t)(i + val_len);    /* skip this TLV's value */
    }

    if (!len || (uint32_t)off + len > tlv_len)
        return 0;

    return ndef_record_uri(tlv + off, len, uri, uri_max);
}

uint8_t nfc_ndef_last_segment(const char *uri, char *out, uint8_t out_max) __reentrant
{
    uint8_t i, start = 0, n = 0;

    if (!out_max)
        return 0;

    for (i = 0; uri[i]; i++) {
        if (uri[i] == '/')              /* only '/' starts a new segment; a */
            start = (uint8_t)(i + 1);   /* query or fragment ends it below */
    }

    for (i = start; uri[i]; i++) {
        char c = uri[i];
        if (c == '?' || c == '#' || c == '/' || c == ' ')
            break;
        if (c < 0x21 || c > 0x7E)       /* keep it printable */
            break;
        if (n + 1 >= out_max)
            break;
        out[n++] = c;
    }

    out[n] = 0;
    return n;
}
