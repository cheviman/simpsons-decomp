/**
 *    Name:        players/effects.c
 *    Description: a player's blinking, hit sparks, balloons and voices: the second sprite at +60 and the sounds by character
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    09-11-2026
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
	uint16_t t1 = 0, z_speed_2 = 0, t2 = 0, floor_z = 0, t3 = 0, t4 = 0;

	z_speed = (uint8_t)(OBJECT(player)->z_speed >> 8u);
	z_speed_sign = (uint16_t)(int8_t)z_speed >> 8;
	t1 = (((uint32_t)(OBJECT(player)->z & 0xFFu) << 8u) | OBJECT(player)->z_fraction);
	z_speed_2 = OBJECT(player)->z_speed;
	t2 = t1;
	carry = (uint16_t)(t2 + z_speed_2) < t2;
	z = (uint8_t)(OBJECT(player)->z >> 8u);
	floor_z = OBJECT(player)->floor_z;
	t3 = ((uint32_t)(uint8_t)(z + z_speed_sign + carry) << 8) | ((uint16_t)(t2 + z_speed_2) >> 8);
	t4 = t3 - floor_z;
	negative = t4 >> 15;
	zero = t4 == 0u;
	overflow = (uint32_t)(int16_t)t3 - (int16_t)floor_z != (uint32_t)(int16_t)(t3 - floor_z);
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
	uint16_t left_of_held = 0;
	uint8_t attributes = 0;
	uint16_t held = 0, t1 = 0, t2 = 0, t3 = 0;

	animation = (uint8_t)first_animation;
	held = OBJECT(player)->player.held;
	t1 = mem_read16(held + 0xCu);
	left_of_held = t1 - 0x18u;
	t2 = OBJECT(player)->x;
	if ((int16_t)t2 <= (int16_t)left_of_held)
		animation++;
	else
	{
		t3 = OBJECT(player)->x;
		if ((int16_t)left_of_held <= (int16_t)t3)
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
void player_flash_palette(uint16_t player)
{
	uint16_t ignored16 = 0, palette = 0;
	uint8_t kind = 0;

	palette_request_kind = 2u;
	kind = OBJECT(player)->kind;
	palette = (uint8_t)(0x22u + kind);
	vector_palette_request(palette, &ignored16, &player);
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
	uint16_t d = 0, effect = 0, effect_state = 0;
	uint8_t player_state = 0, box_dz = 0;
	uint16_t hit_by = 0, t1 = 0, t2 = 0, t3 = 0, z = 0;

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
			t1 = OBJECT(player)->x;
			d = t1;
			t2 = OBJECT(object)->x;
			if ((int16_t)t2 <= (int16_t)d)
				d -= 0x10u;
			else
				d += 0x10u;
			OBJECT(player + 0x60u)->x = d;
			box_dz = OBJECT(player)->box_dz;
			t3 = OBJECT(player)->y;
			OBJECT(player + 0x60u)->y = (int8_t)box_dz + t3 - 0x40u;
			z = OBJECT(player)->z;
			OBJECT(player + 0x60u)->z = z + 0x40u;
		}
	}
	*p_object = object;
	*p_effect = effect;
}

/* A spark where the player's blow landed: at the x of the object it hit, at its height plus the byte Y
   points at. */
uint16_t player_show_hit_spark(uint16_t y, uint16_t player)
{
	uint32_t carry = 0;
	uint16_t effect_state = 0, kind = 0, y_2 = 0;
	uint16_t stack = 0;
	uint16_t t1 = 0, z = 0, object_hit = 0, t2 = 0;

	OBJECT(player)->player.blow_landed = 0u;
	stack = y;
	effect_state = 0x600u;
	kind = 0xEBFu;
	carry = player_start_effect(kind, player, effect_state);
	y_2 = stack;
	if (carry)
		return y_2;
	t1 = OBJECT(player)->y;
	OBJECT(player + 0x60u)->y = t1 - 0x20u;
	z = OBJECT(player)->z;
	OBJECT(player + 0x60u)->z = mem_read8(y_2) + z + 0x20u;
	object_hit = OBJECT(player)->player.object_hit;
	y_2 = object_hit;
	t2 = mem_read16(y_2 + 0xCu);
	OBJECT(player + 0x60u)->x = t2;
	return y_2;
}

/* Shows speech balloon A above the player. */
void player_show_balloon(uint16_t kind, uint16_t player, uint16_t d)
{
	uint32_t carry = 0;
	uint16_t effect_state = 0;

	OBJECT(player + 0x60u)->player.held = (OBJECT(player + 0x60u)->player.held & 0xFF00u) | (d >> 8 & 0xFFu);
	effect_state = (d & 0xFFu) | 0x200u;
	carry = player_start_effect(kind, player, effect_state);
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
	uint32_t carry = 0;
	uint8_t kind = 0;

	kind = OBJECT(player)->kind;
	command = (command & ~0xFFu) | (uint8_t)(command + kind);
	carry = vector_queue_sound(command);
}

/* Unused: queues a sound command plus the player's character. */
void unused_player_play_character_sound(uint16_t object, uint16_t command)
{
	uint32_t carry = 0;
	uint8_t kind = 0;

	kind = OBJECT(object)->kind;
	command = (command & 0xFFu) | ((uint32_t)(uint8_t)((command >> 8) + kind) << 8);
	carry = vector_queue_sound(command);
}
