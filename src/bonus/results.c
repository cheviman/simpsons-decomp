/**
 *    Name:        bonus/results.c
 *    Description: the bonuses' READY and GO signs, the ranking of the results and the portraits row
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    11-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the game's 053248 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

/* The bonuses: shows the READY sign for 160 frames, with its voice (3F32). */
void bonus_show_ready(void)
{
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
		vector_queue_sound(command);
	}
}

/* The bonuses: when READY's time runs out, shows GO with its voice (3F33); carry once it is gone. */
void bonus_show_go(void)
{
	uint16_t command = 0, go_frames = 0, object = 0;
	uint16_t type = 0, type_2 = 0;
	uint32_t type_halfword = 0;

	object = OBJECT_ADDRESS(30);
	type = (((uint32_t)(uint8_t)OBJECT(OBJECT_ADDRESS(30))->type << 8u) | OBJECT(OBJECT_ADDRESS(30))->state);
	go_frames = type;
	if (type == 0u)
		return;
	if (go_frames == 0xA0u)
	{
		command = 0x3F33u;
		vector_queue_sound(command);
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
void bonus_results(uint16_t *p_state_table, uint16_t *p_d, uint32_t *p_results_done)
{
	uint16_t d = (uint16_t)*p_d;
	uint32_t results_done = *p_results_done;
	uint16_t state_table = 0;
	uint8_t state_number = 0;

	state_number = io_read8(bonus_results_state);
	state_table = bonus_results_states_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)state_number << 1))
	{
	case 0:
		bonus_results_start(&state_table, &d, &results_done);
		break;
	case 2:
		bonus_results_first(&state_table, &d, &results_done);
		break;
	case 4:
		bonus_results_second(&state_table, &d, &results_done);
		break;
	case 6:
		bonus_results_third(&state_table, &d, &results_done);
		break;
	case 8:
		bonus_results_fourth(&state_table, &d, &results_done);
		break;
	case 10:
		bonus_results_wait(&state_table, &d, &results_done);
		break;
	case 12:
		bonus_results_wait_count(&state_table, &d, &results_done);
		break;
	case 14:
		bonus_results_count_points(&state_table, &d, &results_done);
		break;
	}
	*p_state_table = state_table;
	*p_d = d;
	*p_results_done = results_done;
}

/* The bonuses' results: prepares the four result boxes, then ranks the winners. */
void bonus_results_start(uint16_t *p_x, uint16_t *p_d, uint32_t *p_results_done)
{
	uint32_t results_done = *p_results_done;
	uint16_t d = 0, object = 0, parent = 0, x = 0;
	uint8_t boxes_left_before = 0, old_boxes_placed = 0;

	io_write8(bonus_results_state, 1u);
	io_write8(results_last_result, 0xFFu);
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
		boxes_left_before = results_boxes_left;
		results_boxes_left = boxes_left_before - 1u;
	} while (boxes_left_before != 1u);
	io_write8(results_place, 1u);
	old_boxes_placed = io_read8(results_boxes_placed);
	io_write8(results_boxes_placed, 0u);
	*p_x = x;
	*p_d = d;
	bonus_results_first(p_x, p_d, &results_done);
	*p_results_done = results_done;
}

/* The bonuses' results: puts the winners (first place sign). */
void bonus_results_first(uint16_t *p_sign_kind, uint16_t *p_d, uint32_t *p_results_done)
{
	uint32_t results_done = *p_results_done;
	uint16_t d = 0, sign_kind = 0;

	sign_kind = 0xE8Bu;
	bonus_results_place_next(&sign_kind, &d);
	*p_sign_kind = sign_kind;
	*p_d = d;
	bonus_results_animate(p_sign_kind, p_d, &results_done);
	*p_results_done = results_done;
}

