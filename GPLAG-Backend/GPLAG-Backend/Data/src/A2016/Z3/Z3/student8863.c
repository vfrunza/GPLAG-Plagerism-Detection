#include <stdio.h>

int main() {
	int mat[200][200], M, N, i, j, k, isti=1;
	do{
		printf("Unesite brojeve M i N: ");
		scanf("%d %d", &M, &N);
		if(M<1 || M>200 || N<1 || N>200)
			printf("Brojevi nisu u trazenom opsegu.\n");
	}while(M<1 || M>200 || N<1 || N>200);
	printf("Unesite elemente matrice: ");
	for(i=0; i<M; i++){
		for(j=0; j<N; j++){
			scanf("%d", &mat[i][j]);
		}
	}
	if(N==1){
		for(i=0; i<M; i++){
			for(j=i+1; j<M; j++){
				if(mat[i][0]==mat[j][0]){
					for(k=j; k<M; k++)
					mat[k][0]=mat[k+1][0];
					M--;
					j--;
				}
					
			}

		}
	}
	else{
		for(i=0; i<M; i++){
			for(j=i+1; j<M; j++){
				for(k=0; k<N; k++){
					if(mat[i][k]!=mat[j][k]){
						isti=0;
						break;
					}
				}
				if(isti==1){
					for(k=0; k<N; k++){
						mat[j][k]=mat[j+1][k];
					}
					M--;
					j--;
				}
				isti=1;
			}
		}
	}
	isti=1;
	if(M==1){
		for(i=0; i<N; i++){
			for(j=i+1; j<N; j++){
				if(mat[0][i]==mat[0][j]){
					for(k=j; k<N; k++)
					mat[0][k]=mat[0][k+1];
					N--;
					j--;
				}
					
			}

		}
	}
	else{
		for(k=0; k<N; k++){
			for(j=k+1; j<N; j++){
				for(i=0; i<M; i++){
					if(mat[i][k]!=mat[i][j]){
						isti=0;
						break;
					}
				}
				if(isti==1){
					for(k=0; k<N; k++){
						mat[i][j]=mat[i][j+1];
					}
					N--;
					j--;
				}
				isti=1;
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
