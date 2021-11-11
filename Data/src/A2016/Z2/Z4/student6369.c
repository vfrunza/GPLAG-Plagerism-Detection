#include <stdio.h>
#include <math.h>

int main() {
	int M,N,i,j,teplicova = 0,cirkularna = 0;
	float mat[100][100];
	printf("Unesite M i N:");
	do{
	    scanf("%d %d",&M,&N);
	} while(M > 0 && M < 100 && N > 0 && N < 100);
	if(M < 0 || M > 100 || N < 0 || N > 100)
	{
	    printf("Pogresan unos!\nUnesite M i N:");
	    scanf("%d %d",&M, &N);
	}
	printf("Unesite elemente matrice: ");
	for(i = 0; i < M ; i++)
	{
	    for(j = 0; j < N ; j++)
	    {
	        scanf("%f",&mat[i][j]);
	    }
	}
	for(i = 0; i < M - 1 ; i++)
	{
	    for(j = 0 ; j < N - 1; j++)
	    {
	        if(fabs(mat[i][j]) == fabs(mat[i+1][j+1])) 
	        {
	        	teplicova = 1;
	        }
	        else if(fabs(mat[i][j]) == fabs(mat[i+1][j+1]) && fabs(mat[i][N-1]) == fabs(mat[i+1][0])) 
	        {
	        	cirkularna = 1;
	        }
	    }
	}
	if(cirkularna == 1) printf("Matrica je cirkularna.");
	if(teplicova == 1) printf("Matrica je Teplicova.");
	
	return 0;
}
