/*
 * KeypadDriver.c
 *
 * Created: 19-04-2018 08:32:20
 *  Author: CodingBeagle
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>

#define ROW_1 4;
#define ROW_2 6;
#define ROW_3 7;
#define ROW_4 5;

char keyPressed = 0;

void InitKeypad()
{
	// Setup interrupt pins
	sei(); // Enable Global Interrupt
	EIMSK |= 0b00001111; // Enable external interrupt pins 0, 1, 2 and 3
	EICRA |= 0b11111111; // Set ISR trigger rising edge on External interrupt 2 (SW2)

	// Setup input pins for keyboard input
	// These are pins PA6 (Row 2) and PA4 (Row 1), and C7 (Row 3) and C5 (Row 4)
	DDRA |= 0b01010000;
	DDRC |= 0b10100000;
}

char GetKey()
{
	return keyPressed;
}

// Column 1
ISR(INT0_vect)
{
	// Key 4 (A6)
	
	if ( (1 << ROW_2) != 0)
	{
		//keyPressed = '4';
	}
}

// Column 2
ISR(INT1_vect)
{
	keyPressed = 1;
}

// Column 3
ISR(INT2_vect)
{
	keyPressed = 1;
}

// Column 4
ISR(INT3_vect)
{
	keyPressed = 1;
}