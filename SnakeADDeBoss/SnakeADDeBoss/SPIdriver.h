/*
 * SPIdriver.h
 *
 * Created: 22-Mar-18 10:07:57 AM
 *  Author: mpkon
 */ 


#ifndef SPIDRIVER_H_
#define SPIDRIVER_H_

void SPI_MasterInit(void);
void SPI_MasterTransmit(char data);

#endif /* SPIDRIVER_H_ */