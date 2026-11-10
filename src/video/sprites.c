/**
 *    Name:        video/sprites.c
 *    Description: the sprite engine: the objects' animations, their moves, the depth sort and their sprites
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    09-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the game's 053248 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

/* At each IRQ, unless the sprites are frozen: sets the step's sprite priority, then with the sprite RAM
   in view animates every object, moves them and their sprites and orders their sprites by depth. */
void update_sprites(void)
{
	uint8_t control = 0;

	if (objects_frozen != 0u)
		return;
	set_step_sprite_priority();
	control = board_control | 2u;
	board_control = control;
	io_write8(0x1FC2u, control);
	animate_objects();
	move_objects();
	sort_objects_by_depth();
	control = board_control & ~3u;
	board_control = control;
	io_write8(0x1FC2u, control);
}

/* Runs the animation of each object that is on and clears the sprites of those that are off. */
void animate_objects(void)
{
	uint8_t a = 0;
	uint16_t object = 0;
	uint8_t flags = 0;

	object = OBJECT_ADDRESS(0);
	do
	{
		flags = OBJECT(object)->flags;
		a = flags;
		if (flags == 0u)
			clear_object_sprites(object);
		else if (a != 1u)
			object = animate_object(object);
		object += 0x60u;
	} while (object != OBJECT_ADDRESS(32));
}

/* Clears the object's sprites in the sprite RAM, and those of the objects that lent it more. */
void clear_object_sprites(uint16_t object)
{
	uint8_t a = 0, d = 0;
	uint16_t lender = 0, sprite = 0;
	uint8_t t1 = 0;
	uint16_t sprites = 0, t2 = 0, t3 = 0;

	sprites = OBJECT(object)->sprites;
	sprite = sprites;
	clear_slots_left = 8u;
	d = 0u;
	a = 0u;
	while (mem_read8(sprite) != 0u)
	{
		mem_write16(sprite, (uint32_t)a << 8);
		sprite += 0x10u;
		t1 = clear_slots_left;
		clear_slots_left = t1 - 1u;
		if (t1 != 1u)
			continue;
		t2 = mem_read16(sprite - 2u);
		lender = t2;
		if (t2 == 0u)
			break;
		clear_slots_left = 8u;
		d = 0u;
		a = 0u;
		mem_write16(sprite - 2u, 0u);
		mem_write8(lender, 0u);
		t3 = mem_read16(lender + 0x59u);
		sprite = t3;
	}
}

/* Draws the object's animation when its frame changes, a new animation starts, it is zoomed or asked to;
   otherwise counts its frame's time down. */
uint16_t animate_object(uint16_t object)
{
	uint8_t a = 0;
	uint16_t sprites = 0;
	uint8_t animation = 0, animation_flags = 0, frame_time = 0, t1 = 0, frame_time_2 = 0, frame_time_3 = 0;
	uint16_t sprites_2 = 0, sprites_3 = 0;

	animation = OBJECT(object)->animation;
	if ((int8_t)animation < 0)
	{
		sprites_2 = OBJECT(object)->sprites;
		sprites = sprites_2;
		object = draw_object(object, sprites);
		return object;
	}
	animation_flags = OBJECT(object)->animation_flags;
	a = animation_flags;
	if ((int8_t)animation_flags < 0)
	{
		sprites_3 = OBJECT(object)->sprites;
		sprites = sprites_3;
		frame_time = OBJECT(object)->frame_time;
		if (frame_time == 0u)
			return draw_object(object, sprites);
		object = draw_object(object, sprites);
		t1 = mem_read8(object + 8u);
		mem_write8(object + 8u, t1 - 1u);
		return object;
	}
	if ((a & 0x40u) != 0u)
	{
		OBJECT(object)->animation_flags = 0u;
		return object;
	}
	if ((OBJECT(object)->flags & 0x10u) != 0u)
	{
		sprites_3 = OBJECT(object)->sprites;
		sprites = sprites_3;
		frame_time = OBJECT(object)->frame_time;
		if (frame_time == 0u)
			return draw_object(object, sprites);
		object = draw_object(object, sprites);
		t1 = mem_read8(object + 8u);
		mem_write8(object + 8u, t1 - 1u);
		return object;
	}
	frame_time_2 = OBJECT(object)->frame_time;
	if (frame_time_2 != 0u)
	{
		frame_time_3 = OBJECT(object)->frame_time;
		OBJECT(object)->frame_time = frame_time_3 - 1u;
		OBJECT(object)->animation_flags = 0u;
		return object;
	}
	sprites_2 = OBJECT(object)->sprites;
	sprites = sprites_2;
	object = draw_object(object, sprites);
	return object;
}

