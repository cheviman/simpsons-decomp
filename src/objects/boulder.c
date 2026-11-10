/**
 *    Name:        objects/boulder.c
 *    Description: stage 5's gorge: the falling boulders and the rocks
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    09-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the game's 053248 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

/* Sets a boulder up, hidden: whether it bounces away, its floor height and its wait, by its spawn's
   state. */
void boulder_start(uint16_t object, uint16_t *p_box, uint16_t *p_boulder_drop)
{
	uint32_t negative = 0;
	uint8_t cell = 0, drop_number = 0;
	uint16_t boulder_drop = 0, box = 0, floor_cell = 0, setup = 0;
	uint8_t parameter = 0, wait = 0, state = 0;
	uint16_t bounces = 0;

	setup = boulder_setup_ADDRESS;
	box = vector_object_setup(object, setup);
	OBJECT(object)->flags = 4u;
	OBJECT(object)->shadow_player = 0x40u;
	parameter = OBJECT(object)->parameter;
	drop_number = parameter;
	OBJECT(object)->boulder.wait_count = drop_number;
	boulder_drop = boulder_drops_ADDRESS + (int8_t)(((uint32_t)drop_number << 1) << 1);
	bounces = (((uint32_t)BOULDER_DROP(boulder_drop)->bounces << 8u) | BOULDER_DROP(boulder_drop)->floor);
	OBJECT(object)->parameter = bounces >> 8;
	OBJECT(object)->floor_z = (OBJECT(object)->floor_z & 0xFF00u) | (bounces & 0xFFu);
	wait = BOULDER_DROP(boulder_drop)->wait;
	OBJECT(object)->timer = wait;
	OBJECT(object)->zoom_x = 0x40u;
	OBJECT(object)->zoom_y = 0x40u;
	floor_cell = 0u;
	vector_floor_at_offset(object, &floor_cell, &negative);
	cell = (uint8_t)(floor_cell >> 8);
	if ((int8_t)cell >= 0)
		OBJECT(object)->floor_z = (OBJECT(object)->floor_z & 0xFF00u) | ((((cell & 0xFu) << 1) << 1) << 1 & 0xFFu);
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
	*p_box = box;
	*p_boulder_drop = boulder_drop;
}

/* Waits, showing the boulder 16 frames before it falls; a boulder with state bit 7 falls in front. */
void boulder_wait(uint16_t object)
{
	uint8_t timer = 0, wait_count = 0, timer_2 = 0, wait_count_2 = 0, attributes = 0, state = 0, attributes_2 = 0;

	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer != 1u)
	{
		wait_count = OBJECT(object)->boulder.wait_count;
		if ((int8_t)wait_count >= 0)
		{
			timer_2 = OBJECT(object)->timer;
			if (timer_2 == 0x10u)
			{
				OBJECT(object)->flags = 0x88u;
				OBJECT(object)->animation_flags = 0x80u;
			}
		}
		return;
	}
	wait_count_2 = OBJECT(object)->boulder.wait_count;
	if ((int8_t)wait_count_2 >= 0)
	{
		OBJECT(object)->timer = 0x60u;
		attributes = OBJECT(object)->attributes;
		OBJECT(object)->attributes = (attributes & 0xCFu) | 0x10u;
		state = OBJECT(object)->state;
		OBJECT(object)->state = state + 1u;
		return;
	}
	OBJECT(object)->timer = 0x60u;
	attributes_2 = OBJECT(object)->attributes;
	OBJECT(object)->attributes = (attributes_2 & 0xCFu) | 0x20u;
	OBJECT(object)->flags = 0x80u;
	OBJECT(object)->state = 4u;
}

