#include <stdio.h>

int main() {
	char c;
	int C=0,B=0,S=0,V=0,P=0, ukupno;
	double proc;
	printf("Unesite vozila: ");
	do{
		scanf("%c",&c);
		if(c=='k' || c=='K')
			break;
		else if(c=='C' || c=='c')
			C++;
		else if(c=='B' || c=='b')
			B++;
		else if(c=='S' || c=='s')
			S++;
		else if(c=='V' || c=='v')
			V++;
		else if(c=='P' || c=='p')
			P++;
		else printf("Neispravan unos\n");
	}while(c!='k' && c!='K');
	
	ukupno=C+B+S+V+P;
	printf("Ukupno evidentirano %d vozila.\n", ukupno);
	if(C>=B && C>=S && C>=V && C>=P) {
		if(ukupno == 0) proc = 0;
		else proc = (double)C/ukupno;
		printf("Najpopularnija boja je crna (%.2f%%).", proc*100);
	}
	else if(B>=C && B>=S && B>=V && B>=P) {
		if(ukupno == 0) proc = 0;
		else proc = (double)B/ukupno;
		printf("Najpopularnija boja je bijela (%.2f%%).", proc*100);
	}
	else if(S>=B && S>=C && S>=V && S>=P) {
		if(ukupno == 0) proc = 0;
		else proc = (double)S/ukupno;
		printf("Najpopularnija boja je siva (%.2f%%).", proc*100);
	}
	else if(V>=C && V>=B && V>=S && V>=P) {
		if(ukupno == 0) proc = 0;
		else proc = (double)V/ukupno;
		printf("Najpopularnija boja je crvena (%.2f%%).", proc*100);
	}
	else {
		if(ukupno == 0) proc = 0;
		else proc = (double)P/ukupno;
		printf("Najpopularnija boja je plava (%.2f%%).", proc*100);
	}
	return 0;
}
