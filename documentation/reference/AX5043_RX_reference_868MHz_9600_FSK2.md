# AX5043 receiver register reference — 868.000 MHz, plain FSK h = 2, 9600 bit/s, fXTAL = 26 MHz

Source of record: `C:\Users\Beatskip\AppData\Local\Temp\radio\AX5043PM.txt` = ON Semiconductor **AND9347/D Rev 4** ("AX5043 Programming Manual").
Cross-checks are marked: **[DS]** = `AX5043-D.txt` (AX5043 datasheet), **[EXT]** = two published third-party implementations of these same formulas (see "Formula verification" at the end). Page numbers are the manual's printed page numbers as they appear in the extracted text.

**Conventions used below**

* "verbatim" quotes are copied exactly as they appear in the extracted text, *including* the pdftotext damage to fractions (`+` for `=`, `ƪ…ƫ` for `⌊…⌋`, `p` for `f`, superscripts split onto their own line). Where the OCR order of a stacked fraction is ambiguous I say so and resolve it against the chip's own reset values and the cross-checks.
* Values under "concrete value" are for **fXTAL = 26 MHz, XTALDIV = 2, BITRATE = 9600, h = 2** and **parameter set 0**.

## 0. Link constants (all manual-grounded)

| Quantity | Value | Source |
|---|---|---|
| fXTAL | 26 MHz | given |
| XTALDIV | **2** | Table 199 (p.74), addr `0xF35`: "Set to 0x10 for reference frequencies (crystal or TCXO) less than 24.8 MHz (fXTALDIV = 1), or to 0x11 otherwise (fXTALDIV = 2)" → for 26 MHz write `0xF35 = 0x11`; `PLLVCODIV.REFDIV` (0x032, Table 73) = `01` gives f_PD = fXTAL/2 |
| fDEV | 9600 Hz = 0.5·h·BITRATE = 0.5·2·9600 | Table 20 (p.13): "32 > h ≥ 0.5 for FSK, 4−FSK or AFSK, fdeviation = 0.5 * h * BITRATE" |
| Occupied / main-lobe BW | (1+h)·BITRATE = 3·9600 = **28 800 Hz** | [DS] Table 22 p.20: "FSK/MSK/GFSK/GMSK … BW = (1 + h) ⋅BITRATE" |
| MODULATION (0x010) | `1000` = FSK | Table 36 (p.36) |
| FRAMING (0x012) | **0x16** | Table 39/40/41 (p.38): FABORT b0=0, FRMMODE b3:1 = `011` "Raw, Pattern Match" (=0x06), CRCMODE b6:4 = `001` "CCITT (16 bit)" (=0x10) |

## 1. Register summary for this link (parameter set 0)

