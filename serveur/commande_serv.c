#include <string.h>
#include "global.h"

char* sortir(char * chaine_env, char arguments[MAX][12], int nb_arguments)
{
  strcpy(chaine_env, "exit");
  return chaine_env;
}

char* halt(char * chaine_env, char arguments[MAX][12], int nb_arguments)
{
  strcpy(chaine_env, "halt");
  return chaine_env;
}

char * testarg(char * chaine_env, char arguments[MAX][12], int nb_arguments)
{
  if(nb_arguments != 2)
    strcpy(chaine_env, "nb arguments invalides");
  else{
    if(!strcmp(arguments[1], "a"))
      strcpy(chaine_env, "aaaaaaaaaa");
    else if(!strcmp(arguments[1], "b"))
      strcpy(chaine_env, "bbbbbbbbb");
    else
      strcpy(chaine_env, "argument invalide");
  }
  return chaine_env;
}
