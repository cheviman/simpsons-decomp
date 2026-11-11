/**
 *    Name:        scenes/stage_ends.c
 *    Description: the bank's jump table, then the scripted scenes at the ends of stages 1, 2, 5 and 6 and after bonus 2
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    10-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the game's 053248 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

/* Runs stage 1's closing scene by its state: the police car comes in (Downtown). */
void stage_1_end(uint16_t u)
{
	uint16_t ignored16 = 0, ignored16_2 = 0, scene_steps = 0;
	uint8_t scene_step = 0;

	scene_steps = stage_1_end_states_ADDRESS;
	scene_step = io_read8(scene_state);
	switch ((int8_t)(uint8_t)((uint32_t)scene_step << 1))
	{
	case 0:
		stage_1_end_start();
		return;
	case 2:
		stage_1_end_put_police_car(u);
		return;
	case 4:
		stage_1_end_move_police_car(scene_steps);
		return;
	case 6:
		stage_1_end_wait();
		return;
	case 8:
		stage_1_end_car_sound(scene_steps);
		return;
	case 10:
	case 38:
		scene_clear(&ignored16, &u);
		return;
	case 12:
		stage_2_end_set_up(&ignored16, &ignored16_2);
		return;
	case 14:
	case 42:
		stage_end_jump_away(&ignored16, &u);
		return;
	case 16:
		stage_2_end_show_area_3(&ignored16, &ignored16_2);
		return;
	case 18:
		stage_2_end_put_players(scene_steps);
		return;
	case 20:
	case 22:
		stage_2_end_players_look_around(&ignored16, &u);
		return;
	case 24:
		scene_end(&ignored16, &ignored16_2);
		return;
	case 26:
		stage_end_put_jumpers(scene_steps);
		return;
	case 28:
		stage_end_run_jumpers(&ignored16, &ignored16_2);
		return;
	case 30:
		stage_end_jumper_wait(scene_steps, u);
		return;
	case 32:
		stage_end_jumper_fly(scene_steps);
		return;
	case 34:
		stage_end_jumper_last_leg(scene_steps);
		return;
	case 36:
		stage_end_jumper_vanish(scene_steps);
		return;
	case 40:
		stage_5_end_set_up(&ignored16, &u);
		return;
	case 44:
		stage_5_end_show_players(&ignored16, &u);
		return;
	case 46:
		stage_5_end_fade(u);
		return;
	case 48:
		stage_5_end_finish(&ignored16, &ignored16_2);
		return;
	case 50:
		stage_6_end_start();
		return;
	case 52:
		stage_6_end_effect(u);
		return;
	case 54:
		stage_6_end_finish(&ignored16, &ignored16_2);
		return;
	case 56:
		stage_6_wake_set_up(&ignored16, &u);
		return;
	case 58:
		stage_6_wake_show_players(&ignored16, &u);
		return;
	case 60:
		stage_6_wake_start();
		return;
	case 62:
		stage_6_wake_wave(&ignored16, &ignored16_2);
		return;
	case 64:
		post_bonus_2_scene_set_up(&ignored16, &u);
		return;
	case 66:
		post_bonus_2_scene_show(&scene_steps, &ignored16_2);
		return;
	case 68:
		post_bonus_2_scene_wait();
		return;
	case 70:
		post_bonus_2_scene_pan();
		return;
	case 72:
		post_bonus_2_scene_finish();
		return;
	case 74:
		stage_7_scene_set_up();
		return;
	case 76:
		stage_7_scene_wait_scroll();
		return;
	case 78:
		stage_7_scene_wait_signal();
		return;
	case 80:
		stage_7_scene_lift(&ignored16, &ignored16_2);
		return;
	case 82:
		stage_7_scene_wait_train();
		return;
	case 84:
		stage_7_scene_put_chain(&ignored16, &ignored16_2);
		return;
	case 86:
		stage_7_scene_move_chain(&ignored16, &ignored16_2);
		return;
	case 88:
		stage_7_scene_chain_done();
		return;
	case 90:
		stage_7_end_set_up(&ignored16, &u);
		return;
	case 92:
		stage_7_end_show(&ignored16, &ignored16_2);
		return;
	case 94:
		stage_7_end_board(scene_steps);
		return;
	case 96:
		stage_7_end_take_off();
		return;
	case 98:
		stage_7_end_slow_down(&ignored16, &ignored16_2);
		return;
	case 100:
		stage_7_end_finish(&ignored16, &ignored16_2);
		return;
	case 102:
		stage_8_start_set_up(&ignored16, &u);
		return;
	case 104:
		stage_8_start_show(&ignored16, &ignored16_2);
		return;
	case 106:
		stage_8_start_descend(&ignored16, &ignored16_2);
		return;
	case 108:
		stage_8_start_stop(&ignored16, &ignored16_2);
		return;
	case 110:
		stage_8_start_landing();
		return;
	case 112:
		stage_8_start_run_off(&ignored16, &ignored16_2);
		return;
	case 114:
		stage_8_start_wait_end(&ignored16, &ignored16_2);
		return;
	case 116:
		stage_8_start_player_ride(scene_steps);
		return;
	case 118:
		stage_8_start_player_drop(scene_steps);
		return;
	case 120:
		stage_8_start_player_look(scene_steps);
		return;
	case 122:
		stage_8_start_player_turn(scene_steps);
		return;
	case 124:
		stage_8_start_player_run(scene_steps);
		return;
	case 126:
		stage_8_start_player_gone(scene_steps);
		return;
	}
}

/* Runs stage 2's closing scene by its state: the players jump off after the kind-9C character (who runs
   off at the stages' ends and is stage 8's first boss), then Krustyland's area 3. */
void stage_2_end(uint16_t u)
{
	uint16_t ignored16 = 0, ignored16_2 = 0, scene_steps = 0;
	uint8_t scene_step = 0;

	gauges_shown = 0u;
	scene_steps = stage_2_end_states_ADDRESS;
	scene_step = io_read8(scene_state);
	switch ((int8_t)(uint8_t)((uint32_t)scene_step << 1))
	{
	case 0:
	case 28:
		scene_clear(&ignored16, &u);
		return;
	case 2:
		stage_2_end_set_up(&ignored16, &ignored16_2);
		return;
	case 4:
	case 32:
		stage_end_jump_away(&ignored16, &u);
		return;
	case 6:
		stage_2_end_show_area_3(&ignored16, &ignored16_2);
		return;
	case 8:
		stage_2_end_put_players(scene_steps);
		return;
	case 10:
	case 12:
		stage_2_end_players_look_around(&ignored16, &u);
		return;
	case 14:
		scene_end(&ignored16, &ignored16_2);
		return;
	case 16:
		stage_end_put_jumpers(scene_steps);
		return;
	case 18:
		stage_end_run_jumpers(&ignored16, &ignored16_2);
		return;
	case 20:
		stage_end_jumper_wait(scene_steps, u);
		return;
	case 22:
		stage_end_jumper_fly(scene_steps);
		return;
	case 24:
		stage_end_jumper_last_leg(scene_steps);
		return;
	case 26:
		stage_end_jumper_vanish(scene_steps);
		return;
	case 30:
		stage_5_end_set_up(&ignored16, &u);
		return;
	case 34:
		stage_5_end_show_players(&ignored16, &u);
		return;
	case 36:
		stage_5_end_fade(u);
		return;
	case 38:
		stage_5_end_finish(&ignored16, &ignored16_2);
		return;
	case 40:
		stage_6_end_start();
		return;
	case 42:
		stage_6_end_effect(u);
		return;
	case 44:
		stage_6_end_finish(&ignored16, &ignored16_2);
		return;
	case 46:
		stage_6_wake_set_up(&ignored16, &u);
		return;
	case 48:
		stage_6_wake_show_players(&ignored16, &u);
		return;
	case 50:
		stage_6_wake_start();
		return;
	case 52:
		stage_6_wake_wave(&ignored16, &ignored16_2);
		return;
	case 54:
		post_bonus_2_scene_set_up(&ignored16, &u);
		return;
	case 56:
		post_bonus_2_scene_show(&scene_steps, &ignored16_2);
		return;
	case 58:
		post_bonus_2_scene_wait();
		return;
	case 60:
		post_bonus_2_scene_pan();
		return;
	case 62:
		post_bonus_2_scene_finish();
		return;
	case 64:
		stage_7_scene_set_up();
		return;
	case 66:
		stage_7_scene_wait_scroll();
		return;
	case 68:
		stage_7_scene_wait_signal();
		return;
	case 70:
		stage_7_scene_lift(&ignored16, &ignored16_2);
		return;
	case 72:
		stage_7_scene_wait_train();
		return;
	case 74:
		stage_7_scene_put_chain(&ignored16, &ignored16_2);
		return;
	case 76:
		stage_7_scene_move_chain(&ignored16, &ignored16_2);
		return;
	case 78:
		stage_7_scene_chain_done();
		return;
	case 80:
		stage_7_end_set_up(&ignored16, &u);
		return;
	case 82:
		stage_7_end_show(&ignored16, &ignored16_2);
		return;
	case 84:
		stage_7_end_board(scene_steps);
		return;
	case 86:
		stage_7_end_take_off();
		return;
	case 88:
		stage_7_end_slow_down(&ignored16, &ignored16_2);
		return;
	case 90:
		stage_7_end_finish(&ignored16, &ignored16_2);
		return;
	case 92:
		stage_8_start_set_up(&ignored16, &u);
		return;
	case 94:
		stage_8_start_show(&ignored16, &ignored16_2);
		return;
	case 96:
		stage_8_start_descend(&ignored16, &ignored16_2);
		return;
	case 98:
		stage_8_start_stop(&ignored16, &ignored16_2);
		return;
	case 100:
		stage_8_start_landing();
		return;
	case 102:
		stage_8_start_run_off(&ignored16, &ignored16_2);
		return;
	case 104:
		stage_8_start_wait_end(&ignored16, &ignored16_2);
		return;
	case 106:
		stage_8_start_player_ride(scene_steps);
		return;
	case 108:
		stage_8_start_player_drop(scene_steps);
		return;
	case 110:
		stage_8_start_player_look(scene_steps);
		return;
	case 112:
		stage_8_start_player_turn(scene_steps);
		return;
	case 114:
		stage_8_start_player_run(scene_steps);
		return;
	case 116:
		stage_8_start_player_gone(scene_steps);
		return;
	case 118:
		stage_8_end_set_up(&ignored16, &ignored16_2);
		return;
	case 120:
		stage_8_end_show(&ignored16, &ignored16_2);
		return;
	case 122:
		stage_8_end_hold();
		return;
	case 124:
		stage_8_end_switch_view(&ignored16, &ignored16_2);
		return;
	case 126:
		stage_8_end_show_kind_13(&ignored16, &ignored16_2);
		return;
	case -10:
		stage_1_end_start();
		return;
	case -8:
		stage_1_end_put_police_car(u);
		return;
	case -6:
		stage_1_end_move_police_car(scene_steps);
		return;
	case -4:
		stage_1_end_wait();
		return;
	case -2:
		stage_1_end_car_sound(scene_steps);
		return;
	}
}

/* Runs stage 5's closing scene by its state, in the gorge. */
void stage_5_end(uint16_t u)
{
	uint16_t ignored16 = 0, ignored16_2 = 0, scene_steps = 0;
	uint8_t scene_step = 0;

	gauges_shown = 0u;
	scene_steps = stage_5_end_states_ADDRESS;
	scene_step = io_read8(scene_state);
	switch ((int8_t)(uint8_t)((uint32_t)scene_step << 1))
	{
	case -28:
	case 0:
		scene_clear(&ignored16, &u);
		return;
	case 2:
		stage_5_end_set_up(&ignored16, &u);
		return;
	case -24:
	case 4:
		stage_end_jump_away(&ignored16, &u);
		return;
	case 6:
		stage_5_end_show_players(&ignored16, &u);
		return;
	case 8:
		stage_5_end_fade(u);
		return;
	case 10:
		stage_5_end_finish(&ignored16, &ignored16_2);
		return;
	case 12:
		stage_6_end_start();
		return;
	case 14:
		stage_6_end_effect(u);
		return;
	case 16:
		stage_6_end_finish(&ignored16, &ignored16_2);
		return;
	case 18:
		stage_6_wake_set_up(&ignored16, &u);
		return;
	case 20:
		stage_6_wake_show_players(&ignored16, &u);
		return;
	case 22:
		stage_6_wake_start();
		return;
	case 24:
		stage_6_wake_wave(&ignored16, &ignored16_2);
		return;
	case 26:
		post_bonus_2_scene_set_up(&ignored16, &u);
		return;
	case 28:
		post_bonus_2_scene_show(&scene_steps, &ignored16_2);
		return;
	case 30:
		post_bonus_2_scene_wait();
		return;
	case 32:
		post_bonus_2_scene_pan();
		return;
	case 34:
		post_bonus_2_scene_finish();
		return;
	case 36:
		stage_7_scene_set_up();
		return;
	case 38:
		stage_7_scene_wait_scroll();
		return;
	case 40:
		stage_7_scene_wait_signal();
		return;
	case 42:
		stage_7_scene_lift(&ignored16, &ignored16_2);
		return;
	case 44:
		stage_7_scene_wait_train();
		return;
	case 46:
		stage_7_scene_put_chain(&ignored16, &ignored16_2);
		return;
	case 48:
		stage_7_scene_move_chain(&ignored16, &ignored16_2);
		return;
	case 50:
		stage_7_scene_chain_done();
		return;
	case 52:
		stage_7_end_set_up(&ignored16, &u);
		return;
	case 54:
		stage_7_end_show(&ignored16, &ignored16_2);
		return;
	case 56:
		stage_7_end_board(scene_steps);
		return;
	case 58:
		stage_7_end_take_off();
		return;
	case 60:
		stage_7_end_slow_down(&ignored16, &ignored16_2);
		return;
	case 62:
		stage_7_end_finish(&ignored16, &ignored16_2);
		return;
	case 64:
		stage_8_start_set_up(&ignored16, &u);
		return;
	case 66:
		stage_8_start_show(&ignored16, &ignored16_2);
		return;
	case 68:
		stage_8_start_descend(&ignored16, &ignored16_2);
		return;
	case 70:
		stage_8_start_stop(&ignored16, &ignored16_2);
		return;
	case 72:
		stage_8_start_landing();
		return;
	case 74:
		stage_8_start_run_off(&ignored16, &ignored16_2);
		return;
	case 76:
		stage_8_start_wait_end(&ignored16, &ignored16_2);
		return;
	case 78:
		stage_8_start_player_ride(scene_steps);
		return;
	case 80:
		stage_8_start_player_drop(scene_steps);
		return;
	case 82:
		stage_8_start_player_look(scene_steps);
		return;
	case 84:
		stage_8_start_player_turn(scene_steps);
		return;
	case 86:
		stage_8_start_player_run(scene_steps);
		return;
	case 88:
		stage_8_start_player_gone(scene_steps);
		return;
	case 90:
		stage_8_end_set_up(&ignored16, &ignored16_2);
		return;
	case 92:
		stage_8_end_show(&ignored16, &ignored16_2);
		return;
	case 94:
		stage_8_end_hold();
		return;
	case 96:
		stage_8_end_switch_view(&ignored16, &ignored16_2);
		return;
	case 98:
		stage_8_end_show_kind_13(&ignored16, &ignored16_2);
		return;
	case 100:
		stage_8_end_reunion(&ignored16, &u);
		return;
	case 102:
		stage_8_end_run_family(&ignored16, &u);
		return;
	case 104:
		stage_8_end_finish(&ignored16, &ignored16_2);
		return;
	case 106:
		stage_8_end_actor_rest();
		return;
	case 108:
		stage_8_end_walker(&scene_steps, &ignored16_2);
		return;
	case 110:
		stage_8_end_maggie_taker(&scene_steps, &ignored16_2);
		return;
	case 112:
		stage_8_end_extra(&scene_steps, &ignored16_2);
		return;
	case 114:
		stage_8_end_slow_extra(&scene_steps, &ignored16_2);
		return;
	case 116:
	case 124:
		stage_8_end_actor_start(scene_steps);
		return;
	case 118:
		stage_8_end_walker_go(scene_steps);
		return;
	case 120:
		stage_8_end_walker_arrive(scene_steps);
		return;
	case 122:
		stage_8_end_actor_done();
		return;
	case 126:
		stage_8_end_extra_go(scene_steps);
		return;
	case -38:
		stage_1_end_start();
		return;
	case -36:
		stage_1_end_put_police_car(u);
		return;
	case -34:
		stage_1_end_move_police_car(scene_steps);
		return;
	case -32:
		stage_1_end_wait();
		return;
	case -30:
		stage_1_end_car_sound(scene_steps);
		return;
	case -26:
		stage_2_end_set_up(&ignored16, &ignored16_2);
		return;
	case -22:
		stage_2_end_show_area_3(&ignored16, &ignored16_2);
		return;
	case -20:
		stage_2_end_put_players(scene_steps);
		return;
	case -18:
	case -16:
		stage_2_end_players_look_around(&ignored16, &u);
		return;
	case -14:
		scene_end(&ignored16, &ignored16_2);
		return;
	case -12:
		stage_end_put_jumpers(scene_steps);
		return;
	case -10:
		stage_end_run_jumpers(&ignored16, &ignored16_2);
		return;
	case -8:
		stage_end_jumper_wait(scene_steps, u);
		return;
	case -6:
		stage_end_jumper_fly(scene_steps);
		return;
	case -4:
		stage_end_jumper_last_leg(scene_steps);
		return;
	case -2:
		stage_end_jumper_vanish(scene_steps);
		return;
	}
}

