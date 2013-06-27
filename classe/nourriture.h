//declaration de la classe nourriture qui sert a stocker les aliments leur valeur nutritive et comment le tamagochi l'aime.
//declaration de la liste de stockage de la nourriture et des fonction qui lui sont associé.

#ifndef NOURRITURE_H
#define NOURRITURE_H

#include "liste.h"

typedef struct nourriture nourriture;
extern liste * debut_nourriture;

//fonction de la methode nourriture
extern nourriture * nourriture_make();
extern void nourriture_delete(nourriture * obj);
extern void nourriture_init(nourriture * obj, char * nom, int nutriment);
extern void nourriture_modifier_gout(nourriture * obj, int gout);
extern int nourriture_obtenir_gout(nourriture * obj);
extern int nourriture_obtenir_nutriment(nourriture * obj);
extern char * nourriture_obtenir_nom(nourriture * obj);
//fonction permetant de gerer la liste de nourriture
void ajouter_nourriture(liste * debut, char * nom, int nutriment);
nourriture * chercher_nourriture(liste  * debut, char * nom);


#endif // definition
