"""
Name:        sound_data_walk.py
Description: the music the Z80's driver plays, walked from its song tables as the driver reads it, in its fixed
             program and in its banks
Version:     0.1.0
Created:     06-11-2026
Modified:    06-11-2026
Author:      Sebastian Toyos

Usage: python tools/sound_data_walk.py [rom folder or .zip] [--reads FOLDER]
Writes build/listing/sound_data_walk.txt: what the walk reads, and the banks' coverage (8000-BFFF: the region's
10000-27FFF), which the core's sound_coverage.py (the program, 0000-7FFF) does not measure.

Places are the sound region's offsets (tools/simpsons_rom.py): the fixed program at its address, a bank's address
at 10000 plus 4000 a bank from bank 2 (banks 0 and 1 are the first: runtime/src/sound.c, MAME's z80_bankswitch_w).
A song (the command 80-AF: 034E "CP $B0", then 0352-0369) is a header in the bank song_banks gives (0359 "LD
A,(HL); LD ($FE00),A") at the address song_headers gives: the start of 12 tracks, one a channel (036A-03BB: F003 to
F373, 03CF "LD E,(HL); INC HL; LD D,(HL)"). The track reader (42AE) reads a byte at a time (4957):
  00-DF        a note, one byte (0x an octave: 4649; low nibble 0 a rest: 4633)
  E0-E4, E6, EE, EF, FE   one argument          E7   nine (the instrument's FM settings: 4770-47A3)
  ED           four (47B8)                      E5   a note held over several lengths: its byte, then a byte of
                                                     two lengths at a time up to the first with a nibble F (4737)
  F0           an address: goes on there (47EC)
  F1           a count and an address: goes on, the count times less one, then goes on there (47FC)
  F2, F4       a count: the start of a loop that F3 and F5 end (one byte each: 4818-4869)
  F6           a count and an address: plays the part there the count times (486C); F7 goes back (488E)
  FF           the track's end (48C9)
  E8-EC, F8-FD none: the driver jumps to 0000 for them (47A9-47B5, 48B0-48B3), no track has one
Every place a track goes on or plays from is walked too; and, in the banks, a run nothing walked whose start reads
as a track up to an end within it is one no song plays (left from the game's making), walked with its parts. And the patches the code hands 0C68 ("LD HL,nnnn; CALL
$0C68", or JP): a YM2151 channel's, 25 bytes (its algorithm and feedback, then the operators' registers, 0C76-0D22);
a K053260 channel's, 3 (0C6D "JP NC,$0D2E": a sample and two bytes), the effects' that the code or a table right
after them shows to be one (2EB5's, before the handler at 2EB8; 36B0's, before effect_steps_36bd). The walk is right when every byte the track reader and
the commands read in the scenarios (--reads: kref --sound-rom-reads) is in what it walked.
"""
import re
import sys
from collections import Counter, defaultdict
from pathlib import Path

TOOLS = Path(__file__).resolve().parent
sys.path[:0] = [str(TOOLS / "core"), str(TOOLS)]
import game_profile  # noqa: E402  (the game's: its root, its ROM set)

ROOT = game_profile.ROOT
DATA = re.compile(r"([0-9A-Fa-f]{4})\s+data\s+(\w+)\s+(\w+)\[(\d+)\]")
HEADERS, BANKS = "song_headers", "song_banks"
TRACKS = 12
BANK_START, BANK_SIZE, WINDOW = 0x10000, 0x4000, 0x8000
FIXED = {0xE0: 2, 0xE1: 2, 0xE2: 2, 0xE3: 2, 0xE4: 2, 0xE6: 2, 0xE7: 10, 0xED: 5, 0xEE: 2, 0xEF: 2, 0xF2: 2,
         0xF3: 1, 0xF4: 2, 0xF5: 1, 0xFE: 2}
GOES_ON = {0xF1: (4, 2)}                    # command: (length, offset of the address), and the track goes on
PLAYS = {0xF6: (4, 2)}
STOPS = {0xF0: (3, 1), 0xF7: (1, None), 0xFF: (1, None)}   # no way on (F0's address is walked)
HELD = 0xE5
NIBBLE_END = 0x0F
MAX_TRACK = 0x2000
# the driver's instructions that read the tracks, the songs' tables and the patches: what --reads checks the walk
# against
READERS = {0x0359, 0x0366, 0x0368, 0x03D0, 0x03D2, 0x495D, 0x0C76, 0x0C80, 0x0C87, 0x0C8C, 0x0C93, 0x0C9A, 0x0CA1,
           0x0CAB, 0x0CB2, 0x0CB7, 0x0CBE, 0x0CC5, 0x0CCC, 0x0CD6, 0x0CDD, 0x0CE2, 0x0CE9, 0x0CF0, 0x0CF7, 0x0D01,
           0x0D08, 0x0D0D, 0x0D14, 0x0D1B, 0x0D22}