| Addr | Register | Bits (fields) | Reset | Manual formula / recommendation | Value here |
|---|---|---|---|---|---|
| 0x100 | IFFREQ1 | IFFREQ (15:8) | 0x13 | formula (garbled, see 2.1); "Please use the AX_RadioLab software to calculate the optimum IF frequency" | **0x05** (see 2.1) |
| 0x101 | IFFREQ0 | IFFREQ (7:0) | 0x27 | idem (IFFREQ = 0x1327 in PM; **0x1127** in [DS] register map — discrepancy) | **0x55** |
| 0x102 | DECIMATION | −, DECIMATION (6:0); b7 reserved | 0x0D | formula (2.2); "The value 0 is illegal." | **0x06** (see 2.2) |
| 0x103 | RXDATARATE2 | RXDATARATE (23:16) | 0x00 | formula (2.3) | **0x00** |
| 0x104 | RXDATARATE1 | RXDATARATE (15:8) | 0x3D | " | **0x70** |
| 0x105 | RXDATARATE0 | RXDATARATE (7:0) | 0x8A | " | **0xD9** |
| 0x106 | MAXDROFFSET2 | MAXDROFFSET (23:16) | 0x00 | formula (2.4) + explicit recommendation (2.4) | **0x00** (recommended) or 0x00 if ±1 % used |
| 0x107 | MAXDROFFSET1 | MAXDROFFSET (15:8) | 0x00 | " | **0x00** (or 0x01) |
| 0x108 | MAXDROFFSET0 | MAXDROFFSET (7:0) | 0x9E | " | **0x00** (or 0x21) |
| 0x109 | MAXRFOFFSET2 | FREQOFFSCORR (23)=b7, b6:4 reserved, MAXRFOFFSET(19:16)=b3:0 | 0x00 | formula (2.5); "Set it to the maximum frequency offset between Transmitter and Receiver." | **0x01** (+0x80 if AFC at 1st LO) |
| 0x10A | MAXRFOFFSET1 | MAXRFOFFSET (15:8) | 0x16 | " | **0x2E** |
| 0x10B | MAXRFOFFSET0 | MAXRFOFFSET (7:0) | 0x87 | " | **0xE7** |
| 0x120 | AGCGAIN0 | AGCDECAY0 (7:4), AGCATTACK0 (3:0) | 0xB4 | f3dB formula (2.6) + explicit recommendation (2.6) | **0x74** (decay 7, attack 4) |
| 0x121 | AGCTARGET0 | AGCTARGET0 (7:0) | 0x76 | target = 2^(AGCTARGETx/16) (2.7); **no recommended value in manual** | reset 0x76 → magnitude 166 (see 2.7) |
| 0x122 | AGCAHYST0 | b7:3 reserved, AGCAHYST0 (2:0) | 0x00 | range = (AGCAHYSTx+1)·3 dB; **no recommended value** | 0x00 |
| 0x123 | AGCMINMAX0 | b7 res, AGCMAXDA0 (6:4), b3 res, AGCMINDA0 (2:0) | 0x00 | behaviour text only (2.8); **no numeric recommendation** | 0x00 |
| 0x124 | TIMEGAIN0 | TIMEGAIN0M (7:4), TIMEGAIN0E (3:0) | 0xF8 | formula (2.9): M,E = arg min \|RXDATARATE/TMGCORRFRAC − M·2^E\|, "TMGCORRFRAC should be chosen at least 4" | **0x7A** (M=7,E=10 → 7168 ≈ 28889/4) |
| 0x125 | DRGAIN0 | DRGAIN0M (7:4), DRGAIN0E (3:0) | 0xF2 | formula (2.10), "DRGCORRFRAC should be chosen at least 64" | **0xE5** (M=14,E=5 → 448 ≈ 28889/64); 0xE3 if DRGCORRFRAC=256 |
| 0x126 | PHASEGAIN0 | FILTERIDX0 (7:6), b5:4 reserved, PHASEGAIN0 (3:0) | 0xC3 | "This register does not normally need to be changed." (=FILTERIDX 11, PHASEGAIN 0011) | **0xC3** |
| 0x127 | FREQGAINA0 | FREQLIM0(7), FREQMODULO0(6), FREQHALFMOD0(5), FREQAMPLGATE0(4), FREQGAINA0(3:0) | 0x0F | "Set FREQGAINA0 = 15 and FREQGAINB0 = 31 to completely disable the baseband frequency recovery loop" | **0x0F** (=15; disabling value) |
| 0x128 | FREQGAINB0 | FREQFREEZE0(7), FREQAVG0(6), b5 res, FREQGAINB0(4:0) | 0x1F | idem | **0x1F** (=31; disabling value) |
| 0x129 | FREQGAINC0 | b7:5 res, FREQGAINC0 (4:0) | 0x0A | "Set FREQGAINC0 = 31 and FREQGAIND0 = 31 to completely disable the RF frequency recovery loop" | **0x0A** (no formula; disable = 0x1F) |
| 0x12A | FREQGAIND0 | RFFREQFREEZE0(7), b6:5 res, FREQGAIND0(4:0) | 0x0A | idem | **0x0A** (disable = 0x1F) |
| 0x12B | AMPLGAIN0 (called AMPLITUDEGAIN0 in the task) | AMPLAVG0(7), AMPLAGC0(6), b5:4 res, AMPLGAIN0(3:0) | 0x46 | "This register does not normally need to be changed." | **0x46** |
| 0x12C | FREQDEV10 (=FREQDEV (11:8)) | b7:4 reserved, FREQDEV0 (11:8) | 0x00 | formula garbled, ambiguous (2.11); enable only later | 0x00 or 0x01 (see 2.11) |
| 0x12D | FREQDEV00 (=FREQDEV (7:0)) | FREQDEV0 (7:0) | 0x20 | " | 0x00 (manual's "enable later" advice) / 0xCD (formula reading A) |
| 0x22C | RSSIREFERENCE | RSSIREFERENCE (7:0) | 0x00 | "adds a constant offset to the computed RSSI value … to compensate for board effects" — **no formula** | 0x00 |
| 0x22D | RSSIABSTHR | RSSIABSTHR (7:0) | 0x00 | threshold only — **no formula, no recommended value** | 0x00 |
| 0x22E | BGNDRSSIGAIN | b7:4 reserved, BGNDRSSIGAIN (3:0) | 0x00 | update law given (2.12) — **no recommended value** | 0x00 |
| 0x22F | BGNDRSSITHR | b7:6 reserved, BGNDRSSITHR (5:0) | 0x00 | threshold only — **no formula, no recommended value** | 0x00 |
| 0x223 | TMGRXBOOST | TMGRXBOOSTE (7:5), TMGRXBOOSTM (4:0) | 0x32 | time = M·2^E μs — **no recommended value** | 0x32 → 18·2¹ = 36 μs |
| 0x224 | TMGRXSETTLE | TMGRXSETTLEE (7:5), TMGRXSETTLEM (4:0) | 0x14 | time = M·2^E μs — **no recommended value** | 0x14 → 20 μs |
| 0x225 | TMGRXOFFSACQ | TMGRXOFFSACQE (7:5), TMGRXOFFSACQM (4:0) | 0x73 | time = M·2^E μs — **no recommended value** | 0x73 → 19·2³ = 152 μs |
| 0x226 | TMGRXCOARSEAGC | TMGRXCOARSEAGCE (7:5), TMGRXCOARSEAGCM (4:0) | 0x39 | time = M·2^E μs — **no recommended value** | 0x39 → 25·2¹ = 50 μs |
| 0x227 | TMGRXAGC | TMGRXAGCE (7:5), TMGRXAGCM (4:0) | 0x00 | time = M·2^E, units set by PKTMISCFLAGS.RXAGCCLK (0 = 1 μs, 1 = bit) — **no recommended value** | 0x00 → 0 |
| 0x228 | TMGRXRSSI | TMGRXRSSIE (7:5), TMGRXRSSIM (4:0) | 0x00 | time = M·2^E, units set by PKTMISCFLAGS.RXRSSICLK — **no recommended value** | 0x00 → 0 |
| 0x229 | TMGRXPREAMBLE1 | E (7:5), M (4:0) | 0x00 | timeout = M·2^E **Bits** — **no recommended value** | 0x00 (0 bits = no timeout) |
| 0x22A | TMGRXPREAMBLE2 | E (7:5), M (4:0) | 0x00 | idem | 0x00 |
| 0x22B | TMGRXPREAMBLE3 | E (7:5), M (4:0) | 0x00 | idem | 0x00 |

