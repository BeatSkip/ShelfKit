#!/usr/bin/env python3
"""send_image.py - convert an image and push it to one Vusion tag.

Reads an image named after the serial number of the tag it belongs to
(`images/1408F525.png`), converts it to the panel's two one-bit planes and
pushes it through the access point's serial port, which forwards it over the
radio. The serial frame format, the packet flow and the image layout are
defined in `firmware/shared/include/shelfkit_proto.h`; the panel framebuffer
layout is in `firmware/shelfkit-vusion/src/epd.h`:

    plane = black/white first, then red, 5624 bytes each, row major,
            19 bytes per row, MSB = leftmost pixel, 0 = ink, 1 = white.

The transfer is stop-and-wait: one UART frame out, one `SK_U_ACK` back
(which carries the offset the tag has confirmed), so a lost frame costs a
retry instead of a corrupt image.

The pixel conversion is tools/png2epd.py's, imported rather than copied, so an
image that goes over the air comes out exactly like the boot image that
png2epd.py compiles into the firmware: `--rotate 90` means the same thing in
both tools (the source's left edge becomes the top of the frame) and the
classifier thresholds default to the same values.

Usage:
    python tools/send_image.py COM8
    python tools/send_image.py COM8 -s 1408F525          # one tag only
    python tools/send_image.py COM8 -d pictures --fit cover --rotate 0
    python tools/send_image.py COM8 --watch --interval 2 # send files as they appear
    python tools/send_image.py --dry-run                 # convert only, no port
    python tools/send_image.py --selftest                # conversion + framing checks
    python tools/send_image.py --list                    # serial ports

Options:
    -d, --dir DIR      image folder (default: images, created if missing)
    -s, --serial SNR   send only this tag's image
    -w, --watch        keep running and re-scan the folder every --interval s
    -p, --port PORT    serial port (may also be the first positional argument)
    -b, --baud RATE    serial rate (default: 38400, the access point's rate)
        --fit MODE     contain (default, letterbox on white), cover, stretch
        --rotate DEG   auto (default), 0, 90, 180, 270 - clockwise; with auto a
                       landscape source is turned 90 deg clockwise into portrait
        --threshold N  luminance below N becomes black ink (default: 110)
        --red-threshold N    red channel above N can be red ink (default: 110)
        --red-dominance N    red must beat green and blue by N (default: 40)
        --dither       Floyd-Steinberg dithering, as in png2epd.py
        --dry-run      convert, report and write <name>.bw.bin/.red.bin, no port
        --timeout SEC  seconds to wait for one IMG_DATA ack (default: 5)
        --end-timeout SEC    seconds to wait for the IMG_END ack, which arrives
                       after the ~20 s panel refresh (default: 60)
        --retries N    extra attempts per frame (default: 5)
        --verbose      show the frames on the wire
"""

import argparse
import math
import os
import re
import sys
import time

try:
    from PIL import Image
except ImportError:
    sys.exit("Pillow is required:  pip install pillow")

try:
    import serial
    from serial.tools import list_ports
except ImportError:
    sys.exit("pyserial is required:  pip install pyserial")

try:
    from tqdm import tqdm
except ImportError:                     # progress is cosmetic, the transfer is not
    tqdm = None

# The conversion itself lives in png2epd.py, the tool that generated the
# firmware's boot image: reusing it keeps an image that goes over the air
# identical to one that is compiled in. Same-directory import, like
# memdump.py does with flashdump.py.
_TOOLS_DIR = os.path.dirname(os.path.abspath(__file__))
if _TOOLS_DIR not in sys.path:
    sys.path.insert(0, _TOOLS_DIR)
try:
    import png2epd
except ImportError:
    sys.exit("png2epd.py is required next to this script (tools/png2epd.py)")

# ── constants mirrored from shelfkit_proto.h / epd.h ──────────────────────
# tools/tests/test_send_image.py re-reads both headers and asserts these are
# still the same numbers.

SK_PROTO_VERSION = 1

SK_PKT_IMG_ACK = 0x13
SK_PKT_IMG_STATUS = 0x14

SK_ST_OK = 0
SK_ST_BAD_SERIAL = 1
SK_ST_FLASH = 2
SK_ST_CRC = 3
SK_ST_OFFSET = 4
SK_ST_BUSY = 5
SK_ST_UNSUPPORTED = 6

SK_SERIAL_MAX = 16
SK_IMG_DATA_MAX = 96

SK_IMG_W = 152
SK_IMG_H = 296
SK_IMG_PLANE_BYTES = 5624               # 152 * 296 / 8
SK_IMG_TOTAL_BYTES = SK_IMG_PLANE_BYTES * 2     # 11248

SK_UART_SYNC0 = 0xAA
SK_UART_SYNC1 = 0x55
SK_U_IMG_BEGIN = 0x01
SK_U_IMG_DATA = 0x02
SK_U_IMG_END = 0x03
SK_U_ACK = 0x81
SK_U_STATUS = 0x82

SK_UART_PAYLOAD_MAX = 2 + SK_IMG_DATA_MAX       # 98

# ── host-side defaults ────────────────────────────────────────────────────

