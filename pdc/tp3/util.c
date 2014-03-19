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



int alea (int bmin, int bmax)
{                            
  int nombre;                                              
                                                          
    nombre = bmin + rand() % (bmax - bmin + 1);
    return nombre;
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

void alea_tableau_int(int* tab,int lg)
{
  int i;
  i=0;
  while(i<lg)
    {
      tab[i]=alea(0,100);
      i++;
    }
}

void lister_tableau_int(int* tab,int lg)
{
  int i;
  i=0;

  while(i<lg)
    {
      printf("%d:%d ",i+1,tab[i]);
      if((i+1)%MAX_NUMBER_PER_LINE==0)
	putchar('\n');
      i++;
    }
  putchar('\n');
}
void is_sorted_int(int* tab, int lg)
{
  int i,x;
  i=1;
  x=tab[0];

  while(i<lg)
    {
      fatal(x<=tab[i],"tableau non trie correctement\n",2);
  x=tab[i];
  i++;
}
  printf("tableau trie correctement, bien joue captain\n");

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

