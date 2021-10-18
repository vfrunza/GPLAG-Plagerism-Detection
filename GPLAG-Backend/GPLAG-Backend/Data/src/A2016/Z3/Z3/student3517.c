#include <stdio.h>

int main() {
	int matrica[200][200],M,N;
	int i,j,k,z;
	do{
		printf("Unesite brojeve M i N: ");
		scanf("%d %d", &M,&N);
		if(M<1 || M>200 || N<1 || N>200)
		printf("Brojevi nisu u trazenom opsegu.\n");}
		while(M<1 || M>200 || N<1 || N>200);
		printf("Unesite elemente matrice: ");
		for(i=0; i<M; i++){
			for(j=0; j<N; j++)
			scanf("%d", &matrica[i][j]);
		}
		for(i=0; i<M; i++){
			for(j=i+1; j<M; j++) {
				for(k=0; k<N; k++) {
					if(matrica[i][k]!=matrica[j][k])
					break;
				}
			
			if(k==N) {
				for(z=j; z<M-1; z++) {
					for(k=0; k<N; k++)
					matrica[z][k]=matrica[z+1][k];
				}
				M--;
				j--;
			}
		}
	}
	for(i=0; i<N; i++){
		for(j=i+1; j<N; j++) {
			for(k=0; k<M; k++) {
				if( matrica[k][i]!=matrica[k][j])
				break;
			}
			if(k==M) {
				for(z=j; z<N-1; z++) {
					for(k=0; k<M; k++) {
					matrica[k][z]=matrica[k][z+1];
				} 
					}
				N--;
				j--;
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
