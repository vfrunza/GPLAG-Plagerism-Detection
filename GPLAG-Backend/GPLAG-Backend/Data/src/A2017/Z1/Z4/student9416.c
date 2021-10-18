#include <stdio.h>

int main() {
	int br_redova, br_kolona, sirina_kolone,i,j,k;
	do{
	printf("Unesite broj redova: ");
	scanf("%d", &br_redova);
	}while(br_redova<=0 || br_redova>10);
	
	do{
		printf("Unesite broj kolona: ");
		scanf("%d", &br_kolona);
	}while(br_kolona<=0||br_kolona>10);
	
	do{
		printf("Unesite sirinu jedne kolone: ");
		scanf("%d", &sirina_kolone);
	}while(sirina_kolone<=0||sirina_kolone>10);
	
	for(i=0; i<br_redova; i++){
		for(j=0; j<br_kolona; j++){
			printf("+");
			for(k=0; k<sirina_kolone; k++){
				printf("-");
			}
		
		} printf("+");
		printf("\n");
		
		for(j=0; j<br_kolona;j++){
			printf("|");
			for(k=0; k<sirina_kolone;k++){
				printf(" ");
			}
		
		} printf("|");
			printf("\n");
	}
	
	for(j=0; j<br_kolona; j++){
		printf("+");
		for(k=0; k<sirina_kolone;k++){
			printf("-");
		}
	}printf("+");
	return 0;
}
