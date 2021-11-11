#include <stdio.h>

int main() {
	int i,j,k,a,b,c;
	do{
	    printf("Unesite broj redova: ");
    	scanf("%d", &a);
	} while(a<=0 || a>10);
	do{
		printf("Unesite broj kolona: ");
		scanf("%d", &b);
	} while(b<=0 || b>10);
	do{
		printf("Unesite sirinu jedne kolone: ");
		scanf("%d", &c);
	} while(c<=0 || c>10);
	
	for(k=0;k<a;k++){

	    for(j=0;j<b;j++){
	        printf("+");
	        for(i=0;i<c;i++){
	            printf("-");
	        }
	    }
	   	printf("+\n");
	    
	    for(j=0;j<b;j++){
	    	printf("|");
	    	for(i=0;i<c;i++){
	    		printf(" ");
	    	}
	    }
	    printf("|\n");
	}
	
	for(j=0;j<b;j++){
		printf("+");
		for(i=0;i<c;i++){
			printf("-");
		}
	}
	printf("+");
	
	return 0;
}