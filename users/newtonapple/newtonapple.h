#pragma once
#include "quantum.h"
#include "wrappers.h"

#ifdef ENABLE_MACVIM
#include "macvim.h"
#define _NEWTONAPPLE_SAFE_RANGE VIM_SAFE_RANGE
#else
#define _NEWTONAPPLE_SAFE_RANGE SAFE_RANGE
#endif

#ifdef ENABLE_SPACE_CADET
#include "space_cadet.h"
#endif

enum newtonapple_layers {
  _QWERTY,
  _CODE,
  _CAP,
#ifdef ENABLE_MACVIM
  _MACVIM,
  _VIMNUM,
#endif
  _MOUSE,
  _NUM,
  _SYM,
  _LED,
  _ADJUST,
  _AUDIO,
};

enum custom_keycodes {
  CRTL_SLBRC = _NEWTONAPPLE_SAFE_RANGE,
  CRTL_SRBRC,
  CMD_SMINS,
  MACVIM_SQUOT,
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
#define MO_VIMNUM MO(_VIMNUM)
#define TG_VIMNUM TG(_VIMNUM)
#endif

#define SYM_MINS LT(_SYM, KC_MINS)
#define SYM_SPC LT(_SYM, KC_SPC)
#define LED_LBRC LT(_LED, KC_LBRC)
#define LED_RBRC LT(_LED, KC_RBRC)
#define NUM_MINS LT(_NUM, KC_MINS)
#define ADJ_BSLS LT(_ADJUST, KC_BSLS)
#define GUI_T_EQL GUI_T(KC_EQL)
#define GUI_T_LBRC GUI_T(KC_LBRC)
#define GUI_T_RBRC RGUI_T(KC_RBRC)
#define SFT_T_QUOT SFT_T(KC_QUOT)
#define ALT_T_LBRC LALT_T(KC_LBRC)
#define ALT_T_RBRC RALT_T(KC_RBRC)
#define CTL_T_BSPC CTL_T(KC_BSPC)
#define CTL_T_LEFT CTL_T(KC_LEFT)
#define CTL_T_RGHT CTL_T(KC_RGHT)

#define OSL_NUM OSL(_NUM)
#define OSL_SYM OSL(_SYM)

#define TT_NUM TT(_NUM)
#define TT_SYM TT(_SYM)

#ifdef RGBLIGHT_ENABLE
void rgb_matrix_scan(void);
#endif
