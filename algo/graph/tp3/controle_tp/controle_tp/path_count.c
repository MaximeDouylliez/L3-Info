/**********************************************************************
 * path_count.c
 *
 *  (Charles Bouillaguet)  <charles.bouillaguet@lifl.fr>
 ***********************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "graphe.h"

/* Couleurs */
typedef enum {ROUGE=0, BLEU=1, VERT=2} tCouleur;
typedef tCouleur tTabCouleurs[MAX_SOMMETS];


// parcours en profondeur, à partir du sommet s
void DFS(tGraphe graphe, tNumeroSommet s, tTabCouleurs couleurs, tPileSommets pile_coloriage_rouge) {
  int i,nbVoisin;
  tNumeroSommet u;


  couleurs[s] = 2;
 
      nbVoisin=grapheNbVoisinsSommet(graphe,s);
   
      for(i=0;i<nbVoisin;i++)
	{
	  u=grapheVoisinSommetNumero(graphe,s,i);
	  if(couleurs[u]==1)
	    {
	      DFS(graphe,u,couleurs,pile_coloriage_rouge);
	      
	    }
	
	}
      couleurs[s]=0;
	 pileSommetsEmpile(pile_coloriage_rouge,s);
    }  



// tri topologique (des descendants de s).
// A la fin, les sommets doivent être empilés dans l'ordre topologique.
// Le premier doit être en haut de la pile (c.a.d. celui qui est dépilé en premier)
void tri_topologique(tGraphe graphe, tNumeroSommet s, tPileSommets pile_coloriage_rouge) {
  int i;
  tTabCouleurs couleurs;

  for (i=0;i<grapheNbSommets(graphe);i++)
    couleurs[i]=1;

  DFS(graphe,s,couleurs,pile_coloriage_rouge);

  // à compléter
}



// vérifie que l'ensemble des descendants de s forme un graphe acyclique
int is_DAG(tGraphe graphe, tNumeroSommet s) {
  int i;
  tPileSommets pile_coloriage_rouge = pileSommetsAlloue();
  tTabCouleurs couleurs;

  // à compléter
}

// calcul le nombre de chemins depuis s vers tous les autres sommets. Résultat dans N.
void count_paths(tGraphe graphe, tNumeroSommet s, int N[MAX_SOMMETS]) {
  int i;
  tPileSommets pile_coloriage_rouge = pileSommetsAlloue();

  // à compléter
}


// affiche la liste de tous les chemins
void list_paths(/* à compléter */) {
  int i;

  // à compléter
}



int main(int argc, char *argv[]) {

  tGraphe graphe;
  char *fic;
  int i;

  /* Traitement des arguments */
  if (argc < 3)
    halt("Usage : %s <fichier_graphe> <nom_sommet_depart>\n", argv[0]);

  fic = argv[1];

  /* Chargement du graphe */
  graphe = grapheAlloue();
  grapheChargeFichier(graphe, fic);
  if (!grapheEstOriente(graphe))
    halt("Le graphe doit être orienté\n");

  printf("Fichier : %s\n", argv[1]);

  // repère le sommet de départ
  tNumeroSommet s = grapheChercheSommetParNom(graphe, argv[2]);


  /* ***************
     Test tri topologique
     ***************

     Décommenter le commentaire suivant pour tester le tri-topologique
  */
  
  printf("TEST tri topologique : \n");
  tPileSommets pile_coloriage_rouge = pileSommetsAlloue();
  tri_topologique(graphe, s, pile_coloriage_rouge);
  while (!pileSommetsEstVide(pile_coloriage_rouge)) {
    int u = pileSommetsDepile(pile_coloriage_rouge);
    tNomSommet nom;
    grapheRecupNomSommet(graphe, u, nom);
    printf("%s  ", nom);
  }
  printf("\n");
  

  /* ***************
     Test is_DAG
     ***************
     Décommenter le commentaire suivant pour tester is_DAG
  */
  /*
  printf("TEST is_DAG : \n");
  if (is_DAG(graphe, s))
    printf("les successeurs de %s forment un DAG.\n", argv[2]);
  else
    printf("le graphe contient un cycle.\n");
  */

  /* *******************************
     Test count Paths
     *******************************
     Décommenter le commentaire suivant pour tester count_paths(...)
  */
  /*
  printf("TEST pathcount : \n");

  int N[MAX_SOMMETS];
  count_paths(graphe, s, N);
  for(i=0; i<grapheNbSommets(graphe); i++) {
    tNomSommet nom;
    grapheRecupNomSommet(graphe, i, nom);
    printf("%s --> %d\n", nom, N[i]);
  }
  */
  /* ***************
     Test list_paths
     ***************
     Décommenter le commentaire suivant pour tester list_paths(...)
  */

  exit(EXIT_SUCCESS);
}

