#include <time.h>
#include <stdlib.h>
#include <pthread.h>


#include "variable_etat.h"

static pthread_mutex_t mutex_etat = PTHREAD_MUTEX_INITIALIZER;

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
  while(pthread_mutex_lock(&mutex_etat));
  obj->valeur += valeur;
  pthread_mutex_unlock(&mutex_etat);
}

void variable_etat_actualiser_temps(variable_etat * obj)
{
  while(pthread_mutex_lock(&mutex_etat));
  obj->temps = time(NULL);
  pthread_mutex_unlock(&mutex_etat);
}

int variable_etat_obtenir_valeur(variable_etat * obj)
{
  int val;
  
  while(pthread_mutex_lock(&mutex_etat));
  val =  obj->valeur;
  pthread_mutex_unlock(&mutex_etat);
  return val;
}

time_t variable_etat_obtenir_temps(variable_etat * obj)
{
  time_t temps;
  
  while(pthread_mutex_lock(&mutex_etat));
  temps =  obj->temps;
  pthread_mutex_unlock(&mutex_etat);
  return temps;
}
