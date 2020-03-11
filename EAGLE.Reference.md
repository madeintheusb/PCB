http://www.elecrom.com/eagle-library-list-of-most-commonly-used-electronics-components/

SEED PCB http://www.seeedstudio.com/blog/2016/03/01/guideline-for-seeed-is-back-in-march/

EAGLE REFERENCE
Thru Hole
	- Resistor 0207/10
	- 10 Pin header adafruit => PINHD-1X10, PINHD-1X8, PINHD-1X4
	- LED LED5MM (LED) adadruit
	- Crystal
		Thru hole HC49US-12.000MABJ-UB
		$0.3 http://www.mouser.com/Search/ProductDetail.aspx?R=HC49US-12.000MABJ-UBvirtualkey69500000virtualkey695-HC49US-12-U
		EAGLE: Device CRYSTALHC49U-V, Package:HC49U-V Adafruit
	- Button/Switch
		5mx5m Device:10-XX library:switch-omron Package:B3F-10XX
		Pin 1 and 2 are always connnected
		Pin 3 and 4 are always connnected

		So wiring can
		1 -> 3 or 1 -> 4
		2 -> 3 or 2 -> 4
		
    - Sliding Switch on/off 3 pin (NOT THRU HOLE)
        Mini slide switch switch 255SB 255SB http://sumo.ly/tStF

- Sliding Switch on/off 3 pin (THRU HOLE)  vertical SPDT slide switch 
        Package: EG1218, Device:EG1218S (EG1218), Library: adafruit
		http://www.ladyada.net/library/pcb/eaglelibrary.html
        
    - Tactile Switch on/off 2 pin		
        SMD Tactile switch 2 pins Package: TACTILE_SWITCH-SMD-RIGHT-ANGLE
        http://www.mouser.com/Search/ProductDetail.aspx?R=MJTP1250virtualkey64200000virtualkey642-MJTP1250
        
	- Chinese switch
			2pin DIP Tact Switch White Button Touch Micro Switch 3x6x5H
			Use 4 header standard

	Resistor Device:R-US_R1206 (R-US_)			package:R1206
		From Mouser 470Ohm 1K
		Ordered from china: 100o 470o 1k 4.7k 10k 100k

    9-Resistor Array (10 pin) for Back Panel - [NOT THRU HOLE]
        Device:M10SMD_MALE (M10), Package:1X10_SMD_MALE Library:SparkFun-Connectors
        
    9-Resistor Array (10 pin) THRU HOLE
    Device:4610x, Package:SPI10, Library:resistor-sip
    
7-SEGMENT-DISPLAY
    Common Cathode (GND) Device: 7-SEGMENT-DISPLAYPTH (7-SEGMENT-DISPLAY) Package: 7-SEGMENT-DISPLAY Library: SparkFun-Displays
    
2N3904

USB
	Female Type A -- Device:USB-A003, package: USB-A003

		USB Connector Right angle male -- DO NOT BUY FROM MOUSER -> BUY FROM ALIEXPRESS FOR $0.2
		http://www.mouser.com/search/refine.aspx?N=13833015
		http://www.mouser.com/Connectors/USB-Connectors/_/N-88hmf?P=1z0yxtiZ1yzudq8Z1ytavvh
		http://www.mouser.com/ProductDetail/TE-Connectivity/1-1734028-1/?qs=sGAEpiMZZMulM8LPOQ%252bykyMvpYkjjOa9KfhnSijHux8%3d

		EAGLE PART USB Type A Female with Soldering connector <<<
			Package: USB-FEMALE-A-PTH, Library:STUNTAZ, download from https://github.com/nall/EagleSupport

		EAGLE PART USB Type A Female with no soldering connector only holder
			Package:USB-A003, Library:con-yamaichi

	Male Type A -- USB MALE LIKE YUBIKEY
		Library:SparkFun-Connectors Device:, Package:USB-A-PCB, Value:USBPCB
		<part name="JP1" library="SparkFun-Connectors" deviceset="USB" device="PCB"/>

	Female Micro USB Type B SMD Weak Attachment		
		Device:USB-ABCONN-11794 (USB-AB), Package:USB-AB-MICRO-SMD_V03, Library:SparkFun-Connectors
		SPARKFUN: https://github.com/sparkfun/USB_microB_Breakout_Board
				  https://www.sparkfun.com/products/12035

	Female Micro USB Type B SMD Strong Attachment		
		https://github.com/adafruit/Adafruit-SMT-Breakout-PCBs
		Device: USBMICRO_20329 (USB), Package:4UCONN_20329, Library:microbuilder
		
	Male A to Female Micro B
		http://www.hobbytronics.co.uk/usb-microb-plug-diy
		Micro USB Data sheet: https://www.sparkfun.com/datasheets/Prototyping/Micro-USB.pdf


    DIP SWITCH
        Search for in eagles SW_DIP-4
        https://www.diymodules.org/eagle-show-library?type=std&file=special.lbr
        
