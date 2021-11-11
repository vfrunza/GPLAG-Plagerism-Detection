#include <stdio.h>

int main() 
{
	int i,j,k,l,m,M,N;
	int mat[200][200];
	printf("Unesite brojeve M i N: ");
	scanf("%d %d",&M,&N);
	while((M<=0 || N<=0) || (N>200 || M>200))
	{
		printf("Brojevi nisu u trazenom opsegu.\n");
		printf("Unesite brojeve M i N: ");
		scanf("%d %d",&M,&N);
	}
	printf("Unesite elemente matrice: ");
	for(i=0;i<M;i++)
	{
		for(j=0;j<N;j++)
		{
		scanf("%d",&mat[i][j]);
		}
	}
	//uporedjivanje redova
	for(i=0;i<M-1;i++)
	{
		for(j=i+1;j<M;j++)
		{
			int br=0;
			for(k=0;k<N;k++)
			{
				if(mat[i][k]==mat[j][k])
				br++;
			}
			//izbacivanje reda
			if(br==N)
			{
				for(l=j;l<M-1;l++)
				{
					for(m=0;m<N;m++)
					{
						mat[l][m]=mat[l+1][m];
					}
				}
				M--;
				j--;
			}
		}
	}
	//uporedjivanje kolona
	for(i=0;i<N-1;i++)
	{
		for(j=i+1;j<N;j++)
		{
			int br=0;
			for(k=0;k<M;k++)
			{
				if(mat[k][i]==mat[k][j])
				br++;
			}
			//izbacivanje kolone
			if(br==M)
			{
				for(l=j;l<N-1;l++)
				{
					for(m=0;m<M;m++)
					{
						mat[m][l]=mat[m][l+1];
					}
				}
				N--;
				j--;
			}
		}
	}
	printf("Nakon izbacivanja redova/kolona matrica glasi:\n");
	for(i=0;i<M;i++)
	{
		for(j=0;j<N;j++)
		{
			printf("%5d",mat[i][j]);
		}
		printf("\n");
	}
	return 0;
}
