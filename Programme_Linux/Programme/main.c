
#include"Projet.h"



int main() {
    int continuer=1;

    while (continuer==1) {
        int choix=welcome();
        printf("Vous avez choisi la %d\n", choix); //supprimer

        switch (choix) {
            case(0): rechercher_animal();
            printf("\n\n________________\n\nAppuyer sur Entrer pour continuer\n");
            getchar();
            getchar();
            system("clear"); //linux
            break;

            case(1): //adopter_animal();
                break;

            case(2): ajouter_animal();
            printf("\n\n________________\n\nAppuyer sur Entrer pour continuer\n");
            getchar();
            getchar();
            system("clear"); //linux
            break;

            case(3): afficher_registre();
            printf("\n\n________________\n\nAppuyer sur Entrer pour continuer\n");
            getchar();
            getchar();
            system("clear"); //linux
            break;

            case(4): nettoyage();
            printf("\n\n________________\n\nAppuyer sur Entrer pour continuer\n");
            getchar();
            getchar();
            system("clear");
            break;

            case(5): bye();
            continuer=0;
            break;

            default:
                printf("\n***\nVeuillez sélectionner une valeur correcte.\n***\n\n");
            break;
        }
    }

    return 0;
}

