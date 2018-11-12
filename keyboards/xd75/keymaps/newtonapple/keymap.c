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
 * .---------------------------------------------------------------------------------------------------------------------------------------------------------------.
 * | MOUSE » `   | 1      | 2      | 3        | 4       | 5     | =      | DISP OFF   | -      | 6            | 7         | 8      | 9      | 0      | BACKSP      |
 * |-------------+--------+--------+----------+---------+-------+--------+------------+--------+--------------+-----------+--------+--------+----------------------|
 * | MOUSE » TAB | Q      | W      | E        | R       | T     | [      | \          | ]      | Y            | U         | I      | O      | P      | BACKSP      |
 * |-------------+--------+--------+----------+---------+-------+--------+------------+--------+--------------+-----------+--------+-----------------+-------------|
 * | MAC » ESC   | A      | S      | D        | F       | G     | HOME   | DEL        | PG UP  | H            | J         | K      | L      | ;      | ENTER       |
 * |-------------+--------+--------+----------+---------+-------+--------+------------+--------+--------------+-----------+--------------------------+-------------|
 * | LSHIFT » (  | Z      | X      | C        | V       | B     | END    | UP         | PG DN  | N            | M         | ,      | .      | /      | RSHIFT » )  |
 * |-------------+--------+--------+----------+---------+----------------+------------+--------+--------------+-----------+-----------------+--------+-------------|
 * | LCTRL       | LCTRL  | LALT   | LGUI » = | NUM » - | SPACE | LEFT   | DOWN       | RIGHT  | MAC » SPACE  | SHIFT » ' | NUM    | RALT   | RGUI   | RCTRL       |
 * '---------------------------------------------------------------------------------------------------------------------------------------------------------------'
 */

 [_QWERTY] = LAYOUT_ortho_5x15(
   MOUSE_GRV,  KC_1,    KC_2,    KC_3,      KC_4,     KC_5,   KC_EQL,  DISP_OFF, KC_MINS, KC_6,       KC_7,        KC_8,    KC_9,    KC_0,     KC_BSPC,
   MOUSE_TAB,  KC_Q,    KC_W,    KC_E,      KC_R,     KC_T,   KC_LBRC, KC_BSLS,  KC_RBRC, KC_Y,       KC_U,        KC_I,    KC_O,    KC_P,     KC_BSPC,
   MACVIM_ESC, KC_A,    KC_S,    KC_D,      KC_F,     KC_G,   KC_HOME, KC_DEL,   KC_PGUP, KC_H,       KC_J,        KC_K,    KC_L,    KC_SCLN,  KC_ENT ,
   KC_LSPO,    KC_Z,    KC_X,    KC_C,      KC_V,     KC_B,   KC_END,  KC_UP,    KC_PGDN, KC_N,       KC_M,        KC_COMM, KC_DOT,  KC_SLSH,  KC_RSPC,
   KC_LCTL,    KC_LCTL, KC_LALT, GUI_T_EQL, SYM_MINS, KC_SPC, KC_LEFT, KC_DOWN,  KC_RGHT, MACVIM_SPC, SFT_T_QUOT,  OSL_NUM, KC_RGUI, KC_RALT,  KC_RCTL
 ),

 [_CAP] = LAYOUT_ortho_5x15(
   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
   _______, S(KC_Q), S(KC_W), S(KC_E), S(KC_R), S(KC_T), _______, _______, _______, S(KC_Y), S(KC_U), S(KC_I), S(KC_O), S(KC_P), _______,
   QWERTY,  S(KC_A), S(KC_S), S(KC_D), S(KC_F), S(KC_G), _______, _______, _______, S(KC_H), S(KC_J), S(KC_K), S(KC_L), _______, _______,
   _______, S(KC_Z), S(KC_X), S(KC_C), S(KC_V), S(KC_B), _______, _______, _______, S(KC_N), S(KC_M), _______, _______, _______, _______,
   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
 ),

/* NUMBERS
 * .---------------------------------------------------------------------------------------------------------------------------------------.
 * | F1      | F2     | F3     | F4     | F5     | F6     |        | SLEEP  |        | F7     | F8     | F9     | F10    | F11    | F12    |
 * |---------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |         |        | `      | =      | -      |        | P7     | P8     | P9     |        | [      | \      | ]      |        |        |
 * |---------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | QWERTY  | 1      | 2      | 3      | 4      | 5      | P4     | P5     | P6     | 6      | 7      | 8      | 9      | 0      |        |
 * |---------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |         |        | MOUSE  | MACVIM | '      | "      | P1     | P2     | P3     | {      | }      |        |        |        |        |
 * |---------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |         |        |        |        | SHIFT  |        | P0     |        | P.     | SYM    |        |        |        |        | RESET  |
 * '---------------------------------------------------------------------------------------------------------------------------------------'
 */

 [_NUM] = LAYOUT_ortho_5x15(
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,    KC_F6,      _______, SLEEP,   _______, KC_F7,      KC_F8,      KC_F9,   KC_F10,  KC_F11,  KC_F12 ,
  _______, _______, KC_GRV,  KC_EQL,  KC_MINS,  _______,    KC_P7,   KC_P8,   KC_P9,   _______,    KC_LBRC,    KC_BSLS, KC_RBRC, _______, _______,
  QWERTY,  KC_1,    KC_2,    KC_3,    KC_4,     KC_5,       KC_P4,   KC_P5,   KC_P6,   KC_6,       KC_7,       KC_8,    KC_9,   KC_0,     _______,
  _______, _______, MOUSE,   MACVIM,  KC_QUOT,  S(KC_QUOT), KC_P1,   KC_P2,   KC_P3,   S(KC_LBRC), S(KC_RBRC), _______, _______, _______, _______,
  _______, _______, _______, _______, KC_LSFT,  _______,    KC_P0,   _______, KC_PDOT, OSL_SYM,    _______,    _______, _______, _______, RESET
 ),

