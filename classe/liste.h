//déclaration de la classe liste qui sert à stocker un maillon d'une chaîne simplement chaîne
//déclaration des fonctions permettant de manipuler la chaîne dans son intégralité.

#ifndef LISTE_H
#define LISTE_H


typedef struct liste liste;


//fonctions de la classe liste
extern liste * liste_make();
extern void liste_delete(liste * obj);
extern void liste_init(liste * obj,liste * suivant, void * valeur);
extern void liste_modifier_valeur(liste * obj, void * valeur);
extern void liste_modifier_suivant(liste * obj, liste * suivant);
extern void * liste_obtenir_valeur(liste * obj);
extern liste * liste_obtenir_suivant(liste * obj);
//fonction permettant de manipuler une liste dans sa globalité
void ajouter_chainon(liste * debut,void * valeur);


#endif
