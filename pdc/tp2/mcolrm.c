#include "util.h"


void
colrm
( int argv1,int argv2)
{
  int indice,sortie;
  char* buffer_ligne;
  sortie=0;
  buffer_ligne=malloc((MAX_LINE+1) * sizeof(char));
 

  if(argv2==-1) /*evite la duplication de code, voir le test de colonne*/
    argv2=argv1;
  while ((sortie=readl(buffer_ligne))!=EOF)
    /*tant qu'il y a des lignes*/
    {
      //lister_tableau(buffer_ligne);
      for(indice=0;buffer_ligne[indice]!='\0';indice++)
	/*tant que la ligne n'est pas terminé*/
	{
	  if(indice<argv1-1 || indice>argv2-1)
	    /*gere l'appel a 1 et 2 arguments*/
	    {
	      printf("%c",buffer_ligne[indice]);
	    }
	}
      putchar('\n');
      buffer_ligne=malloc((MAX_LINE+1) * sizeof(char));
    }
}


int
main 
(int argc, char *argv[])
{

  //  int i;
  fatal(((argc==2 || argc==3)),"Nombre d'arguments invalide",2);
  /* for (i=1;i<argc;i++)
     {
     printf("%d",atoi(argv[i]));
     }*/

  if(argc==1)
    {
      colrm(atoi(argv[1]),atoi("-1"));
    }
  else
    {
      fatal(atoi(argv[1])<atoi(argv[2]),"Le premier argument doit etre inférieur au second !",2);
      colrm(atoi(argv[1]),atoi(argv[2]));
    }

  return 0;
}

