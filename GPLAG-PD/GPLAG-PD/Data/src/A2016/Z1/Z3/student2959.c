#include <stdio.h>
int main () {
	char x;
	int crna=0, bijela=0, siva=0, crvena=0, plava=0, ukupno=0;
	float posc, posb, poss, posv, posp;
	printf ("Unesite vozila: ");
	for (; ;) {
		scanf ("%c",&x);
		if (x!='C' && x!='c' && x!='B' && x!='b' && x!='S' && x!='s' && x!='V' && x!='v' && x!='P' && x!='p' && x!='K' && x!='k') {
			printf ("Neispravan unos\n");
		}
		if (x=='K' || x=='k')  break;
		if (x=='C' || x=='c')  crna++;
		if (x=='B' || x=='b')  bijela++;
		if (x=='S' || x=='s')  siva++;
		if (x=='V' || x=='v')  crvena++;
		if (x=='P' || x=='p')  plava++;
	}
	ukupno = crna + bijela + siva + crvena + plava;
	printf ("Ukupno evidentirano %d vozila.\n",ukupno);
	if (ukupno==0)  printf ("Najpopularnija boja je crna (0.00%).");
	if (crna>=bijela && crna>=siva && crna>=crvena && crna>=plava && ukupno!=0) {
		posc = (crna*100.)/ukupno;
		printf ("Najpopularnija boja je crna (%.2f%%).",posc);
	}
	if (bijela>crna && bijela>=siva && bijela>=crvena && bijela>=plava && ukupno!=0) {
		posb = (bijela*100.)/ukupno;
		printf ("Najpopularnija boja je bijela (%.2f%%).",posb);
	}
	if (siva>crna && siva>bijela && siva>=crvena && siva>=plava && ukupno!=0) {
		poss = (siva*100.)/ukupno;
		printf ("Najpopularnija boja je siva (%.2f%%).",poss);
	}
	if (crvena>crna && crvena>bijela && crvena>siva && crvena>=plava && ukupno!=0) {
		posv = (crvena*100.)/ukupno;
		printf ("Najpopularnija boja je crvena (%.2f%%).",posv);
	}
	if (plava>crna && plava>bijela && plava>siva && plava>crvena && ukupno!=0) {
		posp = (plava*100.)/ukupno;
		printf ("Najpopularnija boja je plava (%.2f%%).",posp);
	}
	return 0;
}
