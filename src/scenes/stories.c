/**
 *    Name:        scenes/stories.c
 *    Description: bank 1F's entries: the stages' story scenes and events, the story actors' types
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    09-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the game's 053248 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

/* Runs stage 1's closing story on the actor at 5640 */
uint16_t story_stage_1_end(uint16_t object_3)
{
	uint16_t ignored16 = 0, object = 0;

	object = OBJECT_ADDRESS(32);
	io_write16(0x1852u, OBJECT_ADDRESS(32));
	OBJECT(OBJECT_ADDRESS(32))->story_actor.script_number = 0x10u;
	story_actor_run(&object, &ignored16, &object_3);
	return object_3;
}

/* Stage 2's events while it plays: the actor at 5640 on its script */
void stage_2_events(void)
{
	uint8_t animation_flags = 0;
	uint16_t actor = 0, child = 0, ignored16 = 0, ignored16_2 = 0;
	uint8_t animation_flags_2 = 0;
	uint16_t next_floor_cell = 0, z = 0, child_actors = 0, t1 = 0;

	actor = OBJECT_ADDRESS(32);
	OBJECT(OBJECT_ADDRESS(32))->parameter = 0x14u;
	story_actor_run(&actor, &ignored16, &ignored16_2);
	next_floor_cell = (((uint32_t)OBJECT(actor)->next_floor_cell << 8u) | (OBJECT(actor)->hit_box >> 8u));
	child = next_floor_cell;
	OBJECT(child)->shadow_player = 1u;
	z = OBJECT(child)->z;
	if ((int16_t)z < 0)
	{
		OBJECT(child)->z = 0u;
		animation_flags_2 = OBJECT(child)->animation_flags;
		animation_flags = animation_flags_2 | 0x80u;
		OBJECT(child)->animation_flags = animation_flags;
		child_actors = OBJECT(actor)->story_actor.child_actors;
		child = child_actors;
		OBJECT(child)->z = 0u;
		OBJECT(child)->animation_flags = animation_flags;
		t1 = (((uint32_t)OBJECT(actor)->unk_45 << 8u) | OBJECT(actor)->floor_cell);
		child = t1;
		OBJECT(child)->z = 0u;
		OBJECT(child)->animation_flags = animation_flags;
	}
}

/* A story actor that takes its parent's kind and starts 40 higher than its own place */
void story_follower(uint16_t *p_object, uint16_t *p_object_3)
{
	uint16_t object = (uint16_t)*p_object;
	uint16_t object_3 = (uint16_t)*p_object_3;
	uint16_t ignored16 = 0;
	uint8_t kind = 0;
	uint16_t parent = 0, z = 0, t1 = 0;

	if (OBJECT(object)->flags != 4u)
		story_actor_run(&object, &ignored16, &object_3);
	else
	{
		parent = OBJECT(object)->parent;
		kind = OBJECT(parent)->kind;
		OBJECT(object)->kind = kind;
		z = OBJECT(object)->z;
		t1 = z + 0x40u;
		OBJECT(object)->z = t1;
		story_actor_run(&object, &ignored16, &object_3);
	}
	*p_object = object;
	*p_object_3 = object_3;
}

/* Runs stage 2's closing story on the actor at 5640 */
void story_stage_2_end(void)
{
	uint16_t ignored16 = 0, ignored16_2 = 0, object = 0;

	object = OBJECT_ADDRESS(32);
	OBJECT(OBJECT_ADDRESS(32))->story_actor.script_number = 0x2Cu;
	story_actor_run(&object, &ignored16, &ignored16_2);
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
	uint16_t ignored16 = 0, ignored16_2 = 0, object = 0;

	object = OBJECT_ADDRESS(32);
	OBJECT(OBJECT_ADDRESS(32))->parameter = 0x1Cu;
	story_actor_run(&object, &ignored16, &ignored16_2);
}

/* The stage's event object at 5640 as a story actor on its script */
uint16_t stage_event_actor(uint16_t object)
{
	uint16_t ignored16 = 0, ignored16_2 = 0;

	io_write16(0x1852u, object);
	OBJECT(object)->parameter = 0x20u;
	story_actor_run(&object, &ignored16, &ignored16_2);
	return object;
}

