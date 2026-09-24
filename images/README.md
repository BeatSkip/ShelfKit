# Images to send to tags

Drop an image here and name it after the **serial number of the tag** you want it on:

```
images/1408F525.png     -> the tag whose NFC serial is 1408F525
images/20553F69.jpg     -> the tag whose NFC serial is 20553F69
```

PNG, JPEG, BMP and GIF all work. Then plug the access point in and start the watcher:

```powershell
python tools/send_image.py COM8 --watch
```

Power the tag. It announces itself over the radio about every 10 seconds, the access point
prints a line for each announcement, and this tool sends the image to that tag:

```
ap: *** ShelfKit access point ***
ap: TAG 1408F525 rssi=-41
1408F525: checked in - sending 1408F525.png
  done: 11248 bytes in 31.4s (358 B/s), 118 blocks, CRC 0x2624 verified
ap: TAG 1408F525 rssi=-40
```

Leave it running. Edit the picture, or drop in a new file for another tag, and it goes out
at that tag's next announcement - within about ten seconds. A tag that is already showing
the current file is not sent anything, and the tool remembers across restarts what each tag
has been given (`images/.sent.json`, gitignored). If a transfer fails, it is tried again at
the next announcement, so an unattended watcher heals itself.

Use the serial the tag itself reports - it reads it out of its NFC chip at boot and
announces it over the radio, and the access point prints it as the `TAG ...` line above.
That printed serial is exactly the file name to use. If you do not know it yet, power the
tag and watch: `python tools/send_image.py COM8 --monitor` prints what the access point
says for 30 seconds and sends nothing.

## Sending once instead

```powershell
python tools/send_image.py COM8                 # every image in this folder, once
python tools/send_image.py COM8 -s 1408F525     # just this tag's image
python tools/send_image.py COM8 --resend        # push again even if it was sent before
```

## What happens to the image

It is scaled to the panel's 152 x 296 portrait frame, quantised to the panel's three inks
(black, white, red) and converted into the two one-bit planes the IL0373 controller wants. The
conversion is `tools/png2epd.py`'s - the same code that builds a compiled-in boot image - so a
picture looks the same whether it is compiled in or sent over the air. The panel is mounted
rotated, so a landscape image is rotated 90 degrees by default; `--rotate 0` turns that off.

A full-screen image takes roughly 35 seconds: 11248 bytes in 96-byte radio frames at
4800 bit/s, each one acknowledged, so a lost frame is retried rather than leaving stripes.

Preview a conversion without touching the radio:

```powershell
python tools/send_image.py --dry-run
```

It writes `<name>.bw.bin` and `<name>.red.bin` next to each image and prints what it would
send, including the image CRC. Those two files are gitignored scratch output.

## The sample

`1408F525.png` is a test card from `tools/make_test_image.py`: "TOP" and an arrow along the
top edge, a red band, black and red corner squares, a measured ruler down one side and a
"bottom" marker. Put it on a label first - it makes it obvious at a glance whether the image
is the right way up, whether red came out red, and whether the whole area was written. Make
one for another tag with:

```powershell
python tools/make_test_image.py images/<serial>.png
```
