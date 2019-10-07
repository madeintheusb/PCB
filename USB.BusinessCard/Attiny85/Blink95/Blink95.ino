/*
  https://riteshkhanna.com/2016/04/20/programming-attiny45attiny85-with-a-usbasp-avr-programmer/

              |----------|
  RESET - P5  | 1      8 | VCC 5V
  D- P3 A3    | 2      7 | P2 CLK A1
  D+ P4 A2    | 3      6 | P1 MISO PWM
  GND         | 4      5 | P0 MOSI PWM AREF
              |----------|
 */

void setup() {  
  //The 8-pin ATTinys (25/45/85) all have 5 usable digital output pins 0-4
  pinMode(1, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(200);              // wait for a second
  digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW
  delay(200);              // wait for a second
}
