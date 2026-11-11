/**
 *    Name:        attract/high_scores.c
 *    Description: the attract's high score table
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    11-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the game's 053248 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

/* The attract's high score step, by mode_phase */
void attract_high_scores(uint16_t u)
{
	for (;;)
	{
		switch ((int8_t)(uint8_t)((uint32_t)mode_phase << 1))
		{
		case 0:
			high_scores_start(u);
			return;
		case 2:
			high_scores_draw_background();
			return;
		case 4:
			high_scores_show(u);
			return;
		case 6:
			high_scores_close(u);
			return;
		case 8:
			warning_skip(u);
			return;
		case 10:
			warning_first_page();
			return;
		case 12:
			warning_second_page();
			return;
		case 14:
			warning_end(u);
			return;
		case 16:
			coin_title_start();
			return;
		case 18:
			coin_title_draw();
			return;
		case 20:
			break;
		case -32:
			attract_opening_scene(u);
			return;
		case -30:
			attract_demo(u);
			return;
		case -28:
			attract_title(u);
			return;
		case -26:
			continue;
		case -24:
			attract_warning(u);
			return;
		case -22:
			attract_coin_title(u);
			return;
		case -20:
			attract_clear_screen();
			return;
		case -18:
			attract_wait_clear();
			return;
		case -16:
			attract_opening_run(u);
			return;
		case -14:
			attract_next_scene();
			return;
		case -12:
			attract_title_clear();
			return;
		case -10:
			attract_title_wait(u);
			return;
		case -8:
			title_show_notices();
			return;
		case -6:
			title_end();
			return;
		case -4:
			demo_start();
			return;
		case -2:
			demo_play(u);
			return;
		}
		break;
	}
	coin_title_blink();
}

/* Starts the high score screen: queues the tile layers' clear, sets the background colour, the scroll
   and the palettes */
void high_scores_start(uint16_t palette_job)
{
	uint16_t job = 0, request = 0;

	job = 0u;
	queue_job(job);
	palette_request_kind = 3u;
	request = 0u;
	palette_job = palette_request(palette_job, request);
	layer_a_scroll_x = 0xFFF0u;
	layer_b_scroll_x = 0xFFF0u;
	palette_request_kind = 1u;
	request = 0xF01u;
	palette_request(palette_job, request);
	attract_timer = 0x40u;
	mode_phase++;
}

/* Once the layers are clear, draws map scene 02 on both tile layers as the high score screen's
   background */
void high_scores_draw_background(void)
{
	uint16_t ignored16 = 0, ignored16_2 = 0, layer_and_columns = 0, request = 0, u = 0;

	if (layer_clear_pending != 0u)
		return;
	map_scene = 2u;
	map_area = 0u;
	set_area_tile_banks();
	io_write8(colour_bases_back_sprites_fixed, 0x3Fu);
	io_write8(colour_bases_layers_a_b, 0x36u);
	layer_and_columns = 0x26u;
	draw_layer_columns(layer_and_columns, &ignored16, &ignored16_2);
	layer_and_columns = 0x126u;
	draw_layer_columns(layer_and_columns, &ignored16, &u);
	io_write8(colour_bases_back_sprites_fixed, 0x13u);
	io_write8(colour_bases_layers_a_b, 0x2Cu);
	palette_request_kind = 3u;
	request = 0x7A53u;
	palette_request(u, request);
	mode_phase++;
}

/* Runs bank 11's high score table for the frame */
void high_scores_show(uint16_t palette_job)
{
	window_bank = 0x11u;
	set_lines(window_bank);
	switch ((int8_t)(uint8_t)((uint32_t)game_step << 1))
	{
	case 0:
		high_scores_set_up();
		return;
	case 2:
		high_scores_show_first();
		return;
	case 4:
	case 10:
		high_scores_wave_out();
		return;
	case 6:
		high_scores_clear_sprites();
		return;
	case 8:
		high_scores_show_second();
		return;
	case 12:
		high_scores_fade_out(palette_job);
		return;
	case 14:
		high_scores_end();
		return;
	}
}

/* Ends the high score screen: the background colour, the sprites, the palettes and the scroll reset, and
   the attract's next step */
void high_scores_close(uint16_t palette_job)
{
	uint16_t request = 0;

	palette_request_kind = 3u;
	request = 0u;
	palette_job = palette_request(palette_job, request);
	clear_sprites();
	palette_request_kind = 1u;
	request = 0xF00u;
	palette_request(palette_job, request);
	layer_a_scroll_x = 0u;
	layer_b_scroll_x = 0u;
	mode_step++;
	mode_phase = 0u;
	game_step = 0u;
	step_phase = 0u;
	step_subphase = 0u;
	step_countdown = 0u;
}
