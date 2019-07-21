Nusbio SMD 0612
===============
	- C2, C3 Capacitor 0.1uF from:VCC to:GND (after fuse)
			W3A4ZC104K4T2A
			W3A4YC104K4T2A Capacitor Array[4] 0.1uF - 3.2 x 1.6 mm - 16v 10% -- $0.66
			http://www.avx.com/docs/Catalogs/caparray.pdf
			W
			3=0612
			A=array
			4=4 capacitor
			Y=16V
			C=X7R
			104=Capacitance code
			K=10%
			4=Automotive
			T=Plated Ni and Sn
			2A=7" Reel 
			http://www.mouser.com/ProductDetail/AVX/W3A4YC104K4T2A/?qs=sGAEpiMZZMt%2fMLURua8N%2fdgAXCdWPceXk9Zz%252bm1uwmo%3d

	http://www.mouser.com/ProductDetail/TDK/CKCA43X7R1H103M100AA/?qs=%2fha2pyFadugUMZhEdmFSj9%252bBrgJLX2grip9tO3l714R74xvmPsGfbP13ucQqsSJi

	- C1 Capacitor 10uF(electrolytic) from:VCC to:GND (after fuse)
	- Crystal
	- 1 Led


	- 1 1k/2k resistor for the led
	- USB Type A Right Angle 4-Pin DIP Female Jack Socket Connector -- http://www.amazon.com/gp/product/B00E1DYW1U?psc=1&redirect=true&ref_=oh_aui_detailpage_o02_s00		
	- Ferrite bead?
					

# Components
	- FT232RL - http://www.mouser.com/ProductDetail/FTDI/FT232RL-REEL/?qs=sGAEpiMZZMs5ceO8zL%252bTxyQLQIH6hE7q
	- 1 Capacitor Electrolitic 10uF between power and ground
	- 1 Capacitor Ceramic 0.1uF between power and ground
	- 1 Capacitor Ceramic 0.1uF between 3VOUT and ground
	
	- FERRITE BEAD 33 OHM 0805 - http://www.digikey.com/product-search/en?keywords=587-1909-1-ND

	Adafruit
	\https://www.adafruit.com/products/284
	https://github.com/adafruit/FTDI-Friend`+
		USB:
		- USB Type A Right Angle 4-Pin DIP Female Jack Socket Connector -- http://www.amazon.com/gp/product/B00E1DYW1U?psc=1&redirect=true&ref_=oh_aui_detailpage_o02_s00
		- VUSB to (20) VCC, (4) VCCIO
			- C1 Capacitor 10uF(electrolytic) from:VCC to:GND (after fuse)
			- C2 Capacitor 0.1uF from:VCC to:GND (after fuse) 
			- C3 Capacitor 0.1uF (17) from:3v3OUT to:GND and to:3.3V [ok]
		- USB D- (16) USBDM
		- USB D+ (15) USBDP
		- USB-GRD is AGND(25)
				
		- GND(7),GND(18),GND(21), TEST to:GND
		- OSC_IN(27)
		- OSC_OUT(28)q
		- Gpio      
			Gpio0, RI  (6)
			Gpio1, DSR (9)
			Gpio2, DTR (2)
			Gpio3, DCD (10)
			Gpio4, CTS (11)
			Gpio5, TXD (1)
			Gpio6, RXD (5)
			Gpio7, RTS (3)
		- Not plugged
			TXLED(23), RXLED(22), PWREN(14), TXDEN(13), SLEEP(12), RESET(19)
			CBUS0,CBUS1,CBUS2,CBUS3,CBUS4,


	Spark Fun Version
	https://github.com/sparkfun/FT232RL_USB_Breakout/tree/V_3.7
		- 500 ma fuse PTC (SMD)

		- C1 Capacitor 0.1uF (17) from:3v3OUT to:GND and to:3.3V
		- C2 Capacitor 0.1uF from:VCC to:GND (after fuse)
		- C5 Capacitor 10uF from:VCC to:GND (after fuse)
		
		- 1 Capacitor 4.7uF () from:vcc,vccio to:GND
		- AGND(25),GND(7),GND(18),GND(21), TEST to:GND
		- VUSB to (20) VCC, (4) VCCIO
		- USB D- (16) USBDM
		- USB D+ (15) USBDP
		- USB GRD is GRD
		- RESET(19) to:?
		- OSC_IN(27)
		- OSC_OUT(28)
		- Gpio      
			Gpio0, RI  (6)
			Gpio1, DSR (9)
			Gpio2, DTR (2)
			Gpio3, DCD (10)
			Gpio4, CTS (11)
			Gpio5, TXD (1)
			Gpio6, RXD (5)
			Gpio7, RTS (3)
		- Not plugged
			TXLED(23), RXLED(22), PWREN(14), TXDEN(13), SLEEP(12)


