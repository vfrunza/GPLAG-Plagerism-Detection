#include <stdio.h>

int main() {
	int M, N, A[100][100], B[100][100], C[100][100], i, j, k, l, rjesenje=1, brojaczaA, brojaczaB, brojaczaC;
	
	do {
		printf ("Unesite brojeve M i N: ");
		scanf ("%d %d", &M, &N);
	} while (M>100 || N>100 || M<0 || N<0);
	
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
			brojaczaA=0;
			brojaczaB=0;
			brojaczaC=0;
			for(k=0; k<M; k++){
				for(l=0; l<N; l++){
					if(A[i][j] == A[k][l]) brojaczaA++;
					if(A[i][j] == B[k][l]) brojaczaB++;
					if(A[i][j] == C[k][l]) brojaczaC++;
				}
			}
			if(brojaczaA != brojaczaB || brojaczaA != brojaczaC) rjesenje = 0;
			if(!rjesenje) break;
		}
		if(!rjesenje) break;
	}

	if(rjesenje) printf("DA\n");
	else printf("NE\n");
	
	
	
	return 0;
}
