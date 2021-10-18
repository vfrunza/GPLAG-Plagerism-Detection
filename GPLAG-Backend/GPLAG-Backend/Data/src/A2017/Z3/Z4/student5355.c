#include <stdio.h>

int max(int matrica[100][100], int visina, int sirina) {
	int najcesci = 0, i, j, temp, indeks = 0, brojac = 0;
	int elementi[10000];
	for (i = 0; i < visina; i++) 
		for (j = 0; j < sirina; j++) elementi[indeks++] = matrica[i][j];
	for (i = 0; i < indeks; i++) {
		temp = 1;
		for (j = i + 1; j < indeks; j++) {
			if (elementi[i] == elementi[j]) temp++;
		}
		if (temp == brojac && elementi[i] < najcesci) najcesci = elementi[i];
		if (temp > brojac) brojac = temp, najcesci = elementi[i];
	}
	return najcesci;
}

int izbaci_kolone(int matrica[100][100], int visina, int sirina, int N) {
	int broj_kolona = sirina, j, i, p, q;
	for (j = 0; j < broj_kolona; j++) 
		for (i = 0; i < visina; i++)
			if (matrica[i][j] == N) {
				if (j == sirina - 1) broj_kolona--;
				else {
					for (q = j; q < broj_kolona - 1; q++) 
						for (p = 0; p < visina; p++)
							matrica[p][q] = matrica[p][q+1];
					broj_kolona--;
				}
				j--;
				break;
			}
	return broj_kolona;
}
void IspisiMatricu(int matrica[100][100], int visina, int sirina) {
	int i, j;
	for (i = 0; i < visina; i++) {
		for (j = 0; j < sirina; j++) 
			printf("%5d", matrica[i][j]);
		printf("\n");
	}
	printf("\n");
}

int main() {
	int matrica[100][100];
	int i, j, sirina, visina;
	printf("Unesite sirinu i visinu matrice: ");
	scanf("%d%d", &sirina, &visina);
	for (i = 0; i < visina; i++) {
		printf ("Unesite elemente %d. reda: ", i + 1);
		for (j = 0; j < sirina; j++)
			scanf("%d", &matrica[i][j]);
	}
	printf ("\n");
	i = 1;
	for (;;) {
		sirina = izbaci_kolone(matrica, visina, sirina, max(matrica, visina, sirina));
		if (sirina == 0) break;
		printf("Nakon %d. prolaza matrica glasi:\n", i++);
		IspisiMatricu(matrica, visina, sirina);
	}
	printf ("Nakon %d. prolaza matrica je prazna!", i);
	return 0;
}
