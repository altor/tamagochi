#include <time.h>
#include <stdlib.h>

#include "variable_etat.h"

struct variable_etat{
  int valeur;
  time_t temps;
};

variable_etat * variable_etat_make()
{
  return malloc(sizeof(struct variable_etat));
}

void variable_etat_delete(variable_etat * obj)
{
  free(obj);
}

void variable_etat_initialiser(variable_etat * obj, int valeur)
{
  obj->valeur = valeur;
  obj->temps = time(NULL);
}

void variable_etat_ajouter_valeur(variable_etat * obj, int valeur)
{
  obj->valeur += valeur;
}

void variable_etat_actualiser_temps(variable_etat * obj)
{
  obj->temps = time(NULL);
}

int variable_etat_obtenir_valeur(variable_etat * obj)
{
  return obj->valeur;
}

time_t variable_etat_obtenir_temps(variable_etat * obj)
{
  return obj->temps;
}
