/**
 *    Name:        objects/stage_4_figures.c
 *    Description: the figures of stages 4 and 5: kinds 87, 9E, 8E (5280 types 1D, 22, 20), 8C, 8A (4F80 22, 21)
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    11-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the game's 053248 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

/* Sets the kind 87 figure up, shown. */
uint16_t walking_kind_87_setup(uint16_t object)
{
	uint16_t setup = 0;
	uint8_t attributes = 0, state = 0;

	setup = walking_kind_87_object_setup_ADDRESS;
	vector_object_setup(object, setup);
	OBJECT(object)->flags = 0x80u;
	attributes = OBJECT(object)->attributes;
	OBJECT(object)->attributes = (attributes & 0xCFu) | 0xA9u;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
	return setup;
}

/* Waits for the scroll to bring the figure on, then waits 32 frames more. */
void walking_kind_87_wait(uint16_t object)
{
	uint8_t state = 0;
	uint16_t screen_x = 0;

	screen_x = OBJECT(object)->x;
	if (screen_x < 0x120u)
	{
		OBJECT(object)->timer = 0x20u;
		state = OBJECT(object)->state;
		OBJECT(object)->state = state + 1u;
	}
}

/* Counts down, then moves the figure toward the front for 16 frames. */
void walking_kind_87_step_out(uint16_t object)
{
	uint8_t timer = 0, state = 0;

	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer == 1u)
	{
		OBJECT(object)->y_speed = -0x100;
		OBJECT(object)->timer = 0x10u;
		state = OBJECT(object)->state;
		OBJECT(object)->state = state + 1u;
	}
}

/* Counts down, then stops the figure and plays animation 81. */
void walking_kind_87_stop(uint16_t object)
{
	uint8_t timer = 0, attributes = 0, state = 0;

	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer == 1u)
	{
		attributes = OBJECT(object)->attributes;
		OBJECT(object)->attributes = (attributes & 0xCFu) | 0x10u;
		OBJECT(object)->y_speed = 0;
		OBJECT(object)->animation = 0x81u;
		state = OBJECT(object)->state;
		OBJECT(object)->state = state + 1u;
	}
}

/* When that animation ends, walks the figure right and toward the front for 64 frames. */
void walking_kind_87_walk_off(uint16_t object)
{
	uint8_t animation_flags = 0, state = 0;

	animation_flags = OBJECT(object)->animation_flags;
	if (animation_flags & 1u)
	{
		OBJECT(object)->x_speed = 0x100;
		OBJECT(object)->y_speed = -0x100;
		OBJECT(object)->timer = 0x40u;
		OBJECT(object)->animation = 0x80u;
		state = OBJECT(object)->state;
		OBJECT(object)->state = state + 1u;
	}
}

/* Counts down, then sends the figure right at a run. */
void walking_kind_87_run_off(uint16_t object)
{
	uint8_t timer = 0, state = 0;

	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer != 1u)
	{
		walking_kind_87_running();
		return;
	}
	OBJECT(object)->x_speed = 0x200;
	OBJECT(object)->y_speed = 0;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
	walking_kind_87_running();
}

/* The figure running off: nothing to do until it leaves the screen. */
void walking_kind_87_running(void)
{
}

/* Sets the kind 9E figure up a little above the ground, walking left for 72 frames. */
uint16_t kind_9e_setup(uint16_t object)
{
	uint16_t setup = 0;
	uint8_t attributes = 0, state = 0;

	setup = kind_9e_object_setup_ADDRESS;
	vector_object_setup(object, setup);
	OBJECT(object)->flags = 0x80u;
	OBJECT(object)->z = 0x10u;
	attributes = OBJECT(object)->attributes;
	OBJECT(object)->attributes = (attributes & 0xCFu) | 0x10u;
	OBJECT(object)->x_speed = -0x100;
	OBJECT(object)->timer = 0x48u;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
	face_movement(object);
	return setup;
}

/* Counts the walk down, then stops the figure, hides its parent (field 40) and plays animation 82. */
uint16_t kind_9e_stop(uint16_t object, uint16_t parent)
{
	uint8_t timer = 0, state = 0;
	uint16_t parent_2 = 0;

	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer == 1u)
	{
		OBJECT(object)->x_speed = 0;
		OBJECT(object)->kind_9e.stopped = 1u;
		parent_2 = OBJECT(object)->parent;
		parent = parent_2;
		OBJECT(parent)->flags = 4u;
		OBJECT(parent)->animation_flags = 0x80u;
		OBJECT(object)->animation = 0x82u;
		state = OBJECT(object)->state;
		OBJECT(object)->state = state + 1u;
	}
	return parent;
}

