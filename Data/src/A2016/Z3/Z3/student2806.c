#include <stdio.h>
#define visina 200
#define sirina 200
int main()
{
	int m, n, mat[visina][sirina], i, j, k, L, l, a, br=0;
	/*UNOS DIMENZIJA MATRICE*/
	do {
		printf("Unesite brojeve M i N: ");
		scanf("%d %d", &m, &n);
		if (m>200 || m<1 || n>200 || n<1) {
			printf("Brojevi nisu u trazenom opsegu.\n");
		}
	} while (m>200 || m<1 || n>200 || n<1);
	/*UNOS DIMENZIJA MATRICE*/
	printf("Unesite elemente matrice: ");
	for (i=0; i<m; i++) {
		for (j=0; j<n; j++) {
			scanf("%d", &mat[i][j]);
		}
	}
	/*RAD SA REDOVIMA*/
	i=0;
	do {
		for (j=i+1; j<m; j++) {
			for (k=0; k<n; k++) {
				if (mat[i][k]==mat[j][k]) br++;
				if (br==n) {
					for (l=j; l<m-1; l++) {
						for (L=0; L<n; L++) {
							mat[l][L]=mat[l+1][L];
						}
					}
					j--;
					m--;
				}
			}
			br=0;
		}
		i++;
	} while (i<m);
	/*RAD SA KOLONAMA*/
	i=0;
	do {
		for (a=i+1; a<n; a++) {
			for (j=0; j<m; j++) {
				if (mat[j][i]==mat[j][a]) br++;
				if (br==m) {
					for (l=0; l<m; l++) {z
						for (L=a; L<n-1; L++) {
							mat[l][L]=mat[l][L+1];
						}
					}
					a--;
					n--;
				}
			}
			br=0;
		}
		i++;
	} while (i<n);



	printf ("Nakon izbacivanja redova/kolona matrica glasi:\n");
	for (i=0; i<m; i++) {
		for (j=0; j<n; j++) {
			printf ("%5d", mat[i][j]);
		}
		printf("\n");
	}
	return 0;
}
