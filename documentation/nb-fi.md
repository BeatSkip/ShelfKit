# NB-Fi on the ShelfKit link

> **Removed.** NB-Fi was implemented on this link, worked, was documented
> below, and has since been taken back out: it is the wrong tool for a house.
> It cost ~4 minutes per image (9 bytes of payload per 36-byte MAC frame),
> ~12 KB of ROM and ~1.4 KB of XRAM for FEC and crypto weight that buys range
> a house does not need. What replaced it - a light frame with a CRC-16,
> compact addressing, managed flooding and wake-on-radio - is in
> [`mesh.md`](mesh.md).
>
> This page is kept as the record of that work and of the references and
> measurements behind it. Nothing in it describes the firmware as it stands
> now; `nbfi.c`, `nbfi.h`, its host test and `tools/analyse_zcode.py` are gone.
> One idea from it was worth keeping and is now in `sk_link.c`:
> `sk_id_from_serial()`, the FNV-1a/32 node address derived from the NFC serial
> (§4's "address matching").

This is the reference for the NB-Fi implementation in `firmware/*/src/nbfi.c`:
what the standard says, where each number came from, what the AX5043 had to
change, and what is *not* done. The register reasoning for the physical layer
still lives in `radio.c`; its justification, including the "do not hand-derive
this" rule, is in [`shelfkit-radio-link.md`](shelfkit-radio-link.md).

## 1. Sources

Everything below is taken from one of these. Where a fact came from a
particular clause it is cited inline.

| Source | What it is |
|---|---|
| [GOST R 70036-2022, full text](https://meganorm.ru/mega_doc/norm/gost-r_gosudarstvennyj-standart/9/gost_r_70036-2022_natsionalnyy_standart_rossiyskoy.html) | The standard itself (mirror; the official PDF is paywalled). All clause numbers below are this document. |
| [waviot/NBFi_WA1470](https://github.com/waviot/NBFi_WA1470) | The reference implementation the standard's bibliography cites (ООО "Телематические Решения"). `NBFiLib/nbfi/nbfi_mac.c`, `nbfi_crypto.c`, `nbfi_crc.c`, `zcode.c`, `pcode.c` are the sources the annexes В/Д/Ж are extracted from. |
| [waviot/preambula](https://github.com/waviot/preambula) | The annex Е/К downlink preamble generator. |
| [AX5043 programming manual (AND9347/D)](https://www.onsemi.com/pdf/datasheet/and9347-d.pdf) | Register semantics. A text copy was used locally. |
| [AX-RadioLAB "VusionLink" config](reference/VusionLink/AX_Radio_Lab_output/config.c) | The vendor's generated register table for this board. Already the repo's source of truth for the PHY. |
| [WAVIoT brochure](https://www.waviot.ru/upload/iblock/fce/fce72abbc7eaf407cc19fef00d4810c3.pdf) | Marketing, not normative. Corroborates the 868.7–869.2 MHz band and 25 mW devices; used for nothing else. |

Two mirror caveats worth recording: `rosgosts.ru` serves a CAPTCHA and
`dokipedia.ru` a Cloudflare interstitial, so neither was usable; and four
formulas in annex A are *images* in the HTML, so they were recovered from the
reference implementation's `NBFi_MAC_get_UL_freq()` / `NBFi_MAC_get_DL_freq()`
and cross-checked against the surrounding prose, which states the same thing in
words (gap = (band − 2·bitrate − 2000)/2, zero when that is not positive).

## 2. What NB-Fi is

### 2.1 Physical layer (clause 5, tables 1 and 2)

| | Uplink | Downlink |
|---|---|---|
| Minimum receive/transmit bandwidth | 51.2 kHz | 102.4 kHz |
| Data rates | 50, 400, 3200, 25600 bit/s | 50 (optional), 400, 3200, 25600 bit/s |
| Modulation | ОФМн-2 (relative BPSK) | ОФМн-2 or ФМн-2 |
| Packet length | 288 bits | 288 bits |
| Channelisation | frequency | frequency |
| Channels in the stated bandwidth | 1024 / 128 / 16 / 1 at the four rates | — |
| Sensitivity (reference) | −150 / −141 / −132 / −123 dBm | −148 / −139 / −130 / −121 dBm |

Dividing the stated bandwidth by the channel count gives **channel spacing =
bit rate** at 50, 400 and 3200 bit/s. Note 2 to table 1 is the clause the
implementation leans on: ОФМн-2 at low rates "cannot be generated at hardware
level by all radio transceivers", and **ЧМн (FSK) at a higher data rate may be
used instead**. That is what licenses the AX5043 mapping in §3.

Clause 5.4 defines an optional LBT mode. Clause 7.3.2.7 defines the transport
configuration parameters, including `NBFI_TX_PHY_CHANNEL` (table 35: code 32 =
`UL_DBPSK_3200_PROT_E`) and `NBFI_RX_PHY_CHANNEL` (table 36: code 12 =
`DL_DBPSK_3200_PROT_D`).

### 2.2 Uplink frame (clause 6.2, table 4, annex В.1) — 36 bytes

```
[ 4-byte preamble 97 15 7A 6F ]
[ 32-byte FEC codeword ]
```

where the 20-byte FEC *source* is

```
[ Modem_ID 4 ][ Crypto Iter 1 ][ Payload 9 ][ MIC0_7 3 ][ Packet CRC 3 ]
```

* `Modem_ID`: 32-bit device address, most significant byte first (6.2.2). The
  network's numbering capacity is 2^32.
* `Crypto Iter`: the low 8 bits of the 32-bit crypto iterator (6.2.3).
* `Payload`: the whole 9-byte transport packet (6.2.4).
* `MIC0_7`: 24-bit integrity value, most significant byte first (6.2.5).
* `Packet CRC`: the low three bytes of CRC32 over source bytes 0..16, most
  significant first (6.2.6).
* FEC: either a non-systematic (255, 363) convolutional code punctured to rate
  5/8, or a non-systematic polar code of the same rate (6.2.7). The base
  station **must** accept the convolutional code; polar decoding is optional.

Bit order within a byte is **most significant bit first** (6.2).

### 2.3 Downlink frame (clause 6.3, table 5, annex В.2) — 36 bytes

```
[ 4-byte device preamble ][ 16-byte source ][ 16-byte ZIGZAG block ]
```

with the source

```
[ Crypto Iter 1 ][ Payload 9 ][ MIC0_7 3 ][ Packet CRC 3 ]
```

* The preamble is derived from the Modem_ID by the annex Е pseudorandom
  correlation search, not fixed.
* `Packet CRC` is CRC32 over source bytes 0..12 (6.3.5), i.e. iterator +
  payload + MIC.
* **The downlink is systematic**: the source travels in clear and the ZIGZAG
  block is appended as a check. This is the single most important structural
  fact for the implementation - see §5.
* The uplink preamble is fixed (`97 15 7A 6F`, annex В.1); the downlink's is
  not.

### 2.4 Transport layer (clause 7.3.1, tables 15–17) — 9 bytes

```
[ HEADER 1 ][ DATA 8 ]
```

`HEADER` is `SYS:1 ACK:1 MULTI:1 ITER:5`, with SYS in the most significant bit
and ITER in the least significant five. A user packet has SYS = 0 and eight
payload bytes; a system packet has SYS = 1 and DATA = `[TYPE 1][SYS_PAYLOAD 7]`.
Application data of exactly 8 bytes goes in a user packet, less than 8 in a
SHORT packet, more than 8 fragmented into a group.

System types (table 18): `0x00` ACK_P, `0x01` HEARTBEAT, `0x02` GROUP, `0x03`
SACK_P, `0x04` CLEAR, `0x06` CONF, `0x07` RESET, `0x08` CLEAR_T, `0x09`
SENDTIME, `0x0A` SYNC, and `0b1xxxxxxx` for SHORT.

* **GROUP** (7.3.2.4): `[0x02][GROUP_LEN][GROUP_CRC][payload 0..4]`, so the
  first packet of a group carries five application bytes and each user packet
  after it carries eight. `GROUP_CRC` is CRC8 over the group's whole payload.
* **ACK_P** (7.3.2.2, table 21): `[0x00][MASK 4][SNR][NOISE_OR_RTC][MFLAGS]`.
  MASK byte *b* bit *k* is the receiving status of the packet with iterator
  *i* − 32 + 8*b* + *k*, where *i* is the ACK_P's own iterator - which is set
  to the iterator of the packet being acknowledged. The acknowledged packet
  itself is **not** in the mask, because the ACK_P's arrival is its proof.

### 2.5 Reliability (clause 7.2.2)

Sessions with `HANDSHAKE_SIMPLE`. A session carries as many packets as the
group, with ITER incrementing per packet modulo 32; the sender sets ACK on the
last packet of each pass; the receiver answers with an ACK_P carrying the mask;
the sender retransmits whatever the mask says is missing and repeats up to
`NBFI_NUM_OF_RETRIES`; on success it sends CLEAR (or CLEAR_T). The receive
buffer is 32 packets deep, which is what the five-bit iterator exists for
(clause 7.1). Timers: `NBFI_RX_TIMEOUT` is either the DRX formula
(`NBFI_UL_DELAY + NBFI_DL_LISTEN_TIME + random`, tables 9–11) or, **when the
transport parameter `WAIT_ACK_TIMEOUT` is non-zero, simply that value**.

### 2.6 Checksums (annex В)

* **CRC32** (В.5): polynomial `0x04C11DB7` taken **most significant bit first**,
  initial value `0xFFFFFFFF`, final xor `0xFFFFFFFF`. That is the catalogue's
  **CRC-32/BZIP2**, not CRC-32/ISO-HDLC - same polynomial, opposite bit order,
  different answer. Check value of `"123456789"` is **0xFC891918**. (The first
  version of this implementation assumed ISO-HDLC; the test caught it.)
* **CRC8** (В.3): the annex's per-bit constant table
  `{0x5e, 0xbc, 0x61, 0xc2, 0x9d, 0x23, 0x46, 0x8c}` is exactly the reflected
  response of a CRC-8/MAXIM (poly 0x8C, init 0). Check value **0xA1**.
* **CRC16** (В.4): reflected poly `0xA001` with the initial value as a
  parameter - CRC-16/ARC. Check value at init 0 is **0xBB3D**. Nothing we send
  uses it; it is implemented and pinned because the annex defines it.

### 2.7 Annex A, the frequency plan

`ULBandwidth = 6400 · 2^UL_WIDTH` (A.1), `DLBandwidth = 102400 · 2^DL_WIDTH`
(A.8), band offsets from `UL_OFFSET/UL_SIGN` and `DL_OFFSET/DL_SIGN` (A.2/A.9),
and

```
ULGap = 0 if ULBandwidth <= Bitrate·2 + 2000, else (ULBandwidth - Bitrate·2 - 2000)/2
ULChannelOffset = ((Modem_ID + MIC0_7) mod 256) · ULGap / 255
ULfreq = base ± ULBandOffset ± ULChannelOffset        (+ if parity, - if not)
DLGap = the same with DLBandwidth
DLChannelOffset = (Modem_ID mod 256) · DLGap / 255
DLfreq = base ± DLBandOffset ± DLChannelOffset        (+ if Modem_ID odd, - if even)
```

## 3. The AX5043 physical layer

### 3.1 The decision

The AX5043 is a narrowband FSK/PSK transceiver. NB-Fi's uplink is DBPSK, which
it cannot emit; note 2 to table 1 permits FSK instead. FSK with h = 1/2 *is*
MSK, and the AX5043's `ENCODING` register has an `ENC DIFF` bit that makes the
data relative - together that is the standard's relative-phase waveform.

Of NB-Fi's four rates we use **3200 bit/s, both directions**:

* it is one of the normative rates;
* it is the fastest rate whose occupied bandwidth still fits inside the 7.2 kHz
  channel filter that AX-RadioLAB generated for this board. 25 600 bit/s would
  want roughly 51.2 kHz and a whole new receiver parameter set, which is
  exactly the thing `shelfkit-radio-link.md` says not to hand-derive;
* 50 and 400 bit/s are below what the AX5043 can do at all.

### 3.2 The registers that changed

**Four**, and no receiver matched-set register was touched:

| Register | Was | Now | Why |
|---|---|---|---|
| `TXRATE` | `0x000C19` (3097) | `0x000811` (2065) | `TXRATE = round(2^24 · BITRATE / FXTAL)`. Verified against the vendor's own table: `2^24 · 4800 / 26e6 = 3097.33 -> 3097 = 0xC19`. For 3200: `2^24 · 3200 / 26e6 = 2064.89 -> 2065 = 0x811`. |
| `FSKDEV` | `0x000408` (1032) | `0x000204` (516) | Manual table 20: `f_dev = 0.5 · h · BITRATE`. The vendor's 1600 Hz at 4800 bit/s is h = 2/3, and `1600 · 2^24 / 26e6 = 1032.4 -> 1032`, confirming the scale. h = 1/2 at 3200 bit/s gives 800 Hz, `800 · 2^24 / 26e6 = 516.2 -> 516`. |
| `RXDATARATE` | `0x003D8D` (15757) | `0x005C54` (23636) | Table 96 is `RXDATARATE ∝ XTAL / (DECIMATION · BITRATE)` - a *period*, so the value rises as the rate falls. Verified at the vendor's operating point: `15757 · 4800 · 22 / 26e6 = 64.0002`, i.e. `RXDATARATE = round(64 · FXTAL / (DECIMATION · BITRATE))`. At 3200 bit/s with `DECIMATION` unchanged: `64 · 26e6 / (22 · 3200) = 23636.36 -> 23636`. |
| `ENCODING` | `0x00` (plain NRZ) | `0x02` (`ENC DIFF`) | The relative encoding that makes the waveform ОФМн-2 rather than ФМн. `ENC DIFF` is the chip's reset default (manual table 37); the previous link had deliberately turned it off. |

Everything else is untouched and must stay untouched: `DECIMATION` (0x16) and
therefore the 7.2 kHz channel filter, all four `RXPARAM` sets, `RXPARAMSETS`,
the IF and gain registers, `MAXRFOFFSET`, the TCXO configuration, the VCO
calibration and the six `FREQA` channel words. The 7.2 kHz filter is *wider*
than a 3200 bit/s signal needs (its null-to-null bandwidth is about 4.8 kHz),
so keeping it costs a few dB of sensitivity but is guaranteed to work - whereas
narrowing it would mean inventing filter coefficients.

`MAXDROFFSET` stays 0, which the manual says is correct when the bit-rate
offset is under about ±1%: both ends use the same 26 MHz TCXO and the register
arithmetic above is exact to well under 0.01%.

### 3.3 Frequency plan in use

`UL_WIDTH = 0` makes `ULBandwidth = 6400 Hz`, which is less than
`2·3200 + 2000 = 8400`, so **formula (A.4) forces `ULGap = 0` and every uplink
packet of every device lands on the same frequency**. That is what lets the
access point - which has one AX5043 receiver, not an SDR - hear anything at
all, and it is what the reference implementation's
`NBFI_UL_FLAG_SEND_ON_CENTRAL_FREQ` does. The downlink does hop per device
(`DLGap = (102400 − 8400)/2 = 47000 Hz`, so ±47 kHz from `Modem_ID mod 256`),
and since it is a function of the Modem_ID both ends compute the same value;
`nbfi_dl_freq()` implements it and the host test pins it. The firmware
currently operates on the central downlink frequency, so a single-channel
access point works: retuning the synthesiser per device needs `FREQA` words
that RadioLAB has not generated, and `radio.c`'s own rule says not to derive
them.

### 3.4 The AX5043's own preamble and sync word

Kept. They are the chip's packet detector and are *not* part of the NB-Fi
frame: NB-Fi's four-byte preamble is carried inside the 36 bytes as ordinary
payload, exactly as the standard's own code does. A real NB-Fi base station,
being an SDR that correlates against that preamble, would still see these
frames; ours detects them a few bits earlier with the sync-word engine. The
cost is the chip's 9 bytes of preamble/sync/length overhead per packet, which
is quantified in §6.

## 4. What is implemented

`nbfi.c`/`nbfi.h` (byte-identical in the tag and the access point, hash-checked
the same way `radio.c`/`radio.h` are) implement:

* the three CRCs of annex В, with the check values pinned by the host test;
* the uplink MAC frame of annex В.1, including the **(255, 363) rate-5/8
  convolutional code** of annex Д.1 - encoder and a **hard-decision
  sliding-window Viterbi decoder** (128 states, register exchange, 32-bit
  window, 8-bit metrics with renormalisation). The convolutional code was
  chosen over the polar code precisely because 6.2.7 makes it the one a base
  station *must* accept, so our uplink is receivable by any conformant base
  station, whereas a polar-encoded packet needs the optional decoder;
* the downlink MAC frame of annex В.2 as **systematic**: the source is read
  from bytes 4..19, the CRC32 is verified, and the ZIGZAG check block is
  verified by re-encoding it (annex Ж);
* the annex Е downlink preamble generator;
* the annex A frequency functions;
* the transport layer: the header bit layout, user / SHORT / GROUP / ACK_P /
  CLEAR packets, group fragmentation and reassembly, the ACK_P 32-bit mask in
  both packings, session retransmission bounded by `NBFI_NUM_OF_RETRIES`, and a
  receive window that rejects replays and stray packets;
* the address matching: the uplink is filtered on `Modem_ID`; the downlink is
  addressed by the Modem_ID-derived preamble; a base station latches the
  Modem_ID from the first frame it hears, and
  `nbfi_modem_id_from_serial()` (FNV-1a/32 over the NFC serial) lets it address
  a tag that has not spoken yet.

Application packets (`shelfkit_proto.h`, up to 103 bytes) ride on top
unmodified: `nbfi_send()` takes one and delivers it as a reliable NB-Fi group
session, `nbfi_poll()` reassembles one and hands it up. Against
`NBFI_APP_MAX = 104` a 103-byte packet becomes 14 transport packets. The
UART/host side is untouched, so the host tools and their protocol tests are
unaffected.

## 5. The ZIGZAG finding, and why there is no decoder

Annex Ж's `ZCODE_Append` maps 16 source bytes to 16 codeword bytes. That map is
linear over GF(2) and its **rank is 127, not 128**: the all-ones source is in
its kernel, because every coded bit is an XOR of two source bits and
complementing both arguments of an XOR changes nothing. So a codeword
determines the source only up to complementation, and one of the 128 codeword
bits carries no information.

`tools/analyse_zcode.py` measures this from the firmware's own permutation
table and the host test asserts it. An earlier version of this work carried a
2 KB generated pseudo-inverse table and a decoder, and two rounds of test
failures were spent discovering that it could only ever return the source up to
complementation.

The systematic reading of table 5 dissolves the problem: the receiver does not
need to invert anything. It reads the source, and uses the block as a check -
which for the errors that matter is a strong one, since the code's only blind
direction is 128 bits wide. Every single-bit error in the 256-bit
(source, block) pair is caught. The frame's own CRC32 covers the blind spot.

## 6. Throughput

Per packet on the air, 36 payload bytes plus the AX5043's 4-byte preamble, 4-byte
sync word and 1 length byte: 360 bits at 3200 bit/s = **112.5 ms**.

* An application datagram costs `1 + ceil((n − 5)/8)` transport packets, so a
  96-byte image block is 13 packets = 1463 ms downlink, plus one ACK_P (113 ms)
  and the tag's answering IMG_ACK as a 1-packet session (113 ms + 113 ms).
  **About 1.8 s per image block, against roughly 0.3 s over the old 4800 bit/s
  link with 96-byte packets** - the NB-Fi transport carries 9 bytes per MAC
  frame where the old link carried 103.
* A full 11248-byte image is 118 blocks, so **≈4 minutes**, against ≈40 s
  before. Long, but bounded and usable; nothing was dropped to get there.
* NB-Fi's own reporting of effective rate agrees: table 3 gives 800 bit/s for
  a 3200 bit/s uplink, i.e. rate/4, which is exactly 9 payload bytes per 36-byte
  frame.
* Range improves: 3200 bit/s with h = 1/2 in the same 7.2 kHz filter has more
  energy per bit than 4800 bit/s with h = 2/3, and the standard's own table 1
  puts the 3200 bit/s sensitivity 9 dB ahead of 25 600.

## 7. What is not done, and what is unverified

**Not implemented**

* **Payload protection.** GOST 6.2.4/6.3.3 require the 9-byte payload to be
  encrypted with Magma (GOST R 34.12-2015) in counter mode under a key derived
  from a per-device 256-bit root key, and 6.2.5/6.3.4 require the MIC to be a
  Magma MAC over the ciphertext plus the full crypto iterator. Instead the
  payload goes in clear and the MIC field carries CRC32 of the same nine bytes
  - which is exactly what the reference library does when it is built without
  its GOST crypto submodule and `NBFI_Crypto_Available()` returns 0. The frame
  layout is unchanged and the crypto iterator is carried and incremented per
  frame, so the format is right and the gap is closed by implementing Magma.
  Why it is not done here: `NBFi_Crypto_Encode`/`Magma_MIC` sit behind a
  submodule (`waviot/gost_crypto`) that is not present, so the two details that
  matter - where the 32-bit IV sits in the 64-bit counter block, and whether
  the MAC covers `crypto_iter` as GOST Г.11 says or only the ciphertext as the
  reference's call site suggests - could not be established from the sources.
  Guessing them would produce a link that works only against itself. The
  key-schedule and iterator rules of annex Г *are* known and are documented
  above; this is a bounded, well-specified piece of remaining work.
* **Polar decoding** for the uplink (6.2.7 makes it optional for a base
  station, which is why the mandatory convolutional code was chosen).
* **Frequency hopping** on the downlink, as described in §3.3.
* **LBT** (5.4), **rate/power adaptation** (7.2.5), **time synchronisation**
  (SENDTIME/CLEAR_T), CONF/RESET/SYNC/HEARTBEAT packets, and the Magma-based
  key-resynchronisation scan of Г.2. ACK_P's SNR and TX_PWR fields are sent as
  zero: they exist to drive adaptation that is not implemented, and reporting a
  measurement the AX5043 has not made would be worse than reporting none.
* **NB-Fi's 32-byte polar code and the convolutional code's soft-decision
  counterpart.** The AX5043 hands up hard bits, so the Viterbi is
  hard-decision; soft-decision would need `FRMMODE = Raw, Soft Bits` and a
  different FIFO path in `radio.c`.

**Unverified without hardware.** The physical layer. Nothing here has been
transmitted. Specifically: whether 3200 bit/s with h = 1/2 inside the
RadioLAB-generated 7.2 kHz filter acquires and holds; whether `ENC DIFF` on
both ends decodes as expected; whether the 500 ms `NBFI_RX_TIMEOUT` is enough
for the turnarounds on this board; and whether the 137-byte stack still holds
when the Viterbi decoder runs inside a receive path that also does flash and
e-paper work. The register arithmetic is verified against the vendor's own
numbers only at 4800 bit/s, so the 3200 bit/s values rest on the *form* of the
manual's formulas (which the 4800 bit/s point confirms) plus exact linear
scaling.

**Unsure.** Two readings were chosen deliberately and could be wrong:

* `NBFI_RX_TIMEOUT`. GOST 7.2.2 allows either the DRX formula - which for
  `DL_DBPSK_3200_PROT_D` is 95 + 6000 + up to 100 ms - or the transport
  parameter `WAIT_ACK_TIMEOUT` when it is non-zero. We set it, and use 500 ms.
  Six seconds per packet would make an image transfer hopeless.
* The replay window. GOST 7.1 and 7.2.2 say the five-bit ITER and the 32-packet
  buffer exist for re-identification and leave the depth of the cyclic check to
  the implementer; we accept a session that starts within 16 iterators of where
  the last one ended. A peer that started a session further away would be
  ignored.

**Test results.** `pwsh -File tools/run_tests.ps1`:

* `nbfi_test.c`: **627 checks, all pass** (up from nothing - this is the new
  suite; see that file's header for what it covers).
* `serial_frame_test.c`: 161 checks, **25 failures - unchanged from the
  baseline**. Those 25 exist at `HEAD` with the pre-NB-Fi `main.c` and my
  changes neither fix nor add to them; `tools/tests/ap_stubs/nbfi_stub.c` maps
  the link layer back onto the radio interface so that the bridge test keeps
  exercising what it was written for.
* The Python suite: **cannot run in this sandbox.** 91 of the 99 tests build
  `tempfile.TemporaryDirectory()` in `setUp` and the file sandbox denies writes
  to the harness's temporary directory (`PermissionError` from `PIL.Image.save`
  inside the test, then from the cleanup `rmtree`). The 8 tests that do not need
  a temporary directory pass. No Python tool was modified, and this sandbox
  also cannot run the firmware flasher, so this is an environment limit rather
  than a regression - but it is unverified here and should be re-run where
  temporary directories are writable.

**Build numbers** (SDCC 3.6.0, `-mmcs51 --model-small --iram-size 256 --xram-size 8192
--code-size 59389`, linked against `libaxdsp`/`libaxdvk2`/`libmf`/`libmfcrypto`):

| Firmware | ROM | XRAM | Free stack |
|---|---|---|---|
| tag (`shelfkit-vusion`) | 41272 / 59389 | 8015 / 8192 | 137 bytes |
| access point | 23931 / 59389 | 2156 / 8192 | 174 bytes |
| dumptool | 8314 / 59389 | 394 / 8192 | 185 bytes |

The tag's committed history records 29347 bytes of ROM and 6613 of XRAM before
this work, so the NB-Fi layer (convolutional encoder + Viterbi + framing +
transport) costs roughly 12 KB of code and 1.4 KB of XRAM. The tag is now
within 180 bytes of its XRAM limit: **any further buffer in `nbfi.c` has to go
through the existing union or into flash**, and the access point has 6 KB to
spare. Note that these figures come from a manual link; the VS Code SDCC
extension may differ by a few hundred bytes.

## 8. Practical notes

* Both firmwares must carry the same `nbfi.c`/`nbfi.h`; they are compared by
  hash like `radio.c`/`radio.h`.
* `nbfi_send()` blocks and leaves the receiver on; `nbfi_poll()` is
  non-blocking and must be given the *same* buffer for the whole of a group,
  because fragments are reassembled straight into it.
* A tag's Modem_ID is `FNV-1a-32` of its NFC serial, so the same tag keeps the
  same address across flashes. Print it at boot - it is in the tag's boot log -
  because a mismatch between it and the access point's idea of the peer looks
  exactly like dead hardware.
* To change the link rate, the four registers in §3.2 are the whole change, plus
  `NBFI_BITRATE` and the two PHY channel codes in `nbfi.h`. Do not touch the
  receiver matched set.
