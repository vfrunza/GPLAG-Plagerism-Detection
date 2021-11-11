#include <stdio.h>

int main() {
	int M, N, i, j, k, l, o, brojac=0;
	int matrica[201][201];
	/* unosenje dimenzija matrice */
	do {
		printf("Unesite brojeve M i N: ");
		scanf("%d %d", &M, &N);
		if(M>200 || N>200 || M<=0 || N<=0)
			printf("Brojevi nisu u trazenom opsegu.\n");
	}
	while (M>200 || N>200 || M<=0 || N<=0);
	/* unosenje elemenata matrice */
	printf("Unesite elemente matrice: ");
	for (i=0; i<M; i++) {
		for (j=0; j<N; j++) {
			scanf("%d", &matrica[i][j]);
		}
	}
	/* provjera da li postoje medjusobno isti redovi */
	for (i=0; i<M; i++) {
		for(k=i+1; k<M; k++) {
			for (j=0; j<N; j++) {
				if (matrica[i][j]==matrica[k][j]) brojac++;
			}
			if (brojac==N) {
				/* izbacivanje reda koji je jednak jednom od prehodnih iz matrice */
				for(l=k; l<M-1; l++) {
				for(o=0; o<N; o++) {
				matrica[l][o]=matrica[l+1][o];
				}}
				k--;
				M--;
			}
			brojac=0;
		}
	}
	/* provjera da li postoje medjusobno iste kolone */
	for (i=0; i<N; i++) {
		for (k=i+1; k<N; k++) {
			for (j=0; j<M; j++) {
				if (matrica[j][i]==matrica[j][k]) brojac++;
			}
			if (brojac==M) {
				/* izbacivanje kolone koja je jednaka jednoj od prehodnih iz matrice */
				for(l=0; l<M; l++) {
					for(o=k; o<N-1; o++) {
						matrica[l][o]=matrica[l][o+1];
					}
				}
				k--;
				N--;
			}
			brojac=0;
		}
	}
	/* ispis krajnje matrice */
	printf("Nakon izbacivanja redova/kolona matrica glasi:\n");
	for (i=0; i<M; i++) {
		for (j=0; j<N; j++) 
			printf("%5d", matrica[i][j]);
		printf("\n");
	}
	return 0;
}
