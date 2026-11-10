/**
 *    Name:        game/game.c
 *    Description: the game mode's frame and its first phase
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    09-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the game's 053248 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

/* The game mode's frame: the random number, the gauges shown, the players counted, the game's phase by
   mode_phase, the points of the beaten enemies; in_attract cleared */
void game_mode_frame(uint16_t u)
{
	uint16_t gauge_counters = 0;
	uint32_t left_caller = 0;

	next_random();
	gauges_shown = 1u;
	window_bank = 0x20u;
	set_lines(window_bank);
	gauge_counters = gauges_count_delays();
	count_players_in_game();
	left_caller = 0u;
	switch ((int8_t)(uint8_t)((uint32_t)mode_phase << 1))
	{
	case 0:
		left_caller = game_start_phase(gauge_counters, u);
		break;
	case 2:
		left_caller = game_run_step(gauge_counters, u);
		break;
	case 4:
		game_continue_phase();
		break;
	case 6:
		left_caller = game_over_phase(gauge_counters, u, left_caller);
		break;
	case 8:
		left_caller = name_entry_phase(gauge_counters, u, left_caller);
		break;
	case 10:
		game_start_clear();
		break;
	case 12:
		game_start_palettes(u);
		break;
	case 14:
		left_caller = step_portraits(gauge_counters, u);
		break;
	case 16:
		left_caller = step_story_1(gauge_counters, u);
		break;
	case 18:
		left_caller = step_stage_1(gauge_counters, u);
		break;
	case 20:
		left_caller = step_bonus_1(gauge_counters, u);
		break;
	case 22:
		left_caller = step_stage_2(gauge_counters, u);
		break;
	case 24:
		step_story_2();
		break;
	case 26:
		left_caller = step_stage_3_forest(gauge_counters, u);
		break;
	case 28:
		left_caller = step_stage_3_cemetery(gauge_counters, u);
		break;
	case 30:
		left_caller = step_stage_4(gauge_counters, u);
		break;
	case 32:
		left_caller = step_stage_5(gauge_counters, u);
		break;
	case 34:
		step_story_3();
		break;
	case 36:
		left_caller = step_stage_6(gauge_counters, u);
		break;
	case 38:
		left_caller = step_bonus_2(gauge_counters, u);
		break;
	case 40:
		left_caller = step_stage_7(gauge_counters, u);
		break;
	case 42:
		step_story_4();
		break;
	case 44:
		left_caller = step_stage_8(gauge_counters, u);
		break;
	case 46:
		left_caller = step_ending(gauge_counters, u);
		break;
	case 48:
		portraits_start(u);
		break;
	case 50:
		portraits_run(u);
		break;
	case 52:
		portraits_wait(u);
		break;
	case 54:
		story_1_start();
		break;
	case 56:
		story_1_wait_layers();
		break;
	case 58:
		story_1_run(u);
		break;
	case 60:
		stage_1_setup();
		break;
	case 62:
		stage_1_title(u);
		break;
	case 64:
		left_caller = stage_1_begin(u, left_caller);
		break;
	case 66:
		stage_1_opening();
		break;
	case 68:
		left_caller = stage_1_play(gauge_counters, left_caller);
		break;
	case 70:
		stage_1_over();
		break;
	case 72:
		left_caller = stage_1_exit(left_caller);
		break;
	case 74:
		left_caller = stage_1_end_phase(u, left_caller);
		break;
	case 76:
		bonus_1_setup();
		break;
	case 78:
		bonus_1_draw();
		break;
	case 80:
		bonus_1_intro_phase(gauge_counters);
		break;
	case 82:
		bonus_1_run(gauge_counters);
		break;
	case 84:
		bonus_1_end_phase();
		break;
	case 86:
		stage_2_setup();
		break;
	case 88:
		stage_2_title(u);
		break;
	case 90:
		left_caller = stage_2_begin(u, left_caller);
		break;
	case 92:
		stage_2_opening();
		break;
	case 94:
		left_caller = stage_2_play(gauge_counters, left_caller);
		break;
	case 96:
		stage_2_after_boss();
		break;
	case 98:
		stage_2_closing_scene();
		break;
	case 100:
		stage_2_end_phase(u);
		break;
	case 102:
		stage_3_forest_setup();
		break;
	case 104:
		stage_3_forest_title(u);
		break;
	case 106:
		left_caller = stage_3_forest_begin(u, left_caller);
		break;
	case 108:
		stage_3_forest_opening();
		break;
	case 110:
		left_caller = stage_3_forest_play(gauge_counters, left_caller);
		break;
	case 112:
		left_caller = stage_3_forest_cleared(gauge_counters, left_caller);
		break;
	case 114:
		stage_3_forest_over();
		break;
	case 116:
		left_caller = stage_3_forest_exit(left_caller);
		break;
	case 118:
		left_caller = stage_3_forest_end_phase();
		break;
	case 120:
		stage_3_cemetery_setup();
		break;
	case 122:
		left_caller = stage_3_cemetery_begin(u, left_caller);
		break;
	case 124:
		stage_3_cemetery_opening();
		break;
	case 126:
		left_caller = stage_3_cemetery_play(gauge_counters, left_caller);
		break;
	}
	if (left_caller != 0u)
		return;
	award_enemy_points();
	in_attract = 0u;
}

