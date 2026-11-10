/**
 *    Name:        players/second_sprite.c
 *    Description: each player's second sprite (balloons, thrown things)
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    09-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the game's 053248 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

/* Runs each player's second sprite; in the last story moves the players in state 2C on */
uint16_t players_update_second_sprites(void)
{
	uint16_t held_object = 0, object = 0, player = 0, push_speed = 0;
	uint8_t t1 = 0, player_state = 0, t2 = 0;
	uint16_t held = 0;

	object = OBJECT_ADDRESS(0);
	player_second_sprite_run(object);
	object = OBJECT_ADDRESS(2);
	player_second_sprite_run(object);
	object = OBJECT_ADDRESS(4);
	player_second_sprite_run(object);
	player = OBJECT_ADDRESS(6);
	player_second_sprite_run(player);
	t1 = io_read8(0x184Du);
	if ((int8_t)t1 >= 2)
	{
		second_sprites_left = 4u;
		player = OBJECT_ADDRESS(0);
		do
		{
			player_state = OBJECT(player)->player.player_state;
			if (player_state == 0x2Cu)
			{
				OBJECT(player)->player.player_state = 0x2Du;
				OBJECT(player)->player.state_timer = 0xFu;
				held = OBJECT(player)->player.held;
				held_object = held;
				OBJECT(held_object)->state = 3u;
				OBJECT(held_object)->z = 0x20u;
				OBJECT(player)->animation = 0xCBu;
				OBJECT(player)->flags = 0x80u;
				OBJECT(player)->player.heavy_object_presses = 0u;
			}
			player += 0xC0u;
			t2 = second_sprites_left;
			second_sprites_left = t2 - 1u;
		} while (t2 != 1u);
	}
	if ((uint16_t)players_push_y == 0u)
		return player;
	if (players_push_y >= 0)
		push_speed = 0x200u;
	else
		push_speed = 0xFE00u;
	players_push_y = push_speed;
	return player;
}

/* Runs the second sprite of the player in U by its state */
void player_second_sprite_run(uint16_t object)
{
	uint8_t flags = 0, parameter = 0;

	flags = OBJECT(object + 0x60u)->flags;
	if (flags == 0u)
	{
		player_update_class(object);
		return;
	}
	parameter = OBJECT(object + 0x60u)->parameter;
	switch ((int8_t)(uint8_t)((uint32_t)parameter << 1))
	{
	case 0:
	case 22:
		player_update_class(object);
		return;
	case 2:
		player_second_sprite_balloon(object);
		return;
	case 4:
		player_second_sprite_start_balloon(object);
		return;
	case 6:
		player_second_sprite_blink(object);
		return;
	case 8:
		player_second_sprite_prompt(object);
		return;
	case 10:
		player_second_sprite_start_prompt(object);
		return;
	case 12:
		player_second_sprite_wait_animation(object);
		return;
	case 14:
		player_second_sprite_fly(object);
		return;
	case 16:
		player_second_sprite_throw_fast(object);
		return;
	case 18:
		player_second_sprite_fall(object);
		return;
	case 20:
		player_second_sprite_throw_slow(object);
		return;
	case 24:
		player_second_sprite_overhead(object);
		return;
	case 26:
		player_second_sprite_off(object);
		return;
	}
}

/* Puts the second sprite over the player's head */
void player_second_sprite_follow(uint16_t object)
{
	uint16_t t1 = 0, t2 = 0, z = 0;

	t1 = OBJECT(object)->x;
	OBJECT(object + 0x60u)->x = t1;
	t2 = OBJECT(object)->y;
	OBJECT(object + 0x60u)->y = t2 - 0x40u;
	z = OBJECT(object)->z;
	OBJECT(object + 0x60u)->z = z + 0x80u;
}

