/**
 *    Name:        enemies/goon_actions.c
 *    Description: the enemy actions bank 14 holds: the goons' strikes, jumps, grabs and throws
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    09-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the game's 053248 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

/* Action 00: waits facing its target (longer with fewer players), then strikes (animation A4, hit box
   7BEE). */
void goon_wait_then_strike(uint16_t object, uint8_t step, uint16_t *p_y, uint16_t *p_step_handlers)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t step_2 = 0;
	uint16_t step_handlers = 0;

	step_2 = (uint8_t)step;
	step_handlers = goon_wait_then_strike_steps_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)step_2 << 1))
	{
	case 0:
		step_handlers = goon_wait_for_target_on_floor(object);
		break;
	case 2:
		goon_wait_then_strike_swing(object);
		break;
	case 4:
		y = goon_strike_hit(object, y);
		break;
	case -26:
	case -12:
	case 6:
		y = goon_strike_recover(object);
		break;
	case -24:
	case -10:
	case 8:
		goon_action_end(object);
		break;
	case -34:
	case -18:
		goon_dash_start(object);
		break;
	case -32:
		goon_approach_until_close(object);
		break;
	case -30:
		y = goon_approach_strike_hit(object, y);
		break;
	case -28:
		goon_approach_strike_recover(object);
		break;
	case -22:
		goon_back_off_start(object);
		break;
	case -20:
		goon_back_off_walk(object);
		break;
	case -16:
		goon_dash_until_close(object);
		break;
	case -14:
		y = goon_dash_strike_hit(object, y);
		break;
	case -8:
		goon_keep_distance_start(object);
		break;
	case -6:
		goon_keep_distance_check(object);
		break;
	case -4:
		goon_keep_distance_closing(object);
		break;
	case -2:
		goon_keep_distance_backing(object);
		break;
	}
	*p_y = y;
	*p_step_handlers = step_handlers;
}

/* Action 01: waits facing its target, then strikes the other way (animation B2, hit box 7BEE). */
void goon_wait_then_strike_2(uint16_t object, uint8_t step, uint16_t *p_y, uint16_t *p_step_handlers)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t step_2 = 0;
	uint16_t step_handlers = 0;

	step_2 = (uint8_t)step;
	step_handlers = goon_wait_then_strike_2_steps_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)step_2 << 1))
	{
	case 0:
		step_handlers = goon_wait_for_target_on_floor(object);
		break;
	case 2:
		goon_wait_then_strike_2_swing(object);
		break;
	case 4:
		y = goon_strike_hit(object, y);
		break;
	case 6:
	case 14:
	case 22:
		y = goon_strike_recover(object);
		break;
	case 8:
	case 16:
	case 24:
		goon_action_end(object);
		break;
	case 10:
		goon_quick_strike_swing(object);
		break;
	case 12:
		y = goon_quick_strike_hit(object, y);
		break;
	case 18:
		goon_quick_strike_2_swing(object);
		break;
	case 20:
		y = goon_quick_strike_2_hit(object, y);
		break;
	case 26:
	case 68:
		step_handlers = goon_jump_or_run(object);
		break;
	case 28:
		goon_jump_attack_leap(object);
		break;
	case 30:
	case 72:
		y = goon_jump_attack_fall(object, y);
		break;
	case 32:
	case 74:
		goon_jump_attack_land(object);
		break;
	case 34:
		goon_jump_attack_run_end(object);
		break;
	}
	*p_y = y;
	*p_step_handlers = step_handlers;
}

/* Action 02: strikes at once (animation A5, hit box 7BFE). */
void goon_quick_strike(uint16_t object, uint8_t step, uint16_t *p_y, uint16_t *p_step_handlers)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t step_2 = 0;
	uint16_t step_handlers = 0;

	step_2 = (uint8_t)step;
	step_handlers = goon_quick_strike_steps_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)step_2 << 1))
	{
	case 0:
		goon_quick_strike_swing(object);
		break;
	case 2:
		y = goon_quick_strike_hit(object, y);
		break;
	case -4:
	case 4:
	case 12:
		y = goon_strike_recover(object);
		break;
	case -2:
	case 6:
	case 14:
		goon_action_end(object);
		break;
	case 8:
		goon_quick_strike_2_swing(object);
		break;
	case 10:
		y = goon_quick_strike_2_hit(object, y);
		break;
	case 16:
	case 58:
		step_handlers = goon_jump_or_run(object);
		break;
	case 18:
		goon_jump_attack_leap(object);
		break;
	case 20:
	case 62:
		y = goon_jump_attack_fall(object, y);
		break;
	case 22:
	case 64:
		goon_jump_attack_land(object);
		break;
	case 24:
		goon_jump_attack_run_end(object);
		break;
	case -10:
		step_handlers = goon_wait_for_target_on_floor(object);
		break;
	case -8:
		goon_wait_then_strike_2_swing(object);
		break;
	case -6:
		y = goon_strike_hit(object, y);
		break;
	}
	*p_y = y;
	*p_step_handlers = step_handlers;
}

/* Action 03: strikes at once the other way (animation A3, hit box 7C06). */
void goon_quick_strike_2(uint16_t object, uint8_t step, uint16_t *p_y, uint16_t *p_step_handlers)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t step_2 = 0;
	uint16_t step_handlers = 0;

	step_2 = (uint8_t)step;
	step_handlers = goon_quick_strike_2_steps_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)step_2 << 1))
	{
	case 0:
		goon_quick_strike_2_swing(object);
		break;
	case 2:
		y = goon_quick_strike_2_hit(object, y);
		break;
	case -12:
	case -4:
	case 4:
		y = goon_strike_recover(object);
		break;
	case -10:
	case -2:
	case 6:
		goon_action_end(object);
		break;
	case 8:
	case 50:
		step_handlers = goon_jump_or_run(object);
		break;
	case 10:
		goon_jump_attack_leap(object);
		break;
	case 12:
	case 54:
		y = goon_jump_attack_fall(object, y);
		break;
	case 14:
	case 56:
		goon_jump_attack_land(object);
		break;
	case 16:
		goon_jump_attack_run_end(object);
		break;
	case -18:
		step_handlers = goon_wait_for_target_on_floor(object);
		break;
	case -16:
		goon_wait_then_strike_2_swing(object);
		break;
	case -14:
		y = goon_strike_hit(object, y);
		break;
	case -8:
		goon_quick_strike_swing(object);
		break;
	case -6:
		y = goon_quick_strike_hit(object, y);
		break;
	}
	*p_y = y;
	*p_step_handlers = step_handlers;
}

/* Action 04: by a chance the game's rank gives, jumps at its target and comes down striking; else runs a
   little. */
void goon_jump_attack(uint16_t object, uint8_t step, uint16_t *p_y, uint16_t *p_step_handlers)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t step_2 = 0;
	uint16_t step_handlers = 0;

	step_2 = (uint8_t)step;
	step_handlers = goon_jump_attack_steps_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)step_2 << 1))
	{
	case 0:
	case 42:
		step_handlers = goon_jump_or_run(object);
		break;
	case 2:
		goon_jump_attack_leap(object);
		break;
	case 4:
	case 46:
		y = goon_jump_attack_fall(object, y);
		break;
	case 6:
	case 48:
		goon_jump_attack_land(object);
		break;
	case 8:
		goon_jump_attack_run_end(object);
		break;
	case -26:
		step_handlers = goon_wait_for_target_on_floor(object);
		break;
	case -24:
		goon_wait_then_strike_2_swing(object);
		break;
	case -22:
		y = goon_strike_hit(object, y);
		break;
	case -20:
	case -12:
	case -4:
		y = goon_strike_recover(object);
		break;
	case -18:
	case -10:
	case -2:
		goon_action_end(object);
		break;
	case -16:
		goon_quick_strike_swing(object);
		break;
	case -14:
		y = goon_quick_strike_hit(object, y);
		break;
	case -8:
		goon_quick_strike_2_swing(object);
		break;
	case -6:
		y = goon_quick_strike_2_hit(object, y);
		break;
	}
	*p_y = y;
	*p_step_handlers = step_handlers;
}

/* Action 05: by the rank's chance jumps straight up and comes down striking; else goes for a grab (no
   behaviour picks it). */
void goon_jump_up_or_grab(uint16_t object, uint8_t step, uint16_t *p_y, uint16_t *p_step_handlers, uint32_t *p_left_caller)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t step_2 = 0;
	uint16_t step_handlers = 0;

	step_2 = (uint8_t)step;
	step_handlers = goon_jump_up_or_grab_steps_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)step_2 << 1))
	{
	case -42:
	case 0:
		step_handlers = goon_jump_or_run(object);
		break;
	case 2:
		goon_jump_up_leap(object);
		break;
	case -38:
	case 4:
		y = goon_jump_attack_fall(object, y);
		break;
	case -36:
	case 6:
		goon_jump_attack_land(object);
		break;
	case 8:
		step_handlers = goon_grab_approach(object, step_handlers);
		break;
	case 10:
		goon_grab_try(object, &y, &step_handlers);
		break;
	case 12:
		goon_grab_hold(object, &y, &step_handlers, p_left_caller);
		break;
	case 14:
		goon_grab_squeeze(object, &y, &step_handlers, p_left_caller);
		break;
	}
	*p_y = y;
	*p_step_handlers = step_handlers;
}

/* Action 1B: throws a bomb (animation 91). */
void bomb_goon_throw(uint16_t object, uint8_t step, uint16_t *p_y, uint16_t *p_step_handlers)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t step_2 = 0;
	uint16_t step_handlers = 0;

	step_2 = (uint8_t)step;
	step_handlers = bomb_goon_throw_steps_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)step_2 << 1))
	{
	case 0:
		bomb_goon_throw_start(object);
		break;
	case 2:
		bomb_goon_throw_release(object, &y, &step_handlers);
		break;
	case 4:
	case 20:
	case 50:
	case 58:
	case 74:
		armed_goon_action_end(object);
		break;
	}
	*p_y = y;
	*p_step_handlers = step_handlers;
}

