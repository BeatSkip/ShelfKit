#!/usr/bin/env python3
"""memdump.py - reset the imagotag, capture every memory, split the capture.

Runs the firmware built from `firmware/dumptool`, which prints, back to back:

    --- NFC (FM11NT081DS) ---   serial number, capability container, 924-byte EEPROM
    --- SPI flash ---           JEDEC ID + 128 KiB contents
    --- MCU flash ---           the AX8052's own 64 KiB code space (only if
                                DUMP_MCU_FLASH is set to 1 in its main.c)

and finishes with "*** end of dump ***".

This script drives the same serial hookup as axsem-flasher.py (DTR = boot pin,
RTS = reset), captures the stream and writes one binary per section next to
the raw capture:

    memdump_<ts>.txt            raw capture, exactly what came over the wire
    memdump_<ts>.nfc.bin        924-byte NFC EEPROM
    memdump_<ts>.spiflash.bin   128 KiB SPI flash
    memdump_<ts>.mcu.bin        64 KiB MCU flash (when that section is present)

Usage:
    python tools/memdump.py COM8
    python tools/memdump.py COM8 -o tag7.txt
    python tools/memdump.py COM8 --timeout 400        # with DUMP_MCU_FLASH enabled
    python tools/memdump.py COM8 --reset none         # you reset the board yourself
    python tools/memdump.py --list
"""

import argparse
import datetime
import os
import re
import sys

# Same-directory import: tools/flashdump.py owns the serial hookup and the
# capture loop, this script only adds the parsing half.
from flashdump import DEFAULT_BAUD, Tag, capture

# name -> (start marker, end marker, output suffix, exact size or None)
SECTIONS = {
    "nfc":      ("--- NFC (FM11NT081DS) ---", "--- end of NFC ---",
                 "_nfc.bin", 924),
    "spiflash": ("--- SPI flash ---", "--- end of SPI flash ---",
                 "_spiflash.bin", None),
    "mcu":      ("--- MCU flash", "--- end of MCU flash ---",
                 "_mcu.bin", None),
}

# "000000: 04 5A 3C EA ...  |.Z<.|"  ->  address + the hex bytes
LINE_RE = re.compile(r"^([0-9A-Fa-f]{4,8}):\s+((?:[0-9A-Fa-f]{2}\s+)*)")
SERIAL_RE = re.compile(r"^NFC serial:\s+((?:[0-9A-Fa-f]{2}\s+)*)\s*\[(.*?)\]")
CC_RE = re.compile(r"^NFC CC:\s+(.+?)\s*$")
JEDEC_RE = re.compile(r"^JEDEC ID:\s+(.+?)\s*$")


def parse_sections(text):
    """Split the capture into {section: {address: byte}} plus the metadata."""
    found = {}
    meta = {"serial": None, "serial_ok": None, "cc": None, "jedec": None}
    current = None

    for raw in text.splitlines():
        line = raw.rstrip("\r")

        m = SERIAL_RE.match(line)
        if m:
            meta["serial"] = m.group(1).split()
            meta["serial_ok"] = m.group(2)
        m = CC_RE.match(line)
        if m:
            meta["cc"] = m.group(1)
        m = JEDEC_RE.match(line)
        if m:
            meta["jedec"] = m.group(1)

        if current is None:
            for name, (start, _end, _suffix, _size) in SECTIONS.items():
                if line.startswith(start):
                    current = name
                    found.setdefault(name, {})
                    break
            continue

        if line.startswith(SECTIONS[current][1]):
            current = None
            continue

        m = LINE_RE.match(line)
        if m:
            addr = int(m.group(1), 16)
            for i, byte in enumerate(m.group(2).split()):
                found[current][addr + i] = int(byte, 16)

    return found, meta


def to_image(entries, size=None):
    """Materialise {address: byte} into a bytes object (0x00 for gaps)."""
    if not entries:
        return b""
    span = max(entries) + 1
    if size is not None:
        span = max(span, size)
    image = bytearray(span)
    for addr, byte in entries.items():
        image[addr] = byte
    return bytes(image)


def main():
    ap = argparse.ArgumentParser(
        description=__doc__,
        formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("port", nargs="?", help="serial port (e.g. COM8 or /dev/ttyUSB0)")
    ap.add_argument("-b", "--baud", type=int, default=DEFAULT_BAUD,
                    help=f"baud rate (default: {DEFAULT_BAUD})")
    ap.add_argument("-o", "--output", default=None,
                    help="raw capture file (default: memdump_<timestamp>.txt)")
    ap.add_argument("--timeout", type=float, default=300.0,
                    help="seconds to wait for the dump (default: 300; the "
                         "128 KiB SPI flash alone needs ~100 s at 38400)")
    ap.add_argument("--reset", choices=["auto", "none"], default="auto",
                    help="'none' skips the reset pulse (reset the board by hand)")
    ap.add_argument("--list", action="store_true", help="list serial ports and exit")
    args = ap.parse_args()

    if args.list:
        from serial.tools import list_ports
        ports = list_ports.comports()
        if not ports:
            print("no serial ports found")
        for p in ports:
            print(f"{p.device:12s}  {p.description}")
        return 0

    if not args.port:
        ap.error("a serial port is required (use --list to see what's available)")

    raw_path = args.output or (
        "memdump_" + datetime.datetime.now().strftime("%Y%m%d_%H%M%S") + ".txt")

    tag = Tag(args.port, args.baud)
    tag.serial.reset_input_buffer()

    if args.reset == "auto":
        tag.reset_into(bootloader=False)
    else:
        print("Reset the board now (power cycle, or reset it by hand)...")

    nbytes, elapsed = capture(tag.serial, raw_path, args.timeout)
    tag.close()

    with open(raw_path, encoding="latin-1") as f:
        text = f.read()

    found, meta = parse_sections(text)
    base, _ext = os.path.splitext(raw_path)

    print(f"\nmemdump summary  ({nbytes} bytes in {elapsed:.1f}s -> {raw_path})")

    if meta["serial"]:
        print(f"  NFC serial      {' '.join(meta['serial'])}  [{meta['serial_ok']}]")
    else:
        print("  NFC serial      - (no NFC section in the capture)")

    if meta["cc"]:
        print(f"  NFC CC          {meta['cc']}")
    if meta["jedec"]:
        print(f"  SPI flash ID    {meta['jedec']}")

    exit_code = 0
    for name, (_start, _end, suffix, size) in SECTIONS.items():
        entries = found.get(name)
        if not entries:
            print(f"  {name:15s} - (section not in the capture)")
            continue
        image = to_image(entries, size)
        out_path = base + suffix
        with open(out_path, "wb") as f:
            f.write(image)
        gaps = len(image) - len(entries)
        note = "" if not gaps else f"  !! {gaps} bytes missing"
        print(f"  {name:15s} {out_path}  {len(image)} bytes{note}")
        if gaps:
            exit_code = 1

    if "*** end of dump ***" not in text:
        print("  !! the end marker never arrived - the capture is incomplete")
        exit_code = 1

    return exit_code


if __name__ == "__main__":
    sys.exit(main())
