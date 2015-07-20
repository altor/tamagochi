#include <string.h>
#include <stdlib.h>
#include "nourriture.h"

struct nourriture{
  char nom[512];
  int nutriment;
  int gout;
};

nourriture * nourriture_make()
{
  return malloc(sizeof(struct nourriture));
}

void nourriture_delete(nourriture * obj)
{
  free(obj);
}

void nourriture_init(nourriture * obj,char * nom, int nutriment)
{
  strcpy(obj->nom, nom);
  obj->nutriment = nutriment;
}
void nourriture_modifier_gout(nourriture * obj, int gout)
{
  obj->gout = gout;
}

int nourriture_obtenir_gout(nourriture * obj)
{
  return obj->gout;
}

int nourriture_obtenir_nutriment(nourriture * obj)
{
  return obj->nutriment;
}

char * nourriture_obtenir_nom(nourriture * obj)
{
  return obj->nom;
}

void ajouter_nourriture(liste * debut, char * nom, int nutriment)
{
  nourriture * aliment = nourriture_make();
  nourriture_init(aliment, nom, nutriment);
  ajouter_chainon(debut, (void*)aliment);

}

nourriture * chercher_nourriture(liste  * debut, char * nom)
{
  liste * courant = liste_obtenir_suivant(debut);
  //on parcourt la liste jusqu'à trouver le nom recherché ou arriver à la fin
  while(strcmp(nourriture_obtenir_nom(liste_obtenir_valeur(courant)), nom) && liste_obtenir_suivant(courant) != NULL){
  courant = liste_obtenir_suivant(courant);
  }
  //si on est arrivé à la fin on vérifie que le dernier chainon contient l'aliment recherché
  if(liste_obtenir_suivant(courant) == NULL){
    if(!strcmp(nourriture_obtenir_nom(liste_obtenir_valeur(courant)), nom))
      return liste_obtenir_valeur(courant);
    return NULL;
  }
  return liste_obtenir_valeur(courant);
}
