#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int izbaci_cifre( int *nizA, int velA, int *nizB, int velB ) {
    int i, j, z, k, h, o, l, s, n, m, a, sum = 0, br = 0, sum_niz = 0;
    int niz[20];
    int provjera = 1, desilo_se = 0, negtivan_je;
    for (l = 0; l < velB; l++) {
        if( nizB[l] < 0 || nizB[l] > 9 ) provjera = 0;
        for ( s = l + 1; s < velB - 1; s++ ) {
            if ( nizB[l] == nizB[s] ) provjera = 0;
        }
    }
    if( provjera == 1 ) {
        for( i = 0; i < velB; i++ ) {
            m = nizB[i];
            for( j = 0; j < velA; j++ ) {
                if( nizA[i] < 0 ) {
                    n = abs( nizA[j] );
                    negtivan_je = 1;
                } else { n = nizA[j]; }
                while( n != 0 ) {
                    a = n % 10;
                    sum =  a + sum * 10;
                    n = n / 10;
                }
                while( sum != 0 ) {
                    a = sum % 10;
                    niz[br] = a;
                    br++;
                    sum = sum / 10;
                }
                for( k = 0; k < br; k++ ) {
                    if( m == niz[k] ) {
                        for( z = k; z < br - 1; z++ ) niz[z] = niz[z + 1];
                        br --;
                        k--;
                        desilo_se = 1;
                    }
                }
                for( h = 0; h < br; h++ ) sum_niz = sum_niz * 10 + niz[h];
                if(negtivan_je == 1) {
                    nizA[j] = ( sum_niz * (-1) ) ;
                }
                if( negtivan_je == 0 ) nizA[j] = sum_niz;
                br = 0;
                sum = 0;
                sum_niz = 0;
                negtivan_je = 0;
            }  
        }
    }
    if( (desilo_se == 1 || desilo_se == 0) && provjera == 1 ) return desilo_se;
    if( provjera == 0  ) return provjera; 
}

int main() {
    int i, velA, velB, m;
    int nizA[100], nizB[100];
    printf("Unesite velicinu niza A: "); scanf("%d", &velA);
	printf("Unesi niz A: ");
	for (i = 0; i < velA; i++) scanf( "%d", &nizA[i] );
	printf("Unesite velicinu niza B: "); scanf("%d", &velB);
	printf("Unesi niz B: ");
	for (i = 0; i < velB; i++) scanf( "%d", &nizB[i] );
	m = izbaci_cifre( nizA, velA, nizB, velB );
	for ( i = 0; i < velA; i++ ) printf( "%d ", nizA[i] );
	printf("\n %d", m);
	return 0;
}