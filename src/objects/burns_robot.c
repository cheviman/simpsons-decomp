/**
 *    Name:        objects/burns_robot.c
 *    Description: Mr. Burns' robot (4F80 type EC, kinds CC-D4): its entrance, its forms and attacks, how each form breaks
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    11-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the game's 053248 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

/* Mr. Burns' robot (type EC): counts its timers up, takes the players' blows, runs its handler by its
   handler number (field 02), and while it walks turns round at walls. */
void burns_robot_run(uint16_t robot)
{
	uint32_t negative = 0;
	uint8_t cell = 0, look_ahead_high = 0, look_ahead_low = 0;
	uint16_t floor_cell = 0, handlers = 0;
	uint8_t state = 0, state_2 = 0, state_3 = 0, walk_direction = 0, walk_direction_2 = 0, walk_direction_3 = 0;
	uint16_t lob_frames = 0, new_lob_frames = 0, volley_frames = 0, new_volley_frames = 0, part_frames = 0, new_part_frames = 0, x_speed = 0, look_ahead_left = 0, look_ahead_right = 0, saved_look_ahead = 0, y_speed = 0;

	lob_frames = OBJECT(robot)->burns_robot.lob_frames;
	new_lob_frames = lob_frames + 1u;
	OBJECT(robot)->burns_robot.lob_frames = new_lob_frames;
	volley_frames = OBJECT(robot)->burns_robot.volley_frames;
	new_volley_frames = volley_frames + 1u;
	OBJECT(robot)->burns_robot.volley_frames = new_volley_frames;
	part_frames = OBJECT(robot)->burns_robot.part_frames;
	new_part_frames = part_frames + 1u;
	OBJECT(robot)->burns_robot.part_frames = new_part_frames;
	state = OBJECT(robot)->state;
	if (state != 0xF9u)
		burns_robot_check_hit(robot);
	handlers = burns_robot_states_ADDRESS;
	state_2 = OBJECT(robot)->state;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		burns_robot_entrance(robot);
		break;
	case 2:
		burns_robot_walk_form_0(robot);
		break;
	case 4:
		burns_robot_walk_form_1(robot);
		break;
	case 6:
	case 8:
	case 10:
		burns_robot_walk_late_forms(robot);
		break;
	case 12:
	case 14:
	case 16:
		burns_robot_swing(robot);
		break;
	case 18:
		burns_robot_volley(robot);
		break;
	case 20:
		burns_robot_lunge(robot);
		break;
	case 22:
		burns_robot_part_attack(robot);
		break;
	case 24:
		burns_robot_lob_bombs(robot);
		break;
	case 26:
		burns_robot_gloat(robot);
		break;
	case 28:
		burns_robot_drop_maggie(robot);
		break;
	case 30:
		burns_robot_walk_to_maggie(robot);
		break;
	case 32:
		burns_robot_stop_at_maggie(robot);
		break;
	case 34:
		burns_robot_let_burns_out(robot);
		break;
	case 36:
		burns_robot_leave(robot);
		break;
	case 38:
	case 42:
		burns_robot_start_breaking(robot);
		break;
	case 40:
		burns_robot_shed_form_3(robot);
		break;
	case 44:
		burns_robot_shed_form_2(robot);
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
		burns_robot_shed_form_1(robot);
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
		burns_robot_start_form(robot);
		break;
	case 64:
		burns_robot_shed_form_0(robot);
		break;
	case 74:
		burns_robot_hurt_flash(robot, handlers);
		break;
	case 76:
		burns_robot_hurt_end(robot);
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
		burns_robot_toss_part(robot);
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
		burns_robot_walk_on(robot);
		break;
	case 102:
		burns_robot_fire_shot(robot);
		break;
	case 104:
		burns_robot_volley_next(robot);
		break;
	case 106:
		burns_robot_volley_end(robot);
		break;
	case -12:
		burns_robot_final_defeat(robot);
		break;
	case -10:
		burns_robot_form_3_broken(robot);
		break;
	case -8:
		burns_robot_form_2_broken(robot);
		break;
	case -6:
		burns_robot_form_1_broken(robot);
		break;
	case -4:
		burns_robot_form_0_broken(robot);
		break;
	case -2:
		burns_robot_hurt(robot);
		break;
	}
	state_3 = OBJECT(robot)->state;
	if (state_3 == 0u)
		return;
	x_speed = OBJECT(robot)->x_speed;
	look_ahead_low = (uint8_t)x_speed;
	look_ahead_high = (uint8_t)(x_speed >> 8);
	if ((int16_t)x_speed < 0)
	{
		look_ahead_left = (((uint32_t)look_ahead_high << 8) | (look_ahead_low & 0xFFu)) - 0x20u;
		look_ahead_low = (uint8_t)look_ahead_left;
		look_ahead_high = (uint8_t)(look_ahead_left >> 8);
	}
	else
	{
		look_ahead_right = (((uint32_t)look_ahead_high << 8) | (look_ahead_low & 0xFFu)) + 0x20u;
		look_ahead_low = (uint8_t)look_ahead_right;
		look_ahead_high = (uint8_t)(look_ahead_right >> 8);
	}
	floor_probe_dx = ((uint32_t)look_ahead_high << 8) | (look_ahead_low & 0xFFu);
	wall_probe_dx = ((uint32_t)look_ahead_high << 8) | (look_ahead_low & 0xFFu);
	floor_probe_dy = 0;
	floor_cell = floor_at_scratch_offset(robot);
	cell = (uint8_t)(floor_cell >> 8);
	if ((int8_t)cell < 0)
	{
		walk_direction = OBJECT(robot)->burns_robot.walk_direction;
		OBJECT(robot)->burns_robot.walk_direction = 0x80u - walk_direction;
		burns_robot_stop(robot);
		return;
	}
	vector_floor_ahead_y(robot, &floor_cell, &negative);
	cell = (uint8_t)(floor_cell >> 8);
	if ((int8_t)cell < 0)
	{
		walk_direction_2 = OBJECT(robot)->burns_robot.walk_direction;
		OBJECT(robot)->burns_robot.walk_direction = 0u - walk_direction_2;
		burns_robot_stop(robot);
		return;
	}
	saved_look_ahead = wall_probe_dx;
	floor_probe_dx = saved_look_ahead;
	y_speed = OBJECT(robot)->y_speed;
	floor_probe_dy = y_speed;
	floor_cell = floor_at_scratch_offset(robot);
	cell = (uint8_t)(floor_cell >> 8);
	if ((int8_t)cell >= 0)
		return;
	walk_direction_3 = OBJECT(robot)->burns_robot.walk_direction;
	OBJECT(robot)->burns_robot.walk_direction = walk_direction_3 - 0x80u;
	burns_robot_stop(robot);
}

/* Its last form broken: drops Maggie's object, walks to it, stops and lets Mr. Burns out, then is gone. */
void burns_robot_final_defeat(uint16_t robot)
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
			return;
		case 2:
			burns_robot_walk_to_maggie(robot);
			return;
		case 4:
			burns_robot_stop_at_maggie(robot);
			return;
		case 6:
			burns_robot_let_burns_out(robot);
			return;
		case 8:
			burns_robot_leave(robot);
			return;
		case 10:
		case 14:
			burns_robot_start_breaking(robot);
			return;
		case 12:
			burns_robot_shed_form_3(robot);
			return;
		case 16:
			burns_robot_shed_form_2(robot);
			return;
		case 18:
		case 32:
			burns_robot_broken_shake(robot);
			return;
		case 20:
		case 34:
			burns_robot_broken_cry(robot);
			return;
		case 22:
			burns_robot_shed_form_1(robot);
			return;
		case 24:
		case 38:
			burns_robot_fall_down(robot);
			return;
		case 26:
		case 40:
			burns_robot_lie_broken(robot);
			return;
		case 28:
		case 42:
			burns_robot_rise_as_next_form(robot);
			return;
		case 30:
		case 44:
			burns_robot_start_form(robot);
			return;
		case 36:
			burns_robot_shed_form_0(robot);
			return;
		case 46:
			burns_robot_hurt_flash(robot, steps);
			return;
		case 48:
			burns_robot_hurt_end(robot);
			return;
		case 50:
			burns_robot_place(robot);
			return;
		case 52:
			burns_robot_wait_for_story(robot);
			return;
		case 54:
			burns_robot_appear(robot);
			return;
		case 56:
			burns_robot_step_up(robot);
			return;
		case 58:
			burns_robot_speak(robot);
			return;
		case 60:
			burns_robot_toss_part(robot);
			return;
		case 62:
			burns_robot_start_fight(robot);
			return;
		case 64:
			burns_robot_ready(robot);
			return;
		case 66:
		case 72:
			burns_robot_stop_and_wind_up(robot);
			return;
		case 68:
		case 88:
			burns_robot_swing_hit(robot);
			return;
		case 70:
		case 90:
			burns_robot_walk_on(robot);
			return;
		case 74:
			burns_robot_fire_shot(robot);
			return;
		case 76:
			burns_robot_volley_next(robot);
			return;
		case 78:
			break;
		case -40:
			continue;
		case -38:
			burns_robot_form_3_broken(robot);
			return;
		case -36:
			burns_robot_form_2_broken(robot);
			return;
		case -34:
			burns_robot_form_1_broken(robot);
			return;
		case -32:
			burns_robot_form_0_broken(robot);
			return;
		case -30:
			burns_robot_hurt(robot);
			return;
		case -28:
			burns_robot_entrance(robot);
			return;
		case -26:
			burns_robot_walk_form_0(robot);
			return;
		case -24:
			burns_robot_walk_form_1(robot);
			return;
		case -22:
		case -20:
		case -18:
			burns_robot_walk_late_forms(robot);
			return;
		case -16:
		case -14:
		case -12:
			burns_robot_swing(robot);
			return;
		case -10:
			burns_robot_volley(robot);
			return;
		case -8:
			burns_robot_lunge(robot);
			return;
		case -6:
			burns_robot_part_attack(robot);
			return;
		case -4:
			burns_robot_lob_bombs(robot);
			return;
		case -2:
			burns_robot_gloat(robot);
			return;
		}
		break;
	}
	burns_robot_volley_end(robot);
}

/* Puts in Maggie's object (5280 type E7) at the stage's x 420 and keeps it; walks 192 frames, then up to
   256 more until there. */
void burns_robot_drop_maggie(uint16_t robot)
{
	uint32_t carry = 0;
	uint8_t list = 0;
	uint16_t maggie_object = 0;
	uint8_t step = 0;
	uint16_t maggie_x = 0, maggie_y = 0;

	OBJECT(robot)->animation = 0x84u;
	list = 1u;
	vector_find_free_slot(list, &maggie_object, &carry);
	OBJECT(maggie_object)->type = -0x19;
	maggie_x = 0x420u - camera_x;
	OBJECT(maggie_object)->x = maggie_x;
	maggie_y = 0xA8u + camera_y;
	OBJECT(maggie_object)->y = maggie_y;
	OBJECT(robot)->burns_robot.maggie = maggie_object;
	OBJECT(robot)->burns_robot.wait_frames = 0xC0u;
	OBJECT(robot)->burns_robot.walk_frames = 0x100u;
	step = OBJECT(robot)->burns_robot.step;
	OBJECT(robot)->burns_robot.step = step + 1u;
}

