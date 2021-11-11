#include <stdio.h>
#include <stdlib.h>

int main() {
	
	
	int  j, i, prvi=0, drugi=0, novi_broj=0, temp=0;
	long int broj, broj_sa_predznakom;
	
	printf("Unesite broj: ");
	scanf(" %ld", &broj_sa_predznakom);
	
	broj = abs(broj_sa_predznakom);
	
	if (broj>=0 && broj<10){
		printf("0");
	}
	
	else{
	
    i=0;
	do{
	    i++;	
	    prvi  = broj%10;
        broj /= 10;
		drugi = broj%10;
		
		temp = abs((prvi - drugi));

        if(i==1){ 
        	novi_broj=novi_broj + temp;
        
        }
        
        else{
        	for(j=1; j<i; j++){
        	temp*=10;
        	}
        	novi_broj=temp+novi_broj;
        	
        		
        	}
        
			
		
	} while(broj>9);
     
	printf("%d",novi_broj);
	
    }


	
	return 0;
}
