"""
Name:        sound_coverage.py
Description: runs the shared core's sound_coverage.py for this game: every byte of the Z80 program as code,
             described data, fill or unknown (build/listing/sound_coverage.txt)
Version:     0.1.0
Created:     05-11-2026
Modified:    05-11-2026
Author:      Sebastian Toyos

The script is the core's (arcade-decomp, which tools/core holds); tools/game_profile.py tells it about this game.
Its usage is the core's.
"""
import runpy
import sys
from pathlib import Path

TOOLS = Path(__file__).resolve().parent
sys.path[:0] = [str(TOOLS / "core"), str(TOOLS)]
runpy.run_path(str(TOOLS / "core" / "sound_coverage.py"), run_name="__main__")
