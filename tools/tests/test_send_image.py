#!/usr/bin/env python3
"""Tests for tools/send_image.py - the CRC, the framing, the conversion layout
and the stop-and-wait transfer.

    python -m unittest discover -s tools/tests -v
    python tools/tests/test_send_image.py

The layout tests are the important ones: they pin down the bit positions that
epd.h's epd_plane_ink()/epd_plane_white() use, and they compare the air path
(tools/send_image.py) against the boot path (tools/png2epd.py) for the same
source image, so both produce the same picture on the panel.
"""

import binascii
import contextlib
import io
import os
import random
import re
import subprocess
import sys
import tempfile
import time
import unittest

TOOLS_DIR = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
REPO_DIR = os.path.dirname(TOOLS_DIR)
if TOOLS_DIR not in sys.path:
    sys.path.insert(0, TOOLS_DIR)

from PIL import Image

import png2epd
import send_image

EPD_H_PATH = os.path.join(REPO_DIR, "firmware", "shelfkit-vusion", "src", "epd.h")
PROTO_H_PATH = os.path.join(REPO_DIR, "firmware", "shared", "include",
                            "shelfkit_proto.h")


# ── independent references ────────────────────────────────────────────────

def bitwise_crc16(data):
    """CRC-16/CCITT-FALSE, written differently from the tool's version."""
    crc = 0xFFFF
    for byte in bytes(data):
        crc ^= byte << 8
        for _ in range(8):
            crc <<= 1
            if crc & 0x10000:
                crc ^= 0x1021
            crc &= 0xFFFF
    return crc


def pack_plane(white_pixels):
    """Pack [[bool]] white(1)/ink(0) into the panel's plane layout.

    Deliberately built from pixel coordinates, starting at 0 and *setting*
    bits for white - the inverse of how the converter is written.
    """
    plane = bytearray(send_image.SK_IMG_PLANE_BYTES)
    for y, row in enumerate(white_pixels):
        for x, is_white in enumerate(row):
            if is_white:
                plane[(y * send_image.SK_IMG_W + x) >> 3] |= 0x80 >> (x & 7)
    return bytes(plane)


def epd_h_plane(ink_pixels):
    """Port of epd.h's epd_plane_ink(), arithmetic copied verbatim."""
    plane = bytearray([0xFF]) * send_image.SK_IMG_PLANE_BYTES
    for x, y in ink_pixels:
        plane[(y * send_image.SK_IMG_W + x) >> 3] &= ~(0x80 >> (x & 7)) & 0xFF
    return bytes(plane)


# ── a fake access point ───────────────────────────────────────────────────

class FakeAP:
    """Answers the host the way the access point firmware should.

    Serial side: exposes pyserial's read()/write()/reset_input_buffer() so
    send_image.transfer() can talk to it directly.
    """

    def __init__(self, serial=b"1408F525", total=send_image.SK_IMG_TOTAL_BYTES,
                 drop_first=(), no_ack_once=(), no_ack=(), partial=None,
                 begin_status=0, end_status=0, begin_offset=0, end_delay=0.0,
                 data_status=None):
        self.serial = serial
        self.total = total
        self.drop_first = set(drop_first)     # answer "still need it" once
        self.no_ack_once = set(no_ack_once)   # stay silent once
        self.no_ack = set(no_ack)             # stay silent always
        self.partial = partial                # (offset, n): ack only n bytes
        self.begin_status = begin_status
        self.end_status = end_status
        self.begin_offset = begin_offset
        self.end_delay = end_delay
        self.data_status = data_status        # (offset, status): refuse one block
        self.image = bytearray(total)
        self.offsets = []
        self.expected = 0
        self.begin = None
        self.image_crc = None
        self.end_seen = 0
        self.types_seen = []
        self._parser = send_image.FrameParser()
        self._tx = bytearray()
        self._delayed = []
        self._delayed_at = 0.0
        self._tried = set()

    # -- pyserial's surface ------------------------------------------------
    def write(self, data):
        for ptype, payload in self._parser.feed(bytes(data)):
            self.handle(ptype, payload)
        return len(data)

    def read(self, size=1):
        if self._delayed and time.monotonic() >= self._delayed_at:
            self._tx += self._delayed.pop(0)
        if not self._tx:
            time.sleep(0.001)
            return b""
        chunk = bytes(self._tx[:size])
        del self._tx[:size]
        return chunk

    def reset_input_buffer(self):
        self._tx.clear()

    def close(self):
        pass

    # -- the access point --------------------------------------------------
    def _ack(self, offset, status, delay=0.0):
        frame = send_image.build_frame(
            send_image.SK_U_ACK,
            bytes([offset >> 8, offset & 0xFF, status]))
        if delay:
            self._delayed.append(frame)
            self._delayed_at = time.monotonic() + delay
        else:
            self._tx += frame

    def _status(self, status, detail=0):
        self._tx += send_image.build_frame(send_image.SK_U_STATUS,
                                           bytes([status, detail]))

    def handle(self, ptype, payload):
        self.types_seen.append(ptype)
        if ptype == send_image.SK_U_IMG_BEGIN:
            self.begin = payload
            if self.begin_status:
                self._status(self.begin_status)
                return
            slen = payload[0]
            total = (payload[1 + slen] << 8) | payload[2 + slen]
            self.image_crc = (payload[3 + slen] << 8) | payload[4 + slen]
            assert payload[1:1 + slen] == self.serial, payload[1:1 + slen]
            assert total == self.total, total
            self.image = bytearray(total)
            self.expected = self.begin_offset
            self._ack(self.expected, send_image.SK_ST_OK)
        elif ptype == send_image.SK_U_IMG_DATA:
            offset = (payload[0] << 8) | payload[1]
            data = payload[2:]
            self.offsets.append(offset)
            if offset in self.no_ack:
                return
            if offset in self.no_ack_once and offset not in self._tried:
                self._tried.add(offset)
                return
            if self.data_status and offset == self.data_status[0]:
                self._ack(offset, self.data_status[1])
                return
            if offset in self.drop_first and offset not in self._tried:
                self._tried.add(offset)
                self._ack(offset, send_image.SK_ST_OK)      # "still need it"
                return
            if self.partial and offset == self.partial[0] and offset not in self._tried:
                self._tried.add(offset)
                count = min(self.partial[1], len(data))
                self.image[offset:offset + count] = data[:count]
                self.expected = offset + count
                self._ack(self.expected, send_image.SK_ST_OK)
                return
            if offset != self.expected:
                self._ack(self.expected, send_image.SK_ST_OFFSET)
                return
            self.image[offset:offset + len(data)] = data
            self.expected = offset + len(data)
            self._ack(self.expected, send_image.SK_ST_OK)
        elif ptype == send_image.SK_U_IMG_END:
            self.end_seen += 1
            status = self.end_status or (
                send_image.SK_ST_OK
                if send_image.crc16_ccitt_false(bytes(self.image)) == self.image_crc
                else send_image.SK_ST_CRC)
            self._ack(self.total, status, self.end_delay)


