/**
 *    Name:        players/states.c
 *    Description: the players' states: standing, walking, jumping, attacks, weapons, carrying, team moves, hit reactions, losing a life
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    11-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the game's 053248 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

/* Two players teamed up, moving together: either one's jump starts the team jump, attack the team attack
   (moves 2 and 3) or a faster run that hits (moves 0 and 1); otherwise they walk by their joysticks,
   hitting what they touch every 16 frames. */
void player_team_move(uint16_t player)
{
	bool L_038311 = false, L_038314 = false, L_038365 = false, L_03836A = false, L_0384D1 = false, L_0386E1 = false, L_0391EB = false, L_039205 = false, L_039216 = false;
	uint8_t animation_base = 0, animation_offset = 0, attack_state = 0, joystick_bits = 0, move_number = 0, owner_kind = 0, pressed_either = 0, voice_high = 0, voice_low = 0, walk_controls = 0, z_low = 0;
	uint16_t joystick = 0, player_z = 0, spark_height = 0, teammate = 0, voice_command = 0, walk_velocities = 0;
	uint16_t saved_walk_velocities = 0;
	uint8_t controls_pressed = 0, partner_pressed = 0, team_move_number = 0, kind = 0, animation_entry = 0, kind_2 = 0, team_move_number_2 = 0, team_move_number_3 = 0, kind_3 = 0, team_move_number_4 = 0, controls = 0, partner_joystick = 0, controls_2 = 0, own_joystick = 0, team_move_number_5 = 0, animation_flags = 0, team_move_number_6 = 0, voice_timer = 0, controls_pressed_2 = 0, controls_pressed_3 = 0, blow_landed = 0, team_direction = 0, controls_pressed_4 = 0, controls_pressed_5 = 0, controls_3 = 0, team_direction_2 = 0, active_controls = 0, controls_4 = 0, controls_5 = 0, controls_6 = 0;
	uint16_t partner = 0, z = 0, floor_z = 0, partner_2 = 0, action = 0, z_2 = 0, floor_z_2 = 0;
	uint32_t action_halfword = 0;

	partner = OBJECT(player)->player.partner;
	teammate = partner;
	z = OBJECT(player)->z;
	z_low = (uint8_t)z;
	floor_z = OBJECT(player)->floor_z;
	if ((int16_t)(((uint32_t)(z >> 8) << 8) | z_low) <= (int16_t)floor_z)
	{
		controls_pressed = OBJECT(player)->player.controls_pressed;
		partner_pressed = OBJECT(teammate)->player.controls_pressed;
		pressed_either = controls_pressed | partner_pressed;
		do
		{
			do
			{
				do
				{
					if (L_039205 || L_0391EB || L_0386E1 || (pressed_either & 0x20u) != 0u)
					{
						do
						{
							if (L_0391EB || !L_039205)
							{
								if (L_0391EB || L_0391EB || !L_0386E1)
								{
									if (!L_0391EB)
									{
										if (!L_0391EB)
										{
											OBJECT(player)->z_speed = 0x780;
											player_set_in_air(player);
											OBJECT(player)->player.state_frames = 1u;
											OBJECT(player)->player.player_state = 0x33u;
											OBJECT(player)->player.state_timer = 0u;
											OBJECT(player)->timer = 0x33u;
											animation_base = 0xF0u;
										}
									}
									L_0391EB = false;
									team_animation_base = animation_base;
									walk_velocities = team_move_animation_offsets_ADDRESS;
									team_move_number = OBJECT(player)->player.team_move_number;
									kind = OBJECT(player)->kind;
									animation_entry = team_move_animation_offsets[(int8_t)((uint8_t)((((uint32_t)team_move_number << 1) << 1) + kind))];
									animation_offset = animation_entry;
								}
							}
							for (;;)
							{
								if (L_039205 || L_039205 || L_0386E1 || (int8_t)animation_entry < 0)
								{
									if (L_039205 || L_039205 || !L_0386E1)
									{
										L_039205 = false;
										partner_2 = OBJECT(player)->player.partner;
										teammate = partner_2;
										player_team_follow(teammate, player);
										kind_2 = OBJECT(teammate)->kind;
										owner_kind = kind_2;
									}
									for (;;)
									{
										if (L_039216 || L_0386E1 || (int8_t)random_number >= 0)
										{
											if (L_039216 || !L_0386E1)
											{
												L_039216 = false;
												OBJECT(player)->shadow_player = ((((uint32_t)owner_kind << 1) << 1) << 1) << 1;
												action = (((uint32_t)OBJECT(player)->action << 8u) | OBJECT(player)->action_step);
												action_halfword = action - 1u;
												OBJECT(player)->action = (uint8_t)(action_halfword >> 8u);
												OBJECT(player)->action_step = (uint8_t)action_halfword;
												if (action != 1u)
												{
													player_take_touches(walk_velocities, player);
													return;
												}
												team_move_number_2 = OBJECT(player)->player.team_move_number;
											}
											if (L_0386E1 || team_move_number_2 == 2u)
											{
												L_0386E1 = false;
												team_move_number_3 = OBJECT(player)->player.team_move_number;
												attack_state = team_move_attack_states[(int8_t)team_move_number_3];
												OBJECT(player)->player.attack_started = attack_state;
												OBJECT(player)->damage = 0xCu;
												OBJECT(player)->attack = 0x13u;
												z_2 = OBJECT(player)->z;
												player_z = z_2;
												floor_z_2 = OBJECT(player)->floor_z;
												if ((int16_t)floor_z_2 < (int16_t)player_z)
												{
													player_start_jump_attack(player_z, player);
													animation_base = 0xFCu;
												}
												else
												{
													OBJECT(player)->x_speed = 0;
													OBJECT(player)->y_speed = 0;
													animation_base = 0xF8u;
												}
												OBJECT(player)->player.player_state = attack_state;
												L_0391EB = true;
											}
											if (!L_0391EB)
											{
												player_team_split(teammate, player);
												OBJECT(teammate)->flags = 0xC0u;
												OBJECT(player)->x_speed = 0;
												OBJECT(teammate)->x_speed = 0;
												OBJECT(player)->y_speed = 0;
												OBJECT(teammate)->y_speed = 0;
												player_take_touches(walk_velocities, player);
												return;
											}
										}
										if (L_0391EB)
											break;
										kind_3 = OBJECT(player)->kind;
										owner_kind = kind_3;
										L_039216 = true;
									}
								}
								if (L_0391EB)
									break;
								OBJECT(player)->animation = animation_offset + team_animation_base;
								L_039205 = true;
							}
						} while (L_0391EB);
					}
					OBJECT(player)->damage = 0u;
					OBJECT(player)->attack = 0u;
					walk_velocities = player_walk_velocities_ADDRESS;
					do
					{
						if (L_0384D1 || (pressed_either & 0x10u) == 0u)
						{
							if (!L_0384D1)
								team_move_number_4 = OBJECT(player)->player.team_move_number;
							if (L_0384D1 || (int8_t)team_move_number_4 >= 2)
							{
								if (!L_0384D1)
								{
									controls = OBJECT(teammate)->player.controls;
									partner_joystick = controls & 0xFu;
									joystick_bits = partner_joystick;
									if (partner_joystick != 0u)
									{
										joystick = (uint32_t)joystick_bits << 8;
										player_walk(walk_velocities, player, joystick);
										return;
									}
									controls_2 = OBJECT(player)->player.controls;
									own_joystick = controls_2 & 0xFu;
									joystick_bits = own_joystick;
									if (own_joystick != 0u)
									{
										joystick = (uint32_t)joystick_bits << 8;
										player_walk(walk_velocities, player, joystick);
										return;
									}
								}
								L_0384D1 = false;
								OBJECT(player)->player.state_frames = 1u;
								OBJECT(player)->x_speed = 0;
								OBJECT(player)->y_speed = 0;
								team_move_number_5 = OBJECT(player)->player.team_move_number;
								if (team_move_number_5 == 0u)
								{
									animation_flags = OBJECT(player)->animation_flags;
									OBJECT(player)->animation_flags = animation_flags | 0x40u;
									L_039205 = true;
								}
								if (!L_039205)
								{
									animation_base = 0xE8u;
									L_0391EB = true;
								}
							}
						}
						else
						{
							team_move_number_6 = OBJECT(player)->player.team_move_number;
							move_number = team_move_number_6;
							L_0386E1 = (int8_t)move_number >= 2;
							if (!L_0386E1)
							{
								L_038314 = move_number != 1u;
								if (!L_038314)
								{
									voice_timer = OBJECT(player)->player.voice_timer;
									OBJECT(player)->player.voice_timer = voice_timer - 1u;
									L_038314 = voice_timer != 1u;
									if (!L_038314)
									{
										OBJECT(player)->player.voice_timer = 3u;
										controls_pressed_2 = OBJECT(player)->player.controls_pressed;
										if ((controls_pressed_2 & 0x10u) != 0u)
										{
											voice_high = 0x3Fu;
											voice_low = 0x2Au;
											L_038311 = true;
										}
										else
										{
											controls_pressed_3 = OBJECT(teammate)->player.controls_pressed;
											L_038314 = (controls_pressed_3 & 0x10u) == 0u;
											if (!L_038314)
											{
												voice_high = 0x3Fu;
												voice_low = 0x2Bu;
												L_038311 = true;
											}
										}
										if (!L_038314)
										{
											if (L_038311)
											{
												L_038311 = false;
												voice_command = ((uint32_t)voice_high << 8) | voice_low;
												vector_queue_sound(voice_command);
											}
										}
									}
								}
								z_low = 0x13u;
								OBJECT(player)->damage = 4u;
								OBJECT(player)->attack = 0x13u;
								walk_velocities = team_walk_velocities_ADDRESS;
							}
						}
						if (L_039205)
							break;
						if (L_0391EB)
							break;
						if (L_0386E1)
							break;
						if ((frame_count & 0xFu) == 0u)
						{
							z_low = 0x11u;
							OBJECT(player)->damage = 4u;
							OBJECT(player)->attack = 0x11u;
						}
						blow_landed = OBJECT(player)->player.blow_landed;
						if (blow_landed != 0u)
						{
							saved_walk_velocities = walk_velocities;
							spark_height = hit_spark_height_ADDRESS;
							voice_command = z_low;
							player_show_hit_spark(spark_height, player);
							walk_velocities = saved_walk_velocities;
						}
						team_direction = OBJECT(player)->player.team_direction;
						for (;;)
						{
							if (L_03836A || (int8_t)team_direction >= 0)
							{
								if (!L_03836A)
								{
									controls_pressed_4 = OBJECT(player)->player.controls_pressed;
									controls_pressed_5 = OBJECT(teammate)->player.controls_pressed;
									team_attack_pressed = (controls_pressed_4 | controls_pressed_5) & 0x10u;
									controls_3 = OBJECT(player)->player.controls;
									walk_controls = controls_3;
									team_direction_2 = OBJECT(player)->player.team_direction;
								}
								for (;;)
								{
									if (L_038365 || L_03836A || team_direction_2 != 0u)
									{
										if (L_038365 || !L_03836A)
										{
											L_038365 = false;
											walk_controls = (walk_controls & 0xEFu) | team_attack_pressed;
										}
										L_03836A = false;
										active_controls = walk_controls & 0x1Fu;
										walk_controls = active_controls;
										if (active_controls != 0u)
										{
											joystick = (voice_command & 0xFFu) | ((walk_controls & 0xFu) << 8);
											player_walk(walk_velocities, player, joystick);
											return;
										}
										L_0384D1 = true;
									}
									if (L_0384D1)
										break;
									controls_4 = OBJECT(teammate)->player.controls;
									walk_controls = controls_4;
									L_038365 = true;
								}
							}
							if (L_0384D1)
								break;
							controls_5 = OBJECT(player)->player.controls;
							controls_6 = OBJECT(teammate)->player.controls;
							walk_controls = controls_5 | controls_6;
							L_03836A = true;
						}
					} while (L_0384D1);
				} while (L_039205);
			} while (L_0391EB);
		} while (L_0386E1);
	}
	player_set_in_air(player);
	OBJECT(player)->z_speed = 0x600;
	player_team_start_fall(player);
}

/* The player standing: jumps, attacks, picks up or uses what it touches, walks by its joystick, gets
   bored after 160 idle frames and, after 32 still frames, offers a team move to a player that touches
   it. */