DEFAULT_BAUD = 38400                    # the access point's rate (see uart.c)
DEFAULT_DIR = "images"
DEFAULT_TIMEOUT = 5.0                   # one acknowledgement
DEFAULT_END_TIMEOUT = 60.0              # the tag refreshes the panel first
DEFAULT_RETRIES = 5                     # extra attempts per frame
DEFAULT_INTERVAL = 2.0                  # --watch re-scan period
DEFAULT_THRESHOLD = 110                 # same luminance cut as png2epd.py
DEFAULT_RED_THRESHOLD = 110
DEFAULT_RED_DOMINANCE = 40
DEFAULT_FIT = "contain"
DEFAULT_ROTATE = "auto"

IMAGE_EXTENSIONS = (".png", ".jpg", ".jpeg", ".bmp", ".gif")

# A file name is a tag serial when it is 1..SK_SERIAL_MAX letters/digits with
# no separator, e.g. 1408F525.
SERIAL_RE = re.compile(r"^[0-9A-Za-z]{1,%d}$" % SK_SERIAL_MAX)

STATUS_NAMES = {
    SK_ST_OK: "OK",
    SK_ST_BAD_SERIAL: "not my serial number",
    SK_ST_FLASH: "SPI flash write failed",
    SK_ST_CRC: "image CRC mismatch",
    SK_ST_OFFSET: "data frame out of order",
    SK_ST_BUSY: "already in a transfer",
    SK_ST_UNSUPPORTED: "unsupported packet type",
}


class TransferError(Exception):
    """The transfer could not be completed (bad frame, status, timeout)."""


def status_text(status):
    """Human-readable name of a SK_ST_* code."""
    if status is None:
        return "no status"
    return STATUS_NAMES.get(status, f"unknown status {status}")


def hexdump(data, limit=32):
    """Compact hex of a frame for --verbose."""
    text = data[:limit].hex(" ")
    if len(data) > limit:
        text += f" ... ({len(data)} bytes)"
    return text


# ── CRC-16/CCITT-FALSE ────────────────────────────────────────────────────
# poly 0x1021, init 0xFFFF, MSB first, no reflection, no final xor - the
# variant shelfkit_proto.h names for the serial frames *and* for the whole
# image CRC in SK_U_IMG_BEGIN. It is what binascii.crc_hqx(data, 0xFFFF)
# computes on the host and libmf's crc_ccitt_msb(buf, len, 0xFFFF) on the
# access point; the check value of "123456789" is 0x29B1. (libmf's other
# entry point, crc_crc16_msb(), is CRC-16/UMTS, poly 0x8005 - not this.) The
# implementation below is standalone so the tool does not depend on
# binascii's variant naming; the tests compare the two byte for byte.

def crc16_ccitt_false(data):
    """CRC-16/CCITT-FALSE of a bytes-like object, as an int."""
    crc = 0xFFFF
    for byte in data:
        crc ^= byte << 8
        for _ in range(8):
            if crc & 0x8000:
                crc = ((crc << 1) ^ 0x1021) & 0xFFFF
            else:
                crc = (crc << 1) & 0xFFFF
    return crc


# ── serial-port frames ────────────────────────────────────────────────────
# [0xAA][0x55][TYPE][LEN][LEN payload bytes][CRC hi][CRC lo]
# with CRC-16/CCITT-FALSE over TYPE, LEN and the payload.

def build_frame(ptype, payload=b""):
    """Build one host -> access point frame."""
    if len(payload) > 0xFF:
        raise TransferError(f"payload too long for one frame: {len(payload)} bytes")
    body = bytes([ptype & 0xFF, len(payload)]) + bytes(payload)
    crc = crc16_ccitt_false(body)
    return bytes([SK_UART_SYNC0, SK_UART_SYNC1]) + body + bytes([crc >> 8, crc & 0xFF])


class FrameParser:
    """Reassemble frames from a byte stream, resynchronising on 0xAA 0x55.

    A frame with a bad length or a bad CRC is dropped and the search for the
    next sync pair continues from just after the rejected sync pair, so junk
    and truncated frames in front of a good frame do not hide it.
    """

    def __init__(self, max_payload=SK_UART_PAYLOAD_MAX):
        self.max_payload = max_payload
        self._buf = bytearray()

    def reset(self):
        self._buf.clear()

    def feed(self, data):
        """Add bytes to the stream, return the complete valid frames found."""
        self._buf += data
        frames = []
        while True:
            frame = self._extract()
            if frame is None:
                return frames
            frames.append(frame)

    def _extract(self):
        buf = self._buf
        while True:
            i = buf.find(b"\xAA\x55")
            if i < 0:
                # No sync: keep a trailing 0xAA, it may be half of one.
                if buf and buf[-1] == SK_UART_SYNC0:
                    del buf[:-1]
                else:
                    buf.clear()
                return None
            if i:
                del buf[:i]
            if len(buf) < 4:                    # need TYPE and LEN as well
                return None
            length = buf[3]
            if length > self.max_payload:       # nonsense length, resync
                del buf[:2]
                continue
            total = 4 + length + 2
            if len(buf) < total:                # frame still incomplete
                return None
            crc = (buf[4 + length] << 8) | buf[5 + length]
            if crc16_ccitt_false(bytes(buf[2:4 + length])) == crc:
                ptype = buf[2]
                payload = bytes(buf[4:4 + length])
                del buf[:total]
                return ptype, payload
            del buf[:2]                         # bad CRC, look for the next sync