/* The bonuses' results: after a wait, puts the players in second place. */
void bonus_results_second(uint16_t *p_sign_kind, uint16_t *p_d, uint32_t *p_results_done)
{
	uint16_t sign_kind = (uint16_t)*p_sign_kind;
	uint16_t d = (uint16_t)*p_d;
	uint32_t results_done = *p_results_done;
	uint8_t results_frames_left = 0, expired_frames = 0;

	results_frames_left = io_read8(bonus_results_timer);
	io_write8(bonus_results_timer, results_frames_left - 1u);
	if (results_frames_left != 1u)
		bonus_results_animate(&sign_kind, &d, &results_done);
	else
	{
		expired_frames = io_read8(bonus_results_timer);
		io_write8(bonus_results_timer, expired_frames + 1u);
		sign_kind = 0xE8Cu;
		bonus_results_place_next(&sign_kind, &d);
		bonus_results_animate(&sign_kind, &d, &results_done);
	}
	*p_sign_kind = sign_kind;
	*p_d = d;
	*p_results_done = results_done;
}

/* The bonuses' results: after a wait, puts the players in third place. */
void bonus_results_third(uint16_t *p_sign_kind, uint16_t *p_d, uint32_t *p_results_done)
{
	uint16_t sign_kind = (uint16_t)*p_sign_kind;
	uint16_t d = (uint16_t)*p_d;
	uint32_t results_done = *p_results_done;
	uint8_t results_frames_left = 0, expired_frames = 0;

	results_frames_left = io_read8(bonus_results_timer);
	io_write8(bonus_results_timer, results_frames_left - 1u);
	if (results_frames_left != 1u)
		bonus_results_animate(&sign_kind, &d, &results_done);
	else
	{
		expired_frames = io_read8(bonus_results_timer);
		io_write8(bonus_results_timer, expired_frames + 1u);
		sign_kind = 0xE8Du;
		bonus_results_place_next(&sign_kind, &d);
		bonus_results_animate(&sign_kind, &d, &results_done);
	}
	*p_sign_kind = sign_kind;
	*p_d = d;
	*p_results_done = results_done;
}

/* The bonuses' results: after a wait, puts the players in fourth place. */
void bonus_results_fourth(uint16_t *p_sign_kind, uint16_t *p_d, uint32_t *p_results_done)
{
	uint16_t sign_kind = (uint16_t)*p_sign_kind;
	uint16_t d = (uint16_t)*p_d;
	uint32_t results_done = *p_results_done;
	uint8_t results_frames_left = 0, expired_frames = 0;

	results_frames_left = io_read8(bonus_results_timer);
	io_write8(bonus_results_timer, results_frames_left - 1u);
	if (results_frames_left != 1u)
		bonus_results_animate(&sign_kind, &d, &results_done);
	else
	{
		expired_frames = io_read8(bonus_results_timer);
		io_write8(bonus_results_timer, expired_frames + 1u);
		sign_kind = 0xE8Eu;
		bonus_results_place_next(&sign_kind, &d);
		bonus_results_animate(&sign_kind, &d, &results_done);
	}
	*p_sign_kind = sign_kind;
	*p_d = d;
	*p_results_done = results_done;
}

/* The bonuses' results: waits before counting the points. */
void bonus_results_wait(uint16_t *p_hop_speed_table, uint16_t *p_state_and_frames, uint32_t *p_results_done)
{
	uint16_t hop_speed_table = (uint16_t)*p_hop_speed_table;
	uint16_t state_and_frames = (uint16_t)*p_state_and_frames;
	uint32_t results_done = *p_results_done;
	uint8_t results_frames_left = 0;

	results_frames_left = io_read8(bonus_results_timer);
	io_write8(bonus_results_timer, results_frames_left - 1u);
	if (results_frames_left != 1u)
		bonus_results_animate(&hop_speed_table, &state_and_frames, &results_done);
	else
	{
		state_and_frames = 0x63Cu;
		io_write16(bonus_results_state, 0x63Cu);
		bonus_results_animate(&hop_speed_table, &state_and_frames, &results_done);
	}
	*p_hop_speed_table = hop_speed_table;
	*p_state_and_frames = state_and_frames;
	*p_results_done = results_done;
}

