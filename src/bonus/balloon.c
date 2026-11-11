/**
 *    Name:        bonus/balloon.c
 *    Description: the bank's jump table, then bonus 1: blow up the balloon (the step after stage 1)
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    11-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the game's 053248 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

/* Runs bonus 1's contest by the scene's state: the players' portraits along the bottom, then the start,
   the blowing, the result and the flight of the balloons. */
void bonus_1_contest(void)
{
	uint32_t carry = 0;
	uint8_t state_offset = 0;
	uint16_t d = 0, ignored16 = 0, ignored16_2 = 0, state_table = 0;
	uint8_t state_number = 0;

	bonus_draw_x = 0x7Cu;
	bonus_draw_y = 0x98u;
	portrait_animation = 0x10u;
	bonus_show_player_portraits();
	d = bonus_1_zoom_players();
	state_table = bonus_1_contest_states_ADDRESS;
	state_number = io_read8(scene_state);
	state_offset = (uint32_t)state_number << 1;
	switch ((int8_t)state_offset)
	{
	case 0:
		bonus_1_contest_start(&ignored16, &d, &carry);
		return;
	case 2:
		bonus_1_contest_play(&ignored16, &ignored16_2, &carry);
		return;
	case 4:
		bonus_1_finish(&ignored16, &d, &carry);
		return;
	case 6:
		bonus_1_contest_set_up(&ignored16, &ignored16_2, &carry);
		return;
	case 8:
		bonus_1_contest_ready(&ignored16, &ignored16_2, &carry);
		return;
	case 10:
		bonus_1_start_music(&ignored16_2, &carry);
		return;
	case 12:
		bonus_1_blow_until_done(&ignored16, &ignored16_2, &carry);
		return;
	case 14:
		bonus_1_finish_music(&ignored16_2, &carry);
		return;
	case 16:
		bonus_1_results(&ignored16, &ignored16_2, &carry);
		return;
	case 18:
		bonus_1_top_up_balloons(&ignored16, &ignored16_2, &carry);
		return;
	case 20:
		bonus_1_fly_away(&ignored16, &d, &carry);
		return;
	case 22:
		d = (d & 0xFFu) | ((uint32_t)state_offset << 8);
		bonus_1_end(&d, &carry);
		return;
	case 24:
		bonus_1_fly(&state_table, &d, &carry);
		return;
	case 26:
		bonus_1_popped(&state_table, &d, &carry);
		return;
	case 28:
		bonus_1_take_off(state_table);
		return;
	case 30:
		bonus_1_lift_off(state_table);
		return;
	case 32:
		bonus_1_speed_up(state_table, &ignored16_2, &carry);
		return;
	case 34:
		bonus_1_rise(state_table, &ignored16_2, &carry);
		return;
	case 36:
		bonus_1_pop(state_table, &ignored16_2, &carry);
		return;
	case 38:
		bonus_1_fall(state_table, &ignored16_2, &carry);
		return;
	case 40:
		bonus_1_lie(state_table);
		return;
	case 42:
		bonus_1_fall_done();
		return;
	case 44:
		bonus_pan_start(&ignored16_2, &carry);
		return;
	case 46:
		bonus_pan_up(&ignored16, &ignored16_2, &carry);
		return;
	case 48:
	case 52:
		bonus_hide_hints();
		return;
	case 50:
		bonus_show_hints_1(state_table, &ignored16_2, &carry);
		return;
	case 54:
		bonus_show_hints_2(state_table, &ignored16_2, &carry);
		return;
	case 56:
		bonus_title_wait();
		return;
	case 58:
		d = (uint32_t)state_offset << 8;
		bonus_title_show(&state_table, &d, &carry);
		return;
	case 60:
		bonus_title_done();
		return;
	case -6:
		bonus_1_intro_pan(&ignored16, &d, &carry);
		return;
	case -4:
		bonus_1_intro_set_up(&ignored16, &ignored16_2, &carry);
		return;
	case -2:
		bonus_1_intro_show_how(&ignored16, &ignored16_2, &carry);
		return;
	}
}

/* Runs bonus 2's contest by its state (from 3 on): the players' set up, the countdown, the yelling, the
   results and the end. */
void bonus_2_contest(void)
{
	uint8_t state_number = 0;
	uint8_t read_state = 0;

	read_state = io_read8(bonus_2_state);
	state_number = read_state;
	if ((int8_t)state_number < 3)
	{
		state_number = 3u;
		io_write8(bonus_2_state, 3u);
	}
	switch ((int8_t)(uint8_t)((uint32_t)state_number << 1))
	{
	case 0:
		bonus_2_start_music();
		return;
	case 2:
		bonus_2_intro_set_up();
		return;
	case 4:
		bonus_2_intro_try();
		return;
	case 6:
		bonus_2_set_up();
		return;
	case 8:
		bonus_2_countdown();
		return;
	case 10:
		bonus_2_yell();
		return;
	case 12:
		bonus_2_results();
		return;
	case 14:
		bonus_2_end();
		return;
	}
}

/* Runs stage 1's boss, the wrestler, each frame: reacts to a hit, runs its state, keeps it inside its
   fighting area and draws its health gauge. */
void wrestler_update(uint16_t object, uint16_t state)
{
	uint32_t carry = 0;
	uint8_t b = 0, d = 0, state_offset = 0;
	uint16_t state_table = 0, step_and_row = 0;
	uint8_t state_2 = 0;

	state = wrestler_check_hit(object, (uint8_t)state);
	b = (uint8_t)state;
	state_table = wrestler_states_ADDRESS;
	state_2 = OBJECT(object)->state;
	state_offset = state_2;
	carry = (int8_t)state_offset < 0;
	state_offset = (uint32_t)state_offset << 1;
	d = b;
	switch ((int8_t)state_offset)
	{
	case 0:
		wrestler_entrance(object, d);
		break;
	case 2:
		wrestler_walk(object);
		break;
	case 4:
		wrestler_punch(object, d);
		break;
	case 6:
		wrestler_guard(object, d);
		break;
	case 8:
	case 10:
		wrestler_jump(object, d);
		break;
	case 12:
		wrestler_idle(object, d);
		break;
	case 14:
		wrestler_wait_target_up(object);
		break;
	case 16:
		wrestler_beaten_wait(object, state_table);
		break;
	case 18:
		wrestler_blink_out(object, d, carry);
		break;
	case 20:
		wrestler_fall(object);
		break;
	case 22:
		wrestler_lie(object);
		break;
	case 24:
		wrestler_get_up(object);
		break;
	case 26:
		wrestler_flinch_wait(object);
		break;
	case 28:
		wrestler_flinch_land(object);
		break;
	case 30:
		wrestler_put_in(object);
		break;
	case 32:
		wrestler_entrance_drop(object);
		break;
	case 34:
		wrestler_entrance_pose(object, state_table);
		break;
	case 36:
		wrestler_entrance_step_out(object);
		break;
	case 38:
		wrestler_entrance_land(object, state_table);
		break;
	case 40:
		wrestler_entrance_stand(object);
		break;
	case 42:
		wrestler_entrance_shout(object);
		break;
	case 44:
		wrestler_entrance_end(object);
		break;
	case 46:
		wrestler_punch_wind_up(object);
		break;
	case 48:
		wrestler_punch_strike(object);
		break;
	case 50:
		wrestler_punch_recover(object);
		break;
	case 52:
		wrestler_guarding(object);
		break;
	case 54:
		wrestler_jump_rise(object);
		break;
	case 56:
		wrestler_jump_land(object);
		break;
	case 58:
		wrestler_jump_recover(object);
		break;
	case 60:
		wrestler_jump_end(object, state_table);
		break;
	case 62:
		wrestler_idle_look(object);
		break;
	case 64:
		wrestler_idle_end(object, state_table);
		break;
	case -6:
		wrestler_beaten(object, d);
		break;
	case -4:
		wrestler_knocked_down(object, d);
		break;
	case -2:
		wrestler_flinch(object, d);
		break;
	}
	wrestler_keep_in_area(object);
	step_and_row = (uint32_t)wrestler_gauge_piece_health_by_players[(int8_t)((uint8_t)(player_count - 1u))] << 8;
	boss_shade_by_vitality(object, step_and_row);
}

/* Runs bonus 1's introduction: the title, the camera's pan and a character showing how to blow up the
   balloon. */
void bonus_1_intro(void)
{
	uint32_t carry = 0;
	uint8_t state_offset = 0;
	uint16_t bonus_number = 0, d = 0, ignored16 = 0, ignored16_2 = 0, state_table = 0;
	uint8_t state_number = 0;

	bonus_number = 0u;
	bonus_number = bonus_title(bonus_number);
	state_table = bonus_1_intro_states_ADDRESS;
	state_number = io_read8(scene_state);
	state_offset = (uint32_t)state_number << 1;
	switch ((int8_t)state_offset)
	{
	case 0:
		bonus_1_intro_pan(&ignored16, &bonus_number, &carry);
		return;
	case 2:
		bonus_1_intro_set_up(&ignored16, &ignored16_2, &carry);
		return;
	case 4:
		bonus_1_intro_show_how(&ignored16, &ignored16_2, &carry);
		return;
	case 6:
		bonus_1_contest_start(&ignored16, &bonus_number, &carry);
		return;
	case 8:
		bonus_1_contest_play(&ignored16, &ignored16_2, &carry);
		return;
	case 10:
		bonus_1_finish(&ignored16, &bonus_number, &carry);
		return;
	case 12:
		bonus_1_contest_set_up(&ignored16, &ignored16_2, &carry);
		return;
	case 14:
		bonus_1_contest_ready(&ignored16, &ignored16_2, &carry);
		return;
	case 16:
		bonus_1_start_music(&ignored16_2, &carry);
		return;
	case 18:
		bonus_1_blow_until_done(&ignored16, &ignored16_2, &carry);
		return;
	case 20:
		bonus_1_finish_music(&ignored16_2, &carry);
		return;
	case 22:
		bonus_1_results(&ignored16, &ignored16_2, &carry);
		return;
	case 24:
		bonus_1_top_up_balloons(&ignored16, &ignored16_2, &carry);
		return;
	case 26:
		bonus_1_fly_away(&ignored16, &bonus_number, &carry);
		return;
	case 28:
		d = (bonus_number & 0xFFu) | ((uint32_t)state_offset << 8);
		bonus_1_end(&d, &carry);
		return;
	case 30:
		bonus_1_fly(&state_table, &bonus_number, &carry);
		return;
	case 32:
		bonus_1_popped(&state_table, &bonus_number, &carry);
		return;
	case 34:
		bonus_1_take_off(state_table);
		return;
	case 36:
		bonus_1_lift_off(state_table);
		return;
	case 38:
		bonus_1_speed_up(state_table, &ignored16_2, &carry);
		return;
	case 40:
		bonus_1_rise(state_table, &ignored16_2, &carry);
		return;
	case 42:
		bonus_1_pop(state_table, &ignored16_2, &carry);
		return;
	case 44:
		bonus_1_fall(state_table, &ignored16_2, &carry);
		return;
	case 46:
		bonus_1_lie(state_table);
		return;
	case 48:
		bonus_1_fall_done();
		return;
	case 50:
		bonus_pan_start(&ignored16_2, &carry);
		return;
	case 52:
		bonus_pan_up(&ignored16, &ignored16_2, &carry);
		return;
	case 54:
	case 58:
		bonus_hide_hints();
		return;
	case 56:
		bonus_show_hints_1(state_table, &ignored16_2, &carry);
		return;
	case 60:
		bonus_show_hints_2(state_table, &ignored16_2, &carry);
		return;
	case 62:
		bonus_title_wait();
		return;
	case 64:
		d = (uint32_t)state_offset << 8;
		bonus_title_show(&state_table, &d, &carry);
		return;
	case 66:
		bonus_title_done();
		return;
	}
}

/* Runs bonus 2's introduction by its state (0 to 2): the music, the title and the camera's pan, then the
   first player in the game trying it out. */
void bonus_2_intro(void)
{
	uint8_t state_number = 0;

	state_number = io_read8(bonus_2_state);
	switch ((int8_t)(uint8_t)((uint32_t)state_number << 1))
	{
	case 0:
		bonus_2_start_music();
		return;
	case 2:
		bonus_2_intro_set_up();
		return;
	case 4:
		bonus_2_intro_try();
		return;
	case 6:
		bonus_2_set_up();
		return;
	case 8:
		bonus_2_countdown();
		return;
	case 10:
		bonus_2_yell();
		return;
	case 12:
		bonus_2_results();
		return;
	case 14:
		bonus_2_end();
		return;
	}
}

/* Runs a speech balloon (kind B0) by its state: put beside its speaker, then carried along with it until
   its time runs out. */
uint16_t speech_balloon_update(uint16_t object)
{
	uint8_t state = 0;

	state = OBJECT(object)->state;
	switch ((int8_t)(uint8_t)((uint32_t)state << 1))
	{
	case 0:
		return speech_balloon_start(object);
	case 2:
		return speech_balloon_follow(object);
	}
	unreachable();
}

/* Bonus 1's introduction, first state: waits for the camera's pan to end. */
void bonus_1_intro_pan(uint16_t *p_step_table, uint16_t *p_d, uint32_t *p_pan_done)
{
	uint16_t d = (uint16_t)*p_d;
	uint32_t pan_done = *p_pan_done;
	uint16_t step_table = 0;
	uint8_t state_number = 0;

	bonus_pan(&step_table, &d, &pan_done);
	if (pan_done)
	{
		state_number = io_read8(scene_state);
		io_write8(scene_state, state_number + 1u);
	}
	*p_step_table = step_table;
	*p_d = d;
	*p_pan_done = pan_done;
}

/* Bonus 1's introduction: puts the players' bonus objects and shows the first player in the game alone
   in the middle, the others hidden. */
