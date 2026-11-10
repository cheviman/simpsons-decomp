/**
 *    Name:        objects/fat_goon_actions.c
 *    Description: the fat goons' attacks: the enemy actions bank 15 handles
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    09-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the game's 053248 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

/* Starts the fat goon walking away from its target for 32 frames. */
void fat_goon_back_off(uint16_t object)
{
	uint8_t target_direction = 0, action_step = 0;
	uint16_t x_speed = 0;

	face_target(object);
	OBJECT(object)->animation = 0x86u;
	OBJECT(object)->x_speed = 0x100;
	target_direction = OBJECT(object)->target_direction;
	if ((int8_t)(target_direction - 0x40u) < 0)
	{
		x_speed = OBJECT(object)->x_speed;
		OBJECT(object)->x_speed = 0u - x_speed;
	}
	OBJECT(object)->timer = 0x20u;
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
	vector_face_direction(object);
}

/* When the walk away ends, goes back to the fight. */
void fat_goon_back_off_end(uint16_t object)
{
	uint8_t timer = 0;

	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer != 1u)
		return;
	OBJECT(object)->state = 2u;
	OBJECT(object)->timer = 0u;
}

/* Starts the bump's wind-up (animation B2), longer the higher the game's rank. */
void fat_goon_bump_wind_up(uint16_t object)
{
	uint8_t action_step = 0;

	OBJECT(object)->animation = 0xB2u;
	OBJECT(object)->timer = 0x40u + rank;
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
	face_target(object);
}

/* At the animation's mark, backs the fat goon into its target with the bump's hit box and sound 7600. */
uint16_t fat_goon_bump_move(uint16_t object, uint16_t y)
{
	uint32_t carry = 0;
	uint16_t box = 0, command = 0;
	uint8_t animation_flags = 0, attributes = 0, action_step = 0, attributes_2 = 0;
	uint16_t x_speed = 0;

	animation_flags = OBJECT(object)->animation_flags;
	if ((animation_flags & 2u) == 0u)
		return y;
	OBJECT(object)->x_speed = 0x80;
	attributes = OBJECT(object)->attributes;
	if ((attributes & 0x40u) != 0u)
	{
		x_speed = OBJECT(object)->x_speed;
		OBJECT(object)->x_speed = 0u - x_speed;
	}
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
	face_movement(object);
	attributes_2 = OBJECT(object)->attributes;
	OBJECT(object)->attributes = attributes_2 ^ 0x40u;
	command = 0x7600u;
	carry = vector_queue_sound(command);
	box = fat_goon_bump_move_box_ADDRESS;
	vector_set_hit_box(object, box);
	return box;
}

/* When the bump's time runs out, stops and turns the fat goon round. */
uint16_t fat_goon_bump_stop(uint16_t object, uint16_t y)
{
	uint16_t box = 0;
	uint8_t timer = 0, attributes = 0, action_step = 0;

	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer != 1u)
		return y;
	OBJECT(object)->x_speed = 0;
	attributes = OBJECT(object)->attributes;
	OBJECT(object)->attributes = attributes ^ 0x40u;
	OBJECT(object)->animation = 0x93u;
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
	OBJECT(object)->timer = 0x20u;
	box = fat_goon_body_box_ADDRESS;
	vector_set_hit_box(object, box);
	return box;
}

/* After 32 frames goes back to the fight. */
void fat_goon_bump_end(uint16_t object)
{
	uint8_t timer = 0;

	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer == 1u)
	{
		OBJECT(object)->state = 2u;
		OBJECT(object)->timer = 0u;
		return;
	}
}

/* Starts the fat goon walking towards its target for up to 64 frames. */
void fat_goon_walk_up(uint16_t object)
{
	uint8_t target_direction = 0, action_step = 0;
	uint16_t x_speed = 0;

	OBJECT(object)->animation = 0x90u;
	face_target(object);
	OBJECT(object)->x_speed = 0x180;
	OBJECT(object)->y_speed = 0;
	target_direction = OBJECT(object)->target_direction;
	if ((int8_t)(target_direction - 0x40u) >= 0)
	{
		x_speed = OBJECT(object)->x_speed;
		OBJECT(object)->x_speed = 0u - x_speed;
	}
	OBJECT(object)->timer = 0x40u;
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
}

