#include <tm4c123gh6pm.h>
#include <stdbool.h>

void Solenoid_Init(void){
	volatile unsigned long delay;
  SYSCTL->RCGCGPIO |= 0x00000020;   // 1) F clock
  delay = SYSCTL->RCGCGPIO;         // delay  
  //GPIO_PORTF_LOCK_R = 0x4C4F434B; // 2) unlock PortF PF0 
	GPIOF->LOCK = 0x4C4F434B;
  //GPIO_PORTF_CR_R |= 0x1F;   	// allow changes to PF4-0  
  GPIOF->CR |= 0x1F; 	
 //GPIO_PORTF_AMSEL_R &= 0x00;     // 3) disable analog function
	GPIOF->AMSEL &= 0x00;
 // GPIO_PORTF_PCTL_R &= 0x00000000; // 4) GPIO clear bit PCTL 
	GPIOF->PCTL &= 0x00000000;
  //GPIO_PORTF_DIR_R &= ~0x11;      // 5.1) PF4,PF0 input,
  //GPIO_PORTF_DIR_R |= 0x08;       // 5.2) PF3 output 
	GPIOF->DIR |= 0x08;
  //GPIO_PORTF_AFSEL_R &= ~0x1F;    // 6) no alternate functions
	GPIOF->AFSEL &= ~0x1F;
  //GPIO_PORTF_PUR_R |= 0x11;       // enable pullup resistors on PF4,PF0   
  GPIOF->PUR 	|= 0x11;
  //GPIO_PORTF_DEN_R |= 0x1F;       // 7) enable digital pins PF4-PF0       
	GPIOF->DEN |= 0x1F;
}

bool CHECK_BIT(int var,int pos) {
    return ((var)>>(pos)) & 1;}
