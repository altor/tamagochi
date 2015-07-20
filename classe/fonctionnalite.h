//déclaration de la classe fonctionnalite qui sert à stocker les fonctions qui mettent à jours les variables du tamagochi.
//déclaration de la liste de stockage des fonctionnalités et des fonctions qui lui sont associées.

#ifndef FONCTIONNALITE_H
#define FONCTIONNALITE_H

#include "liste.h"

typedef void (*PFfonctionnalite) (void);
typedef struct fonctionnalite fonctionnalite;

//methode de la classe fonctionalité
fonctionnalite * fonctionnalite_make();
void fonctionnalite_delete(fonctionnalite * obj);
void fonctionnalite_init(fonctionnalite * obj, int cycle, PFfonctionnalite PF);
int fonctionnalite_obtenir_cycle(fonctionnalite * obj);
PFfonctionnalite fonctionnalite_obtenir_PF(fonctionnalite * obj);

//fonction permetant de manipulé la liste des fonctionalité
void ajouter_fonctionnalite(liste * debut, int cycle, PFfonctionnalite PF);
void lancer_fonctionnalite(liste * courant,int nb_cycle);
void parcourir_fonctionnalite(liste * debut, int nb_cycle);


#endif
