/**
 *    Name:        enemies/robot.c
 *    Description: stage 7's robot (type 30), its actions, its pieces, sparks and launched part
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    11-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the game's 053248 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

/* Sets a robot piece up, hidden, with its rise, wait, animation and direction from robot_pieces. */
uint16_t robot_piece_setup(uint16_t object)
{
	uint16_t heading = 0, piece = 0, setup = 0;
	uint8_t parameter = 0, animation = 0, direction = 0, state = 0;
	uint16_t rise = 0;

	setup = robot_piece_object_setup_ADDRESS;
	vector_object_setup(object, setup);
	OBJECT(object)->flags = 4u;
	OBJECT(object)->kind = 0x8Fu;
	parameter = OBJECT(object)->parameter;
	piece = robot_pieces_ADDRESS + (int8_t)(((uint32_t)parameter << 1) << 1);
	rise = (((uint32_t)ROBOT_PIECE(piece)->rise << 8u) | ROBOT_PIECE(piece)->wait);
	OBJECT(object)->z_speed = (OBJECT(object)->z_speed & 0xFFu) | ((rise >> 8 & 0xFFu) << 8u);
	OBJECT(object)->timer = rise;
	animation = ROBOT_PIECE(piece)->animation;
	OBJECT(object)->animation = animation | 0x80u;
	direction = ROBOT_PIECE(piece)->direction;
	heading = ((uint32_t)direction << 8) | 0x20u;
	vector_set_speed_by_direction(object, heading);
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
	return piece;
}

/* Counts the piece's wait down, then shows it. */
void robot_piece_wait(uint16_t object)
{
	uint8_t timer = 0, state = 0;

	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer == 1u)
	{
		OBJECT(object)->flags = 0x88u;
		state = OBJECT(object)->state;
		OBJECT(object)->state = state + 1u;
	}
}

/* Pulls the piece down; when it lands it bounces once. */
void robot_piece_fall(uint16_t object)
{
	uint32_t carry = 0;
	uint8_t state = 0;
	uint16_t z_speed = 0;

	z_speed = OBJECT(object)->z_speed;
	OBJECT(object)->z_speed = z_speed - 0x40u;
	carry = vector_check_landing(object);
	if (carry)
	{
		OBJECT(object)->z_speed = 0x200;
		state = OBJECT(object)->state;
		OBJECT(object)->state = state + 1u;
	}
	robot_piece_bounce_off_walls(object);
}

/* Pulls the bouncing piece down; when it lands it stops and turns into sparks. */
void robot_piece_bounce(uint16_t object)
{
	uint32_t carry = 0;
	uint8_t state = 0;
	uint16_t z_speed = 0, falling_z_speed = 0;

	z_speed = OBJECT(object)->z_speed;
	falling_z_speed = z_speed - 0x30u;
	OBJECT(object)->z_speed = falling_z_speed;
	carry = vector_check_landing(object);
	if (carry == 0u)
	{
		robot_piece_bounce_off_walls(object);
		return;
	}
	OBJECT(object)->x_speed = 0;
	OBJECT(object)->y_speed = 0;
	OBJECT(object)->kind = 4u;
	OBJECT(object)->animation = 0x80u;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
	robot_piece_bounce_off_walls(object);
}

/* Turns the piece's speeds back where it meets the stage's edges. */
void robot_piece_bounce_off_walls(uint16_t object)
{
	uint32_t negative = 0;
	uint16_t floor_cell = 0;
	uint16_t x_speed = 0, y_speed = 0;

	vector_floor_ahead_x(object, &floor_cell, &negative);
	if ((int8_t)(floor_cell >> 8) < 0)
	{
		x_speed = OBJECT(object)->x_speed;
		OBJECT(object)->x_speed = 0u - x_speed;
	}
	vector_floor_ahead_y(object, &floor_cell, &negative);
	if ((int8_t)(floor_cell >> 8) < 0)
	{
		y_speed = OBJECT(object)->y_speed;
		OBJECT(object)->y_speed = 0u - y_speed;
	}
}

