
#include "mac.h"

void repeat_send_string(uint16_t n, const char *str) {
  for (uint16_t i = 0; i < (n); i++) {
    send_string_P(str);
  }
};


void repeat_send_string_and_cut(uint16_t n, const char *str) {
  repeat_send_string(n, str);
  MAC_CUT();
}
