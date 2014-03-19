#include <stdlib.h>
#include <stdio.h>
#include "util.h"

void fonction(char* tab)
{
  int i;

  for(i=0;i<12;i++)
    {
      tab[i]=('a'+i);
      printf("salut %c\n",tab[i]);
    }
}


void lol()
{

  char c;
  while ((c=getchar())!=EOF)
    {
      printf("salut");
    }
    }

int main ()
{
  //char* tab;
  //int i;
  //i=12;
  // tab=malloc(20*sizeof(char));
  // fonction(tab);
  // lister_tableau(tab,i);
  lol();
  return 0;
}
