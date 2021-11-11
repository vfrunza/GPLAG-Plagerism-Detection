#include <stdio.h>

int main() {
	double matrica[100][100];
	int i,j,M,N,teplicova=1,cirkularna=1;
	do
	{
		printf("Unesite M i N: ");
		scanf("%d %d", &M,&N);
		if(M<=0 || M>100 || N<=0 || N>100)
		{
			printf("Pogresan unos!\n");
		}
	}while(M<=0 || M>100 || N<=0 || N>100);
	
	printf("Unesite elemente matrice: ");
	for(i=0;i<M;i++)
	{
		for(j=0;j<N;j++)
		{
		
			scanf("%lf", &matrica[i][j]);
		}
	}
	for(i=1;i<M;i++)
	{
		for(j=1;j<N;j++){
			if(matrica[i][j] != matrica[i-1][j-1])
			{
				teplicova=0;
			}
		}
	}
	
	for(i=1;i<M;i++)
	{
		if(matrica[i][0] != matrica[i-1][N-1])
		{
			cirkularna=0;
			break;
		}
	}
	if(cirkularna && teplicova)
	{printf("Matrica je cirkularna");}
	else if(teplicova && cirkularna==0)
	{printf("Matrica je Teplicova");}
	else {printf("Matrica nije ni cirkularna ni Teplicova");}
	return 0;
}
