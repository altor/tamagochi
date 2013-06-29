#ifndef ETAT_H
#define ETAT_H

#include "../classe/liste.h"
#include "global.h"

void etat(char arguments[MAX][12], int nb_arguments, void * retour, liste * liste_arg);
void etat_humeur(char arguments[MAX][12], int nb_arguments, void * retour, liste * liste_arg);
void etat_nourriture_ingurgite(char arguments[MAX][12], int nb_arguments, void * retour, liste * liste_arg);
void etat_poid(char arguments[MAX][12], int nb_arguments, void * retour, liste * liste_arg);
void etat_poid_degection(char arguments[MAX][12], int nb_arguments, void * retour, liste * liste_arg);

#endif
