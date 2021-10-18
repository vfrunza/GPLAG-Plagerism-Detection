#include <stdio.h>

int main() {
	int matA[100][100],matB[100][100],matC[100][100],M,N,i,j,k,l,ponavljanje1=0,ponavljanje2=0,ponavljanje3=0,a=1;
	do{
		printf("Unesite brojeve M i N: ");
		scanf("%d %d",&M,&N);
	}while((M < 0 || M >100) || (N < 0 || N > 100));
	printf("Unesite clanove matrice A: ");
	for(i = 0; i < M; i++)
	{
		for(j = 0; j < N; j++)
		{
			scanf("%d",&matA[i][j]);
		}
	}
	printf("Unesite clanove matrice B: ");
	for(i =0; i < M; i++)
	{
		for(j = 0; j < N; j++)
		{
			scanf("%d",&matB[i][j]);
		}
	}
	printf("Unesite clanove matrice C: ");
	for(i = 0; i < M; i++)
	{
		for(j = 0; j < N; j++)
		{
			scanf("%d",&matC[i][j]);
		}
	}
	
	for(i = 0; i < M ; i++)
	{
		for(j = 0; j < N ; j++)
		{
			for(k = 0; k < M ; k++)
			{
				for(l = 0; l < N; l++)
				{
					if(matA[i][j] == matA[k][l]) ponavljanje1++;
				}
			}
			
			for(k = 0; k < M ; k++)
			{
				for(l = 0; l < N ; l++)
				{
					if(matA[i][j] == matB[k][l]) ponavljanje2++;
				}
			}
			
			for(k =0; k < M ; k++)
			{
				for(l = 0; l < N; l++)
				{
					if(matA[i][j] == matC[k][l]) ponavljanje3++;
				}
			}
			if(ponavljanje1 != ponavljanje2 || ponavljanje1 != ponavljanje3)
			{
				a =0;
				break;
			}
		}
	}
	if(a) printf("DA");
	else printf("NE");
	return 0;
}
