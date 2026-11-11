/**
 *    Name:        bonus/wake_up.c
 *    Description: bonus 2: wake up (the step after stage 6), yelling to fill a level
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    11-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the game's 053248 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

/* Bonus 2's introduction: starts its music (sound 8700). */
void bonus_2_start_music(void)
{
	uint16_t command = 0;
	uint8_t state_number = 0;

	command = 0x8700u;
	vector_queue_sound(command);
	state_number = io_read8(bonus_2_state);
	io_write8(bonus_2_state, state_number + 1u);
}

/* Bonus 2's introduction: the title and the camera's pan, then the first player in the game is put in
   the middle to show how it goes. */
void bonus_2_intro_set_up(void)
{
	uint32_t no_player = 0, pan_done = 0;
	uint8_t player_number = 0;
	uint16_t amount = 0, bonus_number = 0, field_offset = 0, first_player = 0, ignored16 = 0, object = 0;
	uint8_t walk_distance_high = 0, walk_distance_low = 0;
	uint8_t state_number = 0;
	uint16_t first_player_x = 0;

	bonus_number = 0x100u;
	bonus_number = bonus_title(bonus_number);
	bonus_pan(&ignored16, &bonus_number, &pan_done);
	if (pan_done == 0u)
		return;
	bonus_keep_backdrop();
	bonus_first_player_in_game(&first_player, &no_player);
	player_number = (uint8_t)(first_player >> 8);
	if (no_player)
	{
		state_number = io_read8(bonus_2_state);
		io_write8(bonus_2_state, state_number + 1u);
		return;
	}
	bonus_2_player_number = player_number;
	bonus_2_player_bits = 0xFu;
	object = OBJECT_ADDRESS(0);
	bonus_2_put_player(object);
	OBJECT(object)->parameter = 1u;
	first_player_x = 0xA8u - OBJECT(OBJECT_ADDRESS(0))->x;
	walk_distance_high = first_player_x >> 8;
	walk_distance_low = first_player_x;
	amount = ((uint32_t)walk_distance_high << 8) | walk_distance_low;
	field_offset = 0xCu;
	bonus_2_move_player(amount, object, field_offset);
	amount = 0x28u;
	field_offset = 0x16u;
	bonus_2_move_player(amount, object, field_offset);
	OBJECT(object)->attributes = 0x30u;
	state_number = io_read8(bonus_2_state);
	io_write8(bonus_2_state, state_number + 1u);
}

/* Bonus 2: adds an amount to a field of a player's object and of its two partners. */
void bonus_2_move_player(uint16_t amount, uint16_t player, uint16_t field_offset)
{
	uint16_t meter_coordinate = 0, sign_coordinate = 0;

	bonus_2_move_amount = amount;
	player += field_offset;
	mem_write16(player, mem_read16(player) + bonus_2_move_amount);
	meter_coordinate = mem_read16(player + 0x60u);
	mem_write16(player + 0x60u, meter_coordinate + bonus_2_move_amount);
	sign_coordinate = mem_read16(player + 0x840u);
	mem_write16(player + 0x840u, sign_coordinate + bonus_2_move_amount);
}

/* Bonus 2's introduction: the shown player reacts to the first player's presses while the hints blink. */
void bonus_2_intro_try(void)
{
	uint32_t level_full = 0;
	uint16_t bonus_number = 0, controls_and_bit = 0, player = 0, player_vars = 0;

	bonus_blink_hints();
	bonus_number = 0x100u;
	bonus_title(bonus_number);
	bonus_2_player_number = 0u;
	player = OBJECT_ADDRESS(0);
	player_vars = player_variables_ADDRESS;
	controls_and_bit = (uint32_t)player_controls(2) << 8;
	bonus_2_player(player_vars, player, &controls_and_bit, &level_full);
}

