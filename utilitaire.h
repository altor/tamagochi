//fonction utilisé par le serveur et le client pour la communication


#ifndef UTILITAIRE_H
#define UTILITAIRE_H

int readline(int fd, char *  ptr, int maxlen);
int writen(int fd, char * ptr, int nbytes);
void err_dump(char * p);

#endif
