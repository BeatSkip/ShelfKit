# AX5043 Transmitter / Synthesizer / Packet Controller — register reference for 868 MHz, 9600 bit/s, h=2, Raw+Pattern-Match, CCITT-16

**Primary source:** ON Semiconductor **AND9347/D Rev 4**, *AX5043 Programming Manual* (workspace copy `AX5043PM.txt`).
**Cross-check source:** `AX5043-D.txt` (AX5043 datasheet, register map + AC characteristics) and a byte-identical PDF of the same manual (`AN_20170807125735.pdf`, 75 pp., header "AND9347/D, AX5043 Programming, February 2017 − Rev. 4").
Table and page numbers below are the manual's own (printed page = PDF page).

## 0. How the garbled formulas were resolved (read this before trusting the formula column)

`pdftotext -layout` destroys every formula in this manual. Example, Table 75 (p. 46), exactly as in `AX5043PM.txt`:

```
Frequency;        FREQA +     ƪp CARRIER
                                  p XTAL
                                            2 24 )
                                                     1
                                                     2
                                                        ƫ
```

I re-extracted the same page from the PDF with `pdftotext -bbox-layout` (word coordinates) and `pdftocairo -svg` (vector geometry, fraction bars are stroked 0.51 pt rules and symbol glyphs can be outline-identified). Findings for that cell:

* `p` = italic **f**; `+` = **=**; `ƪ`/`ƫ` = the big opening/closing **brackets** (rectangle-bracket outlines, x = 463.97 and 539.60).
* the character pdftotext printed as `)` at x = 525.37 is outline-identified as a **plus sign** (cross-shaped path).
* the dropped glyph at x = 502.58 (glyph-7-1) is a **multiplication cross (×)**.
* there are **two** stroked rules in the row: x = 468.85→500.37 at y = 556.84 (the fCARRIER / fXTAL fraction bar) and x = 535.58→539.60 at y = 556.84 (a small **1/2** fraction; its "1" sits at y 547–557, its "2" at y 557–566).

So the printed formula is

> **FREQA = [ fCARRIER / fXTAL × 2²⁴ + 1/2 ]**  — i.e. *fCARRIER/fXTAL·2²⁴ rounded to the nearest integer* ("[x + 1/2]" = round-to-nearest, the notation used throughout this manual).

The identical structure was verified on other pages (e.g. p. 60 FSKDEV, p. 62 TXRATE + TXPWRCOEFFA–D: each row carries the same 4.0 pt-wide "+1/2" rule plus a longer rule for its data fraction). **Every formula below is a reconstruction of this kind and is flagged as such; nothing is invented.**

**Independent numeric cross-checks used throughout** (reset values are consistent with a 16 MHz reference and an ~915 MHz default):
`TXRATE` reset 0x0028F6 = 10486 → 10000 bit/s @16 MHz; `FSKDEV` reset 0x000A3D = 2621 → 2500 Hz → h = 0.5; `FREQA` reset 0x3934CCCD = 959761613 → fCARRIER/fXTAL = 57.2066 → 915.3 MHz (datasheet main divider NDIVm = 4.5…66.5, fRF range 800–1050 MHz for RFDIV = 0).

**Target link:** fXTAL = 26 MHz, fCARRIER = 868 MHz, BITRATE = 9600 bit/s, h = 2 (plain FSK, MODULATION = 1000), no Manchester, no scrambler, FRMMODE = Raw/Pattern Match, CRCMODE = CCITT-16.

---

## 1. Conflicts and gaps found in the manual (must-read)

| # | Issue | Manual text / evidence |
|---|---|---|
| 1 | **The task premise "MSB-first = chip default (PKTADDRCFG bit 7 = 0)" contradicts the manual.** Bit 7 is MSB FIRST and **1 = MSB first, 0 = LSB first**; the reset value of 0x200 is `001−0000`, i.e. bit 7 = 0 (**LSB first**). | Table 153 (p. 65): "MSB FIRST 7 RW 0 — When set, each byte is sent MSB first; when cleared, each byte is sent LSB first". Register map 0x200 reset `001−0000`. |
| 2 | **MODCFGP does not exist** in AND9347/D (or in the datasheet). Only **MODCFGF (0x160)** and **MODCFGA (0x164)** are documented. | grep over both texts: no `MODCFGP`. |
| 3 | **XTALOSC does not exist.** Crystal-oscillator registers are XTALCAP (0x184) and XTALSTATUS (0x01D, bit 0 "XTAL RUN … 1 indicates crystal oscillator running and stable"). | Table 48/149/150; register map 0x01D, 0x184. |
| 4 | **POWCTRL1 does not exist.** Power-related registers: PWRMODE (0x002), POWSTAT (0x003), POWSTICKYSTAT (0x004), POWIRQMASK (0x005). | Tables 25–29; register map 0x002–0x005. |
| 5 | **Table 148 (PLLRNGCLK bit values) is corrupt in the document itself**: all eight rows read "000" in the Bits column (verified in the PDF text layer, not just the extracted txt). Only the formulas survive: fPLLRNG = fXTAL/2⁸, /2⁹, /2¹⁰, /2¹¹, /2¹², /2¹³, /2¹⁴, /2¹⁵ in row order (the obvious 000…111 mapping cannot be confirmed from the manual). | Table 148, p. 64. |
| 6 | **Table 129 (MODCFGF FREQSHAPE) appears mis-labelled**: `00` is described as "External Loop Filter", which duplicates the loop-filter wording of Table 70; the surrounding prose (datasheet p. 8) says frequency shaping is "hard (FSK, MSK), or Gaussian (GMSK, GFSK), with selectable BT = 0.3 or BT = 0.5". Quoted verbatim below; treat `00` as hard/no Gaussian shaping for plain FSK. | Table 129, p. 60; datasheet line 1304. |
| 7 | **Table 35 lists `REVRDONE` at bit 0 of MODULATION while also listing MODULATION as bits 3:0** — impossible. The register map shows only MODULATION[3:0] + RX HALFSPEED (bit 4) at 0x010. `REVRDONE`/`REVRDONE` event bits live in RADIOEVENTMASK0/REQ0. | Table 35, p. 36 vs register map 0x010. |
| 8 | **`PKTCHUNKSIZE` reset value 0000 is documented as "invalid"** — it must be programmed (there is no link-specific recommendation in the manual; AX_RadioLab computes it). | Table 183, p. 70. |
| 9 | **ENCODING reset (0x11) is not NRZ.** Table 37 reset `−−−00010`: ENC DIFF = 1, so differential encoding is ON after reset. "Plain FSK, no Manchester, no scrambler" additionally requires clearing differential encoding → write **ENCODING = 0x00** (Table 38: "NRZ INV = 0, DIFF = 0, SCRAM = 0, MANCH = 0"). | Table 37/38, pp. 37–38. |
| 10 | Where the manual has no formula it says so itself: "**It is recommended that suitable parameters are calculated using the AX_RadioLab tool**" (p. 12) and "**Given these fundamental physical layer parameters, AX_RadioLab should be used to compute the register settings of the AX5043**" (p. 14). | pp. 12, 14. |
| 11 | PWRMODE is **not** just bits 3:0 — REFEN (bit 5) and XOEN (bit 6) reset to 1, so the whole byte must be written (FULLTX = 0x6D, not 0x0D). | Table 25 + register map 0x002. |
| 12 | Minor: PM Table 26 (p. 33) says FIFO mode = **0111**; the datasheet's PWRMODE table says 0110. The PM is self-consistent (Table 19 "0111 FIFOON"). | PM pp. 11, 33. |

