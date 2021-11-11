#include <stdio.h>

int main() { 
	
	int A[100][100], B[100][100], C[100][100], i, j, M, N, brojac1, brojac2, brojac3,ispisiDA, k, l;
	brojac1=0;
	brojac2=0;
	brojac3=0;
	ispisiDA=1;
	
	do {
		printf ("Unesite brojeve M i N: ");
		scanf ("%d %d", &M, &N);
	}
	while (M>100 || M<0 || N>100 || N<0);
	
	printf ("Unesite clanove matrice A: ");
	for (i=0; i<M; i++) {
		for (j=0; j<N; j++) {
			scanf ("%d", &A[i][j]);
		}
	}
	
	printf ("Unesite clanove matrice B: ");
	for (i=0; i<M; i++) {
		for (j=0; j<N; j++) {
			scanf ("%d", &B[i][j]);
		}
	}
	
	printf ("Unesite clanove matrice C: ");
	for (i=0; i<M; i++) {
		for (j=0; j<N; j++) {
			scanf ("%d", &C[i][j]);
		}
	}
	
	
	for (i=0; i<M; i++) {
		for (j=0; j<N; j++) {
			for (k=0; k<M; k++) {
				for (l=0; l<N; l++) {
					if (A[i][j]==A[k][l]) brojac1++;
					
				}
			}
			for (k=0; k<M; k++) {
				for (l=0; l<N; l++) {
					if (A[i][j]==B[k][l]) brojac2++;
				}
			}
			for (k=0; k<M; k++) {
				for (l=0; l<N; l++) {
					if (A[i][j]==C[k][l]) brojac3++;
				}
			}
			if (brojac1!=brojac2 || brojac1!=brojac3) {
			ispisiDA=0;
			break;
			}
		}
	}
	
	if (ispisiDA) printf ("DA");
	else printf ("NE");
	
return 0;
}