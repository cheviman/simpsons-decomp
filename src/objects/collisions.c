/**
 *    Name:        objects/collisions.c
 *    Description: the hit checks: the players against the enemies, the child objects, list 1's objects and each other
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    10-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the game's 053248 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

/* Each frame of play: clears last frame's hits, then checks the players and their partners against the
   enemies, the players against the child objects, the players and partners against list 1's objects, and
   the players against each other. */
void check_collisions(uint16_t *p_object, uint16_t *p_d)
{
	uint16_t d = 0, object = 0;

	d = clear_hits();
	d = collide_players_with_enemies(d);
	d = collide_players_with_child_objects(d);
	d = collide_players_with_list_1_objects(d);
	*p_object = object;
	*p_d = d;
	collide_players_with_players(p_object, p_d);
}

/* Clears the hit flag and the kind of hit taken of the 32 objects from the players' on (all but the
   stage's event object). */
uint16_t clear_hits(void)
{
	uint8_t count = 0, flags = 0;
	uint16_t count_and_flags = 0, object = 0;
	uint8_t objects_left = 0;

	object = OBJECT_ADDRESS(0);
	count = 0x20u;
	do
	{
		flags = OBJECT(object)->flags & 0xDFu;
		OBJECT(object)->flags = flags;
		OBJECT(object)->hit = 0u;
		object += 0x60u;
		objects_left = count;
		count = objects_left - 1u;
	} while (objects_left != 1u);
	count_and_flags = ((uint32_t)count << 8) | flags;
	return count_and_flags;
}

/* Every player and partner in the hit checks against every enemy in them: where their boxes overlap,
   they trade hits. */
uint16_t collide_players_with_enemies(uint16_t d)
{
	uint32_t carry = 0;
	uint8_t flags = 0;
	uint16_t last_flags_word = 0, object = 0, object_2 = 0;
	uint8_t enemy_checks_left = 0, players_left = 0;

	object = OBJECT_ADDRESS(0);
	hit_check_players_left = 8u;
	do
	{
		flags = OBJECT(object)->flags;
		if ((flags & 0x40u) != 0u)
		{
			object_2 = OBJECT_ADDRESS(14);
			hit_check_enemies_left = 8u;
			do
			{
				flags = OBJECT(object_2)->flags;
				if ((flags & 0x40u) != 0u)
				{
					boxes_overlap(object, object_2, &d, &carry);
					flags = (uint8_t)(d >> 8);
					if (carry)
					{
						trade_hits_with_enemy(object, object_2);
						flags = (uint8_t)(d >> 8);
					}
				}
				object_2 += 0x60u;
				enemy_checks_left = hit_check_enemies_left;
				hit_check_enemies_left = enemy_checks_left - 1u;
			} while (enemy_checks_left != 1u);
		}
		object += 0x60u;
		players_left = hit_check_players_left;
		hit_check_players_left = players_left - 1u;
	} while (players_left != 1u);
	last_flags_word = (d & 0xFFu) | ((uint32_t)flags << 8);
	return last_flags_word;
}

/* Every player in the hit checks against every child object in them: where their boxes overlap, they
   trade hits unless the player is attacking. */
uint16_t collide_players_with_child_objects(uint16_t d)
{
	uint32_t carry = 0;
	uint8_t flags = 0;
	uint16_t last_flags_word = 0, object = 0, object_2 = 0;
	uint8_t children_left = 0, players_left = 0;

	object = OBJECT_ADDRESS(0);
	hit_check_players_left = 4u;
	do
	{
		flags = OBJECT(object)->flags;
		if ((flags & 0x40u) != 0u)
		{
			object_2 = OBJECT_ADDRESS(8);
			hit_check_children_left = 6u;
			do
			{
				flags = OBJECT(object_2)->flags;
				if ((flags & 0x40u) != 0u)
				{
					boxes_overlap(object, object_2, &d, &carry);
					flags = (uint8_t)(d >> 8);
					if (carry)
					{
						trade_hits_unless_attacking(object, object_2);
						flags = (uint8_t)(d >> 8);
					}
				}
				object_2 += 0x60u;
				children_left = hit_check_children_left;
				hit_check_children_left = children_left - 1u;
			} while (children_left != 1u);
		}
		object += 0xC0u;
		players_left = hit_check_players_left;
		hit_check_players_left = players_left - 1u;
	} while (players_left != 1u);
	last_flags_word = (d & 0xFFu) | ((uint32_t)flags << 8);
	return last_flags_word;
}

