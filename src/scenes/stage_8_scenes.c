/**
 *    Name:        scenes/stage_8_scenes.c
 *    Description: stage 8's opening and the scene after its last boss
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    11-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the game's 053248 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

/* Stage 8's opening: stops the sound, loads its colours and clears the screen. */
void stage_8_start_set_up(uint16_t *p_x, uint16_t *p_u)
{
	uint16_t u = (uint16_t)*p_u;
	uint16_t command = 0, ignored16 = 0, job = 0, request = 0, scroll_x = 0, scroll_y = 0, u_2 = 0, x = 0;
	uint8_t old_scene_state = 0;

	job = 0u;
	vector_queue_job(job);
	command = 0u;
	vector_queue_sound_always(command);
	palette_request_kind = 1u;
	request = 0xE91u;
	vector_palette_request(u, request);
	scroll_x = 0xFFF0u;
	vector_set_scroll_x(scroll_x);
	scroll_y = 0u;
	layer_b_scroll_x = 0u;
	vector_set_scroll_y(scroll_y);
	layer_b_scroll_y = 0x100u;
	layer_b_edges_on = 1u;
	layer_rows_on = 1u;
	vector_clear_objects(&ignored16, &u_2);
	x = vector_clear_sprites();
	old_scene_state = io_read8(scene_state);
	io_write8(scene_state, old_scene_state + 1u);
	*p_x = x;
	*p_u = u_2;
}

/* Stage 8's opening: the power plant's area 0, the kind-A4 objects, the kind-13 object and the players
   who played, then the music (9600). */
void stage_8_start_show(uint16_t *p_default_object, uint16_t *p_u)
{
	uint16_t default_object = (uint16_t)*p_default_object;
	uint16_t u = (uint16_t)*p_u;
	uint16_t command = 0, ignored16 = 0, ignored16_2 = 0, layer_and_columns = 0, object = 0, record_number = 0, rider_record = 0, u_2 = 0;
	uint8_t riders_left = 0, old_scene_state = 0;

	if (layer_clear_pending != 0u)
		return;
	io_write8(colour_bases_back_sprites_fixed, 0x3Fu);
	io_write8(colour_bases_layers_a_b, 0x36u);
	map_scene = 0x8Du;
	map_area = 0u;
	vector_set_layer_modes();
	layer_and_columns = 0x26u;
	vector_draw_layer_strips(layer_and_columns, &ignored16, &ignored16_2);
	layer_and_columns = 0x126u;
	vector_draw_layer_strips(layer_and_columns, &default_object, &u_2);
	io_write8(colour_bases_back_sprites_fixed, 0x13u);
	io_write8(colour_bases_layers_a_b, 0x2Cu);
	record_number = 0x2E26u;
	scene_put_placement(default_object, record_number);
	record_number = 0x2F26u;
	scene_put_placement(default_object, record_number);
	record_number = 0x3026u;
	object = scene_put_placement(default_object, record_number);
	OBJECT(object)->flags |= 8u;
	OBJECT(object)->shadow_player = 1u;
	record_number = 0x3126u;
	scene_put_placement(default_object, record_number);
	rider_record = 0x3226u;
	object = scene_put_placement(default_object, rider_record);
	leftover_y = object;
	OBJECT(leftover_y)->attributes = 0x10u;
	scene_riders_left = 4u;
	rider_bits = players_present;
	rider_kind = 0x2Au;
	do
	{
		if ((rider_bits & 1u) != 0u)
		{
			rider_record = (rider_record & 0xFFu) | ((uint32_t)rider_kind << 8);
			object = scene_put_placement(default_object, rider_record);
			leftover_y = object;
			OBJECT(leftover_y)->flags |= 8u;
			OBJECT(leftover_y)->action = scene_riders_left * 0x10u + 0x10u;
		}
		rider_bits = rider_bits >> 1;
		rider_kind++;
		riders_left = scene_riders_left;
		scene_riders_left = riders_left - 1u;
	} while (riders_left != 1u);
	command = 0x9600u;
	vector_queue_sound(command);
	io_write16(scene_layer_b_speed, 0x400u);
	old_scene_state = io_read8(scene_state);
	io_write8(scene_state, old_scene_state + 1u);
	*p_default_object = default_object;
	*p_u = u_2;
}

/* Stage 8's opening: the view goes down, slowing, the players with it; at the bottom one of the kind-A4
   objects turns into the kind-9C character and jumps out. */
void stage_8_start_descend(uint16_t *p_object, uint16_t *p_player_states)
{
	uint16_t player_states = (uint16_t)*p_player_states;
	uint32_t carry = 0;
	uint16_t descent_speed = 0, ignored16 = 0, object = 0, scroll_y_low = 0;
	uint8_t old_scene_state = 0, objects_left = 0;
	uint16_t old_descent_speed = 0, descent_step = 0, object_speed = 0;
	uint32_t layer_b_scroll_y_halfword = 0;

	stage_8_start_run_players(&ignored16, &player_states);
	old_descent_speed = io_read16(scene_layer_b_speed);
	descent_speed = old_descent_speed - 9u;
	if ((int16_t)descent_speed <= 9)
		descent_speed = 9u;
	io_write16(scene_layer_b_speed, descent_speed);
	scroll_y_low = (((uint32_t)(layer_b_scroll_y & 0xFFu) << 8u) | layer_b_scroll_y_fraction);
	descent_step = io_read16(scene_layer_b_speed);
	carry = scroll_y_low < descent_step;
	layer_b_scroll_y_halfword = scroll_y_low - descent_step;
	layer_b_scroll_y = (layer_b_scroll_y & 0xFF00u) | ((layer_b_scroll_y_halfword >> 8u) & 0xFFu);
	layer_b_scroll_y_fraction = (uint8_t)layer_b_scroll_y_halfword;
	layer_b_scroll_y = (layer_b_scroll_y & 0xFFu) | (((uint16_t)((uint32_t)(uint8_t)(((uint16_t)((uint32_t)(uint8_t)(layer_b_scroll_y >> 8u) << 8) >> 8) - carry) << 8) >> 8 & 0xFFu) << 8u);
	if ((int16_t)layer_b_scroll_y <= 0x20)
	{
		OBJECT(OBJECT_ADDRESS(26))->kind = 0x9Cu;
		OBJECT(OBJECT_ADDRESS(26))->animation = 0x83u;
		OBJECT(OBJECT_ADDRESS(26))->x_speed = 0x300;
		OBJECT(OBJECT_ADDRESS(26))->z_speed = 0x200;
		io_write16(scene_wait, 0x80u);
		layer_b_scroll_y = 0x20u;
		layer_b_scroll_y_fraction = 0u;
		old_scene_state = io_read8(scene_state);
		io_write8(scene_state, old_scene_state + 1u);
	}
	object = OBJECT_ADDRESS(26);
	scene_objects_left = 4u;
	do
	{
		object_speed = io_read16(scene_layer_b_speed);
		OBJECT(object)->z_speed = 0u - object_speed;
		object += 0x60u;
		objects_left = scene_objects_left;
		scene_objects_left = objects_left - 1u;
	} while (objects_left != 1u);
	*p_object = object;
	*p_player_states = player_states;
}

/* Stage 8's opening: the descent is over. */
void stage_8_start_stop(uint16_t *p_object, uint16_t *p_player_states)
{
	uint16_t player_states = (uint16_t)*p_player_states;
	uint8_t stop_speed = 0, stop_speed_high = 0;
	uint16_t object = 0;
	uint8_t objects_left = 0, old_scene_state = 0;

	object = OBJECT_ADDRESS(27);
	scene_objects_left = 3u;
	stop_speed = 0u;
	stop_speed_high = 0u;
	do
	{
		OBJECT(object)->z_speed = (uint32_t)stop_speed_high << 8;
		object += 0x60u;
		objects_left = scene_objects_left;
		scene_objects_left = objects_left - 1u;
	} while (objects_left != 1u);
	stage_8_start_run_players(&object, &player_states);
	old_scene_state = io_read8(scene_state);
	io_write8(scene_state, old_scene_state + 1u);
	*p_object = object;
	*p_player_states = player_states;
}

/* Stage 8's opening: the kind-9C character lands (sound 6000) and runs. */
uint16_t stage_8_start_landing(void)
{
	uint32_t carry = 0;
	uint16_t command = 0, ignored16 = 0, object = 0;
	uint8_t old_scene_state = 0;
	uint16_t z = 0;

	object = OBJECT_ADDRESS(26);
	vector_apply_gravity(object, &ignored16, &carry);
	z = OBJECT(object)->z;
	if ((int16_t)z > 0x38)
		return object;
	OBJECT(object)->animation = 0x81u;
	OBJECT(object)->z_speed = 0;
	command = 0x6000u;
	vector_queue_sound(command);
	OBJECT(OBJECT_ADDRESS(30))->flags = 0u;
	OBJECT(object)->animation = 0x81u;
	old_scene_state = io_read8(scene_state);
	io_write8(scene_state, old_scene_state + 1u);
	return object;
}

/* Stage 8's opening: the kind-9C character runs off the screen. */
void stage_8_start_run_off(uint16_t *p_object, uint16_t *p_player_states)
{
	uint16_t player_states = (uint16_t)*p_player_states;
	uint16_t ignored16 = 0, object = 0;
	uint8_t old_scene_state = 0;

	stage_8_start_run_players(&ignored16, &player_states);
	object = OBJECT_ADDRESS(26);
	if ((int16_t)OBJECT(OBJECT_ADDRESS(26))->x >= 0x150)
	{
		io_write16(scene_wait, 0x80u);
		OBJECT(object)->flags = 0u;
		old_scene_state = io_read8(scene_state);
		io_write8(scene_state, old_scene_state + 1u);
	}
	*p_object = object;
	*p_player_states = player_states;
}

/* Stage 8's opening: runs the players for the last 128 frames, then ends the scene (no scenario reaches
   its end here). */
