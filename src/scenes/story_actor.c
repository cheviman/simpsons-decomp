/**
 *    Name:        scenes/story_actor.c
 *    Description: the story actor and its script's operations
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    09-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the game's 053248 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

/* Runs a story actor: starts its script, walks it, and when its wait is over runs its operations */
void story_actor_run(uint16_t *p_object, uint16_t *p_object_2, uint16_t *p_object_3)
{
	uint16_t object = (uint16_t)*p_object;
	uint16_t object_2 = (uint16_t)*p_object_2;
	uint16_t object_3 = (uint16_t)*p_object_3;
	uint32_t negative = 0, carry = 0;
	uint8_t a = 0, attributes = 0, b = 0, margin = 0;
	uint16_t awaited = 0, command = 0, d = 0, heading = 0, parent = 0, player_fields = 0, script = 0, u = 0, x = 0;
	uint8_t stack = 0, stack_2 = 0, stack_3 = 0;
	uint8_t flags = 0, script_number = 0, t2 = 0, t3 = 0, t13 = 0, t20 = 0, t22 = 0, t23 = 0, t24 = 0, t25 = 0, t26 = 0, t27 = 0, t28 = 0, t41 = 0, t42 = 0, t44 = 0, t45 = 0, t46 = 0, t48 = 0, t49 = 0, t52 = 0, t53 = 0, t54 = 0, t55 = 0, t56 = 0, t63 = 0, t64 = 0;
	uint16_t parent_2 = 0, t1 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, t8 = 0, t9 = 0, t10 = 0, t11 = 0, t12 = 0, t14 = 0, t15 = 0, t16 = 0, t17 = 0, t18 = 0, t19 = 0, t21 = 0, t29 = 0, t30 = 0, t31 = 0, t32 = 0, t33 = 0, t34 = 0, t35 = 0, t36 = 0, t37 = 0, t38 = 0, t39 = 0, t40 = 0, t43 = 0, t47 = 0, t50 = 0, t51 = 0, t57 = 0, t58 = 0, t59 = 0, t60 = 0, t61 = 0, t62 = 0;

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
			script_number = OBJECT(object)->story_actor.script_number;
			parent_2 = OBJECT(object)->parent;
			parent = parent_2;
			stack_2 = object >> 8;
			stack = (uint8_t)object;
			stack_3 = script_number;
			a = 0u;
			b = 0u;
			object += 0x28u;
			object_3 = 0x18u;
			while (object_3 != 0u)
			{
				mem_write8(object, a);
				mem_write8(object + 1u, b);
				object += 2u;
				object_3--;
			}
			b = stack_3;
			object = ((uint32_t)stack_2 << 8) | stack;
			io_write8(object + 0x30u, b);
			io_write16(object + 0x40u, parent);
			io_write8(object + 0x58u, 0u);
			io_write8(object + 0x2Du, 1u);
			object_2 = story_scripts[b & 0x7Fu];
			io_write16(object + 0x2Eu, object_2);
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
		script_number = OBJECT(object)->story_actor.script_number;
		parent_2 = OBJECT(object)->parent;
		parent = parent_2;
		stack_2 = object >> 8;
		stack = (uint8_t)object;
		stack_3 = script_number;
		a = 0u;
		b = 0u;
		object += 0x28u;
		object_3 = 0x18u;
		while (object_3 != 0u)
		{
			mem_write8(object, a);
			mem_write8(object + 1u, b);
			object += 2u;
			object_3--;
		}
		b = stack_3;
		object = ((uint32_t)stack_2 << 8) | stack;
		io_write8(object + 0x30u, b);
		io_write16(object + 0x40u, parent);
		io_write8(object + 0x58u, 0u);
		io_write8(object + 0x2Du, 1u);
		object_2 = story_scripts[b & 0x7Fu];
		io_write16(object + 0x2Eu, object_2);
	}
	if (object != OBJECT_ADDRESS(32))
	{
		t1 = mem_read16(object + 0x37u);
		object_3 = t1;
		if (t1 != 0u)
		{
			t2 = mem_read8(object + 0x1Fu);
			actor_reach = t2;
			t3 = mem_read8(object + 0x39u);
			t4 = (int8_t)(0u - t3);
			t5 = mem_read16(object + 0xCu);
			t6 = t4 + t5;
			actor_reach_centre_x = t6;
			t7 = actor_reach_centre_x;
			t8 = t7 - actor_reach;
			t9 = OBJECT(object_3)->x;
			if ((int16_t)t8 < (int16_t)t9)
			{
				t10 = actor_reach_centre_x;
				t11 = t10 + actor_reach;
				t12 = OBJECT(object_3)->x;
				if ((int16_t)t12 < (int16_t)t11)
				{
					t13 = mem_read8(object + 0x20u);
					actor_reach = t13;
					t14 = mem_read16(object + 0x11u);
					t15 = t14 - actor_reach;
					t16 = OBJECT(object_3)->y;
					if ((int16_t)t15 < (int16_t)t16)
					{
						t17 = mem_read16(object + 0x11u);
						t18 = t17 + actor_reach;
						t19 = OBJECT(object_3)->y;
						if ((int16_t)t19 < (int16_t)t18)
						{
							mem_write16(object + 0xFu, 0u);
							mem_write16(object + 0x14u, 0u);
							mem_write16(object + 0x19u, 0u);
							mem_write16(object + 0x37u, 0u);
							t20 = mem_read8(object + 6u);
							mem_write8(object + 6u, t20 | 0x40u);
							mem_write16(object + 0x37u, 0u);
							t21 = mem_read16(object + 0x2Eu);
							script = t21;
							*p_object = object;
							*p_object_2 = script;
							*p_object_3 = object_3;
							story_actor_next_operation(p_object, p_object_2, p_object_3);
							return;
						}
					}
				}
			}
			t22 = mem_read8(object + 0x39u);
			margin = t22;
			t23 = mem_read8(object + 4u);
			a = t23;
			if (a <= 3u)
			{
				t24 = mem_read8(object + 0x39u);
				t25 = mem_read8(object + 0x39u);
				stack = (int8_t)t25 >> 1;
				margin = (uint32_t)a * margin - t24 - stack;
			}
			d = margin;
			d = vector_direction_to_offset(object, object_3, d);
			a = (uint8_t)(d >> 8);
			t26 = mem_read8(object + 0x3Au);
			heading = ((uint32_t)a << 8) | t26;
			vector_set_speed_by_direction(object, heading);
			t27 = mem_read8(object + 0x42u);
			if ((t27 & 1u) == 0u)
			{
				t28 = mem_read8(object + 9u);
				attributes = t28 & 0xBFu;
				t29 = mem_read16(object + 0xFu);
				object_3 = t29;
				if ((int16_t)t29 < 0)
					attributes |= 0x40u;
				mem_write8(object + 9u, attributes);
			}
		}
		t30 = mem_read16(object + 0xFu);
		t31 = mem_read16(object + 0x31u);
		t32 = t30 + t31;
		mem_write16(object + 0xFu, t32);
		t33 = mem_read16(object + 0x14u);
		t34 = mem_read16(object + 0x33u);
		t35 = t33 + t34;
		mem_write16(object + 0x14u, t35);
		t36 = mem_read16(object + 0x19u);
		t37 = mem_read16(object + 0x35u);
		t38 = t36 + t37;
		mem_write16(object + 0x19u, t38);
	}
	else
	{
		object_2 = camera_y;
		mem_write16(object + 0x11u, object_2);
		t39 = mem_read16(object + 0x31u);
		players_push_x = t39;
		t40 = mem_read16(object + 0x33u);
		players_push_y = t40;
	}
	t41 = mem_read8(object + 0x42u);
	if ((t41 & 2u) != 0u && (frame_count & 0xFu) == 0u)
	{
		command = 0x4A00u;
		carry = vector_queue_sound(command);
	}
	t42 = mem_read8(object + 0x42u);
	if ((t42 & 4u) != 0u)
	{
		*p_object_2 = object_2;
		*p_object_3 = object_3;
		story_actor_finish_frame(object, p_object_2, p_object_3);
		*p_object = object;
		return;
	}
	t43 = mem_read16(object + 0x2Au);
	awaited = t43;
	if (t43 != 0u)
	{
		t44 = (uint8_t)OBJECT(awaited)->target_dx;
		if (t44 != 1u)
		{
			*p_object_2 = awaited;
			*p_object_3 = object_3;
			story_actor_finish_frame(object, p_object_2, p_object_3);
			*p_object = object;
			return;
		}
		mem_write16(object + 0x2Au, 0u);
		mem_write16(object + 0x37u, 0u);
		t21 = mem_read16(object + 0x2Eu);
		script = t21;
		*p_object = object;
		*p_object_2 = script;
		*p_object_3 = object_3;
		story_actor_next_operation(p_object, p_object_2, p_object_3);
		return;
	}
	t45 = mem_read8(object + 0x29u);
	if (t45 != 0u)
	{
		t46 = io_read8(0x184Eu);
		if (t46 == 0u)
		{
			*p_object_2 = awaited;
			*p_object_3 = object_3;
			story_actor_finish_frame(object, p_object_2, p_object_3);
			*p_object = object;
			return;
		}
		mem_write8(object + 0x29u, 0u);
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
		x = ((uint32_t)stack_2 << 8) | stack;
		mem_write16(x + 0x37u, 0u);
		t21 = mem_read16(x + 0x2Eu);
		script = t21;
		*p_object = x;
		*p_object_2 = script;
		*p_object_3 = u;
		story_actor_next_operation(p_object, p_object_2, p_object_3);
		return;
	}
	t47 = mem_read16(object + 0x3Cu);
	a = (uint8_t)(t47 >> 8);
	b = (uint8_t)t47;
	if (t47 != 0u)
	{
		if ((int16_t)camera_x <= (int16_t)(((uint32_t)a << 8) | b))
		{
			*p_object_2 = awaited;
			*p_object_3 = object_3;
			story_actor_finish_frame(object, p_object_2, p_object_3);
			*p_object = object;
			return;
		}
		mem_write16(object + 0x3Cu, 0u);
		mem_write16(object + 0x37u, 0u);
		t21 = mem_read16(object + 0x2Eu);
		script = t21;
		*p_object = object;
		*p_object_2 = script;
		*p_object_3 = object_3;
		story_actor_next_operation(p_object, p_object_2, p_object_3);
		return;
	}
	t48 = mem_read8(object + 0x42u);
	if ((t48 & 0x10u) != 0u)
	{
		t49 = mem_read8(object + 4u);
		t50 = 4u * t49;
		t51 = t50 + (player_controls_ADDRESS + 0x2u);
		stack = t51;
		stack_2 = t51 >> 8;
		u = ((uint32_t)stack_2 << 8) | stack;
		if (mem_read8(u) != 0u)
		{
			t52 = mem_read8(object + 0x1Du);
			a = t52;
			if (t52 != 0u)
			{
				a--;
				mem_write8(object + 0x1Du, a);
				t53 = mem_read8(object + 0x1Cu);
				a += t53;
				if (a <= 0xE0u)
					mem_write8(object + 0x1Cu, a);
			}
		}
		t54 = mem_read8(object + 0x1Cu);
		mem_write8(object + 0x1Cu, t54 - 1u);
		if (t54 != 1u)
		{
			*p_object_2 = awaited;
			*p_object_3 = u;
			story_actor_finish_frame(object, p_object_2, p_object_3);
			*p_object = object;
			return;
		}
		t55 = mem_read8(object + 0x42u);
		mem_write8(object + 0x42u, t55 & 0xEFu);
		mem_write16(object + 0x37u, 0u);
		t21 = mem_read16(object + 0x2Eu);
		script = t21;
		*p_object = object;
		*p_object_2 = script;
		*p_object_3 = u;
		story_actor_next_operation(p_object, p_object_2, p_object_3);
		return;
	}
	t56 = mem_read8(object + 0x3Bu);
	b = t56;
	if (t56 != 0u)
	{
		a = 0u;
		t57 = mem_read16(object + 0x16u);
		if ((int16_t)b < (int16_t)t57)
		{
			*p_object_2 = awaited;
			*p_object_3 = object_3;
			story_actor_finish_frame(object, p_object_2, p_object_3);
			*p_object = object;
			return;
		}
		mem_write16(object + 0x16u, ((uint32_t)a << 8) | (uint8_t)(b - 1u));
		mem_write8(object + 0x18u, 0u);
		mem_write8(object + 0x3Bu, 0u);
		mem_write16(object + 0x37u, 0u);
		t21 = mem_read16(object + 0x2Eu);
		script = t21;
		*p_object = object;
		*p_object_2 = script;
		*p_object_3 = object_3;
		story_actor_next_operation(p_object, p_object_2, p_object_3);
		return;
	}
	t58 = mem_read16(object + 0x3Eu);
	a = (uint8_t)(t58 >> 8);
	b = (uint8_t)t58;
	if (t58 != 0u)
	{
		t59 = (((uint32_t)a << 8) | b) - camera_x;
		a = (uint8_t)(t59 >> 8);
		b = (uint8_t)t59;
		t60 = mem_read16(object + 0xCu);
		if ((int16_t)t60 < (int16_t)(((uint32_t)a << 8) | b))
		{
			*p_object_2 = awaited;
			*p_object_3 = object_3;
			story_actor_finish_frame(object, p_object_2, p_object_3);
			*p_object = object;
			return;
		}
		t61 = (((uint32_t)a << 8) | b) - 1u;
		mem_write16(object + 0xCu, t61);
		mem_write8(object + 0xEu, 0u);
		mem_write16(object + 0x3Eu, 0u);
		mem_write16(object + 0x37u, 0u);
		t21 = mem_read16(object + 0x2Eu);
		script = t21;
		*p_object = object;
		*p_object_2 = script;
		*p_object_3 = object_3;
		story_actor_next_operation(p_object, p_object_2, p_object_3);
		return;
	}
	t62 = mem_read16(object + 0xAu);
	if (t62 == 0u)
	{
		t63 = mem_read8(object + 0x2Du);
		mem_write8(object + 0x2Du, t63 - 1u);
		if (t63 != 1u)
		{
			*p_object_2 = awaited;
			*p_object_3 = object_3;
			story_actor_finish_frame(object, p_object_2, p_object_3);
			*p_object = object;
			return;
		}
		mem_write16(object + 0x37u, 0u);
		t21 = mem_read16(object + 0x2Eu);
		script = t21;
		*p_object = object;
		*p_object_2 = script;
		*p_object_3 = object_3;
		story_actor_next_operation(p_object, p_object_2, p_object_3);
		return;
	}
	vector_floor_ahead(object, &d, &negative);
	a = (uint8_t)(d >> 8);
	t64 = mem_read8(object + 0xBu);
	if ((a & 0xFu) != t64)
	{
		*p_object_2 = awaited;
		*p_object_3 = object_3;
		story_actor_finish_frame(object, p_object_2, p_object_3);
		*p_object = object;
		return;
	}
	mem_write16(object + 0xAu, 0u);
	mem_write16(object + 0x37u, 0u);
	t21 = mem_read16(object + 0x2Eu);
	script = t21;
	*p_object = object;
	*p_object_2 = script;
	*p_object_3 = object_3;
	story_actor_next_operation(p_object, p_object_2, p_object_3);
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
void story_actor_next_operation(uint16_t *p_object, uint16_t *p_script, uint16_t *p_operations)
{
	uint16_t object = (uint16_t)*p_object;
	uint16_t script = (uint16_t)*p_script;
	uint16_t operations = (uint16_t)*p_operations;
	uint8_t a = 0;
	uint16_t t1 = 0;

	t1 = script;
	script = t1 + 1u;
	a = mem_read8(t1);
	if (a == 0xFFu)
		story_actor_remove(object, &script, &operations);
	else
	{
		operations = story_actor_operations_ADDRESS;
		switch ((int8_t)(uint8_t)((uint32_t)a << 1))
		{
		case 0:
			story_actor_set_kind(&object, &script, &operations);
			break;
		case 2:
			story_actor_set_animation(&object, &script, &operations);
			break;
		case 4:
			story_actor_set_place(&object, &script, &operations);
			break;
		case 6:
			story_actor_set_speeds(&object, &script, &operations);
			break;
		case 8:
			story_actor_set_accelerations(&object, &script, &operations);
			break;
		case 10:
			story_actor_walk_to(&object, &script, &operations);
			break;
		case 12:
			story_actor_put_in(&object, &script, &operations);
			break;
		case 14:
			story_actor_wait(object, &script, &operations);
			break;
		case 16:
			story_actor_set_accelerations_xy(&object, &script, &operations);
			break;
		case 18:
			story_actor_line_up_players(&object, &script, &operations);
			break;
		case 20:
			story_actor_set_hit_box(&object, &script, &operations);
			break;
		case 22:
			story_actor_play_sound(&object, &script, &operations);
			break;
		case 24:
			story_actor_halt(object, &script, &operations);
			break;
		case 26:
			story_actor_set_attributes(&object, &script, &operations);
			break;
		case 28:
			story_actor_toggle_airborne(&object, &script, &operations);
			break;
		case 30:
			story_actor_walk_to_partner(&object, &script, &operations);
			break;
		case 32:
			story_actor_wait_for_object(object, &script, &operations);
			break;
		case 34:
			story_actor_wait_for_players(&object, &script, &operations);
			break;
		case 36:
			story_actor_random_player_faces(&object, &script, &operations);
			break;
		case 38:
			story_actor_set_players_animation(&object, &script, &operations);
			break;
		case 40:
			story_actor_face_object(&object, &script, &operations);
			break;
		case 42:
			story_actor_wait_for_height(object, &script, &operations);
			break;
		case 44:
			story_actor_put_in_child(&object, &script, &operations);
			break;
		case 46:
			story_actor_wait_for_camera(object, &script, &operations);
			break;
		case 48:
			story_actor_set_variable(&object, &script, &operations);
			break;
		case 50:
			story_actor_drop_players_held(&object, &script, &operations);
			break;
		case 52:
			story_actor_walk_to_without_turning(&object, &script, &operations);
			break;
		case 54:
			story_actor_wait_for_x(object, &script, &operations);
			break;
		case 56:
			story_actor_place_players(&object, &script, &operations);
			break;
		case 58:
			story_actor_start_absent_players(&object, &script, &operations);
			break;
		case 60:
			story_actor_play_kind_sound(&object, &script, &operations);
			break;
		case 62:
			story_actor_wait_for_floor(object, &script, &operations);
			break;
		case 64:
			story_actor_play_sound_if_player(&object, &script, &operations);
			break;
		case 66:
			story_actor_player_speaks(&object, &script, &operations);
			break;
		case 68:
			story_actor_toggle_repeat_sound(&object, &script, &operations);
			break;
		case 70:
			story_actor_toggle_flag_08(&object, &script, &operations);
			break;
		case 72:
			story_actor_wait_or_presses(object, &script, &operations);
			break;
		case 74:
			story_actor_stop(&object, &script, &operations);
			break;
		}
	}
	*p_object = object;
	*p_script = script;
	*p_operations = operations;
}

