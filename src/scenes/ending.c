/**
 *    Name:        scenes/ending.c
 *    Description: the ending
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    11-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the game's 053248 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

/* Runs the ending by the scene's state: the family, the staff roll and the last fade; after 192 frames a
   player's button skips it. */
void ending(uint16_t u)
{
	uint32_t skipped = 0;
	uint16_t ignored16 = 0, ignored16_2 = 0, wait = 0;
	uint8_t ending_state = 0;

	wait = 0xC000u;
	vector_check_skip(wait, &ignored16, &skipped);
	if (skipped)
	{
		vector_clear_objects(&ignored16, &ignored16_2);
		scene_running = 0u;
		return;
	}
	gauges_shown = 0u;
	ending_state = io_read8(scene_state);
	switch ((int8_t)(uint8_t)((uint32_t)ending_state << 1))
	{
	case 0:
		ending_set_up(u);
		return;
	case 2:
		ending_show_family();
		return;
	case 4:
		ending_roll_credits();
		return;
	case 6:
		ending_toss();
		return;
	case 8:
		ending_catch();
		return;
	case 10:
		ending_fade_start(u);
		return;
	case 12:
		ending_fade(u);
		return;
	}
}

/* The ending: clears the screen and loads its colours. */
void ending_set_up(uint16_t palette_job)
{
	uint16_t ignored16 = 0, ignored16_2 = 0, job = 0, object = 0, object_count = 0, request = 0, scroll_x = 0, scroll_y = 0;
	uint8_t discarded_read = 0, old_scene_state = 0;

	job = 0u;
	vector_queue_job(job);
	palette_request_kind = 1u;
	request = 0xF90u;
	palette_job = vector_palette_request(palette_job, request);
	palette_request_kind = 2u;
	request = 0x3Au;
	vector_palette_request(palette_job, request);
	scroll_x = 0xFFF0u;
	vector_set_scroll_x(scroll_x);
	scroll_y = 0u;
	vector_set_scroll_y(scroll_y);
	vector_clear_objects(&ignored16, &ignored16_2);
	vector_clear_sprites();
	object = OBJECT_ADDRESS(14);
	object_count = 0x800u;
	reserve_objects_for_sprites(object, object_count);
	discarded_read = io_read8(staff_roll_line);
	io_write8(staff_roll_line, 0u);
	old_scene_state = io_read8(scene_state);
	io_write8(scene_state, old_scene_state + 1u);
}

/* The ending: draws its background and puts the family. */
void ending_show_family(void)
{
	uint16_t ignored16 = 0, ignored16_2 = 0, layer_and_columns = 0, layer_then_placement = 0, object = 0;
	uint8_t old_scene_state = 0;

	if (layer_clear_pending != 0u)
		return;
	io_write8(colour_bases_back_sprites_fixed, 0x3Fu);
	io_write8(colour_bases_layers_a_b, 0x36u);
	map_scene = 0x8Eu;
	map_area = 0u;
	vector_set_layer_modes();
	layer_and_columns = 0x26u;
	vector_draw_layer_strips(layer_and_columns, &ignored16, &ignored16_2);
	layer_then_placement = 0x126u;
	vector_draw_layer_strips(layer_then_placement, &ignored16, &ignored16_2);
	io_write8(colour_bases_back_sprites_fixed, 0x13u);
	io_write8(colour_bases_layers_a_b, 0x2Cu);
	layer_then_placement &= 0xFFu;
	ending_put_placement(layer_then_placement);
	layer_then_placement |= 0x100u;
	object = ending_put_placement(layer_then_placement);
	OBJECT(object)->zoom_x = 0x40u;
	OBJECT(object)->zoom_y = 0x40u;
	old_scene_state = io_read8(scene_state);
	io_write8(scene_state, old_scene_state + 1u);
}

/* The ending: rolls the staff and moves the family through its animations while the view rises; then the
   next pose. */
void ending_roll_credits(void)
{
	uint32_t at_top = 0;
	uint16_t record_number = 0;
	uint8_t old_scene_state = 0;

	ending_staff_roll(0u);
	ending_family_animations();
	at_top = ending_scroll_up();
	if (at_top == 0u)
		return;
	record_number = 0x400u;
	ending_put_placement(record_number);
	old_scene_state = io_read8(scene_state);
	io_write8(scene_state, old_scene_state + 1u);
}

