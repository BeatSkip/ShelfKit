# ShelfKit over-the-air link

How a tag talks to the access point. The register-level reasoning lives in
`firmware/shelfkit-vusion/src/radio.c` (the access point carries the same file); this page is
the working summary: what the link is, where the numbers came from, and what to check when
nothing appears.

## Where the numbers come from

Everything here is taken from the vendor's own working sample project, which is kept in
[`documentation/reference/VusionLink/`](reference/VusionLink/) — an AXSEM **AX-RadioLAB**
generated configuration plus the `easyax5043` SDK driver, with master and slave example
firmware. The file that matters is
[`AX_Radio_Lab_output/config.c`](reference/VusionLink/AX_Radio_Lab_output/config.c), whose
header states the link in one line:

```
// TX: fcarrier=868.300MHz dev=  1.600kHz br=  4.800kBit/s pwr= 15.0dBm
// RX: fcarrier=868.300MHz bw=  7.200kHz br=  4.800kBit/s
```

That generated table is the source of truth for every radio register. This is worth stating
plainly because an earlier version of this driver derived its own physical layer from the
AX5043's reset values and the formulas in the programming manual; that derivation produced a
*different* link (868.000 MHz, 8125 bit/s) and **did not work on hardware**. The manual does
not publish the receiver's channel-filter, IF, AGC or tracking-loop values — RadioLAB computes
them — so deriving them was never going to be reliable. Use the generated table.

## The link

| | |
|---|---|
| Radio | AX5043, integrated in the AX8052F143 |
| Carrier | **868.300 MHz** (channel 0 of six) |
| Modulation | FSK, deviation **1600 Hz**, h = 2/3 |
| Bit rate | **4800 bit/s** |
| Receiver bandwidth | 7.2 kHz |
| Transmit power | 15.0 dBm (`TXPWRCOEFFB` = 0x0FFF) |
| Reference | **26 MHz TCXO** (`XTALOSC` = 0x04, `XTALAMPL` = 0x00, `XTALCAP` = 0x00) |
| Sync word | `93 0B 51 DE` (32 bits), preamble 32 bits of `0xAA` |
| Framing | `FRAMING` = 0x06: raw + pattern match, chip CRC off |
| Encoding | `ENCODING` = 0x00: plain NRZ, no differential encoding |

**The reference is a TCXO, not a crystal.** `XTALOSC = 0x04` with `XTALAMPL = 0x00` and
`XTALCAP = 0x00` is manual table 199's "if a TCXO is used" configuration. This matters more
than it sounds: with crystal-mode settings the AX5043's `XTALSTATUS` never reports the clock
running, so an init sequence that waits for it hangs or times out — which is exactly what
happened on hardware before this was found.

## The channel plan

RadioLAB generated six channels, spaced 25 kHz apart from 868.300 MHz, as pre-computed `FREQA`
words:

| Channel | `FREQA` | Frequency |
|---|---|---|
| 0 | `0x21656A57` | 868.300 MHz |
| 1 | `0x2165A95B` | 868.325 MHz |
| 2 | `0x2165E85F` | 868.350 MHz |
| 3 | `0x21662763` | 868.375 MHz |
| 4 | `0x21666667` | 868.400 MHz |
| 5 | `0x2166A56B` | 868.425 MHz |

ShelfKit uses **channel 0 only**. Using the pre-computed words rather than calculating
`f/fXTAL*2^24` at runtime also removes the long-division code the old driver carried.

## The frame

What actually goes on the air - the link frame's header, its CRC-16, the
addressing, the mesh's flooding rules and its record route - is
[`mesh.md`](mesh.md), with the byte layout also written next to the
application protocol it wraps in
[`firmware/shared/include/shelfkit_proto.h`](../firmware/shared/include/shelfkit_proto.h).

For the record, the vendor reference's own frame (which ShelfKit does **not**
use) is:

```
[ length ][ destination address ][ source address ][ payload ][ CRC-16 ]
   1 byte        4 bytes                                      2 bytes
```

