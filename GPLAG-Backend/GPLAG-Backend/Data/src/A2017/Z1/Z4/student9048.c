#include <stdio.h>


int main() {
	
	int i, j, k, l, m, n, o, red, kolona=0, sirina=0;
	
	/*-----------------------------------*/
	/*        ULAZNI DIO ZADATKA         */
	/*-----------------------------------*/
	
	do {
	
	printf("Unesite broj redova: ");
	scanf("%d", &red);
	
	}while(red<=0 || red>10);
	
	do {
	printf("Unesite broj kolona: ");
	scanf("%d", &kolona);
	
	}while(kolona<=0 || kolona>10);
	
	do{
	printf("Unesite sirinu jedne kolone: ");
	scanf("%d", &sirina);
	
	}while(sirina<=0 || sirina>10);
	
	
	
	/*-----------------------------------*/
	/*          CRTANJE TABELE           */
	/*-----------------------------------*/
	
	/*-----------------------------------*/
	/*             LAJNA #1              */
	/*-----------------------------------*/
	
	
	
	for(n=1; n<=kolona ;n++) {
			printf("+"); 
			
		for(o=1; o<=sirina; o++) {
			printf("-");
		}
		
		}
		printf("+");
		printf("\n");
	
	/*-----------------------------------*/
	/*           TIJELO TABELE           */
	/*-----------------------------------*/
	
	for(i=1; i<=red; i++) {
		
		for(l=1; l<=kolona+1; l++) {
			printf("|");
			
			for(m=1; m<=sirina; m++) {
				printf(" ");
			}
		}
		printf("\n");
		
		
		for(j=1; j<=kolona; j++) {
			printf("+"); 
			
		for(k=1; k<=sirina; k++) {
			printf("-");
		}
		
		}
		printf("+");
		printf("\n");
	}
	
	return 0;
}