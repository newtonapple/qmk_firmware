/* Copyright 2020 newtonapple
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
[_QWERTY] = LAYOUT_65_ansi_blocker_wrapper(
    LCAG_T_GRV, ________________NUMBER_LEFT________________, ________________NUMBER_RIGHT_______________, KC_MINS,     KC_EQL,  KC_BSPC,   CMD_UP,
    MOUSE_TAB,  _________________QWERTY_L1_________________, _________________QWERTY_R1_________________, MACVIM_LBRC, KC_RBRC, KC_BSLASH, KC_PGUP,
    MACVIM_ESC, _________________QWERTY_L2_________________, _________________QWERTY_R2_________________, NUM_QUOT,    MACVIM_ENT,         ADJ_PGDN,
    KC_LSPO,    _________________QWERTY_L3_________________, _________________QWERTY_R3_________________,              KC_RSPC, KC_UP,     CMD_DOWN,
    CRTL_SLBRC, ALT_SBSLS, GUI_T_EQL,                        KC_SPC,                  NUM_MINS, NUM_MINS,              KC_LEFT, KC_DOWN,   KC_RGHT
)
,

[_CAP] = LAYOUT_65_ansi_blocker_wrapper(
    ______________________BLANK_6_______________________, ______________________BLANK_6_______________________, _______, _______, _______,
    _________________ORTHO_GRID_CAP_L1__________________, _________________ORTHO_GRID_CAP_R1__________________, _______, _______, _______,
    _________________ORTHO_GRID_CAP_L2__________________, _________________ORTHO_GRID_CAP_R2__________________, _______,          _______,
    _________________ORTHO_GRID_CAP_L3__________________, _________________ORTHO_GRID_CAP_R3__________________,          _______, _______,
    _________BLANK_3_________,                            _______,                            _______, _______, _________BLANK_3_________
),

[_MACVIM] = LAYOUT_65_ansi_blocker_wrapper(
    ________________ORTHO_GRID_MACVIM_L0________________, ________________ORTHO_GRID_MACVIM_R0________________, _______, _______, SNAP_MAX,
    ________________ORTHO_GRID_MACVIM_L1________________, ________________ORTHO_GRID_MACVIM_R1________________, _______, _______, SNAP_LEFT,
    ________________ORTHO_GRID_MACVIM_L2________________, ________________ORTHO_GRID_MACVIM_R2________________, _______,          SNAP_RGHT,
    ________________ORTHO_GRID_MACVIM_L3________________, ________________ORTHO_GRID_MACVIM_R3________________,          _______, SNAP_CENTER,
    KC_LSFT, _______, MO_VIMNUM,                          KC_BSPC,                          KC_LSFT, MO_VIMNUM, _______, _______, _______
),

[_VIMNUM] = LAYOUT_65_ansi_blocker_wrapper(
    ________________ORTHO_GRID_VIMNUM_L0________________, ________________ORTHO_GRID_VIMNUM_R0________________, _______, _______, _______,
    ________________ORTHO_GRID_VIMNUM_L1________________, ________________ORTHO_GRID_VIMNUM_R1________________, _______, _______, _______,
    ________________ORTHO_GRID_VIMNUM_L2________________, ________________ORTHO_GRID_VIMNUM_R2________________, _______,          _______,
    ________________ORTHO_GRID_VIMNUM_L3________________, ________________ORTHO_GRID_VIMNUM_R3________________,          _______, _______,
    _______, _______, _______,                            KC_BSPC,                            _______, _______, _________BLANK_3_________
),

[_MOUSE] = LAYOUT_65_ansi_blocker_wrapper(
    ________________ORTHO_GRID_MOUSE_L0_________________, ________________ORTHO_GRID_MOUSE_R0_________________, _______, _______, SNAP_BACK,
    ________________ORTHO_GRID_MOUSE_L1_________________, ________________ORTHO_GRID_MOUSE_R1_________________, _______, _______, SNAP_UP,
    ________________ORTHO_GRID_MOUSE_L2_________________, ________________ORTHO_GRID_MOUSE_R2_________________, _______,          SNAP_DOWN,
    ________________ORTHO_GRID_MOUSE_L3_________________, ________________ORTHO_GRID_MOUSE_R3_________________,          _______, SNAP_CENTER,
    KC_LSFT, _______, MO_VIMNUM,                          KC_BTN1,                            KC_BTN2, KC_BTN2, _________BLANK_3_________
),

[_NUM] = LAYOUT_65_ansi_blocker_wrapper(
    _______, _________________ORTHO_GRID_NUM_L0__________________, _________________ORTHO_GRID_NUM_R0__________________, _______, KC_MPLY,
    _________________ORTHO_GRID_NUM_L1__________________, _________________ORTHO_GRID_NUM_R1__________________, _______, _______, KC_MFFD,
    _________________ORTHO_GRID_NUM_L2__________________, _________________ORTHO_GRID_NUM_R2__________________, _______,          KC_MRWD,
    _________________ORTHO_GRID_NUM_L3__________________, _________________ORTHO_GRID_NUM_R3__________________,          _______, KC_MUTE,
    _______, _______, _______,                            _______,                            _______, _______, _________BLANK_3_________
),

[_SYM] = LAYOUT_65_ansi_blocker_wrapper(
    _________________ORTHO_GRID_SYM_L0__________________, _________________ORTHO_GRID_SYM_R0__________________, _______, _______, _______,
    _________________ORTHO_GRID_SYM_L1__________________, _________________ORTHO_GRID_SYM_R1__________________, _______, _______, _______,
    _________________ORTHO_GRID_SYM_L2__________________, _________________ORTHO_GRID_SYM_R2__________________, _______,          _______,
    _________________ORTHO_GRID_SYM_L3__________________, _________________ORTHO_GRID_SYM_R3__________________,          _______, _______,
    _______, _______, _______,                            _______,                            _______, _______, _________BLANK_3_________
),

[_ADJUST] = LAYOUT_65_ansi_blocker_wrapper(
    _______, ________________ORTHO_GRID_ADJUST_L0________________, ________________ORTHO_GRID_ADJUST_R0________________, _______, _______,
    _______, ________________ORTHO_5x12_ADJUST_L1________________, _________________ADJUST_R1_________________, _______, RESET,   _______,
    _______, ________________ORTHO_5x12_ADJUST_L2________________, ________________ORTHO_5x12_ADJUST_R2________________,          _______,
    ________________ORTHO_5x12_ADJUST_L3________________, ________________ORTHO_5x12_ADJUST_R3________________,          _______, _______,
    _______, _______, _______,                            _______,                            _______, _______, _______, _______, _______
)
};

