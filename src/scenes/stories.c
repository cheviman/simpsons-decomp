/**
 *    Name:        scenes/stories.c
 *    Description: bank 1F's entries: the stages' story scenes and events, the story actors' types
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    11-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the game's 053248 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

/* Runs stage 1's closing story on the actor at 5640 */
uint16_t story_stage_1_end(uint16_t object_2)
{
	uint16_t object = 0;

	object = OBJECT_ADDRESS(32);
	io_write16(stage_kept_object, OBJECT_ADDRESS(32));
	OBJECT(OBJECT_ADDRESS(32))->story_actor.script_number = 0x10u;
	story_actor_run(&object, &object_2);
	return object_2;
}

/* Stage 2's events while it plays: the actor at 5640 on its script */
void stage_2_events(void)
{
	uint8_t animation_flags = 0;
	uint16_t actor = 0, child = 0, ignored16 = 0;
	uint8_t animation_flags_2 = 0;
	uint16_t child_actor_3 = 0, z = 0, child_actor = 0, second_child = 0;

	actor = OBJECT_ADDRESS(32);
	OBJECT(OBJECT_ADDRESS(32))->story_actor.script_number = 0x14u;
	story_actor_run(&actor, &ignored16);
	child_actor_3 = OBJECT(actor)->story_actor.child_actor_3;
	child = child_actor_3;
	OBJECT(child)->shadow_player = 1u;
	z = OBJECT(child)->z;
	if ((int16_t)z < 0)
	{
		OBJECT(child)->z = 0u;
		animation_flags_2 = OBJECT(child)->animation_flags;
		animation_flags = animation_flags_2 | 0x80u;
		OBJECT(child)->animation_flags = animation_flags;
		child_actor = OBJECT(actor)->story_actor.child_actor_1;
		child = child_actor;
		OBJECT(child)->z = 0u;
		OBJECT(child)->animation_flags = animation_flags;
		second_child = OBJECT(actor)->story_actor.child_actor_2;
		child = second_child;
		OBJECT(child)->z = 0u;
		OBJECT(child)->animation_flags = animation_flags;
	}
}

/* A story actor that takes its parent's kind and starts 40 higher than its own place */
void story_follower(uint16_t *p_object, uint16_t *p_object_2)
{
	uint16_t object = (uint16_t)*p_object;
	uint16_t object_2 = (uint16_t)*p_object_2;
	uint8_t kind = 0;
	uint16_t parent = 0, z = 0, new_z = 0;

	if (OBJECT(object)->flags != 4u)
		story_actor_run(&object, &object_2);
	else
	{
		parent = OBJECT(object)->parent;
		kind = OBJECT(parent)->kind;
		OBJECT(object)->kind = kind;
		z = OBJECT(object)->z;
		new_z = z + 0x40u;
		OBJECT(object)->z = new_z;
		story_actor_run(&object, &object_2);
	}
	*p_object = object;
	*p_object_2 = object_2;
}

/* Runs stage 2's closing story on the actor at 5640 */
void story_stage_2_end(void)
{
	uint16_t ignored16 = 0, object = 0;

	object = OBJECT_ADDRESS(32);
	OBJECT(OBJECT_ADDRESS(32))->story_actor.script_number = 0x2Cu;
	story_actor_run(&object, &ignored16);
}

/* Unused: a slot of the stories' bank that does nothing. */
void unused_story_vector_no_op_1(void)
{
}

/* Unused: a slot of the stories' bank that does nothing. */
void unused_story_vector_no_op_2(void)
{
}

/* Stage 3's forest events: the actor at 5640 on its script */
void stage_3_forest_events(void)
{
	uint16_t ignored16 = 0, object = 0;

	object = OBJECT_ADDRESS(32);
	OBJECT(OBJECT_ADDRESS(32))->parameter = 0x1Cu;
	story_actor_run(&object, &ignored16);
}

/* The stage's event object at 5640 as a story actor on its script */
uint16_t stage_event_actor(uint16_t object)
{
	uint16_t ignored16 = 0;

	io_write16(stage_kept_object, object);
	OBJECT(object)->parameter = 0x20u;
	story_actor_run(&object, &ignored16);
	return object;
}

/* A story actor noted in 1854 for the stories */
void story_noted_actor(uint16_t *p_x, uint16_t *p_object_2)
{
	uint16_t x = (uint16_t)*p_x;
	uint16_t object = (uint16_t)*p_object_2;

	io_write16(stage_kept_object_2, x);
	*p_x = x;
	*p_object_2 = object;
	story_actor_run(p_x, p_object_2);
}

