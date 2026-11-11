/**
 *    Name:        objects/spawning.c
 *    Description: the stage's spawns by the scroll, the free-slot search, child objects, the enemy limit
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    11-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the game's 053248 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

/* At a stage's start: points the spawns at the scene's spawn list, puts in the spawns already due, and
   runs the four object lists once. */
uint32_t start_stage_objects(uint32_t left_caller)
{
	uint16_t ignored16 = 0;
	uint8_t old_enemy_count = 0;

	io_write16(nearest_player_found, OBJECT_ADDRESS(0));
	old_enemy_count = io_read8(enemies_present);
	io_write8(enemies_present, 0u);
	window_bank = 0x1Bu;
	set_lines(window_bank);
	spawn_next = mem_read16(spawn_list_places[(int8_t)((uint8_t)((uint32_t)scene << 1)) / 2]);
	spawn_stage_objects();
	left_caller = run_enemies(left_caller);
	run_list_1_objects(&ignored16, &left_caller);
	run_child_objects(ignored16);
	run_stage_event();
	return left_caller;
}

/* Puts in every spawn of the scene's list the camera has reached (its x within 336 pixels past the
   camera's, in the cemetery by the climb), unless the stage holds too many enemies: each in a free slot
   of its list, with its type, starting state, place (just off the right edge, or the left with bit 7 of
   its flags), height and floor; spawns above the stage's difficulty are skipped. */
void spawn_stage_objects(void)
{
	uint32_t carry = 0;
	uint8_t enemy_speed = 0, spawn_flags = 0, spawn_height = 0;
	uint16_t spawn = 0, spawned = 0;
	uint8_t flags = 0, level = 0, flags_2 = 0, kind = 0, state = 0, flags_3 = 0, height_steps = 0, depth = 0;
	uint16_t enemies_speed = 0, camera_position = 0, spawn_edge = 0, scroll_position = 0, spawn_place = 0, compared_scroll = 0, spawn_stage_x = 0, camera_offset = 0, spawn_screen_x = 0, placed_x = 0, left_side_x = 0, signed_steps = 0, height_pixels = 0, negated_height = 0, height_on_screen = 0, spawn_y = 0;

	enemy_speed = enemy_speeds_by_rank[(int8_t)rank];
	enemies_speed = (uint32_t)enemy_speed << 1;
	carry = 0u;
	io_write16(enemy_walk_speed, enemies_speed);
	io_write8(stage_player_count, player_count);
	if (in_cemetery != 0u)
	{
		window_bank = 0x1Bu;
		set_lines(window_bank);
	}
	else
	{
		carry = check_enemy_limit(carry);
		if (carry)
			return;
		window_bank = 0x1Bu;
		set_lines(window_bank);
	}
	for (;;)
	{
		spawn = spawn_next;
		if ((uint8_t)(SPAWN(spawn)->x >> 8u) == 0xFFu)
			break;
		if (in_cemetery == 0u)
		{
			camera_position = camera_x;
			spawn_edge = camera_position + 0x150u;
			if (spawn_edge < SPAWN(spawn)->x)
				break;
		}
		else
		{
			scroll_position = cemetery_scroll;
			spawn_place = SPAWN(spawn)->x;
			compared_scroll = scroll_position;
			carry = compared_scroll < spawn_place;
			if (compared_scroll < spawn_place)
				break;
			flags = SPAWN(spawn)->flags;
			if ((flags & 0xCu) == 0u)
			{
				carry = check_enemy_limit(carry);
				if (carry)
				{
					spawn_next = spawn + 8u;
					continue;
				}
			}
		}
		level = SPAWN(spawn)->level;
		if (difficulty < level)
		{
			spawn_next = spawn + 8u;
			continue;
		}
		flags_2 = SPAWN(spawn)->flags;
		spawn_flags = flags_2;
		take_free_object_for_spawn(spawn_flags, &spawned, &carry);
		if (carry == 0u)
		{
			spawn_next = spawn + 8u;
			continue;
		}
		kind = SPAWN(spawn)->kind;
		OBJECT(spawned)->type = kind;
		AT16(OBJECT(spawned)->state, -1) = 0u;
		state = SPAWN(spawn)->state;
		OBJECT(spawned)->parameter = state;
		spawn_stage_x = SPAWN(spawn)->x;
		camera_offset = spawn_stage_x - camera_x;
		spawn_screen_x = camera_offset + 0x40u;
		OBJECT(spawned)->x = spawn_screen_x;
		flags_3 = SPAWN(spawn)->flags;
		if ((int8_t)flags_3 < 0)
		{
			placed_x = OBJECT(spawned)->x;
			left_side_x = placed_x - 0x160u;
			OBJECT(spawned)->x = left_side_x;
		}
		OBJECT(spawned)->x_fraction = 0u;
		height_steps = SPAWN(spawn)->y;
		signed_steps = (int8_t)height_steps;
		height_pixels = (uint32_t)signed_steps << 3;
		negated_height = 0u - height_pixels;
		height_on_screen = negated_height + camera_y;
		spawn_y = height_on_screen + 0x190u;
		OBJECT(spawned)->y = spawn_y;
		OBJECT(spawned)->y_fraction = 0u;
		depth = SPAWN(spawn)->depth;
		spawn_height = depth;
		OBJECT(spawned)->z = spawn_height;
		OBJECT(spawned)->z_fraction = 0u;
		OBJECT(spawned)->floor_z = spawn_height;
		OBJECT(spawned)->carried = 0u;
		OBJECT(spawned)->blocked = 0u;
		spawn_next = spawn + 8u;
	}
}

