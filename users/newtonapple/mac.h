#pragma once

#include "quantum.h"

// Custom Mac keycodes
#define ALT_RGHT LALT(KC_RGHT)
#define ALT_LEFT LALT(KC_LEFT)
#define CMD_RGHT LCMD(KC_RGHT)
#define CMD_LEFT LCMD(KC_LEFT)

#define SEL_ALL LCMD(KC_A)
#define COPY LCMD(KC_C)
#define CUT LCMD(KC_X)
#define PASTE LCMD(KC_V)
#define UNDO LCMD(KC_Z)
#define REDO SCMD(KC_Z)

#define ZOOM_IN LCMD(KC_EQL)
#define ZOOM_OUT LCMD(KC_MIN)
#define ZOOM_RESET LCMD(KC_0)

#define CLOSE LCMD(KC_W)
#define QUIT LCMD(KC_Q)
#define SAVE LCMD(KC_S)

#define PREV_TAB SCMD(KC_LBRC)
#define NEXT_TAB SCMD(KC_RBRC)
#define INDENT LCMD(KC_RBRC)
#define UNINDENT LCMD(KC_LBRC)

#define SNAP_LEFT LCMD(LALT(LCTL(KC_H)))
#define SNAP_RGHT LCMD(LALT(LCTL(KC_L)))
#define SNAP_UP LCMD(LALT(LCTL(KC_K)))
#define SNAP_DOWN LCMD(LALT(LCTL(KC_J)))
#define SNAP_CENTER LCMD(LALT(LCTL(KC_C)))
#define SNAP_MAX LCMD(LALT(LCTL(KC_M)))

#define DISP_OFF LALT(CMD_POWER)
#define SLEEP LCTL(S_POWER)

#define CMD_POWER LCMD(KC_POWER)
#define S_POWER S(KC_POWER)

// Custom SS_TAPs
#define SS_TAP_LEFT SS_TAP(X_LEFT)
#define SS_TAP_RIGHT SS_TAP(X_RIGHT)
#define SS_TAP_UP SS_TAP(X_UP)
#define SS_TAP_DOWN SS_TAP(X_DOWN)

#define SS_TAP_ALT_LEFT SS_LALT(SS_TAP_LEFT)
#define SS_TAP_ALT_RIGHT SS_LALT(SS_TAP_RIGHT)
#define SS_TAP_ALT_UP SS_LALT(SS_TAP_UP)
#define SS_TAP_ALT_DOWN SS_LALT(SS_TAP_DOWN)

#define SS_TAP_ALT_SFT_LEFT SS_LSFT(SS_TAP_ALT_LEFT)
#define SS_TAP_ALT_SFT_RIGHT SS_LSFT(SS_TAP_ALT_RIGHT)

#define SS_TAP_GUI_LEFT SS_LGUI(SS_TAP_LEFT)
#define SS_TAP_GUI_RIGHT SS_LGUI(SS_TAP_RIGHT)

#define SS_TAP_GUI_SFT_LEFT SS_LSFT(SS_TAP_GUI_LEFT)
#define SS_TAP_GUI_SFT_RIGHT SS_LSFT(SS_TAP_GUI_RIGHT)

#define SS_TAP_SFT_LEFT SS_LSFT(SS_TAP_LEFT)
#define SS_TAP_SFT_RIGHT SS_LSFT(SS_TAP_RIGHT)
#define SS_TAP_SFT_UP SS_LSFT(SS_TAP_UP)
#define SS_TAP_SFT_DOWN SS_LSFT(SS_TAP_DOWN)

#define SS_TAP_MAC_CUT SS_LGUI("x")

// Macros for repeatedly sending strings
#define REPEAT_SEND_STRING(N, SS_STRING)                                       \
  for (uint16_t i = 0; i < (N); i++) {                                         \
    SEND_STRING(SS_STRING);                                                    \
  }

#define REPEAT_SEND_STRING_AND_MAC_CUT(N, SS_STRING)                           \
  REPEAT_SEND_STRING(N, SS_STRING);                                            \
  MAC_CUT();

