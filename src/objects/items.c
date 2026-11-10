/**
 *    Name:        objects/items.c
 *    Description: the items and the food lying in the stages, and who brings them
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    09-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the game's 053248 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

/* Sets up the item its spawn's state picks. */
void item_start(uint16_t object, uint16_t *p_box, uint16_t *p_setup)
{
	uint16_t box = 0, setup = 0;
	uint8_t parameter = 0, state = 0;

	parameter = OBJECT(object)->parameter;
	setup = item_setups[(int8_t)((uint8_t)((uint32_t)parameter << 1)) / 2];
	box = vector_object_setup(object, setup);
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
	item_lie();
	*p_box = box;
	*p_setup = setup;
}

/* Does nothing while the item lies. */
void item_lie(void)
{
}

/* Taken: the item goes away. */
void item_taken(uint16_t object)
{
	OBJECT(object)->flags = 0u;
}

/* Sets food jumping out: its animation, hit kind, gravity and speeds by its spawn's state, away from
   where it came from. */
uint16_t food_jump_out_start(uint16_t object)
{
	uint8_t a = 0;
	uint16_t animation = 0, setup = 0, source = 0;
	uint8_t parameter = 0, t4 = 0, attributes = 0, state = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0, t5 = 0, behaviour = 0, t6 = 0, t7 = 0, x_speed = 0;

	setup = food_jump_out_setup_ADDRESS;
	vector_object_setup(object, setup);
	OBJECT(object)->flags = 0x80u;
	parameter = OBJECT(object)->parameter;
	animation = (((uint32_t)FOOD_MOVE(food_moves_ADDRESS + (uint8_t)((parameter & 3u) << 1) - 0x8u)->animation << 8u) | FOOD_MOVE(food_moves_ADDRESS + (uint8_t)((parameter & 3u) << 1) - 0x8u)->hit_kind);
	t1 = mem_read16(animation);
	OBJECT(object)->animation = (t1 >> 8) | 0x80u;
	OBJECT(object)->attack = t1;
	t2 = io_read16(animation + 2u);
	OBJECT(object)->food_jump_out.bounce_speed = t2;
	t3 = io_read16(animation + 4u);
	OBJECT(object)->x_speed = t3;
	t4 = random_number;
	a = t4 >> 1;
	if ((t4 & 1u) == 0u)
		OBJECT(object)->x_speed = (OBJECT(object)->x_speed & 0xFF00u) | (a & 0xFFu);
	t5 = io_read16(animation + 6u);
	OBJECT(object)->z_speed = t5;
	OBJECT(object)->zoom_x = 0x40u;
	OBJECT(object)->zoom_y = 0x40u;
	attributes = OBJECT(object)->attributes;
	OBJECT(object)->attributes = (attributes & 0xCFu) | 0x10u;
	behaviour = OBJECT(object)->behaviour;
	source = behaviour;
	t6 = OBJECT(source)->x;
	t7 = OBJECT(object)->x;
	if (t6 < t7)
	{
		x_speed = OBJECT(object)->x_speed;
		OBJECT(object)->x_speed = 0u - x_speed;
	}
	OBJECT(object)->food_jump_out.bounces_left = 3u;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
	return source;
}

/* Falls and bounces three times, lower each time, then lies for 64 frames (states 0 and 1 vanish on
   landing). */
void food_jump_out_bounce(uint16_t object)
{
	uint32_t carry = 0;
	uint8_t parameter = 0, bounces_left = 0, bounces_left_2 = 0;
	uint16_t z_speed = 0, bounce_speed = 0, t1 = 0;

	z_speed = OBJECT(object)->z_speed;
	bounce_speed = OBJECT(object)->food_jump_out.bounce_speed;
	t1 = z_speed - bounce_speed;
	OBJECT(object)->z_speed = t1;
	carry = vector_check_landing(object);
	if (carry == 0u)
		return;
	parameter = OBJECT(object)->parameter;
	if (parameter < 2u)
	{
		OBJECT(object)->flags = 0u;
		return;
	}
	OBJECT(object)->flags = 0xC0u;
	bounces_left = OBJECT(object)->food_jump_out.bounces_left;
	OBJECT(object)->food_jump_out.bounces_left = bounces_left - 1u;
	if (bounces_left == 1u)
	{
		OBJECT(object)->x_speed = 0;
		OBJECT(object)->timer = 0x40u;
		OBJECT(object)->state = 5u;
		return;
	}
	bounces_left_2 = OBJECT(object)->food_jump_out.bounces_left;
	OBJECT(object)->z_speed = (OBJECT(object)->z_speed & 0xFFu) | (((uint32_t)bounces_left_2 << 1 & 0xFFu) << 8u);
}

