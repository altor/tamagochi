//declaration de la classe variable_etat utilisé pour stocker les variable du tamagochie misent a jour en fonction du temps (humeur, faim etc...)

#ifndef VARIABLE_ETAT_H
#define VARIABLE_ETAT_H


#include <time.h>

typedef struct variable_etat variable_etat;

extern variable_etat * variable_etat_make();
extern void variable_etat_delete(variable_etat * obj);
extern void variable_etat_initialiser(variable_etat * obj,int valeur);
extern void variable_etat_ajouter_valeur(variable_etat * obj, int valeur);
extern int variable_etat_obtenir_valeur(variable_etat * obj);
extern time_t variable_etat_obtenir_temps(variable_etat * obj);
extern void variable_etat_actualiser_temps(variable_etat * obj);

#endif /* VARIABLE_ETAT_H */
