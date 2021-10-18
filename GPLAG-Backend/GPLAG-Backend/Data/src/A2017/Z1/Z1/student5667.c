#include<stdio.h>

int main(){
	char a,b,c,d;
	float cjrestoran = 0, cjfast = 0, cjbistro = 0;
	printf("Unesite jelo za Tarika: ");
	scanf("%c", &a);
	scanf("%c", &d);
	printf("Unesite jelo za Bojana: ");
	scanf("%c", &b);
	scanf("%c", &d);
	printf("Unesite jelo za Mirzu: ");
	scanf("%c", &c);
	float popust = 0,maxipop = 0;
	if(a == 'P' || b == 'P' || c =='P')popust = 0.68;
	if(a == 'P' && b == 'P' || a == 'P' && c == 'P' || b == 'P' && c == 'P')popust = 1.36;
	if(a == 'P' && b == 'P' && c == 'P')popust = 2.04;
	if(maxipop < popust)maxipop = popust;
	if(a == 'C' || b == 'C' || c == 'C')popust = 0.5;
	if(a == 'C' && b == 'C' || a == 'C' && c == 'C' || b == 'C' && c == 'C')popust = 1;
	if(a == 'C' && b == 'C' && c == 'C')popust = 1.5;
	if(maxipop < popust)maxipop = popust;
	if(a == 'H' || b == 'H' || c == 'H')popust = 0.33;
	if(a == 'H' && b == 'H' || a == 'H' && c == 'H' || b == 'H' && c == 'H')popust = 0.66;
	if(a == 'H' && b == 'H' && c == 'H')popust = 0.99;
	if(maxipop < popust)maxipop = popust;
	if(a == 'P'){
		cjrestoran += 6.8;
		cjfast += 8;
		cjbistro += 5.3;
	}
	else if(a == 'H'){
		cjrestoran += 3.3;
		cjfast += 3;
		cjbistro += 5;
	}
	else {
		cjrestoran += 5;
		cjfast += 3.9;
		cjbistro += 6;
	}
	if(b == 'P'){
		cjrestoran += 6.8;
		cjfast += 8;
		cjbistro += 5.3;
	}
	else if(b == 'H'){
		cjrestoran += 3.3;
		cjfast += 3;
		cjbistro += 5;
	}
	else {
		cjrestoran += 5;
		cjfast += 3.9;
		cjbistro += 6;
	}
	if(c == 'P'){
		cjrestoran += 6.8;
		cjfast += 8;
		cjbistro += 5.3;
	}
	else if(c == 'H'){
		cjrestoran += 3.3;
		cjfast += 3;
		cjbistro += 5;
	}
	else {
		cjrestoran += 5;
		cjfast += 3.9;
		cjbistro += 6;
	}
	float min,help;
	if(cjrestoran < cjfast && cjrestoran < cjbistro)min = cjrestoran;
	else if(cjfast < cjrestoran && cjfast < cjbistro)min = cjfast;
	else min = cjbistro;
	if(min == cjrestoran)printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%0.2f KM).",min);
	else if(min == cjfast)printf("Najjeftiniji je Fast-food \"Trovac\" (%0.2f KM).",min);
	else printf("Najjeftiniji je Bistro \"Lorelei\" (%0.2f KM).",min);
	printf("\n"); 
	if(min != cjrestoran)
		if(cjrestoran - maxipop < min)printf("Sa popustom bi Restoran bio jeftiniji (%0.2f KM).", cjrestoran - maxipop);
	return 0;
}