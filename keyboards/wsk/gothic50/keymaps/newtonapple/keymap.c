/* Copyright 2020 David Dai (newtonapple)
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
    ________________ORTHO_GRID_QWERTY_L1________________, _________________QWERTY_R1_________________,  KC_DEL, KC_BSPC,      SNAP_MAX,
    ________________ORTHO_GRID_QWERTY_L2________________, ________________ORTHO_GRID_QWERTY_R2________________,               SNAP_CENTER,
    ________________ORTHO_GRID_QWERTY_L3________________, MACVIM_SQUOT, _________________QWERTY_R3_________________, KC_UP,   SNAP_BACK,
    CRTL_SLBRC, ALT_SBSLS, GUI_T_EQL, MACVIM_SPC, KC_SPC, SFT_T_QUOT, NUM_MINS, ADJ_SRBRC,                  KC_LEFT, KC_DOWN, KC_RGHT
),

[_CAP] = LAYOUT_wrapper(
    _________________ORTHO_GRID_CAP_L1__________________, _________________ORTHO_GRID_CAP_R1__________________, _______, _______,
    _________________ORTHO_GRID_CAP_L2__________________, _________________ORTHO_GRID_CAP_R2__________________,          _______,
    _________________ORTHO_GRID_CAP_L3__________________, _______, _________________ORTHO_GRID_CAP_R3__________________, _______,
    __________________BLANK_5__________________,          _________BLANK_3_________,                   _________BLANK_3_________
 ),

[_MACVIM] = LAYOUT_wrapper(
    ________________ORTHO_GRID_MACVIM_L1________________, ________________ORTHO_GRID_MACVIM_R1________________, _______, KC_HOME,
    ________________ORTHO_GRID_MACVIM_L2________________, ________________ORTHO_GRID_MACVIM_R2________________,          KC_PGUP,
    ________________ORTHO_GRID_MACVIM_L3________________, KC_BSPC, ________________ORTHO_GRID_MACVIM_R3________________, KC_PGDN,
    _________BLANK_3_________, MO_VIMNUM,        _______, RSFT(KC_BSPC), MO_VIMNUM, _______,           _________BLANK_3_________
),

[_VIMNUM] = LAYOUT_wrapper(
    ________________ORTHO_GRID_VIMNUM_L1________________, ________________ORTHO_GRID_VIMNUM_R1________________, _______, _______,
    ________________ORTHO_GRID_VIMNUM_L2________________, ________________ORTHO_GRID_VIMNUM_R2________________,          _______,
    ________________ORTHO_GRID_VIMNUM_L3________________, _______, ________________ORTHO_GRID_VIMNUM_R3________________, _______,
    __________________BLANK_5__________________,          _________BLANK_3_________,                   _________BLANK_3_________
),

[_MOUSE] = LAYOUT_wrapper(
    ________________ORTHO_GRID_MOUSE_L1_________________, ________________ORTHO_GRID_MOUSE_R1_________________, _______,   KC_END,
    ________________ORTHO_GRID_MOUSE_L2_________________, ________________ORTHO_GRID_MOUSE_R2_________________,            KC_PGUP,
    ________________ORTHO_GRID_MOUSE_L3_________________, KC_ENT,  _________________MOUSE_R3__________________, SNAP_UP,   KC_PGDN,
    _________BLANK_3_________, _______,          KC_LSFT, KC_BTN1, KC_BTN2, KC_BTN3,                 SNAP_LEFT, SNAP_DOWN, SNAP_RGHT
),

[_NUM] = LAYOUT_wrapper(
    _________________ORTHO_GRID_NUM_L1__________________, _________________ORTHO_GRID_NUM_R1__________________, _______, KC_MPLY,
    _________________ORTHO_GRID_NUM_L2__________________, _________________ORTHO_GRID_NUM_R2__________________,          KC_MFFD,
    _________________ORTHO_GRID_NUM_L3__________________, _______, _________________ORTHO_GRID_NUM_R3__________________, KC_MRWD,
    __________________BLANK_5__________________,          _______, OSL_SYM, KC_RCTL,                   _________BLANK_3_________
),

[_SYM] = LAYOUT_wrapper(
    _________________ORTHO_GRID_SYM_L1__________________, _________________ORTHO_GRID_SYM_R1__________________, _______, KC_MPLY,
    _________________ORTHO_GRID_SYM_L2__________________, _________________ORTHO_GRID_SYM_R2__________________,          KC_VOLU,
    _________________ORTHO_GRID_SYM_L3__________________, _______, _________________ORTHO_GRID_SYM_R3__________________, KC_VOLD,
    __________________BLANK_5__________________,          _______, OSL_SYM, KC_RCTL,                   _________BLANK_3_________
),

[_ADJUST] = LAYOUT_wrapper(
    ________________ORTHO_GRID_ADJUST_L0________________, ________________ORTHO_GRID_ADJUST_R0________________, RESET,   KC_MPLY,
    ________________ORTHO_4x12_ADJUST_L1________________, ________________ORTHO_4x12_ADJUST_R1________________,          KC_MFFD,
    ________________ORTHO_4x12_ADJUST_L2________________, _______, ________________ORTHO_4x12_ADJUST_R2________________, KC_MRWD,
    __________________BLANK_5__________________,          _________BLANK_3_________,                   _________BLANK_3_________
)
};

// clang-format on

void matrix_init_user(void) {
    // set CapsLock LED to output and low
    setPinOutput(F4);
    writePinLow(F4);
    // set NumLock LED to output and low
    setPinOutput(F5);
    writePinLow(F5);
    // set ScrollLock LED to output and low
    setPinOutput(F6);
    writePinLow(F6);
}

void set_led(uint8_t state) {
    state & 1 ? writePinHigh(F4) : writePinLow(F4);
    (state >> 1) & 1 ? writePinHigh(F5) : writePinLow(F5);
    (state >> 2) & 1 ? writePinHigh(F6) : writePinLow(F6);
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
