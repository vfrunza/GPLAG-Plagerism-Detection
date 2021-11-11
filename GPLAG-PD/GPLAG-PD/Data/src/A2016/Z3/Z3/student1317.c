#include <stdio.h>
#define VELICINA 201

int main() 
{
	int i, j, k, l, M, N, matrica[VELICINA][VELICINA];
	
	do
	{
		printf("Unesite brojeve M i N: ");
		scanf("%d %d", &M, &N);
		
		if(M<1 || M>200 || N<1 || N>200) printf("Brojevi nisu u trazenom opsegu.\n");
	} while(M<1 || M>200 || N<1 || N>200);
	

	printf("Unesite elemente matrice: ");
	for(i=0; i<M; i++)
	{
		for(j=0; j<N; j++)
		{
			scanf("%d", &matrica[i][j]);
		}
	}
	
	/* Poredjenje svih redova matrice */
	for(i=0; i<M-1; i++)
	{
		for(k=i+1; k<M; k++)
		{
			for(j=0; j<N; j++)
			{
				if(matrica[i][j] != matrica[k][j]) break;
			}
			if(j==N && k<M)
			{
				/* Izbacivanje reda iz matrice */
				for(l=k; l<M-1; l++)
				{
					for(j=0; j<N; j++)
					{
						matrica[l][j] = matrica[l+1][j];
					}
				}
				M--;
				k--;
			}
			else if(j==N && k==M) M--;
		}	
	}
	
	/* Poredjenje svih kolona matrice */
	for(i=0; i<N-1; i++)
	{
		for(k=i+1; k<N; k++)
		{
			for(j=0; j<M; j++)
			{
				if(matrica[j][i] != matrica[j][k]) break;
			}
			if(j==M && k<N)
			{
				/* Izbacivanje kolone iz matrice */
				for(l=k; l<N-1; l++)
				{
					for(j=0; j<M; j++)
					{
						matrica[j][l] = matrica[j][l+1];
					}
				}
				N--;
				k--;
			}
			else if(j==M && k==N) N--;
		}	
	}

	printf("Nakon izbacivanja redova/kolona matrica glasi:\n");
	for(i=0; i<M; i++)
	{
		for(j=0; j<N; j++)
		{
			printf("%5d", matrica[i][j]);
		}
		printf("\n");
	}
	return 0;
}
