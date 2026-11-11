/**
 *    Name:        players/players.c
 *    Description: bank 1C: the four players run each frame with their controls, and how a player joins the stage
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    11-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the game's 053248 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

/* Runs the four players' objects with their controls and records, adding their y scroll requests; at a
   stage's end, once all four stand idle, says so in 184E and removes the objects they carry. */
void player_run_all(void)
{
	uint8_t idle_players = 0, players_left = 0;
	uint16_t bit_and_number = 0, controls = 0, held_object = 0, player = 0, player_2 = 0, record = 0;
	uint8_t stack = 0, stack_10002 = 0;
	uint8_t last_idle_players = 0, last_heavy_workers = 0, last_all_idle = 0, stage_is_over = 0, t1 = 0, held_high = 0, players_before = 0;
	uint16_t held = 0;

	last_idle_players = io_read8(players_idle_count);
	io_write8(players_idle_count, 0u);
	last_heavy_workers = io_read8(heavy_object_workers);
	io_write8(heavy_object_workers, 0u);
	players_push_y = 0;
	stack = player_controls(0);
	stack_10002 = player_controls(2);
	controls = ((uint32_t)stack << 8) | stack_10002;
	player = OBJECT_ADDRESS(0);
	record = player_variables_ADDRESS;
	io_write16(running_player_values, player_variables_ADDRESS);
	bit_and_number = 0x100u;
	player_run(record, controls, player, bit_and_number);
	stack = player_controls(4);
	stack_10002 = player_controls(6);
	controls = ((uint32_t)stack << 8) | stack_10002;
	player = OBJECT_ADDRESS(2);
	record = homer_lives_ADDRESS;
	io_write16(running_player_values, homer_lives_ADDRESS);
	bit_and_number = 0x201u;
	player_run(record, controls, player, bit_and_number);
	stack = player_controls(8);
	stack_10002 = player_controls(10);
	controls = ((uint32_t)stack << 8) | stack_10002;
	player = OBJECT_ADDRESS(4);
	record = bart_lives_ADDRESS;
	io_write16(running_player_values, bart_lives_ADDRESS);
	bit_and_number = 0x402u;
	player_run(record, controls, player, bit_and_number);
	stack = player_controls(12);
	stack_10002 = player_controls(14);
	controls = ((uint32_t)stack << 8) | stack_10002;
	player = OBJECT_ADDRESS(6);
	record = lisa_lives_ADDRESS;
	io_write16(running_player_values, lisa_lives_ADDRESS);
	bit_and_number = 0x803u;
	player_run(record, controls, player, bit_and_number);
	last_all_idle = io_read8(players_all_idle);
	io_write8(players_all_idle, 0u);
	stage_is_over = io_read8(players_stop_request);
	if (stage_is_over != 0u)
	{
		t1 = io_read8(players_idle_count);
		idle_players = t1;
		if (idle_players != 4u)
			return;
		io_write8(players_all_idle, idle_players);
		player_2 = OBJECT_ADDRESS(0);
		players_left = 4u;
		do
		{
			if (OBJECT(player_2)->flags != 0u)
			{
				held = OBJECT(player_2)->player.held;
				held_object = held;
				if (held != 0u)
				{
					held_high = (uint8_t)(OBJECT(player_2)->player.held >> 8u);
					if (held_high != 0u)
						OBJECT(held_object)->flags = 0u;
				}
			}
			player_2 += 0xC0u;
			players_before = players_left;
			players_left = players_before - 1u;
		} while (players_before != 1u);
	}
}

/* Runs one player: when its record says it has not entered yet, sets it up afresh (full life unless it
   rejoins) and brings it in, jumping in from the left or dropping from above in scenes 4 and 0B, or
   blinking in place when it rejoins; then takes its controls (none at a stage's end, where its team-up
   is undone) and runs its state. */
