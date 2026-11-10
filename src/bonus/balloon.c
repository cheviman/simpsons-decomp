/**
 *    Name:        bonus/balloon.c
 *    Description: the bank's jump table, then bonus 1: blow up the balloon (the step after stage 1)
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    09-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the game's 053248 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

/* Runs bonus 1's contest by the scene's state: the players' portraits along the bottom, then the start,
   the blowing, the result and the flight of the balloons. */
void bonus_1_contest(uint16_t y)
{
	uint32_t carry = 0;
	uint8_t a = 0;
	uint16_t d = 0, ignored16 = 0, ignored16_2 = 0, ignored16_3 = 0, x = 0;
	uint8_t t1 = 0;

	bonus_draw_x = 0x7Cu;
	bonus_draw_y = 0x98u;
	portrait_animation = 0x10u;
	y = bonus_show_player_portraits(y);
	d = bonus_1_zoom_players();
	x = bonus_1_contest_states_ADDRESS;
	t1 = io_read8(scene_state);
	a = (uint32_t)t1 << 1;
	switch ((int8_t)a)
	{
	case 0:
		bonus_1_contest_start(&ignored16, &y, &d, &carry);
		return;
	case 2:
		bonus_1_contest_play(&ignored16, &ignored16_2, &ignored16_3, &carry);
		return;
	case 4:
		bonus_1_finish(&ignored16, &y, &d, &carry);
		return;
	case 6:
		bonus_1_contest_set_up(&ignored16, &ignored16_2, &ignored16_3, &carry);
		return;
	case 8:
		bonus_1_contest_ready(&ignored16, &ignored16_2, &ignored16_3, &carry);
		return;
	case 10:
		bonus_1_start_music(&ignored16_3, &carry);
		return;
	case 12:
		bonus_1_blow_until_done(&ignored16, &ignored16_2, &ignored16_3, &carry);
		return;
	case 14:
		bonus_1_finish_music(&ignored16_3, &carry);
		return;
	case 16:
		bonus_1_results(&ignored16, &ignored16_2, &ignored16_3, &carry);
		return;
	case 18:
		bonus_1_top_up_balloons(&ignored16, &ignored16_2, &ignored16_3, &carry);
		return;
	case 20:
		bonus_1_fly_away(&ignored16, &y, &d, &carry);
		return;
	case 22:
		d = (d & 0xFFu) | ((uint32_t)a << 8);
		bonus_1_end(&d, &carry);
		return;
	case 24:
		bonus_1_fly(&x, &y, &d, &carry);
		return;
	case 26:
		bonus_1_popped(&x, &y, &d, &carry);
		return;
	case 28:
		bonus_1_take_off(x, &ignored16_2, &ignored16_3);
		return;
	case 30:
		bonus_1_lift_off(x, &ignored16_2, &ignored16_3);
		return;
	case 32:
		bonus_1_speed_up(x, &ignored16_2, &ignored16_3, &carry);
		return;
	case 34:
		bonus_1_rise(x, &ignored16_2, &ignored16_3, &carry);
		return;
	case 36:
		bonus_1_pop(x, &ignored16_3, &carry);
		return;
	case 38:
		bonus_1_fall(x, &ignored16_3, &carry);
		return;
	case 40:
		bonus_1_lie(x);
		return;
	case 42:
		bonus_1_fall_done();
		return;
	case 44:
		bonus_pan_start(y, &ignored16_3, &carry);
		return;
	case 46:
		bonus_pan_up(&ignored16, &ignored16_3, &carry);
		return;
	case 48:
	case 52:
		carry = bonus_hide_hints();
		return;
	case 50:
		bonus_show_hints_1(x, &ignored16_2, &ignored16_3, &carry);
		return;
	case 54:
		bonus_show_hints_2(x, &ignored16_2, &ignored16_3, &carry);
		return;
	case 56:
		bonus_title_wait();
		return;
	case 58:
		d = (uint32_t)a << 8;
		bonus_title_show(&x, &ignored16_2, &d, &carry);
		return;
	case 60:
		bonus_title_done();
		return;
	case -6:
		bonus_1_intro_pan(&ignored16, &y, &d, &carry);
		return;
	case -4:
		bonus_1_intro_set_up(&ignored16, &ignored16_2, &ignored16_3, &carry);
		return;
	case -2:
		bonus_1_intro_show_how(&ignored16, &y, &ignored16_3, &carry);
		return;
	}
}

/* Runs bonus 2's contest by its state (from 3 on): the players' set up, the countdown, the yelling, the
   results and the end. */
void bonus_2_contest(uint16_t y)
{
	uint8_t a = 0;
	uint8_t t1 = 0;

	t1 = io_read8(0x1840u);
	a = t1;
	if ((int8_t)a < 3)
	{
		a = 3u;
		io_write8(0x1840u, 3u);
	}
	switch ((int8_t)(uint8_t)((uint32_t)a << 1))
	{
	case 0:
		bonus_2_start_music();
		return;
	case 2:
		bonus_2_intro_set_up(y);
		return;
	case 4:
		bonus_2_intro_try(y);
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
uint16_t wrestler_update(uint16_t object, uint16_t y, uint16_t state)
{
	uint32_t carry = 0;
	uint8_t a = 0, b = 0, d = 0;
	uint16_t step_and_row = 0, u = 0;
	uint8_t state_2 = 0;

	wrestler_check_hit(object, &y, &state);
	b = (uint8_t)state;
	u = wrestler_states_ADDRESS;
	state_2 = OBJECT(object)->state;
	a = state_2;
	carry = (int8_t)a < 0;
	a = (uint32_t)a << 1;
	d = b;
	switch ((int8_t)a)
	{
	case 0:
		y = wrestler_entrance(object, y, d);
		break;
	case 2:
		y = wrestler_walk(object, y);
		break;
	case 4:
		y = wrestler_punch(object, y, d);
		break;
	case 6:
		y = wrestler_guard(object, y, d);
		break;
	case 8:
	case 10:
		y = wrestler_jump(object, y, d);
		break;
	case 12:
		y = wrestler_idle(object, y, d);
		break;
	case 14:
		y = wrestler_wait_target_up(object, y);
		break;
	case 16:
		y = wrestler_beaten_wait(object, y, u);
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
		y = wrestler_get_up(object, y);
		break;
	case 26:
		wrestler_flinch_wait(object);
		break;
	case 28:
		y = wrestler_flinch_land(object, y);
		break;
	case 30:
		y = wrestler_put_in(object, y);
		break;
	case 32:
		wrestler_entrance_drop(object);
		break;
	case 34:
		y = wrestler_entrance_pose(object, y, u);
		break;
	case 36:
		wrestler_entrance_step_out(object);
		break;
	case 38:
		y = wrestler_entrance_land(object, y, u);
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
		y = wrestler_punch_recover(object, y);
		break;
	case 52:
		y = wrestler_guarding(object, y);
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
		y = wrestler_jump_end(object, y, u);
		break;
	case 62:
		wrestler_idle_look(object);
		break;
	case 64:
		y = wrestler_idle_end(object, y, u);
		break;
	case -6:
		y = wrestler_beaten(object, y, d);
		break;
	case -4:
		y = wrestler_knocked_down(object, y, d);
		break;
	case -2:
		y = wrestler_flinch(object, y, d);
		break;
	}
	wrestler_keep_in_area(object);
	step_and_row = (uint32_t)wrestler_gauge_piece_health_by_players[(int8_t)((uint8_t)(player_count - 1u))] << 8;
	y = boss_shade_by_vitality(object, y, step_and_row);
	return y;
}

/* Runs bonus 1's introduction: the title, the camera's pan and a character showing how to blow up the
   balloon. */
void bonus_1_intro(uint16_t y)
{
	uint32_t carry = 0;
	uint8_t a = 0;
	uint16_t d = 0, ignored16 = 0, ignored16_2 = 0, ignored16_3 = 0, x = 0;
	uint8_t t1 = 0;

	d = 0u;
	bonus_title(&y, &d);
	x = bonus_1_intro_states_ADDRESS;
	t1 = io_read8(scene_state);
	a = (uint32_t)t1 << 1;
	switch ((int8_t)a)
	{
	case 0:
		bonus_1_intro_pan(&ignored16, &y, &d, &carry);
		return;
	case 2:
		bonus_1_intro_set_up(&ignored16, &ignored16_2, &ignored16_3, &carry);
		return;
	case 4:
		bonus_1_intro_show_how(&ignored16, &y, &ignored16_3, &carry);
		return;
	case 6:
		bonus_1_contest_start(&ignored16, &y, &d, &carry);
		return;
	case 8:
		bonus_1_contest_play(&ignored16, &ignored16_2, &ignored16_3, &carry);
		return;
	case 10:
		bonus_1_finish(&ignored16, &y, &d, &carry);
		return;
	case 12:
		bonus_1_contest_set_up(&ignored16, &ignored16_2, &ignored16_3, &carry);
		return;
	case 14:
		bonus_1_contest_ready(&ignored16, &ignored16_2, &ignored16_3, &carry);
		return;
	case 16:
		bonus_1_start_music(&ignored16_3, &carry);
		return;
	case 18:
		bonus_1_blow_until_done(&ignored16, &ignored16_2, &ignored16_3, &carry);
		return;
	case 20:
		bonus_1_finish_music(&ignored16_3, &carry);
		return;
	case 22:
		bonus_1_results(&ignored16, &ignored16_2, &ignored16_3, &carry);
		return;
	case 24:
		bonus_1_top_up_balloons(&ignored16, &ignored16_2, &ignored16_3, &carry);
		return;
	case 26:
		bonus_1_fly_away(&ignored16, &y, &d, &carry);
		return;
	case 28:
		d = (d & 0xFFu) | ((uint32_t)a << 8);
		bonus_1_end(&d, &carry);
		return;
	case 30:
		bonus_1_fly(&x, &y, &d, &carry);
		return;
	case 32:
		bonus_1_popped(&x, &y, &d, &carry);
		return;
	case 34:
		bonus_1_take_off(x, &ignored16_2, &ignored16_3);
		return;
	case 36:
		bonus_1_lift_off(x, &ignored16_2, &ignored16_3);
		return;
	case 38:
		bonus_1_speed_up(x, &ignored16_2, &ignored16_3, &carry);
		return;
	case 40:
		bonus_1_rise(x, &ignored16_2, &ignored16_3, &carry);
		return;
	case 42:
		bonus_1_pop(x, &ignored16_3, &carry);
		return;
	case 44:
		bonus_1_fall(x, &ignored16_3, &carry);
		return;
	case 46:
		bonus_1_lie(x);
		return;
	case 48:
		bonus_1_fall_done();
		return;
	case 50:
		bonus_pan_start(y, &ignored16_3, &carry);
		return;
	case 52:
		bonus_pan_up(&ignored16, &ignored16_3, &carry);
		return;
	case 54:
	case 58:
		carry = bonus_hide_hints();
		return;
	case 56:
		bonus_show_hints_1(x, &ignored16_2, &ignored16_3, &carry);
		return;
	case 60:
		bonus_show_hints_2(x, &ignored16_2, &ignored16_3, &carry);
		return;
	case 62:
		bonus_title_wait();
		return;
	case 64:
		d = (uint32_t)a << 8;
		bonus_title_show(&x, &ignored16_2, &d, &carry);
		return;
	case 66:
		bonus_title_done();
		return;
	}
}

/* Runs bonus 2's introduction by its state (0 to 2): the music, the title and the camera's pan, then the
   first player in the game trying it out. */
void bonus_2_intro(uint16_t y)
{
	uint8_t t1 = 0;

	t1 = io_read8(0x1840u);
	switch ((int8_t)(uint8_t)((uint32_t)t1 << 1))
	{
	case 0:
		bonus_2_start_music();
		return;
	case 2:
		bonus_2_intro_set_up(y);
		return;
	case 4:
		bonus_2_intro_try(y);
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
void bonus_1_intro_pan(uint16_t *p_x, uint16_t *p_y, uint16_t *p_d, uint32_t *p_carry)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t d = (uint16_t)*p_d;
	uint32_t carry = *p_carry;
	uint16_t x = 0;
	uint8_t t1 = 0;

	bonus_pan(&x, &y, &d, &carry);
	if (carry)
	{
		t1 = io_read8(scene_state);
		io_write8(scene_state, t1 + 1u);
	}
	*p_x = x;
	*p_y = y;
	*p_d = d;
	*p_carry = carry;
}

/* Bonus 1's introduction: puts the players' bonus objects and shows the first player in the game alone
   in the middle, the others hidden. */
void bonus_1_intro_set_up(uint16_t *p_balloon, uint16_t *p_y, uint16_t *p_d, uint32_t *p_carry)
{
	uint32_t carry = *p_carry;
	uint8_t a = 0;
	uint16_t balloon = 0, d = 0, ignored16 = 0, u = 0, y = 0;
	uint8_t in_game = 0, t1 = 0;
	uint16_t flyer = 0, middle_part = 0, blower = 0, blower_2 = 0, flyer_2 = 0, middle_part_2 = 0;

	bonus_keep_backdrop();
	bonus_mark_players_in_game();
	bonus_1_put_players(&ignored16, &y, &d, &carry);
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
			io_write8(0x18EEu, intro_player_number);
			intro_player_shown++;
			OBJECT(balloon)->x = 0x9Cu;
			OBJECT(balloon)->y = 0xE8u;
			OBJECT(balloon)->z = 0x28u;
			blower_2 = OBJECT(balloon)->bonus_1.blower;
			u = blower_2;
			mem_write16(u + 0xCu, 0xAEu);
			mem_write16(u + 0x11u, 0xE8u);
			mem_write16(u + 0x16u, 0u);
			flyer_2 = OBJECT(balloon)->bonus_1.flyer;
			mem_write8(flyer_2, 0u);
			middle_part_2 = OBJECT(balloon)->bonus_1.middle_part;
			u = middle_part_2;
			mem_write16(u + 0xCu, 0xAEu);
			mem_write16(u + 0x11u, 0xE8u);
			d = 0u;
			mem_write16(u + 0x16u, 0u);
		}
		balloon += 0xC0u;
		intro_player_number++;
		a = intro_player_number;
		carry = a < 4u;
	} while (a != 4u);
	t1 = io_read8(scene_state);
	io_write8(scene_state, t1 + 1u);
	d = (d & 0xFFu) | ((uint32_t)a << 8);
	*p_balloon = balloon;
	*p_y = y;
	*p_d = d;
	*p_carry = carry;
}

/* Bonus 1's introduction: the shown player blows its balloon by itself, a press every 4 frames, while
   the button hints blink. */
void bonus_1_intro_show_how(uint16_t *p_x, uint16_t *p_y, uint16_t *p_d, uint32_t *p_carry)
{
	uint16_t y = (uint16_t)*p_y;
	uint32_t carry = *p_carry;
	uint16_t bonus_player = 0, d = 0, ignored16 = 0, ignored16_2 = 0, record = 0, x = 0, y_2 = 0;
	uint16_t stack = 0, stack_4 = 0;
	uint8_t t1 = 0, t2 = 0;
	uint16_t object = 0;

	bonus_blink_hints(y);
	t1 = io_read8(0x18EEu);
	bonus_player = bonus_1_player_records[(int8_t)((uint8_t)((uint32_t)t1 << 1)) / 2];
	object = BONUS_PLAYER(bonus_player)->object;
	x = object;
	mem_write8(x, mem_read8(x) | 0x10u);
	mem_write8(BONUS_PLAYER(bonus_player)->presses, 0u);
	if ((frame_count & 3u) == 0u)
		mem_write8(BONUS_PLAYER(bonus_player)->presses, 0x10u);
	stack = bonus_player;
	stack_4 = x;
	bonus_1_press_sound(&ignored16, &ignored16_2, &carry);
	x = stack_4;
	record = stack;
	t2 = io_read8(0x18EEu);
	d = (uint32_t)t2 << 8;
	*p_x = x;
	*p_y = y_2;
	*p_d = d;
	bonus_1_blow(record, p_x, p_y, p_d, &carry);
	*p_carry = carry;
}

/* Bonus 1's contest, first state: runs its start by the sub-state. */
void bonus_1_contest_start(uint16_t *p_x, uint16_t *p_y, uint16_t *p_d, uint32_t *p_carry)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t d = (uint16_t)*p_d;
	uint32_t carry = *p_carry;
	uint8_t a = 0;
	uint16_t x = 0;
	uint8_t t1 = 0;

	for (;;)
	{
		portrait_animation = 0x10u;
		x = bonus_1_contest_start_steps_ADDRESS;
		t1 = io_read8(scene_substate);
		a = t1;
		carry = (int8_t)a < 0;
		a = (uint32_t)a << 1;
		switch ((int8_t)a)
		{
		case 0:
			bonus_1_contest_set_up(&x, &y, &d, &carry);
			break;
		case 2:
			bonus_1_contest_ready(&x, &y, &d, &carry);
			break;
		case 4:
			bonus_1_start_music(&d, &carry);
			break;
		case 6:
			bonus_1_blow_until_done(&x, &y, &d, &carry);
			break;
		case 8:
			bonus_1_finish_music(&d, &carry);
			break;
		case 10:
			bonus_1_results(&x, &y, &d, &carry);
			break;
		case 12:
			bonus_1_top_up_balloons(&x, &y, &d, &carry);
			break;
		case 14:
			bonus_1_fly_away(&x, &y, &d, &carry);
			break;
		case 16:
			d = (d & 0xFFu) | ((uint32_t)a << 8);
			bonus_1_end(&d, &carry);
			break;
		case 18:
			bonus_1_fly(&x, &y, &d, &carry);
			break;
		case 20:
			bonus_1_popped(&x, &y, &d, &carry);
			break;
		case 22:
			bonus_1_take_off(x, &y, &d);
			break;
		case 24:
			bonus_1_lift_off(x, &y, &d);
			break;
		case 26:
			bonus_1_speed_up(x, &y, &d, &carry);
			break;
		case 28:
			bonus_1_rise(x, &y, &d, &carry);
			break;
		case 30:
			bonus_1_pop(x, &d, &carry);
			break;
		case 32:
			bonus_1_fall(x, &d, &carry);
			break;
		case 34:
			d = (d & 0xFFu) | ((uint32_t)a << 8);
			bonus_1_lie(x);
			break;
		case 36:
			d = (d & 0xFFu) | ((uint32_t)a << 8);
			bonus_1_fall_done();
			break;
		case 38:
			bonus_pan_start(y, &d, &carry);
			break;
		case 40:
			bonus_pan_up(&x, &d, &carry);
			break;
		case 42:
		case 46:
			d = (d & 0xFFu) | ((uint32_t)a << 8);
			carry = bonus_hide_hints();
			break;
		case 44:
			bonus_show_hints_1(x, &y, &d, &carry);
			break;
		case 48:
			bonus_show_hints_2(x, &y, &d, &carry);
			break;
		case 50:
			d = bonus_title_wait();
			break;
		case 52:
			d = (d & 0xFFu) | ((uint32_t)a << 8);
			bonus_title_show(&x, &y, &d, &carry);
			break;
		case 54:
			d = (d & 0xFFu) | ((uint32_t)a << 8);
			bonus_title_done();
			break;
		case -12:
			bonus_1_intro_pan(&x, &y, &d, &carry);
			break;
		case -10:
			bonus_1_intro_set_up(&x, &y, &d, &carry);
			break;
		case -8:
			bonus_1_intro_show_how(&x, &y, &d, &carry);
			break;
		case -6:
			continue;
		case -4:
			bonus_1_contest_play(&x, &y, &d, &carry);
			break;
		case -2:
			bonus_1_finish(&x, &y, &d, &carry);
			break;
		}
		break;
	}
	*p_x = x;
	*p_y = y;
	*p_d = d;
	*p_carry = carry;
}

