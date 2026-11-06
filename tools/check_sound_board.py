"""
Name:        check_sound_board.py
Description: runs every control script on kref with the game's own sound board beside MAME's, and says how many
             frames differ in each
Version:     0.1.0
Created:     06-11-2026
Modified:    06-11-2026
Author:      Sebastian Toyos

Usage: python tools/check_sound_board.py [NAME ...] [--jobs N] [--bin DIR] [--out DIR] [--timing FILE]
  NAME      scripts of tests/controls to run (file names without .txt); all of them by default
  --jobs N  scripts at a time (3 by default)
  --bin     where kref is (build/bin by default), built with the game's sound board (src/sound/: K_GAME_SOUND)
  --out     where the runs go (build/sound_check by default)
  --timing  the timing model's table (build/sound/timing.txt by default, which tools/decompile_sound.py writes)

For each script, kref runs the original 053248 program (with its default frame timing) with MAME's sound board
under the game's timing model (--sound-timing) and the game's own sound board beside it (--sound-board-check: the
decompiled sound program of src/sound/ on runtime/src/sound_cpu.c and sound_board.c), fed the same commands at the
same times; per frame the hashes of the samples of the two chips and of the Z80's RAM (without its stack, with its
two answers to the 053248) are compared, and OUT/NAME.txt has them ("FRAME REFERENCE_SAMPLES REFERENCE_RAM
OWN_SAMPLES OWN_RAM"). Each run's 053248 state hashes (OUT/NAME_hashes.txt) are compared with the scenario's
reference under MAME's own Z80 pace (build/scenarios_frames/NAME/hashes.txt), to tell where the timing model moves
the game: "state same" or the first frame that differs.
"""
import subprocess
import sys
import time
from concurrent.futures import ThreadPoolExecutor
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
CONTROLS = ROOT / "tests" / "controls"
REFERENCES = ROOT / "build" / "scenarios_frames"


def reference_frames(name):
    """The frames the scenario's reference ran (its hashes: a frame number and a hash each), or None."""
    hashes = REFERENCES / name / "hashes.txt"
    return len(hashes.read_text(encoding="ascii").split()) // 2 if hashes.exists() else None


def first_state_difference(name, out):
    """'same', or the first frame whose 053248 state hash differs from the scenario's reference"""
    reference = REFERENCES / name / "hashes.txt"
    ours = out / f"{name}_hashes.txt"
    if not reference.exists() or not ours.exists():
        return "no reference"
    expected = [line for line in reference.read_text(encoding="ascii").splitlines() if line]
    actual = [line for line in ours.read_text(encoding="ascii").splitlines() if line]
    for left, right in zip(expected, actual):
        if left != right:
            return f"state differs from frame {left.split()[0]}"
    return "state same" if len(expected) == len(actual) else f"state same for {min(len(expected), len(actual))} frames"


def run(kref, timing, script, out):
    started = time.time()
    result = subprocess.run([str(kref), "--script", str(script), "--sound-timing", str(timing),
                             "--sound-board-check", str(out / f"{script.stem}.txt"),
                             "--hashes", str(out / f"{script.stem}_hashes.txt")],
                            capture_output=True, text=True, cwd=str(ROOT))
    summary = next((line for line in result.stdout.splitlines() if line.startswith("sound board check:")), None)
    frames = next((line.split()[1] for line in result.stdout.splitlines() if line.startswith("frames:")), "?")
    details = [line for line in result.stderr.splitlines() if line.strip()]
    return script.stem, result.returncode, frames, summary, details, time.time() - started


def main():
    arguments = sys.argv[1:]
    jobs, bin_dir, out = 3, ROOT / "build" / "bin", ROOT / "build" / "sound_check"
    timing = ROOT / "build" / "sound" / "timing.txt"
    names = []
    while arguments:
        argument = arguments.pop(0)
        if argument == "--jobs" and arguments:
            jobs = int(arguments.pop(0))
        elif argument == "--bin" and arguments:
            bin_dir = Path(arguments.pop(0))
        elif argument == "--out" and arguments:
            out = Path(arguments.pop(0))
        elif argument == "--timing" and arguments:
            timing = Path(arguments.pop(0))
        elif argument.startswith("--"):
            print(__doc__)
            return 1
        else:
            names.append(argument)
    kref = bin_dir / "kref.exe" if (bin_dir / "kref.exe").exists() else bin_dir / "kref"
    if not kref.exists():
        raise SystemExit(f"{kref}: no such file")
    if not timing.exists():
        raise SystemExit(f"{timing}: no such file (tools/decompile_sound.py writes it)")
    scripts = [CONTROLS / f"{name}.txt" for name in names] if names else sorted(CONTROLS.glob("*.txt"))
    out.mkdir(parents=True, exist_ok=True)
    failed = 0
    frames_total = 0
    started = time.time()
    with ThreadPoolExecutor(max_workers=jobs) as pool:
        for name, code, frames, summary, details, seconds in pool.map(
                lambda script: run(kref, timing, script, out), scripts):
            differs = summary is None or not summary.startswith("sound board check: 0 frames")
            expected = reference_frames(name)
            short = expected is not None and frames != str(expected)
            failed += differs or code != 0 or short
            frames_total += int(frames) if frames.isdigit() else 0
            print(f"{name:<16} {frames:>7} frames{'' if not short else f' (of {expected})'}  "
                  + (summary[len('sound board check: '):] if summary else "did not run")
                  + ("" if code == 0 else f"  (exit {code})")
                  + f"  {first_state_difference(name, out)}  {seconds:.0f} s", flush=True)
            for line in details[:12] if differs or code != 0 else []:
                print("    " + line)
    print(f"{len(scripts)} scripts, {frames_total} frames in {time.time() - started:.0f} s: "
          f"{len(scripts) - failed} to their end with no frame that differs")
    return 1 if failed else 0


if __name__ == "__main__":
    sys.exit(main())
