#include <stdio.h>



int main() {
	int mat[200][200]={{0}}, i=0, j=0, m=0, n=0, x=0, y=0, daLijeKraj=0, k=0;
	do {
		printf ("Unesite brojeve M i N: ");
		scanf ("%d %d", &m, &n);
	
		if (m<=0 || n<=0 || m>200 || n>200) {
			printf ("Brojevi nisu u trazenom opsegu.\n");
		}
	}
	while (m<=0 || m>200 || n<=0 || n>200);
	printf ("Unesite elemente matrice: ");
	for (i=0;i<m;i++) {
		for (j=0;j<n;j++) {
			scanf ("%d", &mat[i][j]);
		}
	}
	for (i=0; i<m-1; i++) {
		for (k=i+1; k<m; k++) {
			for (j=0; j<n; j++) {
				if (mat[i][j]==mat[k][j]) {
					daLijeKraj++;
				}
					if (daLijeKraj==n) {
					for (x=k; x<m; x++) {
						for (y=0; y<n; y++) {
							mat[x][y]=mat[x+1][y];
						}
					  }
					daLijeKraj=0;
					m--;
					k--;
				}
				
			}
			daLijeKraj=0;
		}
	}
	daLijeKraj=0;
	for (i=0; i<n-1; i++) {
		for (k=i+1; k<n; k++) {
			for (j=0; j<m; j++) {
				 if (mat[j][i]==mat[j][k]) {
					daLijeKraj++;
				 }
					if (daLijeKraj==m) {
					for (x=k; x<n; x++) {
						for (y=0; y<m; y++) {
							mat[y][x]=mat[y][x+1];
						}
					  }
					
					daLijeKraj=0;
					n--;
					k--;
				}
				
			}
			daLijeKraj=0;
		}
	}
	printf ("Nakon izbacivanja redova/kolona matrica glasi:\n");
	for (i=0; i<m; i++) {
		for (j=0; j<n; j++) {
			printf ("%5d", mat[i][j]);
		}
		printf ("\n");
	}
	
	return 0;
}