/* Walks until near the target, then winds up for a time by the players in the game. */
uint16_t fat_goon_walk_up_to_target(uint16_t object, uint16_t steps)
{
	uint16_t target = 0;
	uint8_t timer = 0, action_step = 0, action_step_2 = 0;
	uint16_t target_2 = 0, target_dx = 0, z = 0, floor_z = 0;

	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer == 1u)
	{
		OBJECT(object)->state = 2u;
		OBJECT(object)->timer = 0u;
		return steps;
	}
	target_2 = OBJECT(object)->target;
	target = target_2;
	vector_measure_target(object, target);
	target_dx = OBJECT(object)->target_dx;
	if (target_dx >= 0x20u)
		return target;
	OBJECT(object)->x_speed = 0;
	z = OBJECT(target)->z;
	floor_z = OBJECT(target)->floor_z;
	if (z != floor_z)
	{
		OBJECT(object)->timer = 1u;
		action_step = OBJECT(object)->action_step;
		OBJECT(object)->action_step = action_step + 1u;
		return target;
	}
	OBJECT(object)->animation = 0xAAu;
	target = fat_goon_strike_waits_by_players_ADDRESS;
	OBJECT(object)->timer = fat_goon_strike_waits_by_players[(int8_t)player_count];
	action_step_2 = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step_2 + 1u;
	return target;
}

/* When the wind-up ends, swings (animation A4). */
void fat_goon_walk_up_swing(uint16_t object)
{
	uint8_t timer = 0, action_step = 0;

	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer == 1u)
	{
		OBJECT(object)->animation = 0xA4u;
		action_step = OBJECT(object)->action_step;
		OBJECT(object)->action_step = action_step + 1u;
	}
}

/* At the swing's mark, puts out the strike's hit box. */
uint16_t fat_goon_walk_up_hit(uint16_t object, uint16_t y)
{
	uint16_t box = 0;
	uint8_t animation_flags = 0, action_step = 0;

	animation_flags = OBJECT(object)->animation_flags;
	if ((animation_flags & 2u) == 0u)
		return y;
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
	box = fat_goon_walk_up_hit_box_ADDRESS;
	vector_set_hit_box(object, box);
	return box;
}

/* Takes the strike's hit box back to the body's, then waits for the animation's end. */
uint16_t fat_goon_strike_recover(uint16_t object)
{
	uint16_t box = 0;
	uint8_t action_step = 0;

	box = fat_goon_body_box_ADDRESS;
	vector_set_hit_box(object, box);
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
	fat_goon_strike_end(object);
	return box;
}

/* When the animation ends, goes back to the fight. */
void fat_goon_strike_end(uint16_t object)
{
	uint8_t animation_flags = 0;

	animation_flags = OBJECT(object)->animation_flags;
	if ((animation_flags & 1u) == 0u)
		return;
	OBJECT(object)->state = 2u;
	OBJECT(object)->timer = 0u;
}

/* Starts the body slam's wind-up (animation AA) facing the target. */
void fat_goon_body_slam_wind_up(uint16_t object)
{
	uint8_t action_step = 0;

	OBJECT(object)->animation = 0xAAu;
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
	face_target(object);
}

/* When the wind-up ends, jumps forward (animation A8), keeping the jump's direction. */
void fat_goon_body_slam_jump(uint16_t object)
{
	uint8_t animation_flags = 0, attributes = 0, x_speed_2 = 0, action_step = 0;
	uint16_t x_speed = 0;

	animation_flags = OBJECT(object)->animation_flags;
	if ((animation_flags & 1u) == 0u)
		return;
	OBJECT(object)->x_speed = 0x200;
	attributes = OBJECT(object)->attributes;
	if ((attributes & 0x40u) != 0u)
	{
		x_speed = OBJECT(object)->x_speed;
		OBJECT(object)->x_speed = 0u - x_speed;
	}
	x_speed_2 = (uint8_t)(OBJECT(object)->x_speed >> 8u);
	OBJECT(object)->fat_goon.direction = x_speed_2;
	OBJECT(object)->z_speed = 0x600;
	OBJECT(object)->animation = 0xA8u;
	OBJECT(object)->timer = 0x20u;
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
}

