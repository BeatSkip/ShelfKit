# Sending an image to a tag

How to get a picture onto one specific shelf label, and how the pieces fit together.

## The normal way: let the tag come to you

1. Put the image in the folder, named after the tag's serial number:
   `images/1408F525.png`
   PNG, JPEG, BMP and GIF all work; the panel is 152 x 296 portrait, so the image is
   scaled to fit and letterboxed or cropped (see `--fit`).
2. Plug the access point in and find its port.
3. Start the watcher:

```powershell
python tools/ap_server.py COM8 --watch
```

4. Power the tag. It announces itself over the radio about every 10 seconds, the access
   point prints a line for each one, and the watcher pushes that tag's image:

```
watching C:\...\images: an image is sent when its tag checks in (Ctrl-C to stop)
  send record   C:\...\images\.sent.json (0 tag(s)) - nothing sent yet
ap: *** ShelfKit access point ***
ap: radio ready (silicon rev 51)
ap: listening: 868.300 MHz, 4800 bit/s, FSK
ap: link: console trace level 1 (frames, retries and verdicts)
ap: TAG 1408F525 rssi=-41
1408F525: checked in - sending 1408F525.png
  done: 11248 bytes in 31.4s (358 B/s), 118 blocks, CRC 0x2624 verified
ap: TAG 1408F525 rssi=-40
ap: TAG 1408F525 rssi=-41
```

The second and third check-ins do nothing: the image on the tag already matches the file.
Edit `images/1408F525.png` and the next announcement (within ~10 s) sends the new version.

`--watch` is driven by the announcements, not by a timer. The tool prints everything the
access point says, so the boot banner and any access point message - `?? checksum
mismatch`, `ACK off=0000 st=04 (no transfer)` - show up as `ap: ...` lines.

### What stops it sending the same image every 10 seconds

The watcher remembers the pair (serial number, file) it last sent, along with that file's
fingerprint - its size and modification time. A check-in is only a reason to send when the
folder holds an image for that tag whose fingerprint is not the one recorded.

The record lives in `images/.sent.json` and is written **only after a transfer
succeeds**, so:

- restarting the tool does not resend everything (the record is on disk);
- a failed transfer is retried on the tag's next announcement, about 10 seconds later,
  with no intervention - an unattended watcher heals itself;
- `--resend` forgets the record first, so every tag gets exactly one push again.

```json
{
  "sent": {
    "1408F525": {"file": "1408F525.png", "size": 32145, "mtime_ns": 1758537600123456700}
  },
  "version": 1
}
```

The record is per image folder and keyed by serial number, so two folders keep two
independent records. It is gitignored, like the `.bw.bin`/`.red.bin` plane dumps that
`--dry-run` writes.

## Sending once

Without `--watch` the tool is **one pass of the same thing**: it waits for each tag to
announce itself and sends that tag's image when it does, then exits. Nothing is transmitted to
a tag that has not checked in.

That gating is the whole point. The access point is a radio bridge - it has no idea who is out
there - and a tag that is off, still booting or refreshing its panel cannot be reached by
transmitting harder. An immediate push spends the access point's whole retry budget and then
reports `the tag did not answer`, which points at the radio when the real answer is "that tag
was not listening yet". Waiting costs nothing when the tag is there (the command returns as
soon as everything has gone out) and turns a misleading failure into an honest one:

```
2 image(s) waiting for their tag to check in:
  1408F525.png -> 1408F525
  ABCD1234.png -> ABCD1234
  waiting up to 120s (a leaf announces every 60s, a router every 10s; Ctrl-C to stop)
ap: TAG 1408F525 rssi=-41
1408F525: checked in - sending 1408F525.png
  done: 11248 bytes in 31.4s (358 B/s), 118 blocks, CRC 0x2624 verified
1408F525 sent
```

An image that is already on its tag is not pending at all - there is nothing to send, and the
command says so and exits. That is "check if there are new images", the same record `--watch`
uses.

