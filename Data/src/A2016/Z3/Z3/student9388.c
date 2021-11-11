#include <stdio.h>

int main() {
	/*printf("Zadaća 3, Zadatak 3");*/

	int M, N, mat[200][200], i, j, k, l, r, p;
	
	/*Unesite prirodne brojeve M i N koji su manji ili jednaki 200.*/
	
	printf ("Unesite brojeve M i N: ");
	do {
		scanf ("%d %d", &M, &N);
		if (M<1 || M>200 || N<1 || N>200) {
			printf ("Brojevi nisu u trazenom opsegu.\n");
			printf ("Unesite brojeve M i N: ");
			continue;
		}
	}
	while (M<1 || M>200 || N<1 || N>200);
	
	printf ("Unesite elemente matrice: ");
	
	for (i=0; i<M; i++) {
		for (j=0; j<N; j++) {
			scanf("%d", &mat[i][j]);
		}
	}
	
	/*Izbacivanje redova koji se ponavljaju.*/
	
	for (i=0; i<M; i++) {
		for (k=i+1; k<M; k++) {
			p=1;
			for (j=0; j<N; j++) {
				if (mat[i][j]!=mat[k][j]) {
					p=0;
					break;
				}
			}
			/*Kada se završi j petlja ispitali smo jesu li redovi isti. Ako jesu, slijedi izbacivanje.*/
			if (p==1) {
				for (l=k; l<M-1; l++) {
					for (r=0; r<N; r++) {
						mat[l][r]=mat[l+1][r];
					}
				}
				M--;
				k--;
			}
		}
	}
			
	/*Izbacivanje kolona koje se ponavljaju.*/
	
	for (i=0; i<N; i++) {
		for (k=i+1; k<N; k++) {
			p=1;
			for (j=0; j<M; j++) {
				if (mat[i][j]!=mat[k][j]) {
					p=0;
					break;
				}
			}
			/*Kada se završi j petlja ispitali smo jesu li kolone iste. Ako jesu, slijedi izbacivanje.*/
			if (p==1) {
				for (l=k; l<N-1; l++) {
					for (r=0; r<M; r++) {
						mat[r][l]=mat[r][l+1];
					}
				}
				N--;
				k--;
			}
		}
	}
		
	printf("Nakon izbacivanja redova/kolona matrica glasi:\n");

	for (i=0; i<M; i++) {
		for (j=0; j<N; j++) {
			printf("%5d", mat[i][j]);
		}
		printf ("\n");
	}

	return 0;
}


