/**
 *    Name:        players/motion.c
 *    Description: a player's motion against walls, floors, the screen's edges and the scroll, and helpers on its speeds and partner
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    09-11-2026
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
	uint32_t zero = 0, negative = 0, overflow = 0, carry = 0;
	uint8_t a = 0, b = 0;
	uint16_t floor_cell = 0, mover = 0, object = 0, right_limit = 0;
	uint8_t stack = 0;
	uint8_t teamed = 0, y_speed_2 = 0, t3 = 0, x_speed_2 = 0, t6 = 0, vitality = 0, vitality_2 = 0, t7 = 0, attributes = 0, vitality_3 = 0;
	uint16_t partner = 0, t1 = 0, y_speed = 0, t2 = 0, t4 = 0, x_speed = 0, t5 = 0, x_speed_3 = 0, t8 = 0;

	teamed = OBJECT(player)->player.teamed;
	if ((int8_t)teamed >= 0)
		mover = player;
	else
	{
		partner = OBJECT(player)->player.partner;
		mover = partner;
	}
	t1 = (((uint32_t)(OBJECT(player)->y & 0xFFu) << 8u) | OBJECT(player)->y_fraction);
	y_speed = OBJECT(player)->y_speed;
	t2 = t1;
	carry = (uint16_t)(t2 + y_speed) < t2;
	stack = (uint16_t)(t2 + y_speed) >> 8;
	y_speed_2 = (uint8_t)(OBJECT(player)->y_speed >> 8u);
	t3 = (uint8_t)(OBJECT(player)->y >> 8u);
	if ((int16_t)(((uint32_t)(uint8_t)(((uint16_t)(int8_t)y_speed_2 >> 8) + t3 + carry) << 8) | stack) < 0x98)
	{
		OBJECT(player)->y_speed = 0;
		OBJECT(mover)->y_speed = 0;
	}
	t4 = (((uint32_t)(OBJECT(player)->x & 0xFFu) << 8u) | OBJECT(player)->x_fraction);
	x_speed = OBJECT(player)->x_speed;
	t5 = t4;
	carry = (uint16_t)(t5 + x_speed) < t5;
	stack = (uint16_t)(t5 + x_speed) >> 8;
	x_speed_2 = (uint8_t)(OBJECT(player)->x_speed >> 8u);
	t6 = (uint8_t)(OBJECT(player)->x >> 8u);
	a = ((uint16_t)(int8_t)x_speed_2 >> 8) + t6 + carry;
	b = stack;
	vitality = OBJECT(player)->vitality;
	if (vitality == 0u)
	{
		if ((int16_t)(((uint32_t)a << 8) | b) >= 0x5A)
		{
			right_limit = 0x140u;
			vitality_2 = OBJECT(player)->vitality;
			if (vitality_2 != 0u)
			{
				stack = a;
				t7 = scene;
				a = stack;
				if (t7 == 4u)
					right_limit = 0x150u;
			}
			else
				right_limit += 0x26u;
			player_x_limit = right_limit;
			if ((int16_t)player_x_limit < (int16_t)(((uint32_t)a << 8) | b))
				OBJECT(player)->x_speed = 0;
		}
		else
			OBJECT(player)->x_speed = 0;
	}
	else if ((int16_t)(((uint32_t)a << 8) | b) >= 0x70)
	{
		right_limit = 0x140u;
		vitality_2 = OBJECT(player)->vitality;
		if (vitality_2 != 0u)
		{
			stack = a;
			t7 = scene;
			a = stack;
			if (t7 == 4u)
				right_limit = 0x150u;
		}
		else
			right_limit += 0x26u;
		player_x_limit = right_limit;
		if ((int16_t)player_x_limit < (int16_t)(((uint32_t)a << 8) | b))
			OBJECT(player)->x_speed = 0;
	}
	else
		OBJECT(player)->x_speed = 0;
	object = player;
	vector_floor_ahead(object, &floor_cell, &negative);
	a = (uint8_t)(floor_cell >> 8);
	if ((int8_t)a >= 0)
	{
		player_floor_against_height(player, &floor_cell, &zero, &negative, &overflow);
		a = (uint8_t)(floor_cell >> 8);
		b = (uint8_t)floor_cell;
		if ((negative ^ overflow) | zero)
		{
			OBJECT(player)->floor_z = ((uint32_t)a << 8) | b;
			attributes = OBJECT(player)->attributes;
			OBJECT(player)->attributes = (attributes & 0xCFu) | player_floor_priority;
			x_speed_3 = OBJECT(player)->x_speed;
			OBJECT(mover)->x_speed = x_speed_3;
			vitality_3 = OBJECT(player)->vitality;
			t8 = io_read16(0x1848u);
			mem_write8(t8 + 2u, vitality_3);
			return;
		}
	}
	object = player;
	vector_floor_ahead_x(object, &floor_cell, &negative);
	a = (uint8_t)(floor_cell >> 8);
	if ((int8_t)a >= 0)
	{
		player_floor_against_height(player, &floor_cell, &zero, &negative, &overflow);
		a = (uint8_t)(floor_cell >> 8);
		b = (uint8_t)floor_cell;
		if ((negative ^ overflow) | zero)
		{
			OBJECT(player)->y_speed = 0;
			OBJECT(mover)->y_speed = 0;
			OBJECT(player)->floor_z = ((uint32_t)a << 8) | b;
			attributes = OBJECT(player)->attributes;
			OBJECT(player)->attributes = (attributes & 0xCFu) | player_floor_priority;
			x_speed_3 = OBJECT(player)->x_speed;
			OBJECT(mover)->x_speed = x_speed_3;
			vitality_3 = OBJECT(player)->vitality;
			t8 = io_read16(0x1848u);
			mem_write8(t8 + 2u, vitality_3);
			return;
		}
	}
	OBJECT(player)->x_speed = 0;
	object = player;
	vector_floor_ahead_y(object, &floor_cell, &negative);
	a = (uint8_t)(floor_cell >> 8);
	if ((int8_t)a < 0)
	{
		OBJECT(player)->y_speed = 0;
		OBJECT(mover)->y_speed = 0;
		x_speed_3 = OBJECT(player)->x_speed;
		OBJECT(mover)->x_speed = x_speed_3;
		vitality_3 = OBJECT(player)->vitality;
		t8 = io_read16(0x1848u);
		mem_write8(t8 + 2u, vitality_3);
		return;
	}
	player_floor_against_height(player, &floor_cell, &zero, &negative, &overflow);
	a = (uint8_t)(floor_cell >> 8);
	b = (uint8_t)floor_cell;
	if ((negative ^ overflow) | zero)
	{
		OBJECT(player)->floor_z = ((uint32_t)a << 8) | b;
		attributes = OBJECT(player)->attributes;
		OBJECT(player)->attributes = (attributes & 0xCFu) | player_floor_priority;
		x_speed_3 = OBJECT(player)->x_speed;
		OBJECT(mover)->x_speed = x_speed_3;
		vitality_3 = OBJECT(player)->vitality;
		t8 = io_read16(0x1848u);
		mem_write8(t8 + 2u, vitality_3);
		return;
	}
	OBJECT(player)->y_speed = 0;
	OBJECT(mover)->y_speed = 0;
	x_speed_3 = OBJECT(player)->x_speed;
	OBJECT(mover)->x_speed = x_speed_3;
	vitality_3 = OBJECT(player)->vitality;
	t8 = io_read16(0x1848u);
	mem_write8(t8 + 2u, vitality_3);
}

/* The floor height (8 a step) of the block flags in A against the player's height; their priority bits
   in F2. */
