# ShelfKit - Firmware

Firmware and tooling for the **SES-imagotag Vusion 2.6" BWR shelf label** (UU340 variant).
The tag is built around an **Axsem AX8052F143** — an 8051 core with an integrated **AX5043**
sub-GHz transceiver (27-1050 MHz, so the common "2.4 GHz" description of this part is wrong),
clocked by a 26 MHz crystal. It drives a Good Display **GDEW026Z39** e-paper panel
(296×152, black/white/red, IL0373 controller), a Fudan **FM11NT081DS** NFC Forum Type 2 tag
chip (whose NDEF record carries the tag's serial number) and a serial flash.

The original firmware was built with IAR EW8051. This repository builds it with **SDCC**
instead, using the **SDCC-MDF** extension for VS Code.

## Current status

- The project **builds cleanly with SDCC**; roughly 34.6 KB of the ~58 KB usable flash is used,
  with 141 bytes of stack left.
- On boot the tag, in this order:
  1. reads the **NFC chip** and pulls the serial number out of its NDEF URI record (a real tag
     answers `https://nfc.ses-imagotag.com/1408F525`, so the serial is `1408F525`), falling
     back to the 7-byte UID as hex if there is no NDEF record;
  2. **announces itself over the radio** ("I am 1408F525"), three times, so an access point
     sees the tag seconds after it powers up;
  3. shows the **polyform boot image** on the e-paper and blinks the blue LED when the refresh
     finishes.
- It then **listens for an image transfer** addressed to that serial number. A transfer is
  `IMG_BEGIN` / `IMG_DATA` x N / `IMG_END` (`firmware/shared/include/shelfkit_proto.h`): the
  tag stages the image in the upper half of its SPI flash (`SK_IMG_FLASH_ADDR`), verifies it
  against the sender's CRC-16/CCITT-FALSE, and streams both planes from the flash to the panel.
  While nothing is being transferred it repeats its announcement every 10 s, so an access point
  that comes up late still finds the tag. The end-to-end design is in
  [`documentation/shelfkit-image-transfer.md`](../../documentation/shelfkit-image-transfer.md).
- The NFC read and the radio link are **implemented but not yet
  verified on hardware** - the boot log says exactly what happened either way. The flash write
  path and the receive state machine are in the same position: they compile and link, and the
  sequences are the ones the datasheets specify, but no image has been transferred to a real
  tag yet.
- **Flashing works through the AXSEM serial bootloader.** `SDCC: Flash` runs
  `tools/axsem-flasher.py` (see `sdcc-project.json` → `upload`), which resets the tag into its
  bootloader over the CH9102 USB-serial converter and streams the hex at 38400 baud. The port
  comes from `ShelfKit.code-workspace` → `"sdcc.comPort"` (COM8 by default). **Build first**:
  the extension deletes stale `firmware.hex`/`.bin` on every build, so flashing a tree that
  has not been built yet only gets you "Hex file not found".
- The transistor-driven lines on PA2/PA5 are driven by `pwr.c` (config in `pwr.h`), their loads
  still unidentified.

## Repository layout

| Path | Contents |
|---|---|
| `src/` | Application code: `main.c` (NFC read + boot image), `board.c/h`, `hal.h`, drivers `spi.c/h`, `nfc.c/h`, `epd.c/h`, `flash.c/h`, `pwr.c/h`, and the generated boot image `epd_image.c/h` |
| `tools/` | Helper scripts: `png2epd.py` converts a PNG into e-paper plane data |
| `include/` | Project-local headers (currently empty) |
| `lib/` | Prebuilt Axsem LibMF SDK libraries as SDCC archives: `libmf`, `libaxdvk2`, `libaxdsp`, `libmfcrypto` |
| `libraries/` | Full Axsem SDK source tree (IAR/Keil/SDCC/ARM build makefiles and headers) |
| `documentation/` | AX8052F100/F131/F143 datasheets |
| `.sdcc/boards/` | Board definition for the SDCC-MDF extension (project-scoped, travels with the repo) |
| `.vscode/` | Build tasks, IntelliSense config, workspace settings |
| `sdcc-project.json` | SDCC-MDF project configuration |
| `GDEW026Z39-init-reference.md` | Notes on the e-paper init sequence and the sources of each byte |

## Pin map

Full authoritative mapping: `documentation/signal-list.md`.

| Function | Pin | Notes |
|---|---|---|
| LED white / blue / green | `PB0` / `PB7` / `PB6` | active low |
| LED red | `PC4` | active low |
| UART0 TX / RX | `PB4` / `PB5` | 38400 8N1, timer 0 baud (off while the e-paper is driven) |
| SPI SCK / MOSI / MISO | `PC1` / `PC2` / `PC3` | hardware SPI unit |
| CS flash / NFC / EPD | `PC0` / `PB1` / `PA1` | active low |
| EPD D/C, RST, BUSY | `PA0`, `PB5`, `PB2` | D/C: 0 = command, 1 = data |
| NFC field detect / boot | `PB3` | |
| Transistor U4 / U5 | `PA5` / `PA2` | function not identified yet |

One conflict worth knowing about: **EPD reset shares PB5 with the UART RX function.**
Enabling UART0 hands the pin to the UART, so the boot demo leaves UART0 off — if a future
firmware needs UART, it must release PB5 (or reset the panel) before driving the display.

## Building

Required: [SDCC](https://sdcc.sourceforge.net/) (tested with 3.6.0) and the
[SDCC-MDF extension](https://marketplace.visualstudio.com/items?itemName=dzantemir.sdcc-mdf)
(tested with 0.29.11) in VS Code.

1. Open the repository in VS Code.
2. If the extension does not detect SDCC, set the path via *SDCC-MDF: Select Toolchain*.
3. **Ctrl+Shift+B** (or the *SDCC: Build* task). Output lands in `build/`:
   - `firmware.ihx` — linker output
   - `firmware.hex` — Intel HEX, ready for flashing once flashing is wired up
   - `firmware.map` / `firmware.mem` — placement and usage report

The same build by hand, from `firmware/shelfkit-vusion` (PowerShell needs `&` before a quoted
executable path). **The source list is not written out here**: it is every `src/*.c` except
the ones `sdcc-project.json` excludes, and the list below has gone stale more than once.
`tools/build_firmware.ps1` reads the project file and does all of this, printing the ROM,
XRAM and free-stack numbers at the end:

```powershell
powershell -ExecutionPolicy Bypass -File tools/build_firmware.ps1 -Firmware shelfkit-vusion
powershell -ExecutionPolicy Bypass -File tools/build_firmware.ps1 -Firmware shelfkit-vusion -Define SK_TAG_ROUTER=1
```

By hand it is:

```powershell
$sdcc  = 'C:\Program Files\SDCC\bin\sdcc.exe'
$flags = @('-mmcs51','--model-small','--iram-size','256','--xram-size','8192','--code-size','59389')
$inc   = @('-I../shared/include','-I../shared/libraries/libmf/include','-I../shared/libraries/libaxdvk2/include')
$srcs  = @('main','board','spi','nfc','nfc_ndef','flash','pwr','uart','radio','sk_link','epd','epd_image')

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

The host tests (the link layer, the access point's bridge and the Python tools) are one
command from the repository root:

```powershell
powershell -ExecutionPolicy Bypass -File tools/run_tests.ps1
```

`build/firmware.bin` (32 KB flash image, gaps filled with `0xFF`) is what the SDCC-MDF
extension produces alongside the hex; nothing in this repo consumes it.

Memory model is `--model-small`, with 256 B IRAM, 8 KB XRAM and ~58 KB code (the top of the
64 KB flash is reserved, matching the boundary the original IAR linker file used).

## Drivers

### Transistor lines — `src/pwr.h`

Controls the unidentified transistor lines PA2 (U5) and PA5 (U4). Which pins are driven and
their polarity are `#define`s at the top of `pwr.h`:

```c
#define PWR_USE_U4  1       /* PA5 */      #define PWR_USE_U5  1       /* PA2 */
#define PWR_U4_ACTIVE_HIGH  1              #define PWR_U5_ACTIVE_HIGH  1

pwr_init();                /* selected pins become outputs, driven off */
pwr_on();                  /* drive all selected pins to their on level */
pwr_off();
pwr_pulse(100, 100, 0);    /* 100 ms on, 100 ms off, forever */
```

The boot demo calls `pwr_on()` before touching the panel, on the assumption one of the
transistors gates the display supply. If that misbehaves, flip the polarity defines or
disable one pin and rebuild.

### SPI — `src/spi.h`

A thin wrapper over the AX8052's built-in SPI unit, mode 0, MSB first — the same
configuration the vendor's own LCD code uses. Provides `spi_init()`, `spi_transfer()`,
`spi_write()`/`spi_read()`, and chip-select helpers for the three slaves on the bus
(EPD, NFC, flash). The SPI clock source is a `#define` at the top of the header; the default
(0xD8) is the LibMF LCD driver's setting, and 0x06 (SYSCLK) also works.

**The completion wait is bounded, and a bus that never answers is written off.** The vendor's
sequence polls `SPSTATUS` with no limit; here the poll gives up after `SPI_TMO` tries, sets a
flag, and every later transfer returns immediately (`spi_timed_out_flag()`). The reason is the
boot image: 11248 bytes go out over this bus on every power-up, so a bus that never completes a
byte — SPI unit off, a clock source that never runs, a pad that never took SCK/MOSI — would
otherwise stop the tag on the first byte. With the timeout, a label with a dead display still
comes up, announces itself and accepts an image (stored, not shown), and says so once:
`panel: the SPI bus never completed a byte`. A healthy bus never comes close to the timeout.

`epd_wait_busy()` in `epd.c` is the one remaining unbounded poll, and it is unreachable in this
firmware: `main.c` drives the panel through its own `epd_write_cmd()`/`epd_write_data()` and
bounds both of its BUSY waits with `wait_busy_change()`/`wait_busy_return()`. Only
`epd_init()`/`epd_refresh()`/`epd_sleep()` — which nothing calls — reach it.

### NFC — `src/nfc.h`

Driver for the tag's NFC chip, a **Fudan FM11NT081DS**: an NFC Forum Type 2 tag with a
924-byte EEPROM, an SPI *contact* interface next to the 13.56 MHz one, and a factory
programmed 7-byte UID. The protocol notes this driver is built on are written up in
`documentation/FM11NT081DS-spi-notes.md`.

```c
#include "nfc.h"

nfc_init();                              /* take the SPI pads over as GPIO */
if (nfc_read_serial(uid))                /* 7-byte UID, check bytes verified */
    ...;
nfc_read_tag_serial(serial, sizeof serial);  /* the tag's serial number, ASCII */
nfc_read(0x010, nfc_buf, 16);            /* any address, up to 256 bytes */
nfc_release();                           /* back to the hardware SPI unit */
```

**The serial number is not the UID.** A stock tag stores an NDEF URI record in the chip's user
memory and the serial number is the *last path segment* of that URI:

```
0010: 01 03 E8 0E 66 03 22 D1 01 1E 55 04 6E 66 63 2E  |....f."...U.nfc.|
0020: 73 65 73 2D 69 6D 61 67 6F 74 61 67 2E 63 6F 6D  |ses-imagotag.com|
0030: 2F 31 34 30 38 46 35 32 35 FE 00 00 00 00 00 00  |/1408F525.......|
```

That is a Type 2 TLV area (a Lock Control TLV, then `03 22` = 34 bytes of NDEF) holding one URI
record whose payload is `https://nfc.ses-imagotag.com/1408F525` — so the tag's serial number is
**`1408F525`**. `nfc_read_tag_serial()` follows that chain and hands back the string;
`nfc_read_ndef_uri()` returns the whole reconstructed URI for logging, and `nfc_uid_string()`
gives the UID as 14 hex characters for a chip with no NDEF record at all.

The parsing lives in `src/nfc_ndef.c`, which is **plain C with no MCU dependencies**, so it is
unit-tested on the PC against a real capture from this tag:

```powershell
gcc -Wall -Wextra -o nfc_ndef_test tools/tests/nfc_ndef_test.c `
    firmware/shelfkit-vusion/src/nfc_ndef.c
./nfc_ndef_test
```

`main.c` uses it in `nfc_report()` for **the serial number and nothing else**: the NDEF TLV
window (8 bit-banged transactions), and the 7-byte UID only when there is no NDEF record to
fall back from. It used to also read the capability container and hexdump the whole 924-byte
EEPROM — 58 transactions and some 4 KB of UART, about 150 ms of boot blocked before the panel
refresh was even reached, for bytes no part of the firmware ever read. Reading the whole EEPROM
is still a thing that can be done: that is what `firmware/dumptool` is for, driven by
`tools/memdump.py`.

**Why it is bit-banged.** The FM11NT081DS slave only speaks SPI **mode 1** (CPOL=0, CPHA=1,
the factory default) or mode 3, while the IL0373 e-paper controller needs mode 0 — and mode 0
is what the AX8052's SPI unit is set up for. A mode-0 master driving a mode-1 slave is a
timing race (the master changes MOSI on the very edge the slave samples it), so `nfc.c`
sidesteps the undocumented SPMODE mode bits: it switches the SPI unit off, drives SCK/MOSI as
GPIO, reads MISO from `PINC`, then hands the bus back. While it does so it also clears the
PALTC bits of PC1/PC2 (so the peripheral output and the PORT register cannot fight over the
pad) and restores them afterwards. The bit rate lands around 100-250 kHz, far below the
chip's 5 MHz limit — the serial-number read is eight transactions and takes a couple of
milliseconds.

Reading the chip at any other time works the same way; the NFC chip's chip select (PB1) is
held high whenever the hardware SPI unit is in use, so the flash and the panel are unaffected.

A boot log looks like this:

```
*** ShelfKit tag ***
trace level 1 (every block, page and refusal)

--- NFC chip (FM11NT081DS) ---
serial number: 1408F525  [from the NDEF URI]
--- end of NFC ---
```

When the chip has no readable NDEF record the tag falls back to the UID, and says so — the UID
as 14 hex characters, with the reason:

```
serial number: 045A3CEA7D21E8B6  [NO NDEF RECORD - the UID as hex]
```

That line is the one to read when something is wrong with the chip. A UID of all `00` or all
`FF` means nothing came off the contact interface (the chip is unpowered, was not awake yet, or
the pads never became GPIO); see the list below. **The check bytes the driver also verifies are
no longer printed**: with the EEPROM dump gone, the NDEF record is the proof that the chip
answered, and a UID that is all `00`/`FF` is the proof that it did not. The driver still returns
the check-byte verdict and `tools/memdump.py` prints it for a full dump.

If the NDEF read fails, in rough order of likelihood:

1. **The chip may have no supply.** PA2/PA5 switch unidentified transistor loads (`pwr.h`);
   if the NFC chip is behind one of them, try `PWR_USE_U5 1` and/or flip the polarity defines.
2. **The chip was not awake yet.** Raise `NFC_WAKE_US` in `nfc.c` (the datasheet asks for
   >= 100 us between SSN going low and the first clock edge).
3. **The pads never became GPIO.** Verify the `PALTC` handling in `nfc_init()` against the
   port pin schematic in the AX8052F143 datasheet (figure 10).
4. **MOSI/MISO**: the chip's MOSI is an open-drain I/O with an external pull-up; check the
   signal list against the chip's DFN10 pinout (`documentation/FM11NT0X1D_ps_eng.pdf`).

### Radio — `src/radio.h`

The AX5043 inside the AX8052F143, used to tell an access point that this tag exists. On boot
`announce()` sends the serial number to the AP three times before the panel refresh starts:

```c
radio_init();                       /* reset, configure, auto-range, calibrate */
radio_tx(pkt, len);                 /* preamble + sync + frame, all in hardware */
```

The radio is reached through a register window in X address space, **not** through the SPI
pins, so it never competes with the NFC chip or the panel for the bus.

**Every register value comes from the vendor's own working configuration**, kept in
`documentation/reference/VusionLink/` — an AXSEM AX-RadioLAB generated table plus the
`easyax5043` SDK driver. The generated header states the link: *868.300 MHz, deviation
1600 Hz, 4800 bit/s, RX bandwidth 7.2 kHz, 15 dBm, 26 MHz TCXO*. The driver applies that table
verbatim and follows the SDK's init sequence, including the VCO auto-ranging and the VCO
current calibration. The reference is a **TCXO** (`XTALOSC = 0x04`), which matters: with
crystal-mode settings the AX5043's `XTALSTATUS` never reports the clock running.

An earlier version of this driver derived its own physical layer from the AX5043 programming
manual's formulas instead (868.000 MHz, 8125 bit/s). It compiled and ran but never worked on
hardware — the manual does not publish the receiver's filter, IF, AGC or tracking-loop values,
because RadioLAB is expected to compute them.

The link, the frame format and the bring-up checklist are in
[`documentation/shelfkit-radio-link.md`](../../documentation/shelfkit-radio-link.md). The
access point carries the same `radio.c`/`radio.h`, and the two copies must stay identical.

`radio_init()` returns `0` on success and a code otherwise — `main()` prints it together with
a register-level diagnostic dump from `radio_diag()`.

### The link layer — `src/sk_link.c`, `sk_link.h`

Everything above the radio: the frame's header and CRC-16, the compact address derived from
this tag's serial, managed flooding, the record route, and whether this tag relays at all.
`documentation/mesh.md` is the reference; `firmware/shared/include/shelfkit_proto.h` has the
byte layout next to the application protocol it wraps. The access point carries a
byte-identical copy of `sk_link.c` (`tools/tests/sk_link_test.c` asserts that, and the same
for `radio.c`/`radio.h`).

**A tag is a leaf or a router, and that is a build-time choice:**

```powershell
# a battery label: never relays, and its idle state is wake-on-radio (the default)
powershell -File tools/build_firmware.ps1 -Firmware shelfkit-vusion

# a mains-powered label: stays in continuous receive and relays other tags' traffic
powershell -File tools/build_firmware.ps1 -Firmware shelfkit-vusion -Define SK_TAG_ROUTER=1
```

A leaf announces itself every 60 s and sleeps in wake-on-radio in between; a router announces
every 10 s and relays. The boot log says which this build is, and prints the tag's link id:

```
radio: id E5C0F240 (leaf)
radio: announced 1408F525 (as the id above)
...
radio: listening (leaf, wake-on-radio)
```

That id is `FNV-1a/32` of the serial number and is what the access point addresses frames to,
so a mismatch between it and what the access point computes looks exactly like dead hardware.
The announcement line carries the serial for the same reason: the access point's console shows
the serial it received, and a mismatch between the two is the first thing to rule out.

### UART — `src/uart.h`

UART0 is TX-only on this board and carries the tag's **console**: everything the tag does,
from the NFC read at boot to the last page of an image transfer. `TAG_TRACE` (top of `main.c`)
sets how much of it there is:

| Level | What it prints |
|---|---|
| 0 | the boot report and the transfer milestones |
| 1 (default) | plus a line per block accepted, per flash page written, and per refusal — and a summary at the end of a transfer |
| 2 | plus every answer transmitted and every frame the link layer hands up |

```
powershell -File tools/build_firmware.ps1 -Firmware shelfkit-vusion -Define TAG_TRACE=2
```

Level 1 costs about 118 block lines and 44 page lines per image (roughly a second of UART
against a transfer that takes ~35), and each line delays that block's acknowledgement by about
10 ms — nothing against the access point's 600 ms window. The tag's console and the access
point's are written to be read together: the access point says what it sent and whether
anything came back, and the tag says whether the frame arrived and what it did with it.

**The console is not a dependency.** `uart_putc()` bounds its wait for `U0TXEMPTY`
(`UART_TX_SPIN`, ~45x the time a byte takes at 38400 baud) and, after `UART_TX_DEAD` timeouts,
writes the port off: every later byte is dropped without waiting. Nothing in the boot path is
allowed to be gated on serial output — the NFC read, the announcement, the panel refresh and
the receive loop all happen whether or not anything is listening. Without the bound, a tag
whose UART is unclocked, whose pad never took the U0TX function, or whose baud register is
left at zero would stop on its first banner byte: a label that looks dead because its serial
port is. The bound also caps what the trace can cost — 40 lines cannot become 40 waits.

`uart_begin()` is libmf's `uart_timer0_baud()` + `uart0_init()` **inlined** (38400 8N1, TX on
PB4, timer 0 generating the rate). Two reasons, both about RAM:

* libmf's versions live in object files that also contain the buffered UART and UART1's ring
  buffers;
* `<libmfuart0.h>`/`<libmfuart1.h>` declare `uart0_irq()`/`uart1_irq()` as `__interrupt`
  handlers, and SDCC emits the interrupt vector for a *declaration* — which links all of the
  above into any firmware that includes the header. `hal.h` therefore deliberately does not
  include them any more.

This part has 128 bytes of directly addressable internal RAM, and SDCC spends it on statics
*and* on one permanent parameter block per non-reentrant function. Hence two house rules in
this project: buffers go in XRAM, and API functions with parameters are declared
`__reentrant` (SDCC then passes parameters on the stack). Together they are what makes the
e-paper, the NFC driver, the radio and the image transfer fit in one image with 137 bytes of
stack left. (The two console/bus flags added by the bounded waits are in XRAM for the same
reason: internal RAM belongs to the stack.)

The image transfer is what makes the rule bite: adding the receive handlers to `main.c` once
failed to link with `?ASlink-Error-Could not get 21 consecutive bytes in internal RAM for area
OSEG`, which is SDCC saying its parameter/local area is full. Marking the new functions
`__reentrant` moved those blocks onto the stack and *increased* the free stack from 132 to 142
bytes at the same time.

### Serial flash — `src/flash.h`

Thin 25-series SPI NOR driver. Reading is `extflash_release_powerdown()`,
`extflash_read_jedec_id()` and `extflash_read()`; writing adds
`extflash_write_enable()`, `extflash_sector_erase()` (4 KiB), `extflash_page_program()` (256
bytes), `extflash_wait_ready()` (polls status bit 0 with a timeout) and `extflash_verify()`
(reads the page back and compares it byte for byte). `extflash_write()` is the convenience
wrapper that splits a buffer at page boundaries, because a program that runs past a page end
wraps back to the start of the same page and would silently overwrite what was just written.

The dump size lives in `FLASH_SIZE` (default 128 KiB for the suspected
1 Mbit chip; the JEDEC capacity byte tells the truth). The boot firmware prints the JEDEC ID
and a full hexdump of the chip on UART0 at 38400 8N1 (TX = PB4); `tools/flashdump.py`
resets the board (boot pin via DTR, reset via RTS, same wiring as `tools/axsem-flasher.py`)
and saves the stream to a file. Use `--bootloader` to reset into the serial bootloader
instead.

### E-paper — `src/epd.h`

Driver for the GDEW026Z39 (IL0373), driven **rotated — 152 wide × 296 tall** — the same
orientation the stock tag firmware uses. It relies on the panel's built-in OTP LUT, so no
waveform tables are needed.

A full frame is two 5624-byte planes (black/white and red), which together exceed the 8 KB
of XRAM. The API therefore streams the frame in two halves, reusing one buffer:

```c
#include "spi.h"
#include "epd.h"

uint8_t __xdata buf[EPD_PLANE_BYTES];   /* 5624 bytes; 0 = ink, 1 = white */

spi_init();                             /* call after periph_init() */
epd_init();                             /* resets the panel, clears it to white */

epd_plane_ink(buf, 10, 10);             /* bit 0 = ink, MSB = leftmost pixel */
epd_upload(0x10, buf, EPD_PLANE_BYTES); /* black/white plane */

/* refill buf with the red plane (bit 0 = red ink) and send it */
epd_upload(0x13, buf, EPD_PLANE_BYTES);

epd_refresh();                          /* starts the update, waits for BUSY */
epd_sleep();                            /* panel deep sleep */
```

`epd_clear(0xFF, 0xFF)` wipes the screen white without any buffer; static images can live in
`const` (flash) and be passed straight to `epd_upload()`.

A plane that is *not* in RAM is pushed in chunks instead: `epd_stream_begin(cmd)` sends the
data command and switches the controller to data mode, `epd_stream_data(buf, len)` pushes one
chunk, and either may be repeated as many times as the caller likes before `epd_refresh()`.
The panel's CS is released between chunks (each call is its own SPI transaction) so the SPI
flash can be read in between - which is exactly what the image path does, one 256-byte chunk
at a time. `epd_upload()` is now `epd_stream_begin()` + one `epd_stream_data()`, so nothing
about the boot image changed.

### Boot image

`main.c` shows `polyform-eink.png` on boot. The image was converted to the two 1-bit
planes in `src/epd_image.c` by:

```
python tools/png2epd.py polyform-eink.png --dither
```

The converter composites transparency over white, quantizes to black/white/red
(optionally with Floyd-Steinberg dithering) and rotates the image to the panel's mounted
orientation. If the logo shows up sideways on the tag, regenerate with a different
`--rotate` (0/90/180/270; 90 = image's left edge on top).

Two hardware notes that will matter on first bring-up:

- **PB5 is shared: panel reset and UART RX.** `main.c` drives the reset as an ordinary
  output (`DIRB` bit 5) and `uart_begin()` leaves the receiver enabled, because that is
  libmf's bring-up and the access point does read its UART back. An output pad cannot be
  driven by the receiver, so the reset pulse reaches the panel; the firmware never reads the
  UART, so nothing else happens either. (An earlier note here claimed the UART had to stay
  off for the reset to work. It does not: the tag refreshes its panel with the UART on, which
  is what the boot log shows.)
- **BUSY polarity.** Every driver found for this panel on this tag polls BUSY *low* while
  busy — the tag board inverts the line, although the bare Good Display module is
  active-high. `epd.c` defaults to active-low. If `epd_init()` hangs or updates render
  corrupt, flip `EPD_BUSY_ACTIVE_HIGH` and retry.
- The init bytes and their provenance are written up in `GDEW026Z39-init-reference.md`.

## Known issues and quirks

- **The FRC oscillator calibration wait is the one unbounded wait left in the boot path.**
  `main()` follows the AXSEM bootloader: 128 passes of "set `OSCCALIB`, `enter_standby()`
  until bit 6 says the calibration finished". `enter_standby()` is `PCON |= IDLE`, so if that
  bit never sets — the 20 MHz FRC is slaved to the 32 kHz LPX crystal (`LPXOSCGM`,
  `CLKSRC_LPXOSC`), and a crystal that does not start means no calibration interrupt — the CPU
  sleeps for ever with no output at all, the one failure mode that looks like a completely
  dead board. It is left as the vendor wrote it because the sequence is the chip's clock
  bring-up and changing it needs hardware: the bounded version would busy-poll `OSCCALIB`
  instead of sleeping (a `guard` counter outside `enter_standby()` cannot help — the CPU is
  asleep inside it) and carry on uncalibrated, which costs baud accuracy. Worth doing if a
  board is ever found wedged there.
- **SDCC-MDF vs PowerShell** (extension ≤ 0.29.11): the extension emits single-quoted tool
  paths without the `&` call operator, so with a PowerShell terminal every build fails with
  `Unexpected token '-mmcs' …`. This repo works around it with `"sdcc.shellPath": "cmd.exe"`
  in `.vscode/settings.json` (workspace-scoped). After changing it, reload the VS Code
  window — the extension reuses its existing build terminal.
- **Board definitions are cached** by the extension; after editing `axsem-8051.json`,
  reload the window for the change to take effect.
- The `lib/*.lib` files are SDCC archives built from `libraries/` with the vendor's
  `buildsdcc` makefiles. Only `libmf` is currently linked; the other three are present for
  future drivers.

## Not done yet

- Flash/debug recipe for the AX8052 **debug link** (JTAG-ish AXSEM debug adapter). The serial
  bootloader path behind `SDCC: Flash` does work; the debug link is only needed for
  breakpoints and for recovering a tag whose bootloader is gone.
- Hardware verification of the e-paper driver (init + first frame), settling the BUSY
  polarity question.
- Hardware verification of the NFC read: the serial number should come back from the NDEF URI
  (`serial number: 1408F525  [from the NDEF URI]`), and the dump-free boot should reach the
  panel in ~1 ms of I/O instead of the ~150 ms the old 924-byte EEPROM walk cost. A chip with
  no NDEF record falls back to the UID and says so.
- **Hardware verification of the radio link** with an access point running
  `firmware/access-point`: the tag announces, the AP prints `TAG <serial> rssi=<db>`. The
  bring-up checklist (crystal, band, AFC range) is in `documentation/shelfkit-radio-link.md`.
- **Hardware verification of the image transfer**, end to end: the four things to watch are
  (a) whether the three sector erases and the 44 page programs really take (a part that will
  not take a page is reported as `SK_ST_FLASH`, and the boot log prints which page failed),
  (b) whether the panel really accepts a plane that is pushed in twenty-two chunks with CS
  released in between - if it does not, the picture comes out sheared rather than not at all,
  (c) whether the sender's CRC matches `crc_ccitt_msb()`, and (d) the ~20 s the tag spends on
  the panel refresh during which it answers nothing.
- **The access point's image-transfer side** (`documentation/shelfkit-image-transfer.md`).
  The tag implements its half; the AP still only listens for announcements.
- Identification of the PA2/PA5 transistor lines.
- Repo weight: `libraries/` is ~120 MB, of which only `libraries/libmf/include` is needed
  to build.

## License

The code in `src/` has no license declared yet. The Axsem SDK under `libraries/` and `lib/`
retains its original terms (compiler headers are GPL with a linking exception; the rest is
vendor-licensed) — see the individual files.
