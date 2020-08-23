#pragma once
#include "quantum.h"

// Layers
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
  _FN
};

#ifdef ENABLE_MACVIM
#include "macvim.h"
#define _NEWTONAPPLE_SAFE_RANGE VIM_SAFE_RANGE
#else
#define _NEWTONAPPLE_SAFE_RANGE SAFE_RANGE
#endif

#ifdef AUDIO_ENABLE
#include "muse.h"
#endif

#ifdef ENABLE_SPACE_CADET
#include "space_cadet.h"
#endif

#ifndef CUSTOM_KEYMAP
#include "process_records.h"
#include "wrappers.h"
#endif
