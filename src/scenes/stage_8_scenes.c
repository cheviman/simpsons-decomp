/**
 *    Name:        scenes/stage_8_scenes.c
 *    Description: stage 8's opening and the scene after its last boss
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    09-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the game's 053248 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

/* Stage 8's opening: stops the sound, loads its colours and clears the screen. */
void stage_8_start_set_up(uint16_t *p_x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t u = (uint16_t)*p_u;
	uint16_t command = 0, ignored16 = 0, ignored16_2 = 0, job = 0, request = 0, scroll_x = 0, scroll_y = 0, u_2 = 0, x = 0, y = 0;
	uint8_t t1 = 0;

	job = 0u;
	vector_queue_job(job);
	command = 0u;
	vector_queue_sound_always(command);
	palette_request_kind = 1u;
	request = 0xE91u;
	vector_palette_request(request, &ignored16, &u);
	scroll_x = 0xFFF0u;
	vector_set_scroll_x(scroll_x);
	scroll_y = 0u;
	layer_b_scroll_x = 0u;
	vector_set_scroll_y(scroll_y);
	layer_b_scroll_y = 0x100u;
	layer_b_edges_on = 1u;
	layer_rows_on = 1u;
	vector_clear_objects(&ignored16_2, &u_2);
	vector_clear_sprites(&x, &y);
	t1 = io_read8(scene_state);
	io_write8(scene_state, t1 + 1u);
	*p_x = x;
	*p_y = y;
	*p_u = u_2;
}

/* Stage 8's opening: the power plant's area 0, the kind-A4 objects, the kind-13 object and the players
   who played, then the music (9600). */
void stage_8_start_show(uint16_t *p_x, uint16_t *p_object, uint16_t *p_u)
{
	uint16_t x = (uint16_t)*p_x;
	uint16_t object = (uint16_t)*p_object;
	uint16_t u = (uint16_t)*p_u;
	uint32_t carry = 0;
	uint16_t command = 0, d = 0, ignored16 = 0, ignored16_2 = 0, ignored16_3 = 0, layer_and_columns = 0, record_number = 0, u_2 = 0, x_2 = 0;
	uint8_t t1 = 0, t2 = 0;

	if (layer_clear_pending != 0u)
		return;
	io_write8(0x1FB9u, 0x3Fu);
	io_write8(0x1FBAu, 0x36u);
	map_scene = 0x8Du;
	map_area = 0u;
	vector_set_layer_modes();
	layer_and_columns = 0x26u;
	vector_draw_layer_strips(layer_and_columns, &ignored16, &ignored16_2, &ignored16_3);
	layer_and_columns = 0x126u;
	vector_draw_layer_strips(layer_and_columns, &x_2, &ignored16_2, &u_2);
	io_write8(0x1FB9u, 0x13u);
	io_write8(0x1FBAu, 0x2Cu);
	record_number = 0x2E26u;
	scene_put_placement(x_2, record_number);
	record_number = 0x2F26u;
	scene_put_placement(x_2, record_number);
	record_number = 0x3026u;
	object = scene_put_placement(x_2, record_number);
	OBJECT(object)->flags |= 8u;
	OBJECT(object)->shadow_player = 1u;
	record_number = 0x3126u;
	scene_put_placement(x_2, record_number);
	d = 0x3226u;
	object = scene_put_placement(x_2, d);
	OBJECT(object)->attributes = 0x10u;
	scene_riders_left = 4u;
	rider_bits = players_present;
	rider_kind = 0x2Au;
	do
	{
		if ((rider_bits & 1u) != 0u)
		{
			d = (d & 0xFFu) | ((uint32_t)rider_kind << 8);
			object = scene_put_placement(x_2, d);
			OBJECT(object)->flags |= 8u;
			OBJECT(object)->action = scene_riders_left * 0x10u + 0x10u;
		}
		rider_bits = rider_bits >> 1;
		rider_kind++;
		t1 = scene_riders_left;
		scene_riders_left = t1 - 1u;
	} while (t1 != 1u);
	command = 0x9600u;
	carry = vector_queue_sound(command);
	io_write16(0x18EBu, 0x400u);
	t2 = io_read8(scene_state);
	io_write8(scene_state, t2 + 1u);
	*p_x = x_2;
	*p_object = object;
	*p_u = u_2;
}

/* Stage 8's opening: the view goes down, slowing, the players with it; at the bottom one of the kind-A4
   objects turns into the kind-9C character and jumps out. */
void stage_8_start_descend(uint16_t *p_object, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = (uint16_t)*p_u;
	uint32_t carry = 0;
	uint16_t descent_speed = 0, ignored16 = 0, object = 0, scroll_y_low = 0;
	uint8_t t3 = 0, t5 = 0;
	uint16_t t1 = 0, t2 = 0, t4 = 0;
	uint32_t layer_b_scroll_y_halfword = 0;

	stage_8_start_run_players(&ignored16, &y, &u);
	t1 = io_read16(0x18EBu);
	descent_speed = t1 - 9u;
	if ((int16_t)descent_speed <= 9)
		descent_speed = 9u;
	io_write16(0x18EBu, descent_speed);
	scroll_y_low = (((uint32_t)(layer_b_scroll_y & 0xFFu) << 8u) | layer_b_scroll_y_fraction);
	t2 = io_read16(0x18EBu);
	carry = scroll_y_low < t2;
	layer_b_scroll_y_halfword = scroll_y_low - t2;
	layer_b_scroll_y = (layer_b_scroll_y & 0xFF00u) | ((layer_b_scroll_y_halfword >> 8u) & 0xFFu);
	layer_b_scroll_y_fraction = (uint8_t)layer_b_scroll_y_halfword;
	layer_b_scroll_y = (layer_b_scroll_y & 0xFFu) | (((uint16_t)((uint32_t)(uint8_t)(((uint16_t)((uint32_t)(uint8_t)(layer_b_scroll_y >> 8u) << 8) >> 8) - carry) << 8) >> 8 & 0xFFu) << 8u);
	if ((int16_t)layer_b_scroll_y <= 0x20)
	{
		OBJECT(OBJECT_ADDRESS(26))->kind = 0x9Cu;
		OBJECT(OBJECT_ADDRESS(26))->animation = 0x83u;
		OBJECT(OBJECT_ADDRESS(26))->x_speed = 0x300;
		OBJECT(OBJECT_ADDRESS(26))->z_speed = 0x200;
		io_write16(0x18E2u, 0x80u);
		layer_b_scroll_y = 0x20u;
		layer_b_scroll_y_fraction = 0u;
		t3 = io_read8(scene_state);
		io_write8(scene_state, t3 + 1u);
	}
	object = OBJECT_ADDRESS(26);
	scene_objects_left = 4u;
	do
	{
		t4 = io_read16(0x18EBu);
		OBJECT(object)->z_speed = 0u - t4;
		object += 0x60u;
		t5 = scene_objects_left;
		scene_objects_left = t5 - 1u;
	} while (t5 != 1u);
	*p_object = object;
	*p_y = y;
	*p_u = u;
}

/* Stage 8's opening: the descent is over. */
void stage_8_start_stop(uint16_t *p_object, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = (uint16_t)*p_u;
	uint8_t a = 0, d = 0;
	uint16_t object = 0;
	uint8_t t1 = 0, t2 = 0;

	object = OBJECT_ADDRESS(27);
	scene_objects_left = 3u;
	d = 0u;
	a = 0u;
	do
	{
		OBJECT(object)->z_speed = (uint32_t)a << 8;
		object += 0x60u;
		t1 = scene_objects_left;
		scene_objects_left = t1 - 1u;
	} while (t1 != 1u);
	stage_8_start_run_players(&object, &y, &u);
	t2 = io_read8(scene_state);
	io_write8(scene_state, t2 + 1u);
	*p_object = object;
	*p_y = y;
	*p_u = u;
}

