/* zadaca 2, zadatak 4. */

#include <stdio.h>

int main() 
{
	int i=0, j=0, M=0, N=0, teplikova = 1, cirkularna = 1;
	double mat[101][101];
	do
	{
		printf("Unesite M i N: ");
		scanf("%d %d", &M, &N);
		if(M > 100 || M <= 0 || N > 100 || N <= 0) printf("Pogresan unos!\n");
	}
	while(M > 100 || M <= 0 || N > 100 || N <= 0);
	
	printf("Unesite elemente matrice: ");
	
	for(i=0; i<M; i++)
	{
		for(j=0; j<N; j++)
		{
			scanf("%lf", &mat[i][j]);
		}
	}
	
	for(i=0; i<M-1; i++)
	{
		for(j=0; j<N-1; j++)
		{
			if((mat[i][j]) != (mat[i+1][j+1])) teplikova = 0;
		}
	}
	
	for(i=0; i<M-1; i++)
	{
			for(j=0; j<N-1; j++)
			{
				if((mat[i][j]) != (mat[i+1][j+1]) && (mat[i][N-1]) != (mat[i+1][0])) 
				cirkularna = 0;
			}
			
	}
	
	
	
	if(teplikova == 1) printf("Matrica je Teplicova");
	
	else
	{
		if(cirkularna == 1) printf("Matrica je cirkularna");
		
		else printf("Matrica nije ni cirkularna ni Teplicova");
	}
	
	
	
	return 0;
}
