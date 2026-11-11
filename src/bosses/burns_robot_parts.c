/**
 *    Name:        bosses/burns_robot_parts.c
 *    Description: the robot's objects: the wall it breaks out of, the part it tosses, its debris, shots, bombs and held part, Mr. Burns and Maggie at the end
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    11-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the game's 053248 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

/* The robot's shape in stage 8's wall (4D40 type 21, kind CC): runs its step. */
uint16_t burns_breakout_run(uint16_t shape, uint8_t state)
{
	uint16_t states = 0;
	uint8_t state_2 = 0;

	states = burns_breakout_states_ADDRESS;
	state_2 = OBJECT(shape)->state;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		burns_breakout_start(shape);
		return states;
	case 2:
		return burns_breakout_wait(shape, states);
	case 4:
		return burns_breakout_break_wall(shape);
	case 6:
		return burns_breakout_end(shape);
	case 8:
		burns_tossed_part_launch(shape);
		return states;
	case 10:
		burns_tossed_part_fly(shape);
		return states;
	case 12:
	case 14:
	case 16:
		burns_debris_bounce(shape);
		return states;
	case 18:
		burns_debris_blink(shape);
		return states;
	case 20:
		rescued_maggie_wait();
		return states;
	case 22:
		return rescued_maggie_drop(shape);
	case 24:
		return rescued_maggie_fall(shape, states);
	case 26:
	case 28:
	case 30:
	case 32:
		rescued_maggie_bounce(shape);
		return states;
	case 34:
		rescued_maggie_stop(shape);
		return states;
	case 36:
	case 44:
		rescued_maggie_pose(shape);
		return states;
	case 38:
	case 46:
		rescued_maggie_pose_2(shape);
		return states;
	case 40:
	case 48:
		rescued_maggie_crawl(shape);
		return states;
	case 42:
		rescued_maggie_sound_then_stop(shape);
		return states;
	case 50:
		return rescued_maggie_crawl_to_burns(shape);
	case 52:
		rescued_maggie_finish(shape, state);
		return states;
	case 54:
		burns_bomb_fall(shape);
		return states;
	case 56:
		return burns_bomb_fuse(shape, states);
	case 58:
		return burns_bomb_blast(shape);
	case 60:
		burns_part_vanish(shape);
		return states;
	case 62:
		burns_shot_arm(shape);
		return states;
	case 64:
		burns_shot_fly(shape);
		return states;
	case 66:
		return mr_burns_appear(shape);
	case 68:
		return mr_burns_wait_for_blow(shape, states);
	case 70:
		mr_burns_beaten(shape, state);
		return states;
	case 72:
		return mr_burns_release_maggie(shape, states);
	case 74:
		mr_burns_see_maggie(shape);
		return states;
	case 76:
		mr_burns_done();
		return states;
	case -4:
		return check_floor_ahead(shape, states);
	}
	unreachable();
}

/* The part the robot tosses away before its fight (5280 type E4, kind CC animation 82): runs its step. */
uint16_t burns_tossed_part_run(uint16_t part, uint8_t state)
{
	uint16_t states = 0;
	uint8_t state_2 = 0;

	OBJECT(part)->flags |= 0x10u;
	states = burns_tossed_part_states_ADDRESS;
	state_2 = OBJECT(part)->state;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		burns_tossed_part_launch(part);
		return states;
	case 2:
		burns_tossed_part_fly(part);
		return states;
	case 4:
	case 6:
	case 8:
		burns_debris_bounce(part);
		return states;
	case 10:
		burns_debris_blink(part);
		return states;
	case 12:
		rescued_maggie_wait();
		return states;
	case 14:
		return rescued_maggie_drop(part);
	case 16:
		return rescued_maggie_fall(part, states);
	case 18:
	case 20:
	case 22:
	case 24:
		rescued_maggie_bounce(part);
		return states;
	case 26:
		rescued_maggie_stop(part);
		return states;
	case 28:
	case 36:
		rescued_maggie_pose(part);
		return states;
	case 30:
	case 38:
		rescued_maggie_pose_2(part);
		return states;
	case 32:
	case 40:
		rescued_maggie_crawl(part);
		return states;
	case 34:
		rescued_maggie_sound_then_stop(part);
		return states;
	case 42:
		return rescued_maggie_crawl_to_burns(part);
	case 44:
		rescued_maggie_finish(part, state);
		return states;
	case 46:
		burns_bomb_fall(part);
		return states;
	case 48:
		return burns_bomb_fuse(part, states);
	case 50:
		return burns_bomb_blast(part);
	case 52:
		burns_part_vanish(part);
		return states;
	case 54:
		burns_shot_arm(part);
		return states;
	case 56:
		burns_shot_fly(part);
		return states;
	case 58:
		return mr_burns_appear(part);
	case 60:
		return mr_burns_wait_for_blow(part, states);
	case 62:
		mr_burns_beaten(part, state);
		return states;
	case 64:
		return mr_burns_release_maggie(part, states);
	case 66:
		mr_burns_see_maggie(part);
		return states;
	case 68:
		mr_burns_done();
		return states;
	case -12:
		return check_floor_ahead(part, states);
	case -8:
		burns_breakout_start(part);
		return states;
	case -6:
		return burns_breakout_wait(part, states);
	case -4:
		return burns_breakout_break_wall(part);
	case -2:
		return burns_breakout_end(part);
	}
	unreachable();
}

