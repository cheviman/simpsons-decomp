/**
 *    Name:        bosses/dreamland_boss.c
 *    Description: the stage 6 (Dreamland) boss (type F8): its forms, routines, hits and death
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    11-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the game's 053248 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

/* Runs the step routine given, then checks the boss's hits and turns it back at the stage's edges. */
void dreamland_boss_run_step(uint16_t object, uint8_t step)
{
	switch ((int8_t)(uint8_t)((uint32_t)step << 1))
	{
	case 0:
		dreamland_boss_setup(object);
		break;
	case 2:
		dreamland_boss_entrance(object);
		break;
	case 4:
	case 36:
		dreamland_boss_flinch(object);
		break;
	case 6:
		dreamland_boss_chase(object);
		break;
	case 8:
		dreamland_boss_charge(object);
		break;
	case 10:
		dreamland_boss_first_form_hit(object);
		break;
	case 12:
		dreamland_boss_change_to_second_form(object);
		break;
	case 14:
		dreamland_boss_pose_round(object);
		break;
	case 16:
		dreamland_boss_leap(object);
		break;
	case 18:
		dreamland_boss_second_form_hit(object);
		break;
	case 20:
		dreamland_boss_change_to_third_form(object);
		break;
	case 22:
		dreamland_boss_third_form_walk(object);
		break;
	case 24:
		dreamland_boss_spit(object);
		break;
	case 26:
		dreamland_boss_third_form_hit(object);
		break;
	case 28:
		dreamland_boss_change_to_last_form(object);
		break;
	case 30:
		dreamland_boss_wobble(object);
		break;
	case 32:
		dreamland_boss_creep(object);
		break;
	case 34:
		dreamland_boss_lash(object);
		break;
	case 38:
		dreamland_boss_defeat(object);
		break;
	case -4:
		dreamland_boss_beaten(object);
		break;
	case -2:
		dreamland_boss_hit(object);
		break;
	}
	object_take_special_hit(object, 0u);
	dreamland_boss_bounce_off_edges(object);
}

/* Its vitality gone, the boss takes its plain hit box and goes to its form's end (the step 77BC gives by
   its phase). */
void dreamland_boss_beaten(uint16_t object)
{
	uint8_t phase = 0;
	uint16_t hit_box = 0;

	hit_box = OBJECT(object)->hit_box;
	leftover_y = hit_box;
	vector_set_hit_box(object);
	phase = OBJECT(object)->dreamland_boss.phase;
	OBJECT(object)->state = object_1a_next_states[(int8_t)phase];
}

/* When the boss is hit: below its form's level for the players in the game it goes to its form's end,
   otherwise to its form's hit reaction. */
void dreamland_boss_hit(uint16_t object)
{
	uint8_t object_1a_level = 0;
	uint8_t phase = 0, vitality = 0, phase_2 = 0, phase_3 = 0;
	uint16_t hit_box = 0;

	hit_box = OBJECT(object)->hit_box;
	leftover_y = hit_box;
	vector_set_hit_box(object);
	phase = OBJECT(object)->dreamland_boss.phase;
	object_1a_level = OBJECT_1A_LEVEL(object_1a_level_rows[(int8_t)((uint8_t)((uint32_t)phase << 1)) / 2] + (int8_t)player_count);
	io_write8(dreamland_boss_phase_vitality, object_1a_level);
	vitality = OBJECT(object)->vitality;
	if (vitality <= object_1a_level)
	{
		phase_2 = OBJECT(object)->dreamland_boss.phase;
		OBJECT(object)->state = object_1a_next_states[(int8_t)phase_2];
		return;
	}
	phase_3 = OBJECT(object)->dreamland_boss.phase;
	OBJECT(object)->state = object_1a_states_after[(int8_t)phase_3];
}

/* Sets the boss up hidden, unbeatable (vitality FF) and out of the enemy count, with its sound, for its
   entrance. */
void dreamland_boss_setup(uint16_t object)
{
	uint16_t command = 0, setup = 0;

	setup = dreamland_boss_object_setup_ADDRESS;
	vector_object_setup(object, setup);
	OBJECT(object)->flags = 4u;
	OBJECT(object)->dreamland_boss.bounced_across = 4u;
	OBJECT(object)->dreamland_boss.bounced_in_depth = 4u;
	OBJECT(object)->shadow_player = 1u;
	OBJECT(object)->floor_z = 0u;
	OBJECT(object)->attributes = 0x10u;
	OBJECT(object)->vitality = 0xFFu;
	command = 0x6700u;
	vector_queue_sound(command);
	OBJECT(object)->dreamland_boss.phase = 0u;
	OBJECT(object)->enemy_class = -1;
	OBJECT(object)->entrance_pending = 0xFFu;
	OBJECT(object)->state = 1u;
	OBJECT(object)->dreamland_boss.resume_step = 1u;
	OBJECT(object)->dreamland_boss.routine_step = 0u;
	OBJECT(object)->dreamland_boss.change_step = 0u;
}

/* The boss's entrance, by field 52. */
void dreamland_boss_entrance(uint16_t object)
{
	uint8_t routine_step = 0;

	routine_step = OBJECT(object)->dreamland_boss.routine_step;
	switch ((int8_t)(uint8_t)((uint32_t)routine_step << 1))
	{
	case 0:
		dreamland_boss_appear(object);
		return;
	case 2:
		dreamland_boss_drop_in(object);
		return;
	case 4:
		dreamland_boss_bounce_in(object);
		return;
	case 6:
		dreamland_boss_settle(object);
		return;
	case 8:
		dreamland_boss_grow(object);
		return;
	case 10:
		dreamland_boss_entrance_pose(object);
		return;
	case 12:
		dreamland_boss_entrance_pose_end(object);
		return;
	case 14:
		dreamland_boss_start_fight(object);
		return;
	case 16:
		dreamland_boss_flinch_start(object);
		return;
	case 18:
		dreamland_boss_flinch_end(object);
		return;
	case 20:
		dreamland_boss_chase_start(object);
		return;
	case 22:
		dreamland_boss_chase_leg(object);
		return;
	case 24:
		dreamland_boss_chase_run(object);
		return;
	case 26:
		dreamland_boss_chase_next_leg(object);
		return;
	case 28:
		dreamland_boss_chase_rest(object);
		return;
	case 30:
		dreamland_boss_chase_rest_end(object);
		return;
	}
}

/* When direct page 92 is clear, shows the boss tiny, high over the stage, with a sound. */
void dreamland_boss_appear(uint16_t object)
{
	uint16_t command = 0;
	uint8_t attributes = 0, routine_step = 0;

	if (stage_scrolls_on != 0u)
		return;
	OBJECT(object)->flags = 0x98u;
	OBJECT(object)->enemy_class = 0;
	OBJECT(object)->entrance_pending = 0u;
	OBJECT(object)->zoom_x = 0x10u;
	OBJECT(object)->zoom_y = 0x10u;
	OBJECT(object)->animation = 0x80u;
	command = 0xFD00u;
	vector_queue_sound(command);
	attributes = OBJECT(object)->attributes;
	OBJECT(object)->attributes = attributes | 0x40u;
	OBJECT(object)->x = 0x120u;
	OBJECT(object)->z = 0x160u;
	camera_x_held--;
	routine_step = OBJECT(object)->dreamland_boss.routine_step;
	OBJECT(object)->dreamland_boss.routine_step = routine_step + 1u;
}

/* Drops the boss; when it lands it bounces with a thud and its attacking hit box. */
void dreamland_boss_drop_in(uint16_t object)
{
	uint32_t on_floor = 0;
	uint16_t command = 0;
	uint8_t routine_step = 0;

	OBJECT(object)->flags = 0x98u;
	on_floor = dreamland_boss_fall(object);
	if (on_floor == 0u)
	{
		camera_x_held--;
		return;
	}
	OBJECT(object)->flags = 0xDCu;
	leftover_y = dreamland_boss_attack_box_ADDRESS;
	vector_set_hit_box(object);
	OBJECT(object)->z_speed = 0x200;
	command = 0x6400u;
	vector_queue_sound(command);
	routine_step = OBJECT(object)->dreamland_boss.routine_step;
	OBJECT(object)->dreamland_boss.routine_step = routine_step + 1u;
	camera_x_held--;
}

/* Pulls the bouncing boss down; when it lands it takes its plain hit box and waits 64 frames. */
void dreamland_boss_bounce_in(uint16_t object)
{
	uint32_t landed = 0;
	uint16_t ignored16 = 0;
	uint8_t routine_step = 0;

	vector_apply_gravity(object, &ignored16, &landed);
	if (landed == 0u)
	{
		OBJECT(object)->flags = 0x98u;
		camera_x_held--;
		return;
	}
	leftover_y = dreamland_boss_body_box_ADDRESS;
	vector_set_hit_box(object);
	OBJECT(object)->timer = 0x40u;
	routine_step = OBJECT(object)->dreamland_boss.routine_step;
	OBJECT(object)->dreamland_boss.routine_step = routine_step + 1u;
	OBJECT(object)->flags = 0x98u;
	camera_x_held--;
}

/* Counts the wait down, then waits 128 frames more. */
void dreamland_boss_settle(uint16_t object)
{
	uint8_t timer = 0, routine_step = 0;

	OBJECT(object)->flags = 0x98u;
	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer == 1u)
	{
		OBJECT(object)->timer = 0x80u;
		routine_step = OBJECT(object)->dreamland_boss.routine_step;
		OBJECT(object)->dreamland_boss.routine_step = routine_step + 1u;
	}
	camera_x_held--;
}

/* Grows the boss to its full size; after the wait makes it hittable and sets direct page 7C. */
void dreamland_boss_grow(uint16_t object)
{
	uint8_t grown_zoom_x = 0, grown_zoom_y = 0;
	uint8_t timer = 0, routine_step = 0;
	uint16_t zoom_x = 0, grown_zoom = 0;
	uint32_t zoom_x_halfword = 0;

	zoom_x = (((uint32_t)OBJECT(object)->zoom_x << 8u) | OBJECT(object)->zoom_y);
	grown_zoom = zoom_x + 0x101u;
	grown_zoom_y = (uint8_t)grown_zoom;
	grown_zoom_x = (uint8_t)(grown_zoom >> 8);
	if ((uint16_t)(((uint32_t)grown_zoom_x << 8) | (grown_zoom_y & 0xFFu)) < 0x4040u)
	{
		zoom_x_halfword = ((uint32_t)grown_zoom_x << 8) | (grown_zoom_y & 0xFFu);
		OBJECT(object)->zoom_x = (uint8_t)(zoom_x_halfword >> 8u);
		OBJECT(object)->zoom_y = (uint8_t)zoom_x_halfword;
		OBJECT(object)->flags = 0x98u;
	}
	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer == 1u)
	{
		OBJECT(object)->flags = 0xC8u;
		OBJECT(object)->animation = 0x81u;
		boss_arrived = 1u;
		routine_step = OBJECT(object)->dreamland_boss.routine_step;
		OBJECT(object)->dreamland_boss.routine_step = routine_step + 1u;
	}
	camera_x_held--;
}

/* When that animation ends, plays animation 82 for 64 frames. */
void dreamland_boss_entrance_pose(uint16_t object)
{
	uint8_t animation_flags = 0, routine_step = 0;

	animation_flags = OBJECT(object)->animation_flags;
	if (animation_flags & 1u)
	{
		OBJECT(object)->animation = 0x82u;
		OBJECT(object)->timer = 0x40u;
		routine_step = OBJECT(object)->dreamland_boss.routine_step;
		OBJECT(object)->dreamland_boss.routine_step = routine_step + 1u;
	}
	camera_x_held--;
}

/* Counts down, then plays animation 83 for 128 frames. */
void dreamland_boss_entrance_pose_end(uint16_t object)
{
	uint8_t timer = 0, routine_step = 0;

	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer == 1u)
	{
		OBJECT(object)->animation = 0x83u;
		OBJECT(object)->timer = 0x80u;
		routine_step = OBJECT(object)->dreamland_boss.routine_step;
		OBJECT(object)->dreamland_boss.routine_step = routine_step + 1u;
	}
	camera_x_held--;
}

/* Counts down, then starts the boss's first form: it chases the players (step 3). */
void dreamland_boss_start_fight(uint16_t object)
{
	uint8_t timer = 0;

	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer == 1u)
	{
		OBJECT(object)->dreamland_boss.phase = 1u;
		OBJECT(object)->vitality = 0xFFu;
		OBJECT(object)->dreamland_boss.routine_step = 0u;
		OBJECT(object)->state = 3u;
		OBJECT(object)->dreamland_boss.resume_step = 3u;
	}
}

