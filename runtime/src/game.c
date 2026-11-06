/**
 *    Name:        game.c
 *    Description: the game as the ports run it: the board with the assets in place of the ROM, the program on
 *                 it, its frames drawn and its sound made
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    06-11-2026
 *    Author:      Sebastian Toyos
 *
 *    license:BSD-3-Clause
 *    The frame as kref's reference makes it with frame timing (simpsons/frame.h): when the program waits for its
 *    next frame, the board's VBLANK ends (the video takes the scroll and draws the frame) and begins (the board's
 *    events: the IRQ, the sprite DMA and its FIRQ), then the port's game_frame_done (the controls, the frame's
 *    sound closed, its output). The sound board is the game's own (simpsons/sound_board.h: the decompiled sound
 *    program on the Z80's timing model, the game's YM2151 and K053260), the video too (simpsons/video.h).
 */
#include "game/game.h"

#include "game/assets.h"
#include "game/data.h"
#include "konami/cpu.h"
#include "simpsons/frame.h"
#include "simpsons/machine.h"
#include "simpsons/program.h"
#include "simpsons/sound_board.h"
#include "simpsons/video.h"

static simpsons_frame g_frame;
static bool g_draw;
static uint8_t g_program_given[GAME_PROGRAM_SIZE];    /* the program's bytes the assets give: its data */

void (*game_frame_done)(void);

/* The program waits for its next frame: the board's VBLANK, then the port's part */
static void frame(void)
{
	simpsons_video_vblank_end(g_draw ? &g_frame : NULL);
	simpsons_video_vblank_start();
	simpsons_frame_vblank(cpu.i != 0);
	if (game_frame_done)
		game_frame_done();
}

const char *game_load(const char *folder)
{
	const game_assets_memory into[GAME_ASSETS_REGIONS] = {
		{ game_program, g_program_given }, { game_sound, NULL }, { game_tiles, NULL }, { game_sprites, NULL },
		{ game_samples, NULL }, { game_eeprom, NULL } };

	return game_assets_load_into(folder, into);
}

const char *game_reset(bool service, bool draw)
{
	const char *problem;

	simpsons_reset();
	simpsons_board.frame_timing = true;
	simpsons_board.program_given = g_program_given;
	if (service)
		simpsons_board.test &= (uint8_t)~SIMPSONS_TEST_SERVICE;
	if ((problem = simpsons_sound_init()) != NULL)
		return problem;
	simpsons_sound_attach();
	g_draw = draw;
	simpsons_video_reset();
	program_frame = frame;
	program_reset();
	return NULL;
}

void game_end_frame(void)
{
	simpsons_sound_end_frame(simpsons_board.cycles);
}

const simpsons_frame *game_frame(void)
{
	return &g_frame;
}

const int16_t *game_audio(size_t *count)
{
	size_t values;
	const int16_t *mix = simpsons_sound_mix(&values);

	*count = values / 2u;   /* (the mix's values, left and right: two a stereo sample) */
	return mix;
}

uint32_t game_audio_rate(void)
{
	return simpsons_sound_mix_rate();
}

uint64_t game_sound_samples_hash(void)
{
	return simpsons_sound_samples_hash();
}

uint64_t game_sound_state_hash(void)
{
	return simpsons_sound_state_hash();
}