---

## 2. Answers to the specific questions

### Q1 — Exact frequency-word formula for FREQA/FREQB (does RFDIV or the VCO matter?)

**Raw extraction (Table 75, p. 46):** `Frequency;  FREQA +  ƪp CARRIER / p XTAL 2 24 ) 1 2 ƫ` → **reconstructed:**

> **FREQA = [ fCARRIER / fXTAL × 2²⁴ + 1/2 ]**

(The FREQB description is identical: `FREQB + ƪp CARRIER / p XTAL 2 24 ) 1 2 ƫ`, "See notes of FREQA register.")

* **RFDIV and the VCO do not appear anywhere in the formula.** The only symbols in the formula cell are fCARRIER, fXTAL, 2²⁴ and the rounding "+1/2". RFDIV is documented separately as an output divider only: "**RFDIV 2 RW 0 — RF divider: 0 = no RF divider, 1 = divide RF by 2**" (Table 72, p. 46); the datasheet adds "For operation in the 433 MHz band, the RFDIV bit in the PLLVCODIV register must be programmed" and lists fRF range RFDIV = 1 → 400–525 MHz, RFDIV = 0 → 800–1050 MHz. So for **868 MHz use RFDIV = 0** and FREQA is used exactly as written.
* Consistency checks: the main divider is "NDIVm … Controlled indirectly with register FREQ, 4.5 … 66.5" (datasheet Table 8). FREQA/2²⁴ = fCARRIER/fXTAL: for the reset word 0x3934CCCD this is 57.21 (in range, default ≈ 915.3 MHz @16 MHz); a literal ½ factor would put the same reset word at NDIV = 114.4, **outside the specified maximum** — so the "1/2" is the rounding term, not a scale factor. Datasheet fstep = 0.98 Hz at fxtal = 16 MHz also matches fXTAL/2²⁴ = 0.954 Hz, not 0.477 Hz.
* **Manual notes, verbatim:** "It is not recommended to use an RF frequency that is an integer multiple of the reference frequency, due to stray RF desensitizing the receiver." / "It is strongly recommended to always set bit 0 to avoid spectral tones."
* **Computed for this link:**
  FREQA = round(868 000 000 / 26 000 000 × 16 777 216) = round(33.3846153846 × 16 777 216) = round(**560 100 903.3846**) = **560 100 903 = 0x21627627**
  → FREQA3 = 0x21, FREQA2 = 0x62, FREQA1 = 0x76, FREQA0 = **0x27** (bit 0 = 1 ✓ manual requirement). Resulting carrier 867.9999994 MHz (−0.6 Hz).

### Q2 — Exact TXRATE and FSKDEV formulas

**TXRATE (Table 137, p. 62).** Raw: `Transmit Bitrate, TXRATE + ƪ BITRATE / p XTAL 2 24 ) 1 2 ƫ`. Reconstructed:

> **TXRATE = [ BITRATE / fXTAL × 2²⁴ + 1/2 ]**

Followed by: "In asynchronous wire mode, BITRATE ≤ fXTAL / 32".
**Computed:** TXRATE = round(9600/26 000 000 × 16 777 216) = round(**6194.6644**) = **6195 = 0x001833** → TXRATE2 = 0x00, TXRATE1 = 0x18, TXRATE0 = 0x33 (actual 9600.52 bit/s).

**FSKDEV (Table 130, p. 60).** Raw: `(G)FSK Frequency Deviation; FSKDEV + ƪp DEVIATION / p XTAL 2 24 ) 1 2 ƫ`. Reconstructed:

> **FSKDEV = [ fDEVIATION / fXTAL × 2²⁴ + 1/2 ]**, where the manual states verbatim: "**Note that fDEVIATION is actually half the deviation. The mark frequency is fCARRIER + fDEVIATION, the space frequency is fCARRIER − fDEVIATION**" and (p. 13, Table 20) "**fdeviation = 0.5 * h * BITRATE**".

**Computed:** h = 2 → fDEVIATION = 0.5 × 2 × 9600 = **9600 Hz** (half-deviation; total mark-to-space = 19200 Hz).
FSKDEV = round(9600/26 000 000 × 16 777 216) = round(6194.6644) = **6195 = 0x001833** → FSKDEV2 = 0x00, FSKDEV1 = 0x18, FSKDEV0 = 0x33. Mark = 868.0096 MHz, space = 867.9904 MHz.
*AFSK variant quoted for completeness:* "In AFSK mode, the register has a slightly different definition: FSKDEV = [ 0.858785 × fDEVIATION / fXTAL × 2²⁴ + 1/2 ]". "In FM mode, the register has a different definition" (Table 132, FMSHIFT). Not applicable here.

### Q3 — 2-byte sync word with MATCH1 (pattern match unit)

*The pattern-match unit is a **receiver** function* ("FRMRX … this bit is set when a flag is detected in HDLC [1] mode or when the preamble matches in **Raw Pattern Match** mode", Table 39, p. 38). On the **transmit** side the sync bytes are ordinary payload bytes written to the FIFO; nothing in the manual has the transmitter drive MATCH1.

Verbatim (Tables 163–166, p. 66):
* `MATCH1PAT 15:0 RW 0x0000` — "**Pattern for Match Unit 1; LSB is received first; patterns of length less than 16 must be MSB aligned**"
* `MATCH1LEN 3:0 RW 0000` — "**Pattern Length for Match Unit 1; The length in bits of the pattern is MATCH1LEN + 1**"; `MATCH1RAW 7 RW 0` — "Select whether Match Unit 1 operates on decoded (after Manchester, Descrambler etc.) (if 0), or on raw received bits (if 1)"
* `MATCH1MIN 3:0 RW 0000` — "**A match is signalled if the received bitstream matches the pattern in less than MATCH1MIN positions. This can be used to detect inverted sequences.**"
* `MATCH1MAX 3:0 RW 1111` — "**A match is signalled if the received bitstream matches the pattern in more than MATCH1MAX positions.**"