/* When that animation ends, plays animation 83. */
void kind_9e_wait_pose(uint16_t object)
{
	uint8_t animation_flags = 0, state = 0;

	animation_flags = OBJECT(object)->animation_flags;
	if (animation_flags & 1u)
	{
		OBJECT(object)->animation = 0x83u;
		state = OBJECT(object)->state;
		OBJECT(object)->state = state + 1u;
	}
}

/* Waits for the scroll to reach 0238, then plays animation 84. */
void kind_9e_wait_for_scroll(uint16_t object)
{
	uint8_t state = 0;
	uint16_t camera_position = 0;

	camera_position = camera_x;
	if (camera_position >= 0x238u)
	{
		OBJECT(object)->animation = 0x84u;
		state = OBJECT(object)->state;
		OBJECT(object)->state = state + 1u;
	}
}

/* When that animation ends, shows its parent again and walks the figure right. */
uint16_t kind_9e_show_parent(uint16_t object, uint16_t states)
{
	uint16_t parent = 0;
	uint8_t animation_flags = 0, state = 0;
	uint16_t parent_2 = 0;

	animation_flags = OBJECT(object)->animation_flags;
	if ((animation_flags & 1u) == 0u)
		return states;
	parent_2 = OBJECT(object)->parent;
	parent = parent_2;
	OBJECT(parent)->flags = 0x80u;
	OBJECT(parent)->animation_flags = 0x80u;
	OBJECT(object)->animation = 0x81u;
	OBJECT(object)->x_speed = 0x100;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
	face_movement(object);
	return parent;
}

/* Walks the figure right up to x 0100 and stops it; once the scroll reaches 0340, it stands and waits to
   leave. */
void kind_9e_walk_right(uint16_t object)
{
	uint8_t state = 0;
	uint16_t screen_x = 0, camera_position = 0;

	screen_x = OBJECT(object)->x;
	if (screen_x >= 0x100u)
	{
		OBJECT(object)->x_speed = 0;
		OBJECT(object)->animation = 0x80u;
		state = OBJECT(object)->state;
		OBJECT(object)->state = state + 1u;
	}
	camera_position = camera_x;
	if (camera_position >= 0x340u)
	{
		OBJECT(object)->x_speed = 0;
		OBJECT(object)->animation = 0x80u;
		OBJECT(object)->timer = 0x80u;
		OBJECT(object)->state = 8u;
	}
}

/* When its animation ends, walks the figure one way at random for 32 frames. */
void kind_9e_wander(uint16_t object)
{
	uint8_t animation_flags = 0, state = 0;
	uint16_t x_speed = 0;

	animation_flags = OBJECT(object)->animation_flags;
	if ((animation_flags & 1u) == 0u)
		return;
	OBJECT(object)->animation = 0x81u;
	OBJECT(object)->timer = 0x20u;
	OBJECT(object)->x_speed = 0x100;
	if ((int8_t)random_number < 0)
	{
		x_speed = OBJECT(object)->x_speed;
		OBJECT(object)->x_speed = 0u - x_speed;
	}
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
	face_movement(object);
}

/* Keeps the figure pacing between x 00E0 and 0100 until the scroll reaches 0340, then makes it stand and
   wait. */
void kind_9e_pace(uint16_t object)
{
	uint8_t x_high = 0, x_low = 0;
	uint8_t timer = 0, state = 0, state_2 = 0;
	uint16_t camera_position = 0, screen_x = 0;

	camera_position = camera_x;
	if (camera_position < 0x340u)
	{
		timer = OBJECT(object)->timer;
		OBJECT(object)->timer = timer - 1u;
		if (timer == 1u)
		{
			OBJECT(object)->x_speed = 0;
			OBJECT(object)->animation = 0x80u;
			state = OBJECT(object)->state;
			OBJECT(object)->state = state - 1u;
			return;
		}
		screen_x = OBJECT(object)->x;
		x_low = (uint8_t)screen_x;
		x_high = (uint8_t)(screen_x >> 8);
		if ((uint16_t)(((uint32_t)x_high << 8) | (x_low & 0xFFu)) < 0xE0u)
		{
			OBJECT(object)->x_speed = 0x100;
			return;
		}
		if ((uint16_t)(((uint32_t)x_high << 8) | (x_low & 0xFFu)) >= 0x100u)
			OBJECT(object)->x_speed = -0x100;
		return;
	}
	OBJECT(object)->x_speed = 0;
	OBJECT(object)->animation = 0x80u;
	OBJECT(object)->timer = 0x80u;
	state_2 = OBJECT(object)->state;
	OBJECT(object)->state = state_2 + 1u;
}

