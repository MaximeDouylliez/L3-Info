/**********************************************************************
 *testAnalyseur.c
 *
 *  (François lemaire)  <Francois.Lemaire@lifl.fr> 
 * Time-stamp: <2010-10-06 15:06:29 lemaire>
 ***********************************************************************/

/* Ce program prend un nom de graphe en entrée, le charge,
   et l'affiche de façon détaillée.
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "graphe.h"


void affSommetFamous(tGraphe g){

  int bmax,cpt,stock,buffer,indice;
  char* nom;
  bmax=grapheNbSommets(g);
  stock=0;

  printf("\n\n\n\n\nLe sommet avec le plus de voisin est:\n");

  for(cpt=0;cpt<bmax;cpt++)
    {
      if((buffer=grapheNbVoisinsSommet(g,cpt))>stock)
	{
	  stock=buffer;
	  indice=cpt;
	 
	}
    }
  nom=malloc(20*sizeof(char)); 
  grapheRecupNomSommet(g,indice,nom);
  printf("%s\n",nom);
  free(nom);
  printf("Fin\n\n\n\n\n");


}

  void affSommetSeul(tGraphe g){



  int bmax,cpt;
  char* nom;
  bmax=grapheNbSommets(g);

  printf("\n\n\n\n\nLes sommets sans voisins sont:\n");

  for(cpt=0;cpt<bmax;cpt++)
    {
      if(grapheNbVoisinsSommet(g,cpt)==0)
	{
	  nom=malloc(20*sizeof(char)); 
	  grapheRecupNomSommet(g,cpt,nom);
	  printf("%s\n",nom);
	  free(nom);
	}
    }
      printf("Pas plus de sommets sans voisins\n\n\n\n\n");
  }





int main(int argc, char *argv[]) {

  tGraphe graphe;

  if (argc<2) {
    halt("Usage : %s FichierGraphe\n", argv[0]);
  }

  
  graphe = grapheAlloue();
  
  grapheChargeFichier(graphe,  argv[1]);
    grapheAffiche(graphe);
    //affSommetSeul(graphe);
    //affSommetFamous(graphe);

  grapheLibere(graphe);

  exit(EXIT_SUCCESS);
}
