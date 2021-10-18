#include <stdio.h>
#include <stdlib.h>

int vrati_najveci (int brojaci[], int vel, int max_p) {
	int i, rezultat, temp_veci;
	rezultat = 0;
	temp_veci = brojaci[0];
	for (i = 0; i < vel; i++) {
		if (brojaci[i] == max_p) {
			if (brojaci[i] > temp_veci) {
				temp_veci = brojaci[i];
				rezultat = i;
			}
		}
	}
	return rezultat;
}
int vrati_najveci_za_negativne (int brojaci[], int vel, int max_n) {
	int i, rezultat, temp_veci;
	temp_veci = brojaci[0];
	for (i = 0; i < vel; i++) {
		if (brojaci[i] == max_n) {
			if (brojaci[i] >= temp_veci) {
				temp_veci = brojaci[i];
				rezultat = i;
			}
		}
	}
	return rezultat;
}
int max (int matrica[100][100], int visina, int sirina) {
	int brojaci[20] = {0}, brojaci_negativnih[2001] = {0}, i, j, rezultat, max_p, max_n, brojac_najvecih, brojaci_najvecih_negativnih, negativni_elementi;
	brojac_najvecih = 0;
	brojaci_najvecih_negativnih = 0;
	negativni_elementi = 0;
	for (i = 0; i < visina; i++) {
		for (j = 0; j < sirina; j++) {
			if (matrica[i][j] < 0) {
				brojaci_negativnih[abs(matrica[i][j])]++;
				negativni_elementi = 1;
			}
			else brojaci[matrica[i][j]]++;
		}
	}
	if (negativni_elementi) {
		max_n = brojaci_negativnih[0];
		for (i = 0; i < 2001; i++) {
			if(brojaci_negativnih[i] >= max_n) {
				max_n = brojaci_negativnih[i];
				brojaci_najvecih_negativnih++;
				rezultat = i * (-1);
			}
		}
	}
	else {
		max_p = brojaci[0];
		for (i = 0; i < 20; i++) {
			if (brojaci[i] >= max_p) {
				max_p = brojaci[i];
				brojac_najvecih++;
				rezultat = i;
			}
		}
	}
	if(brojac_najvecih > 1) return vrati_najveci(brojaci, 20, max_p);
	if(brojaci_najvecih_negativnih > 1) return vrati_najveci_za_negativne(brojaci_negativnih, 2001, max_n) * (-1);
	else return rezultat;
}
void algoritam_za_izbacivanje (int matrica[100][100], int visina, int sirina, int index) {
	int i, j;
	for (j = index; j < sirina - 1; j++) {
		for (i = 0; i < visina; i++) {
			if (matrica[i][j] == matrica [i][j+1]) continue;
			else matrica[i][j] = matrica [i][j+1];
		}
	}
}

int je_li_red_isti(int matrica[100][100], int visina, int sirina, int N) {
	int i,j,isti;
	isti = 0;
	
	for (i = 0; i < visina; i++) {
		for (j = 0; j < sirina; j++) {
			if (matrica[i][j] == N) isti++;
		}
	}
	if (isti == sirina) return 1;
	else return 0;
}
int izbaci_kolone (int matrica[100][100], int visina, int sirina, int N) {
	int i, j, index;
	
	for (i = 0; i < visina; i++) {
		for (j = 0; j < sirina; j++) {
			if (matrica[i][j] == N) {
				index=j;
				algoritam_za_izbacivanje(matrica, visina, sirina, index);
				sirina--;
			}
		}
	}
	if (je_li_red_isti(matrica, visina, sirina, N)) return 0;
	return sirina;
}
int main() {
	int sirina, visina, i, j, k, matrica[100][100], brojac_ispisa;
	brojac_ispisa = 0;
	printf ("Unesite sirinu i visinu matrice: ");
	scanf("%d %d", &sirina, &visina);
	for (i = 0; i < visina; i++) {
		printf ("Unesite elemente %d. reda: ", i+1);
		for (j = 0; j < sirina; j++) {
			scanf ("%d ", &matrica[i][j]);
		}
	}
	printf ("\n");
		for (i = 1; ; i++) {
			brojac_ispisa = 0;
			sirina = izbaci_kolone(matrica, visina, sirina, max(matrica, visina, sirina));
			for (j = 0; j < visina; j++) {
				for (k = 0; k < sirina; k++) {
					brojac_ispisa++;
				}
			}
			if (brojac_ispisa == 0) {
				printf ("Nakon %d. prolaza matrica je prazna!", i);
				break;
			}
			else printf ("Nakon %d. prolaza matrica glasi:\n", i);
			for (j = 0; j < visina; j++) {
				for (k = 0; k < sirina; k++) {
					printf ("%5d", matrica[j][k]);
				}
				printf ("\n");
			}
		}
	return 0;
}
