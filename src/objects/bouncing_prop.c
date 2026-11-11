/**
 *    Name:        objects/bouncing_prop.c
 *    Description: the kind 05 prop a stage event drops in (5280 type FB)
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    10-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the game's 053248 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

/* Marks the prop done (field 37) once the object in field 2A has gone. */
uint16_t bouncing_prop_check_owner(uint16_t object, uint16_t owner)
{
	uint8_t done = 0, done_2 = 0;
	uint16_t owner_2 = 0;

	done = OBJECT(object)->bouncing_prop.done;
	if (done == 0u)
	{
		owner_2 = OBJECT(object)->bouncing_prop.owner;
		owner = owner_2;
		if (OBJECT(owner)->flags == 0u)
		{
			done_2 = OBJECT(object)->bouncing_prop.done;
			OBJECT(object)->bouncing_prop.done = done_2 + 1u;
		}
	}
	return owner;
}

/* The prop leaving (step FE), by field 29: it flies off into the distance. */
uint16_t bouncing_prop_leave(uint16_t object)
{
	uint16_t steps = 0;
	uint8_t action_step = 0;

	for (;;)
	{
		steps = bouncing_prop_leave_steps_ADDRESS;
		action_step = OBJECT(object)->action_step;
		switch ((int8_t)(uint8_t)((uint32_t)action_step << 1))
		{
		case 0:
			bouncing_prop_leave_start(object);
			return steps;
		case 2:
			bouncing_prop_fly_away(object);
			return steps;
		case 4:
			bouncing_prop_shrink_away(object);
			return steps;
		case 6:
			break;
		case -18:
			continue;
		case -16:
			bouncing_prop_fall_in(object);
			return steps;
		case -14:
			return bouncing_prop_setup(object);
		case -12:
		case -10:
			return bouncing_prop_follow(object, steps);
		case -8:
			bouncing_prop_stop(object);
			return steps;
		case -6:
			bouncing_prop_bounce_start(object);
			return steps;
		case -4:
			return bouncing_prop_bounce(object);
		case -2:
			bouncing_prop_knocked(object);
			return steps;
		}
		break;
	}
	bouncing_prop_rise_out(object);
	return steps;
}

/* Stops the prop at its plain size and throws it up. */
void bouncing_prop_leave_start(uint16_t object)
{
	uint8_t action_step = 0;

	OBJECT(object)->zoom_x = 0x40u;
	OBJECT(object)->zoom_y = 0x40u;
	OBJECT(object)->x_speed = 0;
	OBJECT(object)->y_speed = 0;
	OBJECT(object)->z_speed = 0x200;
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
	bouncing_prop_fly_away(object);
}

/* Once high enough, sends the prop flying into the back for 64 frames; past scroll 03A2 it just rises
   out of the screen. */
void bouncing_prop_fly_away(uint16_t object)
{
	uint8_t action_step = 0;
	uint16_t z = 0, camera_x_now = 0;

	z = OBJECT(object)->z;
	if (z < 0x40u)
		return;
	camera_x_now = camera_x;
	if (camera_x_now > 0x3A2u)
	{
		OBJECT(object)->animation = 0x95u;
		OBJECT(object)->action_step = 3u;
		return;
	}
	OBJECT(object)->animation = 0x94u;
	OBJECT(object)->y_speed = 0x100;
	OBJECT(object)->timer = 0x40u;
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
}

/* Slows the prop's rise and grows its zoom as it goes away, then frees its slot. */
void bouncing_prop_shrink_away(uint16_t object)
{
	uint8_t timer = 0;
	uint16_t z_speed = 0, zoom_x = 0;
	uint32_t zoom_x_halfword = 0;

	z_speed = OBJECT(object)->z_speed;
	OBJECT(object)->z_speed = z_speed - 0x10u;
	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer != 1u)
	{
		zoom_x = (((uint32_t)OBJECT(object)->zoom_x << 8u) | OBJECT(object)->zoom_y);
		zoom_x_halfword = zoom_x + 0x303u;
		OBJECT(object)->zoom_x = (uint8_t)(zoom_x_halfword >> 8u);
		OBJECT(object)->zoom_y = (uint8_t)zoom_x_halfword;
		OBJECT(object)->flags = 0x90u;
		return;
	}
	OBJECT(object)->flags = 0u;
}

/* Frees the prop's slot once it has risen out of the screen. */
void bouncing_prop_rise_out(uint16_t object)
{
	uint16_t z = 0;

	z = OBJECT(object)->z;
	if (z >= 0xF0u)
		OBJECT(object)->flags = 0u;
}

/* Stops the prop, unhittable, and sends it back to moving at the players. */
void bouncing_prop_stop(uint16_t object)
{
	OBJECT(object)->x_speed = 0;
	OBJECT(object)->y_speed = 0;
	OBJECT(object)->flags = 0x80u;
	OBJECT(object)->state = 2u;
}

