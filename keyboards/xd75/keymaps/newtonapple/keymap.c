/* Copyright 2018 David Dai <newtonapple>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
// #include "xd75.h"
#include QMK_KEYBOARD_H
#include "newtonapple.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * .---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------.
 * | MOUSE » `    | 1      | 2         | 3         | 4            | 5      | CMD+[  | SNAP CENTER  |  CMD+] | 6        | 7          | 8        | 9         | 0         | BACKSP      |
 * |--------------+--------+-----------+-----------+--------------+--------+--------+--------------+--------+----------+------------+----------+-----------+-------------------------|
 * | MOUSE » TAB  | Q      | W         | E         | R            | T      | CMD+{  | SNAP MAX     |  CMD+} | Y        | U          | I        | O         | P         | BACKSP      |
 * |--------------+--------+-----------+-----------+--------------+--------+--------+--------------+--------+----------+------------+----------+-----------------------+-------------|
 * | MAC » ESC    | A      | S         | D         | F            | G      | HOME   | SNAP BACK    | PG UP  | H        | J          | K        | L         | ;         | ENTER       |
 * |--------------+--------+-----------+-----------+--------------+--------+--------+--------------+--------+----------+------------+----------------------------------+-------------|
 * | LSHIFT » (   | Z      | X         | C         | V            | B      | END    | UP           | PG DN  | N        | M          | ,        | .         | /         | RSHIFT » )  |
 * |--------------+--------+-----------+-----------+--------------+-----------------+--------------+--------+----------+------------+----------------------+-----------+-------------|
 * | LCTRL » {    | LCTRL  | LALT » [  | LGUI » =  | NUM » SPACE  | SPACE  | LEFT   | DOWN         | RIGHT  | MAC » "  | SHIFT » '  | NUM » -  | LGUI » _  | RALT » ]  | RCTRL » }   |
 * '---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------'
 */

 [_QWERTY] = LAYOUT_ortho_5x15_wrapper(
	 ________________ORTHO_GRID_QWERTY_L0________________, DF(_CODE),  SNAP_MAX,    INDENT,     ________________ORTHO_GRID_QWERTY_R0________________,
	 ________________ORTHO_GRID_QWERTY_L1________________, PREV_TAB,   SNAP_CENTER, NEXT_TAB,   ________________ORTHO_GRID_QWERTY_R1________________,
	 ________________ORTHO_GRID_QWERTY_L2________________, KC_HOME,    SNAP_BACK,   KC_PGUP,    ________________ORTHO_GRID_QWERTY_R2________________,
	 ________________ORTHO_GRID_QWERTY_L3________________, KC_END,     KC_UP,       KC_PGDN,    ________________ORTHO_GRID_QWERTY_R3________________,
	 ________________ORTHO_GRID_QWERTY_L4________________, MOUSE_LEFT, KC_DOWN,     CTL_T_RGHT, ________________ORTHO_GRID_QWERTY_R4________________
 ),

 [_CODE] = LAYOUT_ortho_5x15_wrapper(
	 ________________ORTHO_GRID_QWERTY_L0________________, DF(_QWERTY), SNAP_MAX,    INDENT,     ________________ORTHO_GRID_QWERTY_R0________________,
	 ________________ORTHO_GRID_QWERTY_L1________________, PREV_TAB,    SNAP_CENTER, NEXT_TAB,   ________________ORTHO_GRID_QWERTY_R1________________,
	 ________________ORTHO_GRID_QWERTY_L2________________, KC_HOME,     SNAP_BACK,   KC_PGUP,    ________________ORTHO_GRID_QWERTY_R2________________,
	 ________________ORTHO_GRID_QWERTY_L3________________, KC_END,      KC_UP,       KC_PGDN,    ________________ORTHO_GRID_QWERTY_R3________________,
	 ________________ORTHO_GRID_QWERTY_L4________________, MOUSE_SPC,   KC_DOWN,     CTL_T_BSPC, ________________ORTHO_GRID_QWERTY_R4________________
 ),

 [_CAP] = LAYOUT_ortho_5x15_wrapper(
   _______________________________________________________________BLANK_15______________________________________________________________,
   _________________ORTHO_GRID_CAP_L1__________________, _________BLANK_3_________, _________________ORTHO_GRID_CAP_R1__________________,
   _________________ORTHO_GRID_CAP_L2__________________, _________BLANK_3_________, _________________ORTHO_GRID_CAP_R2__________________,
   _________________ORTHO_GRID_CAP_L3__________________, _________BLANK_3_________, _________________ORTHO_GRID_CAP_R3__________________,
   _______________________________________________________________BLANK_15______________________________________________________________
 ),

