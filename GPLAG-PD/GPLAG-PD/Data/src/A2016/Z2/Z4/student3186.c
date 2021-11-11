#include <stdio.h>
#include <math.h>
#define epsilon 0.0000001

int main() {
	int M, N, i, j, brojac=0, cbrojac=0;
	double mat[100][100];
	
	do {
	printf("Unesite M i N: ");
	scanf ("%d %d", &M, &N);
	if (M<1 ||M>100 ||N<1 ||N>100)
	printf ("Pogresan unos!\n");
	} while (M<1 ||M>100 ||N<1 ||N>100);
	
	printf ("Unesite elemente matrice: ");
	for (i=0; i<M; i++)
	for (j=0; j<N; j++) {
		scanf ("%lf", &mat[i][j]);
	}
	
	for (i=0; i<M-1; i++) {
		if (fabs(mat[i+1][0]-mat[i][N-1])<epsilon)
			cbrojac++;
	for (j=0; j<N-1; j++) {
		if (fabs(mat[i][j]-mat[i+1][j+1])<epsilon)
			brojac++;
		}
	}
	
	if (brojac == (M-1)*(N-1) && cbrojac == M-1)
	printf ("Matrica je cirkularna");
	else if (brojac == (M-1)*(N-1) && cbrojac != M-1)
	printf ("Matrica je Teplicova");
	else
	printf ("Matrica nije ni cirkularna ni Teplicova");
	
	return 0;
}
