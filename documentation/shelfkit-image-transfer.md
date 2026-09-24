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
python tools/send_image.py COM8 --watch
```

4. Power the tag. It announces itself over the radio about every 10 seconds, the access
   point prints a line for each one, and the watcher pushes that tag's image:

```
watching C:\...\images: an image is sent when its tag checks in (Ctrl-C to stop)
  send record   C:\...\images\.sent.json (0 tag(s)) - nothing sent yet
ap: *** ShelfKit access point ***
ap: radio ready (silicon rev 51)
ap: listening: 868.300 MHz, 4800 bit/s, FSK
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

Without `--watch` the tool is a one-shot: every image in the folder is converted and sent
once, whatever the record says, and each success is still recorded (so a later `--watch`
does not repeat it).

```powershell
python tools/send_image.py COM8                 # every image in the folder
python tools/send_image.py COM8 -s 1408F525     # just this tag's image
python tools/send_image.py --dry-run            # convert and report, no port
```

| Option | Meaning |
|---|---|
| `-d`, `--dir` | image folder (default `images`) |
| `-s`, `--serial` | only this tag's image; with `--watch`, only this tag's check-ins |
| `-w`, `--watch` | send when the access point reports that a tag checked in |
| `--resend` | forget `.sent.json` first, so every tag gets one push again |
| `-p`, `--port` | serial port (or the first positional argument) |
| `--fit` | `contain` (default, letterbox on white), `cover` (crop to fill), `stretch` |
| `--rotate` | `auto` (default: 90 deg for a landscape source, 0 for a portrait one), `0`, `90`, `180`, `270` |
| `--threshold`, `--red-threshold`, `--red-dominance`, `--dither` | how pixels become black/red/white ink (same defaults as `tools/png2epd.py`) |
| `--dry-run` | convert and report, but do not open the serial port |
| `--monitor` | print the access point's lines for 30 s and send nothing |
| `--ping` | prove the host -> access point link without a tag |
| `--verbose` | show the frames on the wire and every check-in |

A transfer of a full-screen image takes roughly 25-40 seconds: 11248 bytes in 96-byte radio
frames at 4800 bit/s, each one acknowledged, plus the tag's flash writes. In `--watch` the
tag is busy for that long, so its next announcement may arrive while the transfer is
running; the access point only prints TAG lines while it is idle, and any of its output
still sitting in the port buffer is flushed when a transfer starts. Nothing is lost by
that: the tag announces itself again, and the record makes that a no-op.

## When nothing happens

```powershell
python tools/send_image.py COM8 --monitor   # what does the access point say?
python tools/send_image.py COM8 --ping      # did it hear the host at all?
```

- `--monitor` prints the access point's own output for 30 s and summarises which tags were
  heard. No TAG line at all means the tag is out of range, unpowered, or not flashed.
- `--ping` sends `IMG_END` with no transfer open. That needs no radio, no tag and no flash:
  the access point answers `SK_U_STATUS(..., SK_ST_OFFSET)` as soon as it parses the frame.
  An answer means the host -> access point link is fine and anything else is the radio or
  the tag; no answer means the port, the baud rate or the access point firmware.

## The pieces

```
  images/1408F525.png
        |                              tools/send_image.py
        v                              converts, frames, sends, waits for acks
  +-----------+   serial 38400    +--------------+   868.3 MHz, 4800 bit/s   +---------+
  |    PC     | -----------------> | access point | ------------------------> |   tag   |
  +-----------+ <----------------- +--------------+ <------------------------ +---------+
                 "TAG 1408F525"        ^            announce + acks
                 acks                  |
                        reports every announcement while idle
```

- **`tools/send_image.py`** converts the image into the panel's two monochrome planes,
  runs the serial protocol, and in `--watch` reads the access point's `TAG <serial>
  rssi=<db>` lines to decide when to send. It is stop-and-wait: one block out, one
  acknowledgement back, so the tag's flash can keep up with the radio and the PC never runs
  ahead of it.
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
image. `tools/tests/test_send_image.py` checks that against the committed
`firmware/shelfkit-vusion/src/epd_image.c`.

## Keeping a transfer honest

The radio link has no error correction and the AX5043's own CRC is switched off (see
`shelfkit_proto.h`), so the transfer carries three checks:

- an **XOR checksum** in every radio payload, to throw away frames that decoded badly;
- a **16-bit CRC** over the whole image, computed by the PC and verified by the tag after the
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
