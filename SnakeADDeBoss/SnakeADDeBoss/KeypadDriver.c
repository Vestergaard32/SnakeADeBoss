/*
 * KeypadDriver.c
 *
 * Created: 19-04-2018 08:32:20
 *  Author: CodingBeagle
 */ 

#include <avr/io.h>
#include <avr/cpufunc.h>
#define F_CPU 16000000
#include <util/delay.h>

#define ROW_1 4
#define ROW_2 6
#define ROW_3 7
#define ROW_4 5

#define COLUMN_1 0
#define COLUMN_2 1
#define COLUMN_3 2
#define COLUMN_4 3

char keyPressed = 0;

void InitKeypad()
{
	// Setup input pins to keyboard
	// These are pins PA6 (Row 2) and PA4 (Row 1), and C7 (Row 3) and C5 (Row 4)
	DDRA &= ~(0b01010000);

	DDRC &= ~(0b10100000);

	// Setup output pins to keyboard
	// PD0 = Column 1, PD1 = Column 2, PD2 = Column 3, PD3 = Column 4
	DDRD |= 0b00001111;
	PORTD |= 0b00001111;

	DDRB = 0b11111111;
}

char GetKey()
{
	// Scan Column 1
	PORTD &= ~(1 << COLUMN_1);

	_delay_ms(20);

	PORTB = 0x00;

	_delay_ms(20);

	// 4 Key

	char inputStateC = PINC;


	// 7 Key

	if ((inputStateC & (1 << ROW_3)))
	{
		keyPressed = 1;
		PORTB |= 0xFF;
	}

	if ((inputStateC & (1 << ROW_4)))
	{
		keyPressed = 1;
		PORTB |= 0xFF;
	}

	/*
	if (PINC)
	{
		keyPressed = 1;
	}
	*/

	/*
	
	if ((PINA & (1 << ROW_2)) != 0)
	{
		keyPressed = 1;
	}

	if ((PINC & (1 << ROW_3)) != 0)
	{
		keyPressed = 1;
	}

	if ((PINC & (1 << ROW_4)) != 0)
	{
		keyPressed = 1;
	}*/

	return keyPressed;
}