/* ------------------------------
   $Id: sc_malloc.c,v 1.1 2005/11/24 14:20:40 marquet Exp $
   ------------------------------------------------------------

   Utilisation minimale de malloc()/free() pour utilisation de ma
   bibliothèque de remplacement.  
   
   Philippe Marquet, Nov 2005
   
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "phm_malloc.h"

#define SUPER	"Supercalifragilisticexpialidocious"

int
main(void)
{
    char *str, *strcp; 

    /* Un appel direct à malloc */
    str = malloc(strlen(SUPER)+10); /* pourquoi 9 de trop ? pourquoi pas ! */

    strcpy(str, SUPER) ; 

    /* Un appel a malloc dans cet appel */
    strcp = strdup(str); 

    /* Print is not debug, nevertheless */
    printf("%s\n%s\n", str, strcp); 

    /* On libere la memoire allouee sur str est strcp*/
    free(str);
    free(strcp);

    exit(EXIT_SUCCESS);
}
