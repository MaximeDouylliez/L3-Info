



CC = gcc
CFLAGS = -Wall -ansi -pedantic -g -D_XOPEN_SOURCE=500

EXEC = prlimit maccess

all : $(EXEC)

prlimit : prlimit.o
	$(CC) -o prlimit prlimit.o
	
prlimit.o : prlimit.c
	$(CC) -c $(CFLAGS) prlimit.c

maccess : maccess.o
	$(CC) -o maccess maccess.o

maccess.o : maccess.c
	$(CC) -c $(CFLAGS) maccess.c




.PHONY : clean mrproper

clean :
	rm -f *.o

mrproper :
	rm $(EXEC)