/* Bonus 2's contest: puts the four players, shows READY and sets the timer to 10 seconds. */
void bonus_2_set_up(void)
{
	uint32_t carry = 0;
	uint16_t ignored16 = 0, player_object = 0;

	player_object = OBJECT_ADDRESS(0);
	bonus_2_player_number = 0u;
	bonus_2_player_bits = players_playing;
	do
	{
		bonus_2_put_player(player_object);
		player_object += 0xC0u;
		bonus_2_player_number++;
	} while (bonus_2_player_number != 4u);
	marge_entry_status = 0u;
	homer_entry_status = 0u;
	bart_entry_status = 0u;
	lisa_entry_status = 0u;
	bonus_2_all_players(&ignored16, &carry);
	io_write16(bonus_2_state, 0x464u);
	bonus_show_ready();
	bonus_seconds = 0x10u;
	bonus_draw_x = 0xE0u;
	bonus_draw_y = 0xB8u;
	bonus_2_draw_sign();
	bonus_draw_timer();
	bonus_2_show_portraits();
}

/* Bonus 2: puts a player's portrait, its level meter and the sign beside it (another one for an absent
   player). */
void bonus_2_put_player(uint16_t player)
{
	uint8_t kind = 0, sign_animation = 0;
	uint16_t placed_x = 0;
	uint8_t player_bits_before = 0;

	OBJECT(player)->flags = 0x80u;
	OBJECT(player + 0x60u)->flags = 0x80u;
	OBJECT(player + 0x840u)->flags = 0x80u;
	kind = bonus_2_player_number + 0xAu;
	OBJECT(player)->kind = kind;
	OBJECT(player + 0x60u)->kind = kind;
	OBJECT(player)->animation = 0x88u;
	OBJECT(player + 0x60u)->animation = 0x91u;
	placed_x = bonus_2_portrait_x();
	OBJECT(player)->x = placed_x;
	OBJECT(player)->y = (OBJECT(player)->y & 0xFF00u) | 0xC0u;
	bonus_2_meter_offset = 0;
	placed_x = bonus_2_place_meter(player);
	OBJECT(player + 0x840u)->kind = 0xEu;
	OBJECT(player + 0x840u)->x = placed_x + bonus_2_side_object_x_offsets[(int8_t)bonus_2_player_number];
	OBJECT(player + 0x840u)->y = (OBJECT(player + 0x840u)->y & 0xFF00u) | 0x90u;
	OBJECT(player + 0x840u)->z = (OBJECT(player + 0x840u)->z & 0xFF00u) | 0x30u;
	sign_animation = 0x88u;
	player_bits_before = bonus_2_player_bits;
	bonus_2_player_bits = player_bits_before >> 1;
	if ((player_bits_before & 1u) == 0u)
		sign_animation = 0xC5u;
	OBJECT(player + 0x840u)->animation = sign_animation;
	OBJECT(player + 0x840u)->bonus_2.sign_kept_animation = sign_animation;
}

/* Bonus 2's contest: waits 100 frames with the players reacting, then starts the music (8A00) and the
   yelling. */
void bonus_2_countdown(void)
{
	uint32_t carry = 0;
	uint16_t command = 0, ignored16 = 0;
	uint8_t bonus_2_frames_left = 0;

	bonus_2_all_players(&ignored16, &carry);
	bonus_2_frames_left = io_read8(bonus_2_timer);
	io_write8(bonus_2_timer, bonus_2_frames_left - 1u);
	if (bonus_2_frames_left != 1u)
	{
		bonus_2_show_portraits();
		return;
	}
	command = 0x8A00u;
	vector_queue_sound(command);
	io_write8(bonus_2_state, 5u);
	bonus_2_show_portraits();
}

/* Bonus 2's contest: the players yell to fill their levels while the time runs; when a level is full or
   the time is up, the results' music. */
void bonus_2_yell(void)
{
	uint32_t contest_over = 0;
	uint16_t command = 0, ignored16 = 0;

	bonus_show_go();
	bonus_2_all_players(&ignored16, &contest_over);
	if (contest_over)
	{
		command = 0x8800u;
		vector_queue_sound(command);
		io_write16(bonus_2_state, 0x628u);
		bonus_2_show_portraits();
		return;
	}
	contest_over = bonus_timer_tick();
	if (contest_over)
	{
		command = 0x8800u;
		vector_queue_sound(command);
		io_write16(bonus_2_state, 0x628u);
		bonus_2_show_portraits();
		return;
	}
	bonus_draw_x = 0xE0u;
	bonus_draw_y = 0xB8u;
	bonus_draw_timer();
	bonus_2_show_portraits();
}

