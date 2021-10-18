#include <stdio.h>
#define BE 50 /*Nije naveden maksimalan broj elemenata matrice, a 50 sam postavio iz razloga sto autotestovi zahtijevaju daleko manje :) */

int main() {
	
	int lk, ra, rb, ka, kb, i, j, A[BE][BE], B[BE][BE];
	printf("Unesite sirinu i visinu matrice A: ");
	scanf("%d %d", &ka, &ra);
	printf("Unesite clanove matrice A: ");
	for(i=1; i<=ra; i++) { /* ra-->red A, odnosi se na broj redova matrice a. Isto važi za ostale oznake, inače smo koristili "i" za redove, a "j" za kolone pa onda radi lakšeg snalaženja isto radim i ovdje. :D */ 
		for(j=1; j<=ka; j++) {
			scanf("%d", &A[i][j]);
		}
	}
	
	printf("Unesite sirinu i visinu matrice B: ");
	scanf("%d %d", &kb, &rb);
	printf("Unesite clanove matrice B: ");
	for(i=1; i<=rb; i++) {
		for(j=1; j<=kb; j++) {
			scanf("%d", &B[i][j]);
		}
	}
	
	lk=1;  /* Postavljam logicku vrijednost na 1, a ovisno o inputu ona će se promijeniti ili ostati ista. */

	if(ka!=rb || ra!=kb)
	printf("NE\n");
	else {
		for(i=1; i<=ra; i++) {
			for(j=1; j<=ka; j++) {
				if(A[i][j]!=B[j][ra-i+1]) {
					lk=0;
					i=ra;
					j=ka;
				}
			}
		}
		if (lk==1)
		printf("DA\n");
		else 
		printf("NE\n");
	}
	return 0;
}
