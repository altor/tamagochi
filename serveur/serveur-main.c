#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>

#include "global.h"
#include "serv.h"
#include "tamagochi.h"
#include "../utilitaire.h"
#include "../classe/nourriture.h"
#include "../classe/variable_etat.h"
#include "../classe/liste.h"


#define SOCKET_PATH "/tmp/s.tamagochi"
#define MAX 512
pthread_mutex_t mutex_etat;
int eteindre;
liste * debut_nourriture = NULL;
variable_etat* niv_faim = NULL;
variable_etat* humeur = NULL;
variable_etat* nourriture_ingurgite = NULL;

int main(void)
{
  int sockfd, servlen;
  pthread_t th_serveur, th_tamagochi;
  void * ret;
  struct sockaddr_un serv_addr;

 
  /*                                     */
  /* CREATION ET CONFIGURATION DU SOCKET */      
  /*                                     */ 
  //ouverture du socket
  if( (sockfd = socket(AF_UNIX, SOCK_STREAM, 0)) < 0)
    err_dump("serveur : erreur lors de l'ouverture du socket");
  
  //Configuration du socket
  bzero((char *) &serv_addr,sizeof(serv_addr));
  serv_addr.sun_family = AF_UNIX;
  strcpy(serv_addr.sun_path, SOCKET_PATH);
  servlen = strlen(serv_addr.sun_path) + sizeof(serv_addr.sun_family);

  if (bind(sockfd, (struct sockaddr *) &serv_addr, servlen) < 0)
    err_dump("serveur: erreur lors de la configuration du socket");
  
  listen(sockfd, 1);
  /*                                                    */
  /*  CREATION DES OBJETS PARTAGÉ PAR LES DEUX THREADS  */
  /*                                                    */

  //CREATION DES VARIABLES ETAT//
  niv_faim = variable_etat_make();
  humeur = variable_etat_make();
  nourriture_ingurgite = variable_etat_make();

  //CREATION DE LA NOURITURE//
  //creation de la liste
  debut_nourriture = liste_make();
  liste_init(debut_nourriture, NULL, 0);
  //ajout des composants
  ajouter_nourriture(debut_nourriture, "chocolat", 1);
  ajouter_nourriture(debut_nourriture, "pizza", 4);
  ajouter_nourriture(debut_nourriture, "pate", 4);
  ajouter_nourriture(debut_nourriture, "kebab", 5);
  ajouter_nourriture(debut_nourriture, "tartiflette", 6);

  /*                                               */
  /* CREATION DU THREAD ET CONFIGURATION DES MUTEX */
  /*                                               */
  pthread_mutex_init(&mutex_etat, NULL);

  if(pthread_create(&th_serveur, NULL, thread_serveur, &sockfd) < 0)
    err_dump("erreur lors de la creation du thread serveur");
  eteindre = 1;
  if(pthread_create(&th_tamagochi, NULL, thread_tamagochi, NULL) < 0)
    err_dump("erreur lors de la creation du thread tamagochi");

  pthread_join(th_serveur, &ret);
  eteindre = 0;
  pthread_join(th_tamagochi, &ret);

  
  return 0;
}





