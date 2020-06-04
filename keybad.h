#ifndef  __KEYBAD_H__
#define  __KEYBAD_H__
#include <stdbool.h>

void delayUs(int n);
void delayMs(int n);
void keypad_init(void);
char keypad_getkey(void);
bool keypad_kbhit(void);
char* keypad_readPw( unsigned int noChars);






#endif
