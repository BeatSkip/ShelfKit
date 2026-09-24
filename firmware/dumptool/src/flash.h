/**
 * @file flash.h
 * @brief Minimal SPI NOR flash driver for the tag's serial flash
 *
 * The tag carries a (suspected) 1 Mbit = 128 KiB SPI NOR flash on PC0
 * (CS), sharing the SPI bus with the NFC chip and the e-paper panel.
 * Commands are the standard 25-series set (0x03 read, 0x9F JEDEC ID,
 * 0xAB release from power-down, 0x06 write enable, 0x05 read status,
 * 0x02 page program, 0x20 4 KiB sector erase).
 *
 * ── Staging an image ──────────────────────────────────────────────────
 * A received image is 11248 bytes and the tag has 8 KiB of XRAM, so it is
 * staged in the upper half of this flash (SK_IMG_FLASH_ADDR) and streamed
 * back out to the panel from there. The part programs a 256-byte page at a
 * time and erases a 4096-byte sector at a time, and NOR flash can only
 * clear bits, so the sequence is always erase-then-program:
 *
 *   extflash_release_powerdown();
 *   for each 4 KiB sector covering the image:  extflash_sector_erase();
 *   for each 256-byte page:                    extflash_write();
 *                                              extflash_verify();
 *
 * Every call that makes the part work polls status register bit 0 (WIP)
 * until it is clear again and gives up after a timeout, so a missing or
 * unresponsive chip costs a return code instead of a hang.
 */

#ifndef FLASH_DRIVER_H
#define FLASH_DRIVER_H

#include <ax8052f143.h>
#include <libmftypes.h>

/* Total size to dump. Adjust after checking the JEDEC ID capacity byte:
 *   0x13 = 512 kbit, 0x14 = 1 Mbit, 0x15 = 2 Mbit, 0x16 = 4 Mbit ... */
#define FLASH_SIZE 0x14000UL   /* 128 KiB */

/* The two granularities that matter for writing: a page program may not
 * cross a page boundary, and an erase always takes a whole sector. */
#define FLASH_PAGE_SIZE    256
#define FLASH_SECTOR_SIZE  4096

/* Send 0xAB: wakes the chip if a previous firmware left it in deep
 * power-down. Harmless when the chip is already awake. */
void extflash_release_powerdown(void);

/* Read the 3-byte JEDEC ID (manufacturer, memory type, capacity). */
void extflash_read_jedec_id(uint8_t id[3]);

/* Read len bytes from addr into buf using command 0x03. */
void extflash_read(uint32_t addr, uint8_t *buf, uint16_t len);

/* ── the write path ────────────────────────────────────────────────────── */

/* Set the write enable latch (0x06). The part clears it again at the end of
 * every program or erase, so each of those needs its own call - the two
 * functions below do that themselves; this is only here for callers that
 * issue a command of their own. */
void extflash_write_enable(void) __reentrant;

/* Poll status bit 0 until the write/erase in progress has finished.
 * @return 1 when the part is idle, 0 after @p timeout_ms milliseconds. */
uint8_t extflash_wait_ready(uint16_t timeout_ms) __reentrant;

/* Program one page: 1..FLASH_PAGE_SIZE bytes, none of them crossing the
 * 256-byte page boundary that addr falls in (the part would wrap the excess
 * back to the start of the page, silently corrupting it).
 * @return 1 when the part finished, 0 on a bad length, a page crossing or a
 *         timeout. 0 always means "assume the data in flash is wrong". */
uint8_t extflash_page_program(uint32_t addr, const uint8_t *buf, uint16_t len) __reentrant;

/* Erase the whole 4096-byte sector the address falls in (addr is rounded
 * down: the part erases the sector, not the range the caller asked for).
 * @return 1, or 0 on a timeout. */
uint8_t extflash_sector_erase(uint32_t addr) __reentrant;

/* Program len bytes at addr, splitting them at page boundaries.
 * @return 1, or 0 as soon as one page fails. */
uint8_t extflash_write(uint32_t addr, const uint8_t *buf, uint16_t len) __reentrant;

/* Read len bytes back and compare them with buf, byte for byte - reading
 * into a second buffer would cost another page of the tag's 8 KiB of XRAM.
 * @return 1 when flash holds exactly what was written. */
uint8_t extflash_verify(uint32_t addr, const uint8_t *buf, uint16_t len) __reentrant;

#endif /* FLASH_DRIVER_H */
