#include <stdio.h>

int main() {
	int i=0, j=0, k=0, R=0, C=0, S=0;
	do{
	printf("Unesite broj redova: ");
	scanf ("%d", &R);
	}
	while (R<=0 || R>10);
	do {
		printf("Unesite broj kolona: ");
		scanf ("%d", &C);
	}
	while (C<=0 || C>10);
	do {
		printf("Unesite sirinu jedne kolone: ");
		scanf("%d", &S);
		
	}
	while (S<=0 || S>10);
	
	     for (i=0; i<R; i++){
		  for (j=0; j<C; j++) {
		  	printf ("+");
		  for (k=0;k<S; k++) {
		  	printf ("-");
		  	
		  }
		  }
		
		  printf("+");
		  printf("\n");
		
		
	     
			for (j=0; j<C; j++){
				printf ("|");
			for (k=0; k<S; k++){
				printf(" ");
			}
		}
			printf("|");
			printf("\n");
		
	     }
		
			for (j=0; j<C; j++){
				printf("+");
				for (k=0; k<S; k++){
				printf ("-");
			}
			}
			printf("+");
		
	return 0;
}
