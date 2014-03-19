#include "util.h"


void print_arg(int argc, char** argv)
{
  int i;
  for(i=1;i<argc;i++)
    printf("%s\n",argv[i]);
}


void 
fatal 
(int assert, const char* message,int statuts)
{
  //  printf(" passage dans fatal: valeur de l'assert= %d\n",assert);
  if(!assert)
    {
      fprintf(stderr,"%s\n",message); 
      exit(statuts);
    }  
 
}


int
readl
(char* line)
{
  int cpt;
char buffer;

  cpt=0;
  while ((buffer=getchar())!= EOF && (buffer !='\n') && (cpt < MAX_LINE))
    {     
      line [cpt]=buffer;
      cpt++;
      //  printf("readl:%c\n",buffer);
    }
  fatal(((buffer==EOF || buffer=='\n')) ,"Chaine de caractere trop longue",2);
  // printf("%d",cpt);
  line [cpt+1]='\0';
  // lister_tableau(line);
  // printf("%c",buffer);
  if(buffer==EOF)
    return EOF;
  else
    return cpt+1;
}



void lister_tableau(char* tab)
{
 printf("entree dans lister_tableau\n");
  int i;
  for (i=0;tab[i]!='\0';i++)
    {
      printf("%c\n",tab[i]);
      }
   printf("sortie de Lister_tableau\n");
}
/*
int main ()
{
   char* lol;
   lol=malloc(MAX_LINE*sizeof(char));
   readl(lol);
   lister_tableau(lol);
   // printf(("%s"),lol);
  return 0;
  }*/


