#include <stdio.h>

int main() {
	
	int broj_tacaka, x_koordinate[10], y_koordinate [10], i, j, k;
	char prostor [20][20];
	
	for(i=0; i<20; i++){
	    
        for(j=0; j<20; j++){
        prostor[i][j]=' ';
    }
}

	do{
		
	printf("\nUnesite broj tacaka: ");
	scanf("%d", &broj_tacaka);
    if(broj_tacaka>10 || broj_tacaka<=0) printf("Pogresan unos");
    
	}while(broj_tacaka>10 || broj_tacaka<=0);
    
    
    for(k=0; k<broj_tacaka; k++){
    	
        printf("Unesite %d. tacku: ", k+1);
        scanf("%d %d",&x_koordinate[k], &y_koordinate[k] );
        
        if(x_koordinate[k] < 0 || x_koordinate[k] > 19 || y_koordinate[k] < 0 || y_koordinate[k] > 19){
        	printf("Pogresan unos\n");
        	k--;
        }
       
        
    }

    for(i=0; i<broj_tacaka; i++){
    	
    	for(j=0; j<20; j++) {
    	    
    	    for(k=0; k<20; k++){
    	       
    	        if(j==y_koordinate[i] && k==x_koordinate[i]) {
    	            prostor[j][k]='*';
    	        }
    	        
    	    }
    	    
    	}

        
    }

for(i=0; i<20; i++){
    
    for(j=0; j<20; j++){
        printf("%c", prostor[i][j]);
    }
    
    printf("\n");
}

	return 0;
}
