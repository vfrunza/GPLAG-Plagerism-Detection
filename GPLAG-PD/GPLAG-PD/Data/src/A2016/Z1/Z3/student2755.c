#include <stdio.h>
int main () {
	char s;
	int i, brojacC=0, brojacB=0, brojacS=0, brojacV=0, brojacP=0;
	float brojac=0;
	printf("Unesite vozila: ");
	for(i=0; i<10000; i++) {
		scanf("%c", &s);
		if(s=='K' || s=='k') break;
		else if(s!='C' && s!='c' && s!='B' && s!='b' && s!='S' && s!='s' && s!='V' && s!='v' && s!='P' && s!='p') {
			printf("Neispravan unos\n");
			i--;
			brojac--;
		}
		if(s=='C' || s=='c') brojacC++;
		if(s=='B' || s=='b') brojacB++;
		if(s=='S' || s=='s') brojacS++;
		if(s=='V' || s=='v') brojacV++;
		if(s=='P' || s=='p') brojacP++;
		brojac++;
	}
	printf("Ukupno evidentirano %g vozila.\n", brojac);
	if(brojacC>=brojacB && brojacC>=brojacS && brojacC>=brojacV && brojacC>=brojacP) {
		if(brojac==0)
			printf("Najpopularnija boja je crna (0.00%%).");
		else
			printf("Najpopularnija boja je crna (%.2f%%).", (brojacC/brojac)*100);
	}
	else if(brojacB>brojacC && brojacB>=brojacS && brojacB>=brojacV && brojacB>=brojacP){
		if(brojac==0)
			printf("Najpopularnija boja je bijela (0.00%%).");
		else
			printf("Najpopularnija boja je bijela (%.2f%%).", (brojacB/brojac)*100);
	}
	else if(brojacS>brojacC && brojacS>brojacB && brojacS>=brojacV && brojacS>=brojacP) {
		if(brojac==0)
			printf("Najpopularnija boja je siva (0.00%%).");
		else
			printf("Najpopularnija boja je siva (%.2f%%).", (brojacS/brojac)*100);
	}
	else if(brojacV>brojacC && brojacV>brojacB && brojacV>brojacS && brojacV>=brojacP){
		if(brojac == 0)
			printf("Najpopularnija boja je crvena (0.00%%).");
		else
			printf("Najpopularnija boja je crvena (%.2f%%).", (brojacV/brojac)*100);
	}
	else {
		if(brojac == 0)
			printf("Napopularnija boja je plava (0.00%%).");
		else
			printf("Najpopularnija boja je plava (%.2f%%).", (brojacP/brojac)*100);
	}
	return 0;	
}