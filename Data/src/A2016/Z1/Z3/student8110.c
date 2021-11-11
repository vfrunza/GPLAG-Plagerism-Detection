#include <stdio.h>
int main() {
	int Cb=0,Bb=0,Sb=0,Vb=0,Pb=0,UK;
	char znak;
	float Proc,max;
	printf("Unesite vozila: ");
	while (1) {
	scanf("%c", &znak);
	if (znak=='C' || znak=='c') {
		Cb++;
	}
	else if (znak=='B' || znak=='b') {
		Bb++;
	}
	else if (znak=='S' || znak=='s') {
		Sb++;
	}
	else if (znak=='V' || znak=='v') {
		Vb++;
	}
	else if (znak=='P' || znak=='p') {
		Pb++;
	}
	else if (znak=='K' || znak=='k') {
		break;
	}
	else {
		printf("Neispravan unos\n");
	}
	}
	UK=Cb+Bb+Sb+Vb+Pb;
	printf("Ukupno evidentirano %d vozila.", UK);
	if (UK==0) {
		printf("\nNajpopularnija boja je crna (0.00%%).");
		return 0;
	}
	max=Cb;znak='c';
	if (Bb>max) {
		max=Bb;znak='b';
	}
	if (Sb>max) {
		max=Sb;znak='s';
	}
	if (Vb>max) {
		max=Vb;znak='v';
	}
	if (Pb>max) {
		max=Pb;znak='p';
	}
	Proc=(max/UK)*100;
	if (znak=='c') {
	printf("\nNajpopularnija boja je crna (%.2f%%).", Proc);
	}
	if (znak=='b') {
	printf("\nNajpopularnija boja je bijela (%.2f%%).", Proc);
	}
	if (znak=='s') {
	printf("\nNajpopularnija boja je siva (%.2f%%).", Proc);
	}
	if (znak=='v') {
	printf("\nNajpopularnija boja je crvena (%.2f%%).", Proc);
	}
	if (znak=='p') {
	printf("\nNajpopularnija boja je plava (%.2f%%).", Proc);
	}
	return 0;
}
	
	
	
