#include "Projet.h"


////////////////////
void adoption(){  //créer un nouveau registre en fonction de l'ID autorisé ou pas 
	int ID;
	int trv=0;

	printf("\n\n\n\n");
    	wando_id(); //demande ID

	do {
	    printf("\n\nVotre demande (entier entre 0 et 50 inclus): ");
		while (scanf("%d", &ID)!=1) {
			while (getchar()!='\n');
			printf("Veuillez saisir un entier\n");
		}
	}while (ID<0 || ID>50);







	FILE *fichier = fopen("../Animaux/Registre.txt","r"); //ouverture regitre + fichier temporaire
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


	while(fgets(line, sizeof(line),fichier)!=NULL && i<TAILLE){ // copie du registre dans le temporaire sans Id rechercher
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

	mando_provenance(); //demande empire/republqiue/autres



	do {
		printf("\n\nVotre demande(entier entre 1 et 3 inclus): ");
		while (scanf("%d",&R)!=1) {
			while (getchar()!='\n');
			printf("Veuillez saisir un entier\n");
		}
	}while(R<1 || R>3 );

	printf("\n\n\n\n");
	
	switch (R) {
		case(1):
    			mando_empire();//refuse empire
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
			printf("\n\n\n\n");
			while(getchar()!='\n');
			printf("\n***\nQuelle est votre titre ou votre nom?\n");
			fgets(titre, 50, stdin);

		titre[0]=toupper(titre[0]);
		titre[strcspn(titre, "\n")]='\0';
		
		for (int i = 1; titre[i] != '\0'; i++) {
	   		 titre[i] = tolower(titre[i]);
		}
		 


		if( strcmp(titre, "Yoda")==0){
			printf("\n\n\n\n");
			mando_yoda();//si yoda accepte

			remove(FILENAME);
			rename(TEMPFILE, FILENAME);

		}
		else if(strcmp(titre, "Chasseur de prime")==0) {
			if ( a2.race!=1) {
				//demande pas zillo donc ok
				printf("\n\n\n\n");
				mando_accepte();


				remove(FILENAME);
				rename(TEMPFILE,FILENAME);

			}
			else {
				printf("\n\n\n\n");
				mando_refuse();
				remove(TEMPFILE);
			}
		}
		else {
			if (a2.race!=1) {
                		printf("\n\n\n\n");
                		mando_accepte();
			    	
			    	remove(FILENAME);
				rename(TEMPFILE,FILENAME);
			}
			else {
			    printf("\n\n\n\n");
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
