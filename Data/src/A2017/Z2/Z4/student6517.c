#include <stdio.h>

int main() 
{
	int  M, N, i, j, br1, br2, br3, broj, k, l; 
	int matrica_A[100][100], matrica_B[100][100], matrica_C[100][100];
	
	do{
		printf("Unesite brojeve M i N: ");
		scanf("%d %d", &M, &N);
	}while(M>100 || N>100 );
	
	
	printf("Unesite clanove matrice A: ");
	
	for(i=0; i<M ; i++)
	{
		for(j=0; j<N; j++)
		{
			scanf("%d", &matrica_A[i][j]);
		}
	}
	

	
	
	printf("Unesite clanove matrice B: ");
	
	for(i=0; i<M ; i++)
	{
		for(j=0; j<N; j++)
		{
			scanf("%d", &matrica_B[i][j]);
		}
	}
	
	
	
	printf("Unesite clanove matrice C: ");
	
	for(i=0; i<M ; i++)
	{
		for(j=0; j<N; j++)
		{
			scanf("%d", &matrica_C[i][j]);
		}
	}
	
	
	for(i=0; i<M; i++)
	{
		for(j=0; j<N; j++)
		{
			broj=matrica_A[i][j];
			br1=br2=br3=0;


			for(k=0; k<M; k++)
			{
				for(l=0; l<N; l++)
				{
					
					if(matrica_A[k][l]==broj)
					{
						br1++;
					}
					
					if(matrica_B[k][l]==broj)
					{
						br2++;
					}
					if(matrica_C[k][l]==broj)
					{
						br3++;
					}
					
				}
				
			}
			
			if(br1!=br2 || br1!=br3  || br2!=br3)
					{
					printf("NE");
					return 0;
					}
		}
	}
	
	printf("DA");
	
	return 0;
}
