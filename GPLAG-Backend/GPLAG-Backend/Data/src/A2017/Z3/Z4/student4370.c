#include <stdio.h>

int max(int matrica[100][100], int visina, int sirina);
int izbaci_kolone(int matrica[100][100], int visina, int sirina, int n);

int main() {
	int i, j;
	int matrica[100][100], visina, sirina, broj_prolaza = 0, za_izbaciti;
	
	printf("Unesite sirinu i visinu matrice: ");
	scanf("%d%d", &sirina, &visina);
	
	for (i = 0; i < visina; i++) {
		printf("Unesite elemente %d. reda: ", i + 1);
		
		for (j = 0; j < sirina; j++) {
			scanf("%d", &matrica[i][j]);
		}
	}
	
	printf("\n");
	
	for (;;) {
		za_izbaciti = max(matrica, visina, sirina);
		sirina = izbaci_kolone(matrica, visina, sirina, za_izbaciti);
		broj_prolaza += 1;
		
		if (sirina == 0)
			break;
		
		printf("Nakon %d. prolaza matrica glasi:\n", broj_prolaza);
		for (i = 0; i < visina; i++) {
			for (j = 0; j < sirina; j++)
				printf("%5d", matrica[i][j]);
			
			printf("\n");
		}
		printf("\n");
	}
	
	printf("Nakon %d. prolaza matrica je prazna!\n", broj_prolaza);
	
	return 0;
}

int max(int matrica[100][100], int visina, int sirina) {
	int i, j, k, l;
	int tren_el, tren_br_pon, element, broj_ponavljanja = 0;
	
	for (i = 0; i < visina; i++) {
		for (j = 0; j < sirina; j++) {
			tren_el = matrica[i][j];
			tren_br_pon = 0;
			
			for (k = i; k < visina; k++) {
				for (l = 0; l < sirina; l++) {
					if (matrica[k][l] == tren_el)
						tren_br_pon += 1;
				}
			}
			
			if (tren_br_pon > broj_ponavljanja || (tren_br_pon == broj_ponavljanja && tren_el < element)) {
				broj_ponavljanja = tren_br_pon;
				element = tren_el;
			}
		}
	}
	
	return element;
}

int izbaci_kolone(int matrica[100][100], int visina, int sirina, int n) {
	int i, j, k, l;
	
	for (i = 0; i < sirina; i++) {
		for (j = 0; j < visina; j++) {
			if (matrica[j][i] == n) {
				sirina -= 1;
				
				for (k = i; k < sirina; k++) {
					for (l = 0; l < visina; l++) {
						matrica[l][k] = matrica[l][k + 1];
					}
				}
			
				i -= 1;
				break;
			}
		}
	}
	
	return sirina;
}
