/**
 *    Name:        objects/scenery_bank_15.c
 *    Description: bank 15's scenery: Krustyland's doors and booths, props, the cemetery's pieces
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    11-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the game's 053248 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

/* Sets up the kind 9E object. */
uint16_t kind_9e_spawner_start(uint16_t object)
{
	uint16_t setup = 0;
	uint8_t state = 0;

	setup = kind_9e_spawner_setup_ADDRESS;
	vector_object_setup(object, setup);
	OBJECT(object)->flags = 0x80u;
	OBJECT(object)->attributes = 0x50u;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
	kind_9e_spawner_wait();
	return setup;
}

/* Does nothing once the object has been put in. */
void kind_9e_spawner_wait(void)
{
}

/* Once the camera reaches 0190, puts in bank 18's list 1 type 22 object beside it. */
uint16_t kind_9e_spawner_put_in_object(uint16_t object, uint16_t child)
{
	uint32_t carry = 0;
	uint16_t ignored16 = 0, ignored16_2 = 0;
	uint8_t state = 0;

	if (camera_x < 0x190u)
		return child;
	leftover_y = kind_9e_spawner_object_child_ADDRESS;
	vector_spawn_child(object, &ignored16, &child, &ignored16_2, &carry);
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
	return child;
}

/* Sets up the kind AC object. */
uint16_t kind_ac_start(uint16_t object)
{
	uint16_t setup = 0;
	uint8_t state = 0;

	setup = kind_ac_setup_ADDRESS;
	vector_object_setup(object, setup);
	OBJECT(object)->attributes = 0x10u;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
	return setup;
}

/* Does nothing until something moves the object to its next step. */
void kind_ac_wait(void)
{
}

/* Drops a piece of food and shows its next animation. */
uint16_t kind_ac_drop_food(uint16_t object)
{
	uint32_t carry = 0;
	uint16_t food = 0, ignored16 = 0, ignored16_2 = 0;
	uint8_t state = 0;

	OBJECT(object)->flags = 0x80u;
	leftover_y = kind_ac_drop_food_child_ADDRESS;
	vector_spawn_child(object, &ignored16, &food, &ignored16_2, &carry);
	if (carry == 0u)
	{
		kind_ac_done();
		return food;
	}
	OBJECT(object)->animation = 0x82u;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
	kind_ac_done();
	return food;
}

/* Does nothing after the food is dropped. */
void kind_ac_done(void)
{
}

/* Sets up the kind AB object, good for three hits. */
uint16_t kind_ab_start(uint16_t object)
{
	uint16_t setup = 0;
	uint8_t state = 0;

	setup = kind_ab_setup_ADDRESS;
	vector_object_setup(object, setup);
	OBJECT(object)->attributes = 0x10u;
	OBJECT(object)->kind_ab.let_outs_left = 3u;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
	return setup;
}

/* Waits until a player hits it, then shows its hit animation. */
void kind_ab_wait_hit(uint16_t object)
{
	uint8_t state = 0;

	if ((OBJECT(object)->flags & 0x20u) != 0u)
	{
		OBJECT(object)->flags = 0x80u;
		OBJECT(object)->animation = 0x82u;
		state = OBJECT(object)->state;
		OBJECT(object)->state = state + 1u;
	}
}