void player_floor_against_height(uint16_t player, uint16_t *p_floor_cell, uint32_t *p_zero, uint32_t *p_negative, uint32_t *p_overflow)
{
	uint16_t floor_cell = (uint16_t)*p_floor_cell;
	uint32_t zero = *p_zero;
	uint32_t negative = *p_negative;
	uint32_t overflow = *p_overflow;
	uint8_t a = 0, b = 0;
	uint16_t floor_height = 0;
	uint16_t t1 = 0, z = 0, t2 = 0, t3 = 0;

	a = (uint8_t)(floor_cell >> 8);
	player_floor_priority = a & 0x30u;
	t1 = (uint8_t)((((a & 0xFu) << 1) << 1) << 1);
	a = (uint8_t)(t1 >> 8);
	b = (uint8_t)t1;
	z = OBJECT(player)->z;
	t2 = ((uint32_t)a << 8) | b;
	t3 = t2 - z;
	negative = t3 >> 15;
	zero = t3 == 0u;
	overflow = (uint32_t)t2 - (int16_t)z != (uint32_t)(int16_t)(t2 - z);
	floor_height = ((uint32_t)a << 8) | b;
	*p_floor_cell = floor_height;
	*p_zero = zero;
	*p_negative = negative;
	*p_overflow = overflow;
}

