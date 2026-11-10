/**
 *    Name:        bonus/results.c
 *    Description: the bonuses' READY and GO signs, the ranking of the results and the portraits row
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    09-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the game's 053248 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

/* The bonuses: shows the READY sign for 160 frames, with its voice (3F32). */
void bonus_show_ready(void)
{
	uint32_t carry = 0;
	uint16_t command = 0, object = 0;

	object = OBJECT_ADDRESS(30);
	if ((OBJECT(OBJECT_ADDRESS(30))->flags & 0x80u) == 0u)
	{
		OBJECT(object)->flags = 0x80u;
		OBJECT(object)->x = 0xE8u;
		OBJECT(object)->y = 0x11Cu;
		OBJECT(object)->type = 0;
		OBJECT(object)->state = 0xA0u;
		OBJECT(object)->kind = 0xEu;
		OBJECT(object)->animation = 0x86u;
		command = 0x3F32u;
		carry = vector_queue_sound(command);
	}
}

/* The bonuses: when READY's time runs out, shows GO with its voice (3F33); carry once it is gone. */
void bonus_show_go(void)
{
	uint32_t carry = 0;
	uint16_t command = 0, d = 0, object = 0;
	uint16_t type = 0, type_2 = 0;
	uint32_t type_halfword = 0;

	object = OBJECT_ADDRESS(30);
	type = (((uint32_t)(uint8_t)OBJECT(OBJECT_ADDRESS(30))->type << 8u) | OBJECT(OBJECT_ADDRESS(30))->state);
	d = type;
	if (type == 0u)
		return;
	if (d == 0xA0u)
	{
		command = 0x3F33u;
		carry = vector_queue_sound(command);
	}
	type_2 = (((uint32_t)(uint8_t)OBJECT(object)->type << 8u) | OBJECT(object)->state);
	type_halfword = type_2 - 1u;
	OBJECT(object)->type = (uint8_t)(type_halfword >> 8u);
	OBJECT(object)->state = (uint8_t)type_halfword;
	if (type_2 != 1u)
	{
		OBJECT(object)->x = 0xE8u;
		OBJECT(object)->y = 0x11Cu;
		OBJECT(object)->kind = 0xEu;
		OBJECT(object)->animation = 0x87u;
		return;
	}
	OBJECT(object)->flags = 0u;
	OBJECT(object)->x = 0u;
	OBJECT(object)->y = 0u;
}

/* The bonuses' results by their state: the places one after the other, then the points counted up; carry
   when done. */
void bonus_results(uint16_t *p_x, uint16_t *p_y, uint16_t *p_d, uint32_t *p_carry)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t d = (uint16_t)*p_d;
	uint32_t carry = *p_carry;
	uint16_t x = 0;
	uint8_t t1 = 0;

	t1 = io_read8(0x1842u);
	x = bonus_results_states_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)t1 << 1))
	{
	case 0:
		bonus_results_start(&x, &y, &d, &carry);
		break;
	case 2:
		bonus_results_first(&x, &y, &d, &carry);
		break;
	case 4:
		bonus_results_second(&x, &y, &d, &carry);
		break;
	case 6:
		bonus_results_third(&x, &y, &d, &carry);
		break;
	case 8:
		bonus_results_fourth(&x, &y, &d, &carry);
		break;
	case 10:
		bonus_results_wait(&x, &y, &d, &carry);
		break;
	case 12:
		bonus_results_wait_count(&x, &y, &d, &carry);
		break;
	case 14:
		bonus_results_count_points(&x, &y, &d, &carry);
		break;
	}
	*p_x = x;
	*p_y = y;
	*p_d = d;
	*p_carry = carry;
}

/* The bonuses' results: prepares the four result boxes, then ranks the winners. */
void bonus_results_start(uint16_t *p_x, uint16_t *p_y, uint16_t *p_d, uint32_t *p_carry)
{
	uint16_t y = (uint16_t)*p_y;
	uint32_t carry = *p_carry;
	uint16_t d = 0, object = 0, parent = 0, x = 0;
	uint8_t t1 = 0, t2 = 0;

	io_write8(0x1842u, 1u);
	io_write8(0x1844u, 0xFFu);
	results_boxes_left = 4u;
	object = OBJECT_ADDRESS(14);
	parent = 0x2310u;
	results_print_place = 0x2310u;
	do
	{
		OBJECT(object)->parameter = 0u;
		OBJECT(object)->blocked = 0u;
		OBJECT(object)->parent = parent;
		parent += 9u;
		OBJECT(object)->enemy_class = -1;
		object += 0xC0u;
		t1 = results_boxes_left;
		results_boxes_left = t1 - 1u;
	} while (t1 != 1u);
	io_write8(0x1846u, 1u);
	t2 = io_read8(0x1845u);
	io_write8(0x1845u, 0u);
	*p_x = x;
	*p_y = y;
	*p_d = d;
	bonus_results_first(p_x, p_y, p_d, &carry);
	*p_carry = carry;
}

