
#pragma once

#include "mac.h"

enum macvim_custom_keycodes {
  VIM_C = SAFE_RANGE,
  VIM_D,
  VIM_Y,
  VIM_V,
  VIM_X,
  VIM_0,
  VIM_DOLLAR,
  VIM_ESC,
};

#define VIM_B ALT_LEFT
#define VIM_W ALT_RGHT

#ifndef MACVIM_MAX_REPEAT
#define MACVIM_MAX_REPEAT 300
#endif

bool process_macvim(uint16_t keycode, keyrecord_t *record, bool with_repeat);
void reset_macvim_states(void);
