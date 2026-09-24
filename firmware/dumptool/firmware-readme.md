# ShelfKit — Dumptool

Firmware for the **SES-imagotag Vusion 2.6" BWR shelf label** (UU340 variant) whose only job
is to read every memory on the board and print it over UART. Build it, flash it, capture the
serial stream — that is the whole tool.

The tag is built around an **Axsem AX8052F143** (8051 core, 26 MHz crystal). It drives a Good
Display **GDEW026Z39** e-paper panel (296×152, IL0373), a Fudan **FM11NT081DS** NFC Forum
Type 2 tag chip, and a serial (SPI) flash.

## What it dumps

In this order, back to back:

| # | Memory | What comes out |
|---|---|---|
| 1 | **NFC chip** — FM11NT081DS, 924-byte EEPROM | 7-byte serial number (UID) + its ISO 14443-3 check bytes, the capability container, then the whole EEPROM |
| 2 | **SPI flash** — 128 KiB (see `FLASH_SIZE`) | JEDEC ID, then the whole chip |
| 3 | **MCU flash** — the AX8052's own 64 KiB code space | only when `DUMP_MCU_FLASH` is set to 1 in `src/main.c`; see *Extras* |

The order is not cosmetic: the NFC chip is a **mode-1** SPI slave while the flash and the panel
sit on the hardware SPI unit, which is set up for **mode 0**. `src/nfc.c` bit-bangs the pads in
mode 1, then hands the bus back to the hardware SPI unit for the flash section.

A capture looks like this (abridged):

```
*** imagotag memory dump ***
--- NFC (FM11NT081DS) ---
NFC serial: 04 5A 3C 7D 21 E8 B6  [check bytes ok]
NFC CC: E1 10 6F 00
NFC EEPROM: 924 bytes
000000: 04 5A 3C EA 7D 21 E8 B6 02 00 00 00 E1 10 6F 00  |.Z<.!.........|
...
--- end of NFC ---
--- SPI flash ---
JEDEC ID: 1F 42 00
000000: 01 01 FF FF FF FF FF FF FF FF FF FF FF FF FF FF  |................|
...
--- end of SPI flash ---
*** end of dump ***
```

`[check bytes ok]` means the two check bytes stored next to the UID matched, so the NFC read
really came off the chip. The format of the protocol is written up in
`documentation/FM11NT081DS-spi-notes.md`.

## Using it

1. **Build and flash this project.** In VS Code make `firmware/dumptool` the active folder and
   run *SDCC: Build*, then *SDCC: Flash* (the port comes from `ShelfKit.code-workspace` →
   `"sdcc.comPort"`). Build **before** flashing — the extension deletes stale
   `firmware.hex`/`.bin` on every build.
2. **Capture** — reset the tag and save the stream, splitting it into binaries as it goes:

   ```powershell
   python tools/memdump.py COM8
   ```

   ```
   memdump summary  (395123 bytes in 103.4s -> memdump_20260924_210500.txt)
     NFC serial      04 5A 3C 7D 21 E8 B6  [check bytes ok]
     NFC CC          E1 10 6F 00
     SPI flash ID    1F 42 00
     nfc             memdump_20260924_210500_nfc.bin       924 bytes
     spiflash        memdump_20260924_210500_spiflash.bin  131072 bytes
     mcu             - (section not in the capture)
   ```

   `memdump.py` drives the same wiring as the flasher (DTR = boot pin, RTS = reset), so it
   resets the tag into the application by itself. It imports `tools/flashdump.py` for the
   serial handling; `tools/flashdump.py` on its own still works if you just want the raw text.

   Anything that can read a serial port at 38400 8N1 works too — the sections are plain,
   labelled hexdumps and the capture always ends with `*** end of dump ***`.

The dump takes **~100 s** at 38400 baud, almost all of it the 128 KiB SPI flash. Nothing is
lost while the board is still printing, so start the capture first and reset afterwards.

