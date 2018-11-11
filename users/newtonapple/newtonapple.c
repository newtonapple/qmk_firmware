#include "newtonapple.h"

#define SS_TAP_LEFT SS_TAP(X_LEFT)
#define SS_TAP_RIGHT SS_TAP(X_RIGHT)
#define SS_TAP_UP SS_TAP(X_UP)
#define SS_TAP_DOWN SS_TAP(X_DOWN)

#define SS_TAP_ALT_LEFT SS_LALT(SS_TAP_LEFT)
#define SS_TAP_ALT_RIGHT SS_LALT(SS_TAP_RIGHT)
#define SS_TAP_ALT_SFT_LEFT SS_LSFT(SS_TAP_ALT_LEFT)
#define SS_TAP_ALT_SFT_RIGHT SS_LSFT(SS_TAP_ALT_RIGHT)

#define SS_TAP_GUI_RIGHT SS_LGUI(SS_TAP_RIGHT)
#define SS_TAP_GUI_LEFT SS_LGUI(SS_TAP_LEFT)
#define SS_TAP_GUI_SFT_RIGHT SS_LSFT(SS_TAP_GUI_RIGHT)
#define SS_TAP_GUI_SFT_LEFT SS_LSFT(SS_TAP_GUI_LEFT)

#define SS_TAP_SFT_LEFT SS_LSFT(SS_TAP_LEFT)
#define SS_TAP_SFT_RIGHT SS_LSFT(SS_TAP_RIGHT)
#define SS_TAP_SFT_UP SS_LSFT(SS_TAP_UP)
#define SS_TAP_SFT_DOWN SS_LSFT(SS_TAP_DOWN)

#define SS_TAP_MAC_CUT SS_LGUI("x")

#define VIM_CUT_NEXT_CHAR_FROM_CURSOR                                          \
  MAC_CUT_NEXT_CHAR_FROM_CURSOR(VIM_REPEAT)                                    \
  CLEAR_VIM_REPEAT_AND_RETURN

#define VIM_CUT_PREV_CHAR_FROM_CURSOR                                          \
  MAC_CUT_PREV_CHAR_FROM_CURSOR(VIM_REPEAT)                                    \
  CLEAR_VIM_REPEAT_AND_RETURN

#define VIM_CUT_TO_END_OF_WORD_FROM_CURSOR                                     \
  MAC_CUT_TO_END_OF_WORD_FROM_CURSOR(VIM_REPEAT)                               \
  CLEAR_VIM_REPEAT_AND_RETURN

#define VIM_CUT_WORD_ON_CURSOR                                                 \
  MAC_CUT_WORD_ON_CURSOR(VIM_REPEAT)                                           \
  CLEAR_VIM_REPEAT_AND_RETURN

#define VIM_CUT_LINE                                                           \
  MAC_CUT_LINE(VIM_REPEAT)                                                     \
  CLEAR_VIM_REPEAT_AND_RETURN

#define VIM_CUT_TO_START_OF_WORD_FROM_CURSOR                                   \
  VIM_WITH_MOD(KC_LCTL, X_LCTRL,                                               \
               MAC_CUT_TO_START_OF_WORD_FROM_CURSOR(VIM_REPEAT));

#define VIM_CUT_TO_START_OF_LINE                                               \
  MAC_SEL_TO_START_OF_LINE                                                     \
  MAC_CUT                                                                      \
  CLEAR_VIM_REPEAT_AND_RETURN

#define VIM_SEL_TO_START_OF_LINE                                               \
  VIM_WITH_MOD(KC_LSFT, X_LSHIFT, MAC_SEL_TO_START_OF_LINE);

#define VIM_CUT_TO_END_OF_LINE                                                 \
  MAC_SEL_TO_END_OF_LINE                                                       \
  MAC_CUT                                                                      \
  CLEAR_VIM_REPEAT_AND_RETURN

#define VIM_SEL_TO_END_OF_LINE                                                 \
  VIM_WITH_MOD(KC_LSFT, X_LSHIFT, MAC_SEL_TO_END_OF_LINE);

#define VIM_SEL_LINE VIM_WITH_MOD(KC_LSFT, X_LSHIFT, MAC_SEL_LINE(VIM_REPEAT));

#define VIM_SEL_TO_START_OF_WORD_FROM_CURSOR                                   \
  VIM_WITH_MOD(KC_LSFT, X_LSHIFT, MAC_SEL_TO_START_OF_WORD(VIM_REPEAT));

#define VIM_SEL_TO_END_OF_WORD_FROM_CURSOR                                     \
  VIM_WITH_MOD(KC_LSFT, X_LSHIFT, MAC_SEL_TO_END_OF_WORD(VIM_REPEAT));

#define VIM_MOV_TO_START_OF_WORD_FROM_CURSOR                                   \
  MAC_MOV_TO_START_OF_WORD(VIM_REPEAT)                                         \
  CLEAR_VIM_REPEAT_AND_RETURN

#define VIM_MOV_TO_END_OF_WORD_FROM_CURSOR                                     \
  MAC_MOV_TO_END_OF_WORD(VIM_REPEAT)                                           \
  CLEAR_VIM_REPEAT_AND_RETURN

#define VIM_WITH_MOD(KC, X_KC, CODE)                                           \
  if (get_mods() & MOD_BIT(KC)) {                                              \
    SEND_STRING(SS_UP(X_KC));                                                  \
    CODE;                                                                      \
    SEND_STRING(SS_DOWN(X_KC));                                                \
    CLEAR_VIM_REPEAT_AND_RETURN;                                               \
  }

