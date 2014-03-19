executable: graphe.o  largeur.o profondeur.o
	gcc -o test graphe.o  largeur.o
	gcc -o toto graphe.o profondeur.o

graphe.o: graphe.c graphe.h
	gcc -c -Wall -g -std=c99 graphe.c

largeur.o:largeur.c
	gcc -c -Wall -g -std=c99 largeur.c

profondeur.o:profondeur.c
	gcc -c -Wall -g -std=c99 profondeur.c