/* The bonuses' results: puts the winners (first place sign). */
void bonus_results_first(uint16_t *p_x, uint16_t *p_y, uint16_t *p_d, uint32_t *p_carry)
{
	uint16_t y = (uint16_t)*p_y;
	uint32_t carry = *p_carry;
	uint16_t d = 0, x = 0;

	x = 0xE8Bu;
	bonus_results_place_next(&x, &y, &d);
	*p_x = x;
	*p_y = y;
	*p_d = d;
	bonus_results_animate(p_x, p_y, p_d, &carry);
	*p_carry = carry;
}

/* The bonuses' results: after a wait, puts the players in second place. */
void bonus_results_second(uint16_t *p_x, uint16_t *p_y, uint16_t *p_d, uint32_t *p_carry)
{
	uint16_t x = (uint16_t)*p_x;
	uint16_t y = (uint16_t)*p_y;
	uint16_t d = (uint16_t)*p_d;
	uint32_t carry = *p_carry;
	uint8_t t1 = 0, t2 = 0;

	t1 = io_read8(0x1843u);
	io_write8(0x1843u, t1 - 1u);
	if (t1 != 1u)
		bonus_results_animate(&x, &y, &d, &carry);
	else
	{
		t2 = io_read8(0x1843u);
		io_write8(0x1843u, t2 + 1u);
		x = 0xE8Cu;
		bonus_results_place_next(&x, &y, &d);
		bonus_results_animate(&x, &y, &d, &carry);
	}
	*p_x = x;
	*p_y = y;
	*p_d = d;
	*p_carry = carry;
}

/* The bonuses' results: after a wait, puts the players in third place. */
void bonus_results_third(uint16_t *p_x, uint16_t *p_y, uint16_t *p_d, uint32_t *p_carry)
{
	uint16_t x = (uint16_t)*p_x;
	uint16_t y = (uint16_t)*p_y;
	uint16_t d = (uint16_t)*p_d;
	uint32_t carry = *p_carry;
	uint8_t t1 = 0, t2 = 0;

	t1 = io_read8(0x1843u);
	io_write8(0x1843u, t1 - 1u);
	if (t1 != 1u)
		bonus_results_animate(&x, &y, &d, &carry);
	else
	{
		t2 = io_read8(0x1843u);
		io_write8(0x1843u, t2 + 1u);
		x = 0xE8Du;
		bonus_results_place_next(&x, &y, &d);
		bonus_results_animate(&x, &y, &d, &carry);
	}
	*p_x = x;
	*p_y = y;
	*p_d = d;
	*p_carry = carry;
}

/* The bonuses' results: after a wait, puts the players in fourth place. */
void bonus_results_fourth(uint16_t *p_x, uint16_t *p_y, uint16_t *p_d, uint32_t *p_carry)
{
	uint16_t x = (uint16_t)*p_x;
	uint16_t y = (uint16_t)*p_y;
	uint16_t d = (uint16_t)*p_d;
	uint32_t carry = *p_carry;
	uint8_t t1 = 0, t2 = 0;

	t1 = io_read8(0x1843u);
	io_write8(0x1843u, t1 - 1u);
	if (t1 != 1u)
		bonus_results_animate(&x, &y, &d, &carry);
	else
	{
		t2 = io_read8(0x1843u);
		io_write8(0x1843u, t2 + 1u);
		x = 0xE8Eu;
		bonus_results_place_next(&x, &y, &d);
		bonus_results_animate(&x, &y, &d, &carry);
	}
	*p_x = x;
	*p_y = y;
	*p_d = d;
	*p_carry = carry;
}

