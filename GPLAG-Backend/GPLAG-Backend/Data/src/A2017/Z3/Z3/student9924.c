#include <stdio.h>
#include <stdlib.h>

int broj_ponavljanja(int niz[], int vel, int broj) {
	int br = 0, i;
	for (i = 0; i < vel; i++)
		if(niz[i] == broj) br++;
	return br;
}

int izbaci_cifre(int brojevi[], int vel1, int cifre[], int vel2) {
	int i, j, cifra = 1, broj = 0;
	for (i = 0; i < vel2; i++)
		if(broj_ponavljanja(cifre, vel2, cifre[i]) > 1 || cifre[i] < 0 || cifre[i] > 9)
			return 0;
	for (i = 0; i < vel1; i++) {
		for (j = 0; j < vel2; j++) {
			while (brojevi[i] != 0) {
				if(abs(brojevi[i])%10 != cifre[j]) {
					broj += (brojevi[i]%10)*cifra;
					cifra *= 10;
				}
				brojevi[i] /= 10;
			}
			brojevi[i] = broj;
			broj = 0;
			cifra = 1;
		}	
	}
	return 1;
}

int main() {

	return 0;
}
