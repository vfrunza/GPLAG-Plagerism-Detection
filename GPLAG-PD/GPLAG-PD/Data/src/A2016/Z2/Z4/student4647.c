#include <stdio.h>
#include <math.h>
#define EPSILON 0.0001

int main() {
	long M, N, i, j, T=0, C=0;
	double Mat[100][100]={{0}, {0}};

	do {
		printf("Unesite M i N: ");
		scanf("%ld %ld",&M, &N);
		if (M<=0 || N<=0 || M>100 || N>100)
		printf("Pogresan unos!\n");
	}
	while (M<=0 || M>100 || N<=0 || N>100);
	printf("Unesite elemente matrice: ");
	for (i=0; i<M; i++) {
		for (j=0; j<N; j++) {
			scanf("%lf", &Mat[i][j]); }}
	for (i=0; i<M; i++) {
	for (j=0; j<N; j++) {
			if (j<N-1 && i<M-1 && fabs(Mat[i][j]-Mat[i+1][j+1])<EPSILON) T++;
			if (j<N-1 && i<M-1 && fabs(Mat[i][j]-Mat[i+1][j+1])<EPSILON && fabs(Mat[i][N-1]-Mat[i+1][0])<EPSILON) C++;
		}
	}
	if (N==1 && M!=1) printf("Matrica je Teplicova");
	else if (C==(M-1)*(N-1)) printf("Matrica je cirkularna");
	else if (T==(M-1)*(N-1)) printf("Matrica je Teplicova");
	else printf("Matrica nije ni cirkularna ni Teplicova");
	return 0;
}
