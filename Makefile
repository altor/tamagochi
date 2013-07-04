CCFLAGS = -pthread -Wall -o


OBJ_CLASSE = variable_etat.o commande.o nourriture.o liste.o fonctionalite.o
OBJ_SERV = serveur-main.o serv.o tamagochi.o commande_serv.o etat.o fonctionalite_tamagochi.o
OBJ_SERV_MAIN = $(OBJ_SERV) $(OBJ_CLASSE) utilitaire.o

OBJ_CLI = client-main.o str-cli.o
OBJ_CLI_MAIN = $(OBJ_CLI) utilitaire.o

BIN = client_main serveur_main


all: $(BIN)

clean:
	rm  $(OBJ_SERV_MAIN) $(OBJ_CLI_MAIN) $(BIN)

clean_obj:
	-rm $(OBJ_SERV_MAIN) $(OBJ_CLI_MAIN)

clean_bin:
	-rm $(BIN)

client_main : $(OBJ_CLI_MAIN)
	gcc -Wall -o client_main $(OBJ_CLI_MAIN)

client-main.o: utilitaire.h ./client/str-cli.h ./client/client-main.c
	gcc -Wall -o client-main.o -c ./client/client-main.c

str-cli.o: utilitaire.h ./client/str-cli.c
	gcc -Wall -o str-cli.o -c ./client/str-cli.c

serveur_main : $(OBJ_SERV_MAIN)
	gcc $(CCFLAGS) serveur_main $(OBJ_SERV_MAIN)

serveur-main.o : ./serveur/serveur-main.c utilitaire.h ./serveur/tamagochi.h ./serveur/serv.h
	gcc $(CCFLAGS) serveur-main.o -c ./serveur/serveur-main.c

serv.o : ./serveur/serv.c utilitaire.o utilitaire.h ./classe/variable_etat.h
	gcc $(CCFLAGS) serv.o -c ./serveur/serv.c

tamagochi.o : ./serveur/tamagochi.c  utilitaire.h ./classe/variable_etat.h
	gcc $(CCFLAGS) tamagochi.o -c ./serveur/tamagochi.c
utilitaire.o : utilitaire.c utilitaire.h
	gcc -Wall -o utilitaire.o -c utilitaire.c

variable_etat.o : ./classe/variable_etat.h ./classe/variable_etat.c
	gcc -Wall -o variable_etat.o -c ./classe/variable_etat.c

nourriture.o : ./classe/nourriture.h ./classe/nourriture.c
	gcc -Wall -o nourriture.o -c ./classe/nourriture.c

commande.o : ./classe/commande.h ./classe/commande.c
	gcc -Wall -o commande.o -c ./classe/commande.c

commande_serv.o : ./serveur/commande_serv.h ./serveur/commande_serv.c
	gcc -Wall -o commande_serv.o -c ./serveur/commande_serv.c

fonctionalite.o : ./classe/fonctionalite.h ./classe/liste.h ./classe/fonctionalite.c
	gcc -Wall -o fonctionalite.o -c ./classe/fonctionalite.c

liste.o: ./classe/liste.h ./classe/liste.c
	gcc -Wall -o liste.o -c ./classe/liste.c

etat.o: ./serveur/etat.h ./serveur/global.h ./classe/nourriture.h ./classe/variable_etat.h ./serveur/etat.c
	gcc -Wall -o etat.o -c ./serveur/etat.c

fonctionalite_tamagochi.o: ./serveur/fonctionalite_tamagochi.h ./serveur/fonctionalite_tamagochi.c
	gcc -Wall -o fonctionalite_tamagochi.o -c ./serveur/fonctionalite_tamagochi.c