/**
 *    Name:        enemies/hurt.c
 *    Description: the hit reaction of the enemies with their own hit animations, and the plain goon they turn into
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    09-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the game's 053248 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

/* Turns the enemy into a plain goon (kind 80, the goon's behaviour) lying on the ground, which then gets
   up and fights on. */
void enemy_hurt_become_goon(uint16_t object, uint16_t *p_y, uint16_t *p_behaviour)
{
	uint16_t behaviour = 0, y = 0;
	uint8_t attributes = 0;

	attributes = OBJECT(object)->attributes;
	OBJECT(object)->enemy_hurt.kept_attributes = attributes;
	enemy_become_goon(object, &y, &behaviour);
	OBJECT(object)->animation = 0x8Du;
	OBJECT(object)->timer = 0x18u;
	OBJECT(object)->state = 4u;
	OBJECT(object)->action = 4u;
	OBJECT(object)->action_step = 0u;
	*p_y = y;
	*p_behaviour = behaviour;
}

/* Starts the reaction to a hit: the hit's sound and the hit animation of its action; a flinch for
   actions 0 and 1, else knocked up and away from the hitter; with no vitality left, the defeat. */
uint16_t enemy_hurt_start(uint16_t object, uint16_t u)
{
	uint32_t zero = 0, carry = 0;
	uint8_t reaction = 0;
	uint16_t animations = 0, command = 0, hitter = 0;
	uint8_t vitality = 0, action = 0, action_step = 0;
	uint16_t hit_by = 0, x_speed = 0, t1 = 0, t2 = 0, x_speed_2 = 0;

	command = 0x6300u;
	carry = queue_sound(command);
	vitality = OBJECT(object)->vitality;
	if (vitality == 0u)
	{
		OBJECT(object)->action_step = 2u;
		enemy_hurt_fall_defeated(object);
		return u;
	}
	animations = hit_animations_ADDRESS;
	action = OBJECT(object)->action;
	reaction = action;
	if (reaction < 2u)
	{
		action_step = OBJECT(object)->action_step;
		OBJECT(object)->action_step = action_step + 1u;
		OBJECT(object)->animation = HIT_ANIMATION(animations + (int8_t)reaction) | 0x80u;
		OBJECT(object)->x_speed = 0;
		OBJECT(object)->y_speed = 0;
		return animations;
	}
	OBJECT(object)->animation = HIT_ANIMATION(animations + (int8_t)reaction) | 0x80u;
	OBJECT(object)->y_speed = 0;
	OBJECT(object)->z_speed = 0x400;
	OBJECT(object)->x_speed = -0x200;
	hit_by = OBJECT(object)->hit_by;
	hitter = hit_by;
	x_speed = OBJECT(hitter)->x_speed;
	zero = x_speed == 0u;
	if ((int16_t)x_speed < 0)
	{
		OBJECT(object)->action_step = 5u;
		return hitter;
	}
	if (zero)
	{
		t1 = OBJECT(hitter)->x;
		t2 = OBJECT(object)->x;
		if (t1 < t2)
		{
			x_speed_2 = OBJECT(object)->x_speed;
			OBJECT(object)->x_speed = 0u - x_speed_2;
		}
		OBJECT(object)->action_step = 5u;
		return hitter;
	}
	x_speed_2 = OBJECT(object)->x_speed;
	OBJECT(object)->x_speed = 0u - x_speed_2;
	OBJECT(object)->action_step = 5u;
	return hitter;
}

/* Once the hit animation has run, gives the enemy its hit box back and sends it back to its state 2. */
uint16_t enemy_hurt_recover(uint16_t object, uint16_t y)
{
	uint16_t box = 0;
	uint8_t animation_flags = 0;
	uint16_t hit_box = 0;

	animation_flags = OBJECT(object)->animation_flags;
	if ((animation_flags & 1u) == 0u)
		return y;
	OBJECT(object)->flags = 0xC0u;
	hit_box = OBJECT(object)->hit_box;
	box = hit_box;
	set_hit_box(object, box);
	OBJECT(object)->state = 2u;
	OBJECT(object)->timer = 0u;
	return box;
}

