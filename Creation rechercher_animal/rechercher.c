#include "test.h"

const char* race_espece(Espece race) {
    switch (race) {
        case VARACTYL: return "VARACTYL";
        case ZILLO_BEAST: return "ZILLO_BEAST";
        case PORG: return "PORG";
        case AIWHAS: return "AIWHAS";
        case BANTHA: return "BANTHA";
        case KOWAKIEN: return "KOWAKIEN";
        default: return "INCONNU";
    }
}




int *rechercher_nom(Animal *tab, int taille) {

    char nom[100]={0};
    int *tab_ID=malloc(sizeof(int)*taille);
        if (tab_ID==NULL) {
            printf("erreur alloc 'rechercher_age'\n");
            exit(456);
        }


    printf("Quel est le prenom de vous rechercher: ");
    scanf(" %99s", nom);

    nom[0]=toupper(nom[0]);

    for (int i=0; i<taille; i++) {
            if (strcmp(tab[i].nom, nom)==0) {
                tab_ID[i]=tab[i].ID;
            }
            else {
                tab_ID[i]=-1;
            }
    }
return tab_ID;
}


int *rechercher_age(Animal *tab, int taille) {

    int age=-1;
    int *tab_ID=malloc((sizeof(int)*taille));
        if (tab_ID==NULL) {
            printf("Erreur 'rechercher_age'\n");
            exit(35);
        }

    do {
        printf("Vous souhaiter rechercher selon quel tranche d'âge?:\n0:<20ans\n1:>100ans\n2:Autre\n");
        scanf("%d", &age);
    }
    while (age<0 || age>2);

    switch (age) {
        case(0):
            for (int i=0; i<taille; i++) {
                if (tab[i].bd.age<20) {
                    tab_ID[i]=tab[i].ID;
                }
                else {
                    tab_ID[i]=-1;
                }
            }
        break;

        case(1):
            for (int i=0; i<taille; i++) {
                if (tab[i].bd.age>100) {
                    tab_ID[i]=tab[i].ID;
                }
                else {
                    tab_ID[i]=-1;
                }
            }
        break;

        default:
            for (int i=0; i<taille; i++) {
                if (tab[i].bd.age>=20 && tab[i].bd.age<=100){
                    tab_ID[i]=tab[i].ID;
                }
                else {
                    tab_ID[i]=-1;
                }
            }
        break;

        }

return tab_ID;
}


int* rechercher_espece(Animal *tab, int taille) {

    int *tab_ID=malloc((sizeof(int)*taille));
    if (tab_ID==NULL) {
        printf("Erreur 'rechercher_espece'\n");
        exit(76);
    }
    int race;

    do {
        printf("Quel espece cherchez-vous?\n0:VARACTYL\n1:ZILLO BEAST\n2:PORG\n3:AIWHAS\n4:BANTHA\n5:KOWAKEIN\n");
        scanf("%d", &race);
    }
    while (race<0 || race>5);

        for (int i=0; i<taille; i++) {

            if (tab[i].ID==0 && strlen(tab[i].nom)==0) {
                tab_ID[i]=-1;
                continue;
            }


            if (tab[i].race==race) {
                tab_ID[i]=tab[i].ID;
            }
            else {
                tab_ID[i]=-1;
            }
        }

return tab_ID;
}


void compare_affiche( Animal *tab, int *tab_ID1, int *tab_ID2, int taille) { //complexité o(n^3) mais petite valeur de taille

    if (tab_ID1==NULL || tab_ID2==NULL) {
        printf("ERREUR ALLOC' compare affiche");
        exit(7);
    }

    if (taille<=0) {
        printf("Erreur taille 'compare afiiche'\n");
        exit(7);
    }
    int count=0;

    for (int i=0; i<taille; i++) {

        for (int j=0; j<taille;j++) {

            if (tab_ID1[i]==tab_ID2[j] && tab_ID1[i]!=-1) {

                int id=tab_ID1[i];

                if (tab[id].ID==0 && strlen(tab[id].nom)==0) {
                    continue;
                }


                printf("\n***\n");
                printf("L'animal %d correspond a votre recherche: \n", tab_ID1[i]);
                count++;

                    for (int k=0; k<taille; k++) {

                        if (tab[k].ID==tab_ID1[i]) {

                            printf("ID:%d\nNom:%s\nEspece:%s\nDate de naissance:%d/%d/%d\nAge:%d\nPoids:%d\n", tab[k].ID, tab[k].nom, race_espece(tab[k].race), tab[k].bd.jour, tab[k].bd.mois, tab[k].bd.année, (3026-tab[k].bd.année), tab[k].poids);

                                if (strlen(tab[k].remarque)>0) {
                                    printf("Remarque: %s\n", tab[k].remarque);
                                }
                            printf("\n***\n");
                        }
                    }
            }

        }
    }

if (count==0) {
    printf("Aucun animal ne correspond a ces criteres\n");
}
}