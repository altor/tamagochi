/*
 * Reproduced from Unix Network Programming
 W.Richard Stevens
 Prentice Hall Software Series 1990
 * Read a line from a descriptor. Read the line one byte at a time,
 * looking for the newline. We store the newline in the buffer,
 * then follow it with a null (the same as fgets(3)).
 * We return the number of characters up to, but not including,
 * the null (the same as strlen(3)).
 */
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
int readline(int fd, char *  ptr, int maxlen)
{
  int 	n, rc;
  char	c;
  for (n = 1; n < maxlen; n++) {


    if ( (rc = read(fd, &c, 1)) == 1) {
      if (c == '\n')
	break;
      *ptr++ = c;
    }

    else if (rc == 0) {

      if (n == 1)
	return(0);	/* EOF, no data read */
      else
	break;		/* EOF, some data was read */
    }

    else
      return(-1);	/* error */
    
  }
  *ptr = 0;
  return(n);
}


/*
 * Reproduced from Unix Network Programming
 W.Richard Stevens
 Prentice Hall Software Series 1990
 * Write "n" bytes to a descriptor.
 * Use in place of write() when fd is a stream socket.
 */


int writen(int fd, char * ptr, int nbytes)
{
  int nleft, nwritten;

	
  nleft = nbytes;
  while (nleft > 0) {
    nwritten = write(fd, ptr, nleft);
    if (nwritten <= 0)
      return(nwritten);
    nleft -= nwritten;
    ptr += nwritten;
  }

  return(nbytes - nleft);
}



void err_dump(char * p)
{
  fprintf(stderr,"%s\n",p);
  exit(1);
}
