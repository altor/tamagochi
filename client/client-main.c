/* 
 * Example of client using UNIX domain stream protocol
 * Reproduced from Unix Network Programming
		W.Richard Stevens
		Prentice Hall Software Series 1990
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include "../utilitaire.h"
#include "str-cli.h"

#define	UNIXSTR_PATH	"/tmp/s.tamagochi"
main(argc, argv)
int	argc;
char	*argv[];
{
	int			sockfd, servlen;
	struct sockaddr_un	serv_addr;


	/* 
	 * Fill in the structure "serv_addr" with the address of the
	 * server that we want to send to.
	 */

	bzero((char *) &serv_addr, sizeof(serv_addr));
	serv_addr.sun_family = AF_UNIX;
	strcpy(serv_addr.sun_path, UNIXSTR_PATH);
	servlen = strlen(serv_addr.sun_path) + sizeof(serv_addr.sun_family);

	/* 
	 * Open a socket (an UNIX domain stream socket)
	 */

	if ((sockfd = socket(AF_UNIX, SOCK_STREAM, 0)) < 0)
		err_dump("client: can't open stream socket");

	/*
	 * Connect to the server
	 */
	
	if (connect(sockfd, (struct sockaddr *) &serv_addr, servlen) < 0)
		err_dump("client: can't connect to server");

	str_cli(stdin, sockfd);		/* do it all */
	close(sockfd);
	exit(0);
}