/* The game's first phase, by game_step: the screen cleared, then the palettes */
uint32_t game_start_phase(uint16_t y, uint16_t u)
{
	uint32_t left_caller = 0;

	for (;;)
	{
		gauges_shown = 0u;
		switch ((int8_t)(uint8_t)((uint32_t)game_step << 1))
		{
		case 0:
			left_caller = 0u;
			game_start_clear();
			return left_caller;
		case 2:
			left_caller = 0u;
			game_start_palettes(u);
			return left_caller;
		case 4:
			return step_portraits(y, u);
		case 6:
			return step_story_1(y, u);
		case 8:
			return step_stage_1(y, u);
		case 10:
			return step_bonus_1(y, u);
		case 12:
			return step_stage_2(y, u);
		case 14:
			left_caller = 0u;
			step_story_2();
			return left_caller;
		case 16:
			return step_stage_3_forest(y, u);
		case 18:
			return step_stage_3_cemetery(y, u);
		case 20:
			return step_stage_4(y, u);
		case 22:
			return step_stage_5(y, u);
		case 24:
			left_caller = 0u;
			step_story_3();
			return left_caller;
		case 26:
			return step_stage_6(y, u);
		case 28:
			return step_bonus_2(y, u);
		case 30:
			return step_stage_7(y, u);
		case 32:
			left_caller = 0u;
			step_story_4();
			return left_caller;
		case 34:
			return step_stage_8(y, u);
		case 36:
			return step_ending(y, u);
		case 38:
			left_caller = 0u;
			portraits_start(u);
			return left_caller;
		case 40:
			left_caller = 0u;
			portraits_run(u);
			return left_caller;
		case 42:
			left_caller = 0u;
			portraits_wait(u);
			return left_caller;
		case 44:
			left_caller = 0u;
			story_1_start();
			return left_caller;
		case 46:
			left_caller = 0u;
			story_1_wait_layers();
			return left_caller;
		case 48:
			left_caller = 0u;
			story_1_run(u);
			return left_caller;
		case 50:
			left_caller = 0u;
			stage_1_setup();
			return left_caller;
		case 52:
			left_caller = 0u;
			stage_1_title(u);
			return left_caller;
		case 54:
			left_caller = 0u;
			return stage_1_begin(u, left_caller);
		case 56:
			left_caller = 0u;
			stage_1_opening();
			return left_caller;
		case 58:
			left_caller = 0u;
			return stage_1_play(y, left_caller);
		case 60:
			left_caller = 0u;
			stage_1_over();
			return left_caller;
		case 62:
			left_caller = 0u;
			return stage_1_exit(left_caller);
		case 64:
			left_caller = 0u;
			return stage_1_end_phase(u, left_caller);
		case 66:
			left_caller = 0u;
			bonus_1_setup();
			return left_caller;
		case 68:
			left_caller = 0u;
			bonus_1_draw();
			return left_caller;
		case 70:
			left_caller = 0u;
			bonus_1_intro_phase(y);
			return left_caller;
		case 72:
			left_caller = 0u;
			bonus_1_run(y);
			return left_caller;
		case 74:
			left_caller = 0u;
			bonus_1_end_phase();
			return left_caller;
		case 76:
			left_caller = 0u;
			stage_2_setup();
			return left_caller;
		case 78:
			left_caller = 0u;
			stage_2_title(u);
			return left_caller;
		case 80:
			left_caller = 0u;
			return stage_2_begin(u, left_caller);
		case 82:
			left_caller = 0u;
			stage_2_opening();
			return left_caller;
		case 84:
			left_caller = 0u;
			return stage_2_play(y, left_caller);
		case 86:
			left_caller = 0u;
			stage_2_after_boss();
			return left_caller;
		case 88:
			left_caller = 0u;
			stage_2_closing_scene();
			return left_caller;
		case 90:
			left_caller = 0u;
			stage_2_end_phase(u);
			return left_caller;
		case 92:
			left_caller = 0u;
			stage_3_forest_setup();
			return left_caller;
		case 94:
			left_caller = 0u;
			stage_3_forest_title(u);
			return left_caller;
		case 96:
			left_caller = 0u;
			return stage_3_forest_begin(u, left_caller);
		case 98:
			left_caller = 0u;
			stage_3_forest_opening();
			return left_caller;
		case 100:
			left_caller = 0u;
			return stage_3_forest_play(y, left_caller);
		case 102:
			left_caller = 0u;
			return stage_3_forest_cleared(y, left_caller);
		case 104:
			left_caller = 0u;
			stage_3_forest_over();
			return left_caller;
		case 106:
			left_caller = 0u;
			return stage_3_forest_exit(left_caller);
		case 108:
			return stage_3_forest_end_phase();
		case 110:
			left_caller = 0u;
			stage_3_cemetery_setup();
			return left_caller;
		case 112:
			left_caller = 0u;
			return stage_3_cemetery_begin(u, left_caller);
		case 114:
			left_caller = 0u;
			stage_3_cemetery_opening();
			return left_caller;
		case 116:
			left_caller = 0u;
			return stage_3_cemetery_play(y, left_caller);
		case 118:
			left_caller = 0u;
			stage_3_cemetery_over();
			return left_caller;
		case 120:
			left_caller = 0u;
			return stage_3_cemetery_exit(left_caller);
		case 122:
			left_caller = 0u;
			return stage_3_cemetery_end_phase(u, left_caller);
		case 124:
			left_caller = 0u;
			stage_4_setup();
			return left_caller;
		case 126:
			break;
		case -10:
			continue;
		case -8:
			return game_run_step(y, u);
		case -6:
			left_caller = 0u;
			game_continue_phase();
			return left_caller;
		case -4:
			left_caller = 0u;
			return game_over_phase(y, u, left_caller);
		case -2:
			left_caller = 0u;
			return name_entry_phase(y, u, left_caller);
		}
		break;
	}
	left_caller = 0u;
	stage_4_title(u);
	return left_caller;
}

