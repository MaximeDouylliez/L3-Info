#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

#define BUFFSIZE 5



int index_tail_buffer(const char* buffer,int buffSize,int ntail,int* nlines){ /* renvoi l'indice du dernier caractere lu et met a jour le nombre de ligne lu*/

  int i;

  i=buffSize-1;
 
 

  while(i>=0 && *nlines<ntail){
    if(buffer[i]=='\n')
      (*nlines)++;
    i--;
  }

 
  

  if(*nlines==ntail)
    return i+1;
  
  return -1;
}

int tail_rec(int fd, int* nlines,int* indi,/*int ver,*/int but){

  int useless,indice; 
  char buffer[BUFFSIZE];
  
 

  useless=0;
 
  if (lseek(fd, -BUFFSIZE*(*indi), SEEK_END) != -1) /* positionement du marqueur dans le descripteur de fichier*/
    {
      useless = read(fd, buffer, BUFFSIZE);
 
      indice=index_tail_buffer(buffer,useless,but,nlines);
      (*indi)++;
    } 
  else{
    printf(" erreur, fichier pas assez grand !\n");
    exit(1);
  }
  if((*nlines)!=but)
    {
      tail_rec(fd,nlines,indi,but);
      printf("%s",buffer);
    }
  else printf("%s",buffer+indice);

  return 0;

}


int main(int argc,char**argv){

  int fd;
  int value,ind;
  int *nlines,*indi;

  value=-1,ind=1;
  nlines=&value,indi=&ind;

  fd = open(argv[1], O_RDONLY);
  tail_rec(fd,nlines,indi,atoi(argv[2]));
  return 0;
}




				
 