/* Every player and partner in the hit checks against every object of list 1 in them: where their boxes
   overlap, they trade hits unless the player is attacking. */
uint16_t collide_players_with_list_1_objects(uint16_t d)
{
	uint32_t carry = 0;
	uint8_t flags = 0;
	uint16_t last_flags_word = 0, object = 0, object_2 = 0;
	uint8_t list_1_left = 0, players_left = 0;

	object = OBJECT_ADDRESS(0);
	hit_check_players_left = 8u;
	do
	{
		flags = OBJECT(object)->flags;
		if ((flags & 0x40u) != 0u)
		{
			object_2 = OBJECT_ADDRESS(22);
			hit_check_list_1_left = 0xAu;
			do
			{
				flags = OBJECT(object_2)->flags;
				if ((flags & 0x40u) != 0u)
				{
					boxes_overlap(object, object_2, &d, &carry);
					flags = (uint8_t)(d >> 8);
					if (carry)
					{
						trade_hits_unless_attacking(object, object_2);
						flags = (uint8_t)(d >> 8);
					}
				}
				object_2 += 0x60u;
				list_1_left = hit_check_list_1_left;
				hit_check_list_1_left = list_1_left - 1u;
			} while (list_1_left != 1u);
		}
		object += 0x60u;
		players_left = hit_check_players_left;
		hit_check_players_left = players_left - 1u;
	} while (players_left != 1u);
	last_flags_word = (d & 0xFFu) | ((uint32_t)flags << 8);
	return last_flags_word;
}

/* Unused: checks the object's box against list 1's objects, trading hits with each it touches. */
void unused_collide_with_list_1_objects(uint16_t checked)
{
	uint32_t carry = 0;
	uint16_t ignored16 = 0, object = 0;
	uint8_t list_1_left = 0;

	OBJECT(checked)->flags &= 0xDFu;
	OBJECT(checked)->hit = 0u;
	object = OBJECT_ADDRESS(22);
	hit_check_list_1_left = 0xAu;
	do
	{
		if ((OBJECT(object)->flags & 0x40u) != 0u)
		{
			boxes_overlap(checked, object, &ignored16, &carry);
			if (carry)
				trade_hits_unless_attacking(checked, object);
		}
		object += 0x60u;
		list_1_left = hit_check_list_1_left;
		hit_check_list_1_left = list_1_left - 1u;
	} while (list_1_left != 1u);
}

/* Whether two objects' hit boxes overlap (carry set): in depth, in x (the box's x offset mirrored by the
   facing) and in height, each the distance between the boxes' centres against their two half sizes. */