/* Keeps the player's life in its record (the state of states 01, 2E, 39 and 3F, which do nothing else). */
void player_keep_life(uint16_t player)
{
	uint8_t vitality = 0;
	uint16_t t1 = 0;

	vitality = OBJECT(player)->vitality;
	t1 = io_read16(0x1848u);
	mem_write8(t1 + 2u, vitality);
}

/* The floor's height at the player's next place (carry when it is a wall). */
void player_floor_at_next_place(uint16_t player, uint16_t *p_floor_cell, uint32_t *p_carry)
{
	uint32_t carry = *p_carry;
	uint32_t negative = 0;
	uint8_t b = 0, floor_value = 0;
	uint16_t floor_cell = 0, object = 0;

	object = player;
	vector_floor_ahead(object, &floor_cell, &negative);
	floor_value = (uint8_t)(floor_cell >> 8);
	b = (uint8_t)floor_cell;
	if (floor_value == 0xFFu)
	{
		carry = 1u;
		floor_cell = ((uint32_t)(uint8_t)~floor_value << 8) | b;
	}
	else
	{
		carry = 0u;
		floor_cell = (uint8_t)((((floor_value & 0xFu) << 1) << 1) << 1);
	}
	*p_floor_cell = floor_cell;
	*p_carry = carry;
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
	uint8_t stack = 0;
	uint8_t attributes = 0;
	uint16_t t1 = 0, x_speed = 0;

	t1 = player_walk_velocities_ADDRESS + (uint8_t)((((joystick >> 8) & 0xFu) << 1) << 1);
	velocity = t1 + 2u;
	x_speed = VELOCITY(t1)->x_speed;
	x_speed_low = (uint8_t)x_speed;
	x_speed_high = (uint8_t)(x_speed >> 8);
	if (x_speed == 0u)
	{
		player_request_scroll(velocity, player);
		return velocity;
	}
	OBJECT(player)->x_speed = ((uint32_t)x_speed_high << 8) | (x_speed_low & 0xFFu);
	stack = x_speed_high & 0x40u;
	attributes = OBJECT(player)->attributes;
	OBJECT(player)->attributes = (attributes & 0xBFu) | stack;
	player_request_scroll(velocity, player);
	return velocity;
}

/* Sets the player's y speed from Y and asks the screen to scroll with it: x when it walks past the
   scroll line with no player behind, y likewise past 1840/1842. */
