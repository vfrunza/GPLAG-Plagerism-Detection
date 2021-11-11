#include <stdio.h>

int main()
{
	int i, j, k, l, M, N, mat[500][500], br_istih1, br_istih2;

	do {
		printf("Unesite brojeve M i N: ");
		scanf("%d %d", &M, &N);
		if(M<1 || N<1 || M>200 || N>200)
			printf("Brojevi nisu u trazenom opsegu.\n");
	} while(M<1 || N<1 || M>200 || N>200);

	printf("Unesite elemente matrice: ");
	for(i=0; i<M; i++) {
		for(j=0; j<N; j++) {
			scanf("%d", &mat[i][j]);
		}
	}

	/*poredimo odgovarajuce elemente redova i brojimo koliko ima istih*/
	for(i=1; i<M; i++) {
		for(k=0; k<i; k++) {
			br_istih1=0;
			for(j=0; j<N; j++) {
				if(mat[k][j]==mat[i][j])
					br_istih1++;
			}
			/*ako je broj istih elemenata jednak broju elemenata redova matrice red izbacujemo*/
			if(br_istih1==N) {
				for(l=i; l<M-1; l++) {
					for(j=0; j<N; j++)
						mat[l][j]=mat[l+1][j];
				}
				M--;
				i--;
			}
		}
	}

	/*poredimo odgovarajuce elemnete kolona i brojimo koliko ima istih elemenata*/
	for(j=1; j<N; j++) {
		for(k=0; k<j; k++) {
			br_istih2=0;
			for(i=0; i<M; i++) {
				if(mat[i][k]==mat[i][j])
					br_istih2++;
			}
			/*izbacujemo kolonu ukoliko je br istih elemenata u koloni jendnak broju elemnata kolone matrice*/
			if(br_istih2==M) {
				for(l=j; l<N-1; l++) {
					for(i=0; i<M; i++)
						mat[i][l]=mat[i][l+1];
				}
				N--;
				j--;
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
