#include <string.h>

#include "global.h"
#include "../classe/variable_etat.h"
#include "../classe/liste.h"
#include "../classe/nourriture.h"


char* sortir(char * chaine_env, char arguments[MAX][12], int nb_arguments)
{
  strcpy(chaine_env, "exit");
  return chaine_env;
}

char* halt(char * chaine_env, char arguments[MAX][12], int nb_arguments)
{
  strcpy(chaine_env, "halt");
  return chaine_env;
}

char * testarg(char * chaine_env, char arguments[MAX][12], int nb_arguments)
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
  return chaine_env;
}


char* creer(char * chaine_env, char arguments[MAX][12], int nb_arguments){
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
  return chaine_env;
}
