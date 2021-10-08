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
  [_QWERTY] = LAYOUT_ansi_split_space_wrapper(
    SNAP_MAX,    ________________ORTHO_GRID_QWERTY_L1________________, _________________QWERTY_R1_________________, KC_DEL, KC_BSPC,
    SNAP_CENTER, ________________ORTHO_GRID_QWERTY_L2________________, ________________ORTHO_GRID_QWERTY_R2________________,
    SNAP_BACK,   ________________ORTHO_GRID_QWERTY_L3________________, ________________ORTHO_GRID_QWERTY_R3________________,
    KC_MPLY,     CRTL_SLBRC, ALT_SBSLS, GUI_T_EQL,             KC_SPC, SFT_T_QUOT,  NUM_MINS, MACVIM_SQUOT, SYM_SMINS, ADJ_SRBRC
  ),

  [_CAP] = LAYOUT_ansi_split_space_wrapper(
    _______, _________________ORTHO_GRID_CAP_L1__________________, _________________ORTHO_GRID_CAP_R1__________________, _______,
    _______, _________________ORTHO_GRID_CAP_L2__________________, _________________ORTHO_GRID_CAP_R2__________________,
    _______, _________________ORTHO_GRID_CAP_L3__________________, _________________ORTHO_GRID_CAP_R3__________________,
    _______, _________BLANK_3_________,                _________BLANK_3_________,             _________BLANK_3_________
  ),

  [_MACVIM] = LAYOUT_ansi_split_space_wrapper(
    SNAP_UP,   ________________ORTHO_GRID_MACVIM_L1________________, ________________ORTHO_GRID_MACVIM_R1________________, _______,
    SNAP_LEFT, ________________ORTHO_GRID_MACVIM_L2________________, ________________ORTHO_GRID_MACVIM_R2________________,
    SNAP_RGHT, ________________ORTHO_GRID_MACVIM_L3________________, ________________ORTHO_GRID_MACVIM_R3________________,
    SNAP_DOWN, KC_LSFT, _______, MO_VIMNUM,                 _______, KC_BSPC, MO_VIMNUM, _______, _______, _______
  ),

  [_VIMNUM] = LAYOUT_ansi_split_space_wrapper(
    _______, ________________ORTHO_GRID_VIMNUM_L1________________, ________________ORTHO_GRID_VIMNUM_R1________________, _______,
    _______, ________________ORTHO_GRID_VIMNUM_L2________________, ________________ORTHO_GRID_VIMNUM_R2________________,
    _______, ________________ORTHO_GRID_VIMNUM_L3________________, ________________ORTHO_GRID_VIMNUM_R3________________,
    _______, _________BLANK_3_________,                _________BLANK_3_________,             _________BLANK_3_________
  ),

  [_MOUSE] = LAYOUT_ansi_split_space_wrapper(
    _______, ________________ORTHO_GRID_MOUSE_L1_________________, ________________ORTHO_GRID_MOUSE_R1_________________, _______,
    _______, ________________ORTHO_GRID_MOUSE_L2_________________, ________________ORTHO_GRID_MOUSE_R2_________________,
    _______, ________________ORTHO_GRID_MOUSE_L3_________________, ________________ORTHO_GRID_MOUSE_R3_________________,
    _______, KC_LSFT, _______, _______,                   KC_LSFT, KC_BTN1, KC_BTN2, KC_LEFT, KC_DOWN, KC_RGHT
  ),

  [_NUM] = LAYOUT_ansi_split_space_wrapper(
    KC_HOME, _________________ORTHO_GRID_NUM_L1__________________, _________________ORTHO_GRID_NUM_R1__________________, _______,
    KC_PGUP, _________________ORTHO_GRID_NUM_L2__________________, _________________ORTHO_GRID_NUM_R2__________________,
    KC_PGDN, _________________ORTHO_GRID_NUM_L3__________________, _________________ORTHO_GRID_NUM_R3__________________,
    KC_END,  _________BLANK_3_________,                   _______, _______, KC_UP,  LT(_MACVIM, KC_DOWN), LT(_SYM, KC_LEFT),  KC_RGHT
  ),

  [_SYM] = LAYOUT_ansi_split_space_wrapper(
    KC_VOLU, _________________ORTHO_GRID_SYM_L1__________________, _________________ORTHO_GRID_SYM_R1__________________, _______,
    KC_MFFD, _________________ORTHO_GRID_SYM_L2__________________, _________________ORTHO_GRID_SYM_R2__________________,
    KC_MRWD, _________________ORTHO_GRID_SYM_L3__________________, _________________ORTHO_GRID_SYM_R3__________________,
    KC_VOLD, _________BLANK_3_________,                _________BLANK_3_________,             _________BLANK_3_________
  ),

  [_ADJUST] = LAYOUT_ansi_split_space_wrapper(
    KC_VOLU, _______, ________________ORTHO_GRID_ADJUST_L0________________, ________________ORTHO_GRID_ADJUST_R0________________,
    KC_MFFD, ________________ORTHO_4x12_ADJUST_L1________________, ________________ORTHO_4x12_ADJUST_R1________________,
    KC_MRWD, ________________ORTHO_4x12_ADJUST_L2________________, ________________ORTHO_4x12_ADJUST_R2________________,
    KC_VOLD, _________BLANK_3_________,                _________BLANK_3_________,             _________BLANK_3_________
  )
};
