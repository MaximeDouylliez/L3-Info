#include <stdio.h>
#include <stdlib.h>







void game(int valeur){

  int isWin;
  int valeur_Joueur,valeur_Jeu,cpt_Tour;

  valeur_Jeu=valeur;
  isWin=0;
  cpt_Tour=0;


  while(!isWin){
    cpt_Tour++;
    printf("\n%d tours de jeu, donnez une valeur !\n",cpt_Tour);
    scanf("%d",&valeur_Joueur);

    if(valeur_Joueur==valeur_Jeu){
      isWin=1 ;
      printf("\nVous avez gagné au bout de %d tours",cpt_Tour);}
    else {

      if(valeur_Joueur>valeur_Jeu)
   printf("\n%d trop haute ! valeur mystere doublé\n",valeur_Joueur); 
else
  printf("\n%d trop basse ! valeur mystere doublé\n",valeur_Joueur); 
    valeur_Jeu*=2;
    }

 
}





}

int alea (int bmin, int bmax)
{                                                           //creation d'une valeur aléatoire
  int nombre;                                              //pour le choix du bot entre bmin et bmax
                                                          
    nombre = bmin + rand() % (bmax - bmin + 1);
    return nombre;
}

int main( char** argv , int argc){
  game(alea(1,100));
  return 0;
}
