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

enum layers {
  _MEDIA,
  _MOUSE1,
  _MOUSE2,
  _WINDOW,
  _NAV1,
  _NAV2,
  _LEDRGB,
  _LEDBL,
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_MEDIA] = LAYOUT(
        TO(_NAV1),     KC_MUTE, TO(_MOUSE1),  \
        KC_MRWD,       KC_MPLY, KC_MFFD,      \
        G(A(KC_LEFT)), KC_MPLY, G(A(KC_RGHT)) \
    ),
    [_MOUSE1] = LAYOUT(
        TO(_MEDIA), KC_BTN2,     TO(_MOUSE2),  \
        KC_LSFT,    KC_MS_U,     KC_BTN1,      \
        KC_MS_L,    KC_MS_D,     KC_MS_R       \
    ),
    [_MOUSE2] = LAYOUT(
        TO(_MOUSE1), G(KC_W), TO(_MEDIA),     \
        G(KC_A),     G(KC_Q), G(KC_BTN1),     \
        G(KC_V),     G(KC_X), G(KC_C)         \
    ),
    [_NAV1] = LAYOUT(
        TO(_LEDRGB),           MT(MOD_LSFT, KC_HOME), TO(_NAV2),             \
        MT(MOD_LGUI, KC_PGUP), KC_UP,                 MT(MOD_LALT, KC_PGDN), \
        LT(_NAV2, KC_LEFT),    KC_DOWN,               KC_RGHT                \
    ),
    [_NAV2] = LAYOUT(
        TO(_NAV1),     KC_END,     TO(_WINDOW),   \
        SGUI(KC_LBRC), G(KC_UP),   SGUI(KC_RBRC), \
        G(KC_LBRC),    G(KC_DOWN), G(KC_RBRC)     \
    ),
    [_WINDOW] = LAYOUT(
        TO(_NAV2),  LCAG(KC_SLSH), TO(_NAV1),     \
        LCAG(KC_C), LCAG(KC_K),    LCAG(KC_M),    \
        LCAG(KC_H), LCAG(KC_J),    LCAG(KC_L)     \
    ),
    [_LEDRGB] = LAYOUT(
        TO(_MEDIA), RGB_TOG,  TO(_LEDBL),  \
        RGB_HUD,    RGB_RMOD, RGB_HUI,     \
        RGB_SAD,    RGB_MOD,  RGB_SAI      \
    ),
    [_LEDBL] = LAYOUT(
        TO(_MEDIA), BL_TOGG,  TO(_LEDRGB), \
        BL_DEC,     BL_OFF,   BL_INC,      \
        RGB_SPD,    BL_BRTG,  RGB_SPI      \
    ),
};

void encoder_update_user(uint8_t index, bool clockwise) {
    uint8_t layer = biton32(layer_state);
  switch (layer) {
    case _MEDIA:
      if (index == 0) {
        clockwise ? tap_code(KC_VOLU) : tap_code(KC_VOLD);
      } else {
        if (clockwise) { // shift-alt-vol-up/down (Mac's shortcut for fine-grain volume control)
          SEND_STRING(SS_LSFT(SS_LALT(SS_TAP(X__VOLUP))));
        } else {
          SEND_STRING(SS_LSFT(SS_LALT(SS_TAP(X__VOLDOWN))));
        }
      }
      break;
    case _MOUSE1:
    case _MOUSE2:
    case _NAV1:
    case _NAV2:
    case _WINDOW:
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

