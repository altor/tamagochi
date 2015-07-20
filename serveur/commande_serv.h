//déclaration des fonctions appelées par les commandes utilisées pour la communication client/serveur

#ifndef COMMANDE_SERV_H
#define COMMANDE_SERV_H

void sortir(char arguments[12][MAX], int nb_arguments, void * retour, liste * liste_arg);
void halt(char arguments[12][MAX], int nb_arguments, void * retour, liste * liste_arg);
void  testarg(char arguments[12][MAX], int nb_arguments, void * retour, liste * liste_arg);
void creer(char arguments[12][MAX], int nb_arguments, void * retour, liste * liste_arg);
void etat(char arguments[12][MAX], int nb_arguments, void * retour, liste * liste_arg);
void etat_faim(char arguments[12][MAX], int nb_arguments, void * retour, liste * liste_arg);
void etat_humeur(char arguments[12][MAX], int nb_arguments, void * retour, liste * liste_arg);
void manger(char arguments[12][MAX], int nb_arguments, void * retour, liste * liste_arg);

#endif