void stage_8_start_wait_end(uint16_t *p_x, uint16_t *p_player_states)
{
	uint16_t player_states = (uint16_t)*p_player_states;
	uint16_t x = 0;
	uint16_t end_wait = 0;

	end_wait = io_read16(scene_wait);
	io_write16(scene_wait, end_wait - 1u);
	if (end_wait != 1u)
		stage_8_start_run_players(&x, &player_states);
	else
		stage_8_start_finish(&x, &player_states);
	*p_x = x;
	*p_player_states = player_states;
}

/* Stage 8's opening is over: the scene's variables, the sound and the objects cleared. */
void stage_8_start_finish(uint16_t *p_x, uint16_t *p_u)
{
	uint16_t clear_from = 0, clear_to = 0, command = 0, count = 0, u = 0, x = 0;

	clear_from = scene_state;
	clear_to = scene_substate;
	io_write8(scene_state, 0u);
	count = 0x1Fu;
	while (count != 0u)
	{
		mem_write8(clear_to, mem_read8(clear_from));
		clear_from++;
		clear_to++;
		count--;
	}
	command = 0u;
	vector_queue_sound(command);
	vector_clear_objects(&x, &u);
	scene_running = 0u;
	leftover_y = clear_from;
	*p_x = x;
	*p_u = u;
}

/* Stage 8's opening: runs the players' objects by their state. */
void stage_8_start_run_players(uint16_t *p_object, uint16_t *p_player_states)
{
	uint16_t player_states = (uint16_t)*p_player_states;
	uint16_t object = 0;
	uint8_t stack = 0;
	uint8_t state = 0, players_left = 0;

	stack = 4u;
	object = OBJECT_ADDRESS(22);
	do
	{
		if ((int8_t)OBJECT(object)->flags < 0)
		{
			player_states = stage_8_start_run_players_states_ADDRESS;
			state = OBJECT(object)->state;
			switch ((int8_t)(uint8_t)((uint32_t)state << 1))
			{
			case 0:
				stage_8_start_player_ride(object);
				break;
			case 2:
				stage_8_start_player_drop(object);
				break;
			case 4:
				stage_8_start_player_look(object);
				break;
			case 6:
				stage_8_start_player_turn(object);
				break;
			case 8:
				stage_8_start_player_run(object);
				break;
			case 10:
				stage_8_start_player_gone(object);
				break;
			case 12:
				stage_8_end_set_up(&object, &player_states);
				break;
			case 14:
				stage_8_end_show(&object, &player_states);
				break;
			case 16:
				stage_8_end_hold();
				break;
			case 18:
				stage_8_end_switch_view(&object, &player_states);
				break;
			case 20:
				stage_8_end_show_kind_13(&object, &player_states);
				break;
			case 22:
				stage_8_end_reunion(&object, &player_states);
				break;
			case 24:
				stage_8_end_run_family(&object, &player_states);
				break;
			case 26:
				stage_8_end_finish(&object, &player_states);
				break;
			case 28:
				stage_8_end_actor_rest();
				break;
			case 30:
				stage_8_end_walker(&object, &player_states);
				break;
			case 32:
				stage_8_end_maggie_taker(&object, &player_states);
				break;
			case 34:
				stage_8_end_extra(&object, &player_states);
				break;
			case 36:
				stage_8_end_slow_extra(&object, &player_states);
				break;
			case 38:
			case 46:
			case 54:
				stage_8_end_actor_start(object);
				break;
			case 40:
				stage_8_end_walker_go(object);
				break;
			case 42:
				stage_8_end_walker_arrive(object);
				break;
			case 44:
			case 52:
			case 60:
				stage_8_end_actor_done();
				break;
			case 48:
				stage_8_end_extra_go(object);
				break;
			case 50:
			case 58:
				stage_8_end_extra_arrive(object);
				break;
			case 56:
				stage_8_end_slow_extra_go(object);
				break;
			case 62:
				stage_8_end_taker_wait(object);
				break;
			case 64:
				stage_8_end_take_maggie(object);
				break;
			case 66:
				stage_8_end_holding_maggie(object);
				break;
			case 68:
				stage_8_end_taker_done();
				break;
			case -116:
				stage_1_end_start();
				break;
			case -114:
				player_states = stage_1_end_put_police_car(player_states);
				break;
			case -112:
				object = stage_1_end_move_police_car(object);
				break;
			case -110:
				stage_1_end_wait();
				break;
			case -108:
				object = stage_1_end_car_sound(object);
				break;
			case -106:
			case -78:
				scene_clear(&object, &player_states);
				break;
			case -104:
				stage_2_end_set_up(&object, &player_states);
				break;
			case -102:
			case -74:
				stage_end_jump_away(&object, &player_states);
				break;
			case -100:
				stage_2_end_show_area_3(&object, &player_states);
				break;
			case -98:
				stage_2_end_put_players(object);
				break;
			case -96:
			case -94:
				stage_2_end_players_look_around(&object, &player_states);
				break;
			case -92:
				scene_end(&object, &player_states);
				break;
			case -90:
				object = stage_end_put_jumpers(object);
				break;
			case -88:
				stage_end_run_jumpers(&object, &player_states);
				break;
			case -86:
				player_states = stage_end_jumper_wait(object, player_states);
				break;
			case -84:
				stage_end_jumper_fly(object);
				break;
			case -82:
				stage_end_jumper_last_leg(object);
				break;
			case -80:
				stage_end_jumper_vanish(object);
				break;
			case -76:
				stage_5_end_set_up(&object, &player_states);
				break;
			case -72:
				stage_5_end_show_players(&object, &player_states);
				break;
			case -70:
				player_states = stage_5_end_fade(player_states);
				break;
			case -68:
				stage_5_end_finish(&object, &player_states);
				break;
			case -66:
				stage_6_end_start();
				break;
			case -64:
				player_states = stage_6_end_effect(player_states);
				break;
			case -62:
				stage_6_end_finish(&object, &player_states);
				break;
			case -60:
				stage_6_wake_set_up(&object, &player_states);
				break;
			case -58:
				stage_6_wake_show_players(&object, &player_states);
				break;
			case -56:
				stage_6_wake_start();
				break;
			case -54:
				stage_6_wake_wave(&object, &player_states);
				break;
			case -52:
				post_bonus_2_scene_set_up(&object, &player_states);
				break;
			case -50:
				post_bonus_2_scene_show(&object, &player_states);
				break;
			case -48:
				post_bonus_2_scene_wait();
				break;
			case -46:
				post_bonus_2_scene_pan();
				break;
			case -44:
				post_bonus_2_scene_finish();
				break;
			case -42:
				object = stage_7_scene_set_up();
				break;
			case -40:
				stage_7_scene_wait_scroll();
				break;
			case -38:
				stage_7_scene_wait_signal();
				break;
			case -36:
				stage_7_scene_lift(&object, &player_states);
				break;
			case -34:
				stage_7_scene_wait_train();
				break;
			case -32:
				stage_7_scene_put_chain(&object, &player_states);
				break;
			case -30:
				stage_7_scene_move_chain(&object, &player_states);
				break;
			case -28:
				stage_7_scene_chain_done();
				break;
			case -26:
				stage_7_end_set_up(&object, &player_states);
				break;
			case -24:
				stage_7_end_show(&object, &player_states);
				break;
			case -22:
				stage_7_end_board(object);
				break;
			case -20:
				object = stage_7_end_take_off();
				break;
			case -18:
				stage_7_end_slow_down(&object, &player_states);
				break;
			case -16:
				stage_7_end_finish(&object, &player_states);
				break;
			case -14:
				stage_8_start_set_up(&object, &player_states);
				break;
			case -12:
				stage_8_start_show(&object, &player_states);
				break;
			case -10:
				stage_8_start_descend(&object, &player_states);
				break;
			case -8:
				stage_8_start_stop(&object, &player_states);
				break;
			case -6:
				object = stage_8_start_landing();
				break;
			case -4:
				stage_8_start_run_off(&object, &player_states);
				break;
			case -2:
				stage_8_start_wait_end(&object, &player_states);
				break;
			}
		}
		object += 0x60u;
		players_left = stack;
		stack = players_left - 1u;
	} while (players_left != 1u);
	*p_object = object;
	*p_player_states = player_states;
}

/* Stage 8's opening: a player comes down with the view. */
void stage_8_start_player_ride(uint16_t object)
{
	uint8_t state = 0;
	uint16_t z = 0, descent_speed = 0;

	z = OBJECT(object)->z;
	if ((int16_t)z > 0xBF)
	{
		descent_speed = io_read16(scene_layer_b_speed);
		OBJECT(object)->z_speed = 0u - descent_speed;
		return;
	}
	OBJECT(object)->animation = 0x97u;
	OBJECT(object)->z_speed = 0;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
}

/* Stage 8's opening: a player drops to the floor and says something. */
void stage_8_start_player_drop(uint16_t object)
{
	uint32_t carry = 0;
	uint16_t command = 0, ignored16 = 0;
	uint8_t kind = 0, state = 0;
	uint16_t z = 0, landing_shout = 0;

	vector_apply_gravity(object, &ignored16, &carry);
	z = OBJECT(object)->z;
	if ((int16_t)z > 0x38)
		return;
	OBJECT(object)->animation = 0xD4u;
	OBJECT(object)->z_speed = 0;
	kind = OBJECT(object)->kind;
	landing_shout = kind + 0x3F24u;
	command = landing_shout;
	vector_queue_sound(command);
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
}

/* Stage 8's opening: a player looks around. */
void stage_8_start_player_look(uint16_t object)
{
	uint8_t frame = 0, state = 0;

	frame = OBJECT(object)->frame;
	if (frame == 3u)
	{
		OBJECT(object)->animation = 0xDFu;
		OBJECT(object)->action_step = 0x60u;
		state = OBJECT(object)->state;
		OBJECT(object)->state = state + 1u;
	}
}

