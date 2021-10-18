#include <stdio.h>

int main() {
	
	int M, N, i, j, k, t, mat[200][200] = {{0}};
	int isti_elem;
	
	do
	{
		printf("Unesite brojeve M i N: ");
		scanf("%d %d", &M, &N);
		if(M <= 0 || M > 200 || N <= 0 || N > 200)
		printf("Brojevi nisu u trazenom opsegu.\n");
	}
	while(M <= 0 || M > 200 || N <= 0 || N > 200);
	
	printf("Unesite elemente matrice: ");
	for(i = 0; i < M; i++)
	{
		for(j = 0; j < N; j++)
		{
			scanf("%d", &mat[i][j]);
		}
	}
	
	/*za redove*/
	for(i = 1; i < M; i++)
	{
		for(j = 0; j < i; j++) 
		{
			isti_elem = 1;
			for(k = 0; k < N; k++)
			{
				if(mat[i][k] != mat[j][k])
				{
					isti_elem = 0;
					break;
				}
			}
			/*izbacivanje reda*/
			if(isti_elem)
			{
				for(t = i; t < M - 1; t++)
				{
					for(k = 0; k < N; k++)
					{
						mat[t][k] = mat[t+1][k];
					}
				}
				M--;
				i--;
				break;
			}
		}
	}
	
	/*Za kolone*/
	for(j = 1; j < N; j++)
	{
		for(k = 0; k < j; k++)
		{
			isti_elem = 1;
			for(i = 0; i < M; i++)
			{
				if(mat[i][j] != mat[i][k])
				{
					isti_elem = 0;
					break;
				}
			}
			/*Izbacivanje kolone*/
			if(isti_elem)
			{
				for(t = j; t < N - 1; t++)
				{
					for(i = 0; i < M; i++)
					{
						mat[i][t] = mat[i][t+1];
					}
				}
				N--;
				j--;
				break;
			}
		}
	}
	
	printf("Nakon izbacivanja redova/kolona matrica glasi:\n");
	for(i = 0; i < M; i++)
	{
		for(j = 0; j < N; j++)
		{
			printf("%5d", mat[i][j]);
		}
		printf("\n");
	}
	return 0;
}
