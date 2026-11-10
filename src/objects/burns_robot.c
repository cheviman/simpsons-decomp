/**
 *    Name:        objects/burns_robot.c
 *    Description: Mr. Burns' robot (4F80 type EC, kinds CC-D4): its entrance, its forms and attacks, how each form breaks
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    09-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the game's 053248 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

/* Mr. Burns' robot (type EC): counts its timers up, takes the players' blows, runs its handler by its
   handler number (field 02), and while it walks turns round at walls. */
uint16_t burns_robot_run(uint16_t robot, uint16_t y)
{
	uint32_t negative = 0;
	uint8_t a = 0, cell = 0, d = 0;
	uint16_t floor_cell = 0, handlers = 0;
	uint8_t state = 0, state_2 = 0, state_3 = 0, walk_direction = 0, walk_direction_2 = 0, walk_direction_3 = 0;
	uint16_t lob_frames = 0, t1 = 0, volley_frames = 0, t2 = 0, part_frames = 0, t3 = 0, x_speed = 0, t4 = 0, t5 = 0, t6 = 0, y_speed = 0;

	lob_frames = OBJECT(robot)->burns_robot.lob_frames;
	t1 = lob_frames + 1u;
	OBJECT(robot)->burns_robot.lob_frames = t1;
	volley_frames = OBJECT(robot)->burns_robot.volley_frames;
	t2 = volley_frames + 1u;
	OBJECT(robot)->burns_robot.volley_frames = t2;
	part_frames = OBJECT(robot)->burns_robot.part_frames;
	t3 = part_frames + 1u;
	OBJECT(robot)->burns_robot.part_frames = t3;
	state = OBJECT(robot)->state;
	if (state != 0xF9u)
		burns_robot_check_hit(robot);
	handlers = burns_robot_states_ADDRESS;
	state_2 = OBJECT(robot)->state;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		y = burns_robot_entrance(robot, y);
		break;
	case 2:
		y = burns_robot_walk_form_0(robot, y);
		break;
	case 4:
		y = burns_robot_walk_form_1(robot, y);
		break;
	case 6:
	case 8:
	case 10:
		y = burns_robot_walk_late_forms(robot, y);
		break;
	case 12:
	case 14:
	case 16:
		y = burns_robot_swing(robot, y);
		break;
	case 18:
		y = burns_robot_volley(robot, y);
		break;
	case 20:
		y = burns_robot_lunge(robot, y);
		break;
	case 22:
		y = burns_robot_part_attack(robot);
		break;
	case 24:
		y = burns_robot_lob_bombs(robot, y);
		break;
	case 26:
		y = burns_robot_gloat(robot, y);
		break;
	case 28:
		burns_robot_drop_maggie(robot);
		break;
	case 30:
		y = burns_robot_walk_to_maggie(robot, y);
		break;
	case 32:
		burns_robot_stop_at_maggie(robot);
		break;
	case 34:
		y = burns_robot_let_burns_out(robot, y);
		break;
	case 36:
		burns_robot_leave(robot);
		break;
	case 38:
	case 42:
		burns_robot_start_breaking(robot);
		break;
	case 40:
		y = burns_robot_shed_form_3(robot, y);
		break;
	case 44:
		y = burns_robot_shed_form_2(robot, y);
		break;
	case 46:
	case 60:
		burns_robot_broken_shake(robot);
		break;
	case 48:
	case 62:
		burns_robot_broken_cry(robot);
		break;
	case 50:
		y = burns_robot_shed_form_1(robot, y);
		break;
	case 52:
	case 66:
		burns_robot_fall_down(robot);
		break;
	case 54:
	case 68:
		burns_robot_lie_broken(robot);
		break;
	case 56:
	case 70:
		burns_robot_rise_as_next_form(robot);
		break;
	case 58:
	case 72:
		y = burns_robot_start_form(robot, y);
		break;
	case 64:
		y = burns_robot_shed_form_0(robot, y);
		break;
	case 74:
		y = burns_robot_hurt_flash(robot, y, handlers);
		break;
	case 76:
		y = burns_robot_hurt_end(robot, y);
		break;
	case 78:
		burns_robot_place(robot);
		break;
	case 80:
		burns_robot_wait_for_story(robot);
		break;
	case 82:
		burns_robot_appear(robot);
		break;
	case 84:
		burns_robot_step_up(robot);
		break;
	case 86:
		burns_robot_speak(robot);
		break;
	case 88:
		y = burns_robot_toss_part(robot, y);
		break;
	case 90:
		burns_robot_start_fight(robot);
		break;
	case 92:
		burns_robot_ready(robot);
		break;
	case 94:
	case 100:
		burns_robot_stop_and_wind_up(robot);
		break;
	case 96:
	case 116:
		burns_robot_swing_hit(robot);
		break;
	case 98:
	case 118:
		y = burns_robot_walk_on(robot, y);
		break;
	case 102:
		y = burns_robot_fire_shot(robot, y);
		break;
	case 104:
		burns_robot_volley_next(robot);
		break;
	case 106:
		y = burns_robot_volley_end(robot, y);
		break;
	case -12:
		y = burns_robot_final_defeat(robot, y);
		break;
	case -10:
		y = burns_robot_form_3_broken(robot, y);
		break;
	case -8:
		y = burns_robot_form_2_broken(robot, y);
		break;
	case -6:
		y = burns_robot_form_1_broken(robot, y);
		break;
	case -4:
		y = burns_robot_form_0_broken(robot, y);
		break;
	case -2:
		y = burns_robot_hurt(robot, y);
		break;
	}
	state_3 = OBJECT(robot)->state;
	if (state_3 == 0u)
		return y;
	x_speed = OBJECT(robot)->x_speed;
	d = (uint8_t)x_speed;
	a = (uint8_t)(x_speed >> 8);
	if ((int16_t)x_speed < 0)
	{
		t4 = (((uint32_t)a << 8) | (d & 0xFFu)) - 0x20u;
		d = (uint8_t)t4;
		a = (uint8_t)(t4 >> 8);
	}
	else
	{
		t5 = (((uint32_t)a << 8) | (d & 0xFFu)) + 0x20u;
		d = (uint8_t)t5;
		a = (uint8_t)(t5 >> 8);
	}
	floor_probe_dx = ((uint32_t)a << 8) | (d & 0xFFu);
	wall_probe_dx = ((uint32_t)a << 8) | (d & 0xFFu);
	floor_probe_dy = 0;
	floor_cell = floor_at_scratch_offset(robot);
	cell = (uint8_t)(floor_cell >> 8);
	if ((int8_t)cell < 0)
	{
		walk_direction = OBJECT(robot)->burns_robot.walk_direction;
		OBJECT(robot)->burns_robot.walk_direction = 0x80u - walk_direction;
		burns_robot_stop(robot);
		return y;
	}
	vector_floor_ahead_y(robot, &floor_cell, &negative);
	cell = (uint8_t)(floor_cell >> 8);
	if ((int8_t)cell < 0)
	{
		walk_direction_2 = OBJECT(robot)->burns_robot.walk_direction;
		OBJECT(robot)->burns_robot.walk_direction = 0u - walk_direction_2;
		burns_robot_stop(robot);
		return y;
	}
	t6 = wall_probe_dx;
	floor_probe_dx = t6;
	y_speed = OBJECT(robot)->y_speed;
	floor_probe_dy = y_speed;
	floor_cell = floor_at_scratch_offset(robot);
	cell = (uint8_t)(floor_cell >> 8);
	if ((int8_t)cell >= 0)
		return y;
	walk_direction_3 = OBJECT(robot)->burns_robot.walk_direction;
	OBJECT(robot)->burns_robot.walk_direction = walk_direction_3 - 0x80u;
	burns_robot_stop(robot);
	return y;
}

/* Its last form broken: drops Maggie's object, walks to it, stops and lets Mr. Burns out, then is gone. */
uint16_t burns_robot_final_defeat(uint16_t robot, uint16_t y)
{
	uint16_t steps = 0;
	uint8_t step = 0;

	for (;;)
	{
		steps = burns_robot_final_defeat_actions_ADDRESS;
		step = OBJECT(robot)->burns_robot.step;
		switch ((int8_t)(uint8_t)((uint32_t)step << 1))
		{
		case 0:
			burns_robot_drop_maggie(robot);
			return y;
		case 2:
			return burns_robot_walk_to_maggie(robot, y);
		case 4:
			burns_robot_stop_at_maggie(robot);
			return y;
		case 6:
			return burns_robot_let_burns_out(robot, y);
		case 8:
			burns_robot_leave(robot);
			return y;
		case 10:
		case 14:
			burns_robot_start_breaking(robot);
			return y;
		case 12:
			return burns_robot_shed_form_3(robot, y);
		case 16:
			return burns_robot_shed_form_2(robot, y);
		case 18:
		case 32:
			burns_robot_broken_shake(robot);
			return y;
		case 20:
		case 34:
			burns_robot_broken_cry(robot);
			return y;
		case 22:
			return burns_robot_shed_form_1(robot, y);
		case 24:
		case 38:
			burns_robot_fall_down(robot);
			return y;
		case 26:
		case 40:
			burns_robot_lie_broken(robot);
			return y;
		case 28:
		case 42:
			burns_robot_rise_as_next_form(robot);
			return y;
		case 30:
		case 44:
			return burns_robot_start_form(robot, y);
		case 36:
			return burns_robot_shed_form_0(robot, y);
		case 46:
			return burns_robot_hurt_flash(robot, y, steps);
		case 48:
			return burns_robot_hurt_end(robot, y);
		case 50:
			burns_robot_place(robot);
			return y;
		case 52:
			burns_robot_wait_for_story(robot);
			return y;
		case 54:
			burns_robot_appear(robot);
			return y;
		case 56:
			burns_robot_step_up(robot);
			return y;
		case 58:
			burns_robot_speak(robot);
			return y;
		case 60:
			return burns_robot_toss_part(robot, y);
		case 62:
			burns_robot_start_fight(robot);
			return y;
		case 64:
			burns_robot_ready(robot);
			return y;
		case 66:
		case 72:
			burns_robot_stop_and_wind_up(robot);
			return y;
		case 68:
		case 88:
			burns_robot_swing_hit(robot);
			return y;
		case 70:
		case 90:
			return burns_robot_walk_on(robot, y);
		case 74:
			return burns_robot_fire_shot(robot, y);
		case 76:
			burns_robot_volley_next(robot);
			return y;
		case 78:
			break;
		case -40:
			continue;
		case -38:
			return burns_robot_form_3_broken(robot, y);
		case -36:
			return burns_robot_form_2_broken(robot, y);
		case -34:
			return burns_robot_form_1_broken(robot, y);
		case -32:
			return burns_robot_form_0_broken(robot, y);
		case -30:
			return burns_robot_hurt(robot, y);
		case -28:
			return burns_robot_entrance(robot, y);
		case -26:
			return burns_robot_walk_form_0(robot, y);
		case -24:
			return burns_robot_walk_form_1(robot, y);
		case -22:
		case -20:
		case -18:
			return burns_robot_walk_late_forms(robot, y);
		case -16:
		case -14:
		case -12:
			return burns_robot_swing(robot, y);
		case -10:
			return burns_robot_volley(robot, y);
		case -8:
			return burns_robot_lunge(robot, y);
		case -6:
			return burns_robot_part_attack(robot);
		case -4:
			return burns_robot_lob_bombs(robot, y);
		case -2:
			return burns_robot_gloat(robot, y);
		}
		break;
	}
	return burns_robot_volley_end(robot, y);
}

/* Puts in Maggie's object (5280 type E7) at the stage's x 420 and keeps it; walks 192 frames, then up to
   256 more until there. */
void burns_robot_drop_maggie(uint16_t robot)
{
	uint32_t carry = 0;
	uint8_t list = 0;
	uint16_t maggie = 0;
	uint8_t step = 0;
	uint16_t t1 = 0, t2 = 0;

	OBJECT(robot)->animation = 0x84u;
	list = 1u;
	vector_find_free_slot(list, &maggie, &carry);
	mem_write8(maggie + 1u, 0xE7u);
	t1 = 0x420u - camera_x;
	mem_write16(maggie + 0xCu, t1);
	t2 = 0xA8u + camera_y;
	mem_write16(maggie + 0x11u, t2);
	OBJECT(robot)->burns_robot.maggie = maggie;
	OBJECT(robot)->burns_robot.wait_frames = 0xC0u;
	OBJECT(robot)->burns_robot.walk_frames = 0x100u;
	step = OBJECT(robot)->burns_robot.step;
	OBJECT(robot)->burns_robot.step = step + 1u;
}

/* Walks to Maggie's object, staggering; once there (or out of time) sound 6E and the next step. */
uint16_t burns_robot_walk_to_maggie(uint16_t robot, uint16_t y)
{
	uint32_t carry = 0;
	uint16_t command = 0, direction = 0, distance = 0, object = 0, y_2 = 0;
	uint8_t wait_frames = 0, wait_frames_2 = 0, step = 0;
	uint16_t maggie = 0, walk_frames = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, x_speed = 0;

	maggie = OBJECT(robot)->burns_robot.maggie;
	object = maggie;
	wait_frames = OBJECT(robot)->burns_robot.wait_frames;
	if (wait_frames != 0u)
	{
		wait_frames_2 = OBJECT(robot)->burns_robot.wait_frames;
		OBJECT(robot)->burns_robot.wait_frames = wait_frames_2 - 1u;
	}
	else
	{
		walk_frames = OBJECT(robot)->burns_robot.walk_frames;
		OBJECT(robot)->burns_robot.walk_frames = walk_frames - 1u;
		if (walk_frames == 1u)
		{
			command = 0x6E00u;
			carry = vector_queue_sound(command);
			step = OBJECT(robot)->burns_robot.step;
			OBJECT(robot)->burns_robot.step = step + 1u;
			return y;
		}
		t1 = OBJECT(robot)->x;
		t2 = OBJECT(object)->x;
		distance = t1 - t2;
		if ((int16_t)(distance >> 15 ? 0u - distance : distance) <= 0x20)
		{
			t3 = OBJECT(robot)->y;
			t4 = OBJECT(object)->y;
			distance = t3 - t4;
			if ((int16_t)(distance >> 15 ? 0u - distance : distance) <= 0x20)
			{
				command = 0x6E00u;
				carry = vector_queue_sound(command);
				step = OBJECT(robot)->burns_robot.step;
				OBJECT(robot)->burns_robot.step = step + 1u;
				return y;
			}
		}
	}
	direction = vector_direction_to(robot, object);
	OBJECT(robot)->burns_robot.aim = direction >> 8;
	y_2 = burns_robot_steer(robot);
	stagger_speed = 0x300;
	if ((((uint16_t)((uint32_t)(uint8_t)frame_count << 8) >> 8) & 1u) != 0u)
		stagger_speed = 0u - stagger_speed;
	x_speed = OBJECT(robot)->x_speed;
	OBJECT(robot)->x_speed = x_speed + stagger_speed;
	return y_2;
}

/* Starts breaking down (sound 6E, its look) and stops. */
void burns_robot_stop_at_maggie(uint16_t robot)
{
	burns_robot_start_breaking(robot);
	burns_robot_stop(robot);
}

/* When its animation ends, Mr. Burns comes out of it (5280 type E2), he and Maggie's object linked; the
   robot shows kind D4. */
uint16_t burns_robot_let_burns_out(uint16_t robot, uint16_t object)
{
	uint32_t carry = 0;
	uint8_t list = 0;
	uint16_t behaviour = 0, part_code = 0;
	uint8_t animation_flags = 0, step = 0;
	uint16_t maggie = 0;

	animation_flags = OBJECT(robot)->animation_flags;
	if ((animation_flags & 1u) == 0u)
		return object;
	list = 1u;
	vector_find_free_slot(list, &behaviour, &carry);
	part_code = 0x701u;
	burns_robot_place_part(robot, behaviour, part_code);
	mem_write8(behaviour, 0x80u);
	maggie = OBJECT(robot)->burns_robot.maggie;
	object = maggie;
	OBJECT(object)->behaviour = behaviour;
	mem_write16(behaviour + 0x29u, object);
	OBJECT(robot)->kind = 0xD4u;
	OBJECT(robot)->animation = 0x89u;
	step = OBJECT(robot)->burns_robot.step;
	OBJECT(robot)->burns_robot.step = step + 1u;
	return object;
}

