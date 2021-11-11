#include <stdio.h>

int main() {
	int M,N,i,j,k,ok,l;
	int mat[200][200];
	do{
		printf("Unesite brojeve M i N: ");
		scanf("%d %d", &M, &N);
		if(M <= 0 || M > 200 || N <=0 || N > 200) printf("Brojevi nisu u trazenom opsegu.\n");
	} while(M <= 0 || M > 200 || N <=0 || N > 200);
	printf("Unesite elemente matrice: ");
	for(i = 0; i < M; i++) {
		for(j = 0; j < N; j++) {
			scanf("%d", &mat[i][j]);
		}
	}
	
	for(i = 0; i < M - 1; i++) {
		for(j = i + 1; j < M; j++) {
			if(mat[i][0] == mat[j][0]) {
				//printf("I = %d, J = %d, i = %d, j=%d\n", mat[i][0], mat[j][0], i, j);
				
				for(k = 0; k < N; k++) {
					ok = 1;
					if(mat[i][k] != mat[j][k]){
						ok = 0;
						//printf("ok=%d, i =%d, j=%d, k=%d\n",ok,i,j,k);
						break;
					}
				}
				//printf("ok=%d, j=%d\n",ok,j);
				if(ok == 1){
				//printf("j = %d, i= %d\n",j,i);
				for(k = j; k < M; k++) {
					for(l = 0; l < N; l++) {
						mat[k][l] = mat[k + 1][l];
					}
				}
				M--;
				j--;
			}
			
			} 
		}
		
	}
	
	for(i = 0; i < N - 1; i++) {
		for(j = i + 1; j < N; j++) {
			if(mat[0][i] == mat[0][j]) {
				for(k = 0; k < M; k++) {
					ok = 1;
					if(mat[k][i] != mat[k][j]) {
						ok = 0;
						break;
					}
				}
				if(ok == 1) {
					for(k = j; k < N; k++) {
						for(l = 0; l < M; l++) {
							mat[l][k] = mat[l + 1][k];
						}
					}
					N--;
					j--;
				}
			}
		}
	}
	
	printf("Nakon izbacivanja redova/kolona matrica glasi:\n");
	for(i = 0; i < M; i++) {
		for(j = 0; j < N; j++) {
			printf("%5d",mat[i][j]);
		}
		printf("\n");
	}
	return 0;
}
