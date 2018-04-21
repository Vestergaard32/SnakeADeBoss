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

char Column1Characters[4] = { '1', '4', '7', '*' };
char Column2Characters[4] = { '2', '5', '8', '0' };
char Column3Characters[4] = { '3', '6', '9', '#' };
char Column4Characters[4] = { 'A', 'B', 'C', 'D' };

char characterColumns[4][4] = {
	{ '1', '4', '7', '*' },
	{ '2', '5', '8', '0' },
	{ '3', '6', '9', '#' },
	{ 'A', 'B', 'C', 'D' }
}

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

	//PORTB = 0xFF;
}

char GetKey()
{
	// Scan Column 1 (1, 4, 7, and *)
	PORTD &= ~(1 << COLUMN_1);
	_delay_ms(1);

	for (int columnIndex = 0; columnIndex < 4: columnIndex++)
	{
		// Key '1'
		if ((PINA & (1 << ROW_1)) == 0)
		{
			return characterColumns[columnIndex][0];
		}

		/*
		// Key '4'
		if ((PINA & (1 << ROW_2)) == 0)
		{
			keyPressed = '4';
		}

		// Key '7'
		if ((PINC & (1 << ROW_3)) == 0)
		{
			keyPressed = '7';
		}

		// Key '*'
		if ((PINC & (1 << ROW_4)) == 0)
		{
			keyPressed = '*';
		}
		*/
	}



	return keyPressed;
}