void bonus_1_intro_set_up(uint16_t *p_balloon, uint16_t *p_d, uint32_t *p_carry)
{
	uint32_t carry = *p_carry;
	uint8_t players_done = 0;
	uint16_t balloon = 0, d = 0, ignored16 = 0, placed_part = 0;
	uint8_t in_game = 0, state_number = 0;
	uint16_t flyer = 0, middle_part = 0, blower = 0, blower_2 = 0, flyer_2 = 0, middle_part_2 = 0;

	bonus_keep_backdrop();
	bonus_mark_players_in_game();
	bonus_1_put_players(&ignored16, &d, &carry);
	balloon = OBJECT_ADDRESS(0);
	intro_player_number = 0u;
	intro_player_shown = 0u;
	do
	{
		in_game = OBJECT(balloon)->bonus_1.in_game;
		if (in_game == 0u || intro_player_shown != 0u)
		{
			OBJECT(balloon)->flags = 0u;
			flyer = OBJECT(balloon)->bonus_1.flyer;
			mem_write8(flyer, 0u);
			middle_part = OBJECT(balloon)->bonus_1.middle_part;
			mem_write8(middle_part, 0u);
			blower = OBJECT(balloon)->bonus_1.blower;
			mem_write8(blower, 0u);
		}
		else
		{
			OBJECT(balloon)->attributes = 0x30u;
			io_write8(scene_shared_value, intro_player_number);
			intro_player_shown++;
			OBJECT(balloon)->x = 0x9Cu;
			OBJECT(balloon)->y = 0xE8u;
			OBJECT(balloon)->z = 0x28u;
			blower_2 = OBJECT(balloon)->bonus_1.blower;
			placed_part = blower_2;
			OBJECT(placed_part)->x = 0xAEu;
			OBJECT(placed_part)->y = 0xE8u;
			OBJECT(placed_part)->z = 0u;
			flyer_2 = OBJECT(balloon)->bonus_1.flyer;
			mem_write8(flyer_2, 0u);
			middle_part_2 = OBJECT(balloon)->bonus_1.middle_part;
			placed_part = middle_part_2;
			OBJECT(placed_part)->x = 0xAEu;
			OBJECT(placed_part)->y = 0xE8u;
			d = 0u;
			OBJECT(placed_part)->z = 0u;
		}
		balloon += 0xC0u;
		intro_player_number++;
		players_done = intro_player_number;
		carry = players_done < 4u;
	} while (players_done != 4u);
	state_number = io_read8(scene_state);
	io_write8(scene_state, state_number + 1u);
	d = (d & 0xFFu) | ((uint32_t)players_done << 8);
	*p_balloon = balloon;
	*p_d = d;
	*p_carry = carry;
}

/* Bonus 1's introduction: the shown player blows its balloon by itself, a press every 4 frames, while
   the button hints blink. */
void bonus_1_intro_show_how(uint16_t *p_player_balloon, uint16_t *p_d, uint32_t *p_at_limit)
{
	uint32_t at_limit = *p_at_limit;
	uint16_t bonus_player = 0, d = 0, ignored16 = 0, ignored16_2 = 0, player_balloon = 0, record = 0;
	uint16_t saved_bonus_player = 0, saved_player_balloon = 0;
	uint8_t shown_player_number = 0, player_number = 0;
	uint16_t object = 0;

	bonus_blink_hints();
	shown_player_number = io_read8(scene_shared_value);
	bonus_player = bonus_1_player_records[(int8_t)((uint8_t)((uint32_t)shown_player_number << 1)) / 2];
	object = BONUS_PLAYER(bonus_player)->object;
	player_balloon = object;
	OBJECT(player_balloon)->flags |= 0x10u;
	mem_write8(BONUS_PLAYER(bonus_player)->presses, 0u);
	if ((frame_count & 3u) == 0u)
		mem_write8(BONUS_PLAYER(bonus_player)->presses, 0x10u);
	saved_bonus_player = bonus_player;
	saved_player_balloon = player_balloon;
	bonus_1_press_sound(&ignored16, &ignored16_2, &at_limit);
	player_balloon = saved_player_balloon;
	record = saved_bonus_player;
	player_number = io_read8(scene_shared_value);
	d = (uint32_t)player_number << 8;
	*p_player_balloon = player_balloon;
	*p_d = d;
	bonus_1_blow(record, p_player_balloon, p_d, &at_limit);
	*p_at_limit = at_limit;
}

/* Bonus 1's contest, first state: runs its start by the sub-state. */
void bonus_1_contest_start(uint16_t *p_step_table, uint16_t *p_d, uint32_t *p_carry)
{
	uint16_t d = (uint16_t)*p_d;
	uint32_t carry = *p_carry;
	uint8_t step_offset = 0;
	uint16_t step_table = 0;
	uint8_t step_number = 0;

	for (;;)
	{
		portrait_animation = 0x10u;
		step_table = bonus_1_contest_start_steps_ADDRESS;
		step_number = io_read8(scene_substate);
		step_offset = step_number;
		carry = (int8_t)step_offset < 0;
		step_offset = (uint32_t)step_offset << 1;
		switch ((int8_t)step_offset)
		{
		case 0:
			bonus_1_contest_set_up(&step_table, &d, &carry);
			break;
		case 2:
			bonus_1_contest_ready(&step_table, &d, &carry);
			break;
		case 4:
			bonus_1_start_music(&d, &carry);
			break;
		case 6:
			bonus_1_blow_until_done(&step_table, &d, &carry);
			break;
		case 8:
			bonus_1_finish_music(&d, &carry);
			break;
		case 10:
			bonus_1_results(&step_table, &d, &carry);
			break;
		case 12:
			bonus_1_top_up_balloons(&step_table, &d, &carry);
			break;
		case 14:
			bonus_1_fly_away(&step_table, &d, &carry);
			break;
		case 16:
			d = (d & 0xFFu) | ((uint32_t)step_offset << 8);
			bonus_1_end(&d, &carry);
			break;
		case 18:
			bonus_1_fly(&step_table, &d, &carry);
			break;
		case 20:
			bonus_1_popped(&step_table, &d, &carry);
			break;
		case 22:
			d = bonus_1_take_off(step_table);
			break;
		case 24:
			d = bonus_1_lift_off(step_table);
			break;
		case 26:
			bonus_1_speed_up(step_table, &d, &carry);
			break;
		case 28:
			bonus_1_rise(step_table, &d, &carry);
			break;
		case 30:
			bonus_1_pop(step_table, &d, &carry);
			break;
		case 32:
			bonus_1_fall(step_table, &d, &carry);
			break;
		case 34:
			d = (d & 0xFFu) | ((uint32_t)step_offset << 8);
			bonus_1_lie(step_table);
			break;
		case 36:
			d = (d & 0xFFu) | ((uint32_t)step_offset << 8);
			bonus_1_fall_done();
			break;
		case 38:
			bonus_pan_start(&d, &carry);
			break;
		case 40:
			bonus_pan_up(&step_table, &d, &carry);
			break;
		case 42:
		case 46:
			d = (d & 0xFFu) | ((uint32_t)step_offset << 8);
			carry = bonus_hide_hints();
			break;
		case 44:
			bonus_show_hints_1(step_table, &d, &carry);
			break;
		case 48:
			bonus_show_hints_2(step_table, &d, &carry);
			break;
		case 50:
			d = bonus_title_wait();
			break;
		case 52:
			d = (d & 0xFFu) | ((uint32_t)step_offset << 8);
			bonus_title_show(&step_table, &d, &carry);
			break;
		case 54:
			d = (d & 0xFFu) | ((uint32_t)step_offset << 8);
			bonus_title_done();
			break;
		case -12:
			bonus_1_intro_pan(&step_table, &d, &carry);
			break;
		case -10:
			bonus_1_intro_set_up(&step_table, &d, &carry);
			break;
		case -8:
			bonus_1_intro_show_how(&step_table, &d, &carry);
			break;
		case -6:
			continue;
		case -4:
			bonus_1_contest_play(&step_table, &d, &carry);
			break;
		case -2:
			bonus_1_finish(&step_table, &d, &carry);
			break;
		}
		break;
	}
	*p_step_table = step_table;
	*p_d = d;
	*p_carry = carry;
}

/* Bonus 1's contest: sets the timer to 10 seconds, marks the players in the game, gives the absent
   players their press rates and puts everyone's balloon and its parts. */
void bonus_1_contest_set_up(uint16_t *p_player_object, uint16_t *p_d, uint32_t *p_carry)
{
	uint32_t carry = *p_carry;
	uint16_t d = 0, player_object = 0;
	uint8_t old_marge_presses = 0, old_homer_presses = 0, old_bart_presses = 0, old_lisa_presses = 0, step_number = 0;

	old_marge_presses = io_read8(bonus_1_presses);
	io_write8(bonus_1_presses, 0u);
	old_homer_presses = io_read8(ending_family_step);
	io_write8(ending_family_step, 0u);
	old_bart_presses = io_read8(dream_wave_line);
	io_write8(dream_wave_line, 0u);
	old_lisa_presses = io_read8(scene_layer_b_speed);
	io_write8(scene_layer_b_speed, 0u);
	bonus_seconds = 0x10u;
	bonus_mark_players_in_game();
	bonus_1_set_absent_rates();
	bonus_1_put_players(&player_object, &d, &carry);
	io_write8(scene_wait, 0x60u);
	step_number = io_read8(scene_substate);
	io_write8(scene_substate, step_number + 1u);
	d = (d & 0xFFu) | 0x6000u;
	*p_player_object = player_object;
	*p_d = d;
	*p_carry = carry;
}

/* Bonus 1's contest: shows the READY sign for 96 frames while the balloons stay as they are. */
void bonus_1_contest_ready(uint16_t *p_player_object, uint16_t *p_timer_x, uint32_t *p_carry)
{
	uint32_t carry = *p_carry;
	uint16_t ignored16 = 0, player_object = 0, timer_x = 0;
	uint8_t ready_frames = 0, state_number = 0, old_step = 0;

	bonus_show_ready();
	bonus_1_blow_all(&player_object, &ignored16);
	bonus_draw_x = 0xB8u;
	bonus_draw_y = 0xB8u;
	bonus_1_draw_sign();
	timer_x = bonus_draw_x;
	carry = (uint16_t)(timer_x + 0x28u) < timer_x;
	timer_x += 0x28u;
	bonus_draw_x = timer_x;
	bonus_draw_timer();
	ready_frames = io_read8(scene_wait);
	io_write8(scene_wait, ready_frames - 1u);
	if (ready_frames == 1u)
	{
		state_number = io_read8(scene_state);
		io_write8(scene_state, state_number + 1u);
		old_step = io_read8(scene_substate);
		carry = 0u;
		io_write8(scene_substate, 0u);
	}
	*p_player_object = player_object;
	*p_timer_x = timer_x;
	*p_carry = carry;
}

/* Bonus 1's contest, while it lasts: takes everyone's presses (the absent players' by their rates),
   blows the balloons and runs the sub-state. */
void bonus_1_contest_play(uint16_t *p_step_table, uint16_t *p_d, uint32_t *p_carry)
{
	uint32_t carry = *p_carry;
	uint8_t step_offset = 0;
	uint16_t d = 0, ignored16 = 0, step_table = 0, x = 0;
	uint8_t step_number = 0;

	for (;;)
	{
		bonus_1_take_presses();
		bonus_1_absent_presses();
		bonus_1_blow_all(&ignored16, &d);
		step_table = bonus_1_contest_play_steps_ADDRESS;
		step_number = io_read8(scene_substate);
		step_offset = step_number;
		carry = (int8_t)step_offset < 0;
		step_offset = (uint32_t)step_offset << 1;
		switch ((int8_t)step_offset)
		{
		case 0:
			*p_d = d;
			bonus_1_start_music(p_d, &carry);
			*p_step_table = step_table;
			*p_carry = carry;
			return;
		case 2:
			*p_step_table = x;
			*p_d = d;
			bonus_1_blow_until_done(p_step_table, p_d, &carry);
			*p_carry = carry;
			return;
		case 4:
			*p_d = d;
			bonus_1_finish_music(p_d, &carry);
			*p_step_table = step_table;
			*p_carry = carry;
			return;
		case 6:
			*p_step_table = x;
			*p_d = d;
			bonus_1_results(p_step_table, p_d, &carry);
			*p_carry = carry;
			return;
		case 8:
			*p_step_table = x;
			*p_d = d;
			bonus_1_top_up_balloons(p_step_table, p_d, &carry);
			*p_carry = carry;
			return;
		case 10:
			*p_step_table = x;
			*p_d = d;
			bonus_1_fly_away(p_step_table, p_d, &carry);
			*p_carry = carry;
			return;
		case 12:
			d = (d & 0xFFu) | ((uint32_t)step_offset << 8);
			*p_d = d;
			bonus_1_end(p_d, &carry);
			*p_step_table = step_table;
			*p_carry = carry;
			return;
		case 14:
			*p_step_table = step_table;
			*p_d = d;
			bonus_1_fly(p_step_table, p_d, &carry);
			*p_carry = carry;
			return;
		case 16:
			*p_step_table = step_table;
			*p_d = d;
			bonus_1_popped(p_step_table, p_d, &carry);
			*p_carry = carry;
			return;
		case 18:
			d = bonus_1_take_off(step_table);
			*p_step_table = step_table;
			*p_d = d;
			*p_carry = carry;
			return;
		case 20:
			d = bonus_1_lift_off(step_table);
			*p_step_table = step_table;
			*p_d = d;
			*p_carry = carry;
			return;
		case 22:
			*p_d = d;
			bonus_1_speed_up(step_table, p_d, &carry);
			*p_step_table = step_table;
			*p_carry = carry;
			return;
		case 24:
			*p_d = d;
			bonus_1_rise(step_table, p_d, &carry);
			*p_step_table = step_table;
			*p_carry = carry;
			return;
		case 26:
			*p_d = d;
			bonus_1_pop(step_table, p_d, &carry);
			*p_step_table = step_table;
			*p_carry = carry;
			return;
		case 28:
			*p_d = d;
			bonus_1_fall(step_table, p_d, &carry);
			*p_step_table = step_table;
			*p_carry = carry;
			return;
		case 30:
			d = (d & 0xFFu) | ((uint32_t)step_offset << 8);
			bonus_1_lie(step_table);
			*p_step_table = step_table;
			*p_d = d;
			*p_carry = carry;
			return;
		case 32:
			d = (d & 0xFFu) | ((uint32_t)step_offset << 8);
			bonus_1_fall_done();
			*p_step_table = step_table;
			*p_d = d;
			*p_carry = carry;
			return;
		case 34:
			*p_d = d;
			bonus_pan_start(p_d, &carry);
			*p_step_table = step_table;
			*p_carry = carry;
			return;
		case 36:
			*p_step_table = x;
			*p_d = d;
			bonus_pan_up(p_step_table, p_d, &carry);
			*p_carry = carry;
			return;
		case 38:
		case 42:
			d = (d & 0xFFu) | ((uint32_t)step_offset << 8);
			carry = bonus_hide_hints();
			*p_step_table = step_table;
			*p_d = d;
			*p_carry = carry;
			return;
		case 40:
			*p_d = d;
			bonus_show_hints_1(step_table, p_d, &carry);
			*p_step_table = step_table;
			*p_carry = carry;
			return;
		case 44:
			*p_d = d;
			bonus_show_hints_2(step_table, p_d, &carry);
			*p_step_table = step_table;
			*p_carry = carry;
			return;
		case 46:
			d = bonus_title_wait();
			*p_step_table = step_table;
			*p_d = d;
			*p_carry = carry;
			return;
		case 48:
			d = (d & 0xFFu) | ((uint32_t)step_offset << 8);
			*p_step_table = step_table;
			*p_d = d;
			bonus_title_show(p_step_table, p_d, &carry);
			*p_carry = carry;
			return;
		case 50:
			break;
		case -16:
			*p_step_table = x;
			*p_d = d;
			bonus_1_intro_pan(p_step_table, p_d, &carry);
			*p_carry = carry;
			return;
		case -14:
			*p_step_table = x;
			*p_d = d;
			bonus_1_intro_set_up(p_step_table, p_d, &carry);
			*p_carry = carry;
			return;
		case -12:
			*p_step_table = x;
			*p_d = d;
			bonus_1_intro_show_how(p_step_table, p_d, &carry);
			*p_carry = carry;
			return;
		case -10:
			*p_step_table = x;
			*p_d = d;
			bonus_1_contest_start(p_step_table, p_d, &carry);
			*p_carry = carry;
			return;
		case -8:
			continue;
		case -6:
			*p_step_table = x;
			*p_d = d;
			bonus_1_finish(p_step_table, p_d, &carry);
			*p_carry = carry;
			return;
		case -4:
			*p_step_table = x;
			*p_d = d;
			bonus_1_contest_set_up(p_step_table, p_d, &carry);
			*p_carry = carry;
			return;
		case -2:
			*p_step_table = x;
			*p_d = d;
			bonus_1_contest_ready(p_step_table, p_d, &carry);
			*p_carry = carry;
			return;
		}
		break;
	}
	d = (d & 0xFFu) | ((uint32_t)step_offset << 8);
	bonus_title_done();
	*p_step_table = step_table;
	*p_d = d;
	*p_carry = carry;
}

