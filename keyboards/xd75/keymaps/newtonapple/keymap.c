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

 [_QWERTY] = LAYOUT_ortho_5x15(
	 MOUSE_GRV,  KC_1,    KC_2,       KC_3,      KC_4,    KC_5,   UNINDENT, SNAP_CENTER, INDENT,   KC_6,       KC_7,         KC_8,     KC_9,      KC_0,       KC_BSPC,
	 MOUSE_TAB,  KC_Q,    KC_W,       KC_E,      KC_R,    KC_T,   PREV_TAB, SNAP_MAX,    NEXT_TAB, KC_Y,       KC_U,         KC_I,     KC_O,      KC_P,       KC_BSPC,
	 MACVIM_ESC, KC_A,    KC_S,       KC_D,      KC_F,    KC_G,   KC_HOME,  SNAP_BACK,   KC_PGUP,  KC_H,       KC_J,         KC_K,     KC_L,      KC_SCLN,    KC_ENT ,
	 KC_LSPO,    KC_Z,    KC_X,       KC_C,      KC_V,    KC_B,   KC_END,   KC_UP,       KC_PGDN,  KC_N,       KC_M,         KC_COMM,  KC_DOT,    KC_SLSH,    KC_RSPC,
	 CRTL_SLBRC, KC_LCTL, ALT_T_LBRC, GUI_T_EQL, SYM_SPC, KC_SPC, KC_LEFT,  KC_DOWN,     KC_RGHT,  MACVIM_SQUOT, SFT_T_QUOT, NUM_MINS, CMD_SMINS, ALT_T_RBRC, CRTL_SRBRC
 ),

 [_CAP] = LAYOUT_ortho_5x15(
	 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
	 _______, S(KC_Q), S(KC_W), S(KC_E), S(KC_R), S(KC_T), _______, _______, _______, S(KC_Y), S(KC_U), S(KC_I), S(KC_O), S(KC_P), _______,
	 QWERTY,  S(KC_A), S(KC_S), S(KC_D), S(KC_F), S(KC_G), _______, _______, _______, S(KC_H), S(KC_J), S(KC_K), S(KC_L), _______, _______,
	 _______, S(KC_Z), S(KC_X), S(KC_C), S(KC_V), S(KC_B), _______, _______, _______, S(KC_N), S(KC_M), _______, _______, _______, _______,
	 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
 ),

