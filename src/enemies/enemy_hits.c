/**
 *    Name:        enemies/enemy_hits.c
 *    Description: an enemy taking a hit, the reaction it starts, letting go of its target
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    11-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the game's 053248 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

/* When the enemy was hit by an attack (kinds 11-14) and is not going down: credits the player that hit
   it, takes it out of the hit checks into its hit reactions (state 4) and notes which way the hit pushes
   it and who gets its score; otherwise its caller returns at once. */
void enemy_take_hit(uint16_t object, uint16_t *p_object_2, uint32_t *p_left_caller)
{
	uint16_t object_2 = (uint16_t)*p_object_2;
	uint32_t hitter_still = 0, hitter_moving_left = 0;
	uint16_t object_3 = 0;
	uint32_t left_caller = 0;
	uint8_t hit = 0, state = 0, kind = 0, kind_2 = 0, behaviour = 0, attributes = 0;
	uint16_t hit_by = 0, hit_by_2 = 0, x_speed = 0;

	if ((OBJECT(object)->flags & 0x20u) == 0u)
		left_caller = 1u;
	else
	{
		hit = OBJECT(object)->hit;
		if (hit < 0x11 || hit > 0x14)
			left_caller = 1u;
		else
		{
			state = OBJECT(object)->state;
			if ((int8_t)state < 0)
				left_caller = 1u;
			else
			{
				hit_by = OBJECT(object)->hit_by;
				object_3 = hit_by;
				kind = OBJECT(object)->kind;
				if ((int8_t)kind < 0)
				{
					kind_2 = OBJECT(object_3)->kind;
					if (kind_2 <= 3u)
					{
						behaviour = (uint8_t)(OBJECT(object_3)->behaviour >> 8u);
						OBJECT(object_3)->behaviour = (OBJECT(object_3)->behaviour & 0xFFu) | ((behaviour + 1u & 0xFFu) << 8u);
						AT16(OBJECT(object_3)->hit_box, -1) = object;
					}
				}
				OBJECT(object)->flags = 0x80u;
				OBJECT(object)->state = 4u;
				attributes = OBJECT(object)->attributes;
				OBJECT(object)->hit_from_behind = attributes & 0x40u;
				hit_by_2 = OBJECT(object)->hit_by;
				object_2 = hit_by_2;
				x_speed = OBJECT(object_2)->x_speed;
				hitter_moving_left = x_speed >> 15;
				hitter_still = x_speed == 0u;
				left_caller = 0u;
				enemy_set_knock_direction(object, object_2, hitter_still, hitter_moving_left);
			}
		}
	}
	*p_object_2 = object_2;
	*p_left_caller = left_caller;
}

/* Notes whether the hit pushes the enemy the way it faces (by the hitter's x speed, or by the side the
   hitter stands when it does not move) and takes the hitter's player number for its score. */
void enemy_set_knock_direction(uint16_t object, uint16_t hitter, uint32_t hitter_still, uint32_t hitter_moving_left)
{
	uint8_t hitter_player_bits = 0;
	uint8_t shadow_player = 0, points = 0, hit_from_behind = 0;
	uint16_t hitter_x = 0, enemy_x = 0;

	if (hitter_moving_left)
	{
		shadow_player = OBJECT(hitter)->shadow_player;
		hitter_player_bits = shadow_player & 0x70u;
		points = OBJECT(object)->points;
		OBJECT(object)->points = (points & 0x8Fu) | hitter_player_bits;
		return;
	}
	if (hitter_still)
	{
		hitter_x = OBJECT(hitter)->x;
		enemy_x = OBJECT(object)->x;
		if (hitter_x < enemy_x)
		{
			hit_from_behind = OBJECT(object)->hit_from_behind;
			OBJECT(object)->hit_from_behind = hit_from_behind ^ 0x40u;
		}
		shadow_player = OBJECT(hitter)->shadow_player;
		hitter_player_bits = shadow_player & 0x70u;
		points = OBJECT(object)->points;
		OBJECT(object)->points = (points & 0x8Fu) | hitter_player_bits;
		return;
	}
	hit_from_behind = OBJECT(object)->hit_from_behind;
	OBJECT(object)->hit_from_behind = hit_from_behind ^ 0x40u;
	shadow_player = OBJECT(hitter)->shadow_player;
	hitter_player_bits = shadow_player & 0x70u;
	points = OBJECT(object)->points;
	OBJECT(object)->points = (points & 0x8Fu) | hitter_player_bits;
}

/* When the enemy was hit by an attack: takes the hit and starts the hit reaction its kind gives (kinds
   11 and 12 a flinch or a fall, 13 sent flying, 14 knocked down). */
void enemy_check_hit(uint16_t object, uint16_t *p_reaction_handlers, uint32_t *p_left_caller)
{
	uint16_t reaction_handlers = (uint16_t)*p_reaction_handlers;
	uint8_t hit = 0;

	enemy_take_hit(object, &reaction_handlers, p_left_caller);
	if (*p_left_caller != 0u)
		*p_left_caller = 0u;
	else
	{
		reaction_handlers = enemy_hit_kind_reactions_ADDRESS;
		hit = OBJECT(object)->hit;
		switch ((int8_t)(uint8_t)((hit - 0x11u) << 1))
		{
		case 0:
		case 2:
			enemy_react_to_hit(object);
			break;
		case 4:
			enemy_react_sent_flying(object);
			break;
		case 6:
			enemy_react_knocked_down(object);
			break;
		}
	}
	*p_reaction_handlers = reaction_handlers;
}

