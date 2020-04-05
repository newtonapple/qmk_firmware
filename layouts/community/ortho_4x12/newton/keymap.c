#include QMK_KEYBOARD_H

enum layers {
  _QWERTY,
  _NUM,
  _SYM,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_QWERTY] = LAYOUT_ortho_4x12(
    KC_TAB,            KC_Q,    KC_W,    KC_E,    KC_R,               KC_T,   KC_Y,     KC_U,       KC_I,              KC_O,    KC_P,    KC_BSPC,
//  v-- LT is sticky
    LT(_NUM, KC_ESC),  KC_A,    KC_S,    KC_D,    KC_F,               KC_G,   KC_H,     KC_J,       KC_K,              KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT,           KC_Z,    KC_X,    KC_C,    KC_V,               KC_B,   KC_N,     KC_M,       KC_COMM,           KC_DOT,  KC_SLSH, KC_ENT ,
 //                                               v-- this LT works                                 v-- this LT is sticky
    KC_LCTL,           KC_BSLS, KC_LBRC, KC_EQL,  LT(_SYM, KC_MINS),  KC_SPC, KC_SPC,   KC_QUOT,    LT(_NUM, KC_MINS), KC_RBRC, RESET,   KC_LCTL
  ),

[_SYM] = LAYOUT_ortho_4x12(
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR,    KC_ASTR,    KC_LPRN, KC_RPRN, KC_BSPC,
//  v-- would like to use KC_DEL when I hold down the LT(_NUM, KC_MINS) key
    KC_DEL,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR,    KC_ASTR,    KC_LPRN, KC_RPRN, KC_BSPC,
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR,    KC_ASTR,    KC_LPRN, KC_RPRN, KC_BSPC,
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_TRNS, KC_PERC, KC_CIRC, KC_AMPR,    KC_BSPC,    KC_LPRN, RESET,   KC_BSPC
),

[_NUM] = LAYOUT_ortho_4x12(
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,       KC_8,    KC_9,    KC_0,    KC_BSPC,
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,       KC_8,    KC_9,    KC_0,    KC_BSPC,
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,       KC_8,    KC_9,    KC_0,    KC_BSPC,
 //                                                                            v-- would like to use backspace here when I hold down ESC
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_TRNS, KC_5,    KC_6,    KC_7,       KC_BSPC,    KC_9,    RESET,   KC_BSPC
),
};