/* Moves every object that is on by its x, y and z speeds and by the camera's move, and moves its sprites
   with it without drawing them again. */
void move_objects(void)
{
	uint32_t carry = 0;
	uint8_t a = 0, b = 0;
	uint16_t lender = 0, object = 0, sprite = 0;
	uint8_t t7 = 0, t12 = 0, x_speed_3 = 0, t18 = 0, t24 = 0, t27 = 0, t32 = 0, t36 = 0, y_speed_3 = 0, t42 = 0, z_speed_3 = 0, z = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0, t4 = 0, x_speed = 0, t5 = 0, t6 = 0, t8 = 0, sprites = 0, t9 = 0, t10 = 0, t11 = 0, t13 = 0, t14 = 0, t15 = 0, x_speed_2 = 0, t16 = 0, t17 = 0, t19 = 0, t20 = 0, t21 = 0, y_speed = 0, t22 = 0, t23 = 0, t25 = 0, z_speed = 0, t26 = 0, t28 = 0, t29 = 0, t30 = 0, sprites_2 = 0, t31 = 0, t33 = 0, t34 = 0, t35 = 0, t37 = 0, t38 = 0, t39 = 0, y_speed_2 = 0, t40 = 0, t41 = 0, t43 = 0, t44 = 0, t45 = 0, z_speed_2 = 0, t46 = 0, t47 = 0, t48 = 0;

	if (camera_x_speed < 0)
	{
		t1 = (int8_t)((uint8_t)last_stage_scroll_x - (uint8_t)camera_x);
		a = (uint8_t)(t1 >> 8);
		b = (uint8_t)t1;
	}
	else
	{
		t2 = (int8_t)(0u - ((uint8_t)camera_x - (uint8_t)last_stage_scroll_x));
		a = (uint8_t)(t2 >> 8);
		b = (uint8_t)t2;
	}
	camera_move_x = ((uint32_t)a << 8) | b;
	if (camera_y_speed < 0)
	{
		t3 = (int8_t)(0u - ((uint8_t)last_stage_scroll_y - (uint8_t)camera_y));
		a = (uint8_t)(t3 >> 8);
		b = (uint8_t)t3;
	}
	else
	{
		t4 = (int8_t)((uint8_t)camera_y - (uint8_t)last_stage_scroll_y);
		a = (uint8_t)(t4 >> 8);
		b = (uint8_t)t4;
	}
	camera_move_y = ((uint32_t)a << 8) | b;
	object = OBJECT_ADDRESS(0);
	do
	{
		if (OBJECT(object)->flags > 1u)
		{
			x_speed = OBJECT(object)->x_speed;
			t5 = ((uint32_t)(uint8_t)camera_move_x << 8) + x_speed;
			a = (uint8_t)(t5 >> 8);
			b = (uint8_t)t5;
			if (t5 != 0u)
			{
				t6 = (((uint32_t)(OBJECT(object)->x & 0xFFu) << 8u) | OBJECT(object)->x_fraction);
				t7 = (uint8_t)OBJECT(object)->x;
				t8 = (int8_t)(((uint16_t)((((uint32_t)a << 8) | b) + t6) >> 8) - t7);
				sprite_move = t8;
				move_slots_left = 8u;
				sprites = OBJECT(object)->sprites;
				sprite = sprites;
				while (mem_read8(sprite) != 0u)
				{
					t9 = sprite_move;
					t10 = mem_read16(sprite + 6u);
					t11 = t9 + t10;
					mem_write16(sprite + 6u, t11);
					sprite += 0x10u;
					t12 = move_slots_left;
					move_slots_left = t12 - 1u;
					if (t12 != 1u)
						continue;
					t13 = mem_read16(sprite - 2u);
					lender = t13;
					if (t13 == 0u)
						break;
					t14 = mem_read16(lender + 0x59u);
					sprite = t14;
					move_slots_left = 8u;
				}
			}
			t15 = (((uint32_t)(OBJECT(object)->x & 0xFFu) << 8u) | OBJECT(object)->x_fraction);
			x_speed_2 = OBJECT(object)->x_speed;
			t16 = t15;
			t17 = t16 + x_speed_2;
			carry = (uint16_t)(t16 + x_speed_2) < t16;
			OBJECT(object)->x = (OBJECT(object)->x & 0xFF00u) | ((t17 >> 8u) & 0xFFu);
			OBJECT(object)->x_fraction = (uint8_t)t17;
			x_speed_3 = (uint8_t)(OBJECT(object)->x_speed >> 8u);
			t18 = (uint8_t)(OBJECT(object)->x >> 8u);
			OBJECT(object)->x = (OBJECT(object)->x & 0xFFu) | ((((uint16_t)(int8_t)x_speed_3 >> 8) + t18 + carry & 0xFFu) << 8u);
			t19 = camera_move_x;
			t20 = OBJECT(object)->x;
			t21 = t19 + t20;
			OBJECT(object)->x = t21;
			y_speed = OBJECT(object)->y_speed;
			t22 = ((uint32_t)(uint8_t)camera_move_y << 8) + y_speed;
			t23 = (((uint32_t)(OBJECT(object)->y & 0xFFu) << 8u) | OBJECT(object)->y_fraction);
			t24 = (uint8_t)OBJECT(object)->y;
			t25 = (int8_t)(((uint16_t)(t22 + t23) >> 8) - t24);
			shadow_move_y = t25;
			z_speed = OBJECT(object)->z_speed;
			t26 = (((uint32_t)(OBJECT(object)->z & 0xFFu) << 8u) | OBJECT(object)->z_fraction);
			t27 = (uint8_t)OBJECT(object)->z;
			t28 = (int8_t)(((uint16_t)(z_speed + t26) >> 8) - t27);
			t29 = t28 + shadow_move_y;
			t30 = t29;
			sprite_move = t30;
			if (t30 != 0u || (OBJECT(object)->flags & 8u) != 0u)
			{
				move_slots_left = 8u;
				sprites_2 = OBJECT(object)->sprites;
				sprite = sprites_2;
				while (mem_read8(sprite) != 0u)
				{
					t31 = sprite_move;
					a = (uint8_t)(t31 >> 8);
					b = (uint8_t)t31;
					t32 = mem_read8(sprite + 0xCu);
					if ((int8_t)t32 < 0)
					{
						t33 = shadow_move_y;
						a = (uint8_t)(t33 >> 8);
						b = (uint8_t)t33;
					}
					t34 = mem_read16(sprite + 4u);
					t35 = (((uint32_t)a << 8) | b) + t34;
					mem_write16(sprite + 4u, t35);
					sprite += 0x10u;
					t36 = move_slots_left;
					move_slots_left = t36 - 1u;
					if (t36 != 1u)
						continue;
					t37 = mem_read16(sprite - 2u);
					lender = t37;
					if (t37 == 0u)
						break;
					t38 = mem_read16(lender + 0x59u);
					sprite = t38;
					move_slots_left = 8u;
				}
			}
			t39 = (((uint32_t)(OBJECT(object)->y & 0xFFu) << 8u) | OBJECT(object)->y_fraction);
			y_speed_2 = OBJECT(object)->y_speed;
			t40 = t39;
			t41 = t40 + y_speed_2;
			carry = (uint16_t)(t40 + y_speed_2) < t40;
			OBJECT(object)->y = (OBJECT(object)->y & 0xFF00u) | ((t41 >> 8u) & 0xFFu);
			OBJECT(object)->y_fraction = (uint8_t)t41;
			y_speed_3 = (uint8_t)(OBJECT(object)->y_speed >> 8u);
			t42 = (uint8_t)(OBJECT(object)->y >> 8u);
			OBJECT(object)->y = (OBJECT(object)->y & 0xFFu) | ((((uint16_t)(int8_t)y_speed_3 >> 8) + t42 + carry & 0xFFu) << 8u);
			t43 = camera_move_y;
			t44 = OBJECT(object)->y;
			t45 = t43 + t44;
			OBJECT(object)->y = t45;
			z_speed_2 = OBJECT(object)->z_speed;
			a = (uint8_t)(z_speed_2 >> 8);
			b = (uint8_t)z_speed_2;
			if (z_speed_2 != 0u)
			{
				t46 = (((uint32_t)(OBJECT(object)->z & 0xFFu) << 8u) | OBJECT(object)->z_fraction);
				t47 = ((uint32_t)a << 8) | b;
				t48 = t47 + t46;
				carry = (uint16_t)(t47 + t46) < t47;
				OBJECT(object)->z = (OBJECT(object)->z & 0xFF00u) | ((t48 >> 8u) & 0xFFu);
				OBJECT(object)->z_fraction = (uint8_t)t48;
				z_speed_3 = (uint8_t)(OBJECT(object)->z_speed >> 8u);
				z = (uint8_t)(OBJECT(object)->z >> 8u);
				OBJECT(object)->z = (OBJECT(object)->z & 0xFFu) | ((((uint16_t)(int8_t)z_speed_3 >> 8) + z + carry & 0xFFu) << 8u);
			}
		}
		object += 0x60u;
	} while (object != OBJECT_ADDRESS(32));
}

