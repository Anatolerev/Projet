#include "test.h"

int *rechercher_nom(Animal tab[51]) {

    char nom[100]={0};
    int *tab_ID=malloc(sizeof(int)*51);
        if (tab_ID==NULL) {
            printf("erreur alloc 'rechercher_age'\n");
            exit(456);
        }


    printf("Quel est le prénom de vous rechercher: ");
    scanf(" %99s", nom);

    for (int i=0; i<51; i++) {
            if (strcmp(tab[i].nom, nom)==0) {
                tab_ID[i]=tab[i].ID;
            }
            else {
                tab_ID[i]=-1;
            }
    }
return tab_ID;
}


int *rechercher_age(Animal tab[51]) {

    int age=-1;
    int *tab_ID=malloc((sizeof(int)*51));
        if (tab_ID==NULL) {
            printf("Erreur 'rechercher_age'\n");
            exit(35);
        }

    do {
        printf("Vous souhaiter rechercher selon quel tranche d'âge?:\n0:<20ans\n1:>100ans\n");
        scanf("%d", &age);
    }
    while (age<0 || age>1);

    switch (age) {
        case(0):
            for (int i=0; i<51; i++) {
                if (tab[i].bd.age<20) {
                    tab_ID[i]=tab[i].ID;
                }
                else {
                    tab_ID[i]=-1;
                }

            }
        break;

        default:
            for (int i=0; i<51; i++) {
                if (tab[i].bd.age>100) {
                    tab_ID[i]=tab[i].ID;
                }
                else {
                    tab_ID[i]=-1;
                }
            }
    }

return tab_ID;
}


int* rechercher_espece(Animal tab[51]) {

    int *tab_ID=malloc((sizeof(int)*51));
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

        for (int i=0; i<51; i++) {
            if (tab[i].race==race) {
                tab_ID[i]=tab[i].ID;
            }
            else {
                tab_ID[i]=-1;
            }
        }

return tab_ID;
}