/* Falls; on landing (sound 6500) bounces, far into the distance or a little. */
void boulder_fall(uint16_t object)
{
	uint32_t carry = 0;
	uint16_t command = 0;
	uint8_t state = 0, parameter = 0;
	uint16_t z_speed = 0;

	z_speed = OBJECT(object)->z_speed;
	OBJECT(object)->z_speed = z_speed - 0x30u;
	carry = vector_check_landing(object);
	if (carry == 0u)
	{
		boulder_hurt(object);
		return;
	}
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
	command = 0x6500u;
	carry = vector_queue_sound(command);
	parameter = OBJECT(object)->parameter;
	if (parameter == 0u)
	{
		OBJECT(object)->flags = 0xC0u;
		OBJECT(object)->y_speed = -0x80;
		OBJECT(object)->z_speed = 0x200;
		boulder_hurt(object);
		return;
	}
	OBJECT(object)->y_speed = -0x300;
	OBJECT(object)->z_speed = 0x400;
	OBJECT(object)->flags = 0xD8u;
	boulder_hurt(object);
}

/* Hurts the players and the enemies it touches on alternate frames. */
void boulder_hurt(uint16_t object)
{
	if (((uint8_t)frame_count & 1u) == 0u)
	{
		OBJECT(object)->flags |= 0x40u;
		OBJECT(object)->attack = 0xAu;
		return;
	}
	OBJECT(object)->flags &= 0xBFu;
	OBJECT(object)->attack = 0x14u;
	check_hits_with_enemies(object);
}

/* Bounces along (shrinking into the distance for one that bounces away) until it falls off the floor. */
void boulder_bounce(uint16_t object)
{
	uint32_t negative = 0, carry = 0;
	uint8_t cell = 0, new_zoom_x = 0, new_zoom_y = 0, z_speed_high = 0;
	uint16_t command = 0, floor_cell = 0;
	uint8_t parameter = 0, timer = 0;
	uint16_t zoom_x = 0, t1 = 0, t2 = 0, z_speed = 0, t3 = 0, t4 = 0, z_speed_2 = 0, t5 = 0;
	uint32_t zoom_x_halfword = 0;

	OBJECT(object)->flags = 0u;
	parameter = OBJECT(object)->parameter;
	if (parameter != 0u)
	{
		OBJECT(object)->flags = 0x10u;
		zoom_x = (((uint32_t)OBJECT(object)->zoom_x << 8u) | OBJECT(object)->zoom_y);
		t1 = zoom_x - 0x101u;
		new_zoom_y = (uint8_t)t1;
		new_zoom_x = (uint8_t)(t1 >> 8);
		if ((uint16_t)(((uint32_t)new_zoom_x << 8) | (new_zoom_y & 0xFFu)) >= 0x2020u)
		{
			zoom_x_halfword = ((uint32_t)new_zoom_x << 8) | (new_zoom_y & 0xFFu);
			OBJECT(object)->zoom_x = (uint8_t)(zoom_x_halfword >> 8u);
			OBJECT(object)->zoom_y = (uint8_t)zoom_x_halfword;
		}
	}
	floor_cell = 0u;
	vector_floor_at_offset(object, &floor_cell, &negative);
	cell = (uint8_t)(floor_cell >> 8);
	if ((int8_t)cell < 0)
	{
		t2 = OBJECT(object)->y;
		if (t2 < 0x40u)
			OBJECT(object)->y_speed = 0;
		OBJECT(object)->floor_z &= 0xFF00u;
		OBJECT(object)->flags |= 0x80u;
		timer = OBJECT(object)->timer;
		OBJECT(object)->timer = timer - 1u;
		if (timer != 1u)
		{
			z_speed = OBJECT(object)->z_speed;
			t3 = z_speed - 0x20u;
			z_speed_high = (uint8_t)(t3 >> 8);
			t4 = ((uint32_t)z_speed_high << 8) | (t3 & 0xFFu);
			OBJECT(object)->z_speed = t4;
			if ((int16_t)t4 >= 0 || z_speed_high >= 0xFCu)
				return;
			OBJECT(object)->z_speed = (OBJECT(object)->z_speed & 0xFFu) | 0xFC00u;
			return;
		}
		command = 0x6500u;
		carry = vector_queue_sound(command);
		OBJECT(object)->flags = 0u;
		return;
	}
	OBJECT(object)->floor_z = (OBJECT(object)->floor_z & 0xFF00u) | ((((cell & 0xFu) << 1) << 1) << 1 & 0xFFu);
	OBJECT(object)->flags |= 0xC8u;
	z_speed_2 = OBJECT(object)->z_speed;
	t5 = z_speed_2 - 0x20u;
	OBJECT(object)->z_speed = t5;
	carry = vector_check_landing(object);
	if (carry == 0u)
	{
		boulder_hurt(object);
		return;
	}
	command = 0x6500u;
	carry = vector_queue_sound(command);
	OBJECT(object)->y_speed = -0x100;
	OBJECT(object)->z_speed = 0x200;
	boulder_hurt(object);
}

