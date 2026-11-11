/**
 *    Name:        players/reactions.c
 *    Description: what touches a player each frame: pickups, weapons, blows by their strength, another player's team-up
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    10-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the game's 053248 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

/* Every state's end: counts the blinking down after joining, takes what touched the player by its
   strength (a pickup, a weapon, a blow, or another player's offer of a team move, which teams the two up
   by their characters), and moves it. */
void player_take_touches(uint16_t kind, uint16_t player)
{
	uint32_t carry = 0;
	uint8_t box_width = 0, hit_kind = 0, move = 0;
	uint16_t balloon_value = 0, effect_state = 0, facing = 0, other = 0, partner = 0, player_vars = 0, team_member = 0, team_move = 0, team_sound = 0;
	uint16_t stack = 0;
	uint8_t blink_frames = 0, blink_frames_2 = 0, hit = 0, blink_frames_3 = 0, teamed = 0, teamed_2 = 0, hit_2 = 0, kind_2 = 0, team_move_number = 0, kind_3 = 0, kind_4 = 0, team_move_number_2 = 0, attributes = 0;
	uint16_t t1 = 0, hit_by = 0, team_move_record = 0, sound = 0, first_object_address = 0, first_object_offset = 0, first_direction_address = 0, second_object_offset = 0, second_direction_address = 0, second_x = 0, first_x = 0, partner_2 = 0, hit_offset = 0;

	blink_frames = OBJECT(player)->player.blink_frames;
	if (blink_frames != 0u)
	{
		blink_frames_2 = OBJECT(player)->player.blink_frames;
		OBJECT(player)->player.blink_frames = blink_frames_2 - 1u;
		if (blink_frames_2 == 1u)
		{
			OBJECT(player)->flags = 0xC0u;
			t1 = io_read16(0x1848u);
			player_vars = t1;
			PLAYER_VALUES(player_vars)->entry_status = 2u;
			effect_state = 0xD00u;
			carry = player_start_effect(kind, player, effect_state);
			player_check_motion(player);
			return;
		}
		player_blink(player);
		player_check_motion(player);
		return;
	}
	if ((OBJECT(player)->flags & 0x20u) == 0u)
	{
		player_check_motion(player);
		return;
	}
	hit = OBJECT(player)->hit;
	hit_kind = hit;
	if (hit == 0u)
	{
		player_check_motion(player);
		return;
	}
	if ((int8_t)hit_kind < -0x10)
	{
		if ((int8_t)hit_kind > -0x7D)
		{
			player_check_motion(player);
			return;
		}
		hit_by = OBJECT(player)->hit_by;
		other = hit_by;
		blink_frames_3 = OBJECT(other)->player.blink_frames;
		if (blink_frames_3 != 0u)
		{
			player_check_motion(player);
			return;
		}
		teamed = OBJECT(player)->player.teamed;
		if ((int8_t)teamed < 0)
		{
			player_check_motion(player);
			return;
		}
		teamed_2 = OBJECT(other)->player.teamed;
		if ((int8_t)teamed_2 < 0)
		{
			player_check_motion(player);
			return;
		}
		OBJECT(player)->player.heavy_object_presses = 0u;
		hit_2 = OBJECT(other)->hit;
		kind_2 = OBJECT(player)->kind;
		if ((uint8_t)(hit_2 + 0x80u) != kind_2)
		{
			player_check_motion(player);
			return;
		}
		team_move_number = OBJECT(player)->player.team_move_number;
		box_width = team_move_box_widths[(int8_t)team_move_number];
		OBJECT(player)->box_width = box_width;
		OBJECT(other)->box_width = box_width;
		player_stop(player);
		OBJECT(other)->x_speed = 0;
		OBJECT(other)->y_speed = 0;
		OBJECT(other)->z_speed = 0;
		OBJECT(player)->damage = 0u;
		OBJECT(player)->attack = 0u;
		OBJECT(other)->damage = 0u;
		OBJECT(other)->attack = 0u;
		OBJECT(player)->player.partner = other;
		OBJECT(other)->player.partner = player;
		kind_3 = OBJECT(player)->kind;
		kind_4 = OBJECT(other)->kind;
		team_move_record = team_moves_by_characters_ADDRESS + (uint8_t)(((((((uint32_t)kind_3 << 1) << 1) + kind_4) << 1) << 1) << 1);
		team_move = team_move_record + 1u;
		move = TEAM_MOVE(team_move_record)->move;
		OBJECT(player)->player.team_move_number = move;
		OBJECT(other)->player.team_move_number = move;
		OBJECT(player)->player.teamed = 0xFFu;
		OBJECT(other)->player.teamed = 0xFFu;
		OBJECT(player)->player.hold_presses = 0xFFu;
		OBJECT(other)->player.hold_presses = 0xFFu;
		sound = TEAM_MOVE(team_move - 0x1u)->sound;
		team_sound = sound;
		carry = vector_queue_sound(team_sound);
		first_object_address = team_move;
		first_object_offset = (uint32_t)TEAM_MOVE(first_object_address - 0x1u)->first_object << 2;
		team_member = OBJECT_ADDRESS(0) + first_object_offset;
		first_direction_address = first_object_address + 1u;
		team_move = first_direction_address + 1u;
		OBJECT(team_member)->target_direction = TEAM_MOVE(first_direction_address - 0x2u)->direction;
		team_move_number_2 = OBJECT(player)->player.team_move_number;
		OBJECT(team_member)->animation = team_move_number_2 - 0x20u;
		OBJECT(team_member)->parameter = 0x30u;
		stack = team_member;
		second_object_offset = (uint32_t)TEAM_MOVE(team_move - 0x3u)->second_object << 2;
		team_member = OBJECT_ADDRESS(0) + second_object_offset;
		second_direction_address = team_move - 1u;
		facing = second_direction_address;
		OBJECT(team_member)->target_direction = TEAM_MOVE(second_direction_address - 0x2u)->direction - 1u;
		OBJECT(team_member)->flags = 4u;
		OBJECT(team_member)->parameter = 0x39u;
		balloon_value = (team_sound & 0xFFu) | 0x300u;
		player_show_balloon(facing, player, balloon_value);
		second_x = OBJECT(team_member)->x;
		team_member = stack;
		facing += 4u;
		first_x = OBJECT(team_member)->x;
		if ((int16_t)second_x < (int16_t)first_x)
			facing++;
		attributes = OBJECT(team_member)->attributes;
		OBJECT(team_member)->attributes = (attributes & 0xBFu) | SECOND_OBJECT_FACING(facing);
		partner_2 = OBJECT(player)->player.partner;
		partner = partner_2;
		player_team_follow(partner, player);
		player_check_motion(player);
		return;
	}
	if ((int8_t)hit_kind >= 0x10)
	{
		player_check_motion(player);
		return;
	}
	hit_offset = (int8_t)((uint32_t)hit_kind << 1);
	switch ((int16_t)hit_offset)
	{
	case 0:
	case 22:
	case 24:
	case 30:
	case -32:
	case -30:
	case -28:
	case -26:
	case -6:
	case -4:
	case -2:
		player_check_motion(player);
		return;
	case 2:
		player_take_blow(player);
		return;
	case 4:
		player_take_heavy_blow(player);
		return;
	case 6:
		player_get_grabbed(player);
		return;
	case 8:
		player_take_stun_blow(player);
		return;
	case 10:
		player_take_stun_blow_2(kind, player);
		return;
	case 12:
		player_take_knockaway_blow(player);
		return;
	case 14:
		player_squash(player);
		return;
	case 16:
		player_take_fling_blow(player);
		return;
	case 18:
		player_take_knockdown_blow(player);
		return;
	case 20:
		player_knock_up(player);
		return;
	case 26:
		player_take_pose_blow(player);
		return;
	case -24:
	case -22:
		player_pick_up_item(player);
		return;
	case -20:
	case -18:
	case -16:
		player_pick_up_weapon(player);
		return;
	case -14:
	case -12:
	case -10:
	case -8:
		player_eat_food(player);
		return;
	}
}

