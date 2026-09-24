/**
 * @file libmfcrc.h
 * @brief Host stand-in for libmf's CRC header
 *
 * The firmware calls crc_ccitt_msb_byte(); the test implements it with a
 * from-scratch bitwise CRC-16/CCITT-FALSE and cross-checks the table-driven
 * form libmf's assembly actually uses. crc_crc16_msb_byte() is declared too,
 * because the difference between the two is the trap this test exists to
 * document.
 */

#ifndef AP_TEST_LIBMFC_RC_H
#define AP_TEST_LIBMFC_RC_H

#include "libmftypes.h"

uint16_t crc_ccitt_msb_byte(uint16_t crc, uint8_t c) __reentrant;
uint16_t crc_ccitt_msb(const uint8_t __genericaddr *buf, uint16_t buflen,
                       uint16_t crc) __reentrant;

/* libmf's other CRC-16: poly 0x8005, not the one the protocol uses. */
uint16_t crc_crc16_msb_byte(uint16_t crc, uint8_t c) __reentrant;

#endif /* AP_TEST_LIBMFC_RC_H */