/* When the sparks end, frees the piece's slot; piece 0 becomes the scrap the robot leaves (type F5). */
void robot_piece_burst(uint16_t object)
{
	uint8_t animation_flags = 0, parameter = 0;

	animation_flags = OBJECT(object)->animation_flags;
	if ((animation_flags & 1u) == 0u)
		return;
	parameter = OBJECT(object)->parameter;
	if (parameter == 0u)
	{
		OBJECT(object)->type = -0xB;
		OBJECT(object)->state = 0u;
		OBJECT(object)->kind = 4u;
		OBJECT(object)->animation = 0x20u;
		OBJECT(object)->parameter = 0x20u;
		return;
	}
	OBJECT(object)->flags = 0u;
}

/* Sets the spark up with the time it lasts from hit_spark_times. */
uint16_t robot_spark_setup(uint16_t object)
{
	uint16_t setup = 0, spark_times = 0;
	uint8_t parameter = 0, state = 0;

	setup = robot_spark_object_setup_ADDRESS;
	vector_object_setup(object, setup);
	OBJECT(object)->flags = 0x40u;
	spark_times = hit_spark_times_ADDRESS;
	parameter = OBJECT(object)->parameter;
	OBJECT(object)->timer = hit_spark_times[(int8_t)parameter];
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
	return spark_times;
}

/* Counts the spark's time down and frees its slot. */
void robot_spark_fade(uint16_t object)
{
	uint8_t timer = 0;

	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer == 1u)
		OBJECT(object)->flags = 0u;
}

/* Sets the robot up with its behaviour robot_behaviour (less vitality with 1 or 3 players), turned to
   its player, fighting at once; sets direct page 80 and starts its music. */
void robot_setup(uint16_t object)
{
	uint16_t command = 0, nearest_player = 0, setup = 0;
	uint8_t attributes = 0;

	setup = robot_object_setup_ADDRESS;
	vector_object_setup(object, setup);
	if (player_count & 1u)
		OBJECT(object)->vitality = 0x30u;
	nearest_player = vector_choose_nearest_player(object);
	vector_measure_target(object, nearest_player);
	OBJECT(object)->robot.spare_count = 4u;
	OBJECT(object)->robot.flashing = 1u;
	OBJECT(object)->behaviour = 0x7B70u;
	OBJECT(object)->retarget_time = 0x10u;
	attributes = OBJECT(object)->attributes;
	OBJECT(object)->attributes = (attributes & ~0xFu) | 7u;
	OBJECT(object)->parameter = 0u;
	OBJECT(object)->state = 2u;
	stage_part = 1u;
	command = 0x9B00u;
	vector_queue_sound_unless_attract(command);
}

/* Plays the robot's wind-up for 64 frames, with a sound. */
void robot_combo_wind_up(uint16_t object)
{
	uint16_t command = 0;
	uint8_t action_step = 0;

	OBJECT(object)->animation = 0x8Bu;
	OBJECT(object)->timer = 0x40u;
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
	command = 0x2700u;
	vector_queue_sound(command);
}

/* Counts the wind-up down, then makes the robot hittable. */
void robot_combo_ready(uint16_t object)
{
	uint8_t timer = 0, action_step = 0;

	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer == 1u)
	{
		OBJECT(object)->flags = 0xC0u;
		action_step = OBJECT(object)->action_step;
		OBJECT(object)->action_step = action_step + 1u;
	}
}

/* Plays the robot's wind-up again for 32 frames, with a sound. */
void robot_combo_pause(uint16_t object)
{
	uint16_t command = 0;
	uint8_t action_step = 0;

	OBJECT(object)->animation = 0x8Bu;
	OBJECT(object)->timer = 0x20u;
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
	command = 0x2700u;
	vector_queue_sound(command);
}

