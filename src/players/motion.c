/**
 *    Name:        players/motion.c
 *    Description: a player's motion against walls, floors, the screen's edges and the scroll, and helpers on its speeds and partner
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    11-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the game's 053248 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

/* Stops the player's (and its partner's) x or y speed where the next place is past the back line, the
   screen's edge, a wall or a floor too high, takes the floor it stands on and its priority, and keeps
   its life in its record. */
void player_check_motion(uint16_t player)
{
	uint32_t floor_at_height = 0, floor_below_height = 0, floor_compare_overflow = 0, carry = 0;
	uint8_t floor_high = 0, floor_low = 0, floor_value = 0, next_x_high = 0, next_x_low = 0;
	uint16_t floor_cell = 0, mover = 0, object = 0, player_vars = 0, right_limit = 0;
	uint8_t next_position_byte = 0;
	uint8_t teamed = 0, y_speed_2 = 0, y_high = 0, x_speed_2 = 0, x_high = 0, vitality = 0, vitality_2 = 0, scene_number = 0, attributes = 0, vitality_3 = 0;
	uint16_t partner = 0, y_and_fraction = 0, y_speed = 0, y_low_and_fraction = 0, x_and_fraction = 0, x_speed = 0, x_low_and_fraction = 0, x_speed_3 = 0, running_values = 0;

	teamed = OBJECT(player)->player.teamed;
	if ((int8_t)teamed >= 0)
		mover = player;
	else
	{
		partner = OBJECT(player)->player.partner;
		mover = partner;
	}
	y_and_fraction = (((uint32_t)(OBJECT(player)->y & 0xFFu) << 8u) | OBJECT(player)->y_fraction);
	y_speed = OBJECT(player)->y_speed;
	y_low_and_fraction = y_and_fraction;
	carry = (uint16_t)(y_low_and_fraction + y_speed) < y_low_and_fraction;
	next_position_byte = (uint16_t)(y_low_and_fraction + y_speed) >> 8;
	y_speed_2 = (uint8_t)(OBJECT(player)->y_speed >> 8u);
	y_high = (uint8_t)(OBJECT(player)->y >> 8u);
	if ((int16_t)(((uint32_t)(uint8_t)(((uint16_t)(int8_t)y_speed_2 >> 8) + y_high + carry) << 8) | next_position_byte) < 0x98)
	{
		OBJECT(player)->y_speed = 0;
		OBJECT(mover)->y_speed = 0;
	}
	x_and_fraction = (((uint32_t)(OBJECT(player)->x & 0xFFu) << 8u) | OBJECT(player)->x_fraction);
	x_speed = OBJECT(player)->x_speed;
	x_low_and_fraction = x_and_fraction;
	carry = (uint16_t)(x_low_and_fraction + x_speed) < x_low_and_fraction;
	next_position_byte = (uint16_t)(x_low_and_fraction + x_speed) >> 8;
	x_speed_2 = (uint8_t)(OBJECT(player)->x_speed >> 8u);
	x_high = (uint8_t)(OBJECT(player)->x >> 8u);
	next_x_high = ((uint16_t)(int8_t)x_speed_2 >> 8) + x_high + carry;
	next_x_low = next_position_byte;
	vitality = OBJECT(player)->vitality;
	if (vitality == 0u)
	{
		if ((int16_t)(((uint32_t)next_x_high << 8) | next_x_low) >= 0x5A)
		{
			right_limit = 0x140u;
			vitality_2 = OBJECT(player)->vitality;
			if (vitality_2 != 0u)
			{
				next_position_byte = next_x_high;
				scene_number = scene;
				next_x_high = next_position_byte;
				if (scene_number == 4u)
					right_limit = 0x150u;
			}
			else
				right_limit += 0x26u;
			player_x_limit = right_limit;
			if ((int16_t)player_x_limit < (int16_t)(((uint32_t)next_x_high << 8) | next_x_low))
				OBJECT(player)->x_speed = 0;
		}
		else
			OBJECT(player)->x_speed = 0;
	}
	else if ((int16_t)(((uint32_t)next_x_high << 8) | next_x_low) >= 0x70)
	{
		right_limit = 0x140u;
		vitality_2 = OBJECT(player)->vitality;
		if (vitality_2 != 0u)
		{
			next_position_byte = next_x_high;
			scene_number = scene;
			next_x_high = next_position_byte;
			if (scene_number == 4u)
				right_limit = 0x150u;
		}
		else
			right_limit += 0x26u;
		player_x_limit = right_limit;
		if ((int16_t)player_x_limit < (int16_t)(((uint32_t)next_x_high << 8) | next_x_low))
			OBJECT(player)->x_speed = 0;
	}
	else
		OBJECT(player)->x_speed = 0;
	object = player;
	vector_floor_ahead(object, &floor_cell, &floor_below_height);
	floor_value = (uint8_t)(floor_cell >> 8);
	if ((int8_t)floor_value >= 0)
	{
		player_floor_against_height(player, &floor_cell, &floor_at_height, &floor_below_height, &floor_compare_overflow);
		floor_high = (uint8_t)(floor_cell >> 8);
		floor_low = (uint8_t)floor_cell;
		if ((floor_below_height ^ floor_compare_overflow) | floor_at_height)
		{
			OBJECT(player)->floor_z = ((uint32_t)floor_high << 8) | floor_low;
			attributes = OBJECT(player)->attributes;
			OBJECT(player)->attributes = (attributes & 0xCFu) | player_floor_priority;
			x_speed_3 = OBJECT(player)->x_speed;
			OBJECT(mover)->x_speed = x_speed_3;
			vitality_3 = OBJECT(player)->vitality;
			running_values = io_read16(running_player_values);
			player_vars = running_values;
			PLAYER_VALUES(player_vars)->kept_life = vitality_3;
			return;
		}
	}
	object = player;
	vector_floor_ahead_x(object, &floor_cell, &floor_below_height);
	floor_value = (uint8_t)(floor_cell >> 8);
	if ((int8_t)floor_value >= 0)
	{
		player_floor_against_height(player, &floor_cell, &floor_at_height, &floor_below_height, &floor_compare_overflow);
		floor_high = (uint8_t)(floor_cell >> 8);
		floor_low = (uint8_t)floor_cell;
		if ((floor_below_height ^ floor_compare_overflow) | floor_at_height)
		{
			OBJECT(player)->y_speed = 0;
			OBJECT(mover)->y_speed = 0;
			OBJECT(player)->floor_z = ((uint32_t)floor_high << 8) | floor_low;
			attributes = OBJECT(player)->attributes;
			OBJECT(player)->attributes = (attributes & 0xCFu) | player_floor_priority;
			x_speed_3 = OBJECT(player)->x_speed;
			OBJECT(mover)->x_speed = x_speed_3;
			vitality_3 = OBJECT(player)->vitality;
			running_values = io_read16(running_player_values);
			player_vars = running_values;
			PLAYER_VALUES(player_vars)->kept_life = vitality_3;
			return;
		}
	}
	OBJECT(player)->x_speed = 0;
	object = player;
	vector_floor_ahead_y(object, &floor_cell, &floor_below_height);
	floor_value = (uint8_t)(floor_cell >> 8);
	if ((int8_t)floor_value < 0)
	{
		OBJECT(player)->y_speed = 0;
		OBJECT(mover)->y_speed = 0;
		x_speed_3 = OBJECT(player)->x_speed;
		OBJECT(mover)->x_speed = x_speed_3;
		vitality_3 = OBJECT(player)->vitality;
		running_values = io_read16(running_player_values);
		player_vars = running_values;
		PLAYER_VALUES(player_vars)->kept_life = vitality_3;
		return;
	}
	player_floor_against_height(player, &floor_cell, &floor_at_height, &floor_below_height, &floor_compare_overflow);
	floor_high = (uint8_t)(floor_cell >> 8);
	floor_low = (uint8_t)floor_cell;
	if ((floor_below_height ^ floor_compare_overflow) | floor_at_height)
	{
		OBJECT(player)->floor_z = ((uint32_t)floor_high << 8) | floor_low;
		attributes = OBJECT(player)->attributes;
		OBJECT(player)->attributes = (attributes & 0xCFu) | player_floor_priority;
		x_speed_3 = OBJECT(player)->x_speed;
		OBJECT(mover)->x_speed = x_speed_3;
		vitality_3 = OBJECT(player)->vitality;
		running_values = io_read16(running_player_values);
		player_vars = running_values;
		PLAYER_VALUES(player_vars)->kept_life = vitality_3;
		return;
	}
	OBJECT(player)->y_speed = 0;
	OBJECT(mover)->y_speed = 0;
	x_speed_3 = OBJECT(player)->x_speed;
	OBJECT(mover)->x_speed = x_speed_3;
	vitality_3 = OBJECT(player)->vitality;
	running_values = io_read16(running_player_values);
	player_vars = running_values;
	PLAYER_VALUES(player_vars)->kept_life = vitality_3;
}

