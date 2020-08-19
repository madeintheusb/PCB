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
#define MAX_ANIMATION_INDEX (4-1)

#define WAIT 150

int _currentAnimation = MIN_ANIMATION_INDEX; // We have 4 different types of animation which repeat
int _animationRepeatCounter = 0; // Count the repeat of the current animation
bool _repeatAnimation = true; // When false we stay on the current animation, can be changed with the button
#define ANIMATION_COUNTER_MAX 4 // After each 16 instance of an animation we move to the next one

bool AnalogButtonPressed()
{
	return analogRead(ANIMATION_CHANGE_BUTTON_ANALOG_PIN) > 512;
}

bool IsAnimationChangeButtonPressed()
{
	bool pressed = AnalogButtonPressed();
	if (pressed) { // Wait for button to be released
		Board.Trace("IsAnimationChangeButtonPressed");
		AllOn();
		while (AnalogButtonPressed())
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

	_onBoardLed.Blink(); // Takes care of animation the on board led on/off animation

	if (IsAnimationChangeButtonPressed())
	{		
		_repeatAnimation = !_repeatAnimation;
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

void Sequence(int count, int pins[])
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

void Sequence(int pin0)
{
	if (pin0 == -1) {
		int arr[] = { pin0 };
		Sequence(0, arr); // Only clear all
	}
	else
	{
		int arr[] = { pin0 };
		Sequence(1, arr);
	}
}

void Sequence(int pin0, int pin1)
{
	int arr[] = { pin0, pin1 };
	Sequence(2, arr);
}

void Sequence(int pin0, int pin1, int pin2)
{
	int arr[] = { pin0, pin1, pin2 };
	Sequence(3, arr);
}

void Sequence(int pin0, int pin1, int pin2, int pin3)
{
	int arr[] = { pin0, pin1, pin2, pin3 };
	Sequence(4, arr);
}

void Sequence(int pin0, int pin1, int pin2, int pin3, int pin4)
{
	int arr[] = { pin0, pin1, pin2, pin3, pin4 };
	Sequence(5, arr);
}

void Animation1(bool clearLastStep)
{
	if (CheckForUserAction()) return;
	Sequence(0);
	Sequence(0, 1);
	Sequence(0, 1, 3);
	Sequence(1, 2, 4);
	Sequence(1, 3, 5);
	Sequence(2, 4, 6);
	if (CheckForUserAction()) return;
	Sequence(3, 5, 6);
	Sequence(4, 6, 7);
	Sequence(6, 7);
	Sequence(7);
	if (clearLastStep)
		Sequence(-1);
}

void Animation2(bool clearLastStep)
{
	if (CheckForUserAction()) return;

	Sequence(7);
	Sequence(6, 7);
	Sequence(4, 6, 7);
	Sequence(3, 5, 6);
	Sequence(2, 4, 6);
	if (CheckForUserAction()) return;
	Sequence(1, 3, 5);
	Sequence(1, 2, 4);
	Sequence(0, 1, 3);
	Sequence(0, 1);
	Sequence(0);

	if (clearLastStep)
		Sequence(-1);
}

void Animation3()
{
	Animation1(false);
	if (CheckForUserAction()) return;
	Sequence(7);
	Sequence(6, 7);
	Sequence(4, 6, 7);
	Sequence(3, 5, 6);
	Sequence(2, 4, 6);
	Sequence(1, 3, 5);
	if (CheckForUserAction()) return;
	Sequence(1, 2, 4);
	Sequence(0, 1, 3);
	Sequence(0, 1);
	Sequence(0);
}

void Animation4()
{
	Sequence(0);
	Sequence(0, 2);
	Sequence(0, 2, 4);
	Sequence(0, 2, 4, 6);
	Sequence(1, 3, 5, 7);
	Sequence(2, 4, 6, 7);
	Sequence(5, 6, 7);
	Sequence(6, 7);
	Sequence(7);
	Sequence(-1);
	Sequence(-1);
	Sequence(7);
	if (CheckForUserAction()) return;
	Sequence(6, 7);
	Sequence(5, 6, 7);
	Sequence(2, 4, 6, 7);
	Sequence(1, 3, 5, 7);
	Sequence(0, 2, 4, 6);
	Sequence(0, 2, 4);
	Sequence(0, 1, 2);
	Sequence(0, 1);
	Sequence(0);
	Sequence(-1);
	Sequence(-1);
}

void Animation5()
{
	for (int z = 0; z < 10; z++) {

		int maxSeq = 2;
		for (int i = 0; i < maxSeq; i++) {

			Sequence(0, 2, 4, 6);
			delay(WAIT / (1 + z));
			Sequence(1, 3, 5, 7);
			delay(WAIT / (1 + z));
			if (CheckForUserAction()) return;
		}
	}
}

void setup()
{
	Board.InitializeComputerCommunication(9600, "Starting");
	InitPins();
	for (int i = 0; i < 10; i++) {
		AllOn();
		delay(150 - (i * 10));
		AllOff();
		delay(150 - (i * 10));
	}	
	Sequence(0);
	_onBoardLed.SetBlinkMode(500); // Blink every 1/2 second
	delay(1000);
}

// Add the main program code into the continuous loop() function
void loop()
{
	CheckForUserAction();

	if (_currentAnimation == 0)
		Animation1(true);
	else if (_currentAnimation == 1)
		Animation2(true);
	else if (_currentAnimation == 2)
		Animation3();
	else if (_currentAnimation == 3)
		Animation4();
	
	// If we are in repeat animation mode, we increase the repeat
	if (_repeatAnimation) 
		_animationRepeatCounter += 1;

	// Once we reach the max number of repeat for one animation, we move to the next one
	if (_animationRepeatCounter > ANIMATION_COUNTER_MAX)
	{
		_animationRepeatCounter = 0;
		NextAnimation();
	}		
}
