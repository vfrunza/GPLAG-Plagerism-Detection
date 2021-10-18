#include <stdio.h>

int main() {
	char znak='a';
	float suma=0;
	float postotak;
	int crvena=0;
	int plava=0;
	int crna=0;
	int siva=0;
	int bijela=0;
	printf("Unesite vozila: ");
	while(znak!='k' && znak!='K')
	{
		znak=getchar();
		if(znak!='C' && znak!='c' && znak!='B' && znak!='b' && znak!='S' && znak!='s' && znak!='V' && znak!='v' && znak!='P' && znak!='p' && znak!='k' && znak!='K')
		printf("Neispravan unos\n");
		if(znak=='C' || znak=='c')
			crna++;
		if(znak=='B' || znak=='b')
			bijela++;
		if(znak=='S' || znak=='s')
			siva++;
		if(znak=='V' || znak=='v')
			crvena++;
		if(znak=='P' || znak=='p')
			plava++;
		}
	suma=crna+plava+crvena+bijela+siva;
	printf("Ukupno evidentirano %g vozila.\n", suma);
	if(crna>=plava && crna>=crvena && crna>=bijela && crna>=siva)
	{
		if(suma!=0)
		postotak=crna*100/suma;
		else
		postotak=0;
		printf("Najpopularnija boja je crna (%.2f%%).", postotak);
	}
	if(bijela>=plava && bijela>=crvena && bijela>crna && bijela>=siva)
	{
		if(suma!=0)
		postotak=bijela*100/suma;
		else
		postotak=0;
		postotak=bijela*100/suma;
		printf("Najpopularnija boja je bijela (%.2f%%).", postotak);
	}
	if(siva>=plava && siva>=crvena && siva>bijela && siva>crna)
	{
		if(suma!=0)
		postotak=siva*100/suma;
		else
		postotak=0;
		postotak=siva*100/suma;
		printf("Najpopularnija boja je siva (%.2f%%).", postotak);
	}
	if(crvena>=plava && crvena>crna && crvena>bijela && crvena>siva)
	{
		if(suma!=0)
		postotak=crvena*100/suma;
		else
		postotak=0;
		postotak=crvena*100/suma;
		printf("Najpopularnija boja je crvena (%.2f%%).", postotak);
	}
	if(plava>crna && plava>crvena && plava>bijela && plava>siva)
	{
		if(suma!=0)
		postotak=plava*100/suma;
		else
		postotak=0;
		postotak=plava*100/suma;
		printf("Najpopularnija boja je plava (%.2f%%).", postotak);
	}
	
	
	return 0;
}
