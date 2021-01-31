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

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_QWERTY] = LAYOUT_split_bs_rshift_rshift_wrapper(
  MOUSE_GRV,  ________________NUMBER_LEFT________________, ___________________TSANGAN_QWERTY_R0___________________________________________,
  MOUSE_TAB,  _________________QWERTY_L1_________________, ___________________TSANGAN_QWERTY_R1___________________________________________,
  MACVIM_ESC, _________________QWERTY_L2_________________, ___________________ANSI_QWERTY_R2____________________________,
  ___________________TSANGAN_QWERTY_L3_________________, MACVIM_SQUOT, ___________________TSANGAN_QWERTY_R3_________________________,
  CRTL_SLBRC, ALT_SBSLS,                GUI_T_EQL, KC_SPC, SFT_T_QUOT, NUM_MINS,                 MACVIM_SMINS,  ADJ_SMINS, SYM_SRBRC
),

[_CAP] = LAYOUT_split_bs_rshift_rshift_wrapper(
  ______________________BLANK_6_______________________, ______________________BLANK_6_______________________, _________BLANK_3_________,
  _________________ORTHO_GRID_CAP_L1__________________, _________________ORTHO_GRID_CAP_R1__________________, _______, _______,
  _________________ORTHO_GRID_CAP_L2__________________, _________________ORTHO_GRID_CAP_R2__________________, _______,
  _________________ORTHO_GRID_CAP_L3__________________, _______, _________________ORTHO_GRID_CAP_R3__________________, _______,
  _________BLANK_3_________,                   _________BLANK_3_________,                            _________BLANK_3_________
),

[_MACVIM] = LAYOUT_split_bs_rshift_rshift_wrapper(
  ________________ORTHO_GRID_MACVIM_L0________________, ________________ORTHO_GRID_MACVIM_R0________________, _________BLANK_3_________,
  ________________ORTHO_GRID_MACVIM_L1________________, ________________ORTHO_GRID_MACVIM_R1________________, _______, _______,
  ________________ORTHO_GRID_MACVIM_L2________________, ________________ORTHO_GRID_MACVIM_R2________________, _______,
  ________________ORTHO_GRID_MACVIM_L3________________, KC_BSPC, ________________ORTHO_GRID_MACVIM_R3________________, _______,
  KC_LSFT, _______,                 _______, MO_VIMNUM, RSFT(KC_BSPC), MO_VIMNUM,                  KC_LSFT, MO_VIMNUM, _______
),

[_VIMNUM] = LAYOUT_split_bs_rshift_rshift_wrapper(
  ________________ORTHO_GRID_VIMNUM_L0________________, ________________ORTHO_GRID_VIMNUM_R0________________, _________BLANK_3_________,
  ________________ORTHO_GRID_VIMNUM_L1________________, ________________ORTHO_GRID_VIMNUM_R1________________, _______, _______,
  ________________ORTHO_GRID_VIMNUM_L2________________, ________________ORTHO_GRID_VIMNUM_R2________________, _______,
  ________________ORTHO_GRID_VIMNUM_L3________________, _______, ________________ORTHO_GRID_VIMNUM_R3________________, _______,
  _________BLANK_3_________,                   _________BLANK_3_________,                            _________BLANK_3_________
),

[_MOUSE] = LAYOUT_split_bs_rshift_rshift_wrapper(
  ________________ORTHO_GRID_MOUSE_L0_________________, ________________ORTHO_GRID_MOUSE_R0_________________, _________BLANK_3_________,
  ________________ORTHO_GRID_MOUSE_L1_________________, ________________ORTHO_GRID_MOUSE_R1_________________, _______, _______,
  ________________ORTHO_GRID_MOUSE_L2_________________, ________________ORTHO_GRID_MOUSE_R2_________________, _______,
  ________________ORTHO_GRID_MOUSE_L3_________________, KC_ENTER, ___________________TSANGAN_MOUSE_R3__________________________,
  _______, _______,                   _______, KC_LSFT, KC_BTN1, KC_BTN2,                             KC_LEFT, KC_DOWN, KC_RGHT
),

