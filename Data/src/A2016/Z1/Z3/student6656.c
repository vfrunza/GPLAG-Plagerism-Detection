#include <stdio.h>
#include <math.h>
#define epsilon 0.0001

int main() {
	char a;
	float ukupno=0,C=0,B=0,S=0,V=0,P=0,x;
	
	printf("Unesite vozila: ");

	do
	{
		scanf("%c",&a);
	if(a=='C' || a=='c')
	{
		ukupno++;
		C++;
	}
		else if(a=='B' || a=='b')
	{
		ukupno++;
		B++;
	}
		else if(a=='S' || a=='s')
	{
		ukupno++;
		S++;
	}
		else if(a=='V' || a=='v')
	{
		ukupno++;
		V++;
	}
		else if(a=='P' || a=='p')
	{
		ukupno++;
		P++;
	}
	else if(a=='K' || a=='k')
	{
		break;
	}
	   else{
	   printf("Neispravan unos\n");
	   }
	}while(a!='K' && a!='k');
	
	printf("Ukupno evidentirano %g vozila.",ukupno);
	
	if(fabs(ukupno-0) < epsilon)
	{
		x=fabs((C/ukupno)*100) < epsilon;
		printf("\nNajpopularnija boja je crna (%.2f%%).",x);
		return 0;
	}
	
	if(C>=B && C>=S && C>=V && C>=P)
	{
		x=(C/ukupno)*100;
		printf("\nNajpopularnija boja je crna (%.2f%%).",x);
		return 0;
	}
	if(B>=C && B>=S && B>=V && B>=P)
	{
		x=(B/ukupno)*100;
		printf("\nNajpopularnija boja je bijela (%.2f%%).",x);
		return 0;
	}
	if(S>=C && S>=B && S>=V && S>=P)
	{
		x=(S/ukupno)*100;
		printf("\nNajpopularnija boja je siva (%.2f%%).",x);
		return 0;
	}
	if(V>=C && V>=B && V>=S && V>=P)
	{
		x=(V/ukupno)*100;
		printf("\nNajpopularnija boja je crvena (%.2f%%).",x);
		return 0;
	}
	if(P>=C && P>=B && P>=S && P>=V)
	{
		x=(P/ukupno)*100;
		printf("\nNajpopularnija boja je plava (%.2f%%).",x);
		return 0;
	}
	return 0;
}
