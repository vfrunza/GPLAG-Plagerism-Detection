#include <stdio.h>
#include <math.h>
#define EPS 0.000000001
int main() 
{
	/*printf("Zadaća 2, Zadatak 4");*/
	double mat[100][100];
	int M = 0, N = 0, i = 0, j = 0, tep = 1, cirk = 1;

	do
	{
		ugh:
		printf("Unesite M i N: ");
		scanf("%d %d", &M, &N);
		
		if(M > 100 || M < 1 || N > 100 || N < 1)
		{
			printf("Pogresan unos!\n");
			goto ugh;
		}
			
		else
			goto stajaznam;
	}
	
	while((M <= 100 && M > 0) || (N <= 100) && (N > 0));
	
	stajaznam:
	printf("Unesite elemente matrice: ");
	
	for(i = 0; i < M; i++)
	{
		for(j = 0; j < N; j++)
		{
			scanf("%lf", &mat[i][j]);
		}
	}
	
	for(i = 0; i < M - 1; i++)
	{
		for(j = 0; j < N - 1; j++)
		{
			if(fabs(mat[i][j] - mat[i + 1][j + 1]) > EPS)			
			{
				tep = 0;
				break;
			}
		}
	}
	
	if(tep)
	{
		for(i = 0; i < M - 1; i++)
		{
			for(j = 0; j < N - 1; j++)
			{
				if(fabs(mat[i][N - 1] - mat[i + 1][0]) > EPS)
				{
					cirk = 0;
					break;
				}
			}
			
			if(j < 1)
			{
				cirk = 0;
				break;
			}
		}
		
		if(cirk)
			printf("Matrica je cirkularna\n");
		
		else
			printf("Matrica je Teplicova\n");
	}
	
	else
		printf("Matrica nije ni cirkularna ni Teplicova");
	
	return 0;
}