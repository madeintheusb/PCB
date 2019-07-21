# Nusbio+

Nusbio+ 
- 8 gpios 3,4,5,8-15
- I2C Bus
- SPI Bus

Enclosure.Front.I2C.SPI.8GPIO.8ADC

## Overview
Design a from panel for Nusbio that offer:
* 1 SPI Bus (gpio 0 CLOCK, gpio 1 MOSI, gpio 2 MISO)
	- Gpio 3 is reserved CS for the ADC MCP3008
	- Gpio 4, 5 are available for CS or anything
* 1 I2C Bus (gpio 6 SCL, gpio 7 SDA)
* 8 extended Gpio via the MCP23008 (I2C,SOIC)
	EGALE: Device MCP23008/SO (MCP23008), Package:SO18W, Library:Adafruit
* 8 ADC via the MCP3008 (SOIC) [ISSUE THIS IS SPI]
	EAGLE: Device MCP3008SL (MCP3008), Package SO16, Library:MCP3008

Total Gpio 10 : gpio 4, 5 and 8, 9, 10, 11, 12, 13, 14, 15

Fix SPI Library to support extended gpio as SPI Chip Select

## Price
Nusbio+ comes only with Enclosure -- $30

## Front Panel

GPIO 8		 9			 10			 11		 12		 13		 14		 15		VCC		GND 	  POWER
	[0]		[1]			[2]			[3]		[4]		[5]		[6]		[7]		[8]		[9]	 	[PWR-LED]

SPI CLK	    MOSI		MISO		 3	     4	     5	I2C SCL     SDA		VCC		GND
	[0]		[1]			[2]			[3]		[4]		[5]		[6]		[7]		[8]		[9]
 	 x       x           x           x       x       x       x       x     	 x		 x

ADC  0 		 1			 2 			 3 		 4		 5 		 6		 7 		VCC		GND
	[0]		[1]			[2]			[3]		[4]		[5]		[6]		[7]		[8]		[9]