void boxes_overlap(uint16_t object, uint16_t other, uint16_t *p_overlap_word, uint32_t *p_carry)
{
	uint32_t carry = *p_carry;
	uint8_t distance_high = 0, distance_low = 0;
	uint16_t overlap_word = 0;
	uint8_t box_dy = 0, box_dy_2 = 0, box_depth = 0, box_depth_2 = 0, box_dx = 0, attributes = 0, box_dx_2 = 0, attributes_2 = 0, box_width = 0, box_width_2 = 0, box_dz = 0, box_dz_2 = 0, box_height = 0, box_height_2 = 0;
	uint16_t object_dy = 0, object_y = 0, object_box_y = 0, other_dy = 0, other_y = 0, other_box_y = 0, difference_y = 0, distance_y = 0, object_dx = 0, object_x = 0, object_box_x = 0, turned_object_x = 0, turned_object_box_x = 0, other_dx = 0, other_x = 0, other_box_x = 0, turned_other_x = 0, turned_other_box_x = 0, difference_x = 0, distance_x = 0, z = 0, object_box_z = 0, z_2 = 0, other_box_z = 0, difference_z = 0, distance_z = 0;

	box_dy = OBJECT(object)->box_dy;
	object_dy = (int8_t)box_dy;
	object_y = OBJECT(object)->y;
	object_box_y = object_dy + object_y;
	box_distance = object_box_y;
	box_dy_2 = OBJECT(other)->box_dy;
	other_dy = (int8_t)box_dy_2;
	other_y = OBJECT(other)->y;
	other_box_y = other_dy + other_y;
	difference_y = other_box_y - box_distance;
	distance_high = (uint8_t)(difference_y >> 8);
	distance_low = (uint8_t)difference_y;
	if ((int16_t)difference_y < 0)
	{
		distance_y = 0u - (((uint32_t)distance_high << 8) | distance_low);
		distance_high = (uint8_t)(distance_y >> 8);
		distance_low = (uint8_t)distance_y;
	}
	box_distance = ((uint32_t)distance_high << 8) | distance_low;
	box_depth = OBJECT(object)->box_depth;
	distance_low = box_depth;
	box_depth_2 = OBJECT(other)->box_depth;
	carry = (uint8_t)(distance_low + box_depth_2) < distance_low;
	distance_low += box_depth_2;
	if ((uint16_t)((carry << 8) | distance_low) < box_distance)
	{
		carry = 0u;
		overlap_word = distance_low;
	}
	else
	{
		box_dx = OBJECT(object)->box_dx;
		object_dx = (int8_t)box_dx;
		box_x_offset = object_dx;
		attributes = OBJECT(object)->attributes;
		if ((attributes & 0x40u) == 0u)
		{
			object_x = OBJECT(object)->x;
			object_box_x = object_x + box_x_offset;
			distance_high = (uint8_t)(object_box_x >> 8);
			distance_low = (uint8_t)object_box_x;
		}
		else
		{
			turned_object_x = OBJECT(object)->x;
			turned_object_box_x = turned_object_x - box_x_offset;
			distance_high = (uint8_t)(turned_object_box_x >> 8);
			distance_low = (uint8_t)turned_object_box_x;
		}
		box_distance = ((uint32_t)distance_high << 8) | distance_low;
		box_dx_2 = OBJECT(other)->box_dx;
		other_dx = (int8_t)box_dx_2;
		box_x_offset = other_dx;
		attributes_2 = OBJECT(other)->attributes;
		if ((attributes_2 & 0x40u) == 0u)
		{
			other_x = OBJECT(other)->x;
			other_box_x = other_x + box_x_offset;
			distance_high = (uint8_t)(other_box_x >> 8);
			distance_low = (uint8_t)other_box_x;
		}
		else
		{
			turned_other_x = OBJECT(other)->x;
			turned_other_box_x = turned_other_x - box_x_offset;
			distance_high = (uint8_t)(turned_other_box_x >> 8);
			distance_low = (uint8_t)turned_other_box_x;
		}
		difference_x = (((uint32_t)distance_high << 8) | distance_low) - box_distance;
		distance_high = (uint8_t)(difference_x >> 8);
		distance_low = (uint8_t)difference_x;
		if ((int16_t)difference_x < 0)
		{
			distance_x = 0u - (((uint32_t)distance_high << 8) | distance_low);
			distance_high = (uint8_t)(distance_x >> 8);
			distance_low = (uint8_t)distance_x;
		}
		box_distance = ((uint32_t)distance_high << 8) | distance_low;
		box_width = OBJECT(object)->box_width;
		distance_low = box_width;
		box_width_2 = OBJECT(other)->box_width;
		carry = (uint8_t)(distance_low + box_width_2) < distance_low;
		distance_low += box_width_2;
		if ((uint16_t)((carry << 8) | distance_low) < box_distance)
		{
			carry = 0u;
			overlap_word = distance_low;
		}
		else
		{
			box_dz = OBJECT(object)->box_dz;
			z = OBJECT(object)->z;
			object_box_z = box_dz + z;
			box_distance = object_box_z;
			box_dz_2 = OBJECT(other)->box_dz;
			z_2 = OBJECT(other)->z;
			other_box_z = box_dz_2 + z_2;
			difference_z = other_box_z - box_distance;
			distance_high = (uint8_t)(difference_z >> 8);
			distance_low = (uint8_t)difference_z;
			if ((int16_t)difference_z < 0)
			{
				distance_z = 0u - (((uint32_t)distance_high << 8) | distance_low);
				distance_high = (uint8_t)(distance_z >> 8);
				distance_low = (uint8_t)distance_z;
			}
			box_distance = ((uint32_t)distance_high << 8) | distance_low;
			box_height = OBJECT(object)->box_height;
			distance_low = box_height;
			box_height_2 = OBJECT(other)->box_height;
			carry = (uint8_t)(distance_low + box_height_2) < distance_low;
			distance_low += box_height_2;
			distance_high = carry;
			if (box_distance <= (uint16_t)(((uint32_t)distance_high << 8) | distance_low))
			{
				carry = 1u;
				overlap_word = ((uint32_t)(uint8_t)~distance_high << 8) | distance_low;
			}
			else
			{
				carry = 0u;
				overlap_word = distance_low;
			}
		}
	}
	*p_overlap_word = overlap_word;
	*p_carry = carry;
}

