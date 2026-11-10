/**
 *    Name:        stages/bonus_2.c
 *    Description: bonus stage 2
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    09-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the game's 053248 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

/* Step 12, bonus stage 2, by step_phase, the gauges hidden */
uint32_t step_bonus_2(uint16_t y, uint16_t u)
{
	uint32_t left_caller = 0;

	gauges_shown = 0u;
	switch ((int8_t)(uint8_t)((uint32_t)step_phase << 1))
	{
	case 0:
		left_caller = 0u;
		bonus_2_setup();
		return left_caller;
	case 2:
		left_caller = 0u;
		bonus_2_draw();
		return left_caller;
	case 4:
		left_caller = 0u;
		bonus_2_intro_phase(y);
		return left_caller;
	case 6:
		left_caller = 0u;
		bonus_2_run(y);
		return left_caller;
	case 8:
		left_caller = 0u;
		bonus_2_wait();
		return left_caller;
	case 10:
		left_caller = 0u;
		bonus_2_end_phase(u);
		return left_caller;
	case 12:
		left_caller = 0u;
		stage_7_setup();
		return left_caller;
	case 14:
		left_caller = 0u;
		stage_7_title(u);
		return left_caller;
	case 16:
		left_caller = 0u;
		return stage_7_begin(u, left_caller);
	case 18:
		left_caller = 0u;
		stage_7_opening();
		return left_caller;
	case 20:
		left_caller = 0u;
		return stage_7_play(y, left_caller);
	case 22:
		left_caller = 0u;
		stage_7_over();
		return left_caller;
	case 24:
		left_caller = 0u;
		return stage_7_exit(left_caller);
	case 26:
		left_caller = 0u;
		return stage_7_closing_scene(u, left_caller);
	case 28:
		left_caller = 0u;
		return stage_7_end_phase(u, left_caller);
	case 30:
		left_caller = 0u;
		stage_8_setup();
		return left_caller;
	case 32:
		left_caller = 0u;
		stage_8_title(u);
		return left_caller;
	case 34:
		left_caller = 0u;
		stage_8_entrance(u);
		return left_caller;
	case 36:
		left_caller = 0u;
		return stage_8_begin(u, left_caller);
	case 38:
		left_caller = 0u;
		stage_8_opening();
		return left_caller;
	case 40:
		left_caller = 0u;
		return stage_8_play(y, left_caller);
	case 42:
		left_caller = 0u;
		return stage_8_first_part_exit(left_caller);
	case 44:
		left_caller = 0u;
		return stage_8_story(u, left_caller);
	case 46:
		left_caller = 0u;
		return stage_8_robot_entrance(y, left_caller);
	case 48:
		left_caller = 0u;
		return stage_8_final_fight(y, left_caller);
	case 50:
		left_caller = 0u;
		stage_8_over();
		return left_caller;
	case 52:
		left_caller = 0u;
		return stage_8_exit(left_caller);
	case 54:
		left_caller = 0u;
		return stage_8_closing_scene(left_caller);
	case 56:
		left_caller = 0u;
		return stage_8_objects_wait(left_caller);
	case 58:
		left_caller = 0u;
		return stage_8_end_phase(u, left_caller);
	case 60:
		left_caller = 0u;
		ending_setup();
		return left_caller;
	case 62:
		left_caller = 0u;
		ending_run(u);
		return left_caller;
	case 64:
		left_caller = 0u;
		ending_end();
		return left_caller;
	case 66:
		left_caller = 0u;
		game_over_start();
		return left_caller;
	case 68:
		left_caller = 0u;
		game_over_show();
		return left_caller;
	case 70:
		left_caller = 0u;
		game_over_wait();
		return left_caller;
	case 72:
		left_caller = 0u;
		name_entry_start(u);
		return left_caller;
	case 74:
		left_caller = 0u;
		name_entry_run();
		return left_caller;
	case 76:
		left_caller = 0u;
		name_entry_end();
		return left_caller;
	case -90:
		left_caller = 0u;
		stage_2_after_boss();
		return left_caller;
	case -88:
		left_caller = 0u;
		stage_2_closing_scene();
		return left_caller;
	case -86:
		left_caller = 0u;
		stage_2_end_phase(u);
		return left_caller;
	case -84:
		left_caller = 0u;
		stage_3_forest_setup();
		return left_caller;
	case -82:
		left_caller = 0u;
		stage_3_forest_title(u);
		return left_caller;
	case -80:
		left_caller = 0u;
		return stage_3_forest_begin(u, left_caller);
	case -78:
		left_caller = 0u;
		stage_3_forest_opening();
		return left_caller;
	case -76:
		left_caller = 0u;
		return stage_3_forest_play(y, left_caller);
	case -74:
		left_caller = 0u;
		return stage_3_forest_cleared(y, left_caller);
	case -72:
		left_caller = 0u;
		stage_3_forest_over();
		return left_caller;
	case -70:
		left_caller = 0u;
		return stage_3_forest_exit(left_caller);
	case -68:
		return stage_3_forest_end_phase();
	case -66:
		left_caller = 0u;
		stage_3_cemetery_setup();
		return left_caller;
	case -64:
		left_caller = 0u;
		return stage_3_cemetery_begin(u, left_caller);
	case -62:
		left_caller = 0u;
		stage_3_cemetery_opening();
		return left_caller;
	case -60:
		left_caller = 0u;
		return stage_3_cemetery_play(y, left_caller);
	case -58:
		left_caller = 0u;
		stage_3_cemetery_over();
		return left_caller;
	case -56:
		left_caller = 0u;
		return stage_3_cemetery_exit(left_caller);
	case -54:
		left_caller = 0u;
		return stage_3_cemetery_end_phase(u, left_caller);
	case -52:
		left_caller = 0u;
		stage_4_setup();
		return left_caller;
	case -50:
		left_caller = 0u;
		stage_4_title(u);
		return left_caller;
	case -48:
		left_caller = 0u;
		return stage_4_begin(u, left_caller);
	case -46:
		left_caller = 0u;
		stage_4_opening();
		return left_caller;
	case -44:
		left_caller = 0u;
		return stage_4_play(y, left_caller);
	case -42:
		left_caller = 0u;
		stage_4_over();
		return left_caller;
	case -40:
		left_caller = 0u;
		return stage_4_exit(left_caller);
	case -38:
		left_caller = 0u;
		return stage_4_end_phase(left_caller);
	case -36:
		left_caller = 0u;
		stage_5_setup();
		return left_caller;
	case -34:
		left_caller = 0u;
		stage_5_title(u);
		return left_caller;
	case -32:
		left_caller = 0u;
		return stage_5_begin(u, left_caller);
	case -30:
		left_caller = 0u;
		stage_5_opening();
		return left_caller;
	case -28:
		left_caller = 0u;
		return stage_5_play(y, left_caller);
	case -26:
		left_caller = 0u;
		stage_5_over();
		return left_caller;
	case -24:
		left_caller = 0u;
		return stage_5_exit(left_caller);
	case -22:
		left_caller = 0u;
		stage_5_closing_scene(u);
		return left_caller;
	case -20:
		left_caller = 0u;
		stage_5_end_phase(u);
		return left_caller;
	case -18:
		left_caller = 0u;
		stage_6_setup();
		return left_caller;
	case -16:
		left_caller = 0u;
		stage_6_title(u);
		return left_caller;
	case -14:
		left_caller = 0u;
		return stage_6_begin(u, left_caller);
	case -12:
		left_caller = 0u;
		stage_6_opening();
		return left_caller;
	case -10:
		left_caller = 0u;
		return stage_6_play(y, left_caller);
	case -8:
		left_caller = 0u;
		stage_6_over();
		return left_caller;
	case -6:
		left_caller = 0u;
		return stage_6_exit(left_caller);
	case -4:
		left_caller = 0u;
		stage_6_closing_scene(u);
		return left_caller;
	case -2:
		left_caller = 0u;
		stage_6_end_phase(u);
		return left_caller;
	}
	unreachable();
}

