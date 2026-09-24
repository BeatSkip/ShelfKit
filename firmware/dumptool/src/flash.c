/**
 * @file flash.c
 * @brief Minimal SPI NOR flash driver (25-series command set)
 *
 * Reading was all this driver ever did. Writing an image to a NOR part is
 * the other half and is more delicate: bits can only be cleared by
 * programming and only set again by erasing a whole sector, the part is
 * busy for milliseconds afterwards, and it does not tell anyone when it is
 * done unless asked. So the write path is
 *
 *   write enable (0x06) -> program (0x02) or erase (0x20)
 *     -> poll status (0x05) bit 0 until clear
 *
 * with a read-back (0x03) on top, because a flash write that reports
 * success and stored something else is the failure that matters here (see
 * documentation/shelfkit-image-transfer.md).
 *
 * Addresses and lengths are 32 bit / 16 bit as in the rest of the driver:
 * this part is 128 KiB, so the three address bytes are all of it.
 */

#include "flash.h"
#include "spi.h"

#define CMD_READ        0x03    /* read data, 3-byte address */
#define CMD_JEDEC_ID    0x9F    /* read JEDEC ID */
#define CMD_RELEASE_PD  0xAB    /* release from deep power-down */
#define CMD_PAGE_PROG   0x02    /* program up to one 256-byte page */
#define CMD_READ_STATUS 0x05    /* status register 1 */
#define CMD_WRITE_EN    0x06    /* set the write enable latch */
#define CMD_SECTOR_ERASE 0x20   /* erase one 4 KiB sector */

#define STATUS_WIP      0x01    /* status bit 0: write/erase in progress */

/* Timeouts, in milliseconds. The 25-series datasheets put a 4 KiB sector
 * erase at ~45 ms typical / 400 ms maximum and a page program at ~0.7 ms /
 * 3 ms, so these are the "something is wrong with the part" limits, not the
 * expected durations. Both loops poll, so neither can hang the tag. */
#define TMO_ERASE_MS    3000
#define TMO_PROGRAM_MS  100

/* ── small helpers ────────────────────────────────────────────────────── */

/* One command byte, no payload. */
static void flash_cmd(uint8_t cmd)
{
    spi_select(SPI_DEV_FLASH);
    spi_transfer(cmd);
    spi_deselect(SPI_DEV_FLASH);
}

/* The three address bytes every addressed command takes, high byte first. */
static void flash_send_addr(uint32_t addr)
{
    spi_transfer((uint8_t)(addr >> 16));
    spi_transfer((uint8_t)(addr >> 8));
    spi_transfer((uint8_t)addr);
}

/* ── reading (the paths the dump tool uses - unchanged) ────────────────── */

void extflash_release_powerdown(void)
{
    spi_select(SPI_DEV_FLASH);
    spi_transfer(CMD_RELEASE_PD);
    spi_deselect(SPI_DEV_FLASH);

    /* tRES1: the part needs up to 35 us after this command before it takes
     * another one, and the very next command is now a write enable - which,
     * if it were dropped, would turn the program that follows into a silent
     * no-op. 50 us once per transfer is cheap insurance. */
    delay(50);
}

void extflash_read_jedec_id(uint8_t id[3])
{
    spi_select(SPI_DEV_FLASH);
    spi_transfer(CMD_JEDEC_ID);
    id[0] = spi_transfer(0x00);
    id[1] = spi_transfer(0x00);
    id[2] = spi_transfer(0x00);
    spi_deselect(SPI_DEV_FLASH);
}

void extflash_read(uint32_t addr, uint8_t *buf, uint16_t len)
{
    spi_select(SPI_DEV_FLASH);
    spi_transfer(CMD_READ);
    spi_transfer((uint8_t)(addr >> 16));
    spi_transfer((uint8_t)(addr >> 8));
    spi_transfer((uint8_t)addr);
    spi_read(buf, len);             /* clocks len bytes out of the chip */
    spi_deselect(SPI_DEV_FLASH);
}

/* ── writing ──────────────────────────────────────────────────────────── */

void extflash_write_enable(void) __reentrant
{
    flash_cmd(CMD_WRITE_EN);
}

uint8_t extflash_wait_ready(uint16_t timeout_ms) __reentrant
{
    uint16_t t = timeout_ms;

    while (t) {
        uint8_t sr;

        spi_select(SPI_DEV_FLASH);
        spi_transfer(CMD_READ_STATUS);
        sr = spi_transfer(0x00);
        spi_deselect(SPI_DEV_FLASH);    /* the bus is free between polls */

        if (!(sr & STATUS_WIP))
            return 1;

        delay(1000);                    /* 1 ms between polls */
        t--;
    }

    return 0;
}

uint8_t extflash_page_program(uint32_t addr, const uint8_t *buf, uint16_t len) __reentrant
{
    uint16_t inpage = (uint16_t)(addr & (FLASH_PAGE_SIZE - 1));

    if (!len || len > FLASH_PAGE_SIZE)
        return 0;

    /* A program that runs past the end of the page wraps back to the start
     * of the same page (the part has no address counter carry beyond the
     * low byte), which would overwrite the bytes just written. Refuse
     * instead of silently corrupting them - extflash_write() splits the
     * caller's buffer at the boundary. */
    if ((uint16_t)(inpage + len) > FLASH_PAGE_SIZE)
        return 0;

    extflash_write_enable();

    spi_select(SPI_DEV_FLASH);
    spi_transfer(CMD_PAGE_PROG);
    flash_send_addr(addr);
    spi_write(buf, len);
    spi_deselect(SPI_DEV_FLASH);

    return extflash_wait_ready(TMO_PROGRAM_MS);
}

uint8_t extflash_sector_erase(uint32_t addr) __reentrant
{
    /* The part erases the sector the address falls in, whatever the low
     * bits say, so round down here rather than let a caller believe a
     * smaller range was erased. */
    addr &= ~(uint32_t)(FLASH_SECTOR_SIZE - 1);

    extflash_write_enable();

    spi_select(SPI_DEV_FLASH);
    spi_transfer(CMD_SECTOR_ERASE);
    flash_send_addr(addr);
    spi_deselect(SPI_DEV_FLASH);

    return extflash_wait_ready(TMO_ERASE_MS);
}

uint8_t extflash_write(uint32_t addr, const uint8_t *buf, uint16_t len) __reentrant
{
    while (len) {
        /* Room left in the page this address falls in: 256 bytes when the
         * low address byte is zero, so 256 - (addr & 0xFF). */
        uint16_t room = (uint16_t)(FLASH_PAGE_SIZE -
                        (uint16_t)(addr & (FLASH_PAGE_SIZE - 1)));
        uint16_t n = len;

        if (n > room)
            n = room;

        if (!extflash_page_program(addr, buf, n))
            return 0;

        addr += n;
        buf += n;
        len = (uint16_t)(len - n);
    }

    return 1;
}

uint8_t extflash_verify(uint32_t addr, const uint8_t *buf, uint16_t len) __reentrant
{
    /* Byte by byte, and stop at the first mismatch: reading the page into a
     * buffer to memcmp() would need a second 256-byte buffer in a part with
     * 8 KiB of XRAM, and a full second read even when byte 0 is wrong. */
    spi_select(SPI_DEV_FLASH);
    spi_transfer(CMD_READ);
    flash_send_addr(addr);

    while (len--) {
        if (spi_transfer(0x00) != *buf++) {
            spi_deselect(SPI_DEV_FLASH);
            return 0;
        }
    }

    spi_deselect(SPI_DEV_FLASH);
    return 1;
}
