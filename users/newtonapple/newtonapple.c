#include "newtonapple.h"

void space_cadet(uint16_t kc_mod, const char *str, bool pressed,
                 uint16_t *timer, uint16_t timeout) {
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

void space_cadet_layer(uint8_t layer, const char *str, bool pressed,
                       uint16_t *timer, uint16_t timeout) {
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


#ifdef RGBLIGHT_ENABLE
extern rgblight_config_t rgblight_config;

void rgb_matrix_scan(void) {
  static bool rgb_enable;
  uint8_t layer = biton32(layer_state);
  if (layer == _LED) return;
  if (layer != _QWERTY) {
    rgb_enable = true;
    rgblight_enable_noeeprom();
    rgblight_mode_noeeprom(1);
  }
  switch (layer) {
  case _QWERTY:
    rgblight_config.raw = eeconfig_read_rgblight();
    if (rgblight_config.enable) {
      rgb_enable = true;
      rgblight_enable_noeeprom();
      rgblight_mode_noeeprom(rgblight_config.mode);
      rgblight_sethsv_noeeprom(rgblight_config.hue, rgblight_config.sat, rgblight_config.val);
    } else {
      if (rgb_enable) {
        rgb_enable = false;
        rgblight_disable_noeeprom();
      }
    }
    break;
  case _NUM:
    rgblight_sethsv_noeeprom_azure();
    break;
  case _SYM:
    rgblight_sethsv_noeeprom_yellow();
    break;
  case _MACVIM:
    rgblight_sethsv_noeeprom_green();
    break;
  case _VIMNUM:
    rgblight_sethsv_noeeprom_springgreen();
    break;
  case _MOUSE:
    rgblight_sethsv_noeeprom_teal();
    break;
  case _CAP:
    rgblight_sethsv_noeeprom_orange();
    break;
  }
}
#endif