/* A blow of strength 0C on the floor: holds the animation the hitter left in its field 44 for 32 frames
   (state 2A). */
void player_take_pose_blow(uint16_t player)
{
	uint8_t animation = 0;
	uint16_t command = 0;
	uint8_t pose_animation = 0;
	uint16_t z = 0, floor_z = 0;

	z = OBJECT(player)->z;
	floor_z = OBJECT(player)->floor_z;
	if ((int16_t)floor_z < (int16_t)z)
	{
		player_check_motion(player);
		return;
	}
	pose_animation = OBJECT(player)->player.pose_animation;
	animation = pose_animation;
	if (pose_animation == 0u)
	{
		player_check_motion(player);
		return;
	}
	OBJECT(player)->animation = animation;
	if (animation == 0x97u)
	{
		command = 0x3F28u;
		player_play_voice(player, command);
	}
	OBJECT(player)->player.player_state = 0x2Au;
	OBJECT(player)->player.state_timer = 0x20u;
	OBJECT(player)->x_speed = 0;
	OBJECT(player)->y_speed = 0;
	player_hurt_end(player);
}

/* Attack pressed on an item of strength F4 or F5: picks it up. */
void player_pick_up_item(uint16_t player)
{
	uint16_t held_object = 0, picked_up = 0;
	uint16_t stack = 0;
	uint8_t controls_pressed = 0, teamed = 0, state = 0, status = 0, teamed_2 = 0, held_high = 0;
	uint16_t held = 0, hit_by = 0, held_2 = 0;

	controls_pressed = OBJECT(player)->player.controls_pressed;
	if ((controls_pressed & 0x10u) != 0u)
	{
		held = OBJECT(player)->player.held;
		if (held == 0u)
		{
			teamed = OBJECT(player)->player.teamed;
			if ((int8_t)teamed >= 0)
			{
				hit_by = OBJECT(player)->hit_by;
				picked_up = hit_by;
				state = OBJECT(picked_up)->state;
				if (state == 2u)
				{
					player_check_motion(player);
					return;
				}
				stack = player;
				status = OBJECT(player)->player.status;
				OBJECT(player)->player.status = status & ~1u;
				teamed_2 = OBJECT(player)->player.teamed;
				if ((int8_t)teamed_2 >= 0)
				{
					OBJECT(player)->flags = 0x80u;
					OBJECT(player)->player.player_state = 0x1Du;
					OBJECT(player)->animation = 0xBEu;
				}
				OBJECT(picked_up)->state = 2u;
				OBJECT(picked_up)->throwable.carried = 1u;
				OBJECT(picked_up)->flags &= 0xBFu;
				player_stop(player);
				player = stack;
				held_2 = OBJECT(player)->player.held;
				held_object = held_2;
				if (held_2 != 0u)
				{
					held_high = (uint8_t)(OBJECT(player)->player.held >> 8u);
					if (held_high != 0u)
					{
						OBJECT(held_object)->x_speed = 0;
						OBJECT(held_object)->y_speed = 0;
						OBJECT(held_object)->z_speed = 0;
						player_check_motion(player);
						return;
					}
				}
			}
		}
	}
	player_check_motion(player);
}

