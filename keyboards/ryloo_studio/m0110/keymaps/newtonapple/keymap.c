/* Copyright 2020 David Dai
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
  [_QWERTY] = LAYOUT_60_tsangan_hhkb_standard_bottom_wrapper(
    MOUSE_GRV,  ________________NUMBER_LEFT________________, ___________________TSANGAN_QWERTY_R0___________________________________________,
    MOUSE_TAB,  _________________QWERTY_L1_________________, ___________________TSANGAN_QWERTY_R1___________________________________________,
    MACVIM_ESC, _________________QWERTY_L2_________________, ___________________ANSI_QWERTY_R2____________________________,
      ___________________TSANGAN_QWERTY_L3_________________, ___________________TSANGAN_QWERTY_R3_________________________,
                         ___________________ANSI_QWERTY_L4_, ___________________ANSI_QWERTY_R4_
  ),

  [_CAP] = LAYOUT_60_tsangan_hhkb_standard_bottom_wrapper(
    ______________________BLANK_6_______________________, ______________________BLANK_6_______________________, _______, _______, _______,
    _________________ORTHO_GRID_CAP_L1__________________, _________________ORTHO_GRID_CAP_R1__________________, _______, _______,
    _________________ORTHO_GRID_CAP_L2__________________, _________________ORTHO_GRID_CAP_R2__________________, _______,
    _________________ORTHO_GRID_CAP_L3__________________, _________________ORTHO_GRID_CAP_R3__________________, _______,
    _________BLANK_3_________,                            _______,                   _________BLANK_3_________, _______
  ),

  [_MACVIM] = LAYOUT_60_tsangan_hhkb_standard_bottom_wrapper(
    ________________ORTHO_GRID_MACVIM_L0________________, ________________ORTHO_GRID_MACVIM_R0________________, _________BLANK_3_________,
    ________________ORTHO_GRID_MACVIM_L1________________, ________________ORTHO_GRID_MACVIM_R1________________, _______, _______,
    ________________ORTHO_GRID_MACVIM_L2________________, ________________ORTHO_GRID_MACVIM_R2________________, _______,
    ________________ORTHO_GRID_MACVIM_L3________________, ________________ORTHO_GRID_MACVIM_R3________________, _______,
    KC_LSFT, _______, MO_VIMNUM,                          KC_BSPC,                          KC_LSFT, MO_VIMNUM, _______, _______
  ),

  [_VIMNUM] = LAYOUT_60_tsangan_hhkb_standard_bottom_wrapper(
    ________________ORTHO_GRID_VIMNUM_L0________________, ________________ORTHO_GRID_VIMNUM_R0________________, _________BLANK_3_________,
    ________________ORTHO_GRID_VIMNUM_L1________________, ________________ORTHO_GRID_VIMNUM_R1________________, _______, _______,
    ________________ORTHO_GRID_VIMNUM_L2________________, ________________ORTHO_GRID_VIMNUM_R2________________, _______,
    ________________ORTHO_GRID_VIMNUM_L3________________, ________________ORTHO_GRID_VIMNUM_R3________________, _______,
    _________BLANK_3_________,                            KC_BSPC,                   _________BLANK_3_________, _______
  ),

  [_MOUSE] = LAYOUT_60_tsangan_hhkb_standard_bottom_wrapper(
    ________________ORTHO_GRID_MOUSE_L0_________________, ________________ORTHO_GRID_MOUSE_R0_________________, _______, _______, _______,
    ________________ORTHO_GRID_MOUSE_L1_________________, ________________ORTHO_GRID_MOUSE_R1_________________, _______, _______,
    ________________ORTHO_GRID_MOUSE_L2_________________, ________________ORTHO_GRID_MOUSE_R2_________________, _______,
    ________________ORTHO_GRID_MOUSE_L3_________________, ___________________TSANGAN_MOUSE_R3__________________________,
    KC_LSFT, _______, MO_VIMNUM,                          KC_BTN1,                KC_BTN2,  KC_LEFT, KC_DOWN, KC_RGHT
  ),

  [_NUM] = LAYOUT_60_tsangan_hhkb_standard_bottom_wrapper(
    _______, _________________ORTHO_GRID_NUM_L0__________________, _________________ORTHO_GRID_NUM_R0__________________, _______, _______,
    _________________ORTHO_GRID_NUM_L1__________________, _________________ORTHO_GRID_NUM_R1__________________, _______, _______,
    _________________ORTHO_GRID_NUM_L2__________________, _________________ORTHO_GRID_NUM_R2__________________, _______,
    _________________ORTHO_GRID_NUM_L3__________________, _________________ORTHO_GRID_NUM_R3__________________, _______,
    _______, _______, _______,                            _______, KC_UP,  LT(_MACVIM, KC_DOWN), LT(_SYM, KC_LEFT),  KC_RGHT
  ),

  [_SYM] = LAYOUT_60_tsangan_hhkb_standard_bottom_wrapper(
    _________________ORTHO_GRID_SYM_L0__________________, _________________ORTHO_GRID_SYM_R0__________________, _______, _______, _______,
    _________________ORTHO_GRID_SYM_L1__________________, _________________ORTHO_GRID_SYM_R1__________________, _______, _______,
    _________________ORTHO_GRID_SYM_L2__________________, _________________ORTHO_GRID_SYM_R2__________________, _______,
    _________________ORTHO_GRID_SYM_L3__________________, _________________ORTHO_GRID_SYM_R3__________________, _______,
    _________BLANK_3_________,                            _______,                   _________BLANK_3_________, _______
  ),

  [_ADJUST] = LAYOUT_60_tsangan_hhkb_standard_bottom_wrapper(
    _______, ________________ORTHO_GRID_ADJUST_L0________________, ________________ORTHO_GRID_ADJUST_R0________________, _______, _______,
    _______, ________________ORTHO_5x12_ADJUST_L1________________, _________________ADJUST_R1_________________, _______, RESET,
    _______, ________________ORTHO_5x12_ADJUST_L2________________, ________________ORTHO_5x12_ADJUST_R2________________,
    ________________ORTHO_5x12_ADJUST_L3________________, ________________ORTHO_5x12_ADJUST_R3________________, _______,
    _________BLANK_3_________,                            _______,                   _________BLANK_3_________, _______
  )
};

