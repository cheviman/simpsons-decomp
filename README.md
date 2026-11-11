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

As of 09-11-2026:

- [x] ROM set verification (MAME set `simpsons`, 4 Players World, set 1), by CRC32 and SHA-1 of every file
- [x] A reference: the original programs on MAME's 053248 and Z80 cores, with MAME's K053260 and ymfm's YM2151,
      on a model of the board in C (`runtime/`): state and sound hashes per frame, the code it runs
- [x] The reference's video: MAME's K052109, K053246/K053247 and K053251, a picture hash per frame
- [x] Control scripts that play the game through (`tests/controls/`, `tools/make_scenarios.py`): the attract mode,
      the test mode's pages, games of one and four players, every stage and bonus game to its boss's end, and the
      ending; 25 scenarios, 343,270 frames on the reference
- [x] The same scenarios compared frame by frame with the decompiled game: all 25 the same in state, picture and
      sound
- [x] A decoder and disassembler for the 053248 in the shared core, the same text as MAME's at every offset of
      every program bank and of every opcode with every postbyte
- [x] The 053248's static analysis: all the code the scenarios run (42,668 places), found without traces, its
      banks followed
- [x] The 053248's instructions lifted to the shared core's IR, checked against MAME's core: every opcode with every
      second byte, and every instruction of the program, from random states, the same registers, flags and memory
      accesses (305,100 states, 0 differences)
- [x] Frame timing (`runtime/include/simpsons/frame.h`): the board moves on to its next frame where the program
      waits for one, as on a board fast enough never to lag, the reference's default (`--timing cycles` for MAME's
      pace)
- [x] The 053248 program translated to C an instruction at a time (`tools/recompile.py`, the translation scaffold),
      the same as the reference in every scenario, frame by frame, in state and picture (25 scenarios, 343,270
      frames)
- [x] The Z80's static analysis: all the code the scenarios run (6,155 places), found without traces
- [x] The Z80's program and banks explained, every byte: code, described data (its tables, the 48 songs' tracks,
      the YM2151's and the K053260's patches) or fill
- [x] Every byte of the 053248's program explained: code (the unused routines among it), described data (what the
      engines read, walked from where the code hands it over, and the tables `symbols.txt` names), or fill (the
      assembler's leftovers between and after a bank's pieces)
- [x] The board's runtime in C, checked against MAME's frame by frame in all 25 scenarios: the video (the K052109,
      the K053246/K053247, the K053251 and the palette, pixel for pixel), the sound chips (the YM2151 and the K053260,
      sample for sample) and the board's own code in place of the boot's ROM test
- [x] The Z80 sound program decompiled to readable C (`src/sound/`, `tools/decompile_sound.py`), on a timing model the
      reference keeps too (`kref --sound-timing`): the same samples and RAM in every scenario
- [x] The game from its assets, in a window (`simpsons`, SDL2) or headless: it opens no ROM, and no executable holds
      any of it (`tools/rom_in_executables.py`); the same as the reference in all 25 scenarios in state, picture and
      sound
- [x] The 053248 program decompiled to structured C (`src/`, `tools/decompile.py`): no goto, the same as the
      reference in all 25 scenarios in state, picture and sound; the game in its window runs it
- [x] The 053248's C by subject (`src/attract`, `enemies`, `players`, `stages`, `test_mode`...), its objects as
      `struct object` with each kind's own fields, every function but 5 named and commented by what it does in the
      game; still the same as the reference in all 25 scenarios in state, picture and sound
- [x] The sound program's C named and commented throughout: its 12 channel records as `struct channel` (the YM2151's
      and the K053260's fields by family), every patch loaded by name, every function commented, no variable named
      after a register or an address
- [x] The 053248's work RAM named throughout (the direct page's scratch bytes by the routine that uses them), its data
      and unused code named by what they are, and most of its parameters and locals named by what they hold
- [x] What the 053248's routines leave in Y for later ones, which no call links to them, kept as a global
      (`leftover_y`, as TMNT's carried registers), not passed through hundreds of handlers; its temporaries named,
      and its work RAM's records (palette jobs, sprite entries, coin slots, the players' records) as structures
- [ ] The 053248's C made fully readable: 82 object fields still named after their offset, about 850 parameters and
      locals still named after a register (mostly what a dispatcher hands its handlers in U and D, and the cases of the
      steps' switches that run on into the next table's)
- [x] The assets extracted by subject and checked byte for byte (`tools/extract_assets.py --check`): the sprites by
      the objects whose animations show them, the tiles by the stages whose maps show them, the K053260's samples
      as WAV files, the music as Standard MIDI Files (a song a file, as the Z80's driver plays it), and every other
      byte of data of both programs as text by name: the records by their fields, the addresses as the names of what
      they point at
- [x] The assets loaded back in C byte for byte (`kref --assets-check`), the factory EEPROM among them
- [x] Both programs' data read by name by the decompiled C, from the assets' pieces: the game builds no image of the
      ROM's regions, and neither program's C reads its data through an address of the ROM (`tools/noise_report.py`,
      `rom_reads` 0); an address a program keeps in its state (a pointer into its data) is found among the pieces by
      the place it names

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
of the samples, MIDI files of the music, and the programs' data as text by name; the second rebuilds the graphics
and sample ROM files and every data byte from them and compares them with your set's.

The tools are shared with the other games through [arcade-decomp](https://github.com/cheviman/arcade-decomp),
which `tools/core` holds as a git submodule.

## Legal

BSD 3-Clause License (see `LICENSE`). *The Simpsons* is a trademark of its owners; the game is Konami's. This
repository holds no part of the game's ROMs.