void player_run(uint16_t record, uint16_t controls, uint16_t player, uint16_t bit_and_number)
{
	bool L_038159 = false;
	uint32_t negative = 0, carry = 0;
	uint8_t clear_value = 0, drop_x_high = 0, drop_x_low = 0, floor_value = 0, player_number = 0, scene_number = 0, shadow_player = 0, status = 0;
	uint16_t bytes_left = 0, command = 0, cursor = 0, floor_cell = 0, state_handlers = 0;
	uint8_t stack_10004 = 0;
	uint16_t stack = 0, stack_6 = 0;
	uint8_t idle_players = 0, entry_status = 0, all_idle = 0, status_2 = 0, shadow_player_2 = 0, kept_life = 0, status_3 = 0, status_4 = 0, tries_before = 0, kind = 0, t2 = 0, kind_2 = 0, t4 = 0, state_frames = 0, stage_is_over = 0, blink_frames = 0, animation_flags = 0, teamed = 0, frames_since_press = 0, frames_since_press_2 = 0, player_state = 0;
	uint16_t player_y = 0, entry_z = 0, kind_offset = 0, entry_x = 0, t1 = 0, t3 = 0, drop_x = 0, player_x = 0, moved_x = 0, first_drop_x = 0, t5 = 0, t6 = 0, partner = 0;

	player_number = (uint8_t)bit_and_number;
	if (((bit_and_number >> 8) & players_playing) == 0u)
	{
		idle_players = io_read8(players_idle_count);
		io_write8(players_idle_count, idle_players + 1u);
		return;
	}
	entry_status = PLAYER_VALUES(record)->entry_status;
	if (entry_status == 0u)
	{
		all_idle = io_read8(players_all_idle);
		if (all_idle != 0u)
		{
			idle_players = io_read8(players_idle_count);
			io_write8(players_idle_count, idle_players + 1u);
			return;
		}
		stack = record;
		stack_10004 = player_number;
		status_2 = OBJECT(player)->player.status;
		status = status_2;
		OBJECT(player)->animation = 0x80u;
		stack_6 = player;
		cursor = player + 0x1Cu;
		bytes_left = 0x3Du;
		clear_value = 0u;
		while (bytes_left != 0u)
		{
			mem_write8(cursor, clear_value);
			cursor++;
			bytes_left--;
		}
		player = stack_6;
		OBJECT(player)->player.status = status;
		if ((status & 2u) == 0u)
		{
			OBJECT(player)->attributes = 0u;
			OBJECT(player)->vitality = 0x28u;
			mem_write8(stack + 2u, 0x28u);
		}
		record = stack;
		shadow_player_2 = OBJECT(player)->shadow_player;
		shadow_player = (((((uint32_t)stack_10004 << 1) << 1) << 1) << 1) | shadow_player_2;
		OBJECT(player)->shadow_player = shadow_player;
		OBJECT(player + 0x60u)->shadow_player = shadow_player;
		kept_life = PLAYER_VALUES(record)->kept_life;
		OBJECT(player)->vitality = kept_life;
		PLAYER_VALUES(record)->entry_status = 1u;
		status_3 = OBJECT(player)->player.status;
		if ((status_3 & 2u) != 0u)
		{
			player_start_blinking(player);
			OBJECT(player)->flags = 0xC4u;
			status_4 = OBJECT(player)->player.status;
			OBJECT(player)->player.status = status_4 & ~2u;
			player_reset_box(player);
		}
		else
		{
			scene_number = scene;
			if (scene_number == 4u || scene_number == 0xBu)
				L_038159 = true;
			else
			{
				OBJECT(player)->y = 0xB8u;
				entry_tries_left = 4u;
				carry = player_find_entry_floor(player);
				for (;;)
				{
					if (carry)
					{
						player_y = OBJECT(player)->y;
						OBJECT(player)->y = player_y - 8u;
						tries_before = entry_tries_left;
						entry_tries_left = tries_before - 1u;
						if (tries_before != 1u)
						{
							carry = player_find_entry_floor(player);
							continue;
						}
						entry_tries_left = 9u;
						OBJECT(player)->y = 0xB8u;
						carry = player_find_entry_floor(player);
						for (;;)
						{
							if (carry == 0u)
							{
								entry_z = (uint8_t)entry_floor_height + 0x20u;
								OBJECT(player)->z = entry_z;
								OBJECT(player)->z_speed = 0x100;
								kind = OBJECT(player)->kind;
								kind_offset = (int8_t)((((((uint32_t)kind << 1) << 1) << 1) << 1) << 1);
								entry_x = kind_offset - 0x10u;
								OBJECT(player)->x = entry_x;
								record = 0xE00u;
								OBJECT(player)->x_speed = 0xE00;
								OBJECT(player)->player.player_state = 0x26u;
								OBJECT(player)->animation = 0xBAu;
								command = 0x1601u;
								vector_queue_sound(command);
								break;
							}
							t1 = OBJECT(player)->y;
							OBJECT(player)->y = t1 + 8u;
							t2 = entry_tries_left;
							entry_tries_left = t2 - 1u;
							if (t2 != 1u)
							{
								carry = player_find_entry_floor(player);
								continue;
							}
							L_038159 = true;
							break;
						}
						if (!L_038159)
							break;
					}
					if (L_038159)
						break;
					entry_z = (uint8_t)entry_floor_height + 0x20u;
					OBJECT(player)->z = entry_z;
					OBJECT(player)->z_speed = 0x100;
					kind = OBJECT(player)->kind;
					kind_offset = (int8_t)((((((uint32_t)kind << 1) << 1) << 1) << 1) << 1);
					entry_x = kind_offset - 0x10u;
					OBJECT(player)->x = entry_x;
					record = 0xE00u;
					OBJECT(player)->x_speed = 0xE00;
					OBJECT(player)->player.player_state = 0x26u;
					OBJECT(player)->animation = 0xBAu;
					command = 0x1601u;
					vector_queue_sound(command);
					break;
				}
			}
			if (L_038159)
			{
				kind_2 = OBJECT(player)->kind;
				t3 = (int8_t)((((((uint32_t)kind_2 << 1) << 1) << 1) << 1) << 1);
				drop_x = t3 + 0xD0u;
				drop_x_high = (uint8_t)(drop_x >> 8);
				drop_x_low = (uint8_t)drop_x;
				OBJECT(player)->x = ((uint32_t)drop_x_high << 8) | drop_x_low;
				io_write16(player_drop_x, ((uint32_t)drop_x_high << 8) | drop_x_low);
				OBJECT(player)->y = 0xC0u;
				OBJECT(player)->z = 0xD0u;
				entry_tries_left = 8u;
				record = player;
				vector_floor_ahead(record, &floor_cell, &negative);
				floor_value = (uint8_t)(floor_cell >> 8);
				for (;;)
				{
					if ((uint8_t)(floor_value + 1u) != 0u)
					{
						OBJECT(player)->z_speed = -0x400;
						OBJECT(player)->attributes = 0x40u;
						OBJECT(player)->player.player_state = 0x27u;
						OBJECT(player)->animation = 0xBBu;
						break;
					}
					player_x = OBJECT(player)->x;
					moved_x = player_x - 0x10u;
					OBJECT(player)->x = moved_x;
					t4 = entry_tries_left;
					entry_tries_left = t4 - 1u;
					if (t4 != 1u)
					{
						record = player;
						vector_floor_ahead(record, &floor_cell, &negative);
						floor_value = (uint8_t)(floor_cell >> 8);
						continue;
					}
					first_drop_x = io_read16(player_drop_x);
					OBJECT(player)->x = first_drop_x;
					do
					{
						t5 = OBJECT(player)->x;
						t6 = t5 + 0x10u;
						OBJECT(player)->x = t6;
						record = player;
						vector_floor_ahead(record, &floor_cell, &negative);
						floor_value = (uint8_t)(floor_cell >> 8);
					} while ((uint8_t)(floor_value + 1u) == 0u);
					OBJECT(player)->z_speed = -0x400;
					OBJECT(player)->attributes = 0x40u;
					OBJECT(player)->player.player_state = 0x27u;
					OBJECT(player)->animation = 0xBBu;
					break;
				}
				command = 0x1601u;
				vector_queue_sound(command);
			}
			OBJECT(player)->flags = 0xC4u;
			status_4 = OBJECT(player)->player.status;
			OBJECT(player)->player.status = status_4 & ~2u;
			player_reset_box(player);
		}
		OBJECT(player)->box_height = 0x18u;
		OBJECT(player)->box_dz = 0x18u;
		state_frames = OBJECT(player)->player.state_frames;
		OBJECT(player)->player.state_frames = state_frames + 1u;
		OBJECT(player)->damage = 0u;
		OBJECT(player)->attack = 0x13u;
	}
	else
	{
		stage_is_over = io_read8(players_stop_request);
		if (stage_is_over == 0u)
			OBJECT(player)->target_dy = controls;
		else
		{
			blink_frames = OBJECT(player)->player.blink_frames;
			if (blink_frames != 0u)
			{
				OBJECT(player)->player.blink_frames = 0u;
				OBJECT(player)->flags = 0x80u;
			}
			OBJECT(player + 0x60u)->flags = 0u;
			animation_flags = OBJECT(player + 0x60u)->animation_flags;
			OBJECT(player + 0x60u)->animation_flags = animation_flags | 1u;
			OBJECT(player)->player.controls = 0u;
			OBJECT(player)->player.controls_pressed = 0u;
			teamed = OBJECT(player)->player.teamed;
			if ((int8_t)teamed < 0)
			{
				partner = OBJECT(player)->player.partner;
				record = partner;
				player_team_split(record, player);
				OBJECT(player)->player.state_frames = 0u;
				OBJECT(record)->player.state_frames = 0u;
			}
		}
	}
	frames_since_press = OBJECT(player)->player.frames_since_press;
	if (frames_since_press < 0xEu)
	{
		frames_since_press_2 = OBJECT(player)->player.frames_since_press;
		OBJECT(player)->player.frames_since_press = frames_since_press_2 + 1u;
	}
	player_state = OBJECT(player)->player.player_state;
	state_handlers = player_state_handlers_ADDRESS;
	switch ((int16_t)(uint8_t)((uint32_t)player_state << 1))
	{
	case 0:
		player_stand(state_handlers, player);
		return;
	case 2:
	case 92:
	case 114:
	case 126:
		player_keep_life(player);
		return;
	case 4:
		player_jump(player);
		return;
	case 6:
		player_fall(player);
		return;
	case 8:
		player_throw_carried_4(state_handlers, player);
		return;
	case 10:
		player_throw_carried_5(state_handlers, player);
		return;
	case 12:
		player_swing_6(player);
		return;
	case 14:
		player_swing_7(player);
		return;
	case 16:
		player_throw_weapon_8(state_handlers, player);
		return;
	case 18:
		player_attack_1(player);
		return;
	case 20:
		player_attack_2(player);
		return;
	case 22:
		player_attack_3(player);
		return;
	case 24:
		player_attack_finish(player);
		return;
	case 26:
		player_jump_kick(player);
		return;
	case 28:
	case 46:
	case 80:
		player_drop_after_crash(state_handlers, player);
		return;
	case 30:
		player_flung_back(player);
		return;
	case 32:
	case 36:
	case 38:
	case 58:
	case 60:
	case 70:
	case 72:
		player_wait_for_animation(state_handlers, player);
		return;
	case 34:
		player_squashed(player);
		return;
	case 40:
		player_knocked_flying(player);
		return;
	case 42:
		player_knocked_down(player);
		return;
	case 44:
		player_lying_down(player);
		return;
	case 48:
	case 50:
		player_knocked_up(state_handlers, player);
		return;
	case 52:
	case 54:
		player_stunned(state_handlers, player);
		return;
	case 56:
		player_grabbed(state_handlers, player);
		return;
	case 62:
		player_lose_life(player);
		return;
	case 64:
		player_game_over_start(player);
		return;
	case 66:
		player_game_over_rise(player);
		return;
	case 68:
		player_game_over_end(player);
		return;
	case 74:
		player_idle(player);
		return;
	case 76:
		player_jump_in(player);
		return;
	case 78:
		player_drop_in(player);
		return;
	case 82:
		player_choose_attack(player);
		return;
	case 84:
		player_hold_pose(state_handlers, player);
		return;
	case 86:
		player_throw_weapon_away(state_handlers, player);
		return;
	case 88:
		player_work_heavy_object(state_handlers, player);
		return;
	case 90:
		player_heave_heavy_object(state_handlers, player);
		return;
	case 94:
		player_end_on_animation(state_handlers, player);
		return;
	case 96:
		player_team_ready(state_handlers, player);
		return;
	case 98:
		player_team_start(player);
		return;
	case 100:
		player_team_move(player);
		return;
	case 102:
		player_team_jump(player);
		return;
	case 104:
		player_team_fall(player);
		return;
	case 106:
	case 108:
		player_attack_fall(state_handlers, player);
		return;
	case 110:
		player_team_thrown(state_handlers, player);
		return;
	case 112:
		player_team_attack_homer(record, state_handlers, player);
		return;
	case 116:
		player_grabbed_and_hit(state_handlers, player);
		return;
	case 118:
		player_escape(player);
		return;
	case 120:
		player_stuck_on_back(player);
		return;
	case 122:
		player_slide_down_back(player);
		return;
	case 124:
		player_peel_off_back(player);
		return;
	}
}

