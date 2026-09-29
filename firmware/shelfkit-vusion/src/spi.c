/**
 * @file spi.c
 * @brief Minimal hardware SPI master driver for the AX8052 (AX8052F143)
 *
 * Transfer protocol follows the vendor LibMF SDK's proven LCD driver code
 * (libraries/libmf/source/lcdinit.c):
 *
 *      SPSHREG = byte;                  // start transfer
 *      while (!(SPSTATUS & 0x01)) ;     // wait for completion (RX valid)
 *      byte = SPSHREG;                  // read result, clears the flag
 *
 * with one difference: that wait is bounded here. Polling SPSTATUS without a
 * limit is a hang waiting for a chance to happen - SPI unit off, a clock
 * source that never runs, or a pad that never took the SCK/MOSI function
 * leaves the completion flag clear for ever, and the first byte of the boot
 * image's 11248-byte upload is enough to stop the tag for good. A label whose
 * display is broken should still come up, announce itself and accept an
 * image; it should not be bricked by its panel.
 *
 * SPI_TMO is orders of magnitude more than one byte takes on this bus (see
 * SPI_CLKSRC_BYTE in spi.h), so a working bus never reaches it. After the
 * first timeout the bus is written off: later transfers return immediately
 * rather than paying the timeout again per byte, and the firmware reports it
 * once through spi_timed_out_flag() instead of printing a line per byte. */

#include "spi.h"
#include "board.h"

#define SPI_TMO 20000

/* XRAM rather than a plain static: this part has 128 bytes of directly
 * addressable internal RAM and it is the stack's, while XRAM has kilobytes
 * free. The byte is read once per transfer, which is a `movx` in a path that
 * is already waiting on hardware. */
static uint8_t __xdata spi_timed_out;

uint8_t spi_timed_out_flag(void)
{
    return spi_timed_out;
}

/* Wait for the byte in flight, or give up and write the bus off.
 * @return 1 when the byte completed, 0 when the bus has been written off. */
static uint8_t spi_wait(void)
{
    uint16_t t = SPI_TMO;

    while (!(SPSTATUS & 0x01)) {
        if (!--t) {
            spi_timed_out = 1;
            return 0;
        }
    }
    return 1;
}

void spi_init(void)
{
    /* SPI pins: PC1 = SCK, PC2 = MOSI out; PC3 = MISO in (default) */
    DIRC |= 0x06;
    DIRC &= (uint8_t)~0x08;

    /* All chip selects idle high, as outputs */
    DIRA |= 0x02;                   /* EPD CS on PA1 */
    DIRB |= 0x02;                   /* NFC CS on PB1 */
    DIRC |= 0x01;                   /* FLASH CS on PC0 */

    CS_EPD   = 1;
    CS_NFC   = 1;
    CS_FLASH = 1;

    /* Enable SPI master, mode 0, MSB first */
    SPCLKSRC = SPI_CLKSRC_BYTE;
    SPMODE   = 0x01;
    (void)SPSHREG;                  /* clear any pending flag */
}

void spi_select(spi_dev_t dev)
{
    switch (dev) {
    case SPI_DEV_FLASH: CS_FLASH = 0; break;
    case SPI_DEV_NFC:   CS_NFC   = 0; break;
    case SPI_DEV_EPD:   CS_EPD   = 0; break;
    }
}

void spi_deselect(spi_dev_t dev)
{
    switch (dev) {
    case SPI_DEV_FLASH: CS_FLASH = 1; break;
    case SPI_DEV_NFC:   CS_NFC   = 1; break;
    case SPI_DEV_EPD:   CS_EPD   = 1; break;
    }
}

uint8_t spi_transfer(uint8_t byte)
{
    if (spi_timed_out)
        return 0;                   /* bus written off: do not start anything */
    SPSHREG = byte;
    if (!spi_wait())
        return 0;
    return SPSHREG;
}

void spi_write(const uint8_t *buf, uint16_t len)
{
    while (len--) {
        if (spi_timed_out)
            return;
        SPSHREG = *buf++;
        if (!spi_wait())
            return;
        (void)SPSHREG;              /* discard received byte, clear flag */
    }
}

void spi_read(uint8_t *buf, uint16_t len)
{
    while (len--) {
        if (spi_timed_out) {
            *buf++ = 0;             /* defined bytes for a caller that reads on */
            continue;
        }
        SPSHREG = 0x00;
        if (!spi_wait()) {
            *buf++ = 0;
            continue;
        }
        *buf++ = SPSHREG;
    }
}