/* Clears the sprites, the scores and the sound and queues the tile layers' clear as a game starts */
void game_start_clear(void)
{
	uint32_t carry = 0;
	uint16_t command = 0, ignored16 = 0, ignored16_2 = 0, job = 0;
	uint8_t t1 = 0;

	if (layer_clear_pending != 0u)
		return;
	t1 = io_read8(0x1C80u);
	io_write8(0x1C80u, 0u);
	job = 0u;
	queue_job(job);
	clear_sprites(&ignored16, &ignored16_2);
	reset_for_game();
	command = 0u;
	carry = queue_sound_always(command);
	game_step++;
}

/* Once the layers are clear, sets the background colour and the palettes and moves the game on to its
   steps, from the portraits */
void game_start_palettes(uint16_t palette_job)
{
	uint16_t ignored16 = 0, request = 0;

	if (layer_clear_pending != 0u)
		return;
	palette_request_kind = 3u;
	request = 0u;
	palette_request(request, &ignored16, &palette_job);
	palette_request_kind = 1u;
	request = 0xF00u;
	palette_request(request, &ignored16, &palette_job);
	mode_phase++;
	game_step = 0u;
	step_phase = 0u;
	step_subphase = 0u;
	step_countdown = 0u;
}

/* Runs the game's step, by game_step: the portraits, the stories, the stages, the bonus stages and the
   ending */
