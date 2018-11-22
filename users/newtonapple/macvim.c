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

#define VIM_COPY_LINE()                                                        \
  MAC_COPY_LINE(VIM_REPEAT())                                                  \
  MAC_LEFT();                                                                  \
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

#define VIM_SEL_TO_END_OF_LINE() VIM_WITH_MOD(LSHIFT, MAC_SEL_TO_END_OF_LINE());

#define VIM_SEL_LINE() VIM_WITH_MOD(LSHIFT, MAC_SEL_LINE(VIM_REPEAT()));

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
  if (IS_MOD_ON(MOD)) {                                                        \
    SEND_STRING(SS_UP(X_##MOD));                                               \
    CODE;                                                                      \
    SEND_STRING(SS_DOWN(X_##MOD));                                             \
    CLEAR_VIM_REPEAT_AND_RETURN();                                             \
  }

#define IS_MOD_ON(MOD) get_mods() & MOD_BIT(KC_##MOD)
#define VIM_REPEAT() get_repeat()
#define CLEAR_VIM_REPEAT_AND_RETURN()                                          \
  vim_repeat = 0;                                                              \
  return false;

static uint16_t vim_repeat = 0;

enum VIMODES {
  VIMODE_NO,
  VIMODE_VISUAL,
  VIMODE_DELETE,
  VIMODE_YANK,
};

static uint8_t vimode = VIMODE_NO;

#define IS_VIMODE(MODE) (vimode & (1U << VIMODE_##MODE))
#define SET_VIMODE(MODE) (vimode |= (1U << VIMODE_##MODE));
#define SET_VIMODE_VISUAL() (vimode |= (1U << VIMODE_VISUAL));
#define SET_VIMODE_YANK() (vimode = (1U << VIMODE_YANK) | IS_VIMODE(VISUAL));
#define SET_VIMODE_DELETE()                                                    \
  (vimode = (1U << VIMODE_DELETE) | IS_VIMODE(VISUAL));
#define CLEAR_VIMODE(MODE) (vimode &= ~(1U << VIMODE_##MODE));
#define CLEAR_VIMODES() (vimode = VIMODE_NO);

uint16_t get_repeat(void) { return (vim_repeat > 0 ? vim_repeat : 1); };

void reset_macvim_states(void) {
  vim_repeat = 0;
  if (IS_VIMODE(VISUAL) && IS_MOD_ON(LSHIFT)) {
    MAC_UP_SHIFT();
  }
  CLEAR_VIMODES();
};

void toggle_visual_mode(void) {
  if (IS_MOD_ON(LSHIFT)) {
    MAC_UP_SHIFT();
    CLEAR_VIMODE(VISUAL);
  } else {
    MAC_DOWN_SHIFT();
    SET_VIMODE_VISUAL();
  }
};

bool process_macvim(uint16_t keycode, keyrecord_t *record, bool with_repeat) {
  if (record->event.pressed) {
    if (with_repeat) {
      if (keycode >= KC_1 && keycode <= KC_0) {
        uint16_t repeat = (10 - (KC_0 - keycode)) % 10;
        if (vim_repeat > 0) {
          vim_repeat = vim_repeat * 10 + repeat;
          if (vim_repeat > MACVIM_MAX_REPEAT)
            vim_repeat = 0; // probably made a mistake, to be safe reset it to 0
        } else {
          vim_repeat = repeat;
        }
        return false;
      }
      // Hijack alt-left, alt-right, left, right, up, down to add vim repeat.
      if (vim_repeat > 0) {
        switch (keycode) {
        case VIM_W:
          VIM_MOV_TO_END_OF_WORD();
        case VIM_B:
          VIM_CUT_TO_START_OF_WORD_FROM_CURSOR();
          VIM_MOV_TO_START_OF_WORD();
        case KC_LEFT:
          VIM_MOV_TO_PREV_CHAR();
        case KC_RIGHT:
          VIM_MOV_TO_NEXT_CHAR();
        case KC_UP:
          VIM_MOV_LINE_UP();
          VIM_MOV_TO_PREV_LINE();
        case KC_DOWN:
          VIM_MOV_LINE_DOWN();
          VIM_MOV_TO_NEXT_LINE();
        }
      }
    }

    switch (keycode) {
    case VIM_C:
      VIM_CUT_WORD_ON_CURSOR();
    case VIM_D:
      VIM_CUT_TO_END_OF_WORD_FROM_CURSOR();
    case VIM_V:
      if (IS_MOD_ON(LSHIFT)) {
        // turn off visual mode
        if (IS_VIMODE(VISUAL)) {
          MAC_UP_SHIFT();
          CLEAR_VIMODE(VISUAL);
        } else {
          SET_VIMODE_VISUAL();
          VIM_SEL_LINE();
        }
      } else {
        MAC_DOWN_SHIFT();
        SET_VIMODE_VISUAL();
      }
      return false;
    case VIM_Y:
      if (IS_VIMODE(VISUAL)) {
        // don't hold down shift while copy
        MAC_UP_SHIFT();
        MAC_COPY();
        // deselect by moving one character to the left
        MAC_LEFT();
        reset_macvim_states();
        return false;
      }
      // allow copy while holding down shift
      VIM_WITH_MOD(LSHIFT, MAC_COPY());
      VIM_WITH_MOD(RSHIFT, MAC_COPY());

      if (IS_VIMODE(YANK)) {
        CLEAR_VIMODE(YANK);
        VIM_COPY_LINE();
      } else {
        SET_VIMODE_YANK();
      }
      return false;
    case VIM_X:
      VIM_CUT_PREV_CHAR();
      VIM_CUT_NEXT_CHAR();
    case VIM_ESC:
      reset_macvim_states();
    }
  }
  return true;
}
