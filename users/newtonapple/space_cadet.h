#pragma once
#include "quantum.h"

/*
 * To use SPACE_CADET* macros, you must define the static timer variable:
 *    static uint16_t space_cadet_timer;
 *
 * The SPACE_CADET* macros assume only one key is pressed at a time,
 * i.e. no mixing modifier or layer keys are held at the same time.  It also
 * uses `TAPPING_TERM` as its default timeout value.
 *
 * You can use `space_cadet` & `space_cadet_layer` for custom timers & timouts.
 */

#define SPACE_CADET(keycode, kc_custom, kc_mod, str, pressed)                                   \
    if (keycode == kc_custom) {                                                                 \
        space_cadet(kc_mod, str, pressed, &space_cadet_timer, TAPPING_TERM + CUSTOM_TAP_DELTA); \
        return false;                                                                           \
    };

#define SPACE_CADET_LAYER(keycode, kc_custom, layer, str, pressed)                                   \
    if (keycode == kc_custom) {                                                                      \
        space_cadet_layer(layer, str, pressed, &space_cadet_timer, TAPPING_TERM + CUSTOM_TAP_DELTA); \
        return false;                                                                                \
    };

void space_cadet(uint16_t kc_mod, const char *str, bool pressed, uint16_t *timer, uint16_t timeout);
void space_cadet_layer(uint8_t layer, const char *str, bool pressed, uint16_t *timer, uint16_t timeout);
