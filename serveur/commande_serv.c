#include <string.h>
#include <stdlib.h>

#include "global.h"
#include "../classe/variable_etat.h"
#include "../classe/liste.h"
#include "../classe/nourriture.h"


void sortir(char * chaine_env, char arguments[MAX][12], int nb_arguments, void * retour)
{
  strcpy(chaine_env, "exit");
  *(char**)retour = chaine_env;
}

void halt(char * chaine_env, char arguments[MAX][12], int nb_arguments, void * retour)
{
  strcpy(chaine_env, "halt");
  *(char**)retour = chaine_env;
}

void testarg(char * chaine_env, char arguments[MAX][12], int nb_arguments, void * retour)
{
  if(nb_arguments != 2)
    strcpy(chaine_env, "nb arguments invalides");
  else{
    if(!strcmp(arguments[1], "a"))
      strcpy(chaine_env, "aaaaaaaaaa");
    else if(!strcmp(arguments[1], "b"))
      strcpy(chaine_env, "bbbbbbbbb");
    else
      strcpy(chaine_env, "argument invalide");
  }
  *(char**)retour = chaine_env;
}


void creer(char * chaine_env, char arguments[MAX][12], int nb_arguments, void * retour)
{
  liste * courant = debut_nourriture;
  
  if(alive != 0){
    strcpy(chaine_env, "tamagochi deja vivant");
  }
  else{
    //initialisation des varables d'états
    alive = 1;
    variable_etat_initialiser(niv_faim, 50);
    variable_etat_initialiser(humeur, 50);

    //initialisation des gouts
    while(liste_obtenir_suivant(courant) != NULL){
      courant = liste_obtenir_suivant(courant);
      nourriture_modifier_gout(liste_obtenir_valeur(courant), (rand() % (MAX_GOUT - MIN_GOUT + 1)) + MIN_GOUT);
    }
    strcpy(chaine_env, "tamagochi creé");
  }

  *(char**)retour = chaine_env;
}
