//declaration de la classe commande qui sert a stocker les commandes utilisé pour communiquer entre le serveur et le client.
//declaration de la liste de stockage des commandes et des fonction qui lui sont associé.
#ifndef COMMANDE_H
#define COMMANDE_H

#include "liste.h"
#include "../serveur/global.h"

typedef struct commande commande;
typedef void (*Pfonction) (char arg[12][MAX], int, void *, liste *); 

extern liste * debut_commande;

//fonction de la classe commande
extern commande * commande_make();
extern void commande_init(commande * obj, char * nom, Pfonction fonction, liste * liste_arg);
extern void commande_delete(commande * obj);
extern char * commande_obtenir_nom(commande * obj);
extern  Pfonction commande_obtenir_fonction(commande * obj);
extern liste * commande_obtenir_arg(commande * obj);
//fonction permetant de manipuler la liste des commandes
void ajouter_commande(liste * debut, char * nom, Pfonction fonction, liste * liste_arg);
int lancer_commande(liste * debut, char * nom, char arg2[12][MAX], int arg3, void * retour);

#endif