/* Runs the scene after bonus 2 by its state: the view pans up and the step goes on. */
void post_bonus_2_scene(uint16_t u)
{
	uint16_t ignored16 = 0, ignored16_2 = 0, scene_steps = 0;
	uint8_t scene_step = 0;

	gauges_shown = 0u;
	scene_steps = post_bonus_2_scene_states_ADDRESS;
	scene_step = io_read8(scene_state);
	switch ((int8_t)(uint8_t)((uint32_t)scene_step << 1))
	{
	case 0:
		post_bonus_2_scene_set_up(&ignored16, &u);
		return;
	case 2:
		post_bonus_2_scene_show(&scene_steps, &ignored16_2);
		return;
	case 4:
		post_bonus_2_scene_wait();
		return;
	case 6:
		post_bonus_2_scene_pan();
		return;
	case 8:
		post_bonus_2_scene_finish();
		return;
	case 10:
		stage_7_scene_set_up();
		return;
	case 12:
		stage_7_scene_wait_scroll();
		return;
	case 14:
		stage_7_scene_wait_signal();
		return;
	case 16:
		stage_7_scene_lift(&ignored16, &ignored16_2);
		return;
	case 18:
		stage_7_scene_wait_train();
		return;
	case 20:
		stage_7_scene_put_chain(&ignored16, &ignored16_2);
		return;
	case 22:
		stage_7_scene_move_chain(&ignored16, &ignored16_2);
		return;
	case 24:
		stage_7_scene_chain_done();
		return;
	case 26:
		stage_7_end_set_up(&ignored16, &u);
		return;
	case 28:
		stage_7_end_show(&ignored16, &ignored16_2);
		return;
	case 30:
		stage_7_end_board(scene_steps);
		return;
	case 32:
		stage_7_end_take_off();
		return;
	case 34:
		stage_7_end_slow_down(&ignored16, &ignored16_2);
		return;
	case 36:
		stage_7_end_finish(&ignored16, &ignored16_2);
		return;
	case 38:
		stage_8_start_set_up(&ignored16, &u);
		return;
	case 40:
		stage_8_start_show(&ignored16, &ignored16_2);
		return;
	case 42:
		stage_8_start_descend(&ignored16, &ignored16_2);
		return;
	case 44:
		stage_8_start_stop(&ignored16, &ignored16_2);
		return;
	case 46:
		stage_8_start_landing();
		return;
	case 48:
		stage_8_start_run_off(&ignored16, &ignored16_2);
		return;
	case 50:
		stage_8_start_wait_end(&ignored16, &ignored16_2);
		return;
	case 52:
		stage_8_start_player_ride(scene_steps);
		return;
	case 54:
		stage_8_start_player_drop(scene_steps);
		return;
	case 56:
		stage_8_start_player_look(scene_steps);
		return;
	case 58:
		stage_8_start_player_turn(scene_steps);
		return;
	case 60:
		stage_8_start_player_run(scene_steps);
		return;
	case 62:
		stage_8_start_player_gone(scene_steps);
		return;
	case 64:
		stage_8_end_set_up(&ignored16, &ignored16_2);
		return;
	case 66:
		stage_8_end_show(&ignored16, &ignored16_2);
		return;
	case 68:
		stage_8_end_hold();
		return;
	case 70:
		stage_8_end_switch_view(&ignored16, &ignored16_2);
		return;
	case 72:
		stage_8_end_show_kind_13(&ignored16, &ignored16_2);
		return;
	case 74:
		stage_8_end_reunion(&ignored16, &u);
		return;
	case 76:
		stage_8_end_run_family(&ignored16, &u);
		return;
	case 78:
		stage_8_end_finish(&ignored16, &ignored16_2);
		return;
	case 80:
		stage_8_end_actor_rest();
		return;
	case 82:
		stage_8_end_walker(&scene_steps, &ignored16_2);
		return;
	case 84:
		stage_8_end_maggie_taker(&scene_steps, &ignored16_2);
		return;
	case 86:
		stage_8_end_extra(&scene_steps, &ignored16_2);
		return;
	case 88:
		stage_8_end_slow_extra(&scene_steps, &ignored16_2);
		return;
	case 90:
	case 98:
	case 106:
		stage_8_end_actor_start(scene_steps);
		return;
	case 92:
		stage_8_end_walker_go(scene_steps);
		return;
	case 94:
		stage_8_end_walker_arrive(scene_steps);
		return;
	case 96:
	case 104:
	case 112:
		stage_8_end_actor_done();
		return;
	case 100:
		stage_8_end_extra_go(scene_steps);
		return;
	case 102:
	case 110:
		stage_8_end_extra_arrive(scene_steps);
		return;
	case 108:
		stage_8_end_slow_extra_go(scene_steps);
		return;
	case 114:
		stage_8_end_taker_wait(scene_steps);
		return;
	case 116:
		stage_8_end_take_maggie(scene_steps);
		return;
	case 118:
		stage_8_end_holding_maggie(scene_steps);
		return;
	case 120:
		stage_8_end_taker_done();
		return;
	case -64:
		stage_1_end_start();
		return;
	case -62:
		stage_1_end_put_police_car(u);
		return;
	case -60:
		stage_1_end_move_police_car(scene_steps);
		return;
	case -58:
		stage_1_end_wait();
		return;
	case -56:
		stage_1_end_car_sound(scene_steps);
		return;
	case -54:
	case -26:
		scene_clear(&ignored16, &u);
		return;
	case -52:
		stage_2_end_set_up(&ignored16, &ignored16_2);
		return;
	case -50:
	case -22:
		stage_end_jump_away(&ignored16, &u);
		return;
	case -48:
		stage_2_end_show_area_3(&ignored16, &ignored16_2);
		return;
	case -46:
		stage_2_end_put_players(scene_steps);
		return;
	case -44:
	case -42:
		stage_2_end_players_look_around(&ignored16, &u);
		return;
	case -40:
		scene_end(&ignored16, &ignored16_2);
		return;
	case -38:
		stage_end_put_jumpers(scene_steps);
		return;
	case -36:
		stage_end_run_jumpers(&ignored16, &ignored16_2);
		return;
	case -34:
		stage_end_jumper_wait(scene_steps, u);
		return;
	case -32:
		stage_end_jumper_fly(scene_steps);
		return;
	case -30:
		stage_end_jumper_last_leg(scene_steps);
		return;
	case -28:
		stage_end_jumper_vanish(scene_steps);
		return;
	case -24:
		stage_5_end_set_up(&ignored16, &u);
		return;
	case -20:
		stage_5_end_show_players(&ignored16, &u);
		return;
	case -18:
		stage_5_end_fade(u);
		return;
	case -16:
		stage_5_end_finish(&ignored16, &ignored16_2);
		return;
	case -14:
		stage_6_end_start();
		return;
	case -12:
		stage_6_end_effect(u);
		return;
	case -10:
		stage_6_end_finish(&ignored16, &ignored16_2);
		return;
	case -8:
		stage_6_wake_set_up(&ignored16, &u);
		return;
	case -6:
		stage_6_wake_show_players(&ignored16, &u);
		return;
	case -4:
		stage_6_wake_start();
		return;
	case -2:
		stage_6_wake_wave(&ignored16, &ignored16_2);
		return;
	}
}

