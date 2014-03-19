/* ------------------------------
   $Id: phm_malloc.c,v 1.1 2005/11/24 14:28:58 marquet Exp $
   ------------------------------------------------------------

   Exemple basique de redefinition de la bibliotheque standard
   d'allocation memoire 

   http://www.lifl.fr/~marquet/cnl/pdc/tpbam.html
   
   Philippe Marquet, Nov 2005
   
*/

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

#include "tools.h"
#include "phm_malloc.h"

/* forward definition  */
static void print_malloc_calls(void);

/* Memory chunk size */
#define MSIZE		100000

/* malloc() call trace */
#define MAX_CALL	100 
#define MAX_STR		40 

/* Number of call to the malloc() and phm_malloc() functions */
static int malloc_count = 0; 

/* A data structure to keep trace of a call to a malloc function */
enum  call_e {FREE_CALL, MALLOC_CALL}; 
struct call_s{
    char cl_file[MAX_STR]; 
    unsigned int cl_line; 
    unsigned cl_size; 
    enum call_e cl_type;   
};

/* We keep trace of MAX_CALL calls */
static struct call_s malloc_calls[MAX_CALL];
static int next_call = 0;

/* The memory is a sole memory segment returned by a sole call to
   sbrk(). 
   This memory chunk is handled as a great array.
   No memory de-allocation occurs.
   Out of bound accesses are not ckecked.
   The initial NULL value indicates that the array is not yet
   allocated.
*/
static char *memory = NULL;

/* My own malloc */
void *
phm_malloc (size_t size,	/* as in malloc() */
	    char *filename,	/* source filename of the function call */
	    unsigned line) 	/* source line number of the f. call */
{
    void *ptr;
    static int first_call = TRUE;

    if (first_call) {
	first_call = FALSE;
	atexit(print_malloc_calls);
    }
	
    /* one more call */
    malloc_count++; 

    /* keep trace of the call in malloc_calls[] */
    if (next_call < MAX_CALL) {
	strncpy(malloc_calls[next_call].cl_file,
		filename ? filename : "??",
		MAX_STR); 
	malloc_calls[next_call].cl_line = line; 
	malloc_calls[next_call].cl_size = size; 
	malloc_calls[next_call].cl_type = MALLOC_CALL;   
	next_call++;
    }

    /* memory already allocated? */    
    if (! memory) 
	memory = sbrk(MSIZE); 

    /* memory allocation */
    ptr = memory;
    memory += size;
    
    return ptr;
}

/* My own free() */
void
phm_free (void *ptr,		/* as in free() */
	  char *filename,	/* filename and line of the call */
	  unsigned line) 
{
    /* in fact, we do not free the memory... */
    
    /* keep trace of the call */
    if (next_call < MAX_CALL) {
	strncpy(malloc_calls[next_call].cl_file,
		filename ? filename : "??",
		MAX_STR); 
	malloc_calls[next_call].cl_line = line; 
	malloc_calls[next_call].cl_type = FREE_CALL;   
	next_call++;
    }
    
}

/* Print trace of the calls to malloc() and free() */
static void
print_malloc_calls(void) 
{
    int i ; 

    fprintf(stderr, "------------------------------\n"
	            " Trace des appels a malloc()\n"
                    "------------------------------"
                    "------------------------------\n");
    fprintf(stderr, "%d appel(s) a malloc()\n", malloc_count) ; 
    for (i=0; i<next_call; i++) {
	switch (malloc_calls[i].cl_type) {
	    case MALLOC_CALL: 
		fprintf(stderr, 
			"Dans %18s, ligne %5d, %5d octets demandes\n", 
			malloc_calls[i].cl_file, 
			malloc_calls[i].cl_line, 
			malloc_calls[i].cl_size); 
		break; 
	    case FREE_CALL: 
		fprintf(stderr, 
			"Dans %18s, ligne %5d, appel de free()\n", 
			malloc_calls[i].cl_file, 
			malloc_calls[i].cl_line);  
		break; 
	}
    }
    fprintf(stderr, "------------------------------\n");
}

  
