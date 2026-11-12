"""
Name:        sound_music.py
Description: the sound program's music as Standard MIDI Files, a song a file, and back byte for byte
Version:     0.1.0
Created:     06-11-2026
Modified:    06-11-2026
Author:      Sebastian Toyos

For tools/sound_data_assets.py, which writes the music into assets/sound_data/music: a file a song header (the
commands 80-AF that play it: sound_symbols.txt's song_headers and song_banks), named by what the game plays it for
(SONGS), and music.txt, the files and their songs. --check rebuilds every byte of the songs' headers and tracks, and
of the tracks no song plays, from them.

How the driver plays a song (the Z80's program; places in sound_symbols.txt):
- A song command (80-AF, 034E) selects the bank song_banks gives (0359 "LD ($FE00),A") and reads the header
  song_headers gives: 12 tracks, one for each of the driver's channels (036A-03BB: F003 to F373, 80 bytes each),
  the YM2151's channels 1-8 and the K053260's 1-4. Each channel starts at 41AE: its command byte (+10) the song's (it
  plays while it is not 0), its tempo (+13) 1, its accumulator (+3A) FFFF, its gate left (+3C) 1, the rest 0, its
  place (+3E) the track's.
- The main loop (0B3D) is a pass: it waits for the YM2151's timer B (register 12 = F9, 7 x 16 samples of 64 clocks
  of 3.579545 MHz: 7168 clocks, 499.4 a second), starts it again (0C56), then runs the 12 channels in order (0C18;
  the K053260's at 0BF3) and counts the pass (0BEC: F3D0). A channel reads its track (4289) on the passes where the
  pass count's low 3 bits are its number's (one pass in 8: FM 1 and PCM 1 on the same one, and so on): the tempo is
  added to the accumulator, and at its carry (past FFFF) the channel reads its next commands up to a step.
- read_track (42AE) reads a byte at a time (4957); note_lengths (48FA) is 14 negative words, the units a length
  code adds to the accumulator: 32, 96, 192, 384, 768, 1536, 3072, 288, 576, 1152, 2304, 128, 256, 512 (a quarter
  note is 768: code 4; a whole 6; dotted 7-A; triplets B-D):
      L0            a rest (4633): its length's units L added to the accumulator (a rest shorter than what is
                    left goes on reading, 4636); the gate left 1, and the note keyed off
      0x (x 1-F)    the octave x (4649: 24 x the bytes into the pitch tables)
      LN (N 1-F)    a note (42C2): L its length, N its pitch: an FM channel's pitch word fm_pitches + 2 N + 24 x octave
                    (64 a semitone: N 1 at octave 1 is C1), a PCM channel's pcm_pitches + 2 N + 24 x octave + the
                    instrument's transposition (music_pcm_transpositions, in bytes); the detune (E6) added (42FE-432D).
                    The gate left (4916) is the note's units left x gate / 256, bit by bit, 1 at least, 0 when the
                    gate is 0; the note is keyed on again (0EBE, 0E7B) only when the gate left before it was not 0
                    (4330: E4 00 plays its notes legato). The driver keys a note off (4484-44A2) on the passes where
                    the count's low 4 bits are the channel's number, when what is left of it is no more than its
                    gate left.
                    In drum mode (E0 not 0, 45F5) the pitch is no pitch: N picks a routine of the mode's set (FM:
                    494C + 32 x mode, PCM: instrument_routines 4E4E + 32 x mode), which loads its own patch and keys
                    the channel on (a K053260 sample, 4FD1...)
      E5 b1 .. bn   a held note (4737): b1 a note (its length and pitch), then lengths two a byte, the high nibble
                    first, up to a byte whose high nibble is F (none of its) or whose low one is F (the high one
                    counts); the lengths add up in the accumulator
      E0 mode (46A6), E1 tempo (46D2), E2 instrument (46DB: an FM patch of music_fm_patches, or a PCM patch of
      music_pcm_patches and its transposition; loaded at once if the music has the channel), E3 volume (471E: an
      attenuation, 0.75 dB a step on the FM's carriers; the K053260's volume is 127 less it and the patch's level),
      E4 gate (472E), E6 detune (4767: 1/64 semitones), EE LFO ramp (47D3: every that many passes the channel's PMS
      and AMS one up, to 7), EF pan (47DC: YM2151 register 20's L (bit 0) and R (bit 1); the K053260's pan 1-7): a
      byte each; E7 (4770) the pitch envelope: a period and 4 counts and steps; ED (47B8) the YM2151's LFO: LFRQ,
      PMD, AMD, waveform; F0 address (47EC): goes on there; F1 count, address (47FC): goes on the count less one
      times it is read, then there; F2/F4 count (4818, 4842): a loop, F3/F5 its end (back count less one times); F6
      count, address (486C): plays the part there count times (F7, 488E, goes back); FE priority (48B6); FF the end
      (48C9: the channel stops). E8-EC and F8-FD jump to 0000 (the reset): no track has one.
  Each channel keeps its own tempo: the songs set it on every channel at the same point, but a few give a channel
  one of its own (96's K053260 channels 1 and 3, 98's 2).

The files (write): Standard MIDI Files, format 1, 24 ticks a quarter note: a file's tick is 32 of the
accumulator's units (note_lengths: 96 a whole note, 24 a quarter, 6 a sixteenth, 36 a dotted quarter, 16 a triplet
quarter, 1 the shortest rest). A channel's events are at its own units, so a note is where its length puts it, and
not where the accumulator's carry happens to read it (up to a channel's turn, 8 passes, later).
The tempo: a channel reads tempo units every 8 passes, so a quarter note takes 768 / tempo x 8 passes. A pass is
timer B's 7168 clocks when its work ends before the timer runs out; when it does not, the main loop starts the timer
again late (ymfm starts it short by the low 4 bits of its sample count, so it runs out on a grid of 1024 clocks: an
overrun of up to some 550 clocks costs nothing, a longer one the next step of the grid). The writer counts each
pass's work (PASS_WORK: what its channels read and play, fitted to kref's own) and gives each stretch of a tempo the
time its passes take (Player.pass_time). The model against kref (MAME's Z80 and ymfm): the loops of 16 songs (82
84 85 86 8C 8E 8F 90 93 9B 9D A2 A7 A8 AC AF), timed in the WAV kref writes as the music check plays each (the
period of its sound's envelope, to 10 ms), come within 0.3% of kref's (root mean square; 0.8% at most, 9D's),
and three the fit did not see (81, 99, A4) within 0.15%; timer B alone would make them 1.5% to 5.6% fast. The
tempo of a stretch is its average: a pass that overruns is spread over the stretch, and a note starts on its
channel's turn, up to 8 passes (16 ms) after its tick. Tracks:
  1     the song: its name (FF 03), the 'N' event, the tempo events (FF 51) where the tempo most of the channels
        still playing have changes (a channel with a tempo of its own plays at theirs in a player), the 'U' events
  2-13  the driver's channels: YM2151 1-8, K053260 1-4, each its name (FF 03), the 'S' event, then what the channel
        reads, as the driver plays it
The driver's events that MIDI has none for are sequencer-specific meta events, FF 7F LEN 7D TAG DATA (7D: the
non-commercial manufacturer id; LEN a variable-length quantity):
  'N' (4E)  the song header's place (a name of the assets' layout.txt, ASCII), a 0 byte, then the commands that
            play it (80-AF)
  'S' (53)  the place the header points at for this channel: a name of the layout, as ASCII text, maybe +0xNN
  'C' (43)  a command, its bytes as the driver reads them, an address last as a place's name (ASCII text): the
            octave (01-0F) and E0-FF but E5
  'R' (52)  a rest: no data, its length the time to the channel's next step
  'H' (48)  a held note: the bytes after E5 (the Note On at the same tick plays it, and gives b1's pitch)
  'Z' (5A)  where the file stops showing the channel: no data; the step before it ends here
  'U' (55)  bytes no file shows (no track reaches them, or only after the file's end): a place's name, a 0
            byte, the bytes from there
A note is a Note On and a Note Off; its length is the time to the channel's next step (note, rest, held note,
'Z', or the command FF), its key 11 + N + 12 x octave (the pitch tables' index: N 1 at octave 4 is middle C, 60;
octave bytes over 10 wrap in the driver's byte as they do there), a PCM note's plus its instrument's transposition,
a drum's DRUM_BASE + N. Within a tick a channel's commands come before its step. The channels play loops and parts
as the driver does: a loop's turns one after the other, a part where it is called, a jump where it goes; every
channel goes on to the pass where the last of them first comes back to a state it had (or ends, or its tempo is 0),
or CAP_PASSES passes; after that its next commands, then a 'Z'. A Note Off ends a note where the driver keys it off:
its length less its gate left (the gate's part, as 4916 takes it from the length), to the nearest tick and one at
least; a drum's or a legato one's (E4 00) at its length. The writer's own, which the way back skips:
the tempo events, the names, the velocity (the attenuation the note plays with), the MIDI channel (the YM2151's
channels on 1-8, the K053260's on 11-14, every drum on 10: General MIDI's percussion), the program changes (FM_BASS
or PCM_BASS for an instrument whose notes are mostly below key 48, else FM_LEAD or PCM_LEAD), the pan (CC 10 at
each EF; the board wires only the YM2151's left output) and the detune (a pitch bend at each E6 on an FM channel).

The way back (read): every driver's track, in the order of the file's tracks with an 'S' event, gives its steps:
the events at a tick (commands, then a step), the Note Offs aside. Each channel keeps the driver's record (octave,
mode, instrument, loops, part) and its place, from 'S': a command's bytes go there (an address as the place its
name says, in the bank's window) and the place moves on as the driver's would (a jump, a loop's end, a part, its
return); a note's byte is its length's code (note_lengths: every length has one code) and the pitch the key gives
from the channel's octave (and instrument); a rest's, the length's code. The header's 24 bytes are the 'S' places'
addresses. A byte that comes back twice (a loop's later turns, a part played again, the same place in two files)
has to be the same. What does not come back says what failed: a file that is no Standard MIDI File, a tick that is
no whole driver's tick, a length no code has, a key no pitch nibble gives, a Note Off that is not where the gate
puts it, a byte two places give differently, a place no name has, a music byte no file gives.
"""
import re
from bisect import bisect_right
from collections import Counter, defaultdict