/* Turns the boss's flash on. */
void dreamland_boss_flash_on(uint16_t object)
{
	uint8_t attributes = 0;

	attributes = OBJECT(object)->attributes;
	OBJECT(object)->attributes = attributes | 0x80u;
	OBJECT(object)->animation_flags = 0x80u;
}

/* Turns the boss's flash off. */
void dreamland_boss_flash_off(uint16_t object)
{
	uint8_t attributes = 0;

	attributes = OBJECT(object)->attributes;
	OBJECT(object)->attributes = attributes & 0x7Fu;
	OBJECT(object)->animation_flags = 0x80u;
}

/* Turns the boss's flash over. */
void dreamland_boss_flash_toggle(uint16_t object)
{
	uint8_t attributes = 0;

	attributes = OBJECT(object)->attributes;
	OBJECT(object)->attributes = attributes ^ 0x80u;
	OBJECT(object)->animation_flags = 0x80u;
}

/* The boss's flinch when hit while it cannot be beaten, by field 29; it goes on with its routine (field
   45) meanwhile. */
void dreamland_boss_flinch(uint16_t object)
{
	uint8_t step = 0;
	uint8_t action_step = 0, resume_step = 0;

	action_step = OBJECT(object)->action_step;
	switch ((int8_t)(uint8_t)((uint32_t)action_step << 1))
	{
	case 0:
		dreamland_boss_flinch_start(object);
		break;
	case 2:
		dreamland_boss_flinch_end(object);
		break;
	case 4:
		dreamland_boss_chase_start(object);
		break;
	case 6:
		dreamland_boss_chase_leg(object);
		break;
	case 8:
		dreamland_boss_chase_run(object);
		break;
	case 10:
		dreamland_boss_chase_next_leg(object);
		break;
	case 12:
		dreamland_boss_chase_rest(object);
		break;
	case 14:
		dreamland_boss_chase_rest_end(object);
		break;
	case -16:
		dreamland_boss_appear(object);
		break;
	case -14:
		dreamland_boss_drop_in(object);
		break;
	case -12:
		dreamland_boss_bounce_in(object);
		break;
	case -10:
		dreamland_boss_settle(object);
		break;
	case -8:
		dreamland_boss_grow(object);
		break;
	case -6:
		dreamland_boss_entrance_pose(object);
		break;
	case -4:
		dreamland_boss_entrance_pose_end(object);
		break;
	case -2:
		dreamland_boss_start_fight(object);
		break;
	}
	resume_step = OBJECT(object)->dreamland_boss.resume_step;
	step = resume_step;
	dreamland_boss_run_step(object, step);
}

/* Flashes the boss for 8 frames with the hit sound. */
void dreamland_boss_flinch_start(uint16_t object)
{
	uint16_t command = 0;
	uint8_t action_step = 0;

	OBJECT(object)->flags = 0x88u;
	dreamland_boss_flash_on(object);
	command = 0x6600u;
	vector_queue_sound(command);
	OBJECT(object)->dreamland_boss.flash_time = 8u;
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
}

/* Counts the flash down, then the boss goes back to its routine (field 45). */
void dreamland_boss_flinch_end(uint16_t object)
{
	uint8_t flash_time = 0, resume_step = 0;

	flash_time = OBJECT(object)->dreamland_boss.flash_time;
	OBJECT(object)->dreamland_boss.flash_time = flash_time - 1u;
	if (flash_time != 1u)
		return;
	OBJECT(object)->flags = 0xC8u;
	leftover_y = dreamland_boss_body_box_ADDRESS;
	vector_set_hit_box(object);
	dreamland_boss_flash_off(object);
	resume_step = OBJECT(object)->dreamland_boss.resume_step;
	OBJECT(object)->state = resume_step;
}

/* The first form's chase, by field 52: legs at the nearest player, a rest, until it is in line with its
   player. */
void dreamland_boss_chase(uint16_t object)
{
	uint8_t routine_step = 0;

	routine_step = OBJECT(object)->dreamland_boss.routine_step;
	switch ((int8_t)(uint8_t)((uint32_t)routine_step << 1))
	{
	case 0:
		dreamland_boss_chase_start(object);
		return;
	case 2:
		dreamland_boss_chase_leg(object);
		return;
	case 4:
		dreamland_boss_chase_run(object);
		return;
	case 6:
		dreamland_boss_chase_next_leg(object);
		return;
	case 8:
		dreamland_boss_chase_rest(object);
		return;
	case 10:
		dreamland_boss_chase_rest_end(object);
		return;
	case -20:
		dreamland_boss_appear(object);
		return;
	case -18:
		dreamland_boss_drop_in(object);
		return;
	case -16:
		dreamland_boss_bounce_in(object);
		return;
	case -14:
		dreamland_boss_settle(object);
		return;
	case -12:
		dreamland_boss_grow(object);
		return;
	case -10:
		dreamland_boss_entrance_pose(object);
		return;
	case -8:
		dreamland_boss_entrance_pose_end(object);
		return;
	case -6:
		dreamland_boss_start_fight(object);
		return;
	case -4:
		dreamland_boss_flinch_start(object);
		return;
	case -2:
		dreamland_boss_flinch_end(object);
		return;
	}
}

/* Starts the chase with 8 legs. */
void dreamland_boss_chase_start(uint16_t object)
{
	uint8_t routine_step = 0;

	OBJECT(object)->flags = 0xC8u;
	dreamland_boss_flash_off(object);
	OBJECT(object)->animation = 0x86u;
	OBJECT(object)->dreamland_boss.legs_left = 8u;
	routine_step = OBJECT(object)->dreamland_boss.routine_step;
	OBJECT(object)->dreamland_boss.routine_step = routine_step + 1u;
	dreamland_boss_chase_leg(object);
}

/* Turns the boss toward the nearest player and runs it at him for the leg's time
   (object_1a_chase_leg_times); after 8 legs it charges. */
void dreamland_boss_chase_leg(uint16_t object)
{
	uint8_t angle = 0;
	uint16_t direction = 0, heading = 0, nearest_player = 0;
	uint8_t legs_left = 0, legs_left_2 = 0, routine_step = 0;
	uint16_t player_y = 0, boss_y = 0, dy = 0, depth_difference = 0, depth_distance = 0;

	nearest_player = vector_choose_nearest_player(object);
	player_y = OBJECT(nearest_player)->y;
	boss_y = OBJECT(object)->y;
	dy = player_y - boss_y;
	depth_difference = dy;
	depth_distance = depth_difference >> 15 ? 0u - depth_difference : depth_difference;
	if (depth_distance < 4u)
	{
		OBJECT(object)->x_speed = 0;
		OBJECT(object)->y_speed = 0;
		legs_left = OBJECT(object)->dreamland_boss.legs_left;
		OBJECT(object)->dreamland_boss.legs_left = legs_left - 1u;
		if (legs_left == 1u)
		{
			OBJECT(object)->dreamland_boss.routine_step = 4u;
			return;
		}
		legs_left_2 = OBJECT(object)->dreamland_boss.legs_left;
		OBJECT(object)->timer = object_1a_chase_leg_times[(int8_t)legs_left_2];
		routine_step = OBJECT(object)->dreamland_boss.routine_step;
		OBJECT(object)->dreamland_boss.routine_step = routine_step + 1u;
		return;
	}
	direction = vector_direction_to(object, nearest_player);
	angle = (uint8_t)(direction >> 8);
	heading = ((uint32_t)angle << 8) | 0x30u;
	vector_set_speed_by_direction(object, heading);
	legs_left = OBJECT(object)->dreamland_boss.legs_left;
	OBJECT(object)->dreamland_boss.legs_left = legs_left - 1u;
	if (legs_left == 1u)
	{
		OBJECT(object)->dreamland_boss.routine_step = 4u;
		return;
	}
	legs_left_2 = OBJECT(object)->dreamland_boss.legs_left;
	OBJECT(object)->timer = object_1a_chase_leg_times[(int8_t)legs_left_2];
	routine_step = OBJECT(object)->dreamland_boss.routine_step;
	OBJECT(object)->dreamland_boss.routine_step = routine_step + 1u;
}

/* Counts the leg's time down. */
void dreamland_boss_chase_run(uint16_t object)
{
	uint8_t timer = 0, routine_step = 0;

	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer == 1u)
	{
		routine_step = OBJECT(object)->dreamland_boss.routine_step;
		OBJECT(object)->dreamland_boss.routine_step = routine_step + 1u;
	}
}

/* Goes on to the next leg, unless in line with its player. */
void dreamland_boss_chase_next_leg(uint16_t object)
{
	OBJECT(object)->dreamland_boss.routine_step = 1u;
	dreamland_boss_check_in_line(object);
}

/* When its animation ends, stops the boss for 64 frames. */
void dreamland_boss_chase_rest(uint16_t object)
{
	uint8_t animation_flags = 0, routine_step = 0;

	animation_flags = OBJECT(object)->animation_flags;
	if (animation_flags & 1u)
	{
		OBJECT(object)->animation = 0x82u;
		OBJECT(object)->x_speed = 0;
		OBJECT(object)->y_speed = 0;
		OBJECT(object)->timer = 0x40u;
		routine_step = OBJECT(object)->dreamland_boss.routine_step;
		OBJECT(object)->dreamland_boss.routine_step = routine_step + 1u;
	}
	dreamland_boss_check_in_line(object);
}

/* Counts the rest down and starts the chase again. */
void dreamland_boss_chase_rest_end(uint16_t object)
{
	uint8_t timer = 0;

	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer != 1u)
	{
		dreamland_boss_check_in_line(object);
		return;
	}
	OBJECT(object)->dreamland_boss.routine_step = 0u;
	dreamland_boss_check_in_line(object);
}

/* When the boss is in line with its player (less than 4 apart in depth), sends it charging (step 4). */
void dreamland_boss_check_in_line(uint16_t object)
{
	uint16_t dy = 0, target_player = 0;
	uint16_t target = 0, player_y = 0, boss_y = 0;

	target = OBJECT(object)->target;
	target_player = target;
	player_y = OBJECT(target_player)->y;
	boss_y = OBJECT(object)->y;
	dy = player_y - boss_y;
	if ((uint16_t)(dy >> 15 ? 0u - dy : dy) < 4u)
	{
		OBJECT(object)->dreamland_boss.routine_step = 0u;
		OBJECT(object)->state = 4u;
		OBJECT(object)->dreamland_boss.resume_step = 4u;
	}
}

/* The first form's charge across the screen, by field 52. */
void dreamland_boss_charge(uint16_t object)
{
	uint8_t routine_step = 0;

	routine_step = OBJECT(object)->dreamland_boss.routine_step;
	switch ((int8_t)(uint8_t)((uint32_t)routine_step << 1))
	{
	case 0:
		dreamland_boss_charge_wind_up(object);
		return;
	case 2:
		dreamland_boss_charge_dash(object);
		return;
	case 4:
		dreamland_boss_charge_end(object);
		return;
	case 6:
		dreamland_boss_second_change_start(object);
		return;
	case 8:
		dreamland_boss_second_change_flash(object);
		return;
	case 10:
		dreamland_boss_second_form_start(object);
		return;
	}
}

/* Stops the boss for 64 frames before its charge. */
void dreamland_boss_charge_wind_up(uint16_t object)
{
	uint8_t routine_step = 0;

	OBJECT(object)->flags = 0xC8u;
	OBJECT(object)->animation = 0x86u;
	OBJECT(object)->x_speed = 0;
	OBJECT(object)->y_speed = 0;
	OBJECT(object)->timer = 0x40u;
	routine_step = OBJECT(object)->dreamland_boss.routine_step;
	OBJECT(object)->dreamland_boss.routine_step = routine_step + 1u;
}

/* Counts down, then dashes the boss across at its player with its attacking hit box for 48 frames. */
void dreamland_boss_charge_dash(uint16_t object)
{
	uint16_t target_player = 0;
	uint8_t timer = 0, routine_step = 0;
	uint16_t target = 0, player_x = 0, boss_x = 0, x_speed = 0;

	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer != 1u)
		return;
	OBJECT(object)->x_speed = 0x800;
	target = OBJECT(object)->target;
	target_player = target;
	player_x = OBJECT(target_player)->x;
	boss_x = OBJECT(object)->x;
	if (player_x < boss_x)
	{
		x_speed = OBJECT(object)->x_speed;
		OBJECT(object)->x_speed = 0u - x_speed;
	}
	leftover_y = dreamland_boss_attack_box_ADDRESS;
	vector_set_hit_box(object);
	OBJECT(object)->timer = 0x30u;
	routine_step = OBJECT(object)->dreamland_boss.routine_step;
	OBJECT(object)->dreamland_boss.routine_step = routine_step + 1u;
}

