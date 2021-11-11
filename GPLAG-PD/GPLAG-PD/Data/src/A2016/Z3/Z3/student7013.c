#include <stdio.h>
int main ()
{
	int mat [200][200];
	int M, N, i, j, k, p;
	do {
		printf ("\nUnesite brojeve M i N: ");
		scanf ("%d%d", &M, &N);
		if (M<1 || M>200 || N<1 || N>200) {
			printf ("Brojevi nisu u trazenom opsegu.");
		}
		else {
			break;
		}
	}
	while (1);
	printf ("Unesite elemente matrice: ");
	for (i=0; i<M; i++) {
		for (j=0; j<N; j++) {
			scanf ("%d", &mat[i][j]);
		}
	}
	
	/* redovi */
	for (i=0; i<M-1; i++) {
		for (k=i+1; k<M ; k++) {
			int jednak=1;
			for (j=0; j<N; j++) {
				if (mat[i][j]!=mat[k][j]) {
					jednak=0;
				}
			}
			if (jednak==1) {
				for (p=k; p<M-1; p++) {
					for (j=0; j<N; j++) {
						mat[p][j]=mat[p+1][j];
					}
				}
				k--;
				M--;
			}
		}
	}
	
	/* kolone */
	for (j=0; j<N-1; j++) {
		for (k=j+1; k<N; k++) {
			int ekvivalentan=1;
			for (i=0; i<M; i++) {
				if (mat[i][j]!=mat[i][k]) {
					ekvivalentan=0;
				}
			}
			if (ekvivalentan==1) {
				for (i=0; i<M; i++) {
					for (p=k; p<N-1; p++) {
						mat[i][p]=mat[i][p+1];
					}
				}
				k--;
				N--;
			}
		}
	}
	printf ("Nakon izbacivanja redova/kolona matrica glasi:\n");
	for (i=0; i<M; i++) {
		for (j=0; j<N; j++) {
			printf ("%5.0d", mat[i][j]);
		}
		printf ("\n");
	}
	return 0;
}