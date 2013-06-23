#ifndef SERV_H
#define SERV_H


//fonction lancé par le premier thread. elle gére la communication avec le client et execute les commande envoyé par le client.
void * thread_serveur(void * arg);

#endif
