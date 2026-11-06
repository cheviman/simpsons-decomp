"""
Name:        disassemble.py
Description: runs the shared core's static analysis of the 053248 (tools/core/konami_cpu/analysis.py) for this
             game: the program's code from its vectors and symbols.txt, without traces, into a listing and a report
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
runpy.run_module("konami_cpu.analysis", run_name="__main__")
