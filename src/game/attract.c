/**
 *    Name:        game/attract.c
 *    Description: the attract mode: its scenes until a credit starts the game
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    09-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the game's 053248 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

/* The game's state 1, at each frame: with no credits runs the attract's scene (a coin skips to its scene
   5), with credits starts the game (state 2). */
void attract(uint16_t y, uint16_t u)
{
	uint8_t a = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0;

	in_attract = 1u;
	gauges_shown = 0u;
	if (separate_coin_slots != 0u)
	{
		t1 = slot_credits;
		a = (uint8_t)(t1 >> 8);
		if (t1 == 0u)
		{
			t2 = slot_2_credits;
			a = (uint8_t)(t2 >> 8);
			if (t2 == 0u)
			{
				t3 = slot_3_credits;
				a = (uint8_t)(t3 >> 8);
				if (t3 == 0u)
				{
					t4 = slot_4_credits;
					a = (uint8_t)(t4 >> 8);
					if (t4 == 0u)
					{
						if (coins_inserted != 0u)
						{
							mode_step++;
							mode_phase = 0u;
							game_step = 0u;
							step_phase = 0u;
							step_subphase = 0u;
							step_countdown = 0u;
							mode_step = 5u;
						}
						switch ((int8_t)(uint8_t)((uint32_t)mode_step << 1))
						{
						case 0:
							attract_opening_scene(y, u);
							break;
						case 2:
							attract_demo(y, u);
							break;
						case 4:
							attract_title(y, u);
							break;
						case 6:
							attract_high_scores(y, u);
							break;
						case 8:
							attract_warning(y, u);
							break;
						case 10:
							attract_coin_title(y, u);
							break;
						case 12:
							attract_clear_screen();
							break;
						case 14:
							attract_wait_clear();
							break;
						case 16:
							attract_opening_run(y, u);
							break;
						case 18:
							attract_next_scene();
							break;
						case 20:
							attract_title_clear();
							break;
						case 22:
							attract_title_wait(u);
							break;
						case 24:
							title_show_notices();
							break;
						case 26:
							title_end();
							break;
						case 28:
							demo_start();
							break;
						case 30:
							demo_play(u);
							break;
						case 32:
							high_scores_start(u);
							break;
						case 34:
							high_scores_draw_background();
							break;
						case 36:
							high_scores_show(u);
							break;
						case 38:
							high_scores_close(u);
							break;
						case 40:
							warning_skip(u);
							break;
						case 42:
							warning_first_page();
							break;
						case 44:
							warning_second_page();
							break;
						case 46:
							warning_end(u);
							break;
						case 48:
							coin_title_start();
							break;
						case 50:
							coin_title_draw();
							break;
						case 52:
							coin_title_blink();
							break;
						}
						return;
					}
				}
			}
		}
	}
	else
	{
		t5 = credits;
		a = (uint8_t)(t5 >> 8);
		if (t5 == 0u)
		{
			if (coins_inserted != 0u)
			{
				mode_step++;
				mode_phase = 0u;
				game_step = 0u;
				step_phase = 0u;
				step_subphase = 0u;
				step_countdown = 0u;
				mode_step = 5u;
			}
			switch ((int8_t)(uint8_t)((uint32_t)mode_step << 1))
			{
			case 0:
				attract_opening_scene(y, u);
				break;
			case 2:
				attract_demo(y, u);
				break;
			case 4:
				attract_title(y, u);
				break;
			case 6:
				attract_high_scores(y, u);
				break;
			case 8:
				attract_warning(y, u);
				break;
			case 10:
				attract_coin_title(y, u);
				break;
			case 12:
				attract_clear_screen();
				break;
			case 14:
				attract_wait_clear();
				break;
			case 16:
				attract_opening_run(y, u);
				break;
			case 18:
				attract_next_scene();
				break;
			case 20:
				attract_title_clear();
				break;
			case 22:
				attract_title_wait(u);
				break;
			case 24:
				title_show_notices();
				break;
			case 26:
				title_end();
				break;
			case 28:
				demo_start();
				break;
			case 30:
				demo_play(u);
				break;
			case 32:
				high_scores_start(u);
				break;
			case 34:
				high_scores_draw_background();
				break;
			case 36:
				high_scores_show(u);
				break;
			case 38:
				high_scores_close(u);
				break;
			case 40:
				warning_skip(u);
				break;
			case 42:
				warning_first_page();
				break;
			case 44:
				warning_second_page();
				break;
			case 46:
				warning_end(u);
				break;
			case 48:
				coin_title_start();
				break;
			case 50:
				coin_title_draw();
				break;
			case 52:
				coin_title_blink();
				break;
			}
			return;
		}
		players_joined = 0u;
	}
	players_joined = a;
	AT16(player_variables, -1) = 0u;
	homer_lives = 0u;
	bart_lives = 0u;
	lisa_lives = 0u;
	marge_state = 0u;
	homer_state = 0u;
	bart_state = 0u;
	lisa_state = 0u;
	in_attract = 0u;
	players_playing = 0u;
	game_mode++;
	mode_step = 0u;
	mode_phase = 0u;
	game_step = 0u;
	step_phase = 0u;
	step_subphase = 0u;
	step_countdown = 0u;
	game_mode = 2u;
	unused_mode_word = 0u;
	attract_timer = 0u;
	scene_timer &= 0xFFu;
	step_timer = 0u;
	unused_mode_byte = 0u;
}

