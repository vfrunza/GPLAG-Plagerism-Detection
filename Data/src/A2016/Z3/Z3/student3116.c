#include <stdio.h>


int IzbaciRed(int mat[][200],int m,int n)
{   
	int i,j,k,p,q;
	int pret;
	
	for(i=0;i<m;i++)
	{
		for(j=i+1;j<m;j++)
		{
			pret=1;
			for(k=0;k<n;k++)
			{
			   if(mat[i][k]!=mat[j][k]) pret=0;
			}
			if(pret==1)
			{
				for(p=j;p<m-1;p++)
					for(q=0;q<n;q++)
						mat[p][q]=mat[p+1][q];
					m--;
					j--;
			}
		}
	}
	return m;
}


int IzbaciKolone(int mat[][200],int m,int n)
{   
	int i,j,k,p,q;
	int pret;
	
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			pret=1;
			for(k=0;k<m;k++)
			{ 
			   if(mat[k][i]!=mat[k][j]) pret=0;
			}
			if(pret==1)
			{   
				for(p=j;p<n-1;p++)
					for(q=0;q<m;q++)
						mat[q][p]=mat[q][p+1];
					n--;
					j--;
			}
		}
	}
	return n;
}

int main() 
{
    int M, N, i, j, matrica[200][200];
    
    do {
	printf("Unesite brojeve M i N: ");
	scanf("%d %d", &M, &N);
	if(M<1 || M>200 || N<1 || N>200)
          printf("Brojevi nisu u trazenom opsegu. \n");
    } while (M<1 || M>200 || N<1 || N>200);

	printf("Unesite elemente matrice: ");
	for(i=0; i<M; i++)
	{
		for(j=0; j<N; j++)
		{
			scanf("%d", &matrica[i][j]);
		}
	}
	
	M=IzbaciRed(matrica,M,N);
	N=IzbaciKolone(matrica,M,N);

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