/* When its animation ends, gives its score and is gone. */
void burns_robot_leave(uint16_t robot)
{
	uint8_t animation_flags = 0, points = 0;

	animation_flags = OBJECT(robot)->animation_flags;
	if ((animation_flags & 1u) != 0u)
	{
		points = OBJECT(robot)->points;
		OBJECT(robot)->points = points | 0x81u;
		OBJECT(robot)->flags = 0u;
	}
}

/* Form 3 broken: slows, sheds its pieces and goes on as form 4. */
uint16_t burns_robot_form_3_broken(uint16_t robot, uint16_t y)
{
	uint16_t steps = 0;
	uint8_t step = 0;

	for (;;)
	{
		steps = burns_robot_form_3_broken_actions_ADDRESS;
		step = OBJECT(robot)->burns_robot.step;
		switch ((int8_t)(uint8_t)((uint32_t)step << 1))
		{
		case 0:
		case 4:
			burns_robot_start_breaking(robot);
			return y;
		case 2:
			return burns_robot_shed_form_3(robot, y);
		case 6:
			return burns_robot_shed_form_2(robot, y);
		case 8:
		case 22:
			burns_robot_broken_shake(robot);
			return y;
		case 10:
		case 24:
			burns_robot_broken_cry(robot);
			return y;
		case 12:
			return burns_robot_shed_form_1(robot, y);
		case 14:
		case 28:
			burns_robot_fall_down(robot);
			return y;
		case 16:
		case 30:
			burns_robot_lie_broken(robot);
			return y;
		case 18:
		case 32:
			burns_robot_rise_as_next_form(robot);
			return y;
		case 20:
		case 34:
			return burns_robot_start_form(robot, y);
		case 26:
			return burns_robot_shed_form_0(robot, y);
		case 36:
			return burns_robot_hurt_flash(robot, y, steps);
		case 38:
			return burns_robot_hurt_end(robot, y);
		case 40:
			burns_robot_place(robot);
			return y;
		case 42:
			burns_robot_wait_for_story(robot);
			return y;
		case 44:
			burns_robot_appear(robot);
			return y;
		case 46:
			burns_robot_step_up(robot);
			return y;
		case 48:
			burns_robot_speak(robot);
			return y;
		case 50:
			return burns_robot_toss_part(robot, y);
		case 52:
			burns_robot_start_fight(robot);
			return y;
		case 54:
			burns_robot_ready(robot);
			return y;
		case 56:
		case 62:
			burns_robot_stop_and_wind_up(robot);
			return y;
		case 58:
		case 78:
			burns_robot_swing_hit(robot);
			return y;
		case 60:
		case 80:
			return burns_robot_walk_on(robot, y);
		case 64:
			return burns_robot_fire_shot(robot, y);
		case 66:
			burns_robot_volley_next(robot);
			return y;
		case 68:
			break;
		case -50:
			return burns_robot_final_defeat(robot, y);
		case -48:
			continue;
		case -46:
			return burns_robot_form_2_broken(robot, y);
		case -44:
			return burns_robot_form_1_broken(robot, y);
		case -42:
			return burns_robot_form_0_broken(robot, y);
		case -40:
			return burns_robot_hurt(robot, y);
		case -38:
			return burns_robot_entrance(robot, y);
		case -36:
			return burns_robot_walk_form_0(robot, y);
		case -34:
			return burns_robot_walk_form_1(robot, y);
		case -32:
		case -30:
		case -28:
			return burns_robot_walk_late_forms(robot, y);
		case -26:
		case -24:
		case -22:
			return burns_robot_swing(robot, y);
		case -20:
			return burns_robot_volley(robot, y);
		case -18:
			return burns_robot_lunge(robot, y);
		case -16:
			return burns_robot_part_attack(robot);
		case -14:
			return burns_robot_lob_bombs(robot, y);
		case -12:
			return burns_robot_gloat(robot, y);
		case -10:
			burns_robot_drop_maggie(robot);
			return y;
		case -8:
			return burns_robot_walk_to_maggie(robot, y);
		case -6:
			burns_robot_stop_at_maggie(robot);
			return y;
		case -4:
			return burns_robot_let_burns_out(robot, y);
		case -2:
			burns_robot_leave(robot);
			return y;
		}
		break;
	}
	return burns_robot_volley_end(robot, y);
}

/* At its frame: the next music, pieces 3 and 4 fly off both ways, and it goes on as the next form with
   that form's health, walking at a target. */
uint16_t burns_robot_shed_form_3(uint16_t robot, uint16_t y)
{
	uint32_t carry = 0;
	uint8_t a = 0, health = 0;
	uint16_t d = 0, ignored16 = 0, piece = 0, piece_number = 0, u = 0, y_2 = 0;
	uint8_t animation_flags = 0, form_extra = 0, form_base = 0, form_extra_2 = 0;

	animation_flags = OBJECT(robot)->animation_flags;
	if ((animation_flags & 2u) == 0u)
		return y;
	boss_arrived++;
	piece_number = 0x300u;
	burns_robot_throw_piece(robot, &ignored16, &piece, &piece_number);
	OBJECT(piece)->x_speed = 0x100;
	piece_number = 0x8300u;
	burns_robot_throw_piece(robot, &ignored16, &piece, &piece_number);
	OBJECT(piece)->x_speed = -0x100;
	d = 0x400u;
	burns_robot_throw_piece(robot, &ignored16, &piece, &d);
	a = (uint8_t)(d >> 8);
	OBJECT(piece)->x = (uint32_t)a << 8;
	OBJECT(piece)->x_speed = 0x100;
	piece_number = 0x8400u;
	burns_robot_throw_piece(robot, &y_2, &piece, &piece_number);
	OBJECT(piece)->x_speed = -0x100;
	form_extra = OBJECT(robot)->burns_robot.form_extra;
	OBJECT(robot)->burns_robot.form_extra = form_extra + 1u;
	form_base = OBJECT(robot)->burns_robot.form_base;
	form_extra_2 = OBJECT(robot)->burns_robot.form_extra;
	health = burns_robot_healths[(int8_t)((uint8_t)(form_base + form_extra_2))];
	OBJECT(robot)->vitality = health;
	OBJECT(robot)->burns_robot.health_mark = health;
	burns_robot_reset_timers(robot);
	u = burns_robot_start_walking(robot);
	burns_robot_choose_target(robot, u, &y_2, &carry);
	return y_2;
}

/* Throws off piece A of object_1d_parts (in the 5280 list), up at 0500. */
void burns_robot_throw_piece(uint16_t robot, uint16_t *p_y, uint16_t *p_piece, uint16_t *p_piece_number)
{
	uint16_t piece_number = (uint16_t)*p_piece_number;
	uint32_t carry = 0;
	uint8_t list = 0;
	uint16_t part_code = 0, piece = 0, y = 0;
	uint8_t stack = 0;

	stack = piece_number >> 8;
	list = 1u;
	vector_find_free_slot(list, &piece, &carry);
	part_code = 1u | ((uint32_t)stack << 8);
	y = burns_robot_place_part(robot, piece, part_code);
	OBJECT(piece)->flags = 0x88u;
	OBJECT(piece)->z_speed = 0x500;
	piece_number = 0x500u;
	*p_y = y;
	*p_piece = piece;
	*p_piece_number = piece_number;
}

/* Form 2 broken: slows, sheds its pieces and goes on as form 3. */
uint16_t burns_robot_form_2_broken(uint16_t robot, uint16_t y)
{
	uint16_t steps = 0;
	uint8_t step = 0;

	for (;;)
	{
		steps = burns_robot_form_2_broken_actions_ADDRESS;
		step = OBJECT(robot)->burns_robot.step;
		switch ((int8_t)(uint8_t)((uint32_t)step << 1))
		{
		case -4:
		case 0:
			burns_robot_start_breaking(robot);
			return y;
		case 2:
			return burns_robot_shed_form_2(robot, y);
		case 4:
		case 18:
			burns_robot_broken_shake(robot);
			return y;
		case 6:
		case 20:
			burns_robot_broken_cry(robot);
			return y;
		case 8:
			return burns_robot_shed_form_1(robot, y);
		case 10:
		case 24:
			burns_robot_fall_down(robot);
			return y;
		case 12:
		case 26:
			burns_robot_lie_broken(robot);
			return y;
		case 14:
		case 28:
			burns_robot_rise_as_next_form(robot);
			return y;
		case 16:
		case 30:
			return burns_robot_start_form(robot, y);
		case 22:
			return burns_robot_shed_form_0(robot, y);
		case 32:
			return burns_robot_hurt_flash(robot, y, steps);
		case 34:
			return burns_robot_hurt_end(robot, y);
		case 36:
			burns_robot_place(robot);
			return y;
		case 38:
			burns_robot_wait_for_story(robot);
			return y;
		case 40:
			burns_robot_appear(robot);
			return y;
		case 42:
			burns_robot_step_up(robot);
			return y;
		case 44:
			burns_robot_speak(robot);
			return y;
		case 46:
			return burns_robot_toss_part(robot, y);
		case 48:
			burns_robot_start_fight(robot);
			return y;
		case 50:
			burns_robot_ready(robot);
			return y;
		case 52:
		case 58:
			burns_robot_stop_and_wind_up(robot);
			return y;
		case 54:
		case 74:
			burns_robot_swing_hit(robot);
			return y;
		case 56:
		case 76:
			return burns_robot_walk_on(robot, y);
		case 60:
			return burns_robot_fire_shot(robot, y);
		case 62:
			burns_robot_volley_next(robot);
			return y;
		case 64:
			break;
		case -54:
			return burns_robot_final_defeat(robot, y);
		case -52:
			return burns_robot_form_3_broken(robot, y);
		case -50:
			continue;
		case -48:
			return burns_robot_form_1_broken(robot, y);
		case -46:
			return burns_robot_form_0_broken(robot, y);
		case -44:
			return burns_robot_hurt(robot, y);
		case -42:
			return burns_robot_entrance(robot, y);
		case -40:
			return burns_robot_walk_form_0(robot, y);
		case -38:
			return burns_robot_walk_form_1(robot, y);
		case -36:
		case -34:
		case -32:
			return burns_robot_walk_late_forms(robot, y);
		case -30:
		case -28:
		case -26:
			return burns_robot_swing(robot, y);
		case -24:
			return burns_robot_volley(robot, y);
		case -22:
			return burns_robot_lunge(robot, y);
		case -20:
			return burns_robot_part_attack(robot);
		case -18:
			return burns_robot_lob_bombs(robot, y);
		case -16:
			return burns_robot_gloat(robot, y);
		case -14:
			burns_robot_drop_maggie(robot);
			return y;
		case -12:
			return burns_robot_walk_to_maggie(robot, y);
		case -10:
			burns_robot_stop_at_maggie(robot);
			return y;
		case -8:
			return burns_robot_let_burns_out(robot, y);
		case -6:
			burns_robot_leave(robot);
			return y;
		case -2:
			return burns_robot_shed_form_3(robot, y);
		}
		break;
	}
	return burns_robot_volley_end(robot, y);
}

/* Starts breaking: its breaking look for its form, sound 6E, slowed to a quarter. */
void burns_robot_start_breaking(uint16_t robot)
{
	uint32_t carry = 0;
	uint16_t command = 0, look = 0;
	uint8_t form_base = 0, form_extra = 0, step = 0;

	form_base = OBJECT(robot)->burns_robot.form_base;
	form_extra = OBJECT(robot)->burns_robot.form_extra;
	look = (uint32_t)(uint8_t)(0xAu + form_base + form_extra) << 8;
	burns_robot_set_look(robot, look);
	command = 0x6E00u;
	carry = vector_queue_sound(command);
	burns_robot_slow_down(robot);
	step = OBJECT(robot)->burns_robot.step;
	OBJECT(robot)->burns_robot.step = step + 1u;
}

/* At its frame: pieces 2 fly off, and it goes on as the next form with that form's health, walking at a
   target. */
uint16_t burns_robot_shed_form_2(uint16_t robot, uint16_t y)
{
	uint32_t carry = 0;
	uint8_t a = 0, health = 0;
	uint16_t ignored16 = 0, piece = 0, piece_number = 0, u = 0, y_2 = 0;
	uint8_t animation_flags = 0, t1 = 0, form_extra = 0, form_base = 0, form_extra_2 = 0;
	uint16_t t2 = 0, t3 = 0;

	animation_flags = OBJECT(robot)->animation_flags;
	t1 = animation_flags & 2u;
	a = t1;
	if (t1 == 0u)
		return y;
	piece_number = (uint32_t)a << 8;
	burns_robot_throw_piece_2(robot, piece_number, &ignored16, &piece);
	t2 = OBJECT(robot)->x;
	t3 = t2 + 0x20u;
	OBJECT(piece)->x = t3;
	OBJECT(piece)->x_speed = 0x80;
	piece_number = 0x8280u;
	burns_robot_throw_piece_2(robot, piece_number, &ignored16, &piece);
	OBJECT(piece)->x_speed = -0x100;
	piece_number = 0x200u;
	burns_robot_throw_piece_2(robot, piece_number, &y_2, &piece);
	OBJECT(piece)->x_speed = 0x100;
	form_extra = OBJECT(robot)->burns_robot.form_extra;
	OBJECT(robot)->burns_robot.form_extra = form_extra + 1u;
	form_base = OBJECT(robot)->burns_robot.form_base;
	form_extra_2 = OBJECT(robot)->burns_robot.form_extra;
	health = burns_robot_healths[(int8_t)((uint8_t)(form_base + form_extra_2))];
	OBJECT(robot)->vitality = health;
	OBJECT(robot)->burns_robot.health_mark = health;
	burns_robot_reset_timers(robot);
	u = burns_robot_start_walking(robot);
	burns_robot_choose_target(robot, u, &y_2, &carry);
	return y_2;
}

/* Throws off piece A, up at 0500 (as burns_robot_throw_piece). */
void burns_robot_throw_piece_2(uint16_t robot, uint16_t piece_number, uint16_t *p_y, uint16_t *p_piece)
{
	uint32_t carry = 0;
	uint8_t list = 0;
	uint16_t part_code = 0, piece = 0, y = 0;
	uint8_t stack = 0;

	stack = piece_number >> 8;
	list = 1u;
	vector_find_free_slot(list, &piece, &carry);
	part_code = 1u | ((uint32_t)stack << 8);
	y = burns_robot_place_part(robot, piece, part_code);
	OBJECT(piece)->flags = 0x88u;
	OBJECT(piece)->z_speed = 0x500;
	*p_y = y;
	*p_piece = piece;
}