#define MAC_CUT_NEXT_CHAR_FROM_CURSOR(N)                                       \
  MAC_SEL_NEXT_CHAR_FROM_CURSOR(N)                                             \
  MAC_CUT

#define MAC_CUT_PREV_CHAR_FROM_CURSOR(N)                                       \
  MAC_SEL_PREV_CHAR_FROM_CURSOR(N)                                             \
  MAC_CUT

#define MAC_CUT_TO_START_OF_WORD_FROM_CURSOR(N)                                \
  MAC_SEL_TO_START_OF_WORD(N)                                                  \
  MAC_CUT

#define MAC_CUT_TO_END_OF_WORD_FROM_CURSOR(N)                                  \
  MAC_SEL_TO_END_OF_WORD(N)                                                    \
  MAC_CUT

#define MAC_CUT_LINE(N)                                                        \
  MAC_SEL_LINE(N)                                                              \
  SEND_STRING(SS_TAP_MAC_CUT);

#define MAC_SEL_NEXT_CHAR_FROM_CURSOR(N)                                       \
  REPEAT_SEND_STRING(N, SS_TAP_SFT_RIGHT);
#define MAC_SEL_PREV_CHAR_FROM_CURSOR(N) REPEAT_SEND_STRING(N, SS_TAP_SFT_LEFT);

#define MAC_SEL_LINE(N)                                                        \
  MAC_MOV_TO_START_OF_LINE                                                     \
  MAC_SEL_TO_END_OF_LINE                                                       \
  REPEAT_SEND_STRING(N - 1, SS_TAP_SFT_DOWN);                                  \
  MAC_SEL_TO_END_OF_LINE

#define MAC_CUT_WORD_ON_CURSOR(N)                                              \
  MAC_MOV_TO_END_OF_WORD(N)                                                    \
  MAC_SEL_TO_START_OF_WORD(N)                                                  \
  MAC_CUT

#define MAC_MOV_TO_START_OF_LINE SEND_STRING(SS_TAP_GUI_LEFT);
#define MAC_MOV_TO_END_OF_LINE SEND_STRING(SS_TAP_GUI_RIGHT);

#define MAC_SEL_TO_START_OF_LINE SEND_STRING(SS_TAP_GUI_SFT_LEFT);
#define MAC_SEL_TO_END_OF_LINE SEND_STRING(SS_TAP_GUI_SFT_RIGHT);

#define MAC_MOV_TO_START_OF_WORD(N) REPEAT_SEND_STRING(N, SS_TAP_ALT_LEFT);
#define MAC_MOV_TO_END_OF_WORD(N) REPEAT_SEND_STRING(N, SS_TAP_ALT_RIGHT);

#define MAC_SEL_TO_START_OF_WORD(N) REPEAT_SEND_STRING(N, SS_TAP_ALT_SFT_LEFT);
#define MAC_SEL_TO_END_OF_WORD(N) REPEAT_SEND_STRING(N, SS_TAP_ALT_SFT_RIGHT);

#define REPEAT_SEND_STRING_AND_MAC_CUT(N, SS_STRING)                           \
  REPEAT_SEND_STRING(N, SS_STRING);                                            \
  MAC_CUT;

#define REPEAT_SEND_STRING(N, SS_STRING)                                       \
  for (uint16_t i = 0; i < (N); i++) {                                         \
    SEND_STRING(SS_STRING);                                                    \
  }

#define MAC_CUT SEND_STRING(SS_TAP_MAC_CUT);

#define CLEAR_VIM_REPEAT_AND_RETURN                                            \
  vim_repeat = 0;                                                              \
  return false;

static uint16_t vim_repeat = 0;
#define VIM_REPEAT (vim_repeat > 0 ? vim_repeat : 1)

bool process_macvim(uint16_t keycode, keyrecord_t *record, bool with_repeat) {
  if (record->event.pressed) {
    if (with_repeat) {
      if (keycode >= KC_1 && keycode <= KC_0) {
        uint16_t repeat = (10 - (KC_0 - keycode)) % 10;
        if (vim_repeat > 0) {
          vim_repeat = vim_repeat * 10 + repeat;
        } else {
          vim_repeat = repeat;
        }
        return false;
      }

      switch (keycode) {
      case VIM_W:
        VIM_SEL_TO_END_OF_WORD_FROM_CURSOR;
        VIM_MOV_TO_END_OF_WORD_FROM_CURSOR;
      case VIM_B:
        VIM_SEL_TO_START_OF_WORD_FROM_CURSOR;
        VIM_CUT_TO_START_OF_WORD_FROM_CURSOR;
        VIM_MOV_TO_START_OF_WORD_FROM_CURSOR;
      case VIM_C:
        VIM_CUT_WORD_ON_CURSOR;
      case VIM_D:
        VIM_CUT_TO_END_OF_WORD_FROM_CURSOR;
      case VIM_V:
        VIM_SEL_LINE; // this will return first if SHIFT mod is enable.
        VIM_CUT_LINE; // if there is no mod, it'll default to cutting the line.
      case VIM_DOLLAR:
        VIM_SEL_TO_END_OF_LINE;
        VIM_CUT_TO_END_OF_LINE
      case VIM_0:
        VIM_SEL_TO_START_OF_LINE;
        VIM_CUT_TO_START_OF_LINE;
      case VIM_X:
        VIM_CUT_NEXT_CHAR_FROM_CURSOR;
      case VIM_ESC:
        CLEAR_VIM_REPEAT_AND_RETURN;
      }
    }
  }
  return true;
}
