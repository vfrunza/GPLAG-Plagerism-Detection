#include <stdio.h>

int main() {
	double cijena1, cijena2, cijena3, najpovoljnija, spopustom;
	char tarik, bojan, mirza, novi_red, navodnici='"';
	printf("Unesite jelo za Tarika: ");
	scanf("%c", &tarik);
	scanf("%c", &novi_red);
	printf("Unesite jelo za Bojana: ");
	scanf("%c", &bojan);
	scanf("%c", &novi_red);
	printf("Unesite jelo za Mirzu: ");
	scanf("%c", &mirza);
	scanf("%c", &novi_red);
	if((tarik=='P' && bojan=='H' && mirza=='C') ||(tarik=='H' && bojan=='P' && mirza=='C') || 
	(tarik=='C' && bojan=='P' && mirza=='H') || (tarik=='P' && bojan=='C' && mirza=='H') ||
	(tarik=='H' && bojan=='C' && mirza=='P' ) || (tarik=='C' && bojan=='H' && mirza=='P')) {
		cijena1=15.1; spopustom=cijena1-0.68;
		cijena2=14.9;
		cijena3=16.3;}
		if (tarik=='P' && bojan=='P' && mirza=='P') {
		cijena1=20.4; spopustom=18.36;
		cijena2=24;
		cijena3=15.9; 	} 
		if (tarik=='H' && bojan=='H' && mirza=='H') {
			cijena1=9.9; spopustom=8.91;
			cijena2=9;
			cijena3=15;	}
		if (tarik=='C' && bojan=='C' && mirza=='C') {
			cijena1=15; spopustom=13.5;
			cijena2=11.7;
			cijena3=18; }
		if ((tarik=='P' && bojan=='P' && mirza=='C') || (tarik=='P' && bojan=='C' && mirza=='P') || (tarik=='C' && bojan=='P' && mirza=='P')) {
			cijena1=18.6; spopustom=17.24;
			cijena2=19.9;
			cijena3=16.6; }
		if ((tarik=='P' && bojan=='P' && mirza=='H') || (tarik=='P' && bojan=='H' && mirza=='P') || (tarik=='H' && bojan=='P' && mirza=='P')) {
			cijena1=16.9; spopustom=15.54;
			cijena2=19;
			cijena3=15.6; }
		if ((tarik=='H' && bojan=='H' && mirza=='P') || (tarik=='H' && bojan=='P' && mirza=='H') || (tarik=='P' && bojan=='H' && mirza=='H')) {
			cijena1=13.4; spopustom=12.72;
			cijena2=14;
			cijena3=15.3; }
		if ((tarik=='H' && bojan=='H' && mirza=='C') || (tarik=='H' && bojan=='C' && mirza=='H') || (tarik=='C' && bojan=='H' && mirza=='H')) {
			cijena1=11.6; spopustom=10.94;
			cijena2=9.9;
			cijena3=16; }
		if ((tarik=='C' && bojan=='C' && mirza=='P') || (tarik=='C' && bojan=='P' && mirza=='C') || (tarik=='P' && bojan=='C' && mirza=='C')) {
			cijena1=16.8; spopustom=15.8;
			cijena2=15.8;
			cijena3=17.3; }
		if ((tarik=='C' && bojan=='C' && mirza=='H') || (tarik=='C' && bojan=='H' && mirza=='C') || (tarik=='H' && bojan=='C' && mirza=='C')) {
			cijena1=13.3; spopustom=12.3;
			cijena2=10.8;
			cijena3=17;	}
		if(cijena1<cijena2 && cijena1<cijena3) najpovoljnija=cijena1;
		else if(cijena2<cijena1 && cijena2<cijena3) najpovoljnija=cijena2;
		else najpovoljnija=cijena3;
		if(najpovoljnija==cijena1) printf("Najjeftiniji je Restoran %cKod konja i konjusara%c (%.2f KM).\n", navodnici, navodnici, cijena1);
		else if(najpovoljnija==cijena2) printf("Najjeftiniji je Fast-food %cTrovac%c (%.2f KM).\n", navodnici, navodnici, cijena2);
		else printf("Najjeftiniji je Bistro %cLorelei%c (%.2f KM).\n", navodnici, navodnici, cijena3);
		if(spopustom<najpovoljnija && najpovoljnija!=cijena1) printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", spopustom);

	return 0;
}