/* Form 1 broken: shakes, sheds its pieces, falls, lies, and gets up as form 2. */
uint16_t burns_robot_form_1_broken(uint16_t robot, uint16_t y)
{
	uint16_t steps = 0;
	uint8_t step = 0;

	for (;;)
	{
		steps = burns_robot_form_1_broken_actions_ADDRESS;
		step = OBJECT(robot)->burns_robot.step;
		switch ((int8_t)(uint8_t)((uint32_t)step << 1))
		{
		case 0:
		case 14:
			burns_robot_broken_shake(robot);
			return y;
		case 2:
		case 16:
			burns_robot_broken_cry(robot);
			return y;
		case 4:
			return burns_robot_shed_form_1(robot, y);
		case 6:
		case 20:
			burns_robot_fall_down(robot);
			return y;
		case 8:
		case 22:
			burns_robot_lie_broken(robot);
			return y;
		case 10:
		case 24:
			burns_robot_rise_as_next_form(robot);
			return y;
		case 12:
		case 26:
			return burns_robot_start_form(robot, y);
		case 18:
			return burns_robot_shed_form_0(robot, y);
		case 28:
			return burns_robot_hurt_flash(robot, y, steps);
		case 30:
			return burns_robot_hurt_end(robot, y);
		case 32:
			burns_robot_place(robot);
			return y;
		case 34:
			burns_robot_wait_for_story(robot);
			return y;
		case 36:
			burns_robot_appear(robot);
			return y;
		case 38:
			burns_robot_step_up(robot);
			return y;
		case 40:
			burns_robot_speak(robot);
			return y;
		case 42:
			return burns_robot_toss_part(robot, y);
		case 44:
			burns_robot_start_fight(robot);
			return y;
		case 46:
			burns_robot_ready(robot);
			return y;
		case 48:
		case 54:
			burns_robot_stop_and_wind_up(robot);
			return y;
		case 50:
		case 70:
			burns_robot_swing_hit(robot);
			return y;
		case 52:
		case 72:
			return burns_robot_walk_on(robot, y);
		case 56:
			return burns_robot_fire_shot(robot, y);
		case 58:
			burns_robot_volley_next(robot);
			return y;
		case 60:
			break;
		case -58:
			return burns_robot_final_defeat(robot, y);
		case -56:
			return burns_robot_form_3_broken(robot, y);
		case -54:
			return burns_robot_form_2_broken(robot, y);
		case -52:
			continue;
		case -50:
			return burns_robot_form_0_broken(robot, y);
		case -48:
			return burns_robot_hurt(robot, y);
		case -46:
			return burns_robot_entrance(robot, y);
		case -44:
			return burns_robot_walk_form_0(robot, y);
		case -42:
			return burns_robot_walk_form_1(robot, y);
		case -40:
		case -38:
		case -36:
			return burns_robot_walk_late_forms(robot, y);
		case -34:
		case -32:
		case -30:
			return burns_robot_swing(robot, y);
		case -28:
			return burns_robot_volley(robot, y);
		case -26:
			return burns_robot_lunge(robot, y);
		case -24:
			return burns_robot_part_attack(robot);
		case -22:
			return burns_robot_lob_bombs(robot, y);
		case -20:
			return burns_robot_gloat(robot, y);
		case -18:
			burns_robot_drop_maggie(robot);
			return y;
		case -16:
			return burns_robot_walk_to_maggie(robot, y);
		case -14:
			burns_robot_stop_at_maggie(robot);
			return y;
		case -12:
			return burns_robot_let_burns_out(robot, y);
		case -10:
			burns_robot_leave(robot);
			return y;
		case -8:
		case -4:
			burns_robot_start_breaking(robot);
			return y;
		case -6:
			return burns_robot_shed_form_3(robot, y);
		case -2:
			return burns_robot_shed_form_2(robot, y);
		}
		break;
	}
	return burns_robot_volley_end(robot, y);
}

/* At its frame: stops, rises 32, throws off pieces 1 both ways, and takes its falling look. */
uint16_t burns_robot_shed_form_1(uint16_t robot, uint16_t y)
{
	uint8_t d = 0;
	uint16_t ignored16 = 0, look = 0, piece = 0, piece_number = 0, y_2 = 0;
	uint8_t animation_flags = 0, step = 0;
	uint16_t x_speed = 0, z = 0, t1 = 0;

	animation_flags = OBJECT(robot)->animation_flags;
	if ((animation_flags & 2u) == 0u)
	{
		OBJECT(robot)->x_speed = 0x300;
		if ((frame_count & 1u) != 0u)
		{
			x_speed = OBJECT(robot)->x_speed;
			OBJECT(robot)->x_speed = 0u - x_speed;
		}
		return y;
	}
	OBJECT(robot)->x_speed = 0;
	z = OBJECT(robot)->z;
	t1 = z + 0x20u;
	d = (uint8_t)t1;
	OBJECT(robot)->z = ((uint32_t)(t1 >> 8) << 8) | (d & 0xFFu);
	piece_number = (d & 0xFFu) | 0x8100u;
	burns_robot_throw_piece_3(robot, piece_number, &ignored16, &piece);
	OBJECT(piece)->x_speed = 0x100;
	OBJECT(piece)->y_speed = -0x40;
	OBJECT(piece)->z_speed = 0x500;
	piece_number = 0x100u;
	burns_robot_throw_piece_3(robot, piece_number, &y_2, &piece);
	OBJECT(piece)->x_speed = -0x100;
	OBJECT(piece)->y_speed = -0x20;
	OBJECT(piece)->z_speed = 0x300;
	look = 0x1400u;
	burns_robot_set_look(robot, look);
	step = OBJECT(robot)->burns_robot.step;
	OBJECT(robot)->burns_robot.step = step + 1u;
	return y_2;
}

/* Puts in piece A, shown. */
void burns_robot_throw_piece_3(uint16_t robot, uint16_t piece_number, uint16_t *p_y, uint16_t *p_piece)
{
	uint32_t carry = 0;
	uint8_t list = 0;
	uint16_t part_code = 0, piece = 0, y = 0;
	uint8_t stack = 0;

	stack = piece_number >> 8;
	list = 1u;
	vector_find_free_slot(list, &piece, &carry);
	part_code = 1u | ((uint32_t)stack << 8);
	y = burns_robot_place_part(robot, piece, part_code);
	OBJECT(piece)->flags = 0x80u;
	*p_y = y;
	*p_piece = piece;
}

/* Form 0 broken: shakes, sheds its pieces, falls, lies, and gets up as form 1. */
uint16_t burns_robot_form_0_broken(uint16_t robot, uint16_t y)
{
	uint16_t steps = 0;
	uint8_t step = 0;

	for (;;)
	{
		steps = burns_robot_form_0_broken_actions_ADDRESS;
		step = OBJECT(robot)->burns_robot.step;
		switch ((int8_t)(uint8_t)((uint32_t)step << 1))
		{
		case -14:
		case 0:
			burns_robot_broken_shake(robot);
			return y;
		case -12:
		case 2:
			burns_robot_broken_cry(robot);
			return y;
		case 4:
			return burns_robot_shed_form_0(robot, y);
		case -8:
		case 6:
			burns_robot_fall_down(robot);
			return y;
		case -6:
		case 8:
			burns_robot_lie_broken(robot);
			return y;
		case -4:
		case 10:
			burns_robot_rise_as_next_form(robot);
			return y;
		case -2:
		case 12:
			return burns_robot_start_form(robot, y);
		case 14:
			return burns_robot_hurt_flash(robot, y, steps);
		case 16:
			return burns_robot_hurt_end(robot, y);
		case 18:
			burns_robot_place(robot);
			return y;
		case 20:
			burns_robot_wait_for_story(robot);
			return y;
		case 22:
			burns_robot_appear(robot);
			return y;
		case 24:
			burns_robot_step_up(robot);
			return y;
		case 26:
			burns_robot_speak(robot);
			return y;
		case 28:
			return burns_robot_toss_part(robot, y);
		case 30:
			burns_robot_start_fight(robot);
			return y;
		case 32:
			burns_robot_ready(robot);
			return y;
		case 34:
		case 40:
			burns_robot_stop_and_wind_up(robot);
			return y;
		case 36:
		case 56:
			burns_robot_swing_hit(robot);
			return y;
		case 38:
		case 58:
			return burns_robot_walk_on(robot, y);
		case 42:
			return burns_robot_fire_shot(robot, y);
		case 44:
			burns_robot_volley_next(robot);
			return y;
		case 46:
			break;
		case -72:
			return burns_robot_final_defeat(robot, y);
		case -70:
			return burns_robot_form_3_broken(robot, y);
		case -68:
			return burns_robot_form_2_broken(robot, y);
		case -66:
			return burns_robot_form_1_broken(robot, y);
		case -64:
			continue;
		case -62:
			return burns_robot_hurt(robot, y);
		case -60:
			return burns_robot_entrance(robot, y);
		case -58:
			return burns_robot_walk_form_0(robot, y);
		case -56:
			return burns_robot_walk_form_1(robot, y);
		case -54:
		case -52:
		case -50:
			return burns_robot_walk_late_forms(robot, y);
		case -48:
		case -46:
		case -44:
			return burns_robot_swing(robot, y);
		case -42:
			return burns_robot_volley(robot, y);
		case -40:
			return burns_robot_lunge(robot, y);
		case -38:
			return burns_robot_part_attack(robot);
		case -36:
			return burns_robot_lob_bombs(robot, y);
		case -34:
			return burns_robot_gloat(robot, y);
		case -32:
			burns_robot_drop_maggie(robot);
			return y;
		case -30:
			return burns_robot_walk_to_maggie(robot, y);
		case -28:
			burns_robot_stop_at_maggie(robot);
			return y;
		case -26:
			return burns_robot_let_burns_out(robot, y);
		case -24:
			burns_robot_leave(robot);
			return y;
		case -22:
		case -18:
			burns_robot_start_breaking(robot);
			return y;
		case -20:
			return burns_robot_shed_form_3(robot, y);
		case -16:
			return burns_robot_shed_form_2(robot, y);
		case -10:
			return burns_robot_shed_form_1(robot, y);
		}
		break;
	}
	return burns_robot_volley_end(robot, y);
}

/* Shakes in its form's look for 64 frames. */
void burns_robot_broken_shake(uint16_t robot)
{
	uint16_t look = 0;
	uint8_t form_base = 0, form_extra = 0, step = 0;
	uint16_t x_speed = 0;

	form_base = OBJECT(robot)->burns_robot.form_base;
	form_extra = OBJECT(robot)->burns_robot.form_extra;
	look = (uint32_t)(uint8_t)(form_base + form_extra) << 8;
	burns_robot_set_look(robot, look);
	OBJECT(robot)->burns_robot.wait_frames = 0x40u;
	step = OBJECT(robot)->burns_robot.step;
	OBJECT(robot)->burns_robot.step = step + 1u;
	OBJECT(robot)->x_speed = 0x300;
	if ((frame_count & 1u) != 0u)
	{
		x_speed = OBJECT(robot)->x_speed;
		OBJECT(robot)->x_speed = 0u - x_speed;
	}
}

/* After the shaking: the next music (but in form 1), sound 6E, its breaking look. */
void burns_robot_broken_cry(uint16_t robot)
{
	uint32_t carry = 0;
	uint16_t command = 0, look = 0;
	uint8_t wait_frames = 0, form_base = 0, form_base_2 = 0, form_extra = 0, step = 0;
	uint16_t x_speed = 0;

	wait_frames = OBJECT(robot)->burns_robot.wait_frames;
	OBJECT(robot)->burns_robot.wait_frames = wait_frames - 1u;
	if (wait_frames != 1u)
	{
		OBJECT(robot)->x_speed = 0x300;
		if ((frame_count & 1u) != 0u)
		{
			x_speed = OBJECT(robot)->x_speed;
			OBJECT(robot)->x_speed = 0u - x_speed;
		}
		return;
	}
	form_base = OBJECT(robot)->burns_robot.form_base;
	if (form_base != 1u)
		boss_arrived++;
	command = 0x6E00u;
	carry = vector_queue_sound(command);
	form_base_2 = OBJECT(robot)->burns_robot.form_base;
	form_extra = OBJECT(robot)->burns_robot.form_extra;
	look = (uint32_t)(uint8_t)(0xAu + form_base_2 + form_extra) << 8;
	burns_robot_set_look(robot, look);
	step = OBJECT(robot)->burns_robot.step;
	OBJECT(robot)->burns_robot.step = step + 1u;
}

/* At its frame: stops, rises 32, throws off pieces 0 both ways, and takes its falling look. */
uint16_t burns_robot_shed_form_0(uint16_t robot, uint16_t y)
{
	uint16_t d = 0, ignored16 = 0, look = 0, piece = 0, piece_number = 0, y_2 = 0;
	uint8_t animation_flags = 0, step = 0;
	uint16_t x_speed = 0, z = 0, t1 = 0;

	animation_flags = OBJECT(robot)->animation_flags;
	if ((animation_flags & 2u) == 0u)
	{
		OBJECT(robot)->x_speed = 0x300;
		if ((frame_count & 1u) != 0u)
		{
			x_speed = OBJECT(robot)->x_speed;
			OBJECT(robot)->x_speed = 0u - x_speed;
		}
		return y;
	}
	OBJECT(robot)->x_speed = 0;
	z = OBJECT(robot)->z;
	t1 = z + 0x20u;
	d = t1;
	OBJECT(robot)->z = ((uint32_t)(t1 >> 8) << 8) | (d & 0xFFu);
	d &= 0xFFu;
	burns_robot_throw_piece_4(robot, d, &ignored16, &piece);
	OBJECT(piece)->x_speed = 0x100;
	piece_number = 0x8000u;
	burns_robot_throw_piece_4(robot, piece_number, &y_2, &piece);
	OBJECT(piece)->x_speed = -0x100;
	look = 0x1400u;
	burns_robot_set_look(robot, look);
	step = OBJECT(robot)->burns_robot.step;
	OBJECT(robot)->burns_robot.step = step + 1u;
	return y_2;
}

/* Falls to the floor, then lies 128 frames. */
void burns_robot_fall_down(uint16_t robot)
{
	uint32_t carry = 0;
	uint16_t ignored16 = 0;
	uint8_t step = 0;

	vector_apply_gravity(robot, &ignored16, &carry);
	if (carry)
	{
		OBJECT(robot)->burns_robot.wait_frames = 0x80u;
		step = OBJECT(robot)->burns_robot.step;
		OBJECT(robot)->burns_robot.step = step + 1u;
	}
}

/* Lying broken: the next music (but in form 1), then its lying look. */
void burns_robot_lie_broken(uint16_t robot)
{
	uint16_t look = 0;
	uint8_t wait_frames = 0, form_base = 0, form_base_2 = 0, form_extra = 0, step = 0;

	wait_frames = OBJECT(robot)->burns_robot.wait_frames;
	OBJECT(robot)->burns_robot.wait_frames = wait_frames - 1u;
	if (wait_frames != 1u)
		return;
	form_base = OBJECT(robot)->burns_robot.form_base;
	if (form_base != 1u)
		boss_arrived++;
	form_base_2 = OBJECT(robot)->burns_robot.form_base;
	form_extra = OBJECT(robot)->burns_robot.form_extra;
	look = (uint32_t)(uint8_t)(0x15u + form_base_2 + form_extra) << 8;
	burns_robot_set_look(robot, look);
	step = OBJECT(robot)->burns_robot.step;
	OBJECT(robot)->burns_robot.step = step + 1u;
}

/* When its animation ends, rises as its next form (field 30 one more), with Mr. Burns' voice (3F35). */
void burns_robot_rise_as_next_form(uint16_t robot)
{
	uint32_t carry = 0;
	uint16_t command = 0, look = 0;
	uint8_t animation_flags = 0, form_base = 0, form_base_2 = 0, step = 0;

	animation_flags = OBJECT(robot)->animation_flags;
	if ((animation_flags & 1u) == 0u)
		return;
	form_base = OBJECT(robot)->burns_robot.form_base;
	OBJECT(robot)->burns_robot.form_base = form_base + 1u;
	form_base_2 = OBJECT(robot)->burns_robot.form_base;
	look = (uint32_t)form_base_2 << 8;
	burns_robot_set_look(robot, look);
	command = 0x3F35u;
	carry = vector_queue_sound(command);
	OBJECT(robot)->burns_robot.wait_frames = 0x40u;
	step = OBJECT(robot)->burns_robot.step;
	OBJECT(robot)->burns_robot.step = step + 1u;
}

/* After 64 frames: its new form's health, its timers back to 0, walking at a target. */
uint16_t burns_robot_start_form(uint16_t robot, uint16_t current_target)
{
	uint32_t carry = 0;
	uint8_t health = 0;
	uint16_t u = 0;
	uint8_t wait_frames = 0, form_base = 0, form_extra = 0;

	wait_frames = OBJECT(robot)->burns_robot.wait_frames;
	OBJECT(robot)->burns_robot.wait_frames = wait_frames - 1u;
	if (wait_frames != 1u)
		return current_target;
	form_base = OBJECT(robot)->burns_robot.form_base;
	form_extra = OBJECT(robot)->burns_robot.form_extra;
	health = burns_robot_healths[(int8_t)((uint8_t)(form_base + form_extra))];
	OBJECT(robot)->vitality = health;
	OBJECT(robot)->burns_robot.health_mark = health;
	burns_robot_reset_timers(robot);
	u = burns_robot_start_walking(robot);
	burns_robot_choose_target(robot, u, &current_target, &carry);
	return current_target;
}