[_NUM] = LAYOUT_split_bs_rshift_rshift_wrapper(
  _______, _________________ORTHO_GRID_NUM_L0__________________, _________________ORTHO_GRID_NUM_R0__________________, _______, _______,
  _________________ORTHO_GRID_NUM_L1__________________, _________________ORTHO_GRID_NUM_R1__________________, _______, _______,
  _________________ORTHO_GRID_NUM_L2__________________, _________________ORTHO_GRID_NUM_R2__________________, _______,
  _________________ORTHO_GRID_NUM_L3__________________, _______, _________________ORTHO_GRID_NUM_R3__________________, KC_UP,
  _________BLANK_3_________,                   _______, _______, OSL_SYM,  LT(_SYM, KC_LEFT), LT(_MACVIM, KC_RGHT),  KC_DOWN
),

[_SYM] = LAYOUT_split_bs_rshift_rshift_wrapper(
  _________________ORTHO_GRID_SYM_L0__________________, _________________ORTHO_GRID_SYM_R0__________________, _________BLANK_3_________,
  _________________ORTHO_GRID_SYM_L1__________________, _________________ORTHO_GRID_SYM_R1__________________, _______, _______,
  _________________ORTHO_GRID_SYM_L2__________________, _________________ORTHO_GRID_SYM_R2__________________, _______,
  _________________ORTHO_GRID_SYM_L3__________________, _______, _________________ORTHO_GRID_SYM_R3__________________, _______,
  _________BLANK_3_________,                  _______,  _______, OSL_SYM,  LT(_SYM, KC_LEFT), LT(_MACVIM, KC_RGHT),  KC_DOWN
),

[_ADJUST] = LAYOUT_split_bs_rshift_rshift_wrapper(
  _______, ________________ORTHO_GRID_ADJUST_L0________________, ________________ORTHO_GRID_ADJUST_R0________________, _______, _______,
  _______, ________________ORTHO_5x12_ADJUST_L1________________, _________________ADJUST_R1_________________, _______, RESET,
  _______, ________________ORTHO_5x12_ADJUST_L2________________, ________________ORTHO_5x12_ADJUST_R2________________,
  ________________ORTHO_5x12_ADJUST_L3________________, _______, ________________ORTHO_5x12_ADJUST_R3________________, _______,
  _________BLANK_3_________,                   _________BLANK_3_________,                            _________BLANK_3_________
)
};

// clang-format on

// void matrix_init_user(void) {
//     rgblight_setrgb_at(0, 0, 0, 0); // [..., 0] = top LED
//     rgblight_setrgb_at(0, 0, 0, 1); // [..., 1] = middle LED
//     rgblight_setrgb_at(0, 0, 0, 2); // [..., 2] = bottom LED
// }

// void set_led(uint8_t state) {
//     state & 1 ? writePinHigh(B1) : writePinLow(B1);
//     (state >> 1) & 1 ? writePinHigh(B2) : writePinLow(B2);
//     (state >> 2) & 1 ? writePinHigh(B3) : writePinLow(B3);
// }

// // function for layer indicator LED
layer_state_t layer_state_set_keymap(layer_state_t layer_state) {
    // switch (biton32(layer_state)) {
    //     case _NUM:
    //         // rgblight_setrgb_at(0, 0, 153, 0);
    //         rgblight_setrgb_at(0, 0, 0, 0);
    //         rgblight_setrgb_at(0, 0, 0, 1);
    //         rgblight_setrgb_at(0, 0, 0, 2);
    //         break;
    //     case _SYM:
    //         break;
    //     case _VIMNUM:
    //         break;
    //     case _MACVIM:
    //         break;
    //     case _CAP:
    //         break;
    //     case _MOUSE:
    //         break;
    //     case _ADJUST:
    //         break;
    //     default:
    //         rgblight_setrgb_at(0, 0, 0, 0);
    //         rgblight_setrgb_at(0, 0, 0, 1);
    //         rgblight_setrgb_at(0, 0, 0, 2);
    // }
    rgblight_setrgb_at(0, 0, 0, 0);
    rgblight_setrgb_at(0, 0, 0, 1);
    rgblight_setrgb_at(0, 0, 0, 2);
    return layer_state;
}

layer_state_t layer_state_set_kb(layer_state_t state) {
    rgblight_setrgb_at(0, 0, 0, 0);
    rgblight_setrgb_at(0, 0, 0, 1);
    rgblight_setrgb_at(0, 0, 0, 2);
    return state;
}
