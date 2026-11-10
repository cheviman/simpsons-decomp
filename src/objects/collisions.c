/**
 *    Name:        objects/collisions.c
 *    Description: the hit checks: the players against the enemies, the child objects, list 1's objects and each other
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    09-11-2026
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
	uint16_t d = 0, object = 0;
	uint8_t t1 = 0;

	object = OBJECT_ADDRESS(0);
	count = 0x20u;
	do
	{
		flags = OBJECT(object)->flags & 0xDFu;
		OBJECT(object)->flags = flags;
		OBJECT(object)->hit = 0u;
		object += 0x60u;
		t1 = count;
		count = t1 - 1u;
	} while (t1 != 1u);
	d = ((uint32_t)count << 8) | flags;
	return d;
}

/* Every player and partner in the hit checks against every enemy in them: where their boxes overlap,
   they trade hits. */
uint16_t collide_players_with_enemies(uint16_t d)
{
	uint32_t carry = 0;
	uint8_t flags = 0;
	uint16_t d_2 = 0, object = 0, object_2 = 0;
	uint8_t t1 = 0, t2 = 0;

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
				t1 = hit_check_enemies_left;
				hit_check_enemies_left = t1 - 1u;
			} while (t1 != 1u);
		}
		object += 0x60u;
		t2 = hit_check_players_left;
		hit_check_players_left = t2 - 1u;
	} while (t2 != 1u);
	d_2 = (d & 0xFFu) | ((uint32_t)flags << 8);
	return d_2;
}

/* Every player in the hit checks against every child object in them: where their boxes overlap, they
   trade hits unless the player is attacking. */
uint16_t collide_players_with_child_objects(uint16_t d)
{
	uint32_t carry = 0;
	uint8_t flags = 0;
	uint16_t d_2 = 0, object = 0, object_2 = 0;
	uint8_t t1 = 0, t2 = 0;

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
				t1 = hit_check_children_left;
				hit_check_children_left = t1 - 1u;
			} while (t1 != 1u);
		}
		object += 0xC0u;
		t2 = hit_check_players_left;
		hit_check_players_left = t2 - 1u;
	} while (t2 != 1u);
	d_2 = (d & 0xFFu) | ((uint32_t)flags << 8);
	return d_2;
}

/* Every player and partner in the hit checks against every object of list 1 in them: where their boxes
   overlap, they trade hits unless the player is attacking. */
uint16_t collide_players_with_list_1_objects(uint16_t d)
{
	uint32_t carry = 0;
	uint8_t flags = 0;
	uint16_t d_2 = 0, object = 0, object_2 = 0;
	uint8_t t1 = 0, t2 = 0;

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
				t1 = hit_check_list_1_left;
				hit_check_list_1_left = t1 - 1u;
			} while (t1 != 1u);
		}
		object += 0x60u;
		t2 = hit_check_players_left;
		hit_check_players_left = t2 - 1u;
	} while (t2 != 1u);
	d_2 = (d & 0xFFu) | ((uint32_t)flags << 8);
	return d_2;
}

/* Unused: checks the object's box against list 1's objects, trading hits with each it touches. */
void unused_collide_with_list_1_objects(uint16_t x)
{
	uint32_t carry = 0;
	uint16_t ignored16 = 0, object = 0;
	uint8_t t1 = 0;

	mem_write8(x, mem_read8(x) & 0xDFu);
	mem_write8(x + 0x1Eu, 0u);
	object = OBJECT_ADDRESS(22);
	hit_check_list_1_left = 0xAu;
	do
	{
		if ((OBJECT(object)->flags & 0x40u) != 0u)
		{
			boxes_overlap(x, object, &ignored16, &carry);
			if (carry)
				trade_hits_unless_attacking(x, object);
		}
		object += 0x60u;
		t1 = hit_check_list_1_left;
		hit_check_list_1_left = t1 - 1u;
	} while (t1 != 1u);
}

/* Whether two objects' hit boxes overlap (carry set): in depth, in x (the box's x offset mirrored by the
   facing) and in height, each the distance between the boxes' centres against their two half sizes. */