/* A story actor noted in 1854 for the stories */
void story_noted_actor(uint16_t *p_x, uint16_t *p_object_3)
{
	uint16_t x = (uint16_t)*p_x;
	uint16_t object = (uint16_t)*p_object_3;
	uint16_t ignored16 = 0;

	io_write16(0x1854u, x);
	*p_x = x;
	*p_object_3 = object;
	story_actor_run(p_x, &ignored16, p_object_3);
}

/* Stage 4's events: the actor at 5640 on its script */
void stage_4_events(void)
{
	uint16_t ignored16 = 0, ignored16_2 = 0, object = 0;

	object = OBJECT_ADDRESS(32);
	OBJECT(OBJECT_ADDRESS(32))->parameter = 0x30u;
	story_actor_run(&object, &ignored16, &ignored16_2);
}

/* Runs stage 4's closing story on the actor at 5640 */
void story_stage_4_end(void)
{
	uint16_t ignored16 = 0, ignored16_2 = 0, object = 0;
	uint16_t t1 = 0;

	object = OBJECT_ADDRESS(32);
	io_write16(0x1854u, OBJECT_ADDRESS(32));
	OBJECT(OBJECT_ADDRESS(32))->story_actor.script_number = 0xCu;
	t1 = io_read16(0x1852u);
	OBJECT(OBJECT_ADDRESS(32))->unk_45 = (uint8_t)(t1 >> 8u);
	OBJECT(OBJECT_ADDRESS(32))->floor_cell = (uint8_t)t1;
	story_actor_run(&object, &ignored16, &ignored16_2);
}

/* Does nothing: an object the stories keep in 1852 to refer to */
void story_marker(void)
{
}

/* A story actor of list 2 (type 07) */
void story_extra_actor(uint16_t *p_object, uint16_t *p_object_3)
{
	uint16_t object = (uint16_t)*p_object;
	uint16_t object_3 = (uint16_t)*p_object_3;
	uint16_t ignored16 = 0;

	*p_object = object;
	*p_object_3 = object_3;
	story_actor_run(p_object, &ignored16, p_object_3);
}

/* Stage 5's events: the actor at 5640, with Marge's partner object noted in 1852 */
void stage_5_events(void)
{
	uint16_t ignored16 = 0, ignored16_2 = 0, object = 0;

	io_write16(0x1852u, OBJECT_ADDRESS(1));
	object = OBJECT_ADDRESS(32);
	story_actor_run(&object, &ignored16, &ignored16_2);
}

/* Stage 1's events: the actor at 5640 on its script */
void stage_1_events(void)
{
	uint16_t ignored16 = 0, ignored16_2 = 0, object = 0;

	object = OBJECT_ADDRESS(32);
	OBJECT(OBJECT_ADDRESS(32))->parameter = 0x38u;
	story_actor_run(&object, &ignored16, &ignored16_2);
}

/* Unused: runs the stage's events object (list 3's) as a story actor on script 24, noting it in 1854. */
void unused_events_actor_24(void)
{
	uint16_t ignored16 = 0, ignored16_2 = 0, object = 0;

	object = OBJECT_ADDRESS(32);
	io_write16(0x1854u, OBJECT_ADDRESS(32));
	OBJECT(OBJECT_ADDRESS(32))->parameter = 0x24u;
	story_actor_run(&object, &ignored16, &ignored16_2);
}

/* A story actor of list 2 (type 14) */
void story_extra_actor_2(uint16_t *p_object, uint16_t *p_object_3)
{
	uint16_t object = (uint16_t)*p_object;
	uint16_t object_3 = (uint16_t)*p_object_3;
	uint16_t ignored16 = 0;

	*p_object = object;
	*p_object_3 = object_3;
	story_actor_run(p_object, &ignored16, p_object_3);
}