## Extras

- **MCU flash dump.** Setting `DUMP_MCU_FLASH` to 1 in `src/main.c` adds a section that reads
  the AX8052's own 64 KiB code space with `MOVC` (no unlock needed — the flash lock only
  guards the debug link). It adds ~80 s to the capture, so raise the timeout:
  `python tools/memdump.py COM8 --timeout 400`. Mostly useful to inspect what is actually
  programmed (bootloader area, calibration), since a reflash has already overwritten the stock
  application.
- **Unused e-paper sources are excluded from the build.** `src/epd.c`, `src/epd_image.c` and
  the boot image are still in the tree (they belong to `shelfkit-vusion`), but SDCC links every
  object file it is handed — unused code is *not* dropped — so `sdcc-project.json` excludes them
  with a `{"exclude": ["src/epd.c", "src/epd_image.c"]}` rule. That is the difference between a
  ~19 KB and a ~6 KB firmware; reach for the same trick in any other dump-style project.

## Repository layout

| Path | Contents |
|---|---|
| `src/` | `main.c` (the dump tool), `nfc.c/h` (FM11NT081DS driver), `flash.c/h` (SPI NOR), `spi.c/h`, `board.c/h`, `pwr.c/h`, `hal.h`, plus the unused e-paper driver |
| `documentation/` | AX8052F100/F143 datasheets, the panel datasheet, the NFC protocol notes, `signal-list.md` |
| `build/` | Build output (`firmware.ihx`, `.hex`, `.bin`, `.map`, `.mem`) |
| `.sdcc/boards/` | Board definition for the SDCC-MDF extension (project-scoped) |
| `sdcc-project.json` | SDCC-MDF project configuration |

## Pin map

Full authoritative mapping: `documentation/signal-list.md`.

| Function | Pin | Notes |
|---|---|---|
| LED white / blue / green | `PB0` / `PB7` / `PB6` | active low |
| LED red | `PC4` | active low |
| UART0 TX / RX | `PB4` / `PB5` | 38400 8N1; TX only, PB5 is also the panel reset |
| SPI SCK / MOSI / MISO | `PC1` / `PC2` / `PC3` | hardware SPI unit, or GPIO while the NFC chip is read |
| CS flash / NFC / EPD | `PC0` / `PB1` / `PA1` | active low |
| EPD D/C, RST, BUSY | `PA0`, `PB5`, `PB2` | unused by the dump tool |
| NFC field detect / boot | `PB3` | the flasher and `memdump.py` use it as the boot pin |
| Transistor U4 / U5 | `PA5` / `PA2` | function not identified yet |

## Building