/* The floor height (8 a step) of the block flags in A against the player's height; their priority bits
   in F2. */
void player_floor_against_height(uint16_t player, uint16_t *p_floor_cell, uint32_t *p_floor_at_height, uint32_t *p_floor_below_height, uint32_t *p_floor_compare_overflow)
{
	uint16_t floor_cell = (uint16_t)*p_floor_cell;
	uint32_t floor_at_height = *p_floor_at_height;
	uint32_t floor_below_height = *p_floor_below_height;
	uint32_t floor_compare_overflow = *p_floor_compare_overflow;
	uint8_t block_flags = 0, height_high = 0, height_low = 0;
	uint16_t floor_height = 0;
	uint16_t floor_height_byte = 0, z = 0, floor_height_word = 0, height_difference = 0;

	block_flags = (uint8_t)(floor_cell >> 8);
	player_floor_priority = block_flags & 0x30u;
	floor_height_byte = (uint8_t)((((block_flags & 0xFu) << 1) << 1) << 1);
	height_high = (uint8_t)(floor_height_byte >> 8);
	height_low = (uint8_t)floor_height_byte;
	z = OBJECT(player)->z;
	floor_height_word = ((uint32_t)height_high << 8) | height_low;
	height_difference = floor_height_word - z;
	floor_below_height = height_difference >> 15;
	floor_at_height = height_difference == 0u;
	floor_compare_overflow = (uint32_t)floor_height_word - (int16_t)z != (uint32_t)(int16_t)(floor_height_word - z);
	floor_height = ((uint32_t)height_high << 8) | height_low;
	*p_floor_cell = floor_height;
	*p_floor_at_height = floor_at_height;
	*p_floor_below_height = floor_below_height;
	*p_floor_compare_overflow = floor_compare_overflow;
}

