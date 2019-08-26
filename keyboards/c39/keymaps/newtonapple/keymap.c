#include QMK_KEYBOARD_H
#include "newtonapple.h"


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_QWERTY] = LAYOUT_wrapper(
    MOUSE_TAB,  _________________QWERTY_L1_________________,                                                   KC_ENTER,          _________________QWERTY_R1_________________, LT(_MOUSE, KC_BSPC),
    MACVIM_ESC, _________________QWERTY_L2_________________,                                                   GUI_T(KC_BSPC),    _________________QWERTY_R2_________________, MACVIM_QUOT,
    KC_LSPO, MT(MOD_LCTL, KC_Z), MT(MOD_LALT, KC_X), MT(MOD_LGUI, KC_C), LT(_SYM, KC_V), MT(MOD_LSFT, KC_SPC), LT(_MACVIM, KC_B), LT(_NUM, KC_N), MT(MOD_RSFT, KC_M), MT(MOD_RGUI, KC_COMM), KC_DOT, LT(_ADJUST, KC_SLSH), KC_RSPC
),

[_MACVIM] = LAYOUT_wrapper(
    ________________ORTHO_GRID_MACVIM_L1________________,     KC_BSPC,  ________________ORTHO_GRID_MACVIM_R1________________,
    ________________ORTHO_GRID_MACVIM_L2________________,     KC_BSPC,  ________________ORTHO_GRID_MACVIM_R2________________,
    TG_VIMNUM, UNDO, VIM_X, VIM_C, VIM_V, LT(_VIMNUM, VIM_B), KC_ENTER, ________________ORTHO_GRID_MACVIM_R3________________
 ),

[_VIMNUM] = LAYOUT_wrapper(
    ________________ORTHO_GRID_VIMNUM_L1________________, _______, ________________ORTHO_GRID_VIMNUM_R1________________,
    ________________ORTHO_GRID_VIMNUM_L2________________, _______, ________________ORTHO_GRID_VIMNUM_R2________________,
    ________________ORTHO_GRID_VIMNUM_L3________________, _______, ________________ORTHO_GRID_VIMNUM_R3________________
 ),

 [_MOUSE] = LAYOUT_wrapper(
    _______, QUIT,    CLOSE,   KC_ACL0, KC_ACL1, REDO,                 KC_PGUP, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, PASTE, CUT,
    DEFAULT, SEL_ALL, KC_ACL2, KC_ACL0, KC_ACL1, KC_PGDN,              KC_PGDN, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_BTN1, KC_BTN2,
    _______, UNDO,    CUT,     COPY,    KC_LGUI, MT(MOD_LSFT, KC_ENT), KC_BSPC, MT(MOD_RGUI, KC_BTN1), MT(MOD_LSFT, KC_BTN2), _______, _______, _______, _______
 ),

[_NUM] = LAYOUT_wrapper(
    _________________ORTHO_GRID_NUM_L1__________________,   _______, _________________ORTHO_GRID_NUM_R1__________________,
    _________________ORTHO_GRID_NUM_L2__________________,   _______, _________________ORTHO_GRID_NUM_R2__________________,
    _______, KC_LBRC, KC_RBRC, KC_LGUI, SYM_SMINS, _______, _______, _________________ORTHO_GRID_NUM_R3__________________
 ),

[_SYM] = LAYOUT_wrapper(
    _________________ORTHO_GRID_SYM_L1__________________, _______, _________________ORTHO_GRID_SYM_R1__________________,
    _________________ORTHO_GRID_SYM_L2__________________, _______, _________________ORTHO_GRID_SYM_R2__________________,
    _________________ORTHO_GRID_SYM_L3__________________, _______, _________________ORTHO_GRID_NUM_R3__________________
 ),

[_ADJUST] = LAYOUT_wrapper(
    ________________ORTHO_GRID_ADJUST_L0________________, SNAP_MAX,    ________________ORTHO_GRID_ADJUST_R0________________,
    KC_F1,   KC_F2,    KC_F3,    KC_F4,   KC_F5,   KC_F6, SNAP_CENTER, KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,  KC_F12,
    RESET, __________________BLANK_5__________________,   SNAP_BACK,   ______________________BLANK_6_______________________
 )
};
