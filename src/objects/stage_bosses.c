/**
 *    Name:        objects/stage_bosses.c
 *    Description: what bank 1E's bosses share: states, hit checks, the floor, targets
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    10-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the game's 053248 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

/* True when a player in play is in a state its class marks negative (down or hurt): the bosses taunt
   then */
uint32_t stage_boss_any_player_down(void)
{
	uint32_t carry = 0;
	uint8_t playing_bits = 0;
	uint8_t bits_from_marge = 0, bits_from_homer = 0, bits_from_bart = 0;

	bits_from_marge = players_playing;
	playing_bits = bits_from_marge >> 1;
	if ((bits_from_marge & 1u) == 0u || (int8_t)OBJECT(OBJECT_ADDRESS(0))->state >= 0)
	{
		bits_from_homer = playing_bits;
		playing_bits = bits_from_homer >> 1;
		if ((bits_from_homer & 1u) == 0u || (int8_t)OBJECT(OBJECT_ADDRESS(2))->state >= 0)
		{
			bits_from_bart = playing_bits;
			playing_bits = bits_from_bart >> 1;
			if (((bits_from_bart & 1u) == 0u || (int8_t)OBJECT(OBJECT_ADDRESS(4))->state >= 0) && ((playing_bits & 1u) == 0u || (int8_t)OBJECT(OBJECT_ADDRESS(6))->state >= 0))
			{
				carry = 0u;
				return carry;
			}
		}
	}
	carry = 1u;
	return carry;
}

/* Stops the boss and gives it an animation, a state and that state's wait */
void stage_boss_set_state(uint16_t object, uint16_t state_wait, uint16_t animation_number)
{
	OBJECT(object)->animation = animation_number >> 8;
	OBJECT(object)->x_speed = 0;
	OBJECT(object)->y_speed = 0;
	OBJECT(object)->target_dy = state_wait;
}

/* Marks the boss as in the air (bit 3 of its flags) */
void stage_boss_set_airborne(uint16_t object)
{
	OBJECT(object)->flags |= 8u;
}

/* Clears the in-the-air mark of the boss's flags as it lands */
void stage_boss_clear_airborne(uint16_t object)
{
	OBJECT(object)->flags &= ~8u;
}

/* Throws the boss up and away from its attacker or the screen's edge, and marks it in the air */
uint16_t stage_boss_knock_away(uint16_t object, uint16_t object_2)
{
	uint32_t negative = 0;
	uint16_t floor_cell = 0, x_place = 0;
	uint16_t stack = 0;
	uint8_t attributes = 0;
	uint16_t boss_x = 0, boss_x_at_wall = 0, hit_by = 0;

	OBJECT(object)->z_speed = object_2;
	vector_floor_ahead_x(object, &floor_cell, &negative);
	if (floor_cell >> 8 == 0u)
	{
		boss_x = OBJECT(object)->x;
		x_place = boss_x;
	}
	else
	{
		boss_x_at_wall = OBJECT(object)->x;
		x_place = boss_x_at_wall;
		if ((int16_t)x_place > 0xE0)
		{
			if ((int16_t)x_place > 0xE0)
			{
				stack = leftover_y;
				stack = 0u - stack;
				leftover_y = stack;
				OBJECT(object)->x_speed = leftover_y;
				stage_boss_set_airborne(object);
				return object_2;
			}
			boss_x = OBJECT(object)->x;
			x_place = boss_x;
		}
	}
	if ((int16_t)x_place < 0x78)
	{
		if ((int16_t)leftover_y >= 0)
		{
			OBJECT(object)->x_speed = leftover_y;
			stage_boss_set_airborne(object);
			return object_2;
		}
		if ((int16_t)leftover_y < 0)
		{
			stack = leftover_y;
			stack = 0u - stack;
			leftover_y = stack;
			OBJECT(object)->x_speed = leftover_y;
			stage_boss_set_airborne(object);
			return object_2;
		}
	}
	if ((int16_t)x_place <= 0x138)
	{
		hit_by = OBJECT(object)->hit_by;
		object_2 = hit_by;
		attributes = OBJECT(object_2)->attributes;
		if ((attributes & 0x40u) == 0u)
		{
			OBJECT(object)->x_speed = leftover_y;
			stage_boss_set_airborne(object);
			return object_2;
		}
		stack = leftover_y;
		stack = 0u - stack;
		leftover_y = stack;
		OBJECT(object)->x_speed = leftover_y;
		stage_boss_set_airborne(object);
		return object_2;
	}
	if ((int16_t)leftover_y >= 0)
	{
		stack = leftover_y;
		stack = 0u - stack;
		leftover_y = stack;
		OBJECT(object)->x_speed = leftover_y;
		stage_boss_set_airborne(object);
		return object_2;
	}
	if ((int16_t)leftover_y < 0)
	{
		OBJECT(object)->x_speed = leftover_y;
		stage_boss_set_airborne(object);
		return object_2;
	}
	hit_by = OBJECT(object)->hit_by;
	object_2 = hit_by;
	attributes = OBJECT(object_2)->attributes;
	if ((attributes & 0x40u) != 0u)
	{
		stack = leftover_y;
		stack = 0u - stack;
		leftover_y = stack;
	}
	OBJECT(object)->x_speed = leftover_y;
	stage_boss_set_airborne(object);
	return object_2;
}