void player_stand(uint16_t y, uint16_t player)
{
	uint32_t effect_busy = 0;
	uint8_t base_animation = 0, held = 0, joystick_bits = 0, joystick_x = 0, pressed = 0, state_frames = 0, touched_by = 0;
	uint16_t animation = 0, balloon_value = 0, carry_offsets = 0, command = 0, effect_state = 0, held_2 = 0, joystick = 0, kind = 0, move_and_animation = 0, picked_up = 0, velocities = 0, weapon_effect = 0, x_speed = 0;
	uint8_t effect_low_or_shadow_bits = 0, weapon_effect_kind = 0;
	uint8_t controls_pressed = 0, controls_pressed_2 = 0, controls = 0, jump_joystick_x = 0, held_high = 0, held_weapon = 0, attributes = 0, hit = 0, controls_2 = 0, facing_joystick_x = 0, attack = 0, carrier_kind = 0, kind_2 = 0, kind_3 = 0, shadow_player = 0, shadow_player_2 = 0, frames_since_press = 0, quick_presses = 0, quick_presses_2 = 0, controls_3 = 0, walk_joystick = 0, idle_players = 0, state_frames_2 = 0, teamed = 0, teamed_2 = 0, kind_4 = 0, state_frames_3 = 0;
	uint16_t z = 0, floor_z = 0, held_3 = 0, held_4 = 0, hit_by = 0, hit_by_2 = 0, held_5 = 0;

	z = OBJECT(player)->z;
	floor_z = OBJECT(player)->floor_z;
	if ((int16_t)floor_z < (int16_t)z)
	{
		OBJECT(player)->player.player_state = 3u;
		player_set_in_air(player);
		OBJECT(player)->z_speed = 0x600;
		OBJECT(player)->player.state_frames = 1u;
		player_fall(player);
		return;
	}
	controls_pressed = OBJECT(player)->player.controls_pressed;
	pressed = controls_pressed;
	if ((pressed & 0x20u) != 0u)
	{
		controls_pressed_2 = OBJECT(player)->player.controls_pressed;
		if (controls_pressed_2 != 0x30u)
		{
			player_set_in_air(player);
			OBJECT(player)->player.state_frames = 1u;
			OBJECT(player)->player.teamed = 0u;
			player_reset_box(player);
			OBJECT(player)->player.player_state = 2u;
			OBJECT(player)->player.state_timer = 0u;
			OBJECT(player)->timer = 2u;
			OBJECT(player)->z_speed = 0x780;
			player_jump(player);
			return;
		}
		held_3 = OBJECT(player)->player.held;
		if (held_3 == 0u)
		{
			OBJECT(player)->z_speed = 0x600;
			command = 0x3F20u;
			player_play_voice(player, command);
			player_set_in_air(player);
			controls = OBJECT(player)->player.controls;
			jump_joystick_x = controls & 3u;
			joystick_x = jump_joystick_x;
			if (jump_joystick_x == 0u)
			{
				animation = 0xDB9u;
				player_set_move_stopped(y, player, animation);
				return;
			}
			x_speed = 0xC0u;
			if ((joystick_x & 1u) != 0u)
				x_speed = 0xFF40u;
			OBJECT(player)->x_speed = x_speed;
			animation = 0xDB9u;
			player_set_move_stopped(y, player, animation);
			return;
		}
		held_high = (uint8_t)(OBJECT(player)->player.held >> 8u);
		if (held_high != 0u)
		{
			player_set_in_air(player);
			OBJECT(player)->player.state_frames = 1u;
			OBJECT(player)->player.teamed = 0u;
			player_reset_box(player);
			OBJECT(player)->player.player_state = 2u;
			OBJECT(player)->player.state_timer = 0u;
			OBJECT(player)->timer = 2u;
			OBJECT(player)->z_speed = 0x780;
			player_jump(player);
			return;
		}
		held_weapon = (uint8_t)OBJECT(player)->player.held;
		effect_low_or_shadow_bits = 0x80u;
		weapon_effect_kind = held_weapon;
		weapon_effect = ((uint32_t)weapon_effect_kind << 8) | effect_low_or_shadow_bits;
		effect_state = 0xA00u;
		effect_busy = player_start_effect(weapon_effect, player, effect_state);
		if (effect_busy == 0u)
		{
			OBJECT(player)->player.held = 0u;
			move_and_animation = 0x2BB1u;
			player_set_move_on_floor(weapon_effect, player, move_and_animation);
			return;
		}
		player_set_in_air(player);
		OBJECT(player)->player.state_frames = 1u;
		OBJECT(player)->player.teamed = 0u;
		player_reset_box(player);
		OBJECT(player)->player.player_state = 2u;
		OBJECT(player)->player.state_timer = 0u;
		OBJECT(player)->timer = 2u;
		OBJECT(player)->z_speed = 0x780;
		player_jump(player);
		return;
	}
	if ((pressed & 0x10u) != 0u)
	{
		OBJECT(player)->x_speed = 0;
		attributes = OBJECT(player)->attributes;
		OBJECT(player)->player.attack_facing = attributes & 0x40u;
		held_4 = OBJECT(player)->player.held;
		held_2 = held_4;
		if (held_4 != 0u)
		{
			player_use_held(held_2, player);
			return;
		}
		hit = OBJECT(player)->hit;
		touched_by = hit;
		if (touched_by == 0xFEu)
		{
			OBJECT(player)->damage = 0u;
			OBJECT(player)->attack = 0u;
			hit_by = OBJECT(player)->hit_by;
			OBJECT(player)->player.held = hit_by;
			base_animation = 0xC9u;
			player_face_heavy_object(player, base_animation);
			OBJECT(player)->player.player_state = 0x2Cu;
			player_keep_life(player);
			return;
		}
		controls_2 = OBJECT(player)->player.controls;
		facing_joystick_x = controls_2 & 3u;
		joystick_x = facing_joystick_x;
		if (facing_joystick_x != 0u)
		{
			OBJECT(player)->attributes = 0u;
			if ((joystick_x & 1u) != 0u)
				OBJECT(player)->attributes = 0x40u;
		}
		if (touched_by != 0xFFu)
		{
			player_start_attack(y, player);
			return;
		}
		OBJECT(player)->damage = 0u;
		OBJECT(player)->attack = 0u;
		hit_by_2 = OBJECT(player)->hit_by;
		picked_up = hit_by_2;
		attack = OBJECT(picked_up)->attack;
		if (attack != 0xFFu)
		{
			player_start_attack(y, player);
			return;
		}
		carrier_kind = OBJECT(picked_up)->throwable.carrier_kind;
		if (carrier_kind != 0u)
		{
			player_start_attack(y, player);
			return;
		}
		kind_2 = OBJECT(picked_up)->kind;
		held = kind_2;
		if ((int8_t)held > 5 && (int8_t)held < 9)
		{
			OBJECT(player)->player.held = held;
			command = 0x1800u;
			vector_queue_sound(command);
			OBJECT(player + 0x60u)->player.held = (OBJECT(player + 0x60u)->player.held & 0xFFu) | 0x1400u;
			OBJECT(player)->y_speed = 0;
			OBJECT(picked_up)->carried = 1u;
			OBJECT(picked_up)->parent = player;
			kind_3 = OBJECT(player)->kind;
			OBJECT(picked_up)->throwable.carrier_kind = kind_3 + 1u;
			OBJECT(picked_up)->state = 3u;
			carry_offsets = carry_offsets_picking_up_ADDRESS;
			carry_offsets = player_place_carried(picked_up, carry_offsets, player);
			animation = 0x2FBDu;
			player_set_move(carry_offsets, player, animation);
			return;
		}
		OBJECT(player)->player.held = picked_up;
		shadow_player = OBJECT(player)->shadow_player;
		effect_low_or_shadow_bits = shadow_player & 0x30u;
		shadow_player_2 = OBJECT(picked_up)->shadow_player;
		OBJECT(picked_up)->shadow_player = (shadow_player_2 & 0xCFu) | effect_low_or_shadow_bits;
		command = 0x1800u;
		vector_queue_sound(command);
		OBJECT(player + 0x60u)->player.held = (OBJECT(player + 0x60u)->player.held & 0xFFu) | 0x1400u;
		OBJECT(player)->y_speed = 0;
		OBJECT(picked_up)->carried = 1u;
		OBJECT(picked_up)->parent = player;
		kind_3 = OBJECT(player)->kind;
		OBJECT(picked_up)->throwable.carrier_kind = kind_3 + 1u;
		OBJECT(picked_up)->state = 3u;
		carry_offsets = carry_offsets_picking_up_ADDRESS;
		carry_offsets = player_place_carried(picked_up, carry_offsets, player);
		animation = 0x2FBDu;
		player_set_move(carry_offsets, player, animation);
		return;
	}
	if ((pressed & 0xFu) != 0u)
	{
		frames_since_press = OBJECT(player)->player.frames_since_press;
		if ((int8_t)frames_since_press <= 0xC)
		{
			quick_presses = OBJECT(player)->player.quick_presses;
			if (quick_presses < 4u)
			{
				quick_presses_2 = OBJECT(player)->player.quick_presses;
				OBJECT(player)->player.quick_presses = quick_presses_2 + 1u;
			}
		}
		OBJECT(player)->player.frames_since_press = 0u;
	}
	controls_3 = OBJECT(player)->player.controls;
	walk_joystick = controls_3 & 0xFu;
	joystick_bits = walk_joystick;
	if (walk_joystick != 0u)
	{
		velocities = player_walk_velocities_ADDRESS;
		joystick = (uint32_t)joystick_bits << 8;
		player_walk(velocities, player, joystick);
		return;
	}
	idle_players = io_read8(players_idle_count);
	io_write8(players_idle_count, idle_players + 1u);
	state_frames_2 = OBJECT(player)->player.state_frames;
	state_frames = state_frames_2;
	if (state_frames_2 != 0u)
	{
		state_frames++;
		if (state_frames == 0xA0u)
		{
			command = 0x3F10u;
			player_play_voice(player, command);
			balloon_value = 0x210u;
			player_show_balloon(y, player, balloon_value);
			OBJECT(player)->animation = 0xAFu;
			OBJECT(player)->player.state_frames = 1u;
			player_take_touches(y, player);
			return;
		}
		held_5 = OBJECT(player)->player.held;
		kind = held_5;
		if (held_5 != 0u)
		{
			player_take_touches(kind, player);
			return;
		}
		teamed = OBJECT(player)->player.teamed;
		if (teamed != 0x20u)
		{
			teamed_2 = OBJECT(player)->player.teamed;
			OBJECT(player)->player.teamed = teamed_2 + 1u;
		}
		else
		{
			kind_4 = OBJECT(player)->kind;
			OBJECT(player)->attack = kind_4 - 0x80u;
			OBJECT(player)->damage = 0u;
			OBJECT(player)->box_width = 0x10u;
			OBJECT(player)->box_depth = 8u;
		}
		OBJECT(player)->player.state_frames = state_frames;
		player_take_touches(kind, player);
		return;
	}
	state_frames_3 = OBJECT(player)->player.state_frames;
	OBJECT(player)->player.state_frames = state_frames_3 + 1u;
	OBJECT(player)->x_speed = 0;
	OBJECT(player)->y_speed = 0;
	carry_offsets = carry_offsets_still_ADDRESS;
	base_animation = 0x80u;
	player_set_animation(carry_offsets, player, base_animation);
}

/* Walks the player by its joystick: its x and y speeds from the velocities Y points at, its facing (and
   its partner's), the scroll request, and the walking animation, or the team's when teamed up. */
void player_walk(uint16_t velocities, uint16_t player, uint16_t joystick)
{
	uint8_t animation_base = 0, animation_offset = 0, attack_state = 0, base_animation = 0, owner_kind = 0, team_way = 0, walk_animation = 0, x_speed_high = 0;
	uint16_t carry_offsets = 0, player_z = 0, teammate = 0, velocity = 0;
	uint8_t attributes = 0, teamed = 0, attributes_2 = 0, state_frames = 0, teamed_2 = 0, controls = 0, team_direction = 0, controls_2 = 0, teamed_3 = 0, controls_3 = 0, kind = 0, kind_2 = 0, team_move_number = 0, team_move_number_2 = 0, team_move_number_3 = 0, kind_3 = 0, animation_entry = 0;
	uint16_t velocity_record = 0, x_speed = 0, walk_x_speed = 0, partner = 0, partner_2 = 0, partner_3 = 0, action = 0, z = 0, floor_z = 0;
	uint32_t action_halfword = 0;

	velocity_record = velocities + (uint8_t)(((uint32_t)(joystick >> 8) << 1) << 1);
	velocity = velocity_record + 2u;
	x_speed = VELOCITY(velocity_record)->x_speed;
	x_speed_high = (uint8_t)(x_speed >> 8);
	walk_x_speed = ((uint32_t)x_speed_high << 8) | (uint8_t)x_speed;
	OBJECT(player)->x_speed = walk_x_speed;
	if (walk_x_speed != 0u)
	{
		walk_facing = x_speed_high & 0x40u;
		attributes = OBJECT(player)->attributes;
		OBJECT(player)->attributes = (attributes & 0xBFu) | walk_facing;
		teamed = OBJECT(player)->player.teamed;
		if ((int8_t)teamed < 0)
		{
			partner = OBJECT(player)->player.partner;
			teammate = partner;
			attributes_2 = OBJECT(teammate)->attributes;
			OBJECT(teammate)->attributes = (attributes_2 & 0xBFu) | walk_facing;
		}
	}
	player_request_scroll(velocity, player);
	state_frames = OBJECT(player)->player.state_frames;
	if (state_frames != 0u)
	{
		teamed_2 = OBJECT(player)->player.teamed;
		if ((int8_t)teamed_2 >= 0)
		{
			OBJECT(player)->player.state_frames = 0u;
			OBJECT(player)->player.teamed = 0u;
			OBJECT(player)->player.status = 0u;
			player_reset_box(player);
			walk_animation = 0x81u;
			carry_offsets = carry_offsets_walking_ADDRESS;
			controls = OBJECT(player)->player.controls;
			if ((controls & 4u) == 0u)
			{
				base_animation = walk_animation;
				player_set_animation(carry_offsets, player, base_animation);
				return;
			}
			base_animation = (uint8_t)(walk_animation + 1u);
			player_set_animation(carry_offsets, player, base_animation);
			return;
		}
		partner_2 = OBJECT(player)->player.partner;
		teammate = partner_2;
		team_direction = OBJECT(player)->player.team_direction;
		if ((int8_t)team_direction >= 0)
		{
			OBJECT(player)->player.state_frames = 0u;
			player_team_together(player);
			return;
		}
		team_way = 1u;
		controls_2 = OBJECT(player)->player.controls;
		if ((controls_2 & 0x1Fu) == 0u)
		{
			OBJECT(player)->player.team_direction = 0u;
			OBJECT(teammate)->player.team_direction = team_way;
		}
		else
		{
			OBJECT(player)->player.team_direction = team_way;
			OBJECT(teammate)->player.team_direction = 0u;
		}
		OBJECT(player)->player.state_frames = 0u;
		player_team_together(player);
		return;
	}
	teamed_3 = OBJECT(player)->player.teamed;
	if ((int8_t)teamed_3 >= 0)
	{
		OBJECT(player)->player.teamed = 0u;
		player_reset_box(player);
		walk_animation = 1u;
		carry_offsets = carry_offsets_walking_ADDRESS;
		controls_3 = OBJECT(player)->player.controls;
		if ((controls_3 & 4u) == 0u)
		{
			base_animation = walk_animation;
			player_set_animation(carry_offsets, player, base_animation);
			return;
		}
		base_animation = (uint8_t)(walk_animation + 1u);
		player_set_animation(carry_offsets, player, base_animation);
		return;
	}
	for (;;)
	{
		partner_3 = OBJECT(player)->player.partner;
		teammate = partner_3;
		player_team_follow(teammate, player);
		kind = OBJECT(teammate)->kind;
		owner_kind = kind;
		if ((int8_t)random_number < 0)
		{
			kind_2 = OBJECT(player)->kind;
			owner_kind = kind_2;
		}
		OBJECT(player)->shadow_player = ((((uint32_t)owner_kind << 1) << 1) << 1) << 1;
		action = (((uint32_t)OBJECT(player)->action << 8u) | OBJECT(player)->action_step);
		action_halfword = action - 1u;
		OBJECT(player)->action = (uint8_t)(action_halfword >> 8u);
		OBJECT(player)->action_step = (uint8_t)action_halfword;
		if (action != 1u)
		{
			player_take_touches(velocity, player);
			return;
		}
		team_move_number = OBJECT(player)->player.team_move_number;
		if (team_move_number != 2u)
			break;
		team_move_number_2 = OBJECT(player)->player.team_move_number;
		attack_state = team_move_attack_states[(int8_t)team_move_number_2];
		OBJECT(player)->player.attack_started = attack_state;
		OBJECT(player)->damage = 0xCu;
		OBJECT(player)->attack = 0x13u;
		z = OBJECT(player)->z;
		player_z = z;
		floor_z = OBJECT(player)->floor_z;
		if ((int16_t)floor_z < (int16_t)player_z)
		{
			player_start_jump_attack(player_z, player);
			animation_base = 0xFCu;
		}
		else
		{
			OBJECT(player)->x_speed = 0;
			OBJECT(player)->y_speed = 0;
			animation_base = 0xF8u;
		}
		OBJECT(player)->player.player_state = attack_state;
		team_animation_base = animation_base;
		velocity = team_move_animation_offsets_ADDRESS;
		team_move_number_3 = OBJECT(player)->player.team_move_number;
		kind_3 = OBJECT(player)->kind;
		animation_entry = team_move_animation_offsets[(int8_t)((uint8_t)((((uint32_t)team_move_number_3 << 1) << 1) + kind_3))];
		animation_offset = animation_entry;
		if ((int8_t)animation_entry < 0)
			continue;
		OBJECT(player)->animation = animation_offset + team_animation_base;
	}
	player_team_split(teammate, player);
	OBJECT(teammate)->flags = 0xC0u;
	OBJECT(player)->x_speed = 0;
	OBJECT(teammate)->x_speed = 0;
	OBJECT(player)->y_speed = 0;
	OBJECT(teammate)->y_speed = 0;
	player_take_touches(velocity, player);
}

/* A team going up in its jump, steered by both joysticks; the jump goes higher while either holds jump;
   moves 2 and 3 can attack in the air. */
void player_team_jump(uint16_t player)
{
	bool L_038533 = false;
	uint8_t animation_base = 0, animation_offset = 0, attack_state = 0, owner_kind = 0;
	uint16_t joystick = 0, player_z = 0, teammate = 0, velocity = 0;
	uint8_t controls = 0, controls_2 = 0, attack_started = 0, team_move_number = 0, controls_pressed = 0, partner_pressed = 0, state_timer = 0, controls_3 = 0, controls_4 = 0, state_timer_2 = 0, kind = 0, kind_2 = 0, team_move_number_2 = 0, team_move_number_3 = 0, team_move_number_4 = 0, kind_3 = 0, animation_entry = 0;
	uint16_t partner = 0, z_speed = 0, new_z_speed = 0, slowed_z_speed = 0, partner_2 = 0, action = 0, z = 0, floor_z = 0;
	uint32_t action_halfword = 0, action_halfword_2 = 0;

	partner = OBJECT(player)->player.partner;
	teammate = partner;
	controls = OBJECT(player)->player.controls;
	controls_2 = OBJECT(teammate)->player.controls;
	joystick = (uint32_t)(controls | controls_2) << 8;
	velocity = player_steer(player, joystick);
	attack_started = OBJECT(player)->player.attack_started;
	L_038533 = attack_started != 0u;
	if (!L_038533)
	{
		team_move_number = OBJECT(player)->player.team_move_number;
		L_038533 = (int8_t)team_move_number < 2;
		if (!L_038533)
		{
			controls_pressed = OBJECT(player)->player.controls_pressed;
			partner_pressed = OBJECT(teammate)->player.controls_pressed;
			L_038533 = ((controls_pressed | partner_pressed) & 0x10u) == 0u;
		}
	}
	if (L_038533)
	{
		state_timer = OBJECT(player)->player.state_timer;
		OBJECT(player)->player.state_timer = state_timer + 1u;
		z_speed = OBJECT(player)->z_speed;
		new_z_speed = z_speed - 0x40u;
		slowed_z_speed = new_z_speed;
		OBJECT(player)->z_speed = slowed_z_speed;
		if ((int16_t)slowed_z_speed < 0)
		{
			player_team_start_fall(player);
			return;
		}
		controls_3 = OBJECT(player)->player.controls;
		controls_4 = OBJECT(teammate)->player.controls;
		if (((controls_3 | controls_4) & 0x20u) == 0u)
		{
			state_timer_2 = OBJECT(player)->player.state_timer;
			if ((int8_t)state_timer_2 > 3)
			{
				player_team_start_fall(player);
				return;
			}
		}
		partner_2 = OBJECT(player)->player.partner;
		teammate = partner_2;
		player_team_follow(teammate, player);
		kind = OBJECT(teammate)->kind;
		owner_kind = kind;
		if ((int8_t)random_number < 0)
		{
			kind_2 = OBJECT(player)->kind;
			owner_kind = kind_2;
		}
		OBJECT(player)->shadow_player = ((((uint32_t)owner_kind << 1) << 1) << 1) << 1;
		action = (((uint32_t)OBJECT(player)->action << 8u) | OBJECT(player)->action_step);
		action_halfword = action - 1u;
		OBJECT(player)->action = (uint8_t)(action_halfword >> 8u);
		OBJECT(player)->action_step = (uint8_t)action_halfword;
		if (action != 1u)
		{
			player_take_touches(velocity, player);
			return;
		}
		team_move_number_2 = OBJECT(player)->player.team_move_number;
		if (team_move_number_2 != 2u)
		{
			player_team_split(teammate, player);
			OBJECT(teammate)->flags = 0xC0u;
			OBJECT(player)->x_speed = 0;
			OBJECT(teammate)->x_speed = 0;
			OBJECT(player)->y_speed = 0;
			OBJECT(teammate)->y_speed = 0;
			player_take_touches(velocity, player);
			return;
		}
	}
	do
	{
		team_move_number_3 = OBJECT(player)->player.team_move_number;
		attack_state = team_move_attack_states[(int8_t)team_move_number_3];
		OBJECT(player)->player.attack_started = attack_state;
		OBJECT(player)->damage = 0xCu;
		OBJECT(player)->attack = 0x13u;
		z = OBJECT(player)->z;
		player_z = z;
		floor_z = OBJECT(player)->floor_z;
		if ((int16_t)floor_z < (int16_t)player_z)
		{
			player_start_jump_attack(player_z, player);
			animation_base = 0xFCu;
		}
		else
		{
			OBJECT(player)->x_speed = 0;
			OBJECT(player)->y_speed = 0;
			animation_base = 0xF8u;
		}
		OBJECT(player)->player.player_state = attack_state;
		team_animation_base = animation_base;
		velocity = team_move_animation_offsets_ADDRESS;
		team_move_number_4 = OBJECT(player)->player.team_move_number;
		kind_3 = OBJECT(player)->kind;
		animation_entry = team_move_animation_offsets[(int8_t)((uint8_t)((((uint32_t)team_move_number_4 << 1) << 1) + kind_3))];
		animation_offset = animation_entry;
		if ((int8_t)animation_entry >= 0)
			OBJECT(player)->animation = animation_offset + team_animation_base;
		partner_2 = OBJECT(player)->player.partner;
		teammate = partner_2;
		player_team_follow(teammate, player);
		kind = OBJECT(teammate)->kind;
		owner_kind = kind;
		if ((int8_t)random_number < 0)
		{
			kind_2 = OBJECT(player)->kind;
			owner_kind = kind_2;
		}
		OBJECT(player)->shadow_player = ((((uint32_t)owner_kind << 1) << 1) << 1) << 1;
		action = (((uint32_t)OBJECT(player)->action << 8u) | OBJECT(player)->action_step);
		action_halfword_2 = action - 1u;
		OBJECT(player)->action = (uint8_t)(action_halfword_2 >> 8u);
		OBJECT(player)->action_step = (uint8_t)action_halfword_2;
		if (action != 1u)
		{
			player_take_touches(velocity, player);
			return;
		}
		team_move_number_2 = OBJECT(player)->player.team_move_number;
	} while (team_move_number_2 == 2u);
	player_team_split(teammate, player);
	OBJECT(teammate)->flags = 0xC0u;
	OBJECT(player)->x_speed = 0;
	OBJECT(teammate)->x_speed = 0;
	OBJECT(player)->y_speed = 0;
	OBJECT(teammate)->y_speed = 0;
	player_take_touches(velocity, player);
}

