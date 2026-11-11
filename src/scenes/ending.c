/**
 *    Name:        scenes/ending.c
 *    Description: the ending: the family, the staff roll and the fade
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    10-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the game's 053248 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

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
	discarded_read = io_read8(0x18E6u);
	io_write8(0x18E6u, 0u);
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
	io_write8(0x1FB9u, 0x3Fu);
	io_write8(0x1FBAu, 0x36u);
	map_scene = 0x8Eu;
	map_area = 0u;
	vector_set_layer_modes();
	layer_and_columns = 0x26u;
	vector_draw_layer_strips(layer_and_columns, &ignored16, &ignored16_2);
	layer_then_placement = 0x126u;
	vector_draw_layer_strips(layer_then_placement, &ignored16, &ignored16_2);
	io_write8(0x1FB9u, 0x13u);
	io_write8(0x1FBAu, 0x2Cu);
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
	uint32_t carry = 0;
	uint16_t record_number = 0;
	uint8_t old_scene_state = 0;

	ending_staff_roll(0u);
	ending_family_animations();
	carry = ending_scroll_up();
	if (carry == 0u)
		return;
	record_number = 0x400u;
	ending_put_placement(record_number);
	old_scene_state = io_read8(scene_state);
	io_write8(scene_state, old_scene_state + 1u);
}

/* The ending: on the family's cue something is tossed up, with a sound (0101). */
void ending_toss(void)
{
	uint32_t carry = 0;
	uint16_t command = 0, object = 0, record_number = 0;
	uint8_t old_scene_state = 0;
	uint16_t tossed_y = 0, new_tossed_y = 0;

	ending_staff_roll(0u);
	OBJECT(OBJECT_ADDRESS(9))->animation_flags = 0x40u;
	if ((OBJECT(OBJECT_ADDRESS(8))->animation_flags & 2u) == 0u)
		return;
	command = 0x101u;
	carry = vector_queue_sound(command);
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
	uint32_t carry = 0;
	uint8_t old_scene_state = 0;

	ending_staff_roll(0u);
	carry = ending_tossed_rise();
	OBJECT(OBJECT_ADDRESS(9))->animation_flags = 0x40u;
	if ((OBJECT(OBJECT_ADDRESS(8))->animation_flags & 1u) == 0u)
		return;
	old_scene_state = io_read8(scene_state);
	io_write8(scene_state, old_scene_state + 1u);
}

/* The ending: when the tossed object is gone, the family floats away and the colours start to fade. */
void ending_fade_start(uint16_t u)
{
	uint32_t carry = 0;
	uint16_t request = 0;
	uint8_t old_scene_state = 0;

	OBJECT(OBJECT_ADDRESS(9))->animation_flags = 0x40u;
	u = ending_staff_roll(u);
	carry = ending_tossed_rise();
	if (carry)
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
		io_write16(0x18E2u, 0x180u);
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
	fade_frames_left = io_read16(0x18E2u);
	io_write16(0x18E2u, fade_frames_left - 1u);
	if (fade_frames_left == 1u)
	{
		vector_clear_objects(&ignored16, &ignored16_2);
		scene_running = 0u;
		return;
	}
	fade_frames = io_read16(0x18E2u);
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
	uint32_t carry = 0;
	uint8_t scroll_y_high = 0, scroll_y_low = 0;
	uint8_t scroll_wait = 0, old_scroll_wait = 0, discarded_read = 0;
	uint16_t layer_a_y = 0, new_layer_a_y = 0;

	scroll_wait = io_read8(0x18EAu);
	if (scroll_wait != 0x68u)
	{
		old_scroll_wait = io_read8(0x18EAu);
		io_write8(0x18EAu, old_scroll_wait + 1u);
		carry = 0u;
		return carry;
	}
	discarded_read = io_read8(0x18EAu);
	io_write8(0x18EAu, 0u);
	layer_a_y = layer_a_scroll_y;
	scroll_y_low = (uint8_t)layer_a_y;
	scroll_y_high = (uint8_t)(layer_a_y >> 8);
	if ((uint16_t)(((uint32_t)scroll_y_high << 8) | (scroll_y_low & 0xFFu)) == 0x1Bu)
	{
		carry = 1u;
		return carry;
	}
	new_layer_a_y = (((uint32_t)scroll_y_high << 8) | (scroll_y_low & 0xFFu)) + 1u;
	layer_a_scroll_y = new_layer_a_y;
	old_scroll_wait = io_read8(0x18EAu);
	io_write8(0x18EAu, old_scroll_wait + 1u);
	carry = 0u;
	return carry;
}