/* Operation 00: its kind and animation */
void story_actor_set_kind(uint16_t *p_object, uint16_t *p_script, uint16_t *p_operations)
{
	uint16_t object = (uint16_t)*p_object;
	uint16_t script = (uint16_t)*p_script;
	uint16_t operations = (uint16_t)*p_operations;
	uint16_t t1 = 0;
	uint32_t kind_halfword = 0;

	t1 = script;
	script = t1 + 2u;
	kind_halfword = mem_read16(t1);
	OBJECT(object)->kind = (uint8_t)(kind_halfword >> 8u);
	OBJECT(object)->animation = (uint8_t)kind_halfword;
	*p_object = object;
	*p_script = script;
	*p_operations = operations;
	story_actor_continue(p_object, p_script, p_operations);
}

/* Operation 01: its animation */
void story_actor_set_animation(uint16_t *p_object, uint16_t *p_script, uint16_t *p_operations)
{
	uint16_t object = (uint16_t)*p_object;
	uint16_t script = (uint16_t)*p_script;
	uint16_t operations = (uint16_t)*p_operations;
	uint16_t t1 = 0;

	t1 = script;
	script = t1 + 1u;
	OBJECT(object)->animation = mem_read8(t1);
	*p_object = object;
	*p_script = script;
	*p_operations = operations;
	story_actor_continue(p_object, p_script, p_operations);
}

