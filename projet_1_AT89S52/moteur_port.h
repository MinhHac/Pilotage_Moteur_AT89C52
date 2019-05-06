#ifndef MOTEUR_PORT_H_
#define MOTEUR_PORT_H_

#include <REGX52.H>

// signaux sorties
sbit  S1 = P1^0;
sbit  S2 = P1^1;
sbit  S3 = P1^2;
sbit  S4 = P1^3;

// bouton pourssoir

sbit BUTTON = P0^2;

//P1MDOUT |= 0x0F; //les 4 bits poid faible de P1 sont en PUSH PULL


#define	Phase1;		S1 =0;S2 =0;S3 =1;S4 =1;
#define	Phase2;		S1 =1;S2 =0;S3 =0;S4 =1;
#define	Phase3;		S1 =1;S2 =1;S3 =0;S4 =0;
#define	Phase4;		S1 =0;S2 =1;S3 =1;S4 =0;



#endif 