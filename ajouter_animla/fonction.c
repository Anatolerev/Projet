#include"test.h"

Animal* registre_tab(int taille) {
    FILE * fichier=fopen("../Animaux/Registre.txt", "r");
    if (fichier==NULL) {
        printf("Erreur affichage registre: %d\n", errno);
        printf("Message d'erreur: %s\n", strerror(errno));
        exit(1);
    }

    Animal *tab=malloc(sizeof(Animal)*taille);
    if (tab==NULL) {
        printf("ERREUR malloc 'regsitre_tab'\n");
        exit(1654);
    }
    char phrase[400]={0};
    char remarque_temp[300]={0};

    int i=0;
    int nb_champs=0;

    while (fgets(phrase, sizeof(phrase), fichier)!=NULL && i<taille) {
        phrase[strcspn(phrase, "\r\n")]='\0';  //changement linux pas de \r


            nb_champs=sscanf(phrase, "%d %99s %d %d/%d/%d %d %[^\n]",
            &tab[i].ID,
            tab[i].nom,
            &tab[i].race,
            &tab[i].bd.jour,
            &tab[i].bd.mois,
            &tab[i].bd.année,
            &tab[i].poids,
            remarque_temp);

        if (nb_champs==8) {
            strcpy(tab[i].remarque, remarque_temp);
        }
        else if (nb_champs==7) {
            tab[i].remarque[0]='\0';
        }
        else{
            printf("Donnees invalides 'recherche'\n");
            exit(123);
        }
        tab[i].bd.age=3026-(tab[i].bd.année);
        i++;
    }
    fclose(fichier);
    return tab;
}


void adoption_possible() {
    FILE * fichier=fopen("../Dessin/Watto/watto_possible.txt", "r"); //Lis le texte

    if(fichier==NULL){
        printf("ERREUR 'adoption_possible': %d\n", errno);
        printf("Message d'erreur: %s\n", strerror(errno));
        exit(14);
    }


    int c=fgetc(fichier);

    while(c!=EOF){

        printf("%c", c);
        c=fgetc(fichier);
    }


    fclose(fichier);
}

void adoption_impossible() {
    FILE * fichier=fopen("../Dessin/Watto/watto_impossible.txt", "r"); //Lis le texte

    if(fichier==NULL){
        printf("ERREUR 'adoption_impossible': %d\n", errno);
        printf("Message d'erreur: %s\n", strerror(errno));
        exit(14);
    }


    int c=fgetc(fichier);

    while(c!=EOF){

        printf("%c", c);
        c=fgetc(fichier);
    }


    fclose(fichier);
}

void watto_bonjour() {

        FILE * fichier=fopen("../Dessin/Watto/watto1.txt", "r"); //Lis le texte

        if(fichier==NULL){
            printf("ERREUR 'watto_bonjour': %d\n", errno);
            printf("Message d'erreur: %s\n", strerror(errno));
            exit(15);
        }


        int c=fgetc(fichier);

        while(c!=EOF){

            printf("%c", c);
            c=fgetc(fichier);
        }


fclose(fichier);
}


void watto_espece() {

    FILE * fichier=fopen("../Dessin/Watto/watto2.txt", "r"); //Lis le texte

    if(fichier==NULL){
        printf("ERREUR 'watto_espece': %d\n", errno);
        printf("Message d'erreur: %s\n", strerror(errno));
        exit(16);
    }


    int c=fgetc(fichier);

    while(c!=EOF){

        printf("%c", c);
        c=fgetc(fichier);
    }


    fclose(fichier);
}