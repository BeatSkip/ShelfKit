/**
 * @file nfc_ndef.h
 * @brief Pull the tag's serial number out of the NFC chip's NDEF message
 *
 * The stock Vusion tags store an NFC Forum URI record in the NFC chip's
 * user memory; the serial number is the last path segment of that URI.
 * A real capture (Fudan FM11NT081DS, 924-byte EEPROM, read from address
 * 0x010):
 *
 *   0010: 01 03 E8 0E 66 03 22 D1 01 1E 55 04 6E 66 63 2E  |....f."...U.nfc.|
 *   0020: 73 65 73 2D 69 6D 61 67 6F 74 61 67 2E 63 6F 6D  |ses-imagotag.com|
 *   0030: 2F 31 34 30 38 46 35 32 35 FE 00 00 00 00 00 00  |/1408F525.......|
 *
 * which is NFC Forum Type 2 TLV encoding:
 *
 *   01 03 E8 0E 66        Lock Control TLV (skipped)
 *   03 22                 NDEF TLV, 0x22 = 34 bytes
 *     D1 01 1E 55 04 ...  NDEF record: MB|ME|SR|TNF=1, type len 1, payload 30,
 *                         type 'U', URI identifier code 04 = "https://",
 *                         then "nfc.ses-imagotag.com/1408F525"
 *   FE                    Terminator TLV
 *
 * This module is plain C with no MCU dependencies, so it can be compiled
 * for the host and unit-tested against real captures (tools/tests).
 */

#ifndef NFC_NDEF_H
#define NFC_NDEF_H

/* This module is plain C so that the host test (tools/tests) can compile
 * it with gcc. SDCC already has these types from libmftypes.h, and pulling
 * in its <stdint.h> as well would redefine them. __reentrant is SDCC's
 * "pass parameters on the stack" marker - it keeps a function's parameter
 * block off the 8051's 128 bytes of directly addressable RAM - and means
 * nothing to the host build. */
#if defined(SDCC)
#include <libmftypes.h>
#else
#include <stdint.h>
#define __reentrant
#endif

/* Longest reconstructed URI (including prefix) and serial we will handle */
#define NFC_NDEF_URI_MAX     64
#define NFC_NDEF_SERIAL_MAX  24

/**
 * Walk the Type 2 TLV area and reconstruct the first URI record into @p uri
 * as a NUL-terminated string (the URI identifier code is expanded, so the
 * result is a complete URI such as "https://nfc.ses-imagotag.com/1408F525").
 *
 * @param tlv      TLV area, starting at EEPROM address 0x010
 * @param tlv_len  how many bytes are valid in @p tlv
 * @param uri      output buffer
 * @param uri_max  size of @p uri
 * @return length of the URI (excluding the NUL), or 0 when there is no
 *         usable URI record in the TLV area
 */
uint8_t nfc_ndef_uri(const uint8_t *tlv, uint16_t tlv_len,
                     char *uri, uint8_t uri_max) __reentrant;

/**
 * Last path segment of a URI: "https://nfc.ses-imagotag.com/1408F525" gives
 * "1408F525". Trailing query/fragment separators end the segment too.
 *
 * @return length of the segment (excluding the NUL), or 0 if there is none
 */
uint8_t nfc_ndef_last_segment(const char *uri, char *out, uint8_t out_max) __reentrant;

#endif /* NFC_NDEF_H */
