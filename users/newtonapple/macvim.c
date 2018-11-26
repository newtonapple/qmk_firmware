#include "macvim.h"

#define VIM_CUT_NEXT_CHAR()                                                    \
  MAC_CUT_NEXT_CHAR(VIM_REPEAT())                                              \
  RESET_VIM_REPEAT()

#define VIM_CUT_PREV_CHAR()                                                    \
  VIM_EXEC_AND_RESET_REPEAT_IF_MOD(LSHIFT, MAC_CUT_PREV_CHAR(VIM_REPEAT()))

#define VIM_CUT_TO_START_OF_WORD_FROM_CURSOR()                                 \
  VIM_EXEC_AND_RESET_REPEAT_IF_MOD(                                            \
      LCTRL, MAC_CUT_TO_START_OF_WORD_FROM_CURSOR(VIM_REPEAT()));

#define VIM_CUT_TO_END_OF_WORD_FROM_CURSOR()                                   \
  MAC_CUT_TO_END_OF_WORD_FROM_CURSOR(VIM_REPEAT())                             \
  RESET_VIM_REPEAT()

#define VIM_CUT_WORD_ON_CURSOR()                                               \
  MAC_CUT_WORD_ON_CURSOR(VIM_REPEAT())                                         \
  RESET_VIM_REPEAT()

#define VIM_CUT_TO_START_OF_LINE()                                             \
  MAC_SEL_TO_START_OF_LINE()                                                   \
  MAC_CUT()                                                                    \
  RESET_VIM_REPEAT()

#define VIM_CUT_TO_END_OF_LINE()                                               \
  MAC_SEL_TO_END_OF_LINE()                                                     \
  MAC_CUT()                                                                    \
  RESET_VIM_REPEAT()

#define VIM_CUT_LINE()                                                         \
  MAC_CUT_LINE(VIM_REPEAT())                                                   \
  RESET_VIM_REPEAT()

#define VIM_SHIFT_YANK() VIM_EXEC_IF_SHIFT(MAC_COPY());
#define VIM_SHIFT_CHANGE() VIM_EXEC_IF_SHIFT(MAC_CUT());
#define VIM_SHIFT_DELETE() VIM_SHIFT_CHANGE()

#define VIM_SEL_NEXT_CHAR()                                                    \
  VIM_EXEC_AND_RESET_REPEAT_IF_MOD(LSHIFT, MAC_SEL_NEXT_CHAR(VIM_REPEAT()));

#define VIM_SEL_PREV_CHAR()                                                    \
  VIM_EXEC_AND_RESET_REPEAT_IF_MOD(LSHIFT, MAC_SEL_PREV_CHAR(VIM_REPEAT()));

#define VIM_SEL_TO_START_OF_WORD()                                             \
  VIM_EXEC_AND_RESET_REPEAT_IF_MOD(LSHIFT,                                     \
                                   MAC_SEL_TO_START_OF_WORD(VIM_REPEAT()));

#define VIM_SEL_TO_END_OF_WORD()                                               \
  VIM_EXEC_AND_RESET_REPEAT_IF_MOD(LSHIFT,                                     \
                                   MAC_SEL_TO_END_OF_WORD(VIM_REPEAT()));

#define VIM_SEL_TO_START_OF_LINE()                                             \
  VIM_EXEC_AND_RESET_REPEAT_IF_MOD(LSHIFT, MAC_SEL_TO_START_OF_LINE());

#define VIM_SEL_TO_END_OF_LINE()                                               \
  VIM_EXEC_AND_RESET_REPEAT_IF_MOD(LSHIFT, MAC_SEL_TO_END_OF_LINE());

#define VIM_SEL_LINE()                                                         \
  VIM_EXEC_AND_RESET_REPEAT_IF_MOD(LSHIFT, MAC_SEL_LINE(VIM_REPEAT()));

#define VIM_SEL_TO_NEXT_LINE()                                                 \
  VIM_EXEC_AND_RESET_REPEAT_IF_MOD(LSHIFT, MAC_SEL_TO_NEXT_LINE(VIM_REPEAT()));

