#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void race(){
  int pid,i,j,rep;

  for(i=0;i<10;i++) {
    if(pid!=0)  
      pid=fork();
  }

  if(pid!=0)
    {
      for(i=0;i<10;i++)
	{  
	  rep=wait(0);
	  printf("Arrivée de %d\n",rep);
	}
    }


  for(j=0;j<5000000;j++);
}




  int main(int arg,char** argv){
    race();
    return 0;
  }
