#include "macvim.h"

#define VIM_CUT_NEXT_CHAR()                                                    \
  MAC_CUT_NEXT_CHAR(VIM_REPEAT())                                              \
  RESET_VIM_REPEAT()
#define VIM_CUT_PREV_CHAR()                                                    \
  VIM_EXEC_AND_RESET_REPEAT_IF_MOD(LSHIFT, MAC_CUT_PREV_CHAR(VIM_REPEAT()))

#define VIM_CUT_TO_START_OF_WORD_FROM_CURSOR()                                 \
  if (IS_VIMODE(DELETE)) {                                                     \
    MAC_CUT_TO_START_OF_WORD_FROM_CURSOR(VIM_REPEAT())                         \
    RESET_VIM_STATES()                                                         \
  }
#define VIM_CUT_TO_END_OF_WORD_FROM_CURSOR()                                   \
  if (IS_VIMODE(DELETE)) {                                                     \
    MAC_CUT_TO_END_OF_WORD_FROM_CURSOR(VIM_REPEAT())                           \
    RESET_VIM_STATES()                                                         \
  }
#define VIM_CUT_TO_NEXT_WORD_FROM_CURSOR()                                     \
  if (IS_VIMODE(DELETE)) {                                                     \
    MAC_CUT_TO_NEXT_WORD_FROM_CURSOR(VIM_REPEAT())                             \
    RESET_VIM_STATES()                                                         \
  }
#define VIM_CUT_WORD_ON_CURSOR()                                               \
  if (IS_VIMODE(CHANGE)) {                                                     \
    MAC_CUT_WORD_ON_CURSOR(VIM_REPEAT())                                       \
    RESET_VIM_STATES()                                                         \
  }

#define VIM_COPY_TO_START_OF_WORD_FROM_CURSOR()                                \
  if (IS_VIMODE(YANK)) {                                                       \
    MAC_COPY_TO_START_OF_WORD_FROM_CURSOR(VIM_REPEAT())                        \
    MAC_LEFT()                                                                 \
    RESET_VIM_STATES()                                                         \
  }
#define VIM_COPY_TO_END_OF_WORD_FROM_CURSOR()                                  \
  if (IS_VIMODE(YANK)) {                                                       \
    MAC_COPY_TO_END_OF_WORD_FROM_CURSOR(VIM_REPEAT())                          \
    MAC_LEFT()                                                                 \
    RESET_VIM_STATES()                                                         \
  }
#define VIM_COPY_TO_NEXT_WORD_FROM_CURSOR()                                    \
  if (IS_VIMODE(YANK)) {                                                       \
    MAC_COPY_TO_NEXT_WORD_FROM_CURSOR(VIM_REPEAT())                            \
    MAC_LEFT()                                                                 \
    RESET_VIM_STATES()                                                         \
  }

#define VIM_COPY_WORD_ON_CURSOR()                                              \
  if (IS_VIMODE(YANKI)) {                                                      \
    MAC_COPY_WORD_ON_CURSOR(VIM_REPEAT())                                      \
    MAC_LEFT()                                                                 \
    RESET_VIM_STATES()                                                         \
  }

#define VIM_COPY_TO_START_OF_LINE()                                            \
  if (IS_VIMODE(YANK)) {                                                       \
    MAC_COPY_TO_START_OF_LINE()                                                \
    MAC_RIGHT()                                                                \
    RESET_VIM_STATES()                                                         \
  }
#define VIM_COPY_TO_END_OF_LINE()                                              \
  if (IS_VIMODE(YANK)) {                                                       \
    MAC_COPY_TO_END_OF_LINE()                                                  \
    MAC_LEFT()                                                                 \
    RESET_VIM_STATES()                                                         \
  }

#define VIM_CUT_TO_START_OF_LINE()                                             \
  if (IS_VIMODE(DELETE)) {                                                     \
    MAC_CUT_TO_START_OF_LINE()                                                 \
    RESET_VIM_STATES()                                                         \
  }
