#include <stdio.h>

int main() {
	int i, j, M, N; 
	int Teplicova=1;
	int cirkularna=1;
	double mat[100][100]={0};
	
	do 
	{
		printf("Unesite M i N: ");
		scanf("%d %d", &M, &N);
		if(M>100 || N>100 || M<=0 || N<=0) printf("Pogresan unos!\n");
	} 	while(M>100 || N>100 || M<=0 || N<=0);

	printf("Unesite elemente matrice: ");
	for(i=0; i<M; i++) {
		for(j=0; j<N; j++) {
			scanf("%lf", &mat[i][j]);
		}
	}
	for(i=0; i<M; i++) {
		for(j=0; j<N; j++) {
			if((i==j && mat[i][j]!=mat[0][0]))
			{
				Teplicova=0; break;
			}
				if((i!=j && mat[i][j]!=mat[i+1][j+1] && i<(M-1) && j<(N-1)))
				{
					Teplicova=0; break;
				}
		}
			if(Teplicova==0) break;
	}
	for(i=0; i<M; i++) 
	{
		for(j=0; j<N; j++) 
		{
			if(Teplicova==0 || i<(M-1) && j<=(N-1) && mat[i][N-1]!=mat[i+1][0])
			{
				cirkularna=0; break;
			}
		}
			if(cirkularna==0) break;
	}

	if(cirkularna==1) printf("Matrica je cirkularna");
	else if(Teplicova==1) printf("Matrica je Teplicova");
	else if(cirkularna==0 && Teplicova==0) printf("Matrica nije ni cirkularna ni Teplicova");
	
	return 0;
}