/* Walks to Maggie's object, staggering; once there (or out of time) sound 6E and the next step. */
void burns_robot_walk_to_maggie(uint16_t robot)
{
	uint16_t command = 0, direction = 0, distance = 0, object = 0;
	uint8_t wait_frames = 0, wait_frames_2 = 0, step = 0;
	uint16_t maggie = 0, walk_frames = 0, robot_x = 0, maggie_x = 0, robot_y = 0, maggie_y = 0, x_speed = 0;

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
			vector_queue_sound(command);
			step = OBJECT(robot)->burns_robot.step;
			OBJECT(robot)->burns_robot.step = step + 1u;
			return;
		}
		robot_x = OBJECT(robot)->x;
		maggie_x = OBJECT(object)->x;
		distance = robot_x - maggie_x;
		if ((int16_t)(distance >> 15 ? 0u - distance : distance) <= 0x20)
		{
			robot_y = OBJECT(robot)->y;
			maggie_y = OBJECT(object)->y;
			distance = robot_y - maggie_y;
			if ((int16_t)(distance >> 15 ? 0u - distance : distance) <= 0x20)
			{
				command = 0x6E00u;
				vector_queue_sound(command);
				step = OBJECT(robot)->burns_robot.step;
				OBJECT(robot)->burns_robot.step = step + 1u;
				return;
			}
		}
	}
	direction = vector_direction_to(robot, object);
	OBJECT(robot)->burns_robot.aim = direction >> 8;
	burns_robot_steer(robot);
	stagger_speed = 0x300;
	if ((((uint16_t)((uint32_t)(uint8_t)frame_count << 8) >> 8) & 1u) != 0u)
		stagger_speed = 0u - stagger_speed;
	x_speed = OBJECT(robot)->x_speed;
	OBJECT(robot)->x_speed = x_speed + stagger_speed;
}

/* Starts breaking down (sound 6E, its look) and stops. */
void burns_robot_stop_at_maggie(uint16_t robot)
{
	burns_robot_start_breaking(robot);
	burns_robot_stop(robot);
}

/* When its animation ends, Mr. Burns comes out of it (5280 type E2), he and Maggie's object linked; the
   robot shows kind D4. */
void burns_robot_let_burns_out(uint16_t robot)
{
	uint32_t carry = 0;
	uint8_t list = 0;
	uint16_t burns_object = 0, maggie_object = 0, part_code = 0;
	uint8_t animation_flags = 0, step = 0;
	uint16_t maggie = 0;

	animation_flags = OBJECT(robot)->animation_flags;
	if ((animation_flags & 1u) == 0u)
		return;
	list = 1u;
	vector_find_free_slot(list, &burns_object, &carry);
	part_code = 0x701u;
	burns_robot_place_part(robot, burns_object, part_code);
	OBJECT(burns_object)->flags = 0x80u;
	maggie = OBJECT(robot)->burns_robot.maggie;
	maggie_object = maggie;
	leftover_y = maggie_object;
	OBJECT(maggie_object)->rescued_maggie.burns = burns_object;
	OBJECT(burns_object)->mr_burns.maggie = maggie_object;
	OBJECT(robot)->kind = 0xD4u;
	OBJECT(robot)->animation = 0x89u;
	step = OBJECT(robot)->burns_robot.step;
	OBJECT(robot)->burns_robot.step = step + 1u;
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
void burns_robot_form_3_broken(uint16_t robot)
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
			return;
		case 2:
			burns_robot_shed_form_3(robot);
			return;
		case 6:
			burns_robot_shed_form_2(robot);
			return;
		case 8:
		case 22:
			burns_robot_broken_shake(robot);
			return;
		case 10:
		case 24:
			burns_robot_broken_cry(robot);
			return;
		case 12:
			burns_robot_shed_form_1(robot);
			return;
		case 14:
		case 28:
			burns_robot_fall_down(robot);
			return;
		case 16:
		case 30:
			burns_robot_lie_broken(robot);
			return;
		case 18:
		case 32:
			burns_robot_rise_as_next_form(robot);
			return;
		case 20:
		case 34:
			burns_robot_start_form(robot);
			return;
		case 26:
			burns_robot_shed_form_0(robot);
			return;
		case 36:
			burns_robot_hurt_flash(robot, steps);
			return;
		case 38:
			burns_robot_hurt_end(robot);
			return;
		case 40:
			burns_robot_place(robot);
			return;
		case 42:
			burns_robot_wait_for_story(robot);
			return;
		case 44:
			burns_robot_appear(robot);
			return;
		case 46:
			burns_robot_step_up(robot);
			return;
		case 48:
			burns_robot_speak(robot);
			return;
		case 50:
			burns_robot_toss_part(robot);
			return;
		case 52:
			burns_robot_start_fight(robot);
			return;
		case 54:
			burns_robot_ready(robot);
			return;
		case 56:
		case 62:
			burns_robot_stop_and_wind_up(robot);
			return;
		case 58:
		case 78:
			burns_robot_swing_hit(robot);
			return;
		case 60:
		case 80:
			burns_robot_walk_on(robot);
			return;
		case 64:
			burns_robot_fire_shot(robot);
			return;
		case 66:
			burns_robot_volley_next(robot);
			return;
		case 68:
			break;
		case -50:
			burns_robot_final_defeat(robot);
			return;
		case -48:
			continue;
		case -46:
			burns_robot_form_2_broken(robot);
			return;
		case -44:
			burns_robot_form_1_broken(robot);
			return;
		case -42:
			burns_robot_form_0_broken(robot);
			return;
		case -40:
			burns_robot_hurt(robot);
			return;
		case -38:
			burns_robot_entrance(robot);
			return;
		case -36:
			burns_robot_walk_form_0(robot);
			return;
		case -34:
			burns_robot_walk_form_1(robot);
			return;
		case -32:
		case -30:
		case -28:
			burns_robot_walk_late_forms(robot);
			return;
		case -26:
		case -24:
		case -22:
			burns_robot_swing(robot);
			return;
		case -20:
			burns_robot_volley(robot);
			return;
		case -18:
			burns_robot_lunge(robot);
			return;
		case -16:
			burns_robot_part_attack(robot);
			return;
		case -14:
			burns_robot_lob_bombs(robot);
			return;
		case -12:
			burns_robot_gloat(robot);
			return;
		case -10:
			burns_robot_drop_maggie(robot);
			return;
		case -8:
			burns_robot_walk_to_maggie(robot);
			return;
		case -6:
			burns_robot_stop_at_maggie(robot);
			return;
		case -4:
			burns_robot_let_burns_out(robot);
			return;
		case -2:
			burns_robot_leave(robot);
			return;
		}
		break;
	}
	burns_robot_volley_end(robot);
}

/* At its frame: the next music, pieces 3 and 4 fly off both ways, and it goes on as the next form with
   that form's health, walking at a target. */
void burns_robot_shed_form_3(uint16_t robot)
{
	uint8_t health = 0, piece_word_high = 0;
	uint16_t piece = 0, piece_number = 0, piece_word = 0, u = 0;
	uint8_t animation_flags = 0, form_extra = 0, form_base = 0, form_extra_2 = 0;

	animation_flags = OBJECT(robot)->animation_flags;
	if ((animation_flags & 2u) == 0u)
		return;
	boss_arrived++;
	piece_number = 0x300u;
	burns_robot_throw_piece(robot, &piece, &piece_number);
	OBJECT(piece)->x_speed = 0x100;
	piece_number = 0x8300u;
	burns_robot_throw_piece(robot, &piece, &piece_number);
	OBJECT(piece)->x_speed = -0x100;
	piece_word = 0x400u;
	burns_robot_throw_piece(robot, &piece, &piece_word);
	piece_word_high = (uint8_t)(piece_word >> 8);
	OBJECT(piece)->x = (uint32_t)piece_word_high << 8;
	OBJECT(piece)->x_speed = 0x100;
	piece_number = 0x8400u;
	burns_robot_throw_piece(robot, &piece, &piece_number);
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
	burns_robot_choose_target(robot, u);
}

/* Throws off piece A of object_1d_parts (in the 5280 list), up at 0500. */
void burns_robot_throw_piece(uint16_t robot, uint16_t *p_piece, uint16_t *p_piece_number)
{
	uint16_t piece_number = (uint16_t)*p_piece_number;
	uint32_t carry = 0;
	uint8_t list = 0;
	uint16_t part_code = 0, piece = 0;
	uint8_t saved_piece_number = 0;

	saved_piece_number = piece_number >> 8;
	list = 1u;
	vector_find_free_slot(list, &piece, &carry);
	part_code = 1u | ((uint32_t)saved_piece_number << 8);
	burns_robot_place_part(robot, piece, part_code);
	OBJECT(piece)->flags = 0x88u;
	OBJECT(piece)->z_speed = 0x500;
	piece_number = 0x500u;
	*p_piece = piece;
	*p_piece_number = piece_number;
}

/* Form 2 broken: slows, sheds its pieces and goes on as form 3. */
void burns_robot_form_2_broken(uint16_t robot)
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
			return;
		case 2:
			burns_robot_shed_form_2(robot);
			return;
		case 4:
		case 18:
			burns_robot_broken_shake(robot);
			return;
		case 6:
		case 20:
			burns_robot_broken_cry(robot);
			return;
		case 8:
			burns_robot_shed_form_1(robot);
			return;
		case 10:
		case 24:
			burns_robot_fall_down(robot);
			return;
		case 12:
		case 26:
			burns_robot_lie_broken(robot);
			return;
		case 14:
		case 28:
			burns_robot_rise_as_next_form(robot);
			return;
		case 16:
		case 30:
			burns_robot_start_form(robot);
			return;
		case 22:
			burns_robot_shed_form_0(robot);
			return;
		case 32:
			burns_robot_hurt_flash(robot, steps);
			return;
		case 34:
			burns_robot_hurt_end(robot);
			return;
		case 36:
			burns_robot_place(robot);
			return;
		case 38:
			burns_robot_wait_for_story(robot);
			return;
		case 40:
			burns_robot_appear(robot);
			return;
		case 42:
			burns_robot_step_up(robot);
			return;
		case 44:
			burns_robot_speak(robot);
			return;
		case 46:
			burns_robot_toss_part(robot);
			return;
		case 48:
			burns_robot_start_fight(robot);
			return;
		case 50:
			burns_robot_ready(robot);
			return;
		case 52:
		case 58:
			burns_robot_stop_and_wind_up(robot);
			return;
		case 54:
		case 74:
			burns_robot_swing_hit(robot);
			return;
		case 56:
		case 76:
			burns_robot_walk_on(robot);
			return;
		case 60:
			burns_robot_fire_shot(robot);
			return;
		case 62:
			burns_robot_volley_next(robot);
			return;
		case 64:
			break;
		case -54:
			burns_robot_final_defeat(robot);
			return;
		case -52:
			burns_robot_form_3_broken(robot);
			return;
		case -50:
			continue;
		case -48:
			burns_robot_form_1_broken(robot);
			return;
		case -46:
			burns_robot_form_0_broken(robot);
			return;
		case -44:
			burns_robot_hurt(robot);
			return;
		case -42:
			burns_robot_entrance(robot);
			return;
		case -40:
			burns_robot_walk_form_0(robot);
			return;
		case -38:
			burns_robot_walk_form_1(robot);
			return;
		case -36:
		case -34:
		case -32:
			burns_robot_walk_late_forms(robot);
			return;
		case -30:
		case -28:
		case -26:
			burns_robot_swing(robot);
			return;
		case -24:
			burns_robot_volley(robot);
			return;
		case -22:
			burns_robot_lunge(robot);
			return;
		case -20:
			burns_robot_part_attack(robot);
			return;
		case -18:
			burns_robot_lob_bombs(robot);
			return;
		case -16:
			burns_robot_gloat(robot);
			return;
		case -14:
			burns_robot_drop_maggie(robot);
			return;
		case -12:
			burns_robot_walk_to_maggie(robot);
			return;
		case -10:
			burns_robot_stop_at_maggie(robot);
			return;
		case -8:
			burns_robot_let_burns_out(robot);
			return;
		case -6:
			burns_robot_leave(robot);
			return;
		case -2:
			burns_robot_shed_form_3(robot);
			return;
		}
		break;
	}
	burns_robot_volley_end(robot);
}

/* Starts breaking: its breaking look for its form, sound 6E, slowed to a quarter. */
void burns_robot_start_breaking(uint16_t robot)
{
	uint16_t command = 0, look = 0;
	uint8_t form_base = 0, form_extra = 0, step = 0;

	form_base = OBJECT(robot)->burns_robot.form_base;
	form_extra = OBJECT(robot)->burns_robot.form_extra;
	look = (uint32_t)(uint8_t)(0xAu + form_base + form_extra) << 8;
	burns_robot_set_look(robot, look);
	command = 0x6E00u;
	vector_queue_sound(command);
	burns_robot_slow_down(robot);
	step = OBJECT(robot)->burns_robot.step;
	OBJECT(robot)->burns_robot.step = step + 1u;
}

