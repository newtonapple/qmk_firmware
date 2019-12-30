#pragma once
#include "newtonapple.h"

/*
Since our quirky block definitions are basically a list of comma separated
arguments, we need a wrapper in order for these definitions to be
expanded before being used as arguments to the LAYOUT_xxx macro.
*/

#if (!defined(LAYOUT) && defined(KEYMAP))
#define LAYOUT KEYMAP
#endif

#define KEYMAP_wrapper(...)                    LAYOUT(__VA_ARGS__)
#define LAYOUT_wrapper(...)                    LAYOUT(__VA_ARGS__)
#define LAYOUT_60_ansi_wrapper(...)            LAYOUT_60_ansi(__VA_ARGS__)
#define LAYOUT_ortho_4x12_wrapper(...)         LAYOUT_ortho_4x12(__VA_ARGS__)
#define LAYOUT_ortho_5x12_wrapper(...)         LAYOUT_ortho_5x12(__VA_ARGS__)
#define LAYOUT_ortho_5x15_wrapper(...)         LAYOUT_ortho_5x15(__VA_ARGS__)

/*
 *Layout arguments wrappers to allow a simple way to combine defined blocks
 */
#define LAYOUT_args2_wrapper(LEFT, RIGHT)      LEFT, RIGHT
#define LAYOUT_args3_wrapper(LEFT, MID, RIGHT) LEFT, MID, RIGHT


#define _________BLANK_3_________  \
        _______, _______, _______
#define __________________BLANK_5__________________  \
        _______, _______, _______, _______, _______
#define ______________________BLANK_6_______________________  \
        _______, _______, _______, _______, _______, _______
#define _________________________________________________BLANK_12_________________________________________________ \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
#define _______________________________________________________________BLANK_15______________________________________________________________ \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
/*
 * Blocks for _QWERTY layer
 */
#define _________________QWERTY_L1_________________     KC_Q,    KC_W,    KC_E,    KC_R,    KC_T
#define _________________QWERTY_L2_________________     KC_A,    KC_S,    KC_D,    KC_F,    KC_G
#define _________________QWERTY_L3_________________     KC_Z,    KC_X,    KC_C,    KC_V,    KC_B

#define _________________QWERTY_R1_________________     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P
#define _________________QWERTY_R2_________________     KC_H,    KC_J,    KC_K,    KC_L,    SYM_SCLN
#define _________________QWERTY_R3_________________     KC_N,    KC_M,    KC_COMM, KC_DOT,  RSFT_T_SLSH


#define ________________NUMBER_LEFT________________     KC_1,    KC_2,    KC_3,    KC_4,    KC_5
#define ________________NUMBER_RIGHT_______________     KC_6,    KC_7,    KC_8,    KC_9,    KC_0
#define _________________FUNC_LEFT_________________     KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5
#define _________________FUNC_RIGHT________________     KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10


#define __________________CAP_L1___________________     S(KC_Q), S(KC_W), S(KC_E), S(KC_R), S(KC_T)
#define __________________CAP_L2___________________     S(KC_A), S(KC_S), S(KC_D), S(KC_F), S(KC_G)
#define __________________CAP_L3___________________     S(KC_Z), S(KC_X), S(KC_C), S(KC_V), S(KC_B)


#define __________________CAP_R1___________________     S(KC_Y), S(KC_U), S(KC_I), S(KC_O), S(KC_P)
#define __________________CAP_R2___________________     S(KC_H), S(KC_J), S(KC_K), S(KC_L), _______
#define __________________CAP_R3___________________     S(KC_N), S(KC_M), _______, _______, _______


#define ________________ORTHO_GRID_QWERTY_L0________________     LAYOUT_args2_wrapper(MOUSE_GRV,  ________________NUMBER_LEFT________________)
#define ________________ORTHO_GRID_QWERTY_L1________________     LAYOUT_args2_wrapper(MOUSE_TAB,  _________________QWERTY_L1_________________)
#define ________________ORTHO_GRID_QWERTY_L2________________     LAYOUT_args2_wrapper(MACVIM_ESC, _________________QWERTY_L2_________________)
#define ________________ORTHO_GRID_QWERTY_L3________________     LAYOUT_args2_wrapper(KC_LSPO,    _________________QWERTY_L3_________________)
#define ________________ORTHO_GRID_QWERTY_L4________________     CRTL_SLBRC, CTL_T_BSLS, ALT_T_LBRC, GUI_T_EQL, SYM_SMINS, KC_SPC