/* Starts the team's fall (state 34) with its falling animation. */
void player_team_start_fall(uint16_t player)
{
	uint8_t animation_base = 0, animation_offset = 0, attack_state = 0, owner_kind = 0;
	uint16_t animation_offsets = 0, player_z = 0, teammate = 0;
	uint8_t team_move_number = 0, kind = 0, animation_entry = 0, kind_2 = 0, kind_3 = 0, team_move_number_2 = 0, team_move_number_3 = 0;
	uint16_t partner = 0, action = 0, z = 0, floor_z = 0;
	uint32_t action_halfword = 0;

	OBJECT(player)->player.player_state = 0x34u;
	animation_base = 0xF4u;
	for (;;)
	{
		team_animation_base = animation_base;
		animation_offsets = team_move_animation_offsets_ADDRESS;
		team_move_number = OBJECT(player)->player.team_move_number;
		kind = OBJECT(player)->kind;
		animation_entry = team_move_animation_offsets[(int8_t)((uint8_t)((((uint32_t)team_move_number << 1) << 1) + kind))];
		animation_offset = animation_entry;
		if ((int8_t)animation_entry >= 0)
			OBJECT(player)->animation = animation_offset + team_animation_base;
		partner = OBJECT(player)->player.partner;
		teammate = partner;
		player_team_follow(teammate, player);
		kind_2 = OBJECT(teammate)->kind;
		owner_kind = kind_2;
		if ((int8_t)random_number < 0)
		{
			kind_3 = OBJECT(player)->kind;
			owner_kind = kind_3;
		}
		OBJECT(player)->shadow_player = ((((uint32_t)owner_kind << 1) << 1) << 1) << 1;
		action = (((uint32_t)OBJECT(player)->action << 8u) | OBJECT(player)->action_step);
		action_halfword = action - 1u;
		OBJECT(player)->action = (uint8_t)(action_halfword >> 8u);
		OBJECT(player)->action_step = (uint8_t)action_halfword;
		if (action != 1u)
		{
			player_take_touches(animation_offsets, player);
			return;
		}
		team_move_number_2 = OBJECT(player)->player.team_move_number;
		if (team_move_number_2 != 2u)
			break;
		team_move_number_3 = OBJECT(player)->player.team_move_number;
		attack_state = team_move_attack_states[(int8_t)team_move_number_3];
		OBJECT(player)->player.attack_started = attack_state;
		OBJECT(player)->damage = 0xCu;
		OBJECT(player)->attack = 0x13u;
		z = OBJECT(player)->z;
		player_z = z;
		floor_z = OBJECT(player)->floor_z;
		if ((int16_t)floor_z < (int16_t)player_z)
		{
			player_start_jump_attack(player_z, player);
			animation_base = 0xFCu;
		}
		else
		{
			OBJECT(player)->x_speed = 0;
			OBJECT(player)->y_speed = 0;
			animation_base = 0xF8u;
		}
		OBJECT(player)->player.player_state = attack_state;
	}
	player_team_split(teammate, player);
	OBJECT(teammate)->flags = 0xC0u;
	OBJECT(player)->x_speed = 0;
	OBJECT(teammate)->x_speed = 0;
	OBJECT(player)->y_speed = 0;
	OBJECT(teammate)->y_speed = 0;
	player_take_touches(animation_offsets, player);
}

/* A team falling: lands both on the floor, back to moving together; a team Marge leads bounces first. */
void player_team_fall(uint16_t player)
{
	bool L_038583 = false;
	uint32_t at_floor = 0, below_floor = 0, compare_overflow = 0;
	uint8_t animation_base = 0, animation_offset = 0, attack_state = 0, owner_kind = 0, z_speed_high = 0, z_speed_low = 0;
	uint16_t joystick = 0, player_z = 0, teammate = 0, velocity = 0, z = 0;
	uint8_t controls = 0, controls_2 = 0, attack_started = 0, team_move_number = 0, controls_pressed = 0, partner_pressed = 0, kind = 0, kind_2 = 0, kind_3 = 0, team_move_number_2 = 0, team_move_number_3 = 0, team_move_number_4 = 0, kind_4 = 0, animation_entry = 0;
	uint16_t partner = 0, floor_z = 0, z_speed = 0, bounce_z_speed = 0, bounce_up_speed = 0, z_speed_2 = 0, new_z_speed = 0, faster_z_speed = 0, partner_2 = 0, action = 0, z_2 = 0, floor_z_2 = 0;
	uint32_t action_halfword = 0, action_halfword_2 = 0;

	partner = OBJECT(player)->player.partner;
	teammate = partner;
	controls = OBJECT(player)->player.controls;
	controls_2 = OBJECT(teammate)->player.controls;
	joystick = (uint32_t)(controls | controls_2) << 8;
	velocity = player_steer(player, joystick);
	attack_started = OBJECT(player)->player.attack_started;
	L_038583 = attack_started != 0u;
	if (!L_038583)
	{
		team_move_number = OBJECT(player)->player.team_move_number;
		L_038583 = (int8_t)team_move_number < 2;
		if (!L_038583)
		{
			controls_pressed = OBJECT(player)->player.controls_pressed;
			partner_pressed = OBJECT(teammate)->player.controls_pressed;
			L_038583 = ((controls_pressed | partner_pressed) & 0x10u) == 0u;
		}
	}
	if (L_038583)
	{
		player_next_height_against_floor(player, &at_floor, &below_floor, &compare_overflow);
		if ((below_floor ^ compare_overflow) | at_floor)
		{
			OBJECT(player)->x_speed = 0;
			OBJECT(player)->y_speed = 0;
			floor_z = OBJECT(player)->floor_z;
			z = floor_z;
			OBJECT(player)->z = z;
			OBJECT(teammate)->z = z;
			OBJECT(player)->z_fraction = 0u;
			OBJECT(teammate)->z_fraction = 0u;
			kind = OBJECT(player)->kind;
			if (kind == 0u)
			{
				z_speed = OBJECT(player)->z_speed;
				bounce_z_speed = (int16_t)z_speed >> 1;
				z_speed_high = (uint8_t)(bounce_z_speed >> 8);
				z_speed_low = (uint8_t)bounce_z_speed;
				if ((int8_t)z_speed_high >= -4)
				{
					OBJECT(player)->z_speed = 0;
					player_team_resume(player);
					return;
				}
				bounce_up_speed = 0u - (((uint32_t)z_speed_high << 8) | z_speed_low);
				z_speed_high = (uint8_t)(bounce_up_speed >> 8);
				OBJECT(player)->z_speed = ((uint32_t)z_speed_high << 8) | (uint8_t)bounce_up_speed;
				OBJECT(player)->z = z + (int8_t)(0u - z_speed_high);
				player_team_start_fall(player);
				return;
			}
			player_set_on_floor(player);
			OBJECT(player)->z_speed = 0;
			player_team_resume(player);
			return;
		}
		z_speed_2 = OBJECT(player)->z_speed;
		new_z_speed = z_speed_2 - 0x40u;
		z_speed_high = (uint8_t)(new_z_speed >> 8);
		z_speed_low = (uint8_t)new_z_speed;
		if ((int16_t)(((uint32_t)z_speed_high << 8) | z_speed_low) > -0x300)
		{
			faster_z_speed = (((uint32_t)z_speed_high << 8) | z_speed_low) - 0x80u;
			z_speed_high = (uint8_t)(faster_z_speed >> 8);
			z_speed_low = (uint8_t)faster_z_speed;
		}
		OBJECT(player)->z_speed = ((uint32_t)z_speed_high << 8) | z_speed_low;
		partner_2 = OBJECT(player)->player.partner;
		teammate = partner_2;
		player_team_follow(teammate, player);
		kind_2 = OBJECT(teammate)->kind;
		owner_kind = kind_2;
		if ((int8_t)random_number < 0)
		{
			kind_3 = OBJECT(player)->kind;
			owner_kind = kind_3;
		}
		OBJECT(player)->shadow_player = ((((uint32_t)owner_kind << 1) << 1) << 1) << 1;
		action = (((uint32_t)OBJECT(player)->action << 8u) | OBJECT(player)->action_step);
		action_halfword = action - 1u;
		OBJECT(player)->action = (uint8_t)(action_halfword >> 8u);
		OBJECT(player)->action_step = (uint8_t)action_halfword;
		if (action != 1u)
		{
			player_take_touches(velocity, player);
			return;
		}
		team_move_number_2 = OBJECT(player)->player.team_move_number;
		if (team_move_number_2 != 2u)
		{
			player_team_split(teammate, player);
			OBJECT(teammate)->flags = 0xC0u;
			OBJECT(player)->x_speed = 0;
			OBJECT(teammate)->x_speed = 0;
			OBJECT(player)->y_speed = 0;
			OBJECT(teammate)->y_speed = 0;
			player_take_touches(velocity, player);
			return;
		}
	}
	do
	{
		team_move_number_3 = OBJECT(player)->player.team_move_number;
		attack_state = team_move_attack_states[(int8_t)team_move_number_3];
		OBJECT(player)->player.attack_started = attack_state;
		OBJECT(player)->damage = 0xCu;
		OBJECT(player)->attack = 0x13u;
		z_2 = OBJECT(player)->z;
		player_z = z_2;
		floor_z_2 = OBJECT(player)->floor_z;
		if ((int16_t)floor_z_2 < (int16_t)player_z)
		{
			player_start_jump_attack(player_z, player);
			animation_base = 0xFCu;
		}
		else
		{
			OBJECT(player)->x_speed = 0;
			OBJECT(player)->y_speed = 0;
			animation_base = 0xF8u;
		}
		OBJECT(player)->player.player_state = attack_state;
		team_animation_base = animation_base;
		velocity = team_move_animation_offsets_ADDRESS;
		team_move_number_4 = OBJECT(player)->player.team_move_number;
		kind_4 = OBJECT(player)->kind;
		animation_entry = team_move_animation_offsets[(int8_t)((uint8_t)((((uint32_t)team_move_number_4 << 1) << 1) + kind_4))];
		animation_offset = animation_entry;
		if ((int8_t)animation_entry >= 0)
			OBJECT(player)->animation = animation_offset + team_animation_base;
		partner_2 = OBJECT(player)->player.partner;
		teammate = partner_2;
		player_team_follow(teammate, player);
		kind_2 = OBJECT(teammate)->kind;
		owner_kind = kind_2;
		if ((int8_t)random_number < 0)
		{
			kind_3 = OBJECT(player)->kind;
			owner_kind = kind_3;
		}
		OBJECT(player)->shadow_player = ((((uint32_t)owner_kind << 1) << 1) << 1) << 1;
		action = (((uint32_t)OBJECT(player)->action << 8u) | OBJECT(player)->action_step);
		action_halfword_2 = action - 1u;
		OBJECT(player)->action = (uint8_t)(action_halfword_2 >> 8u);
		OBJECT(player)->action_step = (uint8_t)action_halfword_2;
		if (action != 1u)
		{
			player_take_touches(velocity, player);
			return;
		}
		team_move_number_2 = OBJECT(player)->player.team_move_number;
	} while (team_move_number_2 == 2u);
	player_team_split(teammate, player);
	OBJECT(teammate)->flags = 0xC0u;
	OBJECT(player)->x_speed = 0;
	OBJECT(teammate)->x_speed = 0;
	OBJECT(player)->y_speed = 0;
	OBJECT(teammate)->y_speed = 0;
	player_take_touches(velocity, player);
}

/* Throwing its weapon away (both buttons with a weapon in hand): sound 19 at the throw, back to standing
   when the animation ends. */
void player_throw_weapon_away(uint16_t kind, uint16_t player)
{
	uint8_t frame_flags = 0;
	uint16_t command = 0;
	uint8_t animation_flags = 0;

	animation_flags = OBJECT(player)->animation_flags;
	frame_flags = animation_flags;
	if ((frame_flags & 2u) == 0u)
	{
		if ((frame_flags & 1u) == 0u)
		{
			player_take_touches(kind, player);
			return;
		}
		player_end_state(kind, player);
		return;
	}
	command = 0x1900u;
	vector_queue_sound(command);
	player_take_touches(kind, player);
}

/* The player going up in its jump, steered by its joystick: higher while jump is held, an attack once 24
   above the floor, the fall once it stops rising. */
void player_jump(uint16_t player)
{
	uint8_t base_animation = 0, jump_animation = 0;
	uint16_t carry_offsets = 0, joystick = 0, velocity = 0;
	uint8_t controls = 0, attack_started = 0, controls_pressed = 0, state_timer = 0, controls_2 = 0, state_timer_2 = 0;
	uint16_t z = 0, floor_z = 0, height_above_floor = 0, z_speed = 0, new_z_speed = 0, slowed_z_speed = 0, z_speed_2 = 0;

	controls = OBJECT(player)->player.controls;
	joystick = (uint32_t)controls << 8;
	velocity = player_steer(player, joystick);
	attack_started = OBJECT(player)->player.attack_started;
	if (attack_started == 0u)
	{
		z = OBJECT(player)->z;
		floor_z = OBJECT(player)->floor_z;
		height_above_floor = z - floor_z;
		if ((int16_t)height_above_floor > 0x18)
		{
			controls_pressed = OBJECT(player)->player.controls_pressed;
			if ((controls_pressed & 0x10u) != 0u)
			{
				player_attack_in_air(velocity, player);
				return;
			}
		}
	}
	state_timer = OBJECT(player)->player.state_timer;
	OBJECT(player)->player.state_timer = state_timer + 1u;
	z_speed = OBJECT(player)->z_speed;
	new_z_speed = z_speed - 0x40u;
	slowed_z_speed = new_z_speed;
	OBJECT(player)->z_speed = slowed_z_speed;
	if ((int16_t)slowed_z_speed < 0)
	{
		player_start_fall(velocity, player);
		return;
	}
	controls_2 = OBJECT(player)->player.controls;
	if ((controls_2 & 0x20u) != 0u)
	{
		jump_animation = 0x83u;
		carry_offsets = carry_offsets_still_ADDRESS;
		z_speed_2 = OBJECT(player)->z_speed;
		if ((int16_t)z_speed_2 > 0x480)
		{
			base_animation = jump_animation;
			player_set_animation(carry_offsets, player, base_animation);
			return;
		}
		base_animation = (uint8_t)(jump_animation + 1u);
		player_set_animation(carry_offsets, player, base_animation);
		return;
	}
	state_timer_2 = OBJECT(player)->player.state_timer;
	if ((int8_t)state_timer_2 > 3)
	{
		player_start_fall(velocity, player);
		return;
	}
	jump_animation = 0x83u;
	carry_offsets = carry_offsets_still_ADDRESS;
	z_speed_2 = OBJECT(player)->z_speed;
	if ((int16_t)z_speed_2 > 0x480)
	{
		base_animation = jump_animation;
		player_set_animation(carry_offsets, player, base_animation);
		return;
	}
	base_animation = (uint8_t)(jump_animation + 1u);
	player_set_animation(carry_offsets, player, base_animation);
}

/* Puts the player in its falling state (03). */
void player_start_fall(uint16_t kind, uint16_t player)
{
	OBJECT(player)->player.player_state = 3u;
	player_take_touches(kind, player);
}

/* The player falling, steered by its joystick and able to attack, until it lands. */
void player_fall(uint16_t player)
{
	uint32_t at_floor = 0, below_floor = 0, compare_overflow = 0;
	uint8_t base_animation = 0, z_speed_high = 0, z_speed_low = 0;
	uint16_t carry_offsets = 0, joystick = 0, velocity = 0;
	uint8_t controls = 0, attack_started = 0, controls_pressed = 0;
	uint16_t z_speed = 0, new_z_speed = 0, faster_z_speed = 0;

	controls = OBJECT(player)->player.controls;
	joystick = (uint32_t)controls << 8;
	velocity = player_steer(player, joystick);
	attack_started = OBJECT(player)->player.attack_started;
	if (attack_started == 0u)
	{
		controls_pressed = OBJECT(player)->player.controls_pressed;
		if ((controls_pressed & 0x10u) != 0u)
		{
			player_attack_in_air(velocity, player);
			return;
		}
	}
	player_next_height_against_floor(player, &at_floor, &below_floor, &compare_overflow);
	if ((below_floor ^ compare_overflow) | at_floor)
	{
		player_land(player);
		return;
	}
	z_speed = OBJECT(player)->z_speed;
	new_z_speed = z_speed - 0x40u;
	z_speed_high = (uint8_t)(new_z_speed >> 8);
	z_speed_low = (uint8_t)new_z_speed;
	if ((int16_t)new_z_speed >= 0)
	{
		faster_z_speed = (((uint32_t)z_speed_high << 8) | z_speed_low) - 0x80u;
		z_speed_high = (uint8_t)(faster_z_speed >> 8);
		z_speed_low = (uint8_t)faster_z_speed;
	}
	OBJECT(player)->z_speed = ((uint32_t)z_speed_high << 8) | z_speed_low;
	carry_offsets = carry_offsets_still_ADDRESS;
	base_animation = 0x85u;
	player_set_animation(carry_offsets, player, base_animation);
}

