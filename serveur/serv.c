//Ce fichier définie la fonction thread_serveur ainsi que les fonction qu'elle utilise

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//lib socket
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>

//fichiers locaux
#include "global.h"
#include "../utilitaire.h"
#include "../classe/variable_etat.h"
#include "../classe/liste.h"
#include "commande_serv.h"
#include "../classe/commande.h"


//definition des variables global
variable_etat* niv_faim = NULL;
variable_etat* humeur = NULL;



//fonctions utilisé par la fonction thread serveur
int serv_shell(int sockfd, liste * debut_commande);
int serv_chaine(int sockfd, char * chaine,int taille);
int recup_arguments(char arguments[MAX][12], char * chaine_env, int longueur);


//fonction lancé par le thread serveur
void * thread_serveur(void * arg)
{
  socklen_t clilen;
  int newsockfd;
  int sockfd = *(int*)arg;
  int retour = 1;
  struct sockaddr cli_addr;
  liste * debut_commande = NULL;

  //CREATION COMMANDES//
  //creation de la liste
  debut_commande = liste_make();
  liste_init(debut_commande, NULL, 0);
  //ajout des composants
  ajouter_commande(debut_commande, "creer", creer);
  ajouter_commande(debut_commande, "exit", sortir);
  ajouter_commande(debut_commande, "testarg", testarg);
  ajouter_commande(debut_commande, "halt", halt);

  //initialisation des variable globales
  alive = 0;

  srand(time(NULL));

  //lancement de la boucle de gestion des conection
  
  while(retour != 2){
    clilen = sizeof(cli_addr);
    //création d'un nouveau socket pour dialoguer avec le client
    newsockfd = accept(sockfd, &cli_addr, &clilen); 
    if(newsockfd < 0)
      err_dump("serveur : erreur lors de l'appel d'accept");
    
    retour = serv_shell(newsockfd,debut_commande); //effectuer la requéte
    close(newsockfd);//fermeture du socket client
  }
  return 0;
}


//fonction de gestion des commandes reçut par le serveur
//renvoi 1 si le client demande a etre deconecter
//renvoi 2 si le client demande a arreter le serveur
int serv_shell(int sockfd, liste * debut_commande)
{
  int n, nb_arguments;
  char chaine_rcv[MAX], chaine_env[MAX], arguments[MAX][12];

  while(1){
  n = readline(sockfd, chaine_rcv, MAX); //lecture de la commande et stocakge de sa taille dans n
  if(n == 0)
    return 0; 
  else if(n < 0) //conection interomput avec le client
      err_dump("serveur_shell : erreur lors de l'appel de readline");
  
  nb_arguments = recup_arguments(arguments, chaine_rcv, strlen(chaine_rcv)); //on sépare la commande principale de ses arguments

  if(lancer_commande(debut_commande, arguments[0], chaine_env, arguments, nb_arguments,NULL) == 1)
    strcpy(chaine_env, "commande inconnue");
  else if(!strcmp("halt", chaine_env)){
    strcpy(chaine_env, "exit");
    serv_chaine(sockfd, chaine_env, strlen(chaine_env));
    return 2;
  }
  
  serv_chaine(sockfd, chaine_env, strlen(chaine_env));
  if(!strcmp("exit", chaine_env))
    return 1;
  }
}

// envoi chaine dans sockfd et appel err_dump en cas d'erreur sinon renvoi 0 
int serv_chaine(int sockfd, char * chaine,int taille)
{
  chaine[taille] = '\n';
  chaine[taille + 1] = 0;
  
  if(writen(sockfd, chaine, (taille + 1)) != (taille + 1))
    err_dump("serveur_chaine : erreur lors de l'appel de writen");

  chaine[taille] = 0;
  
  return 0;
}


//separe les arguments de la commande reçu dans un tableau de chaine de caractére(le premier éléments est la commande reçu) et renvoi le nombre d'arguments
int recup_arguments(char arguments[MAX][12], char * chaine_env, int longueur)
{
  int i;
  int nb_arguments = 0;
  int j = 0;

  
  for(i = 0; i < longueur; i++){
    
    if(chaine_env[i] == 32){
      arguments[nb_arguments][j] = 0;
      nb_arguments ++;
      j = 0;
    }
    else{
      arguments[nb_arguments][j] = chaine_env[i];
      j ++;
    }
  }
  arguments[nb_arguments][j] = 0;
  for(i = (nb_arguments + 1); i < 12; i++)
    arguments[i][0] = 0;
  return nb_arguments + 1;
}




