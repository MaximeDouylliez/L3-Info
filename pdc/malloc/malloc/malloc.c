/* ------------------------------
   $Id: malloc.c,v 1.2 2005/11/30 07:39:18 marquet Exp $
   ------------------------------------------------------------

   Exemple basique de redefinition de la bibliotheque standard
   d'allocation memoire 

   http://www.lifl.fr/~marquet/cnl/pdc/tpbam.html
   
   Philippe Marquet, Nov 2005
   
*/

#include <stddef.h>		/* for size_t */
#include "phm_malloc.h"

/* Forget definition of malloc wrappers */
#ifdef malloc
#undef malloc
#undef free
#endif

/* Redefinition of malloc () */
void *
malloc (size_t size)
{
    /* unknown source filename and line */
    return phm_malloc(size, (char *)0, 0); 
}

/* Redefinition of free () */
void
free (void *ptr) 
{
    /* unknown source filename and line */
    phm_free(ptr, (char*) 0, 0); 
}

