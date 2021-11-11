#include <stdio.h>

int main() {
	
	char car;
	int i, c = 0, b = 0, s = 0, v = 0, p = 0, uk = 0;
	float postotak, pop;
	
		//Unos
	
	printf ("Unesite vozila: ");
	
		//Brojac auta i ukupnog broja
	
	for (i = 1; i > 0; i++) {
		scanf ("%c", &car);
		if (car == 'c' || car == 'C') {
			c++;
			uk++;
		}
		else if (car == 'b' || car == 'B') {
			b++;
			uk++;
		}
		else if (car == 's' || car == 'S') {
			s++;
			uk++;
		}
		else if (car == 'v' || car == 'V') {
			v++;
			uk++;
		}
		else if (car == 'p' || car == 'P') {
			p++;
			uk++;
		}
		else if (car == 'k' || car == 'K') {
			break;
		}
		else if (car != 'k' && car != 'b' && car != 'c' && car != 's' && car != 'v' && car != 'p' && car != 'K' && car != 'B' && car != 'C' && car != 'S' && car != 'V' && car != 'P') {
			printf ("Neispravan unos\n");
		}
	}
	
		//Provjera najpopularnijeg/najcesceg
		
		if (c >= v && c >= b && c >= s & c >= p && c != 0) {
			pop = c;
		}
		if (v >= c && v >= b && v >= s && v >= p && v != 0) {
			pop = v;
		}
		if (b >= c && b >= v && b >= s && b >= p && b != 0) {
			pop = b;
		}
		if (s >= c && s >= b && s >= v && s >= p && s != 0) {
			pop = s;
		}
		if (p >= c && p >= b && p >= s && p >= v && p != 0) {
			pop = p;
		}
		
		//Racunanje postotka
		
		postotak = (pop/uk)*100;
		
		//Ispis
		
	printf ("Ukupno evidentirano %d vozila.\n", uk);
		
	if (uk == 0) {
		printf ("Najpopularnija boja je crna (0.00%).");
		return 0;
	}
	
		if (pop == c) {
			printf ("Najpopularnija boja je crna (%.2f%).", postotak);
			return 0;
		}
		else if (pop == b) {
			printf ("Najpopularnija boja je bijela (%.2f%).", postotak);
			return 0;
		}
		else if (pop == s) {
			printf ("Najpopularnija boja je siva (%.2f%).", postotak);
			return 0;
		}
		else if (pop == v) {
			printf ("Najpopularnija boja je crvena (%.2f%).", postotak);
			return 0;
		}
		else if (pop == p) {
			printf ("Najpopularnija boja je plava (%.2f%).", postotak);
			return 0;
		}
		
		
	
	return 0;
}