/* The attract's scene 0 by its step: the screens cleared, then bank 20's opening run step by step, then
   the next scene. */
void attract_opening_scene(uint16_t y, uint16_t u)
{
	for (;;)
	{
		switch ((int8_t)(uint8_t)((uint32_t)mode_phase << 1))
		{
		case 0:
			attract_clear_screen();
			return;
		case 2:
			attract_wait_clear();
			return;
		case 4:
			attract_opening_run(y, u);
			return;
		case 6:
			attract_next_scene();
			return;
		case 8:
			attract_title_clear();
			return;
		case 10:
			attract_title_wait(u);
			return;
		case 12:
			title_show_notices();
			return;
		case 14:
			title_end();
			return;
		case 16:
			demo_start();
			return;
		case 18:
			demo_play(u);
			return;
		case 20:
			high_scores_start(u);
			return;
		case 22:
			high_scores_draw_background();
			return;
		case 24:
			high_scores_show(u);
			return;
		case 26:
			high_scores_close(u);
			return;
		case 28:
			warning_skip(u);
			return;
		case 30:
			warning_first_page();
			return;
		case 32:
			warning_second_page();
			return;
		case 34:
			warning_end(u);
			return;
		case 36:
			coin_title_start();
			return;
		case 38:
			coin_title_draw();
			return;
		case 40:
			break;
		case -12:
			continue;
		case -10:
			attract_demo(y, u);
			return;
		case -8:
			attract_title(y, u);
			return;
		case -6:
			attract_high_scores(y, u);
			return;
		case -4:
			attract_warning(y, u);
			return;
		case -2:
			attract_coin_title(y, u);
			return;
		}
		break;
	}
	coin_title_blink();
}

/* Queues the clearing of the three layers and scrolls both layers to FFF0. */
void attract_clear_screen(void)
{
	uint16_t job = 0;

	job = 0u;
	queue_job(job);
	layer_a_scroll_x = 0xFFF0u;
	layer_b_scroll_x = 0xFFF0u;
	mode_phase++;
}

/* Waits until the screen is cleared, then sets the tile banks for the map's scene 0, area 0. */
void attract_wait_clear(void)
{
	if (layer_clear_pending != 0u)
		return;
	map_scene = 0u;
	map_area = 0u;
	set_area_tile_banks();
	mode_phase++;
}

