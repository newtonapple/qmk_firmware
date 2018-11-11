#pragma once

#include "quantum.h"

enum custom_keycodes {
  VIM_B = SAFE_RANGE,
  VIM_C,
  VIM_D,
  VIM_V,
  VIM_W,
  VIM_X,
  VIM_0,
  VIM_DOLLAR,
  VIM_ESC,
};

bool process_macvim(uint16_t keycode, keyrecord_t *record, bool with_repeat);
