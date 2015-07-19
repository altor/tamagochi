# Tamagochi

Projet personnel permettant d'expérimenter différents aspects de la programmation système.

Le tamagochi est un serveur, sur lequel se connecte les clients pour lui envoyer des commandes. Il simule le comportement d'un animal domestique. L'utilisateur peut, par le biais d'un invite de commande, nourrir le tamagochi. L'état du tamagochi évoluera en fonction de la quantité de nourriture absorbé. Son humeur évoluera aussi s'il aime ou non la nourriture.

## Notion abordé dans le projet

* Communication client-serveur par socket Unix
* Programmation mutli-thread (bibliothèque pthread)

    Coté serveur, un thread est utilisé pour mettre à jour les variables d'états du tamagochi (niveau de faim, humeur etc ...) en fonction du temps. Un autre thread est utilisé pour exécuter les commandes lancés par l'utilisateur.

* Utilisation de mutex : Chaque thread doit accéder aux variables d'états du tamagochi. Des mutex sont utilisés pour résoudre les problèmes d'accès simultané à ces variables.
* Programmation modulaire : les fonctionnalités du tamagochi, ses variables d'états, et les commandes auxquels il répond sont ajoutées dynamiquement au lancement du serveur. Le serveur peut donc très facilement être étendu.

## compilation et utilisation

Chaque commande est à exécuter depuis la racine du projet : 

* Pour compiler, lancez la commande `make`
* Pour lancer le serveur en tache de fond, lancez la commande : `./serveur_main &`
* Pour lancer le client (l'invite de commande communiquant avec le serveur) lancez la commande : `./client_main`

## Commandes

Listes des commandes acceptées par le tamagochi. Les commandes doivent être tapées selon la syntaxe suivante : `commande arg1 arg 2 arg3`.

* `creer` :  crée un tamagochi et initialise ses goûts aléatoirement. 

* `etat arg` : donne la valeur de l'argument demandé (faim, humeur, poids)

* `halt` : éteint le serveur

* `exit` : interrompt la connexion avec le serveur (le tamagochi reste actif et ses variables sont conservé)

* `manger arg` : mange l'aliment arg et augmente le niveau de faim du tamagochi (tartiflette +6, kebab +5, pizza +4, pate +4, chocolat +1)
