#include <stdio.h>

int main() {
	int i;
	char jelo, tarik_izbor, bojan_izbor, mirza_izbor;
	float restoran=0,Fastfood=0,bistro=0,odluka=0,snizenje_restoran=0;
	int brpizza=0,brcevapa=0,brhamburgera=0;
	
	
	for (i=0; i<3; i++) {
		if (i==0) {
			printf("Unesite jelo za Tarika: ");
			scanf(" %c", &tarik_izbor);
			jelo = tarik_izbor;
		}else if (i==1){
			printf("Unesite jelo za Bojana: ");
			scanf(" %c", &bojan_izbor);
			jelo = bojan_izbor;
		} else {
			printf("Unesite jelo za Mirzu: ");
			scanf(" %c", &mirza_izbor);
			jelo = mirza_izbor;
		} 
		if(jelo == 'P') {
			restoran+=6.8;
			Fastfood+=8;
			bistro+=5.3;
			brpizza++; 
		} else if (jelo == 'H') {
			restoran+=3.3;
			Fastfood+=3;
			bistro+=5;
			brhamburgera++;
		} else {
			restoran+=5;
			Fastfood+=3.9;
			bistro+=6;
			brcevapa++;
		} 
	}

		
		if (restoran>Fastfood) odluka=Fastfood;
	       else odluka=restoran;
	    if (odluka>bistro) odluka=bistro;
	    
	    if (odluka==bistro){
	    	printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM). \n", odluka);
	    } else if (odluka==Fastfood){
	    		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM). \n", odluka);
	    } else {
	    		printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM). \n", odluka);
	    }
	    
        if(brpizza*0.68>brcevapa*0.5){
        	snizenje_restoran=brpizza*0.68;
        } else { snizenje_restoran=brcevapa*0.5;
        }
        if (brhamburgera*0.33>snizenje_restoran) {
        snizenje_restoran=brhamburgera*0.33; 
        }
	   
	    
	    if(restoran-snizenje_restoran<odluka)
	    if(odluka!=restoran)
	    printf ("Sa popustom bi Restoran bio jeftiniji (%.2f KM). \n", restoran-snizenje_restoran);
	    
	 
	   
	    
	 
   /*printf("---------------------------------\n" );
   printf("restoran: %.2f\n", restoran );
   printf("fastfood : %.2f\n", Fastfood );
   printf("bistro : %.2f\n", bistro );
   printf("snizenje: %.2f\n", snizenje_restoran ); 
   printf("brham %d brcev %d brpica %d", brhamburgera, brcevapa, brpizza);*/
	    
	     return 0;
	}