/* Mac System Shortcuts & Vim Movements
 * .-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------.
 * | Reset VIM Repeat | 1         | 2          | 3                 | 4          | 5          |            | QUIT        | CLOSE        | 6        | 7      | 8        | 9                | 0      |        |
 * |------------------+-----------+------------+-------------------+------------+------------+------------+-------------+--------------+----------+--------+----------+------------------+--------+--------|
 * |                  | CMD+LEFT  | Next Word  | ALT+RIGHT         | CMD+Z      | CMD+RIGHT  |            | SNAP MAX    | SNAP CENTER  | CMD+c    | CMD+z  |          | Insert New Line  | CMD+p  | CMD+x  |
 * |------------------+-----------+------------+-------------------+------------+------------+------------+-------------+--------------+----------+--------+----------+------------------+--------+--------|
 * | DEFAULT          | CMD+a     | CMD+s      | CUT Rest of Word  |            |            |            | SNAP BACk   |              | LEFT     | DOWN   | UP       | RIGHT            | CMD+c  |        |
 * |------------------+-----------+------------+-------------------+------------+------------+------------+-------------+--------------+----------+--------+----------+------------------+--------+--------|
 * | Toggle VIM Num   | CMD+z     | CUT Char   | CUT Word          | SELECT     | ALT+LEFT   |            | SNAP UP     |              | CMD+{    | CMD+}  | CMD+[    | CMD+]            |        |        |
 * |------------------+-----------+------------+-------------------+------------+------------+------------+-------------+--------------+----------+--------+----------+------------------+--------+--------|
 * |                  |           |            | SHIFT             | VIM Num    |            | SNAP LEFT  | SNAP DOWN   | SNAP RIGHT   | VIM Num  | SHIFT  | VIM Num  |                  |        |        |
 * '-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------'
 */

 [_MACVIM] = LAYOUT_ortho_5x15_wrapper(
	________________ORTHO_GRID_MACVIM_L0________________, _______,   QUIT,      CLOSE,       ________________ORTHO_GRID_MACVIM_R0________________,
	________________ORTHO_GRID_MACVIM_L1________________, _______,   SNAP_MAX,  SNAP_CENTER, ________________ORTHO_GRID_MACVIM_R1________________,
	________________ORTHO_GRID_MACVIM_L2________________, _______,   SNAP_BACK, _______,     ________________ORTHO_GRID_MACVIM_R2________________,
	________________ORTHO_GRID_MACVIM_L3________________, _______,   SNAP_UP,   _______,     ________________ORTHO_GRID_MACVIM_R3________________,
	________________ORTHO_GRID_MACVIM_L4________________, SNAP_LEFT, SNAP_DOWN, SNAP_RGHT,   ________________ORTHO_GRID_MACVIM_R4________________
 ),

 [_VIMNUM] = LAYOUT_ortho_5x15_wrapper(
	________________ORTHO_GRID_VIMNUM_L0________________, _________BLANK_3_________, ________________ORTHO_GRID_VIMNUM_R0________________,
	________________ORTHO_GRID_VIMNUM_L1________________, _________BLANK_3_________, ________________ORTHO_GRID_VIMNUM_R1________________,
	________________ORTHO_GRID_VIMNUM_L2________________, _________BLANK_3_________, ________________ORTHO_GRID_VIMNUM_R2________________,
	________________ORTHO_GRID_VIMNUM_L3________________, _________BLANK_3_________, ________________ORTHO_GRID_VIMNUM_R3________________,
	________________ORTHO_GRID_VIMNUM_L4________________, _________BLANK_3_________, ________________ORTHO_GRID_VIMNUM_R4________________
 ),