#define ________________ORTHO_GRID_QWERTY_R0________________     LAYOUT_args2_wrapper(________________NUMBER_RIGHT_______________, KC_BSPC)
#define ________________ORTHO_GRID_QWERTY_R1________________     LAYOUT_args2_wrapper(_________________QWERTY_R1_________________, KC_BSPC)
#define ________________ORTHO_GRID_QWERTY_R2________________     LAYOUT_args2_wrapper(_________________QWERTY_R2_________________, MACVIM_ENT)
#define ________________ORTHO_GRID_QWERTY_R3________________     LAYOUT_args2_wrapper(_________________QWERTY_R3_________________, KC_RSPC)
#define ________________ORTHO_GRID_QWERTY_R4________________     MACVIM_SQUOT, SFT_T_QUOT, NUM_MINS, GUI_T_RBRC, ADJ_SBSLS, CRTL_SRBRC

#define _________________ORTHO_GRID_CAP_L1__________________     LAYOUT_args2_wrapper(_______, __________________CAP_L1___________________)
#define _________________ORTHO_GRID_CAP_L2__________________     LAYOUT_args2_wrapper(DEFAULT, __________________CAP_L2___________________)
#define _________________ORTHO_GRID_CAP_L3__________________     LAYOUT_args2_wrapper(_______, __________________CAP_L3___________________)

#define _________________ORTHO_GRID_CAP_R1__________________     LAYOUT_args2_wrapper(__________________CAP_R1___________________, _______)
#define _________________ORTHO_GRID_CAP_R2__________________     LAYOUT_args2_wrapper(__________________CAP_R2___________________, _______)
#define _________________ORTHO_GRID_CAP_R3__________________     LAYOUT_args2_wrapper(__________________CAP_R3___________________, _______)


/*
 * Blocks for _MACVIM layer
 */
#define _________________MACVIM_L0_________________     ________________NUMBER_LEFT________________
#define _________________MACVIM_L1_________________     VIM_0,   VIM_W,   VIM_E,   REDO,     VIM_DOL
#define _________________MACVIM_L2_________________     VIM_DOL, SAVE,    VIM_D,   CMD_LEFT, CMD_RGHT
#define _________________MACVIM_L3_________________     UNDO,    VIM_X,   VIM_C,   VIM_V,    VIM_B

#define _________________MACVIM_R0_________________     ________________NUMBER_RIGHT_______________
#define _________________MACVIM_R1_________________     VIM_Y,    UNDO,     VIM_I,    VIM_O,   PASTE
#define _________________MACVIM_R2_________________     KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT, VIM_0
#define _________________MACVIM_R3_________________     PREV_TAB, NEXT_TAB, UNINDENT, INDENT,  KC_BSPC


#define ________________ORTHO_GRID_MACVIM_L0________________     LAYOUT_args2_wrapper(VIM_ESC,   _________________MACVIM_L0_________________)
#define ________________ORTHO_GRID_MACVIM_L1________________     LAYOUT_args2_wrapper(VIM_ESC,   _________________MACVIM_L1_________________)
#define ________________ORTHO_GRID_MACVIM_L2________________     LAYOUT_args2_wrapper(DEFAULT,   _________________MACVIM_L2_________________)
#define ________________ORTHO_GRID_MACVIM_L3________________     LAYOUT_args2_wrapper(TG_VIMNUM, _________________MACVIM_L3_________________)
#define ________________ORTHO_GRID_MACVIM_L4________________     _______, _______, _______, _______, KC_LSFT,  MO_VIMNUM

#define ________________ORTHO_GRID_MACVIM_R0________________     LAYOUT_args2_wrapper(_________________MACVIM_R0_________________, _______)
#define ________________ORTHO_GRID_MACVIM_R1________________     LAYOUT_args2_wrapper(_________________MACVIM_R1_________________, CUT)
#define ________________ORTHO_GRID_MACVIM_R2________________     LAYOUT_args2_wrapper(_________________MACVIM_R2_________________, _______)
#define ________________ORTHO_GRID_MACVIM_R3________________     LAYOUT_args2_wrapper(_________________MACVIM_R3_________________, _______)
#define ________________ORTHO_GRID_MACVIM_R4________________     KC_BSPC, KC_LSFT, MO_VIMNUM, _______, _______, _______


#define _________________VIMNUM_L0_________________     __________________BLANK_5__________________
#define _________________VIMNUM_L1_________________     __________________BLANK_5__________________
#define _________________VIMNUM_L2_________________     ________________NUMBER_LEFT________________
#define _________________VIMNUM_L3_________________     __________________BLANK_5__________________

