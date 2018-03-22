/*
 * Nokia5110Driver.h
 *
 * Created: 22-Mar-18 8:28:59 AM
 *  Author: mpkon
 */ 


#ifndef NOKIA5110DRIVER_H_
#define NOKIA5110DRIVER_H_

void initDisplay(); 
void resetDisplay();
void sendIntruction(unsigned char);
void sendData(unsigned char);



#endif /* NOKIA5110DRIVER_H_ */