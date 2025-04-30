#include"test.h"

void afficher_recherche(int *search1, int *search2) {

    FILE * accueil=fopen("../Dessin/Compte/Bonjour.txt", "r");
    if (accueil==NULL) {
        printf("Erreur recherche_bonjour: %d\n", errno);
        printf("Message d'erreur: %s\n", strerror(errno));
        exit(456);
    }

    int c=fgetc(accueil);
    while (c!=EOF) {
        printf("%c", c);
        c=fgetc(accueil);
    }

    fclose(accueil);


    sleep(2);
    printf("\n\n\n");

    FILE * choix1=fopen("../Dessin/Compte/recherche.txt", "r");
    if (choix1==NULL) {
        printf("Erreur recherche_recherche: %d\n", errno);
        printf("Message d'erreur: %s\n", strerror(errno));
        exit(456);
    }

    c=fgetc(choix1);
    while (c!=EOF) {
        printf("%c", c);
        c=fgetc(choix1);
    }

    fclose(choix1);

            do {
                printf("Votre demande: ");
                if (scanf("%d", search1)!=1) {
                    printf("Vueillez saisir un entier\n");
                    exit(76);
                }

            }
            while (*search1<0 || *search1>2);



    printf("\n\n\n");


    FILE * choix2=fopen("../Dessin/Compte/recherche_2.txt", "r");
    if (choix2==NULL) {
        printf("Erreur recherche_recherche 2: %d\n", errno);
        printf("Message d'erreur: %s\n", strerror(errno));
        exit(456);
    }

    c=fgetc(choix2);
    while (c!=EOF) {
        printf("%c", c);
        c=fgetc(choix2);
    }

    fclose(choix2);


            do {
                printf("Votre demande: ");
                if (scanf("%d", search2)!=1) {
                    printf("Vueillez saisir un entier\n");
                    exit(67);
                }
            }
            while (*search2<0 || *search2>3);



}


int main() {

    int search1=-1;
    int search2=-1;
    int *p1=&search1;
    int *p2=&search2;

    afficher_recherche(&search1, &search2);

    if (search1==-1 ||search2==-1) {
        printf("Erreur selection\n");
        exit(789);
    }
    else if (search1==search2 || search2==3) {
        printf("Vous recherchez selon le critere %d\n", search1);
    }
    else {
        printf("Vous voulez rechercher selon les criteres %d et %d\n", search1, search2);
    }


    FILE * fichier=fopen("../Animaux/Registre.txt", "r");
        if (fichier==NULL) {
            printf("Erreur ouverture registre recherche 2: %d\n", errno);
            printf("Message d'erreur: %s\n", strerror(errno));
            exit(159);
        }


    Animal tab[51]={0};
    char phrase[400]={0};
    char remarque_temp[300]={0};

    int i=0;

        while (fgets(phrase, sizeof(phrase), fichier)!=NULL && i<51) {
            phrase[strcspn(phrase, "\r\n")]='\0';  //changement linux pas de \r

            int nb_champs=sscanf(phrase, "%d %99s %d %d/%d/%d %d %[^\n]",
                &tab[i].ID,
                tab[i].nom,
                &tab[i].race,
                &tab[i].bd.jour,
                &tab[i].bd.mois,
                &tab[i].bd.année,
                &tab[i].poids,
                remarque_temp);

            if (nb_champs==8) {
                strcpy(tab[i].remarque, remarque_temp);
            }
            else if (nb_champs==7) {
                tab[i].remarque[0]='\0';
            }
            else{
                printf("Donnees invalides 'recherche'\n");
                exit(123);
            }
            tab[i].bd.age=3026-(tab[i].bd.année);
            i++;
        }


    int *tab_ID_00;
    int *tab_ID_01;
    int p_identique=0;


    switch (search1) {
        case(0):
            tab_ID_00=rechercher_nom(tab, 51);
        switch(search2) {
            case(1):
                tab_ID_01=rechercher_age(tab, 51);
            break;

            case(2):
                tab_ID_01=rechercher_espece(tab, 51);
            break;

            default: tab_ID_01=tab_ID_00;
            p_identique=1;
            break;
        }
        compare_affiche(tab, tab_ID_00, tab_ID_01, 51);
        break;



        case(1):
            tab_ID_00=rechercher_age(tab, 51);
        switch(search2) {
            case(0):
                tab_ID_01=rechercher_nom(tab, 51);
            break;

            case(2):
                tab_ID_01=rechercher_espece(tab, 51);
            break;

            default: tab_ID_01=tab_ID_00;
            p_identique=1;
            break;
        }
        compare_affiche(tab, tab_ID_00, tab_ID_01, 51);
        break;


        default:
            tab_ID_00=rechercher_espece(tab, 51);
        switch (search2) {
                case(0):
                    tab_ID_01=rechercher_nom(tab, 51);
                break;

                case(1):
                    tab_ID_01=rechercher_age(tab ,51);
                break;

                default:
                    tab_ID_01=tab_ID_00;
                    p_identique=1;
                break;
            }
            compare_affiche(tab, tab_ID_00, tab_ID_01, 51);
        break;
    }


if (p_identique!=0) {
    free(tab_ID_00);
}
else {
    free(tab_ID_00);
    free(tab_ID_01);
}


    return 0;
}