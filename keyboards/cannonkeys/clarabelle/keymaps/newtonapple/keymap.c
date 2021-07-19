/*
Copyright 2021 David Dai (newtonapple)

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
#include "newtonapple.h"

#define MACVIM_DOWN LT(_MACVIM, KC_DOWN)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_QWERTY] = LAYOUT_split_space_wrapper(
 PREV_TAB, SNAP_MAX,    NEXT_TAB,    KC_MPLY,    ________________ORTHO_GRID_QWERTY_L1________________, _________________QWERTY_R1_________________, KC_DEL, KC_BSPC,
 KC_PGUP,  SNAP_CENTER, KC_HOME,                 ________________ORTHO_GRID_QWERTY_L2________________, ________________ORTHO_GRID_QWERTY_R2________________,
 KC_PGDN,  SNAP_BACK,   KC_END,      KC_UP,      ________________ORTHO_GRID_QWERTY_L3________________, ________________ORTHO_GRID_QWERTY_R3________________,
 KC_VOLU,  KC_VOLD,        KC_LEFT,  KC_DOWN, KC_RGHT, CRTL_SLBRC, ALT_SBSLS, GUI_T_EQL, KC_SPC, SFT_T_QUOT,  NUM_MINS, MACVIM_SQUOT, ADJ_SMINS, SYM_SRBRC
),

[_CAP] = LAYOUT_split_space_wrapper(
 KC_P9, KC_P8, KC_P7,      KC_PAST,      _________________ORTHO_GRID_CAP_L1__________________, _________________ORTHO_GRID_CAP_R1__________________, _______,
 KC_P6, KC_P5, KC_P4,                    _________________ORTHO_GRID_CAP_L2__________________, _________________ORTHO_GRID_CAP_R2__________________,
 KC_P3, KC_P2, KC_P1,      _______,      _________________ORTHO_GRID_CAP_L3__________________, _________________ORTHO_GRID_CAP_R3__________________,
 KC_P0, KC_PDOT,  _________BLANK_3_________,  _________BLANK_3_________, _________BLANK_3_________, _________BLANK_3_________
 ),

[_MACVIM] = LAYOUT_split_space_wrapper(
 KC_MRWD,   SNAP_UP,   KC_MFFD,      _______,      ________________ORTHO_GRID_MACVIM_L1________________, ________________ORTHO_GRID_MACVIM_R1________________, _______,
 SNAP_LEFT, SNAP_DOWN, SNAP_RGHT,                  ________________ORTHO_GRID_MACVIM_L2________________, ________________ORTHO_GRID_MACVIM_R2________________,
 ZOOM_OUT,   _______,  ZOOM_IN,      _______,      ________________ORTHO_GRID_MACVIM_L3________________, ________________ORTHO_GRID_MACVIM_R3________________,
 ALT_LEFT,  ALT_RGHT,       _________BLANK_3_________,  _________BLANK_3_________, MO_VIMNUM, RSFT(KC_BSPC), MO_VIMNUM, _________BLANK_3_________
),

[_VIMNUM] = LAYOUT_split_space_wrapper(
 _________BLANK_3_________, _______, ________________ORTHO_GRID_VIMNUM_L1________________, ________________ORTHO_GRID_VIMNUM_R1________________, _______,
 _________BLANK_3_________,          ________________ORTHO_GRID_VIMNUM_L2________________, ________________ORTHO_GRID_VIMNUM_R2________________,
 _________BLANK_3_________, _______, ________________ORTHO_GRID_VIMNUM_L3________________, ________________ORTHO_GRID_VIMNUM_R3________________,
 _______, _______, _________BLANK_3_________, _________BLANK_3_________, _________BLANK_3_________, _________BLANK_3_________
),

[_MOUSE] = LAYOUT_split_space_wrapper(
 _________BLANK_3_________, _______, ________________ORTHO_GRID_MOUSE_L1_________________, ________________ORTHO_GRID_MOUSE_R1_________________, _______,
 _________BLANK_3_________,          ________________ORTHO_GRID_MOUSE_L2_________________, ________________ORTHO_GRID_MOUSE_R2_________________,
 _________BLANK_3_________, _______, ________________ORTHO_GRID_MOUSE_L3_________________, ________________ORTHO_GRID_MOUSE_R3_________________,
 _______, _______, _________BLANK_3_________, _________BLANK_3_________, KC_LSFT,          KC_BTN1, KC_BTN2, KC_LEFT, KC_DOWN, KC_RGHT
),

[_NUM] = LAYOUT_split_space_wrapper(
 KC_P9, KC_P8, KC_P7,      KC_ENT,       _________________ORTHO_GRID_NUM_L1__________________, _________________ORTHO_GRID_NUM_R1__________________, _______,
 KC_P6, KC_P5, KC_P4,                    _________________ORTHO_GRID_NUM_L2__________________, _________________ORTHO_GRID_NUM_R2__________________,
 KC_P3, KC_P2, KC_P1,      KC_PPLS,      _________________ORTHO_GRID_NUM_L3__________________, _________________ORTHO_GRID_NUM_R3__________________,
 KC_P0, KC_PDOT,  KC_PSLS, KC_PAST, KC_PMNS,  _________BLANK_3_________, _______, _______, LT(_SYM, KC_UP),  LT(_MACVIM, KC_DOWN), KC_LEFT, KC_RGHT
),

[_SYM] = LAYOUT_split_space_wrapper(
 _________BLANK_3_________, _______, _________________ORTHO_GRID_SYM_L1__________________, _________________ORTHO_GRID_SYM_R1__________________, _______,
 _________BLANK_3_________,          _________________ORTHO_GRID_SYM_L2__________________, _________________ORTHO_GRID_SYM_R2__________________,
 _________BLANK_3_________, _______, _________________ORTHO_GRID_SYM_L3__________________, _________________ORTHO_GRID_SYM_R3__________________,
 _______, _______, _________BLANK_3_________, _________BLANK_3_________, _______, _______, LT(_SYM, KC_UP),  LT(_MACVIM, KC_DOWN), KC_LEFT, KC_RGHT
),

[_ADJUST] = LAYOUT_split_space_wrapper(
 KC_F9,  KC_F8,  KC_F7,      RESET,        ________________ORTHO_GRID_ADJUST_L0________________, ________________ORTHO_GRID_ADJUST_R0________________, RESET,
 KC_F6,  KC_F5,  KC_F4,                    ________________ORTHO_4x12_ADJUST_L1________________, ________________ORTHO_4x12_ADJUST_R1________________,
 KC_F3,  KC_F2,  KC_F1,      _______,      ________________ORTHO_4x12_ADJUST_L2________________, ________________ORTHO_4x12_ADJUST_R2________________,
 KC_F12, KC_F11,    _________BLANK_3_________, _________BLANK_3_________, _________BLANK_3_________, _________BLANK_3_________
)
};


// // RGB Indicator Customization: (100% stolen from Jetpacktuxedo)
// void keyboard_post_init_user(void) {
//   #ifdef RGBLIGHT_ENABLE
//     rgblight_set_effect_range(0, 1);
//     rgblight_setrgb(100,100,100);
//     rgblight_set();
//   #endif // RGBLIGHT_ENABLE
// }

// void update_led(void) {

//   rgblight_set_effect_range(0, 1);
//   // put all the led in the wanted layer color
//   switch (biton32(layer_state)) {
//     case 0:
//       rgblight_setrgb(255,0,255);
//       break;
//     case 1:
//       rgblight_setrgb(255,0,0);
//       break;
//     case 2:
//       rgblight_setrgb(0,0,255);
//       break;
//     default:
//       rgblight_setrgb(100,100,100);
//       break;
//   }

//   // Override one led if on capslock
//   if (host_keyboard_leds() & (1<<USB_LED_CAPS_LOCK)) {
//     rgblight_setrgb(0,255,0);
//      switch (biton32(layer_state)) {
//       case 0:
//         rgblight_setrgb(0,255,0);
//         break;
//       case 1:
//         rgblight_setrgb(100,100,0);
//         break;
//       case 2:
//         rgblight_setrgb(0,100,100);
//         break;
//       default:
//         rgblight_setrgb(100,100,100);
//         break;
//     }
//   }

//   rgblight_set();
// }

// void led_set_user(uint8_t usb_led) {
//   // must be trigger to
//   // - activate capslock color
//   // - go back to the proper layer color if needed when quitting capslock
//   update_led();
// }

// // RGB Indicator Customization: (cont.)
// //layer_state_t layer_state_set_user(layer_state_t state){
// uint32_t layer_state_set_user(uint32_t state) {
//     #ifdef RGBLIGHT_ENABLE
//       update_led();
//     #endif //RGBLIGHT_ENABLE
//   return state;
// }
