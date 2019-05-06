#include <REGX52.H>
#include "Test_pin.h"
#include "InitDevice.h"
#include "variables_globales.h"
#include "moteur.h"
#include "moteur_port.h"


void INTERRUPT0 (void)	 interrupt 1
{	
	//TEST = !TEST;
	TL0= 0x68;
    TH0 = 0xC5;
	TF0 = 0;
	new_task=1;
}

void INTERRUPT2(void) interrupt 5
{  
   TF2 = 0;		   // co bao
   ChangePhase();
}

void INTERRUPT_UART(void) interrupt 4
{  
   if(TI == 1){
     TI = 0;
	 // gui lai la ok

   }
   else if(RI == 1){
     RI = 0;
	 // nhan ve 1 so thap phan xong roi dieu khien timer 2 de dc 1/4 chu ki la x*100 us
	 val = SBUF;
	 
   }
}
