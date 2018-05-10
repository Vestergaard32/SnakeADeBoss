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

void SPI_MasterInit(void)
{	
	DDR_SPI = (1<<DD_MOSI)|(1<<DD_SCK)|(1<<DD_SS); //MOSI,SS & SCK output,others input
	SPCR = (1<<SPE)|(1<<MSTR)|(1<<SPR0);  		   //SPI, Master, clock = fck/16
}

void SPI_MasterTransmit(char cData)
{
	PORTB &= ~(1 << DD_SS);

	// Start transmission
	SPDR = cData;			
	
	// k variable increment is to avoid C compiler optimization
	int k = 0;
	while( !(SPSR & (1<<SPIF)) ) // Wait for transmission complete
	{
		k++;
	}			
	
	cData = SPDR;

	PORTB|= 1 << DD_SS;
}
