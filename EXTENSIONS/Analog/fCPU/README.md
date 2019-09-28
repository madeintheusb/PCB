# fCPU

## Goal

Create 4 bit CPU that can
- Receive as input 2 4 bit values
- Display each value on a 7-Segment Display
- Add the 2 values
- Display the result of the addition

There is no machine code stored in some EEPROM. The program is hardcoded,
from the 10 outputs of the controller we wire each pin to execute one specific instruction.
Idealy, the program would look like this:

| Controller Pin 	| Instruction                               	|
|----------------	|-------------------------------------------	|
| 1              	| Clear Register 1                          	|
| 2              	| Clear Register 2                          	|
| 3              	| Clear Adder output                        	|
| 4              	| Display Adder result on 7-Segment Display 	|
| 5              	| Read Register 1 from input 1              	|
| 6              	| Read Register 2 from input 2              	|
| 7              	| Add Register 1 and 2                      	|
| 8              	| Display Adder result on 7-Segment Display 	|
| 9              	| Nop                                       	|
| 10             	| Nop                                       	|

Display Limitation: In v1, we can only display number from 0 to 9, we cannot display number from 10 to 15.

## Architecture

Using a SN74LS90 counter, we can count from 0 to 9, to play the role of the Program Counter.

We use a SN74LS42N (Demultiplexers 4 to 10 BCD), to easily trigger up to 10 actions/instructions. Combined with a 2 inverter sn74ls14 (6 inverter/IC), for each instructions we get a pin1 and a pin0, when in execution mode.

### Code execution
    (1) : pin0 --> SN74LS273 Register 1 to CLR, will reset to 0 register 1
        - CTRL_ON_1 [NC], - CTRL_OFF_1 --> REGISTER_1_CLR
        The CLR pin from the register is active low and will be reset to 0 when the wire
        change from state 1 to 0 and then back 1. The state of the write CTRL_OFF_1 is always 1
        except when instruction (1) is executed where the pin become 0, clearing the register.
        CTRL_OFF_1 is always 1 except when instruction 1 is activated when it become 0
    (2) : pin0 --> SN74LS273 Register 2 to CLR, will reset to 0 register 2
    (3) : pin1 --> SN74LS273 Register 1 to CLK, will trigger load the input1 into register 1
    (4) : pin1 --> SN74LS273 Register 2 to CLK, will trigger load the input2 into register 2
    
### Wiring
- CTRL_ON_1 [NC], 
- CTRL_ON_INV_1 --> [REGISTER 1 CLR]

- CTRL_ON_2
- CTRL_ON_INV_2

- CTRL_ON_3
- CTRL_ON_INV_3

- CTRL_ON_4
- CTRL_ON_INV_4

- CTRL_ON_5
- CTRL_ON_INV_5

- CTRL_ON_6
- CTRL_ON_INV_6

### Input device to registers
We will have 2 registers, implemented by the 2 SN74LS273 which is a 8 bit register.
Bit 1..4D are used. Bit 5..8D are tied to 0.
1 -[switch]-> resistor-to-gnd * Register 1 1D
2 -[switch]-> resistor-to-gnd * Register 1 2D
3 -[switch]-> resistor-to-gnd * Register 1 3D
4 -[switch]-> resistor-to-gnd * Register 1 4D

- EAGLE CAD Part: Package:EDG-04, Device:SW_DIP-4.
    * Pin 1,2,3,4 are are connected bit 0..3 of register
    * Pin 1,2,3,4 are also conntected to GND via a 4 resistors
        - When current does not flow pin is tied to 0
        - When current flow pin goes into register pin and also to GND via the resistor
    * Pin 5,6,7,8 are tied to VCC (1).

### Output device
- A bit bus data_bus:1,2,3,4 connected to a 7-Segment Driver, connected to one 7-Segment display
- The data bus can receive the value from register1, register2 or adder1, therefore we need 12 (3*4) diodes
    - Only register1 or register2 or adder1 can send data to the bus at one time
    - How to we activate which device set the data on the bus `TBD`

## Componenents

### Program Counter
SN74LS90
- EAGLE CAD Part: Package: KNOWN, Device:KNOWN.

### Controller/Software simulator

[SN74LS42N](https://www.mouser.com/ProductDetail/Texas-Instruments/SN74LS42N?qs=sGAEpiMZZMutXGli8Ay4kHCkCpxTtxgl92ZLS6s4WlY%3D)

* Demultiplexers 4 to 10 BCD
* Automatically set to 1 or execute
* Require inverting the output

- EAGLE CAD Part: Package:DIL16, Device:74LS42N, US
    * Check pin 8 seems to not be used in EAGLE CAD part, see Data Sheet.

### Inverter

[sn74ls14](http://www.ti.com/lit/ds/symlink/sn74ls14.pdf)
* No floating pin.
* 6 Inverter per IC

- EAGLE CAD Part: Package:DIL16, Device:74LS14N, US

### Adder
SN74LS83A

### Register
* 8b [SN74LS273](http://www.ti.com/lit/ds/symlink/sn74ls273.pdf)
    - Experiment with a SN74LS273
    - Easier to program than the 4 bit below. We will 2 use 8b register and ignore bit 5..8.
    - About $0.25 on AliExpress
    - Programming
        * Input 1D, 2D, 3D, 4D, 5D, 6D, 7D, 8D
        * Output 1Q, 2Q, 3Q, 4Q, 5Q, 6Q, 7Q, 8Q
        * Setting value CLK 0 to 1
        * Clear to 0 CLR 1 to 0
    
* 4b [SN74LS173](http://www.ti.com/lit/ds/symlink/sn74ls173a.pdf)
    - Input 1D, 2D, 3D, 4D
    - Output 1Q,2Q, 3Q, 4Q
    - Setting input set G1=0, G2=0, CLK 0 to 1
    - Setting output M=0, N=0 (this could be set to 0 all the time to output the result)

Gated enable inputs are provided on these devices for controlling the entry of data into the flip-flops. When both data-enable (G1, G2) inputs are low, data at the D inputs are loaded into their respective flip-flops on the next positive transition of the buffered clock input. Gate output-control (M, N) inputs also are provided. When both are low, the normal logic states (high or low levels) of the four outputs are available for driving the loads or bus lines. The outputs are disabled independently from the level of the clock by a high logic level at either output-control input. The outputs then present a high impedance and neither load nor drive the bus line. Detailed operation is given in the function t

### 7 Segment Driver
- 74LS47 common annode

### Schottky Diode 
Registers and adder data bus output is linked to the main DTA_BUS, each for bit is protected
with a Shotcky Diode (2 registers + 1 adder) * 4 = 12 diodes
- Diode 1N5817
- EAGLE CAD Parts:
    * Package Thru-Hole Package:DO35Z10, Device:1N821
    * Diode 1N5817 package:(SS12, small package)
        - Package:MELF-MLL41, Device:DIODE-MELF-MLL41 (DIODE-)


### Connector of write with different name
To connect a wire like CTRL_OFF_1 to REGISTER_1_CLR and keep different name
I use a extra connected which I will to manually solder each part.
- EAGLE CAD Parts:
    * Package SOLDERJUMPER_REFLOW, Device:SOLDERJUMPERREFLOW (SOLDERJUMPER)

## Reference

### IC Series

- [7400 Series](https://en.wikipedia.org/wiki/List_of_7400-series_integrated_circuits) 

## Path

C:\DVT\MadeInTheUSB.PCB\EXTENSIONS\Analog\fCPU
