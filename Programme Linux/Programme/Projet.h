#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>
#include<time.h>
#include<unistd.h>
#include<ctype.h>
#define TAILLE 51
#include<stdbool.h>


typedef  struct {
    char nom[20];
    int count;
}Race_compte;


typedef enum {
    VARACTYL,
    ZILLO_BEAST,
    PORG,
    AIWHAS,
    BANTHA,
    KOWAKIEN,

}Espece;



typedef struct {
    int jour;
    int mois;
    int année;
    int age;
}Date;


typedef struct {

    int ID;
    char nom[100];
    Espece race;
    Date bd;
    int poids;
    char remarque[300];

}Animal;


typedef struct {
    char jour[20];
    Espece race;
    int temps;
    char comment[200];
}Clean;


int welcome();//welcome.c
void bye();//welcome.c
Animal* registre_tab(int taille);//welcome.c
void affiche_varactyl();//welcome.c
void affiche_zillo();//welcome.c
void affiche_kowakien();//welcome.c
void affiche_bantha();//welcome.c
void affiche_aiwhas();//welcome.c
void affiche_porg();//welcome.c
void adoption_impossible();//welcome.c
void adoption_possible();//welcome.c
void watto_bonjour();//welcome.c
void watto_espece();//welcome.c


void afficher_registre(); //nettoyage.c
const char* race_espece(Espece race);//nettoyage.c
void nettoyage();//nettoyage.c
void ajouter_animal();//nettoyage.c
Race_compte* compter_animaux_race();//nettoyage.c
void echanger(Race_compte* a, Race_compte* b);//nettoyage.c
int partition(Race_compte tab[], int low, int high);//nettoyage.c
void quicksort(Race_compte tab[], int low, int high);//nettoyage.c


int *rechercher_nom(Animal *tab, int taille);//recherche.c
int *rechercher_age(Animal *tab, int taille);//recherche.c
int* rechercher_espece(Animal *tab, int taille);//recherche.c
void compare_affiche( Animal *tab, int *tab_ID1, int *tab_ID2, int taille);//recherche.c
void rechercher_animal();//recherche.c
void afficher_recherche(int *search1, int *search2);//recherche.c







