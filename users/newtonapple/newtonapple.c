#include "newtonapple.h"

// #ifdef RGBLIGHT_ENABLE
// #ifndef RGBLIGHT_LAYER_INDICATOR_DISABLE
// extern rgblight_config_t rgblight_config;

// void rgb_matrix_scan(void) {
//   static bool rgb_enable;
//   uint8_t layer = biton32(layer_state);
//   if (layer == _LED)
//     return;
//   if (layer != _QWERTY) {
//     rgb_enable = true;
//     rgblight_enable_noeeprom();
//     rgblight_mode_noeeprom(1);
//   }
//   switch (layer) {
//   case _QWERTY:
//     rgblight_config.raw = eeconfig_read_rgblight();
//     if (rgblight_config.enable) {
//       rgb_enable = true;
//       rgblight_enable_noeeprom();
//       rgblight_mode_noeeprom(rgblight_config.mode);
//       rgblight_sethsv_noeeprom(rgblight_config.hue, rgblight_config.sat,
//                                rgblight_config.val);
//     } else {
//       if (rgb_enable) {
//         rgb_enable = false;
//         rgblight_disable_noeeprom();
//       }
//     }
//     break;
//   case _NUM:
//     rgblight_sethsv_noeeprom_azure();
//     break;
//   case _SYM:
//     rgblight_sethsv_noeeprom_yellow();
//     break;
//   case _MACVIM:
//     rgblight_sethsv_noeeprom_green();
//     break;
//   case _VIMNUM:
//     rgblight_sethsv_noeeprom_springgreen();
//     break;
//   case _MOUSE:
//     rgblight_sethsv_noeeprom_teal();
//     break;
//   case _CAP:
//     rgblight_sethsv_noeeprom_orange();
//     break;
//   }
// }
// #endif
// #endif