/* Counts the dash down, gives back the plain hit box and goes back to the chase. */
void dreamland_boss_charge_end(uint16_t object)
{
	uint8_t timer = 0;

	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer != 1u)
		return;
	leftover_y = dreamland_boss_body_box_ADDRESS;
	vector_set_hit_box(object);
	OBJECT(object)->state = 3u;
	OBJECT(object)->dreamland_boss.resume_step = 3u;
	OBJECT(object)->dreamland_boss.routine_step = 0u;
}

/* Turns the boss's speeds back once where it meets the stage's edges, across or in depth (fields 50 and
   51 keep that it did, cleared again while it is away from the edges). */
void dreamland_boss_bounce_off_edges(uint16_t object)
{
	uint32_t negative = 0;
	uint8_t floor_value = 0;
	uint16_t floor_cell = 0;
	uint8_t bounced_in_depth = 0, side_flip = 0, bounced_in_depth_2 = 0, bounced_across = 0, bounced_in_depth_3 = 0, side_flip_2 = 0, bounced_across_2 = 0;
	uint16_t y_speed = 0, x_speed = 0, y_speed_2 = 0, x_speed_2 = 0;

	vector_floor_ahead(object, &floor_cell, &negative);
	floor_value = (uint8_t)(floor_cell >> 8);
	if ((int8_t)floor_value >= 0)
	{
		OBJECT(object)->dreamland_boss.bounced_across = 0u;
		OBJECT(object)->dreamland_boss.bounced_in_depth = 0u;
		return;
	}
	bounced_in_depth = OBJECT(object)->dreamland_boss.bounced_in_depth;
	if (bounced_in_depth == 0u)
	{
		vector_floor_ahead_y(object, &floor_cell, &negative);
		floor_value = (uint8_t)(floor_cell >> 8);
		if ((int8_t)floor_value < 0)
		{
			side_flip = OBJECT(object)->dreamland_boss.side_flip;
			OBJECT(object)->dreamland_boss.side_flip = side_flip ^ 0x80u;
			bounced_in_depth_2 = OBJECT(object)->dreamland_boss.bounced_in_depth;
			OBJECT(object)->dreamland_boss.bounced_in_depth = bounced_in_depth_2 + 1u;
			y_speed = OBJECT(object)->y_speed;
			OBJECT(object)->y_speed = 0u - y_speed;
		}
	}
	bounced_across = OBJECT(object)->dreamland_boss.bounced_across;
	if (bounced_across != 0u)
		return;
	vector_floor_ahead_x(object, &floor_cell, &negative);
	floor_value = (uint8_t)(floor_cell >> 8);
	if ((int8_t)floor_value >= 0)
	{
		bounced_in_depth_3 = OBJECT(object)->dreamland_boss.bounced_in_depth;
		if (bounced_in_depth_3 == 0u)
		{
			x_speed = OBJECT(object)->x_speed;
			OBJECT(object)->x_speed = 0u - x_speed;
			y_speed_2 = OBJECT(object)->y_speed;
			OBJECT(object)->y_speed = 0u - y_speed_2;
		}
		return;
	}
	side_flip_2 = OBJECT(object)->dreamland_boss.side_flip;
	OBJECT(object)->dreamland_boss.side_flip = side_flip_2 ^ 0x80u;
	bounced_across_2 = OBJECT(object)->dreamland_boss.bounced_across;
	OBJECT(object)->dreamland_boss.bounced_across = bounced_across_2 + 1u;
	x_speed_2 = OBJECT(object)->x_speed;
	OBJECT(object)->x_speed = 0u - x_speed_2;
}

/* Pulls the boss down hard; returns true when it has landed on its floor. */
uint32_t dreamland_boss_fall(uint16_t object)
{
	uint32_t on_floor = 0;
	uint16_t z_speed = 0;
	uint16_t z_speed_2 = 0, floor_z = 0, z = 0, floor_z_2 = 0;

	z_speed_2 = OBJECT(object)->z_speed;
	z_speed = z_speed_2 - 0xC0u;
	OBJECT(object)->z_speed = z_speed;
	if ((int16_t)z_speed >= 0)
	{
		on_floor = 0u;
		return on_floor;
	}
	if (z_speed >> 8 < 0xF0u)
		OBJECT(object)->z_speed = (OBJECT(object)->z_speed & 0xFFu) | 0xF000u;
	floor_z = OBJECT(object)->floor_z;
	land_at_height = floor_z + 0x10u;
	z = OBJECT(object)->z;
	if (land_at_height < z)
	{
		on_floor = 0u;
		return on_floor;
	}
	OBJECT(object)->z_speed = 0;
	floor_z_2 = OBJECT(object)->floor_z;
	OBJECT(object)->z = floor_z_2;
	OBJECT(object)->animation_flags = 0x80u;
	on_floor = 1u;
	return on_floor;
}

/* The end of the first form (step 6), by field 4E: it changes into its second form. */
void dreamland_boss_change_to_second_form(uint16_t object)
{
	uint8_t change_step = 0;

	change_step = OBJECT(object)->dreamland_boss.change_step;
	switch ((int8_t)(uint8_t)((uint32_t)change_step << 1))
	{
	case 0:
		dreamland_boss_second_change_start(object);
		return;
	case 2:
		dreamland_boss_second_change_flash(object);
		return;
	case 4:
		dreamland_boss_second_form_start(object);
		return;
	case -6:
		dreamland_boss_charge_wind_up(object);
		return;
	case -4:
		dreamland_boss_charge_dash(object);
		return;
	case -2:
		dreamland_boss_charge_end(object);
		return;
	}
}

/* Stops the boss, unbeatable, for 128 frames. */
void dreamland_boss_second_change_start(uint16_t object)
{
	uint8_t change_step = 0;

	OBJECT(object)->flags = 0xC8u;
	OBJECT(object)->dreamland_boss.resume_step = 6u;
	OBJECT(object)->dreamland_boss.phase = 0u;
	OBJECT(object)->animation = 0x81u;
	OBJECT(object)->x_speed = 0;
	OBJECT(object)->y_speed = 0;
	OBJECT(object)->z_speed = 0;
	OBJECT(object)->timer = 0x80u;
	change_step = OBJECT(object)->dreamland_boss.change_step;
	OBJECT(object)->dreamland_boss.change_step = change_step + 1u;
}

/* Flashes the boss; after the wait it turns into kind BB with a sound and puts in its shadow (5280 type
   E3). */
void dreamland_boss_second_change_flash(uint16_t object)
{
	uint32_t carry = 0;
	uint16_t command = 0, ignored16 = 0, ignored16_2 = 0, ignored16_3 = 0;
	uint8_t timer = 0, change_step = 0;

	dreamland_boss_flash_toggle(object);
	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer != 1u)
		return;
	command = 0x2000u;
	vector_queue_sound(command);
	OBJECT(object)->kind = 0xBBu;
	OBJECT(object)->animation = 0x84u;
	leftover_y = dreamland_boss_second_change_flash_child_ADDRESS;
	vector_spawn_child(object, &ignored16, &ignored16_2, &ignored16_3, &carry);
	OBJECT(object)->flags = 0x80u;
	OBJECT(object)->timer = 0x40u;
	change_step = OBJECT(object)->dreamland_boss.change_step;
	OBJECT(object)->dreamland_boss.change_step = change_step + 1u;
}

/* Flashes the boss; after the wait starts its second form (phase 2, step 7). */
void dreamland_boss_second_form_start(uint16_t object)
{
	uint8_t timer = 0;

	dreamland_boss_flash_toggle(object);
	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer != 1u)
		return;
	dreamland_boss_flash_off(object);
	OBJECT(object)->dreamland_boss.phase = 2u;
	OBJECT(object)->vitality = 0xFFu;
	OBJECT(object)->flags = 0xC0u;
	leftover_y = dreamland_boss_body_box_ADDRESS;
	vector_set_hit_box(object);
	OBJECT(object)->state = 7u;
	OBJECT(object)->dreamland_boss.resume_step = 7u;
	OBJECT(object)->dreamland_boss.routine_step = 0u;
	OBJECT(object)->dreamland_boss.change_step = 0u;
	OBJECT(object)->dreamland_boss.keeps_acting = 0u;
}

/* The first form's hit reaction, by field 29; while it only flashes it goes on with its routine (field
   45). */
void dreamland_boss_first_form_hit(uint16_t object)
{
	uint8_t step = 0;
	uint8_t action_step = 0, keeps_acting = 0, resume_step = 0;

	action_step = OBJECT(object)->action_step;
	switch ((int8_t)(uint8_t)((uint32_t)action_step << 1))
	{
	case 0:
		dreamland_boss_first_form_hit_start(object);
		break;
	case 2:
		dreamland_boss_knocked_up(object);
		break;
	case 4:
		dreamland_boss_knocked_rise(object);
		break;
	case 6:
		dreamland_boss_knocked_fall(object);
		break;
	case 8:
		dreamland_boss_knocked_land(object);
		break;
	case 10:
		dreamland_boss_knocked_get_up(object);
		break;
	case -4:
		dreamland_boss_first_form_flash_end(object);
		break;
	case -2:
		dreamland_boss_first_form_flash_end_charge(object);
		break;
	}
	keeps_acting = OBJECT(object)->dreamland_boss.keeps_acting;
	if (keeps_acting == 0u)
		return;
	resume_step = OBJECT(object)->dreamland_boss.resume_step;
	step = resume_step;
	dreamland_boss_run_step(object, step);
}

/* Counts the flash down and goes on with the charge. */
void dreamland_boss_first_form_flash_end(uint16_t object)
{
	uint8_t flash_time = 0;

	flash_time = OBJECT(object)->dreamland_boss.flash_time;
	OBJECT(object)->dreamland_boss.flash_time = flash_time - 1u;
	if (flash_time != 1u)
		return;
	dreamland_boss_flash_off(object);
	OBJECT(object)->flags = 0xC8u;
	OBJECT(object)->state = 4u;
	OBJECT(object)->dreamland_boss.resume_step = 4u;
	OBJECT(object)->action_step = 0u;
}

/* Counts the flash down and starts the charge again. */
void dreamland_boss_first_form_flash_end_charge(uint16_t object)
{
	uint8_t flash_time = 0;

	flash_time = OBJECT(object)->dreamland_boss.flash_time;
	OBJECT(object)->dreamland_boss.flash_time = flash_time - 1u;
	if (flash_time != 1u)
		return;
	dreamland_boss_flash_off(object);
	OBJECT(object)->flags = 0xC8u;
	OBJECT(object)->state = 4u;
	OBJECT(object)->dreamland_boss.resume_step = 4u;
	OBJECT(object)->dreamland_boss.routine_step = 0u;
	OBJECT(object)->action_step = 0u;
}

/* Flashes the hit boss with the hit sound; every eighth hit knocks it high into the air away from its
   player. */
void dreamland_boss_first_form_hit_start(uint16_t object)
{
	uint16_t command = 0, target_player = 0;
	uint8_t hit_count = 0, hit_count_2 = 0, action_step = 0, resume_step = 0;
	uint16_t target = 0, player_x = 0, boss_x = 0, x_speed = 0;

	OBJECT(object)->flags = 0x88u;
	dreamland_boss_flash_on(object);
	command = 0x6600u;
	vector_queue_sound(command);
	hit_count = OBJECT(object)->dreamland_boss.hit_count;
	OBJECT(object)->dreamland_boss.hit_count = hit_count - 1u;
	hit_count_2 = OBJECT(object)->dreamland_boss.hit_count;
	if ((hit_count_2 & 7u) == 0u)
	{
		OBJECT(object)->dreamland_boss.keeps_acting = 0u;
		OBJECT(object)->animation = 0x85u;
		OBJECT(object)->x_speed = 0x100;
		OBJECT(object)->z_speed = 0xD00;
		target = OBJECT(object)->target;
		target_player = target;
		player_x = OBJECT(target_player)->x;
		boss_x = OBJECT(object)->x;
		if (player_x < boss_x)
		{
			x_speed = OBJECT(object)->x_speed;
			OBJECT(object)->x_speed = 0u - x_speed;
		}
		OBJECT(object)->timer = 0x20u;
		action_step = OBJECT(object)->action_step;
		OBJECT(object)->action_step = action_step + 1u;
		return;
	}
	OBJECT(object)->dreamland_boss.keeps_acting = 1u;
	OBJECT(object)->dreamland_boss.flash_time = 8u;
	resume_step = OBJECT(object)->dreamland_boss.resume_step;
	if (resume_step != 4u)
	{
		OBJECT(object)->action_step = 0xFFu;
		return;
	}
	OBJECT(object)->action_step = 0xFEu;
}

