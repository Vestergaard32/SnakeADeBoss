/*
 * FlashDriver.c
 *
 * Created: 03-May-18 8:29:20 AM
 *  Author: mpkon
 */ 

#include "FlashDriver.h"
#include <avr/io.h>
#include <avr/boot.h>
#include <avr/pgmspace.h>

#define PAGE_NUMBER 253
#define PAGE_SIZE_BYTES 256


__attribute__((section (".flashwriter")))
void FlashWrite(unsigned char* dataptr)
{
	boot_page_erase( (long) PAGE_NUMBER * (long) PAGE_SIZE_BYTES);
	boot_spm_busy_wait();
	
	boot_page_fill(0, dataptr[0]);
	boot_page_fill(2, dataptr[1]);
	boot_page_fill(4, dataptr[2]);
	
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
	
	dataptr[0] = pgm_read_byte_far(first);
	dataptr[1] = pgm_read_byte_far(second);
	dataptr[2] = pgm_read_byte_far(third);
}