/* A piece of the robot breaking off (5280 type E5): runs its step (bouncing, then blinking out). */
uint16_t burns_debris_run(uint16_t debris, uint8_t state)
{
	uint16_t states = 0;
	uint8_t state_2 = 0;

	states = burns_debris_steps_ADDRESS;
	state_2 = OBJECT(debris)->state;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
	case 2:
	case 4:
		burns_debris_bounce(debris);
		return states;
	case 6:
		burns_debris_blink(debris);
		return states;
	case 8:
		rescued_maggie_wait();
		return states;
	case 10:
		return rescued_maggie_drop(debris);
	case 12:
		return rescued_maggie_fall(debris, states);
	case 14:
	case 16:
	case 18:
	case 20:
		rescued_maggie_bounce(debris);
		return states;
	case 22:
		rescued_maggie_stop(debris);
		return states;
	case 24:
	case 32:
		rescued_maggie_pose(debris);
		return states;
	case 26:
	case 34:
		rescued_maggie_pose_2(debris);
		return states;
	case 28:
	case 36:
		rescued_maggie_crawl(debris);
		return states;
	case 30:
		rescued_maggie_sound_then_stop(debris);
		return states;
	case 38:
		return rescued_maggie_crawl_to_burns(debris);
	case 40:
		rescued_maggie_finish(debris, state);
		return states;
	case 42:
		burns_bomb_fall(debris);
		return states;
	case 44:
		return burns_bomb_fuse(debris, states);
	case 46:
		return burns_bomb_blast(debris);
	case 48:
		burns_part_vanish(debris);
		return states;
	case 50:
		burns_shot_arm(debris);
		return states;
	case 52:
		burns_shot_fly(debris);
		return states;
	case 54:
		return mr_burns_appear(debris);
	case 56:
		return mr_burns_wait_for_blow(debris, states);
	case 58:
		mr_burns_beaten(debris, state);
		return states;
	case 60:
		return mr_burns_release_maggie(debris, states);
	case 62:
		mr_burns_see_maggie(debris);
		return states;
	case 64:
		mr_burns_done();
		return states;
	case -16:
		return check_floor_ahead(debris, states);
	case -12:
		burns_breakout_start(debris);
		return states;
	case -10:
		return burns_breakout_wait(debris, states);
	case -8:
		return burns_breakout_break_wall(debris);
	case -6:
		return burns_breakout_end(debris);
	case -4:
		burns_tossed_part_launch(debris);
		return states;
	case -2:
		burns_tossed_part_fly(debris);
		return states;
	}
	unreachable();
}

/* The same for 5280 type E6. */
uint16_t burns_debris_run_e6(uint16_t debris, uint8_t state)
{
	uint16_t states = 0;
	uint8_t state_2 = 0;

	states = burns_debris_steps_ADDRESS;
	state_2 = OBJECT(debris)->state;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
	case 2:
	case 4:
		burns_debris_bounce(debris);
		return states;
	case 6:
		burns_debris_blink(debris);
		return states;
	case 8:
		rescued_maggie_wait();
		return states;
	case 10:
		return rescued_maggie_drop(debris);
	case 12:
		return rescued_maggie_fall(debris, states);
	case 14:
	case 16:
	case 18:
	case 20:
		rescued_maggie_bounce(debris);
		return states;
	case 22:
		rescued_maggie_stop(debris);
		return states;
	case 24:
	case 32:
		rescued_maggie_pose(debris);
		return states;
	case 26:
	case 34:
		rescued_maggie_pose_2(debris);
		return states;
	case 28:
	case 36:
		rescued_maggie_crawl(debris);
		return states;
	case 30:
		rescued_maggie_sound_then_stop(debris);
		return states;
	case 38:
		return rescued_maggie_crawl_to_burns(debris);
	case 40:
		rescued_maggie_finish(debris, state);
		return states;
	case 42:
		burns_bomb_fall(debris);
		return states;
	case 44:
		return burns_bomb_fuse(debris, states);
	case 46:
		return burns_bomb_blast(debris);
	case 48:
		burns_part_vanish(debris);
		return states;
	case 50:
		burns_shot_arm(debris);
		return states;
	case 52:
		burns_shot_fly(debris);
		return states;
	case 54:
		return mr_burns_appear(debris);
	case 56:
		return mr_burns_wait_for_blow(debris, states);
	case 58:
		mr_burns_beaten(debris, state);
		return states;
	case 60:
		return mr_burns_release_maggie(debris, states);
	case 62:
		mr_burns_see_maggie(debris);
		return states;
	case 64:
		mr_burns_done();
		return states;
	case -16:
		return check_floor_ahead(debris, states);
	case -12:
		burns_breakout_start(debris);
		return states;
	case -10:
		return burns_breakout_wait(debris, states);
	case -8:
		return burns_breakout_break_wall(debris);
	case -6:
		return burns_breakout_end(debris);
	case -4:
		burns_tossed_part_launch(debris);
		return states;
	case -2:
		burns_tossed_part_fly(debris);
		return states;
	}
	unreachable();
}

/* What falls from the beaten robot and turns into Maggie (5280 type E7): runs its step. */
uint16_t rescued_maggie_run(uint16_t maggie, uint8_t state)
{
	uint16_t states = 0;
	uint8_t state_2 = 0;

	states = rescued_maggie_states_ADDRESS;
	state_2 = OBJECT(maggie)->state;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		rescued_maggie_wait();
		return states;
	case 2:
		return rescued_maggie_drop(maggie);
	case 4:
		return rescued_maggie_fall(maggie, states);
	case 6:
	case 8:
	case 10:
	case 12:
		rescued_maggie_bounce(maggie);
		return states;
	case 14:
		rescued_maggie_stop(maggie);
		return states;
	case 16:
	case 24:
		rescued_maggie_pose(maggie);
		return states;
	case 18:
	case 26:
		rescued_maggie_pose_2(maggie);
		return states;
	case 20:
	case 28:
		rescued_maggie_crawl(maggie);
		return states;
	case 22:
		rescued_maggie_sound_then_stop(maggie);
		return states;
	case 30:
		return rescued_maggie_crawl_to_burns(maggie);
	case 32:
		rescued_maggie_finish(maggie, state);
		return states;
	case 34:
		burns_bomb_fall(maggie);
		return states;
	case 36:
		return burns_bomb_fuse(maggie, states);
	case 38:
		return burns_bomb_blast(maggie);
	case 40:
		burns_part_vanish(maggie);
		return states;
	case 42:
		burns_shot_arm(maggie);
		return states;
	case 44:
		burns_shot_fly(maggie);
		return states;
	case 46:
		return mr_burns_appear(maggie);
	case 48:
		return mr_burns_wait_for_blow(maggie, states);
	case 50:
		mr_burns_beaten(maggie, state);
		return states;
	case 52:
		return mr_burns_release_maggie(maggie, states);
	case 54:
		mr_burns_see_maggie(maggie);
		return states;
	case 56:
		mr_burns_done();
		return states;
	case -24:
		return check_floor_ahead(maggie, states);
	case -20:
		burns_breakout_start(maggie);
		return states;
	case -18:
		return burns_breakout_wait(maggie, states);
	case -16:
		return burns_breakout_break_wall(maggie);
	case -14:
		return burns_breakout_end(maggie);
	case -12:
		burns_tossed_part_launch(maggie);
		return states;
	case -10:
		burns_tossed_part_fly(maggie);
		return states;
	case -8:
	case -6:
	case -4:
		burns_debris_bounce(maggie);
		return states;
	case -2:
		burns_debris_blink(maggie);
		return states;
	}
	unreachable();
}

