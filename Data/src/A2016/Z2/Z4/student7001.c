#include <stdio.h>
#define EPSILON 0.001
int main() {
	int mat[100][100], M, N, i, j, teplicova=1, cirkularna=1;
	do {
	printf ("Unesite M i N: ");
	scanf ("%d %d", &M, &N);
	if (M<=0 || M>100 || N<=0 || N>100) printf ("Pogresan unos!\n");
	} while (M<=0 || M>100 || N<=0 || N>100);
	printf ("Unesite elemente matrice: ");
	for (i=0; i<M; i++) {
		for (j=0; j<N; j++) {
			scanf ("%f", &mat[i][j]);
		}
	}
	for (i=0; i<M-1; i++) {
		for (j=0; j<N-1; j++) {
			if (mat[i][j]!=mat[i+1][j+1]) {
				teplicova=0;
			}
		}
	}
	if (teplicova) {
	for (i=0; i<M-1; i++) {
		for (j=0; j<N-1; j++) {
			if (mat[i][N-1]!=mat[i+1][0]) {
				cirkularna=0;
			}
		}
	}
	}
	if (cirkularna) printf ("Matrica je cirkularna");
	else if (cirkularna==0 && teplicova==1) printf ("Matrica je Teplicova");
	else printf ("Matrica nije ni cirkularna ni Teplicova");
	return 0;
}