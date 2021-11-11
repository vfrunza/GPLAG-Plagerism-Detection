#include <stdio.h>
#include <stdlib.h>
#define X 100
#define Y 100
int main() {
	double mat[Y][X];
	int i, j, teplic=1, cirk=1, M, N;
	do
	{
		printf("Unesite M i N: ");
		scanf("%d %d", &M,&N);
		if(M>100 || M<1 || N>100 || N<1)
		printf("Pogresan unos!\n");
	}
		while(M>100 || M<1 || N>100 || N<1);
		printf("Unesite elemente matrice: ");
		for (i=0; i<M; i++)
		{
			for (j=0; j<N; j++)
			{
				scanf("%lf", &mat[i][j]);
			}
		}
		teplic=1;
			for (i=0; i<M-1; i++)
			{
				for (j=0;j<N-1;j++)
				{
					if (mat[i][j]!=mat[i+1][j+1])
						teplic=0;
				}

			}
			if (teplic==1)
            { 
            	cirk=1;
                for (i=0; i<M-1; i++)
			{
				for (j=0; j<N; j++)
				{
					if (mat[i][N-1]!=mat[i+1][0])
					cirk=0;
				}
			
			}
			if (cirk==1) printf ("Matrica je cirkularna");
			else if (teplic==1 && cirk==0) printf ("Matrica je Teplicova");
            }
            else printf ("Matrica nije ni cirkularna ni Teplicova");

	return 0;
}

