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

**The tag and the access point must carry the same `radio.c`/`radio.h`** — and now the same
`sk_link.c` too. The two copies in this repo are byte-identical (asserted by
`tools/tests/sk_link_test.c`), and the driver applies the generated register table verbatim
rather than deriving values by hand — an earlier attempt at deriving them from the programming
manual produced a link that compiled, ran, and never worked.

**The frame, the addressing and the mesh** are in
[`documentation/mesh.md`](../../documentation/mesh.md): a CRC-16 over every frame, a 4-byte
node id derived from a serial, managed flooding with a hop budget and a seen-id ring, and a
record route. The access point is a **router**: it stays in continuous receive and relays
other nodes' traffic, and it adds the wake-on-radio preamble only when the peer it is talking
to is not known to be a router (the frame's role flag says).

What that looks like on the console:

```
TAG 1408F525 rssi=-64
   path via F240 (01 hops, 03 left)          <- the tag's frame reached us through a relay
relay msg 00 origin 1408F525 hops 04->03     <- and this is us relaying someone else's
link: duplicate msg 00 origin 534B4150 (our own, handed back by a relay) via F240 (01 hops, 03 left)
```

The `TAG ... rssi=...` line keeps exactly the shape the host tool matches; the path goes on
the line *after* it, because appending to it would silently stop `tools/ap_server.py
--watch` from recognising the tag.

## The console trace

The same UART carries the bridge's own trace, which is the answer to "where did the transfer
stop". `AP_TRACE` (top of `main.c`) sets how much of it there is:

| Level | What it prints |
|---|---|
| 0 | only the banner and `TAG <serial> rssi=<db>` |
| 1 (default) | plus every host frame parsed, every radio frame sent and heard, every retry, and every verdict handed back |
| 2 | plus a heartbeat for each wait window that is running out, and the serial parser's own recovery steps |

```powershell
powershell -File tools/build_firmware.ps1 -Firmware access-point -Define AP_TRACE=2
```

A transfer reads line by line — the host's frame arrived intact, what it was for, what went on
the air, what came back, and what the host was told:

```
ser: rx IMG_BEGIN len 0D crc ok
xfer: BEGIN serial 1408F525 id E5C0F240 total 2BF0 crc 1234
link: tx IMG_BEGIN len 0F dst 00000000 try 1/4 wor
link: heard IMG_ACK len 05 origin E5C0F240 seq 01 rssi=-42
xfer: the tag took the transfer on (offset 0000) - data blocks follow
ser: tx ACK off=0000 st=00 OK
ser: rx IMG_DATA len 62 crc ok
xfer: data @0000 k=60 want=0060
link: tx IMG_DATA len 64 dst E5C0F240 try 1/10
link: heard IMG_ACK len 05 origin E5C0F240 seq 02 rssi=-42
xfer: block @0000 stored, the tag is at 0060
ser: tx ACK off=0060 st=00 OK
...
xfer: END - the tag now flushes its last page, checks the image CRC and refreshes the panel, then answers (up to 2 s of silence is normal)
xfer: complete, the tag confirmed off=2BF0 st=00 OK (stored and displayed)
```

A transfer that dies leaves the same lines up to the point it died. `tools/ap_server.py`
prints all of this as `ap: ...` lines (it resynchronises on the frame sync bytes, and no trace
line can contain `0xAA` or `0x55`), so one command shows both ends:
`python tools/ap_server.py COM8 --monitor`, or `--verbose` during a transfer.
`documentation/shelfkit-image-transfer.md` has the reading guide.

## Building and flashing

Required: [SDCC](https://sdcc.sourceforge.net/) (tested with 3.6.0) and the
[SDCC-MDF extension](https://marketplace.visualstudio.com/items?itemName=dzantemir.sdcc-mdf)
in VS Code.

1. Open `ShelfKit.code-workspace`.
2. Select `firmware/access-point`, then **Ctrl+Shift+B** (*SDCC: Build*) and *SDCC: Flash*.
   The port comes from the workspace setting `"sdcc.comPort"`. **Build before flashing** — the
   extension deletes stale `firmware.hex`/`.bin` on every build, so flashing an unbuilt tree
   only gets you "Hex file not found".

The build uses ~21 KB of the ~58 KB usable flash, ~1.1 KB of the 8 KB of XRAM, and leaves
176 bytes of the internal RAM as stack.

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
scripted serial line and a scripted tag that answers in real link frames.
`tools/run_tests.ps1` builds and runs everything (this test, the link layer's own test, and
the Python tools) in one command; by hand it is:

```powershell
gcc -Wall -Wextra -Wno-unused-function -Wno-unused-parameter `
    -I tools/tests/ap_stubs -I firmware/shared/include `
    -c -o tools/tests/sk_link_host.o firmware/shelfkit-vusion/src/sk_link.c
gcc -Wall -Wextra -Wno-unused-function -Wno-unused-parameter `
    -I tools/tests/ap_stubs -I firmware/shared/include `
    -o tools/tests/serial_frame_test.exe `
    tools/tests/serial_frame_test.c tools/tests/sk_link_host.o
./tools/tests/serial_frame_test.exe
```

(The link layer is compiled from the tag's copy; the two are byte-identical and the link test
asserts that.)

## Source layout

| File | Contents |
|---|---|
| `main.c` | boot, banner, the receive loop, `TAG <serial> rssi=<db>` reporting, the serial frame parser, the host↔radio bridge, the relay/duplicate/path console lines |
| `sk_link.c` / `sk_link.h` | the link layer: frame, CRC-16, addressing, managed flooding, record route (byte-identical to the tag's copy) |
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
- **`IMG_BEGIN` is a broadcast on the air**, so every tag in range hears it and every tag that
  is not the target refuses it with `IMG_STATUS` + `SK_ST_BAD_SERIAL`. Only an answer that can be
  *attributed* to the addressed tag may decide the transfer's fate: an `IMG_STATUS` is matched
  against the target serial from `IMG_BEGIN` (case-insensitively — the tag folds case), and a
  refusal from any other tag is logged and ignored, as is a status too malformed to read a
  serial out of. Without that check a second tag on the bench silently kills transfers to the
  first — `?? STATUS from ABCD1234 (not the target), ignored` is what that looks like in the log.
  `IMG_ACK` needs no such check: only the addressed tag ever sends one.
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
- **`PLL NOT LOCKED` on the `radio ready` line was a bug, now fixed.** The VCO range in
  `PLLRANGINGA` bits 3:0 is still reported, but the lock bits are only read with the
  synthesizer running (`radio_wait_pll_lock()`, called from the VCOI calibration with
  `PWRMODE = SYNTH_TX`). Sampling them earlier, in STANDBY, reported `0` on every unit
  because the VCO is unpowered there. `radio_init()` now also fails with
  `RADIO_ERR_PLL_LOCK` if the PLL does not lock on the calibrated VCO current, so a real
  lock failure is no longer silent.
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
