#include <stdio.h>

int main() 
{
	int i, j, M, N, matrica[100][100]={{0}}, tep_mat[100][100]={{0}}, cirk_mat[100][100]={{0}}, cirkularna=1, teplicova=1;
	
	/* Unosenje dimenzija matrice */
	do
	{
		printf("Unesite M i N: ");
		scanf("%d %d", &M, &N);
		
		if(M <= 0 || M > 100 || N <= 0 || N > 100) printf("Pogresan unos!\n");
		
	} while(M <= 0 || M > 100 || N <= 0 || N > 100);
	
	/* Unosenje elemenata matrice */
	printf("Unesite elemente matrice: ");
	for(i=0; i < M; i++)
	{
		for(j=0; j < N; j++)
		{
			scanf("%d", &matrica[i][j]);
		}
	}
	
	/* Formiranje cirkularne matrice */
	for(i=0; i < M; i++)
	{
		for(j=0; j < N; j++)
		{
			if(i==0) cirk_mat[i][j] = matrica[i][j];
			else
			{
				if(j==0) cirk_mat[i][j] = cirk_mat[i-1][N-1];
				else cirk_mat[i][j] = cirk_mat[i-1][j-1];
			}
		}
	}
	
	/* Ispitivanje da li je unesena matrica cirkularna */
	for(i=0; i < M; i++)
	{
		for(j=0; j < N; j++)
		{
			 if(matrica[i][j] != cirk_mat[i][j]) 
			 {
			 	cirkularna=0;
			 	break;
			 }
		}
		if(j<N) break;
	}
	
	if(cirkularna == 1) printf("Matrica je cirkularna");
	
	else
	{
		/* Formiranje Teplicove matrice */
		for(i=0; i < M; i++)
		{
			for(j=0; j < N; j++)
			{
				if(i==0 || j==0) tep_mat[i][j] = matrica[i][j];
				else tep_mat[i][j] = matrica[i-1][j-1];
			}
		}
		
		/* Ispitivanje da li je unesena matrica Teplicova */
		for(i=0; i < M; i++)
		{
			for(j=0; j < N; j++)
			{
			 	if(matrica[i][j] != tep_mat[i][j]) 
			 	{
			 		teplicova=0;
			 		break;
			 	}
			}
			if(j<N) break;
		}
	
		if(teplicova == 1) printf("Matrica je Teplicova");
		else printf("Matrica nije ni cirkularna ni Teplicova");
	}
	
	return 0;
}
