#include <stdio.h>

int main() {
	int mat[200][200];
	int M, N, i, j, k, p;
	i=0;
	do{
		if(i!=0){
			printf("Brojevi nisu u trazenom opsegu.\n");
		}	
		i++;
		printf("Unesite brojeve M i N: ");
		scanf("%d %d", &M, &N);
	}
	while(M<=0 || M>200 || N<=0 || N>200);
	printf("Unesite elemente matrice: ");
	for(i=0; i<M; i++){
		for(j=0; j<N; j++){
			scanf("%d", &mat[i][j]);
		}
	}
	//kada je broj kolona veci od 1
	if(N != 1 && M !=1) {
	for(i=0; i<M; i++){
		for(j=i+1; j<M; j++){
			int uslov=1;
			for(k=0; k<N; k++){
				if(mat[i][k] != mat[j][k]){
					uslov=0;
				}
			}
			if(uslov==1){
				for(k=j; k<M-1; k++){
					for(p=0; p<N; p++){
						mat[k][p]=mat[k+1][p];
					}
				}
				M--;
				i--;
			}
		}
	}
	
	
	for(i=0; i<N; i++){
		for(j=i+1; j<N; j++){
			int uslov=1;
			for(k=0; k<M; k++){
				if(mat[k][i]!=mat[k][j]){
					uslov=0;
				}
			}
			if(uslov==1){
				for(k=j; k<N-1; k++){
					for(p=0; p<M; p++){
						mat[p][k]=mat[p][k+1];
					}
				}
				N--;
				j--;
			}
		}
	}
	
		
	}
	//kada je broj kolona jednak 1,a broj redova veci od 1
	else if(N == 1 && M != 1) {
	
	for(i=0; i<M; i++){
		for(j=i+1; j<M; j++){
			int uslov=1;
			for(k=0; k<N; k++){
				if(mat[i][k]!=mat[j][k]){
					uslov=0;
				}
			}
			if(uslov==1){
				for(k=j; k<M-1; k++){
					for(p=0; p<N; p++){
						mat[k][p]=mat[k+1][p];
					}
				}
				M--;
				i--;
			}
		}
	}
	
	}
	
	else if(N != 1 && M == 1) {
	
	for(i=0; i<N; i++){
		for(j=i+1; j<N; j++){
			int uslov=1;
			for(k=0; k<M; k++){
				if(mat[k][i]!=mat[k][j]){
					uslov=0;
				}
			}
			if(uslov==1){
				for(k=j; k<N-1; k++){
					for(p=0; p<M; p++){
						mat[p][k]=mat[p][k+1];
					}
				}
				N--;
				j--;
			}
		}
	}
	
	}
	
	printf("Nakon izbacivanja redova/kolona matrica glasi: \n");
	for(i=0; i<M; i++){
		for(j=0; j<N; j++){
			printf("%5d", mat[i][j]);
		}
		printf("\n");
	}
	return 0;
}