/* Attack pressed on a weapon (strength F6-F8): takes it as weapon kind 6, 7 or 8 with 20 uses. */
void player_pick_up_weapon(uint16_t player)
{
	uint16_t held_object = 0, picked_up = 0;
	uint16_t stack = 0;
	uint8_t controls_pressed = 0, teamed = 0, state = 0, hit = 0, status = 0, teamed_2 = 0, held_high = 0;
	uint16_t held = 0, hit_by = 0, held_2 = 0;

	controls_pressed = OBJECT(player)->player.controls_pressed;
	if ((controls_pressed & 0x10u) != 0u)
	{
		held = OBJECT(player)->player.held;
		if (held == 0u)
		{
			teamed = OBJECT(player)->player.teamed;
			if ((int8_t)teamed >= 0)
			{
				hit_by = OBJECT(player)->hit_by;
				picked_up = hit_by;
				state = OBJECT(picked_up)->state;
				if (state == 2u)
				{
					player_check_motion(player);
					return;
				}
				OBJECT(player + 0x60u)->player.held = (OBJECT(player + 0x60u)->player.held & 0xFFu) | 0x1400u;
				hit = OBJECT(player)->hit;
				OBJECT(player)->player.held = (uint8_t)(hit + 0x10u);
				stack = player;
				status = OBJECT(player)->player.status;
				OBJECT(player)->player.status = status & ~1u;
				teamed_2 = OBJECT(player)->player.teamed;
				if ((int8_t)teamed_2 >= 0)
				{
					OBJECT(player)->flags = 0x80u;
					OBJECT(player)->player.player_state = 0x1Du;
					OBJECT(player)->animation = 0xBEu;
				}
				OBJECT(picked_up)->state = 2u;
				OBJECT(picked_up)->throwable.carried = 1u;
				OBJECT(picked_up)->flags &= 0xBFu;
				player_stop(player);
				player = stack;
				held_2 = OBJECT(player)->player.held;
				held_object = held_2;
				if (held_2 != 0u)
				{
					held_high = (uint8_t)(OBJECT(player)->player.held >> 8u);
					if (held_high != 0u)
					{
						OBJECT(held_object)->x_speed = 0;
						OBJECT(held_object)->y_speed = 0;
						OBJECT(held_object)->z_speed = 0;
						player_check_motion(player);
						return;
					}
				}
			}
		}
	}
	player_check_motion(player);
}