class FrameReader:
    """Read frames off anything with pyserial's read()/reset_input_buffer()."""

    def __init__(self, ser, max_payload=SK_UART_PAYLOAD_MAX):
        self._ser = ser
        self._parser = FrameParser(max_payload)
        self._pending = []

    def flush(self):
        """Drop everything buffered - used before a (re)transmission."""
        self._pending.clear()
        self._parser.reset()
        try:
            self._ser.reset_input_buffer()
        except OSError as exc:                  # not fatal, just no flush
            print(f"warning: could not flush the serial input: {exc}", file=sys.stderr)

    def read_frame(self, timeout):
        """Return (type, payload) of the next valid frame, or None on timeout."""
        if self._pending:
            return self._pending.pop(0)
        deadline = time.monotonic() + timeout
        while True:
            remaining = deadline - time.monotonic()
            if remaining <= 0:
                return None
            try:
                chunk = self._ser.read(4096)
            except OSError as exc:
                raise TransferError(f"serial read failed: {exc}") from exc
            if chunk:
                frames = self._parser.feed(chunk)
                if frames:
                    self._pending.extend(frames[1:])
                    return frames[0]


def write_all(ser, data):
    """Write a whole frame, or raise TransferError."""
    try:
        written = ser.write(data)
    except OSError as exc:
        raise TransferError(f"serial write failed: {exc}") from exc
    if written != len(data):
        raise TransferError(f"short serial write: {written} of {len(data)} bytes")


def read_ack(reader, timeout, verbose=False):
    """Wait for the access point's answer: (offset, status) or None on timeout.

    An SK_U_STATUS answer is an abort, not a retry: the access point could not
    deliver the frame at all (no tag, radio failure, tag refused).
    """
    deadline = time.monotonic() + timeout
    while True:
        remaining = deadline - time.monotonic()
        if remaining <= 0:
            return None
        frame = reader.read_frame(remaining)
        if frame is None:
            return None
        ptype, payload = frame
        if ptype == SK_U_STATUS:
            status = payload[0] if payload else None
            detail = payload[1] if len(payload) > 1 else None
            message = f"the access point refused the transfer: {status_text(status)}"
            if detail is not None:
                message += f" (detail 0x{detail:02X})"
            raise TransferError(message)
        if ptype == SK_U_ACK:
            if len(payload) != 3:
                raise TransferError(
                    f"malformed SK_U_ACK: expected 3 bytes, got {len(payload)} "
                    f"({hexdump(payload)})")
            return (payload[0] << 8) | payload[1], payload[2]
        if verbose:
            print(f"  ignoring frame type 0x{ptype:02X}: {hexdump(payload)}",
                  file=sys.stderr)


def exchange(ser, reader, frame, timeout, retries, what, verbose=False):
    """Send one frame and wait for its ack; retry on timeout, return the ack.

    Returns ((offset, status), retries_used).
    """
    attempts = retries + 1
    last = "no answer"
    for attempt in range(1, attempts + 1):
        reader.flush()
        if verbose:
            print(f"  -> {what}: {hexdump(frame)}")
        write_all(ser, frame)
        ack = read_ack(reader, timeout, verbose)
        if ack is not None:
            if verbose:
                print(f"  <- offset {ack[0]}, status {status_text(ack[1])}")
            return ack, attempt - 1
        last = f"no answer within {timeout:g}s"
        if attempt < attempts:
            print(f"  {what}: {last} - retry {attempt}/{retries}", file=sys.stderr)
    raise TransferError(f"{what}: {last} after {attempts} attempt(s)")


def encode_serial(serial_no):
    """Serial number -> the bytes that go into SK_U_IMG_BEGIN.

    The tag compares this against what it read out of its NFC chip, which is
    upper-case (see the SK_PKT_ANNOUNCE printout in the access point), so the
    file name is upper-cased before it goes on the wire.
    """
    text = (serial_no or "").strip().upper()
    if not text:
        raise TransferError("empty serial number")
    if len(text) > SK_SERIAL_MAX:
        raise TransferError(
            f"serial number {text!r} is longer than SK_SERIAL_MAX ({SK_SERIAL_MAX})")
    try:
        return text.encode("ascii")
    except UnicodeEncodeError as exc:
        raise TransferError(f"serial number {text!r} is not ASCII") from exc


def send_block(ser, reader, offset, block, timeout, retries, verbose=False):
    """Send one SK_U_IMG_DATA and return (next offset the tag needs, retries)."""
    payload = bytes([offset >> 8, offset & 0xFF]) + bytes(block)
    frame = build_frame(SK_U_IMG_DATA, payload)
    what = f"IMG_DATA @{offset}"
    attempts = retries + 1
    last = "no answer"
    for attempt in range(1, attempts + 1):
        reader.flush()
        if verbose:
            print(f"  -> {what} ({len(block)} bytes)")
        write_all(ser, frame)
        ack = read_ack(reader, timeout, verbose)
        if ack is None:
            last = f"no answer within {timeout:g}s"
        else:
            ack_offset, status = ack
            if status != SK_ST_OK:
                raise TransferError(
                    f"the tag refused {what}: {status_text(status)}")
            if ack_offset > offset:
                return ack_offset, attempt - 1
            # The access point answered, but the tag has not moved past this
            # block: resend it. A duplicate block is harmless, the tag only
            # reports the next byte it still needs.
            last = f"the tag still needs offset {ack_offset}"
        if attempt < attempts:
            print(f"  {what}: {last} - retry {attempt}/{retries}", file=sys.stderr)
    raise TransferError(f"{what}: {last} after {attempts} attempt(s)")


