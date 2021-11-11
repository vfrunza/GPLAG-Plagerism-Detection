#include <stdio.h>

int jednakiSuRedovi(int mat[][200],int M,int N,int manjiIndeks,int veciIndeks)
{
	int i,jednakiSu=1;
	
	for(i=0;i<N;i++)
	{
		if( mat[manjiIndeks][i]!=mat[veciIndeks][i] )
		{
			jednakiSu=0;
			break;
		}
	}
	return jednakiSu;
}

int jednakeSuKolone(int mat[][200], int M, int N, int manjiIndeks, int veciIndeks)
{
	int i,jednakeSu=1;
	
	for(i=0; i<M; i++)
	{
		if(mat[i][manjiIndeks]!=mat[i][veciIndeks])
		{
			jednakeSu=0;
			break;
		}
	}
	return jednakeSu;
}


void izbaciRed(int mat[][200], int M, int N, int indeksReda)
{
	int i,j;
	for(i=indeksReda; i<M; i++)
	{
		for(j=0; j<N; j++)
		{
			mat[i][j]=mat[i+1][j];
		}
	}
}

void izbaciKolonu(int mat[][200], int M, int N, int indeksKolone)
{
	int i,j;
	
	for(i=indeksKolone; i<N-1; i++)
	{
		for(j=0;j<M;j++) 
		{
			mat[j][i]=mat[j][i+1];
		}
	}
}

void ispisiMatricu(int mat[][200], int M, int N)
{
	int i,j;
	for(i=0; i<M; i++)
	{
		for(j=0;j<N;j++)
		{
			printf("%5d",mat[i][j]);
		}
		printf("\n");
	}
}

int main() {
	int i,j,M,N,mat[200][200],nestoJeIzbaceno=0;
	
	do
	{
		printf("Unesite brojeve M i N: ");
		scanf("%d %d",&M,&N);
		if( M<=0 || M>200 || N<=0 || N>200 )
		{
			printf("Brojevi nisu u trazenom opsegu.\n");
		}
	}
	while( M<=0 || M>200 || N<=0 || N>200 );
	
	printf("Unesite elemente matrice: ");
	for(i=0;i<M;i++)
	{
		for(j=0;j<N;j++)
		{
			scanf("%d",&mat[i][j]);
		}
	}
	
	printf("Nakon izbacivanja redova/kolona matrica glasi:\n");
	do {
		nestoJeIzbaceno=0;
		for(i=0;i<M;i++)
		{
			for(j=i+1;j<M;j++)
			{
				if( jednakiSuRedovi(mat,M,N,i,j)==1 )
				{
					izbaciRed(mat,M,N,j);
					M--;
					nestoJeIzbaceno=1;
				}
			}
		}
		for(i=0; i<N; i++)
		{
			for(j=i+1; j<N; j++)
			{
				if( jednakeSuKolone(mat,M,N,i,j)==1 )
				{
					izbaciKolonu(mat,M,N,j);
					N--;
					nestoJeIzbaceno=1;
				}
			}
		}
	}while(nestoJeIzbaceno==1);
	ispisiMatricu(mat,M,N);
	return 0;
}
