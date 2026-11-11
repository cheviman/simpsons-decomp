/**
 *    Name:        video/sprites.c
 *    Description: the sprite engine: the objects' animations, their moves, the depth sort and their sprites
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    11-11-2026
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
	io_write8(board_control_register, control);
	animate_objects();
	move_objects();
	sort_objects_by_depth();
	control = board_control & ~3u;
	board_control = control;
	io_write8(board_control_register, control);
}

/* Runs the animation of each object that is on and clears the sprites of those that are off. */
void animate_objects(void)
{
	uint8_t slot_flags = 0;
	uint16_t object = 0;
	uint8_t flags = 0;

	object = OBJECT_ADDRESS(0);
	do
	{
		flags = OBJECT(object)->flags;
		slot_flags = flags;
		if (flags == 0u)
			clear_object_sprites(object);
		else if (slot_flags != 1u)
			object = animate_object(object);
		object += 0x60u;
	} while (object != OBJECT_ADDRESS(32));
}

/* Clears the object's sprites in the sprite RAM, and those of the objects that lent it more. */
void clear_object_sprites(uint16_t object)
{
	uint8_t blank_flags = 0, blank_word = 0;
	uint16_t lender = 0, sprite = 0;
	uint8_t slots_left_was = 0;
	uint16_t sprites = 0, next_lender = 0, lender_sprites = 0;
	uint32_t flags_halfword = 0;

	sprites = OBJECT(object)->sprites;
	sprite = sprites;
	clear_slots_left = 8u;
	blank_word = 0u;
	blank_flags = 0u;
	while (SPRITE_ENTRY(sprite)->flags != 0u)
	{
		flags_halfword = (uint32_t)blank_flags << 8;
		SPRITE_ENTRY(sprite)->flags = (uint8_t)(flags_halfword >> 8u);
		SPRITE_ENTRY(sprite)->depth = (uint8_t)flags_halfword;
		sprite += 0x10u;
		slots_left_was = clear_slots_left;
		clear_slots_left = slots_left_was - 1u;
		if (slots_left_was != 1u)
			continue;
		next_lender = SPRITE_ENTRY(sprite - 0x10u)->borrowed_object;
		lender = next_lender;
		if (next_lender == 0u)
			break;
		clear_slots_left = 8u;
		blank_word = 0u;
		blank_flags = 0u;
		SPRITE_ENTRY(sprite - 0x10u)->borrowed_object = 0u;
		OBJECT(lender)->flags = 0u;
		lender_sprites = OBJECT(lender)->sprites;
		sprite = lender_sprites;
	}
}

/* Draws the object's animation when its frame changes, a new animation starts, it is zoomed or asked to;
   otherwise counts its frame's time down. */
