#include <stdio.h>

int main() {
	int M, N;
	
	do {
		printf("Unesite brojeve M i N: ");
		scanf("%d %d", &M, &N);
		
		if(M <= 0 || M > 200 || N <= 0 || N > 200) {
			printf("Brojevi nisu u trazenom opsegu. \n");
		}
		
	}
	while(M<=0 || M>200 || N<=0 || N>200);
	
	int matrix[200][200];
	
	int i, j;
	
	printf("Unesite elemente matrice: ");
	for(i = 0; i < M; i++) {
		for(j = 0; j < N; j++) {
			
			scanf("%d", &matrix[i][j]);
		}
	}
	for(i = 0; i < M; i++) {
		for(j = 0; j < M; j++) {
			if(i != j) {
				int k, daLiSuIsti = 1;
				for(k = 0; k < N; k++) {
					if(matrix[i][k] != matrix[j][k]) {
						
						daLiSuIsti = 0;
						break;
					}
				}
				if(daLiSuIsti == 1){
					int l;
					for(l = j; l < M - 1; l++) {
						for(k = 0; k < N; k++) {
							matrix[l][k] = matrix[l + 1][k];
						}
					}
					M--;
					j--;
				}
			}
		}
	}
	for(i = 0; i < N; i++) {
		for(j = 0; j < N; j++) {
			if(i != j) {
				int k, daLiSuIsti = 1;
				for(k = 0; k < M; k++) {
					if(matrix[k][i] != matrix[k][j])  {
						daLiSuIsti = 0;
						break;
					}
				}
				if(daLiSuIsti == 1) {
					int l;
					for(l = j; l < N - 1; l++){
						for(k = 0; k < M; k++){
							matrix[k][l] = matrix[k][l+1];
						}
					}
					N--;
					j--;
				}
			}
		}
	}
	printf("Nakon izbacivanja redova/kolona matrica glasi: \n");
	for(i = 0; i < M; i++) {
		for(j = 0; j < N; j++) {
			printf("%5d", matrix[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}	
