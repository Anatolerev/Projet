#include"Projet.h"

int welcome() {
    FILE * fichier=fopen("../Dessin/medical droid.txt", "r"); //Lis le texte

    if(fichier==NULL){
        printf("ERREUR welcome: %d\n", errno);
        printf("Message d'erreur: %s\n", strerror(errno));
        exit(11);
    }


    int c=fgetc(fichier);

    while(c!=EOF){

        printf("%c", c);
        c=fgetc(fichier);
    }


    int rep;
    scanf("%d", &rep);
    return rep;

}





void bye() {
    FILE * fichier=fopen("../Dessin/bye.txt", "r");

    if(fichier==NULL){
        printf("ERREUR bye: %d\n", errno);
        printf("Message d'erreur: %s\n", strerror(errno));
        exit(11);
    }


    int c=fgetc(fichier);

    while(c!=EOF){

        printf("%c", c);
        c=fgetc(fichier);
    }

}