/* Operation 02: its place */
void story_actor_set_place(uint16_t *p_object, uint16_t *p_script, uint16_t *p_operations)
{
	uint16_t object = (uint16_t)*p_object;
	uint16_t script = (uint16_t)*p_script;
	uint16_t operations = (uint16_t)*p_operations;
	uint16_t t1 = 0, t2 = 0, t3 = 0;

	t1 = script;
	OBJECT(object)->x = mem_read16(t1);
	t2 = t1 + 2u;
	OBJECT(object)->y = mem_read16(t2);
	t3 = t2 + 2u;
	script = t3 + 2u;
	OBJECT(object)->z = mem_read16(t3);
	*p_object = object;
	*p_script = script;
	*p_operations = operations;
	story_actor_continue(p_object, p_script, p_operations);
}

/* Operation 03: its speeds */
void story_actor_set_speeds(uint16_t *p_object, uint16_t *p_script, uint16_t *p_operations)
{
	uint16_t object = (uint16_t)*p_object;
	uint16_t script = (uint16_t)*p_script;
	uint16_t operations = (uint16_t)*p_operations;
	uint16_t t1 = 0, t2 = 0, t3 = 0;

	t1 = script;
	OBJECT(object)->x_speed = mem_read16(t1);
	t2 = t1 + 2u;
	OBJECT(object)->y_speed = mem_read16(t2);
	t3 = t2 + 2u;
	script = t3 + 2u;
	OBJECT(object)->z_speed = mem_read16(t3);
	*p_object = object;
	*p_script = script;
	*p_operations = operations;
	story_actor_continue(p_object, p_script, p_operations);
}

/* Operation 04: what it adds to its speeds each frame */
void story_actor_set_accelerations(uint16_t *p_object, uint16_t *p_script, uint16_t *p_operations)
{
	uint16_t object = (uint16_t)*p_object;
	uint16_t script = (uint16_t)*p_script;
	uint16_t operations = (uint16_t)*p_operations;
	uint16_t t1 = 0, t2 = 0, t3 = 0;

	t1 = script;
	OBJECT(object)->story_actor.acceleration_x = mem_read16(t1);
	t2 = t1 + 2u;
	OBJECT(object)->story_actor.acceleration_y = mem_read16(t2);
	t3 = t2 + 2u;
	script = t3 + 2u;
	OBJECT(object)->story_actor.acceleration_z = mem_read16(t3);
	*p_object = object;
	*p_script = script;
	*p_operations = operations;
	story_actor_continue(p_object, p_script, p_operations);
}

/* Operation 1A: walks to an object without turning to face its way */
void story_actor_walk_to_without_turning(uint16_t *p_object, uint16_t *p_script, uint16_t *p_u)
{
	uint16_t object = (uint16_t)*p_object;
	uint16_t script = (uint16_t)*p_script;
	uint16_t u = 0;
	uint8_t script_flags = 0;

	script_flags = OBJECT(object)->story_actor.script_flags;
	OBJECT(object)->story_actor.script_flags = script_flags | 1u;
	*p_object = object;
	*p_script = script;
	*p_u = u;
	story_actor_walk_to_object_in(p_object, p_script, p_u);
}

