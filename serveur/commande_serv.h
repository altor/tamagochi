//declaration des fonction appelé par les commandes utilisé pour la communication serveur/client

#ifndef COMMANDE_SERV_H
#define COMMANDE_SERV_H

void sortir(char * chaine_env, char arguments[MAX][12], int nb_arguments, void * retour);
void halt(char * chaine_env, char arguments[MAX][12], int nb_arguments, void * retour);
void  testarg(char * chaine_env, char arguments[MAX][12], int nb_arguments, void * retour);
void creer(char * chaine_env, char arguments[MAX][12], int nb_arguments, void * retour);

#endif