/* Checks the 8 places 8 pixels apart from x 40 at the player's depth for a way in: carry when one is a
   wall; the highest floor met in F3. */
uint32_t player_find_entry_floor(uint16_t player)
{
	uint32_t carry = 0;
	uint16_t floor_height = 0;
	uint8_t places_before = 0;
	uint16_t player_x = 0;

	OBJECT(player)->x = 0x40u;
	entry_floor_height = 0;
	entry_places_left = 8u;
	do
	{
		player_floor_at_next_place(player, &floor_height, &carry);
		if (carry)
			return carry;
		if (entry_floor_height < (int8_t)floor_height)
			entry_floor_height = (uint8_t)floor_height;
		player_x = OBJECT(player)->x;
		OBJECT(player)->x = player_x + 8u;
		places_before = entry_places_left;
		entry_places_left = places_before - 1u;
	} while (places_before != 1u);
	carry = 0u;
	return carry;
}

/* Player state 40: when its animation ends, the next state with bit 2 of its flags off; then takes its
   touches. */
void player_next_state_at_animation_end(uint16_t kind, uint16_t object)
{
	uint8_t animation_flags = 0, parameter = 0;

	animation_flags = OBJECT(object)->animation_flags;
	if ((animation_flags & 1u) == 0u)
	{
		player_take_touches(kind, object);
		return;
	}
	parameter = OBJECT(object)->parameter;
	OBJECT(object)->parameter = parameter + 1u;
	OBJECT(object)->flags &= ~4u;
	player_take_touches(kind, object);
}