void player_request_scroll(uint16_t velocity, uint16_t player)
{
	uint8_t a = 0, b = 0;
	uint16_t x = 0;
	uint8_t attributes = 0;
	uint16_t t1 = 0, x_speed = 0, t2 = 0, y_speed = 0, t3 = 0, t4 = 0, t5 = 0, y_speed_2 = 0, t6 = 0, t7 = 0, t8 = 0;

	t1 = OBJECT(player)->x;
	x = t1;
	attributes = OBJECT(player)->attributes;
	if ((attributes & 0x40u) != 0u)
	{
		if ((int16_t)x < 0xC0)
		{
			x = 0x118u;
			if ((OBJECT(OBJECT_ADDRESS(0))->flags == 0u || (int16_t)OBJECT(OBJECT_ADDRESS(0))->x < (int16_t)x) && (OBJECT(OBJECT_ADDRESS(2))->flags == 0u || (int16_t)OBJECT(OBJECT_ADDRESS(2))->x < (int16_t)x) && (OBJECT(OBJECT_ADDRESS(4))->flags == 0u || (int16_t)OBJECT(OBJECT_ADDRESS(4))->x < (int16_t)x) && (OBJECT(OBJECT_ADDRESS(6))->flags == 0u || (int16_t)OBJECT(OBJECT_ADDRESS(6))->x < (int16_t)x))
			{
				x_speed = OBJECT(player)->x_speed;
				players_push_x = x_speed;
			}
		}
	}
	else if ((int16_t)x > 0x100)
	{
		x = 0x98u;
		if ((OBJECT(OBJECT_ADDRESS(0))->flags == 0u || (int16_t)x < (int16_t)OBJECT(OBJECT_ADDRESS(0))->x) && (OBJECT(OBJECT_ADDRESS(2))->flags == 0u || (int16_t)x < (int16_t)OBJECT(OBJECT_ADDRESS(2))->x) && (OBJECT(OBJECT_ADDRESS(4))->flags == 0u || (int16_t)x < (int16_t)OBJECT(OBJECT_ADDRESS(4))->x) && (OBJECT(OBJECT_ADDRESS(6))->flags == 0u || (int16_t)x < (int16_t)OBJECT(OBJECT_ADDRESS(6))->x))
		{
			x_speed = OBJECT(player)->x_speed;
			players_push_x = x_speed;
		}
	}
	t2 = OBJECT(player)->y;
	x = t2;
	y_speed = VELOCITY(velocity - 0x2u)->y_speed;
	a = (uint8_t)(y_speed >> 8);
	b = (uint8_t)y_speed;
	t3 = ((uint32_t)a << 8) | b;
	OBJECT(player)->y_speed = t3;
	if (t3 == 0u)
		return;
	if ((int16_t)(((uint32_t)a << 8) | b) < 0)
	{
		t4 = io_read16(0x1842u);
		if ((int16_t)x < (int16_t)t4)
		{
			t5 = io_read16(0x1844u);
			x = t5;
			if ((OBJECT(OBJECT_ADDRESS(0))->flags == 0u || (int16_t)OBJECT(OBJECT_ADDRESS(0))->y < (int16_t)x) && (OBJECT(OBJECT_ADDRESS(2))->flags == 0u || (int16_t)OBJECT(OBJECT_ADDRESS(2))->y < (int16_t)x) && (OBJECT(OBJECT_ADDRESS(4))->flags == 0u || (int16_t)OBJECT(OBJECT_ADDRESS(4))->y < (int16_t)x) && (OBJECT(OBJECT_ADDRESS(6))->flags == 0u || (int16_t)OBJECT(OBJECT_ADDRESS(6))->y < (int16_t)x))
			{
				y_speed_2 = OBJECT(player)->y_speed;
				t6 = y_speed_2 + players_push_y;
				players_push_y = t6;
			}
		}
	}
	else
	{
		t7 = io_read16(0x1840u);
		if ((int16_t)t7 < (int16_t)x)
		{
			t8 = io_read16(0x1846u);
			x = t8;
			if ((OBJECT(OBJECT_ADDRESS(0))->flags == 0u || (int16_t)x < (int16_t)OBJECT(OBJECT_ADDRESS(0))->y) && (OBJECT(OBJECT_ADDRESS(2))->flags == 0u || (int16_t)x < (int16_t)OBJECT(OBJECT_ADDRESS(2))->y) && (OBJECT(OBJECT_ADDRESS(4))->flags == 0u || (int16_t)x < (int16_t)OBJECT(OBJECT_ADDRESS(4))->y) && (OBJECT(OBJECT_ADDRESS(6))->flags == 0u || (int16_t)x < (int16_t)OBJECT(OBJECT_ADDRESS(6))->y))
			{
				y_speed_2 = OBJECT(player)->y_speed;
				t6 = y_speed_2 + players_push_y;
				players_push_y = t6;
				return;
			}
		}
	}
}

/* Places the object in X at the offsets Y gives for the player's character (x turned by its facing, then
   its height). */
uint16_t player_place_carried(uint16_t carried, uint16_t offsets, uint16_t player)
{
	uint8_t b = 0, height = 0;
	uint16_t y = 0;
	uint8_t kind = 0, attributes = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0, t4 = 0;

	kind = OBJECT(player)->kind;
	t1 = offsets + (int8_t)((uint32_t)kind << 1);
	y = t1 + 1u;
	b = mem_read8(t1);
	attributes = OBJECT(player)->attributes;
	if ((attributes & 0x40u) != 0u)
		b = 0u - b;
	t2 = (int8_t)b;
	t3 = OBJECT(player)->x;
	t4 = t2 + t3;
	OBJECT(carried)->x = t4;
	height = mem_read8(y);
	player_place_carried_above(carried, player, height);
	return y;
}

