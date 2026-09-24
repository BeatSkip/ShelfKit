# FM11NT081DS — contact (SPI) interface notes

Working notes for `src/nfc.c`, gathered from the Fudan Microelectronics documents in
`documentation/` and from the FM11NT081D technical manual. Everything the driver depends on is
listed here with where it came from, so the next person does not have to reverse it again.

## The chip

| | |
|---|---|
| Part | FM11NT081DS (`FM11NT0X1D` family, "D" = dual interface, "S" = SPI) |
| Function | NFC Forum Type 2 tag, ISO/IEC 14443-A, 13.56 MHz |
| Memory | 924 bytes EEPROM = 231 pages × 4 bytes; 888 bytes of it user read/write |
| UID | 7 bytes, factory programmed (cascade level 2), read-only |
| Interfaces | RF field **and** a contact interface: I2C on FM11NT081DI, SPI on FM11NT081**DS** |
| Field detect | pin 10 `WIP_FD`, open drain, low active (= `NFC_FD` on PB3 on this tag) |

Sources:

- `documentation/FM11NT0X1D_ps_eng.pdf` — product specification, pinout, memory sizes.
- FM11NT081D 双界面 NFC Forum Type2 标签芯片 技术手册 (technical manual, v1.0) — the SPI
  chapter (4.2) and the contact-interface memory map (3.2.3). Not in this repo; the sections
  used below are transcribed verbatim-in-substance here.

## Pinout (DFN10, FM11NT081DS)

| Pin | Name | Notes |
|---|---|---|
| 1 | VCC | contact-interface supply, 1.8 – 5.5 V |
| 2 | VOUT | harvested-field output, for powering the MCU |
| 3, 4 | IN1, IN2 | antenna |
| 5 | GND | |
| 6 | SSN | SPI chip select, low active, internal weak pull-up |
| 7 | SCLK | SPI clock input |
| 8 | MOSI | SPI slave data in, open drain — **external pull-up required** |
| 9 | MISO | SPI slave data out, tri-state |
| 10 | WIP_FD | EEPROM-write-in-progress / field detect, open drain, low active |

On the tag: SSN = PB1, SCLK = PC1, MOSI = PC2, MISO = PC3, WIP_FD = PB3
(`documentation/signal-list.md`).

## SPI framing

- Slave only, half duplex, up to 5 Mbit/s.
- **Mode 1 (CPOL = 0, CPHA = 1) is the factory default**; mode 3 is the alternative
  (technical manual 4.2.5). There is no mode 0 — which is what the AX8052's SPI unit is wired
  for because of the IL0373 panel, hence the bit-banged master in `nfc.c`.
  In mode 1 the slave samples MOSI on the **falling** edge and shifts MISO out on the
  **rising** edge.
- First byte after SSN goes low is the command byte:

  | Operation | Command byte | Second byte | Payload |
  |---|---|---|---|
  | write register | `000_x_rrrr` | – | data |
  | read register | `001_x_rrrr` | – | data (rrrr = 4-bit register address) |
  | write EEPROM | `010_000_aa` | A7:A0 | 1 – 16 bytes; the erase/write starts when SSN goes high |
  | **read EEPROM** | `011_000_aa` | A7:A0 | N bytes, address auto-increments |

  `aa` are address bits A9:A8, so **one command can only seek inside the 256-byte block its
  address belongs to** — `nfc_read()` is documented with the same restriction. Writes need a
  write-enable sequence (`110, x1110, 0101, 0101`) first and about 10 ms of SSN high to
  complete; the driver only reads.

- **Power-up**: if the chip has no RF field it sits powered down. The MCU must pull SSN low
  to wake it and then wait **at least 100 µs** before the first SCLK edge (4.2.3). Every
  `nfc_read()` is a self-contained frame for that reason.
- **Reset**: SSN must stay high for >= 50 ns to reset the SPI port between frames (5.3.3).
- **Contact timeout**: if the contact interface is selected and no clock arrives for 20 ms it
  resets itself and clears the RF/contact arbitration flag (4.4). Irrelevant for a boot-time
  dump, relevant if a driver ever streams continuously.

## Contact-interface EEPROM map (3.2.3, figure 3-2)

| Byte address | Page | Contents |
|---|---|---|
| 0x000 | 0 | `SN0 SN1 SN2 BCC0` |
| 0x004 | 1 | `SN3 SN4 SN5 SN6` |
| 0x008 | 2 | `BCC1 internal lock0 lock1` |
| 0x00C | 3 | capability container — `E1 10 6F 00` on an 888-byte part |
| 0x010 – 0x387 | 4 – 225 | user data (NDEF lives here) |
| 0x388 – 0x38B | 226 | dynamic lock bytes |
| 0x38C – 0x39B | 227 – 230 | configuration: AUTH0, ACCESS, REGU_CFG, PWD, PACK, 24-bit counter |
| 0x3A0 – 0x3A3 | 232 | ATQA / SAK1 / SAK2 (RF responses) |
| 0x3C0 – 0x3C7 | 240 – 241 | CT lock bits (OTP) |

The UID is stored *around* BCC0, not contiguously — the serial number is

```
SN = EE[0x000], EE[0x001], EE[0x002], EE[0x004], EE[0x005], EE[0x006], EE[0x007]
```

and the two ISO/IEC 14443-3 check bytes are

```
BCC0 = 0x88 ^ SN0 ^ SN1 ^ SN2     (0x88 = the cascade tag for a 7-byte UID)
BCC1 = SN3 ^ SN4 ^ SN5 ^ SN6
```

`nfc_read_serial()` returns success only when both match — that is the cheapest possible
proof that the SPI timing, the pin muxing and the chip's supply are all correct.

`SN0` is Fudan's ISO/IEC 7816-6 manufacturer code — the technical manual says it stores the
manufacturer code but does not print the value, so read it off the chip (it is the same byte
the RF side reports as `UID0`).

## Related

- The RF side of the same EEPROM is a plain NFC Forum Type 2 tag, so a phone reading the tag
  sees the same bytes (pages 0 – 2 as the UID, page 3 as the CC, then the NDEF message).
- The chip also has a 24-bit NFC counter that increments on the first read after each power-up
  (RF side) and an ECC originality signature; neither is exposed over the contact register
  space documented here.
