#include <stdio.h>

int max(int mat[100][100], int visina, int sirina) {
	int i, j, k, l, trazeni=0, broj_ponavljanja, max=0;
	for (i=0; i<visina; i++) {
		for (j=0; j<sirina; j++) {
			if (i==0 && j==0) trazeni=mat[0][0];
			broj_ponavljanja=0;
			/* Za svaki clan ponovo prolazimo kroz matricu i brojimo koliko se puta on ponavlja: */
			for (k=0; k<visina; k++) {
				for (l=0; l<sirina; l++) {
					if (mat[i][j]==mat[k][l]) broj_ponavljanja++;
				}
			}
			if (broj_ponavljanja>max) {
				max=broj_ponavljanja;
				trazeni=mat[i][j];
			}
			else if (broj_ponavljanja==max && mat[i][j]<trazeni) trazeni=mat[i][j];
		}
	}
	return trazeni;
}

int izbaci_kolone(int mat[100][100], int visina, int sirina, int N) {
	int i, j, k, l;
	for (i=0; i<visina; i++) {
		for (j=0; j<sirina; j++) {
			if (mat[i][j]==N) {
				for (k=0; k<visina; k++) {
					for (l=j; l<sirina-1; l++) {
						mat[k][l]=mat[k][l+1];
					}
				}
				j--;
				sirina--;
			}
		}
	}
	return sirina;
}

int main() {
	int mat[100][100], visina, sirina, i, j, broj_prolaza;
	printf("Unesite sirinu i visinu matrice: ");
	scanf("%d%d", &sirina, &visina);
	for (i=0; i<visina; i++) {
		printf("Unesite elemente %d. reda: ", i+1);
		for (j=0; j<sirina; j++) {
			scanf("%d", &mat[i][j]);
		}
	}
	broj_prolaza=1;
	sirina=izbaci_kolone(mat, visina, sirina, max(mat, visina, sirina));
	/* Funkcije pozivamo sve dok ne izbacimo sve kolone, tj. dok je sirina matrice veća od 0: */
	while (sirina!=0) {
		printf("\nNakon %d. prolaza matrica glasi:\n", broj_prolaza);
		for (i=0; i<visina; i++) {
			for (j=0; j<sirina; j++) {
				printf("%5d", mat[i][j]);
			}
			printf("\n");
		}
		broj_prolaza++;
		sirina=izbaci_kolone(mat, visina, sirina, max(mat, visina, sirina));
	}
	printf("\nNakon %d. prolaza matrica je prazna!", broj_prolaza);
	return 0;
}