/* Puts the carried object B above the player's height, just in front of it, with the player's speeds. */
void player_place_carried_above(uint16_t carried, uint16_t player, uint8_t height)
{
	uint8_t x_fraction = 0, y_fraction = 0, z_fraction = 0, animation_flags = 0;
	uint16_t t1 = 0, z = 0, t2 = 0, t3 = 0, t4 = 0, y_speed = 0, z_speed = 0;

	t1 = (int8_t)height;
	z = OBJECT(player)->z;
	t2 = t1 + z;
	OBJECT(carried)->z = t2;
	t3 = OBJECT(player)->y;
	t4 = t3 - 2u;
	OBJECT(carried)->y = t4;
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
	uint16_t x_speed = 0, y_speed = 0, z_speed = 0, t1 = 0, t2 = 0, z = 0;

	x_speed = OBJECT(player)->x_speed;
	OBJECT(partner)->x_speed = x_speed;
	y_speed = OBJECT(player)->y_speed;
	OBJECT(partner)->y_speed = y_speed;
	z_speed = OBJECT(player)->z_speed;
	OBJECT(partner)->z_speed = z_speed;
	t1 = OBJECT(player)->x;
	OBJECT(partner)->x = t1;
	t2 = OBJECT(player)->y;
	OBJECT(partner)->y = t2;
	z = OBJECT(player)->z;
	OBJECT(partner)->z = z;
}

/* Checks the player's next x against the screen's edges and the floor ahead: stops it with carry where
   it can not go, else takes that floor. */
void player_check_screen_edges(uint16_t player, uint32_t *p_zero, uint32_t *p_carry)
{
	uint32_t zero = *p_zero;
	uint32_t carry = *p_carry;
	uint32_t negative = 0;
	uint8_t a = 0, b = 0;
	uint16_t floor_cell = 0, floor_z = 0, left_limit = 0, object = 0, right_limit = 0;
	uint8_t stack = 0, stack_2 = 0;
	uint8_t vitality = 0, vitality_2 = 0, attributes = 0, x_speed_2 = 0, t4 = 0;
	uint16_t z = 0, t1 = 0, z_2 = 0, x_speed = 0, t2 = 0, t3 = 0;

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
	a = (uint8_t)(floor_cell >> 8);
	if ((int8_t)a < 0)
	{
		OBJECT(player)->x_speed = 0;
		OBJECT(player)->y_speed = 0;
		vitality_2 = OBJECT(player)->vitality;
		if (vitality_2 != 0u)
			a = 0xFFu;
		else
			a = 0u;
		carry = 1u;
		zero = (uint8_t)~a == 0u;
	}
	else
	{
		edge_floor_priority = a & 0x30u;
		attributes = OBJECT(player)->attributes;
		OBJECT(player)->attributes = (attributes & 0xCFu) | edge_floor_priority;
		t1 = (uint8_t)((((a & 0xFu) << 1) << 1) << 1);
		a = (uint8_t)(t1 >> 8);
		b = (uint8_t)t1;
		z_2 = OBJECT(player)->z;
		if ((int16_t)z_2 < (int16_t)(((uint32_t)a << 8) | b))
		{
			OBJECT(player)->x_speed = 0;
			OBJECT(player)->y_speed = 0;
			vitality_2 = OBJECT(player)->vitality;
			if (vitality_2 != 0u)
				a = 0xFFu;
			else
				a = 0u;
			carry = 1u;
			zero = (uint8_t)~a == 0u;
		}
		else
		{
			stack = b;
			stack_2 = a;
			floor_z = ((uint32_t)stack_2 << 8) | stack;
			x_speed = OBJECT(player)->x_speed;
			t2 = (((uint32_t)(OBJECT(player)->x & 0xFFu) << 8u) | OBJECT(player)->x_fraction);
			t3 = x_speed;
			carry = (uint16_t)(t3 + t2) < t3;
			stack = (uint16_t)(t3 + t2) >> 8;
			x_speed_2 = (uint8_t)(OBJECT(player)->x_speed >> 8u);
			t4 = (uint8_t)(OBJECT(player)->x >> 8u);
			a = ((uint16_t)(int8_t)x_speed_2 >> 8) + t4 + carry;
			b = stack;
			if ((int16_t)screen_left_edge <= (int16_t)(((uint32_t)a << 8) | b) && (int16_t)(((uint32_t)a << 8) | b) <= (int16_t)screen_right_edge)
			{
				OBJECT(player)->floor_z = floor_z;
				zero = 1u;
				carry = 0u;
			}
			else
			{
				OBJECT(player)->x_speed = 0;
				OBJECT(player)->y_speed = 0;
				vitality_2 = OBJECT(player)->vitality;
				if (vitality_2 != 0u)
					a = 0xFFu;
				else
					a = 0u;
				carry = 1u;
				zero = (uint8_t)~a == 0u;
			}
		}
	}
	*p_zero = zero;
	*p_carry = carry;
}
