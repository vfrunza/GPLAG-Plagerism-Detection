#include <stdio.h>

int main() 
{
	int m, n, i, j, treplicnost=0, cirkularnost=0;
	int matrica[101][101] = {{0},{0}};
	do
	{
		printf("Unesite M i N: ");
		scanf("%d", &m);
		scanf("%d", &n);
		if(m <= 0 || m > 100 || n <= 0 || n > 100) printf("Pogresan unos!\n");
	}
	while(m <= 0 || m > 100 || n <= 0 || n > 100);
	
	printf("Unesite elemente matrice: ");
	for(i=0; i<m; i++)
	{
		for(j=0; j<n; j++)
		{
			scanf("%d", &matrica[i][j]);
		}
	}
	for(i=0; i<m-1; i++)
	{
		for(j=0; j<n-1; j++)
		{
			if(matrica[i][j] != matrica[i+1][j+1])
			{
				treplicnost = 1;
			}
		}
		if(matrica[i][n-1] != matrica[i+1][0])
		{
			cirkularnost = 1;
		}
	}
	if(treplicnost == 1)
	{
		printf("Matrica nije ni cirkularna ni Teplicova");
	}
	else if(treplicnost == 0 && cirkularnost == 0)
	{
		printf("Matrica je cirkularna");
	}
	else
	{
		printf("Matrica je Teplicova");
	}
	
	
	return 0;
}
