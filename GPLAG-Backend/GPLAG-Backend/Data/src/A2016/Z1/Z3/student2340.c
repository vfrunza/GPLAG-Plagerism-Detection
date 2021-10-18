/*3. Selmi je bilo dosadno dok je čekala da počnu predavanja, pa je došla do raskrsnice sa idejom da utvrdi koja boja automobila je najpopularnija 
u Sarajevu. Njen plan je da u računaru evidentira boju svakog automobila koji prođe kroz raskrsnicu. Radi jednostavnosti programa evidentiraće 
automobile pet boja: crna, bijela, siva, crvena i plava. Boje koje su slične nabrojanim (metalik, bordo…) će evidentirati kao osnovne boje, 
a rijetko korištene boje (zelena, žuta, ljubičasta…) neće ni brojati jer nema šansi da neka od tih bude najpopularnija.


Za unos boja koristiće slova i to:
C - crna
B - bijela
S - siva
V - crvena
P - plava
K - kraj unosa
Program treba prihvatati i velika i mala slova, dakle ako Selma unese veliko C ili malo c brojaće se kao jedan automobil crne boje. 
Za sve ostale znakove treba ispisati poruku "Neispravan unos" i nastaviti dalje sa unosom. */

#include <stdio.h>

int main() {
	int max,B,c=0,b=0,s=0,q=0,p=0,i=0;
	char a;
	float P;
	printf("Unesite vozila: ");
	
	/*Unosimo boje pomocu slova*/
	
	
	do {
		scanf("%c", &a);
		if (a == 'K') {
		a='k';
		
	}
	max=c;
	B=1;
		if ((a =='c') || ( a == 'C' )) {
		c++;
		i++;
	}
	if ((a =='b') || ( a == 'B' )) {
		b++;
		i++;
	}
	if (b>max)
	{
	max=b;
	B=2;
	}
	if ((a =='s') || ( a == 'S' )) {
		s++;
		i++;
	
	}
	if (s>max)
	{
	max=s;
	B=3;
	}
	if ((a =='v') || ( a == 'V' )) {
		q++;
		i++;
	}
	if (q>max)
	{
	max=q;
	B=4;
	}
	if ((a =='p') || ( a == 'P' )) {
		p++;
		i++;
	}
	if (p>max)
	{
	max=p;
	B=5;
	}
	if ((a!='c') && (a!='C') && (a!='b') && (a!='B') && (a!='S') && (a!='s') && (a!='v') && (a!='V') && (a!='p') && (a!='P') && (a!='k')) {
		printf("Neispravan unos\n");
	}
	}
	while (a!='k');

/*Nakon što se unese slovo K treba ispisati broj ukupno evidentiranih automobila, boju koja je najpopularnija i procentualni udio vozila te 
boje u ukupnom broju, pri čemu procenat treba biti zaokružen na dvije decimale. Ako je za više boja evidentiran isti broj vozila, treba ispisati 
onu boju koja je navedena ranije u spisku iznad (npr. ako je evidentiran jednak broj automobila sive i plave boje i to su dvije najpopularnije boje, 
treba ispisati procenat vozila sive boje jer se siva boja pojavljuje ranije na spisku).*/

	/*Evidentiramo vozila*/

	printf("Ukupno evidentirano %d vozila.", i);


	/*Ispisivanje procentualno najpopularnije boje vozila.*/

if(i==0)
P=0;
else
P=(max*100.)/i;

	if ( B==1 ) {
			printf("\nNajpopularnija boja je crna (%.2f%%).", P);
		}
	 if ( B==2  ) {
			printf("\nNajpopularnija boja je bijela (%.2f%%).", P);
		}
	 if	( B==4  ) {
			printf("\nNajpopularnija boja je crvena (%.2f%%).", P);
		}
	 if ( B==3  ) {
			printf("\nNajpopularnija boja je siva (%.2f%%).", P);
		}
	 if ( B==5  ) {
			printf("\nNajpopularnija boja je plava (%.2f%%).", P);
		}
	return 0;
}

/*Primjer ulaza i izlaza:
	Unesite vozila: CCbcsVSsCsPk
	Ukupno evidentirano 11 vozila.
	Najpopularnija boja je crna (36.36%).


Savjet: Ako unosite slova koristeći format "%c" nemojte ih razdvajati razmacima niti novim redovima.
Napomena: Pri rješavanju programa nije dozvoljeno koristiti nizove. */