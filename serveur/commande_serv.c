#include <string.h>
#include <stdlib.h>

#include "global.h"
#include "../classe/variable_etat.h"
#include "../classe/liste.h"
#include "../classe/nourriture.h"
#include "../classe/commande.h"


void manger_gout(char * chaine, int gout);


void sortir(char arguments[12][MAX], int nb_arguments, void * retour, liste * liste_arg)
{
  strcpy((char*)retour, "exit");
}


void halt(char arguments[12][MAX], int nb_arguments, void * retour, liste * liste_arg)
{
  strcpy((char*)retour, "halt");
}

void creer(char arguments[12][MAX], int nb_arguments, void * retour, liste * liste_arg)
{
  liste * courant = debut_nourriture;
  
  if(alive != 0){
    strcpy((char*)retour, "tamagochi déjà vivant");
  }
  else{
    //initialisation des varables d'états
    alive = 1;
    variable_etat_initialiser(niv_faim, 4);
    variable_etat_initialiser(humeur, 50);
    variable_etat_initialiser(nourriture_ingurgite, 0);
    poid = POID_DEPART;
    poid_dejection = 0;
    proprete = 4;
    verrou_ingurgitation = 0;
    verrou_digestion = 0;
    //initialisation des gouts
    while(liste_obtenir_suivant(courant) != NULL){
      courant = liste_obtenir_suivant(courant);
      nourriture_modifier_gout(liste_obtenir_valeur(courant), (rand() % (MAX_GOUT - MIN_GOUT + 1)) + MIN_GOUT);
    }
    strcpy((char*)retour, "tamagochi créé");
  }

}

void manger(char arguments[12][MAX], int nb_arguments, void * retour, liste * liste_arg){
  nourriture * aliment = NULL;
  int nutriment;
  
  if(alive){
    if(nb_arguments != 2)
      strcpy(retour, "nombre d'arguments invalides");
    else{
      aliment = chercher_nourriture(debut_nourriture, arguments[1]);
      if(aliment == NULL)
	strcpy(retour, "argument invalide");
      else{
	nutriment = nourriture_obtenir_nutriment(aliment);
	//phase normal, le tamagochi ingurgite la nourriture la nouriture est stockée dans l'estomac et l'humeur du tamagochi évolue. On indique qu'une phase d'ingurgitation commence
	if((variable_etat_obtenir_valeur(nourriture_ingurgite) + nutriment) < CAPACITE_ESTOMAC){

	  variable_etat_ajouter_valeur(nourriture_ingurgite, nutriment);
	  variable_etat_actualiser_temps(nourriture_ingurgite);
	  variable_etat_ajouter_valeur(humeur, nourriture_obtenir_gout(aliment));
	  variable_etat_actualiser_temps(humeur);

	  if(nutriment >= 4 && variable_etat_obtenir_valeur(niv_faim) < 5){
	      variable_etat_ajouter_valeur(niv_faim, 1);	  
	      variable_etat_actualiser_temps(niv_faim);
	    }
	  verrou_ingurgitation = 1;
	  strcpy(retour, "j'ai mangé");
	}
	//si l'estomac est plein, phase de rejet, l'estomac se vide, un sentiment de faim se crée, on indique que la phase d'ingurgitation est intérompu
	else{

	  variable_etat_ajouter_valeur(humeur,-10);
	  variable_etat_initialiser(nourriture_ingurgite, 0);
	  variable_etat_ajouter_valeur(niv_faim, -1);
	  verrou_ingurgitation = 0;
	  strcpy(retour, "nourriture régurgitée");
	}
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
