#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
 
char  doubler(char arg){
  return (arg +1 );
}



void forkfork(int arg){
  int i,pid;


  for(i=0;i<2;i++){
 
    switch (i){ 

    case 0: /*interaction entre le pere et le fils*/
      if((pid=fork())==-1){
	printf("Probleme f1\n");
	exit(0);
      }

      if (pid!=0)/*actions du papa*/
	{
	  wait(pid);
	  exit(0);
	}
      break;

    case 1:/*interaction entre le fils et le petit fils*/
      if(pid==0)
	{
	  if((pid=fork())==-1){
	    printf("Probleme f2\n");
	    exit(0);
	  }
	 
	  if (pid!=0)/*mort du Fils*/
	    exit(0);

	  else /*action du petit fils*/
	    {
	      printf("%c\n",  doubler(arg));
	     
	    }
	}
      break;

    default: printf("pas sence arriver"); break;
    }
  }
}



int main (int argc, char** argv){

  printf("hello:  %c\n\n",argv[1][0]);
  forkfork(argv[1][0]);
  return 0;
}