/* Turns the robot round. */
void robot_combo_turn(uint16_t object)
{
	uint8_t attributes = 0, animation_flags = 0, action_step = 0;

	attributes = OBJECT(object)->attributes;
	OBJECT(object)->attributes = (attributes & 0x7Fu) ^ 0x40u;
	animation_flags = OBJECT(object)->animation_flags;
	OBJECT(object)->animation_flags = animation_flags | 0x80u;
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
}

/* Unused: when its animation ends the robot shows again and starts thinking (state 2). */
void unused_robot_fight_at_animation_end(uint16_t object)
{
	uint8_t animation_flags = 0, attributes = 0, animation_flags_2 = 0;

	animation_flags = OBJECT(object)->animation_flags;
	if ((animation_flags & 1u) == 0u)
		return;
	attributes = OBJECT(object)->attributes;
	OBJECT(object)->attributes = attributes & 0x7Fu;
	animation_flags_2 = OBJECT(object)->animation_flags;
	OBJECT(object)->animation_flags = animation_flags_2 | 0x80u;
	OBJECT(object)->state = 2u;
	OBJECT(object)->timer = 0u;
}

/* Starts the robot's blows, turned to its player. */
void robot_punch_start(uint16_t object)
{
	uint8_t action_step = 0;

	face_target(object);
	OBJECT(object)->animation = 0x90u;
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
}

/* On the first marked frame, gives the robot its first attacking hit box. */
void robot_punch_first_hit(uint16_t object)
{
	uint8_t animation_flags = 0, action_step = 0;

	animation_flags = OBJECT(object)->animation_flags;
	if ((animation_flags & 2u) == 0u)
		return;
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
	leftover_y = robot_punch_first_hit_box_ADDRESS;
	vector_set_hit_box(object);
}

/* Gives the robot back its plain hit box. */
void robot_punch_recover(uint16_t object)
{
	uint8_t action_step = 0;

	leftover_y = robot_body_box_ADDRESS;
	vector_set_hit_box(object);
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
	robot_punch_second_hit(object);
}

/* On the next marked frame, gives the robot its second attacking hit box. */
void robot_punch_second_hit(uint16_t object)
{
	uint8_t animation_flags = 0, action_step = 0;

	animation_flags = OBJECT(object)->animation_flags;
	if ((animation_flags & 2u) == 0u)
		return;
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
	leftover_y = robot_punch_second_hit_box_ADDRESS;
	vector_set_hit_box(object);
}

/* Gives the robot back its plain hit box again. */
void robot_punch_recover_again(uint16_t object)
{
	uint8_t action_step = 0;

	leftover_y = robot_body_box_ADDRESS;
	vector_set_hit_box(object);
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
	robot_attack_end_with_animation(object);
}

/* Ends the robot's action when its animation ends. */
void robot_attack_end_with_animation(uint16_t object)
{
	uint8_t animation_flags = 0;

	animation_flags = OBJECT(object)->animation_flags;
	if ((animation_flags & 1u) == 0u)
		return;
	robot_attack_end(object);
}

/* Ends the robot's action: hittable again, no longer flashing. */
void robot_attack_end(uint16_t object)
{
	uint8_t attributes = 0, animation_flags = 0;

	OBJECT(object)->robot.flashing = 0u;
	OBJECT(object)->flags = 0xC0u;
	attributes = OBJECT(object)->attributes;
	OBJECT(object)->attributes = attributes & 0x7Fu;
	animation_flags = OBJECT(object)->animation_flags;
	OBJECT(object)->animation_flags = animation_flags | 0x80u;
	OBJECT(object)->state = 2u;
	OBJECT(object)->timer = 0u;
}

/* Flashes the robot a frame, out of the hits' reach. */
void robot_flash(uint16_t object)
{
	uint8_t attributes = 0, animation_flags = 0;

	attributes = OBJECT(object)->attributes;
	OBJECT(object)->attributes = attributes ^ 0x80u;
	animation_flags = OBJECT(object)->animation_flags;
	OBJECT(object)->animation_flags = animation_flags | 0x80u;
	OBJECT(object)->flags = 0xC4u;
}