/* When the hit animation ends, lets out bank 16's list 1 type 01 object; after the third it stays still. */
uint16_t kind_ab_let_out(uint16_t object, uint16_t child)
{
	uint32_t carry = 0;
	uint16_t ignored16 = 0, ignored16_2 = 0;
	uint8_t animation_flags = 0, child_out = 0, let_outs_left = 0, state = 0;

	animation_flags = OBJECT(object)->animation_flags;
	if ((animation_flags & 1u) == 0u)
		return child;
	OBJECT(object)->kind_ab.child_out = 0u;
	leftover_y = kind_ab_let_out_child_ADDRESS;
	vector_spawn_child(object, &ignored16, &child, &ignored16_2, &carry);
	if (carry)
	{
		OBJECT(object)->parent = child;
		child_out = OBJECT(object)->kind_ab.child_out;
		OBJECT(object)->kind_ab.child_out = child_out + 1u;
	}
	OBJECT(object)->timer = 0x40u;
	OBJECT(object)->animation = 0x81u;
	let_outs_left = OBJECT(object)->kind_ab.let_outs_left;
	OBJECT(object)->kind_ab.let_outs_left = let_outs_left - 1u;
	if (let_outs_left != 1u)
	{
		state = OBJECT(object)->state;
		OBJECT(object)->state = state + 1u;
		return child;
	}
	OBJECT(object)->animation = 0x80u;
	OBJECT(object)->state = 5u;
	return child;
}

/* Waits until the object it let out reaches its second step. */
uint16_t kind_ab_wait_child(uint16_t object, uint16_t states)
{
	uint16_t child = 0;
	uint8_t child_out = 0, state = 0, state_2 = 0, state_3 = 0;
	uint16_t parent = 0;

	child_out = OBJECT(object)->kind_ab.child_out;
	if (child_out == 0u)
	{
		state = OBJECT(object)->state;
		OBJECT(object)->state = state + 1u;
		return states;
	}
	parent = OBJECT(object)->parent;
	child = parent;
	state_2 = OBJECT(child)->state;
	if (state_2 == 2u)
	{
		state_3 = OBJECT(object)->state;
		OBJECT(object)->state = state_3 + 1u;
		OBJECT(object)->kind_ab.child_out = 0u;
	}
	return child;
}

/* Rests 64 frames, then waits for the next hit. */
void kind_ab_rest(uint16_t object)
{
	uint8_t timer = 0;

	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer != 1u)
	{
		kind_ab_done();
		return;
	}
	OBJECT(object)->flags = 0xC0u;
	OBJECT(object)->state = 1u;
	kind_ab_done();
}

/* Does nothing (the step after its last hit). */
void kind_ab_done(void)
{
}

/* Sets up a Krustyland door: its wait, its list of releases and the object it lets out. */
uint16_t krustyland_door_start(uint16_t object)
{
	uint16_t door_release = 0, krustyland_door = 0, setup = 0;
	uint8_t parameter = 0, state = 0;
	uint16_t wait = 0, trigger_at_x = 0, releases = 0, players = 0;

	setup = krustyland_door_setup_ADDRESS;
	vector_object_setup(object, setup);
	OBJECT(object)->flags = 0x80u;
	OBJECT(object)->attributes = 0x20u;
	parameter = OBJECT(object)->parameter;
	krustyland_door = krustyland_doors_ADDRESS + (int8_t)(((uint32_t)parameter << 1) << 1);
	wait = (((uint32_t)KRUSTYLAND_DOOR(krustyland_door)->wait << 8u) | KRUSTYLAND_DOOR(krustyland_door)->trigger_x);
	OBJECT(object)->timer = wait >> 8;
	trigger_at_x = (wait & 0xFFu) << 4;
	OBJECT(object)->krustyland_door.trigger_x = trigger_at_x;
	releases = KRUSTYLAND_DOOR(krustyland_door)->releases;
	door_release = releases;
	OBJECT(object)->krustyland_door.release = door_release;
	players = (((uint32_t)DOOR_RELEASE(door_release - 0x2u)->players << 8u) | DOOR_RELEASE(door_release - 0x2u)->wait);
	OBJECT(object)->krustyland_door.released_object = players;
	OBJECT(object)->krustyland_door.list_ended = 0u;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
	leftover_y = door_release;
	return krustyland_door;
}

/* Waits until the camera reaches 04E0. */
void krustyland_door_wait_camera(uint16_t object)
{
	uint8_t state = 0;

	if (camera_x >= 0x4E0u)
	{
		state = OBJECT(object)->state;
		OBJECT(object)->state = state + 1u;
	}
}

