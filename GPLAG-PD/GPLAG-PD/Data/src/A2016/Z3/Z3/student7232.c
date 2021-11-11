#include <stdio.h>
int main () {
	int mat[200][200], n, m, M, N, x, y, p=0, temp;
	int brojac=0;
	
	/*UNOS DIMENZIJA*/
	do {
		printf ("Unesite brojeve M i N: ");
		scanf ("%d %d", &M, &N);
		if(M<1 || M>200 || N<1 || N>200) {
			printf ("Brojevi nisu u trazenom opsegu.\n");
		}
	} while (M<1 || M>200 || N<1 || N>200);
	
	/*UNOS ELEMENATA*/
	printf ("Unesite elemente matrice: ");
	for (n=0; n<M; n++) {
		for (m=0; m<N; m++) {
			scanf ("%d", &mat[n][m]);
		}
	}
	
	/*POREĐENJE I IZBACIVANJE REDOVA*/
	for (n=0; n<M; n++) {
		for (m=n+1; m<M; m++) {
			brojac=0;
			for (p=0; p<N; p++) {
				if (mat[n][p]==mat[m][p]) {
					brojac++;
				} if (brojac==N) {
					for (y=m+1; y<M; y++) {
						for (x=0; x<N; x++) {
							temp=mat[y-1][x];
							mat[y-1][x]=mat[y][x];
							mat[y][x]=temp;
						}
					}
					M--;
					m--;
				}
			}
		}
	}
	
	/*POREĐENJE I IZBACIVANJE KOLONA*/
	for (n=0; n<N; n++) {
		for (m=n+1; m<N; m++) {
			brojac=0;
			for (p=0; p<M; p++) {
				if (mat[p][n]==mat[p][m]) {
					brojac++;
				} if (brojac==M) {
					for (y=m+1; y<N; y++) {
						for (x=0; x<M; x++) {
							temp=mat[x][y-1];
							mat[x][y-1]=mat[x][y];
							mat[x][y]=temp;
						}
					}
					N--;
					m--;
				}
			}
		}
	}
	
	/*ISPIS MATRICE*/
	printf ("Nakon izbacivanja redova/kolona matrica glasi: \n");
	for (n=0; n<M; n++) {
		for (m=0; m<N; m++) {
			printf ("%5d", mat[n][m]);
		}
		printf ("\n");
	}
	return 0;
}