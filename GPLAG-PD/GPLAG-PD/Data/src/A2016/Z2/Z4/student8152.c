#include <stdio.h>
#include <stdlib.h>

int main() {
	
	int m, n, i, j, teplicova, cirkularna, zaProvjeruCirkularne;
	double mat[100][100] = {0};
	
	while(1) {
	printf("Unesite M i N: ");
	
	do {
		scanf("%d", &m);
		
	} while(0);
	
	do {
		scanf("%d", &n);
		
	} while(0);
	
	if(m <= 100 && m > 0 && n <= 100 && n > 0) break;
	else printf("Pogresan unos!\n");
	
	}
	
	zaProvjeruCirkularne = abs(m - n);
	
	printf("Unesite elemente matrice: ");
	
	for(i = 0; i < m; i++) {
		
		for(j = 0; j < n; j++) {
			
			scanf("%lf", &mat[i][j]);
		}
	}
	
	teplicova = 1;
	cirkularna = 1;
	for(i = 0; i < m - 1; i++) {
		
		if(mat[i][n - 1] != mat[i + 1][0] || mat[0][zaProvjeruCirkularne] != mat[m - 1][n - 1])  cirkularna = 0;
		
		for(j = 0; j < n - 1; j++) {
			
			if(mat[i][j] != mat[i + 1][j + 1]) {
				
				teplicova = 0;
				
			}
			
		}
	}
	if(cirkularna) {
		
		printf("Matrica je cirkularna");
	}
	
	else if(teplicova) {
		
		printf("Matrica je Teplicova");
	}
	else printf("Matrica nije ni cirkularna ni Teplicova");
	return 0;
}
