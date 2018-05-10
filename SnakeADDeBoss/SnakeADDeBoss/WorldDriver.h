 #ifndef WORLDDRIVER_H_
 #define WORLDDRIVER_H_

void DrawIntroScreen(unsigned char introScreen[]);
void DrawHighscoreText(unsigned char highscoreText[]);
void DrawCharacter(unsigned char number[], char x, char y, int arrayLength);
void DrawPixel(unsigned char x, unsigned char y, unsigned char* world);
void DrawDot(unsigned char x, unsigned char y, unsigned char* world);
void DrawFood(unsigned char x, unsigned char y, unsigned char* world);
void RenderWorld(unsigned char* world);

 #endif