/* The ending: on the family's cue something is tossed up, with a sound (0101). */
void ending_toss(void)
{
	uint16_t command = 0, object = 0, record_number = 0;
	uint8_t old_scene_state = 0;
	uint16_t tossed_y = 0, new_tossed_y = 0;

	ending_staff_roll(0u);
	OBJECT(OBJECT_ADDRESS(9))->animation_flags = 0x40u;
	if ((OBJECT(OBJECT_ADDRESS(8))->animation_flags & 2u) == 0u)
		return;
	command = 0x101u;
	vector_queue_sound(command);
	record_number = 0x501u;
	object = ending_put_placement(record_number);
	tossed_y = OBJECT(object)->y;
	new_tossed_y = tossed_y - 2u;
	OBJECT(object)->y = new_tossed_y;
	OBJECT(object)->x_speed = -0x10;
	OBJECT(object)->z_speed = 0x1E0;
	OBJECT(object)->zoom_x = 0x40u;
	OBJECT(object)->zoom_y = 0x40u;
	old_scene_state = io_read8(scene_state);
	io_write8(scene_state, old_scene_state + 1u);
}

/* The ending: the tossed object rises while the family's pose plays out. */
void ending_catch(void)
{
	uint8_t old_scene_state = 0;

	ending_staff_roll(0u);
	ending_tossed_rise();
	OBJECT(OBJECT_ADDRESS(9))->animation_flags = 0x40u;
	if ((OBJECT(OBJECT_ADDRESS(8))->animation_flags & 1u) == 0u)
		return;
	old_scene_state = io_read8(scene_state);
	io_write8(scene_state, old_scene_state + 1u);
}

/* The ending: when the tossed object is gone, the family floats away and the colours start to fade. */
void ending_fade_start(uint16_t u)
{
	uint32_t gone = 0;
	uint16_t request = 0;
	uint8_t old_scene_state = 0;

	OBJECT(OBJECT_ADDRESS(9))->animation_flags = 0x40u;
	u = ending_staff_roll(u);
	gone = ending_tossed_rise();
	if (gone)
	{
		palette_request_kind = 4u;
		request = 0x440u;
		u = vector_palette_request(u, request);
		palette_request_kind = 4u;
		request = 0x840u;
		u = vector_palette_request(u, request);
		palette_request_kind = 4u;
		request = 0x220u;
		vector_palette_request(u, request);
		io_write16(scene_wait, 0x180u);
		old_scene_state = io_read8(scene_state);
		io_write8(scene_state, old_scene_state + 1u);
		return;
	}
	ending_family_float();
}

/* The ending: the family floats away while the colours fade; then the ending is over. */
void ending_fade(uint16_t palette_job)
{
	uint16_t ignored16 = 0, ignored16_2 = 0, request = 0;
	uint16_t fade_frames_left = 0, fade_frames = 0;

	OBJECT(OBJECT_ADDRESS(9))->animation_flags = 0x40u;
	ending_family_float();
	fade_frames_left = io_read16(scene_wait);
	io_write16(scene_wait, fade_frames_left - 1u);
	if (fade_frames_left == 1u)
	{
		vector_clear_objects(&ignored16, &ignored16_2);
		scene_running = 0u;
		return;
	}
	fade_frames = io_read16(scene_wait);
	if (fade_frames == 0x80u)
	{
		palette_request_kind = 2u;
		request = 0x48u;
		vector_palette_request(palette_job, request);
	}
}

