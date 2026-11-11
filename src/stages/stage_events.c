/**
 *    Name:        stages/stage_events.c
 *    Description: the stage events: holding the scroll, the waves of enemies
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    11-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the game's 053248 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

/* Puts in one or two of bank 19's list 1 type FB objects (two from difficulty 3), then waits. */
void cleared_wave_start(uint16_t object)
{
	uint32_t carry = 0;
	uint16_t child = 0, ignored16 = 0, ignored16_2 = 0;
	uint8_t state = 0;

	OBJECT(object)->x = 0xE0u;
	leftover_y = cleared_wave_child_1_ADDRESS;
	vector_spawn_child(object, &ignored16, &child, &ignored16_2, &carry);
	if (carry)
		OBJECT(child)->behaviour = object;
	if (difficulty < 3u)
	{
		state = OBJECT(object)->state;
		OBJECT(object)->state = state + 1u;
		cleared_wave_wait(object);
		return;
	}
	leftover_y = cleared_wave_child_2_ADDRESS;
	vector_spawn_child(object, &ignored16, &child, &ignored16_2, &carry);
	if (carry)
		OBJECT(child)->behaviour = object;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
	cleared_wave_wait(object);
}

/* Holds the scroll until no enemy is left, then changes the palette, plays sound 9300 and puts in two
   goons. */
void cleared_wave_wait(uint16_t object)
{
	uint32_t carry = 0;
	uint16_t command = 0, ignored16 = 0, ignored16_2 = 0, ignored16_3 = 0;
	uint8_t enemies_in_play = 0;

	enemies_in_play = io_read8(enemies_present);
	if (enemies_in_play != 0u)
	{
		camera_x_held--;
		return;
	}
	stage_part = 2u;
	command = 0x9300u;
	vector_queue_sound(command);
	OBJECT(object)->flags = 0u;
	leftover_y = cleared_wave_child_3_ADDRESS;
	vector_spawn_child(object, &ignored16, &ignored16_2, &ignored16_3, &carry);
	leftover_y = cleared_wave_child_4_ADDRESS;
	vector_spawn_child(object, &ignored16, &ignored16_2, &ignored16_3, &carry);
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
	uint8_t enemies_in_play = 0, enemies_left = 0;

	enemies_in_play = io_read8(enemies_present);
	enemies_left = OBJECT(object)->scroll_lock.enemies_left;
	if (enemies_left < enemies_in_play)
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
	OBJECT(object)->enemy_waves.end_enemies = enemy_waves_end_enemies[(int8_t)wave];
	wave = (uint32_t)wave << 1;
	OBJECT(object)->enemy_waves.spawns = TABLE16(object_15_spawn_lists, (int8_t)wave);
	OBJECT(object)->enemy_waves.next_wave_enemies = TABLE8(enemy_waves_next_wave_enemies, (uint16_t)((int8_t)((uint32_t)wave << 1) + ((player_count - 1u) & 3u)));
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
}

/* Puts in the spawns of the current wave for which enough players are present. */
void enemy_waves_spawn(uint16_t object)
{
	uint32_t carry = 0;
	uint8_t enemy_z = 0, spawn_flags = 0;
	uint16_t enemy = 0, spawn = 0;
	uint8_t wave = 0, players = 0, players_present_now = 0, flags = 0, spawn_x = 0, spawn_y = 0, z = 0, state_2 = 0;
	uint16_t spawns = 0, state = 0, enemy_x = 0, screen_y = 0, enemy_y = 0;

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
		players_present_now = io_read8(stage_player_count);
		if (players < players_present_now)
		{
			flags = TIMED_SPAWN(spawn)->flags;
			spawn_flags = flags;
			vector_find_free_slot_by_flags(spawn_flags, &enemy, &carry);
			if (carry)
			{
				state = (((uint32_t)TIMED_SPAWN(spawn)->state << 8u) | TIMED_SPAWN(spawn)->type);
				OBJECT(enemy)->parameter = state >> 8;
				OBJECT(enemy)->type = state;
				spawn_x = TIMED_SPAWN(spawn)->x;
				enemy_x = (uint32_t)spawn_x << 3;
				OBJECT(enemy)->x = enemy_x;
				spawn_y = TIMED_SPAWN(spawn)->y;
				screen_y = (uint32_t)spawn_y << 3;
				enemy_y = screen_y + camera_y;
				OBJECT(enemy)->y = enemy_y;
				z = TIMED_SPAWN(spawn)->z;
				enemy_z = z;
				OBJECT(enemy)->z = enemy_z;
				OBJECT(enemy)->floor_z = enemy_z;
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
	uint8_t enemies_in_play = 0, next_wave_enemies = 0, wave = 0, state = 0;

	enemies_in_play = io_read8(enemies_present);
	next_wave_enemies = OBJECT(object)->enemy_waves.next_wave_enemies;
	if (enemies_in_play <= next_wave_enemies)
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
	uint8_t enemies_in_play = 0, end_enemies = 0;

	enemies_in_play = io_read8(enemies_present);
	end_enemies = OBJECT(object)->enemy_waves.end_enemies;
	if (enemies_in_play <= end_enemies)
		OBJECT(object)->flags = 0u;
}
