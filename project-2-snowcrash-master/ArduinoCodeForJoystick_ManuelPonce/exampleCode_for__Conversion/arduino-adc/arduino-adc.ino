int potPin = 0;    // select the input pin for the potentiometer
int ledPin = 13;   // select the pin for the LED
int val = 0;       // variable to store the value coming from the sensor
#define sbi(sfr, bit) (_SFR_BYTE(sfr) |= _BV(bit))
uint8_t analog_reference = DEFAULT;

void setup() {
  pinMode(ledPin, OUTPUT);  // declare the ledPin as an OUTPUT
}

int MyanalogRead(uint8_t pin) {
  uint8_t low, high;
  ADMUX = (analog_reference << 6) | (pin & 0x07);
  
  // start the conversion
  sbi(ADCSRA, ADSC);

  while (bit_is_set(ADCSRA, ADSC));
  low  = ADCL;
  high = ADCH;
  return (high << 8) | low;
}

void loop() {
  val = MyanalogRead(potPin);    // read the value from the sensor
  digitalWrite(ledPin, HIGH);  // turn the ledPin on
  delay(val);                  // stop the program for some time
  digitalWrite(ledPin, LOW);   // turn the ledPin off
  delay(val);                  // stop the program for some time
}
 

