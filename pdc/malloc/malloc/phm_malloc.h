/* ------------------------------
   $Id: phm_malloc.h,v 1.2 2005/11/30 07:39:18 marquet Exp $
   ------------------------------------------------------------

   Ma bibliotheque d'allocation mémoire
   
   http://www.lifl.fr/~marquet/cnl/pdc/tpbam.html

   Philippe Marquet, Nov 2005
   
*/

#ifndef _PHM_MALLOC_H_
#define _PHM_MALLOC_H_

/* malloc() and free() replacement */
void *
phm_malloc (size_t size,	/* as in malloc() */
	    char *filename,	/* source filename of the function call */
	    unsigned line); 	/* source line number of the f. call */

void
phm_free (void *ptr,		/* as in free() */
	  char *filename,	/* filename and line of the call */
	  unsigned line);

/* malloc and free as wrappers */
#define malloc(sz)      phm_malloc(sz, __FILE__, __LINE__)
#define free(ptr)       phm_free(ptr, __FILE__, __LINE__)

#endif