/* Action 33: waits facing its target (shovel_goon_close_strike_waits_by_players), then strikes with the
   shovel (animation 92, hit box 7E8F). */
void shovel_goon_close_strike(uint16_t object, uint8_t step, uint16_t *p_y, uint16_t *p_step_handlers)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t step_2 = 0;
	uint16_t step_handlers = 0;

	step_2 = (uint8_t)step;
	step_handlers = shovel_goon_close_strike_steps_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)step_2 << 1))
	{
	case 0:
	case 30:
		step_handlers = shovel_goon_wait_for_target(object);
		break;
	case 2:
		shovel_goon_close_swing(object);
		break;
	case 4:
		y = shovel_goon_close_hit(object, y);
		break;
	case 6:
	case 36:
	case 44:
	case 60:
		y = armed_goon_strike_recover(object);
		break;
	case -8:
	case 8:
	case 38:
	case 46:
	case 62:
		armed_goon_action_end(object);
		break;
	}
	*p_y = y;
	*p_step_handlers = step_handlers;
}

/* Action 0F: walks up to its target and grabs it, holding and squeezing the player until it breaks free
   or is beaten. */
void goon_grab(uint16_t object, uint8_t step, uint16_t *p_y, uint16_t *p_step_handlers, uint32_t *p_left_caller)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t step_2 = 0;
	uint16_t step_handlers = 0;

	step_2 = (uint8_t)step;
	step_handlers = goon_grab_steps_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)step_2 << 1))
	{
	case 0:
		step_handlers = goon_grab_approach(object, step_handlers);
		break;
	case 2:
		goon_grab_try(object, &y, &step_handlers);
		break;
	case 4:
		goon_grab_hold(object, &y, &step_handlers, p_left_caller);
		break;
	case 6:
		goon_grab_squeeze(object, &y, &step_handlers, p_left_caller);
		break;
	case -50:
	case -8:
		step_handlers = goon_jump_or_run(object);
		break;
	case -46:
	case -4:
		y = goon_jump_attack_fall(object, y);
		break;
	case -44:
	case -2:
		goon_jump_attack_land(object);
		break;
	case -6:
		goon_jump_up_leap(object);
		break;
	}
	*p_y = y;
	*p_step_handlers = step_handlers;
}

/* Action 18: with fewer than 3 players present keeps 30 to 50 away from its target for 40 frames, facing
   the way it moves. */
void goon_keep_distance(uint16_t object, uint8_t step, uint16_t *p_y, uint16_t *p_step_handlers)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t step_2 = 0;
	uint16_t step_handlers = 0;

	step_2 = (uint8_t)step;
	step_handlers = goon_keep_distance_steps_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)step_2 << 1))
	{
	case 0:
		goon_keep_distance_start(object);
		break;
	case 2:
		goon_keep_distance_check(object);
		break;
	case 4:
		goon_keep_distance_closing(object);
		break;
	case 6:
		goon_keep_distance_backing(object);
		break;
	case 8:
		step_handlers = goon_wait_for_target_on_floor(object);
		break;
	case 10:
		goon_wait_then_strike_swing(object);
		break;
	case 12:
		y = goon_strike_hit(object, y);
		break;
	case -18:
	case -4:
	case 14:
		y = goon_strike_recover(object);
		break;
	case -16:
	case -2:
	case 16:
		goon_action_end(object);
		break;
	case -26:
	case -10:
		goon_dash_start(object);
		break;
	case -24:
		goon_approach_until_close(object);
		break;
	case -22:
		y = goon_approach_strike_hit(object, y);
		break;
	case -20:
		goon_approach_strike_recover(object);
		break;
	case -14:
		goon_back_off_start(object);
		break;
	case -12:
		goon_back_off_walk(object);
		break;
	case -8:
		goon_dash_until_close(object);
		break;
	case -6:
		y = goon_dash_strike_hit(object, y);
		break;
	}
	vector_face_direction(object);
	*p_y = y;
	*p_step_handlers = step_handlers;
}

/* Action 06: throws its hat (animation AB), waits while it flies and catches it (animation AC). */
void hat_goon_throw_hat(uint16_t object, uint8_t step, uint16_t *p_y, uint16_t *p_step_handlers)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t step_2 = 0;
	uint16_t step_handlers = 0;

	step_2 = (uint8_t)step;
	step_handlers = hat_goon_throw_hat_steps_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)step_2 << 1))
	{
	case 0:
		hat_goon_throw_start(object);
		break;
	case 2:
		hat_goon_throw_release(object, &y, &step_handlers);
		break;
	case 4:
		step_handlers = hat_goon_throw_wait(object);
		break;
	case 6:
		hat_goon_throw_end(object);
		break;
	case -84:
	case -68:
	case -38:
	case -30:
	case -14:
		armed_goon_action_end(object);
		break;
	case -76:
	case -46:
		step_handlers = shovel_goon_wait_for_target(object);
		break;
	case -70:
	case -40:
	case -32:
	case -16:
		y = armed_goon_strike_recover(object);
		break;
	case -44:
		shovel_goon_swing(object);
		break;
	case -42:
		y = shovel_goon_hit(object, y);
		break;
	case -36:
		umbrella_goon_quick_swing(object);
		break;
	case -34:
		y = umbrella_goon_quick_hit(object, y);
		break;
	case -28:
		umbrella_goon_long_swing(object);
		break;
	case -26:
		y = umbrella_goon_long_hit(object, y);
		break;
	case -24:
		y = umbrella_goon_long_recover(object, y);
		break;
	case -22:
		umbrella_goon_long_end(object);
		break;
	case -20:
		umbrella_goon_swing(object);
		break;
	case -18:
		y = umbrella_goon_hit(object, y);
		break;
	case -12:
		umbrella_goon_charge_start(object);
		break;
	case -10:
		y = umbrella_goon_charge_hit(object, y);
		break;
	case -8:
	case -2:
		y = goon_run_through_end(object, y);
		break;
	case -6:
		goon_strike_and_run_swing(object);
		break;
	case -4:
		y = goon_strike_and_run_hit(object, y);
		break;
	}
	*p_y = y;
	*p_step_handlers = step_handlers;
}

/* Action 11: strikes with the umbrella (animation A0, hit box 7EAF). */
void umbrella_goon_strike(uint16_t object, uint8_t step, uint16_t *p_y, uint16_t *p_step_handlers)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t step_2 = 0;
	uint16_t step_handlers = 0;

	step_2 = (uint8_t)step;
	step_handlers = umbrella_goon_strike_steps_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)step_2 << 1))
	{
	case 0:
		umbrella_goon_swing(object);
		break;
	case 2:
		y = umbrella_goon_hit(object, y);
		break;
	case -50:
	case -20:
	case -12:
	case 4:
		y = armed_goon_strike_recover(object);
		break;
	case -64:
	case -48:
	case -18:
	case -10:
	case 6:
		armed_goon_action_end(object);
		break;
	case 8:
		umbrella_goon_charge_start(object);
		break;
	case 10:
		y = umbrella_goon_charge_hit(object, y);
		break;
	case 12:
	case 18:
		y = goon_run_through_end(object, y);
		break;
	case 14:
		goon_strike_and_run_swing(object);
		break;
	case 16:
		y = goon_strike_and_run_hit(object, y);
		break;
	case 20:
		hat_goon_throw_start(object);
		break;
	case 22:
		hat_goon_throw_release(object, &y, &step_handlers);
		break;
	case 24:
		step_handlers = hat_goon_throw_wait(object);
		break;
	case 26:
		hat_goon_throw_end(object);
		break;
	case -56:
	case -26:
		step_handlers = shovel_goon_wait_for_target(object);
		break;
	case -24:
		shovel_goon_swing(object);
		break;
	case -22:
		y = shovel_goon_hit(object, y);
		break;
	case -16:
		umbrella_goon_quick_swing(object);
		break;
	case -14:
		y = umbrella_goon_quick_hit(object, y);
		break;
	case -8:
		umbrella_goon_long_swing(object);
		break;
	case -6:
		y = umbrella_goon_long_hit(object, y);
		break;
	case -4:
		y = umbrella_goon_long_recover(object, y);
		break;
	case -2:
		umbrella_goon_long_end(object);
		break;
	}
	*p_y = y;
	*p_step_handlers = step_handlers;
}

/* Action 12: runs at its target with the umbrella out (hit box 7EB7) for a time by the distance. */
void umbrella_goon_charge(uint16_t object, uint8_t step, uint16_t *p_y, uint16_t *p_step_handlers)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t step_2 = 0;
	uint16_t step_handlers = 0;

	step_2 = (uint8_t)step;
	step_handlers = umbrella_goon_charge_steps_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)step_2 << 1))
	{
	case 0:
		umbrella_goon_charge_start(object);
		break;
	case 2:
		y = umbrella_goon_charge_hit(object, y);
		break;
	case 4:
	case 10:
		y = goon_run_through_end(object, y);
		break;
	case 6:
		goon_strike_and_run_swing(object);
		break;
	case 8:
		y = goon_strike_and_run_hit(object, y);
		break;
	case 12:
		hat_goon_throw_start(object);
		break;
	case 14:
		hat_goon_throw_release(object, &y, &step_handlers);
		break;
	case 16:
		step_handlers = hat_goon_throw_wait(object);
		break;
	case 18:
		hat_goon_throw_end(object);
		break;
	case -72:
	case -56:
	case -26:
	case -18:
	case -2:
		armed_goon_action_end(object);
		break;
	case -64:
	case -34:
		step_handlers = shovel_goon_wait_for_target(object);
		break;
	case -58:
	case -28:
	case -20:
	case -4:
		y = armed_goon_strike_recover(object);
		break;
	case -32:
		shovel_goon_swing(object);
		break;
	case -30:
		y = shovel_goon_hit(object, y);
		break;
	case -24:
		umbrella_goon_quick_swing(object);
		break;
	case -22:
		y = umbrella_goon_quick_hit(object, y);
		break;
	case -16:
		umbrella_goon_long_swing(object);
		break;
	case -14:
		y = umbrella_goon_long_hit(object, y);
		break;
	case -12:
		y = umbrella_goon_long_recover(object, y);
		break;
	case -10:
		umbrella_goon_long_end(object);
		break;
	case -8:
		umbrella_goon_swing(object);
		break;
	case -6:
		y = umbrella_goon_hit(object, y);
		break;
	}
	*p_y = y;
	*p_step_handlers = step_handlers;
}

