#include <stdio.h>

int main() {
	int sirina1, visina1, sirina2, visina2, br = 1, pret = 1, i, j;
	int matA[100][100], matB[100][100];
	printf("Unesite sirinu i visinu matrice A: "); scanf("%d %d", &sirina1, &visina1 );
	printf("Unesite clanove matrice A: ");
	for(i=0; i<visina1; i++) {
		for (j = 0; j < sirina1; j++) scanf( "%d", &matA[i][j] );
	}
	printf("Unesite sirinu i visinu matrice B: "); scanf("%d %d", &sirina2, &visina2 );
	printf("Unesite clanove matrice B: ");
	for(i=0; i<visina2; i++) {
		for (j = 0; j < sirina2; j++) scanf( "%d", &matB[i][j] );
	}
	if( sirina1 == visina2 && visina1 == sirina2 ) {
	for ( i = 0; i < visina1; i++ ) {
		for( j = 0; j < sirina1; j++ ) {
			if( matA[i][j] != matB[j][visina1-br] ) pret = 0;
		}
		br++;
	}
	br = 0;
	if( pret == 0 ) printf("NE");
	else printf("DA");
	} else printf("NE");
	return 0;
}
