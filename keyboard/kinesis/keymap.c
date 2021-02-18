/*
Copyright 2014 Warren Janssens <warren.janssens@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#include <stdint.h>
#include <stdbool.h>
#include <avr/pgmspace.h>
#include <util/delay.h>
#include "keycode.h"
#include "action.h"
#include "action_code.h"
#include "action_macro.h"
#include "bootloader.h"
#include "report.h"
#include "host.h"
#include "print.h"
#include "debug.h"
#include "keymap.h"
#include "action_layer.h"
#include "config.h"

#define KEYMAP(                           \
    kA2,kC2,kB2,kA1,kC1,kB1,kA0,kC0,kB0,  \
                                          \
    kI0,kH0,kG0,kF0,kE0,kD0,              \
    kI1,kH1,kG1,kF1,kE1,kD1,              \
    kI2,kH2,kG2,kF2,kE2,kD2,              \
    kI3,kH3,kG3,kF3,kE3,kD3,              \
        kH4,kG4,kF4,kD4,                  \
                        kD6,kD5,          \
                            kF5,          \
                    kF6,kE6,kH5,          \
                                          \
    kA3,kC3,kB3,kA4,kC4,kB4,kA5,kI5,kI4,  \
                                          \
        kJ4,kK4,kL4,kN4,kO4,kP4,          \
        kJ5,kK5,kL5,kN5,kO5,kP5,          \
        kJ6,kK6,kL6,kN6,kO6,kP6,          \
        kJ7,kK7,kL7,kN7,kO7,kP7,          \
            kJ3,kL3,kN3,kO3,              \
    kE7,kG6,                              \
    kG7,                                  \
    kI7,kH6,kI6                           \
) {                                       \
	{ KC_##kA0,KC_##kA1,KC_##kA2,KC_##kA3,KC_##kA4,KC_##kA5,KC_NO   ,KC_NO   }, \
	{ KC_##kB0,KC_##kB1,KC_##kB2,KC_##kB3,KC_##kB4,KC_NO   ,KC_NO   ,KC_NO   }, \
	{ KC_##kC0,KC_##kC1,KC_##kC2,KC_##kC3,KC_##kC4,KC_NO   ,KC_NO   ,KC_NO   }, \
	{ KC_##kD0,KC_##kD1,KC_##kD2,KC_##kD3,KC_##kD4,KC_##kD5,KC_##kD6,KC_NO   }, \
	{ KC_##kE0,KC_##kE1,KC_##kE2,KC_##kE3,KC_NO   ,KC_NO   ,KC_##kE6,KC_##kE7}, \
	{ KC_##kF0,KC_##kF1,KC_##kF2,KC_##kF3,KC_##kF4,KC_##kF5,KC_##kF6,KC_NO   }, \
	{ KC_##kG0,KC_##kG1,KC_##kG2,KC_##kG3,KC_##kG4,KC_NO   ,KC_##kG6,KC_##kG7}, \
	{ KC_##kH0,KC_##kH1,KC_##kH2,KC_##kH3,KC_##kH4,KC_##kH5,KC_##kH6,KC_NO   }, \
	{ KC_##kI0,KC_##kI1,KC_##kI2,KC_##kI3,KC_NO   ,KC_NO   ,KC_##kI6,KC_##kI7}, \
	{ KC_NO   ,KC_NO   ,KC_NO   ,KC_##kJ3,KC_##kJ4,KC_##kJ5,KC_##kJ6,KC_##kJ7}, \
	{ KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,KC_##kK4,KC_##kK5,KC_##kK6,KC_##kK7}, \
	{ KC_NO   ,KC_NO   ,KC_NO   ,KC_##kL3,KC_##kL4,KC_##kL5,KC_##kL6,KC_##kL7}, \
	{ KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,KC_##kI4,KC_##kI5}, \
	{ KC_NO   ,KC_NO   ,KC_NO   ,KC_##kN3,KC_##kN4,KC_##kN5,KC_##kN6,KC_##kN7}, \
	{ KC_NO   ,KC_NO   ,KC_NO   ,KC_##kO3,KC_##kO4,KC_##kO5,KC_##kO6,KC_##kO7}, \
	{ KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,KC_##kP4,KC_##kP5,KC_##kP6,KC_##kP7} \
}
/*    4y0   A  4y1   B  4y2      4y3   D  4y4   E  4y5   F  4y6   G  4y7   H  5y0   I  5y1   J  5y2   K  5y3   L  5y4   M  5y5   N  5y6   O  5y7  P  */

