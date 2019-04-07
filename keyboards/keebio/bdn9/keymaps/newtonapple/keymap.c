/* Copyright 2019 David Dai <newtonapple>
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

enum layers {
  _MEDIA,
  _NAV1,
  _NAV2,
  // _MOUSE,
  _LEDRGB,
  _LEDBL,
  // _ADJUST,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_MEDIA] = LAYOUT(
        TO(_NAV1),     KC_MUTE, KC_MPLY,      \
        KC_MRWD,       KC_MPLY, KC_MFFD,      \
        G(A(KC_LEFT)), KC_MPLY, G(A(KC_RGHT)) \
    ),
    [_NAV1] = LAYOUT(
        TO(_LEDRGB),           MT(MOD_LSFT, KC_HOME), TO(_NAV2),             \
        MT(MOD_LGUI, KC_PGUP), KC_UP,                 MT(MOD_LALT, KC_PGDN), \
        LT(_NAV2, KC_LEFT),    KC_DOWN,               KC_RGHT                \
    ),
    [_NAV2] = LAYOUT(
        TO(_LEDRGB),   KC_END,     TO(_NAV1),     \
        SGUI(KC_LBRC), G(KC_UP),   SGUI(KC_RBRC), \
        G(KC_LBRC),    G(KC_DOWN), G(KC_RBRC)     \
    ),
    [_LEDRGB] = LAYOUT(
        TO(_MEDIA), RGB_TOG,  TO(_LEDBL), \
        RGB_HUD,    RGB_RMOD, RGB_HUI,    \
        RGB_SAD,    RGB_MOD,  RGB_SAI    \
    ),
    [_LEDBL] = LAYOUT(
        TO(_MEDIA), BL_TOGG,  TO(_LEDRGB), \
        BL_DEC,     BL_OFF,   BL_INC,     \
        RGB_SPD,    BL_BRTG,  RGB_SPI     \
    ),
};

void encoder_update_user(uint8_t index, bool clockwise) {
    uint8_t layer = biton32(layer_state);
  switch (layer) {
    case _MEDIA:
      if (index == 0) {
        clockwise ? tap_code(KC_VOLU) : tap_code(KC_VOLD);
      } else {
        if (clockwise) {
          SEND_STRING(SS_LSFT(SS_LALT(SS_TAP(X__VOLUP))));
          // register_code(KC_LALT);
          // register_code(KC_LSFT);
          // tap_code(KC_VOLU);
          // unregister_code(KC_LALT);
          // unregister_code(KC_LSFT);
        } else {
          SEND_STRING(SS_LSFT(SS_LALT(SS_TAP(X__VOLDOWN))));
          // register_code(KC_LALT);
          // register_code(KC_LSFT);
          // tap_code(KC_VOLD);
          // unregister_code(KC_LALT);
          // unregister_code(KC_LSFT);
        }
      }
      break;
    case _NAV1:
    case _NAV2:
      if (index == 0) {
        clockwise ? tap_code(KC_MS_WH_RIGHT) : tap_code(KC_MS_WH_LEFT);
      } else {
        clockwise ? tap_code(KC_MS_WH_DOWN) : tap_code(KC_MS_WH_UP);
      }
      break;
    case _LEDRGB:
      if (index == 0) {
        clockwise ? rgblight_increase_sat_noeeprom() : rgblight_decrease_sat_noeeprom();
      } else {
        clockwise ? rgblight_increase_val_noeeprom() : rgblight_decrease_val_noeeprom();
      }
      break;
    case _LEDBL:
      if (index == 0) {
        clockwise ? backlight_increase() : backlight_decrease();
      } else {
        clockwise ? rgblight_increase_hue_noeeprom() : rgblight_decrease_hue_noeeprom();
      }
      break;
  }
}
