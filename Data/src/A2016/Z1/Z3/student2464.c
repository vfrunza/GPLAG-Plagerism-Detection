#include <stdio.h>

int main() {
	int crna=0, bijela=0, siva=0, crvena=0, plava=0;
	int ukvozila, max;
	char znak;
	
	printf ("Unesite vozila: ");
	znak = getchar();
	while (znak == '\n') znak = getchar();
	while (1) {
		if (znak=='C' || znak=='c') crna++;
		else if (znak=='B' || znak=='b') bijela++;
		else if (znak=='S' || znak=='s') siva++;
		else if (znak=='V' || znak=='v') crvena++;
		else if (znak=='P' || znak=='p') plava++;
		else if (znak=='K' || znak=='k') break;
		else printf ("Neispravan unos\n");
		znak = getchar();
		while (znak=='\n') znak = getchar();
	}
	
	ukvozila = crna + plava + siva + bijela + crvena;
	max = 0;
	
	if (crna>max) max = crna;
	if (bijela>max) max = bijela;
	if (siva>max) max = siva;
	if (crvena>max) max = crvena;
	if (plava>max) max = plava;
	
	printf ("Ukupno evidentirano %d vozila.\n", ukvozila);
	if (ukvozila==0) printf ("Najpopularnija boja je crna (0.00%%).");
	else if (max==crna) printf ("Najpopularnija boja je crna (%.2f%%).",((crna*1.)/ukvozila)*100);
	else if (max==bijela) printf ("Najpopularnija boja je bijela (%.2f%%).",((bijela*1.)/ukvozila)*100);
	else if (max==siva) printf ("Najpopularnija boja je siva (%.2f%%).",((siva*1.)/ukvozila)*100);
	else if (max==crvena) printf ("Najpopularnija boja je crvena (%.2f%%).",((crvena*1.)/ukvozila)*100);
	else printf ("Najpopularnija boja je plava (%.2f%%).",((plava*1.)/ukvozila)*100);
	return 0;
}