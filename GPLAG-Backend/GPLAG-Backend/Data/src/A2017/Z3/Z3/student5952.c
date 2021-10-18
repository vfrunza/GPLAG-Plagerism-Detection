#include <stdio.h>

int primi_cifru (int cifra, int niz_cifara[], int vel) {
	int ima_je_u_nizu, i;
	ima_je_u_nizu = 0;
	for (i = 0; i < vel; i++) {
		if (cifra == niz_cifara[i]) {
			ima_je_u_nizu = 1;
			break;
		}
	}
	return ima_je_u_nizu;
}

int primi_broj (int broj, int niz_cifara[], int vel) {
	int niz_broja[10], cifra, i, duzina, novi_broj;
	novi_broj = 0;
	duzina = 0;
	i=0;
	while (broj > 0) {
		cifra = broj % 10;
		niz_broja[i] = cifra;
		i++;
		duzina++;
		broj = broj / 10;
	}
	for (i=duzina-1; i>=0; i--) {
		if (!primi_cifru(niz_broja[i], niz_cifara, vel)) {
			novi_broj = 10 * novi_broj + niz_broja[i];
		}
	}
	return novi_broj;
}
void kopiraj_niz(int niz[], int vel, int novi[]) {
	int i;
	for (i = 0; i < vel; i++) {
		novi[i] = niz[i];
	}
}
int izbaci_cifre (int niz_1[], int vel_1, int niz_2[], int vel_2) {
	int i, min, j, temp;
	int niz_3[100];
	kopiraj_niz(niz_2, vel_2, niz_3);
	for (i = 0; i < vel_2; i++) {
		if (niz_2[i] < 0 || niz_2[i] > 9) return 0;
	}
	for (i = 0; i<vel_2; i++) {
		min = i;
		for (j=i+1; j < vel_2; j++) {
			if (niz_2[j] < niz_2[min]) {
				min = j;
			}
		}
		temp = niz_3[i];
		niz_3[i] = niz_3[min];
		niz_3[min] = temp;
	}
	for (i=0; i < vel_2; i++) {
		if (i < vel_2-1 && niz_3[i]==niz_3[i+1]) return 0;
	}
	for (i = 0; i < vel_1; i++) {
		if (niz_1[i] < 0) {
			niz_1[i] = niz_1[i] * (-1);
			niz_1[i] = primi_broj(niz_1[i], niz_2, vel_2) * (-1);
		}
		else niz_1[i] = primi_broj(niz_1[i], niz_2, vel_2);
	}
	return 1;
}
int main() {
	printf("Zadaća 3, Zadatak 3");
	return 0;
}
