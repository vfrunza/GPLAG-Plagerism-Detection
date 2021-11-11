#include <stdio.h>

int main() {
	int sirinaA, sirinaB, visinaA, visinaB, i, j, da=0, matA[100][100], matB[100][100];
	
	printf("Unesite sirinu i visinu matrice A: ");
	scanf("%d %d", &sirinaA, &visinaA);
	printf("Unesite clanove matrice A: ");
	for (i = 0; i < visinaA; i++) {
		for (j = 0; j < sirinaA; j++) {
			scanf("%d", &matA[i][j]);
		}
	}
	
	printf("Unesite sirinu i visinu matrice B: ");
	scanf("%d %d", &sirinaB, &visinaB);
	printf("Unesite clanove matrice B: ");
	for (i = 0; i < visinaB; i++) {
		for (j = 0; j < sirinaB; j++) {
			scanf("%d", &matB[i][j]);
		}
	}
		if (visinaA==sirinaB && sirinaA==visinaB) {
			da=1;
			for(i = 0; i < visinaA&&da; i++) { 
				for(j = 0; j < sirinaA&&da; j++) {
					if(matA[i][j]!=matB[j][sirinaB-i-1]){
						da=0;
					}
				}
			}
		}
	if (da) printf("DA\n"); 
	else printf("NE\n");
	return 0;
}