```powershell
python tools/ap_server.py COM8                 # one pass, driven by check-ins
python tools/ap_server.py COM8 -s 1408F525     # just this tag's image
python tools/ap_server.py COM8 --wait 30       # give up on a silent tag after 30s
python tools/ap_server.py COM8 --resend        # push everything again
python tools/ap_server.py --dry-run            # convert and report, no port
```

If a tag never checks in, the command does not invent a failure for it:

```
1408F525: no check-in within 120s - nothing was sent to it (is the tag powered, in range, and flashed?)
0 sent, 1 never checked in
```

| Option | Meaning |
|---|---|
| `-d`, `--dir` | image folder (default `images`) |
| `-s`, `--serial` | only this tag's image; with `--watch`, only this tag's check-ins |
| `-w`, `--watch` | keep running: send when the access point reports that a tag checked in |
| `--wait` | how long one pass waits for a tag to check in before giving up on it, in seconds (default 120; a leaf announces every 60 s). Ignored with `--watch` |
| `--resend` | forget `.sent.json` first, so every tag gets one push again |
| `-p`, `--port` | serial port (or the first positional argument) |
| `--fit` | `contain` (default, letterbox on white), `cover` (crop to fill), `stretch` |
| `--rotate` | `auto` (default: 90 deg for a landscape source, 0 for a portrait one), `0`, `90`, `180`, `270` |
| `--threshold`, `--red-threshold`, `--red-dominance`, `--dither` | how pixels become black/red/white ink (same defaults as `tools/png2epd.py`) |
| `--dry-run` | convert and report, but do not open the serial port |
| `--monitor` | print the access point's lines for 30 s and send nothing |
| `--ping` | prove the host -> access point link without a tag |
| `--verbose` | every frame on the wire with its round-trip time, the timeout budgets, where the retries were, and every check-in |

A transfer of a full-screen image takes roughly 25-40 seconds: 11248 bytes in 96-byte radio
frames at 4800 bit/s, each one acknowledged, plus the tag's flash writes. The tag is busy for
that long, so its next announcement may arrive while the transfer is running; the access point
only prints TAG lines while it is idle, and any of its output still sitting in the port buffer
is flushed when a transfer starts. Nothing is lost by that: the tag announces itself again,
and the record makes that a no-op for a finished transfer - and for one that failed, that next
check-in is the retry.

## When nothing happens

```powershell
python tools/ap_server.py COM8 --monitor   # what does the access point say?
python tools/ap_server.py COM8 --ping      # did it hear the host at all?
```

- `--monitor` prints the access point's own output for 30 s and summarises which tags were
  heard. No TAG line at all means the tag is out of range, unpowered, or not flashed.
- `--ping` sends `IMG_END` with no transfer open. That needs no radio, no tag and no flash:
  the access point answers `SK_U_STATUS(..., SK_ST_OFFSET)` as soon as it parses the frame.
  An answer means the host -> access point link is fine and anything else is the radio or
  the tag; no answer means the port, the baud rate or the access point firmware.

## Reading the console trace

Both firmwares narrate themselves on their own serial ports, and the two traces are written to
be read together. The access point prints every host frame it parsed, every radio frame it sent
and heard, every retry and the verdict it handed back; the tag prints every block it accepted,
every flash page it wrote, every refusal and a summary at the end.

`tools/ap_server.py` reads the access point's console on the same port as the frame answers
and prints its lines as `ap: ...`. So one command shows the access point's half of the story
during a real transfer:

```powershell
python tools/ap_server.py COM8 --monitor      # idle: who is announcing
python tools/ap_server.py COM8 --verbose      # a transfer, frame by frame
python tools/ap_server.py COM8 -s 1408F525    # one tag, one image
```

The tag's own console is a separate UART (PB4 on the tag board, 38400 8N1). Its trace is what
says whether a frame the access point sent actually arrived — the access point can only report
silence, and silence has two very different causes.

