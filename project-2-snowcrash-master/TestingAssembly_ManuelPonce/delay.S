#include "config.inc"
    .global     delay
    .section    .text
delay:

ldi r24, r16    ;outer loop
3: ldi r25, 255 ;middle loop
2: ldi r26, 255 ;inner loop
1: dec r26
brne 1b
dec r25
brne 2b
dec r24
brne 3b
ret