SET_PATCH = 0x0C68
PATCH = 25
PCM_PATCH = 3


def place(bank, address):
    """The region's offset of a Z80 address with 'bank' chosen"""
    if address < WINDOW:
        return address
    return BANK_START + max(bank - 2, 0) * BANK_SIZE + address - WINDOW


def tables():
    """{name: (address, count, type)} of sound_symbols.txt's data lines"""
    found = {}
    for line in (ROOT / "sound_symbols.txt").read_text(encoding="utf-8").splitlines():
        match = DATA.match(line.split("#", 1)[0].strip())
        if match:
            found[match.group(2)] = (int(match.group(1), 16), int(match.group(4)), match.group(3))
    return found


def described_bytes():
    """The bytes sound_symbols.txt's data lines describe (a patch runs into none of them)"""
    sizes = {"u8": 1, "s8": 1, "u16": 2, "s16": 2}
    lines = [line.split("#", 1)[0].strip() for line in (ROOT / "sound_symbols.txt").read_text(encoding="utf-8").splitlines()]
    for line in lines:
        parts = line.split()
        if len(parts) >= 3 and parts[0] == "struct":
            sizes[parts[1]] = int(parts[2], 16)
    found = set()
    for address, count, kind in tables().values():
        found.update(range(address, address + count * sizes.get(kind, 1)))
    return found


