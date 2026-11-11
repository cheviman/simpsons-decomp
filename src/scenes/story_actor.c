/**
 *    Name:        scenes/story_actor.c
 *    Description: the story actor and its script's operations
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    10-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the game's 053248 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

/* Runs a story actor: starts its script, walks it, and when its wait is over runs its operations */
void story_actor_run(uint16_t *p_object, uint16_t *p_object_2)
{
	uint16_t object = (uint16_t)*p_object;
	uint16_t object_2 = (uint16_t)*p_object_2;
	uint32_t negative = 0, carry = 0;
	uint8_t a = 0, attributes = 0, b = 0, margin = 0, script_number = 0, z = 0;
	uint16_t awaited = 0, command = 0, d = 0, heading = 0, parent = 0, player_fields = 0, script = 0, u = 0;
	uint8_t stack = 0, stack_2 = 0, stack_3 = 0;
	uint8_t flags = 0, script_number_2 = 0, reach_width = 0, reach_margin = 0, reach_depth = 0, old_animation_flags = 0, walk_margin = 0, actor_kind = 0, margin_again = 0, margin_to_halve = 0, actor_walk_speed = 0, turn_flags = 0, old_attributes = 0, sound_flags = 0, halt_flags = 0, awaited_wait = 0, players_awaited = 0, players_signal = 0, press_flags = 0, player_number = 0, press_step = 0, press_frames = 0, press_wait_left = 0, old_press_flags = 0, awaited_height = 0, wait_left = 0, awaited_floor = 0;
	uint16_t parent_2 = 0, walk_target = 0, negative_margin = 0, actor_x = 0, reach_centre = 0, centre_x = 0, reach_left = 0, target_x = 0, centre_x_again = 0, reach_right = 0, target_x_again = 0, actor_y = 0, reach_top = 0, target_y = 0, actor_y_again = 0, reach_bottom = 0, target_y_again = 0, script_at = 0, x_speed_now = 0, old_x_speed = 0, x_acceleration = 0, new_x_speed = 0, old_y_speed = 0, y_acceleration = 0, new_y_speed = 0, old_z_speed = 0, z_acceleration = 0, new_z_speed = 0, push_x = 0, push_y = 0, awaited_actor = 0, awaited_camera_x = 0, controls_offset = 0, pressed_controls = 0, actor_z = 0, awaited_x = 0, awaited_screen_x = 0, actor_x_now = 0, stop_x = 0, floor_wait_word = 0;

	flags = OBJECT(object)->flags;
	a = flags;
	if (flags != 0u)
	{
		if (a == 4u)
		{
			OBJECT(object)->flags = 0x80u;
			OBJECT(object)->zoom_x = 0u;
			OBJECT(object)->zoom_y = 0u;
			OBJECT(object)->x_speed = 0;
			OBJECT(object)->y_speed = 0;
			OBJECT(object)->z_speed = 0;
			script_number_2 = OBJECT(object)->story_actor.script_number;
			parent_2 = OBJECT(object)->parent;
			parent = parent_2;
			stack_2 = object >> 8;
			stack = (uint8_t)object;
			stack_3 = script_number_2;
			a = 0u;
			b = 0u;
			object += 0x28u;
			object_2 = 0x18u;
			while (object_2 != 0u)
			{
				mem_write8(object, a);
				mem_write8(object + 1u, b);
				object += 2u;
				object_2--;
			}
			script_number = stack_3;
			object = ((uint32_t)stack_2 << 8) | stack;
			OBJECT(object)->story_actor.script_number = script_number;
			OBJECT(object)->parent = parent;
			OBJECT(object)->unk_58 = 0u;
			OBJECT(object)->story_actor.wait = 1u;
			OBJECT(object)->story_actor.script = story_scripts[script_number & 0x7Fu];
		}
	}
	else
	{
		if (object != OBJECT_ADDRESS(32))
			return;
		OBJECT(object)->flags = 0x80u;
		OBJECT(object)->zoom_x = 0u;
		OBJECT(object)->zoom_y = 0u;
		OBJECT(object)->x_speed = 0;
		OBJECT(object)->y_speed = 0;
		OBJECT(object)->z_speed = 0;
		script_number_2 = OBJECT(object)->story_actor.script_number;
		parent_2 = OBJECT(object)->parent;
		parent = parent_2;
		stack_2 = object >> 8;
		stack = (uint8_t)object;
		stack_3 = script_number_2;
		a = 0u;
		b = 0u;
		object += 0x28u;
		object_2 = 0x18u;
		while (object_2 != 0u)
		{
			mem_write8(object, a);
			mem_write8(object + 1u, b);
			object += 2u;
			object_2--;
		}
		script_number = stack_3;
		object = ((uint32_t)stack_2 << 8) | stack;
		OBJECT(object)->story_actor.script_number = script_number;
		OBJECT(object)->parent = parent;
		OBJECT(object)->unk_58 = 0u;
		OBJECT(object)->story_actor.wait = 1u;
		OBJECT(object)->story_actor.script = story_scripts[script_number & 0x7Fu];
	}
	if (object != OBJECT_ADDRESS(32))
	{
		walk_target = OBJECT(object)->story_actor.script_target;
		object_2 = walk_target;
		if (walk_target != 0u)
		{
			reach_width = OBJECT(object)->box_width;
			actor_reach = reach_width;
			reach_margin = OBJECT(object)->story_actor.target_margin;
			negative_margin = (int8_t)(0u - reach_margin);
			actor_x = OBJECT(object)->x;
			reach_centre = negative_margin + actor_x;
			actor_reach_centre_x = reach_centre;
			centre_x = actor_reach_centre_x;
			reach_left = centre_x - actor_reach;
			target_x = OBJECT(object_2)->x;
			if ((int16_t)reach_left < (int16_t)target_x)
			{
				centre_x_again = actor_reach_centre_x;
				reach_right = centre_x_again + actor_reach;
				target_x_again = OBJECT(object_2)->x;
				if ((int16_t)target_x_again < (int16_t)reach_right)
				{
					reach_depth = OBJECT(object)->box_depth;
					actor_reach = reach_depth;
					actor_y = OBJECT(object)->y;
					reach_top = actor_y - actor_reach;
					target_y = OBJECT(object_2)->y;
					if ((int16_t)reach_top < (int16_t)target_y)
					{
						actor_y_again = OBJECT(object)->y;
						reach_bottom = actor_y_again + actor_reach;
						target_y_again = OBJECT(object_2)->y;
						if ((int16_t)target_y_again < (int16_t)reach_bottom)
						{
							OBJECT(object)->x_speed = 0;
							OBJECT(object)->y_speed = 0;
							OBJECT(object)->z_speed = 0;
							OBJECT(object)->story_actor.script_target = 0u;
							old_animation_flags = OBJECT(object)->animation_flags;
							OBJECT(object)->animation_flags = old_animation_flags | 0x40u;
							OBJECT(object)->story_actor.script_target = 0u;
							script_at = OBJECT(object)->story_actor.script;
							script = script_at;
							*p_object = object;
							*p_object_2 = object_2;
							story_actor_next_operation(script, p_object, p_object_2);
							return;
						}
					}
				}
			}
			walk_margin = OBJECT(object)->story_actor.target_margin;
			margin = walk_margin;
			actor_kind = OBJECT(object)->kind;
			a = actor_kind;
			if (a <= 3u)
			{
				margin_again = OBJECT(object)->story_actor.target_margin;
				margin_to_halve = OBJECT(object)->story_actor.target_margin;
				stack = (int8_t)margin_to_halve >> 1;
				margin = (uint32_t)a * margin - margin_again - stack;
			}
			d = margin;
			d = vector_direction_to_offset(object, object_2, d);
			a = (uint8_t)(d >> 8);
			actor_walk_speed = OBJECT(object)->story_actor.walk_speed;
			heading = ((uint32_t)a << 8) | actor_walk_speed;
			vector_set_speed_by_direction(object, heading);
			turn_flags = OBJECT(object)->story_actor.script_flags;
			if ((turn_flags & 1u) == 0u)
			{
				old_attributes = OBJECT(object)->attributes;
				attributes = old_attributes & 0xBFu;
				x_speed_now = OBJECT(object)->x_speed;
				object_2 = x_speed_now;
				if ((int16_t)x_speed_now < 0)
					attributes |= 0x40u;
				OBJECT(object)->attributes = attributes;
			}
		}
		old_x_speed = OBJECT(object)->x_speed;
		x_acceleration = OBJECT(object)->story_actor.acceleration_x;
		new_x_speed = old_x_speed + x_acceleration;
		OBJECT(object)->x_speed = new_x_speed;
		old_y_speed = OBJECT(object)->y_speed;
		y_acceleration = OBJECT(object)->story_actor.acceleration_y;
		new_y_speed = old_y_speed + y_acceleration;
		OBJECT(object)->y_speed = new_y_speed;
		old_z_speed = OBJECT(object)->z_speed;
		z_acceleration = OBJECT(object)->story_actor.acceleration_z;
		new_z_speed = old_z_speed + z_acceleration;
		OBJECT(object)->z_speed = new_z_speed;
	}
	else
	{
		OBJECT(object)->y = camera_y;
		push_x = OBJECT(object)->story_actor.acceleration_x;
		players_push_x = push_x;
		push_y = OBJECT(object)->story_actor.acceleration_y;
		players_push_y = push_y;
	}
	sound_flags = OBJECT(object)->story_actor.script_flags;
	if ((sound_flags & 2u) != 0u && (frame_count & 0xFu) == 0u)
	{
		command = 0x4A00u;
		carry = vector_queue_sound(command);
	}
	halt_flags = OBJECT(object)->story_actor.script_flags;
	if ((halt_flags & 4u) != 0u)
	{
		object_2 = story_actor_finish_frame(object, object_2);
		*p_object = object;
		*p_object_2 = object_2;
		return;
	}
	awaited_actor = OBJECT(object)->behaviour;
	awaited = awaited_actor;
	if (awaited_actor != 0u)
	{
		awaited_wait = (uint8_t)OBJECT(awaited)->target_dx;
		if (awaited_wait != 1u)
		{
			object_2 = story_actor_finish_frame(object, object_2);
			*p_object = object;
			*p_object_2 = object_2;
			return;
		}
		OBJECT(object)->behaviour = 0u;
		OBJECT(object)->story_actor.script_target = 0u;
		script_at = OBJECT(object)->story_actor.script;
		script = script_at;
		*p_object = object;
		*p_object_2 = object_2;
		story_actor_next_operation(script, p_object, p_object_2);
		return;
	}
	players_awaited = OBJECT(object)->action_step;
	if (players_awaited != 0u)
	{
		players_signal = io_read8(0x184Eu);
		if (players_signal == 0u)
		{
			object_2 = story_actor_finish_frame(object, object_2);
			*p_object = object;
			*p_object_2 = object_2;
			return;
		}
		OBJECT(object)->action_step = 0u;
		stack_2 = object >> 8;
		stack = (uint8_t)object;
		player_fields = 0x4A68u;
		story_clear_player(player_fields);
		player_fields = 0x4B28u;
		story_clear_player(player_fields);
		player_fields = 0x4BE8u;
		story_clear_player(player_fields);
		player_fields = 0x4CA8u;
		u = story_clear_player(player_fields);
		object = ((uint32_t)stack_2 << 8) | stack;
		OBJECT(object)->story_actor.script_target = 0u;
		script_at = OBJECT(object)->story_actor.script;
		script = script_at;
		*p_object = object;
		*p_object_2 = u;
		story_actor_next_operation(script, p_object, p_object_2);
		return;
	}
	awaited_camera_x = OBJECT(object)->story_actor.camera_wait;
	a = (uint8_t)(awaited_camera_x >> 8);
	b = (uint8_t)awaited_camera_x;
	if (awaited_camera_x != 0u)
	{
		if ((int16_t)camera_x <= (int16_t)(((uint32_t)a << 8) | b))
		{
			object_2 = story_actor_finish_frame(object, object_2);
			*p_object = object;
			*p_object_2 = object_2;
			return;
		}
		OBJECT(object)->story_actor.camera_wait = 0u;
		OBJECT(object)->story_actor.script_target = 0u;
		script_at = OBJECT(object)->story_actor.script;
		script = script_at;
		*p_object = object;
		*p_object_2 = object_2;
		story_actor_next_operation(script, p_object, p_object_2);
		return;
	}
	press_flags = OBJECT(object)->story_actor.script_flags;
	if ((press_flags & 0x10u) != 0u)
	{
		player_number = OBJECT(object)->kind;
		controls_offset = 4u * player_number;
		pressed_controls = controls_offset + (player_controls_ADDRESS + 0x2u);
		stack = pressed_controls;
		stack_2 = pressed_controls >> 8;
		u = ((uint32_t)stack_2 << 8) | stack;
		if (mem_read8(u) != 0u)
		{
			press_step = OBJECT(object)->attack;
			a = press_step;
			if (press_step != 0u)
			{
				a--;
				OBJECT(object)->attack = a;
				press_frames = OBJECT(object)->damage;
				a += press_frames;
				if (a <= 0xE0u)
					OBJECT(object)->damage = a;
			}
		}
		press_wait_left = OBJECT(object)->damage;
		OBJECT(object)->damage = press_wait_left - 1u;
		if (press_wait_left != 1u)
		{
			u = story_actor_finish_frame(object, u);
			*p_object = object;
			*p_object_2 = u;
			return;
		}
		old_press_flags = OBJECT(object)->story_actor.script_flags;
		OBJECT(object)->story_actor.script_flags = old_press_flags & 0xEFu;
		OBJECT(object)->story_actor.script_target = 0u;
		script_at = OBJECT(object)->story_actor.script;
		script = script_at;
		*p_object = object;
		*p_object_2 = u;
		story_actor_next_operation(script, p_object, p_object_2);
		return;
	}
	awaited_height = OBJECT(object)->story_actor.landing_height;
	z = awaited_height;
	if (awaited_height != 0u)
	{
		a = 0u;
		actor_z = OBJECT(object)->z;
		if ((int16_t)z < (int16_t)actor_z)
		{
			object_2 = story_actor_finish_frame(object, object_2);
			*p_object = object;
			*p_object_2 = object_2;
			return;
		}
		OBJECT(object)->z = ((uint32_t)a << 8) | (uint8_t)(z - 1u);
		OBJECT(object)->z_fraction = 0u;
		OBJECT(object)->story_actor.landing_height = 0u;
		OBJECT(object)->story_actor.script_target = 0u;
		script_at = OBJECT(object)->story_actor.script;
		script = script_at;
		*p_object = object;
		*p_object_2 = object_2;
		story_actor_next_operation(script, p_object, p_object_2);
		return;
	}
	awaited_x = OBJECT(object)->story_actor.x_wait;
	a = (uint8_t)(awaited_x >> 8);
	b = (uint8_t)awaited_x;
	if (awaited_x != 0u)
	{
		awaited_screen_x = (((uint32_t)a << 8) | b) - camera_x;
		a = (uint8_t)(awaited_screen_x >> 8);
		b = (uint8_t)awaited_screen_x;
		actor_x_now = OBJECT(object)->x;
		if ((int16_t)actor_x_now < (int16_t)(((uint32_t)a << 8) | b))
		{
			object_2 = story_actor_finish_frame(object, object_2);
			*p_object = object;
			*p_object_2 = object_2;
			return;
		}
		stop_x = (((uint32_t)a << 8) | b) - 1u;
		OBJECT(object)->x = stop_x;
		OBJECT(object)->x_fraction = 0u;
		OBJECT(object)->story_actor.x_wait = 0u;
		OBJECT(object)->story_actor.script_target = 0u;
		script_at = OBJECT(object)->story_actor.script;
		script = script_at;
		*p_object = object;
		*p_object_2 = object_2;
		story_actor_next_operation(script, p_object, p_object_2);
		return;
	}
	floor_wait_word = (((uint32_t)OBJECT(object)->zoom_x << 8u) | OBJECT(object)->zoom_y);
	if (floor_wait_word == 0u)
	{
		wait_left = OBJECT(object)->story_actor.wait;
		OBJECT(object)->story_actor.wait = wait_left - 1u;
		if (wait_left != 1u)
		{
			object_2 = story_actor_finish_frame(object, object_2);
			*p_object = object;
			*p_object_2 = object_2;
			return;
		}
		OBJECT(object)->story_actor.script_target = 0u;
		script_at = OBJECT(object)->story_actor.script;
		script = script_at;
		*p_object = object;
		*p_object_2 = object_2;
		story_actor_next_operation(script, p_object, p_object_2);
		return;
	}
	vector_floor_ahead(object, &d, &negative);
	a = (uint8_t)(d >> 8);
	awaited_floor = OBJECT(object)->zoom_y;
	if ((a & 0xFu) != awaited_floor)
	{
		object_2 = story_actor_finish_frame(object, object_2);
		*p_object = object;
		*p_object_2 = object_2;
		return;
	}
	OBJECT(object)->zoom_x = 0u;
	OBJECT(object)->zoom_y = 0u;
	OBJECT(object)->story_actor.script_target = 0u;
	script_at = OBJECT(object)->story_actor.script;
	script = script_at;
	*p_object = object;
	*p_object_2 = object_2;
	story_actor_next_operation(script, p_object, p_object_2);
}