/* When its time runs out uneaten, turns into a puff. */
void food_jump_out_expire(uint16_t object)
{
	uint8_t timer = 0, state = 0;

	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer == 1u)
	{
		OBJECT(object)->kind = 4u;
		OBJECT(object)->animation = 0x80u;
		OBJECT(object)->flags = 0x80u;
		state = OBJECT(object)->state;
		OBJECT(object)->state = state + 1u;
	}
}

/* Takes the puff away when its animation ends. */
void food_jump_out_vanish(uint16_t object)
{
	uint8_t animation_flags = 0;

	animation_flags = OBJECT(object)->animation_flags;
	if (animation_flags & 1u)
		OBJECT(object)->flags = 0u;
}

/* Sets up a piece of food: its animation and hit kind by its spawn's state. */
void food_start(uint16_t object, uint16_t *p_box, uint16_t *p_hit_kinds)
{
	uint16_t box = 0, hit_kinds = 0, setup = 0;
	uint8_t parameter = 0, state = 0;

	setup = food_setup_ADDRESS;
	box = vector_object_setup(object, setup);
	hit_kinds = food_set_hit_kind(object);
	OBJECT(object)->zoom_x = 0x40u;
	OBJECT(object)->zoom_y = 0x40u;
	parameter = OBJECT(object)->parameter;
	OBJECT(object)->animation = parameter | 0x80u;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
	food_lie();
	*p_box = box;
	*p_hit_kinds = hit_kinds;
}

/* Does nothing while the food lies. */
void food_lie(void)
{
}

/* Gives the food the hit kind of its animation (what touching it does). */
uint16_t food_set_hit_kind(uint16_t object)
{
	uint16_t hit_kinds = 0;
	uint8_t parameter = 0;

	hit_kinds = food_hit_kinds_ADDRESS;
	parameter = OBJECT(object)->parameter;
	OBJECT(object)->attack = food_hit_kinds[(parameter & 0x7Fu) >> 1];
	return hit_kinds;
}

/* Eaten: pops up with sound 2401. */
void food_eaten(uint16_t object)
{
	uint32_t carry = 0;
	uint16_t command = 0;
	uint8_t attributes = 0, state = 0;

	attributes = OBJECT(object)->attributes;
	OBJECT(object)->attributes = attributes & 0xBFu;
	OBJECT(object)->flags = 0x80u;
	command = 0x2401u;
	carry = vector_queue_sound(command);
	OBJECT(object)->x_speed = 0;
	OBJECT(object)->y_speed = -0x80;
	OBJECT(object)->z_speed = 0x300;
	OBJECT(object)->timer = 0x20u;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
}

/* Shrinks for 32 frames, then stops. */
void food_eaten_shrink(uint16_t object)
{
	uint8_t timer = 0, state = 0;
	uint16_t zoom_x = 0, t1 = 0;

	OBJECT(object)->flags = 0x90u;
	zoom_x = (((uint32_t)OBJECT(object)->zoom_x << 8u) | OBJECT(object)->zoom_y);
	t1 = zoom_x - 0x101u;
	OBJECT(object)->zoom_x = (uint8_t)(t1 >> 8u);
	OBJECT(object)->zoom_y = (uint8_t)t1;
	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer == 1u)
	{
		OBJECT(object)->timer = 0x10u;
		OBJECT(object)->y_speed = 0;
		OBJECT(object)->z_speed = 0;
		state = OBJECT(object)->state;
		OBJECT(object)->state = state + 1u;
	}
}

/* Vanishes after 16 frames. */
void food_eaten_vanish(uint16_t object)
{
	uint8_t timer = 0;

	OBJECT(object)->flags = 0x90u;
	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer == 1u)
		OBJECT(object)->flags = 0u;
}

/* Sets up dropped food with the animation its spawn's state gives. */
void dropped_food_start(uint16_t object, uint16_t *p_box, uint16_t *p_setup)
{
	uint16_t box = 0, setup = 0;
	uint8_t parameter = 0, state = 0;

	setup = food_setup_ADDRESS;
	box = vector_object_setup(object, setup);
	OBJECT(object)->flags = 0x80u;
	OBJECT(object)->attributes = 0x10u;
	OBJECT(object)->zoom_x = 0x40u;
	OBJECT(object)->zoom_y = 0x40u;
	parameter = OBJECT(object)->parameter;
	OBJECT(object)->animation = parameter | 0x80u;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
	*p_box = box;
	*p_setup = setup;
}

