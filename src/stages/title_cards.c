/**
 *    Name:        stages/title_cards.c
 *    Description: the stages' title cards
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    09-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the game's 053248 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

/* A stage step's first substep: the title card of the scene's stage, or none for the stories' scenes,
   the cemetery and the attract's demo. */
void stage_title_card(uint16_t u)
{
	uint16_t ignored16 = 0, ignored16_2 = 0, object = 0;

	gauges_shown = 0u;
	if (in_attract != 0u)
	{
		start_player_colour_cycles(&ignored16, &u);
		step_subphase = 0u;
		step_phase++;
		return;
	}
	object = title_cards_by_scene_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)scene << 1))
	{
	case 0:
		stage_1_title_card(&ignored16_2, &ignored16, &u);
		return;
	case 2:
		stage_2_title_card(&ignored16_2, &ignored16, &u);
		return;
	case 4:
	case 8:
	case 14:
	case 20:
		title_card_none(&ignored16, &u);
		return;
	case 6:
		stage_3_title_card(&ignored16_2, &ignored16, &u);
		return;
	case 10:
		stage_4_title_card(&ignored16_2, &ignored16, &u);
		return;
	case 12:
		stage_5_title_card(&ignored16_2, &ignored16, &u);
		return;
	case 16:
		stage_6_title_card(&ignored16_2, &ignored16, &u);
		return;
	case 18:
		stage_7_title_card(&ignored16_2, &ignored16, &u);
		return;
	case 22:
		stage_8_title_card(&ignored16_2, &ignored16, &u);
		return;
	case 24:
		stage_1_title_sound();
		return;
	case 26:
		stage_1_title_show(&ignored16_2, &ignored16, &u);
		return;
	case 28:
	case 52:
	case 58:
	case 66:
	case 72:
		title_card_count_frames();
		return;
	case 30:
	case 42:
		title_card_ready_screen();
		return;
	case 32:
		stage_2_title_show(&ignored16_2, &ignored16, &u);
		return;
	case 34:
		stage_2_title_picture_sound();
		return;
	case 36:
		stage_3_title_ready_screen();
		return;
	case 38:
		stage_3_title_show(&ignored16_2, &ignored16, &u);
		return;
	case 40:
		stage_3_title_picture_sound();
		return;
	case 44:
		stage_4_title_show(&ignored16_2, &ignored16, &u);
		return;
	case 46:
		stage_4_title_picture_sound();
		return;
	case 48:
		stage_5_title_ready_screen();
		return;
	case 50:
		stage_5_title_show(&ignored16_2, &ignored16, &u);
		return;
	case 54:
		stage_6_title_sound();
		return;
	case 56:
		stage_6_title_show(&ignored16_2, &ignored16, &u);
		return;
	case 60:
		stage_7_title_sound();
		return;
	case 62:
		stage_7_title_show(&ignored16_2, &ignored16, &u);
		return;
	case 64:
		stage_7_title_second_picture(&ignored16_2, &ignored16);
		return;
	case 68:
		stage_8_title_sound();
		return;
	case 70:
		stage_8_title_show(&ignored16_2, &ignored16, &u);
		return;
	case -10:
		krusty_balloon_shot_vanish(object);
		return;
	case -8:
		krusty_balloon_shot_fly(object);
		return;
	case -6:
		krusty_balloon_shot_drift(object);
		return;
	case -4:
		krusty_balloon_shot_open(object);
		return;
	case -2:
		krusty_balloon_shot_fall(object);
		return;
	}
}

/* The bank's entry for the steps without a title card: starts the players' colour cycles. */
void stage_start_colour_cycles(uint16_t palette_job)
{
	uint16_t ignored16 = 0;

	start_player_colour_cycles(&ignored16, &palette_job);
}

/* No title card: starts the players' colour cycles and ends the substep. */
void title_card_none(uint16_t *p_y, uint16_t *p_palette_job)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t palette_job = (uint16_t)*p_palette_job;

	start_player_colour_cycles(&y, &palette_job);
	step_subphase = 0u;
	step_phase++;
	*p_y = y;
	*p_palette_job = palette_job;
}

/* Stage 1's title card for C0 frames, or until a player presses a button after 40: runs its step
   (title_card_step). */
void stage_1_title_card(uint16_t *p_x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t x = (uint16_t)*p_x;
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = (uint16_t)*p_u;
	uint32_t carry = 0;
	uint16_t wait = 0;

	for (;;)
	{
		step_subphase++;
		if (step_subphase == 0xC0u)
		{
			title_card_end(&x, &y, &u);
			break;
		}
		wait = 0x4000u;
		vector_check_skip(wait, &x, &carry);
		if (carry)
		{
			title_card_end(&x, &y, &u);
			break;
		}
		x = stage_1_title_card_steps_ADDRESS;
		switch ((int8_t)(uint8_t)((uint32_t)title_card_step << 1))
		{
		case 0:
			stage_1_title_sound();
			break;
		case 2:
			stage_1_title_show(&x, &y, &u);
			break;
		case 4:
		case 28:
		case 34:
		case 42:
		case 48:
			x = title_card_count_frames();
			break;
		case 6:
		case 18:
			title_card_ready_screen();
			break;
		case 8:
			stage_2_title_show(&x, &y, &u);
			break;
		case 10:
			x = stage_2_title_picture_sound();
			break;
		case 12:
			stage_3_title_ready_screen();
			break;
		case 14:
			stage_3_title_show(&x, &y, &u);
			break;
		case 16:
			x = stage_3_title_picture_sound();
			break;
		case 20:
			stage_4_title_show(&x, &y, &u);
			break;
		case 22:
			x = stage_4_title_picture_sound();
			break;
		case 24:
			stage_5_title_ready_screen();
			break;
		case 26:
			stage_5_title_show(&x, &y, &u);
			break;
		case 30:
			stage_6_title_sound();
			break;
		case 32:
			stage_6_title_show(&x, &y, &u);
			break;
		case 36:
			stage_7_title_sound();
			break;
		case 38:
			stage_7_title_show(&x, &y, &u);
			break;
		case 40:
			stage_7_title_second_picture(&x, &y);
			break;
		case 44:
			stage_8_title_sound();
			break;
		case 46:
			stage_8_title_show(&x, &y, &u);
			break;
		case -34:
			krusty_balloon_shot_vanish(x);
			break;
		case -32:
			krusty_balloon_shot_fly(x);
			break;
		case -30:
			krusty_balloon_shot_drift(x);
			break;
		case -28:
			krusty_balloon_shot_open(x);
			break;
		case -26:
			krusty_balloon_shot_fall(x);
			break;
		case -24:
			continue;
		case -22:
			stage_2_title_card(&x, &y, &u);
			break;
		case -20:
		case -16:
		case -10:
		case -4:
			title_card_none(&y, &u);
			break;
		case -18:
			stage_3_title_card(&x, &y, &u);
			break;
		case -14:
			stage_4_title_card(&x, &y, &u);
			break;
		case -12:
			stage_5_title_card(&x, &y, &u);
			break;
		case -8:
			stage_6_title_card(&x, &y, &u);
			break;
		case -6:
			stage_7_title_card(&x, &y, &u);
			break;
		case -2:
			stage_8_title_card(&x, &y, &u);
			break;
		}
		break;
	}
	*p_x = x;
	*p_y = y;
	*p_u = u;
}

