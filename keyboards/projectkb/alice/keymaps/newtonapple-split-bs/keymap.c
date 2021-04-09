/* Copyright 2021 David Dai
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
[_QWERTY] = LAYOUT_wrapper(
SNAP_MAX,      ________________ORTHO_GRID_QWERTY_L0________________,               ___________________TSANGAN_QWERTY_R0___________________________________________,
SNAP_CENTER,   ________________ORTHO_GRID_QWERTY_L1________________,               ___________________TSANGAN_QWERTY_R1___________________________________________,
CRTL_SNAPBACK, ________________ORTHO_GRID_QWERTY_L2________________,               ___________________ANSI_QWERTY_R2____________________________,
               ________________ORTHO_GRID_QWERTY_L3________________, MACVIM_SQUOT, ___________________TSANGAN_QWERTY_R3_________________________,
               CRTL_SLBRC,          GUI_T_EQL, KC_SPC, MACVIM_SMINS,               SFT_T_QUOT, NUM_MINS,                               ALT_SRBRC
),

[_CAP] = LAYOUT_wrapper(
_______, ______________________BLANK_6_______________________,          ______________________BLANK_6_______________________, _________BLANK_3_________,
_______, _________________ORTHO_GRID_CAP_L1__________________,          _________________ORTHO_GRID_CAP_R1__________________, _______, _______,
_______, _________________ORTHO_GRID_CAP_L2__________________,          _________________ORTHO_GRID_CAP_R2__________________, _______,
         _________________ORTHO_GRID_CAP_L3__________________, _______, _________________ORTHO_GRID_CAP_R3__________________, _______,
         _______,                   _________BLANK_3_________,          _________BLANK_3_________
),

[_MACVIM] = LAYOUT_wrapper(
_______, ________________ORTHO_GRID_MACVIM_L0________________,          ________________ORTHO_GRID_MACVIM_R0________________, _________BLANK_3_________,
_______, ________________ORTHO_GRID_MACVIM_L1________________,          ________________ORTHO_GRID_MACVIM_R1________________, _______, _______,
_______, ________________ORTHO_GRID_MACVIM_L2________________,          ________________ORTHO_GRID_MACVIM_R2________________, _______,
         ________________ORTHO_GRID_MACVIM_L3________________, KC_BSPC, ________________ORTHO_GRID_MACVIM_R3________________, _______,
         KC_LSFT,                 _______, _______, MO_VIMNUM,          SFT_T_BSPC, MO_VIMNUM,                                _______
),

[_VIMNUM] = LAYOUT_wrapper(
_______, ________________ORTHO_GRID_VIMNUM_L0________________,          ________________ORTHO_GRID_VIMNUM_R0________________, _________BLANK_3_________,
_______, ________________ORTHO_GRID_VIMNUM_L1________________,          ________________ORTHO_GRID_VIMNUM_R1________________, _______, _______,
_______, ________________ORTHO_GRID_VIMNUM_L2________________,          ________________ORTHO_GRID_VIMNUM_R2________________, _______,
         ________________ORTHO_GRID_VIMNUM_L3________________, _______, ________________ORTHO_GRID_VIMNUM_R3________________, _______,
         _______,                   _________BLANK_3_________,          _________BLANK_3_________
),

[_MOUSE] = LAYOUT_wrapper(
_______, ________________ORTHO_GRID_MOUSE_L0_________________,          ________________ORTHO_GRID_MOUSE_R0_________________, _________BLANK_3_________,
_______, ________________ORTHO_GRID_MOUSE_L1_________________,          ________________ORTHO_GRID_MOUSE_R1_________________, _______, _______,
_______, ________________ORTHO_GRID_MOUSE_L2_________________,          ________________ORTHO_GRID_MOUSE_R2_________________, _______,
         ________________ORTHO_GRID_MOUSE_L3_________________, KC_BTN1, ________________ORTHO_GRID_MOUSE_R3_________________, _______,
         KC_LSFT,        _______,  KC_BTN1, KC_BTN2,           SFT_T_BSPC, KC_BTN1,                                     KC_BTN2
),

[_NUM] = LAYOUT_wrapper(
KC_MPLY, _______, _________________ORTHO_GRID_NUM_L0__________________, _________________ORTHO_GRID_NUM_R0__________________, _______, _______,
KC_MFFD, _________________ORTHO_GRID_NUM_L1__________________,          _________________ORTHO_GRID_NUM_R1__________________, _______, _______,
KC_MRWD, _________________ORTHO_GRID_NUM_L2__________________,          _________________ORTHO_GRID_NUM_R2__________________, _______,
         _________________ORTHO_GRID_NUM_L3__________________, _______, _________________ORTHO_GRID_NUM_R3__________________, _______,
         _______,                   _________BLANK_3_________,          _________BLANK_3_________
),

[_SYM] = LAYOUT_wrapper(
KC_MPLY, _________________ORTHO_GRID_SYM_L0__________________,          _________________ORTHO_GRID_SYM_R0__________________, _________BLANK_3_________,
KC_VOLU, _________________ORTHO_GRID_SYM_L1__________________,          _________________ORTHO_GRID_SYM_R1__________________, _______, _______,
KC_VOLD, _________________ORTHO_GRID_SYM_L2__________________,          _________________ORTHO_GRID_SYM_R2__________________, _______,
         _________________ORTHO_GRID_SYM_L3__________________, _______, _________________ORTHO_GRID_SYM_R3__________________, _______,
         _______,                   _________BLANK_3_________,          _________BLANK_3_________
),

[_ADJUST] = LAYOUT_wrapper(
RGB_TOG,  _______, ________________ORTHO_GRID_ADJUST_L0________________, ________________ORTHO_GRID_ADJUST_R0________________, _______, _______,
RGB_MOD,  _______, ________________ORTHO_5x12_ADJUST_L1________________, _________________ADJUST_R1_________________, _______, RESET,
RGB_RMOD, _______, ________________ORTHO_5x12_ADJUST_L2________________, ________________ORTHO_5x12_ADJUST_R2________________,
          ________________ORTHO_5x12_ADJUST_L3________________, _______, ________________ORTHO_5x12_ADJUST_R3________________, _______,
          _______,                   _________BLANK_3_________,          _________BLANK_3_________
)
};

// clang-format on
bool led_update_user(led_t usb_led) { return false; }

void set_led(uint8_t state) {
    state & 1 ? writePinLow(INDICATOR_PIN_0) : writePinHigh(INDICATOR_PIN_0);
    (state >> 1) & 1 ? writePinLow(INDICATOR_PIN_1) : writePinHigh(INDICATOR_PIN_1);
    (state >> 2) & 1 ? writePinLow(INDICATOR_PIN_2) : writePinHigh(INDICATOR_PIN_2);
}

// function for layer indicator LED
uint32_t layer_state_set_keymap(uint32_t layer_state) {
    switch (biton32(layer_state)) {
        case _NUM:
            set_led(1);
            break;
        case _SYM:
            set_led(2);
            break;
        case _VIMNUM:
            set_led(3);
            break;
        case _MACVIM:
            set_led(4);
            break;
        case _CAP:
            set_led(5);
            break;
        case _MOUSE:
            set_led(6);
            break;
        case _ADJUST:
            set_led(7);
            break;
        default:
            set_led(0);
    }
    return layer_state;
}
