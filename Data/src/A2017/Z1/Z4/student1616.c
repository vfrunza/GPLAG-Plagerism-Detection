#include <stdio.h>

int main() {
	int i, j, m, n, k, br1 = 0, br2 = 0;
	do {
		printf("Unesite broj redova: "); scanf("%d", &n);
	} while ( n < 1 || n > 10 );
	do {
		printf("Unesite broj kolona: "); scanf("%d", &m);
	} while ( m < 1 || n > 10 );
	do {
		printf("Unesite sirinu jedne kolone: "); scanf("%d", &k);
	} while ( k < 1 || k > 10 );
	n = ( (n * 2) + 1 );
	m = ( (m * k) + m + 1);
	for(i = 0; i < n; i++) {
		br1 = 0;
		br2 = 0;
		for(j = 0; j < m; j++) {
			if( ( j == 0 || j == m-1 ) && ( i % 2 == 0 )  ) printf("+");
		    if( (i % 2 == 0) &&  (j > 0) && (j < m-1) ) {
		    	br1++;
		    	if( (br1) == (k + 1) ) { 
		    		printf("+");
		    		br1 = 0;
		    	}
		    	else printf("-");
		    }
		    if ( (j == 0 ||  j == m-1) && (i % 2 != 0) ) printf("|");
		    if( ( i % 2 != 0 ) && ( j > 0 ) && ( j < m-1 ) ) {
		    	br2++;
		    	if(br2 == (k + 1) ) {
		    		printf("|");
		    		br2 = 0;
		    	}
		    	else printf(" ");
		    }
		}
		printf("\n");
	}
	return 0;
}