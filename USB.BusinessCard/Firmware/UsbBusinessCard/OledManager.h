// OledManager.h

#ifndef _OLEDMANAGER_h
#define _OLEDMANAGER_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

class OledManager {
private:
	Adafruit_SSD1306 * _display;
protected:
public:
	OledManager(Adafruit_SSD1306 * display);
	~OledManager();
	void Initialize();
	void Clear();
	void Refresh();
	void DrawRect(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color = WHITE);
};

#endif