def test_image():
    """11248 deterministic bytes to push through the protocol."""
    return bytes((i * 7 + 3) & 0xFF for i in range(send_image.SK_IMG_TOTAL_BYTES))


def run_transfer(ap, image=None, **kwargs):
    image = test_image() if image is None else image
    kwargs.setdefault("timeout", 0.2)
    kwargs.setdefault("end_timeout", 1.0)
    kwargs.setdefault("progress", False)
    return send_image.transfer(ap, ap.serial.decode("ascii"), image, **kwargs)


# ── the tests ─────────────────────────────────────────────────────────────

class CrcTests(unittest.TestCase):

    def test_reference_vector(self):
        """CRC-16/CCITT-FALSE('123456789') is 0x29B1 (the header's check value)."""
        self.assertEqual(send_image.crc16_ccitt_false(b"123456789"), 0x29B1)
        # The header names binascii.crc_hqx(data, 0xFFFF) as the host-side
        # equivalent. Do not assume it: assert the check value first, then the
        # agreement over real data.
        self.assertEqual(binascii.crc_hqx(b"123456789", 0xFFFF), 0x29B1)

    def test_matches_bitwise_reference_and_crc_hqx(self):
        rng = random.Random(20240517)
        for size in (0, 1, 2, 3, 95, 96, 255, 256, 1000, 5624, send_image.SK_IMG_TOTAL_BYTES):
            data = bytes(rng.randrange(256) for _ in range(size))
            mine = send_image.crc16_ccitt_false(data)
            self.assertEqual(mine, bitwise_crc16(data), f"size {size}")
            self.assertEqual(mine, binascii.crc_hqx(data, 0xFFFF), f"size {size}")

    def test_same_variant_for_frames_and_for_the_image(self):
        """One implementation serves both the frame CRC and the image CRC."""
        image = test_image()
        self.assertEqual(send_image.crc16_ccitt_false(image),
                         send_image.bitwise_crc_reference(image))

    def test_not_the_umts_variant(self):
        """0x8005/CRC-16/UMTS would give a different value - make sure we are
        not accidentally computing that one."""
        data = b"123456789"
        umts = 0xFFFF
        for byte in data:
            umts ^= byte
            for _ in range(8):
                umts = (umts >> 1) ^ 0xA001 if umts & 1 else umts >> 1
        self.assertNotEqual(send_image.crc16_ccitt_false(data), umts)


