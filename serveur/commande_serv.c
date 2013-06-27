#include <string.h>
#include <stdlib.h>

#include "global.h"
#include "../classe/variable_etat.h"
#include "../classe/liste.h"
#include "../classe/nourriture.h"
#include "../classe/commande.h"

void init_carac(char * carac, int nb);
void manger_gout(char * chaine, int gout);
void etat_nourriture(char * nom, char * retour);


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

    //initialisation des gouts
    while(liste_obtenir_suivant(courant) != NULL){
      courant = liste_obtenir_suivant(courant);
      nourriture_modifier_gout(liste_obtenir_valeur(courant), (rand() % (MAX_GOUT - MIN_GOUT + 1)) + MIN_GOUT);
    }
    strcpy((char*)retour, "tamagochi creé");
  }

}

void etat(char arguments[MAX][12], int nb_arguments, void * retour, liste * liste_arg)
{
  if(nb_arguments != 2)
    strcpy((char*)retour, "nb arguments invalides");
  else if(!alive)
    strcpy((char*)retour, "pas de tamagochi en vie");
  else{
    if(lancer_commande(liste_arg, arguments[1], NULL, 0, retour) == 1){
      etat_nourriture(arguments[1], retour);
      if(*(char*)retour == -1){
	strcpy((char *)retour, "argument invalide");
      }
    }
  }
}
void etat_faim(char arguments[MAX][12], int nb_arguments, void * retour, liste * liste_arg)
{
  init_carac(retour, variable_etat_obtenir_valeur(niv_faim));
}

void etat_humeur(char arguments[MAX][12], int nb_arguments, void * retour, liste * liste_arg)
{
  init_carac(retour, variable_etat_obtenir_valeur(humeur));
}

void etat_nourriture(char * nom, char * retour)
{
  int nutriment, gout;
  char carac[MAX];

  nourriture * aliment = chercher_nourriture(debut_nourriture, nom);
  if(aliment == NULL){
    retour[0] = -1;;
  }
  else{
    nutriment = nourriture_obtenir_nutriment(aliment);
    gout = nourriture_obtenir_gout(aliment);
    
    strcpy(retour, nom);
    strcat(retour, " gout = ");
    init_carac(carac, gout);
    strcat(retour, carac);
    strcat(retour, " nutriment = ");
    init_carac(carac, nutriment);
    strcat(retour, carac);
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











// transforme un nombre en chaine de caractere
void init_carac(char * carac, int nb)
{
  int u,d,c;
  int signe = 0;
  if(nb < 0){
    signe = 1;
    nb *= (-1);
  }
  
  u = nb % 10;
  d = ((nb % 100) - u)/10;
  c = ((nb % 1000) - (10 * d) - u)/100;
  if(signe == 0){
    carac[0] = c + 48;
    carac[1] = d + 48;
    carac[2] = u + 48;
    carac[3] = 0;
  }
  else{
    carac[0] = '-';
    carac[1] = c + 48;
    carac[2] = d + 48;
    carac[3] = u + 48;
    carac[4] = 0;
  }
} 