/* Puts the player on the floor at a stop and standing. */
void player_land(uint16_t player)
{
	uint16_t floor_z = 0;

	player_set_on_floor(player);
	floor_z = OBJECT(player)->floor_z;
	OBJECT(player)->z = floor_z;
	OBJECT(player)->z_fraction = 0u;
	OBJECT(player)->z_speed = 0;
	OBJECT(player)->x_speed = 0;
	player_set_standing(player);
}

/* Stops the player's y speed and sets it standing (state 00, animation 80 by what it holds). */
void player_set_standing(uint16_t player)
{
	uint8_t base_animation = 0;
	uint16_t carry_offsets = 0;

	OBJECT(player)->y_speed = 0;
	OBJECT(player)->timer = 0u;
	OBJECT(player)->player.attack_started = 0u;
	OBJECT(player)->player.state_frames = 1u;
	OBJECT(player)->player.teamed = 0u;
	OBJECT(player)->player.player_state = 0u;
	carry_offsets = carry_offsets_walking_ADDRESS;
	base_animation = 0x80u;
	player_set_animation(carry_offsets, player, base_animation);
}

/* Attack pressed in a jump or fall: uses what the player holds, or starts an attack. */
void player_attack_in_air(uint16_t kind, uint16_t player)
{
	uint16_t held = 0;
	uint8_t attributes = 0;
	uint16_t held_2 = 0;

	attributes = OBJECT(player)->attributes;
	OBJECT(player)->player.attack_facing = attributes & 0x40u;
	held_2 = OBJECT(player)->player.held;
	held = held_2;
	if (held_2 == 0u)
	{
		player_start_attack(kind, player);
		return;
	}
	player_use_held(held, player);
}

/* Uses what the player holds by its kind (4-8): throws a carried object, swings or throws a weapon. */
void player_use_held(uint16_t held, uint16_t player)
{
	uint8_t held_kind = 0, use_index = 0, use_index_2 = 0;
	uint16_t use_handlers = 0;
	uint8_t weapon_kind = 0, held_high = 0, carried_kind = 0;

	OBJECT(player)->player.attack_gravity = 0x40u;
	weapon_kind = (uint8_t)OBJECT(player)->player.held;
	held_kind = weapon_kind;
	held_high = (uint8_t)(OBJECT(player)->player.held >> 8u);
	if (held_high != 0u)
	{
		carried_kind = OBJECT(held)->kind;
		held_kind = carried_kind;
	}
	held_kind -= 4u;
	use_index = held_kind;
	use_handlers = player_use_held_by_kind_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)held_kind << 1))
	{
	case 0:
		use_index_2 = use_index;
		player_start_throw_kind_4(held, use_handlers, player, use_index_2);
		return;
	case 2:
		use_index_2 = use_index;
		player_start_throw(use_handlers, player, use_index_2);
		return;
	case 4:
		use_index_2 = use_index;
		player_start_swing_6(player, use_index_2);
		return;
	case 6:
		use_index_2 = use_index;
		player_start_swing(player, use_index_2);
		return;
	case 8:
		player_start_throw_weapon_8(use_handlers, player);
		return;
	}
}

/* Starts throwing a carried kind-4 object (state 04), with Homer's own animation E0 for the kind-04
   object showing animation 1A. */
void player_start_throw_kind_4(uint16_t held, uint16_t y, uint16_t player, uint8_t use_index_2)
{
	uint8_t use_index = 0, use_index_3 = 0;
	uint16_t move_and_animation = 0;
	uint8_t saved_use_index = 0;
	uint8_t kind = 0;
	uint16_t held_look = 0, masked_look = 0;

	use_index = (uint8_t)use_index_2;
	kind = OBJECT(player)->kind;
	if (kind == 1u)
	{
		saved_use_index = use_index;
		held_look = (((uint32_t)OBJECT(held)->kind << 8u) | OBJECT(held)->animation);
		masked_look = ((uint32_t)(held_look >> 8) << 8) | (held_look & 0x7Eu);
		use_index = saved_use_index;
		if (masked_look == 0x41Au)
		{
			OBJECT(player)->player.state_timer = 0u;
			move_and_animation = 0x4E0u;
			player_set_move_on_floor(y, player, move_and_animation);
			return;
		}
	}
	use_index_3 = use_index;
	player_start_throw(y, player, use_index_3);
}

/* Starts throwing what it carries: the state its kind gives (04 or 05) with animation B0 plus the kind
   less 4. */
void player_start_throw(uint16_t y, uint16_t player, uint16_t d)
{
	uint8_t a = 0;

	OBJECT(player)->player.state_timer = 0u;
	d = ((uint32_t)(uint8_t)((uint16_t)(((uint32_t)a << 8) | d) + 4u) << 8) | (uint8_t)(d - 0x50u);
	player_set_move_on_floor(y, player, d);
}

/* Starts swinging weapon 6, with its sound (6A). */
void player_start_swing_6(uint16_t player, uint8_t use_index_2)
{
	uint8_t use_index = 0;
	uint16_t command = 0;
	uint8_t saved_use_index = 0;

	saved_use_index = use_index_2;
	command = 0x6A00u;
	vector_queue_sound(command);
	use_index = saved_use_index;
	player_start_swing(player, use_index);
}

/* Starts swinging its weapon (6 or 7): the state and animation by its kind, hit 0813. */
void player_start_swing(uint16_t player, uint16_t d)
{
	uint16_t move_hit = 0;

	OBJECT(player)->player.state_timer = 0x3Cu;
	move_hit = 0x813u;
	d = ((uint32_t)(uint8_t)(d + 4u) << 8) | (uint8_t)(d - 0x50u);
	player_set_move_with_hit(move_hit, player, d);
}

/* Starts throwing weapon 8 (state 08, animation B4) when its second sprite is free. */
void player_start_throw_weapon_8(uint16_t y, uint16_t player)
{
	uint16_t move_and_animation = 0;
	uint8_t flags = 0;

	flags = OBJECT(player + 0x60u)->flags;
	if (flags != 0u)
	{
		player_take_touches(y, player);
		return;
	}
	OBJECT(player)->player.state_timer = 0x3Cu;
	move_and_animation = 0x8B4u;
	player_set_move_on_floor(y, player, move_and_animation);
}

/* Starts an attack: in the air a jump attack; after 4 quick presses of the joystick a dash attack (move
   0B, every eighth one 0C); else state 29, which picks the move. */
void player_start_attack(uint16_t kind, uint16_t player)
{
	uint16_t move_and_animation = 0, move_hit = 0;
	uint8_t frames_since_press = 0, quick_presses = 0, swings = 0, swings_2 = 0;
	uint16_t z = 0, floor_z = 0;

	OBJECT(player)->player.jump_attack = 1u;
	OBJECT(player)->player.attack_started = 1u;
	z = OBJECT(player)->z;
	floor_z = OBJECT(player)->floor_z;
	if ((int16_t)floor_z < (int16_t)z)
	{
		player_plain_attack(player);
		return;
	}
	frames_since_press = OBJECT(player)->player.frames_since_press;
	if ((int8_t)frames_since_press >= 8)
	{
		OBJECT(player)->box_width = 0x20u;
		OBJECT(player)->box_depth = 0x10u;
		OBJECT(player)->player.player_state = 0x29u;
		OBJECT(player)->flags |= 2u;
		player_take_touches(kind, player);
		return;
	}
	quick_presses = OBJECT(player)->player.quick_presses;
	if (quick_presses < 4u)
	{
		OBJECT(player)->box_width = 0x20u;
		OBJECT(player)->box_depth = 0x10u;
		OBJECT(player)->player.player_state = 0x29u;
		OBJECT(player)->flags |= 2u;
		player_take_touches(kind, player);
		return;
	}
	OBJECT(player)->player.quick_presses = 0u;
	move_hit = 0x414u;
	swings = OBJECT(player)->player.swings;
	OBJECT(player)->player.swings = swings + 1u;
	swings_2 = OBJECT(player)->player.swings;
	if (swings_2 >= 8u)
	{
		OBJECT(player)->player.swings = 0u;
		move_hit = 0x414u;
		move_and_animation = 0xCB8u;
		player_start_move(move_hit, player, move_and_animation);
		return;
	}
	move_and_animation = 0xBB7u;
	player_start_move(move_hit, player, move_and_animation);
}

/* With its shout, plays the combo's next move (object_1c_move_steps, object_1c_moves) when the swing
   touches an enemy, turned to it; else a plain swing. */
void player_choose_attack(uint16_t player)
{
	uint8_t attributes = 0, combo_index = 0, move_number = 0;
	uint16_t command = 0, hit = 0, hit_object = 0, move_and_animation = 0;
	uint8_t attributes_2 = 0, combo_step = 0, move_step = 0;
	uint16_t hit_by = 0, player_x = 0, hit_by_2 = 0, hit_x = 0, move_record = 0, state = 0;

	command = 0x3F20u;
	player_play_voice(player, command);
	if ((OBJECT(player)->flags & 0x20u) == 0u)
	{
		player_plain_attack(player);
		return;
	}
	hit_by = OBJECT(player)->hit_by;
	hit_object = hit_by;
	if (hit_object < OBJECT_ADDRESS(14) || hit_object >= OBJECT_ADDRESS(22))
	{
		player_plain_attack(player);
		return;
	}
	attributes_2 = OBJECT(player)->attributes;
	attributes = attributes_2 & 0xBFu;
	player_x = OBJECT(player)->x;
	hit_by_2 = OBJECT(player)->hit_by;
	hit_x = OBJECT(hit_by_2)->x;
	if ((int16_t)hit_x < (int16_t)player_x)
		attributes |= 0x40u;
	OBJECT(player)->attributes = attributes;
	combo_step = OBJECT(player)->player.combo_step;
	combo_index = combo_step;
	move_step = object_1c_move_steps[(int8_t)combo_index];
	move_number = move_step;
	if ((int8_t)move_step < 0)
	{
		move_number = 0u;
		combo_index = 0u;
	}
	OBJECT(player)->player.combo_step = combo_index + 1u;
	move_record = object_1c_moves_ADDRESS + (int8_t)(((uint32_t)move_number << 1) << 1);
	state = (((uint32_t)PLAYER_MOVE(move_record)->state << 8u) | PLAYER_MOVE(move_record)->animation);
	hit = PLAYER_MOVE(move_record)->hit;
	move_and_animation = state;
	player_start_move(hit, player, move_and_animation);
}

/* A swing that touched no enemy: move 09, every third one (or with left or right held) move 0A. */
void player_plain_attack(uint16_t player)
{
	uint16_t move_and_animation = 0, move_hit = 0;
	uint8_t controls = 0, swings = 0, swings_2 = 0;

	controls = OBJECT(player)->player.controls;
	if ((controls & 3u) == 0u)
	{
		swings = OBJECT(player)->player.swings;
		OBJECT(player)->player.swings = swings + 1u;
		swings_2 = OBJECT(player)->player.swings;
		if (swings_2 < 3u)
		{
			move_hit = 0x411u;
			move_and_animation = 0x9B5u;
			player_start_move(move_hit, player, move_and_animation);
			return;
		}
	}
	OBJECT(player)->player.swings = 0u;
	move_hit = 0x412u;
	move_and_animation = 0xAB6u;
	player_start_move(move_hit, player, move_and_animation);
}

/* Starts the attack move in D (state and animation) with the hit in Y: in the air its jump version. */
void player_start_move(uint16_t move_hit, uint16_t player, uint16_t move_and_animation)
{
	uint16_t player_z = 0;
	uint16_t z = 0, floor_z = 0;

	z = OBJECT(player)->z;
	player_z = z;
	floor_z = OBJECT(player)->floor_z;
	if ((int16_t)player_z <= (int16_t)floor_z)
	{
		player_set_move_with_hit(move_hit, player, move_and_animation);
		return;
	}
	move_hit = player_start_jump_attack(player_z, player);
	player_set_air_move(move_hit, player, move_and_animation);
}

/* Sets up a jump attack by its height above the floor: its hit, gravity, up and x speeds and box, with
   the player's shout. */
uint16_t player_start_jump_attack(uint16_t z, uint16_t player)
{
	uint16_t command = 0, cursor = 0, move_hit = 0;
	uint16_t player_z = 0;
	uint8_t attributes = 0;
	uint16_t floor_z = 0, height_above_floor = 0, settings = 0, gravity_address = 0, gravity = 0, rise_address = 0, rise_speed = 0;

	command = 0x3F20u;
	player_play_voice(player, command);
	player_z = z;
	floor_z = OBJECT(player)->floor_z;
	height_above_floor = player_z - floor_z;
	cursor = player_jump_attack_settings_ADDRESS;
	if ((int16_t)height_above_floor < 0x40)
		cursor += 0xAu;
	settings = cursor;
	move_hit = mem_read16(settings);
	gravity_address = settings + 2u;
	gravity = mem_read16(gravity_address);
	OBJECT(player)->player.attack_gravity = gravity;
	OBJECT(player)->flags |= 2u;
	rise_address = gravity_address + 2u;
	cursor = rise_address + 2u;
	rise_speed = mem_read16(rise_address);
	OBJECT(player)->z_speed = rise_speed;
	attributes = OBJECT(player)->attributes;
	if ((attributes & 0x40u) != 0u)
		cursor += 2u;
	OBJECT(player)->x_speed = mem_read16(cursor);
	OBJECT(player)->box_width = 8u;
	OBJECT(player)->box_depth = 4u;
	OBJECT(player)->box_dx = 8;
	return move_hit;
}

/* Keeps the move's hit (Y) and sets the move. */
void player_set_move_with_hit(uint16_t move_hit, uint16_t player, uint16_t d)
{
	OBJECT(player)->player.move_hit = move_hit;
	player_set_move_on_floor(move_hit, player, d);
}

/* Sets the move: on the floor stopped, in the air its jump version. */
void player_set_move_on_floor(uint16_t y, uint16_t player, uint16_t d)
{
	uint16_t z = 0, floor_z = 0;

	z = OBJECT(player)->z;
	floor_z = OBJECT(player)->floor_z;
	if ((int16_t)floor_z < (int16_t)z)
	{
		player_set_air_move(y, player, d);
		return;
	}
	OBJECT(player)->x_speed = 0;
	player_set_move_stopped(y, player, d);
}

/* Keeps the move's hit and takes the air version of its animation (16 on). */
void player_set_air_move(uint16_t move_hit, uint16_t player, uint16_t move_and_animation)
{
	OBJECT(player)->player.move_hit = move_hit;
	move_and_animation = (move_and_animation & ~0xFFu) | (uint8_t)(move_and_animation + 0x10u);
	player_set_move_stopped(move_hit, player, move_and_animation);
}

/* Stops the player's y speed and sets the move. */
void player_set_move_stopped(uint16_t animation_offsets, uint16_t player, uint16_t animation)
{
	OBJECT(player)->y_speed = 0;
	player_set_move(animation_offsets, player, animation);
}

/* Sets the player's state and animation (A, B), its timer and team flag cleared, and runs the move's
   first frame. */
void player_set_move(uint16_t animation_offsets, uint16_t player, uint16_t animation)
{
	uint32_t player_state_halfword = 0;

	OBJECT(player)->animation = (uint8_t)animation;
	player_state_halfword = animation & ~0xFFu;
	OBJECT(player)->player.player_state = (uint8_t)(player_state_halfword >> 8u);
	OBJECT(player)->player.state_timer = (uint8_t)player_state_halfword;
	OBJECT(player)->player.teamed = 0u;
	OBJECT(player)->player.state_frames = 1u;
	OBJECT(player)->animation_flags = 0u;
	player_attack_fall(animation_offsets, player);
}

/* The kid of a Marge team attack, thrown: flies on while it has speed, then turns three times and
   stands. */
void player_team_thrown(uint16_t y, uint16_t player)
{
	uint8_t attributes = 0, x_speed = 0;
	uint8_t blow_landed = 0, state_timer = 0, attributes_2 = 0;
	uint16_t x_speed_2 = 0;

	player_set_in_air(player);
	blow_landed = OBJECT(player)->player.blow_landed;
	if (blow_landed != 0u)
	{
		y = hit_spark_height_in_air_ADDRESS;
		y = player_show_hit_spark(y, player);
	}
	x_speed_2 = OBJECT(player)->x_speed;
	if (x_speed_2 != 0u)
	{
		player_take_touches(y, player);
		return;
	}
	state_timer = OBJECT(player)->player.state_timer;
	OBJECT(player)->player.state_timer = state_timer - 1u;
	if (state_timer == 1u)
	{
		OBJECT(player)->player.player_state = 0u;
		OBJECT(player)->animation = 0x80u;
		OBJECT(player)->damage = 0u;
		OBJECT(player)->attack = 0u;
		player_take_touches(y, player);
		return;
	}
	x_speed = 8u;
	attributes_2 = OBJECT(player)->attributes;
	attributes = attributes_2 ^ 0x40u;
	OBJECT(player)->attributes = attributes;
	if ((attributes & 0x40u) != 0u)
		x_speed = 0u - x_speed;
	OBJECT(player)->x_speed = (OBJECT(player)->x_speed & 0xFFu) | ((x_speed & 0xFFu) << 8u);
	player_take_touches(y, player);
}

/* The jump kick (both buttons): faces by the joystick, kicks with hit 0C13 at the top of the jump, lands
   and stands. */
