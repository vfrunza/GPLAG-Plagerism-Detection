#include <stdio.h>

int main() {
	
	int i, j, matr[100][100], M=0, N=0, isto=1, k, r, n, q;
	
	do
	{
		printf("Unesite brojeve M i N: ");
		scanf("%d", &M);
		scanf("%d", &N);
		
	//pripremite se na jedno pedeset petlji hahah
	
		if(M<=0 || M>200 || N<=0 || N>200)
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
			scanf("%d", &matr[i][j]);					//ma papir brat, odoh ja ovo ispisat' prvo
		}
	}
	
	for(i=1; i<M; i++)					//uporedjujemo i izbcujemo (po potrebi)....haj valjda ce na nesto liciti
	{
		for(r=0; r<i; r++)			
		{
			isto=1;
			
			for(j=0; j<N; j++)
			{
				if(matr[i][j]!=matr[r][j]) 
				{
					isto=0;
					break;
				}
			}
			
			if(isto)
			{
				for(k=i; k<M-1; k++)				//ajd da probamo izbaciti kolonu :P
				{
					for(j=0; j<N; j++)
					{
						matr[k][j]=matr[k+1][j];
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
			isto=1;
			
			for(n=0; n<M; n++)
			{
				if(matr[n][j]!=matr[n][q])
				{
					isto=0;
					break;
				}
			}
			
			if(isto)
			{
				for(k=0; k<M; k++)
				{
					for(i=j; i<N-1; i++)
					{
						matr[k][i]=matr[k][i+1];
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
			printf("%5d", matr[i][j]);
		}
		
		printf("\n");
	}
	
	return 0;
}
