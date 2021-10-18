#include <stdio.h>

int main() {
	int i, j, pom_1, pom_2, pom_3, m, n, br_1 = 0, br_2 = 0, br_3 = 0, pret_1 = 1, pret_2 = 1, pret_3 = 1;
	int matA[100][100], matB[100][100], matC[100][100];
	int niz_sortA[100000], niz_sortB[100000], niz_sortC[100000];
	do {
		printf("Unesite brojeve M i N: "); scanf("%d %d", &m, &n); 
	} while ( ( m < 0 || m > 100 ) || ( n < 0 ||  n > 100 ) );
	printf("Unesite clanove matrice A: ");
	for ( i = 0; i < m; i++ ) {
		for( j = 0; j < n; j++ ) scanf("%d", &matA[i][j]);
	}
	
	for( i=0; i < m; i++ ) {
		for( j = 0; j < n; j++ ) {
			niz_sortA[br_1] = matA[i][j];
			br_1++;
		}
	}
	
	for( i=0; i < br_1; i++ ) {
		for( j = 0; j < br_1; j++ ) {
			if( niz_sortA[i] < niz_sortA[j] ) {
				pom_1 = niz_sortA[j];
				niz_sortA[j] = niz_sortA[i];
				niz_sortA[i] = pom_1;
			}
		}
	}
	printf("Unesite clanove matrice B: ");
	for ( i = 0; i < m; i++ ) {
		for( j = 0; j < n; j++ ) scanf("%d", &matB[i][j]);
	}
	
	for( i = 0; i < m; i++ ) {
		for( j = 0; j < n; j++ ) {
			niz_sortB[br_2] = matB[i][j];
			br_2++;
		}
	}
	
	for( i = 0; i < br_2; i++ ) {
		for( j = 0; j < br_2; j++ ) {
			if( niz_sortB[i] < niz_sortB[j] ) {
				pom_2 = niz_sortB[j];
				niz_sortB[j] = niz_sortB[i];
				niz_sortB[i] = pom_2;
			}
		}
	}
	printf("Unesite clanove matrice C: ");
	for ( i = 0; i < m; i++ ) {
		for( j = 0; j < n; j++ ) scanf("%d", &matC[i][j]);
	}
	
	for( i = 0; i < m; i++ ) {
		for( j = 0; j < n; j++ ) {
			niz_sortC[br_3] = matC[i][j];
			br_3++;
		}
	}
	
	for( i = 0; i < br_3; i++ ) {
		for( j = 0; j < br_3; j++ ) {
			if( niz_sortC[i] < niz_sortC[j] ) {
				pom_3 = niz_sortC[j];
				niz_sortC[j] = niz_sortC[i];
				niz_sortC[i] = pom_3;
			}
		}
	}
	for( i = 0; i < br_1; i++ ) {
		if( niz_sortA[i] != niz_sortC[i] ) pret_1 = 0;
		if( niz_sortB[i] != niz_sortC[i] ) pret_2 = 0;
	}
	if( pret_1 == 1 && pret_2 == 1 ) printf("DA");
	else if( pret_1 == 0 || pret_2 == 0 ) printf("NE");
	return 0;
}