/* Sends the hit prop off one way at random. */
void bouncing_prop_knocked(uint16_t object)
{
	uint16_t x_speed = 0;

	OBJECT(object)->x_speed = 0x200;
	if ((int8_t)random_number >= 0)
	{
		bouncing_prop_bounce_start(object);
		return;
	}
	x_speed = OBJECT(object)->x_speed;
	OBJECT(object)->x_speed = 0u - x_speed;
	bouncing_prop_bounce_start(object);
}

/* Starts the prop's bounce (step 5) with its bouncing hit box; past scroll 03A2 it leaves instead. */
void bouncing_prop_bounce_start(uint16_t object)
{
	uint16_t camera_x_now = 0;

	camera_x_now = camera_x;
	if (camera_x_now > 0x3A2u)
	{
		OBJECT(object)->state = 0xFEu;
		OBJECT(object)->action = 0u;
		OBJECT(object)->action_step = 0u;
		return;
	}
	OBJECT(object)->flags = 0x80u;
	OBJECT(object)->animation = 0x93u;
	leftover_y = bouncing_prop_bounce_start_box_ADDRESS;
	vector_set_hit_box(object);
	face_movement(object);
	OBJECT(object)->z_speed = -0x100;
	OBJECT(object)->state = 5u;
	OBJECT(object)->action = 0u;
	OBJECT(object)->action_step = 0u;
}

/* Sets the prop up with three bounces, thrown up big from the back, falling in (step FF). */
uint16_t bouncing_prop_setup(uint16_t object)
{
	uint16_t setup = 0;

	setup = bouncing_prop_object_setup_ADDRESS;
	vector_object_setup(object, setup);
	OBJECT(object)->bouncing_prop.bounces_left = 3u;
	OBJECT(object)->floor_z = 0u;
	OBJECT(object)->attributes = 0x10u;
	OBJECT(object)->flags = 0x90u;
	OBJECT(object)->y_speed = -0x80;
	OBJECT(object)->z_speed = 0x200;
	OBJECT(object)->zoom_x = 0xFFu;
	OBJECT(object)->zoom_y = 0xFFu;
	OBJECT(object)->state = 0xFFu;
	return setup;
}

/* Pulls the prop down, shrinking it to its plain size, until it lands; then it can be hit and moves at
   the players. */
void bouncing_prop_fall_in(uint16_t object)
{
	uint32_t carry = 0;
	uint16_t zoom_x = 0;
	uint16_t z_speed = 0, zoom_x_2 = 0;

	z_speed = OBJECT(object)->z_speed;
	OBJECT(object)->z_speed = z_speed - 0x10u;
	carry = vector_check_landing(object);
	if (carry)
	{
		OBJECT(object)->y_speed = 0;
		OBJECT(object)->flags = 0xC0u;
		OBJECT(object)->state = 1u;
		return;
	}
	zoom_x_2 = (((uint32_t)OBJECT(object)->zoom_x << 8u) | OBJECT(object)->zoom_y);
	zoom_x = zoom_x_2 - 0x808u;
	if (zoom_x >= 0x4040u)
	{
		OBJECT(object)->zoom_x = (uint8_t)(zoom_x >> 8u);
		OBJECT(object)->zoom_y = (uint8_t)zoom_x;
		OBJECT(object)->flags = 0x90u;
	}
}

/* Every 64 frames sets the prop moving slowly at the nearest player unless it is close; stops it at the
   floor's edge; once done (field 37) it leaves. */
