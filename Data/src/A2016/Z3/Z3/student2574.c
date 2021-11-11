#include <stdio.h>
#define S 200
#define V 200
int main() {
	int	i=0;
	int j=0, k=0, f=0, g=0;
	int M=0, N=0, log=0;
	int A[S][V];
	do {
		printf ("Unesite brojeve M i N: ");
		scanf("%d %d",&M,&N);
		if (M<=0 || N<=0 || M>200 || N>200) {
		printf ("Brojevi nisu u trazenom opsegu.\n");
		}
	}
	while (M<=0 || N<=0 || M>200 || N>200);
	printf ("Unesite elemente matrice: ");
	for (i=0; i<M; i++) {
		for (j=0; j<N; j++) {
			scanf("%d",&A[i][j]);
		}
	}
	/* Izbacivanje istih redova i istih kolona uz očuvanje redoslijeda*/
	/* Ostavljamo prvi red/kolonu koja je jednaka*/
	for (i=0; i<M-1; i++) {
		for (j=1; j<M-i; j++) {
			for (k=0; k<N; k++) {
				if (A[i][k]==A[i+j][k]) {
					log++;
				}
			}
			if (log==N) {
				if (j==M-1) {
					M--;
					log=0;
				}
				else {
					for (f=j; f<M-1; f++) {
						for (g=0; g<N; g++) {
							A[f+i][g]=A[f+i+1][g];
						}
					}
					M--;
					log=0;
					if (j=M-i) 
						i--;
				}
			}
			else 
				log=0;
		}
	}
	log=0;
	for (i=0; i<N-1; i++) {
		for (j=1; j<N-i; j++) {
			for (k=0; k<M; k++) { 
				if (A[k][i]==A[k][i+j]) {
					log++;
				}
			}
			if (log==M) {
				if (i+j==N-1) {
					N--;
					log=0;
				}
				else {
					for (f=j; f<N-1; f++) {
						for (g=0; g<N; g++) { 
							A[g][f+i]=A[g][f+i+1];
						}
					}
					N--;
					log=0;
					j--;
				}
			}
			else 
				log=0;
		}
	}
	printf ("Nakon izbacivanja redova/kolona matrica glasi: \n");
	for (i=0; i<M;	i++) {
		for (j=0; j<N; j++)	{
			printf ("%5d",A[i][j]);
		}
		printf ("\n");
	}
	return 0;
}

	
