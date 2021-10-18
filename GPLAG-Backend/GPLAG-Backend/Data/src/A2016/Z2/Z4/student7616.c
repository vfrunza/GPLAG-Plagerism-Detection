#include <stdio.h>
#include<math.h>
#define EPSILON 0.0000001

int main() 
{
	double mat[100][100];
	int M,N,i,j;
	do
	{
		printf("Unesite M i N: ");
		scanf("%d %d", &M,&N);
		if(M<=0 || M>100 || N<=0 || N>100) {
			printf("Pogresan unos!\n");
		}
	}
	while(M<=0 ||  M>100 || N<=0 || N>100);
	printf("Unesite elemente matrice: ");
	for(i=0; i<M; i++)
	{
		for(j=0; j<N; j++)
		{
			scanf("%lf", &mat[i][j]);
		}
	}
	
	int cir;
	cir=1;
	for(i=0; i<M - 1; i++)
	{
		for(j=0; j<N; j++)
		{
		
			if(j==0)
			{
				if( !(fabs(mat[i][N-1] - mat[i+1][j]) <= EPSILON*(fabs(mat[i+1][j]) + fabs(mat[i][N-1]) ) )
				||	mat[i][N-1] != mat[i+1][j]		)	cir = 0;
			}
			else if(!( (fabs(mat[i][j-1] - mat[i+1][j]) <= EPSILON*(fabs(mat[i+1][j]) + fabs(mat[i][j]) ) ))
	|| mat[i][j-1] != mat[i+1][j]	)	cir = 0;
		}
	}

	if(cir) 
	{
		printf("Matrica je cirkularna\n"); return 0;
	}
	
	int tep;
	tep=1;
	
	for(i=0; i<M - 1; i++)
	{
		for(j=0; j<N - 1; j++)
		{
			if(!(fabs(mat[i][j] - mat[i+1][j+1]) <= EPSILON * ( fabs(mat[i][j]) + fabs( mat[i+1][j+1]) ))
			|| mat[i][j] != mat[i+1][j+1]) tep = 0;
		}
	}
	
	if(tep) 
		printf("Matrica je Teplicova\n");
	else 
		printf("Matrica nije ni cirkularna ni Teplicova");
	return 0;
	
}