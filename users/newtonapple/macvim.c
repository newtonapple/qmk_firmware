#include "macvim.h"

#define VIM_CUT_NEXT_CHAR()                                                    \
  MAC_CUT_NEXT_CHAR(VIM_REPEAT())                                              \
  CLEAR_VIM_REPEAT_AND_RETURN()

#define VIM_CUT_PREV_CHAR()                                                    \
  VIM_WITH_MOD(LSHIFT, MAC_CUT_PREV_CHAR(VIM_REPEAT()))

#define VIM_CUT_TO_START_OF_WORD_FROM_CURSOR()                                 \
  VIM_WITH_MOD(LCTRL, MAC_CUT_TO_START_OF_WORD_FROM_CURSOR(VIM_REPEAT()));

#define VIM_CUT_TO_END_OF_WORD_FROM_CURSOR()                                   \
  MAC_CUT_TO_END_OF_WORD_FROM_CURSOR(VIM_REPEAT())                             \
  CLEAR_VIM_REPEAT_AND_RETURN()

#define VIM_CUT_WORD_ON_CURSOR()                                               \
  MAC_CUT_WORD_ON_CURSOR(VIM_REPEAT())                                         \
  CLEAR_VIM_REPEAT_AND_RETURN()

#define VIM_CUT_TO_START_OF_LINE()                                             \
  MAC_SEL_TO_START_OF_LINE()                                                   \
  MAC_CUT()                                                                    \
  CLEAR_VIM_REPEAT_AND_RETURN()

#define VIM_CUT_TO_END_OF_LINE()                                               \
  MAC_SEL_TO_END_OF_LINE()                                                     \
  MAC_CUT()                                                                    \
  CLEAR_VIM_REPEAT_AND_RETURN()

#define VIM_CUT_LINE()                                                         \
  MAC_CUT_LINE(VIM_REPEAT())                                                   \
  CLEAR_VIM_REPEAT_AND_RETURN()

#define VIM_SEL_NEXT_CHAR()                                                    \
  VIM_WITH_MOD(LSHIFT, MAC_SEL_NEXT_CHAR(VIM_REPEAT()));

#define VIM_SEL_PREV_CHAR()                                                    \
  VIM_WITH_MOD(LSHIFT, MAC_SEL_PREV_CHAR(VIM_REPEAT()));

#define VIM_SEL_TO_START_OF_WORD()                                             \
  VIM_WITH_MOD(LSHIFT, MAC_SEL_TO_START_OF_WORD(VIM_REPEAT()));

#define VIM_SEL_TO_END_OF_WORD()                                               \
  VIM_WITH_MOD(LSHIFT, MAC_SEL_TO_END_OF_WORD(VIM_REPEAT()));

#define VIM_SEL_TO_START_OF_LINE()                                             \
  VIM_WITH_MOD(LSHIFT, MAC_SEL_TO_START_OF_LINE());

#define VIM_SEL_TO_END_OF_LINE()                                               \
  VIM_WITH_MOD(LSHIFT, MAC_SEL_TO_END_OF_LINE());

#define VIM_SEL_LINE()                                                         \
  VIM_WITH_MOD(LSHIFT, MAC_SEL_LINE(VIM_REPEAT()));

#define VIM_SEL_TO_NEXT_LINE()                                                 \
  VIM_WITH_MOD(LSHIFT, MAC_SEL_TO_NEXT_LINE(VIM_REPEAT()));

#define VIM_SEL_TO_PREV_LINE()                                                 \
  VIM_WITH_MOD(LSHIFT, MAC_SEL_TO_PREV_LINE(VIM_REPEAT()));

#define VIM_MOV_TO_NEXT_CHAR()                                                 \
  MAC_MOV_TO_NEXT_CHAR(VIM_REPEAT())                                           \
  CLEAR_VIM_REPEAT_AND_RETURN()

#define VIM_MOV_TO_PREV_CHAR()                                                 \
  MAC_MOV_TO_PREV_CHAR(VIM_REPEAT())                                           \
  CLEAR_VIM_REPEAT_AND_RETURN()

#define VIM_MOV_TO_START_OF_WORD()                                             \
  MAC_MOV_TO_START_OF_WORD(VIM_REPEAT())                                       \
  CLEAR_VIM_REPEAT_AND_RETURN()

