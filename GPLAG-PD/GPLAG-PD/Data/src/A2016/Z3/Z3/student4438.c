#include <stdio.h>

int main() {
	
	int m, n, i, j, k, l, var = 1;
	int matrica[200][200] = {{1,2,3,2}, {4,5,6,5}, {1,2,3,2}, {7,8,9,8}};
	int indexiKolona[200], indexiRedova[200];
	int brojacKolona = 0, brojacRedova = 0;
	
	do {
		printf("Unesite brojeve M i N: ");
		scanf("%d %d", &m, &n);
		if(m > 200 || n > 200 || m <= 0 || n <= 0) printf("Brojevi nisu u trazenom opsegu.\n");
		else break;
	}while(1);
	
	printf("Unesite elemente matrice: ");
	for(i = 0; i < m; i++) {
		for(j = 0; j < n; j++) {
			scanf("%d", &matrica[i][j]);
		}
	}
	
	for(i = 0; i < 200; i++) {
		indexiKolona[i] = -1;
		indexiRedova[i] = -1;
	}
	
	for(i = 0; i < n - 1; i++) {
		for(j = i + 1; j < n; j++) {
			if(matrica[0][i] == matrica[0][j]) {
				for(k = 0; k < m; k++) {
					if(matrica[k][i] != matrica[k][j]) var = 1;
					else {
						var = 0;
					}
				}
			}
			if(var == 0) {
				indexiKolona[brojacKolona] = j;
				brojacKolona++;
			}
			var = 1;
		}
	}
	
	var = 1; 
	
	for(i = 0; i < m - 1; i++) {
		for(j = i + 1; j < m; j++) {
			if(matrica[i][0] == matrica[j][0]) {
				for(k = 0; k < n; k++) {
					if(matrica[i][k] != matrica[j][k]) var = 1;
					else {
						var = 0;
					}
					if(matrica[j][k] < 0) {
						var = 1;
						break;
					}
				}
			}
			if(var == 0) {
				indexiRedova[brojacRedova] = j;
				brojacRedova++;
			}
			var = 1;
		}
	}
	
	var = 0;
	for(i = 0; i < m; i++) {
		for(k = 0; k < brojacRedova; k++) {
			if(indexiRedova[k] == i) {
				var = 1;
				for(l = 0; l < n; l++) matrica[i][l] = 0;
			}
		}
		if(var != 1) {
			for(j = 0; j < n; j++) {
				for(k = 0; k < brojacKolona; k++) {
					if(indexiKolona[k] == j) matrica[i][j] = 0;
				}
			}
		}
		var = 0;
	}
	
	printf("Nakon izbacivanja redova/kolona matrica glasi:\n");
	for(i = 0; i < m; i++) {
		int tmp = 0;
		for(j = 0; j < n; j++) {
			if(matrica[i][j] != 0) {
				if(matrica[i][j] < 0) printf("   %d", matrica[i][j]);
				else if(matrica[i][j] > 9) printf("   %d", matrica[i][j]);
				else if(i > 0 && matrica[i-1][j] > 9) printf("    %d", matrica[i][j]);
				else printf("    %d", matrica[i][j]);
				tmp = 1;
				continue;
			}
			if(j == 0){
				for(k = 0; k < n; k++) {
					if(matrica[i][k] != 0) tmp = 1;
				}
			}
		}
		if(tmp != 0) printf("\n");
	}
	return 0;
}