/* Mouse Movements
 * .-------------------------------------------------------------------------------------------------------------------------------------------------------------------------.
 * |         | ACC0   | ACC1   | ACC2  |        |        |             |            |              |            |             |              |             |        |        |
 * |---------+--------+--------+-------+--------+--------+-------------+------------+--------------+------------+-------------+--------------+-------------+--------+--------|
 * |         | CMD+q  | CMD+w  | ACC2  | CMD+r  | PG UP  |             | SCRL_UP    |              | CMD+c      | CMD+u       | CMD+{        | CMD+}       | CMD+a  | CMD+x  |
 * |---------+--------+--------+-------+--------+--------+-------------+------------+--------------+------------+-------------+--------------+-------------+--------+--------|
 * | DEFAULT | CMD+a  | ACC2   | ACC0  | ACC1   | PG DN  | SCRL_LEFT   | SCRL_DOWN  | SCRL_RIGHT   | LEFT       | DOWN        | UP           | RIGHT       | CMD+c  | CMD+v  |
 * |---------+--------+--------+-------+--------+--------+-------------+------------+--------------+------------+-------------+--------------+-------------+--------+--------|
 * |         |        |        |       | SHIFT  |        | LEFT_CLICK  | UP         | RIGHT_CLICK  | SCRL_LEFT  | SCRL_DOWN   | SCRL_UP      | SCRL_RIGHT  |        |        |
 * |------- -+--------+--------+-------+--------+--------+-------------+------------+--------------+------------+-------------+--------------+-------------+--------+--------|
 * |         |        |        |       | SHIFT  | ACC0   | LEFT        | DOWN       | RIGHT        | LEFT_CLICK | LEFT_CLICK  | RIGHT_CLICK  | MID_CLICK   |        |        |
 * '-------------------------------------------------------------------------------------------------------------------------------------------------------------------------'
 */
 [_MOUSE] = LAYOUT_ortho_5x15_wrapper(
	________________ORTHO_GRID_MOUSE_L0_________________, _______, _______,  _______, ________________ORTHO_GRID_MOUSE_R0_________________,
	________________ORTHO_GRID_MOUSE_L1_________________, _______, KC_WH_U,  _______, ________________ORTHO_GRID_MOUSE_R1_________________,
	________________ORTHO_GRID_MOUSE_L2_________________, KC_WH_L, KC_WH_D,  KC_WH_R, ________________ORTHO_GRID_MOUSE_R2_________________,
	________________ORTHO_GRID_MOUSE_L3_________________, KC_BTN1, KC_MS_UP, KC_BTN2, ________________ORTHO_GRID_MOUSE_R3_________________,
	________________ORTHO_GRID_MOUSE_L4_________________, KC_MS_L, KC_MS_D,  KC_MS_R, ________________ORTHO_GRID_MOUSE_R4_________________
 ),

/* NUMBERS
 * .---------------------------------------------------------------------------------------------------------------------------------------.
 * | F1      | F2     | F3     | F4     | F5     | F6     |        | SLEEP  | LED    | F7     | F8     | F9     | F10    | F11    | F12    |
 * |---------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |         |        | `      | =      | -      | +      | P7     | P8     | P9     |        | [      | \      | ]      | _      |        |
 * |---------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | DEFAULT | 1      | 2      | 3      | 4      | 5      | P4     | P5     | P6     | 6      | 7      | 8      | 9      | 0      |        |
 * |---------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |         |        | MOUSE  | MACVIM | '      | "      | P1     | P2     | P3     | {      | }      |        |        |        |        |
 * |---------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |         |        |        |        | SHIFT  |        | P0     | P.     | Enter  | SYM    |        |        |        |        | RESET  |
 * '---------------------------------------------------------------------------------------------------------------------------------------'
 */

 [_NUM] = LAYOUT_ortho_5x15_wrapper(
	KC_F1,   KC_F2,   KC_F3,     KC_F4,   KC_F5,     KC_F6,      _______, SLEEP,   TG(_LED), KC_F7,      KC_F8,      KC_F9,      KC_F10,  KC_F11,     KC_F12 ,
	_______, KC_GRV,  S(KC_GRV), KC_EQL,  KC_MINS,   S(KC_EQL),  KC_P7,   KC_P8,   KC_P9,    S(KC_LBRC), S(KC_RBRC), S(KC_BSLS), KC_BSLS, S(KC_MINS), _______,
	DEFAULT, KC_1,    KC_2,      KC_3,    KC_4,      KC_5,       KC_P4,   KC_P5,   KC_P6,    KC_6,       KC_7,       KC_8,       KC_9,    KC_0,       _______,
	_______, _______, MOUSE,     MACVIM,  KC_QUOT,   S(KC_QUOT), KC_P1,   KC_P2,   KC_P3,    KC_LBRC,    KC_RBRC,    _______,    _______, _______,    _______,
	_______, _______, _______,   _______, KC_LSFT,   _______,    KC_P0,   KC_PDOT, KC_ENT,   OSL_SYM,    _______,    _______,    _______, _______,    RESET
 ),

