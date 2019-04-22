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
#define _________________QWERTY_R2_________________     KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN
#define _________________QWERTY_R3_________________     KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLASH


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
#define ________________ORTHO_GRID_QWERTY_L4________________     CRTL_SLBRC, KC_LCTL, ALT_T_LBRC, GUI_T_EQL, SYM_SMINS, MOUSE_SPC

#define ________________ORTHO_GRID_QWERTY_R0________________     LAYOUT_args2_wrapper(________________NUMBER_RIGHT_______________, KC_BSPC)
#define ________________ORTHO_GRID_QWERTY_R1________________     LAYOUT_args2_wrapper(_________________QWERTY_R1_________________, KC_BSPC)
#define ________________ORTHO_GRID_QWERTY_R2________________     LAYOUT_args2_wrapper(_________________QWERTY_R2_________________, KC_ENT)
#define ________________ORTHO_GRID_QWERTY_R3________________     LAYOUT_args2_wrapper(_________________QWERTY_R3_________________, KC_RSPC)
#define ________________ORTHO_GRID_QWERTY_R4________________     MACVIM_SQUOT, SFT_T_QUOT, NUM_MINS, CMD_SMINS, ALT_T_RBRC, CRTL_SRBRC

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
#define _________________MACVIM_R3_________________     PREV_TAB, NEXT_TAB, UNINDENT, INDENT,  _______


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