/* Falls with the body slam's hit box once the jump has risen; on landing takes the body's hit box. */
uint16_t fat_goon_body_slam_fall(uint16_t object, uint16_t y)
{
	uint32_t carry = 0;
	uint16_t box = 0;
	uint8_t timer = 0, action_step = 0;
	uint16_t z_speed = 0;

	z_speed = OBJECT(object)->z_speed;
	OBJECT(object)->z_speed = z_speed - 0x40u;
	carry = vector_check_landing(object);
	if (carry == 0u)
	{
		timer = OBJECT(object)->timer;
		OBJECT(object)->timer = timer - 1u;
		if (timer != 1u)
			return y;
		box = fat_goon_body_slam_fall_box_ADDRESS;
		vector_set_hit_box(object, box);
		return box;
	}
	OBJECT(object)->x_speed = 0;
	box = fat_goon_body_box_ADDRESS;
	vector_set_hit_box(object, box);
	OBJECT(object)->timer = 4u;
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
	return box;
}

/* After landing, bounces back the other way (animation A9). */
void fat_goon_body_slam_bounce(uint16_t object)
{
	uint8_t timer = 0, direction = 0, action_step = 0;
	uint16_t x_speed = 0;

	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer != 1u)
		return;
	OBJECT(object)->animation = 0xA9u;
	direction = OBJECT(object)->fat_goon.direction;
	if ((int8_t)direction >= 0)
	{
		x_speed = OBJECT(object)->x_speed;
		OBJECT(object)->x_speed = 0u - x_speed;
	}
	OBJECT(object)->timer = 8u;
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
}

/* After 8 frames goes back to the fight. */
void fat_goon_body_slam_end(uint16_t object)
{
	uint8_t timer = 0;

	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer != 1u)
		return;
	OBJECT(object)->state = 2u;
	OBJECT(object)->timer = 0u;
}

/* Winds up (animation AA) for a time by the players in the game, at once if the target is in the air. */
uint16_t fat_goon_strike_wind_up(uint16_t object)
{
	uint16_t target = 0, waits = 0;
	uint8_t action_step = 0, action_step_2 = 0;
	uint16_t target_2 = 0, z = 0, floor_z = 0;

	target_2 = OBJECT(object)->target;
	target = target_2;
	z = OBJECT(target)->z;
	floor_z = OBJECT(target)->floor_z;
	if (z != floor_z)
	{
		OBJECT(object)->timer = 1u;
		action_step = OBJECT(object)->action_step;
		OBJECT(object)->action_step = action_step + 1u;
		face_target(object);
		return target;
	}
	OBJECT(object)->animation = 0xAAu;
	waits = fat_goon_strike_waits_by_players_ADDRESS;
	OBJECT(object)->timer = fat_goon_strike_waits_by_players[(int8_t)player_count];
	action_step_2 = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step_2 + 1u;
	face_target(object);
	return waits;
}

/* When the wind-up ends, swings (animation AB). */
void fat_goon_strike_swing(uint16_t object)
{
	uint8_t timer = 0, action_step = 0;

	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer != 1u)
		return;
	OBJECT(object)->animation = 0xABu;
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
	face_target(object);
}

/* At the swing's mark, puts out the strike's hit box. */
uint16_t fat_goon_strike_hit(uint16_t object, uint16_t y)
{
	uint8_t animation_flags = 0, action_step = 0;

	animation_flags = OBJECT(object)->animation_flags;
	if ((animation_flags & 2u) == 0u)
		return y;
	y = fat_goon_strike_hit_box_ADDRESS;
	vector_set_hit_box(object, y);
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
	return y;
}

/* When the wind-up ends, swings further out (animation A3). */
void fat_goon_reach_strike_swing(uint16_t object)
{
	uint8_t timer = 0, action_step = 0;

	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer != 1u)
		return;
	OBJECT(object)->animation = 0xA3u;
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
	face_target(object);
}

/* At the swing's mark, puts out the longer strike's hit box. */
uint16_t fat_goon_reach_strike_hit(uint16_t object, uint16_t y)
{
	uint8_t animation_flags = 0, action_step = 0;

	animation_flags = OBJECT(object)->animation_flags;
	if ((animation_flags & 2u) == 0u)
		return y;
	y = fat_goon_reach_strike_hit_box_ADDRESS;
	vector_set_hit_box(object, y);
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
	return y;
}

/* Does nothing: action 0D starts here and never leaves. */
void fat_goon_action_wait(void)
{
}

