#include <stdio.h>
#include <math.h>

int main() 
{
	int  M, N, A, B, i, j; 
	float matrica_A[100][100], matrica_B[100][100], matrica_A2[100][100];
	
	do
	{
		printf("Unesite sirinu i visinu matrice A: ");
		scanf("%d %d", &M, &N);
	}while( M>100 || M<0 || N>100 || N<0);
	
	
	printf("Unesite clanove matrice A: ");          /*unosenje clanova matrice A */
	
	for(i=0; i<N ; i++)
	{
		for(j=0; j<M; j++)
		{
			scanf("%f", &matrica_A[i][j]);
		}
	}
		
		
		
	for(i=0;i<N; i++)                          /*pravljenje zarotirane matrice A*/
	{
		for(j=0; j<M; j++)
		{
			matrica_A2[j][N-1-i]=matrica_A[i][j];
		}
	}
	


	do{
		printf("Unesite sirinu i visinu matrice B: ");
		scanf("%d %d", &A, &B);
	}while( A>100 || A<0 || B>100 || B<0);
	
	printf("Unesite clanove matrice B: ");                  /*unosenje clanova matrice B */
	
	for(i=0; i<B ; i++)
	{
		for(j=0; j<A; j++)
		{
			scanf("%f", &matrica_B[i][j]);
		}
	}
	
	
	if(N!=A || M!=B)
	{
		printf("NE");
		return 0;
	}
	
	
	for(i=0; i<B; i++)
	{
		for (j=0; j<A; j++)
		{
			if(fabs(matrica_A2[i][j]-matrica_B[i][j])>0.001)
			{
				printf("NE");
				return 0;
			}
			
		}
	}
	
	printf("DA");
	
	
	return 0;
}	