#define VIM_CUT_TO_END_OF_LINE()                                               \
  if (IS_VIMODE(DELETE)) {                                                     \
    MAC_CUT_TO_END_OF_LINE()                                                   \
    RESET_VIM_STATES()                                                         \
  }

#define VIM_SHIFT_YANK() VIM_EXEC_IF_SHIFT(MAC_COPY())
#define VIM_SHIFT_CHANGE() VIM_EXEC_IF_SHIFT(MAC_CUT())
#define VIM_SHIFT_DELETE() VIM_SHIFT_CHANGE()

#define VIM_SEL_WORD_ON_CURSOR()                                               \
  if (IS_VIMODE(VISUALI)) {                                                    \
    MAC_UP_SHIFT()                                                             \
    MAC_SEL_WORD_ON_CURSOR(VIM_REPEAT())                                       \
    MAC_DOWN_SHIFT()                                                           \
    SET_VIMODE_VISUAL()                                                        \
    RESET_VIM_REPEAT()                                                         \
  }

#define VIM_SEL_LINE()                                                         \
  VIM_EXEC_AND_RESET_REPEAT_IF_MOD(LSHIFT, MAC_SEL_LINE(VIM_REPEAT()));

#define VIM_MOV_TO_NEXT_CHAR()                                                 \
  MAC_MOV_TO_NEXT_CHAR(VIM_REPEAT())                                           \
  RESET_VIM_REPEAT()
#define VIM_MOV_TO_PREV_CHAR()                                                 \
  MAC_MOV_TO_PREV_CHAR(VIM_REPEAT())                                           \
  RESET_VIM_REPEAT()

#define VIM_MOV_TO_START_OF_WORD()                                             \
  MAC_MOV_TO_START_OF_WORD(VIM_REPEAT())                                       \
  RESET_VIM_REPEAT()
#define VIM_MOV_TO_END_OF_WORD()                                               \
  MAC_MOV_TO_END_OF_WORD(VIM_REPEAT())                                         \
  RESET_VIM_REPEAT()
#define VIM_MOV_TO_NEXT_WORD()                                                 \
  MAC_MOV_TO_NEXT_WORD(VIM_REPEAT())                                           \
  RESET_VIM_REPEAT()

#define VIM_INSERT_NEW_LINE()                                                  \
  MAC_MOV_TO_END_OF_LINE()                                                     \
  REPEAT_SEND_STRING(VIM_REPEAT(), SS_TAP(X_ENTER))                            \
  RESET_VIM_STATES()

#define VIM_MOV_TO_START_OF_LINE()                                             \
  MAC_MOV_TO_START_OF_LINE()                                                   \
  RESET_VIM_REPEAT()
#define VIM_MOV_TO_END_OF_LINE()                                               \
  MAC_MOV_TO_END_OF_LINE()                                                     \
  RESET_VIM_REPEAT()
#define VIM_MOV_TO_NEXT_LINE()                                                 \
  MAC_MOV_TO_NEXT_LINE(VIM_REPEAT())                                           \
  RESET_VIM_REPEAT()
#define VIM_MOV_TO_PREV_LINE()                                                 \
  MAC_MOV_TO_PREV_LINE(VIM_REPEAT())                                           \
  RESET_VIM_REPEAT()
#define VIM_MOV_LINE_UP()                                                      \
  VIM_EXEC_AND_RESET_REPEAT_IF_MOD(LALT, MAC_MOV_LINE_UP(VIM_REPEAT()));
#define VIM_MOV_LINE_DOWN()                                                    \
  VIM_EXEC_AND_RESET_REPEAT_IF_MOD(LALT, MAC_MOV_LINE_DOWN(VIM_REPEAT()));

