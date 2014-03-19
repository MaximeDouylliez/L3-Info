#include <stdlib.h>
#include "util.h"
#define TABSIZE 10000
void swap(int tab[],int i1,int i2);
int comp_entier(int a, int b);
int  sort_gauche(int tab[],int ipivot,int  imontant, int nelem);
int sort_droite(int tab[],int ipivot,int idescendant);
void quicksort_int(int tab[], unsigned int nelem);
