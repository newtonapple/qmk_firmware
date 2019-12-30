/*
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
[_QWERTY] = LAYOUT_wrapper(
________________ORTHO_GRID_QWERTY_L0________________, SNAP_MAX,            SNAP_CENTER,  ________________ORTHO_GRID_QWERTY_R0________________,
________________ORTHO_GRID_QWERTY_L1________________, PREV_TAB,            NEXT_TAB,     ________________ORTHO_GRID_QWERTY_R1________________,
________________ORTHO_GRID_QWERTY_L2________________, KC_HOME,             KC_BSPC,      ________________ORTHO_GRID_QWERTY_R2________________,
________________ORTHO_GRID_QWERTY_L3________________, LT(_MACVIM, KC_END), MACVIM_SQUOT, ________________ORTHO_GRID_QWERTY_R3________________,
CRTL_SLBRC,  CRTL_SLBRC, ALT_T_LBRC, GUI_T_EQL, SYM_SMINS, KC_SPC,         SFT_T_QUOT,   NUM_MINS , RGUI_SQUOT, ADJ_SBSLS, MACVIM_BSLS, CRTL_SRBRC
),


[_CAP] = LAYOUT_wrapper(
______________________BLANK_6_______________________, _______, _______, ______________________BLANK_6_______________________,
_________________ORTHO_GRID_CAP_L1__________________, _______, _______, _________________ORTHO_GRID_CAP_R1__________________,
_________________ORTHO_GRID_CAP_L2__________________, _______, _______, _________________ORTHO_GRID_CAP_R2__________________,
_________________ORTHO_GRID_CAP_L3__________________, _______, _______, _________________ORTHO_GRID_CAP_R3__________________,
                 _______, __________________BLANK_5__________________, __________________BLANK_5__________________, _______
),

[_MACVIM] = LAYOUT_wrapper(
________________ORTHO_GRID_MACVIM_L0________________, _______,   SNAP_BACK, ________________ORTHO_GRID_MACVIM_R0________________,
________________ORTHO_GRID_MACVIM_L1________________, SNAP_LEFT, SNAP_RGHT, ________________ORTHO_GRID_MACVIM_R1________________,
________________ORTHO_GRID_MACVIM_L2________________, SNAP_UP,   KC_ENTER,  ________________ORTHO_GRID_MACVIM_R2________________,
________________ORTHO_GRID_MACVIM_L3________________, SNAP_DOWN, KC_BSPC,   ________________ORTHO_GRID_MACVIM_R3________________,
      _______, _______, _______, _______, KC_LSFT,    MO_VIMNUM, KC_BSPC,   KC_LSFT, MO_VIMNUM, _______, _______, _______
),

[_VIMNUM] = LAYOUT_wrapper(
________________ORTHO_GRID_VIMNUM_L0________________, _______, _______, ________________ORTHO_GRID_VIMNUM_R0________________,
________________ORTHO_GRID_VIMNUM_L1________________, _______, _______, ________________ORTHO_GRID_VIMNUM_R1________________,
________________ORTHO_GRID_VIMNUM_L2________________, _______, _______, ________________ORTHO_GRID_VIMNUM_R2________________,
________________ORTHO_GRID_VIMNUM_L3________________, _______, _______, ________________ORTHO_GRID_VIMNUM_R3________________,
                 _______, __________________BLANK_5__________________, __________________BLANK_5__________________, _______
),

[_MOUSE] = LAYOUT_wrapper(
________________ORTHO_GRID_MOUSE_L0_________________, KC_MUTE,   KC_MPLY, ________________ORTHO_GRID_MOUSE_R0_________________,
________________ORTHO_GRID_MOUSE_L1_________________, KC_MRWD,   KC_MFFD, ________________ORTHO_GRID_MOUSE_R1_________________,
________________ORTHO_GRID_MOUSE_L2_________________, KC_VOLU,   KC_WH_U, ________________ORTHO_GRID_MOUSE_R2_________________,
________________ORTHO_GRID_MOUSE_L3_________________, KC_VOLD,   KC_WH_D, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, _______, _______,
               _______, _______, _______, _______, KC_LSFT,   KC_BTN2,   KC_BTN1, _______, KC_UP, KC_DOWN, KC_LEFT, KC_RGHT
),

[_NUM] = LAYOUT_wrapper(
_________________ORTHO_GRID_NUM_L0__________________, S(KC_LBRC), S(KC_RBRC), _________________ORTHO_GRID_NUM_R0__________________,
_________________ORTHO_GRID_NUM_L1__________________, S(KC_EQL),  KC_MINS,    _________________ORTHO_GRID_NUM_R1__________________,
_________________ORTHO_GRID_NUM_L2__________________, S(KC_8),    KC_SLSH,    _________________ORTHO_GRID_NUM_R2__________________,
_________________ORTHO_GRID_NUM_L3__________________, KC_BSPC,    KC_ENTER,   _________________ORTHO_GRID_NUM_R3__________________,
           _______, __________________BLANK_5__________________,    _______, _______,    KC_UP, KC_DOWN, KC_LEFT, KC_RGHT
),

[_SYM] = LAYOUT_wrapper(
_________________ORTHO_GRID_SYM_L0__________________, _______, _______,  _________________ORTHO_GRID_SYM_R0__________________,
_________________ORTHO_GRID_SYM_L1__________________, _______, _______,  _________________ORTHO_GRID_SYM_R1__________________,
_________________ORTHO_GRID_SYM_L2__________________, _______, KC_ENTER, _________________ORTHO_GRID_SYM_R2__________________,
_________________ORTHO_GRID_SYM_L3__________________, _______, KC_BSPC,  _________________ORTHO_GRID_SYM_R3__________________,
           _______, _______, _______, _______, _______, _______, KC_BSPC,  S(KC_QUOT), S(KC_MINS), _______, _______, _______
),

[_ADJUST] = LAYOUT_wrapper(
RGB_TOG, RGB_M_P, RGB_M_B, RGB_M_R, RGB_M_SW, RGB_M_SN, RGB_TOG,  _______, RGB_M_K, RGB_M_X, RGB_M_G, RGB_M_T, _______, TG(_ADJUST),
_______, __________________BLANK_5__________________,   RGB_RMOD, RGB_MOD, __________________BLANK_5__________________, RESET,
DEFAULT, __________________BLANK_5__________________,   RGB_SAI,  RGB_SAD, __________________BLANK_5__________________, _______,
_______, _______, _______, _______, VLK_TOG, _______,   RGB_HUI,  RGB_HUD, RGB_SPI, RGB_SPD, _______, _______, _______, _______,
         _______, _______, _______, _______, _______,   RGB_VAI,  RGB_VAD, _______, _______, _______, _______, _______
)
};
