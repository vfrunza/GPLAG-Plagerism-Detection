#include <stdio.h>

int main() {
	int ukupno, crna=0, bijela=0, siva=0, crvena=0, plava=0;
	char boja;
	int bigg;
	printf("Unesite vozila: ");
	
	for(boja=0; ; ) {
		scanf("%c", &boja);
		if(boja=='c' || boja=='C') {
			crna++;
		} else if(boja=='b' || boja=='B') {
			bijela++;
		} else if(boja=='s' || boja=='S') {
			siva++;
		} else if(boja=='v' || boja=='V') {
			crvena++;
		} else if(boja=='p' || boja=='P') {
			plava++;
		} else if(boja=='k' || boja=='K') {
			break;
		} else {
			printf("Neispravan unos\n");
			continue;
		}
		}
	
	
	ukupno=crna+bijela+siva+crvena+plava;
	printf("Ukupno evidentirano %d vozila.", ukupno);
	
	if(crna>=bijela && crna>=siva && crna>=crvena && crna>=plava) {
		bigg=crna;
	} else if (bijela>=siva && bijela>=crvena && bijela>=plava) {
		bigg=bijela;
	} else if (siva>=crvena && siva>=plava) {
		bigg=siva;
	} else if(crvena>=plava) {
		bigg=crvena;
	} else {
		bigg=plava; }
	
	if(bigg==crna && crna==0) {
	printf("\nNajpopularnija boja je crna (0.00%%).");
	} else if (bigg==crna) {
	printf("\nNajpopularnija boja je crna (%.2f%%).", (float)bigg/ukupno*100 );
	} else if(bigg==bijela) {
	printf("\nNajpopularnija boja je bijela (%.2f%%).", (float)bigg/ukupno*100 );
	} else if(bigg==siva) {
	printf("\nNajpopularnija boja je siva (%.2f%%).", (float)bigg/ukupno*100 );
	} else if(bigg==crvena) {
	printf("\nNajpopularnija boja je crvena (%.2f%%).", (float)bigg/ukupno*100 );
	} else{
	printf("\nNajpopularnija boja je plava (%.2f%%).", (float)bigg/ukupno*100 );
	}
	return 0;
}
