#include <stdio.h>
#define V 200
#define S 200
int main() {
	int jednaki=0,i,j,k,z,p,r,M,N;
	int matrica[V][S];
	do { 
		printf("Unesite brojeve M i N: ");
		scanf ("%d %d",&M, &N);
		if (M<1 || M>200 || N<1 || N>200) {
			printf ("Brojevi nisu u trazenom opsegu.\n");
		}
	
	}
	while (M<1 || M>200 || N<1 || N>200);
	printf ("Unesite elemente matrice: ");
 	for (i=0; i<M; i++) {
		for (j=0; j<N; j++) {
			scanf ("%d",&matrica[i][j]);
		}
	}
	for (i=0; i<M; i++) {
		for (k=i+1; k<M; k++) {
			for (z=0; z<N; z++) {
				if (matrica[i][z]==matrica[k][z]) {
						jednaki++;
				}		
					if (jednaki==N) {
						for (p=k; p<M-1; p++) {
							for (r=0; r<N; r++) {
							matrica[p][r]=matrica[p+1][r];
							}
						}
						
						M--;
						k--;
					}
				}
			jednaki=0;
			}
		}
	//	jednaki=0;
	for (j=0; j<N; j++) {                                            
		for (z=j+1; z<N; z++) {
			for (k=0; k<M; k++)	 {
				if (matrica[k][j]==matrica[k][z]) {
					jednaki++;
				}	
					if (jednaki==M) {
						for (p=0; p<M; p++) {
							for (r=z; r<N-1; r++){
								matrica[p][r]=matrica[p][r+1];
							}
						}
						
						N--;
						z--;
					}
				}
				jednaki=0;
			}
		}
	
		printf ("Nakon izbacivanja redova/kolona matrica glasi:\n");
		for (i=0; i<M; i++) {
			for (j=0; j<N; j++) {
				printf (" %4d",matrica[i][j]);
		}
		printf ("\n");
	} 
	
	return 0;
}
