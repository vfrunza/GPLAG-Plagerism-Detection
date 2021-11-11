#include <stdio.h>

int main() {
	int M, N, i, j;
	int matrica[100][100];
	do {
		printf("Unesite M i N: ");
		scanf("%d %d",&M,&N);
		if (M <= 0 || M > 100 || N <= 0 || N > 100 )
		{
			printf("Pogresan unos! \n");
		}
		else break;
	} while (1);
	
	printf("Unesite elemente matrice: ");
	for (i = 0; i < M; i++)
	{
		for (j = 0; j < N; j++)
		{
			scanf("%d",&matrica[i][j]);

		}
	}
	 int b = 7; 
    for (i = 0; i < M-1; i++)
    {
    	for (j = 0; j < N-1; j++)
    	{
    		if (matrica[i][j] != matrica[i+1][j+1])
    		b = 9;
    	}
    	if (matrica[i][N-1] != matrica[i+1][0])
    	b = 9;
    }
    if (b == 7){
    printf("Matrica je cirkularna ");
    return 0;
    }
    int a =  5;
    for (i = 0; i < M-1; i++)
    {
    	for (j = 0; j < N-1; j++)
    	{
    		if (matrica[i][j] != matrica[i+1][j+1])
    		a = 10;
    	}
    }
    if (a == 5)
    printf("Matrica je Teplicova ");
   
    if (b != 7 && a != 5)
    printf("Matrica nije ni cirkularna ni Teplicova ");
    

	return 0;
}
