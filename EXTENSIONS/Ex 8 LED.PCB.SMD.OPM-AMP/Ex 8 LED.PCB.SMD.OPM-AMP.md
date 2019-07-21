
8 smd blue led, showing the state of the 8 gpios without interfering

using 8 op-amp like the arduino

https://rheingoldheavy.com/arduino-from-scratch-part-6-pin-13-led/

each gpio goes to the regular output header, but also in paralle goes to
the op-amp + (non-inverter).

OP-AMP:
	Dual LMV358
		Output A         [1  8] Vcc
		In Inver A -     [2  7] Output B
		In Non Inver A + [3  6] In Inver B - 
		Gnd			     [4  5] In Non Inver B +

		1 -> 2 Negative Feedback
		gpio -> 3


	LM358 image - http://www.smokeandwires.co.nz/269-large_default/lm358p-dual-op-amp.jpg

	Quad LM2902M Package SOP14
		http://www.mouser.com/ProductDetail/Fairchild-Semiconductor/LM2902M/?qs=sGAEpiMZZMtCHixnSjNA6EtqSi1QchwPugHi%252bft8%252bCs%3d
		EAGLE LM2902D SO14

		http://www.mouser.com/ProductDetail/Fairchild-Semiconductor/LM2902M/?qs=sGAEpiMZZMtCHixnSjNA6EtqSi1QchwPugHi%252bft8%252bCs%3d 
		$0.2
		sop-14