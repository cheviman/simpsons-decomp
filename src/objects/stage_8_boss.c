/**
 *    Name:        objects/stage_8_boss.c
 *    Description: bank 1D: stage 8's first boss (4F80 type F6, kind 9C): its states and phases, the bombs it throws, its speech balloon
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    09-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the game's 053248 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

/* Stage 8's first boss (type F6, kind 9C): steps its random number, starts its next phase with its
   health back to 80 when it falls to 48, and runs its state (bank_1d_states). */
uint16_t stage_8_boss_run(uint16_t boss, uint16_t enemy_handlers)
{
	uint8_t b = 0, d = 0;
	uint16_t random = 0, seed = 0, states = 0;
	uint8_t phases_left = 0, vitality = 0, phases_left_2 = 0, phase = 0;

	seed = boss + 0x38u;
	random = stage_8_boss_next_random(seed);
	b = (uint8_t)random;
	phases_left = OBJECT(boss)->stage_8_boss.phases_left;
	if (phases_left != 0u)
	{
		vitality = OBJECT(boss)->vitality;
		b = vitality;
		if (b <= 0x48u)
		{
			phases_left_2 = OBJECT(boss)->stage_8_boss.phases_left;
			OBJECT(boss)->stage_8_boss.phases_left = phases_left_2 - 1u;
			OBJECT(boss)->vitality = 0x80u;
		}
	}
	phase = OBJECT(boss)->stage_8_boss.phase;
	states = bank_1d_states_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)phase << 1))
	{
	case 0:
		stage_8_boss_start(boss);
		return states;
	case 2:
		return stage_8_boss_wait_to_enter(boss, states);
	case 4:
	case 12:
	case 16:
	case 46:
	case 48:
		return stage_8_boss_timed_state(boss, states);
	case 6:
	case 8:
		return stage_8_boss_speak(boss);
	case 10:
		return stage_8_boss_start_music(boss, states);
	case 14:
		return stage_8_boss_opening_throw(boss, states);
	case 18:
		return stage_8_boss_fight(boss, enemy_handlers);
	case 20:
		stage_8_boss_idle();
		return states;
	case 22:
	case 24:
		return stage_8_boss_throw(boss, enemy_handlers);
	case 26:
		return stage_8_boss_run_around(boss, enemy_handlers);
	case 28:
		return stage_8_boss_walk_and_bomb(boss, enemy_handlers);
	case 30:
		return stage_8_boss_keep_away(boss);
	case 32:
		return stage_8_boss_jump(boss, enemy_handlers);
	case 34:
		return stage_8_boss_attack(boss, enemy_handlers);
	case 36:
		return stage_8_boss_attack_2(boss, enemy_handlers);
	case 38:
		return stage_8_boss_laugh(boss, enemy_handlers);
	case 40:
		return stage_8_boss_dash(boss, enemy_handlers);
	case 42:
	case 60:
		return stage_8_boss_reel(boss, states, enemy_handlers);
	case 44:
		return stage_8_boss_fall_down(boss, states);
	case 50:
	case 52:
		return stage_8_boss_defeat_blast(boss, states);
	case 54:
		return stage_8_boss_defeat_wait(boss, states);
	case 56:
		d = b;
		stage_8_boss_vanish(boss, d);
		return states;
	case 58:
		return stage_8_boss_attack_wind_up(boss, enemy_handlers);
	}
	unreachable();
}

/* The speech balloon the stage 8 boss puts above itself when it speaks (type 1C of the 4D40 list): shows
   kind B0's animation 84 (82, turned, in scene 4) for 96 frames. */
uint16_t boss_speech_balloon_run(uint16_t balloon, uint16_t kind)
{
	uint8_t frames_left = 0;

	if (OBJECT(balloon)->flags != 4u)
	{
		frames_left = OBJECT(balloon)->boss_speech_balloon.frames_left;
		OBJECT(balloon)->boss_speech_balloon.frames_left = frames_left - 1u;
		if (frames_left == 1u)
			OBJECT(balloon)->flags = 0u;
		return kind;
	}
	OBJECT(balloon)->attributes = 0u;
	OBJECT(balloon)->flags = 0x80u;
	kind = 0xB084u;
	if (scene == 4u)
	{
		kind = 0xB082u;
		OBJECT(balloon)->attributes = 0x80u;
	}
	OBJECT(balloon)->kind = (uint8_t)(kind >> 8u);
	OBJECT(balloon)->animation = (uint8_t)kind;
	OBJECT(balloon)->boss_speech_balloon.frames_left = 0x60u;
	frames_left = OBJECT(balloon)->boss_speech_balloon.frames_left;
	OBJECT(balloon)->boss_speech_balloon.frames_left = frames_left - 1u;
	if (frames_left == 1u)
		OBJECT(balloon)->flags = 0u;
	return kind;
}

/* A bomb the stage 8 boss throws (4D40 type 1D, or 5280 type F1): runs its state (thrown, flying, blast,
   bouncing). */
void stage_8_boss_bomb_run(uint16_t bomb, uint16_t *p_states, uint16_t *p_u)
{
	uint16_t u = (uint16_t)*p_u;
	uint16_t states = 0;
	uint8_t phase = 0;

	phase = OBJECT(bomb)->stage_8_boss_bomb.phase;
	states = stage_8_boss_bomb_states_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)phase << 1))
	{
	case 0:
		stage_8_boss_bomb_throw(bomb, &states, &u);
		break;
	case 2:
		stage_8_boss_bomb_fly(bomb, &states, &u);
		break;
	case 4:
		stage_8_boss_bomb_blast(bomb);
		break;
	case 6:
		stage_8_boss_bomb_bounce(bomb, &states, &u);
		break;
	}
	*p_states = states;
	*p_u = u;
}

/* Carry when a player in the game is reeling or down (its field 02, which bank 1F sets from its state by
   player_state_classes, negative). */
uint32_t stage_8_boss_player_down(void)
{
	uint32_t carry = 0;
	uint8_t playing_bits = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0;

	t1 = players_playing;
	playing_bits = t1 >> 1;
	if ((t1 & 1u) == 0u || (int8_t)OBJECT(OBJECT_ADDRESS(0))->state >= 0)
	{
		t2 = playing_bits;
		playing_bits = t2 >> 1;
		if ((t2 & 1u) == 0u || (int8_t)OBJECT(OBJECT_ADDRESS(2))->state >= 0)
		{
			t3 = playing_bits;
			playing_bits = t3 >> 1;
			if (((t3 & 1u) == 0u || (int8_t)OBJECT(OBJECT_ADDRESS(4))->state >= 0) && ((playing_bits & 1u) == 0u || (int8_t)OBJECT(OBJECT_ADDRESS(6))->state >= 0))
			{
				carry = 0u;
				return carry;
			}
		}
	}
	carry = 1u;
	return carry;
}

/* Stops the bomb and sets its animation (A), state and timer (Y). */
void stage_8_boss_bomb_set_state(uint16_t bomb, uint16_t state_wait, uint16_t animation_number)
{
	OBJECT(bomb)->animation = animation_number >> 8;
	OBJECT(bomb)->x_speed = 0;
	OBJECT(bomb)->y_speed = 0;
	OBJECT(bomb)->target_dy = state_wait;
}

/* Marks the object in the air. */
void stage_8_boss_set_in_air(uint16_t self)
{
	OBJECT(self)->flags |= 8u;
}

/* Marks the object on the floor. */
void stage_8_boss_set_on_floor(uint16_t self)
{
	OBJECT(self)->flags &= ~8u;
}

/* Stops the object's x or y speed at walls, takes the floor under it, and lets it fall: carry once it is
   on the floor. */
