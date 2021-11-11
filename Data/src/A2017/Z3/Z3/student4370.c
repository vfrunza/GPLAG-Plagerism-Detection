#include <stdio.h>

int izbaci_cifre(int* brojevi, int vel_br, int* cifre, int vel_cif);
int izbaci_cifru(int broj, int pozicija);

int main() {
	return 0;	
}

int izbaci_cifre(int* brojevi, int vel_br, int* cifre, int vel_cif) {
	int i, j, k, smanjivac_j;
	int tren_cifra, tren_br, predznak;
	
	for (i = 0; i < vel_cif; i++) {
		tren_cifra = cifre[i];
		
		if (tren_cifra < 0 || tren_cifra > 9)
			return 0;
		
		for (j = i + 1; j < vel_cif; j++) {
			if (cifre[j] == tren_cifra)
				return 0;
		}
	}
	
	for (i = 0; i < vel_br; i++) {
		if (brojevi[i] < 0)
			predznak = -1;
		else
			predznak = 1;
			
		tren_br = brojevi[i] * predznak;
		
		for (j = 1; tren_br / j > 0; j *= 10 / smanjivac_j) {
			smanjivac_j = 1;
			if (tren_br < 10) {
				for (k = 0; k < vel_cif; k++) {
					if (cifre[k] == tren_br)
						tren_br = 0;
				}
				
				break;
			}
			
			tren_cifra = (tren_br / j) % 10;
			
			for (k = 0; k < vel_cif; k++) {
				if (cifre[k] == tren_cifra) {
					if (tren_br == tren_cifra)
						tren_br = 0;
					else
						tren_br = izbaci_cifru(tren_br, j);
						
					smanjivac_j = 10;
				}
			}
		}
			
		brojevi[i] = tren_br * predznak;
	}
	
	return 1;
}

int izbaci_cifru(int broj, int pozicija) {
	int i;
	int novi_broj = broj % pozicija;
	
	for (i = pozicija; broj / (i * 10) > 0; i *= 10) {
		novi_broj += ((broj / (i * 10)) % 10) * i;
	}
	
	return novi_broj;
}