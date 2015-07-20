#include <string.h>


#include "../classe/variable_etat.h"
#include "../classe/nourriture.h"
#include "../classe/commande.h"
#include "etat.h"


void etat_nourriture(char * nom, char * retour);
void init_carac(char * carac, int nb);

void etat(char arguments[12][MAX], int nb_arguments, void * retour, liste * liste_arg)
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
void etat_faim(char arguments[12][MAX], int nb_arguments, void * retour, liste * liste_arg)
{
  init_carac(retour, variable_etat_obtenir_valeur(niv_faim));
}

void etat_proprete(char arguments[12][MAX], int nb_arguments, void * retour, liste * liste_arg)
{
  init_carac(retour, proprete);
}

void etat_humeur(char arguments[12][MAX], int nb_arguments, void * retour, liste * liste_arg)
{
  init_carac(retour, variable_etat_obtenir_valeur(humeur));
}

void etat_nourriture_ingurgite(char arguments[12][MAX], int nb_arguments, void * retour, liste * liste_arg)
{
  init_carac(retour, variable_etat_obtenir_valeur(nourriture_ingurgite));
}

void etat_poid(char arguments[12][MAX], int nb_arguments, void * retour, liste * liste_arg)
{
  init_carac(retour, poid);
}

void etat_poid_dejection(char arguments[12][MAX], int nb_arguments, void * retour, liste * liste_arg)
{
  init_carac(retour, poid_dejection);
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