/* Operation 0F: walks to its partner object (60 after it) */
void story_actor_walk_to_partner(uint16_t *p_object, uint16_t *p_script, uint16_t *p_operations)
{
	uint16_t object = (uint16_t)*p_object;
	uint16_t script = (uint16_t)*p_script;
	uint16_t operations = (uint16_t)*p_operations;
	uint16_t target = 0;
	uint16_t stack = 0;

	stack = object;
	target = stack + 0x60u;
	*p_object = object;
	*p_script = script;
	*p_operations = operations;
	story_actor_set_target(target, p_object, p_script, p_operations);
}

/* Operation 05: walks to an object, facing its way */
void story_actor_walk_to(uint16_t *p_object, uint16_t *p_script, uint16_t *p_u)
{
	uint16_t object = (uint16_t)*p_object;
	uint16_t script = (uint16_t)*p_script;
	uint16_t u = 0;
	uint8_t script_flags = 0;

	script_flags = OBJECT(object)->story_actor.script_flags;
	OBJECT(object)->story_actor.script_flags = script_flags & ~1u;
	*p_object = object;
	*p_script = script;
	*p_u = u;
	story_actor_walk_to_object_in(p_object, p_script, p_u);
}

/* Takes as its target the object a variable named in the script holds */
void story_actor_walk_to_object_in(uint16_t *p_object, uint16_t *p_script, uint16_t *p_target_address)
{
	uint16_t object = (uint16_t)*p_object;
	uint16_t script = (uint16_t)*p_script;
	uint16_t target = 0, target_address = 0;
	uint16_t t1 = 0;

	t1 = script;
	script = t1 + 2u;
	target_address = mem_read16(t1);
	target = mem_read16(target_address);
	*p_object = object;
	*p_script = script;
	*p_target_address = target_address;
	story_actor_set_target(target, p_object, p_script, p_target_address);
}

/* Its target, how far before it to stop, and its speed */
void story_actor_set_target(uint16_t target, uint16_t *p_object, uint16_t *p_script, uint16_t *p_operations)
{
	uint16_t object = (uint16_t)*p_object;
	uint16_t script = (uint16_t)*p_script;
	uint16_t operations = (uint16_t)*p_operations;
	uint16_t d = 0;
	uint16_t t1 = 0;

	OBJECT(object)->story_actor.script_target = target;
	t1 = script;
	script = t1 + 2u;
	d = mem_read16(t1);
	OBJECT(object)->story_actor.target_margin = (uint8_t)(d >> 8u);
	OBJECT(object)->story_actor.walk_speed = (uint8_t)d;
	*p_object = object;
	*p_script = script;
	*p_operations = operations;
	story_actor_continue(p_object, p_script, p_operations);
}

/* Operation 06: puts in the players, their partners, or a child actor it keeps */
void story_actor_put_in(uint16_t *p_actor, uint16_t *p_script, uint16_t *p_object)
{
	uint16_t actor = (uint16_t)*p_actor;
	uint16_t script = (uint16_t)*p_script;
	uint16_t object = (uint16_t)*p_object;
	uint32_t zero = 0, carry = 0;
	uint8_t put_kind = 0;
	uint16_t ignored16 = 0, player = 0;
	uint16_t stack = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0, t15 = 0, t16 = 0, t17 = 0;
	uint16_t t4 = 0, t5 = 0, t6 = 0, t7 = 0, t8 = 0, t9 = 0, t10 = 0, t11 = 0, t12 = 0, z = 0, t13 = 0, t14 = 0;

	t1 = mem_read8(script + 5u);
	put_kind = t1;
	if (put_kind != 4u)
	{
		if (put_kind != 5u)
		{
			stack = script;
			vector_spawn_child(actor, script, &object, &ignored16, &carry);
			script = stack + 8u;
			if (carry == 0u)
				story_actor_continue(&actor, &script, &object);
			else
			{
				if (mem_read8(script - 3u) != 2u)
				{
					story_players_left = 0xBu;
					stack = actor;
					actor += 0x43u;
					for (;;)
					{
						if (mem_read16(actor) != 0u)
						{
							actor += 2u;
							t2 = story_players_left;
							story_players_left = t2 - 1u;
							if (t2 == 1u)
								break;
							continue;
						}
						mem_write16(actor, object);
						break;
					}
					actor = stack;
				}
				story_actor_continue(&actor, &script, &object);
			}
		}
		else
		{
			story_players_left = 4u;
			object = OBJECT_ADDRESS(1);
			for (;;)
			{
				if (OBJECT(object)->flags != 0u)
				{
					object += 0xC0u;
					t3 = story_players_left;
					story_players_left = t3 - 1u;
					if (t3 != 1u)
						continue;
					script += 8u;
					story_actor_continue(&actor, &script, &object);
					break;
				}
				OBJECT(object)->flags = 4u;
				t4 = script;
				t5 = mem_read16(t4);
				t6 = OBJECT(actor)->x;
				t7 = t5 + t6;
				OBJECT(object)->x = t7;
				t8 = t4 + 2u;
				t9 = mem_read16(t8);
				t10 = OBJECT(actor)->y;
				t11 = t9 + t10;
				OBJECT(object)->y = t11;
				t12 = t8 + 2u;
				z = OBJECT(actor)->z;
				t13 = mem_read8(t12) + z;
				OBJECT(object)->z = t13;
				t14 = t12 + 2u;
				script = t14 + 2u;
				OBJECT(object)->parameter = mem_read8(t14);
				story_actor_continue(&actor, &script, &object);
				break;
			}
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
			t15 = story_player_bits;
			story_player_bits = t15 >> 1;
			if (t15 & 1u)
				OBJECT(player)->flags = 4u;
			t16 = mem_read8(script + 6u);
			OBJECT(player)->parameter = t16;
			t17 = mem_read8(script + 7u);
			OBJECT(player)->kind = 4u - story_players_left + t17;
			story_next_player(&player, &zero);
		} while (zero == 0u);
		actor = stack;
		script += 8u;
		story_actor_continue(&actor, &script, &object);
	}
	*p_actor = actor;
	*p_script = script;
	*p_object = object;
}

/* Operation 07: waits that many frames */
void story_actor_wait(uint16_t object, uint16_t *p_script, uint16_t *p_u)
{
	uint16_t script = (uint16_t)*p_script;
	uint16_t u = (uint16_t)*p_u;
	uint16_t t1 = 0;

	t1 = script;
	script = t1 + 1u;
	OBJECT(object)->story_actor.wait = mem_read8(t1);
	OBJECT(object)->story_actor.script = script;
	*p_script = script;
	*p_u = u;
	story_actor_finish_frame(object, p_script, p_u);
}

/* Operation 08: what it adds to its x and y speeds */
void story_actor_set_accelerations_xy(uint16_t *p_object, uint16_t *p_script, uint16_t *p_operations)
{
	uint16_t object = (uint16_t)*p_object;
	uint16_t script = (uint16_t)*p_script;
	uint16_t operations = (uint16_t)*p_operations;
	uint16_t t1 = 0, t2 = 0;

	t1 = script;
	OBJECT(object)->story_actor.acceleration_x = mem_read16(t1);
	t2 = t1 + 2u;
	script = t2 + 2u;
	OBJECT(object)->story_actor.acceleration_y = mem_read16(t2);
	*p_object = object;
	*p_script = script;
	*p_operations = operations;
	story_actor_continue(p_object, p_script, p_operations);
}

