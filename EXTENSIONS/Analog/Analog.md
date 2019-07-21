ANALOG LEARNING
===============

## Velleman flashing led schematic

http://www.talkingelectronics.com/projects/200TrCcts/1-100TransistorCircuits.pdf

## One LED Blink PCB

# Description
	http://www.talkingelectronics.com/projects/200TrCcts/1-100TransistorCircuits.pdf
	See LED FLASHER

- Transistor 
	1 NPN 2N3904
		https://www.sparkfun.com/datasheets/Components/2N3904.pdf

	2 PNP 2N3906
		https://www.sparkfun.com/datasheets/Components/2N3906.pdf

- Capacitor
	EAGLE: Package: C025-030X050 - grid 2.5 mm, outline 3 x 5 mm
- Resistor 0207/10
	- 1 22 Ohm
	- 1 10k/16k Ohm
	- 1 3 or 4 M Ohm
	- 1 LED 5m
	- 1 USB Female adapter
- USB Male Type A Port Right Angle 4-Pin DIP Jack Socket Connector
	http://www.mouser.com/ds/2/418/NG_CD_1734028_C-687243.pdf
	
	- Resistor 16k Combination 
		- 1 22 Ohm absolutely required, cannot be changed
		- 1 M Ohm
		- 16k Ohm
	- LED Bi Color Green/Red
		- 1 22 Ohm absolutely required, cannot be changed
		- 1 M Ohm
		- 16k Ohm
		- Connect the Green as the regular LED
		- Connect the red to power using a 2k Resistor

	
# Eagle Info
- Pad WIREPAD2,54/1,1

- Button 
        EAGLE cad package for these in switch-omron:10XX :B3F-10XX
        https://www.adafruit.com/products/367
- Diode DO-1N4148 - Through Hole Small Current Diode

# Resistor

- Red 2k
- Green 100Ohm
- Yellow 470Ohm
- Blue 1k

2 led blinker with 2 pnp r1=50k r2=470Ohm
http://www.instructables.com/id/Simple-Blinking-LED-Circuit/?ALLSTEPS