/* Stage 1's card, step 0: queues sound 5400 and readies the screen. */
void stage_1_title_sound(void)
{
	uint32_t carry = 0;
	uint16_t command = 0;

	command = 0x5400u;
	carry = vector_queue_sound(command);
	title_card_ready_screen();
}

/* Stage 8's card, step 0: queues sound 5800 and readies the screen. */
void stage_8_title_sound(void)
{
	uint32_t carry = 0;
	uint16_t command = 0;

	command = 0x5800u;
	carry = vector_queue_sound(command);
	title_card_ready_screen();
}

/* Stage 7's card, step 0: queues sound 5700 and readies the screen. */
void stage_7_title_sound(void)
{
	uint32_t carry = 0;
	uint16_t command = 0;

	command = 0x5700u;
	carry = vector_queue_sound(command);
	title_card_ready_screen();
}

/* Queues sound 5600 (stage 5's card) and readies the screen. */
void stage_5_title_sound(void)
{
	uint32_t carry = 0;
	uint16_t command = 0;

	command = 0x5600u;
	carry = vector_queue_sound(command);
	title_card_ready_screen();
}

/* Stage 6's card, step 0: queues sound 3003 and readies the screen. */
void stage_6_title_sound(void)
{
	uint32_t carry = 0;
	uint16_t command = 0;

	command = 0x3003u;
	carry = vector_queue_sound(command);
	title_card_ready_screen();
}

/* Puts the layers and the camera at x FFF0, y 0, queues job 1 (counted in direct page 5D, which the next
   step waits for) and goes on. */
void title_card_ready_screen(void)
{
	uint16_t job = 0, scroll_x = 0, scroll_y = 0;

	scroll_x = 0xFFF0u;
	vector_set_scroll_x(scroll_x);
	scroll_y = 0u;
	vector_set_scroll_y(scroll_y);
	job = 1u;
	vector_queue_job(job);
	title_card_step++;
}

/* Stage 1's card, step 1: once the screen job is done, sets up the card's screen, prints "STAGE 1 /
   DOWNTOWN SPRINGFIELD" and puts in its picture (sliding left) and the card's object of kind 0F (4DA0). */
void stage_1_title_show(uint16_t *p_x, uint16_t *p_object, uint16_t *p_text)
{
	uint16_t x = (uint16_t)*p_x;
	uint16_t object = (uint16_t)*p_object;
	uint16_t text = (uint16_t)*p_text;
	uint16_t colour = 0, record_number = 0, x_2 = 0;

	if (layer_clear_pending != 0u)
		return;
	title_card_load_palettes(text);
	title_card_set_up_screen();
	text = stage_1_title_text_ADDRESS;
	colour = 0u;
	vector_print_text(colour, &x_2, &text);
	record_number = 0u;
	object = title_card_put_picture(record_number);
	OBJECT(object)->x_speed = -0x200;
	record_number = 0x900u;
	object = title_card_put_picture(record_number);
	OBJECT(object)->attributes = 0u;
	title_card_step++;
	*p_x = x_2;
	*p_object = object;
	*p_text = text;
}

/* Stage 3's card, step 2: queues sound 5500 at its picture's animation event, then counts the card's
   frames (title_card_count_frames). */
uint16_t stage_3_title_picture_sound(void)
{
	uint32_t carry = 0;
	uint16_t command = 0;

	if ((OBJECT(OBJECT_ADDRESS(8))->animation_flags & 2u) == 0u)
		return title_card_count_frames();
	command = 0x5500u;
	carry = vector_queue_sound(command);
	return title_card_count_frames();
}

/* Stage 4's card, step 2: queues sound 2C02 at its picture's animation event, then counts the card's
   frames (title_card_count_frames). */
uint16_t stage_4_title_picture_sound(void)
{
	uint32_t carry = 0;
	uint16_t command = 0;

	if ((OBJECT(OBJECT_ADDRESS(8))->animation_flags & 2u) == 0u)
		return title_card_count_frames();
	command = 0x2C02u;
	carry = vector_queue_sound(command);
	return title_card_count_frames();
}

/* Stage 2's card, step 2: queues sound 0F00 at its picture's animation event, then counts the card's
   frames (title_card_count_frames). */
uint16_t stage_2_title_picture_sound(void)
{
	uint32_t carry = 0;
	uint16_t command = 0;

	if ((OBJECT(OBJECT_ADDRESS(8))->animation_flags & 2u) == 0u)
		return title_card_count_frames();
	command = 0xF00u;
	carry = vector_queue_sound(command);
	return title_card_count_frames();
}

/* The cards' last step: sets the layers' priorities and counts the frames in the 4DA0 object's field 28
   in its field 28: past 40 sets its field 06 bit 6, at A0 queues sound 0700. */
uint16_t title_card_count_frames(void)
{
	uint32_t carry = 0;
	uint8_t action = 0;
	uint16_t command = 0, object = 0;
	uint8_t action_2 = 0, action_3 = 0, action_4 = 0, animation_flags = 0;

	io_write8(0x1FB9u, 0x13u);
	io_write8(0x1FBAu, 0x2Cu);
	object = OBJECT_ADDRESS(9);
	action = OBJECT(OBJECT_ADDRESS(9))->action;
	if (action <= 0x40u)
	{
		action_2 = OBJECT(object)->action;
		OBJECT(object)->action = action_2 + 1u;
		return object;
	}
	if (action == 0xA0u)
	{
		action_3 = OBJECT(object)->action;
		OBJECT(object)->action = action_3 + 1u;
		command = 0x700u;
		carry = vector_queue_sound(command);
		return object;
	}
	if (action >= 0xA0u)
		return object;
	action_4 = OBJECT(object)->action;
	OBJECT(object)->action = action_4 + 1u;
	animation_flags = OBJECT(object)->animation_flags;
	OBJECT(object)->animation_flags = animation_flags | 0x40u;
	return object;
}

