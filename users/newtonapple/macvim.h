
#pragma once

#include "mac.h"

enum macvim_custom_keycodes {
  VIM_B = SAFE_RANGE,
  VIM_C,
  VIM_D,
  VIM_V,
  VIM_X,
  VIM_0,
  VIM_DOLLAR,
  VIM_ESC,
};

#define VIM_B ALT_LEFT
#define VIM_W ALT_RGHT

#ifndef MACVIM_MAX_REPEAT
#define MACVIM_MAX_REPEAT 9999
#endif

bool process_macvim(uint16_t keycode, keyrecord_t *record, bool with_repeat);
