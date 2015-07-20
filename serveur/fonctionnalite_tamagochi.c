#include <time.h>
#include <stdio.h>

#include "global.h"


void compteur_cycle(void)
{
  static int cycle = 0;
  cycle++;
  printf("%d\n",cycle);
}

//fonction experimental, non fonctionelle pour le moment
void gestion_prod(void)
{
  static int cycle = 0,
    ancien = 0,
    cycle_digestion = 0;
  static time_t t1, t2;
  int restes;
  

  //si l'ingurgitation à commencé on commence a compter un nombre de cycle
  if(!ancien && verrou_ingurgitation){
    ancien = 1;
    t1 = variable_etat_obtenir_temps(nourriture_ingurgite);
  }

  //on continue tant que l'ingurgitation n'est pas terminée
  if(verrou_ingurgitation){
    t2 = variable_etat_obtenir_temps(nourriture_ingurgite);
    //si une nouvelle ingurgitation a été lancé on réinitialise le nombre de cycle
    if(difftime(t1, t2) != 0){
	cycle = 1;
	t1 = t2;
      }
    else
      cycle ++;
  }
  //si une phase d'ingurgitation a été intérompu on remet le compteur de cycle à zéro
  else if(cycle > 0)
    cycle = 0;

  //si une phase de digestion a commencé
  if(verrou_digestion == 1)
    cycle_digestion ++;
  //dés qu'un nombre de cycle sufisant est passé on lance la digestion
  if(cycle >= (DURE_DIGESTION) )
      {
		printf("DIGESTION\n");
	restes = variable_etat_obtenir_valeur(nourriture_ingurgite);
	//phase normal : on termine la phase d'ingurgitation, le poid et le poid des dejection augmente en fonction de la nourriture ingurgitée, l'estomac est vidé et on prévient que la phase de digestion est en cours.
	verrou_ingurgitation = 0;
	ancien = 0;
	poid += (restes / 4);
	poid_dejection += (restes / 4);
	variable_etat_initialiser(nourriture_ingurgite, 0);
	verrou_digestion = 1;
	cycle_digestion = 0;
      }

  if(cycle_digestion >= DURE_EVACUATION){
    printf("EVACUATION\n");
    verrou_digestion = 0;
    poid_dejection = 0;
    proprete --;
    cycle_digestion = 0;

  }
}

//fonction experimental, non intégré pour le moment
void gestion_poid(void)
{
  if(poid > (POID_DEPART / 4))
    poid -= 2.5;
}

void gestion_etat(void)
{
  if(variable_etat_obtenir_valeur(niv_faim) <= 0 || variable_etat_obtenir_valeur(humeur) <= 0)
    alive = 0;
}

void gestion_faim(void)
{
  if((difftime(time(NULL), variable_etat_obtenir_temps(niv_faim))/CYCLE) >= DURE_FAIM){
    variable_etat_ajouter_valeur(niv_faim, -1);
    variable_etat_actualiser_temps(niv_faim);
    }
}
