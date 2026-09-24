#!/usr/bin/env python3
"""make_test_image.py - draw a panel test card for the imagotag e-paper.

Writes a 152 x 296 portrait PNG (the panel's own orientation, so no rotation
is needed) that makes three things obvious at a glance once it is on a label:

  * which way up the image is   - "TOP" along the top edge, an arrow pointing up
  * that red really is red      - a red band and a red square
  * that the whole area is used - a border all the way round, and corner marks

Name the file after the tag's serial number and drop it in the image folder:

    python tools/make_test_image.py images/1408F525.png
    python tools/send_image.py COM8

Usage:
    python tools/make_test_image.py [out.png] [--serial TEXT] [--fill]
"""

import argparse
import os
import sys

try:
    from PIL import Image, ImageDraw, ImageFont
except ImportError:
    sys.exit("Pillow is required:  pip install pillow")

W, H = 152, 296            # portrait, as the framebuffer sees it

BLACK = (0, 0, 0)
WHITE = (255, 255, 255)
RED = (255, 0, 0)


def font(size):
    """A truetype font if we can find one, else Pillow's bitmap default."""
    for name in ("arial.ttf", "DejaVuSans.ttf", "segoeui.ttf"):
        try:
            return ImageFont.truetype(name, size)
        except OSError:
            continue
    return ImageFont.load_default()


def centred(d, y, text, f, fill):
    w = d.textlength(text, font=f)
    d.text(((W - w) / 2, y), text, font=f, fill=fill)


def main():
    ap = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("out", nargs="?", default="images/1408F525.png",
                    help="where to write the PNG (default: %(default)s)")
    ap.add_argument("--serial", default=None,
                    help="print this instead of the file name (default: the file's base name)")
    ap.add_argument("--fill", action="store_true",
                    help="fill the background with a light pattern instead of white")
    args = ap.parse_args()

    serial = args.serial
    if serial is None:
        serial = os.path.splitext(os.path.basename(args.out))[0]

    img = Image.new("RGB", (W, H), WHITE)
    d = ImageDraw.Draw(img)

    if args.fill:
        # A sparse diagonal hatch: makes a partially refreshed or wrongly
        # clipped image obvious, because the pattern should be uniform.
        for i in range(-H, W, 12):
            d.line([(i, 0), (i + H, H)], fill=(200, 200, 200), width=1)

    # Border all the way round, so it is obvious if the edges are cut off
    d.rectangle([0, 0, W - 1, H - 1], outline=BLACK, width=2)

    # Top edge marker
    f_big = font(22)
    f_med = font(14)
    f_small = font(11)

    centred(d, 8, "TOP", f_big, BLACK)
    d.polygon([(W / 2, 34), (W / 2 - 9, 48), (W / 2 + 9, 48)], fill=BLACK)

    # Red band: the strongest test of the red plane
    d.rectangle([8, 60, W - 9, 84], fill=RED)
    centred(d, 66, "RED", f_med, WHITE)

    # The tag's serial number, large, in the middle
    centred(d, 104, "SERIAL", f_small, BLACK)
    centred(d, 118, serial[:12], f_big, BLACK)

    # Corner marks: black bottom left, red bottom right
    d.rectangle([8, 156, 30, 178], fill=BLACK)
    d.rectangle([W - 31, 156, W - 9, 178], fill=RED)

    # A ruler down the left edge: 10 ticks, so a stretched or shifted image
    # can be measured rather than guessed at
    for i in range(10):
        y = 196 + i * 10
        d.line([(10, y), (10 + (16 if i % 2 == 0 else 8), y)], fill=BLACK, width=1)

    centred(d, H - 62, "bottom", f_small, BLACK)
    d.line([(W / 2, H - 44), (W / 2 - 8, H - 30)], fill=BLACK, width=2)
    d.line([(W / 2, H - 44), (W / 2 + 8, H - 30)], fill=BLACK, width=2)
    d.line([(W / 2 - 8, H - 30), (W / 2 + 8, H - 30)], fill=BLACK, width=2)

    os.makedirs(os.path.dirname(os.path.abspath(args.out)), exist_ok=True)
    img.save(args.out)
    print(f"wrote {args.out}  {W}x{H}  serial={serial}")


if __name__ == "__main__":
    main()
