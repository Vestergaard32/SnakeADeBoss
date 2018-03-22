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
#define CE_BIT 1 // PA1
#define DC_BIT 3 // PA3
//#define DIN_BIT 3 
#define LIGHT_BIT 4 // PA4
//#define CLK_BIT 5 



void initDisplay()
{
	SPI_MasterInit();
	
	// Set port to output
	DDRA |= 0b00111111;
	
	// Set bits to high (active low)
	PORTA = ((1 << RST_BIT) | (1 << CE_BIT) | (1 << DC_BIT) & ~(1 << LIGHT_BIT));
	//PORTA |= 0b00111111;
	
	resetDisplay();
	
	sendIntruction(0b00100000); // Use basic instruction set
	sendIntruction(0b00001100); // Set display mode normal
}


void resetDisplay()
{
	// Set RES low
	PORTA &= ~(1 << RST_BIT);
		
	// Delay of min 100 ns (0,1ms) p.20
	_delay_us(1);
		
	// Set RES high
	PORTA |= (1 << RST_BIT);
}

void sendIntruction(unsigned char cmd)
{
	// Set chip enable (CE) to low
	// This must be done in order to clock in
	// Data
	PORTA &= ~(1 << CE_BIT);
	
	// Set DC low, Command
	PORTA &= ~(1 << DC_BIT);
	
	SPI_MasterTransmit(cmd);
	
	// CE must be set to high after transmission is done
	PORTA |= 1 << CE_BIT;
}

void sendData(unsigned char data)
{
	
}