/* Counts the wait down, then walks the figure off to the left. */
void kind_9e_leave(uint16_t object)
{
	uint8_t timer = 0, state = 0;

	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer != 1u)
		return;
	OBJECT(object)->animation = 0x81u;
	OBJECT(object)->x_speed = -0x100;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
	face_movement(object);
}

/* Frees the figure's slot when it reaches the screen's left edge. */
void kind_9e_remove_at_edge(uint16_t object)
{
	uint16_t screen_x = 0;

	screen_x = OBJECT(object)->x;
	if (screen_x < 0x30u)
		OBJECT(object)->flags = 0u;
}

/* Sets the kind 8E figure up in its pose from kind_8e_poses; state 0 waits for work RAM 187F, the others
   just stand. */
uint16_t kind_8e_watcher_setup(uint16_t object)
{
	uint16_t look = 0, setup = 0;
	uint8_t parameter = 0, parameter_2 = 0, state = 0;
	uint16_t flags = 0;

	setup = kind_8e_watcher_object_setup_ADDRESS;
	vector_object_setup(object, setup);
	OBJECT(object)->flags = 0x80u;
	parameter = OBJECT(object)->parameter;
	look = kind_8e_poses_ADDRESS + (int8_t)((uint32_t)parameter << 1);
	flags = (((uint32_t)POSE(look)->flags << 8u) | POSE(look)->animation);
	OBJECT(object)->attributes = flags >> 8;
	OBJECT(object)->animation = flags;
	parameter_2 = OBJECT(object)->parameter;
	if (parameter_2 != 0u)
	{
		state = OBJECT(object)->state;
		OBJECT(object)->state = state + 1u;
		kind_8e_watcher_stand();
		return look;
	}
	OBJECT(object)->state = 2u;
	return look;
}

/* The figure standing: nothing to do. */
void kind_8e_watcher_stand(void)
{
}

/* When work RAM 187F is set, sets field 44 of the four players' objects to 9F and makes the figure
   hittable. */
void kind_8e_watcher_wait_signal(uint16_t object)
{
	uint8_t watch_signal = 0, state = 0;

	watch_signal = io_read8(rising_scenery_cue);
	if (watch_signal != 0u)
	{
		OBJECT(OBJECT_ADDRESS(0))->player.pose_animation = 0x9Fu;
		OBJECT(OBJECT_ADDRESS(2))->player.pose_animation = 0x9Fu;
		OBJECT(OBJECT_ADDRESS(4))->player.pose_animation = 0x9Fu;
		OBJECT(OBJECT_ADDRESS(6))->player.pose_animation = 0x9Fu;
		OBJECT(object)->flags = 0xC0u;
		state = OBJECT(object)->state;
		OBJECT(object)->state = state + 1u;
	}
}

/* When the figure is hit, makes it unhittable and leaves it standing. */
void kind_8e_watcher_wait_hit(uint16_t object)
{
	if ((OBJECT(object)->flags & 0x20u) != 0u)
	{
		OBJECT(object)->flags = 0x80u;
		OBJECT(object)->state = 1u;
	}
}

/* Unused: does nothing. */
void unused_kind_8e_watcher_no_op(void)
{
}

/* The bystander leaving (step FD), by field 28. */
void kind_8c_bystander_leave(uint16_t object)
{
	uint8_t action = 0;

	for (;;)
	{
		action = OBJECT(object)->action;
		switch ((int8_t)(uint8_t)((uint32_t)action << 1))
		{
		case 0:
			kind_8c_bystander_turn_away(object);
			return;
		case 2:
		case 8:
			kind_8c_bystander_walk_off(object);
			return;
		case 4:
		case 10:
			kind_8c_bystander_walking();
			return;
		case 6:
			break;
		case -10:
			continue;
		case -8:
		case -6:
			kind_8c_bystander_hurt(object);
			return;
		case -4:
			kind_8c_bystander_setup(object);
			return;
		case -2:
			kind_8c_bystander_pose(object);
			return;
		}
		break;
	}
	kind_8c_bystander_reel(object);
}

/* Stops the bystander and plays its turning animation. */
void kind_8c_bystander_turn_away(uint16_t object)
{
	uint8_t action = 0;

	OBJECT(object)->x_speed = 0;
	OBJECT(object)->y_speed = 0;
	OBJECT(object)->animation = 0x90u;
	action = OBJECT(object)->action;
	OBJECT(object)->action = action + 1u;
}

