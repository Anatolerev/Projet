#include "Projet.h"


////////////////////
void afficher_registre() {


    FILE * doc=fopen("../Dessin/Compte/Bonjour.txt", "r");
        if (doc==NULL){
            printf("Erreur affichage registre-bonjour: %d\n", errno);
            printf("Message d'erreur: %s\n", strerror(errno));
            exit(12);
        }

    int c=fgetc(doc);

    while(c!=EOF){

        printf("%c", c);
        c=fgetc(doc);
    }


    fclose(doc);
        sleep(2);

//fermeture bonjour

    Animal* tab=registre_tab(TAILLE);//reçoit tableau contenant les données registres
    int tab_count[6]={0};



    for (int i=0; i<TAILLE; i++) {
        if (tab[i].ID==0 && strlen(tab[i].nom)==0) {
            continue;
        }

        switch (tab[i].race) {
            case(0):tab_count[0]++;
            break;

            case(1): tab_count[1]++;
            break;

            case(2): tab_count[2]++;
            break;

            case(3): tab_count[3]++;
            break;

            case(4): tab_count[4]++;
            break;

            case(5):tab_count[5]++;
            break;

            default:printf("Erreur race 'afficher resigtre'\n");
            exit(1565);
            break;
        }

    }

    Race_compte tab_race[6]={
        {"VARACTYL", tab_count[0]},
        {"ZILLO BEAST", tab_count[1]},
        {"PORG", tab_count[2]},
        {"AIWHAS", tab_count[3]},
        {"BANTHA", tab_count[4]},
        {"KOWAKIEN", tab_count[5]}
    };

    quicksort(tab_race, 0, 5);

    printf("\n\n\nVoici les comptes:\n");
    for (int i = 0; i < 6; i++) {
        printf("%s : %d\n", tab_race[i].nom, tab_race[i].count);
    }
    printf("\n\n");



    sleep(2);

    int *tab_espece=rechercher_espece(tab, TAILLE);//renvoit un tableau composé de ID ou de -1

    for (int i=0; i<TAILLE; i++) {
        if (tab_espece[i]==-1) {
            continue;
        }

            for (int k=0; k<TAILLE; k++){
                if (tab[k].ID==00 && strlen(tab[k].nom)==0) {
                    continue;
                }
                if (tab[k].ID==tab_espece[i]) {
                        printf("\n\n***\n\n");
                        printf("ID:%d\nNom:%s\nEspece:%s\nDate de naissance:%d/%d/%d\nAge:%d\nPoids:%d\n", tab[k].ID, tab[k].nom, race_espece(tab[k].race), tab[k].bd.jour, tab[k].bd.mois, tab[k].bd.année, (3026-tab[k].bd.année), tab[k].poids);

                        if (strlen(tab[k].remarque)>0) {
                            printf("Remarque: %s\n", tab[k].remarque);
                        }
                        printf("\n***\n");
                }
        }
    }

int choix;
		printf("\n\nVoulez vous adopter un de ces animaux? (Saisir 0 ou 1):\n0:Oui\n1:Non\n");
			while(scanf("%d", &choix)!=1){
				while(getchar() != '\n');
				printf("Veuillez saisir une valeur correcte\n");
			}
			
		if(choix==0){
			printf("\n\n");
			adoption();
		}




}
////////////////////





////////////////////
void echanger(Race_compte* a, Race_compte* b) {
    Race_compte temp = *a;
    *a = *b;
    *b = temp;
}
////////////////////

////////////////////
int partition(Race_compte tab[], int premier, int dernier) {
    int pivot = tab[dernier].count;
    int i = premier - 1;
    for (int j = premier; j < dernier; j++) {
                if (tab[j].count > pivot) {
            i++;
            echanger(&tab[i], &tab[j]);
        }
    }
    echanger(&tab[i + 1], &tab[dernier]);
    return i + 1;
}
////////////////////

////////////////////
void quicksort(Race_compte tab[], int premier, int dernier) {
    if (premier < dernier) {
        int pi = partition(tab, premier, dernier);
        quicksort(tab, premier, pi - 1);
        quicksort(tab, pi + 1, dernier);
    }
}
////////////////////

