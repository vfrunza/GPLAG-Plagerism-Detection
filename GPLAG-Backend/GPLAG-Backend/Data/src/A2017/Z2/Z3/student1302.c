#include <stdio.h>

int main()
{
	float A[10][10], B[10][10], C[10][10];
	int i, j, k, l, M, N, X, Y, jednake;

	printf ("Unesite sirinu i visinu matrice A: ");
	scanf ("%d %d", &N, &M);
	printf ("Unesite clanove matrice A: ");
	for (i=0; i<M; i++) {
		for (j=0; j<N; j++) {
			scanf ("%f", &A[i][j]);
		}
	}

	printf ("Unesite sirinu i visinu matrice B: ");
	scanf ("%d %d", &Y, &X);
	printf ("Unesite clanove matrice B: ");
	for (k=0; k<X; k++) {
		for (l=0; l<Y; l++) {
			scanf ("%f", &B[k][l]);
		}
	}
	if (M!=Y || N!=X) {
		printf ("NE\n");
	
		
	} else if (M==N) {
		for (i=0; i<M; i++) {
			for (j=0; j<N; j++) {
				C[j][M-i-1]=A[i][j];
			}
		}

		jednake=1;
		for (i=0; i<M; i++) {
			for (j=0; j<N; j++) {
				if (C[i][j]!=B[i][j]) {
					jednake=0;
					break;
				}
			}
			if (jednake==0) {
				break;
			}
		}

		if(jednake==1) {
			printf ("DA\n");
		} else {
			printf ("NE\n");
		}

		
	} else {
		for (i=0; i<M; i++) {
			for (j=0; j<N; j++) {
				C[j][M-i-1]=A[i][j];
			}
		}

		jednake=1;
		for (i=0; i<N; i++) {
			for (j=0; j<M; j++) {
				if (C[i][j]!=B[i][j]) {
					jednake=0;
					break;
				}
			}
			if (jednake==0) {
				break;
			}
		}

		if(jednake==1) {
			printf ("DA\n");
		} else {
			printf ("NE\n");
		}
		
	} 
	
	return 0;

}