/* Runs bank 20's opening for its step. */
void attract_opening_run(uint16_t y, uint16_t u)
{
	uint8_t a = 0;
	uint16_t move_number = 0, object = 0;

	window_bank = 0x20u;
	set_lines(window_bank);
	object = attract_opening_scenes_ADDRESS;
	a = (uint32_t)game_step << 1;
	switch ((int8_t)a)
	{
	case 0:
		attract_opening(y, u);
		return;
	case 2:
		attract_opening_end(y, u);
		return;
	case 4:
		attract_bart(y, u);
		return;
	case 6:
		attract_homer(y, u);
		return;
	case 8:
		attract_lisa(y, u);
		return;
	case 10:
		attract_marge(y, u);
		return;
	case 12:
		attract_leap(y, u);
		return;
	case 14:
		attract_last_screen(y, u);
		return;
	case 16:
		attract_opening_start(u);
		return;
	case 18:
		attract_opening_zoom();
		return;
	case 20:
		attract_opening_end_start();
		return;
	case 22:
		attract_opening_end_scroll();
		return;
	case 24:
		attract_opening_end_wait();
		return;
	case 26:
		attract_bart_scene_start();
		return;
	case 28:
		attract_bart_scene_move();
		return;
	case 30:
		attract_bart_scene_wait();
		return;
	case 32:
		attract_bart_profile_start();
		return;
	case 34:
		attract_bart_profile_type();
		return;
	case 36:
		attract_bart_profile_end(u);
		return;
	case 38:
		attract_homer_scene_start();
		return;
	case 40:
		attract_homer_scene_wait();
		return;
	case 42:
		attract_homer_scene_end();
		return;
	case 44:
		attract_homer_profile_start();
		return;
	case 46:
		attract_homer_profile_type();
		return;
	case 48:
		attract_homer_profile_end();
		return;
	case 50:
		attract_lisa_scene_start();
		return;
	case 52:
		attract_lisa_scene_walk();
		return;
	case 54:
		attract_lisa_scene_play();
		return;
	case 56:
		attract_lisa_profile_start();
		return;
	case 58:
		attract_lisa_profile_type();
		return;
	case 60:
		attract_lisa_profile_end(u);
		return;
	case 62:
		attract_marge_scene_start();
		return;
	case 64:
		attract_marge_scene_wait();
		return;
	case 66:
		attract_marge_scene_pose();
		return;
	case 68:
		attract_marge_scene_end();
		return;
	case 70:
		attract_marge_profile_start(u);
		return;
	case 72:
		attract_marge_profile_type();
		return;
	case 74:
		attract_marge_profile_end();
		return;
	case 76:
		attract_leap_start();
		return;
	case 78:
		attract_leap_rise();
		return;
	case 80:
		attract_leap_fall();
		return;
	case 82:
		attract_leap_land();
		return;
	case 84:
		attract_leap_end();
		return;
	case 86:
		attract_last_screen_start(u);
		return;
	case 88:
		attract_last_screen_wait(u);
		return;
	case 90:
		move_number = (uint32_t)a << 8;
		attract_profile_move_out(object, y, move_number);
		return;
	case 92:
	case 98:
		attract_profile_move_stop(object);
		return;
	case 94:
		move_number = (uint32_t)a << 8;
		attract_profile_move_pause(object, move_number);
		return;
	case 96:
		attract_profile_move_back(object, y);
		return;
	case 100:
		attract_profile_move_done();
		return;
	}
}

/* Puts the layers back at 0, silences the sound and goes on to the attract's next scene. */
void attract_next_scene(void)
{
	uint32_t carry = 0;
	uint16_t command = 0;

	layer_a_scroll_x = 0u;
	layer_b_scroll_x = 0u;
	command = 0u;
	carry = queue_sound(command);
	mode_step++;
	mode_phase = 0u;
	game_step = 0u;
	step_phase = 0u;
	step_subphase = 0u;
	step_countdown = 0u;
}

/* The attract's scene 2 by its step: the title screen with the copyright, then the Life in Hell
   characters' credits. */
