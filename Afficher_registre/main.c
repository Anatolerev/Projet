#include"test.h"

int main() {

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



    Animal* tab=registre_tab(TAILLE);
    int count=0;
    int tab_count[6]={0};



    for (int i=0; i<TAILLE; i++) {
        if (tab[i].ID==0 && strlen(tab[i].nom)==0) {
            continue;
        }
        count++;
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
    printf("\n\nListe des presences:\n\nVARACTYL: %d\nZILLO BEAST: %d\nPORG: %d\nAIWHAS: %d\nBANTHA: %d\nKOWAKIEN: %d\n\n\n", tab_count[0], tab_count[1], tab_count[2], tab_count[3], tab_count[4], tab_count[5]);
    sleep(2);

    int *tab_espece=rechercher_espece(tab, TAILLE);

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

    return 0;
}