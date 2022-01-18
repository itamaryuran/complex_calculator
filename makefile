mycomp: mycomp.o 
	gcc -g -ansi mycomp.o -o mycomp -lm

mycomp.o: mycomp.c input.o
	gcc -c -Wall -ansi -pedantic mycomp.c -o mycomp.o

input.o: input.c complex.o  
	gcc -c -Wall -ansi -pedantic input.c -o input.o

complex.o: complex.c complex.h
	gcc -c -Wall -ansi -pedantic complex.c -o complex.o -lm
