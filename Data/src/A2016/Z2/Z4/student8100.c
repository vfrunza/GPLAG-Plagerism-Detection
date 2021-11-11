#include <stdio.h>

int main() {
	int M, N, i, j, t=1, c=1;
	double mat[100][100];
	do{
		printf("Unesite M i N: ");
		scanf("%d %d", &M, &N);
		if(M<=0 || M>100 || N<=0 || N>100) printf("Pogresan unos!\n");
	}while(M<=0 || M>100 || N<=0 || N>100);
	printf("Unesite elemente matrice: ");
	for(i=0; i<M; i++)
		for(j=0; j<N; j++)
			scanf("%lf", &mat[i][j]);
	for(i=0; i<M-1; i++){
		for(j=0; j<N-1; j++){
			if(mat[i][j]!=mat[i+1][j+1]){
				t=0;
				break;
			}
		}
	}
	if(t==0) printf("Matrica nije ni cirkularna ni Teplicova");
	else{
		for(i=1; i<M; i++)
			if(mat[i][0]!=mat[i-1][N-1]) c=0;
		if(c) printf("Matrica je cirkularna");
		else printf("Matrica je Teplicova");
	}
	return 0;
}