/* A bomb the robot throws (4D40 type 26): turned back by walls, runs its step. */
uint16_t burns_bomb_run(uint16_t bomb)
{
	uint32_t negative = 0;
	uint8_t cell = 0;
	uint16_t floor_cell = 0, states = 0;
	uint8_t state = 0;
	uint16_t x_speed = 0, y_speed = 0;

	vector_floor_ahead_x(bomb, &floor_cell, &negative);
	cell = (uint8_t)(floor_cell >> 8);
	if ((int8_t)cell < 0)
	{
		x_speed = OBJECT(bomb)->x_speed;
		OBJECT(bomb)->x_speed = 0u - x_speed;
	}
	vector_floor_ahead_y(bomb, &floor_cell, &negative);
	cell = (uint8_t)(floor_cell >> 8);
	if ((int8_t)cell < 0)
	{
		y_speed = OBJECT(bomb)->y_speed;
		OBJECT(bomb)->y_speed = 0u - y_speed;
	}
	states = burns_bomb_states_ADDRESS;
	state = OBJECT(bomb)->state;
	switch ((int8_t)(uint8_t)((uint32_t)state << 1))
	{
	case 0:
		burns_bomb_fall(bomb);
		return states;
	case 2:
		return burns_bomb_fuse(bomb, states);
	case 4:
		return burns_bomb_blast(bomb);
	case 6:
		burns_part_vanish(bomb);
		return states;
	case 8:
		burns_shot_arm(bomb);
		return states;
	case 10:
		burns_shot_fly(bomb);
		return states;
	case 12:
		return mr_burns_appear(bomb);
	case 14:
		return mr_burns_wait_for_blow(bomb, states);
	case 16:
		mr_burns_beaten(bomb, (uint8_t)floor_cell);
		return states;
	case 18:
		return mr_burns_release_maggie(bomb, states);
	case 20:
		mr_burns_see_maggie(bomb);
		return states;
	case 22:
		mr_burns_done();
		return states;
	case -58:
		return check_floor_ahead(bomb, states);
	case -54:
		burns_breakout_start(bomb);
		return states;
	case -52:
		return burns_breakout_wait(bomb, states);
	case -50:
		return burns_breakout_break_wall(bomb);
	case -48:
		return burns_breakout_end(bomb);
	case -46:
		burns_tossed_part_launch(bomb);
		return states;
	case -44:
		burns_tossed_part_fly(bomb);
		return states;
	case -42:
	case -40:
	case -38:
		burns_debris_bounce(bomb);
		return states;
	case -36:
		burns_debris_blink(bomb);
		return states;
	case -34:
		rescued_maggie_wait();
		return states;
	case -32:
		return rescued_maggie_drop(bomb);
	case -30:
		return rescued_maggie_fall(bomb, states);
	case -28:
	case -26:
	case -24:
	case -22:
		rescued_maggie_bounce(bomb);
		return states;
	case -20:
		rescued_maggie_stop(bomb);
		return states;
	case -18:
	case -10:
		rescued_maggie_pose(bomb);
		return states;
	case -16:
	case -8:
		rescued_maggie_pose_2(bomb);
		return states;
	case -14:
	case -6:
		rescued_maggie_crawl(bomb);
		return states;
	case -12:
		rescued_maggie_sound_then_stop(bomb);
		return states;
	case -4:
		return rescued_maggie_crawl_to_burns(bomb);
	case -2:
		rescued_maggie_finish(bomb, floor_cell);
		return states;
	}
	unreachable();
}

/* A shot the robot fires (4D40 type 25): runs its step and bursts on a wall. */
uint16_t burns_shot_run(uint16_t shot, uint8_t state)
{
	uint32_t negative = 0;
	uint8_t cell = 0;
	uint16_t floor_cell = 0, states = 0;
	uint8_t state_2 = 0;

	states = burns_shot_states_ADDRESS;
	state_2 = OBJECT(shot)->state;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		burns_shot_arm(shot);
		break;
	case 2:
		burns_shot_fly(shot);
		break;
	case 4:
		states = mr_burns_appear(shot);
		break;
	case 6:
		states = mr_burns_wait_for_blow(shot, states);
		break;
	case 8:
		mr_burns_beaten(shot, state);
		break;
	case 10:
		states = mr_burns_release_maggie(shot, states);
		break;
	case 12:
		mr_burns_see_maggie(shot);
		break;
	case 14:
		mr_burns_done();
		break;
	case -66:
		states = check_floor_ahead(shot, states);
		break;
	case -62:
		burns_breakout_start(shot);
		break;
	case -60:
		states = burns_breakout_wait(shot, states);
		break;
	case -58:
		states = burns_breakout_break_wall(shot);
		break;
	case -56:
		states = burns_breakout_end(shot);
		break;
	case -54:
		burns_tossed_part_launch(shot);
		break;
	case -52:
		burns_tossed_part_fly(shot);
		break;
	case -50:
	case -48:
	case -46:
		burns_debris_bounce(shot);
		break;
	case -44:
		burns_debris_blink(shot);
		break;
	case -42:
		rescued_maggie_wait();
		break;
	case -40:
		states = rescued_maggie_drop(shot);
		break;
	case -38:
		states = rescued_maggie_fall(shot, states);
		break;
	case -36:
	case -34:
	case -32:
	case -30:
		rescued_maggie_bounce(shot);
		break;
	case -28:
		rescued_maggie_stop(shot);
		break;
	case -26:
	case -18:
		rescued_maggie_pose(shot);
		break;
	case -24:
	case -16:
		rescued_maggie_pose_2(shot);
		break;
	case -22:
	case -14:
		rescued_maggie_crawl(shot);
		break;
	case -20:
		rescued_maggie_sound_then_stop(shot);
		break;
	case -12:
		states = rescued_maggie_crawl_to_burns(shot);
		break;
	case -10:
		rescued_maggie_finish(shot, state);
		break;
	case -8:
		burns_bomb_fall(shot);
		break;
	case -6:
		states = burns_bomb_fuse(shot, states);
		break;
	case -4:
		states = burns_bomb_blast(shot);
		break;
	case -2:
		burns_part_vanish(shot);
		break;
	}
	vector_floor_ahead(shot, &floor_cell, &negative);
	cell = (uint8_t)(floor_cell >> 8);
	if ((int8_t)cell < 0)
	{
		burns_shot_burst(shot);
		return states;
	}
	return states;
}

