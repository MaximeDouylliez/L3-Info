#include "util.h"



int
mlook
(char* mot)
{

  int lgmot,lgphrase,nbvalidline;
  char* ligne_buffer;

  fatal((lgmot=strlen(mot))>0,"Longueur de mot incorecte",2);
  ligne_buffer=malloc((MAX_LINE+1) *sizeof(int));
  nbvalidline=0;

  while(readl(ligne_buffer)!=EOF)//tant qu'il y a des lignes
    {
 
      lgphrase=strlen(ligne_buffer);
      /*   printf("test de la ligne %s ",ligne_buffer);
	   printf(" longueur= %d\n",lgphrase);*/
	  if(!(lgmot<=lgphrase));//si la phrase est au moin aussi longue que le mot
	  else
	    {
	      //printf("passance dans strcmp\n");
	      if((strstr(ligne_buffer,mot))!=NULL)//si le mot est contenu
		{
		  printf("%s\n",ligne_buffer);
		  nbvalidline++;
		}
	    }
	
      ligne_buffer=malloc((MAX_LINE+1) *sizeof(int));
    }
  return nbvalidline;
}
	    


   
	




int
main
(int argc, char** argv)
{
  fatal(argc==2,"Nb Arguments invalide",2);
  /* printf("test\n");
     print_arg(argc,argv);*/
    fatal((mlook(argv[1]))>0,"Aucune ligne valable",2);

  return 0;
}