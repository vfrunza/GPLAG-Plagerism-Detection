#include <stdio.h>

int main () {
	int i, j, M, N, A[100][100], B[100][100], C[100][100], brojaci_A[10000]={0}, brojaci_B[10000]={0}, brojaci_C[10000]={0}, uslov;
	
	do {
		printf ("Unesite brojeve M i N: ");
		scanf ("%d %d", &M, &N);
	} while (M<0 || M>100 || N<0 || N>100);
	
	printf ("Unesite clanove matrice A: ");
	for (i=0;i<M;i++) {
		for (j=0;j<N;j++) {
			scanf ("%d", &A[i][j]);
		}
	}
	
	printf ("Unesite clanove matrice B: ");
	for (i=0;i<M;i++) {
		for (j=0;j<N;j++) {
			scanf ("%d", &B[i][j]);
		}
	}
	
	printf ("Unesite clanove matrice C: ");
	for (i=0;i<M;i++) {
		for (j=0;j<N;j++) {
			scanf ("%d", &C[i][j]);
		}
	}
	
	for (i=0;i<M;i++) {
		for (j=0;j<N;j++) {
			brojaci_A[A[i][j]]++;
			brojaci_B[B[i][j]]++;
			brojaci_C[C[i][j]]++;
		}
	}
	
	uslov = 1;
	for (i=0;i<M;i++) {
		for (j=0;j<N;j++) {
			if (brojaci_C[C[i][j]] != brojaci_A[A[i][j]] || brojaci_B[B[i][j]] != brojaci_A[A[i][j]]) {
				uslov = 0;
				break;
			}
		}
	}
	
	if (uslov) printf ("DA");
	else printf ("NE");
	printf ("\n");
	return 0;
}