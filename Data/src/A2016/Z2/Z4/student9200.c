#include <stdio.h>

int main() {
	int M, N;
	do
	{
		printf("Unesite M i N: ");
		scanf("%d %d",&M,&N);
		
		if(M<=0 || M>100 || N<=0 || N>100) {
			printf("Pogresan unos!\n");
			printf("Unesite M i N: ");
			scanf("%d %d",&M,&N);
			if(M<=0 || N>100 || N<0 || N>100) printf("Pogresan unos!\n");
		}
	}while(M<0||M>100||N<0||N>100);
	double mat[100][100];
	printf("Unesite elemente matrice: ");
	int i,j;
	for(i=0;i<M;i++)
	{
		for(j=0;j<N;j++)
		{
			scanf("%lf",&mat[i][j]);
		}
	}
	int teplicova=1;
	for(i=0;i<M-1;i++)
	{
		for(j=0;j<N-1;j++)
		{
			if(mat[i][j]!=mat[i+1][j+1]) teplicova=0;
		}
	}
	int cirkularna=1;
	double zadnji;
	for(i=0;i<M-1;i++)
	{
		zadnji=mat[i][N-1];
		if(mat[i+1][0]!=zadnji) cirkularna=0;
		for(j=0;j<N-1;j++){
			if(mat[i+1][j+1]!=mat[i][j]) cirkularna=0;
		}
	}
	if(teplicova==1 && cirkularna==0) printf("Matrica je Teplicova");
	if(teplicova==0 && cirkularna==1) printf("Matrica je cirkularna");
	if(teplicova==0 && cirkularna==0) printf("Matrica nije ni cirkularna ni Teplicova");
	if(teplicova==1 && cirkularna==1) printf("Matrica je cirkularna");
	return 0;
}
