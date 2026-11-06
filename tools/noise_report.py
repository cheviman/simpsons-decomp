"""
Name:        noise_report.py
Description: runs the shared core's noise_report.py (tools/core) for this game: counts what is left of the CPU and of the decompiler in the C (src/, src/sound/) against tools/noise_baseline.txt
Version:     0.1.0
Created:     06-11-2026
Modified:    06-11-2026
Author:      Sebastian Toyos

The script is the core's (arcade-decomp, which tools/core holds); tools/game_profile.py tells it about this game.
Its usage is the core's: python tools/noise_report.py [--save] [--src DIR] [--files].
"""
import runpy
import sys
from pathlib import Path

TOOLS = Path(__file__).resolve().parent
sys.path[:0] = [str(TOOLS / "core"), str(TOOLS)]
runpy.run_path(str(TOOLS / "core" / "noise_report.py"), run_name="__main__")