class FrameTests(unittest.TestCase):

    def setUp(self):
        self.payload = bytes([0x00, 0x60]) + bytes(range(96))
        self.frame = send_image.build_frame(send_image.SK_U_IMG_DATA, self.payload)

    def test_header_layout(self):
        self.assertEqual(self.frame[0], send_image.SK_UART_SYNC0)
        self.assertEqual(self.frame[1], send_image.SK_UART_SYNC1)
        self.assertEqual(self.frame[2], send_image.SK_U_IMG_DATA)
        self.assertEqual(self.frame[3], len(self.payload))
        self.assertEqual(len(self.frame), 4 + len(self.payload) + 2)
        crc = (self.frame[-2] << 8) | self.frame[-1]
        self.assertEqual(crc, send_image.crc16_ccitt_false(self.frame[2:-2]))

    def test_round_trip(self):
        frames = send_image.FrameParser().feed(self.frame)
        self.assertEqual(frames, [(send_image.SK_U_IMG_DATA, self.payload)])

    def test_corrupted_crc_is_rejected(self):
        broken = bytearray(self.frame)
        broken[-1] ^= 0x01
        self.assertEqual(send_image.FrameParser().feed(bytes(broken)), [])
        broken = bytearray(self.frame)
        broken[-2] ^= 0x80
        self.assertEqual(send_image.FrameParser().feed(bytes(broken)), [])

    def test_corrupted_payload_is_rejected(self):
        broken = bytearray(self.frame)
        broken[10] ^= 0xFF
        self.assertEqual(send_image.FrameParser().feed(bytes(broken)), [])

    def test_junk_and_partial_frame_before_a_valid_frame(self):
        junk = b"\x00\x11\x22\xAA\x33"
        partial = b"\xAA\x55\x02\x08\x01\x02"        # promises 8 bytes, has 2
        frames = send_image.FrameParser().feed(junk + partial + self.frame)
        self.assertEqual(frames, [(send_image.SK_U_IMG_DATA, self.payload)])

    def test_bad_length_is_rejected(self):
        # LEN above SK_UART_PAYLOAD_MAX: resynchronise instead of waiting for
        # bytes that can never be part of a legal frame.
        overlong = b"\xAA\x55\x02\xFF" + bytes(10)
        good = send_image.build_frame(send_image.SK_U_ACK, bytes([0, 0, 0]))
        frames = send_image.FrameParser().feed(overlong + good)
        self.assertEqual(frames, [(send_image.SK_U_ACK, bytes([0, 0, 0]))])

    def test_split_across_feeds(self):
        parser = send_image.FrameParser()
        self.assertEqual(parser.feed(self.frame[:3]), [])
        self.assertEqual(parser.feed(self.frame[3:20]), [])
        self.assertEqual(parser.feed(self.frame[20:]),
                         [(send_image.SK_U_IMG_DATA, self.payload)])
        self.assertEqual(parser.feed(self.frame), [(send_image.SK_U_IMG_DATA, self.payload)])

    def test_two_frames_in_one_chunk(self):
        end = send_image.build_frame(send_image.SK_U_IMG_END)
        frames = send_image.FrameParser().feed(self.frame + end)
        self.assertEqual(frames, [(send_image.SK_U_IMG_DATA, self.payload),
                                  (send_image.SK_U_IMG_END, b"")])


class ConversionLayoutTests(unittest.TestCase):
    """The bit positions that, if wrong, scramble the picture on the panel."""

    W = send_image.SK_IMG_W
    H = send_image.SK_IMG_H

    def setUp(self):
        self.black = {(0, 0), (0, self.H - 1)}
        self.red = {(self.W - 1, 0), (self.W - 1, self.H - 1)}
        self.black |= {(x, 20) for x in range(self.W)}          # horizontal line
        self.black |= {(10, y) for y in range(self.H)}          # vertical line
        im = Image.new("RGBA", (self.W, self.H), (255, 255, 255, 255))
        for x, y in self.black:
            im.putpixel((x, y), (0, 0, 0, 255))
        for x, y in self.red:
            im.putpixel((x, y), (255, 0, 0, 255))
        im.putpixel((5, 5), (0, 0, 0, 0))       # transparent black -> white
        self.im = im
        self.bw, self.red_plane = send_image.to_planes(im)

    def test_plane_sizes(self):
        self.assertEqual(len(self.bw), send_image.SK_IMG_PLANE_BYTES)
        self.assertEqual(len(self.red_plane), send_image.SK_IMG_PLANE_BYTES)
        self.assertEqual(send_image.SK_IMG_PLANE_BYTES, 5624)
        self.assertEqual(send_image.SK_IMG_TOTAL_BYTES, 11248)

    def test_exact_bytes_at_known_pixel_positions(self):
        # Row 0: black at x=0 (MSB of byte 0), red at x=151 (LSB of byte 18).
        self.assertEqual(self.bw[0], 0x7F)
        self.assertEqual(self.bw[18], 0xFF)
        self.assertEqual(self.red_plane[0], 0xFF)
        self.assertEqual(self.red_plane[18], 0xFE)
        # Row 20 is the horizontal black line: 19 bytes of pure ink.
        self.assertEqual(self.bw[20 * 19:20 * 19 + 19], b"\x00" * 19)
        # Last row: black at x=0 -> byte 5605 bit 7, red at x=151 -> byte 5623 bit 0.
        self.assertEqual(self.bw[5605], 0x7F)
        self.assertEqual(self.bw[5623], 0xFF)
        self.assertEqual(self.red_plane[5605], 0xFF)
        self.assertEqual(self.red_plane[5623], 0xFE)
        # Vertical line at x=10: byte 1 of every row, bit 0x80 >> 2 = 0x20.
        # (Row 20 is the horizontal line, so every bit of its bytes is ink.)
        for y in range(self.H):
            if y == 20:
                continue
            self.assertEqual(self.bw[y * 19 + 1], 0xDF, f"row {y}")
        for y in range(self.H):
            self.assertEqual(self.red_plane[y * 19 + 1], 0xFF, f"row {y}")
        # The fully transparent pixel at (5,5) is white, so row 5 byte 0 is
        # untouched by it.
        self.assertEqual(self.bw[5 * 19], 0xFF)

    def test_matches_an_independently_packed_plane(self):
        # In the black/white plane a red pixel stays white, and vice versa.
        white = [[(x, y) not in self.black for x in range(self.W)]
                 for y in range(self.H)]
        self.assertEqual(self.bw, pack_plane(white))
        white_red = [[(x, y) not in self.red for x in range(self.W)]
                     for y in range(self.H)]
        self.assertEqual(self.red_plane, pack_plane(white_red))

    def test_matches_epd_h_plane_helpers(self):
        """The proof that the air layout equals epd_plane_ink()'s arithmetic."""
        self.assertEqual(self.bw, epd_h_plane(self.black))
        self.assertEqual(self.red_plane, epd_h_plane(self.red))

    def test_ink_counts(self):
        self.assertEqual(send_image.count_ink(self.bw), len(self.black))
        self.assertEqual(send_image.count_ink(self.red_plane), len(self.red))

    def test_only_ink_pixels_are_cleared(self):
        ink_bw = {send_image.plane_byte_index(x, y) for x, y in self.black}
        for index in range(send_image.SK_IMG_PLANE_BYTES):
            if index not in ink_bw:
                self.assertEqual(self.bw[index], 0xFF, f"byte {index}")

    def test_classification_thresholds(self):
        self.assertEqual(send_image.classify(255, 0, 0), "red")
        self.assertEqual(send_image.classify(120, 20, 20), "red")
        self.assertEqual(send_image.classify(255, 255, 255), "white")
        self.assertEqual(send_image.classify(100, 100, 100), "black")
        self.assertEqual(send_image.classify(200, 200, 200), "white")
        # threshold moves the black/white line: a uniform 150 grey is all ink
        # at --threshold 200 and all white at --threshold 100.
        self.assertEqual(send_image.to_planes(
            self._solid((150, 150, 150)), threshold=200)[0][0], 0x00)
        self.assertEqual(send_image.to_planes(
            self._solid((150, 150, 150)), threshold=100)[0][0], 0xFF)
        # a dimmer red needs a lower --red-threshold
        self.assertEqual(send_image.classify(90, 10, 10), "black")
        self.assertEqual(send_image.classify(90, 10, 10, red_threshold=80), "red")

    def _solid(self, rgb):
        return Image.new("RGBA", (self.W, self.H), rgb + (255,))


