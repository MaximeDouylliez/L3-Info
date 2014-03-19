#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
 
char  doubler(char arg){
  return (arg +1 );
}



void forkfork(int arg){
  int pid;
 
  /*interaction entre le pere et le fils*/
  if((pid=fork())==-1){
    printf("Probleme f1\n");
    exit(0);
  }

  if (pid!=0)/*actions du papa*/
    {
      wait(pid);
      exit(0);
    }

  else{

    if((pid=fork())==-1){
      printf("Probleme f2\n");
      exit(0);
    }
	 
    if (pid!=0)/*Actions du fils*/
      exit(0);

    else /*action du petit fils*/
      {
	printf("%c\n",  doubler(arg));
	     
      }
  }
}




int main (int argc, char** argv){

  printf("hello:  %c\n\n",argv[1][0]);
  forkfork(argv[1][0]);
  return 0;
}