void player_jump_kick(uint16_t player)
{
	uint32_t at_floor = 0, below_floor = 0, compare_overflow = 0;
	uint8_t flags = 0, joystick_bits = 0;
	uint16_t damage_and_attack = 0, z_speed = 0;
	uint8_t controls = 0, blow_landed = 0;
	uint16_t z_speed_2 = 0, floor_z = 0;

	controls = OBJECT(player)->player.controls;
	joystick_bits = controls;
	if ((joystick_bits & 1u) != 0u)
		OBJECT(player)->attributes = 0x40u;
	if ((joystick_bits & 2u) != 0u)
		OBJECT(player)->attributes = 0u;
	z_speed_2 = OBJECT(player)->z_speed;
	z_speed = z_speed_2 - 0x60u;
	OBJECT(player)->z_speed = z_speed;
	flags = OBJECT(player)->flags;
	if (z_speed != 0x240u)
	{
		damage_and_attack = player_reset_box(player);
		flags &= ~2u;
	}
	else
	{
		damage_and_attack = 0xC13u;
		OBJECT(player)->damage = 0xCu;
		OBJECT(player)->attack = 0x13u;
		OBJECT(player)->box_width = 0x10u;
		OBJECT(player)->box_dx = 8;
		flags |= 2u;
	}
	OBJECT(player)->flags = flags;
	blow_landed = OBJECT(player)->player.blow_landed;
	if (blow_landed != 0u)
	{
		damage_and_attack = hit_spark_height_ADDRESS;
		damage_and_attack = player_show_hit_spark(damage_and_attack, player);
	}
	player_next_height_against_floor(player, &at_floor, &below_floor, &compare_overflow);
	if (((below_floor ^ compare_overflow) | at_floor) == 0u)
	{
		player_take_touches(damage_and_attack, player);
		return;
	}
	player_set_on_floor(player);
	floor_z = OBJECT(player)->floor_z;
	OBJECT(player)->z = floor_z;
	OBJECT(player)->z_fraction = 0u;
	player_stop(player);
	OBJECT(player)->timer = 0u;
	player_end_state(damage_and_attack, player);
}

/* Holding the heavy object up with another player for 15 frames, then letting it fly (its step 04) and
   standing. */
void player_heave_heavy_object(uint16_t kind, uint16_t player)
{
	uint16_t held_object = 0;
	uint8_t state_timer = 0;
	uint16_t held = 0;

	state_timer = OBJECT(player)->player.state_timer;
	OBJECT(player)->player.state_timer = state_timer - 1u;
	if (state_timer != 1u)
	{
		player_keep_life(player);
		return;
	}
	held = OBJECT(player)->player.held;
	held_object = held;
	OBJECT(player)->player.held = 0u;
	OBJECT(held_object)->state = 4u;
	player_end_state(kind, player);
}

/* Throwing a carried kind-4 object: holds it by character, lets it fly at the animation's throw frame. */
void player_throw_carried_4(uint16_t animation_offsets, uint16_t player)
{
	uint16_t held_object = 0, offsets = 0;
	uint8_t misread = 0, animation_flags = 0, state_timer = 0;
	uint16_t held = 0;

	held = OBJECT(player)->player.held;
	held_object = held;
	misread = io_read8(0x31u);
	if (misread != 0u)
	{
		player_attack_fall(animation_offsets, player);
		return;
	}
	offsets = carry_offsets_throwing_ADDRESS;
	animation_flags = OBJECT(player)->animation_flags;
	if ((animation_flags & 2u) != 0u)
	{
		state_timer = OBJECT(player)->player.state_timer;
		OBJECT(player)->player.state_timer = state_timer + 1u;
		offsets = throw_release_offsets_ADDRESS;
		player_release_throw(held_object, offsets, player);
		return;
	}
	offsets = player_place_carried(held_object, offsets, player);
	player_attack_fall(offsets, player);
}

/* Throwing a carried kind-5 object: the same as for kind 4. */
void player_throw_carried_5(uint16_t animation_offsets, uint16_t player)
{
	uint16_t held_object = 0, offsets = 0;
	uint8_t misread = 0, animation_flags = 0, state_timer = 0;
	uint16_t held = 0;

	held = OBJECT(player)->player.held;
	held_object = held;
	misread = io_read8(0x31u);
	if (misread != 0u)
	{
		player_attack_fall(animation_offsets, player);
		return;
	}
	offsets = carry_offsets_throwing_ADDRESS;
	animation_flags = OBJECT(player)->animation_flags;
	if ((animation_flags & 2u) != 0u)
	{
		state_timer = OBJECT(player)->player.state_timer;
		OBJECT(player)->player.state_timer = state_timer + 1u;
		offsets = throw_release_offsets_ADDRESS;
		player_release_throw(held_object, offsets, player);
		return;
	}
	offsets = player_place_carried(held_object, offsets, player);
	player_attack_fall(offsets, player);
}

/* Lets the carried object fly: sound 19, placed in front, its step 04 and x speed 0400 the way the
   player faces; the player holds nothing. */
void player_release_throw(uint16_t held, uint16_t offsets, uint16_t player)
{
	uint16_t command = 0, throw_speed = 0;
	uint8_t attributes = 0;
	uint16_t player_y = 0;

	command = 0x1900u;
	vector_queue_sound(command);
	player_place_carried(held, offsets, player);
	player_y = OBJECT(player)->y;
	OBJECT(held)->y = player_y;
	OBJECT(held)->y_fraction = 0u;
	OBJECT(held)->state = 4u;
	OBJECT(player)->player.held = 0u;
	throw_speed = 0x400u;
	attributes = OBJECT(player)->attributes;
	if ((attributes & 0x40u) != 0u)
		throw_speed = 0xFC00u;
	OBJECT(held)->x_speed = throw_speed;
	OBJECT(held)->y_speed = 0;
	OBJECT(held)->z_speed = 0;
	player_attack_fall(throw_speed, player);
}

/* Throwing weapon 8: at the throw frame sound 19 and the weapon flies as the second sprite; at the end
   one use less, and none left drops it. */
void player_throw_weapon_8(uint16_t animation_offsets, uint16_t player)
{
	uint8_t frame_flags = 0;
	uint16_t command = 0, effect = 0, effect_state = 0;
	uint8_t animation_flags = 0, weapon_uses = 0;

	animation_flags = OBJECT(player)->animation_flags;
	frame_flags = animation_flags;
	if ((frame_flags & 2u) != 0u)
	{
		command = 0x1900u;
		vector_queue_sound(command);
		effect = 0x882u;
		effect_state = 0x800u;
		player_start_effect(effect, player, effect_state);
		player_attack_fall(effect, player);
		return;
	}
	if (frame_flags & 1u)
	{
		weapon_uses = (uint8_t)(OBJECT(player + 0x60u)->player.held >> 8u);
		OBJECT(player + 0x60u)->player.held = (OBJECT(player + 0x60u)->player.held & 0xFFu) | ((weapon_uses - 1u & 0xFFu) << 8u);
		if (weapon_uses == 1u)
		{
			OBJECT(player)->player.held = 0u;
			player_attack_fall(animation_offsets, player);
			return;
		}
	}
	player_attack_fall(animation_offsets, player);
}

/* Swinging weapon 6. */
void player_swing_6(uint16_t player)
{
	uint16_t spark_height = 0;

	spark_height = hit_spark_height_ADDRESS;
	player_attack_move(spark_height, player);
}

/* Swinging weapon 7, with sound 1E at its hit frame. */
void player_swing_7(uint16_t player)
{
	uint16_t command = 0, spark_height = 0;
	uint8_t animation_flags = 0;

	animation_flags = OBJECT(player)->animation_flags;
	if ((animation_flags & 2u) != 0u)
	{
		command = 0x1E00u;
		vector_queue_sound(command);
	}
	spark_height = hit_spark_height_ADDRESS;
	player_attack_move(spark_height, player);
}

/* The team attack of Homer and a kid (state 38), undone at a stage's end. */
void player_team_attack_homer(uint16_t teammate, uint16_t y, uint16_t player)
{
	uint16_t spark_height = 0;
	uint8_t stage_is_over = 0;

	stage_is_over = io_read8(players_stop_request);
	if (stage_is_over == 0u)
	{
		spark_height = hit_spark_height_ADDRESS;
		player_attack_move(spark_height, player);
		return;
	}
	player_team_split(teammate, player);
	OBJECT(teammate)->flags = 0xC0u;
	player_stand(y, player);
}

/* The first attack move (09, animation B5). */
void player_attack_1(uint16_t player)
{
	uint16_t spark_height = 0;

	spark_height = hit_spark_height_ADDRESS;
	player_attack_walking(spark_height, player);
}

/* The second attack move (0A, animation B6). */
void player_attack_2(uint16_t player)
{
	uint16_t spark_height = 0;

	spark_height = hit_spark_height_ADDRESS;
	player_attack_walking(spark_height, player);
}

/* Moves 09 and 0A on the floor: the player creeps at an eighth of its walk speed by its joystick. */
void player_attack_walking(uint16_t y, uint16_t player)
{
	uint8_t animation = 0, controls = 0;
	uint16_t x_speed = 0, slow_x_speed = 0;

	animation = OBJECT(player)->animation;
	if ((int8_t)(animation & 0x7Fu) >= 0x40)
	{
		player_jump_attack(y, player);
		return;
	}
	controls = OBJECT(player)->player.controls;
	x_speed = player_walk_velocities[controls & 0xFu].x_speed;
	slow_x_speed = (int16_t)x_speed >> 3;
	OBJECT(player)->x_speed = slow_x_speed;
	player_ground_attack(y, player);
}

/* The third attack move (0B, animation B7), also the dash attack. */
void player_attack_3(uint16_t player)
{
	uint16_t spark_height = 0;

	spark_height = hit_spark_height_ADDRESS;
	player_attack_move(spark_height, player);
}

/* The combo's last move (0C, animation B8). */
void player_attack_finish(uint16_t player)
{
	uint16_t spark_height = 0;

	spark_height = hit_spark_height_ADDRESS;
	player_attack_move(spark_height, player);
}

/* Runs an attack move, on the floor or as a jump attack by its animation. */
void player_attack_move(uint16_t y, uint16_t player)
{
	uint8_t animation_number = 0;
	uint8_t animation = 0;

	animation = OBJECT(player)->animation;
	animation_number = animation & 0x7Fu;
	if ((int8_t)animation_number < 0x40 || animation_number == 0x7Bu)
	{
		player_ground_attack(y, player);
		return;
	}
	player_jump_attack(y, player);
}

/* A jump attack: falls with its gravity, hitting every 8 frames while 30 above the floor, until it
   lands. */
void player_jump_attack(uint16_t y, uint16_t player)
{
	uint32_t at_floor = 0, below_floor = 0, compare_overflow = 0;
	uint8_t jump_attack = 0, blow_landed = 0;
	uint16_t z_speed = 0, attack_gravity = 0, new_z_speed = 0, floor_z = 0, z = 0, move_hit = 0;

	jump_attack = OBJECT(player)->player.jump_attack;
	if (jump_attack == 0u)
	{
		z_speed = OBJECT(player)->z_speed;
		attack_gravity = OBJECT(player)->player.attack_gravity;
		new_z_speed = z_speed - attack_gravity;
		OBJECT(player)->z_speed = new_z_speed;
		player_next_height_against_floor(player, &at_floor, &below_floor, &compare_overflow);
		if (((below_floor ^ compare_overflow) | at_floor) == 0u)
		{
			player_take_touches(y, player);
			return;
		}
		OBJECT(player)->animation_flags = 1u;
		OBJECT(player)->player.jump_attack = 0u;
		player_attack_land(y, player);
		return;
	}
	blow_landed = OBJECT(player)->player.blow_landed;
	if (blow_landed == 0u)
	{
		floor_z = OBJECT(player)->floor_z;
		z = OBJECT(player)->z;
		if ((int16_t)z <= (int16_t)(floor_z + 0x1Eu) || (frame_count & 7u) != 0u)
		{
			OBJECT(player)->damage = 0u;
			OBJECT(player)->attack = 0u;
			z_speed = OBJECT(player)->z_speed;
			attack_gravity = OBJECT(player)->player.attack_gravity;
			new_z_speed = z_speed - attack_gravity;
			OBJECT(player)->z_speed = new_z_speed;
			player_next_height_against_floor(player, &at_floor, &below_floor, &compare_overflow);
			if (((below_floor ^ compare_overflow) | at_floor) == 0u)
			{
				player_take_touches(y, player);
				return;
			}
			OBJECT(player)->animation_flags = 1u;
			OBJECT(player)->player.jump_attack = 0u;
			player_attack_land(y, player);
			return;
		}
		move_hit = OBJECT(player)->player.move_hit;
		OBJECT(player)->damage = (uint8_t)(move_hit >> 8u);
		OBJECT(player)->attack = (uint8_t)move_hit;
		z_speed = OBJECT(player)->z_speed;
		attack_gravity = OBJECT(player)->player.attack_gravity;
		new_z_speed = z_speed - attack_gravity;
		OBJECT(player)->z_speed = new_z_speed;
		player_next_height_against_floor(player, &at_floor, &below_floor, &compare_overflow);
		if (((below_floor ^ compare_overflow) | at_floor) == 0u)
		{
			player_take_touches(y, player);
			return;
		}
		OBJECT(player)->animation_flags = 1u;
		OBJECT(player)->player.jump_attack = 0u;
		player_attack_land(y, player);
		return;
	}
	y = hit_spark_height_in_air_ADDRESS;
	y = player_show_hit_spark(y, player);
	OBJECT(player)->damage = 0u;
	OBJECT(player)->attack = 0u;
	z_speed = OBJECT(player)->z_speed;
	attack_gravity = OBJECT(player)->player.attack_gravity;
	new_z_speed = z_speed - attack_gravity;
	OBJECT(player)->z_speed = new_z_speed;
	player_next_height_against_floor(player, &at_floor, &below_floor, &compare_overflow);
	if (((below_floor ^ compare_overflow) | at_floor) == 0u)
	{
		player_take_touches(y, player);
		return;
	}
	OBJECT(player)->animation_flags = 1u;
	OBJECT(player)->player.jump_attack = 0u;
	player_attack_land(y, player);
}

/* An attack on the floor: at the animation's hit frame its hit and the box of player_attack_boxes (state
   38 its own); otherwise no box. */
void player_ground_attack(uint16_t y, uint16_t player)
{
	uint8_t flags = 0, state_value = 0;
	uint8_t blow_landed = 0, animation_flags = 0, player_state = 0, kind = 0;
	uint16_t move_hit = 0, width = 0;

	blow_landed = OBJECT(player)->player.blow_landed;
	if (blow_landed != 0u)
		y = player_show_hit_spark(y, player);
	animation_flags = OBJECT(player)->animation_flags;
	if ((animation_flags & 2u) == 0u)
	{
		y = player_reset_box(player);
		OBJECT(player)->damage = 0u;
		OBJECT(player)->attack = 0u;
		flags = OBJECT(player)->flags & ~2u;
		OBJECT(player)->flags = flags;
		player_attack_fall(y, player);
		return;
	}
	move_hit = OBJECT(player)->player.move_hit;
	OBJECT(player)->damage = (uint8_t)(move_hit >> 8u);
	OBJECT(player)->attack = (uint8_t)move_hit;
	player_state = OBJECT(player)->player.player_state;
	state_value = player_state;
	if (state_value == 0x38u)
	{
		OBJECT(player)->box_width = 0x12u;
		OBJECT(player)->box_dx = 0x10;
		player_attack_fall(y, player);
		return;
	}
	kind = OBJECT(player)->kind;
	width = AT16(ATTACK_BOX(player_attack_boxes_ADDRESS + (int8_t)(((((state_value - 6u) << 1) << 1) + kind) << 1))->width, -1);
	OBJECT(player)->box_width = width >> 8;
	OBJECT(player)->box_dx = width;
	flags = OBJECT(player)->flags | 2u;
	OBJECT(player)->flags = flags;
	player_attack_fall(y, player);
}

/* Lets an attacking player fall to the floor, then ends the move when its animation does. */
void player_attack_fall(uint16_t animation_offsets, uint16_t player)
{
	uint32_t at_floor = 0, below_floor = 0, compare_overflow = 0;
	uint16_t z_speed = 0;

	player_next_height_against_floor(player, &at_floor, &below_floor, &compare_overflow);
	if (at_floor)
	{
		player_attack_end(animation_offsets, player);
		return;
	}
	if ((below_floor ^ compare_overflow) | at_floor)
	{
		player_attack_land(animation_offsets, player);
		return;
	}
	z_speed = OBJECT(player)->z_speed;
	OBJECT(player)->z_speed = z_speed - 0x60u;
	player_attack_end(animation_offsets, player);
}

/* Puts an attacking player on the floor at a stop. */
void player_attack_land(uint16_t animation_offsets, uint16_t player)
{
	uint16_t floor_z = 0;

	player_set_on_floor(player);
	floor_z = OBJECT(player)->floor_z;
	OBJECT(player)->z = floor_z;
	OBJECT(player)->z_fraction = 0u;
	player_stop(player);
	OBJECT(player)->timer = 0u;
	player_attack_end(animation_offsets, player);
}