/* SYMBOLS
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * | F1     | F2     | F3     | F4     | F5     | F6     |        |        |        | F7     | F8     | F9     | F10    | F11    | F12    |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | NUM    |        | ~      | +      | _      | +      | P7     | P8     | P9     | {      | }      | |      | \      | _      |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | CAP    | !      | @      | #      | $      |  %     | P4     | P5     | P6     | ^      | &      | *      | (      | )      |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        | MOUSE  | MACVIM | '      | "      | P1     | P2     | P3     | [      | ]      |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        |        |        |        |        | P0     |        | P.     |        | "      | _      |        |        | RESET  |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */

 [_SYM] = LAYOUT_ortho_5x15_wrapper(
	KC_F1,   KC_F2,    KC_F3,     KC_F4,   KC_F5,      KC_F6,      _______, SLEEP,   TG(_LED), KC_F7,      KC_F8,      KC_F9,      KC_F10,  KC_F11,     KC_F12 ,
	NUM,     KC_GRV,   S(KC_GRV), KC_EQL,  KC_MINS,    S(KC_EQL),  KC_P7,   KC_P8,   KC_P9,    S(KC_LBRC), S(KC_RBRC), S(KC_BSLS), KC_BSLS, S(KC_MINS), _______,
	CAP,     S(KC_1),  S(KC_2),   S(KC_3), S(KC_4),    S(KC_5),    KC_P4,   KC_P5,   KC_P6,    S(KC_6),    S(KC_7),    S(KC_8),    S(KC_9), S(KC_0),    _______,
	_______, _______,  MOUSE,     MACVIM,  KC_QUOT,    S(KC_QUOT), KC_P1,   KC_P2,   KC_P3,    KC_LBRC,    KC_RBRC,    _______,    _______, _______,    _______,
	_______, _______,  _______,   _______, _______,    _______,    KC_P0,   KC_PDOT, KC_ENT,   KC_BSPC,    S(KC_QUOT), S(KC_MINS), _______, _______,    _______
 ),

 [_LED] = LAYOUT_ortho_5x15_wrapper(
	RGB_TOG, RGB_M_P, RGB_M_B, RGB_M_R, RGB_M_SW, RGB_M_SN, _______,  _______, TG(_LED), RGB_M_K, RGB_M_X, RGB_M_G, RGB_M_T, _______, TG(_LED),
	_______, BL_TOGG, BL_OFF,  BL_ON,   _______,  _______,  RGB_RMOD, _______, RGB_MOD,  _______, _______, _______, _______, _______, _______,
	DEFAULT, BL_BRTG, BL_DEC,  BL_INC,  _______,  _______,  RGB_SAI,  RGB_TOG, RGB_HUI,  _______, _______, _______, _______, _______, _______,
	_______, _______, _______, _______, VLK_TOG,  _______,  RGB_SAD,  RGB_VAI, RGB_HUD,  _______, _______, _______, _______, _______, _______,
	_______, _______, _______, _______, _______,  _______,  RGB_SPD,  RGB_VAD, RGB_SPI,  _______, _______, _______, _______, _______, _______
 )
};

void matrix_scan_user(void) {
  #ifdef RGBLIGHT_ENABLE
  rgb_matrix_scan();
  #endif
}

#define IS_LAYER_ON_STATE(layer, state) (state & (1UL << (layer)))

uint32_t layer_state_set_user(uint32_t state) {
  #ifdef ENABLE_MACVIM
  if ( !(IS_LAYER_ON_STATE(_MACVIM, state) || IS_LAYER_ON_STATE(_VIMNUM, state)) ) {
    reset_vim_states();
  }
  #endif
  return state;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  #ifdef ENABLE_SPACE_CADET
  static uint16_t space_cadet_timer;
  SPACE_CADET_LAYER(keycode, MACVIM_SQUOT, _MACVIM, "\"", record->event.pressed);
  SPACE_CADET_LAYER(keycode, SYM_SMINS, _SYM, "_", record->event.pressed);
  SPACE_CADET(keycode, CRTL_SLBRC, KC_LCTRL, "{", record->event.pressed);
  SPACE_CADET(keycode, CRTL_SRBRC, KC_RCTRL, "}", record->event.pressed);
  SPACE_CADET(keycode, CMD_SMINS, KC_RCMD, "_", record->event.pressed);
  #endif
  return process_macvim(keycode, record, IS_LAYER_ON(_MACVIM));
}

