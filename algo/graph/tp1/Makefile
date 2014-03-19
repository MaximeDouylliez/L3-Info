executable: graphe.o testAnalyseur.o hellograph.o #tp1.o
#	gcc -o koko  graphe.o tp1.o
	gcc -o test graphe.o testAnalyseur.o
	gcc -o hellotest graphe.o  hellograph.o

graphe.o: graphe.c graphe.h
	gcc -c -Wall -g -std=c99 graphe.c

hellograph.o:hellograph.c
	gcc -c -Wall -g -std=c99 hellograph.c

testAnalyseur.o: testAnalyseur.c
	gcc -c -Wall -g -std=c99 testAnalyseur.c

tp1.o:tp1.c
	gcc -c -Wall -g -std=c99 tp1.c

