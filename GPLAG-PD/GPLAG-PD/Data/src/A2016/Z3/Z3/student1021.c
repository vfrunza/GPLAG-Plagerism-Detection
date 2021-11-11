#include <stdio.h>
#define VISINA 200
#define SIRINA 200 

int main () {
	int M, N, i=0, j=0, k=0, l=0, m=0, n=0, jednaki=0, mat[VISINA][SIRINA];

	/* Unos dimenzija matrice M*N */
	do {
		printf ("Unesite brojeve M i N: ");
		scanf ("%d %d", &M, &N);
		if (M>200 || M<0 || M==0 || N>200 || N<0 || N==0) {
			printf ("Brojevi nisu u trazenom opsegu.\n");
		}
		else {
			break;
		}
	} while (M>200 || M<0 || M==0 || N>200 || N<0 || N==0);
	
	/* Unos elemenata matrice M*N */
	printf ("Unesite elemente matrice: ");
	for (i=0; i<M; i++) {
		for (j=0; j<N; j++) {
			scanf ("%d", &mat[i][j]);
		}
	}
	
	/* Ispitivanje da li se u matrici M*N pojavljuju jednaki redovi */
		for (i=0; i<M; i++) {
			for (k=i+1; k<M; k++) {
				jednaki=1;
					for (j=0; j<N; j++) {
						if (mat[i][j]!=mat[k][j]) {
							jednaki=0;
						}
					}
	/* Izbacivanje jednakih redova matrice M*N */
					if (jednaki==1) {
						for (n=k+1; n<M; n++) {
							for (j=0; j<N; j++) {
								mat[n-1][j]=mat[n][j];
							}
						}
						M--;
						k--;
					}
			}
		}
		
	/* Ispitivanje da li se u matrici M*N pojavljuju jednake kolone */	
		for (j=0; j<N; j++) {
			for (l=j+1; l<N; l++) {
				jednaki=1;
					for (i=0; i<M; i++) {
						if (mat[i][j]!=mat[i][l]) {
							jednaki=0;
						}
					}
	/* Izbacivanje jednakih kolona matrice M*N */
					if (jednaki==1) {
						for (m=l+1; m<N; m++) {
							for (i=0; i<M; i++) {
								mat[i][m-1]=mat[i][m];
							}
						}
						N--;
						l--;
					}
			}
		}
		
	/* Ispis matrice nakon izbacivanja odgovarajucih redova/kolona */
		printf ("Nakon izbacivanja redova/kolona matrica glasi: \n");
		for (i=0; i<M; i++) {
			for (j=0; j<N; j++) {
				printf ("%5d", mat[i][j]);
			}
			printf ("\n");
		}
	return 0;
}