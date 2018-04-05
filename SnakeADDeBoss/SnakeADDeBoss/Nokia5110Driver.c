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
	PORTA &= ~(1 << LIGHT_BIT);
	
	resetDisplay();
	
	sendIntruction(0x21);
	sendIntruction(0xC0);
	sendIntruction(0x07);
	sendIntruction(0x13);
	
	sendIntruction(0x20); // Use basic instruction set
	sendIntruction(0x0C); // Set display mode normal
	
	sendData(0x1F);
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