/* Food (strength F9-FC): its life goes up by pickup_vitality (at most 28), to the partner with less life
   when teamed, with its voice and a balloon; it picks it up (state 1D). */
void player_eat_food(uint16_t player)
{
	uint32_t zero = 0, carry = 0;
	uint8_t vitality = 0, vitality_2 = 0;
	uint16_t balloon_value = 0, command = 0, held_object = 0, partner = 0, picked_up = 0;
	uint8_t stack_3 = 0;
	uint16_t stack = 0;
	uint8_t state = 0, hit = 0, teamed = 0, vitality_3 = 0, vitality_4 = 0, vitality_5 = 0, status = 0, teamed_2 = 0, held_high = 0;
	uint16_t hit_by = 0, partner_2 = 0, held = 0;

	hit_by = OBJECT(player)->hit_by;
	picked_up = hit_by;
	state = OBJECT(picked_up)->state;
	if (state == 2u)
	{
		player_check_motion(player);
		return;
	}
	stack = player;
	hit = OBJECT(player)->hit;
	stack_3 = hit;
	teamed = OBJECT(player)->player.teamed;
	if ((int8_t)teamed < 0)
	{
		partner_2 = OBJECT(player)->player.partner;
		partner = partner_2;
		OBJECT(partner)->x_speed = 0;
		OBJECT(partner)->y_speed = 0;
		OBJECT(partner)->z_speed = 0;
		vitality_3 = OBJECT(player)->vitality;
		vitality = vitality_3;
		vitality_4 = OBJECT(partner)->vitality;
		zero = (uint8_t)(vitality - vitality_4) == 0u;
		carry = vitality < vitality_4;
		if (vitality_4 <= vitality && ((carry | zero) == 0u || (int8_t)random_number < 0))
			player = partner;
	}
	command = 0x3F0Cu;
	player_play_voice(player, command);
	balloon_value = 0x10Cu;
	player_show_balloon(picked_up, player, balloon_value);
	vitality_5 = OBJECT(player)->vitality;
	vitality_2 = vitality_5 + pickup_vitality[(int8_t)((uint8_t)(stack_3 + 7u))];
	if (vitality_2 > 0x28u)
		vitality_2 = 0x28u;
	OBJECT(player)->vitality = vitality_2;
	status = OBJECT(player)->player.status;
	OBJECT(player)->player.status = status & ~1u;
	teamed_2 = OBJECT(player)->player.teamed;
	if ((int8_t)teamed_2 >= 0)
	{
		OBJECT(player)->flags = 0x80u;
		OBJECT(player)->player.player_state = 0x1Du;
		OBJECT(player)->animation = 0xBEu;
	}
	OBJECT(picked_up)->state = 2u;
	OBJECT(picked_up)->throwable.carried = 1u;
	OBJECT(picked_up)->flags &= 0xBFu;
	player_stop(player);
	player = stack;
	held = OBJECT(player)->player.held;
	held_object = held;
	if (held != 0u)
	{
		held_high = (uint8_t)(OBJECT(player)->player.held >> 8u);
		if (held_high != 0u)
		{
			OBJECT(held_object)->x_speed = 0;
			OBJECT(held_object)->y_speed = 0;
			OBJECT(held_object)->z_speed = 0;
			player_check_motion(player);
			return;
		}
	}
	player_check_motion(player);
}

/* A blow of strength 07: flung toward the back of the stage (state 0F, animation DB). */
void player_take_fling_blow(uint16_t player)
{
	uint8_t animation = 0;
	uint16_t state_and_time = 0;

	player_set_in_air(player);
	state_and_time = 0xF40u;
	animation = 0xDBu;
	player_hurt(state_and_time, player, animation);
}

/* A normal blow (strength 00): reels from the front or behind, falls at the third in a row, is squashed
   by a third stomp from above; in the air it is knocked up, with no life left knocked down. */