/* Action 13: a long strike with the umbrella (animation 92, hit box 7EC7, held 10 frames), then
   animation A5. */
void umbrella_goon_long_strike(uint16_t object, uint8_t step, uint16_t *p_y, uint16_t *p_step_handlers)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t step_2 = 0;
	uint16_t step_handlers = 0;

	step_2 = (uint8_t)step;
	step_handlers = umbrella_goon_long_strike_steps_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)step_2 << 1))
	{
	case 0:
		umbrella_goon_long_swing(object);
		break;
	case 2:
		y = umbrella_goon_long_hit(object, y);
		break;
	case 4:
		y = umbrella_goon_long_recover(object, y);
		break;
	case 6:
		umbrella_goon_long_end(object);
		break;
	case 8:
		umbrella_goon_swing(object);
		break;
	case 10:
		y = umbrella_goon_hit(object, y);
		break;
	case -42:
	case -12:
	case -4:
	case 12:
		y = armed_goon_strike_recover(object);
		break;
	case -56:
	case -40:
	case -10:
	case -2:
	case 14:
		armed_goon_action_end(object);
		break;
	case 16:
		umbrella_goon_charge_start(object);
		break;
	case 18:
		y = umbrella_goon_charge_hit(object, y);
		break;
	case 20:
	case 26:
		y = goon_run_through_end(object, y);
		break;
	case 22:
		goon_strike_and_run_swing(object);
		break;
	case 24:
		y = goon_strike_and_run_hit(object, y);
		break;
	case 28:
		hat_goon_throw_start(object);
		break;
	case 30:
		hat_goon_throw_release(object, &y, &step_handlers);
		break;
	case 32:
		step_handlers = hat_goon_throw_wait(object);
		break;
	case 34:
		hat_goon_throw_end(object);
		break;
	case -48:
	case -18:
		step_handlers = shovel_goon_wait_for_target(object);
		break;
	case -16:
		shovel_goon_swing(object);
		break;
	case -14:
		y = shovel_goon_hit(object, y);
		break;
	case -8:
		umbrella_goon_quick_swing(object);
		break;
	case -6:
		y = umbrella_goon_quick_hit(object, y);
		break;
	}
	*p_y = y;
	*p_step_handlers = step_handlers;
}

/* Action 14: waits facing its target, then strikes with the shovel (animation A0, hit box 7E97). */
void shovel_goon_strike(uint16_t object, uint8_t step, uint16_t *p_y, uint16_t *p_step_handlers)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t step_2 = 0;
	uint16_t step_handlers = 0;

	step_2 = (uint8_t)step;
	step_handlers = shovel_goon_strike_steps_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)step_2 << 1))
	{
	case -30:
	case 0:
		step_handlers = shovel_goon_wait_for_target(object);
		break;
	case 2:
		shovel_goon_swing(object);
		break;
	case 4:
		y = shovel_goon_hit(object, y);
		break;
	case -24:
	case 6:
	case 14:
	case 30:
		y = armed_goon_strike_recover(object);
		break;
	case -38:
	case -22:
	case 8:
	case 16:
	case 32:
		armed_goon_action_end(object);
		break;
	case 10:
		umbrella_goon_quick_swing(object);
		break;
	case 12:
		y = umbrella_goon_quick_hit(object, y);
		break;
	case 18:
		umbrella_goon_long_swing(object);
		break;
	case 20:
		y = umbrella_goon_long_hit(object, y);
		break;
	case 22:
		y = umbrella_goon_long_recover(object, y);
		break;
	case 24:
		umbrella_goon_long_end(object);
		break;
	case 26:
		umbrella_goon_swing(object);
		break;
	case 28:
		y = umbrella_goon_hit(object, y);
		break;
	case 34:
		umbrella_goon_charge_start(object);
		break;
	case 36:
		y = umbrella_goon_charge_hit(object, y);
		break;
	case 38:
	case 44:
		y = goon_run_through_end(object, y);
		break;
	case 40:
		goon_strike_and_run_swing(object);
		break;
	case 42:
		y = goon_strike_and_run_hit(object, y);
		break;
	case 46:
		hat_goon_throw_start(object);
		break;
	case 48:
		hat_goon_throw_release(object, &y, &step_handlers);
		break;
	case 50:
		step_handlers = hat_goon_throw_wait(object);
		break;
	case 52:
		hat_goon_throw_end(object);
		break;
	}
	*p_y = y;
	*p_step_handlers = step_handlers;
}

/* Action 15: waits facing its target (shovel_goon_far_strike_waits_by_players), then the long shovel
   strike (animation 91, hit box 7E9F). */
void shovel_goon_far_strike(uint16_t object, uint8_t step, uint16_t *p_y, uint16_t *p_step_handlers)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t step_2 = 0;
	uint16_t step_handlers = 0;

	step_2 = (uint8_t)step;
	step_handlers = shovel_goon_far_strike_steps_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)step_2 << 1))
	{
	case 0:
		step_handlers = shovel_goon_far_wait(object);
		break;
	case 2:
		shovel_goon_far_swing(object);
		break;
	case 4:
		y = shovel_goon_far_hit(object, y);
		break;
	case 6:
		y = armed_goon_strike_recover(object);
		break;
	case 8:
		armed_goon_action_end(object);
		break;
	}
	*p_y = y;
	*p_step_handlers = step_handlers;
}

/* Action 3D: walks away from its target for 20 frames. */
void goon_back_off(uint16_t object, uint8_t step, uint16_t *p_y, uint16_t *p_step_handlers)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t step_2 = 0;
	uint16_t step_handlers = 0;

	step_2 = (uint8_t)step;
	step_handlers = goon_back_off_steps_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)step_2 << 1))
	{
	case 0:
		goon_back_off_start(object);
		break;
	case 2:
		goon_back_off_walk(object);
		break;
	case -12:
	case 4:
		goon_dash_start(object);
		break;
	case 6:
		goon_dash_until_close(object);
		break;
	case 8:
		y = goon_dash_strike_hit(object, y);
		break;
	case -4:
	case 10:
	case 28:
		y = goon_strike_recover(object);
		break;
	case -2:
	case 12:
	case 30:
		goon_action_end(object);
		break;
	case 14:
		goon_keep_distance_start(object);
		break;
	case 16:
		goon_keep_distance_check(object);
		break;
	case 18:
		goon_keep_distance_closing(object);
		break;
	case 20:
		goon_keep_distance_backing(object);
		break;
	case 22:
		step_handlers = goon_wait_for_target_on_floor(object);
		break;
	case 24:
		goon_wait_then_strike_swing(object);
		break;
	case 26:
		y = goon_strike_hit(object, y);
		break;
	case -10:
		goon_approach_until_close(object);
		break;
	case -8:
		y = goon_approach_strike_hit(object, y);
		break;
	case -6:
		goon_approach_strike_recover(object);
		break;
	}
	*p_y = y;
	*p_step_handlers = step_handlers;
}

/* Action 07: strikes (animation A4, hit box 7EA7) and runs on through (no behaviour picks it). */
void goon_strike_and_run(uint16_t object, uint8_t step, uint16_t *p_y, uint16_t *p_step_handlers)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t step_2 = 0;
	uint16_t step_handlers = 0;

	step_2 = (uint8_t)step;
	step_handlers = goon_strike_and_run_steps_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)step_2 << 1))
	{
	case 0:
		goon_strike_and_run_swing(object);
		break;
	case 2:
		y = goon_strike_and_run_hit(object, y);
		break;
	case -2:
	case 4:
		y = goon_run_through_end(object, y);
		break;
	case 6:
		hat_goon_throw_start(object);
		break;
	case 8:
		hat_goon_throw_release(object, &y, &step_handlers);
		break;
	case 10:
		step_handlers = hat_goon_throw_wait(object);
		break;
	case 12:
		hat_goon_throw_end(object);
		break;
	case -78:
	case -62:
	case -32:
	case -24:
	case -8:
		armed_goon_action_end(object);
		break;
	case -70:
	case -40:
		step_handlers = shovel_goon_wait_for_target(object);
		break;
	case -64:
	case -34:
	case -26:
	case -10:
		y = armed_goon_strike_recover(object);
		break;
	case -38:
		shovel_goon_swing(object);
		break;
	case -36:
		y = shovel_goon_hit(object, y);
		break;
	case -30:
		umbrella_goon_quick_swing(object);
		break;
	case -28:
		y = umbrella_goon_quick_hit(object, y);
		break;
	case -22:
		umbrella_goon_long_swing(object);
		break;
	case -20:
		y = umbrella_goon_long_hit(object, y);
		break;
	case -18:
		y = umbrella_goon_long_recover(object, y);
		break;
	case -16:
		umbrella_goon_long_end(object);
		break;
	case -14:
		umbrella_goon_swing(object);
		break;
	case -12:
		y = umbrella_goon_hit(object, y);
		break;
	case -6:
		umbrella_goon_charge_start(object);
		break;
	case -4:
		y = umbrella_goon_charge_hit(object, y);
		break;
	}
	*p_y = y;
	*p_step_handlers = step_handlers;
}

