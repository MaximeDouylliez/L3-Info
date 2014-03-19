executable: graphe.o path_count.o
	gcc -o exe graphe.o path_count.o

graphe.o: graphe.c graphe.h
	gcc -c -Wall -g -std=c99 graphe.c

path_count.o:path_count.c
	gcc -c -Wall -g -std=c99 path_count.c