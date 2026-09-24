/**
 * @file nfc.h
 * @brief Fudan FM11NT081DS NFC tag chip - contact (SPI) interface driver
 *
 * The UU340 carries an FM11NT081DS: an NFC Forum Type 2 tag with a
 * 924-byte EEPROM that is reachable both over the 13.56 MHz RF field and
 * over a serial (SPI) interface from the AX8052. The factory-programmed
 * 7-byte UID - the tag's serial number - sits at EEPROM address 0x000.
 *
 * The chip hangs off the shared SPI bus (SCK/MOSI/MISO = PC1/PC2/PC3,
 * chip select = PB1), but its SPI slave only speaks mode 1 (CPOL=0,
 * CPHA=1 - the factory default) or mode 3, while the AX8052's SPI unit is
 * set up for mode 0 because that is what the e-paper controller wants.
 * nfc_read() therefore bit-bangs the bus in mode 1 and nfc_release()
 * hands it back to the hardware SPI unit; see nfc.c for the details.
 *
 * Contact-interface EEPROM map (FM11NT081D technical manual, fig. 3-2):
 *
 *   0x000  page 0   SN0 SN1 SN2 BCC0     <- UID bytes 0-2 + check byte
 *   0x004  page 1   SN3 SN4 SN5 SN6      <- UID bytes 3-6
 *   0x008  page 2   BCC1 internal lock lock
 *   0x00C  page 3   capability container (E1 10 6F 00 on this part)
 *   0x010  ..      888 bytes of user memory (NDEF payload lives here)
 *   0x39C           end of the 924-byte EEPROM
 */

#ifndef NFC_DRIVER_H
#define NFC_DRIVER_H

#include <ax8052f143.h>
#include <libmftypes.h>

/* Total EEPROM: 231 pages x 4 bytes */
#define NFC_EEPROM_SIZE   924
/* The 7-byte UID / serial number */
#define NFC_SERIAL_LEN    7

/* EEPROM addresses of the interesting fields */
#define NFC_SERIAL_ADDR   0x000U    /* SN0..SN2, BCC0, SN3..SN6, BCC1 (9 bytes) */
#define NFC_CC_ADDR       0x00CU    /* capability container (4 bytes) */
#define NFC_TLV_ADDR      0x010U    /* start of the NDEF/TLV area (page 4) */
#define NFC_TLV_WINDOW    128U      /* bytes of it we read and parse */

/* Longest ASCII serial (the NDEF URI's last path segment) we will produce */
#ifndef NFC_SERIAL_STR_MAX
#define NFC_SERIAL_STR_MAX 24
#endif

/**
 * Take the SPI bus away from the hardware SPI unit and set up the bit-bang
 * pins. Call before the e-paper driver is initialised (or from any point
 * where the SPI unit can be re-initialised afterwards with spi_init()).
 * Leaves every chip select high, so the flash and the panel stay quiet.
 */
void nfc_init(void);

/**
 * Give the bus back: restore the pin muxing and re-enable the hardware SPI
 * unit via spi_init(). The caller does not need to call spi_init() again.
 */
void nfc_release(void);

/**
 * Read len bytes of the NFC chip's EEPROM, starting at addr.
 *
 * The chip is woken up by pulling SSN low (>= 100 us power-up time) and
 * put back to sleep by releasing it, so every call is a self-contained
 * transaction. Keep len inside a single 256-byte block: the 2 high address
 * bits are part of the command byte, so one command can only seek within
 * the block its address belongs to.
 */
void nfc_read(uint16_t addr, uint8_t *buf, uint8_t len) __reentrant;

/**
 * Read the 7-byte serial number (UID) and verify it against the two
 * ISO/IEC 14443-3 check bytes the chip stores next to it:
 *
 *   BCC0 = 0x88 ^ SN0 ^ SN1 ^ SN2      (0x88 = cascade tag, 7-byte UID)
 *   BCC1 = SN3 ^ SN4 ^ SN5 ^ SN6
 *
 * @return 1 when both check bytes match - i.e. the SPI transaction really
 *         produced the chip's UID - 0 when the read looks like noise.
 */
uint8_t nfc_read_serial(uint8_t serial[NFC_SERIAL_LEN]) __reentrant;

/**
 * Read the tag's serial number the way the stock system does: the NFC
 * EEPROM holds an NDEF URI record ("https://nfc.ses-imagotag.com/1408F525")
 * and the serial number is the last path segment of that URI.
 *
 * The TLV area is read from address 0x010 and parsed by nfc_ndef.c (which
 * is plain C and unit-tested on the host against a real capture).
 *
 * @return length of the serial (excluding the NUL), or 0 when the chip has
 *         no usable URI record.
 */
uint8_t nfc_read_tag_serial(char *serial, uint8_t maxlen) __reentrant;

/**
 * The same as nfc_read_tag_serial(), but the whole reconstructed URI - handy
 * for logging when a tag's serial cannot be parsed.
 */
uint8_t nfc_read_ndef_uri(char *uri, uint8_t maxlen) __reentrant;

/**
 * Fallback identifier for a chip with no (or unreadable) NDEF data: the
 * 7-byte UID as 14 uppercase hex characters.
 *
 * @return length of the string (excluding the NUL), or 0 if @p maxlen is
 *         too small.
 */
uint8_t nfc_uid_string(char *out, uint8_t maxlen) __reentrant;

#endif /* NFC_DRIVER_H */
