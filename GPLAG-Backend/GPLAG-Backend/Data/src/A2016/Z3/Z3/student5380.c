#include <stdio.h>

int main()
{
	/*unos*/
	int mat[200][200] = {0} ,M,N,i,j,brojac1, brojac2, ponr=1,ponk=1;
	do {
		printf ("Unesite brojeve M i N: ");
		scanf ("%d %d", &M, &N);
		if ((M<1) || (M>200) || (N<1) || (N>200)) {
			printf ("Brojevi nisu u trazenom opsegu.\n");
		}
	} while ((M<1) || (M>200) || (N<1) || (N>200));
	printf ("Unesite elemente matrice: ");
	for (i=0; i<M; i++) {
		for (j=0; j<N; j++)
			scanf ("%d", &mat[i][j]);
	}

	/*Redovi*/
	for (i=0; i<M; i++) {
		for (j=i+1; j<M; j++) {
			ponr=1;
			for (brojac1=0; brojac1<N; brojac1++) {
				if (mat[i][brojac1] != mat[j][brojac1])
					ponr=0;
			}
			if (ponr == 1) {
				for (brojac1=j; brojac1<M; brojac1++) {
					for (brojac2=0; brojac2<N; brojac2++) {
						mat[brojac1][brojac2]=mat[brojac1+1][brojac2];
					}


				}
				M--;
				j--;
			}

		}
	}
	/*kolone*/
	for (i=0; i<N; i++) {
		for (j=i+1; j<N; j++) {
			ponk=1;
			for (brojac1=0; brojac1<M; brojac1++) {
				if (mat[brojac1][i] != mat[brojac1][j])
					ponk=0;
			}

			if  (ponk==1) {
				for (brojac1=j; brojac1<N-1; brojac1++) {
					for (brojac2=0; brojac2<M; brojac2++) {
						mat[brojac2][brojac1]=mat[brojac2][brojac1+1];
					}
				}
				N--;
				j--;
			}
		}
	}
	/*ispis*/
	printf ("Nakon izbacivanja redova/kolona matrica glasi:\n");
	for (i=0; i<M; i++) {
		for (j=0; j<N; j++)  {
			printf ("%5d", mat [i][j]);
		}
		printf("\n");
	}


	return 0;
}