/* Bonus stage 2's setup: the sprites, the scene's variables, the palettes, the scroll and the step's
   scene, the tile layers' clear queued */
void bonus_2_setup(void)
{
	uint16_t ignored16 = 0, ignored16_2 = 0, job = 0, request = 0, scroll_x = 0, scroll_y = 0, u = 0;
	uint8_t t1 = 0;

	t1 = io_read8(0x1C80u);
	io_write8(0x1C80u, 0u);
	clear_sprites(&ignored16, &ignored16_2);
	job = 0u;
	queue_job(job);
	u = reset_for_stage();
	palette_request_kind = 1u;
	request = 0xF82u;
	palette_request(request, &ignored16_2, &u);
	scroll_x = 0xFFF0u;
	set_scroll_x(scroll_x);
	scroll_y = 0u;
	set_scroll_y(scroll_y);
	set_step_scene();
	step_phase++;
}

/* Once the layers are clear: map scene 8B on both layers and scene_timer set to 384 frames */
void bonus_2_draw(void)
{
	uint16_t ignored16 = 0, ignored16_2 = 0, ignored16_3 = 0, layer_and_columns = 0;

	if (layer_clear_pending != 0u)
		return;
	map_scene = 0x8Bu;
	map_area = 0u;
	set_area_tile_banks();
	io_write8(0x1FB9u, 0x3Fu);
	io_write8(0x1FBAu, 0x36u);
	layer_and_columns = 0x26u;
	draw_layer_columns(layer_and_columns, &ignored16, &ignored16_2, &ignored16_3);
	layer_and_columns = 0x126u;
	draw_layer_columns(layer_and_columns, &ignored16, &ignored16_2, &ignored16_3);
	layer_a_scroll_y = 0xFF30u;
	scene_timer = 0x180u;
	step_phase++;
}

