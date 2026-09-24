# ShelfKit — Access Point

An **AX8052F143 board used as a UART-to-radio adapter** for ShelfKit tags. It does two things,
in one loop:

- **Reports.** It listens on the AX5043 for tag announcements and prints every one of them over
  its serial port:

  ```
  *** ShelfKit access point ***
  radio ready (silicon rev 51)
  listening: 868.300 MHz, FSK
  TAG 1408F525 rssi=-42
  TAG 1408F525 rssi=-41
  ```

  Anything that reads a serial port at 38400 8N1 can consume that: a terminal, `pyserial`, a
  script, a home-automation bridge. The blue LED blinks once per accepted packet.

- **Bridges.** A host sends the framed image-transfer commands of
  [`shelfkit_proto.h`](../shared/include/shelfkit_proto.h) and the access point turns each one
  into the matching radio packet, retries it until the tag acknowledges it, and answers with the
  offset the tag confirmed (`SK_U_ACK`) or a status (`SK_U_STATUS`). One host frame in, one
  answer out — the host is never more than one block ahead of the tag's flash. The end-to-end
  design is in [`documentation/shelfkit-image-transfer.md`](../../documentation/shelfkit-image-transfer.md).

## The host protocol

```
[0xAA][0x55][TYPE][LEN][LEN payload][CRC hi][CRC lo]
```

with the CRC **CRC-16/CCITT-FALSE (poly 0x1021, init 0xFFFF, MSB first)** over `TYPE`, `LEN` and
the payload. Note that libmf carries two CRC-16s whose names are one letter apart and which are
*not* the same check: `crc_ccitt_msb()` is the one this protocol uses; `crc_crc16_msb()` is poly
0x8005. `tools/tests/serial_frame_test.c` pins the check value (0x29B1 for `"123456789"`).

Host → access point: `SK_U_IMG_BEGIN` (`0x01`), `SK_U_IMG_DATA` (`0x02`), `SK_U_IMG_END` (`0x03`).
Access point → host: `SK_U_ACK` (`0x81`, the offset the tag confirmed) or `SK_U_STATUS` (`0x82`,
`[status][detail]`, where `detail` is the access point's own reason — see `LINK_D_*` in
`main.c`). A frame with a bad CRC, an over-long `LEN` or an unknown type is not answered: the
parser resynchronises on the next `0xAA 0x55`, which is what the header specifies.

## The radio link

Every register value is taken from the vendor's own working sample project, kept in
[`documentation/reference/VusionLink/`](../../documentation/reference/VusionLink/) — an AXSEM
AX-RadioLAB generated configuration plus the `easyax5043` SDK driver. Its header states the
link in one line: **868.300 MHz, deviation 1600 Hz, 4800 bit/s, RX bandwidth 7.2 kHz,
15 dBm, 26 MHz TCXO.** The physical layer, the frame format and the reasoning are in
[`documentation/shelfkit-radio-link.md`](../../documentation/shelfkit-radio-link.md).

**The tag and the access point must carry the same `radio.c`/`radio.h`.** The two copies in
this repo are byte-identical, and the driver applies the generated register table verbatim
rather than deriving values by hand — an earlier attempt at deriving them from the programming
manual produced a link that compiled, ran, and never worked.

## Building and flashing