/* Bonus 1's contest: starts its music (sound 8900). */
void bonus_1_start_music(uint16_t *p_music_command, uint32_t *p_carry)
{
	uint32_t carry = *p_carry;
	uint16_t music_command = 0;
	uint8_t step_number = 0;

	music_command = 0x8900u;
	carry = vector_queue_sound_unless_attract(music_command);
	step_number = io_read8(scene_substate);
	io_write8(scene_substate, step_number + 1u);
	*p_music_command = music_command;
	*p_carry = carry;
}

/* Bonus 1's contest: shows GO and counts the time down; when a balloon is full or the time is up, stops
   the balloons and keeps each player's result (from its balloon's size) for the ranking. */
void bonus_1_blow_until_done(uint16_t *p_balloon, uint16_t *p_d, uint32_t *p_contest_over)
{
	uint32_t contest_over = *p_contest_over;
	uint8_t animation = 0, timer_x_high = 0, timer_x_low = 0, type = 0;
	uint16_t balloon = 0, blower = 0, d = 0, middle_part = 0;
	uint8_t balloon_count = 0;
	uint8_t in_game = 0, balloons_left = 0, state_number = 0, old_step = 0;
	uint16_t blower_2 = 0, middle_part_2 = 0, size = 0, size_over_minimum = 0, sign_x = 0, draw_x = 0;

	bonus_show_go();
	bonus_1_any_balloon_full(&balloon, &contest_over);
	if (contest_over)
	{
		balloon = OBJECT_ADDRESS(0);
		balloon_count = 4u;
		do
		{
			blower_2 = OBJECT(balloon)->bonus_1.blower;
			blower = blower_2;
			animation = 0x81u;
			in_game = OBJECT(balloon)->bonus_1.in_game;
			if (in_game == 0u)
				animation = 0xA9u;
			OBJECT(blower)->animation = animation;
			middle_part_2 = OBJECT(balloon)->bonus_1.middle_part;
			middle_part = middle_part_2;
			OBJECT(middle_part)->animation = 0x81u;
			size = OBJECT(balloon)->bonus_1.size;
			size_over_minimum = size - 0xA0u;
			type = (uint8_t)(size_over_minimum >> 2);
			OBJECT(balloon)->type = type;
			balloon += 0xC0u;
			balloons_left = balloon_count;
			balloon_count = balloons_left - 1u;
		} while (balloons_left != 1u);
		state_number = io_read8(scene_state);
		io_write8(scene_state, state_number + 1u);
		old_step = io_read8(scene_substate);
		contest_over = 0u;
		io_write8(scene_substate, 0u);
		leftover_y = middle_part;
		d = ((uint32_t)balloon_count << 8) | type;
	}
	else
	{
		contest_over = bonus_timer_tick();
		if (contest_over)
		{
			balloon = OBJECT_ADDRESS(0);
			balloon_count = 4u;
			do
			{
				blower_2 = OBJECT(balloon)->bonus_1.blower;
				blower = blower_2;
				animation = 0x81u;
				in_game = OBJECT(balloon)->bonus_1.in_game;
				if (in_game == 0u)
					animation = 0xA9u;
				OBJECT(blower)->animation = animation;
				middle_part_2 = OBJECT(balloon)->bonus_1.middle_part;
				middle_part = middle_part_2;
				OBJECT(middle_part)->animation = 0x81u;
				size = OBJECT(balloon)->bonus_1.size;
				size_over_minimum = size - 0xA0u;
				type = (uint8_t)(size_over_minimum >> 2);
				OBJECT(balloon)->type = type;
				balloon += 0xC0u;
				balloons_left = balloon_count;
				balloon_count = balloons_left - 1u;
			} while (balloons_left != 1u);
			state_number = io_read8(scene_state);
			io_write8(scene_state, state_number + 1u);
			old_step = io_read8(scene_substate);
			contest_over = 0u;
			io_write8(scene_substate, 0u);
			leftover_y = middle_part;
			d = ((uint32_t)balloon_count << 8) | type;
		}
		else
		{
			bonus_draw_x = 0xB8u;
			bonus_draw_y = 0xB8u;
			bonus_1_draw_sign();
			sign_x = bonus_draw_x;
			draw_x = sign_x;
			contest_over = (uint16_t)(draw_x + 0x28u) < draw_x;
			timer_x_high = (uint8_t)((uint16_t)(draw_x + 0x28u) >> 8);
			timer_x_low = (uint8_t)(draw_x + 0x28u);
			bonus_draw_x = ((uint32_t)timer_x_high << 8) | timer_x_low;
			bonus_draw_timer();
			d = ((uint32_t)timer_x_high << 8) | timer_x_low;
		}
	}
	*p_balloon = balloon;
	*p_d = d;
	*p_contest_over = contest_over;
}

/* Bonus 1's end: runs it by the sub-state: the music, the results, the small balloons topped up and the
   flight. */
void bonus_1_finish(uint16_t *p_step_table, uint16_t *p_d, uint32_t *p_carry)
{
	uint16_t d = (uint16_t)*p_d;
	uint32_t carry = *p_carry;
	uint8_t step_offset = 0;
	uint16_t step_table = 0;
	uint8_t step_number = 0;

	for (;;)
	{
		step_table = bonus_1_finish_steps_ADDRESS;
		step_number = io_read8(scene_substate);
		step_offset = step_number;
		carry = (int8_t)step_offset < 0;
		step_offset = (uint32_t)step_offset << 1;
		switch ((int8_t)step_offset)
		{
		case 0:
			bonus_1_finish_music(&d, &carry);
			break;
		case 2:
			bonus_1_results(&step_table, &d, &carry);
			break;
		case 4:
			bonus_1_top_up_balloons(&step_table, &d, &carry);
			break;
		case 6:
			bonus_1_fly_away(&step_table, &d, &carry);
			break;
		case 8:
			d = (d & 0xFFu) | ((uint32_t)step_offset << 8);
			bonus_1_end(&d, &carry);
			break;
		case 10:
			bonus_1_fly(&step_table, &d, &carry);
			break;
		case 12:
			bonus_1_popped(&step_table, &d, &carry);
			break;
		case 14:
			d = bonus_1_take_off(step_table);
			break;
		case 16:
			d = bonus_1_lift_off(step_table);
			break;
		case 18:
			bonus_1_speed_up(step_table, &d, &carry);
			break;
		case 20:
			bonus_1_rise(step_table, &d, &carry);
			break;
		case 22:
			bonus_1_pop(step_table, &d, &carry);
			break;
		case 24:
			bonus_1_fall(step_table, &d, &carry);
			break;
		case 26:
			d = (d & 0xFFu) | ((uint32_t)step_offset << 8);
			bonus_1_lie(step_table);
			break;
		case 28:
			d = (d & 0xFFu) | ((uint32_t)step_offset << 8);
			bonus_1_fall_done();
			break;
		case 30:
			bonus_pan_start(&d, &carry);
			break;
		case 32:
			bonus_pan_up(&step_table, &d, &carry);
			break;
		case 34:
		case 38:
			d = (d & 0xFFu) | ((uint32_t)step_offset << 8);
			carry = bonus_hide_hints();
			break;
		case 36:
			bonus_show_hints_1(step_table, &d, &carry);
			break;
		case 40:
			bonus_show_hints_2(step_table, &d, &carry);
			break;
		case 42:
			d = bonus_title_wait();
			break;
		case 44:
			d = (d & 0xFFu) | ((uint32_t)step_offset << 8);
			bonus_title_show(&step_table, &d, &carry);
			break;
		case 46:
			d = (d & 0xFFu) | ((uint32_t)step_offset << 8);
			bonus_title_done();
			break;
		case -20:
			bonus_1_intro_pan(&step_table, &d, &carry);
			break;
		case -18:
			bonus_1_intro_set_up(&step_table, &d, &carry);
			break;
		case -16:
			bonus_1_intro_show_how(&step_table, &d, &carry);
			break;
		case -14:
			bonus_1_contest_start(&step_table, &d, &carry);
			break;
		case -12:
			bonus_1_contest_play(&step_table, &d, &carry);
			break;
		case -10:
			continue;
		case -8:
			bonus_1_contest_set_up(&step_table, &d, &carry);
			break;
		case -6:
			bonus_1_contest_ready(&step_table, &d, &carry);
			break;
		case -4:
			bonus_1_start_music(&d, &carry);
			break;
		case -2:
			bonus_1_blow_until_done(&step_table, &d, &carry);
			break;
		}
		break;
	}
	*p_step_table = step_table;
	*p_d = d;
	*p_carry = carry;
}

/* Bonus 1's end: starts the results' music (sound 8800). */
void bonus_1_finish_music(uint16_t *p_music_command, uint32_t *p_carry)
{
	uint32_t carry = *p_carry;
	uint16_t music_command = 0;
	uint8_t step_number = 0;

	music_command = 0x8800u;
	carry = vector_queue_sound_unless_attract(music_command);
	step_number = io_read8(scene_substate);
	io_write8(scene_substate, step_number + 1u);
	*p_music_command = music_command;
	*p_carry = carry;
}

/* Bonus 1's end: shows the results; when they are done, marks the players whose balloon is too small and
   gives each a wait before its flight by its place. */
void bonus_1_results(uint16_t *p_balloon, uint16_t *p_d, uint32_t *p_results_done)
{
	uint16_t d = (uint16_t)*p_d;
	uint32_t results_done = *p_results_done;
	uint8_t a = 0, animation = 0, b = 0, player_number = 0, wait = 0;
	uint16_t balloon = 0, blower = 0, d_2 = 0, middle_part_object = 0, places = 0, wait_place = 0;
	uint8_t player_counter = 0;
	uint16_t saved_wait_place = 0;
	uint8_t too_small = 0, in_game = 0, step_number = 0;
	uint16_t size = 0, blower_2 = 0, middle_part = 0, place_address = 0;

	bonus_results(&balloon, &d, &results_done);
	a = (uint8_t)(d >> 8);
	b = (uint8_t)d;
	if (results_done == 0u)
		d_2 = ((uint32_t)a << 8) | b;
	else
	{
		balloon = OBJECT_ADDRESS(0);
		places = results_places_ADDRESS;
		wait_place = scene_palette_effect;
		player_counter = 0u;
		do
		{
			OBJECT(balloon)->bonus_1.flight = 0u;
			OBJECT(balloon)->bonus_1.flight_step = 0u;
			OBJECT(balloon)->bonus_1.too_small = 0u;
			size = OBJECT(balloon)->bonus_1.size;
			if (size <= 0x160u)
			{
				too_small = OBJECT(balloon)->bonus_1.too_small;
				OBJECT(balloon)->bonus_1.too_small = too_small + 1u;
				saved_wait_place = wait_place;
				blower_2 = OBJECT(balloon)->bonus_1.blower;
				blower = blower_2;
				animation = 0x82u;
				in_game = OBJECT(balloon)->bonus_1.in_game;
				if (in_game == 0u)
					animation = 0xAAu;
				OBJECT(blower)->animation = animation;
				middle_part = OBJECT(balloon)->bonus_1.middle_part;
				middle_part_object = middle_part;
				OBJECT(middle_part_object)->animation = 0x81u;
				wait_place = saved_wait_place;
			}
			place_address = places;
			places = place_address + 1u;
			wait = 0xFu * mem_read8(place_address);
			mem_write8(wait_place, wait);
			wait_place++;
			balloon += 0xC0u;
			player_counter = player_counter + 1u;
			player_number = player_counter;
			results_done = player_number < 4u;
		} while (player_number != 4u);
		step_number = io_read8(scene_substate);
		io_write8(scene_substate, step_number + 1u);
		leftover_y = wait_place;
		d_2 = ((uint32_t)player_counter << 8) | wait;
	}
	*p_balloon = balloon;
	*p_d = d_2;
	*p_results_done = results_done;
}

/* Bonus 1's end: the balloons too small blow up by themselves until big enough to fly, then a sound
   (AD00). */
void bonus_1_top_up_balloons(uint16_t *p_player_records_place, uint16_t *p_d, uint32_t *p_carry)
{
	uint32_t carry = *p_carry;
	uint8_t animation = 0, b = 0;
	uint16_t balloon = 0, blower = 0, bonus_player = 0, command = 0, d = 0, middle_part = 0, player_number = 0, player_records_place = 0;
	uint8_t player_counter = 0;
	uint8_t too_small = 0, in_game = 0, still_too_small = 0, step_number = 0;
	uint16_t size = 0, blower_2 = 0, middle_part_2 = 0;

	balloons_growing = 0u;
	balloon = OBJECT_ADDRESS(0);
	player_counter = 0u;
	do
	{
		too_small = OBJECT(balloon)->bonus_1.too_small;
		if (too_small != 0u)
		{
			size = OBJECT(balloon)->bonus_1.size;
			if (size > 0x160u)
			{
				OBJECT(balloon)->bonus_1.too_small = 0u;
				blower_2 = OBJECT(balloon)->bonus_1.blower;
				blower = blower_2;
				animation = 0x81u;
				in_game = OBJECT(balloon)->bonus_1.in_game;
				if (in_game == 0u)
					animation = 0xA9u;
				OBJECT(blower)->animation = animation;
				middle_part_2 = OBJECT(balloon)->bonus_1.middle_part;
				middle_part = middle_part_2;
				leftover_y = middle_part;
				OBJECT(middle_part)->animation = 0x81u;
			}
			else
			{
				bonus_player = bonus_1_player_records[(int8_t)((uint8_t)((uint32_t)player_counter << 1)) / 2];
				mem_write8(BONUS_PLAYER(bonus_player)->presses, 0u);
				if ((frame_count & 1u) == 0u)
					mem_write8(BONUS_PLAYER(bonus_player)->presses, 0x10u);
				player_number = (uint32_t)player_counter << 8;
				bonus_1_blow(bonus_player, &balloon, &player_number, &carry);
			}
		}
		still_too_small = OBJECT(balloon)->bonus_1.too_small;
		balloons_growing |= still_too_small;
		balloon += 0xC0u;
		player_counter = player_counter + 1u;
	} while (player_counter != 4u);
	if (balloons_growing == 0u)
	{
		command = 0xAD00u;
		vector_queue_sound(command);
		step_number = io_read8(scene_substate);
		io_write8(scene_substate, step_number + 1u);
	}
	bonus_1_press_sound(&player_records_place, &d, &carry);
	b = (uint8_t)d;
	d = ((uint32_t)player_counter << 8) | b;
	*p_player_records_place = player_records_place;
	*p_d = d;
	*p_carry = carry;
}

