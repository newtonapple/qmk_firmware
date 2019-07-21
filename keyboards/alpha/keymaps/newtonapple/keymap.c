#include QMK_KEYBOARD_H
#include "newtonapple.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_QWERTY] = LAYOUT(
    LT(_MOUSE, KC_Q),   KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, LT(_MOUSE, KC_P),
    LT(_MACVIM, KC_A),  KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, LT(_MACVIM, KC_QUOT),
    MT(MOD_LCTL, KC_Z), MT(MOD_LALT, KC_X), MT(MOD_RGUI, KC_C), LT(_SYM, KC_V), MT(MOD_LSFT, KC_SPC), LT(_NUM,KC_B), MT(MOD_LGUI, KC_N), LT(_ADJUST, KC_M)
),

[_MACVIM] = LAYOUT(
    VIM_0,   VIM_W, VIM_E,  REDO,     VIM_DOL,  VIM_Y,    UNDO,     VIM_I,    VIM_O,   PASTE,
    VIM_DOL, SAVE,  VIM_D,  CMD_LEFT, CMD_RGHT, KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT, VIM_0,
    UNDO,    VIM_X, VIM_C,  VIM_V, LT(_VIMNUM, KC_BSPC), VIM_B, UNINDENT, INDENT
 ),

[_VIMNUM] = LAYOUT(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
    _______, _______, _______, _______,     _______,     _______, _______, _______
 ),

[_MOUSE] = LAYOUT(
    KC_TAB,  KC_MS_U, KC_ACL0, KC_ACL1, KC_PGUP, COPY,    UNDO,    PREV_TAB, NEXT_TAB, PASTE,
    LT(_MACVIM,KC_ESC),  KC_MS_D, KC_MS_L, KC_MS_R, KC_PGDN, KC_MS_L, KC_MS_D, KC_MS_U,  KC_MS_R,  KC_ENTER,
    UNDO,    CUT,  KC_BTN1, KC_BTN2, MT(MOD_LSFT, KC_ENTER), MT(MOD_RSFT, KC_COMM), KC_DOT, MT(MOD_RSFT, KC_SLSH)
 ),

[_NUM] = LAYOUT(
    KC_GRV,   S(KC_GRV), KC_EQL, KC_MINS, S(KC_EQL), KC_LBRC,   KC_RBRC, S(KC_BSLS), KC_BSLS, KC_SCLN,
    KC_1,     KC_2,      KC_3,   KC_4,    KC_5,       KC_6,     KC_7,    KC_8,       KC_9,    KC_0,
    MT(MOD_LSFT, KC_BSPC),  KC_DEL, MT(MOD_RGUI, KC_COMM),  SYM_SMINS, MT(MOD_LSFT, KC_ENT), KC_COMM, KC_DOT, MT(MOD_RSFT, KC_SLSH)
),

[_SYM] = LAYOUT(
    KC_GRV,  S(KC_GRV), KC_EQL,  KC_MINS,  S(KC_EQL), S(KC_LBRC), S(KC_RBRC), S(KC_BSLS), KC_BSLS, S(KC_SCLN),
    S(KC_1), S(KC_2),   S(KC_3), S(KC_4),  S(KC_5),   S(KC_6),    S(KC_7),    S(KC_8),    S(KC_9), S(KC_0),
    MT(MOD_LSFT, KC_BSPC),  KC_DEL, MT(MOD_RGUI, KC_COMM),  SYM_SMINS, MT(MOD_LSFT, KC_ENT), S(KC_COMM), S(KC_DOT), S(KC_SLSH)
),

[_ADJUST] = LAYOUT(
    G(S(KC_QUOT)), SNAP_MAX,  SNAP_CENTER, SNAP_BACK, KC_MRWD, KC_MPLY,  KC_MFFD, KC_MUTE, KC_VOLD, KC_VOLU,
    SNAP_LEFT,     SNAP_UP,   SNAP_DOWN,   SNAP_RGHT, RGB_MOD, RGB_RMOD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD,
    RESET,  _______, RGB_TOG, VLK_TOG, MO(_FN), RGB_HUI, RGB_HUD, _______
),

[_FN] = LAYOUT(
    KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10,
    KC_F11,KC_F12,KC_BRIU, KC_BRID, RGB_TOG, C(KC_UP),  C(KC_DOWN), C(KC_LEFT), C(KC_RGHT), _______,
    _______, _______, _______, _______,     _______,     _______, _______, _______
)
};
