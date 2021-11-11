#include <stdio.h>

int main() {
	char T, B, M, NR, brojacH = 0, brojacP = 0, brojacC = 0;
	float SumaR = 0, SumaFF = 0, SumaB = 0, pH = 0, pP = 0, pC = 0, Popust = 0;
	
	printf ("Unesite jelo za Tarika: ");
	scanf ("%c", &T);
	scanf ("%c", &NR);
	
	printf ("Unesite jelo za Bojana: ");
	scanf ("%c", &B);
	scanf ("%c", &NR);
	
	printf ("Unesite jelo za Mirzu: ");
	scanf ("%c", &M);
	scanf ("%c", &NR);
	
	/* Tarikov izbor jela */
	if (T == 'P') {
		SumaR += 6.80;
		SumaFF += 8;
		SumaB += 5.30;
		pP += 6.12;
		brojacP++;
	}
	else if (T == 'H') {
		SumaR += 3.30;
		SumaFF += 3;
		SumaB += 5;
		pH += 2.97;
		brojacH++;
	}
	else if (T == 'C') {
		SumaR += 5;
		SumaFF += 3.90;
		SumaB += 6;
		pC += 4.5;
		brojacC++;
	}
	
	/* Bojanov izbor jela */
	if (B == 'P') {
		SumaR += 6.80;
		SumaFF += 8;
		SumaB += 5.30;
		pP += 6.12;
		brojacP++;
	}
	else if (B == 'H') {
		SumaR += 3.30;
		SumaFF += 3;
		SumaB += 5;
		pH += 2.97;
		brojacH++;
	}
	else if (B == 'C') {
		SumaR += 5;
		SumaFF += 3.90;
		SumaB += 6;
		pC += 4.5;
		brojacC++;
	}
	
	/* Mirzin izbor jela */
	if (M == 'P') {
		SumaR += 6.80;
		SumaFF += 8;
		SumaB += 5.30;
		pP += 6.12;
		brojacP++;
	}
	else if (M == 'H') {
		SumaR += 3.30;
		SumaFF += 3;
		SumaB += 5;
		pH += 2.97;
		brojacH++;
	}
	else if (M == 'C') {
		SumaR += 5;
		SumaFF += 3.90;
		SumaB += 6;
		pC += 4.5;
		brojacC++;
	}
	
	if (pP > pH && pP > pC) {
		Popust = brojacP*6.12 + brojacH*3.30 + brojacC*5;
	}
	else if (pH > pP && pH > pC) {
		Popust = 6.8*brojacP + brojacH*2.97 + brojacC*5;
	}
	else {
		Popust = brojacP*6.8 + brojacH*3.30 + brojacC*4.5;
	}
	
	/* Poredenje cijena jela */
	if (SumaR < SumaFF && SumaR < SumaB) {
		printf ("Najjeftiniji je Restoran %cKod konja i konjusara%c (%.2f KM).\n", 34, 34, SumaR);
	}
	else if (SumaFF < SumaR && SumaFF < SumaB) {
		printf ("Najjeftiniji je Fast-food %cTrovac%c (%.2f KM).\n", 34, 34, SumaFF);
		if (Popust < SumaFF) {
			printf ("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", Popust);
		}
	}
	else if (SumaB < SumaR && SumaB < SumaFF) {
		printf ("Najjeftiniji je Bistro %cLorelei%c (%.2f KM).\n", 34, 34, SumaB);
		if (Popust < SumaB) {
			printf ("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", Popust);
		}
	}
	
	return 0;
}