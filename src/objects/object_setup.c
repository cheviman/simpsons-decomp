/**
 *    Name:        objects/object_setup.c
 *    Description: an object's setup and hit box, gravity and landing, the screen's edges
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    11-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the game's 053248 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

/* Starts the object from a setup record: on and in the hit checks, its kind and animation (started
   again), its hit box, its life and its points, and its sprites' priority from the floor map where it
   stands. */
void start_object_from_setup(uint16_t object, uint16_t setup)
{
	uint32_t negative = 0;
	uint8_t floor_value = 0;
	uint16_t floor_cell = 0, hit_box = 0;
	uint8_t life = 0, points = 0, attributes = 0;
	uint16_t kind_and_animation = 0, box = 0;
	uint32_t kind_halfword = 0;

	OBJECT(object)->flags = 0xC0u;
	kind_and_animation = OBJECT_SETUP(setup)->kind_and_animation;
	kind_halfword = ((uint32_t)(kind_and_animation >> 8) << 8) | (uint8_t)(kind_and_animation | 0x80u);
	OBJECT(object)->kind = (uint8_t)(kind_halfword >> 8u);
	OBJECT(object)->animation = (uint8_t)kind_halfword;
	box = OBJECT_SETUP(setup)->box;
	hit_box = box;
	OBJECT(object)->hit_box = hit_box;
	set_hit_box(object, hit_box);
	life = OBJECT_SETUP(setup)->life;
	OBJECT(object)->vitality = life;
	points = OBJECT_SETUP(setup)->points;
	OBJECT(object)->points = points & 0x7Fu;
	attributes = OBJECT(object)->attributes;
	setup_attributes = attributes & 0xCFu;
	floor_cell = 0u;
	floor_at_offset(object, &floor_cell, &negative);
	floor_value = (uint8_t)(floor_cell >> 8);
	OBJECT(object)->next_floor_cell = floor_value;
	OBJECT(object)->attributes = (floor_value & 0x30u) | setup_attributes;
	leftover_y = hit_box;
}

/* Pulls the object's height speed down by gravity and, once it falls, caps its fall and lands it on its
   floor (carry set when it lands). */
void apply_gravity(uint16_t object, uint16_t *p_z_speed, uint32_t *p_carry)
{
	uint32_t carry = *p_carry;
	uint16_t z_speed = 0;
	uint16_t z_speed_2 = 0;

	z_speed_2 = OBJECT(object)->z_speed;
	z_speed = z_speed_2 - 0x60u;
	OBJECT(object)->z_speed = z_speed;
	if ((int16_t)z_speed >= 0)
	{
		carry = 0u;
		z_speed &= 0xFFu;
	}
	else
		cap_fall_and_land(object, &z_speed, &carry);
	*p_z_speed = z_speed;
	*p_carry = carry;
}

/* Caps the object's fall at 8 pixels a frame and, once it is within 7 pixels of its floor, lands it
   there (carry set): its height speed stopped, no longer in the air. */
void cap_fall_and_land(uint16_t object, uint16_t *p_z_speed, uint32_t *p_carry)
{
	uint16_t z_speed = (uint16_t)*p_z_speed;
	uint32_t carry = *p_carry;
	uint8_t animation_flags = 0, floor_z_low = 0;
	uint16_t height = 0;
	uint8_t animation_flags_2 = 0;
	uint16_t floor_z = 0, landing_z = 0, z = 0, floor_z_2 = 0;

	if (z_speed >> 8 < 0xF8u)
		OBJECT(object)->z_speed = (OBJECT(object)->z_speed & 0xFFu) | 0xF800u;
	floor_z = OBJECT(object)->floor_z;
	landing_z = floor_z + 7u;
	land_at_height = landing_z;
	z = OBJECT(object)->z;
	height = z;
	if (land_at_height < (uint16_t)(((uint32_t)(z >> 8) << 8) | (height & 0xFFu)))
	{
		carry = 0u;
		height &= 0xFFu;
	}
	else
	{
		OBJECT(object)->z_speed = 0;
		floor_z_2 = OBJECT(object)->floor_z;
		floor_z_low = (uint8_t)floor_z_2;
		OBJECT(object)->z = ((uint32_t)(floor_z_2 >> 8) << 8) | (floor_z_low & 0xFFu);
		OBJECT(object)->flags &= ~8u;
		animation_flags_2 = OBJECT(object)->animation_flags;
		animation_flags = animation_flags_2 | 0x80u;
		OBJECT(object)->animation_flags = animation_flags;
		carry = 1u;
		height = (floor_z_low & 0xFFu) | ((uint32_t)(uint8_t)~animation_flags << 8);
	}
	*p_z_speed = height;
	*p_carry = carry;
}

