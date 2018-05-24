 #ifndef WORLDDRIVER_H_
 #define WORLDDRIVER_H_

// Draw the intro screen at the beginning of the game
void DrawIntroScreen(unsigned char introScreen[]);

// Draw the text for "highscore" displayed at the end of a game
void DrawHighscoreText(unsigned char highscoreText[]);

// Draw a specific character at an x, y position on the display
void DrawCharacter(unsigned char number[], char x, char y, int arrayLength);

// Draw a single dot at a specific x, y position in the world
void DrawPixel(unsigned char x, unsigned char y, unsigned char* world);

// Draw a 2x2 dot at a specific x, y position in the world
void DrawDot(unsigned char x, unsigned char y, unsigned char* world);

// Draw food image at a specific x, y position in the world
void DrawFood(unsigned char x, unsigned char y, unsigned char* world);

// Render the entire world image for the current framwe
void RenderWorld(unsigned char* world);

 #endif