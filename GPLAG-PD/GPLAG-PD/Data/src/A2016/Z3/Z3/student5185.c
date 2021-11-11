#include <stdio.h>
#define gornjiLimit 200
#define donjiLimit 0

int main() {
	int M, N, brojac, matrica[gornjiLimit][gornjiLimit], i, j, k, l, istinitost, brojac1, brojac2;
	
	brojac = 0;
	istinitost = 0;

	do{
	if (brojac != 0)
	{
		printf("Brojevi nisu u trazenom opsegu.\n");
	}
		
	printf("Unesite brojeve M i N: ");
	scanf ("%d %d", &M, &N);
	brojac++;
	} while ((M <= donjiLimit || M > gornjiLimit)||(N <= donjiLimit || N > gornjiLimit));
	
	brojac1 = M;
	brojac2 = N;
	
	printf("Unesite elemente matrice: ");
	
	for (i = 0; i < M; i++){
		for(j = 0; j < N; j++){
			scanf("%d", &matrica[i][j]);
		}
	}

	for (k = 0; k < M-1; k++){
		for (i = k+1; i < M; i++){
			for(j = 0; j < N; j++){
				if (matrica[k][j] == matrica[i][j]){
					istinitost = 1;
				}
				else if (matrica[k][j] != matrica[i][j]){
					istinitost = 0;
					break;
				}
			}
			
			if (istinitost == 1){
				/*Izbaciti red*/
				
				if (i+1 == M){
					brojac1 = brojac1 - 1; 
				}
				
				else if (i+1 != M){
					for (j = 0; j < N; j++){
						for(l = i; l < M-1; l++){
							matrica[l][j] = matrica[l+1][j];
					}}
				}
			}
		}
	}
	
	for (k = 0; k < N-1; k++){
		for (i = k+1; i < N; i++){
			for(j = 0; j < M; j++){
				if (matrica[j][k] == matrica[j][i]){
					istinitost = 1;
				}
				else if (matrica[j][k] != matrica[j][i]){
					istinitost = 0;
					break;
				}
			}
			
			if (istinitost == 1){
				/*Izbaciti kolonu*/
			
				if (i+1 == N){
					brojac2 = brojac2 - 1; 
				}
				
				else if (i+1 != N){
					for (j = 0; j < M; j++){
						for(l = i; l < N-1; l++){
							matrica[j][l] = matrica[j][l+1];
						}
					}
				}
			}
		}
	}

	
	printf("Nakon izbacivanja redova/kolona matrica glasi:\n");  
	for (i = 0; i < brojac1; i++){
		for(j = 0; j < brojac2; j++){
			if (j==0) {
				printf("%5d", matrica[i][j]);
			}
			else if (j != 0)  {  
				printf("%5d", matrica[i][j]);
			}
		}
		printf("\n");
	}
	
	return 0;
}
