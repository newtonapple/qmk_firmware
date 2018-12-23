#pragma once

#ifdef ENABLE_MACVIM
#include "macvim.h"
#endif

enum newtonapple_layers {
  _QWERTY,
  _CAP,
#ifdef ENABLE_MACVIM
  _MACVIM,
  _VIMNUM,
#endif
  _MOUSE,
  _NUM,
  _SYM,
  _LED,
};

#define QWERTY TO(_QWERTY)
#define CAP TO(_CAP)
#define NUM TO(_NUM)
#define SYM TO(_SYM)
#define MOUSE TO(_MOUSE)
#ifdef ENABLE_MACVIM
#define MACVIM TO(_MACVIM)
#endif

#define MOUSE_GRV LT(_MOUSE, KC_GRV)
#define MOUSE_TAB LT(_MOUSE, KC_TAB)
#ifdef ENABLE_MACVIM
#define VIMNUM TO(_VIMNUM)
#define MACVIM_ESC LT(_MACVIM, KC_ESC)
#define MACVIM_SPC LT(_MACVIM, KC_SPC)
#define MO_VIMNUM MO(_VIMNUM)
#define TG_VIMNUM TG(_VIMNUM)
#endif

#define SYM_MINS LT(_SYM, KC_MINS)
#define SYM_SPC LT(_SYM, KC_SPC)
#define NUM_MINS LT(_NUM, KC_MINS)
#define GUI_T_EQL GUI_T(KC_EQL)
#define SFT_T_QUOT SFT_T(KC_QUOT)

#define OSL_NUM OSL(_NUM)
#define OSL_SYM OSL(_SYM)

#define TT_NUM TT(_NUM)
#define TT_SYM TT(_SYM)
