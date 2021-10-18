#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main() {
	int M,N,i,j,unos=0;
	double matrica[100][100];
	do {
		printf("Unesite M i N: ");
		scanf("%d %d", &M,&N);
	if (M>100 || N>100 || M<=0 || N<=0) { printf("Pogresan unos!\n");
	}
	else {
		unos=1;
	}
	}
	while(unos==0);
	printf("Unesite elemente matrice: ");
	for(i=0;i<M;i++)
	{
		for(j=0;j<N;j++)
		{
			scanf("%lf", &matrica[i][j]);
		}
	}
	int teplicova=1;
	for(i=0;i<M-1;i++)
	{
		for(j=0;j<N-1;j++)
		{
			if(matrica[i][j]!=matrica[i+1][j+1])
			 {
			 	teplicova=0;
			 }
		}
	}
	int cirkularna=1;
	for(i=0;i<M-1;i++)
	{
		for(j=0;j<N;j++)
		{
			if(matrica[i][j]!=matrica[i+1][(j+1)%N])
			{
				cirkularna=0;
			}
		}
	}
if(cirkularna==1)
{
	printf("Matrica je cirkularna");
}
else if(teplicova==1)
{
	printf("Matrica je Teplicova");
}
else if(cirkularna==0 && teplicova==0) {
	printf("Matrica nije ni cirkularna ni Teplicova");
}

return 0;
}