uint16_t bouncing_prop_follow(uint16_t object, uint16_t player)
{
	uint32_t negative = 0;
	uint8_t cell = 0, direction = 0;
	uint16_t direction_offset = 0, floor_cell = 0, heading = 0;
	uint8_t carrier_kind = 0, done = 0, parameter = 0;
	uint16_t prop_x = 0, nearest_x = 0, difference_x = 0, signed_dx = 0, distance_x = 0, prop_y = 0, nearest_y = 0, difference_y = 0, signed_dy = 0, distance_y = 0, x_speed = 0, y_speed = 0;

	carrier_kind = OBJECT(object)->bouncing_prop.carrier_kind;
	if (carrier_kind != 0u)
		return player;
	if ((frame_count & 0x3Fu) == 0u)
	{
		player = vector_choose_nearest_player(object);
		prop_x = OBJECT(object)->x;
		nearest_x = OBJECT(player)->x;
		difference_x = prop_x - nearest_x;
		signed_dx = difference_x;
		distance_x = signed_dx >> 15 ? 0u - signed_dx : signed_dx;
		if (distance_x < 0x40u)
		{
			prop_y = OBJECT(object)->y;
			nearest_y = OBJECT(player)->y;
			difference_y = prop_y - nearest_y;
			signed_dy = difference_y;
			distance_y = signed_dy >> 15 ? 0u - signed_dy : signed_dy;
			if (distance_y < 0x40u)
			{
				OBJECT(object)->x_speed = 0;
				OBJECT(object)->y_speed = 0;
				done = OBJECT(object)->bouncing_prop.done;
				if (done != 0u)
				{
					OBJECT(object)->flags = 0x80u;
					OBJECT(object)->state = 0xFEu;
					OBJECT(object)->action = 0u;
					OBJECT(object)->action_step = 0u;
				}
				return player;
			}
		}
		parameter = OBJECT(object)->parameter;
		direction_offset = parameter;
		direction_offset = vector_direction_to_offset(object, player, direction_offset);
		direction = (uint8_t)(direction_offset >> 8);
		heading = ((uint32_t)direction << 8) | 0x10u;
		vector_set_speed_by_direction(object, heading);
	}
	x_speed = OBJECT(object)->x_speed;
	if (x_speed == 0u)
	{
		done = OBJECT(object)->bouncing_prop.done;
		if (done != 0u)
		{
			OBJECT(object)->flags = 0x80u;
			OBJECT(object)->state = 0xFEu;
			OBJECT(object)->action = 0u;
			OBJECT(object)->action_step = 0u;
		}
		return player;
	}
	y_speed = OBJECT(object)->y_speed;
	if (y_speed == 0u)
	{
		done = OBJECT(object)->bouncing_prop.done;
		if (done != 0u)
		{
			OBJECT(object)->flags = 0x80u;
			OBJECT(object)->state = 0xFEu;
			OBJECT(object)->action = 0u;
			OBJECT(object)->action_step = 0u;
		}
		return player;
	}
	vector_floor_ahead(object, &floor_cell, &negative);
	cell = (uint8_t)(floor_cell >> 8);
	if ((int8_t)cell >= 0)
	{
		done = OBJECT(object)->bouncing_prop.done;
		if (done != 0u)
		{
			OBJECT(object)->flags = 0x80u;
			OBJECT(object)->state = 0xFEu;
			OBJECT(object)->action = 0u;
			OBJECT(object)->action_step = 0u;
		}
		return player;
	}
	OBJECT(object)->x_speed = 0;
	OBJECT(object)->y_speed = 0;
	done = OBJECT(object)->bouncing_prop.done;
	if (done != 0u)
	{
		OBJECT(object)->flags = 0x80u;
		OBJECT(object)->state = 0xFEu;
		OBJECT(object)->action = 0u;
		OBJECT(object)->action_step = 0u;
	}
	return player;
}

/* The prop's bounce (step 5), by field 29. */
uint16_t bouncing_prop_bounce(uint16_t object)
{
	uint16_t steps = 0;
	uint8_t action_step = 0;

	steps = bouncing_prop_bounce_steps_ADDRESS;
	action_step = OBJECT(object)->action_step;
	switch ((int8_t)(uint8_t)((uint32_t)action_step << 1))
	{
	case 0:
		bouncing_prop_bounce_off_edge(object);
		return steps;
	case 2:
		bouncing_prop_land(object);
		return steps;
	}
	unreachable();
}

/* Moves the knocked prop; at the screen's edge it bounces back up with its hit box. */
void bouncing_prop_bounce_off_edge(uint16_t object)
{
	uint8_t action_step = 0;
	uint16_t prop_x = 0, z_speed = 0, x_speed = 0;

	prop_x = OBJECT(object)->x;
	if (prop_x >= 0x60 && prop_x <= 0x15F)
	{
		z_speed = OBJECT(object)->z_speed;
		OBJECT(object)->z_speed = z_speed + 0x18u;
		check_hits_with_enemies(object);
		return;
	}
	x_speed = OBJECT(object)->x_speed;
	OBJECT(object)->x_speed = 0u - x_speed;
	OBJECT(object)->z_speed = 0x180;
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
	OBJECT(object)->animation = 0x95u;
	OBJECT(object)->bouncing_prop.carrier_kind = 0u;
	OBJECT(object)->flags = 0x88u;
	leftover_y = bouncing_prop_bounce_off_edge_box_ADDRESS;
	vector_set_hit_box(object);
}

/* Pulls the prop down; when it lands, counts a bounce: after the third it is done, otherwise it can be
   hit again and moves at the players. */
void bouncing_prop_land(uint16_t object)
{
	uint32_t carry = 0;
	uint16_t ignored16 = 0;
	uint8_t bounces_left = 0;

	vector_apply_gravity(object, &ignored16, &carry);
	if (carry == 0u)
		return;
	OBJECT(object)->x_speed = 0;
	bounces_left = OBJECT(object)->bouncing_prop.bounces_left;
	OBJECT(object)->bouncing_prop.bounces_left = bounces_left - 1u;
	if (bounces_left != 1u)
		OBJECT(object)->flags = 0xC0u;
	else
		OBJECT(object)->bouncing_prop.done = 1u;
	OBJECT(object)->animation = 0x92u;
	OBJECT(object)->state = 2u;
}