/* Player state 41: lands the player when its animation ends; until then takes its touches. */
void player_land_at_animation_end(uint16_t kind, uint16_t object)
{
	uint8_t animation_flags = 0;

	animation_flags = OBJECT(object)->animation_flags;
	if ((animation_flags & 1u) == 0u)
	{
		player_take_touches(kind, object);
		return;
	}
	player_land(object);
}

/* Runs each player's state: out, joining, playing, the continue's countdown, game over */
void update_players(uint16_t *p_player, uint16_t *p_slot, uint16_t *p_d, uint32_t *p_carry)
{
	uint16_t d = (uint16_t)*p_d;
	uint32_t carry = *p_carry;
	uint8_t players_done = 0;
	uint16_t d_2 = 0, player = 0, slot = 0;
	uint8_t stack = 0;
	uint16_t state = 0;

	slot = slot_credits_ADDRESS;
	stack = 0u;
	do
	{
		player = player_records[(int8_t)((uint8_t)((uint32_t)stack << 1)) / 2];
		leftover_y = player_status_handlers_ADDRESS;
		state = PLAYER(player)->state;
		switch ((int8_t)(uint8_t)((uint32_t)mem_read8(state) << 1))
		{
		case 0:
			d = player_out(player, slot);
			break;
		case 2:
		case 10:
			d = player_join(player, slot, (uint8_t)d);
			break;
		case 4:
			d = player_playing(player, slot, (uint8_t)d);
			break;
		case 6:
			d = player_continue_countdown(player, slot);
			break;
		case 8:
			d = player_game_over(player, slot);
			break;
		case 12:
		case 18:
		case 20:
			game_phase_check_none();
			break;
		case 14:
			d = check_players_out((uint8_t)d);
			break;
		case 16:
			continue_screen(&player, &slot, &d);
			break;
		}
		slot += 8u;
		stack = stack + 1u;
		players_done = stack;
		carry = players_done < 4u;
	} while (players_done != 4u);
	d_2 = (d & 0xFFu) | ((uint32_t)stack << 8);
	*p_player = player;
	*p_slot = slot;
	*p_d = d_2;
	*p_carry = carry;
}