/* Throws off piece A, up at 0500 (as burns_robot_throw_piece). */
void burns_robot_throw_piece_4(uint16_t robot, uint16_t piece_number, uint16_t *p_y, uint16_t *p_piece)
{
	uint32_t carry = 0;
	uint8_t list = 0;
	uint16_t part_code = 0, piece = 0, y = 0;
	uint8_t stack = 0;

	stack = piece_number >> 8;
	list = 1u;
	vector_find_free_slot(list, &piece, &carry);
	part_code = 1u | ((uint32_t)stack << 8);
	y = burns_robot_place_part(robot, piece, part_code);
	OBJECT(piece)->flags = 0x88u;
	OBJECT(piece)->z_speed = 0x500;
	*p_y = y;
	*p_piece = piece;
}

/* Hurt by a blow: flashes and reels for 16 frames. */
uint16_t burns_robot_hurt(uint16_t robot, uint16_t y)
{
	uint16_t steps = 0;
	uint8_t step = 0;

	for (;;)
	{
		steps = burns_robot_hurt_actions_ADDRESS;
		step = OBJECT(robot)->burns_robot.step;
		switch ((int8_t)(uint8_t)((uint32_t)step << 1))
		{
		case 0:
			return burns_robot_hurt_flash(robot, y, steps);
		case 2:
			return burns_robot_hurt_end(robot, y);
		case 4:
			burns_robot_place(robot);
			return y;
		case 6:
			burns_robot_wait_for_story(robot);
			return y;
		case 8:
			burns_robot_appear(robot);
			return y;
		case 10:
			burns_robot_step_up(robot);
			return y;
		case 12:
			burns_robot_speak(robot);
			return y;
		case 14:
			return burns_robot_toss_part(robot, y);
		case 16:
			burns_robot_start_fight(robot);
			return y;
		case 18:
			burns_robot_ready(robot);
			return y;
		case 20:
		case 26:
			burns_robot_stop_and_wind_up(robot);
			return y;
		case 22:
		case 42:
			burns_robot_swing_hit(robot);
			return y;
		case 24:
		case 44:
			return burns_robot_walk_on(robot, y);
		case 28:
			return burns_robot_fire_shot(robot, y);
		case 30:
			burns_robot_volley_next(robot);
			return y;
		case 32:
			break;
		case -86:
			return burns_robot_final_defeat(robot, y);
		case -84:
			return burns_robot_form_3_broken(robot, y);
		case -82:
			return burns_robot_form_2_broken(robot, y);
		case -80:
			return burns_robot_form_1_broken(robot, y);
		case -78:
			return burns_robot_form_0_broken(robot, y);
		case -76:
			continue;
		case -74:
			return burns_robot_entrance(robot, y);
		case -72:
			return burns_robot_walk_form_0(robot, y);
		case -70:
			return burns_robot_walk_form_1(robot, y);
		case -68:
		case -66:
		case -64:
			return burns_robot_walk_late_forms(robot, y);
		case -62:
		case -60:
		case -58:
			return burns_robot_swing(robot, y);
		case -56:
			return burns_robot_volley(robot, y);
		case -54:
			return burns_robot_lunge(robot, y);
		case -52:
			return burns_robot_part_attack(robot);
		case -50:
			return burns_robot_lob_bombs(robot, y);
		case -48:
			return burns_robot_gloat(robot, y);
		case -46:
			burns_robot_drop_maggie(robot);
			return y;
		case -44:
			return burns_robot_walk_to_maggie(robot, y);
		case -42:
			burns_robot_stop_at_maggie(robot);
			return y;
		case -40:
			return burns_robot_let_burns_out(robot, y);
		case -38:
			burns_robot_leave(robot);
			return y;
		case -36:
		case -32:
			burns_robot_start_breaking(robot);
			return y;
		case -34:
			return burns_robot_shed_form_3(robot, y);
		case -30:
			return burns_robot_shed_form_2(robot, y);
		case -28:
		case -14:
			burns_robot_broken_shake(robot);
			return y;
		case -26:
		case -12:
			burns_robot_broken_cry(robot);
			return y;
		case -24:
			return burns_robot_shed_form_1(robot, y);
		case -22:
		case -8:
			burns_robot_fall_down(robot);
			return y;
		case -20:
		case -6:
			burns_robot_lie_broken(robot);
			return y;
		case -18:
		case -4:
			burns_robot_rise_as_next_form(robot);
			return y;
		case -16:
		case -2:
			return burns_robot_start_form(robot, y);
		case -10:
			return burns_robot_shed_form_0(robot, y);
		}
		break;
	}
	return burns_robot_volley_end(robot, y);
}

/* Flashes its palette and takes its hurt look for 16 frames. */
uint16_t burns_robot_hurt_flash(uint16_t robot, uint16_t y, uint16_t palette_job)
{
	uint16_t look = 0, request = 0;
	uint8_t form_base = 0, form_extra = 0, step = 0;

	palette_request_kind = 2u;
	request = 0x3Fu;
	vector_palette_request(request, &y, &palette_job);
	form_base = OBJECT(robot)->burns_robot.form_base;
	form_extra = OBJECT(robot)->burns_robot.form_extra;
	look = 0x3Fu | ((uint32_t)(uint8_t)(0x17u + form_base + form_extra) << 8);
	burns_robot_set_look(robot, look);
	OBJECT(robot)->burns_robot.wait_frames = 0x10u;
	step = OBJECT(robot)->burns_robot.step;
	OBJECT(robot)->burns_robot.step = step + 1u;
	return y;
}

/* When the 16 frames are up, walks at a target again. */
uint16_t burns_robot_hurt_end(uint16_t robot, uint16_t current_target)
{
	uint32_t carry = 0;
	uint16_t u = 0;
	uint8_t wait_frames = 0;

	wait_frames = OBJECT(robot)->burns_robot.wait_frames;
	OBJECT(robot)->burns_robot.wait_frames = wait_frames - 1u;
	if (wait_frames != 1u)
		return current_target;
	u = burns_robot_start_walking(robot);
	burns_robot_choose_target(robot, u, &current_target, &carry);
	return current_target;
}

/* Its entrance, step by step until it can be fought. */
uint16_t burns_robot_entrance(uint16_t robot, uint16_t y)
{
	uint16_t steps = 0;
	uint8_t step = 0;

	for (;;)
	{
		steps = burns_robot_entrance_actions_ADDRESS;
		step = OBJECT(robot)->burns_robot.step;
		switch ((int8_t)(uint8_t)((uint32_t)step << 1))
		{
		case 0:
			burns_robot_place(robot);
			return y;
		case 2:
			burns_robot_wait_for_story(robot);
			return y;
		case 4:
			burns_robot_appear(robot);
			return y;
		case 6:
			burns_robot_step_up(robot);
			return y;
		case 8:
			burns_robot_speak(robot);
			return y;
		case 10:
			return burns_robot_toss_part(robot, y);
		case 12:
			burns_robot_start_fight(robot);
			return y;
		case 14:
			burns_robot_ready(robot);
			return y;
		case 16:
		case 22:
			burns_robot_stop_and_wind_up(robot);
			return y;
		case 18:
		case 38:
			burns_robot_swing_hit(robot);
			return y;
		case 20:
		case 40:
			return burns_robot_walk_on(robot, y);
		case 24:
			return burns_robot_fire_shot(robot, y);
		case 26:
			burns_robot_volley_next(robot);
			return y;
		case 28:
			break;
		case -90:
			return burns_robot_final_defeat(robot, y);
		case -88:
			return burns_robot_form_3_broken(robot, y);
		case -86:
			return burns_robot_form_2_broken(robot, y);
		case -84:
			return burns_robot_form_1_broken(robot, y);
		case -82:
			return burns_robot_form_0_broken(robot, y);
		case -80:
			return burns_robot_hurt(robot, y);
		case -78:
			continue;
		case -76:
			return burns_robot_walk_form_0(robot, y);
		case -74:
			return burns_robot_walk_form_1(robot, y);
		case -72:
		case -70:
		case -68:
			return burns_robot_walk_late_forms(robot, y);
		case -66:
		case -64:
		case -62:
			return burns_robot_swing(robot, y);
		case -60:
			return burns_robot_volley(robot, y);
		case -58:
			return burns_robot_lunge(robot, y);
		case -56:
			return burns_robot_part_attack(robot);
		case -54:
			return burns_robot_lob_bombs(robot, y);
		case -52:
			return burns_robot_gloat(robot, y);
		case -50:
			burns_robot_drop_maggie(robot);
			return y;
		case -48:
			return burns_robot_walk_to_maggie(robot, y);
		case -46:
			burns_robot_stop_at_maggie(robot);
			return y;
		case -44:
			return burns_robot_let_burns_out(robot, y);
		case -42:
			burns_robot_leave(robot);
			return y;
		case -40:
		case -36:
			burns_robot_start_breaking(robot);
			return y;
		case -38:
			return burns_robot_shed_form_3(robot, y);
		case -34:
			return burns_robot_shed_form_2(robot, y);
		case -32:
		case -18:
			burns_robot_broken_shake(robot);
			return y;
		case -30:
		case -16:
			burns_robot_broken_cry(robot);
			return y;
		case -28:
			return burns_robot_shed_form_1(robot, y);
		case -26:
		case -12:
			burns_robot_fall_down(robot);
			return y;
		case -24:
		case -10:
			burns_robot_lie_broken(robot);
			return y;
		case -22:
		case -8:
			burns_robot_rise_as_next_form(robot);
			return y;
		case -20:
		case -6:
			return burns_robot_start_form(robot, y);
		case -14:
			return burns_robot_shed_form_0(robot, y);
		case -4:
			return burns_robot_hurt_flash(robot, y, steps);
		case -2:
			return burns_robot_hurt_end(robot, y);
		}
		break;
	}
	return burns_robot_volley_end(robot, y);
}

/* Puts the robot at the stage's x 420 with health A0, and keeps it in 1854. */
void burns_robot_place(uint16_t robot)
{
	uint8_t step = 0;
	uint16_t t1 = 0, t2 = 0;

	io_write16(0x1854u, robot);
	OBJECT(robot)->shadow_player = 1u;
	t1 = 0x420u - camera_x;
	OBJECT(robot)->x = t1;
	t2 = 0xE8u + camera_y;
	OBJECT(robot)->y = t2;
	OBJECT(robot)->vitality = 0xA0u;
	OBJECT(robot)->burns_robot.health_mark = 0xA0u;
	step = OBJECT(robot)->burns_robot.step;
	OBJECT(robot)->burns_robot.step = step + 1u;
}

/* Waits until the story after stage 8's first boss is over (direct page 81). */
void burns_robot_wait_for_story(uint16_t robot)
{
	uint8_t step = 0;

	if (stage_cue != 0u)
	{
		OBJECT(robot)->burns_robot.wait_frames = 0x20u;
		step = OBJECT(robot)->burns_robot.step;
		OBJECT(robot)->burns_robot.step = step + 1u;
	}
}

/* After 32 frames shows itself (look 32), harmless. */
void burns_robot_appear(uint16_t robot)
{
	uint16_t d = 0;
	uint8_t wait_frames = 0, step = 0;

	wait_frames = OBJECT(robot)->burns_robot.wait_frames;
	OBJECT(robot)->burns_robot.wait_frames = wait_frames - 1u;
	if (wait_frames != 1u)
		return;
	OBJECT(robot)->flags = 0x80u;
	d = 0x3200u;
	d = burns_robot_set_look(robot, d);
	d &= 0xFFu;
	burns_robot_set_box(robot, d);
	step = OBJECT(robot)->burns_robot.step;
	OBJECT(robot)->burns_robot.step = step + 1u;
}

/* Steps 16 up the screen and waits 64 frames. */
void burns_robot_step_up(uint16_t robot)
{
	uint8_t animation_flags = 0, step = 0;
	uint16_t t1 = 0, t2 = 0;

	animation_flags = OBJECT(robot)->animation_flags;
	if ((animation_flags & 1u) == 0u)
	{
		t1 = OBJECT(robot)->y;
		t2 = t1 - 0x10u;
		OBJECT(robot)->y = t2;
		OBJECT(robot)->burns_robot.wait_frames = 0x40u;
		step = OBJECT(robot)->burns_robot.step;
		OBJECT(robot)->burns_robot.step = step + 1u;
	}
}

/* Mr. Burns speaks: a speech balloon (4D40 type 29, kind B0 animation 83) on the robot and his voice
   (3F36). */
void burns_robot_speak(uint16_t robot)
{
	uint32_t carry = 0;
	uint8_t list = 0;
	uint16_t balloon = 0, command = 0, look = 0;
	uint8_t wait_frames = 0, step = 0;

	wait_frames = OBJECT(robot)->burns_robot.wait_frames;
	OBJECT(robot)->burns_robot.wait_frames = wait_frames - 1u;
	if (wait_frames != 1u)
		return;
	list = 2u;
	vector_find_free_slot(list, &balloon, &carry);
	if (carry)
	{
		OBJECT(balloon)->type = 0x29;
		OBJECT(balloon)->kind = 0xB0u;
		OBJECT(balloon)->animation = 0x83u;
		OBJECT(balloon)->action = 0x80u;
		OBJECT(balloon)->action_step = (uint8_t)(robot >> 8u);
		OBJECT(balloon)->behaviour = (OBJECT(balloon)->behaviour & 0xFFu) | ((robot & 0xFFu) << 8u);
	}
	command = 0x3F36u;
	carry = vector_queue_sound(command);
	look = 0x3336u;
	burns_robot_set_look(robot, look);
	step = OBJECT(robot)->burns_robot.step;
	OBJECT(robot)->burns_robot.step = step + 1u;
}

/* At its frame tosses away a part (object_1d_parts 8, 5280 type E4) at full size, with sound 0301. */
uint16_t burns_robot_toss_part(uint16_t robot, uint16_t y)
{
	uint32_t carry = 0;
	uint8_t list = 0;
	uint16_t command = 0, part = 0, part_code = 0;
	uint8_t animation_flags = 0, step = 0;

	animation_flags = OBJECT(robot)->animation_flags;
	if ((animation_flags & 2u) == 0u)
		return y;
	list = 1u;
	vector_find_free_slot(list, &part, &carry);
	if (carry)
	{
		part_code = 0x801u;
		y = burns_robot_place_part(robot, part, part_code);
		OBJECT(part)->flags = 0x80u;
		OBJECT(part)->zoom_x = 0x40u;
		OBJECT(part)->zoom_y = 0x40u;
		OBJECT(robot)->burns_robot.wait_frames = 0x40u;
		command = 0x301u;
		carry = vector_queue_sound(command);
	}
	step = OBJECT(robot)->burns_robot.step;
	OBJECT(robot)->burns_robot.step = step + 1u;
	return y;
}

/* After 64 frames: sound 14, the scene's next music, its fighting look, and the step moves on. */
void burns_robot_start_fight(uint16_t robot)
{
	uint32_t carry = 0;
	uint8_t a = 0;
	uint16_t command = 0, d = 0;
	uint8_t wait_frames = 0, step = 0;
	uint32_t step_subphase_halfword = 0;

	wait_frames = OBJECT(robot)->burns_robot.wait_frames;
	OBJECT(robot)->burns_robot.wait_frames = wait_frames - 1u;
	if (wait_frames != 1u)
		return;
	command = 0x1400u;
	carry = vector_queue_sound(command);
	boss_arrived = 1u;
	d = 0x3400u;
	d = burns_robot_set_look(robot, d);
	a = (uint8_t)(d >> 8);
	step = OBJECT(robot)->burns_robot.step;
	OBJECT(robot)->burns_robot.step = step + 1u;
	step_phase++;
	step_subphase_halfword = ((uint32_t)a << 8) | (d & 0xFFu);
	step_subphase = (uint8_t)(step_subphase_halfword >> 8u);
	step_countdown = (uint8_t)step_subphase_halfword;
}

/* When its animation ends it can be hit and starts walking (handler 01). */
void burns_robot_ready(uint16_t robot)
{
	uint8_t animation_flags = 0;

	animation_flags = OBJECT(robot)->animation_flags;
	if ((animation_flags & 1u) == 0u)
		return;
	burns_robot_reset_timers(robot);
	OBJECT(robot)->flags |= 0x40u;
	OBJECT(robot)->burns_robot.step = 0u;
	OBJECT(robot)->state = 1u;
}