/* Starts the robot's shock, turned to its player, stepping forward. */
void robot_advance_shock_start(uint16_t object)
{
	uint8_t attributes = 0, action_step = 0;
	uint16_t x_speed = 0;

	face_target(object);
	OBJECT(object)->animation = 0x9Du;
	OBJECT(object)->x_speed = 0x80;
	attributes = OBJECT(object)->attributes;
	if ((attributes & 0x40u) != 0u)
	{
		x_speed = OBJECT(object)->x_speed;
		OBJECT(object)->x_speed = 0u - x_speed;
	}
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
}

/* On the shock's marked frames puts in its sparks by robot_sparks_by_frame_9d, with the sound at frames
   6 and 0E. */
uint16_t robot_advance_shock_sparks(uint16_t object, uint16_t steps)
{
	uint32_t carry = 0;
	uint8_t animation_frame = 0;
	uint16_t command = 0, ignored16 = 0, ignored16_2 = 0;
	uint8_t animation_flags = 0, animation_flags_2 = 0, action_step = 0, frame = 0, frame_2 = 0;
	uint16_t spark_record = 0;

	animation_flags = OBJECT(object)->animation_flags;
	if ((animation_flags & 2u) == 0u)
	{
		animation_flags_2 = OBJECT(object)->animation_flags;
		if (animation_flags_2 & 1u)
		{
			action_step = OBJECT(object)->action_step;
			OBJECT(object)->action_step = action_step + 1u;
		}
		return steps;
	}
	frame = OBJECT(object)->frame;
	animation_frame = frame;
	if (animation_frame == 6u || animation_frame == 0xEu)
	{
		command = 0x2300u;
		vector_queue_sound(command);
	}
	frame_2 = OBJECT(object)->frame;
	spark_record = robot_sparks_by_frame_9d[(int8_t)((uint8_t)((uint32_t)frame_2 << 1)) / 2];
	leftover_y = spark_record;
	if ((int16_t)spark_record < 0)
	{
		animation_flags_2 = OBJECT(object)->animation_flags;
		if (animation_flags_2 & 1u)
		{
			action_step = OBJECT(object)->action_step;
			OBJECT(object)->action_step = action_step + 1u;
		}
		return steps;
	}
	vector_spawn_child(object, &ignored16, &steps, &ignored16_2, &carry);
	animation_flags_2 = OBJECT(object)->animation_flags;
	if (animation_flags_2 & 1u)
	{
		action_step = OBJECT(object)->action_step;
		OBJECT(object)->action_step = action_step + 1u;
	}
	return steps;
}

/* Turns the robot to its player and starts the shock. */
void robot_shock_92_start(uint16_t object)
{
	face_target(object);
	robot_shock_92_begin(object);
}

/* Starts the robot's shock (animation 92). */
void robot_shock_92_begin(uint16_t object)
{
	uint8_t action_step = 0;

	OBJECT(object)->animation = 0x92u;
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
}

/* On the shock's marked frames puts in its sparks by robot_sparks_by_frame_92. */
uint16_t robot_shock_92_sparks(uint16_t object, uint16_t steps)
{
	uint32_t carry = 0;
	uint16_t command = 0, ignored16 = 0, ignored16_2 = 0;
	uint8_t animation_flags = 0, animation_flags_2 = 0, action_step = 0, frame = 0, frame_2 = 0;
	uint16_t spark_record = 0;

	animation_flags = OBJECT(object)->animation_flags;
	if ((animation_flags & 2u) == 0u)
	{
		animation_flags_2 = OBJECT(object)->animation_flags;
		if (animation_flags_2 & 1u)
		{
			action_step = OBJECT(object)->action_step;
			OBJECT(object)->action_step = action_step + 1u;
		}
		return steps;
	}
	frame = OBJECT(object)->frame;
	if (frame == 6u)
	{
		command = 0x2300u;
		vector_queue_sound(command);
	}
	frame_2 = OBJECT(object)->frame;
	spark_record = robot_sparks_by_frame_92[(int8_t)((uint8_t)((uint32_t)frame_2 << 1)) / 2];
	leftover_y = spark_record;
	if ((int16_t)spark_record < 0)
	{
		animation_flags_2 = OBJECT(object)->animation_flags;
		if (animation_flags_2 & 1u)
		{
			action_step = OBJECT(object)->action_step;
			OBJECT(object)->action_step = action_step + 1u;
		}
		return steps;
	}
	vector_spawn_child(object, &ignored16, &steps, &ignored16_2, &carry);
	animation_flags_2 = OBJECT(object)->animation_flags;
	if (animation_flags_2 & 1u)
	{
		action_step = OBJECT(object)->action_step;
		OBJECT(object)->action_step = action_step + 1u;
	}
	return steps;
}

