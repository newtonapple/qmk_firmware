#pragma once
#include "wrappers.h"
#include "wrappers_ortho.h"

// 60 ANSI
//      _______, _______, _______, _______, _______, _______, _______, _______,
#define ___________________ANSI_QWERTY_L4_                       CRTL_SLBRC, ALT_SBSLS, GUI_T_EQL, LT(_NUM, KC_SPC)

#define ___________________ANSI_QWERTY_R0_____________________________________    LAYOUT_args4_wrapper(________________NUMBER_RIGHT_______________, KC_MINS,     KC_EQL,  KC_BSPC)
#define ___________________ANSI_QWERTY_R1_____________________________________    LAYOUT_args4_wrapper(_________________QWERTY_R1_________________, MACVIM_LBRC, MOUSE_RBRC, KC_BSLASH)
#define ___________________ANSI_QWERTY_R2____________________________             LAYOUT_args3_wrapper(_________________QWERTY_R2_________________, NUM_QUOT,    MACVIM_ENT)
#define ___________________ANSI_QWERTY_R3___________________                      LAYOUT_args2_wrapper(_________________QWERTY_R3_________________, KC_RSPC)
#define ___________________ANSI_QWERTY_R4_                                        NUM_MINS, MACVIM_SQUOT, SYM_SMINS, ADJ_SRBRC


//      _______, _______, _______, _______, _______, _______, _______, _______, _______
#define ___________________TSANGAN_QWERTY_L3_________________                               KC_LSPO,   KC_Z,     KC_X,    KC_C,    KC_V,    KC_B

//      _______, _______, _______, _______, _______, _______, _______, _______, _______
#define ___________________TSANGAN_QWERTY_R0___________________________________________     LAYOUT_args5_wrapper(________________NUMBER_RIGHT_______________, KC_MINS, KC_EQL, KC_BSLASH, KC_DEL)
#define ___________________TSANGAN_QWERTY_R1___________________________________________     LAYOUT_args4_wrapper(_________________QWERTY_R1_________________, MACVIM_LBRC, KC_RBRC, KC_BSPC)
#define ___________________TSANGAN_QWERTY_R3_________________________                       KC_N,  KC_M,  KC_COMM, KC_DOT, KC_SLSH, KC_RSPC, ADJ_SMINS
#define _______TSANGAN_QWERTY_R4_                                                           NUM_MINS, MACVIM_SQUOT, ADJ_SRBRC

//      _______, _______, _______, _______, _______, _______, _______, _______,
#define ____________________ANSI_CAP_R1_______________________________________   LAYOUT_args3_wrapper(_________________ORTHO_GRID_CAP_R1__________________, _______, _______)
#define ____________________ANSI_CAP_R2______________________________            LAYOUT_args2_wrapper(_________________ORTHO_GRID_CAP_R2__________________, _______)

#define ___________________TSANGAN_CAP_R3_________________________     LAYOUT_args3_wrapper(_________________ORTHO_GRID_CAP_R3__________________, _______, _______)


//      _______, _______, _______, _______, _______, _______, _______, _______, _______
#define _______TSANGAN_MOUSE_L4__                             KC_LSFT, _______, _______

#define ___________________TSANGAN_MOUSE_R3__________________________ KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, KC_BTN2, KC_UP, KC_DOWN
#define _______TSANGAN_MOUSE_R4___________                            KC_BTN1, KC_LEFT, KC_DOWN, KC_RGHT

// #define ___________________ANSI_MACVIM_L0___________________     LAYOUT_args2_wrapper(VIM_ESC,   _________________MACVIM_L0_________________)
// #define ___________________ANSI_MACVIM_L1___________________     LAYOUT_args2_wrapper(VIM_ESC,   _________________MACVIM_L1_________________)
// #define ___________________ANSI_MACVIM_L2___________________     LAYOUT_args2_wrapper(DEFAULT,   _________________MACVIM_L2_________________)
// #define ___________________ANSI_MACVIM_L3___________________     LAYOUT_args2_wrapper(TG_VIMNUM, _________________MACVIM_L3_________________)
// #define ___________________ANSI_MACVIM_L4___________________     _______, _______, _______, _______, KC_LSFT,  MO_VIMNUM