/* Mac System Shortcuts & Vim Movements
 * .-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------.
 * | Reset VIM Repeat | 1         | 2          | 3                 | 4          | 5          |            | QUIT        | CLOSE        | 6        | 7      | 8        | 9                | 0      |        |
 * |------------------+-----------+------------+-------------------+------------+------------+------------+-------------+--------------+----------+--------+----------+------------------+--------+--------|
 * |                  | CMD+LEFT  | Next Word  | ALT+RIGHT         | CMD+Z      | CMD+RIGHT  |            | SNAP MAX    | SNAP CENTER  | CMD+c    | CMD+z  |          | Insert New Line  | CMD+p  | CMD+x  |
 * |------------------+-----------+------------+-------------------+------------+------------+------------+-------------+--------------+----------+--------+----------+------------------+--------+--------|
 * | QWERTY           | CMD+a     | CMD+s      | CUT Rest of Word  |            |            |            | SNAP BACk   |              | LEFT     | DOWN   | UP       | RIGHT            | CMD+c  |        |
 * |------------------+-----------+------------+-------------------+------------+------------+------------+-------------+--------------+----------+--------+----------+------------------+--------+--------|
 * | Toggle VIM Num   | CMD+z     | CUT Char   | CUT Word          | SELECT     | ALT+LEFT   |            | SNAP UP     |              | CMD+{    | CMD+}  | CMD+[    | CMD+]            |        |        |
 * |------------------+-----------+------------+-------------------+------------+------------+------------+-------------+--------------+----------+--------+----------+------------------+--------+--------|
 * |                  |           |            | SHIFT             | VIM Num    |            | SNAP LEFT  | SNAP DOWN   | SNAP RIGHT   | VIM Num  | SHIFT  | VIM Num  |                  |        |        |
 * '-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------'
 */

 [_MACVIM] = LAYOUT_ortho_5x15(
	VIM_ESC,   KC_1,    KC_2,    KC_3,     KC_4,     KC_5,      _______,   QUIT,      CLOSE,      KC_6,      KC_7,     KC_8,      KC_9,    KC_0,    _______,
	_______,   VIM_0,   VIM_W,   VIM_E,    REDO,     VIM_DOL,   _______,   SNAP_MAX,  SNAP_CENTER,VIM_Y,     UNDO,     VIM_I,     VIM_O,   PASTE,   CUT,
	QWERTY,    SEL_ALL, SAVE,    VIM_D,    CMD_LEFT, CMD_RGHT,  _______,   SNAP_BACK, _______,    KC_LEFT,   KC_DOWN,  KC_UP,     KC_RGHT, COPY,    _______,
	TG_VIMNUM, UNDO,    VIM_X,   VIM_C,    VIM_V,    VIM_B,     _______,   SNAP_UP,   _______,    PREV_TAB,  NEXT_TAB, UNINDENT,  INDENT,  _______, _______,
	_______,   _______, _______, _______,  KC_LSFT,  MO_VIMNUM, SNAP_LEFT, SNAP_DOWN, SNAP_RGHT,  MO_VIMNUM, KC_LSFT,  MO_VIMNUM, _______, _______, _______
 ),

 [_VIMNUM] = LAYOUT_ortho_5x15(
	_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
	_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
	QWERTY,  KC_1,    KC_2,    KC_3,     KC_4,     KC_5,  _______, _______, _______, KC_6,    KC_7,   KC_8,     KC_9,    KC_0,    _______,
	_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
	_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
 ),

/* Mouse Movements
 * .-------------------------------------------------------------------------------------------------------------------------------------------------------------------------.
 * |         | ACC0   | ACC1   | ACC2   |        |       |             |            |              |            |             |              |             |        |        |
 * |---------+--------+--------+--------+--------+-------+-------------+------------+--------------+------------+-------------+--------------+-------------+--------+--------|
 * |         | CMD+q  | CMD+w  | PG UP  | CMD+r  |       |             | SCRL_UP    |              | CMD+c      | CMD+u       | CMD+{        | CMD+}       | CMD+a  | CMD+x  |
 * |---------+--------+--------+--------+--------+-------+-------------+------------+--------------+------------+-------------+--------------+-------------+--------+--------|
 * | QWERTY  | CMD+a  | CMD+s  | PG DN  | ACC2   |       | SCRL_LEFT   | SCRL_DOWN  | SCRL_RIGHT   | LEFT       | DOWN        | UP           | RIGHT       | CMD+c  | CMD+v  |
 * |---------+--------+--------+--------+--------+-------+-------------+------------+--------------+------------+-------------+--------------+-------------+--------+--------|
 * |         |        |        |        |        |       | LEFT_CLICK  | UP         | RIGHT_CLICK  | SCRL_LEFT  | SCRL_DOWN   | SCRL_UP      | SCRL_RIGHT  |        |        |
 * |------- -+--------+--------+--------+--------+-------+-------------+------------+--------------+------------+-------------+--------------+-------------+--------+--------|
 * |         |        |        |        | ACC1   | ACC2  | LEFT        | DOWN       | RIGHT        | ACC0       | LEFT_CLICK  | RIGHT_CLICK  | MID_CLICK   |        |        |
 * '-------------------------------------------------------------------------------------------------------------------------------------------------------------------------'
 */
 [_MOUSE] = LAYOUT_ortho_5x15(
	_______, KC_MS_ACCEL0, KC_MS_ACCEL1, KC_MS_ACCEL2, _______,      _______,      _______,       _______,       _______,        _______,       _______,       _______,     _______,        _______, _______,
	_______, QUIT,         CLOSE,        KC_PGUP,      REDO,         _______,      _______,       KC_MS_WH_UP,   _______,        COPY,          UNDO,          PREV_TAB,    NEXT_TAB,       PASTE,   CUT,
	QWERTY,  SEL_ALL,      SAVE,         KC_PGDN,      KC_MS_ACCEL2, _______,      KC_MS_WH_LEFT, KC_MS_WH_DOWN, KC_MS_WH_RIGHT, KC_MS_LEFT,    KC_MS_DOWN,    KC_MS_UP,    KC_MS_RIGHT,    COPY,    PASTE,
	_______, _______,      _______,      _______,      _______,      _______,      KC_MS_BTN1,    KC_MS_UP,      KC_MS_BTN2,     KC_MS_WH_LEFT, KC_MS_WH_DOWN, KC_MS_WH_UP, KC_MS_WH_RIGHT, _______, _______,
	_______, _______,      _______,      _______,      KC_LSFT,      KC_MS_ACCEL1, KC_MS_LEFT,    KC_MS_DOWN,    KC_MS_RIGHT,    KC_MS_ACCEL0,  KC_MS_BTN1,    KC_MS_BTN2,  KC_MS_BTN3,     _______, _______
 ),

