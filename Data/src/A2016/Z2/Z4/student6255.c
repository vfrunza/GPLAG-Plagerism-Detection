#include <stdio.h>

int main() {
	int i,j,M,N;
	double mat[100][100];
	do{
		printf("Unesite M i N: ");
		scanf("%d%d",&M,&N);
		if(M>100 || M<=0 || N>100 || N<=0) printf("Pogresan unos!\n");
	} while(M>100 || M<=0 || N>100 || N<=0);
	printf("Unesite elemente matrice: ");
	for(i=0;i<M;i++){
		for(j=0;j<N;j++){
			scanf("%lf",&mat[i][j]);
		}
	}
	for(i=0;i<M-1;i++){
		for(j=0;j<N-1;j++){
			if(mat[i][j]!=mat[i+1][j+1]){
				printf("Matrica nije ni cirkularna ni Teplicova");
				return 0;
			}
		}
	}
	for(i=0;i<M-1;i++){
		if(mat[i+1][0]!=mat[i][N-1]){
			printf("Matrica je Teplicova");
			return 0;
		}
		
	}
	printf("Matrica je cirkularna");
	return 0;
}
