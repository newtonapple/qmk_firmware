/* Copyright 2021 David Dai (newtonapple)
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

#define MEDIA_KEY_DELAY 10

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_QWERTY] = LAYOUT_ansi_wrapper(
  LCAG_T_GRV, ________________NUMBER_LEFT________________, ___________________TSANGAN_QWERTY_R0___________________________________________, KC_MPLY,
  MOUSE_TAB,  _________________QWERTY_L1_________________, ___________________TSANGAN_QWERTY_R1___________________________________________, KC_PGUP,
  MACVIM_ESC, _________________QWERTY_L2_________________, ___________________ANSI_QWERTY_R2____________________________,                   ADJ_PGDN,
  KC_LSPO,    _________________QWERTY_L3_________________, ___________________ANSI_QWERTY_R3___________________,                     KC_UP,
                       ___________________ANSI_QWERTY_L4_, MACVIM_SMINS,                                                      KC_LEFT, KC_DOWN, KC_RGHT
),

[_CAP] = LAYOUT_ansi_wrapper(
  ______________________BLANK_6_______________________, ______________________BLANK_6_______________________, _________BLANK_3_________, _______,
  _________________ORTHO_GRID_CAP_L1__________________, _________________ORTHO_GRID_CAP_R1__________________, _______, _______,          _______,
  _________________ORTHO_GRID_CAP_L2__________________, _________________ORTHO_GRID_CAP_R2__________________, _______,                   _______,
  _________________ORTHO_GRID_CAP_L3__________________, _________________ORTHO_GRID_CAP_R3__________________,                   _______,
  _________BLANK_3_________,                            _______,                                     _______,          _________BLANK_3_________
),

[_MACVIM] = LAYOUT_ansi_wrapper(
  ________________ORTHO_GRID_MACVIM_L0________________, ________________ORTHO_GRID_MACVIM_R0________________, _________BLANK_3_________, _______,
  ________________ORTHO_GRID_MACVIM_L1________________, ________________ORTHO_GRID_MACVIM_R1________________, _______, _______,          CMD_UP,
  ________________ORTHO_GRID_MACVIM_L2________________, ________________ORTHO_GRID_MACVIM_R2________________, _______,                   CMD_DOWN,
  ________________ORTHO_GRID_MACVIM_L3________________, ________________ORTHO_GRID_MACVIM_R3________________,                   _______,
  KC_LSFT, _______, MO_VIMNUM,                          KC_BSPC,                                   MO_VIMNUM,          _______, _______, _______
),

[_VIMNUM] = LAYOUT_ansi_wrapper(
  ________________ORTHO_GRID_VIMNUM_L0________________, ________________ORTHO_GRID_VIMNUM_R0________________, _________BLANK_3_________, _______,
  ________________ORTHO_GRID_VIMNUM_L1________________, ________________ORTHO_GRID_VIMNUM_R1________________, _______, _______,          _______,
  ________________ORTHO_GRID_VIMNUM_L2________________, ________________ORTHO_GRID_VIMNUM_R2________________, _______,                   _______,
  ________________ORTHO_GRID_VIMNUM_L3________________, ________________ORTHO_GRID_VIMNUM_R3________________,                   _______,
  _________BLANK_3_________,                            KC_BSPC,                                    _______,           _________BLANK_3_________
),

[_MOUSE] = LAYOUT_ansi_wrapper(
  ________________ORTHO_GRID_MOUSE_L0_________________, ________________ORTHO_GRID_MOUSE_R0_________________, _________BLANK_3_________, SNAP_BACK,
  ________________ORTHO_GRID_MOUSE_L1_________________, ________________ORTHO_GRID_MOUSE_R1_________________, _______, _______,          SNAP_MAX,
  ________________ORTHO_GRID_MOUSE_L2_________________, ________________ORTHO_GRID_MOUSE_R2_________________, _______,                   SNAP_CENTER,
  ________________ORTHO_GRID_MOUSE_L3_________________, ________________ORTHO_GRID_MOUSE_R3_________________,                   SNAP_UP,
  KC_LSFT, _______, _______,                            KC_BTN1,                            KC_BTN2,               SNAP_LEFT, SNAP_DOWN, SNAP_RGHT
),

[_NUM] = LAYOUT_ansi_wrapper(
  _______, _________________ORTHO_GRID_NUM_L0__________________, _________________ORTHO_GRID_NUM_R0__________________, _______, _______, KC_MPLY,
  _________________ORTHO_GRID_NUM_L1__________________, _________________ORTHO_GRID_NUM_R1__________________, _______, _______,          KC_MFFD,
  _________________ORTHO_GRID_NUM_L2__________________, _________________ORTHO_GRID_NUM_R2__________________, _______,                   KC_MRWD,
  _________________ORTHO_GRID_NUM_L3__________________, _________________ORTHO_GRID_NUM_R3__________________,                  _______,
  _________BLANK_3_________,                            _______,                                     _______,          _________BLANK_3_________
),

[_SYM] = LAYOUT_ansi_wrapper(
  _________________ORTHO_GRID_SYM_L0__________________, _________________ORTHO_GRID_SYM_R0__________________, _________BLANK_3_________, _______,
  _________________ORTHO_GRID_SYM_L1__________________, _________________ORTHO_GRID_SYM_R1__________________, _______, _______,          _______,
  _________________ORTHO_GRID_SYM_L2__________________, _________________ORTHO_GRID_SYM_R2__________________, _______,                   _______,
  _________________ORTHO_GRID_SYM_L3__________________, _________________ORTHO_GRID_SYM_R3__________________,                   _______,
  _________BLANK_3_________,                            _______,                                     _______,          _________BLANK_3_________
),

[_ADJUST] = LAYOUT_ansi_wrapper(
  _______, ________________ORTHO_GRID_ADJUST_L0________________, ________________ORTHO_GRID_ADJUST_R0________________, _________BLANK_3_________,
  _______, ________________ORTHO_5x12_ADJUST_L1________________, _________________ADJUST_R1_________________, _______, RESET,            _______,
  _______, ________________ORTHO_5x12_ADJUST_L2________________, ________________ORTHO_5x12_ADJUST_R2________________,                   _______,
  ________________ORTHO_5x12_ADJUST_L3________________, ________________ORTHO_5x12_ADJUST_R3________________,                   _______,
  _________BLANK_3_________,                            _______,                                     _______,          _________BLANK_3_________
)
};

// clang-format on
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (clockwise) {
        uint16_t held_keycode_timer = timer_read();
        register_code16(KC_VOLU);
        while (timer_elapsed(held_keycode_timer) < MEDIA_KEY_DELAY) {
            // nothing
        }
        unregister_code16(KC_VOLU);
    } else {
        uint16_t held_keycode_timer = timer_read();
        register_code16(KC_VOLD);
        while (timer_elapsed(held_keycode_timer) < MEDIA_KEY_DELAY) {
            // nothing
        }
        unregister_code16(KC_VOLD);
    }
    return true;
}
