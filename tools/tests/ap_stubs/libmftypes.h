/**
 * @file libmftypes.h
 * @brief Host stand-in for libmf's SDCC-specific type/qualifier header
 *
 * tests/serial_frame_test.c compiles the real
 * firmware/access-point/src/main.c so that the frame parser and the bridge
 * are tested as written, not as re-implemented. Everything in this directory
 * exists only to let that source build as ordinary C: the SDCC keywords
 * become nothing, and the handful of SFRs and libmf functions main.c names
 * are declared here and defined in the test.
 *
 * This is the same trick libmf's own libmftypes.h uses for non-SDCC
 * compilers ("#define __reentrant" and so on), so no firmware source needs to
 * know it is being compiled on a PC.
 */

#ifndef AP_TEST_LIBMFTYPES_H
#define AP_TEST_LIBMFTYPES_H

#include <stdint.h>
#include <stddef.h>

#define __reentrant
#define __reentrantb
#define __xdata
#define __code
#define __data
#define __idata
#define __pdata
#define __genericaddr
#define __naked
#define __interrupt(x)

/* libmf's busy wait, counted in microseconds of the 20 MHz core. The test's
 * implementation advances a virtual clock, which is what makes the firmware's
 * timeout budgets assertable. */
void delay(uint16_t us);

void enter_standby(void);

#endif /* AP_TEST_LIBMFTYPES_H */
