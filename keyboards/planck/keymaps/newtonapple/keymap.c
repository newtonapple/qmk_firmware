/* Copyright 2019 David Dai
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
#include "muse.h"
#include "newtonapple.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_ortho_4x12_wrapper(
    ________________ORTHO_GRID_QWERTY_L1________________, ________________ORTHO_GRID_QWERTY_R1________________,
    ________________ORTHO_GRID_QWERTY_L2________________, ________________ORTHO_GRID_QWERTY_R2________________,
    ________________ORTHO_GRID_QWERTY_L3________________, ________________ORTHO_GRID_QWERTY_R3________________,
    ________________ORTHO_GRID_QWERTY_L4________________, ________________ORTHO_GRID_QWERTY_R4________________
  ),

 [_CAP] = LAYOUT_ortho_4x12_wrapper(
    _________________ORTHO_GRID_CAP_L1__________________, _________________ORTHO_GRID_CAP_R1__________________,
    _________________ORTHO_GRID_CAP_L2__________________, _________________ORTHO_GRID_CAP_R2__________________,
    _________________ORTHO_GRID_CAP_L3__________________, _________________ORTHO_GRID_CAP_R3__________________,
    ______________________BLANK_6_______________________, ______________________BLANK_6_______________________
  ),

  [_MACVIM] = LAYOUT_ortho_4x12_wrapper(
    ________________ORTHO_GRID_MACVIM_L1________________, ________________ORTHO_GRID_MACVIM_R1________________,
    ________________ORTHO_GRID_MACVIM_L2________________, ________________ORTHO_GRID_MACVIM_R2________________,
    ________________ORTHO_GRID_MACVIM_L3________________, ________________ORTHO_GRID_MACVIM_R3________________,
    ________________ORTHO_GRID_MACVIM_L4________________, ________________ORTHO_GRID_MACVIM_R4________________
  ),

  [_VIMNUM] = LAYOUT_ortho_4x12_wrapper(
    ________________ORTHO_GRID_VIMNUM_L1________________, ________________ORTHO_GRID_VIMNUM_R1________________,
    ________________ORTHO_GRID_VIMNUM_L2________________, ________________ORTHO_GRID_VIMNUM_R2________________,
    ________________ORTHO_GRID_VIMNUM_L3________________, ________________ORTHO_GRID_VIMNUM_R3________________,
    ________________ORTHO_GRID_VIMNUM_L4________________, ________________ORTHO_GRID_VIMNUM_R4________________
  ),

  [_MOUSE] = LAYOUT_ortho_4x12_wrapper(
    ________________ORTHO_GRID_MOUSE_L1_________________, ________________ORTHO_GRID_MOUSE_R1_________________,
    ________________ORTHO_GRID_MOUSE_L2_________________, ________________ORTHO_GRID_MOUSE_R2_________________,
    ________________ORTHO_GRID_MOUSE_L3_________________, ________________ORTHO_GRID_MOUSE_R3_________________,
    ________________ORTHO_GRID_MOUSE_L4_________________, ________________ORTHO_GRID_MOUSE_R4_________________
  ),

  [_NUM] = LAYOUT_ortho_4x12_wrapper(
    _________________ORTHO_GRID_NUM_L1__________________, _________________ORTHO_GRID_NUM_R1__________________,
    _________________ORTHO_GRID_NUM_L2__________________, _________________ORTHO_GRID_NUM_R2__________________,
    _________________ORTHO_GRID_NUM_L3__________________, _________________ORTHO_GRID_NUM_R3__________________,
    _________________ORTHO_GRID_NUM_L4__________________, _________________ORTHO_GRID_NUM_R4__________________
  ),

  [_SYM] = LAYOUT_ortho_4x12_wrapper(
    NUM,     KC_GRV,  S(KC_GRV), KC_EQL,  KC_MINS,  S(KC_EQL),  S(KC_LBRC), S(KC_RBRC), S(KC_BSLS), KC_BSLS, S(KC_MINS), _______,
    CAP,     S(KC_1), S(KC_2),   S(KC_3), S(KC_4),  S(KC_5),    S(KC_6),    S(KC_7),    S(KC_8),    S(KC_9), S(KC_0),    _______,
    _______, S(KC_5), MOUSE,     MACVIM,  KC_QUOT,  S(KC_QUOT), KC_LBRC,    KC_RBRC,    _______,    _______, _______,    _______,
    _______, _______, _______,   _______, _______,   _______,   KC_BSPC,    S(KC_QUOT), S(KC_MINS), _______, _______,    _______
  ),

  [_ADJUST] = LAYOUT_ortho_4x12_wrapper(
    KC_BRIU, KC_BRID, C(KC_UP), C(KC_DOWN), C(KC_LEFT), C(KC_RGHT), KC_MRWD, KC_MPLY, KC_MFFD, KC_MUTE, KC_VOLD, KC_VOLU,
    _______, MI_ON,   MI_OFF,   MU_MOD,     MUV_IN,     MUV_DE,     _______, _______, _______, _______, _______, RESET,
    _______, AU_ON,   AU_OFF,   CK_RST,     CK_UP,      CK_DOWN,    _______, _______, _______, _______, _______, _______,
    _______, MU_ON,   MU_OFF,   CK_ON,      CK_OFF,     _______,    _______, _______, _______, _______, _______, AUDIO
  ),

  [_AUDIO] = LAYOUT_ortho_4x12_wrapper(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    DEFAULT, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    KC_UP,   KC_LCTL, KC_LALT, KC_LGUI, KC_DOWN, _______, _______, _______, _______, _______, MU_OFF,  MU_ON
  )
};

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
  SPACE_CADET_LAYER(keycode, ADJ_SBSLS, _ADJUST, "|", record->event.pressed);
  SPACE_CADET(keycode, CRTL_SLBRC, KC_LCTRL, "{", record->event.pressed);
  SPACE_CADET(keycode, CRTL_SRBRC, KC_RCTRL, "}", record->event.pressed);
  #endif
  return process_macvim(keycode, record, IS_LAYER_ON(_MACVIM));
}