void attract_title(uint16_t y, uint16_t u)
{
	for (;;)
	{
		switch ((int8_t)(uint8_t)((uint32_t)mode_phase << 1))
		{
		case 0:
			attract_title_clear();
			return;
		case 2:
			attract_title_wait(u);
			return;
		case 4:
			title_show_notices();
			return;
		case 6:
			title_end();
			return;
		case 8:
			demo_start();
			return;
		case 10:
			demo_play(u);
			return;
		case 12:
			high_scores_start(u);
			return;
		case 14:
			high_scores_draw_background();
			return;
		case 16:
			high_scores_show(u);
			return;
		case 18:
			high_scores_close(u);
			return;
		case 20:
			warning_skip(u);
			return;
		case 22:
			warning_first_page();
			return;
		case 24:
			warning_second_page();
			return;
		case 26:
			warning_end(u);
			return;
		case 28:
			coin_title_start();
			return;
		case 30:
			coin_title_draw();
			return;
		case 32:
			break;
		case -20:
			attract_opening_scene(y, u);
			return;
		case -18:
			attract_demo(y, u);
			return;
		case -16:
			continue;
		case -14:
			attract_high_scores(y, u);
			return;
		case -12:
			attract_warning(y, u);
			return;
		case -10:
			attract_coin_title(y, u);
			return;
		case -8:
			attract_clear_screen();
			return;
		case -6:
			attract_wait_clear();
			return;
		case -4:
			attract_opening_run(y, u);
			return;
		case -2:
			attract_next_scene();
			return;
		}
		break;
	}
	coin_title_blink();
}

/* Silences the sound, clears the objects and queues the clearing of the layers. */
void attract_title_clear(void)
{
	uint32_t carry = 0;
	uint16_t command = 0, ignored16 = 0, ignored16_2 = 0, job = 0;

	command = 0u;
	carry = queue_sound(command);
	clear_objects(&ignored16, &ignored16_2);
	job = 0u;
	queue_job(job);
	mode_phase++;
}

/* Waits until the screen is cleared, then draws the title. */
void attract_title_wait(uint16_t palette_job)
{
	if (layer_clear_pending != 0u)
		return;
	attract_title_draw(palette_job);
}

/* Draws the title screen: both layers' picture, the title object (kind 0E), the logo's tiles, MATT
   GROENING and the copyright, and fades the colours in. */
void attract_title_draw(uint16_t palette_job)
{
	uint16_t ignored16 = 0, ignored16_2 = 0, ignored16_3 = 0, layer_and_columns = 0, request = 0, scroll_x = 0, scroll_y = 0, text_number = 0, u = 0;

	scroll_x = 0x10u;
	set_scroll_x(scroll_x);
	scroll_y = 0u;
	set_scroll_y(scroll_y);
	palette_request_kind = 3u;
	request = 0x7A53u;
	palette_request(request, &ignored16, &palette_job);
	palette_request_kind = 1u;
	request = 0xF07u;
	palette_request(request, &ignored16, &palette_job);
	map_scene = 0u;
	map_area = 0u;
	set_area_tile_banks();
	io_write8(0x1FB9u, 0x3Fu);
	io_write8(0x1FBAu, 0x36u);
	layer_and_columns = 0x26u;
	draw_layer_columns(layer_and_columns, &ignored16_2, &ignored16, &ignored16_3);
	layer_and_columns = 0x126u;
	draw_layer_columns(layer_and_columns, &ignored16_2, &ignored16, &ignored16_3);
	layer_a_scroll_y = 0x20u;
	layer_b_scroll_y = 0x20u;
	io_write8(0x1FB9u, 0x13u);
	io_write8(0x1FBAu, 0x2Cu);
	OBJECT(OBJECT_ADDRESS(14))->flags = 0x80u;
	OBJECT(OBJECT_ADDRESS(14))->animation_flags = 0x80u;
	OBJECT(OBJECT_ADDRESS(14))->kind = 0xEu;
	OBJECT(OBJECT_ADDRESS(14))->animation = 0x9Fu;
	OBJECT(OBJECT_ADDRESS(14))->x = 0xD0u;
	OBJECT(OBJECT_ADDRESS(14))->y = 0x128u;
	text_number = 0u;
	print_game_text(text_number);
	text_number = 5u;
	print_game_text(text_number);
	text_number = 2u;
	print_game_text(text_number);
	text_number = 0x103u;
	print_game_text(text_number);
	text_number = 0x7304u;
	u = print_game_text(text_number);
	palette_request_kind = 4u;
	request = 0x1640u;
	palette_request(request, &ignored16, &u);
	attract_timer = 0u;
	mode_phase++;
}
