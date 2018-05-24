#ifndef NOKIA5110DRIVER_H_
#define NOKIA5110DRIVER_H_

// Set up all the pins, SPI communication,
// and display configurations
void initDisplay(); 

// Clear the display (all clear to white)
void clearDisplay();

// Reset Command for display
// This is required during startup of the display
void resetDisplay();

// Set the pixel position of the cursor on the display
// This can be used to draw dots at specific points
void setCursor(char x, char y);

// Send a display instruction to the display using SPI
void sendIntruction(unsigned char);

// Send data (such as video data) to the display using SPI
void sendData(unsigned char);

#endif /* NOKIA5110DRIVER_H_ */