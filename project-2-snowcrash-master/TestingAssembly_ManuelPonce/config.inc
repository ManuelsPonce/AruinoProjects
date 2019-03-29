#include <avr/io.h>

#define LED_PIN     3
#define LED_PORT    _(PORTB)
#define LED_DIR     _(DDRB)
#define JOY_X_PIN   1
#define JOY_PORT  _(PORTC)
#define JOY_DIR   _(DDRC)
#define JOY_Y_PIN   2

//Include this line to avoid SFR_REG issues
#define _(s)    _SFR_IO_ADDR(s)
