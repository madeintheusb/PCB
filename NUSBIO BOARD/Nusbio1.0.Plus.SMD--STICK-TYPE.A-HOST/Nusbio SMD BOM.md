Nusbio SMD 0612
===============

Size: 0805 -- 2 x 1.25mm
	- FT232RL -> ~ $4
	- C1 Capacitor 10uF -- aluminum electrolytic ~ $0.04
	- C2 & C3 Capacitor 0.1uF ceramic ~ $0.03 x 2
	- Crystal - $0.3 -- SMD Special size ~ 0.07 
	- 1 Led	- @0.2 -- 0805 [1 led + 1 resistor:0.04]or[9 led + 9 resistor:0.36]
	- 1 1k/2k resistor for the led
	- USB Plug -- $0.2
	- PCB == $2 -- For Nusbio Stick
	---------------------------------------------
	$6.73 ~ Price [chip:$4, PCB:$2, Other:$0.73]

USB Connector Right angle male -- DO NOT BUY FROM MOUSER -> BUY FROM ALIEXPRESS FOR $0.2
==============================
	http://www.mouser.com/search/refine.aspx?N=13833015
	http://www.mouser.com/Connectors/USB-Connectors/_/N-88hmf?P=1z0yxtiZ1yzudq8Z1ytavvh
	http://www.mouser.com/ProductDetail/TE-Connectivity/1-1734028-1/?qs=sGAEpiMZZMulM8LPOQ%252bykyMvpYkjjOa9KfhnSijHux8%3d

	EAGLE PART USB Type A Female with Soldering connector
		Package: USB-FEMALE-A-PTH, Library:STUNTAZ, download from https://github.com/nall/EagleSupport

	EAGLE PART USB Type A Female with no soldering connector only holder
		Package:USB-A003, Library:con-yamaichi
	
Capacitor 10uF - Electrolytic Aluminium
=======================================
	This capcitor works BUT we do not use , we went all ceramic
	From Mike Beach
	http://www.digikey.com/product-detail/en/CC1206KKX7R7BB106/311-1956-1-ND/5195858
	KEMET’s family of solid tantalum chip capacitors 
	10UF-16V-10%(TANT), Package:EIA3216, CAP-00811
	EIA 3216-18 (Kemet A, AVX A) 3.2 mm × 1.6 mm × 1.8 mm
	http://www.mouser.com/Passive-Components/Capacitors/Tantalum-Capacitors/Tantalum-Capacitors-Solid-SMD/_/N-75hr4?P=1z0wrkrZ1z0x565

	TAJA106K016RNJ -- Tantalum Capacitors - Solid SMD 16volts 10uF 10% -- 1206 3.2 x 1.6mm
		http://www.mouser.com/ProductDetail/AVX/TAJA106K016RNJ/?qs=sGAEpiMZZMuEN2agSAc2pmRv4r8cj6yFp4GfU7lrKPQ%3d
		http://www.aliexpress.com/item/Free-shipping-100pcs-SMD-tantalum-capacitor-10-uf-16-v-106-k-106-c-A3216-type/32350774768.html?spm=2114.01020208.3.2.110vyK		
		http://www.mouser.com/Search/ProductDetail.aspx?R=TAJA106K016RNJvirtualkey58110000virtualkey581-TAJA106K016R


Capacitor 47pF - Ceramic
========================
	http://fr.aliexpress.com/item/Free-Shipping-100PCS-1206-47PF-47P-5-NPO-50V-chip-SMD-Ceramic-capacitor/32521170741.html

Capacitor 0.1uF - Ceramic -- 1206 3.2 x 1.6mm
===========================================
	ALIEXPRESS
		Chip capacitors 1206 104K/100NF/0.1UF 250V TDK capacitor 10 Batch 0.1
			104-
			K-10%
			1cm x 1cm x 1cm (0.39in x 0.39in x 0.39in)
		http://www.aliexpress.com/item/Chip-capacitors-1206-104K-100NF-0-1UF-250V-TDK-capacitor-10-Batch-0-1/1379162937.html

		MOUSER 1206
		http://www.mouser.com/Search/ProductDetail.aspx?R=CC1206KRX7R8BB104virtualkey60120000virtualkey603-CC206KRX7R8BB104

