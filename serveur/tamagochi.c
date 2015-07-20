//ce fichier defini la fonction thread_tamagochi

#include <time.h>

#include "fonctionnalite_tamagochi.h"
#include "../classe/fonctionnalite.h"
#include "../classe/liste.h"
#include "global.h"


void * thread_tamagochi(void * arg)
{

  int diff, nb_cycle;
  time_t temps1, temps2;
  liste * debut_fonctionnalite = NULL;

  //creation liste
  debut_fonctionnalite = liste_make();
  liste_init(debut_fonctionnalite, NULL, 0);
  //ajout fonctionnalite
  //  ajouter_fonctionnalite(debut_fonctionnalite, 1, compteur_cycle);
  ajouter_fonctionnalite(debut_fonctionnalite, 1, gestion_prod);
  ajouter_fonctionnalite(debut_fonctionnalite, 1, gestion_faim);
  ajouter_fonctionnalite(debut_fonctionnalite, DURE_POID, gestion_poid);
  ajouter_fonctionnalite(debut_fonctionnalite, 1, gestion_etat);

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
	parcourir_fonctionnalite(debut_fonctionnalite, nb_cycle);
      }
    }
  }
  return 0;
}
