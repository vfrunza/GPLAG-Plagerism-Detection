#include <stdio.h>
#include <math.h>
#define EPSILON 0.000001
int main ()
{
	int M=0,N=0,i=0,j=0,teplicova=1,cirkularna=1;
	double elva[100][100];

	do {
		printf("Unesite M i N: ");
		scanf("%d %d",&M,&N);
		if(M<1 || N<1 || M>100 || N>100) {
			printf("Pogresan unos!\n");
		}
	} while(M<1 || N<1 || M>100 || N>100);

	printf("Unesite elemente matrice: ");

	for(i=0; i<M; i++) {
		for(j=0; j<N; j++) {
			scanf("%lf",&elva[i][j]);
		}
	}
	for(i=0; i<M-1; i++) {
		for(j=0; j<N-1; j++) {
			if(elva[i][j] != elva[i+1][j+1] || elva[i][N-1] != elva[i+1][0])
				cirkularna=0;
		}
	}
	if(!cirkularna){
		for(i=0; i<M-1; i++) {
			for(j=0; j<N-1; j++) {
				if (elva[i][j] != elva[i+1][j+1])
					teplicova=0;
			}

		}
	}
	
	if(N == 1 && M != 1)
		cirkularna=0;
	
	if(cirkularna) printf("Matrica je cirkularna");
	else if(teplicova) printf("Matrica je Teplicova");
	else printf("Matrica nije ni cirkularna ni Teplicova");
	return 0;
}