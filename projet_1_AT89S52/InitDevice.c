#include <REGX52.H>
#include "InitDevice.h"

void initDevice(void){
     permetion_interrupt();
	 configuration_timer0();
	 configuration_timer1();
}

void configuration_timer0(void){
   //CKCON =   mac dinh chia cho 12
   TMOD	&= ~0x0F;  // cac bits poids faible cua timer0 o muc 0
   TMOD |= 0x01;	// mode 1 => 01 cho 2 bits cuoi
   // TL0, TH0
   TL0= 0x63;
   TH0 = 0xC5;
   TR0 = 1;
}

void configuration_timer1(void){
   //CKCON =   mac dinh chia cho 12
	// khoi tao UART
	SM1 = 1;     //	 UART en mode 1
	SM0 = 0;     // 
	TMOD &= 0x0F; // xoa cac bit poids fort giu lai bits poids faible
	TMOD |= 0x20; // 8 bits auto reload

	TH1 = 0xEA;     ;	//tinh toan de co toc do baud la 2400
	TR1 = 1;         // lancer timer1
	SBUF = 'C';
	SBUF = '5';
}
void permetion_interrupt(void){
   	// interruption
	IT0 =1;
	ET0 =1;       // ET2 = 1 interruption du Timer2
	EA = 1;       // EA =1 permetre l'interruption
}