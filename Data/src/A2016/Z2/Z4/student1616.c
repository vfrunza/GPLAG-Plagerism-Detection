#include <stdio.h>
#include <stdlib.h>

#include <stdio.h>
int main() {
	double mat[100][100];
	int i,j,teplic=0,cirk=1,M,N, desise=0;
	do
	{
		printf("Unesite M i N: ");
		scanf("%d %d", &M,&N);
		if(M>100 || M<1 || N>100 || N<1)
		printf("Pogresan unos!\n");
	}
		while(M>100 || M<1 || N>100 || N<1);
		printf("Unesite elemente matrice: ");
		for(i=0;i<M;i++)
		{
			for(j=0;j<N;j++)
			{
				scanf("%lf", &mat[i][j]);
			}
		}
			for(i=0;i<M-1;i++)
			{
				for(j=0;j<N-1;j++)
				{
					if(mat[i][j]!=mat[i+1][j+1])
					{
						cirk=0;
					}
				}

			}
			if(cirk==1)
            {
                for(i=0;i<M-1;i++)
			{
				for(j=0;j<N;j++)
				{
					if(mat[i][N-1]!=mat[i+1][0])
					{
						desise=1;
					}
				}
				if(desise==1) { teplic=1; break;}
			}
			if(teplic==1) printf("Matrica je Teplicova");
			else printf("Matrica je cirkularna");
            }
            else printf("Matrica nije ni cirkularna ni Teplicova");

	return 0;
}