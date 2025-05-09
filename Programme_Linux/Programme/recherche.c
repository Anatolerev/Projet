#include"Projet.h"

////////////////////
int *rechercher_nom(Animal *tab, int taille) {

    char nom[100]={0};
    int *tab_ID=malloc(sizeof(int)*taille);
        if (tab_ID==NULL) {
            printf("erreur alloc 'rechercher_age'\n");
            exit(456);
        }


    printf("\nQuel est le prenom que vous rechercher: ");
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

    switch (age) {
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

    switch (race) {
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

    if (tab_ID1==NULL || tab_ID2==NULL || tab==NULL) {
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
    printf("\n\n***\nAucun animal ne correspond a ces criteres\n");
}
}
////////////////////





////////////////////
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
        printf("Votre demande (entier entre 0 et 2 inclus): ");

        while (scanf("%d", search1)!=1) {
            while (getchar()!='\n');
            printf("Vueuillez saisir un entier\n");
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
    //int *p1=&search1;
    //int *p2=&search2;

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


    Animal *tab=registre_tab(TAILLE);
    if (tab==NULL) {
        printf("ERREUR regsitre tab'recherche'\n");
        exit(46565);
    }


    int *tab_ID_00;
    int *tab_ID_01;
    int p_identique=0;


    switch (search1) {
        case(0):
            tab_ID_00=rechercher_nom(tab, TAILLE);
        switch(search2) {
            case(1):
                tab_ID_01=rechercher_age(tab, TAILLE);
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





////////////////////
void adoption(){
	int ID;
	int trv=0;


    wando_id();

	do {
	    printf("\n\nVotre demande (entier entre 0 et 50 inclus): ");
		while (scanf("%d", &ID)!=1) {
			while (getchar()!='\n');
			printf("Veuillez saisir un entier\n");
		}
	}while (ID<0 || ID>50);







	FILE *fichier = fopen("../Animaux/Registre.txt","r");
	FILE *temp = fopen("../Animaux/temp.txt","w");
	if( fichier==NULL || temp==NULL) {
		printf("ERREUR 'adoption': %d\n", errno);
		printf("Message d'erreur: %s\n", strerror(errno));
		exit(11);
	}




	char line[1000]={0};

	int id_fonction=-1;
	char nom[100]={0};
	char poubelle[500]={0};
	int race=-1;
	Animal a1, a2;
	char remarque_temps[3000]={0};
	int i=0;


	while(fgets(line, sizeof(line),fichier)!=NULL && i<TAILLE){ // COUYILLZ
		line[strcspn(line, "\r\n")]='\0';

		int nb_champs=sscanf(line, "%d %99s %d %d/%d/%d %d %[^\n]", &a1.ID, a1.nom, &a1.race, &a1.bd.jour, &a1.bd.mois, &a1.bd.année, &a1.poids, remarque_temps);

		if (nb_champs==8) {
			strcpy(a1.remarque, remarque_temps);
		}
		else if (nb_champs==7) {
			a1.remarque[0]='\0';
		}




		if(ID==a1.ID){
			trv++;
			a2=a1;
		}
		else{
			fputs(line,temp);
			fputs("\n", temp);
		}
		i++;
	}



	fclose(fichier);
	fclose(temp);

    printf("\n\n\n\n");

	if (trv==0) {
	    wando_id_introuvable();
		return;
	}

	else if(trv>1){ //stop si deux ID identiques
		printf("Trouvé deux ID correspondant\nERREUR\n");
		return;
	}




	int R;
	char titre[50];

	mando_provenance();


	do {
		printf("\n\nVotre demande(entier entre 1 et 3 inclus): ");
		while (scanf("%d",&R)!=1) {
			while (getchar()!='\n');
			printf("Veuillez saisir un entier\n");
		}
	}while(R<1 || R>3 );


	switch (R) {
		case(1):
            mando_empire();
		    remove(TEMPFILE);
			return;
		break;

		case(2):
			if(a2.race!=1) {
			    //republicain mais demande pas zillo
				mando_accepte();

			    remove(FILENAME);
			    rename(TEMPFILE,FILENAME);
			}
			else {
				mando_refuse();
				remove(TEMPFILE);
				return;
			}
		break;



		case(3):

			printf("Quelle est votre titre ou votre nom?\n Veuilllez mettre des '_' dans les noms composés\n");
		scanf(" %s", titre);

		titre[0]=toupper(titre[0]);


		if( strcmp(titre, "Yoda")==0){
			mando_yoda();

			remove(FILENAME);
			rename(TEMPFILE, FILENAME);

		}
		else if(strcmp(titre, "Chasseur_de_prime")==0) {
			if ( a2.race!=1) {
				//demande pas zillo ok
				mando_accepte();


				remove(FILENAME);
				rename(TEMPFILE,FILENAME);

			}
			else {
				mando_refuse();
				remove(TEMPFILE);
			}
		}
		else {
			if (a2.race!=1) {
                mando_accepte();
			    remove(FILENAME);
				rename(TEMPFILE,FILENAME);
			}
			else {
			    mando_alerte();
			    remove(TEMPFILE);
			}

		}

		break;

		default:
			printf("Nous ne connaissons pas cette provenance\n");
			remove(TEMPFILE);
		break;


	}
}
////////////////////