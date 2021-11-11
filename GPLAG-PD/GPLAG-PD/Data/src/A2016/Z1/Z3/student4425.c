#include <stdio.h>

int main() {
	
	int crna=0, bijela=0, siva=0, crvena=0, plava=0, ukupno=0, max=0, boje=0;
	char karakter;
	
	printf ("Unesite vozila: ");
	
	for (;;) {
		scanf("%c", &karakter);
		
		if (karakter=='K' || karakter=='k') break;
		
		if (karakter!='C' && karakter!='c' && karakter!='B' && karakter!='b' &&
			karakter!='S' && karakter!='s' && karakter!='V' && karakter!='v' &&
			karakter!='P' && karakter!='p' && karakter!='K' && karakter!='k') {
				printf("Neispravan unos\n");
				continue;
			}
		
		if (karakter=='C' || karakter=='c') crna++;
		if (karakter=='B' || karakter=='b') bijela++;
		if (karakter=='S' || karakter=='s') siva++;
		if (karakter=='V' || karakter=='v') crvena++;
		if (karakter=='P' || karakter=='p') plava++;
	}
	
	ukupno=crna+bijela+siva+crvena+plava;
	printf("Ukupno evidentirano %d vozila.\n", ukupno);
	
	max=crna;
	if (bijela>max) max=bijela;
	if (siva>max) max=siva;
	if (crvena>max) max=crvena;
	if (plava>max) max=plava;
	
	if (max==crna) boje=1;
	else if (max==bijela) boje=2;
	else if (max==siva) boje=3;
	else if (max==crvena) boje=4;
	else if (max==plava) boje=5;
	
	switch (boje) {
		case 1:
				if (ukupno==0) {
					printf("Najpopularnija boja je crna (0.00%%).");
				} else {
					printf("Najpopularnija boja je crna (%.2f%%).", 1.0*100*crna/ukupno);
				}
				break;
		case 2:
				printf("Najpopularnija boja je bijela (%.2f%%).", 1.0*100*bijela/ukupno);
				break;
		case 3:
				printf("Najpopularnija boja je siva (%.2f%%).", 1.0*100*siva/ukupno);
				break;
		case 4:
				printf("Najpopularnija boja je crvena (%.2f%%).", 1.0*100*crvena/ukupno);
				break;
		case 5:
				printf("Najpopularnija boja je plava (%.2f%%).", 1.0*100*plava/ukupno);
				break;
	}
	
	return 0;
}
