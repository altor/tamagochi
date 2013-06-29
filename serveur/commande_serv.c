#include <string.h>
#include <stdlib.h>

#include "global.h"
#include "../classe/variable_etat.h"
#include "../classe/liste.h"
#include "../classe/nourriture.h"
#include "../classe/commande.h"


void manger_gout(char * chaine, int gout);


void sortir(char arguments[MAX][12], int nb_arguments, void * retour, liste * liste_arg)
{
  strcpy((char*)retour, "exit");
}


void halt(char arguments[MAX][12], int nb_arguments, void * retour, liste * liste_arg)
{
  strcpy((char*)retour, "halt");
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
    variable_etat_initialiser(nourriture_ingurgite, 0);
    poid = POID_DEPART;
    poid_dejection = 0;
    verrou_ingurgitation = 0;
    verrou_digestion = 0;
    //initialisation des gouts
    while(liste_obtenir_suivant(courant) != NULL){
      courant = liste_obtenir_suivant(courant);
      nourriture_modifier_gout(liste_obtenir_valeur(courant), (rand() % (MAX_GOUT - MIN_GOUT + 1)) + MIN_GOUT);
    }
    strcpy((char*)retour, "tamagochi creé");
  }

}


void manger(char arguments[MAX][12], int nb_arguments, void * retour, liste * liste_arg)
{
  nourriture * aliment = NULL;
  int gout;
  if(alive){
    if(nb_arguments != 2)
      strcpy(retour, "nombre d'arguments invalides");
    else{
      aliment = chercher_nourriture(debut_nourriture, arguments[1]);
      if(aliment == NULL)
	strcpy(retour, "argument invalide");
      else{
	variable_etat_ajouter_valeur(niv_faim, nourriture_obtenir_nutriment(aliment));
	gout = nourriture_obtenir_gout(aliment);
	variable_etat_ajouter_valeur(humeur, gout);
	manger_gout(retour, gout);
      }
    }
  }
  else
    strcpy(retour, "pas de tamagochi en vie");

}
void manger_gout(char * chaine, int gout)
{
  if(gout > 8)
    strcpy(chaine, ">8");
  else if(gout > 6)
    strcpy(chaine, ">6");
  else if(gout > 4)
    strcpy(chaine, ">4");
  else if(gout > 2)
    strcpy(chaine, ">2");
  else if(gout > 0)
    strcpy(chaine, ">0");
  else if(gout > -2)
    strcpy(chaine, ">-2");
  else if(gout > -4)
    strcpy(chaine, ">-4");
  else if(gout > -6)
    strcpy(chaine, ">-6");
  else if(gout > -8)
    strcpy(chaine, ">-8");
  else if(gout > -10)
    strcpy(chaine, ">-10");
}











