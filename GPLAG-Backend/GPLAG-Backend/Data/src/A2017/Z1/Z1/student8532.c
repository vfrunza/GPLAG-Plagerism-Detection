#include <stdio.h>

int main()
{

	int brp = 0, brh = 0, brc = 0, i;
	char t,b,m, taberu;
	float r, f, bi, p, popust = 0, bc = 6.00, bh = 5.00, bp = 5.30, fc = 3.90, fh = 3.00, fp = 8.00, rc = 5.00, rh = 3.30, rp = 6.80;

	printf("Unesite jelo za Tarika: ");
	scanf("%c",&t);
	scanf("%c",&taberu);

	printf("Unesite jelo za Bojana: ");
	scanf("%c",&b);
	scanf("%c",&taberu);

	printf("Unesite jelo za Mirzu: ");
	scanf("%c",&m);
	scanf("%c",&taberu);

	if (t == 80) brp++;
	else if (t == 72) brh++;
	else if (t == 67) brc++;

	if (b == 80) brp++;
	else if (b == 72) brh++;
	else if (b == 67) brc++;

	if (m == 80) brp++;
	else if (m == 72) brh++;
	else if (m == 67) brc++;

	if ( brp== 1 && brh == 1 && brc == 1 ) {
		r = rp + rh + rc;
		f = fp + fh + fc;
		bi = bp + bh + bc;
		p  = rp * 0.1;
	}
	if (brp == 3) {
		bi= 3 * bp;
		r = 3 * rp;
		f = 3 * fp;
		p = 3* rp * 0.1;
	} else if (brh == 3) {
		r = 3 * rh;
		f = 3 * fh;
		bi= 3 * bh;
		p = 3 * rh * 0.1;
	} else if (brc == 3) {
		r = 3 * rc;
		f = 3 * fc;
		bi = 3 * bc;
		p = 3 * rc * 0.1;
	} else if (brp == 2 && brh == 1) {
		r = 2 * rp + rh;
		f = 2 * fp + fh;
		bi = 2 * bp + bh;
		p = 2 * rp * 0.1;
	} else if (brp == 2 && brc == 1) {
		r = 2 * rp + rc;
		f = 2 * fp + fc;
		bi = 2 * bp + bc;
		p = 2 * rp * 0.1;
	} else if (brh == 2 && brp == 1) {
		r = 2 * rh + rp;
		f = 2 * fh + fp;
		bi = 2 * bh + bp;
		p =  rp * 0.1;
	} else if (brh == 2 && brc == 1) {
		r = 2 * rh + rc;
		f = 2 * fh + fc;
		bi = 2 * bh + bc;
		p = 2 * rh * 0.1;
	} else if (brc == 2 && brh == 1) {
		r = 2 * rc + rh;
		f = 2 * fc + fh;
		bi = 2 * bc + bh;
		p = 2 * rc * 0.1;
	} else if (brc == 2 && brp == 1) {
		r = 2 * rc + rp;
		f = 2 * fc + fp;
		bi = 2 * bc + bp;
		p = rp * 0.1;
	}
	popust = r - p;
	if (r < f && r < bi) {
		printf ("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).",r);
	}
	if (f < r && f < bi) {
		printf ("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",f);
	} else if (bi < f && bi < r) {
		printf ("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",bi);
	}

	for (i = 0; i < 1; i++) {
		if (popust >= f || popust>= bi || (r < f && r < bi))	break;
		if (popust < f && popust < bi) {
			printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",popust);
		}
	}
	return 0;
}