/* Stage 2's title card for C0 frames, or until a player presses a button after 40: runs its step. */
void stage_2_title_card(uint16_t *p_x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t x = (uint16_t)*p_x;
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = (uint16_t)*p_u;
	uint32_t carry = 0;
	uint16_t wait = 0;

	for (;;)
	{
		step_subphase++;
		if (step_subphase == 0xC0u)
		{
			title_card_end(&x, &y, &u);
			break;
		}
		wait = 0x4000u;
		vector_check_skip(wait, &x, &carry);
		if (carry)
		{
			title_card_end(&x, &y, &u);
			break;
		}
		x = stage_2_title_card_steps_ADDRESS;
		switch ((int8_t)(uint8_t)((uint32_t)title_card_step << 1))
		{
		case 0:
		case 12:
			title_card_ready_screen();
			break;
		case 2:
			stage_2_title_show(&x, &y, &u);
			break;
		case 4:
			x = stage_2_title_picture_sound();
			break;
		case 6:
			stage_3_title_ready_screen();
			break;
		case 8:
			stage_3_title_show(&x, &y, &u);
			break;
		case 10:
			x = stage_3_title_picture_sound();
			break;
		case 14:
			stage_4_title_show(&x, &y, &u);
			break;
		case 16:
			x = stage_4_title_picture_sound();
			break;
		case 18:
			stage_5_title_ready_screen();
			break;
		case 20:
			stage_5_title_show(&x, &y, &u);
			break;
		case -2:
		case 22:
		case 28:
		case 36:
		case 42:
			x = title_card_count_frames();
			break;
		case 24:
			stage_6_title_sound();
			break;
		case 26:
			stage_6_title_show(&x, &y, &u);
			break;
		case 30:
			stage_7_title_sound();
			break;
		case 32:
			stage_7_title_show(&x, &y, &u);
			break;
		case 34:
			stage_7_title_second_picture(&x, &y);
			break;
		case 38:
			stage_8_title_sound();
			break;
		case 40:
			stage_8_title_show(&x, &y, &u);
			break;
		case -40:
			krusty_balloon_shot_vanish(x);
			break;
		case -38:
			krusty_balloon_shot_fly(x);
			break;
		case -36:
			krusty_balloon_shot_drift(x);
			break;
		case -34:
			krusty_balloon_shot_open(x);
			break;
		case -32:
			krusty_balloon_shot_fall(x);
			break;
		case -30:
			stage_1_title_card(&x, &y, &u);
			break;
		case -28:
			continue;
		case -26:
		case -22:
		case -16:
		case -10:
			title_card_none(&y, &u);
			break;
		case -24:
			stage_3_title_card(&x, &y, &u);
			break;
		case -20:
			stage_4_title_card(&x, &y, &u);
			break;
		case -18:
			stage_5_title_card(&x, &y, &u);
			break;
		case -14:
			stage_6_title_card(&x, &y, &u);
			break;
		case -12:
			stage_7_title_card(&x, &y, &u);
			break;
		case -8:
			stage_8_title_card(&x, &y, &u);
			break;
		case -6:
			stage_1_title_sound();
			break;
		case -4:
			stage_1_title_show(&x, &y, &u);
			break;
		}
		break;
	}
	*p_x = x;
	*p_y = y;
	*p_u = u;
}

/* Stage 2's card, step 1: sets up the card's screen, prints "STAGE 2 / KRUSTYLAND" and puts in its
   picture and the card's object of kind 0F (4DA0). */
void stage_2_title_show(uint16_t *p_x, uint16_t *p_object, uint16_t *p_text)
{
	uint16_t x = (uint16_t)*p_x;
	uint16_t object = (uint16_t)*p_object;
	uint16_t text = (uint16_t)*p_text;
	uint16_t colour = 0, record_number = 0, x_2 = 0;

	if (layer_clear_pending != 0u)
		return;
	title_card_load_palettes(text);
	title_card_set_up_screen();
	text = stage_2_title_text_ADDRESS;
	colour = 0u;
	vector_print_text(colour, &x_2, &text);
	record_number = 0x100u;
	title_card_put_picture(record_number);
	record_number = 0x900u;
	object = title_card_put_picture(record_number);
	OBJECT(object)->attributes = 0u;
	title_card_step++;
	*p_x = x_2;
	*p_object = object;
	*p_text = text;
}

