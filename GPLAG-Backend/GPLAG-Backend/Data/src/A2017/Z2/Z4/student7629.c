#include <stdio.h>

int main() {
	int i,j,k,brojac=0,brojac1=0,M,N;
	double mat[100][100],mat1[100][100],mat2[100][100];
	printf("Unesite brojeve M i N: ");
	do
	{
		scanf("%d %d",&M,&N);
	}while(M<100 && N<100);
	printf("Unesite clanove matrice A: ");
	for(i=0;i<M;i++)
	{
		for(j=0;j<N;j++)
		{
		scanf("%lf",mat[i][j]);
	}
	}
	printf("Unesite clanove matrice B: ");
	for(i=0;i<M;i++)
	{
		for(j=0;j<N;j++)
		{
			scanf("%lf",mat2[i][j]);
		}
	}
	printf("Unesite clanove matrice C: ");
	for(i=0;i<M;i++)
	{
		for(j=0;j<N;j++)
		{
			scanf("%lf",&mat2[i][j]);
		}
	}
	for(i=0;i<M;i++)
	{
		for(j=0;j<N;j++)
		{
			if((mat1[i][j]==mat[i][j] && (mat[i][j]==mat2[i][j]))
			{	
		}
	}


	return 0;
}
