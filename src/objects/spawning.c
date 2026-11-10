/**
 *    Name:        objects/spawning.c
 *    Description: the stage's spawns by the scroll, the free-slot search, child objects, the enemy limit
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    09-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the game's 053248 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

/* At a stage's start: points the spawns at the scene's spawn list, puts in the spawns already due, and
   runs the four object lists once. */
uint32_t start_stage_objects(uint16_t y, uint32_t left_caller)
{
	uint16_t ignored16 = 0, ignored16_2 = 0;
	uint8_t t1 = 0;

	io_write16(0x1872u, OBJECT_ADDRESS(0));
	t1 = io_read8(0x1876u);
	io_write8(0x1876u, 0u);
	window_bank = 0x1Bu;
	set_lines(window_bank);
	spawn_next = mem_read16(spawn_list_places[(int8_t)((uint8_t)((uint32_t)scene << 1)) / 2]);
	spawn_stage_objects();
	left_caller = run_enemies(y, left_caller);
	run_list_1_objects(&ignored16, &ignored16_2, &left_caller);
	run_child_objects(ignored16_2);
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
	uint8_t flags = 0, level = 0, flags_2 = 0, kind = 0, state = 0, flags_3 = 0, t12 = 0, depth = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, t8 = 0, t9 = 0, t10 = 0, t11 = 0, t13 = 0, t14 = 0, t15 = 0, t16 = 0, t17 = 0;

	enemy_speed = enemy_speeds_by_rank[(int8_t)rank];
	t1 = (uint32_t)enemy_speed << 1;
	carry = 0u;
	io_write16(0x1886u, t1);
	io_write8(0x1874u, player_count);
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
			t2 = camera_x;
			t3 = t2 + 0x150u;
			if (t3 < SPAWN(spawn)->x)
				break;
		}
		else
		{
			t4 = cemetery_scroll;
			t5 = SPAWN(spawn)->x;
			t6 = t4;
			carry = t6 < t5;
			if (t6 < t5)
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
		t7 = SPAWN(spawn)->x;
		t8 = t7 - camera_x;
		t9 = t8 + 0x40u;
		OBJECT(spawned)->x = t9;
		flags_3 = SPAWN(spawn)->flags;
		if ((int8_t)flags_3 < 0)
		{
			t10 = OBJECT(spawned)->x;
			t11 = t10 - 0x160u;
			OBJECT(spawned)->x = t11;
		}
		OBJECT(spawned)->x_fraction = 0u;
		t12 = SPAWN(spawn)->y;
		t13 = (int8_t)t12;
		t14 = (uint32_t)t13 << 3;
		t15 = 0u - t14;
		t16 = t15 + camera_y;
		t17 = t16 + 0x190u;
		OBJECT(spawned)->y = t17;
		OBJECT(spawned)->y_fraction = 0u;
		depth = SPAWN(spawn)->depth;
		spawn_height = depth;
		OBJECT(spawned)->z = spawn_height;
		OBJECT(spawned)->z_fraction = 0u;
		OBJECT(spawned)->floor_z = spawn_height;
		OBJECT(spawned)->unk_3D = 0u;
		OBJECT(spawned)->blocked = 0u;
		spawn_next = spawn + 8u;
	}
}

/* Takes a free object in the list a spawn's flags name (bits 2-3). */
void take_free_object_for_spawn(uint16_t spawn_flags, uint16_t *p_slot, uint32_t *p_carry)
{
	uint32_t carry = *p_carry;
	uint16_t slot = 0;

	spawn_flags = ((spawn_flags & 0xCu) >> 1) >> 1;
	*p_slot = slot;
	take_free_object(p_slot, &spawn_flags, &carry);
	*p_carry = carry;
}

/* Finds the first free object of an object list (0 enemies, 1, 2 child objects, 3 the stage's event),
   clears it but for its sprite RAM place and marks it taken (carry set); carry clear when the list is
   full. */
void take_free_object(uint16_t *p_slot, uint16_t *p_list_number, uint32_t *p_carry)
{
	uint8_t list_number = (uint8_t)*p_list_number;
	uint32_t carry = *p_carry;
	uint8_t fill = 0, fill_2 = 0, list_index = 0, slots_left = 0, sprite_place_high = 0;
	uint16_t clear_place = 0, d = 0, slot = 0, words_left = 0;
	uint16_t stack = 0;
	uint8_t t1 = 0;
	uint16_t t2 = 0, t3 = 0;

	list_index = (uint8_t)list_number;
	slots_left = object_list_sizes[(int8_t)list_index];
	slot = object_lists[(int8_t)((uint8_t)((uint32_t)list_index << 1)) / 2];
	for (;;)
	{
		if (mem_read8(slot) != 0u)
		{
			slot += 0x60u;
			t1 = slots_left;
			slots_left = t1 - 1u;
			if (t1 != 1u)
				continue;
			carry = 0u;
			d = (uint32_t)slots_left << 8;
			break;
		}
		t2 = mem_read16(slot + 0x59u);
		free_slot_sprites = t2;
		stack = slot;
		fill_2 = 0u;
		fill = 0u;
		clear_place = slot;
		words_left = 0x30u;
		while (words_left != 0u)
		{
			mem_write8(clear_place, fill_2);
			mem_write8(clear_place + 1u, fill);
			clear_place += 2u;
			words_left--;
		}
		slot = stack;
		t3 = free_slot_sprites;
		sprite_place_high = (uint8_t)(t3 >> 8);
		mem_write16(slot + 0x59u, ((uint32_t)sprite_place_high << 8) | (uint8_t)t3);
		mem_write8(slot, 4u);
		carry = 1u;
		d = ((uint32_t)sprite_place_high << 8) | 0xFBu;
		break;
	}
	*p_slot = slot;
	*p_list_number = d;
	*p_carry = carry;
}

