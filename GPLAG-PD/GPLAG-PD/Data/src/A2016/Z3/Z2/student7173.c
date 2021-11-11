#include <stdio.h>

int zbir_cifara(int broj) {
	int zbir = 0;
	
	/* Broj pretvoriti u njegovu apsolutnu vrijednost */
	if (broj < 0) {
		broj *= -1;
	}

	/* Naci zbir cifara od broja */
	while (broj > 0) {
		zbir += broj % 10;
		broj /= 10;
	}
	
	return zbir;
}

void ubaci(int niz[], int duzina) {
	int i;
	/* Prvo premjestiti sve brojeve osim prvog, pocevsi od zadnjeg,
	tako da iza svakog ostane mjesto za zbir njegovih cifara */
	for (i = duzina - 1; i > 0; i--) {
		niz[i*2] = niz[i];
	}
	
	/* Brojevi se nalaze na parnim indeksima,
	zbirove cifara ubacujemo na neparne indekse */
	for (i = 1; i < duzina*2; i += 2) {
		niz[i] = zbir_cifara(niz[i - 1]);
	}
}

/* Provjerava da li je n clan Fibonaccijevog niza */
int fibonaccijev(int n) {
	int i = 1, j = 1, temp;
	while (j < n) {
		temp = j;
		j += i;
		i = temp;
	}
	
	if (j == n) {
		return 1;
	} else {
		return 0;
	}
}

/* Izbacuje sve clanove Fibonaccijevog niza iz niza */
int izbaci(int niz[], int duzina) {
	int i, n = 0;
	for (i = 0; i < duzina; i++) {
		if (fibonaccijev(niz[i])) {
			n += 1;
		} else {
			niz[i - n] = niz[i];
			/* clan niz[i] ce biti promijenjen u buducnosti, ili nece 
			uci u finalni niz, tako da ga ne moramo sad mijenjati */
		}
	}
	
	/* n sada iznosi broj clanova Fibonaccijevog niza u niz-u */
	return duzina - n;
}

int main() {
	int niz[20] = {0}, i, duzina;
	
	printf("Unesite niz od 10 brojeva: ");
	for (i = 0; i < 10; i++) {
		scanf("%d", &niz[i]);
		
	}

	ubaci(niz, 10);
	duzina = izbaci(niz, 20);
	
	printf("Modificirani niz glasi:");
	for (i = 0; i < duzina; i++) {
		printf(" %d", niz[i]);
		printf("%c", i == duzina-1 ? '.' : ',');
	}

	return 0;
}