import sound_data_walk

TICKS_A_QUARTER = 24            # the files' division: 32 of the accumulator's units a file's tick
UNIT = 32
SOUND_CLOCK = 3579545           # the Z80's and the YM2151's clock (Hz)
TIMER_B_SAMPLES = 16 * (256 - 0xF9)     # 0C56's timer B (register 12 = F9): samples of 64 clocks
CHANNEL_PASSES = 8              # a channel reads its track one pass in 8 (4289: the count's low 3 bits)
POLL_CYCLES = 32                # the main loop's wait for the flag (0B3D-0B42)
RESTART_CYCLES = 430            # from the flag to timer B's start (0C56's three register writes)
# a pass's work, Z80 cycles: its base (the 12 channels' handlers, the loop), each channel whose turn it is (4289's
# add), each byte read_track reads, and what its steps and commands do to the chips (the paths' cycles as MAME's Z80
# counts them, with the YM2151's busy flag: a note keyed on again writes its pitch, key off, PMS/AMS and key on; a
# patch 26 registers), all times 1.143 and the base fitted to the loops of 16 songs as kref plays them (see the
# docstring: within 0.3% of kref's, root mean square, 0.8% at most)
PASS_WORK = {"base": 4070, "turn": 135, "byte": 154, "fm_note": 3540, "fm_legato": 2290, "pcm_note": 2630,
             "drum": 1710, "fm_rest": 510, "pcm_rest": 340, "fm_patch": 5140, "pcm_patch": 690, "fm_volume": 1030,
             "pcm_volume": 230, "fm_pan": 340, "lfo": 690}
CAP_PASSES = 90000              # a file shows at most some 3 minutes of its song (CAP_PASSES passes)
SONG_TRACKS = 12                # a song's channels: YM2151 1-8, K053260 1-4
FM_CHANNELS = 8
FIRST_SONG = 0x80               # the command of song_headers' first entry
TAG = 0x7D                      # the non-commercial manufacturer id of the meta events FF 7F
FM_BASS, FM_LEAD, PCM_BASS, PCM_LEAD = 38, 62, 33, 61   # General MIDI: synth bass 1, synth brass 1, electric bass,
#                                                         brass section
DRUM_CHANNEL = 9                # General MIDI's percussion channel (10 to people)
DRUM_BASE = 34                  # a drum routine N's key: 35 on (General MIDI's percussion keys start there)
MIDI_CHANNELS = (0, 1, 2, 3, 4, 5, 6, 7, 10, 11, 12, 13)
CHANNEL_NAMES = tuple(f"YM2151 channel {n}" for n in range(1, 9)) + tuple(f"K053260 channel {n}" for n in range(1, 5))
FM_PAN = {1: 0, 2: 127, 3: 64}  # EF on an FM channel: L, R, both
PCM_PAN = (64, 0, 34, 49, 64, 78, 94, 127)      # the K053260's pans 1-7 (MAME's pan_mul: 0 to 90 degrees)

# a command's bytes (E5 aside), and the place of the address the ones that carry it have (always last)
COMMAND_LENGTHS = dict(sound_data_walk.FIXED)
COMMAND_LENGTHS.update({0xF0: 3, 0xF1: 4, 0xF6: 4, 0xF7: 1, 0xFF: 1})
ADDRESS_AT = {0xF0: 1, 0xF1: 2, 0xF6: 2}