/* Bonus 2's end: shows the results; when they are done, the players take their end pose. */
void bonus_2_results(void)
{
	uint32_t results_done = 0;
	uint16_t ignored16 = 0, ignored16_2 = 0;
	uint8_t bonus_2_frames_left = 0, frames_before = 0, tested_frames = 0;

	bonus_2_frames_left = io_read8(bonus_2_timer);
	if (bonus_2_frames_left != 0u)
	{
		frames_before = io_read8(bonus_2_timer);
		io_write8(bonus_2_timer, frames_before - 1u);
	}
	bonus_2_all_players(&ignored16, &results_done);
	bonus_results(&ignored16_2, &ignored16, &results_done);
	if (results_done)
	{
		tested_frames = io_read8(bonus_2_timer);
		io_write16(bonus_2_state, 0x70Au);
		OBJECT(OBJECT_ADDRESS(0))->parameter = 6u;
		OBJECT(OBJECT_ADDRESS(2))->parameter = 6u;
		OBJECT(OBJECT_ADDRESS(4))->parameter = 6u;
		OBJECT(OBJECT_ADDRESS(6))->parameter = 6u;
	}
	bonus_2_show_portraits();
}

/* Bonus 2's last state: after a wait, gives the winner its health and goes on to the step's next part. */
void bonus_2_end(void)
{
	uint32_t carry = 0;
	uint16_t d = 0;
	uint8_t bonus_2_frames_left = 0;

	bonus_2_all_players(&d, &carry);
	bonus_2_frames_left = io_read8(bonus_2_timer);
	io_write8(bonus_2_timer, bonus_2_frames_left - 1u);
	if (bonus_2_frames_left != 1u)
	{
		bonus_2_show_portraits();
		return;
	}
	bonus_reward_winners(&d, &carry);
	step_phase++;
	step_subphase = (uint8_t)(d >> 8u);
	step_countdown = (uint8_t)d;
	bonus_2_show_portraits();
}

/* Bonus 2: shows the players' portraits along the bottom. */
void bonus_2_show_portraits(void)
{
	bonus_draw_x = 0x78u;
	bonus_draw_y = 0xA8u;
	portrait_animation = 0x90u;
	bonus_show_player_portraits();
}

/* Bonus 2: runs each player's reactions with its presses (carry: one has filled its level). */
void bonus_2_all_players(uint16_t *p_d, uint32_t *p_level_full)
{
	uint32_t level_full = *p_level_full;
	uint8_t a = 0, b = 0;
	uint16_t controls_and_bit = 0, d = 0, player = 0, player_vars = 0;

	bonus_2_player_number = 0u;
	player = OBJECT_ADDRESS(0);
	player_vars = player_variables_ADDRESS;
	controls_and_bit = ((uint32_t)player_controls(2) << 8) | 1u;
	bonus_2_player(player_vars, player, &controls_and_bit, &level_full);
	a = (uint8_t)(controls_and_bit >> 8);
	b = (uint8_t)controls_and_bit;
	if (level_full == 0u)
	{
		bonus_2_player_number = 1u;
		player = OBJECT_ADDRESS(2);
		player_vars = homer_lives_ADDRESS;
		controls_and_bit = ((uint32_t)player_controls(6) << 8) | 2u;
		bonus_2_player(player_vars, player, &controls_and_bit, &level_full);
		a = (uint8_t)(controls_and_bit >> 8);
		b = (uint8_t)controls_and_bit;
		if (level_full == 0u)
		{
			bonus_2_player_number = 2u;
			player = OBJECT_ADDRESS(4);
			player_vars = bart_lives_ADDRESS;
			controls_and_bit = ((uint32_t)player_controls(10) << 8) | 4u;
			bonus_2_player(player_vars, player, &controls_and_bit, &level_full);
			a = (uint8_t)(controls_and_bit >> 8);
			b = (uint8_t)controls_and_bit;
			if (level_full == 0u)
			{
				bonus_2_player_number = 3u;
				player = OBJECT_ADDRESS(6);
				player_vars = lisa_lives_ADDRESS;
				controls_and_bit = ((uint32_t)player_controls(14) << 8) | 8u;
				bonus_2_player(player_vars, player, &controls_and_bit, &level_full);
				a = (uint8_t)(controls_and_bit >> 8);
				b = (uint8_t)controls_and_bit;
			}
		}
	}
	d = ((uint32_t)a << 8) | b;
	*p_d = d;
	*p_level_full = level_full;
}

