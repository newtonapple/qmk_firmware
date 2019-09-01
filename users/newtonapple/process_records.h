#pragma once
#include "newtonapple.h"

// Custom keycodes
enum custom_keycodes {
  ADJ_SBSLS = _NEWTONAPPLE_SAFE_RANGE,
  ADJ_SRBRC,
  ALT_SBSLS,
  CRTL_SLBRC,
  CRTL_SRBRC,
//   GUI_SMINS,
  RGUI_SQUOT,
//   GUI_T_EQL,
  MACVIM_SQUOT,
  MACVIM_RSPO,
  SYM_SQUOT,
  SYM_SMINS,
  NEWTONAPPLE_SAFE_RANGE,
};

#define DEFAULT TO(0)
#define QWERTY TO(_QWERTY)
#define CAP TO(_CAP)
#define NUM TO(_NUM)
#define SYM TO(_SYM)
#define MOUSE TO(_MOUSE)
#define ADJUST TO(_ADJUST)
#define AUDIO TO(_AUDIO)
#ifdef ENABLE_MACVIM
#define MACVIM TO(_MACVIM)
#endif

#define MOUSE_GRV LT(_MOUSE, KC_GRV)
#define MOUSE_TAB LT(_MOUSE, KC_TAB)
#define MOUSE_SPC LT(_MOUSE, KC_SPC)
#define MOUSE_LEFT LT(_MOUSE, KC_LEFT)
#define MOUSE_RGHT LT(_MOUSE, KC_RGHT)
#ifdef ENABLE_MACVIM
#define VIMNUM TO(_VIMNUM)
#define MACVIM_ESC LT(_MACVIM, KC_ESC)
#define MACVIM_SPC LT(_MACVIM, KC_SPC)
#define MACVIM_QUOT LT(_MACVIM, KC_QUOT)
#define MACVIM_LBRC LT(_MACVIM, KC_LBRC)
#define MO_VIMNUM MO(_VIMNUM)
#define TG_VIMNUM TG(_VIMNUM)
#endif

#define SYM_MINS LT(_SYM, KC_MINS)
#define SYM_SPC LT(_SYM, KC_SPC)
#define SYM_SCLN LT(_SYM, KC_SCLN)
#define NUM_QUOT LT(_NUM, KC_QUOT)
#define LED_LBRC LT(_LED, KC_LBRC)
#define LED_RBRC LT(_LED, KC_RBRC)
#define NUM_MINS LT(_NUM, KC_MINS)
#define ADJ_BSLS LT(_ADJUST, KC_BSLS)
#define GUI_T_EQL GUI_T(KC_EQL)
#define GUI_T_LBRC GUI_T(KC_LBRC)
#define GUI_T_RBRC RGUI_T(KC_RBRC)
#define SFT_T_QUOT SFT_T(KC_QUOT)
#define SFT_T_MINS SFT_T(KC_MINS)
#define RSFT_T_SLSH RSFT_T(KC_SLSH)
#define ALT_T_LBRC LALT_T(KC_LBRC)
#define ALT_T_RBRC RALT_T(KC_RBRC)
#define CTL_T_BSPC CTL_T(KC_BSPC)
#define CTL_T_BSLS CTL_T(KC_BSLS)
#define CTL_T_LEFT CTL_T(KC_LEFT)
#define CTL_T_RGHT CTL_T(KC_RGHT)

#define OSL_NUM OSL(_NUM)
#define OSL_SYM OSL(_SYM)

#define TT_NUM TT(_NUM)
#define TT_SYM TT(_SYM)

#ifndef CUSTOM_KEYMAP
// user these in keymap instad of their _user variants
bool process_record_keymap(uint16_t keycode, keyrecord_t *record);
uint32_t layer_state_set_keymap(uint32_t state);
#endif
