/**
 *    Name:        main.cpp
 *    Description: the translation scaffold: the 053248 program translated to C (tools/recompile.py) on the board
 *                 model, with no screen or sound, the controls a script drives, and hashes of every frame in the
 *                 formats tools/core/konami/reference/kref writes
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    06-11-2026
 *    Author:      Sebastian Toyos
 *
 *    license:BSD-3-Clause
 *    Usage: simpsons_headless [--frames N] [--hashes FILE] [--video-hashes FILE] [--sound-hashes FILE]
 *                             [--script FILE] [--service] [--rom FOLDER]
 *    A development tool, as kref is: it reads the player's ROM set (--rom's folder or .zip, rom/ by default) for
 *    the program's data, the graphics and the sound board, whose Z80 and chips are still MAME's (kref's
 *    sound/ksound_053260.cpp), as its video is (video/kvideo_053246.cpp). It runs with frame timing, as kref
 *    --timing frames does (simpsons/frame.h): the script is applied when each VBLANK starts, and the hashes are
 *    kref's ("FRAME HASH": simpsons_state_hash, the frame's pixels with --video-hashes, the sound board's samples and
 *    RAM with --sound-hashes), so the two compare line by line. --service turns the test switch on.
 */
#include "game/data.h"
#include "game/extract.h"
#include "konami/cpu.h"
#include "simpsons/frame.h"
#include "simpsons/machine.h"
#include "simpsons/program.h"
#include "simpsons/script.h"
#include "ksound_053260.h"
#include "kvideo_053246.h"

#include <cinttypes>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>

namespace {

constexpr const char *kUsage = "Usage: simpsons_headless [--frames N] [--hashes FILE] [--video-hashes FILE]"
	" [--sound-hashes FILE] [--script FILE] [--service] [--rom FOLDER]\n";

uint64_t g_frames = 600;
FILE *g_hashes = nullptr;
FILE *g_video_hashes = nullptr;
FILE *g_sound_hashes = nullptr;
simpsons_script *g_script = nullptr;
bool g_video = false;

FILE *open_output(const char *path)
{
	FILE *file = std::fopen(path, "w");
	if (!file)
	{
		std::fprintf(stderr, "%s: cannot be written\n", path);
		std::exit(1);
	}
	return file;
}

void sound_sync()
{
	ks_run_until(simpsons_board.cycles);
}

void finish()
{
	for (FILE *file : { g_hashes, g_video_hashes, g_sound_hashes })
		if (file)
			std::fclose(file);
	std::printf("frames:            %" PRIu64 "\n", simpsons_board.frame);
	std::printf("interrupts taken:  %u\n", program_interrupts());
	std::printf("sound IRQs:        %u\n", simpsons_board.sound_irqs);
	std::printf("watchdog resets:   %u\n", simpsons_board.watchdog_resets);
	std::fflush(stdout);
	std::exit(0);
}

// The program waits for its next frame: the board's VBLANK ends (the video takes its scroll and draws), begins (its
// events: the IRQ, the sprite DMA and its FIRQ), the controls change and the frame's hashes are taken, as kref's
void on_frame()
{
	const uint64_t number = simpsons_board.frame + 1;
	if (g_video)
		kv_vblank_end(true);
	if (g_video)
		kv_vblank_start();
	simpsons_frame_vblank(cpu.i != 0);
	simpsons_script_apply(g_script, simpsons_board.frame);
	ks_end_frame(simpsons_board.cycles);
	if (g_sound_hashes)
		std::fprintf(g_sound_hashes, "%" PRIu64 " %016" PRIx64 " %016" PRIx64 "\n", number, ks_frame_samples_hash(),
			ks_state_hash());
	if (g_hashes)
		std::fprintf(g_hashes, "%" PRIu64 " %016" PRIx64 "\n", number, simpsons_state_hash());
	if (g_video_hashes)
		std::fprintf(g_video_hashes, "%" PRIu64 " %016" PRIx64 "\n", number, kv_frame_hash());
	if (number >= g_frames)
		finish();
}

} // namespace

int main(int argc, char **argv)
{
	std::string rom_folder = "rom";
	const char *script_path = nullptr;
	bool frames_given = false, service = false;

	for (int index = 1; index < argc; index++)
	{
		const std::string argument = argv[index];
		const bool has_value = index + 1 < argc;
		if (argument == "--frames" && has_value)
		{
			g_frames = std::strtoull(argv[++index], nullptr, 10);
			frames_given = true;
		}
		else if (argument == "--hashes" && has_value)
			g_hashes = open_output(argv[++index]);
		else if (argument == "--video-hashes" && has_value)
			g_video_hashes = open_output(argv[++index]);
		else if (argument == "--sound-hashes" && has_value)
			g_sound_hashes = open_output(argv[++index]);
		else if (argument == "--script" && has_value)
			script_path = argv[++index];
		else if (argument == "--rom" && has_value)
			rom_folder = argv[++index];
		else if (argument == "--service")
			service = true;
		else
		{
			std::fprintf(stderr, "%s", kUsage);
			return 1;
		}
	}
	if (const char *problem = game_rom_set_load(rom_folder.c_str()))
	{
		std::fprintf(stderr, "The ROM set in %s cannot be read: %s\n", rom_folder.c_str(), problem);
		return 1;
	}
	simpsons_reset();
	simpsons_board.frame_timing = true;
	if (service)
		simpsons_board.test &= uint8_t(~SIMPSONS_TEST_SERVICE);
	if (script_path)
	{
		char error[256];
		g_script = simpsons_script_load(script_path, error, sizeof(error));
		if (!g_script)
		{
			std::fprintf(stderr, "%s\n", error);
			return 1;
		}
		if (!frames_given && simpsons_script_frames(g_script))
			g_frames = simpsons_script_frames(g_script);
		simpsons_script_apply(g_script, 0);
	}
	g_video = g_video_hashes != nullptr;
	if (g_video)
		kv_attach();
	ks_attach();
	simpsons_board.sound_sync = sound_sync;

	program_frame = on_frame;
	program_reset();
	program_run();
	return 3;
}
