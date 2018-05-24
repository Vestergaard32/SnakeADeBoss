#ifndef KEYPADDRIVER_H_
#define KEYPADDRIVER_H_

/*
	Initialize the input and output pins
	required for the signals of the keypad
*/
void InitKeypad();

/*
	Get the key currently pressed down on
	the keypad
*/
char GetKey();

#endif /* KEYPADDRIVER_H_ */