/* Keeps the player's life in its record (the state of states 01, 2E, 39 and 3F, which do nothing else). */
void player_keep_life(uint16_t player)
{
	uint16_t player_vars = 0;
	uint8_t vitality = 0;
	uint16_t running_values = 0;

	vitality = OBJECT(player)->vitality;
	running_values = io_read16(running_player_values);
	player_vars = running_values;
	PLAYER_VALUES(player_vars)->kept_life = vitality;
}

/* The floor's height at the player's next place (carry when it is a wall). */
void player_floor_at_next_place(uint16_t player, uint16_t *p_floor_cell, uint32_t *p_wall)
{
	uint32_t wall = *p_wall;
	uint32_t negative = 0;
	uint8_t floor_low = 0, floor_value = 0;
	uint16_t floor_cell = 0, object = 0;

	object = player;
	vector_floor_ahead(object, &floor_cell, &negative);
	floor_value = (uint8_t)(floor_cell >> 8);
	floor_low = (uint8_t)floor_cell;
	if (floor_value == 0xFFu)
	{
		wall = 1u;
		floor_cell = ((uint32_t)(uint8_t)~floor_value << 8) | floor_low;
	}
	else
	{
		wall = 0u;
		floor_cell = (uint8_t)((((floor_value & 0xFu) << 1) << 1) << 1);
	}
	*p_floor_cell = floor_cell;
	*p_wall = wall;
}

/* Stops the player: no x, y or height speed. */
void player_stop(uint16_t player)
{
	OBJECT(player)->x_speed = 0;
	OBJECT(player)->y_speed = 0;
	OBJECT(player)->z_speed = 0;
}