/* Every pair of the four players in the hit checks: where their boxes overlap, they touch (what bank
   1C's team moves start from). */
void collide_players_with_players(uint16_t *p_object, uint16_t *p_last_flags_word)
{
	uint16_t last_flags_word = (uint16_t)*p_last_flags_word;
	uint32_t carry = 0;
	uint8_t flags = 0;
	uint16_t object = 0, object_2 = 0;
	uint8_t players_left = 0, later_players_left = 0;

	object_2 = OBJECT_ADDRESS(0);
	object = OBJECT_ADDRESS(2);
	if ((OBJECT(OBJECT_ADDRESS(0))->flags & 0x40u) != 0u)
	{
		hit_check_players_left = 2u;
		do
		{
			if ((OBJECT(object)->flags & 0x40u) != 0u)
			{
				boxes_overlap(object_2, object, &last_flags_word, &carry);
				if (carry)
					players_touch(object_2, object);
			}
			object += 0xC0u;
			players_left = hit_check_players_left;
			hit_check_players_left = players_left - 1u;
		} while (players_left != 1u);
	}
	object_2 = OBJECT_ADDRESS(2);
	object = OBJECT_ADDRESS(4);
	if ((OBJECT(OBJECT_ADDRESS(2))->flags & 0x40u) != 0u)
	{
		hit_check_players_left = 2u;
		do
		{
			if ((OBJECT(object)->flags & 0x40u) != 0u)
			{
				boxes_overlap(object_2, object, &last_flags_word, &carry);
				if (carry)
					players_touch(object_2, object);
			}
			object += 0xC0u;
			later_players_left = hit_check_players_left;
			hit_check_players_left = later_players_left - 1u;
		} while (later_players_left != 1u);
	}
	object_2 = OBJECT_ADDRESS(4);
	object = OBJECT_ADDRESS(6);
	if ((OBJECT(OBJECT_ADDRESS(4))->flags & 0x40u) != 0u && (OBJECT(object)->flags & 0x40u) != 0u)
	{
		boxes_overlap(object_2, object, &last_flags_word, &carry);
		if (carry)
			players_touch(object_2, object);
	}
	object_2 = OBJECT_ADDRESS(6);
	object = OBJECT_ADDRESS(0);
	flags = OBJECT(OBJECT_ADDRESS(6))->flags;
	if ((flags & 0x40u) != 0u)
	{
		flags = OBJECT(object)->flags;
		if ((flags & 0x40u) != 0u)
		{
			boxes_overlap(object_2, object, &last_flags_word, &carry);
			flags = (uint8_t)(last_flags_word >> 8);
			if (carry)
			{
				players_touch(object_2, object);
				flags = (uint8_t)(last_flags_word >> 8);
			}
		}
	}
	last_flags_word = (last_flags_word & 0xFFu) | ((uint32_t)flags << 8);
	*p_object = object;
	*p_last_flags_word = last_flags_word;
}