/* Operation 09: lines the four players up in a random order */
void story_actor_line_up_players(uint16_t *p_object, uint16_t *p_script, uint16_t *p_line_offsets)
{
	uint16_t object = (uint16_t)*p_object;
	uint16_t script = (uint16_t)*p_script;
	uint32_t zero = 0;
	uint8_t a = 0, b = 0;
	uint16_t line_offsets = 0, player = 0;
	uint16_t stack = 0;
	uint8_t t1 = 0, t8 = 0;
	uint16_t t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, t9 = 0, t10 = 0, t11 = 0;

	line_offsets = player_line_up_orders_ADDRESS + (random_number & 0xCu);
	stack = object;
	player = story_first_player();
	do
	{
		b = 4u - story_players_left;
		t1 = mem_read8(script + 6u);
		a = t1;
		if ((int8_t)t1 < 0)
		{
			t2 = (uint32_t)(uint8_t)(0u - a) * b;
			t3 = 0u - t2;
			a = (uint8_t)(t3 >> 8);
			b = (uint8_t)t3;
		}
		else
		{
			t4 = (uint32_t)a * b;
			a = (uint8_t)(t4 >> 8);
			b = (uint8_t)t4;
		}
		t5 = (((uint32_t)a << 8) | b) + mem_read16(script);
		OBJECT(player)->x = t5;
		t6 = mem_read16(script + 2u);
		OBJECT(player)->y = t6;
		t7 = line_offsets;
		line_offsets = t7 + 1u;
		t8 = mem_read8(script + 7u);
		t9 = (uint32_t)t8 * mem_read8(t7);
		t10 = mem_read16(script + 4u);
		t11 = t9 + t10;
		OBJECT(player)->z = t11;
		story_next_player(&player, &zero);
	} while (zero == 0u);
	object = stack;
	script += 8u;
	*p_object = object;
	*p_script = script;
	*p_line_offsets = line_offsets;
	story_actor_continue(p_object, p_script, p_line_offsets);
}

/* Operation 0A: a hit box */
void story_actor_set_hit_box(uint16_t *p_object, uint16_t *p_script, uint16_t *p_operations)
{
	uint16_t object = (uint16_t)*p_object;
	uint16_t script = (uint16_t)*p_script;
	uint16_t operations = (uint16_t)*p_operations;
	uint16_t t1 = 0, t2 = 0, t3 = 0;

	OBJECT(object)->flags |= 0x40u;
	t1 = script;
	t2 = mem_read16(t1);
	OBJECT(object)->box_width = (uint8_t)(t2 >> 8u);
	OBJECT(object)->box_depth = (uint8_t)t2;
	t3 = t1 + 2u;
	script = t3 + 1u;
	OBJECT(object)->box_height = mem_read8(t3);
	*p_object = object;
	*p_script = script;
	*p_operations = operations;
	story_actor_continue(p_object, p_script, p_operations);
}

/* Operation 20: a sound, if that player's object is in use */
void story_actor_play_sound_if_player(uint16_t *p_object, uint16_t *p_script, uint16_t *p_sound)
{
	uint16_t object = (uint16_t)*p_object;
	uint16_t script = (uint16_t)*p_script;
	uint32_t carry = 0;
	uint16_t command = 0, sound = 0;
	uint8_t stack_10003 = 0, stack_10004 = 0;
	uint16_t stack = 0;
	uint8_t t5 = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0, t4 = 0;

	t1 = script;
	sound = mem_read16(t1);
	t2 = t1 + 2u;
	script = t2 + 1u;
	t3 = 0xC0u * mem_read8(t2);
	t4 = t3 + OBJECT_ADDRESS(0);
	stack = object;
	stack_10003 = t4 >> 8;
	stack_10004 = t4;
	t5 = mem_read8(((uint32_t)stack_10003 << 8) | stack_10004);
	object = stack;
	if (t5 == 0u)
		story_actor_continue(&object, &script, &sound);
	else
	{
		stack = sound;
		command = stack;
		carry = vector_queue_sound(command);
		story_actor_continue(&object, &script, &sound);
	}
	*p_object = object;
	*p_script = script;
	*p_sound = sound;
}

/* Operation 1E: a sound command plus its kind (a character's voice) */
void story_actor_play_kind_sound(uint16_t *p_object, uint16_t *p_script, uint16_t *p_operations)
{
	uint16_t object = (uint16_t)*p_object;
	uint16_t script = (uint16_t)*p_script;
	uint16_t operations = (uint16_t)*p_operations;
	uint32_t carry = 0;
	uint16_t command = 0;
	uint8_t kind = 0;
	uint16_t t1 = 0, t2 = 0;

	kind = OBJECT(object)->kind;
	t1 = script;
	script = t1 + 2u;
	t2 = kind + mem_read16(t1);
	command = t2;
	carry = vector_queue_sound(command);
	*p_object = object;
	*p_script = script;
	*p_operations = operations;
	story_actor_continue(p_object, p_script, p_operations);
}

/* Operation 0B: a sound command */
void story_actor_play_sound(uint16_t *p_object, uint16_t *p_script, uint16_t *p_operations)
{
	uint16_t object = (uint16_t)*p_object;
	uint16_t script = (uint16_t)*p_script;
	uint16_t operations = (uint16_t)*p_operations;
	uint32_t carry = 0;
	uint16_t command = 0;
	uint16_t t1 = 0;

	t1 = script;
	script = t1 + 2u;
	command = mem_read16(t1);
	carry = vector_queue_sound(command);
	*p_object = object;
	*p_script = script;
	*p_operations = operations;
	story_actor_continue(p_object, p_script, p_operations);
}

/* Operation 0C: stops its script for good */
void story_actor_halt(uint16_t object, uint16_t *p_script, uint16_t *p_u)
{
	uint16_t script = (uint16_t)*p_script;
	uint16_t u = (uint16_t)*p_u;
	uint8_t script_flags = 0;

	script_flags = OBJECT(object)->story_actor.script_flags;
	OBJECT(object)->story_actor.script_flags = script_flags | 4u;
	OBJECT(object)->story_actor.script = script;
	*p_script = script;
	*p_u = u;
	story_actor_finish_frame(object, p_script, p_u);
}

/* Operation 0D: its sprite attributes, its animation restarted */
void story_actor_set_attributes(uint16_t *p_object, uint16_t *p_script, uint16_t *p_operations)
{
	uint16_t object = (uint16_t)*p_object;
	uint16_t script = (uint16_t)*p_script;
	uint16_t operations = (uint16_t)*p_operations;
	uint8_t animation_flags = 0;
	uint16_t t1 = 0;

	t1 = script;
	script = t1 + 1u;
	OBJECT(object)->attributes = mem_read8(t1);
	animation_flags = OBJECT(object)->animation_flags;
	OBJECT(object)->animation_flags = animation_flags | 0x80u;
	*p_object = object;
	*p_script = script;
	*p_operations = operations;
	story_actor_continue(p_object, p_script, p_operations);
}

/* Operation 0E: flips the in-the-air bit of its flags */
void story_actor_toggle_airborne(uint16_t *p_object, uint16_t *p_script, uint16_t *p_operations)
{
	uint16_t object = (uint16_t)*p_object;
	uint16_t script = (uint16_t)*p_script;
	uint16_t operations = (uint16_t)*p_operations;

	OBJECT(object)->flags ^= 8u;
	*p_object = object;
	*p_script = script;
	*p_operations = operations;
	story_actor_continue(p_object, p_script, p_operations);
}

/* Operation 10: waits until the object a variable holds has its own wait (field 2D) down to 1 */
void story_actor_wait_for_object(uint16_t object, uint16_t *p_script, uint16_t *p_u)
{
	uint16_t script = (uint16_t)*p_script;
	uint16_t u = 0;
	uint16_t t1 = 0;

	t1 = script;
	script = t1 + 2u;
	u = mem_read16(t1);
	OBJECT(object)->behaviour = mem_read16(u);
	OBJECT(object)->story_actor.script = script;
	*p_script = script;
	*p_u = u;
	story_actor_finish_frame(object, p_script, p_u);
}

/* Operation 11: asks for the players and waits for them, then clears their fields */
void story_actor_wait_for_players(uint16_t *p_object, uint16_t *p_script, uint16_t *p_u)
{
	uint16_t object = (uint16_t)*p_object;
	uint16_t script = (uint16_t)*p_script;
	uint16_t u = (uint16_t)*p_u;
	uint8_t t1 = 0;

	t1 = io_read8(0x184Eu);
	if (t1 != 0u)
		story_actor_continue(&object, &script, &u);
	else
	{
		OBJECT(object)->action_step = 1u;
		io_write8(0x184Bu, 1u);
		OBJECT(object)->story_actor.script = script;
		story_actor_finish_frame(object, &script, &u);
	}
	*p_object = object;
	*p_script = script;
	*p_u = u;
}

