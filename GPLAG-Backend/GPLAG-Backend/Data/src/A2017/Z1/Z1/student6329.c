#include <stdio.h>

int main() {
	char tarik, bojan, mirza, novired;
	printf ("Unesite jelo za Tarika: ");
	scanf ("%c", &tarik);
	scanf ("%c", &novired);
	printf ("Unesite jelo za Bojana: ");
	scanf ("%c", &bojan);
	scanf ("%c", &novired);
	printf ("Unesite jelo za Mirzu: ");
	scanf ("%c", &mirza);
	scanf ("%c", &novired);
	if (tarik == 'H' && mirza == 'H' && bojan == 'H') {
		printf ("Najjeftiniji je Fast-food \"Trovac\" (9.00 KM).\nSa popustom bi Restoran bio jeftiniji (8.91 KM).");
	}
	if (tarik == 'C' && mirza == 'C' && bojan == 'C') {
		printf ("Najjeftiniji je Fast-food \"Trovac\" (11.70 KM).");
	}
	if (tarik == 'P' && mirza == 'P' && bojan == 'P') {
		printf ("Najjeftiniji je Bistro \"Lorelei\" (15.90 KM).");
	}
	if ((tarik == 'H' && mirza == 'H' && bojan == 'P') || (tarik == 'H' && mirza == 'P' && bojan == 'H') || (tarik == 'P' && mirza == 'H' && bojan == 'H')) { 
		printf ("Najjeftiniji je Restoran \"Kod konja i konjusara\" (13.40 KM).");
	}
	if ((tarik == 'H' && mirza == 'C' && bojan == 'H') || (tarik == 'C' && mirza == 'H' && bojan == 'H') || (tarik == 'H' && mirza == 'H' && bojan == 'C')) {
		printf ("Najjeftiniji je Fast-food \"Trovac\" (9.90 KM).");
	}
	if ((tarik == 'P' && mirza == 'P' && bojan == 'H') || (tarik == 'P' && mirza == 'H' && bojan == 'P') || (tarik == 'H' && mirza == 'P' && bojan == 'P')) {
		printf ("Najjeftiniji je Bistro \"Lorelei\" (15.60 KM).\nSa popustom bi Restoran bio jeftiniji (15.54 KM).");
	}
	if ((tarik == 'C' && mirza == 'C' && bojan == 'H') || (tarik == 'C' && mirza == 'H' && bojan == 'C') || (tarik == 'H' && mirza == 'C' && bojan == 'C')) {
		printf ("Najjeftiniji je Fast-food \"Trovac\" (10.80 KM).");
	}
	if ((tarik == 'P' && mirza == 'P' && bojan == 'C') || (tarik == 'P' && mirza == 'C' && bojan == 'P') || (tarik == 'C' && mirza == 'P' && bojan == 'P')) {
		printf ("Najjeftiniji je Bistro \"Lorelei\" (16.60 KM).");
	}
	if ((tarik == 'C' && mirza == 'C' && bojan == 'P') || (tarik == 'C' && mirza == 'P' && bojan == 'C') || (tarik == 'P' && mirza == 'C' && bojan == 'C')) {
		printf ("Najjeftiniji je Fast-food \"Trovac\" (15.80 KM).");
	}
	if ((tarik == 'C' && mirza == 'P' && bojan == 'H') || (tarik == 'P' && mirza == 'H' && bojan == 'C') || (tarik == 'H' && mirza == 'C' && bojan == 'P')) {
		printf ("Najjeftiniji je Fast-food \"Trovac\" (14.90 KM).\nSa popustom bi Restoran bio jeftiniji (14.42 KM).");
	}
return 0;
}