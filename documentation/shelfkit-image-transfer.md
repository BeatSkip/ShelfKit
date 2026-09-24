# Sending an image to a tag

How to get a picture onto one specific shelf label, and how the pieces fit together.

## Using it

1. Put the image in the folder, named after the tag's serial number:
   `images/1408F525.png`
   PNG, JPEG, BMP and GIF all work; the panel is 152 x 296 portrait, so the image is
   scaled to fit and letterboxed or cropped (see `--fit`).
2. Plug the access point in and find its port.
3. Run:

```powershell
python tools/send_image.py COM8
```

It picks up every image in the folder, converts it, and sends it to the tag whose serial
number is the file name. Options:

| Option | Meaning |
|---|---|
| `-d`, `--dir` | image folder (default `images`) |
| `-s`, `--serial` | send only this tag's image |
| `-w`, `--watch` | keep running and send files as they appear |
| `-p`, `--port` | serial port (or the first positional argument) |
| `--fit` | `contain` (default, letterbox on white), `cover` (crop to fill), `stretch` |
| `--rotate` | `auto` (default), `0`, `90`, `180`, `270` |
| `--dry-run` | convert and report, but do not open the serial port |

A transfer of a full-screen image takes roughly 25-40 seconds: 11248 bytes in 96-byte radio
frames at 4800 bit/s, each one acknowledged, plus the tag's flash writes.

## The pieces

```
  images/1408F525.png
        |                              tools/send_image.py
        v                              converts, frames, sends, waits for acks
  +-----------+   serial 38400    +--------------+   868.3 MHz, 4800 bit/s   +---------+
  |    PC     | -----------------> | access point | ------------------------> |   tag   |
  +-----------+ <----------------- +--------------+ <------------------------ +---------+
                    acks              bridges                  acks
```

- **`tools/send_image.py`** converts the image into the panel's two monochrome planes and
  runs the serial protocol. It is stop-and-wait: one block out, one acknowledgement back, so
  the tag's flash can keep up with the radio and the PC never runs ahead of it.
- **The access point** parses the serial frames and forwards each block to the tag over the
  radio, retrying until the tag acknowledges it. It answers the PC with the offset the tag
  has confirmed, or with a status code if it could not deliver.
- **The tag** matches the serial number in the transfer against the one it read from its NFC
  chip, stages the image in its SPI flash, verifies it, and then streams it to the panel.

## The image format

The panel (a Good Display GDEW026Z39 with an IL0373 controller) has two one-bit planes: a
black/white plane and a red plane. Each is 152 x 296 pixels, one byte per eight pixels, rows
padded to whole bytes (19 bytes per row), most significant bit leftmost, and **0 means ink,
1 means white**. The two planes are sent black/white first, then red, 5624 bytes each.

An image is therefore 11248 bytes on the air. The tag's XRAM is only 8 KB, so it never holds
the whole thing: it stages the image in its SPI flash at `0x10000` (the upper half of the
128 KiB part, leaving whatever the factory left in the lower half readable by
`tools/memdump.py`) and streams it back out to the panel from there.

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
- **One transfer at a time.** The access point does not queue, and the tag refuses a second
  `BEGIN` while it is receiving (`SK_ST_BUSY`).
- **No authorisation and no encryption**: anyone with a radio and the protocol can change a
  label's picture. This is a bench tool, not a deployment.
- **The tag's flash writes are newly added code** and were verified on the bench, not in the
  field; `SK_ST_FLASH` reports a part that will not take a page.
