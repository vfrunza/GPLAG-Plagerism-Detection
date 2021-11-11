#include <stdio.h>

int main() {
	
	int matrica[200][200]={0}, M=0, N=0, i, j, k, w, y, flag;
	
	// unos
	
	do {
		printf ("Unesite brojeve M i N: ");
		scanf("%d %d", &M, &N);
		if (M > 200 || M <= 0 || N > 200 || N <= 0) printf ("Brojevi nisu u trazenom opsegu.\n");
	} while (M > 200 || M <= 0 || N > 200 || N <= 0);
	
	printf ("Unesite elemente matrice: ");
	for (i = 0; i < M; i++) {
		for (j = 0; j < N; j++) {
			scanf ("%d", &matrica[i][j]);
		}
	}
	
	// izbacivanje redova (op. nad M)
	if (M==1) goto point1;

	for (i = 0; i < M; i++) {
		
		for (j = 0; j < M; j++) {
			
			flag = 1; //jednaki su
			
			for (k = 0; k < N; k++) {
				if (matrica[j][k] != matrica [i][k] || i == j) {
					flag = 0; //nisu jednaki
					break;
				}
			}
			
			if (flag == 1) {
				
				if (j == M-1) {
					M--;
					break;
				}
				
				//algoritam za izbacivanje
				for (w = j; w < M-1; w++) {
					for (y = 0; y < N; y++) {
						matrica[w][y] = matrica[w+1][y];
					}
				}
				j--;
				M--;
			}
			
		}
	}


	// izbacivanje kolona (op. nad N)
	if (N==1) goto point2;
	point1:
	
	for (i = 0; i < N; i++) {
		
		for (j = 0; j < N; j++) { //j = i+1
			
			flag = 1;
			
			for (k = 0; k < M; k++) {
				if (matrica[k][j] != matrica [k][i] || i == j) {
					flag = 0;
					break;
				}
			}
			
			if (flag == 1) {
				
				if (j == N-1) {
					N--;
					break;
				}
				
				//algoritam za izbacivanje
				for (w = j; w < N-2; w++) {
					for (y = 0; y < M; y++) {
						matrica[y][w] = matrica[y][w+1+1];
					}
					if (M!=1) j--;
					N--;
					if (M==1) N--;
				}
			}
			
		}
	}
	
	// ispisivanje
	point2:
	
	printf ("Nakon izbacivanja redova/kolona matrica glasi: \n");
	
	for (i = 0; i < M; i++) {
		for (j = 0; j < N; j++) {
			printf ("%5d", matrica[i][j]);
		}
		printf ("\n");
	}
	
	return 0;
}