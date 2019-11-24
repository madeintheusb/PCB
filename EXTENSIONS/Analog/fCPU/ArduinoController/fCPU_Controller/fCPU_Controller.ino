/*
	Software to control the fCPU board.
 */
#include <fArduino.h>

//#define ON_BOARD_LED 13
//Led _onBoardLed(ON_BOARD_LED);
TimeOut _monitorTimeOut(1000);

// Set up Arduio pin to talk to the fCPU Control Interface
#define fCPU_REGISTER_1_BIT_0 2
#define fCPU_REGISTER_1_BIT_1 3
#define fCPU_REGISTER_1_BIT_2 4
#define fCPU_REGISTER_1_BIT_3 5

#define fCPU_REGISTER_2_BIT_0 6
#define fCPU_REGISTER_2_BIT_1 7
#define fCPU_REGISTER_2_BIT_2 8
#define fCPU_REGISTER_2_BIT_3 9

#define fCPU_REGISTER_1_CLK 10
#define fCPU_REGISTER_1_CLR 11 // Active Low
#define fCPU_REGISTER_2_CLK 12
#define fCPU_REGISTER_2_CLR 13 // Active Low

#define fCPU_MIN_PORT 2
#define fCPU_MAX_PORT 13

void SetRegisterBit(int pin, bool on) {

	digitalWrite(pin, on ? HIGH : LOW);
}

void ClearRegister(byte index) {

	Serial.print("ClearRegister "); Serial.println(index);

	int pin = index == 1 ? fCPU_REGISTER_1_CLR : fCPU_REGISTER_2_CLR;
	digitalWrite(pin, LOW);
	delay(2);
	digitalWrite(pin, HIGH);
	delay(2);
}

void ClockRegister(byte index) {

	Serial.print("ClockRegister "); Serial.println(index);

	int pin = index == 1 ? fCPU_REGISTER_1_CLK : fCPU_REGISTER_2_CLK;
	digitalWrite(pin, HIGH);
	delay(2);
	digitalWrite(pin, LOW);
	delay(2);
}

void SetRegister(byte registerIndex, byte val) {

	Serial.print("SetRegister "); 
	Serial.print(registerIndex);
	Serial.print(" ");
	Serial.println(val);

	SetRegisterBit(fCPU_REGISTER_1_BIT_0 + (registerIndex == 2 ? 4 : 0), (val & 1));
	SetRegisterBit(fCPU_REGISTER_1_BIT_1 + (registerIndex == 2 ? 4 : 0), (val & 2));
	SetRegisterBit(fCPU_REGISTER_1_BIT_2 + (registerIndex == 2 ? 4 : 0), (val & 4));
	SetRegisterBit(fCPU_REGISTER_1_BIT_3 + (registerIndex == 2 ? 4 : 0), (val & 8));
}

void InitPins() {

	for (int i = fCPU_MIN_PORT; i < fCPU_MAX_PORT; i++) { // Init all output gpio
		Board.SetPinMode(i, OUTPUT);
		digitalWrite(i, LOW);
	}
}

void setup()
{
	Board.InitializeComputerCommunication(115200, "Initializing fCPU Controller");
	//Board.SetPinMode(ON_BOARD_LED, OUTPUT);
	//_onBoardLed.SetBlinkMode(1000);
	InitPins();
	
	ClearRegister(1);
	ClearRegister(2);	
}

String GetUserCommand() {

	return Board.GetWindowsConsoleCommand().Command;
}


void RunProgram(byte v1, byte v2, double speed) {

	SetRegister(1, v1);
	ClockRegister(1);
	delay(1000 * speed);

	ClearRegister(1);
	delay(1000 * speed);

	SetRegister(2, v2);
	ClockRegister(2);
	delay(1000 * speed);

	ClearRegister(2);
	delay(1000 * speed);

	SetRegister(1, v1);
	SetRegister(2, v2);
	ClockRegister(1);
	ClockRegister(2);
	delay(1000 * speed);

	SetRegister(1, 0);
	SetRegister(2, 0);
	ClockRegister(1);
	ClockRegister(2);
	delay(1000 * speed);
}


void RunAllProgram(double wait) {

	RunProgram(1, 2, wait);
	RunProgram(1, 3, wait);
	RunProgram(1, 4, wait);
	RunProgram(1, 5, wait);
	RunProgram(1, 6, wait);
	RunProgram(1, 7, wait);
	RunProgram(1, 8, wait);
}

void loop()
{
	//_onBoardLed.Blink(); // Blink led every 1/2 second
	delay(200);
	if (Serial.available() > 0) {
		
		String cmd = GetUserCommand();
		Serial.print("User Command:"); 
		Serial.print(cmd);
		Serial.println(";");
		if (cmd.equals("RUN\r")) {
			 
			RunAllProgram(0.6);
		}
		if (cmd.equals("RUN_FAST\r")) {

			RunAllProgram(0.1);
		}


		if (cmd.equals("CLK_R_1\r")) {
			SetRegister(1, 1);
			ClockRegister(1);
		}
		if (cmd.equals("CLK_R_2\r")) {
			SetRegister(2,2);
			ClockRegister(2);
		}
		if (cmd.equals("CLR_R_1\r")) {
			ClearRegister(1);			
		}
		if (cmd.equals("CLR_R_2\r")) {
			ClearRegister(2);
		}
		if (cmd.equals("SINK1\r")) {
			digitalWrite(fCPU_REGISTER_1_CLR, LOW);
			Serial.println("Sinking 1");
		}
		if (cmd.equals("STOP_SINK1\r")) {
			digitalWrite(fCPU_REGISTER_1_CLR, HIGH);
			Serial.println("Stop Sinking 1");
		}
		if (cmd.equals("SINK2\r")) {
			digitalWrite(fCPU_REGISTER_2_CLR, LOW);
			Serial.println("Sinking 2");
		}
		if (cmd.equals("STOP_SINK2\r")) {
			digitalWrite(fCPU_REGISTER_2_CLR, HIGH);
			Serial.println("Stop Sinking 2");
		}
	}
	
}