/* At its frame: pieces 2 fly off, and it goes on as the next form with that form's health, walking at a
   target. */
void burns_robot_shed_form_2(uint16_t robot)
{
	uint8_t first_piece = 0, health = 0;
	uint16_t piece = 0, piece_number = 0, u = 0;
	uint8_t animation_flags = 0, shed_frame = 0, form_extra = 0, form_base = 0, form_extra_2 = 0;
	uint16_t robot_x = 0, piece_x = 0;

	animation_flags = OBJECT(robot)->animation_flags;
	shed_frame = animation_flags & 2u;
	first_piece = shed_frame;
	if (shed_frame == 0u)
		return;
	piece_number = (uint32_t)first_piece << 8;
	piece = burns_robot_throw_piece_2(robot, piece_number);
	robot_x = OBJECT(robot)->x;
	piece_x = robot_x + 0x20u;
	OBJECT(piece)->x = piece_x;
	OBJECT(piece)->x_speed = 0x80;
	piece_number = 0x8280u;
	piece = burns_robot_throw_piece_2(robot, piece_number);
	OBJECT(piece)->x_speed = -0x100;
	piece_number = 0x200u;
	piece = burns_robot_throw_piece_2(robot, piece_number);
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
	burns_robot_choose_target(robot, u);
}

/* Throws off piece A, up at 0500 (as burns_robot_throw_piece). */
uint16_t burns_robot_throw_piece_2(uint16_t robot, uint16_t piece_number)
{
	uint32_t carry = 0;
	uint8_t list = 0;
	uint16_t part_code = 0, piece = 0;
	uint8_t saved_piece_number = 0;

	saved_piece_number = piece_number >> 8;
	list = 1u;
	vector_find_free_slot(list, &piece, &carry);
	part_code = 1u | ((uint32_t)saved_piece_number << 8);
	burns_robot_place_part(robot, piece, part_code);
	OBJECT(piece)->flags = 0x88u;
	OBJECT(piece)->z_speed = 0x500;
	return piece;
}

/* Form 1 broken: shakes, sheds its pieces, falls, lies, and gets up as form 2. */
void burns_robot_form_1_broken(uint16_t robot)
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
			return;
		case 2:
		case 16:
			burns_robot_broken_cry(robot);
			return;
		case 4:
			burns_robot_shed_form_1(robot);
			return;
		case 6:
		case 20:
			burns_robot_fall_down(robot);
			return;
		case 8:
		case 22:
			burns_robot_lie_broken(robot);
			return;
		case 10:
		case 24:
			burns_robot_rise_as_next_form(robot);
			return;
		case 12:
		case 26:
			burns_robot_start_form(robot);
			return;
		case 18:
			burns_robot_shed_form_0(robot);
			return;
		case 28:
			burns_robot_hurt_flash(robot, steps);
			return;
		case 30:
			burns_robot_hurt_end(robot);
			return;
		case 32:
			burns_robot_place(robot);
			return;
		case 34:
			burns_robot_wait_for_story(robot);
			return;
		case 36:
			burns_robot_appear(robot);
			return;
		case 38:
			burns_robot_step_up(robot);
			return;
		case 40:
			burns_robot_speak(robot);
			return;
		case 42:
			burns_robot_toss_part(robot);
			return;
		case 44:
			burns_robot_start_fight(robot);
			return;
		case 46:
			burns_robot_ready(robot);
			return;
		case 48:
		case 54:
			burns_robot_stop_and_wind_up(robot);
			return;
		case 50:
		case 70:
			burns_robot_swing_hit(robot);
			return;
		case 52:
		case 72:
			burns_robot_walk_on(robot);
			return;
		case 56:
			burns_robot_fire_shot(robot);
			return;
		case 58:
			burns_robot_volley_next(robot);
			return;
		case 60:
			break;
		case -58:
			burns_robot_final_defeat(robot);
			return;
		case -56:
			burns_robot_form_3_broken(robot);
			return;
		case -54:
			burns_robot_form_2_broken(robot);
			return;
		case -52:
			continue;
		case -50:
			burns_robot_form_0_broken(robot);
			return;
		case -48:
			burns_robot_hurt(robot);
			return;
		case -46:
			burns_robot_entrance(robot);
			return;
		case -44:
			burns_robot_walk_form_0(robot);
			return;
		case -42:
			burns_robot_walk_form_1(robot);
			return;
		case -40:
		case -38:
		case -36:
			burns_robot_walk_late_forms(robot);
			return;
		case -34:
		case -32:
		case -30:
			burns_robot_swing(robot);
			return;
		case -28:
			burns_robot_volley(robot);
			return;
		case -26:
			burns_robot_lunge(robot);
			return;
		case -24:
			burns_robot_part_attack(robot);
			return;
		case -22:
			burns_robot_lob_bombs(robot);
			return;
		case -20:
			burns_robot_gloat(robot);
			return;
		case -18:
			burns_robot_drop_maggie(robot);
			return;
		case -16:
			burns_robot_walk_to_maggie(robot);
			return;
		case -14:
			burns_robot_stop_at_maggie(robot);
			return;
		case -12:
			burns_robot_let_burns_out(robot);
			return;
		case -10:
			burns_robot_leave(robot);
			return;
		case -8:
		case -4:
			burns_robot_start_breaking(robot);
			return;
		case -6:
			burns_robot_shed_form_3(robot);
			return;
		case -2:
			burns_robot_shed_form_2(robot);
			return;
		}
		break;
	}
	burns_robot_volley_end(robot);
}

/* At its frame: stops, rises 32, throws off pieces 1 both ways, and takes its falling look. */
void burns_robot_shed_form_1(uint16_t robot)
{
	uint8_t raised_z_low = 0;
	uint16_t look = 0, piece = 0, piece_number = 0;
	uint8_t animation_flags = 0, step = 0;
	uint16_t x_speed = 0, z = 0, raised_z = 0;

	animation_flags = OBJECT(robot)->animation_flags;
	if ((animation_flags & 2u) == 0u)
	{
		OBJECT(robot)->x_speed = 0x300;
		if ((frame_count & 1u) != 0u)
		{
			x_speed = OBJECT(robot)->x_speed;
			OBJECT(robot)->x_speed = 0u - x_speed;
		}
		return;
	}
	OBJECT(robot)->x_speed = 0;
	z = OBJECT(robot)->z;
	raised_z = z + 0x20u;
	raised_z_low = (uint8_t)raised_z;
	OBJECT(robot)->z = ((uint32_t)(raised_z >> 8) << 8) | (raised_z_low & 0xFFu);
	piece_number = (raised_z_low & 0xFFu) | 0x8100u;
	piece = burns_robot_throw_piece_3(robot, piece_number);
	OBJECT(piece)->x_speed = 0x100;
	OBJECT(piece)->y_speed = -0x40;
	OBJECT(piece)->z_speed = 0x500;
	piece_number = 0x100u;
	piece = burns_robot_throw_piece_3(robot, piece_number);
	OBJECT(piece)->x_speed = -0x100;
	OBJECT(piece)->y_speed = -0x20;
	OBJECT(piece)->z_speed = 0x300;
	look = 0x1400u;
	burns_robot_set_look(robot, look);
	step = OBJECT(robot)->burns_robot.step;
	OBJECT(robot)->burns_robot.step = step + 1u;
}

/* Puts in piece A, shown. */
uint16_t burns_robot_throw_piece_3(uint16_t robot, uint16_t piece_number)
{
	uint32_t carry = 0;
	uint8_t list = 0;
	uint16_t part_code = 0, piece = 0;
	uint8_t saved_piece_number = 0;

	saved_piece_number = piece_number >> 8;
	list = 1u;
	vector_find_free_slot(list, &piece, &carry);
	part_code = 1u | ((uint32_t)saved_piece_number << 8);
	burns_robot_place_part(robot, piece, part_code);
	OBJECT(piece)->flags = 0x80u;
	return piece;
}

/* Form 0 broken: shakes, sheds its pieces, falls, lies, and gets up as form 1. */
void burns_robot_form_0_broken(uint16_t robot)
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
			return;
		case -12:
		case 2:
			burns_robot_broken_cry(robot);
			return;
		case 4:
			burns_robot_shed_form_0(robot);
			return;
		case -8:
		case 6:
			burns_robot_fall_down(robot);
			return;
		case -6:
		case 8:
			burns_robot_lie_broken(robot);
			return;
		case -4:
		case 10:
			burns_robot_rise_as_next_form(robot);
			return;
		case -2:
		case 12:
			burns_robot_start_form(robot);
			return;
		case 14:
			burns_robot_hurt_flash(robot, steps);
			return;
		case 16:
			burns_robot_hurt_end(robot);
			return;
		case 18:
			burns_robot_place(robot);
			return;
		case 20:
			burns_robot_wait_for_story(robot);
			return;
		case 22:
			burns_robot_appear(robot);
			return;
		case 24:
			burns_robot_step_up(robot);
			return;
		case 26:
			burns_robot_speak(robot);
			return;
		case 28:
			burns_robot_toss_part(robot);
			return;
		case 30:
			burns_robot_start_fight(robot);
			return;
		case 32:
			burns_robot_ready(robot);
			return;
		case 34:
		case 40:
			burns_robot_stop_and_wind_up(robot);
			return;
		case 36:
		case 56:
			burns_robot_swing_hit(robot);
			return;
		case 38:
		case 58:
			burns_robot_walk_on(robot);
			return;
		case 42:
			burns_robot_fire_shot(robot);
			return;
		case 44:
			burns_robot_volley_next(robot);
			return;
		case 46:
			break;
		case -72:
			burns_robot_final_defeat(robot);
			return;
		case -70:
			burns_robot_form_3_broken(robot);
			return;
		case -68:
			burns_robot_form_2_broken(robot);
			return;
		case -66:
			burns_robot_form_1_broken(robot);
			return;
		case -64:
			continue;
		case -62:
			burns_robot_hurt(robot);
			return;
		case -60:
			burns_robot_entrance(robot);
			return;
		case -58:
			burns_robot_walk_form_0(robot);
			return;
		case -56:
			burns_robot_walk_form_1(robot);
			return;
		case -54:
		case -52:
		case -50:
			burns_robot_walk_late_forms(robot);
			return;
		case -48:
		case -46:
		case -44:
			burns_robot_swing(robot);
			return;
		case -42:
			burns_robot_volley(robot);
			return;
		case -40:
			burns_robot_lunge(robot);
			return;
		case -38:
			burns_robot_part_attack(robot);
			return;
		case -36:
			burns_robot_lob_bombs(robot);
			return;
		case -34:
			burns_robot_gloat(robot);
			return;
		case -32:
			burns_robot_drop_maggie(robot);
			return;
		case -30:
			burns_robot_walk_to_maggie(robot);
			return;
		case -28:
			burns_robot_stop_at_maggie(robot);
			return;
		case -26:
			burns_robot_let_burns_out(robot);
			return;
		case -24:
			burns_robot_leave(robot);
			return;
		case -22:
		case -18:
			burns_robot_start_breaking(robot);
			return;
		case -20:
			burns_robot_shed_form_3(robot);
			return;
		case -16:
			burns_robot_shed_form_2(robot);
			return;
		case -10:
			burns_robot_shed_form_1(robot);
			return;
		}
		break;
	}
	burns_robot_volley_end(robot);
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
	vector_queue_sound(command);
	form_base_2 = OBJECT(robot)->burns_robot.form_base;
	form_extra = OBJECT(robot)->burns_robot.form_extra;
	look = (uint32_t)(uint8_t)(0xAu + form_base_2 + form_extra) << 8;
	burns_robot_set_look(robot, look);
	step = OBJECT(robot)->burns_robot.step;
	OBJECT(robot)->burns_robot.step = step + 1u;
}

