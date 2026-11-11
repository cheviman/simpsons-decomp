/**
 *    Name:        attract/title.c
 *    Description: the attract's title screen (its end) and the title shown after a coin
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    11-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the game's 053248 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

/* The title's second phase: the layers keep sliding; when attract_timer runs out the copyright gives way
   to the Binky and Bongo notices */
void title_show_notices(void)
{
	uint16_t text_number = 0;
	uint8_t wait_left = 0;

	title_scroll_layers();
	wait_left = attract_timer;
	attract_timer = wait_left - 1u;
	if (wait_left != 1u)
		return;
	text_number = 0x82u;
	print_game_text(text_number);
	text_number = 0x10u;
	print_game_text(text_number);
	text_number = 0x11u;
	print_game_text(text_number);
	mode_phase++;
}

/* The title's last phase: when attract_timer runs out again, the scroll, the objects and the background
   colour are reset and the attract moves to its next step */
void title_end(void)
{
	uint16_t ignored16 = 0, request = 0, u = 0;
	uint8_t wait_left = 0;

	title_scroll_layers();
	wait_left = attract_timer;
	attract_timer = wait_left - 1u;
	if (wait_left != 1u)
		return;
	layer_a_scroll_y = 0u;
	layer_b_scroll_y = 0u;
	clear_objects(&ignored16, &u);
	palette_request_kind = 3u;
	request = 0u;
	palette_request(u, request);
	mode_step++;
	mode_phase = 0u;
	game_step = 0u;
	step_phase = 0u;
	step_subphase = 0u;
	step_countdown = 0u;
}

/* Slides the title's two tile layers a quarter of a pixel a frame, layer A one way and layer B the other */
void title_scroll_layers(void)
{
	uint32_t carry = 0;
	uint16_t layer_a_x_low = 0, old_layer_a_x_low = 0, new_layer_a_x_low = 0, layer_b_x_low = 0, old_layer_b_x_low = 0;

	layer_a_x_low = AT16(layer_a_scroll_x, -1);
	old_layer_a_x_low = layer_a_x_low;
	new_layer_a_x_low = old_layer_a_x_low - 0x40u;
	carry = old_layer_a_x_low < 0x40u;
	AT16(layer_a_scroll_x, -1) = new_layer_a_x_low;
	layer_a_scroll_x = (layer_a_scroll_x & 0xFFu) | (((uint8_t)(layer_a_scroll_x >> 8u) - carry & 0xFFu) << 8u);
	layer_b_x_low = AT16(layer_b_scroll_x, -1);
	old_layer_b_x_low = layer_b_x_low;
	carry = (uint16_t)(old_layer_b_x_low + 0x40u) < old_layer_b_x_low;
	AT16(layer_b_scroll_x, -1) = old_layer_b_x_low + 0x40u;
	layer_b_scroll_x = (layer_b_scroll_x & 0xFFu) | (((uint8_t)(layer_b_scroll_x >> 8u) + carry & 0xFFu) << 8u);
}

/* The attract's step after a coin that gave no credit yet: the title with INSERT COIN, by mode_phase */
void attract_coin_title(uint16_t u)
{
	for (;;)
	{
		switch ((int8_t)(uint8_t)((uint32_t)mode_phase << 1))
		{
		case 0:
			coin_title_start();
			return;
		case 2:
			coin_title_draw();
			return;
		case 4:
			break;
		case -48:
			attract_opening_scene(u);
			return;
		case -46:
			attract_demo(u);
			return;
		case -44:
			attract_title(u);
			return;
		case -42:
			attract_high_scores(u);
			return;
		case -40:
			attract_warning(u);
			return;
		case -38:
			continue;
		case -36:
			attract_clear_screen();
			return;
		case -34:
			attract_wait_clear();
			return;
		case -32:
			attract_opening_run(u);
			return;
		case -30:
			attract_next_scene();
			return;
		case -28:
			attract_title_clear();
			return;
		case -26:
			attract_title_wait(u);
			return;
		case -24:
			title_show_notices();
			return;
		case -22:
			title_end();
			return;
		case -20:
			demo_start();
			return;
		case -18:
			demo_play(u);
			return;
		case -16:
			high_scores_start(u);
			return;
		case -14:
			high_scores_draw_background();
			return;
		case -12:
			high_scores_show(u);
			return;
		case -10:
			high_scores_close(u);
			return;
		case -8:
			warning_skip(u);
			return;
		case -6:
			warning_first_page();
			return;
		case -4:
			warning_second_page();
			return;
		case -2:
			warning_end(u);
			return;
		}
		break;
	}
	coin_title_blink();
}

/* Queues the tile layers' clear for the title after a coin */
void coin_title_start(void)
{
	uint16_t job = 0;

	job = 0u;
	queue_job(job);
	mode_phase++;
}

/* Once the layers are clear, clears the scores, the sound and the objects and draws the title with its
   two halves apart */
void coin_title_draw(void)
{
	uint16_t command = 0, ignored16 = 0, u = 0;
	uint8_t discarded_read = 0;

	if (layer_clear_pending != 0u)
		return;
	reset_for_game();
	discarded_read = io_read8(tile_chip_scroll_control);
	io_write8(tile_chip_scroll_control, 0u);
	command = 0u;
	queue_sound(command);
	clear_objects(&ignored16, &u);
	attract_title_draw(u);
	layer_a_scroll_x = 0xFF80u;
	layer_b_scroll_x = 0x80u;
}

/* Makes INSERT COIN blink: printed or erased every 32 frames by frame_count */
void coin_title_blink(void)
{
	uint8_t erase = 0;
	uint16_t text_number = 0;

	erase = 0u;
	if ((frame_count & 0x20u) != 0u)
		erase = 0x80u;
	text_number = 0x8000u | (uint8_t)(erase + 0x12u);
	print_game_text(text_number);
}
