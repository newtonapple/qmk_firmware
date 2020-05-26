#include QMK_KEYBOARD_H
#include "newtonapple.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_QWERTY] = LAYOUT_split_wrapper(
KC_MPLY,     ________________ORTHO_GRID_QWERTY_L1________________, ___________________TSANGAN_QWERTY_R1___________________________________________,
SNAP_MAX,    ________________ORTHO_GRID_QWERTY_L2________________, ___________________ANSI_QWERTY_R2____________________________,
SNAP_CENTER, ________________ORTHO_GRID_QWERTY_L3________________, ___________________TSANGAN_QWERTY_R3_________________________,
SNAP_BACK,   CRTL_SLBRC, ALT_SBSLS, GUI_T_EQL,             KC_SPC, SFT_T_QUOT,       NUM_MINS, MACVIM_SQUOT, ADJ_SRBRC
),

[_CAP] = LAYOUT_split_wrapper(
_______, _________________ORTHO_GRID_CAP_L1__________________, _________________ORTHO_GRID_CAP_R1__________________, _______, _______,
_______, _________________ORTHO_GRID_CAP_L2__________________, _________________ORTHO_GRID_CAP_R2__________________, _______,
_______, _________________ORTHO_GRID_CAP_L3__________________, _________________ORTHO_GRID_CAP_R3__________________, _______,
_______, _________BLANK_3_________,                   _______, _______,             _________BLANK_3_________
),

[_MACVIM] = LAYOUT_split_wrapper(
SNAP_UP,   ________________ORTHO_GRID_MACVIM_L1________________, ________________ORTHO_GRID_MACVIM_R1________________, _______, _______,
SNAP_LEFT, ________________ORTHO_GRID_MACVIM_L2________________, ________________ORTHO_GRID_MACVIM_R2________________, _______,
SNAP_RGHT, ________________ORTHO_GRID_MACVIM_L3________________, ________________ORTHO_GRID_MACVIM_R3________________, KC_DEL,
SNAP_DOWN, _________BLANK_3_________,                 _______, SFT_T_BSPC,              MO_VIMNUM, _______, _______
),

[_VIMNUM] = LAYOUT_split_wrapper(
_______, ________________ORTHO_GRID_VIMNUM_L1________________, ________________ORTHO_GRID_VIMNUM_R1________________, _______, _______,
_______, ________________ORTHO_GRID_VIMNUM_L2________________, ________________ORTHO_GRID_VIMNUM_R2________________, _______,
_______, ________________ORTHO_GRID_VIMNUM_L3________________, ________________ORTHO_GRID_VIMNUM_R3________________, _______,
_______, _________BLANK_3_________,                   _______, _______,             _________BLANK_3_________
),

[_MOUSE] = LAYOUT_split_wrapper(
_______, ________________ORTHO_GRID_MOUSE_L1_________________, ________________ORTHO_GRID_MOUSE_R1_________________, _______, _______,
_______, ________________ORTHO_GRID_MOUSE_L2_________________, ________________ORTHO_GRID_MOUSE_R2_________________, _______,
_______, ________________ORTHO_GRID_MOUSE_L3_________________, ________________ORTHO_GRID_MOUSE_R3_________________, _______,
_______, KC_LSFT, _______, _______,                   KC_LSFT, KC_BTN1, KC_LEFT, KC_DOWN, KC_RGHT
),

[_NUM] = LAYOUT_split_wrapper(
KC_HOME, _________________ORTHO_GRID_NUM_L1__________________, _________________ORTHO_GRID_NUM_R1__________________, _______, _______,
KC_PGUP, _________________ORTHO_GRID_NUM_L2__________________, _________________ORTHO_GRID_NUM_R2__________________, _______,
KC_PGDN, _________________ORTHO_GRID_NUM_L3__________________, _________________ORTHO_GRID_NUM_R3__________________, _______,
KC_END,  _________BLANK_3_________,                   _______, KC_UP,  LT(_MACVIM, KC_DOWN), LT(_SYM, KC_LEFT),  KC_RGHT
),

[_SYM] = LAYOUT_split_wrapper(
CMD_UP,   _________________ORTHO_GRID_SYM_L1__________________, _________________ORTHO_GRID_SYM_R1__________________, _______, _______,
CMD_LEFT, _________________ORTHO_GRID_SYM_L2__________________, _________________ORTHO_GRID_SYM_R2__________________, _______,
CMD_RGHT, _________________ORTHO_GRID_SYM_L3__________________, _________________ORTHO_GRID_SYM_R3__________________, _______,
CMD_DOWN, _________BLANK_3_________,                   _______, _______,             _________BLANK_3_________
),

[_ADJUST] = LAYOUT_split_wrapper(
KC_VOLU, _______, ________________ORTHO_GRID_ADJUST_L0________________, ________________ORTHO_GRID_ADJUST_R0________________, _______,
KC_MFFD, ________________ORTHO_5x12_ADJUST_L1________________, _________________ADJUST_R1_________________, _______, RESET,
KC_MRWD, ________________ORTHO_5x12_ADJUST_L2________________, ________________ORTHO_5x12_ADJUST_R2________________, _______,
KC_VOLD, _________BLANK_3_________,                   _______, _______,             _________BLANK_3_________
)
};