/* Action 16: strikes at once with the umbrella (animation 91, hit box 7EBF). */
void umbrella_goon_quick_strike(uint16_t object, uint8_t step, uint16_t *p_y, uint16_t *p_step_handlers)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t step_2 = 0;
	uint16_t step_handlers = 0;

	step_2 = (uint8_t)step;
	step_handlers = umbrella_goon_quick_strike_steps_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)step_2 << 1))
	{
	case 0:
		umbrella_goon_quick_swing(object);
		break;
	case 2:
		y = umbrella_goon_quick_hit(object, y);
		break;
	case -34:
	case -4:
	case 4:
	case 20:
		y = armed_goon_strike_recover(object);
		break;
	case -48:
	case -32:
	case -2:
	case 6:
	case 22:
		armed_goon_action_end(object);
		break;
	case 8:
		umbrella_goon_long_swing(object);
		break;
	case 10:
		y = umbrella_goon_long_hit(object, y);
		break;
	case 12:
		y = umbrella_goon_long_recover(object, y);
		break;
	case 14:
		umbrella_goon_long_end(object);
		break;
	case 16:
		umbrella_goon_swing(object);
		break;
	case 18:
		y = umbrella_goon_hit(object, y);
		break;
	case 24:
		umbrella_goon_charge_start(object);
		break;
	case 26:
		y = umbrella_goon_charge_hit(object, y);
		break;
	case 28:
	case 34:
		y = goon_run_through_end(object, y);
		break;
	case 30:
		goon_strike_and_run_swing(object);
		break;
	case 32:
		y = goon_strike_and_run_hit(object, y);
		break;
	case 36:
		hat_goon_throw_start(object);
		break;
	case 38:
		hat_goon_throw_release(object, &y, &step_handlers);
		break;
	case 40:
		step_handlers = hat_goon_throw_wait(object);
		break;
	case 42:
		hat_goon_throw_end(object);
		break;
	case -40:
	case -10:
		step_handlers = shovel_goon_wait_for_target(object);
		break;
	case -8:
		shovel_goon_swing(object);
		break;
	case -6:
		y = shovel_goon_hit(object, y);
		break;
	}
	*p_y = y;
	*p_step_handlers = step_handlers;
}

/* Action 17: dashes at its target and, when close in line with it, strikes (animation B8, hit box 7C16). */
void goon_dash_strike(uint16_t object, uint8_t step, uint16_t *p_y, uint16_t *p_step_handlers)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t step_2 = 0;
	uint16_t step_handlers = 0;

	step_2 = (uint8_t)step;
	step_handlers = goon_dash_strike_steps_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)step_2 << 1))
	{
	case -16:
	case 0:
		goon_dash_start(object);
		break;
	case 2:
		goon_dash_until_close(object);
		break;
	case 4:
		y = goon_dash_strike_hit(object, y);
		break;
	case -8:
	case 6:
	case 24:
		y = goon_strike_recover(object);
		break;
	case -6:
	case 8:
	case 26:
		goon_action_end(object);
		break;
	case 10:
		goon_keep_distance_start(object);
		break;
	case 12:
		goon_keep_distance_check(object);
		break;
	case 14:
		goon_keep_distance_closing(object);
		break;
	case 16:
		goon_keep_distance_backing(object);
		break;
	case 18:
		step_handlers = goon_wait_for_target_on_floor(object);
		break;
	case 20:
		goon_wait_then_strike_swing(object);
		break;
	case 22:
		y = goon_strike_hit(object, y);
		break;
	case -14:
		goon_approach_until_close(object);
		break;
	case -12:
		y = goon_approach_strike_hit(object, y);
		break;
	case -10:
		goon_approach_strike_recover(object);
		break;
	case -4:
		goon_back_off_start(object);
		break;
	case -2:
		goon_back_off_walk(object);
		break;
	}
	*p_y = y;
	*p_step_handlers = step_handlers;
}

/* Action 27: runs up to its target and, when close in line with it, strikes (animation B9, sound 4800,
   hit box 7C1E), then recovers (animation BA). */
void goon_approach_strike(uint16_t object, uint8_t step, uint16_t *p_y, uint16_t *p_step_handlers)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t step_2 = 0;
	uint16_t step_handlers = 0;

	step_2 = (uint8_t)step;
	step_handlers = goon_approach_strike_steps_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)step_2 << 1))
	{
	case 0:
	case 16:
		goon_dash_start(object);
		break;
	case 2:
		goon_approach_until_close(object);
		break;
	case 4:
		y = goon_approach_strike_hit(object, y);
		break;
	case 6:
		goon_approach_strike_recover(object);
		break;
	case 8:
	case 22:
	case 40:
		y = goon_strike_recover(object);
		break;
	case 10:
	case 24:
	case 42:
		goon_action_end(object);
		break;
	case 12:
		goon_back_off_start(object);
		break;
	case 14:
		goon_back_off_walk(object);
		break;
	case 18:
		goon_dash_until_close(object);
		break;
	case 20:
		y = goon_dash_strike_hit(object, y);
		break;
	case 26:
		goon_keep_distance_start(object);
		break;
	case 28:
		goon_keep_distance_check(object);
		break;
	case 30:
		goon_keep_distance_closing(object);
		break;
	case 32:
		goon_keep_distance_backing(object);
		break;
	case 34:
		step_handlers = goon_wait_for_target_on_floor(object);
		break;
	case 36:
		goon_wait_then_strike_swing(object);
		break;
	case 38:
		y = goon_strike_hit(object, y);
		break;
	}
	*p_y = y;
	*p_step_handlers = step_handlers;
}

/* Unused: a goon's action step that waits by the rank (unused_goon_waits_by_rank) with animation 86,
   facing its target. */
void unused_goon_wait_by_rank(uint16_t object)
{
	uint8_t action_step = 0;

	OBJECT(object)->timer = unused_goon_waits_by_rank[(int8_t)rank];
	OBJECT(object)->animation = 0x86u;
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
	face_target(object);
}

/* Action 27, step 1: runs on until within 40 of its target in x (or its time is up); out of line (8 or
   more in y) gives up, else strikes with sound 4800. */
void goon_approach_until_close(uint16_t object)
{
	uint32_t carry = 0;
	uint16_t command = 0;
	uint8_t timer = 0, action_step = 0;
	uint16_t target_dx = 0, target_dy = 0;

	target_dx = OBJECT(object)->target_dx;
	if (target_dx >= 0x40u)
	{
		timer = OBJECT(object)->timer;
		OBJECT(object)->timer = timer - 1u;
		if (timer != 1u)
			return;
	}
	target_dy = OBJECT(object)->target_dy;
	if (target_dy >= 8u)
	{
		OBJECT(object)->state = 2u;
		OBJECT(object)->timer = 0u;
		return;
	}
	OBJECT(object)->animation = 0xB9u;
	command = 0x4800u;
	carry = vector_queue_sound(command);
	OBJECT(object)->timer = 0x20u;
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
}

/* Action 27, step 2: at the animation's event its strike's hit box. */
uint16_t goon_approach_strike_hit(uint16_t object, uint16_t box)
{
	uint8_t animation_flags = 0, action_step = 0;

	animation_flags = OBJECT(object)->animation_flags;
	if ((animation_flags & 2u) == 0u)
		return box;
	box = goon_approach_strike_hit_box_ADDRESS;
	vector_set_hit_box(object, box);
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
	return box;
}

/* Action 27, step 3: after its time stops (animation BA). */
void goon_approach_strike_recover(uint16_t object)
{
	uint8_t timer = 0, action_step = 0;

	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer == 1u)
	{
		OBJECT(object)->x_speed = 0;
		OBJECT(object)->animation = 0xBAu;
		action_step = OBJECT(object)->action_step;
		OBJECT(object)->action_step = action_step + 1u;
	}
}

/* Action 3D, step 0: faces its target and walks away from it (animation 86) for 20 frames. */
void goon_back_off_start(uint16_t object)
{
	uint8_t target_direction = 0, action_step = 0;
	uint16_t x_speed = 0;

	face_target(object);
	OBJECT(object)->animation = 0x86u;
	OBJECT(object)->x_speed = 0x100;
	target_direction = OBJECT(object)->target_direction;
	if ((int8_t)(target_direction - 0x40u) < 0)
	{
		x_speed = OBJECT(object)->x_speed;
		OBJECT(object)->x_speed = 0u - x_speed;
	}
	OBJECT(object)->timer = 0x20u;
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
	vector_face_direction(object);
}

/* Action 3D, step 1: done after its time. */
void goon_back_off_walk(uint16_t object)
{
	uint8_t timer = 0;

	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer != 1u)
		return;
	OBJECT(object)->state = 2u;
	OBJECT(object)->timer = 0u;
}

/* Actions 17 and 27, step 0: runs at its target (animation 90) for up to 40 frames. */
void goon_dash_start(uint16_t object)
{
	uint8_t target_direction = 0, action_step = 0;
	uint16_t x_speed = 0;

	face_target(object);
	OBJECT(object)->animation = 0x90u;
	OBJECT(object)->x_speed = 0x200;
	target_direction = OBJECT(object)->target_direction;
	if ((int8_t)(target_direction - 0x40u) >= 0)
	{
		x_speed = OBJECT(object)->x_speed;
		OBJECT(object)->x_speed = 0u - x_speed;
	}
	OBJECT(object)->timer = 0x40u;
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
	face_movement(object);
}

/* Unused: does nothing. */
void unused_goon_action_no_op(void)
{
}

/* Action 17, step 1: runs on until within 20 of its target in x (or its time is up), stops; out of line
   gives up, else strikes (animation B8). */
void goon_dash_until_close(uint16_t object)
{
	uint8_t action_step = 0, timer = 0;
	uint16_t target_dx = 0, target_dy = 0;

	target_dx = OBJECT(object)->target_dx;
	if (target_dx < 0x20u)
	{
		OBJECT(object)->x_speed = 0;
		target_dy = OBJECT(object)->target_dy;
		if (target_dy >= 8u)
		{
			OBJECT(object)->state = 2u;
			OBJECT(object)->timer = 0u;
			return;
		}
		OBJECT(object)->animation = 0xB8u;
		action_step = OBJECT(object)->action_step;
		OBJECT(object)->action_step = action_step + 1u;
		return;
	}
	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer != 1u)
		return;
	OBJECT(object)->x_speed = 0;
	target_dy = OBJECT(object)->target_dy;
	if (target_dy >= 8u)
	{
		OBJECT(object)->state = 2u;
		OBJECT(object)->timer = 0u;
		return;
	}
	OBJECT(object)->animation = 0xB8u;
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
}

