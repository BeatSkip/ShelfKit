# Images to send to tags

Drop an image here and name it after the **serial number of the tag** you want it on:

```
images/1408F525.png     -> the tag whose NFC serial is 1408F525
images/20553F69.jpg     -> the tag whose NFC serial is 20553F69
```

PNG, JPEG, BMP and GIF all work. Then:

```powershell
python tools/send_image.py COM8
```

Use the serial the tag itself reports - it reads it out of its NFC chip at boot and announces
it over the radio, and the access point prints it:

```
TAG 1408F525 rssi=-41
```

That printed serial is exactly the file name to use. If you do not know it yet, power the tag
and watch the access point: it announces itself a few seconds after boot.

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
