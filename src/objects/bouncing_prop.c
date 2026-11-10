/**
 *    Name:        objects/bouncing_prop.c
 *    Description: the kind 05 prop a stage event drops in (5280 type FB)
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    09-11-2026
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
void bouncing_prop_leave(uint16_t object, uint16_t *p_y, uint16_t *p_steps)
{
	uint16_t y = (uint16_t)*p_y;
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
			break;
		case 2:
			bouncing_prop_fly_away(object);
			break;
		case 4:
			bouncing_prop_shrink_away(object);
			break;
		case 6:
			bouncing_prop_rise_out(object);
			break;
		case -18:
			continue;
		case -16:
			bouncing_prop_fall_in(object);
			break;
		case -14:
			bouncing_prop_setup(object, &y, &steps);
			break;
		case -12:
		case -10:
			steps = bouncing_prop_follow(object, steps);
			break;
		case -8:
			bouncing_prop_stop(object);
			break;
		case -6:
			y = bouncing_prop_bounce_start(object, y);
			break;
		case -4:
			bouncing_prop_bounce(object, &y, &steps);
			break;
		case -2:
			y = bouncing_prop_knocked(object, y);
			break;
		}
		break;
	}
	*p_y = y;
	*p_steps = steps;
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
	uint16_t z = 0, t1 = 0;

	z = OBJECT(object)->z;
	if (z < 0x40u)
		return;
	t1 = camera_x;
	if (t1 > 0x3A2u)
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
uint16_t bouncing_prop_knocked(uint16_t object, uint16_t y)
{
	uint16_t x_speed = 0;

	OBJECT(object)->x_speed = 0x200;
	if ((int8_t)random_number >= 0)
		return bouncing_prop_bounce_start(object, y);
	x_speed = OBJECT(object)->x_speed;
	OBJECT(object)->x_speed = 0u - x_speed;
	return bouncing_prop_bounce_start(object, y);
}

/* Starts the prop's bounce (step 5) with its bouncing hit box; past scroll 03A2 it leaves instead. */
uint16_t bouncing_prop_bounce_start(uint16_t object, uint16_t y)
{
	uint16_t box = 0;
	uint16_t t1 = 0;

	t1 = camera_x;
	if (t1 > 0x3A2u)
	{
		OBJECT(object)->state = 0xFEu;
		OBJECT(object)->action = 0u;
		OBJECT(object)->action_step = 0u;
		return y;
	}
	OBJECT(object)->flags = 0x80u;
	OBJECT(object)->animation = 0x93u;
	box = bouncing_prop_bounce_start_box_ADDRESS;
	vector_set_hit_box(object, box);
	face_movement(object);
	OBJECT(object)->z_speed = -0x100;
	OBJECT(object)->state = 5u;
	OBJECT(object)->action = 0u;
	OBJECT(object)->action_step = 0u;
	return box;
}

/* Sets the prop up with three bounces, thrown up big from the back, falling in (step FF). */
void bouncing_prop_setup(uint16_t object, uint16_t *p_box, uint16_t *p_setup)
{
	uint16_t box = 0, setup = 0;

	setup = bouncing_prop_object_setup_ADDRESS;
	box = vector_object_setup(object, setup);
	OBJECT(object)->bouncing_prop.bounces_left = 3u;
	OBJECT(object)->floor_z = 0u;
	OBJECT(object)->attributes = 0x10u;
	OBJECT(object)->flags = 0x90u;
	OBJECT(object)->y_speed = -0x80;
	OBJECT(object)->z_speed = 0x200;
	OBJECT(object)->zoom_x = 0xFFu;
	OBJECT(object)->zoom_y = 0xFFu;
	OBJECT(object)->state = 0xFFu;
	*p_box = box;
	*p_setup = setup;
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
	uint16_t d = 0, floor_cell = 0, heading = 0;
	uint8_t carrier_kind = 0, done = 0, parameter = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, t8 = 0, t9 = 0, t10 = 0, x_speed = 0, y_speed = 0;

	carrier_kind = OBJECT(object)->bouncing_prop.carrier_kind;
	if (carrier_kind != 0u)
		return player;
	if ((frame_count & 0x3Fu) == 0u)
	{
		player = vector_choose_nearest_player(object);
		t1 = OBJECT(object)->x;
		t2 = mem_read16(player + 0xCu);
		t3 = t1 - t2;
		t4 = t3;
		t5 = t4 >> 15 ? 0u - t4 : t4;
		if (t5 < 0x40u)
		{
			t6 = OBJECT(object)->y;
			t7 = mem_read16(player + 0x11u);
			t8 = t6 - t7;
			t9 = t8;
			t10 = t9 >> 15 ? 0u - t9 : t9;
			if (t10 < 0x40u)
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
		d = parameter;
		d = vector_direction_to_offset(object, player, d);
		direction = (uint8_t)(d >> 8);
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
void bouncing_prop_bounce(uint16_t object, uint16_t *p_y, uint16_t *p_steps)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t steps = 0;
	uint8_t action_step = 0;

	steps = bouncing_prop_bounce_steps_ADDRESS;
	action_step = OBJECT(object)->action_step;
	switch ((int8_t)(uint8_t)((uint32_t)action_step << 1))
	{
	case 0:
		y = bouncing_prop_bounce_off_edge(object, y);
		break;
	case 2:
		bouncing_prop_land(object);
		break;
	}
	*p_y = y;
	*p_steps = steps;
}

/* Moves the knocked prop; at the screen's edge it bounces back up with its hit box. */
uint16_t bouncing_prop_bounce_off_edge(uint16_t object, uint16_t y)
{
	uint16_t box = 0;
	uint8_t action_step = 0;
	uint16_t t1 = 0, z_speed = 0, x_speed = 0;

	t1 = OBJECT(object)->x;
	if (t1 >= 0x60 && t1 <= 0x15F)
	{
		z_speed = OBJECT(object)->z_speed;
		OBJECT(object)->z_speed = z_speed + 0x18u;
		check_hits_with_enemies(object);
		return y;
	}
	x_speed = OBJECT(object)->x_speed;
	OBJECT(object)->x_speed = 0u - x_speed;
	OBJECT(object)->z_speed = 0x180;
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
	OBJECT(object)->animation = 0x95u;
	OBJECT(object)->bouncing_prop.carrier_kind = 0u;
	OBJECT(object)->flags = 0x88u;
	box = bouncing_prop_bounce_off_edge_box_ADDRESS;
	vector_set_hit_box(object, box);
	return box;
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