/* Starts the heavy strike's swing (animation A3) facing the target. */
void fat_goon_heavy_strike_swing(uint16_t object)
{
	uint8_t action_step = 0;

	OBJECT(object)->animation = 0xA3u;
	face_target(object);
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
}

/* At the swing's mark, puts out the heavy strike's hit box with sound 2000. */
uint16_t fat_goon_heavy_strike_hit(uint16_t object, uint16_t y)
{
	uint32_t carry = 0;
	uint16_t box = 0, command = 0;
	uint8_t animation_flags = 0, action_step = 0;

	animation_flags = OBJECT(object)->animation_flags;
	if ((animation_flags & 2u) == 0u)
		return y;
	box = fat_goon_heavy_strike_hit_box_ADDRESS;
	vector_set_hit_box(object, box);
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
	command = 0x2000u;
	carry = vector_queue_sound(command);
	return box;
}

/* Heads for its target to grab it, unless the target is gone or already held. */
uint16_t fat_goon_grab_approach(uint16_t object)
{
	uint8_t direction = 0;
	uint16_t d = 0, heading = 0, target = 0;
	uint8_t state = 0, hold_presses = 0, action_step = 0;
	uint16_t target_2 = 0;

	target_2 = OBJECT(object)->target;
	target = target_2;
	state = OBJECT(target)->state;
	if ((int8_t)state < 0)
	{
		OBJECT(object)->state = 2u;
		OBJECT(object)->timer = 0u;
		return target;
	}
	hold_presses = OBJECT(target)->player.hold_presses;
	if (hold_presses != 0u)
	{
		OBJECT(object)->state = 2u;
		OBJECT(object)->timer = 0u;
		return target;
	}
	face_target(object);
	OBJECT(object)->timer = 0x40u;
	d = vector_direction_to(object, target);
	direction = (uint8_t)(d >> 8);
	heading = ((uint32_t)direction << 8) | 0x30u;
	vector_set_speed_by_direction(object, heading);
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
	enemy_restart_walk_animation(object);
	return target;
}

/* Closes in on the target and, when level with it on the floor, holds it (the animation by the held
   character). */
