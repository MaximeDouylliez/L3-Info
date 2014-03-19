#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void alive(int n,int duree){
  int pid=1;
  int i,j,rep,blabla;


   

  for(i=0;i<n;i++) 
    {
      if(pid!=0) 
	{   
	  pid=fork();
	}
    }

  
  if(pid!=0){
    scanf("%d\n",&blabla);
    for(i=0;i<n;i++)
      rep=wait(0);
  }
    
  while(pid==0)
    {
        printf("je suis le processus  %d et je suis vivant !\n",getpid());
      sleep(5000);
      }
}




int main(int arg,char** argv){
  alive(atoi(argv[1]),atoi(argv[2]));
  return 0;
}
