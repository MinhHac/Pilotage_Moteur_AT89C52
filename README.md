# Pilotage_Moteur_AT89C52_C8051F930

* L’objectif est de piloter un moteur pas à pas possédant quatre phases, commandées par quatre broches du microcontrôleur.
Entre le moteur et le microcontrôleur un étage de puissance est intercalé afin de délivrer le courant nécessaire dans les inducteurs.
Les signaux de commande des phases en sorties du MCU doivent varier périodiquement (période T = 2.4ms).

* Logiciels utilisés : Keil C, Proteus, Simplicity.

* Langage utilisés:  C

* Résumé

 Etape 1 : Gestionnaire de tâche et timer 0.
 
 Programmer un ordonnanceur comportant 4 tâches synchronisées par le timer 0. 
 L’ordonnanceur devra exécuter une nouvelle tâche toutes les 9ms, ce qui signifie que la tâche numéro x sera exécutée toutes les 36ms. 

 Etape 2 : Librairie « Moteur »
 
 Le timer 2 est utilisé comme base de temps pour modifier les phases du moteur toutes les 600μs. Les broches P1.4, P1.5, P1.6 et P1.7 sont utilisées par ailleurs en sortie. Ecrire une librairie qui contient :

  • une fonction d’initialisation du moteur qui configure le timer 2.
               
  • l’ISR du timer 2 qui modifie les broches P1.0 , P1.1, P1.2 et P1.3.
               
  • une fonction d’arrêt et de démarrage du moteur.

 Etape 3 : Utilisation de la librairie dans l’ordonnanceur.
   
 Compléter l'ordonnanceur pour que la tâche 1 initialise le moteur (c’est-à-dire le timer 2) au démarrage du microcontrôleur. 
 Cette même tâche devra examiner l’état d’un bouton poussoir connecté sur la broche P0.2.L’activation du bouton poussoir devra démarrer le moteur s’il est à l’arrêt ou le stopper si le moteur est en rotation.

 Etape 4 : Pilotage de la vitesse du moteur à partir d’un terminal série.
     Un terminal de communication est connecté au microcontrôleur par la liaison série via le module UART0. Dans cette application le terminal permettra à un opérateur de transmettre un octet dont la valeur en décimal, notée x modifiera la vitesse de rotation du moteur. T/4 devra correspondre à x*100 μs

  