// #define ___________________ANSI_MACVIM_R0___________________     LAYOUT_args2_wrapper(_________________MACVIM_R0_________________, _______)
// #define ___________________ANSI_MACVIM_R1___________________     LAYOUT_args2_wrapper(_________________MACVIM_R1_________________, CUT)
// #define ___________________ANSI_MACVIM_R2___________________     LAYOUT_args2_wrapper(_________________MACVIM_R2_________________, _______)
// #define ___________________ANSI_MACVIM_R3___________________     LAYOUT_args2_wrapper(_________________MACVIM_R3_________________, _______)
// #define ___________________ANSI_MACVIM_R4___________________     KC_BSPC, KC_LSFT, MO_VIMNUM, _______, _______, _______

// #define ___________________ANSI_VIMNUM_L0___________________     LAYOUT_args2_wrapper(_______, _________________VIMNUM_L0_________________)
// #define ___________________ANSI_VIMNUM_L1___________________     LAYOUT_args2_wrapper(_______, _________________VIMNUM_L1_________________)
// #define ___________________ANSI_VIMNUM_L2___________________     LAYOUT_args2_wrapper(DEFAULT, _________________VIMNUM_L2_________________)
// #define ___________________ANSI_VIMNUM_L3___________________     LAYOUT_args2_wrapper(_______, _________________VIMNUM_L3_________________)
// #define ___________________ANSI_VIMNUM_L4___________________     ______________________BLANK_6_______________________

// #define ___________________ANSI_VIMNUM_R0___________________     LAYOUT_args2_wrapper(_________________VIMNUM_R0_________________, _______)
// #define ___________________ANSI_VIMNUM_R1___________________     LAYOUT_args2_wrapper(_________________VIMNUM_R1_________________, _______)
// #define ___________________ANSI_VIMNUM_R2___________________     LAYOUT_args2_wrapper(_________________VIMNUM_R2_________________, _______)
// #define ___________________ANSI_VIMNUM_R3___________________     LAYOUT_args2_wrapper(_________________VIMNUM_R3_________________, _______)
// #define ___________________ANSI_VIMNUM_R4___________________     ______________________BLANK_6_______________________

// #define ___________________ANSI_MOUSE_L0____________________     LAYOUT_args2_wrapper(_______, _________________MOUSE_L0__________________)
// #define ___________________ANSI_MOUSE_L1____________________     LAYOUT_args2_wrapper(_______, _________________MOUSE_L1__________________)
// #define ___________________ANSI_MOUSE_L2____________________     LAYOUT_args2_wrapper(DEFAULT, _________________MOUSE_L2__________________)
// #define ___________________ANSI_MOUSE_L3____________________     LAYOUT_args2_wrapper(_______, _________________MOUSE_L3__________________)
// #define ___________________ANSI_MOUSE_L4____________________     LAYOUT_args2_wrapper(_______, _________________MOUSE_L4__________________)

// #define ___________________ANSI_MOUSE_R0____________________     LAYOUT_args2_wrapper(_________________MOUSE_R0__________________, _______)
// #define ___________________ANSI_MOUSE_R1____________________     LAYOUT_args2_wrapper(_________________MOUSE_R1__________________, CUT)
// #define ___________________ANSI_MOUSE_R2____________________     LAYOUT_args2_wrapper(_________________MOUSE_R2__________________, PASTE)
// #define ___________________ANSI_MOUSE_R3____________________     LAYOUT_args2_wrapper(_________________MOUSE_R3__________________, KC_DOWN)
// #define ___________________ANSI_MOUSE_R4____________________     LAYOUT_args2_wrapper(_________________MOUSE_R4__________________, KC_RGHT)