/* SYMBOLS
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * | F1     | F2     | F3     | F4     | F5     | F6     |        |        |        | F7     | F8     | F9     | F10    | F11    | F12    |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | NUM    |        | ~      | +      | _      |        | P7     | P8     | P9     |        | {      | \      | }      |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | CAP    | !      | @      | #      | $      |  %     | P4     | P5     | P6     | ^      | &      | *      | (      | )      |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        | MOUSE  | MACVIM | '      | "      | P1     | P2     | P3     | [      | ]      |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        |        |        | SHIFT  |        | P0     |        | P.     |        | "      |        |        |        | RESET  |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */

 [_SYM] = LAYOUT_ortho_5x15(
  KC_F1,   KC_F2,    KC_F3,     KC_F4,     KC_F5,      KC_F6,      _______, SLEEP,   _______, KC_F7,   KC_F8,      KC_F9,      KC_F10,     KC_F11,  KC_F12 ,
  NUM,     _______,  S(KC_GRV), S(KC_EQL), S(KC_MINS), _______,    KC_P7,   KC_P8,   KC_P9,   _______, S(KC_LBRC), S(KC_BSLS), S(KC_RBRC), _______, _______,
  CAP,     S(KC_1),  S(KC_2),   S(KC_3),   S(KC_4),    S(KC_5),    KC_P4,   KC_P5,   KC_P6,   S(KC_6), S(KC_7),    S(KC_8),    S(KC_9),    S(KC_0), _______,
  _______, _______,  MOUSE,     MACVIM,    KC_QUOT,    S(KC_QUOT), KC_P1,   KC_P2,   KC_P3,   KC_LBRC, KC_RBRC,    _______,    _______,    _______, _______,
  _______, _______,  _______,   _______,   _______,    _______,    KC_P0,   _______, KC_PDOT, _______, S(KC_QUOT), _______,    _______,    _______, _______
 ),

/* Mac System Shortcuts & Vim Movements
 * .-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------.
 * | Reset VIM Repeat | 1      | 2         | 3                 | 4          | 5         |            | QUIT        | CLOSE       | 6      | 7      | 8                  | 9                 | 0         |        |
 * |------------------+--------+-----------+-------------------+------------+-----------+------------+-------------+-------------+--------+--------+--------------------+-------------------+-----------+--------|
 * |                  |        | ALT+RIGHT | ALT+RIGHT         |            |           |            | SNAP MAX    |             |        | CMD+{  |                    | CMD+}             | CMD+a     | CMD+x  |
 * |------------------+--------+-----------+-------------------+------------+-----------+------------+-------------+-------------+--------+--------+--------------------+-------------------+-----------+--------|
 * | QWERTY           | CMD+Z  | CMD+s     | CUT Rest of Word  |            |           |            | SNAP CENTER |             | LEFT   | DOWN   | UP                 | RIGHT             | CMD+c     | CMD+v  |
 * |------------------+--------+-----------+-------------------+------------+-----------+------------+-------------+-------------+--------+--------+--------------------+-------------------+-----------+--------|
 * |                  | CMD+z  | CUT Char  | CUT Word          | CUT Line   | ALT+LEFT  |            | SNAP UP     |             | CMD+[  | CMD+]  | CUT Begin of line  | CUT Rest of Line  |           |        |
 * |------- ----------+--------+-----------+-------------------+------------+-----------+------------+-------------+-------------+--------+--------+--------------------+-------------------+-----------+--------|
 * |                  |        |           | SHIFT             |            |           | SNAP LEFT  | SNAP DOWN   | SNAP RIGHT  |        | CMD+Z  | CMD+z              | CMD+s             |           |        |
 * '-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------'
 */

 [_MACVIM] = LAYOUT_ortho_5x15(
  VIM_ESC, KC_1,    KC_2,    KC_3,     KC_4,     KC_5,     _______,   QUIT,        CLOSE,     KC_6,     KC_7,     KC_8,     KC_9,       KC_0,       _______,
  _______, _______, VIM_W,   ALT_RGHT, ALT_LEFT, _______,  _______,   SNAP_MAX,    _______,   PREV_TAB, NEXT_TAB, UNDO,     REDO,       SEL_ALL,    CUT,
  QWERTY,  REDO,    SAVE,    VIM_D,    CMD_LEFT, CMD_RGHT, _______,   SNAP_CENTER, _______,   KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,    COPY,       PASTE,
  _______, UNDO,    VIM_X,   VIM_C,    VIM_V,    VIM_B,    _______,   SNAP_UP,     _______,   UNINDENT, INDENT,   VIM_0,    VIM_DOLLAR, _______,    _______,
  _______, _______, _______, _______,  KC_LSFT,  KC_LCTL,  SNAP_LEFT, SNAP_DOWN,   SNAP_RGHT, VIM_C,    ALT_LEFT, ALT_RGHT, _______,    _______,    _______
 ),