Resistor $0.02
==============
	220 Ohms http://www.aliexpress.com/item/100-pcs-lot-220-OHM-SMD-0805-Resistor-New-RoHS/2015558100.html
	2.2k http://www.aliexpress.com/item/100-pcs-lot-2-2K-OHM-SMD-0805-Resistor-New-RoHS/2015598709.html
	1.k http://www.aliexpress.com/item/100-pcs-lot-1K-OHM-SMD-0805-Resistor-New-RoHS/2015251564.html
	4.7k http://www.aliexpress.com/item/100-pcs-lot-4-7K-OHM-SMD-0805-Resistor-New-RoHS/2016632097.html

	EAGLE: Device:R-US_R0805 (R-US_), Package:R0805, Adafruit

LED SMD - 1206
==============

	AliExpress
		SMD LED 0805 Blue Super Bright Free shipping A008 $0.02
		http://www.aliexpress.com/item/100PCS-SMD-LED-0805-Blue-Super-Bright-Free-shipping-A008/32421999123.html
		0805-R Ultra Bright SMD, 0805 RED LED 100PCS A008 $0.02
		http://www.aliexpress.com/item/0805-R-Ultra-Bright-SMD-0805-RED-LED-100PCS-A008/32421987323.html

	EAGLE: Device:LEDCHIPLED_0805 (LED), Package:CHIPLED_0805, Adafruit

JUMPER
======
	$1.33 for 50
	http://fr.aliexpress.com/item/IMC-Hot-50pcs-2-54mm-Jumper-Cap-mini-Jumper-Short-Circuit-Cap-Connectors/32438706194.html?ws_ab_test=searchweb201556_1_79_78_77_91_80,searchweb201644_5,searchweb201560_9

	
Crystal SMD
======================================
	LED SMD - Crystals 12MHz 18pF HC49S SMD - 4.7 mm W x 11.4 mm L x 4.3 mm H -- $0.07
	Free Shipping 49 s passive patch crystals 49 SMD crystal false patch 12.000 MHZ 12 MHZ 12 
	http://www.aliexpress.com/item/Free-Shipping-49-s-passive-patch-crystals-49-SMD-crystal-false-patch-12-000-MHZ-12/32295267421.html
	
AliExpress
	http://www.aliexpress.com/wholesale?catId=0&initiative_id=SB_20150827155600&SearchText=49S+SMD+crystals+12+mhz
	Passive patch crystals 49 SMD crystal false patch 12.000 MHZ 12 MHZ 12 m
	http://www.aliexpress.com/item/Free-Shipping-49-s-passive-patch-crystals-49-SMD-crystal-false-patch-12-000-MHZ-12/1918937648.html?spm=2114.01020208.3.10.MxsGO5
	http://www.mouser.com/ProductDetail/Citizen/HCM49-12000MABJ-UT/?qs=6siQ5y5nVCx5wVfYiG8NYA%3d%3d

Thru hole HC49US-12.000MABJ-UB -- http://www.mouser.com/Search/ProductDetail.aspx?R=HC49US-12.000MABJ-UBvirtualkey69500000virtualkey695-HC49US-12-U
                                  
SMD HCM49-12.000MABJ-UT http://www.mouser.com/Search/ProductDetail.aspx?R=HCM49-12.000MABJ-UTvirtualkey69500000virtualkey695-HCM49-12-U
	EAGLE:*CRYSTALHC49S*

Tutorial
	SMD 
	http://www.microbuilder.eu/Tutorials/Fundamentals/SMDPackages.aspx
	CHART
	http://www.topline.tv/SizeChart.html

# Nusbio starter kit
	$2.5 for one bread board and male wire
	http://www.aliexpress.com/store/product/Breadboard-MB-102-8-30-points-Solderless-Prototype-Bread-board-kit-65-Flexible-jumper-wires-wholesale/1194737_2020812175.html


