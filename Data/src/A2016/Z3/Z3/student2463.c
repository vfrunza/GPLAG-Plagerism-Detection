#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i, j, k, s, M, N, brojac, matrica[200][200];

	do {
		printf("Unesite brojeve M i N: ");
		scanf("%d %d", &M,&N);
		if(M<1 || N<1 || M>200 || N>200)
			printf("Brojevi nisu u trazenom opsegu.\n");
	}

	while(M<1 || N<1 || M>200 || N>200);
	printf("Unesite elemente matrice: ");
	for(i=0; i<M; i++) {
		for(j=0; j<N; j++) {
			scanf("%d", &matrica[i][j]);
		}

	}
	for(i=0; i<M; i++) {
		for(k=i+1; k<M; k++) {

			brojac=0;
			for(j=0; j<N; j++) {
				if(matrica[i][j]==matrica[k][j])
					brojac++;
			}
			if(brojac==N) {
				for(j=k; j<M-1; j++) {
					for(s=0; s<N; s++) {
						matrica[j][s]=matrica[j+1][s];
					}
				}
				k--;
				M--;
			}
		}
	}
	for(i=0; i<N-1; i++) {
		for(k=i+1; k<N; k++) {

			brojac=0;
			for(j=0; j<M; j++) {
				if(matrica[j][i]==matrica[j][k])
					brojac++;
			}
			if(brojac==M) {
				for(j=k; j<N-1; j++) {
					for(s=0; s<M; s++) {
						matrica[s][j]=matrica[s][j+1];
					}
				}
				k--;
				N--;
			}
		}
	}
	printf("Nakon izbacivanja redova/kolona matrica glasi:\n");
	for(i=0; i<M; i++) {
		for(j=0; j<N; j++) {
			printf("%5d", matrica[i][j]);
		}
		printf("\n");
	}
	return 0;
}