/* Runs stage 7's scripted scene: two tracks at once, by the scene's state and sub-state. */
uint16_t stage_7_scene(uint16_t u)
{
	uint16_t ignored16 = 0, scene_steps = 0, u_2 = 0;
	uint8_t scene_step = 0, scene_substep = 0;

	scene_steps = stage_7_scene_states_ADDRESS;
	scene_step = io_read8(scene_state);
	switch ((int8_t)(uint8_t)((uint32_t)scene_step << 1))
	{
	case 0:
		stage_7_scene_set_up();
		break;
	case 2:
		stage_7_scene_wait_scroll();
		break;
	case 4:
		stage_7_scene_wait_signal();
		break;
	case 6:
		stage_7_scene_lift(&scene_steps, &u);
		break;
	case 8:
		stage_7_scene_wait_train();
		break;
	case 10:
		stage_7_scene_put_chain(&scene_steps, &u);
		break;
	case 12:
		stage_7_scene_move_chain(&scene_steps, &u);
		break;
	case 14:
		stage_7_scene_chain_done();
		break;
	case 16:
		stage_7_end_set_up(&scene_steps, &u);
		break;
	case 18:
		stage_7_end_show(&scene_steps, &u);
		break;
	case 20:
		stage_7_end_board(scene_steps);
		break;
	case 22:
		stage_7_end_take_off();
		break;
	case 24:
		stage_7_end_slow_down(&scene_steps, &u);
		break;
	case 26:
		stage_7_end_finish(&scene_steps, &u);
		break;
	case 28:
		stage_8_start_set_up(&scene_steps, &u);
		break;
	case 30:
		stage_8_start_show(&scene_steps, &u);
		break;
	case 32:
		stage_8_start_descend(&scene_steps, &u);
		break;
	case 34:
		stage_8_start_stop(&scene_steps, &u);
		break;
	case 36:
		stage_8_start_landing();
		break;
	case 38:
		stage_8_start_run_off(&scene_steps, &u);
		break;
	case 40:
		stage_8_start_wait_end(&scene_steps, &u);
		break;
	case 42:
		stage_8_start_player_ride(scene_steps);
		break;
	case 44:
		stage_8_start_player_drop(scene_steps);
		break;
	case 46:
		stage_8_start_player_look(scene_steps);
		break;
	case 48:
		stage_8_start_player_turn(scene_steps);
		break;
	case 50:
		stage_8_start_player_run(scene_steps);
		break;
	case 52:
		stage_8_start_player_gone(scene_steps);
		break;
	case 54:
		stage_8_end_set_up(&scene_steps, &u);
		break;
	case 56:
		stage_8_end_show(&scene_steps, &u);
		break;
	case 58:
		stage_8_end_hold();
		break;
	case 60:
		stage_8_end_switch_view(&scene_steps, &u);
		break;
	case 62:
		stage_8_end_show_kind_13(&scene_steps, &u);
		break;
	case 64:
		stage_8_end_reunion(&scene_steps, &u);
		break;
	case 66:
		stage_8_end_run_family(&scene_steps, &u);
		break;
	case 68:
		stage_8_end_finish(&scene_steps, &u);
		break;
	case 70:
		stage_8_end_actor_rest();
		break;
	case 72:
		stage_8_end_walker(&scene_steps, &u);
		break;
	case 74:
		stage_8_end_maggie_taker(&scene_steps, &u);
		break;
	case 76:
		stage_8_end_extra(&scene_steps, &u);
		break;
	case 78:
		stage_8_end_slow_extra(&scene_steps, &u);
		break;
	case 80:
	case 88:
	case 96:
		stage_8_end_actor_start(scene_steps);
		break;
	case 82:
		stage_8_end_walker_go(scene_steps);
		break;
	case 84:
		stage_8_end_walker_arrive(scene_steps);
		break;
	case 86:
	case 94:
	case 102:
		stage_8_end_actor_done();
		break;
	case 90:
		stage_8_end_extra_go(scene_steps);
		break;
	case 92:
	case 100:
		stage_8_end_extra_arrive(scene_steps);
		break;
	case 98:
		stage_8_end_slow_extra_go(scene_steps);
		break;
	case 104:
		stage_8_end_taker_wait(scene_steps);
		break;
	case 106:
		stage_8_end_take_maggie(scene_steps);
		break;
	case 108:
		stage_8_end_holding_maggie(scene_steps);
		break;
	case 110:
		stage_8_end_taker_done();
		break;
	case -74:
		stage_1_end_start();
		break;
	case -72:
		u = stage_1_end_put_police_car(u);
		break;
	case -70:
		stage_1_end_move_police_car(scene_steps);
		break;
	case -68:
		stage_1_end_wait();
		break;
	case -66:
		stage_1_end_car_sound(scene_steps);
		break;
	case -64:
	case -36:
		scene_clear(&scene_steps, &u);
		break;
	case -62:
		stage_2_end_set_up(&scene_steps, &u);
		break;
	case -60:
	case -32:
		stage_end_jump_away(&scene_steps, &u);
		break;
	case -58:
		stage_2_end_show_area_3(&scene_steps, &u);
		break;
	case -56:
		stage_2_end_put_players(scene_steps);
		break;
	case -54:
	case -52:
		stage_2_end_players_look_around(&scene_steps, &u);
		break;
	case -50:
		scene_end(&scene_steps, &u);
		break;
	case -48:
		stage_end_put_jumpers(scene_steps);
		break;
	case -46:
		stage_end_run_jumpers(&scene_steps, &u);
		break;
	case -44:
		u = stage_end_jumper_wait(scene_steps, u);
		break;
	case -42:
		stage_end_jumper_fly(scene_steps);
		break;
	case -40:
		stage_end_jumper_last_leg(scene_steps);
		break;
	case -38:
		stage_end_jumper_vanish(scene_steps);
		break;
	case -34:
		stage_5_end_set_up(&scene_steps, &u);
		break;
	case -30:
		stage_5_end_show_players(&scene_steps, &u);
		break;
	case -28:
		u = stage_5_end_fade(u);
		break;
	case -26:
		stage_5_end_finish(&scene_steps, &u);
		break;
	case -24:
		stage_6_end_start();
		break;
	case -22:
		u = stage_6_end_effect(u);
		break;
	case -20:
		stage_6_end_finish(&scene_steps, &u);
		break;
	case -18:
		stage_6_wake_set_up(&scene_steps, &u);
		break;
	case -16:
		stage_6_wake_show_players(&scene_steps, &u);
		break;
	case -14:
		stage_6_wake_start();
		break;
	case -12:
		stage_6_wake_wave(&scene_steps, &u);
		break;
	case -10:
		post_bonus_2_scene_set_up(&scene_steps, &u);
		break;
	case -8:
		post_bonus_2_scene_show(&scene_steps, &u);
		break;
	case -6:
		post_bonus_2_scene_wait();
		break;
	case -4:
		post_bonus_2_scene_pan();
		break;
	case -2:
		post_bonus_2_scene_finish();
		break;
	}
	scene_steps = stage_7_scene_steps_ADDRESS;
	scene_substep = io_read8(scene_substate);
	switch ((int8_t)(uint8_t)((uint32_t)scene_substep << 1))
	{
	case 0:
		stage_7_scene_wait_train();
		return u;
	case 2:
		stage_7_scene_put_chain(&ignored16, &u_2);
		return u_2;
	case 4:
		stage_7_scene_move_chain(&ignored16, &u_2);
		return u_2;
	case 6:
		stage_7_scene_chain_done();
		return u;
	case 8:
		stage_7_end_set_up(&ignored16, &u);
		return u;
	case 10:
		stage_7_end_show(&ignored16, &u);
		return u;
	case 12:
		stage_7_end_board(scene_steps);
		return u;
	case 14:
		stage_7_end_take_off();
		return u;
	case 16:
		stage_7_end_slow_down(&ignored16, &u);
		return u;
	case 18:
		stage_7_end_finish(&ignored16, &u);
		return u;
	case 20:
		stage_8_start_set_up(&ignored16, &u);
		return u;
	case 22:
		stage_8_start_show(&ignored16, &u);
		return u;
	case 24:
		stage_8_start_descend(&ignored16, &u);
		return u;
	case 26:
		stage_8_start_stop(&ignored16, &u);
		return u;
	case 28:
		stage_8_start_landing();
		return u;
	case 30:
		stage_8_start_run_off(&ignored16, &u);
		return u;
	case 32:
		stage_8_start_wait_end(&ignored16, &u);
		return u;
	case 34:
		stage_8_start_player_ride(scene_steps);
		return u;
	case 36:
		stage_8_start_player_drop(scene_steps);
		return u;
	case 38:
		stage_8_start_player_look(scene_steps);
		return u;
	case 40:
		stage_8_start_player_turn(scene_steps);
		return u;
	case 42:
		stage_8_start_player_run(scene_steps);
		return u;
	case 44:
		stage_8_start_player_gone(scene_steps);
		return u;
	case 46:
		stage_8_end_set_up(&ignored16, &u_2);
		return u_2;
	case 48:
		stage_8_end_show(&ignored16, &u);
		return u;
	case 50:
		stage_8_end_hold();
		return u;
	case 52:
		stage_8_end_switch_view(&ignored16, &u_2);
		return u_2;
	case 54:
		stage_8_end_show_kind_13(&ignored16, &u);
		return u;
	case 56:
		stage_8_end_reunion(&ignored16, &u);
		return u;
	case 58:
		stage_8_end_run_family(&ignored16, &u);
		return u;
	case 60:
		stage_8_end_finish(&ignored16, &u);
		return u;
	case 62:
		stage_8_end_actor_rest();
		return u;
	case 64:
		stage_8_end_walker(&scene_steps, &u_2);
		return u_2;
	case 66:
		stage_8_end_maggie_taker(&scene_steps, &u_2);
		return u_2;
	case 68:
		stage_8_end_extra(&scene_steps, &u_2);
		return u_2;
	case 70:
		stage_8_end_slow_extra(&scene_steps, &u_2);
		return u_2;
	case 72:
	case 80:
	case 88:
		stage_8_end_actor_start(scene_steps);
		return u;
	case 74:
		stage_8_end_walker_go(scene_steps);
		return u;
	case 76:
		stage_8_end_walker_arrive(scene_steps);
		return u;
	case 78:
	case 86:
	case 94:
		stage_8_end_actor_done();
		return u;
	case 82:
		stage_8_end_extra_go(scene_steps);
		return u;
	case 84:
	case 92:
		stage_8_end_extra_arrive(scene_steps);
		return u;
	case 90:
		stage_8_end_slow_extra_go(scene_steps);
		return u;
	case 96:
		stage_8_end_taker_wait(scene_steps);
		return u;
	case 98:
		stage_8_end_take_maggie(scene_steps);
		return u;
	case 100:
		stage_8_end_holding_maggie(scene_steps);
		return u;
	case 102:
		stage_8_end_taker_done();
		return u;
	case -82:
		stage_1_end_start();
		return u;
	case -80:
		return stage_1_end_put_police_car(u);
	case -78:
		stage_1_end_move_police_car(scene_steps);
		return u;
	case -76:
		stage_1_end_wait();
		return u;
	case -74:
		stage_1_end_car_sound(scene_steps);
		return u;
	case -72:
	case -44:
		scene_clear(&ignored16, &u);
		return u;
	case -70:
		stage_2_end_set_up(&ignored16, &u);
		return u;
	case -68:
	case -40:
		stage_end_jump_away(&ignored16, &u);
		return u;
	case -66:
		stage_2_end_show_area_3(&ignored16, &u_2);
		return u_2;
	case -64:
		stage_2_end_put_players(scene_steps);
		return u;
	case -62:
	case -60:
		stage_2_end_players_look_around(&ignored16, &u);
		return u;
	case -58:
		scene_end(&ignored16, &u_2);
		return u_2;
	case -56:
		stage_end_put_jumpers(scene_steps);
		return u;
	case -54:
		stage_end_run_jumpers(&ignored16, &u_2);
		return u_2;
	case -52:
		return stage_end_jumper_wait(scene_steps, u);
	case -50:
		stage_end_jumper_fly(scene_steps);
		return u;
	case -48:
		stage_end_jumper_last_leg(scene_steps);
		return u;
	case -46:
		stage_end_jumper_vanish(scene_steps);
		return u;
	case -42:
		stage_5_end_set_up(&ignored16, &u);
		return u;
	case -38:
		stage_5_end_show_players(&ignored16, &u);
		return u;
	case -36:
		return stage_5_end_fade(u);
	case -34:
		stage_5_end_finish(&ignored16, &u_2);
		return u_2;
	case -32:
		stage_6_end_start();
		return u;
	case -30:
		return stage_6_end_effect(u);
	case -28:
		stage_6_end_finish(&ignored16, &u);
		return u;
	case -26:
		stage_6_wake_set_up(&ignored16, &u);
		return u;
	case -24:
		stage_6_wake_show_players(&ignored16, &u);
		return u;
	case -22:
		stage_6_wake_start();
		return u;
	case -20:
		stage_6_wake_wave(&ignored16, &u_2);
		return u_2;
	case -18:
		post_bonus_2_scene_set_up(&ignored16, &u);
		return u;
	case -16:
		post_bonus_2_scene_show(&scene_steps, &u);
		return u;
	case -14:
		post_bonus_2_scene_wait();
		return u;
	case -12:
		post_bonus_2_scene_pan();
		return u;
	case -10:
		post_bonus_2_scene_finish();
		return u;
	case -8:
		stage_7_scene_set_up();
		return u;
	case -6:
		stage_7_scene_wait_scroll();
		return u;
	case -4:
		stage_7_scene_wait_signal();
		return u;
	case -2:
		stage_7_scene_lift(&ignored16, &u);
		return u;
	}
	unreachable();
}

/* Runs stage 7's closing scene by its state: the family leaves Channel 6 aboard the kind-A4 object;
   after 128 frames a player's button skips it. */
uint16_t stage_7_end(uint16_t u)
{
	uint32_t carry = 0;
	uint16_t ignored16 = 0, scene_steps = 0, u_2 = 0, wait = 0;
	uint8_t scene_step = 0;

	wait = 0x8000u;
	vector_check_skip(wait, &ignored16, &carry);
	if (carry)
	{
		vector_clear_objects(&ignored16, &u_2);
		scene_running = 0u;
		return u_2;
	}
	gauges_shown = 0u;
	scene_steps = stage_7_end_states_ADDRESS;
	scene_step = io_read8(scene_state);
	switch ((int8_t)(uint8_t)((uint32_t)scene_step << 1))
	{
	case 0:
		stage_7_end_set_up(&ignored16, &u);
		return u;
	case 2:
		stage_7_end_show(&ignored16, &u);
		return u;
	case 4:
		stage_7_end_board(scene_steps);
		return u;
	case 6:
		stage_7_end_take_off();
		return u;
	case 8:
		stage_7_end_slow_down(&ignored16, &u);
		return u;
	case 10:
		stage_7_end_finish(&ignored16, &u);
		return u;
	case 12:
		stage_8_start_set_up(&ignored16, &u);
		return u;
	case 14:
		stage_8_start_show(&ignored16, &u);
		return u;
	case 16:
		stage_8_start_descend(&ignored16, &u);
		return u;
	case 18:
		stage_8_start_stop(&ignored16, &u);
		return u;
	case 20:
		stage_8_start_landing();
		return u;
	case 22:
		stage_8_start_run_off(&ignored16, &u);
		return u;
	case 24:
		stage_8_start_wait_end(&ignored16, &u);
		return u;
	case 26:
		stage_8_start_player_ride(scene_steps);
		return u;
	case 28:
		stage_8_start_player_drop(scene_steps);
		return u;
	case 30:
		stage_8_start_player_look(scene_steps);
		return u;
	case 32:
		stage_8_start_player_turn(scene_steps);
		return u;
	case 34:
		stage_8_start_player_run(scene_steps);
		return u;
	case 36:
		stage_8_start_player_gone(scene_steps);
		return u;
	case 38:
		stage_8_end_set_up(&ignored16, &u_2);
		return u_2;
	case 40:
		stage_8_end_show(&ignored16, &u);
		return u;
	case 42:
		stage_8_end_hold();
		return u;
	case 44:
		stage_8_end_switch_view(&ignored16, &u_2);
		return u_2;
	case 46:
		stage_8_end_show_kind_13(&ignored16, &u);
		return u;
	case 48:
		stage_8_end_reunion(&ignored16, &u);
		return u;
	case 50:
		stage_8_end_run_family(&ignored16, &u);
		return u;
	case 52:
		stage_8_end_finish(&ignored16, &u);
		return u;
	case 54:
		stage_8_end_actor_rest();
		return u;
	case 56:
		stage_8_end_walker(&scene_steps, &u_2);
		return u_2;
	case 58:
		stage_8_end_maggie_taker(&scene_steps, &u_2);
		return u_2;
	case 60:
		stage_8_end_extra(&scene_steps, &u_2);
		return u_2;
	case 62:
		stage_8_end_slow_extra(&scene_steps, &u_2);
		return u_2;
	case 64:
	case 72:
	case 80:
		stage_8_end_actor_start(scene_steps);
		return u;
	case 66:
		stage_8_end_walker_go(scene_steps);
		return u;
	case 68:
		stage_8_end_walker_arrive(scene_steps);
		return u;
	case 70:
	case 78:
	case 86:
		stage_8_end_actor_done();
		return u;
	case 74:
		stage_8_end_extra_go(scene_steps);
		return u;
	case 76:
	case 84:
		stage_8_end_extra_arrive(scene_steps);
		return u;
	case 82:
		stage_8_end_slow_extra_go(scene_steps);
		return u;
	case 88:
		stage_8_end_taker_wait(scene_steps);
		return u;
	case 90:
		stage_8_end_take_maggie(scene_steps);
		return u;
	case 92:
		stage_8_end_holding_maggie(scene_steps);
		return u;
	case 94:
		stage_8_end_taker_done();
		return u;
	case -90:
		stage_1_end_start();
		return u;
	case -88:
		return stage_1_end_put_police_car(u);
	case -86:
		stage_1_end_move_police_car(scene_steps);
		return u;
	case -84:
		stage_1_end_wait();
		return u;
	case -82:
		stage_1_end_car_sound(scene_steps);
		return u;
	case -80:
	case -52:
		scene_clear(&ignored16, &u);
		return u;
	case -78:
		stage_2_end_set_up(&ignored16, &u);
		return u;
	case -76:
	case -48:
		stage_end_jump_away(&ignored16, &u);
		return u;
	case -74:
		stage_2_end_show_area_3(&ignored16, &u_2);
		return u_2;
	case -72:
		stage_2_end_put_players(scene_steps);
		return u;
	case -70:
	case -68:
		stage_2_end_players_look_around(&ignored16, &u);
		return u;
	case -66:
		scene_end(&ignored16, &u_2);
		return u_2;
	case -64:
		stage_end_put_jumpers(scene_steps);
		return u;
	case -62:
		stage_end_run_jumpers(&ignored16, &u_2);
		return u_2;
	case -60:
		return stage_end_jumper_wait(scene_steps, u);
	case -58:
		stage_end_jumper_fly(scene_steps);
		return u;
	case -56:
		stage_end_jumper_last_leg(scene_steps);
		return u;
	case -54:
		stage_end_jumper_vanish(scene_steps);
		return u;
	case -50:
		stage_5_end_set_up(&ignored16, &u);
		return u;
	case -46:
		stage_5_end_show_players(&ignored16, &u);
		return u;
	case -44:
		return stage_5_end_fade(u);
	case -42:
		stage_5_end_finish(&ignored16, &u_2);
		return u_2;
	case -40:
		stage_6_end_start();
		return u;
	case -38:
		return stage_6_end_effect(u);
	case -36:
		stage_6_end_finish(&ignored16, &u);
		return u;
	case -34:
		stage_6_wake_set_up(&ignored16, &u);
		return u;
	case -32:
		stage_6_wake_show_players(&ignored16, &u);
		return u;
	case -30:
		stage_6_wake_start();
		return u;
	case -28:
		stage_6_wake_wave(&ignored16, &u_2);
		return u_2;
	case -26:
		post_bonus_2_scene_set_up(&ignored16, &u);
		return u;
	case -24:
		post_bonus_2_scene_show(&scene_steps, &u);
		return u;
	case -22:
		post_bonus_2_scene_wait();
		return u;
	case -20:
		post_bonus_2_scene_pan();
		return u;
	case -18:
		post_bonus_2_scene_finish();
		return u;
	case -16:
		stage_7_scene_set_up();
		return u;
	case -14:
		stage_7_scene_wait_scroll();
		return u;
	case -12:
		stage_7_scene_wait_signal();
		return u;
	case -10:
		stage_7_scene_lift(&ignored16, &u);
		return u;
	case -8:
		stage_7_scene_wait_train();
		return u;
	case -6:
		stage_7_scene_put_chain(&ignored16, &u_2);
		return u_2;
	case -4:
		stage_7_scene_move_chain(&ignored16, &u_2);
		return u_2;
	case -2:
		stage_7_scene_chain_done();
		return u;
	}
	unreachable();
}

