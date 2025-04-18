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
}Date;


typedef struct {

    int ID;
    char nom[100];
    Date bd;
    int poids;

}Animal;


typedef struct {
    char jour[20];
    Espece race;
    int temps;
    char comment[200];
}Clean;


int welcome();
void bye();
const char* espece_to_string(Espece race);
void nettoyage();