/* Ends an attack move when its animation does, a team's its own way. */
void player_attack_end(uint16_t animation_offsets, uint16_t player)
{
	uint8_t animation_base = 0, animation_offset = 0, attack_state = 0, facing_left = 0, floor_high = 0, floor_low = 0, owner_kind = 0;
	uint16_t player_z = 0, teammate = 0, x_speed = 0;
	uint8_t facing_for_teammate = 0;
	uint8_t teamed = 0, animation_flags = 0, kind = 0, kind_2 = 0, team_move_number = 0, team_move_number_2 = 0, team_move_number_3 = 0, kind_3 = 0, animation_entry = 0, player_state = 0, attributes = 0, facing_left_bit = 0, attributes_2 = 0;
	uint16_t partner = 0, action = 0, z = 0, floor_z = 0, z_2 = 0, floor_z_2 = 0, floor_z_3 = 0, z_3 = 0, partner_2 = 0, z_4 = 0;
	uint32_t action_halfword = 0;

	teamed = OBJECT(player)->player.teamed;
	if ((int8_t)teamed >= 0)
	{
		player_end_on_animation(animation_offsets, player);
		return;
	}
	animation_flags = OBJECT(player)->animation_flags;
	if ((animation_flags & 1u) == 0u)
	{
		for (;;)
		{
			partner = OBJECT(player)->player.partner;
			teammate = partner;
			player_team_follow(teammate, player);
			kind = OBJECT(teammate)->kind;
			owner_kind = kind;
			if ((int8_t)random_number < 0)
			{
				kind_2 = OBJECT(player)->kind;
				owner_kind = kind_2;
			}
			OBJECT(player)->shadow_player = ((((uint32_t)owner_kind << 1) << 1) << 1) << 1;
			action = (((uint32_t)OBJECT(player)->action << 8u) | OBJECT(player)->action_step);
			action_halfword = action - 1u;
			OBJECT(player)->action = (uint8_t)(action_halfword >> 8u);
			OBJECT(player)->action_step = (uint8_t)action_halfword;
			if (action != 1u)
			{
				player_take_touches(animation_offsets, player);
				return;
			}
			team_move_number = OBJECT(player)->player.team_move_number;
			if (team_move_number != 2u)
				break;
			team_move_number_2 = OBJECT(player)->player.team_move_number;
			attack_state = team_move_attack_states[(int8_t)team_move_number_2];
			OBJECT(player)->player.attack_started = attack_state;
			OBJECT(player)->damage = 0xCu;
			OBJECT(player)->attack = 0x13u;
			z = OBJECT(player)->z;
			player_z = z;
			floor_z = OBJECT(player)->floor_z;
			if ((int16_t)floor_z < (int16_t)player_z)
			{
				player_start_jump_attack(player_z, player);
				animation_base = 0xFCu;
			}
			else
			{
				OBJECT(player)->x_speed = 0;
				OBJECT(player)->y_speed = 0;
				animation_base = 0xF8u;
			}
			OBJECT(player)->player.player_state = attack_state;
			team_animation_base = animation_base;
			animation_offsets = team_move_animation_offsets_ADDRESS;
			team_move_number_3 = OBJECT(player)->player.team_move_number;
			kind_3 = OBJECT(player)->kind;
			animation_entry = team_move_animation_offsets[(int8_t)((uint8_t)((((uint32_t)team_move_number_3 << 1) << 1) + kind_3))];
			animation_offset = animation_entry;
			if ((int8_t)animation_entry < 0)
				continue;
			OBJECT(player)->animation = animation_offset + team_animation_base;
		}
		player_team_split(teammate, player);
		OBJECT(teammate)->flags = 0xC0u;
		OBJECT(player)->x_speed = 0;
		OBJECT(teammate)->x_speed = 0;
		OBJECT(player)->y_speed = 0;
		OBJECT(teammate)->y_speed = 0;
		player_take_touches(animation_offsets, player);
		return;
	}
	OBJECT(player)->damage = 0u;
	OBJECT(player)->attack = 0u;
	player_state = OBJECT(player)->player.player_state;
	if (player_state != 0x35u)
	{
		z_2 = OBJECT(player)->z;
		floor_z_2 = OBJECT(player)->floor_z;
		if ((int16_t)z_2 <= (int16_t)floor_z_2)
		{
			player_team_together(player);
			return;
		}
		player_team_start_fall(player);
		return;
	}
	floor_z_3 = OBJECT(player)->floor_z;
	floor_high = (uint8_t)(floor_z_3 >> 8);
	floor_low = (uint8_t)floor_z_3;
	z_3 = OBJECT(player)->z;
	if ((int16_t)z_3 <= (int16_t)(((uint32_t)floor_high << 8) | floor_low))
	{
		OBJECT(player)->z = ((uint32_t)floor_high << 8) | floor_low;
		OBJECT(player)->z_fraction = 0u;
		OBJECT(player)->z_speed = 0;
		OBJECT(player)->x_speed = 0;
	}
	OBJECT(player)->y_speed = 0;
	partner_2 = OBJECT(player)->player.partner;
	teammate = partner_2;
	OBJECT(player)->player.player_state = 0x37u;
	OBJECT(player)->player.state_timer = 3u;
	OBJECT(teammate)->player.player_state = 0x36u;
	OBJECT(player)->animation = 0xF9u;
	OBJECT(teammate)->animation = 0xF9u;
	OBJECT(player)->damage = 8u;
	OBJECT(player)->attack = 0x11u;
	z_4 = OBJECT(teammate)->z;
	OBJECT(player)->z = z_4 + 0x38u;
	x_speed = 0x800u;
	attributes = OBJECT(player)->attributes;
	facing_left_bit = attributes & 0x40u;
	facing_left = facing_left_bit;
	if (facing_left_bit != 0u)
		x_speed = 0xF800u;
	OBJECT(player)->x_speed = x_speed;
	OBJECT(player)->y_speed = 0;
	OBJECT(player)->z_speed = 0;
	facing_for_teammate = facing_left;
	attributes_2 = OBJECT(teammate)->attributes;
	OBJECT(teammate)->attributes = (attributes_2 & 0x70u) | facing_for_teammate;
	player_team_release(teammate, player);
	OBJECT(teammate)->flags = OBJECT(player)->flags;
	player_take_touches(x_speed, player);
}

/* When the animation ends (an attack, lifting something), faces the way it attacked and goes back to
   standing or falling. */
void player_end_on_animation(uint16_t kind, uint16_t player)
{
	uint8_t animation_flags = 0, attributes = 0, attack_facing = 0;

	animation_flags = OBJECT(player)->animation_flags;
	if ((animation_flags & 1u) == 0u)
	{
		player_take_touches(kind, player);
		return;
	}
	attributes = OBJECT(player)->attributes;
	attack_facing = OBJECT(player)->player.attack_facing;
	OBJECT(player)->attributes = (attributes & 0xBFu) | attack_facing;
	player_back_to_stand(kind, player);
}

/* Ends the state: the player dies with no life left, else stands or falls. */
void player_end_state(uint16_t kind, uint16_t player)
{
	uint8_t vitality = 0;

	vitality = OBJECT(player)->vitality;
	if (vitality == 0u)
	{
		player_die(player);
		return;
	}
	player_back_to_stand(kind, player);
}

/* Back to standing or falling, its attack box off, turned round when its reaction flipped it. */
void player_back_to_stand(uint16_t kind, uint16_t player)
{
	uint8_t status = 0, attributes = 0;
	uint16_t z = 0, floor_z = 0;

	status = OBJECT(player)->player.status;
	if ((int8_t)status < 0)
	{
		attributes = OBJECT(player)->attributes;
		OBJECT(player)->attributes = attributes ^ 0x40u;
		OBJECT(player)->player.status = 0u;
	}
	OBJECT(player)->flags = (OBJECT(player)->flags & ~2u) | 0x40u;
	OBJECT(player)->box_dx = 0;
	OBJECT(player)->damage = 0u;
	OBJECT(player)->attack = 0u;
	z = OBJECT(player)->z;
	floor_z = OBJECT(player)->floor_z;
	if ((int16_t)z <= (int16_t)floor_z)
	{
		player_land(player);
		return;
	}
	player_start_fall(kind, player);
}

/* Flung toward the back of the stage (blow 07): flies up and back until it hits the back line, with a
   thud and its voice. */
void player_flung_back(uint16_t player)
{
	uint32_t zero = 0, carry = 0;
	uint16_t command = 0;
	uint16_t player_y = 0;

	OBJECT(player)->x_speed = 0x100;
	OBJECT(player)->z_speed = 0x500;
	player_check_screen_edges(player, &zero, &carry);
	OBJECT(player)->y_speed = -0x600;
	player_y = OBJECT(player)->y;
	if ((int16_t)player_y >= 0x98)
	{
		player_keep_life(player);
		return;
	}
	command = 0x3F00u;
	player_play_voice(player, command);
	command = 0x1B00u;
	vector_queue_sound(command);
	player_stop(player);
	OBJECT(player)->y = 0x98u;
	OBJECT(player)->player.player_state = 0x3Cu;
	OBJECT(player)->player.state_timer = 0x10u;
	player_stuck_on_back(player);
}

/* Hangs against the back for 16 frames, then starts sliding down. */
void player_stuck_on_back(uint16_t player)
{
	uint8_t state_timer = 0;

	state_timer = OBJECT(player)->player.state_timer;
	OBJECT(player)->player.state_timer = state_timer - 1u;
	if (state_timer != 1u)
	{
		player_keep_life(player);
		return;
	}
	OBJECT(player)->z_speed = -0x80;
	OBJECT(player)->player.player_state = 0x3Du;
	OBJECT(player)->player.state_timer = 0x10u;
	player_slide_down_back(player);
}

/* Slides down the back for 16 frames, then stops. */
void player_slide_down_back(uint16_t player)
{
	uint8_t state_timer = 0;

	state_timer = OBJECT(player)->player.state_timer;
	OBJECT(player)->player.state_timer = state_timer - 1u;
	if (state_timer != 1u)
	{
		player_keep_life(player);
		return;
	}
	OBJECT(player)->z_speed = 0;
	OBJECT(player)->player.player_state = 0x3Eu;
	OBJECT(player)->player.state_timer = 0x10u;
	player_peel_off_back(player);
}

/* After 16 frames more, drops off the back (state 0E, animation DE). */
void player_peel_off_back(uint16_t player)
{
	uint8_t animation = 0;
	uint16_t state_and_time = 0;
	uint8_t state_timer = 0;

	state_timer = OBJECT(player)->player.state_timer;
	OBJECT(player)->player.state_timer = state_timer - 1u;
	if (state_timer != 1u)
	{
		player_keep_life(player);
		return;
	}
	state_and_time = 0xE10u;
	animation = 0xDEu;
	player_set_state(state_and_time, player, animation);
}

/* Squashed flat: waits on the floor until its animation ends, then lies down (state 16). */
void player_squashed(uint16_t player)
{
	uint16_t z = 0;
	uint8_t animation_flags = 0;
	uint16_t floor_z = 0, z_2 = 0;

	floor_z = OBJECT(player)->floor_z;
	z = floor_z;
	z_2 = OBJECT(player)->z;
	if ((int16_t)z_2 <= (int16_t)z)
	{
		OBJECT(player)->z = z;
		OBJECT(player)->z_fraction = 0u;
		OBJECT(player)->z_speed = 0;
		animation_flags = OBJECT(player)->animation_flags;
		if (animation_flags & 1u)
		{
			player_lie_down(player);
			return;
		}
	}
	player_keep_life(player);
}

/* Knocked flying: falls (crashing into the screen's edge), then slides along the floor until its timer
   or speed runs out and lies down. */
void player_knocked_flying(uint16_t player)
{
	uint32_t zero = 0, below_floor = 0, compare_overflow = 0, blocked_ahead = 0;
	uint8_t state_timer = 0;
	uint16_t x_speed = 0, floor_z = 0, z_speed = 0;

	player_next_height_against_floor(player, &zero, &below_floor, &compare_overflow);
	if ((below_floor ^ compare_overflow) | zero)
	{
		player_set_on_floor(player);
		state_timer = OBJECT(player)->player.state_timer;
		OBJECT(player)->player.state_timer = state_timer - 1u;
		if (state_timer == 1u)
		{
			player_lie_down(player);
			return;
		}
		x_speed = OBJECT(player)->x_speed;
		if (x_speed == 0u)
		{
			player_lie_down(player);
			return;
		}
		OBJECT(player)->z_speed = 0;
		floor_z = OBJECT(player)->floor_z;
		OBJECT(player)->z = floor_z;
		OBJECT(player)->z_fraction = 0u;
		player_check_screen_edges(player, &zero, &blocked_ahead);
		if (blocked_ahead == 0u)
		{
			player_keep_life(player);
			return;
		}
		player_lie_down(player);
		return;
	}
	player_set_in_air(player);
	z_speed = OBJECT(player)->z_speed;
	OBJECT(player)->z_speed = z_speed - 0x60u;
	player_check_screen_edges(player, &zero, &blocked_ahead);
	if (zero)
	{
		player_keep_life(player);
		return;
	}
	player_crash_into_edge(player);
}

/* Waits for the reaction's animation to end, then ends the state (picking up, a blow from the front,
   getting up). */
void player_wait_for_animation(uint16_t kind, uint16_t player)
{
	uint8_t animation_flags = 0;

	animation_flags = OBJECT(player)->animation_flags;
	if ((animation_flags & 1u) == 0u)
	{
		player_keep_life(player);
		return;
	}
	player_end_state(kind, player);
}

/* Knocked down (animation D4): when the animation ends, dies with no life left, else gets up (state 23,
   animation DC). */
void player_knocked_down(uint16_t player)
{
	uint8_t animation = 0;
	uint16_t state_and_time = 0;
	uint8_t animation_flags = 0, vitality = 0;

	animation_flags = OBJECT(player)->animation_flags;
	if ((animation_flags & 1u) == 0u)
	{
		player_keep_life(player);
		return;
	}
	vitality = OBJECT(player)->vitality;
	if (vitality == 0u)
	{
		player_die(player);
		return;
	}
	state_and_time = 0x2300u;
	animation = 0xDCu;
	player_set_floor_state(state_and_time, player, animation);
}

/* Lying down (animation D5): when the animation ends, dies with no life left, else gets up (state 24,
   animation DD). */
void player_lying_down(uint16_t player)
{
	uint8_t animation = 0;
	uint16_t state_and_time = 0;
	uint8_t animation_flags = 0, vitality = 0;

	animation_flags = OBJECT(player)->animation_flags;
	if ((animation_flags & 1u) == 0u)
	{
		player_keep_life(player);
		return;
	}
	vitality = OBJECT(player)->vitality;
	if (vitality == 0u)
	{
		player_die(player);
		return;
	}
	state_and_time = 0x2400u;
	animation = 0xDDu;
	player_set_floor_state(state_and_time, player, animation);
}

/* After a crash (into the back, the screen's edge, or a wall when joining): drops to the floor, waits,
   and stands (blinking, when it was joining). */
void player_drop_after_crash(uint16_t kind, uint16_t player)
{
	uint32_t at_floor = 0, below_floor = 0, compare_overflow = 0;
	uint8_t state_timer = 0, state_timer_2 = 0, player_state = 0, state_timer_3 = 0;
	uint16_t floor_z = 0;

	state_timer = OBJECT(player)->player.state_timer;
	if (state_timer != 0x10u)
	{
		state_timer_2 = OBJECT(player)->player.state_timer;
		OBJECT(player)->player.state_timer = state_timer_2 - 1u;
		if (state_timer_2 == 1u)
		{
			player_end_state(kind, player);
			return;
		}
		player_keep_life(player);
		return;
	}
	player_next_height_against_floor(player, &at_floor, &below_floor, &compare_overflow);
	if (((below_floor ^ compare_overflow) | at_floor) == 0u)
	{
		OBJECT(player)->z_speed = -0x300;
		player_keep_life(player);
		return;
	}
	player_state = OBJECT(player)->player.player_state;
	if (player_state == 0x28u)
	{
		player_entry_land(player);
		return;
	}
	state_timer_3 = OBJECT(player)->player.state_timer;
	OBJECT(player)->player.state_timer = state_timer_3 - 1u;
	floor_z = OBJECT(player)->floor_z;
	OBJECT(player)->z = floor_z;
	OBJECT(player)->z_fraction = 0u;
	OBJECT(player)->z_speed = 0;
	player_keep_life(player);
}

/* After a blow of strength 03 or 04 (sound 5E and its voice): falls to the floor and stands when its 60
   frames run out. */
void player_stunned(uint16_t kind, uint16_t player)
{
	uint32_t at_floor = 0, below_floor = 0, compare_overflow = 0;
	uint8_t state_timer = 0;
	uint16_t z_speed = 0, floor_z = 0;

	player_next_height_against_floor(player, &at_floor, &below_floor, &compare_overflow);
	if (((below_floor ^ compare_overflow) | at_floor) == 0u)
	{
		z_speed = OBJECT(player)->z_speed;
		OBJECT(player)->z_speed = z_speed - 0x60u;
		player_keep_life(player);
		return;
	}
	OBJECT(player)->z_speed = 0;
	floor_z = OBJECT(player)->floor_z;
	OBJECT(player)->z = floor_z;
	OBJECT(player)->z_fraction = 0u;
	state_timer = OBJECT(player)->player.state_timer;
	OBJECT(player)->player.state_timer = state_timer - 1u;
	if (state_timer == 1u)
	{
		player_end_state(kind, player);
		return;
	}
	player_keep_life(player);
}

/* Held by an enemy: a blow frees it (state 3A); every 60 frames it loses 4 of its life. */
void player_grabbed(uint16_t y, uint16_t player)
{
	uint8_t hit_kind = 0, vitality = 0;
	uint16_t command = 0, grabber = 0;
	uint8_t hit = 0, flags = 0, state_timer = 0, vitality_2 = 0, life_before = 0;
	uint16_t holder = 0;

	holder = OBJECT(player)->player.holder;
	grabber = holder;
	if ((OBJECT(player)->flags & 0x20u) != 0u)
	{
		hit = OBJECT(player)->hit;
		hit_kind = hit;
		if (hit != 0u && hit_kind < 0x10u)
		{
			OBJECT(grabber)->grabber.squeeze_step = 2u;
			command = 0x3F24u;
			player_play_voice(player, command);
			flags = OBJECT(player + 0x60u)->flags;
			if (flags == 0u)
				player_show_hurt_spark(player, &grabber, &y);
			y = player_flash_palette(y, player);
			OBJECT(player)->flags = 0x80u;
			OBJECT(player)->player.player_state = 0x3Au;
		}
	}
	state_timer = OBJECT(player)->player.state_timer;
	OBJECT(player)->player.state_timer = state_timer - 1u;
	if (state_timer != 1u)
	{
		player_struggle(grabber, y, player);
		return;
	}
	y = player_flash_palette(y, player);
	OBJECT(player)->player.state_timer = 0x3Cu;
	vitality_2 = OBJECT(player)->vitality;
	life_before = vitality_2;
	vitality = life_before - 4u;
	if (life_before < 4u)
		vitality = 0u;
	OBJECT(player)->vitality = vitality;
	player_struggle(grabber, y, player);
}