/* The ending: raises the view a pixel every 104 frames, up to 27 (carry: there). */
uint32_t ending_scroll_up(void)
{
	uint32_t at_top = 0;
	uint8_t scroll_y_high = 0, scroll_y_low = 0;
	uint8_t scroll_wait = 0, old_scroll_wait = 0, discarded_read = 0;
	uint16_t layer_a_y = 0, new_layer_a_y = 0;

	scroll_wait = io_read8(dream_wave_line);
	if (scroll_wait != 0x68u)
	{
		old_scroll_wait = io_read8(dream_wave_line);
		io_write8(dream_wave_line, old_scroll_wait + 1u);
		at_top = 0u;
		return at_top;
	}
	discarded_read = io_read8(dream_wave_line);
	io_write8(dream_wave_line, 0u);
	layer_a_y = layer_a_scroll_y;
	scroll_y_low = (uint8_t)layer_a_y;
	scroll_y_high = (uint8_t)(layer_a_y >> 8);
	if ((uint16_t)(((uint32_t)scroll_y_high << 8) | (scroll_y_low & 0xFFu)) == 0x1Bu)
	{
		at_top = 1u;
		return at_top;
	}
	new_layer_a_y = (((uint32_t)scroll_y_high << 8) | (scroll_y_low & 0xFFu)) + 1u;
	layer_a_scroll_y = new_layer_a_y;
	old_scroll_wait = io_read8(dream_wave_line);
	io_write8(dream_wave_line, old_scroll_wait + 1u);
	at_top = 0u;
	return at_top;
}

/* The ending: every 160 frames, replaces the staff roll's title and name with the next ones. */
uint16_t ending_staff_roll(uint16_t u)
{
	uint16_t colour = 0, ignored16 = 0, text = 0, title = 0;
	uint8_t roll_wait = 0, old_roll_wait = 0, erased_name_line = 0, erased_title_line = 0, old_roll_line = 0, name_line = 0, title_line = 0;

	roll_wait = io_read8(scene_palette_effect);
	if (roll_wait != 0u)
	{
		old_roll_wait = io_read8(scene_palette_effect);
		io_write8(scene_palette_effect, old_roll_wait - 1u);
		return u;
	}
	erased_name_line = io_read8(staff_roll_line);
	text = staff_roll_names[(int8_t)((uint8_t)((uint32_t)erased_name_line << 1)) / 2];
	erase_big_text(text);
	erased_title_line = io_read8(staff_roll_line);
	text = staff_roll_titles[(int8_t)((uint8_t)((uint32_t)erased_title_line << 1)) / 2];
	vector_erase_text(text);
	old_roll_line = io_read8(staff_roll_line);
	io_write8(staff_roll_line, old_roll_line + 1u);
	name_line = io_read8(staff_roll_line);
	text = staff_roll_names[(int8_t)((uint8_t)((uint32_t)name_line << 1)) / 2];
	colour = 0x4000u;
	print_big_text(text, colour);
	title_line = io_read8(staff_roll_line);
	title = staff_roll_titles[(int8_t)((uint8_t)((uint32_t)title_line << 1)) / 2];
	colour = 0u;
	vector_print_text(colour, &ignored16, &title);
	io_write8(scene_palette_effect, 0xA0u);
	return title;
}

/* The ending: after each wait of ending_family_waits, starts the family's next animation. */
void ending_family_animations(void)
{
	uint8_t wait_high = 0, wait_low = 0;
	uint16_t record_number = 0;
	uint8_t family_step = 0, old_family_step = 0;
	uint16_t step_wait = 0, frames_waited = 0, old_frames_waited = 0;

	family_step = io_read8(ending_family_step);
	step_wait = ending_family_waits[(int8_t)((uint8_t)((uint32_t)family_step << 1)) / 2];
	wait_low = (uint8_t)step_wait;
	wait_high = (uint8_t)(step_wait >> 8);
	if ((uint16_t)(((uint32_t)wait_high << 8) | (wait_low & 0xFFu)) == 0xFFFFu)
		return;
	frames_waited = io_read16(scene_second_wait);
	if (frames_waited < (uint16_t)(((uint32_t)wait_high << 8) | (wait_low & 0xFFu)))
	{
		old_frames_waited = io_read16(scene_second_wait);
		io_write16(scene_second_wait, old_frames_waited + 1u);
		return;
	}
	if ((OBJECT(OBJECT_ADDRESS(8))->animation_flags & 1u) == 0u)
		return;
	record_number = (wait_low & 0xFFu) | 0x200u;
	ending_put_placement(record_number);
	io_write16(scene_second_wait, 0u);
	old_family_step = io_read8(ending_family_step);
	io_write8(ending_family_step, old_family_step + 1u);
}