void player_take_blow(uint16_t player)
{
	uint8_t animation = 0;
	uint16_t floor_z = 0, object = 0, state_and_time = 0;
	uint16_t stack = 0;
	uint8_t vitality = 0, blows_taken = 0, blows_taken_2 = 0, attributes = 0, attributes_2 = 0, blows_taken_3 = 0, blows_taken_4 = 0, x_low = 0;
	uint16_t z = 0, floor_z_2 = 0, hit_by = 0, z_above = 0, z_2 = 0, z_speed = 0, floor_z_3 = 0;

	z = OBJECT(player)->z;
	floor_z = z;
	floor_z_2 = OBJECT(player)->floor_z;
	if ((int16_t)floor_z_2 < (int16_t)floor_z)
	{
		player_knock_up(player);
		return;
	}
	OBJECT(player)->z_speed = 0;
	vitality = OBJECT(player)->vitality;
	if (vitality == 0u)
	{
		player_take_knockaway_blow(player);
		return;
	}
	hit_by = OBJECT(player)->hit_by;
	object = hit_by;
	blows_taken = OBJECT(player)->player.blows_taken;
	OBJECT(player)->player.blows_taken = blows_taken + 1u;
	stack = floor_z;
	z_above = stack + 0x10u;
	z_2 = OBJECT(object)->z;
	if ((int16_t)z_above < (int16_t)z_2)
	{
		z_speed = OBJECT(object)->z_speed;
		if ((int16_t)z_speed < 0)
		{
			floor_z_3 = OBJECT(player)->floor_z;
			OBJECT(player)->z = floor_z_3;
			blows_taken_2 = OBJECT(player)->player.blows_taken;
			if ((int8_t)blows_taken_2 < 3)
			{
				state_and_time = 0x1600u;
				animation = 0xD5u;
				player_hurt_stop(state_and_time, player, animation);
				return;
			}
			OBJECT(player)->player.blows_taken = 0u;
			player_squash(player);
			return;
		}
	}
	attributes = OBJECT(object)->attributes;
	attributes_2 = OBJECT(player)->attributes;
	if (((attributes ^ attributes_2) & 0x40u) != 0u)
	{
		blows_taken_3 = OBJECT(player)->player.blows_taken;
		if ((int8_t)blows_taken_3 < 3)
		{
			state_and_time = 0x1E00u;
			animation = 0xD1u;
			player_hurt_stop(state_and_time, player, animation);
			return;
		}
		OBJECT(player)->player.blows_taken = 0u;
		state_and_time = 0x1500u;
		animation = 0xD4u;
		player_hurt_stop(state_and_time, player, animation);
		return;
	}
	blows_taken_4 = OBJECT(player)->player.blows_taken;
	if ((int8_t)blows_taken_4 >= 3)
	{
		player_take_knockdown_blow(player);
		return;
	}
	x_low = (uint8_t)OBJECT(player)->x;
	if ((x_low & 2u) != 0u)
	{
		state_and_time = 0x1E00u;
		animation = 0xD2u;
		player_hurt_stop(state_and_time, player, animation);
		return;
	}
	state_and_time = 0x1600u;
	animation = 0xD5u;
	player_hurt_stop(state_and_time, player, animation);
}

/* A blow of strength 06, or a third stomp from above: squashed flat (state 11, animation D0), with its
   voice. */
void player_squash(uint16_t player)
{
	uint8_t animation = 0;
	uint16_t command = 0, state_and_time = 0;

	command = 0x3F00u;
	player_play_voice(player, command);
	OBJECT(player)->z_speed = -0x600;
	state_and_time = 0x1100u;
	animation = 0xD0u;
	player_hurt_stop(state_and_time, player, animation);
}

/* Knocked up into the air the way its hitter faces, turned to it (state 18, animation D7); with no life
   left bounced away instead. */
void player_knock_up(uint16_t player)
{
	uint8_t animation = 0, attributes = 0;
	uint16_t state_and_time = 0, x_speed = 0;
	uint8_t vitality = 0, attributes_2 = 0;
	uint16_t hit_by = 0;

	vitality = OBJECT(player)->vitality;
	if (vitality == 0u)
	{
		player_bounce_away(player);
		return;
	}
	OBJECT(player)->y_speed = 0;
	player_set_in_air(player);
	hit_by = OBJECT(player)->hit_by;
	attributes_2 = OBJECT(hit_by)->attributes;
	OBJECT(player)->z_speed = 0x680;
	x_speed = 0x1C0u;
	attributes = 0x40u;
	if ((attributes_2 & 0x40u) != 0u)
	{
		x_speed = 0xFE40u;
		attributes = 0u;
	}
	OBJECT(player)->x_speed = x_speed;
	OBJECT(player)->attributes = attributes;
	state_and_time = 0x1800u;
	animation = 0xD7u;
	player_hurt(state_and_time, player, animation);
}

