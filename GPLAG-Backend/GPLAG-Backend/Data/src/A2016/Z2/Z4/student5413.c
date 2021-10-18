#include <stdio.h>

int main() 
{
	int m, n, i, k;
	int T = 1, C = 1;
	double mat[100][100];
	do
	{
		printf("Unesite M i N: ");
		scanf("%d %d", &m, &n);
		if(m <= 0 || m > 100 || n <= 0 || n > 100)
		  printf("Pogresan unos!\n");
		
	}while(m <= 0 || m > 100 || n <= 0 || n > 100);
	
	printf("Unesite elemente matrice: ");
	for(i = 0; i < m; i++)
	{
		for(k = 0; k < n; k++)
		{
			scanf("%lf", &mat[i][k]);
		}
	}
	
	for(i = 0; i < m - 1; i++)
	{
		for(k = 0; k < n - 1; k++)
		{
			if(mat[i][k] != mat[i + 1][k + 1])
			{
				T = 0;
				C = 0;
			}
			if(mat[i][n - 1] != mat[i + 1][0])
			  C = 0;
		}
	}
	
	if(m > 1 && n == 1)
	{
		C = 0;
		T = 1;
	}
	  
	if(C == 1)
	{
		printf("Matrica je cirkularna");
		return 1;
	}
	else if(T == 1)
	{
		printf("Matrica je Teplicova");
		return 2;
	}
	else
	  printf("Matrica nije ni cirkularna ni Teplicova");
	
	return 0;
}