void fat_goon_grab(uint16_t object, uint16_t *p_y, uint16_t *p_target)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t a = 0, b = 0, direction = 0;
	uint16_t d = 0, heading = 0, target = 0;
	uint8_t stack = 0;
	uint8_t state = 0, timer = 0, blink_frames = 0, hold_presses = 0, attributes = 0, attributes_2 = 0, shadow_player = 0, points = 0, shadow_player_2 = 0, action_step = 0;
	uint16_t target_2 = 0, hit_by = 0, target_dx = 0, target_dy = 0, floor_z = 0, z = 0, floor_z_2 = 0, t1 = 0, t2 = 0;
	uint32_t action_halfword = 0, action_halfword_2 = 0;

	target_2 = OBJECT(object)->target;
	target = target_2;
	if ((OBJECT(object)->flags & 0x20u) == 0u)
	{
		state = OBJECT(target)->state;
		if ((int8_t)state < 0)
		{
			OBJECT(object)->state = 2u;
			OBJECT(object)->timer = 0u;
		}
		else
		{
			timer = OBJECT(object)->timer;
			OBJECT(object)->timer = timer - 1u;
			if (timer != 1u)
			{
				d = vector_direction_to(object, target);
				direction = (uint8_t)(d >> 8);
				heading = ((uint32_t)direction << 8) | 0x20u;
				vector_set_speed_by_direction(object, heading);
				vector_choose_walk_animation(object);
			}
			else
			{
				OBJECT(object)->state = 2u;
				OBJECT(object)->timer = 0u;
			}
		}
	}
	else
	{
		blink_frames = OBJECT(target)->player.blink_frames;
		if (blink_frames != 0u)
		{
			a = 0xBu;
			b = 0u;
			action_halfword = ((uint32_t)a << 8) | b;
			OBJECT(object)->action = (uint8_t)(action_halfword >> 8u);
			OBJECT(object)->action_step = (uint8_t)action_halfword;
			OBJECT(object)->x_speed = 0;
			OBJECT(object)->y_speed = 0;
		}
		else
		{
			hold_presses = OBJECT(target)->player.hold_presses;
			if (hold_presses != 0u)
			{
				a = 0xCu;
				b = 0u;
				action_halfword_2 = ((uint32_t)a << 8) | b;
				OBJECT(object)->action = (uint8_t)(action_halfword_2 >> 8u);
				OBJECT(object)->action_step = (uint8_t)action_halfword_2;
				OBJECT(object)->x_speed = 0;
				OBJECT(object)->y_speed = 0;
			}
			else
			{
				hit_by = OBJECT(object)->hit_by;
				if (target != hit_by)
				{
					state = OBJECT(target)->state;
					if ((int8_t)state < 0)
					{
						OBJECT(object)->state = 2u;
						OBJECT(object)->timer = 0u;
					}
					else
					{
						timer = OBJECT(object)->timer;
						OBJECT(object)->timer = timer - 1u;
						if (timer != 1u)
						{
							d = vector_direction_to(object, target);
							direction = (uint8_t)(d >> 8);
							heading = ((uint32_t)direction << 8) | 0x20u;
							vector_set_speed_by_direction(object, heading);
							vector_choose_walk_animation(object);
						}
						else
						{
							OBJECT(object)->state = 2u;
							OBJECT(object)->timer = 0u;
						}
					}
				}
				else
				{
					target_dx = OBJECT(object)->target_dx;
					if (target_dx >= 8u)
					{
						state = OBJECT(target)->state;
						if ((int8_t)state < 0)
						{
							OBJECT(object)->state = 2u;
							OBJECT(object)->timer = 0u;
						}
						else
						{
							timer = OBJECT(object)->timer;
							OBJECT(object)->timer = timer - 1u;
							if (timer != 1u)
							{
								d = vector_direction_to(object, target);
								direction = (uint8_t)(d >> 8);
								heading = ((uint32_t)direction << 8) | 0x20u;
								vector_set_speed_by_direction(object, heading);
								vector_choose_walk_animation(object);
							}
							else
							{
								OBJECT(object)->state = 2u;
								OBJECT(object)->timer = 0u;
							}
						}
					}
					else
					{
						target_dy = OBJECT(object)->target_dy;
						if (target_dy >= 4u)
						{
							state = OBJECT(target)->state;
							if ((int8_t)state < 0)
							{
								OBJECT(object)->state = 2u;
								OBJECT(object)->timer = 0u;
							}
							else
							{
								timer = OBJECT(object)->timer;
								OBJECT(object)->timer = timer - 1u;
								if (timer != 1u)
								{
									d = vector_direction_to(object, target);
									direction = (uint8_t)(d >> 8);
									heading = ((uint32_t)direction << 8) | 0x20u;
									vector_set_speed_by_direction(object, heading);
									vector_choose_walk_animation(object);
								}
								else
								{
									OBJECT(object)->state = 2u;
									OBJECT(object)->timer = 0u;
								}
							}
						}
						else
						{
							floor_z = OBJECT(target)->floor_z;
							a = (uint8_t)(floor_z >> 8);
							b = (uint8_t)floor_z;
							z = OBJECT(target)->z;
							if ((uint16_t)(((uint32_t)a << 8) | b) != z)
							{
								state = OBJECT(target)->state;
								if ((int8_t)state < 0)
								{
									OBJECT(object)->state = 2u;
									OBJECT(object)->timer = 0u;
								}
								else
								{
									timer = OBJECT(object)->timer;
									OBJECT(object)->timer = timer - 1u;
									if (timer != 1u)
									{
										d = vector_direction_to(object, target);
										direction = (uint8_t)(d >> 8);
										heading = ((uint32_t)direction << 8) | 0x20u;
										vector_set_speed_by_direction(object, heading);
										vector_choose_walk_animation(object);
									}
									else
									{
										OBJECT(object)->state = 2u;
										OBJECT(object)->timer = 0u;
									}
								}
							}
							else
							{
								floor_z_2 = OBJECT(object)->floor_z;
								if ((uint16_t)(((uint32_t)a << 8) | b) != floor_z_2)
								{
									state = OBJECT(target)->state;
									if ((int8_t)state < 0)
									{
										OBJECT(object)->state = 2u;
										OBJECT(object)->timer = 0u;
									}
									else
									{
										timer = OBJECT(object)->timer;
										OBJECT(object)->timer = timer - 1u;
										if (timer != 1u)
										{
											d = vector_direction_to(object, target);
											direction = (uint8_t)(d >> 8);
											heading = ((uint32_t)direction << 8) | 0x20u;
											vector_set_speed_by_direction(object, heading);
											vector_choose_walk_animation(object);
										}
										else
										{
											OBJECT(object)->state = 2u;
											OBJECT(object)->timer = 0u;
										}
									}
								}
								else
								{
									vector_enemy_leave_side(object, target);
									OBJECT(target)->player.holder = object;
									OBJECT(target)->player.hold_presses = 0xCu;
									OBJECT(target)->flags |= 0x20u;
									OBJECT(target)->hit = 3u;
									OBJECT(object)->x_speed = 0;
									OBJECT(object)->y_speed = 0;
									t1 = OBJECT(target)->x;
									OBJECT(object)->x = t1;
									t2 = OBJECT(target)->y;
									OBJECT(object)->y = t2;
									attributes = OBJECT(target)->attributes;
									grab_facing = (attributes & 0x40u) ^ 0x40u;
									attributes_2 = OBJECT(object)->attributes;
									OBJECT(object)->attributes = (attributes_2 & 0xBFu) | grab_facing;
									shadow_player = OBJECT(target)->shadow_player;
									stack = shadow_player & 0x70u;
									points = OBJECT(object)->points;
									OBJECT(object)->points = (points & 0x8Fu) | stack;
									y = fat_goon_hold_animations_ADDRESS;
									shadow_player_2 = OBJECT(target)->shadow_player;
									OBJECT(object)->animation = fat_goon_hold_animations[(((shadow_player_2 >> 1) >> 1) >> 1) >> 1] | 0x80u;
									OBJECT(object)->timer = 6u;
									action_step = OBJECT(object)->action_step;
									OBJECT(object)->action_step = action_step + 1u;
								}
							}
						}
					}
				}
			}
		}
	}
	*p_y = y;
	*p_target = target;
}