/* Turns the robot to its player and starts the shock. */
void robot_shock_91_start(uint16_t object)
{
	face_target(object);
	robot_shock_91_begin(object);
}

/* Starts the robot's shock (animation 91). */
void robot_shock_91_begin(uint16_t object)
{
	uint8_t action_step = 0;

	OBJECT(object)->animation = 0x91u;
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
}

/* On the shock's marked frames puts in its sparks by robot_sparks_by_frame_91. */
uint16_t robot_shock_91_sparks(uint16_t object, uint16_t steps)
{
	uint32_t carry = 0;
	uint16_t command = 0, ignored16 = 0, ignored16_2 = 0;
	uint8_t animation_flags = 0, animation_flags_2 = 0, action_step = 0, frame = 0, frame_2 = 0, animation_flags_3 = 0, action_step_2 = 0;
	uint16_t spark_record = 0;

	animation_flags = OBJECT(object)->animation_flags;
	if ((animation_flags & 2u) == 0u)
	{
		animation_flags_2 = OBJECT(object)->animation_flags;
		if (animation_flags_2 & 1u)
		{
			action_step = OBJECT(object)->action_step;
			OBJECT(object)->action_step = action_step + 1u;
		}
		return steps;
	}
	frame = OBJECT(object)->frame;
	if (frame == 6u)
	{
		command = 0x2300u;
		vector_queue_sound(command);
	}
	frame_2 = OBJECT(object)->frame;
	spark_record = robot_sparks_by_frame_91[(int8_t)((uint8_t)((uint32_t)frame_2 << 1)) / 2];
	leftover_y = spark_record;
	if ((int16_t)spark_record >= 0)
		vector_spawn_child(object, &ignored16, &steps, &ignored16_2, &carry);
	animation_flags_3 = OBJECT(object)->animation_flags;
	if (animation_flags_3 & 1u)
	{
		action_step_2 = OBJECT(object)->action_step;
		OBJECT(object)->action_step = action_step_2 + 1u;
	}
	return steps;
}

/* The robot's own hit reaction (step 4), by field 29. */
void robot_hit_reaction(uint16_t object)
{
	uint8_t action_step = 0;

	action_step = OBJECT(object)->action_step;
	switch ((int8_t)(uint8_t)((uint32_t)action_step << 1))
	{
	case 0:
		robot_hit_land(object);
		break;
	case 2:
		robot_hit_strike_back(object);
		break;
	case 4:
		robot_hit_strike_back_recover(object);
		break;
	case 6:
		robot_hit_strike_back_second(object);
		break;
	case 8:
		robot_hit_choose_action(object);
		break;
	case 10:
		robot_break_down(object);
		break;
	case 12:
		robot_explode(object);
		break;
	}
	vector_stop_at_screen_edges(object);
	check_floor(object, 0u);
}

/* Flashes the hit robot with the hit sound until it lands; beaten, it plays its breaking down, otherwise
   it strikes back. */