/* Stage 3's title card for C0 frames, or until a player presses a button after 40: runs its step. */
void stage_3_title_card(uint16_t *p_x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t x = (uint16_t)*p_x;
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = (uint16_t)*p_u;
	uint32_t carry = 0;
	uint16_t wait = 0;

	for (;;)
	{
		step_subphase++;
		if (step_subphase == 0xC0u)
		{
			title_card_end(&x, &y, &u);
			break;
		}
		wait = 0x4000u;
		vector_check_skip(wait, &x, &carry);
		if (carry)
		{
			title_card_end(&x, &y, &u);
			break;
		}
		x = stage_3_title_card_steps_ADDRESS;
		switch ((int8_t)(uint8_t)((uint32_t)title_card_step << 1))
		{
		case 0:
			stage_3_title_ready_screen();
			break;
		case 2:
			stage_3_title_show(&x, &y, &u);
			break;
		case 4:
			x = stage_3_title_picture_sound();
			break;
		case -6:
		case 6:
			title_card_ready_screen();
			break;
		case 8:
			stage_4_title_show(&x, &y, &u);
			break;
		case 10:
			x = stage_4_title_picture_sound();
			break;
		case 12:
			stage_5_title_ready_screen();
			break;
		case 14:
			stage_5_title_show(&x, &y, &u);
			break;
		case -8:
		case 16:
		case 22:
		case 30:
		case 36:
			x = title_card_count_frames();
			break;
		case 18:
			stage_6_title_sound();
			break;
		case 20:
			stage_6_title_show(&x, &y, &u);
			break;
		case 24:
			stage_7_title_sound();
			break;
		case 26:
			stage_7_title_show(&x, &y, &u);
			break;
		case 28:
			stage_7_title_second_picture(&x, &y);
			break;
		case 32:
			stage_8_title_sound();
			break;
		case 34:
			stage_8_title_show(&x, &y, &u);
			break;
		case -46:
			krusty_balloon_shot_vanish(x);
			break;
		case -44:
			krusty_balloon_shot_fly(x);
			break;
		case -42:
			krusty_balloon_shot_drift(x);
			break;
		case -40:
			krusty_balloon_shot_open(x);
			break;
		case -38:
			krusty_balloon_shot_fall(x);
			break;
		case -36:
			stage_1_title_card(&x, &y, &u);
			break;
		case -34:
			stage_2_title_card(&x, &y, &u);
			break;
		case -32:
		case -28:
		case -22:
		case -16:
			title_card_none(&y, &u);
			break;
		case -30:
			continue;
		case -26:
			stage_4_title_card(&x, &y, &u);
			break;
		case -24:
			stage_5_title_card(&x, &y, &u);
			break;
		case -20:
			stage_6_title_card(&x, &y, &u);
			break;
		case -18:
			stage_7_title_card(&x, &y, &u);
			break;
		case -14:
			stage_8_title_card(&x, &y, &u);
			break;
		case -12:
			stage_1_title_sound();
			break;
		case -10:
			stage_1_title_show(&x, &y, &u);
			break;
		case -4:
			stage_2_title_show(&x, &y, &u);
			break;
		case -2:
			x = stage_2_title_picture_sound();
			break;
		}
		break;
	}
	*p_x = x;
	*p_y = y;
	*p_u = u;
}

/* Stage 3's card, step 0: readies the screen with layer A's y scroll at 20. */
void stage_3_title_ready_screen(void)
{
	title_card_ready_screen();
	layer_a_scroll_y = 0x20u;
}

/* Stage 3's card, step 1: sets up the card's screen over the forest's area 1 (scene 86) drawn on layer
   A, prints "STAGE 3 / SPRINGFIELD / DISCOUNT CEMETERY" and puts in its picture and the card's object of
   kind 0F (4DA0). */
void stage_3_title_show(uint16_t *p_x, uint16_t *p_object, uint16_t *p_text)
{
	uint16_t x = (uint16_t)*p_x;
	uint16_t object = (uint16_t)*p_object;
	uint16_t text = (uint16_t)*p_text;
	uint16_t d = 0, ignored16 = 0, ignored16_2 = 0, ignored16_3 = 0, record_number = 0, x_2 = 0;

	if (layer_clear_pending != 0u)
		return;
	title_card_load_palettes(text);
	title_card_set_up_screen();
	map_scene = 0x86u;
	map_area = 1u;
	vector_set_layer_modes();
	d = 0x2Cu;
	vector_draw_layer_strips(d, &ignored16, &ignored16_2, &ignored16_3);
	text = stage_3_title_text_ADDRESS;
	vector_print_text(d, &x_2, &text);
	d |= 0x200u;
	title_card_put_picture(d);
	record_number = (d & 0xFFu) | 0x900u;
	object = title_card_put_picture(record_number);
	OBJECT(object)->attributes = 0u;
	title_card_step++;
	*p_x = x_2;
	*p_object = object;
	*p_text = text;
}

/* Stage 4's title card for C0 frames, or until a player presses a button after 40: runs its step. */
void stage_4_title_card(uint16_t *p_x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t x = (uint16_t)*p_x;
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = (uint16_t)*p_u;
	uint32_t carry = 0;
	uint16_t wait = 0;

	for (;;)
	{
		step_subphase++;
		if (step_subphase == 0xC0u)
		{
			title_card_end(&x, &y, &u);
			break;
		}
		wait = 0x4000u;
		vector_check_skip(wait, &x, &carry);
		if (carry)
		{
			title_card_end(&x, &y, &u);
			break;
		}
		x = stage_4_title_card_steps_ADDRESS;
		switch ((int8_t)(uint8_t)((uint32_t)title_card_step << 1))
		{
		case -12:
		case 0:
			title_card_ready_screen();
			break;
		case 2:
			stage_4_title_show(&x, &y, &u);
			break;
		case 4:
			x = stage_4_title_picture_sound();
			break;
		case 6:
			stage_5_title_ready_screen();
			break;
		case 8:
			stage_5_title_show(&x, &y, &u);
			break;
		case -14:
		case 10:
		case 16:
		case 24:
		case 30:
			x = title_card_count_frames();
			break;
		case 12:
			stage_6_title_sound();
			break;
		case 14:
			stage_6_title_show(&x, &y, &u);
			break;
		case 18:
			stage_7_title_sound();
			break;
		case 20:
			stage_7_title_show(&x, &y, &u);
			break;
		case 22:
			stage_7_title_second_picture(&x, &y);
			break;
		case 26:
			stage_8_title_sound();
			break;
		case 28:
			stage_8_title_show(&x, &y, &u);
			break;
		case -52:
			krusty_balloon_shot_vanish(x);
			break;
		case -50:
			krusty_balloon_shot_fly(x);
			break;
		case -48:
			krusty_balloon_shot_drift(x);
			break;
		case -46:
			krusty_balloon_shot_open(x);
			break;
		case -44:
			krusty_balloon_shot_fall(x);
			break;
		case -42:
			stage_1_title_card(&x, &y, &u);
			break;
		case -40:
			stage_2_title_card(&x, &y, &u);
			break;
		case -38:
		case -34:
		case -28:
		case -22:
			title_card_none(&y, &u);
			break;
		case -36:
			stage_3_title_card(&x, &y, &u);
			break;
		case -32:
			continue;
		case -30:
			stage_5_title_card(&x, &y, &u);
			break;
		case -26:
			stage_6_title_card(&x, &y, &u);
			break;
		case -24:
			stage_7_title_card(&x, &y, &u);
			break;
		case -20:
			stage_8_title_card(&x, &y, &u);
			break;
		case -18:
			stage_1_title_sound();
			break;
		case -16:
			stage_1_title_show(&x, &y, &u);
			break;
		case -10:
			stage_2_title_show(&x, &y, &u);
			break;
		case -8:
			x = stage_2_title_picture_sound();
			break;
		case -6:
			stage_3_title_ready_screen();
			break;
		case -4:
			stage_3_title_show(&x, &y, &u);
			break;
		case -2:
			x = stage_3_title_picture_sound();
			break;
		}
		break;
	}
	*p_x = x;
	*p_y = y;
	*p_u = u;
}

