# The ShelfKit mesh: link frame, managed flooding, wake-on-radio

This is the reference for `firmware/<project>/src/sk_link.c` and the parts of
`radio.c` it drives: what goes on the air, why each field is there, what the
mesh does and does not do, and what it costs. The physical layer - registers,
frequencies, the reasoning that says *do not hand-derive these* - still lives
in [`shelfkit-radio-link.md`](shelfkit-radio-link.md); the frame's byte layout
is also documented next to the application protocol it wraps, in
[`firmware/shared/include/shelfkit_proto.h`](../firmware/shared/include/shelfkit_proto.h).

## 1. What this replaced

The link used to be the application packet on its own: a length byte, then
`[version][type][body][XOR]`, with no addressing and no hop budget. It worked,
and it was "mostly works" for one reason: the XOR. A byte-wide XOR of the
payload catches a single flipped bit and very little else, so the old link
depended on the AX5043's own error detection being off and on an operator
noticing that a transfer had stalled.

NB-Fi (GOST R 70036-2022) replaced that for a while - see
[`nb-fi.md`](nb-fi.md) - and was the wrong tool: 9 bytes of payload per 36-byte
MAC frame put a 12 KB image at ~4 minutes, the FEC and crypto cost ~12 KB of
ROM and ~1.4 KB of XRAM, and its range buys nothing a house needs. It has been
removed; what was worth keeping from it is the compact id (§3).

## 2. The frame

On the air, after the sync word, the chip's length byte and this frame:

```
offset  size  field
0       1     link version (SK_LINK_VERSION = 2)
1       1     packet type (SK_PKT_*), copied from the application payload
2       1     control: hops left in bits 7:4, role flag in bit 0
3       1     sequence number (per origin, wraps at 256)
4       4     origin id: the node that first sent this frame
8       4     destination id (0 = broadcast)
12      1     route length n: how many relays recorded themselves
13      2*n   route: the 2-byte short id of each relay, in order
13+2n   ..    the application payload (version, type, body)
last    2     CRC-16/CCITT-FALSE over everything before it, big-endian
```

* **Version.** 2. A frame from the old link (which had no version byte at the
  link layer at all) is not misread as this one, and `sk_link_bad()` reports
  it, which is how "the wrong firmware is on one end" is told from "no
  signal".
* **Type** is duplicated out of the application payload so that a relay can
  log what it is forwarding without knowing where the payload starts - its
  offset depends on the route. One byte, and it is what makes the
  `relay msg ...` lines possible.
* **Control.** The high nibble is the *hop budget left*, not a count of hops
  travelled; a frame starts at `SK_LINK_HOPS_INIT` (4). Bit 0 is the sender's
  role (1 = router). That single bit is what tells the access point whether a
  wake-up preamble is worth sending - a router is awake by definition - and it
  is what makes "is this tag a router?" visible from the other end of the link
  at all.
* **Sequence** and **origin** together are the message id. They are the
  deduplication key, and both travel unchanged through a relay: the whole
  point is that every copy of a message looks like the same message.
* **Destination.** A 32-bit id, or 0 for broadcast.
* **Route.** §5.

Overhead: **15 bytes** for a frame that no relay has touched (13 header + 2
CRC), +2 per recorded hop. An image block is 96 bytes of image in a 101-byte
application payload, so one block's frame is 118 bytes against the old link's
104: **+13% air time**, which is where most of the transfer's slowdown comes
from (§8).

## 3. Addressing: the compact id

A node's address is `sk_id_from_serial()`: **FNV-1a/32** over its serial with
the letters folded to upper case. The tag's serial comes out of the NFC chip's
NDEF URI; the access point's comes out of an image file name. Folding case
matters - `1408f525` and `1408F525` are the same tag, the old code compared
serials case-insensitively, and two ends that hashed the raw bytes would
disagree about the address of the same label.

The point is that four bytes replace an ASCII serial in every frame, and that
either end can compute the other's address without a handshake: the access
point reads a file name and knows which tag to address; the tag hashes its own
serial once at boot and prints it (`radio: id E5C0F240 (leaf)`), because a
mismatch between the two ends' idea of the id looks exactly like dead
hardware.

`SK_LINK_AP_ID` (`0x534B4150`, `'S','K','A','P'`) is the access point's own
id: it has no NFC serial to hash and there is one access point in this design.
A second one needs its own - build with `-DSK_LINK_AP_ID=...` - or the two
answer each other's traffic.

