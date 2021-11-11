#include <stdio.h>

int main() {
	int  brojacS=0, brojacV=0, brojacP=0, brojacC=0, brojacB=0;
	double pc, pb, ps, pv, pp, suma;
	char znak='a';
	printf("Unesite vozila: ");
	while(znak!='K' && znak!='k') {
		scanf ("%c", &znak);
		if (znak=='K' || znak=='k') break;
		else if (znak==' ') {
			printf ("Neispravan unos\n"); continue;
		}
		
		if (znak=='c' || znak=='C') {
			brojacC++;
		}
		else if (znak=='b' || znak=='B') {
			brojacB++;
		}
		else if (znak=='s' || znak=='S') {
			brojacS++;
		}
		else if (znak=='v' || znak=='V') {
			brojacV++;
		}
		else if (znak=='p' || znak=='P') {
			brojacP++;
		}
		else if (znak!='K' || znak!='k' || znak!='c' || znak!='C' || znak!='B' || znak!='b' || znak!='s' || znak!='S' || znak!='V' || znak!='v' || znak!='p' || znak!='P') {
			printf ("Neispravan unos\n"); continue;
		}
	}
	suma=brojacC+brojacB+brojacP+brojacV+brojacS;
	
	printf ("Ukupno evidentirano %.0lf vozila.\n", suma);
	if (brojacC>=brojacB && brojacC>=brojacP && brojacC>=brojacV && brojacC>=brojacS) {
		pc=(brojacC/suma)*100;
		if(brojacC==0) pc=0.00;
		printf ("Najpopularnija boja je crna (%.2lf%%).", pc);
	}
	else if (brojacS>=brojacC && brojacS>=brojacV && brojacS>=brojacP && brojacS>=brojacB) {
		ps=(brojacS/suma)*100;
		printf ("Najpopularnija boja je siva (%.2lf%%).", ps);
	}
	else if (brojacB>=brojacS && brojacB>=brojacP && brojacB>=brojacV && brojacB>=brojacC) {
		pb=(brojacB/suma)*100;
		printf ("Najpopularnija boja je bijela (%.2lf%%).", pb);
	}
	else if (brojacV>=brojacC && brojacV>=brojacB && brojacV>=brojacP && brojacV>=brojacS) {
		pv=(brojacV/suma)*100;
		printf ("Najpopularnija boja je crvena (%.2lf%%).", pv);
	}
	else if (brojacP>=brojacV && brojacP>=brojacS && brojacP>=brojacB && brojacP>=brojacC) {
		pp=(brojacP/suma)*100;
		printf ("Najpopularnija boja je plava (%.2lf%%).", pp);
	}
	return 0;
}
