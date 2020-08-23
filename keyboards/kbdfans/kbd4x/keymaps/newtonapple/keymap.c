/* Copyright 2018 David Dai
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
#include QMK_KEYBOARD_H
#include "newtonapple.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_planck_mit(
    MOUSE_TAB,  KC_Q,    KC_W,       KC_E,      KC_R,      KC_T,       KC_Y, KC_U,       KC_I,     KC_O,       KC_P,     KC_BSPC,
    MACVIM_ESC, KC_A,    KC_S,       KC_D,      KC_F,      KC_G,       KC_H, KC_J,       KC_K,     KC_L,       KC_SCLN,  KC_ENT,
    KC_LSPO,    KC_Z,    KC_X,       KC_C,      KC_V,      KC_B,       KC_N, KC_M,       KC_COMM,  KC_DOT,     KC_SLSH,  KC_RSPC,
    CRTL_SLBRC, KC_LCTL, ALT_T_LBRC, GUI_T_EQL, SYM_SQUOT, MACVIM_SPC,       SFT_T_QUOT, NUM_MINS, GUI_T_RBRC, LED_RBRC, CRTL_SRBRC
  ),

  [_CAP] = LAYOUT_planck_mit(
    _______, S(KC_Q), S(KC_W), S(KC_E), S(KC_R), S(KC_T), S(KC_Y), S(KC_U), S(KC_I), S(KC_O), S(KC_P), _______,
    DEFAULT, S(KC_A), S(KC_S), S(KC_D), S(KC_F), S(KC_G), S(KC_H), S(KC_J), S(KC_K), S(KC_L), _______, _______,
    _______, S(KC_Z), S(KC_X), S(KC_C), S(KC_V), S(KC_B), S(KC_N), S(KC_M), _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______
  ),

  [_MACVIM] = LAYOUT_planck_mit(
    VIM_ESC,   VIM_0,   VIM_W,   VIM_E,   REDO,     VIM_DOL,   VIM_Y,     UNDO,     VIM_I,     VIM_O,   PASTE,   CUT,
    DEFAULT,   SEL_ALL, SAVE,    VIM_D,   CMD_LEFT, CMD_RGHT,  KC_LEFT,   KC_DOWN,  KC_UP,     KC_RGHT, VIM_0,   VIM_DOL,
    TG_VIMNUM, UNDO,    VIM_X,   VIM_C,   VIM_V,    VIM_B,     PREV_TAB,  NEXT_TAB, UNINDENT,  INDENT,  _______, _______,
    _______,   _______, _______, _______, KC_LSFT,  _______,              KC_LSFT,  MO_VIMNUM, _______, _______, _______
  ),

  [_VIMNUM] = LAYOUT_planck_mit(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    DEFAULT, KC_1,    KC_2,    KC_3,     KC_4,     KC_5,  KC_6,    KC_7,   KC_8,     KC_9,    KC_0,    _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______
  ),

  [_MOUSE] = LAYOUT_planck_mit(
    _______, QUIT,    CLOSE,   KC_ACL2, REDO,    KC_PGUP, COPY,    UNDO,    PREV_TAB, NEXT_TAB, PASTE,   CUT,
    DEFAULT, SEL_ALL, KC_ACL2, KC_ACL0, KC_ACL1, KC_PGDN, KC_MS_L, KC_MS_D, KC_MS_U,  KC_MS_R,  COPY,    PASTE,
    _______, _______, _______, _______, KC_LSFT, _______, KC_WH_L, KC_WH_D, KC_WH_U,  KC_WH_R,  KC_UP,   KC_UP,
    _______, _______, _______, _______, KC_LSFT,          KC_ACL0, KC_BTN1, KC_BTN2,  KC_LEFT,  KC_DOWN, KC_RGHT
  ),

  [_NUM] = LAYOUT_planck_mit(
    _______, KC_GRV,  S(KC_GRV), KC_EQL,  KC_MINS, S(KC_EQL),  S(KC_6),  S(KC_8), S(KC_BSLS), KC_BSLS, S(KC_MINS), _______,
    DEFAULT, KC_1,    KC_2,      KC_3,    KC_4,    KC_5,       KC_6,     KC_7,    KC_8,       KC_9,    KC_0,       _______,
    _______, S(KC_5), MOUSE,     MACVIM,  KC_QUOT, S(KC_QUOT), KC_LBRC,  KC_RBRC, _______,    _______, _______,    _______,
    _______, _______, _______,   _______, KC_LSFT,              _______, OSL_SYM, KC_UP,      KC_DOWN, KC_LEFT,    KC_RGHT
  ),

  [_SYM] = LAYOUT_planck_mit(
    NUM,     KC_GRV,  S(KC_GRV), KC_EQL,  KC_MINS,  S(KC_EQL),  S(KC_LBRC), S(KC_RBRC), S(KC_BSLS), KC_BSLS, S(KC_MINS), _______,
    CAP,     S(KC_1), S(KC_2),   S(KC_3), S(KC_4),  S(KC_5),    S(KC_6),    S(KC_7),    S(KC_8),    S(KC_9), S(KC_0),    _______,
    _______, S(KC_5), MOUSE,     MACVIM,  KC_QUOT,  S(KC_QUOT), KC_LBRC,    KC_RBRC,    _______,    _______, _______,    _______,
    _______, _______, _______,   _______, _______,              _______,    S(KC_QUOT), S(KC_MINS), _______, _______,    _______
  ),

  [_LED] = LAYOUT_planck_mit(
    KC_F1,   KC_F2,   KC_F3,    KC_F4,   KC_F5,    KC_F6,    KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
    RGB_TOG, _______, RGB_RMOD, RGB_HUI, RGB_HUD,  RGB_MOD,  RGB_SPD, RGB_VAD, RGB_VAI, RGB_SPD, _______, RESET,
    RGB_SAI, RGB_M_P, RGB_M_B,  RGB_M_R, RGB_M_SW, RGB_M_SN, RGB_M_K, RGB_M_X, RGB_M_G, RGB_M_T, _______, _______,
    RGB_SAD, _______, _______,  _______, _______,  _______,           _______, _______, _______, _______, _______
  )
};

void matrix_scan_user(void) {
  #ifdef RGBLIGHT_ENABLE
  rgb_matrix_scan();
  #endif
}

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
  SPACE_CADET_LAYER(keycode, SYM_SQUOT, _SYM, "\"", record->event.pressed);
  SPACE_CADET(keycode, CRTL_SLBRC, KC_LCTRL, "{", record->event.pressed);
  SPACE_CADET(keycode, CRTL_SRBRC, KC_RCTRL, "}", record->event.pressed);
  SPACE_CADET(keycode, CMD_SMINS, KC_RCMD, "_", record->event.pressed);
  #endif
  return process_macvim(keycode, record, IS_LAYER_ON(_MACVIM));
}