/* Runs the scene after stage 8's last boss by its state: the family gets Maggie back. */
void stage_8_end(uint16_t u)
{
	uint16_t ignored16 = 0, ignored16_2 = 0, scene_steps = 0;
	uint8_t scene_step = 0;

	gauges_shown = 0u;
	scene_steps = stage_8_end_states_ADDRESS;
	scene_step = io_read8(scene_state);
	switch ((int8_t)(uint8_t)((uint32_t)scene_step << 1))
	{
	case 0:
		stage_8_end_set_up(&ignored16, &ignored16_2);
		return;
	case 2:
		stage_8_end_show(&ignored16, &ignored16_2);
		return;
	case 4:
		stage_8_end_hold();
		return;
	case 6:
		stage_8_end_switch_view(&ignored16, &ignored16_2);
		return;
	case 8:
		stage_8_end_show_kind_13(&ignored16, &ignored16_2);
		return;
	case 10:
		stage_8_end_reunion(&ignored16, &u);
		return;
	case 12:
		stage_8_end_run_family(&ignored16, &u);
		return;
	case 14:
		stage_8_end_finish(&ignored16, &ignored16_2);
		return;
	case 16:
		stage_8_end_actor_rest();
		return;
	case 18:
		stage_8_end_walker(&scene_steps, &ignored16_2);
		return;
	case 20:
		stage_8_end_maggie_taker(&scene_steps, &ignored16_2);
		return;
	case 22:
		stage_8_end_extra(&scene_steps, &ignored16_2);
		return;
	case 24:
		stage_8_end_slow_extra(&scene_steps, &ignored16_2);
		return;
	case 26:
	case 34:
	case 42:
		stage_8_end_actor_start(scene_steps);
		return;
	case 28:
		stage_8_end_walker_go(scene_steps);
		return;
	case 30:
		stage_8_end_walker_arrive(scene_steps);
		return;
	case 32:
	case 40:
	case 48:
		stage_8_end_actor_done();
		return;
	case 36:
		stage_8_end_extra_go(scene_steps);
		return;
	case 38:
	case 46:
		stage_8_end_extra_arrive(scene_steps);
		return;
	case 44:
		stage_8_end_slow_extra_go(scene_steps);
		return;
	case 50:
		stage_8_end_taker_wait(scene_steps);
		return;
	case 52:
		stage_8_end_take_maggie(scene_steps);
		return;
	case 54:
		stage_8_end_holding_maggie(scene_steps);
		return;
	case 56:
		stage_8_end_taker_done();
		return;
	case -128:
		stage_1_end_start();
		return;
	case -126:
		stage_1_end_put_police_car(u);
		return;
	case -124:
		stage_1_end_move_police_car(scene_steps);
		return;
	case -122:
		stage_1_end_wait();
		return;
	case -120:
		stage_1_end_car_sound(scene_steps);
		return;
	case -118:
	case -90:
		scene_clear(&ignored16, &u);
		return;
	case -116:
		stage_2_end_set_up(&ignored16, &ignored16_2);
		return;
	case -114:
	case -86:
		stage_end_jump_away(&ignored16, &u);
		return;
	case -112:
		stage_2_end_show_area_3(&ignored16, &ignored16_2);
		return;
	case -110:
		stage_2_end_put_players(scene_steps);
		return;
	case -108:
	case -106:
		stage_2_end_players_look_around(&ignored16, &u);
		return;
	case -104:
		scene_end(&ignored16, &ignored16_2);
		return;
	case -102:
		stage_end_put_jumpers(scene_steps);
		return;
	case -100:
		stage_end_run_jumpers(&ignored16, &ignored16_2);
		return;
	case -98:
		stage_end_jumper_wait(scene_steps, u);
		return;
	case -96:
		stage_end_jumper_fly(scene_steps);
		return;
	case -94:
		stage_end_jumper_last_leg(scene_steps);
		return;
	case -92:
		stage_end_jumper_vanish(scene_steps);
		return;
	case -88:
		stage_5_end_set_up(&ignored16, &u);
		return;
	case -84:
		stage_5_end_show_players(&ignored16, &u);
		return;
	case -82:
		stage_5_end_fade(u);
		return;
	case -80:
		stage_5_end_finish(&ignored16, &ignored16_2);
		return;
	case -78:
		stage_6_end_start();
		return;
	case -76:
		stage_6_end_effect(u);
		return;
	case -74:
		stage_6_end_finish(&ignored16, &ignored16_2);
		return;
	case -72:
		stage_6_wake_set_up(&ignored16, &u);
		return;
	case -70:
		stage_6_wake_show_players(&ignored16, &u);
		return;
	case -68:
		stage_6_wake_start();
		return;
	case -66:
		stage_6_wake_wave(&ignored16, &ignored16_2);
		return;
	case -64:
		post_bonus_2_scene_set_up(&ignored16, &u);
		return;
	case -62:
		post_bonus_2_scene_show(&scene_steps, &ignored16_2);
		return;
	case -60:
		post_bonus_2_scene_wait();
		return;
	case -58:
		post_bonus_2_scene_pan();
		return;
	case -56:
		post_bonus_2_scene_finish();
		return;
	case -54:
		stage_7_scene_set_up();
		return;
	case -52:
		stage_7_scene_wait_scroll();
		return;
	case -50:
		stage_7_scene_wait_signal();
		return;
	case -48:
		stage_7_scene_lift(&ignored16, &ignored16_2);
		return;
	case -46:
		stage_7_scene_wait_train();
		return;
	case -44:
		stage_7_scene_put_chain(&ignored16, &ignored16_2);
		return;
	case -42:
		stage_7_scene_move_chain(&ignored16, &ignored16_2);
		return;
	case -40:
		stage_7_scene_chain_done();
		return;
	case -38:
		stage_7_end_set_up(&ignored16, &u);
		return;
	case -36:
		stage_7_end_show(&ignored16, &ignored16_2);
		return;
	case -34:
		stage_7_end_board(scene_steps);
		return;
	case -32:
		stage_7_end_take_off();
		return;
	case -30:
		stage_7_end_slow_down(&ignored16, &ignored16_2);
		return;
	case -28:
		stage_7_end_finish(&ignored16, &ignored16_2);
		return;
	case -26:
		stage_8_start_set_up(&ignored16, &u);
		return;
	case -24:
		stage_8_start_show(&ignored16, &ignored16_2);
		return;
	case -22:
		stage_8_start_descend(&ignored16, &ignored16_2);
		return;
	case -20:
		stage_8_start_stop(&ignored16, &ignored16_2);
		return;
	case -18:
		stage_8_start_landing();
		return;
	case -16:
		stage_8_start_run_off(&ignored16, &ignored16_2);
		return;
	case -14:
		stage_8_start_wait_end(&ignored16, &ignored16_2);
		return;
	case -12:
		stage_8_start_player_ride(scene_steps);
		return;
	case -10:
		stage_8_start_player_drop(scene_steps);
		return;
	case -8:
		stage_8_start_player_look(scene_steps);
		return;
	case -6:
		stage_8_start_player_turn(scene_steps);
		return;
	case -4:
		stage_8_start_player_run(scene_steps);
		return;
	case -2:
		stage_8_start_player_gone(scene_steps);
		return;
	}
}

/* Draws the dream's wave once: each line of layer A's x scroll swung by a sine of 64. */
void dream_wave_draw(void)
{
	uint8_t wave_high = 0, wave_low = 0;
	uint16_t line_scroll = 0, wave_value = 0;
	uint8_t discarded_read = 0, row = 0, wave_phase = 0, rows_left = 0;
	uint16_t row_scroll = 0, exchanged = 0, row_scroll_at = 0;

	discarded_read = io_read8(0x18EAu);
	io_write8(0x18EAu, 0u);
	line_scroll = 0x1A00u;
	do
	{
		row = io_read8(0x18EAu);
		wave_phase = io_read8(0x18EBu);
		wave_value = ((uint32_t)(uint8_t)((uint32_t)(row + wave_phase) << 1) << 8) | 0x40u;
		wave_value = wave_sine(wave_value);
		wave_high = (uint8_t)(wave_value >> 8);
		wave_low = (uint8_t)wave_value;
		row_scroll = (((uint32_t)wave_high << 8) | wave_low) + 0x196u;
		wave_high = (row_scroll >> 8) & 1u;
		exchanged = wave_high | 0x1000u;
		row_scroll_at = line_scroll;
		line_scroll = row_scroll_at + 2u;
		mem_write16(row_scroll_at, ((uint32_t)(uint8_t)row_scroll << 8) | (uint8_t)exchanged);
		rows_left = io_read8(0x18EAu);
		io_write8(0x18EAu, rows_left - 1u);
	} while (rows_left != 1u);
}

/* Runs stage 8's opening scene by its state: the family comes down into the power plant; after 128
   frames a player's button skips it. */
void stage_8_start(uint16_t u)
{
	uint32_t carry = 0;
	uint16_t ignored16 = 0, ignored16_2 = 0, scene_steps = 0, wait = 0;
	uint8_t scene_step = 0;

	wait = 0x8000u;
	vector_check_skip(wait, &ignored16, &carry);
	if (carry)
	{
		stage_8_start_finish(&ignored16, &ignored16_2);
		return;
	}
	gauges_shown = 0u;
	scene_steps = stage_8_start_states_ADDRESS;
	scene_step = io_read8(scene_state);
	switch ((int8_t)(uint8_t)((uint32_t)scene_step << 1))
	{
	case 0:
		stage_8_start_set_up(&ignored16, &u);
		return;
	case 2:
		stage_8_start_show(&ignored16, &ignored16_2);
		return;
	case 4:
		stage_8_start_descend(&ignored16, &ignored16_2);
		return;
	case 6:
		stage_8_start_stop(&ignored16, &ignored16_2);
		return;
	case 8:
		stage_8_start_landing();
		return;
	case 10:
		stage_8_start_run_off(&ignored16, &ignored16_2);
		return;
	case 12:
		stage_8_start_wait_end(&ignored16, &ignored16_2);
		return;
	case 14:
		stage_8_start_player_ride(scene_steps);
		return;
	case 16:
		stage_8_start_player_drop(scene_steps);
		return;
	case 18:
		stage_8_start_player_look(scene_steps);
		return;
	case 20:
		stage_8_start_player_turn(scene_steps);
		return;
	case 22:
		stage_8_start_player_run(scene_steps);
		return;
	case 24:
		stage_8_start_player_gone(scene_steps);
		return;
	case 26:
		stage_8_end_set_up(&ignored16, &ignored16_2);
		return;
	case 28:
		stage_8_end_show(&ignored16, &ignored16_2);
		return;
	case 30:
		stage_8_end_hold();
		return;
	case 32:
		stage_8_end_switch_view(&ignored16, &ignored16_2);
		return;
	case 34:
		stage_8_end_show_kind_13(&ignored16, &ignored16_2);
		return;
	case 36:
		stage_8_end_reunion(&ignored16, &u);
		return;
	case 38:
		stage_8_end_run_family(&ignored16, &u);
		return;
	case 40:
		stage_8_end_finish(&ignored16, &ignored16_2);
		return;
	case 42:
		stage_8_end_actor_rest();
		return;
	case 44:
		stage_8_end_walker(&scene_steps, &ignored16_2);
		return;
	case 46:
		stage_8_end_maggie_taker(&scene_steps, &ignored16_2);
		return;
	case 48:
		stage_8_end_extra(&scene_steps, &ignored16_2);
		return;
	case 50:
		stage_8_end_slow_extra(&scene_steps, &ignored16_2);
		return;
	case 52:
	case 60:
	case 68:
		stage_8_end_actor_start(scene_steps);
		return;
	case 54:
		stage_8_end_walker_go(scene_steps);
		return;
	case 56:
		stage_8_end_walker_arrive(scene_steps);
		return;
	case 58:
	case 66:
	case 74:
		stage_8_end_actor_done();
		return;
	case 62:
		stage_8_end_extra_go(scene_steps);
		return;
	case 64:
	case 72:
		stage_8_end_extra_arrive(scene_steps);
		return;
	case 70:
		stage_8_end_slow_extra_go(scene_steps);
		return;
	case 76:
		stage_8_end_taker_wait(scene_steps);
		return;
	case 78:
		stage_8_end_take_maggie(scene_steps);
		return;
	case 80:
		stage_8_end_holding_maggie(scene_steps);
		return;
	case 82:
		stage_8_end_taker_done();
		return;
	case -102:
		stage_1_end_start();
		return;
	case -100:
		stage_1_end_put_police_car(u);
		return;
	case -98:
		stage_1_end_move_police_car(scene_steps);
		return;
	case -96:
		stage_1_end_wait();
		return;
	case -94:
		stage_1_end_car_sound(scene_steps);
		return;
	case -92:
	case -64:
		scene_clear(&ignored16, &u);
		return;
	case -90:
		stage_2_end_set_up(&ignored16, &ignored16_2);
		return;
	case -88:
	case -60:
		stage_end_jump_away(&ignored16, &u);
		return;
	case -86:
		stage_2_end_show_area_3(&ignored16, &ignored16_2);
		return;
	case -84:
		stage_2_end_put_players(scene_steps);
		return;
	case -82:
	case -80:
		stage_2_end_players_look_around(&ignored16, &u);
		return;
	case -78:
		scene_end(&ignored16, &ignored16_2);
		return;
	case -76:
		stage_end_put_jumpers(scene_steps);
		return;
	case -74:
		stage_end_run_jumpers(&ignored16, &ignored16_2);
		return;
	case -72:
		stage_end_jumper_wait(scene_steps, u);
		return;
	case -70:
		stage_end_jumper_fly(scene_steps);
		return;
	case -68:
		stage_end_jumper_last_leg(scene_steps);
		return;
	case -66:
		stage_end_jumper_vanish(scene_steps);
		return;
	case -62:
		stage_5_end_set_up(&ignored16, &u);
		return;
	case -58:
		stage_5_end_show_players(&ignored16, &u);
		return;
	case -56:
		stage_5_end_fade(u);
		return;
	case -54:
		stage_5_end_finish(&ignored16, &ignored16_2);
		return;
	case -52:
		stage_6_end_start();
		return;
	case -50:
		stage_6_end_effect(u);
		return;
	case -48:
		stage_6_end_finish(&ignored16, &ignored16_2);
		return;
	case -46:
		stage_6_wake_set_up(&ignored16, &u);
		return;
	case -44:
		stage_6_wake_show_players(&ignored16, &u);
		return;
	case -42:
		stage_6_wake_start();
		return;
	case -40:
		stage_6_wake_wave(&ignored16, &ignored16_2);
		return;
	case -38:
		post_bonus_2_scene_set_up(&ignored16, &u);
		return;
	case -36:
		post_bonus_2_scene_show(&scene_steps, &ignored16_2);
		return;
	case -34:
		post_bonus_2_scene_wait();
		return;
	case -32:
		post_bonus_2_scene_pan();
		return;
	case -30:
		post_bonus_2_scene_finish();
		return;
	case -28:
		stage_7_scene_set_up();
		return;
	case -26:
		stage_7_scene_wait_scroll();
		return;
	case -24:
		stage_7_scene_wait_signal();
		return;
	case -22:
		stage_7_scene_lift(&ignored16, &ignored16_2);
		return;
	case -20:
		stage_7_scene_wait_train();
		return;
	case -18:
		stage_7_scene_put_chain(&ignored16, &ignored16_2);
		return;
	case -16:
		stage_7_scene_move_chain(&ignored16, &ignored16_2);
		return;
	case -14:
		stage_7_scene_chain_done();
		return;
	case -12:
		stage_7_end_set_up(&ignored16, &u);
		return;
	case -10:
		stage_7_end_show(&ignored16, &ignored16_2);
		return;
	case -8:
		stage_7_end_board(scene_steps);
		return;
	case -6:
		stage_7_end_take_off();
		return;
	case -4:
		stage_7_end_slow_down(&ignored16, &ignored16_2);
		return;
	case -2:
		stage_7_end_finish(&ignored16, &ignored16_2);
		return;
	}
}

