#include <stdio.h>

int main() {
	int red, kolona, sirina, i, k, p, r, t;
	
	do{
		printf("Unesite broj redova: ");
		scanf("%d", &red);
	}while(red<=0 || red>10);
	
	do{
		printf("Unesite broj kolona: ");
		scanf("%d", &kolona);
	}while(kolona<=0 || kolona>10);
	
	do{
		printf("Unesite sirinu jedne kolone: ");
		scanf("%d", &sirina);
	}while(sirina<=0 || sirina>10);
	
	for(i=0; i<red; i++){
		
			for(k=0; k<kolona; k++){
				printf("+");
				for(p=0; p<sirina; p++){
					printf("-");
				}
			}
			
			printf("+");
			printf("\n");
			
				for(r=0; r<kolona; r++){
					printf("|");
					for(t=0; t<sirina; t++){
						printf(" ");
					}
				}
				
			printf("|");
				printf("\n");
	}
	
	for(k=0; k<kolona; k++){
				printf("+");
				for(p=0; p<sirina; p++){
					printf("-");
				}
			}
			
			printf("+");
			printf("\n");
return 0;	
}