/* Gives the second sprite the player's speeds */
void player_second_sprite_match_speeds(uint16_t object)
{
	uint16_t x_speed = 0, y_speed = 0, z_speed = 0;

	x_speed = OBJECT(object)->x_speed;
	OBJECT(object + 0x60u)->x_speed = x_speed;
	y_speed = OBJECT(object)->y_speed;
	OBJECT(object + 0x60u)->y_speed = y_speed;
	z_speed = OBJECT(object)->z_speed;
	OBJECT(object + 0x60u)->z_speed = z_speed;
}

/* Holds the second sprite above the player at its character's height */
void player_second_sprite_overhead(uint16_t object)
{
	uint8_t kind = 0;
	uint16_t t1 = 0, t2 = 0, z = 0;

	t1 = OBJECT(object)->x;
	OBJECT(object + 0x60u)->x = t1;
	t2 = OBJECT(object)->y;
	OBJECT(object + 0x60u)->y = t2 - 0x7Fu;
	z = OBJECT(object)->z;
	kind = OBJECT(object)->kind;
	OBJECT(object + 0x60u)->z = z + (int8_t)player_overhead_heights[(int8_t)kind] + 0x7Fu;
	player_second_sprite_match_speeds(object);
	player_update_class(object);
}

/* Throws the second sprite fast (x speed 0A00) */
void player_second_sprite_throw_fast(uint16_t object)
{
	uint16_t damage = 0, x_speed = 0;

	OBJECT(object + 0x60u)->flags = 0xC0u;
	damage = 0x411u;
	x_speed = 0xA00u;
	player_second_sprite_throw(x_speed, object, damage);
}

/* Throws the second sprite slowly (x speed 0300) */
void player_second_sprite_throw_slow(uint16_t object)
{
	uint16_t damage = 0, x_speed = 0;

	OBJECT(object + 0x60u)->flags = 0xC8u;
	damage = 0x811u;
	x_speed = 0x300u;
	player_second_sprite_throw(x_speed, object, damage);
}

/* Starts the thrown thing from the player's side at its character's height */
void player_second_sprite_throw(uint16_t x_speed, uint16_t object, uint16_t damage)
{
	uint8_t dx = 0;
	uint8_t stack = 0, stack_2 = 0, stack_3 = 0;
	uint8_t attributes = 0, t1 = 0, attributes_2 = 0, kind = 0, parameter = 0;
	uint16_t t2 = 0, t3 = 0, t4 = 0, t5 = 0, z = 0;

	OBJECT(object + 0x60u)->damage = (uint8_t)(damage >> 8u);
	OBJECT(object + 0x60u)->attack = (uint8_t)damage;
	dx = 4u;
	attributes = OBJECT(object)->attributes;
	t1 = attributes & 0x40u;
	stack = t1;
	if (t1 != 0u)
	{
		stack_3 = x_speed >> 8;
		stack_2 = (uint8_t)x_speed;
		stack_3 = 0u - stack_3;
		x_speed = ((uint32_t)stack_3 << 8) | stack_2;
		dx = 0u - dx;
	}
	attributes_2 = OBJECT(object + 0x60u)->attributes;
	OBJECT(object + 0x60u)->attributes = (attributes_2 & 0xBFu) | stack;
	OBJECT(object + 0x60u)->x_speed = x_speed;
	OBJECT(object + 0x60u)->y_speed = 0;
	OBJECT(object + 0x60u)->z_speed = 0;
	t2 = (int8_t)dx;
	t3 = OBJECT(object)->x;
	t4 = t2 + t3;
	OBJECT(object + 0x60u)->x = t4;
	t5 = OBJECT(object)->y;
	OBJECT(object + 0x60u)->y = t5;
	kind = OBJECT(object)->kind;
	z = OBJECT(object)->z;
	OBJECT(object + 0x60u)->z = z + (int8_t)player_throw_heights[(int8_t)kind];
	OBJECT(object + 0x60u)->box_width = 4u;
	OBJECT(object + 0x60u)->box_depth = 4u;
	OBJECT(object + 0x60u)->box_height = 4u;
	parameter = OBJECT(object + 0x60u)->parameter;
	OBJECT(object + 0x60u)->parameter = parameter - 1u;
	player_second_sprite_fly(object);
}