/* Bonus 2: one player: takes its presses (an absent player presses at random), plays the sign's sound on
   its marked frame and runs the player's state (field 30). */
void bonus_2_player(uint16_t player_vars, uint16_t player, uint16_t *p_controls_and_bit, uint32_t *p_level_full)
{
	uint16_t controls_and_bit = (uint16_t)*p_controls_and_bit;
	uint32_t level_full = *p_level_full;
	uint8_t box_look = 0, kind = 0, animation_flags = 0, reaction = 0;

	bonus_2_meter_offset = 0;
	OBJECT(player)->target_dy = (OBJECT(player)->target_dy & 0xFF00u) | (controls_and_bit >> 8 & 0xFFu);
	bonus_2_player_bit = (uint8_t)controls_and_bit;
	bonus_2_player_variables = player_vars;
	box_look = (uint8_t)OBJECT(player + 0x540u)->target_dy;
	if (box_look != 3u)
	{
		OBJECT(player)->target_dy &= 0xFF00u;
		kind = OBJECT(player)->kind;
		if ((int8_t)(((kind - 0xAu) ^ random_number) & 0xFu) < 2)
			OBJECT(player)->target_dy = (OBJECT(player)->target_dy & 0xFF00u) | 0x10u;
	}
	animation_flags = OBJECT(player + 0x840u)->animation_flags;
	if ((animation_flags & 2u) != 0u)
	{
		controls_and_bit = 0x4900u;
		vector_queue_sound(controls_and_bit);
	}
	reaction = OBJECT(player)->bonus_2.reaction;
	switch ((int8_t)(uint8_t)((uint32_t)reaction << 1))
	{
	case 0:
		bonus_2_wait_start(player, &controls_and_bit, &level_full);
		break;
	case 2:
		bonus_2_level(player, &controls_and_bit, &level_full);
		break;
	case 4:
	case 6:
	case 8:
	case 10:
		bonus_2_not_full(&controls_and_bit, &level_full);
		break;
	case 12:
		bonus_2_end_pose(player, &controls_and_bit, &level_full);
		break;
	case 14:
		bonus_2_full(player, &controls_and_bit, &level_full);
		break;
	case 16:
		bonus_2_shake(player, &controls_and_bit, &level_full);
		break;
	case 18:
		bonus_2_squash(player, &controls_and_bit, &level_full);
		break;
	case 20:
		bonus_2_meter_jumps(player, &controls_and_bit, &level_full);
		break;
	case 22:
		bonus_2_bounce(player, &controls_and_bit, &level_full);
		break;
	}
	*p_controls_and_bit = controls_and_bit;
	*p_level_full = level_full;
}

/* Bonus 2: a player waits for the yelling to start. */
void bonus_2_wait_start(uint16_t player, uint16_t *p_d, uint32_t *p_level_full)
{
	uint32_t level_full = *p_level_full;
	uint16_t d = 0;
	uint8_t bonus_state = 0;

	bonus_state = io_read8(bonus_2_state);
	if (bonus_state == 5u)
		OBJECT(player)->bonus_2.reaction = 1u;
	level_full = 0u;
	d = 0u;
	*p_d = (*p_d & 0xFFu) | d;
	*p_level_full = level_full;
}

/* Bonus 2: a player's end pose. */
void bonus_2_end_pose(uint16_t player, uint16_t *p_d, uint32_t *p_level_full)
{
	uint32_t level_full = *p_level_full;
	uint16_t d = 0;
	uint8_t reaction = 0, box_place = 0, sign_animation = 0;

	reaction = OBJECT(player)->bonus_2.reaction;
	OBJECT(player)->bonus_2.reaction = reaction + 1u;
	OBJECT(player)->bonus_2.level = (OBJECT(player)->bonus_2.level & 0xFFu) | 0x5C00u;
	box_place = OBJECT(player + 0x540u)->bonus_2.result_place;
	if (box_place != 1u)
		bonus_2_level(player, &d, &level_full);
	else
	{
		OBJECT(player)->animation = 0x8Au;
		sign_animation = OBJECT(player + 0x840u)->bonus_2.sign_kept_animation;
		OBJECT(player + 0x840u)->animation = sign_animation + 2u;
		bonus_2_level(player, &d, &level_full);
	}
	*p_d = d;
	*p_level_full = level_full;
}

