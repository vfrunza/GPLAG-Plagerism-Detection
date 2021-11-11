#include <stdio.h>

int main() {
	int i,j,redovi,kolone,sirina,k=0;
	
	do {
		printf("Unesite broj redova: ");
		scanf("%d", &redovi);
	} while(redovi<=0 || redovi>10);
	
		do {
		printf("Unesite broj kolona: ");
		scanf("%d", &kolone);
	} while(kolone<=0 || kolone>10);
	
		do {
		printf("Unesite sirinu jedne kolone: ");
		scanf("%d", &sirina);
	} while(sirina<=0 || sirina>10);
	
	for(i=0;i<2*redovi+1;i++) {
		
		for(j=0;j<kolone*sirina+kolone+1;j++){
			
		   if(i%2==0 && (j==0 || j==k*sirina+k)) {
		   	printf("+");
		   	k++;
		   }
			else if(i%2==0) {
				printf("-");
			}
			
		   else if(i%2==1 && (j==0 || j==k*sirina+k)) {
		   	printf("|");
		   	k++;
		   }
		  
		  else {
		  	printf(" ");
		  }
		 
			}
		k=0;
		
		printf("\n");
	}
	
	
	
	return 0;
}