/* The bonuses' results: waits before counting the points. */
void bonus_results_wait(uint16_t *p_x, uint16_t *p_y, uint16_t *p_d, uint32_t *p_carry)
{
	uint16_t x = (uint16_t)*p_x;
	uint16_t y = (uint16_t)*p_y;
	uint16_t d = (uint16_t)*p_d;
	uint32_t carry = *p_carry;
	uint8_t t1 = 0;

	t1 = io_read8(0x1843u);
	io_write8(0x1843u, t1 - 1u);
	if (t1 != 1u)
		bonus_results_animate(&x, &y, &d, &carry);
	else
	{
		d = 0x63Cu;
		io_write16(0x1842u, 0x63Cu);
		bonus_results_animate(&x, &y, &d, &carry);
	}
	*p_x = x;
	*p_y = y;
	*p_d = d;
	*p_carry = carry;
}

/* The bonuses' results: a last short wait before the points. */
void bonus_results_wait_count(uint16_t *p_x, uint16_t *p_y, uint16_t *p_d, uint32_t *p_carry)
{
	uint16_t x = (uint16_t)*p_x;
	uint16_t y = (uint16_t)*p_y;
	uint16_t d = (uint16_t)*p_d;
	uint32_t carry = *p_carry;
	uint8_t t1 = 0;

	t1 = io_read8(0x1843u);
	io_write8(0x1843u, t1 - 1u);
	if (t1 != 1u)
		bonus_results_animate(&x, &y, &d, &carry);
	else
	{
		d = 0x704u;
		io_write16(0x1842u, 0x704u);
		bonus_results_animate(&x, &y, &d, &carry);
	}
	*p_x = x;
	*p_y = y;
	*p_d = d;
	*p_carry = carry;
}

/* The bonuses' results: types each box's text, makes the newly placed ones hop and reads the places. */
void bonus_results_animate(uint16_t *p_x, uint16_t *p_y, uint16_t *p_d, uint32_t *p_carry)
{
	uint16_t x = (uint16_t)*p_x;
	uint16_t y = (uint16_t)*p_y;
	uint16_t d = (uint16_t)*p_d;
	uint32_t carry = *p_carry;
	uint8_t hop = 0, z_speed = 0;
	uint16_t box = 0;
	uint8_t blocked = 0, blocked_2 = 0, hop_2 = 0, hop_3 = 0, t1 = 0;

	results_typed_boxes_left = 4u;
	box = OBJECT_ADDRESS(14);
	do
	{
		blocked = OBJECT(box)->blocked;
		if (blocked != 0u)
		{
			blocked_2 = OBJECT(box)->blocked;
			OBJECT(box)->blocked = blocked_2 - 1u;
			if (blocked_2 == 1u)
				OBJECT(box)->bonus_results.text_wait = 4u;
		}
		results_number = 0u;
		bonus_results_type_text(box, &y, &d);
		hop_2 = OBJECT(box)->bonus_results.hop;
		hop = hop_2;
		if (hop_2 != 0u)
		{
			hop_3 = OBJECT(box)->bonus_results.hop;
			OBJECT(box)->bonus_results.hop = hop_3 - 1u;
			x = bonus_results_hop_speeds_ADDRESS;
			z_speed = bonus_results_hop_speeds[(int8_t)hop];
			OBJECT(box)->z_speed = (OBJECT(box)->z_speed & 0xFFu) | ((z_speed & 0xFFu) << 8u);
			OBJECT(box + 0x60u)->z_speed = (OBJECT(box + 0x60u)->z_speed & 0xFFu) | ((z_speed & 0xFFu) << 8u);
		}
		box += 0xC0u;
		t1 = results_typed_boxes_left;
		results_typed_boxes_left = t1 - 1u;
	} while (t1 != 1u);
	bonus_results_read_places();
	carry = 0u;
	d &= 0xFFu;
	*p_x = x;
	*p_y = y;
	*p_d = d;
	*p_carry = carry;
}

/* The bonuses' results: counts each player's points up on its box with a tick sound, a sound when it is
   done; carry when all are. */