/* Action 17, step 2: at the animation's event its strike's hit box. */
uint16_t goon_dash_strike_hit(uint16_t object, uint16_t box)
{
	uint8_t animation_flags = 0, action_step = 0;

	animation_flags = OBJECT(object)->animation_flags;
	if ((animation_flags & 2u) == 0u)
		return box;
	box = goon_dash_strike_hit_box_ADDRESS;
	vector_set_hit_box(object, box);
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
	return box;
}

/* Action 18, step 0: with 3 players or more present done at once; else faces its target, standing, for
   up to 40 frames. */
void goon_keep_distance_start(uint16_t object)
{
	uint8_t t1 = 0, action_step = 0;

	t1 = io_read8(0x1874u);
	if (t1 >= 3u)
	{
		OBJECT(object)->state = 2u;
		OBJECT(object)->timer = 0u;
		return;
	}
	OBJECT(object)->animation = 0x86u;
	face_target(object);
	OBJECT(object)->timer = 0x40u;
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
}

/* Action 18, step 1: within 30 of its target steps away, beyond 50 steps closer, between them stands. */
void goon_keep_distance_check(uint16_t object)
{
	uint8_t a = 0, d = 0;
	uint8_t timer = 0, action_step = 0, target_direction = 0, action_step_2 = 0, target_direction_2 = 0;
	uint16_t target_dx = 0, target_dx_2 = 0;

	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer == 1u)
	{
		OBJECT(object)->state = 2u;
		OBJECT(object)->timer = 0u;
		return;
	}
	target_dx = OBJECT(object)->target_dx;
	if (target_dx < 0x30u)
	{
		action_step = OBJECT(object)->action_step;
		OBJECT(object)->action_step = action_step + 1u;
		target_direction = OBJECT(object)->target_direction;
		if (target_direction >= 0x40u)
		{
			d = 0x80u;
			a = 0u;
		}
		else
		{
			d = 0x80u;
			a = 0xFFu;
		}
		OBJECT(object)->x_speed = ((uint32_t)a << 8) | (d & 0xFFu);
		action_step_2 = OBJECT(object)->action_step;
		OBJECT(object)->action_step = action_step_2 + 1u;
		return;
	}
	target_dx_2 = OBJECT(object)->target_dx;
	if (target_dx_2 < 0x50u)
	{
		OBJECT(object)->x_speed = 0;
		OBJECT(object)->y_speed = 0;
		return;
	}
	target_direction_2 = OBJECT(object)->target_direction;
	if (target_direction_2 >= 0x40u)
	{
		d = 0x80u;
		a = 0xFFu;
		OBJECT(object)->x_speed = ((uint32_t)a << 8) | (d & 0xFFu);
		action_step_2 = OBJECT(object)->action_step;
		OBJECT(object)->action_step = action_step_2 + 1u;
		return;
	}
	d = 0x80u;
	a = 0u;
	OBJECT(object)->x_speed = ((uint32_t)a << 8) | (d & 0xFFu);
	action_step_2 = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step_2 + 1u;
}

/* Action 18, step 2: stepping closer until within 30. */
void goon_keep_distance_closing(uint16_t object)
{
	uint8_t timer = 0;
	uint16_t target_dx = 0;

	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer == 1u)
	{
		OBJECT(object)->state = 2u;
		OBJECT(object)->timer = 0u;
		return;
	}
	target_dx = OBJECT(object)->target_dx;
	if (target_dx < 0x30u)
		OBJECT(object)->action_step = 1u;
}

/* Action 18, step 3: stepping away until 50 off. */
void goon_keep_distance_backing(uint16_t object)
{
	uint8_t timer = 0;
	uint16_t target_dx = 0;

	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer == 1u)
	{
		OBJECT(object)->state = 2u;
		OBJECT(object)->timer = 0u;
		return;
	}
	target_dx = OBJECT(object)->target_dx;
	if (target_dx >= 0x50u)
		OBJECT(object)->action_step = 1u;
}

/* Actions 00 and 01, step 0: facing its target; with the target on the floor stands for
   goon_strike_waits_by_players' wait, else for a frame. */
uint16_t goon_wait_for_target_on_floor(uint16_t object)
{
	uint16_t object_2 = 0, strike_waits = 0;
	uint8_t action_step = 0, action_step_2 = 0;
	uint16_t target = 0, z = 0, floor_z = 0;

	target = OBJECT(object)->target;
	object_2 = target;
	z = OBJECT(object_2)->z;
	floor_z = OBJECT(object_2)->floor_z;
	if (z != floor_z)
	{
		action_step = OBJECT(object)->action_step;
		OBJECT(object)->action_step = action_step + 1u;
		OBJECT(object)->timer = 1u;
		face_target(object);
		return object_2;
	}
	OBJECT(object)->animation = 0x86u;
	strike_waits = goon_strike_waits_by_players_ADDRESS;
	OBJECT(object)->timer = goon_strike_waits_by_players[(int8_t)player_count];
	action_step_2 = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step_2 + 1u;
	face_target(object);
	return strike_waits;
}

/* Action 00, step 1: after its wait strikes (animation A4) facing its target. */
void goon_wait_then_strike_swing(uint16_t object)
{
	uint8_t timer = 0, action_step = 0;

	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer != 1u)
		return;
	OBJECT(object)->animation = 0xA4u;
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
	face_target(object);
}

/* Actions 00 and 01, step 2: at the animation's event its strike's hit box (7BEE). */
uint16_t goon_strike_hit(uint16_t object, uint16_t box)
{
	uint8_t animation_flags = 0, action_step = 0;

	animation_flags = OBJECT(object)->animation_flags;
	if ((animation_flags & 2u) == 0u)
		return box;
	box = goon_strike_hit_box_ADDRESS;
	vector_set_hit_box(object, box);
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
	return box;
}

/* A strike's end: back to its body's hit box (7BF6), done at the animation's end. */
uint16_t goon_strike_recover(uint16_t object)
{
	uint16_t box = 0;
	uint8_t action_step = 0;

	box = goon_action_body_box_ADDRESS;
	vector_set_hit_box(object, box);
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
	goon_action_end(object);
	return box;
}

/* Done at the animation's end. */
void goon_action_end(uint16_t object)
{
	uint8_t animation_flags = 0;

	animation_flags = OBJECT(object)->animation_flags;
	if ((animation_flags & 1u) == 0u)
		return;
	OBJECT(object)->state = 2u;
	OBJECT(object)->timer = 0u;
}

/* Action 01, step 1: after its wait strikes (animation B2) facing its target. */
void goon_wait_then_strike_2_swing(uint16_t object)
{
	uint8_t timer = 0, action_step = 0;

	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer != 1u)
		return;
	OBJECT(object)->animation = 0xB2u;
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
	face_target(object);
}

/* Unused: a goon's action step that waits 4 with animation 86, facing its target. */
void unused_goon_short_wait(uint16_t object)
{
	uint8_t action_step = 0;

	OBJECT(object)->animation = 0x86u;
	OBJECT(object)->timer = 4u;
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
	face_target(object);
}

/* Action 02, step 0: strikes (animation A5) facing its target. */
void goon_quick_strike_swing(uint16_t object)
{
	uint8_t action_step = 0;

	OBJECT(object)->animation = 0xA5u;
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
	face_target(object);
}

/* Action 02, step 1: at the animation's event its strike's hit box (7BFE). */
uint16_t goon_quick_strike_hit(uint16_t object, uint16_t box)
{
	uint8_t animation_flags = 0, action_step = 0;

	animation_flags = OBJECT(object)->animation_flags;
	if ((animation_flags & 2u) == 0u)
		return box;
	box = goon_quick_strike_hit_box_ADDRESS;
	vector_set_hit_box(object, box);
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
	return box;
}

/* Action 03, step 0: strikes (animation A3) facing its target. */
void goon_quick_strike_2_swing(uint16_t object)
{
	uint8_t action_step = 0;

	OBJECT(object)->animation = 0xA3u;
	face_target(object);
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
}

/* Action 03, step 1: at the animation's event its strike's hit box (7C06). */
uint16_t goon_quick_strike_2_hit(uint16_t object, uint16_t box)
{
	uint8_t animation_flags = 0, action_step = 0;

	animation_flags = OBJECT(object)->animation_flags;
	if ((animation_flags & 2u) == 0u)
		return box;
	box = goon_quick_strike_2_hit_box_ADDRESS;
	vector_set_hit_box(object, box);
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
	return box;
}

/* Action 04, step 4: its short run done after its time. */
void goon_jump_attack_run_end(uint16_t object)
{
	uint8_t timer = 0;

	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer != 1u)
		return;
	OBJECT(object)->state = 2u;
	OBJECT(object)->timer = 0u;
}

/* Actions 04 and 05, step 0: when goon_jump_attack_chances_by_rank's chance comes up crouches to jump
   (animation A6); else runs the way it faces for 10 frames (animation 90). */
uint16_t goon_jump_or_run(uint16_t object)
{
	uint16_t jump_chances = 0;
	uint8_t action_step = 0, attributes = 0;
	uint16_t x_speed = 0;

	jump_chances = goon_jump_attack_chances_by_rank_ADDRESS;
	if (random_number <= goon_jump_attack_chances_by_rank[(int8_t)rank])
	{
		OBJECT(object)->animation = 0xA6u;
		action_step = OBJECT(object)->action_step;
		OBJECT(object)->action_step = action_step + 1u;
		face_target(object);
		return jump_chances;
	}
	OBJECT(object)->animation = 0x90u;
	face_target(object);
	OBJECT(object)->x_speed = 0x180;
	attributes = OBJECT(object)->attributes;
	if ((attributes & 0x40u) != 0u)
	{
		x_speed = OBJECT(object)->x_speed;
		OBJECT(object)->x_speed = 0u - x_speed;
	}
	OBJECT(object)->timer = 0x10u;
	OBJECT(object)->action_step = 4u;
	return jump_chances;
}