class FitAndRotateTests(unittest.TestCase):

    def test_fit_modes_end_at_panel_size(self):
        source = Image.new("RGB", (400, 300), (255, 255, 255))
        for fit in ("contain", "cover", "stretch"):
            prepared = send_image.prepare_image(source, fit=fit, rotate="auto")
            self.assertEqual(prepared.size, (send_image.SK_IMG_W, send_image.SK_IMG_H))

    def test_auto_rotates_landscape_only(self):
        # A landscape 296x152 source. 90 degrees clockwise puts the source's
        # LEFT edge on the TOP row: source (0, 151) -> (0, 0) and
        # source (0, 0) -> (151, 0), exactly as png2epd.py's --rotate 90.
        landscape = Image.new("RGB", (296, 152), (255, 255, 255))
        landscape.putpixel((0, 151), (0, 0, 0))
        landscape.putpixel((0, 0), (0, 0, 0))
        prepared = send_image.prepare_image(landscape, rotate="auto")
        self.assertEqual(prepared.size, (152, 296))
        bw, _red = send_image.to_planes(prepared)
        self.assertEqual(bw[0], 0x7F)        # source bottom-left -> top-left
        self.assertEqual(bw[18], 0xFE)       # source top-left -> top-right
        self.assertEqual(send_image.count_ink(bw), 2)

        # A portrait source is left alone.
        portrait = Image.new("RGB", (152, 296), (255, 255, 255))
        portrait.putpixel((0, 0), (0, 0, 0))
        bw, _red = send_image.to_planes(send_image.prepare_image(portrait, rotate="auto"))
        self.assertEqual(bw[0], 0x7F)

    def test_contain_letterboxes_on_white(self):
        # 608x296 black source: contain scales it to 152x74 and centres it, so
        # 111 white rows sit above and below it.
        source = Image.new("RGB", (608, 296), (0, 0, 0))
        bw, _red = send_image.to_planes(
            send_image.prepare_image(source, fit="contain", rotate=0))
        self.assertEqual(bw[0:19], b"\xFF" * 19)                    # top band
        self.assertEqual(bw[111 * 19:112 * 19], b"\x00" * 19)       # first ink row
        self.assertEqual(bw[184 * 19:185 * 19], b"\x00" * 19)       # last ink row
        self.assertEqual(bw[185 * 19:186 * 19], b"\xFF" * 19)       # bottom band
        self.assertEqual(send_image.count_ink(bw), 152 * 74)

    def test_cover_crops_instead_of_letterboxing(self):
        source = Image.new("RGB", (608, 296), (255, 255, 255))
        prepared = send_image.prepare_image(source, fit="cover", rotate=0)
        self.assertEqual(prepared.size, (152, 296))
        bw, _red = send_image.to_planes(prepared)
        self.assertEqual(bw, b"\xFF" * send_image.SK_IMG_PLANE_BYTES)
        # ... and a black source stays black to every edge.
        black = send_image.to_planes(send_image.prepare_image(
            Image.new("RGB", (608, 296), (0, 0, 0)), fit="cover", rotate=0))[0]
        self.assertEqual(black, b"\x00" * send_image.SK_IMG_PLANE_BYTES)

    def test_stretch_ignores_the_aspect_ratio(self):
        """stretch fills the panel whatever the source shape: a square source
        becomes a 152x296 frame with no white bands."""
        black = send_image.to_planes(send_image.prepare_image(
            Image.new("RGB", (76, 74), (0, 0, 0)), fit="stretch", rotate=0))[0]
        self.assertEqual(black, b"\x00" * send_image.SK_IMG_PLANE_BYTES)
        white = send_image.to_planes(send_image.prepare_image(
            Image.new("RGB", (76, 74), (255, 255, 255)), fit="stretch", rotate=0))[0]
        self.assertEqual(white, b"\xFF" * send_image.SK_IMG_PLANE_BYTES)

    def test_exact_size_source_is_not_resampled(self):
        source = Image.new("RGB", (152, 296), (255, 255, 255))
        source.putpixel((77, 88), (7, 7, 7))
        prepared = send_image.prepare_image(source, fit="contain", rotate="auto")
        self.assertEqual(prepared.size, (152, 296))
        self.assertEqual(prepared.getpixel((77, 88))[:3], (7, 7, 7))


