#include<stdio.h>

int main ()
{

	int m,n;
	int je_jednak;
	int i,j,k,l;
	int niz[200][200];

	do {
		printf ("Unesite brojeve M i N: ");
		scanf ("%d %d", &m , &n);

		if (m<=0 || n<=0 || m>200 || n>200) {
			printf ("Brojevi nisu u trazenom opsegu.\n");
		}
	} while (m<=0 || n<=0 || m>200 || n>200);


	printf ("Unesite elemente matrice: ");

	for (i=0; i<m; i++) { /*unos elemenata*/
		for (j=0; j<n; j++) {

			scanf ("%d", &niz[i][j]);

		}
	}


	for (i=0; i<m; i++) { /*izbacivanje reda*/
		for (j=i+1; j<m; j++) {
			je_jednak=1;
			for (k=0; k<n; k++) {
				if (niz[i][k]!=niz[j][k]) {
					je_jednak=0;
				}
			}
			if (je_jednak==1) {
				for (k=j; k<m-1; k++) {
					for (l=0; l<n; l++) {
						niz[k][l]=niz[k+1][l];
					}
				}
				m--;
				j--;
			}
		}
	}

	for (i=0; i<n; i++) { /*izbacivanje kolone*/
		for (j=i+1; j<n; j++) {
			je_jednak=1;
			for (k=0; k<m; k++) {
				if (niz[k][i]!=niz[k][j]) {
					je_jednak=0;
				}
			}
			if (je_jednak==1) {
				for (k=j; k<n-1; k++) {
					for (l=0; l<m; l++) {
						niz[l][k]=niz[l][k+1];
					}
				}
				n--;
				j--;
			}
		}
	}

	printf ("Nakon izbacivanja redova/kolona matrica glasi:\n");

	for (i=0; i<m; i++) { /*ispis modifikovane matrice*/
		for (j=0; j<n; j++) {
			printf (" %4d", niz[i][j]);
		}
		printf ("\n");
	}





	return 0;
}