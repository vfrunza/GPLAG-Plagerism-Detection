#include <stdio.h>

int main() {
	int i=0,j=0,M=100,N=100,A[100][100],r=0,isti=1,s=0,l=0,iste=1,L=0,p=0,k=0;
	do {
		printf("Unesite brojeve M i N: ");
		scanf("%d %d", &M, &N);
		if ((M>0) && (M<=200) && (N>0) && (N<=200))
			break;
		else
			printf ("Brojevi nisu u trazenom opsegu. \n");
	} while (1);
	
	printf("Unesite elemente matrice: ");
	for(i=0; i<M; i++) {
		for(j=0; j<N; j++) {
			scanf("%d",&A[i][j]);
		}
	}
	/*izbacivanje redova matrice koji se ponavljaju*/
	for (i=0; i<M; i++) {
		for (r=i+1; r<M; r++) {
			isti=1;
			for (j=0; j<N; j++) {
				if (A[i][j]!=A[r][j])
					isti=0;
			}
			if (isti) {
				for (s=r; s<M-1; s++) {
					for (k=0; k<N; k++) {
						A[s][k]=A[s+1][k];
					}
				}
				M--;
				r--;
			}
		}
	}
	/*izbacivanje kolona matrice koje se ponavaljaju*/
	for (j=0; j<N; j++) {
		for (l=j+1; l<N; l++) {
			iste=1;
			for (i=0; i<M; i++) {
				if (A[i][j]!=A[i][l])
					iste=0;
			}
			if (iste) {
				for (L=l; L<N-1; L++) {
					for (p=0; p<M; p++) {
						A[p][L]=A[p][L+1];
					}
				}
				N--;
				l--;
			}
		}
	}
	printf ("Nakon izbacivanja redova/kolona matrica glasi:\n");
	for (i=0; i<M; i++) {
		for (j=0; j<N; j++) {
			printf("%5d",A[i][j]);
		}
		printf ("\n");
	}
	return 0;
}