SOLDER BRIDGE
	Search for solderjumper SOLDERJUMPERREFLOW
		Package: SOLDERJUMPER_REFLOW library microbuilder
	
 Fuse 500ma
	Device: PTCSMD (PTC), package:PTC-1206 Library:SparkFun-PowerIC, Search for:*PTCSMD*
	Resettable Fuse PTC Resettable Fuse. Spark Fun Electronics SKU : COM-08357
	https://www.sparkfun.com/products/8357
	https://www.sparkfun.com/datasheets/Components/RXE025_rev_H.pdf
	http://www.mouser.com/ProductDetail/Bel/0ZCJ0025FF2E/?qs=%2fha2pyFadugaoNql5zaJPt%252bsr4OA3GD2Eko9eRvbj3Ir9qXHDlLf0g%3d%3d
	530-0ZCJ0025FF2E

CAPACTIOR DIP THRU HOLE	
    Device: C-US025-030X050 (C-US)	Package:C025-030X050 Library:Adafruit

FERRITE BIDE
	Remove interference
	https://en.wikipedia.org/wiki/Ferrite_bead

HOLE WITH COPER
	Package:MOUNTINGHOLE_2.5_PLATED Library:microbuilder Value:MOUNTINGHOLE2.5

RESISTOR ARRAY THRU HOLE SOLDERED AS SMD
	M10SMD_MALE - (M10) - SparkFun-Connectors

LIPO PLUG FEMALE
	https://learn.sparkfun.com/tutorials/connector-basics
	JST PH 2-Pin SMT Right Angle Connector

	Wiring change from company to compan with chinese HobbyMart
	The male plug come as LEFT-VCC RIGHT-GND. But adafruit one are reverse
	HobbyMart:
	[_left:VCC_right:GND_] Male JST PH 2-Pin SMT Flat/Right Angle Connector
	[_left:GND_right:VCC_] Female JST PH 2-Pin SMT Flat/Right Angle Connector

	pin 1 GND
	pin 2 VCC

	Search Alliexpress JST PH 2-Pin

	EAGLE 
		M02-JST-2MM-SMT (M02), JST-2-SMD, SparkFun
		JST-2-SMD
		JST Right-Angle Connector - Through-Hole 2-Pin

	Thru hole -https://www.sparkfun.com/products/9749
	SMT - https://www.adafruit.com/product/1769
	
	
SMD
	- Crystal 12 Mhz
		SMD HCM49-12.000MABJ-UT 
		EAGLE:*CRYSTALHC49UP*, Package:HC49UP, Library:crystal
		USA: $0.5 http://www.mouser.com/Search/ProductDetail.aspx?R=HCM49-12.000MABJ-UTvirtualkey69500000virtualkey695-HCM49-12-U
		CHINA $0.1 http://www.aliexpress.com/item/Free-Shipping-49-s-passive-patch-crystals-49-SMD-crystal-false-patch-12-000-MHZ-12/32295267421.html
	- Capacitor 10uF 1206		
		Device:10UF-16V-10%(TANT), Package:EIA3216, Library:SparkFun-Capacitors
	- Capacitor 0.1uF 1206		
		Device:C-USC1206 (C-US), Package:C1206, Library:adafruit
	- LED 0805
		Device:LEDCHIPLED_0805 (LED), Package:CHIPLED_0805, Library:adafruit
	- LED 1206
		Device: LEDSMT1206 (LED) Package:1206, Library:adafruit
	- Resistor 0805
		Device:R-US_R0805 (R-US_), Package:R0805, Library:adafruit

	- Temp sensor TC77
		Package:SO-08 Device:TC77_SO08-5.0V-SO08 (TC77_SO08)

	- Transistor NPN
		- SN3904 200mA
			Eagle Device: MMBT3904LT1-NPN-SOT23-BEC (*-NPN-), Package:SOT23-BEC, Library: Transistor
		- S80550 1.5A
		- S9014 0.5A
		
		Device:2N3904 Library: Transistor Package TO92

	- Nano Pin
		PWM 3,5,6, 9,10,11
		NO PWM 2,5,6,7,13
		SPI CS:10, CLOCK:13, MOSI:11, MISO:12
		I2C SCK:A5 SDA:A4

	- Diode
		- Package SOD 123
		- Package: SMADIODE, Device: DIODESMA (DIODE), Library: adafruit

		MBRX120TPMSCT-ND
		http://www.mouser.com/Search/ProductDetail.aspx?R=MBRX120-TPvirtualkey54720000virtualkey833-MBRX120-TP

		- Thru Hole
		Package:DO35Z10, Device:1N821, Library:diode
			1N5817
				
		Eagle Adafruit\DIODE\DIODESOD-123
			SMADIODE - SMA Surface Mount Package 
			20V 1A Schottky Diode Digikey: 641-1014-6-ND
			DO-1N4148 - Through Hole Small Current Diode
			SOD-123 
			20V 1 A (.5mV Vf) Schottky Diode - Digikey: MBRX120TPMSCT-ND
			SOD-323 
			10V 570mA (.38mV Vf, 3ns) Schottky Diode - Digikey: ZLLS410CT-ND
			SOD-523 
			30V 30mA Schottky Diode (RB751S-40TE61) - Digikey: RB751S-40TE61CT-ND
			SOT23-R/W - SOT23 Package (R = Solder Paste/Reflow Ovens, W = Hand-Soldering) 
			BAT54Film 40V 300mA - Digikey: 497-7162-1-ND
			
	- 100K/10k Ohm DIP Mounted Potentiometer Pot Trimmer Resistor WH06-2
		Eagle Package: 
			SparkFun-ElectroMechanical - TRIM_POT_PTH - Various small potentiometers for "set-and-forget" applications
            TRIMPOTPTH (TRIMPOT) R? (TRIMPOT-1)
            TRIMPOTPTH (TRIMPOT)

    - EEPROM Parallel
        Device:28C16AP (28*16A), Package:DIL24-6, Library:microchip
        