/* Clears a player's fields from 28 on, as a story hands the players back */
uint16_t story_clear_player(uint16_t fields)
{
	uint16_t count = 0, fill = 0;

	fill = 0u;
	count = 0x2Fu;
	while (count != 0u)
	{
		mem_write8(fields, fill >> 8);
		fields++;
		count--;
	}
	return count;
}

/* Runs its script's next operation; FF ends it */
void story_actor_next_operation(uint16_t script, uint16_t *p_object, uint16_t *p_operations)
{
	uint16_t object = (uint16_t)*p_object;
	uint16_t operations = (uint16_t)*p_operations;
	uint8_t operation = 0;
	uint16_t operation_at = 0;

	operation_at = script;
	script = operation_at + 1u;
	operation = mem_read8(operation_at);
	if (operation == 0xFFu)
		operations = story_actor_remove(object, operations);
	else
	{
		operations = story_actor_operations_ADDRESS;
		switch ((int8_t)(uint8_t)((uint32_t)operation << 1))
		{
		case 0:
			story_actor_set_kind(script, &object, &operations);
			break;
		case 2:
			story_actor_set_animation(script, &object, &operations);
			break;
		case 4:
			story_actor_set_place(script, &object, &operations);
			break;
		case 6:
			story_actor_set_speeds(script, &object, &operations);
			break;
		case 8:
			story_actor_set_accelerations(script, &object, &operations);
			break;
		case 10:
			story_actor_walk_to(script, &object, &operations);
			break;
		case 12:
			leftover_y = script;
			story_actor_put_in(&object, &operations);
			break;
		case 14:
			operations = story_actor_wait(object, script, operations);
			break;
		case 16:
			story_actor_set_accelerations_xy(script, &object, &operations);
			break;
		case 18:
			story_actor_line_up_players(script, &object, &operations);
			break;
		case 20:
			story_actor_set_hit_box(script, &object, &operations);
			break;
		case 22:
			story_actor_play_sound(script, &object, &operations);
			break;
		case 24:
			operations = story_actor_halt(object, script, operations);
			break;
		case 26:
			story_actor_set_attributes(script, &object, &operations);
			break;
		case 28:
			story_actor_toggle_airborne(script, &object, &operations);
			break;
		case 30:
			story_actor_walk_to_partner(script, &object, &operations);
			break;
		case 32:
			operations = story_actor_wait_for_object(object, script);
			break;
		case 34:
			story_actor_wait_for_players(script, &object, &operations);
			break;
		case 36:
			story_actor_random_player_faces(script, &object, &operations);
			break;
		case 38:
			story_actor_set_players_animation(script, &object, &operations);
			break;
		case 40:
			story_actor_face_object(script, &object, &operations);
			break;
		case 42:
			operations = story_actor_wait_for_height(object, script, operations);
			break;
		case 44:
			leftover_y = script;
			story_actor_put_in_child(&object, &operations);
			break;
		case 46:
			operations = story_actor_wait_for_camera(object, script, operations);
			break;
		case 48:
			story_actor_set_variable(script, &object, &operations);
			break;
		case 50:
			story_actor_drop_players_held(script, &object, &operations);
			break;
		case 52:
			story_actor_walk_to_without_turning(script, &object, &operations);
			break;
		case 54:
			operations = story_actor_wait_for_x(object, script, operations);
			break;
		case 56:
			story_actor_place_players(script, &object, &operations);
			break;
		case 58:
			story_actor_start_absent_players(script, &object, &operations);
			break;
		case 60:
			story_actor_play_kind_sound(script, &object, &operations);
			break;
		case 62:
			operations = story_actor_wait_for_floor(object, script, operations);
			break;
		case 64:
			story_actor_play_sound_if_player(script, &object, &operations);
			break;
		case 66:
			story_actor_player_speaks(script, &object, &operations);
			break;
		case 68:
			story_actor_toggle_repeat_sound(script, &object, &operations);
			break;
		case 70:
			story_actor_toggle_flag_08(script, &object, &operations);
			break;
		case 72:
			operations = story_actor_wait_or_presses(object, script, operations);
			break;
		case 74:
			story_actor_stop(script, &object, &operations);
			break;
		}
	}
	*p_object = object;
	*p_operations = operations;
}