// #define ____________________ANSI_NUM_L0_____________________     LAYOUT_args2_wrapper(KC_BRID, __________________NUM_L0___________________)
// #define ____________________ANSI_NUM_L1_____________________     LAYOUT_args2_wrapper(_______, __________________NUM_L1___________________)
// #define ____________________ANSI_NUM_L2_____________________     LAYOUT_args2_wrapper(DEFAULT, __________________NUM_L2___________________)
// #define ____________________ANSI_NUM_L3_____________________     LAYOUT_args2_wrapper(_______, __________________NUM_L3___________________)
// #define ____________________ANSI_NUM_L4_____________________     LAYOUT_args2_wrapper(_______, __________________NUM_L4___________________)

// #define ____________________ANSI_NUM_R0_____________________     LAYOUT_args2_wrapper(__________________NUM_R0___________________, KC_VOLU)
// #define ____________________ANSI_NUM_R1_____________________     LAYOUT_args2_wrapper(__________________NUM_R1___________________, _______)
// #define ____________________ANSI_NUM_R2_____________________     LAYOUT_args2_wrapper(__________________NUM_R2___________________, _______)
// #define ____________________ANSI_NUM_R3_____________________     LAYOUT_args2_wrapper(__________________NUM_R3___________________, _______)
// #define ____________________ANSI_NUM_R4_____________________     LAYOUT_args2_wrapper(__________________NUM_R4___________________, KC_RGHT)

// #define ____________________ANSI_SYM_L0_____________________     LAYOUT_args2_wrapper(KC_F1,   __________________SYM_L0___________________)
// #define ____________________ANSI_SYM_L1_____________________     LAYOUT_args2_wrapper(NUM,     __________________SYM_L1___________________)
// #define ____________________ANSI_SYM_L2_____________________     LAYOUT_args2_wrapper(CAP,     __________________SYM_L2___________________)
// #define ____________________ANSI_SYM_L3_____________________     LAYOUT_args2_wrapper(_______, __________________SYM_L3___________________)
// #define ____________________ANSI_SYM_L4_____________________     LAYOUT_args2_wrapper(_______, __________________SYM_L4___________________)

// #define ____________________ANSI_SYM_R0_____________________     LAYOUT_args2_wrapper(__________________SYM_R0___________________, KC_F12)
// #define ____________________ANSI_SYM_R1_____________________     LAYOUT_args2_wrapper(__________________SYM_R1___________________, _______)
// #define ____________________ANSI_SYM_R2_____________________     LAYOUT_args2_wrapper(__________________SYM_R2___________________, _______)
// #define ____________________ANSI_SYM_R3_____________________     LAYOUT_args2_wrapper(__________________SYM_R3___________________, _______)
// #define ____________________ANSI_SYM_R4_____________________     LAYOUT_args2_wrapper(__________________SYM_R4___________________, _______)

// #define ________________ORTHO_GRID_ADJUST_L0________________     _________________ORTHO_GRID_NUM_L0__________________
// #define ________________ORTHO_5x12_ADJUST_L1________________     LAYOUT_args2_wrapper(_______, _________________ADJUST_L1_________________)
// #define ________________ORTHO_5x12_ADJUST_L2________________     LAYOUT_args2_wrapper(_______, _________________ADJUST_L2_________________)
// #define ________________ORTHO_5x12_ADJUST_L3________________     LAYOUT_args2_wrapper(_______, _________________ADJUST_L3_________________)
// #define ________________ORTHO_5x12_ADJUST_L4________________     LAYOUT_args2_wrapper(_______, _________________ADJUST_L4_________________)

// #define ________________ORTHO_GRID_ADJUST_R0________________     _________________ORTHO_GRID_NUM_R0__________________
// #define ________________ORTHO_5x12_ADJUST_R1________________     LAYOUT_args2_wrapper(_________________ADJUST_R1_________________, RESET)
// #define ________________ORTHO_5x12_ADJUST_R2________________     LAYOUT_args2_wrapper(_________________ADJUST_R2_________________, _______)
// #define ________________ORTHO_5x12_ADJUST_R3________________     LAYOUT_args2_wrapper(_________________ADJUST_R3_________________, _______)
// #define ________________ORTHO_5x12_ADJUST_R4________________     LAYOUT_args2_wrapper(_________________ADJUST_R4_________________, AUDIO)
