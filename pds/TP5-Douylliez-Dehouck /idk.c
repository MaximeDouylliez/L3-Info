#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>




void on_do(char* pred,char* cmd)
{
  int pid,statut;
  int* pstatut;
  pstatut=&statut;


  if (pid=fork()==0)
    exec(pred);

  if(waitpid(pid,pstatut,0))
    exec(cmd);
}

void forkintelligent()
  {
    int i;

    for(i=0;i<10;i++)
      {
	if(fork()==0)
	  fils();
      }
  }








int main(int arc,char** argv)
{


  on_do(argv[1],argv[2]);
  


  return 0;
}


  /* table de processus. si signal kill on arrete le processus mais on ne l'elimine pas de la table des processus. il est essentiel que le systeme fasse un wait pour enelver le mode zombie*/

  /* on pred do cmd veut dire qu'on execute cmd si pred reussit */


/* le pere veut executer cmd mais il attend son fils qui a muté pour executer pred et on vois si c'est exit success*/


/* exec remplace le code donc si printf pour message d'erreur il n'apparaitra jamais*/

/* execvp(char*  nom commande ,char**  liste argument)*/

/* dans la ligne d'arguement au lancement du programme il faut delimiter les arguements de la premiere commande et de la seconde. entre les deux commande on insere le mot clé "do"*/

/*if(strcmp(argv[i],"do")==0)
argv[i]="/0";*/


/* wifexited(statut) && wexitstatut(statut)==ok*/

/* wifexited(statut) verifie que le processus n'a pas ete tué*/