/* After its wait, with at most 4 enemies about, opens (sound 1400) and lets out its object if enough
   players play. */
uint16_t krustyland_door_open(uint16_t object, uint16_t released_child)
{
	uint32_t carry = 0;
	uint8_t players_needed = 0, timer = 0;
	uint16_t command = 0, ignored16 = 0, release = 0;
	uint8_t timer_2 = 0, enemies = 0, list_ended = 0, state = 0, state_2 = 0;
	uint16_t release_2 = 0, players = 0, released_object = 0;

	timer_2 = OBJECT(object)->timer;
	OBJECT(object)->timer = timer_2 - 1u;
	if (timer_2 != 1u)
		return released_child;
	enemies = io_read8(enemies_present);
	if (enemies > 4u)
	{
		OBJECT(object)->timer = 1u;
		return released_child;
	}
	command = 0x1400u;
	vector_queue_sound(command);
	OBJECT(object)->animation = 0xA3u;
	release_2 = OBJECT(object)->krustyland_door.release;
	release = release_2;
	leftover_y = release;
	players = (((uint32_t)DOOR_RELEASE(release)->players << 8u) | DOOR_RELEASE(release)->wait);
	timer = (uint8_t)players;
	players_needed = (uint8_t)(players >> 8);
	if ((int16_t)players < 0)
	{
		list_ended = OBJECT(object)->krustyland_door.list_ended;
		OBJECT(object)->krustyland_door.list_ended = list_ended + 1u;
		state = OBJECT(object)->state;
		OBJECT(object)->state = state + 1u;
		return released_child;
	}
	OBJECT(object)->timer = timer;
	release += 2u;
	OBJECT(object)->krustyland_door.release = release;
	if (players_needed < player_count)
	{
		released_object = OBJECT(object)->krustyland_door.released_object;
		leftover_y = released_object;
		vector_spawn_child(object, &release, &released_child, &ignored16, &carry);
	}
	state_2 = OBJECT(object)->state;
	OBJECT(object)->state = state_2 + 1u;
	leftover_y = release;
	return released_child;
}

/* When the door has opened, waits 96 frames; after its last release it goes away. */
void krustyland_door_opened(uint16_t object)
{
	uint8_t animation_flags = 0, state = 0, list_ended = 0;

	animation_flags = OBJECT(object)->animation_flags;
	if (animation_flags & 1u)
	{
		state = OBJECT(object)->state;
		OBJECT(object)->state = state + 1u;
		OBJECT(object)->krustyland_door.open_time = 0x60u;
		list_ended = OBJECT(object)->krustyland_door.list_ended;
		if (list_ended != 0u)
			OBJECT(object)->flags = 0u;
	}
}

/* After the wait, closes the door (animation A4). */
void krustyland_door_close(uint16_t object)
{
	uint8_t open_time = 0, state = 0;

	open_time = OBJECT(object)->krustyland_door.open_time;
	OBJECT(object)->krustyland_door.open_time = open_time - 1u;
	if (open_time == 1u)
	{
		OBJECT(object)->animation = 0xA4u;
		state = OBJECT(object)->state;
		OBJECT(object)->state = state + 1u;
	}
}

/* When the door has closed, waits for the next release. */
void krustyland_door_closed(uint16_t object)
{
	uint8_t animation_flags = 0;

	animation_flags = OBJECT(object)->animation_flags;
	if (animation_flags & 1u)
		OBJECT(object)->state = 2u;
}

