#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define EPSILON 0.0000000001

int main() {
	double niz[100][100];
	int a,b,M,N,t,c;
	do
	{
		printf("Unesite M i N: ");
		scanf("%d %d",&M,&N);
		if (((M<=0) || (M>100)) || ((N<=0) || (N>100)))
		{
			printf("Pogresan unos!\n");
			
		}
		
	} while (((M<=0) || (M>100)) || ((N<=0) || (N>100)));
	printf("Unesite elemente matrice: ");
	t=1;
	c=1;
	for(a=0;a<M;a++)
	{
		for(b=0;b<N;b++)
		{
			scanf("%lf",&niz[a][b]);
				
		}
			
	}
	for (a=0;a<(M-1);a++)
	{
		for(b=0;b<(N-1);b++)
		{
			if((fabs(niz[a][b] - niz[a+1][b+1])>EPSILON))
			t=0;
				
		}
			
	}
	for (a=0;a<(M-1);a++)
	{
		for(b=0;b<(N-1);b++)
		{ 
			if((fabs (niz[a][b]-niz[a+1][b+1])>EPSILON) || (fabs(niz[a][N-1]-niz[a+1][0])>EPSILON))
			c=0;
			
		}
			
	}
	if(((t==1) && (c==0)) || ((M==100) && (N==1)))
	{
		printf("Matrica je Teplicova");
		
	}
	else if (c==1) 
	{
			printf("Matrica je cirkularna");
		
	}
	else
	{
		printf("Matrica nije ni cirkularna ni Teplicova");
		
	}
	return 0;
		
	}
		

