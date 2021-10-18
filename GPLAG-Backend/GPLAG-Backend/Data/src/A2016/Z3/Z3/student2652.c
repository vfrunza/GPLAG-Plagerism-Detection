#include <stdio.h>
int main() {
	int i, j, k, M=0, N=0, C=1, R, u, Q,t=1,matrix[100][100];
	
	/* Do while petljom osiguravamo da su trazeni brojevi u datom opsegu, ako se desi t==0 ne izlazi iz petlje */
	do {printf("Unesite brojeve M i N: ");
		scanf("%d", &M); 
		scanf("%d", &N);
		if(M<=0 || M>200 || N<=0 || N>200){ 
			printf("Brojevi nisu u trazenom opsegu.\n"); 
			t =0; 
			continue;} 
			else break;}
	while(t==0);
	/* Unosenje elemenata matrice*/
	printf("Unesite elemente matrice: ");
	i = 0; 

	while (i<M){
		j = 0;
		while (j<N){
		scanf("%d", &matrix[i][j]);	
		j++;}
	i++; 
	}
	i = 1;
	/* Poredjenje */
	while (i<M)					
	{
		R=0;
		while(R<i)			
		{
			C=1;
			j = 0;
			while (j<N)
			{
				if(matrix[i][j]!=matrix[R][j]) 
				{
					C=0;
					break;
				}
				j++;
			}
			if(C==1)
			{	
				k = i;
				while( k<(M-1) )				
				{
					j = 0;
					while(j<N)
					{
						matrix[k][j]=matrix[k+1][j];
						j++;
					}
					k++;
				}
				M=M-1; i=i-1;
			}
			R++;
		}
		i++;
	} 
	j = 1;
	while(j<N)
	{
		Q = 0;
		while(Q<j)
		{
			C=1;
			u = 0;
			while(u<M)
			{
				if(matrix[u][j]!=matrix[u][Q])
				{
					C=0;
					break;
				}
				u++;
			}
			if(C == 1)
			{
				k = 0;
				while(k<M)
				{
					i = j;
					while(i<N-1)
					{
						matrix[k][i]=matrix[k][i+1];
						i++;
					}
					k++;
				}
				N=N-1; j=j-1;
			}
			Q++;
		}
		j++;
	}
	printf("Nakon izbacivanja redova/kolona matrica glasi:\n");
	i = 0;
	while(i<M)
	{
		j = 0;
		while(j<N)
		{
			printf("%5d", matrix[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	return 0;
}