/* At its frame: stops, rises 32, throws off pieces 0 both ways, and takes its falling look. */
void burns_robot_shed_form_0(uint16_t robot)
{
	uint16_t first_piece_word = 0, look = 0, piece = 0, piece_number = 0;
	uint8_t animation_flags = 0, step = 0;
	uint16_t x_speed = 0, z = 0, raised_z = 0;

	animation_flags = OBJECT(robot)->animation_flags;
	if ((animation_flags & 2u) == 0u)
	{
		OBJECT(robot)->x_speed = 0x300;
		if ((frame_count & 1u) != 0u)
		{
			x_speed = OBJECT(robot)->x_speed;
			OBJECT(robot)->x_speed = 0u - x_speed;
		}
		return;
	}
	OBJECT(robot)->x_speed = 0;
	z = OBJECT(robot)->z;
	raised_z = z + 0x20u;
	first_piece_word = raised_z;
	OBJECT(robot)->z = ((uint32_t)(raised_z >> 8) << 8) | (first_piece_word & 0xFFu);
	first_piece_word &= 0xFFu;
	piece = burns_robot_throw_piece_4(robot, first_piece_word);
	OBJECT(piece)->x_speed = 0x100;
	piece_number = 0x8000u;
	piece = burns_robot_throw_piece_4(robot, piece_number);
	OBJECT(piece)->x_speed = -0x100;
	look = 0x1400u;
	burns_robot_set_look(robot, look);
	step = OBJECT(robot)->burns_robot.step;
	OBJECT(robot)->burns_robot.step = step + 1u;
}

/* Falls to the floor, then lies 128 frames. */
void burns_robot_fall_down(uint16_t robot)
{
	uint32_t landed = 0;
	uint16_t ignored16 = 0;
	uint8_t step = 0;

	vector_apply_gravity(robot, &ignored16, &landed);
	if (landed)
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
	vector_queue_sound(command);
	OBJECT(robot)->burns_robot.wait_frames = 0x40u;
	step = OBJECT(robot)->burns_robot.step;
	OBJECT(robot)->burns_robot.step = step + 1u;
}

/* After 64 frames: its new form's health, its timers back to 0, walking at a target. */
void burns_robot_start_form(uint16_t robot)
{
	uint8_t health = 0;
	uint16_t u = 0;
	uint8_t wait_frames = 0, form_base = 0, form_extra = 0;

	wait_frames = OBJECT(robot)->burns_robot.wait_frames;
	OBJECT(robot)->burns_robot.wait_frames = wait_frames - 1u;
	if (wait_frames != 1u)
		return;
	form_base = OBJECT(robot)->burns_robot.form_base;
	form_extra = OBJECT(robot)->burns_robot.form_extra;
	health = burns_robot_healths[(int8_t)((uint8_t)(form_base + form_extra))];
	OBJECT(robot)->vitality = health;
	OBJECT(robot)->burns_robot.health_mark = health;
	burns_robot_reset_timers(robot);
	u = burns_robot_start_walking(robot);
	burns_robot_choose_target(robot, u);
}

/* Throws off piece A, up at 0500 (as burns_robot_throw_piece). */
uint16_t burns_robot_throw_piece_4(uint16_t robot, uint16_t piece_number)
{
	uint32_t carry = 0;
	uint8_t list = 0;
	uint16_t part_code = 0, piece = 0;
	uint8_t saved_piece_number = 0;

	saved_piece_number = piece_number >> 8;
	list = 1u;
	vector_find_free_slot(list, &piece, &carry);
	part_code = 1u | ((uint32_t)saved_piece_number << 8);
	burns_robot_place_part(robot, piece, part_code);
	OBJECT(piece)->flags = 0x88u;
	OBJECT(piece)->z_speed = 0x500;
	return piece;
}

/* Hurt by a blow: flashes and reels for 16 frames. */
void burns_robot_hurt(uint16_t robot)
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
			burns_robot_hurt_flash(robot, steps);
			return;
		case 2:
			burns_robot_hurt_end(robot);
			return;
		case 4:
			burns_robot_place(robot);
			return;
		case 6:
			burns_robot_wait_for_story(robot);
			return;
		case 8:
			burns_robot_appear(robot);
			return;
		case 10:
			burns_robot_step_up(robot);
			return;
		case 12:
			burns_robot_speak(robot);
			return;
		case 14:
			burns_robot_toss_part(robot);
			return;
		case 16:
			burns_robot_start_fight(robot);
			return;
		case 18:
			burns_robot_ready(robot);
			return;
		case 20:
		case 26:
			burns_robot_stop_and_wind_up(robot);
			return;
		case 22:
		case 42:
			burns_robot_swing_hit(robot);
			return;
		case 24:
		case 44:
			burns_robot_walk_on(robot);
			return;
		case 28:
			burns_robot_fire_shot(robot);
			return;
		case 30:
			burns_robot_volley_next(robot);
			return;
		case 32:
			break;
		case -86:
			burns_robot_final_defeat(robot);
			return;
		case -84:
			burns_robot_form_3_broken(robot);
			return;
		case -82:
			burns_robot_form_2_broken(robot);
			return;
		case -80:
			burns_robot_form_1_broken(robot);
			return;
		case -78:
			burns_robot_form_0_broken(robot);
			return;
		case -76:
			continue;
		case -74:
			burns_robot_entrance(robot);
			return;
		case -72:
			burns_robot_walk_form_0(robot);
			return;
		case -70:
			burns_robot_walk_form_1(robot);
			return;
		case -68:
		case -66:
		case -64:
			burns_robot_walk_late_forms(robot);
			return;
		case -62:
		case -60:
		case -58:
			burns_robot_swing(robot);
			return;
		case -56:
			burns_robot_volley(robot);
			return;
		case -54:
			burns_robot_lunge(robot);
			return;
		case -52:
			burns_robot_part_attack(robot);
			return;
		case -50:
			burns_robot_lob_bombs(robot);
			return;
		case -48:
			burns_robot_gloat(robot);
			return;
		case -46:
			burns_robot_drop_maggie(robot);
			return;
		case -44:
			burns_robot_walk_to_maggie(robot);
			return;
		case -42:
			burns_robot_stop_at_maggie(robot);
			return;
		case -40:
			burns_robot_let_burns_out(robot);
			return;
		case -38:
			burns_robot_leave(robot);
			return;
		case -36:
		case -32:
			burns_robot_start_breaking(robot);
			return;
		case -34:
			burns_robot_shed_form_3(robot);
			return;
		case -30:
			burns_robot_shed_form_2(robot);
			return;
		case -28:
		case -14:
			burns_robot_broken_shake(robot);
			return;
		case -26:
		case -12:
			burns_robot_broken_cry(robot);
			return;
		case -24:
			burns_robot_shed_form_1(robot);
			return;
		case -22:
		case -8:
			burns_robot_fall_down(robot);
			return;
		case -20:
		case -6:
			burns_robot_lie_broken(robot);
			return;
		case -18:
		case -4:
			burns_robot_rise_as_next_form(robot);
			return;
		case -16:
		case -2:
			burns_robot_start_form(robot);
			return;
		case -10:
			burns_robot_shed_form_0(robot);
			return;
		}
		break;
	}
	burns_robot_volley_end(robot);
}

/* Flashes its palette and takes its hurt look for 16 frames. */
void burns_robot_hurt_flash(uint16_t robot, uint16_t palette_job)
{
	uint16_t look = 0, request = 0;
	uint8_t form_base = 0, form_extra = 0, step = 0;

	palette_request_kind = 2u;
	request = 0x3Fu;
	vector_palette_request(palette_job, request);
	form_base = OBJECT(robot)->burns_robot.form_base;
	form_extra = OBJECT(robot)->burns_robot.form_extra;
	look = 0x3Fu | ((uint32_t)(uint8_t)(0x17u + form_base + form_extra) << 8);
	burns_robot_set_look(robot, look);
	OBJECT(robot)->burns_robot.wait_frames = 0x10u;
	step = OBJECT(robot)->burns_robot.step;
	OBJECT(robot)->burns_robot.step = step + 1u;
}

/* When the 16 frames are up, walks at a target again. */
void burns_robot_hurt_end(uint16_t robot)
{
	uint16_t u = 0;
	uint8_t wait_frames = 0;

	wait_frames = OBJECT(robot)->burns_robot.wait_frames;
	OBJECT(robot)->burns_robot.wait_frames = wait_frames - 1u;
	if (wait_frames != 1u)
		return;
	u = burns_robot_start_walking(robot);
	burns_robot_choose_target(robot, u);
}

/* Its entrance, step by step until it can be fought. */
void burns_robot_entrance(uint16_t robot)
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
			return;
		case 2:
			burns_robot_wait_for_story(robot);
			return;
		case 4:
			burns_robot_appear(robot);
			return;
		case 6:
			burns_robot_step_up(robot);
			return;
		case 8:
			burns_robot_speak(robot);
			return;
		case 10:
			burns_robot_toss_part(robot);
			return;
		case 12:
			burns_robot_start_fight(robot);
			return;
		case 14:
			burns_robot_ready(robot);
			return;
		case 16:
		case 22:
			burns_robot_stop_and_wind_up(robot);
			return;
		case 18:
		case 38:
			burns_robot_swing_hit(robot);
			return;
		case 20:
		case 40:
			burns_robot_walk_on(robot);
			return;
		case 24:
			burns_robot_fire_shot(robot);
			return;
		case 26:
			burns_robot_volley_next(robot);
			return;
		case 28:
			break;
		case -90:
			burns_robot_final_defeat(robot);
			return;
		case -88:
			burns_robot_form_3_broken(robot);
			return;
		case -86:
			burns_robot_form_2_broken(robot);
			return;
		case -84:
			burns_robot_form_1_broken(robot);
			return;
		case -82:
			burns_robot_form_0_broken(robot);
			return;
		case -80:
			burns_robot_hurt(robot);
			return;
		case -78:
			continue;
		case -76:
			burns_robot_walk_form_0(robot);
			return;
		case -74:
			burns_robot_walk_form_1(robot);
			return;
		case -72:
		case -70:
		case -68:
			burns_robot_walk_late_forms(robot);
			return;
		case -66:
		case -64:
		case -62:
			burns_robot_swing(robot);
			return;
		case -60:
			burns_robot_volley(robot);
			return;
		case -58:
			burns_robot_lunge(robot);
			return;
		case -56:
			burns_robot_part_attack(robot);
			return;
		case -54:
			burns_robot_lob_bombs(robot);
			return;
		case -52:
			burns_robot_gloat(robot);
			return;
		case -50:
			burns_robot_drop_maggie(robot);
			return;
		case -48:
			burns_robot_walk_to_maggie(robot);
			return;
		case -46:
			burns_robot_stop_at_maggie(robot);
			return;
		case -44:
			burns_robot_let_burns_out(robot);
			return;
		case -42:
			burns_robot_leave(robot);
			return;
		case -40:
		case -36:
			burns_robot_start_breaking(robot);
			return;
		case -38:
			burns_robot_shed_form_3(robot);
			return;
		case -34:
			burns_robot_shed_form_2(robot);
			return;
		case -32:
		case -18:
			burns_robot_broken_shake(robot);
			return;
		case -30:
		case -16:
			burns_robot_broken_cry(robot);
			return;
		case -28:
			burns_robot_shed_form_1(robot);
			return;
		case -26:
		case -12:
			burns_robot_fall_down(robot);
			return;
		case -24:
		case -10:
			burns_robot_lie_broken(robot);
			return;
		case -22:
		case -8:
			burns_robot_rise_as_next_form(robot);
			return;
		case -20:
		case -6:
			burns_robot_start_form(robot);
			return;
		case -14:
			burns_robot_shed_form_0(robot);
			return;
		case -4:
			burns_robot_hurt_flash(robot, steps);
			return;
		case -2:
			burns_robot_hurt_end(robot);
			return;
		}
		break;
	}
	burns_robot_volley_end(robot);
}

