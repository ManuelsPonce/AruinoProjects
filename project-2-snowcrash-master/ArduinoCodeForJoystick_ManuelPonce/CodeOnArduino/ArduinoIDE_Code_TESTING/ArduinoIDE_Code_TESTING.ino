
#define sbi(sfr, bit) (_SFR_BYTE(sfr) |= _BV(bit))
uint8_t analog_reference = DEFAULT;

 int ledPin = 11;
 int joyPinX = 0;                 // slider variable connecetd to analog pin 0
 int joyPinY = 1;                 // slider variable connecetd to analog pin 1
 int valueX = 0;                  // variable to read the value from the analog pin 0
 int valueY = 0;                  // variable to read the value from the analog pin 1

 void setup() {
  pinMode(ledPin, OUTPUT);              // initializes digital pins 0 to 7 as outputs
  Serial.begin(9600);
 }

//Reading the analog input from joystick.
 int MyanalogRead(uint8_t pin){
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
  // reads the value of the variable resistor 
  valueX = MyanalogRead(joyPinX);   
  // this small pause is needed between reading
  // analog pins, otherwise we get the same value twice
  delay(100);             
  // reads the value of the variable resistor 
  valueY = MyanalogRead(joyPinY);   

  digitalWrite(ledPin, HIGH);           
  delay(valueX);
  digitalWrite(ledPin, LOW);
  delay(valueY);
  Serial.print("Joystick Value: ");
  Serial.print(MyanalogRead(valueX));
  Serial.println(MyanalogRead(valueY));
 }