/* Stage 8's opening: the kind-9C character lands (sound 6000) and runs. */
uint16_t stage_8_start_landing(void)
{
	uint32_t carry = 0;
	uint16_t command = 0, ignored16 = 0, object = 0;
	uint8_t t1 = 0;
	uint16_t z = 0;

	object = OBJECT_ADDRESS(26);
	vector_apply_gravity(object, &ignored16, &carry);
	z = OBJECT(object)->z;
	if ((int16_t)z > 0x38)
		return object;
	OBJECT(object)->animation = 0x81u;
	OBJECT(object)->z_speed = 0;
	command = 0x6000u;
	carry = vector_queue_sound(command);
	OBJECT(OBJECT_ADDRESS(30))->flags = 0u;
	OBJECT(object)->animation = 0x81u;
	t1 = io_read8(scene_state);
	io_write8(scene_state, t1 + 1u);
	return object;
}

/* Stage 8's opening: the kind-9C character runs off the screen. */
void stage_8_start_run_off(uint16_t *p_object, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = (uint16_t)*p_u;
	uint16_t ignored16 = 0, object = 0;
	uint8_t t1 = 0;

	stage_8_start_run_players(&ignored16, &y, &u);
	object = OBJECT_ADDRESS(26);
	if ((int16_t)OBJECT(OBJECT_ADDRESS(26))->x >= 0x150)
	{
		io_write16(0x18E2u, 0x80u);
		OBJECT(object)->flags = 0u;
		t1 = io_read8(scene_state);
		io_write8(scene_state, t1 + 1u);
	}
	*p_object = object;
	*p_y = y;
	*p_u = u;
}

/* Stage 8's opening: runs the players for the last 128 frames, then ends the scene (no scenario reaches
   its end here). */
void stage_8_start_wait_end(uint16_t *p_x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = (uint16_t)*p_u;
	uint16_t x = 0;
	uint16_t t1 = 0;

	t1 = io_read16(0x18E2u);
	io_write16(0x18E2u, t1 - 1u);
	if (t1 != 1u)
		stage_8_start_run_players(&x, &y, &u);
	else
		stage_8_start_finish(&x, &y, &u);
	*p_x = x;
	*p_y = y;
	*p_u = u;
}

/* Stage 8's opening is over: the scene's variables, the sound and the objects cleared. */
void stage_8_start_finish(uint16_t *p_x, uint16_t *p_clear_from, uint16_t *p_u)
{
	uint32_t carry = 0;
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
	carry = vector_queue_sound(command);
	vector_clear_objects(&x, &u);
	scene_running = 0u;
	*p_x = x;
	*p_clear_from = clear_from;
	*p_u = u;
}

/* Stage 8's opening: runs the players' objects by their state. */
void stage_8_start_run_players(uint16_t *p_object, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = (uint16_t)*p_u;
	uint16_t object = 0;
	uint8_t stack = 0;
	uint8_t state = 0, t1 = 0;

	stack = 4u;
	object = OBJECT_ADDRESS(22);
	do
	{
		if ((int8_t)OBJECT(object)->flags < 0)
		{
			u = stage_8_start_run_players_states_ADDRESS;
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
				stage_8_end_set_up(&object, &y, &u);
				break;
			case 14:
				stage_8_end_show(&object, &y, &u);
				break;
			case 16:
				stage_8_end_hold();
				break;
			case 18:
				stage_8_end_switch_view(&object, &y, &u);
				break;
			case 20:
				stage_8_end_show_kind_13(&object, &y, &u);
				break;
			case 22:
				stage_8_end_reunion(&object, &y, &u);
				break;
			case 24:
				stage_8_end_run_family(&object, &y, &u);
				break;
			case 26:
				stage_8_end_finish(&object, &u);
				break;
			case 28:
				stage_8_end_actor_rest();
				break;
			case 30:
				stage_8_end_walker(&object, &y, &u);
				break;
			case 32:
				stage_8_end_maggie_taker(&object, &y, &u);
				break;
			case 34:
				stage_8_end_extra(&object, &y, &u);
				break;
			case 36:
				stage_8_end_slow_extra(&object, &y, &u);
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
				u = stage_1_end_put_police_car(u);
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
				scene_clear(&object, &y, &u);
				break;
			case -104:
				stage_2_end_set_up(&object, &y, &u);
				break;
			case -102:
			case -74:
				stage_end_jump_away(&object, &y, &u);
				break;
			case -100:
				stage_2_end_show_area_3(&object, &y, &u);
				break;
			case -98:
				y = stage_2_end_put_players(object, y);
				break;
			case -96:
			case -94:
				stage_2_end_players_look_around(&object, &y, &u);
				break;
			case -92:
				scene_end(&object, &u);
				break;
			case -90:
				stage_end_put_jumpers(&object, &y);
				break;
			case -88:
				stage_end_run_jumpers(&object, &y, &u);
				break;
			case -86:
				u = stage_end_jumper_wait(object, u);
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
				stage_5_end_set_up(&object, &y, &u);
				break;
			case -72:
				stage_5_end_show_players(&object, &y, &u);
				break;
			case -70:
				stage_5_end_fade(&y, &u);
				break;
			case -68:
				stage_5_end_finish(&object, &y, &u);
				break;
			case -66:
				stage_6_end_start();
				break;
			case -64:
				stage_6_end_effect(&y, &u);
				break;
			case -62:
				stage_6_end_finish(&object, &y, &u);
				break;
			case -60:
				stage_6_wake_set_up(&object, &y, &u);
				break;
			case -58:
				stage_6_wake_show_players(&object, &y, &u);
				break;
			case -56:
				stage_6_wake_start();
				break;
			case -54:
				stage_6_wake_wave(&object, &u);
				break;
			case -52:
				post_bonus_2_scene_set_up(&object, &y, &u);
				break;
			case -50:
				post_bonus_2_scene_show(&object, &y, &u);
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
				stage_7_scene_set_up(&object, &y);
				break;
			case -40:
				stage_7_scene_wait_scroll();
				break;
			case -38:
				stage_7_scene_wait_signal();
				break;
			case -36:
				stage_7_scene_lift(&object, &y, &u);
				break;
			case -34:
				stage_7_scene_wait_train();
				break;
			case -32:
				stage_7_scene_put_chain(&object, &y, &u);
				break;
			case -30:
				stage_7_scene_move_chain(&object, &u);
				break;
			case -28:
				stage_7_scene_chain_done();
				break;
			case -26:
				stage_7_end_set_up(&object, &y, &u);
				break;
			case -24:
				stage_7_end_show(&object, &y, &u);
				break;
			case -22:
				y = stage_7_end_board(object);
				break;
			case -20:
				stage_7_end_take_off(&object, &y);
				break;
			case -18:
				stage_7_end_slow_down(&object, &u);
				break;
			case -16:
				stage_7_end_finish(&object, &u);
				break;
			case -14:
				stage_8_start_set_up(&object, &y, &u);
				break;
			case -12:
				stage_8_start_show(&object, &y, &u);
				break;
			case -10:
				stage_8_start_descend(&object, &y, &u);
				break;
			case -8:
				stage_8_start_stop(&object, &y, &u);
				break;
			case -6:
				object = stage_8_start_landing();
				break;
			case -4:
				stage_8_start_run_off(&object, &y, &u);
				break;
			case -2:
				stage_8_start_wait_end(&object, &y, &u);
				break;
			}
		}
		object += 0x60u;
		t1 = stack;
		stack = t1 - 1u;
	} while (t1 != 1u);
	*p_object = object;
	*p_y = y;
	*p_u = u;
}