Broadcast (0) is used for `SK_PKT_ANNOUNCE` (nobody knows this tag exists yet)
and for `IMG_BEGIN`, deliberately: every tag has to hear a transfer start so
that the ones it is not for can refuse it, which is how the access point tells
"wrong tag" from "no tag". Everything else is addressed: `IMG_DATA`/`IMG_END`
to the target tag's id, `IMG_ACK`/`IMG_STATUS` to the id the frame being
answered came from.

## 4. Managed flooding

There is no routing table, no neighbour discovery and no persistent state. A
node that hears a frame it has already handled drops it; otherwise it delivers
it (if it is for this node or a broadcast) and - if it is a router and the hop
budget allows - repeats it.

1. CRC and framing are checked. A frame that fails is dropped and reported
   (`sk_link_bad()`), never acted on.
2. `(origin, seq)` is looked up in a ring of the last `SK_LINK_SEEN` (8)
   messages. A hit is a duplicate: dropped, reported (`sk_link_dup()`), and
   **not** relayed.
3. A miss is recorded, so a copy that arrives later is caught.
4. The frame is delivered if it is a broadcast or addressed to this node.
5. It is relayed if this node is a **router**, the frame is *not* for this
   node, and there is hop budget left. Relay means: hop budget minus one, this
   node's 2-byte short id appended to the route, CRC recomputed, transmit.
6. Before transmitting, the relay waits a short **backoff** of up to
   `SK_LINK_BACKOFF_MS` (96 ms), derived from the message id and its own id.
   Two relays of the same frame therefore almost never start at the same
   moment. This is the whole of the collision avoidance.

**Roles.** A **router** (mains-powered board) stays in continuous receive and
relays. A **leaf** (battery tag) never relays, which is what lets it spend its
life in wake-on-radio. The tag firmware chooses with `-DSK_TAG_ROUTER=1`; a
leaf is the default.

**The seen ring is the whole of the mesh's memory**, and the tradeoff is
stated plainly: eight entries is 40 bytes of XRAM, and a duplicate that turns
up more than eight messages later is not recognised, so it is relayed a second
time. That is a duplicate on the air, not a wrong answer - the application
layer is stop-and-wait and answers a repeated frame exactly as it answered the
first.

**One forward at a time.** A relay holds a single pending frame. If a second
frame needs relaying while one is waiting for its backoff, the second is not
relayed (the origin will send it again). Deliberate: a pointer-free single
slot is what fits in a tag's RAM, and a dropped relay costs a retry.

**The backoff is counted in polls, and each poll with a forward pending burns
a millisecond itself.** A caller that also sleeps between polls therefore sees
up to twice the window (both firmwares do). The window is a collision-avoidance
heuristic, not a protocol constant, so this is noted rather than fixed.

## 5. The record route

Every relay appends **its own 2-byte short id** (the low 16 bits of its full
id) as it forwards, up to `SK_LINK_ROUTE_MAX` (4) entries. A frame that is
already carrying four relays is still forwarded - it just stops recording.

This is the cheap version of IPv4's record-route option, and it exists to
answer one question: **which way did that packet take?** Flooding never
computes a route - copies travel every path and the first to arrive wins - so
the honest answer is observability, not a routing table:

* every relay's console prints what it forwarded:
  `relay msg 00 origin 534B4150 hops 04->03`
* the access point prints the chain it received, on the line *after* the
  check-in:
  ```
  TAG 1408F525 rssi=-64
     path via F240 (01 hops, 03 left)
  ```
  (its own frames coming back through the mesh are reported as
  `link: duplicate msg 00 (our own, handed back by a relay) via F240 (01 hops, 03 left)`)

The path deliberately goes on a second line rather than being appended to the
`TAG ... rssi=...` line: that line's exact shape is what
`tools/send_image.py` matches for `--watch`/check-in, and
`tools/tests/test_send_image.py` pins it, including that trailing junk is *not*
a check-in. Appending here would have silently stopped `--watch` from
recognising the tag.

*Short ids are for display only.* Nothing is ever addressed by an entry in the
route, so two nodes whose short ids collide is a cosmetic problem in a log
line, not a delivery problem.

The **hop budget left** is reported as well (`03 left` above). A frame that
arrives with none left is still delivered to its destination - it just goes no
further.

## 6. Integrity: CRC-16/CCITT-FALSE

One CRC-16 in this project, and it is the one the UART side already used:
poly `0x1021`, init `0xFFFF`, MSB first, no reflection, no final xor. Check
value of `"123456789"` is **0x29B1**.