/* While the object falls (its height speed below 0), caps its fall and lands it on its floor (carry set
   when it lands). */
uint32_t land_if_falling(uint16_t object)
{
	uint32_t carry = 0;
	uint8_t z_speed_high = 0;
	uint16_t z_speed = 0;
	uint8_t z_speed_2 = 0;

	z_speed_2 = (uint8_t)(OBJECT(object)->z_speed >> 8u);
	z_speed_high = z_speed_2;
	if ((int8_t)z_speed_2 >= 0)
	{
		carry = 0u;
		return carry;
	}
	z_speed = (uint32_t)z_speed_high << 8;
	cap_fall_and_land(object, &z_speed, &carry);
	return carry;
}

/* Copies a hit box record into the object: its power and kind of hit, its half sizes and its offsets. */
void set_hit_box(uint16_t object, uint16_t box)
{
	uint16_t width_depth = 0, height_dx = 0, dy_dz = 0;
	uint32_t damage_halfword = 0;

	damage_halfword = HIT_BOX(box)->damage_attack;
	OBJECT(object)->damage = (uint8_t)(damage_halfword >> 8u);
	OBJECT(object)->attack = (uint8_t)damage_halfword;
	width_depth = HIT_BOX(box)->width_depth;
	OBJECT(object)->box_width = (uint8_t)(width_depth >> 8u);
	OBJECT(object)->box_depth = (uint8_t)width_depth;
	height_dx = HIT_BOX(box)->height_dx;
	OBJECT(object)->box_height = (uint8_t)(height_dx >> 8u);
	OBJECT(object)->box_dx = (uint8_t)height_dx;
	dy_dz = HIT_BOX(box)->dy_dz;
	OBJECT(object)->box_dy = (uint8_t)(dy_dz >> 8u);
	OBJECT(object)->box_dz = (uint8_t)dy_dz;
}

/* Stops the object's x speed when it is more than 48 pixels off either side of the screen (objects' x
   runs 40-17F across it). */
void stop_beyond_screen_edge(uint16_t object)
{
	uint16_t screen_x = 0;

	if (OBJECT(object)->flags != 0u)
	{
		screen_x = OBJECT(object)->x;
		if (screen_x < 0x10 || screen_x > 0x1AF)
			OBJECT(object)->x_speed = 0;
	}
}

/* Removes the object once it is more than 64 pixels off either side of the screen; an enemy also lets go
   of its target, and one with no life left is marked defeated. */
uint16_t enemy_remove_off_screen(uint16_t object, uint16_t target)
{
	uint8_t vitality = 0;
	uint16_t screen_x = 0;

	if (OBJECT(object)->flags == 0u)
		return target;
	screen_x = OBJECT(object)->x;
	if (screen_x < 0x1C0u)
		return target;
	OBJECT(object)->flags = 0u;
	if (object >= OBJECT_ADDRESS(22))
		return target;
	vitality = OBJECT(object)->vitality;
	if (vitality == 0u)
		return enemy_mark_defeated(object, target);
	return enemy_release_target(object, target);
}

/* Whether the enemy is on the screen, 16 pixels in from its edges (carry set). */
uint32_t enemy_on_screen(uint16_t object)
{
	uint32_t carry = 0;
	uint16_t screen_x = 0;

	screen_x = OBJECT(object)->x;
	carry = screen_x >= 0x50 && screen_x <= 0x16F;
	return carry;
}