def make_bar(total, enabled):
    """A tqdm bar with byte counts, throughput and ETA, or None."""
    if not enabled or tqdm is None:
        return None
    return tqdm(total=total, unit="B", unit_scale=True, unit_divisor=1024,
                desc="image", leave=True)


def transfer(ser, serial_no, image, timeout=DEFAULT_TIMEOUT,
             end_timeout=DEFAULT_END_TIMEOUT, retries=DEFAULT_RETRIES,
             progress=True, verbose=False):
    """Run SK_U_IMG_BEGIN / DATA* / END against the access point.

    `ser` is an open pyserial port (or anything with read/write/
    reset_input_buffer). `timeout` covers one IMG_DATA acknowledgement,
    `end_timeout` the answer to IMG_END: the tag only acknowledges that one
    after it has finished the ~20 s e-paper refresh. Returns a stats dict;
    raises TransferError.
    """
    image = bytes(image)
    if len(image) != SK_IMG_TOTAL_BYTES:
        raise TransferError(
            f"image is {len(image)} bytes, expected SK_IMG_TOTAL_BYTES "
            f"({SK_IMG_TOTAL_BYTES})")
    serial_bytes = encode_serial(serial_no)
    total = len(image)
    image_crc = crc16_ccitt_false(image)
    reader = FrameReader(ser)
    reader.flush()

    begin = (bytes([len(serial_bytes)]) + serial_bytes
             + bytes([total >> 8, total & 0xFF, image_crc >> 8, image_crc & 0xFF]))
    started = time.monotonic()
    (offset, status), retry_count = exchange(
        ser, reader, build_frame(SK_U_IMG_BEGIN, begin), timeout, retries,
        f"IMG_BEGIN serial {serial_bytes.decode('ascii')} total {total} "
        f"crc 0x{image_crc:04X}", verbose)
    if status != SK_ST_OK:
        raise TransferError(f"the tag refused IMG_BEGIN: {status_text(status)}")
    if offset > total:
        raise TransferError(
            f"the tag answered IMG_BEGIN with offset {offset}, past the image "
            f"({total} bytes)")
    if offset:
        print(f"  resuming at offset {offset} (the tag already has that much)")

    bar = make_bar(total, progress)
    blocks = 0
    try:
        if bar is not None:
            bar.update(offset)
        while offset < total:
            block = image[offset:offset + SK_IMG_DATA_MAX]
            new_offset, used = send_block(ser, reader, offset, block,
                                          timeout, retries, verbose)
            retry_count += used
            blocks += 1
            if bar is not None:
                bar.update(new_offset - offset)
            offset = new_offset

        end_frame = build_frame(SK_U_IMG_END)
        last = "no answer"
        # The tag answers IMG_END only after the panel refresh (about 20 s),
        # so this one gets its own, generous timeout. Retrying resends only
        # IMG_END - the data blocks are already in the tag's flash.
        if progress:
            print(f"  all data acknowledged, waiting up to {end_timeout:g}s "
                  f"for the panel refresh...")
        for attempt in range(1, retries + 2):
            reader.flush()
            if verbose:
                print(f"  -> IMG_END: {hexdump(end_frame)}")
            write_all(ser, end_frame)
            ack = read_ack(reader, end_timeout, verbose)
            if ack is None:
                last = f"no answer within {end_timeout:g}s"
            else:
                ack_offset, status = ack
                if status == SK_ST_CRC:
                    raise TransferError(
                        "the tag verified the image and the CRC did not match - "
                        "the image was not displayed")
                if status != SK_ST_OK:
                    raise TransferError(
                        f"the tag refused IMG_END: {status_text(status)}")
                if ack_offset >= total:
                    break
                last = f"the tag only confirmed {ack_offset} of {total} bytes"
            if attempt <= retries:
                print(f"  IMG_END: {last} - retry {attempt}/{retries}",
                      file=sys.stderr)
        else:
            raise TransferError(f"IMG_END: {last} after {retries + 1} attempt(s)")
    finally:
        if bar is not None:
            bar.close()

    elapsed = time.monotonic() - started
    return {
        "bytes": total,
        "blocks": blocks,
        "retries": retry_count,
        "seconds": elapsed,
        "crc": image_crc,
    }


# ── image conversion ──────────────────────────────────────────────────────

def plane_byte_index(x, y):
    """Byte offset of pixel (x, y) in a plane.

    Mirrors epd.h: ((uint16_t)y * EPD_W + x) >> 3.
    """
    return (y * SK_IMG_W + x) >> 3


def plane_bit_mask(x):
    """Bit that carries pixel x in its byte - epd.h: 0x80 >> (x & 7)."""
    return 0x80 >> (x & 7)


# The classifier is png2epd.classify_ink, unchanged: red first (a saturated
# red-dominant pixel), then dark enough -> black, everything else white.
classify = png2epd.classify_ink