with `length` counting the payload plus 4 (the CRC is excluded because the driver adds
`axradio_framing_swcrclen` to `PKTLENOFFSET` at init), and the CRC being
`crc_crc16_msb(frame, n, 0xFFFF)` appended big-endian. That one is **CRC-16/UMTS (poly
0x8005)** — libmf also ships a CCITT implementation, `crc_ccitt_msb()` (poly 0x1021), and the
names differ by one letter, so it is worth being explicit about which is which. ShelfKit
uses the CCITT one, in the link frame and over the UART.

**ShelfKit keeps its own, simpler application packet on top** and does not implement the
Vusion MAC layer (address filtering, acknowledgements, retries, channel hopping). Both ends
are our own firmware, so the tag and access point only have to agree with each other. The
application payload is defined in
[`firmware/shared/include/shelfkit_proto.h`](../firmware/shared/include/shelfkit_proto.h):
version, packet type, and a type-specific body.

## Initialisation

The driver follows `axradio_init()` from the reference, with polling instead of the SDK's
interrupt-driven state machine:

1. `ax5043_reset()` — reset, check the silicon revision, scratch-register round trip;
2. apply the generated register table;
3. `PLLLOOP = 0x09`, `PLLCPI = 0x08` — 100 kHz loop bandwidth, for ranging;
4. `MODULATION = 0x08`, `FSKDEV = 0`, `PWRMODE = XTAL_ON` (0x05), then wait for
   `XTALSTATUS` bit 0 — **the TCXO settling step the old driver got wrong**;
5. VCO auto-ranging: write `FREQA`, then `PLLRANGINGA = 0x0A | RNGSTART` (VCORA starts at the
   RadioLAB-calibrated 0x0A), wait for `RNGSTART` to clear, keep the resulting range;
6. VCO current calibration (`axradio_adjustvcoi`): sweep `PLLVCOI` ±16 around the calibrated
   `0x99` and keep the value whose VCO tuning voltage, measured through the chip's GPADC, is
   lowest. Then write that current back and **wait for `PLLRANGINGA` bit 6** — the PLL lock
   check, see below;
7. `PWRMODE = POWERDOWN`, re-apply the register table, apply the receiver register set;
8. set `PLLRANGINGA` to the ranged value and `FREQA` to channel 0.

### The PLL lock check, and why step 6 is the only place it can happen

`PLLRANGINGA` bit 6 is documented as "PLL is locked if 1", but it is only true while the
synthesizer is actually running. Everywhere else in the init sequence the chip is in STANDBY
(`PWRMODE` 0x05) or POWERDOWN (0x00) with the VCO unpowered, and bit 6 is 0 *by
construction* — a healthy asleep PLL and a genuinely broken one read identically.

That is why neither the datasheet's ranging flow chart (figure 8) nor the reference driver
checks it during ranging: `easyax5043.c` tests only `RNGERR` there (line 1744). The one
place the vendor reads the lock at all is `axradio_calvcoi()` (line 1632), which runs with
`PWRMODE = SYNTH_TX`.

So the driver does the same: after the VCOI sweep it writes the calibrated current into
`PLLVCOI` — the setting the radio will actually use — and polls bit 6 for up to 100 ms
(`RADIO_TMO_PLL`). A lock failure there is reported as `RADIO_ERR_PLL_LOCK`, because a PLL
that does not lock in SYNTH_TX will not lock in FULLRX either, and the alternative is a
receiver that silently never hears anything.

**The boot log's `PLLRANGINGA` line is a snapshot from this read**, not from step 5. An
earlier version sampled the register once inside the ranging poll loop and printed *that*
value as "PLL locked" / "PLL NOT LOCKED" — so every unit reported `PLL NOT LOCKED`
regardless of its health, because the sample was taken while the VCO was unpowered. The
`VCOI` value in the same line is a useful cross-check: a unit that reports the *uncalibrated*
`0x99` has a dead GPADC (every measurement returned `-1`, so nothing beat the starting
point), whereas a value a few counts either side of it is a real measurement.

