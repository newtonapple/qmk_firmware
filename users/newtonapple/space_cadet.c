#include "space_cadet.h"

void space_cadet(uint16_t kc_mod, const char *str, bool pressed, uint16_t *timer, uint16_t timeout) {
    if (pressed) {
        (*timer) = timer_read();
        register_code16(kc_mod);
    } else {
        unregister_code16(kc_mod);
        if (timer_elapsed(*timer) < timeout) {
            send_string(str);
        }
    }
}

void space_cadet_layer(uint8_t layer, const char *str, bool pressed, uint16_t *timer, uint16_t timeout) {
    if (pressed) {
        (*timer) = timer_read();
        layer_on(layer);
    } else {
        layer_off(layer);
        if (timer_elapsed(*timer) < timeout) {
            send_string(str);
        }
    }
}