/* Mouse Movements
 * .----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------.
 * |         | ACC0   | ACC1      | ACC2     |            |             |                      |              |                    |            |             |             |            |           |        |
 * |---------+--------+-----------+----------+------------+-------------+----------------------+--------------+--------------------+------------+-------------+-------------+------------+-----------+--------|
 * |         | CMD+q  | CMD+w     | CMD+v    | CMD+a      |             |                      | SCRL_UP      |                    | SCRL_LEFT  | SCRL_DOWN   | SCRL_UP     | SCRL_RIGHT | CMD+a     | CMD+x  |
 * |---------+--------+-----------+----------+------------+-------------+----------------------+--------------+--------------------+------------+-------------+-------------+------------+-----------+--------|
 * | QWERTY  | CMD+z  | CMD+s     | CMD+Z    |            |             | SCRL_LEFT            | SCRL_DOWN    | SCRL_RIGHT         | LEFT       | DOWN        | UP          | RIGHT      | CMD+c     | CMD+v  |
 * |---------+--------+-----------+----------+------------+-------------+----------------------+--------------+--------------------+------------+-------------+-------------+------------+-----------+--------|
 * |         |        |           |          |            |             | LEFT_CLICK           | UP           | RIGHT_CLICK        |            |             |             |            |           |        |
 * |------- -+--------+-----------+----------+------------+-------------+----------------------+--------------+--------------------+------------+-------------+-------------+------------+-----------+--------|
 * |         |        |           |          | ACC1       | ACC2        | LEFT                 | DOWN         | RIGHT              | ACC0       | LEFT_CLICK  | RIGHT_CLICK | MID_CLICK  |           |        |
 * '----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------'
 */
 [_MOUSE] = LAYOUT_ortho_5x15(
  _______, KC_MS_ACCEL0, KC_MS_ACCEL1, KC_MS_ACCEL2, _______, _______,      _______,       _______,       _______,        _______,       _______,       _______,     _______,        _______, _______,
  _______, QUIT,         CLOSE,        _______,      _______, _______,      _______,       KC_MS_WH_UP,   _______,        KC_MS_WH_LEFT, KC_MS_WH_DOWN, KC_MS_WH_UP, KC_MS_WH_RIGHT, SEL_ALL, CUT,
  QWERTY,  UNDO,         SAVE,         REDO,         _______, _______,      KC_MS_WH_LEFT, KC_MS_WH_DOWN, KC_MS_WH_RIGHT, KC_MS_LEFT,    KC_MS_DOWN,    KC_MS_UP,    KC_MS_RIGHT,    COPY,    PASTE,
  _______, _______,      _______,      _______,      _______, _______,      KC_MS_BTN1,    KC_MS_UP,      KC_MS_BTN2,     _______,       _______,       _______,     _______,        _______, _______,
  _______, _______,      _______,      _______,      KC_LSFT, KC_MS_ACCEL1, KC_MS_LEFT,    KC_MS_DOWN,    KC_MS_RIGHT,    KC_MS_ACCEL0,  KC_MS_BTN1,    KC_MS_BTN2,  KC_MS_BTN3,     _______, _______
 )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  return process_macvim(keycode, record, biton32(layer_state) == _MACVIM);
}
