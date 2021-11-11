#include <stdio.h>

int main() {
	int i,j,r,k,s;
	do{
	printf("Unesite broj redova: ");
	scanf("%d", &r); 
	}while (r<=0 || r>10);
	do{
	printf("Unesite broj kolona: ");
	scanf("%d", &k); 
	}while(k<=0 || k>10);
	do{
	printf("Unesite sirinu jedne kolone: ");
	scanf("%d", &s);
	}while(s<=0 || s>10);
	
	for(i=0; i<2*r+1; i++){
		if(i%2==0){
			for(j=0; j<s*k+k+1; j++){
				if(j%(s+1)==0){
					printf("+");
				} else printf("-");
			} printf("\n");
			} 
			  
		
			if(i%2!=0){
				for(j=0; j<s*k+k+1; j++){
					if(j%(s+1)==0){
						printf("|");
					} else printf(" ");
				} printf("\n");
			} }  
			return 0; }
	
		
	