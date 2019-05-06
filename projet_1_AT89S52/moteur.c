#include <REGX52.H>
#include "moteur.h"
#include "moteur_port.h"
#include "variables_globales.h"
#include "Test_pin.h"

void InitMoteur(void){  // configurer le timer 2

// co mot cai co, neu init roi thi khoi can init nua
// cai dat Timer 2

	T2MOD = 0x00;
	          //	DCEN =0 et T2OE =0
	T2CON = 0x00;	  // mode 2 -16bits auto reload
	RCAP2L =0x18;
	RCAP2H =0xFC;

	TR2 = 1;        // lancer timer2 = moteur tourne au demarrage du microcontroleur
	ET2=1;          //Timer 2 Interrupt Enable
}

void ChangePhase(void){
     switch(etat_phase) {
		case 0: {
		        TEST =!TEST;
		        Phase1;
			
				break;
		}

		case 1: {
				Phase2;
				break;
		}

		case 2: {
				 Phase3;
				break;
		}

		case 3: {
				 Phase4;
				break;
		}
	}

	etat_phase++;
	if(etat_phase==4) etat_phase =0;
}

void demarage_arret_Moteur(void){
   	 TR2 = !TR2;
}