/* The ending: the tossed object flies up and comes closer, growing, through its animations until gone
   (carry). */
uint32_t ending_tossed_rise(void)
{
	uint32_t gone = 0;
	uint8_t zoom = 0;
	uint16_t object = 0;
	uint8_t zoom_x = 0, animation = 0, animation_2 = 0;
	uint16_t z_speed = 0, new_z_speed = 0;

	object = OBJECT_ADDRESS(10);
	OBJECT(OBJECT_ADDRESS(10))->flags |= 0x10u;
	z_speed = OBJECT(OBJECT_ADDRESS(10))->z_speed;
	new_z_speed = z_speed - 4u;
	OBJECT(OBJECT_ADDRESS(10))->z_speed = new_z_speed;
	OBJECT(OBJECT_ADDRESS(10))->action++;
	if (OBJECT(OBJECT_ADDRESS(10))->action != 3u)
	{
		gone = 0u;
		return gone;
	}
	OBJECT(object)->action = 0u;
	zoom_x = OBJECT(object)->zoom_x;
	zoom = zoom_x - 1u;
	if (zoom != 0x30u)
	{
		OBJECT(object)->zoom_x = zoom;
		OBJECT(object)->zoom_y = zoom;
		gone = 0u;
		return gone;
	}
	animation = OBJECT(object)->animation;
	if (animation == 7u)
	{
		OBJECT(object)->flags = 0u;
		gone = 1u;
		return gone;
	}
	animation_2 = OBJECT(object)->animation;
	OBJECT(object)->animation = animation_2 + 1u;
	zoom = 0x60u;
	OBJECT(object)->zoom_x = zoom;
	OBJECT(object)->zoom_y = zoom;
	gone = 0u;
	return gone;
}

/* The ending: the family floats up, slowly getting smaller. */
void ending_family_float(void)
{
	uint16_t object = 0;
	uint8_t zoom_x = 0, zoom_y = 0;

	object = OBJECT_ADDRESS(8);
	OBJECT(OBJECT_ADDRESS(8))->flags |= 0x10u;
	OBJECT(OBJECT_ADDRESS(8))->z_speed = 4;
	if ((frame_count & 0xFu) == 0u)
	{
		zoom_x = OBJECT(object)->zoom_x;
		OBJECT(object)->zoom_x = zoom_x + 1u;
		zoom_y = OBJECT(object)->zoom_y;
		OBJECT(object)->zoom_y = zoom_y + 1u;
	}
}

/* The ending: puts the given record of ending_placements and hands back its object. */
uint16_t ending_put_placement(uint16_t record_number)
{
	uint32_t shifted_bit = 0;
	uint8_t offset_high = 0, offset_low = 0;
	uint16_t object = 0;
	uint16_t exchanged = 0, placement_record = 0, kind_at = 0, kind = 0, x_at = 0, placement_x = 0, z = 0;
	uint32_t kind_halfword = 0;

	offset_high = (uint8_t)(record_number >> 8);
	exchanged = offset_high | 0x1000u;
	offset_low = (uint8_t)exchanged;
	shifted_bit = (int8_t)offset_low < 0;
	offset_low = (uint32_t)offset_low << 1;
	offset_high = (uint8_t)(((uint32_t)(uint8_t)((uint32_t)offset_high << 8) << 1) | shifted_bit);
	shifted_bit = (int8_t)offset_low < 0;
	offset_low = (uint32_t)offset_low << 1;
	offset_high = (uint8_t)(((uint32_t)offset_high << 1) | shifted_bit);
	shifted_bit = (int8_t)offset_low < 0;
	placement_record = ending_placements_ADDRESS + (((((uint32_t)offset_high << 1) | shifted_bit) << 8) | (uint8_t)((uint32_t)offset_low << 1));
	object = PLACEMENT(placement_record)->object;
	OBJECT(object)->flags = 0x80u;
	kind_at = placement_record + 2u;
	kind = PLACEMENT(kind_at - 0x2u)->kind;
	kind_halfword = ((uint32_t)(kind >> 8) << 8) | (uint8_t)(kind | 0x80u);
	OBJECT(object)->kind = (uint8_t)(kind_halfword >> 8u);
	OBJECT(object)->animation = (uint8_t)kind_halfword;
	x_at = kind_at + 2u;
	placement_x = PLACEMENT(x_at - 0x4u)->x;
	OBJECT(object)->x = placement_x;
	OBJECT(object)->y = 0x80u;
	z = PLACEMENT(x_at - 0x4u)->z;
	OBJECT(object)->z = z;
	return object;
}