/* Bonus 2: a player whose level is full: its meter shows it. */
void bonus_2_full(uint16_t player, uint16_t *p_d, uint32_t *p_level_full)
{
	uint32_t level_full = *p_level_full;
	uint16_t d = 0;
	uint8_t kind = 0;

	kind = OBJECT(player)->kind;
	if ((uint8_t)(random_number + kind) != 0u)
		bonus_2_not_full(&d, &level_full);
	else
	{
		OBJECT(player + 0x60u)->animation = 0x8Bu;
		bonus_2_not_full(&d, &level_full);
	}
	*p_d = (*p_d & 0xFFu) | d;
	*p_level_full = level_full;
}

/* Bonus 2: a reaction to yelling: the player shakes from side to side. */
void bonus_2_shake(uint16_t player, uint16_t *p_d, uint32_t *p_level_full)
{
	uint32_t level_full = *p_level_full;
	uint16_t d = 0, portrait_x = 0;
	uint8_t reaction_time = 0, sign_animation = 0, reaction_time_2 = 0, animation = 0;

	reaction_time = OBJECT(player)->bonus_2.reaction_time;
	OBJECT(player)->bonus_2.reaction_time = reaction_time - 1u;
	if (reaction_time == 1u)
	{
		OBJECT(player)->bonus_2.reaction = 1u;
		portrait_x = bonus_2_portrait_x();
		OBJECT(player)->x = portrait_x;
		sign_animation = OBJECT(player + 0x840u)->bonus_2.sign_kept_animation;
		OBJECT(player + 0x840u)->animation = sign_animation;
		bonus_2_level(player, &d, &level_full);
	}
	else
	{
		portrait_x = bonus_2_portrait_x();
		reaction_time_2 = OBJECT(player)->bonus_2.reaction_time;
		OBJECT(player)->x = portrait_x + bonus_2_shake_x_offsets[reaction_time_2 >> 1];
		animation = OBJECT(player)->animation;
		OBJECT(player)->animation = animation | 0x80u;
		bonus_2_level(player, &d, &level_full);
	}
	*p_d = d;
	*p_level_full = level_full;
}

/* Bonus 2: a reaction to yelling: the player squashes and stretches. */
void bonus_2_squash(uint16_t player, uint16_t *p_d, uint32_t *p_level_full)
{
	uint32_t level_full = *p_level_full;
	uint8_t zoom_index = 0, zoom_x_value = 0, zoom_y_value = 0;
	uint16_t d = 0, portrait_x = 0;
	uint8_t reaction_time = 0, sign_animation = 0, current_level = 0, reaction_time_2 = 0;
	uint32_t zoom_x_halfword = 0, zoom_x_halfword_2 = 0;

	reaction_time = OBJECT(player)->bonus_2.reaction_time;
	OBJECT(player)->bonus_2.reaction_time = reaction_time - 1u;
	if (reaction_time == 1u)
	{
		OBJECT(player)->bonus_2.reaction = 1u;
		portrait_x = bonus_2_portrait_x();
		OBJECT(player)->x = portrait_x;
		sign_animation = OBJECT(player + 0x840u)->bonus_2.sign_kept_animation;
		OBJECT(player + 0x840u)->animation = sign_animation;
		bonus_2_level(player, &d, &level_full);
	}
	else
	{
		current_level = (uint8_t)(OBJECT(player)->bonus_2.level >> 8u);
		if ((int8_t)current_level <= 0x30)
			bonus_2_level(player, &d, &level_full);
		else
		{
			OBJECT(player)->flags = 0x90u;
			OBJECT(player + 0x60u)->flags = 0x90u;
			reaction_time_2 = OBJECT(player)->bonus_2.reaction_time;
			zoom_index = reaction_time_2 >> 1;
			zoom_y_value = bonus_2_squash_zooms_y[zoom_index];
			zoom_x_value = bonus_2_squash_zooms_x[zoom_index];
			zoom_x_halfword = ((uint32_t)zoom_x_value << 8) | zoom_y_value;
			OBJECT(player)->zoom_x = (uint8_t)(zoom_x_halfword >> 8u);
			OBJECT(player)->zoom_y = (uint8_t)zoom_x_halfword;
			zoom_x_halfword_2 = ((uint32_t)zoom_x_value << 8) | zoom_y_value;
			OBJECT(player + 0x60u)->zoom_x = (uint8_t)(zoom_x_halfword_2 >> 8u);
			OBJECT(player + 0x60u)->zoom_y = (uint8_t)zoom_x_halfword_2;
			bonus_2_level(player, &d, &level_full);
		}
	}
	*p_d = d;
	*p_level_full = level_full;
}

