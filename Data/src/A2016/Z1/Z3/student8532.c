#include <stdio.h>

int main() {
	
	char slovo;
	int crnibrojac=0, bijelibrojac=0, sivibrojac=0, crvenibrojac=0, plavibrojac=0, brojac=0;
	float postotak=0;
	
	printf("Unesite vozila: ");
	
	do {
		scanf ("%c", &slovo);
		
		if (slovo =='c' || slovo == 'C') {
		crnibrojac++;
		brojac++;
		}
		else if (slovo == 'b' || slovo == 'B') {
		bijelibrojac++;
		brojac++;
		}
		else if (slovo == 's' || slovo == 'S') {
		sivibrojac++;
		brojac++;
		}
		else if (slovo == 'v' || slovo == 'V') {
		crvenibrojac++;
		brojac++;
		}
		else if (slovo == 'p' || slovo == 'P') {
		plavibrojac++;
		brojac++;
		}
		else {
			if (slovo == 'k' || slovo == 'K')
			continue;
			else
			printf ("Neispravan unos\n");
		}
	} while ( slovo != 'k' && slovo != 'K' );
	
	printf ("Ukupno evidentirano %d vozila.\n", brojac);
	
	if (crnibrojac>=bijelibrojac && crnibrojac>=sivibrojac && crnibrojac>=crvenibrojac && crnibrojac>=plavibrojac) {
		postotak = (((float)crnibrojac/brojac)*100);
		if (brojac == 0)
		postotak = 0;
		
		printf ("Najpopularnija boja je crna (%.2f%%).", postotak);
	}
	else if (bijelibrojac>=crnibrojac && bijelibrojac>=sivibrojac && bijelibrojac>=crvenibrojac && bijelibrojac>=plavibrojac) {
		postotak = (((float)bijelibrojac/brojac)*100);
		printf ("Najpopularnija boja je bijela (%.2f%%).", postotak);
	}
	else if (sivibrojac>=crnibrojac && sivibrojac >= bijelibrojac && sivibrojac>=crvenibrojac && sivibrojac>=plavibrojac) {
		postotak = (((float)sivibrojac/brojac)*100);
		printf ("Najpopularnija boja je siva (%.2f%%).", postotak);
	}
	else if (crvenibrojac>=crnibrojac && crvenibrojac >=bijelibrojac && crvenibrojac>=sivibrojac && crvenibrojac>=plavibrojac) {
		postotak = (((float)crvenibrojac/brojac)*100);
		printf ("Najpopularnija boja je crvena (%.2f%%).", postotak);
	}
	else if (plavibrojac>=crnibrojac && plavibrojac>=bijelibrojac && plavibrojac>=sivibrojac && plavibrojac>=crvenibrojac) {
		postotak = (((float)plavibrojac/brojac)*100);
		printf ("Najpopularnija boja je plava (%.2f%%).", postotak);
	}
	
	return 0;
}