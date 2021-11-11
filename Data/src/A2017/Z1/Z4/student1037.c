#include <stdio.h>

int main() {

	float br_redova, sirina_kolone, br_kolona;
	int i, j, n,k;
    do{

		printf("Unesite broj redova: ");
		scanf("%f", &br_redova);
	


	}
	while(br_redova<=0 || br_redova>10 ) ;
	
	
	do{
	    	printf("Unesite broj kolona: ");
	    	scanf("%f", &br_kolona);
	
	}
	while(br_kolona<=0 || br_kolona>10);
	


	do{
	    	printf("Unesite sirinu jedne kolone: ");
		    scanf("%f", &sirina_kolone);
		    
	}
	while(sirina_kolone<=0 || sirina_kolone>10);

	while(br_redova<0 || br_redova>10 ||
	br_kolona<0 || br_kolona>10 || sirina_kolone<0 || sirina_kolone>10) ;

	for(i = 0; i <= br_redova; i++){
	    
        for(j = 0; j < br_kolona; j++){
            
            printf("+");

            for(n = 0; n < sirina_kolone; n++){
                
                printf("-");
            }
        }

        printf("+");
        printf("\n");

        if(i < br_redova) {
            
            for(j = 0; j <=br_kolona; j++){
                
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