/* Falls past the floor growing bigger, as if towards the screen, and goes away with sound 6500. */
void boulder_fall_in_front(uint16_t object)
{
	uint32_t carry = 0;
	uint16_t command = 0, height = 0, z_speed = 0, zoom_x = 0;
	uint8_t timer = 0, timer_2 = 0;
	uint16_t z = 0, zoom_x_2 = 0, z_speed_2 = 0;

	z = OBJECT(object)->z;
	height = z;
	if ((int16_t)z < 0 && height < 0xFF80u)
	{
		command = 0x6500u;
		carry = vector_queue_sound(command);
		OBJECT(object)->flags = 0u;
		return;
	}
	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	timer_2 = OBJECT(object)->timer;
	if ((uint16_t)((uint32_t)timer_2 << 8) >> 8 < 0x20u)
	{
		OBJECT(object)->flags = 0x90u;
		zoom_x_2 = (((uint32_t)OBJECT(object)->zoom_x << 8u) | OBJECT(object)->zoom_y);
		zoom_x = zoom_x_2 + 0x202u;
		if (zoom_x < 0x8080u)
		{
			OBJECT(object)->zoom_x = (uint8_t)(zoom_x >> 8u);
			OBJECT(object)->zoom_y = (uint8_t)zoom_x;
		}
	}
	z_speed_2 = OBJECT(object)->z_speed;
	z_speed = z_speed_2 - 0x20u;
	OBJECT(object)->z_speed = z_speed;
	if ((int16_t)z_speed >= 0 || z_speed >> 8 >= 0xFCu)
		return;
	OBJECT(object)->z_speed = (OBJECT(object)->z_speed & 0xFFu) | 0xFC00u;
}

/* Sets a rock up; the first also sets the four players' field 44 to 97. */
void gorge_rock_start(uint16_t object, uint16_t *p_box, uint16_t *p_setup)
{
	uint16_t box = 0, setup = 0;
	uint8_t parameter = 0, attributes = 0, state = 0;

	setup = gorge_rock_setup_ADDRESS;
	box = vector_object_setup(object, setup);
	parameter = OBJECT(object)->parameter;
	if (parameter == 0u)
	{
		OBJECT(OBJECT_ADDRESS(0))->unk_44 = 0x97u;
		OBJECT(OBJECT_ADDRESS(2))->unk_44 = 0x97u;
		OBJECT(OBJECT_ADDRESS(4))->unk_44 = 0x97u;
		OBJECT(OBJECT_ADDRESS(6))->unk_44 = 0x97u;
	}
	attributes = OBJECT(object)->attributes;
	OBJECT(object)->attributes = (attributes & 0xCFu) | 0x10u;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
	*p_box = box;
	*p_setup = setup;
}

/* Waits until something hits the rock, then starts its breaking animation. */
void gorge_rock_wait_hit(uint16_t object)
{
	uint8_t state = 0;

	if ((OBJECT(object)->flags & 0x20u) != 0u)
	{
		OBJECT(object)->flags = 0x80u;
		OBJECT(object)->animation = 0x81u;
		OBJECT(object)->timer = 0x40u;
		state = OBJECT(object)->state;
		OBJECT(object)->state = state + 1u;
	}
}

/* Takes the rock away when its breaking animation ends. */
void gorge_rock_break_end(uint16_t object)
{
	uint8_t animation_flags = 0;

	animation_flags = OBJECT(object)->animation_flags;
	if (animation_flags & 1u)
		OBJECT(object)->flags = 0u;
}