/* Stage 4's card, step 1: sets up the card's screen, prints "STAGE 4 / MOE'S TAVERN" and puts in its
   picture and the card's object of kind 0F (4DA0). */
void stage_4_title_show(uint16_t *p_x, uint16_t *p_object, uint16_t *p_text)
{
	uint16_t x = (uint16_t)*p_x;
	uint16_t object = (uint16_t)*p_object;
	uint16_t text = (uint16_t)*p_text;
	uint16_t colour = 0, record_number = 0, x_2 = 0;

	if (layer_clear_pending != 0u)
		return;
	title_card_load_palettes(text);
	title_card_set_up_screen();
	text = stage_4_title_text_ADDRESS;
	colour = 0u;
	vector_print_text(colour, &x_2, &text);
	record_number = 0x300u;
	title_card_put_picture(record_number);
	record_number = 0x900u;
	object = title_card_put_picture(record_number);
	OBJECT(object)->attributes = 0u;
	title_card_step++;
	*p_x = x_2;
	*p_object = object;
	*p_text = text;
}

/* Stage 5's title card for C0 frames, or until a player presses a button after 40: runs its step. */
void stage_5_title_card(uint16_t *p_x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t x = (uint16_t)*p_x;
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = (uint16_t)*p_u;
	uint32_t carry = 0;
	uint16_t wait = 0;

	for (;;)
	{
		step_subphase++;
		if (step_subphase == 0xC0u)
		{
			title_card_end(&x, &y, &u);
			break;
		}
		wait = 0x4000u;
		vector_check_skip(wait, &x, &carry);
		if (carry)
		{
			title_card_end(&x, &y, &u);
			break;
		}
		x = stage_5_title_card_steps_ADDRESS;
		switch ((int8_t)(uint8_t)((uint32_t)title_card_step << 1))
		{
		case 0:
			stage_5_title_ready_screen();
			break;
		case 2:
			stage_5_title_show(&x, &y, &u);
			break;
		case -20:
		case 4:
		case 10:
		case 18:
		case 24:
			x = title_card_count_frames();
			break;
		case 6:
			stage_6_title_sound();
			break;
		case 8:
			stage_6_title_show(&x, &y, &u);
			break;
		case 12:
			stage_7_title_sound();
			break;
		case 14:
			stage_7_title_show(&x, &y, &u);
			break;
		case 16:
			stage_7_title_second_picture(&x, &y);
			break;
		case 20:
			stage_8_title_sound();
			break;
		case 22:
			stage_8_title_show(&x, &y, &u);
			break;
		case -58:
			krusty_balloon_shot_vanish(x);
			break;
		case -56:
			krusty_balloon_shot_fly(x);
			break;
		case -54:
			krusty_balloon_shot_drift(x);
			break;
		case -52:
			krusty_balloon_shot_open(x);
			break;
		case -50:
			krusty_balloon_shot_fall(x);
			break;
		case -48:
			stage_1_title_card(&x, &y, &u);
			break;
		case -46:
			stage_2_title_card(&x, &y, &u);
			break;
		case -44:
		case -40:
		case -34:
		case -28:
			title_card_none(&y, &u);
			break;
		case -42:
			stage_3_title_card(&x, &y, &u);
			break;
		case -38:
			stage_4_title_card(&x, &y, &u);
			break;
		case -36:
			continue;
		case -32:
			stage_6_title_card(&x, &y, &u);
			break;
		case -30:
			stage_7_title_card(&x, &y, &u);
			break;
		case -26:
			stage_8_title_card(&x, &y, &u);
			break;
		case -24:
			stage_1_title_sound();
			break;
		case -22:
			stage_1_title_show(&x, &y, &u);
			break;
		case -18:
		case -6:
			title_card_ready_screen();
			break;
		case -16:
			stage_2_title_show(&x, &y, &u);
			break;
		case -14:
			x = stage_2_title_picture_sound();
			break;
		case -12:
			stage_3_title_ready_screen();
			break;
		case -10:
			stage_3_title_show(&x, &y, &u);
			break;
		case -8:
			x = stage_3_title_picture_sound();
			break;
		case -4:
			stage_4_title_show(&x, &y, &u);
			break;
		case -2:
			x = stage_4_title_picture_sound();
			break;
		}
		break;
	}
	*p_x = x;
	*p_y = y;
	*p_u = u;
}

/* Stage 5's card, step 0: queues its sound and readies the screen with layer A's y scroll at 28. */
void stage_5_title_ready_screen(void)
{
	stage_5_title_sound();
	layer_a_scroll_y = 0x28u;
}

/* Stage 5's card, step 1: sets up the card's screen over the gorge (scene 89, area 2's tiles, area 4
   drawn on layer A), prints "STAGE 5 / SPRINGFIELD BUTTE" and puts in its picture and the card's object
   of kind 0F (4DA0). */
void stage_5_title_show(uint16_t *p_x, uint16_t *p_object, uint16_t *p_text)
{
	uint16_t x = (uint16_t)*p_x;
	uint16_t object = (uint16_t)*p_object;
	uint16_t text = (uint16_t)*p_text;
	uint16_t d = 0, ignored16 = 0, ignored16_2 = 0, ignored16_3 = 0, record_number = 0, x_2 = 0;

	if (layer_clear_pending != 0u)
		return;
	title_card_load_palettes(text);
	title_card_set_up_screen();
	map_scene = 0x89u;
	map_area = 2u;
	vector_set_layer_modes();
	map_area = 4u;
	d = 0x2Cu;
	vector_draw_layer_strips(d, &ignored16, &ignored16_2, &ignored16_3);
	text = stage_5_title_text_ADDRESS;
	vector_print_text(d, &x_2, &text);
	d |= 0x400u;
	title_card_put_picture(d);
	record_number = (d & 0xFFu) | 0x900u;
	object = title_card_put_picture(record_number);
	OBJECT(object)->attributes = 0u;
	title_card_step++;
	*p_x = x_2;
	*p_object = object;
	*p_text = text;
}

