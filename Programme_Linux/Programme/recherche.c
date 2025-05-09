#include"Projet.h"

////////////////////
int *rechercher_nom(Animal *tab, int taille) { //recupère tableau avec info registre

    char nom[100]={0};
    int *tab_ID=malloc(sizeof(int)*taille);
        if (tab_ID==NULL) {
            printf("erreur alloc 'rechercher_nom'\n");
            exit(456);
        }


    printf("\nQuel est le prenom que vous rechercher: ");
    scanf(" %99s", nom);

    nom[0]=toupper(nom[0]);
    
    	for (int i = 1; nom[i] != '\0'; i++) {
    		nom[i] = tolower(nom[i]);
	}	

    for (int i=0; i<taille; i++) {			//insert L'ID correspondant à la recherche ou met -1
            if (strcmp(tab[i].nom, nom)==0) {
                tab_ID[i]=tab[i].ID;
            }
            else {
                tab_ID[i]=-1;
            }
    }

   
return tab_ID;
}
////////////////////





////////////////////
int *rechercher_age(Animal *tab, int taille) {

    int age=-1;
    int *tab_ID=malloc((sizeof(int)*taille));
      
        if (tab_ID==NULL) {
            printf("Erreur 'rechercher_age'\n");
            exit(35);
        }

    do {
        printf("\nVous souhaiter rechercher selon quel tranche d'âge?:\n0:<20ans\n1:>100ans\n2:Autre\n");
        while (scanf("%d", &age)!=1) {
            while (getchar()!='\n');
            printf("Veuillez entrer un entier\n");
        }
    }
    while (age<0 || age>2);

    switch (age) {			//insert L'ID correspondant à la recherche ou met -1
        case(0):
            for (int i=0; i<taille; i++) {
                if (tab[i].bd.age<20 && tab[i].bd.age>0) { 
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
////////////////////





////////////////////
int* rechercher_espece(Animal *tab, int taille) {
    
    int *tab_ID=malloc((sizeof(int)*taille));
    
    if (tab_ID==NULL) {
        printf("Erreur 'rechercher_espece'\n");
        exit(76);
    }
    int race;

    do {
        printf("\nQuel espece cherchez-vous?\n0:VARACTYL\n1:ZILLO BEAST\n2:PORG\n3:AIWHAS\n4:BANTHA\n5:KOWAKEIN\n");
        while (scanf("%d", &race)!=1) {
            while (getchar()!='\n');
            printf("Veuillez saisir un entier\n");
        }
    }
    while (race<0 || race>5);

    switch (race) {			//affichage visuel de l'animal
        case(0):affiche_varactyl();
        sleep(1);
        break;

        case(1):affiche_zillo();
        sleep(1);
        break;

        case(2):affiche_porg();
        sleep(1);
        break;

        case(3):affiche_aiwhas();
        sleep(1);
        break;

        case(4):affiche_bantha();sleep(1);
        break;

        default:affiche_kowakien();sleep(1);
        break;

    }


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
////////////////////





////////////////////
void compare_affiche( Animal *tab, int *tab_ID1, int *tab_ID2, int taille) { //complexité o(n^3) mais petite valeur de taille

    if (tab_ID1==NULL || tab_ID2==NULL || tab==NULL) {				//recoit deux tab avec ID ou -1 et un tab avec les infos du registre
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

            if (tab_ID1[i]==tab_ID2[j] && tab_ID1[i]!=-1) { 				//recherche les id qui sont dans les deux tableaux

                int id=tab_ID1[i];

                if (tab[id].ID==0 && strlen(tab[id].nom)==0) {				//passe les 'cases' du tableau vide
                    continue;
                }


                printf("\n***\n");
                printf("L'animal %d correspond a votre recherche: \n", tab_ID1[i]);
                count++;



                    for (int k=0; k<taille; k++) {					//recherche de l'id commun au deux tableau dans les données extrait du registre dans 'tab'

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

	int choix;

	if (count==0) {
	    	printf("\n\n***\nAucun animal ne correspond a ces criteres\n");
	}
	else{
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
	

}
////////////////////





////////////////////
void afficher_recherche(int *search1, int *search2) {

    FILE * accueil=fopen("../Dessin/Compte/Bonjour.txt", "r"); 		//affiche présentation
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

    FILE * choix1=fopen("../Dessin/Compte/recherche.txt", "r");    	//présente critère 1
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
        printf("Votre demande (entier entre 0 et 2 inclus): ");

        while (scanf("%d", search1)!=1) {
            while (getchar()!='\n');
            printf("Veuillez saisir un entier\n");
        }

    }
    while (*search1<0 || *search1>2);



    printf("\n\n\n");


    FILE * choix2=fopen("../Dessin/Compte/recherche_2.txt", "r");		//présente critère 2
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
        printf("\n\nVotre demande (entier entre 0 et 3 inclus): ");
        while (scanf("%d", search2)!=1) {
            while (getchar()!='\n');
            printf("Veuillez saisir un entier\n");
        }
    }
    while (*search2<0 || *search2>3);



}
////////////////////






////////////////////
void rechercher_animal() {
    int search1=-1;
    int search2=-1;
    

    afficher_recherche(&search1, &search2);//affiche les critères

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


    Animal *tab=registre_tab(TAILLE); //recupère tab avec info du registre
    if (tab==NULL) {
        printf("ERREUR regsitre tab'recherche'\n");
        exit(46565);
    }


    int *tab_ID_00;
    int *tab_ID_01;
    int p_identique=0;


    switch (search1) {
        case(0):
            tab_ID_00=rechercher_nom(tab, TAILLE);//retourne tab avec des Id corrects ou -1
        switch(search2) {
            case(1):
                tab_ID_01=rechercher_age(tab, TAILLE); //retourne tab avec des Id corrects ou -1
            break;

            case(2):
                tab_ID_01=rechercher_espece(tab, TAILLE); //retourne tab avec des Id corrects ou -1
            break;

            default: tab_ID_01=tab_ID_00; // pas de deucième critères
            p_identique=1;
            break;
        }
        compare_affiche(tab, tab_ID_00, tab_ID_01, TAILLE);//affiche les animaux correspondants
        break;


								//même fonctionnement pour le reste
        case(1):
            tab_ID_00=rechercher_age(tab, TAILLE);
        switch(search2) {
            case(0):
                tab_ID_01=rechercher_nom(tab, TAILLE);
            break;

            case(2):
                tab_ID_01=rechercher_espece(tab, TAILLE);
            break;

            default: tab_ID_01=tab_ID_00;
            p_identique=1;
            break;
        }
        compare_affiche(tab, tab_ID_00, tab_ID_01, TAILLE);
        break;


        default:
            tab_ID_00=rechercher_espece(tab, TAILLE);
        switch (search2) {
            case(0):
                tab_ID_01=rechercher_nom(tab, TAILLE);
            break;

            case(1):
                tab_ID_01=rechercher_age(tab ,TAILLE);
            break;

            default:
                tab_ID_01=tab_ID_00;
            p_identique=1;
            break;
        }
        compare_affiche(tab, tab_ID_00, tab_ID_01, TAILLE);
        break;
    }


    if (p_identique!=0) {
        free(tab_ID_00);
    }
    else {
        free(tab_ID_00);
        free(tab_ID_01);
    }
    free(tab);
}
////////////////////