#define VIM_SEL_TO_PREV_LINE()                                                 \
  VIM_EXEC_AND_RESET_REPEAT_IF_MOD(LSHIFT, MAC_SEL_TO_PREV_LINE(VIM_REPEAT()));

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

static uint16_t vim_repeat = 0;

enum VIMODES {
  VIMODE_NO = 0,
  VIMODE_VISUAL,
  VIMODE_CHANGE,
  VIMODE_DELETE,
  VIMODE_YANK,
};
#define VIM_EDIT_MODE_OFFSET VIMODE_CHANGE
#define VIM_EDIT_MODE_IDX(MODE) (MODE - VIMODE_CHANGE)

#define VIM_EDIT(MODE)                                                         \
  if (vim_visual_edit(VIMODE_##MODE))                                          \
    return false;                                                              \
  VIM_SHIFT_##MODE();                                                          \
  if (vim_edit_lines(VIMODE_##MODE))                                           \
    return false;                                                              \
  SET_VIMODE_##MODE();                                                         \
  return false;

static uint8_t vimode = VIMODE_NO;

#define IS_VIMODE(MODE) (vimode & (1U << VIMODE_##MODE))
#define SET_VIMODE(MODE) (vimode |= (1U << VIMODE_##MODE));
#define SET_VIMODE_VISUAL() (vimode |= (1U << VIMODE_VISUAL));
#define SET_VIMODE_YANK() (vimode = (1U << VIMODE_YANK) | IS_VIMODE(VISUAL));
#define SET_VIMODE_CHANGE()                                                    \
  (vimode = (1U << VIMODE_CHANGE) | IS_VIMODE(VISUAL));
#define SET_VIMODE_DELETE()                                                    \
  (vimode = (1U << VIMODE_DELETE) | IS_VIMODE(VISUAL));

#define RESET_VIMODE(MODE) (vimode &= ~(1U << VIMODE_##MODE));
#define RESET_VIMODES() (vimode = VIMODE_NO);

uint16_t get_repeat(void);
bool is_vimode(uint8_t mode);
void reset_vimode(uint8_t mode);

bool vim_visual_edit(uint8_t mode);
void vim_cut_selection(void);
void vim_copy_selection(void);

bool vim_edit_lines(uint8_t mode);
void vim_cut_lines(void);
void vim_copy_lines(void);

typedef void (*VimEdit)(void);

VimEdit vim_visual_edit_funcs[] = {
    &vim_cut_selection,
    &vim_cut_selection,
    &vim_copy_selection,
};

VimEdit vim_edit_lines_funcs[] = {
    &vim_cut_lines,
    &vim_cut_lines,
    &vim_copy_lines,
};

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
    reset_macvim_states();
    return true;
  }
  return false;
};
void vim_cut_selection() { MAC_CUT(); };
void vim_copy_selection() { MAC_COPY(); };

bool vim_edit_lines(uint8_t mode) {
  if (is_vimode(mode)) {
    reset_vimode(mode);
    if (mode == VIMODE_YANK) {
      MAC_COPY_LINE(VIM_REPEAT());
      MAC_LEFT();
    } else {
      MAC_CUT_LINE(VIM_REPEAT());
    }
    // vim_edit_lines_funcs[VIM_EDIT_MODE_IDX(mode)]();
    vim_repeat = 0;
    return true;
  }
  return false;
};

void vim_cut_lines() { MAC_CUT_LINE(VIM_REPEAT()); }
void vim_copy_lines() { MAC_COPY_LINE(VIM_REPEAT()); }

void reset_macvim_states(void) {
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
      VIM_EDIT(CHANGE);
    case VIM_D:
      VIM_EDIT(DELETE);
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
    case VIM_Y:
      VIM_EDIT(YANK);
    case VIM_X:
      VIM_CUT_PREV_CHAR();
      VIM_CUT_NEXT_CHAR();
    case VIM_ESC:
      reset_macvim_states();
    }
  }
  return true;
}
