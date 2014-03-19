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

int tail_rec(int fd, int* nlines,int* pind){

  int useless,indice; 
  char buffer[BUFFSIZE];

  useless=0;
  if (lseek(fd, -BUFFSIZE*(*pind), SEEK_END) != -1)
{
    useless = read(fd, buffer, BUFFSIZE);
    indice=index_tail_buffer(buffer,useless,10,nlines);
    (*pind)++;
  } 
  if(*nlines!=10)
{
    tail_rec(fd,nlines,pind);
    printf("%s",buffer);
}
  else printf("%s",buffer+indice);

  return 0;

}


int main(int argc,char**argv){

  int fd;
  int value,ind;
  int *nlines,pind;
  value=-1,ind=1;
  nlines=&value,pind=&ind;

  fd = open(argv[1], O_RDONLY);
  tail_rec(fd,nlines,pind);
  return 0;
}




				
 