# what the game plays each song for, its file's name: the scenarios of tests/controls played in kref, with the
# 053248's sound queue (4900-493F: the commands 8680 queues, 9054 sends) and the step (4803) read every 10 frames,
# and the picture when a song starts (90 by the routine that queues it); a song nothing starts is song_XX. C0-EF fade
# the music out first, then play 80-AF (0458, 0BB5)
SONGS = {
    0x80: ("attract", "the attract: as it starts (frame 620 of every scenario), and when it comes back after a game"),
    0x91: ("game_start", "a game's start: as the first story starts (step 1), and the second round's"),
    0x81: ("stage_1", "stage 1 (step 2), from its start and after a continue"),
    0x8F: ("stage_1_boss", "stage 1's boss (command CF)"),
    0x90: ("name_entry", "the high score's name entry: name_entry_start queues 9000 (no scenario gets a high score)"),
    0x98: ("boss_defeated", "a boss falls: after the bosses of stages 1 and 3 to 8"),
    0x96: ("area_clear", "the family walks on: after 98 at a stage's end, and as steps 7 and 15 start"),
    0x95: ("after_stages_1_and_5", "after stages 1 and 5 (after 96): a scene with a speech balloon"),
    0x87: ("bonus_start", "a bonus stage's start (steps 3 and 12)"),
    0x89: ("bonus_1", "bonus stage 1 (step 3)"),
    0x8A: ("bonus_2", "bonus stage 2 (step 12)"),
    0x88: ("bonus_end", "a bonus stage's end (steps 3 and 12)"),
    0xAD: ("after_bonus_1", "after bonus stage 1, before stage 2"),
    0xA0: ("after_bonus_2", "after bonus stage 2, before stage 7"),
    0x82: ("stage_2", "stage 2 (step 4)"),
    0x8D: ("stage_2_boss", "stage 2's boss (command CD)"),
    0x9E: ("after_stage_2", "after stage 2's boss, before step 6"),
    0x84: ("stage_3", "stage 3's first part (step 6)"),
    0x94: ("stage_3_part_1_end", "the end of stage 3's first part, the graveyard, before step 7"),
    0xA7: ("stage_3_part_2", "stage 3's second part (step 7)"),
    0xA8: ("stage_3_boss_and_stage_8", "stage 3's boss (command E8, in step 7) and stage 8's start (step 15)"),
    0x85: ("stage_4", "stage 4 (step 8)"),
    0x8C: ("stage_4_boss", "stage 4's boss (command CC)"),
    0x97: ("after_stage_4", "after stage 4 (after 98 and 96), before step 9"),
    0x86: ("stage_5", "stage 5 (step 9)"),
    0x8E: ("stage_5_boss", "stage 5's boss"),
    0x9A: ("after_stage_5", "after stage 5 (after 95), before step 11"),
    0xA4: ("stage_6", "stage 6 (step 11)"),
    0xA5: ("stage_6_boss", "stage 6's boss"),
    0xAB: ("after_stage_6", "after stage 6 (after 98 and 96), before bonus stage 2"),
    0x93: ("stage_7", "stage 7 (step 13), and back after 9B"),
    0x9B: ("stage_7_aliens", "stage 7's set with the aliens"),
    0x9D: ("stage_7_japan", "stage 7's Japanese set (command DD)"),
    0x9C: ("stage_7_boss", "stage 7's boss (command DC)"),
    0x83: ("after_stage_7", "after stage 7 (after 98 and 96), before step 15"),
    0x99: ("stage_8_part_2", "stage 8 (step 15), its second part"),
    0xAA: ("stage_8_boss_1", "stage 8's first boss, a robot"),
    0xAC: ("final_boss", "stage 8's last boss, Mr. Burns' robot"),
    0x8B: ("ending", "the ending, after the last boss: the family together"),
    0xA1: ("continue", "CONTINUE, when the last player's last life is lost"),
    0x92: ("game_over", "GAME OVER, when the continue's count runs out"),
}


class MusicError(Exception):
    """What does not come back from the files, or does not go into them"""


# ---- the driver ----

def z80_address(place):
    """The Z80's address of a region's place (a bank's in the window 8000-BFFF)"""
    if place < sound_data_walk.WINDOW:
        return place
    return sound_data_walk.WINDOW + (place - sound_data_walk.BANK_START) % sound_data_walk.BANK_SIZE


def held_length(data):
    """The bytes of a held note after E5, from 'data': b1, then up to the first byte with a nibble F"""
    at = 1
    while at < len(data) and data[at] >> 4 != 0xF and data[at] & 0x0F != 0x0F:
        at += 1
    return min(at + 1, len(data))


def held_units(data, lengths):
    """The units of a held note's bytes (after E5), as 4737 adds them up; None when a code is none of
    note_lengths'"""
    codes = [data[0] >> 4]
    for byte in data[1:]:
        if byte >> 4 == 0xF:
            break
        codes.append(byte >> 4)
        if byte & 0x0F == 0x0F:
            break
        codes.append(byte & 0x0F)
    parts = [lengths[code] if code < len(lengths) else None for code in codes]
    return None if None in parts else sum(parts)


def gate_units(length, gate):
    """4916: the units of a note's 'length' its gate takes off its end, bit by bit (1 at least; 0 for gate 0)"""
    if not gate:
        return 0
    found, part = 0, length & 0xFFFF
    for bit in range(7, -1, -1):
        part >>= 1
        if gate >> bit & 1:
            found += part
    return found & 0xFFFF or 1


def code_of(units, lengths):
    """The length's code of a note or a rest of 'units' (None if none has it)"""
    return lengths.index(units) if units in lengths else None