/* Action 04, step 1: at the animation's end leaps forward (animation A7). */
void goon_jump_attack_leap(uint16_t object)
{
	uint8_t animation_flags = 0, attributes = 0, action_step = 0;
	uint16_t x_speed = 0;

	animation_flags = OBJECT(object)->animation_flags;
	if ((animation_flags & 1u) == 0u)
		return;
	OBJECT(object)->animation = 0xA7u;
	OBJECT(object)->x_speed = 0x200;
	attributes = OBJECT(object)->attributes;
	if ((attributes & 0x40u) != 0u)
	{
		x_speed = OBJECT(object)->x_speed;
		OBJECT(object)->x_speed = 0u - x_speed;
	}
	OBJECT(object)->z_speed = 0x400;
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
}

/* Actions 04 and 05, step 2: falls (gravity 40) with its strike's hit box (7C0E) from the animation's
   event; near the floor lands (animation A8) with its body's. */
uint16_t goon_jump_attack_fall(uint16_t object, uint16_t box)
{
	uint16_t z_speed = 0;
	uint8_t animation_flags = 0, action_step = 0;
	uint16_t z = 0, floor_z = 0, z_speed_2 = 0;

	z = OBJECT(object)->z;
	floor_z = OBJECT(object)->floor_z;
	if ((uint16_t)(z - floor_z) >= 4u)
	{
		animation_flags = OBJECT(object)->animation_flags;
		if ((((uint16_t)((uint32_t)animation_flags << 8) >> 8) & 2u) != 0u)
		{
			box = goon_jump_attack_fall_box_ADDRESS;
			vector_set_hit_box(object, box);
		}
	}
	else
	{
		OBJECT(object)->animation = 0xA8u;
		box = goon_action_body_box_ADDRESS;
		vector_set_hit_box(object, box);
		action_step = OBJECT(object)->action_step;
		OBJECT(object)->action_step = action_step + 1u;
	}
	z_speed_2 = OBJECT(object)->z_speed;
	z_speed = z_speed_2 - 0x40u;
	goon_jump_attack_settle(object, z_speed);
	return box;
}

/* Actions 04 and 05, step 3: comes down the rest of the way (gravity 10). */
void goon_jump_attack_land(uint16_t object)
{
	uint16_t z_speed = 0;
	uint16_t z_speed_2 = 0;

	z_speed_2 = OBJECT(object)->z_speed;
	z_speed = z_speed_2 - 0x10u;
	goon_jump_attack_settle(object, z_speed);
}

/* Takes the new z speed and moves; on the floor, animation A8 and done. */
void goon_jump_attack_settle(uint16_t object, uint16_t z_speed)
{
	uint32_t carry = 0;

	OBJECT(object)->z_speed = z_speed;
	carry = vector_check_landing(object);
	if (carry == 0u)
		return;
	OBJECT(object)->animation = 0xA8u;
	OBJECT(object)->state = 2u;
	OBJECT(object)->timer = 0u;
}

/* Action 05, step 1: at the animation's end leaps straight up (animation A7). */
void goon_jump_up_leap(uint16_t object)
{
	uint8_t animation_flags = 0, action_step = 0;

	animation_flags = OBJECT(object)->animation_flags;
	if (animation_flags & 1u)
	{
		OBJECT(object)->animation = 0xA7u;
		OBJECT(object)->z_speed = 0x400;
		action_step = OBJECT(object)->action_step;
		OBJECT(object)->action_step = action_step + 1u;
	}
}

/* Action 0F, step 0: when its field 32 has bit 7 strikes at once instead (action 02); with its target
   down or already held gives up; else walks at it for up to 40 frames. */
uint16_t goon_grab_approach(uint16_t object, uint16_t step_handlers)
{
	uint8_t angle = 0;
	uint16_t direction = 0, heading = 0, target_player = 0;
	uint8_t not_behind_target = 0, state = 0, hold_presses = 0, action_step = 0;
	uint16_t target = 0;

	not_behind_target = OBJECT(object)->goon.not_behind_target;
	if ((int8_t)not_behind_target < 0)
	{
		OBJECT(object)->action = 2u;
		OBJECT(object)->action_step = 0u;
		goon_quick_strike_swing(object);
		return step_handlers;
	}
	target = OBJECT(object)->target;
	target_player = target;
	state = OBJECT(target_player)->state;
	if ((int8_t)state < 0)
	{
		OBJECT(object)->state = 2u;
		OBJECT(object)->timer = 0u;
		return target_player;
	}
	hold_presses = OBJECT(target_player)->player.hold_presses;
	if (hold_presses != 0u)
	{
		OBJECT(object)->state = 2u;
		OBJECT(object)->timer = 0u;
		return target_player;
	}
	face_target(object);
	OBJECT(object)->timer = 0x40u;
	direction = vector_direction_to(object, target_player);
	angle = (uint8_t)(direction >> 8);
	heading = ((uint32_t)angle << 8) | 0x30u;
	vector_set_speed_by_direction(object, heading);
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
	enemy_restart_walk_animation(object);
	return target_player;
}

/* Action 0F, step 1: touching its target, close and both on the floor: grabs the player (its fields 4B,
   3D, 1E and the hit flag), takes its place and shows the animation of holding that player's character
   (goon_hold_animations); else keeps walking at it until its time is up. */
void goon_grab_try(uint16_t object, uint16_t *p_hold_animations, uint16_t *p_target_player)
{
	uint16_t hold_animations = (uint16_t)*p_hold_animations;
	uint8_t a = 0, step = 0;
	uint16_t direction = 0, heading = 0, target_player = 0;
	uint8_t stack = 0;
	uint8_t state = 0, timer = 0, blink_frames = 0, hold_presses = 0, attributes = 0, attributes_2 = 0, shadow_player = 0, points = 0, shadow_player_2 = 0, action_step = 0;
	uint16_t target = 0, hit_by = 0, target_dx = 0, target_dy = 0, floor_z = 0, z = 0, floor_z_2 = 0, t1 = 0, t2 = 0;

	target = OBJECT(object)->target;
	target_player = target;
	if ((OBJECT(object)->flags & 0x20u) == 0u)
	{
		state = OBJECT(target_player)->state;
		if ((int8_t)state < 0)
		{
			OBJECT(object)->state = 2u;
			OBJECT(object)->timer = 0u;
		}
		else
		{
			timer = OBJECT(object)->timer;
			OBJECT(object)->timer = timer - 1u;
			if (timer != 1u)
			{
				direction = vector_direction_to(object, target_player);
				a = (uint8_t)(direction >> 8);
				heading = ((uint32_t)a << 8) | 0x30u;
				vector_set_speed_by_direction(object, heading);
				vector_choose_walk_animation(object);
			}
			else
			{
				OBJECT(object)->state = 2u;
				OBJECT(object)->timer = 0u;
			}
		}
	}
	else
	{
		blink_frames = OBJECT(target_player)->player.blink_frames;
		if (blink_frames != 0u)
		{
			OBJECT(object)->x_speed = 0;
			OBJECT(object)->y_speed = 0;
			OBJECT(object)->action = 2u;
			OBJECT(object)->action_step = 0u;
		}
		else
		{
			hold_presses = OBJECT(target_player)->player.hold_presses;
			if (hold_presses != 0u)
			{
				OBJECT(object)->x_speed = 0;
				OBJECT(object)->y_speed = 0;
				OBJECT(object)->action = 2u;
				OBJECT(object)->action_step = 0u;
			}
			else
			{
				hit_by = OBJECT(object)->hit_by;
				if (target_player != hit_by)
				{
					state = OBJECT(target_player)->state;
					if ((int8_t)state < 0)
					{
						OBJECT(object)->state = 2u;
						OBJECT(object)->timer = 0u;
					}
					else
					{
						timer = OBJECT(object)->timer;
						OBJECT(object)->timer = timer - 1u;
						if (timer != 1u)
						{
							direction = vector_direction_to(object, target_player);
							a = (uint8_t)(direction >> 8);
							heading = ((uint32_t)a << 8) | 0x30u;
							vector_set_speed_by_direction(object, heading);
							vector_choose_walk_animation(object);
						}
						else
						{
							OBJECT(object)->state = 2u;
							OBJECT(object)->timer = 0u;
						}
					}
				}
				else
				{
					target_dx = OBJECT(object)->target_dx;
					if (target_dx >= 8u)
					{
						state = OBJECT(target_player)->state;
						if ((int8_t)state < 0)
						{
							OBJECT(object)->state = 2u;
							OBJECT(object)->timer = 0u;
						}
						else
						{
							timer = OBJECT(object)->timer;
							OBJECT(object)->timer = timer - 1u;
							if (timer != 1u)
							{
								direction = vector_direction_to(object, target_player);
								a = (uint8_t)(direction >> 8);
								heading = ((uint32_t)a << 8) | 0x30u;
								vector_set_speed_by_direction(object, heading);
								vector_choose_walk_animation(object);
							}
							else
							{
								OBJECT(object)->state = 2u;
								OBJECT(object)->timer = 0u;
							}
						}
					}
					else
					{
						target_dy = OBJECT(object)->target_dy;
						if (target_dy >= 4u)
						{
							state = OBJECT(target_player)->state;
							if ((int8_t)state < 0)
							{
								OBJECT(object)->state = 2u;
								OBJECT(object)->timer = 0u;
							}
							else
							{
								timer = OBJECT(object)->timer;
								OBJECT(object)->timer = timer - 1u;
								if (timer != 1u)
								{
									direction = vector_direction_to(object, target_player);
									a = (uint8_t)(direction >> 8);
									heading = ((uint32_t)a << 8) | 0x30u;
									vector_set_speed_by_direction(object, heading);
									vector_choose_walk_animation(object);
								}
								else
								{
									OBJECT(object)->state = 2u;
									OBJECT(object)->timer = 0u;
								}
							}
						}
						else
						{
							floor_z = OBJECT(target_player)->floor_z;
							a = (uint8_t)(floor_z >> 8);
							step = (uint8_t)floor_z;
							z = OBJECT(target_player)->z;
							if ((uint16_t)(((uint32_t)a << 8) | step) != z)
							{
								state = OBJECT(target_player)->state;
								if ((int8_t)state < 0)
								{
									OBJECT(object)->state = 2u;
									OBJECT(object)->timer = 0u;
								}
								else
								{
									timer = OBJECT(object)->timer;
									OBJECT(object)->timer = timer - 1u;
									if (timer != 1u)
									{
										direction = vector_direction_to(object, target_player);
										a = (uint8_t)(direction >> 8);
										heading = ((uint32_t)a << 8) | 0x30u;
										vector_set_speed_by_direction(object, heading);
										vector_choose_walk_animation(object);
									}
									else
									{
										OBJECT(object)->state = 2u;
										OBJECT(object)->timer = 0u;
									}
								}
							}
							else
							{
								floor_z_2 = OBJECT(object)->floor_z;
								if ((uint16_t)(((uint32_t)a << 8) | step) != floor_z_2)
								{
									state = OBJECT(target_player)->state;
									if ((int8_t)state < 0)
									{
										OBJECT(object)->state = 2u;
										OBJECT(object)->timer = 0u;
									}
									else
									{
										timer = OBJECT(object)->timer;
										OBJECT(object)->timer = timer - 1u;
										if (timer != 1u)
										{
											direction = vector_direction_to(object, target_player);
											a = (uint8_t)(direction >> 8);
											heading = ((uint32_t)a << 8) | 0x30u;
											vector_set_speed_by_direction(object, heading);
											vector_choose_walk_animation(object);
										}
										else
										{
											OBJECT(object)->state = 2u;
											OBJECT(object)->timer = 0u;
										}
									}
								}
								else
								{
									vector_enemy_leave_side(object, target_player);
									OBJECT(target_player)->player.holder = object;
									OBJECT(target_player)->player.hold_presses = 0xCu;
									OBJECT(target_player)->flags |= 0x20u;
									OBJECT(target_player)->hit = 3u;
									OBJECT(object)->x_speed = 0;
									OBJECT(object)->y_speed = 0;
									t1 = OBJECT(target_player)->x;
									OBJECT(object)->x = t1;
									t2 = OBJECT(target_player)->y;
									OBJECT(object)->y = t2;
									attributes = OBJECT(target_player)->attributes;
									grab_facing = attributes & 0x40u;
									attributes_2 = OBJECT(object)->attributes;
									OBJECT(object)->attributes = (attributes_2 & 0xBFu) | grab_facing;
									shadow_player = OBJECT(target_player)->shadow_player;
									stack = shadow_player & 0x70u;
									points = OBJECT(object)->points;
									OBJECT(object)->points = (points & 0x8Fu) | stack;
									hold_animations = goon_hold_animations_ADDRESS;
									shadow_player_2 = OBJECT(target_player)->shadow_player;
									OBJECT(object)->animation = goon_hold_animations[(((shadow_player_2 >> 1) >> 1) >> 1) >> 1] | 0x80u;
									action_step = OBJECT(object)->action_step;
									OBJECT(object)->action_step = action_step + 1u;
								}
							}
						}
					}
				}
			}
		}
	}
	*p_hold_animations = hold_animations;
	*p_target_player = target_player;
}

