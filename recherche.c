#include"Projet.h"


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




void rechercher_animal() {
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