/* A blow of strength 08: knocked flying a short way (8 frames), or far with no life left. */
void player_take_knockdown_blow(uint16_t player)
{
	uint16_t state_and_time = 0;
	uint8_t vitality = 0;

	vitality = OBJECT(player)->vitality;
	if (vitality != 0u)
	{
		state_and_time = 0x1408u;
		OBJECT(player)->player.blows_taken = 0u;
		player_knock_flying(state_and_time, player);
		return;
	}
	player_take_knockaway_blow(player);
}

/* A blow of strength 05: knocked flying (state 14 for 32 frames). */
void player_take_knockaway_blow(uint16_t player)
{
	uint16_t state_and_time = 0;

	state_and_time = 0x1420u;
	player_knock_flying(state_and_time, player);
}

/* Knocks the player flying the way its hitter faces (x speed 0400), turned to it, in the state Y gives
   (14, animation D3). */
void player_knock_flying(uint16_t state_and_time, uint16_t player)
{
	uint8_t animation = 0, attributes = 0;
	uint16_t x_speed = 0;
	uint8_t status = 0, attributes_2 = 0;
	uint16_t hit_by = 0;

	status = OBJECT(player)->player.status;
	OBJECT(player)->player.status = status | 0x80u;
	hit_by = OBJECT(player)->hit_by;
	attributes_2 = OBJECT(hit_by)->attributes;
	x_speed = 0x400u;
	attributes = 0u;
	if ((attributes_2 & 0x40u) != 0u)
	{
		x_speed = 0xFC00u;
		attributes = 0x40u;
	}
	OBJECT(player)->x_speed = x_speed;
	OBJECT(player)->attributes = attributes;
	OBJECT(player)->z_fraction = 0u;
	OBJECT(player)->z_speed = 0;
	animation = 0xD3u;
	player_hurt_stop_y(state_and_time, player, animation);
}

/* A blow of strength 01: in the air knocked up; on the floor knocked flying or bounced away, by chance. */
void player_take_heavy_blow(uint16_t player)
{
	uint8_t x_low = 0;
	uint16_t z = 0, floor_z = 0;

	z = OBJECT(player)->z;
	floor_z = OBJECT(player)->floor_z;
	if ((int16_t)floor_z < (int16_t)z)
	{
		player_knock_up(player);
		return;
	}
	OBJECT(player)->z_speed = 0;
	x_low = (uint8_t)OBJECT(player)->x;
	if ((x_low & 2u) != 0u)
	{
		player_take_knockaway_blow(player);
		return;
	}
	player_bounce_away(player);
}

/* Bounced away up and back the way its hitter faces (state 19, animation D2), to turn round after. */
void player_bounce_away(uint16_t player)
{
	uint8_t animation = 0, speed_high = 0, speed_low = 0;
	uint16_t state_and_time = 0;
	uint8_t attributes = 0, status = 0;
	uint16_t hit_by = 0;

	player_set_in_air(player);
	hit_by = OBJECT(player)->hit_by;
	attributes = OBJECT(hit_by)->attributes;
	if ((attributes & 0x40u) != 0u)
	{
		OBJECT(player)->attributes = 0x40u;
		speed_low = 0u;
		OBJECT(player)->x_speed = (OBJECT(player)->x_speed & 0xFFu) | 0xFC00u;
		speed_high = 4u;
	}
	else
	{
		OBJECT(player)->attributes = 0u;
		speed_high = 4u;
		speed_low = 0u;
		OBJECT(player)->x_speed = 0x400;
	}
	OBJECT(player)->z_speed = ((uint32_t)speed_high << 8) | speed_low;
	OBJECT(player)->y_speed = 0;
	state_and_time = 0x1900u;
	status = OBJECT(player)->player.status;
	OBJECT(player)->player.status = status | 0x80u;
	animation = 0xD2u;
	player_hurt(state_and_time, player, animation);
}

/* Grabbed by an enemy (strength 02): held (state 1C, animation BF), with a blinking balloon the first 5
   times in its record. */
