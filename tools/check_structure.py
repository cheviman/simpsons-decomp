"""
Name:        check_structure.py
Description: runs the shared core's check_structure.py (tools/core) for this game: checks that the C's if, loops, switch and control variables do what the program's jumps do, on a copy of the C it writes into OUT_DIR
Version:     0.1.0
Created:     06-11-2026
Modified:    06-11-2026
Author:      Sebastian Toyos

The script is the core's (arcade-decomp, which tools/core holds); tools/game_profile.py tells it about this game.
Its usage is the core's: python tools/check_structure.py OUT_DIR [--sound] [--runs N].
"""
import runpy
import sys
from pathlib import Path

TOOLS = Path(__file__).resolve().parent
sys.path[:0] = [str(TOOLS / "core"), str(TOOLS)]
runpy.run_path(str(TOOLS / "core" / "check_structure.py"), run_name="__main__")
