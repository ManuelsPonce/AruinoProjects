#include "config.inc"
    .global    setup
    .section    .text
setup:
    sbi    LED_DIR, LED_PIN
    cbi    LED_PORT, LED_PIN
    ret
