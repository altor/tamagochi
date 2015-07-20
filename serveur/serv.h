#ifndef SERV_H
#define SERV_H


//fonction lancée par le premier thread. elle gére la communication avec le client et execute les commandes envoyées par le client.
void * thread_serveur(void * arg);

#endif
