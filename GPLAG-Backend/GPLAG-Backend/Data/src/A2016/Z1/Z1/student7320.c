#include <stdio.h>

int main() {
	// parcijala max 20
	// zadaca max 10
	// prisustvo max 10
	// zavrsni max 40
	double parc11, parc21, prisustvo1, zadaca1, zavrsni1;
	double parc12, parc22, prisustvo2, zadaca2, zavrsni2;
	double parc13, parc23, prisustvo3, zadaca3, zavrsni3;
	
	printf("Unesite bodove za Tarika: \n");
	printf("I parcijalni ispit: ");
	scanf("%lf", &parc11);
	if (parc11 < 0. || parc11 > 20.) {
		printf("Neispravan broj bodova\n");
		return 0;
	}
	printf("II parcijalni ispit: ");
	scanf("%lf", &parc21);
	if (parc21 < 0. || parc21 > 20.) {
		printf("Neispravan broj bodova\n");
		return 0;
	}
	printf("Prisustvo: ");
	scanf("%lf", &prisustvo1);
	if (prisustvo1 < 0. || prisustvo1 > 10.) {
		printf("Neispravan broj bodova\n");
		return 0;
	}
	printf("Zadace: ");
	scanf("%lf", &zadaca1);
	if (zadaca1 < 0. || zadaca1 > 10.) {
		printf("Neispravan broj bodova\n");
		return 0;
	}
	printf("Zavrsni ispit: ");
	scanf("%lf", &zavrsni1);
	if (zavrsni1 < 0. || zavrsni1 > 40.) {
		printf("Neispravan broj bodova\n");
		return 0;
	}
	
	
	
	printf("Unesite bodove za Bojana: \n");
	printf("I parcijalni ispit: ");
	scanf("%lf", &parc12);
	if (parc12 < 0. || parc12 > 20.) {
		printf("Neispravan broj bodova\n");
		return 0;
	}
	printf("II parcijalni ispit: ");
	scanf("%lf", &parc22);
	if (parc22 < 0. || parc22 > 20.) {
		printf("Neispravan broj bodova\n");
		return 0;
	}
	printf("Prisustvo: ");
	scanf("%lf", &prisustvo2);
	if (prisustvo2 < 0. || prisustvo2 > 10.) {
		printf("Neispravan broj bodova\n");
		return 0;
	}
	printf("Zadace: ");
	scanf("%lf", &zadaca2);
	if (zadaca2 < 0. || zadaca2 > 10.) {
		printf("Neispravan broj bodova\n");
		return 0;
	}
	printf("Zavrsni ispit: ");
	scanf("%lf", &zavrsni2);
	if (zavrsni2 < 0. || zavrsni2 > 40.) {
		printf("Neispravan broj bodova\n");
		return 0;
	}
	
	
	printf("Unesite bodove za Mirzu: \n");
	printf("I parcijalni ispit: ");
	scanf("%lf", &parc13);
	if (parc13 < 0. || parc13 > 20.) {
		printf("Neispravan broj bodova\n");
		return 0;
	}
	printf("II parcijalni ispit: ");
	scanf("%lf", &parc23);
	if (parc23 < 0. || parc23 > 20.) {
		printf("Neispravan broj bodova\n");
		return 0;
	}
	printf("Prisustvo: ");
	scanf("%lf", &prisustvo3);
	if (prisustvo3 < 0. || prisustvo3 > 10.) {
		printf("Neispravan broj bodova\n");
		return 0;
	}
	printf("Zadace: ");
	scanf("%lf", &zadaca3);
	if (zadaca3 < 0. || zadaca3 > 10.) {
		printf("Neispravan broj bodova\n");
		return 0;
	}
	printf("Zavrsni ispit: ");
	scanf("%lf", &zavrsni3);
	if (zavrsni3 < 0. || zavrsni3 > 40.) {
		printf("Neispravan broj bodova\n");
		return 0;
	}
	
	int ocjena1, ocjena2, ocjena3;
	int broj_koliko_je_polozilo = 0;
	int broj_razlicitih_ocjena = 1;
	double suma1, suma2, suma3;
	suma1 = parc11 + parc21 + zadaca1 + prisustvo1 + zavrsni1;
	suma2 = parc12 + parc22 + zadaca2 + prisustvo2 + zavrsni2;
	suma3 = parc13 + parc23 + zadaca3 + prisustvo3 + zavrsni3;
	
	if (suma1 < 55) ocjena1 = 0;
	else if (suma1 >= 55 && suma1 < 65) ocjena1 = 6;
	else if (suma1 >= 65 && suma1 < 75) ocjena1 = 7;
	else if (suma1 >= 75 && suma1 < 85) ocjena1 = 8;
	else if (suma1 >= 85 && suma1 < 92) ocjena1 = 9;
	else if (suma1 >= 92 && suma1 <= 100) ocjena1 = 10;
	
	if (suma2 < 55) ocjena2 = 0;
	else if (suma2 >= 55 && suma2 < 65) ocjena2 = 6;
	else if (suma2 >= 65 && suma2 < 75) ocjena2 = 7;
	else if (suma2 >= 75 && suma2 < 85) ocjena2 = 8;
	else if (suma2 >= 85 && suma2 < 92) ocjena2 = 9;
	else if (suma2 >= 92 && suma2 <= 100) ocjena2 = 10;
	
	if (suma3 < 55) ocjena3 = 0;
	else if (suma3 >= 55 && suma3 < 65) ocjena3 = 6;
	else if (suma3 >= 65 && suma3 < 75) ocjena3 = 7;
	else if (suma3 >= 75 && suma3 < 85) ocjena3 = 8;
	else if (suma3 >= 85 && suma3 < 92) ocjena3 = 9;
	else if (suma3 >= 92 && suma3 <= 100) ocjena3 = 10;
	
	if (ocjena1 != 0) broj_koliko_je_polozilo++;
	if (ocjena2 != 0) broj_koliko_je_polozilo++;
	if (ocjena3 != 0) broj_koliko_je_polozilo++;
	
	if (broj_koliko_je_polozilo == 0) printf("Nijedan student nije polozio.\n");
	else if (broj_koliko_je_polozilo == 1) printf("Jedan student je polozio.\n");
	else if (broj_koliko_je_polozilo == 2) printf("Dva studenta su polozila.\n");
	else if (broj_koliko_je_polozilo == 3) printf("Sva tri studenta su polozila.\n");
	
	if (ocjena1 != ocjena2) {
		if (ocjena2 == ocjena3) broj_razlicitih_ocjena = 2;
		else if (ocjena2 != ocjena3) broj_razlicitih_ocjena = 3;
	}
	else if (ocjena1 == ocjena2) {
		if (ocjena2 == ocjena3) broj_razlicitih_ocjena = 1;
		else if (ocjena2 != ocjena3) broj_razlicitih_ocjena = 2;
	}
	if (broj_koliko_je_polozilo == 3) {
		if (broj_razlicitih_ocjena == 1) printf("Sva tri studenta imaju istu ocjenu.\n");
		else if (broj_razlicitih_ocjena == 2) printf("Dva od tri studenta imaju istu ocjenu.\n");
		else if (broj_razlicitih_ocjena == 3) printf("Svaki student ima razlicitu ocjenu.\n");
	}
	
	return 0;
}
