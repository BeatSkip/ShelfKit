#!/usr/bin/env python3
"""ap_server.py - the host program that manages image transfers to tags.

It owns both halves of a push: the folder of images named after tag serials
with the record of what each tag already has, and the serial conversation with
the access point. An image (`images/1408F525.png`) is converted to the panel's
two one-bit planes here, framed here, and driven over the access point's serial
port block by block; the access point is the radio bridge on the other end and
knows nothing about images. The serial frame format, the packet flow and the
image layout are defined in `firmware/shared/include/shelfkit_proto.h`; the
panel framebuffer layout is in `firmware/shelfkit-vusion/src/epd.h`:

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

The usual way to use it is `--watch`, which does not poll the folder at all: the
access point prints a "TAG <serial> rssi=<db>" line every time a tag announces
itself (about every 10 s), and the tool sends that tag's image when it checks in
and only if the image is new or has changed since the last successful send. The
pair of (serial, file fingerprint) that was sent is remembered in
`images/.sent.json`, so restarting the tool does not resend anything.

Running it without `--watch` is **one pass of the same thing**: it waits for
each tag to announce itself and sends that tag's image when it does, then exits
once everything has gone out or `--wait` seconds have passed. Nothing is
transmitted to a tag that has not checked in - a tag that is off, still booting
or refreshing its panel cannot be reached by transmitting harder, and trying
only spends the retry budget and reports a failure that says nothing about the
real problem. A tag whose image is already current is skipped; `--resend`
pushes everything again.

Usage:
    python tools/ap_server.py COM8 --watch               # keep running
    python tools/ap_server.py COM8                       # one pass, on check-in
    python tools/ap_server.py COM8 -s 1408F525           # one tag only
    python tools/ap_server.py COM8 -d pictures --fit cover --rotate 0
    python tools/ap_server.py COM8 --monitor             # just print what the
                                                          # access point says
    python tools/ap_server.py COM8 --ping                # is the AP hearing me?
    python tools/ap_server.py --dry-run                  # convert only, no port
    python tools/ap_server.py --selftest                 # conversion + framing
    python tools/ap_server.py --list                     # serial ports

Options:
    -d, --dir DIR      image folder (default: images, created if missing)
    -s, --serial SNR   only this tag's image (with --watch: only this tag)
    -w, --watch        keep running: send when the access point reports that a
                       tag checked in (never gives up)
    -p, --port PORT    serial port (may also be the first positional argument)
    -b, --baud RATE    serial rate (default: 38400, the access point's rate)
        --resend       forget the send record and push every tag's image once
        --wait SEC     how long one pass waits for a tag to check in before
                       giving up on it without sending (default: 120; a leaf
                       announces every 60s). Ignored with --watch
        --fit MODE     contain (default, letterbox on white), cover, stretch
        --rotate DEG   auto (default), 0, 90, 180, 270 - clockwise; with auto a
                       landscape source is turned 90 deg clockwise into portrait
        --threshold N  luminance below N becomes black ink (default: 110)
        --red-threshold N    red channel above N can be red ink (default: 110)
        --red-dominance N    red must beat green and blue by N (default: 40)
        --dither       Floyd-Steinberg dithering, as in png2epd.py
        --dry-run      convert, report and write <name>.bw.bin/.red.bin, no port
        --timeout SEC  seconds to wait for one IMG_DATA ack (default: 10)
        --begin-timeout SEC  seconds to wait for the IMG_BEGIN ack, which comes
                       after the tag has erased its flash (default: 20)
        --end-timeout SEC    seconds to wait for the IMG_END ack, which arrives
                       after the ~20 s panel refresh (default: 60)
        --retries N    extra attempts per frame (default: 5)
        --monitor      print the access point's lines for 30 s, send nothing
        --ping         prove the host -> access point link without a tag
        --verbose      every frame on the wire with its round-trip time, the
                       budgets, where the retries were, and every check-in
"""

import argparse
import contextlib
import json
import math
import os
import re
import shutil
import sys
import tempfile
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
# tools/tests/test_ap_server.py re-reads both headers and asserts these are
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

# The detail byte of an SK_U_STATUS that the *access point* originated, as
# opposed to a tag's refusal forwarded with LINK_D_TAG. Mirrors the LINK_D_*
# defines in firmware/access-point/src/main.c.
LINK_D_TIMEOUT = 0
LINK_D_RADIO = 1
LINK_D_NO_XFER = 2
LINK_D_TAG = 3

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
DEFAULT_TIMEOUT = 10.0                  # one acknowledgement. The access point
                                        # retries a data frame on the radio for
                                        # up to 6 s before it gives up, so this
                                        # has to outlast that - otherwise its
                                        # answer ("I heard you, but the tag did
                                        # not") is never seen, and a tag problem
                                        # looks like a dead serial port.
DEFAULT_BEGIN_TIMEOUT = 20.0            # IMG_BEGIN is the slow one: the tag
                                        # erases three flash sectors before it
                                        # answers, and the access point allows
                                        # 12 s for the whole exchange
