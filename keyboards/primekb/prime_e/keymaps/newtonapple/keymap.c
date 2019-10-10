/* Copyright 2019 David Dai (newtonapple)
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
    ________________ORTHO_GRID_QWERTY_L1________________,               ________________ORTHO_GRID_QWERTY_R1________________, KC_BSPC,
    ________________ORTHO_GRID_QWERTY_L2________________,               ________________ORTHO_GRID_QWERTY_R2________________,
    ________________ORTHO_GRID_QWERTY_L3________________, MACVIM_SQUOT, ________________ORTHO_GRID_QWERTY_R3________________,
    CRTL_SLBRC, ALT_SBSLS,           GUI_T_EQL,   KC_SPC,               SFT_T_QUOT, NUM_MINS,           ADJ_SMINS, SYM_SRBRC
),

[_CAP] = LAYOUT_wrapper(
    _________________ORTHO_GRID_CAP_L1__________________,          _________________ORTHO_GRID_CAP_R1__________________, _______,
    _________________ORTHO_GRID_CAP_L2__________________,          _________________ORTHO_GRID_CAP_R2__________________,
    _________________ORTHO_GRID_CAP_L3__________________, _______, _________________ORTHO_GRID_CAP_R3__________________,
    _______, _______,                   _______, _______,          _______, _______,                   _______, _______
 ),

[_MACVIM] = LAYOUT_wrapper(
    ________________ORTHO_GRID_MACVIM_L1________________,          ________________ORTHO_GRID_MACVIM_R1________________, _______,
    ________________ORTHO_GRID_MACVIM_L2________________,          ________________ORTHO_GRID_MACVIM_R2________________,
    ________________ORTHO_GRID_MACVIM_L3________________, KC_BSPC, ________________ORTHO_GRID_MACVIM_R3________________,
    _______, _______,                 _______, MO_VIMNUM,          RSFT(KC_BSPC), MO_VIMNUM,           _______, _______
),

[_VIMNUM] = LAYOUT_wrapper(
    ________________ORTHO_GRID_VIMNUM_L1________________,          ________________ORTHO_GRID_VIMNUM_R1________________, _______,
    ________________ORTHO_GRID_VIMNUM_L2________________,          ________________ORTHO_GRID_VIMNUM_R2________________,
    ________________ORTHO_GRID_VIMNUM_L3________________, _______, ________________ORTHO_GRID_VIMNUM_R3________________,
    _______, _______,                   _______, _______,          _______, _______,                   _______, _______
),

[_MOUSE] = LAYOUT_wrapper(
    ________________ORTHO_GRID_MOUSE_L1_________________,           ________________ORTHO_GRID_MOUSE_R1_________________, _______,
    ________________ORTHO_GRID_MOUSE_L2_________________,           ________________ORTHO_GRID_MOUSE_R2_________________,
    ________________ORTHO_GRID_MOUSE_L3_________________, KC_ENTER, ________________ORTHO_GRID_MOUSE_R3_________________,
    _______, _______,                   _______, KC_LSFT,           KC_BTN1, KC_BTN2,                   KC_LEFT, KC_RGHT
),

[_NUM] = LAYOUT_wrapper(
    _________________ORTHO_GRID_NUM_L1__________________,          _________________ORTHO_GRID_NUM_R1__________________, _______,
    _________________ORTHO_GRID_NUM_L2__________________,          _________________ORTHO_GRID_NUM_R2__________________,
    _________________ORTHO_GRID_NUM_L3__________________, _______, _________________ORTHO_GRID_NUM_R3__________________,
    _______, _______,                   _______, _______,          _______, OSL_SYM,                   KC_LEFT, KC_RGHT
),

[_SYM] = LAYOUT_wrapper(
    _________________ORTHO_GRID_SYM_L1__________________,          _________________ORTHO_GRID_SYM_R1__________________, _______,
    _________________ORTHO_GRID_SYM_L2__________________,          _________________ORTHO_GRID_SYM_R2__________________,
    _________________ORTHO_GRID_SYM_L3__________________, _______, _________________ORTHO_GRID_SYM_R3__________________,
    _______, _______,                   _______, _______,          _______, OSL_SYM,                   KC_LEFT, KC_RGHT
),

[_ADJUST] = LAYOUT_wrapper(
    ________________ORTHO_GRID_ADJUST_L0________________,          ________________ORTHO_GRID_ADJUST_R0________________, RESET,
    ________________ORTHO_4x12_ADJUST_L1________________,          ________________ORTHO_4x12_ADJUST_R1________________,
    ________________ORTHO_4x12_ADJUST_L2________________, _______, ________________ORTHO_4x12_ADJUST_R2________________,
    _______, _______,                   _______, _______,          _______, _______,                   _______, _______
)
};

// clang-format on

void matrix_init_user(void) {
    // set CapsLock LED to output and low
    setPinOutput(B1);
    writePinLow(B1);
    // set NumLock LED to output and low
    setPinOutput(B2);
    writePinLow(B2);
    // set ScrollLock LED to output and low
    setPinOutput(B3);
    writePinLow(B3);
}

void set_led(uint8_t state) {
    state & 1 ? writePinHigh(B1) : writePinLow(B1);
    (state >> 1) & 1 ? writePinHigh(B2) : writePinLow(B2);
    (state >> 2) & 1 ? writePinHigh(B3) : writePinLow(B3);
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
