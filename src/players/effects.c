/**
 *    Name:        players/effects.c
 *    Description: a player's blinking, hit sparks, balloons and voices: the second sprite at +60 and the sounds by character
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    11-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the game's 053248 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

/* Makes the player safe and blinking for 120 frames after it joins, with its mark (its own kind,
   animation 87) above it. */
void player_start_blinking(uint16_t player)
{
	uint8_t attributes = 0, kind = 0;

	attributes = OBJECT(player)->attributes;
	OBJECT(player)->attributes = attributes & 0x4Fu;
	OBJECT(player)->player.blink_frames = 0x78u;
	OBJECT(player + 0x60u)->player.player_state = 0xCu;
	OBJECT(player + 0x60u)->flags = 0x80u;
	kind = OBJECT(player)->kind;
	OBJECT(player + 0x60u)->kind = kind;
	OBJECT(player + 0x60u)->animation = 0x87u;
	OBJECT(player + 0x60u)->attributes = 0u;
	OBJECT(player)->flags = 0xC4u;
}

/* Compares the player's height after its height speed with its floor (above, at or below). */
void player_next_height_against_floor(uint16_t player, uint32_t *p_zero, uint32_t *p_negative, uint32_t *p_overflow)
{
	uint32_t zero = *p_zero;
	uint32_t negative = *p_negative;
	uint32_t overflow = *p_overflow;
	uint32_t carry = 0;
	uint8_t z_speed = 0, z = 0;
	uint16_t z_and_fraction = 0, z_speed_2 = 0, t1 = 0, floor_z = 0, next_z = 0, next_height_above_floor = 0;

	z_speed = (uint8_t)(OBJECT(player)->z_speed >> 8u);
	z_speed_sign = (uint16_t)(int8_t)z_speed >> 8;
	z_and_fraction = (((uint32_t)(OBJECT(player)->z & 0xFFu) << 8u) | OBJECT(player)->z_fraction);
	z_speed_2 = OBJECT(player)->z_speed;
	t1 = z_and_fraction;
	carry = (uint16_t)(t1 + z_speed_2) < t1;
	z = (uint8_t)(OBJECT(player)->z >> 8u);
	floor_z = OBJECT(player)->floor_z;
	next_z = ((uint32_t)(uint8_t)(z + z_speed_sign + carry) << 8) | ((uint16_t)(t1 + z_speed_2) >> 8);
	next_height_above_floor = next_z - floor_z;
	negative = next_height_above_floor >> 15;
	zero = next_height_above_floor == 0u;
	overflow = (uint32_t)(int16_t)next_z - (int16_t)floor_z != (uint32_t)(int16_t)(next_z - floor_z);
	*p_zero = zero;
	*p_negative = negative;
	*p_overflow = overflow;
}

/* Shows or hides the player every other call, safe meanwhile. */
void player_blink(uint16_t player)
{
	OBJECT(player)->flags = (OBJECT(player)->flags | 4u) ^ 0x80u;
}

/* Faces the heavy object it works at (turned left when right of it) with animation B plus 1: the
   in-between case the code meant, animation B itself, never comes (LEAX for LEAY). */
uint16_t player_face_heavy_object(uint16_t player, uint8_t first_animation)
{
	uint8_t animation = 0;
	uint16_t held = 0, left_of_held = 0;
	uint8_t attributes = 0;
	uint16_t held_2 = 0, held_x = 0, player_x = 0, t1 = 0;

	animation = (uint8_t)first_animation;
	held_2 = OBJECT(player)->player.held;
	held = held_2;
	held_x = OBJECT(held)->x;
	left_of_held = held_x - 0x18u;
	player_x = OBJECT(player)->x;
	if ((int16_t)player_x <= (int16_t)left_of_held)
		animation++;
	else
	{
		t1 = OBJECT(player)->x;
		if ((int16_t)left_of_held <= (int16_t)t1)
		{
			attributes = OBJECT(player)->attributes;
			OBJECT(player)->attributes = attributes | 0x40u;
			animation++;
			OBJECT(player)->animation = animation;
			return left_of_held;
		}
	}
	OBJECT(player)->animation = animation;
	return left_of_held;
}

/* The player's hurt voice and a spark where it was hit. */
void player_hurt_voice(uint16_t player)
{
	uint16_t command = 0, ignored16 = 0, ignored16_2 = 0;

	command = 0x3F24u;
	player_play_voice(player, command);
	player_show_hurt_spark(player, &ignored16, &ignored16_2);
}

/* Flashes the player's palette (palette effect 22 plus its character). */
uint16_t player_flash_palette(uint16_t y, uint16_t player)
{
	uint16_t palette = 0, y_2 = 0;
	uint16_t stack = 0;
	uint8_t kind = 0;

	stack = y;
	palette_request_kind = 2u;
	kind = OBJECT(player)->kind;
	palette = (uint8_t)(0x22u + kind);
	vector_palette_request(player, palette);
	y_2 = stack;
	return y_2;
}

/* Marks the player in the air. */
void player_set_in_air(uint16_t player)
{
	OBJECT(player)->flags |= 8u;
}

/* Marks the player on the floor. */
void player_set_on_floor(uint16_t player)
{
	OBJECT(player)->flags &= ~8u;
}

