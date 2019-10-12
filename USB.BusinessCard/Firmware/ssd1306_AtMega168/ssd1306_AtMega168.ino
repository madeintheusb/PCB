/* Tiny Function Plotter (SSD1306 version) - see http://www.technoblogy.com/show?2CFT

   David Johnson-Davies - www.technoblogy.com - 14th October 2018
   ATtiny85 @ 8 MHz (internal oscillator; BOD disabled)
   
   CC BY 4.0
   Licensed under a Creative Commons Attribution 4.0 International license: 
   http://creativecommons.org/licenses/by/4.0/
*/

#include <Wire.h>

// Constants
int const address = 61;
int const commands = 0x00;
int const onecommand = 0x80;
int const data = 0x40;
int const onedata = 0xC0;

// OLED display **********************************************

// Initialisation sequence for OLED module

int const InitLen = 10;
const uint8_t Init[InitLen] PROGMEM = {
  0x8D, // Charge pump
  0x14,
  0x20, // Memory mode
  0x01, // Vertical addressing
  0xA1, // Flip horizontally
  0x81, // Set contrast
  0xCF, // brighter
  0xDB, // Set vcom detect
  0x40, // brighter
  0xAF  // Display on
};

void InitDisplay () {
  Wire.beginTransmission(address);
  Wire.write(commands);
  for (uint8_t i=0; i<InitLen; i++) Wire.write(pgm_read_byte(&Init[i]));
  Wire.endTransmission();
}

// Plot point (SSD1306): x (0 to 127), y (0 to 63), mode (0 = point, 1 = histogram)
void PlotPoint (int x, int y, int mode) {
  Wire.beginTransmission(address);
  Wire.write(commands);
  Wire.write(0x21); Wire.write(x); Wire.write(x);  // Column range
  Wire.write(0x22); Wire.write(0); Wire.write(7);  // Page range
  Wire.endTransmission();
  Wire.beginTransmission(address);
  Wire.write(data);
  for (int i=0; i<8; i++) {
    if (y > 7) Wire.write(- mode);
    else if (y < 0) Wire.write(0);
    else Wire.write((1<<y) - mode);
    y = y - 8;
  }
  Wire.endTransmission();
}

void ClearDisplay () {
  for (int x=0; x<128; x++) PlotPoint(x, 0, 1);
}

// Setup **********************************************

void setup() {
  Wire.begin();
  InitDisplay();
}

// Gaussian approximation
int e (int x, int f, int m) {
  return (f * 256) / (256 + ((x - m) * (x - m)));
}

// Demo plot
void loop () {
  for (int x=0; x<128; x++) {
    int y = e(x, 40, 24) + e(x, 68, 64) + e(x, 30, 104) - 14;
    PlotPoint(x, y, 0);
  }
  for (;;);
}