/* Orders the objects by their y, a row of the table at 3000 a line, and numbers their sprites in that
   order for the sprite chip. */
void sort_objects_by_depth(void)
{
	uint8_t a = 0, b = 0, sprite_order = 0;
	uint16_t last_in_row = 0, next_in_row = 0, object = 0, row_object = 0, row_place = 0, rows = 0, sprite = 0;
	uint8_t stack_10001 = 0, stack_10002 = 0;
	uint16_t stack = 0;
	uint8_t t8 = 0, t12 = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, t9 = 0, t10 = 0, t11 = 0;

	object = OBJECT_ADDRESS(0);
	rows = 0x3000u;
	do
	{
		if (OBJECT(object)->flags > 1u)
		{
			t1 = OBJECT(object)->y;
			a = (uint8_t)(t1 >> 8);
			b = (uint8_t)t1;
			if ((int16_t)t1 >= 0)
			{
				if ((int16_t)(((uint32_t)a << 8) | b) <= 0x17F)
				{
					t2 = OBJECT(object)->y;
					a = (uint8_t)(t2 >> 8);
					b = (uint8_t)t2;
				}
				else
				{
					a = 1u;
					b = 0x7Fu;
				}
			}
			else
			{
				a = 0u;
				b = 0u;
			}
			b &= ~1u;
			t3 = io_read16(rows + (((uint32_t)a << 8) | b));
			last_in_row = t3;
			if (t3 == 0u)
				io_write16(rows + (((uint32_t)a << 8) | b), object);
			else
			{
				stack = last_in_row;
				a = (uint8_t)(stack >> 8);
				b = (uint8_t)stack;
				do
				{
					stack_10001 = a;
					stack_10002 = b;
					last_in_row = ((uint32_t)stack_10001 << 8) | stack_10002;
					t4 = io_read16(last_in_row + 0x5Eu);
					a = (uint8_t)(t4 >> 8);
					b = (uint8_t)t4;
				} while (t4 != 0u);
				io_write16(last_in_row + 0x5Eu, object);
			}
		}
		object += 0x60u;
	} while (object != OBJECT_ADDRESS(32));
	row_place = 0x3000u;
	next_sprite_number = 1u;
	depth_rows_left = 0xC0u;
	do
	{
		t5 = row_place;
		row_place = t5 + 2u;
		t6 = mem_read16(t5);
		row_object = t6;
		if (t6 != 0u)
		{
			mem_write16(row_place - 2u, 0u);
			for (;;)
			{
				t7 = mem_read16(row_object + 0x59u);
				sprite = t7;
				sort_slots_left = 8u;
				while (mem_read8(sprite) != 0u)
				{
					sprite_order = next_sprite_number;
					if ((int8_t)mem_read8(row_object) >= 0)
						sprite_order = 0u;
					mem_write8(sprite + 1u, sprite_order);
					next_sprite_number++;
					sprite += 0x10u;
					t8 = sort_slots_left;
					sort_slots_left = t8 - 1u;
					if (t8 != 1u)
						continue;
					t9 = mem_read16(sprite - 2u);
					a = (uint8_t)(t9 >> 8);
					b = (uint8_t)t9;
					if (t9 == 0u)
						break;
					stack_10001 = a;
					stack_10002 = b;
					t10 = io_read16((((uint32_t)stack_10001 << 8) | stack_10002) + 0x59u);
					sprite = t10;
					sort_slots_left = 8u;
				}
				t11 = mem_read16(row_object + 0x5Eu);
				next_in_row = t11;
				if (t11 == 0u)
					break;
				mem_write16(row_object + 0x5Eu, 0u);
				row_object = next_in_row;
			}
		}
		t12 = depth_rows_left;
		depth_rows_left = t12 - 1u;
	} while (t12 != 1u);
}