/* Bonus 1's contest: sets the timer to 10 seconds, marks the players in the game, gives the absent
   players their press rates and puts everyone's balloon and its parts. */
void bonus_1_contest_set_up(uint16_t *p_player_object, uint16_t *p_y, uint16_t *p_d, uint32_t *p_carry)
{
	uint32_t carry = *p_carry;
	uint16_t d = 0, player_object = 0, y = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0;

	t1 = io_read8(0x18E8u);
	io_write8(0x18E8u, 0u);
	t2 = io_read8(0x18E9u);
	io_write8(0x18E9u, 0u);
	t3 = io_read8(0x18EAu);
	io_write8(0x18EAu, 0u);
	t4 = io_read8(0x18EBu);
	io_write8(0x18EBu, 0u);
	bonus_seconds = 0x10u;
	bonus_mark_players_in_game();
	bonus_1_set_absent_rates();
	bonus_1_put_players(&player_object, &y, &d, &carry);
	io_write8(0x18E2u, 0x60u);
	t5 = io_read8(scene_substate);
	io_write8(scene_substate, t5 + 1u);
	d = (d & 0xFFu) | 0x6000u;
	*p_player_object = player_object;
	*p_y = y;
	*p_d = d;
	*p_carry = carry;
}

/* Bonus 1's contest: shows the READY sign for 96 frames while the balloons stay as they are. */
void bonus_1_contest_ready(uint16_t *p_player_object, uint16_t *p_blower, uint16_t *p_d, uint32_t *p_carry)
{
	uint32_t carry = *p_carry;
	uint16_t blower = 0, d = 0, ignored16 = 0, player_object = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0;

	bonus_show_ready();
	bonus_1_blow_all(&player_object, &blower, &ignored16);
	bonus_draw_x = 0xB8u;
	bonus_draw_y = 0xB8u;
	bonus_1_draw_sign();
	d = bonus_draw_x;
	carry = (uint16_t)(d + 0x28u) < d;
	d += 0x28u;
	bonus_draw_x = d;
	bonus_draw_timer();
	t1 = io_read8(0x18E2u);
	io_write8(0x18E2u, t1 - 1u);
	if (t1 == 1u)
	{
		t2 = io_read8(scene_state);
		io_write8(scene_state, t2 + 1u);
		t3 = io_read8(scene_substate);
		carry = 0u;
		io_write8(scene_substate, 0u);
	}
	*p_player_object = player_object;
	*p_blower = blower;
	*p_d = d;
	*p_carry = carry;
}

/* Bonus 1's contest, while it lasts: takes everyone's presses (the absent players' by their rates),
   blows the balloons and runs the sub-state. */
