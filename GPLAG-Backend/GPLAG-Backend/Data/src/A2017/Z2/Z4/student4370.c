#include <stdio.h>

#define MAX_DIM 100

int main() {
	int m, n;
	int matA[MAX_DIM][MAX_DIM], matB[MAX_DIM][MAX_DIM], matC[MAX_DIM][MAX_DIM];
	int trenutniElement, brojNulaA = 0, brojNulaB = 0, brojNulaC = 0, nadjenElement = 0;
	int i, j, k, l;
	
	do {
		printf("Unesite brojeve M i N: ");
		scanf("%d %d", &m, &n);
	} while (m < 0 || n < 0 || n > 100 || m > 100);
	
	printf("Unesite clanove matrice A: ");
	for (i = 0; i < m; i++)
		for (j = 0; j < n; j++)
			scanf("%d", &matA[i][j]);
	
	printf("Unesite clanove matrice B: ");
	for (i = 0; i < m; i++)
		for (j = 0; j < n; j++)
			scanf("%d", &matB[i][j]);
			
	printf("Unesite clanove matrice C: ");
	for (i = 0; i < m; i++)
		for (j = 0; j < n; j++)
			scanf("%d", &matC[i][j]);
	
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			if (matA[i][j] == 0)
				brojNulaA += 1;
			if (matB[i][j] == 0)
				brojNulaB += 1;
			if (matC[i][j] == 0)
				brojNulaC += 1;
		}
	}
	
	if (brojNulaA != brojNulaB || brojNulaA != brojNulaC) {
		printf("NE");
		return 0;
	}
	
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			if (matA[i][j] == 0)
				continue;
				
			trenutniElement = matA[i][j];
			
			nadjenElement = 0;
			
			for (k = 0; k < m && !nadjenElement; k++) {
				for (l = 0; l < n && !nadjenElement; l++) {
					if (matB[k][l] == trenutniElement) {
						matB[k][l] = 0;
						nadjenElement = 1;
					}
				}
			}
			
			if (!nadjenElement) {
				printf("NE");
				return 0;
			}
			
			nadjenElement = 0;
			
			for (k = 0; k < m && !nadjenElement; k++) {
				for (l = 0; l < n && !nadjenElement; l++) {
					if (matC[k][l] == trenutniElement) {
						matC[k][l] = 0;
						nadjenElement = 1;
					}
				}
			}
			
			if (!nadjenElement) {
				printf("NE");
				return 0;
			}
			
			matA[i][j] = 0;
		}
	}
	
	printf("DA");
	
	return 0;
}