/* Runs the first part of stage 6's closing scene by its state: a long palette effect. */
void stage_6_end(uint16_t u)
{
	uint16_t ignored16 = 0, ignored16_2 = 0, scene_steps = 0;
	uint8_t scene_step = 0;

	scene_steps = stage_6_end_states_ADDRESS;
	scene_step = io_read8(scene_state);
	switch ((int8_t)(uint8_t)((uint32_t)scene_step << 1))
	{
	case 0:
		stage_6_end_start();
		return;
	case 2:
		stage_6_end_effect(u);
		return;
	case 4:
		stage_6_end_finish(&ignored16, &ignored16_2);
		return;
	case 6:
		stage_6_wake_set_up(&ignored16, &u);
		return;
	case 8:
		stage_6_wake_show_players(&ignored16, &u);
		return;
	case 10:
		stage_6_wake_start();
		return;
	case 12:
		stage_6_wake_wave(&ignored16, &ignored16_2);
		return;
	case 14:
		post_bonus_2_scene_set_up(&ignored16, &u);
		return;
	case 16:
		post_bonus_2_scene_show(&scene_steps, &ignored16_2);
		return;
	case 18:
		post_bonus_2_scene_wait();
		return;
	case 20:
		post_bonus_2_scene_pan();
		return;
	case 22:
		post_bonus_2_scene_finish();
		return;
	case 24:
		stage_7_scene_set_up();
		return;
	case 26:
		stage_7_scene_wait_scroll();
		return;
	case 28:
		stage_7_scene_wait_signal();
		return;
	case 30:
		stage_7_scene_lift(&ignored16, &ignored16_2);
		return;
	case 32:
		stage_7_scene_wait_train();
		return;
	case 34:
		stage_7_scene_put_chain(&ignored16, &ignored16_2);
		return;
	case 36:
		stage_7_scene_move_chain(&ignored16, &ignored16_2);
		return;
	case 38:
		stage_7_scene_chain_done();
		return;
	case 40:
		stage_7_end_set_up(&ignored16, &u);
		return;
	case 42:
		stage_7_end_show(&ignored16, &ignored16_2);
		return;
	case 44:
		stage_7_end_board(scene_steps);
		return;
	case 46:
		stage_7_end_take_off();
		return;
	case 48:
		stage_7_end_slow_down(&ignored16, &ignored16_2);
		return;
	case 50:
		stage_7_end_finish(&ignored16, &ignored16_2);
		return;
	case 52:
		stage_8_start_set_up(&ignored16, &u);
		return;
	case 54:
		stage_8_start_show(&ignored16, &ignored16_2);
		return;
	case 56:
		stage_8_start_descend(&ignored16, &ignored16_2);
		return;
	case 58:
		stage_8_start_stop(&ignored16, &ignored16_2);
		return;
	case 60:
		stage_8_start_landing();
		return;
	case 62:
		stage_8_start_run_off(&ignored16, &ignored16_2);
		return;
	case 64:
		stage_8_start_wait_end(&ignored16, &ignored16_2);
		return;
	case 66:
		stage_8_start_player_ride(scene_steps);
		return;
	case 68:
		stage_8_start_player_drop(scene_steps);
		return;
	case 70:
		stage_8_start_player_look(scene_steps);
		return;
	case 72:
		stage_8_start_player_turn(scene_steps);
		return;
	case 74:
		stage_8_start_player_run(scene_steps);
		return;
	case 76:
		stage_8_start_player_gone(scene_steps);
		return;
	case 78:
		stage_8_end_set_up(&ignored16, &ignored16_2);
		return;
	case 80:
		stage_8_end_show(&ignored16, &ignored16_2);
		return;
	case 82:
		stage_8_end_hold();
		return;
	case 84:
		stage_8_end_switch_view(&ignored16, &ignored16_2);
		return;
	case 86:
		stage_8_end_show_kind_13(&ignored16, &ignored16_2);
		return;
	case 88:
		stage_8_end_reunion(&ignored16, &u);
		return;
	case 90:
		stage_8_end_run_family(&ignored16, &u);
		return;
	case 92:
		stage_8_end_finish(&ignored16, &ignored16_2);
		return;
	case 94:
		stage_8_end_actor_rest();
		return;
	case 96:
		stage_8_end_walker(&scene_steps, &ignored16_2);
		return;
	case 98:
		stage_8_end_maggie_taker(&scene_steps, &ignored16_2);
		return;
	case 100:
		stage_8_end_extra(&scene_steps, &ignored16_2);
		return;
	case 102:
		stage_8_end_slow_extra(&scene_steps, &ignored16_2);
		return;
	case 104:
	case 112:
	case 120:
		stage_8_end_actor_start(scene_steps);
		return;
	case 106:
		stage_8_end_walker_go(scene_steps);
		return;
	case 108:
		stage_8_end_walker_arrive(scene_steps);
		return;
	case 110:
	case 118:
	case 126:
		stage_8_end_actor_done();
		return;
	case 114:
		stage_8_end_extra_go(scene_steps);
		return;
	case 116:
	case 124:
		stage_8_end_extra_arrive(scene_steps);
		return;
	case 122:
		stage_8_end_slow_extra_go(scene_steps);
		return;
	case -50:
		stage_1_end_start();
		return;
	case -48:
		stage_1_end_put_police_car(u);
		return;
	case -46:
		stage_1_end_move_police_car(scene_steps);
		return;
	case -44:
		stage_1_end_wait();
		return;
	case -42:
		stage_1_end_car_sound(scene_steps);
		return;
	case -40:
	case -12:
		scene_clear(&ignored16, &u);
		return;
	case -38:
		stage_2_end_set_up(&ignored16, &ignored16_2);
		return;
	case -36:
	case -8:
		stage_end_jump_away(&ignored16, &u);
		return;
	case -34:
		stage_2_end_show_area_3(&ignored16, &ignored16_2);
		return;
	case -32:
		stage_2_end_put_players(scene_steps);
		return;
	case -30:
	case -28:
		stage_2_end_players_look_around(&ignored16, &u);
		return;
	case -26:
		scene_end(&ignored16, &ignored16_2);
		return;
	case -24:
		stage_end_put_jumpers(scene_steps);
		return;
	case -22:
		stage_end_run_jumpers(&ignored16, &ignored16_2);
		return;
	case -20:
		stage_end_jumper_wait(scene_steps, u);
		return;
	case -18:
		stage_end_jumper_fly(scene_steps);
		return;
	case -16:
		stage_end_jumper_last_leg(scene_steps);
		return;
	case -14:
		stage_end_jumper_vanish(scene_steps);
		return;
	case -10:
		stage_5_end_set_up(&ignored16, &u);
		return;
	case -6:
		stage_5_end_show_players(&ignored16, &u);
		return;
	case -4:
		stage_5_end_fade(u);
		return;
	case -2:
		stage_5_end_finish(&ignored16, &ignored16_2);
		return;
	}
}

/* Runs the second part of stage 6's closing scene by its state: back in the gorge, the dream's wave
   fades away; after 96 frames a player's button skips it. */
void stage_6_wake(uint16_t u)
{
	uint32_t carry = 0;
	uint16_t delay = 0, ignored16 = 0, ignored16_2 = 0, scene_steps = 0, wait = 0;
	uint8_t scene_step = 0;
	uint16_t delay_left = 0;

	wait = 0x6000u;
	vector_check_skip(wait, &ignored16, &carry);
	if (carry)
	{
		scene_running = 0u;
		delay = 0x2000u;
		do
		{
			delay_left = delay - 1u;
			delay = delay_left;
		} while (delay_left != 0u);
		return;
	}
	gauges_shown = 0u;
	scene_steps = stage_6_wake_states_ADDRESS;
	scene_step = io_read8(scene_state);
	switch ((int8_t)(uint8_t)((uint32_t)scene_step << 1))
	{
	case 0:
		stage_6_wake_set_up(&ignored16, &u);
		return;
	case 2:
		stage_6_wake_show_players(&ignored16, &u);
		return;
	case 4:
		stage_6_wake_start();
		return;
	case 6:
		stage_6_wake_wave(&ignored16, &ignored16_2);
		return;
	case 8:
		post_bonus_2_scene_set_up(&ignored16, &u);
		return;
	case 10:
		post_bonus_2_scene_show(&scene_steps, &ignored16_2);
		return;
	case 12:
		post_bonus_2_scene_wait();
		return;
	case 14:
		post_bonus_2_scene_pan();
		return;
	case 16:
		post_bonus_2_scene_finish();
		return;
	case 18:
		stage_7_scene_set_up();
		return;
	case 20:
		stage_7_scene_wait_scroll();
		return;
	case 22:
		stage_7_scene_wait_signal();
		return;
	case 24:
		stage_7_scene_lift(&ignored16, &ignored16_2);
		return;
	case 26:
		stage_7_scene_wait_train();
		return;
	case 28:
		stage_7_scene_put_chain(&ignored16, &ignored16_2);
		return;
	case 30:
		stage_7_scene_move_chain(&ignored16, &ignored16_2);
		return;
	case 32:
		stage_7_scene_chain_done();
		return;
	case 34:
		stage_7_end_set_up(&ignored16, &u);
		return;
	case 36:
		stage_7_end_show(&ignored16, &ignored16_2);
		return;
	case 38:
		stage_7_end_board(scene_steps);
		return;
	case 40:
		stage_7_end_take_off();
		return;
	case 42:
		stage_7_end_slow_down(&ignored16, &ignored16_2);
		return;
	case 44:
		stage_7_end_finish(&ignored16, &ignored16_2);
		return;
	case 46:
		stage_8_start_set_up(&ignored16, &u);
		return;
	case 48:
		stage_8_start_show(&ignored16, &ignored16_2);
		return;
	case 50:
		stage_8_start_descend(&ignored16, &ignored16_2);
		return;
	case 52:
		stage_8_start_stop(&ignored16, &ignored16_2);
		return;
	case 54:
		stage_8_start_landing();
		return;
	case 56:
		stage_8_start_run_off(&ignored16, &ignored16_2);
		return;
	case 58:
		stage_8_start_wait_end(&ignored16, &ignored16_2);
		return;
	case 60:
		stage_8_start_player_ride(scene_steps);
		return;
	case 62:
		stage_8_start_player_drop(scene_steps);
		return;
	case 64:
		stage_8_start_player_look(scene_steps);
		return;
	case 66:
		stage_8_start_player_turn(scene_steps);
		return;
	case 68:
		stage_8_start_player_run(scene_steps);
		return;
	case 70:
		stage_8_start_player_gone(scene_steps);
		return;
	case 72:
		stage_8_end_set_up(&ignored16, &ignored16_2);
		return;
	case 74:
		stage_8_end_show(&ignored16, &ignored16_2);
		return;
	case 76:
		stage_8_end_hold();
		return;
	case 78:
		stage_8_end_switch_view(&ignored16, &ignored16_2);
		return;
	case 80:
		stage_8_end_show_kind_13(&ignored16, &ignored16_2);
		return;
	case 82:
		stage_8_end_reunion(&ignored16, &u);
		return;
	case 84:
		stage_8_end_run_family(&ignored16, &u);
		return;
	case 86:
		stage_8_end_finish(&ignored16, &ignored16_2);
		return;
	case 88:
		stage_8_end_actor_rest();
		return;
	case 90:
		stage_8_end_walker(&scene_steps, &ignored16_2);
		return;
	case 92:
		stage_8_end_maggie_taker(&scene_steps, &ignored16_2);
		return;
	case 94:
		stage_8_end_extra(&scene_steps, &ignored16_2);
		return;
	case 96:
		stage_8_end_slow_extra(&scene_steps, &ignored16_2);
		return;
	case 98:
	case 106:
	case 114:
		stage_8_end_actor_start(scene_steps);
		return;
	case 100:
		stage_8_end_walker_go(scene_steps);
		return;
	case 102:
		stage_8_end_walker_arrive(scene_steps);
		return;
	case 104:
	case 112:
	case 120:
		stage_8_end_actor_done();
		return;
	case 108:
		stage_8_end_extra_go(scene_steps);
		return;
	case 110:
	case 118:
		stage_8_end_extra_arrive(scene_steps);
		return;
	case 116:
		stage_8_end_slow_extra_go(scene_steps);
		return;
	case 122:
		stage_8_end_taker_wait(scene_steps);
		return;
	case 124:
		stage_8_end_take_maggie(scene_steps);
		return;
	case 126:
		stage_8_end_holding_maggie(scene_steps);
		return;
	case -56:
		stage_1_end_start();
		return;
	case -54:
		stage_1_end_put_police_car(u);
		return;
	case -52:
		stage_1_end_move_police_car(scene_steps);
		return;
	case -50:
		stage_1_end_wait();
		return;
	case -48:
		stage_1_end_car_sound(scene_steps);
		return;
	case -46:
	case -18:
		scene_clear(&ignored16, &u);
		return;
	case -44:
		stage_2_end_set_up(&ignored16, &ignored16_2);
		return;
	case -42:
	case -14:
		stage_end_jump_away(&ignored16, &u);
		return;
	case -40:
		stage_2_end_show_area_3(&ignored16, &ignored16_2);
		return;
	case -38:
		stage_2_end_put_players(scene_steps);
		return;
	case -36:
	case -34:
		stage_2_end_players_look_around(&ignored16, &u);
		return;
	case -32:
		scene_end(&ignored16, &ignored16_2);
		return;
	case -30:
		stage_end_put_jumpers(scene_steps);
		return;
	case -28:
		stage_end_run_jumpers(&ignored16, &ignored16_2);
		return;
	case -26:
		stage_end_jumper_wait(scene_steps, u);
		return;
	case -24:
		stage_end_jumper_fly(scene_steps);
		return;
	case -22:
		stage_end_jumper_last_leg(scene_steps);
		return;
	case -20:
		stage_end_jumper_vanish(scene_steps);
		return;
	case -16:
		stage_5_end_set_up(&ignored16, &u);
		return;
	case -12:
		stage_5_end_show_players(&ignored16, &u);
		return;
	case -10:
		stage_5_end_fade(u);
		return;
	case -8:
		stage_5_end_finish(&ignored16, &ignored16_2);
		return;
	case -6:
		stage_6_end_start();
		return;
	case -4:
		stage_6_end_effect(u);
		return;
	case -2:
		stage_6_end_finish(&ignored16, &ignored16_2);
		return;
	}
}

/* Stage 1's closing scene: sets a 128-frame wait. */
void stage_1_end_start(void)
{
	uint8_t old_scene_state = 0;

	io_write16(0x18E7u, 0x80u);
	old_scene_state = io_read8(scene_state);
	io_write8(scene_state, old_scene_state + 1u);
}

/* Stage 1's closing scene: after the wait, the music (9600) and the police car with its two doors. */
uint16_t stage_1_end_put_police_car(uint16_t car_part)
{
	uint32_t carry = 0;
	uint8_t list_number = 0;
	uint16_t car = 0, command = 0;
	uint8_t old_scene_state = 0;
	uint16_t police_wait = 0;

	police_wait = io_read16(0x18E7u);
	io_write16(0x18E7u, police_wait - 1u);
	if (police_wait != 1u)
		return car_part;
	command = 0x9600u;
	carry = vector_queue_sound_unless_attract(command);
	list_number = 2u;
	vector_find_free_slot(list_number, &car, &carry);
	io_write16(scene_substate, car);
	OBJECT(car)->flags = 0x80u;
	OBJECT(car)->type = 0;
	OBJECT(car)->kind = 0xFu;
	OBJECT(car)->animation = 0x93u;
	OBJECT(car)->attributes = 0x20u;
	OBJECT(car)->x = 0xE0u;
	OBJECT(car)->y = 0x100u;
	OBJECT(car)->z = 0xFF10u;
	list_number = 2u;
	vector_find_free_slot(list_number, &car, &carry);
	io_write16(0x18E3u, car);
	OBJECT(car)->flags = 0x80u;
	OBJECT(car)->type = 0;
	OBJECT(car)->kind = 0xFu;
	OBJECT(car)->animation = 0x92u;
	OBJECT(car)->attributes = 0x20u;
	OBJECT(car)->x = 0xE0u;
	OBJECT(car)->y = 0x100u;
	OBJECT(car)->z = 0xFF70u;
	list_number = 2u;
	vector_find_free_slot(list_number, &car_part, &carry);
	io_write16(0x18E5u, car_part);
	OBJECT(car_part)->flags = 0x80u;
	OBJECT(car_part)->type = 0;
	OBJECT(car_part)->kind = 0xFu;
	OBJECT(car_part)->animation = 0xA1u;
	OBJECT(car_part)->attributes = 0x20u;
	OBJECT(car_part)->x = 0xE0u;
	OBJECT(car_part)->y = 0xFEu;
	OBJECT(car_part)->z = 0xFF10u;
	io_write16(0x18E7u, 0xE0u);
	old_scene_state = io_read8(scene_state);
	io_write8(scene_state, old_scene_state + 1u);
	return car_part;
}