void bonus_1_contest_play(uint16_t *p_x, uint16_t *p_y, uint16_t *p_d, uint32_t *p_carry)
{
	uint32_t carry = *p_carry;
	uint8_t a = 0;
	uint16_t d = 0, ignored16 = 0, x = 0, y = 0;
	uint8_t t1 = 0;

	for (;;)
	{
		bonus_1_take_presses();
		bonus_1_absent_presses();
		bonus_1_blow_all(&ignored16, &y, &d);
		x = bonus_1_contest_play_steps_ADDRESS;
		t1 = io_read8(scene_substate);
		a = t1;
		carry = (int8_t)a < 0;
		a = (uint32_t)a << 1;
		switch ((int8_t)a)
		{
		case 0:
			*p_d = d;
			bonus_1_start_music(p_d, &carry);
			*p_x = x;
			*p_y = y;
			*p_carry = carry;
			return;
		case 2:
			*p_x = x;
			*p_y = y;
			*p_d = d;
			bonus_1_blow_until_done(p_x, p_y, p_d, &carry);
			*p_carry = carry;
			return;
		case 4:
			*p_d = d;
			bonus_1_finish_music(p_d, &carry);
			*p_x = x;
			*p_y = y;
			*p_carry = carry;
			return;
		case 6:
			*p_x = x;
			*p_y = y;
			*p_d = d;
			bonus_1_results(p_x, p_y, p_d, &carry);
			*p_carry = carry;
			return;
		case 8:
			*p_x = x;
			*p_y = y;
			*p_d = d;
			bonus_1_top_up_balloons(p_x, p_y, p_d, &carry);
			*p_carry = carry;
			return;
		case 10:
			*p_x = x;
			*p_y = y;
			*p_d = d;
			bonus_1_fly_away(p_x, p_y, p_d, &carry);
			*p_carry = carry;
			return;
		case 12:
			d = (d & 0xFFu) | ((uint32_t)a << 8);
			*p_d = d;
			bonus_1_end(p_d, &carry);
			*p_x = x;
			*p_y = y;
			*p_carry = carry;
			return;
		case 14:
			*p_x = x;
			*p_y = y;
			*p_d = d;
			bonus_1_fly(p_x, p_y, p_d, &carry);
			*p_carry = carry;
			return;
		case 16:
			*p_x = x;
			*p_y = y;
			*p_d = d;
			bonus_1_popped(p_x, p_y, p_d, &carry);
			*p_carry = carry;
			return;
		case 18:
			*p_y = y;
			*p_d = d;
			bonus_1_take_off(x, p_y, p_d);
			*p_x = x;
			*p_carry = carry;
			return;
		case 20:
			*p_y = y;
			*p_d = d;
			bonus_1_lift_off(x, p_y, p_d);
			*p_x = x;
			*p_carry = carry;
			return;
		case 22:
			*p_y = y;
			*p_d = d;
			bonus_1_speed_up(x, p_y, p_d, &carry);
			*p_x = x;
			*p_carry = carry;
			return;
		case 24:
			*p_y = y;
			*p_d = d;
			bonus_1_rise(x, p_y, p_d, &carry);
			*p_x = x;
			*p_carry = carry;
			return;
		case 26:
			*p_d = d;
			bonus_1_pop(x, p_d, &carry);
			*p_x = x;
			*p_y = y;
			*p_carry = carry;
			return;
		case 28:
			*p_d = d;
			bonus_1_fall(x, p_d, &carry);
			*p_x = x;
			*p_y = y;
			*p_carry = carry;
			return;
		case 30:
			d = (d & 0xFFu) | ((uint32_t)a << 8);
			bonus_1_lie(x);
			*p_x = x;
			*p_y = y;
			*p_d = d;
			*p_carry = carry;
			return;
		case 32:
			d = (d & 0xFFu) | ((uint32_t)a << 8);
			bonus_1_fall_done();
			*p_x = x;
			*p_y = y;
			*p_d = d;
			*p_carry = carry;
			return;
		case 34:
			*p_d = d;
			bonus_pan_start(y, p_d, &carry);
			*p_x = x;
			*p_y = y;
			*p_carry = carry;
			return;
		case 36:
			*p_x = x;
			*p_d = d;
			bonus_pan_up(p_x, p_d, &carry);
			*p_y = y;
			*p_carry = carry;
			return;
		case 38:
		case 42:
			d = (d & 0xFFu) | ((uint32_t)a << 8);
			carry = bonus_hide_hints();
			*p_x = x;
			*p_y = y;
			*p_d = d;
			*p_carry = carry;
			return;
		case 40:
			*p_y = y;
			*p_d = d;
			bonus_show_hints_1(x, p_y, p_d, &carry);
			*p_x = x;
			*p_carry = carry;
			return;
		case 44:
			*p_y = y;
			*p_d = d;
			bonus_show_hints_2(x, p_y, p_d, &carry);
			*p_x = x;
			*p_carry = carry;
			return;
		case 46:
			d = bonus_title_wait();
			*p_x = x;
			*p_y = y;
			*p_d = d;
			*p_carry = carry;
			return;
		case 48:
			d = (d & 0xFFu) | ((uint32_t)a << 8);
			*p_x = x;
			*p_y = y;
			*p_d = d;
			bonus_title_show(p_x, p_y, p_d, &carry);
			*p_carry = carry;
			return;
		case 50:
			break;
		case -16:
			*p_x = x;
			*p_y = y;
			*p_d = d;
			bonus_1_intro_pan(p_x, p_y, p_d, &carry);
			*p_carry = carry;
			return;
		case -14:
			*p_x = x;
			*p_y = y;
			*p_d = d;
			bonus_1_intro_set_up(p_x, p_y, p_d, &carry);
			*p_carry = carry;
			return;
		case -12:
			*p_x = x;
			*p_y = y;
			*p_d = d;
			bonus_1_intro_show_how(p_x, p_y, p_d, &carry);
			*p_carry = carry;
			return;
		case -10:
			*p_x = x;
			*p_y = y;
			*p_d = d;
			bonus_1_contest_start(p_x, p_y, p_d, &carry);
			*p_carry = carry;
			return;
		case -8:
			continue;
		case -6:
			*p_x = x;
			*p_y = y;
			*p_d = d;
			bonus_1_finish(p_x, p_y, p_d, &carry);
			*p_carry = carry;
			return;
		case -4:
			*p_x = x;
			*p_y = y;
			*p_d = d;
			bonus_1_contest_set_up(p_x, p_y, p_d, &carry);
			*p_carry = carry;
			return;
		case -2:
			*p_x = x;
			*p_y = y;
			*p_d = d;
			bonus_1_contest_ready(p_x, p_y, p_d, &carry);
			*p_carry = carry;
			return;
		}
		break;
	}
	d = (d & 0xFFu) | ((uint32_t)a << 8);
	bonus_title_done();
	*p_x = x;
	*p_y = y;
	*p_d = d;
	*p_carry = carry;
}

/* Bonus 1's contest: starts its music (sound 8900). */
void bonus_1_start_music(uint16_t *p_d, uint32_t *p_carry)
{
	uint32_t carry = *p_carry;
	uint16_t d = 0;
	uint8_t t1 = 0;

	d = 0x8900u;
	carry = vector_queue_sound_unless_attract(d);
	t1 = io_read8(scene_substate);
	io_write8(scene_substate, t1 + 1u);
	*p_d = d;
	*p_carry = carry;
}

/* Bonus 1's contest: shows GO and counts the time down; when a balloon is full or the time is up, stops
   the balloons and keeps each player's result (from its balloon's size) for the ranking. */
void bonus_1_blow_until_done(uint16_t *p_balloon, uint16_t *p_middle_part, uint16_t *p_d, uint32_t *p_carry)
{
	uint16_t middle_part = (uint16_t)*p_middle_part;
	uint32_t carry = *p_carry;
	uint8_t a = 0, animation = 0, b = 0, type = 0;
	uint16_t balloon = 0, blower = 0, d = 0;
	uint8_t stack = 0;
	uint8_t in_game = 0, t2 = 0, t3 = 0, t4 = 0;
	uint16_t blower_2 = 0, middle_part_2 = 0, size = 0, t1 = 0, t5 = 0, t6 = 0;

	bonus_show_go();
	bonus_1_any_balloon_full(&balloon, &carry);
	if (carry)
	{
		balloon = OBJECT_ADDRESS(0);
		stack = 4u;
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
			t1 = size - 0xA0u;
			type = (uint8_t)(t1 >> 2);
			OBJECT(balloon)->type = type;
			balloon += 0xC0u;
			t2 = stack;
			stack = t2 - 1u;
		} while (t2 != 1u);
		t3 = io_read8(scene_state);
		io_write8(scene_state, t3 + 1u);
		t4 = io_read8(scene_substate);
		carry = 0u;
		io_write8(scene_substate, 0u);
		d = ((uint32_t)stack << 8) | type;
	}
	else
	{
		carry = bonus_timer_tick();
		if (carry)
		{
			balloon = OBJECT_ADDRESS(0);
			stack = 4u;
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
				t1 = size - 0xA0u;
				type = (uint8_t)(t1 >> 2);
				OBJECT(balloon)->type = type;
				balloon += 0xC0u;
				t2 = stack;
				stack = t2 - 1u;
			} while (t2 != 1u);
			t3 = io_read8(scene_state);
			io_write8(scene_state, t3 + 1u);
			t4 = io_read8(scene_substate);
			carry = 0u;
			io_write8(scene_substate, 0u);
			d = ((uint32_t)stack << 8) | type;
		}
		else
		{
			bonus_draw_x = 0xB8u;
			bonus_draw_y = 0xB8u;
			bonus_1_draw_sign();
			t5 = bonus_draw_x;
			t6 = t5;
			carry = (uint16_t)(t6 + 0x28u) < t6;
			a = (uint8_t)((uint16_t)(t6 + 0x28u) >> 8);
			b = (uint8_t)(t6 + 0x28u);
			bonus_draw_x = ((uint32_t)a << 8) | b;
			bonus_draw_timer();
			d = ((uint32_t)a << 8) | b;
		}
	}
	*p_balloon = balloon;
	*p_middle_part = middle_part;
	*p_d = d;
	*p_carry = carry;
}

/* Bonus 1's end: runs it by the sub-state: the music, the results, the small balloons topped up and the
   flight. */
void bonus_1_finish(uint16_t *p_x, uint16_t *p_y, uint16_t *p_d, uint32_t *p_carry)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t d = (uint16_t)*p_d;
	uint32_t carry = *p_carry;
	uint8_t a = 0;
	uint16_t x = 0;
	uint8_t t1 = 0;

	for (;;)
	{
		x = bonus_1_finish_steps_ADDRESS;
		t1 = io_read8(scene_substate);
		a = t1;
		carry = (int8_t)a < 0;
		a = (uint32_t)a << 1;
		switch ((int8_t)a)
		{
		case 0:
			bonus_1_finish_music(&d, &carry);
			break;
		case 2:
			bonus_1_results(&x, &y, &d, &carry);
			break;
		case 4:
			bonus_1_top_up_balloons(&x, &y, &d, &carry);
			break;
		case 6:
			bonus_1_fly_away(&x, &y, &d, &carry);
			break;
		case 8:
			d = (d & 0xFFu) | ((uint32_t)a << 8);
			bonus_1_end(&d, &carry);
			break;
		case 10:
			bonus_1_fly(&x, &y, &d, &carry);
			break;
		case 12:
			bonus_1_popped(&x, &y, &d, &carry);
			break;
		case 14:
			bonus_1_take_off(x, &y, &d);
			break;
		case 16:
			bonus_1_lift_off(x, &y, &d);
			break;
		case 18:
			bonus_1_speed_up(x, &y, &d, &carry);
			break;
		case 20:
			bonus_1_rise(x, &y, &d, &carry);
			break;
		case 22:
			bonus_1_pop(x, &d, &carry);
			break;
		case 24:
			bonus_1_fall(x, &d, &carry);
			break;
		case 26:
			d = (d & 0xFFu) | ((uint32_t)a << 8);
			bonus_1_lie(x);
			break;
		case 28:
			d = (d & 0xFFu) | ((uint32_t)a << 8);
			bonus_1_fall_done();
			break;
		case 30:
			bonus_pan_start(y, &d, &carry);
			break;
		case 32:
			bonus_pan_up(&x, &d, &carry);
			break;
		case 34:
		case 38:
			d = (d & 0xFFu) | ((uint32_t)a << 8);
			carry = bonus_hide_hints();
			break;
		case 36:
			bonus_show_hints_1(x, &y, &d, &carry);
			break;
		case 40:
			bonus_show_hints_2(x, &y, &d, &carry);
			break;
		case 42:
			d = bonus_title_wait();
			break;
		case 44:
			d = (d & 0xFFu) | ((uint32_t)a << 8);
			bonus_title_show(&x, &y, &d, &carry);
			break;
		case 46:
			d = (d & 0xFFu) | ((uint32_t)a << 8);
			bonus_title_done();
			break;
		case -20:
			bonus_1_intro_pan(&x, &y, &d, &carry);
			break;
		case -18:
			bonus_1_intro_set_up(&x, &y, &d, &carry);
			break;
		case -16:
			bonus_1_intro_show_how(&x, &y, &d, &carry);
			break;
		case -14:
			bonus_1_contest_start(&x, &y, &d, &carry);
			break;
		case -12:
			bonus_1_contest_play(&x, &y, &d, &carry);
			break;
		case -10:
			continue;
		case -8:
			bonus_1_contest_set_up(&x, &y, &d, &carry);
			break;
		case -6:
			bonus_1_contest_ready(&x, &y, &d, &carry);
			break;
		case -4:
			bonus_1_start_music(&d, &carry);
			break;
		case -2:
			bonus_1_blow_until_done(&x, &y, &d, &carry);
			break;
		}
		break;
	}
	*p_x = x;
	*p_y = y;
	*p_d = d;
	*p_carry = carry;
}

/* Bonus 1's end: starts the results' music (sound 8800). */
void bonus_1_finish_music(uint16_t *p_d, uint32_t *p_carry)
{
	uint32_t carry = *p_carry;
	uint16_t d = 0;
	uint8_t t1 = 0;

	d = 0x8800u;
	carry = vector_queue_sound_unless_attract(d);
	t1 = io_read8(scene_substate);
	io_write8(scene_substate, t1 + 1u);
	*p_d = d;
	*p_carry = carry;
}

/* Bonus 1's end: shows the results; when they are done, marks the players whose balloon is too small and
   gives each a wait before its flight by its place. */