void bonus_results_count_points(uint16_t *p_x, uint16_t *p_place, uint16_t *p_d, uint32_t *p_carry)
{
	uint16_t x = (uint16_t)*p_x;
	uint16_t place = (uint16_t)*p_place;
	uint8_t d = (uint8_t)*p_d;
	uint32_t carry = *p_carry;
	uint8_t players_done = 0, points_shown = 0;
	uint16_t box = 0, command = 0, d_2 = 0, number = 0;
	uint8_t t1 = 0, points_shown_2 = 0, target_dy = 0, target_dy_2 = 0, look = 0, t2 = 0;

	players_done = (uint8_t)d;
	t1 = io_read8(0x1843u);
	io_write8(0x1843u, t1 - 1u);
	if (t1 != 1u)
	{
		carry = 0u;
		d_2 = players_done;
	}
	else
	{
		io_write8(0x1843u, 4u);
		results_boxes_left = 4u;
		box = OBJECT_ADDRESS(14);
		results_print_place = 0x2411u;
		results_counts_done = 0u;
		do
		{
			points_shown_2 = OBJECT(box)->bonus_results.points_shown;
			points_shown = points_shown_2 + 1u;
			if (points_shown == (uint8_t)OBJECT(box - 0x540u)->type)
			{
				results_counts_done++;
				target_dy = (uint8_t)(OBJECT(box)->target_dy >> 8u);
				if (target_dy == 0u)
				{
					command = 0xA01u;
					carry = vector_queue_sound(command);
					target_dy_2 = (uint8_t)(OBJECT(box)->target_dy >> 8u);
					OBJECT(box)->target_dy = (OBJECT(box)->target_dy & 0xFFu) | ((target_dy_2 + 1u & 0xFFu) << 8u);
				}
			}
			else
			{
				OBJECT(box)->bonus_results.points_shown = points_shown;
				number = (uint32_t)points_shown << 8;
				bonus_results_print_number(&place, &number);
				look = OBJECT(box)->bonus_results.look;
			}
			x = results_print_place + 9u;
			results_print_place = x;
			box += 0xC0u;
			t2 = results_boxes_left;
			results_boxes_left = t2 - 1u;
		} while (t2 != 1u);
		command = 0x801u;
		carry = vector_queue_sound(command);
		players_done = results_counts_done;
		bonus_results_read_places();
		if (players_done == 4u)
		{
			io_write16(0x1842u, 0u);
			carry = 1u;
			d_2 = 0xFF00u;
		}
		else
		{
			carry = 0u;
			d_2 = players_done;
		}
	}
	*p_x = x;
	*p_place = place;
	*p_d = d_2;
	*p_carry = carry;
}

/* The bonuses' results: keeps the four players' places (for bonus 1's flight waits). */
void bonus_results_read_places(void)
{
	results_marge_place = OBJECT(OBJECT_ADDRESS(14))->unk_45;
	results_homer_place = OBJECT(OBJECT_ADDRESS(16))->unk_45;
	results_bart_place = OBJECT(OBJECT_ADDRESS(18))->unk_45;
	results_lisa_place = OBJECT(OBJECT_ADDRESS(20))->unk_45;
}

/* The bonuses' results: finds the best result not placed yet and puts every player who has it in that
   place: its sign hops in and its box and text appear. */
