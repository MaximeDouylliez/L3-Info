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



void aff_distance(tGraphe g,int* d,tNumeroSommet* pred,char* sommet){

 tNomSommet nom;
 int i;
 
 for(i=0;i<grapheNbSommets(g);i++){
grapheRecupNomSommet(g,i,nom);
   printf("\n%s est a distance %d de %s",nom,d[i],sommet);

 }printf("\n");
}

 void  aff_plus_courte_chaine(tGraphe g,int* d,tNumeroSommet* pred,char* sommet_depart,char* sommet_fin){
    tNomSommet nom;
    tNumeroSommet x;
    
    if (strcmp(sommet_depart,sommet_fin)!=0){
        x=grapheChercheSommetParNom(g,sommet_fin);
	  grapheRecupNomSommet(g,pred[x],nom);
 printf("\n%s est a distance %d de %s",sommet_fin,d[x],sommet_depart);
      aff_plus_courte_chaine(g,d,pred,sommet_depart,nom);
     
    }
  else  printf("\n\nbienvenue a bord\n");
 }




 

void parcour_Largeur(tGraphe g,char* sommet,char* sommett){


  int i,nbVoisin;
  int d [MAX_SOMMETS];
  tNumeroSommet pred[MAX_SOMMETS];
  tNumeroSommet sommetDepart,suivant,x;
  tNomSommet nom;
  tTabCouleurs coul;
  tFileSommets file;
  

  file= fileSommetsAlloue();
  sommetDepart=grapheChercheSommetParNom(g,sommet);


  for (i=0;i<grapheNbSommets(g);i++)     
	coul[i]=BLEU;  
  coul[sommetDepart]=1;
  printf("\n\n\n\ndebut de l'enfilade\n");
  fileSommetsEnfile(file,sommetDepart);
  d[sommetDepart]=0;
  pred[sommetDepart]=NULL;

  while(!fileSommetsEstVide(file))
    {
      x=fileSommetsDefile(file);
      // printf("plop");
      nbVoisin=grapheNbVoisinsSommet(g,x);
    

      for(i=0;i<nbVoisin;i++)
	{
	  suivant=grapheVoisinSommetNumero(g,x,i);


	  if(coul[suivant]==BLEU)
	    {
	      coul[suivant]=VERT;
	      fileSommetsEnfile(file,suivant);
	      d[suivant]=d[x]+1;
	      pred[suivant]=x;
	 
	    }

	}
      grapheRecupNomSommet(g,x,nom);
      printf("%s est trouvé\n",nom);
      coul[x]=ROUGE;
    }


  aff_distance(g,d,pred,sommet);

  aff_plus_courte_chaine(g,d,pred,sommet,sommett);


}


 
  





int main(int argc, char *argv[]) {

  tGraphe graphe;



  if (argc<3) {
    halt("Usage : %s FichierGraphe\n", argv[0]);
  }
  
  graphe = grapheAlloue();
  grapheChargeFichier(graphe, argv[1]);
  parcour_Largeur(graphe,argv[2],argv[3]);
  grapheLibere(graphe);
  exit(EXIT_SUCCESS);
}
