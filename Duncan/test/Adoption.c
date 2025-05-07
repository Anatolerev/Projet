#include "Projet.h"
#define FILENAME "../Animaux/Registre.txt"
#define TEMPFILE "../Animaux/temp.txt"





int main() {
    
    int ID;
    int trv=0;
   
    printf("Quel est l' ID de l'animal a adopter ? \n ");
    scanf("%d", &ID);
    
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

	
	
	
	if(trv>1){ //stop si deux ID identiques
		printf("Trouvé deux ID correspondant\nERREUR\n");
		return 0;
	}

	
	
	if(trv==1) {
	    int R;
	    char titre[50];
	    
	    printf( "ID trouvé dans le registre ! \n" );
	    
	    
	   
	    printf("\nD'où venez vous? \n1:Empire\n2:République\n3:Autres\n");	    
	    scanf("%d",&R);
	    
	    while(R<1 || R>3 ){
		    printf("\n\n***\nERREUR\n***\n\nD'où venez vous? \n1:Empire\n2:République\n3:Autres\n");
		     scanf("%d",&R);
	    }
	    
	    
		if(R==1){ 
			printf("Nous n'avons plus d'animaux pour vous!\nLes autorités republicaines sont en routes\nVeuillez vous soumettre sans montrer de resistance.\n");
			return 0 ;
		} 
		else if(R==2 && a2.race!=1) { //demande pas zillo donc ok
			printf("Adoption accordé !\n ");
		
			remove(FILENAME);
			rename(TEMPFILE,FILENAME);
		
	       		printf("adoption enregistré!\n");
		}		
		else if(R==2 && a2.race==1){//id zillo beast donc refusé
		 	printf("l'adoption est refusé !\nIl vous est impossible d'adopter le zillo beast\n " );
	       		return 0;
		
		}
		else{
		
			printf("Quelle est votre titre ou votre nom?\n Veuilllez à mettre des '_' dans les noms composés\n");
			scanf(" %s", titre);
			
			titre[0]=toupper(titre[0]);//verifier
			
			
			if( strcmp(titre, "Yoda")==0){
			    printf("acces autorisé !! \n");
			    
			     printf("adoption accordé !\n ");
			
			    remove(FILENAME);
			    rename(TEMPFILE, FILENAME);
			
			    printf("adoption enregistré!\n");
			    
			}		       
		       	else if(strcmp(titre, "Chasseur_de_prime")==0 && a2.race!=1){ //demande pas zillo ok
			     printf("acces autorisé !! \n");
			    
			     printf("adoption accordé !\n ");
			
			    remove(FILENAME);
			    rename(TEMPFILE,FILENAME);
			
			    printf("adoption enregistré!\n");
			    
			}
			if(strcmp(titre, "Chasseur_de_prime")==0 && a2.race==1){//demande zillo refusé
			 printf("l'adoption est refusé !\nVous n'avez pas les droits\n " );
			return 0;
			
			}
	   
	    }
	}
}