/* Bonus 1's end: after each player's wait, runs its balloon's flight; goes on when all four are gone. */
void bonus_1_fly_away(uint16_t *p_player_object, uint16_t *p_d, uint32_t *p_carry)
{
	uint16_t d = (uint16_t)*p_d;
	uint32_t carry = *p_carry;
	uint8_t flown = 0;
	uint16_t d_2 = 0, player_object = 0, wait_place = 0;
	uint8_t player_counter = 0;
	uint16_t saved_wait_place = 0;
	uint8_t old_flown = 0, flown_count = 0, step_number = 0;

	old_flown = io_read8(dream_wave_step);
	io_write8(dream_wave_step, 0u);
	player_object = OBJECT_ADDRESS(0);
	wait_place = scene_palette_effect;
	player_counter = 0u;
	do
	{
		if (mem_read8(wait_place) != 0u)
			mem_write8(wait_place, mem_read8(wait_place) - 1u);
		else
		{
			saved_wait_place = wait_place;
			bonus_1_flight(&player_object, &d);
			wait_place = saved_wait_place;
		}
		player_object += 0xC0u;
		wait_place++;
		player_counter = player_counter + 1u;
	} while (player_counter != 4u);
	flown_count = io_read8(dream_wave_step);
	flown = flown_count;
	carry = flown < 4u;
	if (flown == 4u)
	{
		step_number = io_read8(scene_substate);
		io_write8(scene_substate, step_number + 1u);
	}
	d_2 = (d & 0xFFu) | ((uint32_t)player_counter << 8);
	*p_player_object = player_object;
	*p_d = d_2;
	*p_carry = carry;
}

/* Bonus 1's last state: gives the winner its health and goes on to the step's next part. */
void bonus_1_end(uint16_t *p_d, uint32_t *p_carry)
{
	uint16_t d = (uint16_t)*p_d;
	uint32_t carry = *p_carry;
	uint16_t d_2 = 0;
	uint16_t subphase_and_countdown = 0;

	bonus_reward_winners(&d, &carry);
	step_phase++;
	subphase_and_countdown = d;
	step_subphase = (uint8_t)(d >> 8u);
	step_countdown = (uint8_t)d;
	d_2 = subphase_and_countdown;
	*p_d = d_2;
	*p_carry = carry;
}

/* Bonus 1: blows each player's balloon by its presses. */
void bonus_1_blow_all(uint16_t *p_player_object, uint16_t *p_d)
{
	uint32_t carry = 0;
	uint8_t player_number = 0;
	uint16_t d = 0, ignored16 = 0, ignored16_2 = 0, player_object = 0, record = 0;

	bonus_1_press_sound(&ignored16, &ignored16_2, &carry);
	player_object = OBJECT_ADDRESS(0);
	blowing_player_number = 0u;
	do
	{
		record = bonus_1_player_records[(int8_t)((uint8_t)((uint32_t)blowing_player_number << 1)) / 2];
		d = (uint32_t)blowing_player_number << 8;
		bonus_1_blow(record, &player_object, &d, &carry);
		player_object += 0xC0u;
		blowing_player_number++;
		player_number = blowing_player_number;
	} while (player_number != 4u);
	d = (d & 0xFFu) | ((uint32_t)player_number << 8);
	*p_player_object = player_object;
	*p_d = d;
}

/* Bonus 1: one player's balloon: a press makes it grow for 16 frames, else it shrinks; its zoom follows
   its size, and at the smallest it shows empty. */
void bonus_1_blow(uint16_t record, uint16_t *p_balloon, uint16_t *p_player_number, uint32_t *p_at_limit)
{
	uint16_t balloon = (uint16_t)*p_balloon;
	uint16_t player_number = (uint16_t)*p_player_number;
	uint32_t at_limit = *p_at_limit;
	uint8_t a = 0, animation = 0, animation_flags = 0, b = 0, state = 0;
	uint16_t blower = 0, middle_part = 0, middle_part_object = 0, y = 0;
	uint8_t negated_width_high = 0, negated_width = 0;
	uint16_t saved_balloon = 0, scaled_box_size = 0;
	uint8_t state_number = 0, animation_flags_2 = 0, animation_flags_3 = 0, growing = 0, animation_flags_4 = 0, timer = 0, animation_flags_5 = 0, growing_2 = 0, in_game = 0, animation_flags_6 = 0, animation_2 = 0, zoom_width = 0, zoom_height = 0, size_width = 0, size_height = 0, zoom_x = 0, zoom_x_2 = 0, in_game_2 = 0, checked_width = 0, checked_height = 0;
	uint16_t blower_2 = 0, blower_3 = 0, middle_part_2 = 0, blower_4 = 0, middle_part_3 = 0, growth = 0, growth_2 = 0;
	uint32_t box_dx_product = 0;

	blowing_player = player_number >> 8;
	state_number = io_read8(scene_state);
	state = state_number;
	at_limit = state < 0u;
	if (state == 0u)
	{
		blower_2 = OBJECT(balloon)->bonus_1.blower;
		blower = blower_2;
		animation_flags_2 = OBJECT(blower)->animation_flags;
		animation_flags = animation_flags_2 | 0x40u;
		OBJECT(blower)->animation_flags = animation_flags;
		leftover_y = blower;
		player_number = ((uint32_t)animation_flags << 8) | state;
	}
	else
	{
		animation_flags_3 = OBJECT(balloon)->animation_flags;
		OBJECT(balloon)->animation_flags = animation_flags_3 & 0xBFu;
		OBJECT(balloon)->bonus_1.growth = 0;
		if ((mem_read8(BONUS_PLAYER(record)->presses) & 0x30u) == 0u)
		{
			growing = OBJECT(balloon)->bonus_1.growing;
			if (growing == 0u)
			{
				blower_3 = OBJECT(balloon)->bonus_1.blower;
				blower = blower_3;
				animation_flags_4 = OBJECT(blower)->animation_flags;
				if ((animation_flags_4 & 1u) != 0u)
					OBJECT(balloon)->timer = 1u;
				timer = OBJECT(balloon)->timer;
				if (timer != 0u)
				{
					animation_flags_5 = OBJECT(blower)->animation_flags;
					OBJECT(blower)->animation_flags = animation_flags_5 | 0x40u;
					middle_part_2 = OBJECT(balloon)->bonus_1.middle_part;
					middle_part_object = middle_part_2;
					OBJECT(middle_part_object)->animation = 0x81u;
				}
				OBJECT(balloon)->bonus_1.growth = -0x1800;
			}
			else
			{
				growing_2 = OBJECT(balloon)->bonus_1.growing;
				OBJECT(balloon)->bonus_1.growing = growing_2 - 1u;
			}
		}
		else
		{
			OBJECT(balloon)->timer = 0u;
			blower_4 = OBJECT(balloon)->bonus_1.blower;
			blower = blower_4;
			animation = 2u;
			in_game = OBJECT(balloon)->bonus_1.in_game;
			if (in_game == 0u)
				animation = 0x2Au;
			OBJECT(blower)->animation = animation;
			animation_flags_6 = OBJECT(blower)->animation_flags;
			OBJECT(blower)->animation_flags = animation_flags_6 & 0xBFu;
			middle_part_3 = OBJECT(balloon)->bonus_1.middle_part;
			middle_part = middle_part_3;
			animation = 2u;
			animation_2 = OBJECT(middle_part)->animation;
			if (2u != animation_2)
				OBJECT(middle_part)->animation = animation | 0x80u;
			OBJECT(balloon)->bonus_1.growth = 0x1C00;
			OBJECT(balloon)->bonus_1.growing = 0x10u;
		}
		balloon_growing = 0u;
		growth = OBJECT(balloon)->bonus_1.growth;
		if ((int16_t)growth >= 0)
		{
			if ((OBJECT(balloon)->flags & 0x20u) != 0u)
			{
				at_limit = bonus_1_stretch_height(balloon);
				if (at_limit)
					bonus_1_stretch_width(balloon);
			}
			else if ((random_number & 3u) != 0u)
			{
				at_limit = bonus_1_stretch_height(balloon);
				if (at_limit)
					bonus_1_stretch_width(balloon);
			}
			else
			{
				at_limit = bonus_1_stretch_width(balloon);
				if (at_limit)
					bonus_1_stretch_height(balloon);
			}
		}
		else
		{
			growth_2 = OBJECT(balloon)->bonus_1.growth;
			OBJECT(balloon)->bonus_1.growth = 0u - growth_2;
			balloon_growing++;
			if ((random_number & 3u) != 0u)
			{
				at_limit = bonus_1_stretch_height(balloon);
				if (at_limit)
					bonus_1_stretch_width(balloon);
			}
			else
			{
				at_limit = bonus_1_stretch_width(balloon);
				if (at_limit)
					bonus_1_stretch_height(balloon);
			}
		}
		zoom_width = (uint8_t)(OBJECT(balloon)->bonus_1.width_zoom >> 8u);
		OBJECT(balloon)->zoom_x = zoom_width;
		zoom_height = (uint8_t)(OBJECT(balloon)->bonus_1.height_zoom >> 8u);
		OBJECT(balloon)->zoom_y = zoom_height;
		size_width = (uint8_t)(OBJECT(balloon)->bonus_1.width_zoom >> 8u);
		negated_width_high = 0u;
		negated_width = 0u - size_width;
		size_height = (uint8_t)(OBJECT(balloon)->bonus_1.height_zoom >> 8u);
		b = 0u - size_height;
		OBJECT(balloon)->bonus_1.size = b + (((uint32_t)negated_width_high << 8) | negated_width);
		saved_balloon = balloon;
		zoom_x = OBJECT(balloon)->zoom_x;
		scaled_box_size = konami_divx(0x4000u, zoom_x) * 0x20u;
		balloon = saved_balloon;
		OBJECT(balloon)->box_width = scaled_box_size >> 8;
		OBJECT(balloon)->box_depth = 0x40u;
		saved_balloon = balloon;
		zoom_x_2 = OBJECT(balloon)->zoom_x;
		box_dx_product = konami_divx(0x4000u, zoom_x_2) * 0u;
		y = (uint16_t)box_dx_product;
		at_limit = box_dx_product >> 15;
		scaled_box_size = y;
		b = (uint8_t)scaled_box_size;
		balloon = saved_balloon;
		OBJECT(balloon)->box_dx = scaled_box_size >> 8;
		OBJECT(balloon)->box_dy = 0x20;
		OBJECT(balloon)->box_height = 1u;
		in_game_2 = OBJECT(balloon)->bonus_1.in_game;
		a = in_game_2;
		if (in_game_2 != 0u)
		{
			OBJECT(balloon)->animation = 0x86u;
			checked_width = (uint8_t)(OBJECT(balloon)->bonus_1.width_zoom >> 8u);
			a = checked_width;
			at_limit = a < 0xB0u;
			if (a == 0xB0u)
			{
				checked_height = (uint8_t)(OBJECT(balloon)->bonus_1.height_zoom >> 8u);
				a = checked_height;
				at_limit = a < 0xB0u;
				if (a == 0xB0u)
				{
					OBJECT(balloon)->animation = 0x85u;
					OBJECT(balloon)->zoom_x = 0x40u;
					a = 0x40u;
					OBJECT(balloon)->zoom_y = 0x40u;
				}
			}
		}
		leftover_y = y;
		player_number = ((uint32_t)a << 8) | b;
	}
	*p_balloon = balloon;
	*p_player_number = player_number;
	*p_at_limit = at_limit;
}

/* Bonus 1: grows or shrinks the balloon's width by its speed, between 4000 and B000 (carry: at a limit). */
uint32_t bonus_1_stretch_width(uint16_t object)
{
	uint32_t at_limit = 0;
	uint16_t balloon = 0, change = 0;
	uint16_t saved_balloon = 0, scaled_growth = 0;
	uint16_t growth = 0, width_zoom = 0, width_zoom_2 = 0;

	saved_balloon = object;
	growth = OBJECT(object)->bonus_1.growth;
	scaled_growth = growth;
	width_zoom = OBJECT(object)->bonus_1.width_zoom;
	scaled_growth = ((((uint32_t)width_zoom * width_zoom) >> 16) * scaled_growth) >> 16;
	change = scaled_growth;
	balloon = saved_balloon;
	if (balloon_growing == 0u)
		change = 0u - change;
	width_zoom_2 = OBJECT(balloon)->bonus_1.width_zoom;
	change += width_zoom_2;
	if (change > 0xB000u)
	{
		OBJECT(balloon)->bonus_1.width_zoom = 0xB000u;
		at_limit = 1u;
		return at_limit;
	}
	if (change >= 0x4000u)
	{
		OBJECT(balloon)->bonus_1.width_zoom = change;
		at_limit = 0u;
		return at_limit;
	}
	OBJECT(balloon)->bonus_1.width_zoom = 0x4000u;
	at_limit = 1u;
	return at_limit;
}

/* Bonus 1: grows or shrinks the balloon's height by its speed, between 2000 and B000 (carry: at a
   limit). */
uint32_t bonus_1_stretch_height(uint16_t object)
{
	uint32_t at_limit = 0;
	uint16_t balloon = 0, change = 0;
	uint16_t saved_balloon = 0, scaled_growth = 0;
	uint16_t growth = 0, height_zoom = 0, old_height_zoom = 0;

	saved_balloon = object;
	growth = OBJECT(object)->bonus_1.growth;
	scaled_growth = growth;
	height_zoom = OBJECT(object)->bonus_1.height_zoom;
	scaled_growth = ((((uint32_t)height_zoom * height_zoom) >> 16) * scaled_growth) >> 16;
	change = scaled_growth;
	balloon = saved_balloon;
	if (balloon_growing == 0u)
		change = 0u - change;
	old_height_zoom = OBJECT(balloon)->bonus_1.height_zoom;
	change += old_height_zoom;
	if (change > 0xB000u)
	{
		OBJECT(balloon)->bonus_1.height_zoom = 0xB000u;
		at_limit = 1u;
		return at_limit;
	}
	if (change >= 0x2000u)
	{
		OBJECT(balloon)->bonus_1.height_zoom = change;
		at_limit = 0u;
		return at_limit;
	}
	OBJECT(balloon)->bonus_1.height_zoom = 0x2000u;
	at_limit = 1u;
	return at_limit;
}