/* Puts the robot at the stage's x 420 with health A0, and keeps it in 1854. */
void burns_robot_place(uint16_t robot)
{
	uint8_t step = 0;
	uint16_t robot_x = 0, robot_y = 0;

	io_write16(stage_kept_object_2, robot);
	OBJECT(robot)->shadow_player = 1u;
	robot_x = 0x420u - camera_x;
	OBJECT(robot)->x = robot_x;
	robot_y = 0xE8u + camera_y;
	OBJECT(robot)->y = robot_y;
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
	uint16_t look_word = 0;
	uint8_t wait_frames = 0, step = 0;

	wait_frames = OBJECT(robot)->burns_robot.wait_frames;
	OBJECT(robot)->burns_robot.wait_frames = wait_frames - 1u;
	if (wait_frames != 1u)
		return;
	OBJECT(robot)->flags = 0x80u;
	look_word = 0x3200u;
	look_word = burns_robot_set_look(robot, look_word);
	look_word &= 0xFFu;
	burns_robot_set_box(robot, look_word);
	step = OBJECT(robot)->burns_robot.step;
	OBJECT(robot)->burns_robot.step = step + 1u;
}

/* Steps 16 up the screen and waits 64 frames. */
void burns_robot_step_up(uint16_t robot)
{
	uint8_t animation_flags = 0, step = 0;
	uint16_t robot_y = 0, raised_y = 0;

	animation_flags = OBJECT(robot)->animation_flags;
	if ((animation_flags & 1u) == 0u)
	{
		robot_y = OBJECT(robot)->y;
		raised_y = robot_y - 0x10u;
		OBJECT(robot)->y = raised_y;
		OBJECT(robot)->burns_robot.wait_frames = 0x40u;
		step = OBJECT(robot)->burns_robot.step;
		OBJECT(robot)->burns_robot.step = step + 1u;
	}
}

/* Mr. Burns speaks: a speech balloon (4D40 type 29, kind B0 animation 83) on the robot and his voice
   (3F36). */
void burns_robot_speak(uint16_t robot)
{
	uint32_t slot_found = 0;
	uint8_t list = 0;
	uint16_t balloon = 0, command = 0, look = 0;
	uint8_t wait_frames = 0, step = 0;

	wait_frames = OBJECT(robot)->burns_robot.wait_frames;
	OBJECT(robot)->burns_robot.wait_frames = wait_frames - 1u;
	if (wait_frames != 1u)
		return;
	list = 2u;
	vector_find_free_slot(list, &balloon, &slot_found);
	if (slot_found)
	{
		OBJECT(balloon)->type = 0x29;
		OBJECT(balloon)->kind = 0xB0u;
		OBJECT(balloon)->animation = 0x83u;
		OBJECT(balloon)->action = 0x80u;
		OBJECT(balloon)->action_step = (uint8_t)(robot >> 8u);
		OBJECT(balloon)->behaviour = (OBJECT(balloon)->behaviour & 0xFFu) | ((robot & 0xFFu) << 8u);
	}
	command = 0x3F36u;
	vector_queue_sound(command);
	look = 0x3336u;
	burns_robot_set_look(robot, look);
	step = OBJECT(robot)->burns_robot.step;
	OBJECT(robot)->burns_robot.step = step + 1u;
}

/* At its frame tosses away a part (object_1d_parts 8, 5280 type E4) at full size, with sound 0301. */
void burns_robot_toss_part(uint16_t robot)
{
	uint32_t slot_found = 0;
	uint8_t list = 0;
	uint16_t command = 0, part = 0, part_code = 0;
	uint8_t animation_flags = 0, step = 0;

	animation_flags = OBJECT(robot)->animation_flags;
	if ((animation_flags & 2u) == 0u)
		return;
	list = 1u;
	vector_find_free_slot(list, &part, &slot_found);
	if (slot_found)
	{
		part_code = 0x801u;
		burns_robot_place_part(robot, part, part_code);
		OBJECT(part)->flags = 0x80u;
		OBJECT(part)->zoom_x = 0x40u;
		OBJECT(part)->zoom_y = 0x40u;
		OBJECT(robot)->burns_robot.wait_frames = 0x40u;
		command = 0x301u;
		vector_queue_sound(command);
	}
	step = OBJECT(robot)->burns_robot.step;
	OBJECT(robot)->burns_robot.step = step + 1u;
}

/* After 64 frames: sound 14, the scene's next music, its fighting look, and the step moves on. */
void burns_robot_start_fight(uint16_t robot)
{
	uint8_t look_kind = 0;
	uint16_t command = 0, look_word = 0;
	uint8_t wait_frames = 0, step = 0;
	uint32_t step_subphase_halfword = 0;

	wait_frames = OBJECT(robot)->burns_robot.wait_frames;
	OBJECT(robot)->burns_robot.wait_frames = wait_frames - 1u;
	if (wait_frames != 1u)
		return;
	command = 0x1400u;
	vector_queue_sound(command);
	boss_arrived = 1u;
	look_word = 0x3400u;
	look_word = burns_robot_set_look(robot, look_word);
	look_kind = (uint8_t)(look_word >> 8);
	step = OBJECT(robot)->burns_robot.step;
	OBJECT(robot)->burns_robot.step = step + 1u;
	step_phase++;
	step_subphase_halfword = ((uint32_t)look_kind << 8) | (look_word & 0xFFu);
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
void burns_robot_walk_form_0(uint16_t robot)
{
	uint32_t action_started = 0;
	uint16_t command = 0, look = 0, u = 0;
	uint8_t animation = 0, form_base = 0, aim = 0, animation_flags = 0;

	burns_robot_decide_form_0(robot, &u, &action_started);
	if (action_started)
		return;
	action_started = burns_robot_choose_target(robot, u);
	if (action_started)
		return;
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
	burns_robot_walk(robot);
	animation_flags = OBJECT(robot)->animation_flags;
	if ((animation_flags & 2u) != 0u)
	{
		command = 0x5A00u;
		vector_queue_sound(command);
	}
}

/* Form 1 walking at its target, turning a step at a time, sound 13 every 64 frames, attacking when it
   can. */
void burns_robot_walk_form_1(uint16_t robot)
{
	uint32_t aim_below = 0, action_started = 0;
	uint8_t turn = 0, walk_direction = 0;
	uint16_t command = 0, look = 0, u = 0;
	uint8_t animation = 0, form_base = 0, aim = 0, walk_direction_2 = 0, walk_direction_3 = 0;

	burns_robot_decide_form_1(robot, &u, &action_started);
	if (action_started)
		return;
	action_started = burns_robot_choose_target(robot, u);
	if (action_started)
		return;
	if ((frame_count & 0x3Fu) == 0u)
	{
		command = 0x1300u;
		vector_queue_sound(command);
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
	aim_below = (uint8_t)(walk_direction - walk_direction_2) >> 7;
	if (walk_direction == walk_direction_2)
	{
		burns_robot_walk(robot);
		return;
	}
	if (aim_below)
		turn = 0u - turn;
	walk_direction_3 = OBJECT(robot)->burns_robot.walk_direction;
	OBJECT(robot)->burns_robot.walk_direction = turn + walk_direction_3;
	burns_robot_walk(robot);
}

/* Forms 2-4 walking at their target, turning 3 steps at a time, attacking when they can. */
void burns_robot_walk_late_forms(uint16_t robot)
{
	uint32_t action_started = 0;
	uint16_t look = 0, u = 0;
	uint8_t animation = 0, form_base = 0, form_extra = 0;

	burns_robot_decide_late_forms(robot, &u, &action_started);
	if (action_started)
		return;
	action_started = burns_robot_choose_target(robot, u);
	if (action_started)
		return;
	animation = OBJECT(robot)->animation;
	if (animation != 1u)
	{
		form_base = OBJECT(robot)->burns_robot.form_base;
		form_extra = OBJECT(robot)->burns_robot.form_extra;
		look = (uint32_t)(uint8_t)(5u + form_base + form_extra) << 8;
		burns_robot_set_look(robot, look);
	}
	burns_robot_aim_at_target(robot);
	burns_robot_steer(robot);
}

/* Turns its walking direction up to 3 steps toward its aim and walks that way. */
void burns_robot_steer(uint16_t robot)
{
	uint32_t aim_below = 0;
	uint8_t turn = 0, walk_direction = 0;
	uint8_t aim = 0, walk_direction_2 = 0, walk_direction_3 = 0;

	turn = 3u;
	aim = OBJECT(robot)->burns_robot.aim;
	walk_direction = aim;
	walk_direction_2 = OBJECT(robot)->burns_robot.walk_direction;
	aim_below = (uint8_t)(walk_direction - walk_direction_2) >> 7;
	if (walk_direction == walk_direction_2)
	{
		burns_robot_walk(robot);
		return;
	}
	if (aim_below)
		turn = 0u - turn;
	walk_direction_3 = OBJECT(robot)->burns_robot.walk_direction;
	OBJECT(robot)->burns_robot.walk_direction = turn + walk_direction_3;
	burns_robot_walk(robot);
}

/* A swing (forms 0 and 1, and form 2's other attack): stops, winds up, hits at its frames, walks on. */
void burns_robot_swing(uint16_t robot)
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
			return;
		case 2:
		case 22:
			burns_robot_swing_hit(robot);
			return;
		case 4:
		case 24:
			burns_robot_walk_on(robot);
			return;
		case 8:
			burns_robot_fire_shot(robot);
			return;
		case 10:
			burns_robot_volley_next(robot);
			return;
		case 12:
			break;
		case -106:
			burns_robot_final_defeat(robot);
			return;
		case -104:
			burns_robot_form_3_broken(robot);
			return;
		case -102:
			burns_robot_form_2_broken(robot);
			return;
		case -100:
			burns_robot_form_1_broken(robot);
			return;
		case -98:
			burns_robot_form_0_broken(robot);
			return;
		case -96:
			burns_robot_hurt(robot);
			return;
		case -94:
			burns_robot_entrance(robot);
			return;
		case -92:
			burns_robot_walk_form_0(robot);
			return;
		case -90:
			burns_robot_walk_form_1(robot);
			return;
		case -88:
		case -86:
		case -84:
			burns_robot_walk_late_forms(robot);
			return;
		case -82:
		case -80:
		case -78:
			continue;
		case -76:
			burns_robot_volley(robot);
			return;
		case -74:
			burns_robot_lunge(robot);
			return;
		case -72:
			burns_robot_part_attack(robot);
			return;
		case -70:
			burns_robot_lob_bombs(robot);
			return;
		case -68:
			burns_robot_gloat(robot);
			return;
		case -66:
			burns_robot_drop_maggie(robot);
			return;
		case -64:
			burns_robot_walk_to_maggie(robot);
			return;
		case -62:
			burns_robot_stop_at_maggie(robot);
			return;
		case -60:
			burns_robot_let_burns_out(robot);
			return;
		case -58:
			burns_robot_leave(robot);
			return;
		case -56:
		case -52:
			burns_robot_start_breaking(robot);
			return;
		case -54:
			burns_robot_shed_form_3(robot);
			return;
		case -50:
			burns_robot_shed_form_2(robot);
			return;
		case -48:
		case -34:
			burns_robot_broken_shake(robot);
			return;
		case -46:
		case -32:
			burns_robot_broken_cry(robot);
			return;
		case -44:
			burns_robot_shed_form_1(robot);
			return;
		case -42:
		case -28:
			burns_robot_fall_down(robot);
			return;
		case -40:
		case -26:
			burns_robot_lie_broken(robot);
			return;
		case -38:
		case -24:
			burns_robot_rise_as_next_form(robot);
			return;
		case -36:
		case -22:
			burns_robot_start_form(robot);
			return;
		case -30:
			burns_robot_shed_form_0(robot);
			return;
		case -20:
			burns_robot_hurt_flash(robot, steps);
			return;
		case -18:
			burns_robot_hurt_end(robot);
			return;
		case -16:
			burns_robot_place(robot);
			return;
		case -14:
			burns_robot_wait_for_story(robot);
			return;
		case -12:
			burns_robot_appear(robot);
			return;
		case -10:
			burns_robot_step_up(robot);
			return;
		case -8:
			burns_robot_speak(robot);
			return;
		case -6:
			burns_robot_toss_part(robot);
			return;
		case -4:
			burns_robot_start_fight(robot);
			return;
		case -2:
			burns_robot_ready(robot);
			return;
		}
		break;
	}
	burns_robot_volley_end(robot);
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
	vector_queue_sound(command);
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
void burns_robot_walk_on(uint16_t robot)
{
	uint16_t u = 0;

	u = burns_robot_start_walking(robot);
	burns_robot_choose_target(robot, u);
}