DEFAULT_END_TIMEOUT = 60.0              # the tag refreshes the panel first
DEFAULT_RETRIES = 5                     # extra attempts per frame
DEFAULT_THRESHOLD = 110                 # same luminance cut as png2epd.py
DEFAULT_RED_THRESHOLD = 110
DEFAULT_RED_DOMINANCE = 40
DEFAULT_FIT = "contain"
DEFAULT_ROTATE = "auto"

# How long one-shot mode waits for a tag to announce itself before giving up.
#
# Two minutes, because a *leaf* tag (the battery default) announces itself
# every 60 s: a shorter wait would miss a tag that is sitting there perfectly
# healthy. It is a ceiling, not a delay - the command returns as soon as every
# image has been sent - so it only costs time when something is genuinely
# wrong, which is exactly when the report ("no check-in from 1408F525") is
# worth waiting for.
DEFAULT_WAIT = 120.0

# --watch reads the access point instead of polling the folder. These two
# shape that loop: how long one read waits for a line, and how long silence
# has to last before the tool points at the port as the likely problem.
WATCH_READ_TIMEOUT = 0.5
WATCH_SILENCE_HINT = 30.0
WATCH_SILENCE_REPEAT = 60.0
WATCH_LINE_MAX = 512                    # drop a "line" longer than this

# What the access point prints for every announcement it hears
# (report_packet() in firmware/access-point/src/main.c):
#
#   uart_puts("TAG "); <serial, printable chars, '?' for the rest>
#   uart_puts(" rssi="); uart_putdec(rssi); uart_puts("\r\n");
#
# so: "TAG 1408F525 rssi=-41". The serial is printed byte for byte, so a
# non-printable byte arrives as '?'; a space would arrive as a space, which is
# why the serial part is matched as printable non-space characters.
TAG_RE = re.compile(r"^TAG ([!-~]{1,%d}) rssi=(-?\d+)$" % SK_SERIAL_MAX)

IMAGE_EXTENSIONS = (".png", ".jpg", ".jpeg", ".bmp", ".gif")

# The send record: which image each tag has already been given. Kept next to
# the images (and gitignored), so restarting the tool does not resend them.
STATE_FILE = ".sent.json"
STATE_VERSION = 1

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