/* While held: escapes (state 3B) at the stage's end, when its holder is thrown, or after enough presses;
   with no life left falls (state 15). */
void player_struggle(uint16_t holder, uint16_t kind, uint16_t player)
{
	uint16_t effect_state = 0, holder_object = 0;
	uint8_t vitality = 0, stage_is_over = 0, state = 0, controls_pressed = 0, hold_presses = 0;
	uint16_t holder_2 = 0;

	vitality = OBJECT(player)->vitality;
	if (vitality == 0u)
	{
		effect_state = 0xD00u;
		player_start_effect(kind, player, effect_state);
		holder_2 = OBJECT(player)->player.holder;
		holder_object = holder_2;
		OBJECT(holder_object)->grabber.squeeze_step = 0u;
		player_fall_down(player);
		return;
	}
	stage_is_over = io_read8(players_stop_request);
	if (stage_is_over != 0u)
	{
		effect_state = 0xD00u;
		player_start_effect(kind, player, effect_state);
		OBJECT(holder)->grabber.squeeze_step = 0u;
		OBJECT(player)->player.hold_presses = 0u;
		OBJECT(player)->flags = 0x80u;
		OBJECT(player)->player.player_state = 0x3Bu;
		player_keep_life(player);
		return;
	}
	state = OBJECT(holder)->state;
	if (state == 4u)
	{
		effect_state = 0xD00u;
		player_start_effect(kind, player, effect_state);
		OBJECT(holder)->grabber.squeeze_step = 0u;
		OBJECT(player)->player.hold_presses = 0u;
		OBJECT(player)->flags = 0x80u;
		OBJECT(player)->player.player_state = 0x3Bu;
		player_keep_life(player);
		return;
	}
	controls_pressed = OBJECT(player)->player.controls_pressed;
	if (controls_pressed != 0u)
	{
		hold_presses = OBJECT(player)->player.hold_presses;
		OBJECT(player)->player.hold_presses = hold_presses - 1u;
		if (hold_presses == 1u)
		{
			effect_state = 0xD00u;
			player_start_effect(kind, player, effect_state);
			OBJECT(holder)->grabber.squeeze_step = 0u;
			OBJECT(player)->player.hold_presses = 0u;
			OBJECT(player)->flags = 0x80u;
			OBJECT(player)->player.player_state = 0x3Bu;
			player_keep_life(player);
			return;
		}
	}
	player_keep_life(player);
}

/* Held and hit: waits for its holder's animation to end, then is held again. */
void player_grabbed_and_hit(uint16_t kind, uint16_t player)
{
	uint16_t grabber = 0;
	uint8_t animation_flags = 0;
	uint16_t holder = 0;

	holder = OBJECT(player)->player.holder;
	grabber = holder;
	animation_flags = OBJECT(grabber)->animation_flags;
	if ((animation_flags & 1u) == 0u)
	{
		player_struggle(grabber, kind, player);
		return;
	}
	OBJECT(player)->flags = 0xC0u;
	OBJECT(player)->player.player_state = 0x1Cu;
	player_struggle(grabber, kind, player);
}

/* Freed from a hold: standing again. */
void player_escape(uint16_t player)
{
	OBJECT(player)->flags = 0xC0u;
	OBJECT(player)->animation = 0x80u;
	OBJECT(player)->player.player_state = 0u;
	player_keep_life(player);
}

/* Knocked up into the air: crashes into the screen's edge, or lands on its feet, bounces away, or falls
   down. */
void player_knocked_up(uint16_t kind, uint16_t player)
{
	uint32_t zero = 0, below_floor = 0, compare_overflow = 0, carry = 0;
	uint8_t animation = 0, animation_number = 0, state_value = 0, x_speed_high = 0;
	uint16_t place_x = 0, state_and_time = 0, x_speed = 0;
	uint8_t x_speed_2 = 0, player_state = 0, x_low = 0, player_state_2 = 0;
	uint16_t z_speed = 0, falling_z_speed = 0, floor_z = 0, player_x = 0;

	player_next_height_against_floor(player, &zero, &below_floor, &compare_overflow);
	if (((below_floor ^ compare_overflow) | zero) == 0u)
	{
		z_speed = OBJECT(player)->z_speed;
		falling_z_speed = z_speed - 0x60u;
		OBJECT(player)->z_speed = falling_z_speed;
		player_check_screen_edges(player, &zero, &carry);
		if (zero)
		{
			player_keep_life(player);
			return;
		}
		player_crash_into_edge(player);
		return;
	}
	floor_z = OBJECT(player)->floor_z;
	OBJECT(player)->z = floor_z;
	OBJECT(player)->z_fraction = 0u;
	player_set_on_floor(player);
	OBJECT(player)->z_speed = 0;
	x_speed_2 = (uint8_t)(OBJECT(player)->x_speed >> 8u);
	x_speed_high = x_speed_2;
	OBJECT(player)->x_speed = 0;
	player_state = OBJECT(player)->player.player_state;
	state_value = player_state;
	if (state_value == 0x18u)
	{
		player_x = OBJECT(player)->x;
		place_x = player_x;
		if ((int16_t)place_x < 0x140 && (int16_t)place_x > 0x70)
		{
			x_low = (uint8_t)OBJECT(player)->x;
			state_value = x_low;
			if ((state_value & 1u) == 0u)
			{
				player_end_state(kind, player);
				return;
			}
		}
	}
	if ((state_value & 2u) == 0u)
	{
		player_fall_down(player);
		return;
	}
	x_speed = 0x400u;
	if (x_speed_high == 0u)
	{
		player_fall_down(player);
		return;
	}
	if ((int8_t)x_speed_high < 0)
		x_speed = 0xFC00u;
	OBJECT(player)->x_speed = x_speed;
	state_and_time = 0x1420u;
	animation_number = 0xD3u;
	player_state_2 = OBJECT(player)->player.player_state;
	if (player_state_2 != 0x19u)
		state_and_time = 0x1408u;
	animation = animation_number;
	player_set_floor_state(state_and_time, player, animation);
}

/* Crashes into the screen's edge: sound 1B, state 17 (animation D6). */
void player_crash_into_edge(uint16_t player)
{
	uint16_t command = 0;

	command = 0x1B00u;
	vector_queue_sound(command);
	OBJECT(player)->animation = 0xD6u;
	OBJECT(player)->player.player_state = 0x17u;
	OBJECT(player)->player.state_timer = 0x20u;
	OBJECT(player)->z_speed = 0;
	player_keep_life(player);
}

/* Falls down where it is (state 15, animation D4). */
void player_fall_down(uint16_t player)
{
	uint8_t animation = 0;
	uint16_t state_and_time = 0;

	OBJECT(player)->x_speed = 0;
	state_and_time = 0x1500u;
	animation = 0xD4u;
	player_set_floor_state(state_and_time, player, animation);
}

/* Puts the player on the floor and sets the state in Y with animation B. */
void player_set_floor_state(uint16_t state_and_time, uint16_t player, uint8_t animation)
{
	uint16_t floor_z = 0;

	player_set_on_floor(player);
	floor_z = OBJECT(player)->floor_z;
	OBJECT(player)->z = floor_z;
	OBJECT(player)->z_fraction = 0u;
	player_set_state(state_and_time, player, animation);
}

/* Sets the player's state and timer (Y) and animation (B), no height speed, its box back to its body,
   and moves it. */
void player_set_state(uint16_t state_and_time, uint16_t player, uint8_t animation)
{
	OBJECT(player)->animation = animation;
	OBJECT(player)->player.player_state = (uint8_t)(state_and_time >> 8u);
	OBJECT(player)->player.state_timer = (uint8_t)state_and_time;
	OBJECT(player)->z_speed = 0;
	OBJECT(player)->player.state_frames = 1u;
	OBJECT(player)->player.teamed = 0u;
	player_reset_box(player);
	player_check_motion(player);
}

/* Lies down where it is (state 16, animation D5), its count of blows cleared. */
void player_lie_down(uint16_t player)
{
	uint8_t animation = 0;
	uint16_t state_and_time = 0;

	OBJECT(player)->x_speed = 0;
	OBJECT(player)->player.blows_taken = 0u;
	state_and_time = 0x1600u;
	animation = 0xD5u;
	player_set_floor_state(state_and_time, player, animation);
}

/* The player's life is gone: drops what it carries, sound 1A, the rank's step back to 0; it loses a life
   (state 1F), or on its last life starts the game-over sprite rising above it (state 20). */
void player_die(uint16_t player)
{
	uint8_t lives_low = 0;
	uint16_t command = 0, effect_state = 0, held_object = 0, kind = 0, player_vars = 0, raised_y = 0, z = 0;
	uint8_t held_high = 0, held_attack = 0;
	uint16_t held = 0, lives_address = 0, lives_word = 0, running_values = 0, player_x = 0, player_y = 0, z_2 = 0;

	held = OBJECT(player)->player.held;
	held_object = held;
	if (held != 0u)
	{
		held_high = (uint8_t)(OBJECT(player)->player.held >> 8u);
		if (held_high != 0u)
		{
			OBJECT(player)->player.held = 0u;
			held_attack = OBJECT(held_object)->attack;
			if (held_attack != 0xFEu)
			{
				OBJECT(held_object)->x_speed = 0;
				OBJECT(held_object)->y_speed = 0;
				OBJECT(held_object)->state = 6u;
			}
		}
	}
	player_stop(player);
	command = 0x1A00u;
	vector_queue_sound(command);
	rank_time_step = 0u;
	lives_address = io_read16(running_player_values);
	lives_word = mem_read16(lives_address);
	lives_low = (uint8_t)lives_word;
	if ((uint16_t)(((uint32_t)(lives_word >> 8) << 8) | (lives_low & 0xFFu)) != 1u)
	{
		OBJECT(player)->animation = 0xDFu;
		OBJECT(player)->player.player_state = 0x1Fu;
		OBJECT(player)->player.state_timer = 0x78u;
		player_keep_life(player);
		return;
	}
	running_values = io_read16(running_player_values);
	player_vars = running_values;
	PLAYER_VALUES(player_vars)->grab_hints = 0u;
	OBJECT(player)->animation = 0xCEu;
	kind = 0x2E0u;
	effect_state = (lives_low & 0xFFu) | 0xB00u;
	player_start_effect(kind, player, effect_state);
	player_x = OBJECT(player)->x;
	OBJECT(player + 0x60u)->x = player_x;
	player_y = OBJECT(player)->y;
	raised_y = player_y - 0x50u;
	OBJECT(player)->y = raised_y;
	OBJECT(player + 0x60u)->y = raised_y + 0x10u;
	z_2 = OBJECT(player)->z;
	z = z_2 + 0x50u;
	OBJECT(player)->z = z;
	OBJECT(player + 0x60u)->z = z;
	OBJECT(player)->player.player_state = 0x20u;
	OBJECT(player)->player.state_timer = 0x52u;
	player_keep_life(player);
}

/* Losing a life: blinks, vanishes, then takes a life off its record, clears the rank's counts and has it
   join again. */
void player_lose_life(uint16_t player)
{
	uint8_t timer_value = 0;
	uint16_t player_vars = 0;
	uint8_t state_timer = 0, state_timer_2 = 0;
	uint16_t running_values = 0, lives_address = 0;

	state_timer = OBJECT(player)->player.state_timer;
	OBJECT(player)->player.state_timer = state_timer - 1u;
	if (state_timer == 1u)
	{
		camera_wait_frames = 0u;
		rank_frames = 0u;
		running_values = io_read16(running_player_values);
		player_vars = running_values;
		PLAYER_VALUES(player_vars)->entry_status = 0u;
		OBJECT(player)->player.status = 0u;
		lives_address = io_read16(running_player_values);
		mem_write16(lives_address, mem_read16(lives_address) - 1u);
		player_keep_life(player);
		return;
	}
	state_timer_2 = OBJECT(player)->player.state_timer;
	timer_value = state_timer_2;
	if (timer_value == 0x1Eu)
	{
		OBJECT(player)->flags = 0u;
		player_keep_life(player);
		return;
	}
	if ((int8_t)(timer_value - 0x1Eu) < 0 || (int8_t)timer_value >= 0x50)
	{
		player_keep_life(player);
		return;
	}
	player_blink(player);
	player_keep_life(player);
}

/* On its last life: when the second sprite's animation ends, gives it animation E4 (state 21). */
void player_game_over_start(uint16_t player)
{
	uint16_t kind = 0;
	uint8_t animation_flags = 0, player_state = 0;

	animation_flags = OBJECT(player + 0x60u)->animation_flags;
	if (animation_flags & 1u)
	{
		kind = 0x2E4u;
		OBJECT(player + 0x60u)->kind = (uint8_t)(kind >> 8u);
		OBJECT(player + 0x60u)->animation = (uint8_t)kind;
		player_state = OBJECT(player)->player.player_state;
		OBJECT(player)->player.player_state = player_state + 1u;
	}
	player_blink(player);
	player_keep_life(player);
}

/* When its timer runs out, gives the second sprite animation E8 (state 22). */
void player_game_over_rise(uint16_t player)
{
	uint8_t state_timer = 0, player_state = 0;

	state_timer = OBJECT(player)->player.state_timer;
	OBJECT(player)->player.state_timer = state_timer - 1u;
	if (state_timer == 1u)
	{
		OBJECT(player + 0x60u)->kind = 2u;
		OBJECT(player + 0x60u)->animation = 0xE8u;
		player_state = OBJECT(player)->player.player_state;
		OBJECT(player)->player.player_state = player_state + 1u;
	}
	player_blink(player);
	player_keep_life(player);
}

/* When the second sprite's animation ends, the player and the sprite are gone and its last life is taken
   off. */
void player_game_over_end(uint16_t player)
{
	uint16_t player_vars = 0;
	uint8_t animation_flags = 0;
	uint16_t game_over_values = 0, running_values = 0, lives_address = 0;

	animation_flags = OBJECT(player + 0x60u)->animation_flags;
	if ((animation_flags & 1u) == 0u)
	{
		player_keep_life(player);
		return;
	}
	game_over_values = io_read16(running_player_values);
	player_vars = game_over_values;
	PLAYER_VALUES(player_vars)->entry_status = 0u;
	OBJECT(player + 0x60u)->flags = 0u;
	OBJECT(player)->flags = 0u;
	camera_wait_frames = 0u;
	rank_frames = 0u;
	running_values = io_read16(running_player_values);
	player_vars = running_values;
	PLAYER_VALUES(player_vars)->entry_status = 0u;
	OBJECT(player)->player.status = 0u;
	lives_address = io_read16(running_player_values);
	mem_write16(lives_address, mem_read16(lives_address) - 1u);
	player_keep_life(player);
}

/* Joining with a leap in from the left: rises while its x speed falls off, then falls (state 27); a wall
   on the way crashes it. */
void player_jump_in(uint16_t player)
{
	uint16_t x_speed = 0;
	uint8_t player_state = 0, attributes = 0;
	uint16_t z_speed = 0, x_speed_2 = 0, player_x = 0;

	player_set_in_air(player);
	z_speed = OBJECT(player)->z_speed;
	OBJECT(player)->z_speed = z_speed + 8u;
	x_speed_2 = OBJECT(player)->x_speed;
	x_speed = x_speed_2 - 0x70u;
	OBJECT(player)->x_speed = x_speed;
	if ((int16_t)x_speed >= 0)
	{
		player_x = OBJECT(player)->x;
		if ((int16_t)player_x >= 0x72)
		{
			player_entry_crash(player);
			return;
		}
		player_keep_life(player);
		return;
	}
	player_state = OBJECT(player)->player.player_state;
	OBJECT(player)->player.player_state = player_state + 1u;
	OBJECT(player)->animation = 0xBBu;
	attributes = OBJECT(player)->attributes;
	OBJECT(player)->attributes = (uint16_t)((((uint16_t)((uint32_t)attributes << 8) >> 8) | 0x40u) << 8) >> 8;
	player_entry_crash(player);
}

/* Joining, falling to the floor (from the leap, or from above in scenes 4 and 0B). */
void player_drop_in(uint16_t player)
{
	uint32_t at_floor = 0, below_floor = 0, compare_overflow = 0;
	uint16_t old_x_speed = 0;
	uint16_t z_speed = 0, x_speed = 0;

	player_set_in_air(player);
	player_next_height_against_floor(player, &at_floor, &below_floor, &compare_overflow);
	if ((below_floor ^ compare_overflow) | at_floor)
	{
		player_entry_land(player);
		return;
	}
	z_speed = OBJECT(player)->z_speed;
	OBJECT(player)->z_speed = z_speed - 0x60u;
	x_speed = OBJECT(player)->x_speed;
	old_x_speed = x_speed;
	if ((int16_t)old_x_speed <= -0x300)
	{
		player_entry_crash(player);
		return;
	}
	OBJECT(player)->x_speed = old_x_speed - 0x60u;
	player_entry_crash(player);
}

