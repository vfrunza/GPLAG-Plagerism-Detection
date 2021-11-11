#include <stdio.h>

int main() {
	int i, j, n, x [10], y [10], k;
	char niz [20][20];
	
	for(i=0; i<20; i++) {
	for(j=0; j<20; j++) {
			
		 niz[i][j]=' ';
			
		}
		
	}
	
	do{
		
	printf("\nUnesite broj tacaka: ");
	scanf("%d", &n);
    if(n>10 || n<=0) printf("Pogresan unos");
    
	}while(n>10 || n<=0);
    
    
    for(k=0; k<n; k++){
    	
        printf("Unesite %d. tacku: ", k+1);
        scanf("%d %d",&x[k], &y[k] );
        
        if(x[k] < 0 || x[k] > 19 || y[k] < 0 || y[k] > 19){
        	printf("Pogresan unos\n");
        	k--;
        }
    }
	
	for(k=0; k<n; k++) {
	for(i=0; i<20; i++) {
		for(j=0; j<20; j++) {
			if(i==y[k] && j==x[k]){
			niz[i][j]='*';	
	     		} 
     		}
		}

	}
	
		for(i=0; i<20; i++) {
		for(j=0; j<20; j++) {
		printf("%c", niz[i][j]);
		  	}
		printf("\n");
	}
	
	return 0;
}