/* A player out of the game: not playing; a credit (its slot's own with separate coin slots) lets it join */
uint16_t player_out(uint16_t player, uint16_t slot)
{
	uint8_t credits_high = 0, credits_low = 0;
	uint16_t credits_word = 0;
	uint16_t play_status = 0, own_credits = 0, state = 0, shared_credits = 0, state_2 = 0;

	play_status = PLAYER(player)->play_status;
	mem_write8(play_status, 0u);
	if (separate_coin_slots != 0u)
	{
		own_credits = COIN_SLOT(slot)->own_credits;
		credits_low = (uint8_t)own_credits;
		credits_high = (uint8_t)(own_credits >> 8);
		if (own_credits != 0u)
		{
			credits_high = 1u;
			state = PLAYER(player)->state;
			mem_write8(state, 1u);
		}
		credits_word = (credits_low & 0xFFu) | ((uint32_t)credits_high << 8);
		return credits_word;
	}
	shared_credits = credits;
	credits_low = (uint8_t)shared_credits;
	credits_high = (uint8_t)(shared_credits >> 8);
	if (shared_credits != 0u)
	{
		credits_high = 1u;
		state_2 = PLAYER(player)->state;
		mem_write8(state_2, 1u);
	}
	credits_word = (credits_low & 0xFFu) | ((uint32_t)credits_high << 8);
	return credits_word;
}

/* A player who may join: start or a button with a credit gives it its lives, its place in
   players_in_game and a full life; a new player's last score goes into the high scores first; then it
   plays */