/* A frame of bonus stage 2's instructions (bank 10); when scene_timer runs out or a button skips them,
   the objects are cleared and the bonus stage's area 1 is drawn */
void bonus_2_intro_phase(uint16_t y)
{
	uint32_t carry = 0;
	uint8_t b = 0;
	uint16_t command = 0, ignored16 = 0, ignored16_2 = 0, ignored16_3 = 0, ignored16_4 = 0, layer_and_columns = 0, scroll_x = 0, scroll_y = 0, wait = 0;
	uint16_t t1 = 0;

	wait = 0xD000u | b;
	check_skip(wait, &ignored16, &carry);
	if (carry == 0u)
	{
		io_write8(0x1FB9u, 0x13u);
		io_write8(0x1FBAu, 0x2Cu);
		t1 = scene_timer;
		scene_timer = t1 - 1u;
		if (t1 != 1u)
		{
			window_bank = 0x10u;
			set_lines(window_bank);
			bonus_2_intro(y);
			update_players(&ignored16, &ignored16_3, &ignored16_2, &ignored16_4, &carry);
			return;
		}
	}
	clear_objects(&ignored16, &ignored16_2);
	io_write8(0x1FB9u, 0x3Fu);
	io_write8(0x1FBAu, 0x36u);
	clear_layer_b();
	scroll_x = 0xFFF0u;
	set_scroll_x(scroll_x);
	scroll_y = 0u;
	set_scroll_y(scroll_y);
	map_area = 1u;
	set_area_tile_banks();
	layer_and_columns = 0x26u;
	draw_layer_columns(layer_and_columns, &ignored16, &ignored16_3, &ignored16_2);
	io_write8(0x1FB9u, 0x13u);
	io_write8(0x1FBAu, 0x2Cu);
	command = 0u;
	carry = queue_sound_always(command);
	step_phase++;
}

/* A frame of bonus stage 2's game, run by bank 10 */
void bonus_2_run(uint16_t y)
{
	uint32_t carry = 0;
	uint16_t ignored16 = 0, ignored16_2 = 0, ignored16_3 = 0, ignored16_4 = 0;

	window_bank = 0x10u;
	set_lines(window_bank);
	bonus_2_contest(y);
	update_players(&ignored16, &ignored16_2, &ignored16_3, &ignored16_4, &carry);
}

/* Waits 64 frames after bonus stage 2's game, then notes stage_players */
void bonus_2_wait(void)
{
	step_timer = (step_timer & 0xFFu) | (((uint8_t)(step_timer >> 8u) + 1u & 0xFFu) << 8u);
	if ((uint8_t)(step_timer >> 8u) == 0x40u)
	{
		players_present = players_playing;
		step_timer &= 0xFFu;
		step_phase++;
	}
}

/* Bonus stage 2's end (bank 12), which a button skips after C0 frames; then the next step */
void bonus_2_end_phase(uint16_t u)
{
	uint32_t carry = 0;
	uint8_t b = 0;
	uint16_t ignored16 = 0, wait = 0;

	wait = 0xC000u | b;
	check_skip(wait, &ignored16, &carry);
	if (carry)
	{
		game_step++;
		step_phase = 0u;
		step_subphase = 0u;
		step_countdown = 0u;
	}
	else
	{
		scene_running = 1u;
		window_bank = 0x12u;
		set_lines(window_bank);
		post_bonus_2_scene(u);
		if (scene_running == 0u)
		{
			game_step++;
			step_phase = 0u;
			step_subphase = 0u;
			step_countdown = 0u;
			return;
		}
	}
}