/* Takes a free object in the list a spawn's flags name (bits 2-3). */
void take_free_object_for_spawn(uint16_t spawn_flags, uint16_t *p_slot, uint32_t *p_slot_found)
{
	uint32_t slot_found = *p_slot_found;
	uint16_t slot = 0;

	spawn_flags = ((spawn_flags & 0xCu) >> 1) >> 1;
	*p_slot = slot;
	take_free_object(p_slot, &spawn_flags, &slot_found);
	*p_slot_found = slot_found;
}

/* Finds the first free object of an object list (0 enemies, 1, 2 child objects, 3 the stage's event),
   clears it but for its sprite RAM place and marks it taken (carry set); carry clear when the list is
   full. */
void take_free_object(uint16_t *p_slot, uint16_t *p_list_number, uint32_t *p_slot_found)
{
	uint8_t list_number = (uint8_t)*p_list_number;
	uint32_t slot_found = *p_slot_found;
	uint8_t fill = 0, fill_2 = 0, list_index = 0, slots_left = 0, sprite_place_high = 0;
	uint16_t clear_place = 0, d = 0, slot_object = 0, words_left = 0;
	uint16_t saved_slot_object = 0;
	uint8_t slots_to_check = 0;
	uint16_t kept_sprites = 0, restored_sprites = 0;

	list_index = (uint8_t)list_number;
	slots_left = object_list_sizes[(int8_t)list_index];
	slot_object = object_lists[(int8_t)((uint8_t)((uint32_t)list_index << 1)) / 2];
	for (;;)
	{
		if (OBJECT(slot_object)->flags != 0u)
		{
			slot_object += 0x60u;
			slots_to_check = slots_left;
			slots_left = slots_to_check - 1u;
			if (slots_to_check != 1u)
				continue;
			slot_found = 0u;
			d = (uint32_t)slots_left << 8;
			break;
		}
		kept_sprites = OBJECT(slot_object)->sprites;
		free_slot_sprites = kept_sprites;
		saved_slot_object = slot_object;
		fill_2 = 0u;
		fill = 0u;
		clear_place = slot_object;
		words_left = 0x30u;
		while (words_left != 0u)
		{
			mem_write8(clear_place, fill_2);
			mem_write8(clear_place + 1u, fill);
			clear_place += 2u;
			words_left--;
		}
		slot_object = saved_slot_object;
		restored_sprites = free_slot_sprites;
		sprite_place_high = (uint8_t)(restored_sprites >> 8);
		OBJECT(slot_object)->sprites = ((uint32_t)sprite_place_high << 8) | (uint8_t)restored_sprites;
		OBJECT(slot_object)->flags = 4u;
		slot_found = 1u;
		d = ((uint32_t)sprite_place_high << 8) | 0xFBu;
		break;
	}
	*p_slot = slot_object;
	*p_list_number = d;
	*p_slot_found = slot_found;
}

/* Puts in a child object a record describes (child_object: its list, state and type) at an offset from
   the object. */
void spawn_child_object(uint16_t object, uint16_t record, uint16_t *p_child, uint16_t *p_list_number, uint32_t *p_slot_found)
{
	uint32_t slot_found = *p_slot_found;
	uint8_t child_type = 0;
	uint16_t child = 0, list_number = 0;
	uint8_t list = 0;
	uint16_t state = 0;

	list = CHILD_OBJECT(record)->list;
	list_number = list;
	take_free_object(&child, &list_number, &slot_found);
	if (slot_found)
	{
		state = (((uint32_t)CHILD_OBJECT(record)->state << 8u) | CHILD_OBJECT(record)->type);
		child_type = (uint8_t)state;
		OBJECT(child)->parameter = ((state & ~0xFFu) | child_type) >> 8;
		OBJECT(child)->type = child_type;
		place_child_object(object, record, child, &list_number, &slot_found);
	}
	*p_child = child;
	*p_list_number = list_number;
	*p_slot_found = slot_found;
}

/* Places a new child object at the record's offset from its parent (the x offset mirrored, and the child
   turned, when the parent faces left), keeping the parent in it. */
