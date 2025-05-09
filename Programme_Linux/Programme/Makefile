all: projet.exe 

main.o : main.c Projet.h
	gcc -c main.c -o main.o
	
Welcome.o : Welcome.c Projet.h
	gcc -c Welcome.c -o Welcome.o 
	
nettoyage.o : nettoyage.c Projet.h
	gcc -c nettoyage.c -o nettoyage.o
	
recherche.o : recherche.c Projet.h
	gcc -c recherche.c -o recherche.o 
	
adoption.o: adoption.c Projet.h
	gcc -c adoption.c -o adoption.o
	
afficher_registre.o: afficher_registre.c Projet.h
	gcc -c afficher_registre.c -o afficher_registre.o
	
ajouter.o: ajouter.c Projet.h
	gcc -c ajouter.c -o ajouter.o
	
projet.exe: main.o Welcome.o nettoyage.o recherche.o adoption.o afficher_registre.o ajouter.o
	
	gcc main.o Welcome.o nettoyage.o recherche.o adoption.o afficher_registre.o ajouter.o -o projet.exe 
	
clean: 
	rm -f main.o Welcome.o nettoyage.o recherche.o adoption.o afficher_registre.o ajouter.o projet.exe
