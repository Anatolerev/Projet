#include"Projet.h"

////////////////////
Temps convertion_temps(int t){


	int h=0;
	
	Temps t1;
	t1.heure=0;
	t1.minute=0;

	if(t<0){
		printf("ERREUR 'convertion_temps'\n");
		exit(45);
	}
	

	h=t/60;
	t%=60;
	
	
t1.heure=h;
t1.minute=t;


return t1;
}
////////////////////





////////////////////
const char* race_espece(Espece race) {
    switch (race) {
        case VARACTYL: return "VARACTYL";
        case ZILLO_BEAST: return "ZILLO_BEAST";
        case PORG: return "PORG";
        case AIWHAS: return "AIWHAS";
        case BANTHA: return "BANTHA";
        case KOWAKIEN: return "KOWAKIEN";
        default: return "INCONNU";
    }
}
////////////////////




////////////////////
Race_compte* compter_animaux_race() {

    Animal *tab=registre_tab(TAILLE);
    if (tab==NULL) {
        printf("ERREUR tab_regsitre 'nettoyage'\n");
        exit(487);
    }

    Race_compte *tab2=malloc(sizeof(Race_compte)*6);

    if (tab2==NULL) {
        printf("ERREUR tab2 'compter'\n");
        exit(174);
    }

    strcpy(tab2[0].nom, "VARACTYL");
    strcpy(tab2[1].nom, "ZILLO_BEAST");
    strcpy(tab2[2].nom, "PORG");
    strcpy(tab2[3].nom, "AIWHAS");
    strcpy(tab2[4].nom, "BANTHA");
    strcpy(tab2[5].nom, "KOWAKIEN");

    for (int i=0; i<6; i++) {
        tab2[i].count=0;
    }



    for (int i=0; i<TAILLE; i++) {
        if (tab[i].ID==0 && strlen(tab[i].nom)==0) {
            continue;
        }

        switch (tab[i].race) {
            case(0):tab2[0].count++;
            break;

            case(1): tab2[1].count++;
            break;

            case(2): tab2[2].count++;
            break;

            case(3): tab2[3].count++;
            break;

            case(4): tab2[4].count++;
            break;

            case(5): tab2[5].count++;
            break;

            default:printf("Erreur race 'afficher resigtre'\n");
            exit(1565);
            break;
        }

    }
    return tab2;
}
////////////////////




////////////////////
void nettoyage() {
    FILE * cavalier=fopen("../Nettoyage/Cavalier.txt", "r");
    if (cavalier==NULL) {
        printf("Erreur nettoyage: %d\n", errno);
        printf("Message d'erreur: %s\n", strerror(errno));
        exit(21);
    }
    int a=fgetc(cavalier);

    while (a!=EOF) {
        printf("%c", a);
        a=fgetc(cavalier);
    }

    fclose(cavalier);

    sleep(3);



    FILE* fichier = fopen("../Nettoyage/donnees.txt", "r");
    if (fichier == NULL) {
        printf("Erreur nettoyage: %d\n", errno);
        printf("Message d'erreur: %s\n", strerror(errno));
        exit(10);
    }

    Clean tab[6];
    int i = 0;

    while (i < 6 && fscanf(fichier, "%19s %d %d %199[^\n]", tab[i].jour, &tab[i].race, &tab[i].temps, tab[i].comment) == 4) {
        i++;
    }

    fclose(fichier);

    Race_compte *tab_count=compter_animaux_race();
    if (tab_count==NULL) {
        printf("ERREUR tab_count 'nettoyage'\n");
        exit(12365);
    }

    printf("\n\n\n");


    for (int i = 0; i < 6; i++) {

        int count=0;

        for (int j=0; j<6; j++) {

            if ( strcmp( race_espece(tab[i].race), tab_count[j].nom )==0) {
                count=tab_count[j].count;
                break;
            }
        }

	int temps_minute=tab[i].temps * count;
        Temps t1=convertion_temps(temps_minute);
        
        printf("\n***\n");
        printf("Jour: %s\n", tab[i].jour);
        printf("Espece: %s\n", race_espece(tab[i].race));
        printf("Temps unitaire en minutes: %d\n", tab[i].temps);
        printf("Temps total: %dheure(s) %d minute(s)\n", t1.heure, t1.minute);
        printf("Commentaire: %s\n", tab[i].comment);
        printf("***\n");
    }




    free(tab_count);
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
}
////////////////////



////////////////////
void ajouter_animal() {
    watto_bonjour();
    printf("\n\n____________________________\nAppuyer deux fois sur entrer\n\n");
    getchar();
    getchar();

    printf("\n\n");
    watto_espece();
    printf("\n\n____________________________\nAppuyer deux fois sur entrer\n\n");
    getchar();
    getchar();



    srand(time(NULL));
    Animal *tab=registre_tab(TAILLE);
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


    if (nb==-1 || nb==50) {
        adoption_impossible();
        return; 
    }
    else {
        adoption_possible();
    }



    printf("\n\nNom: ");
    scanf(" %s", tab[nb].nom);
    while (getchar() != '\n');

    tab[nb].nom[0]=toupper(tab[nb].nom[0]);

    do {
        printf("\n\nSelectionner son espece:\n0:VARACTYL\n1:ZILLO BEAST\n2:PORG\n3:AIWHAS\n4:BANTHA\n5:KOWAKIEN\n");
        scanf(" %d", &tab[nb].race);
        while (getchar() != '\n');
    }while (tab[nb].race<0 || tab[nb].race>5);

    
    printf("\n\nNous sommes en 3026 et il nous est impossible de prendre des animaux nés avant 2876/\n\n");
    
    do {
        printf("\n\nDate de naissance, veuillez respecter ce format: jj/mm/aaaa\n");
        scanf("%d/%d/%d", &tab[nb].bd.jour, &tab[nb].bd.mois, &tab[nb].bd.année);
        while (getchar() != '\n');
    }while ( (tab[nb].bd.jour<1 || tab[nb].bd.jour>31) || (tab[nb].bd.mois<1 || tab[nb].bd.mois>12) || (tab[nb].bd.année<2876 || tab[nb].bd.année>3026) );

    do {
        printf("\n\nPoids en kilogrammes:\n");
        scanf("%d", &tab[nb].poids);
        while (getchar() != '\n');
    }while (tab[nb].poids<1 || tab[nb].poids>3200);


    int remarque;
    do {
            printf("Avez-vous une reamrque a faire sur %s?\n0:Oui\n1:Non\n", tab[nb].nom);
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

    do {
            existe=false;
            id=rand()%51+1;
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
    printf("Regsitre mis a jour avec succes\n");

}
////////////////////

