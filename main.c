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
            break;

            case(1): //adopter_animal();
            break;

            case(2): //ajouter_animal();
            break;

            case(3): //afficher_regitre();
            break;

            case(4): nettoyage();
                printf("\n\n________________\n\nAppuyer sur Entrer pour continuer\n");
                getchar();
                getchar();
            break;

            default: bye();
                continuer=0;
            break;
        }
    }

    return 0;
}