void robot_hit_land(uint16_t object)
{
	uint32_t carry = 0;
	uint16_t command = 0, ignored16 = 0;
	uint8_t vitality = 0, action_step = 0;
	uint16_t hit_box = 0;

	robot_flash(object);
	hit_box = OBJECT(object)->hit_box;
	leftover_y = hit_box;
	vector_set_hit_box(object);
	command = 0x6300u;
	vector_queue_sound(command);
	vector_apply_gravity(object, &ignored16, &carry);
	if (carry == 0u)
		return;
	OBJECT(object)->x_speed = 0;
	OBJECT(object)->y_speed = 0;
	vitality = OBJECT(object)->vitality;
	if (vitality != 0u)
	{
		OBJECT(object)->animation = 0x90u;
		action_step = OBJECT(object)->action_step;
		OBJECT(object)->action_step = action_step + 1u;
		return;
	}
	OBJECT(object)->animation = 0x88u;
	OBJECT(object)->action_step = 5u;
}

/* Flashes the robot while its strike back reaches the first blow. */
void robot_hit_strike_back(uint16_t object)
{
	robot_flash(object);
	robot_punch_first_hit(object);
}

/* The robot's strike back: back to its plain hit box. */
void robot_hit_strike_back_recover(uint16_t object)
{
	robot_punch_recover(object);
}

/* The robot's strike back: the second blow. */
void robot_hit_strike_back_second(uint16_t object)
{
	robot_punch_second_hit(object);
}

/* When the strike back ends, takes the robot's next action and status from robot_actions_after_hit and
   robot_status_after_hit, flashing until it acts. */
void robot_hit_choose_action(uint16_t object)
{
	uint8_t hit_index = 0;
	uint8_t animation_flags = 0, attributes = 0, animation_flags_2 = 0, hit_round = 0, hit_round_2 = 0;
	uint16_t hit_box = 0;

	hit_box = OBJECT(object)->hit_box;
	leftover_y = hit_box;
	vector_set_hit_box(object);
	animation_flags = OBJECT(object)->animation_flags;
	if (animation_flags & 1u)
	{
		OBJECT(object)->flags = 0xC4u;
		OBJECT(object)->robot.flashing = 0xC4u;
		attributes = OBJECT(object)->attributes;
		OBJECT(object)->attributes = attributes & 0x7Fu;
		animation_flags_2 = OBJECT(object)->animation_flags;
		OBJECT(object)->animation_flags = animation_flags_2 | 0x80u;
		hit_round = OBJECT(object)->robot.hit_round;
		OBJECT(object)->robot.hit_round = hit_round - 1u;
		hit_round_2 = OBJECT(object)->robot.hit_round;
		hit_index = hit_round_2 & 7u;
		OBJECT(object)->action = robot_actions_after_hit[hit_index];
		OBJECT(object)->action_step = 0u;
		OBJECT(object)->flags = (uint8_t)(CHILD_OBJECT(robot_piece_children_ADDRESS + hit_index - 0x8u)->dx >> 8u);
		OBJECT(object)->state = 3u;
	}
}

/* Flashes the beaten robot until its breaking down ends, then waits 64 frames. */
void robot_break_down(uint16_t object)
{
	uint8_t animation_flags = 0, attributes = 0, animation_flags_2 = 0, action_step = 0;

	robot_flash(object);
	animation_flags = OBJECT(object)->animation_flags;
	if (animation_flags & 1u)
	{
		OBJECT(object)->timer = 0x40u;
		attributes = OBJECT(object)->attributes;
		OBJECT(object)->attributes = attributes & 0x7Fu;
		animation_flags_2 = OBJECT(object)->animation_flags;
		OBJECT(object)->animation_flags = animation_flags_2 | 0x80u;
		action_step = OBJECT(object)->action_step;
		OBJECT(object)->action_step = action_step + 1u;
	}
}

/* Flashes the beaten robot for its wait, then bursts it into pieces and counts it beaten. */
void robot_explode(uint16_t object)
{
	uint8_t timer = 0;

	robot_flash(object);
	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer != 1u)
		return;
	robot_put_in_pieces(object);
	OBJECT(object)->flags = 0u;
	vector_enemy_score_and_release(object, 0u);
}