void stage_8_boss_move(uint16_t boss, uint16_t *p_landing_speed, uint32_t *p_carry)
{
	uint16_t landing_speed = (uint16_t)*p_landing_speed;
	uint32_t carry = *p_carry;
	uint32_t negative = 0;
	uint8_t floor_height_high = 0, floor_height_low = 0, floor_value = 0;
	uint16_t floor_cell = 0;
	uint8_t attributes = 0;
	uint16_t t1 = 0, z = 0, floor_z = 0, z_2 = 0, z_speed = 0, z_speed_2 = 0, t2 = 0;

	vector_floor_ahead(boss, &floor_cell, &negative);
	floor_value = (uint8_t)(floor_cell >> 8);
	if ((int8_t)floor_value >= 0)
	{
		priority_bits = floor_value & 0x30u;
		attributes = OBJECT(boss)->attributes;
		OBJECT(boss)->attributes = (attributes & 0xCFu) | priority_bits;
		t1 = (uint8_t)((((floor_value & 0xFu) << 1) << 1) << 1);
		floor_height_high = (uint8_t)(t1 >> 8);
		floor_height_low = (uint8_t)t1;
		z = OBJECT(boss)->z;
		if ((int16_t)z < (int16_t)(((uint32_t)floor_height_high << 8) | floor_height_low))
		{
			OBJECT(boss)->y_speed = 0;
			OBJECT(boss)->x_speed = 0;
			floor_z = OBJECT(boss)->floor_z;
			floor_height_high = (uint8_t)(floor_z >> 8);
			floor_height_low = (uint8_t)floor_z;
		}
		else
			OBJECT(boss)->floor_z = ((uint32_t)floor_height_high << 8) | floor_height_low;
	}
	else
	{
		vector_floor_ahead_x(boss, &floor_cell, &negative);
		floor_value = (uint8_t)(floor_cell >> 8);
		if (negative == 0u)
		{
			OBJECT(boss)->y_speed = 0;
			priority_bits = floor_value & 0x30u;
			attributes = OBJECT(boss)->attributes;
			OBJECT(boss)->attributes = (attributes & 0xCFu) | priority_bits;
			t1 = (uint8_t)((((floor_value & 0xFu) << 1) << 1) << 1);
			floor_height_high = (uint8_t)(t1 >> 8);
			floor_height_low = (uint8_t)t1;
			z = OBJECT(boss)->z;
			if ((int16_t)z < (int16_t)(((uint32_t)floor_height_high << 8) | floor_height_low))
			{
				OBJECT(boss)->y_speed = 0;
				OBJECT(boss)->x_speed = 0;
				floor_z = OBJECT(boss)->floor_z;
				floor_height_high = (uint8_t)(floor_z >> 8);
				floor_height_low = (uint8_t)floor_z;
			}
			else
				OBJECT(boss)->floor_z = ((uint32_t)floor_height_high << 8) | floor_height_low;
		}
		else
		{
			OBJECT(boss)->x_speed = 0;
			vector_floor_ahead_y(boss, &floor_cell, &negative);
			floor_value = (uint8_t)(floor_cell >> 8);
			if (negative == 0u)
			{
				priority_bits = floor_value & 0x30u;
				attributes = OBJECT(boss)->attributes;
				OBJECT(boss)->attributes = (attributes & 0xCFu) | priority_bits;
				t1 = (uint8_t)((((floor_value & 0xFu) << 1) << 1) << 1);
				floor_height_high = (uint8_t)(t1 >> 8);
				floor_height_low = (uint8_t)t1;
				z = OBJECT(boss)->z;
				if ((int16_t)z < (int16_t)(((uint32_t)floor_height_high << 8) | floor_height_low))
				{
					OBJECT(boss)->y_speed = 0;
					OBJECT(boss)->x_speed = 0;
					floor_z = OBJECT(boss)->floor_z;
					floor_height_high = (uint8_t)(floor_z >> 8);
					floor_height_low = (uint8_t)floor_z;
				}
				else
					OBJECT(boss)->floor_z = ((uint32_t)floor_height_high << 8) | floor_height_low;
			}
			else if (negative)
			{
				OBJECT(boss)->y_speed = 0;
				OBJECT(boss)->x_speed = 0;
				floor_z = OBJECT(boss)->floor_z;
				floor_height_high = (uint8_t)(floor_z >> 8);
				floor_height_low = (uint8_t)floor_z;
			}
			else
			{
				OBJECT(boss)->y_speed = 0;
				priority_bits = floor_value & 0x30u;
				attributes = OBJECT(boss)->attributes;
				OBJECT(boss)->attributes = (attributes & 0xCFu) | priority_bits;
				t1 = (uint8_t)((((floor_value & 0xFu) << 1) << 1) << 1);
				floor_height_high = (uint8_t)(t1 >> 8);
				floor_height_low = (uint8_t)t1;
				z = OBJECT(boss)->z;
				if ((int16_t)z < (int16_t)(((uint32_t)floor_height_high << 8) | floor_height_low))
				{
					OBJECT(boss)->y_speed = 0;
					OBJECT(boss)->x_speed = 0;
					floor_z = OBJECT(boss)->floor_z;
					floor_height_high = (uint8_t)(floor_z >> 8);
					floor_height_low = (uint8_t)floor_z;
				}
				else
					OBJECT(boss)->floor_z = ((uint32_t)floor_height_high << 8) | floor_height_low;
			}
		}
	}
	z_2 = OBJECT(boss)->z;
	if ((int16_t)z_2 <= (int16_t)(((uint32_t)floor_height_high << 8) | floor_height_low))
	{
		OBJECT(boss)->z = ((uint32_t)floor_height_high << 8) | floor_height_low;
		z_speed = OBJECT(boss)->z_speed;
		landing_speed = z_speed;
		if (z_speed != 0u)
		{
			OBJECT(boss)->z_speed = 0;
			stage_8_boss_set_on_floor(boss);
		}
		carry = 1u;
	}
	else
	{
		z_speed_2 = OBJECT(boss)->z_speed;
		t2 = z_speed_2 - 0x60u;
		OBJECT(boss)->z_speed = t2;
		carry = 0u;
	}
	*p_landing_speed = landing_speed;
	*p_carry = carry;
}

/* A random player in play, in U. */
void stage_8_boss_pick_player(uint16_t *p_player, uint16_t *p_first_slot)
{
	uint32_t zero = 0;
	uint8_t slot_high = 0, slot_low = 0;
	uint16_t first_slot = 0, player = 0;
	uint8_t stack = 0, stack_10002 = 0;
	uint16_t t1 = 0, t2 = 0;

	t1 = (random_number & 3u) * 0xC0u;
	t2 = t1 + OBJECT_ADDRESS(0);
	slot_high = (uint8_t)(t2 >> 8);
	slot_low = (uint8_t)t2;
	stack = slot_high;
	stack_10002 = slot_low;
	player = ((uint32_t)stack << 8) | stack_10002;
	stage_8_boss_next_player(&player, &zero);
	if (zero)
	{
		stage_8_boss_next_player(&player, &zero);
		if (zero)
		{
			stage_8_boss_next_player(&player, &zero);
			if (zero)
				stage_8_boss_next_player(&player, &zero);
		}
	}
	first_slot = ((uint32_t)slot_high << 8) | slot_low;
	*p_player = player;
	*p_first_slot = first_slot;
}

/* The next player's object after U (from the first after the fourth); Z when it is not in play. */
void stage_8_boss_next_player(uint16_t *p_player, uint32_t *p_zero)
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

/* Notes the player who hit it (its number from the player's field 5B) for the score. */
uint16_t stage_8_boss_credit_hitter(uint16_t boss)
{
	uint16_t object = 0;
	uint8_t shadow_player = 0;
	uint16_t hit_by = 0;

	hit_by = OBJECT(boss)->hit_by;
	object = hit_by;
	shadow_player = OBJECT(object)->shadow_player;
	OBJECT(boss)->points = shadow_player & ~0xFu;
	return object;
}

/* Marks its score for the player who beat it. */
void stage_8_boss_give_score(uint16_t boss)
{
	uint8_t points = 0;

	points = OBJECT(boss)->points;
	OBJECT(boss)->points = points | 0x81u;
}

/* Carry when a player in the game is within F8 of it across and FA in depth, that player in U. */
void stage_8_boss_find_close_player(uint16_t boss, uint16_t *p_player, uint32_t *p_carry)
{
	uint32_t carry = *p_carry;
	uint16_t player = 0, playing_bits = 0;

	player = OBJECT_ADDRESS(0);
	playing_bits = players_playing;
	stage_8_boss_player_is_close(boss, player, &playing_bits, &carry);
	if (carry == 0u)
	{
		player = OBJECT_ADDRESS(2);
		stage_8_boss_player_is_close(boss, player, &playing_bits, &carry);
		if (carry == 0u)
		{
			player = OBJECT_ADDRESS(4);
			stage_8_boss_player_is_close(boss, player, &playing_bits, &carry);
			if (carry == 0u)
			{
				player = OBJECT_ADDRESS(6);
				stage_8_boss_player_is_close(boss, player, &playing_bits, &carry);
			}
		}
	}
	*p_player = player;
	*p_carry = carry;
}

