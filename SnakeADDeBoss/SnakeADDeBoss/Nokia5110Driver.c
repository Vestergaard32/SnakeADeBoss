/*
 * Nokia5110Driver.c
 *
 * Created: 22-Mar-18 8:30:26 AM
 *  Author: mpkon
 */ 

/*
  [Display]        [PortA]
  RST	------  PA0		Reset
  CE	------  PA1		Chip enable
  DC	------  PA2		Data (low) Command (High)
  DIN	------  PA3		Serial Data In
  CLK	------  PA5
  VCC	------  3.3V
  LIGHT -----	PA4
  GND	------  GND

*/
#include <avr/io.h>
#include <avr/cpufunc.h>
#define F_CPU 16000000
#include <util/delay.h>
#include "Nokia5110Driver.h"
#include "SPIdriver.h"

#define RST_BIT 0 // PA0
#define DC_BIT 1 // PA1
#define LIGHT_BIT 2 // PA2

void initDisplay()
{
	SPI_MasterInit();
	
	// Set port to output
	DDRA = 0xFF;
	
	// Set bits to high (active low)
	PORTA |= (1 << RST_BIT);
	PORTA |= (1 << DC_BIT);

	// Turn on light
	PORTA &= ~(1 << LIGHT_BIT);
	
	// Required display reset
	// This has to be done before doing
	// Anything else with the display
	resetDisplay();
	
	// Use extended instruction set
	sendIntruction(0x21);

	// Here we control operation voltage of the LCD
	// We set it to 6V (the minimum allowed voltage range)
	// If you do not set a VOP value, the internal voltage generator
	// Will be switched off, and thus the display won't function.
	sendIntruction(0xC0);

	// We set the bias voltage levels
	// The bias value is taken after the
	// optimum bias value described in official
	// data sheet.
	sendIntruction(0x13);

	// Use basic instruction set
	sendIntruction(0x20);

	// Set display mode normal
	sendIntruction(0b00001100);
	
	// Clear the display to make sure
	// No pixels are alive on startup
	clearDisplay();

	sendData(0x1F);
	sendData(0x1F); // For some reason, the first data draw is not counted
}


void resetDisplay()
{
	// Set RES low
	PORTA &= ~(1 << RST_BIT);
		
	// Delay of min 100 ns (0,1ms) p.20
	_delay_ms(100);
		
	// Set RES high
	PORTA |= (1 << RST_BIT);
}

void sendIntruction(unsigned char cmd)
{
	// Set DC low, Command
	PORTA &= ~(1 << DC_BIT);
	SPI_MasterTransmit(cmd);
	PORTA |= 1 << DC_BIT;
}

void sendData(unsigned char data)
{	
	PORTA |= 1 << DC_BIT;
	SPI_MasterTransmit(data);
}

void clearDisplay()
{
	for (int k=0; k<=503; k++)
	{
		sendData(0x00);
	}
}