class Png2EpdParityTests(unittest.TestCase):
    """The air path must produce what the boot path (png2epd.py) produces."""

    def setUp(self):
        self.tmp = tempfile.TemporaryDirectory()
        self.addCleanup(self.tmp.cleanup)

    def _write(self, size, name):
        im = Image.new("RGB", size, (255, 255, 255))
        for i in range(0, size[0], 13):
            im.putpixel((i, (i * 3) % size[1]), (0, 0, 0))
        for i in range(0, size[0], 17):
            im.putpixel((i, (i * 5 + 2) % size[1]), (255, 0, 0))
        im.putpixel((0, 0), (0, 0, 0))
        im.putpixel((size[0] - 1, size[1] - 1), (255, 0, 0))
        im.putpixel((3, 3), (128, 128, 128))
        path = os.path.join(self.tmp.name, name)
        im.save(path)
        return path

    def test_landscape_source_rotate_auto_equals_boot_path(self):
        path = self._write((296, 152), "landscape.png")
        # Exactly what png2epd.py --rotate 90 does.
        boot = png2epd.rotate_image(Image.open(path).convert("RGBA"), 90)
        bw_boot, red_boot = png2epd.to_planes(boot, False)
        (bw_air, red_air), _note = send_image.convert_file(
            path, fit="contain", rotate="auto")
        self.assertEqual(bw_air, bytes(bw_boot))
        self.assertEqual(red_air, bytes(red_boot))
        (bw_air90, red_air90), _note = send_image.convert_file(
            path, fit="contain", rotate="90")
        self.assertEqual(bw_air90, bytes(bw_boot))

    def test_portrait_source_rotate_auto_equals_rotate_zero(self):
        path = self._write((152, 296), "portrait.png")
        boot = Image.open(path).convert("RGBA")
        bw_boot, red_boot = png2epd.to_planes(boot, False)
        (bw_air, red_air), _note = send_image.convert_file(
            path, fit="contain", rotate="auto")
        self.assertEqual(bw_air, bytes(bw_boot))
        self.assertEqual(red_air, bytes(red_boot))

    def test_dither_option_matches_boot_path(self):
        path = self._write((296, 152), "dither.png")
        boot = png2epd.rotate_image(Image.open(path).convert("RGBA"), 90)
        bw_boot, red_boot = png2epd.to_planes(boot, True)
        (bw_air, red_air), _note = send_image.convert_file(
            path, fit="contain", rotate="auto", dither=True)
        self.assertEqual(bw_air, bytes(bw_boot))
        self.assertEqual(red_air, bytes(red_boot))

    def test_rotate_image_matches_pils_own_rotation(self):
        """The refactor of png2epd's rotation did not change its output."""
        rng = random.Random(7)
        source = Image.new("RGB", (23, 41))
        source.putdata([(rng.randrange(256), rng.randrange(256), rng.randrange(256))
                        for _ in range(23 * 41)])
        for degrees in (90, 180, 270):
            expected = source.rotate((360 - degrees) % 360, expand=True)
            self.assertEqual(png2epd.rotate_image(source, degrees).tobytes(),
                             expected.tobytes(), f"rotate {degrees}")

    def test_cli_output_equals_air_path(self):
        """End to end: png2epd.py's own CLI, C arrays vs the air planes."""
        path = self._write((296, 152), "cli.png")
        out_dir = os.path.join(self.tmp.name, "gen")
        os.makedirs(out_dir)
        result = subprocess.run(
            [sys.executable, os.path.join(TOOLS_DIR, "png2epd.py"), path,
             "--rotate", "90", "--out-dir", out_dir],
            capture_output=True, text=True)
        self.assertEqual(result.returncode, 0, result.stderr)
        with open(os.path.join(out_dir, "epd_image.c"), encoding="utf-8") as f:
            text = f.read()
        bw_part = text.split("epd_image_bw[EPD_PLANE_BYTES] = {")[1].split("};")[0]
        red_part = text.split("epd_image_red[EPD_PLANE_BYTES] = {")[1].split("};")[0]
        bw_c = bytes(int(v, 16) for v in re.findall(r"0x([0-9A-Fa-f]{2})", bw_part))
        red_c = bytes(int(v, 16) for v in re.findall(r"0x([0-9A-Fa-f]{2})", red_part))
        (bw_air, red_air), _note = send_image.convert_file(
            path, fit="contain", rotate="auto")
        self.assertEqual(len(bw_c), send_image.SK_IMG_PLANE_BYTES)
        self.assertEqual(bw_air, bw_c)
        self.assertEqual(red_air, red_c)


