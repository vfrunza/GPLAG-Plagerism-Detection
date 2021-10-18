#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define EPSILON 0.00001
int main() {
	int M,N,i,j,T,C,br=0;
	double mat[100][100];
	printf("Unesite M i N: ");
	scanf("%d %d",&M,&N);
	while((M<=0 || N<=0) || (N>100 || M>100))
	{
		printf("Pogresan unos!\n");
		printf("Unesite M i N: ");
		scanf("%d %d",&M,&N);
	}
	printf("Unesite elemente matrice: ");
	for(i=0;i<M;i++)
	{
		for(j=0;j<N;j++)
		{
		scanf("%lf ",&mat[i][j]);
		}
	}
		for(i=0;i<M-1;i++)
		{
			if(fabs(mat[i][0]-mat[i+1][0])>EPSILON)
			br++;
		}
	if(M==1)
	
	{
		printf("Matrica je cirkularna");
	}
	else if(N==1 && br==0)
	{
		printf("Matrica je cirkularna");
	}
	else if(N==1 && br>0)
	{
		printf("Matrica je Teplicova");
	}
	else
	{
	T=1;
	for(i=0;i<M-1;i++)
	{
		for(j=0;j<N-1;j++)
		{
		if(fabs(mat[i][j]-mat[i+1][j+1])>EPSILON)	
		{
			i=101;
			j=101;
			T=0;
		}
		}
	}
	C=1;
	for(i=0;i<M-1;i++)
	{
		for(j=0;j<N-1;j++)
		{
		if(fabs(mat[i][j]-mat[i+1][j+1])>EPSILON || fabs(mat[i][N-1]-mat[i+1][0])>EPSILON)
		{
			i=101;
			j=101;
			C=0;
		}
		}
	}
	if(C==1)
	printf("Matrica je cirkularna");
	else if(C==0 && T==1)
	printf("Matrica je Teplicova");
	else
	printf("Matrica nije ni cirkularna ni Teplicova");
	}
	return 0;
}
