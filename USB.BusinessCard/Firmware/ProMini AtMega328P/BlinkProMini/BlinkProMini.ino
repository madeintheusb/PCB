/*
  Usp program USBASP
  And MadeInTheUSB.net extension to program Arduino Pro Mini
  AtMega328P 8Mhz

avrdude: error: could not find USB device with vid=0x16c0 pid=0x5dc vendor='www.fischl.de' product='USBasp'
https://rlogiacco.wordpress.com/2016/09/01/usbasp-windows-10/
https://zadig.akeo.ie/

downloaded USBasp-win-driver-x86-x64-v3.0.7.zip from 
https://protostack.com.au/shop/accessories/usbasp-avr-programmer/
THIS WORKED
 */

void setup() {  
  
  pinMode(13, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);              // wait for a second
  digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW
  delay(500);              // wait for a second
}