/* Stage 8's opening: a player comes down with the view. */
void stage_8_start_player_ride(uint16_t object)
{
	uint8_t state = 0;
	uint16_t z = 0, t1 = 0;

	z = OBJECT(object)->z;
	if ((int16_t)z > 0xBF)
	{
		t1 = io_read16(0x18EBu);
		OBJECT(object)->z_speed = 0u - t1;
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
	uint16_t z = 0, t1 = 0;

	vector_apply_gravity(object, &ignored16, &carry);
	z = OBJECT(object)->z;
	if ((int16_t)z > 0x38)
		return;
	OBJECT(object)->animation = 0xD4u;
	OBJECT(object)->z_speed = 0;
	kind = OBJECT(object)->kind;
	t1 = kind + 0x3F24u;
	command = t1;
	carry = vector_queue_sound(command);
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
	uint16_t t1 = 0;

	t1 = OBJECT(object)->x;
	if ((int16_t)t1 >= 0x150)
		OBJECT(object)->flags = 0u;
}

/* The scene after stage 8's last boss: stops the sound, clears the tiles, loads its colours and clears
   the screen. */
void stage_8_end_set_up(uint16_t *p_x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t clear_from = 0, clear_to = 0, command = 0, count = 0, ignored16 = 0, ignored16_2 = 0, job = 0, request = 0, scroll_x = 0, scroll_y = 0, u = 0, x = 0, y = 0;
	uint8_t t1 = 0;

	job = 0u;
	vector_queue_job(job);
	command = 0u;
	vector_queue_sound_always(command);
	clear_from = 0x3C00u;
	clear_to = 0x3C01u;
	io_write8(0x3C00u, 0u);
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
	vector_palette_request(request, &ignored16, &count);
	scroll_x = 0xFFF0u;
	vector_set_scroll_x(scroll_x);
	scroll_y = 0u;
	vector_set_scroll_y(scroll_y);
	vector_clear_objects(&ignored16_2, &u);
	vector_clear_sprites(&x, &y);
	t1 = io_read8(scene_state);
	io_write8(scene_state, t1 + 1u);
	*p_x = x;
	*p_y = y;
	*p_u = u;
}

/* The scene after stage 8's last boss: the power plant's area 2 with the kind-13 object and the music
   (9600). */
void stage_8_end_show(uint16_t *p_x, uint16_t *p_object, uint16_t *p_u)
{
	uint16_t x = (uint16_t)*p_x;
	uint16_t object = (uint16_t)*p_object;
	uint16_t u = (uint16_t)*p_u;
	uint32_t carry = 0;
	uint16_t command = 0, ignored16 = 0, ignored16_2 = 0, ignored16_3 = 0, layer_and_columns = 0, record_number = 0, u_2 = 0, x_2 = 0;
	uint8_t t1 = 0;

	if (layer_clear_pending != 0u)
		return;
	io_write8(0x1FB9u, 0x3Fu);
	io_write8(0x1FBAu, 0x36u);
	map_scene = 0x8Du;
	map_area = 2u;
	vector_set_layer_modes();
	layer_and_columns = 0x26u;
	vector_draw_layer_strips(layer_and_columns, &ignored16, &ignored16_2, &ignored16_3);
	layer_and_columns = 0x126u;
	vector_draw_layer_strips(layer_and_columns, &x_2, &ignored16_2, &u_2);
	record_number = 0x2326u;
	object = scene_put_placement(x_2, record_number);
	OBJECT(object)->attributes = 0x10u;
	io_write8(0x1FB9u, 0x13u);
	io_write8(0x1FBAu, 0x2Cu);
	command = 0x9600u;
	carry = vector_queue_sound(command);
	io_write16(0x18E2u, 0x30u);
	t1 = io_read8(scene_state);
	io_write8(scene_state, t1 + 1u);
	*p_x = x_2;
	*p_object = object;
	*p_u = u_2;
}

/* The scene after stage 8's last boss: holds the kind-13 object's picture. */
void stage_8_end_hold(void)
{
	uint8_t t2 = 0;
	uint16_t t1 = 0;

	OBJECT(OBJECT_ADDRESS(8))->animation_flags |= 0x40u;
	t1 = io_read16(0x18E2u);
	io_write16(0x18E2u, t1 - 1u);
	if (t1 == 1u)
	{
		io_write16(0x18E2u, 0x60u);
		t2 = io_read8(scene_state);
		io_write8(scene_state, t2 + 1u);
	}
}

/* The scene after stage 8's last boss: moves layer B and clears the objects. */
void stage_8_end_switch_view(uint16_t *p_x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t ignored16 = 0, ignored16_2 = 0, layer_and_columns = 0, u = 0, x = 0, y = 0;
	uint8_t t1 = 0;

	io_write8(0x1FB9u, 0x3Fu);
	io_write8(0x1FBAu, 0x36u);
	layer_b_scroll_x = 0x120u;
	layer_b_last_scroll_x = 0x120u;
	layer_b_offset_x = 0u;
	layer_and_columns = 0x126u;
	vector_draw_layer_strips(layer_and_columns, &ignored16, &y, &ignored16_2);
	vector_clear_objects(&ignored16, &u);
	io_write16(0x18E2u, 0x60u);
	x = clear_child_objects();
	t1 = io_read8(scene_state);
	io_write8(scene_state, t1 + 1u);
	*p_x = x;
	*p_y = y;
	*p_u = u;
}

/* The scene after stage 8's last boss: back to the scene, the kind-13 objects in it. */
void stage_8_end_show_kind_13(uint16_t *p_x, uint16_t *p_object, uint16_t *p_u)
{
	uint16_t x = (uint16_t)*p_x;
	uint16_t object = (uint16_t)*p_object;
	uint16_t u = (uint16_t)*p_u;
	uint16_t ignored16 = 0, ignored16_2 = 0, ignored16_3 = 0, layer_and_columns = 0, record_number = 0, u_2 = 0, x_2 = 0;
	uint8_t t2 = 0;
	uint16_t t1 = 0;

	io_write8(0x1FB9u, 0x13u);
	io_write8(0x1FBAu, 0x2Cu);
	t1 = io_read16(0x18E2u);
	io_write16(0x18E2u, t1 - 1u);
	if (t1 != 1u)
		return;
	io_write8(0x1FB9u, 0x3Fu);
	io_write8(0x1FBAu, 0x36u);
	layer_b_scroll_x = 0xFFF0u;
	layer_b_last_scroll_x = 0xFFF0u;
	layer_b_offset_x = 0u;
	layer_and_columns = 0x126u;
	vector_draw_layer_strips(layer_and_columns, &ignored16, &ignored16_2, &ignored16_3);
	vector_clear_objects(&x_2, &u_2);
	record_number = 0x2426u;
	scene_put_placement(x_2, record_number);
	record_number = 0x2526u;
	scene_put_placement(x_2, record_number);
	record_number = 0x2626u;
	object = scene_put_placement(x_2, record_number);
	io_write16(0x18E2u, 0x100u);
	t2 = io_read8(scene_state);
	io_write8(scene_state, t2 + 1u);
	*p_x = x_2;
	*p_object = object;
	*p_u = u_2;
}

/* The scene after stage 8's last boss: back where the fight ended, Maggie, Mr. Burns and the family: one
   player who played picked at random to get Maggie, the others walking in. */
void stage_8_end_reunion(uint16_t *p_object, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t object = (uint16_t)*p_object;
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = (uint16_t)*p_u;
	uint32_t carry = 0;
	uint8_t a = 0, b = 0, bit = 0, blink_flags = 0, count = 0, present = 0, scroll_x_high = 0, scroll_x_low = 0, scroll_y_high = 0, scroll_y_low = 0, shifts = 0;
	uint16_t command = 0, ignored16 = 0, ignored16_2 = 0, layer_and_columns = 0, request = 0, u_2 = 0, y_2 = 0;
	uint8_t t4 = 0, t5 = 0, t6 = 0, t15 = 0, t16 = 0, t27 = 0, t36 = 0, t49 = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0, t7 = 0, t8 = 0, t9 = 0, t10 = 0, t11 = 0, t12 = 0, t13 = 0, t14 = 0, t17 = 0, t18 = 0, t19 = 0, t20 = 0, t21 = 0, t22 = 0, t23 = 0, t24 = 0, t25 = 0, t26 = 0, t28 = 0, t29 = 0, t30 = 0, t31 = 0, t32 = 0, t33 = 0, t34 = 0, t35 = 0, t37 = 0, t38 = 0, t39 = 0, t40 = 0, t41 = 0, t42 = 0, t43 = 0, t44 = 0, t45 = 0, t46 = 0, t47 = 0, t48 = 0;
	uint32_t kind_halfword = 0, behaviour_halfword = 0, kind_halfword_2 = 0, kind_halfword_3 = 0, kind_halfword_4 = 0, behaviour_halfword_2 = 0;

	io_write8(0x1FB9u, 0x13u);
	io_write8(0x1FBAu, 0x2Cu);
	t1 = io_read16(0x18E2u);
	io_write16(0x18E2u, t1 - 1u);
	if (t1 != 1u)
	{
		blink_flags = 0u;
		if ((frame_count & 0x20u) != 0u)
			blink_flags = 0x80u;
		OBJECT(OBJECT_ADDRESS(9))->flags = blink_flags;
		OBJECT(OBJECT_ADDRESS(9))->animation_flags = blink_flags;
		if ((frame_count & 0x1Fu) != 0u)
			return;
		command = 0x4500u;
		carry = vector_queue_sound(command);
		return;
	}
	clear_child_objects();
	t2 = io_read16(0x18F8u);
	scroll_x_high = (uint8_t)(t2 >> 8);
	scroll_x_low = (uint8_t)t2;
	layer_a_scroll_x = ((uint32_t)scroll_x_high << 8) | scroll_x_low;
	layer_b_scroll_x = ((uint32_t)scroll_x_high << 8) | scroll_x_low;
	t3 = io_read16(0x18FAu);
	scroll_y_high = (uint8_t)(t3 >> 8);
	scroll_y_low = (uint8_t)t3;
	layer_a_scroll_y = ((uint32_t)scroll_y_high << 8) | scroll_y_low;
	layer_b_scroll_y = ((uint32_t)scroll_y_high << 8) | scroll_y_low;
	palette_request_kind = 1u;
	request = 0x880u;
	vector_palette_request(request, &ignored16_2, &u);
	palette_request_kind = 1u;
	request = 0xF8Eu;
	vector_palette_request(request, &ignored16_2, &u);
	io_write8(0x1FB9u, 0x3Fu);
	io_write8(0x1FBAu, 0x36u);
	map_scene = 0x8Du;
	map_area = 1u;
	vector_set_layer_modes();
	layer_and_columns = 0x2Cu;
	vector_draw_layer_strips(layer_and_columns, &ignored16, &ignored16_2, &u_2);
	y_2 = vector_clear_layer_b();
	io_write8(0x1FB9u, 0x13u);
	io_write8(0x1FBAu, 0x2Cu);
	t4 = io_read8(0x18FCu);
	t5 = (((t4 >> 1) >> 1) >> 1) >> 1;
	shifts = t5;
	if (t5 != 0u)
	{
		bit = 1u;
		while (shifts != 0u)
		{
			bit = (uint32_t)bit << 1;
			shifts--;
		}
		io_write8(0x18FCu, bit);
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
			t6 = count;
			count = t6 - 1u;
		} while (t6 != 1u);
		io_write8(0x18FCu, present & reunion_player);
	}
	reunion_player = 0u;
	reunion_player_bits = players_present;
	reunion_standing_x = 0x60u;
	reunion_walker_x = 0xFE80u;
	reunion_walker_wait = 0xFFE0u;
	object = OBJECT_ADDRESS(22);
	do
	{
		if ((reunion_player_bits & 1u) == 0u)
		{
			OBJECT(object)->flags = 0x80u;
			kind_halfword = ((uint32_t)reunion_player << 8) | 0x80u;
			OBJECT(object)->kind = (uint8_t)(kind_halfword >> 8u);
			OBJECT(object)->animation = (uint8_t)kind_halfword;
			t7 = io_read16(0x18F4u);
			t8 = t7 + reunion_walker_x;
			OBJECT(object)->x = t8;
			t9 = io_read16(0x18F6u);
			t10 = t9 - 0x10u;
			OBJECT(object)->y = t10;
			t11 = reunion_walker_x;
			t12 = t11 - 0x20u;
			reunion_walker_x = t12;
			t13 = reunion_walker_wait;
			t14 = t13 + 0x20u;
			a = (uint8_t)(t14 >> 8);
			b = (uint8_t)t14;
			reunion_walker_wait = ((uint32_t)a << 8) | b;
			behaviour_halfword = ((uint32_t)a << 8) | b;
			OBJECT(object)->behaviour = (OBJECT(object)->behaviour & 0xFF00u) | ((behaviour_halfword >> 8u) & 0xFFu);
			OBJECT(object)->target_dx = (OBJECT(object)->target_dx & 0xFFu) | ((behaviour_halfword & 0xFFu) << 8u);
			OBJECT(object)->type = -0xC;
			OBJECT(object)->state = 1u;
		}
		else
		{
			t15 = io_read8(0x18FCu);
			if ((t15 & 1u) != 0u)
			{
				t16 = io_read8(0x18FCu);
				io_write8(0x18FCu, 0u);
				OBJECT(object)->flags = 0x80u;
				kind_halfword_2 = ((uint32_t)reunion_player << 8) | 0x80u;
				OBJECT(object)->kind = (uint8_t)(kind_halfword_2 >> 8u);
				OBJECT(object)->animation = (uint8_t)kind_halfword_2;
				t17 = io_read16(0x18F4u);
				t18 = t17 + 0x70u;
				OBJECT(object)->x = t18;
				t19 = io_read16(0x18F6u);
				t20 = t19 - 0xEu;
				OBJECT(object)->y = t20;
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
				t21 = io_read16(0x18F4u);
				t22 = t21 + reunion_standing_x;
				OBJECT(object)->x = t22;
				t23 = io_read16(0x18F6u);
				t24 = t23 + 0x10u;
				OBJECT(object)->y = t24;
				t25 = reunion_standing_x;
				t26 = t25 - 0x20u;
				reunion_standing_x = t26;
				OBJECT(object)->attributes = 0x40u;
				OBJECT(object)->type = -0xC;
				OBJECT(object)->state = 0u;
			}
		}
		OBJECT(object)->target_dx = (OBJECT(object)->target_dx & 0xFF00u) | (reunion_player & 0xFFu);
		object += 0x60u;
		t27 = io_read8(0x18FCu);
		io_write8(0x18FCu, t27 >> 1);
		reunion_player_bits = reunion_player_bits >> 1;
		reunion_player++;
	} while (reunion_player != 4u);
	if ((players_present & 0xFu) == 0xFu)
	{
		reunion_player = 0x81u;
		reunion_player_bits = 2u;
		reunion_walker_wait = 0u;
		reunion_walker_x = 0xFE80u;
		do
		{
			OBJECT(object)->flags = 0x80u;
			kind_halfword_4 = 0xC900u | reunion_player;
			OBJECT(object)->kind = (uint8_t)(kind_halfword_4 >> 8u);
			OBJECT(object)->animation = (uint8_t)kind_halfword_4;
			reunion_player++;
			reunion_player++;
			t28 = io_read16(0x18F4u);
			t29 = t28 + reunion_walker_x;
			OBJECT(object)->x = t29;
			t30 = io_read16(0x18F6u);
			t31 = t30 + 0x10u;
			OBJECT(object)->y = t31;
			t32 = reunion_walker_x;
			t33 = t32 - 0x20u;
			reunion_walker_x = t33;
			t34 = reunion_walker_wait;
			t35 = t34 + 0x20u;
			a = (uint8_t)(t35 >> 8);
			b = (uint8_t)t35;
			reunion_walker_wait = ((uint32_t)a << 8) | b;
			behaviour_halfword_2 = ((uint32_t)a << 8) | b;
			OBJECT(object)->behaviour = (OBJECT(object)->behaviour & 0xFF00u) | ((behaviour_halfword_2 >> 8u) & 0xFFu);
			OBJECT(object)->target_dx = (OBJECT(object)->target_dx & 0xFFu) | ((behaviour_halfword_2 & 0xFFu) << 8u);
			OBJECT(object)->type = -0xC;
			OBJECT(object)->state = 3u;
			object += 0x60u;
			t36 = reunion_player_bits;
			reunion_player_bits = t36 - 1u;
		} while (t36 != 1u);
		OBJECT(object)->flags = 0x80u;
		OBJECT(object)->kind = 0xCAu;
		OBJECT(object)->animation = 0x81u;
		t37 = io_read16(0x18F4u);
		t38 = t37 - 0x180u;
		OBJECT(object)->x = t38;
		t39 = io_read16(0x18F6u);
		t40 = t39 + 0x10u;
		OBJECT(object)->y = t40;
		t41 = reunion_walker_wait;
		t42 = t41 + 0x20u;
		OBJECT(object)->behaviour = (OBJECT(object)->behaviour & 0xFF00u) | ((t42 >> 8u) & 0xFFu);
		OBJECT(object)->target_dx = (OBJECT(object)->target_dx & 0xFFu) | ((t42 & 0xFFu) << 8u);
		OBJECT(object)->type = -0xC;
		OBJECT(object)->state = 4u;
	}
	OBJECT(OBJECT_ADDRESS(29))->flags = 0x80u;
	OBJECT(OBJECT_ADDRESS(29))->kind = 0x11u;
	OBJECT(OBJECT_ADDRESS(29))->animation = 0x86u;
	OBJECT(OBJECT_ADDRESS(29))->attributes = 0x40u;
	t43 = io_read16(0x18F4u);
	t44 = t43 + 0x60u;
	OBJECT(OBJECT_ADDRESS(29))->x = t44;
	t45 = io_read16(0x18F6u);
	t46 = t45 - 0x10u;
	OBJECT(OBJECT_ADDRESS(29))->y = t46;
	OBJECT(OBJECT_ADDRESS(29))->type = -0xC;
	object = OBJECT_ADDRESS(30);
	OBJECT(OBJECT_ADDRESS(30))->flags = 0x80u;
	OBJECT(OBJECT_ADDRESS(30))->kind = 0xD3u;
	OBJECT(OBJECT_ADDRESS(30))->animation = 0x83u;
	OBJECT(OBJECT_ADDRESS(30))->attributes = 0x40u;
	t47 = io_read16(0x18F4u);
	OBJECT(OBJECT_ADDRESS(30))->x = t47;
	t48 = io_read16(0x18F6u);
	OBJECT(OBJECT_ADDRESS(30))->y = t48;
	OBJECT(OBJECT_ADDRESS(30))->type = -0xC;
	io_write16(0x18E2u, 0x1C0u);
	t49 = io_read8(scene_state);
	io_write8(scene_state, t49 + 1u);
	*p_object = object;
	*p_y = y_2;
	*p_u = u_2;
}