/* The thrown thing flies until it hits something */
void player_second_sprite_fly(uint16_t object)
{
	uint8_t flags = 0;

	flags = OBJECT(object + 0x60u)->flags;
	if ((flags & 0x20u) == 0u)
	{
		player_second_sprite_fall(object);
		return;
	}
	player_second_sprite_land(object);
}

/* The thrown thing lands (kind 0E animation BF) and waits for its animation */
void player_second_sprite_land(uint16_t object)
{
	uint16_t t1 = 0, z = 0;

	OBJECT(object + 0x60u)->parameter = 6u;
	OBJECT(object + 0x60u)->kind = 0xEu;
	OBJECT(object + 0x60u)->animation = 0xBFu;
	t1 = OBJECT(object + 0x60u)->y;
	OBJECT(object + 0x60u)->y = t1 - 0x10u;
	z = OBJECT(object + 0x60u)->z;
	OBJECT(object + 0x60u)->z = z + 0x10u;
	OBJECT(object + 0x60u)->x_speed = 0;
	OBJECT(object + 0x60u)->y_speed = 0;
	OBJECT(object + 0x60u)->z_speed = 0;
	player_update_class(object);
}

/* The thrown thing falls until it leaves the screen or reaches the floor */
void player_second_sprite_fall(uint16_t object)
{
	uint32_t negative = 0;
	uint8_t floor_value = 0;
	uint16_t floor_cell = 0, object_2 = 0, sprite_x = 0;
	uint16_t t1 = 0, t2 = 0, z = 0;

	t1 = OBJECT(object + 0x60u)->x;
	sprite_x = t1;
	if ((int16_t)sprite_x <= 0x44 || (int16_t)sprite_x >= 0x17C)
	{
		player_second_sprite_off(object);
		return;
	}
	object_2 = object + 0x60u;
	vector_floor_ahead_x(object_2, &floor_cell, &negative);
	floor_value = (uint8_t)(floor_cell >> 8);
	if ((int8_t)floor_value < 0)
	{
		player_second_sprite_land(object);
		return;
	}
	t2 = (uint8_t)((((floor_value & 0xFu) << 1) << 1) << 1);
	z = OBJECT(object + 0x60u)->z;
	if ((int16_t)t2 <= (int16_t)z)
	{
		player_update_class(object);
		return;
	}
	player_second_sprite_land(object);
}

/* Off when its animation ends */
void player_second_sprite_wait_animation(uint16_t object)
{
	uint8_t animation_flags = 0;

	animation_flags = OBJECT(object + 0x60u)->animation_flags;
	if ((animation_flags & 1u) == 0u)
	{
		player_update_class(object);
		return;
	}
	player_second_sprite_off(object);
}

/* Starts the two-picture prompt over the player */
void player_second_sprite_start_prompt(uint16_t object)
{
	player_second_sprite_follow(object);
	OBJECT(object + 0x60u)->x_speed = 0;
	OBJECT(object + 0x60u)->y_speed = 0;
	OBJECT(object + 0x60u)->z_speed = 0;
	OBJECT(object + 0x60u)->parameter = 4u;
	OBJECT(object + 0x60u)->unk_3D = 1u;
	player_second_sprite_prompt(object);
}