/* Sets the sprites' default priority for the story's step. */
void set_step_sprite_priority(void)
{
	step_sprite_priority = step_sprite_priorities[(int8_t)game_step];
}

/* Steps the object's animation and writes its frame's sprites (and its shadow's) in the sprite RAM at Y,
   borrowing another object's sprites when it needs more than 8. */
uint16_t draw_object(uint16_t object, uint16_t sprites)
{
	uint32_t carry = 0;
	uint8_t a = 0, animation = 0, frame_flags = 0, frame_time = 0, index = 0, kind_number = 0;
	uint16_t animations = 0, frame_record = 0, lender = 0, list = 0;
	uint8_t stack = 0, stack_2 = 0;
	uint8_t animation_flags = 0, kind = 0, frame_time_2 = 0, frame = 0, attributes = 0, animation_2 = 0, frame_2 = 0, t4 = 0, animation_flags_2 = 0, frame_time_3 = 0, animation_flags_3 = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0, t5 = 0, t6 = 0, t7 = 0, t8 = 0, t9 = 0, t10 = 0;

	draw_shadow_sprite = 0u;
	sprite_slot = 0u;
	if ((OBJECT(object)->flags & 8u) != 0u)
		draw_shadow_sprite++;
	animation_flags = OBJECT(object)->animation_flags;
	drawn_animation_flags = animation_flags;
	OBJECT(object)->animation_flags = 0u;
	a = 0u;
	kind = OBJECT(object)->kind;
	kind_number = kind;
	if ((int8_t)kind < 0)
	{
		kind_number &= 0x7Fu;
		carry = (int8_t)kind_number < 0;
		t1 = animation_sets_high_ADDRESS + (((((uint32_t)a << 1) | carry) << 8) | (uint8_t)((uint32_t)kind_number << 1));
		window_bank = ANIMATION_SET(t1)->bank;
		set_lines(window_bank);
		index = ANIMATION_SET(t1)->index;
	}
	else
	{
		carry = (int8_t)kind_number < 0;
		t2 = animation_sets_ADDRESS + (((((uint32_t)a << 1) | carry) << 8) | (uint8_t)((uint32_t)kind_number << 1));
		window_bank = ANIMATION_SET(t2)->bank;
		set_lines(window_bank);
		index = ANIMATION_SET(t2)->index;
	}
	frame_time_2 = OBJECT(object)->frame_time;
	if (frame_time_2 == 0u)
	{
		frame = OBJECT(object)->frame;
		OBJECT(object)->frame = frame + 1u;
	}
	animations = ANIMATION_SET_INDEX(BANK_WINDOW + index);
	frame_attributes = 0xC0u;
	attributes = OBJECT(object)->attributes;
	if ((attributes & 0x40u) != 0u)
		frame_attributes |= 0x10u;
	a = 0u;
	animation_2 = OBJECT(object)->animation;
	animation = animation_2;
	if ((int8_t)animation_2 < 0)
	{
		OBJECT(object)->frame_time = 0u;
		OBJECT(object)->frame = 0u;
		animation &= 0x7Fu;
		OBJECT(object)->animation = animation;
	}
	carry = (int8_t)animation < 0;
	frame_2 = OBJECT(object)->frame;
	t3 = mem_read16(animations + (((((uint32_t)a << 1) | carry) << 8) | (uint8_t)((uint32_t)animation << 1))) + (int8_t)(((uint32_t)frame_2 << 1) << 1);
	frame_record = t3 + 1u;
	t4 = mem_read8(t3);
	frame_flags = t4;
	if ((int8_t)t4 < 0)
	{
		animation_flags_2 = OBJECT(object)->animation_flags;
		OBJECT(object)->animation_flags = animation_flags_2 | 1u;
		if ((frame_flags & 1u) != 0u)
		{
			t5 = frame_record;
			OBJECT(object)->frame = mem_read8(t5);
			frame_record = mem_read16(t5 + 1u);
		}
		else
		{
			OBJECT(object)->frame = 0u;
			t6 = frame_record;
			OBJECT(object)->animation = mem_read8(t6);
			frame_record = mem_read16(t6 + 1u);
		}
		t7 = frame_record;
		frame_flags = mem_read8(t7);
		frame_marked = frame_flags & 0x10u;
		frame_sprites_left = frame_flags & 0xFu;
		t8 = t7 + 1u;
		frame_record = t8 + 1u;
		OBJECT(object)->frame_time = io_read8(t8);
	}
	else
	{
		frame_marked = frame_flags & 0x10u;
		frame_sprites_left = frame_flags & 0xFu;
		t9 = frame_record;
		frame_record = t9 + 1u;
		frame_time = mem_read8(t9);
		frame_time_3 = OBJECT(object)->frame_time;
		if (frame_time_3 == 0u)
			OBJECT(object)->frame_time = frame_time;
	}
	if (frame_marked != 0u)
	{
		animation_flags_3 = OBJECT(object)->animation_flags;
		OBJECT(object)->animation_flags = animation_flags_3 | 2u;
	}
	list = mem_read16(frame_record);
	set_object_priority(object);
	sprite_slot = 0u;
	if ((uint8_t)(frame_sprites_left + draw_shadow_sprite) < 8u)
		return write_object_sprites(object, sprites, list);
	stack_2 = object >> 8;
	stack = (uint8_t)object;
	t10 = mem_read16(sprites + 0x7Eu);
	lender = t10;
	if (t10 != 0u)
	{
		mem_write16(sprites + 0x7Eu, lender);
		object = ((uint32_t)stack_2 << 8) | stack;
		return write_object_sprites(object, sprites, list);
	}
	borrow_object_for_sprites(&lender, &carry);
	if (carry)
	{
		mem_write16(sprites + 0x7Eu, lender);
		object = ((uint32_t)stack_2 << 8) | stack;
		return write_object_sprites(object, sprites, list);
	}
	object = ((uint32_t)stack_2 << 8) | stack;
	clear_object_sprites(object);
	return object;
}