/* A story actor of list 2 (type 15) */
void story_extra_actor_3(uint16_t *p_object, uint16_t *p_object_3)
{
	uint16_t object = (uint16_t)*p_object;
	uint16_t object_3 = (uint16_t)*p_object_3;
	uint16_t ignored16 = 0;

	*p_object = object;
	*p_object_3 = object_3;
	story_actor_run(p_object, &ignored16, p_object_3);
}

/* Runs stage 5's closing story on the actor at 5640 */
uint16_t story_stage_5_end(uint16_t object_3)
{
	uint16_t ignored16 = 0, object = 0;

	object = OBJECT_ADDRESS(32);
	io_write16(0x1854u, OBJECT_ADDRESS(32));
	OBJECT(OBJECT_ADDRESS(32))->story_actor.script_number = 0x24u;
	story_actor_run(&object, &ignored16, &object_3);
	return object_3;
}

/* Stage 7's events: the actor at 5640 on stage 4's script */
void stage_7_events(void)
{
	uint16_t ignored16 = 0, ignored16_2 = 0, object = 0;

	object = OBJECT_ADDRESS(32);
	OBJECT(OBJECT_ADDRESS(32))->parameter = 0x30u;
	story_actor_run(&object, &ignored16, &ignored16_2);
}

/* Runs stage 7's closing story on the actor at 5640 */
uint16_t story_stage_7_end(uint16_t object_3)
{
	uint16_t ignored16 = 0, object = 0;

	object = OBJECT_ADDRESS(32);
	io_write16(0x1852u, OBJECT_ADDRESS(32));
	OBJECT(OBJECT_ADDRESS(32))->story_actor.script_number = 0x34u;
	story_actor_run(&object, &ignored16, &object_3);
	return object_3;
}

/* Stage 6's events: the actor at 5640 on its script */
void stage_6_events(void)
{
	uint16_t ignored16 = 0, ignored16_2 = 0, object = 0;

	object = OBJECT_ADDRESS(32);
	OBJECT(OBJECT_ADDRESS(32))->parameter = 0x4Cu;
	story_actor_run(&object, &ignored16, &ignored16_2);
}

/* Unused: runs the stage's events object (list 3's) as a story actor on script 50. */
void unused_events_actor_50(void)
{
	uint16_t ignored16 = 0, ignored16_2 = 0, object = 0;

	object = OBJECT_ADDRESS(32);
	OBJECT(OBJECT_ADDRESS(32))->parameter = 0x50u;
	story_actor_run(&object, &ignored16, &ignored16_2);
}

/* Stage 3's cemetery events: the actor at 5640 on its script */
void stage_3_cemetery_events(void)
{
	uint16_t ignored16 = 0, ignored16_2 = 0, object = 0;

	object = OBJECT_ADDRESS(32);
	OBJECT(OBJECT_ADDRESS(32))->parameter = 0x54u;
	story_actor_run(&object, &ignored16, &ignored16_2);
}

/* Runs stage 3's closing story on the actor at 5640 */
uint16_t story_stage_3_end(uint16_t object_3)
{
	uint16_t ignored16 = 0, object = 0;

	object = OBJECT_ADDRESS(32);
	OBJECT(OBJECT_ADDRESS(32))->story_actor.script_number = 0x58u;
	story_actor_run(&object, &ignored16, &object_3);
	return object_3;
}

/* Stage 8's events: the actor at 5640 on its script */
void stage_8_events(void)
{
	uint8_t wait = 0;
	uint16_t ignored16 = 0, ignored16_2 = 0, object = 0;
	uint8_t t1 = 0, t3 = 0;
	uint16_t t2 = 0;

	object = OBJECT_ADDRESS(32);
	OBJECT(OBJECT_ADDRESS(32))->parameter = 0x5Cu;
	t1 = io_read8(0x1854u);
	wait = t1;
	if (t1 == 0u)
	{
		story_actor_run(&object, &ignored16, &ignored16_2);
		return;
	}
	t2 = io_read16(0x1852u);
	mem_write8(t2 + 0x2Au, wait - 1u);
	t3 = io_read8(0x1854u);
	io_write8(0x1854u, 0u);
	story_actor_run(&object, &ignored16, &ignored16_2);
}

