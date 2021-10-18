#include <stdio.h>
#define Br 200

int main() {
	int m, n, i, j, k, l, r, a;
	int mat[Br][Br]={{0}};
	
	do {
		printf("Unesite brojeve M i N: ");
		scanf("%d %d", &m, &n);
		if(m<=0 || n<=0 || m>200 || n>200) 
		printf("Brojevi nisu u trazenom opsegu.\n");
	} while(m<=0 || n<=0 || m>200 || n>200);
	printf("Unesite elemente matrice: ");
	for(i=0; i<m; i++) {
		for(j=0; j<n; j++) {
			scanf("%d", &mat[i][j]);
		}
	}
for(a=0; a<2; a++) {
	for(i=0; i<m; i++) {
		for(k=i+1; k<=m; k++) {
			for(j=0; j<n; j++) {
				if(mat[i][j]!=mat[k][j])
				break;
				if(j==n-1) {
					for(l=k; l<=m; l++) {
						for(r=0; r<n; r++) {
							mat[l][r]=mat[l+1][r];
						}
					}
					m--;
				}
			}
		}
	}
	for(i=0; i<n; i++) {
		for(k=i+1; k<=n; k++) {
			for(j=0; j<m; j++) {
				if(mat[j][i]!=mat[j][k])
				break;
				if(j==m-1) {
					for(l=k; l<=n; l++) {
						for(r=0; r<m; r++) {
							mat[r][l]=mat[r][l+1];
						}
					}
					n--;
				}
			}
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
