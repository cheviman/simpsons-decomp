/**
 *    Name:        objects/scenery_bank_17.c
 *    Description: bank 17's scenery: the posing figure and the unused Homer object
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    09-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the game's 053248 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

/* Sets a figure up by its spawn's state: its kind, attributes and four poses. */
void random_pose_figure_start(uint16_t object, uint16_t *p_box, uint16_t *p_random_pose_figure)
{
	uint16_t box = 0, random_pose_figure = 0, setup = 0;
	uint8_t parameter = 0, state = 0;
	uint16_t kind = 0, poses = 0;

	setup = random_pose_figure_setup_ADDRESS;
	box = vector_object_setup(object, setup);
	OBJECT(object)->flags = 0x80u;
	parameter = OBJECT(object)->parameter;
	random_pose_figure = random_pose_figures_ADDRESS + (int8_t)(((uint32_t)parameter << 1) << 1);
	kind = (((uint32_t)RANDOM_POSE_FIGURE(random_pose_figure)->kind << 8u) | RANDOM_POSE_FIGURE(random_pose_figure)->attributes);
	OBJECT(object)->kind = kind >> 8;
	OBJECT(object)->attributes = kind;
	poses = RANDOM_POSE_FIGURE(random_pose_figure)->poses;
	OBJECT(object)->behaviour = poses;
	OBJECT(object)->timer = 1u;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
	random_pose_figure = random_pose_figure_pose(object, random_pose_figure);
	*p_box = box;
	*p_random_pose_figure = random_pose_figure;
}

/* Strikes one of its four poses at random. */
uint16_t random_pose_figure_pose(uint16_t object, uint16_t u)
{
	uint8_t timer = 0, t1 = 0;
	uint16_t behaviour = 0;

	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer == 1u)
	{
		behaviour = OBJECT(object)->behaviour;
		u = behaviour;
		t1 = (uint8_t)OBJECT(object)->x;
		OBJECT(object)->animation = mem_read8(u + ((random_number + t1) & 3u)) | 0x80u;
	}
	return u;
}

/* Unused: lets go and stays. */
void unused_homer_object_let_go(uint16_t object)
{
	OBJECT(object)->animation = 0x81u;
	OBJECT(object)->state = 0xFEu;
	unused_homer_object_idle();
}

/* Unused: does nothing. */
void unused_homer_object_idle(void)
{
}

/* Unused: sets up the object with Homer's sprites. */
void unused_homer_object_start(uint16_t object, uint16_t *p_box, uint16_t *p_setup)
{
	uint16_t box = 0, setup = 0;
	uint8_t state = 0;

	setup = unused_homer_object_setup_ADDRESS;
	box = vector_object_setup(object, setup);
	OBJECT(object)->timer = 1u;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
	*p_box = box;
	*p_setup = setup;
}

/* Unused: waits until the nearest player is close, then gets ready. */
uint16_t unused_homer_object_wait_near(uint16_t object)
{
	uint16_t target = 0;
	uint8_t timer = 0, state = 0;
	uint16_t target_2 = 0, target_dy = 0, target_dx = 0, t1 = 0;

	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer == 1u)
	{
		OBJECT(object)->timer = 0x10u;
		vector_choose_nearest_player(object);
	}
	target_2 = OBJECT(object)->target;
	target = target_2;
	vector_measure_target(object, target);
	target_dy = OBJECT(object)->target_dy;
	target_dx = OBJECT(object)->target_dx;
	t1 = target_dy + target_dx;
	if (t1 < 0x40u)
	{
		OBJECT(object)->flags = 0xC0u;
		OBJECT(object)->animation = 0xAFu;
		state = OBJECT(object)->state;
		OBJECT(object)->state = state + 1u;
	}
	return target;
}

/* Unused: when a player hits it, holds that player. */
uint16_t unused_homer_object_wait_hit(uint16_t object, uint16_t hitter)
{
	uint8_t animation_flags = 0, state = 0;
	uint16_t hit_by = 0;

	if ((OBJECT(object)->flags & 0x20u) == 0u)
	{
		animation_flags = OBJECT(object)->animation_flags;
		if (animation_flags & 1u)
		{
			OBJECT(object)->animation = 0xAFu;
			state = OBJECT(object)->state;
			OBJECT(object)->state = state + 1u;
		}
		return hitter;
	}
	hit_by = OBJECT(object)->hit_by;
	hitter = hit_by;
	if (hitter >= OBJECT_ADDRESS(14))
	{
		animation_flags = OBJECT(object)->animation_flags;
		if (animation_flags & 1u)
		{
			OBJECT(object)->animation = 0xAFu;
			state = OBJECT(object)->state;
			OBJECT(object)->state = state + 1u;
		}
		return hitter;
	}
	OBJECT(object)->target = hitter;
	OBJECT(object)->animation = 0xB8u;
	OBJECT(hitter)->blocked = 0x10u;
	OBJECT(hitter)->unk_3D = 6u;
	OBJECT(object)->state = 5u;
	return hitter;
}

/* Unused: holds the player until it breaks free or is beaten. */
uint16_t unused_homer_object_hold(uint16_t object)
{
	uint16_t held = 0;
	uint8_t vitality = 0, hold_presses = 0;
	uint16_t target = 0;

	target = OBJECT(object)->target;
	held = target;
	vitality = OBJECT(held)->vitality;
	if (vitality != 0u)
	{
		hold_presses = OBJECT(held)->player.hold_presses;
		if (hold_presses == 0u)
		{
			OBJECT(object)->animation = 0xAFu;
			OBJECT(object)->state = 3u;
		}
		return held;
	}
	OBJECT(object)->animation = 0xAFu;
	OBJECT(object)->state = 3u;
	return held;
}

/* Unused: when its animation ends, stands for 64 frames. */
void unused_homer_object_release(uint16_t object)
{
	uint8_t animation_flags = 0, state = 0;

	animation_flags = OBJECT(object)->animation_flags;
	if (animation_flags & 1u)
	{
		OBJECT(object)->animation = 0x80u;
		OBJECT(object)->timer = 0x40u;
		state = OBJECT(object)->state;
		OBJECT(object)->state = state + 1u;
	}
}

/* Unused: after its rest, waits for a player again. */
void unused_homer_object_rest(uint16_t object)
{
	uint8_t timer = 0;

	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer == 1u)
		OBJECT(object)->state = 1u;
}