void bonus_results_place_next(uint16_t *p_sign_kind, uint16_t *p_box_text, uint16_t *p_d)
{
	uint16_t sign_kind = (uint16_t)*p_sign_kind;
	uint16_t box_text = (uint16_t)*p_box_text;
	uint8_t look = 0, look_2 = 0, place = 0, placed = 0, players_left = 0, result = 0;
	uint16_t box = 0, d = 0, kind = 0, object = 0;
	uint8_t type = 0, t1 = 0, t2 = 0, look_3 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, t8 = 0;
	uint32_t kind_halfword = 0;

	placed_sign = sign_kind;
	placed_count = 0u;
	placed_result = 0u;
	players_left = 4u;
	object = OBJECT_ADDRESS(0);
	do
	{
		type = OBJECT(object)->type;
		result = type;
		t1 = io_read8(0x1844u);
		if (result < t1 && placed_result <= result)
		{
			placed_count++;
			placed_result = result;
		}
		object += 0xC0u;
		t2 = players_left;
		players_left = t2 - 1u;
	} while (t2 != 1u);
	if (placed_count != 0u)
	{
		io_write8(0x1844u, placed_result);
		placed_count = 0u;
		placed_result = 4u;
		box = OBJECT_ADDRESS(14);
		sign_kind = 0x78u;
		do
		{
			look_3 = OBJECT(box)->bonus_results.look;
			look = look_3;
			placed_count++;
			t3 = io_read8(0x1844u);
			if ((uint8_t)OBJECT(box - 0x540u)->type == t3)
			{
				OBJECT(box)->flags = 0x80u;
				OBJECT(box + 0x60u)->flags = 0x80u;
				OBJECT(box)->x = sign_kind;
				OBJECT(box + 0x60u)->x = sign_kind;
				OBJECT(box)->y = 0x60u;
				OBJECT(box + 0x60u)->y = 0x60u;
				OBJECT(box)->z = 0xD0u;
				OBJECT(box + 0x60u)->z = 0xD0u;
				kind = placed_sign;
				OBJECT(box)->kind = (uint8_t)(kind >> 8u);
				OBJECT(box)->animation = (uint8_t)kind;
				kind_halfword = kind + 5u;
				OBJECT(box + 0x60u)->kind = (uint8_t)(kind_halfword >> 8u);
				OBJECT(box + 0x60u)->animation = (uint8_t)kind_halfword;
				OBJECT(box)->bonus_results.hop = 0x1Fu;
				OBJECT(box)->blocked = 0xAu;
				t4 = io_read8(0x1846u);
				place = t4;
				if (look == 3u)
				{
					box_text = bonus_result_player_text_ADDRESS;
					if ((uint8_t)OBJECT(box - 0x540u)->type == 0u)
					{
						box_text = bonus_result_absent_text_ADDRESS;
						OBJECT(box)->bonus_results.no_points = 1u;
						place = 4u;
					}
				}
				else
					box_text = bonus_result_text_ADDRESS;
				OBJECT(box)->bonus_results.text = box_text;
				OBJECT(box)->bonus_results.place = place;
				look_2 = look;
				sign_kind = bonus_results_draw_box(sign_kind, box, look_2);
				OBJECT(box - 0x540u)->type++;
				t5 = io_read8(0x1845u);
				io_write8(0x1845u, t5 + 1u);
			}
			box += 0xC0u;
			sign_kind += 0x48u;
			t6 = placed_result;
			placed_result = t6 - 1u;
		} while (t6 != 1u);
		t7 = io_read8(0x1845u);
		placed = t7;
		if (placed == placed_count)
			placed = 5u;
		else
			placed++;
		io_write16(0x1842u, ((uint32_t)placed << 8) | 0xEu);
		t8 = io_read8(0x1846u);
		io_write8(0x1846u, t8 + 1u);
		d = ((uint32_t)placed << 8) | 0xEu;
	}
	else
		d = ((uint32_t)players_left << 8) | result;
	*p_sign_kind = sign_kind;
	*p_box_text = box_text;
	*p_d = d;
}

/* The bonuses: keeps the row of the players' portraits (an absent player's sign instead) at the given
   place. */
