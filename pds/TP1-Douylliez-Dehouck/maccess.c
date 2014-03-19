
#include <limits.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

#define XOPEN_SOURCE 500


char* mode(int i) {
		
  switch ( i ) {
  case 1 :
    return "Write\n";
    break;
  case 2 :
    return "Read\n";
    break;
  case 3 :
    return "Execute\n";
    break;
  default :
    return "Ne doit pas arriver\n";
    break;
  }
  return "N'arrive pas non plus\n";
}


int main( int argc, char** argv) {

  int i;
  int opt[4] = {0};
  int res[4] = {0};
		
  if (argc < 3 || argc > 6) {
    printf("Usage : maccess [-v] (-w,r,x) nomDuFichier\n");
    return 1; 
  }

  for (i=1; i< argc-1; i++) {
    if(! (strcmp(argv[i], "-v")))
      opt[0] = 1;
    if(! (strcmp(argv[i], "-w")))
      opt[1] = 1;
    if(! (strcmp(argv[i], "-r")))
      opt[2] = 1;
    if(! (strcmp(argv[i], "-x")))
      opt[3] = 1;
  }

  if (argc-2 != opt[0]+opt[1]+opt[2]+opt[3]) {
    printf("Usage : maccess [-v] (-w,r,x) nomDuFichier\n");
    return 1;
  }

  if ( opt[1])
    res[1] = access(argv[argc-1], W_OK) * (-1) * errno ;
  if ( opt[2])
    res[2] =  access(argv[argc-1], R_OK) * (-1) * errno ;
  if ( opt[3])
    res[3] =  access(argv[argc-1], X_OK) * (-1) * errno ;

	
  if (! opt[0])
    return res[1]+res[2]+res[3];


  for (i=1; i<=3; i++) {
    if ( opt[i]){
      printf("\n%d\n",res[i]);
      switch ( res[i]) {
							
      case EACCES : 
	printf ("Le droit d'acces %s au fichier n'est pas positionne.\n", mode(i));
	break;
      case EMLINK : 
	printf ("trop de lien symbolique \n");
	break;
      case 36 : 
	printf ("Nom ou Path trop long\n");
	break;
      case 20 : 
	printf ("Un des composants du path n'est pas un répértoire\n");
	break;
      case 2 : 
	printf ("Le fichier n'existe pas\n");
	break;
	
      default:  printf("Autre\n");
	break;
	
	
      }
    }
  }
  
  return 0;
  
}
