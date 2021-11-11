#include <stdio.h>

int main() {
	int M, N, ispravnost, teplicova, i, j, mat[101][101], cirkularna;
	M=101, N=101, ispravnost=0, teplicova=1, cirkularna=1;
	while(ispravnost!=1)
	{
	printf("Unesite M i N: ");
	scanf("%d %d", &M, &N);
	if((M<=0 || M>100) || (N<=0 || N>100)) 
	{
		printf("Pogresan unos!\n");
		
	}
	else ispravnost=1;
	}
	printf("Unesite elemente matrice: ");
	for(i=0; i<M-1; i++) {
		for(j=0; j<N-1; j++){
			scanf("%d", &mat[i][j]);
		}
	}
	for(i=0; i<M-1; i++) {
		for(j=0; j<N-1; j++){
			if(i!=M-2 && j!=N-2 && i!=M-1 && j!=N-1 )
			{
			if((mat[i][j]!=mat[i+1][j+1]) || (mat[i][j]!=mat[i][N-1-j]))
			cirkularna=0;
			if(mat[i][j]!=mat[i+1][j+1] || mat[i][j]!=mat[i+1][j])
			teplicova=0;
			}
		}
	}
	if(cirkularna) printf("Matrica je cirkularna");
	else if(teplicova) printf("Matrica je Teplicova");
	else printf("Matrica nije ni cirkularna ni Teplicova");
	return 0;
}