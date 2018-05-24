#ifndef SPIDRIVER_H_
#define SPIDRIVER_H_

// Initialize SPI configuration
void SPI_MasterInit(void);

// Send data over SPI connection
void SPI_MasterTransmit(char data);

#endif /* SPIDRIVER_H_ */