/* Stage 4's events: the actor at 5640 on its script */
void stage_4_events(void)
{
	uint16_t ignored16 = 0, object = 0;

	object = OBJECT_ADDRESS(32);
	OBJECT(OBJECT_ADDRESS(32))->parameter = 0x30u;
	story_actor_run(&object, &ignored16);
}

/* Runs stage 4's closing story on the actor at 5640 */
void story_stage_4_end(void)
{
	uint16_t ignored16 = 0, object = 0;
	uint16_t noted_actor = 0;

	object = OBJECT_ADDRESS(32);
	io_write16(stage_kept_object_2, OBJECT_ADDRESS(32));
	OBJECT(OBJECT_ADDRESS(32))->story_actor.script_number = 0xCu;
	noted_actor = io_read16(stage_kept_object);
	OBJECT(OBJECT_ADDRESS(32))->story_actor.child_actor_2 = noted_actor;
	story_actor_run(&object, &ignored16);
}

/* Does nothing: an object the stories keep in 1852 to refer to */
void story_marker(void)
{
}

/* A story actor of list 2 (type 07) */
void story_extra_actor(uint16_t *p_object, uint16_t *p_object_2)
{
	uint16_t object = (uint16_t)*p_object;
	uint16_t object_2 = (uint16_t)*p_object_2;

	*p_object = object;
	*p_object_2 = object_2;
	story_actor_run(p_object, p_object_2);
}

/* Stage 5's events: the actor at 5640, with Marge's partner object noted in 1852 */
void stage_5_events(void)
{
	uint16_t ignored16 = 0, object = 0;

	io_write16(stage_kept_object, OBJECT_ADDRESS(1));
	object = OBJECT_ADDRESS(32);
	story_actor_run(&object, &ignored16);
}

/* Stage 1's events: the actor at 5640 on its script */
void stage_1_events(void)
{
	uint16_t ignored16 = 0, object = 0;

	object = OBJECT_ADDRESS(32);
	OBJECT(OBJECT_ADDRESS(32))->parameter = 0x38u;
	story_actor_run(&object, &ignored16);
}

/* Unused: runs the stage's events object (list 3's) as a story actor on script 24, noting it in 1854. */
void unused_events_actor_24(void)
{
	uint16_t ignored16 = 0, object = 0;

	object = OBJECT_ADDRESS(32);
	io_write16(stage_kept_object_2, OBJECT_ADDRESS(32));
	OBJECT(OBJECT_ADDRESS(32))->parameter = 0x24u;
	story_actor_run(&object, &ignored16);
}

/* A story actor of list 2 (type 14) */
void story_extra_actor_2(uint16_t *p_object, uint16_t *p_object_2)
{
	uint16_t object = (uint16_t)*p_object;
	uint16_t object_2 = (uint16_t)*p_object_2;

	*p_object = object;
	*p_object_2 = object_2;
	story_actor_run(p_object, p_object_2);
}

/* A story actor of list 2 (type 15) */
void story_extra_actor_3(uint16_t *p_object, uint16_t *p_object_2)
{
	uint16_t object = (uint16_t)*p_object;
	uint16_t object_2 = (uint16_t)*p_object_2;

	*p_object = object;
	*p_object_2 = object_2;
	story_actor_run(p_object, p_object_2);
}

/* Runs stage 5's closing story on the actor at 5640 */
uint16_t story_stage_5_end(uint16_t object_2)
{
	uint16_t object = 0;

	object = OBJECT_ADDRESS(32);
	io_write16(stage_kept_object_2, OBJECT_ADDRESS(32));
	OBJECT(OBJECT_ADDRESS(32))->story_actor.script_number = 0x24u;
	story_actor_run(&object, &object_2);
	return object_2;
}

/* Stage 7's events: the actor at 5640 on stage 4's script */
void stage_7_events(void)
{
	uint16_t ignored16 = 0, object = 0;

	object = OBJECT_ADDRESS(32);
	OBJECT(OBJECT_ADDRESS(32))->parameter = 0x30u;
	story_actor_run(&object, &ignored16);
}

/* Runs stage 7's closing story on the actor at 5640 */
uint16_t story_stage_7_end(uint16_t object_2)
{
	uint16_t object = 0;

	object = OBJECT_ADDRESS(32);
	io_write16(stage_kept_object, OBJECT_ADDRESS(32));
	OBJECT(OBJECT_ADDRESS(32))->story_actor.script_number = 0x34u;
	story_actor_run(&object, &object_2);
	return object_2;
}