/* Bonus 1: runs a player's balloon by its flight (field 43): flying off, or popped. */
void bonus_1_flight(uint16_t *p_object, uint16_t *p_d)
{
	uint16_t object = (uint16_t)*p_object;
	uint16_t d = (uint16_t)*p_d;
	uint32_t carry = 0;
	uint8_t flight_offset = 0;
	uint8_t flight = 0;

	flight = OBJECT(object)->bonus_1.flight;
	flight_offset = (uint32_t)flight << 1;
	switch ((int8_t)flight_offset)
	{
	case 0:
		bonus_1_fly(&object, &d, &carry);
		break;
	case 2:
		bonus_1_popped(&object, &d, &carry);
		break;
	case 4:
		d = bonus_1_take_off(object);
		break;
	case 6:
		d = bonus_1_lift_off(object);
		break;
	case 8:
		bonus_1_speed_up(object, &d, &carry);
		break;
	case 10:
		bonus_1_rise(object, &d, &carry);
		break;
	case 12:
		bonus_1_pop(object, &d, &carry);
		break;
	case 14:
		bonus_1_fall(object, &d, &carry);
		break;
	case 16:
		d = (d & 0xFFu) | ((uint32_t)flight_offset << 8);
		bonus_1_lie(object);
		break;
	case 18:
		d = (d & 0xFFu) | ((uint32_t)flight_offset << 8);
		bonus_1_fall_done();
		break;
	case 20:
		bonus_pan_start(&d, &carry);
		break;
	case 22:
		bonus_pan_up(&object, &d, &carry);
		break;
	case 24:
	case 28:
		d = (d & 0xFFu) | ((uint32_t)flight_offset << 8);
		bonus_hide_hints();
		break;
	case 26:
		bonus_show_hints_1(object, &d, &carry);
		break;
	case 30:
		bonus_show_hints_2(object, &d, &carry);
		break;
	case 32:
		d = bonus_title_wait();
		break;
	case 34:
		d = (d & 0xFFu) | ((uint32_t)flight_offset << 8);
		bonus_title_show(&object, &d, &carry);
		break;
	case 36:
		d = (d & 0xFFu) | ((uint32_t)flight_offset << 8);
		bonus_title_done();
		break;
	case -30:
		bonus_1_intro_pan(&object, &d, &carry);
		break;
	case -28:
		bonus_1_intro_set_up(&object, &d, &carry);
		break;
	case -26:
		bonus_1_intro_show_how(&object, &d, &carry);
		break;
	case -24:
		bonus_1_contest_start(&object, &d, &carry);
		break;
	case -22:
		bonus_1_contest_play(&object, &d, &carry);
		break;
	case -20:
		bonus_1_finish(&object, &d, &carry);
		break;
	case -18:
		bonus_1_contest_set_up(&object, &d, &carry);
		break;
	case -16:
		bonus_1_contest_ready(&object, &d, &carry);
		break;
	case -14:
		bonus_1_start_music(&d, &carry);
		break;
	case -12:
		bonus_1_blow_until_done(&object, &d, &carry);
		break;
	case -10:
		bonus_1_finish_music(&d, &carry);
		break;
	case -8:
		bonus_1_results(&object, &d, &carry);
		break;
	case -6:
		bonus_1_top_up_balloons(&object, &d, &carry);
		break;
	case -4:
		bonus_1_fly_away(&object, &d, &carry);
		break;
	case -2:
		d = (d & 0xFFu) | ((uint32_t)flight_offset << 8);
		bonus_1_end(&d, &carry);
		break;
	}
	*p_object = object;
	*p_d = d;
}

/* Bonus 1: runs a flying balloon by its step (field 44). */
void bonus_1_fly(uint16_t *p_object, uint16_t *p_d, uint32_t *p_carry)
{
	uint16_t object = (uint16_t)*p_object;
	uint16_t d = (uint16_t)*p_d;
	uint32_t carry = *p_carry;
	uint8_t step_offset = 0;
	uint8_t flight_step = 0;

	for (;;)
	{
		flight_step = OBJECT(object)->bonus_1.flight_step;
		step_offset = flight_step;
		carry = (int8_t)step_offset < 0;
		step_offset = (uint32_t)step_offset << 1;
		switch ((int8_t)step_offset)
		{
		case 0:
			d = bonus_1_take_off(object);
			break;
		case 2:
			d = bonus_1_lift_off(object);
			break;
		case 4:
			bonus_1_speed_up(object, &d, &carry);
			break;
		case 6:
			bonus_1_rise(object, &d, &carry);
			break;
		case 8:
			bonus_1_pop(object, &d, &carry);
			break;
		case 10:
			bonus_1_fall(object, &d, &carry);
			break;
		case 12:
			d = (d & 0xFFu) | ((uint32_t)step_offset << 8);
			bonus_1_lie(object);
			break;
		case 14:
			d = (d & 0xFFu) | ((uint32_t)step_offset << 8);
			bonus_1_fall_done();
			break;
		case 16:
			bonus_pan_start(&d, &carry);
			break;
		case 18:
			bonus_pan_up(&object, &d, &carry);
			break;
		case 20:
		case 24:
			d = (d & 0xFFu) | ((uint32_t)step_offset << 8);
			carry = bonus_hide_hints();
			break;
		case 22:
			bonus_show_hints_1(object, &d, &carry);
			break;
		case 26:
			bonus_show_hints_2(object, &d, &carry);
			break;
		case 28:
			d = bonus_title_wait();
			break;
		case 30:
			d = (d & 0xFFu) | ((uint32_t)step_offset << 8);
			bonus_title_show(&object, &d, &carry);
			break;
		case 32:
			d = (d & 0xFFu) | ((uint32_t)step_offset << 8);
			bonus_title_done();
			break;
		case -34:
			bonus_1_intro_pan(&object, &d, &carry);
			break;
		case -32:
			bonus_1_intro_set_up(&object, &d, &carry);
			break;
		case -30:
			bonus_1_intro_show_how(&object, &d, &carry);
			break;
		case -28:
			bonus_1_contest_start(&object, &d, &carry);
			break;
		case -26:
			bonus_1_contest_play(&object, &d, &carry);
			break;
		case -24:
			bonus_1_finish(&object, &d, &carry);
			break;
		case -22:
			bonus_1_contest_set_up(&object, &d, &carry);
			break;
		case -20:
			bonus_1_contest_ready(&object, &d, &carry);
			break;
		case -18:
			bonus_1_start_music(&d, &carry);
			break;
		case -16:
			bonus_1_blow_until_done(&object, &d, &carry);
			break;
		case -14:
			bonus_1_finish_music(&d, &carry);
			break;
		case -12:
			bonus_1_results(&object, &d, &carry);
			break;
		case -10:
			bonus_1_top_up_balloons(&object, &d, &carry);
			break;
		case -8:
			bonus_1_fly_away(&object, &d, &carry);
			break;
		case -6:
			d = (d & 0xFFu) | ((uint32_t)step_offset << 8);
			bonus_1_end(&d, &carry);
			break;
		case -4:
			continue;
		case -2:
			bonus_1_popped(&object, &d, &carry);
			break;
		}
		break;
	}
	*p_object = object;
	*p_d = d;
	*p_carry = carry;
}

/* Bonus 1: a balloon's flight starts: the player holds on to it. */
uint16_t bonus_1_take_off(uint16_t object)
{
	uint8_t animation = 0, in_game = 0;
	uint16_t blower = 0, d = 0, flyer = 0, middle_part_object = 0;
	uint8_t in_game_2 = 0, flight_step = 0;
	uint16_t flyer_2 = 0, middle_part = 0, blower_2 = 0;

	flyer_2 = OBJECT(object)->bonus_1.flyer;
	flyer = flyer_2;
	OBJECT(flyer)->flags = 0x80u;
	animation = 0x83u;
	in_game_2 = OBJECT(object)->bonus_1.in_game;
	in_game = in_game_2;
	if (in_game_2 == 0u)
		animation = 0xABu;
	OBJECT(flyer)->animation = animation;
	middle_part = OBJECT(object)->bonus_1.middle_part;
	middle_part_object = middle_part;
	OBJECT(middle_part_object)->animation = 0x83u;
	blower_2 = OBJECT(object)->bonus_1.blower;
	blower = blower_2;
	OBJECT(blower)->kind = 0xAu;
	OBJECT(blower)->animation = 0x8Fu;
	OBJECT(object)->bonus_1.lift_time = 0x20u;
	flight_step = OBJECT(object)->bonus_1.flight_step;
	OBJECT(object)->bonus_1.flight_step = flight_step + 1u;
	leftover_y = blower;
	d = 0x2000u | in_game;
	return d;
}

/* Bonus 1: the player and its balloon start rising. */
uint16_t bonus_1_lift_off(uint16_t object)
{
	uint16_t flyer = 0, z_speed = 0;
	uint8_t lift_time = 0, flight_step = 0;
	uint16_t flyer_2 = 0, z_speed_2 = 0;

	z_speed = 0xA0u;
	OBJECT(object)->z_speed = 0xA0;
	lift_time = OBJECT(object)->bonus_1.lift_time;
	OBJECT(object)->bonus_1.lift_time = lift_time - 1u;
	if (lift_time == 1u)
	{
		flyer_2 = OBJECT(object)->bonus_1.flyer;
		flyer = flyer_2;
		leftover_y = flyer;
		z_speed_2 = OBJECT(object)->z_speed;
		z_speed = z_speed_2;
		OBJECT(flyer)->z_speed = z_speed;
		flight_step = OBJECT(object)->bonus_1.flight_step;
		OBJECT(object)->bonus_1.flight_step = flight_step + 1u;
	}
	return z_speed;
}

/* Bonus 1: the flying player and balloon rise faster. */
void bonus_1_speed_up(uint16_t object, uint16_t *p_z_speed, uint32_t *p_carry)
{
	uint32_t carry = *p_carry;
	uint16_t flyer = 0, z_speed = 0;
	uint8_t flight_step = 0;
	uint16_t z_speed_2 = 0, flyer_2 = 0, z_speed_3 = 0;

	z_speed_2 = OBJECT(object)->z_speed;
	OBJECT(object)->z_speed = z_speed_2 + 8u;
	flyer_2 = OBJECT(object)->bonus_1.flyer;
	flyer = flyer_2;
	z_speed_3 = OBJECT(flyer)->z_speed;
	z_speed = z_speed_3;
	carry = (uint16_t)(z_speed + 8u) < z_speed;
	z_speed += 8u;
	OBJECT(flyer)->z_speed = z_speed;
	flight_step = OBJECT(object)->bonus_1.flight_step;
	OBJECT(object)->bonus_1.flight_step = flight_step + 1u;
	leftover_y = flyer;
	*p_z_speed = z_speed;
	*p_carry = carry;
}

/* Bonus 1: the flying player and balloon rise faster; an absent player's balloon pops on the way up, and
   one past the top is gone. */
void bonus_1_rise(uint16_t object, uint16_t *p_height, uint32_t *p_carry)
{
	uint32_t carry = *p_carry;
	uint16_t flyer = 0, height = 0;
	uint8_t in_game = 0, flown_count = 0;
	uint16_t z_speed = 0, flyer_2 = 0, z_speed_2 = 0, z = 0, z_2 = 0, flyer_3 = 0;

	z_speed = OBJECT(object)->z_speed;
	OBJECT(object)->z_speed = z_speed + 8u;
	flyer_2 = OBJECT(object)->bonus_1.flyer;
	flyer = flyer_2;
	z_speed_2 = OBJECT(flyer)->z_speed;
	OBJECT(flyer)->z_speed = z_speed_2 + 8u;
	in_game = OBJECT(object)->bonus_1.in_game;
	if (in_game == 0u)
	{
		z = OBJECT(object)->z;
		if (z > 0x80u)
		{
			OBJECT(object)->bonus_1.flight = 1u;
			OBJECT(object)->bonus_1.flight_step = 0u;
		}
	}
	z_2 = OBJECT(object)->z;
	height = z_2;
	carry = height < 0x180u;
	if (height > 0x180u)
	{
		OBJECT(object)->flags = 0u;
		flyer_3 = OBJECT(object)->bonus_1.flyer;
		carry = 0u;
		mem_write8(flyer_3, 0u);
		flown_count = io_read8(dream_wave_step);
		io_write8(dream_wave_step, flown_count + 1u);
	}
	leftover_y = flyer;
	*p_height = height;
	*p_carry = carry;
}

/* Bonus 1: runs a popped balloon by its step (field 44); never seen in the scenarios. */
void bonus_1_popped(uint16_t *p_balloon_object, uint16_t *p_d, uint32_t *p_carry)
{
	uint16_t balloon_object = (uint16_t)*p_balloon_object;
	uint8_t d = (uint8_t)*p_d;
	uint32_t carry = *p_carry;
	uint8_t animation_done = 0, step_offset = 0;
	uint16_t d_2 = 0;
	uint8_t flight_step = 0, popped_flags = 0, animation_ended = 0;

	flight_step = OBJECT(balloon_object)->bonus_1.flight_step;
	step_offset = flight_step;
	carry = (int8_t)step_offset < 0;
	step_offset = (uint32_t)step_offset << 1;
	d_2 = (d & 0xFFu) | ((uint32_t)step_offset << 8);
	switch ((int8_t)step_offset)
	{
	case 0:
		bonus_1_pop(balloon_object, &d_2, &carry);
		break;
	case 2:
		bonus_1_fall(balloon_object, &d_2, &carry);
		break;
	case 4:
		bonus_1_lie(balloon_object);
		break;
	case 6:
		bonus_1_fall_done();
		break;
	case 8:
		bonus_pan_start(&d_2, &carry);
		break;
	case 10:
		bonus_pan_up(&balloon_object, &d_2, &carry);
		break;
	case 12:
	case 16:
		carry = bonus_hide_hints();
		break;
	case 14:
		bonus_show_hints_1(balloon_object, &d_2, &carry);
		break;
	case 18:
		bonus_show_hints_2(balloon_object, &d_2, &carry);
		break;
	case 20:
		d_2 = bonus_title_wait();
		break;
	case 22:
		bonus_title_show(&balloon_object, &d_2, &carry);
		break;
	case 24:
		bonus_title_done();
		break;
	case -42:
		bonus_1_intro_pan(&balloon_object, &d_2, &carry);
		break;
	case -40:
		bonus_1_intro_set_up(&balloon_object, &d_2, &carry);
		break;
	case -38:
		bonus_1_intro_show_how(&balloon_object, &d_2, &carry);
		break;
	case -36:
		bonus_1_contest_start(&balloon_object, &d_2, &carry);
		break;
	case -34:
		bonus_1_contest_play(&balloon_object, &d_2, &carry);
		break;
	case -32:
		bonus_1_finish(&balloon_object, &d_2, &carry);
		break;
	case -30:
		bonus_1_contest_set_up(&balloon_object, &d_2, &carry);
		break;
	case -28:
		bonus_1_contest_ready(&balloon_object, &d_2, &carry);
		break;
	case -26:
		bonus_1_start_music(&d_2, &carry);
		break;
	case -24:
		bonus_1_blow_until_done(&balloon_object, &d_2, &carry);
		break;
	case -22:
		bonus_1_finish_music(&d_2, &carry);
		break;
	case -20:
		bonus_1_results(&balloon_object, &d_2, &carry);
		break;
	case -18:
		bonus_1_top_up_balloons(&balloon_object, &d_2, &carry);
		break;
	case -16:
		bonus_1_fly_away(&balloon_object, &d_2, &carry);
		break;
	case -14:
		bonus_1_end(&d_2, &carry);
		break;
	case -12:
		bonus_1_fly(&balloon_object, &d_2, &carry);
		break;
	case -10:
		bonus_1_popped(&balloon_object, &d_2, &carry);
		break;
	case -8:
		d_2 = bonus_1_take_off(balloon_object);
		break;
	case -6:
		d_2 = bonus_1_lift_off(balloon_object);
		break;
	case -4:
		bonus_1_speed_up(balloon_object, &d_2, &carry);
		break;
	case -2:
		bonus_1_rise(balloon_object, &d_2, &carry);
		break;
	}
	popped_flags = OBJECT(balloon_object)->animation_flags;
	animation_ended = popped_flags & 1u;
	animation_done = animation_ended;
	if (animation_ended != 0u)
	{
		carry = 0u;
		OBJECT(balloon_object)->flags = 0u;
	}
	d_2 = (d_2 & 0xFFu) | ((uint32_t)animation_done << 8);
	*p_balloon_object = balloon_object;
	*p_d = d_2;
	*p_carry = carry;
}