/* The scene after stage 8's last boss: runs each actor by its state; when the time is up, moves to the
   power plant's area 3 with its music (8B00). */
void stage_8_end_run_family(uint16_t *p_object, uint16_t *p_y, uint16_t *p_steps)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t steps = (uint16_t)*p_steps;
	uint32_t carry = 0;
	uint16_t command = 0, ignored16 = 0, ignored16_2 = 0, ignored16_3 = 0, layer_and_columns = 0, object = 0, record_number = 0, request = 0, scroll_x = 0, scroll_y = 0;
	uint8_t stack = 0;
	uint8_t t2 = 0, state = 0, t3 = 0;
	uint16_t t1 = 0;

	t1 = io_read16(0x18E2u);
	io_write16(0x18E2u, t1 - 1u);
	if (t1 == 1u)
	{
		io_write16(0x18E2u, 0xC0u);
		vector_clear_list_1_objects();
		scroll_x = 0xFFF0u;
		vector_set_scroll_x(scroll_x);
		scroll_y = 0u;
		vector_set_scroll_y(scroll_y);
		palette_request_kind = 1u;
		request = 0xE8Fu;
		vector_palette_request(request, &ignored16, &steps);
		map_scene = 0x8Du;
		map_area = 3u;
		vector_set_layer_modes();
		io_write8(0x1FB9u, 0x3Fu);
		io_write8(0x1FBAu, 0x36u);
		layer_and_columns = 0x26u;
		vector_draw_layer_strips(layer_and_columns, &ignored16_2, &ignored16, &ignored16_3);
		layer_and_columns = 0x126u;
		vector_draw_layer_strips(layer_and_columns, &ignored16_2, &ignored16, &ignored16_3);
		vector_clear_objects(&object, &steps);
		record_number = 0x2726u;
		y = scene_put_placement(object, record_number);
		io_write16(0x18E2u, 0x140u);
		palette_request_kind = 2u;
		request = 0x39u;
		vector_palette_request(request, &y, &steps);
		command = 0x8B00u;
		carry = vector_queue_sound(command);
		io_write16(0x18E2u, 0x140u);
		t2 = io_read8(scene_state);
		io_write8(scene_state, t2 + 1u);
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
				stage_8_end_walker(&object, &y, &steps);
				break;
			case 4:
				stage_8_end_maggie_taker(&object, &y, &steps);
				break;
			case 6:
				stage_8_end_extra(&object, &y, &steps);
				break;
			case 8:
				stage_8_end_slow_extra(&object, &y, &steps);
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
				stage_2_end_show_area_3(&object, &y, &steps);
				break;
			case -126:
				y = stage_2_end_put_players(object, y);
				break;
			case -124:
			case -122:
				stage_2_end_players_look_around(&object, &y, &steps);
				break;
			case -120:
				scene_end(&object, &steps);
				break;
			case -118:
				stage_end_put_jumpers(&object, &y);
				break;
			case -116:
				stage_end_run_jumpers(&object, &y, &steps);
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
				scene_clear(&object, &y, &steps);
				break;
			case -104:
				stage_5_end_set_up(&object, &y, &steps);
				break;
			case -102:
				stage_end_jump_away(&object, &y, &steps);
				break;
			case -100:
				stage_5_end_show_players(&object, &y, &steps);
				break;
			case -98:
				stage_5_end_fade(&y, &steps);
				break;
			case -96:
				stage_5_end_finish(&object, &y, &steps);
				break;
			case -94:
				stage_6_end_start();
				break;
			case -92:
				stage_6_end_effect(&y, &steps);
				break;
			case -90:
				stage_6_end_finish(&object, &y, &steps);
				break;
			case -88:
				stage_6_wake_set_up(&object, &y, &steps);
				break;
			case -86:
				stage_6_wake_show_players(&object, &y, &steps);
				break;
			case -84:
				stage_6_wake_start();
				break;
			case -82:
				stage_6_wake_wave(&object, &steps);
				break;
			case -80:
				post_bonus_2_scene_set_up(&object, &y, &steps);
				break;
			case -78:
				post_bonus_2_scene_show(&object, &y, &steps);
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
				stage_7_scene_set_up(&object, &y);
				break;
			case -68:
				stage_7_scene_wait_scroll();
				break;
			case -66:
				stage_7_scene_wait_signal();
				break;
			case -64:
				stage_7_scene_lift(&object, &y, &steps);
				break;
			case -62:
				stage_7_scene_wait_train();
				break;
			case -60:
				stage_7_scene_put_chain(&object, &y, &steps);
				break;
			case -58:
				stage_7_scene_move_chain(&object, &steps);
				break;
			case -56:
				stage_7_scene_chain_done();
				break;
			case -54:
				stage_7_end_set_up(&object, &y, &steps);
				break;
			case -52:
				stage_7_end_show(&object, &y, &steps);
				break;
			case -50:
				y = stage_7_end_board(object);
				break;
			case -48:
				stage_7_end_take_off(&object, &y);
				break;
			case -46:
				stage_7_end_slow_down(&object, &steps);
				break;
			case -44:
				stage_7_end_finish(&object, &steps);
				break;
			case -42:
				stage_8_start_set_up(&object, &y, &steps);
				break;
			case -40:
				stage_8_start_show(&object, &y, &steps);
				break;
			case -38:
				stage_8_start_descend(&object, &y, &steps);
				break;
			case -36:
				stage_8_start_stop(&object, &y, &steps);
				break;
			case -34:
				object = stage_8_start_landing();
				break;
			case -32:
				stage_8_start_run_off(&object, &y, &steps);
				break;
			case -30:
				stage_8_start_wait_end(&object, &y, &steps);
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
				stage_8_end_set_up(&object, &y, &steps);
				break;
			case -14:
				stage_8_end_show(&object, &y, &steps);
				break;
			case -12:
				stage_8_end_hold();
				break;
			case -10:
				stage_8_end_switch_view(&object, &y, &steps);
				break;
			case -8:
				stage_8_end_show_kind_13(&object, &y, &steps);
				break;
			case -6:
				stage_8_end_reunion(&object, &y, &steps);
				break;
			case -4:
				stage_8_end_run_family(&object, &y, &steps);
				break;
			case -2:
				stage_8_end_finish(&object, &steps);
				break;
			}
			object += 0x60u;
			t3 = stack;
			stack = t3 - 1u;
		} while (t3 != 1u);
	}
	*p_object = object;
	*p_y = y;
	*p_steps = steps;
}

