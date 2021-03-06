/*
AT28C16 EEPROM Programmer
(C) Frederic Torres 2018
*/

#ifndef _EEPROM_PROGRAMMER_h
#define _EEPROM_PROGRAMMER_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

#include <fArduino.h>

// Need Arduino Mega 2560

#define EEPROM_D0 2
#define EEPROM_D7 9

#define EEPROM_A0 22
#define EEPROM_A7 29

#define EEPROM_OUTPUT_ENABLE 40
#define EEPROM_WRITE_ENABLE 41

enum DATA_MODE { READ = 0, WRITE };

class EEPROM_Programmer {

private:
	DATA_MODE _dataMode;

public:
	byte DataValue;
	int AddrValue;

	EEPROM_Programmer();
	~EEPROM_Programmer();
	void Init();

	void SetPinsForDataBusInReadMode();
	void SetPinsForDataBusInWriteMode();
	void SetPinsForAddressBus8Bits();

	String GetStatus();
	void SetDataBusWriteData(byte d);
	byte GetDataBusReadData();
	void CheckForReadMode();
	void CheckForWriteMode();

	
	void SetAddressBus8bits(byte addr8bit);
	void SetDataBusAndAddressBus8bitWriteData(byte data, byte addr);

	void AnimationStartSequence();
	void AnimationWorkProperlySequence();
	//#define EEPROM_OUTPUT_ENABLE 40
	//#define EEPROM_WRITE_ENABLE 41
	void SetOutputEnable();
	void SetOutputDisable();
	void InitiateWriteByteOperation();
};

#endif

