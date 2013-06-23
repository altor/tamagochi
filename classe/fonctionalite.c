#include <stdlib.h>

#include "fonctionalite.h"

struct fonctionalite{
  int cycle;
  PFfonctionalite PF;
};

fonctionalite * fonctionalite_make()
{
  return malloc(sizeof(fonctionalite));
}

void fonctionalite_delete(fonctionalite * obj)
{
  free(obj);
}

void fonctionalite_init(fonctionalite * obj, int cycle, PFfonctionalite PF)
{
  obj->cycle = cycle;
  obj->PF = PF;
}

int fonctionalite_obtenir_cycle(fonctionalite * obj)
{
  return obj->cycle;
}

PFfonctionalite fonctionalite_obtenir_PF(fonctionalite * obj)
{
  return obj->PF;
}



void ajouter_fonctionalite(liste * debut, int cycle, PFfonctionalite PF)
{
  fonctionalite *  fonctionalite_cree = fonctionalite_make();
  fonctionalite_init(fonctionalite_cree, cycle, PF);
  ajouter_chainon(debut, fonctionalite_cree);
}

void lancer_fonctionalite(liste * courant,int nb_cycle)
{
  fonctionalite * fonctionalite_courante = liste_obtenir_valeur(courant);
  int cycle = fonctionalite_obtenir_cycle(fonctionalite_courante);
  PFfonctionalite PF = NULL;
  
  if(nb_cycle % cycle == 0){
    PF = fonctionalite_obtenir_PF(fonctionalite_courante);
    (*PF)();
  }
}

void parcourir_fonctionalite(liste * debut, int nb_cycle)
{
  liste * courant = liste_obtenir_suivant(debut);

  if(courant != NULL){
    while(liste_obtenir_suivant(courant) != NULL){
      lancer_fonctionalite(courant, nb_cycle);
      courant = liste_obtenir_suivant(courant);
    }
    //on lance la derniére fonctionalité
    lancer_fonctionalite(courant, nb_cycle);
  }
}