/* The scene after stage 8's last boss: an actor that does nothing. */
void stage_8_end_actor_rest(void)
{
}

/* The scene after stage 8's last boss: a player walking in, by its step. */
void stage_8_end_walker(uint16_t *p_object, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t object = (uint16_t)*p_object;
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = 0;
	uint8_t action = 0;

	for (;;)
	{
		u = stage_8_end_walker_actions_ADDRESS;
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
			stage_end_put_jumpers(&object, &y);
			break;
		case -126:
			stage_end_run_jumpers(&object, &y, &u);
			break;
		case -124:
			u = stage_end_jumper_wait(object, u);
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
			scene_clear(&object, &y, &u);
			break;
		case -114:
			stage_5_end_set_up(&object, &y, &u);
			break;
		case -112:
			stage_end_jump_away(&object, &y, &u);
			break;
		case -110:
			stage_5_end_show_players(&object, &y, &u);
			break;
		case -108:
			stage_5_end_fade(&y, &u);
			break;
		case -106:
			stage_5_end_finish(&object, &y, &u);
			break;
		case -104:
			stage_6_end_start();
			break;
		case -102:
			stage_6_end_effect(&y, &u);
			break;
		case -100:
			stage_6_end_finish(&object, &y, &u);
			break;
		case -98:
			stage_6_wake_set_up(&object, &y, &u);
			break;
		case -96:
			stage_6_wake_show_players(&object, &y, &u);
			break;
		case -94:
			stage_6_wake_start();
			break;
		case -92:
			stage_6_wake_wave(&object, &u);
			break;
		case -90:
			post_bonus_2_scene_set_up(&object, &y, &u);
			break;
		case -88:
			post_bonus_2_scene_show(&object, &y, &u);
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
			stage_7_scene_set_up(&object, &y);
			break;
		case -78:
			stage_7_scene_wait_scroll();
			break;
		case -76:
			stage_7_scene_wait_signal();
			break;
		case -74:
			stage_7_scene_lift(&object, &y, &u);
			break;
		case -72:
			stage_7_scene_wait_train();
			break;
		case -70:
			stage_7_scene_put_chain(&object, &y, &u);
			break;
		case -68:
			stage_7_scene_move_chain(&object, &u);
			break;
		case -66:
			stage_7_scene_chain_done();
			break;
		case -64:
			stage_7_end_set_up(&object, &y, &u);
			break;
		case -62:
			stage_7_end_show(&object, &y, &u);
			break;
		case -60:
			y = stage_7_end_board(object);
			break;
		case -58:
			stage_7_end_take_off(&object, &y);
			break;
		case -56:
			stage_7_end_slow_down(&object, &u);
			break;
		case -54:
			stage_7_end_finish(&object, &u);
			break;
		case -52:
			stage_8_start_set_up(&object, &y, &u);
			break;
		case -50:
			stage_8_start_show(&object, &y, &u);
			break;
		case -48:
			stage_8_start_descend(&object, &y, &u);
			break;
		case -46:
			stage_8_start_stop(&object, &y, &u);
			break;
		case -44:
			object = stage_8_start_landing();
			break;
		case -42:
			stage_8_start_run_off(&object, &y, &u);
			break;
		case -40:
			stage_8_start_wait_end(&object, &y, &u);
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
			stage_8_end_set_up(&object, &y, &u);
			break;
		case -24:
			stage_8_end_show(&object, &y, &u);
			break;
		case -22:
			stage_8_end_hold();
			break;
		case -20:
			stage_8_end_switch_view(&object, &y, &u);
			break;
		case -18:
			stage_8_end_show_kind_13(&object, &y, &u);
			break;
		case -16:
			stage_8_end_reunion(&object, &y, &u);
			break;
		case -14:
			stage_8_end_run_family(&object, &y, &u);
			break;
		case -12:
			stage_8_end_finish(&object, &u);
			break;
		case -10:
			stage_8_end_actor_rest();
			break;
		case -8:
			continue;
		case -6:
			stage_8_end_maggie_taker(&object, &y, &u);
			break;
		case -4:
			stage_8_end_extra(&object, &y, &u);
			break;
		case -2:
			stage_8_end_slow_extra(&object, &y, &u);
			break;
		}
		break;
	}
	*p_object = object;
	*p_y = y;
	*p_u = u;
}

