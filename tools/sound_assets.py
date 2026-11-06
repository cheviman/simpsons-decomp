"""
Name:        sound_assets.py
Description: The Simpsons' K053260 samples as WAV files, by the Z80 driver's sample table, and back byte for byte
Version:     0.1.0
Created:     06-11-2026
Modified:    06-11-2026
Author:      Sebastian Toyos

A sample is a record of the driver's table (sound_symbols.txt's samples: 8 bytes, the K053260 channel's registers 0-6
and a byte whose bit 0 is ADPCM, 0D3B-0D56): its pitch (registers 0-1, 12 bits), its length (2-3) and its start
(4-6, 21 bits). The chip plays the bytes after the start, the length of them (MAME's k053260.cpp: the position is
incremented before it is read), each one as a signed 8-bit level (PCM) or as two 4-bit steps (KADPCM: the low nibble
first, each adding kadpcm_table's step to the level, from 0). Its rate is the chip's clock (3.579545 MHz) over 1000
less the pitch, hex.
The WAVs are 8-bit: a PCM sample's bytes with their sign bit flipped; a KADPCM sample's levels, which give its steps
back (the 16 steps are all different, mod 256). The region's bytes no sample plays (the start's own byte, the table
at the region's start, what nothing uses) are WAVs of their bytes as they are (unused_XXXXX.wav), or, a few bytes,
samples.txt's own lines (bytes PLACE HEX). samples.txt lists each file with where it goes.
"""
from pathlib import Path

import asset_formats  # noqa: E402  (the core's WAV reader and writer)

CLOCK = 3579545
RECORD = 8
TABLE = 0x28E9                  # the driver's sample table (sound_symbols.txt: samples)
COUNT = 163
KADPCM_STEPS = (0, 1, 2, 4, 8, 16, 32, 64, -128, -64, -32, -16, -8, -4, -2, -1)
STEP_OF = {step & 0xFF: nibble for nibble, step in enumerate(KADPCM_STEPS)}
RAW_RATE = 8000
INLINE = 16                     # the bytes no sample plays that samples.txt holds itself, up to this many


def table(sound):
    """[(start, length, pitch, kadpcm)] of the driver's sample records"""
    found = []
    for index in range(COUNT):
        record = sound[TABLE + RECORD * index:TABLE + RECORD * (index + 1)]
        found.append((record[4] | record[5] << 8 | (record[6] & 0x1F) << 16, record[2] | record[3] << 8,
                      record[0] | (record[1] & 0x0F) << 8, bool(record[7] & 1)))
    return found


def decode_kadpcm(data):
    level, levels = 0, bytearray()
    for byte in data:
        for nibble in (byte & 0x0F, byte >> 4):
            level = (level + KADPCM_STEPS[nibble]) & 0xFF
            levels.append(level ^ 0x80)
    return bytes(levels)


def encode_kadpcm(levels):
    previous, nibbles = 0, []
    for value in levels:
        level = value ^ 0x80
        nibbles.append(STEP_OF[(level - previous) & 0xFF])
        previous = level
    return bytes(nibbles[index] | nibbles[index + 1] << 4 for index in range(0, len(nibbles) - 1, 2))


def write(sound, region, folder):
    """The samples and the bytes no sample plays, as WAVs in 'folder', and samples.txt"""
    folder.mkdir(parents=True, exist_ok=True)
    lines = []
    played = bytearray(len(region))
    seen = set()
    for number, (start, length, pitch, kadpcm) in enumerate(table(sound)):
        first = start + 1
        if (first, length, kadpcm) in seen or first + length > len(region):
            continue
        seen.add((first, length, kadpcm))
        data = region[first:first + length]
        name = f"sample_{number:03d}"
        samples = decode_kadpcm(data) if kadpcm else bytes(byte ^ 0x80 for byte in data)
        asset_formats.write_wav(folder / f"{name}.wav", samples, CLOCK // max(1, 0x1000 - pitch), bits=8)
        lines.append(f"{name} {first:06X} {length} {'kadpcm' if kadpcm else 'pcm'}")
        played[first:first + length] = b"\x01" * length
    at = 0
    while at < len(region):
        if played[at]:
            at += 1
            continue
        stop = at
        while stop < len(region) and not played[stop]:
            stop += 1
        if stop - at <= INLINE:
            # (the byte before a sample, which the chip skips: in the list itself)
            lines.append(f"bytes {at:06X} {region[at:stop].hex()}")
        else:
            name = f"unused_{at:06X}"
            asset_formats.write_wav(folder / f"{name}.wav", region[at:stop], RAW_RATE, bits=8)
            lines.append(f"{name} {at:06X} {stop - at} raw")
        at = stop
    (folder / "samples.txt").write_text("\n".join(lines) + "\n", encoding="ascii")
    return len(seen), len(lines) - len(seen)


def read(folder, size):
    """The region the WAVs in 'folder' and samples.txt give back"""
    region = bytearray(size)
    for line in (folder / "samples.txt").read_text(encoding="ascii").splitlines():
        if line.startswith("bytes "):
            _, first, data = line.split()
            region[int(first, 16):int(first, 16) + len(data) // 2] = bytes.fromhex(data)
            continue
        name, first, length, kind = line.split()
        first, length = int(first, 16), int(length)
        samples, _ = asset_formats.read_wav_unsigned(folder / f"{name}.wav")
        if kind == "kadpcm":
            data = encode_kadpcm(samples)
        elif kind == "pcm":
            data = bytes(sample ^ 0x80 for sample in samples)
        else:
            data = samples
        if len(data) != length:
            raise SystemExit(f"{name}.wav: {len(data)} bytes, samples.txt says {length}")
        region[first:first + length] = data
    return bytes(region)
