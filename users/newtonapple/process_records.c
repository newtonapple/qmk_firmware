#include "process_records.h"

#define IS_LAYER_ON_STATE(layer, state) (state & (1UL << (layer)))

__attribute__((weak))
bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
  return true;
}
__attribute__((weak))
uint32_t layer_state_set_keymap(uint32_t state) {
  return state;
}

uint32_t layer_state_set_user(uint32_t state) {
#ifdef ENABLE_MACVIM
  if (!(IS_LAYER_ON_STATE(_MACVIM, state) ||
        IS_LAYER_ON_STATE(_VIMNUM, state))) {
    reset_vim_states();
  }
#endif
  return layer_state_set_keymap(state);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
#ifdef ENABLE_SPACE_CADET
  static uint16_t space_cadet_timer;
  SPACE_CADET_LAYER(keycode, MACVIM_SQUOT, _MACVIM, "\"",
                    record->event.pressed);
  SPACE_CADET_LAYER(keycode, SYM_SMINS, _SYM, "_", record->event.pressed);
  SPACE_CADET_LAYER(keycode, ADJ_SBSLS, _ADJUST, "|", record->event.pressed);
  SPACE_CADET(keycode, CRTL_SLBRC, KC_LCTRL, "{", record->event.pressed);
  SPACE_CADET(keycode, CRTL_SRBRC, KC_RCTRL, "}", record->event.pressed);
#endif
  return (process_macvim(keycode, record, IS_LAYER_ON(_MACVIM)) &&
          process_record_keymap(keycode, record));
}

