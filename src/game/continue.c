/**
 *    Name:        game/continue.c
 *    Description: the continue
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    09-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the game's 053248 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

/* The game's continue phase: the objects frozen, the players' handling and the continue screen */
void game_continue_phase(void)
{
	uint32_t carry = 0;
	uint16_t ignored16 = 0, ignored16_2 = 0, ignored16_3 = 0, u = 0;

	objects_frozen = 1u;
	update_players(&ignored16, &ignored16_2, &u, &ignored16_3, &carry);
	game_phase_check(u);
}

/* By mode_phase: while the stages play, the check that someone still plays; in the continue phase, the
   continue screen */
uint16_t game_phase_check(uint16_t u)
{
	uint16_t ignored16 = 0, ignored16_2 = 0, ignored16_3 = 0, player = 0;

	player = game_phase_checks_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)mode_phase << 1))
	{
	case 0:
	case 6:
	case 8:
		game_phase_check_none();
		return u;
	case 2:
		check_players_out(0u);
		return u;
	case 4:
		continue_screen(&ignored16, &ignored16_2, &u, &ignored16_3);
		return u;
	case -12:
		player_out(player, u);
		return u;
	case -10:
	case -2:
		player_join(player, u, &ignored16_2, &ignored16_3);
		return u;
	case -8:
		player_playing(player, u, &ignored16_2, &ignored16_3);
		return u;
	case -6:
		player_continue_countdown(player, u, &ignored16_2, &ignored16_3);
		return u;
	case -4:
		player_game_over(player, u);
		return u;
	}
	unreachable();
}

/* Nothing to check in this phase */
void game_phase_check_none(void)
{
}

/* When no player is playing any more: the continue's music, the stall object freed, the objects frozen
   and the game's continue phase */
uint16_t check_players_out(uint8_t d)
{
	uint32_t carry = 0;
	uint8_t play_status = 0;
	uint16_t command = 0, d_2 = 0;

	play_status = marge_play_status;
	if (play_status != 2u)
	{
		play_status = homer_play_status;
		if (play_status != 2u)
		{
			play_status = bart_play_status;
			if (play_status != 2u)
			{
				play_status = lisa_play_status;
				if (play_status == 2u)
				{
					d_2 = (d & 0xFFu) | ((uint32_t)play_status << 8);
					return d_2;
				}
				command = 0u;
				carry = queue_sound_always(command);
				command = 0xA100u;
				carry = queue_sound_always(command);
				if (hurry_up_out != 0u)
				{
					hurry_up_out = 0u;
					mem_write8(hurry_up_object, 0u);
				}
				d = 0u;
				hurry_up_frames = 0u;
				objects_frozen = 1u;
				play_status = 2u;
				mode_phase = 2u;
			}
		}
	}
	d_2 = (d & 0xFFu) | ((uint32_t)play_status << 8);
	return d_2;
}

/* A frame of the continue screen: CONTINUE and its count, a second each 60 frames or each press; a
   player who joins resumes the game and its music; at 0 the waiting players are out and the game over
   phase starts */