/* Unused: when the boss is beaten by a kind 5 object, marks that object. */
void unused_stage_boss_mark_kind_5_hitter(uint16_t object)
{
	uint8_t hit = 0;
	uint16_t hitter = 0;
	uint8_t hit_2 = 0, kind = 0;
	uint16_t hit_by = 0;

	hit_2 = OBJECT(object)->hit;
	hit = hit_2;
	if ((int8_t)hit < 0x10)
		return;
	if (hit == 0xFFu)
	{
		hit_by = OBJECT(object)->hit_by;
		hitter = hit_by;
		kind = OBJECT(hitter)->kind;
		if (kind == 5u)
		{
			OBJECT(hitter)->enemy_class = 1;
			return;
		}
	}
}

/* 18 pixels in front of the object in U, by the way it faces */
uint16_t stage_boss_offset_ahead_of(uint16_t other)
{
	uint8_t offset = 0, other_attributes = 0;
	uint16_t offset_ahead = 0;
	uint8_t attributes = 0;

	attributes = OBJECT(other)->attributes;
	other_attributes = attributes;
	offset = 0x18u;
	if ((other_attributes & 0x40u) != 0u)
		offset = 0u - offset;
	offset_ahead = ((uint32_t)other_attributes << 8) | offset;
	return offset_ahead;
}

/* Stops the boss at the screen's sides and keeps it on the floor */
uint32_t stage_boss_move_on_screen(uint16_t object)
{
	uint32_t carry = 0;
	uint16_t next_x = 0, x_and_fraction = 0;
	uint8_t stack = 0;
	uint8_t x_speed_2 = 0, x_high = 0;
	uint16_t x_low_and_fraction = 0, x_speed = 0, x_speed_3 = 0, x_speed_4 = 0;

	x_low_and_fraction = (((uint32_t)(OBJECT(object)->x & 0xFFu) << 8u) | OBJECT(object)->x_fraction);
	x_and_fraction = x_low_and_fraction;
	x_speed = OBJECT(object)->x_speed;
	carry = (uint16_t)(x_and_fraction + x_speed) < x_and_fraction;
	stack = (uint16_t)(x_and_fraction + x_speed) >> 8;
	x_speed_2 = (uint8_t)(OBJECT(object)->x_speed >> 8u);
	x_high = (uint8_t)(OBJECT(object)->x >> 8u);
	next_x = ((uint32_t)(uint8_t)(((uint16_t)(int8_t)x_speed_2 >> 8) + x_high + carry) << 8) | stack;
	if ((int16_t)next_x >= 0x70)
	{
		if ((int16_t)next_x > 0x140)
		{
			x_speed_3 = OBJECT(object)->x_speed;
			if ((int16_t)x_speed_3 >= 0)
				return stage_boss_stop_on_floor(object);
		}
		return stage_boss_follow_floor(object);
	}
	x_speed_4 = OBJECT(object)->x_speed;
	if ((int16_t)x_speed_4 >= 0)
		return stage_boss_follow_floor(object);
	return stage_boss_stop_on_floor(object);
}