uint16_t animate_object(uint16_t object)
{
	uint8_t animation_flags_now = 0;
	uint16_t sprites = 0;
	uint8_t animation = 0, animation_flags = 0, frame_time = 0, frame_time_was = 0, frame_time_2 = 0, frame_time_3 = 0;
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
	animation_flags_now = animation_flags;
	if ((int8_t)animation_flags < 0)
	{
		sprites_3 = OBJECT(object)->sprites;
		sprites = sprites_3;
		frame_time = OBJECT(object)->frame_time;
		if (frame_time == 0u)
			return draw_object(object, sprites);
		object = draw_object(object, sprites);
		frame_time_was = OBJECT(object)->frame_time;
		OBJECT(object)->frame_time = frame_time_was - 1u;
		return object;
	}
	if ((animation_flags_now & 0x40u) != 0u)
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
		frame_time_was = OBJECT(object)->frame_time;
		OBJECT(object)->frame_time = frame_time_was - 1u;
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
	uint8_t x_low = 0, x_slots_left_was = 0, x_speed_3 = 0, x_high = 0, y_low = 0, z_low = 0, sprite_priority = 0, y_slots_left_was = 0, y_speed_3 = 0, y_high = 0, z_speed_3 = 0, z = 0;
	uint16_t shift_x_moving_left = 0, shift_x_moving_right = 0, shift_y_moving_up = 0, shift_y_moving_down = 0, x_speed = 0, screen_step_x = 0, pre_x_and_fraction = 0, sprite_shift_x = 0, sprites = 0, x_shift = 0, old_sprite_x = 0, new_sprite_x = 0, x_lender_found = 0, x_lender_sprites = 0, x_and_fraction = 0, x_speed_2 = 0, x_and_fraction_before = 0, x_and_fraction_after = 0, camera_shift_x = 0, moved_x = 0, shifted_x = 0, y_speed = 0, screen_step_y = 0, pre_y_and_fraction = 0, floor_shift_y = 0, z_speed = 0, pre_z_and_fraction = 0, height_shift = 0, sprite_shift_y = 0, y_shift = 0, sprites_2 = 0, y_shift_now = 0, floor_y_shift = 0, old_sprite_y = 0, new_sprite_y = 0, y_lender_found = 0, y_lender_sprites = 0, y_and_fraction = 0, y_speed_2 = 0, y_and_fraction_before = 0, y_and_fraction_after = 0, camera_shift_y = 0, moved_y = 0, shifted_y = 0, z_speed_2 = 0, z_and_fraction = 0, height_speed = 0, z_and_fraction_after = 0;

	if (camera_x_speed < 0)
	{
		shift_x_moving_left = (int8_t)((uint8_t)last_stage_scroll_x - (uint8_t)camera_x);
		a = (uint8_t)(shift_x_moving_left >> 8);
		b = (uint8_t)shift_x_moving_left;
	}
	else
	{
		shift_x_moving_right = (int8_t)(0u - ((uint8_t)camera_x - (uint8_t)last_stage_scroll_x));
		a = (uint8_t)(shift_x_moving_right >> 8);
		b = (uint8_t)shift_x_moving_right;
	}
	camera_move_x = ((uint32_t)a << 8) | b;
	if (camera_y_speed < 0)
	{
		shift_y_moving_up = (int8_t)(0u - ((uint8_t)last_stage_scroll_y - (uint8_t)camera_y));
		a = (uint8_t)(shift_y_moving_up >> 8);
		b = (uint8_t)shift_y_moving_up;
	}
	else
	{
		shift_y_moving_down = (int8_t)((uint8_t)camera_y - (uint8_t)last_stage_scroll_y);
		a = (uint8_t)(shift_y_moving_down >> 8);
		b = (uint8_t)shift_y_moving_down;
	}
	camera_move_y = ((uint32_t)a << 8) | b;
	object = OBJECT_ADDRESS(0);
	do
	{
		if (OBJECT(object)->flags > 1u)
		{
			x_speed = OBJECT(object)->x_speed;
			screen_step_x = ((uint32_t)(uint8_t)camera_move_x << 8) + x_speed;
			a = (uint8_t)(screen_step_x >> 8);
			b = (uint8_t)screen_step_x;
			if (screen_step_x != 0u)
			{
				pre_x_and_fraction = (((uint32_t)(OBJECT(object)->x & 0xFFu) << 8u) | OBJECT(object)->x_fraction);
				x_low = (uint8_t)OBJECT(object)->x;
				sprite_shift_x = (int8_t)(((uint16_t)((((uint32_t)a << 8) | b) + pre_x_and_fraction) >> 8) - x_low);
				sprite_move = sprite_shift_x;
				move_slots_left = 8u;
				sprites = OBJECT(object)->sprites;
				sprite = sprites;
				while (SPRITE_ENTRY(sprite)->flags != 0u)
				{
					x_shift = sprite_move;
					old_sprite_x = SPRITE_ENTRY(sprite)->x;
					new_sprite_x = x_shift + old_sprite_x;
					SPRITE_ENTRY(sprite)->x = new_sprite_x;
					sprite += 0x10u;
					x_slots_left_was = move_slots_left;
					move_slots_left = x_slots_left_was - 1u;
					if (x_slots_left_was != 1u)
						continue;
					x_lender_found = SPRITE_ENTRY(sprite - 0x10u)->borrowed_object;
					lender = x_lender_found;
					if (x_lender_found == 0u)
						break;
					x_lender_sprites = OBJECT(lender)->sprites;
					sprite = x_lender_sprites;
					move_slots_left = 8u;
				}
			}
			x_and_fraction = (((uint32_t)(OBJECT(object)->x & 0xFFu) << 8u) | OBJECT(object)->x_fraction);
			x_speed_2 = OBJECT(object)->x_speed;
			x_and_fraction_before = x_and_fraction;
			x_and_fraction_after = x_and_fraction_before + x_speed_2;
			carry = (uint16_t)(x_and_fraction_before + x_speed_2) < x_and_fraction_before;
			OBJECT(object)->x = (OBJECT(object)->x & 0xFF00u) | ((x_and_fraction_after >> 8u) & 0xFFu);
			OBJECT(object)->x_fraction = (uint8_t)x_and_fraction_after;
			x_speed_3 = (uint8_t)(OBJECT(object)->x_speed >> 8u);
			x_high = (uint8_t)(OBJECT(object)->x >> 8u);
			OBJECT(object)->x = (OBJECT(object)->x & 0xFFu) | ((((uint16_t)(int8_t)x_speed_3 >> 8) + x_high + carry & 0xFFu) << 8u);
			camera_shift_x = camera_move_x;
			moved_x = OBJECT(object)->x;
			shifted_x = camera_shift_x + moved_x;
			OBJECT(object)->x = shifted_x;
			y_speed = OBJECT(object)->y_speed;
			screen_step_y = ((uint32_t)(uint8_t)camera_move_y << 8) + y_speed;
			pre_y_and_fraction = (((uint32_t)(OBJECT(object)->y & 0xFFu) << 8u) | OBJECT(object)->y_fraction);
			y_low = (uint8_t)OBJECT(object)->y;
			floor_shift_y = (int8_t)(((uint16_t)(screen_step_y + pre_y_and_fraction) >> 8) - y_low);
			shadow_move_y = floor_shift_y;
			z_speed = OBJECT(object)->z_speed;
			pre_z_and_fraction = (((uint32_t)(OBJECT(object)->z & 0xFFu) << 8u) | OBJECT(object)->z_fraction);
			z_low = (uint8_t)OBJECT(object)->z;
			height_shift = (int8_t)(((uint16_t)(z_speed + pre_z_and_fraction) >> 8) - z_low);
			sprite_shift_y = height_shift + shadow_move_y;
			y_shift = sprite_shift_y;
			sprite_move = y_shift;
			if (y_shift != 0u || (OBJECT(object)->flags & 8u) != 0u)
			{
				move_slots_left = 8u;
				sprites_2 = OBJECT(object)->sprites;
				sprite = sprites_2;
				while (SPRITE_ENTRY(sprite)->flags != 0u)
				{
					y_shift_now = sprite_move;
					a = (uint8_t)(y_shift_now >> 8);
					b = (uint8_t)y_shift_now;
					sprite_priority = SPRITE_ENTRY(sprite)->priority;
					if ((int8_t)sprite_priority < 0)
					{
						floor_y_shift = shadow_move_y;
						a = (uint8_t)(floor_y_shift >> 8);
						b = (uint8_t)floor_y_shift;
					}
					old_sprite_y = SPRITE_ENTRY(sprite)->y;
					new_sprite_y = (((uint32_t)a << 8) | b) + old_sprite_y;
					SPRITE_ENTRY(sprite)->y = new_sprite_y;
					sprite += 0x10u;
					y_slots_left_was = move_slots_left;
					move_slots_left = y_slots_left_was - 1u;
					if (y_slots_left_was != 1u)
						continue;
					y_lender_found = SPRITE_ENTRY(sprite - 0x10u)->borrowed_object;
					lender = y_lender_found;
					if (y_lender_found == 0u)
						break;
					y_lender_sprites = OBJECT(lender)->sprites;
					sprite = y_lender_sprites;
					move_slots_left = 8u;
				}
			}
			y_and_fraction = (((uint32_t)(OBJECT(object)->y & 0xFFu) << 8u) | OBJECT(object)->y_fraction);
			y_speed_2 = OBJECT(object)->y_speed;
			y_and_fraction_before = y_and_fraction;
			y_and_fraction_after = y_and_fraction_before + y_speed_2;
			carry = (uint16_t)(y_and_fraction_before + y_speed_2) < y_and_fraction_before;
			OBJECT(object)->y = (OBJECT(object)->y & 0xFF00u) | ((y_and_fraction_after >> 8u) & 0xFFu);
			OBJECT(object)->y_fraction = (uint8_t)y_and_fraction_after;
			y_speed_3 = (uint8_t)(OBJECT(object)->y_speed >> 8u);
			y_high = (uint8_t)(OBJECT(object)->y >> 8u);
			OBJECT(object)->y = (OBJECT(object)->y & 0xFFu) | ((((uint16_t)(int8_t)y_speed_3 >> 8) + y_high + carry & 0xFFu) << 8u);
			camera_shift_y = camera_move_y;
			moved_y = OBJECT(object)->y;
			shifted_y = camera_shift_y + moved_y;
			OBJECT(object)->y = shifted_y;
			z_speed_2 = OBJECT(object)->z_speed;
			a = (uint8_t)(z_speed_2 >> 8);
			b = (uint8_t)z_speed_2;
			if (z_speed_2 != 0u)
			{
				z_and_fraction = (((uint32_t)(OBJECT(object)->z & 0xFFu) << 8u) | OBJECT(object)->z_fraction);
				height_speed = ((uint32_t)a << 8) | b;
				z_and_fraction_after = height_speed + z_and_fraction;
				carry = (uint16_t)(height_speed + z_and_fraction) < height_speed;
				OBJECT(object)->z = (OBJECT(object)->z & 0xFF00u) | ((z_and_fraction_after >> 8u) & 0xFFu);
				OBJECT(object)->z_fraction = (uint8_t)z_and_fraction_after;
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
	uint8_t sort_slots_left_was = 0, rows_left_was = 0;
	uint16_t object_y = 0, object_y_again = 0, row_head = 0, next_drawn = 0, row_at = 0, row_first = 0, row_object_sprites = 0, sort_lender = 0, sort_lender_sprites = 0, next_drawn_read = 0;

	object = OBJECT_ADDRESS(0);
	rows = 0x3000u;
	do
	{
		if (OBJECT(object)->flags > 1u)
		{
			object_y = OBJECT(object)->y;
			a = (uint8_t)(object_y >> 8);
			b = (uint8_t)object_y;
			if ((int16_t)object_y >= 0)
			{
				if ((int16_t)(((uint32_t)a << 8) | b) <= 0x17F)
				{
					object_y_again = OBJECT(object)->y;
					a = (uint8_t)(object_y_again >> 8);
					b = (uint8_t)object_y_again;
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
			row_head = io_read16(rows + (((uint32_t)a << 8) | b));
			last_in_row = row_head;
			if (row_head == 0u)
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
					next_drawn = OBJECT(last_in_row)->draw_next;
					a = (uint8_t)(next_drawn >> 8);
					b = (uint8_t)next_drawn;
				} while (next_drawn != 0u);
				OBJECT(last_in_row)->draw_next = object;
			}
		}
		object += 0x60u;
	} while (object != OBJECT_ADDRESS(32));
	row_place = 0x3000u;
	next_sprite_number = 1u;
	depth_rows_left = 0xC0u;
	do
	{
		row_at = row_place;
		row_place = row_at + 2u;
		row_first = mem_read16(row_at);
		row_object = row_first;
		if (row_first != 0u)
		{
			mem_write16(row_place - 2u, 0u);
			for (;;)
			{
				row_object_sprites = OBJECT(row_object)->sprites;
				sprite = row_object_sprites;
				sort_slots_left = 8u;
				while (SPRITE_ENTRY(sprite)->flags != 0u)
				{
					sprite_order = next_sprite_number;
					if ((int8_t)OBJECT(row_object)->flags >= 0)
						sprite_order = 0u;
					SPRITE_ENTRY(sprite)->depth = sprite_order;
					next_sprite_number++;
					sprite += 0x10u;
					sort_slots_left_was = sort_slots_left;
					sort_slots_left = sort_slots_left_was - 1u;
					if (sort_slots_left_was != 1u)
						continue;
					sort_lender = SPRITE_ENTRY(sprite - 0x10u)->borrowed_object;
					a = (uint8_t)(sort_lender >> 8);
					b = (uint8_t)sort_lender;
					if (sort_lender == 0u)
						break;
					stack_10001 = a;
					stack_10002 = b;
					sort_lender_sprites = io_read16((((uint32_t)stack_10001 << 8) | stack_10002) + 0x59u);
					sprite = sort_lender_sprites;
					sort_slots_left = 8u;
				}
				next_drawn_read = OBJECT(row_object)->draw_next;
				next_in_row = next_drawn_read;
				if (next_drawn_read == 0u)
					break;
				OBJECT(row_object)->draw_next = 0u;
				row_object = next_in_row;
			}
		}
		rows_left_was = depth_rows_left;
		depth_rows_left = rows_left_was - 1u;
	} while (rows_left_was != 1u);
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
	uint8_t animation = 0, frame_flags = 0, frame_time = 0, index = 0, index_high = 0, kind_number = 0;
	uint16_t animations = 0, frame_record = 0, lender = 0, list = 0;
	uint8_t stack = 0, stack_2 = 0;
	uint8_t animation_flags = 0, kind = 0, frame_time_2 = 0, frame = 0, attributes = 0, animation_2 = 0, frame_2 = 0, frame_head = 0, animation_flags_2 = 0, frame_time_3 = 0, animation_flags_3 = 0;
	uint16_t high_set_record = 0, set_record = 0, frame_at = 0, jump_frame_at = 0, next_animation_at = 0, new_frame_at = 0, new_frame_time_at = 0, frame_time_at = 0, lender_found = 0;

	draw_shadow_sprite = 0u;
	sprite_slot = 0u;
	if ((OBJECT(object)->flags & 8u) != 0u)
		draw_shadow_sprite++;
	animation_flags = OBJECT(object)->animation_flags;
	drawn_animation_flags = animation_flags;
	OBJECT(object)->animation_flags = 0u;
	index_high = 0u;
	kind = OBJECT(object)->kind;
	kind_number = kind;
	if ((int8_t)kind < 0)
	{
		kind_number &= 0x7Fu;
		carry = (int8_t)kind_number < 0;
		high_set_record = animation_sets_high_ADDRESS + (((((uint32_t)index_high << 1) | carry) << 8) | (uint8_t)((uint32_t)kind_number << 1));
		window_bank = ANIMATION_SET(high_set_record)->bank;
		set_lines(window_bank);
		index = ANIMATION_SET(high_set_record)->index;
	}
	else
	{
		carry = (int8_t)kind_number < 0;
		set_record = animation_sets_ADDRESS + (((((uint32_t)index_high << 1) | carry) << 8) | (uint8_t)((uint32_t)kind_number << 1));
		window_bank = ANIMATION_SET(set_record)->bank;
		set_lines(window_bank);
		index = ANIMATION_SET(set_record)->index;
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
	index_high = 0u;
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
	frame_at = mem_read16(animations + (((((uint32_t)index_high << 1) | carry) << 8) | (uint8_t)((uint32_t)animation << 1))) + (int8_t)(((uint32_t)frame_2 << 1) << 1);
	frame_record = frame_at + 1u;
	frame_head = mem_read8(frame_at);
	frame_flags = frame_head;
	if ((int8_t)frame_head < 0)
	{
		animation_flags_2 = OBJECT(object)->animation_flags;
		OBJECT(object)->animation_flags = animation_flags_2 | 1u;
		if ((frame_flags & 1u) != 0u)
		{
			jump_frame_at = frame_record;
			OBJECT(object)->frame = mem_read8(jump_frame_at);
			frame_record = mem_read16(jump_frame_at + 1u);
		}
		else
		{
			OBJECT(object)->frame = 0u;
			next_animation_at = frame_record;
			OBJECT(object)->animation = mem_read8(next_animation_at);
			frame_record = mem_read16(next_animation_at + 1u);
		}
		new_frame_at = frame_record;
		frame_flags = mem_read8(new_frame_at);
		frame_marked = frame_flags & 0x10u;
		frame_sprites_left = frame_flags & 0xFu;
		new_frame_time_at = new_frame_at + 1u;
		frame_record = new_frame_time_at + 1u;
		OBJECT(object)->frame_time = io_read8(new_frame_time_at);
	}
	else
	{
		frame_marked = frame_flags & 0x10u;
		frame_sprites_left = frame_flags & 0xFu;
		frame_time_at = frame_record;
		frame_record = frame_time_at + 1u;
		frame_time = mem_read8(frame_time_at);
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
	lender_found = SPRITE_ENTRY(sprites + 0x70u)->borrowed_object;
	lender = lender_found;
	if (lender_found != 0u)
	{
		SPRITE_ENTRY(sprites + 0x70u)->borrowed_object = lender;
		object = ((uint32_t)stack_2 << 8) | stack;
		return write_object_sprites(object, sprites, list);
	}
	borrow_object_for_sprites(&lender, &carry);
	if (carry)
	{
		SPRITE_ENTRY(sprites + 0x70u)->borrowed_object = lender;
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
	uint8_t a = 0, b = 0, zoom_x = 0, zoom_y = 0;
	uint16_t lender = 0, lender_object = 0;
	uint8_t stack = 0, stack_2 = 0, stack_3 = 0, stack_4 = 0, stack_5 = 0, stack_6 = 0;
	uint8_t object_attributes = 0, object_zoom_x = 0, listed_offset_x = 0, object_zoom_y = 0, listed_offset_y = 0, sprites_left_was = 0;
	uint16_t code_at = 0, listed_code = 0, colour_at = 0, size_at = 0, offset_x_at = 0, plain_x = 0, scaled_offset_x = 0, x_before_minus = 0, x_minus_offset = 0, x_before_plus = 0, x_plus_offset = 0, offset_y_at = 0, plain_y = 0, scaled_offset_y = 0, y_before_minus = 0, y_minus_offset = 0, y_before_plus = 0, y_plus_offset = 0, zoomed_object_z = 0, zoomed_sprite_y = 0, plain_offset_x_at = 0, offset_x = 0, object_x = 0, sprite_x = 0, plain_offset_y_at = 0, offset_y = 0, object_y = 0, ground_y = 0, plain_object_z = 0, sprite_y = 0, next_block_object = 0, next_block_sprites = 0, spare_block_object = 0, spare_block_sprites = 0;
	uint32_t priority_halfword = 0, zoomed_product_x = 0, zoomed_product_y = 0;

	do
	{
		sprite_flipped = 0u;
		code_at = list;
		list = code_at + 2u;
		listed_code = mem_read16(code_at);
		a = (uint8_t)(listed_code >> 8);
		b = (uint8_t)listed_code;
		if ((int16_t)listed_code >= 0)
			SPRITE_ENTRY(sprite)->code = ((uint32_t)a << 8) | b;
		else
		{
			SPRITE_ENTRY(sprite)->code = ((a & 0x7Fu) << 8) | b;
			sprite_flipped = 0x10u;
		}
		a = object_sprite_priority;
		object_attributes = OBJECT(object)->attributes;
		b = object_attributes;
		if ((int8_t)object_attributes < 0)
		{
			list++;
			b &= 0xFu;
		}
		else
		{
			colour_at = list;
			list = colour_at + 1u;
			b = mem_read8(colour_at);
		}
		priority_halfword = ((uint32_t)a << 8) | b;
		SPRITE_ENTRY(sprite)->priority = (uint8_t)(priority_halfword >> 8u);
		SPRITE_ENTRY(sprite)->colour = (uint8_t)priority_halfword;
		size_at = list;
		list = size_at + 1u;
		SPRITE_ENTRY(sprite)->flags = (frame_attributes ^ sprite_flipped) | mem_read8(size_at);
		if ((OBJECT(object)->flags & 0x10u) != 0u)
		{
			stack = window_bank;
			SPRITE_ENTRY(sprite)->flags &= 0xBFu;
			object_zoom_x = OBJECT(object)->zoom_x;
			zoom_x = object_zoom_x;
			if (zoom_x < 0x10u)
				zoom_x = 0x10u;
			SPRITE_ENTRY(sprite)->zoom_x = zoom_x;
			zoom_x -= 0x10u;
			zoom_offset_negative = 0u;
			offset_x_at = list;
			list = offset_x_at + 1u;
			listed_offset_x = mem_read8(offset_x_at);
			negative = listed_offset_x >> 7;
			a = listed_offset_x;
			if (listed_offset_x == 0u)
			{
				plain_x = OBJECT(object)->x;
				a = (uint8_t)(plain_x >> 8);
				b = (uint8_t)plain_x;
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
				stack_4 = zoom_x;
				window_bank = 0x1Du;
				set_lines(window_bank);
				b = stack_4;
				carry = (int8_t)b < 0;
				stack_4 = zoom_offset;
				stack_5 = 0u;
				zoomed_product_x = (uint32_t)mem_read16(zoom_steps_address[0] + ((carry << 8) | (uint8_t)((uint32_t)b << 1))) * (uint16_t)(((uint32_t)stack_5 << 8) | stack_4);
				stack_5 = (uint16_t)zoomed_product_x >> 8;
				stack_6 = zoomed_product_x >> 16;
				scaled_offset_x = ((uint32_t)stack_6 << 8) | stack_5;
				zoomed_offset = scaled_offset_x;
				sprite = ((uint32_t)stack_3 << 8) | stack_2;
				object = zoomed_object;
				if (((frame_attributes ^ zoom_offset_negative) & 0x10u) != 0u)
				{
					x_before_minus = OBJECT(object)->x;
					x_minus_offset = x_before_minus - zoomed_offset;
					a = (uint8_t)(x_minus_offset >> 8);
					b = (uint8_t)x_minus_offset;
				}
				else
				{
					x_before_plus = OBJECT(object)->x;
					x_plus_offset = x_before_plus + zoomed_offset;
					a = (uint8_t)(x_plus_offset >> 8);
					b = (uint8_t)x_plus_offset;
				}
			}
			SPRITE_ENTRY(sprite)->x = ((uint32_t)a << 8) | b;
			stack_3 = list >> 8;
			stack_2 = (uint8_t)list;
			window_bank = stack;
			set_lines(window_bank);
			list = ((uint32_t)stack_3 << 8) | stack_2;
			object_zoom_y = OBJECT(object)->zoom_y;
			zoom_y = object_zoom_y;
			if (zoom_y < 0x10u)
				zoom_y = 0x10u;
			SPRITE_ENTRY(sprite)->zoom_y = zoom_y;
			zoom_y -= 0x10u;
			zoom_offset_negative = 0u;
			offset_y_at = list;
			list = offset_y_at + 1u;
			listed_offset_y = mem_read8(offset_y_at);
			negative = listed_offset_y >> 7;
			a = listed_offset_y;
			if (listed_offset_y == 0u)
			{
				plain_y = OBJECT(object)->y;
				a = (uint8_t)(plain_y >> 8);
				b = (uint8_t)plain_y;
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
				stack_4 = zoom_y;
				window_bank = 0x1Du;
				set_lines(window_bank);
				b = stack_4;
				carry = (int8_t)b < 0;
				stack_4 = zoom_offset;
				stack_5 = 0u;
				zoomed_product_y = (uint32_t)mem_read16(zoom_steps_address[0] + ((carry << 8) | (uint8_t)((uint32_t)b << 1))) * (uint16_t)(((uint32_t)stack_5 << 8) | stack_4);
				stack_5 = (uint16_t)zoomed_product_y >> 8;
				stack_6 = zoomed_product_y >> 16;
				scaled_offset_y = ((uint32_t)stack_6 << 8) | stack_5;
				zoomed_offset = scaled_offset_y;
				sprite = ((uint32_t)stack_3 << 8) | stack_2;
				object = zoomed_object;
				if (zoom_offset_negative != 0u)
				{
					y_before_minus = OBJECT(object)->y;
					y_minus_offset = y_before_minus - zoomed_offset;
					a = (uint8_t)(y_minus_offset >> 8);
					b = (uint8_t)y_minus_offset;
				}
				else
				{
					y_before_plus = OBJECT(object)->y;
					y_plus_offset = y_before_plus + zoomed_offset;
					a = (uint8_t)(y_plus_offset >> 8);
					b = (uint8_t)y_plus_offset;
				}
			}
			zoomed_object_z = OBJECT(object)->z;
			zoomed_sprite_y = (((uint32_t)a << 8) | b) + zoomed_object_z;
			SPRITE_ENTRY(sprite)->y = zoomed_sprite_y;
			window_bank = stack;
			set_lines(window_bank);
		}
		else
		{
			plain_offset_x_at = list;
			list = plain_offset_x_at + 1u;
			b = mem_read8(plain_offset_x_at);
			if ((frame_attributes & 0x10u) != 0u)
				b = 0u - b;
			offset_x = (int8_t)b;
			object_x = OBJECT(object)->x;
			sprite_x = offset_x + object_x;
			SPRITE_ENTRY(sprite)->x = sprite_x;
			plain_offset_y_at = list;
			list = plain_offset_y_at + 1u;
			offset_y = (int8_t)mem_read8(plain_offset_y_at);
			object_y = OBJECT(object)->y;
			ground_y = offset_y + object_y;
			plain_object_z = OBJECT(object)->z;
			sprite_y = ground_y + plain_object_z;
			SPRITE_ENTRY(sprite)->y = sprite_y;
			SPRITE_ENTRY(sprite)->zoom_y = 0x40u;
		}
		sprite += 0x10u;
		sprite_slot++;
		if (sprite_slot == 8u)
		{
			next_block_object = SPRITE_ENTRY(sprite - 0x10u)->borrowed_object;
			stack = next_block_object;
			stack_2 = next_block_object >> 8;
			next_block_sprites = io_read16((((uint32_t)stack_2 << 8) | stack) + 0x59u);
			sprite = next_block_sprites;
			sprite_slot = 0u;
		}
		sprites_left_was = frame_sprites_left - 1u;
		frame_sprites_left = sprites_left_was;
	} while ((int8_t)sprites_left_was >= 0);
	OBJECT(object)->flags &= 0xEFu;
	if (draw_shadow_sprite != 0u)
	{
		sprite = write_shadow_sprite(object, sprite);
		sprite_slot++;
	}
	for (;;)
	{
		if (sprite_slot == 8u)
		{
			spare_block_object = SPRITE_ENTRY(sprite - 0x10u)->borrowed_object;
			lender = spare_block_object;
			if (spare_block_object == 0u)
				break;
			SPRITE_ENTRY(sprite - 0x10u)->borrowed_object = 0u;
			lender_object = lender;
			OBJECT(lender_object)->flags = 0u;
			spare_block_sprites = OBJECT(lender_object)->sprites;
			sprite = spare_block_sprites;
			sprite_slot = 0u;
		}
		if (SPRITE_ENTRY(sprite)->flags == 0u)
			break;
		SPRITE_ENTRY(sprite)->flags = 0u;
		SPRITE_ENTRY(sprite)->depth = 0u;
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
	uint8_t attributes = 0, attribute_priority_bits = 0;

	attributes = OBJECT(object)->attributes;
	attribute_priority_bits = attributes & 0x30u;
	priority = attribute_priority_bits;
	if (attribute_priority_bits == 0u)
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
	uint16_t floor_z = 0, shadow_object_y = 0, shadow_y = 0, shadow_x = 0, shadow_record = 0, code = 0;
	uint32_t priority_halfword = 0;

	floor_z = OBJECT(object)->floor_z;
	shadow_object_y = OBJECT(object)->y;
	shadow_y = floor_z + shadow_object_y;
	SPRITE_ENTRY(sprite)->y = shadow_y;
	shadow_x = OBJECT(object)->x;
	SPRITE_ENTRY(sprite)->x = shadow_x;
	shadow_player = OBJECT(object)->shadow_player;
	shadow_record = shadow_sprites_ADDRESS + (uint8_t)(((shadow_player & 0xFu) << 1) << 1);
	shadow_sprite = shadow_record + 1u;
	SPRITE_ENTRY(sprite)->flags = SHADOW_SPRITE(shadow_record)->attributes;
	set_object_priority(object);
	priority_halfword = (object_sprite_priority | 0x80u) << 8;
	SPRITE_ENTRY(sprite)->priority = (uint8_t)(priority_halfword >> 8u);
	SPRITE_ENTRY(sprite)->colour = (uint8_t)priority_halfword;
	code = SHADOW_SPRITE(shadow_sprite - 0x1u)->code;
	SPRITE_ENTRY(sprite)->code = code;
	SPRITE_ENTRY(sprite)->zoom_y = 0x40u;
	sprite += 0x10u;
	return sprite;
}
