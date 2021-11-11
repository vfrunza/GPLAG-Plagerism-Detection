#include <stdio.h>

int main() {
	
	double A[100][100], B[100][100], Cpom[100][100];
	int i, j, sirina1, visina1, sirina2, visina2;
	
	
	printf("Unesite sirinu i visinu matrice A: ");
	scanf("%d %d", &sirina1, &visina1);
	
	
	printf("Unesite clanove matrice A: ");
	for (i=0; i<visina1; i++) {
		for (j=0; j<sirina1; j++) {
			
			scanf("%lf", &A[i][j]);
		}
	}
	
	printf("Unesite sirinu i visinu matrice B: ");
	scanf("%d %d", &sirina2, &visina2);
	
	printf("Unesite clanove matrice B: ");
	for (i=0; i<visina2; i++) {
		for (j=0; j<sirina2; j++) {
			
			scanf("%lf", &B[i][j]);
		}
	}
	
	for (i=0; i<visina1; i++) {
		for (j=0; j<sirina1; j++) {
		Cpom[j][sirina1-1-i]=A[i][j]; }
	}
	
	for (i=0; i<visina2; i++) {
		for (j=0; j<sirina2; j++) {
			if (Cpom[i][j]!=B[i][j]) {
				printf("NE");
				return 0;
			}
		}
	}
			printf("DA"); 
	return 0;
	
}
