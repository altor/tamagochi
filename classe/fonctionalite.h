//declaration de la classe fonctionalite qui sert a stocker les fonction qui mettent a jours les variables du tamagochi.
//declaration de la liste de stockage des fonctionalité et des fonction qui lui sont associé.

#ifndef FONCTIONALITE_H
#define FONCTIONALITE_H

#include "liste.h"

typedef void (*PFfonctionalite) (void);
typedef struct fonctionalite fonctionalite;

//methode de la classe fonctionalité
fonctionalite * fonctionalite_make();
void fonctionalite_delete(fonctionalite * obj);
void fonctionalite_init(fonctionalite * obj, int cycle, PFfonctionalite PF);
int fonctionalite_obtenir_cycle(fonctionalite * obj);
PFfonctionalite fonctionalite_obtenir_PF(fonctionalite * obj);

//fonction permetant de manipulé la liste des fonctionalité
void ajouter_fonctionalite(liste * debut, int cycle, PFfonctionalite PF);
void lancer_fonctionalite(liste * courant,int nb_cycle);
void parcourir_fonctionalite(liste * debut, int nb_cycle);


#endif