void bonus_1_results(uint16_t *p_balloon, uint16_t *p_wait_place, uint16_t *p_d, uint32_t *p_carry)
{
	uint16_t wait_place = (uint16_t)*p_wait_place;
	uint16_t d = (uint16_t)*p_d;
	uint32_t carry = *p_carry;
	uint8_t a = 0, animation = 0, b = 0, player_number = 0, wait = 0;
	uint16_t balloon = 0, blower = 0, d_2 = 0, places = 0;
	uint8_t stack = 0;
	uint16_t stack_3 = 0;
	uint8_t too_small = 0, in_game = 0, t2 = 0;
	uint16_t size = 0, blower_2 = 0, middle_part = 0, t1 = 0;

	bonus_results(&balloon, &wait_place, &d, &carry);
	a = (uint8_t)(d >> 8);
	b = (uint8_t)d;
	if (carry == 0u)
		d_2 = ((uint32_t)a << 8) | b;
	else
	{
		balloon = OBJECT_ADDRESS(0);
		places = results_places_ADDRESS;
		wait_place = 0x18E4u;
		stack = 0u;
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
				stack_3 = wait_place;
				blower_2 = OBJECT(balloon)->bonus_1.blower;
				blower = blower_2;
				animation = 0x82u;
				in_game = OBJECT(balloon)->bonus_1.in_game;
				if (in_game == 0u)
					animation = 0xAAu;
				OBJECT(blower)->animation = animation;
				middle_part = OBJECT(balloon)->bonus_1.middle_part;
				mem_write8(middle_part + 5u, 0x81u);
				wait_place = stack_3;
			}
			t1 = places;
			places = t1 + 1u;
			wait = 0xFu * mem_read8(t1);
			mem_write8(wait_place, wait);
			wait_place++;
			balloon += 0xC0u;
			stack = stack + 1u;
			player_number = stack;
			carry = player_number < 4u;
		} while (player_number != 4u);
		t2 = io_read8(scene_substate);
		io_write8(scene_substate, t2 + 1u);
		d_2 = ((uint32_t)stack << 8) | wait;
	}
	*p_balloon = balloon;
	*p_wait_place = wait_place;
	*p_d = d_2;
	*p_carry = carry;
}

/* Bonus 1's end: the balloons too small blow up by themselves until big enough to fly, then a sound
   (AD00). */
void bonus_1_top_up_balloons(uint16_t *p_player_records_place, uint16_t *p_middle_part, uint16_t *p_d, uint32_t *p_carry)
{
	uint16_t middle_part = (uint16_t)*p_middle_part;
	uint32_t carry = *p_carry;
	uint8_t animation = 0, b = 0;
	uint16_t balloon = 0, blower = 0, bonus_player = 0, command = 0, d = 0, player_number = 0, player_records_place = 0;
	uint8_t stack = 0;
	uint8_t too_small = 0, in_game = 0, t1 = 0, t2 = 0;
	uint16_t size = 0, blower_2 = 0, middle_part_2 = 0;

	balloons_growing = 0u;
	balloon = OBJECT_ADDRESS(0);
	stack = 0u;
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
				OBJECT(middle_part)->animation = 0x81u;
			}
			else
			{
				bonus_player = bonus_1_player_records[(int8_t)((uint8_t)((uint32_t)stack << 1)) / 2];
				mem_write8(BONUS_PLAYER(bonus_player)->presses, 0u);
				if ((frame_count & 1u) == 0u)
					mem_write8(BONUS_PLAYER(bonus_player)->presses, 0x10u);
				player_number = (uint32_t)stack << 8;
				bonus_1_blow(bonus_player, &balloon, &middle_part, &player_number, &carry);
			}
		}
		t1 = OBJECT(balloon)->unk_3F;
		balloons_growing |= t1;
		balloon += 0xC0u;
		stack = stack + 1u;
	} while (stack != 4u);
	if (balloons_growing == 0u)
	{
		command = 0xAD00u;
		carry = vector_queue_sound(command);
		t2 = io_read8(scene_substate);
		io_write8(scene_substate, t2 + 1u);
	}
	bonus_1_press_sound(&player_records_place, &d, &carry);
	b = (uint8_t)d;
	d = ((uint32_t)stack << 8) | b;
	*p_player_records_place = player_records_place;
	*p_middle_part = middle_part;
	*p_d = d;
	*p_carry = carry;
}

/* Bonus 1's end: after each player's wait, runs its balloon's flight; goes on when all four are gone. */
void bonus_1_fly_away(uint16_t *p_player_object, uint16_t *p_y, uint16_t *p_d, uint32_t *p_carry)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t d = (uint16_t)*p_d;
	uint32_t carry = *p_carry;
	uint8_t flown = 0;
	uint16_t d_2 = 0, player_object = 0, wait_place = 0;
	uint8_t stack = 0;
	uint16_t stack_3 = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0;

	t1 = io_read8(0x18ECu);
	io_write8(0x18ECu, 0u);
	player_object = OBJECT_ADDRESS(0);
	wait_place = 0x18E4u;
	stack = 0u;
	do
	{
		if (mem_read8(wait_place) != 0u)
			mem_write8(wait_place, mem_read8(wait_place) - 1u);
		else
		{
			stack_3 = wait_place;
			bonus_1_flight(&player_object, &y, &d);
			wait_place = stack_3;
		}
		player_object += 0xC0u;
		wait_place++;
		stack = stack + 1u;
	} while (stack != 4u);
	t2 = io_read8(0x18ECu);
	flown = t2;
	carry = flown < 4u;
	if (flown == 4u)
	{
		t3 = io_read8(scene_substate);
		io_write8(scene_substate, t3 + 1u);
	}
	d_2 = (d & 0xFFu) | ((uint32_t)stack << 8);
	*p_player_object = player_object;
	*p_y = y;
	*p_d = d_2;
	*p_carry = carry;
}

/* Bonus 1's last state: gives the winner its health and goes on to the step's next part. */
void bonus_1_end(uint16_t *p_d, uint32_t *p_carry)
{
	uint16_t d = (uint16_t)*p_d;
	uint32_t carry = *p_carry;
	uint16_t d_2 = 0;
	uint16_t stack = 0;

	bonus_reward_winners(&d, &carry);
	step_phase++;
	stack = d;
	step_subphase = (uint8_t)(d >> 8u);
	step_countdown = (uint8_t)d;
	d_2 = stack;
	*p_d = d_2;
	*p_carry = carry;
}

/* Bonus 1: blows each player's balloon by its presses. */
void bonus_1_blow_all(uint16_t *p_player_object, uint16_t *p_blower, uint16_t *p_d)
{
	uint32_t carry = 0;
	uint8_t player_number = 0;
	uint16_t blower = 0, d = 0, ignored16 = 0, ignored16_2 = 0, player_object = 0, record = 0;

	bonus_1_press_sound(&ignored16, &ignored16_2, &carry);
	player_object = OBJECT_ADDRESS(0);
	blowing_player_number = 0u;
	do
	{
		record = bonus_1_player_records[(int8_t)((uint8_t)((uint32_t)blowing_player_number << 1)) / 2];
		d = (uint32_t)blowing_player_number << 8;
		bonus_1_blow(record, &player_object, &blower, &d, &carry);
		player_object += 0xC0u;
		blowing_player_number++;
		player_number = blowing_player_number;
	} while (player_number != 4u);
	d = (d & 0xFFu) | ((uint32_t)player_number << 8);
	*p_player_object = player_object;
	*p_blower = blower;
	*p_d = d;
}

/* Bonus 1: one player's balloon: a press makes it grow for 16 frames, else it shrinks; its zoom follows
   its size, and at the smallest it shows empty. */
void bonus_1_blow(uint16_t record, uint16_t *p_balloon, uint16_t *p_blower, uint16_t *p_player_number, uint32_t *p_carry)
{
	uint16_t balloon = (uint16_t)*p_balloon;
	uint16_t player_number = (uint16_t)*p_player_number;
	uint32_t carry = *p_carry;
	uint8_t a = 0, animation = 0, animation_flags = 0, b = 0, state = 0;
	uint16_t blower = 0, middle_part = 0;
	uint8_t stack_10001 = 0, stack_10002 = 0;
	uint16_t stack = 0, stack_4 = 0;
	uint8_t t1 = 0, animation_flags_2 = 0, animation_flags_3 = 0, growing = 0, animation_flags_4 = 0, timer = 0, animation_flags_5 = 0, growing_2 = 0, in_game = 0, animation_flags_6 = 0, animation_2 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, zoom_x = 0, zoom_x_2 = 0, in_game_2 = 0, t7 = 0, t8 = 0;
	uint16_t blower_2 = 0, blower_3 = 0, middle_part_2 = 0, blower_4 = 0, middle_part_3 = 0, growth = 0, growth_2 = 0;
	uint32_t t6 = 0;

	blowing_player = player_number >> 8;
	t1 = io_read8(scene_state);
	state = t1;
	carry = state < 0u;
	if (state == 0u)
	{
		blower_2 = OBJECT(balloon)->bonus_1.blower;
		blower = blower_2;
		animation_flags_2 = OBJECT(blower)->animation_flags;
		animation_flags = animation_flags_2 | 0x40u;
		OBJECT(blower)->animation_flags = animation_flags;
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
					mem_write8(middle_part_2 + 5u, 0x81u);
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
				carry = bonus_1_stretch_height(balloon);
				if (carry)
					carry = bonus_1_stretch_width(balloon);
			}
			else if ((random_number & 3u) != 0u)
			{
				carry = bonus_1_stretch_height(balloon);
				if (carry)
					carry = bonus_1_stretch_width(balloon);
			}
			else
			{
				carry = bonus_1_stretch_width(balloon);
				if (carry)
					carry = bonus_1_stretch_height(balloon);
			}
		}
		else
		{
			growth_2 = OBJECT(balloon)->bonus_1.growth;
			OBJECT(balloon)->bonus_1.growth = 0u - growth_2;
			balloon_growing++;
			if ((random_number & 3u) != 0u)
			{
				carry = bonus_1_stretch_height(balloon);
				if (carry)
					carry = bonus_1_stretch_width(balloon);
			}
			else
			{
				carry = bonus_1_stretch_width(balloon);
				if (carry)
					carry = bonus_1_stretch_height(balloon);
			}
		}
		t2 = (uint8_t)(OBJECT(balloon)->bonus_1.width_zoom >> 8u);
		OBJECT(balloon)->zoom_x = t2;
		t3 = (uint8_t)(OBJECT(balloon)->bonus_1.height_zoom >> 8u);
		OBJECT(balloon)->zoom_y = t3;
		t4 = (uint8_t)(OBJECT(balloon)->bonus_1.width_zoom >> 8u);
		stack_10001 = 0u;
		stack_10002 = 0u - t4;
		t5 = (uint8_t)(OBJECT(balloon)->bonus_1.height_zoom >> 8u);
		b = 0u - t5;
		OBJECT(balloon)->bonus_1.size = b + (((uint32_t)stack_10001 << 8) | stack_10002);
		stack = balloon;
		zoom_x = OBJECT(balloon)->zoom_x;
		stack_4 = konami_divx(0x4000u, zoom_x) * 0x20u;
		balloon = stack;
		OBJECT(balloon)->box_width = stack_4 >> 8;
		OBJECT(balloon)->box_depth = 0x40u;
		stack = balloon;
		zoom_x_2 = OBJECT(balloon)->zoom_x;
		t6 = konami_divx(0x4000u, zoom_x_2) * 0u;
		blower = (uint16_t)t6;
		carry = t6 >> 15;
		stack_4 = blower;
		b = (uint8_t)stack_4;
		balloon = stack;
		OBJECT(balloon)->box_dx = stack_4 >> 8;
		OBJECT(balloon)->box_dy = 0x20;
		OBJECT(balloon)->box_height = 1u;
		in_game_2 = OBJECT(balloon)->bonus_1.in_game;
		a = in_game_2;
		if (in_game_2 != 0u)
		{
			OBJECT(balloon)->animation = 0x86u;
			t7 = (uint8_t)(OBJECT(balloon)->bonus_1.width_zoom >> 8u);
			a = t7;
			carry = a < 0xB0u;
			if (a == 0xB0u)
			{
				t8 = (uint8_t)(OBJECT(balloon)->bonus_1.height_zoom >> 8u);
				a = t8;
				carry = a < 0xB0u;
				if (a == 0xB0u)
				{
					OBJECT(balloon)->animation = 0x85u;
					OBJECT(balloon)->zoom_x = 0x40u;
					a = 0x40u;
					OBJECT(balloon)->zoom_y = 0x40u;
				}
			}
		}
		player_number = ((uint32_t)a << 8) | b;
	}
	*p_balloon = balloon;
	*p_blower = blower;
	*p_player_number = player_number;
	*p_carry = carry;
}

