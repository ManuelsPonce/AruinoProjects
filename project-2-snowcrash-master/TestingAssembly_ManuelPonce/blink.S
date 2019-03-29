#include "config.inc"

    .global    blink
    .extern    delay
    .section    .text
blink:
    //Toggle LED
    in     r24, LED_PORT
    ldi    r25, (1 << LED_PIN)
    eor    r24, r25
    out    LED_PORT, r24
    rcall  delay
    ret