/* Bonus 1: the balloon pops (sound 6C00) and the player falls. */
void bonus_1_pop(uint16_t object, uint16_t *p_d, uint32_t *p_carry)
{
	uint32_t carry = *p_carry;
	uint16_t command = 0, d = 0, flyer = 0;
	uint8_t attributes = 0, flight_step = 0;
	uint16_t flyer_2 = 0;

	command = 0x6C00u;
	vector_queue_sound(command);
	OBJECT(object)->kind = 0x90u;
	OBJECT(object)->animation = 0x93u;
	carry = 0u;
	OBJECT(object)->z_speed = 0;
	flyer_2 = OBJECT(object)->bonus_1.flyer;
	flyer = flyer_2;
	OBJECT(flyer)->kind = 0x80u;
	attributes = OBJECT(flyer)->attributes;
	OBJECT(flyer)->attributes = attributes | 0x40u;
	OBJECT(flyer)->animation = 0x8Du;
	flight_step = OBJECT(object)->bonus_1.flight_step;
	OBJECT(object)->bonus_1.flight_step = flight_step + 1u;
	d = 0x8D00u;
	*p_d = d;
	*p_carry = carry;
}

/* Bonus 1: the popped balloon's player falls to the floor and lands. */
void bonus_1_fall(uint16_t object, uint16_t *p_d, uint32_t *p_landed)
{
	uint32_t landed = *p_landed;
	uint8_t lie_time = 0;
	uint16_t balloon = 0, d = 0, flyer_object = 0;
	uint16_t saved_balloon = 0;
	uint8_t flight_step = 0;
	uint16_t flyer = 0, flyer_2 = 0;

	flyer = OBJECT(object)->bonus_1.flyer;
	saved_balloon = object;
	object = flyer;
	vector_apply_gravity(object, &d, &landed);
	lie_time = (uint8_t)(d >> 8);
	balloon = saved_balloon;
	if (landed)
	{
		flyer_2 = OBJECT(balloon)->bonus_1.flyer;
		flyer_object = flyer_2;
		OBJECT(flyer_object)->animation = 0x8Eu;
		lie_time = 0x60u;
		OBJECT(balloon)->bonus_1.lie_time = 0x60u;
		flight_step = OBJECT(balloon)->bonus_1.flight_step;
		OBJECT(balloon)->bonus_1.flight_step = flight_step + 1u;
	}
	d = (d & 0xFFu) | ((uint32_t)lie_time << 8);
	*p_d = d;
	*p_landed = landed;
}

/* Bonus 1: the fallen player lies for 96 frames. */
void bonus_1_lie(uint16_t object)
{
	uint8_t lie_time = 0, flight_step = 0;

	lie_time = OBJECT(object)->bonus_1.lie_time;
	OBJECT(object)->bonus_1.lie_time = lie_time - 1u;
	if (lie_time == 1u)
	{
		flight_step = OBJECT(object)->bonus_1.flight_step;
		OBJECT(object)->bonus_1.flight_step = flight_step + 1u;
	}
}

/* Bonus 1: counts the fallen player as gone. */
void bonus_1_fall_done(void)
{
	uint8_t flown_count = 0;

	flown_count = io_read8(dream_wave_step);
	io_write8(dream_wave_step, flown_count + 1u);
}

/* Bonus 1: whether a player's balloon has grown past its limit (carry). */
void bonus_1_any_balloon_full(uint16_t *p_balloon, uint32_t *p_balloon_full)
{
	uint32_t balloon_full = *p_balloon_full;
	uint16_t balloon = 0;
	uint8_t balloon_count = 0;
	uint8_t balloons_left = 0;
	uint16_t size = 0;

	balloon = OBJECT_ADDRESS(0);
	balloon_count = 4u;
	for (;;)
	{
		size = OBJECT(balloon)->bonus_1.size;
		if (size >= 0x1A0u)
		{
			balloon_full = 1u;
			break;
		}
		balloon += 0xC0u;
		balloons_left = balloon_count;
		balloon_count = balloons_left - 1u;
		if (balloons_left == 1u)
		{
			balloon_full = 0u;
			break;
		}
	}
	*p_balloon = balloon;
	*p_balloon_full = balloon_full;
}

/* The bonuses' timer: counts a frame down (carry when the time is up). */
uint32_t bonus_timer_tick(void)
{
	uint32_t time_up = 0, half_carry = 0;
	uint8_t frames = 0, seconds = 0;
	uint8_t old_frames = 0, old_seconds = 0;

	old_frames = bonus_frames;
	frames = old_frames;
	if (old_frames == 0u)
	{
		bonus_frames = frames;
		old_seconds = bonus_seconds;
		seconds = old_seconds;
		if (old_seconds == 0u)
		{
			bonus_draw_x = 0xE0u;
			bonus_draw_y = 0xB8u;
			bonus_draw_timer();
			time_up = 1u;
			return time_up;
		}
		half_carry = ((uint8_t)(seconds ^ 0x99u ^ (seconds - 0x67u)) >> 4) & 1u;
		time_up = (uint8_t)(seconds - 0x67u) < seconds;
		bonus_seconds = konami_daa((uint8_t)(seconds - 0x67u), half_carry, time_up);
		bonus_frames = 0x98u;
		time_up = 0u;
		return time_up;
	}
	half_carry = ((uint8_t)(frames ^ 0x99u ^ (frames - 0x67u)) >> 4) & 1u;
	time_up = (uint8_t)(frames - 0x67u) < frames;
	frames = konami_daa((uint8_t)(frames - 0x67u), half_carry, time_up);
	if (frames == 0u)
	{
		bonus_frames = frames;
		old_seconds = bonus_seconds;
		seconds = old_seconds;
		if (old_seconds == 0u)
		{
			bonus_draw_x = 0xE0u;
			bonus_draw_y = 0xB8u;
			bonus_draw_timer();
			time_up = 1u;
			return time_up;
		}
		half_carry = ((uint8_t)(seconds ^ 0x99u ^ (seconds - 0x67u)) >> 4) & 1u;
		time_up = (uint8_t)(seconds - 0x67u) < seconds;
		bonus_seconds = konami_daa((uint8_t)(seconds - 0x67u), half_carry, time_up);
		bonus_frames = 0x98u;
		time_up = 0u;
		return time_up;
	}
	half_carry = ((uint8_t)(frames ^ 0x99u ^ (frames - 0x67u)) >> 4) & 1u;
	time_up = (uint8_t)(frames - 0x67u) < frames;
	frames = konami_daa((uint8_t)(frames - 0x67u), half_carry, time_up);
	if (frames != 0u)
	{
		bonus_frames = frames;
		time_up = 0u;
		return time_up;
	}
	bonus_frames = frames;
	old_seconds = bonus_seconds;
	seconds = old_seconds;
	if (old_seconds == 0u)
	{
		bonus_draw_x = 0xE0u;
		bonus_draw_y = 0xB8u;
		bonus_draw_timer();
		time_up = 1u;
		return time_up;
	}
	half_carry = ((uint8_t)(seconds ^ 0x99u ^ (seconds - 0x67u)) >> 4) & 1u;
	time_up = (uint8_t)(seconds - 0x67u) < seconds;
	bonus_seconds = konami_daa((uint8_t)(seconds - 0x67u), half_carry, time_up);
	bonus_frames = 0x98u;
	time_up = 0u;
	return time_up;
}

/* Does nothing: the bonuses' timer is not drawn (the drawing after it, unused_bonus_draw_timer_digits,
   nothing calls). */
void bonus_draw_timer(void)
{
}

/* Unused: would draw the bonus timer's 4 digits as sprites (kind 0E, animations B0-B9). */
void unused_bonus_draw_timer_digits(void)
{
	uint8_t a = 0, digit_x_low = 0;
	uint16_t object = 0;
	uint8_t digit_count = 0;
	uint8_t digits_left = 0, seconds_tens = 0;
	uint16_t digit_x = 0, next_digit_x = 0, digit_z = 0, x_before_gap = 0, x_after_gap = 0;

	object = OBJECT_ADDRESS(9);
	digit_count = 4u;
	do
	{
		OBJECT(object)->flags = 0x80u;
		OBJECT(object)->kind = 0xEu;
		digit_x = bonus_draw_x;
		digit_x_low = (uint8_t)digit_x;
		a = (uint8_t)(digit_x >> 8);
		OBJECT(object)->x = ((uint32_t)a << 8) | (digit_x_low & 0xFFu);
		next_digit_x = (((uint32_t)a << 8) | (digit_x_low & 0xFFu)) + 0x10u;
		bonus_draw_x = next_digit_x;
		OBJECT(object)->y = 0xA0u;
		digit_z = bonus_draw_y;
		OBJECT(object)->z = digit_z;
		if (digit_count == 3u)
		{
			x_before_gap = bonus_draw_x;
			x_after_gap = x_before_gap + 8u;
			bonus_draw_x = x_after_gap;
		}
		object += 0x60u;
		digits_left = digit_count;
		digit_count = digits_left - 1u;
	} while (digits_left != 1u);
	object = OBJECT_ADDRESS(9);
	seconds_tens = (((bonus_seconds >> 1) >> 1) >> 1) >> 1;
	a = seconds_tens;
	if (seconds_tens == 0u)
		OBJECT(object)->flags = 0u;
	OBJECT(object)->animation = a - 0x50u;
	object += 0x60u;
	OBJECT(object)->animation = (bonus_seconds & 0xFu) - 0x50u;
	object += 0x60u;
	OBJECT(object)->animation = ((((bonus_frames >> 1) >> 1) >> 1) >> 1) - 0x50u;
	OBJECT(object + 0x60u)->animation = (bonus_frames & 0xFu) - 0x50u;
}

/* Does nothing: the sign that would go with bonus 1 (unused_bonus_1_put_sign, right after it) is not
   put. */
void bonus_1_draw_sign(void)
{
}

/* Unused: would put a kind 0E sign (animation 8F) at the given place. */
void unused_bonus_1_put_sign(void)
{
	uint16_t sign_x = 0, sign_z = 0;

	OBJECT(OBJECT_ADDRESS(8))->flags = 0x80u;
	OBJECT(OBJECT_ADDRESS(8))->kind = 0xEu;
	OBJECT(OBJECT_ADDRESS(8))->animation = 0x8Fu;
	sign_x = bonus_draw_x;
	OBJECT(OBJECT_ADDRESS(8))->x = sign_x;
	OBJECT(OBJECT_ADDRESS(8))->y = 0xA0u;
	sign_z = bonus_draw_y;
	OBJECT(OBJECT_ADDRESS(8))->z = sign_z;
}

/* Bonus 1: puts each player's balloon and its three parts (the character blowing, the part between and
   the one that flies with it), the absent players' in their own look. */
void bonus_1_put_players(uint16_t *p_player_object, uint16_t *p_d, uint32_t *p_carry)
{
	uint32_t carry = *p_carry;
	uint8_t part_field = 0, player_number = 0, zoom_x = 0, zoom_y = 0;
	uint16_t balloon = 0, d = 0, default_object = 0, object = 0, placed_part = 0, player_object = 0, record_number = 0;
	uint8_t player_or_object_low = 0, saved_player_object_high = 0;
	uint8_t in_game = 0, in_game_2 = 0, in_game_3 = 0, player_in_game = 0;
	uint16_t flyer = 0;

	balloon = OBJECT_ADDRESS(0);
	player_number = 0u;
	do
	{
		player_or_object_low = player_number;
		record_number = (uint32_t)player_number << 8;
		bonus_put_placement(balloon, &object, &record_number, &carry);
		in_game = OBJECT(balloon)->bonus_1.in_game;
		if (in_game == 0u)
		{
			record_number = 0x1000u;
			bonus_put_placement(balloon, &object, &record_number, &carry);
		}
		OBJECT(object)->flags = OBJECT(object)->flags;
		OBJECT(balloon)->timer = 1u;
		zoom_x = 0x40u;
		in_game_2 = OBJECT(balloon)->bonus_1.in_game;
		if (in_game_2 == 0u)
			zoom_x = 0xB0u;
		OBJECT(balloon)->zoom_x = zoom_x;
		OBJECT(balloon)->bonus_1.width_zoom = (OBJECT(balloon)->bonus_1.width_zoom & 0xFFu) | 0xB000u;
		zoom_y = 0x40u;
		in_game_3 = OBJECT(balloon)->bonus_1.in_game;
		if (in_game_3 == 0u)
			zoom_y = 0xB0u;
		OBJECT(balloon)->zoom_y = zoom_y;
		OBJECT(balloon)->bonus_1.height_zoom = (OBJECT(balloon)->bonus_1.height_zoom & 0xFFu) | 0xB000u;
		balloon += 0xC0u;
		player_number = player_or_object_low + 1u;
	} while (player_number != 4u);
	player_object = OBJECT_ADDRESS(0);
	balloon_player_number = 0u;
	do
	{
		balloon_part = 0u;
		do
		{
			record_number = (uint32_t)(uint8_t)((((uint32_t)balloon_part << 1) << 1) + balloon_player_number + 4u) << 8;
			bonus_put_placement(player_object, &placed_part, &record_number, &carry);
			leftover_y = placed_part;
			player_in_game = OBJECT(player_object)->bonus_1.in_game;
			if (player_in_game == 0u)
			{
				saved_player_object_high = player_object >> 8;
				player_or_object_low = (uint8_t)player_object;
				default_object = leftover_y;
				record_number = (uint32_t)(uint8_t)(0x11u + balloon_part) << 8;
				bonus_put_placement(default_object, &placed_part, &record_number, &carry);
				leftover_y = placed_part;
				player_object = ((uint32_t)saved_player_object_high << 8) | player_or_object_low;
			}
			part_field = ((uint32_t)balloon_part << 1) + 0x33u;
			mem_write16(player_object + (int8_t)part_field, leftover_y);
			balloon_part++;
		} while (balloon_part != 3u);
		flyer = OBJECT(player_object)->bonus_1.flyer;
		mem_write8(flyer, 0u);
		player_object += 0xC0u;
		balloon_player_number++;
		player_number = balloon_player_number;
		carry = player_number < 4u;
	} while (player_number != 4u);
	d = ((uint32_t)player_number << 8) | part_field;
	*p_player_object = player_object;
	*p_d = d;
	*p_carry = carry;
}

