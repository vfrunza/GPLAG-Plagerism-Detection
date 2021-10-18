#include <stdio.h>

#define RP 6.80 /*Cijena pice u Restoranu kod konja i konjusara*/
#define RH 3.30 /*Cijena hamburgera u Restoranu kod konja i konjusara*/
#define RC 5.00 /*Cijena cevapa u Restoranu kod konja i konjusara*/
#define TP 8.00 /*Cijena pizze u Trovacu*/
#define TH 3.00 /*Cijena hamburgera u Trovacu*/
#define TC 3.90
#define BP 5.30
#define BH 5.00
#define BC 6.00

int main ()
{

	double suma1=0; /*Restoran*/
	double suma2=0; /*Trovac*/
	double suma3=0; /*Bistro*/

	char jeloT, jeloM, jeloB, novi_red;

	printf ("Unesite jelo za Tarika: ");
	scanf ("%c", &jeloT);
	scanf ("%c", &novi_red);

	if (jeloT=='P') {
		suma1+=RP;
		suma2+=TP;
		suma3+=BP;
	}

	else if (jeloT=='H') {

		suma1+=RH;
		suma2+=TH;
		suma3+=BH;

	}

	else if (jeloT=='C') {

		suma1+=RC;
		suma2+=TC;
		suma3+=BC;

	}

	printf ("Unesite jelo za Bojana: ");
	scanf ("%c", &jeloB);
	scanf ("%c", &novi_red);

	if (jeloB=='P') {
		suma1+=RP;
		suma2+=TP;
		suma3+=BP;
	}

	else if (jeloB=='H') {
		suma1+=RH;
		suma2+=TH;
		suma3+=BH;
	}

	else if (jeloB=='C') {
		suma1+=RC;
		suma2+=TC;
		suma3+=BC;
	}

	printf("Unesite jelo za Mirzu: ");
	scanf ("%c", &jeloM);
	scanf ("%c", &novi_red);

	if (jeloM=='P') {
		suma1+=RP;
		suma2+=TP;
		suma3+=BP;
	}

	else if (jeloM=='H') {
		suma1+=RH;
		suma2+=TH;
		suma3+=BH;
	}

	else if (jeloM=='C') {
		suma1+=RC;
		suma2+=TC;
		suma3+=BC;
	}

	if (suma1<suma2 && suma1<suma3) {
		printf ("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2lf KM).\n",suma1);
		return 0;
	}

	else if (suma2<suma1 && suma2<suma3) {

		printf ("Najjeftiniji je Fast-food \"Trovac\" (%.2lf KM).\n", suma2);

		if (jeloT=='P' && jeloB=='P' && jeloM=='P') {
			suma1-=0.68*3;
		}

		else if (jeloT=='H' && jeloB=='H' && jeloM=='H') {
			suma1-=0.33*3;
		}

		else if (jeloT=='C' && jeloB=='C' && jeloM=='C') {
			suma1-=0.50;
		} else if (jeloT=='H' && jeloB=='H' && jeloM=='P') {
			suma1-=0.33*2;
		} else if (jeloT=='H' && jeloB=='P' && jeloM=='P') {
			suma1-=0.68*2;
		} else if (jeloT=='H' && jeloB=='H' && jeloM=='C') {
			suma1-=0.33*2;
		} else if (jeloT=='H' && jeloB=='C' && jeloM=='C') {
			suma1-=0.50*2;
		} else if (jeloT=='P' && jeloB=='C' && jeloM=='C') {
			suma1-=0.50;
		} else if (jeloT=='P' && jeloB=='P' && jeloM=='C') {
			suma1-=0.68*2;
		} else if (jeloT=='C' && jeloB=='H' && jeloM=='P') {
			suma1-=0.68;
		}
	   

		if  (suma1<suma2) printf ("\nSa popustom bi Restoran bio jeftiniji (%.2lf KM).\n", suma1);
		return 0;
	}


	else if (suma3<suma2 && suma3<suma1) {

		printf ("Najjeftiniji je Bistro \"Lorelei\" (%.2lf KM).", suma3);
		
			if (jeloT=='P' && jeloB=='P' && jeloM=='P') {
			suma1-=0.68*3;
		}

		else if (jeloT=='H' && jeloB=='H' && jeloM=='H') {
			suma1-=0.33*3;
		}

		else if (jeloT=='C' && jeloB=='C' && jeloM=='C') {
			suma1-=0.50;
		} else if (jeloT=='H' && jeloB=='H' && jeloM=='P') {
			suma1-=0.33*2;
		} else if (jeloT=='H' && jeloB=='P' && jeloM=='P') {
			suma1-=0.68*2;
		} else if (jeloT=='H' && jeloB=='H' && jeloM=='C') {
			suma1-=0.33*2;
		} else if (jeloT=='H' && jeloB=='C' && jeloM=='C') {
			suma1-=0.50*2;
		} else if (jeloT=='P' && jeloB=='C' && jeloM=='C') {
			suma1-=0.50;
		} else if (jeloT=='P' && jeloB=='P' && jeloM=='C') {
			suma1-=0.68*2;
		} else if (jeloT=='C' && jeloB=='H' && jeloM=='P') {
			suma1-=0.68;
		}

	
		if (suma1<suma3) printf ("\nSa popustom bi Restoran bio jeftiniji (%.2lf KM).\n", suma1);

	}
	return 0;

}