/* Operation 00: its kind and animation */
void story_actor_set_kind(uint16_t script, uint16_t *p_object, uint16_t *p_operations)
{
	uint16_t object = (uint16_t)*p_object;
	uint16_t operations = (uint16_t)*p_operations;
	uint16_t kind_at = 0;
	uint32_t kind_halfword = 0;

	kind_at = script;
	script = kind_at + 2u;
	kind_halfword = mem_read16(kind_at);
	OBJECT(object)->kind = (uint8_t)(kind_halfword >> 8u);
	OBJECT(object)->animation = (uint8_t)kind_halfword;
	*p_object = object;
	*p_operations = operations;
	story_actor_continue(script, p_object, p_operations);
}

/* Operation 01: its animation */
void story_actor_set_animation(uint16_t script, uint16_t *p_object, uint16_t *p_operations)
{
	uint16_t object = (uint16_t)*p_object;
	uint16_t operations = (uint16_t)*p_operations;
	uint16_t animation_at = 0;

	animation_at = script;
	script = animation_at + 1u;
	OBJECT(object)->animation = mem_read8(animation_at);
	*p_object = object;
	*p_operations = operations;
	story_actor_continue(script, p_object, p_operations);
}

/* Operation 02: its place */
void story_actor_set_place(uint16_t script, uint16_t *p_object, uint16_t *p_operations)
{
	uint16_t object = (uint16_t)*p_object;
	uint16_t operations = (uint16_t)*p_operations;
	uint16_t x_at = 0, y_at = 0, z_at = 0;

	x_at = script;
	OBJECT(object)->x = mem_read16(x_at);
	y_at = x_at + 2u;
	OBJECT(object)->y = mem_read16(y_at);
	z_at = y_at + 2u;
	script = z_at + 2u;
	OBJECT(object)->z = mem_read16(z_at);
	*p_object = object;
	*p_operations = operations;
	story_actor_continue(script, p_object, p_operations);
}

/* Operation 03: its speeds */
void story_actor_set_speeds(uint16_t script, uint16_t *p_object, uint16_t *p_operations)
{
	uint16_t object = (uint16_t)*p_object;
	uint16_t operations = (uint16_t)*p_operations;
	uint16_t x_speed_at = 0, y_speed_at = 0, z_speed_at = 0;

	x_speed_at = script;
	OBJECT(object)->x_speed = mem_read16(x_speed_at);
	y_speed_at = x_speed_at + 2u;
	OBJECT(object)->y_speed = mem_read16(y_speed_at);
	z_speed_at = y_speed_at + 2u;
	script = z_speed_at + 2u;
	OBJECT(object)->z_speed = mem_read16(z_speed_at);
	*p_object = object;
	*p_operations = operations;
	story_actor_continue(script, p_object, p_operations);
}

/* Operation 04: what it adds to its speeds each frame */
void story_actor_set_accelerations(uint16_t script, uint16_t *p_object, uint16_t *p_operations)
{
	uint16_t object = (uint16_t)*p_object;
	uint16_t operations = (uint16_t)*p_operations;
	uint16_t acceleration_x_at = 0, acceleration_y_at = 0, acceleration_z_at = 0;

	acceleration_x_at = script;
	OBJECT(object)->story_actor.acceleration_x = mem_read16(acceleration_x_at);
	acceleration_y_at = acceleration_x_at + 2u;
	OBJECT(object)->story_actor.acceleration_y = mem_read16(acceleration_y_at);
	acceleration_z_at = acceleration_y_at + 2u;
	script = acceleration_z_at + 2u;
	OBJECT(object)->story_actor.acceleration_z = mem_read16(acceleration_z_at);
	*p_object = object;
	*p_operations = operations;
	story_actor_continue(script, p_object, p_operations);
}