/* Squeezes the held player (sound 2000 every 16 frames) until it breaks free, which costs the fat goon
   life, or is beaten. */
uint16_t fat_goon_squeeze(uint16_t object)
{
	uint32_t carry = 0;
	uint8_t vitality = 0;
	uint16_t command = 0, target = 0;
	uint8_t timer = 0, timer_2 = 0, hold_presses = 0, vitality_2 = 0, vitality_3 = 0, squeeze_step = 0, squeeze_step_2 = 0;
	uint16_t target_2 = 0;

	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	timer_2 = OBJECT(object)->timer;
	if ((timer_2 & 0xFu) == 0u)
	{
		command = 0x2000u;
		carry = vector_queue_sound(command);
	}
	OBJECT(object)->attack = 0u;
	target_2 = OBJECT(object)->target;
	target = target_2;
	hold_presses = OBJECT(target)->player.hold_presses;
	if (hold_presses == 0u)
	{
		vitality_2 = OBJECT(object)->vitality;
		vitality = vitality_2 - 3u;
		OBJECT(object)->vitality = vitality;
		if ((int8_t)vitality < 0)
			OBJECT(object)->vitality = 0u;
		OBJECT(object)->attack = 0u;
		OBJECT(object)->flags = 0x88u;
		OBJECT(object)->state = 4u;
		OBJECT(object)->action = (random_number & 1u) + 2u;
		OBJECT(object)->action_step = 0u;
		return target;
	}
	vitality_3 = OBJECT(target)->vitality;
	if (vitality_3 == 0u)
	{
		OBJECT(object)->attack = 0u;
		OBJECT(object)->state = 2u;
		OBJECT(object)->timer = 0u;
		return target;
	}
	squeeze_step = OBJECT(object)->fat_goon.squeeze_step;
	if (squeeze_step == 2u)
	{
		squeeze_step_2 = OBJECT(object)->fat_goon.squeeze_step;
		OBJECT(object)->fat_goon.squeeze_step = squeeze_step_2 + 1u;
		OBJECT(object)->action_step = 3u;
	}
	return target;
}

/* When the squeeze's animation ends, starts it again, and squeezes. */
uint16_t fat_goon_squeeze_again(uint16_t object)
{
	uint8_t animation_flags = 0, action_step = 0;

	animation_flags = OBJECT(object)->animation_flags;
	if (animation_flags & 1u)
	{
		OBJECT(object)->fat_goon.squeeze_step = 1u;
		action_step = OBJECT(object)->action_step;
		OBJECT(object)->action_step = action_step - 1u;
	}
	return fat_goon_squeeze(object);
}