@contextlib.contextmanager
def scratch_dir():
    """A temporary directory that is actually writable.

    tempfile.TemporaryDirectory() asks for mode 0700, which on Windows becomes
    an owner-only ACL. Inside a file sandbox that does not run as that owner -
    the agent harness's, for instance - every write into the fresh directory
    fails, and because the failure shows up as a PermissionError from
    rmtree() during cleanup it masks the original one. Creating the directory
    with 0o777 sidesteps the whole thing; it is deleted immediately and holds
    nothing but this tool's own scratch file.
    """
    root = tempfile.gettempdir()
    path = None
    for _ in range(200):
        candidate = os.path.join(root, tempfile.gettempprefix()
                                 + next(tempfile._get_candidate_names()))
        try:
            os.mkdir(candidate, 0o777)
        except FileExistsError:
            continue
        path = candidate
        break
    if path is None:
        raise RuntimeError("no free name for a temporary directory in " + root)
    try:
        yield path
    finally:
        shutil.rmtree(path, ignore_errors=True)


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
                self._show_access_point_text(chunk)
                frames = self._parser.feed(chunk)
                if frames:
                    self._pending.extend(frames[1:])
                    return frames[0]

    def _show_access_point_text(self, chunk):
        """Print the access point's plain-text lines seen during a transfer.

        The port carries both binary frame answers and human-readable lines,
        and the binary path throws the text away. That is fine until
        something goes wrong *during* a transfer, which is exactly when the
        access point's own trace ("link: sent ...", "link: heard ...", "??
        STATUS ... ignored") is the only thing that says whether the tag
        answered. Runs of four or more printable characters are printed as
        "ap: ..." lines; a binary frame cannot survive that filter.
        """
        text, run = "", []
        for b in chunk:
            if 32 <= b < 127:
                run.append(chr(b))
                continue
            if len(run) >= 4:
                text += "".join(run) + "\n"
            run = []
        if len(run) >= 4:
            text += "".join(run) + "\n"
        for line in text.splitlines():
            line = line.strip()
            if line:
                print(f"ap: {line}")


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
            # The access point reports its own failures with a status byte
            # borrowed from the tag's vocabulary, so the detail byte is what
            # actually says what happened. Detail 0 is "the tag never
            # answered", which used to surface as "not my serial number" and
            # sent everyone looking at serial numbers and NFC records.
            if detail == LINK_D_TIMEOUT:
                message = ("the tag did not answer: the access point sent the "
                           "frame but heard nothing back")
            elif detail == LINK_D_RADIO:
                message = "the access point could not transmit (radio failure)"
            elif detail == LINK_D_NO_XFER:
                message = ("the access point has no transfer open - a BEGIN "
                           "did not get through")
            else:
                message = f"the tag refused: {status_text(status)}"
            message += f" (status 0x{status:02X}, detail 0x{detail:02X})" \
                if status is not None and detail is not None else ""
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
    """Send one SK_U_IMG_DATA and return (next offset, retries used, seconds).

    The time is the whole exchange for this block, retries included, which is
    what makes the verbose output answer "is this transfer slow because of the
    air, the tag's flash, or the PC".
    """
    payload = bytes([offset >> 8, offset & 0xFF]) + bytes(block)
    frame = build_frame(SK_U_IMG_DATA, payload)
    what = f"IMG_DATA @{offset}"
    attempts = retries + 1
    last = "no answer"
    started = time.monotonic()
    for attempt in range(1, attempts + 1):
        reader.flush()
        if verbose:
            print(f"  -> {what} (block {len(block)} B, frame {len(frame)} B, "
                  f"try {attempt}/{attempts})")
        sent_at = time.monotonic()
        write_all(ser, frame)
        ack = read_ack(reader, timeout, verbose)
        waited = time.monotonic() - sent_at
        if ack is None:
            last = f"no answer within {timeout:g}s"
            if verbose:
                print(f"  <- {what}: nothing came back in {waited:.2f}s")
        else:
            ack_offset, status = ack
            if verbose:
                print(f"  <- {what}: tag is at {ack_offset} "
                      f"(0x{ack_offset:04X}), {status_text(status)}, "
                      f"{waited * 1000:.0f} ms")
            if status != SK_ST_OK:
                raise TransferError(
                    f"the tag refused {what}: {status_text(status)}")
            if ack_offset > offset:
                return ack_offset, attempt - 1, time.monotonic() - started
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
             begin_timeout=DEFAULT_BEGIN_TIMEOUT,
             end_timeout=DEFAULT_END_TIMEOUT, retries=DEFAULT_RETRIES,
             progress=True, verbose=False):
    """Run SK_U_IMG_BEGIN / DATA* / END against the access point.

    `ser` is an open pyserial port (or anything with read/write/
    reset_input_buffer). `timeout` covers one IMG_DATA acknowledgement,
    `begin_timeout` the answer to IMG_BEGIN (the tag erases flash first),
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

    if verbose:
        # What is about to happen, before any of it does: the numbers below
        # are the ones to compare a failure against ("118 blocks" and then
        # "blocks 42" says where it stopped).
        print(f"  transfer: tag {serial_bytes.decode('ascii')}, {total} bytes in "
              f"{(total + SK_IMG_DATA_MAX - 1) // SK_IMG_DATA_MAX} blocks of up to "
              f"{SK_IMG_DATA_MAX} B, image CRC 0x{image_crc:04X}")
        print(f"  budgets:  begin {begin_timeout:g}s, block {timeout:g}s, "
              f"end {end_timeout:g}s, {retries} retry/retries per frame")
        print("  note:     the access point's own console lines print here as "
              "\"ap: ...\" - that is the serial trace from the other end")

    begin = (bytes([len(serial_bytes)]) + serial_bytes
             + bytes([total >> 8, total & 0xFF, image_crc >> 8, image_crc & 0xFF]))
    started = time.monotonic()
    (offset, status), begin_retries = exchange(
        ser, reader, build_frame(SK_U_IMG_BEGIN, begin), begin_timeout, retries,
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
    data_retries = 0
    end_retries = 0
    slowest_at, slowest_s = 0, 0.0
    try:
        if bar is not None:
            bar.update(offset)
        while offset < total:
            block = image[offset:offset + SK_IMG_DATA_MAX]
            at = offset
            new_offset, used, seconds = send_block(ser, reader, offset, block,
                                                   timeout, retries, verbose)
            data_retries += used
            blocks += 1
            if seconds > slowest_s:
                slowest_at, slowest_s = at, seconds
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
                print(f"  -> IMG_END (try {attempt}/{retries + 1}), waiting up to "
                      f"{end_timeout:g}s: the tag refreshes the panel first")
            write_all(ser, end_frame)
            ack = read_ack(reader, end_timeout, verbose)
            if ack is None:
                last = f"no answer within {end_timeout:g}s"
            else:
                ack_offset, status = ack
                if verbose:
                    print(f"  <- IMG_END: tag is at {ack_offset} "
                          f"(0x{ack_offset:04X}), {status_text(status)}")
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
                end_retries += 1
                print(f"  IMG_END: {last} - retry {attempt}/{retries}",
                      file=sys.stderr)
        else:
            raise TransferError(f"IMG_END: {last} after {retries + 1} attempt(s)")
    except TransferError:
        # Where it stopped, before the exception unwinds: a transfer that dies
        # at block 42 of 118 is a different problem from one that dies at 117.
        if verbose:
            print(f"  stopped: {blocks} of "
                  f"{(total + SK_IMG_DATA_MAX - 1) // SK_IMG_DATA_MAX} blocks sent, "
                  f"tag confirmed offset {offset}, {data_retries} retries",
                  file=sys.stderr)
        raise
    finally:
        if bar is not None:
            bar.close()

    elapsed = time.monotonic() - started
    if verbose:
        # Where the retries were. The three phases fail for different reasons
        # (no tag / a lost block / no panel answer), and the slowest block says
        # whether the time went into the air or into the tag's flash.
        print(f"  retries: {begin_retries} begin, {data_retries} over "
              f"{blocks} blocks, {end_retries} end")
        print(f"  timing:  {elapsed / max(blocks, 1) * 1000:.0f} ms per block on "
              f"average, slowest @{slowest_at} took {slowest_s * 1000:.0f} ms")
    return {
        "bytes": total,
        "blocks": blocks,
        "retries": begin_retries + data_retries + end_retries,
        "begin_retries": begin_retries,
        "data_retries": data_retries,
        "end_retries": end_retries,
        "slowest_block": slowest_at,
        "slowest_seconds": slowest_s,
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


def find_image(directory, serial):
    """The image for one tag: [(SERIAL, path)] has at most one entry, or None.

    Name order decides when a folder holds two files for the same serial
    (1408F525.bmp and 1408F525.png), so the choice is at least repeatable.
    """
    found = find_images(directory, only=serial)
    return found[0] if found else None


def fingerprint(path):
    """Size and mtime of an image: what decides whether it needs sending again.

    Replacing a file with different bytes changes at least one of the two;
    rewriting identical bytes may not, which is fine - the panel would show
    the same picture.
    """
    info = os.stat(path)
    return (info.st_size, info.st_mtime_ns)


class SendRecord:
    """What each tag has already been given, persisted as JSON.

    Keyed by serial number, valued by the source file's name plus its
    fingerprint. Only successful transfers are recorded (see send_file()), so
    a tag that checks in again after a failure gets the image retried, and a
    tool that is restarted does not resend everything it sent before.
    """

    def __init__(self, path):
        self.path = path
        self.entries = {}

    def __len__(self):
        return len(self.entries)

    def load(self):
        """Read the record; a missing or unreadable file just means 'nothing sent'."""
        try:
            with open(self.path, encoding="utf-8") as f:
                data = json.load(f)
        except FileNotFoundError:
            self.entries = {}
            return self
        except (OSError, ValueError) as exc:
            print(f"{self.path}: ignoring the send record: {exc}", file=sys.stderr)
            self.entries = {}
            return self
        sent = data.get("sent") if isinstance(data, dict) else None
        if not isinstance(sent, dict):
            print(f"{self.path}: ignoring the send record: no 'sent' table",
                  file=sys.stderr)
            self.entries = {}
            return self
        self.entries = {}
        for serial, entry in sent.items():
            if not isinstance(entry, dict):
                continue
            try:
                self.entries[str(serial)] = (str(entry["file"]),
                                             int(entry["size"]),
                                             int(entry["mtime_ns"]))
            except (KeyError, TypeError, ValueError):
                continue                    # a hand-edited entry is dropped
        return self

    def save(self):
        """Write the record atomically, so a crash cannot truncate it."""
        data = {"version": STATE_VERSION,
                "sent": {serial: {"file": name, "size": size, "mtime_ns": mtime}
                         for serial, (name, size, mtime) in self.entries.items()}}
        tmp = self.path + ".tmp"
        try:
            with open(tmp, "w", encoding="utf-8") as f:
                json.dump(data, f, indent=2, sort_keys=True)
                f.write("\n")
            os.replace(tmp, self.path)
        except OSError as exc:
            print(f"{self.path}: cannot write the send record: {exc}", file=sys.stderr)

    def is_current(self, serial, path, fp):
        """True when this exact file was already sent to this tag."""
        return self.entries.get(serial) == (os.path.basename(path), fp[0], fp[1])

    def record(self, serial, path, fp):
        """Note a successful send and persist it."""
        self.entries[serial] = (os.path.basename(path), fp[0], fp[1])
        self.save()

    def clear(self):
        """Forget everything (--resend)."""
        self.entries = {}
        self.save()


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


def ping(ser, timeout=DEFAULT_TIMEOUT, retries=1):
    """Ask the access point to prove it is reading its serial port.

    IMG_END with no transfer open needs no radio, no tag and no flash: the
    access point answers SK_U_STATUS(offset, SK_ST_OFFSET) with its "no
    transfer" detail as soon as it parses the frame. So this separates the two
    halves of "nothing happened":

      any valid answer   the host -> access point link is fine, so the fault
                         is downstream: the radio, or the tag
      no answer          the access point is not hearing the host at all -
                         wrong port, wrong rate, or (the trap this tool fell
                         into) the board being held in reset by an asserted
                         DTR/RTS that was never released

    Note the answer to a ping is a *refusal* - SK_U_STATUS, not SK_U_ACK - so
    it must be read as proof of life, not run through the transfer path's
    "a status is fatal" logic.
    """
    reader = FrameReader(ser)
    reader.flush()
    frame = build_frame(SK_U_IMG_END)
    attempts = retries + 1

    for attempt in range(1, attempts + 1):
        write_all(ser, frame)
        deadline = time.monotonic() + timeout
        while True:
            remaining = deadline - time.monotonic()
            if remaining <= 0:
                break
            got = reader.read_frame(remaining)
            if got is None:
                break
            ptype, payload = got
            if ptype == SK_U_ACK and len(payload) == 3:
                print(f"the access point answered IMG_END with ACK(offset "
                      f"{(payload[0] << 8) | payload[1]}, "
                      f"{status_text(payload[2])}) after {attempt} attempt(s)")
                print("host -> access point is working; anything still wrong is "
                      "the radio or the tag")
                return 0
            if ptype == SK_U_STATUS and payload:
                detail = payload[1] if len(payload) > 1 else None
                extra = f", detail 0x{detail:02X}" if detail is not None else ""
                print(f"the access point answered IMG_END with "
                      f"{status_text(payload[0])}{extra} after {attempt} "
                      f"attempt(s)")
                print("host -> access point is working: that refusal is the "
                      "correct answer to a ping with no transfer open, and it "
                      "proves the frame was parsed")
                print("anything still wrong is the radio or the tag")
                return 0
            # Any other frame is still an answer from a live access point.
            print(f"the access point answered with frame type 0x{ptype:02X} "
                  f"after {attempt} attempt(s) - it is reading the host")
            return 0
        if attempt < attempts:
            print(f"  no answer within {timeout:g}s - retry {attempt}/{retries}",
                  file=sys.stderr)

    print("the access point did not answer: check the port, the baud rate "
          "(38400), that its firmware is running, and that nothing is holding "
          "the board in reset (the tool releases DTR/RTS when it opens the "
          "port; a terminal that asserts them will silence the board)",
          file=sys.stderr)
    return 1


class LineReader:
    """Read the access point's text output off the same port as the frames.

    The port carries two kinds of bytes: the human-readable lines the access
    point prints while it is idle (banner, "TAG ...", "?? checksum mismatch"),
    and the binary frame answers that come back while a transfer is running.
    This class owns the text side and keeps its own partial-line buffer, so a
    line split across two reads is still one line. Nothing here ever feeds the
    frame parser, and the frame parser never reads through this buffer:
    - before starting a transfer, drop_partial() throws away the half-line the
      transfer is about to take bytes away from (the transfer's own
      FrameReader.flush() empties the port buffer);
    - after a transfer, whatever text arrived meanwhile is read normally, at
      worst with a truncated first line, which simply prints and is ignored.
    """

    def __init__(self, ser):
        self._ser = ser
        self._buf = b""

    def drop_partial(self):
        """Forget a line that was never terminated (call before a transfer)."""
        self._buf = b""

    def read_line(self, timeout=WATCH_READ_TIMEOUT):
        """The next line without its CR/LF, or None if none arrived in time.

        An empty string means an empty line: the access point only ever sends
        CR LF between lines, but a blank line is not worth filtering here.
        """
        deadline = time.monotonic() + timeout
        while True:
            if b"\n" in self._buf:
                line, self._buf = self._buf.split(b"\n", 1)
                return line.rstrip(b"\r").decode("ascii", "replace")
            remaining = deadline - time.monotonic()
            if remaining <= 0:
                return None
            try:
                chunk = self._ser.read(4096)
            except OSError as exc:
                raise TransferError(f"serial read failed: {exc}") from exc
            if chunk:
                self._buf += chunk
                if len(self._buf) > WATCH_LINE_MAX and b"\n" not in self._buf:
                    # Not a line at all: noise, or a rate mismatch. Keep the
                    # tail, it may still be the start of a real line.
                    self._buf = self._buf[-WATCH_LINE_MAX:]


def parse_tag_line(line):
    """The serial number from "TAG 1408F525 rssi=-41", or None.

    The exact shape comes from report_packet() in the access point's main.c:
    "TAG ", the serial as printed, " rssi=" and a signed decimal. Anything
    else - the boot banner, "?? checksum mismatch", a half-received line - is
    not a check-in.
    """
    match = TAG_RE.match(line.strip())
    return match.group(1).upper() if match else None


def send_file(args, ser, serial, path, record=None):
    """Convert one image, push it to its tag and record the success.

    The fingerprint is taken before the transfer: if the file is edited while
    the radio is busy, the next check-in sees the new one and sends it.
    Returns the stats dict; raises TransferError/OSError/ValueError.
    """
    fp = fingerprint(path)
    if args.dry_run:
        dry_run_one(args, serial, path)
        return None
    stats = send_one(args, ser, serial, path)
    if record is not None:
        record.record(serial, path, fp)
    return stats


def dry_run_all(args, ser=None):
    """--dry-run: convert and report every image, without opening a port.

    The port-carrying paths are send_pending() (one pass, on check-in) and
    watch_loop() (forever). This one has no tag to wait for and no port to
    wait on. Returns (failed, seen).
    """
    images = find_images(args.dir, args.serial)
    failed = 0
    for serial, path in images:
        try:
            send_file(args, ser, serial, path, None)
        except (TransferError, OSError, ValueError) as exc:
            print(f"{os.path.basename(path)}: {exc}", file=sys.stderr)
            failed += 1
    return failed, len(images)


def report_no_images(args):
    """The "nothing to do" message for a folder that has no image for the tag."""
    if args.serial:
        print(f"no image for tag {args.serial.upper()} in "
              f"{os.path.abspath(args.dir)}")
    else:
        print(f"no images in {os.path.abspath(args.dir)} - name one after "
              f"the tag's serial, e.g. {os.path.join(args.dir, '1408F525.png')}")


def pending_images(args, record):
    """The images that are not on their tag yet, as {SERIAL: path}.

    This is what "check if there are new images" means: a file whose size and
    modification time match what the record says that tag was last given needs
    nothing doing. `--resend` (which forgets the record) makes everything
    pending again, and so does a tag that has never been sent to.
    """
    pending = {}
    for serial, path in find_images(args.dir, args.serial):
        if record is not None and not args.resend:
            try:
                fp = fingerprint(path)
            except OSError:
                fp = None
            if fp is not None and record.is_current(serial, path, fp):
                continue
        pending[serial] = path
    return pending


def send_pending(args, ser, record):
    """One-shot mode: push what is new, when each tag checks in.

    The access point is a radio bridge with no memory of who is out there, and
    a tag that is not listening cannot be reached by transmitting harder: an
    immediate push at a tag that is off, still booting, or refreshing its panel
    spends the whole retry budget and then reports a failure that says nothing
    about the actual problem. So this waits for each tag to announce itself
    ("TAG <serial> rssi=<db>", which a tag sends every 10 s as a router or
    every 60 s as a leaf) and sends that tag's image when it does.

    Returns an exit code: 0 when everything went out, 1 when something did not.
    """
    images = find_images(args.dir, args.serial)
    if not images:
        report_no_images(args)
        return 1

    # --resend means "forget what was sent": with the record empty, everything
    # is new again. Done here rather than by the caller so that a run cannot
    # depend on the order the two are called in.
    if args.resend and len(record):
        print(f"forgetting {len(record)} send record(s): {record.path}")
        record.clear()

    pending = pending_images(args, record)
    if not pending:
        print(f"nothing to send: {len(images)} image(s) are already on their "
              f"tag(s) (--resend pushes them again)")
        return 0

    print(f"{len(pending)} image(s) waiting for their tag to check in:")
    for serial, path in sorted(pending.items()):
        print(f"  {os.path.basename(path)} -> {serial}")
    print(f"  waiting up to {args.wait:g}s (a leaf announces every 60s, a "
          f"router every 10s; Ctrl-C to stop)")

    deadline = time.monotonic() + args.wait
    sent, failed = check_in_loop(args, ser, record, pending=pending,
                                 deadline=deadline)

    leftover = sorted(pending)
    missed = [serial for serial in leftover if serial not in failed]
    for serial in missed:
        print(f"{serial}: no check-in within {args.wait:g}s - nothing was sent "
              f"to it (is the tag powered, in range, and flashed?)",
              file=sys.stderr)
    if failed:
        # check_in() has already printed what went wrong, per tag.
        print(f"{len(sent)} sent, {len(failed)} failed, {len(missed)} never "
              f"checked in", file=sys.stderr)
        return 1
    if missed:
        print(f"{len(sent)} sent, {len(missed)} never checked in", file=sys.stderr)
        return 1
    print(f"{len(sent)} sent")
    return 0


def check_in(args, ser, serial, record, notes=None):
    """Act on one "TAG <serial>" line from the access point.

    Sends that tag's image when the folder has one and it differs from what
    this tag was last given. Returns one of "sent", "up-to-date", "no-image",
    "failed" or "ignored".
    """
    if args.serial and serial != args.serial.strip().upper():
        return "ignored"
    found = find_images(args.dir, only=serial)
    if not found:
        if notes is not None and ("no-image", serial) not in notes:
            notes.add(("no-image", serial))
            print(f"{serial}: checked in - no {serial}.png/jpg/bmp/gif in "
                  f"{os.path.abspath(args.dir)}")
        return "no-image"
    if len(found) > 1 and notes is not None and ("many", serial) not in notes:
        notes.add(("many", serial))
        print(f"{serial}: {len(found)} images match this tag, using "
              f"{os.path.basename(found[0][1])} and ignoring the rest",
              file=sys.stderr)
    path = found[0][1]
    try:
        fp = fingerprint(path)
    except OSError as exc:
        print(f"{serial}: cannot stat {os.path.basename(path)}: {exc}",
              file=sys.stderr)
        return "failed"
    if record is not None and record.is_current(serial, path, fp):
        if args.verbose and notes is not None and ("current", serial) not in notes:
            notes.add(("current", serial))
            print(f"{serial}: checked in - {os.path.basename(path)} is already "
                  f"on the tag")
        return "up-to-date"
    print(f"{serial}: checked in - sending {os.path.basename(path)}")
    try:
        send_file(args, ser, serial, path, record)
    except (TransferError, OSError, ValueError) as exc:
        # Deliberately not recorded: the tag announces itself again in about
        # 10 s, and that check-in retries the transfer.
        print(f"{serial}: {exc}", file=sys.stderr)
        print(f"{serial}: will try again when the tag checks in next",
              file=sys.stderr)
        return "failed"
    if notes is not None:
        notes.discard(("current", serial))
    return "sent"


def check_in_loop(args, ser, record, pending=None, deadline=None,
                  max_iterations=None):
    """Wait for tags to check in, and act on each one.

    Reads the access point's lines; every line is printed (the boot banner and
    its messages are the operator's only view of the radio side), and a
    "TAG <serial> rssi=<db>" line is a check-in.

    `pending` is {SERIAL: path} - the images still to go out - and the loop
    stops once it is empty. None means "act on every check-in whose image is
    new", which is --watch. `deadline` bounds the whole loop and
    `max_iterations` bounds the number of reads (the tests use it to run the
    real loop over a fake port). Returns (sent, failed), as sets of serials.
    """
    reader = LineReader(ser)
    notes = set()
    sent, failed = set(), set()
    silent_since = time.monotonic()
    iterations = 0

    while ((max_iterations is None or iterations < max_iterations)
           and (deadline is None or time.monotonic() < deadline)
           and (pending is None or pending)):
        iterations += 1
        line = reader.read_line(WATCH_READ_TIMEOUT)
        if line is None:
            if time.monotonic() - silent_since > WATCH_SILENCE_HINT:
                silent_since = time.monotonic() + WATCH_SILENCE_REPEAT
                print(f"no output from the access point for "
                      f"{WATCH_SILENCE_HINT:g}s - is it on {args.port}? "
                      f"(--monitor, --ping)", file=sys.stderr)
            continue
        silent_since = time.monotonic()
        if not line:
            continue
        print(f"ap: {line}")
        serial = parse_tag_line(line)
        if serial is None:
            continue
        if pending is not None and serial not in pending:
            continue                # another tag: not one of ours to send
        # The tag's line is done; anything half-read now belongs to the
        # transfer, not to the text stream.
        reader.drop_partial()
        result = check_in(args, ser, serial, record, notes)
        if result == "sent":
            sent.add(serial)
            failed.discard(serial)
            if pending is not None:
                pending.pop(serial, None)
        elif result == "failed":
            failed.add(serial)
        elif result in ("up-to-date", "no-image") and pending is not None:
            # Nothing to send to this one after all; do not hold the run open
            # waiting for it to check in again.
            pending.pop(serial, None)
    return sent, failed


def watch_loop(args, ser, record=None, max_iterations=None):
    """Send an image when the access point reports that its tag checked in.

    Keeps running: every check-in whose image is new or has changed gets that
    tag's image, forever. Ctrl-C stops.

    `max_iterations` bounds the loop and exists so the tests can run the real
    loop over a fake port; None means "until interrupted".
    """
    record = SendRecord(os.path.join(args.dir, STATE_FILE)) if record is None \
        else record
    record.load()
    if args.resend and len(record):
        print(f"forgetting {len(record)} send record(s): {record.path}")
        record.clear()
    print(f"watching {os.path.abspath(args.dir)}: an image is sent when its tag "
          f"checks in (Ctrl-C to stop)")
    print(f"  send record   {record.path} ({len(record)} tag(s))"
          + ("" if len(record) else " - nothing sent yet"))
    print("  a tag announces itself about every 10s; --monitor shows the access "
          "point's own output")
    check_in_loop(args, ser, record, max_iterations=max_iterations)
    return 0


def send_one(args, ser, serial, path):
    """Convert one image and push it to its tag."""
    (bw, red), note = convert_file(path, args.fit, args.rotate, args.threshold,
                                   args.red_threshold, args.red_dominance,
                                   args.dither)
    image = bw + red
    print(f"{os.path.basename(path)} -> tag {serial}  ({note}; "
          f"black {count_ink(bw)} px, red {count_ink(red)} px)")
    stats = transfer(ser, serial, image, timeout=args.timeout,
                     begin_timeout=args.begin_timeout,
                     end_timeout=args.end_timeout,
                     retries=args.retries, progress=not args.no_progress,
                     verbose=args.verbose)
    rate = stats["bytes"] / stats["seconds"] if stats["seconds"] else 0.0
    retries = f", {stats['retries']} retries" if stats["retries"] else ""
    print(f"  done: {stats['bytes']} bytes in {stats['seconds']:.1f}s "
          f"({rate:.0f} B/s), {stats['blocks']} blocks{retries}, "
          f"CRC 0x{stats['crc']:04X} verified")
    return stats


def monitor(ser, seconds=30.0):
    """Print what the access point says, without sending anything.

    A tag running this firmware re-announces itself about every 10 seconds,
    so a TAG line appearing here (and repeating) is the proof that the tag is
    alive, flashed, in range and talking to the access point. Everything else
    on the line - the boot banner, its own error messages - is printed too,
    because that is the only view of the radio side the host gets.
    """
    print(f"listening for {seconds:g}s - a live tag prints TAG <serial> rssi=<db> "
          f"every ~10s (Ctrl-C to stop)")
    reader = LineReader(ser)
    deadline = time.monotonic() + seconds
    lines = 0
    tags = {}
    try:
        while time.monotonic() < deadline:
            line = reader.read_line(min(WATCH_READ_TIMEOUT, max(0.0, deadline - time.monotonic())))
            if line is None:
                continue
            if not line:
                continue
            lines += 1
            print(f"ap: {line}")
            serial = parse_tag_line(line)
            if serial is not None:
                tags[serial] = tags.get(serial, 0) + 1
    except KeyboardInterrupt:
        print()
    if tags:
        summary = ", ".join(f"{serial} x{count}" for serial, count in sorted(tags.items()))
        print(f"{lines} line(s) from the access point; tags heard: {summary}")
    else:
        print(f"{lines} line(s) from the access point, no TAG line - no tag is "
              f"announcing itself (out of range, unpowered, or not flashed)")
    return 0


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

    # 5. the access point's check-in line
    check("a TAG line parses to its serial",
          parse_tag_line("TAG 1408F525 rssi=-41") == "1408F525"
          and parse_tag_line("TAG 1408F525 rssi=-41\r") == "1408F525")
    check("the banner and other access point lines are not check-ins",
          parse_tag_line("*** ShelfKit access point ***") is None
          and parse_tag_line("?? checksum mismatch (12 bytes, noise?)") is None
          and parse_tag_line("TAG rssi=-41") is None
          and parse_tag_line("TAG 1408F525 rssi=") is None)

    # 6. the send record: what stops a tag being re-sent every 10 seconds
    with scratch_dir() as tmp:
        png = os.path.join(tmp, "1408F525.png")
        record = SendRecord(os.path.join(tmp, STATE_FILE))
        record.record("1408F525", png, (100, 200))
        reloaded = SendRecord(os.path.join(tmp, STATE_FILE)).load()
        check("the send record survives a reload",
              reloaded.is_current("1408F525", png, (100, 200)),
              f"{len(reloaded)} tag(s)")
        check("a changed file or another tag is not current",
              not reloaded.is_current("1408F525", png, (100, 201))
              and not reloaded.is_current("ABCD1234", png, (100, 200)))

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
                    help="send only this tag's image (with --watch: only act on "
                         "this tag's check-ins)")
    ap.add_argument("-w", "--watch", action="store_true",
                    help="keep running: send a tag's image when the access point "
                         "reports that the tag checked in, if the image is new or "
                         "has changed")
    ap.add_argument("--resend", action="store_true",
                    help=f"forget {STATE_FILE} first, so every tag gets one push "
                         f"again")
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
    ap.add_argument("--begin-timeout", type=float, default=DEFAULT_BEGIN_TIMEOUT,
                    help=f"seconds to wait for the answer to IMG_BEGIN, which "
                         f"comes after the tag erases its flash "
                         f"(default: {DEFAULT_BEGIN_TIMEOUT:g})")
    ap.add_argument("--ping", action="store_true",
                    help="check the host -> access point link without using the "
                         "radio, then exit")
    ap.add_argument("--monitor", action="store_true",
                    help="print what the access point says for 30s and send "
                         "nothing; a live tag announces itself every ~10s")
    ap.add_argument("--end-timeout", type=float, default=DEFAULT_END_TIMEOUT,
                    help=f"seconds to wait for the answer to IMG_END, which the "
                         f"tag sends after the panel refresh "
                         f"(default: {DEFAULT_END_TIMEOUT:g})")
    ap.add_argument("--retries", type=int, default=DEFAULT_RETRIES,
                    help=f"extra attempts per frame (default: {DEFAULT_RETRIES})")
    ap.add_argument("--wait", type=float, default=DEFAULT_WAIT,
                    help=f"seconds to wait for a tag to check in before giving "
                         f"up without sending to it (default: {DEFAULT_WAIT:g}; a "
                         f"leaf tag announces itself every 60s). Ignored with "
                         f"--watch, which never gives up")
    ap.add_argument("--dry-run", action="store_true",
                    help="convert and report, write the planes, do not open the port")
    ap.add_argument("--no-progress", action="store_true",
                    help="no progress bar")
    ap.add_argument("--verbose", action="store_true",
                    help="every frame on the wire with its round-trip time, the "
                         "timeout budgets, where the retries were, and every "
                         "check-in")
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
    if args.wait <= 0:
        ap.error("--wait must be positive (it is the time a tag has to check in)")
    if args.timeout <= 0:
        ap.error("--timeout must be positive")
    if args.begin_timeout <= 0:
        ap.error("--begin-timeout must be positive")
    if args.end_timeout <= 0:
        ap.error("--end-timeout must be positive")
    if args.dry_run and (args.watch or args.monitor or args.ping):
        ap.error("--dry-run cannot be combined with --watch, --monitor or --ping: "
                 "they all read the access point's port")
    return args


def open_port(port, baud):
    """Open the serial port with clear diagnostics."""
    try:
        ser = serial.Serial(
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

    # Release DTR and RTS immediately - do not remove this.
    #
    # On these tag boards the CH9102's two handshake lines are wired to the
    # board's reset and boot pins. That is how tools/axsem-flasher.py gets a
    # tag into its bootloader, and it is why flashing always works. But
    # pyserial *drives both lines the moment it opens a port*, and an
    # asserted DTR/RTS holds the board in reset. The symptom is brutally
    # misleading: a perfectly healthy access point prints no banner, no TAG
    # lines and answers nothing at all, so it looks like dead firmware or a
    # broken UART receive - while the same board talks normally the instant
    # these two lines are released.
    ser.dtr = False
    ser.rts = False
    return ser


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

        if args.monitor:
            return monitor(ser, 30.0)

        if args.ping:
            return ping(ser, timeout=args.timeout, retries=args.retries)

        if args.watch:
            watch_loop(args, ser)
            return 0

        # One-shot: one pass, driven by the tags' own check-ins. Successes are
        # recorded, so a second run does not repeat them.
        if args.dry_run:
            failed, seen = dry_run_all(args, ser)
            if not seen:
                report_no_images(args)
                return 1
            return 1 if failed else 0

        record = SendRecord(os.path.join(args.dir, STATE_FILE))
        record.load()
        return send_pending(args, ser, record)
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