uint16_t bonus_show_player_portraits(uint16_t kind)
{
	uint8_t look = 0, old_look = 0, player_bits = 0;
	uint16_t object = 0;
	uint8_t stack = 0, stack_10002 = 0, saved_portrait_animation = 0;
	uint8_t t1 = 0, t2 = 0, kind_2 = 0, state = 0, t3 = 0;
	uint16_t t4 = 0, t5 = 0, t6 = 0;

	bonus_portrait_player = 0u;
	object = OBJECT_ADDRESS(14);
	player_bits = players_playing;
	do
	{
		stack = player_bits;
		t1 = (uint8_t)OBJECT(object)->target_dy;
		old_look = t1;
		if (t1 != 0u)
		{
			t2 = old_look;
			old_look = t2 - 1u;
			if (t2 != 1u)
			{
				if (old_look != 1u)
				{
					kind_2 = OBJECT(object)->kind;
					if (kind_2 != 0xEu)
					{
						state = OBJECT(object)->state;
						OBJECT(object)->state = state - 1u;
						if (state == 1u)
							OBJECT(object)->flags = 0u;
					}
				}
				else
				{
					t3 = io_read8(0x1842u);
					if (t3 == 0u && (player_bits & 1u) != 0u)
					{
						kind = 0xEC2u;
						look = 1u;
						OBJECT(object)->target_dy = (OBJECT(object)->target_dy & 0xFF00u) | (look & 0xFFu);
						OBJECT(object)->kind = (uint8_t)(kind >> 8u);
						OBJECT(object)->animation = (uint8_t)kind;
						OBJECT(object)->flags = 0x80u;
						t4 = bonus_portrait_player * 0x48u;
						t5 = t4 + bonus_draw_x;
						OBJECT(object)->x = t5;
						t6 = bonus_draw_y;
						OBJECT(object)->y = t6;
						OBJECT(object)->z = 0u;
					}
				}
			}
		}
		else if ((player_bits & 1u) != 0u)
		{
			OBJECT(object)->state = 0xFFu;
			stack_10002 = bonus_portrait_player + 0xAu;
			saved_portrait_animation = portrait_animation;
			kind = ((uint32_t)stack_10002 << 8) | saved_portrait_animation;
			look = 3u;
			OBJECT(object)->target_dy = (OBJECT(object)->target_dy & 0xFF00u) | (look & 0xFFu);
			OBJECT(object)->kind = (uint8_t)(kind >> 8u);
			OBJECT(object)->animation = (uint8_t)kind;
			OBJECT(object)->flags = 0x80u;
			t4 = bonus_portrait_player * 0x48u;
			t5 = t4 + bonus_draw_x;
			OBJECT(object)->x = t5;
			t6 = bonus_draw_y;
			OBJECT(object)->y = t6;
			OBJECT(object)->z = 0u;
		}
		else
		{
			kind = 0xEAEu;
			look = 2u;
			OBJECT(object)->target_dy = (OBJECT(object)->target_dy & 0xFF00u) | (look & 0xFFu);
			OBJECT(object)->kind = (uint8_t)(kind >> 8u);
			OBJECT(object)->animation = (uint8_t)kind;
			OBJECT(object)->flags = 0x80u;
			t4 = bonus_portrait_player * 0x48u;
			t5 = t4 + bonus_draw_x;
			OBJECT(object)->x = t5;
			t6 = bonus_draw_y;
			OBJECT(object)->y = t6;
			OBJECT(object)->z = 0u;
		}
		player_bits = stack >> 1;
		object += 0xC0u;
		bonus_portrait_player++;
	} while (bonus_portrait_player != 4u);
	return kind;
}

/* The bonuses' results: types a box's text one letter every 4 frames into the tile RAM ('$' moves, '%'
   prints the points). */
void bonus_results_type_text(uint16_t box, uint16_t *p_y, uint16_t *p_move)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t move = (uint16_t)*p_move;
	uint8_t character = 0, points = 0, text_wait = 0;
	uint8_t text_wait_2 = 0, text_wait_3 = 0, t2 = 0;
	uint16_t text = 0, t1 = 0, t3 = 0, t4 = 0, text_cursor = 0, text_cursor_2 = 0, text_cursor_3 = 0, t5 = 0;

	text_wait = (uint8_t)(move >> 8);
	text_wait_2 = OBJECT(box)->bonus_results.text_wait;
	if ((int8_t)text_wait_2 >= 0)
	{
		text_wait_3 = OBJECT(box)->bonus_results.text_wait;
		OBJECT(box)->bonus_results.text_wait = text_wait_3 - 1u;
		if (text_wait_3 == 1u)
		{
			for (;;)
			{
				text = OBJECT(box)->bonus_results.text;
				t1 = text;
				y = t1 + 1u;
				t2 = mem_read8(t1);
				character = t2;
				if (t2 == 0u)
				{
					text_wait = 0xFFu;
					break;
				}
				if (character == 0x24u)
				{
					t3 = y;
					t4 = mem_read16(t3);
					move = t4;
					OBJECT(box)->bonus_results.text = t3 + 2u;
					text_cursor = OBJECT(box)->bonus_results.text_cursor;
					OBJECT(box)->bonus_results.text_cursor = text_cursor + (((uint32_t)(t4 >> 8) << 8) | (move & 0xFFu));
					continue;
				}
				OBJECT(box)->bonus_results.text = y;
				if (character == 0x25u)
				{
					points = results_number;
					text_cursor_2 = OBJECT(box)->bonus_results.text_cursor;
					results_print_place = text_cursor_2;
					move = (move & 0xFFu) | ((uint32_t)points << 8);
					bonus_results_print_number(&y, &move);
				}
				else
				{
					text_cursor_3 = OBJECT(box)->bonus_results.text_cursor;
					t5 = text_cursor_3;
					y = t5 + 1u;
					OBJECT(t5)->flags = character - 0x30u;
					OBJECT(box)->bonus_results.text_cursor = y;
				}
				text_wait = 4u;
				break;
			}
			OBJECT(box)->bonus_results.text_wait = text_wait;
		}
	}
	move = (move & 0xFFu) | ((uint32_t)text_wait << 8);
	*p_y = y;
	*p_move = move;
}