uint32_t game_run_step(uint16_t y, uint16_t u)
{
	uint32_t left_caller = 0;

	for (;;)
	{
		switch ((int8_t)(uint8_t)((uint32_t)game_step << 1))
		{
		case 0:
			return step_portraits(y, u);
		case 2:
			return step_story_1(y, u);
		case 4:
			return step_stage_1(y, u);
		case 6:
			return step_bonus_1(y, u);
		case 8:
			return step_stage_2(y, u);
		case 10:
			left_caller = 0u;
			step_story_2();
			return left_caller;
		case 12:
			return step_stage_3_forest(y, u);
		case 14:
			return step_stage_3_cemetery(y, u);
		case 16:
			return step_stage_4(y, u);
		case 18:
			return step_stage_5(y, u);
		case 20:
			left_caller = 0u;
			step_story_3();
			return left_caller;
		case 22:
			return step_stage_6(y, u);
		case 24:
			return step_bonus_2(y, u);
		case 26:
			return step_stage_7(y, u);
		case 28:
			left_caller = 0u;
			step_story_4();
			return left_caller;
		case 30:
			return step_stage_8(y, u);
		case 32:
			return step_ending(y, u);
		case 34:
			left_caller = 0u;
			portraits_start(u);
			return left_caller;
		case 36:
			left_caller = 0u;
			portraits_run(u);
			return left_caller;
		case 38:
			left_caller = 0u;
			portraits_wait(u);
			return left_caller;
		case 40:
			left_caller = 0u;
			story_1_start();
			return left_caller;
		case 42:
			left_caller = 0u;
			story_1_wait_layers();
			return left_caller;
		case 44:
			left_caller = 0u;
			story_1_run(u);
			return left_caller;
		case 46:
			left_caller = 0u;
			stage_1_setup();
			return left_caller;
		case 48:
			left_caller = 0u;
			stage_1_title(u);
			return left_caller;
		case 50:
			left_caller = 0u;
			return stage_1_begin(u, left_caller);
		case 52:
			left_caller = 0u;
			stage_1_opening();
			return left_caller;
		case 54:
			left_caller = 0u;
			return stage_1_play(y, left_caller);
		case 56:
			left_caller = 0u;
			stage_1_over();
			return left_caller;
		case 58:
			left_caller = 0u;
			return stage_1_exit(left_caller);
		case 60:
			left_caller = 0u;
			return stage_1_end_phase(u, left_caller);
		case 62:
			left_caller = 0u;
			bonus_1_setup();
			return left_caller;
		case 64:
			left_caller = 0u;
			bonus_1_draw();
			return left_caller;
		case 66:
			left_caller = 0u;
			bonus_1_intro_phase(y);
			return left_caller;
		case 68:
			left_caller = 0u;
			bonus_1_run(y);
			return left_caller;
		case 70:
			left_caller = 0u;
			bonus_1_end_phase();
			return left_caller;
		case 72:
			left_caller = 0u;
			stage_2_setup();
			return left_caller;
		case 74:
			left_caller = 0u;
			stage_2_title(u);
			return left_caller;
		case 76:
			left_caller = 0u;
			return stage_2_begin(u, left_caller);
		case 78:
			left_caller = 0u;
			stage_2_opening();
			return left_caller;
		case 80:
			left_caller = 0u;
			return stage_2_play(y, left_caller);
		case 82:
			left_caller = 0u;
			stage_2_after_boss();
			return left_caller;
		case 84:
			left_caller = 0u;
			stage_2_closing_scene();
			return left_caller;
		case 86:
			left_caller = 0u;
			stage_2_end_phase(u);
			return left_caller;
		case 88:
			left_caller = 0u;
			stage_3_forest_setup();
			return left_caller;
		case 90:
			left_caller = 0u;
			stage_3_forest_title(u);
			return left_caller;
		case 92:
			left_caller = 0u;
			return stage_3_forest_begin(u, left_caller);
		case 94:
			left_caller = 0u;
			stage_3_forest_opening();
			return left_caller;
		case 96:
			left_caller = 0u;
			return stage_3_forest_play(y, left_caller);
		case 98:
			left_caller = 0u;
			return stage_3_forest_cleared(y, left_caller);
		case 100:
			left_caller = 0u;
			stage_3_forest_over();
			return left_caller;
		case 102:
			left_caller = 0u;
			return stage_3_forest_exit(left_caller);
		case 104:
			return stage_3_forest_end_phase();
		case 106:
			left_caller = 0u;
			stage_3_cemetery_setup();
			return left_caller;
		case 108:
			left_caller = 0u;
			return stage_3_cemetery_begin(u, left_caller);
		case 110:
			left_caller = 0u;
			stage_3_cemetery_opening();
			return left_caller;
		case 112:
			left_caller = 0u;
			return stage_3_cemetery_play(y, left_caller);
		case 114:
			left_caller = 0u;
			stage_3_cemetery_over();
			return left_caller;
		case 116:
			left_caller = 0u;
			return stage_3_cemetery_exit(left_caller);
		case 118:
			left_caller = 0u;
			return stage_3_cemetery_end_phase(u, left_caller);
		case 120:
			left_caller = 0u;
			stage_4_setup();
			return left_caller;
		case 122:
			left_caller = 0u;
			stage_4_title(u);
			return left_caller;
		case 124:
			left_caller = 0u;
			return stage_4_begin(u, left_caller);
		case 126:
			break;
		case -14:
			return game_start_phase(y, u);
		case -12:
			continue;
		case -10:
			left_caller = 0u;
			game_continue_phase();
			return left_caller;
		case -8:
			left_caller = 0u;
			return game_over_phase(y, u, left_caller);
		case -6:
			left_caller = 0u;
			return name_entry_phase(y, u, left_caller);
		case -4:
			left_caller = 0u;
			game_start_clear();
			return left_caller;
		case -2:
			left_caller = 0u;
			game_start_palettes(u);
			return left_caller;
		}
		break;
	}
	left_caller = 0u;
	stage_4_opening();
	return left_caller;
}