/* Not code of its own: where an entry past the end of story 1's actor steps would lead, the middle of
   the sprite writer's loop; the game never goes there. */
void story_1_bart_steps_overrun(void)
{
	lost_stack(0x079C00u);
}

/* Writes the sprites of the frame's list at U for the object into its slots from Y: code, colour,
   attributes and place, zoomed when its flags say, then its shadow, and clears the slots left over. */
uint16_t write_object_sprites(uint16_t object, uint16_t sprite, uint16_t list)
{
	uint32_t negative = 0, carry = 0;
	uint8_t a = 0, b = 0;
	uint16_t lender = 0, lender_object = 0;
	uint8_t stack = 0, stack_2 = 0, stack_3 = 0, stack_4 = 0, stack_5 = 0, stack_6 = 0;
	uint8_t t3 = 0, t6 = 0, t8 = 0, t16 = 0, t18 = 0, t40 = 0;
	uint16_t t1 = 0, t2 = 0, t4 = 0, t5 = 0, t7 = 0, t9 = 0, t11 = 0, t12 = 0, t13 = 0, t14 = 0, t15 = 0, t17 = 0, t19 = 0, t21 = 0, t22 = 0, t23 = 0, t24 = 0, t25 = 0, t26 = 0, t27 = 0, t28 = 0, t29 = 0, t30 = 0, t31 = 0, t32 = 0, t33 = 0, t34 = 0, t35 = 0, t36 = 0, t37 = 0, t38 = 0, t39 = 0, t41 = 0, t42 = 0;
	uint32_t t10 = 0, t20 = 0;

	do
	{
		sprite_flipped = 0u;
		t1 = list;
		list = t1 + 2u;
		t2 = mem_read16(t1);
		a = (uint8_t)(t2 >> 8);
		b = (uint8_t)t2;
		if ((int16_t)t2 >= 0)
			mem_write16(sprite + 2u, ((uint32_t)a << 8) | b);
		else
		{
			mem_write16(sprite + 2u, ((a & 0x7Fu) << 8) | b);
			sprite_flipped = 0x10u;
		}
		a = object_sprite_priority;
		t3 = mem_read8(object + 9u);
		b = t3;
		if ((int8_t)t3 < 0)
		{
			list++;
			b &= 0xFu;
		}
		else
		{
			t4 = list;
			list = t4 + 1u;
			b = mem_read8(t4);
		}
		mem_write16(sprite + 0xCu, ((uint32_t)a << 8) | b);
		t5 = list;
		list = t5 + 1u;
		mem_write8(sprite, (frame_attributes ^ sprite_flipped) | mem_read8(t5));
		if ((mem_read8(object) & 0x10u) != 0u)
		{
			stack = window_bank;
			mem_write8(sprite, mem_read8(sprite) & 0xBFu);
			t6 = mem_read8(object + 0xAu);
			b = t6;
			if (b < 0x10u)
				b = 0x10u;
			mem_write8(sprite + 0xBu, b);
			b -= 0x10u;
			zoom_offset_negative = 0u;
			t7 = list;
			list = t7 + 1u;
			t8 = mem_read8(t7);
			negative = t8 >> 7;
			a = t8;
			if (t8 == 0u)
			{
				t9 = mem_read16(object + 0xCu);
				a = (uint8_t)(t9 >> 8);
				b = (uint8_t)t9;
			}
			else
			{
				if (negative)
				{
					a = 0u - a;
					zoom_offset_negative--;
				}
				zoom_offset = a;
				zoomed_object = object;
				stack_3 = sprite >> 8;
				stack_2 = (uint8_t)sprite;
				stack_4 = b;
				window_bank = 0x1Du;
				set_lines(window_bank);
				b = stack_4;
				carry = (int8_t)b < 0;
				stack_4 = zoom_offset;
				stack_5 = 0u;
				t10 = (uint32_t)mem_read16(zoom_steps_address[0] + ((carry << 8) | (uint8_t)((uint32_t)b << 1))) * (uint16_t)(((uint32_t)stack_5 << 8) | stack_4);
				stack_5 = (uint16_t)t10 >> 8;
				stack_6 = t10 >> 16;
				t11 = ((uint32_t)stack_6 << 8) | stack_5;
				zoomed_offset = t11;
				sprite = ((uint32_t)stack_3 << 8) | stack_2;
				object = zoomed_object;
				if (((frame_attributes ^ zoom_offset_negative) & 0x10u) != 0u)
				{
					t12 = io_read16(object + 0xCu);
					t13 = t12 - zoomed_offset;
					a = (uint8_t)(t13 >> 8);
					b = (uint8_t)t13;
				}
				else
				{
					t14 = io_read16(object + 0xCu);
					t15 = t14 + zoomed_offset;
					a = (uint8_t)(t15 >> 8);
					b = (uint8_t)t15;
				}
			}
			mem_write16(sprite + 6u, ((uint32_t)a << 8) | b);
			stack_3 = list >> 8;
			stack_2 = (uint8_t)list;
			window_bank = stack;
			set_lines(window_bank);
			list = ((uint32_t)stack_3 << 8) | stack_2;
			t16 = mem_read8(object + 0xBu);
			b = t16;
			if (b < 0x10u)
				b = 0x10u;
			mem_write8(sprite + 9u, b);
			b -= 0x10u;
			zoom_offset_negative = 0u;
			t17 = list;
			list = t17 + 1u;
			t18 = mem_read8(t17);
			negative = t18 >> 7;
			a = t18;
			if (t18 == 0u)
			{
				t19 = mem_read16(object + 0x11u);
				a = (uint8_t)(t19 >> 8);
				b = (uint8_t)t19;
			}
			else
			{
				if (negative)
				{
					a = 0u - a;
					zoom_offset_negative--;
				}
				zoom_offset = a;
				zoomed_object = object;
				stack_3 = sprite >> 8;
				stack_2 = (uint8_t)sprite;
				stack_4 = b;
				window_bank = 0x1Du;
				set_lines(window_bank);
				b = stack_4;
				carry = (int8_t)b < 0;
				stack_4 = zoom_offset;
				stack_5 = 0u;
				t20 = (uint32_t)mem_read16(zoom_steps_address[0] + ((carry << 8) | (uint8_t)((uint32_t)b << 1))) * (uint16_t)(((uint32_t)stack_5 << 8) | stack_4);
				stack_5 = (uint16_t)t20 >> 8;
				stack_6 = t20 >> 16;
				t21 = ((uint32_t)stack_6 << 8) | stack_5;
				zoomed_offset = t21;
				sprite = ((uint32_t)stack_3 << 8) | stack_2;
				object = zoomed_object;
				if (zoom_offset_negative != 0u)
				{
					t22 = io_read16(object + 0x11u);
					t23 = t22 - zoomed_offset;
					a = (uint8_t)(t23 >> 8);
					b = (uint8_t)t23;
				}
				else
				{
					t24 = io_read16(object + 0x11u);
					t25 = t24 + zoomed_offset;
					a = (uint8_t)(t25 >> 8);
					b = (uint8_t)t25;
				}
			}
			t26 = mem_read16(object + 0x16u);
			t27 = (((uint32_t)a << 8) | b) + t26;
			mem_write16(sprite + 4u, t27);
			window_bank = stack;
			set_lines(window_bank);
		}
		else
		{
			t28 = list;
			list = t28 + 1u;
			b = mem_read8(t28);
			if ((frame_attributes & 0x10u) != 0u)
				b = 0u - b;
			t29 = (int8_t)b;
			t30 = mem_read16(object + 0xCu);
			t31 = t29 + t30;
			mem_write16(sprite + 6u, t31);
			t32 = list;
			list = t32 + 1u;
			t33 = (int8_t)mem_read8(t32);
			t34 = mem_read16(object + 0x11u);
			t35 = t33 + t34;
			t36 = mem_read16(object + 0x16u);
			t37 = t35 + t36;
			mem_write16(sprite + 4u, t37);
			mem_write8(sprite + 9u, 0x40u);
		}
		sprite += 0x10u;
		sprite_slot++;
		if (sprite_slot == 8u)
		{
			t38 = mem_read16(sprite - 2u);
			stack = t38;
			stack_2 = t38 >> 8;
			t39 = io_read16((((uint32_t)stack_2 << 8) | stack) + 0x59u);
			sprite = t39;
			sprite_slot = 0u;
		}
		t40 = frame_sprites_left - 1u;
		frame_sprites_left = t40;
	} while ((int8_t)t40 >= 0);
	mem_write8(object, mem_read8(object) & 0xEFu);
	if (draw_shadow_sprite != 0u)
	{
		sprite = write_shadow_sprite(object, sprite);
		sprite_slot++;
	}
	for (;;)
	{
		if (sprite_slot == 8u)
		{
			t41 = mem_read16(sprite - 2u);
			lender = t41;
			if (t41 == 0u)
				break;
			mem_write16(sprite - 2u, 0u);
			lender_object = lender;
			mem_write8(lender_object, 0u);
			t42 = mem_read16(lender_object + 0x59u);
			sprite = t42;
			sprite_slot = 0u;
		}
		if (mem_read8(sprite) == 0u)
			break;
		mem_write16(sprite, 0u);
		sprite += 0x10u;
		sprite_slot++;
	}
	return object;
}