/* The part the robot holds out in front of it (4F80 type EA): kept 48 in front of the robot while it
   holds it, gone after. */
void burns_held_part_run(uint16_t part)
{
	uint8_t attributes = 0;
	uint16_t holder = 0;
	uint8_t holding_part = 0, attributes_2 = 0, animation_flags = 0;
	uint16_t robot = 0, holder_x = 0, part_x = 0, holder_y = 0, x_speed = 0, y_speed = 0;

	robot = OBJECT(part)->burns_held_part.robot;
	holder = robot;
	holding_part = OBJECT(holder)->burns_robot.holding_part;
	if (holding_part == 0u)
	{
		OBJECT(part)->flags = 0u;
		return;
	}
	held_part_dx = 0x30;
	attributes_2 = OBJECT(holder)->attributes;
	attributes = attributes_2 & 0x40u;
	OBJECT(part)->attributes = attributes;
	if (attributes != 0u)
		held_part_dx = 0u - held_part_dx;
	holder_x = OBJECT(holder)->x;
	part_x = holder_x + held_part_dx;
	OBJECT(part)->x = part_x;
	holder_y = OBJECT(holder)->y;
	OBJECT(part)->y = holder_y;
	x_speed = OBJECT(holder)->x_speed;
	OBJECT(part)->x_speed = x_speed;
	y_speed = OBJECT(holder)->y_speed;
	OBJECT(part)->y_speed = y_speed;
	animation_flags = OBJECT(part)->animation_flags;
	OBJECT(part)->animation_flags = animation_flags | 0x80u;
}

/* Mr. Burns out of his beaten robot (5280 type E2, kind D3): runs his step. */
uint16_t mr_burns_run(uint16_t burns, uint8_t state)
{
	uint16_t states = 0;
	uint8_t state_2 = 0;

	states = mr_burns_states_ADDRESS;
	state_2 = OBJECT(burns)->state;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		return mr_burns_appear(burns);
	case 2:
		return mr_burns_wait_for_blow(burns, states);
	case 4:
		mr_burns_beaten(burns, state);
		return states;
	case 6:
		return mr_burns_release_maggie(burns, states);
	case 8:
		mr_burns_see_maggie(burns);
		return states;
	case 10:
		mr_burns_done();
		return states;
	case -70:
		return check_floor_ahead(burns, states);
	case -66:
		burns_breakout_start(burns);
		return states;
	case -64:
		return burns_breakout_wait(burns, states);
	case -62:
		return burns_breakout_break_wall(burns);
	case -60:
		return burns_breakout_end(burns);
	case -58:
		burns_tossed_part_launch(burns);
		return states;
	case -56:
		burns_tossed_part_fly(burns);
		return states;
	case -54:
	case -52:
	case -50:
		burns_debris_bounce(burns);
		return states;
	case -48:
		burns_debris_blink(burns);
		return states;
	case -46:
		rescued_maggie_wait();
		return states;
	case -44:
		return rescued_maggie_drop(burns);
	case -42:
		return rescued_maggie_fall(burns, states);
	case -40:
	case -38:
	case -36:
	case -34:
		rescued_maggie_bounce(burns);
		return states;
	case -32:
		rescued_maggie_stop(burns);
		return states;
	case -30:
	case -22:
		rescued_maggie_pose(burns);
		return states;
	case -28:
	case -20:
		rescued_maggie_pose_2(burns);
		return states;
	case -26:
	case -18:
		rescued_maggie_crawl(burns);
		return states;
	case -24:
		rescued_maggie_sound_then_stop(burns);
		return states;
	case -16:
		return rescued_maggie_crawl_to_burns(burns);
	case -14:
		rescued_maggie_finish(burns, state);
		return states;
	case -12:
		burns_bomb_fall(burns);
		return states;
	case -10:
		return burns_bomb_fuse(burns, states);
	case -8:
		return burns_bomb_blast(burns);
	case -6:
		burns_part_vanish(burns);
		return states;
	case -4:
		burns_shot_arm(burns);
		return states;
	case -2:
		burns_shot_fly(burns);
		return states;
	}
	unreachable();
}

/* Shows the robot's shape in the wall (kind CC, animation 91). */
void burns_breakout_start(uint16_t shape)
{
	uint8_t state = 0;

	OBJECT(shape)->flags = 0x80u;
	OBJECT(shape)->kind = 0xCCu;
	OBJECT(shape)->animation = 0x91u;
	state = OBJECT(shape)->state;
	OBJECT(shape)->state = state + 1u;
}

/* Flickers between two animations until the story after the first boss is over, then puts in the
   breaking piece (kind 13). */
uint16_t burns_breakout_wait(uint16_t shape, uint16_t piece)
{
	uint32_t carry = 0;
	uint8_t frame = 0, list = 0;
	uint16_t part_code = 0;
	uint8_t state = 0, frame_now = 0;

	if (stage_cue != 0u)
	{
		list = 2u;
		vector_find_free_slot(list, &piece, &carry);
		part_code = 0x602u;
		burns_robot_place_part(shape, piece, part_code);
		OBJECT(piece)->flags = 0x80u;
		OBJECT(piece)->flags = 0x80u;
		OBJECT(piece)->kind = 0x13u;
		OBJECT(piece)->animation = 0x89u;
		OBJECT(shape)->burns_breakout.piece = piece;
		state = OBJECT(shape)->state;
		OBJECT(shape)->state = state + 1u;
		return piece;
	}
	frame_now = (uint8_t)frame_count;
	frame = frame_now;
	if (frame_now == 0u)
	{
		OBJECT(shape)->animation = 0x91u;
		return piece;
	}
	if (frame == 0x80u)
	{
		OBJECT(shape)->animation = 0x93u;
		return piece;
	}
	return piece;
}