/* Lets the defeated enemy fall; once it lands it lies down. */
void enemy_hurt_fall_defeated(uint16_t object)
{
	uint32_t carry = 0;
	uint16_t ignored16 = 0;
	uint8_t action_step = 0;

	apply_gravity(object, &ignored16, &carry);
	if (carry)
	{
		OBJECT(object)->x_speed = 0;
		OBJECT(object)->y_speed = 0;
		OBJECT(object)->animation = 0x88u;
		action_step = OBJECT(object)->action_step;
		OBJECT(object)->action_step = action_step + 1u;
	}
}

/* Keeps the defeated enemy lying until its animation is over, with its sound on the marked frame; then
   it gets up as a plain goon, or (field vanishes) it starts to blink out. */
void enemy_hurt_lie_defeated(uint16_t object, uint16_t *p_y, uint16_t *p_u)
{
	uint32_t carry = 0;
	uint8_t a = 0, d = 0;
	uint16_t command = 0, u_2 = 0, y_2 = 0;
	uint8_t animation_flags = 0, vanishes = 0, action_step = 0, animation_flags_2 = 0;
	uint16_t frame_sound = 0;

	animation_flags = OBJECT(object)->animation_flags;
	if (animation_flags & 1u)
	{
		vanishes = OBJECT(object)->enemy_hurt.vanishes;
		if (vanishes == 0u)
		{
			OBJECT(object)->x_speed = 0;
			*p_y = y_2;
			*p_u = u_2;
			enemy_hurt_become_goon(object, p_y, p_u);
			return;
		}
		OBJECT(object)->timer = 0x10u;
		action_step = OBJECT(object)->action_step;
		OBJECT(object)->action_step = action_step + 1u;
	}
	animation_flags_2 = OBJECT(object)->animation_flags;
	if ((animation_flags_2 & 2u) == 0u)
		return;
	frame_sound = OBJECT(object)->enemy_hurt.frame_sound;
	d = (uint8_t)frame_sound;
	a = (uint8_t)(frame_sound >> 8);
	if (frame_sound == 0u)
		return;
	command = (d & 0xFFu) | ((uint32_t)a << 8);
	carry = queue_sound(command);
}

/* Blinks the defeated enemy out; at the end it is gone and its points scored. */
uint16_t enemy_hurt_vanish(uint16_t object, uint16_t target)
{
	uint8_t timer = 0;

	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer != 1u)
	{
		OBJECT(object)->flags = (OBJECT(object)->flags ^ 0x80u) | 4u;
		return target;
	}
	OBJECT(object)->flags = 0u;
	return enemy_mark_defeated(object, target);
}

/* Lets the knocked enemy fall; once it lands it stays down for 10 frames. */
void enemy_hurt_fall(uint16_t object)
{
	uint32_t carry = 0;
	uint16_t ignored16 = 0;
	uint8_t action_step = 0;

	apply_gravity(object, &ignored16, &carry);
	if (carry)
	{
		OBJECT(object)->x_speed = 0;
		OBJECT(object)->timer = 0x10u;
		action_step = OBJECT(object)->action_step;
		OBJECT(object)->action_step = action_step + 1u;
	}
}

/* After its time down, the knocked enemy gets up (animation 8F) with its hit box back. */
uint16_t enemy_hurt_get_up(uint16_t object, uint16_t box)
{
	uint8_t timer = 0;
	uint16_t hit_box = 0;

	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer != 1u)
		return box;
	hit_box = OBJECT(object)->hit_box;
	box = hit_box;
	set_hit_box(object, box);
	OBJECT(object)->flags = 0xC0u;
	OBJECT(object)->animation = 0x8Fu;
	OBJECT(object)->action_step = 1u;
	return box;
}
