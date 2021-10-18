#include <stdio.h>
#include <math.h>

int main() {
char b;
float crna,bijela,siva,crvena,plava,p;
int suma;
suma=0;
crna=0;
bijela=0;
siva=0;
crvena=0;
plava=0;
printf("Unesite vozila: ");
do {
	scanf("%c",&b);
	

	if (b=='C' || b=='c') {
		crna++;
		suma++;
	} else if (b=='B' || b=='b') {
		bijela++;
		suma++;
	} else if (b=='S' || b=='s') {
		siva++;
		suma++;
	} else if (b=='V' || b=='v') {
		crvena++;
		suma++;
	} else if (b=='P' || b=='p') {
		plava++;
		suma++;
	} else if (b!='c' && b!='C' && b!='b' && b!='B' && b!='K' && b!='k' && b!='p' && b!='P' && b!='V' && b!='v' && b!='s' && b!='S')
	printf("Neispravan unos\n");
	
	
} while (b!='K' && b!='k');

if (suma==0) { 
	printf("Ukupno evidentirano 0 vozila.");
	printf("\nNajpopularnija boja je crna (0.00%%).");
	return 0;
} else printf("Ukupno evidentirano %d vozila.", suma);

if (crna>=bijela && crna>=siva && crna>=crvena && crna>=plava) {
	p=(crna*100)/suma;
	printf("\nNajpopularnija boja je crna (%.2f%%).",p);
} else if (bijela>=crna && bijela>=siva && bijela>=crvena && bijela>=plava) {
	p=(bijela*100)/suma;
	printf("\nNajpopularnija boja je bijela (%.2f%%).",p);
} else if (siva>=crna && siva>=bijela && siva>=crvena && siva>=plava) {
	p=(siva*100)/suma;
	printf("\nNajpopularnija boja je siva (%.2f%%).",p);
} else if (crvena>=crna && crvena>=bijela && crvena>=siva && crvena>=plava) {
	p=(crvena*100)/suma;
	printf("\nNajpopularnija boja je crvena (%.2f%%).",p);
} else if (plava>=crna && plava>=bijela && plava>=siva && plava>=crvena) {
	p=(plava*100)/suma;
	printf("\nNajpopularnija boja je plava (%.2f%%).",p);
}



	
	
	return 0;
}
