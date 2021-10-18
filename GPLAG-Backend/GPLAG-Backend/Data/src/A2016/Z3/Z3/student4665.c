#include <stdio.h>

int main() {
	int m, n;
	int mat[200][200];
	int i, j, k, h, l;
	int brojac=0;
	do {
	printf("Unesite brojeve M i N: ");
	scanf("%d%d", &m, &n);
	if (m<=200 && n<=200 && m>0 && n>0) break;
	else printf ("Brojevi nisu u trazenom opsegu.\n");	
	} while(1);
	
	printf("Unesite elemente matrice: ");
	for(i=0; i<m; i++) {
		for(j=0; j<n; j++) {
			scanf("%d", &mat[i][j]);
		}
	}
	
	/*pronalazak istih redova*/
	for(i=0; i<m; i++) {
		for(k=i+1; k<m; k++) {
			brojac=0;
			for(j=0; j<n; j++) {
				if(mat[i][j]!=mat[k][j]) {
					brojac=1;
					break;
				}
			}		
			/*izbacivajenje*/
			if(brojac==0) {
				l=k;
				for(h=k+1; h<m; h++) {
					for(j=0; j<n; j++)
						mat[l][j]=mat[h][j];
				l++;
				}
				m--;
				k--;
			}
		}
	}
	
	for (i=0; i<n; i++) {
		for (k=i+1; k<n; k++) {
			brojac=0;
			for (j=0; j<m; j++) {
				if (mat[j][i]!=mat[j][k]) {					
					brojac=1;
					break;
				}
			}
			/*izbacivanje*/
			if (brojac==0) {
				l=k;
					for(h=k+1; h<n; h++)
						for(j=0; j<m; j++)
							mat[j][l++]=mat[j][h];
				n--;
				k--;
			}
		}
	}
	
	printf("Nakon izbacivanja redova/kolona matrica glasi: \n");
	for(i=0; i<m; i++) {
		for(j=0; j<n; j++) {
			printf("%5d", mat[i][j]);
		}
		printf("\n");
	}
	return 0;
}
