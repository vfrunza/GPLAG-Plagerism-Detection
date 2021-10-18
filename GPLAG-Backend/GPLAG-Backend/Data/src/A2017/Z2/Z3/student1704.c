#include <stdio.h>

int main() {
	float matA[100][100], matB[100][100];
	int Ai, Aj, Bi, Bj, i, j;
	
	printf("Unesite sirinu i visinu matrice A: ");
	scanf("%d %d", &Aj, &Ai);
	
	printf("Unesite clanove matrice A: ");
	for(i=0; i<Ai; i++) {
		for(j=0; j<Aj; j++) {
			scanf("%f", &matA[i][j]);
		}
	}
	
	printf("Unesite sirinu i visinu matrice B: ");
	scanf("%d %d", &Bj, &Bi);
	
	printf("Unesite clanove matrice B: ");
	for(i=0; i<Bi; i++) {
		for(j=0; j<Bj; j++) {
			scanf("%f", &matB[i][j]);
		}
	}
	
	if(Ai!=Bj || Aj!=Bi) {
		printf("NE\n");
		return 0;
	}
	
	
	for(i=0; i<Ai; i++) {
		for(j=0; j<Aj; j++) {
			if(matA[i][j]!=matB[j][Bj-i-1]) {
				printf("NE\n");
				return 0;
			}
		}
	}
	printf("DA\n");
	
	return 0;
}
