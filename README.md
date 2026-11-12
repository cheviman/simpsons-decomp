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

As of 11-11-2026:

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
      `struct object` with each kind's own fields, every function named and commented by what it does in the
      game; still the same as the reference in all 25 scenarios in state, picture and sound
- [x] The sound program's C named and commented throughout: its 12 channel records as `struct channel` (the YM2151's
      and the K053260's fields by family), every patch loaded by name, every function commented, no variable named
      after a register or an address
- [x] The 053248's work RAM named throughout (the direct page's scratch bytes by the routine that uses them), its data
      and unused code named by what they are, and most of its parameters and locals named by what they hold
- [x] What the 053248's routines leave in Y for later ones, which no call links to them, kept as a global
      (`leftover_y`, as TMNT's carried registers), not passed through hundreds of handlers; its temporaries named,
      and its work RAM's records (palette jobs, sprite entries, coin slots, the players' records) as structures
- [x] The board's memory the 053248 keeps variables in (the K052109's RAM at 1840-18FF and 3840-38FF: scene waits,
      counts, signals) read and written by name, as are the board's registers
- [x] Every object field the 053248's C reaches named, by the family that owns it (no `->unk_XX` left)
- [x] The flags a 053248 routine hands its caller named by what they say (the 6809's convention: a carry for
      `landed`, `slot_found`, `gone`, `player_down`...): named where the routine works it out, and the name goes up
      by itself to every caller whose flag only comes from routines that say the same
- [x] What the 053248's handlers only pass along to each other in a register or a flag (a `d`, `u` or `carry` that
      comes in and goes on untouched) counted apart, as what the register held between routines: the step tables
      have no length, so a step's dispatcher may run on into the next table's handlers, and the C hands those values
      on as the original does (`tools/noise_report.py`: `passed_registers`, `passed_flags`)
- [x] The sound program's flags named the same way (`voice_ended`, `timer_ran_out`, `no_song`...), and both programs'
      temporaries and the 053248's stack slots named by what they hold (a loop's count, a pointer saved across a call)
- [x] The 053248's C as readable as its machine code lets it be: what still keeps a register's, a flag's or a
      stack slot's name, and why, is counted and listed under "Reading the C"
