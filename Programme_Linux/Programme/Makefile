all: projet.exe 

main.o : main.c Projet.h
	gcc -c main.c -o main.o
	
Welcome.o : Welcome.c Projet.h
	gcc -c Welcome.c -o Welcome.o 
	
nettoyage.o : nettoyage.c Projet.h
	gcc -c nettoyage.c -o nettoyage.o
	
recherche.o : recherche.c Projet.h
	gcc -c recherche.c -o recherche.o 
	
projet.exe: main.o Welcome.o nettoyage.o recherche.o
	gcc main.o Welcome.o nettoyage.o recherche.o -o projet.exe 
	
clean: 
	rm -f main.o Welcome.o nettoyage.o recherche.o projet.exe
