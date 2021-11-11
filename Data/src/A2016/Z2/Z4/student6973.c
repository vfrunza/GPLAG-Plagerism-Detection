#include <stdio.h>
#define EPS 0.00001
#include <math.h>

int main() {
	int M=0,N=0,i=0,j=0;
	double mat[100][100];
	int teplicova = 1, cirkularna = 1;
	do {
		printf("Unesite M i N: ");
		scanf("%d %d", &M, &N);
		if(M <=0 || M > 100 || N <= 0 || N > 100) printf("Pogresan unos!\n");
	} while(M <=0 || M > 100 || N <= 0 || N > 100);
	printf("Unesite elemente matrice: ");
	for(i = 0; i < M; i++) {
		for(j = 0; j < N; j++) {
			scanf("%lf",&mat[i][j]);
		}
	}
	/*for(i = 0; i < M; i++) {
		for(j = 0; j < N; j++) {
			printf("%5d",mat[i][j]);
		}
		printf("\n");
	}*/
	for(i = 1; i < M; i++) {
		for(j = 1; j < N; j++) {
			if(fabs(mat[i][j] - mat[i - 1][j - 1]) > EPS) {
				teplicova = 0;
				printf("Matrica nije ni cirkularna ni Teplicova");
				return 0;
			}
		}
	}
	if(teplicova == 1) {
		for(i = 1; i < M; i++) {
			if(fabs(mat[i][0] - mat[i - 1][N - 1]) > EPS){
				cirkularna = 0;
				break;
			}
		}
		if(cirkularna == 1) printf("Matrica je cirkularna");
		if(cirkularna == 0) printf("Matrica je Teplicova");
	}
	return 0;
}
