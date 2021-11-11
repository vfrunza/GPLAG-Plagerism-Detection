#include <stdio.h>

int main() {
	int matr[20][20],i,j,M,N,k,p=0,l,m;
	do {
		printf("Unesite brojeve M i N: ");
		scanf("%d %d", &M, &N);
		if (M<=0 || N<=0 || M>200 || N>200) printf("Brojevi nisu u trazenom opsegu.\n");
	} while (M<=0 || N<=0 || M>200 || N>200);
	printf("Unesite elemente matrice: ");
	for(i=0; i<M; i++) {
		for(j=0; j<N; j++) {
			scanf("%d", &matr[i][j]);
		}
	}
	/* Petljom se prolazi kroz elemente matrice i trazi da li postoji red (u sljedećoj petlji kolona) jednak nekom drugom redu/koloni. Za svaki clan jednak u ta dva reda/kolone,
	brojac se povecava za 1, i ako je na kraju brojac jednak ukupnom broju clanova jednog reda/kolone vrsi se izbacivanje drugog reda/kolone od ta dva jednaka reda/kolone. */
	for (i=0; i<M-1; i++) {
		for (k=0; k<M-i-1; k++) {
			for (j=0; j<N; j++) {
				if (matr[i][j]==matr[i+k+1][j]) p++;
			}
			if (p==N) { 
				for (l=0; l<M-1-i-k; l++) {
					for (j=0; j<N; j++) {
						matr[l+k+i+1][j]=matr[l+1+1+i+k][j];
					}
				}
				M--;
				k--;
			}
				p=0;
		}
	}
	p=0;
	for (j=0; j<N-1; j++) {
		for (k=0; k<N-j-1; k++) {
			for (i=0; i<M; i++) {
				if (matr[i][j]==matr[i][j+k+1]) p++;
			}
			if (p==M) { 
				for (m=0; m<M; m++) {
					for (l=0; l<N-j-k-1; l++) {
						matr[m][j+k+1+l]=matr[m][j+1+k+1+l];
					}
				}
				N--;
				k--;
			}
				p=0;
		}
	}
	printf("Nakon izbacivanja redova/kolona matrica glasi:\n");
	for(i=0; i<M; i++) {
		for(j=0; j<N; j++) {
			printf("%5d", matr[i][j]);
		}
		printf("\n");
	}
	return 0;
}