#define VIM_EXEC_AND_RESET_REPEAT_IF_MOD(MOD, CODE)                            \
  if (IS_MOD_ON(MOD)) {                                                        \
    SEND_STRING(SS_UP(X_##MOD));                                               \
    CODE;                                                                      \
    SEND_STRING(SS_DOWN(X_##MOD));                                             \
    RESET_VIM_REPEAT();                                                        \
  }

#define VIM_EXEC_IF_SHIFT(CODE)                                                \
  VIM_EXEC_AND_RESET_REPEAT_IF_MOD(LSHIFT, CODE);                              \
  VIM_EXEC_AND_RESET_REPEAT_IF_MOD(RSHIFT, CODE);

#define IS_MOD_ON(MOD) get_mods() & MOD_BIT(KC_##MOD)
#define VIM_REPEAT() get_repeat()
#define RESET_VIM_REPEAT()                                                     \
  vim_repeat = 0;                                                              \
  return false;

#define RESET_VIM_STATES()                                                     \
  reset_vim_states();                                                          \
  return false;

static uint16_t vim_repeat = 0;

enum VIMODES {
  VIMODE_NO = 0,
  VIMODE_VISUAL,
  VIMODE_VISUALI,
  VIMODE_CHANGE,
  VIMODE_DELETE,
  VIMODE_YANK,
  VIMODE_YANKI,
};
// #define VIM_EDIT_MODE_OFFSET VIMODE_CHANGE
// #define VIM_EDIT_MODE_IDX(MODE) (MODE - VIMODE_CHANGE)

#define VIM_EDIT(MODE)                                                         \
  if (vim_visual_edit(VIMODE_##MODE))                                          \
    return false;                                                              \
  VIM_SHIFT_##MODE();                                                          \
  if (vim_edit_lines(VIMODE_##MODE))                                           \
    return false;                                                              \
  SET_VIMODE_##MODE();                                                         \
  return false;

static uint8_t vimode = VIMODE_NO;

#define VIMODE_NO_MASK (1U << VIMODE_NO)
#define VIMODE_VISUAL_MASK (1U << VIMODE_VISUAL)
#define VIMODE_VISUALI_MASK (1U << VIMODE_VISUALI)
#define VIMODE_DELETE_MASK (1U << VIMODE_DELETE)
#define VIMODE_CHANGE_MASK (1U << VIMODE_CHANGE)
#define VIMODE_YANK_MASK (1U << VIMODE_YANK)
#define VIMODE_YANKI_MASK (1U << VIMODE_YANKI)

#define IS_VIMODE(MODE) (vimode & VIMODE_##MODE##_MASK)
#define IS_VIMODE_EDIT()                                                       \
  (vimode & (VIMODE_DELETE_MASK | VIMODE_CHANGE_MASK | VIMODE_YANK_MASK |      \
             VIMODE_YANKI_MASK))
#define SET_VIMODE_VISUAL() (vimode = VIMODE_VISUAL_MASK);
#define SET_VIMODE_VISUALI() (vimode = VIMODE_VISUALI_MASK);
#define SET_VIMODE_YANK() (vimode = VIMODE_YANK_MASK | IS_VIMODE(VISUAL));
#define SET_VIMODE_YANKI() (vimode = VIMODE_YANKI_MASK | IS_VIMODE(VISUAL));
#define SET_VIMODE_CHANGE() (vimode = VIMODE_CHANGE_MASK | IS_VIMODE(VISUAL));
#define SET_VIMODE_DELETE() (vimode = VIMODE_DELETE_MASK | IS_VIMODE(VISUAL));

#define RESET_VIMODE(MODE) (vimode &= ~VIMODE_##MODE##_MASK);
#define RESET_VIMODES() (vimode = VIMODE_NO);

uint16_t get_repeat(void);
bool is_vimode(uint8_t mode);
void reset_vimode(uint8_t mode);

bool vim_visual_edit(uint8_t mode);

bool vim_edit_lines(uint8_t mode);

uint16_t get_repeat(void) { return (vim_repeat > 0 ? vim_repeat : 1); };
void reset_vimode(uint8_t mode) { vimode &= ~(1U << mode); };
bool is_vimode(uint8_t mode) { return (vimode & (1U << mode)); };

bool vim_visual_edit(uint8_t mode) {
  if (IS_VIMODE(VISUAL)) {
    MAC_UP_SHIFT();
    if (mode == VIMODE_YANK) {
      MAC_COPY();
      MAC_LEFT();
    } else {
      MAC_CUT();
    }
    reset_vim_states();
    return true;
  }
  return false;
};

bool vim_edit_lines(uint8_t mode) {
  if (is_vimode(mode)) {
    reset_vimode(mode);
    if (mode == VIMODE_YANK) {
      MAC_COPY_LINE(VIM_REPEAT());
      MAC_LEFT();
    } else if (mode == VIMODE_DELETE) {
      MAC_CUT_LINE(VIM_REPEAT());
      MAC_DELETE();
    } else {
      MAC_CUT_LINE(VIM_REPEAT());
    }
    vim_repeat = 0;
    return true;
  }
  return false;
};

void reset_vim_states(void) {
  vim_repeat = 0;
  if (IS_VIMODE(VISUAL) && IS_MOD_ON(LSHIFT)) {
    MAC_UP_SHIFT();
  }
  RESET_VIMODES();
};

void toggle_visual_mode(void) {
  if (IS_MOD_ON(LSHIFT)) {
    MAC_UP_SHIFT();
    RESET_VIMODE(VISUAL);
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
      if (vim_repeat > 0 || IS_VIMODE_EDIT()) {
        switch (keycode) {
        case VIM_E:
          VIM_COPY_TO_END_OF_WORD_FROM_CURSOR();
          VIM_CUT_TO_END_OF_WORD_FROM_CURSOR();
          VIM_CUT_WORD_ON_CURSOR();
          VIM_MOV_TO_END_OF_WORD();
        case VIM_B:
          VIM_COPY_TO_START_OF_WORD_FROM_CURSOR();
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
    case VIM_W:
      VIM_SEL_WORD_ON_CURSOR();
      VIM_COPY_WORD_ON_CURSOR();
      VIM_COPY_TO_NEXT_WORD_FROM_CURSOR();
      VIM_CUT_TO_NEXT_WORD_FROM_CURSOR();
      VIM_CUT_WORD_ON_CURSOR();
      VIM_MOV_TO_NEXT_WORD();
    case VIM_C:
      VIM_EDIT(CHANGE);
    case VIM_D:
      VIM_EDIT(DELETE);
    case VIM_Y:
      VIM_EDIT(YANK);
    case VIM_X:
      if (vim_visual_edit(VIMODE_DELETE))
        return false;
      VIM_CUT_PREV_CHAR();
      VIM_CUT_NEXT_CHAR();
    case VIM_I:
      if (is_vimode(VIMODE_VISUAL)) {
        SET_VIMODE_VISUALI();
      } else if (is_vimode(VIMODE_YANK)) {
        SET_VIMODE_YANKI();
      } else {
        VIM_MOV_TO_START_OF_LINE();
      }
      return false;
    case VIM_O:
      VIM_INSERT_NEW_LINE();
    case VIM_0:
      VIM_COPY_TO_START_OF_LINE();
      VIM_CUT_TO_START_OF_LINE();
      VIM_MOV_TO_START_OF_LINE();
    case VIM_DOL:
      VIM_COPY_TO_END_OF_LINE();
      VIM_CUT_TO_END_OF_LINE();
      VIM_MOV_TO_END_OF_LINE();
    case VIM_V:
      if (IS_MOD_ON(LSHIFT)) {
        // turn off visual mode
        if (IS_VIMODE(VISUAL)) {
          MAC_UP_SHIFT();
          RESET_VIMODE(VISUAL);
        } else {
          SET_VIMODE_VISUAL();
          VIM_SEL_LINE();
        }
      } else {
        MAC_DOWN_SHIFT();
        SET_VIMODE_VISUAL();
      }
      return false;
    case VIM_ESC:
      reset_vim_states();
    }
  }
  return true;
}
