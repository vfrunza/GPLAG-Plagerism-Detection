#include <stdio.h>



int main() {
	int  i,j, M , N, tacnot=1, tacnoc=1;
	double matrica[100][100];
	printf("Unesite M i N: ");
	scanf("%d%d", &M , &N);
	while( (M<=0||M>100 ) || (N<=0 ||N>100)) { printf("Pogresan unos!\n"); printf("Unesite M i N: ");
	scanf("%d%d", &M , &N);}
	
	printf("Unesite elemente matrice: ");
	for(i=0; i<M; i++)
	{
		for(j=0; j<N; j++)
		{
			scanf("%lf", &matrica[i][j] );
		}
	}
	
	for(i=1; i<M; i++)
	{
		for(j=1; j<N; j++)
		{
		 if(matrica[i][j]!=matrica[i-1][j-1])
		 { tacnot=0;
		 	
		 }
		}
	}
	for(i=1; i<M; i++)
	{
	
			if(matrica[i][0]!=matrica[i-1][N-1]){ tacnoc=0; break;}
		
	}
	if(tacnoc && tacnot) printf("Matrica je cirkularna");
	else if(tacnot && tacnoc==0) printf("Matrica je Teplicova");
	else printf("Matrica nije ni cirkularna ni Teplicova");

	return 0;
}
