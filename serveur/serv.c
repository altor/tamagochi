//Ce fichier défini la fonction thread_serveur ainsi que les fonctions qu'elle utilise

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//lib socket
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>

//fichiers locaux
#include "etat.h"
#include "global.h"
#include "../utilitaire.h"
#include "../classe/variable_etat.h"
#include "../classe/liste.h"
#include "commande_serv.h"
#include "../classe/commande.h"


int poid, poid_dejection, verou_ingurgitation, verrou_digestion, proprete;
//fonctions utilisées par la fonction thread serveur
int serv_shell(int sockfd, liste * debut_commande);
int serv_chaine(int sockfd, char * chaine,int taille);
int recup_arguments(char arguments[12][MAX], char * chaine_env, int longueur);


//fonction lancées par le thread serveur
void * thread_serveur(void * arg)
{
  socklen_t clilen;
  int newsockfd;
  int sockfd = *(int*)arg;
  int retour = 1;
  struct sockaddr cli_addr;
  liste * debut_commande = NULL;
  liste * arg_etat = NULL;

  //CREATION COMMANDES//
  //creation de la liste
  debut_commande = liste_make();
  liste_init(debut_commande, NULL, 0);
  //ajout des composants
  ajouter_commande(debut_commande, "creer", creer, NULL);
  ajouter_commande(debut_commande, "manger", manger, NULL);
  //commande etat et ses argument
  arg_etat = liste_make();
  liste_init(arg_etat, NULL, 0);
  ajouter_commande(arg_etat, "faim", etat_faim, NULL);
  ajouter_commande(arg_etat, "n_i", etat_nourriture_ingurgite, NULL);
  ajouter_commande(arg_etat, "poid", etat_poid, NULL);
  ajouter_commande(arg_etat, "poid_dejection", etat_poid_dejection, NULL);
  ajouter_commande(arg_etat, "humeur", etat_humeur, NULL);
  ajouter_commande(arg_etat, "proprete", etat_proprete, NULL);
  ajouter_commande(debut_commande, "etat", etat, arg_etat);

  ajouter_commande(debut_commande, "exit", sortir, NULL);  
  ajouter_commande(debut_commande, "halt", halt, NULL);

  //initialisation des variables globales
  alive = 0;

  srand(time(NULL));

  //lancement de la boucle de gestion des connections
  
  while(retour != 2){
    clilen = sizeof(cli_addr);
    //création d'un nouveau socket pour dialoguer avec le client
    newsockfd = accept(sockfd, &cli_addr, &clilen); 
    if(newsockfd < 0)
      err_dump("serveur : erreur lors de l'appel d'accept");
    
    retour = serv_shell(newsockfd,debut_commande); //effectuer la requête
    close(newsockfd);//fermeture du socket client
  }
  return 0;
}


//fonction de gestion des commandes reçut par le serveur
//renvoi 1 si le client demande à être déconnecter
//renvoi 2 si le client demande à arrêter le serveur
int serv_shell(int sockfd, liste * debut_commande)
{
  int n, nb_arguments;
  char chaine_rcv[MAX], chaine_env[MAX], arguments[12][MAX];

  while(1){
  n = readline(sockfd, chaine_rcv, MAX); //lecture de la commande et stockage de sa taille dans n
  if(n == 0)
    return 0; 
  else if(n < 0) //connections interrompu avec le client
      err_dump("serveur_shell : erreur lors de l'appel de readline");
  
  nb_arguments = recup_arguments(arguments, chaine_rcv, strlen(chaine_rcv)); //on sépare la commande principale de ses arguments

  if(lancer_commande(debut_commande, arguments[0], arguments, nb_arguments,chaine_env) == 1)
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


//sépare les arguments de la commande reçu dans un tableau de chaîne de caractère(le premier éléments est la commande reçu) et renvoi le nombre d'arguments
int recup_arguments(char arguments[12][MAX], char * chaine_env, int longueur)
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