/* Puts in a child object a record describes (child_object: its list, state and type) at an offset from
   the object. */
void spawn_child_object(uint16_t object, uint16_t record, uint16_t *p_child, uint16_t *p_d, uint32_t *p_carry)
{
	uint32_t carry = *p_carry;
	uint8_t child_type = 0;
	uint16_t child = 0, d = 0;
	uint8_t list = 0;
	uint16_t state = 0;

	list = CHILD_OBJECT(record)->list;
	d = list;
	take_free_object(&child, &d, &carry);
	if (carry)
	{
		state = (((uint32_t)CHILD_OBJECT(record)->state << 8u) | CHILD_OBJECT(record)->type);
		child_type = (uint8_t)state;
		OBJECT(child)->parameter = ((state & ~0xFFu) | child_type) >> 8;
		OBJECT(child)->type = child_type;
		place_child_object(object, record, child, &d, &carry);
	}
	*p_child = child;
	*p_d = d;
	*p_carry = carry;
}

/* Places a new child object at the record's offset from its parent (the x offset mirrored, and the child
   turned, when the parent faces left), keeping the parent in it. */
void place_child_object(uint16_t object, uint16_t record, uint16_t child, uint16_t *p_d, uint32_t *p_carry)
{
	uint32_t carry = *p_carry;
	uint8_t child_z_high = 0, child_z_low = 0;
	uint16_t d = 0;
	uint8_t attributes = 0, attributes_2 = 0, dz = 0;
	uint16_t dx = 0, t1 = 0, t2 = 0, t3 = 0, dy = 0, t4 = 0, t5 = 0, z = 0, t6 = 0;

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
	t1 = child_dx;
	t2 = OBJECT(object)->x;
	t3 = t1 + t2;
	OBJECT(child)->x = t3;
	dy = CHILD_OBJECT(record)->dy;
	t4 = OBJECT(object)->y;
	t5 = dy + t4;
	OBJECT(child)->y = t5;
	dz = CHILD_OBJECT(record)->dz;
	z = OBJECT(object)->z;
	t6 = dz + z;
	child_z_high = (uint8_t)(t6 >> 8);
	child_z_low = (uint8_t)t6;
	OBJECT(child)->z = ((uint32_t)child_z_high << 8) | child_z_low;
	OBJECT(child)->unk_3D = 0u;
	carry = 1u;
	d = ((uint32_t)(uint8_t)~child_z_high << 8) | child_z_low;
	*p_d = d;
	*p_carry = carry;
}

/* Works out how many enemies the stage holds at most (by the difficulty and the scene, in the cemetery
   by the players) and whether there are more (carry set); in most scenes holding the camera's x scroll
   while there are; with a hold flag set (one nothing writes), holds both scrolls instead. */
uint32_t check_enemy_limit(uint32_t carry)
{
	uint8_t limit = 0;
	uint16_t enemy_limit = 0;
	uint8_t t1 = 0, t2 = 0;

	if (in_cemetery != 0u)
	{
		limit = cemetery_enemy_limits_by_players[(int8_t)player_count];
		io_write8(0x1885u, limit);
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
	t1 = io_read8(0x189Cu);
	if (t1 != 0u)
	{
		camera_x_held = 1u;
		camera_y_held = 1u;
		return carry;
	}
	io_write8(0x1885u, enemy_limits_by_difficulty[(int8_t)difficulty]);
	t2 = io_read8(0x1885u);
	limit = extra_enemies_by_scene[(int8_t)scene] + t2;
	io_write8(0x1885u, limit);
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
	uint32_t carry = 0;
	uint8_t held = 0;
	uint8_t t1 = 0, t2 = 0;

	held = 0u;
	t1 = io_read8(0x1876u);
	t2 = enemy_limit >> 8;
	carry = t2 < t1;
	if (t2 < t1)
		held--;
	camera_x_held = held;
	return carry;
}

/* Whether there are more enemies than the limit (carry set), without touching the scroll. */
uint32_t compare_enemy_limit(uint16_t enemy_limit)
{
	uint32_t carry = 0;
	uint8_t t1 = 0;

	t1 = io_read8(0x1876u);
	carry = enemy_limit >> 8 < t1;
	return carry;
}