#define _________________VIMNUM_R0_________________     __________________BLANK_5__________________
#define _________________VIMNUM_R1_________________     __________________BLANK_5__________________
#define _________________VIMNUM_R2_________________     ________________NUMBER_RIGHT_______________
#define _________________VIMNUM_R3_________________     __________________BLANK_5__________________

#define ________________ORTHO_GRID_VIMNUM_L0________________     LAYOUT_args2_wrapper(_______, _________________VIMNUM_L0_________________)
#define ________________ORTHO_GRID_VIMNUM_L1________________     LAYOUT_args2_wrapper(_______, _________________VIMNUM_L1_________________)
#define ________________ORTHO_GRID_VIMNUM_L2________________     LAYOUT_args2_wrapper(DEFAULT, _________________VIMNUM_L2_________________)
#define ________________ORTHO_GRID_VIMNUM_L3________________     LAYOUT_args2_wrapper(_______, _________________VIMNUM_L3_________________)
#define ________________ORTHO_GRID_VIMNUM_L4________________     ______________________BLANK_6_______________________

#define ________________ORTHO_GRID_VIMNUM_R0________________     LAYOUT_args2_wrapper(_________________VIMNUM_R0_________________, _______)
#define ________________ORTHO_GRID_VIMNUM_R1________________     LAYOUT_args2_wrapper(_________________VIMNUM_R1_________________, _______)
#define ________________ORTHO_GRID_VIMNUM_R2________________     LAYOUT_args2_wrapper(_________________VIMNUM_R2_________________, _______)
#define ________________ORTHO_GRID_VIMNUM_R3________________     LAYOUT_args2_wrapper(_________________VIMNUM_R3_________________, _______)
#define ________________ORTHO_GRID_VIMNUM_R4________________     ______________________BLANK_6_______________________


/*
 * Blocks for _MOUSE layer
 */
#define _________________MOUSE_L0__________________     KC_ACL2, KC_ACL0, KC_ACL1, _______, _______
#define _________________MOUSE_L1__________________     QUIT,    CLOSE,   KC_ACL2, REDO,    KC_PGUP
#define _________________MOUSE_L2__________________     SEL_ALL, KC_ACL2, KC_ACL0, KC_ACL1, KC_PGDN
#define _________________MOUSE_L3__________________     _______, _______, _______, KC_LSFT, _______
#define _________________MOUSE_L4__________________     _______, _______, _______, KC_LSFT, KC_ACL0

#define _________________MOUSE_R0__________________     __________________BLANK_5__________________
#define _________________MOUSE_R1__________________     COPY,    UNDO,    PREV_TAB, NEXT_TAB, PASTE
#define _________________MOUSE_R2__________________     KC_MS_L, KC_MS_D, KC_MS_U,  KC_MS_R,  COPY
#define _________________MOUSE_R3__________________     KC_WH_L, KC_WH_D, KC_WH_U,  KC_WH_R,  KC_UP
#define _________________MOUSE_R4__________________     KC_ENTER, KC_BTN1, KC_BTN2, KC_LEFT,  KC_DOWN


#define ________________ORTHO_GRID_MOUSE_L0_________________     LAYOUT_args2_wrapper(_______, _________________MOUSE_L0__________________)
#define ________________ORTHO_GRID_MOUSE_L1_________________     LAYOUT_args2_wrapper(_______, _________________MOUSE_L1__________________)
#define ________________ORTHO_GRID_MOUSE_L2_________________     LAYOUT_args2_wrapper(DEFAULT, _________________MOUSE_L2__________________)
#define ________________ORTHO_GRID_MOUSE_L3_________________     LAYOUT_args2_wrapper(_______, _________________MOUSE_L3__________________)
#define ________________ORTHO_GRID_MOUSE_L4_________________     LAYOUT_args2_wrapper(_______, _________________MOUSE_L4__________________)

#define ________________ORTHO_GRID_MOUSE_R0_________________     LAYOUT_args2_wrapper(_________________MOUSE_R0__________________, _______)
#define ________________ORTHO_GRID_MOUSE_R1_________________     LAYOUT_args2_wrapper(_________________MOUSE_R1__________________, CUT)
#define ________________ORTHO_GRID_MOUSE_R2_________________     LAYOUT_args2_wrapper(_________________MOUSE_R2__________________, PASTE)
#define ________________ORTHO_GRID_MOUSE_R3_________________     LAYOUT_args2_wrapper(_________________MOUSE_R3__________________, KC_DOWN)
#define ________________ORTHO_GRID_MOUSE_R4_________________     LAYOUT_args2_wrapper(_________________MOUSE_R4__________________, KC_RGHT)