/* Stage 8's opening: a player turns after 96 frames. */
void stage_8_start_player_turn(uint16_t object)
{
	uint8_t action_step = 0, state = 0;

	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step - 1u;
	if (action_step == 1u)
	{
		OBJECT(object)->animation = 0xDCu;
		state = OBJECT(object)->state;
		OBJECT(object)->state = state + 1u;
	}
}

/* Stage 8's opening: a player runs off to the right (no scenario reaches it). */
void stage_8_start_player_run(uint16_t object)
{
	uint8_t animation_flags = 0, state = 0;

	animation_flags = OBJECT(object)->animation_flags;
	if ((animation_flags & 1u) != 0u)
	{
		OBJECT(object)->animation = 0x81u;
		OBJECT(object)->x_speed = 0x300;
		OBJECT(object)->attributes = 0u;
		state = OBJECT(object)->state;
		OBJECT(object)->state = state + 1u;
	}
}

/* Stage 8's opening: a player past the right edge is gone (no scenario reaches it). */
void stage_8_start_player_gone(uint16_t object)
{
	uint16_t player_x = 0;

	player_x = OBJECT(object)->x;
	if ((int16_t)player_x >= 0x150)
		OBJECT(object)->flags = 0u;
}

/* The scene after stage 8's last boss: stops the sound, clears the tiles, loads its colours and clears
   the screen. */
void stage_8_end_set_up(uint16_t *p_x, uint16_t *p_u)
{
	uint16_t clear_from = 0, clear_to = 0, command = 0, count = 0, ignored16 = 0, job = 0, request = 0, scroll_x = 0, scroll_y = 0, u = 0, x = 0;
	uint8_t old_scene_state = 0;

	job = 0u;
	vector_queue_job(job);
	command = 0u;
	vector_queue_sound_always(command);
	clear_from = palette_jobs;
	clear_to = 0x3C01u;
	io_write8(palette_jobs, 0u);
	count = 0x1FFu;
	while (count != 0u)
	{
		mem_write8(clear_to, mem_read8(clear_from));
		clear_from++;
		clear_to++;
		count--;
	}
	palette_request_kind = 1u;
	request = 0xE8Fu;
	vector_palette_request(count, request);
	scroll_x = 0xFFF0u;
	vector_set_scroll_x(scroll_x);
	scroll_y = 0u;
	vector_set_scroll_y(scroll_y);
	vector_clear_objects(&ignored16, &u);
	x = vector_clear_sprites();
	old_scene_state = io_read8(scene_state);
	io_write8(scene_state, old_scene_state + 1u);
	*p_x = x;
	*p_u = u;
}

/* The scene after stage 8's last boss: the power plant's area 2 with the kind-13 object and the music
   (9600). */
void stage_8_end_show(uint16_t *p_default_object, uint16_t *p_u)
{
	uint16_t default_object = (uint16_t)*p_default_object;
	uint16_t u = (uint16_t)*p_u;
	uint16_t command = 0, ignored16 = 0, ignored16_2 = 0, layer_and_columns = 0, object = 0, record_number = 0, u_2 = 0;
	uint8_t old_scene_state = 0;

	if (layer_clear_pending != 0u)
		return;
	io_write8(colour_bases_back_sprites_fixed, 0x3Fu);
	io_write8(colour_bases_layers_a_b, 0x36u);
	map_scene = 0x8Du;
	map_area = 2u;
	vector_set_layer_modes();
	layer_and_columns = 0x26u;
	vector_draw_layer_strips(layer_and_columns, &ignored16, &ignored16_2);
	layer_and_columns = 0x126u;
	vector_draw_layer_strips(layer_and_columns, &default_object, &u_2);
	record_number = 0x2326u;
	object = scene_put_placement(default_object, record_number);
	leftover_y = object;
	OBJECT(leftover_y)->attributes = 0x10u;
	io_write8(colour_bases_back_sprites_fixed, 0x13u);
	io_write8(colour_bases_layers_a_b, 0x2Cu);
	command = 0x9600u;
	vector_queue_sound(command);
	io_write16(scene_wait, 0x30u);
	old_scene_state = io_read8(scene_state);
	io_write8(scene_state, old_scene_state + 1u);
	*p_default_object = default_object;
	*p_u = u_2;
}

/* The scene after stage 8's last boss: holds the kind-13 object's picture. */
void stage_8_end_hold(void)
{
	uint8_t old_scene_state = 0;
	uint16_t hold_wait = 0;

	OBJECT(OBJECT_ADDRESS(8))->animation_flags |= 0x40u;
	hold_wait = io_read16(scene_wait);
	io_write16(scene_wait, hold_wait - 1u);
	if (hold_wait == 1u)
	{
		io_write16(scene_wait, 0x60u);
		old_scene_state = io_read8(scene_state);
		io_write8(scene_state, old_scene_state + 1u);
	}
}

/* The scene after stage 8's last boss: moves layer B and clears the objects. */
void stage_8_end_switch_view(uint16_t *p_x, uint16_t *p_u)
{
	uint16_t ignored16 = 0, ignored16_2 = 0, layer_and_columns = 0, u = 0, x = 0;
	uint8_t old_scene_state = 0;

	io_write8(colour_bases_back_sprites_fixed, 0x3Fu);
	io_write8(colour_bases_layers_a_b, 0x36u);
	layer_b_scroll_x = 0x120u;
	layer_b_last_scroll_x = 0x120u;
	layer_b_offset_x = 0u;
	layer_and_columns = 0x126u;
	vector_draw_layer_strips(layer_and_columns, &ignored16, &ignored16_2);
	vector_clear_objects(&ignored16, &u);
	io_write16(scene_wait, 0x60u);
	x = clear_child_objects();
	old_scene_state = io_read8(scene_state);
	io_write8(scene_state, old_scene_state + 1u);
	*p_x = x;
	*p_u = u;
}

/* The scene after stage 8's last boss: back to the scene, the kind-13 objects in it. */
void stage_8_end_show_kind_13(uint16_t *p_default_object, uint16_t *p_u)
{
	uint16_t default_object = (uint16_t)*p_default_object;
	uint16_t u = (uint16_t)*p_u;
	uint16_t ignored16 = 0, ignored16_2 = 0, layer_and_columns = 0, object = 0, record_number = 0, u_2 = 0;
	uint8_t old_scene_state = 0;
	uint16_t view_wait = 0;

	io_write8(colour_bases_back_sprites_fixed, 0x13u);
	io_write8(colour_bases_layers_a_b, 0x2Cu);
	view_wait = io_read16(scene_wait);
	io_write16(scene_wait, view_wait - 1u);
	if (view_wait != 1u)
		return;
	io_write8(colour_bases_back_sprites_fixed, 0x3Fu);
	io_write8(colour_bases_layers_a_b, 0x36u);
	layer_b_scroll_x = 0xFFF0u;
	layer_b_last_scroll_x = 0xFFF0u;
	layer_b_offset_x = 0u;
	layer_and_columns = 0x126u;
	vector_draw_layer_strips(layer_and_columns, &ignored16, &ignored16_2);
	vector_clear_objects(&default_object, &u_2);
	record_number = 0x2426u;
	scene_put_placement(default_object, record_number);
	record_number = 0x2526u;
	scene_put_placement(default_object, record_number);
	record_number = 0x2626u;
	object = scene_put_placement(default_object, record_number);
	leftover_y = object;
	io_write16(scene_wait, 0x100u);
	old_scene_state = io_read8(scene_state);
	io_write8(scene_state, old_scene_state + 1u);
	*p_default_object = default_object;
	*p_u = u_2;
}

/* The scene after stage 8's last boss: back where the fight ended, Maggie, Mr. Burns and the family: one
   player who played picked at random to get Maggie, the others walking in. */