void continue_screen(uint16_t *p_player, uint16_t *p_player_vars, uint16_t *p_countdown_address, uint16_t *p_d)
{
	uint16_t player_vars = (uint16_t)*p_player_vars;
	uint16_t countdown_address = (uint16_t)*p_countdown_address;
	uint8_t d = (uint8_t)*p_d;
	uint32_t carry = 0, half_carry = 0;
	uint8_t a = 0, b = 0, player_number = 0, seconds = 0, state = 0;
	uint16_t command = 0, d_2 = 0, player = 0, x = 0;
	uint8_t stack = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0;
	uint16_t countdown = 0, credit_given = 0, countdown_2 = 0, countdown_3 = 0;

	b = (uint8_t)d;
	if (marge_play_status == 2u || homer_play_status == 2u || bart_play_status == 2u || lisa_play_status == 2u)
	{
		window_bank = 0x20u;
		set_lines(window_bank);
		continue_end();
		resume_stage_music();
		mode_phase = 1u;
		objects_frozen = 0u;
		clear_text_layer(&x, &d_2);
		a = (uint8_t)(d_2 >> 8);
		b = (uint8_t)d_2;
		d_2 = ((uint32_t)(uint8_t)~a << 8) | b;
		*p_player = x;
		*p_d = d_2;
		return;
	}
	stack = b;
	window_bank = 0x20u;
	set_lines(window_bank);
	state = stack;
	continue_draw();
	player = player_records[(int8_t)((uint8_t)((uint32_t)continue_player << 1)) / 2];
	continue_frames++;
	if (continue_frames == 0x3Cu)
	{
		t1 = continue_seconds;
		t2 = 0x99u + t1;
		half_carry = ((0x99u ^ t1 ^ t2) >> 4) & 1u;
		carry = (uint8_t)(0x99u + t1) < 0x99u;
		seconds = konami_daa(t2, half_carry, carry);
		if (seconds == 0x99u)
		{
			player_vars = player_variables_ADDRESS;
			player_number = 0u;
			do
			{
				t3 = mem_read8(player_vars + 7u);
				if (t3 == 3u)
				{
					stack = player_number;
					player = player_records[(int8_t)((uint8_t)((uint32_t)player_number << 1)) / 2];
					countdown = PLAYER(player)->countdown;
					countdown_address = countdown;
					mem_write16(countdown_address, 0u);
					credit_given = PLAYER(player)->credit_given;
					mem_write8(credit_given, 0u);
					mem_write8(player_vars + 7u, 4u);
					player_number = stack;
				}
				player_vars += 8u;
				player_number++;
			} while (player_number != 4u);
			command = 0u;
			carry = queue_sound_always(command);
			command = 0x7F00u;
			carry = queue_sound_always(command);
			command = 0x9200u;
			carry = queue_sound_always(command);
			continue_seconds = 0u;
			continue_player = 0u;
			mode_phase = 3u;
			game_step = 0u;
			d_2 = 0x300u;
			*p_player = player;
			*p_player_vars = player_vars;
			*p_countdown_address = countdown_address;
			*p_d = d_2;
			return;
		}
		continue_seconds = seconds;
		continue_frames = 0u;
	}
	if (((player_controls(2) | player_controls(6) | player_controls(10) | player_controls(14)) & 0x10u) == 0u)
	{
		if (continue_seconds == continue_seconds_heard)
		{
			seconds = continue_seconds;
			continue_seconds_heard = seconds;
			d_2 = ((uint32_t)seconds << 8) | state;
			*p_player = player;
			*p_player_vars = player_vars;
			*p_countdown_address = countdown_address;
			*p_d = d_2;
			return;
		}
		b = 1u;
		command = 0x501u;
		carry = queue_sound_always(command);
		seconds = continue_seconds;
		continue_seconds_heard = seconds;
		d_2 = ((uint32_t)seconds << 8) | b;
		*p_player = player;
		*p_player_vars = player_vars;
		*p_countdown_address = countdown_address;
		*p_d = d_2;
		return;
	}
	countdown_2 = PLAYER(player)->countdown;
	countdown_address = countdown_2;
	t4 = continue_seconds;
	t5 = 0x99u + t4;
	half_carry = ((0x99u ^ t4 ^ t5) >> 4) & 1u;
	carry = (uint8_t)(0x99u + t4) < 0x99u;
	seconds = konami_daa(t5, half_carry, carry);
	if (seconds == 0x99u)
	{
		player_vars = player_variables_ADDRESS;
		player_number = 0u;
		do
		{
			t3 = mem_read8(player_vars + 7u);
			if (t3 == 3u)
			{
				stack = player_number;
				player = player_records[(int8_t)((uint8_t)((uint32_t)player_number << 1)) / 2];
				countdown = PLAYER(player)->countdown;
				countdown_address = countdown;
				mem_write16(countdown_address, 0u);
				credit_given = PLAYER(player)->credit_given;
				mem_write8(credit_given, 0u);
				mem_write8(player_vars + 7u, 4u);
				player_number = stack;
			}
			player_vars += 8u;
			player_number++;
		} while (player_number != 4u);
		command = 0u;
		carry = queue_sound_always(command);
		command = 0x7F00u;
		carry = queue_sound_always(command);
		command = 0x9200u;
		carry = queue_sound_always(command);
		continue_seconds = 0u;
		continue_player = 0u;
		mode_phase = 3u;
		game_step = 0u;
		d_2 = 0x300u;
		*p_player = player;
		*p_player_vars = player_vars;
		*p_countdown_address = countdown_address;
		*p_d = d_2;
		return;
	}
	continue_frames = 0u;
	continue_seconds = seconds;
	mem_write8(countdown_address, seconds);
	player_vars = player_variables_ADDRESS;
	player_number = 0u;
	do
	{
		t6 = mem_read8(player_vars + 7u);
		state = t6;
		if (state == 3u)
		{
			stack = player_number;
			player = player_records[(int8_t)((uint8_t)((uint32_t)player_number << 1)) / 2];
			countdown_3 = PLAYER(player)->countdown;
			countdown_address = countdown_3;
			seconds = continue_seconds;
			if (seconds <= mem_read8(countdown_address))
			{
				mem_write8(countdown_address, seconds);
				mem_write8(countdown_address + 1u, 0u);
			}
			player_number = stack;
		}
		player_vars += 8u;
		player_number++;
	} while (player_number != 4u);
	if (continue_seconds == continue_seconds_heard)
	{
		seconds = continue_seconds;
		continue_seconds_heard = seconds;
		d_2 = ((uint32_t)seconds << 8) | state;
		*p_player = player;
		*p_player_vars = player_vars;
		*p_countdown_address = countdown_address;
		*p_d = d_2;
		return;
	}
	b = 1u;
	command = 0x501u;
	carry = queue_sound_always(command);
	seconds = continue_seconds;
	continue_seconds_heard = seconds;
	d_2 = ((uint32_t)seconds << 8) | b;
	*p_player = player;
	*p_player_vars = player_vars;
	*p_countdown_address = countdown_address;
	*p_d = d_2;
}
