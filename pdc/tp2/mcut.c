#include "util.h"

#define  DELIMITEUR ' '

void 
mcut
(int argc,char** argv)
{
  int indice1,indice2,i,col,sortie;
  char delim,c;
  char* buffer_ligne;

  sortie=0;
  col=1;
  delim=argv[1][0];
 
  buffer_ligne=malloc((MAX_LINE+1) * sizeof(char));
 

  //printf("entree dans mcut\n");
  while ((sortie=readl(buffer_ligne))!=EOF)/*tant qu'il y a des lignes*/
    {
      //printf("mcut2\n");
      for(indice1=0;buffer_ligne[indice1]!='\0';indice1++)
	/*tant que la lignes n'est pas terminé*/
	{  
	  c=buffer_ligne[indice1];
	  //	  	  printf("mcut3\n%c\n",c);
	  if(c==delim)/* si delim, alors on imprime un bete espace sinon...*/
	    {
	      col++;
	      // printf("delim !\n");
	   for(indice2=2;indice2<=argc-1;)
	     {	
		  if (col==(atoi(argv[indice2])))
		    {
		      putchar(DELIMITEUR);
		      indice2=argc+1;
		    }
		  else indice2++;
		}
	    }
	  else
	    {
	      for(indice2=2;indice2<=argc-1;)
		/*on compare l'indice de colonne avec les fieldno*/
		{ // printf("col:   %d\n",col);
		  //  printf("mcut4    indice: %d  tab:   %s\n",indice2,argv[indice2]);
		  if (col==(atoi(argv[indice2])))
		    {
		      //   printf("cut!\n");
		      printf("%c",buffer_ligne[indice1]);
		      indice2=argc+1;
		    }
		  else indice2++;
		}
	    }
	}


      putchar('\n');
      buffer_ligne=malloc((MAX_LINE+1) * sizeof(char));
    }
}



int
main
(int argc,char** argv)
{

  //  printf("entree dans main,argc=%d\n",argc);
  fatal((argc>=2),"nombre insuffisant d'argument",2);
  //  print_arg(argc,argv);
  mcut(argc,argv);

  return 0;
}
