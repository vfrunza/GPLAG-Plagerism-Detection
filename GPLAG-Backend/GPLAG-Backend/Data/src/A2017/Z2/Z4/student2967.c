#include <stdio.h>

int main() {
	
	int i,j,M,N,k,l,t,z;
	int mat[100][100];

	
	do{
		printf("Unesite M i N: ");
		scanf("%d %d",&M,&N);
		
		if(M<=0 || M>100 || N<=0 || N>100)
		printf("Pogresan unos!\n");
	}
	while(M<=0 || M>100 || N<=0 || N>100);
	
	
	printf("Unesite elemente matrice: ");
	
	for(i=0;i<M;i++)
	{
		for(j=0;j<N;j++)
		{
			scanf("%f",&mat[i][j]);
		}
	}
	
	
	for(k=0;k<M;k++)
	{
		for(l=0;l<N;l++)
		{
			if(k==N-1 && l==M-1 && mat[k][l]!=mat[k-1][l-1])
			{
				printf("Matrica nije ni cirkularna ni Teplicova");
				return 0 ;
			}
			
			
			
			else	if(k==M-1)
			{
				l++;
				continue;
			}
			else if(l==N-1)
			{
				k++;
				continue;
			}
			else if(mat[k][l]!=mat[k+1][l+1])
			{
				printf("Matrica nije ni cirkularna ni Teplicova");
				return 0;
			}
			
		
		}
	}
	
	for(t=0;t<M;t++)
	{
		for(z=0;z<N;z++)
		{
			if(t==M-1)
			{
				z++;
				continue;
			}
			
			else if(mat[t][N-1]!=mat[t+1][0])
			{
				printf("Matrica je Teplicova");
				return 0;
			}
		}
	}
	
	
	
	printf("Matrica je cirkularna");
	
	
	return 0;
}