/* Action 0F, step 2: holds the player; the player breaking free leaves the goon 2 health less and hurt
   (reaction 2 or 3 by chance); the player beaten, done; on its turn squeezes (the next animation). */
void goon_grab_hold(uint16_t object, uint16_t *p_hold_animations, uint16_t *p_target_player, uint32_t *p_left_caller)
{
	uint16_t hold_animations = (uint16_t)*p_hold_animations;
	uint8_t vitality = 0;
	uint16_t target_player = 0, u = 0;
	uint8_t hold_presses = 0, vitality_2 = 0, vitality_3 = 0, squeeze_step = 0, squeeze_step_2 = 0, shadow_player = 0;
	uint16_t target = 0;

	OBJECT(object)->attack = 0u;
	target = OBJECT(object)->target;
	target_player = target;
	hold_presses = OBJECT(target_player)->player.hold_presses;
	if (hold_presses == 0u)
	{
		vitality_2 = OBJECT(object)->vitality;
		vitality = vitality_2 - 2u;
		OBJECT(object)->vitality = vitality;
		if ((int8_t)vitality < 0)
			OBJECT(object)->vitality = 0u;
		OBJECT(object)->attack = 0u;
		OBJECT(object)->flags = 0x88u;
		OBJECT(object)->state = 4u;
		OBJECT(object)->action = (random_number & 1u) + 2u;
		OBJECT(object)->action_step = 0u;
		*p_hold_animations = hold_animations;
		*p_target_player = u;
		vector_enemy_react(object, p_hold_animations, p_target_player, p_left_caller);
		return;
	}
	vitality_3 = OBJECT(target_player)->vitality;
	if (vitality_3 == 0u)
	{
		OBJECT(object)->state = 2u;
		OBJECT(object)->timer = 0u;
	}
	else
	{
		squeeze_step = OBJECT(object)->goon.squeeze_step;
		if (squeeze_step == 2u)
		{
			squeeze_step_2 = OBJECT(object)->goon.squeeze_step;
			OBJECT(object)->goon.squeeze_step = squeeze_step_2 + 1u;
			hold_animations = goon_hold_animations_ADDRESS;
			shadow_player = OBJECT(target_player)->shadow_player;
			OBJECT(object)->animation = (goon_hold_animations[(((shadow_player >> 1) >> 1) >> 1) >> 1] + 1u) | 0x80u;
			OBJECT(object)->action_step = 3u;
		}
	}
	*p_hold_animations = hold_animations;
	*p_target_player = target_player;
}

/* Action 0F, step 3: at the squeeze's end goes back to holding. */
void goon_grab_squeeze(uint16_t object, uint16_t *p_hold_animations, uint16_t *p_u, uint32_t *p_left_caller)
{
	uint16_t hold_animations = (uint16_t)*p_hold_animations;
	uint16_t u = 0;
	uint8_t animation_flags = 0, action_step = 0;

	animation_flags = OBJECT(object)->animation_flags;
	if (animation_flags & 1u)
	{
		OBJECT(object)->goon.squeeze_step = 1u;
		action_step = OBJECT(object)->action_step;
		OBJECT(object)->action_step = action_step - 1u;
	}
	*p_hold_animations = hold_animations;
	*p_u = u;
	goon_grab_hold(object, p_hold_animations, p_u, p_left_caller);
}

/* Action 1B, step 0: winds up (animation 91) facing its target. */
void bomb_goon_throw_start(uint16_t object)
{
	uint8_t action_step = 0;

	OBJECT(object)->animation = 0x91u;
	face_target(object);
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
}

/* Action 1B, step 1: at the animation's event throws a bomb forward. */
void bomb_goon_throw_release(uint16_t object, uint16_t *p_child_record, uint16_t *p_bomb)
{
	uint16_t child_record = (uint16_t)*p_child_record;
	uint16_t bomb = (uint16_t)*p_bomb;
	uint32_t carry = 0;
	uint8_t animation_flags = 0, action_step = 0, attributes = 0;
	uint16_t x_speed = 0;

	animation_flags = OBJECT(object)->animation_flags;
	if ((animation_flags & 2u) != 0u)
	{
		action_step = OBJECT(object)->action_step;
		OBJECT(object)->action_step = action_step + 1u;
		child_record = bomb_goon_throw_release_child_ADDRESS;
		spawn_list_2_child(object, child_record, &bomb, &carry);
		if (carry)
		{
			OBJECT(bomb)->x_speed = 0x300;
			attributes = OBJECT(object)->attributes;
			if ((attributes & 0x40u) != 0u)
			{
				x_speed = OBJECT(bomb)->x_speed;
				OBJECT(bomb)->x_speed = 0u - x_speed;
			}
		}
	}
	*p_child_record = child_record;
	*p_bomb = bomb;
}

/* Actions 14 and 33, step 0: facing its target; with the target on the floor stands (animation 80) for
   shovel_goon_close_strike_waits_by_players' wait, else a frame. */
uint16_t shovel_goon_wait_for_target(uint16_t object)
{
	uint16_t object_2 = 0, strike_waits = 0;
	uint8_t action_step = 0, action_step_2 = 0;
	uint16_t target = 0, z = 0, floor_z = 0;

	target = OBJECT(object)->target;
	object_2 = target;
	z = OBJECT(object_2)->z;
	floor_z = OBJECT(object_2)->floor_z;
	if (z != floor_z)
	{
		action_step = OBJECT(object)->action_step;
		OBJECT(object)->action_step = action_step + 1u;
		OBJECT(object)->timer = 1u;
		face_target(object);
		return object_2;
	}
	OBJECT(object)->animation = 0x80u;
	strike_waits = shovel_goon_close_strike_waits_by_players_ADDRESS;
	OBJECT(object)->timer = shovel_goon_close_strike_waits_by_players[(int8_t)player_count];
	action_step_2 = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step_2 + 1u;
	face_target(object);
	return strike_waits;
}

/* Action 33, step 1: after its wait strikes (animation 92). */
void shovel_goon_close_swing(uint16_t object)
{
	uint8_t timer = 0, action_step = 0;

	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer != 1u)
		return;
	OBJECT(object)->animation = 0x92u;
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
	face_target(object);
}

/* Action 33, step 2: at the animation's event the shovel's hit box (7E8F). */
uint16_t shovel_goon_close_hit(uint16_t object, uint16_t box)
{
	uint8_t animation_flags = 0, action_step = 0;

	animation_flags = OBJECT(object)->animation_flags;
	if ((animation_flags & 2u) == 0u)
		return box;
	box = shovel_goon_close_hit_box_ADDRESS;
	vector_set_hit_box(object, box);
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
	return box;
}

/* Action 15, step 0: stands (animation 80) facing its target for
   shovel_goon_far_strike_waits_by_players' wait. */
uint16_t shovel_goon_far_wait(uint16_t object)
{
	uint16_t strike_waits = 0;
	uint8_t action_step = 0;

	OBJECT(object)->animation = 0x80u;
	strike_waits = shovel_goon_far_strike_waits_by_players_ADDRESS;
	OBJECT(object)->timer = shovel_goon_far_strike_waits_by_players[(int8_t)player_count];
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
	face_target(object);
	return strike_waits;
}