class Channel:
    """A channel's record, as 41AE leaves it at 'start' (a region's place)"""
    FIELDS = ("octave", "mode", "gate", "detune", "volume", "pan", "instrument", "lfo_ramp", "priority", "jump_count",
              "loop_count", "loop_start", "loop_2_count", "loop_2_start", "repeat_count", "repeat_return",
              "repeat_part")

    def __init__(self, number, start, bank):
        self.number = number                # 0-7: YM2151 1-8; 8-11: K053260 1-4
        self.pcm = number >= FM_CHANNELS
        self.place = start
        self.bank = bank
        for name in self.FIELDS:
            setattr(self, name, 0)
        self.tempo = 1
        self.envelope = bytes(9)
        self.transposition = 0              # a PCM instrument's, in the pitch table's bytes
        self.accumulator = 0xFFFF
        self.gate_left = 1

    def state(self):
        """What the channel's future depends on, but its time: a loop's start, a part's return only while they
        are in use"""
        return (self.place, self.octave, self.mode, self.tempo, self.gate, self.detune, self.volume, self.pan,
                self.instrument, self.lfo_ramp, self.envelope, self.priority, self.jump_count, self.gate_left == 0,
                self.loop_count, self.loop_2_count, self.repeat_count,
                self.loop_start if self.loop_count else None, self.loop_2_start if self.loop_2_count else None,
                (self.repeat_return, self.repeat_part) if self.repeat_count else None)

    def target(self, address):
        return sound_data_walk.place(self.bank, address)

    def execute(self, at, data, target, transpositions):
        """The command 'data' (its bytes) at 'at' (a place), 'target' the place of the address it carries: what it
        does to the record; the place the track goes on at (None: it ends)"""
        command = data[0]
        if command < 0x10:
            self.octave = command
            return at + 1
        argument = data[1] if len(data) > 1 else 0
        if command == 0xE0:
            self.mode = argument
        elif command == 0xE1:
            self.tempo = argument
        elif command == 0xE2:
            self.instrument = argument
            if self.pcm:
                self.transposition = transpositions[argument] if argument < len(transpositions) else 0
        elif command == 0xE3:
            self.volume = argument
        elif command == 0xE4:
            self.gate = argument
        elif command == 0xE6:
            self.detune = argument
        elif command == 0xE7:
            self.envelope = bytes(data[1:])
        elif command == 0xEE:
            self.lfo_ramp = argument
        elif command == 0xEF:
            self.pan = argument
        elif command == 0xFE:
            self.priority = argument
        elif command == 0xF0:
            return target
        elif command == 0xF1:
            self.jump_count = (self.jump_count + 1) & 0xFF
            if self.jump_count == argument:
                self.jump_count = 0
                return target
            return at + 4
        elif command in (0xF2, 0xF4):
            second = "_2" if command == 0xF4 else ""
            setattr(self, f"loop{second}_count", argument)
            setattr(self, f"loop{second}_start", at + 2)
            return at + 2
        elif command in (0xF3, 0xF5):
            second = "_2" if command == 0xF5 else ""
            count = (getattr(self, f"loop{second}_count") - 1) & 0xFF
            setattr(self, f"loop{second}_count", count)
            return at + 1 if count == 0 else getattr(self, f"loop{second}_start")
        elif command == 0xF6:
            self.repeat_count = argument
            self.repeat_return = at + 2         # the F6's address, which F7 reads again
            self.repeat_part = target
            return target
        elif command == 0xF7:
            self.repeat_count = (self.repeat_count - 1) & 0xFF
            return self.repeat_return + 2 if self.repeat_count == 0 else self.repeat_part
        elif command == 0xFF:
            return None
        elif command not in COMMAND_LENGTHS:
            raise MusicError(f"the command {command:02X} at {at:05X} jumps to 0000")
        return at + len(data)

    # -- the keys of the files' notes --

    def drums(self):
        return self.mode != 0

    def offset(self, nibble):
        """The note's bytes into the pitch table (42FE-4316: a byte), and a PCM instrument's transposition"""
        return ((2 * nibble + (24 * self.octave & 0xFF)) & 0xFF) + (self.transposition if self.pcm else 0)

    def key(self, nibble):
        """The key of the note whose pitch nibble is 'nibble' (None: no key has it)"""
        if self.drums():
            return DRUM_BASE + nibble if 0 < nibble <= 15 else None
        key = 11 + self.offset(nibble) // 2
        return key if 0 <= key <= 127 else None

    def nibble(self, key):
        """The pitch nibble that gives 'key' (None: none does)"""
        for nibble in range(16):
            if self.key(nibble) == key:
                return nibble
        return None

    def channel(self):
        """The MIDI channel of its notes"""
        return DRUM_CHANNEL if self.drums() else MIDI_CHANNELS[self.number]

    def released(self, units):
        """The ticks after a note of 'units' starts where the driver keys it off"""
        if self.drums() or not self.gate:
            return units // UNIT
        return max(1, (units - gate_units(units, self.gate) + UNIT // 2) // UNIT)


# ---- the songs, played pass by pass ----

class Player:
    """A song's 12 tracks from 'starts' (places) in 'bank', played as the driver does, a pass at a time: each
    channel's reads (the commands up to a step: [units, [(at, bytes, target)], step, length units, pass]; a step
    ('note', at, byte, nibble), ('rest', at, byte), ('held', at, bytes, nibble), ('end', at) or None)"""

    def __init__(self, image, starts, bank, lengths, transpositions):
        self.image = image
        self.lengths = lengths
        self.transpositions = transpositions
        self.channels = [Channel(number, start, bank) for number, start in enumerate(starts)]
        for channel in self.channels:
            channel.reads, channel.seen = [], set()
            channel.playing, channel.units, channel.done = True, 0, None
            channel.owner = False           # +41's bit 7: the music has keyed the channel (its first note)
        self.passes = 0
        self.clock = 3 * 1024 + 300     # the Z80's cycles when this pass starts
        self.clocks = []                # the clock at each pass's start
        self.work = 0

    def u16(self, at):
        return self.image[at] | self.image[at + 1] << 8

    def command_bytes(self, channel, at):
        command = self.image[at]
        if command < 0xE0:
            return bytes([command]), None
        if command not in COMMAND_LENGTHS:
            raise MusicError(f"{CHANNEL_NAMES[channel.number]}: the command {command:02X} at {at:05X} jumps to 0000")
        length = COMMAND_LENGTHS[command]
        target = channel.target(self.u16(at + ADDRESS_AT[command])) if command in ADDRESS_AT else None
        return bytes(self.image[at:at + length]), target

    def cost(self, kind, count=1):
        """A pass's work: 'count' times what 'kind' costs (PASS_WORK)"""
        self.work += PASS_WORK[kind] * count

    def read(self, channel):
        """read_track (42AE): the channel's commands up to its next step, as a read; and its work in the pass"""
        state = channel.state()
        if channel.done is None and state in channel.seen:
            channel.done = self.passes
        channel.seen.add(state)
        read = [channel.units, [], None, 0, self.passes]
        channel.reads.append(read)
        kind = "pcm_" if channel.pcm else "fm_"
        while True:
            at = channel.place
            byte = self.image[at]
            if (byte < 0x10 and byte) or (byte >= 0xE0 and byte != 0xE5):
                data, target = self.command_bytes(channel, at)
                read[1].append((at, data, target))
                self.cost("byte", len(data))
                if channel.owner and data[0] in (0xE2, 0xE3):
                    self.cost(kind + ("patch" if data[0] == 0xE2 else "volume"))
                elif channel.owner and data[0] == 0xEF and not channel.pcm:
                    self.cost("fm_pan")
                elif data[0] == 0xED:
                    self.cost("lfo")
                place = channel.execute(at, data, target, self.transpositions)
                if place is None:
                    read[2] = ("end", at)
                    channel.playing = False
                    if channel.done is None:
                        channel.done = self.passes
                    return
                channel.place = place
                continue
            self.cost("byte")
            if byte == 0xE5:
                data = bytes(self.image[at + 1:at + 1 + held_length(self.image[at + 1:at + 40])])
                units = held_units(data, self.lengths)
                if units is None:
                    raise MusicError(f"{CHANNEL_NAMES[channel.number]}: the held note at {at:05X} has a length no "
                                     f"code has")
                self.cost("byte", len(data))
                read[2] = ("held", at, bytes([0xE5]) + data, data[0] & 0x0F)
                channel.place = at + 1 + len(data)
            elif byte & 0x0F == 0:
                units = self.lengths[byte >> 4]
                read[2] = ("rest", at, bytes([byte]))
                channel.place = at + 1
            else:
                units = self.lengths[byte >> 4] if byte >> 4 < len(self.lengths) else None
                if units is None:
                    raise MusicError(f"{CHANNEL_NAMES[channel.number]}: the note {byte:02X} at {at:05X} has a length "
                                     f"no code has")
                read[2] = ("note", at, bytes([byte]), byte & 0x0F)
                channel.place = at + 1
            channel.units += units
            read[3] = units
            total = channel.accumulator + 0x10000 - units
            carry = total > 0xFFFF
            channel.accumulator = total & 0xFFFF
            if read[2][0] == "rest":
                if carry:
                    # a rest shorter than what is left: the next step at once, in the same read's pass
                    read = [channel.units, [], None, 0, self.passes]
                    channel.reads.append(read)
                    continue
                channel.gate_left = 1
                self.cost(kind + "rest")
                return
            if channel.drums():
                channel.gate_left = 1
                self.cost("drum")
            else:
                if not channel.owner:
                    # 42DA: the patch, the volume and the pan of a channel the music did not have
                    self.cost(kind + "patch")
                    self.cost(kind + "volume")
                    if not channel.pcm:
                        self.cost("fm_pan")
                rekey = channel.gate_left != 0
                channel.gate_left = gate_units((0x10000 - channel.accumulator) & 0xFFFF, channel.gate)
                self.cost("pcm_note" if channel.pcm else "fm_note" if rekey else "fm_legato")
            channel.owner = True
            return

    def pass_time(self):
        """The pass's end and the next one's start: timer B runs out 7 x 16 samples after its start, short by the
        low 4 bits of the sample count (ymfm: its divide by 16 runs free), which the main loop finds after the
        pass's work, at a turn of its wait; then it starts timer B again"""
        samples = -(-self.clock // 64)
        expiry = self.clock + (TIMER_B_SAMPLES - (samples & 15)) * 64
        end = self.clock + PASS_WORK["base"] + self.work
        found = end if end >= expiry else end + POLL_CYCLES * -(-(expiry - end) // POLL_CYCLES)
        self.clock = found + RESTART_CYCLES
        self.work = 0

    def step(self):
        """A pass of the main loop: the channels whose turn it is read when their accumulator carries"""
        self.clocks.append(self.clock)
        for channel in self.channels:
            if not channel.playing or self.passes % CHANNEL_PASSES != channel.number % CHANNEL_PASSES:
                continue
            if channel.tempo == 0:
                channel.playing = False
                if channel.done is None:
                    channel.done = self.passes
                continue
            total = channel.accumulator + channel.tempo
            channel.accumulator = total & 0xFFFF
            self.cost("turn")
            if total > 0xFFFF:
                self.read(channel)
        self.pass_time()
        self.passes += 1

    def run(self):
        """Plays until every channel has come back to a state it had or ended (or CAP_PASSES passes), and then
        until each has read past that pass: the pass where the file stops showing the song"""
        end = None
        while True:
            self.step()
            if end is None and (all(channel.done is not None for channel in self.channels)
                                or self.passes >= CAP_PASSES):
                end = max(channel.done if channel.done is not None else self.passes for channel in self.channels)
            if end is not None and all(not channel.playing or channel.reads[-1][4] >= end
                                       for channel in self.channels):
                self.clocks.append(self.clock)
                return end

    def shown(self, end):
        """Each channel's reads the file shows: those before pass 'end', then the first one at or after it, its
        commands only (its step a cut), unless it ends the track; the last read of a channel the tempo stopped, and
        then a cut"""
        tracks = []
        for channel in self.channels:
            reads = []
            for units, items, step, length, pass_ in channel.reads:
                if pass_ < end:
                    reads.append((units, items, step, length, pass_))
                    continue
                if step is not None and step[0] == "end":
                    reads.append((units, items, step, length, pass_))
                else:
                    reads.append((units, items, ("cut",), 0, pass_))
                break
            else:
                if reads and reads[-1][2][0] != "end":
                    last = reads[-1]
                    reads.append((last[0] + last[3], [], ("cut",), 0, end))
            tracks.append(reads)
        return tracks

    def tempo_events(self, tracks):
        """[(tick, microseconds a quarter note)] where the song's tempo changes: at each tick the tempo most of the
        channels that still play have (the lowest channel's on a tie); a stretch of one tempo at the time the passes
        of its first channel that plays it through take (between its reads, in proportion to its units)"""
        segments = []                   # each channel's [(first units, tempo)] and the units it plays to
        for reads in tracks:
            changes = [(0, 1)]
            for units, items, step, length, pass_ in reads:
                for at, data, target in items:
                    if data[0] == 0xE1:
                        if changes[-1][0] == units:
                            changes.pop()
                        changes.append((units, data[1]))
            segments.append((changes, reads[-1][0] if reads else 0))

        def tempo_of(number, units):
            return next(tempo for first, tempo in reversed(segments[number][0]) if first <= units)

        points = sorted({units for changes, end in segments for units, _ in changes}
                        | {end for changes, end in segments})
        stretches = []                  # [first units, last units, tempo]
        for first, last in zip(points, points[1:]):
            tempos = {number: tempo_of(number, first) for number, (_, end) in enumerate(segments) if end > first}
            if not tempos:
                continue
            counts = Counter(tempos.values())
            tempo = tempos[min(number for number, tempo in tempos.items() if counts[tempo] == max(counts.values()))]
            if stretches and stretches[-1][2] == tempo and stretches[-1][1] == first:
                stretches[-1][1] = last
            else:
                stretches.append([first, last, tempo])
        out = []
        for first, last, tempo in stretches:
            if not tempo:
                continue
            # the channel that plays the stretch at its tempo the furthest (the lowest of those that play it through)
            playing = [number for number, (_, end) in enumerate(segments)
                       if end > first and tempo_of(number, first) == tempo]
            number = min(playing, key=lambda number: (-min(segments[number][1], last), number))
            stop = min(segments[number][1], last)
            for change, value in segments[number][0]:
                if first < change < stop and value != tempo:
                    stop = change
            cycles = (self.clock_at(tracks[number], stop, tempo) - self.clock_at(tracks[number], first, tempo)) \
                / (stop - first) * UNIT
            out.append((first // UNIT, round(cycles * TICKS_A_QUARTER * 1_000_000 / SOUND_CLOCK)))
        return out

    def clock_at(self, reads, units, tempo):
        """The Z80's cycles when a channel's reads are at 'units', between the passes of its reads (past them, at
        'tempo' with timer B's passes)"""
        points = [(read[0], self.clocks[read[4]]) for read in reads if read[4] < len(self.clocks)]
        for (units_0, clock_0), (units_1, clock_1) in zip(points, points[1:]):
            if units_0 <= units <= units_1 and units_1 > units_0:
                return clock_0 + (clock_1 - clock_0) * (units - units_0) / (units_1 - units_0)
        units_0, clock_0 = points[-1] if units > points[-1][0] else points[0]
        return clock_0 + (units - units_0) / tempo * CHANNEL_PASSES * TIMER_B_SAMPLES * 64


# ---- the files ----

def vlq(value):
    """A variable-length quantity"""
    out = [value & 0x7F]
    value >>= 7
    while value:
        out.append(0x80 | (value & 0x7F))
        value >>= 7
    return bytes(reversed(out))


def meta(kind, data):
    return bytes([0xFF, kind]) + vlq(len(data)) + data


def driver_event(tag, data=b""):
    return meta(0x7F, bytes([TAG, ord(tag)]) + data)


class Track:
    """A track's events, in order at a tick, Note Offs first"""

    def __init__(self):
        self.events = []

    def add(self, tick, data, note_off=False):
        self.events.append((tick, 0 if note_off else 1, len(self.events), data))

    def chunk(self):
        out = bytearray()
        now = 0
        for tick, _, _, data in sorted(self.events):
            out += vlq(tick - now) + data
            now = tick
        out += b"\x00\xFF\x2F\x00"
        return b"MTrk" + len(out).to_bytes(4, "big") + bytes(out)


class Names:
    """The places' names: 'pieces' {first: (stop, name)}"""

    def __init__(self, pieces):
        self.starts = sorted(pieces)
        self.pieces = pieces
        self.addresses = {name: first for first, (_, name) in pieces.items()}

    def name(self, place):
        index = bisect_right(self.starts, place) - 1
        if index >= 0:
            first = self.starts[index]
            stop, name = self.pieces[first]
            if first <= place < stop:
                return name if place == first else f"{name}+0x{place - first:X}"
        raise MusicError(f"{place:05X} is in no piece of the sound region")

    def place(self, text, where):
        base, plus, offset = text.partition("+")
        if base not in self.addresses or (plus and not re.fullmatch(r"0x[0-9A-Fa-f]+", offset)):
            raise MusicError(f"{where}: no place is named {text}")
        return self.addresses[base] + (int(offset, 16) if plus else 0)


def replay(tracks, starts, bank, transpositions, levels):
    """The notes of the shown reads ('tracks', Player.shown): {(track, read): (key, velocity, MIDI channel, ticks to
    its Note Off)}, each instrument's keys, and the channels' pans and bends {(track, read): [(kind, value)]}"""
    notes, played, controls = {}, defaultdict(list), defaultdict(list)
    for number, reads in enumerate(tracks):
        channel = Channel(number, starts[number], bank)
        for index, (units, items, step, length, pass_) in enumerate(reads):
            for at, data, target in items:
                channel.execute(at, data, target, transpositions)
                if data[0] == 0xEF:
                    pan = FM_PAN.get(data[1] & 3) if not channel.pcm else PCM_PAN[data[1] & 7]
                    if pan is not None:
                        controls[(number, index)].append(("pan", pan))
                elif data[0] == 0xE6 and not channel.pcm:
                    controls[(number, index)].append(("bend", min(0x3FFF, 0x2000 + data[1] * 0x2000 // 128)))
            if step[0] not in ("note", "held"):
                continue
            nibble = step[3]
            key = channel.key(nibble)
            if key is None:
                raise MusicError(f"{CHANNEL_NAMES[number]}: the note at {step[1]:05X} has no key")
            if channel.pcm:
                level = levels.get(channel.instrument, 0)
                velocity = 127 - min(127, channel.volume + level) if not channel.drums() else 100
            else:
                velocity = round(127 * 10 ** (-0.75 * min(channel.volume, 0x7F) / 40)) if not channel.drums() else 100
            if not channel.drums():
                played[(channel.pcm, channel.instrument)].append(key)
            notes[(number, index)] = (key, max(1, min(127, velocity)), channel.channel(), channel.released(length),
                                      None if channel.drums() else (channel.pcm, channel.instrument))
    return notes, played, controls


def song_file(name, numbers, header, starts, tracks, tempos, notes, programs, controls, names, unshown):
    """A song's Standard MIDI File"""
    songs = ", ".join(f"{FIRST_SONG + number:02X}" for number in numbers)
    first = Track()
    first.add(0, meta(0x03, f"The Simpsons {name}: the song command {songs}".encode("ascii")))
    first.add(0, driver_event("N", names.name(header).encode("ascii") + b"\x00"
                              + bytes(FIRST_SONG + number for number in numbers)))
    for tick, quarter in tempos:
        first.add(tick, meta(0x51, min(quarter, 0xFFFFFF).to_bytes(3, "big")))
    for place, data in unshown:
        first.add(0, driver_event("U", place.encode("ascii") + b"\x00" + data))
    chunks = [first.chunk()]
    for number, reads in enumerate(tracks):
        track = Track()
        midi = MIDI_CHANNELS[number]
        track.add(0, meta(0x03, CHANNEL_NAMES[number].encode("ascii")))
        track.add(0, driver_event("S", names.name(starts[number]).encode("ascii")))
        program = None
        for index, (units, items, step, length, pass_) in enumerate(reads):
            tick = units // UNIT
            for at, data, target in items:
                if data[0] in ADDRESS_AT:
                    data = data[:ADDRESS_AT[data[0]]] + names.name(target).encode("ascii")
                track.add(tick, driver_event("C", data))
            for kind, value in controls.get((number, index), []):
                track.add(tick, bytes([0xB0 | midi, 10, value]) if kind == "pan"
                          else bytes([0xE0 | midi, value & 0x7F, value >> 7]))
            kind = step[0]
            if kind == "rest":
                track.add(tick, driver_event("R"))
            elif kind == "cut":
                track.add(tick, driver_event("Z"))
            elif kind in ("note", "held"):
                if kind == "held":
                    track.add(tick, driver_event("H", step[2][1:]))
                key, velocity, channel, released, instrument = notes[(number, index)]
                if instrument is not None and programs.get(instrument) != program:
                    program = programs[instrument]
                    track.add(tick, bytes([0xC0 | channel, program]))
                track.add(tick, bytes([0x90 | channel, key, velocity]))
                track.add(tick + released, bytes([0x80 | channel, key, 0]), note_off=True)
        chunks.append(track.chunk())
    header_chunk = b"MThd" + (6).to_bytes(4, "big") + (1).to_bytes(2, "big") + len(chunks).to_bytes(2, "big") \
        + TICKS_A_QUARTER.to_bytes(2, "big")
    return header_chunk + b"".join(chunks)


def tables(image, by_name):
    """note_lengths' units, music_pcm_transpositions (in the pitch table's bytes) and each PCM instrument's level
    (its patch's second byte) from the sound program 'image'"""
    first, stop = by_name["note_lengths"]
    lengths = [0x10000 - (image[at] | image[at + 1] << 8) for at in range(first, stop, 2)]
    first, stop = by_name["music_pcm_transpositions"]
    transpositions = []
    for at in range(first, stop, 2):
        word = image[at] | image[at + 1] << 8
        transpositions.append(word - 0x10000 if word & 0x8000 else word)
    first, stop = by_name["music_pcm_patches"]
    levels = {}
    for index, at in enumerate(range(first, stop, 2)):
        patch = image[at] | image[at + 1] << 8
        if patch + 2 < len(image):
            levels[index] = image[patch + 1]
    return lengths, transpositions, levels


def song_list(image, by_name):
    """[(header place, bank, [song numbers])]: song_headers and song_banks, a header once"""
    headers, stop = by_name["song_headers"]
    banks = by_name["song_banks"][0]
    found = {}
    for number in range((stop - headers) // 2):
        bank = image[banks + number] & 7
        address = image[headers + 2 * number] | image[headers + 2 * number + 1] << 8
        found.setdefault((sound_data_walk.place(bank, address), bank), []).append(number)
    return [(header, bank, numbers) for (header, bank), numbers in found.items()]


def play(image, header, bank, lengths, transpositions):
    """A song's Player, played up to where its file stops, and that pass"""
    starts = [sound_data_walk.place(bank, image[header + 2 * track] | image[header + 2 * track + 1] << 8)
              for track in range(SONG_TRACKS)]
    player = Player(image, starts, bank, lengths, transpositions)
    return player, player.run(), starts


def write(image, pieces, folder):
    """The songs of the sound region 'image' as MIDI files into 'folder', and its music.txt; 'pieces' [(name, kind,
    first, stop)] are sound_data_assets' (the music's kinds 'music track' and 'song header'). Returns the files'
    count"""
    by_name = {name: (first, stop) for name, _, first, stop in pieces}
    names = Names({first: (stop, name) for name, _, first, stop in pieces})
    lengths, transpositions, levels = tables(image, by_name)
    songs = []
    for header, bank, numbers in song_list(image, by_name):
        named = [FIRST_SONG + number for number in numbers if FIRST_SONG + number in SONGS]
        name = SONGS[named[0]][0] if named else f"song_{FIRST_SONG + numbers[0]:02x}"
        player, end, starts = play(image, header, bank, lengths, transpositions)
        tracks = player.shown(end)
        notes, played, controls = replay(tracks, starts, bank, transpositions, levels)
        songs.append({"name": name, "numbers": numbers, "header": header, "starts": starts, "tracks": tracks,
                      "tempos": player.tempo_events(tracks), "notes": notes, "played": played,
                      "controls": controls})

    # the instruments' programs: a bass below key 48
    keys = defaultdict(list)
    for song in songs:
        for instrument, played in song["played"].items():
            keys[instrument] += played
    programs = {}
    for (pcm, instrument), played in keys.items():
        low = sorted(played)[len(played) // 2] < 48
        programs[(pcm, instrument)] = (PCM_BASS if low else PCM_LEAD) if pcm else (FM_BASS if low else FM_LEAD)

    # the bytes no file shows, in the file that shows the most of their piece, or of the music before it
    shown = defaultdict(set)
    for song in songs:
        for units, items, step, length, pass_ in (read for reads in song["tracks"] for read in reads):
            for at, data, target in items:
                shown[song["name"]].update(range(at, at + len(data)))
            if step[0] in ("note", "rest", "held"):
                shown[song["name"]].update(range(step[1], step[1] + len(step[2])))
        shown[song["name"]].update(range(song["header"], song["header"] + 2 * SONG_TRACKS))
    every = set().union(*shown.values()) if shown else set()
    owner = songs[0]["name"]
    unshown = defaultdict(list)
    music = sorted((first, stop, name) for name, kind, first, stop in pieces if kind in ("music track", "song header"))
    for first, stop, name in music:
        counts = Counter({song: sum(1 for place in range(first, stop) if place in places)
                          for song, places in shown.items()})
        if counts and counts.most_common(1)[0][1]:
            owner = counts.most_common(1)[0][0]
        run = None
        for place in list(range(first, stop)) + [None]:
            if place is not None and place not in every:
                run = run or [place, place]
                run[1] = place + 1
                continue
            if run:
                unshown[owner].append((names.name(run[0]), bytes(image[run[0]:run[1]])))
                run = None

    folder.mkdir(parents=True, exist_ok=True)
    for old in folder.glob("*.mid"):
        if old.stem not in {song["name"] for song in songs}:
            old.unlink()
    listing = ["# the songs (tools/sound_music.py): each MIDI file, the song commands that play it, and what the game",
               "# plays it for"]
    for song in songs:
        data = song_file(song["name"], song["numbers"], song["header"], song["starts"], song["tracks"],
                         song["tempos"], song["notes"], programs, song["controls"], names,
                         unshown.get(song["name"], []))
        (folder / f"{song['name']}.mid").write_bytes(data)
        uses = "; ".join(SONGS[FIRST_SONG + number][1] for number in song["numbers"] if FIRST_SONG + number in SONGS)
        listing.append(f"{song['name']}  " + " ".join(f"{FIRST_SONG + number:02X}" for number in song["numbers"])
                       + (f"  # {uses}" if uses else ""))
    (folder / "music.txt").write_text("\n".join(listing) + "\n", encoding="ascii")
    return len(songs)


# ---- the way back ----

def parse(data, where):
    """A Standard MIDI File: (division, [track's events: (tick, kind, values)]), kinds 'on' (channel, key, velocity),
    'off' (channel, key) and 'meta' (type, bytes); the others left out"""
    if data[:4] != b"MThd" or len(data) < 14:
        raise MusicError(f"{where} is no Standard MIDI File")
    division = int.from_bytes(data[12:14], "big")
    if division & 0x8000 or not division:
        raise MusicError(f"{where}: its time is no ticks a quarter note")
    at = 8 + int.from_bytes(data[4:8], "big")
    tracks = []
    while at + 8 <= len(data):
        kind, size = data[at:at + 4], int.from_bytes(data[at + 4:at + 8], "big")
        body = data[at + 8:at + 8 + size]
        at += 8 + size
        if kind != b"MTrk":
            continue
        events, tick, place, status = [], 0, 0, None

        def number():
            nonlocal place
            value = 0
            for _ in range(4):
                if place >= len(body):
                    raise MusicError(f"{where}: track {len(tracks) + 1} ends inside an event")
                byte = body[place]
                place += 1
                value = value << 7 | byte & 0x7F
                if not byte & 0x80:
                    return value
            raise MusicError(f"{where}: track {len(tracks) + 1}: a variable-length quantity of more than 4 bytes")

        while place < len(body):
            tick += number()
            if place >= len(body):
                raise MusicError(f"{where}: track {len(tracks) + 1} ends inside an event")
            byte = body[place]
            if byte == 0xFF:
                if place + 1 >= len(body):
                    raise MusicError(f"{where}: track {len(tracks) + 1} ends inside an event")
                kind_ = body[place + 1]
                place += 2
                size_ = number()
                if kind_ == 0x2F:
                    break
                events.append((tick, "meta", (kind_, bytes(body[place:place + size_]))))
                place += size_
                continue
            if byte in (0xF0, 0xF7):
                place += 1
                place += number()
                continue
            if byte & 0x80:
                if byte > 0xF0:
                    raise MusicError(f"{where}: track {len(tracks) + 1}, tick {tick}: a status byte {byte:02X}")
                status = byte
                place += 1
            elif status is None:
                raise MusicError(f"{where}: track {len(tracks) + 1}, tick {tick}: data with no status before it")
            size_ = 1 if status & 0xE0 == 0xC0 else 2
            if place + size_ > len(body):
                raise MusicError(f"{where}: track {len(tracks) + 1} ends inside an event")
            values = body[place:place + size_]
            place += size_
            if status & 0xF0 == 0x90 and values[1]:
                events.append((tick, "on", (status & 0x0F, values[0], values[1])))
            elif status & 0xF0 in (0x80, 0x90):
                events.append((tick, "off", (status & 0x0F, values[0])))
        tracks.append(events)
    return division, tracks


class Rebuilt:
    """The bytes the files give, by place, and where each came from"""

    def __init__(self, names):
        self.names = names
        self.bytes = {}

    def put(self, place, data, where):
        for offset, byte in enumerate(data):
            at = place + offset
            if at in self.bytes and self.bytes[at][0] != byte:
                raise MusicError(f"{where}: the byte at {self.names.name(at)} comes back as {byte:02X}, and as "
                                 f"{self.bytes[at][0]:02X} from {self.bytes[at][1]}")
            self.bytes.setdefault(at, (byte, where))


def driver_tracks(tracks, where):
    """The tracks with an 'S' event, as [(start name, [read: [tick, [command bytes], step, Note Off tick]], here)],
    and the file's 'N' and 'U' events. A read is a tick's events, the commands and then a step: ('note', key),
    ('rest',), ('held', bytes, key), ('cut',); after a command FF, nothing"""
    header, unshown, found = None, [], []
    for index, events in enumerate(tracks):
        start, reads, open_note, ended = None, [], None, False
        here = f"{where}, track {index + 1}"
        for tick, kind, values in sorted(events, key=lambda event: (event[0], event[1] != "off")):
            if kind == "off":
                if open_note is not None and open_note[0] == values[1]:
                    open_note[1][3] = tick
                    open_note = None
                continue
            if kind == "meta":
                if values[0] != 0x7F or values[1][:1] != bytes([TAG]) or len(values[1]) < 2:
                    continue
                tag, data = chr(values[1][1]), values[1][2:]
                if tag == "N":
                    place, zero, _ = data.partition(b"\x00")
                    if not zero:
                        raise MusicError(f"{here}, tick {tick}: an 'N' event with no place")
                    header = (place.decode("ascii", "replace"), f"{here}, tick {tick}")
                    continue
                if tag == "U":
                    place, zero, rest = data.partition(b"\x00")
                    if not zero:
                        raise MusicError(f"{here}, tick {tick}: a 'U' event with no place")
                    unshown.append((place.decode("ascii", "replace"), rest, f"{here}, tick {tick}"))
                    continue
                if tag == "S":
                    start = data.decode("ascii", "replace")
                    continue
                if tag not in "CRHZ":
                    continue
            if start is None:
                raise MusicError(f"{here}, tick {tick}: the driver's events come before its start ('S')")
            if ended:
                raise MusicError(f"{here}, tick {tick}: an event after the channel's end")
            if not reads or reads[-1][0] != tick:
                if reads and reads[-1][2] is None:
                    raise MusicError(f"{here}, tick {reads[-1][0]}: commands with no step after them")
                reads.append([tick, [], None, None])
            read = reads[-1]
            if kind == "on":
                if read[2] is not None and not (read[2][0] == "held" and read[2][2] is None):
                    raise MusicError(f"{here}, tick {tick}: a second step at a tick")
                if open_note is not None:
                    raise MusicError(f"{here}, tick {tick}: a note starts before the one at tick {open_note[1][0]} "
                                     f"ends")
                read[2] = ("held", read[2][1], values[1]) if read[2] is not None else ("note", values[1])
                open_note = (values[1], read)
                continue
            if read[2] is not None:
                raise MusicError(f"{here}, tick {tick}: an event after the tick's step")
            if tag == "C":
                if not data:
                    raise MusicError(f"{here}, tick {tick}: a command with no bytes")
                read[1].append(data)
                ended = data[0] == 0xFF
            elif tag == "R":
                read[2] = ("rest",)
            elif tag == "H":
                read[2] = ("held", data, None)
            else:
                read[2] = ("cut",)
                ended = True
        if start is None:
            continue
        if reads and reads[-1][2] is None and not ended:
            raise MusicError(f"{here}, tick {reads[-1][0]}: commands with no step after them")
        found.append((start, reads, here))
    return header, unshown, found


def rebuild(files, names, lengths, transpositions, out):
    """The way back: the bytes the MIDI files 'files' ([(name, bytes)]) give into 'out' (Rebuilt); 'names' the
    layout's (Names), 'lengths' note_lengths' units, 'transpositions' music_pcm_transpositions'"""
    for file_name, data in files:
        division, tracks = parse(data, file_name)
        header, unshown, found = driver_tracks(tracks, file_name)
        if header is None:
            raise MusicError(f"{file_name}: no 'N' event says its song header")
        if len(found) != SONG_TRACKS:
            raise MusicError(f"{file_name}: {len(found)} tracks with a start ('S'); a song has {SONG_TRACKS}")
        # the driver's ticks
        for _, reads, here in found:
            for read in reads:
                for slot in (0, 3):
                    if read[slot] is not None:
                        if read[slot] * TICKS_A_QUARTER % division:
                            raise MusicError(f"{here}: the tick {read[slot]} is no whole driver's tick")
                        read[slot] = read[slot] * TICKS_A_QUARTER // division
        header_place = names.place(header[0], header[1])
        for number, (start, reads, here) in enumerate(found):
            place = names.place(start, f"{here}, its start")
            out.put(header_place + 2 * number, z80_address(place).to_bytes(2, "little"), f"{file_name}'s 'S'")
        for number, (start, reads, here) in enumerate(found):
            place = names.place(start, f"{here}, its start")
            channel = Channel(number, place, None)
            for index, (tick, commands, step, released) in enumerate(reads):
                at = f"{here}, tick {tick}"
                following = reads[index + 1][0] if index + 1 < len(reads) else None
                ended = False
                for command_data in commands:
                    command = command_data[0]
                    if 0x10 <= command < 0xE0 or command == 0xE5 or not command:
                        raise MusicError(f"{at}: {command:02X} is no command ('C')")
                    if command >= 0xE0 and command not in COMMAND_LENGTHS:
                        raise MusicError(f"{at}: the command {command:02X} jumps to 0000")
                    target = None
                    data_ = command_data
                    if command in ADDRESS_AT:
                        text = command_data[ADDRESS_AT[command]:].decode("ascii", "replace")
                        target = names.place(text, at)
                        data_ = command_data[:ADDRESS_AT[command]] + z80_address(target).to_bytes(2, "little")
                    if len(data_) != COMMAND_LENGTHS.get(command, 1):
                        raise MusicError(f"{at}: the command {command:02X} has {len(data_)} bytes; the driver reads "
                                         f"{COMMAND_LENGTHS.get(command, 1)}")
                    out.put(channel.place, data_, at)
                    place = channel.execute(channel.place, data_, target, transpositions)
                    if place is None:
                        ended = True
                        break
                    channel.place = place
                if ended or step is None:
                    continue
                if step[0] == "cut":
                    continue
                if following is None:
                    raise MusicError(f"{at}: no step after it says how long it is")
                units = (following - tick) * UNIT
                if step[0] == "held":
                    held = step[1]
                    if not held or held_length(held) != len(held):
                        raise MusicError(f"{at}: the held note's bytes ('H') do not end at their first nibble F")
                    if held_units(held, lengths) is None:
                        raise MusicError(f"{at}: the held note's bytes ('H') have a length's code note_lengths has "
                                         f"not")
                    if held_units(held, lengths) != units:
                        raise MusicError(f"{at}: the held note lasts {units} units; its lengths ('H') add up to "
                                         f"{held_units(held, lengths)}")
                    if step[2] is None:
                        raise MusicError(f"{at}: the held note ('H') has no Note On")
                    nibble = channel.nibble(step[2])
                    if nibble is None:
                        raise MusicError(f"{at}: no pitch gives the key {step[2]} from the channel's octave")
                    data_ = bytes([0xE5, held[0] & 0xF0 | nibble]) + held[1:]
                else:
                    code = code_of(units, lengths)
                    if code is None:
                        raise MusicError(f"{at}: no note or rest lasts {units} units (note_lengths)")
                    nibble = 0
                    if step[0] == "note":
                        nibble = channel.nibble(step[1])
                        if not nibble:
                            raise MusicError(f"{at}: no pitch gives the key {step[1]} from the channel's octave")
                    data_ = bytes([code << 4 | nibble])
                if step[0] != "rest":
                    expected = tick + channel.released(units)
                    if released is None:
                        raise MusicError(f"{at}: the note has no Note Off")
                    if released != expected:
                        raise MusicError(f"{at}: the note ends at tick {released}; the driver keys it off at "
                                         f"{expected}")
                out.put(channel.place, data_, at)
                channel.place += len(data_)
        for place, data_, here in unshown:
            out.put(names.place(place, here), data_, here)
    return out


def read(folder, names, lengths, transpositions):
    """The music the MIDI files of music.txt in 'folder' give: a Rebuilt"""
    listing = folder / "music.txt"
    if not listing.exists():
        raise MusicError(f"no {listing.name} in {folder}")
    files = []
    for line in listing.read_text(encoding="ascii").splitlines():
        if line.strip() and not line.startswith("#"):
            name = line.split()[0]
            path = folder / f"{name}.mid"
            if not path.exists():
                raise MusicError(f"music.txt names {name}, and there is no {path.name}")
            files.append((path.name, path.read_bytes()))
    return rebuild(files, names, lengths, transpositions, Rebuilt(names))