/* The bonuses' results: a last short wait before the points. */
void bonus_results_wait_count(uint16_t *p_hop_speed_table, uint16_t *p_state_and_frames, uint32_t *p_results_done)
{
	uint16_t hop_speed_table = (uint16_t)*p_hop_speed_table;
	uint16_t state_and_frames = (uint16_t)*p_state_and_frames;
	uint32_t results_done = *p_results_done;
	uint8_t results_frames_left = 0;

	results_frames_left = io_read8(bonus_results_timer);
	io_write8(bonus_results_timer, results_frames_left - 1u);
	if (results_frames_left != 1u)
		bonus_results_animate(&hop_speed_table, &state_and_frames, &results_done);
	else
	{
		state_and_frames = 0x704u;
		io_write16(bonus_results_state, 0x704u);
		bonus_results_animate(&hop_speed_table, &state_and_frames, &results_done);
	}
	*p_hop_speed_table = hop_speed_table;
	*p_state_and_frames = state_and_frames;
	*p_results_done = results_done;
}

/* The bonuses' results: types each box's text, makes the newly placed ones hop and reads the places. */
void bonus_results_animate(uint16_t *p_hop_speed_table, uint16_t *p_d, uint32_t *p_results_done)
{
	uint16_t hop_speed_table = (uint16_t)*p_hop_speed_table;
	uint16_t d = (uint16_t)*p_d;
	uint32_t results_done = *p_results_done;
	uint8_t hop = 0, z_speed = 0;
	uint16_t box = 0;
	uint8_t blocked = 0, blocked_2 = 0, hop_2 = 0, hop_3 = 0, boxes_left_before = 0;

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
		d = bonus_results_type_text(box, d);
		hop_2 = OBJECT(box)->bonus_results.hop;
		hop = hop_2;
		if (hop_2 != 0u)
		{
			hop_3 = OBJECT(box)->bonus_results.hop;
			OBJECT(box)->bonus_results.hop = hop_3 - 1u;
			hop_speed_table = bonus_results_hop_speeds_ADDRESS;
			z_speed = bonus_results_hop_speeds[(int8_t)hop];
			OBJECT(box)->z_speed = (OBJECT(box)->z_speed & 0xFFu) | ((z_speed & 0xFFu) << 8u);
			OBJECT(box + 0x60u)->z_speed = (OBJECT(box + 0x60u)->z_speed & 0xFFu) | ((z_speed & 0xFFu) << 8u);
		}
		box += 0xC0u;
		boxes_left_before = results_typed_boxes_left;
		results_typed_boxes_left = boxes_left_before - 1u;
	} while (boxes_left_before != 1u);
	bonus_results_read_places();
	results_done = 0u;
	d &= 0xFFu;
	*p_hop_speed_table = hop_speed_table;
	*p_d = d;
	*p_results_done = results_done;
}

/* The bonuses' results: counts each player's points up on its box with a tick sound, a sound when it is
   done; carry when all are. */
