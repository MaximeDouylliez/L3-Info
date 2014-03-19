#include "qsint.h"




void swap(int tab[],int i1,int i2)
{
  int var;

  var= tab[i1];
  tab[i1]=tab[i2];
  tab[i2]=var;
}

int comp_entier(int a, int b)
{
  if(a>b)
    return 1;
  else if (a<b)
    return -1;
  else return 0;
}



int  sort_gauche(int tab[],int ipivot,int  imontant,int  nelem)
{
  if((comp_entier(tab[imontant],tab[ipivot])!=1)&& (imontant<nelem-1))
    return sort_gauche(tab,ipivot,imontant+1,nelem);
  else
    return imontant;
}

int  sort_droite(int tab[],int ipivot,int idescendant)
{
  if((comp_entier(tab[ipivot],tab[idescendant])!=1)&& (idescendant>0))
    return sort_droite(tab,ipivot,idescendant-1);
  else
    return idescendant;
}

void
quicksort_int
(int tab[], unsigned int nelem)
{

  int ipivot,imontant,idescendant;

  if (nelem>1){

    //  lister_tableau_int(tab,nelem);
    imontant=0;
    idescendant=nelem-1;
    ipivot=0;

    while(imontant<idescendant)
      { 
	idescendant= sort_droite(tab,ipivot,idescendant);
	imontant= sort_gauche(tab,ipivot,imontant,nelem);  
    
	//   printf("m:%d d:%d p:%d\n\n",imontant+1,idescendant+1,ipivot+1); 
	if(imontant<idescendant)
	  {
	
	    swap(tab,imontant,idescendant);
	    //  printf("swap des valeurs !\n");
	  }
      }

    swap(tab,ipivot,idescendant);
    ipivot=idescendant;
 
    //  lister_tableau_int(tab,nelem);
    // printf("recursion gauche\n");
    quicksort_int(tab,ipivot);
    //printf("recursion droite\n");
    quicksort_int(&tab[ipivot+1],nelem-ipivot-1);
    

  }
  
}


