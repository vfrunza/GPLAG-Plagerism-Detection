#include <stdio.h>


int main() {
	int m, n, i, j, mat[200][200], k, isti, l;
	
	do {
		printf("Unesite brojeve M i N: ");
		scanf("%d %d", &m, &n);
		if (m < 1 || n < 1 || m > 200 || n > 200) {
			printf("Brojevi nisu u trazenom opsegu.\n");
		}
	} while (m < 1 || n < 1 || m > 200 || n > 200);
	
	printf("Unesite elemente matrice: ");
	
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			scanf("%d", &mat[i][j]);
		}
	}
	
	for (i = 0; i < m-1; i++) {
		for (j = i+1; j < m; j++) {
			isti = 1;
			for (k = 0; k < n; k++) {
				if (mat[i][k] != mat[j][k]) {
					isti = 0;
					break;
				}
			}
			if (isti == 1) {
				for (l = j; l < m-1; l++) {
					for (k = 0; k < n; k++) {
						mat[l][k] = mat[l+1][k];
					}
				}
				m--;
				j--;
			}
		}
	}
	for (i = 0; i < n-1; i++) {
		for (j = i+1; j < n; j++) {
			isti = 1;
			for (k = 0; k < m; k++) {
				if (mat[k][i] != mat[k][j]) {
					isti = 0;
					break;
				}
			}
			if (isti == 1) {
				for (l = j; l < n-1; l++) {
					for (k = 0; k < m; k++) {
						mat[k][l] = mat[k][l+1];
					}
				}
				n--;
				j--;
			}
		}
	}
	printf("Nakon izbacivanja redova/kolona matrica glasi:\n");
	
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			printf("%5d", mat[i][j]);
		}
		printf("\n");
	}
	return 0;
}