/* Operation 12: a random player present takes an animation facing an object */
void story_actor_random_player_faces(uint16_t *p_object, uint16_t *p_script, uint16_t *p_target_x)
{
	uint16_t object = (uint16_t)*p_object;
	uint16_t script = (uint16_t)*p_script;
	uint8_t attributes = 0;
	uint16_t player = 0, target_x = 0;
	uint16_t stack = 0;
	uint8_t attributes_2 = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0, t4 = 0;

	stack = object;
	player = story_random_player();
	t1 = script;
	OBJECT(player)->animation = mem_read8(t1);
	attributes_2 = OBJECT(player)->attributes;
	attributes = attributes_2 & 0xBFu;
	t2 = t1 + 1u;
	script = t2 + 2u;
	t3 = io_read16(mem_read16(mem_read16(t2)) + 0xCu);
	target_x = t3;
	t4 = OBJECT(player)->x;
	if ((int16_t)target_x < (int16_t)t4)
		attributes |= 0x40u;
	OBJECT(player)->attributes = attributes;
	object = stack;
	*p_object = object;
	*p_script = script;
	*p_target_x = target_x;
	story_actor_continue(p_object, p_script, p_target_x);
}

/* Operation 13: the players not in one animation take another */
void story_actor_set_players_animation(uint16_t *p_object, uint16_t *p_script, uint16_t *p_operations)
{
	uint16_t object = (uint16_t)*p_object;
	uint16_t script = (uint16_t)*p_script;
	uint16_t operations = (uint16_t)*p_operations;
	uint32_t zero = 0;
	uint16_t player = 0;
	uint16_t stack = 0;
	uint8_t animation = 0, t1 = 0;

	stack = object;
	player = story_first_player();
	do
	{
		if (OBJECT(player)->flags == 0u)
		{
			animation = OBJECT(player)->animation;
			if (animation != mem_read8(script))
			{
				t1 = mem_read8(script + 1u);
				OBJECT(player)->animation = t1;
			}
		}
		story_next_player(&player, &zero);
	} while (zero == 0u);
	object = stack;
	script += 2u;
	*p_object = object;
	*p_script = script;
	*p_operations = operations;
	story_actor_continue(p_object, p_script, p_operations);
}

/* Operation 14: faces the object a variable holds */
void story_actor_face_object(uint16_t *p_object, uint16_t *p_script, uint16_t *p_target_x)
{
	uint16_t object = (uint16_t)*p_object;
	uint16_t script = (uint16_t)*p_script;
	uint8_t attributes = 0;
	uint16_t target_x = 0;
	uint8_t attributes_2 = 0, animation_flags = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0;

	attributes_2 = OBJECT(object)->attributes;
	attributes = attributes_2 & 0xBFu;
	t1 = script;
	script = t1 + 2u;
	t2 = io_read16(mem_read16(mem_read16(t1)) + 0xCu);
	target_x = t2;
	t3 = OBJECT(object)->x;
	if ((int16_t)target_x < (int16_t)t3)
		attributes |= 0x40u;
	OBJECT(object)->attributes = attributes;
	animation_flags = OBJECT(object)->animation_flags;
	OBJECT(object)->animation_flags = animation_flags | 0x80u;
	*p_object = object;
	*p_script = script;
	*p_target_x = target_x;
	story_actor_continue(p_object, p_script, p_target_x);
}

/* Operation 15: waits until it is down to a height */
void story_actor_wait_for_height(uint16_t object, uint16_t *p_script, uint16_t *p_u)
{
	uint16_t script = (uint16_t)*p_script;
	uint16_t u = (uint16_t)*p_u;
	uint8_t landing_height = 0;
	uint16_t t1 = 0;

	t1 = script;
	script = t1 + 1u;
	landing_height = mem_read8(t1) + 1u;
	OBJECT(object)->story_actor.landing_height = landing_height;
	io_write8(0x184Bu, landing_height);
	OBJECT(object)->story_actor.script = script;
	*p_script = script;
	*p_u = u;
	story_actor_finish_frame(object, p_script, p_u);
}

/* Operation 16: puts in a child actor it does not keep */
void story_actor_put_in_child(uint16_t *p_object, uint16_t *p_script, uint16_t *p_u)
{
	uint16_t object = (uint16_t)*p_object;
	uint16_t script = (uint16_t)*p_script;
	uint32_t carry = 0;
	uint16_t ignored16 = 0, u = 0;
	uint16_t stack = 0;

	stack = script;
	vector_spawn_child(object, script, &u, &ignored16, &carry);
	script = stack + 8u;
	*p_object = object;
	*p_script = script;
	*p_u = u;
	story_actor_continue(p_object, p_script, p_u);
}

/* Operation 17: waits for the camera to reach an x */
void story_actor_wait_for_camera(uint16_t object, uint16_t *p_script, uint16_t *p_u)
{
	uint16_t script = (uint16_t)*p_script;
	uint16_t u = (uint16_t)*p_u;
	uint16_t t1 = 0;

	t1 = script;
	script = t1 + 2u;
	OBJECT(object)->story_actor.camera_wait = mem_read16(t1);
	OBJECT(object)->story_actor.script = script;
	*p_script = script;
	*p_u = u;
	story_actor_finish_frame(object, p_script, p_u);
}

/* Operation 18: writes a byte to a variable */
void story_actor_set_variable(uint16_t *p_object, uint16_t *p_script, uint16_t *p_u)
{
	uint16_t object = (uint16_t)*p_object;
	uint16_t script = (uint16_t)*p_script;
	uint16_t u = 0;
	uint16_t t1 = 0, t2 = 0;

	t1 = script;
	u = mem_read16(t1);
	t2 = t1 + 2u;
	script = t2 + 1u;
	mem_write8(u, mem_read8(t2));
	*p_object = object;
	*p_script = script;
	*p_u = u;
	story_actor_continue(p_object, p_script, p_u);
}

/* Operation 19: the four players hold nothing any more, then the next operation. */
void story_actor_drop_players_held(uint16_t *p_object, uint16_t *p_script, uint16_t *p_operations)
{
	uint16_t object = (uint16_t)*p_object;
	uint16_t script = (uint16_t)*p_script;
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
	*p_script = script;
	*p_operations = operations;
	story_actor_continue(p_object, p_script, p_operations);
}

/* Operation 1B: waits until it reaches an x on the screen */
void story_actor_wait_for_x(uint16_t object, uint16_t *p_script, uint16_t *p_u)
{
	uint16_t script = (uint16_t)*p_script;
	uint16_t u = (uint16_t)*p_u;
	uint16_t t1 = 0;

	t1 = script;
	script = t1 + 2u;
	OBJECT(object)->story_actor.x_wait = mem_read16(t1) + 1u;
	OBJECT(object)->story_actor.script = script;
	*p_script = script;
	*p_u = u;
	story_actor_finish_frame(object, p_script, p_u);
}

