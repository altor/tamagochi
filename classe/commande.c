#include <stdlib.h>
#include <string.h>

#include "commande.h"

struct commande{
  char nom[512];
  Pfonction fonction;
};

commande * commande_make()
{
  return malloc(sizeof(commande));
}

void commande_delete(commande * obj)
{
  free(obj);
}

void commande_init(commande * obj, char * nom, Pfonction fonction)
{
  strcpy(obj->nom, nom);
  obj->fonction = fonction;
}

char * commande_obtenir_nom(commande * obj)
{
  return obj->nom;
}

Pfonction commande_obtenir_fonction(commande * obj)
{
  return obj->fonction;
}

void ajouter_commande(liste * debut, char * nom, Pfonction fonction)
{
  commande * commande_cree = commande_make();
  commande_init(commande_cree, nom, fonction);
  ajouter_chainon(debut, commande_cree);

}

int lancer_commande(liste * debut, char * nom, char* arg1,char arg2[MAX][12], int arg3)
{
  liste * courant = debut;
  Pfonction fonction = NULL;


  //on verifie que la liste n'est pas vide
  courant = liste_obtenir_suivant(courant);
  if(courant == NULL)
    return 1;
  //on parcour la liste jusqu'a trouvé le nom de la commande ou arrivé a la fin
  while((strcmp(commande_obtenir_nom(liste_obtenir_valeur(courant)), nom)) && (liste_obtenir_suivant(courant) != NULL))
    courant = liste_obtenir_suivant(courant);
  //si on arrive a la fin de la liste, on verifie si le dernier chainon contient la commande donné.
  if(liste_obtenir_suivant(courant) == NULL){
    if(strcmp(commande_obtenir_nom(liste_obtenir_valeur(courant)), nom))
      return 1;
    else{
      fonction = commande_obtenir_fonction(liste_obtenir_valeur(courant));
      (*fonction)(arg1,arg2,arg3);
      return 0;
    }
  }
  else{
    fonction = commande_obtenir_fonction(liste_obtenir_valeur(courant));
    (*fonction)(arg1,arg2,arg3);
   return 0;
  }
}
