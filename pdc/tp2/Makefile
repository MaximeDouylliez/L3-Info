


tp: mcolrm.o util.o mcut.o mlook.o mgrep.o
	gcc -o mcolrm  mcolrm.o util.o
	gcc -o mcut  mcut.o util.o
	gcc -o mlook mlook.o util.o
	gcc -o mgrep mgrep.o util.o

mcolrm.o: mcolrm.c
	gcc -c -Wall mcolrm.c

mcut.o: mcut.c
	gcc -c -Wall mcut.c

mlook.o: mlook.c
	gcc -c -Wall mlook.c

mgrep.o: mgrep.c
	gcc -c -Wall mgrep.c

util.o: util.c util.h
	gcc -c -Wall util.c

