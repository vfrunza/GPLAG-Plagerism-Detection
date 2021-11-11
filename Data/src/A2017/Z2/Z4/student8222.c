#include <stdio.h>

int main()
{
	int A[100][100],B[100][100],C[100][100],M,N,i,j,brojac1[100]= {0},brojac2[100]= {0},brojac3[100]= {0},temp=0;
	do {
		printf("Unesite brojeve M i N: ");
		scanf("%d %d",&M,&N);
	} while (!(M>0 && M<=100 && N>0 && N<=100));
	printf("Unesite clanove matrice A: ");
	for (i=0; i<M; i++) {
		for (j=0; j<N; j++) {
			scanf("%d",&A[i][j]);
			brojac1[A[i][j]]++;
		}
	}
	printf("Unesite clanove matrice B: ");
	for (i=0; i<M; i++) {
		for (j=0; j<N; j++) {
			scanf("%d",&B[i][j]);
			brojac2[B[i][j]]++;
		}
	}
	printf("Unesite clanove matrice C: ");
	for (i=0; i<M; i++) {
		for (j=0; j<N; j++) {
			scanf("%d",&C[i][j]);
			brojac3[C[i][j]]++;
		}
	}
	for (i=0;i<M;i++) {
		for (j=0;j<N;j++) {
			if (((brojac1[A[i][j]])==(brojac2[B[i][j]])) && ((brojac2[B[i][j]])==(brojac3[C[i][j]]))) temp=0;
		}
	if (temp==0) break;
	}
	if (temp==0) printf("DA\n");
	else printf("NE\n");
	return 0;
}