void stage_8_end_reunion(uint16_t *p_object, uint16_t *p_u)
{
	uint16_t object = (uint16_t)*p_object;
	uint16_t u = (uint16_t)*p_u;
	uint8_t bit = 0, blink_flags = 0, count = 0, present = 0, scroll_x_high = 0, scroll_x_low = 0, scroll_y_high = 0, scroll_y_low = 0, shifts = 0, stop_offset_high = 0, stop_offset_low = 0;
	uint16_t command = 0, ignored16 = 0, layer_and_columns = 0, request = 0, u_2 = 0;
	uint8_t picked = 0, picked_number = 0, players_left = 0, picked_bit = 0, discarded_read = 0, old_picked_bits = 0, extras_left = 0, old_scene_state = 0;
	uint16_t reunion_wait = 0, saved_scroll_x = 0, saved_scroll_y = 0, walker_spot_x = 0, walker_x = 0, walker_spot_y = 0, walker_y = 0, old_walker_x = 0, next_walker_x = 0, old_stop_offset = 0, walker_stop_offset = 0, taker_spot_x = 0, taker_x = 0, taker_spot_y = 0, taker_y = 0, stander_spot_x = 0, stander_x = 0, stander_spot_y = 0, stander_y = 0, old_stander_x = 0, next_stander_x = 0, extra_spot_x = 0, extra_x = 0, extra_spot_y = 0, extra_y = 0, old_extra_x = 0, next_extra_x = 0, old_extra_offset = 0, extra_stop_offset = 0, slow_spot_x = 0, slow_extra_x = 0, slow_spot_y = 0, slow_extra_y = 0, old_slow_offset = 0, slow_stop_offset = 0, maggie_spot_x = 0, maggie_x = 0, maggie_spot_y = 0, maggie_y = 0, spot_x = 0, spot_y = 0;
	uint32_t kind_halfword = 0, kind_halfword_2 = 0, kind_halfword_3 = 0, kind_halfword_4 = 0;

	io_write8(colour_bases_back_sprites_fixed, 0x13u);
	io_write8(colour_bases_layers_a_b, 0x2Cu);
	reunion_wait = io_read16(scene_wait);
	io_write16(scene_wait, reunion_wait - 1u);
	if (reunion_wait != 1u)
	{
		blink_flags = 0u;
		if ((frame_count & 0x20u) != 0u)
			blink_flags = 0x80u;
		OBJECT(OBJECT_ADDRESS(9))->flags = blink_flags;
		OBJECT(OBJECT_ADDRESS(9))->animation_flags = blink_flags;
		if ((frame_count & 0x1Fu) != 0u)
			return;
		command = 0x4500u;
		vector_queue_sound(command);
		return;
	}
	clear_child_objects();
	saved_scroll_x = io_read16(reunion_camera_x);
	scroll_x_high = (uint8_t)(saved_scroll_x >> 8);
	scroll_x_low = (uint8_t)saved_scroll_x;
	layer_a_scroll_x = ((uint32_t)scroll_x_high << 8) | scroll_x_low;
	layer_b_scroll_x = ((uint32_t)scroll_x_high << 8) | scroll_x_low;
	saved_scroll_y = io_read16(reunion_camera_y);
	scroll_y_high = (uint8_t)(saved_scroll_y >> 8);
	scroll_y_low = (uint8_t)saved_scroll_y;
	layer_a_scroll_y = ((uint32_t)scroll_y_high << 8) | scroll_y_low;
	layer_b_scroll_y = ((uint32_t)scroll_y_high << 8) | scroll_y_low;
	palette_request_kind = 1u;
	request = 0x880u;
	u = vector_palette_request(u, request);
	palette_request_kind = 1u;
	request = 0xF8Eu;
	vector_palette_request(u, request);
	io_write8(colour_bases_back_sprites_fixed, 0x3Fu);
	io_write8(colour_bases_layers_a_b, 0x36u);
	map_scene = 0x8Du;
	map_area = 1u;
	vector_set_layer_modes();
	layer_and_columns = 0x2Cu;
	vector_draw_layer_strips(layer_and_columns, &ignored16, &u_2);
	vector_clear_layer_b();
	io_write8(colour_bases_back_sprites_fixed, 0x13u);
	io_write8(colour_bases_layers_a_b, 0x2Cu);
	picked = io_read8(maggie_rescuer);
	picked_number = (((picked >> 1) >> 1) >> 1) >> 1;
	shifts = picked_number;
	if (picked_number != 0u)
	{
		bit = 1u;
		while (shifts != 0u)
		{
			bit = (uint32_t)bit << 1;
			shifts--;
		}
		io_write8(maggie_rescuer, bit);
	}
	else
	{
		present = players_present;
		reunion_player = 1u;
		count = 4u;
		do
		{
			if ((present & reunion_player) != 0u)
				break;
			reunion_player = (uint32_t)reunion_player << 1;
			players_left = count;
			count = players_left - 1u;
		} while (players_left != 1u);
		io_write8(maggie_rescuer, present & reunion_player);
	}
	reunion_player = 0u;
	reunion_player_bits = players_present;
	reunion_standing_x = 0x60u;
	reunion_walker_x = 0xFE80u;
	reunion_walker_stop_offset = 0xFFE0u;
	object = OBJECT_ADDRESS(22);
	do
	{
		if ((reunion_player_bits & 1u) == 0u)
		{
			OBJECT(object)->flags = 0x80u;
			kind_halfword = ((uint32_t)reunion_player << 8) | 0x80u;
			OBJECT(object)->kind = (uint8_t)(kind_halfword >> 8u);
			OBJECT(object)->animation = (uint8_t)kind_halfword;
			walker_spot_x = io_read16(reunion_spot_x);
			walker_x = walker_spot_x + reunion_walker_x;
			OBJECT(object)->x = walker_x;
			walker_spot_y = io_read16(reunion_spot_y);
			walker_y = walker_spot_y - 0x10u;
			OBJECT(object)->y = walker_y;
			old_walker_x = reunion_walker_x;
			next_walker_x = old_walker_x - 0x20u;
			reunion_walker_x = next_walker_x;
			old_stop_offset = reunion_walker_stop_offset;
			walker_stop_offset = old_stop_offset + 0x20u;
			stop_offset_high = (uint8_t)(walker_stop_offset >> 8);
			stop_offset_low = (uint8_t)walker_stop_offset;
			reunion_walker_stop_offset = ((uint32_t)stop_offset_high << 8) | stop_offset_low;
			OBJECT(object)->stage_8_end.stop_offset = ((uint32_t)stop_offset_high << 8) | stop_offset_low;
			OBJECT(object)->type = -0xC;
			OBJECT(object)->state = 1u;
		}
		else
		{
			picked_bit = io_read8(maggie_rescuer);
			if ((picked_bit & 1u) != 0u)
			{
				discarded_read = io_read8(maggie_rescuer);
				io_write8(maggie_rescuer, 0u);
				OBJECT(object)->flags = 0x80u;
				kind_halfword_2 = ((uint32_t)reunion_player << 8) | 0x80u;
				OBJECT(object)->kind = (uint8_t)(kind_halfword_2 >> 8u);
				OBJECT(object)->animation = (uint8_t)kind_halfword_2;
				taker_spot_x = io_read16(reunion_spot_x);
				taker_x = taker_spot_x + 0x70u;
				OBJECT(object)->x = taker_x;
				taker_spot_y = io_read16(reunion_spot_y);
				taker_y = taker_spot_y - 0xEu;
				OBJECT(object)->y = taker_y;
				OBJECT(object)->attributes = 0x40u;
				OBJECT(object)->type = -0xC;
				OBJECT(object)->state = 2u;
			}
			else
			{
				OBJECT(object)->flags = 0x80u;
				kind_halfword_3 = ((uint32_t)reunion_player << 8) | 0x9Eu;
				OBJECT(object)->kind = (uint8_t)(kind_halfword_3 >> 8u);
				OBJECT(object)->animation = (uint8_t)kind_halfword_3;
				stander_spot_x = io_read16(reunion_spot_x);
				stander_x = stander_spot_x + reunion_standing_x;
				OBJECT(object)->x = stander_x;
				stander_spot_y = io_read16(reunion_spot_y);
				stander_y = stander_spot_y + 0x10u;
				OBJECT(object)->y = stander_y;
				old_stander_x = reunion_standing_x;
				next_stander_x = old_stander_x - 0x20u;
				reunion_standing_x = next_stander_x;
				OBJECT(object)->attributes = 0x40u;
				OBJECT(object)->type = -0xC;
				OBJECT(object)->state = 0u;
			}
		}
		OBJECT(object)->stage_8_end.actor_player = reunion_player;
		object += 0x60u;
		old_picked_bits = io_read8(maggie_rescuer);
		io_write8(maggie_rescuer, old_picked_bits >> 1);
		reunion_player_bits = reunion_player_bits >> 1;
		reunion_player++;
	} while (reunion_player != 4u);
	if ((players_present & 0xFu) == 0xFu)
	{
		reunion_player = 0x81u;
		reunion_player_bits = 2u;
		reunion_walker_stop_offset = 0u;
		reunion_walker_x = 0xFE80u;
		do
		{
			OBJECT(object)->flags = 0x80u;
			kind_halfword_4 = 0xC900u | reunion_player;
			OBJECT(object)->kind = (uint8_t)(kind_halfword_4 >> 8u);
			OBJECT(object)->animation = (uint8_t)kind_halfword_4;
			reunion_player++;
			reunion_player++;
			extra_spot_x = io_read16(reunion_spot_x);
			extra_x = extra_spot_x + reunion_walker_x;
			OBJECT(object)->x = extra_x;
			extra_spot_y = io_read16(reunion_spot_y);
			extra_y = extra_spot_y + 0x10u;
			OBJECT(object)->y = extra_y;
			old_extra_x = reunion_walker_x;
			next_extra_x = old_extra_x - 0x20u;
			reunion_walker_x = next_extra_x;
			old_extra_offset = reunion_walker_stop_offset;
			extra_stop_offset = old_extra_offset + 0x20u;
			stop_offset_high = (uint8_t)(extra_stop_offset >> 8);
			stop_offset_low = (uint8_t)extra_stop_offset;
			reunion_walker_stop_offset = ((uint32_t)stop_offset_high << 8) | stop_offset_low;
			OBJECT(object)->stage_8_end.stop_offset = ((uint32_t)stop_offset_high << 8) | stop_offset_low;
			OBJECT(object)->type = -0xC;
			OBJECT(object)->state = 3u;
			object += 0x60u;
			extras_left = reunion_player_bits;
			reunion_player_bits = extras_left - 1u;
		} while (extras_left != 1u);
		OBJECT(object)->flags = 0x80u;
		OBJECT(object)->kind = 0xCAu;
		OBJECT(object)->animation = 0x81u;
		slow_spot_x = io_read16(reunion_spot_x);
		slow_extra_x = slow_spot_x - 0x180u;
		OBJECT(object)->x = slow_extra_x;
		slow_spot_y = io_read16(reunion_spot_y);
		slow_extra_y = slow_spot_y + 0x10u;
		OBJECT(object)->y = slow_extra_y;
		old_slow_offset = reunion_walker_stop_offset;
		slow_stop_offset = old_slow_offset + 0x20u;
		OBJECT(object)->stage_8_end.stop_offset = slow_stop_offset;
		OBJECT(object)->type = -0xC;
		OBJECT(object)->state = 4u;
	}
	OBJECT(OBJECT_ADDRESS(29))->flags = 0x80u;
	OBJECT(OBJECT_ADDRESS(29))->kind = 0x11u;
	OBJECT(OBJECT_ADDRESS(29))->animation = 0x86u;
	OBJECT(OBJECT_ADDRESS(29))->attributes = 0x40u;
	maggie_spot_x = io_read16(reunion_spot_x);
	maggie_x = maggie_spot_x + 0x60u;
	OBJECT(OBJECT_ADDRESS(29))->x = maggie_x;
	maggie_spot_y = io_read16(reunion_spot_y);
	maggie_y = maggie_spot_y - 0x10u;
	OBJECT(OBJECT_ADDRESS(29))->y = maggie_y;
	OBJECT(OBJECT_ADDRESS(29))->type = -0xC;
	object = OBJECT_ADDRESS(30);
	OBJECT(OBJECT_ADDRESS(30))->flags = 0x80u;
	OBJECT(OBJECT_ADDRESS(30))->kind = 0xD3u;
	OBJECT(OBJECT_ADDRESS(30))->animation = 0x83u;
	OBJECT(OBJECT_ADDRESS(30))->attributes = 0x40u;
	spot_x = io_read16(reunion_spot_x);
	OBJECT(OBJECT_ADDRESS(30))->x = spot_x;
	spot_y = io_read16(reunion_spot_y);
	OBJECT(OBJECT_ADDRESS(30))->y = spot_y;
	OBJECT(OBJECT_ADDRESS(30))->type = -0xC;
	io_write16(scene_wait, 0x1C0u);
	old_scene_state = io_read8(scene_state);
	io_write8(scene_state, old_scene_state + 1u);
	*p_object = object;
	*p_u = u_2;
}