class TransferTests(unittest.TestCase):

    def test_full_image_blocks_reconstruct_it(self):
        image = test_image()
        ap = FakeAP()
        stats = run_transfer(ap, image)
        self.assertEqual(bytes(ap.image), image)
        self.assertEqual(stats["bytes"], send_image.SK_IMG_TOTAL_BYTES)
        self.assertEqual(stats["blocks"], 118)
        self.assertEqual(stats["retries"], 0)
        self.assertEqual(stats["crc"], send_image.crc16_ccitt_false(image))
        # Offsets run 0, 96, 192 ... and all blocks but the last are full.
        self.assertEqual(ap.offsets, list(range(0, send_image.SK_IMG_TOTAL_BYTES,
                                                send_image.SK_IMG_DATA_MAX)))
        self.assertEqual(ap.types_seen[0], send_image.SK_U_IMG_BEGIN)
        self.assertEqual(ap.types_seen[-1], send_image.SK_U_IMG_END)
        self.assertEqual(ap.end_seen, 1)

    def test_begin_payload_carries_serial_total_and_crc(self):
        image = test_image()
        ap = FakeAP()
        run_transfer(ap, image)
        payload = ap.begin
        slen = payload[0]
        self.assertEqual(payload[1:1 + slen], b"1408F525")
        self.assertEqual((payload[1 + slen] << 8) | payload[2 + slen],
                         send_image.SK_IMG_TOTAL_BYTES)
        self.assertEqual((payload[3 + slen] << 8) | payload[4 + slen],
                         send_image.crc16_ccitt_false(image))

    def test_serial_is_upper_cased(self):
        ap = FakeAP(serial=b"1408F525")
        send_image.transfer(ap, "1408f525", test_image(), timeout=0.2,
                            end_timeout=1.0, progress=False)
        self.assertEqual(bytes(ap.image), test_image())

    def test_retry_when_the_tag_does_not_move(self):
        ap = FakeAP(drop_first={192})
        stats = run_transfer(ap)
        self.assertEqual(bytes(ap.image), test_image())
        self.assertEqual(stats["retries"], 1)
        self.assertEqual(ap.offsets.count(192), 2)

    def test_retry_after_a_timeout(self):
        ap = FakeAP(no_ack_once={96, 4800})
        stats = run_transfer(ap, retries=2)
        self.assertEqual(bytes(ap.image), test_image())
        self.assertEqual(stats["retries"], 2)

    def test_partial_ack_resumes_at_the_reported_offset(self):
        ap = FakeAP(partial=(192, 50))
        run_transfer(ap)
        self.assertEqual(bytes(ap.image), test_image())
        self.assertIn(242, ap.offsets)
        self.assertNotIn(288, ap.offsets)       # the tail was not skipped

    def test_out_of_order_status_aborts(self):
        ap = FakeAP(data_status=(96, send_image.SK_ST_OFFSET))
        with self.assertRaises(send_image.TransferError) as ctx:
            run_transfer(ap)
        self.assertIn("out of order", str(ctx.exception))

    def test_status_frame_aborts_with_the_status_name(self):
        ap = FakeAP(begin_status=send_image.SK_ST_BUSY)
        with self.assertRaises(send_image.TransferError) as ctx:
            run_transfer(ap)
        self.assertIn("already in a transfer", str(ctx.exception))

    def test_timeout_aborts_after_the_retries(self):
        ap = FakeAP(no_ack={0})
        with self.assertRaises(send_image.TransferError) as ctx:
            run_transfer(ap, retries=2)
        self.assertIn("3 attempt", str(ctx.exception))

    def test_end_crc_verdict_aborts(self):
        ap = FakeAP(end_status=send_image.SK_ST_CRC)
        with self.assertRaises(send_image.TransferError) as ctx:
            run_transfer(ap)
        self.assertIn("CRC", str(ctx.exception))

    def test_end_corruption_is_caught_by_the_fake_tag(self):
        # The fake tag verifies the image itself: flip one byte in transit.
        ap = FakeAP()
        original = ap.handle

        def corrupt(ptype, payload):
            if ptype == send_image.SK_U_IMG_DATA and (payload[0] << 8 | payload[1]) == 96:
                payload = bytearray(payload)
                payload[5] ^= 0xFF
                payload = bytes(payload)
            original(ptype, payload)

        ap.handle = corrupt
        with self.assertRaises(send_image.TransferError) as ctx:
            run_transfer(ap)
        self.assertIn("CRC", str(ctx.exception))

    def test_end_ack_after_the_panel_refresh_is_not_a_failure(self):
        """IMG_END is answered only after ~20 s of panel refresh: the long
        --end-timeout must cover it, and the data must not be resent."""
        ap = FakeAP(end_delay=0.25)
        stats = run_transfer(ap, timeout=0.05, end_timeout=1.5)
        self.assertEqual(bytes(ap.image), test_image())
        self.assertEqual(ap.end_seen, 1)
        self.assertEqual(stats["blocks"], 118)

    def test_end_timeout_too_short_retries_only_the_end(self):
        """If the final ack misses even the long timeout, only IMG_END is sent
        again - the 11248 data bytes are not re-transmitted."""
        ap = FakeAP(end_delay=0.3)
        with contextlib.redirect_stderr(io.StringIO()):
            with self.assertRaises(send_image.TransferError):
                run_transfer(ap, timeout=0.05, end_timeout=0.05, retries=1)
        self.assertEqual(len(ap.offsets), 118)      # no data block was resent
        self.assertGreaterEqual(ap.end_seen, 2)

    def test_wrong_image_size_is_refused(self):
        with self.assertRaises(send_image.TransferError):
            run_transfer(FakeAP(), b"\x00" * 100)

    def test_verbose_transfer_shows_the_frames(self):
        ap = FakeAP(drop_first={96})
        out = io.StringIO()
        with contextlib.redirect_stdout(out), contextlib.redirect_stderr(out):
            stats = run_transfer(ap, verbose=True)
        self.assertEqual(bytes(ap.image), test_image())
        self.assertEqual(stats["retries"], 1)
        text = out.getvalue()
        self.assertIn("IMG_DATA @96", text)
        self.assertIn("IMG_BEGIN", text)