/* NUMBERS
 * .---------------------------------------------------------------------------------------------------------------------------------------.
 * | F1      | F2     | F3     | F4     | F5     | F6     |        | SLEEP  | LED    | F7     | F8     | F9     | F10    | F11    | F12    |
 * |---------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |         |        | `      | =      | -      | +      | P7     | P8     | P9     |        | [      | \      | ]      | _      |        |
 * |---------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | QWERTY  | 1      | 2      | 3      | 4      | 5      | P4     | P5     | P6     | 6      | 7      | 8      | 9      | 0      |        |
 * |---------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |         |        | MOUSE  | MACVIM | '      | "      | P1     | P2     | P3     | {      | }      |        |        |        |        |
 * |---------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |         |        |        |        | SHIFT  |        | P0     |        | P.     | SYM    |        |        |        |        | RESET  |
 * '---------------------------------------------------------------------------------------------------------------------------------------'
 */

 [_NUM] = LAYOUT_ortho_5x15(
	KC_F1,   KC_F2,   KC_F3,     KC_F4,   KC_F5,     KC_F6,      _______, SLEEP,   TG(_LED), KC_F7,      KC_F8,      KC_F9,      KC_F10,  KC_F11,     KC_F12 ,
	_______, KC_GRV,  S(KC_GRV), KC_EQL,  KC_MINS,   S(KC_EQL),  KC_P7,   KC_P8,   KC_P9,    S(KC_LBRC), S(KC_RBRC), S(KC_BSLS), KC_BSLS, S(KC_MINS), _______,
	QWERTY,  KC_1,    KC_2,      KC_3,    KC_4,      KC_5,       KC_P4,   KC_P5,   KC_P6,    KC_6,       KC_7,       KC_8,       KC_9,    KC_0,       _______,
	_______, _______, MOUSE,     MACVIM,  KC_QUOT,   S(KC_QUOT), KC_P1,   KC_P2,   KC_P3,    KC_LBRC,    KC_RBRC,    _______,    _______, _______,    _______,
	_______, _______, _______,   _______, KC_LSFT,   _______,    KC_P0,   _______, KC_PDOT,  OSL_SYM,    _______,    _______,    _______, _______,    RESET
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

 [_SYM] = LAYOUT_ortho_5x15(
	KC_F1,   KC_F2,    KC_F3,     KC_F4,   KC_F5,      KC_F6,      _______, SLEEP,   TG(_LED), KC_F7,      KC_F8,      KC_F9,      KC_F10,  KC_F11,     KC_F12 ,
	NUM,     KC_GRV,   S(KC_GRV), KC_EQL,  KC_MINS,    S(KC_EQL),  KC_P7,   KC_P8,   KC_P9,    S(KC_LBRC), S(KC_RBRC), S(KC_BSLS), KC_BSLS, S(KC_MINS), _______,
	CAP,     S(KC_1),  S(KC_2),   S(KC_3), S(KC_4),    S(KC_5),    KC_P4,   KC_P5,   KC_P6,    S(KC_6),    S(KC_7),    S(KC_8),    S(KC_9), S(KC_0),    _______,
	_______, _______,  MOUSE,     MACVIM,  KC_QUOT,    S(KC_QUOT), KC_P1,   KC_P2,   KC_P3,    KC_LBRC,    KC_RBRC,    _______,    _______, _______,    _______,
	_______, _______,  _______,   _______, _______,    _______,    KC_P0,   _______, KC_PDOT,  _______,    S(KC_QUOT), S(KC_MINS), _______, _______,    _______
 ),

 [_LED] = LAYOUT_ortho_5x15(
	RGB_TOG, RGB_M_P, RGB_M_B, RGB_M_R, RGB_M_SW, RGB_M_SN, _______,  _______, TG(_LED), RGB_M_K, RGB_M_X, RGB_M_G, RGB_M_T, _______, TG(_LED),
	_______, BL_TOGG, BL_OFF,  BL_ON,   _______,  _______,  RGB_RMOD, _______, RGB_MOD,  _______, _______, _______, _______, _______, _______,
	QWERTY,  BL_BRTG, BL_DEC,  BL_INC,  _______,  _______,  RGB_SAI,  RGB_TOG, RGB_HUI,  _______, _______, _______, _______, _______, _______,
	_______, _______, _______, _______, _______,  _______,  RGB_SAD,  RGB_VAI, RGB_HUD,  _______, _______, _______, _______, _______, _______,
	_______, _______, _______, _______, _______,  _______,  RGB_SPD,  RGB_VAD, RGB_SPI,  _______, _______, _______, _______, _______, _______
 )
};


