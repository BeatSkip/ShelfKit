/**
 * @file libmf.h
 * @brief Host stand-in for libmf's umbrella header
 *
 * The real one pulls in the debug link, flash, UART, ADC, BCH and radio
 * modules. main.c only needs the types and the CRC from it.
 */

#ifndef AP_TEST_LIBMF_H
#define AP_TEST_LIBMF_H

#include "libmftypes.h"
#include "libmfcrc.h"

#endif /* AP_TEST_LIBMF_H */
