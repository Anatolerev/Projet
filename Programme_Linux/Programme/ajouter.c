#include "Projet.h"



////////////////////
void ajouter_animal() {
    watto_bonjour();//affiche presentation watto
    printf("\n\n____________________________\nAppuyer deux fois sur entrer\n\n");
    getchar();
    getchar();

    printf("\n\n");
    watto_espece();// watto espece limite
    printf("\n\n____________________________\nAppuyer deux fois sur entrer\n\n");
    getchar();
    getchar();



    srand(time(NULL));
    Animal *tab=registre_tab(TAILLE);//renvoit tableau avec les infos du registre
    if (tab==NULL) {
        printf("ERREUR registre_tab 'ajouter_animal'\n");
        exit(12);
    }

    int nb=-1;

    for (int i=0; i<TAILLE; i++) {
        if (tab[i].ID==0 && strlen(tab[i].nom)==0) {
            nb=i;
            printf("\nIl y'a %d animaux dans le refuge\n", nb);
            break;
        }
    }


    if (nb==-1 || nb>=50) {
        adoption_impossible();//watto trop animaux
        return;
    }
    else {
        adoption_possible(); //watto info pour ajout 
    }



    printf("\n\nNom: ");
    scanf(" %99s", tab[nb].nom);
    while (getchar() != '\n');

    tab[nb].nom[0]=toupper(tab[nb].nom[0]);
    	
    	for (int i = 1; tab[nb].nom[i] != '\0'; i++) {
   		 tab[nb].nom[i] = tolower(tab[nb].nom[i]);
	}

    do{
        printf("\n\nSelectionner son espece:\n0:VARACTYL\n1:ZILLO BEAST\n2:PORG\n3:AIWHAS\n4:BANTHA\n5:KOWAKIEN\n");
        
        	while(scanf("%d", &tab[nb].race)!=1){
        	
        		while (getchar() != '\n');
        		printf("Veuillez rentrer un entier\n");
        	}
    
    	while (getchar() != '\n');
    
    }while (tab[nb].race<0 || tab[nb].race>5);


    printf("\n\nNous sommes en 3026 et il nous est impossible de prendre des animaux nés avant 2876/\n\n");

    do {
        printf("\n\nDate de naissance, veuillez respecter ce format: jj/mm/aaaa\n");
        scanf("%d/%d/%d", &tab[nb].bd.jour, &tab[nb].bd.mois, &tab[nb].bd.année);
        while (getchar() != '\n');
    }while ( (tab[nb].bd.jour<1 || tab[nb].bd.jour>31) || (tab[nb].bd.mois<1 || tab[nb].bd.mois>12) || (tab[nb].bd.année<2876 || tab[nb].bd.année>3026) );

    do {
        printf("\n\nPoids en kilogrammes:\n (Pour des raisons techniques, veuillez vous adressez a un autre refuge pour des poids supérieurs à 3 200kg)\n");
        scanf("%d", &tab[nb].poids);
        while (getchar() != '\n');
    }while (tab[nb].poids<1 || tab[nb].poids>3200);


    int remarque;
    do {
            printf("\n\nAvez-vous une remarque a faire sur %s?\n0:Oui\n1:Non\n", tab[nb].nom);
            scanf("%d", &remarque);
            while (getchar() != '\n');
    }while (remarque!=0 && remarque!=1);

    if (remarque==0) {
        printf("Que voulez-vous partager a son sujet?\n(Sans accents ni apostrophe)\n");
        fgets(tab[nb].remarque, 300, stdin);
        tab[nb].remarque[strcspn(tab[nb].remarque, "\n")]='\0';
        tab[nb].remarque[0]=toupper(tab[nb].remarque[0]);
    }
    else {
        strcpy(tab[nb].remarque,"\0");
    }

    int id;
    bool existe;

    do { //créer un nouvel ID tant que il existe déjà 
            existe=false;
            id=rand()%50+1;
            for (int i=0; i<TAILLE; i++) {
                if (tab[i].ID==id) {
                    existe=true;
                    break;
                }
            }

    }while (existe==true);
    

    tab[nb].ID=id;


    FILE * doc=fopen("../Animaux/Registre.txt", "w");
        if (doc==NULL) {
            printf("ERREUR 'adoption': %d\n", errno);
            printf("Message d'erreur: %s\n", strerror(errno));
            exit(103);
        }

    for (int i=0; i<(nb+1); i++) {
        fprintf(doc, "%d %s %d %02d/%02d/%04d %d", tab[i].ID, tab[i].nom, tab[i].race, tab[i].bd.jour, tab[i].bd.mois, tab[i].bd.année, tab[i].poids);

        if (strlen(tab[i].remarque)>0) {
            fprintf(doc, " %s", tab[i].remarque);
        }
        fprintf(doc,"\n");
    }

fclose(doc);
    printf("\n\n\nRegsitre mis a jour avec succes\n");
    
   free(tab);

}
////////////////////

