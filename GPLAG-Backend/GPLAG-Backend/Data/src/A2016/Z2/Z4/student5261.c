#include <stdio.h>
#define VISINA 100
#define SIRINA 100

int main()
{
	int M, N, i, j, CIRKULARNA = 1, TEPLICA = 1;
	double mat[VISINA][SIRINA];
	do
	{
		printf("Unesite M i N: ");
		scanf("%d %d", &M, &N);
		if(M<=0 || N<=0 || M>100 || N>100)
		{
			printf("Pogresan unos!\n");
		}
		
	}
	while(M<=0 || N<=0 || M>100 || N>100);
	printf("Unesite elemente matrice: ");
	for(i=0; i<M; i++)
	{
		for(j=0; j<N; j++)
		{
			scanf("%lf", &mat[i][j]);
		}
	}
	for(i=0; i<M-1; i++)
	{
		for(j=0; j<N-1; j++)
		{
			if(mat[i][j] != mat[i+1][j+1] || mat[i][N-1] != mat[i+1][0])
			{
			CIRKULARNA = 0;
			}
			break;
		}
	}
	if(N == 1 && M != 1)
	CIRKULARNA = 0;
	if(CIRKULARNA)
	{
		printf("Matrica je cirkularna");
		return 0;
	}
	for(i=0; i<M-1; i++)
	{
		for(j=0; j<N-1; j++)
		{
			if(mat[i][j] != mat[i+1][j+1])
			{
				TEPLICA = 0;
			}
			break;
		}
	}
	if(TEPLICA)
	{
		printf("Matrica je Teplicova");
		return 0;
	}
	
	printf("Matrica nije ni cirkularna ni Teplicova");
	
	
	
	return 0;
	
}


