#ifndef HAL_H
#define HAL_H

#include <ax8052f143.h>
#include <libmftypes.h>
#include <libmfwtimer.h>

/* Deliberately NOT <libmfuart.h>/<libmfuart0.h>/<libmfuart1.h>: they declare
 * uart0_irq()/uart1_irq() as __interrupt handlers, and SDCC emits the
 * interrupt vector for a declaration - which drags libmf's buffered UART
 * (and its three 64-byte ring buffers, most of this part's 128 bytes of
 * directly addressable RAM) into every link. This firmware talks to the
 * UART registers directly instead; see src/uart.c. */

//Choose LOWFREQ_QUARZ or LOWFREQ_RC as source for RTC clock
//#define LOWFREQ_QUARZ
#define LOWFREQ_RC

#define HIGH (1)
#define LOW (0)

#define BIT(x)  (1<<(x))
#define SET(p,x)    do{(p) |= (x);}while(0)
#define CLEAR(p,x)  do{(p) &= ~(x);}while(0)

#define PIN_SET_INPUT(p,x)  CLEAR(p, (BIT(x)))
#define PIN_SET_OUTPUT(p,x) SET(p, (BIT(x)))
#define PIN_SET_LOW(p,x)    CLEAR(p, (BIT(x)))
#define PIN_SET_HIGH(p,x)   SET(p, (BIT(x)))

#ifdef LOWFREQ_QUARZ
#define SECONDS(x) ((uint32_t)(x) * 8192)
#elif defined LOWFREQ_RC
#define SECONDS(x) ((uint32_t)(x) * 640)
#endif // LOWFREQ_QUARZ
#define MILLISECONDS(x) (SECONDS(x) / 1000)

#define ABSOLUTE    0
#define RELATIVE    1

#define NAIVE_MEMCPY(x,y,n) for(int i=0;i<(n);i++){x[i]=y[i];}

#endif // HAL_H
