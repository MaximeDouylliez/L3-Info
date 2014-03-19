#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

#define BUFFSIZE 5


int index_tail_buffer(const char* buffer,int buffSize,int ntail,int* nlines){

  int i;

  i=buffSize-1;
 
  /*  printf("hello:\n\"\n%s\"",buffer);*/

  while(i>=0 && *nlines<ntail){
    if(buffer[i]=='\n')
      (*nlines)++;
    i--;
  }

  /*printf("\n%c\n",buffer[i]+1);*/
  

  if(*nlines==ntail)
    return i+1;
  
  return -1;
}

int tail_rec(int fd, int* nlines,int* indi,int ver,int but){

  int useless,indice; 
  char buffer[BUFFSIZE];

  if(ver==1)
    printf("fichier ne contient pas dix lignes !");
  else{

  useless=0;
  if (lseek(fd, -BUFFSIZE*(*indi), SEEK_END) != -1)
{
    useless = read(fd, buffer, BUFFSIZE);
    if (useless!=BUFFSIZE)
      ver=1;
    indice=index_tail_buffer(buffer,useless,10,nlines);
    (*indi)++;
  } 
  if(*nlines!=but)
{
  tail_rec(fd,nlines,indi,ver);
    printf("%s",buffer);
}
  else printf("%s",buffer+indice);
  }
  return 0;

}


int main(int argc,char**argv){

  int fd;
  int value,ind;
  int *nlines,indi;

  printf("salut\n");
  value=-1,ind=1;
  nlines=&value,indi=&ind;

  fd = open(argv[1], O_RDONLY);
  tail_rec(fd,nlines,indi,0,atoi(argv[2]);
  return 0;
}




				
 
