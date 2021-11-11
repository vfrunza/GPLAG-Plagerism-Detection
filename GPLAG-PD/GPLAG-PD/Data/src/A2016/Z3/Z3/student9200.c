#include <stdio.h>

int main() {
	int M,N;
	do
	{
		printf("Unesite brojeve M i N: ");
		scanf("%d %d",&M,&N);
		if(M<1 || M>200 || N<1 || N>200)
		{
			printf("Brojevi nisu u trazenom opsegu.\n");
			continue;
		}
		else break;
	}while(1);
	
	printf("Unesite elemente matrice: ");
	int i,j;
	int mat[200][200];
	
	for(i=0;i<M;i++)
	{
		for(j=0;j<N;j++)
		{
			scanf("%d",&mat[i][j]);
		}
	}
	
	
	printf("Nakon izbacivanja redova/kolona matrica glasi:  \n  ");
	for(i=0;i<M;i++)
	{
		for(j=0;j<N;j++)
		{
			printf("  %d  ",mat[i][j]);
		}printf("\n  ");
	}
	return 0;
}