/* Turns the flash off for the knocked boss. */
void dreamland_boss_knocked_up(uint16_t object)
{
	uint8_t action_step = 0;

	dreamland_boss_flash_off(object);
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
	dreamland_boss_knocked_rise(object);
}

/* Pulls the knocked boss down; once it falls it takes its attacking hit box. */
void dreamland_boss_knocked_rise(uint16_t object)
{
	uint32_t landed = 0;
	uint16_t ignored16 = 0;
	uint8_t action_step = 0;
	uint16_t z_speed = 0;

	z_speed = OBJECT(object)->z_speed;
	if ((int16_t)z_speed < 0)
	{
		action_step = OBJECT(object)->action_step;
		OBJECT(object)->action_step = action_step + 1u;
		OBJECT(object)->flags = 0xCCu;
		leftover_y = dreamland_boss_attack_box_ADDRESS;
		vector_set_hit_box(object);
		return;
	}
	vector_apply_gravity(object, &ignored16, &landed);
	if (landed)
	{
		dreamland_boss_knocked_bounce(object);
		return;
	}
}

/* Pulls the knocked boss down hard; when it lands it bounces with a thud. */
void dreamland_boss_knocked_fall(uint16_t object)
{
	uint32_t on_floor = 0;

	on_floor = dreamland_boss_fall(object);
	if (on_floor == 0u)
		return;
	dreamland_boss_knocked_bounce(object);
}

/* Bounces the landed boss up again with the next of object_1a_bounce_animations and a thud. */
void dreamland_boss_knocked_bounce(uint16_t object)
{
	uint16_t command = 0;
	uint8_t retarget_time = 0, retarget_time_2 = 0;

	retarget_time = OBJECT(object)->retarget_time;
	OBJECT(object)->retarget_time = retarget_time - 1u;
	retarget_time_2 = OBJECT(object)->retarget_time;
	OBJECT(object)->animation = object_1a_bounce_animations[retarget_time_2 & 3u];
	OBJECT(object)->flags = 0x88u;
	OBJECT(object)->x_speed = 0;
	OBJECT(object)->y_speed = 0;
	OBJECT(object)->z_speed = 0x400;
	command = 0x6400u;
	vector_queue_sound(command);
	OBJECT(object)->action_step = 4u;
	leftover_y = dreamland_boss_body_box_ADDRESS;
	vector_set_hit_box(object);
}

/* Pulls the boss down hard; when it lands, a thud and a 32 frames' wait. */
void dreamland_boss_knocked_land(uint16_t object)
{
	uint32_t on_floor = 0;
	uint16_t command = 0;
	uint8_t action_step = 0;

	on_floor = dreamland_boss_fall(object);
	if (on_floor == 0u)
		return;
	OBJECT(object)->flags = 0x88u;
	OBJECT(object)->timer = 0x20u;
	command = 0x6400u;
	vector_queue_sound(command);
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
}

/* Counts the wait down and sends the boss back to its chase. */
void dreamland_boss_knocked_get_up(uint16_t object)
{
	uint8_t timer = 0;

	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer == 1u)
	{
		OBJECT(object)->flags = 0xC8u;
		OBJECT(object)->state = 3u;
		OBJECT(object)->dreamland_boss.resume_step = 3u;
		OBJECT(object)->action_step = 0u;
		OBJECT(object)->dreamland_boss.routine_step = 0u;
	}
}

/* The second form's round of poses, by field 52, measuring its player and turning back at the edges. */
void dreamland_boss_pose_round(uint16_t object)
{
	uint16_t target = 0;
	uint8_t routine_step = 0;
	uint16_t target_2 = 0;

	routine_step = OBJECT(object)->dreamland_boss.routine_step;
	switch ((int8_t)(uint8_t)((uint32_t)routine_step << 1))
	{
	case 0:
		dreamland_boss_next_pose(object);
		break;
	case 2:
		dreamland_boss_hold_pose(object);
		break;
	}
	target_2 = OBJECT(object)->target;
	target = target_2;
	vector_measure_target(object, target);
	dreamland_boss_bounce_off_edges(object);
}

/* Takes the next pose of the round (object_1a_pose_times, object_1a_pose_animations); FF ends the round. */
void dreamland_boss_next_pose(uint16_t object)
{
	uint8_t timer = 0;
	uint8_t hit_count = 0, hit_count_2 = 0, keeps_acting = 0, retarget_time = 0, retarget_time_2 = 0, pose_time = 0, retarget_time_3 = 0, routine_step = 0;

	OBJECT(object)->flags = 0xC0u;
	leftover_y = dreamland_boss_body_box_ADDRESS;
	vector_set_hit_box(object);
	dreamland_boss_flash_off(object);
	OBJECT(object)->dreamland_boss.keeps_acting = 0u;
	hit_count = OBJECT(object)->dreamland_boss.hit_count;
	OBJECT(object)->dreamland_boss.hit_count = hit_count - 1u;
	hit_count_2 = OBJECT(object)->dreamland_boss.hit_count;
	if ((hit_count_2 & 3u) != 0u)
	{
		keeps_acting = OBJECT(object)->dreamland_boss.keeps_acting;
		OBJECT(object)->dreamland_boss.keeps_acting = keeps_acting + 1u;
	}
	retarget_time = OBJECT(object)->retarget_time;
	OBJECT(object)->retarget_time = retarget_time - 1u;
	retarget_time_2 = OBJECT(object)->retarget_time;
	pose_time = object_1a_pose_times[retarget_time_2 & 7u];
	timer = pose_time;
	if ((int8_t)pose_time < 0)
	{
		dreamland_boss_end_poses(object);
		return;
	}
	OBJECT(object)->timer = timer;
	retarget_time_3 = OBJECT(object)->retarget_time;
	OBJECT(object)->animation = object_1a_pose_animations[retarget_time_3 & 7u];
	routine_step = OBJECT(object)->dreamland_boss.routine_step;
	OBJECT(object)->dreamland_boss.routine_step = routine_step + 1u;
}

/* Holds the pose for its time. */
void dreamland_boss_hold_pose(uint16_t object)
{
	uint8_t timer = 0;

	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer != 1u)
	{
		vector_face_direction(object);
		return;
	}
	dreamland_boss_end_poses(object);
}

/* Ends the round of poses and sends the boss leaping (step 8), facing its player. */
void dreamland_boss_end_poses(uint16_t object)
{
	OBJECT(object)->dreamland_boss.routine_step = 0u;
	OBJECT(object)->state = 8u;
	OBJECT(object)->dreamland_boss.resume_step = 8u;
	dreamland_boss_flash_off(object);
	OBJECT(object)->flags = 0xC0u;
	leftover_y = dreamland_boss_body_box_ADDRESS;
	vector_set_hit_box(object);
	vector_face_direction(object);
}

/* The second form's leap at its player, by field 52. */
void dreamland_boss_leap(uint16_t object)
{
	uint8_t routine_step = 0;

	routine_step = OBJECT(object)->dreamland_boss.routine_step;
	switch ((int8_t)(uint8_t)((uint32_t)routine_step << 1))
	{
	case 0:
		dreamland_boss_leap_crouch(object);
		break;
	case 2:
		dreamland_boss_leap_take_off(object);
		break;
	case 4:
		dreamland_boss_leap_rise(object);
		break;
	case 6:
		dreamland_boss_leap_fall(object);
		break;
	case 8:
		dreamland_boss_leap_rebound(object);
		break;
	case 10:
		dreamland_boss_leap_land(object);
		break;
	}
	dreamland_boss_bounce_off_edges(object);
}

/* Crouches the boss, turned to the nearest player. */
void dreamland_boss_leap_crouch(uint16_t object)
{
	uint16_t nearest_player = 0;
	uint8_t routine_step = 0;

	OBJECT(object)->flags = 0xC0u;
	dreamland_boss_flash_off(object);
	leftover_y = dreamland_boss_body_box_ADDRESS;
	vector_set_hit_box(object);
	OBJECT(object)->dreamland_boss.keeps_acting = 1u;
	OBJECT(object)->x_speed = 0;
	OBJECT(object)->y_speed = 0;
	nearest_player = vector_choose_nearest_player(object);
	vector_measure_target(object, nearest_player);
	OBJECT(object)->animation = 0x8Bu;
	routine_step = OBJECT(object)->dreamland_boss.routine_step;
	OBJECT(object)->dreamland_boss.routine_step = routine_step + 1u;
	vector_face_direction(object);
}

/* When the crouch ends, leaps the boss at its player, as far and high as its distance asks, with a
   sound. */
void dreamland_boss_leap_take_off(uint16_t object)
{
	uint8_t angle = 0;
	uint16_t command = 0, direction = 0, heading = 0, target_player = 0;
	uint8_t animation_flags = 0, leap_distance = 0, leap_distance_2 = 0, routine_step = 0;
	uint16_t target_dx = 0, target = 0;

	animation_flags = OBJECT(object)->animation_flags;
	if ((animation_flags & 1u) == 0u)
		return;
	command = 0x3800u;
	vector_queue_sound(command);
	target_dx = OBJECT(object)->target_dx;
	OBJECT(object)->dreamland_boss.leap_distance = (target_dx >> 4) & 0xFu;
	target = OBJECT(object)->target;
	target_player = target;
	direction = vector_direction_to(object, target_player);
	angle = (uint8_t)(direction >> 8);
	leap_distance = OBJECT(object)->dreamland_boss.leap_distance;
	heading = ((uint32_t)angle << 8) | object_1a_leap_speeds[(int8_t)leap_distance];
	vector_set_speed_by_direction(object, heading);
	leap_distance_2 = OBJECT(object)->dreamland_boss.leap_distance;
	OBJECT(object)->z_speed = (uint32_t)object_1a_leap_heights[(int8_t)leap_distance_2] << 8;
	OBJECT(object)->flags = 0x80u;
	routine_step = OBJECT(object)->dreamland_boss.routine_step;
	OBJECT(object)->dreamland_boss.routine_step = routine_step + 1u;
	vector_face_direction(object);
}

/* Pulls the leaping boss down; lands it if it comes down. */
void dreamland_boss_leap_rise(uint16_t object)
{
	uint32_t landed = 0;
	uint16_t ignored16 = 0;
	uint8_t routine_step = 0;
	uint16_t z_speed = 0;

	OBJECT(object)->flags = 0x80u;
	z_speed = OBJECT(object)->z_speed;
	if ((int16_t)z_speed < 0)
	{
		routine_step = OBJECT(object)->dreamland_boss.routine_step;
		OBJECT(object)->dreamland_boss.routine_step = routine_step + 1u;
	}
	vector_apply_gravity(object, &ignored16, &landed);
	if (landed)
	{
		dreamland_boss_leap_bounce(object);
		return;
	}
}

/* Pulls the falling boss down hard until it lands. */
void dreamland_boss_leap_fall(uint16_t object)
{
	uint32_t on_floor = 0;

	on_floor = dreamland_boss_fall(object);
	if (on_floor == 0u)
		return;
	dreamland_boss_leap_bounce(object);
}

/* The landed boss bounces up again with its attacking hit box and a thud. */
void dreamland_boss_leap_bounce(uint16_t object)
{
	uint16_t command = 0;

	OBJECT(object)->flags = 0xC4u;
	leftover_y = dreamland_boss_attack_box_ADDRESS;
	vector_set_hit_box(object);
	command = 0x6400u;
	vector_queue_sound(command);
	OBJECT(object)->animation = 0x84u;
	OBJECT(object)->z_speed = 0x400;
	OBJECT(object)->dreamland_boss.routine_step = 4u;
}

/* Makes the bouncing boss unhittable while it comes down. */
void dreamland_boss_leap_rebound(uint16_t object)
{
	uint8_t routine_step = 0;

	OBJECT(object)->flags = 0x80u;
	routine_step = OBJECT(object)->dreamland_boss.routine_step;
	OBJECT(object)->dreamland_boss.routine_step = routine_step + 1u;
	dreamland_boss_leap_land(object);
}