/* Puts in the robot's 8 pieces (5280 type 33, states 0-7) with the explosion's sound. */
void robot_put_in_pieces(uint16_t object)
{
	uint32_t carry = 0;
	uint16_t child_record = 0, command = 0, ignored16 = 0, ignored16_2 = 0;
	uint8_t pieces_before = 0;

	command = 0x6E00u;
	vector_queue_sound(command);
	robot_pieces_left = 8u;
	child_record = robot_piece_children_ADDRESS;
	do
	{
		leftover_y = child_record;
		vector_spawn_child(object, &child_record, &ignored16, &ignored16_2, &carry);
		if (carry == 0u)
			break;
		child_record += 8u;
		pieces_before = robot_pieces_left;
		robot_pieces_left = pieces_before - 1u;
	} while (pieces_before != 1u);
	leftover_y = child_record;
}

/* Starts the robot's launch with a sound. */
void robot_launch_part_start(uint16_t object)
{
	uint16_t command = 0;
	uint8_t action_step = 0;

	OBJECT(object)->animation = 0x97u;
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
	command = 0x2700u;
	vector_queue_sound(command);
}

/* When that animation ends, makes the robot hittable and sends off its part (4D40 type 17), then waits
   128 frames. */
uint16_t robot_launch_part_release(uint16_t object, uint16_t steps)
{
	uint32_t carry = 0;
	uint16_t child_object = 0, part = 0;
	uint8_t animation_flags = 0, action_step = 0;

	animation_flags = OBJECT(object)->animation_flags;
	if ((animation_flags & 1u) == 0u)
		return steps;
	OBJECT(object)->flags = 0xC0u;
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
	OBJECT(object)->timer = 0x80u;
	leftover_y = robot_launch_part_release_child_ADDRESS;
	child_object = robot_launch_part_release_child_ADDRESS;
	spawn_list_2_child(object, child_object, &part, &carry);
	return part;
}

/* Counts the wait down and goes on with a sound. */
void robot_launch_part_wait(uint16_t object)
{
	uint16_t command = 0;
	uint8_t timer = 0, action_step = 0;

	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer != 1u)
		return;
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
	command = 0x2700u;
	vector_queue_sound(command);
}

/* Sets the launched part up, big, for 32 frames. */
uint16_t robot_part_setup(uint16_t object)
{
	uint16_t setup = 0;
	uint8_t state = 0;

	setup = robot_part_object_setup_ADDRESS;
	vector_object_setup(object, setup);
	OBJECT(object)->flags = 0x80u;
	OBJECT(object)->zoom_x = 0xC0u;
	OBJECT(object)->zoom_y = 0xC0u;
	OBJECT(object)->timer = 0x20u;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
	return setup;
}

/* Counts down, then sends the part off into the back with a sound. */
void robot_part_launch(uint16_t object)
{
	uint16_t command = 0;
	uint8_t timer = 0, state = 0;

	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer != 1u)
		return;
	OBJECT(object)->animation = 0x99u;
	OBJECT(object)->flags = 0x90u;
	OBJECT(object)->y_speed = -0x80;
	OBJECT(object)->timer = 0x30u;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
	command = 0x2300u;
	vector_queue_sound(command);
}

/* Shrinks the part by robot_part_zooms as it goes, stops it, and frees its slot at the end. */
uint16_t robot_part_fly_away(uint16_t object, uint16_t states)
{
	uint8_t zoom = 0;
	uint16_t zooms = 0;
	uint8_t timer = 0, timer_2 = 0, timer_3 = 0;

	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer == 1u)
	{
		OBJECT(object)->flags = 0u;
		return states;
	}
	timer_2 = OBJECT(object)->timer;
	if (timer_2 == 0x1Au)
		OBJECT(object)->y_speed = 0;
	OBJECT(object)->flags = 0x90u;
	zooms = robot_part_zooms_ADDRESS;
	timer_3 = OBJECT(object)->timer;
	zoom = robot_part_zooms[(int8_t)timer_3];
	OBJECT(object)->zoom_x = zoom;
	OBJECT(object)->zoom_y = zoom;
	return zooms;
}
