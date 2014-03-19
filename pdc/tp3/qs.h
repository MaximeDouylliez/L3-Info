#include <stdlib.h>
#include "util.h"
#define TABSIZE 10
void swap(char* tab,int i1,int i2,int size);
int comp_entier(int a, int b);
int comp_double(double a,double b);
int comp_char(char a,char b);
int  sort_gauche(void* tab,int ipivot,int  imontant,int size,int nelem,
		 int(*compar)(const void*, const void*));
int  sort_droite(void* tab,int ipivot,int idescendant,int size,
		 int(*compar)(const void*, const void*));
void quicksort (void* base,int nelem,int size,
int(*compar)(const void*, const void*));
