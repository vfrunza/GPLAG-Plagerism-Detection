#include <stdio.h>

int main() {
	int M, N, i, j, teplicova=1, cirk=1;
	double mat[100][100];
		printf("Unesite M i N: ");
		scanf("%d %d", &M, &N);
	while(M<=0 || M>=101 || N<=0 || N>=101)
		{
			printf("Pogresan unos!\n");
			printf("Unesite M i N: ");
			scanf("%d %d", &M, &N);
		}
	printf("Unesite elemente matrice: ");
	for(i=0; i<M; i++)
	{
		for(j=0; j<N; j++)
		{
			scanf("%lf", &mat[i][j]);
		}
	}
	for(i=0; i<M-1; i++){
		for(j=0; j<N-1; j++){
			if (mat[i][j]!=mat[i+1][j+1])
			{teplicova=0;
			cirk=0;
			}
			else if (teplicova==1) {
				if(mat[i][N-1]!=mat[i+1][0])
				cirk=0;}
			else if (teplicova==0)
				cirk=0;
			
		}
	}
	if(M==1) printf("Matrica je cirkularna");
	else if (N==1) printf("Matrica je Teplicova");
	else if(cirk==1)
	printf("Matrica je cirkularna");
	else if(teplicova==1)
	printf("Matrica je Teplicova");
	
	
	else
	printf("Matrica nije ni cirkularna ni Teplicova");

	return 0;
}
