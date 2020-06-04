#include <tm4c123gh6pm.h>
#include <string.h>
#include <stdlib.h>
#include "mainUART.H"
#include "keybad.h"
#include "room.h"
#include "UARTorderProcessing.h"
#include "pwChecker.h"
#include "solonoid.h"
 int main ()
 {
	 uart0_Init();
	 keypad_init();
	 Solenoid_Init();
	 
	 char * PcOrder = readString('m');
	 struct room r [10];
	 pcOrder_Processing_2 (PcOrder,r);
	  while (1)
		{
			//if keybad.readPw = room password : open solonoid
			if (checkPassword(keypad_readPw(4),r[4]))
				GPIOF->DATA |= 0X08 ;
			
		}
		
 }
 
 