/*
 * Blocks for _SYM layer
 */
#define __________________NUM_L0___________________     KC_BRIU,  C(KC_UP),  C(KC_DOWN), C(KC_LEFT), C(KC_RGHT)
#define __________________NUM_L1___________________     KC_GRV,   S(KC_GRV), KC_EQL,     KC_MINS,    S(KC_EQL)
#define __________________NUM_L2___________________     KC_1,     KC_2,      KC_3,       KC_4,       KC_5
#define __________________NUM_L3___________________     S(KC_5),  S(KC_9),   S(KC_0),    KC_QUOT,    S(KC_QUOT)
#define __________________NUM_L4___________________     _______,  _______,   _______,    _______,    _______

#define __________________NUM_R0___________________     KC_MRWD,  KC_MPLY,   KC_MFFD,    KC_MUTE,    KC_VOLD
#define __________________NUM_R1___________________     S(KC_6),  S(KC_8),   S(KC_BSLS), KC_BSLS,    S(KC_MINS)
#define __________________NUM_R2___________________     KC_6,     KC_7,      KC_8,       KC_9,       KC_0
#define __________________NUM_R3___________________     KC_LBRC,  KC_RBRC,   _______,    _______,    _______
#define __________________NUM_R4___________________     _______,  OSL_SYM,   KC_UP,      KC_DOWN,    KC_LEFT

#define _________________ORTHO_GRID_NUM_L0__________________     LAYOUT_args2_wrapper(KC_BRID, __________________NUM_L0___________________)
#define _________________ORTHO_GRID_NUM_L1__________________     LAYOUT_args2_wrapper(_______, __________________NUM_L1___________________)
#define _________________ORTHO_GRID_NUM_L2__________________     LAYOUT_args2_wrapper(DEFAULT, __________________NUM_L2___________________)
#define _________________ORTHO_GRID_NUM_L3__________________     LAYOUT_args2_wrapper(_______, __________________NUM_L3___________________)
#define _________________ORTHO_GRID_NUM_L4__________________     LAYOUT_args2_wrapper(_______, __________________NUM_L4___________________)

#define _________________ORTHO_GRID_NUM_R0__________________     LAYOUT_args2_wrapper(__________________NUM_R0___________________, KC_VOLU)
#define _________________ORTHO_GRID_NUM_R1__________________     LAYOUT_args2_wrapper(__________________NUM_R1___________________, _______)
#define _________________ORTHO_GRID_NUM_R2__________________     LAYOUT_args2_wrapper(__________________NUM_R2___________________, _______)
#define _________________ORTHO_GRID_NUM_R3__________________     LAYOUT_args2_wrapper(__________________NUM_R3___________________, _______)
#define _________________ORTHO_GRID_NUM_R4__________________     LAYOUT_args2_wrapper(__________________NUM_R4___________________, KC_RGHT)

/*
 * Blocks for _SYM layer
 */
#define __________________SYM_L0___________________      KC_F2,   KC_F3,     KC_F4,   KC_F5,    KC_F6
#define __________________SYM_L1___________________      KC_GRV,  S(KC_GRV), KC_EQL,  KC_MINS,  S(KC_EQL)
#define __________________SYM_L2___________________      S(KC_1), S(KC_2),   S(KC_3), S(KC_4),  S(KC_5)
#define __________________SYM_L3___________________      S(KC_5), MOUSE,     MACVIM,  S(KC_9),  S(KC_0)
#define __________________SYM_L4___________________      _______, _______,   _______, _______,   _______

#define __________________SYM_R0___________________     KC_F7,      KC_F8,      KC_F9,      KC_F10,  KC_F11
#define __________________SYM_R1___________________     S(KC_LBRC), S(KC_RBRC), S(KC_BSLS), KC_BSLS, S(KC_MINS)
#define __________________SYM_R2___________________     S(KC_6),    S(KC_7),    S(KC_8),    S(KC_9), S(KC_0)
#define __________________SYM_R3___________________     KC_LBRC,    KC_RBRC,    _______,    _______, _______
#define __________________SYM_R4___________________     KC_BSPC,    S(KC_QUOT), S(KC_MINS), _______, _______

#define _________________ORTHO_GRID_SYM_L0__________________     LAYOUT_args2_wrapper(KC_F1,   __________________SYM_L0___________________)
#define _________________ORTHO_GRID_SYM_L1__________________     LAYOUT_args2_wrapper(NUM,     __________________SYM_L1___________________)
#define _________________ORTHO_GRID_SYM_L2__________________     LAYOUT_args2_wrapper(CAP,     __________________SYM_L2___________________)
#define _________________ORTHO_GRID_SYM_L3__________________     LAYOUT_args2_wrapper(_______, __________________SYM_L3___________________)
#define _________________ORTHO_GRID_SYM_L4__________________     LAYOUT_args2_wrapper(_______, __________________SYM_L4___________________)