class Walk:
    def __init__(self, image, code=()):
        self.image = image
        self.code = set(code)       # the program's bytes of code (the coverage's analysis), where no patch is
        self.described = described_bytes()
        self.spans = {}             # {first: (stop, kind)}
        self.owner = {}
        self.problems = []
        self.songs = 0
        self.tracks = set()
        self.commands = Counter()
        self.patch_places = set()
        self.unreached = set()
        named = tables()
        missing = [name for name in (HEADERS, BANKS) if name not in named]
        if missing:
            raise SystemExit("sound_data_walk: sound_symbols.txt names no " + ", ".join(missing))
        self.headers, self.banks = named[HEADERS], named[BANKS]

    def claim(self, first, stop, kind):
        taken = {self.owner[byte] for byte in range(first, stop) if byte in self.owner}
        if first in self.spans and self.spans[first] == (stop, kind):
            return True
        if taken and all(self.spans[start][1] == kind for start in taken):
            first = min([first] + list(taken))
            stop = max([stop] + [self.spans[start][0] for start in taken])
            for start in taken:
                del self.spans[start]
        elif taken:
            start = min(taken)
            self.problems.append(f"{kind} at {first:05X}-{stop - 1:05X} runs over a {self.spans[start][1]} at {start:05X}")
            return False
        self.spans[first] = (stop, kind)
        for byte in range(first, stop):
            self.owner[byte] = first
        return True

    def byte(self, bank, address):
        return self.image[place(bank, address)]

    def word(self, bank, address):
        return self.byte(bank, address) | self.byte(bank, address + 1) << 8

    def run(self):
        headers, count, _ = self.headers
        banks, _, _ = self.banks
        for index in range(count):
            bank = self.image[banks + index] & 7
            header = self.image[headers + 2 * index] | self.image[headers + 2 * index + 1] << 8
            if not self.claim(place(bank, header), place(bank, header) + 2 * TRACKS, "song header"):
                continue
            self.songs += 1
            for track in range(TRACKS):
                self.track(bank, self.word(bank, header + 2 * track), f"song {0x80 + index:02X} track {track}")
        self.patches()
        self.unreached_tracks()

    def patches(self):
        """The patches the code hands the routine that sets one (LD HL,nnnn then CALL or JP $0C68): an FM one, or a
        PCM one when code starts within an FM one's length"""
        image = self.image
        for at in range(WINDOW - 6):
            if image[at] == 0x21 and image[at + 3] in (0xCD, 0xC3)                     and image[at + 4] | image[at + 5] << 8 == SET_PATCH:
                patch = image[at + 1] | image[at + 2] << 8
                size, kind = PATCH, "fm patch"
                if any(byte in self.code or byte in self.described for byte in range(patch, patch + PATCH)):
                    size, kind = PCM_PATCH, "pcm patch"
                if patch + size <= WINDOW and not any(byte in self.code for byte in range(patch, patch + size))                         and self.claim(patch, patch + size, kind):
                    self.patch_places.add(patch)

    def unreached_tracks(self):
        """In the banks, a run nothing walked (but its 0xFF fill) that reads as a track to its end: left from the
        game's making, no song plays it"""
        image = self.image
        byte = BANK_START
        while byte < len(image):
            if byte in self.owner or image[byte] == 0xFF:
                byte += 1
                continue
            stop = byte
            while stop < len(image) and stop not in self.owner and stop % BANK_SIZE:
                stop += 1
            while stop > byte and image[stop - 1] == 0xFF:
                stop -= 1
            bank = 2 + (byte - BANK_START) // BANK_SIZE
            address = WINDOW + (byte - BANK_START) % BANK_SIZE
            end = self.track_end(bank, address)
            if end is not None and place(bank, end) <= stop:
                # (with the parts it goes on to: 13455's F1 goes on at 134AC)
                self.track(bank, address, f"the track at {byte:05X} no song plays")
                self.unreached.add(byte)
            byte = max(stop, byte + 1)

    def track_end(self, bank, address):
        """Where the track at 'address' ends, read as the driver reads it (no place it goes on to is followed), or
        None if it is no track"""
        at = address
        while at - address < MAX_TRACK:
            command = self.byte(bank, at)
            if command < 0xE0:
                at += 1
            elif command in FIXED:
                at += FIXED[command]
            elif command in GOES_ON or command in PLAYS:
                at += (GOES_ON.get(command) or PLAYS[command])[0]
            elif command in STOPS:
                return at + STOPS[command][0]
            else:
                return None
        return None

    def track(self, bank, start, source):
        work = [start]
        while work:
            address = work.pop()
            if (bank, address) in self.tracks:
                continue
            self.tracks.add((bank, address))
            at = address
            while at - address < MAX_TRACK:
                command = self.byte(bank, at)
                self.commands[command if command >= 0xE0 else "note"] += 1
                if command < 0xE0:
                    length = 1
                elif command in FIXED:
                    length = FIXED[command]
                elif command == HELD:
                    length = 2
                    while True:
                        held = self.byte(bank, at + length)
                        length += 1
                        if held & 0xF0 == 0xF0 or held & 0x0F == NIBBLE_END:
                            break
                elif command in GOES_ON:
                    length, offset = GOES_ON[command]
                    work.append(self.word(bank, at + offset))
                elif command in PLAYS:
                    length, offset = PLAYS[command]
                    work.append(self.word(bank, at + offset))
                elif command in STOPS:
                    length, offset = STOPS[command]
                    if offset is not None:
                        work.append(self.word(bank, at + offset))
                    at += length
                    break
                else:
                    self.problems.append(f"{source}: command {command:02X} at {place(bank, at):05X}")
                    break
                at += length
            first = place(bank, address)
            self.claim(first, first + at - address, "music track")


def spans(program, starts):
    """For the sound coverage (the profile's SOUND_DATA_WALK): {first: (stop, kind)} of what the walk reads in the
    program (0000-7FFF; the banks are this tool's to measure), and the problems it met"""
    # (the program's image the coverage hands over is the Z80's 64 KB, without the banks the songs' tracks are in:
    # the walk reads the whole region from the ROM set the game's tools use)
    image = game_profile.rom.build_sound(game_profile.rom.load_set(ROOT / "rom"))
    if image[:WINDOW] != bytes(program.image[:WINDOW]):
        raise SystemExit("sound_data_walk: rom/ is not the ROM set the coverage reads")
    code = {byte for address, instruction in program.analysis.instructions.items()
            for byte in range(address, address + instruction.length)}
    walk = Walk(image, code)
    walk.run()
    found = {first: span for first, span in walk.spans.items() if first < WINDOW}
    return found, walk.problems