/* Stage 6's title card for C0 frames, or until a player presses a button after 40: runs its step. */
void stage_6_title_card(uint16_t *p_x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t x = (uint16_t)*p_x;
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = (uint16_t)*p_u;
	uint32_t carry = 0;
	uint16_t wait = 0;

	for (;;)
	{
		step_subphase++;
		if (step_subphase == 0xC0u)
		{
			title_card_end(&x, &y, &u);
			break;
		}
		wait = 0x4000u;
		vector_check_skip(wait, &x, &carry);
		if (carry)
		{
			title_card_end(&x, &y, &u);
			break;
		}
		x = stage_6_title_card_steps_ADDRESS;
		switch ((int8_t)(uint8_t)((uint32_t)title_card_step << 1))
		{
		case 0:
			stage_6_title_sound();
			break;
		case 2:
			stage_6_title_show(&x, &y, &u);
			break;
		case -26:
		case -2:
		case 4:
		case 12:
		case 18:
			x = title_card_count_frames();
			break;
		case 6:
			stage_7_title_sound();
			break;
		case 8:
			stage_7_title_show(&x, &y, &u);
			break;
		case 10:
			stage_7_title_second_picture(&x, &y);
			break;
		case 14:
			stage_8_title_sound();
			break;
		case 16:
			stage_8_title_show(&x, &y, &u);
			break;
		case -64:
			krusty_balloon_shot_vanish(x);
			break;
		case -62:
			krusty_balloon_shot_fly(x);
			break;
		case -60:
			krusty_balloon_shot_drift(x);
			break;
		case -58:
			krusty_balloon_shot_open(x);
			break;
		case -56:
			krusty_balloon_shot_fall(x);
			break;
		case -54:
			stage_1_title_card(&x, &y, &u);
			break;
		case -52:
			stage_2_title_card(&x, &y, &u);
			break;
		case -50:
		case -46:
		case -40:
		case -34:
			title_card_none(&y, &u);
			break;
		case -48:
			stage_3_title_card(&x, &y, &u);
			break;
		case -44:
			stage_4_title_card(&x, &y, &u);
			break;
		case -42:
			stage_5_title_card(&x, &y, &u);
			break;
		case -38:
			continue;
		case -36:
			stage_7_title_card(&x, &y, &u);
			break;
		case -32:
			stage_8_title_card(&x, &y, &u);
			break;
		case -30:
			stage_1_title_sound();
			break;
		case -28:
			stage_1_title_show(&x, &y, &u);
			break;
		case -24:
		case -12:
			title_card_ready_screen();
			break;
		case -22:
			stage_2_title_show(&x, &y, &u);
			break;
		case -20:
			x = stage_2_title_picture_sound();
			break;
		case -18:
			stage_3_title_ready_screen();
			break;
		case -16:
			stage_3_title_show(&x, &y, &u);
			break;
		case -14:
			x = stage_3_title_picture_sound();
			break;
		case -10:
			stage_4_title_show(&x, &y, &u);
			break;
		case -8:
			x = stage_4_title_picture_sound();
			break;
		case -6:
			stage_5_title_ready_screen();
			break;
		case -4:
			stage_5_title_show(&x, &y, &u);
			break;
		}
		break;
	}
	*p_x = x;
	*p_y = y;
	*p_u = u;
}

/* Stage 6's card, step 1: sets up the card's screen, prints "STAGE 6 / DREAMLAND" and puts in its
   picture and the card's object of kind 0F (4DA0). */
void stage_6_title_show(uint16_t *p_x, uint16_t *p_object, uint16_t *p_text)
{
	uint16_t x = (uint16_t)*p_x;
	uint16_t object = (uint16_t)*p_object;
	uint16_t text = (uint16_t)*p_text;
	uint16_t colour = 0, record_number = 0, x_2 = 0;

	if (layer_clear_pending != 0u)
		return;
	title_card_load_palettes(text);
	title_card_set_up_screen();
	text = stage_6_title_text_ADDRESS;
	colour = 0u;
	vector_print_text(colour, &x_2, &text);
	record_number = 0x500u;
	title_card_put_picture(record_number);
	record_number = 0x900u;
	object = title_card_put_picture(record_number);
	OBJECT(object)->attributes = 0u;
	title_card_step++;
	*p_x = x_2;
	*p_object = object;
	*p_text = text;
}

/* Stage 7's title card for C0 frames, or until a player presses a button after 40: runs its step. */
void stage_7_title_card(uint16_t *p_x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t x = (uint16_t)*p_x;
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = (uint16_t)*p_u;
	uint32_t carry = 0;
	uint16_t wait = 0;

	for (;;)
	{
		step_subphase++;
		if (step_subphase == 0xC0u)
		{
			title_card_end(&x, &y, &u);
			break;
		}
		wait = 0x4000u;
		vector_check_skip(wait, &x, &carry);
		if (carry)
		{
			title_card_end(&x, &y, &u);
			break;
		}
		x = stage_7_title_card_steps_ADDRESS;
		switch ((int8_t)(uint8_t)((uint32_t)title_card_step << 1))
		{
		case 0:
			stage_7_title_sound();
			break;
		case 2:
			stage_7_title_show(&x, &y, &u);
			break;
		case 4:
			stage_7_title_second_picture(&x, &y);
			break;
		case -32:
		case -8:
		case -2:
		case 6:
		case 12:
			x = title_card_count_frames();
			break;
		case 8:
			stage_8_title_sound();
			break;
		case 10:
			stage_8_title_show(&x, &y, &u);
			break;
		case -70:
			krusty_balloon_shot_vanish(x);
			break;
		case -68:
			krusty_balloon_shot_fly(x);
			break;
		case -66:
			krusty_balloon_shot_drift(x);
			break;
		case -64:
			krusty_balloon_shot_open(x);
			break;
		case -62:
			krusty_balloon_shot_fall(x);
			break;
		case -60:
			stage_1_title_card(&x, &y, &u);
			break;
		case -58:
			stage_2_title_card(&x, &y, &u);
			break;
		case -56:
		case -52:
		case -46:
		case -40:
			title_card_none(&y, &u);
			break;
		case -54:
			stage_3_title_card(&x, &y, &u);
			break;
		case -50:
			stage_4_title_card(&x, &y, &u);
			break;
		case -48:
			stage_5_title_card(&x, &y, &u);
			break;
		case -44:
			stage_6_title_card(&x, &y, &u);
			break;
		case -42:
			continue;
		case -38:
			stage_8_title_card(&x, &y, &u);
			break;
		case -36:
			stage_1_title_sound();
			break;
		case -34:
			stage_1_title_show(&x, &y, &u);
			break;
		case -30:
		case -18:
			title_card_ready_screen();
			break;
		case -28:
			stage_2_title_show(&x, &y, &u);
			break;
		case -26:
			x = stage_2_title_picture_sound();
			break;
		case -24:
			stage_3_title_ready_screen();
			break;
		case -22:
			stage_3_title_show(&x, &y, &u);
			break;
		case -20:
			x = stage_3_title_picture_sound();
			break;
		case -16:
			stage_4_title_show(&x, &y, &u);
			break;
		case -14:
			x = stage_4_title_picture_sound();
			break;
		case -12:
			stage_5_title_ready_screen();
			break;
		case -10:
			stage_5_title_show(&x, &y, &u);
			break;
		case -6:
			stage_6_title_sound();
			break;
		case -4:
			stage_6_title_show(&x, &y, &u);
			break;
		}
		break;
	}
	*p_x = x;
	*p_y = y;
	*p_u = u;
}

