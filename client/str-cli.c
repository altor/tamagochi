/*
 * Reproduced from Unix Network Programming
		W.Richard Stevens
		Prentice Hall Software Series 1990
 * Read the contents of the FILE *fp, write each line to the 
 * stream socket (to the server process), then read a line back from
 * the socket and write it to the standard output.
 *
 * Return to caller when an EOF is encountered on the input file.
 */

#include	<stdio.h>
#include <string.h>
#include "../utilitaire.h"
#define	MAXLINE 512

int
str_cli(fp, sockfd)
register FILE	*fp;
register int	sockfd;
{
	int	n;
	char	sendline[MAXLINE], recvline[MAXLINE + 1];
	printf(">");
	while (fgets(sendline, MAXLINE, fp) != NULL) {
	  n = strlen(sendline);
	  if (writen(sockfd, sendline, n) != n)
	    err_dump("str_cli: writen error on socket");
	  /* 
	   * Now read a line from the socket and write it to
	   * our standard output.
	   */
	  
	  n = readline(sockfd, recvline, MAXLINE);
	  if (n < 0)
	    err_dump("str_cli: readline error");
	  if(!strcmp(recvline, "exit"))
	     return 0;
	  recvline[n-1] = 0;		/* null terminate */
	  fputs(recvline, stdout);
	  printf("\n>");
	}
	
	if (ferror(fp))
	  err_dump("str_cli: error reading file");
	
}