void bonus_results_count_points(uint16_t *p_next_print_place, uint16_t *p_d, uint32_t *p_results_done)
{
	uint16_t next_print_place = (uint16_t)*p_next_print_place;
	uint8_t d = (uint8_t)*p_d;
	uint32_t results_done = *p_results_done;
	uint8_t players_done = 0, points_shown = 0;
	uint16_t box = 0, command = 0, d_2 = 0;
	uint8_t results_frames_left = 0, points_shown_2 = 0, target_dy = 0, target_dy_2 = 0, look = 0, boxes_left_before = 0;

	players_done = (uint8_t)d;
	results_frames_left = io_read8(bonus_results_timer);
	io_write8(bonus_results_timer, results_frames_left - 1u);
	if (results_frames_left != 1u)
	{
		results_done = 0u;
		d_2 = players_done;
	}
	else
	{
		io_write8(bonus_results_timer, 4u);
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
					players_done = 1u;
					command = 0xA01u;
					vector_queue_sound(command);
					target_dy_2 = (uint8_t)(OBJECT(box)->target_dy >> 8u);
					OBJECT(box)->target_dy = (OBJECT(box)->target_dy & 0xFFu) | ((target_dy_2 + 1u & 0xFFu) << 8u);
				}
			}
			else
			{
				OBJECT(box)->bonus_results.points_shown = points_shown;
				d_2 = ((uint32_t)points_shown << 8) | players_done;
				d_2 = bonus_results_print_number(d_2);
				players_done = (uint8_t)d_2;
				look = OBJECT(box)->bonus_results.look;
			}
			next_print_place = results_print_place + 9u;
			results_print_place = next_print_place;
			box += 0xC0u;
			boxes_left_before = results_boxes_left;
			results_boxes_left = boxes_left_before - 1u;
		} while (boxes_left_before != 1u);
		command = 0x801u;
		vector_queue_sound(command);
		players_done = results_counts_done;
		bonus_results_read_places();
		if (players_done == 4u)
		{
			io_write16(bonus_results_state, 0u);
			results_done = 1u;
			d_2 = 0xFF00u;
		}
		else
		{
			results_done = 0u;
			d_2 = players_done;
		}
	}
	*p_next_print_place = next_print_place;
	*p_d = d_2;
	*p_results_done = results_done;
}

/* The bonuses' results: keeps the four players' places (for bonus 1's flight waits). */
void bonus_results_read_places(void)
{
	results_marge_place = OBJECT(OBJECT_ADDRESS(14))->bonus_results.place;
	results_homer_place = OBJECT(OBJECT_ADDRESS(16))->bonus_results.place;
	results_bart_place = OBJECT(OBJECT_ADDRESS(18))->bonus_results.place;
	results_lisa_place = OBJECT(OBJECT_ADDRESS(20))->bonus_results.place;
}

/* The bonuses' results: finds the best result not placed yet and puts every player who has it in that
   place: its sign hops in and its box and text appear. */
void bonus_results_place_next(uint16_t *p_sign_kind, uint16_t *p_d)
{
	uint16_t sign_kind = (uint16_t)*p_sign_kind;
	uint8_t look = 0, look_2 = 0, place = 0, placed = 0, players_left = 0, result = 0;
	uint16_t box = 0, box_text = 0, d = 0, kind = 0, object = 0;
	uint8_t type = 0, placed_before = 0, players_left_before = 0, look_3 = 0, result_to_place = 0, current_place = 0, old_boxes_placed = 0, boxes_left_before = 0, boxes_placed = 0, old_place = 0;
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
		placed_before = io_read8(results_last_result);
		if (result < placed_before && placed_result <= result)
		{
			placed_count++;
			placed_result = result;
		}
		object += 0xC0u;
		players_left_before = players_left;
		players_left = players_left_before - 1u;
	} while (players_left_before != 1u);
	if (placed_count != 0u)
	{
		io_write8(results_last_result, placed_result);
		placed_count = 0u;
		placed_result = 4u;
		box = OBJECT_ADDRESS(14);
		sign_kind = 0x78u;
		do
		{
			look_3 = OBJECT(box)->bonus_results.look;
			look = look_3;
			placed_count++;
			result_to_place = io_read8(results_last_result);
			if ((uint8_t)OBJECT(box - 0x540u)->type == result_to_place)
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
				current_place = io_read8(results_place);
				place = current_place;
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
				sign_kind = bonus_results_draw_box(sign_kind, box_text, box, look_2);
				OBJECT(box - 0x540u)->type++;
				old_boxes_placed = io_read8(results_boxes_placed);
				io_write8(results_boxes_placed, old_boxes_placed + 1u);
			}
			box += 0xC0u;
			sign_kind += 0x48u;
			boxes_left_before = placed_result;
			placed_result = boxes_left_before - 1u;
		} while (boxes_left_before != 1u);
		boxes_placed = io_read8(results_boxes_placed);
		placed = boxes_placed;
		if (placed == placed_count)
			placed = 5u;
		else
			placed++;
		io_write16(bonus_results_state, ((uint32_t)placed << 8) | 0xEu);
		old_place = io_read8(results_place);
		io_write8(results_place, old_place + 1u);
		d = ((uint32_t)placed << 8) | 0xEu;
	}
	else
		d = ((uint32_t)players_left << 8) | result;
	*p_sign_kind = sign_kind;
	*p_d = d;
}

