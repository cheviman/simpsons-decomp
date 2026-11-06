"""
Name:        simpsons_rom.py
Description: MAME 'simpsons' ROM set (The Simpsons, 4 Players World, set 1) and its regions
Version:     0.1.0
Created:     05-11-2026
Modified:    05-11-2026
Author:      Sebastian Toyos

Files are identified by CRC32 + SHA1, not by name. Accepts a folder or the .zip as is.
Region layouts follow ROM_START( simpsons ) in MAME src/mame/konami/simpsons.cpp (BSD-3-Clause).

The main CPU, Konami's 053248 (a 6809 with Konami's own opcodes), sees 64 KB: 0x8000-0xFFFF is fixed to the
program region's last 32 KB (0x78000-0x7FFFF), and 0x6000-0x7FFF is a window onto any of the region's 64
banks of 8 KB, which the CPU's bank lines select. The sound Z80 sees 0x0000-0x7FFF fixed and 0x8000-0xBFFF as
a window onto a 16 KB bank of the rest of its ROM.
"""
import hashlib
import zipfile
import zlib
from pathlib import Path

SET_NAME = "simpsons"

# MAME name -> (crc32, sha1, size)
ROM_FILES = {
    "072-g02.16c": ("580ce1d6", "5b07fb8e8041e1663980aa35d853fdc13b22dac5", 0x020000),
    "072-g01.17c": ("9f843def", "858432b59101b0577c5cec6ac0c7c20ab0780c9a", 0x020000),
    "072-j13.13c": ("aade2abd", "10f178d5ed399b4866266e075d91ca3db26798f8", 0x020000),
    "072-j12.15c": ("479e12f2", "15a6cb12e68b4773a29ab463640a43f8e814de59", 0x020000),
    "072-e03.6g": ("866b7a35", "98905764eb4c7d968ccc17618a1f24ee12e33c0e", 0x020000),
    "072-b07.18h": ("ba1ec910", "0805ccb641271dea43185dc0365732260db1763d", 0x080000),
    "072-b06.16h": ("cf2bbcab", "47afea47f9bc8cb5eb1c7b7fbafe954b3e749aeb", 0x080000),
    "072-b08.3n": ("7de500ad", "61b76b8f402e3bde1509679aaaa28ef08cafb0ab", 0x100000),
    "072-b09.8n": ("aa085093", "925239d79bf607021d371263352618876f59c1f8", 0x100000),
    "072-b10.12n": ("577dbd53", "e603e03e3dcba766074561faa92afafa5761953d", 0x100000),
    "072-b11.16l": ("55fab05d", "54db8559d71ed257de9a29c8808654eaea0df9e2", 0x100000),
    "072-d05.1f": ("1397a73b", "369422c84cca5472967af54b8351e29fcd69f621", 0x100000),
    "072-d04.1d": ("78778013", "edbd6d83b0d1a20df39bb160b92395586fa3c32d", 0x040000),
    "simpsons.12c.nv": ("ec3f0449", "da35b98cd10bfabe9df3ede05462fabeb0e01ca9", 0x000080),
}

# The maincpu region: 512 KB, four chips one after another (64 banks of 8 KB)
PROGRAM_AREAS = [
    (0x000000, 0x020000),  # 072-g02.16c
    (0x020000, 0x040000),  # 072-g01.17c
    (0x040000, 0x060000),  # 072-j13.13c
    (0x060000, 0x080000),  # 072-j12.15c
]
CODE_AREAS = PROGRAM_AREAS                      # (code in all four: the banks are spread over them)
# a bank's end repeats, at the same offsets, what another bank holds there: the assembler's buffer, not cleared from
# bank to bank (the core's coverage.py: fill)
RESIDUE_BANK_SIZE = 0x2000
PROGRAM_SIZE = 0x080000
PROGRAM_BANK_SIZE = 0x2000
FIXED_PROGRAM = (0x078000, 0x080000)            # what the CPU sees at 0x8000-0xFFFF

# The audiocpu region: 0x0000-0x7FFF the Z80's fixed program, 0x10000-0x27FFF its banks (0x8000-0xFFFF unused)
SOUND_SIZE = 0x028000
SOUND_BANK_BASE = 0x010000
SOUND_BANK_SIZE = 0x4000


def read_files(source):
    """Return {original_name: bytes} from a folder or a .zip."""
    source = Path(source)
    contents = {}
    if source.is_file() and source.suffix.lower() == ".zip":
        with zipfile.ZipFile(source) as archive:
            for entry in archive.infolist():
                if not entry.is_dir():
                    contents[Path(entry.filename).name] = archive.read(entry)
        return contents
    for path in sorted(source.iterdir()):
        if path.is_file():
            contents[path.name] = path.read_bytes()
    return contents