/* Sets up the kind A5 character walking in from the right, with a partner when more than 2 players are
   present. */
void kind_a5_start(uint16_t object, uint16_t *p_y, uint16_t *p_u)
{
	uint32_t carry = 0;
	uint8_t partner_number = 0;
	uint16_t box = 0, hit_kinds = 0, ignored16 = 0, setup = 0;
	uint8_t attributes = 0, t1 = 0, t2 = 0, parameter = 0, t3 = 0, parameter_2 = 0, state = 0;

	setup = kind_a5_setup_ADDRESS;
	box = vector_object_setup(object, setup);
	hit_kinds = food_set_hit_kind(object);
	attributes = OBJECT(object)->attributes;
	OBJECT(object)->attributes = (attributes & 0xCFu) | 0x10u;
	t1 = io_read8(0x187Cu);
	io_write8(0x187Cu, 0u);
	t2 = io_read8(0x187Du);
	io_write8(0x187Du, 0u);
	OBJECT(object)->kind_a5.food_dropped = 0u;
	parameter = OBJECT(object)->parameter;
	partner_number = parameter;
	if ((int8_t)parameter >= 0)
	{
		t3 = io_read8(0x1874u);
		if (t3 > 2u)
		{
			box = kind_a5_partners[partner_number & 3u];
			vector_spawn_child(object, box, &hit_kinds, &ignored16, &carry);
		}
	}
	parameter_2 = OBJECT(object)->parameter;
	OBJECT(object)->animation = ((uint32_t)parameter_2 << 1) | 0x80u;
	OBJECT(object)->timer = 0x40u;
	OBJECT(object)->x_speed = -0x100;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
	face_movement(object);
	*p_y = box;
	*p_u = hit_kinds;
}

/* Walks in for 64 frames and stops, or stops at once when another one has dropped food. */
void kind_a5_walk_in(uint16_t object)
{
	uint8_t timer = 0, t1 = 0, state = 0;

	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer == 1u)
	{
		OBJECT(object)->x_speed = 0;
		OBJECT(object)->state = 5u;
		return;
	}
	t1 = io_read8(0x187Cu);
	if (t1 != 0u)
	{
		state = OBJECT(object)->state;
		OBJECT(object)->state = state + 1u;
	}
}

/* Drops its food (counted in 187C) and shows its dropping animation. */
void kind_a5_drop_food(uint16_t object, uint16_t *p_record, uint16_t *p_food)
{
	uint16_t record = (uint16_t)*p_record;
	uint16_t food = (uint16_t)*p_food;
	uint32_t carry = 0;
	uint16_t ignored16 = 0;
	uint8_t food_dropped = 0, t1 = 0, parameter = 0, state = 0;

	OBJECT(object)->x_speed = 0;
	food_dropped = OBJECT(object)->kind_a5.food_dropped;
	if (food_dropped == 0u)
	{
		OBJECT(object)->timer = 0u;
		OBJECT(object)->state = 5u;
		return;
	}
	t1 = io_read8(0x187Cu);
	io_write8(0x187Cu, t1 + 1u);
	parameter = OBJECT(object)->parameter;
	record = kind_a5_food_drops[(int8_t)((uint8_t)((uint32_t)parameter << 1)) / 2];
	vector_spawn_child(object, record, &food, &ignored16, &carry);
	OBJECT(object)->flags = 0x80u;
	OBJECT(object)->animation = 0x8Au;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
	*p_record = record;
	*p_food = food;
}

/* When the dropping animation ends, walks off, or waits. */
void kind_a5_after_drop(uint16_t object)
{
	uint8_t animation_flags = 0, food_dropped = 0, state = 0;

	animation_flags = OBJECT(object)->animation_flags;
	if ((animation_flags & 1u) == 0u)
	{
		kind_a5_walking();
		return;
	}
	food_dropped = OBJECT(object)->kind_a5.food_dropped;
	if (food_dropped != 0u)
	{
		state = OBJECT(object)->state;
		OBJECT(object)->state = state + 1u;
		OBJECT(object)->animation = 0x88u;
		kind_a5_walk_off(object);
		return;
	}
	OBJECT(object)->state = 6u;
}