/* The bonuses: keeps the row of the players' portraits (an absent player's sign instead) at the given
   place. */
void bonus_show_player_portraits(void)
{
	uint8_t look = 0, old_look = 0, player_bits = 0;
	uint16_t kind = 0, portrait = 0;
	uint8_t player_bits_left = 0, portrait_kind = 0, saved_portrait_animation = 0;
	uint8_t current_look = 0, look_before = 0, kind_2 = 0, state = 0, results_state = 0;
	uint16_t portrait_offset = 0, portrait_x = 0, portrait_y = 0;

	bonus_portrait_player = 0u;
	portrait = OBJECT_ADDRESS(14);
	player_bits = players_playing;
	do
	{
		player_bits_left = player_bits;
		current_look = OBJECT(portrait)->bonus_results.look;
		old_look = current_look;
		if (current_look != 0u)
		{
			look_before = old_look;
			old_look = look_before - 1u;
			if (look_before != 1u)
			{
				if (old_look != 1u)
				{
					kind_2 = OBJECT(portrait)->kind;
					if (kind_2 != 0xEu)
					{
						state = OBJECT(portrait)->state;
						OBJECT(portrait)->state = state - 1u;
						if (state == 1u)
							OBJECT(portrait)->flags = 0u;
					}
				}
				else
				{
					results_state = io_read8(bonus_results_state);
					if (results_state == 0u && (player_bits & 1u) != 0u)
					{
						kind = 0xEC2u;
						leftover_y = 0xEC2u;
						look = 1u;
						OBJECT(portrait)->bonus_results.look = look;
						OBJECT(portrait)->kind = (uint8_t)(kind >> 8u);
						OBJECT(portrait)->animation = (uint8_t)kind;
						OBJECT(portrait)->flags = 0x80u;
						portrait_offset = bonus_portrait_player * 0x48u;
						portrait_x = portrait_offset + bonus_draw_x;
						OBJECT(portrait)->x = portrait_x;
						portrait_y = bonus_draw_y;
						OBJECT(portrait)->y = portrait_y;
						OBJECT(portrait)->z = 0u;
					}
				}
			}
		}
		else if ((player_bits & 1u) != 0u)
		{
			OBJECT(portrait)->state = 0xFFu;
			portrait_kind = bonus_portrait_player + 0xAu;
			saved_portrait_animation = portrait_animation;
			kind = ((uint32_t)portrait_kind << 8) | saved_portrait_animation;
			leftover_y = kind;
			look = 3u;
			OBJECT(portrait)->bonus_results.look = look;
			OBJECT(portrait)->kind = (uint8_t)(kind >> 8u);
			OBJECT(portrait)->animation = (uint8_t)kind;
			OBJECT(portrait)->flags = 0x80u;
			portrait_offset = bonus_portrait_player * 0x48u;
			portrait_x = portrait_offset + bonus_draw_x;
			OBJECT(portrait)->x = portrait_x;
			portrait_y = bonus_draw_y;
			OBJECT(portrait)->y = portrait_y;
			OBJECT(portrait)->z = 0u;
		}
		else
		{
			kind = 0xEAEu;
			leftover_y = 0xEAEu;
			look = 2u;
			OBJECT(portrait)->bonus_results.look = look;
			OBJECT(portrait)->kind = (uint8_t)(kind >> 8u);
			OBJECT(portrait)->animation = (uint8_t)kind;
			OBJECT(portrait)->flags = 0x80u;
			portrait_offset = bonus_portrait_player * 0x48u;
			portrait_x = portrait_offset + bonus_draw_x;
			OBJECT(portrait)->x = portrait_x;
			portrait_y = bonus_draw_y;
			OBJECT(portrait)->y = portrait_y;
			OBJECT(portrait)->z = 0u;
		}
		player_bits = player_bits_left >> 1;
		portrait += 0xC0u;
		bonus_portrait_player++;
	} while (bonus_portrait_player != 4u);
}

