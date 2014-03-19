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



typedef enum {ROUGE=0, BLEU=1, VERT=2} tCouleur;
typedef tCouleur tTabCouleurs[MAX_SOMMETS];


void parcour_Profondeur(tGraphe g,char* sommet){
  
  
  int i,nbVoisin;
  
  tNumeroSommet sommetDepart,suivant,x;
  tNomSommet nom;
 tTabCouleurs coul;
  tPileSommets file;
  
  
  file= pileSommetsAlloue();
  sommetDepart=grapheChercheSommetParNom(g,sommet);
  
  // n opérations pour la boucle
  for (i=0;i<grapheNbSommets(g);i++)
    coul[i]=1;
  coul[sommetDepart] = 2;


  printf("\n\n\n\ndebut de l'empilade\n");
  pileSommetsEmpile(file,sommetDepart);
  while(!pileSommetsEstVide(file))
    {
      x=pileSommetsDepile(file);
      nbVoisin=grapheNbVoisinsSommet(g,x);
   
      for(i=0;i<nbVoisin;i++)
	{
	  suivant=grapheVoisinSommetNumero(g,x,i);
	  if(coul[suivant]==1)
	    {
	      coul[suivant]=2;
	      pileSommetsEmpile(file,suivant);
	      
	    }
	  coul[x]=0;
	     grapheRecupNomSommet(g,x,nom);
      printf("%s est trouvé\n",nom);
	}
    }  
}









int main(int argc, char *argv[]) {
  
  tGraphe graphe;
  
  
  
  if (argc<3) {
    halt("Usage : %s FichierGraphe\n", argv[0]);
  }
  
  
  graphe = grapheAlloue();
  grapheChargeFichier(graphe, argv[1]);
  parcour_Profondeur(graphe,argv[2]);
  grapheLibere(graphe);
  exit(EXIT_SUCCESS);
}
