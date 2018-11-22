
#include "mac.h"

void repeat_send_string(uint16_t n, const char *str) {
  for (uint16_t i = 0; i < (n); i++) {
    send_string_P(str);
  }
};
