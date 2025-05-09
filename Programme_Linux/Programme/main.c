
#include"Projet.h"



int main() {
    int continuer=1;

	//bienvenue();
	//sleep(3);
	system("clear");
	star_wars();
	printf("\n\n");

    while (continuer==1) {
        int choix=welcome();
        printf("Vous avez choisi la %d\n", choix); //supprimer

        switch (choix) {
            case(0): rechercher_animal();//envoie fonction recherche
		    printf("\n\n________________\n\nAppuyer sur Entrer pour continuer\n");
		    getchar();
		    getchar();
		    system("clear"); //linux
            break;

            case(1): adoption();//envoie fonction adoption
		    printf("\n\n________________\n\nAppuyer sur Entrer pour continuer\n");
		    getchar();
		    getchar();
		    system("clear");
            break;

            case(2): ajouter_animal();//envoie fonction ajouter_animal
		    printf("\n\n________________\n\nAppuyer sur Entrer pour continuer\n");
		    getchar();
		    getchar();
		    system("clear"); //supp terminal
            break;

            case(3): afficher_registre();//envoie fonction affiche_registre
		    printf("\n\n________________\n\nAppuyer sur Entrer pour continuer\n");
		    getchar();
		    getchar();
		    system("clear"); //linux
            break;

            case(4): nettoyage();// envoie fonction nettoyage
		    printf("\n\n________________\n\nAppuyer sur Entrer pour continuer\n");
		    getchar();
		    getchar();
		    system("clear");
            break;

            case(5): bye();//affiche message de fin
            	continuer=0;//condition arret de la boucle
            break;

            default:
                printf("\n***\nVeuillez sélectionner une valeur correcte.\n***\n\n");//detection erreur
            break;
        }
    }
	sleep(2);
	printf("\n\n\n");
	end();
    return 0;
}