/* Steers the player by the joystick in A: its x speed and facing from player_walk_velocities, then its y
   speed and the scroll. */
uint16_t player_steer(uint16_t player, uint16_t joystick)
{
	uint8_t x_speed_high = 0, x_speed_low = 0;
	uint16_t velocity = 0;
	uint8_t facing_left_bit = 0;
	uint8_t attributes = 0;
	uint16_t velocity_record = 0, x_speed = 0;

	velocity_record = player_walk_velocities_ADDRESS + (uint8_t)((((joystick >> 8) & 0xFu) << 1) << 1);
	velocity = velocity_record + 2u;
	x_speed = VELOCITY(velocity_record)->x_speed;
	x_speed_low = (uint8_t)x_speed;
	x_speed_high = (uint8_t)(x_speed >> 8);
	if (x_speed == 0u)
	{
		player_request_scroll(velocity, player);
		return velocity;
	}
	OBJECT(player)->x_speed = ((uint32_t)x_speed_high << 8) | (x_speed_low & 0xFFu);
	facing_left_bit = x_speed_high & 0x40u;
	attributes = OBJECT(player)->attributes;
	OBJECT(player)->attributes = (attributes & 0xBFu) | facing_left_bit;
	player_request_scroll(velocity, player);
	return velocity;
}

/* Sets the player's y speed from Y and asks the screen to scroll with it: x when it walks past the
   scroll line with no player behind, y likewise past 1840/1842. */
void player_request_scroll(uint16_t velocity, uint16_t player)
{
	uint8_t y_speed_high = 0, y_speed_low = 0;
	uint16_t others_line_y = 0, place_x = 0, place_y = 0, scroll_line_x = 0;
	uint8_t attributes = 0;
	uint16_t player_x = 0, x_speed = 0, player_y = 0, y_speed = 0, new_y_speed = 0, upper_scroll_line = 0, upper_others_line = 0, y_speed_2 = 0, push_sum = 0, lower_scroll_line = 0, lower_others_line = 0;

	player_x = OBJECT(player)->x;
	place_x = player_x;
	attributes = OBJECT(player)->attributes;
	if ((attributes & 0x40u) != 0u)
	{
		if ((int16_t)place_x < 0xC0)
		{
			scroll_line_x = 0x118u;
			if ((OBJECT(OBJECT_ADDRESS(0))->flags == 0u || (int16_t)OBJECT(OBJECT_ADDRESS(0))->x < (int16_t)scroll_line_x) && (OBJECT(OBJECT_ADDRESS(2))->flags == 0u || (int16_t)OBJECT(OBJECT_ADDRESS(2))->x < (int16_t)scroll_line_x) && (OBJECT(OBJECT_ADDRESS(4))->flags == 0u || (int16_t)OBJECT(OBJECT_ADDRESS(4))->x < (int16_t)scroll_line_x) && (OBJECT(OBJECT_ADDRESS(6))->flags == 0u || (int16_t)OBJECT(OBJECT_ADDRESS(6))->x < (int16_t)scroll_line_x))
			{
				x_speed = OBJECT(player)->x_speed;
				players_push_x = x_speed;
			}
		}
	}
	else if ((int16_t)place_x > 0x100)
	{
		scroll_line_x = 0x98u;
		if ((OBJECT(OBJECT_ADDRESS(0))->flags == 0u || (int16_t)scroll_line_x < (int16_t)OBJECT(OBJECT_ADDRESS(0))->x) && (OBJECT(OBJECT_ADDRESS(2))->flags == 0u || (int16_t)scroll_line_x < (int16_t)OBJECT(OBJECT_ADDRESS(2))->x) && (OBJECT(OBJECT_ADDRESS(4))->flags == 0u || (int16_t)scroll_line_x < (int16_t)OBJECT(OBJECT_ADDRESS(4))->x) && (OBJECT(OBJECT_ADDRESS(6))->flags == 0u || (int16_t)scroll_line_x < (int16_t)OBJECT(OBJECT_ADDRESS(6))->x))
		{
			x_speed = OBJECT(player)->x_speed;
			players_push_x = x_speed;
		}
	}
	player_y = OBJECT(player)->y;
	place_y = player_y;
	y_speed = VELOCITY(velocity - 0x2u)->y_speed;
	y_speed_high = (uint8_t)(y_speed >> 8);
	y_speed_low = (uint8_t)y_speed;
	new_y_speed = ((uint32_t)y_speed_high << 8) | y_speed_low;
	OBJECT(player)->y_speed = new_y_speed;
	if (new_y_speed == 0u)
		return;
	if ((int16_t)(((uint32_t)y_speed_high << 8) | y_speed_low) < 0)
	{
		upper_scroll_line = io_read16(bonus_results_state);
		if ((int16_t)place_y < (int16_t)upper_scroll_line)
		{
			upper_others_line = io_read16(results_last_result);
			others_line_y = upper_others_line;
			if ((OBJECT(OBJECT_ADDRESS(0))->flags == 0u || (int16_t)OBJECT(OBJECT_ADDRESS(0))->y < (int16_t)others_line_y) && (OBJECT(OBJECT_ADDRESS(2))->flags == 0u || (int16_t)OBJECT(OBJECT_ADDRESS(2))->y < (int16_t)others_line_y) && (OBJECT(OBJECT_ADDRESS(4))->flags == 0u || (int16_t)OBJECT(OBJECT_ADDRESS(4))->y < (int16_t)others_line_y) && (OBJECT(OBJECT_ADDRESS(6))->flags == 0u || (int16_t)OBJECT(OBJECT_ADDRESS(6))->y < (int16_t)others_line_y))
			{
				y_speed_2 = OBJECT(player)->y_speed;
				push_sum = y_speed_2 + players_push_y;
				players_push_y = push_sum;
			}
		}
	}
	else
	{
		lower_scroll_line = io_read16(bonus_2_state);
		if ((int16_t)lower_scroll_line < (int16_t)place_y)
		{
			lower_others_line = io_read16(results_place);
			others_line_y = lower_others_line;
			if ((OBJECT(OBJECT_ADDRESS(0))->flags == 0u || (int16_t)others_line_y < (int16_t)OBJECT(OBJECT_ADDRESS(0))->y) && (OBJECT(OBJECT_ADDRESS(2))->flags == 0u || (int16_t)others_line_y < (int16_t)OBJECT(OBJECT_ADDRESS(2))->y) && (OBJECT(OBJECT_ADDRESS(4))->flags == 0u || (int16_t)others_line_y < (int16_t)OBJECT(OBJECT_ADDRESS(4))->y) && (OBJECT(OBJECT_ADDRESS(6))->flags == 0u || (int16_t)others_line_y < (int16_t)OBJECT(OBJECT_ADDRESS(6))->y))
			{
				y_speed_2 = OBJECT(player)->y_speed;
				push_sum = y_speed_2 + players_push_y;
				players_push_y = push_sum;
				return;
			}
		}
	}
}

