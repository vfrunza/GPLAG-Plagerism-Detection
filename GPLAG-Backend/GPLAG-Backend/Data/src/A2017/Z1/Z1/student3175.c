#include <stdio.h>

int main()
{
	double t,b,m,H1=3.30,H2=3.00,H3=5.00,P1=6.80,P2=8.00,P3=5.30,C1=5.00,C2=3.90,C3=6.00,cijena1=0, cijena2=0, cijena3=0;
	char tarik,bojan,mirza,novi_red;
	printf ("Unesite jelo za Tarika: ");
	scanf ("%c", &tarik);
	scanf ("%c", &novi_red);
	printf ("Unesite jelo za Bojana: ");
	scanf ("%c", &bojan);
	scanf ("%c", &novi_red);
	printf ("Unesite jelo za Mirzu: ");
	scanf ("%c", &mirza);
	scanf ("%c", &novi_red);

	if (tarik == 'H') {
		cijena1 += H1;
		cijena2 += H2;
		cijena3 += H3;
	}
	if (tarik == 'P') {
		cijena1 += P1;
		cijena2 += P2;
		cijena3 += P3;
	}
	if (tarik == 'C') {
		cijena1 += C1;
		cijena2 += C2;
		cijena3 += C3;
	}
	if (bojan == 'H') {
		cijena1 += H1;
		cijena2 += H2;
		cijena3 += H3;
	}
	if (bojan == 'P') {
		cijena1 += P1;
		cijena2 += P2;
		cijena3 += P3;
	}
	if (bojan == 'C') {
		cijena1 += C1;
		cijena2 += C2;
		cijena3 += C3;
	}
	if (mirza == 'H') {
		cijena1 += H1;
		cijena2 += H2;
		cijena3 += H3;
	}
	if (mirza == 'P') {
		cijena1 += P1;
		cijena2 += P2;
		cijena3 += P3;
	}
	if (mirza == 'C') {
		cijena1 += C1;
		cijena2 += C2;
		cijena3 += C3;
	}
	double min;
	min = cijena1;
	if (min>cijena2) {
		min = cijena2;
	}
	if (min>cijena3) {
		min = cijena3;
	}

	if (min == cijena1) {
		printf ("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).", min);
	} else if (min == cijena2) {
		printf ("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", min);
	} else {
		printf ("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).", min);
	}
	double popust;
	if (tarik == 'P' || bojan == 'P' || mirza == 'P') {
		if (tarik == 'P') popust = (cijena1 -=  P1*0.1);
		if (bojan == 'P') popust = (cijena1 -=  P1*0.1);
		if (mirza == 'P') popust = (cijena1 -=  P1*0.1);
	} else if (tarik == 'H' || bojan == 'H' || mirza == 'H') {
		if (tarik == 'H') popust = (cijena1 -= H1*0.1);
		if (bojan == 'H') popust = (cijena1 -= H1*0.1);
		if (mirza == 'H') popust = (cijena1 -= H1*0.1);
	} else {
		if (tarik == 'C') popust = (cijena1 -= C1*0.1);
		if (bojan == 'C') popust = (cijena1 -= C1*0.1);
		if (mirza == 'C') popust = (cijena1 -= C1*0.1);
	}
	if ((min == cijena2) && (min>popust)) {
		printf ("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", popust);
	} else if ((min == cijena3) && (min>popust) ) {
		printf ("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", popust);
	}
	return 0;
}