/* Walks off (counted in 187D), the first one and the partner going opposite ways. */
void kind_a5_walk_off(uint16_t object)
{
	uint8_t t1 = 0, t2 = 0, parameter = 0, parameter_2 = 0;
	uint16_t x_speed = 0, x_speed_2 = 0;

	OBJECT(object)->x_speed = 0x180;
	t1 = io_read8(0x187Du);
	io_write8(0x187Du, t1 + 1u);
	t2 = io_read8(0x187Du);
	if (t2 == 1u)
	{
		parameter = OBJECT(object)->parameter;
		if ((int8_t)parameter < 0)
		{
			face_movement(object);
			return;
		}
		x_speed = OBJECT(object)->x_speed;
		OBJECT(object)->x_speed = 0u - x_speed;
		face_movement(object);
		return;
	}
	parameter_2 = OBJECT(object)->parameter;
	if ((int8_t)parameter_2 >= 0)
	{
		face_movement(object);
		return;
	}
	x_speed_2 = OBJECT(object)->x_speed;
	OBJECT(object)->x_speed = 0u - x_speed_2;
	face_movement(object);
}

/* Does nothing while it walks. */
void kind_a5_walking(void)
{
}

/* Shows its next animation. */
void kind_a5_turn(uint16_t object)
{
	uint8_t animation = 0, state = 0;

	animation = OBJECT(object)->animation;
	OBJECT(object)->animation = (animation + 1u) | 0x80u;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
}

/* After its wait, walks off. */
void kind_a5_wait(uint16_t object)
{
	uint8_t timer = 0, parameter = 0;

	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer != 1u)
		return;
	parameter = OBJECT(object)->parameter;
	OBJECT(object)->animation = ((uint32_t)parameter << 1) | 0x80u;
	OBJECT(object)->state = 4u;
	kind_a5_walk_off(object);
}

/* Sets up the kind A9 character walking in from the right. */
void kind_a9_start(uint16_t object, uint16_t *p_box, uint16_t *p_setup)
{
	uint16_t box = 0, setup = 0;
	uint8_t state = 0;

	setup = kind_a9_setup_ADDRESS;
	box = vector_object_setup(object, setup);
	OBJECT(object)->x_speed = -0x100;
	OBJECT(object)->timer = 0x40u;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
	face_movement(object);
	*p_box = box;
	*p_setup = setup;
}

/* Walks in for 64 frames and stops. */
void kind_a9_walk_in(uint16_t object)
{
	uint8_t timer = 0;

	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer == 1u)
	{
		OBJECT(object)->x_speed = 0;
		OBJECT(object)->state = 5u;
	}
}

/* Once told to (field 3D), drops its food and shows its dropping animation. */
void kind_a9_drop_food(uint16_t object, uint16_t *p_record, uint16_t *p_food)
{
	uint16_t record = (uint16_t)*p_record;
	uint16_t food = (uint16_t)*p_food;
	uint32_t carry = 0;
	uint16_t ignored16 = 0;
	uint8_t food_dropped = 0, state = 0;

	OBJECT(object)->x_speed = 0;
	food_dropped = OBJECT(object)->kind_a9.food_dropped;
	if (food_dropped == 0u)
		return;
	record = kind_a9_drop_food_child_ADDRESS;
	vector_spawn_child(object, record, &food, &ignored16, &carry);
	OBJECT(object)->flags = 0x80u;
	OBJECT(object)->animation = 0x82u;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
	*p_record = record;
	*p_food = food;
}

/* After the drop, walks off to the left. */
void kind_a9_leave(uint16_t object)
{
	uint8_t timer = 0, state = 0;

	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer != 1u)
	{
		kind_a9_walking();
		return;
	}
	OBJECT(object)->x_speed = -0x200;
	OBJECT(object)->animation = 0x80u;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
	kind_a9_walking();
}

/* Does nothing while it walks. */
void kind_a9_walking(void)
{
}

/* Stops and shows its waiting animation. */
void kind_a9_pause(uint16_t object)
{
	uint8_t state = 0;

	OBJECT(object)->animation = 0x83u;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
}

/* After its wait, walks on to the left. */
void kind_a9_pause_end(uint16_t object)
{
	uint8_t timer = 0;

	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer == 1u)
	{
		OBJECT(object)->animation = 0x81u;
		OBJECT(object)->x_speed = -0x100;
		OBJECT(object)->state = 4u;
	}
}