uint16_t player_join(uint16_t player, uint16_t slot, uint8_t d)
{
	uint32_t carry = 0;
	uint8_t a = 0, b = 0, new_lives = 0;
	uint16_t coins = 0, d_2 = 0;
	uint8_t stack = 0;
	uint8_t start_pressed = 0, lives_added = 0, lives_before = 0, t1 = 0, bit = 0, initial_3 = 0, number = 0;
	uint16_t play_status = 0, lives = 0, coins_left = 0, lives_2 = 0, shared_credits = 0, state = 0, t2 = 0, credits_left = 0, lives_3 = 0, lives_4 = 0, life = 0, object_life = 0, countdown = 0, state_2 = 0, play_status_2 = 0, state_3 = 0, score = 0, last_score = 0, score_2 = 0, initial = 0;

	b = (uint8_t)d;
	play_status = PLAYER(player)->play_status;
	mem_write8(play_status, 0u);
	if (separate_coin_slots != 0u)
	{
		start_pressed = mem_read8(PLAYER(player)->pressed) & 0xB0u;
		a = start_pressed;
		if (start_pressed == 0u)
		{
			d_2 = ((uint32_t)a << 8) | b;
			return d_2;
		}
		lives = PLAYER(player)->lives;
		new_lives = mem_read8(lives);
		coins = COIN_SLOT(slot)->own_credits;
		do
		{
			lives_added = lives_per_credit;
			lives_before = new_lives;
			new_lives = lives_before + lives_added;
			if ((uint8_t)(lives_before + lives_added) < lives_before)
				new_lives = 0xFFu;
			coins_left = coins - 1u;
			coins = coins_left;
			leftover_y = coins;
		} while (coins_left != 0u);
		lives_2 = PLAYER(player)->lives;
		mem_write8(lives_2, new_lives);
		COIN_SLOT(slot)->own_credits = 0u;
	}
	else
	{
		shared_credits = credits;
		a = (uint8_t)(shared_credits >> 8);
		b = (uint8_t)shared_credits;
		if (shared_credits == 0u)
		{
			state = PLAYER(player)->state;
			mem_write8(state, 0u);
			d_2 = ((uint32_t)a << 8) | b;
			return d_2;
		}
		t1 = mem_read8(PLAYER(player)->pressed) & 0xB0u;
		a = t1;
		if (t1 == 0u)
		{
			d_2 = ((uint32_t)a << 8) | b;
			return d_2;
		}
		t2 = credits;
		credits_left = t2 - 1u;
		credits = credits_left;
		lives_3 = PLAYER(player)->lives;
		lives_4 = PLAYER(player)->lives;
		mem_write8(lives_4, mem_read8(lives_3) + lives_per_credit);
	}
	bit = PLAYER(player)->bit;
	players_playing |= bit;
	life = PLAYER(player)->life;
	mem_write8(life, 0x28u);
	object_life = PLAYER(player)->object_life;
	mem_write8(object_life, 0x28u);
	b = 0u;
	countdown = PLAYER(player)->countdown;
	PLAYER_COUNTERS(countdown)->seconds = 0u;
	PLAYER_COUNTERS(countdown)->frames = 0u;
	state_2 = PLAYER(player)->state;
	if (mem_read8(state_2) == 5u)
	{
		play_status_2 = PLAYER(player)->play_status;
		mem_write8(play_status_2, 2u);
		a = 2u;
		state_3 = PLAYER(player)->state;
		mem_write8(state_3, 2u);
		d_2 = ((uint32_t)a << 8) | b;
		return d_2;
	}
	score = PLAYER(player)->score;
	last_score = mem_read16(score);
	a = (uint8_t)(last_score >> 8);
	b = (uint8_t)last_score;
	new_high_score_points = ((uint32_t)a << 8) | b;
	score_2 = PLAYER(player)->score;
	mem_write16(score_2, 0u);
	d_2 = ((uint32_t)a << 8) | b;
	high_score_rank(&d_2, &carry);
	a = (uint8_t)(d_2 >> 8);
	b = (uint8_t)d_2;
	if (carry == 0u)
	{
		play_status_2 = PLAYER(player)->play_status;
		mem_write8(play_status_2, 2u);
		a = 2u;
		state_3 = PLAYER(player)->state;
		mem_write8(state_3, 2u);
		d_2 = ((uint32_t)a << 8) | b;
		return d_2;
	}
	stack = a;
	initial = (((uint32_t)PLAYER(player)->initial_1 << 8u) | PLAYER(player)->initial_2);
	b = (uint8_t)initial;
	new_high_score = ((uint32_t)(initial >> 8) << 8) | b;
	initial_3 = PLAYER(player)->initial_3;
	new_high_score_initial_3 = initial_3;
	number = PLAYER(player)->number;
	new_high_score_player = number;
	d_2 = ((uint32_t)stack << 8) | b;
	d_2 = insert_high_score(d_2);
	b = (uint8_t)d_2;
	play_status_2 = PLAYER(player)->play_status;
	mem_write8(play_status_2, 2u);
	a = 2u;
	state_3 = PLAYER(player)->state;
	mem_write8(state_3, 2u);
	d_2 = ((uint32_t)a << 8) | b;
	return d_2;
}

