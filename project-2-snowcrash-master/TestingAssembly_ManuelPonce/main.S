; blink - blink an LED on PB0 on and off at a .5 second rate

#include "config.inc"

    .global    main
    .extern    setup
    .extern    blink

    .section    .text
main:
        rcall    setup
		//toggle Joystick
1:      in       r16, JOY_PORT
        ldi      r17, (1<<JOY_X_PIN)
        eor      r16, r17
        rcall    blink
        rjmp     1b
