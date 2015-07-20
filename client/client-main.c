#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include "../utilitaire.h"
#include "str-cli.h"

#define	UNIXSTR_PATH	"/tmp/s.tamagochi"
int main(int argc, char * argv[])
{
  int sockfd, servlen;
  struct sockaddr_un serv_addr;

  bzero((char *) &serv_addr, sizeof(serv_addr));
  serv_addr.sun_family = AF_UNIX;
  strcpy(serv_addr.sun_path, UNIXSTR_PATH);
  servlen = strlen(serv_addr.sun_path) + sizeof(serv_addr.sun_family);


  if ((sockfd = socket(AF_UNIX, SOCK_STREAM, 0)) < 0)
    err_dump("client: impossible d'ouvrir le flux vers le socket");

	
  if (connect(sockfd, (struct sockaddr *) &serv_addr, servlen) < 0)
    err_dump("client: impossible de se connecter au serveur");

  str_cli(stdin, sockfd);	
  close(sockfd);
  exit(0);
}




