# The Simpsons — decompilation

A reconstruction of Konami's 1991 arcade game *The Simpsons* (a Konami 053248 main CPU, a 6809 with Konami's
own opcodes, with a Z80 sound board) into platform-agnostic C, not an emulator, following the method of
[segasonic-decomp](https://github.com/cheviman/segasonic-decomp),
[outrunners-decomp](https://github.com/cheviman/outrunners-decomp) and
[tmntarcade-decomp](https://github.com/cheviman/tmntarcade-decomp): both of the game's programs decompiled one
function at a time into readable C, and checked frame by frame against MAME in state, picture and sound.

**This repository contains no game data.** As with [n64decomp/sm64](https://github.com/n64decomp/sm64), you
bring your own ROM set (MAME's `simpsons`) for everything else: the tools verify it, extract the assets, and
you build your own executable, which runs from the assets and opens no ROM.

## Status

As of 05-11-2026:

- [x] ROM set verification (MAME set `simpsons`, 4 Players World, set 1), by CRC32 and SHA-1 of every file
- [x] A reference: the original programs on MAME's 053248 and Z80 cores, with MAME's K053260 and ymfm's YM2151,
      on a model of the board in C (`runtime/`): state and sound hashes per frame, the code it runs
- [x] The reference's video: MAME's K052109, K053246/K053247 and K053251, a picture hash per frame
- [x] Control scripts that play the game through (`tests/controls/`, `tools/make_scenarios.py`): the attract mode,
      the test mode's pages, games of one and four players, every stage and bonus game to its boss's end, and the
      ending; 25 scenarios, 343,270 frames on the reference
- [ ] The same scenarios compared frame by frame with the decompiled game
- [x] A decoder and disassembler for the 053248 in the shared core, the same text as MAME's at every offset of
      every program bank and of every opcode with every postbyte
- [x] The 053248's static analysis: all the code the scenarios run (42,668 places), found without traces, its
      banks followed
- [x] The Z80's static analysis: all the code the scenarios run (6,155 places), found without traces
- [x] The Z80's program and banks explained, every byte: code, described data (its tables, the 48 songs' tracks,
      the YM2151's and the K053260's patches) or fill
- [ ] Every byte of the 053248's program explained (99.86% now: code, described data, or fill, the assembler's
      leftovers between and after a bank's pieces among it)
- [ ] The decompiled C of both programs, and the board's runtime
- [x] The assets extracted by subject and checked byte for byte (`tools/extract_assets.py --check`): the sprites by
      the objects whose animations show them, the tiles by the scenes whose maps show them, the K053260's samples
      as WAV files, and every byte of data of both programs as text by name
- [ ] The assets loaded by name by the decompiled game

## Verifying your ROM set

```bash
git clone --recursive <this repository>
py tools/verify_rom.py rom/simpsons.zip
```

## Extracting the assets

```bash
py tools/extract_assets.py rom/simpsons.zip
py tools/extract_assets.py rom/simpsons.zip --check
```

The first writes `assets/` (never part of the repository): PNG sheets of the sprites and tiles by subject, WAV files
of the samples, and the programs' data as text by name; the second rebuilds the graphics and sample ROM files and
every data byte from them and compares them with your set's.

The tools are shared with the other games through [arcade-decomp](https://github.com/cheviman/arcade-decomp),
which `tools/core` holds as a git submodule.

## Legal

BSD 3-Clause License (see `LICENSE`). *The Simpsons* is a trademark of its owners; the game is Konami's. This
repository holds no part of the game's ROMs.
