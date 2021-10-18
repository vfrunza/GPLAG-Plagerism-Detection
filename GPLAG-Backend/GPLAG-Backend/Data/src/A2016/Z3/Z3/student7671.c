#include <stdio.h>

int main() {
	int M, N, mat[201][201], i, j, nije, k, m, l;
	printf("Unesite brojeve M i N: ");
	scanf("%d %d", &M, &N);
	while(M<=0 || M>200 || N>200 || N<=0) {
		printf("Brojevi nisu u trazenom opsegu.\n");
		printf("Unesite brojeve M i N: ");
		scanf("%d %d", &M, &N);
	}
	printf("Unesite elemente matrice: ");
	for(i=0;i<M;i++) {
		for(j=0;j<N;j++) {
			scanf("%d", &mat[i][j]);
		}
	}
	
	for(i=0;i<M;i++) {
		for(j=i+1;j<M;j++) {
			for(k=0;k<N;k++) {
				nije=1;
				if(mat[i][k] != mat[j][k]) {
					nije=0;
					break;
				}
			}
			if(nije==1) {
				if(j<M-1) {
					for(l=j;l<M;l++) {
						for(m=0;m<N;m++) {
							mat[l][m]=mat[l+1][m];
						}
						j--;
						M--;
						break;
					}
				}
				else if(j+1==M) {
					M--;
					break;
				}
			}
		}
	}
	
	for(i=0;i<N;i++) {
		for(j=i+1;j<N;j++) {
			for(k=0;k<M;k++) {
				nije=1;
				if(mat[k][i]!=mat[k][j]) {
					nije=0;
					break;	
				}
			}
			if(nije) {
				if(j<N-1) {
				for(l=0;l<M;l++) {
					for(m=j;m<N;m++) {
						mat[l][m]=mat[l][m + 1];
					}
					j--;
					N--;
					break;
				}
			}
			else if(j+1==N) {
					N--;
					break;
				}
			}
		}
	}
	printf("Nakon izbacivanja redova/kolona matrica glasi: \n");
	for(i=0;i<M;i++) {
		for(j=0;j<N;j++) {
				printf("%5d",mat[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}