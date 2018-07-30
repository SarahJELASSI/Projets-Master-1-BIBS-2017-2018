all : main

Allocation_mem.o : Allocation_mem.c
	gcc -c -Wall -g -ansi Allocation_mem.c
	
Affichage.o : Affichage.c
	gcc -c -Wall -g -ansi Affichage.c
	
Outils.o : Outils.c
	gcc -c -Wall -g -ansi Outils.c
	
UPGMA.o : UPGMA.c
	gcc -c -Wall -g -ansi UPGMA.c
	
main_UPGMA.o : main_UPGMA.c
	gcc -c -Wall -g -ansi main_UPGMA.c
	
main : main_UPGMA.o UPGMA.o 
	gcc main_UPGMA.o Allocation_mem.o Affichage.o Outils.o  UPGMA.o -o main

clean : 
	rm *o
	
mrproper :
	rm *o main
	
