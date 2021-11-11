#include <stdio.h>

int main() {
	int M,N;
	int i, j, mat[100][100];
	int teplicova=1;
	int cirkularna=1;
	do
	{
		printf("Unesite M i N: ");
	scanf("%d %d", &M, &N);
	if(M>100 || N>100 || M<=0 || N<=0) printf("Pogresan unos!\n");
	}while(M>100 || N>100 || M<=0 || N<=0);
	
	printf("Unesite elemente matrice: ");
	for(i=0;i<M;i++){
		for(j=0;j<N;j++){
			scanf("%d", &mat[i][j]);
		}
	}
	for(i=1;i<M;i++){
		for(j=1;j<N;j++){
			if(mat[i][j]!=mat[i-1][j-1])
			{   
				teplicova=0;
				printf("Matrica nije ni cirkularna ni Teplicova");
				return 0;
			}
		}
	}
	if(teplicova==1){
		for(i=1;i<M;i++){
				if(mat[i][0]!=mat[i-1][N-1]){
					cirkularna=0;
					break;
			}
		}
		if(cirkularna==1) printf("Matrica je cirkularna");
		else if(cirkularna==0) printf("Matrica je Teplicova");
	}
	return 0;
}