/* Action 15, step 1: after its wait strikes (animation 91). */
void shovel_goon_far_swing(uint16_t object)
{
	uint8_t timer = 0, action_step = 0;

	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer == 1u)
	{
		OBJECT(object)->animation = 0x91u;
		action_step = OBJECT(object)->action_step;
		OBJECT(object)->action_step = action_step + 1u;
	}
}

/* Action 15, step 2: at the animation's event the long shovel's hit box (7E9F). */
uint16_t shovel_goon_far_hit(uint16_t object, uint16_t box)
{
	uint8_t animation_flags = 0, action_step = 0;

	animation_flags = OBJECT(object)->animation_flags;
	if ((animation_flags & 2u) == 0u)
		return box;
	box = shovel_goon_far_hit_box_ADDRESS;
	vector_set_hit_box(object, box);
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
	return box;
}

/* An armed goon's strike's end: back to its body's hit box (7E87), done at the animation's end. */
uint16_t armed_goon_strike_recover(uint16_t object)
{
	uint16_t box = 0;
	uint8_t action_step = 0;

	box = armed_goon_body_box_ADDRESS;
	vector_set_hit_box(object, box);
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
	armed_goon_action_end(object);
	return box;
}

/* Done at the animation's end. */
void armed_goon_action_end(uint16_t object)
{
	uint8_t animation_flags = 0;

	animation_flags = OBJECT(object)->animation_flags;
	if ((animation_flags & 1u) == 0u)
		return;
	OBJECT(object)->state = 2u;
	OBJECT(object)->timer = 0u;
}

/* Action 14, step 1: after its wait strikes (animation A0). */
void shovel_goon_swing(uint16_t object)
{
	uint8_t timer = 0, action_step = 0;

	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer != 1u)
		return;
	OBJECT(object)->animation = 0xA0u;
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
	face_target(object);
}

/* Action 14, step 2: at the animation's event the shovel's hit box (7E97). */
uint16_t shovel_goon_hit(uint16_t object, uint16_t box)
{
	uint8_t animation_flags = 0, action_step = 0;

	animation_flags = OBJECT(object)->animation_flags;
	if ((animation_flags & 2u) == 0u)
		return box;
	box = shovel_goon_hit_box_ADDRESS;
	vector_set_hit_box(object, box);
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
	return box;
}

/* Action 16, step 0: strikes (animation 91) facing its target. */
void umbrella_goon_quick_swing(uint16_t object)
{
	uint8_t action_step = 0;

	OBJECT(object)->animation = 0x91u;
	face_target(object);
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
}

/* Action 16, step 1: at the animation's event the umbrella's hit box (7EBF). */
uint16_t umbrella_goon_quick_hit(uint16_t object, uint16_t box)
{
	uint8_t animation_flags = 0, action_step = 0;

	animation_flags = OBJECT(object)->animation_flags;
	if ((animation_flags & 2u) == 0u)
		return box;
	box = umbrella_goon_quick_hit_box_ADDRESS;
	vector_set_hit_box(object, box);
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
	return box;
}

/* Action 13, step 0: strikes (animation 92) facing its target. */
void umbrella_goon_long_swing(uint16_t object)
{
	uint8_t action_step = 0;

	OBJECT(object)->animation = 0x92u;
	face_target(object);
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
}

/* Action 13, step 1: at the animation's event the umbrella's hit box (7EC7), held for 10 frames. */
uint16_t umbrella_goon_long_hit(uint16_t object, uint16_t box)
{
	uint8_t animation_flags = 0, action_step = 0;

	animation_flags = OBJECT(object)->animation_flags;
	if ((animation_flags & 2u) == 0u)
		return box;
	box = umbrella_goon_long_hit_box_ADDRESS;
	vector_set_hit_box(object, box);
	OBJECT(object)->timer = 0x10u;
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
	return box;
}

/* Action 13, step 2: after its time back to its body's hit box, animation A5. */
uint16_t umbrella_goon_long_recover(uint16_t object, uint16_t box)
{
	uint8_t timer = 0, action_step = 0;

	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer != 1u)
		return box;
	box = armed_goon_body_box_ADDRESS;
	vector_set_hit_box(object, box);
	OBJECT(object)->animation = 0xA5u;
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
	return box;
}

/* Action 13, step 3: done. */
void umbrella_goon_long_end(uint16_t object)
{
	OBJECT(object)->state = 2u;
	OBJECT(object)->timer = 0u;
}

/* Action 11, step 0: strikes (animation A0) facing its target. */
void umbrella_goon_swing(uint16_t object)
{
	uint8_t action_step = 0;

	OBJECT(object)->animation = 0xA0u;
	face_target(object);
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
}

/* Action 11, step 1: at the animation's event the umbrella's hit box (7EAF). */
uint16_t umbrella_goon_hit(uint16_t object, uint16_t box)
{
	uint8_t animation_flags = 0, action_step = 0;

	animation_flags = OBJECT(object)->animation_flags;
	if ((animation_flags & 2u) == 0u)
		return box;
	box = umbrella_goon_hit_box_ADDRESS;
	vector_set_hit_box(object, box);
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
	return box;
}

/* Action 12, step 0: faces its target and starts running (animation 90) for 8 frames. */
void umbrella_goon_charge_start(uint16_t object)
{
	uint8_t action_step = 0;

	face_target(object);
	OBJECT(object)->animation = 0x90u;
	OBJECT(object)->timer = 8u;
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
}

/* Action 12, step 1: after 8 frames puts the umbrella's hit box (7EB7) out and runs through. */
uint16_t umbrella_goon_charge_hit(uint16_t object, uint16_t y)
{
	uint16_t box = 0;
	uint8_t timer = 0;

	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer != 1u)
		return y;
	box = umbrella_goon_charge_hit_box_ADDRESS;
	vector_set_hit_box(object, box);
	goon_run_through(object);
	return box;
}

/* Runs on the way it faces for 8 frames plus an eighth of the x distance to its target. */
void goon_run_through(uint16_t object)
{
	uint8_t t1 = 0, attributes = 0, action_step = 0;
	uint16_t x_speed = 0;

	t1 = (uint8_t)OBJECT(object)->target_dx;
	OBJECT(object)->timer = (((t1 >> 1) >> 1) >> 1) + 8u;
	OBJECT(object)->y_speed = 0;
	OBJECT(object)->x_speed = 0x200;
	attributes = OBJECT(object)->attributes;
	if ((attributes & 0x40u) != 0u)
	{
		x_speed = OBJECT(object)->x_speed;
		OBJECT(object)->x_speed = 0u - x_speed;
	}
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
}

/* After its run back to its body's hit box, done. */
uint16_t goon_run_through_end(uint16_t object, uint16_t y)
{
	uint16_t box = 0;
	uint8_t timer = 0;

	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer != 1u)
		return y;
	box = armed_goon_body_box_ADDRESS;
	vector_set_hit_box(object, box);
	OBJECT(object)->state = 2u;
	OBJECT(object)->timer = 0u;
	return box;
}

/* Action 07, step 0: strikes (animation A4) facing its target. */
void goon_strike_and_run_swing(uint16_t object)
{
	uint8_t action_step = 0;

	face_target(object);
	OBJECT(object)->animation = 0xA4u;
	OBJECT(object)->timer = 8u;
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
}

/* Action 07, step 1: after 8 frames its strike's hit box (7EA7), and runs through. */
uint16_t goon_strike_and_run_hit(uint16_t object, uint16_t y)
{
	uint16_t box = 0;
	uint8_t timer = 0;

	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer != 1u)
		return y;
	box = goon_strike_and_run_hit_box_ADDRESS;
	vector_set_hit_box(object, box);
	goon_run_through(object);
	return box;
}

/* Action 06, step 0: winds up (animation AB) facing its target. */
void hat_goon_throw_start(uint16_t object)
{
	uint8_t action_step = 0;

	OBJECT(object)->animation = 0xABu;
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
	face_target(object);
}

/* Action 06, step 1: at the animation's event throws its hat (list 2 type 02) and keeps it in field 40;
   no room, done. */
void hat_goon_throw_release(uint16_t object, uint16_t *p_child_record, uint16_t *p_hat)
{
	uint16_t child_record = (uint16_t)*p_child_record;
	uint16_t hat = (uint16_t)*p_hat;
	uint32_t carry = 0;
	uint8_t animation_flags = 0, action_step = 0;

	animation_flags = OBJECT(object)->animation_flags;
	if ((animation_flags & 2u) != 0u)
	{
		child_record = hat_goon_throw_release_child_ADDRESS;
		spawn_list_2_child(object, child_record, &hat, &carry);
		if (carry == 0u)
		{
			OBJECT(object)->state = 2u;
			OBJECT(object)->timer = 0u;
		}
		else
		{
			OBJECT(object)->hat_goon_throw.hat = hat;
			OBJECT(object)->timer = 0x30u;
			action_step = OBJECT(object)->action_step;
			OBJECT(object)->action_step = action_step + 1u;
		}
	}
	*p_child_record = child_record;
	*p_hat = hat;
}

/* Action 06, step 2: done once the hat is gone; after 30 frames catches it (animation AC). */
uint16_t hat_goon_throw_wait(uint16_t object)
{
	uint16_t object_2 = 0;
	uint8_t timer = 0, action_step = 0;
	uint16_t hat = 0;

	hat = OBJECT(object)->hat_goon_throw.hat;
	object_2 = hat;
	if (OBJECT(object_2)->flags == 0u)
	{
		OBJECT(object)->state = 2u;
		OBJECT(object)->timer = 0u;
		return object_2;
	}
	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer == 1u)
	{
		OBJECT(object)->animation = 0xACu;
		action_step = OBJECT(object)->action_step;
		OBJECT(object)->action_step = action_step + 1u;
	}
	return object_2;
}

/* Action 06, step 3: done at the animation's end. */
void hat_goon_throw_end(uint16_t object)
{
	uint8_t animation_flags = 0;

	animation_flags = OBJECT(object)->animation_flags;
	if ((animation_flags & 1u) == 0u)
		return;
	OBJECT(object)->state = 2u;
	OBJECT(object)->timer = 0u;
}