Required framing/misc settings (all verbatim above/below): FRAMING FRMMODE = **011 "Raw, Pattern Match"**, CRCMODE = **001 "CCITT (16 bit)"**, FABORT = 0 → **FRAMING (0x12) = 0x16**. `MATCH1RAW = 0` (decoded bitstream; valid here because Manchester/scrambler are off). The only mode-specific "misc" note in the manual is for the *other* raw mode: "If FRMMODE is set to Raw, Soft Bits, register F72 must be set to 0x06. **Otherwise, it should be left or set to 0x00**" → for Raw, Pattern Match **F72 = 0x00** (p. 38). **No PKTMISCFLAGS bit is required by pattern-match mode** (all five bits are RSSI/AGC/WOR related — Table 184, p. 70).

**Concrete writes (derivation shown; the manual has *no* worked example and *no* MIN/MAX recommendation):**
16-bit pattern → MATCH1LEN = **0x0F** (length = 15+1 = 16), MATCH1PAT1 = 0x218, MATCH1PAT0 = 0x219.
Following "LSB is received first" (MATCH1PAT bit 0 = first bit on air) and the byte order selected by PKTADDRCFG MSB FIRST:

| PKTADDRCFG bit 7 (on-air order of 0xAB 0xCD) | MATCH1PAT (16-bit) | MATCH1PAT1 (0x218) | MATCH1PAT0 (0x219) | Derivation |
|---|---|---|---|---|
| **1 = MSB first** | **0xB3D5** | **0xB3** | **0xD5** | on-air word 0xABCD (bit-reversed per "LSB received first") → reverse16(0xABCD) = 0xB3D5 |
| **0 = LSB first (the actual reset state)** | **0xCDAB** | **0xCD** | **0xAB** | on-air bytes already LSB-first, so PAT = 0xCDAB (byte 2 in the high half) |

MIN/MAX: reset values `MATCH1MIN = 0x0`, `MATCH1MAX = 0xF` are the only values the manual offers for a full-length pattern. Reading the two verbatim sentences as a count of *matching* positions (match if count > MAX, or count < MIN), MAX = 15 requires all 16 positions to match (exact); the reset MAX of MATCH0, `11111` = 31 for its 32-bit pattern, is consistent with that reading, and MIN = 0 disables the inverted-sequence detector. **This is an interpretation of the quoted text, not a manual statement — the manual publishes no example and no recommended MIN/MAX for a 2-byte sync word.**

### Q4 — Exact FIFO procedure for TRANSMIT

**Flow (manual Figure 9, p. 15, verbatim):** "Set PWRMODE to FULLTX → Enable TCXO if used → **Write Preamble to FIFO → Write Packet to FIFO** → Wait until crystal oscillator is running → **Commit FIFO** → Wait until transmission is done → Set PWRMODE to POWERDOWN". Prose: "The microprocessor first places the chip into FULLTX mode. … The microprocessor can now write the preamble and the actual packet to the FIFO." / "In the transmit case, PWRMODE should first be set to FULLTX. Before writing to the FIFO, the microprocessor must ensure that the SVMODEM bit is high in Register POWSTAT … **The transmitter remains idle until the contents of the FIFO are committed** (unless the FIFO AUTO COMMIT bit is set in Register FIFOSTAT)." (pp. 12, 15). After commit: "the transmitter notices that the FIFO is no longer empty. It then powers up the synthesizer and settles it (registers TMGTXBOOST and TMGTXSETTLE determine the timing). The Preamble and the Packet(s) are then transmitted, followed by the transmitter and synthesizer shut-down." / "The PWRMODE register should stay at FULLTX until the transmission is fully completed."

**Chunk encoding (Table 3, p. 7):** header byte = top 3 bits length code + bottom 5 bits type. `000` no payload, `001` 1 byte, `010` 2 bytes, `011` 3 bytes, `100/101/110` invalid, **`111` "Variable length payload; payload size is encoded in the following length byte … everything after the length byte is included in the length"**.

**Chunk types (Table 4, pp. 8–9):** NOP `0x00`; RSSI `0x31`(R); TXCTRL `0x3C`(T); FREQOFFS `0x52`(R); ANTRSSI2 `0x55`(R); REPEATDATA `0x62`(T, 3-byte payload); TIMER `0x70`(R); RFFREQOFFS `0x73`(R); DATARATE `0x74`(R); ANTRSSI3 `0x75`(R); **DATA `0xE1` (T/R, variable)**; TXPWR `0xFD`(T).

**DATA chunk (Table 15, p. 9), verbatim:**
```
header  1 1 1 0 0 0 0 1   (=0xE1)      then LENGTH byte, then flags byte, then DATA bytes
flags   0 0 UNENC RAW NOCRC RESIDUE PKTEND PKTSTART
```
"**LENGTH includes the flags byte as well as all DATA bytes.**" Flags, verbatim: "Setting **RAW** to one causes the DATA to bypass the framing mode, but still pass through the encoder." / "Setting **UNENC** to one causes the DATA to bypass the framing mode, as well as the encoder, except for inversion. UNENC has priority over RAW." / "Setting **NOCRC** suppresses the generation of the CRC bytes." / "Setting **RESIDUE** allows the transmission of a number of data bits that is not a multiple of eight … The transmitter looks for the highest bit set. This is considered the stop bit. Only bits below the stop bit are transmitted." / "**PKTSTART** and **PKTEND** bits enable the transmission of packets that are larger than the FIFO size. If PKTSTART is set, the radio packet starts at the beginning of the DATA command payload. If PKTEND is set, the radio packet ends at the end of the DATA command payload. If PKTSTART is not set, this command is the continuation of a previous DATA command. If PKTEND is not set, the packet is continued with the next DATA command."
Example given by the manual for a 20-bit preamble (p. 9): `0xE1, 0x04, 0x24, 0xAA, 0xAA, 0x1A` (0x24 = UNENC + RESIDUE).

**Packet length byte — where it comes from:** *there is no transmit-side length-byte insertion documented.* The chunk LENGTH byte above is the FIFO chunk length. PKTLENCFG ("LEN POS — Position of the length byte", "LEN BITS — Number of significant bits in the length byte"), PKTLENOFFSET and PKTMAXLEN are described purely from the receiver's point of view: "**The receiver adds LEN OFFSET to the length byte.** The value of (length byte + LEN OFFSET) counts every byte in the packet after the synchronization pattern, up to and excluding the CRC bytes, but including the length byte." (p. 65). "Size checks are implemented using the PKTLENCFG, PKTLENOFFSET and PKTMAXLEN registers" (p. 10). **Conclusion: for FRMMODE = Raw/Pattern Match you must place your own length byte in the DATA payload if the protocol has one.**