/* Stops the boss where there is no floor, takes the floor's priority and height, and falls to it */
uint32_t stage_boss_follow_floor(uint16_t object)
{
	uint32_t negative = 0;
	uint8_t floor_height_high = 0, floor_height_low = 0, floor_value = 0;
	uint16_t floor_cell = 0, z = 0;
	uint8_t attributes = 0;
	uint16_t floor_height = 0, z_2 = 0;

	vector_floor_ahead(object, &floor_cell, &negative);
	floor_value = (uint8_t)(floor_cell >> 8);
	if ((int8_t)floor_value >= 0)
	{
		priority_bits = floor_value & 0x30u;
		attributes = OBJECT(object)->attributes;
		OBJECT(object)->attributes = (attributes & 0xCFu) | priority_bits;
		floor_height = (uint8_t)((((floor_value & 0xFu) << 1) << 1) << 1);
		floor_height_high = (uint8_t)(floor_height >> 8);
		floor_height_low = (uint8_t)floor_height;
		z_2 = OBJECT(object)->z;
		if ((int16_t)z_2 < (int16_t)(((uint32_t)floor_height_high << 8) | floor_height_low))
		{
			OBJECT(object)->y_speed = 0;
			return stage_boss_stop_on_floor(object);
		}
		OBJECT(object)->floor_z = ((uint32_t)floor_height_high << 8) | floor_height_low;
		z = ((uint32_t)floor_height_high << 8) | floor_height_low;
		return stage_boss_settle(object, z);
	}
	vector_floor_ahead_x(object, &floor_cell, &negative);
	floor_value = (uint8_t)(floor_cell >> 8);
	if ((int8_t)floor_value >= 0)
	{
		OBJECT(object)->y_speed = 0;
		priority_bits = floor_value & 0x30u;
		attributes = OBJECT(object)->attributes;
		OBJECT(object)->attributes = (attributes & 0xCFu) | priority_bits;
		floor_height = (uint8_t)((((floor_value & 0xFu) << 1) << 1) << 1);
		floor_height_high = (uint8_t)(floor_height >> 8);
		floor_height_low = (uint8_t)floor_height;
		z_2 = OBJECT(object)->z;
		if ((int16_t)z_2 < (int16_t)(((uint32_t)floor_height_high << 8) | floor_height_low))
		{
			OBJECT(object)->y_speed = 0;
			return stage_boss_stop_on_floor(object);
		}
		OBJECT(object)->floor_z = ((uint32_t)floor_height_high << 8) | floor_height_low;
		z = ((uint32_t)floor_height_high << 8) | floor_height_low;
		return stage_boss_settle(object, z);
	}
	OBJECT(object)->x_speed = 0;
	vector_floor_ahead_y(object, &floor_cell, &negative);
	floor_value = (uint8_t)(floor_cell >> 8);
	if ((int8_t)floor_value >= 0)
	{
		priority_bits = floor_value & 0x30u;
		attributes = OBJECT(object)->attributes;
		OBJECT(object)->attributes = (attributes & 0xCFu) | priority_bits;
		floor_height = (uint8_t)((((floor_value & 0xFu) << 1) << 1) << 1);
		floor_height_high = (uint8_t)(floor_height >> 8);
		floor_height_low = (uint8_t)floor_height;
		z_2 = OBJECT(object)->z;
		if ((int16_t)z_2 < (int16_t)(((uint32_t)floor_height_high << 8) | floor_height_low))
		{
			OBJECT(object)->y_speed = 0;
			return stage_boss_stop_on_floor(object);
		}
		OBJECT(object)->floor_z = ((uint32_t)floor_height_high << 8) | floor_height_low;
		z = ((uint32_t)floor_height_high << 8) | floor_height_low;
		return stage_boss_settle(object, z);
	}
	if ((int8_t)floor_value < 0)
	{
		OBJECT(object)->y_speed = 0;
		return stage_boss_stop_on_floor(object);
	}
	OBJECT(object)->y_speed = 0;
	priority_bits = floor_value & 0x30u;
	attributes = OBJECT(object)->attributes;
	OBJECT(object)->attributes = (attributes & 0xCFu) | priority_bits;
	floor_height = (uint8_t)((((floor_value & 0xFu) << 1) << 1) << 1);
	floor_height_high = (uint8_t)(floor_height >> 8);
	floor_height_low = (uint8_t)floor_height;
	z_2 = OBJECT(object)->z;
	if ((int16_t)z_2 < (int16_t)(((uint32_t)floor_height_high << 8) | floor_height_low))
	{
		OBJECT(object)->y_speed = 0;
		return stage_boss_stop_on_floor(object);
	}
	OBJECT(object)->floor_z = ((uint32_t)floor_height_high << 8) | floor_height_low;
	z = ((uint32_t)floor_height_high << 8) | floor_height_low;
	return stage_boss_settle(object, z);
}

