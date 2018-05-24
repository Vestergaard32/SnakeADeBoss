#ifndef BITMAPS_H_
#define BITMAPS_H_

/*
	This file contains arrays of bytes representing various different
	images and characters used throughout the game
*/

unsigned char IntroScreenImage[]=
{		
	0x00,0x70,0xF8,0xD8,0x98,0x00,0xF0,0xF8,0x18,0xF8,0xF0,0x00,0x00,0xF0,0xF8,0x98,
	0xF8,0xF0,0x00,0x00,0xF8,0xF8,0x40,0xF0,0xF8,0x18,0x08,0x00,0xF0,0xF8,0xD8,0xD8,
	0x00,0x00,0x00,0x00,0x00,0xF0,0xF8,0x98,0xF8,0xF0,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x06,0x06,0x06,0x03,0x03,0x00,0x07,0x07,0x00,0x07,0x07,0x00,
	0x00,0x07,0x07,0x01,0x07,0x07,0x00,0x00,0x07,0x07,0x00,0x03,0x07,0x07,0x04,0x00,
	0x03,0x07,0x06,0x06,0x00,0x00,0x00,0x00,0x00,0x87,0x87,0x81,0x87,0x87,0x80,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x80,0x80,0x80,
	0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x80,0x80,0x00,0x00,
	0x80,0x80,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7F,0x7F,0x01,
	0x61,0x61,0x73,0x3F,0x1E,0x3C,0x7E,0x66,0x6E,0x6E,0x0C,0x00,0x00,0x00,0x00,0x00,
	0x7F,0x7F,0x01,0x6D,0x7F,0x3B,0x3C,0x7E,0x66,0x66,0x7E,0x3C,0x00,0x60,0x67,0x6F,
	0x3D,0x39,0x60,0x67,0x6F,0x3D,0x39,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xF8,
	0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,
	0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,
	0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0xF8,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xE0,
	0xE0,0x60,0x60,0x60,0x60,0x60,0x60,0x60,0x60,0x60,0x60,0x7E,0x7E,0x06,0x06,0x06,
	0x06,0x06,0x06,0x00,0x00,0x00,0x00,0x02,0x05,0x02,0x00,0x00,0xFF,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3F,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x26,
	0x26,0x26,0x26,0x27,0x27,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,
	0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,
	0x3F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
};

unsigned char HighscoreText[]=
{
	0x00,0x00,0x00,0x00,0x00,0x00,0xF8,0xF8,0x80,0x80,0x80,0x80,0x80,0x80,0xF8,0xF8,
	0x00,0x00,0xD8,0xD8,0x00,0x00,0x80,0xC0,0xC0,0xC0,0xC0,0x80,0x00,0x00,0xFC,0xFC,
	0x80,0xC0,0xC0,0xC0,0x80,0x00,0x00,0xE0,0xF0,0xB8,0x98,0x98,0x98,0x10,0x00,0x00,
	0x00,0x80,0xC0,0xC0,0xC0,0xC0,0x80,0x00,0x00,0x80,0xC0,0xC0,0xC0,0xC0,0x00,0x00,
	0xC0,0xC0,0x80,0xC0,0xC0,0xC0,0x00,0x00,0x80,0xC0,0xC0,0xC0,0xC0,0x80,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3F,0x3F,0x01,0x01,0x01,0x01,
	0x01,0x01,0x3F,0x3F,0x00,0x00,0x3F,0x3F,0x00,0x1F,0x3F,0x31,0x30,0xB8,0xFF,0xFF,
	0x00,0x00,0x3F,0x3F,0x01,0x00,0x00,0x3F,0x3F,0x00,0x1C,0x3C,0x31,0x31,0x31,0x31,
	0x19,0x1F,0x0F,0x00,0x0E,0x1F,0x31,0x30,0x30,0x39,0x19,0x00,0x0F,0x1F,0x31,0x30,
	0x30,0x1F,0x0F,0x00,0x3F,0x3F,0x01,0x00,0x03,0x03,0x00,0x0F,0x1F,0x3D,0x36,0x36,
	0x33,0x13,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0x03,0x03,
	0x03,0x03,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, '\\'
};

/* Empty space */
unsigned char Space[]=
{
	0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,
};

/* 0 */
unsigned char Zero[]=
{
	0x10,0x10,0x7E,0xFF,0xD3,0xFF,0x7E,0x10,
};

/* 1 */
unsigned char One[]=
{
	0x10,0xD6,0xD6,0xFF,0xFF,0xD0,0xD0,0x10,
};

/* 2 */
unsigned char Two[]=
{
	0x10,0xF6,0xF6,0xD3,0xDB,0xDF,0xD6,0x10,
};

/* 3 */
unsigned char Three[]=
{
	0x10,0x10,0x76,0xD3,0xDB,0xFF,0x76,0x10,
};

/* 4 */
unsigned char Four[]=
{
	0x10,0x30,0x38,0x3C,0x36,0xFF,0xFF,0x30,
};

/* 5 */
unsigned char Five[]=
{
	0x10,0x10,0x7F,0xDF,0xDB,0xFB,0x73,0x10,
};

/* 6 */
unsigned char Six[]=
{
	0x10,0x10,0x78,0xFC,0xDE,0xFB,0x71,0x10,
};

/* 7 */
unsigned char Seven[]=
{
	0x10,0x10,0x13,0xD3,0xF3,0x3B,0x17,0x13,
};

/* 8 */
unsigned char Eight[]=
{
	0x10,0x10,0x76,0xFF,0xDB,0xFF,0x76,0x10,
};

/* 9 */
unsigned char Nine[]=
{
	0x10,0x10,0x1E,0x9F,0xDB,0x7F,0x1E,0x10,
};

/* - */
unsigned char Dash[]=
{
	0x10,0x10,0x30,0x30,0x30,0x30,0x10,0x10,
};

/* . */
unsigned char Dot[]=
{
	0x10,0x10,0x90,0x10,0x10,0x10,0x10,0x10,
};

unsigned char* CharacterMapper[10] = {
	Zero, One, Two, Three, Four, Five, Six, Seven, Eight, Nine
};

#endif /* BITMAPS_H_ */