/* Picks the reaction to a hit of kind 11 or 12: with no life left or in the air, knocked down or sent
   flying by turns; pushed the way it faces, the flinch from behind; else the flinch of its kind. */
void enemy_react_to_hit(uint16_t object)
{
	uint8_t action = 0;
	uint8_t vitality = 0, knock_turn = 0, next_knock_turn = 0, hit_from_behind = 0, hit = 0;
	uint16_t z_speed = 0;

	vitality = OBJECT(object)->vitality;
	if (vitality == 0u)
	{
		knock_turn = io_read8(knockdown_turn);
		io_write8(knockdown_turn, knock_turn - 1u);
		next_knock_turn = io_read8(knockdown_turn);
		if ((next_knock_turn & 1u) == 0u)
		{
			enemy_react_knocked_down(object);
			return;
		}
		enemy_react_sent_flying(object);
		return;
	}
	z_speed = OBJECT(object)->z_speed;
	if (z_speed != 0u)
	{
		knock_turn = io_read8(knockdown_turn);
		io_write8(knockdown_turn, knock_turn - 1u);
		next_knock_turn = io_read8(knockdown_turn);
		if ((next_knock_turn & 1u) == 0u)
		{
			enemy_react_knocked_down(object);
			return;
		}
		enemy_react_sent_flying(object);
		return;
	}
	hit_from_behind = OBJECT(object)->hit_from_behind;
	if (hit_from_behind == 0u)
	{
		hit = OBJECT(object)->hit;
		if (hit == 0x11u)
			action = 9u;
		else
			action = 1u;
	}
	else
		action = 0u;
	OBJECT(object)->action = action;
	OBJECT(object)->action_step = 0u;
}

/* Starts the hit reaction of being sent flying, forward or backward by which way the hit pushes it. */
void enemy_react_sent_flying(uint16_t object)
{
	uint8_t action = 0;
	uint8_t hit_from_behind = 0;

	hit_from_behind = OBJECT(object)->hit_from_behind;
	if (hit_from_behind == 0u)
		action = 8u;
	else
		action = 7u;
	OBJECT(object)->action = action;
	OBJECT(object)->action_step = 0u;
}

/* Starts the hit reaction of being knocked down, forward or backward by which way the hit pushes it. */
void enemy_react_knocked_down(uint16_t object)
{
	uint8_t action = 0;
	uint8_t hit_from_behind = 0;

	hit_from_behind = OBJECT(object)->hit_from_behind;
	if (hit_from_behind == 0u)
		action = 3u;
	else
		action = 2u;
	OBJECT(object)->action = action;
	OBJECT(object)->action_step = 0u;
}

/* Marks the enemy defeated (its score is given) and lets go of its target. */
uint16_t enemy_mark_defeated(uint16_t object, uint16_t target)
{
	uint8_t points = 0;

	points = OBJECT(object)->points;
	OBJECT(object)->points = points | 0x80u;
	return enemy_release_target(object, target);
}

/* An enemy that counts as one goes off its target: one attacker fewer on that player, and the side it
   took given back. */
uint16_t enemy_release_target(uint16_t object, uint16_t target)
{
	uint8_t enemy_class = 0, attackers = 0, attackers_left = 0;
	uint16_t target_2 = 0;

	enemy_class = OBJECT(object)->enemy_class;
	if ((int8_t)enemy_class < 0)
		return target;
	target_2 = OBJECT(object)->target;
	target = target_2;
	attackers = OBJECT(target)->player.attackers;
	attackers_left = attackers - 1u;
	OBJECT(target)->player.attackers = attackers_left;
	if ((int8_t)attackers_left < 0)
		OBJECT(target)->player.attackers = 0u;
	enemy_leave_side(object, target);
	return target;
}

/* Gives the target's side back when the enemy holds one. */
void enemy_leave_side_if_holding(uint16_t object, uint16_t target)
{
	uint8_t parameter = 0;

	parameter = OBJECT(object)->parameter;
	if (parameter != 1u)
		return;
	enemy_leave_side(object, target);
}

/* Gives back the side of its target the enemy took (one of the player's two attack slots) and goes back
   to coming at it. */
void enemy_leave_side(uint16_t object, uint16_t target)
{
	uint8_t side_flags = 0, target_sides = 0;
	uint8_t sides_taken = 0, side = 0;

	sides_taken = OBJECT(target)->player.sides_taken;
	target_sides = sides_taken;
	side = OBJECT(object)->enemy.side;
	side_flags = side;
	if ((int8_t)side >= 0)
		target_sides &= 0x7Fu;
	else
	{
		OBJECT(object)->enemy.side = side_flags & 0x7Fu;
		target_sides &= 0xBFu;
	}
	OBJECT(target)->player.sides_taken = target_sides;
	OBJECT(object)->parameter = 0u;
	OBJECT(object)->timer = 0u;
}