/* The bonuses' results: types a box's text one letter every 4 frames into the tile RAM ('$' moves, '%'
   prints the points). */
uint16_t bonus_results_type_text(uint16_t box, uint16_t move)
{
	uint8_t character = 0, points = 0, text_wait = 0;
	uint16_t text = 0, text_cursor = 0;
	uint8_t text_wait_2 = 0, text_wait_3 = 0, text_byte = 0;
	uint16_t text_2 = 0, character_place = 0, move_place = 0, cursor_move = 0, text_cursor_2 = 0, text_cursor_3 = 0, text_cursor_4 = 0, tile_place = 0;

	text_wait = (uint8_t)(move >> 8);
	text_wait_2 = OBJECT(box)->bonus_results.text_wait;
	if ((int8_t)text_wait_2 >= 0)
	{
		text_wait_3 = OBJECT(box)->bonus_results.text_wait;
		OBJECT(box)->bonus_results.text_wait = text_wait_3 - 1u;
		if (text_wait_3 != 1u)
		{
			move = (move & 0xFFu) | ((uint32_t)text_wait << 8);
			return move;
		}
		for (;;)
		{
			text_2 = OBJECT(box)->bonus_results.text;
			character_place = text_2;
			text = character_place + 1u;
			leftover_y = text;
			text_byte = mem_read8(character_place);
			character = text_byte;
			if (text_byte == 0u)
			{
				text_wait = 0xFFu;
				OBJECT(box)->bonus_results.text_wait = text_wait;
				move = (move & 0xFFu) | ((uint32_t)text_wait << 8);
				return move;
			}
			if (character != 0x24u)
				break;
			move_place = text;
			cursor_move = mem_read16(move_place);
			move = cursor_move;
			OBJECT(box)->bonus_results.text = move_place + 2u;
			text_cursor_2 = OBJECT(box)->bonus_results.text_cursor;
			OBJECT(box)->bonus_results.text_cursor = text_cursor_2 + (((uint32_t)(cursor_move >> 8) << 8) | (move & 0xFFu));
		}
		OBJECT(box)->bonus_results.text = text;
		if (character == 0x25u)
		{
			points = results_number;
			text_cursor_3 = OBJECT(box)->bonus_results.text_cursor;
			results_print_place = text_cursor_3;
			move = (move & 0xFFu) | ((uint32_t)points << 8);
			move = bonus_results_print_number(move);
		}
		else
		{
			text_cursor_4 = OBJECT(box)->bonus_results.text_cursor;
			tile_place = text_cursor_4;
			text_cursor = tile_place + 1u;
			leftover_y = text_cursor;
			OBJECT(tile_place)->flags = character - 0x30u;
			OBJECT(box)->bonus_results.text_cursor = text_cursor;
		}
		text_wait = 4u;
		OBJECT(box)->bonus_results.text_wait = text_wait;
	}
	move = (move & 0xFFu) | ((uint32_t)text_wait << 8);
	return move;
}