/* Stops the boss's x speed and settles it on its floor height */
uint32_t stage_boss_stop_on_floor(uint16_t object)
{
	uint16_t z = 0;
	uint16_t floor_z = 0;

	OBJECT(object)->x_speed = 0;
	floor_z = OBJECT(object)->floor_z;
	z = floor_z;
	return stage_boss_settle(object, z);
}

/* Pulls the boss down to its floor; on landing stops it and clears its in-the-air mark */
uint32_t stage_boss_settle(uint16_t object, uint16_t z)
{
	uint32_t carry = 0;
	uint16_t z_2 = 0, z_speed = 0, z_speed_2 = 0;

	z_2 = OBJECT(object)->z;
	if ((int16_t)z < (int16_t)z_2)
	{
		z_speed = OBJECT(object)->z_speed;
		OBJECT(object)->z_speed = z_speed - 0x60u;
		carry = 0u;
		return carry;
	}
	OBJECT(object)->z = z;
	z_speed_2 = OBJECT(object)->z_speed;
	leftover_y = z_speed_2;
	if (z_speed_2 != 0u)
	{
		OBJECT(object)->z_speed = 0;
		stage_boss_clear_airborne(object);
	}
	carry = 1u;
	return carry;
}

/* Sets the object active and shown (flags C0) */
void stage_boss_activate(uint16_t object)
{
	OBJECT(object)->flags = 0xC0u;
}

/* A player's object in U, from a random slot on to the first one in use */
uint16_t stage_boss_pick_random_player(void)
{
	uint32_t zero = 0;
	uint16_t player = 0;
	uint8_t stack = 0, stack_10002 = 0;
	uint16_t player_offset = 0, start_player = 0;

	player_offset = (random_number & 3u) * 0xC0u;
	start_player = player_offset + OBJECT_ADDRESS(0);
	stack = start_player >> 8;
	stack_10002 = start_player;
	player = ((uint32_t)stack << 8) | stack_10002;
	stage_boss_next_player_slot(&player, &zero);
	if (zero == 0u)
		return player;
	stage_boss_next_player_slot(&player, &zero);
	if (zero == 0u)
		return player;
	stage_boss_next_player_slot(&player, &zero);
	if (zero)
		stage_boss_next_player_slot(&player, &zero);
	return player;
}

/* The next player's slot after U, wrapping from Lisa's to Marge's, and whether it is in use */
void stage_boss_next_player_slot(uint16_t *p_player, uint32_t *p_zero)
{
	uint16_t player = (uint16_t)*p_player;
	uint32_t zero = *p_zero;

	player += 0xC0u;
	if (player == OBJECT_ADDRESS(8))
		player = OBJECT_ADDRESS(0);
	zero = OBJECT(player)->flags == 0u;
	*p_player = player;
	*p_zero = zero;
}

/* Turns the direction in the scratch byte by B toward the object in U */
void stage_boss_turn_toward(uint16_t object, uint16_t other, uint16_t turn_step)
{
	uint32_t overflow = 0;
	uint8_t turn = 0;
	uint8_t current_direction = 0, wanted_direction = 0;

	turn_step = vector_direction_to_offset(object, other, turn_step);
	turn = (uint8_t)turn_step;
	current_direction = turning_direction;
	wanted_direction = ((turn_step & ~0xFFu) | turn) >> 8;
	overflow = (uint32_t)(int8_t)wanted_direction - (int8_t)current_direction != (uint32_t)(int8_t)(wanted_direction - current_direction);
	if ((int8_t)wanted_direction < (int8_t)current_direction)
	{
		if (overflow == 0u)
			turn = 0u - turn;
	}
	else if (overflow)
	{
		turn = 0u - turn;
		turning_direction += turn;
		return;
	}
	turning_direction += turn;
}

