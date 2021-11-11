#include <stdio.h>

int main() {
	
	int broj, a, b, cifra, rezultat = 0, nule, i, j;
	
	printf ("Unesite broj: ");
	scanf ("%d", &broj);
	
	if (broj < 0) broj = -broj;
	if (broj/10 < 1) {
		printf ("0");
		return 0;
	}
	
	for (i = 1; i < 9999; i++) {
		a = broj%10;
		broj/=10;
		b = broj%10;
		cifra = a-b;
		if (cifra < 0) cifra = -cifra;
		if (i == 1) nule = 1;
		else {
			nule = 1;
			for (j = 1; j < i; j++) nule*=10;
		}
		if (broj < 1) break;
		rezultat+=cifra*nule;
	}
	
	printf ("%d", rezultat);
	
	return 0;
}