/* Bonus 2: a reaction to yelling: the level meter moves aside. */
void bonus_2_meter_jumps(uint16_t player, uint16_t *p_d, uint32_t *p_level_full)
{
	uint32_t level_full = *p_level_full;
	uint8_t jump_step = 0;
	uint16_t d = 0, portrait_x = 0;
	uint8_t reaction_time = 0, sign_animation = 0, current_level = 0, reaction_time_2 = 0;

	reaction_time = OBJECT(player)->bonus_2.reaction_time;
	OBJECT(player)->bonus_2.reaction_time = reaction_time - 1u;
	if (reaction_time == 1u)
	{
		OBJECT(player)->bonus_2.reaction = 1u;
		portrait_x = bonus_2_portrait_x();
		OBJECT(player)->x = portrait_x;
		sign_animation = OBJECT(player + 0x840u)->bonus_2.sign_kept_animation;
		OBJECT(player + 0x840u)->animation = sign_animation;
		bonus_2_level(player, &d, &level_full);
	}
	else
	{
		current_level = (uint8_t)(OBJECT(player)->bonus_2.level >> 8u);
		if ((int8_t)current_level <= 0x48)
			bonus_2_level(player, &d, &level_full);
		else
		{
			reaction_time_2 = OBJECT(player)->bonus_2.reaction_time;
			jump_step = reaction_time_2 >> 1;
			bonus_2_meter_offset = TABLE8(bonus_2_level_object_x_moves, (uint16_t)(jump_step + (int8_t)((((uint32_t)bonus_2_player_number << 1) << 1) << 1)));
			if (jump_step != 7u)
				bonus_2_level(player, &d, &level_full);
			else
			{
				OBJECT(player)->animation = 0x89u;
				bonus_2_level(player, &d, &level_full);
			}
		}
	}
	*p_d = d;
	*p_level_full = level_full;
}

/* Bonus 2: a reaction to yelling: the player bounces up and down. */
void bonus_2_bounce(uint16_t player, uint16_t *p_d, uint32_t *p_level_full)
{
	uint32_t level_full = *p_level_full;
	uint16_t d = 0, portrait_x = 0;
	uint8_t reaction_time = 0, sign_animation = 0, current_level = 0, reaction_time_2 = 0, animation = 0;

	reaction_time = OBJECT(player)->bonus_2.reaction_time;
	OBJECT(player)->bonus_2.reaction_time = reaction_time - 1u;
	if (reaction_time == 1u)
	{
		OBJECT(player)->bonus_2.reaction = 1u;
		portrait_x = bonus_2_portrait_x();
		OBJECT(player)->x = portrait_x;
		sign_animation = OBJECT(player + 0x840u)->bonus_2.sign_kept_animation;
		OBJECT(player + 0x840u)->animation = sign_animation;
		bonus_2_level(player, &d, &level_full);
	}
	else
	{
		current_level = (uint8_t)(OBJECT(player)->bonus_2.level >> 8u);
		if ((int8_t)current_level <= 0x18)
			bonus_2_level(player, &d, &level_full);
		else
		{
			reaction_time_2 = OBJECT(player)->bonus_2.reaction_time;
			OBJECT(player)->y = 0xC0u + (int8_t)((((reaction_time_2 & 2u) << 1) << 1) - 4u);
			animation = OBJECT(player)->animation;
			OBJECT(player)->animation = animation | 0x80u;
			bonus_2_level(player, &d, &level_full);
		}
	}
	*p_d = d;
	*p_level_full = level_full;
}