/* Stage 1's closing scene: a sound (9500), and the police car and its doors start moving up the screen. */
uint16_t stage_1_end_move_police_car(uint16_t third_part)
{
	uint32_t carry = 0;
	uint16_t command = 0, first_part = 0, second_part = 0;
	uint8_t old_scene_state = 0;
	uint16_t police_wait = 0, saved_first_part = 0, saved_second_part = 0, saved_third_part = 0;

	police_wait = io_read16(0x18E7u);
	io_write16(0x18E7u, police_wait - 1u);
	if (police_wait != 1u)
		return third_part;
	command = 0x9500u;
	carry = vector_queue_sound_unless_attract(command);
	saved_first_part = io_read16(scene_substate);
	first_part = saved_first_part;
	OBJECT(first_part)->z_speed = 0x100;
	saved_second_part = io_read16(0x18E3u);
	second_part = saved_second_part;
	OBJECT(second_part)->z_speed = 0x100;
	saved_third_part = io_read16(0x18E5u);
	third_part = saved_third_part;
	OBJECT(third_part)->z_speed = 0x100;
	io_write16(0x18E7u, 0x100u);
	old_scene_state = io_read8(scene_state);
	io_write8(scene_state, old_scene_state + 1u);
	return third_part;
}

/* Stage 1's closing scene: waits 192 frames. */
void stage_1_end_wait(void)
{
	uint8_t old_scene_state = 0;
	uint16_t police_wait = 0;

	police_wait = io_read16(0x18E7u);
	io_write16(0x18E7u, police_wait - 1u);
	if (police_wait == 1u)
	{
		io_write16(0x18E7u, 0xC0u);
		old_scene_state = io_read8(scene_state);
		io_write8(scene_state, old_scene_state + 1u);
	}
}

/* Stage 1's closing scene: the car's sound (4A00) every 16 frames while it is low on the screen; when
   the time is up the scene is over. */
uint16_t stage_1_end_car_sound(uint16_t first_part)
{
	uint32_t carry = 0;
	uint16_t command = 0;
	uint16_t saved_first_part = 0, part_z = 0, police_wait = 0;

	if ((frame_count & 0xFu) == 0u)
	{
		saved_first_part = io_read16(scene_substate);
		first_part = saved_first_part;
		part_z = OBJECT(first_part)->z;
		if ((int16_t)part_z <= 0xB0)
		{
			command = 0x4A00u;
			carry = vector_queue_sound(command);
		}
	}
	police_wait = io_read16(0x18E7u);
	io_write16(0x18E7u, police_wait - 1u);
	if (police_wait == 1u)
		scene_running = 0u;
	return first_part;
}

/* A scripted scene: loads its colours and clears the screen, the objects and the sprites. */
void scene_clear(uint16_t *p_x, uint16_t *p_u)
{
	uint16_t u = (uint16_t)*p_u;
	uint16_t ignored16 = 0, job = 0, request = 0, scroll_x = 0, scroll_y = 0, u_2 = 0, x = 0;
	uint8_t old_scene_state = 0;

	palette_request_kind = 1u;
	request = 0x880u;
	u = vector_palette_request(u, request);
	palette_request_kind = 1u;
	request = 0xE89u;
	vector_palette_request(u, request);
	job = 0u;
	vector_queue_job(job);
	scroll_x = 0xFFF0u;
	vector_set_scroll_x(scroll_x);
	scroll_y = 0u;
	vector_set_scroll_y(scroll_y);
	vector_clear_objects(&ignored16, &u_2);
	x = vector_clear_sprites();
	old_scene_state = io_read8(scene_state);
	io_write8(scene_state, old_scene_state + 1u);
	*p_x = x;
	*p_u = u_2;
}

/* Stage 2's closing scene: the music (9E00), Krustyland's area 2 and the kind-9C character close up. */
void stage_2_end_set_up(uint16_t *p_default_object, uint16_t *p_u)
{
	uint16_t default_object = (uint16_t)*p_default_object;
	uint16_t u = (uint16_t)*p_u;
	uint32_t carry = 0;
	uint16_t command = 0, layer_and_columns = 0, object = 0, record_number = 0, u_2 = 0;
	uint8_t old_scene_state = 0;

	if (layer_clear_pending != 0u)
		return;
	command = 0x9E00u;
	carry = vector_queue_sound_unless_attract(command);
	io_write8(0x1FB9u, 0x3Fu);
	io_write8(0x1FBAu, 0x36u);
	map_scene = 0x84u;
	map_area = 2u;
	layer_and_columns = 0x26u;
	vector_draw_layer_strips(layer_and_columns, &default_object, &u_2);
	io_write8(0x1FB9u, 0x13u);
	io_write8(0x1FBAu, 0x2Cu);
	record_number = 0xD26u;
	object = scene_put_placement(default_object, record_number);
	leftover_y = object;
	OBJECT(leftover_y)->zoom_x = 0x30u;
	OBJECT(leftover_y)->zoom_y = 0x30u;
	OBJECT(leftover_y)->parameter = 4u;
	OBJECT(leftover_y)->unk_32 = 4u;
	OBJECT(leftover_y)->blocked = 1u;
	old_scene_state = io_read8(scene_state);
	io_write8(scene_state, old_scene_state + 1u);
	*p_default_object = default_object;
	*p_u = u_2;
}

/* A stage's closing scene: the players jump off after the kind-9C character, by the sub-state. */
void stage_end_jump_away(uint16_t *p_jump_steps, uint16_t *p_u)
{
	uint16_t u = (uint16_t)*p_u;
	uint16_t jump_steps = 0;
	uint8_t scene_substep = 0;

	for (;;)
	{
		jump_steps = stage_end_jump_away_steps_ADDRESS;
		scene_substep = io_read8(scene_substate);
		switch ((int8_t)(uint8_t)((uint32_t)scene_substep << 1))
		{
		case 0:
			jump_steps = stage_end_put_jumpers(jump_steps);
			break;
		case 2:
			stage_end_run_jumpers(&jump_steps, &u);
			break;
		case 4:
			u = stage_end_jumper_wait(jump_steps, u);
			break;
		case 6:
			stage_end_jumper_fly(jump_steps);
			break;
		case 8:
			stage_end_jumper_last_leg(jump_steps);
			break;
		case 10:
			stage_end_jumper_vanish(jump_steps);
			break;
		case -16:
		case 12:
			scene_clear(&jump_steps, &u);
			break;
		case 14:
			stage_5_end_set_up(&jump_steps, &u);
			break;
		case -12:
		case 16:
			continue;
		case 18:
			stage_5_end_show_players(&jump_steps, &u);
			break;
		case 20:
			u = stage_5_end_fade(u);
			break;
		case 22:
			stage_5_end_finish(&jump_steps, &u);
			break;
		case 24:
			stage_6_end_start();
			break;
		case 26:
			u = stage_6_end_effect(u);
			break;
		case 28:
			stage_6_end_finish(&jump_steps, &u);
			break;
		case 30:
			stage_6_wake_set_up(&jump_steps, &u);
			break;
		case 32:
			stage_6_wake_show_players(&jump_steps, &u);
			break;
		case 34:
			stage_6_wake_start();
			break;
		case 36:
			stage_6_wake_wave(&jump_steps, &u);
			break;
		case 38:
			post_bonus_2_scene_set_up(&jump_steps, &u);
			break;
		case 40:
			post_bonus_2_scene_show(&jump_steps, &u);
			break;
		case 42:
			post_bonus_2_scene_wait();
			break;
		case 44:
			post_bonus_2_scene_pan();
			break;
		case 46:
			post_bonus_2_scene_finish();
			break;
		case 48:
			jump_steps = stage_7_scene_set_up();
			break;
		case 50:
			stage_7_scene_wait_scroll();
			break;
		case 52:
			stage_7_scene_wait_signal();
			break;
		case 54:
			stage_7_scene_lift(&jump_steps, &u);
			break;
		case 56:
			stage_7_scene_wait_train();
			break;
		case 58:
			stage_7_scene_put_chain(&jump_steps, &u);
			break;
		case 60:
			stage_7_scene_move_chain(&jump_steps, &u);
			break;
		case 62:
			stage_7_scene_chain_done();
			break;
		case 64:
			stage_7_end_set_up(&jump_steps, &u);
			break;
		case 66:
			stage_7_end_show(&jump_steps, &u);
			break;
		case 68:
			stage_7_end_board(jump_steps);
			break;
		case 70:
			jump_steps = stage_7_end_take_off();
			break;
		case 72:
			stage_7_end_slow_down(&jump_steps, &u);
			break;
		case 74:
			stage_7_end_finish(&jump_steps, &u);
			break;
		case 76:
			stage_8_start_set_up(&jump_steps, &u);
			break;
		case 78:
			stage_8_start_show(&jump_steps, &u);
			break;
		case 80:
			stage_8_start_descend(&jump_steps, &u);
			break;
		case 82:
			stage_8_start_stop(&jump_steps, &u);
			break;
		case 84:
			jump_steps = stage_8_start_landing();
			break;
		case 86:
			stage_8_start_run_off(&jump_steps, &u);
			break;
		case 88:
			stage_8_start_wait_end(&jump_steps, &u);
			break;
		case 90:
			stage_8_start_player_ride(jump_steps);
			break;
		case 92:
			stage_8_start_player_drop(jump_steps);
			break;
		case 94:
			stage_8_start_player_look(jump_steps);
			break;
		case 96:
			stage_8_start_player_turn(jump_steps);
			break;
		case 98:
			stage_8_start_player_run(jump_steps);
			break;
		case 100:
			stage_8_start_player_gone(jump_steps);
			break;
		case 102:
			stage_8_end_set_up(&jump_steps, &u);
			break;
		case 104:
			stage_8_end_show(&jump_steps, &u);
			break;
		case 106:
			stage_8_end_hold();
			break;
		case 108:
			stage_8_end_switch_view(&jump_steps, &u);
			break;
		case 110:
			stage_8_end_show_kind_13(&jump_steps, &u);
			break;
		case 112:
			stage_8_end_reunion(&jump_steps, &u);
			break;
		case 114:
			stage_8_end_run_family(&jump_steps, &u);
			break;
		case 116:
			stage_8_end_finish(&jump_steps, &u);
			break;
		case 118:
			stage_8_end_actor_rest();
			break;
		case 120:
			stage_8_end_walker(&jump_steps, &u);
			break;
		case 122:
			stage_8_end_maggie_taker(&jump_steps, &u);
			break;
		case 124:
			stage_8_end_extra(&jump_steps, &u);
			break;
		case 126:
			stage_8_end_slow_extra(&jump_steps, &u);
			break;
		case -26:
			stage_1_end_start();
			break;
		case -24:
			u = stage_1_end_put_police_car(u);
			break;
		case -22:
			jump_steps = stage_1_end_move_police_car(jump_steps);
			break;
		case -20:
			stage_1_end_wait();
			break;
		case -18:
			jump_steps = stage_1_end_car_sound(jump_steps);
			break;
		case -14:
			stage_2_end_set_up(&jump_steps, &u);
			break;
		case -10:
			stage_2_end_show_area_3(&jump_steps, &u);
			break;
		case -8:
			stage_2_end_put_players(jump_steps);
			break;
		case -6:
		case -4:
			stage_2_end_players_look_around(&jump_steps, &u);
			break;
		case -2:
			scene_end(&jump_steps, &u);
			break;
		}
		break;
	}
	*p_jump_steps = jump_steps;
	*p_u = u;
}

/* A stage's closing scene: puts each player who played the stage close up, each with a wait by its
   order. */
uint16_t stage_end_put_jumpers(uint16_t x)
{
	uint8_t jumper_number = 0;
	uint16_t jumper = 0, record_number = 0;
	uint8_t old_scene_substate = 0;

	scene_player_bit = 1u;
	scene_player = 0u;
	jumper_order = 0u;
	do
	{
		if ((players_present & scene_player_bit) != 0u)
		{
			record_number = (uint32_t)scene_player << 8;
			jumper = scene_put_placement(x, record_number);
			leftover_y = jumper;
			OBJECT(leftover_y)->unk_32 = scene_player;
			OBJECT(leftover_y)->zoom_x = 0x30u;
			OBJECT(leftover_y)->zoom_y = 0x30u;
			x = stage_end_exit_waits_ADDRESS;
			jumper_number = jumper_order;
			OBJECT(leftover_y)->parameter = jumper_number;
			OBJECT(leftover_y)->blocked = (uint8_t)(EXIT_SPEED(stage_end_exit_speeds_ADDRESS + (int8_t)jumper_number - 0x4u)->x_speed >> 8u);
			jumper_order++;
		}
		scene_player_bit = (uint32_t)scene_player_bit << 1;
		scene_player++;
	} while (scene_player != 4u);
	io_write16(0x18E2u, 0xB0u);
	if (scene == 6u)
		io_write16(0x18E2u, 0x140u);
	old_scene_substate = io_read8(scene_substate);
	io_write8(scene_substate, old_scene_substate + 1u);
	return x;
}

