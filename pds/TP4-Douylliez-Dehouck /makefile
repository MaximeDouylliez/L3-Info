



CC = gcc
CFLAGS = -Wall -ansi -pedantic -g -D_XOPEN_SOURCE=500

EXEC = forkfork2

all : $(EXEC)

Y : forkfork2.o
	$(CC) -o forkfork2 forkfork2.o

forkfork2.o : forkfork2.c
	$(CC) -c $(CFLAGS) forkfork2.c


.PHONY : clean mrproper

clean :
	rm -f *.o

mrproper :
	rm $(EXEC)