/* Stage 6's events: the actor at 5640 on its script */
void stage_6_events(void)
{
	uint16_t ignored16 = 0, object = 0;

	object = OBJECT_ADDRESS(32);
	OBJECT(OBJECT_ADDRESS(32))->parameter = 0x4Cu;
	story_actor_run(&object, &ignored16);
}

/* Unused: runs the stage's events object (list 3's) as a story actor on script 50. */
void unused_events_actor_50(void)
{
	uint16_t ignored16 = 0, object = 0;

	object = OBJECT_ADDRESS(32);
	OBJECT(OBJECT_ADDRESS(32))->parameter = 0x50u;
	story_actor_run(&object, &ignored16);
}

/* Stage 3's cemetery events: the actor at 5640 on its script */
void stage_3_cemetery_events(void)
{
	uint16_t ignored16 = 0, object = 0;

	object = OBJECT_ADDRESS(32);
	OBJECT(OBJECT_ADDRESS(32))->parameter = 0x54u;
	story_actor_run(&object, &ignored16);
}

/* Runs stage 3's closing story on the actor at 5640 */
uint16_t story_stage_3_end(uint16_t object_2)
{
	uint16_t object = 0;

	object = OBJECT_ADDRESS(32);
	OBJECT(OBJECT_ADDRESS(32))->story_actor.script_number = 0x58u;
	story_actor_run(&object, &object_2);
	return object_2;
}

/* Stage 8's events: the actor at 5640 on its script */
void stage_8_events(void)
{
	uint8_t wait = 0;
	uint16_t ignored16 = 0, object = 0;
	uint8_t noted_wait = 0, discarded_read = 0;
	uint16_t noted_actor = 0;

	object = OBJECT_ADDRESS(32);
	OBJECT(OBJECT_ADDRESS(32))->story_actor.script_number = 0x5Cu;
	noted_wait = io_read8(stage_kept_object_2);
	wait = noted_wait;
	if (noted_wait == 0u)
	{
		story_actor_run(&object, &ignored16);
		return;
	}
	noted_actor = io_read16(stage_kept_object);
	mem_write8(noted_actor + 0x2Au, wait - 1u);
	discarded_read = io_read8(stage_kept_object_2);
	io_write8(stage_kept_object_2, 0u);
	story_actor_run(&object, &ignored16);
}

/* Runs the story after Mr. Burns' robot, the players' second sprites lined up by the object in 1852 */
uint16_t story_stage_8_end(void)
{
	uint32_t zero = 0;
	uint8_t flags = 0, noted_x_high = 0, noted_x_low = 0, speed_high = 0, speed_low = 0;
	uint16_t actor = 0, noted_actor = 0, player = 0;
	uint16_t stack = 0;
	uint8_t flags_2 = 0, kind = 0;
	uint16_t noted_object = 0, noted_x = 0, kind_offset = 0, noted_again = 0, noted_x_again = 0, partner_x = 0, noted_y = 0, partner_y = 0;

	actor = OBJECT_ADDRESS(32);
	OBJECT(OBJECT_ADDRESS(32))->story_actor.acceleration_x = 0;
	noted_object = io_read16(stage_kept_object);
	noted_actor = noted_object;
	noted_x = OBJECT(noted_actor)->x;
	noted_x_high = (uint8_t)(noted_x >> 8);
	noted_x_low = (uint8_t)noted_x;
	if ((int16_t)(((uint32_t)noted_x_high << 8) | noted_x_low) < 0xAF)
	{
		speed_high = 0xFEu;
		speed_low = 0u;
		OBJECT(actor)->story_actor.acceleration_x = ((uint32_t)speed_high << 8) | speed_low;
		OBJECT(actor)->story_actor.acceleration_y = -0x100;
	}
	else if ((int16_t)(((uint32_t)noted_x_high << 8) | noted_x_low) > 0xB1)
	{
		speed_high = 2u;
		speed_low = 0u;
		OBJECT(actor)->story_actor.acceleration_x = ((uint32_t)speed_high << 8) | speed_low;
		OBJECT(actor)->story_actor.acceleration_y = -0x100;
	}
	stack = actor;
	player = story_first_player();
	do
	{
		flags_2 = OBJECT(player)->flags;
		flags = flags_2;
		if (flags_2 != 0u)
		{
			OBJECT(player)->flags = flags | 0x40u;
			kind = OBJECT(player)->kind;
			kind_offset = (int8_t)((((((uint32_t)kind << 1) << 1) << 1) << 1) << 1);
			noted_again = io_read16(stage_kept_object);
			noted_actor = noted_again;
			noted_x_again = OBJECT(noted_actor)->x;
			partner_x = kind_offset + noted_x_again;
			OBJECT(player + 0x60u)->x = partner_x;
			noted_y = OBJECT(noted_actor)->y;
			partner_y = noted_y + 0x10u;
			OBJECT(player + 0x60u)->y = partner_y;
		}
		story_next_player(&player, &zero);
	} while (zero == 0u);
	actor = stack;
	OBJECT(actor)->story_actor.script_number = 0x60u;
	story_actor_run(&actor, &noted_actor);
	return noted_actor;
}