Also needed (not in the requested list, but part of the same link config): `RXPARAMSETS` (0x117) = **0xF4**, `PKTMISCFLAGS` (0x231) = 0x00 (keep clocks at 1 μs), and the performance-tuning registers in §4.

## 2. Per-register formulas, verbatim fragments, and arithmetic

### 2.1 IFFREQ1/IFFREQ0 (0x100/0x101, 16 bits)
Verbatim (Table 94, p.49):
> "IF Frequency; IFFREQ + ƪp IF p XTALDIV / p XTAL … 2 20 ) 1 2 ƫ"
> "Please use the AX_RadioLab software to calculate the optimum IF frequency for given physical layer parameters."

The stacked-fraction order is damaged; the reading consistent with the chip's register scaling, with [EXT] and with the datasheet's own offset scaling is
**IFFREQ = ⌊ f_IF · XTALDIV / fXTAL · 2²⁰ + ½⌋**; the LSB is fXTAL/(2²⁰·XTALDIV) = 26e6/(1048576·2) = 12.4 Hz.
**The manual gives no numeric recommendation** — only the formula and the AX_RadioLab instruction. Constraints: f_IF must be high enough that the spectrum does not fold at DC, i.e. f_IF ≥ (occupied BW)/2 = **14 400 Hz** here; the chip's reset config uses f_IF = 4903·26 MHz/(2·2²⁰) = 60.8 kHz.
[EXT] conventions: f_IF = BW_nominal/2 = 16 923 Hz → IFFREQ = ⌊16923·2·2²⁰/26e6 + ½⌋ = 1365 = **0x0555**; f_IF = f_baseband/6 = 22 569 Hz → 1821 = **0x071D**. Either is a *starting* value only; RadioLab decides (per the manual).

Reset discrepancy: PM register map (Table 22, p.24) and Table 94 both say **0x1327**; [DS] register map says **0x1127**.

### 2.2 DECIMATION (0x102, bits 6:0)
Verbatim (Table 95, p.49):
> "Filter Decimation factor; Filter Output runs at [fBASEBAND · 4 =] p XTAL / 2 p XTALDIV DECIMATION"
> "The value 0 is illegal."

The next sentence in [DS] (Table 19) is: "DECIMATION — This register programs the bandwidth of the digital channel filter."
Channel-filter bandwidth (Table 116, p.56, NOTE 1):
> "NOTE: 1. Fractional Filter Bandwidth — The relative bandwidths in the table above need to be multiplied with p XTAL / 2 16 p XTALDIV DECIMATION to get the bandwidth in Hz."

| FILTERIDXx | −3dB | nominal | −10dB | −40dB |
|---|---|---|---|---|
| 00 | 0.121399 | 0.150000 | 0.174805 | 0.256653 |
| 01 | 0.149475 | 0.177845 | 0.202759 | 0.284729 |
| 10 | 0.182373 | 0.210858 | 0.235718 | 0.317566 |
| **11 (default)** | **0.221497** | **0.250000** | 0.274780 | 0.356812 |

**The extracted denominator reads "2 16", which cannot be right**: it yields sub-Hz bandwidths. The numerically consistent reading — and the one used by both [EXT] implementations and by the chip's own reset set — is **2⁴ = 16**:
`BW = relBW · fXTAL / (16 · XTALDIV · DECIMATION)`, equivalently `f_baseband = fXTAL/(16·XTALDIV·DECIMATION)` and `BW_−3dB = 0.221497·f_baseband`.
Checks: (a) reset values DECIMATION = 13, fXTAL = 16 MHz, XTALDIV = 1, FILTERIDX = 11 → 19.2 kHz nominal for a 10 kbit/s default (coherent); (b) DECIMATION = 1 gives 250 kHz, exactly the main-lobe bandwidth of the chip's 125 kbit/s maximum rate; (c) [EXT] AFSK-1200 config (10.4 kHz) → DECIMATION = 0x18, (G)MSK-9600 (14.4 kHz) → 0x11, both reproduced by the 2⁴ form only.

Value here: required BW = 28 800 Hz. Targeting the −3dB column (FILTERIDX0 = 11):
`DEC = 0.221497·26e6/(16·2·28800) = 5758922/921600 = 6.25 → **0x06**`
(0x07 if the target is the *nominal* column: 0.25·26e6/921600 = 7.05.)
With DEC = 6: f_baseband = 26e6/192 = 135 417 Hz → −3dB 29 994 Hz, nominal 33 854 Hz, −10 dB 37 210 Hz. The manual gives **no recommended DECIMATION value** ("no formula in manual" for *choosing* it) — §3 below and the AX_RadioLab note are all it offers.

### 2.3 RXDATARATE2/1/0 (0x103–0x105, 24 bits)
Verbatim (Table 96, p.50):
> "RXDATARATE + ƪ p XTALDIV … 27 p XTAL / BITRATE DECIMATION ) 1 2 ƫ"
> "RXDATARATE − TIMEGAINx ≥ 212 should be ensured when programming. Otherwise, the hardware does it, but this may cause instability due to asymmetric timing correction."