void place_child_object(uint16_t object, uint16_t record, uint16_t child, uint16_t *p_d, uint32_t *p_slot_found)
{
	uint32_t slot_found = *p_slot_found;
	uint8_t child_z_high = 0, child_z_low = 0;
	uint16_t d = 0;
	uint8_t attributes = 0, attributes_2 = 0, dz = 0;
	uint16_t dx = 0, offset_from_parent = 0, parent_place_x = 0, child_x = 0, dy = 0, parent_place_y = 0, child_y = 0, z = 0, child_z = 0;

	OBJECT(child)->parent = object;
	AT16(OBJECT(child)->state, -1) = 0u;
	dx = CHILD_OBJECT(record)->dx;
	child_dx = dx;
	attributes = OBJECT(object)->attributes;
	if ((attributes & 0x40u) != 0u)
	{
		attributes_2 = OBJECT(child)->attributes;
		OBJECT(child)->attributes = attributes_2 | 0x40u;
		child_dx = 0u - child_dx;
	}
	offset_from_parent = child_dx;
	parent_place_x = OBJECT(object)->x;
	child_x = offset_from_parent + parent_place_x;
	OBJECT(child)->x = child_x;
	dy = CHILD_OBJECT(record)->dy;
	parent_place_y = OBJECT(object)->y;
	child_y = dy + parent_place_y;
	OBJECT(child)->y = child_y;
	dz = CHILD_OBJECT(record)->dz;
	z = OBJECT(object)->z;
	child_z = dz + z;
	child_z_high = (uint8_t)(child_z >> 8);
	child_z_low = (uint8_t)child_z;
	OBJECT(child)->z = ((uint32_t)child_z_high << 8) | child_z_low;
	OBJECT(child)->carried = 0u;
	slot_found = 1u;
	d = ((uint32_t)(uint8_t)~child_z_high << 8) | child_z_low;
	*p_d = d;
	*p_slot_found = slot_found;
}

/* Works out how many enemies the stage holds at most (by the difficulty and the scene, in the cemetery
   by the players) and whether there are more (carry set); in most scenes holding the camera's x scroll
   while there are; with a hold flag set (one nothing writes), holds both scrolls instead. */
uint32_t check_enemy_limit(uint32_t too_many_enemies)
{
	uint8_t limit = 0;
	uint16_t enemy_limit = 0;
	uint8_t hold_scrolls = 0, difficulty_limit = 0;

	if (in_cemetery != 0u)
	{
		limit = cemetery_enemy_limits_by_players[(int8_t)player_count];
		io_write8(enemies_allowed, limit);
		switch ((int8_t)(uint8_t)((uint32_t)scene << 1))
		{
		case 0:
		case 2:
		case 6:
		case 10:
		case 12:
		case 16:
		case 18:
		case 22:
			enemy_limit = (uint32_t)limit << 8;
			return hold_scroll_over_enemy_limit(enemy_limit);
		case 4:
		case 8:
		case 14:
		case 20:
			enemy_limit = (uint32_t)limit << 8;
			return compare_enemy_limit(enemy_limit);
		}
	}
	hold_scrolls = io_read8(hold_both_scrolls);
	if (hold_scrolls != 0u)
	{
		camera_x_held = 1u;
		camera_y_held = 1u;
		return too_many_enemies;
	}
	io_write8(enemies_allowed, enemy_limits_by_difficulty[(int8_t)difficulty]);
	difficulty_limit = io_read8(enemies_allowed);
	limit = extra_enemies_by_scene[(int8_t)scene] + difficulty_limit;
	io_write8(enemies_allowed, limit);
	switch ((int8_t)(uint8_t)((uint32_t)scene << 1))
	{
	case 0:
	case 2:
	case 6:
	case 10:
	case 12:
	case 16:
	case 18:
	case 22:
		enemy_limit = (uint32_t)limit << 8;
		return hold_scroll_over_enemy_limit(enemy_limit);
	case 4:
	case 8:
	case 14:
	case 20:
		enemy_limit = (uint32_t)limit << 8;
		return compare_enemy_limit(enemy_limit);
	}
	unreachable();
}

/* Holds the camera's x scroll while there are more enemies than the limit (carry set), lets it go
   otherwise. */
uint32_t hold_scroll_over_enemy_limit(uint16_t enemy_limit)
{
	uint32_t too_many_enemies = 0;
	uint8_t held = 0;
	uint8_t enemies = 0, limit_value = 0;

	held = 0u;
	enemies = io_read8(enemies_present);
	limit_value = enemy_limit >> 8;
	too_many_enemies = limit_value < enemies;
	if (limit_value < enemies)
		held--;
	camera_x_held = held;
	return too_many_enemies;
}

/* Whether there are more enemies than the limit (carry set), without touching the scroll. */
uint32_t compare_enemy_limit(uint16_t enemy_limit)
{
	uint32_t too_many_enemies = 0;
	uint8_t enemies = 0;

	enemies = io_read8(enemies_present);
	too_many_enemies = enemy_limit >> 8 < enemies;
	return too_many_enemies;
}