/* A stage's closing scene: runs the jumping objects until the time is up, then clears them. */
void stage_end_run_jumpers(uint16_t *p_object, uint16_t *p_steps)
{
	uint16_t object = 0, steps = 0;
	uint8_t stack = 0;
	uint8_t old_scene_state = 0, discarded_read = 0, type = 0, jumpers_left = 0;
	uint16_t jumpers_wait = 0;

	jumpers_wait = io_read16(0x18E2u);
	io_write16(0x18E2u, jumpers_wait - 1u);
	if (jumpers_wait == 1u)
	{
		vector_clear_layer_b();
		vector_clear_objects(&object, &steps);
		old_scene_state = io_read8(scene_state);
		io_write8(scene_state, old_scene_state + 1u);
		discarded_read = io_read8(scene_substate);
		io_write8(scene_substate, 0u);
	}
	else
	{
		object = OBJECT_ADDRESS(8);
		stack = 5u;
		do
		{
			steps = stage_end_jumper_steps_ADDRESS;
			if (OBJECT(object)->flags != 0u)
			{
				type = OBJECT(object)->type;
				switch ((uint16_t)(steps + (int8_t)((uint32_t)type << 1)))
				{
				case stage_1_end_states_ADDRESS:
					stage_1_end_start();
					break;
				case 0x7702u:
					steps = stage_1_end_put_police_car(steps);
					break;
				case 0x7704u:
					object = stage_1_end_move_police_car(object);
					break;
				case 0x7706u:
					stage_1_end_wait();
					break;
				case 0x7708u:
					object = stage_1_end_car_sound(object);
					break;
				case stage_2_end_states_ADDRESS:
				case stage_5_end_states_ADDRESS:
					scene_clear(&object, &steps);
					break;
				case 0x770Cu:
					stage_2_end_set_up(&object, &steps);
					break;
				case 0x770Eu:
				case 0x772Au:
					stage_end_jump_away(&object, &steps);
					break;
				case 0x7710u:
					stage_2_end_show_area_3(&object, &steps);
					break;
				case 0x7712u:
					stage_2_end_put_players(object);
					break;
				case 0x7714u:
				case 0x7716u:
					stage_2_end_players_look_around(&object, &steps);
					break;
				case 0x7718u:
					scene_end(&object, &steps);
					break;
				case stage_end_jump_away_steps_ADDRESS:
					object = stage_end_put_jumpers(object);
					break;
				case 0x771Cu:
					stage_end_run_jumpers(&object, &steps);
					break;
				case stage_end_jumper_steps_ADDRESS:
					steps = stage_end_jumper_wait(object, steps);
					break;
				case 0x7720u:
					stage_end_jumper_fly(object);
					break;
				case 0x7722u:
					stage_end_jumper_last_leg(object);
					break;
				case 0x7724u:
					stage_end_jumper_vanish(object);
					break;
				case 0x7728u:
					stage_5_end_set_up(&object, &steps);
					break;
				case 0x772Cu:
					stage_5_end_show_players(&object, &steps);
					break;
				case 0x772Eu:
					steps = stage_5_end_fade(steps);
					break;
				case 0x7730u:
					stage_5_end_finish(&object, &steps);
					break;
				case stage_6_end_states_ADDRESS:
					stage_6_end_start();
					break;
				case 0x7734u:
					steps = stage_6_end_effect(steps);
					break;
				case 0x7736u:
					stage_6_end_finish(&object, &steps);
					break;
				case stage_6_wake_states_ADDRESS:
					stage_6_wake_set_up(&object, &steps);
					break;
				case 0x773Au:
					stage_6_wake_show_players(&object, &steps);
					break;
				case 0x773Cu:
					stage_6_wake_start();
					break;
				case 0x773Eu:
					stage_6_wake_wave(&object, &steps);
					break;
				case post_bonus_2_scene_states_ADDRESS:
					post_bonus_2_scene_set_up(&object, &steps);
					break;
				case 0x7742u:
					post_bonus_2_scene_show(&object, &steps);
					break;
				case 0x7744u:
					post_bonus_2_scene_wait();
					break;
				case 0x7746u:
					post_bonus_2_scene_pan();
					break;
				case 0x7748u:
					post_bonus_2_scene_finish();
					break;
				case stage_7_scene_states_ADDRESS:
					object = stage_7_scene_set_up();
					break;
				case 0x774Cu:
					stage_7_scene_wait_scroll();
					break;
				case 0x774Eu:
					stage_7_scene_wait_signal();
					break;
				case 0x7750u:
					stage_7_scene_lift(&object, &steps);
					break;
				case stage_7_scene_steps_ADDRESS:
					stage_7_scene_wait_train();
					break;
				case 0x7754u:
					stage_7_scene_put_chain(&object, &steps);
					break;
				case 0x7756u:
					stage_7_scene_move_chain(&object, &steps);
					break;
				case 0x7758u:
					stage_7_scene_chain_done();
					break;
				case stage_7_end_states_ADDRESS:
					stage_7_end_set_up(&object, &steps);
					break;
				case 0x775Cu:
					stage_7_end_show(&object, &steps);
					break;
				case 0x775Eu:
					stage_7_end_board(object);
					break;
				case 0x7760u:
					object = stage_7_end_take_off();
					break;
				case 0x7762u:
					stage_7_end_slow_down(&object, &steps);
					break;
				case 0x7764u:
					stage_7_end_finish(&object, &steps);
					break;
				case stage_8_start_states_ADDRESS:
					stage_8_start_set_up(&object, &steps);
					break;
				case 0x7768u:
					stage_8_start_show(&object, &steps);
					break;
				case 0x776Au:
					stage_8_start_descend(&object, &steps);
					break;
				case 0x776Cu:
					stage_8_start_stop(&object, &steps);
					break;
				case 0x776Eu:
					object = stage_8_start_landing();
					break;
				case 0x7770u:
					stage_8_start_run_off(&object, &steps);
					break;
				case 0x7772u:
					stage_8_start_wait_end(&object, &steps);
					break;
				case stage_8_start_run_players_states_ADDRESS:
					stage_8_start_player_ride(object);
					break;
				case 0x7776u:
					stage_8_start_player_drop(object);
					break;
				case 0x7778u:
					stage_8_start_player_look(object);
					break;
				case 0x777Au:
					stage_8_start_player_turn(object);
					break;
				case 0x777Cu:
					stage_8_start_player_run(object);
					break;
				case 0x777Eu:
					stage_8_start_player_gone(object);
					break;
				case stage_8_end_states_ADDRESS:
					stage_8_end_set_up(&object, &steps);
					break;
				case 0x7782u:
					stage_8_end_show(&object, &steps);
					break;
				case 0x7784u:
					stage_8_end_hold();
					break;
				case 0x7786u:
					stage_8_end_switch_view(&object, &steps);
					break;
				case 0x7788u:
					stage_8_end_show_kind_13(&object, &steps);
					break;
				case 0x778Au:
					stage_8_end_reunion(&object, &steps);
					break;
				case 0x778Cu:
					stage_8_end_run_family(&object, &steps);
					break;
				case 0x778Eu:
					stage_8_end_finish(&object, &steps);
					break;
				case stage_8_end_run_family_states_ADDRESS:
					stage_8_end_actor_rest();
					break;
				case 0x7792u:
					stage_8_end_walker(&object, &steps);
					break;
				case 0x7794u:
					stage_8_end_maggie_taker(&object, &steps);
					break;
				case 0x7796u:
					stage_8_end_extra(&object, &steps);
					break;
				case 0x7798u:
					stage_8_end_slow_extra(&object, &steps);
					break;
				case stage_8_end_walker_actions_ADDRESS:
					stage_8_end_actor_start(object);
					break;
				case 0x779Cu:
					stage_8_end_walker_go(object);
					break;
				}
			}
			object += 0x60u;
			jumpers_left = stack;
			stack = jumpers_left - 1u;
		} while (jumpers_left != 1u);
	}
	*p_object = object;
	*p_steps = steps;
}

/* A stage's closing scene: a jumper waits its turn, then jumps with a shout. */
uint16_t stage_end_jumper_wait(uint16_t object, uint16_t u)
{
	uint32_t carry = 0;
	uint8_t blocked = 0, player = 0;
	uint16_t command = 0, exit_speed = 0;
	uint8_t blocked_2 = 0, blocked_3 = 0, jumper_player = 0, parameter = 0, type = 0;
	uint16_t jump_shout = 0, exit_speed_record = 0, x_speed = 0, y_speed = 0;

	blocked_2 = OBJECT(object)->blocked;
	blocked = blocked_2;
	if (blocked_2 != 0u)
	{
		blocked_3 = OBJECT(object)->blocked;
		OBJECT(object)->blocked = blocked_3 - 1u;
		return u;
	}
	jumper_player = OBJECT(object)->stage_end_jumper.jumper_player;
	player = jumper_player;
	if (player != 4u)
	{
		jump_shout = (((uint32_t)blocked << 8) | player) + 0x3F28u;
		command = jump_shout;
		carry = vector_queue_sound(command);
	}
	parameter = OBJECT(object)->parameter;
	exit_speed_record = stage_end_exit_speeds_ADDRESS + (int8_t)(((uint32_t)parameter << 1) << 1);
	exit_speed = exit_speed_record + 2u;
	x_speed = EXIT_SPEED(exit_speed_record)->x_speed;
	OBJECT(object)->x_speed = x_speed;
	y_speed = EXIT_SPEED(exit_speed - 0x2u)->y_speed;
	OBJECT(object)->z_speed = y_speed;
	type = OBJECT(object)->type;
	OBJECT(object)->type = type + 1u;
	return exit_speed;
}

/* A stage's closing scene (stage 5's): on its second leg, once small enough, a jumper plays a sound
   (4E00) and its last animation. */
void stage_end_jumper_last_leg(uint16_t object)
{
	uint32_t carry = 0;
	uint16_t command = 0;
	uint8_t hit_from_behind = 0, zoom_x = 0, type = 0;

	hit_from_behind = OBJECT(object)->hit_from_behind;
	if (hit_from_behind == 0u)
	{
		stage_end_jumper_fly(object);
		return;
	}
	zoom_x = OBJECT(object)->zoom_x;
	if (zoom_x < 0x80u)
	{
		stage_end_jumper_fly(object);
		return;
	}
	command = 0x4E00u;
	carry = vector_queue_sound(command);
	OBJECT(object)->animation = 0x9Cu;
	OBJECT(object)->zoom_x = 0x40u;
	OBJECT(object)->zoom_y = 0x40u;
	type = OBJECT(object)->type;
	OBJECT(object)->type = type + 1u;
}

/* A stage's closing scene: a jumper flies off into the distance, shrinking; at the smallest it shows
   again at normal size with its next animation. */
void stage_end_jumper_fly(uint16_t object)
{
	uint8_t animation = 0, speed_high = 0, speed_low = 0, zoom = 0;
	uint8_t zoom_x = 0, old_zoom = 0, jumper_player = 0, jumper_player_2 = 0, hit_from_behind = 0, type = 0;
	uint16_t x_speed = 0, old_x_speed = 0, slower_x_speed = 0, z_speed = 0, new_z_speed = 0;

	zoom_x = OBJECT(object)->zoom_x;
	old_zoom = zoom_x;
	zoom = old_zoom + 2u;
	OBJECT(object)->zoom_x = zoom;
	OBJECT(object)->zoom_y = zoom;
	if ((uint8_t)(old_zoom + 2u) < old_zoom)
	{
		jumper_player = OBJECT(object)->stage_end_jumper.jumper_player;
		animation = 0x98u + jumper_player;
		jumper_player_2 = OBJECT(object)->stage_end_jumper.jumper_player;
		if (jumper_player_2 == 4u)
			animation = 0x8Eu;
		OBJECT(object)->animation = animation;
		OBJECT(object)->zoom_x = 0x40u;
		OBJECT(object)->zoom_y = 0x40u;
		hit_from_behind = OBJECT(object)->hit_from_behind;
		OBJECT(object)->hit_from_behind = hit_from_behind + 1u;
		if (scene == 6u)
		{
			type = OBJECT(object)->type;
			OBJECT(object)->type = type + 1u;
		}
	}
	OBJECT(object)->flags |= 0x10u;
	x_speed = OBJECT(object)->x_speed;
	old_x_speed = x_speed;
	slower_x_speed = old_x_speed - 8u;
	speed_high = (uint8_t)(slower_x_speed >> 8);
	speed_low = (uint8_t)slower_x_speed;
	if (old_x_speed < 8u)
	{
		speed_high = 0u;
		speed_low = 0u;
	}
	OBJECT(object)->x_speed = ((uint32_t)speed_high << 8) | speed_low;
	z_speed = OBJECT(object)->z_speed;
	new_z_speed = z_speed + 0x16u;
	speed_high = (uint8_t)(new_z_speed >> 8);
	speed_low = (uint8_t)new_z_speed;
	if ((int16_t)(((uint32_t)speed_high << 8) | speed_low) >= -0x10)
	{
		speed_high = 0xFFu;
		speed_low = 0xF0u;
	}
	OBJECT(object)->z_speed = ((uint32_t)speed_high << 8) | speed_low;
}

/* A stage's closing scene: a jumper is gone when its animation ends. */
void stage_end_jumper_vanish(uint16_t object)
{
	uint8_t animation_flags = 0;

	animation_flags = OBJECT(object)->animation_flags;
	if ((animation_flags & 1u) != 0u)
		OBJECT(object)->flags = 0u;
}

/* Stage 2's closing scene: draws Krustyland's area 3. */
void stage_2_end_show_area_3(uint16_t *p_x, uint16_t *p_u)
{
	uint16_t layer_and_columns = 0, u = 0, x = 0;
	uint8_t old_scene_state = 0;

	map_area = 3u;
	io_write8(0x1FB9u, 0x3Fu);
	io_write8(0x1FBAu, 0x36u);
	layer_and_columns = 0x26u;
	vector_draw_layer_strips(layer_and_columns, &x, &u);
	io_write8(0x1FB9u, 0x13u);
	io_write8(0x1FBAu, 0x2Cu);
	old_scene_state = io_read8(scene_state);
	io_write8(scene_state, old_scene_state + 1u);
	*p_x = x;
	*p_u = u;
}

/* Stage 2's closing scene: puts the players, each with its voice. */
void stage_2_end_put_players(uint16_t default_object)
{
	uint32_t carry = 0;
	uint16_t record_number = 0, shout_command = 0, y = 0;
	uint8_t old_scene_state = 0;
	uint16_t shout = 0;

	scene_player_bit = 1u;
	scene_player = 0u;
	do
	{
		if ((players_present & scene_player_bit) != 0u)
		{
			record_number = (shout_command & 0xFFu) | ((uint32_t)(uint8_t)(scene_player + 4u) << 8);
			y = scene_put_placement(default_object, record_number);
			leftover_y = y;
			shout = scene_player + 0x3F28u;
			shout_command = shout;
			carry = vector_queue_sound(shout_command);
		}
		scene_player_bit = (uint32_t)scene_player_bit << 1;
		scene_player++;
	} while (scene_player != 4u);
	io_write16(0x18E2u, 0x80u);
	old_scene_state = io_read8(scene_state);
	io_write8(scene_state, old_scene_state + 1u);
}

/* Stage 2's closing scene: the view rises while the players wander from side to side; then the colours
   fade (in stage 5's step the objects are cleared instead). */
void stage_2_end_players_look_around(uint16_t *p_object, uint16_t *p_palette_job)
{
	uint16_t object = (uint16_t)*p_object;
	uint16_t palette_job = (uint16_t)*p_palette_job;
	uint16_t request = 0;
	uint16_t stack = 0;
	uint8_t old_scene_state = 0;
	uint16_t look_wait = 0, layer_a_y = 0, new_layer_a_y = 0;

	look_wait = io_read16(0x18E2u);
	io_write16(0x18E2u, look_wait - 1u);
	if (look_wait == 1u)
	{
		old_scene_state = io_read8(scene_state);
		io_write8(scene_state, old_scene_state + 1u);
		if (game_step == 9u)
			vector_clear_objects(&object, &palette_job);
		else
		{
			palette_request_kind = 4u;
			request = 0x1EE0u;
			palette_job = vector_palette_request(palette_job, request);
			io_write16(0x18E2u, 0x100u);
		}
	}
	else
	{
		layer_a_y = layer_a_scroll_y;
		new_layer_a_y = layer_a_y + 0x10u;
		layer_a_scroll_y = new_layer_a_y;
		object = OBJECT_ADDRESS(11);
		scene_player_bit = 1u;
		scene_player = 0u;
		do
		{
			if ((players_present & scene_player_bit) != 0u)
			{
				stack = object;
				if (((stack + (uint8_t)frame_count) & 0x40u) == 0u)
					OBJECT(object)->x_speed = -0x80;
				else
					OBJECT(object)->x_speed = 0x80;
			}
			object -= 0x60u;
			scene_player_bit = (uint32_t)scene_player_bit << 1;
			scene_player++;
		} while (scene_player != 4u);
	}
	*p_object = object;
	*p_palette_job = palette_job;
}

/* A scripted scene: is over, and the objects are cleared. */
void scene_end(uint16_t *p_x, uint16_t *p_u)
{
	uint16_t u = 0, x = 0;

	scene_running = 0u;
	*p_x = x;
	*p_u = u;
	vector_clear_objects(p_x, p_u);
}

/* Stage 5's closing scene: its sounds (7E00, 9A00), two palette effects, the gorge's area 1 and a
   kind-10 object (object_12_placements 8). */
void stage_5_end_set_up(uint16_t *p_default_object, uint16_t *p_u)
{
	uint16_t default_object = (uint16_t)*p_default_object;
	uint16_t u = (uint16_t)*p_u;
	uint32_t carry = 0;
	uint16_t command = 0, ignored16 = 0, ignored16_2 = 0, layer_and_columns = 0, object = 0, record_number = 0, request = 0, u_2 = 0;
	uint8_t old_scene_state = 0;

	if (layer_clear_pending != 0u)
		return;
	command = 0x7E00u;
	carry = vector_queue_sound(command);
	command = 0x9A00u;
	carry = vector_queue_sound_unless_attract(command);
	palette_request_kind = 2u;
	request = 0x10u;
	u = vector_palette_request(u, request);
	io_write16(0x18E4u, u);
	palette_request_kind = 2u;
	request = 0x11u;
	u = vector_palette_request(u, request);
	io_write16(0x18E6u, u);
	io_write8(0x1FB9u, 0x3Fu);
	io_write8(0x1FBAu, 0x36u);
	map_scene = 0x89u;
	map_area = 1u;
	vector_set_layer_modes();
	layer_and_columns = 0x26u;
	vector_draw_layer_strips(layer_and_columns, &ignored16, &ignored16_2);
	layer_and_columns = 0x126u;
	vector_draw_layer_strips(layer_and_columns, &default_object, &u_2);
	io_write8(0x1FB9u, 0x13u);
	io_write8(0x1FBAu, 0x2Cu);
	record_number = 0x826u;
	object = scene_put_placement(default_object, record_number);
	leftover_y = object;
	old_scene_state = io_read8(scene_state);
	io_write8(scene_state, old_scene_state + 1u);
	*p_default_object = default_object;
	*p_u = u_2;
}

