#include QMK_KEYBOARD_H
#include "newtonapple.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // clang-format off
[_QWERTY] = LAYOUT_wrapper(
    ________________ORTHO_GRID_QWERTY_L1________________, ________________ORTHO_GRID_QWERTY_R1________________,
    ________________ORTHO_GRID_QWERTY_L2________________, ________________ORTHO_GRID_QWERTY_R2________________,
    ________________ORTHO_GRID_QWERTY_L3________________, _________________QWERTY_R3_________________,
                CRTL_SLBRC, ALT_SBSLS, GUI_T_EQL, KC_SPC, SFT_T_QUOT, NUM_MINS, ADJ_SMINS
),

[_CAP] = LAYOUT_wrapper(
    _________________ORTHO_GRID_CAP_L1__________________, _________________ORTHO_GRID_CAP_R1__________________,
    _________________ORTHO_GRID_CAP_L2__________________, _________________ORTHO_GRID_CAP_R2__________________,
    _________________ORTHO_GRID_CAP_L3__________________, __________________CAP_R3___________________,
                      _______, _______, _______, _______, _______, _______, _______
 ),

[_MACVIM] = LAYOUT_wrapper(
    ________________ORTHO_GRID_MACVIM_L1________________, ________________ORTHO_GRID_MACVIM_R1________________,
    ________________ORTHO_GRID_MACVIM_L2________________, ________________ORTHO_GRID_MACVIM_R2________________,
    ________________ORTHO_GRID_MACVIM_L3________________, _________________MACVIM_R3_________________,
                    _______, _______, _______, MO_VIMNUM, RSFT(KC_BSPC), MO_VIMNUM, _______
),

[_VIMNUM] = LAYOUT_wrapper(
    ________________ORTHO_GRID_VIMNUM_L1________________, ________________ORTHO_GRID_VIMNUM_R1________________,
    ________________ORTHO_GRID_VIMNUM_L2________________, ________________ORTHO_GRID_VIMNUM_R2________________,
    ________________ORTHO_GRID_VIMNUM_L3________________, _________________VIMNUM_L3_________________,
                      _______, _______, _______, _______, _______, _______, _______
),

[_MOUSE] = LAYOUT_wrapper(
    ________________ORTHO_GRID_MOUSE_L1_________________, ________________ORTHO_GRID_MOUSE_R1_________________,
    ________________ORTHO_GRID_MOUSE_L2_________________, ________________ORTHO_GRID_MOUSE_R2_________________,
    ________________ORTHO_GRID_MOUSE_L3_________________, _________________MOUSE_R4__________________,
                      _______, _______, _______, KC_LSFT, KC_BTN1, KC_BTN2, KC_LEFT
),

[_NUM] = LAYOUT_wrapper(
    _________________ORTHO_GRID_NUM_L1__________________, _________________ORTHO_GRID_NUM_R1__________________,
    _________________ORTHO_GRID_NUM_L2__________________, _________________ORTHO_GRID_NUM_R2__________________,
    _________________ORTHO_GRID_NUM_L3__________________, __________________NUM_R4___________________,
                      _______, _______, _______, _______, OSL_SYM, KC_LEFT, KC_RGHT
),

[_SYM] = LAYOUT_wrapper(
    _________________ORTHO_GRID_SYM_L1__________________, _________________ORTHO_GRID_SYM_R1__________________,
    _________________ORTHO_GRID_SYM_L2__________________, _________________ORTHO_GRID_SYM_R2__________________,
    _________________ORTHO_GRID_SYM_L3__________________, __________________SYM_R3___________________,
                      _______, _______, _______, _______, OSL_SYM, KC_LEFT, KC_RGHT
),

[_ADJUST] = LAYOUT_wrapper(
    ________________ORTHO_GRID_ADJUST_L0________________, ________________ORTHO_GRID_ADJUST_R0________________,
    ________________ORTHO_4x12_ADJUST_L1________________, ________________ORTHO_4x12_ADJUST_R1________________,
    ________________ORTHO_4x12_ADJUST_L2________________, _________________ADJUST_R2_________________,
                      _______, _______, _______, _______, VLK_TOG, _______, _______
)
    // clang-format on
};