/* A volley of shots (form 1's second attack): winds up, fires shot after shot, walks on. */
void burns_robot_volley(uint16_t robot)
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
			return;
		case 2:
			burns_robot_fire_shot(robot);
			return;
		case 4:
			burns_robot_volley_next(robot);
			return;
		case 6:
			break;
		case -4:
		case 16:
			burns_robot_swing_hit(robot);
			return;
		case -2:
		case 18:
			burns_robot_walk_on(robot);
			return;
		case -112:
			burns_robot_final_defeat(robot);
			return;
		case -110:
			burns_robot_form_3_broken(robot);
			return;
		case -108:
			burns_robot_form_2_broken(robot);
			return;
		case -106:
			burns_robot_form_1_broken(robot);
			return;
		case -104:
			burns_robot_form_0_broken(robot);
			return;
		case -102:
			burns_robot_hurt(robot);
			return;
		case -100:
			burns_robot_entrance(robot);
			return;
		case -98:
			burns_robot_walk_form_0(robot);
			return;
		case -96:
			burns_robot_walk_form_1(robot);
			return;
		case -94:
		case -92:
		case -90:
			burns_robot_walk_late_forms(robot);
			return;
		case -88:
		case -86:
		case -84:
			burns_robot_swing(robot);
			return;
		case -82:
			continue;
		case -80:
			burns_robot_lunge(robot);
			return;
		case -78:
			burns_robot_part_attack(robot);
			return;
		case -76:
			burns_robot_lob_bombs(robot);
			return;
		case -74:
			burns_robot_gloat(robot);
			return;
		case -72:
			burns_robot_drop_maggie(robot);
			return;
		case -70:
			burns_robot_walk_to_maggie(robot);
			return;
		case -68:
			burns_robot_stop_at_maggie(robot);
			return;
		case -66:
			burns_robot_let_burns_out(robot);
			return;
		case -64:
			burns_robot_leave(robot);
			return;
		case -62:
		case -58:
			burns_robot_start_breaking(robot);
			return;
		case -60:
			burns_robot_shed_form_3(robot);
			return;
		case -56:
			burns_robot_shed_form_2(robot);
			return;
		case -54:
		case -40:
			burns_robot_broken_shake(robot);
			return;
		case -52:
		case -38:
			burns_robot_broken_cry(robot);
			return;
		case -50:
			burns_robot_shed_form_1(robot);
			return;
		case -48:
		case -34:
			burns_robot_fall_down(robot);
			return;
		case -46:
		case -32:
			burns_robot_lie_broken(robot);
			return;
		case -44:
		case -30:
			burns_robot_rise_as_next_form(robot);
			return;
		case -42:
		case -28:
			burns_robot_start_form(robot);
			return;
		case -36:
			burns_robot_shed_form_0(robot);
			return;
		case -26:
			burns_robot_hurt_flash(robot, steps);
			return;
		case -24:
			burns_robot_hurt_end(robot);
			return;
		case -22:
			burns_robot_place(robot);
			return;
		case -20:
			burns_robot_wait_for_story(robot);
			return;
		case -18:
			burns_robot_appear(robot);
			return;
		case -16:
			burns_robot_step_up(robot);
			return;
		case -14:
			burns_robot_speak(robot);
			return;
		case -12:
			burns_robot_toss_part(robot);
			return;
		case -10:
			burns_robot_start_fight(robot);
			return;
		case -8:
			burns_robot_ready(robot);
			return;
		}
		break;
	}
	burns_robot_volley_end(robot);
}