/* Operation 1A: walks to an object without turning to face its way */
void story_actor_walk_to_without_turning(uint16_t script, uint16_t *p_object, uint16_t *p_u)
{
	uint16_t object = (uint16_t)*p_object;
	uint16_t u = 0;
	uint8_t script_flags = 0;

	script_flags = OBJECT(object)->story_actor.script_flags;
	OBJECT(object)->story_actor.script_flags = script_flags | 1u;
	*p_object = object;
	*p_u = u;
	story_actor_walk_to_object_in(script, p_object, p_u);
}

/* Operation 0F: walks to its partner object (60 after it) */
void story_actor_walk_to_partner(uint16_t script, uint16_t *p_object, uint16_t *p_operations)
{
	uint16_t object = (uint16_t)*p_object;
	uint16_t operations = (uint16_t)*p_operations;
	uint16_t target = 0;
	uint16_t stack = 0;

	stack = object;
	target = stack + 0x60u;
	*p_object = object;
	*p_operations = operations;
	story_actor_set_target(script, target, p_object, p_operations);
}

/* Operation 05: walks to an object, facing its way */
void story_actor_walk_to(uint16_t script, uint16_t *p_object, uint16_t *p_u)
{
	uint16_t object = (uint16_t)*p_object;
	uint16_t u = 0;
	uint8_t script_flags = 0;

	script_flags = OBJECT(object)->story_actor.script_flags;
	OBJECT(object)->story_actor.script_flags = script_flags & ~1u;
	*p_object = object;
	*p_u = u;
	story_actor_walk_to_object_in(script, p_object, p_u);
}

/* Takes as its target the object a variable named in the script holds */
void story_actor_walk_to_object_in(uint16_t script, uint16_t *p_object, uint16_t *p_target_address)
{
	uint16_t object = (uint16_t)*p_object;
	uint16_t target = 0, target_address = 0;
	uint16_t variable_at = 0;

	variable_at = script;
	script = variable_at + 2u;
	target_address = mem_read16(variable_at);
	target = mem_read16(target_address);
	*p_object = object;
	*p_target_address = target_address;
	story_actor_set_target(script, target, p_object, p_target_address);
}

/* Its target, how far before it to stop, and its speed */
void story_actor_set_target(uint16_t script, uint16_t target, uint16_t *p_object, uint16_t *p_operations)
{
	uint16_t object = (uint16_t)*p_object;
	uint16_t operations = (uint16_t)*p_operations;
	uint16_t margin_and_speed = 0;
	uint16_t margin_at = 0;

	OBJECT(object)->story_actor.script_target = target;
	margin_at = script;
	script = margin_at + 2u;
	margin_and_speed = mem_read16(margin_at);
	OBJECT(object)->story_actor.target_margin = (uint8_t)(margin_and_speed >> 8u);
	OBJECT(object)->story_actor.walk_speed = (uint8_t)margin_and_speed;
	*p_object = object;
	*p_operations = operations;
	story_actor_continue(script, p_object, p_operations);
}

/* Operation 06: puts in the players, their partners, or a child actor it keeps */
void story_actor_put_in(uint16_t *p_actor, uint16_t *p_object)
{
	uint16_t actor = (uint16_t)*p_actor;
	uint16_t object = (uint16_t)*p_object;
	uint32_t zero = 0, carry = 0;
	uint8_t put_kind = 0;
	uint16_t ignored16 = 0, ignored16_2 = 0, player = 0, script = 0;
	uint16_t stack = 0;
	uint8_t child_list = 0, slots_left = 0, partners_left = 0, present_bits = 0, players_state = 0, kind_base = 0;
	uint16_t offset_dx = 0, actor_x = 0, child_x = 0, dy_at = 0, offset_dy = 0, actor_y = 0, child_y = 0, dz_at = 0, z = 0, child_z = 0, state_at = 0;

	child_list = mem_read8(leftover_y + 5u);
	put_kind = child_list;
	if (put_kind != 4u)
	{
		if (put_kind != 5u)
		{
			stack = leftover_y;
			vector_spawn_child(actor, &ignored16, &object, &ignored16_2, &carry);
			script = stack + 8u;
			if (carry == 0u)
			{
				*p_actor = actor;
				*p_object = object;
				story_actor_continue(script, p_actor, p_object);
				return;
			}
			if (mem_read8(script - 3u) == 2u)
			{
				*p_actor = actor;
				*p_object = object;
				story_actor_continue(script, p_actor, p_object);
				return;
			}
			story_players_left = 0xBu;
			stack = actor;
			actor += 0x43u;
			do
			{
				if (mem_read16(actor) == 0u)
				{
					mem_write16(actor, object);
					break;
				}
				actor += 2u;
				slots_left = story_players_left;
				story_players_left = slots_left - 1u;
			} while (slots_left != 1u);
			actor = stack;
		}
		else
		{
			story_players_left = 4u;
			object = OBJECT_ADDRESS(1);
			do
			{
				if (OBJECT(object)->flags == 0u)
				{
					OBJECT(object)->flags = 4u;
					offset_dx = mem_read16(leftover_y);
					actor_x = OBJECT(actor)->x;
					child_x = offset_dx + actor_x;
					OBJECT(object)->x = child_x;
					dy_at = leftover_y + 2u;
					offset_dy = mem_read16(dy_at);
					actor_y = OBJECT(actor)->y;
					child_y = offset_dy + actor_y;
					OBJECT(object)->y = child_y;
					dz_at = dy_at + 2u;
					z = OBJECT(actor)->z;
					child_z = mem_read8(dz_at) + z;
					OBJECT(object)->z = child_z;
					state_at = dz_at + 2u;
					script = state_at + 2u;
					OBJECT(object)->parameter = mem_read8(state_at);
					*p_actor = actor;
					*p_object = object;
					story_actor_continue(script, p_actor, p_object);
					return;
				}
				object += 0xC0u;
				partners_left = story_players_left;
				story_players_left = partners_left - 1u;
			} while (partners_left != 1u);
			script = leftover_y + 8u;
		}
	}
	else
	{
		story_player_bits = players_present;
		stack = actor;
		player = story_first_player();
		do
		{
			OBJECT(player + 0x60u)->flags = 0u;
			present_bits = story_player_bits;
			story_player_bits = present_bits >> 1;
			if (present_bits & 1u)
				OBJECT(player)->flags = 4u;
			players_state = mem_read8(leftover_y + 6u);
			OBJECT(player)->parameter = players_state;
			kind_base = mem_read8(leftover_y + 7u);
			OBJECT(player)->kind = 4u - story_players_left + kind_base;
			story_next_player(&player, &zero);
		} while (zero == 0u);
		actor = stack;
		script = leftover_y + 8u;
	}
	*p_actor = actor;
	*p_object = object;
	story_actor_continue(script, p_actor, p_object);
}

/* Operation 07: waits that many frames */
uint16_t story_actor_wait(uint16_t object, uint16_t script, uint16_t operations)
{
	uint16_t wait_at = 0;

	wait_at = script;
	OBJECT(object)->story_actor.wait = mem_read8(wait_at);
	OBJECT(object)->story_actor.script = wait_at + 1u;
	return story_actor_finish_frame(object, operations);
}

/* Operation 08: what it adds to its x and y speeds */
void story_actor_set_accelerations_xy(uint16_t script, uint16_t *p_object, uint16_t *p_operations)
{
	uint16_t object = (uint16_t)*p_object;
	uint16_t operations = (uint16_t)*p_operations;
	uint16_t acceleration_x_at = 0, acceleration_y_at = 0;

	acceleration_x_at = script;
	OBJECT(object)->story_actor.acceleration_x = mem_read16(acceleration_x_at);
	acceleration_y_at = acceleration_x_at + 2u;
	script = acceleration_y_at + 2u;
	OBJECT(object)->story_actor.acceleration_y = mem_read16(acceleration_y_at);
	*p_object = object;
	*p_operations = operations;
	story_actor_continue(script, p_object, p_operations);
}