/* Form 0 walking straight at its target with heavy steps (sound 5A), attacking when it can. */
uint16_t burns_robot_walk_form_0(uint16_t robot, uint16_t y)
{
	uint32_t carry = 0;
	uint16_t command = 0, look = 0, u = 0;
	uint8_t animation = 0, form_base = 0, aim = 0, animation_flags = 0;

	burns_robot_decide_form_0(robot, &y, &u, &carry);
	if (carry)
		return y;
	burns_robot_choose_target(robot, u, &y, &carry);
	if (carry)
		return y;
	animation = OBJECT(robot)->animation;
	if (animation != 4u)
	{
		form_base = OBJECT(robot)->burns_robot.form_base;
		look = (uint32_t)(uint8_t)(5u + form_base) << 8;
		burns_robot_set_look(robot, look);
	}
	burns_robot_aim_at_target(robot);
	aim = OBJECT(robot)->burns_robot.aim;
	OBJECT(robot)->burns_robot.walk_direction = aim;
	y = burns_robot_walk(robot);
	animation_flags = OBJECT(robot)->animation_flags;
	if ((animation_flags & 2u) != 0u)
	{
		command = 0x5A00u;
		carry = vector_queue_sound(command);
	}
	return y;
}

/* Form 1 walking at its target, turning a step at a time, sound 13 every 64 frames, attacking when it
   can. */
uint16_t burns_robot_walk_form_1(uint16_t robot, uint16_t y)
{
	uint32_t negative = 0, carry = 0;
	uint8_t turn = 0, walk_direction = 0;
	uint16_t command = 0, look = 0, u = 0;
	uint8_t animation = 0, form_base = 0, aim = 0, walk_direction_2 = 0, walk_direction_3 = 0;

	burns_robot_decide_form_1(robot, &y, &u, &carry);
	if (carry)
		return y;
	burns_robot_choose_target(robot, u, &y, &carry);
	if (carry)
		return y;
	if ((frame_count & 0x3Fu) == 0u)
	{
		command = 0x1300u;
		carry = vector_queue_sound(command);
	}
	animation = OBJECT(robot)->animation;
	if (animation != 0u)
	{
		form_base = OBJECT(robot)->burns_robot.form_base;
		look = (uint32_t)(uint8_t)(5u + form_base) << 8;
		burns_robot_set_look(robot, look);
	}
	burns_robot_aim_at_target(robot);
	turn = 1u;
	aim = OBJECT(robot)->burns_robot.aim;
	walk_direction = aim;
	walk_direction_2 = OBJECT(robot)->burns_robot.walk_direction;
	negative = (uint8_t)(walk_direction - walk_direction_2) >> 7;
	if (walk_direction == walk_direction_2)
	{
		y = burns_robot_walk(robot);
		return y;
	}
	if (negative)
		turn = 0u - turn;
	walk_direction_3 = OBJECT(robot)->burns_robot.walk_direction;
	OBJECT(robot)->burns_robot.walk_direction = turn + walk_direction_3;
	y = burns_robot_walk(robot);
	return y;
}

/* Forms 2-4 walking at their target, turning 3 steps at a time, attacking when they can. */
uint16_t burns_robot_walk_late_forms(uint16_t robot, uint16_t y)
{
	uint32_t carry = 0;
	uint16_t look = 0, u = 0;
	uint8_t animation = 0, form_base = 0, form_extra = 0;

	burns_robot_decide_late_forms(robot, &y, &u, &carry);
	if (carry)
		return y;
	burns_robot_choose_target(robot, u, &y, &carry);
	if (carry)
		return y;
	animation = OBJECT(robot)->animation;
	if (animation != 1u)
	{
		form_base = OBJECT(robot)->burns_robot.form_base;
		form_extra = OBJECT(robot)->burns_robot.form_extra;
		look = (uint32_t)(uint8_t)(5u + form_base + form_extra) << 8;
		burns_robot_set_look(robot, look);
	}
	burns_robot_aim_at_target(robot);
	return burns_robot_steer(robot);
}

/* Turns its walking direction up to 3 steps toward its aim and walks that way. */
uint16_t burns_robot_steer(uint16_t robot)
{
	uint32_t negative = 0;
	uint8_t turn = 0, walk_direction = 0;
	uint16_t y = 0;
	uint8_t aim = 0, walk_direction_2 = 0, walk_direction_3 = 0;

	turn = 3u;
	aim = OBJECT(robot)->burns_robot.aim;
	walk_direction = aim;
	walk_direction_2 = OBJECT(robot)->burns_robot.walk_direction;
	negative = (uint8_t)(walk_direction - walk_direction_2) >> 7;
	if (walk_direction == walk_direction_2)
	{
		y = burns_robot_walk(robot);
		return y;
	}
	if (negative)
		turn = 0u - turn;
	walk_direction_3 = OBJECT(robot)->burns_robot.walk_direction;
	OBJECT(robot)->burns_robot.walk_direction = turn + walk_direction_3;
	y = burns_robot_walk(robot);
	return y;
}

/* A swing (forms 0 and 1, and form 2's other attack): stops, winds up, hits at its frames, walks on. */
uint16_t burns_robot_swing(uint16_t robot, uint16_t y)
{
	uint16_t steps = 0;
	uint8_t step = 0;

	for (;;)
	{
		steps = burns_robot_swing_actions_ADDRESS;
		step = OBJECT(robot)->burns_robot.step;
		switch ((int8_t)(uint8_t)((uint32_t)step << 1))
		{
		case 0:
		case 6:
			burns_robot_stop_and_wind_up(robot);
			return y;
		case 2:
		case 22:
			burns_robot_swing_hit(robot);
			return y;
		case 4:
		case 24:
			return burns_robot_walk_on(robot, y);
		case 8:
			return burns_robot_fire_shot(robot, y);
		case 10:
			burns_robot_volley_next(robot);
			return y;
		case 12:
			break;
		case -106:
			return burns_robot_final_defeat(robot, y);
		case -104:
			return burns_robot_form_3_broken(robot, y);
		case -102:
			return burns_robot_form_2_broken(robot, y);
		case -100:
			return burns_robot_form_1_broken(robot, y);
		case -98:
			return burns_robot_form_0_broken(robot, y);
		case -96:
			return burns_robot_hurt(robot, y);
		case -94:
			return burns_robot_entrance(robot, y);
		case -92:
			return burns_robot_walk_form_0(robot, y);
		case -90:
			return burns_robot_walk_form_1(robot, y);
		case -88:
		case -86:
		case -84:
			return burns_robot_walk_late_forms(robot, y);
		case -82:
		case -80:
		case -78:
			continue;
		case -76:
			return burns_robot_volley(robot, y);
		case -74:
			return burns_robot_lunge(robot, y);
		case -72:
			return burns_robot_part_attack(robot);
		case -70:
			return burns_robot_lob_bombs(robot, y);
		case -68:
			return burns_robot_gloat(robot, y);
		case -66:
			burns_robot_drop_maggie(robot);
			return y;
		case -64:
			return burns_robot_walk_to_maggie(robot, y);
		case -62:
			burns_robot_stop_at_maggie(robot);
			return y;
		case -60:
			return burns_robot_let_burns_out(robot, y);
		case -58:
			burns_robot_leave(robot);
			return y;
		case -56:
		case -52:
			burns_robot_start_breaking(robot);
			return y;
		case -54:
			return burns_robot_shed_form_3(robot, y);
		case -50:
			return burns_robot_shed_form_2(robot, y);
		case -48:
		case -34:
			burns_robot_broken_shake(robot);
			return y;
		case -46:
		case -32:
			burns_robot_broken_cry(robot);
			return y;
		case -44:
			return burns_robot_shed_form_1(robot, y);
		case -42:
		case -28:
			burns_robot_fall_down(robot);
			return y;
		case -40:
		case -26:
			burns_robot_lie_broken(robot);
			return y;
		case -38:
		case -24:
			burns_robot_rise_as_next_form(robot);
			return y;
		case -36:
		case -22:
			return burns_robot_start_form(robot, y);
		case -30:
			return burns_robot_shed_form_0(robot, y);
		case -20:
			return burns_robot_hurt_flash(robot, y, steps);
		case -18:
			return burns_robot_hurt_end(robot, y);
		case -16:
			burns_robot_place(robot);
			return y;
		case -14:
			burns_robot_wait_for_story(robot);
			return y;
		case -12:
			burns_robot_appear(robot);
			return y;
		case -10:
			burns_robot_step_up(robot);
			return y;
		case -8:
			burns_robot_speak(robot);
			return y;
		case -6:
			return burns_robot_toss_part(robot, y);
		case -4:
			burns_robot_start_fight(robot);
			return y;
		case -2:
			burns_robot_ready(robot);
			return y;
		}
		break;
	}
	return burns_robot_volley_end(robot, y);
}

/* Stops and winds up. */
void burns_robot_stop_and_wind_up(uint16_t robot)
{
	burns_robot_stop(robot);
	burns_robot_wind_up(robot);
}

/* Waits out its wait (32 frames after a quick decision), then sound 7D and its attack's look for its
   form and attack; it can not be hurt. */
void burns_robot_wind_up(uint16_t robot)
{
	uint32_t carry = 0;
	uint16_t command = 0, look = 0;
	uint8_t wait_frames = 0, wait_frames_2 = 0, form_base = 0, form_extra = 0, attack_choice = 0, step = 0;

	wait_frames = OBJECT(robot)->burns_robot.wait_frames;
	if (wait_frames != 0u)
	{
		wait_frames_2 = OBJECT(robot)->burns_robot.wait_frames;
		OBJECT(robot)->burns_robot.wait_frames = wait_frames_2 - 1u;
		return;
	}
	command = 0x7D00u;
	carry = vector_queue_sound(command);
	OBJECT(robot)->flags |= 4u;
	form_base = OBJECT(robot)->burns_robot.form_base;
	form_extra = OBJECT(robot)->burns_robot.form_extra;
	attack_choice = OBJECT(robot)->burns_robot.attack_choice;
	look = (uint32_t)(uint8_t)(((uint32_t)(form_base + form_extra) << 1) + 0x26u + attack_choice) << 8;
	burns_robot_set_look(robot, look);
	step = OBJECT(robot)->burns_robot.step;
	OBJECT(robot)->burns_robot.step = step + 1u;
}

/* Hits with its attack's box at the animation's hit frames, none between; the next step when the
   animation ends. */
void burns_robot_swing_hit(uint16_t robot)
{
	uint8_t box = 0;
	uint16_t box_number = 0;
	uint8_t animation_flags = 0, step = 0, animation_flags_2 = 0, form_base = 0, form_extra = 0, attack_choice = 0;

	animation_flags = OBJECT(robot)->animation_flags;
	if ((animation_flags & 1u) != 0u)
	{
		step = OBJECT(robot)->burns_robot.step;
		OBJECT(robot)->burns_robot.step = step + 1u;
		return;
	}
	box = 0u;
	animation_flags_2 = OBJECT(robot)->animation_flags;
	if ((animation_flags_2 & 2u) != 0u)
	{
		form_base = OBJECT(robot)->burns_robot.form_base;
		form_extra = OBJECT(robot)->burns_robot.form_extra;
		attack_choice = OBJECT(robot)->burns_robot.attack_choice;
		box = ((uint32_t)(form_base + form_extra) << 1) + attack_choice + 3u;
	}
	box_number = (uint32_t)box << 8;
	burns_robot_set_box(robot, box_number);
}

/* Walks at a target again. */
uint16_t burns_robot_walk_on(uint16_t robot, uint16_t current_target)
{
	uint32_t carry = 0;
	uint16_t u = 0;

	u = burns_robot_start_walking(robot);
	burns_robot_choose_target(robot, u, &current_target, &carry);
	return current_target;
}

/* A volley of shots (form 1's second attack): winds up, fires shot after shot, walks on. */
uint16_t burns_robot_volley(uint16_t robot, uint16_t y)
{
	uint16_t steps = 0;
	uint8_t step = 0;

	for (;;)
	{
		steps = burns_robot_volley_actions_ADDRESS;
		step = OBJECT(robot)->burns_robot.step;
		switch ((int8_t)(uint8_t)((uint32_t)step << 1))
		{
		case -6:
		case 0:
			burns_robot_stop_and_wind_up(robot);
			return y;
		case 2:
			return burns_robot_fire_shot(robot, y);
		case 4:
			burns_robot_volley_next(robot);
			return y;
		case 6:
			break;
		case -4:
		case 16:
			burns_robot_swing_hit(robot);
			return y;
		case -2:
		case 18:
			return burns_robot_walk_on(robot, y);
		case -112:
			return burns_robot_final_defeat(robot, y);
		case -110:
			return burns_robot_form_3_broken(robot, y);
		case -108:
			return burns_robot_form_2_broken(robot, y);
		case -106:
			return burns_robot_form_1_broken(robot, y);
		case -104:
			return burns_robot_form_0_broken(robot, y);
		case -102:
			return burns_robot_hurt(robot, y);
		case -100:
			return burns_robot_entrance(robot, y);
		case -98:
			return burns_robot_walk_form_0(robot, y);
		case -96:
			return burns_robot_walk_form_1(robot, y);
		case -94:
		case -92:
		case -90:
			return burns_robot_walk_late_forms(robot, y);
		case -88:
		case -86:
		case -84:
			return burns_robot_swing(robot, y);
		case -82:
			continue;
		case -80:
			return burns_robot_lunge(robot, y);
		case -78:
			return burns_robot_part_attack(robot);
		case -76:
			return burns_robot_lob_bombs(robot, y);
		case -74:
			return burns_robot_gloat(robot, y);
		case -72:
			burns_robot_drop_maggie(robot);
			return y;
		case -70:
			return burns_robot_walk_to_maggie(robot, y);
		case -68:
			burns_robot_stop_at_maggie(robot);
			return y;
		case -66:
			return burns_robot_let_burns_out(robot, y);
		case -64:
			burns_robot_leave(robot);
			return y;
		case -62:
		case -58:
			burns_robot_start_breaking(robot);
			return y;
		case -60:
			return burns_robot_shed_form_3(robot, y);
		case -56:
			return burns_robot_shed_form_2(robot, y);
		case -54:
		case -40:
			burns_robot_broken_shake(robot);
			return y;
		case -52:
		case -38:
			burns_robot_broken_cry(robot);
			return y;
		case -50:
			return burns_robot_shed_form_1(robot, y);
		case -48:
		case -34:
			burns_robot_fall_down(robot);
			return y;
		case -46:
		case -32:
			burns_robot_lie_broken(robot);
			return y;
		case -44:
		case -30:
			burns_robot_rise_as_next_form(robot);
			return y;
		case -42:
		case -28:
			return burns_robot_start_form(robot, y);
		case -36:
			return burns_robot_shed_form_0(robot, y);
		case -26:
			return burns_robot_hurt_flash(robot, y, steps);
		case -24:
			return burns_robot_hurt_end(robot, y);
		case -22:
			burns_robot_place(robot);
			return y;
		case -20:
			burns_robot_wait_for_story(robot);
			return y;
		case -18:
			burns_robot_appear(robot);
			return y;
		case -16:
			burns_robot_step_up(robot);
			return y;
		case -14:
			burns_robot_speak(robot);
			return y;
		case -12:
			return burns_robot_toss_part(robot, y);
		case -10:
			burns_robot_start_fight(robot);
			return y;
		case -8:
			burns_robot_ready(robot);
			return y;
		}
		break;
	}
	return burns_robot_volley_end(robot, y);
}

/* At its frame fires a shot (4D40 type 25) at x speed 0500 the way it faces, sound 1D. */
uint16_t burns_robot_fire_shot(uint16_t robot, uint16_t y)
{
	uint32_t carry = 0;
	uint8_t facing = 0, list = 0, turned_part = 0;
	uint16_t box_number = 0, command = 0, object = 0, part_code = 0, self = 0, shot = 0;
	uint16_t stack = 0;
	uint8_t animation_flags = 0, attributes = 0, action = 0;
	uint16_t t1 = 0;

	animation_flags = OBJECT(robot)->animation_flags;
	if ((animation_flags & 2u) == 0u)
		return y;
	list = 2u;
	vector_find_free_slot(list, &shot, &carry);
	if (carry == 0u)
	{
		burns_robot_start_walking(robot);
		return y;
	}
	OBJECT(shot)->flags = 0x88u;
	OBJECT(shot)->action_step = 0x10u;
	shot_speed = 0x500;
	turned_part = 5u;
	attributes = OBJECT(robot)->attributes;
	facing = attributes & 0x40u;
	OBJECT(shot)->attributes = facing;
	if (facing != 0u)
	{
		turned_part -= 0x80u;
		shot_speed = 0u - shot_speed;
	}
	part_code = 2u | ((turned_part | 5u) << 8);
	y = burns_robot_place_part(robot, shot, part_code);
	command = 0x1D00u;
	carry = vector_queue_sound(command);
	t1 = shot_speed;
	OBJECT(shot)->x_speed = t1;
	stack = robot;
	self = shot;
	box_number = 0xF00u;
	burns_robot_set_box(self, box_number);
	object = stack;
	action = OBJECT(object)->action;
	OBJECT(object)->action = action + 1u;
	return y;
}

