#ifndef GLOBAL_H
#define GLOBAL_H

#define MAX 512
#define MAX_GOUT 10
#define MIN_GOUT -10




#include <pthread.h>
#include <time.h>
#include "../classe/variable_etat.h"
#include "../classe/liste.h"

extern variable_etat* niv_faim;
extern variable_etat* humeur;



extern pthread_mutex_t mutex_etat;

int eteindre, alive;



#endif