/* Operation 09: lines the four players up in a random order */
void story_actor_line_up_players(uint16_t script, uint16_t *p_object, uint16_t *p_line_offsets)
{
	uint16_t object = (uint16_t)*p_object;
	uint32_t zero = 0;
	uint8_t offset_high = 0, offset_low = 0;
	uint16_t line_offsets = 0, player = 0;
	uint16_t stack = 0;
	uint8_t x_step = 0, z_step = 0;
	uint16_t back_product = 0, back_offset = 0, forward_offset = 0, player_x = 0, line_y = 0, order_at = 0, z_offset = 0, line_z = 0, player_z = 0;

	line_offsets = player_line_up_orders_ADDRESS + (random_number & 0xCu);
	stack = object;
	player = story_first_player();
	do
	{
		offset_low = 4u - story_players_left;
		x_step = mem_read8(script + 6u);
		offset_high = x_step;
		if ((int8_t)x_step < 0)
		{
			back_product = (uint32_t)(uint8_t)(0u - offset_high) * offset_low;
			back_offset = 0u - back_product;
			offset_high = (uint8_t)(back_offset >> 8);
			offset_low = (uint8_t)back_offset;
		}
		else
		{
			forward_offset = (uint32_t)offset_high * offset_low;
			offset_high = (uint8_t)(forward_offset >> 8);
			offset_low = (uint8_t)forward_offset;
		}
		player_x = (((uint32_t)offset_high << 8) | offset_low) + mem_read16(script);
		OBJECT(player)->x = player_x;
		line_y = mem_read16(script + 2u);
		OBJECT(player)->y = line_y;
		order_at = line_offsets;
		line_offsets = order_at + 1u;
		z_step = mem_read8(script + 7u);
		z_offset = (uint32_t)z_step * mem_read8(order_at);
		line_z = mem_read16(script + 4u);
		player_z = z_offset + line_z;
		OBJECT(player)->z = player_z;
		story_next_player(&player, &zero);
	} while (zero == 0u);
	object = stack;
	script += 8u;
	*p_object = object;
	*p_line_offsets = line_offsets;
	story_actor_continue(script, p_object, p_line_offsets);
}

/* Operation 0A: a hit box */
void story_actor_set_hit_box(uint16_t script, uint16_t *p_object, uint16_t *p_operations)
{
	uint16_t object = (uint16_t)*p_object;
	uint16_t operations = (uint16_t)*p_operations;
	uint16_t box_at = 0, width_and_depth = 0, height_at = 0;

	OBJECT(object)->flags |= 0x40u;
	box_at = script;
	width_and_depth = mem_read16(box_at);
	OBJECT(object)->box_width = (uint8_t)(width_and_depth >> 8u);
	OBJECT(object)->box_depth = (uint8_t)width_and_depth;
	height_at = box_at + 2u;
	script = height_at + 1u;
	OBJECT(object)->box_height = mem_read8(height_at);
	*p_object = object;
	*p_operations = operations;
	story_actor_continue(script, p_object, p_operations);
}

/* Operation 20: a sound, if that player's object is in use */
void story_actor_play_sound_if_player(uint16_t script, uint16_t *p_object, uint16_t *p_sound)
{
	uint16_t object = (uint16_t)*p_object;
	uint32_t carry = 0;
	uint16_t command = 0, sound = 0;
	uint8_t stack_10003 = 0, stack_10004 = 0;
	uint16_t stack = 0;
	uint8_t player_flags = 0;
	uint16_t sound_at = 0, player_at = 0, player_offset = 0, player_object = 0;

	sound_at = script;
	sound = mem_read16(sound_at);
	player_at = sound_at + 2u;
	script = player_at + 1u;
	player_offset = 0xC0u * mem_read8(player_at);
	player_object = player_offset + OBJECT_ADDRESS(0);
	stack = object;
	stack_10003 = player_object >> 8;
	stack_10004 = player_object;
	player_flags = mem_read8(((uint32_t)stack_10003 << 8) | stack_10004);
	object = stack;
	if (player_flags == 0u)
		story_actor_continue(script, &object, &sound);
	else
	{
		stack = sound;
		command = stack;
		carry = vector_queue_sound(command);
		story_actor_continue(script, &object, &sound);
	}
	*p_object = object;
	*p_sound = sound;
}

/* Operation 1E: a sound command plus its kind (a character's voice) */
void story_actor_play_kind_sound(uint16_t script, uint16_t *p_object, uint16_t *p_operations)
{
	uint16_t object = (uint16_t)*p_object;
	uint16_t operations = (uint16_t)*p_operations;
	uint32_t carry = 0;
	uint16_t command = 0;
	uint8_t kind = 0;
	uint16_t command_at = 0, kind_command = 0;

	kind = OBJECT(object)->kind;
	command_at = script;
	script = command_at + 2u;
	kind_command = kind + mem_read16(command_at);
	command = kind_command;
	carry = vector_queue_sound(command);
	*p_object = object;
	*p_operations = operations;
	story_actor_continue(script, p_object, p_operations);
}

/* Operation 0B: a sound command */
void story_actor_play_sound(uint16_t script, uint16_t *p_object, uint16_t *p_operations)
{
	uint16_t object = (uint16_t)*p_object;
	uint16_t operations = (uint16_t)*p_operations;
	uint32_t carry = 0;
	uint16_t command = 0;
	uint16_t command_at = 0;

	command_at = script;
	script = command_at + 2u;
	command = mem_read16(command_at);
	carry = vector_queue_sound(command);
	*p_object = object;
	*p_operations = operations;
	story_actor_continue(script, p_object, p_operations);
}

/* Operation 0C: stops its script for good */
uint16_t story_actor_halt(uint16_t object, uint16_t script, uint16_t operations)
{
	uint8_t script_flags = 0;

	script_flags = OBJECT(object)->story_actor.script_flags;
	OBJECT(object)->story_actor.script_flags = script_flags | 4u;
	OBJECT(object)->story_actor.script = script;
	return story_actor_finish_frame(object, operations);
}

/* Operation 0D: its sprite attributes, its animation restarted */
void story_actor_set_attributes(uint16_t script, uint16_t *p_object, uint16_t *p_operations)
{
	uint16_t object = (uint16_t)*p_object;
	uint16_t operations = (uint16_t)*p_operations;
	uint8_t animation_flags = 0;
	uint16_t attributes_at = 0;

	attributes_at = script;
	script = attributes_at + 1u;
	OBJECT(object)->attributes = mem_read8(attributes_at);
	animation_flags = OBJECT(object)->animation_flags;
	OBJECT(object)->animation_flags = animation_flags | 0x80u;
	*p_object = object;
	*p_operations = operations;
	story_actor_continue(script, p_object, p_operations);
}

/* Operation 0E: flips the in-the-air bit of its flags */
void story_actor_toggle_airborne(uint16_t script, uint16_t *p_object, uint16_t *p_operations)
{
	uint16_t object = (uint16_t)*p_object;
	uint16_t operations = (uint16_t)*p_operations;

	OBJECT(object)->flags ^= 8u;
	*p_object = object;
	*p_operations = operations;
	story_actor_continue(script, p_object, p_operations);
}

/* Operation 10: waits until the object a variable holds has its own wait (field 2D) down to 1 */
uint16_t story_actor_wait_for_object(uint16_t object, uint16_t script)
{
	uint16_t object_variable = 0;
	uint16_t variable_at = 0;

	variable_at = script;
	object_variable = mem_read16(variable_at);
	OBJECT(object)->behaviour = mem_read16(object_variable);
	OBJECT(object)->story_actor.script = variable_at + 2u;
	return story_actor_finish_frame(object, object_variable);
}

/* Operation 11: asks for the players and waits for them, then clears their fields */
void story_actor_wait_for_players(uint16_t script, uint16_t *p_object, uint16_t *p_u)
{
	uint16_t object = (uint16_t)*p_object;
	uint16_t u = (uint16_t)*p_u;
	uint8_t players_signal = 0;

	players_signal = io_read8(0x184Eu);
	if (players_signal != 0u)
		story_actor_continue(script, &object, &u);
	else
	{
		OBJECT(object)->action_step = 1u;
		io_write8(0x184Bu, 1u);
		OBJECT(object)->story_actor.script = script;
		u = story_actor_finish_frame(object, u);
	}
	*p_object = object;
	*p_u = u;
}

