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
#include "newtonapple.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_ortho_5x12_wrapper(
    ________________ORTHO_GRID_QWERTY_L0________________, ________________ORTHO_GRID_QWERTY_R0________________,
    ________________ORTHO_GRID_QWERTY_L1________________, ________________ORTHO_GRID_QWERTY_R1________________,
    ________________ORTHO_GRID_QWERTY_L2________________, ________________ORTHO_GRID_QWERTY_R2________________,
    ________________ORTHO_GRID_QWERTY_L3________________, ________________ORTHO_GRID_QWERTY_R3________________,
    ________________ORTHO_GRID_QWERTY_L4________________, ________________ORTHO_GRID_QWERTY_R4________________
  ),

  [_CAP] = LAYOUT_ortho_5x12_wrapper(
    ______________________BLANK_6_______________________, ______________________BLANK_6_______________________,
    _________________ORTHO_GRID_CAP_L1__________________, _________________ORTHO_GRID_CAP_R1__________________,
    _________________ORTHO_GRID_CAP_L2__________________, _________________ORTHO_GRID_CAP_R2__________________,
    _________________ORTHO_GRID_CAP_L3__________________, _________________ORTHO_GRID_CAP_R3__________________,
    ______________________BLANK_6_______________________, ______________________BLANK_6_______________________
  ),

  [_MACVIM] = LAYOUT_ortho_5x12_wrapper(
    ________________ORTHO_GRID_MACVIM_L0________________, ________________ORTHO_GRID_MACVIM_R0________________,
    ________________ORTHO_GRID_MACVIM_L1________________, ________________ORTHO_GRID_MACVIM_R1________________,
    ________________ORTHO_GRID_MACVIM_L2________________, ________________ORTHO_GRID_MACVIM_R2________________,
    ________________ORTHO_GRID_MACVIM_L3________________, ________________ORTHO_GRID_MACVIM_R3________________,
    ________________ORTHO_GRID_MACVIM_L4________________, ________________ORTHO_GRID_MACVIM_R4________________
  ),

  [_VIMNUM] = LAYOUT_ortho_5x12_wrapper(
	________________ORTHO_GRID_VIMNUM_L0________________, ________________ORTHO_GRID_VIMNUM_R0________________,
	________________ORTHO_GRID_VIMNUM_L1________________, ________________ORTHO_GRID_VIMNUM_R1________________,
	________________ORTHO_GRID_VIMNUM_L2________________, ________________ORTHO_GRID_VIMNUM_R2________________,
	________________ORTHO_GRID_VIMNUM_L3________________, ________________ORTHO_GRID_VIMNUM_R3________________,
	________________ORTHO_GRID_VIMNUM_L4________________, ________________ORTHO_GRID_VIMNUM_R4________________
  ),

  [_MOUSE] = LAYOUT_ortho_5x12_wrapper(
    ________________ORTHO_GRID_MOUSE_L0_________________, ________________ORTHO_GRID_MOUSE_R0_________________,
    ________________ORTHO_GRID_MOUSE_L1_________________, ________________ORTHO_GRID_MOUSE_R1_________________,
    ________________ORTHO_GRID_MOUSE_L2_________________, ________________ORTHO_GRID_MOUSE_R2_________________,
    ________________ORTHO_GRID_MOUSE_L3_________________, ________________ORTHO_GRID_MOUSE_R3_________________,
    ________________ORTHO_GRID_MOUSE_L4_________________, ________________ORTHO_GRID_MOUSE_R4_________________
  ),

  [_NUM] = LAYOUT_ortho_5x12_wrapper(
    _________________ORTHO_GRID_NUM_L0__________________, _________________ORTHO_GRID_NUM_R0__________________,
    _________________ORTHO_GRID_NUM_L1__________________, _________________ORTHO_GRID_NUM_R1__________________,
    _________________ORTHO_GRID_NUM_L2__________________, _________________ORTHO_GRID_NUM_R2__________________,
    _________________ORTHO_GRID_NUM_L3__________________, _________________ORTHO_GRID_NUM_R3__________________,
    _________________ORTHO_GRID_NUM_L4__________________, _________________ORTHO_GRID_NUM_R4__________________
  ),

  [_SYM] = LAYOUT_ortho_5x12_wrapper(
    _________________ORTHO_GRID_SYM_L0__________________, _________________ORTHO_GRID_SYM_R0__________________,
    _________________ORTHO_GRID_SYM_L1__________________, _________________ORTHO_GRID_SYM_R1__________________,
    _________________ORTHO_GRID_SYM_L2__________________, _________________ORTHO_GRID_SYM_R2__________________,
    _________________ORTHO_GRID_SYM_L3__________________, _________________ORTHO_GRID_SYM_R3__________________,
    _________________ORTHO_GRID_SYM_L4__________________, _________________ORTHO_GRID_SYM_R4__________________
  ),

  [_ADJUST] = LAYOUT_ortho_5x12_wrapper(
    ________________ORTHO_GRID_ADJUST_L0________________, ________________ORTHO_GRID_ADJUST_R0________________,
    ________________ORTHO_5x12_ADJUST_L1________________, ________________ORTHO_5x12_ADJUST_R1________________,
    ________________ORTHO_5x12_ADJUST_L2________________, ________________ORTHO_5x12_ADJUST_R2________________,
    ________________ORTHO_5x12_ADJUST_L3________________, ________________ORTHO_5x12_ADJUST_R3________________,
    ________________ORTHO_5x12_ADJUST_L4________________, ________________ORTHO_5x12_ADJUST_R4________________
  ),

  [_AUDIO] = LAYOUT_ortho_5x12_wrapper(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    DEFAULT, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    KC_UP,   KC_LCTL, KC_LALT, KC_LGUI, KC_DOWN, _______, _______, _______, _______, _______, MU_OFF,  MU_ON
  )
};