void boxes_overlap(uint16_t object, uint16_t other, uint16_t *p_d, uint32_t *p_carry)
{
	uint32_t carry = *p_carry;
	uint8_t a = 0, b = 0;
	uint16_t d = 0;
	uint8_t box_dy = 0, box_dy_2 = 0, box_depth = 0, box_depth_2 = 0, box_dx = 0, attributes = 0, box_dx_2 = 0, attributes_2 = 0, box_width = 0, box_width_2 = 0, box_dz = 0, box_dz_2 = 0, box_height = 0, box_height_2 = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, t8 = 0, t9 = 0, t10 = 0, t11 = 0, t12 = 0, t13 = 0, t14 = 0, t15 = 0, t16 = 0, t17 = 0, t18 = 0, t19 = 0, t20 = 0, z = 0, t21 = 0, z_2 = 0, t22 = 0, t23 = 0, t24 = 0;

	box_dy = OBJECT(object)->box_dy;
	t1 = (int8_t)box_dy;
	t2 = OBJECT(object)->y;
	t3 = t1 + t2;
	box_distance = t3;
	box_dy_2 = OBJECT(other)->box_dy;
	t4 = (int8_t)box_dy_2;
	t5 = OBJECT(other)->y;
	t6 = t4 + t5;
	t7 = t6 - box_distance;
	a = (uint8_t)(t7 >> 8);
	b = (uint8_t)t7;
	if ((int16_t)t7 < 0)
	{
		t8 = 0u - (((uint32_t)a << 8) | b);
		a = (uint8_t)(t8 >> 8);
		b = (uint8_t)t8;
	}
	box_distance = ((uint32_t)a << 8) | b;
	box_depth = OBJECT(object)->box_depth;
	b = box_depth;
	box_depth_2 = OBJECT(other)->box_depth;
	carry = (uint8_t)(b + box_depth_2) < b;
	b += box_depth_2;
	if ((uint16_t)((carry << 8) | b) < box_distance)
	{
		carry = 0u;
		d = b;
	}
	else
	{
		box_dx = OBJECT(object)->box_dx;
		t9 = (int8_t)box_dx;
		box_x_offset = t9;
		attributes = OBJECT(object)->attributes;
		if ((attributes & 0x40u) == 0u)
		{
			t10 = OBJECT(object)->x;
			t11 = t10 + box_x_offset;
			a = (uint8_t)(t11 >> 8);
			b = (uint8_t)t11;
		}
		else
		{
			t12 = OBJECT(object)->x;
			t13 = t12 - box_x_offset;
			a = (uint8_t)(t13 >> 8);
			b = (uint8_t)t13;
		}
		box_distance = ((uint32_t)a << 8) | b;
		box_dx_2 = OBJECT(other)->box_dx;
		t14 = (int8_t)box_dx_2;
		box_x_offset = t14;
		attributes_2 = OBJECT(other)->attributes;
		if ((attributes_2 & 0x40u) == 0u)
		{
			t15 = OBJECT(other)->x;
			t16 = t15 + box_x_offset;
			a = (uint8_t)(t16 >> 8);
			b = (uint8_t)t16;
		}
		else
		{
			t17 = OBJECT(other)->x;
			t18 = t17 - box_x_offset;
			a = (uint8_t)(t18 >> 8);
			b = (uint8_t)t18;
		}
		t19 = (((uint32_t)a << 8) | b) - box_distance;
		a = (uint8_t)(t19 >> 8);
		b = (uint8_t)t19;
		if ((int16_t)t19 < 0)
		{
			t20 = 0u - (((uint32_t)a << 8) | b);
			a = (uint8_t)(t20 >> 8);
			b = (uint8_t)t20;
		}
		box_distance = ((uint32_t)a << 8) | b;
		box_width = OBJECT(object)->box_width;
		b = box_width;
		box_width_2 = OBJECT(other)->box_width;
		carry = (uint8_t)(b + box_width_2) < b;
		b += box_width_2;
		if ((uint16_t)((carry << 8) | b) < box_distance)
		{
			carry = 0u;
			d = b;
		}
		else
		{
			box_dz = OBJECT(object)->box_dz;
			z = OBJECT(object)->z;
			t21 = box_dz + z;
			box_distance = t21;
			box_dz_2 = OBJECT(other)->box_dz;
			z_2 = OBJECT(other)->z;
			t22 = box_dz_2 + z_2;
			t23 = t22 - box_distance;
			a = (uint8_t)(t23 >> 8);
			b = (uint8_t)t23;
			if ((int16_t)t23 < 0)
			{
				t24 = 0u - (((uint32_t)a << 8) | b);
				a = (uint8_t)(t24 >> 8);
				b = (uint8_t)t24;
			}
			box_distance = ((uint32_t)a << 8) | b;
			box_height = OBJECT(object)->box_height;
			b = box_height;
			box_height_2 = OBJECT(other)->box_height;
			carry = (uint8_t)(b + box_height_2) < b;
			b += box_height_2;
			a = carry;
			if (box_distance <= (uint16_t)(((uint32_t)a << 8) | b))
			{
				carry = 1u;
				d = ((uint32_t)(uint8_t)~a << 8) | b;
			}
			else
			{
				carry = 0u;
				d = b;
			}
		}
	}
	*p_d = d;
	*p_carry = carry;
}

