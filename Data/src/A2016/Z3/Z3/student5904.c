#include <stdio.h>

int main() {
	
	int M, N, i, j, k, l, p, q, brisati_red, brisati_stupac, mat[200][200];
	
	do {
		
	printf("Unesite brojeve M i N: ");
	scanf("%d %d", &M, &N);
	
	if (M<1 || M>200 || N<1 || N>200)
		printf("Brojevi nisu u trazenom opsegu.\n");
	
	} while (M<1 || M>200 || N<1 || N>200);
	
	printf("Unesite elemente matrice:");
	
	for(i=0;i<M;i++){
		for(j=0;j<N;j++){
			scanf("%d", &mat[i][j]);
		}
	}
	
	/* BRISANJE REDA*/
	
	for(i=0; i<M; i++) {
		for(k=1; k<M-i; k++) {
			if (mat[i][0] == mat[i+k][0]) {
				brisati_red=1;
					for(l=1; l<N; l++) {
						if(mat[i][l] != mat[i+k][l]) {
							brisati_red=0; 
							break;
						}
				}
				
				if(brisati_red) {
					if (i+k==M-1)
						M--;
					else {	
						for(q=0; q<M-k; q++) {
							for(p=0; p<N; p++) {
								mat[i+k+q][p] = mat[i+k+q+1][p];
							} 
						}	
						M--; k--;
					}	
				}
			}
		}
	}
	
	/* BRISANJE STUPCA */
	
	for(j=0; j<N; j++) {
		for(l=1; l<N-j; l++) {
			if (mat[0][j] == mat[0][j+l]) {
				brisati_stupac = 1;
					for(k=1; k<M; k++) {
						if(mat[k][j] != mat[k][j+l]) {
							brisati_stupac=0; 
							break; 
					}
				}
				
				if (brisati_stupac) {
					if(j+l==N-1)
						N--;
					else {
						for(q=0; q<N-l; q++) {	
							for(p=0; p<N; p++) {
								mat[p][j+l+q] = mat[p][j+l+q+1];
							}
						}	
						N--; l--;
					} 
				}					
			}
		}
	}


	/* ispis matrice */
	
	printf(" Nakon izbacivanja redova/kolona matrica glasi: \n");
	
	for(i=0; i<M; i++) {
		for(j=0; j<N; j++) {
			printf("%5d", mat[i][j]);
		} printf("\n");
	}
	
	return 0;
}
