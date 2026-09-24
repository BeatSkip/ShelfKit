/**
 * @file ax8052f143.h
 * @brief Host stand-in for the AX8052F143's SFR definitions
 *
 * Only what firmware/access-point/src/main.c names, and only enough of it to
 * be an assignable lvalue - the test never runs main(), so the boot sequence
 * at the top of it is compiled and thrown away.
 *
 * U0SHREG is the interesting one: it is a function call used as an lvalue, so
 * every byte the firmware transmits lands in the next slot of the test's
 * capture buffer. That is how the host frames the access point emits are
 * checked byte for byte, sync bytes and CRC included.
 */

#ifndef AP_TEST_AX8052F143_H
#define AP_TEST_AX8052F143_H

#include <stdint.h>

/* One wide pool for the SFRs main() touches while it boots. uint16_t because
 * FRCOSCREF = 19531 is written to one of them. */
extern uint16_t ap_sfr[12];

#define PALTB         ap_sfr[0]
#define DIRB          ap_sfr[1]
#define PORTB         ap_sfr[2]
#define FRCOSCREF     ap_sfr[3]
#define FRCOSCKFILT   ap_sfr[4]
#define LPXOSCGM      ap_sfr[5]
#define OSCFORCERUN   ap_sfr[6]
#define FRCOSCCONFIG  ap_sfr[7]
#define WTCFGB        ap_sfr[8]
#define OSCCALIB      ap_sfr[9]
#define FRCOSCFREQ1   ap_sfr[10]

#define CLKSRC_LPXOSC 0x02
#define CLKSRC_FRCOSC 0x01

extern uint8_t u0_status;
extern uint8_t u0_ctrl;
extern uint8_t ap_ie_5;

uint8_t *ap_tx_slot(void);

#define U0STATUS (u0_status)
#define U0CTRL   (u0_ctrl)
#define U0SHREG  (*ap_tx_slot())
#define IE_5     ap_ie_5

#endif /* AP_TEST_AX8052F143_H */
