VARIABLE D'ETAT===========================
alive -> variable booléene 1 le tamagochi est en vie 0 il est mort

niv_faim -> le niveau de faim du tamagochi il est compris entre 0 et 100, si il tombe a 0 le tamagochi meurt si il est a 72 le tamagochi refusera de manger
Le niveau de faim diminu de 1 pt tout les cycles et peut etre augmenter en donnant a manger au tamagochi

humeur -> l'humeur du tamagochi ,varie entre 0 et 100. si elle tombe a 0 le tamagochi s'en ira (il meurt)
l'humeur decendras si on n'a pas nourie le tamagochi pendant plus de 20 cycle ou si on lui donne a manger un aliment qu'il n'aime pas. l'humeur montera si on lui donne a manger un aliment qu'il aime

aliment_gout -> nombre compris entre -10 et 10 qui determine comment le tamagochi aime l'aliment en question. Cette valeur est ajouté a la variable humeur quand le tamagochi mange l'aliment corespondant




COMMANDE DU TAMAGOCHI================================

les commandes doivent etre tapé selon la syntaxe suivante

commande arg1 arg 2 arg3 ...

creer -> creer un tamagochi et initialise ses gouts aléatoirement. Les varialbes humeur et faim sont initialisé à 50

etat arg -> donne la valeur de l'arguments demandé (faim, humeur, gouts)

tuer -> tue le tamagochi

manger arg -> mange l'aliment arg (kebab +5, pizza +4, pate +4, chocolat +1, tartiflette +6)
