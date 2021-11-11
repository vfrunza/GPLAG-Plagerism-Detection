#include <stdio.h>

int main()
{
	int i, j, k, l, m, n, M, N,V, A[100][100], B[100][100], C[100][100], brojaciA[1000]= {0}, maxA;

	do {
		printf ("Unesite brojeve M i N: ");
		scanf ("%d %d", &M, &N);
	} while (M>100 || N>100);

	printf ("Unesite clanove matrice A: ");
	for (i=0; i<M; i++) {
		for (j=0; j<N; j++) {
			scanf ("%d", &A[i][j]);
		}
	}

	printf ("Unesite clanove matrice B: ");
	for (k=0; k<M; k++) {
		for (l=0; l<N; l++) {
			scanf ("%d", &B[k][l]);
		}
	}

	printf ("Unesite clanove matrice C: ");
	for (m=0; m<M; m++) {
		for (n=0; n<N; n++) {
			scanf ("%d", &C[m][n]);
		}
	}

	maxA=A[0][0];
	for (i=0; i<M; i++) {
		for (j=0; j<N; j++) {
			if (A[i][j]>maxA) {
				maxA=A[i][j];
			}
		}
	}
	V=maxA+1;

	for (i=0; i<M; i++) {
		for (j=0; j<N; j++) {
			for (k=0; k<V; k++) {
				if (brojaciA[k]==A[i][j]) {
					brojaciA[k]++;
				}
			}
		}
	}
	for (i=0; i<V; i++) {
		if (brojaciA[i]!=0) {
			printf ("%d", brojaciA[i]);
		}
	}



	return 0;
}
