//declaration des fonction appelé par les commandes utilisé pour la communication serveur/client

#ifndef COMMANDE_SERV_H
#define COMMANDE_SERV_H

char* sortir(char * chaine_env, char arguments[MAX][12], int nb_arguments);
char* halt(char * chaine_env, char arguments[MAX][12], int nb_arguments);
char * testarg(char * chaine_env, char arguments[MAX][12], int nb_arguments);

#endif