/* Takes the last free object of the lists (from 55E0 down) to lend its sprites (flags 1); carry and X
   when there was one. */
void borrow_object_for_sprites(uint16_t *p_object, uint32_t *p_carry)
{
	uint32_t carry = *p_carry;
	uint16_t object = 0;

	object = OBJECT_ADDRESS(31);
	for (;;)
	{
		if (OBJECT(object)->flags == 0u)
		{
			OBJECT(object)->flags = 1u;
			carry = 1u;
			break;
		}
		object -= 0x60u;
		if (object == OBJECT_ADDRESS(8))
		{
			carry = 0u;
			break;
		}
	}
	*p_object = object;
	*p_carry = carry;
}

/* Sets the priority the object's sprites get against the layers: its attributes' bits 4-5, or the step's
   default. */
void set_object_priority(uint16_t object)
{
	uint8_t priority = 0;
	uint8_t attributes = 0, t1 = 0;

	attributes = OBJECT(object)->attributes;
	t1 = attributes & 0x30u;
	priority = t1;
	if (t1 == 0u)
	{
		object_sprite_priority = step_sprite_priority;
		return;
	}
	priority = (priority >> 1) >> 1;
	object_sprite_priority = priority;
	object_sprite_priority |= (priority >> 1) >> 1;
}

/* Writes the object's shadow as a sprite at Y: the shadow_sprites entry its field shadow_player names,
   on the floor under it. */
uint16_t write_shadow_sprite(uint16_t object, uint16_t sprite)
{
	uint16_t shadow_sprite = 0;
	uint8_t shadow_player = 0;
	uint16_t floor_z = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, code = 0;

	floor_z = OBJECT(object)->floor_z;
	t1 = OBJECT(object)->y;
	t2 = floor_z + t1;
	mem_write16(sprite + 4u, t2);
	t3 = OBJECT(object)->x;
	mem_write16(sprite + 6u, t3);
	shadow_player = OBJECT(object)->shadow_player;
	t4 = shadow_sprites_ADDRESS + (uint8_t)(((shadow_player & 0xFu) << 1) << 1);
	shadow_sprite = t4 + 1u;
	mem_write8(sprite, SHADOW_SPRITE(t4)->attributes);
	set_object_priority(object);
	mem_write16(sprite + 0xCu, (object_sprite_priority | 0x80u) << 8);
	code = SHADOW_SPRITE(shadow_sprite - 0x1u)->code;
	mem_write16(sprite + 2u, code);
	mem_write8(sprite + 9u, 0x40u);
	sprite += 0x10u;
	return sprite;
}
