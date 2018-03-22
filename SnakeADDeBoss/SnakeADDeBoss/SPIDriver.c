/*
 * SPIDriver.c
 *
 * Created: 22-Mar-18 10:08:22 AM
 *  Author: mpkon
 */ 
#include <avr/io.h>
#include <avr/cpufunc.h>
#define F_CPU 16000000
#include <util/delay.h>

#define DDR_SPI DDRB
#define DD_SS   0
#define DD_SCK  1
#define DD_MOSI 2
#define DD_MISO 3
#define DD_DORD 5

#define OUTPUT 0xFF
#define INPUT  0x00

void SPI_MasterInit(void)
{
	unsigned char sData = 0x00;		// SPI Data variable
	unsigned int  i		= 0;		// Variable for delay loop
	DDRD = OUTPUT;		  			// PORTD for Debugging
	PORTD = 0xF0;
	
	DDR_SPI = (1<<DD_DORD)|(1<<DD_MOSI)|(1<<DD_SCK)|(1<<DD_SS); //MOSI,SS & SCK output,others input
	SPCR = (1<<SPE)|(1<<MSTR)|(1<<SPR0);  		   //SPI, Master, clock = fck/16
}

char SPI_MasterReceive(void)
{
	
	while(!(SPSR & (1<<SPIF)));				// Wait for reception complete
	return SPDR;   							// Return Data Register
}

void SPI_MasterTransmit(char cData)
{
	SPDR = cData;			 	   			// Start transmission
	while((SPSR & (1<<SPIF)) != SPIF);				// Wait for transmission complete
	cData = SPDR;
}

void delay(unsigned int val)
{
	unsigned int i = 0;
	for(i=0;i< val; i++)
	{
		_NOP();
	}
}