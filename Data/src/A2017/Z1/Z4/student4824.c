#include <stdio.h>

int main() {
	int r,k,sk,i,j;
	do {
	printf("Unesite broj redova: ");
	scanf("%d",&r);
		
	}
	while (r<=0 || r>10);
	do {
	printf("Unesite broj kolona: ");
	scanf("%d",&k);
		
	}
	while(k<=0 || k>10);
	do {
	printf("Unesite sirinu jedne kolone: ");
	scanf("%d",&sk);
		
	} while(sk<=0 || sk>=11);
	
	for(i=0; i<((r*2)+1); i++) {
		for(j=0; j<((sk+1)*k+1); j++) {
			
			if (sk%2!=0 || sk%2==0) { 
				if ((i==0 || i%2==0) && ( j%(sk+1)==0 || j==0)){
					printf("+");
					
				} else if((i==0 || i%2==0) && (j%(sk+1)!=0)){
					printf("-");
					
				} else if(i%2!=0 && (j==0 || (j%(sk+1)==0))) {
					printf("|");
				} else {
					printf(" ");
				}
				
			}
			
		}
		printf("\n");
		
	}
		return 0; 
		
	}
		
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	

