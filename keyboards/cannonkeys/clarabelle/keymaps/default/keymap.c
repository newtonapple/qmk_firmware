 /*
 Copyright 2020 Garret Gartner

 This program is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 2 of the License, or
 (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H
// #include "tankplanker.h"

// Keymap Customization:
#define GUI   KC_LGUI
#define ALT   KC_LALT
#define L_CURBR LSFT(KC_LBRC)
#define R_CURBR LSFT(KC_RBRC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[0] = LAYOUT_all(
    KC_7, KC_8, KC_9,      KC_GESC,     KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,  KC_T,   KC_Y,  KC_U,   KC_I,  KC_O,    KC_P,    KC_BSLS, KC_BSPC,
    KC_4, KC_5, KC_6,                   KC_CAPS,  KC_A,    KC_S,    KC_D,    KC_F,  KC_G,   KC_H,  KC_J,   KC_K,  KC_L,    KC_SCLN, KC_NO ,  KC_ENT,
    KC_1, KC_2, KC_3,      KC_UP,       KC_LSPO,  KC_NO,   KC_Z,    KC_X,    KC_C,  KC_V,   KC_B,  KC_N,   KC_M,  KC_COMM, KC_DOT,  KC_SLSH, KC_RSPC,
    KC_0, KC_0,    KC_LEFT, KC_DOWN, KC_RGHT,     KC_LCTL, KC_LGUI, KC_LALT, LT(1, KC_SPC), LT(1, KC_SPC), LT(2, KC_SPC),  KC_RALT, KC_RGUI, KC_RCTL, MO(2)
),

[1] = LAYOUT_all(
    KC_7, KC_8, KC_9,       KC_GRAVE,   _______,         _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    KC_4, KC_5, KC_6,                   _______,         KC_MINS, KC_EQL,  KC_QUOT, KC_SCLN, KC_DLR,  KC_H,    KC_J,    KC_K,    KC_L,    _______, KC_NO,   KC_BSPC,
    KC_1, KC_2, KC_3,       KC_UP,      LSFT_T(KC_LCBR), KC_NO,   KC_TILD, KC_AT,   KC_HASH, KC_PIPE, KC_CIRC, KC_EQL,  KC_QUOT, KC_LBRC, KC_RBRC, KC_SLSH, RSFT_T(KC_RCBR),
    KC_0, KC_0,    KC_LEFT, KC_DOWN, KC_RGHT,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

[2] = LAYOUT_all(
    KC_F7, KC_F8, KC_F9,      RESET,   _______,         _______, _______, _______, _______,   _______, _______, _______, _______, _______, _______, _______, _______,
    KC_F4, KC_F5, KC_F6,               KC_TAB,          KC_PLUS, KC_UNDS, KC_BSLS, KC_COLN,   KC_DLR,  KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_NO ,  KC_BSPC,
    KC_F1, KC_F2, KC_F3,      _______, LSFT_T(KC_LCBR), KC_NO,   KC_EXLM, KC_PERC, KC_BSLASH, KC_AMPR, KC_AT,   KC_CIRC, KC_DQUO, KC_LCBR, KC_RCBR, KC_SLSH, RSFT_T(KC_RCBR),
    KC_0, KC_0,      _______, _______, _______,   _______, _______, _______,   _______, _______, _______,   _______, _______, _______, _______
)
};

// RGB Indicator Customization: (100% stolen from Jetpacktuxedo)
void keyboard_post_init_user(void) {
  #ifdef RGBLIGHT_ENABLE
    rgblight_set_effect_range(0, 1);
    rgblight_setrgb(100,100,100);
    rgblight_set();
  #endif // RGBLIGHT_ENABLE
}

void update_led(void) {

  rgblight_set_effect_range(0, 1);
  // put all the led in the wanted layer color
  switch (biton32(layer_state)) {
    case 0:
      rgblight_setrgb(255,0,255);
      break;
    case 1:
      rgblight_setrgb(255,0,0);
      break;
    case 2:
      rgblight_setrgb(0,0,255);
      break;
    default:
      rgblight_setrgb(100,100,100);
      break;
  }

  // Override one led if on capslock
  if (host_keyboard_leds() & (1<<USB_LED_CAPS_LOCK)) {
    rgblight_setrgb(0,255,0);
     switch (biton32(layer_state)) {
      case 0:
        rgblight_setrgb(0,255,0);
        break;
      case 1:
        rgblight_setrgb(100,100,0);
        break;
      case 2:
        rgblight_setrgb(0,100,100);
        break;
      default:
        rgblight_setrgb(100,100,100);
        break;
    }
  }

  rgblight_set();
}

void led_set_user(uint8_t usb_led) {
  // must be trigger to
  // - activate capslock color
  // - go back to the proper layer color if needed when quitting capslock
  update_led();
}

// RGB Indicator Customization: (cont.)
//layer_state_t layer_state_set_user(layer_state_t state){
uint32_t layer_state_set_user(uint32_t state) {
    #ifdef RGBLIGHT_ENABLE
      update_led();
    #endif //RGBLIGHT_ENABLE
  return state;
}