def identify_set(source):
    """Return ({mame_name: bytes}, [report lines]), matching every file by its hashes. A folder that holds
    none of the set's files loose is read through the first .zip in it that does."""
    found, report = _identify(source)
    if not found and Path(source).is_dir():
        for archive in sorted(Path(source).glob("*.zip")):
            found, report = _identify(archive)
            if found:
                break
    return found, report


def _identify(source):
    by_crc = {crc: name for name, (crc, _, _) in ROM_FILES.items()}
    found = {}
    report = []
    for original_name, data in read_files(source).items():
        crc = format(zlib.crc32(data) & 0xFFFFFFFF, "08x")
        mame_name = by_crc.get(crc)
        if mame_name and ROM_FILES[mame_name][1] == hashlib.sha1(data).hexdigest():
            found[mame_name] = data
            report.append(f"OK      {original_name:20} = {mame_name}")
        else:
            report.append(f"--      {original_name:20} not part of the set (crc {crc})")
    for mame_name in sorted(set(ROM_FILES) - set(found)):
        report.append(f"MISSING {mame_name}")
    return found, report


def load_set(source):
    """Like identify_set, but stops when a file is missing."""
    found, _ = identify_set(source)
    missing = sorted(set(ROM_FILES) - set(found))
    if missing:
        raise SystemExit(f"The '{SET_NAME}' ROM set is incomplete. Missing: " + ", ".join(missing))
    return found


def interleave_words(*chips):
    """ROM_LOAD32_WORD / ROM_LOAD64_WORD: every group of 2 x len(chips) bytes takes a 16-bit word of each chip,
    in the order given."""
    lanes = len(chips)
    result = bytearray(len(chips[0]) * lanes)
    for lane, chip in enumerate(chips):
        result[lane * 2::lanes * 2] = chip[0::2]
        result[lane * 2 + 1::lanes * 2] = chip[1::2]
    return result


def build_program(rom):
    """maincpu region (512 KB, big endian): the 64 banks of 8 KB, the last four of which the CPU sees fixed at
    0x8000-0xFFFF."""
    return bytes(rom["072-g02.16c"] + rom["072-g01.17c"] + rom["072-j13.13c"] + rom["072-j12.15c"])


def build_sound(rom):
    """audiocpu region (160 KB): the chip's first 32 KB at 0x0000 (the Z80's fixed program), the rest at
    0x10000 (ROM_CONTINUE), the banks the Z80 sees at 0x8000-0xBFFF."""
    chip = rom["072-e03.6g"]
    region = bytearray(SOUND_SIZE)
    region[0x0000:0x8000] = chip[:0x8000]
    region[SOUND_BANK_BASE:SOUND_BANK_BASE + len(chip) - 0x8000] = chip[0x8000:]
    return bytes(region)


def build_tiles(rom):
    """k052109 region (1 MB) in file byte order: the tile layers' graphics."""
    return bytes(interleave_words(rom["072-b07.18h"], rom["072-b06.16h"]))


def build_sprites(rom):
    """k053246 region (4 MB) in file byte order: the sprites' graphics."""
    return bytes(interleave_words(rom["072-b08.3n"], rom["072-b09.8n"], rom["072-b10.12n"], rom["072-b11.16l"]))


def build_samples(rom):
    """k053260 region (1.25 MB): the K053260's samples."""
    return bytes(rom["072-d05.1f"] + rom["072-d04.1d"])


def canonical_address(address):
    """A place of the program: its offset in the program region (what kref's traces and symbols.txt give: a bank's
    window resolved), or None if it is not in the region."""
    return address if 0 <= address < PROGRAM_SIZE else None


class ProgramMemory:
    """The program region by place (its offsets): anything outside it reads 0xFF. An instruction that runs past a
    bank's end goes on in the next bank here, in the fixed program on the CPU: what needs the CPU's view takes it
    from konami_cpu.analysis."""

    def __init__(self, image):
        self.image = image

    def r8(self, address):
        offset = canonical_address(address)
        return self.image[offset] if offset is not None else 0xFF

    def r16(self, address):
        return (self.r8(address) << 8) | self.r8(address + 1)


def build_eeprom(rom):
    """eeprom region (128 bytes): the ER5911's contents MAME starts with (without it the game boots upside down
    and reports an error)."""
    return bytes(rom["simpsons.12c.nv"])