/* A player playing: when its lives run out it leaves players_in_game and its continue's countdown starts
   at 20 seconds, which the continue screen shows; with separate coin slots its slot's coins add lives */
uint16_t player_playing(uint16_t player, uint16_t slot, uint8_t d)
{
	uint8_t a = 0, b = 0, new_lives = 0;
	uint16_t coins = 0, d_2 = 0;
	uint8_t bit = 0, number = 0, own_slots = 0, lives_added = 0, lives_before = 0;
	uint16_t play_status = 0, lives = 0, countdown = 0, countdown_2 = 0, play_status_2 = 0, state = 0, own_credits = 0, lives_2 = 0, coins_left = 0, lives_3 = 0;

	b = (uint8_t)d;
	play_status = PLAYER(player)->play_status;
	mem_write8(play_status, 2u);
	lives = PLAYER(player)->lives;
	if (mem_read8(lives) == 0u)
	{
		bit = PLAYER(player)->bit;
		players_playing &= ~bit;
		number = PLAYER(player)->number;
		continue_player = number;
		countdown = PLAYER(player)->countdown;
		PLAYER_COUNTERS(countdown)->seconds = 0u;
		PLAYER_COUNTERS(countdown)->frames = 0u;
		countdown_2 = PLAYER(player)->countdown;
		PLAYER_COUNTERS(countdown_2)->seconds = 0x20u;
		continue_seconds = 0x20u;
		continue_frames = 0u;
		play_status_2 = PLAYER(player)->play_status;
		mem_write8(play_status_2, 1u);
		state = PLAYER(player)->state;
		mem_write8(state, 3u);
		d_2 = 0x300u;
		return d_2;
	}
	own_slots = separate_coin_slots;
	a = own_slots;
	if (own_slots != 0u)
	{
		own_credits = COIN_SLOT(slot)->own_credits;
		a = (uint8_t)(own_credits >> 8);
		b = (uint8_t)own_credits;
		if (own_credits == 0u)
		{
			d_2 = ((uint32_t)a << 8) | b;
			return d_2;
		}
		lives_2 = PLAYER(player)->lives;
		new_lives = mem_read8(lives_2);
		coins = COIN_SLOT(slot)->own_credits;
		do
		{
			lives_added = lives_per_credit;
			lives_before = new_lives;
			new_lives = lives_before + lives_added;
			if ((uint8_t)(lives_before + lives_added) < lives_before)
				new_lives = 0xFFu;
			coins_left = coins - 1u;
			coins = coins_left;
			leftover_y = coins;
		} while (coins_left != 0u);
		lives_3 = PLAYER(player)->lives;
		mem_write8(lives_3, new_lives);
		a = 0u;
		b = 0u;
		COIN_SLOT(slot)->own_credits = 0u;
	}
	d_2 = ((uint32_t)a << 8) | b;
	return d_2;
}

/* A player whose lives ran out: a credit lets it join again; else its countdown loses a second each 60
   frames while the gauges are shown, and at 0 it is game over */
