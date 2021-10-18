#include <stdio.h>

int main() {
	int  i, j, a, b, c, k, l, m;
	do{
		printf("Unesite broj redova: ");
		scanf("%d", &a);
		printf("Unesite broj kolona: ");
		scanf("%d", &b);
		printf("Unesite sirinu jedne kolone: ");
		scanf("%d", &c);
	}while((a<=0 && a>10) || (b<=0 && b>10) || (c<=0 && c>10));
		
	for(i=1; i<a+2; i++) {
		for(j=1; j<b+2; j++) {
			 if(j!=b+1){ 
			 printf("+");
			 
			for(k=1; k<c+1; k++){
			printf("-");
			
		}
		}else
			printf("+");
			
			}
		printf("\n");
		
		if(i!=a+1){
			for(l=1; l<b+2; l++){
				if(l!=b+1){
				printf("|");
				
				for(m=1; m<c+1; m++)
				printf(" ");
				
				} else{
					printf("|");
	printf("\n");
				}
				
				
			}
		}}
		return 0;
			
	}	
	
	