#ifdef RGBLIGHT_ENABLE
extern rgblight_config_t rgblight_config;
#endif

void rgb_matrix_scan(void) {
  uint8_t layer = biton32(layer_state);
  if (layer == _LED) return;
  if (layer != _QWERTY) {
    rgblight_enable_noeeprom();
    rgblight_mode_noeeprom(1);
  }
  switch (layer) {
  case _QWERTY:
    rgblight_config.raw = eeconfig_read_rgblight();
    if (rgblight_config.enable) {
      rgblight_enable_noeeprom();
      rgblight_mode_noeeprom(rgblight_config.mode);
      rgblight_sethsv_noeeprom(rgblight_config.hue, rgblight_config.sat, rgblight_config.val);
    } else {
      rgblight_disable_noeeprom();
    }
    break;
  case _NUM:
    rgblight_sethsv_noeeprom_azure();
    break;
  case _SYM:
    rgblight_sethsv_noeeprom_yellow();
    break;
  case _MACVIM:
    rgblight_sethsv_noeeprom_green();
    break;
  case _VIMNUM:
    rgblight_sethsv_noeeprom_springgreen();
    break;
  case _MOUSE:
    rgblight_sethsv_noeeprom_teal();
    break;
  case _CAP:
    rgblight_sethsv_noeeprom_orange();
    break;
  }
}

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
  SPACE_CADET(keycode, CRTL_SLBRC, KC_LCTRL, "{", record->event.pressed);
  SPACE_CADET(keycode, CRTL_SRBRC, KC_RCTRL, "}", record->event.pressed);
  SPACE_CADET(keycode, CMD_SMINS, KC_RCMD, "_", record->event.pressed);
  #endif
  return process_macvim(keycode, record, IS_LAYER_ON(_MACVIM));
}