/* The bonuses' results: writes the given number as up to three digits. */
void bonus_results_print_number(uint16_t *p_place, uint16_t *p_number)
{
	uint16_t number = (uint16_t)*p_number;
	uint8_t b = 0, hundreds = 0, number_left = 0, tens = 0;
	uint16_t place = 0;
	uint16_t t1 = 0, t2 = 0;

	number_left = (uint8_t)(number >> 8);
	b = (uint8_t)number;
	place = results_print_place + 1u;
	if (number_left < 0xAu)
	{
		io_write8(place, number_left);
		number = ((uint32_t)number_left << 8) | b;
	}
	else
	{
		if (number_left >= 0x64u)
		{
			number_left -= 0x64u;
			hundreds = 1u;
			if (number_left >= 0x64u)
			{
				number_left -= 0x64u;
				hundreds++;
			}
			t1 = place;
			place = t1 + 1u;
			io_write8(t1, hundreds);
		}
		tens = 0u;
		while (number_left >= 0xAu)
		{
			number_left -= 0xAu;
			tens++;
		}
		t2 = place;
		place = t2 + 1u;
		mem_write8(t2, tens);
		mem_write8(place, number_left);
		number = ((uint32_t)number_left << 8) | tens;
	}
	*p_place = place;
	*p_number = number;
}

/* The bonuses: the number of the first player in the game. */
void bonus_first_player_in_game(uint16_t *p_first_player, uint32_t *p_negative)
{
	uint32_t negative = *p_negative;
	uint8_t player_bits = 0;
	uint16_t first_player = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0;

	player_bits = players_playing;
	first_player_slots_left = 4u;
	do
	{
		t1 = player_bits;
		player_bits = t1 >> 1;
		if (t1 & 1u)
			break;
		t2 = first_player_slots_left;
		first_player_slots_left = t2 - 1u;
	} while (t2 != 1u);
	t3 = 4u - first_player_slots_left;
	negative = t3 >> 7;
	first_player = ((uint32_t)t3 << 8) | player_bits;
	*p_first_player = first_player;
	*p_negative = negative;
}

/* The bonuses' results: draws a player's box of tiles under its sign (taller for a player in the game). */
uint16_t bonus_results_draw_box(uint16_t box_x, uint16_t box, uint8_t look)
{
	uint8_t colour = 0, rows = 0, rows_left = 0;
	uint16_t box_tiles = 0, count = 0, tiles = 0;
	uint8_t stack_9 = 0, stack_1000A = 0, stack_1000B = 0;
	uint16_t stack = 0, stack_B = 0;
	uint8_t t5 = 0, t6 = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0, t4 = 0;

	stack = box_x;
	colour = 0xB2u;
	if (look != 3u)
		colour = 0xF2u;
	stack_9 = colour;
	stack_B = box_x;
	t1 = io_read16(0xA0u);
	t2 = stack_B - t1;
	t3 = t2 >> 3;
	t4 = t3 + 0x22C0u;
	stack_1000A = t4 >> 8;
	stack_1000B = t4;
	tiles = ((uint32_t)stack_1000A << 8) | stack_1000B;
	colour = stack_9;
	rows = 7u;
	if ((uint8_t)OBJECT(box - 0x540u)->type == 0u)
		rows = 4u;
	stack_9 = rows;
	rows_left = stack_9;
	box_tiles = bonus_result_box_tiles_ADDRESS;
	stack_B = tiles;
	do
	{
		count = 8u;
		while (count != 0u)
		{
			mem_write8(tiles, mem_read8(box_tiles));
			box_tiles++;
			tiles++;
			count--;
		}
		tiles += 0x38u;
		t5 = rows_left;
		rows_left = t5 - 1u;
	} while (t5 != 1u);
	tiles = stack_B - 0x2000u;
	rows_left = stack_9;
	do
	{
		count = 8u;
		while (count != 0u)
		{
			mem_write8(tiles, colour);
			tiles++;
			count--;
		}
		tiles += 0x38u;
		t6 = rows_left;
		rows_left = t6 - 1u;
	} while (t6 != 1u);
	box_x = stack;
	return box_x;
}