/* Operation 12: a random player present takes an animation facing an object */
void story_actor_random_player_faces(uint16_t script, uint16_t *p_object, uint16_t *p_target_x)
{
	uint16_t object = (uint16_t)*p_object;
	uint8_t attributes = 0;
	uint16_t player = 0, target_x = 0;
	uint16_t stack = 0;
	uint8_t attributes_2 = 0;
	uint16_t animation_at = 0, variable_at = 0, faced_x = 0, player_x = 0;

	stack = object;
	player = story_random_player();
	animation_at = script;
	OBJECT(player)->animation = mem_read8(animation_at);
	attributes_2 = OBJECT(player)->attributes;
	attributes = attributes_2 & 0xBFu;
	variable_at = animation_at + 1u;
	script = variable_at + 2u;
	faced_x = io_read16(mem_read16(mem_read16(variable_at)) + 0xCu);
	target_x = faced_x;
	player_x = OBJECT(player)->x;
	if ((int16_t)target_x < (int16_t)player_x)
		attributes |= 0x40u;
	OBJECT(player)->attributes = attributes;
	object = stack;
	*p_object = object;
	*p_target_x = target_x;
	story_actor_continue(script, p_object, p_target_x);
}

/* Operation 13: the players not in one animation take another */
void story_actor_set_players_animation(uint16_t script, uint16_t *p_object, uint16_t *p_operations)
{
	uint16_t object = (uint16_t)*p_object;
	uint16_t operations = (uint16_t)*p_operations;
	uint32_t zero = 0;
	uint16_t player = 0;
	uint16_t stack = 0;
	uint8_t animation = 0, new_animation = 0;

	stack = object;
	player = story_first_player();
	do
	{
		if (OBJECT(player)->flags == 0u)
		{
			animation = OBJECT(player)->animation;
			if (animation != mem_read8(script))
			{
				new_animation = mem_read8(script + 1u);
				OBJECT(player)->animation = new_animation;
			}
		}
		story_next_player(&player, &zero);
	} while (zero == 0u);
	object = stack;
	script += 2u;
	*p_object = object;
	*p_operations = operations;
	story_actor_continue(script, p_object, p_operations);
}

/* Operation 14: faces the object a variable holds */
void story_actor_face_object(uint16_t script, uint16_t *p_object, uint16_t *p_target_x)
{
	uint16_t object = (uint16_t)*p_object;
	uint8_t attributes = 0;
	uint16_t target_x = 0;
	uint8_t attributes_2 = 0, animation_flags = 0;
	uint16_t variable_at = 0, faced_x = 0, actor_x = 0;

	attributes_2 = OBJECT(object)->attributes;
	attributes = attributes_2 & 0xBFu;
	variable_at = script;
	script = variable_at + 2u;
	faced_x = io_read16(mem_read16(mem_read16(variable_at)) + 0xCu);
	target_x = faced_x;
	actor_x = OBJECT(object)->x;
	if ((int16_t)target_x < (int16_t)actor_x)
		attributes |= 0x40u;
	OBJECT(object)->attributes = attributes;
	animation_flags = OBJECT(object)->animation_flags;
	OBJECT(object)->animation_flags = animation_flags | 0x80u;
	*p_object = object;
	*p_target_x = target_x;
	story_actor_continue(script, p_object, p_target_x);
}

/* Operation 15: waits until it is down to a height */
uint16_t story_actor_wait_for_height(uint16_t object, uint16_t script, uint16_t operations)
{
	uint8_t landing_height = 0;
	uint16_t height_at = 0;

	height_at = script;
	landing_height = mem_read8(height_at) + 1u;
	OBJECT(object)->story_actor.landing_height = landing_height;
	io_write8(0x184Bu, landing_height);
	OBJECT(object)->story_actor.script = height_at + 1u;
	return story_actor_finish_frame(object, operations);
}

/* Operation 16: puts in a child actor it does not keep */
void story_actor_put_in_child(uint16_t *p_object, uint16_t *p_u)
{
	uint16_t object = (uint16_t)*p_object;
	uint32_t carry = 0;
	uint16_t ignored16 = 0, ignored16_2 = 0, script = 0, u = 0;
	uint16_t saved_leftover_y = 0;

	saved_leftover_y = leftover_y;
	vector_spawn_child(object, &ignored16, &u, &ignored16_2, &carry);
	script = saved_leftover_y + 8u;
	*p_object = object;
	*p_u = u;
	story_actor_continue(script, p_object, p_u);
}

/* Operation 17: waits for the camera to reach an x */
uint16_t story_actor_wait_for_camera(uint16_t object, uint16_t script, uint16_t operations)
{
	uint16_t camera_x_at = 0;

	camera_x_at = script;
	OBJECT(object)->story_actor.camera_wait = mem_read16(camera_x_at);
	OBJECT(object)->story_actor.script = camera_x_at + 2u;
	return story_actor_finish_frame(object, operations);
}

/* Operation 18: writes a byte to a variable */
void story_actor_set_variable(uint16_t script, uint16_t *p_object, uint16_t *p_variable)
{
	uint16_t object = (uint16_t)*p_object;
	uint16_t variable = 0;
	uint16_t variable_at = 0, value_at = 0;

	variable_at = script;
	variable = mem_read16(variable_at);
	value_at = variable_at + 2u;
	script = value_at + 1u;
	mem_write8(variable, mem_read8(value_at));
	*p_object = object;
	*p_variable = variable;
	story_actor_continue(script, p_object, p_variable);
}

/* Operation 19: the four players hold nothing any more, then the next operation. */
void story_actor_drop_players_held(uint16_t script, uint16_t *p_object, uint16_t *p_operations)
{
	uint16_t object = (uint16_t)*p_object;
	uint16_t operations = (uint16_t)*p_operations;

	OBJECT(OBJECT_ADDRESS(0))->unk_3F = 0u;
	OBJECT(OBJECT_ADDRESS(0))->parent &= 0xFFu;
	OBJECT(OBJECT_ADDRESS(2))->unk_3F = 0u;
	OBJECT(OBJECT_ADDRESS(2))->parent &= 0xFFu;
	OBJECT(OBJECT_ADDRESS(4))->unk_3F = 0u;
	OBJECT(OBJECT_ADDRESS(4))->parent &= 0xFFu;
	OBJECT(OBJECT_ADDRESS(6))->unk_3F = 0u;
	OBJECT(OBJECT_ADDRESS(6))->parent &= 0xFFu;
	*p_object = object;
	*p_operations = operations;
	story_actor_continue(script, p_object, p_operations);
}

/* Operation 1B: waits until it reaches an x on the screen */
uint16_t story_actor_wait_for_x(uint16_t object, uint16_t script, uint16_t operations)
{
	uint16_t x_wait_at = 0;

	x_wait_at = script;
	OBJECT(object)->story_actor.x_wait = mem_read16(x_wait_at) + 1u;
	OBJECT(object)->story_actor.script = x_wait_at + 2u;
	return story_actor_finish_frame(object, operations);
}

/* Operation 1C: puts the four players at steps from a place, and maybe shows them */
void story_actor_place_players(uint16_t script, uint16_t *p_object, uint16_t *p_places)
{
	uint16_t object = (uint16_t)*p_object;
	uint32_t zero = 0;
	uint16_t places = 0, player = 0;
	uint16_t stack = 0;
	uint16_t place_x_at = 0, place_y_at = 0, offset_x_at = 0, offset_y_at = 0, run_in_at = 0;

	place_x_at = script;
	place_players_x = mem_read16(place_x_at);
	place_y_at = place_x_at + 2u;
	script = place_y_at + 2u;
	place_players_y = mem_read16(place_y_at);
	stack = object;
	places = story_player_place_offsets_ADDRESS;
	player = story_first_player();
	do
	{
		offset_x_at = places;
		OBJECT(player)->x = mem_read16(offset_x_at) + place_players_x;
		offset_y_at = offset_x_at + 2u;
		places = offset_y_at + 2u;
		OBJECT(player)->y = mem_read16(offset_y_at) + place_players_y;
		story_next_player(&player, &zero);
	} while (zero == 0u);
	object = stack;
	run_in_at = script;
	script = run_in_at + 1u;
	if (mem_read8(run_in_at) == 0u)
		story_actor_continue(script, &object, &places);
	else
	{
		OBJECT(OBJECT_ADDRESS(0))->flags = 4u;
		OBJECT(OBJECT_ADDRESS(2))->flags = 4u;
		OBJECT(OBJECT_ADDRESS(4))->flags = 4u;
		OBJECT(OBJECT_ADDRESS(6))->flags = 4u;
		story_actor_continue(script, &object, &places);
	}
	*p_object = object;
	*p_places = places;
}

