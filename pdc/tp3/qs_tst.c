#include "qs.h"
#include "util.h"

int
main
()
{

  void* tab;
  int  (*p) (const void* ,const void*);
  int size;
  size=4;
  p=&(comp_entier);
  tab=malloc(TABSIZE*sizeof(int));
  alea_tableau_int(tab,TABSIZE);
  // lister_tableau_int(tab,TABSIZE);
  quicksort(tab,TABSIZE,size,p);
 // lister_tableau_int(tab,TABSIZE);
 is_sorted_int(tab,TABSIZE);
  return 0;
}

