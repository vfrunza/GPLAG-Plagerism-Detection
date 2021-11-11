#include <stdio.h>

int main() {
	char boja;
	float prosjek;
	int crna=0, bijela=0, siva=0, crvena=0, plava=0, brvozila=0, temp=0;
	printf("Unesite vozila: ");
	do {
		scanf("%c", &boja);
			 if (boja=='C' || boja=='c') {crna++;brvozila++;}
		else if (boja=='B' || boja=='b') {bijela++;brvozila++;}
		else if (boja=='S' || boja=='s') {siva++;brvozila++;}
		else if (boja=='V' || boja=='v') {crvena++;brvozila++;}
		else if (boja=='P' || boja=='p') {plava++;brvozila++;}
		else if (boja=='K' || boja=='k') break;
		else printf("Neispravan unos\n");
	}while(1);
	printf("Ukupno evidentirano %d vozila.", brvozila);
	
	if (crna>=bijela && crna>=siva && crna>=crvena && crna>=plava) temp=crna;
	if (bijela>=crna && bijela>=siva && bijela>=crvena && bijela>=plava) temp=bijela;
	if (siva>=crna && siva>=bijela && siva>=crvena && siva>=plava) temp=siva;
	if (crvena>=crna && crvena>=bijela && crvena>=siva && crvena>=plava) temp=crvena;
	if (plava>=crna && plava>=bijela && plava>=siva && plava>=crvena) temp=plava;
	printf("\n");
	if (brvozila!=0) prosjek=(float)(temp)/brvozila*100;
	else prosjek=0;
	if (temp==crna) printf("Najpopularnija boja je crna (%.2f%%).", prosjek);
	else if (temp==bijela) printf("Najpopularnija boja je bijela (%.2f%%).", prosjek);
	else if (temp==siva) printf("Najpopularnija boja je siva (%.2f%%).", prosjek);
	else if (temp==crvena) printf("Najpopularnija boja je crvena (%.2f%%).", prosjek);
	else if (temp==plava) printf("Najpopularnija boja je plava (%.2f%%).", prosjek);
	return 0;
}