/* The scene after stage 8's last boss: runs each actor by its state; when the time is up, moves to the
   power plant's area 3 with its music (8B00). */
void stage_8_end_run_family(uint16_t *p_object, uint16_t *p_steps)
{
	uint16_t steps = (uint16_t)*p_steps;
	uint16_t command = 0, ignored16 = 0, ignored16_2 = 0, layer_and_columns = 0, object = 0, record_number = 0, request = 0, scroll_x = 0, scroll_y = 0, y = 0;
	uint8_t stack = 0;
	uint8_t old_scene_state = 0, state = 0, actors_left = 0;
	uint16_t family_wait = 0;

	family_wait = io_read16(scene_wait);
	io_write16(scene_wait, family_wait - 1u);
	if (family_wait == 1u)
	{
		io_write16(scene_wait, 0xC0u);
		vector_clear_list_1_objects();
		scroll_x = 0xFFF0u;
		vector_set_scroll_x(scroll_x);
		scroll_y = 0u;
		vector_set_scroll_y(scroll_y);
		palette_request_kind = 1u;
		request = 0xE8Fu;
		vector_palette_request(steps, request);
		map_scene = 0x8Du;
		map_area = 3u;
		vector_set_layer_modes();
		io_write8(colour_bases_back_sprites_fixed, 0x3Fu);
		io_write8(colour_bases_layers_a_b, 0x36u);
		layer_and_columns = 0x26u;
		vector_draw_layer_strips(layer_and_columns, &ignored16, &ignored16_2);
		layer_and_columns = 0x126u;
		vector_draw_layer_strips(layer_and_columns, &ignored16, &ignored16_2);
		vector_clear_objects(&object, &steps);
		record_number = 0x2726u;
		y = scene_put_placement(object, record_number);
		leftover_y = y;
		io_write16(scene_wait, 0x140u);
		palette_request_kind = 2u;
		request = 0x39u;
		steps = vector_palette_request(steps, request);
		command = 0x8B00u;
		vector_queue_sound(command);
		io_write16(scene_wait, 0x140u);
		old_scene_state = io_read8(scene_state);
		io_write8(scene_state, old_scene_state + 1u);
	}
	else
	{
		object = OBJECT_ADDRESS(22);
		stack = 7u;
		do
		{
			steps = stage_8_end_run_family_states_ADDRESS;
			state = OBJECT(object)->state;
			switch ((int8_t)(uint8_t)((uint32_t)state << 1))
			{
			case 0:
				stage_8_end_actor_rest();
				break;
			case 2:
				stage_8_end_walker(&object, &steps);
				break;
			case 4:
				stage_8_end_maggie_taker(&object, &steps);
				break;
			case 6:
				stage_8_end_extra(&object, &steps);
				break;
			case 8:
				stage_8_end_slow_extra(&object, &steps);
				break;
			case 10:
			case 18:
			case 26:
				stage_8_end_actor_start(object);
				break;
			case 12:
				stage_8_end_walker_go(object);
				break;
			case 14:
				stage_8_end_walker_arrive(object);
				break;
			case 16:
			case 24:
			case 32:
				stage_8_end_actor_done();
				break;
			case 20:
				stage_8_end_extra_go(object);
				break;
			case 22:
			case 30:
				stage_8_end_extra_arrive(object);
				break;
			case 28:
				stage_8_end_slow_extra_go(object);
				break;
			case 34:
				stage_8_end_taker_wait(object);
				break;
			case 36:
				stage_8_end_take_maggie(object);
				break;
			case 38:
				stage_8_end_holding_maggie(object);
				break;
			case 40:
				stage_8_end_taker_done();
				break;
			case -128:
				stage_2_end_show_area_3(&object, &steps);
				break;
			case -126:
				stage_2_end_put_players(object);
				break;
			case -124:
			case -122:
				stage_2_end_players_look_around(&object, &steps);
				break;
			case -120:
				scene_end(&object, &steps);
				break;
			case -118:
				object = stage_end_put_jumpers(object);
				break;
			case -116:
				stage_end_run_jumpers(&object, &steps);
				break;
			case -114:
				steps = stage_end_jumper_wait(object, steps);
				break;
			case -112:
				stage_end_jumper_fly(object);
				break;
			case -110:
				stage_end_jumper_last_leg(object);
				break;
			case -108:
				stage_end_jumper_vanish(object);
				break;
			case -106:
				scene_clear(&object, &steps);
				break;
			case -104:
				stage_5_end_set_up(&object, &steps);
				break;
			case -102:
				stage_end_jump_away(&object, &steps);
				break;
			case -100:
				stage_5_end_show_players(&object, &steps);
				break;
			case -98:
				steps = stage_5_end_fade(steps);
				break;
			case -96:
				stage_5_end_finish(&object, &steps);
				break;
			case -94:
				stage_6_end_start();
				break;
			case -92:
				steps = stage_6_end_effect(steps);
				break;
			case -90:
				stage_6_end_finish(&object, &steps);
				break;
			case -88:
				stage_6_wake_set_up(&object, &steps);
				break;
			case -86:
				stage_6_wake_show_players(&object, &steps);
				break;
			case -84:
				stage_6_wake_start();
				break;
			case -82:
				stage_6_wake_wave(&object, &steps);
				break;
			case -80:
				post_bonus_2_scene_set_up(&object, &steps);
				break;
			case -78:
				post_bonus_2_scene_show(&object, &steps);
				break;
			case -76:
				post_bonus_2_scene_wait();
				break;
			case -74:
				post_bonus_2_scene_pan();
				break;
			case -72:
				post_bonus_2_scene_finish();
				break;
			case -70:
				object = stage_7_scene_set_up();
				break;
			case -68:
				stage_7_scene_wait_scroll();
				break;
			case -66:
				stage_7_scene_wait_signal();
				break;
			case -64:
				stage_7_scene_lift(&object, &steps);
				break;
			case -62:
				stage_7_scene_wait_train();
				break;
			case -60:
				stage_7_scene_put_chain(&object, &steps);
				break;
			case -58:
				stage_7_scene_move_chain(&object, &steps);
				break;
			case -56:
				stage_7_scene_chain_done();
				break;
			case -54:
				stage_7_end_set_up(&object, &steps);
				break;
			case -52:
				stage_7_end_show(&object, &steps);
				break;
			case -50:
				stage_7_end_board(object);
				break;
			case -48:
				object = stage_7_end_take_off();
				break;
			case -46:
				stage_7_end_slow_down(&object, &steps);
				break;
			case -44:
				stage_7_end_finish(&object, &steps);
				break;
			case -42:
				stage_8_start_set_up(&object, &steps);
				break;
			case -40:
				stage_8_start_show(&object, &steps);
				break;
			case -38:
				stage_8_start_descend(&object, &steps);
				break;
			case -36:
				stage_8_start_stop(&object, &steps);
				break;
			case -34:
				object = stage_8_start_landing();
				break;
			case -32:
				stage_8_start_run_off(&object, &steps);
				break;
			case -30:
				stage_8_start_wait_end(&object, &steps);
				break;
			case -28:
				stage_8_start_player_ride(object);
				break;
			case -26:
				stage_8_start_player_drop(object);
				break;
			case -24:
				stage_8_start_player_look(object);
				break;
			case -22:
				stage_8_start_player_turn(object);
				break;
			case -20:
				stage_8_start_player_run(object);
				break;
			case -18:
				stage_8_start_player_gone(object);
				break;
			case -16:
				stage_8_end_set_up(&object, &steps);
				break;
			case -14:
				stage_8_end_show(&object, &steps);
				break;
			case -12:
				stage_8_end_hold();
				break;
			case -10:
				stage_8_end_switch_view(&object, &steps);
				break;
			case -8:
				stage_8_end_show_kind_13(&object, &steps);
				break;
			case -6:
				stage_8_end_reunion(&object, &steps);
				break;
			case -4:
				stage_8_end_run_family(&object, &steps);
				break;
			case -2:
				stage_8_end_finish(&object, &steps);
				break;
			}
			object += 0x60u;
			actors_left = stack;
			stack = actors_left - 1u;
		} while (actors_left != 1u);
	}
	*p_object = object;
	*p_steps = steps;
}

/* The scene after stage 8's last boss: an actor that does nothing. */
void stage_8_end_actor_rest(void)
{
}