/* Alternates the balloon's first two pictures over the player every 30 frames */
void player_second_sprite_prompt(uint16_t object)
{
	uint8_t prompt_animation = 0, prompt_kind = 0;
	uint8_t t1 = 0, animation_flags = 0, t2 = 0;
	uint32_t kind_halfword = 0, kind_halfword_2 = 0;

	OBJECT(object + 0x60u)->attributes = 0u;
	t1 = OBJECT(object + 0x60u)->unk_3D;
	OBJECT(object + 0x60u)->unk_3D = t1 - 1u;
	if (t1 == 1u)
	{
		OBJECT(object + 0x60u)->unk_3D = 0x3Cu;
		prompt_animation = 0x80u;
		prompt_kind = 0xB1u;
		kind_halfword = ((uint32_t)prompt_kind << 8) | (prompt_animation & 0xFFu);
		OBJECT(object + 0x60u)->kind = (uint8_t)(kind_halfword >> 8u);
		OBJECT(object + 0x60u)->animation = (uint8_t)kind_halfword;
		animation_flags = OBJECT(object)->animation_flags;
		OBJECT(object)->animation_flags = animation_flags & ~2u;
		player_update_class(object);
		return;
	}
	t2 = OBJECT(object + 0x60u)->unk_3D;
	if (t2 != 0x1Eu)
	{
		player_update_class(object);
		return;
	}
	prompt_animation = 0x81u;
	prompt_kind = 0xB1u;
	kind_halfword_2 = ((uint32_t)prompt_kind << 8) | (prompt_animation & 0xFFu);
	OBJECT(object + 0x60u)->kind = (uint8_t)(kind_halfword_2 >> 8u);
	OBJECT(object + 0x60u)->animation = (uint8_t)kind_halfword_2;
	animation_flags = OBJECT(object)->animation_flags;
	OBJECT(object)->animation_flags = animation_flags & ~2u;
	player_update_class(object);
}

/* Follows the player blinking until its time runs out */
void player_second_sprite_blink(uint16_t object)
{
	uint8_t blink_time = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0;

	player_second_sprite_follow(object);
	player_second_sprite_match_speeds(object);
	t1 = OBJECT(object + 0x60u)->unk_3E;
	OBJECT(object + 0x60u)->unk_3E = t1 - 1u;
	if (t1 == 1u)
	{
		player_second_sprite_off(object);
		return;
	}
	t2 = OBJECT(object + 0x60u)->unk_3E;
	t3 = t2 & 0x3Fu;
	blink_time = t3;
	if (t3 == 0u)
	{
		OBJECT(object + 0x60u)->flags = 0x80u;
		player_update_class(object);
		return;
	}
	if (blink_time != 0x10u)
	{
		player_update_class(object);
		return;
	}
	OBJECT(object + 0x60u)->flags = 4u;
	player_update_class(object);
}

/* Shows a speech balloon over the player (or over the pair's speaker) */
void player_second_sprite_start_balloon(uint16_t player)
{
	uint8_t balloon = 0, balloon_animation = 0;
	uint16_t partner = 0;
	uint8_t t1 = 0, t2 = 0, kind = 0, kind_2 = 0, kind_3 = 0;
	uint16_t partner_2 = 0;
	uint32_t kind_halfword = 0;

	t1 = io_read8(0x185Au);
	if (t1 != 0u)
	{
		player_second_sprite_off(player);
		return;
	}
	t2 = (uint8_t)OBJECT(player + 0x60u)->player.held;
	balloon = t2;
	balloon_animation = player_balloon_animations[(int8_t)balloon];
	if (balloon != 3u)
	{
		kind = OBJECT(player)->kind;
		balloon_animation += kind;
	}
	else
	{
		partner_2 = OBJECT(player)->player.partner;
		partner = partner_2;
		OBJECT(partner + 0x60u)->flags = 0u;
		OBJECT(partner + 0x60u)->parameter = 0u;
		kind_2 = OBJECT(partner)->kind;
		kind_3 = OBJECT(player)->kind;
		balloon_animation += pair_balloon_players[(int8_t)((uint8_t)((((uint32_t)kind_2 << 1) << 1) + kind_3))];
	}
	kind_halfword = 0xB100u | balloon_animation;
	OBJECT(player + 0x60u)->kind = (uint8_t)(kind_halfword >> 8u);
	OBJECT(player + 0x60u)->animation = (uint8_t)kind_halfword;
	OBJECT(player + 0x60u)->player.player_state = 1u;
	OBJECT(player + 0x60u)->player.heavy_object_presses = 0x50u;
	player_second_sprite_follow(player);
	OBJECT(player + 0x60u)->attributes = 0u;
	player_update_class(player);
}

