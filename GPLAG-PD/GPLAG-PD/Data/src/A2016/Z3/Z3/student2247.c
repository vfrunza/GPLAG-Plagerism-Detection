#include <stdio.h>
#define DUZINA 200
#define SIRINA 200
int main() {
	int mat[DUZINA][SIRINA], M, N, i, j, brojac=0, k, l, m;
	do {
		printf("Unesite brojeve M i N: ");
		scanf("%d %d", &M, &N);
		if(M<=0 || N<=0 || M>200 || N>200) printf("Brojevi nisu u trazenom opsegu.\n");
	} while(M<=0 || N<=0 || M>200 || N>200);
	printf("Unesite elemente matrice: ");
	for(i=0; i<M; i++) {
		for(j=0; j<N; j++) {
			scanf("%d", &mat[i][j]);
		}
	}
	for(i=0; i<M; i++) {
		for(j=i+1; j<M; j++) {
			brojac = 0;
			for(k=0; k<N; k++) {
				if(mat[i][k]!=mat[j][k]) {
					break;
				}
				else {
					brojac++;
				}
				if(brojac==N) {
					for(l=j; l<M; l++) {
						for(m=0; m<N; m++) {
							mat[l][m] = mat[l+1][m];
						}
					}
					M--;
					j--;
					break;
				}
			}
		}		
	}
	for(i=0; i<N; i++) {
		for(j=i+1; j<N; j++) {
			brojac = 0;
			for(k=0; k<N; k++) {
				if(mat[k][i]!=mat[k][j]) {
					break;
				}
				else { 
					brojac++;
				}
				if(brojac==M) {
					for(l=j; l<N; l++) {
						for(m=0; m<N; m++) {
							mat[m][l] = mat[m][l+1];
						}
					}
					N--;
					j--;
					break;
				}
			}
		}		
	}	
	printf("Nakon izbacivanja redova/kolona matrica glasi: ");
	for(i=0; i<M; i++) {
		printf("\n");
		for(j=0; j<N; j++) {
			printf("%5d", mat[i][j]);
		}
	}
	return 0;
}