/* When the animation ends: another shot until burns_robot_volleys_by_players are fired, then the
   volley's end. */
void burns_robot_volley_next(uint16_t robot)
{
	uint8_t players_index = 0;
	uint8_t animation_flags = 0, shots_fired = 0, shots_fired_2 = 0, step = 0, step_2 = 0;

	animation_flags = OBJECT(robot)->animation_flags;
	if ((animation_flags & 1u) == 0u)
		return;
	players_index = player_count - 1u;
	shots_fired = OBJECT(robot)->burns_robot.shots_fired;
	OBJECT(robot)->burns_robot.shots_fired = shots_fired + 1u;
	shots_fired_2 = OBJECT(robot)->burns_robot.shots_fired;
	if (shots_fired_2 < burns_robot_volleys_by_players[(int8_t)players_index])
	{
		OBJECT(robot)->animation = 0x8Eu;
		step = OBJECT(robot)->burns_robot.step;
		OBJECT(robot)->burns_robot.step = step - 1u;
		return;
	}
	OBJECT(robot)->animation = 0x8Cu;
	step_2 = OBJECT(robot)->burns_robot.step;
	OBJECT(robot)->burns_robot.step = step_2 + 1u;
}

/* When the animation ends, walks at a target again. */
uint16_t burns_robot_volley_end(uint16_t robot, uint16_t current_target)
{
	uint32_t carry = 0;
	uint16_t u = 0;
	uint8_t animation_flags = 0;

	animation_flags = OBJECT(robot)->animation_flags;
	if ((animation_flags & 1u) == 0u)
		return current_target;
	u = burns_robot_start_walking(robot);
	burns_robot_choose_target(robot, u, &current_target, &carry);
	return current_target;
}

/* A lunge (form 2's first attack): slows, winds up, hits, walks on. */
uint16_t burns_robot_lunge(uint16_t robot, uint16_t y)
{
	uint8_t step = 0;

	step = OBJECT(robot)->burns_robot.step;
	switch ((int8_t)(uint8_t)((uint32_t)step << 1))
	{
	case 0:
		burns_robot_slow_down_step(robot);
		return y;
	case 2:
		burns_robot_wind_up(robot);
		return y;
	case -16:
	case 4:
		burns_robot_swing_hit(robot);
		return y;
	case -14:
	case 6:
		return burns_robot_walk_on(robot, y);
	case 8:
		burns_robot_part_attack_start(robot);
		return y;
	case 10:
		burns_robot_part_attack_raise(robot);
		return y;
	case 12:
		return burns_robot_part_attack_hold(robot, y);
	case 14:
		return burns_robot_part_attack_carry(robot, y);
	case 16:
		burns_robot_lob_aim(robot);
		return y;
	case 18:
		return burns_robot_lob_throw(robot, y);
	case 20:
		burns_robot_lob_recover(robot);
		return y;
	case 22:
		return burns_robot_lob_end(robot, y);
	}
	unreachable();
}

/* Slows to a quarter of its speed, then the next step. */
void burns_robot_slow_down_step(uint16_t robot)
{
	uint8_t step = 0;

	burns_robot_slow_down(robot);
	step = OBJECT(robot)->burns_robot.step;
	OBJECT(robot)->burns_robot.step = step + 1u;
}

/* Its held part (forms 2 and 3): raises it, holds it out in front for 64 frames while it walks, then
   walks on. */
uint16_t burns_robot_part_attack(uint16_t robot)
{
	uint8_t step = 0;

	step = OBJECT(robot)->burns_robot.step;
	switch ((int8_t)(uint8_t)((uint32_t)step << 1))
	{
	case 0:
		burns_robot_part_attack_start(robot);
		break;
	case 2:
		burns_robot_part_attack_raise(robot);
		break;
	case 4:
		burns_robot_part_attack_hold(robot, 0u);
		break;
	case 6:
		burns_robot_part_attack_carry(robot, 0u);
		break;
	case 8:
		burns_robot_lob_aim(robot);
		break;
	case 10:
		burns_robot_lob_throw(robot, 0u);
		break;
	case 12:
		burns_robot_lob_recover(robot);
		break;
	case 14:
		burns_robot_lob_end(robot, 0u);
		break;
	case -24:
	case -4:
		burns_robot_swing_hit(robot);
		break;
	case -22:
	case -2:
		burns_robot_walk_on(robot, 0u);
		break;
	case -8:
		burns_robot_slow_down_step(robot);
		break;
	case -6:
		burns_robot_wind_up(robot);
		break;
	}
	burns_robot_aim_at_target(robot);
	return burns_robot_steer(robot);
}

/* Takes its look for the held part's attack by form. */
void burns_robot_part_attack_start(uint16_t robot)
{
	uint16_t look = 0;
	uint8_t form_base = 0, form_extra = 0, step = 0;

	form_base = OBJECT(robot)->burns_robot.form_base;
	form_extra = OBJECT(robot)->burns_robot.form_extra;
	look = (uint32_t)(uint8_t)(((uint32_t)(form_base + form_extra) << 1) + 0x27u) << 8;
	burns_robot_set_look(robot, look);
	OBJECT(robot)->burns_robot.wait_frames = 0x20u;
	step = OBJECT(robot)->burns_robot.step;
	OBJECT(robot)->burns_robot.step = step + 1u;
}

/* When its animation ends, sound 11 and its holding look. */
void burns_robot_part_attack_raise(uint16_t robot)
{
	uint32_t carry = 0;
	uint16_t command = 0, look = 0;
	uint8_t animation_flags = 0, form_extra = 0, step = 0;

	animation_flags = OBJECT(robot)->animation_flags;
	if ((animation_flags & 1u) == 0u)
		return;
	command = 0x1100u;
	carry = vector_queue_sound(command);
	form_extra = OBJECT(robot)->burns_robot.form_extra;
	look = (uint32_t)(uint8_t)(0x30u + form_extra) << 8;
	burns_robot_set_look(robot, look);
	step = OBJECT(robot)->burns_robot.step;
	OBJECT(robot)->burns_robot.step = step + 1u;
}

/* At its frame holds out its part (4F80 type EA) in front of it, harmful, for 64 frames. */
uint16_t burns_robot_part_attack_hold(uint16_t robot, uint16_t y)
{
	uint32_t carry = 0;
	uint8_t list = 0, turned_part = 0;
	uint16_t box_number = 0, held_part = 0, object = 0, part_code = 0, self = 0;
	uint16_t stack = 0;
	uint8_t animation_flags = 0, action = 0, attributes = 0;

	animation_flags = OBJECT(robot)->animation_flags;
	if ((animation_flags & 2u) == 0u)
		return y;
	OBJECT(robot)->flags &= ~4u;
	list = 0u;
	vector_find_free_slot(list, &held_part, &carry);
	if (carry == 0u)
	{
		mem_write8(held_part, 0xC0u);
		mem_write16(held_part + 0x29u, robot);
		OBJECT(robot)->burns_robot.held_part = held_part;
		stack = robot;
		self = held_part;
		box_number = 0x1000u;
		burns_robot_set_box(self, box_number);
		object = stack;
		OBJECT(object)->action_step = 0x40u;
		OBJECT(object)->unk_43 = 1u;
		action = OBJECT(object)->action;
		OBJECT(object)->action = action + 1u;
		return y;
	}
	turned_part = 0xEu;
	attributes = OBJECT(robot)->attributes;
	if ((attributes & 0x40u) != 0u)
		turned_part -= 0x80u;
	part_code = (uint32_t)turned_part << 8;
	y = burns_robot_place_part(robot, held_part, part_code);
	mem_write8(held_part, 0xC0u);
	mem_write16(held_part + 0x29u, robot);
	OBJECT(robot)->burns_robot.held_part = held_part;
	stack = robot;
	self = held_part;
	box_number = 0x1000u;
	burns_robot_set_box(self, box_number);
	object = stack;
	OBJECT(object)->action_step = 0x40u;
	OBJECT(object)->unk_43 = 1u;
	action = OBJECT(object)->action;
	OBJECT(object)->action = action + 1u;
	return y;
}

/* Carries the held part along with its speeds; when the 64 frames are up lets go of it and walks at a
   target. */
uint16_t burns_robot_part_attack_carry(uint16_t robot, uint16_t current_target)
{
	uint32_t carry = 0;
	uint16_t part = 0, u = 0;
	uint8_t wait_frames = 0;
	uint16_t held_part = 0, x_speed = 0, y_speed = 0;

	held_part = OBJECT(robot)->burns_robot.held_part;
	part = held_part;
	x_speed = OBJECT(robot)->x_speed;
	OBJECT(part)->x_speed = x_speed;
	y_speed = OBJECT(robot)->y_speed;
	OBJECT(part)->y_speed = y_speed;
	wait_frames = OBJECT(robot)->burns_robot.wait_frames;
	OBJECT(robot)->burns_robot.wait_frames = wait_frames - 1u;
	if (wait_frames != 1u)
		return current_target;
	OBJECT(robot)->burns_robot.holding_part = 0u;
	u = burns_robot_start_walking(robot);
	burns_robot_choose_target(robot, u, &current_target, &carry);
	return current_target;
}

/* Lobs bombs (the tables' shots: 4D40 type 26): aims, throws, recovers; form 4 throws three. */
uint16_t burns_robot_lob_bombs(uint16_t robot, uint16_t y)
{
	uint8_t step = 0;

	step = OBJECT(robot)->burns_robot.step;
	switch ((int8_t)(uint8_t)((uint32_t)step << 1))
	{
	case 0:
		burns_robot_lob_aim(robot);
		return y;
	case 2:
		return burns_robot_lob_throw(robot, y);
	case 4:
		burns_robot_lob_recover(robot);
		return y;
	case 6:
		return burns_robot_lob_end(robot, y);
	case -32:
	case -12:
		burns_robot_swing_hit(robot);
		return y;
	case -30:
	case -10:
		return burns_robot_walk_on(robot, y);
	case -16:
		burns_robot_slow_down_step(robot);
		return y;
	case -14:
		burns_robot_wind_up(robot);
		return y;
	case -8:
		burns_robot_part_attack_start(robot);
		return y;
	case -6:
		burns_robot_part_attack_raise(robot);
		return y;
	case -4:
		return burns_robot_part_attack_hold(robot, y);
	case -2:
		return burns_robot_part_attack_carry(robot, y);
	}
	unreachable();
}

/* Takes its throwing look by form, slowing (forms 2-4) or stopping. */
void burns_robot_lob_aim(uint16_t robot)
{
	uint16_t look = 0;
	uint8_t form_base = 0, form_extra = 0, step = 0, form_base_2 = 0;

	form_base = OBJECT(robot)->burns_robot.form_base;
	form_extra = OBJECT(robot)->burns_robot.form_extra;
	look = (uint32_t)(uint8_t)(((uint32_t)(form_base + form_extra) << 1) + 0x1Cu) << 8;
	burns_robot_set_look(robot, look);
	step = OBJECT(robot)->burns_robot.step;
	OBJECT(robot)->burns_robot.step = step + 1u;
	form_base_2 = OBJECT(robot)->burns_robot.form_base;
	if (form_base_2 == 2u)
	{
		burns_robot_slow_down(robot);
		return;
	}
	burns_robot_stop(robot);
}

/* At its frame throws a bomb (4D40 type 26) at x speed 0200 the way it faces, its y speed by the count
   of bombs thrown. */
uint16_t burns_robot_lob_throw(uint16_t robot, uint16_t y)
{
	uint32_t carry = 0;
	uint8_t facing = 0, list = 0, turned_part = 0;
	uint16_t bomb = 0, part_code = 0;
	uint8_t animation_flags = 0, step = 0, attributes = 0, form_base = 0, form_extra = 0, bombs_lobbed = 0;
	uint16_t t1 = 0, t2 = 0;

	animation_flags = OBJECT(robot)->animation_flags;
	if ((animation_flags & 2u) == 0u)
		return y;
	list = 2u;
	vector_find_free_slot(list, &bomb, &carry);
	if (carry == 0u)
	{
		step = OBJECT(robot)->burns_robot.step;
		OBJECT(robot)->burns_robot.step = step + 1u;
		return y;
	}
	OBJECT(bomb)->flags = 0xC8u;
	lob_speed = 0x200;
	turned_part = 9u;
	attributes = OBJECT(robot)->attributes;
	facing = attributes & 0x40u;
	OBJECT(bomb)->attributes = facing;
	if (facing != 0u)
	{
		turned_part -= 0x80u;
		lob_speed = 0u - lob_speed;
	}
	form_base = OBJECT(robot)->burns_robot.form_base;
	form_extra = OBJECT(robot)->burns_robot.form_extra;
	part_code = 2u | ((uint32_t)(uint8_t)(turned_part + form_base + form_extra) << 8);
	burns_robot_place_part(robot, bomb, part_code);
	t1 = lob_speed;
	OBJECT(bomb)->x_speed = t1;
	y = burns_robot_shot_y_speeds_ADDRESS;
	bombs_lobbed = OBJECT(robot)->burns_robot.bombs_lobbed;
	t2 = burns_robot_shot_y_speeds[(int8_t)((uint8_t)((uint32_t)bombs_lobbed << 1)) / 2];
	OBJECT(bomb)->y_speed = t2;
	step = OBJECT(robot)->burns_robot.step;
	OBJECT(robot)->burns_robot.step = step + 1u;
	return y;
}

/* When its animation ends, its look after the throw. */
void burns_robot_lob_recover(uint16_t robot)
{
	uint16_t look = 0;
	uint8_t animation_flags = 0, form_base = 0, form_extra = 0, step = 0;

	animation_flags = OBJECT(robot)->animation_flags;
	if ((animation_flags & 1u) == 0u)
		return;
	form_base = OBJECT(robot)->burns_robot.form_base;
	form_extra = OBJECT(robot)->burns_robot.form_extra;
	look = (uint32_t)(uint8_t)(((uint32_t)(form_base + form_extra) << 1) + 0x1Du) << 8;
	burns_robot_set_look(robot, look);
	step = OBJECT(robot)->burns_robot.step;
	OBJECT(robot)->burns_robot.step = step + 1u;
}

/* When its animation ends, form 4 throws again up to three bombs; then walks at a target. */
uint16_t burns_robot_lob_end(uint16_t robot, uint16_t current_target)
{
	uint32_t carry = 0;
	uint16_t u = 0;
	uint8_t animation_flags = 0, form_base = 0, form_extra = 0, bombs_lobbed = 0, bombs_lobbed_2 = 0;

	animation_flags = OBJECT(robot)->animation_flags;
	if ((animation_flags & 1u) == 0u)
		return current_target;
	form_base = OBJECT(robot)->burns_robot.form_base;
	form_extra = OBJECT(robot)->burns_robot.form_extra;
	if ((uint8_t)(form_base + form_extra) == 4u)
	{
		bombs_lobbed = OBJECT(robot)->burns_robot.bombs_lobbed;
		OBJECT(robot)->burns_robot.bombs_lobbed = bombs_lobbed + 1u;
		bombs_lobbed_2 = OBJECT(robot)->burns_robot.bombs_lobbed;
		if ((int8_t)bombs_lobbed_2 < 3)
		{
			OBJECT(robot)->burns_robot.step = 0u;
			return current_target;
		}
	}
	u = burns_robot_start_walking(robot);
	burns_robot_choose_target(robot, u, &current_target, &carry);
	return current_target;
}

