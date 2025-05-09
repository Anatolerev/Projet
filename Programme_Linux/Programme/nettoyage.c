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
const char* race_espece(Espece race) { //renvoie une valeur lors entrée 'espece'
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

    Animal *tab=registre_tab(TAILLE);//recupère tableau avec info du registre
    if (tab==NULL) {
        printf("ERREUR tab_regsitre 'nettoyage'\n");
        exit(487);
    }

    Race_compte *tab2=malloc(sizeof(Race_compte)*6);// création tableau {"race", nombre}

    if (tab2==NULL) {
        printf("ERREUR tab2 'compter'\n");
        exit(174);
    }

    strcpy(tab2[0].nom, "VARACTYL"); //insertion nom dans tableau
    strcpy(tab2[1].nom, "ZILLO_BEAST");
    strcpy(tab2[2].nom, "PORG");
    strcpy(tab2[3].nom, "AIWHAS");
    strcpy(tab2[4].nom, "BANTHA");
    strcpy(tab2[5].nom, "KOWAKIEN");

    for (int i=0; i<6; i++) { //initilisation des comptes à 0
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
    free(tab);
    return tab2;
}
////////////////////




////////////////////
void nettoyage() {
    FILE * cavalier=fopen("../Nettoyage/Cavalier.txt", "r");// affichage presentation cavalier
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



    FILE* fichier = fopen("../Nettoyage/donnees.txt", "r");//ouverture des données de nettoyage
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

    Race_compte *tab_count=compter_animaux_race();// recupère tableau avec le compte par race
    
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

	int temps_minute=tab[i].temps * count;//temps nettoyage*nombre de betes/espece
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








