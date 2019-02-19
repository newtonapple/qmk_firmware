#pragma once
#include "quantum.h"

#ifdef ENABLE_MACVIM
#include "macvim.h"
#define _NEWTONAPPLE_SAFE_RANGE VIM_SAFE_RANGE
#else
#define _NEWTONAPPLE_SAFE_RANGE SAFE_RANGE
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
#define MACVIM_SPC LT(_MACVIM, KC_SPC)
#define LED_RBRC LT(_LED, KC_RBRC)
#define NUM_MINS LT(_NUM, KC_MINS)
#define GUI_T_EQL GUI_T(KC_EQL)
#define SFT_T_QUOT SFT_T(KC_QUOT)
#define ALT_T_LBRC LALT_T(KC_LBRC)
#define ALT_T_RBRC RALT_T(KC_RBRC)

#define OSL_NUM OSL(_NUM)
#define OSL_SYM OSL(_SYM)

#define TT_NUM TT(_NUM)
#define TT_SYM TT(_SYM)

#ifdef ENABLE_SPACE_CADET

/*
 * To use SPACE_CADET* macros, you must define the static timer variable:
 *    static uint16_t space_cadet_timer;
 *
 * The SPACE_CADET* macros assume only one key is pressed at a time,
 * i.e. no mixing modifier or layer keys are held at the same time.  It uses
 * `TAPPING_TERM` is defined. as it's default timeout value.
 *
 * You can use `space_cadet` & `space_cadet_layer` for custom timers & timouts.
 */

#define SPACE_CADET(keycode, kc_custom, kc_mod, str, pressed)                  \
  if (keycode == kc_custom) {                                                  \
    space_cadet(kc_mod, str, pressed, &space_cadet_timer, TAPPING_TERM);       \
    return false;                                                              \
  };

#define SPACE_CADET_LAYER(keycode, kc_custom, layer, str, pressed)             \
  if (keycode == kc_custom) {                                                  \
    space_cadet_layer(layer, str, pressed, &space_cadet_timer, TAPPING_TERM);  \
    return false;                                                              \
  };

void space_cadet(uint16_t kc_mod, const char *str, bool pressed,
                 uint16_t *timer, uint16_t timeout);

void space_cadet_layer(uint8_t layer, const char *str, bool pressed,
                       uint16_t *timer, uint16_t timeout);
#endif

void rgb_matrix_scan(void);