/* The scene after stage 8's last boss: a player walking in, by its step. */
void stage_8_end_walker(uint16_t *p_object, uint16_t *p_walker_steps)
{
	uint16_t object = (uint16_t)*p_object;
	uint16_t walker_steps = 0;
	uint8_t action = 0;

	for (;;)
	{
		walker_steps = stage_8_end_walker_actions_ADDRESS;
		action = OBJECT(object)->action;
		switch ((int8_t)(uint8_t)((uint32_t)action << 1))
		{
		case 0:
		case 8:
		case 16:
			stage_8_end_actor_start(object);
			break;
		case 2:
			stage_8_end_walker_go(object);
			break;
		case 4:
			stage_8_end_walker_arrive(object);
			break;
		case 6:
		case 14:
		case 22:
			stage_8_end_actor_done();
			break;
		case 10:
			stage_8_end_extra_go(object);
			break;
		case 12:
		case 20:
			stage_8_end_extra_arrive(object);
			break;
		case 18:
			stage_8_end_slow_extra_go(object);
			break;
		case 24:
			stage_8_end_taker_wait(object);
			break;
		case 26:
			stage_8_end_take_maggie(object);
			break;
		case 28:
			stage_8_end_holding_maggie(object);
			break;
		case 30:
			stage_8_end_taker_done();
			break;
		case -128:
			object = stage_end_put_jumpers(object);
			break;
		case -126:
			stage_end_run_jumpers(&object, &walker_steps);
			break;
		case -124:
			walker_steps = stage_end_jumper_wait(object, walker_steps);
			break;
		case -122:
			stage_end_jumper_fly(object);
			break;
		case -120:
			stage_end_jumper_last_leg(object);
			break;
		case -118:
			stage_end_jumper_vanish(object);
			break;
		case -116:
			scene_clear(&object, &walker_steps);
			break;
		case -114:
			stage_5_end_set_up(&object, &walker_steps);
			break;
		case -112:
			stage_end_jump_away(&object, &walker_steps);
			break;
		case -110:
			stage_5_end_show_players(&object, &walker_steps);
			break;
		case -108:
			walker_steps = stage_5_end_fade(walker_steps);
			break;
		case -106:
			stage_5_end_finish(&object, &walker_steps);
			break;
		case -104:
			stage_6_end_start();
			break;
		case -102:
			walker_steps = stage_6_end_effect(walker_steps);
			break;
		case -100:
			stage_6_end_finish(&object, &walker_steps);
			break;
		case -98:
			stage_6_wake_set_up(&object, &walker_steps);
			break;
		case -96:
			stage_6_wake_show_players(&object, &walker_steps);
			break;
		case -94:
			stage_6_wake_start();
			break;
		case -92:
			stage_6_wake_wave(&object, &walker_steps);
			break;
		case -90:
			post_bonus_2_scene_set_up(&object, &walker_steps);
			break;
		case -88:
			post_bonus_2_scene_show(&object, &walker_steps);
			break;
		case -86:
			post_bonus_2_scene_wait();
			break;
		case -84:
			post_bonus_2_scene_pan();
			break;
		case -82:
			post_bonus_2_scene_finish();
			break;
		case -80:
			object = stage_7_scene_set_up();
			break;
		case -78:
			stage_7_scene_wait_scroll();
			break;
		case -76:
			stage_7_scene_wait_signal();
			break;
		case -74:
			stage_7_scene_lift(&object, &walker_steps);
			break;
		case -72:
			stage_7_scene_wait_train();
			break;
		case -70:
			stage_7_scene_put_chain(&object, &walker_steps);
			break;
		case -68:
			stage_7_scene_move_chain(&object, &walker_steps);
			break;
		case -66:
			stage_7_scene_chain_done();
			break;
		case -64:
			stage_7_end_set_up(&object, &walker_steps);
			break;
		case -62:
			stage_7_end_show(&object, &walker_steps);
			break;
		case -60:
			stage_7_end_board(object);
			break;
		case -58:
			object = stage_7_end_take_off();
			break;
		case -56:
			stage_7_end_slow_down(&object, &walker_steps);
			break;
		case -54:
			stage_7_end_finish(&object, &walker_steps);
			break;
		case -52:
			stage_8_start_set_up(&object, &walker_steps);
			break;
		case -50:
			stage_8_start_show(&object, &walker_steps);
			break;
		case -48:
			stage_8_start_descend(&object, &walker_steps);
			break;
		case -46:
			stage_8_start_stop(&object, &walker_steps);
			break;
		case -44:
			object = stage_8_start_landing();
			break;
		case -42:
			stage_8_start_run_off(&object, &walker_steps);
			break;
		case -40:
			stage_8_start_wait_end(&object, &walker_steps);
			break;
		case -38:
			stage_8_start_player_ride(object);
			break;
		case -36:
			stage_8_start_player_drop(object);
			break;
		case -34:
			stage_8_start_player_look(object);
			break;
		case -32:
			stage_8_start_player_turn(object);
			break;
		case -30:
			stage_8_start_player_run(object);
			break;
		case -28:
			stage_8_start_player_gone(object);
			break;
		case -26:
			stage_8_end_set_up(&object, &walker_steps);
			break;
		case -24:
			stage_8_end_show(&object, &walker_steps);
			break;
		case -22:
			stage_8_end_hold();
			break;
		case -20:
			stage_8_end_switch_view(&object, &walker_steps);
			break;
		case -18:
			stage_8_end_show_kind_13(&object, &walker_steps);
			break;
		case -16:
			stage_8_end_reunion(&object, &walker_steps);
			break;
		case -14:
			stage_8_end_run_family(&object, &walker_steps);
			break;
		case -12:
			stage_8_end_finish(&object, &walker_steps);
			break;
		case -10:
			stage_8_end_actor_rest();
			break;
		case -8:
			continue;
		case -6:
			stage_8_end_maggie_taker(&object, &walker_steps);
			break;
		case -4:
			stage_8_end_extra(&object, &walker_steps);
			break;
		case -2:
			stage_8_end_slow_extra(&object, &walker_steps);
			break;
		}
		break;
	}
	*p_object = object;
	*p_walker_steps = walker_steps;
}

/* The scene after stage 8's last boss: an actor's 32-frame wait. */
void stage_8_end_actor_start(uint16_t object)
{
	uint8_t action = 0;

	OBJECT(object)->stage_8_end.actor_wait = 0x20u;
	action = OBJECT(object)->action;
	OBJECT(object)->action = action + 1u;
}

/* The scene after stage 8's last boss: after the wait, the player runs in. */
void stage_8_end_walker_go(uint16_t object)
{
	uint8_t actor_wait = 0, action = 0;

	actor_wait = OBJECT(object)->stage_8_end.actor_wait;
	OBJECT(object)->stage_8_end.actor_wait = actor_wait - 1u;
	if (actor_wait == 1u)
	{
		OBJECT(object)->x_speed = 0x300;
		OBJECT(object)->animation = 0x81u;
		action = OBJECT(object)->action;
		OBJECT(object)->action = action + 1u;
	}
}

/* The scene after stage 8's last boss: the player stops by Maggie with a shout. */
void stage_8_end_walker_arrive(uint16_t object)
{
	uint16_t command = 0, distance = 0;
	uint8_t walker_player = 0, action = 0;
	uint16_t walker_x = 0, walker_offset = 0, spot_x = 0, past_spot = 0;

	walker_x = OBJECT(object)->x;
	walker_offset = OBJECT(object)->stage_8_end.stop_offset;
	spot_x = io_read16(reunion_spot_x);
	past_spot = walker_x + walker_offset - spot_x;
	distance = past_spot;
	if ((int16_t)past_spot < 0 || (int16_t)distance < 0x20)
		return;
	walker_player = OBJECT(object)->stage_8_end.actor_player;
	command = walker_player + 0x3F08u;
	vector_queue_sound(command);
	OBJECT(object)->x_speed = 0;
	OBJECT(object)->animation = 0x9Eu;
	action = OBJECT(object)->action;
	OBJECT(object)->action = action + 1u;
}

/* The scene after stage 8's last boss: an actor that has finished. */
void stage_8_end_actor_done(void)
{
}

