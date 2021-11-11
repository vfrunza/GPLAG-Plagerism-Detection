#include <stdio.h>
#include <stdlib.h>
int main(){
	int i;
	int j;
	int M;
	int N;
	int x = 0;
	int MATRIX[200][200];
	int l = 0;
	int a, b;
	int zamjena;
	do {
		printf("Unesite brojeve M i N: ");
		scanf("%d %d", &M, &N);
		if (M > 200 || M < 1 || N > 200 || N < 1){
			printf("Brojevi nisu u trazenom opsegu.\n");
		}} while(M > 200 || M < 1 || N > 200 || N < 1);
		printf("Unesite elemente matrice: ");
		for(i = 0; i < M; i++){
			for(j = 0; j < N; j++){
			scanf("%d", &MATRIX[i][j]);
		}
	}
	for(i = 0; i < M; i++){
		for (j = i + 1; j < M; j++){
			l = 0;
			for(x = 0; x < N; x++){
				if (MATRIX[i][x] == MATRIX[j][x]){
					l ++;
				}
				if (l == N){
					for(a = j + 1; a < M; a++ ){
						for(b = 0; b < N; b++){
							zamjena = MATRIX[a-1];
							MATRIX[a-1][b] = MATRIX[a][b];
							MATRIX[a][b] = zamjena;
						}
					}
					M --;
					j --;
				}
			}
		}
	}
	for (i = 0; i < N; i++){
		for(j = i +  1; j < N; j++){
			l = 0;
			for(x = 0; x < M; x ++){
				if (MATRIX[x][i] == MATRIX[x][j]){
					l++;
				}
				if(l == M){
					for(a = j+1; a < N; a++){
						for(b = 0; b < M; b++){
							zamjena = MATRIX[b][a-1];
							MATRIX[b][a-1] = MATRIX[b][a];
							MATRIX[b][a] = zamjena;
						}
					}
					N -- ;
					j --;
				}
			}
		}
	}
	printf("Nakon izbacivanja redova/kolona matrica glasi:\n");
	for(i = 0; i < M; i++){
		for (j = 0; j < N; j++){
			printf("%5d", MATRIX[i][j]);
		}
		printf("\n");
	}
	return 0;
	}
	