/* Bonus 1: grows or shrinks the balloon's width by its speed, between 4000 and B000 (carry: at a limit). */
uint32_t bonus_1_stretch_width(uint16_t object)
{
	uint32_t carry = 0;
	uint16_t action_step = 0;
	uint16_t stack = 0, stack_4 = 0;
	uint16_t growth = 0, width_zoom = 0, action_step_2 = 0;

	stack = object;
	growth = OBJECT(object)->bonus_1.growth;
	stack_4 = growth;
	width_zoom = OBJECT(object)->bonus_1.width_zoom;
	stack_4 = ((((uint32_t)width_zoom * width_zoom) >> 16) * stack_4) >> 16;
	action_step = stack_4;
	object = stack;
	if (balloon_growing == 0u)
		action_step = 0u - action_step;
	action_step_2 = (((uint32_t)OBJECT(object)->action_step << 8u) | (OBJECT(object)->behaviour >> 8u));
	action_step += action_step_2;
	if (action_step > 0xB000u)
	{
		OBJECT(object)->action_step = 0xB0u;
		OBJECT(object)->behaviour &= 0xFFu;
		carry = 1u;
		return carry;
	}
	if (action_step >= floor_map_ADDRESS)
	{
		OBJECT(object)->action_step = (uint8_t)(action_step >> 8u);
		OBJECT(object)->behaviour = (OBJECT(object)->behaviour & 0xFFu) | ((action_step & 0xFFu) << 8u);
		carry = 0u;
		return carry;
	}
	OBJECT(object)->action_step = 0x40u;
	OBJECT(object)->behaviour &= 0xFFu;
	carry = 1u;
	return carry;
}

/* Bonus 1: grows or shrinks the balloon's height by its speed, between 2000 and B000 (carry: at a
   limit). */
uint32_t bonus_1_stretch_height(uint16_t object)
{
	uint32_t carry = 0;
	uint16_t change = 0;
	uint16_t stack = 0, stack_4 = 0;
	uint16_t growth = 0, height_zoom = 0, t1 = 0;

	stack = object;
	growth = OBJECT(object)->bonus_1.growth;
	stack_4 = growth;
	height_zoom = OBJECT(object)->bonus_1.height_zoom;
	stack_4 = ((((uint32_t)height_zoom * height_zoom) >> 16) * stack_4) >> 16;
	change = stack_4;
	object = stack;
	if (balloon_growing == 0u)
		change = 0u - change;
	t1 = (((uint32_t)(OBJECT(object)->behaviour & 0xFFu) << 8u) | (OBJECT(object)->target_dx >> 8u));
	change += t1;
	if (change > 0xB000u)
	{
		OBJECT(object)->behaviour = (OBJECT(object)->behaviour & 0xFF00u) | 0xB0u;
		OBJECT(object)->target_dx &= 0xFFu;
		carry = 1u;
		return carry;
	}
	if (change >= 0x2000u)
	{
		OBJECT(object)->behaviour = (OBJECT(object)->behaviour & 0xFF00u) | ((change >> 8u) & 0xFFu);
		OBJECT(object)->target_dx = (OBJECT(object)->target_dx & 0xFFu) | ((change & 0xFFu) << 8u);
		carry = 0u;
		return carry;
	}
	OBJECT(object)->behaviour = (OBJECT(object)->behaviour & 0xFF00u) | 0x20u;
	OBJECT(object)->target_dx &= 0xFFu;
	carry = 1u;
	return carry;
}

/* Bonus 1: runs a player's balloon by its flight (field 43): flying off, or popped. */
void bonus_1_flight(uint16_t *p_object, uint16_t *p_y, uint16_t *p_d)
{
	uint16_t object = (uint16_t)*p_object;
	uint16_t y = (uint16_t)*p_y;
	uint16_t d = (uint16_t)*p_d;
	uint32_t carry = 0;
	uint8_t a = 0;
	uint8_t flight = 0;

	flight = OBJECT(object)->bonus_1.flight;
	a = (uint32_t)flight << 1;
	switch ((int8_t)a)
	{
	case 0:
		bonus_1_fly(&object, &y, &d, &carry);
		break;
	case 2:
		bonus_1_popped(&object, &y, &d, &carry);
		break;
	case 4:
		bonus_1_take_off(object, &y, &d);
		break;
	case 6:
		bonus_1_lift_off(object, &y, &d);
		break;
	case 8:
		bonus_1_speed_up(object, &y, &d, &carry);
		break;
	case 10:
		bonus_1_rise(object, &y, &d, &carry);
		break;
	case 12:
		bonus_1_pop(object, &d, &carry);
		break;
	case 14:
		bonus_1_fall(object, &d, &carry);
		break;
	case 16:
		d = (d & 0xFFu) | ((uint32_t)a << 8);
		bonus_1_lie(object);
		break;
	case 18:
		d = (d & 0xFFu) | ((uint32_t)a << 8);
		bonus_1_fall_done();
		break;
	case 20:
		bonus_pan_start(y, &d, &carry);
		break;
	case 22:
		bonus_pan_up(&object, &d, &carry);
		break;
	case 24:
	case 28:
		d = (d & 0xFFu) | ((uint32_t)a << 8);
		carry = bonus_hide_hints();
		break;
	case 26:
		bonus_show_hints_1(object, &y, &d, &carry);
		break;
	case 30:
		bonus_show_hints_2(object, &y, &d, &carry);
		break;
	case 32:
		d = bonus_title_wait();
		break;
	case 34:
		d = (d & 0xFFu) | ((uint32_t)a << 8);
		bonus_title_show(&object, &y, &d, &carry);
		break;
	case 36:
		d = (d & 0xFFu) | ((uint32_t)a << 8);
		bonus_title_done();
		break;
	case -30:
		bonus_1_intro_pan(&object, &y, &d, &carry);
		break;
	case -28:
		bonus_1_intro_set_up(&object, &y, &d, &carry);
		break;
	case -26:
		bonus_1_intro_show_how(&object, &y, &d, &carry);
		break;
	case -24:
		bonus_1_contest_start(&object, &y, &d, &carry);
		break;
	case -22:
		bonus_1_contest_play(&object, &y, &d, &carry);
		break;
	case -20:
		bonus_1_finish(&object, &y, &d, &carry);
		break;
	case -18:
		bonus_1_contest_set_up(&object, &y, &d, &carry);
		break;
	case -16:
		bonus_1_contest_ready(&object, &y, &d, &carry);
		break;
	case -14:
		bonus_1_start_music(&d, &carry);
		break;
	case -12:
		bonus_1_blow_until_done(&object, &y, &d, &carry);
		break;
	case -10:
		bonus_1_finish_music(&d, &carry);
		break;
	case -8:
		bonus_1_results(&object, &y, &d, &carry);
		break;
	case -6:
		bonus_1_top_up_balloons(&object, &y, &d, &carry);
		break;
	case -4:
		bonus_1_fly_away(&object, &y, &d, &carry);
		break;
	case -2:
		d = (d & 0xFFu) | ((uint32_t)a << 8);
		bonus_1_end(&d, &carry);
		break;
	}
	*p_object = object;
	*p_y = y;
	*p_d = d;
}

/* Bonus 1: runs a flying balloon by its step (field 44). */
void bonus_1_fly(uint16_t *p_object, uint16_t *p_y, uint16_t *p_d, uint32_t *p_carry)
{
	uint16_t object = (uint16_t)*p_object;
	uint16_t y = (uint16_t)*p_y;
	uint16_t d = (uint16_t)*p_d;
	uint32_t carry = *p_carry;
	uint8_t a = 0;
	uint8_t flight_step = 0;

	for (;;)
	{
		flight_step = OBJECT(object)->bonus_1.flight_step;
		a = flight_step;
		carry = (int8_t)a < 0;
		a = (uint32_t)a << 1;
		switch ((int8_t)a)
		{
		case 0:
			bonus_1_take_off(object, &y, &d);
			break;
		case 2:
			bonus_1_lift_off(object, &y, &d);
			break;
		case 4:
			bonus_1_speed_up(object, &y, &d, &carry);
			break;
		case 6:
			bonus_1_rise(object, &y, &d, &carry);
			break;
		case 8:
			bonus_1_pop(object, &d, &carry);
			break;
		case 10:
			bonus_1_fall(object, &d, &carry);
			break;
		case 12:
			d = (d & 0xFFu) | ((uint32_t)a << 8);
			bonus_1_lie(object);
			break;
		case 14:
			d = (d & 0xFFu) | ((uint32_t)a << 8);
			bonus_1_fall_done();
			break;
		case 16:
			bonus_pan_start(y, &d, &carry);
			break;
		case 18:
			bonus_pan_up(&object, &d, &carry);
			break;
		case 20:
		case 24:
			d = (d & 0xFFu) | ((uint32_t)a << 8);
			carry = bonus_hide_hints();
			break;
		case 22:
			bonus_show_hints_1(object, &y, &d, &carry);
			break;
		case 26:
			bonus_show_hints_2(object, &y, &d, &carry);
			break;
		case 28:
			d = bonus_title_wait();
			break;
		case 30:
			d = (d & 0xFFu) | ((uint32_t)a << 8);
			bonus_title_show(&object, &y, &d, &carry);
			break;
		case 32:
			d = (d & 0xFFu) | ((uint32_t)a << 8);
			bonus_title_done();
			break;
		case -34:
			bonus_1_intro_pan(&object, &y, &d, &carry);
			break;
		case -32:
			bonus_1_intro_set_up(&object, &y, &d, &carry);
			break;
		case -30:
			bonus_1_intro_show_how(&object, &y, &d, &carry);
			break;
		case -28:
			bonus_1_contest_start(&object, &y, &d, &carry);
			break;
		case -26:
			bonus_1_contest_play(&object, &y, &d, &carry);
			break;
		case -24:
			bonus_1_finish(&object, &y, &d, &carry);
			break;
		case -22:
			bonus_1_contest_set_up(&object, &y, &d, &carry);
			break;
		case -20:
			bonus_1_contest_ready(&object, &y, &d, &carry);
			break;
		case -18:
			bonus_1_start_music(&d, &carry);
			break;
		case -16:
			bonus_1_blow_until_done(&object, &y, &d, &carry);
			break;
		case -14:
			bonus_1_finish_music(&d, &carry);
			break;
		case -12:
			bonus_1_results(&object, &y, &d, &carry);
			break;
		case -10:
			bonus_1_top_up_balloons(&object, &y, &d, &carry);
			break;
		case -8:
			bonus_1_fly_away(&object, &y, &d, &carry);
			break;
		case -6:
			d = (d & 0xFFu) | ((uint32_t)a << 8);
			bonus_1_end(&d, &carry);
			break;
		case -4:
			continue;
		case -2:
			bonus_1_popped(&object, &y, &d, &carry);
			break;
		}
		break;
	}
	*p_object = object;
	*p_y = y;
	*p_d = d;
	*p_carry = carry;
}

/* Bonus 1: a balloon's flight starts: the player holds on to it. */
void bonus_1_take_off(uint16_t object, uint16_t *p_blower, uint16_t *p_d)
{
	uint8_t animation = 0, in_game = 0;
	uint16_t blower = 0, d = 0, flyer = 0;
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
	mem_write8(middle_part + 5u, 0x83u);
	blower_2 = OBJECT(object)->bonus_1.blower;
	blower = blower_2;
	OBJECT(blower)->kind = 0xAu;
	OBJECT(blower)->animation = 0x8Fu;
	OBJECT(object)->bonus_1.lift_time = 0x20u;
	flight_step = OBJECT(object)->bonus_1.flight_step;
	OBJECT(object)->bonus_1.flight_step = flight_step + 1u;
	d = 0x2000u | in_game;
	*p_blower = blower;
	*p_d = d;
}

/* Bonus 1: the player and its balloon start rising. */
void bonus_1_lift_off(uint16_t object, uint16_t *p_flyer, uint16_t *p_z_speed)
{
	uint16_t flyer = (uint16_t)*p_flyer;
	uint16_t z_speed = 0;
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
		z_speed_2 = OBJECT(object)->z_speed;
		z_speed = z_speed_2;
		OBJECT(flyer)->z_speed = z_speed;
		flight_step = OBJECT(object)->bonus_1.flight_step;
		OBJECT(object)->bonus_1.flight_step = flight_step + 1u;
	}
	*p_flyer = flyer;
	*p_z_speed = z_speed;
}

/* Bonus 1: the flying player and balloon rise faster. */
void bonus_1_speed_up(uint16_t object, uint16_t *p_flyer, uint16_t *p_z_speed, uint32_t *p_carry)
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
	*p_flyer = flyer;
	*p_z_speed = z_speed;
	*p_carry = carry;
}

/* Bonus 1: the flying player and balloon rise faster; an absent player's balloon pops on the way up, and
   one past the top is gone. */
void bonus_1_rise(uint16_t object, uint16_t *p_flyer, uint16_t *p_height, uint32_t *p_carry)
{
	uint32_t carry = *p_carry;
	uint16_t flyer = 0, height = 0;
	uint8_t in_game = 0, t1 = 0;
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
		t1 = io_read8(0x18ECu);
		io_write8(0x18ECu, t1 + 1u);
	}
	*p_flyer = flyer;
	*p_height = height;
	*p_carry = carry;
}