/* Operation 1D: the players not playing take one of four scripts at random */
void story_actor_start_absent_players(uint16_t script, uint16_t *p_object, uint16_t *p_absent_script)
{
	uint16_t object = (uint16_t)*p_object;
	uint32_t zero = 0;
	uint8_t playing = 0;
	uint16_t absent_script = 0, player = 0;
	uint16_t stack = 0;
	uint8_t playing_bits = 0;

	absent_script = story_scripts[64 + (random_number & 6u) / 2u];
	playing = players_playing;
	stack = object;
	player = story_first_player();
	do
	{
		playing_bits = playing;
		playing = playing_bits >> 1;
		if ((playing_bits & 1u) == 0u)
		{
			OBJECT(player)->target_dx = (OBJECT(player)->target_dx & 0xFF00u) | 0x1u;
			OBJECT(player)->target_dy = absent_script;
		}
		story_next_player(&player, &zero);
	} while (zero == 0u);
	object = stack;
	*p_object = object;
	*p_absent_script = absent_script;
	story_actor_continue(script, p_object, p_absent_script);
}

/* Operation 1F: waits until the floor under it is a given one */
uint16_t story_actor_wait_for_floor(uint16_t object, uint16_t script, uint16_t operations)
{
	uint16_t floor_at = 0;

	floor_at = script;
	OBJECT(object)->zoom_y = mem_read8(floor_at);
	OBJECT(object)->zoom_x = 1u;
	OBJECT(object)->story_actor.script = floor_at + 1u;
	return story_actor_finish_frame(object, operations);
}

/* Operation 21: a random player present speaks the line, its balloon over it */
void story_actor_player_speaks(uint16_t script, uint16_t *p_object, uint16_t *p_operations)
{
	uint16_t object = (uint16_t)*p_object;
	uint16_t operations = (uint16_t)*p_operations;
	uint32_t carry = 0;
	uint8_t parameter = 0, voice_high = 0, voice_low = 0;
	uint16_t command = 0, player = 0;
	uint8_t stack_10003 = 0, stack_10004 = 0;
	uint16_t stack = 0;
	uint8_t kind = 0, kind_2 = 0;
	uint16_t voice = 0, speaker_x = 0, speaker_y = 0, balloon_y = 0, z = 0, balloon_z = 0;
	uint32_t kind_halfword = 0;

	stack = object;
	player = story_random_player();
	kind = OBJECT(player)->kind;
	voice = mem_read16(script + (int8_t)((uint32_t)kind << 1));
	voice_high = (uint8_t)(voice >> 8);
	voice_low = (uint8_t)voice;
	if ((uint16_t)(((uint32_t)voice_high << 8) | voice_low) < 0x3F08u || (uint16_t)(((uint32_t)voice_high << 8) | voice_low) > 0x3F0Bu)
	{
		if ((uint16_t)(((uint32_t)voice_high << 8) | voice_low) < 0x3F14u || (uint16_t)(((uint32_t)voice_high << 8) | voice_low) > 0x3F17u)
		{
			command = ((uint32_t)voice_high << 8) | voice_low;
			carry = vector_queue_sound(command);
			script += 8u;
			object = stack;
			*p_object = object;
			*p_operations = operations;
			story_actor_continue(script, p_object, p_operations);
			return;
		}
		stack_10003 = voice_high;
		stack_10004 = voice_low;
		kind_2 = OBJECT(player)->kind;
		kind_halfword = 0xB100u | (uint8_t)(kind_2 - 0x6Cu);
		OBJECT(player + 0x60u)->kind = (uint8_t)(kind_halfword >> 8u);
		OBJECT(player + 0x60u)->animation = (uint8_t)kind_halfword;
		parameter = 0x13u;
	}
	else
	{
		stack_10003 = voice_high;
		stack_10004 = voice_low;
		parameter = 0x33u;
	}
	OBJECT(player + 0x60u)->parameter = parameter;
	OBJECT(player + 0x60u)->flags = 4u;
	speaker_x = OBJECT(player)->x;
	OBJECT(player + 0x60u)->x = speaker_x;
	speaker_y = OBJECT(player)->y;
	balloon_y = speaker_y - 2u;
	OBJECT(player + 0x60u)->y = balloon_y;
	z = OBJECT(player)->z;
	balloon_z = z + 0x42u;
	OBJECT(player + 0x60u)->z = balloon_z;
	voice_high = stack_10003;
	voice_low = stack_10004;
	command = ((uint32_t)voice_high << 8) | voice_low;
	carry = vector_queue_sound(command);
	script += 8u;
	object = stack;
	*p_object = object;
	*p_operations = operations;
	story_actor_continue(script, p_object, p_operations);
}

/* Operation 22: starts or stops sound 4A00 every 16 frames */
void story_actor_toggle_repeat_sound(uint16_t script, uint16_t *p_object, uint16_t *p_operations)
{
	uint16_t object = (uint16_t)*p_object;
	uint16_t operations = (uint16_t)*p_operations;
	uint8_t script_flags = 0;

	script_flags = OBJECT(object)->story_actor.script_flags;
	OBJECT(object)->story_actor.script_flags = script_flags ^ 2u;
	*p_object = object;
	*p_operations = operations;
	story_actor_continue(script, p_object, p_operations);
}

/* Operation 23: flips bit 3 of the actor's field 42, then the next operation. */
void story_actor_toggle_flag_08(uint16_t script, uint16_t *p_object, uint16_t *p_operations)
{
	uint16_t object = (uint16_t)*p_object;
	uint16_t operations = (uint16_t)*p_operations;
	uint8_t script_flags = 0;

	script_flags = OBJECT(object)->story_actor.script_flags;
	OBJECT(object)->story_actor.script_flags = script_flags ^ 8u;
	*p_object = object;
	*p_operations = operations;
	story_actor_continue(script, p_object, p_operations);
}

/* Operation 24: waits, its player's presses shortening the wait */
uint16_t story_actor_wait_or_presses(uint16_t object, uint16_t script, uint16_t operations)
{
	uint8_t script_flags = 0;
	uint16_t wait_at = 0, wait_and_step = 0;

	script_flags = OBJECT(object)->story_actor.script_flags;
	OBJECT(object)->story_actor.script_flags = script_flags | 0x10u;
	wait_at = script;
	wait_and_step = mem_read16(wait_at);
	OBJECT(object)->damage = (uint8_t)(wait_and_step >> 8u);
	OBJECT(object)->attack = (uint8_t)wait_and_step;
	OBJECT(object)->story_actor.script = wait_at + 2u;
	return story_actor_finish_frame(object, operations);
}

/* Operation 25: stops it (speeds and accelerations cleared) */
void story_actor_stop(uint16_t script, uint16_t *p_object, uint16_t *p_operations)
{
	uint16_t object = (uint16_t)*p_object;
	uint16_t operations = (uint16_t)*p_operations;

	OBJECT(object)->x_speed = 0;
	OBJECT(object)->y_speed = 0;
	OBJECT(object)->z_speed = 0;
	OBJECT(object)->story_actor.acceleration_x = 0;
	OBJECT(object)->story_actor.acceleration_y = 0;
	OBJECT(object)->story_actor.acceleration_z = 0;
	*p_object = object;
	*p_operations = operations;
	story_actor_continue(script, p_object, p_operations);
}

/* Goes on to the next operation */
void story_actor_continue(uint16_t script, uint16_t *p_object, uint16_t *p_operations)
{
	uint16_t object = (uint16_t)*p_object;
	uint16_t operations = (uint16_t)*p_operations;

	*p_object = object;
	*p_operations = operations;
	story_actor_next_operation(script, p_object, p_operations);
}

