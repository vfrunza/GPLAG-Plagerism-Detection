#include <stdio.h>
int main() {
	float procenat;
	char boja;
	int A=0,C=0,B=0,S=0,V=0,P=0;
	printf("Unesite vozila: ");
	do {
		scanf(" %c",&boja);
		A++;
		if (boja=='c' || boja=='C') C++;
		else if (boja=='b' || boja=='B') B++;
		else if (boja=='s' || boja=='S') S++;
		else if (boja=='v' || boja=='V') V++;
		else if (boja=='p' || boja=='P') P++;
		else printf("Neispravan unos\n");
	}
	while (boja!='k' || boja!='K');
	if (C>B && C>S && C>V && C>P) {
		procenat=C/A;
		printf("Ukupno evidentirano %d vozila.\nNajpopularnija boja je bijela (%.2f %).",A,procenat);
	}
	else if (B>C && B>S && B>V && B>P) {
		procenat=B/A;
		printf("Ukupno evidentirano %d vozila.\nNajpopularnija boja je crna (%.2f %).",A,procenat);
	}
	else if (S>B && S>C && S>V && S>P) {
		procenat=S/A;
		printf("Ukupno evidentirano %d vozila.\nNajpopularnija boja je siva (%.2 f%).",A,procenat);
	}
	else if (V>B && V>C && V>S && V>P) {
		procenat=V/A;
		printf("Ukupno evidentirano %d vozila.\nNajpopularnija boja je crvena (%.2f %).",A,procenat);
	}
	else if (P>B && P>C && P>V && P>S) {
		procenat=P/A;
		printf("Ukupno evidentirano %d vozila.\nNajpopularnija boja je plava (%.2f%).",A,procenat);
	}
	return 0;
}