class CliTests(unittest.TestCase):

    def setUp(self):
        self.tmp = tempfile.TemporaryDirectory()
        self.addCleanup(self.tmp.cleanup)
        self.dir = self.tmp.name
        self.path = os.path.join(self.dir, "1408f525.PNG")
        im = Image.new("RGB", (296, 152), (255, 255, 255))
        im.putpixel((0, 0), (0, 0, 0))
        im.putpixel((295, 0), (255, 0, 0))
        im.save(self.path)

    def test_dry_run_converts_without_a_port(self):
        out = io.StringIO()
        with contextlib.redirect_stdout(out):
            rc = send_image.main(["--dry-run", "-d", self.dir])
        self.assertEqual(rc, 0)
        text = out.getvalue()
        self.assertIn("1408F525", text)
        self.assertIn("dry run - the serial port was not opened", text)

        bw_path = os.path.join(self.dir, "1408f525.bw.bin")
        red_path = os.path.join(self.dir, "1408f525.red.bin")
        with open(bw_path, "rb") as f:
            bw = f.read()
        with open(red_path, "rb") as f:
            red = f.read()
        self.assertEqual(len(bw), send_image.SK_IMG_PLANE_BYTES)
        self.assertEqual(len(red), send_image.SK_IMG_PLANE_BYTES)
        (expected_bw, expected_red), _note = send_image.convert_file(self.path)
        self.assertEqual(bw, expected_bw)
        self.assertEqual(red, expected_red)

    def test_no_port_is_an_error_without_dry_run(self):
        with self.assertRaises(SystemExit):
            with contextlib.redirect_stderr(io.StringIO()):
                send_image.main(["-d", self.dir])

    def test_missing_directory_is_created(self):
        target = os.path.join(self.dir, "new")
        with contextlib.redirect_stdout(io.StringIO()):
            rc = send_image.main(["--dry-run", "-d", target])
        self.assertTrue(os.path.isdir(target))
        self.assertEqual(rc, 1)             # created, but there is nothing in it

    def test_selftest_passes(self):
        out = io.StringIO()
        with contextlib.redirect_stdout(out):
            rc = send_image.main(["--selftest"])
        text = out.getvalue()
        self.assertNotIn("FAIL", text, text)
        self.assertIn("checks passed", text)
        self.assertEqual(rc, 0)

    def test_list_does_not_need_a_port(self):
        out = io.StringIO()
        with contextlib.redirect_stdout(out):
            rc = send_image.main(["--list"])
        self.assertEqual(rc, 0)

    def test_dry_run_serial_filter(self):
        out = io.StringIO()
        with contextlib.redirect_stdout(out):
            rc = send_image.main(["--dry-run", "-d", self.dir, "-s", "1408f525",
                                  "--verbose"])
        self.assertEqual(rc, 0)
        self.assertIn("1408F525", out.getvalue())
        self.assertIn("first frame", out.getvalue())

    def test_dry_run_serial_filter_with_no_match(self):
        out = io.StringIO()
        with contextlib.redirect_stdout(out):
            rc = send_image.main(["--dry-run", "-d", self.dir, "-s", "DEADBEEF"])
        self.assertEqual(rc, 1)
        self.assertIn("no image for tag DEADBEEF", out.getvalue())


class DiscoveryTests(unittest.TestCase):

    def setUp(self):
        self.tmp = tempfile.TemporaryDirectory()
        self.addCleanup(self.tmp.cleanup)
        self.dir = self.tmp.name
        for name in ("notes.txt", "not a serial.png",
                     "toolongserialsixteen1.png", "noextension"):
            open(os.path.join(self.dir, name), "wb").close()
        # The two serial-named files are real images, so a dry run converts them.
        for name in ("1408F525.png", "1408F525.bmp", "abcd1234.JPG"):
            im = Image.new("RGB", (296, 152), (255, 255, 255))
            im.putpixel((0, 0), (0, 0, 0))
            im.save(os.path.join(self.dir, name))

    def test_only_serial_named_images(self):
        found = send_image.find_images(self.dir)
        self.assertEqual(found, [("1408F525", os.path.join(self.dir, "1408F525.bmp")),
                                 ("1408F525", os.path.join(self.dir, "1408F525.png")),
                                 ("ABCD1234", os.path.join(self.dir, "abcd1234.JPG"))])

    def test_serial_filter_is_case_insensitive(self):
        found = send_image.find_images(self.dir, only="1408f525")
        self.assertEqual([os.path.basename(p) for _s, p in found],
                         ["1408F525.bmp", "1408F525.png"])

    def test_missing_directory_is_empty(self):
        self.assertEqual(send_image.find_images(os.path.join(self.dir, "nope")), [])

    def test_process_pending_skips_unchanged_files(self):
        args = send_image.build_parser().parse_args(["--dry-run", "-d", self.dir])
        state = {}
        with contextlib.redirect_stdout(io.StringIO()):
            done, failed, seen = send_image.process_pending(args, None, state)
        self.assertEqual((done, failed, seen), (3, 0, 3))
        with contextlib.redirect_stdout(io.StringIO()):
            done, failed, seen = send_image.process_pending(args, None, state)
        self.assertEqual((done, failed, seen), (0, 0, 3))    # nothing changed


