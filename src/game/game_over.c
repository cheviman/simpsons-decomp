/**
 *    Name:        game/game_over.c
 *    Description: GAME OVER and the high score check
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    11-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the game's 053248 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

/* The game over phase, by game_step, the gauges hidden */
uint32_t game_over_phase(uint16_t u, uint32_t left_caller)
{
	gauges_shown = 0u;
	switch ((int8_t)(uint8_t)((uint32_t)game_step << 1))
	{
	case 0:
		game_over_start();
		return left_caller;
	case 2:
		game_over_show();
		return left_caller;
	case 4:
		game_over_wait();
		return left_caller;
	case 6:
		name_entry_start(u);
		return left_caller;
	case 8:
		name_entry_run();
		return left_caller;
	case 10:
		name_entry_end();
		return left_caller;
	case -128:
		stage_3_cemetery_opening();
		return left_caller;
	case -126:
		return stage_3_cemetery_play(left_caller);
	case -124:
		stage_3_cemetery_over();
		return left_caller;
	case -122:
		return stage_3_cemetery_exit(left_caller);
	case -120:
		return stage_3_cemetery_end_phase(u, left_caller);
	case -118:
		stage_4_setup();
		return left_caller;
	case -116:
		stage_4_title(u);
		return left_caller;
	case -114:
		return stage_4_begin(u, left_caller);
	case -112:
		stage_4_opening();
		return left_caller;
	case -110:
		return stage_4_play(left_caller);
	case -108:
		stage_4_over();
		return left_caller;
	case -106:
		return stage_4_exit(left_caller);
	case -104:
		return stage_4_end_phase(left_caller);
	case -102:
		stage_5_setup();
		return left_caller;
	case -100:
		stage_5_title(u);
		return left_caller;
	case -98:
		return stage_5_begin(u, left_caller);
	case -96:
		stage_5_opening();
		return left_caller;
	case -94:
		return stage_5_play(left_caller);
	case -92:
		stage_5_over();
		return left_caller;
	case -90:
		return stage_5_exit(left_caller);
	case -88:
		stage_5_closing_scene(u);
		return left_caller;
	case -86:
		stage_5_end_phase(u);
		return left_caller;
	case -84:
		stage_6_setup();
		return left_caller;
	case -82:
		stage_6_title(u);
		return left_caller;
	case -80:
		return stage_6_begin(u, left_caller);
	case -78:
		stage_6_opening();
		return left_caller;
	case -76:
		return stage_6_play(left_caller);
	case -74:
		stage_6_over();
		return left_caller;
	case -72:
		return stage_6_exit(left_caller);
	case -70:
		stage_6_closing_scene(u);
		return left_caller;
	case -68:
		stage_6_end_phase(u);
		return left_caller;
	case -66:
		bonus_2_setup();
		return left_caller;
	case -64:
		bonus_2_draw();
		return left_caller;
	case -62:
		bonus_2_intro_phase();
		return left_caller;
	case -60:
		bonus_2_run();
		return left_caller;
	case -58:
		bonus_2_wait();
		return left_caller;
	case -56:
		bonus_2_end_phase(u);
		return left_caller;
	case -54:
		stage_7_setup();
		return left_caller;
	case -52:
		stage_7_title(u);
		return left_caller;
	case -50:
		return stage_7_begin(u, left_caller);
	case -48:
		stage_7_opening();
		return left_caller;
	case -46:
		return stage_7_play(left_caller);
	case -44:
		stage_7_over();
		return left_caller;
	case -42:
		return stage_7_exit(left_caller);
	case -40:
		return stage_7_closing_scene(u, left_caller);
	case -38:
		return stage_7_end_phase(u, left_caller);
	case -36:
		stage_8_setup();
		return left_caller;
	case -34:
		stage_8_title(u);
		return left_caller;
	case -32:
		stage_8_entrance(u);
		return left_caller;
	case -30:
		return stage_8_begin(u, left_caller);
	case -28:
		stage_8_opening();
		return left_caller;
	case -26:
		return stage_8_play(left_caller);
	case -24:
		return stage_8_first_part_exit(left_caller);
	case -22:
		return stage_8_story(u, left_caller);
	case -20:
		return stage_8_robot_entrance(left_caller);
	case -18:
		return stage_8_final_fight(left_caller);
	case -16:
		stage_8_over();
		return left_caller;
	case -14:
		return stage_8_exit(left_caller);
	case -12:
		return stage_8_closing_scene(left_caller);
	case -10:
		return stage_8_objects_wait(left_caller);
	case -8:
		return stage_8_end_phase(u, left_caller);
	case -6:
		ending_setup();
		return left_caller;
	case -4:
		ending_run(u);
		return left_caller;
	case -2:
		ending_end();
		return left_caller;
	}
	unreachable();
}

/* Starts GAME OVER: the fixed layer's texts cleared, every palette job stopped, a palette effect and the
   screen darkened */
void game_over_start(void)
{
	uint8_t delay = 0;
	uint16_t clear_from = 0, clear_to = 0, count = 0, job = 0, request = 0;

	delay = 0u;
	do
	{
		delay++;
	} while (delay != 4u);
	job = 1u;
	queue_job(job);
	clear_from = palette_jobs;
	clear_to = 0x3C01u;
	io_write8(palette_jobs, 0u);
	count = 0x1FFu;
	while (count != 0u)
	{
		mem_write8(clear_to, mem_read8(clear_from));
		clear_from++;
		clear_to++;
		count--;
	}
	palette_request_kind = 2u;
	request = 0xBu;
	count = palette_request(count, request);
	palette_request_kind = 4u;
	request = 0x1E80u;
	palette_request(count, request);
	game_step++;
}

/* Once the fixed layer is clear, shows GAME OVER for scene_timer's 384 frames */
void game_over_show(void)
{
	if (layer_clear_pending != 0u)
		return;
	window_bank = 0x20u;
	set_lines(window_bank);
	game_over_draw();
	scene_timer = 0x180u;
	game_step++;
}

/* Waits for scene_timer, then the game's end */
void game_over_wait(void)
{
	uint16_t timer_before = 0;

	timer_before = scene_timer;
	scene_timer = timer_before - 1u;
	if (timer_before != 1u)
		return;
	game_finish();
}

/* Clears the screen and checks each player's score against the high scores: the name entry when one gets
   in, else the game's end */
void game_finish(void)
{
	uint32_t carry = 0;
	uint16_t score = 0, score_address = 0;
	uint8_t old_scroll_control = 0, scores_left = 0;

	old_scroll_control = io_read8(tile_chip_scroll_control);
	io_write8(tile_chip_scroll_control, 0u);
	clear_sprites();
	clear_tile_layers();
	score_address = marge_score_ADDRESS;
	finish_scores_left = 4u;
	do
	{
		score = mem_read16(score_address);
		high_score_rank(&score, &carry);
		if (carry)
		{
			reset_for_stage();
			mode_phase = 4u;
			game_step = 0u;
			return;
		}
		score_address += 8u;
		scores_left = finish_scores_left;
		finish_scores_left = scores_left - 1u;
	} while (scores_left != 1u);
	end_game();
}
