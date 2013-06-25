//declaration de la classe commande qui sert a stocker les commandes utilisé pour communiquer entre le serveur et le client.
//declaration de la liste de stockage des commandes et des fonction qui lui sont associé.
#ifndef COMMANDE_H
#define COMMANDE_H

#include "liste.h"
#include "../serveur/global.h"

typedef struct commande commande;
typedef void (*Pfonction) (char*,char arg[MAX][12], int, void *); 

extern liste * debut_commande;

//fonction de la classe commande
extern commande * commande_make();
extern void commande_init(commande * obj, char * nom, Pfonction fonction);
extern void commande_delete(commande * obj);
extern char * commande_obtenir_nom(commande * obj);
extern  Pfonction commande_obtenir_fonction(commande * obj);
//fonction permetant de manipuler la liste des commandes
void ajouter_commande(liste * debut, char * nom, Pfonction fonction);
int lancer_commande(liste * debut, char * nom, char* arg1,char arg2[MAX][12], int arg3, void * retour);

#endif