class BootImageParityTests(unittest.TestCase):
    """The real end-to-end check: the boot image that is compiled into the
    firmware, against the planes the air path derives from the same source."""

    PNG = os.path.join(REPO_DIR, "firmware", "shelfkit-vusion", "polyform-eink.png")
    C_FILE = os.path.join(REPO_DIR, "firmware", "shelfkit-vusion", "src", "epd_image.c")

    def _array(self, text, plane):
        part = text.split(f"epd_image_{plane}[EPD_PLANE_BYTES] = {{")[1].split("};")[0]
        return bytes(int(v, 16) for v in re.findall(r"0x([0-9A-Fa-f]{2})", part))

    def test_committed_boot_image_matches_the_air_path(self):
        if not (os.path.exists(self.PNG) and os.path.exists(self.C_FILE)):
            self.skipTest("the boot image and its source are not in this checkout")
        with open(self.C_FILE, encoding="utf-8", errors="replace") as f:
            text = f.read()
        header = text.splitlines()[0]
        if "rotate=90" not in header or "dither=off" not in header:
            self.skipTest(f"the committed boot image was generated differently: {header}")
        bw_c = self._array(text, "bw")
        red_c = self._array(text, "red")
        self.assertEqual(len(bw_c), send_image.SK_IMG_PLANE_BYTES)
        (bw_air, red_air), _note = send_image.convert_file(
            self.PNG, fit="contain", rotate="auto")
        self.assertEqual(bw_air, bw_c)
        self.assertEqual(red_air, red_c)


class HeaderInterfaceTests(unittest.TestCase):
    """The numbers the tool hard-codes are the ones in the frozen headers."""

    def _defines(self, path):
        with open(path, encoding="utf-8", errors="replace") as f:
            text = f.read()
        return {m.group(1): m.group(2)
                for m in re.finditer(r"^#define\s+(\w+)\s+([^\s/]+)", text,
                                     re.MULTILINE)}

    def test_proto_header_constants(self):
        defines = self._defines(PROTO_H_PATH)
        self.assertEqual(int(defines["SK_IMG_DATA_MAX"], 0), send_image.SK_IMG_DATA_MAX)
        self.assertEqual(int(defines["SK_IMG_PLANE_BYTES"], 0),
                         send_image.SK_IMG_PLANE_BYTES)
        self.assertEqual(int(defines["SK_IMG_PLANES"], 0), 2)
        self.assertEqual(int(defines["SK_IMG_W"], 0), send_image.SK_IMG_W)
        self.assertEqual(int(defines["SK_IMG_H"], 0), send_image.SK_IMG_H)
        self.assertEqual(int(defines["SK_SERIAL_MAX"], 0), send_image.SK_SERIAL_MAX)
        self.assertEqual(int(defines["SK_UART_SYNC0"], 0), send_image.SK_UART_SYNC0)
        self.assertEqual(int(defines["SK_UART_SYNC1"], 0), send_image.SK_UART_SYNC1)
        self.assertEqual(int(defines["SK_U_IMG_BEGIN"], 0), send_image.SK_U_IMG_BEGIN)
        self.assertEqual(int(defines["SK_U_IMG_DATA"], 0), send_image.SK_U_IMG_DATA)
        self.assertEqual(int(defines["SK_U_IMG_END"], 0), send_image.SK_U_IMG_END)
        self.assertEqual(int(defines["SK_U_ACK"], 0), send_image.SK_U_ACK)
        self.assertEqual(int(defines["SK_U_STATUS"], 0), send_image.SK_U_STATUS)
        self.assertEqual(int(defines["SK_ST_OK"], 0), send_image.SK_ST_OK)
        self.assertEqual(int(defines["SK_ST_BAD_SERIAL"], 0), send_image.SK_ST_BAD_SERIAL)
        self.assertEqual(int(defines["SK_ST_FLASH"], 0), send_image.SK_ST_FLASH)
        self.assertEqual(int(defines["SK_ST_CRC"], 0), send_image.SK_ST_CRC)
        self.assertEqual(int(defines["SK_ST_OFFSET"], 0), send_image.SK_ST_OFFSET)
        self.assertEqual(int(defines["SK_ST_BUSY"], 0), send_image.SK_ST_BUSY)
        self.assertEqual(int(defines["SK_ST_UNSUPPORTED"], 0),
                         send_image.SK_ST_UNSUPPORTED)
        self.assertEqual(send_image.SK_IMG_PLANE_BYTES * 2,
                         send_image.SK_IMG_TOTAL_BYTES)

    def test_epd_header_geometry(self):
        defines = self._defines(EPD_H_PATH)
        self.assertEqual(int(defines["EPD_W"], 0), send_image.SK_IMG_W)
        self.assertEqual(int(defines["EPD_H"], 0), send_image.SK_IMG_H)
        self.assertEqual((send_image.SK_IMG_W * send_image.SK_IMG_H + 7) // 8,
                         send_image.SK_IMG_PLANE_BYTES)


if __name__ == "__main__":
    unittest.main(verbosity=2)
