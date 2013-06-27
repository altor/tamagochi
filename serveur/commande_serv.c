#include <string.h>
#include <stdlib.h>

#include "global.h"
#include "../classe/variable_etat.h"
#include "../classe/liste.h"
#include "../classe/nourriture.h"
#include "../classe/commande.h"

void sortir(char arguments[MAX][12], int nb_arguments, void * retour, liste * liste_arg)
{
  strcpy((char*)retour, "exit");
}


void halt(char arguments[MAX][12], int nb_arguments, void * retour, liste * liste_arg)
{
  strcpy((char*)retour, "halt");
}

void  testarg(char arguments[MAX][12], int nb_arguments, void * retour, liste * liste_arg)
{
  if(nb_arguments != 2)
    strcpy((char*)retour, "nb arguments invalides");
  
  else{
    if(lancer_commande(liste_arg, arguments[1], NULL, 0, retour) == 1)
      strcpy((char *)retour, "argument invalide");
  }
}

void testarg_a(char arguments[MAX][12], int nb_arguments, void * retour, liste * liste_arg)
{
  strcpy((char*)retour, "aaaaaaaa");
}

void testarg_b(char arguments[MAX][12], int nb_arguments, void * retour, liste * liste_arg)
{
  strcpy((char*)retour, "bbbbbbbbb");
}


void creer(char arguments[MAX][12], int nb_arguments, void * retour, liste * liste_arg)
{
  liste * courant = debut_nourriture;
  
  if(alive != 0){
    strcpy((char*)retour, "tamagochi deja vivant");
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
    strcpy((char*)retour, "tamagochi creé");
  }

}