/* The bystander when hit (steps FE, FF), by field 28: it reels and walks off. */
void kind_8c_bystander_hurt(uint16_t object)
{
	uint8_t action = 0;

	for (;;)
	{
		action = OBJECT(object)->action;
		switch ((int8_t)(uint8_t)((uint32_t)action << 1))
		{
		case 0:
			break;
		case -4:
		case 2:
			kind_8c_bystander_walk_off(object);
			return;
		case -2:
		case 4:
			kind_8c_bystander_walking();
			return;
		case -16:
			kind_8c_bystander_leave(object);
			return;
		case -14:
		case -12:
			continue;
		case -10:
			kind_8c_bystander_setup(object);
			return;
		case -8:
			kind_8c_bystander_pose(object);
			return;
		case -6:
			kind_8c_bystander_turn_away(object);
			return;
		}
		break;
	}
	kind_8c_bystander_reel(object);
}

/* Stops the hit bystander with the hit sound and its hurt animation. */
void kind_8c_bystander_reel(uint16_t object)
{
	uint16_t command = 0;
	uint8_t action = 0;

	command = 0x6300u;
	vector_queue_sound(command);
	OBJECT(object)->x_speed = 0;
	OBJECT(object)->y_speed = 0;
	OBJECT(object)->animation = 0x89u;
	action = OBJECT(object)->action;
	OBJECT(object)->action = action + 1u;
}

/* When its animation ends, walks the bystander off to the left. */
void kind_8c_bystander_walk_off(uint16_t object)
{
	uint8_t animation_flags = 0, action = 0;

	animation_flags = OBJECT(object)->animation_flags;
	if ((animation_flags & 1u) == 0u)
		return;
	OBJECT(object)->x_speed = -0x180;
	OBJECT(object)->animation = 0x81u;
	action = OBJECT(object)->action;
	OBJECT(object)->action = action + 1u;
	face_movement(object);
}

/* The bystander walking off: nothing to do until it leaves the screen. */
void kind_8c_bystander_walking(void)
{
}

/* Sets the bystander up facing left, out of the enemy count. */
void kind_8c_bystander_setup(uint16_t object)
{
	uint16_t setup = 0;
	uint8_t state = 0;

	setup = kind_8c_bystander_object_setup_ADDRESS;
	vector_object_setup(object, setup);
	OBJECT(object)->attributes = 0x40u;
	OBJECT(object)->enemy_class = -1;
	OBJECT(object)->entrance_pending = 0xFFu;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
}

/* Every 128 frames shows the bystander's next pose from kind_8c_animations; when the scroll reaches 0270
   it leaves (step FD). */
void kind_8c_bystander_pose(uint16_t object)
{
	uint8_t pose = 0, pose_2 = 0;
	uint16_t camera_position = 0;

	if ((frame_count & 0x7Fu) == 0u)
	{
		pose = OBJECT(object)->kind_8c_bystander.pose;
		OBJECT(object)->kind_8c_bystander.pose = pose + 1u;
		pose_2 = OBJECT(object)->kind_8c_bystander.pose;
		OBJECT(object)->animation = kind_8c_animations[pose_2 & 3u];
	}
	camera_position = camera_x;
	if (camera_position >= 0x270u)
	{
		OBJECT(object)->flags = 0x80u;
		OBJECT(object)->state = 0xFDu;
		OBJECT(object)->action = 0u;
	}
}

/* The carrier when hit or when it has set its goon down (steps FE, FF), by field 28: it runs off. */
void kind_8a_carrier_hurt(uint16_t object)
{
	uint8_t action = 0;

	for (;;)
	{
		action = OBJECT(object)->action;
		switch ((int8_t)(uint8_t)((uint32_t)action << 1))
		{
		case 0:
			kind_8a_carrier_run_off(object);
			return;
		case 2:
			break;
		case -16:
		case -14:
			continue;
		case -12:
			kind_8a_carrier_setup(object);
			return;
		case -10:
			kind_8a_carrier_pick_up(object);
			return;
		case -8:
			kind_8a_carrier_carry(object);
			return;
		case -6:
			kind_8a_carrier_set_down(object);
			return;
		case -4:
			kind_8a_carrier_straighten(object);
			return;
		case -2:
			kind_8a_carrier_done(object);
			return;
		}
		break;
	}
	kind_8a_carrier_running();
}

/* Sends the carrier running off to the right. */
void kind_8a_carrier_run_off(uint16_t object)
{
	uint8_t action = 0;

	OBJECT(object)->animation = 0x82u;
	OBJECT(object)->x_speed = 0x200;
	action = OBJECT(object)->action;
	OBJECT(object)->action = action + 1u;
	face_movement(object);
}

