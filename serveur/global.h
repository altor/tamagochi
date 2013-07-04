#ifndef GLOBAL_H
#define GLOBAL_H

#define MAX 512
#define MAX_GOUT 10
#define MIN_GOUT -10

#define POID_DEPART 5
#define CAPACITE_ESTOMAC 20

#include <pthread.h>
#include <time.h>
#include "../classe/variable_etat.h"
#include "../classe/liste.h"

int poid, poid_dejection, verrou_ingurgitation, verrou_digestion;
extern variable_etat* niv_faim, *humeur, *nourriture_ingurgite ;




extern pthread_mutex_t mutex_etat;

int eteindre, alive;



#endif