/* The object and the one it overlaps hit each other: each loses the other's power from its life unless
   it takes no damage, keeps the strongest kind of hit and who gave it, and is marked hit. */
void trade_hits_with_enemy(uint16_t object, uint16_t other)
{
	uint8_t attack = 0, vitality = 0;
	uint8_t vitality_2 = 0, damage = 0, old_vitality = 0, hit = 0, attack_2 = 0, attack_3 = 0;

	if ((OBJECT(object)->flags & 4u) != 0u)
	{
		give_hit(object, other);
		return;
	}
	vitality_2 = OBJECT(object)->vitality;
	damage = OBJECT(other)->damage;
	old_vitality = vitality_2;
	vitality = old_vitality - damage;
	if (old_vitality < damage)
		vitality = 0u;
	OBJECT(object)->vitality = vitality;
	hit = OBJECT(object)->hit;
	attack = hit;
	if (hit != 0u)
	{
		attack_2 = OBJECT(other)->attack;
		if ((int8_t)attack <= (int8_t)attack_2)
		{
			attack_3 = OBJECT(other)->attack;
			OBJECT(object)->hit = attack_3;
			OBJECT(object)->hit_by = other;
		}
		OBJECT(object)->flags |= 0x20u;
		give_hit(object, other);
		return;
	}
	attack_3 = OBJECT(other)->attack;
	OBJECT(object)->hit = attack_3;
	OBJECT(object)->hit_by = other;
	OBJECT(object)->flags |= 0x20u;
	give_hit(object, other);
}

/* The object's box hits the other: unless the other takes no damage, it loses the object's power from
   its life, keeps the stronger of its kind of hit and the object's, with the object as the one that hit
   it, and is marked hit. */
void give_hit(uint16_t hitter, uint16_t target)
{
	uint8_t attack = 0, hitter_damage = 0, vitality = 0;
	uint8_t damage = 0, vitality_2 = 0, damage_dealt = 0, old_vitality = 0, hit = 0, attack_2 = 0, attack_3 = 0;

	if ((OBJECT(target)->flags & 4u) != 0u)
		return;
	damage = OBJECT(hitter)->damage;
	hitter_damage = damage;
	if (damage != 0u)
	{
		hit_damage = hitter_damage;
		vitality_2 = OBJECT(target)->vitality;
		damage_dealt = hit_damage;
		old_vitality = vitality_2;
		vitality = old_vitality - damage_dealt;
		if (old_vitality < damage_dealt)
			vitality = 0u;
		OBJECT(target)->vitality = vitality;
	}
	hit = OBJECT(target)->hit;
	attack = hit;
	if (hit != 0u)
	{
		attack_2 = OBJECT(hitter)->attack;
		if ((int8_t)attack <= (int8_t)attack_2)
		{
			attack_3 = OBJECT(hitter)->attack;
			OBJECT(target)->hit = attack_3;
			OBJECT(target)->hit_by = hitter;
		}
		OBJECT(target)->flags |= 0x20u;
		return;
	}
	attack_3 = OBJECT(hitter)->attack;
	OBJECT(target)->hit = attack_3;
	OBJECT(target)->hit_by = hitter;
	OBJECT(target)->flags |= 0x20u;
}