/* Notes in field 27 which player's attack beat the boss, for the score */
uint16_t stage_boss_note_beater(uint16_t object)
{
	uint16_t object_2 = 0;
	uint8_t shadow_player = 0;
	uint16_t hit_by = 0;

	hit_by = OBJECT(object)->hit_by;
	object_2 = hit_by;
	shadow_player = OBJECT(object_2)->shadow_player;
	OBJECT(object)->points = shadow_player & ~0xFu;
	return object_2;
}

/* Asks the score routine to award the beater one score step */
void stage_boss_award_score(uint16_t object)
{
	uint8_t points = 0;

	points = OBJECT(object)->points;
	OBJECT(object)->points = points | 0x81u;
}

/* The first player in play within the ranges in the scratch words, in U, carry set if one is */
void stage_boss_find_near_player(uint16_t object, uint16_t *p_player, uint16_t *p_playing_bits, uint32_t *p_carry)
{
	uint32_t carry = *p_carry;
	uint16_t player = 0, playing_bits = 0;

	player = OBJECT_ADDRESS(0);
	playing_bits = players_playing;
	stage_boss_player_is_near(object, player, &playing_bits, &carry);
	if (carry == 0u)
	{
		player = OBJECT_ADDRESS(2);
		stage_boss_player_is_near(object, player, &playing_bits, &carry);
		if (carry == 0u)
		{
			player = OBJECT_ADDRESS(4);
			stage_boss_player_is_near(object, player, &playing_bits, &carry);
			if (carry == 0u)
			{
				player = OBJECT_ADDRESS(6);
				stage_boss_player_is_near(object, player, &playing_bits, &carry);
			}
		}
	}
	*p_player = player;
	*p_playing_bits = playing_bits;
	*p_carry = carry;
}

/* Whether the player in U is in play and within the ranges in the scratch words */
void stage_boss_player_is_near(uint16_t object, uint16_t object_2, uint16_t *p_playing_bits, uint32_t *p_carry)
{
	uint8_t playing_bits = (uint8_t)*p_playing_bits;
	uint32_t carry = *p_carry;
	uint16_t distance = 0, playing_bits_left = 0;
	uint8_t stack = 0;
	uint8_t player_bits = 0;
	uint16_t own_x = 0, player_at_x = 0, x_distance = 0, own_y = 0, player_at_y = 0, y_distance = 0;

	player_bits = playing_bits;
	playing_bits_left = player_bits >> 1;
	if ((player_bits & 1u) == 0u)
	{
		carry = 0u;
		playing_bits_left &= 0xFFu;
	}
	else
	{
		stack = (uint8_t)playing_bits_left;
		own_x = OBJECT(object)->x;
		player_at_x = OBJECT(object_2)->x;
		distance = own_x - player_at_x;
		x_distance = distance >> 15 ? 0u - distance : distance;
		playing_bits_left = stack;
		if (reach_x <= (int16_t)x_distance)
		{
			carry = 0u;
			playing_bits_left &= 0xFFu;
		}
		else
		{
			stack = (uint8_t)playing_bits_left;
			own_y = OBJECT(object)->y;
			player_at_y = OBJECT(object_2)->y;
			distance = own_y - player_at_y;
			distance = (uint16_t)(distance >> 15 ? 0u - distance : distance);
			y_distance = distance;
			playing_bits_left = (distance & ~0xFFu) | stack;
			if (reach_y <= (int16_t)y_distance)
			{
				carry = 0u;
				playing_bits_left &= 0xFFu;
			}
			else
			{
				carry = 1u;
				playing_bits_left = (playing_bits_left & 0xFFu) | ((uint32_t)(uint8_t)~(playing_bits_left >> 8) << 8);
			}
		}
	}
	*p_playing_bits = playing_bits_left;
	*p_carry = carry;
}

/* True when a player's object is in the air (its height not 0) */
void stage_boss_any_player_off_floor(uint16_t *p_player, uint32_t *p_carry)
{
	uint32_t carry = *p_carry;
	uint16_t player = 0;

	player = OBJECT_ADDRESS(0);
	stage_boss_player_off_floor(&player, &carry);
	if (carry == 0u)
	{
		player = OBJECT_ADDRESS(2);
		stage_boss_player_off_floor(&player, &carry);
		if (carry == 0u)
		{
			player = OBJECT_ADDRESS(4);
			stage_boss_player_off_floor(&player, &carry);
			if (carry == 0u)
			{
				player = OBJECT_ADDRESS(6);
				stage_boss_player_off_floor(&player, &carry);
			}
		}
	}
	*p_player = player;
	*p_carry = carry;
}