/* No hit, and the player's box back to its body's (0E by 06). */
uint16_t player_reset_box(uint16_t player)
{
	uint16_t box_size = 0;

	OBJECT(player)->damage = 0u;
	OBJECT(player)->attack = 0u;
	OBJECT(player)->box_dx = 0;
	box_size = 0xE06u;
	OBJECT(player)->box_width = 0xEu;
	OBJECT(player)->box_depth = 6u;
	return box_size;
}

/* A spark (kind 0E, animation BF) on the player's side toward its hitter. */
void player_show_hurt_spark(uint16_t player, uint16_t *p_object, uint16_t *p_effect)
{
	uint16_t object = (uint16_t)*p_object;
	uint32_t carry = 0;
	uint16_t effect = 0, effect_state = 0, spark_x = 0;
	uint8_t player_state = 0, box_dz = 0;
	uint16_t hit_by = 0, player_x = 0, hitter_x = 0, player_y = 0, z = 0;

	effect_state = 0x600u;
	effect = 0xEBFu;
	carry = player_start_effect(effect, player, effect_state);
	if (carry == 0u)
	{
		player_state = OBJECT(player + 0x60u)->player.player_state;
		if ((int8_t)((uint16_t)((uint32_t)player_state << 8) >> 8) <= 6)
		{
			hit_by = OBJECT(player)->hit_by;
			object = hit_by;
			player_x = OBJECT(player)->x;
			spark_x = player_x;
			hitter_x = OBJECT(object)->x;
			if ((int16_t)hitter_x <= (int16_t)spark_x)
				spark_x -= 0x10u;
			else
				spark_x += 0x10u;
			OBJECT(player + 0x60u)->x = spark_x;
			box_dz = OBJECT(player)->box_dz;
			player_y = OBJECT(player)->y;
			OBJECT(player + 0x60u)->y = (int8_t)box_dz + player_y - 0x40u;
			z = OBJECT(player)->z;
			OBJECT(player + 0x60u)->z = z + 0x40u;
		}
	}
	*p_object = object;
	*p_effect = effect;
}

/* A spark where the player's blow landed: at the x of the object it hit, at its height plus the byte Y
   points at. */
uint16_t player_show_hit_spark(uint16_t spark_height, uint16_t player)
{
	uint32_t carry = 0;
	uint16_t effect_state = 0, hit_object = 0, kind = 0;
	uint16_t stack = 0;
	uint16_t player_y = 0, z = 0, object_hit = 0, hit_x = 0;

	OBJECT(player)->player.blow_landed = 0u;
	stack = spark_height;
	effect_state = 0x600u;
	kind = 0xEBFu;
	carry = player_start_effect(kind, player, effect_state);
	spark_height = stack;
	if (carry)
		return spark_height;
	player_y = OBJECT(player)->y;
	OBJECT(player + 0x60u)->y = player_y - 0x20u;
	z = OBJECT(player)->z;
	OBJECT(player + 0x60u)->z = mem_read8(spark_height) + z + 0x20u;
	object_hit = OBJECT(player)->player.object_hit;
	hit_object = object_hit;
	hit_x = OBJECT(hit_object)->x;
	OBJECT(player + 0x60u)->x = hit_x;
	return hit_object;
}

/* Shows speech balloon A above the player. */
void player_show_balloon(uint16_t kind, uint16_t player, uint16_t balloon_value)
{
	uint16_t effect_state = 0;

	OBJECT(player + 0x60u)->player.held = (OBJECT(player + 0x60u)->player.held & 0xFF00u) | (balloon_value >> 8 & 0xFFu);
	effect_state = (balloon_value & 0xFFu) | 0x200u;
	player_start_effect(kind, player, effect_state);
}

/* Starts the player's second sprite as effect A (its state in bank 1F) with kind and animation Y, unless
   an effect of a higher number runs (carry). */
uint32_t player_start_effect(uint16_t kind, uint16_t player, uint16_t effect_state)
{
	uint32_t carry = 0;
	uint8_t player_state = 0;
	uint8_t player_state_2 = 0;

	player_state = (uint8_t)(effect_state >> 8);
	player_state_2 = OBJECT(player + 0x60u)->player.player_state;
	if ((int8_t)player_state < (int8_t)player_state_2)
	{
		carry = 1u;
		return carry;
	}
	OBJECT(player + 0x60u)->player.player_state = player_state;
	OBJECT(player + 0x60u)->kind = (uint8_t)(kind >> 8u);
	OBJECT(player + 0x60u)->animation = (uint8_t)kind;
	OBJECT(player + 0x60u)->flags = 0x80u;
	OBJECT(player + 0x60u)->animation_flags = 0u;
	OBJECT(player + 0x60u)->x_speed = 0;
	OBJECT(player + 0x60u)->y_speed = 0;
	carry = 0u;
	OBJECT(player + 0x60u)->z_speed = 0;
	return carry;
}

/* Plays the sound in D for the player's character (its number added to B). */
void player_play_voice(uint16_t player, uint16_t command)
{
	uint8_t kind = 0;

	kind = OBJECT(player)->kind;
	command = (command & ~0xFFu) | (uint8_t)(command + kind);
	vector_queue_sound(command);
}

/* Unused: queues a sound command plus the player's character. */
void unused_player_play_character_sound(uint16_t object, uint16_t command)
{
	uint8_t kind = 0;

	kind = OBJECT(object)->kind;
	command = (command & 0xFFu) | ((uint32_t)(uint8_t)((command >> 8) + kind) << 8);
	vector_queue_sound(command);
}
