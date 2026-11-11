/**
 *    Name:        game/start.c
 *    Description: the game's start: the four portraits the players join on
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    11-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the game's 053248 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

/* Step 0, the game's start on the four portraits, by step_phase */
uint32_t step_portraits(uint16_t u)
{
	uint32_t left_caller = 0;

	for (;;)
	{
		switch ((int8_t)(uint8_t)((uint32_t)step_phase << 1))
		{
		case 0:
			left_caller = 0u;
			portraits_start(u);
			return left_caller;
		case 2:
			left_caller = 0u;
			portraits_run(u);
			return left_caller;
		case 4:
			left_caller = 0u;
			portraits_wait(u);
			return left_caller;
		case 6:
			left_caller = 0u;
			story_1_start();
			return left_caller;
		case 8:
			left_caller = 0u;
			story_1_wait_layers();
			return left_caller;
		case 10:
			left_caller = 0u;
			story_1_run(u);
			return left_caller;
		case 12:
			left_caller = 0u;
			stage_1_setup();
			return left_caller;
		case 14:
			left_caller = 0u;
			stage_1_title(u);
			return left_caller;
		case 16:
			left_caller = 0u;
			return stage_1_begin(u, left_caller);
		case 18:
			left_caller = 0u;
			stage_1_opening();
			return left_caller;
		case 20:
			left_caller = 0u;
			return stage_1_play(left_caller);
		case 22:
			left_caller = 0u;
			stage_1_over();
			return left_caller;
		case 24:
			left_caller = 0u;
			return stage_1_exit(left_caller);
		case 26:
			left_caller = 0u;
			return stage_1_end_phase(u, left_caller);
		case 28:
			left_caller = 0u;
			bonus_1_setup();
			return left_caller;
		case 30:
			left_caller = 0u;
			bonus_1_draw();
			return left_caller;
		case 32:
			left_caller = 0u;
			bonus_1_intro_phase();
			return left_caller;
		case 34:
			left_caller = 0u;
			bonus_1_run();
			return left_caller;
		case 36:
			left_caller = 0u;
			bonus_1_end_phase();
			return left_caller;
		case 38:
			left_caller = 0u;
			stage_2_setup();
			return left_caller;
		case 40:
			left_caller = 0u;
			stage_2_title(u);
			return left_caller;
		case 42:
			left_caller = 0u;
			return stage_2_begin(u, left_caller);
		case 44:
			left_caller = 0u;
			stage_2_opening();
			return left_caller;
		case 46:
			left_caller = 0u;
			return stage_2_play(left_caller);
		case 48:
			left_caller = 0u;
			stage_2_after_boss();
			return left_caller;
		case 50:
			left_caller = 0u;
			stage_2_closing_scene();
			return left_caller;
		case 52:
			left_caller = 0u;
			stage_2_end_phase(u);
			return left_caller;
		case 54:
			left_caller = 0u;
			stage_3_forest_setup();
			return left_caller;
		case 56:
			left_caller = 0u;
			stage_3_forest_title(u);
			return left_caller;
		case 58:
			left_caller = 0u;
			return stage_3_forest_begin(u, left_caller);
		case 60:
			left_caller = 0u;
			stage_3_forest_opening();
			return left_caller;
		case 62:
			left_caller = 0u;
			return stage_3_forest_play(left_caller);
		case 64:
			left_caller = 0u;
			return stage_3_forest_cleared(left_caller);
		case 66:
			left_caller = 0u;
			stage_3_forest_over();
			return left_caller;
		case 68:
			left_caller = 0u;
			return stage_3_forest_exit(left_caller);
		case 70:
			return stage_3_forest_end_phase();
		case 72:
			left_caller = 0u;
			stage_3_cemetery_setup();
			return left_caller;
		case 74:
			left_caller = 0u;
			return stage_3_cemetery_begin(u, left_caller);
		case 76:
			left_caller = 0u;
			stage_3_cemetery_opening();
			return left_caller;
		case 78:
			left_caller = 0u;
			return stage_3_cemetery_play(left_caller);
		case 80:
			left_caller = 0u;
			stage_3_cemetery_over();
			return left_caller;
		case 82:
			left_caller = 0u;
			return stage_3_cemetery_exit(left_caller);
		case 84:
			left_caller = 0u;
			return stage_3_cemetery_end_phase(u, left_caller);
		case 86:
			left_caller = 0u;
			stage_4_setup();
			return left_caller;
		case 88:
			left_caller = 0u;
			stage_4_title(u);
			return left_caller;
		case 90:
			left_caller = 0u;
			return stage_4_begin(u, left_caller);
		case 92:
			left_caller = 0u;
			stage_4_opening();
			return left_caller;
		case 94:
			left_caller = 0u;
			return stage_4_play(left_caller);
		case 96:
			left_caller = 0u;
			stage_4_over();
			return left_caller;
		case 98:
			left_caller = 0u;
			return stage_4_exit(left_caller);
		case 100:
			left_caller = 0u;
			return stage_4_end_phase(left_caller);
		case 102:
			left_caller = 0u;
			stage_5_setup();
			return left_caller;
		case 104:
			left_caller = 0u;
			stage_5_title(u);
			return left_caller;
		case 106:
			left_caller = 0u;
			return stage_5_begin(u, left_caller);
		case 108:
			left_caller = 0u;
			stage_5_opening();
			return left_caller;
		case 110:
			left_caller = 0u;
			return stage_5_play(left_caller);
		case 112:
			left_caller = 0u;
			stage_5_over();
			return left_caller;
		case 114:
			left_caller = 0u;
			return stage_5_exit(left_caller);
		case 116:
			left_caller = 0u;
			stage_5_closing_scene(u);
			return left_caller;
		case 118:
			left_caller = 0u;
			stage_5_end_phase(u);
			return left_caller;
		case 120:
			left_caller = 0u;
			stage_6_setup();
			return left_caller;
		case 122:
			left_caller = 0u;
			stage_6_title(u);
			return left_caller;
		case 124:
			left_caller = 0u;
			return stage_6_begin(u, left_caller);
		case 126:
			break;
		case -48:
			return game_start_phase(u);
		case -46:
			return game_run_step(u);
		case -44:
			left_caller = 0u;
			game_continue_phase();
			return left_caller;
		case -42:
			left_caller = 0u;
			return game_over_phase(u, left_caller);
		case -40:
			left_caller = 0u;
			return name_entry_phase(u, left_caller);
		case -38:
			left_caller = 0u;
			game_start_clear();
			return left_caller;
		case -36:
			left_caller = 0u;
			game_start_palettes(u);
			return left_caller;
		case -34:
			continue;
		case -32:
			return step_story_1(u);
		case -30:
			return step_stage_1(u);
		case -28:
			return step_bonus_1(u);
		case -26:
			return step_stage_2(u);
		case -24:
			left_caller = 0u;
			step_story_2();
			return left_caller;
		case -22:
			return step_stage_3_forest(u);
		case -20:
			return step_stage_3_cemetery(u);
		case -18:
			return step_stage_4(u);
		case -16:
			return step_stage_5(u);
		case -14:
			left_caller = 0u;
			step_story_3();
			return left_caller;
		case -12:
			return step_stage_6(u);
		case -10:
			return step_bonus_2(u);
		case -8:
			return step_stage_7(u);
		case -6:
			left_caller = 0u;
			step_story_4();
			return left_caller;
		case -4:
			return step_stage_8(u);
		case -2:
			return step_ending(u);
		}
		break;
	}
	left_caller = 0u;
	stage_6_opening();
	return left_caller;
}

