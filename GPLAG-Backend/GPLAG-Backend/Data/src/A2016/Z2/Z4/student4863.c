#include <stdio.h>

int main() {
	int M=1, N=1, i, j, C=1, T=1;
	double a[100][100];
	do{
		printf("Unesite M i N: ");
		scanf("%d %d", &M, &N);
		if(M<=0 || M>100 || N<=0 || N>100)
			printf("Pogresan unos!\n");
	}while(M<=0 || M>100 || N<=0 || N>100);
	printf("Unesite elemente matrice: ");
	for(i=0; i<M; i++)
	{
		for(j=0; j<N; j++)
			scanf("%lf", &a[i][j]);
	}
	
	//PROVJERA CIRKULARNA
	for(i=0; i<M-1; i++)
	{
		for(j=0; j<N; j++)
		{
			if(j<N-1 &&a[i][j]!=a[i+1][j+1])
				C=0;
			else if (j==(N-1) && a[i][j] != a[i+1][0])
				C=0;
		}
	}
	
	//PROVJERA TEPLICOVA
	for(i=0; i<M-1; i++)
	{
		for(j=0; j<N-1; j++)
		{
			if(a[i][j] != a[i+1][j+1])
				T=0;
		}
	}
	if(C) printf("Matrica je cirkularna");
	else if(T) printf("Matrica je Teplicova");
	else printf("Matrica nije ni cirkularna ni Teplicova");
	
	

	return 0;
}