**CRC:** generated by the chip. "The Packet Controller also (optionally) adds cyclic redundancy check bits at the end of the packet…" / "The CRC polynomial can be selected in register FRAMING"; supported: "**CRC-CCITT (16bit): x16 + x12 + x5 + 1 (hexadecimal: 0x1021)**", CRC-16 (16 bit, 0x…), "CRC-32 (32bit): … 0x04C11DB7". "**The CRC is always transmitted MSB first regardless of the MSB first setting of register PKTADDRCFG**". **CRCMODE = 001 selects CCITT-16** (Table 41); CRCINIT (0x14–0x17, 32 bit) reset 0xFFFFFFFF "normally all ones". Setting NOCRC in the DATA flags suppresses CRC generation.

**COMMIT and the FIFO command encodings (Table 64, p. 44):** writing FIFOSTAT (0x28) issues a command in FIFOCMD[5:0]:

| Code | Meaning |
|---|---|
| `000000` (0x00) | No Operation |
| `000001` (0x01) | ASK Coherent |
| `000010` (0x02) | Clear FIFO Error (OVER and UNDER) Flags |
| `000011` (0x03) | Clear FIFO Data and Flags |
| **`000100` (0x04)** | **Commit** |
| `000101` (0x05) | Rollback |
| `000110`,`000111`,`001XXX`,`01XXXX`,`1XXXXX` | Invalid |

"Writing the COMMIT command to the FIFOSTAT register copies the write ahead pointer to the write pointer, thus making the written data visible to the consumer." / "Writing the ROLLBACK command … sets the write ahead pointer to the write pointer, thus discarding data written to the FIFO." FIFO AUTO COMMIT (bit 7, RW, reset 0): "If one, FIFO write bytes are automatically commited on every write." FIFODATA (0x29) is the FIFO port; "when accessing this register, the SPI address pointer is not incremented, allowing for efficient burst accesses."

**Recommended preamble for this link (p. 16):** "Otherwise, use **UNENCODED 01010101**" (= 0x55 bytes with UNENC set / REPEATDATA), "If MSBFIRST in register PKTADDRCFG is set, then the preamble sequences should be reversed" (→ 0xAA bytes for MSB-first). In FEC mode use HDLC flags 01111110; if scrambler/Manchester is enabled send RAW 0x11.

### Q5 — Auto-ranging the VCO

Prose (p. 12): "**Whenever the frequency changes, the synthesizer VCO should be set to the correct range using the built-in auto-ranging. A re-ranging of the VCO is required if the frequency change required is larger than 5 MHz in the 868/915 MHz band or 2.5 MHz in the 433 MHz band. Each individual chip must be auto-ranged.** If both frequency register sets FREQA and FREQB are used, then both frequencies must be auto-ranged by first starting auto-ranging in PLLRANGINGA, waiting for its completion, followed by starting auto-ranging in PLLRANGINGB and waiting for its completion."
"**Before starting the auto-ranging, the appropriate frequency registers (FREQA3, FREQA2, FREQA1 and FREQA0 or FREQB3…0) need to be programmed. Auto-ranging starts at the VCOR (register PLLRANGINGA or PLLRANGINGB) setting; if you already know the approximately correct synthesizer VCO range, you should set VCORA/VCORB to this value prior to starting auto-ranging; this can speed up the ranging process considerably. If you have no prior knowledge about the correct range, set VCORA/VCORB to 8. Starting with VCORA/VCORB < 6 should be avoided, as the initial synthesizer frequency can exceed the maximum frequency specification.**"
"**Hardware clears the RNG START bit automatically as soon as the ranging is finished**; the device may be programmed to deliver an interrupt on resetting of the RNG START bit." / "**Waiting until auto-ranging terminates can be performed by either polling the register PLLRANGINGA or PLLRANGINGB for RNG START to go low, or by enabling the IRQMPLLRNGDONE interrupt in register IRQMASK1.**"
Flow chart (Figure 8, p. 13): Set PWRMODE to STANDBY → enable TCXO if used → wait until crystal oscillator is ready → **Set RNGSTART of PLLRANGINGA/B** → poll `RNGSTART = 1?` → when done check `RNGERR = 1?` (error) → Set PWRMODE to POWERDOWN → disable TCXO if used.

**PLLRANGINGA (0x33) bit fields, Table 74 (p. 46):** VCORA[3:0] RW reset **1000** ("VCO Range; depending on bit FREQSEL of PLLLOOP, VCORA or VCORB is used"); RNG START bit 4 (RS) reset 0 ("Write 1 to start autoranging, bit clears when autoranging done. Autoranging always applies to the VCOR selected by FREQSEL of PLLLOOP"); RNGERR bit 5 (R) ("Set when RNG START transitions from 1 to 0 and the programmed frequency cannot be achieved"); PLL LOCK bit 6 (R) ("PLL is locked if 1"); STICKY LOCK bit 7 (R) ("if 0, PLL lost lock after last read of PLLRANGINGA or PLLRANGINGB register").
**Concrete:** write PLLRANGINGA = **0x08** (VCORA = 8, reset value, FREQSEL = 0 → FREQA), then write **0x18** = VCORA 8 + RNGSTART = 1; poll until bit 4 reads 0; then check bit 5 (RNGERR) and bit 6 (PLL LOCK). PLLRANGINGA **is not** a formula-based value — the manual gives no other recommendation.

### Q6 — "packet received" / "transmission done" interrupts and idle RADIOSTATE

**Transmission done** (manual, p. 15, verbatim): "**The end of the transmission may be determined by polling the register RADIOSTATE until it indicates idle, or by enabling the radio controller interrupt (bit IRQMRADIOCTRL) in register IRQMASK0 and setting the radio controller to signal an interrupt at the end of transmission (bit REVMDONE of register RADIOEVENTMASK0).**"

| Purpose | Bits |
|---|---|
| TX/RX done, IRQ enable | **IRQMRADIOCTRL** — bit 6 of IRQMASK0 (reg 0x007, reset 0x00) → write 0x40 |
| TX/RX done, event enable | **REVMDONE** — bit 0 of RADIOEVENTMASK0 (reg 0x009, reset 0x00) → write 0x01. (REVMSETTLED bit 1, REVMRADIOSTATECHG bit 2, REVMRXPARAMSETCHG bit 3, REVMFRAMECLK bit 4) |
| TX/RX done, pending (read) | **IRQRRADIOCTRL** bit 6 of IRQREQUEST0 (0x00D); **REVRDONE** bit 0 of RADIOEVENTREQ0 (0x00F, "Transmit or Receive Done Radio Event Pending", cleared by reading) |
| Packet received | **FIFO not empty**: FIFOSTAT (0x28) FIFO EMPTY bit 0 = 0 / IRQMFIFONOTEMPTY bit 0 of IRQMASK0 (0x007) / IRQRQFIFONOTEMPTY bit 0 of IRQREQUEST0 (0x00D). Manual: receiver flow chart tests "Packet Received? (FIFO not empty)" (p. 16) and "only wake up once the FIFO is no longer empty (IRQMFIFONOTEMPTY interrupt in register IRQMASK0)" (p. 17). Also useful: IRQMPLLRNGDONE = bit 12 in IRQMASK1 (reg 0x006, bits 12:8) |
| Packet content/validity | DATA chunk flags in the FIFO (Table 17, p. 10): ABORT (bit 6), SIZEFAIL (5), ADDRFAIL (4), CRCFAIL (3), RESIDUE (2), PKTEND (1), PKTSTART (0) — drop the chunk unless PKTACCEPTFLAGS accepts the failure |