/* Step 16, the ending, by step_phase, the gauges hidden */
uint32_t step_ending(uint16_t u)
{
	uint32_t left_caller = 0;

	gauges_shown = 0u;
	switch ((int8_t)(uint8_t)((uint32_t)step_phase << 1))
	{
	case 0:
		left_caller = 0u;
		ending_setup();
		return left_caller;
	case 2:
		left_caller = 0u;
		ending_run(u);
		return left_caller;
	case 4:
		left_caller = 0u;
		ending_end();
		return left_caller;
	case 6:
		left_caller = 0u;
		game_over_start();
		return left_caller;
	case 8:
		left_caller = 0u;
		game_over_show();
		return left_caller;
	case 10:
		left_caller = 0u;
		game_over_wait();
		return left_caller;
	case 12:
		left_caller = 0u;
		name_entry_start(u);
		return left_caller;
	case 14:
		left_caller = 0u;
		name_entry_run();
		return left_caller;
	case 16:
		left_caller = 0u;
		name_entry_end();
		return left_caller;
	case -128:
		return stage_3_forest_end_phase();
	case -126:
		left_caller = 0u;
		stage_3_cemetery_setup();
		return left_caller;
	case -124:
		left_caller = 0u;
		return stage_3_cemetery_begin(u, left_caller);
	case -122:
		left_caller = 0u;
		stage_3_cemetery_opening();
		return left_caller;
	case -120:
		left_caller = 0u;
		return stage_3_cemetery_play(left_caller);
	case -118:
		left_caller = 0u;
		stage_3_cemetery_over();
		return left_caller;
	case -116:
		left_caller = 0u;
		return stage_3_cemetery_exit(left_caller);
	case -114:
		left_caller = 0u;
		return stage_3_cemetery_end_phase(u, left_caller);
	case -112:
		left_caller = 0u;
		stage_4_setup();
		return left_caller;
	case -110:
		left_caller = 0u;
		stage_4_title(u);
		return left_caller;
	case -108:
		left_caller = 0u;
		return stage_4_begin(u, left_caller);
	case -106:
		left_caller = 0u;
		stage_4_opening();
		return left_caller;
	case -104:
		left_caller = 0u;
		return stage_4_play(left_caller);
	case -102:
		left_caller = 0u;
		stage_4_over();
		return left_caller;
	case -100:
		left_caller = 0u;
		return stage_4_exit(left_caller);
	case -98:
		left_caller = 0u;
		return stage_4_end_phase(left_caller);
	case -96:
		left_caller = 0u;
		stage_5_setup();
		return left_caller;
	case -94:
		left_caller = 0u;
		stage_5_title(u);
		return left_caller;
	case -92:
		left_caller = 0u;
		return stage_5_begin(u, left_caller);
	case -90:
		left_caller = 0u;
		stage_5_opening();
		return left_caller;
	case -88:
		left_caller = 0u;
		return stage_5_play(left_caller);
	case -86:
		left_caller = 0u;
		stage_5_over();
		return left_caller;
	case -84:
		left_caller = 0u;
		return stage_5_exit(left_caller);
	case -82:
		left_caller = 0u;
		stage_5_closing_scene(u);
		return left_caller;
	case -80:
		left_caller = 0u;
		stage_5_end_phase(u);
		return left_caller;
	case -78:
		left_caller = 0u;
		stage_6_setup();
		return left_caller;
	case -76:
		left_caller = 0u;
		stage_6_title(u);
		return left_caller;
	case -74:
		left_caller = 0u;
		return stage_6_begin(u, left_caller);
	case -72:
		left_caller = 0u;
		stage_6_opening();
		return left_caller;
	case -70:
		left_caller = 0u;
		return stage_6_play(left_caller);
	case -68:
		left_caller = 0u;
		stage_6_over();
		return left_caller;
	case -66:
		left_caller = 0u;
		return stage_6_exit(left_caller);
	case -64:
		left_caller = 0u;
		stage_6_closing_scene(u);
		return left_caller;
	case -62:
		left_caller = 0u;
		stage_6_end_phase(u);
		return left_caller;
	case -60:
		left_caller = 0u;
		bonus_2_setup();
		return left_caller;
	case -58:
		left_caller = 0u;
		bonus_2_draw();
		return left_caller;
	case -56:
		left_caller = 0u;
		bonus_2_intro_phase();
		return left_caller;
	case -54:
		left_caller = 0u;
		bonus_2_run();
		return left_caller;
	case -52:
		left_caller = 0u;
		bonus_2_wait();
		return left_caller;
	case -50:
		left_caller = 0u;
		bonus_2_end_phase(u);
		return left_caller;
	case -48:
		left_caller = 0u;
		stage_7_setup();
		return left_caller;
	case -46:
		left_caller = 0u;
		stage_7_title(u);
		return left_caller;
	case -44:
		left_caller = 0u;
		return stage_7_begin(u, left_caller);
	case -42:
		left_caller = 0u;
		stage_7_opening();
		return left_caller;
	case -40:
		left_caller = 0u;
		return stage_7_play(left_caller);
	case -38:
		left_caller = 0u;
		stage_7_over();
		return left_caller;
	case -36:
		left_caller = 0u;
		return stage_7_exit(left_caller);
	case -34:
		left_caller = 0u;
		return stage_7_closing_scene(u, left_caller);
	case -32:
		left_caller = 0u;
		return stage_7_end_phase(u, left_caller);
	case -30:
		left_caller = 0u;
		stage_8_setup();
		return left_caller;
	case -28:
		left_caller = 0u;
		stage_8_title(u);
		return left_caller;
	case -26:
		left_caller = 0u;
		stage_8_entrance(u);
		return left_caller;
	case -24:
		left_caller = 0u;
		return stage_8_begin(u, left_caller);
	case -22:
		left_caller = 0u;
		stage_8_opening();
		return left_caller;
	case -20:
		left_caller = 0u;
		return stage_8_play(left_caller);
	case -18:
		left_caller = 0u;
		return stage_8_first_part_exit(left_caller);
	case -16:
		left_caller = 0u;
		return stage_8_story(u, left_caller);
	case -14:
		left_caller = 0u;
		return stage_8_robot_entrance(left_caller);
	case -12:
		left_caller = 0u;
		return stage_8_final_fight(left_caller);
	case -10:
		left_caller = 0u;
		stage_8_over();
		return left_caller;
	case -8:
		left_caller = 0u;
		return stage_8_exit(left_caller);
	case -6:
		left_caller = 0u;
		return stage_8_closing_scene(left_caller);
	case -4:
		left_caller = 0u;
		return stage_8_objects_wait(left_caller);
	case -2:
		left_caller = 0u;
		return stage_8_end_phase(u, left_caller);
	}
	unreachable();
}

/* Clears the sprites, the tile layers and the scene's variables for the ending */
void ending_setup(void)
{
	clear_sprites();
	clear_tile_layers();
	reset_for_stage();
	step_phase++;
}

/* A frame of the ending (the family, the staff roll), run by bank 11 until it clears scene_running; then
   the tile layers' clear queued */
void ending_run(uint16_t u)
{
	uint16_t job = 0;

	scene_running = 1u;
	window_bank = 0x11u;
	set_lines(window_bank);
	ending(u);
	if (scene_running != 0u)
		return;
	gauges_shown = 0u;
	job = 0u;
	queue_job(job);
	step_phase++;
}

/* Once the layers are clear, clears the objects and ends the game as after GAME OVER: the high scores
   checked */
void ending_end(void)
{
	uint16_t ignored16 = 0, ignored16_2 = 0;

	gauges_shown = 0u;
	if (layer_clear_pending != 0u)
		return;
	clear_objects(&ignored16, &ignored16_2);
	game_finish();
}