/* Every pair of the four players in the hit checks: where their boxes overlap, they touch (what bank
   1C's team moves start from). */
void collide_players_with_players(uint16_t *p_object, uint16_t *p_d)
{
	uint16_t d = (uint16_t)*p_d;
	uint32_t carry = 0;
	uint8_t flags = 0;
	uint16_t d_2 = 0, object = 0, object_2 = 0;
	uint8_t t1 = 0, t2 = 0;

	object_2 = OBJECT_ADDRESS(0);
	object = OBJECT_ADDRESS(2);
	if ((OBJECT(OBJECT_ADDRESS(0))->flags & 0x40u) != 0u)
	{
		hit_check_players_left = 2u;
		do
		{
			if ((OBJECT(object)->flags & 0x40u) != 0u)
			{
				boxes_overlap(object_2, object, &d, &carry);
				if (carry)
					players_touch(object_2, object);
			}
			object += 0xC0u;
			t1 = hit_check_players_left;
			hit_check_players_left = t1 - 1u;
		} while (t1 != 1u);
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
				boxes_overlap(object_2, object, &d, &carry);
				if (carry)
					players_touch(object_2, object);
			}
			object += 0xC0u;
			t2 = hit_check_players_left;
			hit_check_players_left = t2 - 1u;
		} while (t2 != 1u);
	}
	object_2 = OBJECT_ADDRESS(4);
	object = OBJECT_ADDRESS(6);
	if ((OBJECT(OBJECT_ADDRESS(4))->flags & 0x40u) != 0u && (OBJECT(object)->flags & 0x40u) != 0u)
	{
		boxes_overlap(object_2, object, &d, &carry);
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
			boxes_overlap(object_2, object, &d, &carry);
			flags = (uint8_t)(d >> 8);
			if (carry)
			{
				players_touch(object_2, object);
				flags = (uint8_t)(d >> 8);
			}
		}
	}
	d_2 = (d & 0xFFu) | ((uint32_t)flags << 8);
	*p_object = object;
	*p_d = d_2;
}

/* The object and the one it overlaps hit each other: each loses the other's power from its life unless
   it takes no damage, keeps the strongest kind of hit and who gave it, and is marked hit. */
void trade_hits_with_enemy(uint16_t object, uint16_t other)
{
	uint8_t attack = 0, vitality = 0;
	uint8_t vitality_2 = 0, damage = 0, t1 = 0, hit = 0, attack_2 = 0, attack_3 = 0;

	if ((OBJECT(object)->flags & 4u) != 0u)
	{
		give_hit(object, other);
		return;
	}
	vitality_2 = OBJECT(object)->vitality;
	damage = OBJECT(other)->damage;
	t1 = vitality_2;
	vitality = t1 - damage;
	if (t1 < damage)
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
	uint8_t a = 0, attack = 0, vitality = 0;
	uint8_t damage = 0, vitality_2 = 0, t1 = 0, t2 = 0, hit = 0, attack_2 = 0, attack_3 = 0;

	if ((OBJECT(target)->flags & 4u) != 0u)
		return;
	damage = OBJECT(hitter)->damage;
	a = damage;
	if (damage != 0u)
	{
		hit_damage = a;
		vitality_2 = OBJECT(target)->vitality;
		t1 = hit_damage;
		t2 = vitality_2;
		vitality = t2 - t1;
		if (t2 < t1)
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
	uint8_t vitality_2 = 0, damage = 0, t1 = 0, hit = 0, attack_2 = 0, attack_3 = 0, vitality_3 = 0, damage_2 = 0, t2 = 0, hit_2 = 0, attack_4 = 0, attack_5 = 0;

	if ((OBJECT(object)->flags & 4u) == 0u)
	{
		vitality_2 = OBJECT(object)->vitality;
		damage = OBJECT(other)->damage;
		t1 = vitality_2;
		vitality = t1 - damage;
		if (t1 < damage)
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
	t2 = vitality_3;
	vitality = t2 - damage_2;
	if (t2 < damage_2)
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