def load_reads(folder):
    reads = defaultdict(set)
    for path in sorted(Path(folder).rglob("sound_rom_reads.txt")):
        for line in path.read_text(encoding="ascii").splitlines():
            if not line.strip() or line.startswith("#"):
                continue
            pc, span = line.split()
            first, last = (int(value, 16) for value in span.split("-"))
            reads[int(pc, 16)].update(range(first, last + 1))
    return reads


def report(walk, image, reads=None):
    kinds = Counter()
    for first, (stop, kind) in walk.spans.items():
        kinds[kind] += stop - first
    lines = ["Sound data walk", "===============", "",
             f"songs: {walk.songs}, tracks and the parts they play: {len(walk.tracks)}, patches: {len(walk.patch_places)}, "
             f"tracks no song plays: {len(walk.unreached)}"]
    lines += [f"  {kind:<16} {count:7d} bytes" for kind, count in sorted(kinds.items())]
    lines.append("  commands: " + ", ".join(f"{command:02X} {count}" if isinstance(command, int) else f"{command} {count}"
                                            for command, count in sorted(walk.commands.items(), key=str)))
    # the banks' coverage: walked, read by the driver, the EPROM's erased 0xFF, unknown
    walked = set(walk.owner)
    # (the ROM check sums a whole bank at a time, 0976-09DA: its reads say nothing of what a byte is)
    summing = {pc for pc, places in (reads or {}).items()
               if any(all(byte in places for byte in range(start, start + BANK_SIZE))
                      for start in range(BANK_START, len(image), BANK_SIZE))}
    read = set().union(*(places for pc, places in reads.items() if pc not in summing)) if reads else set()
    counts = Counter()
    unknown = []
    for byte in range(BANK_START, len(image)):
        if byte in walked:
            counts["walked"] += 1
        elif byte in read:
            counts["read, not walked"] += 1
        else:
            counts["other"] += 1
            unknown.append(byte)
    runs = []
    for byte in unknown:
        if runs and runs[-1][1] == byte:
            runs[-1][1] = byte + 1
        else:
            runs.append([byte, byte + 1])
    fill = sum(stop - first for first, stop in runs if stop - first >= 16 and not any(image[first:stop].strip(b"\xff")))
    lines += ["", "readers that sum a whole bank, left out: " + " ".join(f"{pc:04X}" for pc in sorted(summing)),
              f"the banks (region {BANK_START:05X}-{len(image) - 1:05X}, {len(image) - BANK_START} bytes): "
              f"walked {counts['walked']}, read and not walked {counts['read, not walked']}, "
              f"0xFF fill {fill}, unknown {counts['other'] - fill}"]
    rest = [(first, stop) for first, stop in runs if not (stop - first >= 16 and not any(image[first:stop].strip(b"\xff")))]
    lines += [f"  unknown {first:05X}-{stop - 1:05X} {stop - first:6}  {image[first:first + 12].hex(' ')}"
              for first, stop in sorted(rest, key=lambda run: run[0] - run[1])[:30]]
    if reads is not None:
        missed = defaultdict(set)
        for pc, places in reads.items():
            if pc in READERS:
                missed[pc] |= places - walked - set(range(0, 0x8000))
        lines += ["", "bytes the track reader read in the scenarios that the walk did not reach, by reader:"]
        lines += [f"  {pc:04X} {len(places):6d}" + (f"  {min(places):05X}-{max(places):05X}" if places else "")
                  for pc, places in sorted(missed.items())]
    lines += ["", f"problems: {len(walk.problems)}"] + [f"  {problem}" for problem in walk.problems[:40]]
    return lines


def main():
    arguments = sys.argv[1:]
    reads = None
    if "--reads" in arguments:
        position = arguments.index("--reads")
        reads = load_reads(arguments[position + 1])
        del arguments[position:position + 2]
    source = Path(arguments[0]) if arguments else ROOT / "rom"
    image = game_profile.rom.build_sound(game_profile.rom.load_set(source))
    from z80 import analysis as z80_analysis
    program = z80_analysis.load_program(image, ROOT / "sound_symbols.txt")
    code = {byte for address, instruction in program.analysis.instructions.items()
            for byte in range(address, address + instruction.length)}
    walk = Walk(image, code)
    walk.run()
    lines = report(walk, image, reads)
    out = ROOT / "build" / "listing"
    out.mkdir(parents=True, exist_ok=True)
    (out / "sound_data_walk.txt").write_text("\n".join(lines) + "\n", encoding="ascii")
    print("\n".join(lines[:70]))


if __name__ == "__main__":
    main()
