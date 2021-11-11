#include <stdio.h>
#define VISINA 100
#define DUZINA 100

int main() 
{
	double mat[	VISINA][DUZINA];
	
	int i,j,tepmat,cirmat,M,N;
	
	printf("Unesite M i N: ");
	scanf("%d %d",&M,&N);
	
	while(M<=0 || M>100 || N<=0 || N>100)
	{
		printf("Pogresan unos!\n");
		printf("Unesite M i N: ");
		scanf("%d %d",&M,&N);
		
	}
	
	printf("Unesite elemente matrice: ");
	
	for(i=0;i<M;i++)
	{
		for(j=0;j<N;j++)
		{
			scanf("%lf",&mat[i][j]);
		}
	}
	
	tepmat=1;
	cirmat=1;
	if(M!=1 && N==1)
	{
		tepmat=1;
		cirmat=0;
	}
	
	for(i=0;i<M-1;i++)
	{
		for(j=0;j<N-1;j++)
		{
			if(mat[i][j]!=mat[i+1][j+1])
			{
				tepmat=0;
				break;
			}
		}
	}
	
	for(i=0;i<M-1;i++)
	{
		for(j=0;j<N-1;j++)
		{
			if(mat[i][N-1]!=mat[i+1][0])
			{
				cirmat=0;
				break;
			}
		}
	}
	
	
	if(cirmat==1 && tepmat==1)
		printf("Matrica je cirkularna");
	else if(tepmat==1 && cirmat==0)
		printf("Matrica je Teplicova");	
	else
		printf("Matrica nije ni cirkularna ni Teplicova");
	return 0;
}
