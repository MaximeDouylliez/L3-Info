#include "qsint.h"
#include "util.h"

int
main
()
{

  int* tab;
  tab=malloc(TABSIZE*sizeof(int));
  alea_tableau_int(tab,TABSIZE);
  // lister_tableau_int(tab,TABSIZE);
 quicksort_int(tab,TABSIZE);
 // lister_tableau_int(tab,TABSIZE);
 is_sorted_int(tab,TABSIZE);
  return 0;
}
