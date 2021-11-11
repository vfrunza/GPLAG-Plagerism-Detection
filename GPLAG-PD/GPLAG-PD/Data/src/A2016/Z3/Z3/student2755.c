#include <stdio.h>
#define BREL 200

int main() {
	int mat[BREL][BREL], i, j, k, m, n, l, razlicit;
	printf("Unesite brojeve M i N: ");
	scanf("%d %d", &m, &n);
	while(m<=0 || m>200 || n<=0 || n>200) {
		printf("Brojevi nisu u trazenom opsegu.\nUnesite brojeve M i N: ");
		scanf("%d %d", &m, &n);
	}
	
	printf("Unesite elemente matrice: ");
	for(i=0; i<m; i++) {
		for(j=0; j<n; j++) {
			scanf("%d", &mat[i][j]);
		}
	}
	
	/*Brisanje istih redova*/
	for(i=0; i<m-1; i++) {
		for(j=i+1; j<m; j++) {
			razlicit=0;
			for(k=0; k<n; k++) {
				if(mat[i][k] != mat[j][k]) {
					razlicit=1;
					break;
				}
			}
			if(razlicit==0) {
				for(k=j; k<m-1; k++) {
					for(l=0; l<n; l++){
						mat[k][l]=mat[k+1][l];
					}
				}
				m--;
				j--;
			}
		}
	}
	
	/*Brisanje istih kolona*/
	for(i=0; i<n-1; i++) {
		for(j=i+1; j<n; j++) {
			razlicit=0;
			for(k=0; k<m; k++) {
				if(mat[k][i]!=mat[k][j]) {
					razlicit=1;
					break;
				}
			}
			if(razlicit==0) {
				for(k=j; k<n-1; k++) {
					for(l=0; l<m; l++){
						mat[l][k]=mat[l][k+1];
					}
				}
				n--;
				j--;
			}
		}
	}
	
	printf("Nakon izbacivanja redova/kolona matrica glasi:\n");
	for(i=0; i<m; i++) {
		for(j=0; j<n; j++) {
			printf("%5d", mat[i][j]);
		}
		printf("\n");
	}
	
	
	return 0;
}
