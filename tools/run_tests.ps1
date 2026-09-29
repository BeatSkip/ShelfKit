# Run every ShelfKit host test.
#
#   powershell -ExecutionPolicy Bypass -File tools/run_tests.ps1
#
# (or `pwsh -File tools/run_tests.ps1` where PowerShell 7 is installed) from
# the repository root. Exits non-zero if anything fails, and prints
# "all suites passed" when everything is green.
#
# Three suites:
#   * the Python tools (the host-side image transfer and its serial protocol),
#     tools/tests/test_ap_server.py;
#   * sk_link_test.c, the link layer itself (frame layout, CRC, addressing,
#     managed flooding, the record route), which compiles the real sk_link.c
#     against a virtual radio and drives it from both sides;
#   * serial_frame_test.c, the access point's serial bridge, which compiles the
#     real firmware/access-point/src/main.c - link layer included - against
#     stubs. The scripted tag answers with real link frames, so what this
#     covers is the bridge, its retry/timeout budgets and the frames the
#     access point puts on the air.
#
# sk_link.c is compiled once into an object here and linked into both C tests;
# the two firmwares' copies are byte-identical, and sk_link_test.c asserts
# that, so either copy would do.
#
# The scratch directory for the Python suite is pinned inside the repository:
# tempfile's default is a directory created with mode 0700, which on Windows is
# an owner-only ACL that some sandboxes refuse to write into. The tests work
# around that themselves (tools/tests/test_ap_server.py, TempDir), and this
# only makes the choice explicit.

$ErrorActionPreference = 'Continue'
$root = Split-Path -Parent $PSScriptRoot
Set-Location $root

$env:SHELFKIT_TEST_TMP = Join-Path $root '.tmp-test'
$gcc  = 'C:\Strawberry\c\bin\gcc.exe'
$cflags = @('-Wall', '-Wextra', '-Wno-unused-function', '-Wno-unused-parameter',
            '-I', 'tools/tests/ap_stubs', '-I', 'firmware/shared/include')
$link_obj = 'tools/tests/sk_link_host.o'

$failed = 0

Write-Host '== python tools =='
& python -m unittest discover -s tools/tests
if ($LASTEXITCODE -ne 0) { $failed = 1 }

Write-Host ''
Write-Host '== the link layer (compiling the real sk_link.c) =='
& $gcc @cflags -c -o $link_obj firmware/shelfkit-vusion/src/sk_link.c
if ($LASTEXITCODE -ne 0) { $failed = 1 }

Write-Host ''
Write-Host '== sk_link_test (framing, CRC, flooding, record route) =='
& $gcc @cflags -o tools/tests/sk_link_test.exe tools/tests/sk_link_test.c $link_obj
if ($LASTEXITCODE -ne 0) { $failed = 1 } else {
    & ./tools/tests/sk_link_test.exe
    if ($LASTEXITCODE -ne 0) { $failed = 1 }
}

Write-Host ''
Write-Host '== serial_frame_test (access point serial bridge) =='
& $gcc @cflags -o tools/tests/serial_frame_test.exe tools/tests/serial_frame_test.c $link_obj
if ($LASTEXITCODE -ne 0) { $failed = 1 } else {
    & ./tools/tests/serial_frame_test.exe
    if ($LASTEXITCODE -ne 0) { $failed = 1 }
}

Write-Host ''
if ($failed) { Write-Host 'SOME SUITES FAILED'; exit 1 }
Write-Host 'all suites passed'
exit 0