`sk_link.c` implements it itself rather than calling libmf, for a specific
reason: libmf carries two CRC-16s whose names differ by one letter -
`crc_ccitt_msb()` (the protocol's) and `crc_crc16_msb()` (poly 0x8005, the
Vusion MAC's) - and the wrong one fails silently. Sixty bytes of code that can
be pinned against the published check value is worth more than a name lookup.
`tools/tests/sk_link_test.c` checks it against an independent bitwise
implementation as well as the check value.

The application payload no longer carries its XOR byte. That is the point:
the XOR was the old link's only integrity check, and it cannot see two
flipped bits.

## 7. Wake-on-radio: never sit in receive

The biggest single power lever on a battery tag. In continuous receive the
AX5043 spends its whole life listening - around 12 mA plus the front end's
bias, whether or not anything is there. In WOR it wakes itself every
`RADIO_WOR_PERIOD` low-power-oscillator cycles, listens for about a preamble,
and sleeps in between.

The point is not "transmit less": **the e-paper refresh is the tag's largest
single energy cost**, by a wide margin. The point is *never sit in receive*.

### 7.1 The receiver

`radio_rx_wor_start()` follows `easyax5043.c`'s `ax5043_receiver_on_wor()` line
for line, with the vendor's generated values. Every value below is the
vendor's; none is derived here:

| Register | Value | Where it comes from |
|---|---|---|
| `BGNDRSSIGAIN` | `0x02` | `ax5043_receiver_on_wor()`, WOR only |
| `LPOSCCONFIG` | `0x01` | same: "start LPOSC, slow mode" |
| `RSSIREFERENCE` | `0x3A` | same as the continuous receiver (`config.c`: `0xFA + 64`) |
| `TMGRXAGC` | `0x0A` | `config.c`'s `ax5043_set_registers_rxwor()` |
| `TMGRXPREAMBLE1` | `0x19` | same table: how much preamble to wait for |
| `PKTMISCFLAGS` | `0x03` | same table: `RXRSSICLK | RXAGCCLK` |
| `PKTSTOREFLAGS` | `0x00` | no RSSI/timer chunks in front of the packet |
| `PWRMODE` | `0x0B` | `AX5043_PWRSTATE_WOR_RX` (`easyax5043.h`) |
| `WAKEUPFREQ` | `128` | `config.c`: `axradio_wor_period` |
| `WAKEUP` | period + `WAKEUPTIMER` | `ax5043_receiver_on_wor()` |

Two things the vendor does that are **not** done here, because the vendor's own
guard for them is false on this board: the `F143_WOR_TCXO` power-interrupt
dance (`IRQMASK0 |= 0x80`, `POWIRQMASK = 0x90`) is only armed when the TCXO_EN
signal is passed through to a GPIO - `(PALTRADIO & 0x40) && (PINFUNCPWRAMP &
0x0F) == 0x07` - and `config.c` sets `PALTRADIO = 0x00` with `PINFUNCPWRAMP =
0x82`. And no radio interrupt is enabled at all: this driver polls. If WOR
ever fails to wake on new hardware, that TCXO workaround is the first thing to
add.

`PKTMISCFLAGS` bit 4 (`WORMULTIPKT`, "stay on after a packet") is deliberately
clear, as in the vendor's table. Whether the tag stays awake is the firmware's
business, and it does exactly that: on any received frame the tag switches to
continuous receive, and drops back to WOR after `LEAF_AWAKE_MS` (3 s) with
nothing heard.

### 7.2 The transmitter

A WOR receiver is only on for a fraction of each wake-up period, so it cannot
be expected to catch a 32-bit preamble. `radio_tx_wor()` sends the packet
behind the vendor's long wake-up preamble: `RADIO_WOR_PREAMBLE_UNITS` (164)
bytes of `0xAA`, which is `axradio_phy_preamble_wor_longlen` (4) plus
`axradio_phy_preamble_wor_len` (160) from `config.c`.

That preamble is **`164 bytes = 273 ms`** of air time at 4800 bit/s, and the
units are bytes, not bits: `easyax5043.c`'s short-preamble state writes the
REPEATDATA count as `axradio_txbuffer_cnt >> 3` and debits the counter by
`cnt << 3`, i.e. the counter is in bits and the count field is in bytes. That
also confirms the ordinary 32-bit preamble: `axradio_phy_preamble_len = 32`
(bits) is the driver's `RADIO_PREAMBLE_BYTES = 4` (bytes). The vendor's own
comment - "wor_longlen + wor_len totals to 240.0ms plus 32bits" - is the same
order of magnitude for the WOR part.

So the long preamble costs ~273 ms, and it is used only where it has to be:
the access point sends `IMG_BEGIN` behind it (a leaf is probably asleep and
this is the frame that has to reach it), and a *retry* to a peer that is not
known to be a router. As soon as a peer has spoken once, its role flag says
whether it is a router, and a router gets the ordinary preamble from then on.
On the bench a whole image transfer used the long preamble exactly **once** -
the first `IMG_BEGIN` - and one retry.

The observed wake-up: the tag was in WOR from 16.1 s, the access point's
`IMG_BEGIN` arrived at 51.3 s and the tag logged `radio: awake` - i.e. the
receiver woke inside the long preamble and acquired the frame.

### 7.3 The duty cycle, and the regulatory 1%

* **Configured receive duty.** The wake-up timer runs every 128 LPOSC cycles
  (`axradio_wor_period`, the vendor's value) with the LPOSC in slow mode. The
  manual extract in this repository does not give the slow-mode LPOSC
  frequency or the unit of `TMGRXPREAMBLE1`, so the exact fraction is not
  stated here rather than guessed. What *is* measured is the upper bound on
  the wake-up period: the tag woke on a 273 ms preamble, and a WOR receiver
  can only be caught by a preamble longer than its period plus its listen
  window - so the period is under ~270 ms, i.e. the receiver is on for a
  small fraction of each ~0.2 s, not continuously.
* **The MCU keeps polling.** This driver has no interrupt-driven receive path
  (it polls `FIFOSTAT`), so the MCU does not sleep; the saving is entirely the
  radio's. Making the MCU sleep too would mean an interrupt handler and a
  wake-up path, which is a bigger change than this one and is listed as
  unverified/not done below.
* **868.0-868.6 MHz is duty-cycle limited to 1%** in the EU. Our carrier,
  868.300 MHz, is inside that band. An 11248-byte image is ~118 frames of
  ~165 ms each plus acknowledgements - about **40 s of transmitter-on time**,
  which is under 1% of an hour but over 1% of the ~81 s the transfer takes.
  The rule that matters operationally: **images cannot be pushed more often
  than roughly once every hour per access point** without exceeding the 1%
  duty cycle, and the tooling (`--watch`, the send record) already sends an
  image only when it is new or has changed. A tag's periodic announcement is
  3 frames of ~55 ms every 10 s (router) or 60 s (leaf): 1.7% and 0.3%
  respectively - the router's announcements alone would sit on the limit, so
  an installation that cares should announce less often or move to a
  duty-cycle-free sub-band.

## 8. What it costs, and what it measured

**Build numbers** (SDCC 3.6.0, the flags in `tools/build_firmware.ps1`;
before the link layer in brackets):

| Firmware | ROM | XRAM | Free stack |
|---|---|---|---|
| tag (`shelfkit-vusion`) | 33599 / 59389 (29347) | 6964 / 8192 (6613) | 141 B |
| access point | 16693 / 59389 (12141) | 1104 / 8192 (754) | 177 B |
| dumptool | 8314 / 59389 (8314) | 394 / 8192 | 185 B |

The tag's XRAM went up by 351 bytes (two frame buffers, the seen ring and the
last-frame metadata), its ROM by 4252 - of which `sk_link.c` itself is about
3.6 KB, the rest being the WOR transmit/receive paths and the consoles'
relay/duplicate/path logging. **None of it is internal RAM**: every static in
`sk_link.c` is explicitly `__xdata` and every function `__reentrant`, because
the 128 bytes of directly addressable RAM are the stack's and the linker's
overlay area. (Getting that wrong the first time is exactly what "Could not get
21 consecutive bytes in internal RAM for area OSEG" means; the dumptool, which
does not link the link layer, is byte-for-byte unchanged.)

**Hardware results** (two boards, 20 cm apart - see the power note below):

| | |
|---|---|
| Announcement | tag `radio: id E5C0F240 (leaf)`; access point `TAG 1408F525 rssi=-45` |
| Image transfer, router tag | **80.8 s**, 118 blocks, 1 retry, 11248 bytes, 139 B/s, CRC verified, image displayed |
| Image transfer, leaf tag in WOR | **80.8 s**, same block/retry/CRC result, image displayed |
| Relay | `relay msg 00 origin 534B4150 hops 04->03` on the router; `link: duplicate msg 00 (our own, handed back by a relay) via F240 (01 hops, 03 left)` on the access point |
| WOR | tag enters WOR at 16.1 s, wakes on the access point's long preamble at 51.3 s, returns to WOR 3 s after the exchange ends |

The old link moved the same image in ~40 s (281 B/s). The new one is **about
twice as slow**, and the causes are understood: +13% from the frame header and
CRC, and the rest from the access point's per-block wait window
(`LINK_DATA_WAIT_MS`, 600 ms) - a block is ~200 ms of air and the tag's answer
~60 ms, so a block that is answered promptly still costs the sender most of a
wait slice only when the answer is missed. That window is a *tuning* question,
not a link-design one, and it is the first thing to look at if the transfer
time matters.

## 9. The bench power trap (important for anyone re-testing this)

`RADIO_TXPWR_COEFF` is `0x0FFF` (15 dBm) as committed, and on a bench with the
two boards ~20 cm apart the link **does not work at all in the access
point to tag direction**: four `IMG_BEGIN`s, each behind a 273 ms preamble,
produced no answer, while the tag's announcements were received at -38 dBm.
At `0x0400` (-12 dB) everything in §8 works. This is precisely the failure
mode `radio.h` documents, both directions of it, and it is a property of two
antennas a hand's width apart, not of the link. Every hardware result above was
measured with `-DRADIO_TXPWR_COEFF=0x0400` (the value is overridable from the
build for exactly this reason); the committed value is unchanged.

To reproduce the measurements on this bench, build and flash both ends at the
lower power:

```powershell
powershell -ExecutionPolicy Bypass -File tools/build_firmware.ps1 `
    -Firmware shelfkit-vusion,access-point -Define RADIO_TXPWR_COEFF=0x0400
python tools/axsem-flasher.py firmware/access-point/build/firmware.hex -p COM7
python tools/axsem-flasher.py firmware/shelfkit-vusion/build/firmware.hex -p COM8
# add ,SK_TAG_ROUTER=1 to -Define for the relay measurement instead of WOR
```

The boards are left carrying the committed build (§8's numbers above were
taken before they were put back), so a test that fails at 20 cm with the
committed firmware is this section, not a broken link.

## 10. Unverified, not done, and next

**Unverified**

* **The first answer after a panel refresh is lost.** In four consecutive
  transfers the tag's `IMG_ACK` immediately after `show_image()` never reached
  the access point, while the 118 block answers before it and the announcements
  after it got through; `sk_link_send()` reported success, so the frame was
  transmitted (`radio: tx failed` never appeared) and the loss is on the air or
  in the access point's receiver, not in the tag's transmit path. Sending the
  answer **twice, 250 ms apart** makes the transfer complete reliably (the
  access point drops the second copy as a duplicate), and that is what the tag
  firmware does now. The root cause is not understood and is the first thing
  to chase: the obvious suspects are the access point's receiver state after
  its own `IMG_END` pair and the tag's radio after ~10 s of panel work.
* **The wake-up period and listen window** are the vendor's values, and the
  measured fact is only that a 273 ms preamble wakes the tag (§7.3). The exact
  duty cycle needs the manual's LPOSC frequency, which the repository's manual
  extract does not contain.
* **Range.** Everything here was measured at 20 cm at -12 dB. Nothing has been
  measured across a room or a house, which is the case the mesh and WOR exist
  for.
* **Two relays at once.** With two boards, "relay" means one relay. The
  backoff, the "first copy to arrive wins" behaviour and the hop budget have
  only been exercised on the host (`sk_link_test.c`), never on the air.

**Not done**

* No acknowledgement at the link layer. Reliability is the application's
  (stop-and-wait, per block), deliberately: a link-layer ACK would double the
  frames for a layer whose job here is to carry bytes.
* No channel hopping, no LBT, no rate or power adaptation. Carrier 0 only.
* The MCU does not sleep in WOR - only the radio does (§7.3).
* `PKTMISCFLAGS` bit 4 is left clear; "stay awake" is firmware state instead.
* A tag's role is a compile-time define. A tag that could switch roles at
  runtime (or on a console command) would be nicer, and the frame format
  already carries the bit.
* The tag's own packet dispatch (`handle_packet`) has no host test: it needs
  stubs for the NFC, flash, SPI and panel drivers that do not exist yet. That
  gap is what let `SK_PKT_IMG_END`'s two-byte payload be rejected by a
  three-byte minimum length check for a whole hardware session (see
  `SK_MIN_PAYLOAD` in `shelfkit_proto.h`).

**Where the tests are.** `tools/run_tests.ps1` runs all three suites:
`tools/tests/test_send_image.py` (the host tools, 99 tests),
`tools/tests/sk_link_test.c` (the link layer against a virtual radio, 142
checks - frame layout, CRC, addressing, flooding, hop limit, full route,
duplicates, bad frames, the record route and an end-to-end three-node walk) and
`tools/tests/serial_frame_test.c` (the access point's serial bridge with the
real link layer underneath it, 162 checks).
