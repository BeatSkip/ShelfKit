# Reference material

## `VusionLink/` — the vendor's own working configuration

An AXSEM/AX-RadioLAB sample project: a master and a slave firmware built on the `easyax5043`
SDK, together with `AX_Radio_Lab_output/config.c` — the **AX-RadioLAB generated register
table**. This is the source of truth for the radio link and the driver is built on it. The
project state (`axradiolabstate.xml`) is included, so the configuration can be reopened in
AX-RadioLAB and regenerated.

Its generated header states the link in one line:

```
// TX: fcarrier=868.300MHz dev=  1.600kHz br=  4.800kBit/s pwr= 15.0dBm
// RX: fcarrier=868.300MHz bw=  7.200kHz br=  4.800kBit/s
```

See [`documentation/shelfkit-radio-link.md`](../shelfkit-radio-link.md) for how ShelfKit uses
it. Note that the sources are CP1252-encoded, not UTF-8 — read them with
`Get-Content -Encoding Default` on Windows, or tools will reject them.

## The AX5043 research notes

Two documents produced while working out how to program the AX5043 from the programming manual
alone (ON Semi AND9347/D). They are kept because they quote the manual's formulas and register
tables verbatim — the PDF's typesetting garbles them beyond what `pdftotext` recovers.

**They describe a physical layer that was abandoned.** They assume 9600 bit/s, h = 2 and the
chip's hardware CRC on; an attempt was then made to derive a link from the chip's reset values
(868.000 MHz, 8125 bit/s), which compiled, ran, and never worked on hardware. What actually
runs is the RadioLAB configuration above. Treat these two documents as manual quotations, not
as a design.

- `ax5043_tx_synth_packet_reference.md` — transmitter, synthesizer, packet controller and FIFO
  framing, plus the frequency/rate/deviation formulas.
- `AX5043_RX_reference_868MHz_9600_FSK2.md` — receiver chain: decimation, data rate, the
  tracking loops, the four receiver parameter sets, and which values the manual does *not*
  give (it defers those to AX_RadioLab).