/* At the piece's frame knocks a hole in the wall's tiles (16 rows of 32), hides the shape, sound 4F. */
uint16_t burns_breakout_break_wall(uint16_t shape)
{
	uint8_t fill = 0;
	uint16_t command = 0, piece = 0;
	uint16_t row_start = 0;
	uint8_t animation_flags = 0, tiles_left = 0, rows_left = 0, state = 0;
	uint16_t piece_2 = 0, piece_y = 0, raised_y = 0, tile_at = 0;

	piece_2 = OBJECT(shape)->burns_breakout.piece;
	piece = piece_2;
	animation_flags = OBJECT(piece)->animation_flags;
	if ((animation_flags & 2u) == 0u)
		return piece;
	piece_y = OBJECT(piece)->y;
	raised_y = piece_y - 0x10u;
	OBJECT(piece)->y = raised_y;
	piece = 0x30ACu;
	wall_rows_left = 0x10u;
	do
	{
		wall_tiles_left = 0x20u;
		fill = 0x10u;
		row_start = piece;
		do
		{
			mem_write8(piece - 0x2000u, 0u);
			tile_at = piece;
			piece = tile_at + 1u;
			mem_write8(tile_at, fill);
			tiles_left = wall_tiles_left;
			wall_tiles_left = tiles_left - 1u;
		} while (tiles_left != 1u);
		piece = row_start + 0x40u;
		rows_left = wall_rows_left;
		wall_rows_left = rows_left - 1u;
	} while (rows_left != 1u);
	OBJECT(shape)->flags = 4u;
	command = 0x4F00u;
	vector_queue_sound(command);
	state = OBJECT(shape)->state;
	OBJECT(shape)->state = state + 1u;
	return piece;
}

/* When the piece's animation ends, both are gone. */
uint16_t burns_breakout_end(uint16_t shape)
{
	uint16_t piece = 0;
	uint8_t animation_flags = 0, state = 0;
	uint16_t piece_2 = 0;

	piece_2 = OBJECT(shape)->burns_breakout.piece;
	piece = piece_2;
	animation_flags = OBJECT(piece)->animation_flags;
	if ((animation_flags & 1u) != 0u)
	{
		OBJECT(shape)->flags = 0u;
		OBJECT(piece)->flags = 0u;
		state = OBJECT(shape)->state;
		OBJECT(shape)->state = state + 1u;
	}
	return piece;
}

/* Sends the tossed part off left, up and back, for 128 frames. */
void burns_tossed_part_launch(uint16_t part)
{
	uint8_t state = 0;

	OBJECT(part)->x_speed = -0x100;
	OBJECT(part)->z_speed = 0x100;
	OBJECT(part)->y_speed = -0x40;
	OBJECT(part)->burns_tossed_part.flight_frames = 0x80u;
	state = OBJECT(part)->state;
	OBJECT(part)->state = state + 1u;
}

/* The tossed part flies off, shrinking every 4 frames, gone after 128. */
void burns_tossed_part_fly(uint16_t part)
{
	uint8_t flight_frames = 0, zoom_x = 0, zoom_y = 0;

	flight_frames = OBJECT(part)->burns_tossed_part.flight_frames;
	OBJECT(part)->burns_tossed_part.flight_frames = flight_frames - 1u;
	if (flight_frames == 1u)
	{
		OBJECT(part)->flags = 0u;
		return;
	}
	if ((frame_count & 3u) == 0u)
	{
		zoom_x = OBJECT(part)->zoom_x;
		OBJECT(part)->zoom_x = zoom_x - 1u;
		zoom_y = OBJECT(part)->zoom_y;
		OBJECT(part)->zoom_y = zoom_y - 1u;
	}
}

/* A piece's last bounces, blinking, gone after 64 frames. */
void burns_debris_blink(uint16_t debris)
{
	uint8_t flags = 0;
	uint8_t blink_frames = 0;

	blink_frames = OBJECT(debris)->burns_debris.blink_frames;
	OBJECT(debris)->burns_debris.blink_frames = blink_frames - 1u;
	if (blink_frames == 1u)
	{
		OBJECT(debris)->flags = 0u;
		return;
	}
	flags = OBJECT(debris)->flags | 0x80u;
	if ((frame_count & 1u) != 0u)
		flags &= 0x7Fu;
	OBJECT(debris)->flags = flags;
	burns_debris_bounce(debris);
}

/* A piece bouncing: turned back by walls, half its height speed back up at each landing; after 3 it
   starts blinking. */
void burns_debris_bounce(uint16_t debris)
{
	uint32_t no_floor = 0, landed = 0;
	uint16_t ignored16 = 0;
	uint8_t x_speed = 0, z_speed = 0, state = 0, state_2 = 0;

	vector_floor_ahead(debris, &ignored16, &no_floor);
	if (no_floor)
	{
		x_speed = (uint8_t)(OBJECT(debris)->x_speed >> 8u);
		OBJECT(debris)->x_speed = (OBJECT(debris)->x_speed & 0xFFu) | ((0u - x_speed & 0xFFu) << 8u);
	}
	landed = burns_part_fall(debris);
	if (landed)
	{
		z_speed = (uint8_t)(OBJECT(debris)->z_speed >> 8u);
		OBJECT(debris)->z_speed = (OBJECT(debris)->z_speed & 0xFFu) | (((int8_t)(0u - z_speed) >> 1 & 0xFFu) << 8u);
		state = OBJECT(debris)->state;
		if (state != 3u)
		{
			state_2 = OBJECT(debris)->state;
			OBJECT(debris)->state = state_2 + 1u;
			OBJECT(debris)->burns_debris.blink_frames = 0x40u;
		}
	}
}

/* Moves the object by its height speed with gravity: carry when it is at the floor (height 0). */
uint32_t burns_part_fall(uint16_t part)
{
	uint32_t below_floor = 0, carry = 0;
	uint8_t z_speed_high = 0, z_speed_low = 0;
	uint8_t z_speed_2 = 0, z = 0;
	uint16_t z_speed = 0, next_z_speed = 0, z_low_and_fraction = 0, z_speed_now = 0, new_z_low_and_fraction = 0, z_2 = 0;

	z_speed = OBJECT(part)->z_speed;
	next_z_speed = z_speed - 0x60u;
	z_speed_high = (uint8_t)(next_z_speed >> 8);
	z_speed_low = (uint8_t)next_z_speed;
	OBJECT(part)->z_speed = ((uint32_t)z_speed_high << 8) | z_speed_low;
	z_low_and_fraction = (((uint32_t)(OBJECT(part)->z & 0xFFu) << 8u) | OBJECT(part)->z_fraction);
	z_speed_now = ((uint32_t)z_speed_high << 8) | z_speed_low;
	new_z_low_and_fraction = z_speed_now + z_low_and_fraction;
	carry = (uint16_t)(z_speed_now + z_low_and_fraction) < z_speed_now;
	OBJECT(part)->z = (OBJECT(part)->z & 0xFF00u) | ((new_z_low_and_fraction >> 8u) & 0xFFu);
	OBJECT(part)->z_fraction = (uint8_t)new_z_low_and_fraction;
	z_speed_2 = (uint8_t)(OBJECT(part)->z_speed >> 8u);
	z = (uint8_t)(OBJECT(part)->z >> 8u);
	OBJECT(part)->z = (OBJECT(part)->z & 0xFFu) | ((((uint16_t)(int8_t)z_speed_2 >> 8) + z + carry & 0xFFu) << 8u);
	z_2 = OBJECT(part)->z;
	below_floor = z_2 >> 15;
	if (z_2 == 0u || below_floor)
	{
		OBJECT(part)->z = 0u;
		OBJECT(part)->z_fraction = 0u;
		carry = 1u;
		return carry;
	}
	carry = 0u;
	return carry;
}