A working transfer reads like this (access point):

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

and on the tag, for the same blocks:

```
serial number: 1408F525  [from the NDEF URI]
radio: id E5C0F240 (leaf)
radio: announced 1408F525 (as the id above)
radio: listening (leaf, wake-on-radio)
img: BEGIN, erasing 03 sectors
img: receiving 2BF0 bytes, CRC 1234 (sender id 534B4150)
img: data @0000 k=60 -> have 0060 of 2BF0
img: page 0100 ok
...
img: all data in: 2BF0 bytes in 118 blocks (0 repeats), 44 flash pages
img: complete, driving the panel (this is the ~20 s the sender is waiting through)
img: displayed
img: answering END (off 2BF0 st=00 OK) - sent twice
```

### Which line answers which question

| Symptom | Where to look |
|---|---|
| Nothing at all, no `TAG` line | `--monitor`. No announcement means the tag is out of range, unpowered, or its radio never initialised (the tag's boot log says which) |
| `N image(s) waiting for their tag to check in`, then `no check-in within 120s` | The tool never transmitted. The tag is not announcing: power, range, or firmware. This is the one case where nothing was sent, so there is no radio failure to chase |
| `--ping` gets no answer | The port, the baud rate (38400), or the access point is held in reset by an asserted DTR/RTS |
| `ser: rx ... crc ok` never appears | The host's frames are not arriving intact — check the port and the rate. A `ser: rx CRC mismatch`, a `bad length` or a `frame abandoned half-way` line names the exact failure |
| `xfer: BEGIN serial ...` appears, then four `link: tx IMG_BEGIN` and `xfer: the BEGIN went unanswered for 6000 ms` | The access point is transmitting; no tag is answering that serial. Compare the serial with the tag's `serial number:` line and the id with its `radio: id` line |
| `radio: awake (a frame was waiting from the panel refresh)` on the tag | Normal for a pushed image: the BEGIN arrived while the tag was driving its panel, and was taken out of the radio's FIFO when the receive loop started. Without that line the frame would have been discarded when the tag armed wake-on-radio |
| `panel: the SPI bus never completed a byte` on the tag | The panel and the flash are unreachable (SPI clock source or pads), but the tag still came up and still accepts an image — it will store it and not show it. The boot is not blocked by it |
| No tag output at all, not even the banner | The tag stopped before its console: most likely the 32 kHz crystal, so the FRC calibration in `main()` never completes (see the tag readme's known issues). Nothing after `uart_begin()` is gated on serial output, so this is hardware, not the console |
| `link: heard IMG_STATUS` ... `(not the target), ignored` | A second tag is in range and refusing a broadcast — the transfer will be slow, not broken |
| `xfer: block @NNNN not delivered after 10 tries` | The block never landed. On the tag, `img: data @...` says whether it arrived; a gap line (`is ahead of me - a frame is missing`) means the air lost it, a repeat line means the answer was lost on the way back |
| `xfer: no answer to the END in 60 s` | The tag took the END and never reported the refresh — on the tag, `img: refreshing panel` / `img: PANEL REFRESH INCOMPLETE` says whether the panel or the radio is at fault |
| `img: page NNNN VERIFY FAILED` on the tag | The SPI flash took the page and read back something else: a hardware problem, reported honestly rather than displayed |

### Turning the trace up or down

Both levels are compile-time switches, documented in each firmware's readme:

```powershell
powershell -File tools/build_firmware.ps1 -Firmware access-point -Define AP_TRACE=2
powershell -File tools/build_firmware.ps1 -Firmware shelfkit-vusion -Define TAG_TRACE=2
```

Level 2 adds a heartbeat for every wait window that is running out (access point) and every
answer and every frame the link layer hands up (tag). It is for a link that is being brought
up: the extra UART time is air-independent, so it delays the retry that follows it. Level 0
(`-Define AP_TRACE=0`) leaves only the banner and the `TAG` lines, which is what a deployed
access point should run.

## The pieces

```
  images/1408F525.png
        |
        v
  +------------------+  serial 38400  +--------------+  868.3 MHz, 4800 bit/s  +---------+
  | PC: ap_server.py | -------------> | access point | ----------------------> |   tag   |
  +------------------+ <------------ +--------------+ <---------------------- +---------+
      "TAG 1408F525"                     ^             announce + acks
      acks                               |
                              reports every announcement while idle
```

- **`tools/ap_server.py`** is the host program that manages the transfer. It converts the
  image into the panel's two monochrome planes, runs the serial protocol, remembers what each
  tag already has, and reads the access point's `TAG <serial> rssi=<db>` lines to decide when
  to send. It is stop-and-wait: one block out, one acknowledgement back, so the tag's flash can
  keep up with the radio and the PC never runs ahead of it.
- **The access point** listens on the radio while no transfer is running and prints every
  announcement; when the host sends it a frame, it forwards that block to the tag,
  retrying until the tag acknowledges it, and answers the PC with the offset the tag has
  confirmed, or with a status code if it could not deliver.
- **The tag** matches the serial number in the transfer against the one it read from its
  NFC chip, stages the image in its SPI flash, verifies it, and then streams it to the
  panel.

## The image format

The panel (a Good Display GDEW026Z39 with an IL0373 controller) has two one-bit planes: a
black/white plane and a red plane. Each is 152 x 296 pixels, one byte per eight pixels, rows
padded to whole bytes (19 bytes per row), most significant bit leftmost, and **0 means ink,
1 means white**. The two planes are sent black/white first, then red, 5624 bytes each.

An image is therefore 11248 bytes on the air. The tag's XRAM is only 8 KB, so it never holds
the whole thing: it stages the image in its SPI flash at `0x10000` (the upper half of the
128 KiB part, leaving whatever the factory left in the lower half readable by
`tools/memdump.py`) and streams it back out to the panel from there.

The conversion is `tools/png2epd.py`'s, imported rather than copied, so an image that goes
over the air is bit for bit the image that tool would compile into the firmware as a boot
image. `tools/tests/test_ap_server.py` checks that against the committed
`firmware/shelfkit-vusion/src/epd_image.c`.

## Keeping a transfer honest

The radio link has no error correction and the AX5043's own CRC is switched off (see
`shelfkit_proto.h`), so the transfer carries three checks:

- a **CRC-16 over every link frame**, which is what throws away a frame that decoded badly on
  the air (`link: bad frame dropped` on the access point, `radio: bad frame dropped` on the
  tag);
- a **16-bit CRC over the whole image**, computed by the PC and verified by the tag after the
  last byte, so a transfer that went subtly wrong is not displayed;
- **byte offsets and acknowledgements**: every data frame says which image byte it carries,
  and the tag answers with the next offset it still needs. The access point retries a frame
  until the tag's answer moves past it, so a lost frame costs a retry, not a corrupt image.

The tag writes each flash page only once it is complete and reads it back to verify, and it
reports a flash failure to the access point rather than pretending to have stored the image.

## What is still open

- **The tag stages the image in flash but does not keep it across a reboot.** The flash
  region survives, so a "show the image I already have" step is a small addition, but nothing
  reads it back at boot yet.
- **The send record is not verified against the tag.** It says "this tag was given this
  file"; after a tag is reflashed, or its flash is erased, the record still says so and the
  image has to be pushed again with `--resend`.
- **One transfer at a time.** The access point does not queue, and the tag refuses a second
  `BEGIN` while it is receiving (`SK_ST_BUSY`); while one tag is being served, the other
  tags' announcements wait.
- **No authorisation and no encryption**: anyone with a radio and the protocol can change a
  label's picture. This is a bench tool, not a deployment.
- **The tag's flash writes are newly added code** and were verified on the bench, not in the
  field; `SK_ST_FLASH` reports a part that will not take a page.