/* The scene after stage 8's last boss: an actor's 32-frame wait. */
void stage_8_end_actor_start(uint16_t object)
{
	uint8_t action = 0;

	OBJECT(object)->behaviour = (OBJECT(object)->behaviour & 0xFFu) | 0x2000u;
	action = OBJECT(object)->action;
	OBJECT(object)->action = action + 1u;
}

/* The scene after stage 8's last boss: after the wait, the player runs in. */
void stage_8_end_walker_go(uint16_t object)
{
	uint8_t behaviour = 0, action = 0;

	behaviour = (uint8_t)(OBJECT(object)->behaviour >> 8u);
	OBJECT(object)->behaviour = (OBJECT(object)->behaviour & 0xFFu) | ((behaviour - 1u & 0xFFu) << 8u);
	if (behaviour == 1u)
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
	uint32_t carry = 0;
	uint16_t command = 0, distance = 0;
	uint8_t t5 = 0, action = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0, t4 = 0;

	t1 = OBJECT(object)->x;
	t2 = (((uint32_t)(OBJECT(object)->behaviour & 0xFFu) << 8u) | (OBJECT(object)->target_dx >> 8u));
	t3 = io_read16(0x18F4u);
	t4 = t1 + t2 - t3;
	distance = t4;
	if ((int16_t)t4 < 0 || (int16_t)distance < 0x20)
		return;
	t5 = (uint8_t)OBJECT(object)->target_dx;
	command = t5 + 0x3F08u;
	carry = vector_queue_sound(command);
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
void stage_8_end_extra(uint16_t *p_object, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t object = (uint16_t)*p_object;
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = 0;
	uint8_t action = 0;

	for (;;)
	{
		u = stage_8_end_extra_actions_ADDRESS;
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
			scene_clear(&object, &y, &u);
			break;
		case -122:
			stage_5_end_set_up(&object, &y, &u);
			break;
		case -120:
			stage_end_jump_away(&object, &y, &u);
			break;
		case -118:
			stage_5_end_show_players(&object, &y, &u);
			break;
		case -116:
			stage_5_end_fade(&y, &u);
			break;
		case -114:
			stage_5_end_finish(&object, &y, &u);
			break;
		case -112:
			stage_6_end_start();
			break;
		case -110:
			stage_6_end_effect(&y, &u);
			break;
		case -108:
			stage_6_end_finish(&object, &y, &u);
			break;
		case -106:
			stage_6_wake_set_up(&object, &y, &u);
			break;
		case -104:
			stage_6_wake_show_players(&object, &y, &u);
			break;
		case -102:
			stage_6_wake_start();
			break;
		case -100:
			stage_6_wake_wave(&object, &u);
			break;
		case -98:
			post_bonus_2_scene_set_up(&object, &y, &u);
			break;
		case -96:
			post_bonus_2_scene_show(&object, &y, &u);
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
			stage_7_scene_set_up(&object, &y);
			break;
		case -86:
			stage_7_scene_wait_scroll();
			break;
		case -84:
			stage_7_scene_wait_signal();
			break;
		case -82:
			stage_7_scene_lift(&object, &y, &u);
			break;
		case -80:
			stage_7_scene_wait_train();
			break;
		case -78:
			stage_7_scene_put_chain(&object, &y, &u);
			break;
		case -76:
			stage_7_scene_move_chain(&object, &u);
			break;
		case -74:
			stage_7_scene_chain_done();
			break;
		case -72:
			stage_7_end_set_up(&object, &y, &u);
			break;
		case -70:
			stage_7_end_show(&object, &y, &u);
			break;
		case -68:
			y = stage_7_end_board(object);
			break;
		case -66:
			stage_7_end_take_off(&object, &y);
			break;
		case -64:
			stage_7_end_slow_down(&object, &u);
			break;
		case -62:
			stage_7_end_finish(&object, &u);
			break;
		case -60:
			stage_8_start_set_up(&object, &y, &u);
			break;
		case -58:
			stage_8_start_show(&object, &y, &u);
			break;
		case -56:
			stage_8_start_descend(&object, &y, &u);
			break;
		case -54:
			stage_8_start_stop(&object, &y, &u);
			break;
		case -52:
			object = stage_8_start_landing();
			break;
		case -50:
			stage_8_start_run_off(&object, &y, &u);
			break;
		case -48:
			stage_8_start_wait_end(&object, &y, &u);
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
			stage_8_end_set_up(&object, &y, &u);
			break;
		case -32:
			stage_8_end_show(&object, &y, &u);
			break;
		case -30:
			stage_8_end_hold();
			break;
		case -28:
			stage_8_end_switch_view(&object, &y, &u);
			break;
		case -26:
			stage_8_end_show_kind_13(&object, &y, &u);
			break;
		case -24:
			stage_8_end_reunion(&object, &y, &u);
			break;
		case -22:
			stage_8_end_run_family(&object, &y, &u);
			break;
		case -20:
			stage_8_end_finish(&object, &u);
			break;
		case -18:
			stage_8_end_actor_rest();
			break;
		case -16:
			stage_8_end_walker(&object, &y, &u);
			break;
		case -14:
			stage_8_end_maggie_taker(&object, &y, &u);
			break;
		case -12:
			continue;
		case -10:
			stage_8_end_slow_extra(&object, &y, &u);
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
	*p_y = y;
	*p_u = u;
}

/* The scene after stage 8's last boss: after the wait, the extra walks in. */
void stage_8_end_extra_go(uint16_t object)
{
	uint8_t behaviour = 0, action = 0;

	behaviour = (uint8_t)(OBJECT(object)->behaviour >> 8u);
	OBJECT(object)->behaviour = (OBJECT(object)->behaviour & 0xFFu) | ((behaviour - 1u & 0xFFu) << 8u);
	if (behaviour == 1u)
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
	uint16_t t1 = 0, t2 = 0, t3 = 0, t4 = 0;

	t1 = OBJECT(object)->x;
	t2 = (((uint32_t)(OBJECT(object)->behaviour & 0xFFu) << 8u) | (OBJECT(object)->target_dx >> 8u));
	t3 = io_read16(0x18F4u);
	t4 = t1 + t2 - t3;
	distance = t4;
	if ((int16_t)t4 >= 0 && (int16_t)distance >= 0x20)
	{
		OBJECT(object)->x_speed = 0;
		animation = OBJECT(object)->animation;
		OBJECT(object)->animation = (uint16_t)((((uint16_t)((uint32_t)(uint8_t)(((uint16_t)((uint32_t)animation << 8) >> 8) - 1u) << 8) >> 8) | 0x80u) << 8) >> 8;
		action = OBJECT(object)->action;
		OBJECT(object)->action = action + 1u;
	}
}

/* The scene after stage 8's last boss: the slow extra walking in, by its step. */
void stage_8_end_slow_extra(uint16_t *p_object, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t object = (uint16_t)*p_object;
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = 0;
	uint8_t action = 0;

	for (;;)
	{
		u = stage_8_end_slow_extra_actions_ADDRESS;
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
			stage_end_jump_away(&object, &y, &u);
			break;
		case -126:
			stage_5_end_show_players(&object, &y, &u);
			break;
		case -124:
			stage_5_end_fade(&y, &u);
			break;
		case -122:
			stage_5_end_finish(&object, &y, &u);
			break;
		case -120:
			stage_6_end_start();
			break;
		case -118:
			stage_6_end_effect(&y, &u);
			break;
		case -116:
			stage_6_end_finish(&object, &y, &u);
			break;
		case -114:
			stage_6_wake_set_up(&object, &y, &u);
			break;
		case -112:
			stage_6_wake_show_players(&object, &y, &u);
			break;
		case -110:
			stage_6_wake_start();
			break;
		case -108:
			stage_6_wake_wave(&object, &u);
			break;
		case -106:
			post_bonus_2_scene_set_up(&object, &y, &u);
			break;
		case -104:
			post_bonus_2_scene_show(&object, &y, &u);
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
			stage_7_scene_set_up(&object, &y);
			break;
		case -94:
			stage_7_scene_wait_scroll();
			break;
		case -92:
			stage_7_scene_wait_signal();
			break;
		case -90:
			stage_7_scene_lift(&object, &y, &u);
			break;
		case -88:
			stage_7_scene_wait_train();
			break;
		case -86:
			stage_7_scene_put_chain(&object, &y, &u);
			break;
		case -84:
			stage_7_scene_move_chain(&object, &u);
			break;
		case -82:
			stage_7_scene_chain_done();
			break;
		case -80:
			stage_7_end_set_up(&object, &y, &u);
			break;
		case -78:
			stage_7_end_show(&object, &y, &u);
			break;
		case -76:
			y = stage_7_end_board(object);
			break;
		case -74:
			stage_7_end_take_off(&object, &y);
			break;
		case -72:
			stage_7_end_slow_down(&object, &u);
			break;
		case -70:
			stage_7_end_finish(&object, &u);
			break;
		case -68:
			stage_8_start_set_up(&object, &y, &u);
			break;
		case -66:
			stage_8_start_show(&object, &y, &u);
			break;
		case -64:
			stage_8_start_descend(&object, &y, &u);
			break;
		case -62:
			stage_8_start_stop(&object, &y, &u);
			break;
		case -60:
			object = stage_8_start_landing();
			break;
		case -58:
			stage_8_start_run_off(&object, &y, &u);
			break;
		case -56:
			stage_8_start_wait_end(&object, &y, &u);
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
			stage_8_end_set_up(&object, &y, &u);
			break;
		case -40:
			stage_8_end_show(&object, &y, &u);
			break;
		case -38:
			stage_8_end_hold();
			break;
		case -36:
			stage_8_end_switch_view(&object, &y, &u);
			break;
		case -34:
			stage_8_end_show_kind_13(&object, &y, &u);
			break;
		case -32:
			stage_8_end_reunion(&object, &y, &u);
			break;
		case -30:
			stage_8_end_run_family(&object, &y, &u);
			break;
		case -28:
			stage_8_end_finish(&object, &u);
			break;
		case -26:
			stage_8_end_actor_rest();
			break;
		case -24:
			stage_8_end_walker(&object, &y, &u);
			break;
		case -22:
			stage_8_end_maggie_taker(&object, &y, &u);
			break;
		case -20:
			stage_8_end_extra(&object, &y, &u);
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
	*p_y = y;
	*p_u = u;
}

/* The scene after stage 8's last boss: after the wait, the slow extra walks in. */
void stage_8_end_slow_extra_go(uint16_t object)
{
	uint8_t behaviour = 0, action = 0;

	behaviour = (uint8_t)(OBJECT(object)->behaviour >> 8u);
	OBJECT(object)->behaviour = (OBJECT(object)->behaviour & 0xFFu) | ((behaviour - 1u & 0xFFu) << 8u);
	if (behaviour == 1u)
	{
		OBJECT(object)->x_speed = 0x100;
		action = OBJECT(object)->action;
		OBJECT(object)->action = action + 1u;
	}
}

/* The scene after stage 8's last boss: the player picked to get Maggie, by its step. */
void stage_8_end_maggie_taker(uint16_t *p_object, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t object = (uint16_t)*p_object;
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = 0;
	uint8_t action = 0;

	for (;;)
	{
		u = stage_8_end_maggie_taker_actions_ADDRESS;
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
			stage_6_end_effect(&y, &u);
			break;
		case -124:
			stage_6_end_finish(&object, &y, &u);
			break;
		case -122:
			stage_6_wake_set_up(&object, &y, &u);
			break;
		case -120:
			stage_6_wake_show_players(&object, &y, &u);
			break;
		case -118:
			stage_6_wake_start();
			break;
		case -116:
			stage_6_wake_wave(&object, &u);
			break;
		case -114:
			post_bonus_2_scene_set_up(&object, &y, &u);
			break;
		case -112:
			post_bonus_2_scene_show(&object, &y, &u);
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
			stage_7_scene_set_up(&object, &y);
			break;
		case -102:
			stage_7_scene_wait_scroll();
			break;
		case -100:
			stage_7_scene_wait_signal();
			break;
		case -98:
			stage_7_scene_lift(&object, &y, &u);
			break;
		case -96:
			stage_7_scene_wait_train();
			break;
		case -94:
			stage_7_scene_put_chain(&object, &y, &u);
			break;
		case -92:
			stage_7_scene_move_chain(&object, &u);
			break;
		case -90:
			stage_7_scene_chain_done();
			break;
		case -88:
			stage_7_end_set_up(&object, &y, &u);
			break;
		case -86:
			stage_7_end_show(&object, &y, &u);
			break;
		case -84:
			y = stage_7_end_board(object);
			break;
		case -82:
			stage_7_end_take_off(&object, &y);
			break;
		case -80:
			stage_7_end_slow_down(&object, &u);
			break;
		case -78:
			stage_7_end_finish(&object, &u);
			break;
		case -76:
			stage_8_start_set_up(&object, &y, &u);
			break;
		case -74:
			stage_8_start_show(&object, &y, &u);
			break;
		case -72:
			stage_8_start_descend(&object, &y, &u);
			break;
		case -70:
			stage_8_start_stop(&object, &y, &u);
			break;
		case -68:
			object = stage_8_start_landing();
			break;
		case -66:
			stage_8_start_run_off(&object, &y, &u);
			break;
		case -64:
			stage_8_start_wait_end(&object, &y, &u);
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
			stage_8_end_set_up(&object, &y, &u);
			break;
		case -48:
			stage_8_end_show(&object, &y, &u);
			break;
		case -46:
			stage_8_end_hold();
			break;
		case -44:
			stage_8_end_switch_view(&object, &y, &u);
			break;
		case -42:
			stage_8_end_show_kind_13(&object, &y, &u);
			break;
		case -40:
			stage_8_end_reunion(&object, &y, &u);
			break;
		case -38:
			stage_8_end_run_family(&object, &y, &u);
			break;
		case -36:
			stage_8_end_finish(&object, &u);
			break;
		case -34:
			stage_8_end_actor_rest();
			break;
		case -32:
			stage_8_end_walker(&object, &y, &u);
			break;
		case -30:
			continue;
		case -28:
			stage_8_end_extra(&object, &y, &u);
			break;
		case -26:
			stage_8_end_slow_extra(&object, &y, &u);
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
	*p_y = y;
	*p_u = u;
}

/* The scene after stage 8's last boss: the picked player waits 128 frames. */
void stage_8_end_taker_wait(uint16_t object)
{
	uint8_t action = 0;

	OBJECT(object)->behaviour = (OBJECT(object)->behaviour & 0xFFu) | 0x8000u;
	action = OBJECT(object)->action;
	OBJECT(object)->action = action + 1u;
}

/* The scene after stage 8's last boss: the picked player takes Maggie. */
void stage_8_end_take_maggie(uint16_t object)
{
	uint32_t carry = 0;
	uint16_t command = 0;
	uint8_t behaviour = 0, action = 0;

	behaviour = (uint8_t)(OBJECT(object)->behaviour >> 8u);
	OBJECT(object)->behaviour = (OBJECT(object)->behaviour & 0xFFu) | ((behaviour - 1u & 0xFFu) << 8u);
	if (behaviour == 1u)
	{
		OBJECT(object)->animation = 0xAEu;
		action = OBJECT(object)->action;
		OBJECT(object)->action = action + 1u;
	}
	if ((frame_count & 0x1Fu) == 0u)
	{
		command = 0x4500u;
		carry = vector_queue_sound(command);
	}
}

/* The scene after stage 8's last boss: Maggie is in the player's arms (with two voices when all four
   played). */
void stage_8_end_holding_maggie(uint16_t object)
{
	uint32_t carry = 0;
	uint16_t command = 0;
	uint8_t animation_flags = 0, action = 0;

	animation_flags = OBJECT(object)->animation_flags;
	if ((animation_flags & 1u) == 0u)
		return;
	if (players_present == 0xFu)
	{
		command = 0x3F09u;
		carry = vector_queue_sound(command);
		command = 0x3F0Au;
		carry = vector_queue_sound(command);
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
	uint32_t carry = 0;
	uint16_t command = 0;
	uint16_t t1 = 0;

	io_write8(0x1FB9u, 0x13u);
	io_write8(0x1FBAu, 0x2Cu);
	t1 = io_read16(0x18E2u);
	io_write16(0x18E2u, t1 - 1u);
	if (t1 == 1u)
	{
		vector_clear_objects(&x, &u);
		scene_running = 0u;
	}
	else if ((frame_count & 0x1Fu) == 0u)
	{
		command = 0x4500u;
		carry = vector_queue_sound(command);
	}
	*p_x = x;
	*p_u = u;
}

/* Unused: would blink an object by the frame and play a sound (4500) every 32 frames. */
void unused_stage_8_end_blink(void)
{
	uint32_t carry = 0;
	uint16_t command = 0;

	OBJECT(OBJECT_ADDRESS(9))->flags = ((((uint8_t)frame_count & 0x10u) << 1) << 1) << 1;
	OBJECT(OBJECT_ADDRESS(9))->animation_flags = 0x80u;
	if ((frame_count & 0x1Fu) == 0u)
	{
		command = 0x4500u;
		carry = vector_queue_sound(command);
	}
}
