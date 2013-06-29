//se fichier definie la fonction thread_tamagochi ainsi que les fonctions qu'elle utilise

#include <time.h>

#include "../classe/fonctionalite.h"
#include "../classe/liste.h"
#include "global.h"

#define CYCLE 1 //duré d'un cycle de mise à jour en seconde
#define DURE_JOUR 24 //nombre de cycle en une journé
#define DURE_PRODUCTION (DURE_JOUR / 4) //duré d'un cycle de production en cycle (ingurgistation, digestion , evacuation)
#define DURE_DIGESTION ((DURE_PRODUCTION /3)//nombre de cycle avant le déclanchement de la digestion
#define DURE_EVACUATION (DURE_PRODUCTION - DURE_DIGESTION)//nombre de cycle avant le déclanchement de la digestion
#define DURE_HUMEUR (DURE_JOUR / 6) //nombre de cycle avant la mise a jour d'humeur
#define DURE_POID  DURE_JOUR// nombre de cycle avant la mise a jour de poid



void * thread_tamagochi(void * arg)
{

  int diff, nb_cycle;
  time_t temps1, temps2;
  liste * debut_fonctionalite = NULL;

  //creation liste
  debut_fonctionalite = liste_make();
  liste_init(debut_fonctionalite, NULL, 0);
  //ajout fonctionalite



  nb_cycle = 0;
  temps2 = time(NULL);
  //lancement de la boucle evenementielle
  while(eteindre){
    if(alive){
      temps1 = time(NULL);
      diff = difftime(temps1,temps2);
      if(diff >= CYCLE){
	temps2 = temps1;
	nb_cycle ++;
	parcourir_fonctionalite(debut_fonctionalite, nb_cycle);
      }
    }
  }
  return 0;
}
