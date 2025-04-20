#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>
#include<time.h>
#include<unistd.h>



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


int welcome();
void bye();
const char* race_espece(Espece race);
void nettoyage();