/* Starts the portraits: the sprites and the tile layers cleared, their palettes, the scroll and
   step_timer set to 32 seconds */
void portraits_start(uint16_t palette_job)
{
	uint16_t job = 0, request = 0, scroll_x = 0, scroll_y = 0;

	clear_sprites();
	job = 0u;
	queue_job(job);
	palette_request_kind = 7u;
	request = 0x200u;
	palette_job = palette_request(palette_job, request);
	window_bank = 0x13u;
	set_lines(window_bank);
	stage_start_colour_cycles(palette_job);
	scroll_x = 0xFFF0u;
	set_scroll_x(scroll_x);
	scroll_y = 0u;
	set_scroll_y(scroll_y);
	step_timer = 0x780u;
	step_phase++;
}

/* A frame of the portraits: the players join; when one has pressed, a short wait follows (none with
   separate coin slots), and when step_timer runs out everyone with a credit is made to join */
void portraits_run(uint16_t u)
{
	uint32_t carry = 0;
	uint16_t ignored16 = 0, ignored16_2 = 0, ignored16_3 = 0;
	uint16_t timer_before = 0;

	if (layer_clear_pending != 0u)
		return;
	timer_before = step_timer;
	step_timer = timer_before - 1u;
	if (timer_before == 1u)
	{
		player_controls(2) = 0xA0u;
		player_controls(6) = 0xA0u;
		player_controls(10) = 0xA0u;
		player_controls(14) = 0xA0u;
		update_players(&ignored16, &ignored16_2, &ignored16_3, &carry);
		portraits_end();
		return;
	}
	scene_running = 0u;
	window_bank = 0x2Fu;
	set_lines(window_bank);
	game_start_portraits(u);
	if (scene_running == 0u)
	{
		update_players(&ignored16, &ignored16_2, &ignored16_3, &carry);
		return;
	}
	if (separate_coin_slots != 0u)
	{
		portraits_end();
		return;
	}
	step_timer = (step_timer & 0xFFu) | 0x4000u;
	step_phase++;
	update_players(&ignored16, &ignored16_2, &ignored16_3, &carry);
}

/* The portraits' last 64 frames after a player has pressed */
void portraits_wait(uint16_t u)
{
	uint32_t carry = 0;
	uint16_t ignored16 = 0, ignored16_2 = 0, ignored16_3 = 0;
	uint8_t wait_before = 0;

	window_bank = 0x2Fu;
	set_lines(window_bank);
	game_start_portraits(u);
	wait_before = (uint8_t)(step_timer >> 8u);
	step_timer = (step_timer & 0xFFu) | ((wait_before - 1u & 0xFFu) << 8u);
	if (wait_before != 1u)
	{
		update_players(&ignored16, &ignored16_2, &ignored16_3, &carry);
		return;
	}
	portraits_end();
}

/* Ends the portraits: step_timer cleared and the game's next step (story 1), with the players' handling */
void portraits_end(void)
{
	uint32_t carry = 0;
	uint16_t ignored16 = 0, ignored16_2 = 0, ignored16_3 = 0;

	step_timer = 0u;
	game_step++;
	step_phase = 0u;
	step_subphase = 0u;
	step_countdown = 0u;
	update_players(&ignored16, &ignored16_2, &ignored16_3, &carry);
}
