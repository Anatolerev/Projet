#include"Projet.h"



int main() {

    int choix=welcome();
    printf("Vous avez choisi la %d\n", choix); //supprimer

    switch (choix) {
        case(0): //rechercher_animal();
        break;

        case(1): //adopter_animal();
        break;

        case(2): //ajouter_animal();
        break;

        case(3): //afficher_regitre();
        break;

        case(4): nettoyage();
        break;

        default: bye();
        break;
    }


    return 0;
}