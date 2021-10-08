/* Copyright 2019 Newtonapple
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

enum layers {
    _DEFAULT,
    _FN,
    _LED,
};
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_DEFAULT] = LAYOUT_ortho_4x4(
    LT(_FN, KC_MPLY), KC_MUTE,    KC_VOLD, KC_VOLU,
    LT(_FN, KC_ESC),  LCAG(KC_M), KC_HOME, KC_PGUP,
    MO(_LED),         LCAG(KC_C), KC_END,  KC_PGDN,
    KC_UP,            KC_DOWN,    KC_LEFT, KC_RGHT
  ),

  [_FN] = LAYOUT_ortho_4x4(
    _______,    _______,        KC_MRWD,        KC_MFFD,
    _______,    _______,        SGUI(KC_RBRC),  LCAG(KC_K),
    _______,    LCAG(KC_SLSH),  SGUI(KC_LBRC),  LCAG(KC_J),
    RESET,      _______,        LCAG(KC_H),     LCAG(KC_L)
  ),

  [_LED] = LAYOUT_ortho_4x4(
    _______,    RGB_TOG,  RGB_VAD,  RGB_VAI,
    _______,    RGB_SPI,  RGB_SAI,  RGB_HUI,
    _______,    RGB_SPD,  RGB_SAD,  RGB_HUD,
    _______,    _______,  RGB_RMOD, RGB_MOD
  ),
};

bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
  return true;
}

void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

void led_set_user(uint8_t usb_led) {

}
