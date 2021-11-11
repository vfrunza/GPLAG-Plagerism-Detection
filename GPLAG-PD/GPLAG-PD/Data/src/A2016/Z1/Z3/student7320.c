#include <stdio.h>

int main() {
	char c;
	double val;
	int crna, crvena, bijela, siva, plava, uk;
	crna = crvena = bijela = siva = plava = uk = 0;
	printf("Unesite vozila: ");
	while (1) {
		c = getchar();
		if (c == 'k' || c == 'K') {
			break;
		}
		else if (c == 'C' || c == 'c') crna++;
		else if (c == 'b' || c == 'B') bijela++;
		else if (c == 's' || c == 'S') siva++;
		else if (c == 'v' || c == 'V') crvena++;
		else if (c == 'p' || c == 'P') plava++;
		else {
			printf("Neispravan unos\n");
		}
		
	}
	
	uk = crna + bijela + siva + crvena + plava;
	printf("Ukupno evidentirano %d vozila.\n", uk);
	printf("Najpopularnija boja je ");
	
	if (uk == 0) {
		printf("crna (0.00%%).\n");
		return 0;
	}
	int max = 0;
	if (crna > max) max = crna;
	if (bijela > max) max = bijela;
	if (siva > max) max = siva;
	if (crvena > max) max = crvena;
	if (plava > max) max = plava;
	
	if (max == crna) {
		val = (crna * 1. / uk * 1.);
		val *= 100.;
		printf("crna (%.2f%%).\n", val);
	}
	else if (max == bijela) {
		val = (bijela * 1. / uk * 1.);
		val *= 100.;
		printf("bijela (%.2f%%).\n", val);
	}
	else if (max == siva) {
		val = (siva * 1. / uk * 1.);
		val *= 100.;
		printf("siva (%.2f%%).\n", val);
	}
	else if (max == crvena) {
		val = (crvena * 1. / uk * 1.);
		val *= 100.;
		printf("crvena (%.2f%%).\n", val);
	}
	else if (max == plava) {
		val = (plava * 1. / uk * 1.);
		val *= 100.;
		printf("plava (%.2f%%).\n", val);
	}
	return 0;
}