/* Runs the story before Mr. Burns' robot, each player's second sprite put at its character's place on
   the screen */
uint16_t story_burns_robot_entrance(uint16_t object_2)
{
	uint32_t zero = 0;
	uint8_t camera_x_high = 0, camera_x_low = 0, flags = 0, speed_high = 0, speed_low = 0;
	uint16_t actor = 0, player = 0;
	uint16_t stack = 0;
	uint8_t flags_2 = 0, kind = 0;
	uint16_t camera_x_now = 0, kind_offset = 0, offset_place_x = 0, partner_x = 0, partner_y = 0;

	actor = OBJECT_ADDRESS(32);
	OBJECT(OBJECT_ADDRESS(32))->story_actor.script_number = 0x64u;
	OBJECT(OBJECT_ADDRESS(32))->story_actor.acceleration_x = 0;
	camera_x_now = camera_x;
	camera_x_high = (uint8_t)(camera_x_now >> 8);
	camera_x_low = (uint8_t)camera_x_now;
	if ((int16_t)(((uint32_t)camera_x_high << 8) | camera_x_low) < 0x33C)
	{
		speed_high = 2u;
		speed_low = 0u;
		OBJECT(actor)->story_actor.acceleration_x = ((uint32_t)speed_high << 8) | speed_low;
	}
	else if ((int16_t)(((uint32_t)camera_x_high << 8) | camera_x_low) > 0x33E)
	{
		speed_high = 0xFEu;
		speed_low = 0u;
		OBJECT(actor)->story_actor.acceleration_x = ((uint32_t)speed_high << 8) | speed_low;
	}
	stack = actor;
	player = story_first_player();
	do
	{
		flags_2 = OBJECT(player)->flags;
		flags = flags_2;
		if (flags_2 != 0u)
		{
			OBJECT(player)->flags = flags | 0x40u;
			kind = OBJECT(player)->kind;
			kind_offset = (int8_t)((((((uint32_t)kind << 1) << 1) << 1) << 1) << 1);
			offset_place_x = kind_offset + 0x3EDu;
			partner_x = offset_place_x - camera_x;
			OBJECT(player + 0x60u)->x = partner_x;
			partner_y = 0xB0u + camera_y;
			OBJECT(player + 0x60u)->y = partner_y;
		}
		story_next_player(&player, &zero);
	} while (zero == 0u);
	actor = stack;
	OBJECT(actor)->story_actor.acceleration_y = 0x100;
	story_actor_run(&actor, &object_2);
	return object_2;
}

/* Copies the scene's 8 bytes of settings to 1840-1847 and clears the stories' flags */
void scene_load_story_settings(uint16_t *p_copy_to, uint16_t *p_count)
{
	uint16_t copy_to = 0, count = 0, settings = 0;
	uint8_t discarded_read = 0, discarded_read_2 = 0, discarded_read_3 = 0, discarded_read_4 = 0;

	settings = story_scene_settings_ADDRESS + (int8_t)((((uint32_t)scene << 1) << 1) << 1);
	copy_to = bonus_2_state;
	count = 8u;
	while (count != 0u)
	{
		mem_write8(copy_to, mem_read8(settings));
		settings++;
		copy_to++;
		count--;
	}
	discarded_read = io_read8(players_stop_request);
	io_write8(players_stop_request, 0u);
	discarded_read_2 = io_read8(players_all_idle);
	io_write8(players_all_idle, 0u);
	discarded_read_3 = io_read8(0x1850u);
	io_write8(0x1850u, 0u);
	discarded_read_4 = io_read8(player_balloons_off);
	io_write8(player_balloons_off, 0u);
	leftover_y = settings;
	*p_copy_to = copy_to;
	*p_count = count;
}
