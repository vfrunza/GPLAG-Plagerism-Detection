#include <stdio.h>

int main() {
	int n, i, j, a, pom;
	do {
		printf("Unesite broj N: "); scanf("%d", &n);
		if(n % 4 != 0 || n < 8) printf("Neispravno N!\n") ;
	} while ( n % 4 != 0 || n < 8 );
	printf("\n");
	a = n / 4;
	pom = n - a;
	for( i = 0; i < n; i++ ) {
		for( j = 0; j < n; j++ ) {
			if( i < n / 2  && j < n / 2 && i == j ) printf("\\");
			else if( i >= (n / 2)/2  && j < n / 2 && i + j == ( (n/2) - 1)  ) printf("/");
		    else if( i < (n / 2)/2  && j < n / 2 && i + j == ( (n/2) - 1)  ) printf("/");
		    else if( i < n / 2 && j >= n/2 ) {
				if( ( i == 0 || i + 1 == n / 2 ) && (j == n / 2 || j == n - 1 ) ) printf("+");
				else if( ( i == 0 || i + 1 == n / 2 ) && ( j > n / 2 && j < n - 1 ) ) printf("-");
				else if( ( i > 0  && i + 1 < n / 2 ) && (j == n/2 || j == n-1) ) printf("|");
				else printf(" ");
			}
			else if( i >= n / 2 && j < n / 2 ) {
				if( ( i == n/2 || i == n - 1 ) && (j == 0 || j + 1== n / 2  ) ) printf("+");
				else if( ( i == n / 2 || i == n - 1 ) && ( j > 0 && j + 1 < n/2 ) ) printf("-");
				else if( ( i > n / 2  && i  < n -1 ) && (j == 0 || j + 1 == n/2 ) ) printf("|");
				else printf(" ");
			}
			else if( i >= n / 2 && j >= n / 2 ) {
				if( (i==pom && j==pom) || (i + 1 == pom && j == pom) || (i == pom && j + 1 == pom) || (i + 1 == pom && j + 1 == pom) ) printf("+");
				else if( (i == pom-1 && j < pom - 1) || (i == pom-1 && j > pom) ) printf("-");
				else if( (i == pom && j < pom - 1) || (i == pom && j > pom) ) printf("-");
				else if( (j == pom-1 && i < pom - 1) || (j == pom && i < pom - 1) ) printf("|");
				else if( (j == pom-1 && i > pom ) || (j == pom && i > pom ) ) printf("|");
				else printf(" ");
			}
			else printf(" ");
		}
		printf("\n");
	}
	return 0;
}