/* Stage 7's card, step 1: sets up the card's screen, prints "STAGE 7 / CHANNEL 6" and puts in its first
   picture (sliding left and up) and the card's object of kind 0F (4DA0). */
void stage_7_title_show(uint16_t *p_x, uint16_t *p_object, uint16_t *p_text)
{
	uint16_t text = (uint16_t)*p_text;
	uint16_t colour = 0, object = 0, record_number = 0, x = 0;

	title_card_load_palettes(text);
	title_card_set_up_screen();
	text = stage_7_title_text_ADDRESS;
	colour = 0u;
	vector_print_text(colour, &x, &text);
	record_number = 0x600u;
	object = title_card_put_picture(record_number);
	OBJECT(object)->y = 0x82u;
	OBJECT(object)->x_speed = -0x100;
	OBJECT(object)->z_speed = 0x100;
	record_number = 0x900u;
	object = title_card_put_picture(record_number);
	OBJECT(object)->attributes = 0u;
	step_countdown = 0x80u;
	title_card_step++;
	*p_x = x;
	*p_object = object;
	*p_text = text;
}

/* Stage 7's card, step 2: stops its first picture at x E0 and 46 high; after 80 frames puts in the
   second picture. */
void stage_7_title_second_picture(uint16_t *p_x, uint16_t *p_object)
{
	uint16_t object = (uint16_t)*p_object;
	uint8_t z_low = 0;
	uint16_t object_2 = 0, record_number = 0, x = 0;
	uint8_t t2 = 0;
	uint16_t t1 = 0, z = 0;

	OBJECT(OBJECT_ADDRESS(9))->animation_flags |= 0x40u;
	io_write8(0x1FB9u, 0x13u);
	io_write8(0x1FBAu, 0x2Cu);
	object_2 = OBJECT_ADDRESS(8);
	t1 = OBJECT(OBJECT_ADDRESS(8))->x;
	if (t1 == 0xE0u)
		OBJECT(object_2)->x_speed = 0;
	z = OBJECT(object_2)->z;
	z_low = (uint8_t)z;
	if ((uint16_t)(((uint32_t)(z >> 8) << 8) | (z_low & 0xFFu)) == 0x46u)
	{
		z_low = 0u;
		OBJECT(object_2)->z_speed = 0;
	}
	t2 = step_countdown;
	step_countdown = t2 - 1u;
	if (t2 != 1u)
	{
		x = title_card_count_frames();
		*p_x = x;
		*p_object = object;
		return;
	}
	record_number = (z_low & 0xFFu) | 0x700u;
	object = title_card_put_picture(record_number);
	OBJECT(object)->y = 0x82u;
	title_card_step++;
	x = title_card_count_frames();
	*p_x = x;
	*p_object = object;
}

/* Stage 8's title card for C0 frames, or until a player presses a button after 40: runs its step. */
void stage_8_title_card(uint16_t *p_x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t x = (uint16_t)*p_x;
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = (uint16_t)*p_u;
	uint32_t carry = 0;
	uint16_t wait = 0;

	for (;;)
	{
		step_subphase++;
		if (step_subphase == 0xC0u)
		{
			title_card_end(&x, &y, &u);
			break;
		}
		wait = 0x4000u;
		vector_check_skip(wait, &x, &carry);
		if (carry)
		{
			title_card_end(&x, &y, &u);
			break;
		}
		x = stage_8_title_card_steps_ADDRESS;
		switch ((int8_t)(uint8_t)((uint32_t)title_card_step << 1))
		{
		case 0:
			stage_8_title_sound();
			break;
		case 2:
			stage_8_title_show(&x, &y, &u);
			break;
		case -40:
		case -16:
		case -10:
		case -2:
		case 4:
			x = title_card_count_frames();
			break;
		case -78:
			krusty_balloon_shot_vanish(x);
			break;
		case -76:
			krusty_balloon_shot_fly(x);
			break;
		case -74:
			krusty_balloon_shot_drift(x);
			break;
		case -72:
			krusty_balloon_shot_open(x);
			break;
		case -70:
			krusty_balloon_shot_fall(x);
			break;
		case -68:
			stage_1_title_card(&x, &y, &u);
			break;
		case -66:
			stage_2_title_card(&x, &y, &u);
			break;
		case -64:
		case -60:
		case -54:
		case -48:
			title_card_none(&y, &u);
			break;
		case -62:
			stage_3_title_card(&x, &y, &u);
			break;
		case -58:
			stage_4_title_card(&x, &y, &u);
			break;
		case -56:
			stage_5_title_card(&x, &y, &u);
			break;
		case -52:
			stage_6_title_card(&x, &y, &u);
			break;
		case -50:
			stage_7_title_card(&x, &y, &u);
			break;
		case -46:
			continue;
		case -44:
			stage_1_title_sound();
			break;
		case -42:
			stage_1_title_show(&x, &y, &u);
			break;
		case -38:
		case -26:
			title_card_ready_screen();
			break;
		case -36:
			stage_2_title_show(&x, &y, &u);
			break;
		case -34:
			x = stage_2_title_picture_sound();
			break;
		case -32:
			stage_3_title_ready_screen();
			break;
		case -30:
			stage_3_title_show(&x, &y, &u);
			break;
		case -28:
			x = stage_3_title_picture_sound();
			break;
		case -24:
			stage_4_title_show(&x, &y, &u);
			break;
		case -22:
			x = stage_4_title_picture_sound();
			break;
		case -20:
			stage_5_title_ready_screen();
			break;
		case -18:
			stage_5_title_show(&x, &y, &u);
			break;
		case -14:
			stage_6_title_sound();
			break;
		case -12:
			stage_6_title_show(&x, &y, &u);
			break;
		case -8:
			stage_7_title_sound();
			break;
		case -6:
			stage_7_title_show(&x, &y, &u);
			break;
		case -4:
			stage_7_title_second_picture(&x, &y);
			break;
		}
		break;
	}
	*p_x = x;
	*p_y = y;
	*p_u = u;
}

