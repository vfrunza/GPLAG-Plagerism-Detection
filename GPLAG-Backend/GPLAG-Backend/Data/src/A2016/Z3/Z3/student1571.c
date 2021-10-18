#include <stdio.h>
#define VEL 200

int main()
{
	int a,p,b,s,q,i,j,mat[VEL][VEL],M,N;
	do {
		printf("Unesite brojeve M i N: ");
		scanf("%d%d",&M,&N);
		if (M>200 || N>200 || N<0 || M<0)
			printf("Brojevi nisu u trazenom opsegu.\n");
	} while (M>200 || M<0 || N>200 || N<0);

	printf("Unesite elemente matrice: ");
	for (i=0; i<M; i++) {
		for (j=0; j<N; j++) {
			scanf("%d",&mat[i][j]);
		}
	}

	for (i=0; i<M-1; i++) {
		for (j=i+1; j<M; j++) {
			a=0;
			if (mat[i][0]==mat[j][0]) {
				a=1;
				for (p=1; p<N; p++) {
					if (mat[i][p]!=mat[j][p]) a=0;
				}
				if (a==1) {
					for (q=j; q<M-1; q++) {
						for (s=0; s<N; s++) {
							mat[q][s]=mat[q+1][s];
						}
					}
					M--;
				}
			}
		}
	}

	for (i=0; i<N-1; i++) {
		for (j=i+1; j<N; j++) {
			b=0;
			if (mat[0][i]==mat[0][j]) {
				b=1;
				for (p=1; p<M; p++) {
					if (mat[p][i]!=mat[p][j]) b=0;
				}
				if (b==1) {
					for (q=j; q<N-1; q++) {
						for (s=0; s<M; s++) {
							mat[q][s]=mat[q][s+1];
						}
					}
					N--;
				}
			}
		}
	}
	printf("Nakon izbacivanja redova/kolona matrica glasi:\n");
	for (i=0; i<M; i++) {
		for (j=0; j<N; j++) {
			printf("%5d",mat[i][j]);
		}
		printf("\n");
	}
	return 0;
}