**RADIOSTATE (0x01C, read-only, reset 0000), Table 47 (p. 40), verbatim:**

| Bits | Meaning |
|---|---|
| **0000** | **Idle** |
| 0001 | Powerdown |
| 0100 | Tx PLL Settings |
| 0110 | Tx |
| 0111 | Tx Tail |
| 1000 | Rx PLL Settings |
| 1001 | Rx Antenna Selection |
| 1100 / 1101 / 1110 | Rx Preamble 1 / 2 / 3 |
| 1111 | Rx |

**Idle for TX-done polling = RADIOSTATE == 0000.** (XTALSTATUS 0x01D bit 0 = XTAL RUN is the "crystal ready" flag; SPI status bit S4 = "XTAL OSCILLATOR RUNNING".)

---

## 3. Register reference for this link

Legend: **formula** column quotes the manual (reconstructed where the text extraction garbles it, see §0); "no formula in manual" means the manual gives neither formula nor link-dependent recommendation.

### 3.1 Operating mode

| Register | Addr | Fields (bits) | Reset | Manual formula/recommendation | Value for this link |
|---|---|---|---|---|---|
| PWRMODE | 0x002 | PWRMODE[3:0]; WDS[4] R; REFEN[5]; XOEN[6]; RST[7] | 011−0000 (0x30) | Table 26: `1101 Transmitter Running` (FULLTX), `1100 Synthesizer running, Transmit Mode`, `0101 Crystal Oscillator enabled`, `0111 FIFO enabled`, `0000 Powerdown`. "The PWRMODE register should stay at FULLTX until the transmission is fully completed." | FULLTX byte = **0x6D** (RST=0, XOEN=1, REFEN=1, PWRMODE=1101); SYNTHTX = 0x6C; POWERDOWN = 0x60. Reset RST: set/clear bit 7 (0xB0→0x30) |
| POWSTAT | 0x003 | — | — | (needed before FIFO writes) | poll SVMODEM (bit 3) = 1 |

### 3.2 Synthesizer (PLL)

| Register | Addr | Fields (bits) | Reset | Manual formula/recommendation | Value for this link |
|---|---|---|---|---|---|
| PLLLOOP | 0x030 | FLT[1:0]; FILTEN[2]; DIRECT[3]; FREQSEL[7] | 0−−−1001 (0x09) | Table 70: `00 External Loop Filter`, `01 Internal Loop Filter, BW = 100 kHz for ICP = 68 µA`, `10 Internal Loop Filter x2, BW = 200 kHz for ICP = 272 mA [sic]`, `11 Internal Loop Filter x5, BW = 500 kHz for ICP = 1.7 mA [sic]`. FREQSEL: "0 = use FREQA, 1 = use FREQB". No link formula → AX_RadioLab. Receiver PLL loop settings: "For transmission of FSK and MSK it is required that the synthesizer bandwidth must be in the order of the data-rate" (datasheet p. 18) | keep reset **0x09** (FLT=01, DIRECT=1, FREQSEL=0); not derivable from a formula |
| PLLLOOPBOOST | 0x038 | FLT[1:0]; FILTEN[2]; DIRECT[3]; FREQSEL[7] (FREQSEL common to both) | 0−−−1011 (0x0B) | "the settings in the registers PLLLOOPBOOST and PLLCPIBOOST are applied first for a programmable duration before reverting to the settings in PLLLOOP and PLLCPI" | keep reset **0x0B**; no formula |
| PLLCPI | 0x031 | PLLCPI[7:0] | 00001000 (0x08) | "Charge pump current in multiples of 8.5 μA" | reset 0x08 = 8 × 8.5 µA = **68 µA**; no formula |
| PLLCPIBOOST | 0x039 | PLLCPI[7:0] | 11001000 (0xC8) | same field, boosted value | reset 0xC8 = 200 × 8.5 µA = **1.7 mA**; no formula |
| PLLVCODIV | 0x032 | REFDIV[1:0]; RFDIV[2]; VCOIMAN[6] (map); VCOSEL[4]; VCO2INT[5] | −000−000 (0x00) | "RFDIV: 0 = no RF divider, 1 = divide RF by 2"; "VCOSEL 0 = fully internal VCO1, 1 = internal VCO2 with external inductor or external VCO, depending on VCO2INT"; Table 73: `00 fPD = fXTAL`, `01 fXTAL/2`, `10 fXTAL/4`, `11 fXTAL/8` | **0x00** = REFDIV 00 (fPD = 26 MHz), RFDIV = 0 (868 MHz band needs no divider), VCOSEL = 0 (internal VCO1), VCO2INT = 0 |
| PLLRANGINGA | 0x033 | VCORA[3:0]; RNG START[4] RS; RNGERR[5] R; PLL LOCK[6] R; STICKY LOCK[7] R | 00001000 (0x08) | see Q5 (verbatim above) | **0x08** (VCORA = 8) then **0x18** to start ranging |
| PLLVCOI | 0x180 | VCOI[5:0]; VCOIE[7] | 0−010010 (0x12) | "This field sets the bias current for both VCOs. The increment is 50 μA for VCO1 and 10 μA for VCO2." / "VCOIE … Enable manual VCOI" | no formula/recommendation; keep reset **0x12** (VCOIE = 0 → automatic) |
| PLLRNGCLK | 0x183 | PLLRNGCLK[2:0] | −−−−−011 (0x03) | Table 148 rows: fPLLRNG = fXTAL/2⁸, /2⁹, /2¹⁰, /2¹¹, /2¹², /2¹³, /2¹⁴, /2¹⁵; "fPLLRNG should be less than one tenth of the loop filter bandwidth, to allow enough settling time." **Bit codes corrupt in the document (all rows read 000)** | keep reset **0x03**; the 000…111 ↔ 2⁸…2¹⁵ mapping is *not* stated by the manual (flag) |
| PLLLOCKDET | 0x182 | LOCKDETDLY[1:0]; LOCKDETDLYM[2]; LOCKDETDLYR[7:6] R | −−−−−011 (writable bits → 0x03) | Table 146: `00 6 ns`, `01 9 ns`, `10 12 ns`, `11 14 ns`; LOCKDETDLYM: "0 = Automatic Lock Delay (determined by the currently active frequency register); 1 = Manual Lock Delay" | keep reset **0x03** (automatic, 14 ns); no formula |
| FREQA3 | 0x034 | FREQA[31:24] | 00111001 | **FREQA = [ fCARRIER / fXTAL × 2²⁴ + 1/2 ]** | **0x21** |
| FREQA2 | 0x035 | FREQA[23:16] | 00110100 | idem | **0x62** |
| FREQA1 | 0x036 | FREQA[15:8] | 11001100 | idem | **0x76** |
| FREQA0 | 0x037 | FREQA[7:0] | 11001101 | idem; "It is strongly recommended to always set bit 0 to avoid spectral tones" | **0x27** (bit 0 = 1) |

