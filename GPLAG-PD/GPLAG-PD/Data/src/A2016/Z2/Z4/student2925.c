#include <stdio.h>

int main() {
	double mat[100][100];
	int M,N,prett,pretc,i,j;
	do
	{
		printf("Unesite M i N: ");
	scanf("%d%d",&M,&N);
	if(M>100 || N>100 ||M<=0 ||N<=0)printf("Pogresan unos!\n");
	
	}while (M>100 || N>100 ||M<=0 ||N<=0 );
	printf("Unesite elemente matrice: ");
	for(i=0; i<M; i++)
	for(j=0; j<N; j++)
	    scanf("%lf",&mat[i][j]);
prett=1;
for(i=1; i<M; i++)
	for(j=1; j<N; j++) 
	if(mat[i][j]!=mat[i-1][j-1])
	prett=0;
	
	if(prett==1)
	{
		pretc=1;
		for(i=1; i<M; i++)
		     if(N-i>=0)
			if(mat[i][0]!=mat[0][N-i]) 
			pretc=0;
		if(pretc==1)printf("Matrica je cirkularna");	
		else printf("Matrica je Teplicova");	
	}else
	{
	printf("Matrica nije ni cirkularna ni Teplicova");	
	}
	return 0;
}