Reading (confirmed by [EXT] code `((1<<7) * fxtal) / (fxtaldiv * baudrate * decimation)`, which is also what the reset set satisfies):
**RXDATARATE = ⌊ 2⁷ · fXTAL / (XTALDIV · BITRATE · DECIMATION) + ½⌋** ("27" is a damaged "2⁷").
Value here: 128·26e6/(2·9600·6) = 3 328 000 000/115 200 = 28 888.9 → **28 889 = 0x0070D9** → 0x103 = 0x00, 0x104 = 0x70, 0x105 = 0xD9.
Constraint check: 28 889 − TIMEGAIN(7168) = 21 721 ≥ 4096 ✔
(For reference, the chip's reset set is self-consistent: 128·16e6/(1·10000·13) = 15 753.8 → 15 754 = 0x003D8A, i.e. fXTAL = 16 MHz, XTALDIV = 1, BITRATE = 10 kbit/s.)

### 2.4 MAXDROFFSET2/1/0 (0x106–0x108, 24 bits)
Verbatim (Table 97, p.50):
> "The maximum bitrate offset the receiver is able to tolerate can be specified by the parameter BITRATE. The receiver will be able to tolerate a data rate within the range BITRATE ± BITRATE. The downside of increasing BITRATE is that the required preamble length increases. Therefore, BITRATE should only be chosen as large as the transmitters require. If the bitrate offset is less than approximately ±1%, receiver bitrate tracking should be switched off completely by setting MAXDROFFSET to zero, to ensure minimum preamble length."

Formula (fragment "MAXDROFFSET + ƪ p XTALDIV … 27 p XTAL / BITRATE 2 DBITRATE DECIMATION") reads, consistently with [EXT] (`(1<<7)*fxtal*dr_offset/(fxtaldiv*baudrate*baudrate*decimation)`):
**MAXDROFFSET = ⌊ 2⁷ · fXTAL · ΔBITRATE / (XTALDIV · DECIMATION · BITRATE²) + ½⌋** = RXDATARATE·ΔBITRATE/BITRATE.
**Manual's recommended value for this link: 0x000000** (crystal-derived 9600 bit/s on both ends; also §"Recommended Preamble", p.16: a TX/RX data-rate deviation below "approximately 0.1%" means "the data rate acquisition loop should be switched off completely (setting registers MAXDROFFSET0, MAXDROFFSET1 and MAXDROFFSET2 to zero)").
If you must allow exactly ±1 % (±96 bit/s): 28 889·0.01 = 288.9 → 289 = **0x000121** (0x106 = 0x00, 0x107 = 0x01, 0x108 = 0x21).

### 2.5 MAXRFOFFSET2/1/0 (0x109–0x10B, 20 bits + FREQOFFSCORR at bit 23)
Verbatim (Table 98, p.50) — note the extracted numerator reads `p CARRIER`, which cannot be literal (a 20-bit field holding 868 MHz/26 MHz·2²⁴ would overflow); the surrounding prose and [EXT]/[DS] scaling show it must be the **offset**:
> "MAXRFOFFSET + ƪ p CARRIER / p XTAL 2 24 ) 1 2 ƫ … FREQOFFSCORR 23 RW 0 — Correct frequency offset at the first LO if this bit is one; at the second LO if this bit is zero"
> "This register sets the maximum frequency offset the built-in Automatic Frequency Correction (AFC) should handle. Set it to the maximum frequency offset between Transmitter and Receiver. Enlarging this register increases the time needed for the AFC to achieve lock. The AFC can only achieve lock if the transmit signal partially passes through the receiver channel filter. This limits the practically usable range for the AFC circuit to approximately ±1/4 of the Filter Bandwidth. The acquisition and tracking range can be increased by increasing the Receiver Channel Filter Bandwidth, at the expense of slightly reducing the Sensitivity."

**MAXRFOFFSET = ⌊ Δf · 2²⁴ / fXTAL + ½⌋** (DS gives the same fXTAL/2²⁴ scaling for the AFC read-back: "Δf = TRKRFFREQ·fXTAL/2²⁴", datasheet AFC section).
Value here: the manual's own ±BW/4 limit with BW_−3dB = 29 994 Hz → Δf = ±7 499 Hz:
`MAXRFOFFSET = 7499·16777216/26e6 = 4838.6 → 4839 = 0x012E7` → 0x109 = 0x01 (FREQOFFSCORR = 0 → correct at the 2nd LO; add 0x80 for 1st LO), 0x10A = 0x2E, 0x10B = 0xE7.
**Warning grounded in the same paragraph:** ±BW/4 = ±7.5 kHz is the hard AFC limit here. At 868 MHz that is ±8.6 ppm of *total* TX+RX reference error, so two ±20 ppm crystals (±34.7 kHz worst case) cannot be pulled in at this BW; either use tighter references or widen the filter (DECIMATION = 1 gives ±BW/4 ≈ ±45 kHz, at a sensitivity cost).

### 2.6 AGCGAIN0 (0x120; bits 7:4 AGCDECAY0, bits 3:0 AGCATTACK0)
Verbatim (Table 109, p.53):
> "c + cos ǒ 25 p p XTALDIV / p XTAL … p 3dB Ǔ"
> "AGC{ATTACK|DECAY}x + * log 2(1 * c ) Ǹc 2 * 4 c ) 3))"
> "The recommended AGCATTACK setting is f3dB ≅ ΒΙΤRΑΤΕ/10 for ASK, and f3dB ≅ ΒΙΤRΑΤΕ for (G)FSK."
> "The recommended AGCDECAY setting is f3dB ≅ ΒΙΤRΑΤΕ/100 for ASK, and f3dB ≅ ΒΙΤRΑΤΕ/10 for (G)FSK."
> "A value of 0xF in the AGC{ATTACK|DECAY}x disables AGC update. Thus, setting the AGCGAIN0/AGCGAIN1/AGCGAIN2/AGCGAIN3 register to 0xFF completely freezes the AGC."

Reading (identical to [EXT] code `c = cos((1<<5)*PI*f_xtaldiv*f3db/fxtal); gain = -log2(1 - c + sqrt(c*c - 4*c + 3))`):
`c = cos(2⁵·π·XTALDIV·f3dB/fXTAL)`, `AGCx = −log2(1 − c + √(c² − 4c + 3))`.
Value here: prefactor 1/(2⁵·π·XTALDIV/fXTAL) = 26e6/(32π·2) = 129 313 Hz.
* attack target = BITRATE = 9600 Hz → exact formula gives **3.70**; f3dB(3) = 15 244 Hz, f3dB(4) = **7842 Hz** (closest to 9600) → AGCATTACK0 = **4**
* decay target = BITRATE/10 = 960 Hz → formula gives **7.07**; f3dB(7) = **1006 Hz**, f3dB(8) = 504 Hz → AGCDECAY0 = **7**
⇒ **AGCGAIN0 = (7<<4)|4 = 0x74**. (Truncating the exact formula instead of rounding gives attack 3 → 0x73; the manual gives only the target f3dB, not the rounding rule.)

### 2.7 AGCTARGET0 (0x121, 8 bits)
Verbatim (Table 110, p.53): "The target ADC output average magnitude is 2 [AGCTARGETx] / 16" — i.e. **magnitude = 2^(AGCTARGETx/16)**, "Note that the ADC can produce magnitudes from 0…2⁹−1."
**No recommended value in the manual.** Reset 0x76 = 118 → target magnitude 2^(118/16) = 2^7.375 = **166** (of a 511 full scale). [EXT] implementations pick 0x84 (=132 → 304) and 0x89 (=137 → 377) as "≈0.6–0.75 of full scale"; those numbers are *not* from the manual.

### 2.8 AGCAHYST0 (0x122) and AGCMINMAX0 (0x123)
Verbatim (Table 111, p.54): "This field specifies Digital Threshold Range. It is (AGCAHYSTx+1) 3 dB; If set to zero, the analog AGC always follows immediately. Increasing this value gives the AGC controller more leeway delay analog AGC following."
Verbatim (Table 112, p.54): "When the digital AGC attenuation exceeds its maximum value, it is reset to the value given in AGCMAXDAx … This value is given in 3 dB steps. Setting it to AGCAHYSTx causes 'drag' AGC behaviour with minimum analog AGC steps (probably desirable); decreasing it causes less frequent but larger analog AGC steps" / "Setting it to 000 causes 'drag' AGC behaviour with minimum analog AGC steps (probably desirable); increasing it causes less frequent but larger analog AGC steps".
No numeric formulas or recommended magnitudes → keep resets: **AGCAHYST0 = 0x00, AGCMINMAX0 = 0x00** (which is exactly the "drag" combination the manual calls "probably desirable").

### 2.9 TIMEGAIN0 (0x124; M = bits 7:4, E = bits 3:0)
Verbatim (Table 113, p.54–55):
> "TIMEGAINxM, TIMEGAINxE + arg min ŤTMGCORRFRACx / RXDATARATE … * TIMEGAINxM 2 TIMEGAINxE Ť"
> "TMGCORRFRAC should be chosen at least 4. Larger values result in less sampling time jitter, but slower timing lock-in."

Reading (confirmed by [EXT] code `TIMEGAIN0 = gain_dec2exp(rxdatarate / 4)`, and by the chip reset set where 15 754/4 = 3938 → 15·2⁸ = 3840 = 0xF8, the reset value):
**TIMEGAINxM,TIMEGAINxE = arg min over M(1..15),E(0..15) of | RXDATARATE/TMGCORRFRAC − M·2^E |**.
Value here (TMGCORRFRAC = 4): 28 889/4 = 7222.25 → 7·2¹⁰ = 7168 (nearest) → **TIMEGAIN0 = (7<<4)|10 = 0x7A**.
(Note: a broken third-party write-up states this formula with `Bitrate` instead of `RXDATARATE`; the manual's text and the reset values both use RXDATARATE.)

### 2.10 DRGAIN0 (0x125; M = bits 7:4, E = bits 3:0)
Verbatim (Table 114, p.55):
> "DRGAINxM, DRGAINxE + arg min ŤDRGCORRFRACx / RXDATARATE … * DRGAINxM 2 DRGAINxE Ť"
> "DRGCORRFRAC should be chosen at least 64. Larger values result in less estimated datarate jitter, but slower datarate acquisition."

Value here: DRGCORRFRAC = 64 → 28 889/64 = 451.4 → 14·2⁵ = 448 → **DRGAIN0 = (14<<4)|5 = 0xE5**.
(DRGCORRFRAC = 256, the choice implied by the chip's own reset set, gives 112.8 → 14·2³ = 112 → 0xE3.)

### 2.11 FREQDEV10/FREQDEV00 (0x12C/0x12D = FREQDEV0 (11:8)/(7:0), 12 bits)
Verbatim (Table 122, p.58):
> "FREQDEVx + ƪ p DEVIATION 28 / BITRATE … k SF ) 1 2 ƫ … is kSF transmitter shaping and receiver filtering dependent constant. It is usually around ksf ≅ 0.8"
> "Enabling this feature (FREQDEVx 0 0) can lead the frequency offset estimator to lock at the wrong offset. It is therefore recommended to enable it only after the frequency offset estimator is close to the correct offset (i.e. FREQDEV0 = 0)."

The extracted block does **not** let me place kSF unambiguously (three stacked lines: `fDEVIATION 2⁸`, `BITRATE`, `kSF`), and the two candidate readings differ by 1/kSF²:
* reading A `FREQDEVx = ⌊ (fDEVIATION/BITRATE)·kSF·2⁸ + ½⌋` → for h = 2 (fDEV/BITRATE = 1.0): 0.8·256 = 204.8 → **205 = 0x0CD**;
* reading B `FREQDEVx = ⌊ (fDEVIATION/BITRATE)·2⁸/kSF + ½⌋` → 1.0·256/0.8 = **320 = 0x140**.
[EXT] uses a third expression, `2·h·0.8·2⁸` = **410 = 0x19A**. I am therefore **not** asserting a value: this is the one register in the list whose manual formula I cannot pin down from the extracted text. It is also optional — the datasheet says of the TX-side counterpart: "The receiver does not explicitly need to know the frequency deviation, only the channel filter bandwidth has to be set wide enough for the complete modulation to pass." The manual's own advice is to leave it at 0 during acquisition ([EXT] writes 0 to parameter set 0 and the computed value to sets 1–3), so **0x12C = 0x00, 0x12D = 0x00** is the manual-sanctioned starting point; verify any non-zero value against AX_RadioLab.

### 2.12 RSSI registers
* `RSSIREFERENCE` 0x22C (8 bits, reset 0x00): "This register adds a constant offset to the computed RSSI value. It is used to compensate for board effects." — **no formula, no recommended value**.
* `RSSIABSTHR` 0x22D (8 bits, reset 0x00): "RSSI levels above this threshold indicate a busy channel." — **no formula/recommendation**.
* `BGNDRSSIGAIN` 0x22E (bits 3:0, reset 0000): "The background RSSI estimate BGNDRSSI is updated after antenna RSSI measurement … The update is performed as follows: BGNDRSSI = BGNDRSSI + (RSSI − BGNDRSSI) ⋅ 2^−BGNDRSSIGAIN" — **no recommended value**.
* `BGNDRSSITHR` 0x22F (bits 5:0, reset 000000): "RSSI levels more than BGNDRSSITHR above the background RSSI level indicate a busy channel." — **no formula/recommendation**.
(Background-RSSI computation must be enabled with `PKTMISCFLAGS.BGNDRSSI` = bit 2.)

### 2.13 TMGRX* timeout/settling registers (0x223–0x22B)
Verbatim formulas (Tables 169–177, pp.67–68):
* "The Receive PLL Boost Time is TMGRXBOOSTM ⋅ 2^TMGRXBOOSTE μs." (0x223)
* "The Receive PLL (post Boost) Settling Time is TMGRXSETTLEM ⋅ 2^TMGRXSETTLEE μs." (0x224)
* "The Baseband DC Offset Acquisition Time is TMGRXOFFSACQM ⋅ 2^TMGRXOFFSACQE μs." (0x225)
* "The Receive Coarse AGC Time is TMGRXCOARSEAGCM ⋅ 2^TMGRXCOARSEAGCE μs." (0x226)
* "The Receiver AGC Settling Time is TMGRXAGCM ⋅ 2^TMGRXAGCE. Whether this time is measured in Bits or μs is determined by bit RXAGC CLK in register PKTMISCFLAGS." (0x227)
* "The Receiver RSSI Settling Time is TMGRXRSSIM ⋅ 2^TMGRXRSSIE. Whether this time is measured in Bits or μs is determined by bit RXRSSI CLK in register PKTMISCFLAGS." (0x228)
* "The Receiver Preamble 1/2/3 Timeout is TMGRXPREAMBLE1M/2M/3M ⋅ 2^TMGRXPREAMBLE1E/2E/3E Bits." (0x229/0x22A/0x22B)
`PKTMISCFLAGS` (0x231, Table 184): RXRSSICLK b0, RXAGCCLK b1, BGNDRSSI b2, AGCSETTLDET b3, WORMULTIPKT b4; all reset 0 (0 = 1 μs, 1 = bit clock).
**The manual gives no recommended values for any TMGRX\* register** — only the formulas above and the reset values in the table. Preamble duration requirements are discussed qualitatively on pp.15–16 (see §3).

## 3. Explicit answers to the three questions

**1. Is there a recommended default/starting-value table in the manual for these demodulator/tracking registers?**
**No.** The manual contains no "recommended settings"/RadioLab sample table for the 0x100–0x22F receiver parameters; it gives reset values, a few per-register formulas, and repeatedly defers to the tool:
* p.14: "Given these fundamental physical layer parameters, AX_RadioLab should be used to compute the register settings of the AX5043."
* p.49 (IFFREQ): "Please use the AX_RadioLab software to calculate the optimum IF frequency for given physical layer parameters."
* p.12: "It is recommended that suitable parameters are calculated using the AX_RadioLab tool available from Axsem."
* p.73: "Registers with Addresses from 0xF00 to 0xFFF are performance tuning registers. Their optimum values are computed by AX_RadioLab; this section only gives a rough overview of how they should be set. Do not read or write addresses not listed in the table below."

The only table of recommended values the manual actually prints is **Table 199 (p.73–74), for the 0xF00–0xFFF performance-tuning registers** (see §4). The only register-level recommendations for the requested set are prose: AGCATTACK/AGCDECAY f3dB targets, TMGCORRFRAC ≥ 4, DRGCORRFRAC ≥ 64, MAXDROFFSET = 0 when the bitrate offset is below ≈±1 % (≈0.1 % for minimum preamble), FREQGAINA = 15 with FREQGAINB = 31 and FREQGAINC = 31 with FREQGAIND = 31 to disable the respective loops, FREQDEV enabled only after acquisition, and "does not normally need to be changed" for PHASEGAIN/AMPLGAIN.

**2. RXPARAMSETS / RXPARAMCURSET**
Verbatim (Tables 106–108, p.53):
> "RXPS0 1:0 RW 00 — RX Parameter Set Number to be used for initial settling"
> "RXPS1 3:2 RW 00 — RX Parameter Set Number to be used after Pattern 1 matched and before Pattern 0 match"
> "RXPS2 5:4 RW 00 — RX Parameter Set Number to be used after Pattern 0 matched"
> "RXPS3 7:6 RW 00 — RX Parameter Set Number to be used after a packet start has been detected"
> "RXSI 1:0 R − RX Parameter Set Index (determines which RXPS is used)"; "RXSN 3:2 R − RX Parameter Set Number (=RXPS[RXSI (1:0)])"; "RXSI 4 R − Rx Parameter Set Index (special function bit)"
> Table 108: "0XX Normal Function (indirection via RXPS) / 1X0 Coarse AGC / 1X1 Baseband Offset Acquisition"

Purpose (pp.18–19): "In order to allow both fast acquisition to enable short preambles and low steady state noise performance to enable high receiver sensitivity, the receiver supports multiple acquisition and tracking loop parameter sets. When the receiver searches for a transmission signal, it uses wide loop bandwidths. Once it detects a preamble with sufficient probability, it switches to a lower loop bandwidth. Once a frame start is detected, it switches to an even lower loop bandwidth." … "the parameter set number of Figure 13 is not directly used to address the parameter set. Instead, it indexes into register RXPARAMSETS, where the actual parameter set number is read out."
So `RXPARAMSETS` is a 4-entry indirection table (one 2-bit target set number per receiver state) and `RXPARAMCURSET` (read-only) reports the index currently selected (`RXSI`), the resolved set number (`RXSN`), and — when bit 4 of RXSI is set — that the receiver is temporarily using special-purpose parameters (coarse AGC or baseband-offset acquisition).

**Which set is active after reset?** `RXPARAMSETS` reset value is `0x00` → RXPS0…RXPS3 all = 0, so **parameter set 0** is used in every state (0x120–0x12F). `RXPARAMCURSET` is read-only with no defined reset ("−−−−−−−−"). Parameter sets are mapped as set 0 = 0x120–0x12F, set 1 = 0x130–0x13F, set 2 = 0x140–0x14F, set 3 = 0x150–0x15F. For this link's "Raw, Pattern Match" framing (states: initial settling → MATCH1 → MATCH0 → packet), [EXT] writes `RXPARAMSETS = 0xF4` (RXPS0 = 0, RXPS1 = 1, RXPS2 = 3, RXPS3 = 3) — a working, but not manual-recommended, starting point.

**3. Digital channel filter bandwidth**
Set by **`DECIMATION` (0x102, bits 6:0)**, which [DS] describes as "This register programs the bandwidth of the digital channel filter", together with **`FILTERIDXx` (bits 7:6 of `PHASEGAINx`)** which selects the relative bandwidth (−3dB/nominal/−10dB/−40dB) from Table 116.
The manual's formula (Table 116 NOTE 1, quoted in full in §2.2) is `BW = relBW · fXTAL/(2¹⁶·XTALDIV·DECIMATION)` as extracted — see §2.2 for why the workable reading is `fXTAL/(16·XTALDIV·DECIMATION)` (i.e. **BW = relBW · fXTAL/(2⁴ · XTALDIV · DECIMATION)**), which is what both [EXT] implementations and the chip's reset defaults use.
There is **no formula in the manual that relates the filter bandwidth to the bit rate**. The bit rate enters only indirectly: `RXDATARATE` is defined "relative to the channel filter bandwidth" ([DS] Table 19), and because `RXDATARATE = 2⁷·fXTAL/(XTALDIV·DECIMATION·BITRATE)` while `BW = relBW·fXTAL/(16·XTALDIV·DECIMATION)`, the two are rigidly coupled: **RXDATARATE = 2¹¹/(relBW·BITRATE) · BW** (for relBW = 0.25: RXDATARATE = 8192·BW/BITRATE ≈ 0.853·BW at 9600 bit/s). Requirements on BW come from the modulation: the datasheet's main-lobe value `(1+h)·BITRATE` (28 800 Hz here) and the AFC constraint `±BW/4` (p.50).

## 4. Table 199 — the manual's only recommended-values table (0xF00–0xFFF, p.73–74)
Verbatim intro: "Registers with Addresses from 0xF00 to 0xFFF are performance tuning registers. Their optimum values are computed by AX_RadioLab; this section only gives a rough overview of how they should be set. Do not read or write addresses not listed in the table below."

| Addr | Manual's value | For this link (crystal, 26 MHz, 868 MHz, Raw Pattern Match) |
|---|---|---|
| 0xF00 | "Set to 0x0F" | 0x0F |
| 0xF0C | "Keep the default 0x00" | 0x00 |
| 0xF0D | "Set to 0x03" | 0x03 |
| 0xF10 | "Set to 0x04 if a TCXO is used. If a crystal is used, set to 0x0D if the reference frequency … is more than 43 MHz, or to 0x03 otherwise" | **0x03** |
| 0xF11 | "Set to 0x07 if a crystal is connected to CLK16P/CLK16N, or 0x00 if a TCXO is used" | **0x07** (crystal) |
| 0xF1C | "Set to 0x07" | 0x07 |
| 0xF21 | RX "Set to 0x5C" | 0x5C |
| 0xF22 | RX "Set to 0x53" | 0x53 |
| 0xF23 | RX "Set to 0x76" | 0x76 |
| 0xF26 | RX "Set to 0x92" | 0x92 |
| 0xF30–0xF33 | RX "This register should be reset between WOR wake-ups. The reset value is the value read after successful packet reception or 0x3F/0xF0 if no packet has been received yet." | only relevant for wake-on-radio |
| 0xF34 | "Set to 0x28 if RFDIV in register PLLVCODIV is set, or to 0x08 otherwise" | 0x08 (868 MHz, internal VCO, RFDIV off) |
| 0xF35 | "Set to 0x10 for reference frequencies (crystal or TCXO) less than 24.8 MHz (fXTALDIV = 1), or to 0x11 otherwise (fXTALDIV = 2)" | **0x11** |
| 0xF44 | "Set to 0x24" | 0x24 |
| 0xF72 | RX "Set to 0x06 if the framing mode is set to 'Raw, Soft Bits' (register FRAMING), or to 0x00 otherwise" | **0x00** (Raw, Pattern Match) |

## 5. Formula verification (why I trust the readings above)
1. **Chip reset defaults are internally consistent with the readings.** DECIMATION = 13, RXDATARATE = 0x003D8A = 15 754, MAXDROFFSET = 0x00009E = 158, FREQDEV = 0x020, AFSKSPACE = 0x40 = 64, AFSKMARK = 0x75 = 117, TIMEGAIN0 = 0xF8 (=15·2⁸ = 3840), DRGAIN0 = 0xF2 (=15·2² = 60), FILTERIDX = 11. For fXTAL = 16 MHz, XTALDIV = 1, DECIMATION = 13, BITRATE = 10 000: RXDATARATE = 2⁷·16e6/(13·10⁴) = 15 753.8 → 15 754 ✔; MAXDROFFSET = 2⁷·16e6·100/(13·10⁸) = 157.5 → 158 (i.e. ±1 %) ✔; TIMEGAIN0 = argmin|15 754/4 − M·2^E| = 15·2⁸ = 3840 ✔; DRGAIN0 = argmin|15 754/256 − M·2^E| = 15·2² = 60 ✔; AFSKSPACE 64 → 64·16e6/(2¹⁶·13) = 1201 Hz and AFSKMARK 117 → 2197 Hz (the classic 1200/2200 Hz AFSK pair) ✔; and the 2⁴ bandwidth form gives 19.2 kHz nominal for that 10 kbit/s default ✔.
2. **Two independent third-party implementations of the manual's formulas agree with the readings** and were used only as cross-checks, never as the source of register values:
   * Libre Space Foundation AX5043 driver ([gitlab.com/librespacefoundation/ax5043-driver](https://gitlab.com/librespacefoundation/ax5043-driver)): `RXDATARATE = ((1<<7)*fxtal)/(fxtaldiv*baudrate*decimation)`; `MAXDROFFSET = ((1<<7)*fxtal*dr_offset)/(fxtaldiv*baudrate*baudrate*decimation)`, forced to 0 when `dr_offset/baudrate < 0.01`; `MAXRFOFFSET = offset/fxtal*(1<<24) | (freq_offset_corr << 23)`; `f_baseband = fxtal/((1<<4)*fxtaldiv*dec)`, `rx_bw_3db = f_baseband/4.514733` (= 0.221497 × f_baseband, i.e. the manual's FILTERIDX = 11 −3 dB coefficient); `TIMEGAIN0 = argmin|rxdatarate/4 − M·2^E|`; `IFFREQ = (if_freq*fxtaldiv/fxtal)*(1<<20)`; AGC via `cos(2⁵·π·XTALDIV·f3dB/fXTAL)` and `−log2(1 − c + √(c²−4c+3))` with the manual's BITRATE and BITRATE/10 targets.
   * [notblackmagic.com/bitsnpieces/ax5043](https://notblackmagic.com/bitsnpieces/ax5043/) (independent write-up of the same tables, validated against AX-RadioLab output for AFSK-1200 and (G)MSK-9600 on 16 MHz) gives the same 2⁷ RXDATARATE, the same 2⁴ bandwidth relation, the same IFFREQ and MAXRFOFFSET forms, and a full AGC f3dB table. Its TIMEGAIN/DRGAIN formula substitutes `Bitrate` for the manual's `RXDATARATE` and is therefore wrong (it does not reproduce the chip's reset values); I did not use it.
3. **Where the manual's typesetting is unrecoverable** I say so explicitly rather than guessing: the kSF placement in FREQDEV (2.11) is the only such case among the requested registers. The extracted "2 16" in Table 116's bandwidth note is treated as a typo for 2⁴ on the strength of items 1 and 2 above.

### Residual risks for firmware
* IFFREQ, DECIMATION and DRGAIN have **no manual-recommended numbers**; the values given here are the minimum-bandwidth starting point and should be replaced by AX-RadioLab output when available.
* The AFC pull-in range is only ±BW/4 (≈±7.5 kHz with DECIMATION = 6). Two ±20 ppm crystals at 868 MHz need ≈±34.7 kHz, so either widen the filter (lower DECIMATION) or use a TCXO — this is the largest practical risk in the link as specified.
* FREQDEV (2.11): leave at 0 until the frequency-offset estimator has settled, as the manual recommends.
