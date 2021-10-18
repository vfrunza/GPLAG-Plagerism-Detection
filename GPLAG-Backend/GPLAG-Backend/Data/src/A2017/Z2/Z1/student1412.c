#include <stdio.h>

int main() {
	int n = 0, i, j;
	do{
		printf("Unesite broj N: ");
		scanf("%d", &n);	
		if( n < 8 || n%4 != 0){
			printf("Neispravno N!\n");
		}
	}while(n < 8 || n%4 != 0);
	printf("\n");


	int k=(n/2)-1;


	for(i=0; i<n; i++) {
	    for(j=0; j<n; j++) {

	    	/*Gornja polovina matrice*/

	        if ( i <= (n/2) - 1) {

	        	/*Prvi kvadrant*/
	            if ( j <= (n/2) - 1) {

	                if ( i == j ) printf("\\");

	                else if ( j == k ) printf("/");

	                else printf(" ");
	            }

	            /*Drugi kvadrant*/
	            else if ( j > (n/2) - 1 ) {

	            	if ( i == 0 && j == (n/2) || i == 0 && j == (n-1) || i == (n/2)-1 && j == (n/2) || i == (n/2)-1 && j == (n-1) )
	            	printf("+");

	            	else if ( i == 0 && j != (n/2) || i == 0 && j != (n-1) || i == (n/2)-1 && j != (n/2) || i == (n/2)-1 && j != (n-1) )
	            	printf("-");

	            	else if (i != 0 && j == (n/2) || i != (n/2)-1 && j == (n-1) )
	            	printf("|");

	            	else printf(" ");
	            }

	        }
	        else if(i >= (n/2)){
		    	if(j <= (n/2) - 1){
		    		if(i == (n/2) && j == 0 || i == (n/2) && j == (n/2)-1 || i == (n-1) && j == 0 || i == (n-1) && j == (n/2)-1) printf("+");
                    else if(i == (n/2) && j > 0 && j < (n/2)-1 || i == (n-1) && j > 0 && j < (n/2)-1) printf("-");
                    else if(i > (n/2) && j == 0 && i <(n-1) || i > (n/2) && j == (n/2) -1 && i <(n-1)) printf("|");
		    		else printf(" ");
		    	}else if(j > (n/2) - 1){
                    int pola = n/2;
                    int jednaLinija = pola + (pola/2) - 1;
                    int drugaLinija = pola + (pola/2) ;

                    if(i == jednaLinija && j == jednaLinija && i == j  || i == drugaLinija && j == drugaLinija && i == j || i == jednaLinija && j == drugaLinija && (i+1) == j || i == drugaLinija && j == jednaLinija && i == (j+1)) printf("+");
                    else if(j == jednaLinija || j == drugaLinija) printf("|");
                    else if(i == jednaLinija || i == drugaLinija) printf("-");
                    else printf(" ");
		    	}
		    }

	    }
	    printf("\n");
	    k--;
	}

	return 0;
}