Required: [SDCC](https://sdcc.sourceforge.net/) (tested with 3.6.0) and the
[SDCC-MDF extension](https://marketplace.visualstudio.com/items?itemName=dzantemir.sdcc-mdf)
(tested with 0.29.11) in VS Code.

1. Open the repository in VS Code (the `ShelfKit.code-workspace` file opens every project).
2. If the extension does not detect SDCC, set the path via *SDCC-MDF: Select Toolchain*.
3. Select `firmware/dumptool`, then **Ctrl+Shift+B** (*SDCC: Build*); *SDCC: Flash* writes it
   through the AXSEM serial bootloader.

This project currently uses ~6 KB of the ~58 KB usable flash.

The same build by hand, from `firmware/dumptool` (PowerShell needs `&` before a quoted
executable path):

```powershell
$sdcc  = 'C:\Program Files\SDCC\bin\sdcc.exe'
$flags = @('-mmcs51','--model-small','--iram-size','256','--xram-size','8192','--code-size','59389')
$inc   = @('-I../shared/include','-I../shared/libraries/libmf/include','-I../shared/libraries/libaxdvk2/include')
$srcs  = @('main','board','spi','nfc','flash','pwr')   # see the exclude rule in sdcc-project.json

foreach ($s in $srcs) {
    & $sdcc -c @flags @inc "src/$s.c" -o "build/obj/src/$s.rel"
}

& $sdcc @flags @inc ($srcs | ForEach-Object { "build/obj/src/$_.rel" }) `
    '../shared/lib/libaxdsp.lib' '../shared/lib/libaxdvk2.lib' `
    '../shared/lib/libmf.lib'    '../shared/lib/libmfcrypto.lib' `
    -o 'build/firmware.ihx'

# The hex the flasher eats has to be plain ASCII - PowerShell's '>' would
# write UTF-16 with a BOM and the bootloader would choke on the first line.
& 'C:\Program Files\SDCC\bin\packihx.exe' 'build/firmware.ihx' |
    Set-Content -Encoding ascii 'build/firmware.hex'
```

## Driver notes

### NFC — `src/nfc.c`

Fudan FM11NT081DS: NFC Forum Type 2 tag, 924-byte EEPROM, SPI contact interface, 7-byte
factory UID at EEPROM address 0x000 — the tag's serial number. Protocol details, the memory
map and the read framing (`011_000xx` + address byte, address auto-increments, ≥100 µs
power-up after SSN goes low, SPI **mode 1**) are in `documentation/FM11NT081DS-spi-notes.md`.

The AX8052's SPI unit cannot do mode 1 as wired here, so the driver turns the SPI unit off,
drives SCK/MOSI as GPIO, reads MISO from `PINC`, and restores everything afterwards
(`nfc_release()` calls `spi_init()`). The bit rate lands around 100–250 kHz, far below the
chip's 5 MHz limit.

If the serial number reads back as all `00`/`FF` with `[check bytes BAD]`, nothing reached the
chip. In rough order of likelihood: the chip has no supply (PA2/PA5 switch unidentified
transistor loads — see `pwr.h`), the wake-up delay is too short, or the pads never became
GPIO (see the `PALTC` handling in `nfc_init()`).

### Serial flash — `src/flash.c`

Thin 25-series SPI NOR driver: `extflash_release_powerdown()`, `extflash_read_jedec_id()`,
`extflash_read()`. The dump size is `FLASH_SIZE` in `flash.h` (128 KiB by default — check the
JEDEC capacity byte against the real chip).

### UART — `src/main.c`

UART0 at 38400 8N1 on PB4, TX only, written straight to the UART registers: the prebuilt
`libmf.lib` in this link has broken FIFO size tables, which wedges `libmf`'s `uart0_tx()`
after a few bytes. The FRC oscillator is slaved to the 32 kHz crystal with the same sequence
the AXSEM bootloader uses — without it the baud rate is ~10% off and nothing decodes.

## Known issues and quirks

- **SDCC-MDF vs PowerShell** (extension ≤ 0.29.11): the extension emits single-quoted tool
  paths without the `&` call operator, so with a PowerShell terminal every build fails with
  `Unexpected token '-mmcs' …`. This repo works around it with `"sdcc.shellPath": "cmd.exe"`
  in `.vscode/settings.json` (workspace-scoped). After changing it, reload the VS Code window.
- **Board definitions are cached** by the extension; after editing
  `.sdcc/boards/…/axsem-8052f143.json`, reload the window for the change to take effect.
- The `lib/*.lib` files are SDCC archives built from `libraries/` with the vendor's
  `buildsdcc` makefiles. Only `libmf` is really needed.
- The hexdump goes out at **38400 8N1** with no flow control. A capture tool that drops bytes
  silently produces gaps; `memdump.py` reports any address it never saw.

## Not done yet

- Hardware verification of the NFC read: the serial number should come back with
  `[check bytes ok]` and the CC should read `E1 10 6F 00`.
- Identification of the PA2/PA5 transistor lines (they may gate the flash/NFC supply).
- Debug-link recipe for the AX8052 (the serial bootloader path works; the debug link is only
  needed for breakpoints and recovery).