void player_get_grabbed(uint16_t player)
{
	uint32_t carry = 0;
	uint8_t animation = 0, grab_animation = 0;
	uint16_t effect_state = 0, holder = 0, player_vars = 0, state_and_time = 0;
	uint8_t hints_shown = 0, hints_before = 0, vitality = 0;
	uint16_t holder_2 = 0, t1 = 0;

	holder_2 = OBJECT(player)->player.holder;
	holder = holder_2;
	OBJECT(holder)->unk_58 = 1u;
	t1 = io_read16(0x1848u);
	player_vars = t1;
	hints_shown = PLAYER_VALUES(player_vars)->grab_hints;
	if ((int8_t)hints_shown < 5)
	{
		hints_before = PLAYER_VALUES(player_vars)->grab_hints;
		PLAYER_VALUES(player_vars)->grab_hints = hints_before + 1u;
		effect_state = 0x500u;
		carry = player_start_effect(player_vars, player, effect_state);
	}
	grab_animation = 0xBFu;
	state_and_time = 0x1C01u;
	vitality = OBJECT(player)->vitality;
	if (vitality != 4u)
	{
		animation = grab_animation;
		player_set_hurt_stopped(state_and_time, player, animation);
		return;
	}
	state_and_time = 0x1C3Cu;
	animation = grab_animation;
	player_set_hurt_stopped(state_and_time, player, animation);
}

/* A blow of strength 03: sound 5E, its voice, stunned for 60 frames (state 1B, animation D9). */
void player_take_stun_blow(uint16_t player)
{
	uint32_t carry = 0;
	uint8_t animation = 0;
	uint16_t command = 0, state_and_time = 0;

	command = 0x5E00u;
	carry = vector_queue_sound(command);
	command = 0x3F28u;
	player_play_voice(player, command);
	state_and_time = 0x1B3Cu;
	animation = 0xD9u;
	player_set_hurt_state(state_and_time, player, animation);
}

/* A blow of strength 04: sound 5E, balloon 0, its voice, stunned for 60 frames (state 1A, animation D8). */
void player_take_stun_blow_2(uint16_t kind, uint16_t player)
{
	uint32_t carry = 0;
	uint8_t animation = 0;
	uint16_t balloon_value = 0, command = 0, state_and_time = 0;

	command = 0x5E00u;
	carry = vector_queue_sound(command);
	balloon_value = 0u;
	player_show_balloon(kind, player, balloon_value);
	command = 0x3F04u;
	player_play_voice(player, command);
	state_and_time = 0x1A3Cu;
	animation = 0xD8u;
	player_set_hurt_state(state_and_time, player, animation);
}

/* Takes the player's flags back to visible and in the air only, then 03960A. */
void player_set_hurt_state(uint16_t state_and_time, uint16_t player, uint8_t animation)
{
	OBJECT(player)->flags &= 0x88u;
	player_set_hurt_stopped(state_and_time, player, animation);
}

/* Sets the reaction's state and timer (Y) and animation (B), stopped, then flashes its palette and drops
   what it holds. */
void player_set_hurt_stopped(uint16_t state_and_time, uint16_t player, uint8_t animation)
{
	OBJECT(player)->player.player_state = (uint8_t)(state_and_time >> 8u);
	OBJECT(player)->player.state_timer = (uint8_t)state_and_time;
	OBJECT(player)->animation = animation;
	player_stop(player);
	player_hurt_flash(player);
}

/* Stops the player's x and y speeds and sets the reaction (039618). */
void player_hurt_stop(uint16_t state_and_time, uint16_t player, uint8_t animation)
{
	OBJECT(player)->x_speed = 0;
	player_hurt_stop_y(state_and_time, player, animation);
}

/* Stops the player's y speed and sets the reaction (03961B). */
void player_hurt_stop_y(uint16_t state_and_time, uint16_t player, uint8_t animation)
{
	OBJECT(player)->y_speed = 0;
	player_hurt(state_and_time, player, animation);
}

/* Sets the reaction's state and timer (Y) and animation (B), with its hurt voice and a spark, its
   palette's flash, and drops what it holds. */
void player_hurt(uint16_t state_and_time, uint16_t player, uint8_t animation)
{
	OBJECT(player)->flags &= 0x88u;
	OBJECT(player)->player.player_state = (uint8_t)(state_and_time >> 8u);
	OBJECT(player)->player.state_timer = (uint8_t)state_and_time;
	OBJECT(player)->animation = animation;
	player_hurt_voice(player);
	player_hurt_flash(player);
}