/* The scene after stage 8's last boss: an extra character walking in, by its step. */
void stage_8_end_extra(uint16_t *p_object, uint16_t *p_extra_steps)
{
	uint16_t object = (uint16_t)*p_object;
	uint16_t extra_steps = 0;
	uint8_t action = 0;

	for (;;)
	{
		extra_steps = stage_8_end_extra_actions_ADDRESS;
		action = OBJECT(object)->action;
		switch ((int8_t)(uint8_t)((uint32_t)action << 1))
		{
		case -8:
		case 0:
		case 8:
			stage_8_end_actor_start(object);
			break;
		case 2:
			stage_8_end_extra_go(object);
			break;
		case 4:
		case 12:
			stage_8_end_extra_arrive(object);
			break;
		case -2:
		case 6:
		case 14:
			stage_8_end_actor_done();
			break;
		case 10:
			stage_8_end_slow_extra_go(object);
			break;
		case 16:
			stage_8_end_taker_wait(object);
			break;
		case 18:
			stage_8_end_take_maggie(object);
			break;
		case 20:
			stage_8_end_holding_maggie(object);
			break;
		case 22:
			stage_8_end_taker_done();
			break;
		case -128:
			stage_end_jumper_last_leg(object);
			break;
		case -126:
			stage_end_jumper_vanish(object);
			break;
		case -124:
			scene_clear(&object, &extra_steps);
			break;
		case -122:
			stage_5_end_set_up(&object, &extra_steps);
			break;
		case -120:
			stage_end_jump_away(&object, &extra_steps);
			break;
		case -118:
			stage_5_end_show_players(&object, &extra_steps);
			break;
		case -116:
			extra_steps = stage_5_end_fade(extra_steps);
			break;
		case -114:
			stage_5_end_finish(&object, &extra_steps);
			break;
		case -112:
			stage_6_end_start();
			break;
		case -110:
			extra_steps = stage_6_end_effect(extra_steps);
			break;
		case -108:
			stage_6_end_finish(&object, &extra_steps);
			break;
		case -106:
			stage_6_wake_set_up(&object, &extra_steps);
			break;
		case -104:
			stage_6_wake_show_players(&object, &extra_steps);
			break;
		case -102:
			stage_6_wake_start();
			break;
		case -100:
			stage_6_wake_wave(&object, &extra_steps);
			break;
		case -98:
			post_bonus_2_scene_set_up(&object, &extra_steps);
			break;
		case -96:
			post_bonus_2_scene_show(&object, &extra_steps);
			break;
		case -94:
			post_bonus_2_scene_wait();
			break;
		case -92:
			post_bonus_2_scene_pan();
			break;
		case -90:
			post_bonus_2_scene_finish();
			break;
		case -88:
			object = stage_7_scene_set_up();
			break;
		case -86:
			stage_7_scene_wait_scroll();
			break;
		case -84:
			stage_7_scene_wait_signal();
			break;
		case -82:
			stage_7_scene_lift(&object, &extra_steps);
			break;
		case -80:
			stage_7_scene_wait_train();
			break;
		case -78:
			stage_7_scene_put_chain(&object, &extra_steps);
			break;
		case -76:
			stage_7_scene_move_chain(&object, &extra_steps);
			break;
		case -74:
			stage_7_scene_chain_done();
			break;
		case -72:
			stage_7_end_set_up(&object, &extra_steps);
			break;
		case -70:
			stage_7_end_show(&object, &extra_steps);
			break;
		case -68:
			stage_7_end_board(object);
			break;
		case -66:
			object = stage_7_end_take_off();
			break;
		case -64:
			stage_7_end_slow_down(&object, &extra_steps);
			break;
		case -62:
			stage_7_end_finish(&object, &extra_steps);
			break;
		case -60:
			stage_8_start_set_up(&object, &extra_steps);
			break;
		case -58:
			stage_8_start_show(&object, &extra_steps);
			break;
		case -56:
			stage_8_start_descend(&object, &extra_steps);
			break;
		case -54:
			stage_8_start_stop(&object, &extra_steps);
			break;
		case -52:
			object = stage_8_start_landing();
			break;
		case -50:
			stage_8_start_run_off(&object, &extra_steps);
			break;
		case -48:
			stage_8_start_wait_end(&object, &extra_steps);
			break;
		case -46:
			stage_8_start_player_ride(object);
			break;
		case -44:
			stage_8_start_player_drop(object);
			break;
		case -42:
			stage_8_start_player_look(object);
			break;
		case -40:
			stage_8_start_player_turn(object);
			break;
		case -38:
			stage_8_start_player_run(object);
			break;
		case -36:
			stage_8_start_player_gone(object);
			break;
		case -34:
			stage_8_end_set_up(&object, &extra_steps);
			break;
		case -32:
			stage_8_end_show(&object, &extra_steps);
			break;
		case -30:
			stage_8_end_hold();
			break;
		case -28:
			stage_8_end_switch_view(&object, &extra_steps);
			break;
		case -26:
			stage_8_end_show_kind_13(&object, &extra_steps);
			break;
		case -24:
			stage_8_end_reunion(&object, &extra_steps);
			break;
		case -22:
			stage_8_end_run_family(&object, &extra_steps);
			break;
		case -20:
			stage_8_end_finish(&object, &extra_steps);
			break;
		case -18:
			stage_8_end_actor_rest();
			break;
		case -16:
			stage_8_end_walker(&object, &extra_steps);
			break;
		case -14:
			stage_8_end_maggie_taker(&object, &extra_steps);
			break;
		case -12:
			continue;
		case -10:
			stage_8_end_slow_extra(&object, &extra_steps);
			break;
		case -6:
			stage_8_end_walker_go(object);
			break;
		case -4:
			stage_8_end_walker_arrive(object);
			break;
		}
		break;
	}
	*p_object = object;
	*p_extra_steps = extra_steps;
}

/* The scene after stage 8's last boss: after the wait, the extra walks in. */
void stage_8_end_extra_go(uint16_t object)
{
	uint8_t actor_wait = 0, action = 0;

	actor_wait = OBJECT(object)->stage_8_end.actor_wait;
	OBJECT(object)->stage_8_end.actor_wait = actor_wait - 1u;
	if (actor_wait == 1u)
	{
		OBJECT(object)->x_speed = 0x200;
		action = OBJECT(object)->action;
		OBJECT(object)->action = action + 1u;
	}
}

/* The scene after stage 8's last boss: the extra stops by Maggie. */
void stage_8_end_extra_arrive(uint16_t object)
{
	uint16_t distance = 0;
	uint8_t animation = 0, action = 0;
	uint16_t extra_x = 0, extra_offset = 0, spot_x = 0, past_spot = 0;

	extra_x = OBJECT(object)->x;
	extra_offset = OBJECT(object)->stage_8_end.stop_offset;
	spot_x = io_read16(reunion_spot_x);
	past_spot = extra_x + extra_offset - spot_x;
	distance = past_spot;
	if ((int16_t)past_spot >= 0 && (int16_t)distance >= 0x20)
	{
		OBJECT(object)->x_speed = 0;
		animation = OBJECT(object)->animation;
		OBJECT(object)->animation = (uint16_t)((((uint16_t)((uint32_t)(uint8_t)(((uint16_t)((uint32_t)animation << 8) >> 8) - 1u) << 8) >> 8) | 0x80u) << 8) >> 8;
		action = OBJECT(object)->action;
		OBJECT(object)->action = action + 1u;
	}
}

/* The scene after stage 8's last boss: the slow extra walking in, by its step. */
void stage_8_end_slow_extra(uint16_t *p_object, uint16_t *p_slow_extra_steps)
{
	uint16_t object = (uint16_t)*p_object;
	uint16_t slow_extra_steps = 0;
	uint8_t action = 0;

	for (;;)
	{
		slow_extra_steps = stage_8_end_slow_extra_actions_ADDRESS;
		action = OBJECT(object)->action;
		switch ((int8_t)(uint8_t)((uint32_t)action << 1))
		{
		case -16:
		case -8:
		case 0:
			stage_8_end_actor_start(object);
			break;
		case 2:
			stage_8_end_slow_extra_go(object);
			break;
		case -4:
		case 4:
			stage_8_end_extra_arrive(object);
			break;
		case -10:
		case -2:
		case 6:
			stage_8_end_actor_done();
			break;
		case 8:
			stage_8_end_taker_wait(object);
			break;
		case 10:
			stage_8_end_take_maggie(object);
			break;
		case 12:
			stage_8_end_holding_maggie(object);
			break;
		case 14:
			stage_8_end_taker_done();
			break;
		case -128:
			stage_end_jump_away(&object, &slow_extra_steps);
			break;
		case -126:
			stage_5_end_show_players(&object, &slow_extra_steps);
			break;
		case -124:
			slow_extra_steps = stage_5_end_fade(slow_extra_steps);
			break;
		case -122:
			stage_5_end_finish(&object, &slow_extra_steps);
			break;
		case -120:
			stage_6_end_start();
			break;
		case -118:
			slow_extra_steps = stage_6_end_effect(slow_extra_steps);
			break;
		case -116:
			stage_6_end_finish(&object, &slow_extra_steps);
			break;
		case -114:
			stage_6_wake_set_up(&object, &slow_extra_steps);
			break;
		case -112:
			stage_6_wake_show_players(&object, &slow_extra_steps);
			break;
		case -110:
			stage_6_wake_start();
			break;
		case -108:
			stage_6_wake_wave(&object, &slow_extra_steps);
			break;
		case -106:
			post_bonus_2_scene_set_up(&object, &slow_extra_steps);
			break;
		case -104:
			post_bonus_2_scene_show(&object, &slow_extra_steps);
			break;
		case -102:
			post_bonus_2_scene_wait();
			break;
		case -100:
			post_bonus_2_scene_pan();
			break;
		case -98:
			post_bonus_2_scene_finish();
			break;
		case -96:
			object = stage_7_scene_set_up();
			break;
		case -94:
			stage_7_scene_wait_scroll();
			break;
		case -92:
			stage_7_scene_wait_signal();
			break;
		case -90:
			stage_7_scene_lift(&object, &slow_extra_steps);
			break;
		case -88:
			stage_7_scene_wait_train();
			break;
		case -86:
			stage_7_scene_put_chain(&object, &slow_extra_steps);
			break;
		case -84:
			stage_7_scene_move_chain(&object, &slow_extra_steps);
			break;
		case -82:
			stage_7_scene_chain_done();
			break;
		case -80:
			stage_7_end_set_up(&object, &slow_extra_steps);
			break;
		case -78:
			stage_7_end_show(&object, &slow_extra_steps);
			break;
		case -76:
			stage_7_end_board(object);
			break;
		case -74:
			object = stage_7_end_take_off();
			break;
		case -72:
			stage_7_end_slow_down(&object, &slow_extra_steps);
			break;
		case -70:
			stage_7_end_finish(&object, &slow_extra_steps);
			break;
		case -68:
			stage_8_start_set_up(&object, &slow_extra_steps);
			break;
		case -66:
			stage_8_start_show(&object, &slow_extra_steps);
			break;
		case -64:
			stage_8_start_descend(&object, &slow_extra_steps);
			break;
		case -62:
			stage_8_start_stop(&object, &slow_extra_steps);
			break;
		case -60:
			object = stage_8_start_landing();
			break;
		case -58:
			stage_8_start_run_off(&object, &slow_extra_steps);
			break;
		case -56:
			stage_8_start_wait_end(&object, &slow_extra_steps);
			break;
		case -54:
			stage_8_start_player_ride(object);
			break;
		case -52:
			stage_8_start_player_drop(object);
			break;
		case -50:
			stage_8_start_player_look(object);
			break;
		case -48:
			stage_8_start_player_turn(object);
			break;
		case -46:
			stage_8_start_player_run(object);
			break;
		case -44:
			stage_8_start_player_gone(object);
			break;
		case -42:
			stage_8_end_set_up(&object, &slow_extra_steps);
			break;
		case -40:
			stage_8_end_show(&object, &slow_extra_steps);
			break;
		case -38:
			stage_8_end_hold();
			break;
		case -36:
			stage_8_end_switch_view(&object, &slow_extra_steps);
			break;
		case -34:
			stage_8_end_show_kind_13(&object, &slow_extra_steps);
			break;
		case -32:
			stage_8_end_reunion(&object, &slow_extra_steps);
			break;
		case -30:
			stage_8_end_run_family(&object, &slow_extra_steps);
			break;
		case -28:
			stage_8_end_finish(&object, &slow_extra_steps);
			break;
		case -26:
			stage_8_end_actor_rest();
			break;
		case -24:
			stage_8_end_walker(&object, &slow_extra_steps);
			break;
		case -22:
			stage_8_end_maggie_taker(&object, &slow_extra_steps);
			break;
		case -20:
			stage_8_end_extra(&object, &slow_extra_steps);
			break;
		case -18:
			continue;
		case -14:
			stage_8_end_walker_go(object);
			break;
		case -12:
			stage_8_end_walker_arrive(object);
			break;
		case -6:
			stage_8_end_extra_go(object);
			break;
		}
		break;
	}
	*p_object = object;
	*p_slow_extra_steps = slow_extra_steps;
}