/* Whether the player in U is in use and off the floor */
void stage_boss_player_off_floor(uint16_t *p_object, uint32_t *p_carry)
{
	uint16_t object = (uint16_t)*p_object;
	uint32_t carry = *p_carry;
	uint16_t z = 0;

	if (OBJECT(object)->flags == 0u)
		carry = 0u;
	else
	{
		z = OBJECT(object)->z;
		object = z;
		if (z == 0u)
			carry = 0u;
		else
			carry = 1u;
	}
	*p_object = object;
	*p_carry = carry;
}

/* Makes the boss unhurtable (bit 2 of its flags) */
void stage_boss_shield(uint16_t object)
{
	OBJECT(object)->flags |= 4u;
}

/* Makes the boss hurtable again */
void stage_boss_unshield(uint16_t object)
{
	OBJECT(object)->flags &= ~4u;
}

/* Whether the boss was hit this frame: 0 no, 1 hurt, FF beaten (its health at or below its limit for the
   players) */
void stage_boss_check_hit(uint16_t object, uint16_t health_limits, uint16_t *p_object_2, uint32_t *p_zero, uint32_t *p_negative)
{
	uint16_t object_2 = (uint16_t)*p_object_2;
	uint32_t zero = *p_zero;
	uint32_t negative = *p_negative;
	uint32_t carry = 0;
	uint8_t behaviour = 0, health = 0, players = 0;
	uint16_t command = 0;
	uint8_t hit = 0, vitality = 0, vitality_2 = 0;
	uint16_t hit_by = 0;

	if ((OBJECT(object)->flags & 0x20u) == 0u)
	{
		negative = 0u;
		zero = 1u;
	}
	else
	{
		hit = OBJECT(object)->hit;
		behaviour = hit;
		if ((int8_t)behaviour < 0x11)
		{
			negative = 0u;
			zero = 1u;
		}
		else
		{
			OBJECT(object)->damage = 0u;
			OBJECT(object)->attack = 0u;
			hit_by = OBJECT(object)->hit_by;
			object_2 = hit_by;
			if ((int16_t)object_2 >= 0x4A40 && (int16_t)object_2 < 0x4D40)
			{
				OBJECT(object_2)->behaviour = (OBJECT(object_2)->behaviour & 0xFFu) | ((behaviour & 0xFFu) << 8u);
				AT16(OBJECT(object_2)->hit_box, -1) = object;
			}
			OBJECT(object)->flags = 0x80u;
			vitality = OBJECT(object)->vitality;
			health = vitality;
			players = player_count;
			if (health <= BEATEN_HEALTH(health_limits + (int8_t)players))
			{
				vitality_2 = OBJECT(object)->vitality;
				health = vitality_2;
			}
			if (health <= BEATEN_HEALTH(health_limits + (int8_t)players))
			{
				OBJECT(object)->vitality = 0u;
				object_2 = stage_boss_note_beater(object);
				command = 0x6600u;
				carry = vector_queue_sound(command);
				negative = 1u;
				zero = 0xFFu == 0u;
			}
			else
			{
				command = 0x6600u;
				carry = vector_queue_sound(command);
				negative = 0u;
				zero = 1u == 0u;
			}
		}
	}
	*p_object_2 = object_2;
	*p_zero = zero;
	*p_negative = negative;
}

/* Blinks the beaten boss for its wait, then removes it and awards its score (carry set when gone) */
uint32_t stage_boss_blink_out(uint16_t object)
{
	uint32_t carry = 0;
	uint8_t blinks_left = 0;

	OBJECT(object)->flags = (OBJECT(object)->flags ^ 0x80u) | 4u;
	blinks_left = (uint8_t)OBJECT(object)->target_dy;
	OBJECT(object)->target_dy = (OBJECT(object)->target_dy & 0xFF00u) | (blinks_left - 1u & 0xFFu);
	if (blinks_left != 1u)
	{
		carry = 0u;
		return carry;
	}
	OBJECT(object)->flags = 0u;
	stage_boss_award_score(object);
	carry = 1u;
	return carry;
}