/* Runs the story after Mr. Burns' robot, the players' second sprites lined up by the object in 1852 */
uint16_t story_stage_8_end(void)
{
	uint32_t zero = 0;
	uint8_t flags = 0, noted_x_high = 0, noted_x_low = 0, speed_high = 0, speed_low = 0;
	uint16_t actor = 0, ignored16 = 0, noted_actor = 0, player = 0;
	uint16_t stack = 0;
	uint8_t flags_2 = 0, kind = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, t8 = 0;

	actor = OBJECT_ADDRESS(32);
	OBJECT(OBJECT_ADDRESS(32))->story_actor.acceleration_x = 0;
	t1 = io_read16(0x1852u);
	noted_actor = t1;
	t2 = OBJECT(noted_actor)->x;
	noted_x_high = (uint8_t)(t2 >> 8);
	noted_x_low = (uint8_t)t2;
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
			t3 = (int8_t)((((((uint32_t)kind << 1) << 1) << 1) << 1) << 1);
			t4 = io_read16(0x1852u);
			noted_actor = t4;
			t5 = OBJECT(noted_actor)->x;
			t6 = t3 + t5;
			OBJECT(player + 0x60u)->x = t6;
			t7 = OBJECT(noted_actor)->y;
			t8 = t7 + 0x10u;
			OBJECT(player + 0x60u)->y = t8;
		}
		story_next_player(&player, &zero);
	} while (zero == 0u);
	actor = stack;
	OBJECT(actor)->story_actor.script_number = 0x60u;
	story_actor_run(&actor, &ignored16, &noted_actor);
	return noted_actor;
}

/* Runs the story before Mr. Burns' robot, each player's second sprite put at its character's place on
   the screen */
uint16_t story_burns_robot_entrance(uint16_t object_3)
{
	uint32_t zero = 0;
	uint8_t camera_x_high = 0, camera_x_low = 0, flags = 0, speed_high = 0, speed_low = 0;
	uint16_t actor = 0, ignored16 = 0, player = 0;
	uint16_t stack = 0;
	uint8_t flags_2 = 0, kind = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0;

	actor = OBJECT_ADDRESS(32);
	OBJECT(OBJECT_ADDRESS(32))->story_actor.script_number = 0x64u;
	OBJECT(OBJECT_ADDRESS(32))->story_actor.acceleration_x = 0;
	t1 = camera_x;
	camera_x_high = (uint8_t)(t1 >> 8);
	camera_x_low = (uint8_t)t1;
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
			t2 = (int8_t)((((((uint32_t)kind << 1) << 1) << 1) << 1) << 1);
			t3 = t2 + 0x3EDu;
			t4 = t3 - camera_x;
			OBJECT(player + 0x60u)->x = t4;
			t5 = 0xB0u + camera_y;
			OBJECT(player + 0x60u)->y = t5;
		}
		story_next_player(&player, &zero);
	} while (zero == 0u);
	actor = stack;
	OBJECT(actor)->story_actor.acceleration_y = 0x100;
	story_actor_run(&actor, &ignored16, &object_3);
	return object_3;
}

/* Copies the scene's 8 bytes of settings to 1840-1847 and clears the stories' flags */
void scene_load_story_settings(uint16_t *p_copy_to, uint16_t *p_settings, uint16_t *p_count)
{
	uint16_t copy_to = 0, count = 0, settings = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0, t4 = 0;

	settings = story_scene_settings_ADDRESS + (int8_t)((((uint32_t)scene << 1) << 1) << 1);
	copy_to = 0x1840u;
	count = 8u;
	while (count != 0u)
	{
		mem_write8(copy_to, mem_read8(settings));
		settings++;
		copy_to++;
		count--;
	}
	t1 = io_read8(0x184Bu);
	io_write8(0x184Bu, 0u);
	t2 = io_read8(0x184Eu);
	io_write8(0x184Eu, 0u);
	t3 = io_read8(0x1850u);
	io_write8(0x1850u, 0u);
	t4 = io_read8(0x185Au);
	io_write8(0x185Au, 0u);
	*p_copy_to = copy_to;
	*p_settings = settings;
	*p_count = count;
}