/* Gloating with no target (a player down or none to go for): waits for a player, then walks on. */
uint16_t burns_robot_gloat(uint16_t robot, uint16_t y)
{
	uint8_t step = 0;

	step = OBJECT(robot)->burns_robot.step;
	switch ((int8_t)(uint8_t)((uint32_t)step << 1))
	{
	case 0:
		burns_robot_gloat_until_player(robot);
		return y;
	case 2:
		return burns_robot_gloat_end(robot, y);
	}
	unreachable();
}

/* Stands (but in forms 2-4) until there is a player to go for, then can be hit again and waits 32
   frames. */
void burns_robot_gloat_until_player(uint16_t robot)
{
	uint32_t carry = 0;
	uint16_t ignored16 = 0, ignored16_2 = 0;
	uint8_t form_base = 0, step = 0;

	form_base = OBJECT(robot)->burns_robot.form_base;
	if (form_base != 2u)
		burns_robot_stop(robot);
	find_nearest_player(robot, &ignored16, &ignored16_2, &carry);
	if (carry)
	{
		OBJECT(robot)->flags |= 0x40u;
		OBJECT(robot)->burns_robot.wait_frames = 0x20u;
		step = OBJECT(robot)->burns_robot.step;
		OBJECT(robot)->burns_robot.step = step + 1u;
	}
}

/* After 32 frames walks at a target. */
uint16_t burns_robot_gloat_end(uint16_t robot, uint16_t current_target)
{
	uint32_t carry = 0;
	uint16_t u = 0;
	uint8_t wait_frames = 0;

	wait_frames = OBJECT(robot)->burns_robot.wait_frames;
	OBJECT(robot)->burns_robot.wait_frames = wait_frames - 1u;
	if (wait_frames != 1u)
		return current_target;
	u = burns_robot_start_walking(robot);
	burns_robot_choose_target(robot, u, &current_target, &carry);
	return current_target;
}

/* When a player's blow hits it, lets go of its held part and takes the blow. */
void burns_robot_check_hit(uint16_t robot)
{
	uint32_t negative = 0;
	uint8_t hit = 0;

	if ((OBJECT(robot)->flags & 0x20u) != 0u)
	{
		hit = OBJECT(robot)->hit;
		negative = hit >> 7;
		if (hit != 0u && negative == 0u)
		{
			OBJECT(robot)->burns_robot.holding_part = 0u;
			burns_robot_take_hit(robot);
		}
	}
}

/* Form 0: facing its target, lobs bombs when they are due and it is in the middle, else attacks a target
   in reach (its second attack by chance); carry when it does. */
void burns_robot_decide_form_0(uint16_t robot, uint16_t *p_y, uint16_t *p_target, uint32_t *p_carry)
{
	uint16_t y = (uint16_t)*p_y;
	uint32_t carry = *p_carry;
	uint16_t target = 0;

	burns_robot_facing_target(robot, &target, &carry);
	if (carry == 0u)
		carry = 0u;
	else
	{
		burns_robot_lob_due(robot, &y, &carry);
		if (carry == 0u)
		{
			reach_x = 0x58;
			reach_y = 0x12;
			burns_robot_target_in_reach(robot, &target, &carry);
			if (carry == 0u)
				carry = 0u;
			else if (random_number < burns_robot_second_attack_chances_by_players[(int8_t)((uint8_t)(player_count - 1u))])
			{
				chosen_attack = 1u;
				burns_robot_start_attack(robot, &target, &carry);
			}
			else
			{
				chosen_attack = 0u;
				burns_robot_start_attack(robot, &target, &carry);
			}
		}
		else
		{
			carry = burns_robot_in_middle(robot);
			if (carry)
				carry = burns_robot_start_lob(robot);
			else
			{
				reach_x = 0x58;
				reach_y = 0x12;
				burns_robot_target_in_reach(robot, &target, &carry);
				if (carry == 0u)
					carry = 0u;
				else if (random_number < burns_robot_second_attack_chances_by_players[(int8_t)((uint8_t)(player_count - 1u))])
				{
					chosen_attack = 1u;
					burns_robot_start_attack(robot, &target, &carry);
				}
				else
				{
					chosen_attack = 0u;
					burns_robot_start_attack(robot, &target, &carry);
				}
			}
		}
	}
	*p_y = y;
	*p_target = target;
	*p_carry = carry;
}

/* Form 1: as form 0, and fires a volley at a target in line across but further back once 128 frames have
   passed since the last. */
void burns_robot_decide_form_1(uint16_t robot, uint16_t *p_y, uint16_t *p_target, uint32_t *p_carry)
{
	uint16_t y = (uint16_t)*p_y;
	uint32_t carry = *p_carry;
	uint16_t look = 0, target = 0;
	uint16_t target_player = 0, volley_frames = 0;

	burns_robot_facing_target(robot, &target, &carry);
	if (carry == 0u)
		carry = 0u;
	else
	{
		target_player = OBJECT(robot)->burns_robot.target_player;
		target = target_player;
		burns_robot_lob_due(robot, &y, &carry);
		if (carry)
		{
			carry = burns_robot_in_middle(robot);
			if (carry)
			{
				carry = burns_robot_start_lob(robot);
				*p_y = y;
				*p_target = target;
				*p_carry = carry;
				return;
			}
		}
		reach_x = 0x58;
		carry = burns_robot_target_across(robot, target);
		if (carry == 0u)
		{
			volley_frames = OBJECT(robot)->burns_robot.volley_frames;
			if ((int16_t)volley_frames < 0x80)
				carry = 0u;
			else
			{
				reach_y = 0x22;
				carry = burns_robot_target_in_depth(robot, target);
				if (carry == 0u)
					carry = 0u;
				else
				{
					carry = burns_robot_in_middle(robot);
					if (carry)
					{
						burns_robot_face_target(robot);
						OBJECT(robot)->flags |= 4u;
						OBJECT(robot)->burns_robot.attack_choice = 1u;
						OBJECT(robot)->burns_robot.volley_frames = 0u;
						OBJECT(robot)->burns_robot.wait_frames = 0u;
						OBJECT(robot)->burns_robot.shots_fired = 0u;
						look = 0x2900u;
						burns_robot_set_look(robot, look);
						OBJECT(robot)->state = 9u;
						OBJECT(robot)->burns_robot.step = 0u;
						carry = 1u;
					}
					else
						carry = 0u;
				}
			}
		}
		else
		{
			reach_y = 0x12;
			burns_robot_target_in_reach(robot, &target, &carry);
			if (carry)
			{
				chosen_attack = 0u;
				*p_target = target;
				burns_robot_start_attack(robot, p_target, &carry);
				*p_y = y;
				*p_carry = carry;
				return;
			}
			carry = 0u;
		}
	}
	*p_y = y;
	*p_target = target;
	*p_carry = carry;
}

/* Forms 2-4: as form 0, and holds out its part when burns_robot_held_part_times have passed (not form
   4). */
void burns_robot_decide_late_forms(uint16_t robot, uint16_t *p_y, uint16_t *p_target, uint32_t *p_carry)
{
	uint16_t y = (uint16_t)*p_y;
	uint32_t carry = *p_carry;
	uint16_t target = 0;
	uint8_t form_extra = 0, form_extra_2 = 0;
	uint16_t t1 = 0, part_frames = 0;

	burns_robot_facing_target(robot, &target, &carry);
	if (carry == 0u)
		carry = 0u;
	else
	{
		burns_robot_lob_due(robot, &y, &carry);
		if (carry == 0u)
		{
			reach_x = 0x58;
			reach_y = 0x12;
			burns_robot_target_in_reach(robot, &target, &carry);
			if (carry == 0u)
			{
				form_extra = OBJECT(robot)->burns_robot.form_extra;
				if (form_extra == 2u)
					carry = 0u;
				else
				{
					y = burns_robot_held_part_times_ADDRESS;
					form_extra_2 = OBJECT(robot)->burns_robot.form_extra;
					t1 = burns_robot_held_part_times[(((((uint32_t)form_extra_2 << 1) << 1) + rank) & 0x1Eu) / 2u];
					part_frames = OBJECT(robot)->burns_robot.part_frames;
					if ((int16_t)t1 <= (int16_t)part_frames)
					{
						OBJECT(robot)->burns_robot.part_frames = 0u;
						if (player_count >= 3u)
							OBJECT(robot)->flags |= 4u;
						OBJECT(robot)->burns_robot.wait_frames = 0u;
						OBJECT(robot)->state = 0xBu;
						carry = 0u;
						OBJECT(robot)->burns_robot.step = 0u;
					}
					else
						carry = 0u;
				}
			}
			else
			{
				chosen_attack = 0u;
				burns_robot_start_attack(robot, &target, &carry);
			}
		}
		else
		{
			carry = burns_robot_in_middle(robot);
			if (carry)
				carry = burns_robot_start_lob(robot);
			else
			{
				reach_x = 0x58;
				reach_y = 0x12;
				burns_robot_target_in_reach(robot, &target, &carry);
				if (carry == 0u)
				{
					form_extra = OBJECT(robot)->burns_robot.form_extra;
					if (form_extra == 2u)
						carry = 0u;
					else
					{
						y = burns_robot_held_part_times_ADDRESS;
						form_extra_2 = OBJECT(robot)->burns_robot.form_extra;
						t1 = burns_robot_held_part_times[(((((uint32_t)form_extra_2 << 1) << 1) + rank) & 0x1Eu) / 2u];
						part_frames = OBJECT(robot)->burns_robot.part_frames;
						if ((int16_t)t1 <= (int16_t)part_frames)
						{
							OBJECT(robot)->burns_robot.part_frames = 0u;
							if (player_count >= 3u)
								OBJECT(robot)->flags |= 4u;
							OBJECT(robot)->burns_robot.wait_frames = 0u;
							OBJECT(robot)->state = 0xBu;
							carry = 0u;
							OBJECT(robot)->burns_robot.step = 0u;
						}
						else
							carry = 0u;
					}
				}
				else
				{
					chosen_attack = 0u;
					burns_robot_start_attack(robot, &target, &carry);
				}
			}
		}
	}
	*p_y = y;
	*p_target = target;
	*p_carry = carry;
}

/* Carry when it faces its target. */
void burns_robot_facing_target(uint16_t robot, uint16_t *p_target, uint32_t *p_carry)
{
	uint32_t carry = *p_carry;
	uint16_t target = 0;
	uint8_t attributes = 0, attributes_2 = 0;
	uint16_t target_player = 0, t1 = 0, t2 = 0;

	target_player = OBJECT(robot)->burns_robot.target_player;
	target = target_player;
	t1 = OBJECT(robot)->x;
	t2 = OBJECT(target)->x;
	if ((int16_t)t1 < (int16_t)t2)
	{
		attributes = OBJECT(robot)->attributes;
		if ((attributes & 0x40u) != 0u)
			carry = 0u;
		else
			carry = 1u;
	}
	else
	{
		attributes_2 = OBJECT(robot)->attributes;
		if ((attributes_2 & 0x40u) == 0u)
			carry = 0u;
		else
			carry = 1u;
	}
	*p_target = target;
	*p_carry = carry;
}

/* Walks in its walking direction at its form's speed for the rank, facing it. */
uint16_t burns_robot_walk(uint16_t robot)
{
	uint16_t heading = 0, speeds = 0;
	uint8_t walk_direction = 0, form_base = 0, form_extra = 0;

	walk_direction = OBJECT(robot)->burns_robot.walk_direction;
	form_base = OBJECT(robot)->burns_robot.form_base;
	form_extra = OBJECT(robot)->burns_robot.form_extra;
	speeds = burns_robot_walk_speeds[(int8_t)((uint8_t)((uint32_t)(form_base + form_extra) << 1)) / 2];
	heading = ((uint32_t)walk_direction << 8) | WALK_SPEED(speeds + (rank >> 1));
	vector_set_speed_by_direction(robot, heading);
	burns_robot_face_target(robot);
	return speeds;
}

/* Keeps its target for 64 frames, taking the player 07D2AB finds when the target is gone or down; with
   none it gloats (carry). */
void burns_robot_choose_target(uint16_t robot, uint16_t target_player, uint16_t *p_current_target, uint32_t *p_carry)
{
	uint16_t current_target = (uint16_t)*p_current_target;
	uint32_t carry = *p_carry;
	uint16_t ignored16 = 0;
	uint8_t t1 = 0, target_frames = 0, target_frames_2 = 0;
	uint16_t target_player_2 = 0;

	find_nearest_player(robot, &target_player, &ignored16, &carry);
	if (carry == 0u)
		carry = burns_robot_start_gloating(robot);
	else
	{
		target_player_2 = OBJECT(robot)->burns_robot.target_player;
		current_target = target_player_2;
		if (mem_read8(current_target) == 0u)
		{
			OBJECT(robot)->burns_robot.target_frames = 0x40u;
			OBJECT(robot)->burns_robot.target_player = target_player;
			carry = 0u;
		}
		else
		{
			t1 = mem_read8(current_target + 2u);
			if ((int8_t)t1 < 0)
			{
				OBJECT(robot)->burns_robot.target_frames = 0x40u;
				OBJECT(robot)->burns_robot.target_player = target_player;
				carry = 0u;
			}
			else
			{
				target_frames = OBJECT(robot)->burns_robot.target_frames;
				if (target_frames == 0u)
				{
					OBJECT(robot)->burns_robot.target_frames = 0x40u;
					OBJECT(robot)->burns_robot.target_player = target_player;
					carry = 0u;
				}
				else
				{
					target_frames_2 = OBJECT(robot)->burns_robot.target_frames;
					OBJECT(robot)->burns_robot.target_frames = target_frames_2 - 1u;
					carry = 0u;
				}
			}
		}
	}
	*p_current_target = current_target;
	*p_carry = carry;
}

/* Aims at the place beside its target on its own side (the other side when that is a wall), and notes
   the direction to the target. */
void burns_robot_aim_at_target(uint16_t robot)
{
	uint32_t negative = 0;
	uint8_t a = 0, cell = 0, direction = 0, side = 0, target_dy = 0;
	uint16_t d = 0, direction_to_target = 0, object = 0, target = 0;
	uint8_t stack_3 = 0;
	uint16_t stack = 0;
	uint16_t target_player = 0, t1 = 0, t2 = 0;

	target_player = OBJECT(robot)->burns_robot.target_player;
	target = target_player;
	t1 = OBJECT(robot)->x;
	t2 = OBJECT(target)->x;
	if ((int16_t)t2 < (int16_t)t1)
		side = 0x40u;
	else
		side = 0xC0u;
	stack = robot;
	stack_3 = side;
	object = target;
	d = (uint32_t)(uint16_t)(((uint32_t)a << 8) | side) << 8;
	vector_floor_at_offset(object, &d, &negative);
	cell = (uint8_t)(d >> 8);
	if ((int8_t)cell < 0)
		stack_3 = 0u - stack_3;
	object = stack;
	d = stack_3;
	d = vector_direction_to_offset(object, target, d);
	direction = (uint8_t)(d >> 8);
	OBJECT(object)->target_dx = (OBJECT(object)->target_dx & 0xFF00u) | (direction & 0xFFu);
	direction_to_target = vector_direction_to(object, target);
	target_dy = (uint8_t)(direction_to_target >> 8);
	OBJECT(object)->target_dy = (OBJECT(object)->target_dy & 0xFFu) | ((target_dy & 0xFFu) << 8u);
}

/* Faces left or right by the direction to its target. */
void burns_robot_face_target(uint16_t robot)
{
	uint8_t target_heading = 0, attributes = 0, attributes_2 = 0;

	target_heading = OBJECT(robot)->burns_robot.target_heading;
	if ((uint8_t)(target_heading + 0x40u) >= 0x80u)
	{
		attributes = OBJECT(robot)->attributes;
		OBJECT(robot)->attributes = attributes | 0x40u;
		return;
	}
	attributes_2 = OBJECT(robot)->attributes;
	OBJECT(robot)->attributes = attributes_2 & 0xBFu;
}

/* Takes look A of burns_robot_animations: its kind and animation. */
uint16_t burns_robot_set_look(uint16_t robot, uint16_t look)
{
	uint8_t look_animation = 0, look_kind = 0;
	uint16_t t1 = 0;
	uint32_t kind_halfword = 0;

	t1 = burns_robot_animations[(int8_t)((uint8_t)((uint32_t)(look >> 8) << 1)) / 2];
	look_kind = (uint8_t)(t1 >> 8);
	look_animation = t1 | 0x80u;
	kind_halfword = ((uint32_t)look_kind << 8) | look_animation;
	OBJECT(robot)->kind = (uint8_t)(kind_halfword >> 8u);
	OBJECT(robot)->animation = (uint8_t)kind_halfword;
	look = ((uint32_t)look_kind << 8) | look_animation;
	return look;
}

