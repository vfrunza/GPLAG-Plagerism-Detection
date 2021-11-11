#include <stdio.h>

int main() {
	//printf("Zadaća 3, Zadatak 3");
	int m, n, i, j, jednake_kolone = 0, jednaki_redovi = 0, k, brojac_kolone, brojac_reda, indeks_reda, indeks_kolone, broj, broj1;
	int mat[200][200];
		
	do {
		printf("Unesite brojeve M i N: ");
		scanf("%d %d", &m, &n);
		if(m<=0 || n<=0 || m>200 || n>200) 
			printf("Brojevi nisu u trazenom opsegu.\n");
	}
	while (m<=0 || n<=0 || m>200 || n>200);
	printf("Unesite elemente matrice: ");

	for( i = 0; i < m; i++) {
		for(j = 0; j < n;j++) {
			scanf("%d", &mat[i][j]);
		}
	}
	
	for(i = 0; i < m-1; i++) {
		
		jednaki_redovi = 0;
		broj = i;
		brojac_reda = 0;
		k = 1;
		
		while( i+k < m) {
			
			for(j = 0;j < n; j++) {
				if(mat[i][j]==mat[i+k][j])
					brojac_reda++; 
			}
			
			if(brojac_reda == n) {
				indeks_reda = i+k;
				jednaki_redovi = 1;
			}
		
			else {
				k++;
				brojac_reda = 0;
			}
		    if(jednaki_redovi == 1) {
				for(i = indeks_reda; i < m-1; i++) {
					for(j = 0; j <n ;j++) {
						mat[i][j] = mat[i+1][j];
			
					}
				}
				m--;
				i--;
			}
		}
	}

	j = 0;

	for(j = 0; j < n-1; j++) {
		
		jednake_kolone = 0;
		broj1 = j;
		brojac_kolone = 0;
		k = 1;
		
		while( j+k < n) {
			for(i = 0; i < m; i++) {
				if(mat[i][j] == mat[i][j+k]) {
					brojac_kolone++; 
				} 
			}
			if (brojac_kolone == m) {
				indeks_kolone= j+k;
				jednake_kolone = 1;
			}
			else {
				k++;
				brojac_kolone = 0;
			} 
			
			if (jednake_kolone==1) {
				for(i = 0; i < m; i++) {
					for(j = indeks_kolone; j < n-1; j++) {
						mat[i][j] = mat[i][j+1];
					}
				}
				n--;
				j--;
	
			}
		}
	}
	
	printf("Nakon izbacivanja redova/kolona matrica glasi:\n");
	for(i = 0; i < m; i++) {
		for (j = 0; j < n;j++) {
			printf("%5d", mat[i][j]);
		}
		printf("\n");
	}

	return 0;
}
