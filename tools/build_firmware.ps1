# Build one ShelfKit firmware, or all of them.
#
#   powershell -ExecutionPolicy Bypass -File tools/build_firmware.ps1
#   powershell -ExecutionPolicy Bypass -File tools/build_firmware.ps1 -Firmware shelfkit-vusion
#   powershell -ExecutionPolicy Bypass -File tools/build_firmware.ps1 -Define SK_TAG_ROUTER=1
#
# -Firmware selects which projects to build (default: all three).
# -Define passes -D flags straight to SDCC, which is how a tag is built as a
# mains-powered router rather than a battery leaf: -Define SK_TAG_ROUTER=1 (see
# the note at the top of firmware/shelfkit-vusion/src/main.c). Note that this
# overwrites build/firmware.hex, so rebuild without it before flashing a tag
# that should be a leaf again.
#
# This is the build the firmware-readme.md documents by hand: every source in
# <firmware>/src compiled to its own .rel with the project's flags, the rels
# linked against the four prebuilt Axsem archives, and build/firmware.hex
# rewritten from build/firmware.ihx with packihx (plain ASCII - the bootloader
# chokes on a UTF-16 BOM, which is what PowerShell's '>' would write).
#
# After the link it prints the three numbers the project tracks: ROM, XRAM and
# the free stack, out of build/firmware.mem.
#
# The bootloader firmware is deliberately not built here: it is a separate
# target with its own memory layout and nothing in the link work touches it.

param(
    [string[]]$Firmware = @('shelfkit-vusion', 'access-point', 'dumptool'),
    [string[]]$Define = @()
)

# `-File script.ps1 -Firmware a,b` arrives as one string, so split on commas
# rather than relying on the caller's shell to build the array.
$Firmware = @($Firmware | ForEach-Object { $_ -split ',' } | Where-Object { $_ })
$Define = @($Define | ForEach-Object { $_ -split ',' } | Where-Object { $_ })

# 'Continue' rather than 'Stop': under 'Stop', PowerShell 5.1 turns a native
# command's stderr into a terminating error *before* the redirection below can
# catch it, so SDCC's two harmless warnings would fail the build. Every step
# is checked by $LASTEXITCODE instead.
$ErrorActionPreference = 'Continue'
$root = Split-Path -Parent $PSScriptRoot
Set-Location $root

$sdcc    = 'C:\Program Files\SDCC\bin\sdcc.exe'
$packihx = 'C:\Program Files\SDCC\bin\packihx.exe'
$flags   = @('-mmcs51', '--model-small', '--iram-size', '256',
             '--xram-size', '8192', '--code-size', '59389')
foreach ($d in $Define) { $flags += "-D$d" }

$names = $Firmware

foreach ($name in $names) {
    $dir = Join-Path $root "firmware/$name"
    if (-not (Test-Path $dir)) { throw "no such firmware: $name" }

    Set-Location $dir
    $inc  = @('-I../shared/include',
              '-I../shared/libraries/libmf/include',
              '-I../shared/libraries/libaxdvk2/include')

    # The source list is sdcc-project.json's: every src/*.c except the ones its
    # exclude rule names. The access point and the dumptool both exclude
    # epd.c/epd_image.c - they drive no panel, and epd_image.c alone is a 20 KB
    # boot image that would double their ROM. Reading it from the project file
    # rather than repeating it keeps this build and VS Code's in step.
    $proj = Get-Content 'sdcc-project.json' -Raw | ConvertFrom-Json
    $excl = @()
    foreach ($s in $proj.sources) {
        if ($s -is [string]) { continue }
        foreach ($e in $s.exclude) { $excl += (Split-Path $e -Leaf) }
    }
    $srcs = Get-ChildItem src -Filter *.c |
            Sort-Object Name |
            Where-Object { $excl -notcontains $_.Name } |
            ForEach-Object { $_.BaseName }
    $obj  = 'build/obj/src'
    New-Item -ItemType Directory -Force -Path $obj | Out-Null

    Write-Host "== $name ==" -ForegroundColor Cyan
    # SDCC's warnings go to stderr, and a tool that pipes stderr through
    # PowerShell must not turn a warning into a failed build (the warnings here
    # are the same two or three SDCC has always emitted). Everything is
    # captured and only printed when a step actually fails.
    $log = 'build/build-stderr.txt'
    foreach ($s in $srcs) {
        & $sdcc -c @flags @inc "src/$s.c" -o "$obj/$s.rel" 2> $log
        if ($LASTEXITCODE -ne 0) {
            Get-Content $log | Write-Host
            throw "${name}: compiling $s.c failed"
        }
    }

    $rels = $srcs | ForEach-Object { "$obj/$_.rel" }
    & $sdcc @flags @inc @rels `
        '../shared/lib/libaxdsp.lib' '../shared/lib/libaxdvk2.lib' `
        '../shared/lib/libmf.lib'    '../shared/lib/libmfcrypto.lib' `
        -o 'build/firmware.ihx' 2> $log
    if ($LASTEXITCODE -ne 0) {
        Get-Content $log | Write-Host
        throw "${name}: link failed"
    }
    Get-Content $log | Write-Host

    & $packihx 'build/firmware.ihx' 2> $log | Set-Content -Encoding ascii 'build/firmware.hex'
    if ($LASTEXITCODE -ne 0) {
        Get-Content $log | Write-Host
        throw "${name}: packihx failed"
    }

    foreach ($line in Get-Content 'build/firmware.mem') {
        if ($line -match 'Stack starts at:\s*0x([0-9a-f]+).*with (\d+) bytes') {
            Write-Host ("   free stack {0} bytes" -f $matches[2])
        }
        if ($line -match 'EXTERNAL RAM\s+0x[0-9a-f]+\s+0x[0-9a-f]+\s+(\d+)\s+(\d+)') {
            Write-Host ("   XRAM {0} / {1}" -f $matches[1], $matches[2])
        }
        if ($line -match 'ROM/EPROM/FLASH\s+0x[0-9a-f]+\s+0x[0-9a-f]+\s+(\d+)\s+(\d+)') {
            Write-Host ("   ROM  {0} / {1}" -f $matches[1], $matches[2])
        }
    }
    Set-Location $root
}