- [x] The assets extracted by subject and checked byte for byte (`tools/extract_assets.py --check`): the sprites by
      the objects whose animations show them, the tiles by the stages whose maps show them, the K053260's samples
      as WAV files, the music as Standard MIDI Files (a song a file, as the Z80's driver plays it), and every other
      byte of data of both programs as text by name: the records by their fields, the addresses as the names of what
      they point at; every piece named by what names it in the program (the function whose code reads it, the piece
      that points at it, an object kind's animations by what they show), none by its place; and the same assets
      whether or not the reference's runs are at hand
- [x] The assets loaded back in C byte for byte (`kref --assets-check`), the factory EEPROM among them
- [x] Both programs' data read by name by the decompiled C, from the assets' pieces: the game builds no image of the
      ROM's regions, and neither program's C reads its data through an address of the ROM (`tools/noise_report.py`,
      `rom_reads` 0); an address a program keeps in its state (a pointer into its data) is found among the pieces by
      the place it names

## Getting started

Requirements: Python 3.10 or newer (the tools use its standard library only), CMake 3.20 or newer, a C11 and C++20
compiler (Visual Studio 2026 Build Tools on Windows) and, for the game's window, the SDL2 development files: on
Windows, unpack `SDL2-devel-2.x.x-VC.zip` from [SDL's releases](https://github.com/libsdl-org/SDL/releases) into
`build/downloads/sdl2/`; elsewhere, the system's package (`libsdl2-dev`). Without SDL2 only the headless builds
are made. The game has been built and played on Windows; the build is written for other compilers too, but has not
been tried there yet.

1. Clone with the shared core, [arcade-decomp](https://github.com/cheviman/arcade-decomp), which this repository
   keeps in `tools/core` as a git submodule (the tools are the same for every game; a clone made without
   `--recursive` takes it with `git submodule update --init`):

   ```bash
   git clone --recursive https://github.com/cheviman/simpsons-decomp
   ```

2. Put your own copy of MAME's `simpsons` set (4 Players World, set 1) in `rom/` (the .zip as is, or its files),
   and check it: every one of its 14 files is known by its CRC32 and SHA-1, whatever its name.

   ```bash
   python tools/verify_rom.py
   ```

   | File | Size | CRC32 | What it holds |
   |---|---|---|---|
   | `072-g02.16c`, `072-g01.17c`, `072-j13.13c`, `072-j12.15c` | 128 KB each | `580ce1d6`, `9f843def`, `aade2abd`, `479e12f2` | 053248 program, 0x00000-0x7FFFF in that order: 64 banks of 8 KB, which the CPU sees one at a time at 6000-7FFF; the last four (0x78000-0x7FFFF) are the fixed program it sees at 8000-FFFF |
   | `072-e03.6g` | 128 KB | `866b7a35` | Z80 sound program: its first 32 KB fixed at 0000-7FFF, the rest 16 KB banks at 8000-BFFF |
   | `072-b07.18h`, `072-b06.16h` | 512 KB each | `ba1ec910`, `cf2bbcab` | tile graphics (K052109) |
   | `072-b08.3n`, `072-b09.8n`, `072-b10.12n`, `072-b11.16l` | 1 MB each | `7de500ad`, `aa085093`, `577dbd53`, `55fab05d` | sprite graphics (K053246/K053247) |
   | `072-d05.1f`, `072-d04.1d` | 1 MB, 256 KB | `1397a73b`, `78778013` | K053260 samples |
   | `simpsons.12c.nv` | 128 bytes | `ec3f0449` | the ER5911 EEPROM as the board leaves the factory (without it the game boots upside down and reports an error) |

3. Extract the assets into `assets/` (never part of the repository), and check that they build back into your ROM
   set byte for byte: the tile, sprite and sample files, every data byte of both programs, and the EEPROM.

   ```bash
   python tools/extract_assets.py
   ```

   ```bash
   python tools/extract_assets.py --check
   ```

   Both take the ROM set's folder or .zip first (`rom/` by default), and `--out FOLDER` for another place than
   `assets/`. "The assets" below says what they are.

4. Build the game and the development tools into `build/bin/`:

   ```bash
   cmake -S . -B build/msvc
   ```

   ```bash
   cmake --build build/msvc --config Release --parallel 6
   ```

   That makes `simpsons` (the window), `simpsons_game_headless` (the same game with no screen or sound, for the
   checks) and the reference tools: `kref`, the original programs on MAME's cores, and the oracles that check the
   053248's disassembler, its lift and its helpers against MAME's (`-DSIMPSONS_REFERENCE_TOOLS=OFF` leaves them
   out; they need Python at configure time, which writes MAME's Konami CPU core). `simpsons_headless`, the
   translation scaffold, is built only after `tools/recompile.py` (see "Changing the decompilation").

5. Play:

   ```bash
   build/bin/simpsons
   ```

   The game reads its assets from `--assets FOLDER`, or from an `assets` folder beside the executable or up to
   three folders above it (so `build/bin/simpsons` finds the repository's), or in the current folder; it opens no
   ROM. The executable can be copied anywhere with SDL2's library beside it (`SDL2.dll` on Windows, which the build
   puts next to it) and the assets: they come from your ROM set, so they are yours, not to share.

   Or run the game without a window, from the repository's root (it reads `assets/` there), here with the controls
   of the attract mode, writing a hash of every frame:

   ```bash
   build/bin/simpsons_game_headless --script tests/controls/attract.txt --hashes build/attract.txt
   ```

## Playing

It is the arcade game for four: each player has a coin slot and a start button, and a coin, then the start, attack
or jump button, brings that player's character in (player 1 is Marge, 2 Homer, 3 Bart, 4 Lisa). The attack or
jump button of a player in the game skips a story.

| Control | Keys |
|---|---|
| Move (player 1) | the arrow keys |
| Attack, jump | Z or left Ctrl; X or left Alt |
| Coins 1-4 | 5, 6, 7, 8 |
| Start 1-4 | 1, 2, 3, 4 |
| Test switch | F2 |
| Full screen | F11 or Alt+Enter |
| Smooth or sharp pixels | F3 |
| Quit | Escape |

Game controllers are players 1 to 4 in the order they are plugged in: the pad or the left stick moves, A
attacks, B jumps, Back puts a coin in, Start is the start button.

The board keeps its settings in its EEPROM, and the game starts with the factory's every time (`assets/eeprom.txt`):
what the test mode changes lasts until the game is closed. The test switch pressed during the attract mode opens
the test mode's menu, which the first player's stick and attack button go through (ROM, screen, colour and I/O
checks, music and sound tests, the start buttons and the coin and game options); held from the start
(`--service`), it resets the EEPROM's settings.

Options of `simpsons` and `simpsons_game_headless`: `--script FILE` plays a control script instead of the
controls (`simpsons --fast` runs it without waiting for each frame's time); `--hashes`, `--video-hashes` and
`--sound-hashes FILE` write a hash of every frame's state, picture and sound, as the reference does; `--service`
holds the test switch from the start; `--assets FOLDER` says where the assets are. `simpsons_game_headless` also
takes `--frames N` (600, or the script's `end`, by default), `--sound-wav FILE` (the sound the ports play, 16-bit
stereo) and `--dump FRAME ... --dump-dir DIR` (the board's memories at the end of those frames, as `kref --dump`
writes them).

A control script (`runtime/include/simpsons/script.h` has the format) is a line an event, applied when a frame's
VBLANK starts: `FRAME press INPUT [FRAMES]`, `hold INPUT`, `release INPUT`, `poke ADDRESS VALUE` (a byte through
the bus) and `end`, where `FRAME` is a frame number or `+N` after the previous event, and the inputs are `coin1` to
`coin4`, `service`, and for each player `leftN`, `rightN`, `upN`, `downN`, `attackN`, `jumpN` and `startN`.

## Changing the decompilation

`src/` is written by the decompiler from your ROM set, `symbols.txt`, `tools/game_profile.py` and the names of the
assets' data pieces (`assets/data/layout.txt`); `src/sound/` from the sound program and `sound_symbols.txt`.
Change those (names, types, comments, what the analysis cannot work out alone), not the C, and write it again.
Extract the assets first, and again after a change to `symbols.txt` that names data: the C reads the program's
data by the names the assets give it.

```bash
python tools/decompile.py
```

```bash
python tools/decompile_sound.py
```

`decompile_sound.py` also writes the Z80's timing table, `build/sound/timing.txt`, which the reference needs to
keep the sound program's time as the game's own sound board does: run it once in a new clone before the checks
below. Then build again (step 4 of "Getting started").

`build/bin/kref` runs the original programs on MAME's cores against the same board model. Both it and the game
take the control scripts of `tests/controls/` (written by `tools/make_scenarios.py`), and both write hashes of
every frame. This runs every script on both, compares them frame by frame in state, picture and sound, and
checks that the static analysis alone finds all the code the reference ran (results in `build/scenarios/`, or
`--out DIR`; `--native-only` reuses the reference's results of an earlier run there; scripts named by their file
name, without `.txt`, run alone):

```bash
python tools/check_scenarios.py --video --sound --jobs 6
```

The game's own sound board against MAME's, sample for sample and byte for byte of the Z80's RAM, `kref` running
both on the same commands:

```bash
python tools/check_sound_board.py --jobs 6
```

Every function's ifs, loops and switches against the program's jumps, the code no scenario runs too, for the
053248 program and for the sound program:

```bash
python tools/check_structure.py build/structure
```

```bash
python tools/check_structure.py build/structure_sound --sound
```

What the C still has of the CPU, of the decompiler and of the ROM's places, against `tools/noise_baseline.txt`
(`--save` makes the current numbers the baseline):

```bash
python tools/noise_report.py
```

No executable holds a stretch of the ROM set:

```bash
python tools/rom_in_executables.py
```

Other tools:

- `tools/disassemble.py` runs the 053248's static analysis and writes the listing, `build/listing/simpsons.s`,
  with a report beside it (`--trace FILE ...` checks it against the places a run of the reference executed,
  `kref --trace`).
- `tools/coverage.py --reads build/reads` classifies every byte of the 053248 program (code, data the code or
  `symbols.txt` describes, fill) with the bytes the reference read as data (`kref --rom-reads FILE` for each
  script, as `build/reads/NAME/rom_reads.txt`); `tools/sound_coverage.py` does the same for the sound program
  (`kref --sound-rom-reads`).
- `tools/data_walk.py` walks the data the engines read from where the code hands it over (animations, sprite
  lists, maps and tile blocks, palettes, texts, spawn lists, stories, demos...): `build/listing/data_walk.txt`.
  `tools/sound_data_walk.py` walks the music from the song tables, in the fixed program and in the banks:
  `build/listing/sound_data_walk.txt`.
- `tools/recompile.py` writes the translation scaffold the decompiler grew from (a C statement per instruction)
  into `build/generated/`, from your ROM; CMake then builds `simpsons_headless` from it, and
  `check_scenarios.py --translated` checks it.
- `python tools/decompile.py --trace --out DIR` writes a copy of the C in which every function and block reports
  itself (build it with `-DSIMPSONS_DECOMPILED_DIR=DIR` and a `-DSIMPSONS_BIN_DIR` of its own, run it with
  `SIMPSONS_TRACE=FILE` and `SIMPSONS_TRACE_FRAMES=FIRST-LAST`); `tools/core/konami/reference/compare_order.py`
  finds where it parts from `kref --order FIRST LAST FILE`, every instruction of those frames in order.
  `--variables FILE` lists every local with the instructions that write it, which `symbols.txt`'s `local` lines
  name them by; `--checks` writes a build in which a jump through a table with an index it does not have stops
  the program.
- `kref --dump FRAME ... --dump-dir DIR` saves the board's memories at the end of frames, `--video-dump FRAME
  ... --video-dir DIR` the frames as BMP, `--sound-wav FILE` the sound mixed, `--text FRAME` the fixed layer as
  text, `--jumps FILE` where each jump through a register or a table went, `--interrupts FILE` where each
  interrupt came, `--video-check FILE` and `--sound-check` the game's own video and sound chips against MAME's,
  `--assets-check assets` the assets against the ROM set; `--timing cycles` runs at MAME's pace instead of by
  frames, and `--rom FOLDER` reads the ROM set from elsewhere than `rom/`.
- `tools/core/konami/reference/compare_konami_with_mame.py` checks the 053248 disassembler against MAME's at every
  offset of the program and of an image of every opcode, `compare_konami_lift_with_mame.py --program rom` the lift
  of every opcode and of the program's instructions against MAME's core, from random states, and
  `compare_konami_ops.py` the C helpers of the translation on all their inputs.

## Layout

```
rom/                      your ROM set (not in the repository)
assets/, build/           made on your machine (not in the repository)
src/                      the 053248 program's C, decompiled (tools/decompile.py writes it), in files by subject
src/sound/                the Z80 sound program's C (tools/decompile_sound.py writes it)
symbols.txt               the 053248 program's names, types, structures and fields, parameters and locals, what
                          pointers point at, the files, and the layout of the tables the analysis cannot measure
                          alone; its comments keep the evidence for each name, and its "comment" lines are what
                          the C says above each function
sound_symbols.txt         the same for the sound program
runtime/                  the board in C: its memory map, banks, inputs, interrupts and EEPROM (machine.c), the
                          video (video.c), the sound board and its chips (sound_board.c, sound_cpu.c, ym2151.c,
                          k053260.c), the assets into the board's memories and the programs' data by name
                          (assets.c, png.c, music.c), the decompiled program's runtime (game_program.c: the frame,
                          the bank, the interrupts, the tables) and the game as the ports run it (game.c); also
                          what only the tools use: the ROM set's reader (rom_set.c, inflate.c), the board as the
                          reference's Z80 sees it (sound.c), the scripts (script.c) and the translation
                          scaffold's runtime (konami_cpu.c, konami_ops.c, board_code.c)
runtime/replaced.txt      the functions the board puts its own in place of (the boot's ROM test), and
runtime/sound_replaced.txt  the sound program's (its reset and its ROM test)
ports/headless/           the game with no screen or sound, for the checks (simpsons_game_headless; with the
                          translation scaffold, simpsons_headless)
ports/sdl2/               the game in a window, on SDL2: picture, sound, keyboard and game controllers
tests/controls/           the control scripts: coins, buttons, moves and pokes by frame
tools/core/               arcade-decomp, the shared core (git submodule): the decompiler, the 053248 (konami_cpu)
                          and Z80 frontends, the analyses, the checks; its konami/reference/ holds kref and the
                          copies of MAME's and ymfm's code it builds from
tools/game_profile.py     what the core needs to know of this game
tools/simpsons_rom.py     the ROM set: its files by hash, and the regions as the board lays them out
tools/verify_rom.py       the ROM set's check
tools/extract_assets.py   the assets from the ROM set, and --check back (simpsons_graphics, sound_assets,
                          data_assets, sound_data_assets, sound_music)
tools/sound_music.py      the songs as Standard MIDI Files, and back to the driver's bytes
tools/data_walk.py        the data the engines read, walked from the code
tools/sound_data_walk.py  the music's tracks and patches, walked from the song tables
tools/make_scenarios.py   writes the control scripts
tools/disassemble.py      the static analysis: build/listing/simpsons.s and report.txt (the core's)
tools/coverage.py, sound_coverage.py   every byte of each program as code, data or fill
tools/decompile.py, decompile_sound.py   the programs as C
tools/recompile.py        the translation scaffold: build/generated/
tools/check_scenarios.py, check_sound_board.py, check_structure.py, rom_in_executables.py   the checks
tools/noise_report.py     what the C still has of the CPU, against tools/noise_baseline.txt
```

## The assets

`python tools/extract_assets.py` writes them from your ROM set into `assets/`, by subject, and `--check` builds
every byte of the ROM set but the code back from them:

```
tiles/       the K052109's 8 x 8 tiles in 71 sheets: one a scene's area and layer, by the scene tables and the
             character banks its layer modes give (stage_1_downtown_area_0_layer_a, stage_2_krustyland_...,
             stage_8_power_plant_..., bonus_1_..., attract_intro_..., name_entry_..., ending_...), then
             the tiles nothing shows, 256 a sheet (unused_XXXXX); tiles.txt lists each sheet's codes
sprites/     the K053247's 16 x 16 cells in 114 sheets, by the animation set whose animations show them, named by
             what it shows (marge, homer, bart, lisa, goon, moe, nelson, sideshow_bob, kabuki_warrior, smithers,
             burns_robot, mr_burns...; kind_AD, a set nothing sets up or shows), then the cells nothing
             shows (unused_XXXXX); sprites.txt lists each sheet's codes
sounds/      the K053260's 163 samples by the sound driver's sample table (sample_000.wav ...), the bytes no
             sample plays (unused_XXXXXX.wav), and samples.txt: where each goes
sound_data/  the Z80 program's data as text: patches.txt (the YM2151's and the K053260's), tables.txt (the
             driver's), other.txt (fill), layout.txt; music/ a Standard MIDI File a song (attract.mid,
             stage_1.mid ... stage_8_boss_1.mid, bonus_1.mid, name_entry.mid, ending.mid...; song_XX for the seven
             songs nothing in the program starts, two of them empty), and music.txt: the song commands each file
             plays for, and what the game plays it for
data/        the 053248 program's data as text, a file a subject (animations, sprite_lists, maps, tile_blocks,
             palettes, palette_effects, texts, screens, spawns, stories, objects, demos, tables, fill), a section
             a piece, every piece named; code_read.txt, the fixed program's code the map engines read as tiles or
             as a map past a map's edge, which the game has to be given as data; structures.txt, the structures
             the record lines name, so that the files read back without symbols.txt; layout.txt, each piece's
             name, place, length and file
eeprom.txt   the ER5911's 128 bytes as the board leaves the factory (the settings the game starts with)
```

- **Sheets.** 4-bit indexed PNGs, 16 sprite cells or 32 tiles a row: a pixel is its pen, as the chips read it.
  The colours are those of the palette most of the sheet's sprites or tiles show with, as the palette sets load
  them: an approximation, for the eye; the game reads the pens only, and its colours are the palettes of
  `data/palettes.txt`. A tile or a cell goes to the first sheet that shows it.
- **Data.** A piece is a section, `[name] kind`, of typed lines that give its bytes back in order: numbers (`u8`,
  `u16` in hex, `s8`, `s16` in decimal), `ref NAME[+N]` for the address of a piece or of code (`code_PLACE`),
  `frame` and `end` for an animation, `sprite` for a sprite list's entry, `colours` for a palette (xBGR 555),
  `text` for the game's texts (`@` a space), `record STRUCT` for a record of a table `symbols.txt` describes, field
  by field, and lines of their own for a scene's map and blocks (`area`), a palette set's loads (`load`), an
  object's setup (`setup`), a tile picture (`picture`), a demo (`demo`) and an object's path (`step`, `loop`).
  A piece is named by `symbols.txt`, else by what names it in the program: the routine whose code reads it, the
  named piece that points at it (an entry of a table by its index: `goon_animations_3`; an animation's sprite
  lists: `goon_animations_3_sprites`), an object kind's animations by what they show; a piece nothing names but
  the one before it is that one's rest (`_rest`) or fill (`_fill`); none by its place. The same assets come out
  whether or not the reference's runs are at hand. `tools/data_assets.py`'s docstring has every line's format.
- **Music.** A file's track 1 is the song (its name, its tempo events, which give the game's speed: within 0.3 %
  root mean square of the reference's on 16 songs timed against it, 0.8 % at most), and tracks 2 to 13 the
  driver's channels (the YM2151's eight, the K053260's four), with their loops and parts played as the driver plays
  them; 24 ticks a quarter note, one tick 32 of the driver's units; a note is a Note On and Off at its key (the
  drums on General MIDI's percussion), and what MIDI has no event for (the octave, the instrument, the gate,
  detune, the pitch envelope, the LFO, loops, calls, jumps, held notes, rests) is in sequencer-specific events with
  the driver's bytes. A file shows at most some 3 minutes of its song. The board wires only the YM2151's left
  output; the files pan as the program asks. `tools/sound_music.py`'s docstring has the format.

Edit them and run the game: it loads them. A piece keeps its size (the code reaches the data at fixed places),
and so do a song's channels and a sample; a note's pitch and length, a palette's colours, a tile's or a sprite's
pens can change. A note a loop or a part plays more than once has to be the same each time it is shown.

## Reading the C

The 053248 program's C lives in `src/`, in files by subject:

```
game.h  ram.h  table.c   the prototypes and leftover_y; the work RAM's variables and structures, the board's
                         registers, the data's tables and records; the code the board runs by itself (the reset,
                         the IRQ and FIRQ handlers) and the registry of the tables the game loads by name
system/   boot.c         the reset: the board set up, the RAM and ROM checks, the main loop that runs the jobs
          interrupts.c   the IRQ's handler (the K052109's, at VBLANK: the inputs, the coin counters, the jobs) and
                         the FIRQ's (the sprite DMA's)
          inputs.c  jobs.c  eeprom.c  random.c  reset.c   the coin slots, the credits and the controls; the queues
                         of jobs and of sound commands for the Z80; the EEPROM's test and reset; the random number;
                         clearing a stage's, a game's and the scores' variables
          jump_table.c   the fixed program's entry points for the banks, an LBRA each
attract/  sequence.c  intro.c  title.c  warning.c  demo.c  high_scores.c   the attract mode: its scenes until a
                         credit, the opening and the family's profiles, the title, the export warning, the demo, the
                         high score table
game/     start.c  game.c  continue.c  game_over.c  name_entry.c  score.c  skip.c   the game's modes: the four
                         portraits the players join on, the game's steps, the continue, GAME OVER, the name entry,
                         the scores, the stories' skip
stages/   stage.c  stage_1.c ... stage_8.c  bonus_1.c  bonus_2.c   what every stage shares, and each stage's own
          story_steps.c  title_cards.c  stage_events.c  scroll.c  rank.c   the story steps, the title cards, the
                         scroll's holds and the waves of enemies, the camera, the game's rank
scenes/   story_1.c  story_scenes.c  story_actor.c  stage_ends.c  stage_7_scenes.c  stage_8_scenes.c
          scene_objects.c  game_start_portraits.c  ending.c   the scripted scenes: the stories and their actor, the
                         scenes at the ends of stages, the portraits, the family, the staff roll and the fade
players/  players.c  states.c  motion.c  reactions.c  effects.c  second_sprite.c  gauges.c   the four players: their
                         controls and states, their moves, what touches them, their blinking and voices, their
                         second sprite, the top line's scores, lives and gauges
enemies/  enemy_states.c  enemy_moves.c  enemy_targets.c  enemy_hits.c  enemy_hit_reactions.c  enemy_climbing.c
          enemy_facing.c  reactions.c  hurt.c   what the enemies share: thinking, moves, targets, hits, reactions
          goon.c  goons.c  goon_actions.c  goon_bomb.c  zombies.c  rising_zombie.c  grabbing_zombie.c  ninja.c
          robot.c  knight.c  lumberjack.c  gorilla.c  donut.c  cloud_devil.c  ghost_on_rope.c  flying_saxophone.c
                         each kind of enemy, its actions and what it throws
bosses/   wrestler.c  krusty_balloon.c  stage_3_boss.c  football_player.c  bear.c  dreamland_boss.c
          dreamland_boss_objects.c  stage_7_boss.c  stage_7_boss_helper.c  stage_8_boss.c  burns_robot.c
          burns_robot_parts.c  stage_bosses.c   each stage's boss (1 to 8, then Mr. Burns' robot), its objects, and
                         what the bosses of stages 3, 4 and 5 share
objects/  object_lists.c  object_setup.c  spawning.c  collisions.c  bank_entries.c   the four object lists'
                         dispatchers, an object's setup, gravity and landing, the stage's spawns and the free slots,
                         the hit checks, each object bank's table of handlers
          items.c  police_car.c  doors.c  obstacles.c  teacup_goon_ride.c  belly_dancer.c  marge_cloud.c  ...
                         the other objects, one a file, named by what they show
bonus/    balloon.c  wake_up.c  results.c   the two bonus games and their results
engine/   objects.c  floor.c  directions.c   the objects' slots, the floor map, directions and speeds
video/    sprites.c      the sprite engine: the objects' animations, their moves, the depth sort and their sprites
          background_maps.c  palette.c  text.c  clear.c  dream_wave.c   the tile layers' maps, the palette jobs,
                         the text printers, clearing the layers, stage 6's wave
test_mode/  menu.c  checks.c  rom_check.c  sound_test.c  options.c   the test mode's pages
sound/    sound.h  main.c  music.c  chips.c  fm_effects.c  pcm_effects.c  drums.c  unused_effects.c  tables.c
                         the Z80's: the reset, the commands and the main loop; the music; the chips; the effects;
                         the drums; the tables it reads by name
```

Each file's header says what it holds; `symbols.txt`'s `file` lines give each stretch of the program to its file,
and a file's functions are in the order of their addresses. What the C uses besides memory is in
`runtime/include/game/support.h`.

- **Memory.** The game's variables are lvalues over the work RAM (4000-5FFF) by name (`game_mode`, `game_step`,
  `step_phase`, `camera_x`); the work RAM is kept the other way round in the host's memory, so that a value of the
  big-endian 053248 of any width at any address is a value of the (little-endian) host's, and an array of it is
  written as `NAME(index)` (`player_controls(2)`). Its structures are reached with `OBJECT(address)` (the 33
  objects from 4A40, `OBJECT_ADDRESS(n)`: the four players at 4A40 + C0 x n, each with its second sprite's object
  60 after it, then the four lists the dispatchers run, 4D40 x 6, 4F80 x 8, 5280 x 10 and 5640), `PALETTE_JOB`,
  `SPRITE_ENTRY`, `COIN_SLOT`, `PLAYER_INPUT`, `PLAYER_VALUES` and `PLAYER_COUNTERS`: the game keeps 16-bit
  addresses in its variables, as the original does. The fields every object has are the object's own
  (`OBJECT(object)->animation`); what each kind keeps in the rest of its bytes is a view of the object for its
  family of functions (`OBJECT(boss)->stage_3_boss.join_wait`), and a family whose name starts with another's reads
  that one's fields too.
- **Data and banks.** The program's data are read by name from the assets: tables (`goon_hold_animations[i]`,
  `TABLE8(name, offset)` where the code reads one at another width or past its start), records reached through an
  address the program keeps (`PLAYER(player)->state`, `SPAWN(spawn)->...`), single values a pointer walks
  (`GAME_TEXT_ENTRY(p)`). The fixed program picks the bank it sees at 6000-7FFF itself, `window_bank = 0x12u;
  set_lines(window_bank);` (the original's SETLN), and the C reads the data of the bank the CPU has. The board's
  devices are reached through its bus, as the board has them: its registers by name
  (`io_write8(colour_bases_layers_a_b, 0x36u)`), and the K052109's RAM the program keeps variables in
  (`bonus_2_state`, at 1840).
- **Registers.** Everything a function keeps in registers is a parameter, a result or a local, named by
  `symbols.txt` or by what it holds (the object a handler runs on is `object`, a player's record `player`). What
  one routine leaves in Y and another reads before setting it, all through the frame (the object lists' runners
  hand each handler what the one before left there), is the game's state, and the C keeps it in one global
  variable, `leftover_y` (`src/game.h`); the runtime puts it back when an interrupt's handler returns, as the CPU's
  RTI puts back the registers the interrupt pushed.
- **Results and flags.** A function hands back one value as its return value and more through pointers
  (`uint16_t *p_text`); a caller's variable goes in and comes out. A 6809 routine often answers in a flag, the
  carry mostly: in the C that is a result named by what it says, where the routine works it out (`landed`,
  `slot_found`, `no_floor`, `gone`, `player_down`), and the name goes up to every caller whose flag only comes from
  routines that say the same.
- **Comments.** Every function has a comment above it in the game's terms (the `comment` lines of `symbols.txt`
  and `sound_symbols.txt`); code nothing runs starts with "Unused:". The rest of `symbols.txt`'s comments keep the
  evidence: the instructions of the listing that show each name.
- **Control flow.** Loops, `if`, `switch` and `return` come from the original's branches; there is no `goto`. A
  jump through a table of handlers (a mode's steps, an object's states) is a `switch` on the offset the table is
  read with (`switch ((int8_t)(uint8_t)((uint32_t)step_phase << 1))`), each case the call of the handler the table
  holds there; the tables have no length, and a switch keeps the cases of the handlers that follow its table,
  which an index past its end reaches. In the sound program, the handler a channel's record keeps is a `switch` on
  that handler, its cases named after them (`case fm_effect_02_ADDRESS:`). Where the original's jumps cross in a
  way blocks cannot, a `bool` named after the place the jump goes to carries it: 10 functions (`enemy_think`,
  `player_run`, `player_team_move`, `player_team_jump`, `player_team_fall`, `scripted_object`,
  `stage_8_boss_phase_1`, `name_entry_edit_initials`, `test_print`, and the sound program's `music_tick`). A
  function whose every path returns from a switch ends with `unreachable()`. A routine that drops its own return
  address and returns to its caller's caller hands back `left_caller` set, and its caller returns at once.
- **Interrupts and the frame.** `frame_wait(SIMPSONS_FRAME_WAIT)` is where the main loop finds no job and the board
  moves on to its next frame (and the boot's two waits, `SIMPSONS_BOOT_WAIT` for the sprite DMA's FIRQ and
  `SIMPSONS_SWITCH_WAIT` for the test switch to be let go); `take_interrupts()` is where the interrupts raised are
  handled, and `firq_point()` where the IRQ's handler takes the sprite DMA's FIRQ. The interrupt mask is the
  runtime's (`enable_irq()`, `restore_mask()`), and the handlers are ordinary functions (`irq_handler`,
  `firq_handler`). The boot's ROM test is the board's own (`BOARD_ORIGINAL(add_rom_bytes)`, `runtime/replaced.txt`;
  the sound program's reset and ROM test, `runtime/sound_replaced.txt`): the game has no ROM to sum.
- **The sound program.** `src/sound/` is the Z80 program the same way: its 12 channel records as `struct channel`,
  by the chip's channel each drives (`CHANNEL(FM_0)` to `CHANNEL(FM_7)` for the YM2151's, `CHANNEL(PCM_0)` to
  `CHANNEL(PCM_3)` for the K053260's voices), their fields by the family of handlers that uses them
  (`CHANNEL(channel)->pcm.key_bit`); its tables by name from the assets (`src/sound/tables.c`), the self test's
  results it keeps in the Z80's other registers as globals (`self_test_failures`, `program_rom_sum`), the chips
  through the board's bus; `z80_block(cycles)` opens each stretch of code with the time it takes, so the chips'
  timers, the interrupt and the samples happen when they did on the board, and `z80_halt()` waits for the
  K053260's NMI.

What the C keeps of the original's machine code, and why (`python tools/noise_report.py`):

- One global variable, `leftover_y`, for what the routines carry in Y from one to a later one (above).
- 625 parameters and locals named after a register (`d`, `u`) and 254 flags' variables (`carry`) that only pass a
  value along (`passed_registers`, `passed_flags`): what the register or the flag held between routines. The steps
  of a mode and the objects' states run through tables of handlers that have no length, so a step's dispatch may
  run on into the next table's handlers, and each handler hands D, U and the carry on to the next as it found them;
  the C hands them on as the original does.
- 132 results written back before an early return (`*p_d = d;`), in 10 step dispatchers: a dispatcher hands back
  what the handler it ran left.
- 187 parameters and locals still named after a register that the code uses, and 164 flags' variables it uses,
  all of the 053248's: values that are two things at once (D's two halves set apart, a register that holds a count
  and then a pointer), and the carries of sums and shifts the original does a byte at a time, which are carries.
- 35 partial writes of a variable, `x = (x & ~0xFFu) | y`: a byte written into a value whose other byte is read
  afterwards (the 053248's A and B are the halves of D); 30 of them put a part of one value into another.
- 73 places that read or write several fields at once or a table at another width (`AS16`, `AT16`, `TABLE8`,
  `TABLE16`): the original does (the random number, a word, read a byte at a time).
- 763 places that reach memory through an address the code works out (`mem_read8`, `mem_write16`): the routines
  that clear, copy or test memory wherever they are told (`tools/game_profile.py`'s `MEMORY_ROUTINES` lists each
  with its reason), the printers and the map drawers, the scripts, and the players' records whose variables'
  addresses the data gives; and 1,294 reads and writes of the board's devices through the bus (`io_write8`), the
  K052109's RAM the program keeps variables in among them.
- 4 values the decompiler works out once, named by a number (`t1`, in the board's own ROM test), 3 stack slots
  named after their place, and 7,927 casts.
- 136 `unreachable()` after a switch whose every case returns; one jump through a table that holds no code
  (`invalid_jump`, in `unused_enemy_run_action_jump`, which nothing runs); 2 functions nothing reaches that keep a
  stack the C has not (`lost_stack`: `story_1_bart_steps_overrun` and `palette_effects_overrun`, where an entry past
  the end of a table would lead, the middle of other code); and 10 functions with a control variable (above).

With nothing of all that, 3,734 of the 4,362 functions (85.6 %) and 99.1 % of the lines of code; with nothing but
the global, the fields at once, the parts changed in place and the memory routines' addresses, 3,794 (87.0 %) and
99.3 %.

## How the port works

- **Game code.** The 053248 and Z80 machine code is decompiled to C (`src/`, `src/sound/`), so the game runs
  natively with no CPU emulation. `runtime/src/game_program.c` runs it by frames: the program takes no time, and
  the board moves on to its next VBLANK where the program waits for one, as on a board fast enough never to lag;
  the interrupt handlers are functions it calls there, and the bank the program picks is a variable of the
  runtime's. The sound board runs the sound program on its own timing model (`runtime/src/sound_cpu.c`), which the
  reference keeps around MAME's Z80 too, so that the two compare sample for sample.
- **Data.** The game loads its assets (`runtime/src/assets.c`, `png.c`, `music.c`): the sheets into the video
  chips' memories, the samples into the K053260's, the factory EEPROM, and both programs' data, piece by piece,
  by the places the programs know them by. The tables the C reads by name are copies the loader makes, each
  element in the host's byte order (`src/table.c`, `src/sound/tables.c`); an address a program keeps in its
  variables is found among the pieces through the bank the CPU has; a read of a byte only the original's code
  holds stops the game. It opens no ROM.
- **Video and sound.** The K052109, the K053246/K053247, the K053251 and the palette are a library
  (`runtime/src/video.c`) that draws each frame from the board's memories into a 320 x 224 picture; the YM2151
  (`ym2151.c`) and the K053260 (`k053260.c`) are libraries that make the samples, which the sound board mixes in
  stereo as the board's speaker has them (`sound_board.c`: the YM2151's left output on both sides).
- **Platforms.** A port provides a window, input, audio output and the frame's pace (59.185 frames a second),
  through the game's calls (`runtime/include/game/game.h`: load the assets, reset, run, and a hook at the end of
  every frame) and the board's inputs (`runtime/include/simpsons/machine.h`); `ports/sdl2/` is the first.

## Legal

- This project is licensed under the BSD 3-Clause License; see `LICENSE`.
- The C in `src/` is the game's programs decompiled into a new form: logic only, with names and comments written
  for this project. No ROM contents (graphics, sound, data) and no extracted assets are distributed by this
  project; they come from your own ROM set.
- `runtime/src/machine.c`, `video.c`, `k053260.c`, `sound_board.c` and `ym2151.c` follow the behaviour of MAME's
  `simpsons.cpp`, `k052109.cpp`, `k053246_k053247_k055673.cpp`, `k053251.cpp`, `k053260.cpp`, `eepromser.cpp` and
  `eeprom.cpp` and of ymfm's OPM (all BSD-3-Clause); the ROM set's layout comes from MAME's `simpsons.cpp`. Copies
  of MAME's and ymfm's code are in arcade-decomp's reference tools only (`tools/core/konami/reference/`), under
  their licenses, and never built into the game.
- *The Simpsons* is a trademark of its owner, and the arcade game is Konami's. This project is not affiliated with
  or endorsed by either.