/* The game's end: back to the attract, or a new game from the first story for the players who joined
   meanwhile */
uint16_t end_game(void)
{
	uint8_t players_left = 0;
	uint16_t health_address = 0, ignored16 = 0, play_status = 0, request = 0, u = 0;
	uint8_t t1 = 0;

	mode_step = 0u;
	mode_phase = 0u;
	game_step = 0u;
	step_phase = 0u;
	step_subphase = 0u;
	step_countdown = 0u;
	players_going_on = 0u;
	play_status = marge_play_status_ADDRESS;
	health_address = 0x49D2u;
	players_left = 4u;
	do
	{
		if (mem_read8(play_status) == 2u)
		{
			mem_write8(health_address, 0x28u);
			players_going_on++;
		}
		play_status++;
		health_address += 8u;
		t1 = players_left;
		players_left = t1 - 1u;
	} while (t1 != 1u);
	if (players_going_on != 0u)
	{
		u = reset_for_game();
		palette_request_kind = 1u;
		request = 0xF00u;
		palette_request(request, &ignored16, &u);
		game_mode = 2u;
		mode_phase = 1u;
		game_step = 1u;
		return u;
	}
	u = reset_for_play();
	game_mode = 1u;
	marge_state = 0u;
	homer_state = 0u;
	bart_state = 0u;
	lisa_state = 0u;
	return u;
}
