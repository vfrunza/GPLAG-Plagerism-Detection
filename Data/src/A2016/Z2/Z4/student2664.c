#include <stdio.h>

int main() {
	int M,N;
	int i, j, sta=0;
	double mat[100][100];
	
	do {
		printf("Unesite M i N: ");
		scanf("%d %d",&M,&N);
		if ((M>100 || M<=0) || (N>100 || N<=0))
		printf ("Pogresan unos!\n");
	} while ((M>100 || M<=0) || (N>100 || N<=0));
		
		printf ("Unesite elemente matrice: ");
		for (i=0; i<M; i++) {
			for (j=0; j<N; j++) {
				scanf("%lf", &mat[i][j]);
			}
		}
		
		for ( i = 1 ; i < M ; i++)
		{
			for ( j = 1 ; j < N ; j++)
			{
				if (mat[i-1][j-1] == mat[i][j] && mat[i-1][N-1] == mat[i][0])
				{
				if (sta == 2)
				continue;
				sta = 1;
				} 
				else if (mat[i-1][j-1] == mat[i][j] && mat[i-1][N-1] != mat[i][0]) 	{
				sta = 2;
				} 
				else {
				sta = 0;
				}
			}
		}
		
		if (M == 1)
		sta = 1;
		else if (N == 1)
		sta = 2;
		
		if (sta == 1)
		printf ("Matrica je cirkularna");
		else if (sta == 2)
		printf ("Matrica je Teplicova");
		else
		printf ("Matrica nije ni cirkularna ni Teplicova");
	
		return 0;
}