/* A joining player that meets a wall crashes into it (sound 1B, state 28, animation D6). */
void player_entry_crash(uint16_t player)
{
	uint32_t zero = 0, blocked_ahead = 0;
	uint8_t animation = 0;
	uint16_t command = 0, state_and_time = 0;

	player_check_screen_edges(player, &zero, &blocked_ahead);
	if (blocked_ahead == 0u)
	{
		player_keep_life(player);
		return;
	}
	OBJECT(player)->z_speed = 0;
	OBJECT(player)->damage = 0u;
	OBJECT(player)->attack = 0u;
	command = 0x1B00u;
	vector_queue_sound(command);
	state_and_time = 0x2820u;
	animation = 0xD6u;
	player_set_state(state_and_time, player, animation);
}

/* A joining player lands: standing, blinking and safe for 120 frames. */
void player_entry_land(uint16_t player)
{
	uint16_t floor_z = 0;

	OBJECT(player)->x_speed = 0;
	OBJECT(player)->z_speed = 0;
	floor_z = OBJECT(player)->floor_z;
	OBJECT(player)->z = floor_z;
	OBJECT(player)->z_fraction = 0u;
	player_start_blinking(player);
	OBJECT(player)->player.player_state = 0u;
	OBJECT(player)->damage = 0u;
	OBJECT(player)->attack = 0u;
	OBJECT(player)->animation = 0x80u;
	player_keep_life(player);
}

/* State 25: nothing but keeping its life in the record. */
void player_idle(uint16_t player)
{
	player_keep_life(player);
}

/* Holds the pose a blow of strength 0C gave it until its timer runs out. */
void player_hold_pose(uint16_t kind, uint16_t player)
{
	uint8_t state_timer = 0;

	state_timer = OBJECT(player)->player.state_timer;
	OBJECT(player)->player.state_timer = state_timer - 1u;
	if (state_timer != 1u)
	{
		player_take_touches(kind, player);
		return;
	}
	player_end_state(kind, player);
}

/* At a heavy object that takes two (strength FE): each attack works at it (its field 28 to 2), and after
   3 the player counts in 184D, where bank 1F lifts it once two have (state 2D); a direction or jump lets
   go. */
void player_work_heavy_object(uint16_t kind, uint16_t player)
{
	uint8_t first_animation = 0;
	uint16_t held_object = 0, left_of_held = 0;
	uint8_t controls = 0, heavy_object_presses = 0, heavy_workers = 0, controls_pressed = 0, heavy_object_presses_2 = 0;
	uint16_t held = 0;

	controls = OBJECT(player)->player.controls;
	if ((controls & 0x2Fu) != 0u)
	{
		OBJECT(player)->player.held = 0u;
		OBJECT(player)->player.heavy_object_presses = 0u;
		player_set_standing(player);
		return;
	}
	heavy_object_presses = OBJECT(player)->player.heavy_object_presses;
	if ((int8_t)heavy_object_presses >= 3)
	{
		heavy_workers = io_read8(heavy_object_workers);
		io_write8(heavy_object_workers, heavy_workers + 1u);
		player_take_touches(kind, player);
		return;
	}
	controls_pressed = OBJECT(player)->player.controls_pressed;
	if ((controls_pressed & 0x10u) == 0u)
	{
		player_take_touches(kind, player);
		return;
	}
	held = OBJECT(player)->player.held;
	held_object = held;
	OBJECT(held_object)->action = 2u;
	first_animation = 0xC9u;
	left_of_held = player_face_heavy_object(player, first_animation);
	heavy_object_presses_2 = OBJECT(player)->player.heavy_object_presses;
	OBJECT(player)->player.heavy_object_presses = heavy_object_presses_2 + 1u;
	player_take_touches(left_of_held, player);
}

/* A pair just teamed up waits for either's input to start (state 31, the pair's balloon in scene 0); a
   jump or a stage's end undoes it. */
void player_team_ready(uint16_t animation_offsets, uint16_t player)
{
	uint8_t animation_base = 0, animation_offset = 0, attack_state = 0, owner_kind = 0, pressed_either = 0;
	uint16_t effect_state = 0, kind = 0, player_z = 0, teammate = 0;
	uint8_t stage_is_over = 0, controls_pressed = 0, partner_pressed = 0, team_move_number = 0, team_move_number_2 = 0, kind_2 = 0, animation_entry = 0, kind_3 = 0, kind_4 = 0, team_move_number_3 = 0, team_move_number_4 = 0;
	uint16_t partner = 0, z = 0, floor_z = 0, partner_2 = 0, action = 0, z_2 = 0, floor_z_2 = 0;
	uint32_t action_halfword = 0;

	partner = OBJECT(player)->player.partner;
	teammate = partner;
	stage_is_over = io_read8(players_stop_request);
	if (stage_is_over != 0u)
	{
		player_team_split(teammate, player);
		OBJECT(teammate)->flags = 0xC0u;
		player_stand(animation_offsets, player);
		return;
	}
	z = OBJECT(player)->z;
	floor_z = OBJECT(player)->floor_z;
	if ((int16_t)floor_z < (int16_t)z)
	{
		player_team_split(teammate, player);
		OBJECT(teammate)->flags = 0xC0u;
		player_stand(animation_offsets, player);
		return;
	}
	controls_pressed = OBJECT(player)->player.controls_pressed;
	partner_pressed = OBJECT(teammate)->player.controls_pressed;
	pressed_either = controls_pressed | partner_pressed;
	if ((pressed_either & 0x20u) != 0u)
	{
		player_team_split(teammate, player);
		OBJECT(teammate)->flags = 0xC0u;
		player_stand(animation_offsets, player);
		return;
	}
	if ((pressed_either & 0x1Fu) == 0u)
	{
		player_take_touches(animation_offsets, player);
		return;
	}
	team_move_number = OBJECT(player)->player.team_move_number;
	if ((int8_t)team_move_number < 2 && scene == 0u)
	{
		OBJECT(player + 0x60u)->player.blink_frames = 0u;
		kind = 0xB180u;
		effect_state = 0x300u;
		player_start_effect(kind, player, effect_state);
	}
	OBJECT(player)->player.voice_timer = 3u;
	OBJECT(player)->player.player_state = 0x31u;
	animation_base = 0xE4u;
	for (;;)
	{
		team_animation_base = animation_base;
		animation_offsets = team_move_animation_offsets_ADDRESS;
		team_move_number_2 = OBJECT(player)->player.team_move_number;
		kind_2 = OBJECT(player)->kind;
		animation_entry = team_move_animation_offsets[(int8_t)((uint8_t)((((uint32_t)team_move_number_2 << 1) << 1) + kind_2))];
		animation_offset = animation_entry;
		if ((int8_t)animation_entry >= 0)
			OBJECT(player)->animation = animation_offset + team_animation_base;
		partner_2 = OBJECT(player)->player.partner;
		teammate = partner_2;
		player_team_follow(teammate, player);
		kind_3 = OBJECT(teammate)->kind;
		owner_kind = kind_3;
		if ((int8_t)random_number < 0)
		{
			kind_4 = OBJECT(player)->kind;
			owner_kind = kind_4;
		}
		OBJECT(player)->shadow_player = ((((uint32_t)owner_kind << 1) << 1) << 1) << 1;
		action = (((uint32_t)OBJECT(player)->action << 8u) | OBJECT(player)->action_step);
		action_halfword = action - 1u;
		OBJECT(player)->action = (uint8_t)(action_halfword >> 8u);
		OBJECT(player)->action_step = (uint8_t)action_halfword;
		if (action != 1u)
		{
			player_take_touches(animation_offsets, player);
			return;
		}
		team_move_number_3 = OBJECT(player)->player.team_move_number;
		if (team_move_number_3 != 2u)
			break;
		team_move_number_4 = OBJECT(player)->player.team_move_number;
		attack_state = team_move_attack_states[(int8_t)team_move_number_4];
		OBJECT(player)->player.attack_started = attack_state;
		OBJECT(player)->damage = 0xCu;
		OBJECT(player)->attack = 0x13u;
		z_2 = OBJECT(player)->z;
		player_z = z_2;
		floor_z_2 = OBJECT(player)->floor_z;
		if ((int16_t)floor_z_2 < (int16_t)player_z)
		{
			player_start_jump_attack(player_z, player);
			animation_base = 0xFCu;
		}
		else
		{
			OBJECT(player)->x_speed = 0;
			OBJECT(player)->y_speed = 0;
			animation_base = 0xF8u;
		}
		OBJECT(player)->player.player_state = attack_state;
	}
	player_team_split(teammate, player);
	OBJECT(teammate)->flags = 0xC0u;
	OBJECT(player)->x_speed = 0;
	OBJECT(teammate)->x_speed = 0;
	OBJECT(player)->y_speed = 0;
	OBJECT(teammate)->y_speed = 0;
	player_take_touches(animation_offsets, player);
}

/* Starts the team move: 480 frames for both, then moving together. */
void player_team_start(uint16_t player)
{
	uint16_t teammate = 0;
	uint16_t partner = 0;

	partner = OBJECT(player)->player.partner;
	teammate = partner;
	OBJECT(player)->action = 1u;
	OBJECT(player)->action_step = 0xE0u;
	OBJECT(teammate)->action = 1u;
	OBJECT(teammate)->action_step = 0xE0u;
	player_team_resume(player);
}

/* Back to moving together with its partner. */
void player_team_resume(uint16_t player)
{
	player_team_together(player);
}

/* Moving together (state 32) on the floor: the partner follows; when the 480 frames run out the pair
   splits (a Marge-and-kid pair attacks first). */
void player_team_together(uint16_t player)
{
	uint8_t animation_base = 0, animation_offset = 0, attack_state = 0, owner_kind = 0;
	uint16_t animation_offsets = 0, player_z = 0, teammate = 0;
	uint8_t team_move_number = 0, team_move_number_2 = 0, kind = 0, animation_entry = 0, kind_2 = 0, kind_3 = 0, team_move_number_3 = 0, team_move_number_4 = 0;
	uint16_t floor_z = 0, partner = 0, action = 0, z = 0, floor_z_2 = 0;
	uint32_t action_halfword = 0;

	floor_z = OBJECT(player)->floor_z;
	animation_offsets = floor_z;
	OBJECT(player)->z = animation_offsets;
	OBJECT(player)->z_fraction = 0u;
	player_stop(player);
	OBJECT(player)->timer = 0u;
	OBJECT(player)->player.attack_started = 0u;
	OBJECT(player)->player.player_state = 0x32u;
	team_move_number = OBJECT(player)->player.team_move_number;
	if (team_move_number != 0u)
	{
		animation_base = 0xECu;
		team_animation_base = animation_base;
		animation_offsets = team_move_animation_offsets_ADDRESS;
		team_move_number_2 = OBJECT(player)->player.team_move_number;
		kind = OBJECT(player)->kind;
		animation_entry = team_move_animation_offsets[(int8_t)((uint8_t)((((uint32_t)team_move_number_2 << 1) << 1) + kind))];
		animation_offset = animation_entry;
		if ((int8_t)animation_entry >= 0)
			OBJECT(player)->animation = animation_offset + team_animation_base;
	}
	for (;;)
	{
		partner = OBJECT(player)->player.partner;
		teammate = partner;
		player_team_follow(teammate, player);
		kind_2 = OBJECT(teammate)->kind;
		owner_kind = kind_2;
		if ((int8_t)random_number < 0)
		{
			kind_3 = OBJECT(player)->kind;
			owner_kind = kind_3;
		}
		OBJECT(player)->shadow_player = ((((uint32_t)owner_kind << 1) << 1) << 1) << 1;
		action = (((uint32_t)OBJECT(player)->action << 8u) | OBJECT(player)->action_step);
		action_halfword = action - 1u;
		OBJECT(player)->action = (uint8_t)(action_halfword >> 8u);
		OBJECT(player)->action_step = (uint8_t)action_halfword;
		if (action != 1u)
		{
			player_take_touches(animation_offsets, player);
			return;
		}
		team_move_number_3 = OBJECT(player)->player.team_move_number;
		if (team_move_number_3 != 2u)
			break;
		team_move_number_4 = OBJECT(player)->player.team_move_number;
		attack_state = team_move_attack_states[(int8_t)team_move_number_4];
		OBJECT(player)->player.attack_started = attack_state;
		OBJECT(player)->damage = 0xCu;
		OBJECT(player)->attack = 0x13u;
		z = OBJECT(player)->z;
		player_z = z;
		floor_z_2 = OBJECT(player)->floor_z;
		if ((int16_t)floor_z_2 < (int16_t)player_z)
		{
			player_start_jump_attack(player_z, player);
			animation_base = 0xFCu;
		}
		else
		{
			OBJECT(player)->x_speed = 0;
			OBJECT(player)->y_speed = 0;
			animation_base = 0xF8u;
		}
		OBJECT(player)->player.player_state = attack_state;
		team_animation_base = animation_base;
		animation_offsets = team_move_animation_offsets_ADDRESS;
		team_move_number_2 = OBJECT(player)->player.team_move_number;
		kind = OBJECT(player)->kind;
		animation_entry = team_move_animation_offsets[(int8_t)((uint8_t)((((uint32_t)team_move_number_2 << 1) << 1) + kind))];
		animation_offset = animation_entry;
		if ((int8_t)animation_entry < 0)
			continue;
		OBJECT(player)->animation = animation_offset + team_animation_base;
	}
	player_team_split(teammate, player);
	OBJECT(teammate)->flags = 0xC0u;
	OBJECT(player)->x_speed = 0;
	OBJECT(teammate)->x_speed = 0;
	OBJECT(player)->y_speed = 0;
	OBJECT(teammate)->y_speed = 0;
	player_take_touches(animation_offsets, player);
}

/* Sets the player's walking or standing animation by what it holds (a weapon's or a carried object's set
   of animations) and carries the object above it, bobbing; at a stage's end what it carries is removed. */
void player_set_animation(uint16_t carry_offsets, uint16_t player, uint8_t base_animation)
{
	uint8_t animation = 0, animation_offset = 0, dx = 0, facing_left = 0, height = 0, status = 0;
	uint16_t dropped_object = 0, height_address = 0, held_object = 0;
	uint8_t offset_or_facing = 0;
	uint8_t held_high = 0, weapon_kind = 0, stage_is_over = 0, kind = 0, team_stop_request = 0, kind_3 = 0, carry_stop_request = 0, dropped_high = 0, kind_4 = 0, kind_5 = 0, attributes = 0, facing_left_bit = 0, attributes_2 = 0, animation_flags = 0, status_2 = 0;
	uint16_t held = 0, kind_2 = 0, held_look = 0, held_2 = 0, kind_offsets = 0, dx_word = 0, player_x = 0, carried_x = 0;

	animation = (uint8_t)base_animation;
	held = OBJECT(player)->player.held;
	held_object = held;
	if (held == 0u)
	{
		OBJECT(player)->animation = animation;
		player_take_touches(carry_offsets, player);
		return;
	}
	held_high = (uint8_t)(OBJECT(player)->player.held >> 8u);
	if (held_high == 0u)
	{
		weapon_kind = (uint8_t)OBJECT(player)->player.held;
		offset_or_facing = (((weapon_kind - 3u) << 1) << 1) << 1;
		OBJECT(player)->animation = animation + offset_or_facing;
		stage_is_over = io_read8(players_stop_request);
		if (stage_is_over != 0u)
		{
			player_drop_held(held_object, player);
			return;
		}
		player_take_touches(carry_offsets, player);
		return;
	}
	kind = OBJECT(player)->kind;
	if (kind == 1u)
	{
		offset_or_facing = animation;
		kind_2 = (((uint32_t)OBJECT(held_object)->kind << 8u) | OBJECT(held_object)->animation);
		held_look = ((uint32_t)(kind_2 >> 8) << 8) | (kind_2 & 0x7Eu);
		animation = offset_or_facing;
		if (held_look == 0x41Au)
		{
			OBJECT(player)->animation = animation + 0x61u;
			player_team_follow(held_object, player);
			team_stop_request = io_read8(players_stop_request);
			if (team_stop_request != 0u)
			{
				player_drop_held(held_object, player);
				return;
			}
			player_take_touches(carry_offsets, player);
			return;
		}
	}
	kind_3 = OBJECT(held_object)->kind;
	animation_offset = (((kind_3 - 3u) << 1) << 1) << 1;
	offset_or_facing = animation_offset;
	OBJECT(player)->animation = animation + offset_or_facing;
	carry_stop_request = io_read8(players_stop_request);
	if (carry_stop_request != 0u)
	{
		held_2 = OBJECT(player)->player.held;
		dropped_object = held_2;
		if (held_2 != 0u)
		{
			dropped_high = (uint8_t)(OBJECT(player)->player.held >> 8u);
			if (dropped_high != 0u)
			{
				OBJECT(dropped_object)->flags = 0u;
				OBJECT(player)->player.held = 0u;
			}
		}
		player_break_team(player);
		return;
	}
	kind_4 = OBJECT(player)->kind;
	kind_5 = OBJECT(player)->kind;
	kind_offsets = carry_offsets + (int8_t)(animation_offset + kind_4 + kind_5);
	height_address = kind_offsets + 1u;
	dx = mem_read8(kind_offsets);
	attributes = OBJECT(player)->attributes;
	facing_left_bit = attributes & 0x40u;
	facing_left = facing_left_bit;
	if (facing_left_bit != 0u)
		dx = 0u - dx;
	offset_or_facing = facing_left;
	attributes_2 = OBJECT(held_object)->attributes;
	OBJECT(held_object)->attributes = (attributes_2 & 0xBFu) | offset_or_facing;
	dx_word = (int8_t)dx;
	player_x = OBJECT(player)->x;
	carried_x = dx_word + player_x;
	OBJECT(held_object)->x = carried_x;
	animation_flags = OBJECT(player)->animation_flags;
	status_2 = OBJECT(player)->player.status;
	status = ((animation_flags & 2u) >> 1) ^ status_2;
	OBJECT(player)->player.status = status;
	height = (uint8_t)(status + mem_read8(height_address));
	player_place_carried_above(held_object, player, height);
	player_take_touches(height_address, player);
}
