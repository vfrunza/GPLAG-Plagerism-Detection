#include <stdio.h>

int main() {
	double A[100][100];
	int m, n, teplicova, cirkularna, i, j;
	
	do {
		printf("Unesite M i N: ");
		scanf("%d %d", &m, &n);
		if (n < 1 || n > 100 || m < 1 || m > 100) { printf("Pogresan unos!\n"); }
	} while (n < 1 || n > 100 || m < 1 || m > 100);
	
	printf("Unesite elemente matrice: ");
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			scanf("%lf", &A[i][j]);
		}
	}
	
	/* Teplicova? */
	teplicova = 1;
	/* Od prvog reda */
	for (j = 0; j < n; j++) {
		i = 0;
		while (teplicova && i < m - 1 && i + j < n - 1) {
			if (A[i][i + j] != A[i + 1][i + j + 1]) {
				teplicova = 0;
			}
			i++;
		}
		if (!teplicova) {
			break;
		}
	}
	/* Od prve kolone, bez pocetnog */
	if (teplicova) {
		for (i = 1; i < m - 1; i++) {
			j = 0;
			while (teplicova && j + i < m - 1 && j < n - 1) {
				if (A[j + i][j] != A[j + i + 1][j + 1]) { 
					teplicova = 0;
				}
				j++;
			}
			if (!teplicova) {
				break;
			}
		}
	}
	
	/* Circkularna? */
	cirkularna = 1;
	for (i = 0; i < m - 1; i++) {
		for (j = 0 ; j < n; j++) {
			if (A[i][j] != A[i + 1][(j + 1) % n]) {
				cirkularna = 0;
			}
			if (!cirkularna) {
				break;
			}
		}
		if (!cirkularna) {
			break;
		}
	}
	
	if (cirkularna) {
		printf("Matrica je cirkularna");
	} else if (teplicova) {
		printf("Matrica je Teplicova");
	} else {
		printf("Matrica nije ni cirkularna ni Teplicova");
	}

	return 0;
}

