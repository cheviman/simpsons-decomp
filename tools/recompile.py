"""
Name:        recompile.py
Description: runs the shared core's recompile.py (tools/core) for this game: the 053248 program translated to C an
             instruction at a time (konami_cpu/translate.py, the profile's TRANSLATOR), the translation scaffold
Version:     0.1.0
Created:     06-11-2026
Modified:    06-11-2026
Author:      Sebastian Toyos

The script is the core's (arcade-decomp, which tools/core holds); tools/game_profile.py tells it about this game.
Its usage is the core's: python tools/recompile.py [rom folder or .zip]. It writes build/generated/, which is the
game's code translated from the player's own ROM: never part of the repository.
"""
import runpy
import sys
from pathlib import Path

TOOLS = Path(__file__).resolve().parent
sys.path[:0] = [str(TOOLS / "core"), str(TOOLS)]
runpy.run_path(str(TOOLS / "core" / "recompile.py"), run_name="__main__")
