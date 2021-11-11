#include <stdio.h>

int main()
{
	int M,N,i,j;
	double mat[100][100] = {0};
	int tep=1;
	int cir=1;
	do {
		printf("Unesite M i N: ");
		scanf("%d %d",&M,&N);
		if(M>100  || N>100 || M<=0 || N<=0) 
			printf("Pogresan unos!\n");
	} while(M>100 || N>100 || M<=0 || N<=0);
	
	printf("Unesite elemente matrice: ");
	for(i=0; i<M; i++) {
		for(j=0; j<N; j++) {
			scanf("%lf",&mat[i][j]);
		}
	}
	for(i=1; i<M; i++) {
		for(j=1; j<N; j++) {
			if(mat[i][j]!=mat[i-1][j-1]) {
				tep=0;
				cir=0;
			}
		}
	}

	if (tep==1) {
		for(i=1; i<M; i++) {
			if(mat[i][0]!=mat[i-1][N-1]) 
				cir=0;
		}
	}

	if (tep==0 && cir==0) 
		printf("Matrica nije ni cirkularna ni Teplicova");
	else if(tep==1 && cir==0 ) 
		printf("Matrica je Teplicova");
	else  if(cir==1 && tep==1 )
		printf("Matrica je cirkularna");
	return 0;
}