# Video
	- Reflow https://www.youtube.com/watch?v=_5lksMvmqQc
	-	http://www.jmedved.com/usbuart/
		https://www.youtube.com/watch?v=g5Pl0cuzVQw

	- https://www.youtube.com/watch?v=E0a1N-68lJg

			
	http://obrazki.elektroda.pl/2123633000_1298130404.jpg
	- 1 Capacitor 100nF (17) from:3v3OUT to:GND
	- 1 Capacitor 4.7uF () from:vcc,vccio to:GND
	- AGND(25),GND(7),GND(18),GND(21), TEST to:GND
	- from:VUSB to (20) VCC, (4) VCCIO
	- USB D- (16) USBDM
	- USB D+ (15) USBDP
	- USB GRD is GRD
	- RESET(19) to:?
	
	https://upverter.com/sath/155d4df4a872df29/xB-Buddy/
	USB Adapter Type A
		1 U3		USB Type A Connector	FCI	87520-0010BLF	Through Hole
		1 C3		10 uF 10V Capacitor	Sanyo	10SH10M
		2 C1, C2	100 nF Capacitor	Murata	GRM188R70J104KA01D	0603

Other Product
https://www.sparkfun.com/products/retired/199
http://www.silabs.com/products/mcu/Pages/USBtoUARTBridgeVCPDrivers.aspx

PARTS:
- 10 Pin header adafruit => PINHD-1X10
- FT232RL
			USB Male Type A Port Right Angle 4-Pin DIP Jack Socket Connector
			USB A Type Plug Male Socket Connector 90 degree DIP Type,USB-A-01
				http://www.aliexpress.com/item/Free-shipping-100pcs-USB-connectors-A-type-Male-right-angle-DIP-4-Pins-White-insulator/550428944.html
- Capacitor Electrolytic Radial 
	10uF  electrolytic capacitor Radial Adafruit Package C-US025-024X044 (C-US) (2mm)
		http://www.mouser.com/ProductDetail/Vishay-Sprague/517D106M025JA6AE3/?qs=sGAEpiMZZMvwFf0viD3Y3UFPmOH88wd0QFkz%252bh9Y1e4%3d
	0.1uF Ceramic Capacitor Package: C050-055X075 -- grid 5 mm, outline 5.5 x 7.5 mm
		http://www.mouser.com/ProductDetail/TDK/FK28X7R1E104K/?qs=sGAEpiMZZMt3KoXD5rJ2N48tYEMqcp4xEeCIZV2cepk%3d -- $0.082
		

- External Oscillator  
	12.0MHz +- 0.5% AT-Cut Crystal
	http://www.ftdichip.com/Support/Documents/AppNotes/AN_100_Using_The_FT232_245R_With_External_Osc(FT_000067).pdf
	The FT232R and FT245R have internal load capacitors and so external capacitors will not be required in many applications.
	The values are 6.27pF for OSCI and 30pF for OSCO.
	http://www.mouser.com/All-Manufacturers/Passive-Components/_/N-5g73Z0?Keyword=at-cut+12&FS=True
	http://www.mouser.com/ProductDetail/Citizen-Finetech-Miyota/HC49US-12000MABJ-UB/?qs=sGAEpiMZZMukHu%252bjC5l7YXzLYL1e2SuNVT6nzaq%2ffc0%3d

	Adafruit:
		Package: HC49U-V
		
	Eagle part thru hole: 		
		Device:CRYSTALHC49U-V (CRYSTAL)
		Package: HC49U-V
		Library: SparkFun-FreqCtrl -- https://github.com/sparkfun/SparkFun-Eagle-Libraries

Gpio0 , GPIOType.RI  
Gpio1 , GPIOType.DSR 
Gpio2 , GPIOType.DTR 
Gpio3 , GPIOType.DCD 
Gpio4 , GPIOType.CTS
Gpio5 , GPIOType.TXD
Gpio6 , GPIOType.RXD 
Gpio7 , GPIOType.RTS 
   

SschmartBoard

204-0006-01 -- 3 package 8 pins, 20 pins and 28 pins
http://www.mouser.com/ds/2/356/204-0006-01-204251.pdf

. I also bought a small soldering iron tip, a Hakko T18-BL, thinking that my current tip is probably too big for the troughs in the Schmartboard.
