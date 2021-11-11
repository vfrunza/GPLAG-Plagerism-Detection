#include <stdio.h>

int main() {
	
	int M, N, i, j;
	double mat[100][100];
	
	do {
		printf("Unesite M i N: ");
		scanf("%d %d", &M, &N);
		if(M<1 || M>100 || N<1 || N>100) printf("Pogresan unos!\n");
		
	} 
	while (N<1 || M>100 || M<1 || N>100);
	printf("Unesite elemente matrice: ");
	for (i=0;i<M;i++)
	{
		for(j=0;j<N;j++) 
		{ 
			scanf("%lf", &mat[i][j]);
		}
	}
	int c;
	c=1;
	for(i=0;i<M-1;i++) 
	{
		for(j=0;j<N-1;j++)
		{
			if(mat[i][j]!=mat[i+1][j+1] || mat[i][N-1]!=mat[i+1][0]) {
				c=0;
				break;
			}
    	}
			
	}
	int t;
	t=1;
	for(i=0;i<M-1;i++) 
	{
		for(j=0;j<N-1;j++)
		{
			if(mat[i][j]!=mat[i+1][j+1]) {
				t=0;
				break;
			}
    	}
			
	}
	if((t==1) && (c==0)) printf("Matrica je Teplicova");
    else if((c==1) && (t==1)) printf("Matrica je cirkularna");
	else printf("Matrica nije ni cirkularna ni Teplicova");
	
	return 0;
}