/* Sets up the kind B2 object with the bear (bank 17's kind A2) beside it. */
uint16_t kind_b2_leaper_start(uint16_t object)
{
	uint32_t carry = 0;
	uint16_t ignored16 = 0, ignored16_2 = 0, parent = 0, setup = 0;
	uint8_t state = 0;

	setup = kind_b2_leaper_setup_ADDRESS;
	vector_object_setup(object, setup);
	OBJECT(object)->flags = 0x80u;
	OBJECT(object)->shadow_player = 0x40u;
	OBJECT(object)->attributes = 0x10u;
	leftover_y = kind_b2_leaper_child_ADDRESS;
	vector_spawn_child(object, &ignored16, &parent, &ignored16_2, &carry);
	if (carry == 0u)
	{
		OBJECT(object)->state = 6u;
		kind_b2_leaper_idle();
		return parent;
	}
	OBJECT(object)->parent = parent;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
	return parent;
}

/* Does nothing (when there was no slot for its bear). */
void kind_b2_leaper_idle(void)
{
}

/* When its bear starts off, leaps away with sound 5C00. */
uint16_t kind_b2_leaper_jump(uint16_t object)
{
	uint16_t command = 0, object_2 = 0;
	uint8_t state = 0, state_2 = 0;
	uint16_t parent = 0;

	parent = OBJECT(object)->parent;
	object_2 = parent;
	state = OBJECT(object_2)->state;
	if (state != 3u)
		return object_2;
	command = 0x5C00u;
	vector_queue_sound(command);
	OBJECT(object)->floor_z = 0u;
	OBJECT(object)->x_speed = 0x80;
	OBJECT(object)->y_speed = -0x100;
	OBJECT(object)->z_speed = 0x600;
	OBJECT(object)->timer = 0x10u;
	state_2 = OBJECT(object)->state;
	OBJECT(object)->state = state_2 + 1u;
	return object_2;
}

/* Falls; on landing plays sound 5D00 and stops. */
void kind_b2_leaper_fall(uint16_t object)
{
	uint32_t carry = 0;
	uint16_t command = 0, ignored16 = 0;
	uint8_t timer = 0, state = 0;

	vector_apply_gravity(object, &ignored16, &carry);
	if (carry == 0u)
	{
		timer = OBJECT(object)->timer;
		OBJECT(object)->timer = timer - 1u;
		if (timer == 1u)
			OBJECT(object)->animation = 0x84u;
		return;
	}
	command = 0x5D00u;
	vector_queue_sound(command);
	OBJECT(object)->x_speed = 0;
	OBJECT(object)->y_speed = 0;
	OBJECT(object)->flags = 0xC0u;
	OBJECT(object)->timer = 0x20u;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
}

/* Hurts the enemies it lands on for a frame. */
void kind_b2_leaper_crash(uint16_t object)
{
	uint8_t state = 0;

	OBJECT(object)->flags = 0x80u;
	OBJECT(object)->attack = 0x14u;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
	check_hits_with_enemies(object);
}

/* Waits 32 frames after landing. */
void kind_b2_leaper_wait(uint16_t object)
{
	uint8_t timer = 0, state = 0;

	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer == 1u)
	{
		OBJECT(object)->timer = 0x10u;
		state = OBJECT(object)->state;
		OBJECT(object)->state = state + 1u;
	}
}

/* Blinks for 16 frames and goes away. */
void kind_b2_leaper_vanish(uint16_t object)
{
	uint8_t timer = 0;

	OBJECT(object)->flags ^= 0x84u;
	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer == 1u)
		OBJECT(object)->flags = 0u;
}

/* Sets a prop up by its spawn's state: its kind, animation, attributes and the x it goes away at. */
uint16_t prop_start(uint16_t object)
{
	uint16_t prop = 0, setup = 0;
	uint8_t parameter = 0, state = 0;
	uint16_t kind = 0, attributes = 0, leave_at_x = 0;

	setup = prop_setup_ADDRESS;
	vector_object_setup(object, setup);
	OBJECT(object)->flags = 0x80u;
	parameter = OBJECT(object)->parameter;
	prop = props_ADDRESS + (int8_t)(((uint32_t)parameter << 1) << 1);
	kind = (((uint32_t)PROP(prop)->kind << 8u) | PROP(prop)->animation);
	OBJECT(object)->kind = (uint8_t)(kind >> 8u);
	OBJECT(object)->animation = (uint8_t)kind;
	attributes = (((uint32_t)PROP(prop)->attributes << 8u) | PROP(prop)->leave_x);
	OBJECT(object)->attributes = attributes >> 8;
	leave_at_x = (attributes & 0xFFu) << 4;
	OBJECT(object)->prop.leave_x = leave_at_x;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
	return prop;
}