def prepare_image(im, fit=DEFAULT_FIT, rotate=DEFAULT_ROTATE):
    """Rotate/scale an image to exactly SK_IMG_W x SK_IMG_H RGBA.

    The rotation is png2epd.rotate_image(), so `--rotate 90` means here what
    it means there: the source's left edge becomes the top of the frame.
    `auto` uses 90 for a landscape source and 0 for a portrait one - the
    framebuffer is 152 wide by 296 tall before the source is rotated into it.
    """
    if rotate == "auto":
        degrees = 90 if im.width > im.height else 0
    else:
        degrees = int(rotate)

    im = png2epd.rotate_image(im.convert("RGBA"), degrees)
    width, height = im.size
    if width < 1 or height < 1:
        raise ValueError("the image has no pixels")
    if (width, height) == (SK_IMG_W, SK_IMG_H):
        return im               # already exact: no resampling, boot-image parity

    if fit == "stretch":
        return im.resize((SK_IMG_W, SK_IMG_H), Image.Resampling.LANCZOS)
    if fit == "contain":
        scale = min(SK_IMG_W / width, SK_IMG_H / height)
        size = (max(1, int(width * scale)), max(1, int(height * scale)))
    elif fit == "cover":
        scale = max(SK_IMG_W / width, SK_IMG_H / height)
        size = (max(SK_IMG_W, math.ceil(width * scale)),
                max(SK_IMG_H, math.ceil(height * scale)))
    else:
        raise ValueError(f"unsupported fit mode: {fit}")

    resized = im.resize(size, Image.Resampling.LANCZOS)
    if fit == "contain":
        # Letterbox on white: the panel's white is the substrate.
        canvas = Image.new("RGBA", (SK_IMG_W, SK_IMG_H), (255, 255, 255, 255))
        canvas.paste(resized, ((SK_IMG_W - size[0]) // 2,
                               (SK_IMG_H - size[1]) // 2))
        return canvas

    left = (size[0] - SK_IMG_W) // 2
    top = (size[1] - SK_IMG_H) // 2
    return resized.crop((left, top, left + SK_IMG_W, top + SK_IMG_H))


def to_planes(im, threshold=DEFAULT_THRESHOLD,
              red_threshold=DEFAULT_RED_THRESHOLD,
              red_dominance=DEFAULT_RED_DOMINANCE, dither=False):
    """Convert a 152x296 RGBA image into (black/white plane, red plane).

    A thin, validating wrapper around png2epd.to_planes(), so both paths use
    one implementation of the bit layout: both planes start white (0xFF) and
    ink pixels get their bit cleared, exactly like epd_plane_ink().
    """
    if im.size != (SK_IMG_W, SK_IMG_H):
        raise ValueError(f"expected {SK_IMG_W}x{SK_IMG_H} pixels, got "
                         f"{im.size[0]}x{im.size[1]}")
    bw, red = png2epd.to_planes(im.convert("RGBA"), dither=dither,
                                threshold=threshold,
                                red_threshold=red_threshold,
                                red_dominance=red_dominance)
    if len(bw) != SK_IMG_PLANE_BYTES or len(red) != SK_IMG_PLANE_BYTES:
        raise ValueError(f"png2epd produced {len(bw)}/{len(red)} bytes per plane, "
                         f"expected {SK_IMG_PLANE_BYTES}")
    return bytes(bw), bytes(red)


def count_ink(plane):
    """Ink pixels in one plane (a cleared bit is ink)."""
    return sum((~byte & 0xFF).bit_count() for byte in plane)


def convert_file(path, fit=DEFAULT_FIT, rotate=DEFAULT_ROTATE,
                 threshold=DEFAULT_THRESHOLD, red_threshold=DEFAULT_RED_THRESHOLD,
                 red_dominance=DEFAULT_RED_DOMINANCE, dither=False):
    """Open an image and return (bw_plane, red_plane, source_size, note)."""
    with Image.open(path) as im:
        source_size = im.size
        prepared = prepare_image(im, fit, rotate)
    orientation = ("landscape -> rotated 90 deg clockwise"
                   if rotate == "auto" and source_size[0] > source_size[1]
                   else f"rotate {rotate}")
    note = (f"{source_size[0]}x{source_size[1]} px, {orientation}, fit {fit}"
            + (", dithered" if dither else ""))
    return to_planes(prepared, threshold, red_threshold, red_dominance,
                     dither), note


def plane_report(bw, red, note):
    """The lines a dry run prints about one converted image."""
    lines = [f"  source        {note}",
             f"  panel         {SK_IMG_W}x{SK_IMG_H}, {SK_IMG_PLANE_BYTES} bytes per plane",
             f"  ink           black {count_ink(bw)} px, red {count_ink(red)} px",
             f"  image bytes   {len(bw) + len(red)} "
             f"(black/white then red), CRC-16/CCITT-FALSE "
             f"0x{crc16_ccitt_false(bytes(bw) + bytes(red)):04X}"]
    return lines


# ── folder scanning and one-image jobs ────────────────────────────────────

def find_images(directory, only=None):
    """Return [(SERIAL, path)] for every image file named after a tag.

    `only` restricts the result to one serial (case-insensitive).
    """
    wanted = only.strip().upper() if only else None
    try:
        names = sorted(os.listdir(directory))
    except FileNotFoundError:
        return []
    found = []
    for name in names:
        stem, ext = os.path.splitext(name)
        if ext.lower() not in IMAGE_EXTENSIONS:
            continue
        if not SERIAL_RE.match(stem):
            continue
        if wanted is not None and stem.upper() != wanted:
            continue
        found.append((stem.upper(), os.path.join(directory, name)))
    return found


def file_key(path):
    """Change detector for --watch: size and mtime together."""
    info = os.stat(path)
    return (info.st_size, info.st_mtime_ns)


def dry_run_one(args, serial, path):
    """Convert, report and write the two planes next to the source image."""
    (bw, red), note = convert_file(path, args.fit, args.rotate, args.threshold,
                                   args.red_threshold, args.red_dominance,
                                   args.dither)
    base = os.path.splitext(path)[0]
    bw_path, red_path = base + ".bw.bin", base + ".red.bin"
    with open(bw_path, "wb") as f:
        f.write(bw)
    with open(red_path, "wb") as f:
        f.write(red)

    total = len(bw) + len(red)
    blocks = (total + SK_IMG_DATA_MAX - 1) // SK_IMG_DATA_MAX
    print(f"{os.path.basename(path)} -> tag {serial}")
    for line in plane_report(bw, red, note):
        print(line)
    print(f"  planes        {bw_path}")
    print(f"                {red_path}")
    print(f"  would send    IMG_BEGIN serial {encode_serial(serial).decode('ascii')}, "
          f"total {total}, crc 0x{crc16_ccitt_false(bytes(bw) + bytes(red)):04X}; "
          f"{blocks} IMG_DATA blocks of up to {SK_IMG_DATA_MAX} bytes; IMG_END")
    if args.verbose:
        begin = (bytes([len(encode_serial(serial))]) + encode_serial(serial)
                 + bytes([total >> 8, total & 0xFF]) + b"\x00\x00")
        print(f"  first frame   {hexdump(build_frame(SK_U_IMG_BEGIN, begin))}")
    print("  dry run - the serial port was not opened")


def send_one(args, ser, serial, path):
    """Convert one image and push it to its tag."""
    (bw, red), note = convert_file(path, args.fit, args.rotate, args.threshold,
                                   args.red_threshold, args.red_dominance,
                                   args.dither)
    image = bw + red
    print(f"{os.path.basename(path)} -> tag {serial}  ({note}; "
          f"black {count_ink(bw)} px, red {count_ink(red)} px)")
    stats = transfer(ser, serial, image, timeout=args.timeout,
                     end_timeout=args.end_timeout,
                     retries=args.retries, progress=not args.no_progress,
                     verbose=args.verbose)
    rate = stats["bytes"] / stats["seconds"] if stats["seconds"] else 0.0
    retries = f", {stats['retries']} retries" if stats["retries"] else ""
    print(f"  done: {stats['bytes']} bytes in {stats['seconds']:.1f}s "
          f"({rate:.0f} B/s), {stats['blocks']} blocks{retries}, "
          f"CRC 0x{stats['crc']:04X} verified")
    return stats


def process_pending(args, ser, state):
    """Handle every image that is new or changed since the last scan.

    `state` maps path -> file_key() of what has been handled; a file that
    changes is sent again. Returns (done, failed, seen).
    """
    images = find_images(args.dir, args.serial)
    done = failed = 0
    for serial, path in images:
        try:
            key = file_key(path)
        except OSError as exc:
            print(f"{os.path.basename(path)}: cannot stat: {exc}", file=sys.stderr)
            failed += 1
            continue
        if state.get(path) == key:
            continue
        try:
            if args.dry_run:
                dry_run_one(args, serial, path)
            else:
                send_one(args, ser, serial, path)
        except (TransferError, OSError, ValueError) as exc:
            print(f"{os.path.basename(path)}: {exc}", file=sys.stderr)
            failed += 1
            state.pop(path, None)       # stays pending, the next scan retries
            continue
        state[path] = key
        done += 1
    return done, failed, len(images)


def watch_loop(args, ser):
    """Send images as they appear; Ctrl-C stops."""
    state = {}
    print(f"watching {os.path.abspath(args.dir)} every {args.interval:g}s "
          f"(Ctrl-C to stop)")
    while True:
        process_pending(args, ser, state)
        time.sleep(args.interval)


# ── selftest ──────────────────────────────────────────────────────────────

def run_selftest(verbose=False):
    """Exercise the conversion and the framing on synthetic input."""
    results = []

    def check(name, condition, detail=""):
        results.append((name, bool(condition), detail))
        print(f"{'PASS' if condition else 'FAIL'}  {name}{'  ' + detail if detail else ''}")

    # 1. the reference vector from shelfkit_proto.h's CRC description
    vector = crc16_ccitt_false(b"123456789")
    check("CRC-16/CCITT-FALSE('123456789') == 0x29B1", vector == 0x29B1,
          f"got 0x{vector:04X}")

    # 2. framing round trip, corruption, resynchronisation
    frame = build_frame(SK_U_IMG_DATA, bytes([0x00, 0x60]) + bytes(range(96)))
    parsed = FrameParser().feed(frame)
    check("frame parses back to type and payload",
          len(parsed) == 1 and parsed[0][0] == SK_U_IMG_DATA
          and parsed[0][1] == bytes([0x00, 0x60]) + bytes(range(96)))
    broken = bytearray(frame)
    broken[-1] ^= 0x01
    check("corrupted CRC is rejected", FrameParser().feed(bytes(broken)) == [])
    stream = b"\x00\x11\x22\xAA\x55\x02\x08\x01\x02" + frame
    recovered = FrameParser().feed(stream)
    check("junk and a partial frame in front are skipped",
          len(recovered) == 1 and recovered[0][1] == parsed[0][1])

    # 3. conversion layout: ink bits in the panel's own positions
    im = Image.new("RGB", (SK_IMG_W, SK_IMG_H), (255, 255, 255))
    im.putpixel((0, 0), (0, 0, 0))
    im.putpixel((SK_IMG_W - 1, 0), (255, 0, 0))
    im.putpixel((0, SK_IMG_H - 1), (0, 0, 0))
    im.putpixel((SK_IMG_W - 1, SK_IMG_H - 1), (255, 0, 0))
    bw, red = to_planes(im)
    check("planes are SK_IMG_PLANE_BYTES each",
          len(bw) == SK_IMG_PLANE_BYTES and len(red) == SK_IMG_PLANE_BYTES)
    check("(0,0) black -> bw[0] MSB clear, red untouched",
          bw[0] == 0x7F and red[0] == 0xFF, f"bw[0]=0x{bw[0]:02X} red[0]=0x{red[0]:02X}")
    check("(151,0) red -> red[18] LSB clear, bw untouched",
          red[18] == 0xFE and bw[18] == 0xFF, f"bw[18]=0x{bw[18]:02X} red[18]=0x{red[18]:02X}")
    check("(0,295) black -> bw[5605] MSB clear",
          bw[5605] == 0x7F and red[5605] == 0xFF)
    check("(151,295) red -> red[5623] LSB clear",
          red[5623] == 0xFE and bw[5623] == 0xFF)
    check("white stays 1 everywhere else",
          count_ink(bw) == 2 and count_ink(red) == 2,
          f"black {count_ink(bw)} px, red {count_ink(red)} px")

    # 4. a whole image: block boundaries carry the right offsets
    image = bytes(bw) + bytes(red)
    check("whole image is SK_IMG_TOTAL_BYTES",
          len(image) == SK_IMG_TOTAL_BYTES, f"{len(image)} bytes")
    blocks = [image[i:i + SK_IMG_DATA_MAX] for i in range(0, len(image), SK_IMG_DATA_MAX)]
    rebuilt = bytearray()
    good = True
    for offset in range(0, len(image), SK_IMG_DATA_MAX):
        block = blocks[offset // SK_IMG_DATA_MAX]
        payload = bytes([offset >> 8, offset & 0xFF]) + block
        parsed = FrameParser().feed(build_frame(SK_U_IMG_DATA, payload))
        if not parsed or parsed[0][1][:2] != bytes([offset >> 8, offset & 0xFF]):
            good = False
            break
        rebuilt += parsed[0][1][2:]
    check("BEGIN/DATA/END framing rebuilds the image byte for byte",
          good and bytes(rebuilt) == image,
          f"{len(blocks)} blocks, {len(rebuilt)} bytes")
    check("image CRC is stable across the two implementations",
          crc16_ccitt_false(image) == bitwise_crc_reference(image))
    if verbose:
        print(f"       image CRC 0x{crc16_ccitt_false(image):04X}")

    failed = [name for name, ok, _ in results if not ok]
    print(f"\nselftest: {len(results) - len(failed)}/{len(results)} checks passed")
    return 1 if failed else 0


def bitwise_crc_reference(data):
    """A second, deliberately different CRC-16/CCITT-FALSE implementation.

    Straight from the polynomial, one bit at a time with an explicit feedback
    term (no byte-wide xor-in, no register shifted into a byte buffer). The
    selftest and the tests use it to cross-check the implementation above.
    """
    crc = 0xFFFF
    for byte in bytes(data):
        for bit in range(7, -1, -1):
            feedback = ((crc >> 15) & 1) ^ ((byte >> bit) & 1)
            crc = (crc << 1) & 0xFFFF
            if feedback:
                crc ^= 0x1021
    return crc


# ── command line ──────────────────────────────────────────────────────────

def build_parser():
    ap = argparse.ArgumentParser(
        description=__doc__,
        formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("port", nargs="?", help="serial port (e.g. COM8 or /dev/ttyUSB0)")
    ap.add_argument("-p", "--port", dest="port_opt", default=None, metavar="PORT",
                    help="serial port, same as the positional argument")
    ap.add_argument("-b", "--baud", type=int, default=DEFAULT_BAUD,
                    help=f"serial rate (default: {DEFAULT_BAUD})")
    ap.add_argument("-d", "--dir", default=DEFAULT_DIR,
                    help=f"image folder (default: {DEFAULT_DIR})")
    ap.add_argument("-s", "--serial", default=None,
                    help="send only this tag's image")
    ap.add_argument("-w", "--watch", action="store_true",
                    help="keep running and send images as they appear")
    ap.add_argument("--interval", type=float, default=DEFAULT_INTERVAL,
                    help=f"seconds between folder scans with --watch "
                         f"(default: {DEFAULT_INTERVAL:g})")
    ap.add_argument("--fit", choices=["contain", "cover", "stretch"],
                    default=DEFAULT_FIT,
                    help=f"how the image fills the panel (default: {DEFAULT_FIT})")
    ap.add_argument("--rotate", choices=["auto", "0", "90", "180", "270"],
                    default=DEFAULT_ROTATE,
                    help="clockwise rotation before conversion (default: auto - "
                         "landscape sources are turned 90 deg clockwise)")
    ap.add_argument("--threshold", type=int, default=DEFAULT_THRESHOLD,
                    help=f"luminance below this becomes black ink "
                         f"(default: {DEFAULT_THRESHOLD}, same as png2epd.py)")
    ap.add_argument("--red-threshold", type=int, default=DEFAULT_RED_THRESHOLD,
                    help=f"red channel above this can be red ink "
                         f"(default: {DEFAULT_RED_THRESHOLD}, same as png2epd.py)")
    ap.add_argument("--red-dominance", type=int, default=DEFAULT_RED_DOMINANCE,
                    help=f"red must lead green and blue by this much "
                         f"(default: {DEFAULT_RED_DOMINANCE}, same as png2epd.py)")
    ap.add_argument("--dither", action="store_true",
                    help="Floyd-Steinberg dithering to white/black/red "
                         "(same as png2epd.py --dither)")
    ap.add_argument("--timeout", type=float, default=DEFAULT_TIMEOUT,
                    help=f"seconds to wait for one IMG_DATA acknowledgement "
                         f"(default: {DEFAULT_TIMEOUT:g})")
    ap.add_argument("--end-timeout", type=float, default=DEFAULT_END_TIMEOUT,
                    help=f"seconds to wait for the answer to IMG_END, which the "
                         f"tag sends after the panel refresh "
                         f"(default: {DEFAULT_END_TIMEOUT:g})")
    ap.add_argument("--retries", type=int, default=DEFAULT_RETRIES,
                    help=f"extra attempts per frame (default: {DEFAULT_RETRIES})")
    ap.add_argument("--dry-run", action="store_true",
                    help="convert and report, write the planes, do not open the port")
    ap.add_argument("--no-progress", action="store_true",
                    help="no progress bar")
    ap.add_argument("--verbose", action="store_true",
                    help="show every frame on the wire")
    ap.add_argument("--selftest", action="store_true",
                    help="check the conversion and the framing on synthetic input")
    ap.add_argument("--list", action="store_true",
                    help="list serial ports and exit")
    return ap


def parse_args(argv=None):
    ap = build_parser()
    args = ap.parse_args(argv)

    if args.port and args.port_opt and args.port != args.port_opt:
        ap.error(f"two different ports given: {args.port!r} and {args.port_opt!r}")
    if args.port_opt:
        args.port = args.port_opt
    if not 0 <= args.threshold <= 256:
        ap.error("--threshold must be between 0 and 256")
    if args.red_threshold < 0 or args.red_threshold > 256:
        ap.error("--red-threshold must be between 0 and 256")
    if args.retries < 0:
        ap.error("--retries must not be negative")
    if args.timeout <= 0:
        ap.error("--timeout must be positive")
    if args.end_timeout <= 0:
        ap.error("--end-timeout must be positive")
    if args.interval <= 0:
        ap.error("--interval must be positive")
    return args


def open_port(port, baud):
    """Open the serial port with clear diagnostics."""
    try:
        return serial.Serial(
            port=port,
            baudrate=baud,
            bytesize=serial.EIGHTBITS,
            parity=serial.PARITY_NONE,
            stopbits=serial.STOPBITS_ONE,
            timeout=0.05,           # read poll; the frame deadline is in FrameReader
            xonxoff=False,
            rtscts=False,
            dsrdtr=False,
        )
    except OSError as exc:
        raise TransferError(f"cannot open {port}: {exc}") from exc


def main(argv=None):
    args = parse_args(argv)

    if args.list:
        ports = list_ports.comports()
        if not ports:
            print("no serial ports found")
        for p in ports:
            print(f"{p.device:12s}  {p.description}")
        return 0

    if args.selftest:
        return run_selftest(verbose=args.verbose)

    if not args.dry_run and not args.port:
        build_parser().error("a serial port is required (use --list to see what's "
                             "available, or --dry-run)")

    try:
        os.makedirs(args.dir, exist_ok=True)
    except OSError as exc:
        print(f"cannot create the image folder {args.dir}: {exc}", file=sys.stderr)
        return 1

    ser = None
    try:
        if not args.dry_run:
            ser = open_port(args.port, args.baud)

        if args.watch:
            watch_loop(args, ser)
            return 0

        done, failed, seen = process_pending(args, ser, {})
        if not seen:
            if args.serial:
                print(f"no image for tag {args.serial.upper()} in "
                      f"{os.path.abspath(args.dir)}")
            else:
                print(f"no images in {os.path.abspath(args.dir)} - name one after "
                      f"the tag's serial, e.g. {os.path.join(args.dir, '1408F525.png')}")
            return 1
        if failed:
            print(f"{done} sent, {failed} failed", file=sys.stderr)
            return 1
        return 0
    except TransferError as exc:
        print(f"error: {exc}", file=sys.stderr)
        return 1
    except KeyboardInterrupt:
        print("\ninterrupted")
        return 130
    finally:
        if ser is not None:
            ser.close()


if __name__ == "__main__":
    sys.exit(main())