/* When the boss lands, stops it with its plain hit box and starts another round of poses. */
void dreamland_boss_leap_land(uint16_t object)
{
	uint32_t landed = 0;
	uint16_t ignored16 = 0;

	vector_apply_gravity(object, &ignored16, &landed);
	if (landed == 0u)
		return;
	OBJECT(object)->x_speed = 0;
	OBJECT(object)->y_speed = 0;
	OBJECT(object)->state = 7u;
	OBJECT(object)->dreamland_boss.resume_step = 7u;
	OBJECT(object)->dreamland_boss.routine_step = 0u;
	dreamland_boss_flash_off(object);
	OBJECT(object)->flags = 0xC0u;
	leftover_y = dreamland_boss_body_box_ADDRESS;
	vector_set_hit_box(object);
}

/* The second form's hit reaction, by field 29; while it only flashes it goes on with its routine (field
   45). */
void dreamland_boss_second_form_hit(uint16_t object)
{
	uint8_t step = 0;
	uint8_t action_step = 0, keeps_acting = 0, resume_step = 0;

	action_step = OBJECT(object)->action_step;
	switch ((int8_t)(uint8_t)((uint32_t)action_step << 1))
	{
	case 0:
		dreamland_boss_second_form_hit_start(object);
		break;
	case 2:
		dreamland_boss_second_form_reel(object);
		break;
	case 4:
		dreamland_boss_second_form_recover(object);
		break;
	case 6:
		dreamland_boss_third_change_start(object);
		break;
	case 8:
		dreamland_boss_third_change_land(object);
		break;
	case 10:
		dreamland_boss_third_change_flash(object);
		break;
	case 12:
		dreamland_boss_third_change_kind(object);
		break;
	case 14:
		dreamland_boss_third_form_start(object);
		break;
	case 16:
		dreamland_boss_third_form_walk_start(object);
		break;
	case 18:
		dreamland_boss_third_form_approach(object);
		break;
	case 20:
		dreamland_boss_third_form_close_in(object);
		break;
	case 22:
		dreamland_boss_spit_start(object);
		break;
	case 24:
		dreamland_boss_spit_ball(object);
		break;
	case 26:
		dreamland_boss_spit_end(object);
		break;
	case -2:
		dreamland_boss_second_form_flash_end(object);
		break;
	}
	keeps_acting = OBJECT(object)->dreamland_boss.keeps_acting;
	if (keeps_acting == 0u)
		return;
	resume_step = OBJECT(object)->dreamland_boss.resume_step;
	step = resume_step;
	dreamland_boss_run_step(object, step);
}

/* Counts the flash down and sends the boss back to its routine. */
void dreamland_boss_second_form_flash_end(uint16_t object)
{
	uint8_t flash_time = 0, resume_step = 0;

	flash_time = OBJECT(object)->dreamland_boss.flash_time;
	OBJECT(object)->dreamland_boss.flash_time = flash_time - 1u;
	if (flash_time != 1u)
		return;
	OBJECT(object)->flags = 0xC0u;
	leftover_y = dreamland_boss_body_box_ADDRESS;
	vector_set_hit_box(object);
	dreamland_boss_flash_off(object);
	resume_step = OBJECT(object)->dreamland_boss.resume_step;
	OBJECT(object)->state = resume_step;
}

/* Flashes the hit boss with the hit sound: while it acts (field 43) it only flashes, otherwise it reels. */
void dreamland_boss_second_form_hit_start(uint16_t object)
{
	uint16_t command = 0;
	uint8_t keeps_acting = 0, action_step = 0;

	OBJECT(object)->flags = 0x80u;
	dreamland_boss_flash_on(object);
	OBJECT(object)->x_speed = 0;
	OBJECT(object)->y_speed = 0;
	command = 0x6600u;
	vector_queue_sound(command);
	keeps_acting = OBJECT(object)->dreamland_boss.keeps_acting;
	if (keeps_acting == 0u)
	{
		OBJECT(object)->animation = 0x89u;
		action_step = OBJECT(object)->action_step;
		OBJECT(object)->action_step = action_step + 1u;
		return;
	}
	OBJECT(object)->dreamland_boss.flash_time = 8u;
	OBJECT(object)->action_step = 0xFFu;
}

/* Turns the reeling boss's flash off. */
void dreamland_boss_second_form_reel(uint16_t object)
{
	uint8_t action_step = 0;

	dreamland_boss_flash_off(object);
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
	dreamland_boss_second_form_recover(object);
}

/* When the reel ends, gives back the plain hit box and starts another round of poses. */
void dreamland_boss_second_form_recover(uint16_t object)
{
	uint8_t animation_flags = 0;

	animation_flags = OBJECT(object)->animation_flags;
	if ((animation_flags & 1u) == 0u)
		return;
	OBJECT(object)->flags = 0xC0u;
	leftover_y = dreamland_boss_body_box_ADDRESS;
	vector_set_hit_box(object);
	OBJECT(object)->state = 7u;
	OBJECT(object)->dreamland_boss.resume_step = 7u;
	OBJECT(object)->action_step = 0u;
	OBJECT(object)->dreamland_boss.routine_step = 0u;
}

/* The end of the second form (step 0A), by field 4E: it falls and changes into its third form. */
void dreamland_boss_change_to_third_form(uint16_t object)
{
	uint8_t change_step = 0;

	change_step = OBJECT(object)->dreamland_boss.change_step;
	switch ((int8_t)(uint8_t)((uint32_t)change_step << 1))
	{
	case 0:
		dreamland_boss_third_change_start(object);
		return;
	case 2:
		dreamland_boss_third_change_land(object);
		return;
	case 4:
		dreamland_boss_third_change_flash(object);
		return;
	case 6:
		dreamland_boss_third_change_kind(object);
		return;
	case 8:
		dreamland_boss_third_form_start(object);
		return;
	case 10:
		dreamland_boss_third_form_walk_start(object);
		return;
	case 12:
		dreamland_boss_third_form_approach(object);
		return;
	case 14:
		dreamland_boss_third_form_close_in(object);
		return;
	case 16:
		dreamland_boss_spit_start(object);
		return;
	case 18:
		dreamland_boss_spit_ball(object);
		return;
	case 20:
		dreamland_boss_spit_end(object);
		return;
	case -8:
		dreamland_boss_second_form_flash_end(object);
		return;
	case -6:
		dreamland_boss_second_form_hit_start(object);
		return;
	case -4:
		dreamland_boss_second_form_reel(object);
		return;
	case -2:
		dreamland_boss_second_form_recover(object);
		return;
	}
}

/* Makes the boss unbeatable with the hit sound. */
void dreamland_boss_third_change_start(uint16_t object)
{
	uint16_t command = 0;
	uint8_t change_step = 0;

	OBJECT(object)->flags = 0xC8u;
	OBJECT(object)->dreamland_boss.resume_step = 0xAu;
	OBJECT(object)->dreamland_boss.phase = 0u;
	command = 0x6600u;
	vector_queue_sound(command);
	change_step = OBJECT(object)->dreamland_boss.change_step;
	OBJECT(object)->dreamland_boss.change_step = change_step + 1u;
	dreamland_boss_third_change_land(object);
}

/* Pulls the boss down; when it lands, plays animation 85 for 128 frames. */
void dreamland_boss_third_change_land(uint16_t object)
{
	uint32_t landed = 0;
	uint16_t ignored16 = 0;
	uint8_t change_step = 0;

	vector_apply_gravity(object, &ignored16, &landed);
	if (landed)
	{
		OBJECT(object)->flags = 0xC8u;
		OBJECT(object)->animation = 0x85u;
		OBJECT(object)->x_speed = 0;
		OBJECT(object)->y_speed = 0;
		OBJECT(object)->z_speed = 0;
		OBJECT(object)->timer = 0x80u;
		change_step = OBJECT(object)->dreamland_boss.change_step;
		OBJECT(object)->dreamland_boss.change_step = change_step + 1u;
	}
}

/* Flashes the boss; after the wait it turns back into kind BA. */
void dreamland_boss_third_change_flash(uint16_t object)
{
	uint8_t timer = 0, change_step = 0;

	dreamland_boss_flash_toggle(object);
	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer == 1u)
	{
		OBJECT(object)->kind = 0xBAu;
		OBJECT(object)->animation = 0x81u;
		OBJECT(object)->timer = 0x40u;
		change_step = OBJECT(object)->dreamland_boss.change_step;
		OBJECT(object)->dreamland_boss.change_step = change_step + 1u;
	}
}

/* Flashes the boss; after the wait it turns into kind D0. */
void dreamland_boss_third_change_kind(uint16_t object)
{
	uint8_t timer = 0, change_step = 0;

	dreamland_boss_flash_toggle(object);
	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer == 1u)
	{
		OBJECT(object)->kind = 0xD0u;
		OBJECT(object)->animation = 0x85u;
		OBJECT(object)->timer = 0x40u;
		change_step = OBJECT(object)->dreamland_boss.change_step;
		OBJECT(object)->dreamland_boss.change_step = change_step + 1u;
	}
}

/* Flashes the boss; after the wait starts its third form (phase 3, step 0B). */
void dreamland_boss_third_form_start(uint16_t object)
{
	uint8_t timer = 0;

	dreamland_boss_flash_toggle(object);
	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer != 1u)
		return;
	dreamland_boss_flash_off(object);
	OBJECT(object)->dreamland_boss.phase = 3u;
	OBJECT(object)->vitality = 0xFFu;
	OBJECT(object)->flags = 0xC8u;
	leftover_y = dreamland_boss_body_box_ADDRESS;
	vector_set_hit_box(object);
	OBJECT(object)->state = 0xBu;
	OBJECT(object)->dreamland_boss.resume_step = 0xBu;
	OBJECT(object)->dreamland_boss.routine_step = 0u;
	OBJECT(object)->dreamland_boss.change_step = 0u;
	OBJECT(object)->dreamland_boss.keeps_acting = 0u;
}

/* When the boss's animation ends, sends it spitting (step 0C). */
void dreamland_boss_check_spit(uint16_t object)
{
	uint8_t animation_flags = 0;

	animation_flags = OBJECT(object)->animation_flags;
	if (animation_flags & 1u)
	{
		OBJECT(object)->state = 0xCu;
		OBJECT(object)->dreamland_boss.resume_step = 0xCu;
		OBJECT(object)->dreamland_boss.routine_step = 0u;
	}
}

/* The third form's walk at its player, by field 52, until it spits. */
void dreamland_boss_third_form_walk(uint16_t object)
{
	uint16_t target = 0;
	uint8_t routine_step = 0;
	uint16_t target_2 = 0;

	routine_step = OBJECT(object)->dreamland_boss.routine_step;
	switch ((int8_t)(uint8_t)((uint32_t)routine_step << 1))
	{
	case 0:
		dreamland_boss_third_form_walk_start(object);
		break;
	case 2:
		dreamland_boss_third_form_approach(object);
		break;
	case 4:
		dreamland_boss_third_form_close_in(object);
		break;
	case 6:
		dreamland_boss_spit_start(object);
		break;
	case 8:
		dreamland_boss_spit_ball(object);
		break;
	case 10:
		dreamland_boss_spit_end(object);
		break;
	case -18:
		dreamland_boss_second_form_flash_end(object);
		break;
	case -16:
		dreamland_boss_second_form_hit_start(object);
		break;
	case -14:
		dreamland_boss_second_form_reel(object);
		break;
	case -12:
		dreamland_boss_second_form_recover(object);
		break;
	case -10:
		dreamland_boss_third_change_start(object);
		break;
	case -8:
		dreamland_boss_third_change_land(object);
		break;
	case -6:
		dreamland_boss_third_change_flash(object);
		break;
	case -4:
		dreamland_boss_third_change_kind(object);
		break;
	case -2:
		dreamland_boss_third_form_start(object);
		break;
	}
	dreamland_boss_check_spit(object);
	target_2 = OBJECT(object)->target;
	target = target_2;
	vector_measure_target(object, target);
	dreamland_boss_bounce_off_edges(object);
}

/* Starts the walk at the nearest player. */
void dreamland_boss_third_form_walk_start(uint16_t object)
{
	uint8_t side_flip = 0, routine_step = 0;

	OBJECT(object)->flags = 0xC8u;
	dreamland_boss_flash_off(object);
	OBJECT(object)->dreamland_boss.keeps_acting = 1u;
	OBJECT(object)->animation = 0x86u;
	vector_choose_nearest_player(object);
	side_flip = OBJECT(object)->dreamland_boss.side_flip;
	OBJECT(object)->dreamland_boss.side_flip = side_flip ^ 0x80u;
	OBJECT(object)->timer = 0xFFu;
	routine_step = OBJECT(object)->dreamland_boss.routine_step;
	OBJECT(object)->dreamland_boss.routine_step = routine_step + 1u;
}