/* Takes box A of burns_robot_hit_boxes: its hit, sizes and offsets. */
uint16_t burns_robot_set_box(uint16_t self, uint16_t box_number)
{
	uint16_t field_1c = 0, u = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0, t4 = 0;
	uint32_t box_width_halfword = 0, box_height_halfword = 0, box_dy_halfword = 0;

	t1 = TABLE16(burns_robot_hit_boxes, (int8_t)((uint16_t)((uint32_t)(uint8_t)((uint32_t)(box_number >> 8) << 1) << 8) >> 8));
	field_1c = HIT_BOX(t1)->field_1c;
	OBJECT(self)->damage = (uint8_t)(field_1c >> 8u);
	OBJECT(self)->attack = (uint8_t)field_1c;
	t2 = t1 + 2u;
	box_width_halfword = HIT_BOX(t2 - 0x2u)->field_1f;
	OBJECT(self)->box_width = (uint8_t)(box_width_halfword >> 8u);
	OBJECT(self)->box_depth = (uint8_t)box_width_halfword;
	t3 = t2 + 2u;
	box_height_halfword = HIT_BOX(t3 - 0x4u)->field_21;
	OBJECT(self)->box_height = (uint8_t)(box_height_halfword >> 8u);
	OBJECT(self)->box_dx = (uint8_t)box_height_halfword;
	t4 = t3 + 2u;
	u = t4 + 2u;
	box_dy_halfword = HIT_BOX(t4 - 0x6u)->field_23;
	OBJECT(self)->box_dy = (uint8_t)(box_dy_halfword >> 8u);
	OBJECT(self)->box_dz = (uint8_t)box_dy_halfword;
	return u;
}

/* Carry when its target is within F8 across and up to FA further down the screen. */
void burns_robot_target_in_reach(uint16_t robot, uint16_t *p_target, uint32_t *p_carry)
{
	uint32_t carry = *p_carry;
	uint16_t target = 0;
	uint16_t target_player = 0;

	target_player = OBJECT(robot)->burns_robot.target_player;
	target = target_player;
	carry = burns_robot_target_across(robot, target);
	if (carry == 0u)
		carry = 0u;
	else
		carry = burns_robot_target_in_depth(robot, target);
	*p_target = target;
	*p_carry = carry;
}

/* Carry when U is up to FA further down the screen than it. */
uint32_t burns_robot_target_in_depth(uint16_t robot, uint16_t target)
{
	uint32_t carry = 0;
	uint16_t depth = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0;

	t1 = OBJECT(target)->y;
	t2 = OBJECT(robot)->y;
	t3 = t1 - t2;
	depth = t3;
	if ((int16_t)t3 < 0 || reach_y < (int16_t)depth)
	{
		carry = 0u;
		return carry;
	}
	carry = 1u;
	return carry;
}

/* Carry when U is within F8 across. */
uint32_t burns_robot_target_across(uint16_t robot, uint16_t target)
{
	uint32_t carry = 0;
	uint16_t across = 0;
	uint16_t t1 = 0, t2 = 0;

	t1 = OBJECT(robot)->x;
	t2 = OBJECT(target)->x;
	across = t1 - t2;
	if (reach_x < (int16_t)(across >> 15 ? 0u - across : across))
	{
		carry = 0u;
		return carry;
	}
	carry = 1u;
	return carry;
}

/* Back to walking: can be hit and hurt, its body's box, its form's walking handler. */
uint16_t burns_robot_start_walking(uint16_t robot)
{
	uint16_t box_number = 0, u = 0;
	uint8_t form_base = 0, form_base_2 = 0;

	OBJECT(robot)->flags = (OBJECT(robot)->flags | 0x40u) & ~4u;
	form_base = OBJECT(robot)->burns_robot.form_base;
	box_number = (uint32_t)form_base << 8;
	u = burns_robot_set_box(robot, box_number);
	form_base_2 = OBJECT(robot)->burns_robot.form_base;
	OBJECT(robot)->state = 1u + form_base_2;
	OBJECT(robot)->burns_robot.step = 0u;
	OBJECT(robot)->burns_robot.wait_frames = 0u;
	return u;
}

/* Mr. Burns gloats (voice 3F38): handler 0D with its gloating look; it can not be hit meanwhile. */
uint32_t burns_robot_start_gloating(uint16_t robot)
{
	uint32_t carry = 0;
	uint16_t command = 0, look = 0;
	uint8_t form_base = 0, form_extra = 0;

	command = 0x3F38u;
	carry = vector_queue_sound(command);
	OBJECT(robot)->state = 0xDu;
	OBJECT(robot)->burns_robot.step = 0u;
	form_base = OBJECT(robot)->burns_robot.form_base;
	form_extra = OBJECT(robot)->burns_robot.form_extra;
	look = 0x38u | ((uint32_t)(uint8_t)(0xFu + form_base + form_extra) << 8);
	burns_robot_set_look(robot, look);
	OBJECT(robot)->flags &= 0xBFu;
	carry = 1u;
	return carry;
}

/* Takes a blow: a spark on the player, sound 66, no box; at or below its form's beaten health for the
   players in the game its form breaks, else it is hurt. */
void burns_robot_take_hit(uint16_t robot)
{
	uint32_t carry = 0;
	uint16_t box_number = 0, command = 0, object = 0;
	uint8_t form_base = 0, form_base_2 = 0, form_extra = 0, vitality = 0, shadow_player = 0, form_base_3 = 0, form_extra_2 = 0;
	uint16_t hit_by = 0, hit_by_2 = 0;

	hit_by = OBJECT(robot)->hit_by;
	object = hit_by;
	OBJECT(object)->behaviour = (OBJECT(object)->behaviour & 0xFFu) | 0x100u;
	AT16(OBJECT(object)->hit_box, -1) = robot;
	OBJECT(robot)->flags &= 0xBBu;
	form_base = OBJECT(robot)->burns_robot.form_base;
	if (form_base != 2u)
		burns_robot_stop(robot);
	command = 0x6600u;
	carry = vector_queue_sound(command);
	box_number = 0u;
	burns_robot_set_box(robot, box_number);
	form_base_2 = OBJECT(robot)->burns_robot.form_base;
	form_extra = OBJECT(robot)->burns_robot.form_extra;
	vitality = OBJECT(robot)->vitality;
	if (BEATEN_HEALTH(burns_robot_beaten_healths[(int8_t)((uint8_t)((uint32_t)(form_base_2 + form_extra) << 1)) / 2] + ((int8_t)(player_count - 1u))) < vitality)
	{
		OBJECT(robot)->state = 0xFFu;
		OBJECT(robot)->burns_robot.step = 0u;
		return;
	}
	hit_by_2 = OBJECT(robot)->hit_by;
	shadow_player = OBJECT(hit_by_2)->shadow_player;
	OBJECT(robot)->points = shadow_player & ~0xFu;
	OBJECT(robot)->flags &= 0xBFu;
	form_base_3 = OBJECT(robot)->burns_robot.form_base;
	form_extra_2 = OBJECT(robot)->burns_robot.form_extra;
	OBJECT(robot)->state = 0xFEu - form_base_3 - form_extra_2;
	OBJECT(robot)->burns_robot.step = 0u;
}

/* Starts attack F0 of its form (handler 6 + 2 x form base + it), at once by chance or after hurt, else
   after a 32-frame wait; gloats when its target is down. */
void burns_robot_start_attack(uint16_t robot, uint16_t *p_object, uint32_t *p_carry)
{
	uint32_t carry = *p_carry;
	uint16_t look = 0, target = 0;
	uint8_t state = 0, form_base = 0, attack_choice = 0, form_base_2 = 0, form_extra = 0, form_extra_2 = 0, form_base_3 = 0, vitality = 0, health_mark = 0, vitality_2 = 0;
	uint16_t target_player = 0;

	OBJECT(robot)->burns_robot.attack_choice = chosen_attack;
	target_player = OBJECT(robot)->burns_robot.target_player;
	target = target_player;
	state = OBJECT(target)->state;
	if ((int8_t)state < 0)
		carry = burns_robot_start_gloating(robot);
	else
	{
		form_base = OBJECT(robot)->burns_robot.form_base;
		attack_choice = OBJECT(robot)->burns_robot.attack_choice;
		OBJECT(robot)->state = ((uint32_t)form_base << 1) + attack_choice + 6u;
		form_base_2 = OBJECT(robot)->burns_robot.form_base;
		form_extra = OBJECT(robot)->burns_robot.form_extra;
		look = (uint32_t)(uint8_t)(form_base_2 + form_extra) << 8;
		burns_robot_set_look(robot, look);
		OBJECT(robot)->burns_robot.step = 0u;
		OBJECT(robot)->burns_robot.wait_frames = 0u;
		form_extra_2 = OBJECT(robot)->burns_robot.form_extra;
		form_base_3 = OBJECT(robot)->burns_robot.form_base;
		target = burns_robot_quick_attack_chances[(int8_t)((uint8_t)((uint32_t)(form_extra_2 + form_base_3) << 1)) / 2];
		if (random_number < QUICK_ATTACK_CHANCE(target + ((int8_t)(player_count - 1u))))
		{
			vitality = OBJECT(robot)->vitality;
			OBJECT(robot)->burns_robot.health_mark = vitality;
			carry = 1u;
		}
		else
		{
			health_mark = OBJECT(robot)->burns_robot.health_mark;
			vitality_2 = OBJECT(robot)->vitality;
			if ((uint8_t)(health_mark - vitality_2) > 0xCu)
			{
				vitality = OBJECT(robot)->vitality;
				OBJECT(robot)->burns_robot.health_mark = vitality;
				carry = 1u;
			}
			else
			{
				OBJECT(robot)->burns_robot.wait_frames = 0x20u;
				carry = 1u;
			}
		}
	}
	*p_object = target;
	*p_carry = carry;
}

/* Starts lobbing bombs (handler 0C), facing its target, safe meanwhile. */
uint32_t burns_robot_start_lob(uint16_t robot)
{
	uint32_t carry = 0;

	OBJECT(robot)->burns_robot.lob_frames = 0u;
	OBJECT(robot)->burns_robot.bombs_lobbed = 0u;
	OBJECT(robot)->burns_robot.wait_frames = 0u;
	burns_robot_face_target(robot);
	OBJECT(robot)->flags |= 4u;
	OBJECT(robot)->state = 0xCu;
	OBJECT(robot)->burns_robot.step = 0u;
	carry = 1u;
	return carry;
}

/* Stops: no x, y or height speed. */
void burns_robot_stop(uint16_t self)
{
	OBJECT(self)->x_speed = 0;
	OBJECT(self)->y_speed = 0;
	OBJECT(self)->z_speed = 0;
}

/* Slows to a quarter of its x and y speeds. */
void burns_robot_slow_down(uint16_t robot)
{
	uint32_t carry = 0;
	uint8_t a = 0, b = 0;
	uint16_t x_speed = 0, y_speed = 0;

	x_speed = OBJECT(robot)->x_speed;
	a = (uint8_t)(x_speed >> 8);
	carry = a & 1u;
	a = (int8_t)a >> 1;
	b = ((uint8_t)x_speed >> 1) | (carry << 7);
	carry = a & 1u;
	OBJECT(robot)->x_speed = ((uint32_t)(uint8_t)((int8_t)a >> 1) << 8) | (uint8_t)((b >> 1) | (carry << 7));
	y_speed = OBJECT(robot)->y_speed;
	a = (uint8_t)(y_speed >> 8);
	carry = a & 1u;
	a = (int8_t)a >> 1;
	b = ((uint8_t)y_speed >> 1) | (carry << 7);
	carry = a & 1u;
	OBJECT(robot)->y_speed = ((uint32_t)(uint8_t)((int8_t)a >> 1) << 8) | (uint8_t)((b >> 1) | (carry << 7));
}

/* Sets up the new object U as part A of object_1d_parts at the robot's place (turned round when A has
   bit 7): its offsets, type, kind and animation. */
uint16_t burns_robot_place_part(uint16_t self, uint16_t part, uint16_t part_code)
{
	uint8_t a = 0, b = 0, part_number = 0;
	uint16_t part_2 = 0;
	uint16_t t1 = 0, t2 = 0, dy = 0, t3 = 0, t4 = 0, t5 = 0, dz = 0, z = 0, t6 = 0, t7 = 0, kind = 0, t8 = 0, t9 = 0, t10 = 0, t11 = 0;

	part_number = (uint8_t)(part_code >> 8);
	part_dx &= 0xFFu;
	placed_part_number = part_number;
	if ((int8_t)part_number < 0)
	{
		OBJECT(part)->attributes = 0x40u;
		part_number &= 0x7Fu;
	}
	t1 = object_1d_parts_ADDRESS + (int8_t)((((uint32_t)part_number << 1) << 1) << 1);
	part_dx_low = PART(t1)->dx;
	t2 = t1 + 1u;
	dy = PART(t2 - 0x1u)->dy;
	t3 = OBJECT(self)->y;
	t4 = dy + t3;
	OBJECT(part)->y = t4;
	t5 = t2 + 1u;
	dz = PART(t5 - 0x2u)->dz;
	z = OBJECT(self)->z;
	t6 = dz + z;
	OBJECT(part)->z = t6;
	t7 = t5 + 1u;
	part_2 = t7 + 1u;
	OBJECT(part)->type = PART(t7 - 0x3u)->type;
	kind = (((uint32_t)PART(part_2 - 0x4u)->kind << 8u) | PART(part_2 - 0x4u)->animation);
	OBJECT(part)->kind = (uint8_t)(kind >> 8u);
	OBJECT(part)->animation = (uint8_t)kind;
	t8 = part_dx;
	a = (uint8_t)(t8 >> 8);
	b = (uint8_t)t8;
	if ((int8_t)placed_part_number < 0)
	{
		t9 = 0u - (((uint32_t)a << 8) | b);
		a = (uint8_t)(t9 >> 8);
		b = (uint8_t)t9;
	}
	t10 = OBJECT(self)->x;
	t11 = (((uint32_t)a << 8) | b) + t10;
	OBJECT(part)->x = t11;
	return part_2;
}

/* Carry when its x is within 40-180. */
uint32_t burns_robot_in_middle(uint16_t robot)
{
	uint32_t carry = 0;
	uint8_t a = 0, d = 0;
	uint16_t t1 = 0;

	t1 = OBJECT(robot)->x;
	d = (uint8_t)t1;
	a = (uint8_t)(t1 >> 8);
	if ((int16_t)(((uint32_t)a << 8) | (d & 0xFFu)) < 0x40 || (int16_t)(((uint32_t)a << 8) | (d & 0xFFu)) > 0x180)
	{
		carry = 0u;
		return carry;
	}
	carry = 1u;
	return carry;
}

/* Carry when the frames since its last bombs pass burns_robot_shot_times for the rank and form. */
void burns_robot_lob_due(uint16_t robot, uint16_t *p_shot_times, uint32_t *p_carry)
{
	uint32_t carry = *p_carry;
	uint16_t shot_times = 0;
	uint8_t form_base = 0, form_extra = 0;
	uint16_t t1 = 0, lob_frames = 0;

	shot_times = burns_robot_shot_times_ADDRESS;
	form_base = OBJECT(robot)->burns_robot.form_base;
	form_extra = OBJECT(robot)->burns_robot.form_extra;
	t1 = burns_robot_shot_times[((rank + form_base + form_extra) & 0x1Eu) / 2u];
	lob_frames = OBJECT(robot)->burns_robot.lob_frames;
	if ((int16_t)t1 < (int16_t)lob_frames)
		carry = 1u;
	else
		carry = 0u;
	*p_shot_times = shot_times;
	*p_carry = carry;
}

/* Its three attack timers back to 0. */
void burns_robot_reset_timers(uint16_t robot)
{
	OBJECT(robot)->burns_robot.lob_frames = 0u;
	OBJECT(robot)->burns_robot.volley_frames = 0u;
	OBJECT(robot)->burns_robot.part_frames = 0u;
}