/* Bonus 2: a player's level: shows it on the meter; it falls each frame, a press raises it and sometimes
   starts a reaction, and a long silence drops it; carry when full. */
void bonus_2_level(uint16_t player, uint16_t *p_d, uint32_t *p_level_full)
{
	uint32_t level_full = *p_level_full;
	uint8_t a = 0, b = 0;
	uint16_t d = 0;
	uint8_t level_high = 0, bonus_state = 0, pressed_controls = 0, quiet_frames = 0, quiet_frames_2 = 0, reaction = 0, level_low_bits = 0, sign_animation = 0, reaction_2 = 0;
	uint16_t level = 0, lowered_level = 0, level_2 = 0, dropped_level = 0, level_3 = 0, raised_level = 0;
	uint32_t random_rolled_once = 0, random_rolled_twice = 0, reaction_halfword = 0;

	bonus_2_place_meter(player);
	level_high = (uint8_t)(OBJECT(player)->bonus_2.level >> 8u);
	a = (level_high >> 1) >> 1;
	b = a;
	OBJECT(player + 0x60u)->animation = ((a >> 1) >> 1) - 0x6Fu;
	if (b <= 0x14u)
	{
		bonus_state = io_read8(bonus_2_state);
		a = bonus_state;
		if (a == 2u || a == 5u)
		{
			level = OBJECT(player)->bonus_2.level;
			lowered_level = level - 8u;
			a = (uint8_t)(lowered_level >> 8);
			b = (uint8_t)lowered_level;
			if ((int16_t)lowered_level < 0)
			{
				a = 0u;
				b = 0u;
			}
			OBJECT(player)->bonus_2.level = ((uint32_t)a << 8) | b;
			pressed_controls = (uint8_t)OBJECT(player)->target_dy;
			if ((pressed_controls & 0x30u) == 0u)
			{
				quiet_frames = OBJECT(player)->bonus_2.quiet_frames;
				if (quiet_frames == 0xFu)
				{
					level_2 = OBJECT(player)->bonus_2.level;
					dropped_level = level_2 - 0xB0u;
					a = (uint8_t)(dropped_level >> 8);
					b = (uint8_t)dropped_level;
					if ((int16_t)dropped_level < 0)
					{
						a = 0u;
						b = 0u;
						OBJECT(player)->bonus_2.quiet_frames = 0u;
					}
					OBJECT(player)->bonus_2.level = ((uint32_t)a << 8) | b;
					d = b;
					bonus_2_not_full(&d, &level_full);
				}
				else
				{
					quiet_frames_2 = OBJECT(player)->bonus_2.quiet_frames;
					OBJECT(player)->bonus_2.quiet_frames = quiet_frames_2 + 1u;
					d = b;
					bonus_2_not_full(&d, &level_full);
				}
			}
			else
			{
				level_3 = OBJECT(player)->bonus_2.level;
				raised_level = level_3 + 0x180u;
				b = (uint8_t)raised_level;
				OBJECT(player)->bonus_2.level = ((uint32_t)(raised_level >> 8) << 8) | b;
				OBJECT(player)->bonus_2.quiet_frames = 0u;
				reaction = OBJECT(player)->bonus_2.reaction;
				a = reaction;
				level_full = a < 3u;
				if ((int8_t)a < 3)
				{
					level_low_bits = b & 3u;
					b = level_low_bits;
					if (level_low_bits == 0u)
					{
						a = random_number;
						random_rolled_once = ((uint32_t)a << 1) | level_full;
						level_full = a >> 7;
						a = (uint8_t)random_rolled_once;
						random_rolled_twice = ((uint32_t)a << 1) | level_full;
						level_full = a >> 7;
						b = 0x10u;
						reaction_halfword = ((uint32_t)(uint8_t)(((((uint32_t)(uint8_t)random_rolled_twice << 1) | level_full) & 3u) + 8u) << 8) | 0x10u;
						OBJECT(player)->bonus_2.reaction = (uint8_t)(reaction_halfword >> 8u);
						OBJECT(player)->bonus_2.reaction_time = (uint8_t)reaction_halfword;
						OBJECT(player)->animation = 0x88u;
						sign_animation = OBJECT(player + 0x840u)->bonus_2.sign_kept_animation;
						OBJECT(player + 0x840u)->animation = sign_animation + 1u;
						OBJECT(player)->y = 0xC0u;
					}
				}
				d = b;
				bonus_2_not_full(&d, &level_full);
			}
		}
		else
		{
			d = b;
			bonus_2_not_full(&d, &level_full);
		}
	}
	else
	{
		reaction_2 = OBJECT(player)->bonus_2.reaction;
		a = reaction_2;
		if ((int8_t)a < 8)
		{
			b = 7u;
			OBJECT(player)->bonus_2.reaction = 7u;
		}
		level_full = 1u;
		d = ((uint32_t)(uint8_t)~a << 8) | b;
	}
	*p_d = d;
	*p_level_full = level_full;
}