/* The bonuses' results: writes the given number as up to three digits. */
uint16_t bonus_results_print_number(uint16_t number)
{
	uint8_t b = 0, hundreds = 0, number_left = 0, tens = 0;
	uint16_t place = 0;
	uint16_t tens_place = 0, hundreds_place = 0;

	number_left = (uint8_t)(number >> 8);
	b = (uint8_t)number;
	place = results_print_place + 1u;
	if (number_left < 0xAu)
	{
		io_write8(place, number_left);
		leftover_y = place;
		number = ((uint32_t)number_left << 8) | b;
		return number;
	}
	if (number_left < 0x64u)
	{
		tens = 0u;
		while (number_left >= 0xAu)
		{
			number_left -= 0xAu;
			tens++;
		}
		tens_place = place;
		place = tens_place + 1u;
		mem_write8(tens_place, tens);
		mem_write8(place, number_left);
		leftover_y = place;
		number = ((uint32_t)number_left << 8) | tens;
		return number;
	}
	number_left -= 0x64u;
	hundreds = 1u;
	if (number_left >= 0x64u)
	{
		number_left -= 0x64u;
		hundreds++;
	}
	hundreds_place = place;
	place = hundreds_place + 1u;
	io_write8(hundreds_place, hundreds);
	tens = 0u;
	while (number_left >= 0xAu)
	{
		number_left -= 0xAu;
		tens++;
	}
	tens_place = place;
	place = tens_place + 1u;
	mem_write8(tens_place, tens);
	mem_write8(place, number_left);
	leftover_y = place;
	number = ((uint32_t)number_left << 8) | tens;
	return number;
}

/* The bonuses: the number of the first player in the game. */
void bonus_first_player_in_game(uint16_t *p_first_player, uint32_t *p_no_player)
{
	uint32_t no_player = *p_no_player;
	uint8_t player_bits = 0;
	uint16_t first_player = 0;
	uint8_t bits_before = 0, slots_left_before = 0, first_player_number = 0;

	player_bits = players_playing;
	first_player_slots_left = 4u;
	do
	{
		bits_before = player_bits;
		player_bits = bits_before >> 1;
		if (bits_before & 1u)
			break;
		slots_left_before = first_player_slots_left;
		first_player_slots_left = slots_left_before - 1u;
	} while (slots_left_before != 1u);
	first_player_number = 4u - first_player_slots_left;
	no_player = first_player_number >> 7;
	first_player = ((uint32_t)first_player_number << 8) | player_bits;
	*p_first_player = first_player;
	*p_no_player = no_player;
}

/* The bonuses' results: draws a player's box of tiles under its sign (taller for a player in the game). */
uint16_t bonus_results_draw_box(uint16_t box_x, uint16_t y, uint16_t box, uint8_t look)
{
	uint8_t colour = 0, rows = 0, rows_left = 0;
	uint16_t box_tiles = 0, count = 0, tiles = 0;
	uint8_t colour_or_rows = 0, first_tile_high = 0, first_tile_low = 0;
	uint16_t saved_box_text = 0, saved_box_x = 0, box_start = 0;
	uint8_t tile_rows_before = 0, colour_rows_before = 0;
	uint16_t subtracted_scroll = 0, screen_x = 0, tile_column = 0, first_tile = 0;

	saved_box_text = y;
	saved_box_x = box_x;
	colour = 0xB2u;
	if (look != 3u)
		colour = 0xF2u;
	colour_or_rows = colour;
	box_start = box_x;
	subtracted_scroll = io_read16(0xA0u);
	screen_x = box_start - subtracted_scroll;
	tile_column = screen_x >> 3;
	first_tile = tile_column + 0x22C0u;
	first_tile_high = first_tile >> 8;
	first_tile_low = first_tile;
	tiles = ((uint32_t)first_tile_high << 8) | first_tile_low;
	colour = colour_or_rows;
	rows = 7u;
	if ((uint8_t)OBJECT(box - 0x540u)->type == 0u)
		rows = 4u;
	colour_or_rows = rows;
	rows_left = colour_or_rows;
	box_tiles = bonus_result_box_tiles_ADDRESS;
	box_start = tiles;
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
		tile_rows_before = rows_left;
		rows_left = tile_rows_before - 1u;
	} while (tile_rows_before != 1u);
	tiles = box_start - 0x2000u;
	rows_left = colour_or_rows;
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
		colour_rows_before = rows_left;
		rows_left = colour_rows_before - 1u;
	} while (colour_rows_before != 1u);
	box_x = saved_box_x;
	leftover_y = saved_box_text;
	return box_x;
}
