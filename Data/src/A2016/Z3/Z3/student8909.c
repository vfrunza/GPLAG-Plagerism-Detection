#include <stdio.h>

int main() 
{
	int M, N, i, j, a, b, k, isti, mat[200][200];
	do
	{
		printf("\nUnesite brojeve M i N: ");
		scanf("%d %d", &M, &N);
		
		if(M>200 || M<=0 || N<=0 || N>200)
		printf("Brojevi nisu u trazenom opsegu.");
	}
	while(M<=0 || M>200 || N<=0 || N>200);
	
	printf("Unesite elemente matrice: ");
	
	for(i=0; i<M; i++)
	{
		for(j=0; j<N; j++)
		{
			scanf("%d", &mat[i][j]);
		}
	}
	
	
	// Izbacivanje reda.

	
	for(i=0; i<M; i++)
	{
		for(j=i+1; j<M; j++)
		{
			isti = 1;
			
			for(k=0; k<N; k++)
			{
				if(mat[i][k] != mat[j][k])
				{
					isti = 0;
					break;
				}
			}
		if(isti == 1)
		{
			for(a=j; a<M-1; a++)
			{
				for(b=0; b<N; b++)
				{
					mat[a][b] = mat[a+1][b];
				}
			}
			j--;
			M--;
		}
		
	}
}

// Izbacivanje kolone


	for(j=0; j<N; j++)
	{
		for(i=j+1; i<N; i++)
		{
			isti=1;
			for(k=0; k<M; k++)
			{
				if(mat[k][j] != mat[k][i])
				{
					isti = 0;
					break;
				}
			}
			
			if(isti)
			{
				for(a=i; a<N-1; a++)
				{
					for(b=0; b<M; b++)
					{
						mat[b][a] = mat[b][a+1];
					}
				}
				i--;
				N--;
			}
		}
	}
	
	
	
	// Ispis matrice
	
	printf("Nakon izbacivanja redova/kolona matrica glasi: \n");
	
	for(i=0; i<M; i++)
	{
		for(j=0; j<N; j++)
		{
			printf("%5d", mat[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}
