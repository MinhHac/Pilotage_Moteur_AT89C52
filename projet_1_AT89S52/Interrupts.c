#include <REGX52.H>
#include "Test_pin.h"
#include "InitDevice.h"
#include "variables_globales.h"
#include "moteur.h"
#include "moteur_port.h"


void INTERRUPT0 (void)	 interrupt 1
{		TF0 = 0;
	    new_task=1;
}

void INTERRUPT2(void) interrupt 5
{  
   TF2 = 0;	
   ChangePhase2();	
   //TEST = !TEST; 
}

void INTERRUPT_UART(void) interrupt 4
{  	 //TEST =!TEST;
     static bit pass_T =0, pass_R=0;	 
	 if(TI==1){	         // fin de transmission
	    TI=0;
		if(pass_T == 0){
		  SBUF = 'A';
		  pass_T =1;
		}
		else {
		  pass_T=0;
		}
	 } 
     else if(RI == 1){   // fin de reception
	   RI = 0;  
	   if(pass_R==0){
	      val = SBUF;
		  //TEST=!TEST;
	      //val = 5;
	   }
	   else {
	   	  pass_R=0;
	   }
   }	  
}
