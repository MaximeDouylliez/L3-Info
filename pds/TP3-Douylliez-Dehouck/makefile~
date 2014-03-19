



CC = gcc
CFLAGS = -Wall -ansi -pedantic -g -D_XOPEN_SOURCE=500

EXEC = tail2

all : $(EXEC)

tail2 : tail2.o
	$(CC) -o tail2 tail2.o

tail2.o : tail2.c
	$(CC) -c $(CFLAGS) tail2.c


.PHONY : clean mrproper

clean :
	rm -f *.o

mrproper :
	rm $(EXEC)