Required: [SDCC](https://sdcc.sourceforge.net/) (tested with 3.6.0) and the
[SDCC-MDF extension](https://marketplace.visualstudio.com/items?itemName=dzantemir.sdcc-mdf)
in VS Code.

1. Open `ShelfKit.code-workspace`.
2. Select `firmware/access-point`, then **Ctrl+Shift+B** (*SDCC: Build*) and *SDCC: Flash*.
   The port comes from the workspace setting `"sdcc.comPort"`. **Build before flashing** — the
   extension deletes stale `firmware.hex`/`.bin` on every build, so flashing an unbuilt tree
   only gets you "Hex file not found".

The build uses ~11 KB of the ~58 KB usable flash, ~740 bytes of the 8 KB of XRAM, and leaves
179 bytes of the internal RAM as stack.

The same build by hand, from `firmware/access-point`:

```powershell
$sdcc  = 'C:\Program Files\SDCC\bin\sdcc.exe'
$flags = @('-mmcs51','--model-small','--iram-size','256','--xram-size','8192','--code-size','59389')
$inc   = @('-I../shared/include','-I../shared/libraries/libmf/include','-I../shared/libraries/libaxdvk2/include')
$srcs  = @('main','board','spi','radio','flash','pwr','uart')   # see the exclude rule below

foreach ($s in $srcs) {
    & $sdcc -c @flags @inc "src/$s.c" -o "build/obj/src/$s.rel"
}

& $sdcc @flags @inc ($srcs | ForEach-Object { "build/obj/src/$_.rel" }) `
    '../shared/lib/libaxdsp.lib' '../shared/lib/libaxdvk2.lib' `
    '../shared/lib/libmf.lib'    '../shared/lib/libmfcrypto.lib' `
    -o 'build/firmware.ihx'

& 'C:\Program Files\SDCC\bin\packihx.exe' 'build/firmware.ihx' |
    Set-Content -Encoding ascii 'build/firmware.hex'
```

`build/firmware.mem` reports the three numbers that matter: the ROM and EXTERNAL RAM sizes and
`Stack starts at: ... with N bytes available`.

## Host tests

`main.c`'s parser and bridge have no MCU dependency, so they are tested on the PC: the test
compiles the real `main.c` against stub headers (`tools/tests/ap_stubs/`) and drives it with a
scripted serial line and a scripted tag.

```powershell
gcc -Wall -Wextra -Wno-unused-function -Wno-unused-parameter `
    -I tools/tests/ap_stubs -I firmware/shared/include `
    -o tools/tests/serial_frame_test.exe tools/tests/serial_frame_test.c
./tools/tests/serial_frame_test.exe
```

## Source layout

| File | Contents |
|---|---|
| `main.c` | boot, banner, the receive loop, `TAG <serial> rssi=<db>` reporting, the serial frame parser, the host↔radio bridge |
| `radio.c/h` | the AX5043 driver — init, auto-ranging, transmit, receive |
| `uart.c/h` | minimal UART0 bring-up at 38400 8N1 on PB4/PB5, TX and polled RX |
| `board.c/h`, `hal.h`, `pwr.c/h` | board pins and the PA2/PA5 transistor lines |
| `spi.c/h`, `flash.c/h` | SPI bus and serial flash (linked but unused so far) |
| `epd.c/h`, `epd_image.c/h` | the tag's e-paper driver, **excluded from this build** |

`sdcc-project.json` excludes `src/epd.c` and `src/epd_image.c`: SDCC links every object file it
is handed, so a ~11 KB boot image would otherwise sit in the AP firmware. The e-paper sources
stay in the tree because they are the tag's, and this project folder started as a copy of it.

## Pin map

| Function | Pin | Notes |
|---|---|---|
| UART0 TX / RX | `PB4` / `PB5` | 38400 8N1; both directions used here (on a tag board PB5 is the panel reset, which is why the tag never listens) |
| LED blue / white / green | `PB7` / `PB0` / `PB6` | active low; blue blinks per packet |
| LED red | `PC4` | active low |
| SPI SCK / MOSI / MISO | `PC1` / `PC2` / `PC3` | unused by the AP |
| CS flash / NFC / EPD | `PC0` / `PB1` / `PA1` | unused by the AP |
| NFC field detect / boot | `PB3` | the flasher uses it as the boot pin |
| Transistor U4 / U5 | `PA5` / `PA2` | driven on at boot (`pwr.c`), function unidentified |

## Notes

- **RAM is the scarce resource on this part**: 128 bytes of directly addressable internal RAM
  for statics *and* function parameter blocks. Two consequences are baked into this project:
  buffers live in XRAM, and the new API functions are declared `__reentrant` so SDCC passes
  their parameters on the stack instead of allocating a permanent parameter block.
- **The UART receiver is polled, not interrupt-driven.** This firmware never sets IE/EA, so
  there is no vector to be woken by; `uart_rx_ready()`/`uart_getc()` in `uart.c` make the same
  two register accesses libmf's own UART0 handler does. The one hazard of polling is that the
  receiver has a single byte of buffering while we are busy transmitting, so `uart_putc()`
  spends its waits draining the receiver into a 64-byte XRAM ring; without it, printing a `TAG`
  line in the middle of a host frame would cost the host that frame.
- **Timing.** `delay(1000)` from libmf is ~1 ms of the 20 MHz core, which is what the retry
  budgets in `main.c` are written in. A radio round trip plus a flash page write is a few
  hundred milliseconds. Two waits are much longer because they cover the *tag's* work rather
  than the air: `IMG_BEGIN` is answered only after the tag has erased three flash sectors
  (~150 ms typically, 3 s hard timeout each, hence the 12 s budget, during which a second
  `IMG_BEGIN` is answered `SK_ST_BUSY` — "already on it", not a refusal), and `IMG_END` only
  after the ~20 s e-paper refresh, hence the 60 s wait. `IMG_END` is the one frame that is sent
  **twice**: if nothing comes back in 2 s the air almost certainly ate it, and sending it again
  while the tag is still in its receive state is what saves the transfer. It is safe because the
  answer is ~20 s away either way — a duplicate that arrives after the tag has taken the frame
  is answered from its stored verdict, not by refreshing the panel again. Never a third time.
- The parser gives up on a half-received frame after ~0.1 s of silence (`SER_IDLE_LIMIT`). That
  is what stops a frame the host abandoned mid-way from being completed with the *next* frame's
  bytes; the constant is only good to a factor of a few, and deliberately sits far from both the
  260 µs between two bytes of a real frame and any host's retry delay.
- **`hal.h` deliberately does not include `libmfuart*.h`.** Those headers declare
  `uart0_irq()`/`uart1_irq()` as `__interrupt` handlers, and SDCC emits the interrupt vector
  for a declaration — which drags libmf's buffered UART and its UART1 ring buffers into the
  link. `uart.c` configures the UART registers directly instead (see its header).
- `radio_init()` returns a code on failure and `main()` stops with the LED dark. It also prints
  a register-level diagnostic from `radio_diag()` — the raw `XTALSTATUS`, `POWSTAT` and
  `PLLRANGINGA` of the failing step — because that is what distinguishes a reference-clock
  problem from a PLL or VCO one when debugging on hardware.
- The receiver stays in FULLRX continuously (7-11 mA on the radio). Wake-on-radio is a later
  feature.

## Not done yet

- No addressing, acknowledgements or channel access for *announcements*: a tag announces, the
  access point listens. An image transfer is addressed by serial in the tag's own filter, but
  the air packets carry no address the radio can use.
- The access point does not queue transfers and cannot serve two hosts at once; a second
  `IMG_BEGIN` supersedes the first.
- No hardware verification of the bridge yet: the end-to-end test needs the tag firmware's
  image-receive path (see the last section of
  [`documentation/shelfkit-image-transfer.md`](../../documentation/shelfkit-image-transfer.md)).
  What *is* verified without hardware is the parser, the CRC and every retry/timeout decision —
  see "Host tests" above.
- Hardware verification of the radio link (see the bring-up checklist in the link doc).
