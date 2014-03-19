# $Id: malloc.make,v 1.2 2005/11/24 14:30:05 marquet Exp $
#------------------------------------------------------------

# Le compilateur C 
CC      = gcc
CFLAGS  = -Wall -Werror -ansi -pedantic
CFLAGS += -D_XOPEN_SOURCE=500
CFLAGS += -g

###------------------------------
### Default entry
###------------------------------------------------------------
all: libmalloc.so sc_malloc

###------------------------------
### Entries
###------------------------------------------------------------
sc_malloc: sc_malloc.o malloc.o phm_malloc.o
	$(CC) $(CFLAGS) -o $@ $^

malloc.o : malloc.c phm_malloc.h
	$(CC) $(CFLAGS) -fPIC -c malloc.c
phm_malloc.o : phm_malloc.c phm_malloc.h tools.h

libmalloc.so : malloc.o phm_malloc.o 
	$(CC) -shared -Wl,-soname,libmalloc.so -o libmalloc.so $^

###------------------------------
### Misc entries
###------------------------------------------------------------

.PHONY: clean realclean
clean realclean : 
	$(RM) core a.out *.o *.a *.so sc 