#define _________________ORTHO_GRID_SYM_R0__________________     LAYOUT_args2_wrapper(__________________SYM_R0___________________, KC_F12)
#define _________________ORTHO_GRID_SYM_R1__________________     LAYOUT_args2_wrapper(__________________SYM_R1___________________, _______)
#define _________________ORTHO_GRID_SYM_R2__________________     LAYOUT_args2_wrapper(__________________SYM_R2___________________, _______)
#define _________________ORTHO_GRID_SYM_R3__________________     LAYOUT_args2_wrapper(__________________SYM_R3___________________, _______)
#define _________________ORTHO_GRID_SYM_R4__________________     LAYOUT_args2_wrapper(__________________SYM_R4___________________, _______)


/*
 * Blocks for _ADJUST layer
 */
#define _________________ADJUST_L0_________________     __________________NUM_L0___________________
#define _________________ADJUST_L1_________________     MI_ON,   MI_OFF,  MU_MOD, MUV_IN,   MUV_DE
#define _________________ADJUST_L2_________________     AU_ON,   AU_OFF,  CK_RST, CK_UP,    CK_DOWN
#define _________________ADJUST_L3_________________     MU_ON,   MU_OFF,  CK_ON,  CK_OFF,   _______
#define _________________ADJUST_L4_________________     __________________BLANK_5__________________

#define _________________ADJUST_R0_________________     __________________NUM_R0___________________
#define _________________ADJUST_R1_________________     RGB_TOG, RGB_MOD, RGB_RMOD, RGB_VAI, RGB_VAD
#define _________________ADJUST_R2_________________     BL_TOGG, RGB_SAI, RGB_SAD,  RGB_HUI, RGB_HUD
#define _________________ADJUST_R3_________________     BL_BRTG, BL_INC,  BL_DEC,   VLK_TOG, _______
#define _________________ADJUST_R4_________________     __________________BLANK_5__________________

#define ________________ORTHO_GRID_ADJUST_L0________________     _________________ORTHO_GRID_NUM_L0__________________
#define ________________ORTHO_5x12_ADJUST_L1________________     LAYOUT_args2_wrapper(_______, _________________ADJUST_L1_________________)
#define ________________ORTHO_5x12_ADJUST_L2________________     LAYOUT_args2_wrapper(_______, _________________ADJUST_L2_________________)
#define ________________ORTHO_5x12_ADJUST_L3________________     LAYOUT_args2_wrapper(_______, _________________ADJUST_L3_________________)
#define ________________ORTHO_5x12_ADJUST_L4________________     LAYOUT_args2_wrapper(_______, _________________ADJUST_L4_________________)

#define ________________ORTHO_GRID_ADJUST_R0________________     _________________ORTHO_GRID_NUM_R0__________________
#define ________________ORTHO_5x12_ADJUST_R1________________     LAYOUT_args2_wrapper(_________________ADJUST_R1_________________, RESET)
#define ________________ORTHO_5x12_ADJUST_R2________________     LAYOUT_args2_wrapper(_________________ADJUST_R2_________________, _______)
#define ________________ORTHO_5x12_ADJUST_R3________________     LAYOUT_args2_wrapper(_________________ADJUST_R3_________________, _______)
#define ________________ORTHO_5x12_ADJUST_R4________________     LAYOUT_args2_wrapper(_________________ADJUST_R4_________________, AUDIO)

#define ________________ORTHO_4x12_ADJUST_L1________________     LAYOUT_args2_wrapper(_______, _________________ADJUST_L1_________________)
#define ________________ORTHO_4x12_ADJUST_L2________________     LAYOUT_args2_wrapper(_______, _________________ADJUST_L2_________________)
#define ________________ORTHO_4x12_ADJUST_L3________________     LAYOUT_args2_wrapper(_______, _________________ADJUST_L3_________________)

#define ________________ORTHO_4x12_ADJUST_R1________________     LAYOUT_args2_wrapper(_________________ADJUST_R1_________________, RESET)
#define ________________ORTHO_4x12_ADJUST_R2________________     LAYOUT_args2_wrapper(_________________ADJUST_R2_________________, _______)
#define ________________ORTHO_4x12_ADJUST_R3________________     LAYOUT_args2_wrapper(_________________ADJUST_R3_________________, AUDIO)