/*
					A	B	C	D	E	F	G	H	I	J	K	L	M	N	O	P
					4y0	4y1	4y2	4y3	4y4	4y5	4y6	4y7	5y0	5y1	5y2	5y3	5y4	5y5	5y6	5y7
					r0	r1	r2	 r3 r4	r5	r6	r7	r8	r9	r10	r11	r12	r13	r14	r15
0	PB0		21	c0	f6	f8	f7	5	4	3	2	1	=+
1	PB1		22	c1	f3	f5	f4	t	r	e	w	q	TAB
2	PB2		23	c2	ESC	f2	f1	g	f	d	s	a	CL
3	PB3		24	c3	f9	f11	f10	b	v	c	x	z	LS	UP		DN		[{	]}
4	PB4		25	c4  f12	SL	PS	RT		LT	§±	`~		6	7	8		9	0	-_
5	PB5		26	c5	PB	PGM	KPD	LA		HM		END		y	u	i		o	p	\
6	PB6		27	c6  			LC	DEL	BS	RC	ENT	SP	h	j	k		l	;:	'"
7	PB7		28	c7					RA		PU		PD	n	m	,<		.>	/?	RS
*/

#if defined(KEYMAP_DVORAK)
#include "keymap_dvorak.h"
#elif defined(KEYMAP_COLEMAK)
#include "keymap_colemak.h"
#elif defined(KEYMAP_WORKMAN)
#include "keymap_workman.h"
#elif defined(KEYMAP_PROGRAMMER)
#include "keymap_programmer.h"
#else
#include "keymap_qwerty.h"
#endif


#define KEYMAPS_SIZE    (sizeof(keymaps) / sizeof(keymaps[0]))
#define FN_ACTIONS_SIZE (sizeof(fn_actions) / sizeof(fn_actions[0]))
#define FN_ACTIONS_1_SIZE   (sizeof(fn_actions_1) / sizeof(fn_actions_1[0]))
#define FN_ACTIONS_2_SIZE   (sizeof(fn_actions_2) / sizeof(fn_actions_2[0]))
#define FN_ACTIONS_3_SIZE   (sizeof(fn_actions_3) / sizeof(fn_actions_3[0]))

/* translates key to keycode */
uint8_t keymap_key_to_keycode(uint8_t layer, keypos_t key)
{
    uint8_t x;
    if (layer < KEYMAPS_SIZE) {
        x = pgm_read_byte(&keymaps[(layer)][(key.row)][(key.col)]);
    } else {
    // fall back to layer 0
        x = pgm_read_byte(&keymaps[0][(key.row)][(key.col)]);
    }
    dprintf("%d",x); dprintln();
    return x;
}

/* translates Fn keycode to action */
action_t keymap_fn_to_action(uint8_t keycode)
{
	uint8_t layer = biton32(layer_state);

	action_t action;
	action.code = ACTION_NO;

	if (layer == 1 && FN_INDEX(keycode) < FN_ACTIONS_1_SIZE) {
		action.code = pgm_read_word(&fn_actions_1[FN_INDEX(keycode)]);
	}
	if (layer == 2 && FN_INDEX(keycode) < FN_ACTIONS_2_SIZE) {
		action.code = pgm_read_word(&fn_actions_2[FN_INDEX(keycode)]);
	}
	if (layer == 3 && FN_INDEX(keycode) < FN_ACTIONS_3_SIZE) {
		action.code = pgm_read_word(&fn_actions_3[FN_INDEX(keycode)]);
	}
	// by default, use fn_actions from default layer 0
	// this is needed to get mapping for same key, that was used switch to some layer,
	// to have possibility to switch layers back
	if (action.code == ACTION_NO && FN_INDEX(keycode) < FN_ACTIONS_SIZE) {
		action.code = pgm_read_word(&fn_actions[FN_INDEX(keycode)]);
	}

	return action;
}


