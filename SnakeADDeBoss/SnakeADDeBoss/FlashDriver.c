#include "FlashDriver.h"
#include <avr/io.h>
#include <avr/boot.h>
#include <avr/pgmspace.h>

#define PAGE_NUMBER 253
#define PAGE_SIZE_BYTES 256

// Flashwriter section equals address 0x1FF00
__attribute__((section (".flashwriter")))
void FlashWrite(unsigned char* dataptr)
{
	// Erase entire page
	boot_page_erase( (long) PAGE_NUMBER * (long) PAGE_SIZE_BYTES);
	boot_spm_busy_wait();
	
	// Save top 1 highscore
	boot_page_fill(0, dataptr[0]);

	// Save top 2 highscore
	boot_page_fill(2, dataptr[1]);

	// Save top 3 highscore
	boot_page_fill(4, dataptr[2]);
	
	// Write highscore data to page
	boot_page_write((long) PAGE_NUMBER * (long) PAGE_SIZE_BYTES);
	boot_spm_busy_wait();
	
	boot_rww_enable();
	boot_spm_busy_wait();	
}

void FlashRead(unsigned char* dataptr)
{
	long first = (long) PAGE_NUMBER* (long) PAGE_SIZE_BYTES;
	long second = ((long) PAGE_NUMBER * (long)PAGE_SIZE_BYTES)+2;
	long third = ((long) PAGE_NUMBER* (long)PAGE_SIZE_BYTES)+4;
	
	// read top 1 highscore
	dataptr[0] = pgm_read_byte_far(first);

	// read top 2 highscore
	dataptr[1] = pgm_read_byte_far(second);

	// read top 3 highscore
	dataptr[2] = pgm_read_byte_far(third);
}