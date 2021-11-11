#include <stdio.h>

int main() {
	char a=0, b, crni=0, bijeli=0, sivi=0, crveni=0, plavi=0;
	float U, Pc, Pb, Ps, Pv, Pp;
	printf ("Unesite vozila: ");
	while (a!=1) {
	scanf ("%c", &b);
	if (b=='c' || b=='C') {
		crni++;
	} if (b=='b' || b=='B') {
		bijeli++;
	} if (b=='s' || b=='S') {
		sivi++;
	} if (b=='v' || b=='V') {
		crveni++;
	} if (b=='p' || b=='P') {
		plavi++;
	} if (b=='k' || b=='K') {
		a=1;
	}
	if (b!='c' && b!='C' && b!='b' && b!='B' && b!='s' && b!='S' && b!='v' && b!='V' && b!='p' && b!='P' && b!='k' && b!='K') {
		printf ("Neispravan unos\n");
	}
	}
	U=crni+bijeli+sivi+crveni+plavi;
	printf ("Ukupno evidentirano %g vozila.", U);
	Pc=crni*100/U;
	Pb=bijeli*100/U;
	Ps=sivi*100/U;
	Pv=crveni*100/U;
	Pp=plavi*100/U;
	if (Pc>=Pb && Pc>=Ps && Pc>=Pv && Pc>=Pp) {
		printf ("\nNajpopularnija boja je crna (%.2f%%).", Pc);
	}
	if (Pb>Pc && Pb>=Ps && Pb>=Pv && Pb>=Pp) {
		printf ("\nNajpopularnija boja je bijela (%.2f%%).", Pb);
	}
	if (Ps>Pc && Ps>Pb && Ps>=Pv && Ps>=Pp) {
		printf ("\nNajpopularnija boja je siva (%.2f%%).", Ps);
	}
	if (Pv>Pc && Pv>Pb && Pv>Ps && Pv>=Pp) {
		printf ("\nNajpopularnija boja je crvena (%.2f%%).", Pv);
	}
	if (Pp>Pc && Pp>Pb && Pp>Ps && Pp>Pv) {
		printf ("\nNajpopularnija boja je plava (%.2f%%).", Pp);
	}
	if (U==0) {
		printf ("\nNajpopularnija boja je crna (0.00%%).");
	}
	return 0;
}