uint16_t player_continue_countdown(uint16_t player, uint16_t slot)
{
	uint32_t carry = 0, half_carry = 0;
	uint8_t d = 0, seconds_left = 0;
	uint16_t countdown_digits = 0, d_2 = 0;
	uint8_t gauges_on = 0, frames_before = 0, frames_now = 0, seconds_now = 0, seconds_sum = 0;
	uint16_t play_status = 0, own_credits = 0, play_status_2 = 0, state = 0, shared_credits = 0, play_status_3 = 0, state_2 = 0, countdown = 0, credit_given = 0, play_status_4 = 0, state_3 = 0;

	play_status = PLAYER(player)->play_status;
	mem_write8(play_status, 1u);
	if (separate_coin_slots != 0u)
	{
		own_credits = COIN_SLOT(slot)->own_credits;
		d = (uint8_t)own_credits;
		if (own_credits != 0u)
		{
			play_status_2 = PLAYER(player)->play_status;
			mem_write8(play_status_2, 0u);
			state = PLAYER(player)->state;
			mem_write8(state, 5u);
			d_2 = (d & 0xFFu) | 0x500u;
			return d_2;
		}
	}
	else
	{
		shared_credits = credits;
		d = (uint8_t)shared_credits;
		if (shared_credits != 0u)
		{
			play_status_3 = PLAYER(player)->play_status;
			mem_write8(play_status_3, 0u);
			state_2 = PLAYER(player)->state;
			mem_write8(state_2, 5u);
			d_2 = (d & 0xFFu) | 0x500u;
			return d_2;
		}
	}
	gauges_on = gauges_shown;
	seconds_left = gauges_on;
	if (gauges_on != 0u)
	{
		countdown = PLAYER(player)->countdown;
		countdown_digits = countdown;
		leftover_y = countdown_digits;
		frames_before = PLAYER_COUNTERS(countdown_digits)->frames;
		PLAYER_COUNTERS(countdown_digits)->frames = frames_before + 1u;
		frames_now = PLAYER_COUNTERS(countdown_digits)->frames;
		seconds_left = frames_now;
		if (seconds_left == 0x3Cu)
		{
			PLAYER_COUNTERS(countdown_digits)->frames = 0u;
			seconds_now = PLAYER_COUNTERS(countdown_digits)->seconds;
			seconds_sum = 0x99u + seconds_now;
			half_carry = ((0x99u ^ seconds_now ^ seconds_sum) >> 4) & 1u;
			carry = (uint8_t)(0x99u + seconds_now) < 0x99u;
			seconds_left = konami_daa(seconds_sum, half_carry, carry);
			PLAYER_COUNTERS(countdown_digits)->seconds = seconds_left;
			if (seconds_left == 0x99u)
			{
				PLAYER_COUNTERS(countdown_digits)->seconds = 0u;
				PLAYER_COUNTERS(countdown_digits)->frames = 0u;
				credit_given = PLAYER(player)->credit_given;
				mem_write8(credit_given, 0u);
				play_status_4 = PLAYER(player)->play_status;
				mem_write8(play_status_4, 0u);
				seconds_left = 4u;
				state_3 = PLAYER(player)->state;
				mem_write8(state_3, 4u);
			}
		}
	}
	d_2 = (d & 0xFFu) | ((uint32_t)seconds_left << 8);
	return d_2;
}

/* A player's game over: C0 frames during which a credit still lets it in, then out of the game */
uint16_t player_game_over(uint16_t player, uint16_t slot)
{
	uint16_t d = 0;
	uint16_t play_status = 0, countdown = 0, countdown_2 = 0, countdown_3 = 0, state = 0;

	play_status = PLAYER(player)->play_status;
	mem_write8(play_status, 0u);
	COIN_SLOT(slot)->credit_given = 0u;
	countdown = PLAYER(player)->countdown;
	PLAYER_COUNTERS(countdown)->seconds++;
	countdown_2 = PLAYER(player)->countdown;
	if (PLAYER_COUNTERS(countdown_2)->seconds < 0xC0u)
		return player_out(player, slot);
	d = 0u;
	countdown_3 = PLAYER(player)->countdown;
	PLAYER_COUNTERS(countdown_3)->seconds = 0u;
	PLAYER_COUNTERS(countdown_3)->frames = 0u;
	state = PLAYER(player)->state;
	mem_write8(state, 0u);
	return d;
}

/* Counts the players in players_in_game into player_count, at least 1 */
void count_players_in_game(void)
{
	uint8_t players_left = 0, playing_bits = 0;
	uint8_t players_before = 0;

	player_count = 0u;
	playing_bits = players_playing;
	players_left = 4u;
	do
	{
		if ((playing_bits & 1u) != 0u)
			player_count++;
		playing_bits = playing_bits >> 1;
		players_before = players_left;
		players_left = players_before - 1u;
	} while (players_before != 1u);
	if (player_count == 0u)
		player_count++;
}

/* Outside the attract, gives the points of each beaten enemy to the player who beat it, through the
   score jobs */
void award_enemy_points(void)
{
	uint8_t points_code = 0;
	uint16_t job = 0, object = 0;
	uint8_t points = 0, objects_before = 0;

	if (in_attract != 0u)
		return;
	object = OBJECT_ADDRESS(14);
	points_objects_left = 8u;
	do
	{
		points = OBJECT(object)->points;
		points_code = points;
		if ((int8_t)points < 0 && (points_code & 0x40u) == 0u)
		{
			enemy_points = points_code;
			job = ((uint32_t)(uint8_t)((((((enemy_points & 0x30u) >> 1) >> 1) >> 1) >> 1) + 3u) << 8) | (points_code & 0xFu);
			queue_job(job);
			OBJECT(object)->points = 0u;
		}
		object += 0x60u;
		objects_before = points_objects_left;
		points_objects_left = objects_before - 1u;
	} while (objects_before != 1u);
}