/* At its frame fires a shot (4D40 type 25) at x speed 0500 the way it faces, sound 1D. */
void burns_robot_fire_shot(uint16_t robot)
{
	uint32_t slot_found = 0;
	uint8_t facing = 0, list = 0, turned_part = 0;
	uint16_t box_number = 0, command = 0, object = 0, part_code = 0, self = 0, shot = 0;
	uint16_t saved_robot = 0;
	uint8_t animation_flags = 0, attributes = 0, action = 0;
	uint16_t shot_x_speed = 0;

	animation_flags = OBJECT(robot)->animation_flags;
	if ((animation_flags & 2u) == 0u)
		return;
	list = 2u;
	vector_find_free_slot(list, &shot, &slot_found);
	if (slot_found == 0u)
	{
		burns_robot_start_walking(robot);
		return;
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
	burns_robot_place_part(robot, shot, part_code);
	command = 0x1D00u;
	vector_queue_sound(command);
	shot_x_speed = shot_speed;
	OBJECT(shot)->x_speed = shot_x_speed;
	saved_robot = robot;
	self = shot;
	box_number = 0xF00u;
	burns_robot_set_box(self, box_number);
	object = saved_robot;
	action = OBJECT(object)->action;
	OBJECT(object)->action = action + 1u;
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
void burns_robot_volley_end(uint16_t robot)
{
	uint16_t u = 0;
	uint8_t animation_flags = 0;

	animation_flags = OBJECT(robot)->animation_flags;
	if ((animation_flags & 1u) == 0u)
		return;
	u = burns_robot_start_walking(robot);
	burns_robot_choose_target(robot, u);
}

/* A lunge (form 2's first attack): slows, winds up, hits, walks on. */
void burns_robot_lunge(uint16_t robot)
{
	uint8_t step = 0;

	step = OBJECT(robot)->burns_robot.step;
	switch ((int8_t)(uint8_t)((uint32_t)step << 1))
	{
	case 0:
		burns_robot_slow_down_step(robot);
		return;
	case 2:
		burns_robot_wind_up(robot);
		return;
	case -16:
	case 4:
		burns_robot_swing_hit(robot);
		return;
	case -14:
	case 6:
		burns_robot_walk_on(robot);
		return;
	case 8:
		burns_robot_part_attack_start(robot);
		return;
	case 10:
		burns_robot_part_attack_raise(robot);
		return;
	case 12:
		burns_robot_part_attack_hold(robot);
		return;
	case 14:
		burns_robot_part_attack_carry(robot);
		return;
	case 16:
		burns_robot_lob_aim(robot);
		return;
	case 18:
		burns_robot_lob_throw(robot);
		return;
	case 20:
		burns_robot_lob_recover(robot);
		return;
	case 22:
		burns_robot_lob_end(robot);
		return;
	}
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
void burns_robot_part_attack(uint16_t robot)
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
		burns_robot_part_attack_hold(robot);
		break;
	case 6:
		burns_robot_part_attack_carry(robot);
		break;
	case 8:
		burns_robot_lob_aim(robot);
		break;
	case 10:
		burns_robot_lob_throw(robot);
		break;
	case 12:
		burns_robot_lob_recover(robot);
		break;
	case 14:
		burns_robot_lob_end(robot);
		break;
	case -24:
	case -4:
		burns_robot_swing_hit(robot);
		break;
	case -22:
	case -2:
		burns_robot_walk_on(robot);
		break;
	case -8:
		burns_robot_slow_down_step(robot);
		break;
	case -6:
		burns_robot_wind_up(robot);
		break;
	}
	burns_robot_aim_at_target(robot);
	burns_robot_steer(robot);
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
	uint16_t command = 0, look = 0;
	uint8_t animation_flags = 0, form_extra = 0, step = 0;

	animation_flags = OBJECT(robot)->animation_flags;
	if ((animation_flags & 1u) == 0u)
		return;
	command = 0x1100u;
	vector_queue_sound(command);
	form_extra = OBJECT(robot)->burns_robot.form_extra;
	look = (uint32_t)(uint8_t)(0x30u + form_extra) << 8;
	burns_robot_set_look(robot, look);
	step = OBJECT(robot)->burns_robot.step;
	OBJECT(robot)->burns_robot.step = step + 1u;
}

/* At its frame holds out its part (4F80 type EA) in front of it, harmful, for 64 frames. */
void burns_robot_part_attack_hold(uint16_t robot)
{
	uint32_t slot_found = 0;
	uint8_t list = 0, turned_part = 0;
	uint16_t box_number = 0, held_object = 0, part_code = 0, robot_back = 0, self = 0;
	uint16_t saved_robot = 0;
	uint8_t animation_flags = 0, step = 0, attributes = 0;

	animation_flags = OBJECT(robot)->animation_flags;
	if ((animation_flags & 2u) == 0u)
		return;
	OBJECT(robot)->flags &= ~4u;
	list = 0u;
	vector_find_free_slot(list, &held_object, &slot_found);
	if (slot_found == 0u)
	{
		OBJECT(held_object)->flags = 0xC0u;
		OBJECT(held_object)->burns_held_part.robot = robot;
		OBJECT(robot)->burns_robot.held_part = held_object;
		saved_robot = robot;
		self = held_object;
		box_number = 0x1000u;
		burns_robot_set_box(self, box_number);
		robot_back = saved_robot;
		OBJECT(robot_back)->burns_robot.wait_frames = 0x40u;
		OBJECT(robot_back)->burns_robot.holding_part = 1u;
		step = OBJECT(robot_back)->burns_robot.step;
		OBJECT(robot_back)->burns_robot.step = step + 1u;
		return;
	}
	turned_part = 0xEu;
	attributes = OBJECT(robot)->attributes;
	if ((attributes & 0x40u) != 0u)
		turned_part -= 0x80u;
	part_code = (uint32_t)turned_part << 8;
	burns_robot_place_part(robot, held_object, part_code);
	OBJECT(held_object)->flags = 0xC0u;
	OBJECT(held_object)->burns_held_part.robot = robot;
	OBJECT(robot)->burns_robot.held_part = held_object;
	saved_robot = robot;
	self = held_object;
	box_number = 0x1000u;
	burns_robot_set_box(self, box_number);
	robot_back = saved_robot;
	OBJECT(robot_back)->burns_robot.wait_frames = 0x40u;
	OBJECT(robot_back)->burns_robot.holding_part = 1u;
	step = OBJECT(robot_back)->burns_robot.step;
	OBJECT(robot_back)->burns_robot.step = step + 1u;
}

/* Carries the held part along with its speeds; when the 64 frames are up lets go of it and walks at a
   target. */
void burns_robot_part_attack_carry(uint16_t robot)
{
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
		return;
	OBJECT(robot)->burns_robot.holding_part = 0u;
	u = burns_robot_start_walking(robot);
	burns_robot_choose_target(robot, u);
}

/* Lobs bombs (the tables' shots: 4D40 type 26): aims, throws, recovers; form 4 throws three. */
void burns_robot_lob_bombs(uint16_t robot)
{
	uint8_t step = 0;

	step = OBJECT(robot)->burns_robot.step;
	switch ((int8_t)(uint8_t)((uint32_t)step << 1))
	{
	case 0:
		burns_robot_lob_aim(robot);
		return;
	case 2:
		burns_robot_lob_throw(robot);
		return;
	case 4:
		burns_robot_lob_recover(robot);
		return;
	case 6:
		burns_robot_lob_end(robot);
		return;
	case -32:
	case -12:
		burns_robot_swing_hit(robot);
		return;
	case -30:
	case -10:
		burns_robot_walk_on(robot);
		return;
	case -16:
		burns_robot_slow_down_step(robot);
		return;
	case -14:
		burns_robot_wind_up(robot);
		return;
	case -8:
		burns_robot_part_attack_start(robot);
		return;
	case -6:
		burns_robot_part_attack_raise(robot);
		return;
	case -4:
		burns_robot_part_attack_hold(robot);
		return;
	case -2:
		burns_robot_part_attack_carry(robot);
		return;
	}
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
void burns_robot_lob_throw(uint16_t robot)
{
	uint32_t slot_found = 0;
	uint8_t facing = 0, list = 0, turned_part = 0;
	uint16_t bomb = 0, part_code = 0;
	uint8_t animation_flags = 0, step = 0, attributes = 0, form_base = 0, form_extra = 0, bombs_lobbed = 0;
	uint16_t lob_x_speed = 0, lob_y_speed = 0;

	animation_flags = OBJECT(robot)->animation_flags;
	if ((animation_flags & 2u) == 0u)
		return;
	list = 2u;
	vector_find_free_slot(list, &bomb, &slot_found);
	if (slot_found == 0u)
	{
		step = OBJECT(robot)->burns_robot.step;
		OBJECT(robot)->burns_robot.step = step + 1u;
		return;
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
	lob_x_speed = lob_speed;
	OBJECT(bomb)->x_speed = lob_x_speed;
	leftover_y = burns_robot_shot_y_speeds_ADDRESS;
	bombs_lobbed = OBJECT(robot)->burns_robot.bombs_lobbed;
	lob_y_speed = burns_robot_shot_y_speeds[(int8_t)((uint8_t)((uint32_t)bombs_lobbed << 1)) / 2];
	OBJECT(bomb)->y_speed = lob_y_speed;
	step = OBJECT(robot)->burns_robot.step;
	OBJECT(robot)->burns_robot.step = step + 1u;
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
void burns_robot_lob_end(uint16_t robot)
{
	uint16_t u = 0;
	uint8_t animation_flags = 0, form_base = 0, form_extra = 0, bombs_lobbed = 0, bombs_lobbed_2 = 0;

	animation_flags = OBJECT(robot)->animation_flags;
	if ((animation_flags & 1u) == 0u)
		return;
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
			return;
		}
	}
	u = burns_robot_start_walking(robot);
	burns_robot_choose_target(robot, u);
}

/* Gloating with no target (a player down or none to go for): waits for a player, then walks on. */
void burns_robot_gloat(uint16_t robot)
{
	uint8_t step = 0;

	step = OBJECT(robot)->burns_robot.step;
	switch ((int8_t)(uint8_t)((uint32_t)step << 1))
	{
	case 0:
		burns_robot_gloat_until_player(robot);
		return;
	case 2:
		burns_robot_gloat_end(robot);
		return;
	}
}

/* Stands (but in forms 2-4) until there is a player to go for, then can be hit again and waits 32
   frames. */
void burns_robot_gloat_until_player(uint16_t robot)
{
	uint32_t player_found = 0;
	uint16_t ignored16 = 0, ignored16_2 = 0;
	uint8_t form_base = 0, step = 0;

	form_base = OBJECT(robot)->burns_robot.form_base;
	if (form_base != 2u)
		burns_robot_stop(robot);
	find_nearest_player(robot, &ignored16, &ignored16_2, &player_found);
	if (player_found)
	{
		OBJECT(robot)->flags |= 0x40u;
		OBJECT(robot)->burns_robot.wait_frames = 0x20u;
		step = OBJECT(robot)->burns_robot.step;
		OBJECT(robot)->burns_robot.step = step + 1u;
	}
}

/* After 32 frames walks at a target. */
void burns_robot_gloat_end(uint16_t robot)
{
	uint16_t u = 0;
	uint8_t wait_frames = 0;

	wait_frames = OBJECT(robot)->burns_robot.wait_frames;
	OBJECT(robot)->burns_robot.wait_frames = wait_frames - 1u;
	if (wait_frames != 1u)
		return;
	u = burns_robot_start_walking(robot);
	burns_robot_choose_target(robot, u);
}

/* When a player's blow hits it, lets go of its held part and takes the blow. */
void burns_robot_check_hit(uint16_t robot)
{
	uint32_t negative_hit = 0;
	uint8_t hit = 0;

	if ((OBJECT(robot)->flags & 0x20u) != 0u)
	{
		hit = OBJECT(robot)->hit;
		negative_hit = hit >> 7;
		if (hit != 0u && negative_hit == 0u)
		{
			OBJECT(robot)->burns_robot.holding_part = 0u;
			burns_robot_take_hit(robot);
		}
	}
}

/* Form 0: facing its target, lobs bombs when they are due and it is in the middle, else attacks a target
   in reach (its second attack by chance); carry when it does. */
void burns_robot_decide_form_0(uint16_t robot, uint16_t *p_target, uint32_t *p_carry)
{
	uint32_t carry = *p_carry;
	uint16_t target = 0;

	burns_robot_facing_target(robot, &target, &carry);
	if (carry == 0u)
		carry = 0u;
	else
	{
		carry = burns_robot_lob_due(robot);
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
	*p_target = target;
	*p_carry = carry;
}

/* Form 1: as form 0, and fires a volley at a target in line across but further back once 128 frames have
   passed since the last. */
void burns_robot_decide_form_1(uint16_t robot, uint16_t *p_target, uint32_t *p_carry)
{
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
		carry = burns_robot_lob_due(robot);
		if (carry)
		{
			carry = burns_robot_in_middle(robot);
			if (carry)
			{
				carry = burns_robot_start_lob(robot);
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
				*p_carry = carry;
				return;
			}
			carry = 0u;
		}
	}
	*p_target = target;
	*p_carry = carry;
}

/* Forms 2-4: as form 0, and holds out its part when burns_robot_held_part_times have passed (not form
   4). */
void burns_robot_decide_late_forms(uint16_t robot, uint16_t *p_target, uint32_t *p_carry)
{
	uint32_t carry = *p_carry;
	uint16_t target = 0;
	uint8_t form_extra = 0, form_extra_2 = 0;
	uint16_t held_part_time = 0, part_frames = 0;

	burns_robot_facing_target(robot, &target, &carry);
	if (carry == 0u)
		carry = 0u;
	else
	{
		carry = burns_robot_lob_due(robot);
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
					leftover_y = burns_robot_held_part_times_ADDRESS;
					form_extra_2 = OBJECT(robot)->burns_robot.form_extra;
					held_part_time = burns_robot_held_part_times[(((((uint32_t)form_extra_2 << 1) << 1) + rank) & 0x1Eu) / 2u];
					part_frames = OBJECT(robot)->burns_robot.part_frames;
					if ((int16_t)held_part_time <= (int16_t)part_frames)
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
						leftover_y = burns_robot_held_part_times_ADDRESS;
						form_extra_2 = OBJECT(robot)->burns_robot.form_extra;
						held_part_time = burns_robot_held_part_times[(((((uint32_t)form_extra_2 << 1) << 1) + rank) & 0x1Eu) / 2u];
						part_frames = OBJECT(robot)->burns_robot.part_frames;
						if ((int16_t)held_part_time <= (int16_t)part_frames)
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
	*p_target = target;
	*p_carry = carry;
}

/* Carry when it faces its target. */
void burns_robot_facing_target(uint16_t robot, uint16_t *p_target, uint32_t *p_facing)
{
	uint32_t facing = *p_facing;
	uint16_t target = 0;
	uint8_t attributes = 0, attributes_2 = 0;
	uint16_t target_player = 0, robot_x = 0, target_x = 0;

	target_player = OBJECT(robot)->burns_robot.target_player;
	target = target_player;
	robot_x = OBJECT(robot)->x;
	target_x = OBJECT(target)->x;
	if ((int16_t)robot_x < (int16_t)target_x)
	{
		attributes = OBJECT(robot)->attributes;
		if ((attributes & 0x40u) != 0u)
			facing = 0u;
		else
			facing = 1u;
	}
	else
	{
		attributes_2 = OBJECT(robot)->attributes;
		if ((attributes_2 & 0x40u) == 0u)
			facing = 0u;
		else
			facing = 1u;
	}
	*p_target = target;
	*p_facing = facing;
}

/* Walks in its walking direction at its form's speed for the rank, facing it. */
void burns_robot_walk(uint16_t robot)
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
	leftover_y = speeds;
}

/* Keeps its target for 64 frames, taking the player 07D2AB finds when the target is gone or down; with
   none it gloats (carry). */
uint32_t burns_robot_choose_target(uint16_t robot, uint16_t target_player)
{
	uint32_t carry = 0;
	uint16_t current_target = 0, ignored16 = 0;
	uint8_t target_state = 0, target_frames = 0, target_frames_2 = 0;
	uint16_t target_player_2 = 0;

	find_nearest_player(robot, &target_player, &ignored16, &carry);
	if (carry == 0u)
		return burns_robot_start_gloating(robot);
	target_player_2 = OBJECT(robot)->burns_robot.target_player;
	current_target = target_player_2;
	if (OBJECT(current_target)->flags != 0u)
	{
		target_state = OBJECT(current_target)->state;
		if ((int8_t)target_state >= 0)
		{
			target_frames = OBJECT(robot)->burns_robot.target_frames;
			if (target_frames != 0u)
			{
				target_frames_2 = OBJECT(robot)->burns_robot.target_frames;
				OBJECT(robot)->burns_robot.target_frames = target_frames_2 - 1u;
				carry = 0u;
				leftover_y = current_target;
				return carry;
			}
		}
	}
	OBJECT(robot)->burns_robot.target_frames = 0x40u;
	OBJECT(robot)->burns_robot.target_player = target_player;
	carry = 0u;
	leftover_y = current_target;
	return carry;
}

/* Aims at the place beside its target on its own side (the other side when that is a wall), and notes
   the direction to the target. */
void burns_robot_aim_at_target(uint16_t robot)
{
	uint32_t negative = 0;
	uint8_t a = 0, cell = 0, direction = 0, side = 0, target_dy = 0;
	uint16_t direction_to_target = 0, object = 0, side_probe = 0, target = 0;
	uint8_t aim_offset = 0;
	uint16_t saved_robot = 0;
	uint16_t target_player = 0, robot_x = 0, target_x = 0;

	target_player = OBJECT(robot)->burns_robot.target_player;
	target = target_player;
	robot_x = OBJECT(robot)->x;
	target_x = OBJECT(target)->x;
	if ((int16_t)target_x < (int16_t)robot_x)
		side = 0x40u;
	else
		side = 0xC0u;
	saved_robot = robot;
	aim_offset = side;
	object = target;
	side_probe = (uint32_t)(uint16_t)(((uint32_t)a << 8) | side) << 8;
	vector_floor_at_offset(object, &side_probe, &negative);
	cell = (uint8_t)(side_probe >> 8);
	if ((int8_t)cell < 0)
		aim_offset = 0u - aim_offset;
	object = saved_robot;
	side_probe = aim_offset;
	side_probe = vector_direction_to_offset(object, target, side_probe);
	direction = (uint8_t)(side_probe >> 8);
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
	uint16_t look_entry = 0;
	uint32_t kind_halfword = 0;

	look_entry = burns_robot_animations[(int8_t)((uint8_t)((uint32_t)(look >> 8) << 1)) / 2];
	look_kind = (uint8_t)(look_entry >> 8);
	look_animation = look_entry | 0x80u;
	kind_halfword = ((uint32_t)look_kind << 8) | look_animation;
	OBJECT(robot)->kind = (uint8_t)(kind_halfword >> 8u);
	OBJECT(robot)->animation = (uint8_t)kind_halfword;
	look = ((uint32_t)look_kind << 8) | look_animation;
	return look;
}

/* Takes box A of burns_robot_hit_boxes: its hit, sizes and offsets. */
uint16_t burns_robot_set_box(uint16_t self, uint16_t box_number)
{
	uint16_t box_end = 0, damage_attack = 0;
	uint16_t box_record = 0, box_sizes = 0, box_heights = 0, box_offsets = 0;
	uint32_t box_width_halfword = 0, box_height_halfword = 0, box_dy_halfword = 0;

	box_record = TABLE16(burns_robot_hit_boxes, (int8_t)((uint16_t)((uint32_t)(uint8_t)((uint32_t)(box_number >> 8) << 1) << 8) >> 8));
	damage_attack = HIT_BOX(box_record)->damage_attack;
	OBJECT(self)->damage = (uint8_t)(damage_attack >> 8u);
	OBJECT(self)->attack = (uint8_t)damage_attack;
	box_sizes = box_record + 2u;
	box_width_halfword = HIT_BOX(box_sizes - 0x2u)->width_depth;
	OBJECT(self)->box_width = (uint8_t)(box_width_halfword >> 8u);
	OBJECT(self)->box_depth = (uint8_t)box_width_halfword;
	box_heights = box_sizes + 2u;
	box_height_halfword = HIT_BOX(box_heights - 0x4u)->height_dx;
	OBJECT(self)->box_height = (uint8_t)(box_height_halfword >> 8u);
	OBJECT(self)->box_dx = (uint8_t)box_height_halfword;
	box_offsets = box_heights + 2u;
	box_end = box_offsets + 2u;
	box_dy_halfword = HIT_BOX(box_offsets - 0x6u)->dy_dz;
	OBJECT(self)->box_dy = (uint8_t)(box_dy_halfword >> 8u);
	OBJECT(self)->box_dz = (uint8_t)box_dy_halfword;
	return box_end;
}

/* Carry when its target is within F8 across and up to FA further down the screen. */
void burns_robot_target_in_reach(uint16_t robot, uint16_t *p_target, uint32_t *p_in_reach)
{
	uint32_t in_reach = *p_in_reach;
	uint16_t target = 0;
	uint16_t target_player = 0;

	target_player = OBJECT(robot)->burns_robot.target_player;
	target = target_player;
	in_reach = burns_robot_target_across(robot, target);
	if (in_reach == 0u)
		in_reach = 0u;
	else
		in_reach = burns_robot_target_in_depth(robot, target);
	*p_target = target;
	*p_in_reach = in_reach;
}

/* Carry when U is up to FA further down the screen than it. */
uint32_t burns_robot_target_in_depth(uint16_t robot, uint16_t target)
{
	uint32_t within_depth = 0;
	uint16_t depth = 0;
	uint16_t target_y = 0, robot_y = 0, difference_y = 0;

	target_y = OBJECT(target)->y;
	robot_y = OBJECT(robot)->y;
	difference_y = target_y - robot_y;
	depth = difference_y;
	if ((int16_t)difference_y < 0 || reach_y < (int16_t)depth)
	{
		within_depth = 0u;
		return within_depth;
	}
	within_depth = 1u;
	return within_depth;
}

/* Carry when U is within F8 across. */
uint32_t burns_robot_target_across(uint16_t robot, uint16_t target)
{
	uint32_t within_across = 0;
	uint16_t across = 0;
	uint16_t robot_x = 0, target_x = 0;

	robot_x = OBJECT(robot)->x;
	target_x = OBJECT(target)->x;
	across = robot_x - target_x;
	if (reach_x < (int16_t)(across >> 15 ? 0u - across : across))
	{
		within_across = 0u;
		return within_across;
	}
	within_across = 1u;
	return within_across;
}

/* Back to walking: can be hit and hurt, its body's box, its form's walking handler. */
uint16_t burns_robot_start_walking(uint16_t robot)
{
	uint16_t box_end = 0, box_number = 0;
	uint8_t form_base = 0, form_base_2 = 0;

	OBJECT(robot)->flags = (OBJECT(robot)->flags | 0x40u) & ~4u;
	form_base = OBJECT(robot)->burns_robot.form_base;
	box_number = (uint32_t)form_base << 8;
	box_end = burns_robot_set_box(robot, box_number);
	form_base_2 = OBJECT(robot)->burns_robot.form_base;
	OBJECT(robot)->state = 1u + form_base_2;
	OBJECT(robot)->burns_robot.step = 0u;
	OBJECT(robot)->burns_robot.wait_frames = 0u;
	return box_end;
}

/* Mr. Burns gloats (voice 3F38): handler 0D with its gloating look; it can not be hit meanwhile. */
uint32_t burns_robot_start_gloating(uint16_t robot)
{
	uint32_t action_started = 0;
	uint16_t command = 0, look = 0;
	uint8_t form_base = 0, form_extra = 0;

	command = 0x3F38u;
	vector_queue_sound(command);
	OBJECT(robot)->state = 0xDu;
	OBJECT(robot)->burns_robot.step = 0u;
	form_base = OBJECT(robot)->burns_robot.form_base;
	form_extra = OBJECT(robot)->burns_robot.form_extra;
	look = 0x38u | ((uint32_t)(uint8_t)(0xFu + form_base + form_extra) << 8);
	burns_robot_set_look(robot, look);
	OBJECT(robot)->flags &= 0xBFu;
	action_started = 1u;
	return action_started;
}

/* Takes a blow: a spark on the player, sound 66, no box; at or below its form's beaten health for the
   players in the game its form breaks, else it is hurt. */
void burns_robot_take_hit(uint16_t robot)
{
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
	vector_queue_sound(command);
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
void burns_robot_start_attack(uint16_t robot, uint16_t *p_object, uint32_t *p_action_started)
{
	uint32_t action_started = *p_action_started;
	uint16_t look = 0, target = 0;
	uint8_t state = 0, form_base = 0, attack_choice = 0, form_base_2 = 0, form_extra = 0, form_extra_2 = 0, form_base_3 = 0, vitality = 0, health_mark = 0, vitality_2 = 0;
	uint16_t target_player = 0;

	OBJECT(robot)->burns_robot.attack_choice = chosen_attack;
	target_player = OBJECT(robot)->burns_robot.target_player;
	target = target_player;
	state = OBJECT(target)->state;
	if ((int8_t)state < 0)
		action_started = burns_robot_start_gloating(robot);
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
			action_started = 1u;
		}
		else
		{
			health_mark = OBJECT(robot)->burns_robot.health_mark;
			vitality_2 = OBJECT(robot)->vitality;
			if ((uint8_t)(health_mark - vitality_2) > 0xCu)
			{
				vitality = OBJECT(robot)->vitality;
				OBJECT(robot)->burns_robot.health_mark = vitality;
				action_started = 1u;
			}
			else
			{
				OBJECT(robot)->burns_robot.wait_frames = 0x20u;
				action_started = 1u;
			}
		}
	}
	*p_object = target;
	*p_action_started = action_started;
}

/* Starts lobbing bombs (handler 0C), facing its target, safe meanwhile. */
uint32_t burns_robot_start_lob(uint16_t robot)
{
	uint32_t action_started = 0;

	OBJECT(robot)->burns_robot.lob_frames = 0u;
	OBJECT(robot)->burns_robot.bombs_lobbed = 0u;
	OBJECT(robot)->burns_robot.wait_frames = 0u;
	burns_robot_face_target(robot);
	OBJECT(robot)->flags |= 4u;
	OBJECT(robot)->state = 0xCu;
	OBJECT(robot)->burns_robot.step = 0u;
	action_started = 1u;
	return action_started;
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
	uint8_t speed_high = 0, speed_low = 0;
	uint16_t x_speed = 0, y_speed = 0;

	x_speed = OBJECT(robot)->x_speed;
	speed_high = (uint8_t)(x_speed >> 8);
	carry = speed_high & 1u;
	speed_high = (int8_t)speed_high >> 1;
	speed_low = ((uint8_t)x_speed >> 1) | (carry << 7);
	carry = speed_high & 1u;
	OBJECT(robot)->x_speed = ((uint32_t)(uint8_t)((int8_t)speed_high >> 1) << 8) | (uint8_t)((speed_low >> 1) | (carry << 7));
	y_speed = OBJECT(robot)->y_speed;
	speed_high = (uint8_t)(y_speed >> 8);
	carry = speed_high & 1u;
	speed_high = (int8_t)speed_high >> 1;
	speed_low = ((uint8_t)y_speed >> 1) | (carry << 7);
	carry = speed_high & 1u;
	OBJECT(robot)->y_speed = ((uint32_t)(uint8_t)((int8_t)speed_high >> 1) << 8) | (uint8_t)((speed_low >> 1) | (carry << 7));
}

/* Sets up the new object U as part A of object_1d_parts at the robot's place (turned round when A has
   bit 7): its offsets, type, kind and animation. */
void burns_robot_place_part(uint16_t self, uint16_t part, uint16_t part_code)
{
	uint8_t part_number = 0, shift_x_high = 0, shift_x_low = 0;
	uint16_t part_2 = 0;
	uint16_t part_record = 0, record_dy = 0, dy = 0, self_y = 0, part_y = 0, record_dz = 0, dz = 0, z = 0, part_z = 0, record_type = 0, kind = 0, shift_x = 0, turned_shift_x = 0, self_x = 0, part_x = 0;

	part_number = (uint8_t)(part_code >> 8);
	part_dx &= 0xFFu;
	placed_part_number = part_number;
	if ((int8_t)part_number < 0)
	{
		OBJECT(part)->attributes = 0x40u;
		part_number &= 0x7Fu;
	}
	part_record = object_1d_parts_ADDRESS + (int8_t)((((uint32_t)part_number << 1) << 1) << 1);
	part_dx_low = PART(part_record)->dx;
	record_dy = part_record + 1u;
	dy = PART(record_dy - 0x1u)->dy;
	self_y = OBJECT(self)->y;
	part_y = dy + self_y;
	OBJECT(part)->y = part_y;
	record_dz = record_dy + 1u;
	dz = PART(record_dz - 0x2u)->dz;
	z = OBJECT(self)->z;
	part_z = dz + z;
	OBJECT(part)->z = part_z;
	record_type = record_dz + 1u;
	part_2 = record_type + 1u;
	OBJECT(part)->type = PART(record_type - 0x3u)->type;
	kind = (((uint32_t)PART(part_2 - 0x4u)->kind << 8u) | PART(part_2 - 0x4u)->animation);
	OBJECT(part)->kind = (uint8_t)(kind >> 8u);
	OBJECT(part)->animation = (uint8_t)kind;
	shift_x = part_dx;
	shift_x_high = (uint8_t)(shift_x >> 8);
	shift_x_low = (uint8_t)shift_x;
	if ((int8_t)placed_part_number < 0)
	{
		turned_shift_x = 0u - (((uint32_t)shift_x_high << 8) | shift_x_low);
		shift_x_high = (uint8_t)(turned_shift_x >> 8);
		shift_x_low = (uint8_t)turned_shift_x;
	}
	self_x = OBJECT(self)->x;
	part_x = (((uint32_t)shift_x_high << 8) | shift_x_low) + self_x;
	OBJECT(part)->x = part_x;
	leftover_y = part_2;
}

/* Carry when its x is within 40-180. */
uint32_t burns_robot_in_middle(uint16_t robot)
{
	uint32_t in_middle = 0;
	uint8_t robot_x_high = 0, robot_x_low = 0;
	uint16_t robot_x = 0;

	robot_x = OBJECT(robot)->x;
	robot_x_low = (uint8_t)robot_x;
	robot_x_high = (uint8_t)(robot_x >> 8);
	if ((int16_t)(((uint32_t)robot_x_high << 8) | (robot_x_low & 0xFFu)) < 0x40 || (int16_t)(((uint32_t)robot_x_high << 8) | (robot_x_low & 0xFFu)) > 0x180)
	{
		in_middle = 0u;
		return in_middle;
	}
	in_middle = 1u;
	return in_middle;
}

/* Carry when the frames since its last bombs pass burns_robot_shot_times for the rank and form. */
uint32_t burns_robot_lob_due(uint16_t robot)
{
	uint32_t lob_due = 0;
	uint16_t shot_times = 0;
	uint8_t form_base = 0, form_extra = 0;
	uint16_t lob_time = 0, lob_frames = 0;

	shot_times = burns_robot_shot_times_ADDRESS;
	form_base = OBJECT(robot)->burns_robot.form_base;
	form_extra = OBJECT(robot)->burns_robot.form_extra;
	lob_time = burns_robot_shot_times[((rank + form_base + form_extra) & 0x1Eu) / 2u];
	lob_frames = OBJECT(robot)->burns_robot.lob_frames;
	if ((int16_t)lob_time < (int16_t)lob_frames)
	{
		lob_due = 1u;
		leftover_y = shot_times;
		return lob_due;
	}
	lob_due = 0u;
	leftover_y = shot_times;
	return lob_due;
}

/* Its three attack timers back to 0. */
void burns_robot_reset_timers(uint16_t robot)
{
	OBJECT(robot)->burns_robot.lob_frames = 0u;
	OBJECT(robot)->burns_robot.volley_frames = 0u;
	OBJECT(robot)->burns_robot.part_frames = 0u;
}
