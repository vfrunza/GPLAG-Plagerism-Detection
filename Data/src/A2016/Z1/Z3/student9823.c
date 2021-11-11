#include <stdio.h>
/*
Za unos boja koristiće slova i to:
C - crna
B - bijela
S - siva
V - crvena
P - plava
K - kraj unosa
Program treba prihvatati i velika i mala slova, dakle ako Selma unese veliko C ili malo c brojaće se kao jedan automobil crne boje.
Za sve ostale znakove treba ispisati poruku "Neispravan unos" i nastaviti dalje sa unosom.

CCbcsVSsCsPk

Nakon što se unese slovo K treba ispisati broj ukupno evidentiranih automobila, boju koja je najpopularnija i procentualni udio vozila
te boje u ukupnom broju, pri čemu procenat treba biti zaokružen na dvije decimale. Ako je za više boja evidentiran isti broj vozila, treba ispisati 
onu boju koja je navedena ranije u spisku iznad (npr. ako je evidentiran jednak broj automobila sive i plave boje i to su dvije najpopularnije boje, 
treba ispisati procenat vozila sive boje jer se siva boja pojavljuje ranije na spisku). */

int main() {
	char slovo;
	double brojac=0;
	int c=0, b=0, s=0, v=0, p=0;
	printf("Unesite vozila: ");
	
	do {
		scanf("%c",&slovo); 
		if(slovo=='C' || slovo=='c') {c++; brojac++;}
		else if(slovo=='B' || slovo=='b') {b++; brojac++;}
		else if(slovo=='S' || slovo=='s') {s++; brojac++;}
		else if(slovo=='V' || slovo=='v') {v++; brojac++;}
		else if(slovo=='P' || slovo=='p') {p++; brojac++;}
		 
		if(slovo!='C' && slovo!='c' && slovo!='B' && slovo!='b' && slovo!='S' && slovo!='s' 
		&& slovo!='V' && slovo!='v' && slovo!='P' && slovo!='p' && slovo!='k' && slovo!='K') {
		printf("Neispravan unos\n"); } 
		
	} while(slovo!='K' && slovo!='k');
	
	int max;
	max=c;
	
	
	
	if(b>max) max=b;
	if(s>max) max=s;
	if(v>max) max=v;
	if(p>max) max=p;
	
	double maxP;
	// max = maxP * max / 100
	printf("Ukupno evidentirano %g vozila.\n", brojac);
	if(brojac==0) printf("Najpopularnija boja je crna (0.00%).");
	else {
	maxP = (100*max)/(brojac);
	
	//printf("%.2f%%\n", maxP);
	if(max==c) printf("Najpopularnija boja je crna (%.2f%%).", maxP);
	else if(max==b) printf("Najpopularnija boja je bijela (%.2f%%).", maxP);
	else if(max==s) printf("Najpopularnija boja je siva (%.2f%%).", maxP);
	else if(max==v) printf("Najpopularnija boja je crvena (%.2f%%).", maxP);
	else if(max==p) printf("Najpopularnija boja je plava (%.2f%%).", maxP);
	}
	
	return 0;
}