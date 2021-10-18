#include <stdio.h>
#define POPUST 0.9

int main() {
	char tarik, bojan, mirza, novi_red;
	int p=0, h=0, c=0;
	float ct1, ct2, ct3, cb1, cb2, cb3, cm1, cm2, cm3, C1, C2, C3;
	printf ("Unesite jelo za Tarika: ");
	scanf ("%c", &tarik);
	scanf ("%c", &novi_red);
	printf ("Unesite jelo za Bojana: ");
	scanf ("%c", &bojan);
	scanf ("%c", &novi_red);
	printf ("Unesite jelo za Mirzu: ");
	scanf ("%c", &mirza);
	scanf ("%c", &novi_red);
	if (tarik=='P') {
		ct1=6.8;
		ct2=8;
		ct3=5.3;
		p++;
	}
	else if (tarik=='H') {
		ct1=3.3;
		ct2=3;
		ct3=5;
		h++;
	}
	else if (tarik=='C') {
		ct1=5;
		ct2=3.9;
		ct3=6;
		c++;
	}
	if (bojan=='P') {
		cb1=6.8;
		cb2=8;
		cb3=5.3;
		p++;
	}
	else if (bojan=='H') {
		cb1=3.3;
		cb2=3;
		cb3=5;
		h++;
	}
	else if (bojan=='C') {
		cb1=5;
		cb2=3.9;
		cb3=6;
		c++;
	}
	if (mirza=='P') {
		cm1=6.8;
		cm2=8;
		cm3=5.3;
		p++;
	}
	else if (mirza=='H') {
		cm1=3.3;
		cm2=3;
		cm3=5;
		h++;
	}
	else if (mirza=='C') {
		cm1=5;
		cm2=3.9;
		cm3=6;
		c++;
	}
	C1=ct1+cb1+cm1;
	C2=ct2+cb2+cm2;
	C3=ct3+cb3+cm3;
	if (C1<=C2 && C1<=C3) {
		printf ("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).", C1);
	}
	else if (C2<=C1 && C2<=C3) {
		printf ("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", C2);
		C1=0;
		if (p!=0) {
			C1=p*6.8*POPUST+c*5+h*3.3;
		}
		else if (c!=0) {
			C1=c*5*POPUST+h*3.3;
		}
		else C1=h*3.3*POPUST;
		if (C1<=C2) {
			printf ("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", C1);
		}
	}
	else if (C3<=C1 && C3<=C2) {
		printf ("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).", C3);
		C1=0;
		if (p!=0) {
			C1=p*6.8*POPUST+c*5+h*3.3;
		}
		else if (c!=0) {
			C1=c*5*POPUST+h*3.3;
		}
		else C1=h*3.3*POPUST;
		if (C1<=C3) {
			printf ("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", C1);
		}
	}
	
	return 0;
}