/* Stage 5's closing scene: stops its palette effects and shows the players (no scenario reaches it). */
void stage_5_end_show_players(uint16_t *p_x, uint16_t *p_u)
{
	uint16_t u = (uint16_t)*p_u;
	uint16_t x = 0;
	uint16_t first_effect = 0, second_effect = 0;

	first_effect = io_read16(0x18E4u);
	mem_write8(first_effect, 0u);
	second_effect = io_read16(0x18E6u);
	mem_write8(second_effect, 0u);
	*p_x = x;
	*p_u = u;
	stage_end_show_players(p_x, p_u);
}

/* A stage's closing scene: two palette effects, the gorge's area 3 and the players who played, the
   absent players' places blanked. */
void stage_end_show_players(uint16_t *p_default_object, uint16_t *p_u)
{
	uint16_t u = (uint16_t)*p_u;
	uint16_t default_object = 0, ignored16 = 0, ignored16_2 = 0, layer_and_columns = 0, layer_then_player = 0, object = 0, request = 0, scroll_x = 0, scroll_y = 0, u_2 = 0;
	uint8_t old_scene_state = 0;

	palette_request_kind = 2u;
	request = 0x12u;
	u = vector_palette_request(u, request);
	io_write16(0x18E4u, u);
	palette_request_kind = 2u;
	request = 0x13u;
	u = vector_palette_request(u, request);
	io_write16(0x18E6u, u);
	map_area = 3u;
	scroll_x = 0xFFF0u;
	vector_set_scroll_x(scroll_x);
	scroll_y = 0u;
	vector_set_scroll_y(scroll_y);
	io_write8(0x1FB9u, 0x3Fu);
	io_write8(0x1FBAu, 0x36u);
	layer_and_columns = 0x40u;
	vector_draw_layer_strips(layer_and_columns, &ignored16, &ignored16_2);
	layer_then_player = 0x126u;
	vector_draw_layer_strips(layer_then_player, &default_object, &u_2);
	shown_player = 0u;
	shown_player_bit = 1u;
	do
	{
		if ((players_present & shown_player_bit) != 0u)
		{
			layer_then_player = (layer_then_player & 0xFFu) | ((uint32_t)(uint8_t)(shown_player + 9u) << 8);
			object = scene_put_placement(default_object, layer_then_player);
			leftover_y = object;
			OBJECT(leftover_y)->attributes = 0x20u;
		}
		else
		{
			layer_then_player = (uint32_t)shown_player << 8;
			blank_absent_player(layer_then_player);
		}
		shown_player_bit = (uint32_t)shown_player_bit << 1;
		shown_player++;
	} while (shown_player != 4u);
	io_write8(0x1FB9u, 0x13u);
	io_write8(0x1FBAu, 0x2Cu);
	io_write16(0x18E2u, 0x40u);
	old_scene_state = io_read8(scene_state);
	io_write8(scene_state, old_scene_state + 1u);
	*p_default_object = default_object;
	*p_u = u_2;
}

/* Stage 5's closing scene: stops the palette effects and fades the colours. */
uint16_t stage_5_end_fade(uint16_t palette_job)
{
	uint16_t request = 0;
	uint8_t old_scene_state = 0;
	uint16_t fade_wait = 0, first_effect = 0, second_effect = 0;

	fade_wait = io_read16(0x18E2u);
	io_write16(0x18E2u, fade_wait - 1u);
	if (fade_wait != 1u)
		return palette_job;
	first_effect = io_read16(0x18E4u);
	mem_write8(first_effect, 0u);
	second_effect = io_read16(0x18E6u);
	mem_write8(second_effect, 0u);
	palette_request_kind = 4u;
	request = 0x1EE0u;
	palette_job = vector_palette_request(palette_job, request);
	io_write16(0x18E2u, 0xE0u);
	old_scene_state = io_read8(scene_state);
	io_write8(scene_state, old_scene_state + 1u);
	return palette_job;
}

/* Stage 5's closing scene: after the fade, it is over and the objects and sprites are cleared. */
void stage_5_end_finish(uint16_t *p_x, uint16_t *p_wave_steps)
{
	uint16_t x = (uint16_t)*p_x;
	uint16_t ignored16 = 0, wave_steps = 0;
	uint8_t wave_step = 0;
	uint16_t finish_wait = 0;

	finish_wait = io_read16(0x18E2u);
	io_write16(0x18E2u, finish_wait - 1u);
	if (finish_wait != 1u)
	{
		wave_steps = dream_wave_grow_steps_ADDRESS;
		wave_step = io_read8(0x18ECu);
		switch ((int8_t)(uint8_t)((uint32_t)wave_step << 1))
		{
		case 0:
			dream_wave_start(&x, &wave_steps);
			break;
		case 2:
			x = dream_wave_grow();
			break;
		case 4:
			x = dream_wave_keep();
			break;
		case 6:
			dream_wave_start_full();
			break;
		case 8:
			x = dream_wave_hold();
			break;
		case 10:
			x = dream_wave_shrink();
			break;
		case 12:
			dream_wave_done();
			break;
		}
	}
	else
	{
		scene_running = 0u;
		vector_clear_objects(&ignored16, &wave_steps);
		x = vector_clear_sprites();
	}
	*p_x = x;
	*p_wave_steps = wave_steps;
}

/* Stage 6's closing scene: sets a 128-frame wait. */
void stage_6_end_start(void)
{
	uint8_t old_scene_state = 0;

	io_write8(0x18E2u, 0x80u);
	old_scene_state = io_read8(scene_state);
	io_write8(scene_state, old_scene_state + 1u);
}

/* Stage 6's closing scene: after the wait, a palette effect and a sound (AB00) for 512 frames. */
uint16_t stage_6_end_effect(uint16_t u)
{
	uint32_t carry = 0;
	uint16_t command = 0, request = 0;
	uint8_t effect_wait = 0, old_scene_state = 0;

	effect_wait = io_read8(0x18E2u);
	io_write8(0x18E2u, effect_wait - 1u);
	if (effect_wait != 1u)
		return u;
	palette_request_kind = 5u;
	request = 0xEFFu;
	u = vector_palette_request(u, request);
	io_write16(0x18E4u, u);
	command = 0xAB00u;
	carry = vector_queue_sound(command);
	io_write16(0x18E2u, 0x200u);
	old_scene_state = io_read8(scene_state);
	io_write8(scene_state, old_scene_state + 1u);
	return u;
}

/* Stage 6's closing scene, first part: stops the effect and is over. */
void stage_6_end_finish(uint16_t *p_clear_to, uint16_t *p_count)
{
	uint16_t clear_to = (uint16_t)*p_clear_to;
	uint16_t count = (uint16_t)*p_count;
	uint16_t clear_from = 0;
	uint16_t finish_wait = 0, effect_job = 0;

	finish_wait = io_read16(0x18E2u);
	io_write16(0x18E2u, finish_wait - 1u);
	if (finish_wait != 1u)
		return;
	effect_job = io_read16(0x18E4u);
	mem_write8(effect_job, 0u);
	clear_from = scene_state;
	leftover_y = scene_state;
	clear_to = scene_substate;
	io_write8(scene_state, 0u);
	count = 0x1Fu;
	while (count != 0u)
	{
		mem_write8(clear_to, mem_read8(clear_from));
		clear_from++;
		leftover_y = clear_from;
		clear_to++;
		count--;
	}
	scene_running = 0u;
	*p_clear_to = clear_to;
	*p_count = count;
}

/* Stage 6's closing scene, second part: back to the gorge's area 1, the screen cleared. */
void stage_6_wake_set_up(uint16_t *p_x, uint16_t *p_u)
{
	uint16_t u = (uint16_t)*p_u;
	uint16_t x = 0;

	map_scene = 0x89u;
	map_area = 1u;
	vector_set_layer_modes();
	*p_x = x;
	*p_u = u;
	scene_clear(p_x, p_u);
}

/* Stage 6's closing scene: once the screen is clear, shows the players in the gorge. */
void stage_6_wake_show_players(uint16_t *p_x, uint16_t *p_u)
{
	uint16_t x = (uint16_t)*p_x;
	uint16_t u = (uint16_t)*p_u;

	if (layer_clear_pending == 0u)
		stage_end_show_players(&x, &u);
	*p_x = x;
	*p_u = u;
}

/* Stage 6's closing scene: sets 192 frames for the wave. */
void stage_6_wake_start(void)
{
	uint8_t old_scene_state = 0;

	io_write16(0x18E2u, 0xC0u);
	old_scene_state = io_read8(scene_state);
	io_write8(scene_state, old_scene_state + 1u);
}

/* Stage 6's closing scene: runs the dream's wave for 192 frames, then it is over. */
void stage_6_wake_wave(uint16_t *p_delay, uint16_t *p_u)
{
	uint16_t delay = 0, u = 0;
	uint16_t wave_wait = 0, delay_left = 0;

	u = dream_wave_fade_out();
	wave_wait = io_read16(0x18E2u);
	io_write16(0x18E2u, wave_wait - 1u);
	if (wave_wait == 1u)
		scene_running = 0u;
	delay = 0x2000u;
	do
	{
		delay_left = delay - 1u;
		delay = delay_left;
	} while (delay_left != 0u);
	*p_delay = delay;
	*p_u = u;
}

/* The scene after bonus 2: its colours and the layers' places, the screen cleared. */
void post_bonus_2_scene_set_up(uint16_t *p_x, uint16_t *p_u)
{
	uint16_t u = (uint16_t)*p_u;
	uint16_t ignored16 = 0, job = 0, request = 0, u_2 = 0, x = 0;
	uint8_t old_scene_state = 0;

	palette_request_kind = 1u;
	request = 0xE8Cu;
	vector_palette_request(u, request);
	job = 0u;
	vector_queue_job(job);
	layer_a_scroll_x = 0x10u;
	layer_b_scroll_x = 0xFFF0u;
	layer_a_scroll_y = 0x120u;
	layer_b_scroll_y = 0u;
	vector_clear_objects(&ignored16, &u_2);
	x = vector_clear_sprites();
	old_scene_state = io_read8(scene_state);
	io_write8(scene_state, old_scene_state + 1u);
	*p_x = x;
	*p_u = u_2;
}

/* The scene after bonus 2: the music (A000), bonus 2's area 2 with the kind-A4 object, the absent
   players' places blanked. */
void post_bonus_2_scene_show(uint16_t *p_x, uint16_t *p_u)
{
	uint16_t x = (uint16_t)*p_x;
	uint16_t u = (uint16_t)*p_u;
	uint32_t carry = 0;
	uint16_t command = 0, ignored16 = 0, ignored16_3 = 0, layer_and_columns = 0, player_and_blank = 0, record_number = 0, u_2 = 0, x_2 = 0;
	uint8_t old_scene_state = 0;

	if (layer_clear_pending != 0u)
		return;
	command = 0xA000u;
	carry = vector_queue_sound_unless_attract(command);
	record_number = 0x1300u;
	scene_put_placement(x, record_number);
	io_write8(0x1FB9u, 0x3Fu);
	io_write8(0x1FBAu, 0x36u);
	map_scene = 0x8Bu;
	map_area = 2u;
	vector_set_layer_modes();
	layer_and_columns = 0x26u;
	vector_draw_layer_strips(layer_and_columns, &ignored16, &ignored16_3);
	layer_and_columns = 0x126u;
	vector_draw_layer_strips(layer_and_columns, &x_2, &u_2);
	shown_player = 0u;
	shown_player_bit = 1u;
	do
	{
		if ((players_present & shown_player_bit) == 0u)
		{
			player_and_blank = ((uint32_t)shown_player << 8) | 1u;
			blank_absent_player(player_and_blank);
		}
		shown_player_bit = (uint32_t)shown_player_bit << 1;
		shown_player++;
	} while (shown_player != 4u);
	io_write8(0x1FB9u, 0x13u);
	io_write8(0x1FBAu, 0x2Cu);
	io_write16(0x18E2u, 0x80u);
	old_scene_state = io_read8(scene_state);
	io_write8(scene_state, old_scene_state + 1u);
	*p_x = x_2;
	*p_u = u_2;
}

/* The scene after bonus 2: waits 128 frames and lets the layers move. */
void post_bonus_2_scene_wait(void)
{
	uint8_t old_scene_state = 0;
	uint16_t pan_wait = 0;

	pan_wait = io_read16(0x18E2u);
	io_write16(0x18E2u, pan_wait - 1u);
	if (pan_wait == 1u)
	{
		layer_a_offset_y = 0u;
		layer_rows_on = 1u;
		layer_a_edges_on = 1u;
		draw_all_layer_edges = 1u;
		old_scene_state = io_read8(scene_state);
		io_write8(scene_state, old_scene_state + 1u);
	}
}

/* The scene after bonus 2: the two layers part as the view moves, the kind-A4 object going with it. */
void post_bonus_2_scene_pan(void)
{
	uint32_t carry = 0;
	uint16_t layer_a_scroll_y_low = 0, layer_b_scroll_y_low = 0;
	uint8_t old_scene_state = 0;
	uint32_t layer_b_scroll_y_halfword = 0;

	layer_a_scroll_y_low = AT16(layer_a_scroll_y, -1);
	carry = (uint16_t)(layer_a_scroll_y_low - 0x80u) < layer_a_scroll_y_low;
	AT16(layer_a_scroll_y, -1) = layer_a_scroll_y_low - 0x80u;
	layer_a_scroll_y = (layer_a_scroll_y & 0xFFu) | (((uint16_t)((uint32_t)(uint8_t)(((uint16_t)(int8_t)0xFFu >> 8) + (uint8_t)(layer_a_scroll_y >> 8u) + carry) << 8) >> 8 & 0xFFu) << 8u);
	layer_b_scroll_y_low = (((uint32_t)(layer_b_scroll_y & 0xFFu) << 8u) | layer_b_scroll_y_fraction);
	carry = (uint16_t)(layer_b_scroll_y_low + 0x40u) < layer_b_scroll_y_low;
	layer_b_scroll_y_halfword = layer_b_scroll_y_low + 0x40u;
	layer_b_scroll_y = (layer_b_scroll_y & 0xFF00u) | ((layer_b_scroll_y_halfword >> 8u) & 0xFFu);
	layer_b_scroll_y_fraction = (uint8_t)layer_b_scroll_y_halfword;
	layer_b_scroll_y = (layer_b_scroll_y & 0xFFu) | (((uint16_t)((uint32_t)(uint8_t)(0u + (uint8_t)(layer_b_scroll_y >> 8u) + carry) << 8) >> 8 & 0xFFu) << 8u);
	OBJECT(OBJECT_ADDRESS(8))->y_speed = -0x80;
	if ((int16_t)layer_b_scroll_y >= 0x20)
	{
		OBJECT(OBJECT_ADDRESS(8))->y_speed = 0;
		io_write16(0x18E2u, 0x60u);
		old_scene_state = io_read8(scene_state);
		io_write8(scene_state, old_scene_state + 1u);
	}
}

/* The scene after bonus 2: after 96 frames, it is over. */
void post_bonus_2_scene_finish(void)
{
	uint16_t finish_wait = 0;

	finish_wait = io_read16(0x18E2u);
	io_write16(0x18E2u, finish_wait - 1u);
	if (finish_wait == 1u)
		scene_running = 0u;
}
