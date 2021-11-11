#include <stdio.h>

int main() {
	int mat[200][200];
	int M, N, i, j, k, m, n, checker;
	do{
		printf("Unesite brojeve M i N: "); scanf("%d %d", &M, &N);
		if(M<=0||M>200||N<=0||N>200) printf("Brojevi nisu u trazenom opsegu.\n");
	}while(M<=0||M>200||N<=0||N>200);
	
	printf("Unesite elemente matrice: ");
	for(i=0; i<M; i++){
		for(j=0; j<N; j++){
			scanf("%d",&mat[i][j]);
		}
	}
	/*izbacivanje redova*/
	
	for(i=0; i<M; i++){
		for(k=i+1; k<M; k++){
			checker=1;
			for(j=0; j<N; j++){
				if(mat[i][j]!=mat[k][j]){
					checker=0; break;
				}
			}
			if(checker){
				for(m=k; m<M-1; m++){
					for(n=0; n<N; n++){
						mat[m][n]=mat[m+1][n];
					}
				}
				M--; k--;
			}
		}
	}
	/*izbacivanje kolona analogno kao za izbacivanje redova..................*/
	
	for(j=0; j<N; j++){
		for(k=j+1; k<N; k++){
			checker=1;
			for(i=0; i<M; i++){
				if(mat[i][j]!=mat[i][k]){
					checker=0; break;
				}
			}
			if(checker){
				for(n=k; n<N-1; n++){
					for(m=0; m<M; m++){
						mat[m][n]=mat[m][n+1];
					}
				}
				N--; k--;
			}
		}
	}
	
	printf("Nakon izbacivanja redova/kolona matrica glasi:\n");
	for(i=0; i<M; i++){
		for(j=0; j<N; j++){
			printf("%5d", mat[i][j]);
		}
		printf("\n");
	}
	return 0;
}