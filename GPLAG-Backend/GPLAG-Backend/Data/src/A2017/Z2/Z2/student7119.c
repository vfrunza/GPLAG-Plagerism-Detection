#include <stdio.h>
int main() {
	int n, a, b, m, sum = 0, br_c = 0, i, j, br_i = 0, br = 1, vel, c, pret = 1, br_null = 0, k = 0;
	int niz_pocetni[100], niz_b[1000], niz_pom[1000], niz_brojaca[9], niz_null[100];
	do {
		printf("Unesite velicinu niza: "); scanf("%d", &vel);
	}
	while ( vel <= 0 || vel > 100 );
	printf("Unesite clanove niza: "); 
	for (i = 0; i < vel; i++) scanf("%d", &niz_pocetni[i]);

	for( i = 0; i < vel; i++ ) {
		n = niz_pocetni[i];
		if ( n == 0 ) br_null++;
		while( n != 0 ) {
			a = n % 10;
			if( a == 0 ) br_null++;
		    sum = a + sum * 10; 
		    n = n / 10; 
	    }
	    niz_pocetni[i] = sum;
	    sum = 0;
	    niz_null[i] = br_null;
	    br_null = 0;
	}
	for(i=0; i<vel; i++) {
		b = niz_pocetni[i];
		while ( b != 0 ) {
			a = b % 10;
			niz_pom[br_c] = a;
			br_c++;
			b = b / 10;
		}
		if( niz_null[i] != 0  && niz_pocetni[i] <= 9 ) {
			m = niz_null[i];
			m = m + br_c;
			for( j = br_c; j < m; j++ ) {
				niz_pom[br_c] = 0;
				br_c++;
			}
		}
	}
	for( i = 0; i < br_c - 1; i++ )
	{
		c = br_c - i;
		if ( niz_pom[i] == niz_pom[i + 1] ) br++;
		else if ( niz_pom[i] != niz_pom[ i + 1  ] ) pret = 0;
		if ( pret == 0  && c != 2 ) {
		    niz_b[br_i] = niz_pom[i];
		    br_i++;
		    niz_b[br_i] = br;
		    br_i++;
		    br = 1;
		    pret = 1;
		}
		if ( pret == 1  && c == 2  ) {
			niz_b[br_i] = niz_pom[i];
			br_i++;
			niz_b[br_i] = br;
			br_i++;
			br = 1;
		}
		if ( pret == 0  && c == 2 ) {
			niz_b[br_i] = niz_pom[i];
			br_i++;
			niz_b[br_i] = br;
			br_i++;
			br = 1;
		}
		if ( c == 2 && pret == 0 && br == 1) {
			niz_b[br_i] = niz_pom[i + 1];
			br_i++;
			niz_b[br_i] = 1;
			br_i++;
		}
	}
	printf("Finalni niz glasi:\n");
	for (i = 0; i < br_i; i++)  printf( "%d ", niz_b[i] );
	return 0;
}