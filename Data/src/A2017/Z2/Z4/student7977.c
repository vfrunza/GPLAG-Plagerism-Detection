#include <stdio.h>

int main()
{

	int i, j, k, l, M, N, A[100][100], B[100][100], C[100][100], temp, lk;



	do {
		printf("Unesite brojeve M i N: ");
		scanf("%d %d", &M, &N);
		continue;
	} while (M>100 || N>100);

	printf("Unesite clanove matrice A: ");
	for (i=0; i<M; i++) {
		for(j=0; j<N; j++) {
			scanf("%d", &A[i][j]);
		}
	}
	printf("Unesite clanove matrice B: ");
	for (i=0; i<M; i++) {
		for(j=0; j<N; j++) {
			scanf("%d", &B[i][j]);
		}
	}
	printf("Unesite clanove matrice C: ");
	for (i=0; i<M; i++) {
		for(j=0; j<N; j++) {
			scanf("%d", &C[i][j]);
		}
	}
	k=0;
	for(i=0; i<M; i++) {
		for(j=0; j<N; j++) {
			for(k=i; k<M; k++) {
				for(l=0; l<N; l++) {
					if(k!=i || j<=l) {
						if (A[k][l]<A[i][j]) {
							temp=A[i][j];
							A[i][j]=A[k][l];
							A[k][l]=temp;
						}
					}
				}
			}
		}
	}
	k=0;
	for(i=0; i<M; i++) {
		for(j=0; j<N; j++) {
			for(k=i; k<M; k++) {
				for(l=0; l<N; l++) {
					if(k!=i || j<=l) {
						if (B[k][l]<B[i][j]) {
							temp=B[i][j];
							B[i][j]=B[k][l];
							B[k][l]=temp;
						}
					}
				}
			}
		}
	}
	k=0;
	for(i=0; i<M; i++) {
		for(j=0; j<N; j++) {
			for(k=i; k<M; k++) {
				for(l=0; l<N; l++) {
					if(k!=i || j<=l) {
						if (C[k][l]<C[i][j]) {
							temp=C[i][j];
							C[i][j]=C[k][l];
							C[k][l]=temp;
						}
					}
				}
			}
		}
	}


	lk=1;
	for (i=0; i<M; i++) {
		for(j=0; j<N; j++) {
			if(A[i][j]!=B[i][j] || B[i][j]!=C[i][j]) {
				lk=0;
				i=M;
				j=N;
			}
		}
	}


	if(lk)
		printf("DA");
	else
		printf("NE");


	return 0;
}
