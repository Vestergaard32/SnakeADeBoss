#ifndef FLASHDRIVER_H_
#define FLASHDRIVER_H_

/*
	The FlashDriver is used to save highscores to non-volatile flash memory
*/

// Save top 3 highscore data to flash
void FlashWrite(unsigned char* dataptr);

// Read top 3 highscore data from flash
void FlashRead(unsigned char* dataptr);

#endif /* FLASHDRIVER_H_ */