/* Waits until Mr. Burns is out. */
void rescued_maggie_wait(void)
{
}

/* Appears beside Mr. Burns, high up (a piece of the robot, kind CC animation 82). */
uint16_t rescued_maggie_drop(uint16_t maggie)
{
	uint16_t mr_burns = 0;
	uint8_t state = 0;
	uint16_t burns = 0, burns_x = 0, burns_y = 0;

	burns = OBJECT(maggie)->rescued_maggie.burns;
	mr_burns = burns;
	OBJECT(maggie)->flags = 0x80u;
	burns_x = OBJECT(mr_burns)->x;
	OBJECT(maggie)->x = burns_x + 0x20u;
	burns_y = OBJECT(mr_burns)->y;
	OBJECT(maggie)->y = burns_y;
	OBJECT(maggie)->z = 0x100u;
	OBJECT(maggie)->kind = 0xCCu;
	OBJECT(maggie)->animation = 0x82u;
	state = OBJECT(maggie)->state;
	OBJECT(maggie)->state = state + 1u;
	return mr_burns;
}

/* Falls; near the floor tells Mr. Burns and bounces off right and back. */
uint16_t rescued_maggie_fall(uint16_t maggie, uint16_t mr_burns)
{
	uint32_t carry = 0;
	uint16_t bounce_speed = 0;
	uint8_t landed_count = 0, bounce_high = 0, state = 0;
	uint16_t z = 0, burns = 0, z_speed = 0;

	burns_part_fall(maggie);
	z = OBJECT(maggie)->z;
	if ((int16_t)z <= 0x10)
	{
		burns = OBJECT(maggie)->rescued_maggie.burns;
		mr_burns = burns;
		landed_count = OBJECT(mr_burns)->mr_burns.maggie_landed;
		OBJECT(mr_burns)->mr_burns.maggie_landed = landed_count + 1u;
		z_speed = OBJECT(maggie)->z_speed;
		bounce_speed = 0u - z_speed;
		bounce_high = bounce_speed >> 8;
		carry = bounce_high & 1u;
		bounce_speed = (bounce_speed & 0xFFu) | ((uint32_t)(uint8_t)((int8_t)bounce_high >> 1) << 8);
		OBJECT(maggie)->z_speed = (bounce_speed & ~0xFFu) | (uint8_t)(((uint8_t)bounce_speed >> 1) | (carry << 7));
		OBJECT(maggie)->x_speed = 0x300;
		OBJECT(maggie)->y_speed = -0x80;
		state = OBJECT(maggie)->state;
		OBJECT(maggie)->state = state + 1u;
	}
	return mr_burns;
}

/* Bounces, half as high each time. */
void rescued_maggie_bounce(uint16_t maggie)
{
	uint32_t carry = 0;
	uint16_t bounce_speed = 0;
	uint8_t bounce_high = 0, state = 0;
	uint16_t z_speed = 0;

	carry = burns_part_fall(maggie);
	if (carry)
	{
		z_speed = OBJECT(maggie)->z_speed;
		bounce_speed = 0u - z_speed;
		bounce_high = bounce_speed >> 8;
		carry = bounce_high & 1u;
		bounce_speed = (bounce_speed & 0xFFu) | ((uint32_t)(uint8_t)((int8_t)bounce_high >> 1) << 8);
		OBJECT(maggie)->z_speed = (bounce_speed & ~0xFFu) | (uint8_t)(((uint8_t)bounce_speed >> 1) | (carry << 7));
		state = OBJECT(maggie)->state;
		OBJECT(maggie)->state = state + 1u;
	}
}

/* Its sound, then stops (03B764). */
void rescued_maggie_sound_then_stop(uint16_t maggie)
{
	rescued_maggie_sound(0u);
	rescued_maggie_stop(maggie);
}

/* Stops as Maggie (kind 11, animation 88) with sound 48, for 32 frames. */
void rescued_maggie_stop(uint16_t maggie)
{
	uint16_t command = 0;
	uint8_t wait_frames = 0, wait_frames_2 = 0, state = 0;

	wait_frames = OBJECT(maggie)->rescued_maggie.wait_frames;
	if (wait_frames != 0u)
	{
		wait_frames_2 = OBJECT(maggie)->rescued_maggie.wait_frames;
		OBJECT(maggie)->rescued_maggie.wait_frames = wait_frames_2 - 1u;
		return;
	}
	command = 0x4800u;
	vector_queue_sound(command);
	OBJECT(maggie)->x_speed = 0;
	OBJECT(maggie)->y_speed = 0;
	OBJECT(maggie)->z_speed = 0;
	OBJECT(maggie)->kind = 0x11u;
	OBJECT(maggie)->animation = 0x88u;
	OBJECT(maggie)->rescued_maggie.wait_frames = 0x20u;
	state = OBJECT(maggie)->state;
	OBJECT(maggie)->state = state + 1u;
}

/* After 32 frames, animation 89 for 32 frames. */
void rescued_maggie_pose(uint16_t maggie)
{
	uint8_t wait_frames = 0, state = 0;

	wait_frames = OBJECT(maggie)->rescued_maggie.wait_frames;
	OBJECT(maggie)->rescued_maggie.wait_frames = wait_frames - 1u;
	if (wait_frames == 1u)
	{
		OBJECT(maggie)->animation = 0x89u;
		OBJECT(maggie)->rescued_maggie.wait_frames = 0x20u;
		state = OBJECT(maggie)->state;
		OBJECT(maggie)->state = state + 1u;
	}
}

/* After 32 frames, animation 87 for 64 frames. */
void rescued_maggie_pose_2(uint16_t maggie)
{
	uint8_t wait_frames = 0, state = 0;

	wait_frames = OBJECT(maggie)->rescued_maggie.wait_frames;
	OBJECT(maggie)->rescued_maggie.wait_frames = wait_frames - 1u;
	if (wait_frames == 1u)
	{
		OBJECT(maggie)->animation = 0x87u;
		OBJECT(maggie)->rescued_maggie.wait_frames = 0x40u;
		state = OBJECT(maggie)->state;
		OBJECT(maggie)->state = state + 1u;
	}
}