/* Bonus 1: runs a popped balloon by its step (field 44); never seen in the scenarios. */
void bonus_1_popped(uint16_t *p_object, uint16_t *p_y, uint16_t *p_d, uint32_t *p_carry)
{
	uint16_t object = (uint16_t)*p_object;
	uint16_t y = (uint16_t)*p_y;
	uint8_t d = (uint8_t)*p_d;
	uint32_t carry = *p_carry;
	uint8_t a = 0, animation_done = 0;
	uint16_t d_2 = 0;
	uint8_t flight_step = 0, t1 = 0, t2 = 0;

	flight_step = OBJECT(object)->bonus_1.flight_step;
	a = flight_step;
	carry = (int8_t)a < 0;
	a = (uint32_t)a << 1;
	d_2 = (d & 0xFFu) | ((uint32_t)a << 8);
	switch ((int8_t)a)
	{
	case 0:
		bonus_1_pop(object, &d_2, &carry);
		break;
	case 2:
		bonus_1_fall(object, &d_2, &carry);
		break;
	case 4:
		bonus_1_lie(object);
		break;
	case 6:
		bonus_1_fall_done();
		break;
	case 8:
		bonus_pan_start(y, &d_2, &carry);
		break;
	case 10:
		bonus_pan_up(&object, &d_2, &carry);
		break;
	case 12:
	case 16:
		carry = bonus_hide_hints();
		break;
	case 14:
		bonus_show_hints_1(object, &y, &d_2, &carry);
		break;
	case 18:
		bonus_show_hints_2(object, &y, &d_2, &carry);
		break;
	case 20:
		d_2 = bonus_title_wait();
		break;
	case 22:
		bonus_title_show(&object, &y, &d_2, &carry);
		break;
	case 24:
		bonus_title_done();
		break;
	case -42:
		bonus_1_intro_pan(&object, &y, &d_2, &carry);
		break;
	case -40:
		bonus_1_intro_set_up(&object, &y, &d_2, &carry);
		break;
	case -38:
		bonus_1_intro_show_how(&object, &y, &d_2, &carry);
		break;
	case -36:
		bonus_1_contest_start(&object, &y, &d_2, &carry);
		break;
	case -34:
		bonus_1_contest_play(&object, &y, &d_2, &carry);
		break;
	case -32:
		bonus_1_finish(&object, &y, &d_2, &carry);
		break;
	case -30:
		bonus_1_contest_set_up(&object, &y, &d_2, &carry);
		break;
	case -28:
		bonus_1_contest_ready(&object, &y, &d_2, &carry);
		break;
	case -26:
		bonus_1_start_music(&d_2, &carry);
		break;
	case -24:
		bonus_1_blow_until_done(&object, &y, &d_2, &carry);
		break;
	case -22:
		bonus_1_finish_music(&d_2, &carry);
		break;
	case -20:
		bonus_1_results(&object, &y, &d_2, &carry);
		break;
	case -18:
		bonus_1_top_up_balloons(&object, &y, &d_2, &carry);
		break;
	case -16:
		bonus_1_fly_away(&object, &y, &d_2, &carry);
		break;
	case -14:
		bonus_1_end(&d_2, &carry);
		break;
	case -12:
		bonus_1_fly(&object, &y, &d_2, &carry);
		break;
	case -10:
		bonus_1_popped(&object, &y, &d_2, &carry);
		break;
	case -8:
		bonus_1_take_off(object, &y, &d_2);
		break;
	case -6:
		bonus_1_lift_off(object, &y, &d_2);
		break;
	case -4:
		bonus_1_speed_up(object, &y, &d_2, &carry);
		break;
	case -2:
		bonus_1_rise(object, &y, &d_2, &carry);
		break;
	}
	t1 = mem_read8(object + 6u);
	t2 = t1 & 1u;
	animation_done = t2;
	if (t2 != 0u)
	{
		carry = 0u;
		mem_write8(object, 0u);
	}
	d_2 = (d_2 & 0xFFu) | ((uint32_t)animation_done << 8);
	*p_object = object;
	*p_y = y;
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
	carry = vector_queue_sound(command);
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
void bonus_1_fall(uint16_t object, uint16_t *p_d, uint32_t *p_carry)
{
	uint32_t carry = *p_carry;
	uint8_t lie_time = 0;
	uint16_t balloon = 0, d = 0;
	uint16_t stack = 0;
	uint8_t flight_step = 0;
	uint16_t flyer = 0, flyer_2 = 0;

	flyer = OBJECT(object)->bonus_1.flyer;
	stack = object;
	object = flyer;
	vector_apply_gravity(object, &d, &carry);
	lie_time = (uint8_t)(d >> 8);
	balloon = stack;
	if (carry)
	{
		flyer_2 = OBJECT(balloon)->bonus_1.flyer;
		mem_write8(flyer_2 + 5u, 0x8Eu);
		lie_time = 0x60u;
		OBJECT(balloon)->bonus_1.lie_time = 0x60u;
		flight_step = OBJECT(balloon)->bonus_1.flight_step;
		OBJECT(balloon)->bonus_1.flight_step = flight_step + 1u;
	}
	d = (d & 0xFFu) | ((uint32_t)lie_time << 8);
	*p_d = d;
	*p_carry = carry;
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
	uint8_t t1 = 0;

	t1 = io_read8(0x18ECu);
	io_write8(0x18ECu, t1 + 1u);
}

/* Bonus 1: whether a player's balloon has grown past its limit (carry). */
void bonus_1_any_balloon_full(uint16_t *p_object, uint32_t *p_carry)
{
	uint32_t carry = *p_carry;
	uint16_t object = 0;
	uint8_t stack = 0;
	uint8_t t1 = 0;
	uint16_t parameter = 0;

	object = OBJECT_ADDRESS(0);
	stack = 4u;
	for (;;)
	{
		parameter = (((uint32_t)OBJECT(object)->parameter << 8u) | OBJECT(object)->blocked);
		if (parameter >= 0x1A0u)
		{
			carry = 1u;
			break;
		}
		object += 0xC0u;
		t1 = stack;
		stack = t1 - 1u;
		if (t1 == 1u)
		{
			carry = 0u;
			break;
		}
	}
	*p_object = object;
	*p_carry = carry;
}

/* The bonuses' timer: counts a frame down (carry when the time is up). */
uint32_t bonus_timer_tick(void)
{
	uint32_t carry = 0, half_carry = 0;
	uint8_t frames = 0, seconds = 0;
	uint8_t t1 = 0, t2 = 0;

	t1 = bonus_frames;
	frames = t1;
	if (t1 == 0u)
	{
		bonus_frames = frames;
		t2 = bonus_seconds;
		seconds = t2;
		if (t2 == 0u)
		{
			bonus_draw_x = 0xE0u;
			bonus_draw_y = 0xB8u;
			bonus_draw_timer();
			carry = 1u;
			return carry;
		}
		half_carry = ((uint8_t)(seconds ^ 0x99u ^ (seconds - 0x67u)) >> 4) & 1u;
		carry = (uint8_t)(seconds - 0x67u) < seconds;
		bonus_seconds = konami_daa((uint8_t)(seconds - 0x67u), half_carry, carry);
		bonus_frames = 0x98u;
		carry = 0u;
		return carry;
	}
	half_carry = ((uint8_t)(frames ^ 0x99u ^ (frames - 0x67u)) >> 4) & 1u;
	carry = (uint8_t)(frames - 0x67u) < frames;
	frames = konami_daa((uint8_t)(frames - 0x67u), half_carry, carry);
	if (frames == 0u)
	{
		bonus_frames = frames;
		t2 = bonus_seconds;
		seconds = t2;
		if (t2 == 0u)
		{
			bonus_draw_x = 0xE0u;
			bonus_draw_y = 0xB8u;
			bonus_draw_timer();
			carry = 1u;
			return carry;
		}
		half_carry = ((uint8_t)(seconds ^ 0x99u ^ (seconds - 0x67u)) >> 4) & 1u;
		carry = (uint8_t)(seconds - 0x67u) < seconds;
		bonus_seconds = konami_daa((uint8_t)(seconds - 0x67u), half_carry, carry);
		bonus_frames = 0x98u;
		carry = 0u;
		return carry;
	}
	half_carry = ((uint8_t)(frames ^ 0x99u ^ (frames - 0x67u)) >> 4) & 1u;
	carry = (uint8_t)(frames - 0x67u) < frames;
	frames = konami_daa((uint8_t)(frames - 0x67u), half_carry, carry);
	if (frames != 0u)
	{
		bonus_frames = frames;
		carry = 0u;
		return carry;
	}
	bonus_frames = frames;
	t2 = bonus_seconds;
	seconds = t2;
	if (t2 == 0u)
	{
		bonus_draw_x = 0xE0u;
		bonus_draw_y = 0xB8u;
		bonus_draw_timer();
		carry = 1u;
		return carry;
	}
	half_carry = ((uint8_t)(seconds ^ 0x99u ^ (seconds - 0x67u)) >> 4) & 1u;
	carry = (uint8_t)(seconds - 0x67u) < seconds;
	bonus_seconds = konami_daa((uint8_t)(seconds - 0x67u), half_carry, carry);
	bonus_frames = 0x98u;
	carry = 0u;
	return carry;
}

/* Does nothing: the bonuses' timer is not drawn (the drawing after it, unused_bonus_draw_timer_digits,
   nothing calls). */
void bonus_draw_timer(void)
{
}

/* Unused: would draw the bonus timer's 4 digits as sprites (kind 0E, animations B0-B9). */
void unused_bonus_draw_timer_digits(void)
{
	uint8_t a = 0, d = 0;
	uint16_t object = 0;
	uint8_t stack = 0;
	uint8_t t6 = 0, t7 = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0;

	object = OBJECT_ADDRESS(9);
	stack = 4u;
	do
	{
		OBJECT(object)->flags = 0x80u;
		OBJECT(object)->kind = 0xEu;
		t1 = bonus_draw_x;
		d = (uint8_t)t1;
		a = (uint8_t)(t1 >> 8);
		OBJECT(object)->x = ((uint32_t)a << 8) | (d & 0xFFu);
		t2 = (((uint32_t)a << 8) | (d & 0xFFu)) + 0x10u;
		bonus_draw_x = t2;
		OBJECT(object)->y = 0xA0u;
		t3 = bonus_draw_y;
		OBJECT(object)->z = t3;
		if (stack == 3u)
		{
			t4 = bonus_draw_x;
			t5 = t4 + 8u;
			bonus_draw_x = t5;
		}
		object += 0x60u;
		t6 = stack;
		stack = t6 - 1u;
	} while (t6 != 1u);
	object = OBJECT_ADDRESS(9);
	t7 = (((bonus_seconds >> 1) >> 1) >> 1) >> 1;
	a = t7;
	if (t7 == 0u)
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
	uint16_t t1 = 0, t2 = 0;

	OBJECT(OBJECT_ADDRESS(8))->flags = 0x80u;
	OBJECT(OBJECT_ADDRESS(8))->kind = 0xEu;
	OBJECT(OBJECT_ADDRESS(8))->animation = 0x8Fu;
	t1 = bonus_draw_x;
	OBJECT(OBJECT_ADDRESS(8))->x = t1;
	OBJECT(OBJECT_ADDRESS(8))->y = 0xA0u;
	t2 = bonus_draw_y;
	OBJECT(OBJECT_ADDRESS(8))->z = t2;
}

/* Bonus 1: puts each player's balloon and its three parts (the character blowing, the part between and
   the one that flies with it), the absent players' in their own look. */
void bonus_1_put_players(uint16_t *p_player_object, uint16_t *p_y, uint16_t *p_d, uint32_t *p_carry)
{
	uint32_t carry = *p_carry;
	uint8_t part_field = 0, player_number = 0, zoom_x = 0, zoom_y = 0;
	uint16_t balloon = 0, d = 0, default_object = 0, object = 0, player_object = 0, record_number = 0, y = 0;
	uint8_t stack = 0, stack_2 = 0;
	uint8_t in_game = 0, in_game_2 = 0, in_game_3 = 0, t1 = 0;
	uint16_t hit_from_behind = 0;

	balloon = OBJECT_ADDRESS(0);
	player_number = 0u;
	do
	{
		stack = player_number;
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
		player_number = stack + 1u;
	} while (player_number != 4u);
	player_object = OBJECT_ADDRESS(0);
	balloon_player_number = 0u;
	do
	{
		balloon_part = 0u;
		do
		{
			record_number = (uint32_t)(uint8_t)((((uint32_t)balloon_part << 1) << 1) + balloon_player_number + 4u) << 8;
			bonus_put_placement(player_object, &y, &record_number, &carry);
			t1 = OBJECT(player_object)->unk_3E;
			if (t1 == 0u)
			{
				stack_2 = player_object >> 8;
				stack = (uint8_t)player_object;
				default_object = y;
				record_number = (uint32_t)(uint8_t)(0x11u + balloon_part) << 8;
				bonus_put_placement(default_object, &y, &record_number, &carry);
				player_object = ((uint32_t)stack_2 << 8) | stack;
			}
			part_field = ((uint32_t)balloon_part << 1) + 0x33u;
			mem_write16(player_object + (int8_t)part_field, y);
			balloon_part++;
		} while (balloon_part != 3u);
		hit_from_behind = (((uint32_t)OBJECT(player_object)->hit_from_behind << 8u) | OBJECT(player_object)->unk_34);
		mem_write8(hit_from_behind, 0u);
		player_object += 0xC0u;
		balloon_player_number++;
		player_number = balloon_player_number;
		carry = player_number < 4u;
	} while (player_number != 4u);
	d = ((uint32_t)player_number << 8) | part_field;
	*p_player_object = player_object;
	*p_y = y;
	*p_d = d;
	*p_carry = carry;
}

/* The bonuses: puts the given record of bonus_placements (its object, or the caller's where it says
   FFFF; its kind, animation, x and height, FFFF keeping the old one) and hands back the object. */
void bonus_put_placement(uint16_t default_object, uint16_t *p_placed, uint16_t *p_record_number, uint32_t *p_carry)
{
	uint16_t record_number = (uint16_t)*p_record_number;
	uint32_t carry = *p_carry;
	uint8_t a = 0, b = 0;
	uint16_t placed = 0, placement = 0, u = 0;
	uint16_t t1 = 0, t2 = 0, kind = 0, t3 = 0, t4 = 0, z = 0, t5 = 0;
	uint32_t kind_halfword = 0;

	t1 = bonus_placements[(int8_t)((uint8_t)((uint32_t)(record_number >> 8) << 1)) / 2];
	u = t1 + 2u;
	placed = PLACEMENT(t1)->object;
	if (placed == 0xFFFFu)
		placed = default_object;
	OBJECT(placed)->flags |= 0x80u;
	t2 = u;
	kind = PLACEMENT(t2 - 0x2u)->kind;
	kind_halfword = ((uint32_t)(kind >> 8) << 8) | (uint8_t)(kind | 0x80u);
	OBJECT(placed)->kind = (uint8_t)(kind_halfword >> 8u);
	OBJECT(placed)->animation = (uint8_t)kind_halfword;
	t3 = t2 + 2u;
	placement = t3 + 2u;
	t4 = PLACEMENT(t3 - 0x4u)->x;
	a = (uint8_t)(t4 >> 8);
	b = (uint8_t)t4;
	if ((uint16_t)(((uint32_t)a << 8) | b) != 0xFFFFu)
		OBJECT(placed)->x = ((uint32_t)a << 8) | b;
	OBJECT(placed)->y = 0xB0u;
	z = PLACEMENT(placement - 0x6u)->z;
	a = (uint8_t)(z >> 8);
	b = (uint8_t)z;
	t5 = ((uint32_t)a << 8) | b;
	carry = t5 < 0xFFFFu;
	if (t5 != 0xFFFFu)
		OBJECT(placed)->z = ((uint32_t)a << 8) | b;
	record_number = ((uint32_t)a << 8) | b;
	*p_placed = placed;
	*p_record_number = record_number;
	*p_carry = carry;
}

/* Bonus 1: copies each player in the game's newly pressed controls into its bonus record. */
void bonus_1_take_presses(void)
{
	uint16_t balloon = 0, bonus_player = 0;
	uint8_t stack = 0;
	uint8_t in_game = 0;
	uint16_t controls_pressed = 0;

	balloon = OBJECT_ADDRESS(0);
	stack = 0u;
	do
	{
		in_game = OBJECT(balloon)->bonus_1.in_game;
		if (in_game != 0u)
		{
			bonus_player = bonus_1_player_records[(int8_t)((uint8_t)((uint32_t)stack << 1)) / 2];
			controls_pressed = BONUS_PLAYER(bonus_player)->controls_pressed;
			mem_write8(BONUS_PLAYER(bonus_player)->presses, mem_read8(controls_pressed));
		}
		balloon += 0xC0u;
		stack = stack + 1u;
	} while (stack != 4u);
}

/* Bonus 1: gives each absent player a press rate (frames between presses) for its balloon to blow by
   itself. */
void bonus_1_set_absent_rates(void)
{
	uint16_t player_object = 0;
	uint8_t stack = 0, stack_2 = 0;
	uint8_t t1 = 0, enemy_class = 0;
	uint16_t object = 0;

	absent_player_seen = 0u;
	stack = 0u;
	stack_2 = random_number & 3u;
	do
	{
		object = BONUS_PLAYER(bonus_1_player_records[stack_2 & 0x7Fu])->object;
		player_object = object;
		t1 = OBJECT(player_object)->unk_3E;
		if (t1 == 0u)
		{
			if (absent_player_seen == 0u)
			{
				absent_player_seen++;
				OBJECT(player_object)->enemy_class = 0;
			}
			else
				OBJECT(player_object)->enemy_class = stack + stack_2;
		}
		enemy_class = OBJECT(player_object)->enemy_class;
		OBJECT(player_object)->enemy_class = enemy_class + 5u;
		stack_2 = (stack_2 + 1u) & 3u;
		stack = stack + 1u;
	} while (stack != 4u);
}

/* Bonus 1: the absent players press by themselves, one press each so many frames. */
void bonus_1_absent_presses(void)
{
	uint16_t balloon = 0, bonus_player = 0;
	uint8_t stack = 0;
	uint8_t in_game = 0, press_wait = 0, press_wait_2 = 0, press_rate = 0;

	balloon = OBJECT_ADDRESS(0);
	stack = 0u;
	do
	{
		in_game = OBJECT(balloon)->bonus_1.in_game;
		if (in_game == 0u)
		{
			bonus_player = bonus_1_player_records[(int8_t)((uint8_t)((uint32_t)stack << 1)) / 2];
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
		stack = stack + 1u;
	} while (stack != 4u);
}

/* Bonus 1: plays the press sound (2900) when a player in the game presses, at most once each 32 frames. */
void bonus_1_press_sound(uint16_t *p_player_records_place, uint16_t *p_d, uint32_t *p_carry)
{
	uint32_t carry = *p_carry;
	uint8_t player_number = 0, presses = 0;
	uint16_t command = 0, d = 0, player_records_place = 0, record = 0;
	uint8_t stack = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0;

	t1 = io_read8(0x18EDu);
	if ((int8_t)t1 >= 0)
	{
		t2 = io_read8(0x18EDu);
		io_write8(0x18EDu, t2 + 1u);
	}
	presses = 0u;
	stack = 0u;
	player_records_place = bonus_1_player_records_ADDRESS;
	do
	{
		record = mem_read16(player_records_place);
		t3 = mem_read8(player_records_place + 0x3Eu);
		if (t3 != 0u)
			presses |= mem_read8(mem_read16(record));
		player_records_place += 2u;
		stack = stack + 1u;
		player_number = stack;
		carry = player_number < 4u;
	} while (player_number != 4u);
	t4 = presses & 0x3Fu;
	presses = t4;
	if (t4 != 0u)
	{
		t5 = io_read8(0x18EDu);
		presses = t5;
		carry = presses < 0x20u;
		if (presses > 0x20u)
		{
			t6 = io_read8(0x18EDu);
			io_write8(0x18EDu, 0u);
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
	uint8_t in_game = 0, t1 = 0;

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
		t1 = players_left;
		players_left = t1 - 1u;
	} while (t1 != 1u);
}

/* Bonus 1: has the 4 players' objects drawn zoomed (by their balloon's size). */
uint16_t bonus_1_zoom_players(void)
{
	uint8_t flags = 0, players_left = 0;
	uint16_t d = 0, object = 0;
	uint8_t t1 = 0;

	object = OBJECT_ADDRESS(0);
	players_left = 4u;
	do
	{
		flags = OBJECT(object)->flags | 0x10u;
		OBJECT(object)->flags = flags;
		object += 0xC0u;
		t1 = players_left;
		players_left = t1 - 1u;
	} while (t1 != 1u);
	d = ((uint32_t)flags << 8) | players_left;
	return d;
}

/* The bonuses' introduction: runs the camera's pan by its step; carry when it is over. */
void bonus_pan(uint16_t *p_x, uint16_t *p_y, uint16_t *p_d, uint32_t *p_carry)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t d = (uint16_t)*p_d;
	uint32_t carry = *p_carry;
	uint8_t a = 0;
	uint16_t x = 0;

	x = bonus_pan_steps_ADDRESS;
	a = step_subphase;
	carry = (int8_t)a < 0;
	a = (uint32_t)a << 1;
	switch ((int8_t)a)
	{
	case 0:
		bonus_pan_start(y, &d, &carry);
		break;
	case 2:
		bonus_pan_up(&x, &d, &carry);
		break;
	case 4:
	case 8:
		d = (d & 0xFFu) | ((uint32_t)a << 8);
		carry = bonus_hide_hints();
		break;
	case 6:
		bonus_show_hints_1(x, &y, &d, &carry);
		break;
	case 10:
		bonus_show_hints_2(x, &y, &d, &carry);
		break;
	case 12:
		d = bonus_title_wait();
		break;
	case 14:
		d = (d & 0xFFu) | ((uint32_t)a << 8);
		bonus_title_show(&x, &y, &d, &carry);
		break;
	case 16:
		d = (d & 0xFFu) | ((uint32_t)a << 8);
		bonus_title_done();
		break;
	case -50:
		bonus_1_intro_pan(&x, &y, &d, &carry);
		break;
	case -48:
		bonus_1_intro_set_up(&x, &y, &d, &carry);
		break;
	case -46:
		bonus_1_intro_show_how(&x, &y, &d, &carry);
		break;
	case -44:
		bonus_1_contest_start(&x, &y, &d, &carry);
		break;
	case -42:
		bonus_1_contest_play(&x, &y, &d, &carry);
		break;
	case -40:
		bonus_1_finish(&x, &y, &d, &carry);
		break;
	case -38:
		bonus_1_contest_set_up(&x, &y, &d, &carry);
		break;
	case -36:
		bonus_1_contest_ready(&x, &y, &d, &carry);
		break;
	case -34:
		bonus_1_start_music(&d, &carry);
		break;
	case -32:
		bonus_1_blow_until_done(&x, &y, &d, &carry);
		break;
	case -30:
		bonus_1_finish_music(&d, &carry);
		break;
	case -28:
		bonus_1_results(&x, &y, &d, &carry);
		break;
	case -26:
		bonus_1_top_up_balloons(&x, &y, &d, &carry);
		break;
	case -24:
		bonus_1_fly_away(&x, &y, &d, &carry);
		break;
	case -22:
		d = (d & 0xFFu) | ((uint32_t)a << 8);
		bonus_1_end(&d, &carry);
		break;
	case -20:
		bonus_1_fly(&x, &y, &d, &carry);
		break;
	case -18:
		bonus_1_popped(&x, &y, &d, &carry);
		break;
	case -16:
		bonus_1_take_off(x, &y, &d);
		break;
	case -14:
		bonus_1_lift_off(x, &y, &d);
		break;
	case -12:
		bonus_1_speed_up(x, &y, &d, &carry);
		break;
	case -10:
		bonus_1_rise(x, &y, &d, &carry);
		break;
	case -8:
		bonus_1_pop(x, &d, &carry);
		break;
	case -6:
		bonus_1_fall(x, &d, &carry);
		break;
	case -4:
		d = (d & 0xFFu) | ((uint32_t)a << 8);
		bonus_1_lie(x);
		break;
	case -2:
		d = (d & 0xFFu) | ((uint32_t)a << 8);
		bonus_1_fall_done();
		break;
	}
	*p_x = x;
	*p_y = y;
	*p_d = d;
	*p_carry = carry;
}

/* The bonuses' introduction: shows the title's object and starts the camera's pan. */
void bonus_pan_start(uint16_t object, uint16_t *p_d, uint32_t *p_carry)
{
	uint32_t carry = *p_carry;
	uint16_t d = 0;

	OBJECT(object)->flags = 0x80u;
	OBJECT(object)->y = 0x70u;
	OBJECT(object)->attributes = 0x20u;
	step_subphase++;
	carry = 0u;
	d = 0x70u;
	*p_d = d;
	*p_carry = carry;
}

/* The bonuses' introduction: pans the view up 3 a frame, the backdrop rising with it, until it has gone
   round (carry). */
void bonus_pan_up(uint16_t *p_backdrop, uint16_t *p_d, uint32_t *p_carry)
{
	uint32_t carry = *p_carry;
	uint8_t b = 0;
	uint16_t backdrop = 0, d = 0;
	uint16_t t1 = 0, t2 = 0;

	backdrop = OBJECT_ADDRESS(8);
	OBJECT(OBJECT_ADDRESS(8))->z_speed = 0x300;
	t1 = layer_a_scroll_y;
	t2 = t1;
	b = (uint8_t)(t2 + 3u);
	layer_a_scroll_y = ((uint32_t)((uint16_t)(t2 + 3u) >> 8) << 8) | b;
	if (t2 <= (uint16_t)(t2 + 3u))
	{
		carry = 0u;
		d = b;
	}
	else
	{
		backdrop = OBJECT_ADDRESS(8);
		layer_a_scroll_y = 0u;
		OBJECT(OBJECT_ADDRESS(8))->z_speed = 0;
		OBJECT(OBJECT_ADDRESS(8))->z = 0xCFu;
		OBJECT(OBJECT_ADDRESS(8))->animation_flags = 0x80u;
		step_subphase = 0u;
		carry = 1u;
		d = 0x7FCFu;
	}
	*p_backdrop = backdrop;
	*p_d = d;
	*p_carry = carry;
}

/* The bonuses' introduction: shows the press hints in turn, one pair after the other with a gap between. */
uint16_t bonus_blink_hints(uint16_t y)
{
	uint32_t carry = 0;
	uint8_t a = 0, b = 0;
	uint16_t d = 0, ignored16 = 0, ignored16_2 = 0, x = 0, y_2 = 0;
	uint16_t t1 = 0;

	t1 = ((uint8_t)frame_count & 0x60u) >> 5;
	a = (uint8_t)(t1 >> 8);
	x = bonus_hint_blink_steps_ADDRESS;
	b = (uint32_t)t1 << 1;
	switch ((int8_t)b)
	{
	case 0:
	case 4:
		carry = bonus_hide_hints();
		return y;
	case 2:
		bonus_show_hints_1(x, &y_2, &ignored16_2, &carry);
		return y_2;
	case 6:
		bonus_show_hints_2(x, &y_2, &ignored16_2, &carry);
		return y_2;
	case 8:
		bonus_title_wait();
		return y;
	case 10:
		d = (uint32_t)a << 8;
		bonus_title_show(&x, &y, &d, &carry);
		return y;
	case 12:
		bonus_title_done();
		return y;
	case -54:
		d = b;
		bonus_1_intro_pan(&ignored16, &y, &d, &carry);
		return y;
	case -52:
		bonus_1_intro_set_up(&ignored16, &y_2, &ignored16_2, &carry);
		return y_2;
	case -50:
		bonus_1_intro_show_how(&ignored16, &y, &ignored16_2, &carry);
		return y;
	case -48:
		d = b;
		bonus_1_contest_start(&ignored16, &y, &d, &carry);
		return y;
	case -46:
		bonus_1_contest_play(&ignored16, &y_2, &ignored16_2, &carry);
		return y_2;
	case -44:
		d = b;
		bonus_1_finish(&ignored16, &y, &d, &carry);
		return y;
	case -42:
		bonus_1_contest_set_up(&ignored16, &y_2, &ignored16_2, &carry);
		return y_2;
	case -40:
		bonus_1_contest_ready(&ignored16, &y_2, &ignored16_2, &carry);
		return y_2;
	case -38:
		bonus_1_start_music(&ignored16_2, &carry);
		return y;
	case -36:
		bonus_1_blow_until_done(&ignored16, &y, &ignored16_2, &carry);
		return y;
	case -34:
		bonus_1_finish_music(&ignored16_2, &carry);
		return y;
	case -32:
		bonus_1_results(&ignored16, &y, &ignored16_2, &carry);
		return y;
	case -30:
		bonus_1_top_up_balloons(&ignored16, &y, &ignored16_2, &carry);
		return y;
	case -28:
		d = b;
		bonus_1_fly_away(&ignored16, &y, &d, &carry);
		return y;
	case -26:
		d = ((uint32_t)a << 8) | b;
		bonus_1_end(&d, &carry);
		return y;
	case -24:
		d = b;
		bonus_1_fly(&x, &y, &d, &carry);
		return y;
	case -22:
		d = b;
		bonus_1_popped(&x, &y, &d, &carry);
		return y;
	case -20:
		bonus_1_take_off(x, &y_2, &ignored16_2);
		return y_2;
	case -18:
		bonus_1_lift_off(x, &y, &ignored16_2);
		return y;
	case -16:
		bonus_1_speed_up(x, &y_2, &ignored16_2, &carry);
		return y_2;
	case -14:
		bonus_1_rise(x, &y_2, &ignored16_2, &carry);
		return y_2;
	case -12:
		bonus_1_pop(x, &ignored16_2, &carry);
		return y;
	case -10:
		bonus_1_fall(x, &ignored16_2, &carry);
		return y;
	case -8:
		bonus_1_lie(x);
		return y;
	case -6:
		bonus_1_fall_done();
		return y;
	case -4:
		bonus_pan_start(y, &ignored16_2, &carry);
		return y;
	case -2:
		bonus_pan_up(&ignored16, &ignored16_2, &carry);
		return y;
	}
	unreachable();
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
void bonus_show_hints_1(uint16_t default_object, uint16_t *p_object, uint16_t *p_d, uint32_t *p_carry)
{
	uint32_t carry = *p_carry;
	uint16_t d = 0, object = 0, record_number = 0;

	record_number = 0x1500u;
	bonus_put_placement(default_object, &object, &record_number, &carry);
	OBJECT(object)->flags = 0x80u;
	d = 0x1600u;
	bonus_put_placement(default_object, &object, &d, &carry);
	OBJECT(object)->flags = 0x80u;
	OBJECT(object)->attributes = 0x20u;
	d = (d & 0xFFu) | 0x2000u;
	*p_object = object;
	*p_d = d;
	*p_carry = carry;
}

/* The bonuses' introduction: shows the second pair of press hints. */
void bonus_show_hints_2(uint16_t default_object, uint16_t *p_object, uint16_t *p_d, uint32_t *p_carry)
{
	uint32_t carry = *p_carry;
	uint16_t d = 0, object = 0, record_number = 0;

	record_number = 0x1700u;
	bonus_put_placement(default_object, &object, &record_number, &carry);
	OBJECT(object)->flags = 0x80u;
	d = 0x1800u;
	bonus_put_placement(default_object, &object, &d, &carry);
	OBJECT(object)->flags = 0x80u;
	OBJECT(object)->attributes = 0x20u;
	d = (d & 0xFFu) | 0x2000u;
	*p_object = object;
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
void bonus_title(uint16_t *p_y, uint16_t *p_d)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t d = (uint16_t)*p_d;
	uint32_t carry = 0;
	uint8_t b = 0;
	uint16_t ignored16 = 0, x = 0;
	uint8_t t1 = 0;

	x = bonus_title_steps_ADDRESS;
	t1 = io_read8(0x18F1u);
	b = (uint32_t)t1 << 1;
	switch ((int8_t)b)
	{
	case 0:
		d = bonus_title_wait();
		break;
	case 2:
		d |= b;
		bonus_title_show(&x, &y, &d, &carry);
		break;
	case 4:
		d |= b;
		bonus_title_done();
		break;
	case -62:
		d = b;
		bonus_1_intro_pan(&ignored16, &y, &d, &carry);
		break;
	case -60:
		bonus_1_intro_set_up(&ignored16, &y, &d, &carry);
		break;
	case -58:
		bonus_1_intro_show_how(&ignored16, &y, &d, &carry);
		break;
	case -56:
		d = b;
		bonus_1_contest_start(&ignored16, &y, &d, &carry);
		break;
	case -54:
		bonus_1_contest_play(&ignored16, &y, &d, &carry);
		break;
	case -52:
		d = b;
		bonus_1_finish(&ignored16, &y, &d, &carry);
		break;
	case -50:
		bonus_1_contest_set_up(&ignored16, &y, &d, &carry);
		break;
	case -48:
		bonus_1_contest_ready(&ignored16, &y, &d, &carry);
		break;
	case -46:
		bonus_1_start_music(&d, &carry);
		break;
	case -44:
		bonus_1_blow_until_done(&ignored16, &y, &d, &carry);
		break;
	case -42:
		bonus_1_finish_music(&d, &carry);
		break;
	case -40:
		d = b;
		bonus_1_results(&ignored16, &y, &d, &carry);
		break;
	case -38:
		bonus_1_top_up_balloons(&ignored16, &y, &d, &carry);
		break;
	case -36:
		d = b;
		bonus_1_fly_away(&ignored16, &y, &d, &carry);
		break;
	case -34:
		d |= b;
		bonus_1_end(&d, &carry);
		break;
	case -32:
		d = b;
		bonus_1_fly(&x, &y, &d, &carry);
		break;
	case -30:
		d = b;
		bonus_1_popped(&x, &y, &d, &carry);
		break;
	case -28:
		bonus_1_take_off(x, &y, &d);
		break;
	case -26:
		bonus_1_lift_off(x, &y, &d);
		break;
	case -24:
		bonus_1_speed_up(x, &y, &d, &carry);
		break;
	case -22:
		bonus_1_rise(x, &y, &d, &carry);
		break;
	case -20:
		bonus_1_pop(x, &d, &carry);
		break;
	case -18:
		bonus_1_fall(x, &d, &carry);
		break;
	case -16:
		d |= b;
		bonus_1_lie(x);
		break;
	case -14:
		d |= b;
		bonus_1_fall_done();
		break;
	case -12:
		bonus_pan_start(y, &d, &carry);
		break;
	case -10:
		bonus_pan_up(&ignored16, &d, &carry);
		break;
	case -8:
	case -4:
		d |= b;
		carry = bonus_hide_hints();
		break;
	case -6:
		bonus_show_hints_1(x, &y, &d, &carry);
		break;
	case -2:
		bonus_show_hints_2(x, &y, &d, &carry);
		break;
	}
	*p_y = y;
	*p_d = d;
}

/* The bonuses' introduction: waits 192 frames before the title. */
uint16_t bonus_title_wait(void)
{
	uint16_t d = 0;
	uint8_t t1 = 0;

	d = 0xC0u;
	io_write16(0x18EFu, 0xC0u);
	t1 = io_read8(0x18F1u);
	io_write8(0x18F1u, t1 + 1u);
	return d;
}

/* The bonuses' introduction: puts the given bonus' title and plays its voice. */
void bonus_title_show(uint16_t *p_x, uint16_t *p_object, uint16_t *p_d, uint32_t *p_carry)
{
	uint16_t x = (uint16_t)*p_x;
	uint16_t object = (uint16_t)*p_object;
	uint16_t d = (uint16_t)*p_d;
	uint32_t carry = *p_carry;
	uint8_t a = 0;
	uint16_t d_2 = 0, record_number = 0;
	uint8_t stack = 0;
	uint8_t t3 = 0;
	uint16_t t1 = 0, t2 = 0;

	a = (uint8_t)(d >> 8);
	t1 = io_read16(0x18EFu);
	carry = t1 == 0u;
	io_write16(0x18EFu, t1 - 1u);
	if (t1 == 1u)
	{
		stack = a;
		record_number = (uint32_t)(uint8_t)(a + 0x1Au) << 8;
		bonus_put_placement(x, &object, &record_number, &carry);
		OBJECT(object)->flags = 0x80u;
		x = bonus_intro_sounds_ADDRESS;
		t2 = bonus_intro_sounds[(int8_t)((uint8_t)((uint32_t)stack << 1)) / 2];
		d = t2;
		a = (uint8_t)(t2 >> 8);
		carry = vector_queue_sound(d);
		t3 = io_read8(0x18F1u);
		io_write8(0x18F1u, t3 + 1u);
	}
	d_2 = (d & 0xFFu) | ((uint32_t)a << 8);
	*p_x = x;
	*p_object = object;
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
	uint8_t stack = 0, stack_6 = 0;
	uint8_t look_2 = 0, place_2 = 0, no_points = 0, t1 = 0;

	stack = d >> 8;
	box = OBJECT_ADDRESS(14);
	health_address = 0x49D2u;
	stack_6 = 4u;
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
		t1 = stack_6;
		stack_6 = t1 - 1u;
	} while (t1 != 1u);
	d_2 = (uint32_t)stack << 8;
	*p_d = (*p_d & 0xFFu) | d_2;
	*p_carry = carry;
}
