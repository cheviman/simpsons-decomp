/**
 *    Name:        stages/stage_events.c
 *    Description: the stage events: holding the scroll, the waves of enemies
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    09-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the game's 053248 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

/* Puts in one or two of bank 19's list 1 type FB objects (two from difficulty 3), then waits. */
uint16_t cleared_wave_start(uint16_t object)
{
	uint32_t carry = 0;
	uint16_t child = 0, ignored16 = 0, y = 0;
	uint8_t state = 0;

	OBJECT(object)->x = 0xE0u;
	y = cleared_wave_child_1_ADDRESS;
	vector_spawn_child(object, y, &child, &ignored16, &carry);
	if (carry)
		OBJECT(child)->behaviour = object;
	if (difficulty < 3u)
	{
		state = OBJECT(object)->state;
		OBJECT(object)->state = state + 1u;
		return cleared_wave_wait(object, y);
	}
	y = cleared_wave_child_2_ADDRESS;
	vector_spawn_child(object, y, &child, &ignored16, &carry);
	if (carry)
		OBJECT(child)->behaviour = object;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
	return cleared_wave_wait(object, y);
}

/* Holds the scroll until no enemy is left, then changes the palette, plays sound 9300 and puts in two
   goons. */
uint16_t cleared_wave_wait(uint16_t object, uint16_t y)
{
	uint32_t carry = 0;
	uint16_t command = 0, ignored16 = 0, ignored16_2 = 0, record = 0;
	uint8_t t1 = 0;

	t1 = io_read8(0x1876u);
	if (t1 != 0u)
	{
		camera_x_held--;
		return y;
	}
	stage_part = 2u;
	command = 0x9300u;
	carry = vector_queue_sound(command);
	OBJECT(object)->flags = 0u;
	record = cleared_wave_child_3_ADDRESS;
	vector_spawn_child(object, record, &ignored16, &ignored16_2, &carry);
	record = cleared_wave_child_4_ADDRESS;
	vector_spawn_child(object, record, &ignored16, &ignored16_2, &carry);
	return record;
}

/* Starts holding the scroll. */
void scroll_lock_start(uint16_t object)
{
	uint8_t state = 0;

	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
	scroll_lock(object);
}

/* Holds the scroll while there are more enemies than its count, then goes away. */
void scroll_lock(uint16_t object)
{
	uint8_t t1 = 0, enemies_left = 0;

	t1 = io_read8(0x1876u);
	enemies_left = OBJECT(object)->scroll_lock.enemies_left;
	if (enemies_left < t1)
	{
		camera_x_held--;
		return;
	}
	OBJECT(object)->flags = 0u;
}

/* Takes its spawn list and its counts by its spawn's state: the enemies left for the next wave (by the
   players) and for its end. */
void enemy_waves_start(uint16_t object)
{
	uint8_t wave = 0;
	uint8_t next_wave_enemies = 0, state = 0;

	next_wave_enemies = OBJECT(object)->enemy_waves.next_wave_enemies;
	wave = next_wave_enemies;
	OBJECT(object)->enemy_waves.end_enemies = object_15_times[(int8_t)wave];
	wave = (uint32_t)wave << 1;
	OBJECT(object)->enemy_waves.spawns = TABLE16(object_15_spawn_lists, (int8_t)wave);
	OBJECT(object)->enemy_waves.next_wave_enemies = TABLE8(object_15_next_kinds, (uint16_t)((int8_t)((uint32_t)wave << 1) + ((player_count - 1u) & 3u)));
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
}

/* Puts in the spawns of the current wave for which enough players are present. */
void enemy_waves_spawn(uint16_t object)
{
	uint32_t carry = 0;
	uint8_t b = 0, spawn_flags = 0;
	uint16_t enemy = 0, spawn = 0;
	uint8_t wave = 0, players = 0, t1 = 0, flags = 0, t2 = 0, t4 = 0, z = 0, state_2 = 0;
	uint16_t spawns = 0, state = 0, t3 = 0, t5 = 0, t6 = 0;

	spawns = OBJECT(object)->enemy_waves.spawns;
	spawn = spawns;
	if (TIMED_SPAWN(spawn)->time == 0xFFu)
	{
		OBJECT(object)->state = 3u;
		return;
	}
	for (;;)
	{
		wave = OBJECT(object)->enemy_waves.wave;
		if (TIMED_SPAWN(spawn)->time != wave)
			break;
		players = TIMED_SPAWN(spawn)->players;
		t1 = io_read8(0x1874u);
		if (players < t1)
		{
			flags = TIMED_SPAWN(spawn)->flags;
			spawn_flags = flags;
			vector_find_free_slot_by_flags(spawn_flags, &enemy, &carry);
			if (carry)
			{
				state = (((uint32_t)TIMED_SPAWN(spawn)->state << 8u) | TIMED_SPAWN(spawn)->type);
				OBJECT(enemy)->parameter = state >> 8;
				OBJECT(enemy)->type = state;
				t2 = TIMED_SPAWN(spawn)->x;
				t3 = (uint32_t)t2 << 3;
				OBJECT(enemy)->x = t3;
				t4 = TIMED_SPAWN(spawn)->y;
				t5 = (uint32_t)t4 << 3;
				t6 = t5 + camera_y;
				OBJECT(enemy)->y = t6;
				z = TIMED_SPAWN(spawn)->z;
				b = z;
				OBJECT(enemy)->z = b;
				OBJECT(enemy)->floor_z = b;
			}
		}
		spawn += 8u;
	}
	OBJECT(object)->enemy_waves.spawns = spawn;
	state_2 = OBJECT(object)->state;
	OBJECT(object)->state = state_2 + 1u;
}

/* Waits until the enemies are down to the wave's count, then goes on to the next wave. */
void enemy_waves_next(uint16_t object)
{
	uint8_t t1 = 0, next_wave_enemies = 0, wave = 0, state = 0;

	t1 = io_read8(0x1876u);
	next_wave_enemies = OBJECT(object)->enemy_waves.next_wave_enemies;
	if (t1 <= next_wave_enemies)
	{
		wave = OBJECT(object)->enemy_waves.wave;
		OBJECT(object)->enemy_waves.wave = wave + 1u;
		state = OBJECT(object)->state;
		OBJECT(object)->state = state - 1u;
	}
}

/* Once the list has ended, waits until the enemies are down to its last count and goes away. */
void enemy_waves_end(uint16_t object)
{
	uint8_t t1 = 0, end_enemies = 0;

	t1 = io_read8(0x1876u);
	end_enemies = OBJECT(object)->enemy_waves.end_enemies;
	if (t1 <= end_enemies)
		OBJECT(object)->flags = 0u;
}
