#include"Projet.h"

const char* espece_to_string(Espece race) {
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

void nettoyage() { //TD08/Ex fichier/Ex tableau

    FILE * cavalier=fopen("../Nettoyage/Cavalier.txt", "r");
        if (cavalier==NULL) {
            printf("Erreur: %d\n", errno);
            printf("Message d'erreur: %s\n", strerror(errno));
            exit(21);
        }

    int a=fgetc(cavalier);

    while (a!=EOF) {
        printf("%c", a);
        a=fgetc(cavalier);
    }

    fclose(cavalier);

    sleep(3);


    FILE* fichier = fopen("../Nettoyage/donnees.txt", "r");
    if (fichier == NULL) {
        printf("Erreur: %d\n", errno);
        printf("Message d'erreur: %s\n", strerror(errno));
        exit(10);
    }

    Clean tab[7];
    int i = 0;

    while (fscanf(fichier, "%s %d %d %[^\n]", tab[i].jour, &tab[i].race, &tab[i].temps, tab[i].comment) == 4) {
        i++;
    }

    fclose(fichier);

    for (int i = 0; i < 6; i++) {
        printf("\n***\n");
        printf("Jour: %s\n", tab[i].jour);
        printf("Espece: %s\n", espece_to_string(tab[i].race));
        printf("Temps en minutes: %d\n", tab[i].temps);
        printf("Commentaire: %s\n", tab[i].comment);
        printf("***\n");
    }

}
