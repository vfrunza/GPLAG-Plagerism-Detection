#include <stdio.h>
int main () {
	int M, N, i, j, k, p, r, s, brkolona, brredova;
	int mat[200][200];
	do {
		printf("Unesite brojeve M i N: ");
		scanf("%d %d", &M, &N);
		if(M<1 || M>200 || N<1|| N>200) printf("Brojevi nisu u trazenom opsegu.\n");
	} while(M<1 || M>200 || N<1 || N>200);
	printf("Unesite elemente matrice: ");
	for(i=0; i<M; i++) {
		for(j=0; j<N; j++) {
			scanf("%d", &mat[i][j]);
		}
	}
	for(k=0; k<N-1; k++) { /* Trazenje istih kolona i izbacivanje */
		for(j=k+1; j<N; j++) {
			brkolona=0;
			for(i=0; i<M; i++) {
				if(mat[i][k]==mat[i][j]) brkolona++;
			}
			if(brkolona==M) {
				for(p=j; p<N; p++) {
					for(i=0; i<M; i++) {
						mat[i][p]=mat[i][p+1];
					}
				}
				N--;
				j--;
			}
		}
	}
	for(r=0; r<M; r++) { /* Trazenje istih redova i izbacivanje */
		for(i=r+1; i<M; i++) {
			brredova=0;
			for(j=0; j<N; j++) {
				if(mat[r][j]==mat[i][j]) brredova++;
			}
			if(brredova==N) {
				for(s=i; s<M; s++) {
					for(j=0; j<N; j++) {
						mat[s][j]=mat[s+1][j];
					}
				}
				M--;
			    i--;
			}
		}
	}
	printf("Nakon izbacivanja redova/kolona matrica glasi: \n");
	for(i=0; i<M; i++) {
		for(j=0; j<N; j++) {
			printf("%5d", mat[i][j]);
		}
		printf("\n");
	}
	return 0;
}