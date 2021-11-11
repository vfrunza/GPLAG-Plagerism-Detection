#include <stdio.h>

int abs(int x) { return x > 0 ? x : -x; }

int ubaci(int *niz, int duzina) {
	int i, zbir_cifara, broj;
	for (i = duzina - 1; i >= 0; i--) { //idemo unatraske da ne prepisemo elemente koji nam trebaju
		broj = abs(niz[2*i] = niz[i]);
		zbir_cifara = 0;
		while (broj > 0) {
			zbir_cifara += broj % 10; //skidamo jednu po jednu cifru sa broja i sabiramo u zbir cifara
			broj /= 10;
		}
		niz[2*i + 1] = zbir_cifara;
	}
	return 20;
}

int izbaci(int *niz, int n) {
	int i, j, novi, stari, swap;
	for (i = 0; i < n; i++) {
		stari = 0;
		novi = 1;
		while (novi <= niz[i]) { //za svaki element niza generisemo fibonacijev niz do tog broja
			swap = novi;
			novi += stari;
			stari = swap;
			if (niz[i] == novi) { //ako je element iz fibonacijevog niza
				for (j = i; j < n - 1; j++) //izbacujemo ga iz niza
					niz[j] = niz[j+1];
				i--;
				n--;
				break;
			}
		}
	}
	return n;
}

int main() {
	int niz[20], duzina = 10, i;
	
	printf("Unesite niz od 10 brojeva: ");
	
	for (i = 0; i < duzina; i++) scanf("%d", niz + i);
	
	duzina = ubaci(niz, duzina);
	duzina = izbaci(niz, duzina);
	
	printf("Modificirani niz glasi: ");
	for (i = 0; i < duzina - 1; i++) printf("%d, ", niz[i]);
	if (duzina > 0) printf("%d.", niz[i]);
	
	return 0;
}
