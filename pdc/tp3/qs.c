#include "qs.h"




int comp_entier(int a, int b)
{
  if(a>b)
    return 1;
  else if (a<b)
    return -1;
  else return 0;

}

int comp_double(double a, double b)
{
  if(a>b)
    return 1;
  else if (a<b)
    return -1;
  else return 0;
}

int comp_char(char a, char b)
{
  if(a>64 && a<91)
    a+=32;
  if(b>64 && b<91)
    b+=32;

  if(a>b)
    return 1;
  else if (a<b)
    return -1;
  else return 0;
}





char*  get(char* tab,int i, int size)
{
  char* chaine;
  chaine= malloc(size*sizeof(char));

  for (i=0;i<size;i++)
    chaine[i]=tab[i];
  return chaine;
}



void swap(char *tab,int i1,int i2,int size)
{ 
  char c;
  int i;

  for (i=0;i<size;i++)
    {
      c=tab[i1*size+i];
      tab [i1*size+i]= tab [i2*size+i];
      tab[i2*size+i]=c;
    }
}

int  sort_gauche(void* tab,int ipivot,int  imontant,int size,int nelem,
int(*compar)(const void*, const void*))
{
  if((compar(get(tab,imontant,size),get(tab,ipivot,size))!=1) && (imontant<nelem-1))
    return sort_gauche(tab,ipivot,imontant+1,nelem,size,compar);
  else
    return imontant;
}

int  sort_droite(void* tab,int ipivot,int idescendant,int size,
int(*compar)(const void*, const void*))
{
  if((compar(get(tab,ipivot,size),get(tab,idescendant,size))!=1)&& (idescendant>0))
    return sort_droite(tab,ipivot,idescendant-1,size,compar);
  else
    return idescendant;
}

void
quicksort
(void* base,int nelem,int size,
 int(*compar)(const void*, const void*))
{

  int ipivot,imontant,idescendant;

  if (nelem>1){

    //  lister_tableau_int(tab,nelem);
    imontant=0;
    idescendant=nelem-1;
    ipivot=0;

    while(imontant<idescendant)
      { 
	idescendant= sort_droite(base,ipivot,idescendant,size,compar);
	imontant= sort_gauche(base,ipivot,imontant,size,nelem,compar);  
    
	//   printf("m:%d d:%d p:%d\n\n",imontant+1,idescendant+1,ipivot+1); 
	if(imontant<idescendant)
	  {
	
	    swap(base,imontant,idescendant,size);
	    //  printf("swap des valeurs !\n");
	  }
      }

    swap(base,ipivot,idescendant,size);
    ipivot=idescendant;
 
    //  lister_tableau_int(tab,nelem);
    // printf("recursion gauche\n");
    quicksort(base,ipivot,size,compar);
    //printf("recursion droite\n");
    quicksort(base+((ipivot+1)*size),nelem-ipivot-1,size,compar);
    

  }
  
}