#define VIM_MOV_TO_END_OF_WORD()                                               \
  MAC_MOV_TO_END_OF_WORD(VIM_REPEAT())                                         \
  CLEAR_VIM_REPEAT_AND_RETURN()

#define VIM_MOV_TO_NEXT_LINE()                                                 \
  MAC_MOV_TO_NEXT_LINE(VIM_REPEAT())                                           \
  CLEAR_VIM_REPEAT_AND_RETURN()

#define VIM_MOV_TO_PREV_LINE()                                                 \
  MAC_MOV_TO_PREV_LINE(VIM_REPEAT())                                           \
  CLEAR_VIM_REPEAT_AND_RETURN()

#define VIM_MOV_LINE_UP() VIM_WITH_MOD(LALT, MAC_MOV_LINE_UP(VIM_REPEAT()));

#define VIM_MOV_LINE_DOWN() VIM_WITH_MOD(LALT, MAC_MOV_LINE_DOWN(VIM_REPEAT()));

#define VIM_WITH_MOD(MOD, CODE)                                                \
  if (get_mods() & MOD_BIT(KC_##MOD)) {                                        \
    SEND_STRING(SS_UP(X_##MOD));                                               \
    CODE;                                                                      \
    SEND_STRING(SS_DOWN(X_##MOD));                                             \
    CLEAR_VIM_REPEAT_AND_RETURN();                                             \
  }

#define CLEAR_VIM_REPEAT_AND_RETURN()                                          \
  vim_repeat = 0;                                                              \
  return false;

static uint16_t vim_repeat = 0;
#define VIM_REPEAT() (vim_repeat > 0 ? vim_repeat : 1)

bool process_macvim(uint16_t keycode, keyrecord_t *record, bool with_repeat) {
  if (record->event.pressed) {
    if (with_repeat) {
      if (keycode >= KC_1 && keycode <= KC_0) {
        uint16_t repeat = (10 - (KC_0 - keycode)) % 10;
        if (vim_repeat > 0) {
          vim_repeat = vim_repeat * 10 + repeat;
          if (vim_repeat > MACVIM_MAX_REPEAT)
            vim_repeat = MACVIM_MAX_REPEAT;
        } else {
          vim_repeat = repeat;
        }
        return false;
      }
      // Hijack left, right, up, down to add vim repeat.
      if (vim_repeat > 0) {
        switch (keycode) {
        case KC_LEFT:
          VIM_SEL_PREV_CHAR();
          VIM_MOV_TO_PREV_CHAR();
        case KC_RIGHT:
          VIM_SEL_NEXT_CHAR();
          VIM_MOV_TO_NEXT_CHAR();
        case KC_UP:
          VIM_MOV_LINE_UP();
          VIM_SEL_TO_PREV_LINE();
          VIM_MOV_TO_PREV_LINE();
        case KC_DOWN:
          VIM_MOV_LINE_UP();
          VIM_SEL_TO_NEXT_LINE();
          VIM_MOV_TO_NEXT_LINE();
        }
      }
    }

    switch (keycode) {
    case VIM_W:
      VIM_SEL_TO_END_OF_WORD();
      VIM_MOV_TO_END_OF_WORD();
    case VIM_B:
      VIM_SEL_TO_START_OF_WORD();
      VIM_CUT_TO_START_OF_WORD_FROM_CURSOR();
      VIM_MOV_TO_START_OF_WORD();
    case VIM_C:
      VIM_CUT_WORD_ON_CURSOR();
    case VIM_D:
      VIM_CUT_TO_END_OF_WORD_FROM_CURSOR();
    case VIM_V:
      VIM_SEL_LINE();
      VIM_CUT_LINE();
    case VIM_DOLLAR:
      VIM_SEL_TO_END_OF_LINE();
      VIM_CUT_TO_END_OF_LINE();
    case VIM_0:
      VIM_SEL_TO_START_OF_LINE();
      VIM_CUT_TO_START_OF_LINE();
    case VIM_X:
      VIM_CUT_PREV_CHAR();
      VIM_CUT_NEXT_CHAR();
    case VIM_ESC:
      CLEAR_VIM_REPEAT_AND_RETURN();
    }
  }
  return true;
}
