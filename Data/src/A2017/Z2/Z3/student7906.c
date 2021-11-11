#include <stdio.h>

int main() {
	int matA[100][100], matB[100][100], sA, vA, sB, vB, i, j, transA[100][100];
	
	/* unos matrica */
	
	printf("Unesite sirinu i visinu matrice A: ");
	scanf("%d %d", &sA, &vA);
	printf("Unesite clanove matrice A: ");
	for(i=0; i<vA; i++) {
		for(j=0; j<sA; j++) {
			scanf("%d", &matA[i][j]);
		}
	}
	
	printf("Unesite sirinu i visinu matrice B: ");
	scanf("%d %d", &sB, &vB);
	printf("Unesite clanove matrice B: ");
	for(i=0; i<vB; i++) {
		for(j=0; j<sB; j++) {
			scanf("%d", &matB[i][j]);
		}
	}
	
	/* uslov za transponovanje i rotaciju */
	/* matrica se prvo transponuje pa se zamijeni redoslijed kolona sto daje rotiranu matricu za 90 stepeni */
	
	if(vB!=sA || sB!=vA) {
    printf("NE\n"); 
		return 0;
	}
    else {
	for(i=0; i<sA; i++) {
		for(j=0; j<vA; j++) {
			transA[i][j]=matA[j][i];
		}
	}
	
	for(i=0; i<sA; i++) {
		for(j=0; j<vA; j++) {
	 	if (transA[i][vA - 1 - j] != matB[i][j]) {  
	 			printf("NE\n");
                return 0;
	 			}
            }
        }
    }
	printf("DA\n");

	return 0;
}
