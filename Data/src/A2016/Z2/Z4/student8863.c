#include <stdio.h>

int main() {
	int M, N, /*mat[100][100]*/ i, j, t=1, c=1;
	double mat[100][100];
	printf("Unesite M i N: ");
	scanf("%d %d", &M, &N);
	while(M<1 || M>100 || N<1 || N>100){
		printf("Pogresan unos!\n");
		printf("Unesite M i N: ");
		scanf("%d %d", &M, &N);
	}
	
	printf("Unesite elemente matrice: ");
	for(i=0; i<M; i++){
		for(j=0; j<N; j++){
			scanf("%lf", &mat[i][j]);
		}
	}
	
	for(i=0; i<M-1; i++){
		for(j=0; j<N-1;j++){
			if(mat[i][j]==mat[i+1][j+1] && mat[i+1][0]!=mat[i][N-1])
				c=0;
			else if(mat[i][j]!=mat[i+1][j+1]){
				t=0;
				c=0;
			}
			
		}
	}
	
	if(c==1){
		if(N==1 && M!=1)
		printf("Matrica je Teplicova");
		else printf("Matrica je cirkularna");
	}
	else if(t==1)
		printf("Matrica je Teplicova");
	else
		printf("Matrica nije ni cirkularna ni Teplicova");
	
	return 0;
}
