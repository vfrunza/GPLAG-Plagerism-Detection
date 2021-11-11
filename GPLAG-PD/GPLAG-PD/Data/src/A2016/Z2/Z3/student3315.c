#include <stdio.h>

int main() {
	int b,e,a,c;
	int k=0,brojac=0;
	do{
		printf("Unesite broj tacaka: ");
		scanf("%d",&c);
		if(c>0 && c<=10) 
			break;
		else
			printf("Pogresan unos\n");
		
		
	}
	
	while(5);
    int prviniz[10];
    int druginiz[10];
    do{
    printf("Unesite %d. tacku: ",k+1);
    scanf("%d%d",&prviniz[k],&druginiz[k]);
    if(prviniz[k]<0 || prviniz[k]>19 || druginiz[k]<0 || druginiz[k]>19) {
    	printf("Pogresan unos\n");
    	continue;
    }
    
    k++; 
    }
    while(k<c);
    
    for(a=0;a<20;a++){
    	for(b=0;b<20;b++) {
    		for(e=0;e<c;e++){
    if(b==prviniz[e] && a==druginiz[e]) {			
    		printf("*");
    		break;
    		}
    brojac++;
    
    	}
    	
    if(brojac==c) 
    	printf(" ");
    brojac=0;
    	
    	}	
    printf("\n");
    }
    return 0;
    }
