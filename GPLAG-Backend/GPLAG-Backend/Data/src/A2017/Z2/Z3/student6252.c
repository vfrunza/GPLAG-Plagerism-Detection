#include <stdio.h>

int main() {
	
	int i=0, j=0, i1=0, i2=0, j1=0, j2=0, matA[100][100], matB[100][100],ai=0,aj=0,bi=0,bj=0;
	
	printf ("Unesite sirinu i visinu matrice A: ");
	scanf ("%d %d", &i1, &j1);
	printf ("Unesite clanove matrice A: ");
	for (i = 0; i < i1; i++) {
		for (j = 0; j < j1; j++) {
		scanf ("%d", &matA[ai][aj]);
		}
	}
	
	printf ("Unesite sirinu i visinu matrice B: ");
	scanf ("%d %d", &i2, &j2);
	printf ("Unesite clanove matrice B: ");
	for (i = 0; i < i2; i++) {
		for (j = 0; j < j2; j++) {
			scanf ("%d", &matB[bi][bj]);
		}
	}
	
	for (i = 0; i < i1; i++) {
		for (j = 0; j < j1; j++) {
			if (matB[bi][bj]=matA[bj][i1-ai]) {
				printf ("DA\n");
			} else printf ("NE\n");
		}
	}
	return 0;
}