/* The carrier running off: nothing to do until it leaves the screen. */
void kind_8a_carrier_running(void)
{
}

/* Sets the carrier up out of the enemy count, coming in from the right. */
void kind_8a_carrier_setup(uint16_t object)
{
	uint16_t setup = 0;
	uint8_t enemy_class = 0, state = 0;

	setup = kind_8a_carrier_object_setup_ADDRESS;
	vector_object_setup(object, setup);
	enemy_class = OBJECT(object)->enemy_class;
	OBJECT(object)->enemy_class = enemy_class - 1u;
	OBJECT(object)->x_speed = -0x200;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
}

/* Puts in the goon it carries (5280 type 17) and walks in with it; with no free slot it runs off. */
void kind_8a_carrier_pick_up(uint16_t object)
{
	uint32_t slot_found = 0;
	uint16_t carried_goon = 0, ignored16 = 0, ignored16_2 = 0;
	uint8_t state = 0;

	leftover_y = kind_8a_carrier_pick_up_child_ADDRESS;
	vector_spawn_child(object, &ignored16, &carried_goon, &ignored16_2, &slot_found);
	if (slot_found == 0u)
	{
		OBJECT(object)->state = 0xFEu;
		OBJECT(object)->action = 0u;
		return;
	}
	OBJECT(object)->kind_8a_carrier.carried_goon = carried_goon;
	OBJECT(object)->timer = 0x40u;
	OBJECT(object)->flags = 0xC0u;
	OBJECT(object)->x_speed = -0x100;
	OBJECT(object)->animation = 0x81u;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
	face_movement(object);
}

/* Keeps the goon on the carrier's back while it walks in; when its walk is over it stops; if the goon is
   hit the carrier lets it go. */
void kind_8a_carrier_carry(uint16_t object)
{
	uint16_t carried_goon = 0;
	uint8_t state = 0, animation_flags = 0, timer = 0, state_2 = 0;
	uint16_t carried_goon_2 = 0, carried_goon_3 = 0, carrier_x = 0, carrier_y = 0, goon_y = 0, z = 0, goon_z = 0;

	carried_goon_2 = OBJECT(object)->kind_8a_carrier.carried_goon;
	carried_goon = carried_goon_2;
	state = OBJECT(carried_goon)->state;
	if ((int8_t)state < 0)
	{
		OBJECT(object)->state = 5u;
		return;
	}
	carried_goon_3 = OBJECT(object)->kind_8a_carrier.carried_goon;
	carried_goon = carried_goon_3;
	animation_flags = OBJECT(carried_goon)->animation_flags;
	OBJECT(carried_goon)->animation_flags = animation_flags | 0x80u;
	carrier_x = OBJECT(object)->x;
	OBJECT(carried_goon)->x = carrier_x;
	carrier_y = OBJECT(object)->y;
	goon_y = carrier_y - 4u;
	OBJECT(carried_goon)->y = goon_y;
	z = OBJECT(object)->z;
	goon_z = z + 0x40u;
	OBJECT(carried_goon)->z = goon_z;
	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer == 1u)
	{
		OBJECT(object)->timer = 0x10u;
		OBJECT(object)->x_speed = 0;
		OBJECT(object)->y_speed = 0;
		state_2 = OBJECT(object)->state;
		OBJECT(object)->state = state_2 + 1u;
	}
}

/* Plays the carrier setting the goon down and lets the goon fight (its step 2). */
void kind_8a_carrier_set_down(uint16_t object)
{
	uint16_t carried_goon = 0;
	uint8_t state = 0;
	uint16_t carried_goon_2 = 0;

	OBJECT(object)->animation = 0x84u;
	carried_goon_2 = OBJECT(object)->kind_8a_carrier.carried_goon;
	carried_goon = carried_goon_2;
	OBJECT(carried_goon)->state = 2u;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
}

/* When that animation ends, plays animation 83. */
void kind_8a_carrier_straighten(uint16_t object)
{
	uint8_t animation_flags = 0, state = 0;

	animation_flags = OBJECT(object)->animation_flags;
	if (animation_flags & 1u)
	{
		OBJECT(object)->animation = 0x83u;
		state = OBJECT(object)->state;
		OBJECT(object)->state = state + 1u;
	}
}

/* When that animation ends, sends the carrier off (step FE). */
void kind_8a_carrier_done(uint16_t object)
{
	uint8_t animation_flags = 0;

	animation_flags = OBJECT(object)->animation_flags;
	if ((animation_flags & 1u) == 0u)
		return;
	OBJECT(object)->flags = 0x80u;
	OBJECT(object)->state = 0xFEu;
	OBJECT(object)->action = 0u;
}
