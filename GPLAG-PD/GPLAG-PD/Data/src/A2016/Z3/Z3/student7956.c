#include <stdio.h>

int main() {
	
	int i, j, matrica[100][100], M=0, N=0, brojac=1, a, p, n, q;
	
	do
	{
		printf("Unesite brojeve M i N: ");
		scanf("%d", &M);
		scanf("%d", &N);
		
	
		if(M<1 || M>200 || N<1 || N>200)
		{
			printf("Brojevi nisu u trazenom opsegu.\n");
			continue;
		}
		else break;
	}
	while(1);
	
	printf("Unesite elemente matrice: ");
	
	for(i=0; i<M; i++)
	{
		for(j=0; j<N; j++)
		{
			scanf("%d", &matrica[i][j]);					
		}
	}
	
	for(i=1; i<M; i++)					
	{
		for(p=0; p<i; p++)			
		{
			brojac=1;
			
			for(j=0; j<N; j++)
			{
				if(matrica[i][j]!=matrica[p][j]) 
				{
					brojac=0;
					break;
				}
			}
			
			if(brojac)
			{
				for(a=i; a<M-1; a++)				
				{
					for(j=0; j<N; j++)
					{
						matrica[a][j]=matrica[a+1][j];
					}
				}
				
				M--;
				i--;
			}
		}
	}
	
	for(j=1; j<N; j++)
	{
		for(q=0; q<j; q++)
		{
			brojac=1;
			
			for(n=0; n<M; n++)
			{
				if(matrica[n][j]!=matrica[n][q])
				{
					brojac=0;
					break;
				}
			}
			
			if(brojac)
			{
				for(i=j; i<N-1; i++)
				{
					for(a=0; a<M; a++)
					{
						matrica[a][i]=matrica[a][i+1];
					}
				}
				
				N--;
				j--;
			}
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