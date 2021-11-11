#include <stdio.h>

int main() {
	
	int M, N, i, j, brojac;
	float mat[100][100];
	
	do {
		printf("Unesite M i N: ");
		scanf("%d%d",&M,&N);
		if(M > 100 || N >100 || M <= 0 || N <= 0) printf("Pogresan unos!\n");
	} while (M > 100 || N > 100 || M <= 0 || N <= 0);
	
	printf("Unesite elemente matrice: ");
		for(i=0; i<M; i++){
			for(j=0; j<N; j++){
				scanf("%d",&mat[i][j]);
			}
		}
		
		brojac = 0;
		for(i=0; i < M-1; i++) if(mat[i][N-1] == mat[i+1][0]) brojac++;
		if(brojac == M-1 && ( M <= 1 || (M > 2 && mat[M-1][N-1] == mat[M-2][N-2]))) {
			printf("Matrica je cirkularna");
			return 0;
		}
		
		for(i=1; i<M; i++)
			for(j=1; j<N; j++) {
				if(mat[i][j] != mat[i-1][j-1]) { j = N  + 1; i = M + 1; }
			}
		if(i == M && j == N) {
			printf("Matrica je Teplicova");
			return 0;
		}
		
		
		
		printf("Matrica nije ni cirkularna ni Teplicova");
	
	
	return 0;
}
