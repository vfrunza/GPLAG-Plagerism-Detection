#include <stdio.h>
#define VISINA 100
#define SIRINA 100

int main ()
{
	double mat[VISINA][SIRINA];
	int i, j, N, M;
	int teplicova=1, cirkularna=1; /*postaviti vrijednost na logicku istinu*/
	
	do
	{
		printf("Unesite M i N: ");
		scanf("%d%d", &M, &N);
		if((N<1|| N>100) || (M<1 || M>100)) printf("Pogresan unos!\n");
		else break;
	}while((N<0 || N>100) || (M<1 || M>100));
	
	/*UNOS ELEMENATA SA TASTATURE*/
	printf("Unesite elemente matrice: ");
	for(i=0; i<M; i++)
	{
		for(j=0; j<N; j++)
		{
			scanf("%lf", &mat[i][j]);
		}
	}
	
	
	/*ISPITIVANJE*/
	for(i=0; i<M-1; i++)
	{
		for(j=0; j<N-1; j++)
		{
			if(mat[i][j]!=mat[i+1][j+1])
			{
				teplicova=0;  break;
			}
		}	
	}
	
    if(teplicova==1)
	{
		for(i=0; i<M-1; i++)
		{
			if(N==1)
			{
				cirkularna=0; break;
			}
			for(j=0; j<N-1; j++)
			{
				if(mat[0][N-1] != mat[1][0]  || mat[M-2][N-1]!=mat[M-1][0])
				{
					cirkularna=0; break;
				}
			
				
			}
		}
	}
	
	if(cirkularna==0 && teplicova==1) printf("Matrica je Teplicova\n");
	if(cirkularna==1 && teplicova==1) printf("Matrica je cirkularna\n");
	if(teplicova==0) printf("Matrica nije ni cirkularna ni Teplicova\n");

	return 0;
}