/* Walks the boss toward its player across or in depth until it is in line with him, picking the nearest
   player every 32 frames. */
void dreamland_boss_third_form_approach(uint16_t object)
{
	uint8_t side_flip = 0, target_direction = 0, side_flip_2 = 0, target_direction_2 = 0, routine_step = 0, timer = 0, timer_2 = 0, side_flip_3 = 0, timer_3 = 0;
	uint16_t target_dx = 0, x_speed = 0, y_speed = 0, target_dy = 0;

	target_dx = OBJECT(object)->target_dx;
	if (target_dx < 0x100u)
	{
		OBJECT(object)->y_speed = 0;
		OBJECT(object)->x_speed = 0x100;
		side_flip = OBJECT(object)->dreamland_boss.side_flip;
		if ((int8_t)side_flip < 0)
		{
			x_speed = OBJECT(object)->x_speed;
			OBJECT(object)->x_speed = 0u - x_speed;
		}
	}
	else
	{
		target_direction = OBJECT(object)->target_direction;
		side_flip_2 = OBJECT(object)->dreamland_boss.side_flip;
		if ((int8_t)(target_direction - 0x40u - side_flip_2) < 0)
		{
			OBJECT(object)->y_speed = 0;
			OBJECT(object)->x_speed = 0x100;
			side_flip = OBJECT(object)->dreamland_boss.side_flip;
			if ((int8_t)side_flip < 0)
			{
				x_speed = OBJECT(object)->x_speed;
				OBJECT(object)->x_speed = 0u - x_speed;
			}
		}
		else
		{
			OBJECT(object)->x_speed = 0;
			OBJECT(object)->y_speed = 0x100;
			target_direction_2 = OBJECT(object)->target_direction;
			if ((int8_t)target_direction_2 < 0)
			{
				y_speed = OBJECT(object)->y_speed;
				OBJECT(object)->y_speed = 0u - y_speed;
			}
		}
	}
	target_dy = OBJECT(object)->target_dy;
	if (target_dy < 3u)
	{
		routine_step = OBJECT(object)->dreamland_boss.routine_step;
		OBJECT(object)->dreamland_boss.routine_step = routine_step + 1u;
	}
	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	timer_2 = OBJECT(object)->timer;
	if (timer_2 == 0u)
	{
		side_flip_3 = OBJECT(object)->dreamland_boss.side_flip;
		OBJECT(object)->dreamland_boss.side_flip = side_flip_3 ^ 0x80u;
	}
	timer_3 = OBJECT(object)->timer;
	if ((timer_3 & 0x1Fu) == 0u)
		vector_choose_nearest_player(object);
	vector_face_direction(object);
}

/* Walks the boss across toward its player while it stays in line with him; out of line it goes back to
   approaching. */
void dreamland_boss_third_form_close_in(uint16_t object)
{
	uint8_t target_direction = 0, routine_step = 0, timer = 0, timer_2 = 0;
	uint16_t target_dx = 0, x_speed = 0, target_dy = 0;

	target_dx = OBJECT(object)->target_dx;
	if (target_dx >= 0xE0u)
	{
		OBJECT(object)->y_speed = 0;
		OBJECT(object)->x_speed = 0x100;
		target_direction = OBJECT(object)->target_direction;
		if ((int8_t)(target_direction - 0x40u) >= 0)
		{
			x_speed = OBJECT(object)->x_speed;
			OBJECT(object)->x_speed = 0u - x_speed;
		}
	}
	else
		OBJECT(object)->x_speed = 0;
	target_dy = OBJECT(object)->target_dy;
	if (target_dy >= 3u)
	{
		routine_step = OBJECT(object)->dreamland_boss.routine_step;
		OBJECT(object)->dreamland_boss.routine_step = routine_step - 1u;
	}
	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	timer_2 = OBJECT(object)->timer;
	if ((timer_2 & 0x1Fu) == 0u)
		vector_choose_nearest_player(object);
	vector_face_direction(object);
}

/* The third form's spit, by field 52. */
void dreamland_boss_spit(uint16_t object)
{
	uint8_t routine_step = 0;

	routine_step = OBJECT(object)->dreamland_boss.routine_step;
	switch ((int8_t)(uint8_t)((uint32_t)routine_step << 1))
	{
	case 0:
		dreamland_boss_spit_start(object);
		break;
	case 2:
		dreamland_boss_spit_ball(object);
		break;
	case 4:
		dreamland_boss_spit_end(object);
		break;
	case -24:
		dreamland_boss_second_form_flash_end(object);
		break;
	case -22:
		dreamland_boss_second_form_hit_start(object);
		break;
	case -20:
		dreamland_boss_second_form_reel(object);
		break;
	case -18:
		dreamland_boss_second_form_recover(object);
		break;
	case -16:
		dreamland_boss_third_change_start(object);
		break;
	case -14:
		dreamland_boss_third_change_land(object);
		break;
	case -12:
		dreamland_boss_third_change_flash(object);
		break;
	case -10:
		dreamland_boss_third_change_kind(object);
		break;
	case -8:
		dreamland_boss_third_form_start(object);
		break;
	case -6:
		dreamland_boss_third_form_walk_start(object);
		break;
	case -4:
		dreamland_boss_third_form_approach(object);
		break;
	case -2:
		dreamland_boss_third_form_close_in(object);
		break;
	}
	dreamland_boss_bounce_off_edges(object);
}

/* Stops the boss and starts its spit, turned to the nearest player. */
void dreamland_boss_spit_start(uint16_t object)
{
	uint16_t nearest_player = 0;
	uint8_t routine_step = 0;

	OBJECT(object)->flags = 0xC8u;
	dreamland_boss_flash_off(object);
	OBJECT(object)->x_speed = 0;
	OBJECT(object)->y_speed = 0;
	OBJECT(object)->dreamland_boss.keeps_acting = 1u;
	OBJECT(object)->animation = 0x87u;
	routine_step = OBJECT(object)->dreamland_boss.routine_step;
	OBJECT(object)->dreamland_boss.routine_step = routine_step + 1u;
	nearest_player = vector_choose_nearest_player(object);
	vector_measure_target(object, nearest_player);
	vector_face_direction(object);
}

/* On the marked frame, spits a ball (4D40 type 20). */
void dreamland_boss_spit_ball(uint16_t object)
{
	uint32_t child_placed = 0;
	uint16_t child_object = 0, ignored16 = 0;
	uint8_t animation_flags = 0, routine_step = 0;

	animation_flags = OBJECT(object)->animation_flags;
	if ((animation_flags & 2u) == 0u)
	{
		dreamland_boss_spit_end(object);
		return;
	}
	routine_step = OBJECT(object)->dreamland_boss.routine_step;
	OBJECT(object)->dreamland_boss.routine_step = routine_step + 1u;
	leftover_y = dreamland_boss_spit_ball_child_ADDRESS;
	child_object = dreamland_boss_spit_ball_child_ADDRESS;
	spawn_list_2_child(object, child_object, &ignored16, &child_placed);
}

/* When the spit ends, sends the boss walking again. */
void dreamland_boss_spit_end(uint16_t object)
{
	uint8_t animation_flags = 0, attributes = 0;

	animation_flags = OBJECT(object)->animation_flags;
	if (animation_flags & 1u)
	{
		OBJECT(object)->state = 0xBu;
		OBJECT(object)->dreamland_boss.resume_step = 0xBu;
		OBJECT(object)->dreamland_boss.routine_step = 0u;
		OBJECT(object)->flags = 0xC8u;
		attributes = OBJECT(object)->attributes;
		OBJECT(object)->attributes = attributes & 0x7Fu;
		OBJECT(object)->animation_flags = 0x80u;
	}
}

/* The third form's hit reaction, by field 29; while it only flashes it goes on with its routine (field
   45). */
void dreamland_boss_third_form_hit(uint16_t object)
{
	uint8_t step = 0;
	uint8_t action_step = 0, keeps_acting = 0, resume_step = 0;

	action_step = OBJECT(object)->action_step;
	switch ((int8_t)(uint8_t)((uint32_t)action_step << 1))
	{
	case 0:
		dreamland_boss_third_form_hit_start(object);
		break;
	case 2:
		dreamland_boss_third_form_reel(object);
		break;
	case 4:
		dreamland_boss_third_form_reel_on(object);
		break;
	case 6:
		dreamland_boss_third_form_reel_more(object);
		break;
	case 8:
		dreamland_boss_third_form_recover(object);
		break;
	case -4:
		dreamland_boss_third_form_flash_end(object);
		break;
	case -2:
		dreamland_boss_third_form_flash_end_spit(object);
		break;
	}
	keeps_acting = OBJECT(object)->dreamland_boss.keeps_acting;
	if (keeps_acting == 0u)
		return;
	resume_step = OBJECT(object)->dreamland_boss.resume_step;
	step = resume_step;
	dreamland_boss_run_step(object, step);
}

/* Counts the flash down and goes on with the spit. */
void dreamland_boss_third_form_flash_end(uint16_t object)
{
	uint8_t flash_time = 0;

	flash_time = OBJECT(object)->dreamland_boss.flash_time;
	OBJECT(object)->dreamland_boss.flash_time = flash_time - 1u;
	if (flash_time != 1u)
		return;
	dreamland_boss_flash_off(object);
	OBJECT(object)->flags = 0xC8u;
	OBJECT(object)->state = 0xCu;
	OBJECT(object)->dreamland_boss.resume_step = 0xCu;
	OBJECT(object)->action_step = 0u;
}

/* Counts the flash down and starts the spit again. */
void dreamland_boss_third_form_flash_end_spit(uint16_t object)
{
	uint8_t flash_time = 0;

	flash_time = OBJECT(object)->dreamland_boss.flash_time;
	OBJECT(object)->dreamland_boss.flash_time = flash_time - 1u;
	if (flash_time != 1u)
		return;
	dreamland_boss_flash_off(object);
	OBJECT(object)->flags = 0xC8u;
	OBJECT(object)->state = 0xCu;
	OBJECT(object)->dreamland_boss.resume_step = 0xCu;
	OBJECT(object)->dreamland_boss.routine_step = 0u;
	OBJECT(object)->action_step = 0u;
}

/* Flashes the hit boss with the hit sound; every eighth hit makes it reel. */
void dreamland_boss_third_form_hit_start(uint16_t object)
{
	uint16_t command = 0;
	uint8_t hit_count = 0, hit_count_2 = 0, action_step = 0, resume_step = 0;

	OBJECT(object)->flags = 0x88u;
	dreamland_boss_flash_on(object);
	OBJECT(object)->x_speed = 0;
	OBJECT(object)->y_speed = 0;
	command = 0x6600u;
	vector_queue_sound(command);
	hit_count = OBJECT(object)->dreamland_boss.hit_count;
	OBJECT(object)->dreamland_boss.hit_count = hit_count - 1u;
	hit_count_2 = OBJECT(object)->dreamland_boss.hit_count;
	if ((hit_count_2 & 7u) == 0u)
	{
		OBJECT(object)->dreamland_boss.keeps_acting = 0u;
		OBJECT(object)->animation = 0x83u;
		action_step = OBJECT(object)->action_step;
		OBJECT(object)->action_step = action_step + 1u;
		return;
	}
	OBJECT(object)->dreamland_boss.keeps_acting = 1u;
	OBJECT(object)->dreamland_boss.flash_time = 8u;
	resume_step = OBJECT(object)->dreamland_boss.resume_step;
	if (resume_step != 0xCu)
	{
		OBJECT(object)->action_step = 0xFFu;
		return;
	}
	OBJECT(object)->action_step = 0xFEu;
}

/* Turns the reeling boss's flash off. */
void dreamland_boss_third_form_reel(uint16_t object)
{
	uint8_t action_step = 0;

	dreamland_boss_flash_off(object);
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
	dreamland_boss_third_form_reel_on(object);
}

/* When that animation ends, plays animation 84. */
void dreamland_boss_third_form_reel_on(uint16_t object)
{
	uint8_t animation_flags = 0, action_step = 0;

	animation_flags = OBJECT(object)->animation_flags;
	if (animation_flags & 1u)
	{
		OBJECT(object)->animation = 0x84u;
		action_step = OBJECT(object)->action_step;
		OBJECT(object)->action_step = action_step + 1u;
	}
}

