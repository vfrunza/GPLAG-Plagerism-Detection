#include <stdio.h>

int main()
{
	int M,N, A[100][100], B[100][100], C[100][100],i,j,a1,bra[100]= {0},b1,brb[100]= {0},brc[100]= {0},c1,s=0,maxa,maxb,maxc;
	do {
		printf ("Unesite brojeve M i N: ");
		scanf ("%d%d", &M, &N);
	} while ((M<0 || M>100) || (N<0 || N>100));

	printf ("Unesite clanove matrice A: ");
	for (i=0; i<M; i++) {
		for (j=0; j<N; j++) {
			scanf ("%d", &A[i][j]);
		}
	}

	maxa=A[0][0];
	for (i=0; i<M; i++) {
		for (j=0; j<N; j++) {
			if (A[i][j]>maxa)
				maxa=A[i][j];
		}
	}


	printf ("Unesite clanove matrice B: ");
	for (i=0; i<M; i++) {
		for (j=0; j<N; j++) {
			scanf ("%d", &B[i][j]);
		}
	}
	maxb=B[0][0];
	for (i=0; i<M; i++) {
		for (j=0; j<N; j++) {
			if (B[i][j]>maxb)
				maxb=B[i][j];
		}
	}

		
		
		printf ("Unesite clanove matrice C: ");
		for (i=0; i<M; i++) {
			for (j=0; j<N; j++) {
				scanf ("%d", &C[i][j]);
			}
		}
		maxc=C[0][0];
		for (i=0; i<M; i++) {
			for (j=0; j<N; j++) {
				if (C[i][j]>maxc)
					maxc=C[i][j];
			}
		}

			
			for (i=0; i<M; i++) {
				for (j=0; j<(N); j++) {
					for (a1=0; a1<maxa+1; a1++) {
						if (A[i][j]==a1) {
							bra[a1]++;
						}
					}
				}
			}

			for (i=0; i<M; i++) {
				for (j=0; j<(N); j++) {
					for (b1=0; b1<maxb+1; b1++) {
						if (B[i][j]==b1) {
							brb[b1]++;
						}
					}
				}
			}

			for (i=0; i<M; i++) {
				for (j=0; j<(N); j++) {
					for (c1=0; c1<maxc+1; c1++) {
						if (C[i][j]==c1) {
							brc[c1]++;
						}
					}
				}
			}
			
			for (i=0; i<(M*N); i++) {
				if (bra[i]==brb[i] && bra[i]==brc[i])
					s++;
			}

			if (s==(M*N))
				printf ("DA\n");
			else
				printf ("NE\n");
			return 0;
		}