/* Stage 8's card, step 1: sets up the card's screen, prints "STAGE 8 / SPRINGFIELD / NUCLEAR POWER
   PLANT" and puts in its picture and the card's object of kind 0F (4DA0). */
void stage_8_title_show(uint16_t *p_x, uint16_t *p_object, uint16_t *p_text)
{
	uint16_t text = (uint16_t)*p_text;
	uint16_t colour = 0, object = 0, record_number = 0, x = 0;

	title_card_load_palettes(text);
	title_card_set_up_screen();
	text = stage_8_title_text_ADDRESS;
	colour = 0u;
	vector_print_text(colour, &x, &text);
	record_number = 0x800u;
	title_card_put_picture(record_number);
	record_number = 0x900u;
	object = title_card_put_picture(record_number);
	OBJECT(object)->attributes = 0u;
	title_card_step++;
	*p_x = x;
	*p_object = object;
	*p_text = text;
}

/* The card's end: stops the sound, loads palette sets 0880, clears the screen's layers and all the
   objects, and ends the substep. */
void title_card_end(uint16_t *p_x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t u = (uint16_t)*p_u;
	uint32_t carry = 0;
	uint16_t command = 0, ignored16 = 0, ignored16_2 = 0, ignored16_3 = 0, request = 0, u_2 = 0, x = 0, y = 0;

	command = 0u;
	carry = vector_queue_sound(command);
	palette_request_kind = 1u;
	request = 0x880u;
	vector_palette_request(request, &ignored16, &u);
	vector_clear_text_layer(&ignored16_2, &ignored16_3);
	y = vector_clear_layer_a();
	vector_clear_objects(&x, &u_2);
	step_subphase = 0u;
	step_phase++;
	*p_x = x;
	*p_y = y;
	*p_u = u_2;
}

/* Puts in record A of stage_title_placements (0-8 a stage's picture at 4D40, kind C2 with the stage's
   animation; 9 an object of kind 0F, animation 1F, at 4DA0) and leaves its object in Y. */
uint16_t title_card_put_picture(uint16_t record_number)
{
	uint32_t carry = 0;
	uint8_t a = 0, b = 0;
	uint16_t object = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0, kind = 0, t4 = 0, t5 = 0, z = 0;
	uint32_t kind_halfword = 0;

	a = (uint8_t)(record_number >> 8);
	t1 = a | 0x1000u;
	b = (uint8_t)t1;
	carry = (int8_t)b < 0;
	b = (uint32_t)b << 1;
	a = (uint8_t)(((uint32_t)(uint8_t)((uint32_t)a << 8) << 1) | carry);
	carry = (int8_t)b < 0;
	b = (uint32_t)b << 1;
	a = (uint8_t)(((uint32_t)a << 1) | carry);
	carry = (int8_t)b < 0;
	t2 = stage_title_placements_ADDRESS + (((((uint32_t)a << 1) | carry) << 8) | (uint8_t)((uint32_t)b << 1));
	object = PLACEMENT(t2)->object;
	OBJECT(object)->flags = 0x80u;
	t3 = t2 + 2u;
	kind = PLACEMENT(t3 - 0x2u)->kind;
	kind_halfword = ((uint32_t)(kind >> 8) << 8) | (uint8_t)(kind | 0x80u);
	OBJECT(object)->kind = (uint8_t)(kind_halfword >> 8u);
	OBJECT(object)->animation = (uint8_t)kind_halfword;
	t4 = t3 + 2u;
	t5 = PLACEMENT(t4 - 0x4u)->x;
	OBJECT(object)->x = t5;
	OBJECT(object)->y = 0x80u;
	z = PLACEMENT(t4 - 0x4u)->z;
	OBJECT(object)->z = z;
	OBJECT(object)->attributes = 0x20u;
	return object;
}

/* Clears the text layer, takes scene 2's area 0 (its tile banks) and draws it on layer B, with the
   card's layer priorities. */
void title_card_set_up_screen(void)
{
	uint16_t ignored16 = 0, ignored16_2 = 0, ignored16_3 = 0, ignored16_4 = 0, layer_and_columns = 0;

	vector_clear_text_layer(&ignored16, &ignored16_2);
	map_scene = 2u;
	map_area = 0u;
	vector_set_layer_modes();
	io_write8(0x1FB9u, 0x3Fu);
	io_write8(0x1FBAu, 0x36u);
	layer_and_columns = 0x12Cu;
	vector_draw_layer_strips(layer_and_columns, &ignored16, &ignored16_3, &ignored16_4);
}

/* Loads palette sets 0F0C and starts the players' colour cycles. */
void title_card_load_palettes(uint16_t palette_job)
{
	uint16_t ignored16 = 0, request = 0;

	palette_request_kind = 1u;
	request = 0xF0Cu;
	vector_palette_request(request, &ignored16, &palette_job);
	start_player_colour_cycles(&ignored16, &palette_job);
}

/* Starts palette effects 7-10, which cycle colour 5 of each player's sprite palette (32-35) through
   white and pinks. */
void start_player_colour_cycles(uint16_t *p_y, uint16_t *p_palette_job)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t palette_job = (uint16_t)*p_palette_job;
	uint16_t request = 0;

	palette_request_kind = 2u;
	request = 7u;
	vector_palette_request(request, &y, &palette_job);
	palette_request_kind = 2u;
	request = 8u;
	vector_palette_request(request, &y, &palette_job);
	palette_request_kind = 2u;
	request = 9u;
	vector_palette_request(request, &y, &palette_job);
	palette_request_kind = 2u;
	request = 0xAu;
	*p_y = y;
	*p_palette_job = palette_job;
	vector_palette_request(request, p_y, p_palette_job);
}