/* Sets up the item carrier its spawn's state picks, walking in from the right. */
void item_carrier_start(uint16_t object, uint16_t *p_box, uint16_t *p_setup)
{
	uint16_t box = 0, setup = 0;
	uint8_t parameter = 0, state = 0;

	parameter = OBJECT(object)->parameter;
	setup = item_carrier_setups[(int8_t)((uint8_t)((uint32_t)parameter << 1)) / 2];
	box = vector_object_setup(object, setup);
	OBJECT(object)->item_carrier.food_dropped = 0u;
	OBJECT(object)->timer = 0x40u;
	OBJECT(object)->x_speed = -0x100;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
	face_movement(object);
	*p_box = box;
	*p_setup = setup;
}

/* Walks in for 64 frames and stops. */
void item_carrier_walk_in(uint16_t object)
{
	uint8_t timer = 0;

	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer == 1u)
	{
		OBJECT(object)->x_speed = 0;
		OBJECT(object)->state = 5u;
	}
}

/* Puts down its item and shows its putting-down animation (without a free slot it just walks off). */
void item_carrier_put_down(uint16_t object, uint16_t *p_record, uint16_t *p_u)
{
	uint32_t carry = 0;
	uint16_t ignored16 = 0, record = 0, target = 0;
	uint8_t parameter = 0, state = 0;

	OBJECT(object)->x_speed = 0;
	parameter = OBJECT(object)->parameter;
	record = item_carrier_items[(int8_t)((uint8_t)((uint32_t)parameter << 1)) / 2];
	vector_spawn_child(object, record, &target, &ignored16, &carry);
	if (carry == 0u)
	{
		OBJECT(object)->target = 0xFFFFu;
		OBJECT(object)->x_speed = -0x180;
		OBJECT(object)->state = 4u;
	}
	else
	{
		OBJECT(object)->target = target;
		OBJECT(object)->flags = 0x80u;
		OBJECT(object)->animation = 0x84u;
		state = OBJECT(object)->state;
		OBJECT(object)->state = state + 1u;
	}
	*p_record = record;
	*p_u = target;
}

/* When the putting-down animation ends, walks off to the left. */
void item_carrier_leave(uint16_t object)
{
	uint8_t animation_flags = 0, state = 0;

	animation_flags = OBJECT(object)->animation_flags;
	if ((animation_flags & 1u) == 0u)
	{
		item_carrier_walking();
		return;
	}
	OBJECT(object)->animation = 0x80u;
	OBJECT(object)->x_speed = -0x180;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
	item_carrier_walking();
}

/* Does nothing while it walks. */
void item_carrier_walking(void)
{
}

/* Shows its next animation. */
void item_carrier_pause(uint16_t object)
{
	uint8_t animation = 0, state = 0;

	animation = OBJECT(object)->animation;
	OBJECT(object)->animation = (animation + 1u) | 0x80u;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
}

/* After its wait, walks on to the left. */
void item_carrier_pause_end(uint16_t object)
{
	uint8_t timer = 0;

	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer == 1u)
	{
		OBJECT(object)->animation = 0x81u;
		OBJECT(object)->x_speed = -0x100;
		OBJECT(object)->state = 4u;
	}
}

/* Sets up the item a carrier puts down, with the kind its spawn's state picks. */
uint16_t carried_item_start(uint16_t object)
{
	uint16_t kinds = 0, setup = 0;
	uint8_t parameter = 0, state = 0;

	setup = carried_item_setup_ADDRESS;
	vector_object_setup(object, setup);
	OBJECT(object)->animation = 0x80u;
	kinds = carried_item_kinds_ADDRESS;
	parameter = OBJECT(object)->parameter;
	OBJECT(object)->kind = carried_item_kinds[(int8_t)parameter];
	OBJECT(object)->flags = 0x80u;
	OBJECT(object)->zoom_x = 0x40u;
	OBJECT(object)->zoom_y = 0x40u;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
	return kinds;
}

/* Pops up with sound 2401, then shrinks and vanishes like eaten food. */
void carried_item_pop(uint16_t object)
{
	uint32_t carry = 0;
	uint16_t command = 0;
	uint8_t animation = 0, attributes = 0, state = 0;

	animation = OBJECT(object)->animation;
	OBJECT(object)->animation = (animation + 1u) | 0x80u;
	attributes = OBJECT(object)->attributes;
	OBJECT(object)->attributes = attributes & 0xBFu;
	OBJECT(object)->flags = 0x80u;
	command = 0x2401u;
	carry = vector_queue_sound(command);
	OBJECT(object)->x_speed = 0;
	OBJECT(object)->y_speed = -0x80;
	OBJECT(object)->z_speed = 0x100;
	OBJECT(object)->timer = 0x20u;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
}
