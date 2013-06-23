#include <stdlib.h>

#include "liste.h"

struct liste{
  liste * suivant;
  void * valeur;
};


liste * liste_make()
{
  return malloc(sizeof(liste));
}

void liste_init(liste * obj, liste * suivant, void * valeur)
{
  obj->suivant = suivant;
  obj->valeur = valeur;
}
void liste_delete(liste * obj)
{
  free(obj);
}

void liste_modifier_valeur(liste * obj, void * valeur)
{
  obj->valeur = valeur;
}

void liste_modifier_suivant(liste * obj, liste * suivant)
{
  obj->suivant = suivant;
}




void * liste_obtenir_valeur(liste * obj)
{
  return obj->valeur;
}

liste * liste_obtenir_suivant(liste * obj)
{
  return obj->suivant;
}

void ajouter_chainon(liste * debut,void * valeur)
{
  liste * courant = debut;
  while(liste_obtenir_suivant(courant) != NULL)
    courant = liste_obtenir_suivant(courant);
  liste_modifier_suivant(courant, liste_make());
  liste_init(liste_obtenir_suivant(courant), NULL, valeur);
}
