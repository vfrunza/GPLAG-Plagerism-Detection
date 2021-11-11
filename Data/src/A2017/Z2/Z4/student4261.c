#include <stdio.h>

int main()
{
	int matA[100][100], matB[100][100], matC[100][100], matD[100][100], i, j, k, l, x=0, y=0, M, N, brojac1=0, brojac2=0;
	do {
		printf("Unesite brojeve M i N: ");
		scanf("%d%d", &M, &N);
	} while ((M<0 || M>100) || (N<0 || N>100));
	printf("Unesite clanove matrice A: ");
	for (i=0; i<M; i++) {
		for (j=0; j<N; j++) {
			scanf("%d", &matA[i][j]);
		}
	}
	printf("Unesite clanove matrice B: ");
	for (i=0; i<M; i++) {
		for (j=0; j<N; j++) {
			scanf("%d", &matB[i][j]);
		}
	}
	printf("Unesite clanove matrice C: ");
	for (i=0; i<M; i++) {
		for (j=0; j<N; j++) {
			scanf("%d", &matC[i][j]);
		}
	}
	for (i=0; i<M; i++) {
		for (j=0; j<N; j++) {
			matD[i][j]=matA[i][j];
		}
	}
	for (i=0; i<M; i++) {
		for (j=0; j<N; j++) {
			if (x>matB[i][j]) x=matB[i][j]-1;
			if (y>matC[i][j]) y=matC[i][j]-1;
		}
	}
	for (i=0; i<M; i++) {
		for (j=0; j<N; j++) {
			for (k=0; k<M; k++) {
				for (l=0; l<N; l++) {
					if (matB[i][j]==matD[k][l]) {
						matD[k][l]=x;
						matB[i][j]=x-1;
						brojac1++;
					}
				}
			}
		}
	}
	for (i=0; i<M; i++) {
		for (j=0; j<N; j++) {
			for (k=0; k<M; k++) {
				for (l=0; l<N; l++) {
					if (matC[i][j]==matA[k][l]) {
						matA[k][l]=y;
						matC[i][j]=y-1;
						brojac2++;
					}
				}
			}
		}
	}
	if (brojac1==M*N && brojac2==M*N) printf("DA\n");
	else printf("NE\n");
	return 0;
}