/* When that animation ends, plays the next of object_1a_repeat_animations. */
void dreamland_boss_third_form_reel_more(uint16_t object)
{
	uint8_t animation_flags = 0, retarget_time = 0, retarget_time_2 = 0, action_step = 0;

	animation_flags = OBJECT(object)->animation_flags;
	if (animation_flags & 1u)
	{
		retarget_time = OBJECT(object)->retarget_time;
		OBJECT(object)->retarget_time = retarget_time - 1u;
		retarget_time_2 = OBJECT(object)->retarget_time;
		OBJECT(object)->animation = object_1a_repeat_animations[retarget_time_2 & 3u];
		action_step = OBJECT(object)->action_step;
		OBJECT(object)->action_step = action_step + 1u;
	}
}

/* When that animation ends, sends the boss walking again. */
void dreamland_boss_third_form_recover(uint16_t object)
{
	uint8_t animation_flags = 0;

	animation_flags = OBJECT(object)->animation_flags;
	if (animation_flags & 1u)
	{
		OBJECT(object)->animation = 0x86u;
		OBJECT(object)->flags = 0xC8u;
		OBJECT(object)->state = 0xBu;
		OBJECT(object)->dreamland_boss.resume_step = 0xBu;
		OBJECT(object)->action_step = 0u;
	}
}

/* The end of the third form (step 0E), by field 4E: it changes into its last form. */
void dreamland_boss_change_to_last_form(uint16_t object)
{
	uint8_t change_step = 0;

	change_step = OBJECT(object)->dreamland_boss.change_step;
	switch ((int8_t)(uint8_t)((uint32_t)change_step << 1))
	{
	case 0:
		dreamland_boss_last_change_start(object);
		return;
	case 2:
		dreamland_boss_last_change_pose(object);
		return;
	case 4:
		dreamland_boss_last_change_kind(object);
		return;
	case 6:
		dreamland_boss_last_form_start(object);
		return;
	case 8:
		dreamland_boss_wobble_start(object);
		return;
	case 10:
		dreamland_boss_stretch_tall(object);
		return;
	case 12:
		dreamland_boss_squash_short(object);
		return;
	case 14:
		dreamland_boss_stretch_wide(object);
		return;
	case 16:
		dreamland_boss_squash_narrow(object);
		return;
	case 18:
		dreamland_boss_wobble_wait(object);
		return;
	case 20:
		dreamland_boss_put_out_chain(object);
		return;
	case 22:
		dreamland_boss_last_form_fight(object);
		return;
	}
}

/* Stops the boss, unbeatable, for 128 frames. */
void dreamland_boss_last_change_start(uint16_t object)
{
	uint8_t change_step = 0;

	OBJECT(object)->flags = 0xC8u;
	OBJECT(object)->dreamland_boss.resume_step = 0xEu;
	OBJECT(object)->dreamland_boss.phase = 0u;
	OBJECT(object)->animation = 0x83u;
	OBJECT(object)->x_speed = 0;
	OBJECT(object)->y_speed = 0;
	OBJECT(object)->z_speed = 0;
	OBJECT(object)->timer = 0x80u;
	change_step = OBJECT(object)->dreamland_boss.change_step;
	OBJECT(object)->dreamland_boss.change_step = change_step + 1u;
}

/* Flashes the boss; after the wait plays animation 8A. */
void dreamland_boss_last_change_pose(uint16_t object)
{
	uint8_t timer = 0, change_step = 0;

	dreamland_boss_flash_toggle(object);
	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer == 1u)
	{
		OBJECT(object)->animation = 0x8Au;
		OBJECT(object)->timer = 0x40u;
		change_step = OBJECT(object)->dreamland_boss.change_step;
		OBJECT(object)->dreamland_boss.change_step = change_step + 1u;
	}
}

/* Flashes the boss; after the wait it turns back into kind BA. */
void dreamland_boss_last_change_kind(uint16_t object)
{
	uint8_t timer = 0, change_step = 0;

	dreamland_boss_flash_toggle(object);
	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer == 1u)
	{
		OBJECT(object)->kind = 0xBAu;
		OBJECT(object)->animation = 0x81u;
		OBJECT(object)->timer = 0x40u;
		change_step = OBJECT(object)->dreamland_boss.change_step;
		OBJECT(object)->dreamland_boss.change_step = change_step + 1u;
	}
}

/* Flashes the boss; after the wait it starts its wobble (step 0F), unbeatable. */
void dreamland_boss_last_form_start(uint16_t object)
{
	uint8_t timer = 0;

	dreamland_boss_flash_toggle(object);
	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer != 1u)
		return;
	dreamland_boss_flash_off(object);
	OBJECT(object)->animation = 0x82u;
	OBJECT(object)->dreamland_boss.phase = 0u;
	OBJECT(object)->vitality = 0xFFu;
	OBJECT(object)->flags = 0xC8u;
	OBJECT(object)->state = 0xFu;
	OBJECT(object)->dreamland_boss.resume_step = 0xFu;
	OBJECT(object)->dreamland_boss.routine_step = 0u;
	OBJECT(object)->dreamland_boss.change_step = 0u;
}

/* The boss's wobble before it puts out its chain, by field 52. */
void dreamland_boss_wobble(uint16_t object)
{
	uint8_t routine_step = 0;

	routine_step = OBJECT(object)->dreamland_boss.routine_step;
	switch ((int8_t)(uint8_t)((uint32_t)routine_step << 1))
	{
	case 0:
		dreamland_boss_wobble_start(object);
		return;
	case 2:
		dreamland_boss_stretch_tall(object);
		return;
	case 4:
		dreamland_boss_squash_short(object);
		return;
	case 6:
		dreamland_boss_stretch_wide(object);
		return;
	case 8:
		dreamland_boss_squash_narrow(object);
		return;
	case 10:
		dreamland_boss_wobble_wait(object);
		return;
	case 12:
		dreamland_boss_put_out_chain(object);
		return;
	case 14:
		dreamland_boss_last_form_fight(object);
		return;
	case -8:
		dreamland_boss_last_change_start(object);
		return;
	case -6:
		dreamland_boss_last_change_pose(object);
		return;
	case -4:
		dreamland_boss_last_change_kind(object);
		return;
	case -2:
		dreamland_boss_last_form_start(object);
		return;
	}
}

/* Starts the wobble at its plain size: 4 rounds of 4 squeezes. */
void dreamland_boss_wobble_start(uint16_t object)
{
	uint8_t routine_step = 0;

	OBJECT(object)->flags = 0xC8u;
	OBJECT(object)->zoom_x = 0x40u;
	OBJECT(object)->zoom_y = 0x40u;
	OBJECT(object)->timer = 2u;
	OBJECT(object)->dreamland_boss.legs_left = 4u;
	OBJECT(object)->retarget_time = 4u;
	routine_step = OBJECT(object)->dreamland_boss.routine_step;
	OBJECT(object)->dreamland_boss.routine_step = routine_step + 1u;
}

/* Stretches the boss taller for 2 frames. */
void dreamland_boss_stretch_tall(uint16_t object)
{
	uint8_t zoom_y = 0, legs_left = 0, timer = 0, routine_step = 0;

	OBJECT(object)->flags |= 0xD8u;
	zoom_y = OBJECT(object)->zoom_y;
	legs_left = OBJECT(object)->dreamland_boss.legs_left;
	OBJECT(object)->zoom_y = zoom_y + legs_left;
	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer == 1u)
	{
		OBJECT(object)->timer = 2u;
		routine_step = OBJECT(object)->dreamland_boss.routine_step;
		OBJECT(object)->dreamland_boss.routine_step = routine_step + 1u;
	}
}

/* Squashes the boss back down for 2 frames. */
void dreamland_boss_squash_short(uint16_t object)
{
	uint8_t zoom_y = 0, legs_left = 0, timer = 0, routine_step = 0;

	OBJECT(object)->flags |= 0xD8u;
	zoom_y = OBJECT(object)->zoom_y;
	legs_left = OBJECT(object)->dreamland_boss.legs_left;
	OBJECT(object)->zoom_y = zoom_y - legs_left;
	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer == 1u)
	{
		OBJECT(object)->timer = 2u;
		routine_step = OBJECT(object)->dreamland_boss.routine_step;
		OBJECT(object)->dreamland_boss.routine_step = routine_step + 1u;
	}
}

/* Stretches the boss wider for 2 frames. */
void dreamland_boss_stretch_wide(uint16_t object)
{
	uint8_t zoom_x = 0, legs_left = 0, timer = 0, routine_step = 0;

	OBJECT(object)->flags |= 0xD8u;
	zoom_x = OBJECT(object)->zoom_x;
	legs_left = OBJECT(object)->dreamland_boss.legs_left;
	OBJECT(object)->zoom_x = zoom_x + legs_left;
	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer == 1u)
	{
		OBJECT(object)->timer = 2u;
		routine_step = OBJECT(object)->dreamland_boss.routine_step;
		OBJECT(object)->dreamland_boss.routine_step = routine_step + 1u;
	}
}

/* Squashes the boss back narrower; after the squeezes and rounds, waits 128 frames. */
void dreamland_boss_squash_narrow(uint16_t object)
{
	uint8_t zoom_x = 0, legs_left = 0, timer = 0, legs_left_2 = 0, retarget_time = 0, routine_step = 0;

	OBJECT(object)->flags |= 0xD8u;
	zoom_x = OBJECT(object)->zoom_x;
	legs_left = OBJECT(object)->dreamland_boss.legs_left;
	OBJECT(object)->zoom_x = zoom_x - legs_left;
	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer != 1u)
		return;
	OBJECT(object)->timer = 2u;
	legs_left_2 = OBJECT(object)->dreamland_boss.legs_left;
	OBJECT(object)->dreamland_boss.legs_left = legs_left_2 - 1u;
	if (legs_left_2 != 1u)
	{
		OBJECT(object)->dreamland_boss.routine_step = 1u;
		return;
	}
	retarget_time = OBJECT(object)->retarget_time;
	OBJECT(object)->retarget_time = retarget_time - 1u;
	if (retarget_time == 1u)
	{
		OBJECT(object)->timer = 0x80u;
		routine_step = OBJECT(object)->dreamland_boss.routine_step;
		OBJECT(object)->dreamland_boss.routine_step = routine_step + 1u;
		return;
	}
	OBJECT(object)->dreamland_boss.legs_left = 4u;
	OBJECT(object)->dreamland_boss.routine_step = 1u;
}

/* Counts the wait down. */
void dreamland_boss_wobble_wait(uint16_t object)
{
	uint8_t timer = 0, routine_step = 0;

	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer == 1u)
	{
		routine_step = OBJECT(object)->dreamland_boss.routine_step;
		OBJECT(object)->dreamland_boss.routine_step = routine_step + 1u;
	}
}

/* Puts out the boss's chain of balls (4F80 type FF), held by the boss, and sets work RAM 185A. */
void dreamland_boss_put_out_chain(uint16_t object)
{
	uint32_t slot_found = 0;
	uint16_t ignored16 = 0, ignored16_2 = 0, object_2 = 0;
	uint8_t routine_step = 0;

	leftover_y = dreamland_boss_put_out_chain_child_ADDRESS;
	vector_spawn_child(object, &ignored16, &object_2, &ignored16_2, &slot_found);
	if (slot_found)
	{
		OBJECT(object_2)->target = object;
		OBJECT(object)->dreamland_boss.chain = object_2;
		io_write8(player_balloons_off, 1u);
		OBJECT(object)->timer = 0x80u;
		routine_step = OBJECT(object)->dreamland_boss.routine_step;
		OBJECT(object)->dreamland_boss.routine_step = routine_step + 1u;
	}
}

/* Counts down, then starts the last form (phase 4): it creeps at the players and lashes its chain. */
void dreamland_boss_last_form_fight(uint16_t object)
{
	uint8_t timer = 0;

	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer == 1u)
	{
		OBJECT(object)->vitality = 0xFFu;
		OBJECT(object)->dreamland_boss.phase = 4u;
		OBJECT(object)->state = 0x10u;
		OBJECT(object)->dreamland_boss.resume_step = 0x10u;
		OBJECT(object)->dreamland_boss.routine_step = 0u;
	}
}

/* The last form's creep at the players, by field 52. */
void dreamland_boss_creep(uint16_t object)
{
	uint8_t routine_step = 0;

	routine_step = OBJECT(object)->dreamland_boss.routine_step;
	switch ((int8_t)(uint8_t)((uint32_t)routine_step << 1))
	{
	case 0:
		dreamland_boss_creep_start(object);
		break;
	case 2:
		dreamland_boss_creep_end(object);
		break;
	}
}

