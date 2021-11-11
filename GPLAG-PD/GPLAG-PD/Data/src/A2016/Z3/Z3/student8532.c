#include <stdio.h>
#define vel 200

/* funkcija koja izbacuje red matrice i kao rezultat vraca novi broj redova */
int izbaci_red (int mat[vel][vel], int red, int kolona) {
	int i, j, k, l, brojac;
	
	for (i=0; i<red; i++) {
		for (j=i+1; j<red; j++) {
			brojac = 0;
			for (k=0; k<kolona; k++) {
				if (mat[i][k] == mat[j][k])
				brojac ++;
			}
			if (brojac == kolona) {
				for (k=0; k<kolona; k++) {
					for (l=j; l<red-1; l++)
					mat[l][k] = mat[l+1][k];
				}
					red--; 
					j--;
			}
		}
	}
	return red;
}

/* funkcija koja izbacuje kolonu matrice i kao rezultat vraca novi broj kolona */
int izbaci_kolonu (int mat[vel][vel], int red, int kolona) {
	int i, j, k, l, brojac;
	
	for (i=0; i<kolona; i++) {
		for (j=i+1; j<kolona; j++) {
			brojac = 0;
			for (k=0; k<red; k++) {
				if (mat[k][i] == mat[k][j])
				brojac ++;
			}
			if (brojac == red) {
				for (k=0; k<red; k++) {
					for (l=j; l<kolona-1; l++)
					mat[k][l] = mat[k][l+1];
				}
					kolona--;
					j--;
			}
		}
	}
	return kolona;
}

int main() {
	int m, n, i, j, mat[vel][vel];
	
	do {
	printf("Unesite brojeve M i N: ");
	scanf ("%d %d", &m, &n);
	
	if (m>200 || n>200 || m<1 || n<1)
	printf ("Brojevi nisu u trazenom opsegu.\n");
	} while (m>200 || n>200 || m<1 || n<1);
	
	printf ("Unesite elemente matrice: ");
	for (i=0; i<m; i++)
		for (j=0; j<n; j++) {
			scanf ("%d", &mat[i][j]);
	}
	
	m = izbaci_red(mat, m, n);
	n = izbaci_kolonu(mat, m, n);
	
	printf ("Nakon izbacivanja redova/kolona matrica glasi: \n");
	for (i=0; i<m; i++) {
		for (j=0; j<n; j++) {
			printf ("%5d", mat[i][j]);
		}	printf ("\n");
	}
	
	return 0;
}