/* Operation 1C: puts the four players at steps from a place, and maybe shows them */
void story_actor_place_players(uint16_t *p_object, uint16_t *p_script, uint16_t *p_places)
{
	uint16_t object = (uint16_t)*p_object;
	uint16_t script = (uint16_t)*p_script;
	uint32_t zero = 0;
	uint16_t places = 0, player = 0;
	uint16_t stack = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0;

	t1 = script;
	place_players_x = mem_read16(t1);
	t2 = t1 + 2u;
	script = t2 + 2u;
	place_players_y = mem_read16(t2);
	stack = object;
	places = story_player_place_offsets_ADDRESS;
	player = story_first_player();
	do
	{
		t3 = places;
		OBJECT(player)->x = mem_read16(t3) + place_players_x;
		t4 = t3 + 2u;
		places = t4 + 2u;
		OBJECT(player)->y = mem_read16(t4) + place_players_y;
		story_next_player(&player, &zero);
	} while (zero == 0u);
	object = stack;
	t5 = script;
	script = t5 + 1u;
	if (mem_read8(t5) == 0u)
		story_actor_continue(&object, &script, &places);
	else
	{
		OBJECT(OBJECT_ADDRESS(0))->flags = 4u;
		OBJECT(OBJECT_ADDRESS(2))->flags = 4u;
		OBJECT(OBJECT_ADDRESS(4))->flags = 4u;
		OBJECT(OBJECT_ADDRESS(6))->flags = 4u;
		story_actor_continue(&object, &script, &places);
	}
	*p_object = object;
	*p_script = script;
	*p_places = places;
}

/* Operation 1D: the players not playing take one of four scripts at random */
void story_actor_start_absent_players(uint16_t *p_object, uint16_t *p_script, uint16_t *p_absent_script)
{
	uint16_t object = (uint16_t)*p_object;
	uint16_t script = (uint16_t)*p_script;
	uint32_t zero = 0;
	uint8_t playing = 0;
	uint16_t absent_script = 0, player = 0;
	uint16_t stack = 0;
	uint8_t t1 = 0;

	absent_script = story_scripts[64 + (random_number & 6u) / 2u];
	playing = players_playing;
	stack = object;
	player = story_first_player();
	do
	{
		t1 = playing;
		playing = t1 >> 1;
		if ((t1 & 1u) == 0u)
		{
			OBJECT(player)->target_dx = (OBJECT(player)->target_dx & 0xFF00u) | 0x1u;
			OBJECT(player)->target_dy = absent_script;
		}
		story_next_player(&player, &zero);
	} while (zero == 0u);
	object = stack;
	*p_object = object;
	*p_script = script;
	*p_absent_script = absent_script;
	story_actor_continue(p_object, p_script, p_absent_script);
}

/* Operation 1F: waits until the floor under it is a given one */
void story_actor_wait_for_floor(uint16_t object, uint16_t *p_script, uint16_t *p_u)
{
	uint16_t script = (uint16_t)*p_script;
	uint16_t u = (uint16_t)*p_u;
	uint16_t t1 = 0;

	t1 = script;
	script = t1 + 1u;
	OBJECT(object)->zoom_y = mem_read8(t1);
	OBJECT(object)->zoom_x = 1u;
	OBJECT(object)->story_actor.script = script;
	*p_script = script;
	*p_u = u;
	story_actor_finish_frame(object, p_script, p_u);
}

/* Operation 21: a random player present speaks the line, its balloon over it */
void story_actor_player_speaks(uint16_t *p_object, uint16_t *p_script, uint16_t *p_operations)
{
	uint16_t object = (uint16_t)*p_object;
	uint16_t script = (uint16_t)*p_script;
	uint16_t operations = (uint16_t)*p_operations;
	uint32_t carry = 0;
	uint8_t a = 0, b = 0, parameter = 0;
	uint16_t command = 0, player = 0;
	uint8_t stack_10003 = 0, stack_10004 = 0;
	uint16_t stack = 0;
	uint8_t kind = 0, kind_2 = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0, t4 = 0, z = 0, t5 = 0;
	uint32_t kind_halfword = 0;

	stack = object;
	player = story_random_player();
	kind = OBJECT(player)->kind;
	t1 = mem_read16(script + (int8_t)((uint32_t)kind << 1));
	a = (uint8_t)(t1 >> 8);
	b = (uint8_t)t1;
	if ((uint16_t)(((uint32_t)a << 8) | b) < 0x3F08u || (uint16_t)(((uint32_t)a << 8) | b) > 0x3F0Bu)
	{
		if ((uint16_t)(((uint32_t)a << 8) | b) < 0x3F14u || (uint16_t)(((uint32_t)a << 8) | b) > 0x3F17u)
		{
			command = ((uint32_t)a << 8) | b;
			carry = vector_queue_sound(command);
			script += 8u;
			object = stack;
			*p_object = object;
			*p_script = script;
			*p_operations = operations;
			story_actor_continue(p_object, p_script, p_operations);
			return;
		}
		stack_10003 = a;
		stack_10004 = b;
		kind_2 = OBJECT(player)->kind;
		kind_halfword = 0xB100u | (uint8_t)(kind_2 - 0x6Cu);
		OBJECT(player + 0x60u)->kind = (uint8_t)(kind_halfword >> 8u);
		OBJECT(player + 0x60u)->animation = (uint8_t)kind_halfword;
		parameter = 0x13u;
	}
	else
	{
		stack_10003 = a;
		stack_10004 = b;
		parameter = 0x33u;
	}
	OBJECT(player + 0x60u)->parameter = parameter;
	OBJECT(player + 0x60u)->flags = 4u;
	t2 = OBJECT(player)->x;
	OBJECT(player + 0x60u)->x = t2;
	t3 = OBJECT(player)->y;
	t4 = t3 - 2u;
	OBJECT(player + 0x60u)->y = t4;
	z = OBJECT(player)->z;
	t5 = z + 0x42u;
	OBJECT(player + 0x60u)->z = t5;
	a = stack_10003;
	b = stack_10004;
	command = ((uint32_t)a << 8) | b;
	carry = vector_queue_sound(command);
	script += 8u;
	object = stack;
	*p_object = object;
	*p_script = script;
	*p_operations = operations;
	story_actor_continue(p_object, p_script, p_operations);
}

/* Operation 22: starts or stops sound 4A00 every 16 frames */
void story_actor_toggle_repeat_sound(uint16_t *p_object, uint16_t *p_script, uint16_t *p_operations)
{
	uint16_t object = (uint16_t)*p_object;
	uint16_t script = (uint16_t)*p_script;
	uint16_t operations = (uint16_t)*p_operations;
	uint8_t script_flags = 0;

	script_flags = OBJECT(object)->story_actor.script_flags;
	OBJECT(object)->story_actor.script_flags = script_flags ^ 2u;
	*p_object = object;
	*p_script = script;
	*p_operations = operations;
	story_actor_continue(p_object, p_script, p_operations);
}

/* Operation 23: flips bit 3 of the actor's field 42, then the next operation. */
void story_actor_toggle_flag_08(uint16_t *p_object, uint16_t *p_script, uint16_t *p_operations)
{
	uint16_t object = (uint16_t)*p_object;
	uint16_t script = (uint16_t)*p_script;
	uint16_t operations = (uint16_t)*p_operations;
	uint8_t script_flags = 0;

	script_flags = OBJECT(object)->story_actor.script_flags;
	OBJECT(object)->story_actor.script_flags = script_flags ^ 8u;
	*p_object = object;
	*p_script = script;
	*p_operations = operations;
	story_actor_continue(p_object, p_script, p_operations);
}

/* Operation 24: waits, its player's presses shortening the wait */
void story_actor_wait_or_presses(uint16_t object, uint16_t *p_script, uint16_t *p_u)
{
	uint16_t script = (uint16_t)*p_script;
	uint16_t u = (uint16_t)*p_u;
	uint8_t script_flags = 0;
	uint16_t t1 = 0, t2 = 0;

	script_flags = OBJECT(object)->story_actor.script_flags;
	OBJECT(object)->story_actor.script_flags = script_flags | 0x10u;
	t1 = script;
	script = t1 + 2u;
	t2 = mem_read16(t1);
	OBJECT(object)->damage = (uint8_t)(t2 >> 8u);
	OBJECT(object)->attack = (uint8_t)t2;
	OBJECT(object)->story_actor.script = script;
	*p_script = script;
	*p_u = u;
	story_actor_finish_frame(object, p_script, p_u);
}