SCREW
	Nusbio screw for pcb and enclosure

	100pcs/lot M3 Truss Head Self Tapping Screw Steel With Black M3*6/8/10/12/16/20/25/30
	M3 6mm

	https://www.aliexpress.com/item/100pcs-lot-M3-Truss-Head-Self-Tapping-Screw-Steel-With-Black-M3-6-8-10-12/32789825344.html?spm=2114.13010608.0.0.PkHeNw


https://github.com/adafruit/Adafruit-Circuit-Playground-PCB

Package: SOD-123


	DO-214AC

Hole for aligator clip	
	SEWALLI microbuilder
	SEWTAP-ALLIGATOR 

how to make parts in cadsoft eagle
	http://dangerousprototypes.com/2012/03/07/how-to-make-parts-in-cadsoft-eagle/

# Adafruit copper hole - pcb Weird shaped
https://www.adafruit.com/products/269
https://github.com/adafruit/Adafruit-9-DOF-and-10-DOF-PCBs

EAGLE Round corner for PCB
Redraw a rectangle with round corder (select round corner in the toolbar) 
at the DIMENSION Level
https://www.youtube.com/watch?v=Vx-Z3RD4748


How to create the gerber file
	https://www.youtube.com/watch?v=B_SbQeF83XU



OSHPARK
http://docs.oshpark.com/submitting-orders/cutouts-and-slots/	

http://michaelhleonard.com/how-to-design-the-perfect-pcb-part2/

GERBER
	https://www.youtube.com/watch?v=oXWwHbusicM
	
OTHER FT232H INTERFACE
    TUMPA TIAO - board with ft2232h	
        http://www.diygadget.com/tiao-usb-multi-protocol-adapter-jtag-spi-i2c-serial.html	
	
	
	
PCB SEED STUDIO

https://www.seeedstudio.io/fusion_pcb.html?gclid=CjwKCAjwmtDpBRAQEiwAC6lm4-jXcHjrWDgZhC8iEzrM_5TUmSa04AT3yFwPLPXUvMbjXvlSDIyIIRoC_TAQAvD_BwE

## NEXT ORDER
C:\DVT\MadeInTheUSB.PCB\USB.BusinessCard\Gerbers
Clock Multiplexer -- C:\DVT\MadeInTheUSB.PCB\EXTENSIONS\Analog\Clock Multiplexer\Gerbers
fCPU v1 -- C:\DVT\MadeInTheUSB.PCB\EXTENSIONS\Analog\fCPU\Gerbers
French USB -- C:\DVT\MadeInTheUSB.PCB\EXTENSIONS\Useless USB Gift Board\Gerbers

## Overboard motoro
- https://www.google.com/search?q=how+to+control+hoverboard+wheel+motor&rlz=1C1CHBD_enUS700US700&source=lnms&sa=X&ved=0ahUKEwjL5tL4m4blAhUjWN8KHSI3DbYQ_AUIDSgA&biw=1164&bih=553&dpr=1.1
- https://www.youtube.com/watch?v=LJzoy2TJXFk
- https://www.google.com/search?q=odrive+board&rlz=1C1CHBD_enUS700US700&oq=odri&aqs=chrome.0.69i59j0l2j69i57j69i60l2.1718j0j9&sourceid=chrome&ie=UTF-8
- https://www.google.com/search?q=emax+esc+30a&rlz=1C1CHBD_enUS700US700&source=lnms&sa=X&ved=0ahUKEwiwici4nYblAhVChuAKHSIKD58Q_AUIDSgA&biw=1164&bih=553&dpr=1.1

## How to insert an image
- Convert the image to 2 colors black and white
- in the board , menu File -> Import -> Bitmap
	* Select the bitmap
	* Select the color style mostly choice number 2
	* Select DPI, the greater the DPI the smaller the image will be
	* Select the layer mostly 25, top text