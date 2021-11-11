#include <stdio.h>

int main() {
	
	int bred, brkol, sirina, i, j, k, l, m;
	
	do{
		
		printf("Unesite broj redova: ");
		scanf("%d", &bred);
	} while ((bred<=0) || (bred>10));


	do {
		printf("Unesite broj kolona: ");
		scanf("%d", &brkol); 
		
	} while((brkol<=0)||(brkol>10));
		
		
	do {
	
		printf("Unesite sirinu jedne kolone: ");
		scanf("%d", &sirina);
		
	} while ((sirina<=0)||(sirina>10));

	
	for(j = 0; j < bred; j++) {
		
		for (k=0; k<brkol; k++) {
				printf("+");
				for (i=0; i<sirina; i++) {
					printf("-");
				}
		}
		printf("+");
		printf("\n");
		
		for (k=0; k<brkol; k++) {
				printf("|");
				for (i=0; i<sirina; i++) {
					printf(" ");
				}
		}
		printf("|");
		printf("\n");
		
	}


	for (k=0; k<brkol; k++) {
			printf("+");
			for (i=0; i<sirina; i++) {
				printf("-");
			}
	}
	printf("+");
	printf("\n");

	return 0;
	
}