/* Takes the prop away once the scroll brings it left of its x. */
void prop_leave(uint16_t object)
{
	uint16_t screen_x = 0, leave_x = 0;

	screen_x = OBJECT(object)->x;
	leave_x = OBJECT(object)->prop.leave_x;
	if (screen_x < leave_x)
		OBJECT(object)->flags = 0u;
}

/* Sets up the kind AA object of stage 8. */
uint16_t kind_aa_start(uint16_t object)
{
	uint16_t setup = 0;
	uint8_t state = 0;

	setup = kind_aa_setup_ADDRESS;
	vector_object_setup(object, setup);
	OBJECT(object)->flags = 0x80u;
	OBJECT(object)->attributes = 0x10u;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
	kind_aa_idle();
	return setup;
}

/* Does nothing. */
void kind_aa_idle(void)
{
}

/* Sets up the kind AA object of stage 7; the first puts in its pair ahead of it. */
uint16_t kind_aa_pair_start(uint16_t object)
{
	uint32_t carry = 0;
	uint16_t ignored16 = 0, ignored16_2 = 0, u = 0;
	uint8_t state = 0, parameter = 0;

	u = kind_aa_pair_setup_ADDRESS;
	vector_object_setup(object, u);
	OBJECT(object)->flags = 0x80u;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
	parameter = OBJECT(object)->parameter;
	if (parameter != 0u)
	{
		OBJECT(object)->attributes = 0x10u;
		OBJECT(object)->animation = 0x84u;
		OBJECT(object)->z = 0u;
		return u;
	}
	OBJECT(object)->attributes = 0x20u;
	leftover_y = kind_aa_pair_child_ADDRESS;
	vector_spawn_child(object, &ignored16, &u, &ignored16_2, &carry);
	return u;
}

/* Takes the object away near the screen's left edge. */
void kind_aa_pair_leave(uint16_t object)
{
	uint16_t screen_x = 0;

	screen_x = OBJECT(object)->x;
	if (screen_x < 0x20u)
		OBJECT(object)->flags = 0u;
}

/* Sets up the kind CB object, good for three hits. */
uint16_t kind_cb_start(uint16_t object)
{
	uint16_t setup = 0;
	uint8_t state = 0;

	setup = kind_cb_setup_ADDRESS;
	vector_object_setup(object, setup);
	OBJECT(object)->attributes = 0x60u;
	OBJECT(object)->kind_cb.hits_left = 3u;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
	kind_cb_done();
	return setup;
}

/* Does nothing after its third hit. */
void kind_cb_done(void)
{
}

/* Waits until a player hits it, then shows its hit animation. */
void kind_cb_wait_hit(uint16_t object)
{
	uint8_t state = 0;

	if ((OBJECT(object)->flags & 0x20u) != 0u)
	{
		OBJECT(object)->flags = 0x80u;
		OBJECT(object)->animation = 0x81u;
		state = OBJECT(object)->state;
		OBJECT(object)->state = state + 1u;
	}
}

/* When the hit animation ends, rests; after the third hit it stays as it is. */
void kind_cb_hit_end(uint16_t object)
{
	uint8_t animation_flags = 0, hits_left = 0, state = 0;

	animation_flags = OBJECT(object)->animation_flags;
	if ((animation_flags & 1u) == 0u)
		return;
	OBJECT(object)->timer = 0x80u;
	OBJECT(object)->animation = 0x80u;
	hits_left = OBJECT(object)->kind_cb.hits_left;
	OBJECT(object)->kind_cb.hits_left = hits_left - 1u;
	if (hits_left != 1u)
	{
		state = OBJECT(object)->state;
		OBJECT(object)->state = state + 1u;
		return;
	}
	OBJECT(object)->state = 4u;
}