/* Sends the boss slowly at the nearest player for the time object_1a_approach_times gives. */
void dreamland_boss_creep_start(uint16_t object)
{
	uint8_t angle = 0;
	uint16_t direction = 0, heading = 0, nearest_player = 0;
	uint8_t hit_count = 0, hit_count_2 = 0, routine_step = 0;

	OBJECT(object)->flags = 0xC8u;
	dreamland_boss_flash_off(object);
	nearest_player = vector_choose_nearest_player(object);
	direction = vector_direction_to(object, nearest_player);
	angle = (uint8_t)(direction >> 8);
	heading = ((uint32_t)angle << 8) | 0x20u;
	vector_set_speed_by_direction(object, heading);
	hit_count = OBJECT(object)->dreamland_boss.hit_count;
	OBJECT(object)->dreamland_boss.hit_count = hit_count - 1u;
	hit_count_2 = OBJECT(object)->dreamland_boss.hit_count;
	OBJECT(object)->timer = object_1a_approach_times[hit_count_2 & 0xFu];
	routine_step = OBJECT(object)->dreamland_boss.routine_step;
	OBJECT(object)->dreamland_boss.routine_step = routine_step + 1u;
}

/* Counts down, then stops the boss with a sound and sends it lashing (step 11). */
void dreamland_boss_creep_end(uint16_t object)
{
	uint16_t command = 0;
	uint8_t timer = 0;

	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer != 1u)
		return;
	command = 0x6700u;
	vector_queue_sound(command);
	OBJECT(object)->x_speed = 0;
	OBJECT(object)->y_speed = 0;
	OBJECT(object)->state = 0x11u;
	OBJECT(object)->dreamland_boss.resume_step = 0x11u;
	OBJECT(object)->dreamland_boss.routine_step = 0u;
}

/* The last form's lash, by field 52. */
void dreamland_boss_lash(uint16_t object)
{
	uint8_t step_offset = 0, step_offset_2 = 0;
	uint8_t routine_step = 0;

	routine_step = OBJECT(object)->dreamland_boss.routine_step;
	step_offset = (uint32_t)routine_step << 1;
	switch ((int8_t)step_offset)
	{
	case 0:
		dreamland_boss_lash_start(object);
		return;
	case 2:
		dreamland_boss_lash_end(object);
		return;
	case 4:
		dreamland_boss_defeat_start(object);
		return;
	case 6:
		dreamland_boss_defeat_reach_middle(object);
		return;
	case 8:
		dreamland_boss_defeat_pop_chain(object);
		return;
	case 10:
		dreamland_boss_defeat_burst(object);
		return;
	case 12:
		dreamland_boss_defeat_release(object);
		return;
	case 14:
		dreamland_boss_defeat_bounce(object);
		return;
	case 16:
		dreamland_boss_defeat_land(object);
		return;
	case 18:
		step_offset_2 = step_offset;
		dreamland_boss_defeat_vanish(object, step_offset_2);
		return;
	}
}

/* Sends the chain's head out (its step 2) and turns the boss to the nearest player for 128 frames. */
void dreamland_boss_lash_start(uint16_t object)
{
	uint16_t chain = 0, chain_head = 0, nearest_player = 0;
	uint8_t routine_step = 0;
	uint16_t chain_2 = 0, parent = 0;

	OBJECT(object)->flags = 0xC8u;
	chain_2 = OBJECT(object)->dreamland_boss.chain;
	chain = chain_2;
	parent = OBJECT(chain)->parent;
	chain_head = parent;
	OBJECT(chain_head)->state = 2u;
	nearest_player = vector_choose_nearest_player(object);
	vector_measure_target(object, nearest_player);
	vector_face_direction(object);
	OBJECT(object)->timer = 0x80u;
	routine_step = OBJECT(object)->dreamland_boss.routine_step;
	OBJECT(object)->dreamland_boss.routine_step = routine_step + 1u;
}

/* Counts down and sends the boss creeping again. */
void dreamland_boss_lash_end(uint16_t object)
{
	uint8_t timer = 0;

	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer == 1u)
	{
		OBJECT(object)->state = 0x10u;
		OBJECT(object)->dreamland_boss.resume_step = 0x10u;
		OBJECT(object)->dreamland_boss.routine_step = 0u;
	}
}

/* The beaten boss (step 13), by field 29: it pulls its chain back, bursts, lets out what it held and
   goes, which ends the stage. */
void dreamland_boss_defeat(uint16_t object)
{
	uint8_t step_offset = 0, step_offset_2 = 0;
	uint8_t action_step = 0;

	action_step = OBJECT(object)->action_step;
	step_offset = (uint32_t)action_step << 1;
	step_offset_2 = step_offset;
	switch ((int8_t)step_offset)
	{
	case 0:
		dreamland_boss_defeat_start(object);
		break;
	case 2:
		dreamland_boss_defeat_reach_middle(object);
		break;
	case 4:
		dreamland_boss_defeat_pop_chain(object);
		break;
	case 6:
		dreamland_boss_defeat_burst(object);
		break;
	case 8:
		dreamland_boss_defeat_release(object);
		break;
	case 10:
		dreamland_boss_defeat_bounce(object);
		break;
	case 12:
		dreamland_boss_defeat_land(object);
		break;
	case 14:
		dreamland_boss_defeat_vanish(object, step_offset_2);
		break;
	case -4:
		dreamland_boss_lash_start(object);
		break;
	case -2:
		dreamland_boss_lash_end(object);
		break;
	}
	camera_x_held--;
}

/* Pulls the chain's head back (its step 5), with a sound, and walks the boss to the middle of the
   screen. */
void dreamland_boss_defeat_start(uint16_t object)
{
	uint16_t chain = 0, chain_head = 0, command = 0;
	uint8_t action_step = 0;
	uint16_t chain_2 = 0, parent = 0, boss_x = 0, x_speed = 0;

	OBJECT(object)->flags = 0x88u;
	chain_2 = OBJECT(object)->dreamland_boss.chain;
	chain = chain_2;
	parent = OBJECT(chain)->parent;
	chain_head = parent;
	OBJECT(chain_head)->state = 5u;
	dreamland_boss_flash_off(object);
	command = 0xFD00u;
	vector_queue_sound(command);
	OBJECT(object)->x_speed = 0x100;
	boss_x = OBJECT(object)->x;
	if (boss_x >= 0xE0u)
	{
		x_speed = OBJECT(object)->x_speed;
		OBJECT(object)->x_speed = 0u - x_speed;
	}
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
}

/* When the boss reaches the middle, stops it with animation 81 for 64 frames. */
void dreamland_boss_defeat_reach_middle(uint16_t object)
{
	uint8_t action_step = 0;
	uint16_t boss_x = 0, middle_offset = 0;

	boss_x = OBJECT(object)->x;
	middle_offset = boss_x - 0xC0u;
	if (middle_offset < 0x40u)
	{
		OBJECT(object)->animation = 0x81u;
		OBJECT(object)->x_speed = 0;
		OBJECT(object)->y_speed = 0;
		OBJECT(object)->timer = 0x40u;
		action_step = OBJECT(object)->action_step;
		OBJECT(object)->action_step = action_step + 1u;
	}
}

/* Counts down, then bursts the chain from its head (its step FE) and waits 128 frames. */
void dreamland_boss_defeat_pop_chain(uint16_t object)
{
	uint16_t chain = 0, chain_head = 0;
	uint8_t timer = 0, action_step = 0;
	uint16_t chain_2 = 0, parent = 0;

	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer == 1u)
	{
		chain_2 = OBJECT(object)->dreamland_boss.chain;
		chain = chain_2;
		parent = OBJECT(chain)->parent;
		chain_head = parent;
		OBJECT(chain_head)->state = 0xFEu;
		OBJECT(object)->timer = 0x80u;
		action_step = OBJECT(object)->action_step;
		OBJECT(object)->action_step = action_step + 1u;
	}
}

/* Counts down, then bursts the boss (kind D1) with its sounds, for 128 frames. */
void dreamland_boss_defeat_burst(uint16_t object)
{
	uint16_t command = 0;
	uint8_t timer = 0, action_step = 0;

	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer != 1u)
		return;
	OBJECT(object)->x_speed = 0;
	OBJECT(object)->y_speed = 0;
	command = 0x9800u;
	vector_queue_sound(command);
	command = 0x7100u;
	vector_queue_sound(command);
	OBJECT(object)->z = 0x40u;
	OBJECT(object)->kind = 0xD1u;
	OBJECT(object)->animation = 0x88u;
	leftover_y = dreamland_boss_defeat_burst_box_ADDRESS;
	vector_set_hit_box(object);
	OBJECT(object)->flags = 0xC4u;
	OBJECT(object)->timer = 0x80u;
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
}

/* Lets out one of object_1a_released_objects (4D40 type 27) every 32 frames, then makes what is left of
   the boss jump. */
void dreamland_boss_defeat_release(uint16_t object)
{
	uint32_t carry = 0;
	uint8_t time_left = 0;
	uint16_t ignored16 = 0, ignored16_2 = 0, ignored16_3 = 0;
	uint8_t timer = 0, legs_left = 0, legs_left_2 = 0, timer_2 = 0, shadow_player = 0, attributes = 0, points = 0, action_step = 0;

	OBJECT(object)->flags = 0x80u;
	timer = OBJECT(object)->timer;
	time_left = timer;
	if (time_left >= 0x40u && (time_left & 0x1Fu) == 0u)
	{
		legs_left = OBJECT(object)->dreamland_boss.legs_left;
		OBJECT(object)->dreamland_boss.legs_left = legs_left - 1u;
		legs_left_2 = OBJECT(object)->dreamland_boss.legs_left;
		leftover_y = object_1a_released_objects[legs_left_2 & 3u];
		vector_spawn_child(object, &ignored16, &ignored16_2, &ignored16_3, &carry);
	}
	timer_2 = OBJECT(object)->timer;
	OBJECT(object)->timer = timer_2 - 1u;
	if (timer_2 == 1u)
	{
		OBJECT(object)->animation = 0x81u;
		OBJECT(object)->z_speed = 0x400;
		OBJECT(object)->flags = 0x88u;
		shadow_player = OBJECT(object)->shadow_player;
		OBJECT(object)->shadow_player = shadow_player & ~0xFu;
		attributes = OBJECT(object)->attributes;
		OBJECT(object)->attributes = attributes | 0x40u;
		points = OBJECT(object)->points;
		OBJECT(object)->points = points | 0x80u;
		OBJECT(object)->timer = 0x40u;
		action_step = OBJECT(object)->action_step;
		OBJECT(object)->action_step = action_step + 1u;
	}
}

/* When it lands, bounces it again with a thud. */
void dreamland_boss_defeat_bounce(uint16_t object)
{
	uint32_t landed = 0;
	uint16_t command = 0, ignored16 = 0;
	uint8_t action_step = 0;

	vector_apply_gravity(object, &ignored16, &landed);
	if (landed == 0u)
		return;
	command = 0x2000u;
	vector_queue_sound(command);
	OBJECT(object)->z_speed = 0x400;
	OBJECT(object)->flags = 0x88u;
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
}

/* When it lands again, a thud and a 128 frames' wait. */
void dreamland_boss_defeat_land(uint16_t object)
{
	uint32_t landed = 0;
	uint16_t command = 0, ignored16 = 0;
	uint8_t action_step = 0;

	vector_apply_gravity(object, &ignored16, &landed);
	if (landed == 0u)
		return;
	OBJECT(object)->flags = 0x88u;
	command = 0x2000u;
	vector_queue_sound(command);
	OBJECT(object)->timer = 0x80u;
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
}

/* Flickers what is left of the boss away and frees its slot: the stage is cleared (direct page 7D) and
   the step goes on (4804). */
void dreamland_boss_defeat_vanish(uint16_t object, uint8_t step_offset)
{
	uint16_t command = 0;
	uint8_t timer = 0, timer_2 = 0, timer_3 = 0;
	uint32_t step_subphase_halfword = 0;

	timer = OBJECT(object)->timer;
	if (timer < 0x40u)
		OBJECT(object)->flags ^= 0x84u;
	timer_2 = OBJECT(object)->timer;
	OBJECT(object)->timer = timer_2 - 1u;
	if (timer_2 == 1u)
	{
		OBJECT(object)->flags = 0u;
		boss_beaten = 1u;
		step_phase++;
		step_subphase_halfword = 0x100u | step_offset;
		step_subphase = (uint8_t)(step_subphase_halfword >> 8u);
		step_countdown = (uint8_t)step_subphase_halfword;
		return;
	}
	timer_3 = OBJECT(object)->timer;
	if (timer_3 == 0x40u)
	{
		command = 0x9600u;
		vector_queue_sound(command);
	}
}