/* Bonus 2: a player's state that only says its level is not full. */
void bonus_2_not_full(uint16_t *p_d, uint32_t *p_level_full)
{
	uint32_t level_full = *p_level_full;
	uint16_t d = 0;

	level_full = 0u;
	d = 0u;
	*p_d = (*p_d & 0xFFu) | d;
	*p_level_full = level_full;
}

/* Bonus 2: the x of the current player's portrait (the middle while it shows how it goes). */
uint16_t bonus_2_portrait_x(void)
{
	uint16_t portrait_x = 0;
	uint8_t player_x_high = 0, player_x_low = 0;
	uint8_t bonus_state = 0;
	uint16_t table_x = 0;

	bonus_state = io_read8(bonus_2_state);
	if (bonus_state != 2u)
	{
		table_x = bonus_2_player_x[(int8_t)((uint8_t)((uint32_t)bonus_2_player_number << 1)) / 2];
		player_x_high = table_x >> 8;
		player_x_low = table_x;
		portrait_x = ((uint32_t)player_x_high << 8) | player_x_low;
		return portrait_x;
	}
	portrait_x = 0xA8u;
	return portrait_x;
}

/* Bonus 2: places a player's level meter beside its portrait. */
uint16_t bonus_2_place_meter(uint16_t player)
{
	uint16_t meter_x = 0;
	uint8_t kind = 0;
	uint16_t dx = 0, player_x_place = 0, player_y_place = 0, z = 0;

	kind = OBJECT(player)->kind;
	dx = (((uint32_t)(uint8_t)XZ_OFFSET(bonus_2_level_object_offsets_ADDRESS + (int8_t)((uint32_t)kind << 1))->dx << 8u) | (uint8_t)XZ_OFFSET(bonus_2_level_object_offsets_ADDRESS + (int8_t)((uint32_t)kind << 1))->dz);
	player_x_place = OBJECT(player)->x;
	meter_x = player_x_place + (int8_t)(dx >> 8) + bonus_2_meter_offset;
	OBJECT(player + 0x60u)->x = meter_x;
	player_y_place = OBJECT(player)->y;
	OBJECT(player + 0x60u)->y = player_y_place - 2u;
	z = OBJECT(player)->z;
	OBJECT(player + 0x60u)->z = z + (int8_t)dx;
	return meter_x;
}

/* Does nothing: the sign that would go with bonus 2 (unused_bonus_2_put_sign, right after it) is not
   put. */
void bonus_2_draw_sign(void)
{
}

/* Unused: would put a kind 0E sign (animation 8F) at the given place. */
void unused_bonus_2_put_sign(void)
{
	OBJECT(OBJECT_ADDRESS(31))->flags = 0x80u;
	OBJECT(OBJECT_ADDRESS(31))->x = bonus_draw_x - 0x28u;
	OBJECT(OBJECT_ADDRESS(31))->y = 0xA0u;
	OBJECT(OBJECT_ADDRESS(31))->z = bonus_draw_y;
	OBJECT(OBJECT_ADDRESS(31))->kind = 0xEu;
	OBJECT(OBJECT_ADDRESS(31))->animation = 0x8Fu;
}

/* Unused: a bare return. */
void unused_bonus_rts(void)
{
}

/* Unreached: would take the sign of unused_bonus_2_put_sign off. */
void unreached_bonus_clear_sign(void)
{
	OBJECT(OBJECT_ADDRESS(31))->flags = 0u;
}
