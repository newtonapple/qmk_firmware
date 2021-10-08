
#pragma once

#include "mac.h"

enum macvim_custom_keycodes {
  VIM_C = SAFE_RANGE,
  VIM_D,
  VIM_I,
  VIM_O,
  VIM_Y,
  VIM_V,
  VIM_W,
  VIM_X,
  VIM_0,
  VIM_DOLLAR,
  VIM_ESC,
  VIM_SAFE_RANGE
};

#define VIM_B ALT_LEFT
#define VIM_E ALT_RGHT
#define VIM_DOL VIM_DOLLAR

#ifndef MACVIM_MAX_REPEAT
#define MACVIM_MAX_REPEAT 300
#endif

bool process_macvim(uint16_t keycode, keyrecord_t *record, bool with_repeat);
void reset_vim_states(void);
