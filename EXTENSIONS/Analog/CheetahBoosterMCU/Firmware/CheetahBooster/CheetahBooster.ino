#include <fArduino.h>
#include "CheetahBooster.h"

#define DEBUG_ANIMATION 0
Led _onBoardLed(LED_BUILTIN);

#define LED_0 2
#define LED_1 3
#define LED_2 4
#define LED_3 5
#define LED_4 6
#define LED_5 7
#define LED_6 8
#define LED_7 9
#define LED_MIN LED_0
#define LED_MAX LED_7

#define ANIMATION_CHANGE_BUTTON_ANALOG_PIN 2 // Need a Pull down resitor

#define MIN_ANIMATION_INDEX 0
#define MAX_ANIMATION_INDEX 4

#define WAIT 140

int _currentAnimation = MIN_ANIMATION_INDEX;
int _animationCounter = 0;
bool _moveToNextAnumation = true;
#define ANIMATION_COUNTER_MAX 2 // After each 16 instance of an animation we move to the next one

bool IsAnimationChangeButtonPressed() 
{
	int v = analogRead(ANIMATION_CHANGE_BUTTON_ANALOG_PIN);
	// Board.Trace(StringFormat.Format("analogRead %d", v));

	bool pressed = v > 512;

	if (pressed) { // Wait for button to be released
		Board.Trace("IsAnimationChangeButtonPressed");
		AllOn();
		while (IsAnimationChangeButtonPressed()) 
		{
			delay(200);
		}
		AllOff();
	}

	return pressed;
}

void NextAnimation() {
	_currentAnimation += 1;
	if (_currentAnimation > MAX_ANIMATION_INDEX)
		_currentAnimation = MIN_ANIMATION_INDEX;
}

bool CheckForUserAction() {

	_onBoardLed.Blink();

	if (IsAnimationChangeButtonPressed()) 
	{
		_moveToNextAnumation = !_moveToNextAnumation;
		return true; // Notify change of state
	}
	return false;
}

void InitPins()
{
	for (int p = LED_MIN; p <= LED_7; p++) // all off
		pinMode(p, OUTPUT);

	pinMode(LED_BUILTIN, OUTPUT);
}

void sequence(int count, int pins[])
{
	AllOff();

	for (int p = 0; p < count; p++)
	{
		int pin = pins[p] + LED_MIN;
		digitalWrite(pin, HIGH);
	}

	int wait = WAIT;
	if (DEBUG_ANIMATION) wait *= 3;
	delay(wait - (count * 15));
}

void AllOff()
{
	for (int p = LED_MIN; p <= LED_7; p++)
		digitalWrite(p, LOW);
}

void AllOn()
{
	for (int p = LED_MIN; p <= LED_7; p++)
		digitalWrite(p, HIGH);
}


void sequence(int pin0)
{
	if (pin0 == -1) {
		int arr[] = { pin0 };
		sequence(0, arr);
	}
	else
	{
		int arr[] = { pin0 };
		sequence(1, arr);
	}
}

void sequence(int pin0, int pin1)
{
	int arr[] = { pin0, pin1 };
	sequence(2, arr);
}

void sequence(int pin0, int pin1, int pin2)
{
	int arr[] = { pin0, pin1, pin2 };
	sequence(3, arr);
}

void sequence(int pin0, int pin1, int pin2, int pin3)
{
	int arr[] = { pin0, pin1, pin2, pin3 };
	sequence(4, arr);
}

void sequence(int pin0, int pin1, int pin2, int pin3, int pin4)
{
	int arr[] = { pin0, pin1, pin2, pin3, pin4 };
	sequence(5, arr);
}

void Animation1(bool clearLastStep)
{
	if (CheckForUserAction()) return;
	sequence(0);
	sequence(0, 1);
	sequence(0, 1, 3);
	sequence(1, 2, 4);
	sequence(1, 3, 5);
	sequence(2, 4, 6);
	if (CheckForUserAction()) return;
	sequence(3, 5, 6);
	sequence(4, 6, 7);
	sequence(6, 7);
	sequence(7);
	if (clearLastStep)
		sequence(-1);
}

void Animation2(bool clearLastStep)
{
	if (CheckForUserAction()) return;
	if (clearLastStep)
		sequence(-1);
	sequence(7);
	sequence(6, 7);
	sequence(4, 6, 7);
	sequence(3, 5, 6);
	sequence(2, 4, 6);
	if (CheckForUserAction()) return;
	sequence(1, 3, 5);
	sequence(1, 2, 4);
	sequence(0, 1, 3);
	sequence(0, 1);
	sequence(0);
}

void Animation3()
{
	Animation1(false);
	if (CheckForUserAction()) return;
	sequence(7);
	sequence(6, 7);
	sequence(4, 6, 7);
	sequence(3, 5, 6);
	sequence(2, 4, 6);
	sequence(1, 3, 5);
	if (CheckForUserAction()) return;
	sequence(1, 2, 4);
	sequence(0, 1, 3);
	sequence(0, 1);
	sequence(0);
}

void Animation4()
{
	sequence(0);
	sequence(0, 2);
	sequence(0, 2, 4);
	sequence(0, 2, 4, 6);
	sequence(1, 3, 5, 7);
	sequence(2, 4, 6, 7);
	sequence(5, 6, 7);
	sequence(6, 7);
	sequence(7);
	sequence(-1);
	sequence(-1);
	sequence(7);

	sequence(6, 7);
	sequence(5, 6, 7);
	sequence(2, 4, 6, 7);
	sequence(1, 3, 5, 7);
	sequence(0, 2, 4, 6);
	sequence(0, 2, 4);
	sequence(0, 1, 2);
	sequence(0, 1);
	sequence(0);
	sequence(-1);
	sequence(-1);
}

void Animation5()
{
	for (int z = 0; z < 10; z++) {

		int maxSeq = 2;
		for (int i = 0; i < maxSeq; i++) {

			sequence(0, 2, 4, 6);
			delay(WAIT / (1 + z));
			sequence(1, 3, 5, 7);
			delay(WAIT / (1 + z));
			if (CheckForUserAction()) return;
		}
	}
}

void setup()
{
	Board.InitializeComputerCommunication(9600, "Starting");
	InitPins();
	sequence(0);
	_onBoardLed.SetBlinkMode(500); // Blink every second
}

// Add the main program code into the continuous loop() function
void loop()
{
	CheckForUserAction();

	if (_currentAnimation == 0)
		Animation1(true);

	if (_currentAnimation == 1)
		Animation2(true);

	if (_currentAnimation == 2)
		Animation3();

	if (_currentAnimation == 3)
		Animation4();

	//if (_currentAnimation == 4)
	//	Animation5();

	if (_moveToNextAnumation) 
	{
		_animationCounter += 1;
	}

	if (_animationCounter > ANIMATION_COUNTER_MAX) 
	{
		_animationCounter = 0;
		NextAnimation();
	}
}

