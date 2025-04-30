#include"test.h"

int main() {
    srand(time(NULL));
    FILE * fichier=fopen("../Animaux/Registre.txt", "w");
    FILE * fichier_nom=fopen("../Animaux/Nom_animaux.txt", "r");


    if (fichier == NULL) {
        printf("Erreur: %d\n", errno);
        printf("Message d'erreur: %s\n", strerror(errno));
        exit(15);
    }

    if (fichier_nom == NULL) {
        printf("Erreur: %d\n", errno);
        printf("Message d'erreur: %s\n", strerror(errno));
        exit(15);
    }

    int ID_utilisé[51]={0};
    int count_zillo=0;

    for (int i=0; i<34; i++) {


        Animal a;

        do {
            a.ID=rand()%51+1;
        }while (ID_utilisé[a.ID]==1);
        ID_utilisé[a.ID]=1;

        do {
            a.race=rand()%6;
        }while (a.race==1 && count_zillo>=3);
        if (a.race==1) {
            count_zillo++;
        }


            if (a.race==0) {
                a.poids=rand()%151+400;
                a.bd.age=rand()%11+20;
                a.bd.année=3026-a.bd.age;
            }
            else if (a.race==1) {
                a.poids=rand()%1501+1500;
                a.bd.age=rand()%41+80;
                a.bd.année=3026-a.bd.age;

            }
            else if (a.race==2) {
                a.poids=rand()%11+5;
                a.bd.age=rand()%11+15;
                a.bd.année=3026-a.bd.age;
            }
            else if (a.race==3) {
                a.poids=rand()%201+800;
                a.bd.age=rand()%11+25;
                a.bd.année=3026-a.bd.age;
            }
            else if (a.race==4){
                a.poids=rand()%201+700;
                a.bd.age=rand()%11+10;
                a.bd.année=3026-a.bd.age;

            }
            else {
                a.poids=rand()%6+5;
                a.bd.age=rand()%4+4;
                a.bd.année=3026-a.bd.age;
            }


        a.bd.jour=rand()%28+1;
        a.bd.mois=rand()%12+1;



        char nom[100];

        if (fgets(nom, sizeof(nom), fichier_nom)!=NULL) {
            nom[strcspn(nom, "\n")]='\0';
            strcpy(a.nom, nom);
        }
        else {
            printf("Pas assez de noms");
            exit(89);
        }

            fprintf(fichier, "%d %s %d %02d/%02d/%04d %d %d\n", a.ID, a.nom, a.race, a.bd.jour, a.bd.mois, a.bd.année, a.bd.age, a.poids);
    }
    fclose(fichier);
    fclose(fichier_nom);

    return 0;
}