Transmitting repeats the pattern the SDK uses: `PWRMODE = XTAL_ON`, then `FIFO_ON`, apply the
transmitter register set, clear the FIFO (`FIFOSTAT = 3`), write the preamble and packet
chunks, and `PWRMODE = FULL_TX`; the driver then polls `RADIOSTATE` until it returns to 0 and
powers the radio down again.

## Changing things

| Want to change | Where |
|---|---|
| Carrier frequency | the `FREQA` word in radio.c — recompute with RadioLAB, do not hand-derive |
| Sync word | `MATCH0PAT` (each byte bit-reversed, `rev8()`) in both firmwares |
| TX power | `RADIO_TXPWR_COEFF` (0x0FFF = the reference's 15 dBm), or -DRADIO_TXPWR_COEFF=... for a bench measurement |
| Preamble length | `RADIO_PREAMBLE_BYTES`, both |
| Wake-on-radio preamble | `RADIO_WOR_PREAMBLE_UNITS` in radio.c — see [`mesh.md`](mesh.md) §7 |
| Bit rate / deviation / filter | **regenerate with AX-RadioLAB** — see below |
| Announcement repeats | `RADIO_ANNOUNCE_REPEATS`/`..._GAP_MS`, tag only |
| Frame layout, CRC, addressing, mesh | `firmware/shared/include/shelfkit_proto.h` + `sk_link.c` — see [`mesh.md`](mesh.md) |

The one thing not to do by hand is change the bit rate, deviation or any receiver parameter:
they are a matched set that RadioLAB computes together (decimation, IF frequency, data rate,
`FSKDEV`, the four receiver parameter sets, gain and timing registers). Editing one value
breaks the set.

## Bring-up checklist

1. **Start from the boot log.** `radio_init()` returns 0 on success; anything else is reported
   with the raw `XTALSTATUS`, `POWSTAT` and `PLLRANGINGA` registers, which is usually enough to
   tell a clock problem from a PLL or VCO problem. If `XTALSTATUS` bit 0 never sets, the
   reference clock is not running — check the TCXO configuration above first, since that was a
   real failure mode here. `PLL NOT LOCKED` on a *successful* line is likewise not a
   measurement: on the success path the lock state is the one read with the synthesizer
   running, and `radio_init()` cannot succeed without it, so treat that text as a
   driver bug if you ever see it rather than a fault.
2. **Band and antenna**: 868 MHz is the EU ISM band. A US variant may want 915 MHz, and the
   antenna matching network decides what actually radiates. The PLL can lock happily on a
   carrier the antenna does not pass.
3. **AFC range**: the reference notes a maximum frequency offset of ±3362 Hz, which is about
   ±3.9 ppm at 868 MHz. Two boards whose references differ by more than that will not
   acquire. If that is what you see, widen the channel filter (in RadioLAB) or fit a better
   reference.
4. **RSSI**: `TAG ... rssi=-NN` is read from the `RSSI` register right after reception; the
   reference's `axradio_phy_rssioffset` is 64 and its `rssireference` is `0xFA + 64`, so the
   raw register needs that offset applied to be a sensible dBm figure.
5. **Both ends the same build**: the tag and access point must carry the *same* `radio.c` and
   `radio.h`; the two copies are meant to be identical and are hash-compared in development.

## What is deliberately not done yet

* No channel hopping — channel 0 only, although the reference's other five channels are
  documented above for when that changes. The access point stays in FULLRX; a battery tag's
  idle state is wake-on-radio ([`mesh.md`](mesh.md) §7).
* No link-layer acknowledgement, LBT, or rate/power adaptation. Reliability is the
  application's (stop-and-wait, one block at a time) and the hop budget is the mesh's
  ([`mesh.md`](mesh.md) §§4-5).
* The tag's transmit power is the reference's 15 dBm, which is a lot for a battery tag — and
  on a bench with the two boards a hand's width apart it is *too much*: see
  [`mesh.md`](mesh.md) §9 before concluding that a test failure is a design failure.