/* The bonuses: puts the given record of bonus_placements (its object, or the caller's where it says
   FFFF; its kind, animation, x and height, FFFF keeping the old one) and hands back the object. */
void bonus_put_placement(uint16_t default_object, uint16_t *p_placed, uint16_t *p_record_number, uint32_t *p_carry)
{
	uint16_t record_number = (uint16_t)*p_record_number;
	uint32_t carry = *p_carry;
	uint8_t coordinate_high = 0, coordinate_low = 0;
	uint16_t placed = 0, placement = 0, record_cursor = 0;
	uint16_t placement_record = 0, kind_cursor = 0, kind = 0, x_cursor = 0, new_x = 0, z = 0, new_z = 0;
	uint32_t kind_halfword = 0;

	placement_record = bonus_placements[(int8_t)((uint8_t)((uint32_t)(record_number >> 8) << 1)) / 2];
	record_cursor = placement_record + 2u;
	placed = PLACEMENT(placement_record)->object;
	if (placed == 0xFFFFu)
		placed = default_object;
	OBJECT(placed)->flags |= 0x80u;
	kind_cursor = record_cursor;
	kind = PLACEMENT(kind_cursor - 0x2u)->kind;
	kind_halfword = ((uint32_t)(kind >> 8) << 8) | (uint8_t)(kind | 0x80u);
	OBJECT(placed)->kind = (uint8_t)(kind_halfword >> 8u);
	OBJECT(placed)->animation = (uint8_t)kind_halfword;
	x_cursor = kind_cursor + 2u;
	placement = x_cursor + 2u;
	new_x = PLACEMENT(x_cursor - 0x4u)->x;
	coordinate_high = (uint8_t)(new_x >> 8);
	coordinate_low = (uint8_t)new_x;
	if ((uint16_t)(((uint32_t)coordinate_high << 8) | coordinate_low) != 0xFFFFu)
		OBJECT(placed)->x = ((uint32_t)coordinate_high << 8) | coordinate_low;
	OBJECT(placed)->y = 0xB0u;
	z = PLACEMENT(placement - 0x6u)->z;
	coordinate_high = (uint8_t)(z >> 8);
	coordinate_low = (uint8_t)z;
	new_z = ((uint32_t)coordinate_high << 8) | coordinate_low;
	carry = new_z < 0xFFFFu;
	if (new_z != 0xFFFFu)
		OBJECT(placed)->z = ((uint32_t)coordinate_high << 8) | coordinate_low;
	record_number = ((uint32_t)coordinate_high << 8) | coordinate_low;
	*p_placed = placed;
	*p_record_number = record_number;
	*p_carry = carry;
}

/* Bonus 1: copies each player in the game's newly pressed controls into its bonus record. */
void bonus_1_take_presses(void)
{
	uint16_t balloon = 0, bonus_player = 0;
	uint8_t player_counter = 0;
	uint8_t in_game = 0;
	uint16_t controls_pressed = 0;

	balloon = OBJECT_ADDRESS(0);
	player_counter = 0u;
	do
	{
		in_game = OBJECT(balloon)->bonus_1.in_game;
		if (in_game != 0u)
		{
			bonus_player = bonus_1_player_records[(int8_t)((uint8_t)((uint32_t)player_counter << 1)) / 2];
			controls_pressed = BONUS_PLAYER(bonus_player)->controls_pressed;
			mem_write8(BONUS_PLAYER(bonus_player)->presses, mem_read8(controls_pressed));
		}
		balloon += 0xC0u;
		player_counter = player_counter + 1u;
	} while (player_counter != 4u);
}

/* Bonus 1: gives each absent player a press rate (frames between presses) for its balloon to blow by
   itself. */
void bonus_1_set_absent_rates(void)
{
	uint16_t player_object = 0;
	uint8_t player_counter = 0, record_index = 0;
	uint8_t player_in_game = 0, press_rate = 0;
	uint16_t object = 0;

	absent_player_seen = 0u;
	player_counter = 0u;
	record_index = random_number & 3u;
	do
	{
		object = BONUS_PLAYER(bonus_1_player_records[record_index & 0x7Fu])->object;
		player_object = object;
		player_in_game = OBJECT(player_object)->bonus_1.in_game;
		if (player_in_game == 0u)
		{
			if (absent_player_seen == 0u)
			{
				absent_player_seen++;
				OBJECT(player_object)->bonus_1.press_rate = 0u;
			}
			else
				OBJECT(player_object)->bonus_1.press_rate = player_counter + record_index;
		}
		press_rate = OBJECT(player_object)->bonus_1.press_rate;
		OBJECT(player_object)->bonus_1.press_rate = press_rate + 5u;
		record_index = (record_index + 1u) & 3u;
		player_counter = player_counter + 1u;
	} while (player_counter != 4u);
}

/* Bonus 1: the absent players press by themselves, one press each so many frames. */
void bonus_1_absent_presses(void)
{
	uint16_t balloon = 0, bonus_player = 0;
	uint8_t player_counter = 0;
	uint8_t in_game = 0, press_wait = 0, press_wait_2 = 0, press_rate = 0;

	balloon = OBJECT_ADDRESS(0);
	player_counter = 0u;
	do
	{
		in_game = OBJECT(balloon)->bonus_1.in_game;
		if (in_game == 0u)
		{
			bonus_player = bonus_1_player_records[(int8_t)((uint8_t)((uint32_t)player_counter << 1)) / 2];
			press_wait = OBJECT(balloon)->bonus_1.press_wait;
			if (press_wait != 0u)
			{
				mem_write8(BONUS_PLAYER(bonus_player)->presses, 0u);
				press_wait_2 = OBJECT(balloon)->bonus_1.press_wait;
				OBJECT(balloon)->bonus_1.press_wait = press_wait_2 - 1u;
			}
			else
			{
				mem_write8(BONUS_PLAYER(bonus_player)->presses, 0x10u);
				press_rate = OBJECT(balloon)->bonus_1.press_rate;
				OBJECT(balloon)->bonus_1.press_wait = press_rate;
			}
		}
		balloon += 0xC0u;
		player_counter = player_counter + 1u;
	} while (player_counter != 4u);
}

/* Bonus 1: plays the press sound (2900) when a player in the game presses, at most once each 32 frames. */
void bonus_1_press_sound(uint16_t *p_player_records_place, uint16_t *p_d, uint32_t *p_carry)
{
	uint32_t carry = *p_carry;
	uint8_t player_number = 0, presses = 0;
	uint16_t command = 0, d = 0, player_records_place = 0, record = 0;
	uint8_t player_counter = 0;
	uint8_t frames_since_sound = 0, counted_frames = 0, slot_in_game = 0, pressed_bits = 0, waited_frames = 0, old_waited_frames = 0;

	frames_since_sound = io_read8(dream_wave_size);
	if ((int8_t)frames_since_sound >= 0)
	{
		counted_frames = io_read8(dream_wave_size);
		io_write8(dream_wave_size, counted_frames + 1u);
	}
	presses = 0u;
	player_counter = 0u;
	player_records_place = bonus_1_player_records_ADDRESS;
	do
	{
		record = mem_read16(player_records_place);
		slot_in_game = mem_read8(player_records_place + 0x3Eu);
		if (slot_in_game != 0u)
			presses |= mem_read8(mem_read16(record));
		player_records_place += 2u;
		player_counter = player_counter + 1u;
		player_number = player_counter;
		carry = player_number < 4u;
	} while (player_number != 4u);
	pressed_bits = presses & 0x3Fu;
	presses = pressed_bits;
	if (pressed_bits != 0u)
	{
		waited_frames = io_read8(dream_wave_size);
		presses = waited_frames;
		carry = presses < 0x20u;
		if (presses > 0x20u)
		{
			old_waited_frames = io_read8(dream_wave_size);
			io_write8(dream_wave_size, 0u);
			presses = 0x29u;
			player_number = 0u;
			command = 0x2900u;
			carry = vector_queue_sound(command);
		}
	}
	d = ((uint32_t)presses << 8) | player_number;
	*p_player_records_place = player_records_place;
	*p_d = d;
	*p_carry = carry;
}

/* Bonus 1: marks each player's object with whether the player is in the game. */
void bonus_mark_players_in_game(void)
{
	uint8_t player_bit = 0, players_left = 0;
	uint16_t balloon = 0;
	uint8_t in_game = 0, players_left_before = 0;

	balloon = OBJECT_ADDRESS(0);
	player_bit = 1u;
	players_left = 4u;
	do
	{
		OBJECT(balloon)->bonus_1.in_game = 0u;
		if ((player_bit & players_playing) != 0u)
		{
			in_game = OBJECT(balloon)->bonus_1.in_game;
			OBJECT(balloon)->bonus_1.in_game = in_game + 1u;
		}
		player_bit = (uint32_t)player_bit << 1;
		balloon += 0xC0u;
		players_left_before = players_left;
		players_left = players_left_before - 1u;
	} while (players_left_before != 1u);
}

/* Bonus 1: has the 4 players' objects drawn zoomed (by their balloon's size). */
uint16_t bonus_1_zoom_players(void)
{
	uint8_t flags = 0, players_left = 0;
	uint16_t d = 0, object = 0;
	uint8_t players_left_before = 0;

	object = OBJECT_ADDRESS(0);
	players_left = 4u;
	do
	{
		flags = OBJECT(object)->flags | 0x10u;
		OBJECT(object)->flags = flags;
		object += 0xC0u;
		players_left_before = players_left;
		players_left = players_left_before - 1u;
	} while (players_left_before != 1u);
	d = ((uint32_t)flags << 8) | players_left;
	return d;
}

/* The bonuses' introduction: runs the camera's pan by its step; carry when it is over. */
void bonus_pan(uint16_t *p_step_table, uint16_t *p_d, uint32_t *p_pan_done)
{
	uint16_t d = (uint16_t)*p_d;
	uint32_t pan_done = *p_pan_done;
	uint8_t step_offset = 0;
	uint16_t step_table = 0;

	step_table = bonus_pan_steps_ADDRESS;
	step_offset = step_subphase;
	pan_done = (int8_t)step_offset < 0;
	step_offset = (uint32_t)step_offset << 1;
	switch ((int8_t)step_offset)
	{
	case 0:
		bonus_pan_start(&d, &pan_done);
		break;
	case 2:
		bonus_pan_up(&step_table, &d, &pan_done);
		break;
	case 4:
	case 8:
		d = (d & 0xFFu) | ((uint32_t)step_offset << 8);
		pan_done = bonus_hide_hints();
		break;
	case 6:
		bonus_show_hints_1(step_table, &d, &pan_done);
		break;
	case 10:
		bonus_show_hints_2(step_table, &d, &pan_done);
		break;
	case 12:
		d = bonus_title_wait();
		break;
	case 14:
		d = (d & 0xFFu) | ((uint32_t)step_offset << 8);
		bonus_title_show(&step_table, &d, &pan_done);
		break;
	case 16:
		d = (d & 0xFFu) | ((uint32_t)step_offset << 8);
		bonus_title_done();
		break;
	case -50:
		bonus_1_intro_pan(&step_table, &d, &pan_done);
		break;
	case -48:
		bonus_1_intro_set_up(&step_table, &d, &pan_done);
		break;
	case -46:
		bonus_1_intro_show_how(&step_table, &d, &pan_done);
		break;
	case -44:
		bonus_1_contest_start(&step_table, &d, &pan_done);
		break;
	case -42:
		bonus_1_contest_play(&step_table, &d, &pan_done);
		break;
	case -40:
		bonus_1_finish(&step_table, &d, &pan_done);
		break;
	case -38:
		bonus_1_contest_set_up(&step_table, &d, &pan_done);
		break;
	case -36:
		bonus_1_contest_ready(&step_table, &d, &pan_done);
		break;
	case -34:
		bonus_1_start_music(&d, &pan_done);
		break;
	case -32:
		bonus_1_blow_until_done(&step_table, &d, &pan_done);
		break;
	case -30:
		bonus_1_finish_music(&d, &pan_done);
		break;
	case -28:
		bonus_1_results(&step_table, &d, &pan_done);
		break;
	case -26:
		bonus_1_top_up_balloons(&step_table, &d, &pan_done);
		break;
	case -24:
		bonus_1_fly_away(&step_table, &d, &pan_done);
		break;
	case -22:
		d = (d & 0xFFu) | ((uint32_t)step_offset << 8);
		bonus_1_end(&d, &pan_done);
		break;
	case -20:
		bonus_1_fly(&step_table, &d, &pan_done);
		break;
	case -18:
		bonus_1_popped(&step_table, &d, &pan_done);
		break;
	case -16:
		d = bonus_1_take_off(step_table);
		break;
	case -14:
		d = bonus_1_lift_off(step_table);
		break;
	case -12:
		bonus_1_speed_up(step_table, &d, &pan_done);
		break;
	case -10:
		bonus_1_rise(step_table, &d, &pan_done);
		break;
	case -8:
		bonus_1_pop(step_table, &d, &pan_done);
		break;
	case -6:
		bonus_1_fall(step_table, &d, &pan_done);
		break;
	case -4:
		d = (d & 0xFFu) | ((uint32_t)step_offset << 8);
		bonus_1_lie(step_table);
		break;
	case -2:
		d = (d & 0xFFu) | ((uint32_t)step_offset << 8);
		bonus_1_fall_done();
		break;
	}
	*p_step_table = step_table;
	*p_d = d;
	*p_pan_done = pan_done;
}

/* The bonuses' introduction: shows the title's object and starts the camera's pan. */
void bonus_pan_start(uint16_t *p_d, uint32_t *p_pan_done)
{
	uint32_t pan_done = *p_pan_done;
	uint16_t d = 0;

	OBJECT(leftover_y)->flags = 0x80u;
	OBJECT(leftover_y)->y = 0x70u;
	OBJECT(leftover_y)->attributes = 0x20u;
	step_subphase++;
	pan_done = 0u;
	d = 0x70u;
	*p_d = d;
	*p_pan_done = pan_done;
}

/* The bonuses' introduction: pans the view up 3 a frame, the backdrop rising with it, until it has gone
   round (carry). */