/* The scene after stage 8's last boss: after the wait, the slow extra walks in. */
void stage_8_end_slow_extra_go(uint16_t object)
{
	uint8_t actor_wait = 0, action = 0;

	actor_wait = OBJECT(object)->stage_8_end.actor_wait;
	OBJECT(object)->stage_8_end.actor_wait = actor_wait - 1u;
	if (actor_wait == 1u)
	{
		OBJECT(object)->x_speed = 0x100;
		action = OBJECT(object)->action;
		OBJECT(object)->action = action + 1u;
	}
}

/* The scene after stage 8's last boss: the player picked to get Maggie, by its step. */
void stage_8_end_maggie_taker(uint16_t *p_object, uint16_t *p_taker_steps)
{
	uint16_t object = (uint16_t)*p_object;
	uint16_t taker_steps = 0;
	uint8_t action = 0;

	for (;;)
	{
		taker_steps = stage_8_end_maggie_taker_actions_ADDRESS;
		action = OBJECT(object)->action;
		switch ((int8_t)(uint8_t)((uint32_t)action << 1))
		{
		case 0:
			stage_8_end_taker_wait(object);
			break;
		case 2:
			stage_8_end_take_maggie(object);
			break;
		case 4:
			stage_8_end_holding_maggie(object);
			break;
		case 6:
			stage_8_end_taker_done();
			break;
		case -128:
			stage_6_end_start();
			break;
		case -126:
			taker_steps = stage_6_end_effect(taker_steps);
			break;
		case -124:
			stage_6_end_finish(&object, &taker_steps);
			break;
		case -122:
			stage_6_wake_set_up(&object, &taker_steps);
			break;
		case -120:
			stage_6_wake_show_players(&object, &taker_steps);
			break;
		case -118:
			stage_6_wake_start();
			break;
		case -116:
			stage_6_wake_wave(&object, &taker_steps);
			break;
		case -114:
			post_bonus_2_scene_set_up(&object, &taker_steps);
			break;
		case -112:
			post_bonus_2_scene_show(&object, &taker_steps);
			break;
		case -110:
			post_bonus_2_scene_wait();
			break;
		case -108:
			post_bonus_2_scene_pan();
			break;
		case -106:
			post_bonus_2_scene_finish();
			break;
		case -104:
			object = stage_7_scene_set_up();
			break;
		case -102:
			stage_7_scene_wait_scroll();
			break;
		case -100:
			stage_7_scene_wait_signal();
			break;
		case -98:
			stage_7_scene_lift(&object, &taker_steps);
			break;
		case -96:
			stage_7_scene_wait_train();
			break;
		case -94:
			stage_7_scene_put_chain(&object, &taker_steps);
			break;
		case -92:
			stage_7_scene_move_chain(&object, &taker_steps);
			break;
		case -90:
			stage_7_scene_chain_done();
			break;
		case -88:
			stage_7_end_set_up(&object, &taker_steps);
			break;
		case -86:
			stage_7_end_show(&object, &taker_steps);
			break;
		case -84:
			stage_7_end_board(object);
			break;
		case -82:
			object = stage_7_end_take_off();
			break;
		case -80:
			stage_7_end_slow_down(&object, &taker_steps);
			break;
		case -78:
			stage_7_end_finish(&object, &taker_steps);
			break;
		case -76:
			stage_8_start_set_up(&object, &taker_steps);
			break;
		case -74:
			stage_8_start_show(&object, &taker_steps);
			break;
		case -72:
			stage_8_start_descend(&object, &taker_steps);
			break;
		case -70:
			stage_8_start_stop(&object, &taker_steps);
			break;
		case -68:
			object = stage_8_start_landing();
			break;
		case -66:
			stage_8_start_run_off(&object, &taker_steps);
			break;
		case -64:
			stage_8_start_wait_end(&object, &taker_steps);
			break;
		case -62:
			stage_8_start_player_ride(object);
			break;
		case -60:
			stage_8_start_player_drop(object);
			break;
		case -58:
			stage_8_start_player_look(object);
			break;
		case -56:
			stage_8_start_player_turn(object);
			break;
		case -54:
			stage_8_start_player_run(object);
			break;
		case -52:
			stage_8_start_player_gone(object);
			break;
		case -50:
			stage_8_end_set_up(&object, &taker_steps);
			break;
		case -48:
			stage_8_end_show(&object, &taker_steps);
			break;
		case -46:
			stage_8_end_hold();
			break;
		case -44:
			stage_8_end_switch_view(&object, &taker_steps);
			break;
		case -42:
			stage_8_end_show_kind_13(&object, &taker_steps);
			break;
		case -40:
			stage_8_end_reunion(&object, &taker_steps);
			break;
		case -38:
			stage_8_end_run_family(&object, &taker_steps);
			break;
		case -36:
			stage_8_end_finish(&object, &taker_steps);
			break;
		case -34:
			stage_8_end_actor_rest();
			break;
		case -32:
			stage_8_end_walker(&object, &taker_steps);
			break;
		case -30:
			continue;
		case -28:
			stage_8_end_extra(&object, &taker_steps);
			break;
		case -26:
			stage_8_end_slow_extra(&object, &taker_steps);
			break;
		case -24:
		case -16:
		case -8:
			stage_8_end_actor_start(object);
			break;
		case -22:
			stage_8_end_walker_go(object);
			break;
		case -20:
			stage_8_end_walker_arrive(object);
			break;
		case -18:
		case -10:
		case -2:
			stage_8_end_actor_done();
			break;
		case -14:
			stage_8_end_extra_go(object);
			break;
		case -12:
		case -4:
			stage_8_end_extra_arrive(object);
			break;
		case -6:
			stage_8_end_slow_extra_go(object);
			break;
		}
		break;
	}
	*p_object = object;
	*p_taker_steps = taker_steps;
}

/* The scene after stage 8's last boss: the picked player waits 128 frames. */
void stage_8_end_taker_wait(uint16_t object)
{
	uint8_t action = 0;

	OBJECT(object)->stage_8_end.actor_wait = 0x80u;
	action = OBJECT(object)->action;
	OBJECT(object)->action = action + 1u;
}

/* The scene after stage 8's last boss: the picked player takes Maggie. */
void stage_8_end_take_maggie(uint16_t object)
{
	uint16_t command = 0;
	uint8_t actor_wait = 0, action = 0;

	actor_wait = OBJECT(object)->stage_8_end.actor_wait;
	OBJECT(object)->stage_8_end.actor_wait = actor_wait - 1u;
	if (actor_wait == 1u)
	{
		OBJECT(object)->animation = 0xAEu;
		action = OBJECT(object)->action;
		OBJECT(object)->action = action + 1u;
	}
	if ((frame_count & 0x1Fu) == 0u)
	{
		command = 0x4500u;
		vector_queue_sound(command);
	}
}

/* The scene after stage 8's last boss: Maggie is in the player's arms (with two voices when all four
   played). */
void stage_8_end_holding_maggie(uint16_t object)
{
	uint16_t command = 0;
	uint8_t animation_flags = 0, action = 0;

	animation_flags = OBJECT(object)->animation_flags;
	if ((animation_flags & 1u) == 0u)
		return;
	if (players_present == 0xFu)
	{
		command = 0x3F09u;
		vector_queue_sound(command);
		command = 0x3F0Au;
		vector_queue_sound(command);
	}
	OBJECT(OBJECT_ADDRESS(29))->flags = 0u;
	action = OBJECT(object)->action;
	OBJECT(object)->action = action + 1u;
}

/* The scene after stage 8's last boss: the picked player has finished. */
void stage_8_end_taker_done(void)
{
}

/* The scene after stage 8's last boss: waits in area 3, then it is over. */
void stage_8_end_finish(uint16_t *p_x, uint16_t *p_u)
{
	uint16_t x = (uint16_t)*p_x;
	uint16_t u = (uint16_t)*p_u;
	uint16_t command = 0;
	uint16_t finish_wait = 0;

	io_write8(colour_bases_back_sprites_fixed, 0x13u);
	io_write8(colour_bases_layers_a_b, 0x2Cu);
	finish_wait = io_read16(scene_wait);
	io_write16(scene_wait, finish_wait - 1u);
	if (finish_wait == 1u)
	{
		vector_clear_objects(&x, &u);
		scene_running = 0u;
	}
	else if ((frame_count & 0x1Fu) == 0u)
	{
		command = 0x4500u;
		vector_queue_sound(command);
	}
	*p_x = x;
	*p_u = u;
}

/* Unused: would blink an object by the frame and play a sound (4500) every 32 frames. */
void unused_stage_8_end_blink(void)
{
	uint16_t command = 0;

	OBJECT(OBJECT_ADDRESS(9))->flags = ((((uint8_t)frame_count & 0x10u) << 1) << 1) << 1;
	OBJECT(OBJECT_ADDRESS(9))->animation_flags = 0x80u;
	if ((frame_count & 0x1Fu) == 0u)
	{
		command = 0x4500u;
		vector_queue_sound(command);
	}
}