// Macros for various Mac copy-cut-paste actions
#define MAC_CUT() SEND_STRING(SS_TAP_MAC_CUT);

#define MAC_CUT_NEXT_CHAR(N)                                       \
  MAC_SEL_NEXT_CHAR(N)                                                         \
  MAC_CUT()
#define MAC_CUT_PREV_CHAR(N)                                       \
  MAC_SEL_PREV_CHAR(N)                                                         \
  MAC_CUT()

#define MAC_CUT_WORD_ON_CURSOR(N)                                              \
  MAC_MOV_TO_END_OF_WORD(N)                                                    \
  MAC_SEL_TO_START_OF_WORD(N)                                                  \
  MAC_CUT()
#define MAC_CUT_TO_START_OF_WORD_FROM_CURSOR(N)                                \
  MAC_SEL_TO_START_OF_WORD(N)                                                  \
  MAC_CUT()
#define MAC_CUT_TO_END_OF_WORD_FROM_CURSOR(N)                                  \
  MAC_SEL_TO_END_OF_WORD(N)                                                    \
  MAC_CUT()

#define MAC_CUT_LINE(N)                                                        \
  MAC_SEL_LINE(N)                                                              \
  SEND_STRING(SS_TAP_MAC_CUT);

#define MAC_SEL_NEXT_CHAR(N) REPEAT_SEND_STRING(N, SS_TAP_SFT_RIGHT);
#define MAC_SEL_PREV_CHAR(N) REPEAT_SEND_STRING(N, SS_TAP_SFT_LEFT);

#define MAC_SEL_TO_START_OF_WORD(N) REPEAT_SEND_STRING(N, SS_TAP_ALT_SFT_LEFT);
#define MAC_SEL_TO_END_OF_WORD(N) REPEAT_SEND_STRING(N, SS_TAP_ALT_SFT_RIGHT);

#define MAC_SEL_TO_NEXT_LINE(N) REPEAT_SEND_STRING(N, SS_TAP_SFT_DOWN);
#define MAC_SEL_TO_PREV_LINE(N) REPEAT_SEND_STRING(N, SS_TAP_SFT_UP);
#define MAC_SEL_TO_START_OF_LINE() SEND_STRING(SS_TAP_GUI_SFT_LEFT);
#define MAC_SEL_TO_END_OF_LINE() SEND_STRING(SS_TAP_GUI_SFT_RIGHT);
#define MAC_SEL_LINE(N)                                                        \
  MAC_MOV_TO_START_OF_LINE()                                                   \
  MAC_SEL_TO_END_OF_LINE()                                                     \
  REPEAT_SEND_STRING(N - 1, SS_TAP_SFT_DOWN);                                  \
  MAC_SEL_TO_END_OF_LINE()

#define MAC_MOV_TO_NEXT_CHAR(N) REPEAT_SEND_STRING(N, SS_TAP_RIGHT);
#define MAC_MOV_TO_PREV_CHAR(N) REPEAT_SEND_STRING(N, SS_TAP_LEFT);

#define MAC_MOV_TO_START_OF_WORD(N) REPEAT_SEND_STRING(N, SS_TAP_ALT_LEFT);
#define MAC_MOV_TO_END_OF_WORD(N) REPEAT_SEND_STRING(N, SS_TAP_ALT_RIGHT);

#define MAC_MOV_TO_NEXT_LINE(N) REPEAT_SEND_STRING(N, SS_TAP_DOWN);
#define MAC_MOV_TO_PREV_LINE(N) REPEAT_SEND_STRING(N, SS_TAP_UP);
#define MAC_MOV_TO_START_OF_LINE() SEND_STRING(SS_TAP_GUI_LEFT);
#define MAC_MOV_TO_END_OF_LINE() SEND_STRING(SS_TAP_GUI_RIGHT);

#define MAC_MOV_LINE_UP(N) REPEAT_SEND_STRING(N, SS_TAP_ALT_UP);
#define MAC_MOV_LINE_DOWN(N) REPEAT_SEND_STRING(N, SS_TAP_ALT_DOWN);