/* With its sound every 16 frames; after its wait crawls left (animation 81) for 40 frames. */
void rescued_maggie_crawl(uint16_t maggie)
{
	uint8_t wait_frames = 0, state = 0;

	rescued_maggie_sound(0u);
	wait_frames = OBJECT(maggie)->rescued_maggie.wait_frames;
	OBJECT(maggie)->rescued_maggie.wait_frames = wait_frames - 1u;
	if (wait_frames == 1u)
	{
		OBJECT(maggie)->animation = 0x81u;
		OBJECT(maggie)->x_speed = -0x80;
		OBJECT(maggie)->attributes = 0x40u;
		OBJECT(maggie)->rescued_maggie.wait_frames = 0x28u;
		state = OBJECT(maggie)->state;
		OBJECT(maggie)->state = state + 1u;
	}
}

/* Crawls on until within 96 of Mr. Burns, then stops (animation 86) for 128 frames. */
uint16_t rescued_maggie_crawl_to_burns(uint16_t maggie)
{
	uint16_t mr_burns = 0;
	uint8_t state = 0;
	uint16_t burns = 0, maggie_x = 0, burns_x = 0, difference_x = 0;

	rescued_maggie_sound(0u);
	burns = OBJECT(maggie)->rescued_maggie.burns;
	mr_burns = burns;
	maggie_x = OBJECT(maggie)->x;
	burns_x = OBJECT(mr_burns)->x;
	difference_x = maggie_x - burns_x;
	if ((int16_t)difference_x <= 0x60)
	{
		OBJECT(maggie)->animation = 0x86u;
		OBJECT(maggie)->x_speed = 0;
		OBJECT(maggie)->rescued_maggie.wait_frames = 0x80u;
		state = OBJECT(maggie)->state;
		OBJECT(maggie)->state = state + 1u;
	}
	return mr_burns;
}

/* After its 128 frames the step moves on (the game's end). */
void rescued_maggie_finish(uint16_t maggie, uint16_t d)
{
	uint8_t wait_frames = 0;

	d = rescued_maggie_sound(d);
	wait_frames = OBJECT(maggie)->rescued_maggie.wait_frames;
	OBJECT(maggie)->rescued_maggie.wait_frames = wait_frames - 1u;
	if (wait_frames == 1u)
	{
		step_phase++;
		step_subphase = (uint8_t)(d >> 8u);
		step_countdown = (uint8_t)d;
	}
}

/* Sound 45 every 16 frames. */
uint16_t rescued_maggie_sound(uint16_t d)
{
	uint8_t phase_then_sound = 0;
	uint16_t d_2 = 0;
	uint8_t frame_phase = 0;

	frame_phase = (uint8_t)frame_count & 0xFu;
	phase_then_sound = frame_phase;
	if (frame_phase == 0u)
	{
		d = 0x4500u;
		phase_then_sound = 0x45u;
		vector_queue_sound(d);
	}
	d_2 = (d & 0xFFu) | ((uint32_t)phase_then_sound << 8);
	return d_2;
}

/* A lobbed bomb falls; landing, sound 52 and its fuse (animation 87, 32 frames). */
void burns_bomb_fall(uint16_t bomb)
{
	uint32_t landed = 0;
	uint16_t command = 0, ignored16 = 0;
	uint8_t state = 0;

	vector_apply_gravity(bomb, &ignored16, &landed);
	if (landed == 0u)
		return;
	command = 0x5200u;
	vector_queue_sound(command);
	OBJECT(bomb)->animation = 0x87u;
	OBJECT(bomb)->burns_bomb.fuse = 0x20u;
	state = OBJECT(bomb)->state;
	OBJECT(bomb)->state = state + 1u;
}

/* Burns its fuse; touched or out of time it blows up: the screen shakes, sound 4C, a flash, its blast
   (animation 89). */
uint16_t burns_bomb_fuse(uint16_t bomb, uint16_t palette_job)
{
	uint16_t command = 0, request = 0;
	uint8_t state = 0, fuse = 0;

	if ((OBJECT(bomb)->flags & 0x20u) != 0u)
	{
		screen_shake_on = 1u;
		screen_shake_kind = 0u;
		command = 0x4C00u;
		vector_queue_sound(command);
		palette_request_kind = 6u;
		request = 0xE20u;
		palette_job = vector_palette_request(palette_job, request);
		OBJECT(bomb)->animation = 0x89u;
		OBJECT(bomb)->x_speed = 0;
		OBJECT(bomb)->y_speed = 0;
		state = OBJECT(bomb)->state;
		OBJECT(bomb)->state = state + 1u;
	}
	else
	{
		fuse = OBJECT(bomb)->burns_bomb.fuse;
		OBJECT(bomb)->burns_bomb.fuse = fuse - 1u;
		if (fuse == 1u)
		{
			screen_shake_on = 1u;
			screen_shake_kind = 0u;
			command = 0x4C00u;
			vector_queue_sound(command);
			palette_request_kind = 6u;
			request = 0xE20u;
			palette_job = vector_palette_request(palette_job, request);
			OBJECT(bomb)->animation = 0x89u;
			OBJECT(bomb)->x_speed = 0;
			OBJECT(bomb)->y_speed = 0;
			state = OBJECT(bomb)->state;
			OBJECT(bomb)->state = state + 1u;
			return palette_job;
		}
	}
	return palette_job;
}

/* The blast hits with box 0E at its frames; gone when it ends. */
uint16_t burns_bomb_blast(uint16_t bomb)
{
	uint8_t box = 0;
	uint16_t box_number = 0, u = 0;
	uint8_t animation_flags = 0, animation_flags_2 = 0;

	box = 0u;
	animation_flags = OBJECT(bomb)->animation_flags;
	if ((animation_flags & 2u) != 0u)
		box = 0xEu;
	box_number = (uint32_t)box << 8;
	u = burns_robot_set_box(bomb, box_number);
	animation_flags_2 = OBJECT(bomb)->animation_flags;
	if ((animation_flags_2 & 1u) != 0u)
		OBJECT(bomb)->flags = 0u;
	return u;
}

/* Gone when its animation ends (a shot's burst). */
void burns_part_vanish(uint16_t part)
{
	uint8_t animation_flags = 0;

	animation_flags = OBJECT(part)->animation_flags;
	if ((animation_flags & 1u) != 0u)
		OBJECT(part)->flags = 0u;
}