/* Operation 25: stops it (speeds and accelerations cleared) */
void story_actor_stop(uint16_t *p_object, uint16_t *p_script, uint16_t *p_operations)
{
	uint16_t object = (uint16_t)*p_object;
	uint16_t script = (uint16_t)*p_script;
	uint16_t operations = (uint16_t)*p_operations;

	OBJECT(object)->x_speed = 0;
	OBJECT(object)->y_speed = 0;
	OBJECT(object)->z_speed = 0;
	OBJECT(object)->story_actor.acceleration_x = 0;
	OBJECT(object)->story_actor.acceleration_y = 0;
	OBJECT(object)->story_actor.acceleration_z = 0;
	*p_object = object;
	*p_script = script;
	*p_operations = operations;
	story_actor_continue(p_object, p_script, p_operations);
}

/* Goes on to the next operation */
void story_actor_continue(uint16_t *p_object, uint16_t *p_script, uint16_t *p_operations)
{
	uint16_t object = (uint16_t)*p_object;
	uint16_t script = (uint16_t)*p_script;
	uint16_t operations = (uint16_t)*p_operations;

	*p_object = object;
	*p_script = script;
	*p_operations = operations;
	story_actor_next_operation(p_object, p_script, p_operations);
}

/* Runs its children (and the players during a story), and removes it off the screen */
void story_actor_finish_frame(uint16_t object, uint16_t *p_script, uint16_t *p_u)
{
	uint16_t script = (uint16_t)*p_script;
	uint16_t u = (uint16_t)*p_u;
	uint8_t a = 0, count = 0;
	uint16_t ignored16 = 0;
	uint8_t stack_3 = 0;
	uint16_t stack = 0, stack_5 = 0;
	uint8_t t3 = 0, t4 = 0, parameter = 0;
	uint16_t t1 = 0, t2 = 0, t5 = 0, z = 0;

	if ((int16_t)object < 0x4A40 || (int16_t)object > 0x4CE0)
	{
		count = 0xBu;
		stack = object;
		script = object + 0x43u;
		do
		{
			stack_3 = count;
			t1 = script;
			script = t1 + 2u;
			t2 = mem_read16(t1);
			object = t2;
			if (t2 != 0u)
			{
				stack_5 = script;
				story_actor_run(&object, &ignored16, &u);
				script = stack_5;
			}
			t3 = stack_3;
			count = t3 - 1u;
		} while (t3 != 1u);
		object = stack;
	}
	if (object == OBJECT_ADDRESS(32))
	{
		t4 = io_read8(0x184Eu);
		if (t4 != 0u)
		{
			stack = object;
			object = OBJECT_ADDRESS(0);
			story_actor_run(&object, &script, &u);
			object = OBJECT_ADDRESS(1);
			story_actor_run(&object, &script, &u);
			object = OBJECT_ADDRESS(2);
			story_actor_run(&object, &script, &u);
			object = OBJECT_ADDRESS(3);
			story_actor_run(&object, &script, &u);
			object = OBJECT_ADDRESS(4);
			story_actor_run(&object, &script, &u);
			object = OBJECT_ADDRESS(5);
			story_actor_run(&object, &script, &u);
			object = OBJECT_ADDRESS(6);
			story_actor_run(&object, &script, &u);
			object = OBJECT_ADDRESS(7);
			story_actor_run(&object, &script, &u);
			object = stack;
		}
	}
	if (object != OBJECT_ADDRESS(32))
	{
		parameter = OBJECT(object)->parameter;
		a = parameter;
		if (a != 0x21u && a != 0xDu)
		{
			t5 = OBJECT(object)->x;
			script = t5;
			if ((int16_t)script >= 0x190 || (int16_t)script < 0)
				story_actor_remove(object, &script, &u);
			else
			{
				z = OBJECT(object)->z;
				script = z;
				if ((int16_t)script >= 0x280 || (int16_t)script <= -0x200)
					story_actor_remove(object, &script, &u);
			}
		}
	}
	*p_script = script;
	*p_u = u;
}

/* Removes the actor; the one at 5640 ends the story and hands the players back */
void story_actor_remove(uint16_t object, uint16_t *p_child_slot, uint16_t *p_u)
{
	uint16_t child_slot = (uint16_t)*p_child_slot;
	uint16_t u = (uint16_t)*p_u;
	uint32_t zero = 0;
	uint8_t a = 0;
	uint16_t count = 0, ignored16 = 0, player = 0;
	uint16_t stack = 0, stack_4 = 0;
	uint8_t t1 = 0, t2 = 0, attributes = 0, t3 = 0, t5 = 0;
	uint16_t parent = 0, t4 = 0;

	if (object == OBJECT_ADDRESS(32))
	{
		scene_running = 0u;
		t1 = io_read8(0x184Bu);
		io_write8(0x184Bu, 0u);
		t2 = io_read8(0x184Eu);
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
				a = 0u;
				while (count != 0u)
				{
					mem_write8(player, a);
					player++;
					count--;
				}
				player = stack_4;
				t3 = OBJECT(player)->unk_34;
				OBJECT(player)->unk_34 = t3 | 2u;
			}
			OBJECT(player + 0x60u)->flags = 0u;
			OBJECT(player + 0x60u)->parameter = 0u;
			OBJECT(player)->kind = 4u - story_players_left;
			story_next_player(&player, &zero);
		} while (zero == 0u);
		u = stack;
		story_actor_remove_children(&u, &ignored16);
	}
	else
	{
		OBJECT(object)->flags = 0u;
		parent = OBJECT(object)->parent;
		child_slot = parent + 0x43u;
		story_players_left = 0xBu;
		do
		{
			t4 = child_slot;
			child_slot = t4 + 2u;
			if (object == mem_read16(t4))
			{
				mem_write16(child_slot - 2u, 0u);
				break;
			}
			t5 = story_players_left;
			story_players_left = t5 - 1u;
		} while (t5 != 1u);
	}
	*p_child_slot = child_slot;
	*p_u = u;
}

/* Removes an actor's children and theirs */
void story_actor_remove_children(uint16_t *p_parent, uint16_t *p_d)
{
	uint16_t parent = (uint16_t)*p_parent;
	uint16_t d = (uint16_t)*p_d;
	uint8_t count = 0;
	uint16_t child = 0, child_slot = 0, d_2 = 0;
	uint8_t stack = 0;
	uint8_t t3 = 0;
	uint16_t t1 = 0, t2 = 0;

	stack = d >> 8;
	count = 0xBu;
	child_slot = parent + 0x43u;
	do
	{
		t1 = child_slot;
		child_slot = t1 + 2u;
		t2 = mem_read16(t1);
		child = t2;
		if (t2 != 0u)
		{
			OBJECT(child)->flags = 0u;
			d_2 = (uint32_t)count << 8;
			story_actor_remove_children(&child, &d_2);
			count = (uint8_t)(d_2 >> 8);
		}
		t3 = count;
		count = t3 - 1u;
	} while (t3 != 1u);
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
	uint8_t kind_2 = 0, t3 = 0, t4 = 0, t5 = 0;
	uint16_t t1 = 0, t2 = 0;

	story_player_bits = players_present;
	t1 = (random_number & 3u) * 0xC0u;
	t2 = t1 + OBJECT_ADDRESS(0);
	stack = t2 >> 8;
	stack_10002 = t2;
	player = ((uint32_t)stack << 8) | stack_10002;
	kind_2 = OBJECT(player)->kind;
	kind = kind_2;
	if (kind_2 != 0u)
	{
		do
		{
			story_player_bits = story_player_bits >> 1;
			t3 = kind;
			kind = t3 - 1u;
		} while (t3 != 1u);
	}
	t4 = story_player_bits;
	story_player_bits = t4 >> 1;
	if (t4 & 1u)
		return player;
	story_player_bits = players_present;
	player = story_first_player();
	do
	{
		t5 = story_player_bits;
		story_player_bits = t5 >> 1;
		if (t5 & 1u)
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
	uint8_t t1 = 0;

	player += 0xC0u;
	t1 = story_players_left - 1u;
	zero = t1 == 0u;
	story_players_left = t1;
	*p_player = player;
	*p_zero = zero;
}