/* A player against an object of list 1 or a child object: while the player is attacking only its hit
   lands, otherwise they trade hits. */
void trade_hits_unless_attacking(uint16_t object, uint16_t other)
{
	if ((OBJECT(object)->flags & 2u) != 0u)
	{
		give_hit(object, other);
		return;
	}
	trade_hits(object, other);
}

/* The object and the one it overlaps hit each other: each loses the other's power from its life unless
   it takes no damage, keeps the strongest kind of hit and who gave it, and is marked hit. */
void trade_hits(uint16_t object, uint16_t other)
{
	uint8_t attack = 0, vitality = 0;
	uint8_t vitality_2 = 0, damage = 0, old_vitality = 0, hit = 0, attack_2 = 0, attack_3 = 0, vitality_3 = 0, damage_2 = 0, other_old_vitality = 0, hit_2 = 0, attack_4 = 0, attack_5 = 0;

	if ((OBJECT(object)->flags & 4u) == 0u)
	{
		vitality_2 = OBJECT(object)->vitality;
		damage = OBJECT(other)->damage;
		old_vitality = vitality_2;
		vitality = old_vitality - damage;
		if (old_vitality < damage)
			vitality = 0u;
		OBJECT(object)->vitality = vitality;
		hit = OBJECT(object)->hit;
		attack = hit;
		if (hit == 0u)
		{
			attack_2 = OBJECT(other)->attack;
			OBJECT(object)->hit = attack_2;
			OBJECT(object)->hit_by = other;
		}
		else
		{
			attack_3 = OBJECT(other)->attack;
			if ((int8_t)attack <= (int8_t)attack_3)
			{
				attack_2 = OBJECT(other)->attack;
				OBJECT(object)->hit = attack_2;
				OBJECT(object)->hit_by = other;
			}
		}
		OBJECT(object)->flags |= 0x20u;
	}
	if ((OBJECT(other)->flags & 4u) != 0u)
		return;
	vitality_3 = OBJECT(other)->vitality;
	damage_2 = OBJECT(object)->damage;
	other_old_vitality = vitality_3;
	vitality = other_old_vitality - damage_2;
	if (other_old_vitality < damage_2)
		vitality = 0u;
	OBJECT(other)->vitality = vitality;
	hit_2 = OBJECT(other)->hit;
	attack = hit_2;
	if (hit_2 != 0u)
	{
		attack_4 = OBJECT(object)->attack;
		if ((int8_t)attack <= (int8_t)attack_4)
		{
			attack_5 = OBJECT(object)->attack;
			OBJECT(other)->hit = attack_5;
			OBJECT(other)->hit_by = object;
		}
		OBJECT(other)->flags |= 0x20u;
		return;
	}
	attack_5 = OBJECT(object)->attack;
	OBJECT(other)->hit = attack_5;
	OBJECT(other)->hit_by = object;
	OBJECT(other)->flags |= 0x20u;
}

/* Two players whose boxes overlap, unless either was hit this frame: each takes the other's kind of hit
   and the other as the one that touched it, with no damage, and both are marked hit (what the team moves
   start from). */
void players_touch(uint16_t object, uint16_t other)
{
	uint8_t attack = 0, attack_2 = 0;

	if ((OBJECT(object)->flags & 0x20u) == 0u && (OBJECT(other)->flags & 0x20u) == 0u)
	{
		attack = OBJECT(other)->attack;
		OBJECT(object)->hit = attack;
		OBJECT(object)->hit_by = other;
		OBJECT(object)->flags |= 0x20u;
		attack_2 = OBJECT(object)->attack;
		OBJECT(other)->hit = attack_2;
		OBJECT(other)->hit_by = object;
		OBJECT(other)->flags |= 0x20u;
	}
}