/* Places the object in X at the offsets Y gives for the player's character (x turned by its facing, then
   its height). */
uint16_t player_place_carried(uint16_t carried, uint16_t offsets, uint16_t player)
{
	uint8_t height = 0, x_offset = 0;
	uint16_t height_address = 0;
	uint8_t kind = 0, attributes = 0;
	uint16_t kind_offsets = 0, x_offset_word = 0, player_x = 0, carried_x = 0;

	kind = OBJECT(player)->kind;
	kind_offsets = offsets + (int8_t)((uint32_t)kind << 1);
	height_address = kind_offsets + 1u;
	x_offset = mem_read8(kind_offsets);
	attributes = OBJECT(player)->attributes;
	if ((attributes & 0x40u) != 0u)
		x_offset = 0u - x_offset;
	x_offset_word = (int8_t)x_offset;
	player_x = OBJECT(player)->x;
	carried_x = x_offset_word + player_x;
	OBJECT(carried)->x = carried_x;
	height = mem_read8(height_address);
	player_place_carried_above(carried, player, height);
	return height_address;
}

/* Puts the carried object B above the player's height, just in front of it, with the player's speeds. */
void player_place_carried_above(uint16_t carried, uint16_t player, uint8_t height)
{
	uint8_t x_fraction = 0, y_fraction = 0, z_fraction = 0, animation_flags = 0;
	uint16_t height_word = 0, z = 0, carried_z = 0, player_y = 0, carried_y = 0, y_speed = 0, z_speed = 0;

	height_word = (int8_t)height;
	z = OBJECT(player)->z;
	carried_z = height_word + z;
	OBJECT(carried)->z = carried_z;
	player_y = OBJECT(player)->y;
	carried_y = player_y - 2u;
	OBJECT(carried)->y = carried_y;
	x_fraction = OBJECT(player)->x_fraction;
	OBJECT(carried)->x_fraction = x_fraction;
	y_fraction = OBJECT(player)->y_fraction;
	OBJECT(carried)->y_fraction = y_fraction;
	z_fraction = OBJECT(player)->z_fraction;
	OBJECT(carried)->z_fraction = z_fraction;
	y_speed = OBJECT(player)->y_speed;
	OBJECT(carried)->y_speed = y_speed;
	z_speed = OBJECT(player)->z_speed;
	OBJECT(carried)->z_speed = z_speed;
	animation_flags = OBJECT(carried)->animation_flags;
	OBJECT(carried)->animation_flags = animation_flags | 0x80u;
}

