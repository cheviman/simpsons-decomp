/**
 *    Name:        attract/warning.c
 *    Description: the attract's export warning (skipped in this set)
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    11-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the game's 053248 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

/* The attract's export warning step, by mode_phase */
void attract_warning(uint16_t u)
{
	for (;;)
	{
		switch ((int8_t)(uint8_t)((uint32_t)mode_phase << 1))
		{
		case 0:
			warning_skip(u);
			return;
		case 2:
			warning_first_page();
			return;
		case 4:
			warning_second_page();
			return;
		case 6:
			warning_end(u);
			return;
		case 8:
			coin_title_start();
			return;
		case 10:
			coin_title_draw();
			return;
		case 12:
			break;
		case -40:
			attract_opening_scene(u);
			return;
		case -38:
			attract_demo(u);
			return;
		case -36:
			attract_title(u);
			return;
		case -34:
			attract_high_scores(u);
			return;
		case -32:
			continue;
		case -30:
			attract_coin_title(u);
			return;
		case -28:
			attract_clear_screen();
			return;
		case -26:
			attract_wait_clear();
			return;
		case -24:
			attract_opening_run(u);
			return;
		case -22:
			attract_next_scene();
			return;
		case -20:
			attract_title_clear();
			return;
		case -18:
			attract_title_wait(u);
			return;
		case -16:
			title_show_notices();
			return;
		case -14:
			title_end();
			return;
		case -12:
			demo_start();
			return;
		case -10:
			demo_play(u);
			return;
		case -8:
			high_scores_start(u);
			return;
		case -6:
			high_scores_draw_background();
			return;
		case -4:
			high_scores_show(u);
			return;
		case -2:
			high_scores_close(u);
			return;
		}
		break;
	}
	coin_title_blink();
}

/* Skips the export warning: the step ends at once and the attract starts over */
void warning_skip(uint16_t palette_job)
{
	attract_restart(palette_job);
}

/* Unused: would start the export warning, with its palettes and the tile layers' clear */
void warning_start(uint16_t palette_job)
{
	uint16_t job = 0, request = 0;

	palette_request_kind = 1u;
	request = 0xF07u;
	palette_request(palette_job, request);
	job = 0u;
	queue_job(job);
	mode_phase++;
}

/* Never reached: prints WARNING and the first page of the export warning once the layers are clear */
void warning_first_page(void)
{
	uint16_t request = 0, text_number = 0, u = 0;

	if (layer_clear_pending != 0u)
		return;
	text_number = 0u;
	print_game_text(text_number);
	text_number = 0x800Du;
	print_game_text(text_number);
	text_number = 0xEu;
	u = print_game_text(text_number);
	palette_request_kind = 3u;
	request = 0x6D6Bu;
	palette_request(u, request);
	attract_timer = 0u;
	mode_phase++;
}

/* Never reached: after attract_timer's frames, the export warning's second page in place of the first */
void warning_second_page(void)
{
	uint16_t text_number = 0;
	uint8_t wait_left = 0;

	wait_left = attract_timer;
	attract_timer = wait_left - 1u;
	if (wait_left != 1u)
		return;
	text_number = 0x8Eu;
	print_game_text(text_number);
	text_number = 0xFu;
	print_game_text(text_number);
	mode_phase++;
}

/* Never reached: after attract_timer's frames, the warning ends and the attract starts over */
void warning_end(uint16_t palette_job)
{
	uint8_t wait_left = 0;

	wait_left = attract_timer;
	attract_timer = wait_left - 1u;
	if (wait_left != 1u)
		return;
	attract_restart(palette_job);
}

/* Starts the attract over from its first step, the characters' profiles */
void attract_restart(uint16_t palette_job)
{
	uint16_t request = 0;

	palette_request_kind = 3u;
	request = 0u;
	palette_request(palette_job, request);
	mode_step++;
	mode_phase = 0u;
	game_step = 0u;
	step_phase = 0u;
	step_subphase = 0u;
	step_countdown = 0u;
	mode_step = 0u;
}
