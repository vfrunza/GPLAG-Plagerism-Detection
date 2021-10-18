#include <stdio.h>

int main() {
	
	int i, j, m1, n1, m2, n2, temp, b;
	int matA[100][100], matB[100][100];
	
	printf("Unesite sirinu i visinu matrice A: ");
	scanf("%d %d", &m1, &n1);
	
	printf("Unesite clanove matrice A: ");
	for(i=0; i<m1; i++){
		for(j=0; j<n1; j++)
		scanf("%d", &matA[i][j]);
	}
	
	printf("Unesite sirinu i visinu matrice B: ");
	scanf("%d %d", &m2, &n2);
	
	printf("Unesite clanove matrice B: ");
	for(i=0; i<m2; i++){
		for(j=0; j<n2; j++)
		scanf("%d", &matB[i][j]);
	}
	
	
	
	return 0;
}