/* Undoes a team-up: both players standing (state 00, animation 80). */
void player_team_split(uint16_t partner, uint16_t player)
{
	OBJECT(player)->player.player_state = 0u;
	OBJECT(partner)->player.player_state = 0u;
	OBJECT(player)->animation = 0x80u;
	OBJECT(partner)->animation = 0x80u;
	player_team_release(partner, player);
}

/* Lets the two players of a team-up go: shown, no longer teamed, the partner on the same floor, each
   with its own shadow. */
void player_team_release(uint16_t partner, uint16_t player)
{
	uint8_t kind = 0, kind_2 = 0;
	uint16_t floor_z = 0;

	OBJECT(player)->flags |= 0x80u;
	OBJECT(partner)->flags |= 0x80u;
	OBJECT(player)->timer = 0u;
	OBJECT(player)->player.attack_started = 0u;
	OBJECT(partner)->timer = 0u;
	OBJECT(partner)->player.attack_started = 0u;
	OBJECT(player)->player.state_frames = 1u;
	OBJECT(player)->player.teamed = 0u;
	OBJECT(partner)->player.state_frames = 1u;
	OBJECT(partner)->player.teamed = 0u;
	OBJECT(player)->player.hold_presses = 0u;
	OBJECT(partner)->player.hold_presses = 0u;
	OBJECT(player)->player.team_spare = 0u;
	OBJECT(partner)->player.team_spare = 0u;
	floor_z = OBJECT(player)->floor_z;
	OBJECT(partner)->floor_z = floor_z;
	kind = OBJECT(player)->kind;
	OBJECT(player)->shadow_player = ((((uint32_t)kind << 1) << 1) << 1) << 1;
	kind_2 = OBJECT(partner)->kind;
	OBJECT(partner)->shadow_player = ((((uint32_t)kind_2 << 1) << 1) << 1) << 1;
}

/* The partner takes the player's speeds and place. */
void player_team_follow(uint16_t partner, uint16_t player)
{
	uint16_t x_speed = 0, y_speed = 0, z_speed = 0, player_x = 0, player_y = 0, z = 0;

	x_speed = OBJECT(player)->x_speed;
	OBJECT(partner)->x_speed = x_speed;
	y_speed = OBJECT(player)->y_speed;
	OBJECT(partner)->y_speed = y_speed;
	z_speed = OBJECT(player)->z_speed;
	OBJECT(partner)->z_speed = z_speed;
	player_x = OBJECT(player)->x;
	OBJECT(partner)->x = player_x;
	player_y = OBJECT(player)->y;
	OBJECT(partner)->y = player_y;
	z = OBJECT(player)->z;
	OBJECT(partner)->z = z;
}

/* Checks the player's next x against the screen's edges and the floor ahead: stops it with carry where
   it can not go, else takes that floor. */