/* Carry when the player U, in the game by the bit in B, is within F8 across and FA in depth. */
void stage_8_boss_player_is_close(uint16_t boss, uint16_t object, uint16_t *p_playing_bits, uint32_t *p_carry)
{
	uint8_t playing_bits = (uint8_t)*p_playing_bits;
	uint32_t carry = *p_carry;
	uint16_t distance = 0, playing_bits_left = 0;
	uint8_t stack = 0;
	uint8_t t1 = 0;
	uint16_t t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0;

	t1 = playing_bits;
	playing_bits_left = t1 >> 1;
	if ((t1 & 1u) == 0u)
	{
		carry = 0u;
		playing_bits_left &= 0xFFu;
	}
	else
	{
		stack = (uint8_t)playing_bits_left;
		t2 = OBJECT(boss)->x;
		t3 = OBJECT(object)->x;
		distance = t2 - t3;
		t4 = distance >> 15 ? 0u - distance : distance;
		playing_bits_left = stack;
		if (reach_x <= (int16_t)t4)
		{
			carry = 0u;
			playing_bits_left &= 0xFFu;
		}
		else
		{
			stack = (uint8_t)playing_bits_left;
			t5 = OBJECT(boss)->y;
			t6 = OBJECT(object)->y;
			distance = t5 - t6;
			distance = (uint16_t)(distance >> 15 ? 0u - distance : distance);
			t7 = distance;
			playing_bits_left = (distance & ~0xFFu) | stack;
			if (reach_y <= (int16_t)t7)
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

/* The boss can not be hurt. */
uint32_t stage_8_boss_make_invulnerable(uint16_t boss)
{
	uint32_t zero = 0;
	uint8_t flags = 0;

	flags = OBJECT(boss)->flags | 4u;
	zero = flags == 0u;
	OBJECT(boss)->flags = flags;
	return zero;
}

/* The boss can be hurt again. */
void stage_8_boss_make_vulnerable(uint16_t boss)
{
	OBJECT(boss)->flags &= ~4u;
}

/* Takes a player's blow (strength 11 or more): sound 66, its spark on the player; 1 when it holds on, FF
   when its health is at or below the limit Y gives for the players in the game (beaten, the hitter
   noted), 0 when not hit. */
void stage_8_boss_take_hit(uint16_t boss, uint16_t limits, uint16_t *p_object, uint32_t *p_zero, uint32_t *p_negative)
{
	uint16_t object = (uint16_t)*p_object;
	uint32_t zero = *p_zero;
	uint32_t negative = *p_negative;
	uint32_t carry = 0;
	uint8_t behaviour = 0, health = 0, players = 0;
	uint16_t command = 0;
	uint8_t hit = 0, vitality = 0, vitality_2 = 0;
	uint16_t hit_by = 0;

	if ((OBJECT(boss)->flags & 0x20u) == 0u)
	{
		negative = 0u;
		zero = 1u;
	}
	else
	{
		hit = OBJECT(boss)->hit;
		behaviour = hit;
		if ((int8_t)behaviour < 0x11)
		{
			negative = 0u;
			zero = 1u;
		}
		else
		{
			OBJECT(boss)->damage = 0u;
			OBJECT(boss)->attack = 0u;
			hit_by = OBJECT(boss)->hit_by;
			object = hit_by;
			if ((int16_t)object >= 0x4A40 && object < OBJECT_ADDRESS(8))
			{
				OBJECT(object)->behaviour = (OBJECT(object)->behaviour & 0xFFu) | ((behaviour & 0xFFu) << 8u);
				AT16(OBJECT(object)->hit_box, -1) = boss;
			}
			OBJECT(boss)->flags = 0x80u;
			vitality = OBJECT(boss)->vitality;
			health = vitality;
			players = player_count;
			if (health <= mem_read8(limits + (int8_t)players))
			{
				vitality_2 = OBJECT(boss)->vitality;
				health = vitality_2;
			}
			if (health <= mem_read8(limits + (int8_t)players))
			{
				OBJECT(boss)->vitality = 0u;
				object = stage_8_boss_credit_hitter(boss);
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
	*p_object = object;
	*p_zero = zero;
	*p_negative = negative;
}

/* Blinks, safe, until its timer runs out, then is gone with its score given (carry). */
uint32_t stage_8_boss_blink_out(uint16_t boss)
{
	uint32_t carry = 0;
	uint8_t state_timer = 0;

	OBJECT(boss)->flags = (OBJECT(boss)->flags ^ 0x80u) | 4u;
	state_timer = OBJECT(boss)->stage_8_boss.state_timer;
	OBJECT(boss)->stage_8_boss.state_timer = state_timer - 1u;
	if (state_timer != 1u)
	{
		carry = 0u;
		return carry;
	}
	OBJECT(boss)->flags = 0u;
	stage_8_boss_give_score(boss);
	carry = 1u;
	return carry;
}

/* At its animation's hit frames hits with Y and can be hurt, else no hit; carry when the animation has
   ended. */
uint32_t stage_8_boss_hit_on_frame(uint16_t boss, uint16_t damage)
{
	uint32_t carry = 0;
	uint8_t animation_flags = 0, animation_flags_2 = 0;

	animation_flags = OBJECT(boss)->animation_flags;
	if ((animation_flags & 2u) != 0u)
		stage_8_boss_make_vulnerable(boss);
	else
		damage = 0u;
	OBJECT(boss)->damage = (uint8_t)(damage >> 8u);
	OBJECT(boss)->attack = (uint8_t)damage;
	animation_flags_2 = OBJECT(boss)->animation_flags;
	carry = animation_flags_2 & 1u;
	return carry;
}

/* Sets the object's box from the 4 bytes Y points at. */
uint16_t stage_8_boss_set_box(uint16_t self, uint16_t box)
{
	uint16_t box_height = 0, box_rest = 0;
	uint16_t t1 = 0;
	uint32_t box_width_halfword = 0;

	t1 = box;
	box_rest = t1 + 2u;
	box_width_halfword = mem_read16(t1);
	OBJECT(self)->box_width = (uint8_t)(box_width_halfword >> 8u);
	OBJECT(self)->box_depth = (uint8_t)box_width_halfword;
	box_height = mem_read16(box_rest);
	OBJECT(self)->box_height = (uint8_t)(box_height >> 8u);
	OBJECT(self)->box_dx = (uint8_t)box_height;
	OBJECT(self)->box_dz = box_height >> 8;
	return box_rest;
}

/* Faces the way it moves, starting its animation again when it turns. */
void stage_8_boss_face_motion(uint16_t boss)
{
	uint8_t facing = 0;
	uint8_t attributes = 0, attributes_2 = 0, animation = 0;
	uint16_t x_speed = 0;

	facing = 0u;
	x_speed = OBJECT(boss)->x_speed;
	if ((int16_t)x_speed < 0)
		facing = 0x40u;
	attributes = OBJECT(boss)->attributes;
	if (((facing ^ attributes) & 0x40u) != 0u)
	{
		attributes_2 = OBJECT(boss)->attributes;
		OBJECT(boss)->attributes = attributes_2 ^ 0x40u;
		animation = OBJECT(boss)->animation;
		OBJECT(boss)->animation = animation | 0x80u;
	}
}

/* Faces the nearest player. */
uint16_t stage_8_boss_face_nearest_player(uint16_t boss)
{
	uint8_t attributes = 0;
	uint16_t target_player = 0;
	uint8_t attributes_2 = 0;
	uint16_t t1 = 0, t2 = 0;

	target_player = vector_choose_nearest_player(boss);
	attributes_2 = OBJECT(boss)->attributes;
	attributes = attributes_2 & 0xBFu;
	t1 = OBJECT(boss)->x;
	t2 = OBJECT(target_player)->x;
	if ((int16_t)t2 < (int16_t)t1)
		attributes |= 0x40u;
	OBJECT(boss)->attributes = attributes;
	return target_player;
}

/* Unused: sets its speeds from a direction and the speed a table gives for the rank. */
void unused_stage_8_boss_set_speed_by_rank(uint16_t object, uint16_t speeds_by_rank, uint16_t direction)
{
	uint16_t heading = 0;

	heading = (direction & ~0xFFu) | mem_read8(speeds_by_rank + (rank >> 1));
	vector_set_speed_by_direction(object, heading);
}

/* Carry when it has no x or y speed. */
uint32_t stage_8_boss_is_still(uint16_t boss)
{
	uint32_t carry = 0;
	uint16_t x_speed = 0, y_speed = 0;

	x_speed = OBJECT(boss)->x_speed;
	if (x_speed == 0u)
	{
		y_speed = OBJECT(boss)->y_speed;
		if (y_speed == 0u)
		{
			carry = 1u;
			return carry;
		}
	}
	carry = 0u;
	return carry;
}

/* Unused: shades the boss by its vitality, in steps a table gives for the players in the game. */
void unused_stage_8_boss_shade_by_players(uint16_t object, uint16_t piece_health_by_players, uint8_t gauge_number)
{
	uint16_t shade_step_and_row = 0;

	shade_step_and_row = (gauge_number & 0xFFu) | ((uint32_t)mem_read8(piece_health_by_players + (int8_t)player_count) << 8);
	boss_shade_by_vitality(object, piece_health_by_players, shade_step_and_row);
}

/* Stops it and starts state B. */
uint16_t stage_8_boss_stop_and_start_state(uint16_t boss, uint8_t new_phase)
{
	OBJECT(boss)->x_speed = 0;
	OBJECT(boss)->y_speed = 0;
	return stage_8_boss_start_state(boss, new_phase);
}

/* Starts state B with its timer and animation from stage_8_boss_state_starts. */
uint16_t stage_8_boss_start_state(uint16_t boss, uint8_t new_phase)
{
	uint8_t animation = 0, phase = 0;
	uint16_t state_start_table = 0;
	uint16_t wait = 0;

	phase = (uint8_t)new_phase;
	state_start_table = stage_8_boss_state_starts_ADDRESS;
	OBJECT(boss)->stage_8_boss.phase = phase;
	wait = (((uint32_t)STATE_START(state_start_table + (int8_t)((uint32_t)phase << 1))->wait << 8u) | STATE_START(state_start_table + (int8_t)((uint32_t)phase << 1))->animation);
	animation = (uint8_t)wait;
	OBJECT(boss)->stage_8_boss.state_timer = ((wait & ~0xFFu) | animation) >> 8;
	OBJECT(boss)->animation = animation;
	return state_start_table;
}

/* Unused: writes 1234 into its target field and marks it on the floor. */
void unused_stage_8_boss_mark_on_floor(uint16_t boss)
{
	mem_write16(boss + 0x38u, 0x1234u);
	stage_8_boss_set_on_floor(boss);
}

/* Sets the boss up: kind 9C, health 80 with 3 phases to go, at x 1A0, the bombs' random number from the
   game's. */
void stage_8_boss_start(uint16_t boss)
{
	uint16_t t1 = 0;

	OBJECT(boss)->kind = 0x9Cu;
	OBJECT(boss)->vitality = 0x80u;
	OBJECT(boss)->stage_8_boss.health_mark = 0x80u;
	OBJECT(boss)->stage_8_boss.phase = 1u;
	OBJECT(boss)->stage_8_boss.run_speed = 2u;
	t1 = AT16(random_number, -1);
	io_write16(0x1852u, t1);
	OBJECT(boss)->stage_8_boss.phases_left = 2u;
	OBJECT(boss)->x = 0x1A0u;
}

/* Waits while direct page 92 is set, then shows itself walking in from the right (state 02). */
uint16_t stage_8_boss_wait_to_enter(uint16_t boss, uint16_t states)
{
	uint8_t new_phase = 0;
	uint8_t attributes = 0;

	if (stage_scrolls_on != 0u)
		return states;
	OBJECT(boss)->x_speed = -0x200;
	OBJECT(boss)->flags = 0x80u;
	attributes = OBJECT(boss)->attributes;
	OBJECT(boss)->attributes = attributes | 0x40u;
	new_phase = 2u;
	return stage_8_boss_start_state(boss, new_phase);
}

/* A timed state (walking in, poses before and after the fight, its defeat): holds the scroll, moves, and
   at the end of its time goes to the next state. */
uint16_t stage_8_boss_timed_state(uint16_t boss, uint16_t landing_speed)
{
	uint32_t carry = 0;
	uint8_t state_timer = 0;

	camera_x_held = 1u;
	camera_y_held = 1u;
	stage_8_boss_move(boss, &landing_speed, &carry);
	state_timer = OBJECT(boss)->stage_8_boss.state_timer;
	OBJECT(boss)->stage_8_boss.state_timer = state_timer - 1u;
	if (state_timer == 1u)
		return stage_8_boss_next_state(boss);
	return landing_speed;
}

/* Starts its next state (sound 47 after state 17). */
uint16_t stage_8_boss_next_state(uint16_t boss)
{
	uint32_t carry = 0;
	uint8_t new_phase = 0;
	uint16_t command = 0;
	uint8_t phase = 0, phase_2 = 0;

	phase = OBJECT(boss)->stage_8_boss.phase;
	if (phase == 0x17u)
	{
		command = 0x4700u;
		carry = vector_queue_sound(command);
	}
	phase_2 = OBJECT(boss)->stage_8_boss.phase;
	new_phase = (uint8_t)(phase_2 + 1u);
	return stage_8_boss_stop_and_start_state(boss, new_phase);
}

/* After its pose, asks for the scene's next music (the boss's) and goes on. */
uint16_t stage_8_boss_start_music(uint16_t boss, uint16_t states)
{
	uint8_t new_phase = 0;
	uint8_t state_timer = 0, phase = 0;

	state_timer = OBJECT(boss)->stage_8_boss.state_timer;
	OBJECT(boss)->stage_8_boss.state_timer = state_timer - 1u;
	if (state_timer == 1u)
	{
		boss_arrived = 1u;
		phase = OBJECT(boss)->stage_8_boss.phase;
		new_phase = (uint8_t)(phase + 1u);
		return stage_8_boss_stop_and_start_state(boss, new_phase);
	}
	return states;
}

/* Speaks: its speech balloon above it and its voice (3F34), then the next state. */
uint16_t stage_8_boss_speak(uint16_t boss)
{
	uint32_t carry = 0;
	uint16_t balloon_record = 0, command = 0, ignored16 = 0;
	uint8_t state_timer = 0, phase = 0;

	state_timer = OBJECT(boss)->stage_8_boss.state_timer;
	OBJECT(boss)->stage_8_boss.state_timer = state_timer - 1u;
	if (state_timer != 1u)
	{
		balloon_record = stage_8_boss_speak_child_ADDRESS;
		spawn_list_2_child(boss, balloon_record, &ignored16, &carry);
		command = 0x3F34u;
		carry = vector_queue_sound(command);
		return stage_8_boss_next_state(boss);
	}
	phase = OBJECT(boss)->stage_8_boss.phase;
	if (phase != 4u)
		return stage_8_boss_next_state(boss);
	balloon_record = stage_8_boss_speak_child_ADDRESS;
	spawn_list_2_child(boss, balloon_record, &ignored16, &carry);
	command = 0x3F34u;
	carry = vector_queue_sound(command);
	return stage_8_boss_next_state(boss);
}

/* Unused: does nothing. */
void unused_stage_8_boss_no_op(void)
{
}

/* Its first throw: two bombs for each player in the game; when the animation ends it can be hit and the
   fight goes on. */
uint16_t stage_8_boss_opening_throw(uint16_t boss, uint16_t child_record)
{
	uint16_t bomb_count = 0, box = 0, ignored16 = 0;
	uint8_t animation_flags = 0, animation_flags_2 = 0;

	animation_flags = OBJECT(boss)->animation_flags;
	if ((animation_flags & 2u) != 0u)
	{
		bomb_count = (uint32_t)(uint8_t)((uint32_t)player_count << 1) << 8;
		stage_8_boss_throw_bombs(boss, bomb_count, &child_record, &ignored16);
	}
	animation_flags_2 = OBJECT(boss)->animation_flags;
	if ((animation_flags_2 & 1u) == 0u)
		return child_record;
	OBJECT(boss)->flags = 0xC0u;
	OBJECT(boss)->damage = 0u;
	OBJECT(boss)->attack = 0u;
	box = stage_8_boss_box_ADDRESS;
	stage_8_boss_set_box(boss, box);
	OBJECT(boss)->stage_8_boss.count_down = 0x56u;
	return stage_8_boss_next_state(boss);
}

/* The fight: frees the scroll and runs its phase (first, second or third by its phases to go). */
uint16_t stage_8_boss_fight(uint16_t boss, uint16_t enemy_handlers)
{
	uint8_t phases_left = 0;

	camera_x_held = 0u;
	camera_y_held = 0u;
	phases_left = OBJECT(boss)->stage_8_boss.phases_left;
	switch ((int8_t)(uint8_t)((uint32_t)phases_left << 1))
	{
	case 0:
		return stage_8_boss_phase_3(boss);
	case 2:
		return stage_8_boss_phase_2(boss, enemy_handlers);
	case 4:
		return stage_8_boss_phase_1(boss, enemy_handlers);
	}
	unreachable();
}

/* Its first phase: walks toward the nearest player or a random way, laughs now and then or when a player
   is down, and stops to throw bombs, again and again by chance. */
uint16_t stage_8_boss_phase_1(uint16_t boss, uint16_t target_player)
{
	bool L_03A3A4 = false;
	uint32_t carry = 0;
	uint8_t angle = 0, new_phase = 0, speed_high = 0, speed_low = 0;
	uint16_t command = 0, direction = 0, heading = 0, speed = 0;
	uint8_t stack = 0;
	uint8_t count_down = 0, count_down_2 = 0, t1 = 0, state_timer = 0, phase_1_hits = 0, laugh_frames = 0, laugh_frames_2 = 0, count = 0, count_2 = 0;
	uint16_t x_speed = 0, x_speed_2 = 0, x_speed_3 = 0, t2 = 0;

	count_down = OBJECT(boss)->stage_8_boss.count_down;
	if (count_down != 0u)
	{
		count_down_2 = OBJECT(boss)->stage_8_boss.count_down;
		OBJECT(boss)->stage_8_boss.count_down = count_down_2 - 1u;
		if (count_down_2 != 1u)
		{
			x_speed = OBJECT(boss)->x_speed;
			if (x_speed == 0u)
			{
				OBJECT(boss)->animation = 0x90u;
				L_03A3A4 = true;
			}
			if (!L_03A3A4)
			{
				speed = stage_8_boss_speed(boss);
				speed_high = (uint8_t)(speed >> 8);
				speed_low = (uint8_t)speed;
			}
			if (L_03A3A4 || (int16_t)(((uint32_t)speed_high << 8) | speed_low) <= 0xC0 || (random_number & 0x3Fu) == 0u)
			{
				t1 = (uint8_t)(OBJECT(boss)->stage_8_boss.random >> 8u);
				angle = t1;
				if ((angle & 1u) == 0u)
					angle &= ~3u;
				else
				{
					target_player = vector_choose_nearest_player(boss);
					direction = vector_direction_to(boss, target_player);
					angle = (uint8_t)(direction >> 8);
				}
				stack = angle;
				heading = ((uint32_t)stack << 8) | stage_8_boss_walk_speeds_by_players[(int8_t)player_count];
				vector_set_speed_by_direction(boss, heading);
				stage_8_boss_turn_to_motion(boss);
				x_speed_2 = OBJECT(boss)->x_speed;
				x_speed_3 = OBJECT(boss)->x_speed;
				t2 = x_speed_2 + x_speed_3;
				OBJECT(boss)->x_speed = t2;
			}
			state_timer = OBJECT(boss)->stage_8_boss.state_timer;
			OBJECT(boss)->stage_8_boss.state_timer = state_timer - 1u;
			if (state_timer == 1u)
			{
				command = 0x7900u;
				carry = vector_queue_sound(command);
				new_phase = 0x13u;
				stage_8_boss_stop_and_start_state(boss, new_phase);
				phase_1_hits = OBJECT(boss)->stage_8_boss.phase_1_hits;
				OBJECT(boss)->stage_8_boss.phase_1_hits = phase_1_hits + 1u;
				return stage_8_boss_move_and_take_hits(boss, target_player);
			}
			laugh_frames = OBJECT(boss)->stage_8_boss.laugh_frames;
			OBJECT(boss)->stage_8_boss.laugh_frames = laugh_frames + 1u;
			laugh_frames_2 = OBJECT(boss)->stage_8_boss.laugh_frames;
			if (laugh_frames_2 <= 0x78u)
				return stage_8_boss_move_and_take_hits(boss, target_player);
			OBJECT(boss)->stage_8_boss.laugh_frames = 0u;
			carry = stage_8_boss_player_down();
			if (carry == 0u)
				return stage_8_boss_move_and_take_hits(boss, target_player);
			command = 0x7900u;
			carry = vector_queue_sound(command);
			new_phase = 0x13u;
			stage_8_boss_stop_and_start_state(boss, new_phase);
			phase_1_hits = OBJECT(boss)->stage_8_boss.phase_1_hits;
			OBJECT(boss)->stage_8_boss.phase_1_hits = phase_1_hits + 1u;
			return stage_8_boss_move_and_take_hits(boss, target_player);
		}
	}
	if (random_number > 0xC0u)
	{
		new_phase = 0xBu;
		stage_8_boss_stop_and_start_state(boss, new_phase);
		target_player = stage_8_boss_face_nearest_player(boss);
	}
	else
	{
		speed = stage_8_boss_speed(boss);
		speed_high = (uint8_t)(speed >> 8);
		speed_low = (uint8_t)speed;
		if ((int16_t)(((uint32_t)speed_high << 8) | speed_low) <= 0xC0)
		{
			new_phase = 0xBu;
			stage_8_boss_stop_and_start_state(boss, new_phase);
			target_player = stage_8_boss_face_nearest_player(boss);
			OBJECT(boss)->stage_8_boss.count_down = 0x56u;
			if ((int8_t)random_number <= (int8_t)stage_8_boss_stop_throwing_chances_by_players[(int8_t)player_count])
				return stage_8_boss_check_close_player(boss);
			count = OBJECT(boss)->stage_8_boss.count;
			OBJECT(boss)->stage_8_boss.count = count + 1u;
			count_2 = OBJECT(boss)->stage_8_boss.count;
			if (count_2 > 3u)
			{
				OBJECT(boss)->stage_8_boss.count = 0u;
				return stage_8_boss_move_and_take_hits(boss, target_player);
			}
			OBJECT(boss)->stage_8_boss.count_down = 1u;
			return stage_8_boss_move_and_take_hits(boss, target_player);
		}
		new_phase = 0xCu;
		stage_8_boss_start_state(boss, new_phase);
	}
	OBJECT(boss)->stage_8_boss.count_down = 0x56u;
	if ((int8_t)random_number <= (int8_t)stage_8_boss_stop_throwing_chances_by_players[(int8_t)player_count])
		return stage_8_boss_check_close_player(boss);
	count = OBJECT(boss)->stage_8_boss.count;
	OBJECT(boss)->stage_8_boss.count = count + 1u;
	count_2 = OBJECT(boss)->stage_8_boss.count;
	if (count_2 > 3u)
	{
		OBJECT(boss)->stage_8_boss.count = 0u;
		return stage_8_boss_move_and_take_hits(boss, target_player);
	}
	OBJECT(boss)->stage_8_boss.count_down = 1u;
	return stage_8_boss_move_and_take_hits(boss, target_player);
}

/* Throws its bombs (as many as stage_8_boss_bombs_by_players gives) at the throw frame, and goes back to
   fighting when the animation ends. */
uint16_t stage_8_boss_throw(uint16_t boss, uint16_t enemy_handlers)
{
	uint8_t animation_bits = 0, bombs = 0;
	uint16_t bomb_count = 0, ignored16 = 0, ignored16_2 = 0;
	uint8_t animation_flags = 0;

	animation_flags = OBJECT(boss)->animation_flags;
	animation_bits = animation_flags;
	if ((animation_bits & 2u) == 0u)
	{
		if ((animation_bits & 1u) == 0u)
			return stage_8_boss_check_close_player(boss);
		return stage_8_boss_resume(boss, enemy_handlers);
	}
	bombs = stage_8_boss_bombs_by_players[(int8_t)player_count];
	bombs_left = bombs;
	bomb_count = (uint32_t)bombs << 8;
	stage_8_boss_throw_bombs(boss, bomb_count, &ignored16, &ignored16_2);
	return stage_8_boss_check_close_player(boss);
}

/* Starts its second phase: runs a random way (state 0D) at its run speed, for 128 steps. */
uint16_t stage_8_boss_phase_2(uint16_t boss, uint16_t enemy_handlers)
{
	uint32_t negative = 0;
	uint8_t a = 0, chosen_speed = 0, floor_low = 0, new_phase = 0, run_speed = 0;
	uint16_t floor_cell = 0;
	uint8_t stack = 0;
	uint8_t t1 = 0;

	new_phase = 0xDu;
	stage_8_boss_start_state(boss, new_phase);
	OBJECT(boss)->y_speed = 0;
	chosen_speed = stage_8_boss_run_speeds_by_players[(int8_t)player_count];
	if ((int8_t)random_number < 0)
		chosen_speed = 0u - chosen_speed;
	stack = chosen_speed;
	vector_floor_ahead(boss, &floor_cell, &negative);
	a = (uint8_t)(floor_cell >> 8);
	floor_low = (uint8_t)floor_cell;
	t1 = a;
	run_speed = stack;
	if ((int8_t)t1 < 0)
		run_speed = 0u - run_speed;
	OBJECT(boss)->x_speed = ((uint32_t)run_speed << 8) | floor_low;
	OBJECT(boss)->stage_8_boss.run_speed = run_speed;
	OBJECT(boss)->stage_8_boss.steps_left = 0x80u;
	return stage_8_boss_run_around(boss, enemy_handlers);
}

/* Its run: turns back at walls, drops bombs as it goes, and after 128 steps walks at a random player
   dropping bombs (state 0E). */
uint16_t stage_8_boss_run_around(uint16_t boss, uint16_t enemy_handlers)
{
	uint32_t negative = 0;
	uint8_t angle = 0, bombs = 0, floor_value = 0, new_phase = 0, run_speed = 0;
	uint16_t bomb_count = 0, direction = 0, floor_cell = 0, heading = 0, ignored16 = 0, target_player = 0;
	uint8_t count_down = 0, count_down_2 = 0, run_speed_2 = 0, animation_flags = 0, steps = 0, steps_2 = 0, steps_left = 0;

	count_down = OBJECT(boss)->stage_8_boss.count_down;
	if (count_down == 0u)
		stage_8_boss_make_vulnerable(boss);
	else
	{
		count_down_2 = OBJECT(boss)->stage_8_boss.count_down;
		OBJECT(boss)->stage_8_boss.count_down = count_down_2 - 1u;
		if (count_down_2 == 1u)
			stage_8_boss_make_vulnerable(boss);
	}
	vector_floor_ahead(boss, &floor_cell, &negative);
	floor_value = (uint8_t)(floor_cell >> 8);
	if ((int8_t)floor_value < 0)
	{
		run_speed_2 = OBJECT(boss)->stage_8_boss.run_speed;
		run_speed = 0u - run_speed_2;
		OBJECT(boss)->stage_8_boss.run_speed = run_speed;
		OBJECT(boss)->x_speed = (uint32_t)run_speed << 8;
	}
	animation_flags = OBJECT(boss)->animation_flags;
	if ((animation_flags & 2u) != 0u)
	{
		steps = OBJECT(boss)->stage_8_boss.steps;
		OBJECT(boss)->stage_8_boss.steps = steps + 1u;
		steps_2 = OBJECT(boss)->stage_8_boss.steps;
		if ((steps_2 & 6u) != 0u)
		{
			bombs = (uint32_t)player_count << 1;
			bombs_left = bombs;
			bomb_count = (floor_cell & 0xFFu) | ((uint32_t)bombs << 8);
			stage_8_boss_throw_bombs(boss, bomb_count, &ignored16, &enemy_handlers);
		}
	}
	stage_8_boss_turn_to_motion(boss);
	steps_left = OBJECT(boss)->stage_8_boss.steps_left;
	OBJECT(boss)->stage_8_boss.steps_left = steps_left - 1u;
	if (steps_left != 1u)
	{
		if (random_number < stage_8_boss_run_skip_attack_chances_by_players[(int8_t)player_count])
			return stage_8_boss_take_hits(boss, enemy_handlers);
		return stage_8_boss_check_close_player(boss);
	}
	stage_8_boss_pick_player(&target_player, &direction);
	direction = vector_direction_to_offset(boss, target_player, direction);
	angle = (uint8_t)(direction >> 8);
	heading = ((uint32_t)angle << 8) | stage_8_boss_walk_speeds_by_players[(int8_t)player_count];
	vector_set_speed_by_direction(boss, heading);
	new_phase = 0xEu;
	stage_8_boss_start_state(boss, new_phase);
	stage_8_boss_face_motion(boss);
	return stage_8_boss_take_hits(boss, target_player);
}

/* Walks at its player dropping a bomb every 4 frames until its timer runs out, then fights on. */
uint16_t stage_8_boss_walk_and_bomb(uint16_t boss, uint16_t enemy_handlers)
{
	uint16_t bomb_count = 0, ignored16 = 0;
	uint8_t steps = 0, state_timer = 0;

	steps = OBJECT(boss)->stage_8_boss.steps;
	if ((steps & 3u) == 0u && (frame_count & 3u) == 0u)
	{
		bomb_count = 0x100u;
		stage_8_boss_throw_bombs(boss, bomb_count, &ignored16, &enemy_handlers);
	}
	state_timer = OBJECT(boss)->stage_8_boss.state_timer;
	OBJECT(boss)->stage_8_boss.state_timer = state_timer - 1u;
	if (state_timer != 1u)
		return stage_8_boss_check_close_player(boss);
	return stage_8_boss_resume(boss, enemy_handlers);
}

/* Starts its third phase: picks a random player to keep away from (state 0F). */
uint16_t stage_8_boss_phase_3(uint16_t boss)
{
	uint8_t new_phase = 0;
	uint16_t ignored16 = 0, player = 0;
	uint8_t count = 0;

	stage_8_boss_pick_player(&player, &ignored16);
	OBJECT(boss)->stage_8_boss.marked_player = player;
	new_phase = 0xFu;
	stage_8_boss_start_state(boss, new_phase);
	OBJECT(boss)->x_speed = 1;
	count = OBJECT(boss)->stage_8_boss.count;
	OBJECT(boss)->stage_8_boss.count = count + 1u;
	OBJECT(boss)->stage_8_boss.steps_left = 1u;
	stage_8_boss_set_on_floor(boss);
	return stage_8_boss_keep_away(boss);
}

/* Its third phase: backs away from its player, jumps at a player when it stops or every sixth time, and
   dashes at one every 64 frames when its count runs out. */
uint16_t stage_8_boss_keep_away(uint16_t boss)
{
	uint32_t carry = 0;
	uint8_t angle = 0, new_phase = 0;
	uint16_t direction = 0, heading = 0, ignored16 = 0, player = 0, target_player = 0, u = 0;
	uint8_t steps_left = 0, t1 = 0, count = 0;
	uint16_t marked_player = 0;

	if ((frame_count & 0x3Fu) == 0u)
	{
		steps_left = OBJECT(boss)->stage_8_boss.steps_left;
		OBJECT(boss)->stage_8_boss.steps_left = steps_left - 1u;
		if (steps_left == 1u)
		{
			stage_8_boss_pick_player(&u, &ignored16);
			direction = 0x14u;
			direction = vector_direction_to_offset(boss, u, direction);
			angle = (uint8_t)(direction >> 8);
			heading = ((uint32_t)angle << 8) | stage_8_boss_dash_speeds_by_players[(int8_t)player_count];
			vector_set_speed_by_direction(boss, heading);
			stage_8_boss_face_motion(boss);
			new_phase = 0x14u;
			stage_8_boss_start_state(boss, new_phase);
			OBJECT(boss)->stage_8_boss.steps_left = 3u;
			return stage_8_boss_move_and_take_hits(boss, u);
		}
		stage_8_boss_pick_player(&player, &ignored16);
		OBJECT(boss)->stage_8_boss.marked_player = player;
	}
	carry = stage_8_boss_is_still(boss);
	if (carry)
	{
		new_phase = 0x10u;
		stage_8_boss_start_state(boss, new_phase);
		OBJECT(boss)->z_speed = 0x900;
		t1 = (uint8_t)OBJECT(boss)->z;
		OBJECT(boss)->z = (OBJECT(boss)->z & 0xFF00u) | (t1 + 1u & 0xFFu);
		stage_8_boss_pick_player(&target_player, &ignored16);
		direction = vector_direction_to(boss, target_player);
		angle = (uint8_t)(direction >> 8);
		u = stage_8_boss_jump_speeds_by_players_ADDRESS;
		heading = ((uint32_t)angle << 8) | stage_8_boss_jump_speeds_by_players[(int8_t)player_count];
		vector_set_speed_by_direction(boss, heading);
		stage_8_boss_set_in_air(boss);
		stage_8_boss_face_motion(boss);
		OBJECT(boss)->stage_8_boss.count_down = 0u;
		OBJECT(boss)->stage_8_boss.count = 0u;
		return stage_8_boss_move_and_take_hits(boss, u);
	}
	count = OBJECT(boss)->stage_8_boss.count;
	if (count > 5u)
	{
		new_phase = 0x10u;
		stage_8_boss_start_state(boss, new_phase);
		OBJECT(boss)->z_speed = 0x900;
		t1 = (uint8_t)OBJECT(boss)->z;
		OBJECT(boss)->z = (OBJECT(boss)->z & 0xFF00u) | (t1 + 1u & 0xFFu);
		stage_8_boss_pick_player(&target_player, &ignored16);
		direction = vector_direction_to(boss, target_player);
		angle = (uint8_t)(direction >> 8);
		u = stage_8_boss_jump_speeds_by_players_ADDRESS;
		heading = ((uint32_t)angle << 8) | stage_8_boss_jump_speeds_by_players[(int8_t)player_count];
		vector_set_speed_by_direction(boss, heading);
		stage_8_boss_set_in_air(boss);
		stage_8_boss_face_motion(boss);
		OBJECT(boss)->stage_8_boss.count_down = 0u;
		OBJECT(boss)->stage_8_boss.count = 0u;
		return stage_8_boss_move_and_take_hits(boss, u);
	}
	marked_player = OBJECT(boss)->stage_8_boss.marked_player;
	u = marked_player;
	direction = vector_direction_to(boss, u);
	angle = (uint8_t)(direction >> 8);
	heading = ((uint32_t)(uint8_t)(angle - 0x80u) << 8) | stage_8_boss_retreat_speeds_by_players[(int8_t)player_count];
	vector_set_speed_by_direction(boss, heading);
	stage_8_boss_face_motion(boss);
	return stage_8_boss_move_and_take_hits(boss, u);
}

/* In its jump: drops bombs (every frame with 2 or more players), and fights on when it lands. */
uint16_t stage_8_boss_jump(uint16_t boss, uint16_t enemy_handlers)
{
	uint32_t carry = 0;
	uint16_t bomb_count = 0, ignored16 = 0, u = 0;
	uint8_t count_down = 0, count_down_2 = 0;

	stage_8_boss_move(boss, &ignored16, &carry);
	if (carry)
		return stage_8_boss_resume(boss, enemy_handlers);
	count_down = OBJECT(boss)->stage_8_boss.count_down;
	OBJECT(boss)->stage_8_boss.count_down = count_down + 1u;
	count_down_2 = OBJECT(boss)->stage_8_boss.count_down;
	if ((int8_t)player_count <= (int8_t)stage_8_boss_jump_bomb_player_limits[(int8_t)count_down_2])
		return stage_8_boss_take_hits(boss, enemy_handlers);
	OBJECT(boss)->stage_8_boss.count_down = 0u;
	bomb_count = 0x100u;
	stage_8_boss_throw_bombs(boss, bomb_count, &ignored16, &u);
	return stage_8_boss_take_hits(boss, u);
}

/* Its dash: goes on while it is fast and its timer lasts, then fights on. */
uint16_t stage_8_boss_dash(uint16_t boss, uint16_t enemy_handlers)
{
	uint16_t d = 0;
	uint8_t state_timer = 0;

	stage_8_boss_set_in_air(boss);
	d = stage_8_boss_speed(boss);
	if ((int16_t)d > 0xC0)
	{
		state_timer = OBJECT(boss)->stage_8_boss.state_timer;
		OBJECT(boss)->stage_8_boss.state_timer = state_timer - 1u;
		if (state_timer != 1u)
			return stage_8_boss_check_close_player(boss);
	}
	return stage_8_boss_resume(boss, enemy_handlers);
}

/* Back to fighting (state 09) with its usual box. */
uint16_t stage_8_boss_resume(uint16_t boss, uint16_t enemy_handlers)
{
	uint8_t new_phase = 0;
	uint16_t box = 0;

	new_phase = 9u;
	stage_8_boss_stop_and_start_state(boss, new_phase);
	box = stage_8_boss_box_ADDRESS;
	stage_8_boss_set_box(boss, box);
	return stage_8_boss_take_hits(boss, enemy_handlers);
}

/* A close player: winds up, then turns to the nearest player and attacks (state 11), safe meanwhile. */
uint16_t stage_8_boss_attack_wind_up(uint16_t boss, uint16_t enemy_handlers)
{
	uint32_t zero = 0;
	uint8_t new_phase = 0;
	uint16_t box = 0, target_player = 0;
	uint8_t state_timer = 0;

	stage_8_boss_make_vulnerable(boss);
	state_timer = OBJECT(boss)->stage_8_boss.state_timer;
	OBJECT(boss)->stage_8_boss.state_timer = state_timer - 1u;
	if (state_timer != 1u)
		return stage_8_boss_move_and_take_hits(boss, enemy_handlers);
	box = stage_8_boss_wind_up_box_ADDRESS;
	stage_8_boss_set_box(boss, box);
	target_player = stage_8_boss_face_nearest_player(boss);
	zero = stage_8_boss_make_invulnerable(boss);
	new_phase = 0x11u;
	stage_8_boss_stop_and_start_state(boss, new_phase);
	return stage_8_boss_move_and_take_hits(boss, target_player);
}

/* Its close attack, hitting with 040A at its frames, then its second part (state 12). */
uint16_t stage_8_boss_attack(uint16_t boss, uint16_t enemy_handlers)
{
	uint32_t zero = 0, carry = 0;
	uint8_t new_phase = 0;
	uint16_t damage = 0;

	damage = 0x40Au;
	carry = stage_8_boss_hit_on_frame(boss, damage);
	if (carry == 0u)
		return stage_8_boss_move_and_take_hits(boss, enemy_handlers);
	zero = stage_8_boss_make_invulnerable(boss);
	new_phase = 0x12u;
	stage_8_boss_stop_and_start_state(boss, new_phase);
	return stage_8_boss_move_and_take_hits(boss, enemy_handlers);
}

/* The close attack's second part, hitting with 040A, then fights on. */
uint16_t stage_8_boss_attack_2(uint16_t boss, uint16_t enemy_handlers)
{
	uint32_t carry = 0;
	uint16_t damage = 0;

	damage = 0x40Au;
	carry = stage_8_boss_hit_on_frame(boss, damage);
	if (carry == 0u)
		return stage_8_boss_move_and_take_hits(boss, enemy_handlers);
	return stage_8_boss_resume(boss, enemy_handlers);
}

/* Laughing (sound 79) until its timer runs out, then fights on. */
uint16_t stage_8_boss_laugh(uint16_t boss, uint16_t enemy_handlers)
{
	uint8_t state_timer = 0;

	state_timer = OBJECT(boss)->stage_8_boss.state_timer;
	OBJECT(boss)->stage_8_boss.state_timer = state_timer - 1u;
	if (state_timer != 1u)
		return stage_8_boss_move_and_take_hits(boss, enemy_handlers);
	return stage_8_boss_resume(boss, enemy_handlers);
}

/* State 0A: nothing. */
void stage_8_boss_idle(void)
{
}

/* With a player within 48 across and 16 in depth, starts its close attack (a short wind-up when it lost
   16 health since the last), then moves and takes hits. */
uint16_t stage_8_boss_check_close_player(uint16_t boss)
{
	uint32_t carry = 0;
	uint8_t new_phase = 0;
	uint16_t close_player = 0;
	uint8_t health_mark = 0, vitality = 0, vitality_2 = 0;

	reach_x = 0x30;
	reach_y = 0x10;
	stage_8_boss_find_close_player(boss, &close_player, &carry);
	if (carry == 0u)
		return stage_8_boss_move_and_take_hits(boss, close_player);
	new_phase = 0x1Du;
	stage_8_boss_stop_and_start_state(boss, new_phase);
	health_mark = OBJECT(boss)->stage_8_boss.health_mark;
	vitality = OBJECT(boss)->vitality;
	if ((uint8_t)(health_mark - vitality) > 0x10u)
	{
		vitality_2 = OBJECT(boss)->vitality;
		OBJECT(boss)->stage_8_boss.health_mark = vitality_2;
		return stage_8_boss_move_and_take_hits(boss, close_player);
	}
	OBJECT(boss)->stage_8_boss.state_timer = 0x14u;
	return stage_8_boss_move_and_take_hits(boss, close_player);
}

/* Unused: stops it and starts state 1D, then moves it and takes its hits. */
void unused_stage_8_boss_start_state_1d(uint16_t boss, uint16_t u)
{
	uint8_t new_phase = 0;

	new_phase = 0x1Du;
	stage_8_boss_stop_and_start_state(boss, new_phase);
	stage_8_boss_move_and_take_hits(boss, u);
}

/* Moves it, then takes the players' blows. */
uint16_t stage_8_boss_move_and_take_hits(uint16_t boss, uint16_t u)
{
	uint32_t carry = 0;
	uint16_t ignored16 = 0;

	stage_8_boss_move(boss, &ignored16, &carry);
	return stage_8_boss_take_hits(boss, u);
}

/* Takes a player's blow: flashes, turns to the hitter and reels (state 15) or falls (state 16, a strong
   blow or in the air); beaten, it cries out and starts its defeat (state 17). */
uint16_t stage_8_boss_take_hits(uint16_t boss, uint16_t u)
{
	uint32_t zero = 0, negative = 0, carry = 0;
	uint8_t new_phase = 0;
	uint16_t command = 0, ignored16 = 0, limits = 0, object = 0, palette_effect_number = 0;
	uint16_t stack = 0;
	uint8_t phases_left = 0, attributes = 0, attributes_2 = 0, attributes_3 = 0, hit = 0;
	uint16_t hit_by = 0, z_speed = 0, z = 0;

	limits = stage_8_boss_beaten_healths_by_players_ADDRESS;
	stage_8_boss_take_hit(boss, limits, &u, &zero, &negative);
	if (zero)
		return limits;
	if (negative)
	{
		command = 0x7900u;
		carry = vector_queue_sound(command);
		new_phase = 0x17u;
		return stage_8_boss_stop_and_start_state(boss, new_phase);
	}
	stack = boss;
	phases_left = OBJECT(boss)->stage_8_boss.phases_left;
	if (phases_left == 0u)
	{
		palette_request_kind = 2u;
		palette_effect_number = 0x41u;
		vector_palette_request(palette_effect_number, &ignored16, &u);
	}
	else
	{
		palette_request_kind = 2u;
		palette_effect_number = 0x40u;
		vector_palette_request(palette_effect_number, &ignored16, &u);
	}
	object = stack;
	hit_by = OBJECT(object)->hit_by;
	attributes = OBJECT(hit_by)->attributes;
	attributes_2 = OBJECT(object)->attributes;
	if (((attributes ^ attributes_2) & 0x40u) == 0u)
	{
		attributes_3 = OBJECT(object)->attributes;
		OBJECT(object)->attributes = attributes_3 ^ 0x40u;
	}
	hit = OBJECT(object)->hit;
	if ((int8_t)hit >= 0x13)
	{
		new_phase = 0x16u;
		return stage_8_boss_stop_and_start_state(object, new_phase);
	}
	z_speed = OBJECT(object)->z_speed;
	if ((int16_t)z_speed > 0x400)
		OBJECT(object)->z_speed = 0x400;
	z = OBJECT(object)->z;
	if (z != 0u)
	{
		new_phase = 0x16u;
		return stage_8_boss_stop_and_start_state(object, new_phase);
	}
	new_phase = 0x15u;
	return stage_8_boss_stop_and_start_state(object, new_phase);
}

/* Reeling or getting up: when the animation ends fights on; in its second phase, after enough blows, it
   can not be hurt for a while. */
uint16_t stage_8_boss_reel(uint16_t boss, uint16_t states, uint16_t enemy_handlers)
{
	uint32_t zero = 0, carry = 0;
	uint8_t players = 0;
	uint8_t animation_flags = 0, phases_left = 0, count = 0, count_2 = 0;

	stage_8_boss_move(boss, &states, &carry);
	animation_flags = OBJECT(boss)->animation_flags;
	if ((animation_flags & 1u) == 0u)
		return states;
	OBJECT(boss)->flags = 0xC0u;
	phases_left = OBJECT(boss)->stage_8_boss.phases_left;
	if (phases_left != 1u)
		return stage_8_boss_resume(boss, enemy_handlers);
	count = OBJECT(boss)->stage_8_boss.count;
	OBJECT(boss)->stage_8_boss.count = count + 1u;
	count_2 = OBJECT(boss)->stage_8_boss.count;
	players = player_count;
	if (count_2 <= mem_read8(stage_8_boss_hit_limits_address[0] + (int8_t)players))
		return stage_8_boss_resume(boss, enemy_handlers);
	OBJECT(boss)->stage_8_boss.count = 0u;
	states = stage_8_boss_invulnerable_times_by_players_ADDRESS;
	OBJECT(boss)->stage_8_boss.count_down = stage_8_boss_invulnerable_times_by_players[(int8_t)players];
	zero = stage_8_boss_make_invulnerable(boss);
	if (zero == 0u)
		return stage_8_boss_resume(boss, enemy_handlers);
	return states;
}

/* Knocked down: when the animation ends, gets up (state 1E). */
uint16_t stage_8_boss_fall_down(uint16_t boss, uint16_t landing_speed)
{
	uint32_t carry = 0;
	uint8_t new_phase = 0;
	uint8_t animation_flags = 0;

	stage_8_boss_move(boss, &landing_speed, &carry);
	animation_flags = OBJECT(boss)->animation_flags;
	if ((animation_flags & 1u) == 0u)
		return landing_speed;
	new_phase = 0x1Eu;
	return stage_8_boss_stop_and_start_state(boss, new_phase);
}

/* Its defeat: holds the scroll; at the animation's frame a blast (the bombs' sound 6F) hitting around it
   with strength 05; then the next state. */
uint16_t stage_8_boss_defeat_blast(uint16_t boss, uint16_t states)
{
	uint32_t carry = 0;
	uint8_t animation_bits = 0;
	uint16_t command = 0;
	uint8_t animation_flags = 0;

	camera_x_held = 1u;
	camera_y_held = 1u;
	OBJECT(boss)->damage = 0u;
	OBJECT(boss)->attack = 0u;
	OBJECT(boss)->flags = 0x80u;
	animation_flags = OBJECT(boss)->animation_flags;
	animation_bits = animation_flags;
	if ((animation_bits & 1u) != 0u)
		return stage_8_boss_next_state(boss);
	if ((animation_bits & 2u) == 0u)
		return states;
	command = 0x6F00u;
	carry = vector_queue_sound(command);
	OBJECT(boss)->damage = 0u;
	OBJECT(boss)->attack = 5u;
	OBJECT(boss)->flags = 0xC0u;
	return states;
}

/* Lies beaten until its timer runs out, then sends sound FD and goes on. */
uint16_t stage_8_boss_defeat_wait(uint16_t boss, uint16_t landing_speed)
{
	uint32_t carry = 0;
	uint16_t command = 0;
	uint8_t state_timer = 0;

	camera_x_held = 1u;
	camera_y_held = 1u;
	stage_8_boss_move(boss, &landing_speed, &carry);
	state_timer = OBJECT(boss)->stage_8_boss.state_timer;
	OBJECT(boss)->stage_8_boss.state_timer = state_timer - 1u;
	if (state_timer != 1u)
		return landing_speed;
	command = 0xFD00u;
	carry = vector_queue_sound(command);
	return stage_8_boss_next_state(boss);
}

/* Blinks out; then frees the scroll, says a boss is beaten (direct page 7D) and moves the step on
   (07B333 then plays the story before the robot). */
void stage_8_boss_vanish(uint16_t boss, uint8_t d)
{
	uint32_t carry = 0;
	uint32_t step_subphase_halfword = 0;

	carry = stage_8_boss_blink_out(boss);
	if (carry)
	{
		camera_x_held = 0u;
		camera_y_held = 0u;
		boss_beaten = 1u;
		step_phase++;
		step_subphase_halfword = 0x100u | d;
		step_subphase = (uint8_t)(step_subphase_halfword >> 8u);
		step_countdown = (uint8_t)step_subphase_halfword;
	}
}

/* Throws the bomb (kind 9C animation 89) at a random player, spread and sped by the bombs' random
   number, high enough for the distance; a bomb dropped while the boss walks just bounces about. */
void stage_8_boss_bomb_throw(uint16_t bomb, uint16_t *p_object, uint16_t *p_target_player)
{
	uint32_t carry = 0;
	uint8_t angle = 0, reach_high = 0, reach_low = 0, throw_speed_high = 0, throw_speed_low = 0;
	uint16_t command = 0, direction = 0, heading = 0, ignored16 = 0, object = 0, target_player = 0;
	uint8_t t1 = 0, state = 0, t2 = 0, target_dy = 0, phase = 0;
	uint16_t x_speed = 0, x_speed_2 = 0, t3 = 0, thrower = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, t8 = 0, t9 = 0, t10 = 0, t11 = 0, t12 = 0, t13 = 0, t14 = 0, t15 = 0, t16 = 0, z = 0;

	OBJECT(bomb)->flags = 0x80u;
	OBJECT(bomb)->kind = 0x9Cu;
	OBJECT(bomb)->animation = 0x89u;
	stage_8_boss_set_in_air(bomb);
	OBJECT(bomb)->shadow_player = 2u;
	t1 = io_read8(0x1852u);
	bomb_spread = (t1 & 7u) - 3u;
	stage_8_boss_pick_player(&target_player, &ignored16);
	state = OBJECT(target_player)->state;
	if ((int8_t)state >= 0)
	{
		direction = vector_direction_to(bomb, target_player);
		angle = (uint8_t)(direction >> 8);
	}
	else
		angle = random_number;
	t2 = io_read8(0x1852u);
	heading = ((uint32_t)(uint8_t)(angle + bomb_spread) << 8) | (uint8_t)((((t2 & 0x78u) >> 1) >> 1) + 0x1Au);
	vector_set_speed_by_direction(bomb, heading);
	x_speed = OBJECT(bomb)->x_speed;
	x_speed_2 = OBJECT(bomb)->x_speed;
	t3 = x_speed + x_speed_2;
	OBJECT(bomb)->x_speed = t3;
	thrower = OBJECT(bomb)->stage_8_boss_bomb.thrower;
	object = thrower;
	target_dy = (uint8_t)(OBJECT(object)->target_dy >> 8u);
	if (target_dy == 0xEu)
	{
		OBJECT(bomb)->stage_8_boss_bomb.phase = 3u;
		OBJECT(bomb)->stage_8_boss_bomb.state_timer = 0xA0u;
	}
	else
	{
		t4 = OBJECT(bomb)->x;
		t5 = OBJECT(target_player)->x;
		t6 = t4 - t5;
		t7 = t6;
		t8 = t7 >> 15 ? 0u - t7 : t7;
		bomb_distance = t8;
		t9 = OBJECT(bomb)->y;
		t10 = OBJECT(target_player)->y;
		t11 = t9 - t10;
		t12 = t11;
		t13 = t12 >> 15 ? 0u - t12 : t12;
		t14 = t13 + bomb_distance;
		t15 = t14 + bomb_distance;
		reach_high = (uint8_t)(t15 >> 8);
		reach_low = (uint8_t)t15;
		bomb_distance = ((uint32_t)reach_high << 8) | reach_low;
		t16 = (((uint32_t)reach_high << 8) | reach_low) + bomb_distance;
		throw_speed_high = (uint8_t)(t16 >> 8);
		throw_speed_low = (uint8_t)t16;
		OBJECT(bomb)->z_speed = ((uint32_t)throw_speed_high << 8) | throw_speed_low;
		if ((int16_t)(((uint32_t)throw_speed_high << 8) | throw_speed_low) >= 0x2C0)
		{
			command = 0x301u;
			carry = vector_queue_sound(command);
		}
		else
		{
			z = OBJECT(bomb)->z;
			if (z > 0x40u)
			{
				command = 0x301u;
				carry = vector_queue_sound(command);
			}
		}
		phase = OBJECT(bomb)->stage_8_boss_bomb.phase;
		OBJECT(bomb)->stage_8_boss_bomb.phase = phase + 1u;
		object = 0x1852u;
		stage_8_boss_next_random(object);
	}
	*p_object = object;
	*p_target_player = target_player;
}

/* A dropped bomb bouncing until its timer runs out, then it blows up. */
void stage_8_boss_bomb_bounce(uint16_t bomb, uint16_t *p_object, uint16_t *p_u)
{
	uint16_t object = (uint16_t)*p_object;
	uint16_t u = (uint16_t)*p_u;
	uint8_t state_timer = 0;

	state_timer = OBJECT(bomb)->stage_8_boss_bomb.state_timer;
	OBJECT(bomb)->stage_8_boss_bomb.state_timer = state_timer - 1u;
	if (state_timer == 1u)
		object = stage_8_boss_bomb_explode(bomb);
	else
		stage_8_boss_bomb_fly(bomb, &object, &u);
	*p_object = object;
	*p_u = u;
}

/* A flying bomb: falls, stopped by walls; on the floor it blows up (at once when a player is down or the
   boss beaten), or bounces on when the boss is bombing on the run, and by chance in its second phase. */
void stage_8_boss_bomb_fly(uint16_t bomb, uint16_t *p_object, uint16_t *p_u)
{
	uint16_t object = (uint16_t)*p_object;
	uint32_t negative = 0, carry = 0;
	uint16_t floor_cell = 0, z_speed = 0;
	uint8_t vitality = 0, target_dy = 0, t1 = 0, t2 = 0;
	uint16_t z = 0, thrower = 0, x_speed = 0, x_speed_2 = 0, x_speed_3 = 0, y_speed = 0, y_speed_2 = 0, y_speed_3 = 0, z_speed_2 = 0, z_speed_3 = 0;

	z = OBJECT(bomb)->z;
	z_speed = z;
	if ((int16_t)z < 0)
	{
		carry = stage_8_boss_player_down();
		if (carry)
			object = stage_8_boss_bomb_explode(bomb);
		else
		{
			thrower = OBJECT(bomb)->stage_8_boss_bomb.thrower;
			object = thrower;
			vitality = OBJECT(object)->vitality;
			if (vitality == 0u)
				object = stage_8_boss_bomb_explode(bomb);
			else
			{
				target_dy = (uint8_t)(OBJECT(object)->target_dy >> 8u);
				if ((uint16_t)((uint32_t)target_dy << 8) >> 8 == 0xEu)
				{
					x_speed = OBJECT(bomb)->x_speed;
					x_speed_2 = OBJECT(bomb)->x_speed;
					x_speed_3 = OBJECT(bomb)->x_speed;
					OBJECT(bomb)->x_speed = (int16_t)(x_speed + x_speed_2 + x_speed_3) >> 2;
					y_speed = OBJECT(bomb)->y_speed;
					y_speed_2 = OBJECT(bomb)->y_speed;
					y_speed_3 = OBJECT(bomb)->y_speed;
					OBJECT(bomb)->y_speed = (int16_t)(y_speed + y_speed_2 + y_speed_3) >> 2;
					z_speed_2 = OBJECT(bomb)->z_speed;
					OBJECT(bomb)->z_speed = 0u - ((int16_t)z_speed_2 >> 1);
					OBJECT(bomb)->z = 0u;
				}
				else
				{
					t1 = (uint8_t)OBJECT(object)->target_dx;
					if ((uint16_t)((uint32_t)t1 << 8) >> 8 != 1u)
						object = stage_8_boss_bomb_explode(bomb);
					else
					{
						object = 0x1852u;
						stage_8_boss_next_random(object);
						t2 = io_read8(0x1852u);
						if ((int8_t)t2 >= 0)
							object = stage_8_boss_bomb_explode(bomb);
						else
						{
							x_speed = OBJECT(bomb)->x_speed;
							x_speed_2 = OBJECT(bomb)->x_speed;
							x_speed_3 = OBJECT(bomb)->x_speed;
							OBJECT(bomb)->x_speed = (int16_t)(x_speed + x_speed_2 + x_speed_3) >> 2;
							y_speed = OBJECT(bomb)->y_speed;
							y_speed_2 = OBJECT(bomb)->y_speed;
							y_speed_3 = OBJECT(bomb)->y_speed;
							OBJECT(bomb)->y_speed = (int16_t)(y_speed + y_speed_2 + y_speed_3) >> 2;
							z_speed_2 = OBJECT(bomb)->z_speed;
							OBJECT(bomb)->z_speed = 0u - ((int16_t)z_speed_2 >> 1);
							OBJECT(bomb)->z = 0u;
						}
					}
				}
			}
		}
	}
	else
	{
		z_speed_3 = OBJECT(bomb)->z_speed;
		z_speed = z_speed_3 - 0x18u;
		OBJECT(bomb)->z_speed = z_speed;
		vector_floor_ahead(bomb, &floor_cell, &negative);
		if ((uint8_t)((floor_cell >> 8) + 1u) == 0u)
		{
			OBJECT(bomb)->x_speed = 0;
			OBJECT(bomb)->y_speed = 0;
		}
	}
	*p_object = object;
	*p_u = z_speed;
}

/* Blows the bomb up: stopped on the floor, sound 6F, its blast (animation 8A) hitting with 0405 in its
   box. */
uint16_t stage_8_boss_bomb_explode(uint16_t bomb)
{
	uint32_t carry = 0;
	uint16_t animation_number = 0, box = 0, command = 0, state_wait = 0;

	OBJECT(bomb)->x_speed = 0;
	OBJECT(bomb)->y_speed = 0;
	OBJECT(bomb)->z_speed = 0;
	OBJECT(bomb)->z = 0u;
	OBJECT(bomb)->flags = 0xC0u;
	command = 0x6F00u;
	carry = vector_queue_sound(command);
	stage_8_boss_set_on_floor(bomb);
	state_wait = 0x200u;
	animation_number = 0x8A00u;
	stage_8_boss_bomb_set_state(bomb, state_wait, animation_number);
	OBJECT(bomb)->damage = 4u;
	OBJECT(bomb)->attack = 5u;
	box = stage_8_boss_bomb_blast_box_ADDRESS;
	return stage_8_boss_set_box(bomb, box);
}

/* The blast: harms only until its hit frame, gone when the animation ends. */
void stage_8_boss_bomb_blast(uint16_t bomb)
{
	uint8_t animation_bits = 0;
	uint8_t animation_flags = 0;

	animation_flags = OBJECT(bomb)->animation_flags;
	animation_bits = animation_flags;
	if ((animation_bits & 2u) != 0u)
		OBJECT(bomb)->flags = 0x80u;
	if (animation_bits & 1u)
	{
		OBJECT(bomb)->flags = 0u;
		return;
	}
}

/* Puts in A bombs (the last in the 5280 list when the 4D40 list is full); on the floor within the play
   area also puts in the child 7A8C (type E1, state 26) under it. */
void stage_8_boss_throw_bombs(uint16_t boss, uint16_t bomb_count, uint16_t *p_child_record, uint16_t *p_child)
{
	uint32_t carry = 0;
	uint16_t child = 0, child_record = 0, ignored16 = 0, record = 0, x_place = 0;
	uint8_t t1 = 0;
	uint16_t z = 0, t2 = 0, t3 = 0;

	bombs_left = bomb_count >> 8;
	do
	{
		child_record = stage_8_boss_throw_child_1_ADDRESS;
		spawn_list_2_child(boss, child_record, &child, &carry);
		if (carry == 0u)
		{
			record = stage_8_boss_throw_child_2_ADDRESS;
			*p_child = child;
			vector_spawn_child(boss, record, p_child, &ignored16, &carry);
			*p_child_record = record;
			return;
		}
		t1 = bombs_left;
		bombs_left = t1 - 1u;
	} while (t1 != 1u);
	z = OBJECT(boss)->z;
	if (z == 0u)
	{
		t2 = OBJECT(boss)->x;
		x_place = t2;
		if ((int16_t)x_place > 0x30 && (int16_t)x_place < 0x1A0)
		{
			t3 = OBJECT(boss)->y;
			if ((int16_t)t3 > 0x90)
			{
				child_record = stage_8_boss_throw_child_3_ADDRESS;
				vector_spawn_child(boss, child_record, &child, &ignored16, &carry);
			}
		}
	}
	*p_child_record = child_record;
	*p_child = child;
}

/* Steps the random number Y points at: times 5 plus 3711. */
uint16_t stage_8_boss_next_random(uint16_t seed)
{
	uint16_t previous = 0;
	uint16_t stack = 0;

	previous = mem_read16(seed);
	stack = previous;
	previous = previous + mem_read16(seed) + mem_read16(seed) + mem_read16(seed) + stack + 0x3711u;
	mem_write16(seed, previous);
	return previous;
}

/* Turns it to the way it moves, starting its animation again (as stage_8_boss_face_motion). */
void stage_8_boss_turn_to_motion(uint16_t boss)
{
	uint8_t old_attributes = 0;
	uint8_t attributes = 0, animation = 0, attributes_2 = 0;
	uint16_t x_speed = 0;

	x_speed = OBJECT(boss)->x_speed;
	if ((int16_t)x_speed < 0)
	{
		attributes = OBJECT(boss)->attributes;
		old_attributes = attributes;
		if ((old_attributes & 0x40u) == 0u)
		{
			OBJECT(boss)->attributes = old_attributes ^ 0x40u;
			animation = OBJECT(boss)->animation;
			OBJECT(boss)->animation = animation | 0x80u;
		}
		return;
	}
	attributes_2 = OBJECT(boss)->attributes;
	old_attributes = attributes_2;
	if ((old_attributes & 0x40u) == 0u)
		return;
	if ((old_attributes & 0x40u) != 0u)
	{
		OBJECT(boss)->attributes = old_attributes ^ 0x40u;
		animation = OBJECT(boss)->animation;
		OBJECT(boss)->animation = animation | 0x80u;
		return;
	}
	attributes = OBJECT(boss)->attributes;
	old_attributes = attributes;
	if ((old_attributes & 0x40u) == 0u)
	{
		OBJECT(boss)->attributes = old_attributes ^ 0x40u;
		animation = OBJECT(boss)->animation;
		OBJECT(boss)->animation = animation | 0x80u;
	}
}

/* Its speed: its x and y speeds' sizes added. */
uint16_t stage_8_boss_speed(uint16_t boss)
{
	uint16_t speed = 0;
	uint16_t stack = 0;
	uint16_t x_speed = 0, y_speed = 0;

	x_speed = OBJECT(boss)->x_speed;
	stack = x_speed >> 15 ? 0u - x_speed : x_speed;
	y_speed = OBJECT(boss)->y_speed;
	speed = (y_speed >> 15 ? 0u - y_speed : y_speed) + stack;
	return speed;
}
