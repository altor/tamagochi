#ifndef GLOBAL_H
#define GLOBAL_H

#define MAX 512
#define MAX_GOUT 10
#define MIN_GOUT -10

#define POID_DEPART 5
#define CAPACITE_ESTOMAC 7
#define CYCLE 1 //durée d'un cycle de mise à jour en seconde
#define DURE_JOUR 24 //nombre de cycle en une journée
#define DURE_PRODUCTION (DURE_JOUR / 4) //durée de la digestion en cycle (ingurgistation, digestion , évacuation)
#define DURE_DIGESTION (DURE_PRODUCTION /3)//nombre de cycle avant le déclenchement de la digestion
#define DURE_EVACUATION (DURE_PRODUCTION - DURE_DIGESTION)//nombre de cycle avant le déclenchement de la digestion
#define DURE_HUMEUR (DURE_JOUR / 6) //nombre de cycle avant la mise à jour de l'humeur
#define DURE_POID  DURE_JOUR// nombre de cycle avant la mise à jour du poids
#define DURE_FAIM (DURE_JOUR / 4) //nombre de cycle sans manger avant que le tamagochi ne commence à avoir faim

#include <pthread.h>
#include <time.h>
#include "../classe/variable_etat.h"
#include "../classe/liste.h"

int poid, poid_dejection, verrou_ingurgitation, verrou_digestion, proprete;
extern variable_etat* niv_faim, *humeur, *nourriture_ingurgite ;
extern pthread_mutex_t mutex_etat;

int eteindre, alive;

#endif