void player_check_screen_edges(uint16_t player, uint32_t *p_no_crash, uint32_t *p_carry)
{
	uint32_t no_crash = *p_no_crash;
	uint32_t carry = *p_carry;
	uint32_t negative = 0;
	uint8_t floor_value = 0, height_high = 0, height_low = 0, next_x_high = 0, next_x_low = 0, stopped_flag = 0;
	uint16_t floor_cell = 0, floor_z = 0, left_limit = 0, object = 0, right_limit = 0;
	uint8_t floor_or_next_x_low = 0, floor_z_high = 0;
	uint8_t vitality = 0, vitality_2 = 0, attributes = 0, x_speed_2 = 0, x_high = 0;
	uint16_t z = 0, floor_height_byte = 0, z_2 = 0, x_speed = 0, x_and_fraction = 0, speed_word = 0;

	left_limit = 0x70u;
	right_limit = 0x140u;
	vitality = OBJECT(player)->vitality;
	if (vitality == 0u)
	{
		z = OBJECT(player)->z;
		if (z != 0u)
		{
			left_limit -= 0x16u;
			right_limit += 0x26u;
		}
	}
	screen_left_edge = left_limit;
	screen_right_edge = right_limit;
	object = player;
	vector_floor_ahead_x(object, &floor_cell, &negative);
	floor_value = (uint8_t)(floor_cell >> 8);
	if ((int8_t)floor_value < 0)
	{
		OBJECT(player)->x_speed = 0;
		OBJECT(player)->y_speed = 0;
		vitality_2 = OBJECT(player)->vitality;
		if (vitality_2 != 0u)
			stopped_flag = 0xFFu;
		else
			stopped_flag = 0u;
		carry = 1u;
		no_crash = (uint8_t)~stopped_flag == 0u;
	}
	else
	{
		edge_floor_priority = floor_value & 0x30u;
		attributes = OBJECT(player)->attributes;
		OBJECT(player)->attributes = (attributes & 0xCFu) | edge_floor_priority;
		floor_height_byte = (uint8_t)((((floor_value & 0xFu) << 1) << 1) << 1);
		height_high = (uint8_t)(floor_height_byte >> 8);
		height_low = (uint8_t)floor_height_byte;
		z_2 = OBJECT(player)->z;
		if ((int16_t)z_2 < (int16_t)(((uint32_t)height_high << 8) | height_low))
		{
			OBJECT(player)->x_speed = 0;
			OBJECT(player)->y_speed = 0;
			vitality_2 = OBJECT(player)->vitality;
			if (vitality_2 != 0u)
				stopped_flag = 0xFFu;
			else
				stopped_flag = 0u;
			carry = 1u;
			no_crash = (uint8_t)~stopped_flag == 0u;
		}
		else
		{
			floor_or_next_x_low = height_low;
			floor_z_high = height_high;
			floor_z = ((uint32_t)floor_z_high << 8) | floor_or_next_x_low;
			x_speed = OBJECT(player)->x_speed;
			x_and_fraction = (((uint32_t)(OBJECT(player)->x & 0xFFu) << 8u) | OBJECT(player)->x_fraction);
			speed_word = x_speed;
			carry = (uint16_t)(speed_word + x_and_fraction) < speed_word;
			floor_or_next_x_low = (uint16_t)(speed_word + x_and_fraction) >> 8;
			x_speed_2 = (uint8_t)(OBJECT(player)->x_speed >> 8u);
			x_high = (uint8_t)(OBJECT(player)->x >> 8u);
			next_x_high = ((uint16_t)(int8_t)x_speed_2 >> 8) + x_high + carry;
			next_x_low = floor_or_next_x_low;
			if ((int16_t)screen_left_edge <= (int16_t)(((uint32_t)next_x_high << 8) | next_x_low) && (int16_t)(((uint32_t)next_x_high << 8) | next_x_low) <= (int16_t)screen_right_edge)
			{
				OBJECT(player)->floor_z = floor_z;
				no_crash = 1u;
				carry = 0u;
			}
			else
			{
				OBJECT(player)->x_speed = 0;
				OBJECT(player)->y_speed = 0;
				vitality_2 = OBJECT(player)->vitality;
				if (vitality_2 != 0u)
					stopped_flag = 0xFFu;
				else
					stopped_flag = 0u;
				carry = 1u;
				no_crash = (uint8_t)~stopped_flag == 0u;
			}
		}
	}
	*p_no_crash = no_crash;
	*p_carry = carry;
}
