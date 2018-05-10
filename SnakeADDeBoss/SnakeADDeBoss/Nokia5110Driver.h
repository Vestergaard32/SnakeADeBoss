#ifndef NOKIA5110DRIVER_H_
#define NOKIA5110DRIVER_H_

void initDisplay(); 
void clearDisplay();
void resetDisplay();
void setCursor(char x, char y);
void sendIntruction(unsigned char);
void sendData(unsigned char);

#endif /* NOKIA5110DRIVER_H_ */