/* Flashes the player's palette, then 03962F. */
void player_hurt_flash(uint16_t player)
{
	player_flash_palette(0u, player);
	player_hurt_end(player);
}

/* Its hit off, drops what it holds and undoes a team-up it is in. */
void player_hurt_end(uint16_t player)
{
	uint16_t held = 0;
	uint16_t held_2 = 0;

	OBJECT(player)->damage = 0u;
	OBJECT(player)->attack = 0u;
	OBJECT(player)->player.state_frames = 1u;
	OBJECT(player)->player.heavy_object_presses = 0u;
	held_2 = OBJECT(player)->player.held;
	held = held_2;
	if (held_2 == 0u)
	{
		player_break_team(player);
		return;
	}
	player_drop_held(held, player);
}

/* Drops the object it carries (its step 06, stopped) unless it is a heavy object (strength FE), and its
   box back to its body. */
void player_drop_held(uint16_t held, uint16_t player)
{
	uint8_t held_high = 0, attack = 0;

	held_high = (uint8_t)(OBJECT(player)->player.held >> 8u);
	if (held_high == 0u)
	{
		player_break_team(player);
		return;
	}
	OBJECT(player)->player.held = 0u;
	attack = OBJECT(held)->attack;
	if (attack != 0xFEu)
	{
		OBJECT(held)->x_speed = 0;
		OBJECT(held)->y_speed = 0;
		OBJECT(held)->state = 6u;
	}
	player_reset_box(player);
	player_check_motion(player);
}

/* A teamed player hit: the team-up is undone, the partner takes the same reaction (or stands, when this
   one was grabbed) and loses as much life. */
void player_break_team(uint16_t player)
{
	uint32_t zero = 0, carry = 0;
	uint8_t life_lost = 0, state_value = 0, timer_value = 0, vitality = 0;
	uint16_t object = 0, partner = 0;
	uint16_t stack = 0, stack_4 = 0;
	uint8_t teamed = 0, animation = 0, vitality_2 = 0, last_life = 0, life_now = 0, vitality_3 = 0, lost_life = 0;
	uint16_t partner_2 = 0, state_and_timer = 0;
	uint32_t player_state_halfword = 0, player_state_halfword_2 = 0;

	teamed = OBJECT(player)->player.teamed;
	OBJECT(player)->player.teamed = 0u;
	if ((int8_t)teamed >= 0)
	{
		player_check_motion(player);
		return;
	}
	partner_2 = OBJECT(player)->player.partner;
	partner = partner_2;
	player_team_release(partner, player);
	state_and_timer = (((uint32_t)OBJECT(player)->player.player_state << 8u) | OBJECT(player)->player.state_timer);
	timer_value = (uint8_t)state_and_timer;
	state_value = (uint8_t)(state_and_timer >> 8);
	if (state_value != 0x1Cu)
	{
		player_state_halfword = ((uint32_t)state_value << 8) | (timer_value & 0xFFu);
		OBJECT(partner)->player.player_state = (uint8_t)(player_state_halfword >> 8u);
		OBJECT(partner)->player.state_timer = (uint8_t)player_state_halfword;
		animation = OBJECT(player)->animation;
		OBJECT(partner)->animation = animation;
	}
	else
	{
		OBJECT(partner)->animation = 0x80u;
		player_state_halfword_2 = timer_value & 0xFFu;
		OBJECT(partner)->player.player_state = (uint8_t)(player_state_halfword_2 >> 8u);
		OBJECT(partner)->player.state_timer = (uint8_t)player_state_halfword_2;
	}
	OBJECT(partner)->flags = OBJECT(player)->flags;
	player_team_follow(partner, player);
	stack = player;
	stack_4 = partner;
	player = partner;
	player_check_screen_edges(player, &zero, &carry);
	object = stack_4;
	player = stack;
	vitality_2 = OBJECT(player)->vitality;
	last_life = OBJECT(player)->player.last_life;
	life_now = vitality_2;
	life_lost = life_now - last_life;
	if (life_now == last_life)
	{
		player_check_motion(player);
		return;
	}
	vitality_3 = OBJECT(object)->vitality;
	lost_life = life_lost;
	vitality = lost_life + vitality_3;
	if (lost_life <= (uint8_t)(lost_life + vitality_3))
		vitality = 0u;
	OBJECT(object)->vitality = vitality;
	player_check_motion(player);
}
