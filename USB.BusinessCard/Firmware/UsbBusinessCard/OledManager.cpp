#include "OledManager.h"

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define OLED_I2C_ADDR 0x3C // Address 0x3C for 128x32

OledManager::OledManager(Adafruit_SSD1306 * display) {
	this->_display = display;
	
}

OledManager::~OledManager() {

}

void OledManager::Initialize() {
	
	// SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
	if (!this->_display->begin(SSD1306_SWITCHCAPVCC, OLED_I2C_ADDR)) { // Address 0x3C for 128x32

	}
}

void OledManager::Clear() {

	this->_display->clearDisplay();
}

void OledManager::Refresh() {

	this->_display->display();
}

void OledManager::DrawRect(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color /* = WHITE*/) {

	this->_display->drawRect(x, y, w, h, color);
}