/* Runs its children (and the players during a story), and removes it off the screen */
uint16_t story_actor_finish_frame(uint16_t object, uint16_t u)
{
	uint8_t actor_script = 0, count = 0;
	uint16_t child_slot = 0, y = 0;
	uint8_t stack_3 = 0;
	uint16_t stack = 0, stack_5 = 0;
	uint8_t children_left = 0, players_signal = 0, parameter = 0;
	uint16_t child_slot_at = 0, slot_child = 0, actor_x = 0, z = 0;

	if ((int16_t)object < 0x4A40 || (int16_t)object > 0x4CE0)
	{
		count = 0xBu;
		stack = object;
		child_slot = object + 0x43u;
		do
		{
			stack_3 = count;
			child_slot_at = child_slot;
			child_slot = child_slot_at + 2u;
			slot_child = mem_read16(child_slot_at);
			object = slot_child;
			if (slot_child != 0u)
			{
				stack_5 = child_slot;
				story_actor_run(&object, &u);
				child_slot = stack_5;
			}
			children_left = stack_3;
			count = children_left - 1u;
		} while (children_left != 1u);
		object = stack;
	}
	if (object == OBJECT_ADDRESS(32))
	{
		players_signal = io_read8(0x184Eu);
		if (players_signal != 0u)
		{
			stack = object;
			object = OBJECT_ADDRESS(0);
			story_actor_run(&object, &u);
			object = OBJECT_ADDRESS(1);
			story_actor_run(&object, &u);
			object = OBJECT_ADDRESS(2);
			story_actor_run(&object, &u);
			object = OBJECT_ADDRESS(3);
			story_actor_run(&object, &u);
			object = OBJECT_ADDRESS(4);
			story_actor_run(&object, &u);
			object = OBJECT_ADDRESS(5);
			story_actor_run(&object, &u);
			object = OBJECT_ADDRESS(6);
			story_actor_run(&object, &u);
			object = OBJECT_ADDRESS(7);
			story_actor_run(&object, &u);
			object = stack;
		}
	}
	if (object == OBJECT_ADDRESS(32))
		return u;
	parameter = OBJECT(object)->parameter;
	actor_script = parameter;
	if (actor_script == 0x21u || actor_script == 0xDu)
		return u;
	actor_x = OBJECT(object)->x;
	y = actor_x;
	if ((int16_t)y < 0x190 && (int16_t)y >= 0)
	{
		z = OBJECT(object)->z;
		y = z;
		if ((int16_t)y < 0x280 && (int16_t)y > -0x200)
			return u;
	}
	return story_actor_remove(object, u);
}

/* Removes the actor; the one at 5640 ends the story and hands the players back */
uint16_t story_actor_remove(uint16_t object, uint16_t u)
{
	uint32_t zero = 0;
	uint8_t fill = 0;
	uint16_t child_slot = 0, count = 0, ignored16 = 0, parent = 0, player = 0;
	uint16_t stack = 0, stack_4 = 0;
	uint8_t discarded_read = 0, discarded_read_2 = 0, attributes = 0, old_bits = 0, slots_left = 0;
	uint16_t parent_2 = 0, child_slot_at = 0;

	if (object == OBJECT_ADDRESS(32))
	{
		scene_running = 0u;
		discarded_read = io_read8(0x184Bu);
		io_write8(0x184Bu, 0u);
		discarded_read_2 = io_read8(0x184Eu);
		io_write8(0x184Eu, 0u);
		io_write16(0x1852u, 0u);
		io_write16(0x1854u, 0u);
		io_write16(0x1856u, 0u);
		io_write16(0x1858u, 0u);
		OBJECT(object)->flags = 0u;
		stack = object;
		player = story_first_player();
		do
		{
			if (OBJECT(player)->flags != 0u)
			{
				OBJECT(player)->parameter = 0u;
				OBJECT(player + 0x60u)->parameter = 0u;
				OBJECT(player + 0x60u)->flags = 0u;
				attributes = OBJECT(player)->attributes;
				OBJECT(player)->attributes = attributes & 0xBFu;
				OBJECT(player)->x_speed = 0;
				OBJECT(player)->y_speed = 0;
				OBJECT(player)->z_speed = 0;
				stack_4 = player;
				player += 0x1Cu;
				count = 0x3Du;
				fill = 0u;
				while (count != 0u)
				{
					mem_write8(player, fill);
					player++;
					count--;
				}
				player = stack_4;
				old_bits = OBJECT(player)->unk_34;
				OBJECT(player)->unk_34 = old_bits | 2u;
			}
			OBJECT(player + 0x60u)->flags = 0u;
			OBJECT(player + 0x60u)->parameter = 0u;
			OBJECT(player)->kind = 4u - story_players_left;
			story_next_player(&player, &zero);
		} while (zero == 0u);
		parent = stack;
		story_actor_remove_children(&parent, &ignored16);
		return parent;
	}
	OBJECT(object)->flags = 0u;
	parent_2 = OBJECT(object)->parent;
	child_slot = parent_2 + 0x43u;
	story_players_left = 0xBu;
	for (;;)
	{
		child_slot_at = child_slot;
		child_slot = child_slot_at + 2u;
		if (object == mem_read16(child_slot_at))
			break;
		slots_left = story_players_left;
		story_players_left = slots_left - 1u;
		if (slots_left == 1u)
			return u;
	}
	mem_write16(child_slot - 2u, 0u);
	return u;
}

/* Removes an actor's children and theirs */
void story_actor_remove_children(uint16_t *p_parent, uint16_t *p_d)
{
	uint16_t parent = (uint16_t)*p_parent;
	uint16_t d = (uint16_t)*p_d;
	uint8_t count = 0;
	uint16_t child = 0, child_slot = 0, d_2 = 0;
	uint8_t stack = 0;
	uint8_t children_left = 0;
	uint16_t child_slot_at = 0, slot_child = 0;

	stack = d >> 8;
	count = 0xBu;
	child_slot = parent + 0x43u;
	do
	{
		child_slot_at = child_slot;
		child_slot = child_slot_at + 2u;
		slot_child = mem_read16(child_slot_at);
		child = slot_child;
		if (slot_child != 0u)
		{
			OBJECT(child)->flags = 0u;
			d_2 = (uint32_t)count << 8;
			story_actor_remove_children(&child, &d_2);
			count = (uint8_t)(d_2 >> 8);
		}
		children_left = count;
		count = children_left - 1u;
	} while (children_left != 1u);
	d_2 = (uint32_t)stack << 8;
	*p_parent = child;
	*p_d = (*p_d & 0xFFu) | d_2;
}

/* A random player present (in X), or the first present after it */
uint16_t story_random_player(void)
{
	uint32_t zero = 0;
	uint8_t kind = 0;
	uint16_t player = 0;
	uint8_t stack = 0, stack_10002 = 0;
	uint8_t kind_2 = 0, shifts_left = 0, player_bits = 0, first_bits = 0;
	uint16_t player_offset = 0, random_player = 0;

	story_player_bits = players_present;
	player_offset = (random_number & 3u) * 0xC0u;
	random_player = player_offset + OBJECT_ADDRESS(0);
	stack = random_player >> 8;
	stack_10002 = random_player;
	player = ((uint32_t)stack << 8) | stack_10002;
	kind_2 = OBJECT(player)->kind;
	kind = kind_2;
	if (kind_2 != 0u)
	{
		do
		{
			story_player_bits = story_player_bits >> 1;
			shifts_left = kind;
			kind = shifts_left - 1u;
		} while (shifts_left != 1u);
	}
	player_bits = story_player_bits;
	story_player_bits = player_bits >> 1;
	if (player_bits & 1u)
		return player;
	story_player_bits = players_present;
	player = story_first_player();
	do
	{
		first_bits = story_player_bits;
		story_player_bits = first_bits >> 1;
		if (first_bits & 1u)
			break;
		story_next_player(&player, &zero);
	} while (zero == 0u);
	return player;
}

/* Marge's object in X and a count of four */
uint16_t story_first_player(void)
{
	uint16_t player = 0;

	story_players_left = 4u;
	player = OBJECT_ADDRESS(0);
	return player;
}

/* The next player's object, counting down */
void story_next_player(uint16_t *p_player, uint32_t *p_zero)
{
	uint16_t player = (uint16_t)*p_player;
	uint32_t zero = *p_zero;
	uint8_t players_left = 0;

	player += 0xC0u;
	players_left = story_players_left - 1u;
	zero = players_left == 0u;
	story_players_left = players_left;
	*p_player = player;
	*p_zero = zero;
}