/* Keeps the balloon over its speaker until its time runs out */
void player_second_sprite_balloon(uint16_t player)
{
	uint16_t d = 0, partner = 0;
	uint16_t stack = 0;
	uint8_t heavy_object_presses = 0, teamed = 0, team_direction = 0, t1 = 0, kind = 0;
	uint16_t partner_2 = 0, t2 = 0, t3 = 0, z = 0, x_speed = 0, y_speed = 0, z_speed = 0;

	heavy_object_presses = OBJECT(player + 0x60u)->player.heavy_object_presses;
	OBJECT(player + 0x60u)->player.heavy_object_presses = heavy_object_presses - 1u;
	if (heavy_object_presses == 1u)
	{
		player_second_sprite_off(player);
		return;
	}
	teamed = OBJECT(player)->player.teamed;
	if ((int8_t)teamed >= 0)
	{
		player_second_sprite_follow(player);
		player_second_sprite_match_speeds(player);
		player_update_class(player);
		return;
	}
	team_direction = OBJECT(player)->player.team_direction;
	if (team_direction != 0u)
	{
		player_second_sprite_follow(player);
		player_second_sprite_match_speeds(player);
		player_update_class(player);
		return;
	}
	partner_2 = OBJECT(player)->player.partner;
	t1 = mem_read8(partner_2 + 4u);
	kind = OBJECT(player)->kind;
	d = ((uint32_t)pair_balloon_players[(int8_t)((uint16_t)((uint32_t)(uint8_t)(((uint16_t)((uint32_t)(uint8_t)((uint32_t)((uint16_t)((uint32_t)(uint8_t)((uint32_t)((uint16_t)((uint32_t)t1 << 8) >> 8) << 1) << 8) >> 8) << 1) << 8) >> 8) + kind) << 8) >> 8)] << 8) | 0xC0u;
	stack = (uint32_t)(d >> 8) * (uint8_t)d + OBJECT_ADDRESS(0);
	partner = stack;
	t2 = OBJECT(partner)->x;
	OBJECT(player + 0x60u)->x = t2;
	t3 = OBJECT(partner)->y;
	OBJECT(player + 0x60u)->y = t3 - 0x40u;
	z = OBJECT(partner)->z;
	OBJECT(player + 0x60u)->z = z + 0x80u;
	x_speed = OBJECT(partner)->x_speed;
	OBJECT(player + 0x60u)->x_speed = x_speed;
	y_speed = OBJECT(partner)->y_speed;
	OBJECT(player + 0x60u)->y_speed = y_speed;
	z_speed = OBJECT(partner)->z_speed;
	OBJECT(player + 0x60u)->z_speed = z_speed;
	player_update_class(player);
}

/* Turns the second sprite off */
void player_second_sprite_off(uint16_t object)
{
	OBJECT(object + 0x60u)->flags = 0u;
	OBJECT(object + 0x60u)->parameter = 0u;
	player_update_class(object);
}

/* Each frame: the player's class by its state (player_state_classes) into its field 02 */
void player_update_class(uint16_t player)
{
	uint8_t shadow_player = 0, vitality = 0, player_state = 0;

	shadow_player = OBJECT(player)->shadow_player;
	OBJECT(player + 0x60u)->shadow_player = shadow_player & 0x30u;
	vitality = OBJECT(player)->vitality;
	OBJECT(player)->player.last_life = vitality;
	player_state = OBJECT(player)->player.player_state;
	OBJECT(player)->state = player_state_classes[(int8_t)player_state];
}
