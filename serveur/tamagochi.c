//se fichier definie la fonction thread_tamagochi ainsi que les fonctions qu'elle utilise

#include <time.h>

#include "fonctionalite_tamagochi.h"
#include "../classe/fonctionalite.h"
#include "../classe/liste.h"
#include "global.h"





void * thread_tamagochi(void * arg)
{

  int diff, nb_cycle;
  time_t temps1, temps2;
  liste * debut_fonctionalite = NULL;

  //creation liste
  debut_fonctionalite = liste_make();
  liste_init(debut_fonctionalite, NULL, 0);
  //ajout fonctionalite
  //  ajouter_fonctionalite(debut_fonctionalite, 1, compteur_cycle);
  ajouter_fonctionalite(debut_fonctionalite, 1, gestion_prod);
  

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
