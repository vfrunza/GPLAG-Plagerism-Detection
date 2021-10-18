#include <stdio.h>

int main() {

	float broj_redova, sirina_kolone, broj_kolona;
	int i,j,k,n;

	do{

		printf("Unesite broj redova: ");
		scanf("%f", &broj_redova);
	


	}while(broj_redova<=0 || broj_redova>10 ) ;
	
	
	do{
	    	printf("Unesite broj kolona: ");
	    	scanf("%f", &broj_kolona);
	
	}while(broj_kolona<=0 || broj_kolona>10);
	


	do{
	    	printf("Unesite sirinu jedne kolone: ");
		    scanf("%f", &sirina_kolone);
	}while(sirina_kolone<=0 || sirina_kolone>10);




	for(i=0; i<=broj_redova; i++){
        for(j=0; j<broj_kolona; j++){
            printf("+");

            for(n=0; n<sirina_kolone; n++){
                printf("-");
            }
        }

        printf("+");
        printf("\n");

        if(i < broj_redova) {
            for(j=0; j<=broj_kolona; j++){
                printf("|");


                for(n=0; n<sirina_kolone; n++){
                    printf(" ");

                }
            }
        }

        printf("\n");
    }

	

  
	

return 0;
}
