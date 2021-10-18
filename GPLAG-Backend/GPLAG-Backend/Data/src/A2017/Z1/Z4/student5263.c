#include <stdio.h>

int main() {
	int red, kolona, sirina, i, j, k;
	do{
		printf("Unesite broj redova: ");
		scanf("%d", &red);
		}while( red<=0 || red>10);
	
	do{
		printf("Unesite broj kolona: ");
		scanf("%d", &kolona);
	}while( kolona<=0 || kolona>10);
	
	do{
		printf("Unesite sirinu jedne kolone: ");
		scanf("%d", &sirina);
	}while( sirina<=0 || sirina>10);
	
	printf("+");
	for(j=1; j<=kolona; j++){
		for(k=1; k<=sirina; k++)
			printf("-");
		printf("+");
	}
	printf("\n");

	for(i = 1; i<=red; i++){
		/*prvi dio*/
		printf("|");
		for(j=1; j<=kolona; j++){
			for(k=1; k<=sirina; k++)
				printf(" ");
			printf("|");
		}
		printf("\n");	
		/*drugi dio*/
		printf("+");
		for(j=1; j<=kolona; j++){
			for(k=1; k<=sirina; k++)
				printf("-");
			printf("+");
		}
		printf("\n");
	}				
	return 0;
}
