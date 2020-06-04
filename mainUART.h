#ifndef  __MAINUART_H__
#define  __MAINUART_H__

void uart0_Init (void);
char readChar(void);
char* readString(char delimiter);
void printString(char * string);
#endif
