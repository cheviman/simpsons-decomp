/**
 *    Name:        enemies/enemy_facing.c
 *    Description: an enemy facing its target and its walk animation by direction
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    10-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the game's 053248 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

/* Turns the enemy to face its target, by the direction to it. */
void enemy_face_target(uint16_t object)
{
	uint8_t attributes = 0;
	uint8_t attributes_2 = 0, target_direction = 0;

	attributes_2 = OBJECT(object)->attributes;
	attributes = attributes_2;
	target_direction = OBJECT(object)->target_direction;
	if ((int8_t)(target_direction - 0x40u) >= 0)
		attributes |= 0x40u;
	else
		attributes &= 0xBFu;
	OBJECT(object)->attributes = attributes;
}

/* Sets the enemy's walk animation toward the front or the back by where its target is, faces it, and
   starts the animation again. */
void enemy_restart_walk_animation(uint16_t object)
{
	uint8_t animation = 0;

	enemy_walk_animation_by_depth(object);
	animation = OBJECT(object)->animation;
	OBJECT(object)->animation = animation | 0x80u;
}

/* Picks the enemy's walk animation by where its target is: sideways when level with it in depth, toward
   the front or the back otherwise (changed only when the target moves into another quarter), and faces
   it. */
void enemy_pick_walk_animation(uint16_t object)
{
	uint8_t animation = 0, walk_quarter = 0;
	uint8_t target_direction = 0, target_direction_2 = 0, walk_quarter_2 = 0, animation_2 = 0;
	uint16_t target_dy = 0;

	target_dy = OBJECT(object)->target_dy;
	if (target_dy < 0x10u)
	{
		target_direction = OBJECT(object)->target_direction;
		OBJECT(object)->enemy.walk_quarter = target_direction & 0xC0u;
		animation = 1u;
		OBJECT(object)->animation = animation;
		enemy_face_target(object);
		return;
	}
	target_direction_2 = OBJECT(object)->target_direction;
	walk_quarter = target_direction_2 & 0xC0u;
	walk_quarter_2 = OBJECT(object)->enemy.walk_quarter;
	if (walk_quarter != walk_quarter_2)
	{
		OBJECT(object)->enemy.walk_quarter = walk_quarter;
		enemy_walk_animation_by_depth(object);
		return;
	}
	animation_2 = OBJECT(object)->animation;
	if (animation_2 == 1u)
	{
		enemy_walk_animation_by_depth(object);
		return;
	}
}

/* Sets the enemy's walk animation toward the front or the back by where its target is, and faces it. */
void enemy_walk_animation_by_depth(uint16_t object)
{
	uint8_t animation = 0;
	uint8_t target_direction = 0;

	target_direction = OBJECT(object)->target_direction;
	if ((int8_t)target_direction >= 0)
		animation = 3u;
	else
		animation = 2u;
	OBJECT(object)->animation = animation;
	enemy_face_target(object);
}

/* Keeps the direction to the target (what the moves compare with to aim again) and picks the walk
   animation. */
void enemy_pick_walk_animation_noting_direction(uint16_t object)
{
	uint8_t target_direction = 0;

	target_direction = OBJECT(object)->target_direction;
	OBJECT(object)->enemy.aimed_direction = target_direction;
	enemy_pick_walk_animation(object);
}
