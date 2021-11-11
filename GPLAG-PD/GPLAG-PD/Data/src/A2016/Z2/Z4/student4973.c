#include <stdio.h>

int main()
{
	int M,N,i,j;
	double mat[100][100];
	int cirkularna=0;
	do {

		printf("Unesite M i N: ");
		scanf("%d%d",&M,&N);
		if(M<=0 || M>100 || N<=0 || N>100) printf("Pogresan unos!\n");
	} while(M<=0 || M>100 || N<=0 || N>100);
	printf("Unesite elemente matrice: ");
	for(i=0; i<M; i++) {
		for(j=0; j<N; j++) {
			scanf("%lf",&mat[i][j]);
		}
	}
	int teplicova=1;
	for(i=0; i<M-1; i++) {
		for(j=0; j<N-1; j++) {
			if(mat[i][j]!=mat[i+1][j+1])
				teplicova=0;
		}
	}
	if(teplicova==1) {
		cirkularna=1;
		for(i=0; i<M-1; i++) {
			for(j=0; j<N-1; j++) {
				if(mat[i][N-1]!=mat[i+1][0])
					cirkularna=0;
			}
		}
	}
	if(cirkularna==1) printf("Matrica je cirkularna");
	else if(teplicova==1) printf("Matrica je Teplicova");
	else printf("Matrica nije ni cirkularna ni Teplicova");
	return 0;
}