/* A shot becomes harmful after its first 16 frames. */
void burns_shot_arm(uint16_t shot)
{
	uint8_t arm_frames = 0, state = 0;

	arm_frames = OBJECT(shot)->burns_shot.arm_frames;
	OBJECT(shot)->burns_shot.arm_frames = arm_frames - 1u;
	if (arm_frames == 1u)
	{
		OBJECT(shot)->flags |= 0x40u;
		state = OBJECT(shot)->state;
		OBJECT(shot)->state = state + 1u;
	}
}

/* A shot flies on until it touches something. */
void burns_shot_fly(uint16_t shot)
{
	if ((OBJECT(shot)->flags & 0x20u) != 0u)
	{
		burns_shot_burst(shot);
		return;
	}
}

/* The shot bursts (kind 90, animation 93), stopped and harmless. */
void burns_shot_burst(uint16_t shot)
{
	burns_robot_stop(shot);
	OBJECT(shot)->flags &= 0xBFu;
	OBJECT(shot)->kind = 0x90u;
	OBJECT(shot)->animation = 0x93u;
	OBJECT(shot)->state = 0xFFu;
}

/* Mr. Burns out of the robot: can be hit (box 0D), for 192 frames. */
uint16_t mr_burns_appear(uint16_t burns)
{
	uint16_t box_number = 0, u = 0;
	uint8_t state = 0;

	OBJECT(burns)->flags |= 0x40u;
	box_number = 0xD00u;
	u = burns_robot_set_box(burns, box_number);
	OBJECT(burns)->mr_burns.wait_frames = 0xC0u;
	state = OBJECT(burns)->state;
	OBJECT(burns)->state = state + 1u;
	return u;
}

/* Waits for a player's blow (noting who in 18FC, sound 63) or the end of its 192 frames; then sound 98,
   his voice (3F39), turned left (animation 81). */
uint16_t mr_burns_wait_for_blow(uint16_t burns, uint16_t object)
{
	uint16_t command = 0;
	uint8_t old_blow_player = 0, wait_frames = 0, state = 0, hit = 0, shadow_player = 0;
	uint16_t hit_by = 0;

	old_blow_player = io_read8(maggie_rescuer);
	io_write8(maggie_rescuer, 0u);
	wait_frames = OBJECT(burns)->mr_burns.wait_frames;
	OBJECT(burns)->mr_burns.wait_frames = wait_frames - 1u;
	if (wait_frames == 1u)
	{
		command = 0x9800u;
		vector_queue_sound(command);
		command = 0x3F39u;
		vector_queue_sound(command);
		OBJECT(burns)->attributes = 0x40u;
		OBJECT(burns)->animation = 0x81u;
		OBJECT(burns)->mr_burns.wait_frames = 0x20u;
		state = OBJECT(burns)->state;
		OBJECT(burns)->state = state + 1u;
		return object;
	}
	if ((OBJECT(burns)->flags & 0x20u) == 0u)
		return object;
	hit = OBJECT(burns)->hit;
	if (hit == 0u)
		return object;
	hit_by = OBJECT(burns)->hit_by;
	object = hit_by;
	shadow_player = OBJECT(object)->shadow_player;
	io_write8(maggie_rescuer, shadow_player & ~0xFu);
	command = 0x6300u;
	vector_queue_sound(command);
	command = 0x9800u;
	vector_queue_sound(command);
	command = 0x3F39u;
	vector_queue_sound(command);
	OBJECT(burns)->attributes = 0x40u;
	OBJECT(burns)->animation = 0x81u;
	OBJECT(burns)->mr_burns.wait_frames = 0x20u;
	state = OBJECT(burns)->state;
	OBJECT(burns)->state = state + 1u;
	return object;
}

/* After 32 frames: keeps him in 1852, a boss beaten (direct page 7D), and the step moves on. */
void mr_burns_beaten(uint16_t burns, uint8_t state_number)
{
	uint8_t wait_frames = 0, state = 0;
	uint32_t step_subphase_halfword = 0;

	wait_frames = OBJECT(burns)->mr_burns.wait_frames;
	OBJECT(burns)->mr_burns.wait_frames = wait_frames - 1u;
	if (wait_frames == 1u)
	{
		io_write16(stage_kept_object, burns);
		boss_beaten = 1u;
		step_phase++;
		step_subphase_halfword = 0x100u | (state_number & 0xFFu);
		step_subphase = (uint8_t)(step_subphase_halfword >> 8u);
		step_countdown = (uint8_t)step_subphase_halfword;
		state = OBJECT(burns)->state;
		OBJECT(burns)->state = state + 1u;
	}
}

/* When his animation ends, Maggie's object starts falling. */
uint16_t mr_burns_release_maggie(uint16_t burns, uint16_t rescued)
{
	uint8_t animation_flags = 0, maggie_state = 0, state = 0;
	uint16_t maggie = 0;

	animation_flags = OBJECT(burns)->animation_flags;
	if ((animation_flags & 1u) != 0u)
	{
		maggie = OBJECT(burns)->mr_burns.maggie;
		rescued = maggie;
		maggie_state = OBJECT(rescued)->state;
		OBJECT(rescued)->state = maggie_state + 1u;
		state = OBJECT(burns)->state;
		OBJECT(burns)->state = state + 1u;
	}
	return rescued;
}

/* When Maggie lands: his voice (3F2C), his place and the scroll kept in 18F4-18FA, animation 82. */
void mr_burns_see_maggie(uint16_t burns)
{
	uint16_t command = 0;
	uint8_t maggie_landed = 0, state = 0;
	uint16_t burns_x = 0, burns_y = 0;

	maggie_landed = OBJECT(burns)->mr_burns.maggie_landed;
	if (maggie_landed == 0u)
		return;
	command = 0x3F2Cu;
	vector_queue_sound(command);
	burns_x = OBJECT(burns)->x;
	io_write16(reunion_spot_x, burns_x);
	burns_y = OBJECT(burns)->y;
	io_write16(reunion_spot_y, burns_y);
	io_write16(reunion_camera_x, camera_x);
	io_write16(reunion_camera_y, camera_y);
	OBJECT(burns)->animation = 0x82u;
	OBJECT(burns)->mr_burns.wait_frames = 0x40u;
	state = OBJECT(burns)->state;
	OBJECT(burns)->state = state + 1u;
}

/* His last state: nothing. */
void mr_burns_done(void)
{
}