/* The ending: every 160 frames, replaces the staff roll's title and name with the next ones. */
uint16_t ending_staff_roll(uint16_t u)
{
	uint16_t colour = 0, ignored16 = 0, text = 0, title = 0;
	uint8_t roll_wait = 0, old_roll_wait = 0, erased_name_line = 0, erased_title_line = 0, old_roll_line = 0, name_line = 0, title_line = 0;

	roll_wait = io_read8(0x18E4u);
	if (roll_wait != 0u)
	{
		old_roll_wait = io_read8(0x18E4u);
		io_write8(0x18E4u, old_roll_wait - 1u);
		return u;
	}
	erased_name_line = io_read8(0x18E6u);
	text = staff_roll_names[(int8_t)((uint8_t)((uint32_t)erased_name_line << 1)) / 2];
	erase_big_text(text);
	erased_title_line = io_read8(0x18E6u);
	text = staff_roll_titles[(int8_t)((uint8_t)((uint32_t)erased_title_line << 1)) / 2];
	vector_erase_text(text);
	old_roll_line = io_read8(0x18E6u);
	io_write8(0x18E6u, old_roll_line + 1u);
	name_line = io_read8(0x18E6u);
	text = staff_roll_names[(int8_t)((uint8_t)((uint32_t)name_line << 1)) / 2];
	colour = 0x4000u;
	print_big_text(text, colour);
	title_line = io_read8(0x18E6u);
	title = staff_roll_titles[(int8_t)((uint8_t)((uint32_t)title_line << 1)) / 2];
	colour = 0u;
	vector_print_text(colour, &ignored16, &title);
	io_write8(0x18E4u, 0xA0u);
	return title;
}

/* The ending: after each wait of ending_family_waits, starts the family's next animation. */
void ending_family_animations(void)
{
	uint8_t wait_high = 0, wait_low = 0;
	uint16_t record_number = 0;
	uint8_t family_step = 0, old_family_step = 0;
	uint16_t step_wait = 0, frames_waited = 0, old_frames_waited = 0;

	family_step = io_read8(0x18E9u);
	step_wait = ending_family_waits[(int8_t)((uint8_t)((uint32_t)family_step << 1)) / 2];
	wait_low = (uint8_t)step_wait;
	wait_high = (uint8_t)(step_wait >> 8);
	if ((uint16_t)(((uint32_t)wait_high << 8) | (wait_low & 0xFFu)) == 0xFFFFu)
		return;
	frames_waited = io_read16(0x18E7u);
	if (frames_waited < (uint16_t)(((uint32_t)wait_high << 8) | (wait_low & 0xFFu)))
	{
		old_frames_waited = io_read16(0x18E7u);
		io_write16(0x18E7u, old_frames_waited + 1u);
		return;
	}
	if ((OBJECT(OBJECT_ADDRESS(8))->animation_flags & 1u) == 0u)
		return;
	record_number = (wait_low & 0xFFu) | 0x200u;
	ending_put_placement(record_number);
	io_write16(0x18E7u, 0u);
	old_family_step = io_read8(0x18E9u);
	io_write8(0x18E9u, old_family_step + 1u);
}

/* The ending: the tossed object flies up and comes closer, growing, through its animations until gone
   (carry). */
uint32_t ending_tossed_rise(void)
{
	uint32_t carry = 0;
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
		carry = 0u;
		return carry;
	}
	OBJECT(object)->action = 0u;
	zoom_x = OBJECT(object)->zoom_x;
	zoom = zoom_x - 1u;
	if (zoom != 0x30u)
	{
		OBJECT(object)->zoom_x = zoom;
		OBJECT(object)->zoom_y = zoom;
		carry = 0u;
		return carry;
	}
	animation = OBJECT(object)->animation;
	if (animation == 7u)
	{
		OBJECT(object)->flags = 0u;
		carry = 1u;
		return carry;
	}
	animation_2 = OBJECT(object)->animation;
	OBJECT(object)->animation = animation_2 + 1u;
	zoom = 0x60u;
	OBJECT(object)->zoom_x = zoom;
	OBJECT(object)->zoom_y = zoom;
	carry = 0u;
	return carry;
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
	uint32_t carry = 0;
	uint8_t offset_high = 0, offset_low = 0;
	uint16_t object = 0;
	uint16_t exchanged = 0, placement_record = 0, kind_at = 0, kind = 0, x_at = 0, placement_x = 0, z = 0;
	uint32_t kind_halfword = 0;

	offset_high = (uint8_t)(record_number >> 8);
	exchanged = offset_high | 0x1000u;
	offset_low = (uint8_t)exchanged;
	carry = (int8_t)offset_low < 0;
	offset_low = (uint32_t)offset_low << 1;
	offset_high = (uint8_t)(((uint32_t)(uint8_t)((uint32_t)offset_high << 8) << 1) | carry);
	carry = (int8_t)offset_low < 0;
	offset_low = (uint32_t)offset_low << 1;
	offset_high = (uint8_t)(((uint32_t)offset_high << 1) | carry);
	carry = (int8_t)offset_low < 0;
	placement_record = ending_placements_ADDRESS + (((((uint32_t)offset_high << 1) | carry) << 8) | (uint8_t)((uint32_t)offset_low << 1));
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
