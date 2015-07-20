#include <stdlib.h>

#include "fonctionnalite.h"

struct fonctionnalite{
  int cycle;
  PFfonctionnalite PF;
};

fonctionnalite * fonctionnalite_make()
{
  return malloc(sizeof(fonctionnalite));
}

void fonctionnalite_delete(fonctionnalite * obj)
{
  free(obj);
}

void fonctionnalite_init(fonctionnalite * obj, int cycle, PFfonctionnalite PF)
{
  obj->cycle = cycle;
  obj->PF = PF;
}

int fonctionnalite_obtenir_cycle(fonctionnalite * obj)
{
  return obj->cycle;
}

PFfonctionnalite fonctionnalite_obtenir_PF(fonctionnalite * obj)
{
  return obj->PF;
}



void ajouter_fonctionnalite(liste * debut, int cycle, PFfonctionnalite PF)
{
  fonctionnalite *  fonctionnalite_cree = fonctionnalite_make();
  fonctionnalite_init(fonctionnalite_cree, cycle, PF);
  ajouter_chainon(debut, fonctionnalite_cree);
}

void lancer_fonctionnalite(liste * courant,int nb_cycle)
{
  fonctionnalite * fonctionnalite_courante = liste_obtenir_valeur(courant);
  int cycle = fonctionnalite_obtenir_cycle(fonctionnalite_courante);
  PFfonctionnalite PF = NULL;
  
  if(nb_cycle % cycle == 0){
    PF = fonctionnalite_obtenir_PF(fonctionnalite_courante);
    (*PF)();
  }
}

void parcourir_fonctionnalite(liste * debut, int nb_cycle)
{
  liste * courant = liste_obtenir_suivant(debut);

  if(courant != NULL){
    while(liste_obtenir_suivant(courant) != NULL){
      lancer_fonctionnalite(courant, nb_cycle);
      courant = liste_obtenir_suivant(courant);
    }
    //on lance la derniére fonctionalité
    lancer_fonctionnalite(courant, nb_cycle);
  }
}