void bonus_pan_up(uint16_t *p_backdrop, uint16_t *p_d, uint32_t *p_pan_done)
{
	uint32_t pan_done = *p_pan_done;
	uint8_t new_scroll_low = 0;
	uint16_t backdrop = 0, d = 0;
	uint16_t scroll_y_read = 0, old_scroll_y = 0;

	backdrop = OBJECT_ADDRESS(8);
	OBJECT(OBJECT_ADDRESS(8))->z_speed = 0x300;
	scroll_y_read = layer_a_scroll_y;
	old_scroll_y = scroll_y_read;
	new_scroll_low = (uint8_t)(old_scroll_y + 3u);
	layer_a_scroll_y = ((uint32_t)((uint16_t)(old_scroll_y + 3u) >> 8) << 8) | new_scroll_low;
	if (old_scroll_y <= (uint16_t)(old_scroll_y + 3u))
	{
		pan_done = 0u;
		d = new_scroll_low;
	}
	else
	{
		backdrop = OBJECT_ADDRESS(8);
		layer_a_scroll_y = 0u;
		OBJECT(OBJECT_ADDRESS(8))->z_speed = 0;
		OBJECT(OBJECT_ADDRESS(8))->z = 0xCFu;
		OBJECT(OBJECT_ADDRESS(8))->animation_flags = 0x80u;
		step_subphase = 0u;
		pan_done = 1u;
		d = 0x7FCFu;
	}
	*p_backdrop = backdrop;
	*p_d = d;
	*p_pan_done = pan_done;
}

/* The bonuses' introduction: shows the press hints in turn, one pair after the other with a gap between. */
void bonus_blink_hints(void)
{
	uint32_t carry = 0;
	uint8_t a = 0, step_offset = 0;
	uint16_t d = 0, ignored16 = 0, ignored16_2 = 0, step_table = 0;
	uint16_t blink_step = 0;

	blink_step = ((uint8_t)frame_count & 0x60u) >> 5;
	a = (uint8_t)(blink_step >> 8);
	step_table = bonus_hint_blink_steps_ADDRESS;
	step_offset = (uint32_t)blink_step << 1;
	switch ((int8_t)step_offset)
	{
	case 0:
	case 4:
		bonus_hide_hints();
		return;
	case 2:
		bonus_show_hints_1(step_table, &ignored16_2, &carry);
		return;
	case 6:
		bonus_show_hints_2(step_table, &ignored16_2, &carry);
		return;
	case 8:
		bonus_title_wait();
		return;
	case 10:
		d = (uint32_t)a << 8;
		bonus_title_show(&step_table, &d, &carry);
		return;
	case 12:
		bonus_title_done();
		return;
	case -54:
		d = step_offset;
		bonus_1_intro_pan(&ignored16, &d, &carry);
		return;
	case -52:
		bonus_1_intro_set_up(&ignored16, &ignored16_2, &carry);
		return;
	case -50:
		bonus_1_intro_show_how(&ignored16, &ignored16_2, &carry);
		return;
	case -48:
		d = step_offset;
		bonus_1_contest_start(&ignored16, &d, &carry);
		return;
	case -46:
		bonus_1_contest_play(&ignored16, &ignored16_2, &carry);
		return;
	case -44:
		d = step_offset;
		bonus_1_finish(&ignored16, &d, &carry);
		return;
	case -42:
		bonus_1_contest_set_up(&ignored16, &ignored16_2, &carry);
		return;
	case -40:
		bonus_1_contest_ready(&ignored16, &ignored16_2, &carry);
		return;
	case -38:
		bonus_1_start_music(&ignored16_2, &carry);
		return;
	case -36:
		bonus_1_blow_until_done(&ignored16, &ignored16_2, &carry);
		return;
	case -34:
		bonus_1_finish_music(&ignored16_2, &carry);
		return;
	case -32:
		bonus_1_results(&ignored16, &ignored16_2, &carry);
		return;
	case -30:
		bonus_1_top_up_balloons(&ignored16, &ignored16_2, &carry);
		return;
	case -28:
		d = step_offset;
		bonus_1_fly_away(&ignored16, &d, &carry);
		return;
	case -26:
		d = ((uint32_t)a << 8) | step_offset;
		bonus_1_end(&d, &carry);
		return;
	case -24:
		d = step_offset;
		bonus_1_fly(&step_table, &d, &carry);
		return;
	case -22:
		d = step_offset;
		bonus_1_popped(&step_table, &d, &carry);
		return;
	case -20:
		bonus_1_take_off(step_table);
		return;
	case -18:
		bonus_1_lift_off(step_table);
		return;
	case -16:
		bonus_1_speed_up(step_table, &ignored16_2, &carry);
		return;
	case -14:
		bonus_1_rise(step_table, &ignored16_2, &carry);
		return;
	case -12:
		bonus_1_pop(step_table, &ignored16_2, &carry);
		return;
	case -10:
		bonus_1_fall(step_table, &ignored16_2, &carry);
		return;
	case -8:
		bonus_1_lie(step_table);
		return;
	case -6:
		bonus_1_fall_done();
		return;
	case -4:
		bonus_pan_start(&ignored16_2, &carry);
		return;
	case -2:
		bonus_pan_up(&ignored16, &ignored16_2, &carry);
		return;
	}
}

/* The bonuses' introduction: hides the press hints. */
uint32_t bonus_hide_hints(void)
{
	uint32_t carry = 0;

	OBJECT(OBJECT_ADDRESS(9))->flags = 0u;
	carry = 0u;
	OBJECT(OBJECT_ADDRESS(10))->flags = 0u;
	return carry;
}

/* The bonuses' introduction: shows the first pair of press hints. */
void bonus_show_hints_1(uint16_t default_object, uint16_t *p_d, uint32_t *p_carry)
{
	uint32_t carry = *p_carry;
	uint16_t d = 0, object = 0, placed = 0, record_number = 0;

	record_number = 0x1500u;
	bonus_put_placement(default_object, &object, &record_number, &carry);
	OBJECT(object)->flags = 0x80u;
	d = 0x1600u;
	bonus_put_placement(default_object, &placed, &d, &carry);
	leftover_y = placed;
	OBJECT(leftover_y)->flags = 0x80u;
	OBJECT(leftover_y)->attributes = 0x20u;
	d = (d & 0xFFu) | 0x2000u;
	*p_d = d;
	*p_carry = carry;
}

/* The bonuses' introduction: shows the second pair of press hints. */
void bonus_show_hints_2(uint16_t default_object, uint16_t *p_d, uint32_t *p_carry)
{
	uint32_t carry = *p_carry;
	uint16_t d = 0, object = 0, placed = 0, record_number = 0;

	record_number = 0x1700u;
	bonus_put_placement(default_object, &object, &record_number, &carry);
	OBJECT(object)->flags = 0x80u;
	d = 0x1800u;
	bonus_put_placement(default_object, &placed, &d, &carry);
	leftover_y = placed;
	OBJECT(leftover_y)->flags = 0x80u;
	OBJECT(leftover_y)->attributes = 0x20u;
	d = (d & 0xFFu) | 0x2000u;
	*p_d = d;
	*p_carry = carry;
}

/* The bonuses: puts bonus_placements' record 25 (kind 0E animation 48) back when its object is off. */
void bonus_keep_backdrop(void)
{
	uint32_t carry = 0;
	uint16_t backdrop = 0, object = 0, record_number = 0;

	backdrop = mem_read16(bonus_placements[25]);
	if (OBJECT(backdrop)->flags != 0u)
		return;
	record_number = 0x1900u;
	bonus_put_placement(backdrop, &object, &record_number, &carry);
	OBJECT(object)->flags = 0x80u;
}

/* The bonuses' introduction: shows the bonus' title by its step: a wait, then the title and its sound. */
uint16_t bonus_title(uint16_t bonus_number)
{
	uint32_t carry = 0;
	uint8_t step_offset = 0;
	uint16_t d = 0, ignored16 = 0, step_table = 0;
	uint8_t title_step = 0;

	step_table = bonus_title_steps_ADDRESS;
	title_step = io_read8(bonus_title_step);
	step_offset = (uint32_t)title_step << 1;
	switch ((int8_t)step_offset)
	{
	case 0:
		return bonus_title_wait();
	case 2:
		bonus_number |= step_offset;
		bonus_title_show(&step_table, &bonus_number, &carry);
		return bonus_number;
	case 4:
		bonus_number |= step_offset;
		bonus_title_done();
		return bonus_number;
	case -62:
		d = step_offset;
		bonus_1_intro_pan(&ignored16, &d, &carry);
		return d;
	case -60:
		bonus_1_intro_set_up(&ignored16, &d, &carry);
		return d;
	case -58:
		bonus_1_intro_show_how(&ignored16, &d, &carry);
		return d;
	case -56:
		d = step_offset;
		bonus_1_contest_start(&ignored16, &d, &carry);
		return d;
	case -54:
		bonus_1_contest_play(&ignored16, &d, &carry);
		return d;
	case -52:
		d = step_offset;
		bonus_1_finish(&ignored16, &d, &carry);
		return d;
	case -50:
		bonus_1_contest_set_up(&ignored16, &d, &carry);
		return d;
	case -48:
		bonus_1_contest_ready(&ignored16, &d, &carry);
		return d;
	case -46:
		bonus_1_start_music(&d, &carry);
		return d;
	case -44:
		bonus_1_blow_until_done(&ignored16, &d, &carry);
		return d;
	case -42:
		bonus_1_finish_music(&d, &carry);
		return d;
	case -40:
		d = step_offset;
		bonus_1_results(&ignored16, &d, &carry);
		return d;
	case -38:
		bonus_1_top_up_balloons(&ignored16, &d, &carry);
		return d;
	case -36:
		d = step_offset;
		bonus_1_fly_away(&ignored16, &d, &carry);
		return d;
	case -34:
		bonus_number |= step_offset;
		bonus_1_end(&bonus_number, &carry);
		return bonus_number;
	case -32:
		d = step_offset;
		bonus_1_fly(&step_table, &d, &carry);
		return d;
	case -30:
		d = step_offset;
		bonus_1_popped(&step_table, &d, &carry);
		return d;
	case -28:
		return bonus_1_take_off(step_table);
	case -26:
		return bonus_1_lift_off(step_table);
	case -24:
		bonus_1_speed_up(step_table, &d, &carry);
		return d;
	case -22:
		bonus_1_rise(step_table, &d, &carry);
		return d;
	case -20:
		bonus_1_pop(step_table, &d, &carry);
		return d;
	case -18:
		bonus_1_fall(step_table, &d, &carry);
		return d;
	case -16:
		bonus_number |= step_offset;
		bonus_1_lie(step_table);
		return bonus_number;
	case -14:
		bonus_number |= step_offset;
		bonus_1_fall_done();
		return bonus_number;
	case -12:
		bonus_pan_start(&d, &carry);
		return d;
	case -10:
		bonus_pan_up(&ignored16, &d, &carry);
		return d;
	case -8:
	case -4:
		bonus_number |= step_offset;
		bonus_hide_hints();
		return bonus_number;
	case -6:
		bonus_show_hints_1(step_table, &d, &carry);
		return d;
	case -2:
		bonus_show_hints_2(step_table, &d, &carry);
		return d;
	}
	unreachable();
}

/* The bonuses' introduction: waits 192 frames before the title. */
uint16_t bonus_title_wait(void)
{
	uint16_t title_frames = 0;
	uint8_t title_step = 0;

	title_frames = 0xC0u;
	io_write16(bonus_title_frames, 0xC0u);
	title_step = io_read8(bonus_title_step);
	io_write8(bonus_title_step, title_step + 1u);
	return title_frames;
}

/* The bonuses' introduction: puts the given bonus' title and plays its voice. */
void bonus_title_show(uint16_t *p_x, uint16_t *p_d, uint32_t *p_carry)
{
	uint16_t x = (uint16_t)*p_x;
	uint16_t d = (uint16_t)*p_d;
	uint32_t carry = *p_carry;
	uint8_t a = 0;
	uint16_t d_2 = 0, placed = 0, record_number = 0;
	uint8_t bonus_index = 0;
	uint8_t title_step = 0;
	uint16_t title_frames_left = 0, intro_sound = 0;

	a = (uint8_t)(d >> 8);
	title_frames_left = io_read16(bonus_title_frames);
	carry = title_frames_left == 0u;
	io_write16(bonus_title_frames, title_frames_left - 1u);
	if (title_frames_left == 1u)
	{
		bonus_index = a;
		record_number = (uint32_t)(uint8_t)(a + 0x1Au) << 8;
		bonus_put_placement(x, &placed, &record_number, &carry);
		leftover_y = placed;
		OBJECT(leftover_y)->flags = 0x80u;
		x = bonus_intro_sounds_ADDRESS;
		intro_sound = bonus_intro_sounds[(int8_t)((uint8_t)((uint32_t)bonus_index << 1)) / 2];
		d = intro_sound;
		a = (uint8_t)(intro_sound >> 8);
		carry = vector_queue_sound(d);
		title_step = io_read8(bonus_title_step);
		io_write8(bonus_title_step, title_step + 1u);
	}
	d_2 = (d & 0xFFu) | ((uint32_t)a << 8);
	*p_x = x;
	*p_d = d_2;
	*p_carry = carry;
}

/* The bonuses' introduction: the title is up (nothing more to do). */
void bonus_title_done(void)
{
}

/* The bonuses' end: each player in first place gets 20 health, up to the full 40. */
void bonus_reward_winners(uint16_t *p_d, uint32_t *p_carry)
{
	uint16_t d = (uint16_t)*p_d;
	uint32_t carry = *p_carry;
	uint8_t health = 0, look = 0, place = 0;
	uint16_t box = 0, d_2 = 0, health_address = 0;
	uint8_t saved_state_offset = 0, boxes_to_check = 0;
	uint8_t look_2 = 0, place_2 = 0, no_points = 0, boxes_left = 0;

	saved_state_offset = d >> 8;
	box = OBJECT_ADDRESS(14);
	health_address = 0x49D2u;
	boxes_to_check = 4u;
	do
	{
		look_2 = OBJECT(box)->bonus_results.look;
		look = look_2;
		carry = look < 3u;
		if (look == 3u)
		{
			place_2 = OBJECT(box)->bonus_results.place;
			place = place_2;
			carry = place == 0u;
			if (place == 1u)
			{
				no_points = OBJECT(box)->bonus_results.no_points;
				if (no_points == 0u)
				{
					health = mem_read8(health_address) + 0x14u;
					carry = health < 0x28u;
					if (health > 0x28u)
						health = 0x28u;
					mem_write8(health_address, health);
				}
			}
		}
		box += 0xC0u;
		health_address += 8u;
		boxes_left = boxes_to_check;
		boxes_to_check = boxes_left - 1u;
	} while (boxes_left != 1u);
	d_2 = (uint32_t)saved_state_offset << 8;
	*p_d = (*p_d & 0xFFu) | d_2;
	*p_carry = carry;
}