(Companion, not requested: FREQB3–FREQB0 = 0x03C–0x03F, reset 0x3934CCCD, same formula; PLLRANGINGB = 0x03B.)

### 3.3 Transmitter / modulator

| Register | Addr | Fields (bits) | Reset | Manual formula/recommendation | Value for this link |
|---|---|---|---|---|---|
| MODULATION | 0x010 | MODULATION[3:0]; RX HALFSPEED[4] | −−−01000 (0x08) | Table 36: `1000 FSK`; "Transmitter amplitude shaping is set using the MODCFGA register, and frequency shaping is set using the MODCFGF register." | **0x08** (FSK, RX HALFSPEED = 0) = reset |
| MODCFGF | 0x160 | FREQSHAPE[1:0] | −−−−−−00 (0x00) | "This register selects the frequency shaping mode of the transmitter." Table 129: `01 Invalid`, `00 External Loop Filter`, `10 Gaussian BT = 0.3`, `11 Gaussian BT = 0.5` — **the `00` label is inconsistent with the prose (hard vs. Gaussian shaping), see §1 #6** | **0x00** for plain (hard) FSK — no formula in manual |
| MODCFGP | — | — | — | **register does not exist in the manual** | n/a |
| MODCFGA | 0x164 | TXDIFF[0]; TXSE[1]; AMPLSHAPE[2]; SLOWRAMP[5:4]; PTTLCKGATE[6]; BROWNGATE[7] | 0000−101 (0x05) | Table 135: `0 Unshaped`, `1 Raised Cosine`; Table 136: `00 Normal Startup (1 Bit Time)`, `01 2 Bit Time`, `10 4 Bit Time`, `11 8 Bit Time`. "Amplitude shaping is used even for constant modulus modulation such as FSK, to ramp up and down the transmitter at the beginning and the end of the transmission." / "The ramp time is normally one bit time, but may be longer by changing the SLOWRAMP field" | **0x05** (TXDIFF = 1 differential, TXSE = 0, AMPLSHAPE = 1 raised cosine, SLOWRAMP = 1 bit time) = reset; no link-specific formula |
| FSKDEV2 | 0x161 | FSKDEV[23:16] | 00000000 | **FSKDEV = [ fDEVIATION / fXTAL × 2²⁴ + 1/2 ]**, fDEVIATION = 0.5·h·BITRATE (half-deviation) | **0x00** |
| FSKDEV1 | 0x162 | FSKDEV[15:8] | 00001010 | idem | **0x18** |
| FSKDEV0 | 0x163 | FSKDEV[7:0] | 00111101 | idem | **0x33** (9600.52 Hz) |
| TXRATE2 | 0x165 | TXRATE[23:16] | 00000000 | **TXRATE = [ BITRATE / fXTAL × 2²⁴ + 1/2 ]** | **0x00** |
| TXRATE1 | 0x166 | TXRATE[15:8] | 00101000 | idem | **0x18** |
| TXRATE0 | 0x167 | TXRATE[7:0] | 11110110 | idem | **0x33** (9600.52 bit/s) |
| TXPWRCOEFFA1 / A0 | 0x168 / 0x169 | TXPWRCOEFFA[15:8] / [7:0] | 00000000 / 00000000 | **TXPWRCOEFFx = [ αx × 2¹² + 1/2 ]**; "The transmit predistortion circuit applies the following function to the output of the raised cosine amplitude shaping: **f(x) = α4·x⁴ + α3·x³ + α2·x² + α1·x + α0**" | **0x0000** = reset |
| TXPWRCOEFFB1 / B0 | 0x16A / 0x16B | TXPWRCOEFFB[15:8] / [7:0] | 00001111 / 11111111 | "For conventional (non-predistorted output), α0 = α2 = α3 = α4 = 0 and 0 ≤ α1 ≤ 1 controls the output power. (0 means no output power, 1 means maximum output power)." | reset **0x0FFF** → α1 = 4095/4096 ≈ 1 = maximum power; set per required output power (manual gives no absolute-power mapping) |
| TXPWRCOEFFC1 / C0 | 0x16C / 0x16D | [15:8] / [7:0] | 0x0000 / 0x0000 | see TXPWRCOEFFB (α2) | **0x0000** = reset |
| TXPWRCOEFFD1 / D0 | 0x16E / 0x16F | [15:8] / [7:0] | 0x0000 / 0x0000 | see TXPWRCOEFFB (α3) | **0x0000** = reset |
| TXPWRCOEFFE1 / E0 | 0x170 / 0x171 | [15:8] / [7:0] | 0x0000 / 0x0000 | see TXPWRCOEFFB (α4) | **0x0000** = reset |
| TMGTXBOOST | 0x220 | TMGTXBOOSTM[4:0]; TMGTXBOOSTE[7:5] | 00110010 (0x32) | "**The Transmit PLL Boost Time is TMGTXBOOSTM ⋅ 2^TMGTXBOOSTE μs.**" | reset M = 18, E = 1 → 36 µs; no link-specific recommendation (AX_RadioLab) |
| TMGTXSETTLE | 0x221 | TMGTXSETTLEM[4:0]; TMGTXSETTLEE[7:5] | 00001010 (0x0A) | "**The Transmit PLL (post Boost) Settling Time is TMGTXSETTLEM ⋅ 2^TMGTXSETTLEE μs.**" | reset M = 10, E = 0 → 10 µs; no link-specific recommendation |
| ENCODING *(companion)* | 0x011 | ENCINV[0]; ENCDIFF[1]; ENCSCRAM[2]; ENCMANCH[3]; ENCNOSYNC[4] | −−−00010 (0x02) | Table 38 NRZ = INV 0, DIFF 0, SCRAM 0, MANCH 0 | **0x00** — reset 0x02 has differential encoding ON (§1 #9) |

### 3.4 Framing, packet controller, pattern match

| Register | Addr | Fields (bits) | Reset | Manual formula/recommendation | Value for this link |
|---|---|---|---|---|---|
| FRAMING *(companion)* | 0x012 | FABORT[0] S; FRMMODE[3:1]; CRCMODE[6:4]; FRMRX[7] R | −0000000 (0x00) | Table 40: `011 Raw, Pattern Match`; Table 41: `001 CCITT (16 bit)` | **0x16** |
| PKTADDRCFG | 0x200 | ADDR POS[3:0]; FEC SYNC DIS[5]; CRC SKIP FIRST[6]; MSB FIRST[7] | 001−0000 (0x20) | "MSB FIRST … When set, each byte is sent MSB first; when cleared, each byte is sent LSB first"; "CRC SKIP FIRST … the first byte of the packet is not included in the CRC calculation"; "FEC SYNC DIS … disable FEC sync search during packet reception" | **0x20** = reset (LSB first) **or 0xA0** if you really want MSB-first (see §1 #1) |
| PKTLENCFG | 0x201 | LEN POS[3:0]; LEN BITS[7:4] | 00000000 | "LEN POS — Position of the length byte"; "LEN BITS — Number of significant bits in the length byte"; arbitrary-length RX recipe: LEN BITS = 1111, PKTMAXLEN = 0xFF, ACCPT LRGP = 1 | **no formula/recommendation for this link**; reset 0x00 = no length logic (RX-side size check only) |
| PKTLENOFFSET | 0x202 | LEN OFFSET[7:0] | 0x00 | "**The receiver adds LEN OFFSET to the length byte.** The value of (length byte + LEN OFFSET) counts every byte in the packet after the synchronization pattern, up to and excluding the CRC bytes, but including the length byte." "The length offset is treated as a signed value; LEN OFFSET 0xff means the length offset is −1." | no formula for this link; reset 0x00 |
| PKTMAXLEN | 0x203 | MAX LEN[7:0] | 0x00 | "Packet Maximum Length" (used by SIZEFAIL size checks) | **no recommendation in manual**; reset 0x00 |
| PKTCHUNKSIZE | 0x230 | PKTCHUNKSIZE[3:0] | −−−−0000 (0x00 = **invalid**) | Table 183: `0001 1`, `0010 2`, `0011 4`, `0100 8`, `0101 16`, `0110 32`, `0111 64`, `1000 96`, `1001 128`, `1010 160`, `1011 192`, `1100 224`, `1101 240`, `1110/1111 invalid`; "The PKTCHUNKSIZE limits the maximum chunk size in the FIFO. This number includes the flags byte and all data bytes, but not the chunk header and the chunk length byte." | **no formula in manual** (AX_RadioLab); reset 0000 is documented as invalid — must be programmed |
| PKTMISCFLAGS | 0x231 | RXRSSI CLK[0]; RXAGC CLK[1]; BGND RSSI[2]; AGC SETTL DET[3]; WOR MULTI PKT[4] | −−−00000 (0x00) | bits as listed; **none relate to pattern matching** ("WOR MULTI PKT: If 1, the receiver continues to be on after a packet is received in wake-on-radio mode") | **0x00**; no pattern-match requirement |
| PKTSTOREFLAGS | 0x232 | ST TIMER[0]; ST FOFFS[1]; ST RFOFFS[2]; ST DR[3]; ST RSSI[4]; ST CRCB[5]; ST ANT RSSI[6] | −0000000 (0x00) | "Store … at end of packet"; "ST CRCB … Normally, CRC bytes are discarded after checking." | **0x00** (RX meta-data only) |
| PKTACCEPTFLAGS | 0x233 | ACCPT RESIDUE[0]; ACCPT ABRT[1]; ACCPT CRCF[2]; ACCPT ADDRF[3]; ACCPT SZF[4]; ACCPT LRGP[5] | −−000000 (0x00) | "Note that if ACCPTCRCF is not set … packets which fail the CRC check are silently dropped." / ACCPT LRGP needed for "packets that span multiple FIFO chunks" | **0x00** (RX-side) |
| MATCH1PAT1 | 0x218 | MATCH1PAT[15:8] | 0x00 | "LSB is received first; patterns of length less than 16 must be MSB aligned" | **0xB3** (MSB-first) / **0xCD** (LSB-first) — see Q3 |
| MATCH1PAT0 | 0x219 | MATCH1PAT[7:0] | 0x00 | idem | **0xD5** (MSB-first) / **0xAB** (LSB-first) |
| MATCH1LEN | 0x21C | MATCH1LEN[3:0]; MATCH1RAW[7] | 0−−−0000 (0x00) | "The length in bits of the pattern is **MATCH1LEN + 1**"; MATCH1RAW 0 = decoded bits, 1 = raw received bits | **0x0F** (16-bit pattern), MATCH1RAW = 0 |
| MATCH1MIN | 0x21D | MATCH1MIN[3:0] | −−−−0000 (0x00) | "A match is signalled if the received bitstream matches the pattern in less than MATCH1MIN positions. This can be used to detect inverted sequences." | **0x00** = reset; no manual recommendation (see Q3 caveat) |
| MATCH1MAX | 0x21E | MATCH1MAX[3:0] | −−−−1111 (0x0F) | "A match is signalled if the received bitstream matches the pattern in more than MATCH1MAX positions." | **0x0F** = reset (= all 16 positions must match, interpretation in Q3); no manual recommendation |

### 3.5 FIFO, PLL/oscillator and pin/status registers

| Register | Addr | Fields (bits) | Reset | Manual formula/recommendation | Value for this link |
|---|---|---|---|---|---|
| FIFOSTAT | 0x028 | read: FIFO EMPTY[0], FIFO FULL[1], FIFO UNDER[2], FIFO OVER[3], FIFO CNT THR[4], FIFO FREE THR[5], FIFO AUTO COMMIT[7]; write: FIFOCMD[5:0] | 0−−−−−−− (bit 7 = 0) | Table 63 + Table 64 (see Q4). "FIFO AUTO COMMIT 7 RW 0 — If one, FIFO write bytes are automatically commited on every write" | read for status; **write 0x04 = Commit**, 0x05 = Rollback, 0x02 = clear error flags, 0x03 = clear FIFO data+flags |
| PINFUNCIRQ | 0x024 | PFIRQ[2:0]; PIIRQ[6]; PUIRQ[7] | 00−−−011 (0x03) | Table 57: `011 IRQ Output Interrupt Request`, `000`/`001`/`010` static, `111 Test Observation` | **0x03** = reset (IRQ pin driven by the interrupt controller); set PIIRQ to invert if needed |
| IRQMASK0 | 0x007 | IRQMFIFONOTEMPTY[0], IRQMFIFONOTFULL[1], IRQMFIFOTHRCNT[2], IRQMFIFOTHRFREE[3], IRQMFIFOERROR[4], IRQMPLLUNLOCK[5], IRQMRADIOCTRL[6], IRQMPOWER[7] | 00000000 | "Zero disables the corresponding interrupt, while one enables it." | TX-done IRQ: **0x40**; RX FIFO IRQ: **0x01**; both: **0x41** |
| IRQMASK1 | 0x006 | IRQMASK[12:8]: IRQMXTALREADY[8], IRQMWAKEUPTIMER[9], IRQMLPOSC[10], IRQMGPADC[11], IRQMPLLRNGDONE[12] | −−−00000 | idem | **0x10** to enable autoranging-done IRQ (bit 12); 0x00 otherwise |
| RADIOEVENTMASK0 | 0x009 | REVMDONE[0], REVMSETTLED[1], REVMRADIOSTATECHG[2], REVMRXPARAMSETCHG[3], REVMFRAMECLK[4] | 00000000 | "REVMDONE 0 RW 0 — Transmit or Receive Done Radio Event Enable" | **0x01** for TX/RX-done events (pair with IRQMASK0 bit 6); 0x00 otherwise |
| RADIOEVENTMASK1 | 0x008 | RADIO EVENT MASK[8] | −−−−−−−0 | idem | **0x00** |
| XTALCAP | 0x184 | XTALCAP[7:0] | 00000000 | "Load Capacitance Configuration"; "**For values XTALCAP(5:0) ≠ 0, CL = 8 pF + 0.5 pF ⋅ XTALCAP (5:0).**" Table 150: `000000 3 pF`, `000001 8.5 pF`, `000010 9 pF`, … `110111 36 pF`, … `111111 40 pF` | **no formula/recommendation in manual for selecting CL for a given crystal** (the mapping is given, the choice is not); reset 000000 = 3 pF |
| XTALOSC | — | — | — | **register does not exist in the manual** (use XTALSTATUS 0x01D bit 0 / XTALCAP 0x184) | n/a |
| POWCTRL1 | — | — | — | **register does not exist in the manual** (use PWRMODE 0x002, POWSTAT 0x003, POWSTICKYSTAT 0x004, POWIRQMASK 0x005) | n/a |

**Mandatory undocumented-address performance registers for a 26 MHz crystal (Table 199, p. 73–74):**
`F34` = **0x08** with RFDIV = 0 (or 0x28 if RFDIV is set); `F35` = **0x11** for fXTAL ≥ 24.8 MHz (0x10 below) → 26 MHz uses **0x11** (fXTALDIV = 2); `F10` = **0x03** for a crystal ≤ 43 MHz (0x0D if reference > 43 MHz, 0x04 for TCXO); `F11` = 0x07 for a crystal on CLK16P/CLK16N; `F00` = 0x0F; `F0D` = 0x03; `F1C` = 0x07; `F44` = 0x24; `F72` = **0x00** (0x06 only for "Raw, Soft Bits"); others as listed. "Registers with Addresses from 0xF00 to 0xFFF are performance tuning registers. Their optimum values are computed by AX_RadioLab".

---

## 4. Consolidated write list for this link (26 MHz / 868 MHz / 9600 bit/s / h=2 / Raw+Pattern-Match / CCITT-16)

```
PWRMODE(0x002)      = 0x30   (reset; then per flow: STANDBY 0x65 for autoranging, FULLTX 0x6D to transmit)
PLLVCODIV(0x032)    = 0x00   (RFDIV=0, REFDIV=00 -> fPD = 26 MHz, internal VCO1)
PLLRANGINGA(0x033)  = 0x08   then 0x18 (VCORA=8 + RNGSTART=1), poll RNGSTART==0, check RNGERR(bit5)/PLLLOCK(bit6)
FREQA3..0(0x034-37) = 21 62 76 27        (FREQA = 560 100 903 = round(868/26 * 2^24))
MODULATION(0x010)   = 0x08   (FSK)
ENCODING(0x011)     = 0x00   (NRZ: clear the reset ENC DIFF)
MODCFGF(0x160)      = 0x00   (no Gaussian shaping; label of 00 in Table 129 is suspect - see §1 #6)
FRAMING(0x012)      = 0x16   (FRMMODE=011 Raw, Pattern Match | CRCMODE=001 CCITT-16)
MODCFGA(0x164)      = 0x05   (reset: differential PA, raised-cosine amplitude shaping, 1-bit ramp)
TXRATE2..0(0x165-67)= 00 18 33            (TXRATE = 6195 = round(9600/26e6 * 2^24))
FSKDEV2..0(0x161-63)= 00 18 33            (fDEVIATION = 0.5*2*9600 = 9600 Hz; FSKDEV = 6195)
TXPWRCOEFFB1/B0     = 0F FF  (alpha1 ~ 1 = max power; A,C,D,E stay 0x0000)
TMGTXBOOST(0x220)   = 0x32   (36 us, reset - no link formula, AX_RadioLab)
TMGTXSETTLE(0x221)  = 0x0A   (10 us, reset - no link formula)
MATCH1PAT1(0x218)   = 0xB3 ; MATCH1PAT0(0x219) = 0xD5   (0xAB 0xCD, MSB-first; 0xCD/0xAB if LSB-first)
MATCH1LEN(0x21C)    = 0x0F   (16-bit pattern, MATCH1RAW=0)
MATCH1MIN(0x21D)    = 0x00 ; MATCH1MAX(0x21E) = 0x0F   (no manual recommendation - interpretation only)
PKTCHUNKSIZE(0x230) = must be programmed (reset 0000 is invalid); no formula in manual
PKTMISCFLAGS(0x231)= 0x00 (no pattern-match requirement)
PKTADDRCFG(0x200)   = 0x20 (reset, LSB first) or 0xA0 (MSB first)
PINFUNCIRQ(0x024)   = 0x03 (reset: IRQ pin = interrupt request)
TX: PWRMODE=0x6D -> (wait SVMODEM=1) -> write preamble+data chunks -> FIFOSTAT(0x028)=0x04 (Commit)
    -> poll RADIOSTATE(0x01C) for 0x0, or IRQMASK0(0x007)=0x40 + RADIOEVENTMASK0(0x009)=0x01
F34=0x08 (RFDIV=0), F35=0x11 (fXTAL >= 24.8 MHz), F10=0x03, F11=0x07, F00=0x0F, F0D=0x03, F1C=0x07, F44=0x24, F72=0x00
```

**Not determinable from the manual (flagged, not guessed):** PLL loop bandwidth / charge-pump / boost timings for this bit rate, PKTCHUNKSIZE, XTALCAP for a given crystal CL, TXPWRCOEFFB for a required output power in dBm, PLLRNGCLK bit codes (Table 148 corrupt), MATCH1MIN/MAX recommendation, and whether any RFDIV factor belongs in the FREQA formula (none is printed; the datasheet's divider-range and step-size figures are only consistent with the formula exactly as printed).
