
#include"Projet.h"


////////////////////
Animal* registre_tab(int taille) {
    FILE * fichier=fopen("../Animaux/Registre.txt", "r");
    if (fichier==NULL) {
        printf("Erreur affichage registre: %d\n", errno);
        printf("Message d'erreur: %s\n", strerror(errno));
        exit(1);
    }

    Animal *tab=malloc(sizeof(Animal)*taille);
    if (tab==NULL) {
        printf("ERREUR malloc 'regsitre_tab'\n");
        exit(1654);
    }
    char phrase[400]={0};
    char remarque_temp[300]={0};

    int i=0;

    while (fgets(phrase, sizeof(phrase), fichier)!=NULL && i<taille) {
        phrase[strcspn(phrase, "\r\n")]='\0';  //changement linux pas de \r, chez windows \r\n utilisé retour à la ligne + saut ligne

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
    fclose(fichier);
    return tab;
}
////////////////////




////////////////////
int welcome() {
    FILE * fichier=fopen("../Dessin/medical droid.txt", "r"); //Lis le texte

    if(fichier==NULL){
        printf("ERREUR welcome: %d\n", errno);
        printf("Message d'erreur: %s\n", strerror(errno));
        exit(11);
    }


    int c=fgetc(fichier);

    while(c!=EOF){

        printf("%c", c);
        c=fgetc(fichier);
    }

    printf("Votre demande (entier entre 0 et 5): ");
    int rep;
    while (scanf("%d", &rep)!=1) {
        while (getchar()!='\n');
        printf("Veuillez saisir un entier\n");
    }
    return rep;

}
////////////////////





////////////////////
void affiche_varactyl() {

    FILE * fichier=fopen("../Dessin/espece/Varactyl.txt", "r"); //Lis le texte

    if(fichier==NULL){
        printf("ERREUR 'affiche_vractyl': %d\n", errno);
        printf("Message d'erreur: %s\n", strerror(errno));
        exit(11);
    }


    int c=fgetc(fichier);

    while(c!=EOF){

        printf("%c", c);
        c=fgetc(fichier);
    }


fclose(fichier);
}
////////////////////




////////////////////
void affiche_zillo() {

    FILE * fichier=fopen("../Dessin/espece/zillo.txt", "r"); //Lis le texte

    if(fichier==NULL){
        printf("ERREUR 'affiche_zillo': %d\n", errno);
        printf("Message d'erreur: %s\n", strerror(errno));
        exit(11);
    }


    int c=fgetc(fichier);

    while(c!=EOF){

        printf("%c", c);
        c=fgetc(fichier);
    }


    fclose(fichier);
}


////////////////////
void affiche_porg() {

    FILE * fichier=fopen("../Dessin/espece/porg.txt", "r"); //Lis le texte

    if(fichier==NULL){
        printf("ERREUR 'affiche_porg': %d\n", errno);
        printf("Message d'erreur: %s\n", strerror(errno));
        exit(11);
    }


    int c=fgetc(fichier);

    while(c!=EOF){

        printf("%c", c);
        c=fgetc(fichier);
    }


    fclose(fichier);
}
////////////////////



////////////////////
void affiche_aiwhas() {

    FILE * fichier=fopen("../Dessin/espece/aiwhas.txt", "r"); //Lis le texte

    if(fichier==NULL){
        printf("ERREUR 'affiche_aiwhas': %d\n", errno);
        printf("Message d'erreur: %s\n", strerror(errno));
        exit(11);
    }


    int c=fgetc(fichier);

    while(c!=EOF){

        printf("%c", c);
        c=fgetc(fichier);
    }


    fclose(fichier);
}
////////////////////



////////////////////
void affiche_bantha() {

    FILE * fichier=fopen("../Dessin/espece/Bantha.txt", "r"); //Lis le texte

    if(fichier==NULL){
        printf("ERREUR 'affiche_bantha': %d\n", errno);
        printf("Message d'erreur: %s\n", strerror(errno));
        exit(11);
    }


    int c=fgetc(fichier);

    while(c!=EOF){

        printf("%c", c);
        c=fgetc(fichier);
    }


    fclose(fichier);
}
////////////////////




////////////////////
void affiche_kowakien() {

    FILE * fichier=fopen("../Dessin/espece/kowak.txt", "r"); //Lis le texte

    if(fichier==NULL){
        printf("ERREUR 'affiche_kowak': %d\n", errno);
        printf("Message d'erreur: %s\n", strerror(errno));
        exit(11);
    }


    int c=fgetc(fichier);

    while(c!=EOF){

        printf("%c", c);
        c=fgetc(fichier);
    }


    fclose(fichier);
}
////////////////////




////////////////////
void bye() {
    FILE * fichier=fopen("../Dessin/bye.txt", "r");

    if(fichier==NULL){
        printf("ERREUR bye: %d\n", errno);
        printf("Message d'erreur: %s\n", strerror(errno));
        exit(11);
    }


    int c=fgetc(fichier);

    while(c!=EOF){

        printf("%c", c);
        c=fgetc(fichier);
    }

}
////////////////////








////////////////////
void adoption_possible() {
    FILE * fichier=fopen("../Dessin/Watto/watto_possible.txt", "r"); //Lis le texte

    if(fichier==NULL){
        printf("ERREUR 'adoption_possible': %d\n", errno);
        printf("Message d'erreur: %s\n", strerror(errno));
        exit(14);
    }


    int c=fgetc(fichier);

    while(c!=EOF){

        printf("%c", c);
        c=fgetc(fichier);
    }


    fclose(fichier);
}
////////////////////



////////////////////
void adoption_impossible() {
    FILE * fichier=fopen("../Dessin/Watto/watto_impossible.txt", "r"); //Lis le texte

    if(fichier==NULL){
        printf("ERREUR 'adoption_impossible': %d\n", errno);
        printf("Message d'erreur: %s\n", strerror(errno));
        exit(14);
    }


    int c=fgetc(fichier);

    while(c!=EOF){

        printf("%c", c);
        c=fgetc(fichier);
    }


    fclose(fichier);
}
////////////////////





////////////////////
void watto_bonjour() {

    FILE * fichier=fopen("../Dessin/Watto/watto1.txt", "r"); //Lis le texte

    if(fichier==NULL){
        printf("ERREUR 'watto_bonjour': %d\n", errno);
        printf("Message d'erreur: %s\n", strerror(errno));
        exit(15);
    }


    int c=fgetc(fichier);

    while(c!=EOF){

        printf("%c", c);
        c=fgetc(fichier);
    }


    fclose(fichier);
}
////////////////////




////////////////////
void watto_espece() {

    FILE * fichier=fopen("../Dessin/Watto/watto2.txt", "r"); //Lis le texte

    if(fichier==NULL){
        printf("ERREUR 'watto_espece': %d\n", errno);
        printf("Message d'erreur: %s\n", strerror(errno));
        exit(16);
    }


    int c=fgetc(fichier);

    while(c!=EOF){

        printf("%c", c);
        c=fgetc(fichier);
    }


    fclose(fichier);
}
////////////////////


////////////////////
void wando_id() {
    FILE * fichier=fopen("../Dessin/Mando/mando_id.txt", "r"); //Lis le texte

    if(fichier==NULL){
        printf("ERREUR 'wando_id': %d\n", errno);
        printf("Message d'erreur: %s\n", strerror(errno));
        exit(41);
    }


    int c=fgetc(fichier);

    while(c!=EOF){

        printf("%c", c);
        c=fgetc(fichier);
    }


    fclose(fichier);
}
////////////////////


////////////////////
void wando_id_introuvable() {
    FILE *fichier = fopen("../Dessin/Mando/mando_id_introuvable.txt", "r"); //Lis le texte

    if
    (fichier == NULL){
        printf("ERREUR 'wando_id_introuvable': %d\n", errno);
        printf("Message d'erreur: %s\n", strerror(errno));
        exit(456576);
    }


    int c = fgetc(fichier);

    while (c!=EOF){

        printf("%c", c);
        c=fgetc(fichier);
    }


    fclose(fichier);

}
////////////////////



////////////////////
void mando_provenance() {
    FILE *fichier = fopen("../Dessin/Mando/mando_provenance.txt", "r"); //Lis le texte

    if
    (fichier == NULL){
        printf("ERREUR 'wando_provenance': %d\n", errno);
        printf("Message d'erreur: %s\n", strerror(errno));
        exit(453);
    }


    int c = fgetc(fichier);

    while (c!=EOF){

        printf("%c", c);
        c=fgetc(fichier);
    }


    fclose(fichier);

}
////////////////////




////////////////////
void mando_empire() {
    FILE *fichier = fopen("../Dessin/Mando/mando_empire.txt", "r"); //Lis le texte

    if
    (fichier == NULL){
        printf("ERREUR 'wando_empire': %d\n", errno);
        printf("Message d'erreur: %s\n", strerror(errno));
        exit(482);
    }


    int c = fgetc(fichier);

    while (c!=EOF){

        printf("%c", c);
        c=fgetc(fichier);
    }


    fclose(fichier);

}
////////////////////




////////////////////
void mando_accepte() {
    FILE *fichier = fopen("../Dessin/Mando/mando_accepte.txt", "r"); //Lis le texte

    if
    (fichier == NULL){
        printf("ERREUR 'wando_accepte': %d\n", errno);
        printf("Message d'erreur: %s\n", strerror(errno));
        exit(511);
    }


    int c = fgetc(fichier);

    while (c!=EOF){

        printf("%c", c);
        c=fgetc(fichier);
    }


    fclose(fichier);

}
////////////////////



////////////////////
void mando_refuse() {
    FILE *fichier = fopen("../Dessin/Mando/mando_refuse.txt", "r"); //Lis le texte

    if
    (fichier == NULL){
        printf("ERREUR 'wando_refuse': %d\n", errno);
        printf("Message d'erreur: %s\n", strerror(errno));
        exit(539);
    }


    int c = fgetc(fichier);

    while (c!=EOF){

        printf("%c", c);
        c=fgetc(fichier);
    }


    fclose(fichier);

}
////////////////////


////////////////////
void mando_yoda() {
    FILE *fichier = fopen("../Dessin/Mando/mando_yoda.txt", "r"); //Lis le texte

    if(fichier == NULL){
        printf("ERREUR 'wando_yoda': %d\n", errno);
        printf("Message d'erreur: %s\n", strerror(errno));
        exit(565);
    }


    int c = fgetc(fichier);

    while (c!=EOF){

        printf("%c", c);
        c=fgetc(fichier);
    }


    fclose(fichier);

}
////////////////////



////////////////////
void mando_alerte() {
    FILE *fichier = fopen("../Dessin/Mando/mando_alerte.txt", "r"); //Lis le texte

    if(fichier == NULL){
        printf("ERREUR 'wando_alerte': %d\n", errno);
        printf("Message d'erreur: %s\n", strerror(errno));
        exit(592);
    }


    int c = fgetc(fichier);

    while (c!=EOF){

        printf("%c", c);
        c=fgetc(fichier);
    }


    fclose(fichier);

}
////////////////////