/* Rests 128 frames, then waits for the next hit. */
void kind_cb_rest(uint16_t object)
{
	uint8_t timer = 0;

	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer == 1u)
	{
		OBJECT(object)->flags = 0xC0u;
		OBJECT(object)->state = 1u;
	}
}

/* Sets up the flung kind D1 piece: its x and height speeds by its spawn's state. */
uint16_t kind_d1_fling_start(uint16_t object)
{
	uint16_t kind_d1_fling = 0, setup = 0;
	uint8_t parameter = 0, state = 0;
	uint16_t x_speed = 0, z_speed = 0;

	setup = kind_d1_fling_setup_ADDRESS;
	vector_object_setup(object, setup);
	OBJECT(object)->attributes = 0x10u;
	OBJECT(object)->zoom_x = 0x60u;
	OBJECT(object)->zoom_y = 0x60u;
	OBJECT(object)->flags = 0x90u;
	parameter = OBJECT(object)->parameter;
	kind_d1_fling = kind_d1_flings_ADDRESS + (uint8_t)(((parameter & 3u) << 1) << 1);
	x_speed = KIND_D1_FLING(kind_d1_fling)->x_speed;
	OBJECT(object)->x_speed = x_speed;
	z_speed = KIND_D1_FLING(kind_d1_fling)->z_speed;
	OBJECT(object)->z_speed = z_speed;
	OBJECT(object)->timer = 0x40u;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
	return kind_d1_fling;
}

/* Shrinks the piece as it flies; after 64 frames it vanishes with sound 2000. */
void kind_d1_fling_shrink(uint16_t object)
{
	uint16_t command = 0, zoom_x = 0;
	uint8_t timer = 0;
	uint16_t zoom_x_2 = 0;

	OBJECT(object)->flags = 0x90u;
	zoom_x_2 = (((uint32_t)OBJECT(object)->zoom_x << 8u) | OBJECT(object)->zoom_y);
	zoom_x = zoom_x_2 - 0x101u;
	if (zoom_x >= 0x1010u)
	{
		OBJECT(object)->zoom_x = (uint8_t)(zoom_x >> 8u);
		OBJECT(object)->zoom_y = (uint8_t)zoom_x;
	}
	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer != 1u)
		return;
	command = 0x2000u;
	vector_queue_sound(command);
	OBJECT(object)->flags = 0u;
}

/* Sets a cemetery piece up at x 009A, with the height and animation its spawn's state picks. */
uint16_t cemetery_piece_start(uint16_t object)
{
	uint16_t cemetery_piece = 0, setup = 0;
	uint8_t parameter = 0, animation = 0, state = 0;
	uint16_t z = 0;

	setup = cemetery_piece_setup_ADDRESS;
	vector_object_setup(object, setup);
	OBJECT(object)->x = 0x9Au;
	parameter = OBJECT(object)->parameter;
	cemetery_piece = cemetery_pieces_ADDRESS + (int8_t)(((uint32_t)parameter << 1) << 1);
	z = CEMETERY_PIECE(cemetery_piece)->z;
	OBJECT(object)->z = z;
	animation = CEMETERY_PIECE(cemetery_piece)->animation;
	OBJECT(object)->animation = animation;
	OBJECT(object)->attributes = 0x20u;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
	cemetery_piece_bob(object);
	return cemetery_piece;
}

/* Moves the piece up and down with the stage's vertical speed (48E2). */
void cemetery_piece_bob(uint16_t object)
{
	OBJECT(object)->z_speed = cemetery_scroll_speed;
}