/* Gives the boss its attack's damage on the animation's attack frames, and says whether the animation
   ended */
uint32_t stage_boss_attack_frame(uint16_t object, uint16_t damage)
{
	uint32_t carry = 0;
	uint8_t animation_flags = 0, animation_flags_2 = 0;

	animation_flags = OBJECT(object)->animation_flags;
	if ((animation_flags & 2u) != 0u)
		stage_boss_unshield(object);
	else
		damage = 0u;
	OBJECT(object)->damage = (uint8_t)(damage >> 8u);
	OBJECT(object)->attack = (uint8_t)damage;
	animation_flags_2 = OBJECT(object)->animation_flags;
	carry = animation_flags_2 & 1u;
	return carry;
}

/* Copies a hit box record into the boss's fields 1F-24 */
void stage_boss_set_hit_box(uint16_t object, uint16_t box)
{
	uint16_t box_rest = 0, height = 0;
	uint16_t box_record = 0;

	box_record = box;
	box_rest = box_record + 2u;
	OBJECT(object)->box_width = BOSS_BOX(box_record)->width;
	OBJECT(object)->box_depth = BOSS_BOX(box_record)->depth;
	height = (((uint32_t)BOSS_BOX(box_rest - 0x2u)->height << 8u) | (uint8_t)BOSS_BOX(box_rest - 0x2u)->dx);
	OBJECT(object)->box_height = (uint8_t)(height >> 8u);
	OBJECT(object)->box_dx = (uint8_t)height;
	OBJECT(object)->box_dz = height >> 8;
	leftover_y = box_rest;
}

/* Unused: faces the way it moves in x, restarting its animation when it turns. */
void unused_stage_boss_face_motion(uint16_t object)
{
	uint8_t facing = 0;
	uint8_t attributes = 0, attributes_2 = 0, animation = 0;
	uint16_t x_speed = 0;

	facing = 0u;
	x_speed = OBJECT(object)->x_speed;
	if ((int16_t)x_speed < 0)
		facing = 0x40u;
	attributes = OBJECT(object)->attributes;
	if (((facing ^ attributes) & 0x40u) != 0u)
	{
		attributes_2 = OBJECT(object)->attributes;
		OBJECT(object)->attributes = attributes_2 ^ 0x40u;
		animation = OBJECT(object)->animation;
		OBJECT(object)->animation = animation | 0x80u;
	}
}

/* Turns the boss toward the nearest player (in U) */
uint16_t stage_boss_face_nearest_player(uint16_t object)
{
	uint8_t attributes = 0;
	uint16_t target_player = 0;
	uint8_t attributes_2 = 0;
	uint16_t own_x = 0, target_x = 0;

	target_player = vector_choose_nearest_player(object);
	attributes_2 = OBJECT(object)->attributes;
	attributes = attributes_2 & 0xBFu;
	own_x = OBJECT(object)->x;
	target_x = OBJECT(target_player)->x;
	if ((int16_t)target_x < (int16_t)own_x)
		attributes |= 0x40u;
	OBJECT(object)->attributes = attributes;
	return target_player;
}

/* Sets the boss's speeds in direction A at the speed the table in Y gives for the rank */
void stage_boss_walk_by_rank(uint16_t object, uint16_t speeds_by_rank, uint16_t direction)
{
	uint16_t heading = 0;

	heading = (direction & ~0xFFu) | WALK_SPEED(speeds_by_rank + (rank >> 1));
	vector_set_speed_by_direction(object, heading);
}

/* Unused: tests whether the boss stands still (both speeds zero). */
void unused_stage_boss_is_still(uint16_t object)
{
	uint16_t x_speed = 0, y_speed = 0;

	x_speed = OBJECT(object)->x_speed;
	if (x_speed == 0u)
	{
		y_speed = OBJECT(object)->y_speed;
		if (y_speed == 0u)
			return;
	}
}

/* Shows the boss's health gauge B, a piece standing for the table's health by the players in play */
void stage_boss_set_gauge(uint16_t object, uint16_t piece_health_by_players, uint16_t gauge_number)
{
	gauge_number |= (uint32_t)GAUGE_HEALTH(piece_health_by_players + (int8_t)player_count) << 8;
	boss_shade_by_vitality(object, gauge_number);
}
